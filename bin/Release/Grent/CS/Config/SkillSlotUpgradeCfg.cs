using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能槽培养表配置数据类
public class SkillSlotUpgradeElement
{
	public int id;               	//条目id	id的值为技能槽id*1000+当前该槽等级
	public int slot_id;          	//技能槽id	对应技能槽在代码中的id 0.普攻技能 1.技能槽1 2.技能槽2 3.技能槽3 4.技能槽4 5.QTE技能
	public int lv;               	//技能槽等级	该技能槽当前的等级
	public int cost;             	//升级消费	升级至下一等级需要消耗的银币数量 
	public int required_lv;      	//等级锁	升级至下一等级需要达到的角色级别
	public li phy_attribute_1;   	//物理职业属性加成1	该技能槽改等级所加成的属性类型及属性值1 属性类型|属性值
	public li phy_attribute_2;   	//物理职业属性加成2	该技能槽改等级所加成的属性类型及属性值2 属性类型|属性值
	public li mag_attribute_1;   	//魔法职业属性加成1	该技能槽改等级所加成的属性类型及属性值1 属性类型|属性值
	public li mag_attribute_2;   	//魔法职业属性加成2	该技能槽改等级所加成的属性类型及属性值2 属性类型|属性值

	public bool IsValidate = false;
	public SkillSlotUpgradeElement()
	{
		id = -1;
	}
};

//技能槽培养表配置封装类
public class SkillSlotUpgradeTable
{

	private SkillSlotUpgradeTable()
	{
		m_mapElements = new Dictionary<int, SkillSlotUpgradeElement>();
		m_emptyItem = new SkillSlotUpgradeElement();
		m_vecAllElements = new List<SkillSlotUpgradeElement>();
	}
	private Dictionary<int, SkillSlotUpgradeElement> m_mapElements = null;
	private List<SkillSlotUpgradeElement>	m_vecAllElements = null;
	private SkillSlotUpgradeElement m_emptyItem = null;
	private static SkillSlotUpgradeTable sInstance = null;

	public static SkillSlotUpgradeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SkillSlotUpgradeTable();
			return sInstance;
		}
	}

	public SkillSlotUpgradeElement GetElement(int key)
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

  public List<SkillSlotUpgradeElement> GetAllElement(Predicate<SkillSlotUpgradeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SkillSlotUpgrade.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SkillSlotUpgrade.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SkillSlotUpgrade.bin]未找到");
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
			Ex.Logger.Log("SkillSlotUpgrade.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="slot_id"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[slot_id]位置不对应"); return false; }
		if(vecLine[2]!="lv"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[3]!="cost"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[4]!="required_lv"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[5]!="phy_attribute_1"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[phy_attribute_1]位置不对应"); return false; }
		if(vecLine[6]!="phy_attribute_2"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[phy_attribute_2]位置不对应"); return false; }
		if(vecLine[7]!="mag_attribute_1"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[mag_attribute_1]位置不对应"); return false; }
		if(vecLine[8]!="mag_attribute_2"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[mag_attribute_2]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillSlotUpgradeElement member = new SkillSlotUpgradeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cost );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_lv );
			readPos += GameAssist.ReadString( binContent, readPos, out member.phy_attribute_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.phy_attribute_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mag_attribute_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mag_attribute_2);

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("SkillSlotUpgrade.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="slot_id"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[slot_id]位置不对应"); return false; }
		if(vecLine[2]!="lv"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[3]!="cost"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[cost]位置不对应"); return false; }
		if(vecLine[4]!="required_lv"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[5]!="phy_attribute_1"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[phy_attribute_1]位置不对应"); return false; }
		if(vecLine[6]!="phy_attribute_2"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[phy_attribute_2]位置不对应"); return false; }
		if(vecLine[7]!="mag_attribute_1"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[mag_attribute_1]位置不对应"); return false; }
		if(vecLine[8]!="mag_attribute_2"){Ex.Logger.Log("SkillSlotUpgrade.csv中字段[mag_attribute_2]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			SkillSlotUpgradeElement member = new SkillSlotUpgradeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.slot_id=Convert.ToInt32(vecLine[1]);
			member.lv=Convert.ToInt32(vecLine[2]);
			member.cost=Convert.ToInt32(vecLine[3]);
			member.required_lv=Convert.ToInt32(vecLine[4]);
			member.phy_attribute_1=vecLine[5];
			member.phy_attribute_2=vecLine[6];
			member.mag_attribute_1=vecLine[7];
			member.mag_attribute_2=vecLine[8];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
