using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//子弹类配置数据类
public class BulletElement
{
	public int id;               	//子弹ID	
	public string comment;       	//描述	子弹备注信息，和显示无关
	public int generateLocationType;	//生成位置类型	0=读表，根据表中配置数据决定生成位置 1=技能选择位置 2=技能目标位置
	public int generateNum;      	//产生数量	最大产生子弹的数量
	public int generateType;     	//产生方式	0=平行 1=扇形 2=追踪
	public float objParam;       	//发射偏转角度	初始子弹创建偏转角度
	public float bulletGap;      	//子弹空间间隔	如果产生方式是0，则填入间隔距离； 如果产生方式是1，则填入角度。 单位：m
	public float startRange;     	//生成点偏移距离	子弹生成时子弹起始位置与caster之间距离，单位：m
	public float generateRange;  	//子弹生成距离	子弹以caster位置+生成点偏移距离为起始点，以子弹生成方向和该距离为参数生成子弹，单位：m
	public int moveCount;        	//移动段数	子弹可飞行多段
	public li moveType;          	//各段子弹移动类型	0=读表 1=飞向技能选择的位置 2=飞向技能目标 3=飞向技能选择的方向 4=飞向caster
	public li deflectionAngle;   	//飞行偏移角度	当前方向（初始为生成方向）加偏转角度，作为子弹该段的飞行方向。若该段移动类型为飞向指定目标，则填0
	public lf maxRange;          	//最大距离	各段最大飞行距离（m），若该段移动方向或位置是玩家选择的，则填0占位
	public li duration;          	//飞行时间	各段飞行时间，用连接符“|”连接，单位：ms 最大飞行距离为0时，表示子弹持续时间；距离大于0时，表示飞行时间； 当飞行时间填写0时，子弹按照发射速度进行移动
	public lf speed;             	//子弹飞行速度	各段飞行速度，用连接符“|”连接，单位：m/s 子弹发射的飞行速度
	public li stayTime;          	//子弹停留时间	各段子弹停留时间，用连接符“|”连接，单位：ms
	public li attackList;        	//产生效果的attackList	碰撞后产生的attackId，多个attack用连接符“|”连接
	public string flyEffect;     	//特效名称	模型或特效名称
	public int buffMount;        	//挂点ID	特效挂点ID
	public string endEffect;     	//结束特效	子弹消失是是否播放特效 没有特效=不填 有特效填特效名称
	public int flags;            	//是否产生碰撞	0=穿墙 1=碰墙消失 2=碰墙停留
	public int disappearType;    	//消失类型	0:走完整个过程消失 1:打足最大碰撞次数消失
	public int maxCollisionTimes;	//最大碰撞次数	 最大碰撞目标个数
	public int isLast;           	//是否持续伤害	一次性伤害=0，同一个人只受到一次伤害，在达到最远距离或打到最大碰撞次数后消失； 持续伤害=1，同一个人可受到多次伤害，在持续时间结束后消失
	public int interval;         	//间隔时间	持续伤害的间隔时间，单位：ms
	public int typeId;           	//类型ID	客户端对特殊子弹的处理 0=常规 1=冰龙
	public li triggerAttackId;   	//额外触发的attackid	当子弹触发效果区域和碰撞区域大小不一致时，将用于检测碰撞区域的attack的list填写到该列；区域大小一致时直接使用attackList，该列为空
	public int hitOnce;          	//同一个人是否伤害一次	弃用字段 同一个人是否伤害一次 0=否 1=是
	public int hasFinalEffect;   	//到最大距离是否产生效果	弃用字段 服务器和客户端均未使用

	public bool IsValidate = false;
	public BulletElement()
	{
		id = -1;
	}
};

//子弹类配置封装类
public class BulletTable
{

	private BulletTable()
	{
		m_mapElements = new Dictionary<int, BulletElement>();
		m_emptyItem = new BulletElement();
		m_vecAllElements = new List<BulletElement>();
	}
	private Dictionary<int, BulletElement> m_mapElements = null;
	private List<BulletElement>	m_vecAllElements = null;
	private BulletElement m_emptyItem = null;
	private static BulletTable sInstance = null;

