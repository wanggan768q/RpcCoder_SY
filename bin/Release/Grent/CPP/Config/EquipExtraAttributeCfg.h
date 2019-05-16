#ifndef __EQUIPEXTRAATTRIBUTE_CONFIG_H
#define __EQUIPEXTRAATTRIBUTE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备后缀属性配置数据结构
struct EquipExtraAttributeElement
{
	friend class EquipExtraAttributeTable;
	int id;                      	//后缀属性id	对应装备级别
	string comment;              	//道具注释	策划用
	vector<int> item;            	//消耗道具	道具ID|数量
	vector<int> consume;         	//锁定消耗	数量
	int consume_item;            	//锁定消耗	道具ID
	vector<int> consume_num;     	//锁定消耗	数量
	vector<int> quality_weight;  	//品质权值	白|绿|蓝|紫|橙
	vector<int> max_hp;          	//生命上限	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> physic_damage;   	//物理攻击	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> magic_damage;    	//魔法攻击	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> physic_defense;  	//物理防御	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> magic_defense;   	//魔法防御	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> critical;        	//暴击值	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> tenacity;        	//韧性值	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> penetrate;       	//穿透值	分别对应 属性id|属性权值|属性下限|属性上限
	vector<int> block;           	//格挡值	分别对应 属性id|属性权值|属性下限|属性上限

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
	EquipExtraAttributeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备后缀属性配置封装类
class EquipExtraAttributeTable
{
	friend class TableData;
private:
	EquipExtraAttributeTable(){}
	~EquipExtraAttributeTable(){}
	map<int, EquipExtraAttributeElement>	m_mapElements;
	vector<EquipExtraAttributeElement>	m_vecAllElements;
	EquipExtraAttributeElement m_emptyItem;
public:
	static EquipExtraAttributeTable& Instance()
	{
		static EquipExtraAttributeTable sInstance;
		return sInstance;
	}

	EquipExtraAttributeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipExtraAttributeElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipExtraAttribute.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipExtraAttribute.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipExtraAttribute.bin]未找到");
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
		if(vecLine.size() != 16)
		{
			printf_message("EquipExtraAttribute.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipExtraAttribute.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipExtraAttribute.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="item"){printf_message("EquipExtraAttribute.csv中字段[item]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="consume"){printf_message("EquipExtraAttribute.csv中字段[consume]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="consume_item"){printf_message("EquipExtraAttribute.csv中字段[consume_item]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="consume_num"){printf_message("EquipExtraAttribute.csv中字段[consume_num]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="quality_weight"){printf_message("EquipExtraAttribute.csv中字段[quality_weight]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="max_hp"){printf_message("EquipExtraAttribute.csv中字段[max_hp]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="physic_damage"){printf_message("EquipExtraAttribute.csv中字段[physic_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="magic_damage"){printf_message("EquipExtraAttribute.csv中字段[magic_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="physic_defense"){printf_message("EquipExtraAttribute.csv中字段[physic_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="magic_defense"){printf_message("EquipExtraAttribute.csv中字段[magic_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="critical"){printf_message("EquipExtraAttribute.csv中字段[critical]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="tenacity"){printf_message("EquipExtraAttribute.csv中字段[tenacity]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="penetrate"){printf_message("EquipExtraAttribute.csv中字段[penetrate]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="block"){printf_message("EquipExtraAttribute.csv中字段[block]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)16)
			{
				assert(false);
				return false;
			}
			EquipExtraAttributeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.consume_item=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
