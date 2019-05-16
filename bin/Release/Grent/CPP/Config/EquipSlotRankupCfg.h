#ifndef __EQUIPSLOTRANKUP_CONFIG_H
#define __EQUIPSLOTRANKUP_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备升星配置数据结构
struct EquipSlotRankupElement
{
	friend class EquipSlotRankupTable;
	int id;                      	//星级ID	每个阶级所对应的唯一ID
	string comment;              	//阶级注释	策划用
	int rank;                    	//符文数量	当前等级显示用
	int level;                   	//星级数量	当前等级显示用
	float rankup_rate;           	//成功率	升至下级需要 1表示100%
	float rankdown_rate;         	//降级率	升至下级需要 1表示100%
	vector<int> rankup_require;  	//升星道具	升至下级需要 道具id|道具数量
	vector<int> safe_rankup_require;	//保底升星道具	升至下级需要 道具id|道具数量
	int attribute;               	//属性成长	当前级别 属性成长百分比 1表示1%
	int unlock_needed;           	//需要解锁	当前级别需求 该等级需要解锁
	int slot_1_requirement;      	//解锁需求	当前级别武器栏解锁需要达到的爬塔等级
	int slot_2_requirement;      	//解锁需求	当前级别耳坠解锁需要达到的爬塔等级
	int slot_3_requirement;      	//解锁需求	当前级别项链解锁需要达到的爬塔等级
	int slot_4_requirement;      	//解锁需求	当前级别戒指解锁需要达到的爬塔等级
	int slot_5_requirement;      	//解锁需求	当前级别头盔解锁需要达到的爬塔等级
	int slot_6_requirement;      	//解锁需求	当前级别胸甲解锁需要达到的爬塔等级
	int slot_7_requirement;      	//解锁需求	当前级别臂甲解锁需要达到的爬塔等级
	int slot_8_requirement;      	//解锁需求	当前级别腿甲解锁需要达到的爬塔等级

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
	EquipSlotRankupElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备升星配置封装类
class EquipSlotRankupTable
{
	friend class TableData;
private:
	EquipSlotRankupTable(){}
	~EquipSlotRankupTable(){}
	map<int, EquipSlotRankupElement>	m_mapElements;
	vector<EquipSlotRankupElement>	m_vecAllElements;
	EquipSlotRankupElement m_emptyItem;
public:
	static EquipSlotRankupTable& Instance()
	{
		static EquipSlotRankupTable sInstance;
		return sInstance;
	}

	EquipSlotRankupElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipSlotRankupElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipSlotRankup.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipSlotRankup.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipSlotRankup.bin]未找到");
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
		if(vecLine.size() != 18)
		{
			printf_message("EquipSlotRankup.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipSlotRankup.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipSlotRankup.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rank"){printf_message("EquipSlotRankup.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="level"){printf_message("EquipSlotRankup.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="rankup_rate"){printf_message("EquipSlotRankup.csv中字段[rankup_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="rankdown_rate"){printf_message("EquipSlotRankup.csv中字段[rankdown_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="rankup_require"){printf_message("EquipSlotRankup.csv中字段[rankup_require]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="safe_rankup_require"){printf_message("EquipSlotRankup.csv中字段[safe_rankup_require]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="attribute"){printf_message("EquipSlotRankup.csv中字段[attribute]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="unlock_needed"){printf_message("EquipSlotRankup.csv中字段[unlock_needed]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="slot_1_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_1_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="slot_2_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_2_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="slot_3_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_3_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="slot_4_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_4_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="slot_5_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_5_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="slot_6_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_6_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="slot_7_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_7_requirement]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="slot_8_requirement"){printf_message("EquipSlotRankup.csv中字段[slot_8_requirement]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)18)
			{
				assert(false);
				return false;
			}
			EquipSlotRankupElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.rank=(int)atoi(vecLine[2].c_str());
			member.level=(int)atoi(vecLine[3].c_str());
			member.rankup_rate=(float)atof(vecLine[4].c_str());
			member.rankdown_rate=(float)atof(vecLine[5].c_str());
			member.attribute=(int)atoi(vecLine[8].c_str());
			member.unlock_needed=(int)atoi(vecLine[9].c_str());
			member.slot_1_requirement=(int)atoi(vecLine[10].c_str());
			member.slot_2_requirement=(int)atoi(vecLine[11].c_str());
			member.slot_3_requirement=(int)atoi(vecLine[12].c_str());
			member.slot_4_requirement=(int)atoi(vecLine[13].c_str());
			member.slot_5_requirement=(int)atoi(vecLine[14].c_str());
			member.slot_6_requirement=(int)atoi(vecLine[15].c_str());
			member.slot_7_requirement=(int)atoi(vecLine[16].c_str());
			member.slot_8_requirement=(int)atoi(vecLine[17].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
