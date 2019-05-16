using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//任务对话表配置数据类
public class StringChatmenuElement
{
	public int id;               	//序号	序号
	public string comment;       	//文本内容备注	文本内容备注
	public int npc;              	//发言者	填写NPC的ID，0为玩家自己
	public string sc;            	//简体中文	简体中文

	public bool IsValidate = false;
	public StringChatmenuElement()
	{
		id = -1;
	}
};

//任务对话表配置封装类
public class StringChatmenuTable
{

	private StringChatmenuTable()
	{
		m_mapElements = new Dictionary<int, StringChatmenuElement>();
		m_emptyItem = new StringChatmenuElement();
		m_vecAllElements = new List<StringChatmenuElement>();
	}
	private Dictionary<int, StringChatmenuElement> m_mapElements = null;
	private List<StringChatmenuElement>	m_vecAllElements = null;
	private StringChatmenuElement m_emptyItem = null;
	private static StringChatmenuTable sInstance = null;

	public static StringChatmenuTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StringChatmenuTable();
			return sInstance;
		}
	}

	public StringChatmenuElement GetElement(int key)
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

  public List<StringChatmenuElement> GetAllElement(Predicate<StringChatmenuElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StringChatmenu.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StringChatmenu.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StringChatmenu.bin]未找到");
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
			Ex.Logger.Log("StringChatmenu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringChatmenu.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StringChatmenu.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="npc"){Ex.Logger.Log("StringChatmenu.csv中字段[npc]位置不对应"); return false; }
		if(vecLine[3]!="sc"){Ex.Logger.Log("StringChatmenu.csv中字段[sc]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StringChatmenuElement member = new StringChatmenuElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc );
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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("StringChatmenu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StringChatmenu.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StringChatmenu.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="npc"){Ex.Logger.Log("StringChatmenu.csv中字段[npc]位置不对应"); return false; }
		if(vecLine[3]!="sc"){Ex.Logger.Log("StringChatmenu.csv中字段[sc]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			StringChatmenuElement member = new StringChatmenuElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.npc=Convert.ToInt32(vecLine[2]);
			member.sc=vecLine[3];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
