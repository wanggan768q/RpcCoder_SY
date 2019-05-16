using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物属性表配置数据类
public class PetAttributeElement
{
	public int id;               	//属性条目id	填写ID即可
	public string comment;       	//注释	策划用
	public int experience;       	//升级经验	升级经验
	public int total_exp;        	//升级经验总和	一级到当前经验的和
	public li max_hp;            	//生命上限	初始生命上限
	public li phy_damage;        	//物理攻击	初始物理攻击
	public li mag_damage;        	//魔法攻击	初始魔法攻击
	public li phy_defense;       	//物理防御	初始物理防御
	public li mag_defense;       	//魔法防御	初始魔法防御
	public li critical;          	//暴击值	初始暴击值
	public li tenacity;          	//韧性值	初始韧性值
	public li penetrait;         	//穿透值	初始穿透值
	public li block;             	//格挡值	初始格挡值

	public bool IsValidate = false;
	public PetAttributeElement()
	{
		id = -1;
	}
};

//宠物属性表配置封装类
public class PetAttributeTable
{

	private PetAttributeTable()
	{
		m_mapElements = new Dictionary<int, PetAttributeElement>();
		m_emptyItem = new PetAttributeElement();
		m_vecAllElements = new List<PetAttributeElement>();
	}
	private Dictionary<int, PetAttributeElement> m_mapElements = null;
	private List<PetAttributeElement>	m_vecAllElements = null;
	private PetAttributeElement m_emptyItem = null;
	private static PetAttributeTable sInstance = null;

	public static PetAttributeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetAttributeTable();
			return sInstance;
		}
	}

	public PetAttributeElement GetElement(int key)
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

  public List<PetAttributeElement> GetAllElement(Predicate<PetAttributeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetAttribute.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetAttribute.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetAttribute.bin]未找到");
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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("PetAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="experience"){Ex.Logger.Log("PetAttribute.csv中字段[experience]位置不对应"); return false; }
		if(vecLine[3]!="total_exp"){Ex.Logger.Log("PetAttribute.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[4]!="max_hp"){Ex.Logger.Log("PetAttribute.csv中字段[max_hp]位置不对应"); return false; }
		if(vecLine[5]!="phy_damage"){Ex.Logger.Log("PetAttribute.csv中字段[phy_damage]位置不对应"); return false; }
		if(vecLine[6]!="mag_damage"){Ex.Logger.Log("PetAttribute.csv中字段[mag_damage]位置不对应"); return false; }
		if(vecLine[7]!="phy_defense"){Ex.Logger.Log("PetAttribute.csv中字段[phy_defense]位置不对应"); return false; }
		if(vecLine[8]!="mag_defense"){Ex.Logger.Log("PetAttribute.csv中字段[mag_defense]位置不对应"); return false; }
		if(vecLine[9]!="critical"){Ex.Logger.Log("PetAttribute.csv中字段[critical]位置不对应"); return false; }
		if(vecLine[10]!="tenacity"){Ex.Logger.Log("PetAttribute.csv中字段[tenacity]位置不对应"); return false; }
		if(vecLine[11]!="penetrait"){Ex.Logger.Log("PetAttribute.csv中字段[penetrait]位置不对应"); return false; }
		if(vecLine[12]!="block"){Ex.Logger.Log("PetAttribute.csv中字段[block]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetAttributeElement member = new PetAttributeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.experience );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.total_exp );
			readPos += GameAssist.ReadString( binContent, readPos, out member.max_hp);
			readPos += GameAssist.ReadString( binContent, readPos, out member.phy_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mag_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.phy_defense);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mag_defense);
			readPos += GameAssist.ReadString( binContent, readPos, out member.critical);
			readPos += GameAssist.ReadString( binContent, readPos, out member.tenacity);
			readPos += GameAssist.ReadString( binContent, readPos, out member.penetrait);
			readPos += GameAssist.ReadString( binContent, readPos, out member.block);

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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("PetAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="experience"){Ex.Logger.Log("PetAttribute.csv中字段[experience]位置不对应"); return false; }
		if(vecLine[3]!="total_exp"){Ex.Logger.Log("PetAttribute.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[4]!="max_hp"){Ex.Logger.Log("PetAttribute.csv中字段[max_hp]位置不对应"); return false; }
		if(vecLine[5]!="phy_damage"){Ex.Logger.Log("PetAttribute.csv中字段[phy_damage]位置不对应"); return false; }
		if(vecLine[6]!="mag_damage"){Ex.Logger.Log("PetAttribute.csv中字段[mag_damage]位置不对应"); return false; }
		if(vecLine[7]!="phy_defense"){Ex.Logger.Log("PetAttribute.csv中字段[phy_defense]位置不对应"); return false; }
		if(vecLine[8]!="mag_defense"){Ex.Logger.Log("PetAttribute.csv中字段[mag_defense]位置不对应"); return false; }
		if(vecLine[9]!="critical"){Ex.Logger.Log("PetAttribute.csv中字段[critical]位置不对应"); return false; }
		if(vecLine[10]!="tenacity"){Ex.Logger.Log("PetAttribute.csv中字段[tenacity]位置不对应"); return false; }
		if(vecLine[11]!="penetrait"){Ex.Logger.Log("PetAttribute.csv中字段[penetrait]位置不对应"); return false; }
		if(vecLine[12]!="block"){Ex.Logger.Log("PetAttribute.csv中字段[block]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)13)
			{
				return false;
			}
			PetAttributeElement member = new PetAttributeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.experience=Convert.ToInt32(vecLine[2]);
			member.total_exp=Convert.ToInt32(vecLine[3]);
			member.max_hp=vecLine[4];
			member.phy_damage=vecLine[5];
			member.mag_damage=vecLine[6];
			member.phy_defense=vecLine[7];
			member.mag_defense=vecLine[8];
			member.critical=vecLine[9];
			member.tenacity=vecLine[10];
			member.penetrait=vecLine[11];
			member.block=vecLine[12];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
