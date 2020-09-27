using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//界面文本表配置数据类
public class StringUiElement
{
	public int id;               	//序号	数字编号
	public string sc;            	//简体中文	简体中文

	public bool IsValidate = false;
	public StringUiElement()
	{
		id = -1;
	}
};

//界面文本表配置封装类
public class StringUiTable
{

	private StringUiTable()
	{
		m_mapElements = new Dictionary<int, StringUiElement>();
		m_emptyItem = new StringUiElement();
		m_vecAllElements = new List<StringUiElement>();
	}
	private Dictionary<int, StringUiElement> m_mapElements = null;
	private List<StringUiElement>	m_vecAllElements = null;
	private StringUiElement m_emptyItem = null;
	private static StringUiTable sInstance = null;

	public static StringUiTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StringUiTable();
			return sInstance;
		}
	}

	public StringUiElement GetElement(int key)
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

  public List<StringUiElement> GetAllElement(Predicate<StringUiElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StringUi.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StringUi.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StringUi.bin]未找到");
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
		if(vecLine.Count != 2)
		{
			Ex.Logger.Log("StringUi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringUi.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="sc"){Ex.Logger.Log("StringUi.csv中字段[sc]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StringUiElement member = new StringUiElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.sc);

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
		if(vecLine.Count != 2)
		{
			Ex.Logger.Log("StringUi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringUi.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="sc"){Ex.Logger.Log("StringUi.csv中字段[sc]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)2)
			{
				return false;
			}
			StringUiElement member = new StringUiElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.sc=vecLine[1];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
