using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//怪物模板配置数据类
public class MonsterElement
{
	public int id;               	//序号	序号
	public string name;          	//名字	名字
	public li skills;            	//属性参数1	属性参数1

	public bool IsValidate = false;
	public MonsterElement()
	{
		id = -1;
	}
};

//怪物模板配置封装类
public class MonsterTable
{

	private MonsterTable()
	{
		m_mapElements = new Dictionary<int, MonsterElement>();
		m_emptyItem = new MonsterElement();
		m_vecAllElements = new List<MonsterElement>();
	}
	private Dictionary<int, MonsterElement> m_mapElements = null;
	private List<MonsterElement>	m_vecAllElements = null;
	private MonsterElement m_emptyItem = null;
	private static MonsterTable sInstance = null;

	public static MonsterTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MonsterTable();
			return sInstance;
		}
	}

	public MonsterElement GetElement(int key)
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

  public List<MonsterElement> GetAllElement(Predicate<MonsterElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Monster.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Monster.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Monster.bin]未找到");
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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("Monster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Monster.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Monster.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="skills"){Ex.Logger.Log("Monster.csv中字段[skills]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MonsterElement member = new MonsterElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.skills);

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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("Monster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Monster.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Monster.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="skills"){Ex.Logger.Log("Monster.csv中字段[skills]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			MonsterElement member = new MonsterElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=vecLine[1];
			member.skills=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
