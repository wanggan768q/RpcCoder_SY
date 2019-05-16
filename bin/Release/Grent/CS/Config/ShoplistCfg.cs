using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//积分商店表配置数据类
public class ShoplistElement
{
	public int id;               	//商店ID	填写ID即可
	public string comment;       	//注释	策划用
	public int shop_name;        	//商店名	填写文本ID
	public int order;            	//商店顺序	从低至高排列
	public int currency;         	//货币ID	货币表货币ID
	public int condition;        	//限制条件文本	填写文本ID
	public li source;            	//货币来源	类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留

	public bool IsValidate = false;
	public ShoplistElement()
	{
		id = -1;
	}
};

//积分商店表配置封装类
public class ShoplistTable
{

	private ShoplistTable()
	{
		m_mapElements = new Dictionary<int, ShoplistElement>();
		m_emptyItem = new ShoplistElement();
		m_vecAllElements = new List<ShoplistElement>();
	}
	private Dictionary<int, ShoplistElement> m_mapElements = null;
	private List<ShoplistElement>	m_vecAllElements = null;
	private ShoplistElement m_emptyItem = null;
	private static ShoplistTable sInstance = null;

	public static ShoplistTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ShoplistTable();
			return sInstance;
		}
	}

	public ShoplistElement GetElement(int key)
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

  public List<ShoplistElement> GetAllElement(Predicate<ShoplistElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Shoplist.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Shoplist.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Shoplist.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("Shoplist.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Shoplist.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Shoplist.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="shop_name"){Ex.Logger.Log("Shoplist.csv中字段[shop_name]位置不对应"); return false; }
		if(vecLine[3]!="order"){Ex.Logger.Log("Shoplist.csv中字段[order]位置不对应"); return false; }
		if(vecLine[4]!="currency"){Ex.Logger.Log("Shoplist.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[5]!="condition"){Ex.Logger.Log("Shoplist.csv中字段[condition]位置不对应"); return false; }
		if(vecLine[6]!="source"){Ex.Logger.Log("Shoplist.csv中字段[source]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ShoplistElement member = new ShoplistElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.shop_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.currency );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.condition );
			readPos += GameAssist.ReadString( binContent, readPos, out member.source);

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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("Shoplist.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Shoplist.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Shoplist.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="shop_name"){Ex.Logger.Log("Shoplist.csv中字段[shop_name]位置不对应"); return false; }
		if(vecLine[3]!="order"){Ex.Logger.Log("Shoplist.csv中字段[order]位置不对应"); return false; }
		if(vecLine[4]!="currency"){Ex.Logger.Log("Shoplist.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[5]!="condition"){Ex.Logger.Log("Shoplist.csv中字段[condition]位置不对应"); return false; }
		if(vecLine[6]!="source"){Ex.Logger.Log("Shoplist.csv中字段[source]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			ShoplistElement member = new ShoplistElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.shop_name=Convert.ToInt32(vecLine[2]);
			member.order=Convert.ToInt32(vecLine[3]);
			member.currency=Convert.ToInt32(vecLine[4]);
			member.condition=Convert.ToInt32(vecLine[5]);
			member.source=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
