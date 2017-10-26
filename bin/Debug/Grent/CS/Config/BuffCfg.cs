using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//效果配置数据类
public class BuffElement
{
	public int id;               	//数据索引	数据索引
	public int buffID;           	//对应的BuffID	对应的BuffID
	public int overTimed;        	//是否是延时性Buff	是否是延时性Buff
	public int continuance;      	//如果是延时的，那么延时时间是多少	如果是延时的，那么延时时间是多少
	public li pars;              	//参数	参数

	public bool IsValidate = false;
	public BuffElement()
	{
		id = -1;
	}
};

//效果配置封装类
public class BuffTable
{

	private BuffTable()
	{
		m_mapElements = new Dictionary<int, BuffElement>();
		m_emptyItem = new BuffElement();
		m_vecAllElements = new List<BuffElement>();
	}
	private Dictionary<int, BuffElement> m_mapElements = null;
	private List<BuffElement>	m_vecAllElements = null;
	private BuffElement m_emptyItem = null;
	private static BuffTable sInstance = null;

	public static BuffTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffTable();
			return sInstance;
		}
	}

	public BuffElement GetElement(int key)
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

  public List<BuffElement> GetAllElement(Predicate<BuffElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Buff.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Buff.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Buff.bin]未找到");
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
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[3]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[4]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffElement member = new BuffElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.overTimed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);

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
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[3]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[4]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			BuffElement member = new BuffElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.buffID=Convert.ToInt32(vecLine[1]);
			member.overTimed=Convert.ToInt32(vecLine[2]);
			member.continuance=Convert.ToInt32(vecLine[3]);
			member.pars=vecLine[4];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
