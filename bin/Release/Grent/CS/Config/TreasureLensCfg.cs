using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝物库镜头表配置数据类
public class TreasureLensElement
{
	public int id;               	//ID	
	public string comment;       	//道具注释	策划用
	public float lens_depression;	//镜头俯角	主摄像机的俯角
	public float lens_distance;  	//镜头距人物距离	主摄像机距离人物的距离

	public bool IsValidate = false;
	public TreasureLensElement()
	{
		id = -1;
	}
};

//宝物库镜头表配置封装类
public class TreasureLensTable
{

	private TreasureLensTable()
	{
		m_mapElements = new Dictionary<int, TreasureLensElement>();
		m_emptyItem = new TreasureLensElement();
		m_vecAllElements = new List<TreasureLensElement>();
	}
	private Dictionary<int, TreasureLensElement> m_mapElements = null;
	private List<TreasureLensElement>	m_vecAllElements = null;
	private TreasureLensElement m_emptyItem = null;
	private static TreasureLensTable sInstance = null;

	public static TreasureLensTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TreasureLensTable();
			return sInstance;
		}
	}

	public TreasureLensElement GetElement(int key)
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

  public List<TreasureLensElement> GetAllElement(Predicate<TreasureLensElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TreasureLens.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TreasureLens.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TreasureLens.bin]未找到");
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
			Ex.Logger.Log("TreasureLens.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureLens.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureLens.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="lens_depression"){Ex.Logger.Log("TreasureLens.csv中字段[lens_depression]位置不对应"); return false; }
		if(vecLine[3]!="lens_distance"){Ex.Logger.Log("TreasureLens.csv中字段[lens_distance]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TreasureLensElement member = new TreasureLensElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.lens_depression);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.lens_distance);

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
			Ex.Logger.Log("TreasureLens.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureLens.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureLens.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="lens_depression"){Ex.Logger.Log("TreasureLens.csv中字段[lens_depression]位置不对应"); return false; }
		if(vecLine[3]!="lens_distance"){Ex.Logger.Log("TreasureLens.csv中字段[lens_distance]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			TreasureLensElement member = new TreasureLensElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.lens_depression=Convert.ToSingle(vecLine[2]);
			member.lens_distance=Convert.ToSingle(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
