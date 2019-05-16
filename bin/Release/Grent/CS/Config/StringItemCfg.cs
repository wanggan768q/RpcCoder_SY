using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//道具文本表配置数据类
public class StringItemElement
{
	public int id;               	//序号	100以内用作测试  道具文本规则 道具id*10+index{0} index-0_名称;1_描述  套装命名规则 套装id*10+index{0} index-0_名称;1_描述  道具类型规则 道具类型id*1000+道具子类型id
	public string comment;       	//文本内容备注	文本内容备注
	public string sc;            	//简体中文	简体中文

	public bool IsValidate = false;
	public StringItemElement()
	{
		id = -1;
	}
};

//道具文本表配置封装类
public class StringItemTable
{

	private StringItemTable()
	{
		m_mapElements = new Dictionary<int, StringItemElement>();
		m_emptyItem = new StringItemElement();
		m_vecAllElements = new List<StringItemElement>();
	}
	private Dictionary<int, StringItemElement> m_mapElements = null;
	private List<StringItemElement>	m_vecAllElements = null;
	private StringItemElement m_emptyItem = null;
	private static StringItemTable sInstance = null;

	public static StringItemTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StringItemTable();
			return sInstance;
		}
	}

	public StringItemElement GetElement(int key)
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

  public List<StringItemElement> GetAllElement(Predicate<StringItemElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StringItem.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StringItem.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StringItem.bin]未找到");
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
			Ex.Logger.Log("StringItem.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringItem.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StringItem.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="sc"){Ex.Logger.Log("StringItem.csv中字段[sc]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StringItemElement member = new StringItemElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
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
			Ex.Logger.Log("StringItem.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringItem.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StringItem.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="sc"){Ex.Logger.Log("StringItem.csv中字段[sc]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			StringItemElement member = new StringItemElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.sc=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
