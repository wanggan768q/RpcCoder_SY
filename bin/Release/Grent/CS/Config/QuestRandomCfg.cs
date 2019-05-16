using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//等级表配置数据类
public class QuestRandomElement
{
	public int id;               	//主键id	
	public string comment;       	//任务备注	玩家等级
	public li racequest_id;      	//师门任务id	任务id
	public li hunt_quest_id;     	//猎魔任务id	任务id
	public li treasure_monster_1_id;	//低级藏宝图怪物id	怪物id
	public li treasure_monster_2_id;	//高级藏宝图怪物id	怪物id
	public li battle_quest_id;   	//阵营战id	怪物id

	public bool IsValidate = false;
	public QuestRandomElement()
	{
		id = -1;
	}
};

//等级表配置封装类
public class QuestRandomTable
{

	private QuestRandomTable()
	{
		m_mapElements = new Dictionary<int, QuestRandomElement>();
		m_emptyItem = new QuestRandomElement();
		m_vecAllElements = new List<QuestRandomElement>();
	}
	private Dictionary<int, QuestRandomElement> m_mapElements = null;
	private List<QuestRandomElement>	m_vecAllElements = null;
	private QuestRandomElement m_emptyItem = null;
	private static QuestRandomTable sInstance = null;

	public static QuestRandomTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new QuestRandomTable();
			return sInstance;
		}
	}

	public QuestRandomElement GetElement(int key)
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

  public List<QuestRandomElement> GetAllElement(Predicate<QuestRandomElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("QuestRandom.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("QuestRandom.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[QuestRandom.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("QuestRandom.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QuestRandom.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QuestRandom.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="racequest_id"){Ex.Logger.Log("QuestRandom.csv中字段[racequest_id]位置不对应"); return false; }
		if(vecLine[3]!="hunt_quest_id"){Ex.Logger.Log("QuestRandom.csv中字段[hunt_quest_id]位置不对应"); return false; }
		if(vecLine[4]!="treasure_monster_1_id"){Ex.Logger.Log("QuestRandom.csv中字段[treasure_monster_1_id]位置不对应"); return false; }
		if(vecLine[5]!="treasure_monster_2_id"){Ex.Logger.Log("QuestRandom.csv中字段[treasure_monster_2_id]位置不对应"); return false; }
		if(vecLine[6]!="battle_quest_id"){Ex.Logger.Log("QuestRandom.csv中字段[battle_quest_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			QuestRandomElement member = new QuestRandomElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.racequest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.hunt_quest_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_monster_1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_monster_2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.battle_quest_id);

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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("QuestRandom.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QuestRandom.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QuestRandom.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="racequest_id"){Ex.Logger.Log("QuestRandom.csv中字段[racequest_id]位置不对应"); return false; }
		if(vecLine[3]!="hunt_quest_id"){Ex.Logger.Log("QuestRandom.csv中字段[hunt_quest_id]位置不对应"); return false; }
		if(vecLine[4]!="treasure_monster_1_id"){Ex.Logger.Log("QuestRandom.csv中字段[treasure_monster_1_id]位置不对应"); return false; }
		if(vecLine[5]!="treasure_monster_2_id"){Ex.Logger.Log("QuestRandom.csv中字段[treasure_monster_2_id]位置不对应"); return false; }
		if(vecLine[6]!="battle_quest_id"){Ex.Logger.Log("QuestRandom.csv中字段[battle_quest_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			QuestRandomElement member = new QuestRandomElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.racequest_id=vecLine[2];
			member.hunt_quest_id=vecLine[3];
			member.treasure_monster_1_id=vecLine[4];
			member.treasure_monster_2_id=vecLine[5];
			member.battle_quest_id=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
