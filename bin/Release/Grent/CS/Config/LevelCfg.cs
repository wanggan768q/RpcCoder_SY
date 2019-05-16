using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//等级表配置数据类
public class LevelElement
{
	public int id;               	//主键id	
	public string comment;       	//任务备注	玩家等级
	public li racequest_id_first_day;	//占星任务第一天	任务id 可以分段，但任务id中间必须是连续的，12025|12036|12050|12081
	public li racequest_id_head_3;	//占星任务id前三次	任务id
	public li racequest_id_tail_7;	//占星任务后七次	任务id
	public li hunt_quest_id;     	//猎魔任务id	任务id
	public li treasure_map_1_id; 	//低级藏宝图map id	treasuremap_id
	public li treasure_map_2_id; 	//高级藏宝图map id	treasuremap_id
	public li treasure_monster_1_id;	//低级藏宝图怪物id	怪物id
	public li treasure_monster_2_id;	//高级藏宝图怪物id	怪物id
	public li battle_quest_id;   	//世界战场活跃度箱子	任务id
	public li elite_quest_id;    	//精英怪任务id	任务id
	public li arena_quest_id;    	//竞技场活动任务	任务id
	public li daily_quest_id;    	//世界战场和爬塔活动 积分计数任务	每天刷新 自动会接到的任务 以下填任务id
	public li battle_quest_2_id; 	//世界战场活动任务	以下填任务id

	public bool IsValidate = false;
	public LevelElement()
	{
		id = -1;
	}
};

//等级表配置封装类
public class LevelTable
{

	private LevelTable()
	{
		m_mapElements = new Dictionary<int, LevelElement>();
		m_emptyItem = new LevelElement();
		m_vecAllElements = new List<LevelElement>();
	}
	private Dictionary<int, LevelElement> m_mapElements = null;
	private List<LevelElement>	m_vecAllElements = null;
	private LevelElement m_emptyItem = null;
	private static LevelTable sInstance = null;

	public static LevelTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LevelTable();
			return sInstance;
		}
	}

	public LevelElement GetElement(int key)
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

  public List<LevelElement> GetAllElement(Predicate<LevelElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Level.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Level.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Level.bin]未找到");
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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Level.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Level.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Level.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="racequest_id_first_day"){Ex.Logger.Log("Level.csv中字段[racequest_id_first_day]位置不对应"); return false; }
		if(vecLine[3]!="racequest_id_head_3"){Ex.Logger.Log("Level.csv中字段[racequest_id_head_3]位置不对应"); return false; }
		if(vecLine[4]!="racequest_id_tail_7"){Ex.Logger.Log("Level.csv中字段[racequest_id_tail_7]位置不对应"); return false; }
		if(vecLine[5]!="hunt_quest_id"){Ex.Logger.Log("Level.csv中字段[hunt_quest_id]位置不对应"); return false; }
		if(vecLine[6]!="treasure_map_1_id"){Ex.Logger.Log("Level.csv中字段[treasure_map_1_id]位置不对应"); return false; }
		if(vecLine[7]!="treasure_map_2_id"){Ex.Logger.Log("Level.csv中字段[treasure_map_2_id]位置不对应"); return false; }
		if(vecLine[8]!="treasure_monster_1_id"){Ex.Logger.Log("Level.csv中字段[treasure_monster_1_id]位置不对应"); return false; }
		if(vecLine[9]!="treasure_monster_2_id"){Ex.Logger.Log("Level.csv中字段[treasure_monster_2_id]位置不对应"); return false; }
		if(vecLine[10]!="battle_quest_id"){Ex.Logger.Log("Level.csv中字段[battle_quest_id]位置不对应"); return false; }
		if(vecLine[11]!="elite_quest_id"){Ex.Logger.Log("Level.csv中字段[elite_quest_id]位置不对应"); return false; }
		if(vecLine[12]!="arena_quest_id"){Ex.Logger.Log("Level.csv中字段[arena_quest_id]位置不对应"); return false; }
		if(vecLine[13]!="daily_quest_id"){Ex.Logger.Log("Level.csv中字段[daily_quest_id]位置不对应"); return false; }
		if(vecLine[14]!="battle_quest_2_id"){Ex.Logger.Log("Level.csv中字段[battle_quest_2_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LevelElement member = new LevelElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.racequest_id_first_day);
			readPos += GameAssist.ReadString( binContent, readPos, out member.racequest_id_head_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.racequest_id_tail_7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.hunt_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_map_1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_map_2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_monster_1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_monster_2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.battle_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.elite_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.arena_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.daily_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.battle_quest_2_id);

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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Level.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Level.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Level.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="racequest_id_first_day"){Ex.Logger.Log("Level.csv中字段[racequest_id_first_day]位置不对应"); return false; }
		if(vecLine[3]!="racequest_id_head_3"){Ex.Logger.Log("Level.csv中字段[racequest_id_head_3]位置不对应"); return false; }
		if(vecLine[4]!="racequest_id_tail_7"){Ex.Logger.Log("Level.csv中字段[racequest_id_tail_7]位置不对应"); return false; }
		if(vecLine[5]!="hunt_quest_id"){Ex.Logger.Log("Level.csv中字段[hunt_quest_id]位置不对应"); return false; }
		if(vecLine[6]!="treasure_map_1_id"){Ex.Logger.Log("Level.csv中字段[treasure_map_1_id]位置不对应"); return false; }
		if(vecLine[7]!="treasure_map_2_id"){Ex.Logger.Log("Level.csv中字段[treasure_map_2_id]位置不对应"); return false; }
		if(vecLine[8]!="treasure_monster_1_id"){Ex.Logger.Log("Level.csv中字段[treasure_monster_1_id]位置不对应"); return false; }
		if(vecLine[9]!="treasure_monster_2_id"){Ex.Logger.Log("Level.csv中字段[treasure_monster_2_id]位置不对应"); return false; }
		if(vecLine[10]!="battle_quest_id"){Ex.Logger.Log("Level.csv中字段[battle_quest_id]位置不对应"); return false; }
		if(vecLine[11]!="elite_quest_id"){Ex.Logger.Log("Level.csv中字段[elite_quest_id]位置不对应"); return false; }
		if(vecLine[12]!="arena_quest_id"){Ex.Logger.Log("Level.csv中字段[arena_quest_id]位置不对应"); return false; }
		if(vecLine[13]!="daily_quest_id"){Ex.Logger.Log("Level.csv中字段[daily_quest_id]位置不对应"); return false; }
		if(vecLine[14]!="battle_quest_2_id"){Ex.Logger.Log("Level.csv中字段[battle_quest_2_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)15)
			{
				return false;
			}
			LevelElement member = new LevelElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.racequest_id_first_day=vecLine[2];
			member.racequest_id_head_3=vecLine[3];
			member.racequest_id_tail_7=vecLine[4];
			member.hunt_quest_id=vecLine[5];
			member.treasure_map_1_id=vecLine[6];
			member.treasure_map_2_id=vecLine[7];
			member.treasure_monster_1_id=vecLine[8];
			member.treasure_monster_2_id=vecLine[9];
			member.battle_quest_id=vecLine[10];
			member.elite_quest_id=vecLine[11];
			member.arena_quest_id=vecLine[12];
			member.daily_quest_id=vecLine[13];
			member.battle_quest_2_id=vecLine[14];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
