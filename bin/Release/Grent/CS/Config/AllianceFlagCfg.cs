using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//公会旗帜表配置数据类
public class AllianceFlagElement
{
	public int id;               	//ID	填写ID即可
	public string comment;       	//注释	策划用
	public string icon;          	//旗帜图标	图片名
	public string pic;           	//旗帜图	图片名
	public int price;            	//旗帜价格	填写整数

	public bool IsValidate = false;
	public AllianceFlagElement()
	{
		id = -1;
	}
};

//公会旗帜表配置封装类
public class AllianceFlagTable
{

	private AllianceFlagTable()
	{
		m_mapElements = new Dictionary<int, AllianceFlagElement>();
		m_emptyItem = new AllianceFlagElement();
		m_vecAllElements = new List<AllianceFlagElement>();
	}
	private Dictionary<int, AllianceFlagElement> m_mapElements = null;
	private List<AllianceFlagElement>	m_vecAllElements = null;
	private AllianceFlagElement m_emptyItem = null;
	private static AllianceFlagTable sInstance = null;

	public static AllianceFlagTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AllianceFlagTable();
			return sInstance;
		}
	}

	public AllianceFlagElement GetElement(int key)
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

  public List<AllianceFlagElement> GetAllElement(Predicate<AllianceFlagElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AllianceFlag.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AllianceFlag.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AllianceFlag.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("AllianceFlag.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceFlag.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceFlag.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="icon"){Ex.Logger.Log("AllianceFlag.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[3]!="pic"){Ex.Logger.Log("AllianceFlag.csv中字段[pic]位置不对应"); return false; }
		if(vecLine[4]!="price"){Ex.Logger.Log("AllianceFlag.csv中字段[price]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AllianceFlagElement member = new AllianceFlagElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.price );

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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("AllianceFlag.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceFlag.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceFlag.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="icon"){Ex.Logger.Log("AllianceFlag.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[3]!="pic"){Ex.Logger.Log("AllianceFlag.csv中字段[pic]位置不对应"); return false; }
		if(vecLine[4]!="price"){Ex.Logger.Log("AllianceFlag.csv中字段[price]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			AllianceFlagElement member = new AllianceFlagElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.icon=vecLine[2];
			member.pic=vecLine[3];
			member.price=Convert.ToInt32(vecLine[4]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
