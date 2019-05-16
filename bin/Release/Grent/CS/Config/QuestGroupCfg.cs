using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//任务组配置数据类
public class QuestGroupElement
{
	public int id;               	//任务组id	对应任务组别
	public string comment;       	//注释	备注
	public li quest_range_id;    	//任务段	关联quest表

	public bool IsValidate = false;
	public QuestGroupElement()
	{
		id = -1;
	}
};

//任务组配置封装类
public class QuestGroupTable
{

	private QuestGroupTable()
	{
		m_mapElements = new Dictionary<int, QuestGroupElement>();
		m_emptyItem = new QuestGroupElement();
		m_vecAllElements = new List<QuestGroupElement>();
	}
	private Dictionary<int, QuestGroupElement> m_mapElements = null;
	private List<QuestGroupElement>	m_vecAllElements = null;
	private QuestGroupElement m_emptyItem = null;
	private static QuestGroupTable sInstance = null;

	public static QuestGroupTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new QuestGroupTable();
			return sInstance;
		}
	}

	public QuestGroupElement GetElement(int key)
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

  public List<QuestGroupElement> GetAllElement(Predicate<QuestGroupElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("QuestGroup.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("QuestGroup.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[QuestGroup.bin]未找到");
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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("QuestGroup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QuestGroup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QuestGroup.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_range_id"){Ex.Logger.Log("QuestGroup.csv中字段[quest_range_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			QuestGroupElement member = new QuestGroupElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_range_id);

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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("QuestGroup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QuestGroup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QuestGroup.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_range_id"){Ex.Logger.Log("QuestGroup.csv中字段[quest_range_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			QuestGroupElement member = new QuestGroupElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.quest_range_id=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
