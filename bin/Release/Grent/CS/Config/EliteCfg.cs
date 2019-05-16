using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//精英怪配置数据类
public class EliteElement
{
	public int id;               	//主键id	100奥斯缇温 200马鬃草原 300精灵之森 400科尔努斯 500飞龙溪谷 600奎利亚
	public string comment;       	//注释	
	public int waypoint_id;      	//刷新路点id	
	public int npc_id;           	//怪物id	

	public bool IsValidate = false;
	public EliteElement()
	{
		id = -1;
	}
};

//精英怪配置封装类
public class EliteTable
{

	private EliteTable()
	{
		m_mapElements = new Dictionary<int, EliteElement>();
		m_emptyItem = new EliteElement();
		m_vecAllElements = new List<EliteElement>();
	}
	private Dictionary<int, EliteElement> m_mapElements = null;
	private List<EliteElement>	m_vecAllElements = null;
	private EliteElement m_emptyItem = null;
	private static EliteTable sInstance = null;

	public static EliteTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EliteTable();
			return sInstance;
		}
	}

	public EliteElement GetElement(int key)
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

  public List<EliteElement> GetAllElement(Predicate<EliteElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Elite.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Elite.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Elite.bin]未找到");
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
			Ex.Logger.Log("Elite.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Elite.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Elite.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="waypoint_id"){Ex.Logger.Log("Elite.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[3]!="npc_id"){Ex.Logger.Log("Elite.csv中字段[npc_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EliteElement member = new EliteElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_id );

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
			Ex.Logger.Log("Elite.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Elite.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Elite.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="waypoint_id"){Ex.Logger.Log("Elite.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[3]!="npc_id"){Ex.Logger.Log("Elite.csv中字段[npc_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			EliteElement member = new EliteElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.waypoint_id=Convert.ToInt32(vecLine[2]);
			member.npc_id=Convert.ToInt32(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
