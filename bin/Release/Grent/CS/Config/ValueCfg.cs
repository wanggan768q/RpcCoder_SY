using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//参数配置数据类
public class ValueElement
{
	public int id;               	//序号	序号
	public int value;            	//值	值
	public string comment;       	//描述	描述

	public bool IsValidate = false;
	public ValueElement()
	{
		id = -1;
	}
};

//参数配置封装类
public class ValueTable
{

	private ValueTable()
	{
		m_mapElements = new Dictionary<int, ValueElement>();
		m_emptyItem = new ValueElement();
		m_vecAllElements = new List<ValueElement>();
	}
	private Dictionary<int, ValueElement> m_mapElements = null;
	private List<ValueElement>	m_vecAllElements = null;
	private ValueElement m_emptyItem = null;
	private static ValueTable sInstance = null;

	public static ValueTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ValueTable();
			return sInstance;
		}
	}

	public ValueElement GetElement(int key)
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

  public List<ValueElement> GetAllElement(Predicate<ValueElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Value.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Value.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Value.bin]未找到");
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
			Ex.Logger.Log("Value.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Value.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="value"){Ex.Logger.Log("Value.csv中字段[value]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Value.csv中字段[comment]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ValueElement member = new ValueElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.value );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);

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
			Ex.Logger.Log("Value.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Value.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="value"){Ex.Logger.Log("Value.csv中字段[value]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Value.csv中字段[comment]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			ValueElement member = new ValueElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.value=Convert.ToInt32(vecLine[1]);
			member.comment=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
