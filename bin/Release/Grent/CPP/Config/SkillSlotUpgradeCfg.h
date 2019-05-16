#ifndef __SKILLSLOTUPGRADE_CONFIG_H
#define __SKILLSLOTUPGRADE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//技能槽培养表配置数据结构
struct SkillSlotUpgradeElement
{
	friend class SkillSlotUpgradeTable;
	int id;                      	//条目id	id的值为技能槽id*1000+当前该槽等级
	int slot_id;                 	//技能槽id	对应技能槽在代码中的id 0.普攻技能 1.技能槽1 2.技能槽2 3.技能槽3 4.技能槽4 5.QTE技能
	int lv;                      	//技能槽等级	该技能槽当前的等级
	int cost;                    	//升级消费	升级至下一等级需要消耗的银币数量 
	int required_lv;             	//等级锁	升级至下一等级需要达到的角色级别
	vector<int> phy_attribute_1; 	//物理职业属性加成1	该技能槽改等级所加成的属性类型及属性值1 属性类型|属性值
	vector<int> phy_attribute_2; 	//物理职业属性加成2	该技能槽改等级所加成的属性类型及属性值2 属性类型|属性值
	vector<int> mag_attribute_1; 	//魔法职业属性加成1	该技能槽改等级所加成的属性类型及属性值1 属性类型|属性值
	vector<int> mag_attribute_2; 	//魔法职业属性加成2	该技能槽改等级所加成的属性类型及属性值2 属性类型|属性值

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
	SkillSlotUpgradeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//技能槽培养表配置封装类
class SkillSlotUpgradeTable
{
	friend class TableData;
private:
	SkillSlotUpgradeTable(){}
	~SkillSlotUpgradeTable(){}
	map<int, SkillSlotUpgradeElement>	m_mapElements;
	vector<SkillSlotUpgradeElement>	m_vecAllElements;
	SkillSlotUpgradeElement m_emptyItem;
public:
	static SkillSlotUpgradeTable& Instance()
	{
		static SkillSlotUpgradeTable sInstance;
		return sInstance;
	}

	SkillSlotUpgradeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillSlotUpgradeElement>&	GetAllElement()
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
		if( LoadConfigContent("SkillSlotUpgrade.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SkillSlotUpgrade.bin", strTableContent ) )
		{
			printf_message("配置文件[SkillSlotUpgrade.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("SkillSlotUpgrade.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("SkillSlotUpgrade.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="slot_id"){printf_message("SkillSlotUpgrade.csv中字段[slot_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="lv"){printf_message("SkillSlotUpgrade.csv中字段[lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="cost"){printf_message("SkillSlotUpgrade.csv中字段[cost]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="required_lv"){printf_message("SkillSlotUpgrade.csv中字段[required_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="phy_attribute_1"){printf_message("SkillSlotUpgrade.csv中字段[phy_attribute_1]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="phy_attribute_2"){printf_message("SkillSlotUpgrade.csv中字段[phy_attribute_2]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="mag_attribute_1"){printf_message("SkillSlotUpgrade.csv中字段[mag_attribute_1]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="mag_attribute_2"){printf_message("SkillSlotUpgrade.csv中字段[mag_attribute_2]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			SkillSlotUpgradeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.slot_id=(int)atoi(vecLine[1].c_str());
			member.lv=(int)atoi(vecLine[2].c_str());
			member.cost=(int)atoi(vecLine[3].c_str());
			member.required_lv=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
