using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝石配置数据类
public class BaoShiElement
{
	public int ID;               	//编号	宝石ID
	public int Type;             	//宝石类别	宝石类别
	public int Lv;               	//宝石等级	宝石等级
	public int Limit;            	//镶嵌限制	镶嵌限制
	public ls AttrWuQi;          	//属性类别-武器	属性类别-武器
	public li NumWuQi;           	//属性参数1	属性参数1
	public lf AttrOther;         	//属性类别-其他	属性类别-其他
	public string NumOther;      	//属性参数2	属性参数2
	public int HeCheng;          	//合成后的宝石	合成后的宝石

	public bool IsValidate = false;
	public BaoShiElement()
	{
		ID = -1;
	}
};

//宝石配置封装类
public class BaoShiTable
{

	private BaoShiTable()
	{
		m_mapElements = new Dictionary<int, BaoShiElement>();
		m_emptyItem = new BaoShiElement();
		m_vecAllElements = new List<BaoShiElement>();
	}
	private Dictionary<int, BaoShiElement> m_mapElements = null;
	private List<BaoShiElement>	m_vecAllElements = null;
	private BaoShiElement m_emptyItem = null;
	private static BaoShiTable sInstance = null;

	public static BaoShiTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BaoShiTable();
			return sInstance;
		}
	}

	public BaoShiElement GetElement(int key)
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

  public List<BaoShiElement> GetAllElement(Predicate<BaoShiElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BaoShi.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BaoShi.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[BaoShi.bin]未找到");
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
			Ex.Logger.Log("BaoShi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Ex.Logger.Log("BaoShi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Ex.Logger.Log("BaoShi.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="Lv"){Ex.Logger.Log("BaoShi.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[3]!="Limit"){Ex.Logger.Log("BaoShi.csv中字段[Limit]位置不对应"); return false; }
		if(vecLine[4]!="AttrWuQi"){Ex.Logger.Log("BaoShi.csv中字段[AttrWuQi]位置不对应"); return false; }
		if(vecLine[5]!="NumWuQi"){Ex.Logger.Log("BaoShi.csv中字段[NumWuQi]位置不对应"); return false; }
		if(vecLine[6]!="AttrOther"){Ex.Logger.Log("BaoShi.csv中字段[AttrOther]位置不对应"); return false; }
		if(vecLine[7]!="NumOther"){Ex.Logger.Log("BaoShi.csv中字段[NumOther]位置不对应"); return false; }
		if(vecLine[8]!="HeCheng"){Ex.Logger.Log("BaoShi.csv中字段[HeCheng]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BaoShiElement member = new BaoShiElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Limit );
			readPos += GameAssist.ReadString( binContent, readPos, out member.AttrWuQi);
			readPos += GameAssist.ReadString( binContent, readPos, out member.NumWuQi);
			readPos += GameAssist.ReadString( binContent, readPos, out member.AttrOther);
			readPos += GameAssist.ReadString( binContent, readPos, out member.NumOther);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.HeCheng );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
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
			Ex.Logger.Log("BaoShi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="ID"){Ex.Logger.Log("BaoShi.csv中字段[ID]位置不对应"); return false; }
		if(vecLine[1]!="Type"){Ex.Logger.Log("BaoShi.csv中字段[Type]位置不对应"); return false; }
		if(vecLine[2]!="Lv"){Ex.Logger.Log("BaoShi.csv中字段[Lv]位置不对应"); return false; }
		if(vecLine[3]!="Limit"){Ex.Logger.Log("BaoShi.csv中字段[Limit]位置不对应"); return false; }
		if(vecLine[4]!="AttrWuQi"){Ex.Logger.Log("BaoShi.csv中字段[AttrWuQi]位置不对应"); return false; }
		if(vecLine[5]!="NumWuQi"){Ex.Logger.Log("BaoShi.csv中字段[NumWuQi]位置不对应"); return false; }
		if(vecLine[6]!="AttrOther"){Ex.Logger.Log("BaoShi.csv中字段[AttrOther]位置不对应"); return false; }
		if(vecLine[7]!="NumOther"){Ex.Logger.Log("BaoShi.csv中字段[NumOther]位置不对应"); return false; }
		if(vecLine[8]!="HeCheng"){Ex.Logger.Log("BaoShi.csv中字段[HeCheng]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			BaoShiElement member = new BaoShiElement();
			member.ID=Convert.ToInt32(vecLine[0]);
			member.Type=Convert.ToInt32(vecLine[1]);
			member.Lv=Convert.ToInt32(vecLine[2]);
			member.Limit=Convert.ToInt32(vecLine[3]);
			member.AttrWuQi=vecLine[4];
			member.NumWuQi=vecLine[5];
			member.AttrOther=vecLine[6];
			member.NumOther=vecLine[7];
			member.HeCheng=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};
