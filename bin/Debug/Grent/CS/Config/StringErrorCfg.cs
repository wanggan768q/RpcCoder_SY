using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//错误码表配置数据类
public class StringErrorElement
{
	public int id;               	//序号	需要必须为负值
	public int is_display;       	//是否显示	标示该错误码是否已文本提示框的形式显示在游戏中 0.不显示 1.显示
	public string sc;            	//简体中文	简体中文文本

	public bool IsValidate = false;
	public StringErrorElement()
	{
		id = -1;
	}
};

//错误码表配置封装类
public class StringErrorTable
{

	private StringErrorTable()
	{
		m_mapElements = new Dictionary<int, StringErrorElement>();
		m_emptyItem = new StringErrorElement();
		m_vecAllElements = new List<StringErrorElement>();
	}
	private Dictionary<int, StringErrorElement> m_mapElements = null;
	private List<StringErrorElement>	m_vecAllElements = null;
	private StringErrorElement m_emptyItem = null;
	private static StringErrorTable sInstance = null;

	public static StringErrorTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StringErrorTable();
			return sInstance;
		}
	}

	public StringErrorElement GetElement(int key)
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

  public List<StringErrorElement> GetAllElement(Predicate<StringErrorElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StringError.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StringError.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StringError.bin]未找到");
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
			Ex.Logger.Log("StringError.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringError.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="is_display"){Ex.Logger.Log("StringError.csv中字段[is_display]位置不对应"); return false; }
		if(vecLine[2]!="sc"){Ex.Logger.Log("StringError.csv中字段[sc]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StringErrorElement member = new StringErrorElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_display );
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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("StringError.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringError.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="is_display"){Ex.Logger.Log("StringError.csv中字段[is_display]位置不对应"); return false; }
		if(vecLine[2]!="sc"){Ex.Logger.Log("StringError.csv中字段[sc]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			StringErrorElement member = new StringErrorElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.is_display=Convert.ToInt32(vecLine[1]);
			member.sc=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
