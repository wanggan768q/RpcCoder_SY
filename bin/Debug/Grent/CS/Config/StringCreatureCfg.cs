﻿using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC文本表配置数据类
public class StringCreatureElement
{
	public int id;               	//序号	序号
	public string sc;            	//简体中文	简体中文

	public bool IsValidate = false;
	public StringCreatureElement()
	{
		id = -1;
	}
};

//NPC文本表配置封装类
public class StringCreatureTable
{

	private StringCreatureTable()
	{
		m_mapElements = new Dictionary<int, StringCreatureElement>();
		m_emptyItem = new StringCreatureElement();
		m_vecAllElements = new List<StringCreatureElement>();
	}
	private Dictionary<int, StringCreatureElement> m_mapElements = null;
	private List<StringCreatureElement>	m_vecAllElements = null;
	private StringCreatureElement m_emptyItem = null;
	private static StringCreatureTable sInstance = null;

	public static StringCreatureTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StringCreatureTable();
			return sInstance;
		}
	}

	public StringCreatureElement GetElement(int key)
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

  public List<StringCreatureElement> GetAllElement(Predicate<StringCreatureElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StringCreature.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StringCreature.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StringCreature.bin]未找到");
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
			Ex.Logger.Log("StringCreature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringCreature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="sc"){Ex.Logger.Log("StringCreature.csv中字段[sc]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StringCreatureElement member = new StringCreatureElement();
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
			Ex.Logger.Log("StringCreature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringCreature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="sc"){Ex.Logger.Log("StringCreature.csv中字段[sc]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)2)
			{
				return false;
			}
			StringCreatureElement member = new StringCreatureElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.sc=vecLine[1];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
