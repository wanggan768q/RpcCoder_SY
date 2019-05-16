using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//道具类型配置数据类
public class ItemTypeElement
{
	public int id;               	//类型ID	道具类型ID
	public int type;             	//道具大类	道具大类ID
	public string type_name;     	//大类名称	策划用
	public int subtype;          	//道具子类	道具子类ID
	public string comment;       	//子类名称	策划用
	public int name_id;          	//类名称	用于显示， 从StringItem表中获取
	public int auction;          	//是否可	0:不可交易 1:可交易

	public bool IsValidate = false;
	public ItemTypeElement()
	{
		id = -1;
	}
};

//道具类型配置封装类
public class ItemTypeTable
{

	private ItemTypeTable()
	{
		m_mapElements = new Dictionary<int, ItemTypeElement>();
		m_emptyItem = new ItemTypeElement();
		m_vecAllElements = new List<ItemTypeElement>();
	}
	private Dictionary<int, ItemTypeElement> m_mapElements = null;
	private List<ItemTypeElement>	m_vecAllElements = null;
	private ItemTypeElement m_emptyItem = null;
	private static ItemTypeTable sInstance = null;

	public static ItemTypeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ItemTypeTable();
			return sInstance;
		}
	}

	public ItemTypeElement GetElement(int key)
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

  public List<ItemTypeElement> GetAllElement(Predicate<ItemTypeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ItemType.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ItemType.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ItemType.bin]未找到");
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
			Ex.Logger.Log("ItemType.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemType.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("ItemType.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="type_name"){Ex.Logger.Log("ItemType.csv中字段[type_name]位置不对应"); return false; }
		if(vecLine[3]!="subtype"){Ex.Logger.Log("ItemType.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("ItemType.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[5]!="name_id"){Ex.Logger.Log("ItemType.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[6]!="auction"){Ex.Logger.Log("ItemType.csv中字段[auction]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ItemTypeElement member = new ItemTypeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.type_name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auction );

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
			Ex.Logger.Log("ItemType.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemType.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("ItemType.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="type_name"){Ex.Logger.Log("ItemType.csv中字段[type_name]位置不对应"); return false; }
		if(vecLine[3]!="subtype"){Ex.Logger.Log("ItemType.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("ItemType.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[5]!="name_id"){Ex.Logger.Log("ItemType.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[6]!="auction"){Ex.Logger.Log("ItemType.csv中字段[auction]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			ItemTypeElement member = new ItemTypeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.type=Convert.ToInt32(vecLine[1]);
			member.type_name=vecLine[2];
			member.subtype=Convert.ToInt32(vecLine[3]);
			member.comment=vecLine[4];
			member.name_id=Convert.ToInt32(vecLine[5]);
			member.auction=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
