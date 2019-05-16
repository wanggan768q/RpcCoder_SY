#ifndef __EQUIPPROTO_CONFIG_H
#define __EQUIPPROTO_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备原型配置数据结构
struct EquipProtoElement
{
	friend class EquipProtoTable;
	int id;                      	//装备ID	{equip(0)}_{class(0)}_{lv(000)}_{rank(0)}_{suit(0)}_{part(0)}:    equip-2,    class-0_物理;1_法术;2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    suit-0_非套装;1_1天赋;2_2天赋    part-1_武器;2_耳环;3_项链;4_戒指;5_帽子;6_盔甲;7_臂甲;8_腿甲
	string comment;              	//道具注释	策划用
	int equip_level;             	//装备等级	根据装备等级 生成后缀属性区间
	int refine_cost;             	//洗练消耗	对该装备进行洗练时 消耗的软货币值
	vector<int> basic_attribute_1;	//基础属性条目1	分别对应 条目id|条目区间下限|条目区间上限
	vector<int> basic_attribute_2;	//基础属性条目2	分别对应 条目id|条目区间下限|条目区间上限
	vector<int> basic_attribute_3;	//基础属性条目3	分别对应 条目id|条目区间下限|条目区间上限
	vector<int> extra_attribute_num;	//后缀属性数量	分别对应 数量下限|数量上限
	int extra_attribute_type;    	//后缀属性分类	（暂不使用） 0全部 1攻击向 2防御向
	int special_skill_id;        	//特殊技能组id	对应特殊技能组id，如果不会生成特殊技能则不填
	int suit_id;                 	//套装id	该装备所对应的套装id

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
	EquipProtoElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备原型配置封装类
class EquipProtoTable
{
	friend class TableData;
private:
	EquipProtoTable(){}
	~EquipProtoTable(){}
	map<int, EquipProtoElement>	m_mapElements;
	vector<EquipProtoElement>	m_vecAllElements;
	EquipProtoElement m_emptyItem;
public:
	static EquipProtoTable& Instance()
	{
		static EquipProtoTable sInstance;
		return sInstance;
	}

	EquipProtoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipProtoElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipProto.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipProto.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipProto.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("EquipProto.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipProto.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipProto.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="equip_level"){printf_message("EquipProto.csv中字段[equip_level]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="refine_cost"){printf_message("EquipProto.csv中字段[refine_cost]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="basic_attribute_1"){printf_message("EquipProto.csv中字段[basic_attribute_1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="basic_attribute_2"){printf_message("EquipProto.csv中字段[basic_attribute_2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="basic_attribute_3"){printf_message("EquipProto.csv中字段[basic_attribute_3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="extra_attribute_num"){printf_message("EquipProto.csv中字段[extra_attribute_num]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="extra_attribute_type"){printf_message("EquipProto.csv中字段[extra_attribute_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="special_skill_id"){printf_message("EquipProto.csv中字段[special_skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="suit_id"){printf_message("EquipProto.csv中字段[suit_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			EquipProtoElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.equip_level=(int)atoi(vecLine[2].c_str());
			member.refine_cost=(int)atoi(vecLine[3].c_str());
			member.extra_attribute_type=(int)atoi(vecLine[8].c_str());
			member.special_skill_id=(int)atoi(vecLine[9].c_str());
			member.suit_id=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
