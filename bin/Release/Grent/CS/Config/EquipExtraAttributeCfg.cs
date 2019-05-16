using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备后缀属性配置数据类
public class EquipExtraAttributeElement
{
	public int id;               	//后缀属性id	对应装备级别
	public string comment;       	//道具注释	策划用
	public li item;              	//消耗道具	道具ID|数量
	public li consume;           	//锁定消耗	数量
	public int consume_item;     	//锁定消耗	道具ID
	public li consume_num;       	//锁定消耗	数量
	public li quality_weight;    	//品质权值	白|绿|蓝|紫|橙
	public li max_hp;            	//生命上限	分别对应 属性id|属性权值|属性下限|属性上限
	public li physic_damage;     	//物理攻击	分别对应 属性id|属性权值|属性下限|属性上限
	public li magic_damage;      	//魔法攻击	分别对应 属性id|属性权值|属性下限|属性上限
	public li physic_defense;    	//物理防御	分别对应 属性id|属性权值|属性下限|属性上限
	public li magic_defense;     	//魔法防御	分别对应 属性id|属性权值|属性下限|属性上限
	public li critical;          	//暴击值	分别对应 属性id|属性权值|属性下限|属性上限
	public li tenacity;          	//韧性值	分别对应 属性id|属性权值|属性下限|属性上限
	public li penetrate;         	//穿透值	分别对应 属性id|属性权值|属性下限|属性上限
	public li block;             	//格挡值	分别对应 属性id|属性权值|属性下限|属性上限

	public bool IsValidate = false;
	public EquipExtraAttributeElement()
	{
		id = -1;
	}
};

//装备后缀属性配置封装类
public class EquipExtraAttributeTable
{

	private EquipExtraAttributeTable()
	{
		m_mapElements = new Dictionary<int, EquipExtraAttributeElement>();
		m_emptyItem = new EquipExtraAttributeElement();
		m_vecAllElements = new List<EquipExtraAttributeElement>();
	}
	private Dictionary<int, EquipExtraAttributeElement> m_mapElements = null;
	private List<EquipExtraAttributeElement>	m_vecAllElements = null;
	private EquipExtraAttributeElement m_emptyItem = null;
	private static EquipExtraAttributeTable sInstance = null;

	public static EquipExtraAttributeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipExtraAttributeTable();
			return sInstance;
		}
	}

	public EquipExtraAttributeElement GetElement(int key)
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

  public List<EquipExtraAttributeElement> GetAllElement(Predicate<EquipExtraAttributeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipExtraAttribute.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipExtraAttribute.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipExtraAttribute.bin]未找到");
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
		if(vecLine.Count != 16)
		{
			Ex.Logger.Log("EquipExtraAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[item]位置不对应"); return false; }
		if(vecLine[3]!="consume"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume]位置不对应"); return false; }
		if(vecLine[4]!="consume_item"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume_item]位置不对应"); return false; }
		if(vecLine[5]!="consume_num"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume_num]位置不对应"); return false; }
		if(vecLine[6]!="quality_weight"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[quality_weight]位置不对应"); return false; }
		if(vecLine[7]!="max_hp"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[max_hp]位置不对应"); return false; }
		if(vecLine[8]!="physic_damage"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[physic_damage]位置不对应"); return false; }
		if(vecLine[9]!="magic_damage"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[magic_damage]位置不对应"); return false; }
		if(vecLine[10]!="physic_defense"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[11]!="magic_defense"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[12]!="critical"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[critical]位置不对应"); return false; }
		if(vecLine[13]!="tenacity"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[tenacity]位置不对应"); return false; }
		if(vecLine[14]!="penetrate"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[penetrate]位置不对应"); return false; }
		if(vecLine[15]!="block"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[block]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipExtraAttributeElement member = new EquipExtraAttributeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.item);
			readPos += GameAssist.ReadString( binContent, readPos, out member.consume);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.consume_item );
			readPos += GameAssist.ReadString( binContent, readPos, out member.consume_num);
			readPos += GameAssist.ReadString( binContent, readPos, out member.quality_weight);
			readPos += GameAssist.ReadString( binContent, readPos, out member.max_hp);
			readPos += GameAssist.ReadString( binContent, readPos, out member.physic_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.magic_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.physic_defense);
			readPos += GameAssist.ReadString( binContent, readPos, out member.magic_defense);
			readPos += GameAssist.ReadString( binContent, readPos, out member.critical);
			readPos += GameAssist.ReadString( binContent, readPos, out member.tenacity);
			readPos += GameAssist.ReadString( binContent, readPos, out member.penetrate);
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
		if(vecLine.Count != 16)
		{
			Ex.Logger.Log("EquipExtraAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="item"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[item]位置不对应"); return false; }
		if(vecLine[3]!="consume"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume]位置不对应"); return false; }
		if(vecLine[4]!="consume_item"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume_item]位置不对应"); return false; }
		if(vecLine[5]!="consume_num"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[consume_num]位置不对应"); return false; }
		if(vecLine[6]!="quality_weight"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[quality_weight]位置不对应"); return false; }
		if(vecLine[7]!="max_hp"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[max_hp]位置不对应"); return false; }
		if(vecLine[8]!="physic_damage"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[physic_damage]位置不对应"); return false; }
		if(vecLine[9]!="magic_damage"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[magic_damage]位置不对应"); return false; }
		if(vecLine[10]!="physic_defense"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[11]!="magic_defense"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[12]!="critical"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[critical]位置不对应"); return false; }
		if(vecLine[13]!="tenacity"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[tenacity]位置不对应"); return false; }
		if(vecLine[14]!="penetrate"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[penetrate]位置不对应"); return false; }
		if(vecLine[15]!="block"){Ex.Logger.Log("EquipExtraAttribute.csv中字段[block]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			EquipExtraAttributeElement member = new EquipExtraAttributeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.item=vecLine[2];
			member.consume=vecLine[3];
			member.consume_item=Convert.ToInt32(vecLine[4]);
			member.consume_num=vecLine[5];
			member.quality_weight=vecLine[6];
			member.max_hp=vecLine[7];
			member.physic_damage=vecLine[8];
			member.magic_damage=vecLine[9];
			member.physic_defense=vecLine[10];
			member.magic_defense=vecLine[11];
			member.critical=vecLine[12];
			member.tenacity=vecLine[13];
			member.penetrate=vecLine[14];
			member.block=vecLine[15];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
