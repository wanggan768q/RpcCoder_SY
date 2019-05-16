using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//头顶信息表配置数据类
public class HeadUpInfoElement
{
	public int id;               	//序号	
	public string comment;       	//注释	策划用
	public int priority;         	//显示优先级	优先级越低，显示位置越靠下
	public float interspace;     	//元件间距	该元件距离下一层元件中心的距离（3D数值）

	public bool IsValidate = false;
	public HeadUpInfoElement()
	{
		id = -1;
	}
};

//头顶信息表配置封装类
public class HeadUpInfoTable
{

	private HeadUpInfoTable()
	{
		m_mapElements = new Dictionary<int, HeadUpInfoElement>();
		m_emptyItem = new HeadUpInfoElement();
		m_vecAllElements = new List<HeadUpInfoElement>();
	}
	private Dictionary<int, HeadUpInfoElement> m_mapElements = null;
	private List<HeadUpInfoElement>	m_vecAllElements = null;
	private HeadUpInfoElement m_emptyItem = null;
	private static HeadUpInfoTable sInstance = null;

	public static HeadUpInfoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new HeadUpInfoTable();
			return sInstance;
		}
	}

	public HeadUpInfoElement GetElement(int key)
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

  public List<HeadUpInfoElement> GetAllElement(Predicate<HeadUpInfoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("HeadUpInfo.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("HeadUpInfo.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[HeadUpInfo.bin]未找到");
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
			Ex.Logger.Log("HeadUpInfo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("HeadUpInfo.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("HeadUpInfo.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="priority"){Ex.Logger.Log("HeadUpInfo.csv中字段[priority]位置不对应"); return false; }
		if(vecLine[3]!="interspace"){Ex.Logger.Log("HeadUpInfo.csv中字段[interspace]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			HeadUpInfoElement member = new HeadUpInfoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.priority );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.interspace);

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
			Ex.Logger.Log("HeadUpInfo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("HeadUpInfo.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("HeadUpInfo.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="priority"){Ex.Logger.Log("HeadUpInfo.csv中字段[priority]位置不对应"); return false; }
		if(vecLine[3]!="interspace"){Ex.Logger.Log("HeadUpInfo.csv中字段[interspace]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			HeadUpInfoElement member = new HeadUpInfoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.priority=Convert.ToInt32(vecLine[2]);
			member.interspace=Convert.ToSingle(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
