using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//世界等级配置数据类
public class WorldLevelElement
{
	public int id;               	//等级区间ID	
	public string comment;       	//备注	
	public int level_min;        	//等级差下限	
	public int level_max;        	//等级差上限	
	public float exp_ratio;      	//经验获取比例	

	public bool IsValidate = false;
	public WorldLevelElement()
	{
		id = -1;
	}
};

//世界等级配置封装类
public class WorldLevelTable
{

	private WorldLevelTable()
	{
		m_mapElements = new Dictionary<int, WorldLevelElement>();
		m_emptyItem = new WorldLevelElement();
		m_vecAllElements = new List<WorldLevelElement>();
	}
	private Dictionary<int, WorldLevelElement> m_mapElements = null;
	private List<WorldLevelElement>	m_vecAllElements = null;
	private WorldLevelElement m_emptyItem = null;
	private static WorldLevelTable sInstance = null;

	public static WorldLevelTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new WorldLevelTable();
			return sInstance;
		}
	}

	public WorldLevelElement GetElement(int key)
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

  public List<WorldLevelElement> GetAllElement(Predicate<WorldLevelElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("WorldLevel.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("WorldLevel.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[WorldLevel.bin]未找到");
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
			Ex.Logger.Log("WorldLevel.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("WorldLevel.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("WorldLevel.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="level_min"){Ex.Logger.Log("WorldLevel.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[3]!="level_max"){Ex.Logger.Log("WorldLevel.csv中字段[level_max]位置不对应"); return false; }
		if(vecLine[4]!="exp_ratio"){Ex.Logger.Log("WorldLevel.csv中字段[exp_ratio]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			WorldLevelElement member = new WorldLevelElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_max );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.exp_ratio);

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
			Ex.Logger.Log("WorldLevel.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("WorldLevel.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("WorldLevel.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="level_min"){Ex.Logger.Log("WorldLevel.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[3]!="level_max"){Ex.Logger.Log("WorldLevel.csv中字段[level_max]位置不对应"); return false; }
		if(vecLine[4]!="exp_ratio"){Ex.Logger.Log("WorldLevel.csv中字段[exp_ratio]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			WorldLevelElement member = new WorldLevelElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.level_min=Convert.ToInt32(vecLine[2]);
			member.level_max=Convert.ToInt32(vecLine[3]);
			member.exp_ratio=Convert.ToSingle(vecLine[4]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
