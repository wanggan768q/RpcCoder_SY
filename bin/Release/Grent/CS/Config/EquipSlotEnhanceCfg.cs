using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备强化配置数据类
public class EquipSlotEnhanceElement
{
	public int id;               	//阶级ID	每个阶级所对应的唯一ID
	public string comment;       	//阶级注释	策划用
	public int rank;             	//对应段位	显示用的段位
	public int level;            	//对应等级	显示用的等级
	public int exp;              	//升级经验	升级至下一级需要的经验
	public int total_exp;        	//升级经验和	需要消耗总经验
	public int require_level;    	//等级需求	升级至下一级需要达到的等级
	public int marquee;          	//装备强化跑马灯	0不显示 1显示
	public li slot_1_attribute_1_phy;	//部位属性提升	武器栏属性提升1  属性ID|当前级别属性值
	public li slot_1_attribute_2_phy;	//部位属性提升	武器栏属性提升2  属性ID|当前级别属性值
	public li slot_1_attribute_3_phy;	//部位属性提升	武器栏属性提升3  属性ID|当前级别属性值
	public li slot_2_attribute_1_phy;	//部位属性提升	耳坠栏属性提升1  属性ID|当前级别属性值
	public li slot_2_attribute_2_phy;	//部位属性提升	耳坠栏属性提升2  属性ID|当前级别属性值
	public li slot_2_attribute_3_phy;	//部位属性提升	耳坠栏属性提升3  属性ID|当前级别属性值
	public li slot_3_attribute_1_phy;	//部位属性提升	项链栏属性提升1  属性ID|当前级别属性值
	public li slot_3_attribute_2_phy;	//部位属性提升	项链栏属性提升2  属性ID|当前级别属性值
	public li slot_3_attribute_3_phy;	//部位属性提升	项链栏属性提升3  属性ID|当前级别属性值
	public li slot_4_attribute_1_phy;	//部位属性提升	戒指栏属性提升1  属性ID|当前级别属性值
	public li slot_4_attribute_2_phy;	//部位属性提升	戒指栏属性提升2  属性ID|当前级别属性值
	public li slot_4_attribute_3_phy;	//部位属性提升	戒指栏属性提升3  属性ID|当前级别属性值
	public li slot_5_attribute_1_phy;	//部位属性提升	头盔栏属性提升1  属性ID|当前级别属性值
	public li slot_5_attribute_2_phy;	//部位属性提升	头盔栏属性提升2  属性ID|当前级别属性值
	public li slot_5_attribute_3_phy;	//部位属性提升	头盔栏属性提升3  属性ID|当前级别属性值
	public li slot_6_attribute_1_phy;	//部位属性提升	胸甲栏属性提升1  属性ID|当前级别属性值
	public li slot_6_attribute_2_phy;	//部位属性提升	胸甲栏属性提升2  属性ID|当前级别属性值
	public li slot_6_attribute_3_phy;	//部位属性提升	胸甲栏属性提升3  属性ID|当前级别属性值
	public li slot_7_attribute_1_phy;	//部位属性提升	臂甲栏属性提升1  属性ID|当前级别属性值
	public li slot_7_attribute_2_phy;	//部位属性提升	臂甲栏属性提升2  属性ID|当前级别属性值
	public li slot_7_attribute_3_phy;	//部位属性提升	臂甲栏属性提升3  属性ID|当前级别属性值
	public li slot_8_attribute_1_phy;	//部位属性提升	腿甲栏属性提升1  属性ID|当前级别属性值
	public li slot_8_attribute_2_phy;	//部位属性提升	腿甲栏属性提升2  属性ID|当前级别属性值
	public li slot_8_attribute_3_phy;	//部位属性提升	腿甲栏属性提升3  属性ID|当前级别属性值
	public li slot_1_attribute_1_mag;	//部位属性提升	武器栏属性提升1  属性ID|当前级别属性值
	public li slot_1_attribute_2_mag;	//部位属性提升	武器栏属性提升2  属性ID|当前级别属性值
	public li slot_1_attribute_3_mag;	//部位属性提升	武器栏属性提升3  属性ID|当前级别属性值
	public li slot_2_attribute_1_mag;	//部位属性提升	耳坠栏属性提升1  属性ID|当前级别属性值
	public li slot_2_attribute_2_mag;	//部位属性提升	耳坠栏属性提升2  属性ID|当前级别属性值
	public li slot_2_attribute_3_mag;	//部位属性提升	耳坠栏属性提升3  属性ID|当前级别属性值
	public li slot_3_attribute_1_mag;	//部位属性提升	项链栏属性提升1  属性ID|当前级别属性值
	public li slot_3_attribute_2_mag;	//部位属性提升	项链栏属性提升2  属性ID|当前级别属性值
	public li slot_3_attribute_3_mag;	//部位属性提升	项链栏属性提升3  属性ID|当前级别属性值
	public li slot_4_attribute_1_mag;	//部位属性提升	戒指栏属性提升1  属性ID|当前级别属性值
	public li slot_4_attribute_2_mag;	//部位属性提升	戒指栏属性提升2  属性ID|当前级别属性值
	public li slot_4_attribute_3_mag;	//部位属性提升	戒指栏属性提升3  属性ID|当前级别属性值
	public li slot_5_attribute_1_mag;	//部位属性提升	头盔栏属性提升1  属性ID|当前级别属性值
	public li slot_5_attribute_2_mag;	//部位属性提升	头盔栏属性提升2  属性ID|当前级别属性值
	public li slot_5_attribute_3_mag;	//部位属性提升	头盔栏属性提升3  属性ID|当前级别属性值
	public li slot_6_attribute_1_mag;	//部位属性提升	胸甲栏属性提升1  属性ID|当前级别属性值
	public li slot_6_attribute_2_mag;	//部位属性提升	胸甲栏属性提升2  属性ID|当前级别属性值
	public li slot_6_attribute_3_mag;	//部位属性提升	胸甲栏属性提升3  属性ID|当前级别属性值
	public li slot_7_attribute_1_mag;	//部位属性提升	臂甲栏属性提升1  属性ID|当前级别属性值
	public li slot_7_attribute_2_mag;	//部位属性提升	臂甲栏属性提升2  属性ID|当前级别属性值
	public li slot_7_attribute_3_mag;	//部位属性提升	臂甲栏属性提升3  属性ID|当前级别属性值
	public li slot_8_attribute_1_mag;	//部位属性提升	腿甲栏属性提升1  属性ID|当前级别属性值
	public li slot_8_attribute_2_mag;	//部位属性提升	腿甲栏属性提升2  属性ID|当前级别属性值
	public li slot_8_attribute_3_mag;	//部位属性提升	腿甲栏属性提升3  属性ID|当前级别属性值

