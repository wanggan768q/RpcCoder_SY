using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//藏宝图表配置数据类
public class TreasureMapElement
{
	public int id;               	//主键id	场景+编号
	public string comment;       	//注释	场景+位置说明
	public int waypoint_id;      	//路点id	
	public li trigger_id;        	//触发id	10001|20001|30001 掉落包id|怪物id|宝箱id
	public li range;             	//刷怪权重	5|3|2 直接掉落|刷怪权重|刷宝箱权重

	public bool IsValidate = false;
	public TreasureMapElement()
	{
		id = -1;
	}
};

//藏宝图表配置封装类
public class TreasureMapTable
{

	private TreasureMapTable()
	{
		m_mapElements = new Dictionary<int, TreasureMapElement>();
		m_emptyItem = new TreasureMapElement();
		m_vecAllElements = new List<TreasureMapElement>();
	}
	private Dictionary<int, TreasureMapElement> m_mapElements = null;
	private List<TreasureMapElement>	m_vecAllElements = null;
	private TreasureMapElement m_emptyItem = null;
	private static TreasureMapTable sInstance = null;

	public static TreasureMapTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TreasureMapTable();
			return sInstance;
		}
	}

	public TreasureMapElement GetElement(int key)
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

  public List<TreasureMapElement> GetAllElement(Predicate<TreasureMapElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TreasureMap.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TreasureMap.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TreasureMap.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("TreasureMap.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureMap.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureMap.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="waypoint_id"){Ex.Logger.Log("TreasureMap.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[3]!="trigger_id"){Ex.Logger.Log("TreasureMap.csv中字段[trigger_id]位置不对应"); return false; }
		if(vecLine[4]!="range"){Ex.Logger.Log("TreasureMap.csv中字段[range]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TreasureMapElement member = new TreasureMapElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.trigger_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.range);

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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("TreasureMap.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureMap.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureMap.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="waypoint_id"){Ex.Logger.Log("TreasureMap.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[3]!="trigger_id"){Ex.Logger.Log("TreasureMap.csv中字段[trigger_id]位置不对应"); return false; }
		if(vecLine[4]!="range"){Ex.Logger.Log("TreasureMap.csv中字段[range]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			TreasureMapElement member = new TreasureMapElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.waypoint_id=Convert.ToInt32(vecLine[2]);
			member.trigger_id=vecLine[3];
			member.range=vecLine[4];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
