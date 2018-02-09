using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//战斗属性配置数据类
public class AttributeFormatConfigElement
{
	public int id;               	//ID	添加需要 通知程序
	public string name;          	//属性中文名	仅策划用
	public int nameid;           	//属性名称ID	属性名称ID
	public string des;           	//属性说明	仅策划用
	public int desid;            	//属性说明ID	属性说明ID
	public lf weight;            	//战力权重	格式=[参数1,参数2] 战力等于=[参数2/参数1]

	public bool IsValidate = false;
	public AttributeFormatConfigElement()
	{
		id = -1;
	}
};

//战斗属性配置封装类
public class AttributeFormatConfigTable
{

	private AttributeFormatConfigTable()
	{
		m_mapElements = new Dictionary<int, AttributeFormatConfigElement>();
		m_emptyItem = new AttributeFormatConfigElement();
		m_vecAllElements = new List<AttributeFormatConfigElement>();
	}
	private Dictionary<int, AttributeFormatConfigElement> m_mapElements = null;
	private List<AttributeFormatConfigElement>	m_vecAllElements = null;
	private AttributeFormatConfigElement m_emptyItem = null;
	private static AttributeFormatConfigTable sInstance = null;

	public static AttributeFormatConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AttributeFormatConfigTable();
			return sInstance;
		}
	}

	public AttributeFormatConfigElement GetElement(int key)
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

  public List<AttributeFormatConfigElement> GetAllElement(Predicate<AttributeFormatConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AttributeFormatConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AttributeFormatConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AttributeFormatConfig.bin]未找到");
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
			Ex.Logger.Log("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="nameid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[nameid]位置不对应"); return false; }
		if(vecLine[3]!="des"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[des]位置不对应"); return false; }
		if(vecLine[4]!="desid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[desid]位置不对应"); return false; }
		if(vecLine[5]!="weight"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[weight]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AttributeFormatConfigElement member = new AttributeFormatConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.nameid );
			readPos += GameAssist.ReadString( binContent, readPos, out member.des);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desid );
			readPos += GameAssist.ReadString( binContent, readPos, out member.weight);

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
			Ex.Logger.Log("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="nameid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[nameid]位置不对应"); return false; }
		if(vecLine[3]!="des"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[des]位置不对应"); return false; }
		if(vecLine[4]!="desid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[desid]位置不对应"); return false; }
		if(vecLine[5]!="weight"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[weight]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			AttributeFormatConfigElement member = new AttributeFormatConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=vecLine[1];
			member.nameid=Convert.ToInt32(vecLine[2]);
			member.des=vecLine[3];
			member.desid=Convert.ToInt32(vecLine[4]);
			member.weight=vecLine[5];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
