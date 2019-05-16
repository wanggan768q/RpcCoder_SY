using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物资质属性表配置数据类
public class PetAttributeFormatConfigElement
{
	public int id;               	//ID	添加需要 通知程序
	public string comment;       	//备注	仅策划用
	public int name;             	//属性名称ID	属性名称ID
	public int type;             	//属性显示	0：显示数字 1：显示百分比
	public int desc;             	//属性说明ID	属性说明ID
	public li attr;              	//对应属性	该资质对应 生效的属性

	public bool IsValidate = false;
	public PetAttributeFormatConfigElement()
	{
		id = -1;
	}
};

//宠物资质属性表配置封装类
public class PetAttributeFormatConfigTable
{

	private PetAttributeFormatConfigTable()
	{
		m_mapElements = new Dictionary<int, PetAttributeFormatConfigElement>();
		m_emptyItem = new PetAttributeFormatConfigElement();
		m_vecAllElements = new List<PetAttributeFormatConfigElement>();
	}
	private Dictionary<int, PetAttributeFormatConfigElement> m_mapElements = null;
	private List<PetAttributeFormatConfigElement>	m_vecAllElements = null;
	private PetAttributeFormatConfigElement m_emptyItem = null;
	private static PetAttributeFormatConfigTable sInstance = null;

	public static PetAttributeFormatConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetAttributeFormatConfigTable();
			return sInstance;
		}
	}

	public PetAttributeFormatConfigElement GetElement(int key)
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

  public List<PetAttributeFormatConfigElement> GetAllElement(Predicate<PetAttributeFormatConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetAttributeFormatConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetAttributeFormatConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetAttributeFormatConfig.bin]未找到");
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
			Ex.Logger.Log("PetAttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="desc"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[5]!="attr"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[attr]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetAttributeFormatConfigElement member = new PetAttributeFormatConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.attr);

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
			Ex.Logger.Log("PetAttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="desc"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[5]!="attr"){Ex.Logger.Log("PetAttributeFormatConfig.csv中字段[attr]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			PetAttributeFormatConfigElement member = new PetAttributeFormatConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.type=Convert.ToInt32(vecLine[3]);
			member.desc=Convert.ToInt32(vecLine[4]);
			member.attr=vecLine[5];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
