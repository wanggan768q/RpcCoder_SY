using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物星级表配置数据类
public class PetRankElement
{
	public int id;               	//宠物星级id	对应宠物星级数量
	public string comment;       	//注释	策划用
	public ls rank_lv;           	//星级层数	该星级对应的资源 1为星 2为月 3为日 已填充|未填充
	public int rank_star;        	//星级星数	该星级对应的显示星数 1~5
	public float attribute_scale;	//升级属性加成	每次升级属性增加倍率 1表示为100%
	public int unlock_lv;        	//锁定等级	星级锁定等级

	public bool IsValidate = false;
	public PetRankElement()
	{
		id = -1;
	}
};

//宠物星级表配置封装类
public class PetRankTable
{

	private PetRankTable()
	{
		m_mapElements = new Dictionary<int, PetRankElement>();
		m_emptyItem = new PetRankElement();
		m_vecAllElements = new List<PetRankElement>();
	}
	private Dictionary<int, PetRankElement> m_mapElements = null;
	private List<PetRankElement>	m_vecAllElements = null;
	private PetRankElement m_emptyItem = null;
	private static PetRankTable sInstance = null;

	public static PetRankTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetRankTable();
			return sInstance;
		}
	}

	public PetRankElement GetElement(int key)
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

  public List<PetRankElement> GetAllElement(Predicate<PetRankElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetRank.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetRank.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetRank.bin]未找到");
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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("PetRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetRank.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetRank.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_lv"){Ex.Logger.Log("PetRank.csv中字段[rank_lv]位置不对应"); return false; }
		if(vecLine[3]!="rank_star"){Ex.Logger.Log("PetRank.csv中字段[rank_star]位置不对应"); return false; }
		if(vecLine[4]!="attribute_scale"){Ex.Logger.Log("PetRank.csv中字段[attribute_scale]位置不对应"); return false; }
		if(vecLine[5]!="unlock_lv"){Ex.Logger.Log("PetRank.csv中字段[unlock_lv]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetRankElement member = new PetRankElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rank_lv);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank_star );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attribute_scale);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );

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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("PetRank.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetRank.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetRank.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_lv"){Ex.Logger.Log("PetRank.csv中字段[rank_lv]位置不对应"); return false; }
		if(vecLine[3]!="rank_star"){Ex.Logger.Log("PetRank.csv中字段[rank_star]位置不对应"); return false; }
		if(vecLine[4]!="attribute_scale"){Ex.Logger.Log("PetRank.csv中字段[attribute_scale]位置不对应"); return false; }
		if(vecLine[5]!="unlock_lv"){Ex.Logger.Log("PetRank.csv中字段[unlock_lv]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			PetRankElement member = new PetRankElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.rank_lv=vecLine[2];
			member.rank_star=Convert.ToInt32(vecLine[3]);
			member.attribute_scale=Convert.ToSingle(vecLine[4]);
			member.unlock_lv=Convert.ToInt32(vecLine[5]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
