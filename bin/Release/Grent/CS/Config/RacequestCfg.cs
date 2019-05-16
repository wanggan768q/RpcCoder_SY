using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//占星任务表配置数据类
public class RacequestElement
{
	public int id;               	//数据索引	 
	public string comment;       	//任务备注	仅策划用
	public int quest_id;         	//任务id	填任务表中对应配置的id 
	public int racequest_level;  	//所需玩家等级	仅程序用
	public li racequest_weight;  	//权重	随机任务时的概率权重

	public bool IsValidate = false;
	public RacequestElement()
	{
		id = -1;
	}
};

//占星任务表配置封装类
public class RacequestTable
{

	private RacequestTable()
	{
		m_mapElements = new Dictionary<int, RacequestElement>();
		m_emptyItem = new RacequestElement();
		m_vecAllElements = new List<RacequestElement>();
	}
	private Dictionary<int, RacequestElement> m_mapElements = null;
	private List<RacequestElement>	m_vecAllElements = null;
	private RacequestElement m_emptyItem = null;
	private static RacequestTable sInstance = null;

	public static RacequestTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RacequestTable();
			return sInstance;
		}
	}

	public RacequestElement GetElement(int key)
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

  public List<RacequestElement> GetAllElement(Predicate<RacequestElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Racequest.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Racequest.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Racequest.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("Racequest.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Racequest.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Racequest.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Racequest.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="racequest_level"){Ex.Logger.Log("Racequest.csv中字段[racequest_level]位置不对应"); return false; }
		if(vecLine[4]!="racequest_weight"){Ex.Logger.Log("Racequest.csv中字段[racequest_weight]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RacequestElement member = new RacequestElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.racequest_level );
			readPos += GameAssist.ReadString( binContent, readPos, out member.racequest_weight);

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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("Racequest.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Racequest.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Racequest.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Racequest.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="racequest_level"){Ex.Logger.Log("Racequest.csv中字段[racequest_level]位置不对应"); return false; }
		if(vecLine[4]!="racequest_weight"){Ex.Logger.Log("Racequest.csv中字段[racequest_weight]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			RacequestElement member = new RacequestElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.quest_id=Convert.ToInt32(vecLine[2]);
			member.racequest_level=Convert.ToInt32(vecLine[3]);
			member.racequest_weight=vecLine[4];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
