using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//药剂表配置数据类
public class PotionElement
{
	public int id;               	//id	药剂功能的id
	public string comment;       	//注释	该数据的功能
	public int type;             	//药剂类型	对应该道具是血池还是药剂 0 --血池 1 --药剂
	public int item_id;          	//道具id	对应的道具的id

	public bool IsValidate = false;
	public PotionElement()
	{
		id = -1;
	}
};

//药剂表配置封装类
public class PotionTable
{

	private PotionTable()
	{
		m_mapElements = new Dictionary<int, PotionElement>();
		m_emptyItem = new PotionElement();
		m_vecAllElements = new List<PotionElement>();
	}
	private Dictionary<int, PotionElement> m_mapElements = null;
	private List<PotionElement>	m_vecAllElements = null;
	private PotionElement m_emptyItem = null;
	private static PotionTable sInstance = null;

	public static PotionTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PotionTable();
			return sInstance;
		}
	}

	public PotionElement GetElement(int key)
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

  public List<PotionElement> GetAllElement(Predicate<PotionElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Potion.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Potion.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Potion.bin]未找到");
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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("Potion.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Potion.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Potion.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Potion.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="item_id"){Ex.Logger.Log("Potion.csv中字段[item_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PotionElement member = new PotionElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_id );

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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("Potion.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Potion.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Potion.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Potion.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="item_id"){Ex.Logger.Log("Potion.csv中字段[item_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			PotionElement member = new PotionElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.type=Convert.ToInt32(vecLine[2]);
			member.item_id=Convert.ToInt32(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