	public bool IsValidate = false;
	public EquipSlotEnhanceElement()
	{
		id = -1;
	}
};

//装备强化配置封装类
public class EquipSlotEnhanceTable
{

	private EquipSlotEnhanceTable()
	{
		m_mapElements = new Dictionary<int, EquipSlotEnhanceElement>();
		m_emptyItem = new EquipSlotEnhanceElement();
		m_vecAllElements = new List<EquipSlotEnhanceElement>();
	}
	private Dictionary<int, EquipSlotEnhanceElement> m_mapElements = null;
	private List<EquipSlotEnhanceElement>	m_vecAllElements = null;
	private EquipSlotEnhanceElement m_emptyItem = null;
	private static EquipSlotEnhanceTable sInstance = null;

	public static EquipSlotEnhanceTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipSlotEnhanceTable();
			return sInstance;
		}
	}

	public EquipSlotEnhanceElement GetElement(int key)
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

  public List<EquipSlotEnhanceElement> GetAllElement(Predicate<EquipSlotEnhanceElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipSlotEnhance.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipSlotEnhance.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipSlotEnhance.bin]未找到");
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
		if(vecLine.Count != 56)
		{
			Ex.Logger.Log("EquipSlotEnhance.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[3]!="level"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[level]位置不对应"); return false; }
		if(vecLine[4]!="exp"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[5]!="total_exp"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[6]!="require_level"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[require_level]位置不对应"); return false; }
		if(vecLine[7]!="marquee"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[8]!="slot_1_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[9]!="slot_1_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[10]!="slot_1_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[11]!="slot_2_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[12]!="slot_2_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[13]!="slot_2_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[14]!="slot_3_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[15]!="slot_3_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[16]!="slot_3_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[17]!="slot_4_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[18]!="slot_4_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[19]!="slot_4_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[20]!="slot_5_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[21]!="slot_5_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[22]!="slot_5_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[23]!="slot_6_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[24]!="slot_6_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[25]!="slot_6_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[26]!="slot_7_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[27]!="slot_7_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[28]!="slot_7_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[29]!="slot_8_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[30]!="slot_8_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[31]!="slot_8_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[32]!="slot_1_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[33]!="slot_1_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[34]!="slot_1_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[35]!="slot_2_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[36]!="slot_2_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[37]!="slot_2_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[38]!="slot_3_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[39]!="slot_3_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[40]!="slot_3_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[41]!="slot_4_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[42]!="slot_4_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[43]!="slot_4_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[44]!="slot_5_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[45]!="slot_5_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[46]!="slot_5_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[47]!="slot_6_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[48]!="slot_6_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[49]!="slot_6_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[50]!="slot_7_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[51]!="slot_7_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[52]!="slot_7_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[53]!="slot_8_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[54]!="slot_8_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[55]!="slot_8_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_3_mag]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipSlotEnhanceElement member = new EquipSlotEnhanceElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.total_exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.require_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee );
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_1_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_2_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_3_phy);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_attribute_3_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_1_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_2_mag);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_attribute_3_mag);

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
		if(vecLine.Count != 56)
		{
			Ex.Logger.Log("EquipSlotEnhance.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[3]!="level"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[level]位置不对应"); return false; }
		if(vecLine[4]!="exp"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[5]!="total_exp"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[6]!="require_level"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[require_level]位置不对应"); return false; }
		if(vecLine[7]!="marquee"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[8]!="slot_1_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[9]!="slot_1_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[10]!="slot_1_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[11]!="slot_2_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[12]!="slot_2_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[13]!="slot_2_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[14]!="slot_3_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[15]!="slot_3_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[16]!="slot_3_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[17]!="slot_4_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[18]!="slot_4_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[19]!="slot_4_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[20]!="slot_5_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[21]!="slot_5_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[22]!="slot_5_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[23]!="slot_6_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[24]!="slot_6_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[25]!="slot_6_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[26]!="slot_7_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[27]!="slot_7_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[28]!="slot_7_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[29]!="slot_8_attribute_1_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_1_phy]位置不对应"); return false; }
		if(vecLine[30]!="slot_8_attribute_2_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_2_phy]位置不对应"); return false; }
		if(vecLine[31]!="slot_8_attribute_3_phy"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_3_phy]位置不对应"); return false; }
		if(vecLine[32]!="slot_1_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[33]!="slot_1_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[34]!="slot_1_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_1_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[35]!="slot_2_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[36]!="slot_2_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[37]!="slot_2_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_2_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[38]!="slot_3_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[39]!="slot_3_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[40]!="slot_3_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_3_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[41]!="slot_4_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[42]!="slot_4_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[43]!="slot_4_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_4_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[44]!="slot_5_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[45]!="slot_5_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[46]!="slot_5_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_5_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[47]!="slot_6_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[48]!="slot_6_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[49]!="slot_6_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_6_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[50]!="slot_7_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[51]!="slot_7_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[52]!="slot_7_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_7_attribute_3_mag]位置不对应"); return false; }
		if(vecLine[53]!="slot_8_attribute_1_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_1_mag]位置不对应"); return false; }
		if(vecLine[54]!="slot_8_attribute_2_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_2_mag]位置不对应"); return false; }
		if(vecLine[55]!="slot_8_attribute_3_mag"){Ex.Logger.Log("EquipSlotEnhance.csv中字段[slot_8_attribute_3_mag]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)56)
			{
				return false;
			}
			EquipSlotEnhanceElement member = new EquipSlotEnhanceElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.rank=Convert.ToInt32(vecLine[2]);
			member.level=Convert.ToInt32(vecLine[3]);
			member.exp=Convert.ToInt32(vecLine[4]);
			member.total_exp=Convert.ToInt32(vecLine[5]);
			member.require_level=Convert.ToInt32(vecLine[6]);
			member.marquee=Convert.ToInt32(vecLine[7]);
			member.slot_1_attribute_1_phy=vecLine[8];
			member.slot_1_attribute_2_phy=vecLine[9];
			member.slot_1_attribute_3_phy=vecLine[10];
			member.slot_2_attribute_1_phy=vecLine[11];
			member.slot_2_attribute_2_phy=vecLine[12];
			member.slot_2_attribute_3_phy=vecLine[13];
			member.slot_3_attribute_1_phy=vecLine[14];
			member.slot_3_attribute_2_phy=vecLine[15];
			member.slot_3_attribute_3_phy=vecLine[16];
			member.slot_4_attribute_1_phy=vecLine[17];
			member.slot_4_attribute_2_phy=vecLine[18];
			member.slot_4_attribute_3_phy=vecLine[19];
			member.slot_5_attribute_1_phy=vecLine[20];
			member.slot_5_attribute_2_phy=vecLine[21];
			member.slot_5_attribute_3_phy=vecLine[22];
			member.slot_6_attribute_1_phy=vecLine[23];
			member.slot_6_attribute_2_phy=vecLine[24];
			member.slot_6_attribute_3_phy=vecLine[25];
			member.slot_7_attribute_1_phy=vecLine[26];
			member.slot_7_attribute_2_phy=vecLine[27];
			member.slot_7_attribute_3_phy=vecLine[28];
			member.slot_8_attribute_1_phy=vecLine[29];
			member.slot_8_attribute_2_phy=vecLine[30];
			member.slot_8_attribute_3_phy=vecLine[31];
			member.slot_1_attribute_1_mag=vecLine[32];
			member.slot_1_attribute_2_mag=vecLine[33];
			member.slot_1_attribute_3_mag=vecLine[34];
			member.slot_2_attribute_1_mag=vecLine[35];
			member.slot_2_attribute_2_mag=vecLine[36];
			member.slot_2_attribute_3_mag=vecLine[37];
			member.slot_3_attribute_1_mag=vecLine[38];
			member.slot_3_attribute_2_mag=vecLine[39];
			member.slot_3_attribute_3_mag=vecLine[40];
			member.slot_4_attribute_1_mag=vecLine[41];
			member.slot_4_attribute_2_mag=vecLine[42];
			member.slot_4_attribute_3_mag=vecLine[43];
			member.slot_5_attribute_1_mag=vecLine[44];
			member.slot_5_attribute_2_mag=vecLine[45];
			member.slot_5_attribute_3_mag=vecLine[46];
			member.slot_6_attribute_1_mag=vecLine[47];
			member.slot_6_attribute_2_mag=vecLine[48];
			member.slot_6_attribute_3_mag=vecLine[49];
			member.slot_7_attribute_1_mag=vecLine[50];
			member.slot_7_attribute_2_mag=vecLine[51];
			member.slot_7_attribute_3_mag=vecLine[52];
			member.slot_8_attribute_1_mag=vecLine[53];
			member.slot_8_attribute_2_mag=vecLine[54];
			member.slot_8_attribute_3_mag=vecLine[55];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