	public static BulletTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BulletTable();
			return sInstance;
		}
	}

	public BulletElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<BulletElement> GetAllElement(Predicate<BulletElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Bullet.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Bullet.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Bullet.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 29)
		{
			Ex.Logger.Log("Bullet.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Bullet.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Bullet.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="generateLocationType"){Ex.Logger.Log("Bullet.csv中字段[generateLocationType]位置不对应"); return false; }
		if(vecLine[3]!="generateNum"){Ex.Logger.Log("Bullet.csv中字段[generateNum]位置不对应"); return false; }
		if(vecLine[4]!="generateType"){Ex.Logger.Log("Bullet.csv中字段[generateType]位置不对应"); return false; }
		if(vecLine[5]!="objParam"){Ex.Logger.Log("Bullet.csv中字段[objParam]位置不对应"); return false; }
		if(vecLine[6]!="bulletGap"){Ex.Logger.Log("Bullet.csv中字段[bulletGap]位置不对应"); return false; }
		if(vecLine[7]!="startRange"){Ex.Logger.Log("Bullet.csv中字段[startRange]位置不对应"); return false; }
		if(vecLine[8]!="generateRange"){Ex.Logger.Log("Bullet.csv中字段[generateRange]位置不对应"); return false; }
		if(vecLine[9]!="moveCount"){Ex.Logger.Log("Bullet.csv中字段[moveCount]位置不对应"); return false; }
		if(vecLine[10]!="moveType"){Ex.Logger.Log("Bullet.csv中字段[moveType]位置不对应"); return false; }
		if(vecLine[11]!="deflectionAngle"){Ex.Logger.Log("Bullet.csv中字段[deflectionAngle]位置不对应"); return false; }
		if(vecLine[12]!="maxRange"){Ex.Logger.Log("Bullet.csv中字段[maxRange]位置不对应"); return false; }
		if(vecLine[13]!="duration"){Ex.Logger.Log("Bullet.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[14]!="speed"){Ex.Logger.Log("Bullet.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[15]!="stayTime"){Ex.Logger.Log("Bullet.csv中字段[stayTime]位置不对应"); return false; }
		if(vecLine[16]!="attackList"){Ex.Logger.Log("Bullet.csv中字段[attackList]位置不对应"); return false; }
		if(vecLine[17]!="flyEffect"){Ex.Logger.Log("Bullet.csv中字段[flyEffect]位置不对应"); return false; }
		if(vecLine[18]!="buffMount"){Ex.Logger.Log("Bullet.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[19]!="endEffect"){Ex.Logger.Log("Bullet.csv中字段[endEffect]位置不对应"); return false; }
		if(vecLine[20]!="flags"){Ex.Logger.Log("Bullet.csv中字段[flags]位置不对应"); return false; }
		if(vecLine[21]!="disappearType"){Ex.Logger.Log("Bullet.csv中字段[disappearType]位置不对应"); return false; }
		if(vecLine[22]!="maxCollisionTimes"){Ex.Logger.Log("Bullet.csv中字段[maxCollisionTimes]位置不对应"); return false; }
		if(vecLine[23]!="isLast"){Ex.Logger.Log("Bullet.csv中字段[isLast]位置不对应"); return false; }
		if(vecLine[24]!="interval"){Ex.Logger.Log("Bullet.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[25]!="typeId"){Ex.Logger.Log("Bullet.csv中字段[typeId]位置不对应"); return false; }
		if(vecLine[26]!="triggerAttackId"){Ex.Logger.Log("Bullet.csv中字段[triggerAttackId]位置不对应"); return false; }
		if(vecLine[27]!="hitOnce"){Ex.Logger.Log("Bullet.csv中字段[hitOnce]位置不对应"); return false; }
		if(vecLine[28]!="hasFinalEffect"){Ex.Logger.Log("Bullet.csv中字段[hasFinalEffect]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BulletElement member = new BulletElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.generateLocationType );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.generateNum );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.generateType );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.objParam);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.bulletGap);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.startRange);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.generateRange);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.moveCount );
			readPos += GameAssist.ReadString( binContent, readPos, out member.moveType);
			readPos += GameAssist.ReadString( binContent, readPos, out member.deflectionAngle);
			readPos += GameAssist.ReadString( binContent, readPos, out member.maxRange);
			readPos += GameAssist.ReadString( binContent, readPos, out member.duration);
			readPos += GameAssist.ReadString( binContent, readPos, out member.speed);
			readPos += GameAssist.ReadString( binContent, readPos, out member.stayTime);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attackList);
			readPos += GameAssist.ReadString( binContent, readPos, out member.flyEffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffMount );
			readPos += GameAssist.ReadString( binContent, readPos, out member.endEffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.flags );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.disappearType );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.maxCollisionTimes );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.isLast );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.typeId );
			readPos += GameAssist.ReadString( binContent, readPos, out member.triggerAttackId);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hitOnce );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hasFinalEffect );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 29)
		{
			Ex.Logger.Log("Bullet.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Bullet.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Bullet.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="generateLocationType"){Ex.Logger.Log("Bullet.csv中字段[generateLocationType]位置不对应"); return false; }
		if(vecLine[3]!="generateNum"){Ex.Logger.Log("Bullet.csv中字段[generateNum]位置不对应"); return false; }
		if(vecLine[4]!="generateType"){Ex.Logger.Log("Bullet.csv中字段[generateType]位置不对应"); return false; }
		if(vecLine[5]!="objParam"){Ex.Logger.Log("Bullet.csv中字段[objParam]位置不对应"); return false; }
		if(vecLine[6]!="bulletGap"){Ex.Logger.Log("Bullet.csv中字段[bulletGap]位置不对应"); return false; }
		if(vecLine[7]!="startRange"){Ex.Logger.Log("Bullet.csv中字段[startRange]位置不对应"); return false; }
		if(vecLine[8]!="generateRange"){Ex.Logger.Log("Bullet.csv中字段[generateRange]位置不对应"); return false; }
		if(vecLine[9]!="moveCount"){Ex.Logger.Log("Bullet.csv中字段[moveCount]位置不对应"); return false; }
		if(vecLine[10]!="moveType"){Ex.Logger.Log("Bullet.csv中字段[moveType]位置不对应"); return false; }
		if(vecLine[11]!="deflectionAngle"){Ex.Logger.Log("Bullet.csv中字段[deflectionAngle]位置不对应"); return false; }
		if(vecLine[12]!="maxRange"){Ex.Logger.Log("Bullet.csv中字段[maxRange]位置不对应"); return false; }
		if(vecLine[13]!="duration"){Ex.Logger.Log("Bullet.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[14]!="speed"){Ex.Logger.Log("Bullet.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[15]!="stayTime"){Ex.Logger.Log("Bullet.csv中字段[stayTime]位置不对应"); return false; }
		if(vecLine[16]!="attackList"){Ex.Logger.Log("Bullet.csv中字段[attackList]位置不对应"); return false; }
		if(vecLine[17]!="flyEffect"){Ex.Logger.Log("Bullet.csv中字段[flyEffect]位置不对应"); return false; }
		if(vecLine[18]!="buffMount"){Ex.Logger.Log("Bullet.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[19]!="endEffect"){Ex.Logger.Log("Bullet.csv中字段[endEffect]位置不对应"); return false; }
		if(vecLine[20]!="flags"){Ex.Logger.Log("Bullet.csv中字段[flags]位置不对应"); return false; }
		if(vecLine[21]!="disappearType"){Ex.Logger.Log("Bullet.csv中字段[disappearType]位置不对应"); return false; }
		if(vecLine[22]!="maxCollisionTimes"){Ex.Logger.Log("Bullet.csv中字段[maxCollisionTimes]位置不对应"); return false; }
		if(vecLine[23]!="isLast"){Ex.Logger.Log("Bullet.csv中字段[isLast]位置不对应"); return false; }
		if(vecLine[24]!="interval"){Ex.Logger.Log("Bullet.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[25]!="typeId"){Ex.Logger.Log("Bullet.csv中字段[typeId]位置不对应"); return false; }
		if(vecLine[26]!="triggerAttackId"){Ex.Logger.Log("Bullet.csv中字段[triggerAttackId]位置不对应"); return false; }
		if(vecLine[27]!="hitOnce"){Ex.Logger.Log("Bullet.csv中字段[hitOnce]位置不对应"); return false; }
		if(vecLine[28]!="hasFinalEffect"){Ex.Logger.Log("Bullet.csv中字段[hasFinalEffect]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)29)
			{
				return false;
			}
			BulletElement member = new BulletElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.generateLocationType=Convert.ToInt32(vecLine[2]);
			member.generateNum=Convert.ToInt32(vecLine[3]);
			member.generateType=Convert.ToInt32(vecLine[4]);
			member.objParam=Convert.ToSingle(vecLine[5]);
			member.bulletGap=Convert.ToSingle(vecLine[6]);
			member.startRange=Convert.ToSingle(vecLine[7]);
			member.generateRange=Convert.ToSingle(vecLine[8]);
			member.moveCount=Convert.ToInt32(vecLine[9]);
			member.moveType=vecLine[10];
			member.deflectionAngle=vecLine[11];
			member.maxRange=vecLine[12];
			member.duration=vecLine[13];
			member.speed=vecLine[14];
			member.stayTime=vecLine[15];
			member.attackList=vecLine[16];
			member.flyEffect=vecLine[17];
			member.buffMount=Convert.ToInt32(vecLine[18]);
			member.endEffect=vecLine[19];
			member.flags=Convert.ToInt32(vecLine[20]);
			member.disappearType=Convert.ToInt32(vecLine[21]);
			member.maxCollisionTimes=Convert.ToInt32(vecLine[22]);
			member.isLast=Convert.ToInt32(vecLine[23]);
			member.interval=Convert.ToInt32(vecLine[24]);
			member.typeId=Convert.ToInt32(vecLine[25]);
			member.triggerAttackId=vecLine[26];
			member.hitOnce=Convert.ToInt32(vecLine[27]);
			member.hasFinalEffect=Convert.ToInt32(vecLine[28]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
