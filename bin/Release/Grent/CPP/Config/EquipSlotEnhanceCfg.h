#ifndef __EQUIPSLOTENHANCE_CONFIG_H
#define __EQUIPSLOTENHANCE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备强化配置数据结构
struct EquipSlotEnhanceElement
{
	friend class EquipSlotEnhanceTable;
	int id;                      	//阶级ID	每个阶级所对应的唯一ID
	string comment;              	//阶级注释	策划用
	int rank;                    	//对应段位	显示用的段位
	int level;                   	//对应等级	显示用的等级
	int exp;                     	//升级经验	升级至下一级需要的经验
	int total_exp;               	//升级经验和	需要消耗总经验
	int require_level;           	//等级需求	升级至下一级需要达到的等级
	int marquee;                 	//装备强化跑马灯	0不显示 1显示
	vector<int> slot_1_attribute_1_phy;	//部位属性提升	武器栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_1_attribute_2_phy;	//部位属性提升	武器栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_1_attribute_3_phy;	//部位属性提升	武器栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_2_attribute_1_phy;	//部位属性提升	耳坠栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_2_attribute_2_phy;	//部位属性提升	耳坠栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_2_attribute_3_phy;	//部位属性提升	耳坠栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_3_attribute_1_phy;	//部位属性提升	项链栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_3_attribute_2_phy;	//部位属性提升	项链栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_3_attribute_3_phy;	//部位属性提升	项链栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_4_attribute_1_phy;	//部位属性提升	戒指栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_4_attribute_2_phy;	//部位属性提升	戒指栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_4_attribute_3_phy;	//部位属性提升	戒指栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_5_attribute_1_phy;	//部位属性提升	头盔栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_5_attribute_2_phy;	//部位属性提升	头盔栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_5_attribute_3_phy;	//部位属性提升	头盔栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_6_attribute_1_phy;	//部位属性提升	胸甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_6_attribute_2_phy;	//部位属性提升	胸甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_6_attribute_3_phy;	//部位属性提升	胸甲栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_7_attribute_1_phy;	//部位属性提升	臂甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_7_attribute_2_phy;	//部位属性提升	臂甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_7_attribute_3_phy;	//部位属性提升	臂甲栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_8_attribute_1_phy;	//部位属性提升	腿甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_8_attribute_2_phy;	//部位属性提升	腿甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_8_attribute_3_phy;	//部位属性提升	腿甲栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_1_attribute_1_mag;	//部位属性提升	武器栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_1_attribute_2_mag;	//部位属性提升	武器栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_1_attribute_3_mag;	//部位属性提升	武器栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_2_attribute_1_mag;	//部位属性提升	耳坠栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_2_attribute_2_mag;	//部位属性提升	耳坠栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_2_attribute_3_mag;	//部位属性提升	耳坠栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_3_attribute_1_mag;	//部位属性提升	项链栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_3_attribute_2_mag;	//部位属性提升	项链栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_3_attribute_3_mag;	//部位属性提升	项链栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_4_attribute_1_mag;	//部位属性提升	戒指栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_4_attribute_2_mag;	//部位属性提升	戒指栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_4_attribute_3_mag;	//部位属性提升	戒指栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_5_attribute_1_mag;	//部位属性提升	头盔栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_5_attribute_2_mag;	//部位属性提升	头盔栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_5_attribute_3_mag;	//部位属性提升	头盔栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_6_attribute_1_mag;	//部位属性提升	胸甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_6_attribute_2_mag;	//部位属性提升	胸甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_6_attribute_3_mag;	//部位属性提升	胸甲栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_7_attribute_1_mag;	//部位属性提升	臂甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_7_attribute_2_mag;	//部位属性提升	臂甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_7_attribute_3_mag;	//部位属性提升	臂甲栏属性提升3  属性ID|当前级别属性值
	vector<int> slot_8_attribute_1_mag;	//部位属性提升	腿甲栏属性提升1  属性ID|当前级别属性值
	vector<int> slot_8_attribute_2_mag;	//部位属性提升	腿甲栏属性提升2  属性ID|当前级别属性值
	vector<int> slot_8_attribute_3_mag;	//部位属性提升	腿甲栏属性提升3  属性ID|当前级别属性值

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	EquipSlotEnhanceElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备强化配置封装类
class EquipSlotEnhanceTable
{
	friend class TableData;
private:
	EquipSlotEnhanceTable(){}
	~EquipSlotEnhanceTable(){}
	map<int, EquipSlotEnhanceElement>	m_mapElements;
	vector<EquipSlotEnhanceElement>	m_vecAllElements;
	EquipSlotEnhanceElement m_emptyItem;
public:
	static EquipSlotEnhanceTable& Instance()
	{
		static EquipSlotEnhanceTable sInstance;
		return sInstance;
	}

	EquipSlotEnhanceElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipSlotEnhanceElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("EquipSlotEnhance.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipSlotEnhance.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipSlotEnhance.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 56)
		{
			printf_message("EquipSlotEnhance.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipSlotEnhance.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipSlotEnhance.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rank"){printf_message("EquipSlotEnhance.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="level"){printf_message("EquipSlotEnhance.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="exp"){printf_message("EquipSlotEnhance.csv中字段[exp]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="total_exp"){printf_message("EquipSlotEnhance.csv中字段[total_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="require_level"){printf_message("EquipSlotEnhance.csv中字段[require_level]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="marquee"){printf_message("EquipSlotEnhance.csv中字段[marquee]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="slot_1_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="slot_1_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="slot_1_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="slot_2_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="slot_2_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="slot_2_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="slot_3_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="slot_3_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="slot_3_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="slot_4_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="slot_4_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="slot_4_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="slot_5_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="slot_5_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="slot_5_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="slot_6_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="slot_6_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="slot_6_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="slot_7_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="slot_7_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="slot_7_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="slot_8_attribute_1_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_1_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="slot_8_attribute_2_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_2_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="slot_8_attribute_3_phy"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_3_phy]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="slot_1_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="slot_1_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="slot_1_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_1_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="slot_2_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="slot_2_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="slot_2_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_2_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="slot_3_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="slot_3_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="slot_3_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_3_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="slot_4_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="slot_4_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="slot_4_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_4_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="slot_5_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="slot_5_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="slot_5_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_5_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="slot_6_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="slot_6_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="slot_6_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_6_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="slot_7_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="slot_7_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="slot_7_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_7_attribute_3_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="slot_8_attribute_1_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_1_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[54]!="slot_8_attribute_2_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_2_mag]位置不对应 ");assert(false); return false; }
		if(vecLine[55]!="slot_8_attribute_3_mag"){printf_message("EquipSlotEnhance.csv中字段[slot_8_attribute_3_mag]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)56)
			{
				assert(false);
				return false;
			}
			EquipSlotEnhanceElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.rank=(int)atoi(vecLine[2].c_str());
			member.level=(int)atoi(vecLine[3].c_str());
			member.exp=(int)atoi(vecLine[4].c_str());
			member.total_exp=(int)atoi(vecLine[5].c_str());
			member.require_level=(int)atoi(vecLine[6].c_str());
			member.marquee=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
