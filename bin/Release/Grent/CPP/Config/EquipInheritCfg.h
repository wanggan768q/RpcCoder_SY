#ifndef __EQUIPINHERIT_CONFIG_H
#define __EQUIPINHERIT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备继承配置数据结构
struct EquipInheritElement
{
	friend class EquipInheritTable;
	int id;                      	//阶级ID	每个阶级所对应的唯一ID
	string comment;              	//阶级注释	策划用
	int equip_level;             	//对应装等	该装备所对应的equipprote表的equip_level字段
	vector<int> cost;            	//继承消耗	继承该装备属性所消耗的道具id和道具数量 道具id|数量

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
	EquipInheritElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备继承配置封装类
class EquipInheritTable
{
	friend class TableData;
private:
	EquipInheritTable(){}
	~EquipInheritTable(){}
	map<int, EquipInheritElement>	m_mapElements;
	vector<EquipInheritElement>	m_vecAllElements;
	EquipInheritElement m_emptyItem;
public:
	static EquipInheritTable& Instance()
	{
		static EquipInheritTable sInstance;
		return sInstance;
	}

	EquipInheritElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipInheritElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipInherit.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipInherit.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipInherit.bin]未找到");
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
		if(vecLine.size() != 4)
		{
			printf_message("EquipInherit.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipInherit.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipInherit.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="equip_level"){printf_message("EquipInherit.csv中字段[equip_level]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="cost"){printf_message("EquipInherit.csv中字段[cost]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			EquipInheritElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.equip_level=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
