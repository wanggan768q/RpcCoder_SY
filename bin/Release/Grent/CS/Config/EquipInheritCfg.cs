using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备继承配置数据类
public class EquipInheritElement
{
	public int id;               	//阶级ID	每个阶级所对应的唯一ID
	public string comment;       	//阶级注释	策划用
	public int equip_level;      	//对应装等	该装备所对应的equipprote表的equip_level字段
	public li cost;              	//继承消耗	继承该装备属性所消耗的道具id和道具数量 道具id|数量

	public bool IsValidate = false;
	public EquipInheritElement()
	{
		id = -1;
	}
};

//装备继承配置封装类
public class EquipInheritTable
{

	private EquipInheritTable()
	{
		m_mapElements = new Dictionary<int, EquipInheritElement>();
		m_emptyItem = new EquipInheritElement();
		m_vecAllElements = new List<EquipInheritElement>();
	}
	private Dictionary<int, EquipInheritElement> m_mapElements = null;
	private List<EquipInheritElement>	m_vecAllElements = null;
	private EquipInheritElement m_emptyItem = null;
	private static EquipInheritTable sInstance = null;

	public static EquipInheritTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipInheritTable();
			return sInstance;
		}
	}

	public EquipInheritElement GetElement(int key)
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

  public List<EquipInheritElement> GetAllElement(Predicate<EquipInheritElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipInherit.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipInherit.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipInherit.bin]未找到");
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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("EquipInherit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipInherit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipInherit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="equip_level"){Ex.Logger.Log("EquipInherit.csv中字段[equip_level]位置不对应"); return false; }
		if(vecLine[3]!="cost"){Ex.Logger.Log("EquipInherit.csv中字段[cost]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipInheritElement member = new EquipInheritElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.equip_level );
			readPos += GameAssist.ReadString( binContent, readPos, out member.cost);

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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("EquipInherit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipInherit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipInherit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="equip_level"){Ex.Logger.Log("EquipInherit.csv中字段[equip_level]位置不对应"); return false; }
		if(vecLine[3]!="cost"){Ex.Logger.Log("EquipInherit.csv中字段[cost]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			EquipInheritElement member = new EquipInheritElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.equip_level=Convert.ToInt32(vecLine[2]);
			member.cost=vecLine[3];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
