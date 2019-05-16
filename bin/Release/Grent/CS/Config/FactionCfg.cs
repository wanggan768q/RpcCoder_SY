using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//阵营组关系配置数据类
public class FactionElement
{
	public int id;               	//组id	组id 必须保证ID 是顺序的
	public string comment;       	//组名	仅策划用
	public string group;         	//组标识	0=无效 1=友好 2=中立 3=敌对
	public int g0;               	//0	
	public int g1;               	//通用阵营	
	public int g2;               	//中立阵营	
	public int g3;               	//敌对阵营	
	public int g4;               	//野外战场阵营A	
	public int g5;               	//野外战场阵营B	
	public int g6;               	//阵营战阵营关系	
	public li allgroup;          	//合并	公式不要手填！！！

	public bool IsValidate = false;
	public FactionElement()
	{
		id = -1;
	}
};

//阵营组关系配置封装类
public class FactionTable
{

	private FactionTable()
	{
		m_mapElements = new Dictionary<int, FactionElement>();
		m_emptyItem = new FactionElement();
		m_vecAllElements = new List<FactionElement>();
	}
	private Dictionary<int, FactionElement> m_mapElements = null;
	private List<FactionElement>	m_vecAllElements = null;
	private FactionElement m_emptyItem = null;
	private static FactionTable sInstance = null;

	public static FactionTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new FactionTable();
			return sInstance;
		}
	}

	public FactionElement GetElement(int key)
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

  public List<FactionElement> GetAllElement(Predicate<FactionElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Faction.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Faction.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Faction.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("Faction.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Faction.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Faction.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("Faction.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g0"){Ex.Logger.Log("Faction.csv中字段[g0]位置不对应"); return false; }
		if(vecLine[4]!="g1"){Ex.Logger.Log("Faction.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[5]!="g2"){Ex.Logger.Log("Faction.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[6]!="g3"){Ex.Logger.Log("Faction.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[7]!="g4"){Ex.Logger.Log("Faction.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[8]!="g5"){Ex.Logger.Log("Faction.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[9]!="g6"){Ex.Logger.Log("Faction.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[10]!="allgroup"){Ex.Logger.Log("Faction.csv中字段[allgroup]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			FactionElement member = new FactionElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.group);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g0 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g6 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.allgroup);

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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("Faction.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Faction.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Faction.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("Faction.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g0"){Ex.Logger.Log("Faction.csv中字段[g0]位置不对应"); return false; }
		if(vecLine[4]!="g1"){Ex.Logger.Log("Faction.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[5]!="g2"){Ex.Logger.Log("Faction.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[6]!="g3"){Ex.Logger.Log("Faction.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[7]!="g4"){Ex.Logger.Log("Faction.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[8]!="g5"){Ex.Logger.Log("Faction.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[9]!="g6"){Ex.Logger.Log("Faction.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[10]!="allgroup"){Ex.Logger.Log("Faction.csv中字段[allgroup]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			FactionElement member = new FactionElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.group=vecLine[2];
			member.g0=Convert.ToInt32(vecLine[3]);
			member.g1=Convert.ToInt32(vecLine[4]);
			member.g2=Convert.ToInt32(vecLine[5]);
			member.g3=Convert.ToInt32(vecLine[6]);
			member.g4=Convert.ToInt32(vecLine[7]);
			member.g5=Convert.ToInt32(vecLine[8]);
			member.g6=Convert.ToInt32(vecLine[9]);
			member.allgroup=vecLine[10];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
