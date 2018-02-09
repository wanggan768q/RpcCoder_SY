using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//Lua脚本配置数据类
public class LuaScriptElement
{
	public int lua_id;           	//脚本id	脚本id
	public string file;          	//	

	public bool IsValidate = false;
	public LuaScriptElement()
	{
		lua_id = -1;
	}
};

//Lua脚本配置封装类
public class LuaScriptTable
{

	private LuaScriptTable()
	{
		m_mapElements = new Dictionary<int, LuaScriptElement>();
		m_emptyItem = new LuaScriptElement();
		m_vecAllElements = new List<LuaScriptElement>();
	}
	private Dictionary<int, LuaScriptElement> m_mapElements = null;
	private List<LuaScriptElement>	m_vecAllElements = null;
	private LuaScriptElement m_emptyItem = null;
	private static LuaScriptTable sInstance = null;

	public static LuaScriptTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LuaScriptTable();
			return sInstance;
		}
	}

	public LuaScriptElement GetElement(int key)
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

  public List<LuaScriptElement> GetAllElement(Predicate<LuaScriptElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("LuaScript.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("LuaScript.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[LuaScript.bin]未找到");
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
			Ex.Logger.Log("LuaScript.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="lua_id"){Ex.Logger.Log("LuaScript.csv中字段[lua_id]位置不对应"); return false; }
		if(vecLine[1]!="file"){Ex.Logger.Log("LuaScript.csv中字段[file]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LuaScriptElement member = new LuaScriptElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.lua_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.file);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.lua_id] = member;
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
			Ex.Logger.Log("LuaScript.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="lua_id"){Ex.Logger.Log("LuaScript.csv中字段[lua_id]位置不对应"); return false; }
		if(vecLine[1]!="file"){Ex.Logger.Log("LuaScript.csv中字段[file]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)2)
			{
				return false;
			}
			LuaScriptElement member = new LuaScriptElement();
			member.lua_id=Convert.ToInt32(vecLine[0]);
			member.file=vecLine[1];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.lua_id] = member;
		}
		return true;
	}
};
