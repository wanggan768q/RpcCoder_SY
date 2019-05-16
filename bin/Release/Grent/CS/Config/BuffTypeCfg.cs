using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//Buff冒字显示配置数据类
public class BuffTypeElement
{
	public int id;               	//对应的BuffID	对应的BuffID
	public string desc;          	//参数说明	仅说明
	public int desc_id;          	//StringBuff_buff_id	StringBuff_buff_id
	public string res;           	//资源名称	资源名称

	public bool IsValidate = false;
	public BuffTypeElement()
	{
		id = -1;
	}
};

//Buff冒字显示配置封装类
public class BuffTypeTable
{

	private BuffTypeTable()
	{
		m_mapElements = new Dictionary<int, BuffTypeElement>();
		m_emptyItem = new BuffTypeElement();
		m_vecAllElements = new List<BuffTypeElement>();
	}
	private Dictionary<int, BuffTypeElement> m_mapElements = null;
	private List<BuffTypeElement>	m_vecAllElements = null;
	private BuffTypeElement m_emptyItem = null;
	private static BuffTypeTable sInstance = null;

	public static BuffTypeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffTypeTable();
			return sInstance;
		}
	}

	public BuffTypeElement GetElement(int key)
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

  public List<BuffTypeElement> GetAllElement(Predicate<BuffTypeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BuffType.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BuffType.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[BuffType.bin]未找到");
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
			Ex.Logger.Log("BuffType.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffType.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffType.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("BuffType.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="res"){Ex.Logger.Log("BuffType.csv中字段[res]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffTypeElement member = new BuffTypeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.res);

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
			Ex.Logger.Log("BuffType.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffType.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffType.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("BuffType.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="res"){Ex.Logger.Log("BuffType.csv中字段[res]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			BuffTypeElement member = new BuffTypeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.desc=vecLine[1];
			member.desc_id=Convert.ToInt32(vecLine[2]);
			member.res=vecLine[3];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
