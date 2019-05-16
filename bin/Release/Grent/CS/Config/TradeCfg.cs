using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//交易行表配置数据类
public class TradeElement
{
	public int id;               	//道具ID	道具ID
	public string comment;       	//道具注释	策划用
	public int type;             	//道具1级类	策划用
	public int type_name;        	//大类名称	用于显示， 从StringItem表中获取
	public int subtype;          	//道具子类	策划用
	public int subtype_name;     	//子类名称	用于显示， 从StringItem表中获取
	public li price_range;       	//道具推荐单价幅度	可交易道具的价值区间 单位为金币
	public int is_publicity;     	//是否需要公示	0：上架无需上架 1：上架需要公示
	public int type_coin;        	//可交易货币类型	0：仅金币交易 1：仅钻石交易 2：金币和钻石交易
	public int benchmark_price;  	//开服基准价	0：非定价商品
	public li benchmark_price_range;	//基准价浮动范围	基准价浮动范围
	public lf benchmark_price_ratio;	//基准价浮动系数	基准价浮动系数

	public bool IsValidate = false;
	public TradeElement()
	{
		id = -1;
	}
};

//交易行表配置封装类
public class TradeTable
{

	private TradeTable()
	{
		m_mapElements = new Dictionary<int, TradeElement>();
		m_emptyItem = new TradeElement();
		m_vecAllElements = new List<TradeElement>();
	}
	private Dictionary<int, TradeElement> m_mapElements = null;
	private List<TradeElement>	m_vecAllElements = null;
	private TradeElement m_emptyItem = null;
	private static TradeTable sInstance = null;

	public static TradeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TradeTable();
			return sInstance;
		}
	}

	public TradeElement GetElement(int key)
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

  public List<TradeElement> GetAllElement(Predicate<TradeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Trade.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Trade.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Trade.bin]未找到");
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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("Trade.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Trade.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Trade.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Trade.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="type_name"){Ex.Logger.Log("Trade.csv中字段[type_name]位置不对应"); return false; }
		if(vecLine[4]!="subtype"){Ex.Logger.Log("Trade.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[5]!="subtype_name"){Ex.Logger.Log("Trade.csv中字段[subtype_name]位置不对应"); return false; }
		if(vecLine[6]!="price_range"){Ex.Logger.Log("Trade.csv中字段[price_range]位置不对应"); return false; }
		if(vecLine[7]!="is_publicity"){Ex.Logger.Log("Trade.csv中字段[is_publicity]位置不对应"); return false; }
		if(vecLine[8]!="type_coin"){Ex.Logger.Log("Trade.csv中字段[type_coin]位置不对应"); return false; }
		if(vecLine[9]!="benchmark_price"){Ex.Logger.Log("Trade.csv中字段[benchmark_price]位置不对应"); return false; }
		if(vecLine[10]!="benchmark_price_range"){Ex.Logger.Log("Trade.csv中字段[benchmark_price_range]位置不对应"); return false; }
		if(vecLine[11]!="benchmark_price_ratio"){Ex.Logger.Log("Trade.csv中字段[benchmark_price_ratio]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TradeElement member = new TradeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.price_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_publicity );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type_coin );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.benchmark_price );
			readPos += GameAssist.ReadString( binContent, readPos, out member.benchmark_price_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.benchmark_price_ratio);

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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("Trade.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Trade.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Trade.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Trade.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="type_name"){Ex.Logger.Log("Trade.csv中字段[type_name]位置不对应"); return false; }
		if(vecLine[4]!="subtype"){Ex.Logger.Log("Trade.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[5]!="subtype_name"){Ex.Logger.Log("Trade.csv中字段[subtype_name]位置不对应"); return false; }
		if(vecLine[6]!="price_range"){Ex.Logger.Log("Trade.csv中字段[price_range]位置不对应"); return false; }
		if(vecLine[7]!="is_publicity"){Ex.Logger.Log("Trade.csv中字段[is_publicity]位置不对应"); return false; }
		if(vecLine[8]!="type_coin"){Ex.Logger.Log("Trade.csv中字段[type_coin]位置不对应"); return false; }
		if(vecLine[9]!="benchmark_price"){Ex.Logger.Log("Trade.csv中字段[benchmark_price]位置不对应"); return false; }
		if(vecLine[10]!="benchmark_price_range"){Ex.Logger.Log("Trade.csv中字段[benchmark_price_range]位置不对应"); return false; }
		if(vecLine[11]!="benchmark_price_ratio"){Ex.Logger.Log("Trade.csv中字段[benchmark_price_ratio]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			TradeElement member = new TradeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.type=Convert.ToInt32(vecLine[2]);
			member.type_name=Convert.ToInt32(vecLine[3]);
			member.subtype=Convert.ToInt32(vecLine[4]);
			member.subtype_name=Convert.ToInt32(vecLine[5]);
			member.price_range=vecLine[6];
			member.is_publicity=Convert.ToInt32(vecLine[7]);
			member.type_coin=Convert.ToInt32(vecLine[8]);
			member.benchmark_price=Convert.ToInt32(vecLine[9]);
			member.benchmark_price_range=vecLine[10];
			member.benchmark_price_ratio=vecLine[11];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
