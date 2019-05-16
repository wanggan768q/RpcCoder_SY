using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//充值商品表配置数据类
public class RechargeElement
{
	public int id;               	//主键id	商品id
	public string comment;       	//注释	
	public int weight;           	//页面显示权重	必须是 1～N
	public int nameId;           	//名称id	
	public string iconName;      	//图片名称	
	public int active;           	//是否可用	0 禁用 1 启用
	public int recommend;        	//是否推荐	0 禁用 1 启用
	public int productType;      	//商品类型	1 货币 2 礼包
	public int productPrice;     	//商品价格	人民币
	public int productDiamond;   	//商品钻石数	
	public int productBindDiamond;	//商品数	
	public int productBagId;     	//商品礼包id	

	public bool IsValidate = false;
	public RechargeElement()
	{
		id = -1;
	}
};

//充值商品表配置封装类
public class RechargeTable
{

	private RechargeTable()
	{
		m_mapElements = new Dictionary<int, RechargeElement>();
		m_emptyItem = new RechargeElement();
		m_vecAllElements = new List<RechargeElement>();
	}
	private Dictionary<int, RechargeElement> m_mapElements = null;
	private List<RechargeElement>	m_vecAllElements = null;
	private RechargeElement m_emptyItem = null;
	private static RechargeTable sInstance = null;

	public static RechargeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RechargeTable();
			return sInstance;
		}
	}

	public RechargeElement GetElement(int key)
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

  public List<RechargeElement> GetAllElement(Predicate<RechargeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Recharge.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Recharge.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Recharge.bin]未找到");
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
			Ex.Logger.Log("Recharge.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Recharge.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Recharge.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="weight"){Ex.Logger.Log("Recharge.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[3]!="nameId"){Ex.Logger.Log("Recharge.csv中字段[nameId]位置不对应"); return false; }
		if(vecLine[4]!="iconName"){Ex.Logger.Log("Recharge.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[5]!="active"){Ex.Logger.Log("Recharge.csv中字段[active]位置不对应"); return false; }
		if(vecLine[6]!="recommend"){Ex.Logger.Log("Recharge.csv中字段[recommend]位置不对应"); return false; }
		if(vecLine[7]!="productType"){Ex.Logger.Log("Recharge.csv中字段[productType]位置不对应"); return false; }
		if(vecLine[8]!="productPrice"){Ex.Logger.Log("Recharge.csv中字段[productPrice]位置不对应"); return false; }
		if(vecLine[9]!="productDiamond"){Ex.Logger.Log("Recharge.csv中字段[productDiamond]位置不对应"); return false; }
		if(vecLine[10]!="productBindDiamond"){Ex.Logger.Log("Recharge.csv中字段[productBindDiamond]位置不对应"); return false; }
		if(vecLine[11]!="productBagId"){Ex.Logger.Log("Recharge.csv中字段[productBagId]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RechargeElement member = new RechargeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.weight );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.nameId );
			readPos += GameAssist.ReadString( binContent, readPos, out member.iconName);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.active );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recommend );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.productType );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.productPrice );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.productDiamond );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.productBindDiamond );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.productBagId );

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
			Ex.Logger.Log("Recharge.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Recharge.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Recharge.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="weight"){Ex.Logger.Log("Recharge.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[3]!="nameId"){Ex.Logger.Log("Recharge.csv中字段[nameId]位置不对应"); return false; }
		if(vecLine[4]!="iconName"){Ex.Logger.Log("Recharge.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[5]!="active"){Ex.Logger.Log("Recharge.csv中字段[active]位置不对应"); return false; }
		if(vecLine[6]!="recommend"){Ex.Logger.Log("Recharge.csv中字段[recommend]位置不对应"); return false; }
		if(vecLine[7]!="productType"){Ex.Logger.Log("Recharge.csv中字段[productType]位置不对应"); return false; }
		if(vecLine[8]!="productPrice"){Ex.Logger.Log("Recharge.csv中字段[productPrice]位置不对应"); return false; }
		if(vecLine[9]!="productDiamond"){Ex.Logger.Log("Recharge.csv中字段[productDiamond]位置不对应"); return false; }
		if(vecLine[10]!="productBindDiamond"){Ex.Logger.Log("Recharge.csv中字段[productBindDiamond]位置不对应"); return false; }
		if(vecLine[11]!="productBagId"){Ex.Logger.Log("Recharge.csv中字段[productBagId]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			RechargeElement member = new RechargeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.weight=Convert.ToInt32(vecLine[2]);
			member.nameId=Convert.ToInt32(vecLine[3]);
			member.iconName=vecLine[4];
			member.active=Convert.ToInt32(vecLine[5]);
			member.recommend=Convert.ToInt32(vecLine[6]);
			member.productType=Convert.ToInt32(vecLine[7]);
			member.productPrice=Convert.ToInt32(vecLine[8]);
			member.productDiamond=Convert.ToInt32(vecLine[9]);
			member.productBindDiamond=Convert.ToInt32(vecLine[10]);
			member.productBagId=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
