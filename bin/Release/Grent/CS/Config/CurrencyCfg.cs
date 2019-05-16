using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//货币表配置数据类
public class CurrencyElement
{
	public int id;               	//货币id	货币id
	public string comment;       	//说明	注释
	public int item_id;          	//对应道具表中id	对应道具表中id
	public int name;             	//货币名	stringid
	public string icon;          	//货币图标	图标名
	public string color;         	//货币颜色	色值
	public int belong;           	//从属关系	1=玩家 2=公会
	public int show;             	//是否在货币界面展示	1=显示，按id顺序 为空不显示

	public bool IsValidate = false;
	public CurrencyElement()
	{
		id = -1;
	}
};

//货币表配置封装类
public class CurrencyTable
{

	private CurrencyTable()
	{
		m_mapElements = new Dictionary<int, CurrencyElement>();
		m_emptyItem = new CurrencyElement();
		m_vecAllElements = new List<CurrencyElement>();
	}
	private Dictionary<int, CurrencyElement> m_mapElements = null;
	private List<CurrencyElement>	m_vecAllElements = null;
	private CurrencyElement m_emptyItem = null;
	private static CurrencyTable sInstance = null;

	public static CurrencyTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CurrencyTable();
			return sInstance;
		}
	}

	public CurrencyElement GetElement(int key)
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

  public List<CurrencyElement> GetAllElement(Predicate<CurrencyElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Currency.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Currency.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Currency.bin]未找到");
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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("Currency.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Currency.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Currency.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item_id"){Ex.Logger.Log("Currency.csv中字段[item_id]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Currency.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("Currency.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="color"){Ex.Logger.Log("Currency.csv中字段[color]位置不对应"); return false; }
		if(vecLine[6]!="belong"){Ex.Logger.Log("Currency.csv中字段[belong]位置不对应"); return false; }
		if(vecLine[7]!="show"){Ex.Logger.Log("Currency.csv中字段[show]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CurrencyElement member = new CurrencyElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.color);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.belong );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.show );

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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("Currency.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Currency.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Currency.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item_id"){Ex.Logger.Log("Currency.csv中字段[item_id]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Currency.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("Currency.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="color"){Ex.Logger.Log("Currency.csv中字段[color]位置不对应"); return false; }
		if(vecLine[6]!="belong"){Ex.Logger.Log("Currency.csv中字段[belong]位置不对应"); return false; }
		if(vecLine[7]!="show"){Ex.Logger.Log("Currency.csv中字段[show]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			CurrencyElement member = new CurrencyElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.item_id=Convert.ToInt32(vecLine[2]);
			member.name=Convert.ToInt32(vecLine[3]);
			member.icon=vecLine[4];
			member.color=vecLine[5];
			member.belong=Convert.ToInt32(vecLine[6]);
			member.show=Convert.ToInt32(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
