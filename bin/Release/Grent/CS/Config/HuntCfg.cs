using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//猎魔表配置数据类
public class HuntElement
{
	public int id;               	//主键id	
	public string comment;       	//备注	
	public int quest_id;         	//任务id	
	public li monster_1_id;      	//小怪1	第一波
	public li monster_2_id;      	//小怪2	第二波
	public li monster_3_id;      	//小怪3	第三波
	public li monster_4_id;      	//首领	boss波

	public bool IsValidate = false;
	public HuntElement()
	{
		id = -1;
	}
};

//猎魔表配置封装类
public class HuntTable
{

	private HuntTable()
	{
		m_mapElements = new Dictionary<int, HuntElement>();
		m_emptyItem = new HuntElement();
		m_vecAllElements = new List<HuntElement>();
	}
	private Dictionary<int, HuntElement> m_mapElements = null;
	private List<HuntElement>	m_vecAllElements = null;
	private HuntElement m_emptyItem = null;
	private static HuntTable sInstance = null;

	public static HuntTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HuntTable();
			return sInstance;
		}
	}

	public HuntElement GetElement(int key)
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

  public List<HuntElement> GetAllElement(Predicate<HuntElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Hunt.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Hunt.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Hunt.bin]未找到");
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
			Ex.Logger.Log("Hunt.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Hunt.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Hunt.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Hunt.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="monster_1_id"){Ex.Logger.Log("Hunt.csv中字段[monster_1_id]位置不对应"); return false; }
		if(vecLine[4]!="monster_2_id"){Ex.Logger.Log("Hunt.csv中字段[monster_2_id]位置不对应"); return false; }
		if(vecLine[5]!="monster_3_id"){Ex.Logger.Log("Hunt.csv中字段[monster_3_id]位置不对应"); return false; }
		if(vecLine[6]!="monster_4_id"){Ex.Logger.Log("Hunt.csv中字段[monster_4_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HuntElement member = new HuntElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_4_id);

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
			Ex.Logger.Log("Hunt.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Hunt.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Hunt.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Hunt.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="monster_1_id"){Ex.Logger.Log("Hunt.csv中字段[monster_1_id]位置不对应"); return false; }
		if(vecLine[4]!="monster_2_id"){Ex.Logger.Log("Hunt.csv中字段[monster_2_id]位置不对应"); return false; }
		if(vecLine[5]!="monster_3_id"){Ex.Logger.Log("Hunt.csv中字段[monster_3_id]位置不对应"); return false; }
		if(vecLine[6]!="monster_4_id"){Ex.Logger.Log("Hunt.csv中字段[monster_4_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			HuntElement member = new HuntElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.quest_id=Convert.ToInt32(vecLine[2]);
			member.monster_1_id=vecLine[3];
			member.monster_2_id=vecLine[4];
			member.monster_3_id=vecLine[5];
			member.monster_4_id=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
