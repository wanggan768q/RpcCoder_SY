using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//公会建筑表配置数据类
public class AllianceBuildingElement
{
	public int id;               	//ID	填写ID即可
	public string comment;       	//注释	策划用
	public int building;         	//建筑名不带等级	stringid
	public int name;             	//建筑名字	stringid
	public int desc;             	//建筑描述	stringid
	public int type;             	//类型	填写整数
	public int cost;             	//该建筑的维护费用	填写整数
	public string pic;           	//建筑图	图片名
	public int level;            	//建筑等级	建筑最小等级为1，0为配表通用型
	public li buff;              	//建筑所加战斗属性	无写0 有写作用号|所加数值
	public int currency;         	//升级至下一级需公会资金	填写整数
	public int resource;         	//升级至下一级需公会资源	填写整数
	public int time;             	//升级所需时间	分钟为单位
	public int up_currency;      	//加速1次所需绑钻	填写整数
	public int up_time;          	//加速1次减少时长	分钟为单位
	public int up_rewards;       	//加速1次奖励的帮贡	整数
	public li condition1;        	//升级所需条件	且关系
	public li condition2;        	//升级所需条件	或关系
	public int effect;           	//升级带来效果	填写整数

	public bool IsValidate = false;
	public AllianceBuildingElement()
	{
		id = -1;
	}
};

//公会建筑表配置封装类
public class AllianceBuildingTable
{

	private AllianceBuildingTable()
	{
		m_mapElements = new Dictionary<int, AllianceBuildingElement>();
		m_emptyItem = new AllianceBuildingElement();
		m_vecAllElements = new List<AllianceBuildingElement>();
	}
	private Dictionary<int, AllianceBuildingElement> m_mapElements = null;
	private List<AllianceBuildingElement>	m_vecAllElements = null;
	private AllianceBuildingElement m_emptyItem = null;
	private static AllianceBuildingTable sInstance = null;

	public static AllianceBuildingTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AllianceBuildingTable();
			return sInstance;
		}
	}

	public AllianceBuildingElement GetElement(int key)
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

  public List<AllianceBuildingElement> GetAllElement(Predicate<AllianceBuildingElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AllianceBuilding.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AllianceBuilding.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AllianceBuilding.bin]未找到");
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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("AllianceBuilding.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceBuilding.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceBuilding.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="building"){Ex.Logger.Log("AllianceBuilding.csv中字段[building]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("AllianceBuilding.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="desc"){Ex.Logger.Log("AllianceBuilding.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("AllianceBuilding.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="cost"){Ex.Logger.Log("AllianceBuilding.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[7]!="pic"){Ex.Logger.Log("AllianceBuilding.csv中字段[pic]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("AllianceBuilding.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="buff"){Ex.Logger.Log("AllianceBuilding.csv中字段[buff]位置不对应"); return false; }
		if(vecLine[10]!="currency"){Ex.Logger.Log("AllianceBuilding.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[11]!="resource"){Ex.Logger.Log("AllianceBuilding.csv中字段[resource]位置不对应"); return false; }
		if(vecLine[12]!="time"){Ex.Logger.Log("AllianceBuilding.csv中字段[time]位置不对应"); return false; }
		if(vecLine[13]!="up_currency"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_currency]位置不对应"); return false; }
		if(vecLine[14]!="up_time"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_time]位置不对应"); return false; }
		if(vecLine[15]!="up_rewards"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_rewards]位置不对应"); return false; }
		if(vecLine[16]!="condition1"){Ex.Logger.Log("AllianceBuilding.csv中字段[condition1]位置不对应"); return false; }
		if(vecLine[17]!="condition2"){Ex.Logger.Log("AllianceBuilding.csv中字段[condition2]位置不对应"); return false; }
		if(vecLine[18]!="effect"){Ex.Logger.Log("AllianceBuilding.csv中字段[effect]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AllianceBuildingElement member = new AllianceBuildingElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.building );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cost );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.currency );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.resource );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_currency );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_rewards );
			readPos += GameAssist.ReadString( binContent, readPos, out member.condition1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.condition2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect );

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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("AllianceBuilding.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceBuilding.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceBuilding.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="building"){Ex.Logger.Log("AllianceBuilding.csv中字段[building]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("AllianceBuilding.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="desc"){Ex.Logger.Log("AllianceBuilding.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("AllianceBuilding.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="cost"){Ex.Logger.Log("AllianceBuilding.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[7]!="pic"){Ex.Logger.Log("AllianceBuilding.csv中字段[pic]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("AllianceBuilding.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="buff"){Ex.Logger.Log("AllianceBuilding.csv中字段[buff]位置不对应"); return false; }
		if(vecLine[10]!="currency"){Ex.Logger.Log("AllianceBuilding.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[11]!="resource"){Ex.Logger.Log("AllianceBuilding.csv中字段[resource]位置不对应"); return false; }
		if(vecLine[12]!="time"){Ex.Logger.Log("AllianceBuilding.csv中字段[time]位置不对应"); return false; }
		if(vecLine[13]!="up_currency"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_currency]位置不对应"); return false; }
		if(vecLine[14]!="up_time"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_time]位置不对应"); return false; }
		if(vecLine[15]!="up_rewards"){Ex.Logger.Log("AllianceBuilding.csv中字段[up_rewards]位置不对应"); return false; }
		if(vecLine[16]!="condition1"){Ex.Logger.Log("AllianceBuilding.csv中字段[condition1]位置不对应"); return false; }
		if(vecLine[17]!="condition2"){Ex.Logger.Log("AllianceBuilding.csv中字段[condition2]位置不对应"); return false; }
		if(vecLine[18]!="effect"){Ex.Logger.Log("AllianceBuilding.csv中字段[effect]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)19)
			{
				return false;
			}
			AllianceBuildingElement member = new AllianceBuildingElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.building=Convert.ToInt32(vecLine[2]);
			member.name=Convert.ToInt32(vecLine[3]);
			member.desc=Convert.ToInt32(vecLine[4]);
			member.type=Convert.ToInt32(vecLine[5]);
			member.cost=Convert.ToInt32(vecLine[6]);
			member.pic=vecLine[7];
			member.level=Convert.ToInt32(vecLine[8]);
			member.buff=vecLine[9];
			member.currency=Convert.ToInt32(vecLine[10]);
			member.resource=Convert.ToInt32(vecLine[11]);
			member.time=Convert.ToInt32(vecLine[12]);
			member.up_currency=Convert.ToInt32(vecLine[13]);
			member.up_time=Convert.ToInt32(vecLine[14]);
			member.up_rewards=Convert.ToInt32(vecLine[15]);
			member.condition1=vecLine[16];
			member.condition2=vecLine[17];
			member.effect=Convert.ToInt32(vecLine[18]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
