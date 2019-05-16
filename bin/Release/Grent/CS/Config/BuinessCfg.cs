using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//生活技能细则配置数据类
public class BuinessElement
{
	public int id;               	//生活技能子等级id	id=生活技能idx10+等级
	public int type;             	//对应生活技能ID	对应生活技能ID
	public int lv;               	//等级	等级
	public int exp;              	//级别所需exp	升至该等级所需
	public int cost;             	//级段对应制作消耗精力值	暂无精力相关
	public li item;              	//可制造道具	道具表中id
	public int unlock_lv;        	//解锁新道具等级	等级
	public int unlock_item;      	//解锁新道具ID	道具表中id
	public int loot_item;        	//制作时产出道具	填写DropWeight_权值掉落表的掉落ID

	public bool IsValidate = false;
	public BuinessElement()
	{
		id = -1;
	}
};

//生活技能细则配置封装类
public class BuinessTable
{

	private BuinessTable()
	{
		m_mapElements = new Dictionary<int, BuinessElement>();
		m_emptyItem = new BuinessElement();
		m_vecAllElements = new List<BuinessElement>();
	}
	private Dictionary<int, BuinessElement> m_mapElements = null;
	private List<BuinessElement>	m_vecAllElements = null;
	private BuinessElement m_emptyItem = null;
	private static BuinessTable sInstance = null;

	public static BuinessTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuinessTable();
			return sInstance;
		}
	}

	public BuinessElement GetElement(int key)
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

  public List<BuinessElement> GetAllElement(Predicate<BuinessElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Buiness.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Buiness.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Buiness.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("Buiness.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buiness.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("Buiness.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="lv"){Ex.Logger.Log("Buiness.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[3]!="exp"){Ex.Logger.Log("Buiness.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[4]!="cost"){Ex.Logger.Log("Buiness.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[5]!="item"){Ex.Logger.Log("Buiness.csv中字段[item]位置不对应"); return false; }
		if(vecLine[6]!="unlock_lv"){Ex.Logger.Log("Buiness.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[7]!="unlock_item"){Ex.Logger.Log("Buiness.csv中字段[unlock_item]位置不对应"); return false; }
		if(vecLine[8]!="loot_item"){Ex.Logger.Log("Buiness.csv中字段[loot_item]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuinessElement member = new BuinessElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cost );
			readPos += GameAssist.ReadString( binContent, readPos, out member.item);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_item );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.loot_item );

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("Buiness.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buiness.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("Buiness.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="lv"){Ex.Logger.Log("Buiness.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[3]!="exp"){Ex.Logger.Log("Buiness.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[4]!="cost"){Ex.Logger.Log("Buiness.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[5]!="item"){Ex.Logger.Log("Buiness.csv中字段[item]位置不对应"); return false; }
		if(vecLine[6]!="unlock_lv"){Ex.Logger.Log("Buiness.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[7]!="unlock_item"){Ex.Logger.Log("Buiness.csv中字段[unlock_item]位置不对应"); return false; }
		if(vecLine[8]!="loot_item"){Ex.Logger.Log("Buiness.csv中字段[loot_item]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			BuinessElement member = new BuinessElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.type=Convert.ToInt32(vecLine[1]);
			member.lv=Convert.ToInt32(vecLine[2]);
			member.exp=Convert.ToInt32(vecLine[3]);
			member.cost=Convert.ToInt32(vecLine[4]);
			member.item=vecLine[5];
			member.unlock_lv=Convert.ToInt32(vecLine[6]);
			member.unlock_item=Convert.ToInt32(vecLine[7]);
			member.loot_item=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
