using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//镜像表配置数据类
public class MirrorElement
{
	public int id;               	//序号	5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：珀希洛斯岛 25：艾尔拉诺 26：燃烧沙漠 27：弗罗林王都
	public string comment;       	//备注	备注
	public int map_id;           	//地图ID	该镜像所在的地图ID，程序在此与玩家实际所在的场景ID进行判断，如果不符，则无法创建镜像
	public int trigger_type;     	//触发类型	1为路点，2为事件区域，3为脚本 后一个数字代表对应的ID，脚本的话填写0即可
	public li trigger_list;      	//触发ID	前一列数字代表触发类型：1为路点id，2为事件区域id，3为脚本 后一个数字代表对应的ID，不用填
	public li quest_id;          	//绑定任务id	所需的任务ID，只有当玩家拥有该任务以及符合下面的quest_step的条件时，该事件才会起作用。
	public int quest_step;       	//任务状态	 1：为任务接受后，目标完成前可触发（任务表中的target相关列）；  2：任务目标完成后可触发  3：指定任务完成后可触发 
	public int mirror_type;      	//镜像类型	1：单人镜像 2：组队镜像 3：世界镜像
	public int cg_id;            	//需要播放的cg动画	需要播放的cg动画
	public string music;         	//所改变的背景音乐	所改变的背景音乐
	public string script;        	//脚本路径	脚本路径
	public int effect_type;      	//进入镜像时的特效标识	1：火焰 2：冰冻 3：水波纹 4：模糊（梦境） 
	public int ending_boss_id;   	//结束bossID	该boss死亡后自动退出镜像
	public int can_exit;         	//是否可以显示退出按钮	界面上是否会显示退出镜像的按钮 
	public int Hunt_id;          	//猎魔id	猎魔表
	public li area_id;           	//区域id	区域Id
	public int monster_delay;    	//刷怪延迟	创建n秒后进行刷怪  单位：秒
	public int survival_tm;      	//存在时间	创建后镜像存在的时间  单位：秒

	public bool IsValidate = false;
	public MirrorElement()
	{
		id = -1;
	}
};

//镜像表配置封装类
public class MirrorTable
{

	private MirrorTable()
	{
		m_mapElements = new Dictionary<int, MirrorElement>();
		m_emptyItem = new MirrorElement();
		m_vecAllElements = new List<MirrorElement>();
	}
	private Dictionary<int, MirrorElement> m_mapElements = null;
	private List<MirrorElement>	m_vecAllElements = null;
	private MirrorElement m_emptyItem = null;
	private static MirrorTable sInstance = null;

	public static MirrorTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MirrorTable();
			return sInstance;
		}
	}

	public MirrorElement GetElement(int key)
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

  public List<MirrorElement> GetAllElement(Predicate<MirrorElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Mirror.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Mirror.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Mirror.bin]未找到");
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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("Mirror.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mirror.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mirror.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Mirror.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="trigger_type"){Ex.Logger.Log("Mirror.csv中字段[trigger_type]位置不对应"); return false; }
		if(vecLine[4]!="trigger_list"){Ex.Logger.Log("Mirror.csv中字段[trigger_list]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("Mirror.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[6]!="quest_step"){Ex.Logger.Log("Mirror.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[7]!="mirror_type"){Ex.Logger.Log("Mirror.csv中字段[mirror_type]位置不对应"); return false; }
		if(vecLine[8]!="cg_id"){Ex.Logger.Log("Mirror.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[9]!="music"){Ex.Logger.Log("Mirror.csv中字段[music]位置不对应"); return false; }
		if(vecLine[10]!="script"){Ex.Logger.Log("Mirror.csv中字段[script]位置不对应"); return false; }
		if(vecLine[11]!="effect_type"){Ex.Logger.Log("Mirror.csv中字段[effect_type]位置不对应"); return false; }
		if(vecLine[12]!="ending_boss_id"){Ex.Logger.Log("Mirror.csv中字段[ending_boss_id]位置不对应"); return false; }
		if(vecLine[13]!="can_exit"){Ex.Logger.Log("Mirror.csv中字段[can_exit]位置不对应"); return false; }
		if(vecLine[14]!="Hunt_id"){Ex.Logger.Log("Mirror.csv中字段[Hunt_id]位置不对应"); return false; }
		if(vecLine[15]!="area_id"){Ex.Logger.Log("Mirror.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[16]!="monster_delay"){Ex.Logger.Log("Mirror.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[17]!="survival_tm"){Ex.Logger.Log("Mirror.csv中字段[survival_tm]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MirrorElement member = new MirrorElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.trigger_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.trigger_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mirror_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cg_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ending_boss_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_exit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Hunt_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.area_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster_delay );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.survival_tm );

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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("Mirror.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mirror.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mirror.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Mirror.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="trigger_type"){Ex.Logger.Log("Mirror.csv中字段[trigger_type]位置不对应"); return false; }
		if(vecLine[4]!="trigger_list"){Ex.Logger.Log("Mirror.csv中字段[trigger_list]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("Mirror.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[6]!="quest_step"){Ex.Logger.Log("Mirror.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[7]!="mirror_type"){Ex.Logger.Log("Mirror.csv中字段[mirror_type]位置不对应"); return false; }
		if(vecLine[8]!="cg_id"){Ex.Logger.Log("Mirror.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[9]!="music"){Ex.Logger.Log("Mirror.csv中字段[music]位置不对应"); return false; }
		if(vecLine[10]!="script"){Ex.Logger.Log("Mirror.csv中字段[script]位置不对应"); return false; }
		if(vecLine[11]!="effect_type"){Ex.Logger.Log("Mirror.csv中字段[effect_type]位置不对应"); return false; }
		if(vecLine[12]!="ending_boss_id"){Ex.Logger.Log("Mirror.csv中字段[ending_boss_id]位置不对应"); return false; }
		if(vecLine[13]!="can_exit"){Ex.Logger.Log("Mirror.csv中字段[can_exit]位置不对应"); return false; }
		if(vecLine[14]!="Hunt_id"){Ex.Logger.Log("Mirror.csv中字段[Hunt_id]位置不对应"); return false; }
		if(vecLine[15]!="area_id"){Ex.Logger.Log("Mirror.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[16]!="monster_delay"){Ex.Logger.Log("Mirror.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[17]!="survival_tm"){Ex.Logger.Log("Mirror.csv中字段[survival_tm]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)18)
			{
				return false;
			}
			MirrorElement member = new MirrorElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.map_id=Convert.ToInt32(vecLine[2]);
			member.trigger_type=Convert.ToInt32(vecLine[3]);
			member.trigger_list=vecLine[4];
			member.quest_id=vecLine[5];
			member.quest_step=Convert.ToInt32(vecLine[6]);
			member.mirror_type=Convert.ToInt32(vecLine[7]);
			member.cg_id=Convert.ToInt32(vecLine[8]);
			member.music=vecLine[9];
			member.script=vecLine[10];
			member.effect_type=Convert.ToInt32(vecLine[11]);
			member.ending_boss_id=Convert.ToInt32(vecLine[12]);
			member.can_exit=Convert.ToInt32(vecLine[13]);
			member.Hunt_id=Convert.ToInt32(vecLine[14]);
			member.area_id=vecLine[15];
			member.monster_delay=Convert.ToInt32(vecLine[16]);
			member.survival_tm=Convert.ToInt32(vecLine[17]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
