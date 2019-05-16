using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//积分商品表配置数据类
public class ShopitemsElement
{
	public int id;               	//ID	填写ID即可
	public string comment;       	//注释	策划用
	public int item_id;          	//道具ID	道具ID
	public string name;          	//道具名称	策划用
	public int shop_id;          	//商店ID	商店ID
	public int order;            	//道具展示顺序	道具按数字从小到大排序，数字不可跳。 从“0”开始！！
	public int limit_type;       	//购买限制	0无1日2周
	public int limit_num;        	//数量限购	不填写则不限购
	public int price;            	//价格	填写数量
	public int exchange_type;    	//限制类型	1为历史数量-废弃 2为任务是否完成填写-1则不限制
	public int exchange_condition;	//购买限制	填写任务表id填写-1则不限制 exchange_type=2时填写任务ID

	public bool IsValidate = false;
	public ShopitemsElement()
	{
		id = -1;
	}
};

//积分商品表配置封装类
public class ShopitemsTable
{

	private ShopitemsTable()
	{
		m_mapElements = new Dictionary<int, ShopitemsElement>();
		m_emptyItem = new ShopitemsElement();
		m_vecAllElements = new List<ShopitemsElement>();
	}
	private Dictionary<int, ShopitemsElement> m_mapElements = null;
	private List<ShopitemsElement>	m_vecAllElements = null;
	private ShopitemsElement m_emptyItem = null;
	private static ShopitemsTable sInstance = null;

	public static ShopitemsTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ShopitemsTable();
			return sInstance;
		}
	}

	public ShopitemsElement GetElement(int key)
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

  public List<ShopitemsElement> GetAllElement(Predicate<ShopitemsElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Shopitems.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Shopitems.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Shopitems.bin]未找到");
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
			Ex.Logger.Log("Shopitems.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Shopitems.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Shopitems.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item_id"){Ex.Logger.Log("Shopitems.csv中字段[item_id]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Shopitems.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="shop_id"){Ex.Logger.Log("Shopitems.csv中字段[shop_id]位置不对应"); return false; }
		if(vecLine[5]!="order"){Ex.Logger.Log("Shopitems.csv中字段[order]位置不对应"); return false; }
		if(vecLine[6]!="limit_type"){Ex.Logger.Log("Shopitems.csv中字段[limit_type]位置不对应"); return false; }
		if(vecLine[7]!="limit_num"){Ex.Logger.Log("Shopitems.csv中字段[limit_num]位置不对应"); return false; }
		if(vecLine[8]!="price"){Ex.Logger.Log("Shopitems.csv中字段[price]位置不对应"); return false; }
		if(vecLine[9]!="exchange_type"){Ex.Logger.Log("Shopitems.csv中字段[exchange_type]位置不对应"); return false; }
		if(vecLine[10]!="exchange_condition"){Ex.Logger.Log("Shopitems.csv中字段[exchange_condition]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ShopitemsElement member = new ShopitemsElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.shop_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.limit_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.limit_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_condition );

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
			Ex.Logger.Log("Shopitems.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Shopitems.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Shopitems.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item_id"){Ex.Logger.Log("Shopitems.csv中字段[item_id]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Shopitems.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="shop_id"){Ex.Logger.Log("Shopitems.csv中字段[shop_id]位置不对应"); return false; }
		if(vecLine[5]!="order"){Ex.Logger.Log("Shopitems.csv中字段[order]位置不对应"); return false; }
		if(vecLine[6]!="limit_type"){Ex.Logger.Log("Shopitems.csv中字段[limit_type]位置不对应"); return false; }
		if(vecLine[7]!="limit_num"){Ex.Logger.Log("Shopitems.csv中字段[limit_num]位置不对应"); return false; }
		if(vecLine[8]!="price"){Ex.Logger.Log("Shopitems.csv中字段[price]位置不对应"); return false; }
		if(vecLine[9]!="exchange_type"){Ex.Logger.Log("Shopitems.csv中字段[exchange_type]位置不对应"); return false; }
		if(vecLine[10]!="exchange_condition"){Ex.Logger.Log("Shopitems.csv中字段[exchange_condition]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			ShopitemsElement member = new ShopitemsElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.item_id=Convert.ToInt32(vecLine[2]);
			member.name=vecLine[3];
			member.shop_id=Convert.ToInt32(vecLine[4]);
			member.order=Convert.ToInt32(vecLine[5]);
			member.limit_type=Convert.ToInt32(vecLine[6]);
			member.limit_num=Convert.ToInt32(vecLine[7]);
			member.price=Convert.ToInt32(vecLine[8]);
			member.exchange_type=Convert.ToInt32(vecLine[9]);
			member.exchange_condition=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
