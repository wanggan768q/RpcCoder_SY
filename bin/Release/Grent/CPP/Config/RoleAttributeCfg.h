#ifndef __ROLEATTRIBUTE_CONFIG_H
#define __ROLEATTRIBUTE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色属性值配置数据结构
struct RoleAttributeElement
{
	friend class RoleAttributeTable;
	int id;                      	//id	无意义
	int config_id;               	//配置id	对应role表中的id
	string comment;              	//注释	注释
	int attr_type;               	//属性类型	属性类型
	int attr_value;              	//初始属性值	初始属性值
	int attr_add;                	//成长属性值	成长属性值

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
	RoleAttributeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色属性值配置封装类
class RoleAttributeTable
{
	friend class TableData;
private:
	RoleAttributeTable(){}
	~RoleAttributeTable(){}
	map<int, RoleAttributeElement>	m_mapElements;
	vector<RoleAttributeElement>	m_vecAllElements;
	RoleAttributeElement m_emptyItem;
public:
	static RoleAttributeTable& Instance()
	{
		static RoleAttributeTable sInstance;
		return sInstance;
	}

	RoleAttributeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RoleAttributeElement>&	GetAllElement()
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
		if( LoadConfigContent("RoleAttribute.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("RoleAttribute.bin", strTableContent ) )
		{
			printf_message("配置文件[RoleAttribute.bin]未找到");
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
		if(vecLine.size() != 6)
		{
			printf_message("RoleAttribute.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("RoleAttribute.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="config_id"){printf_message("RoleAttribute.csv中字段[config_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="comment"){printf_message("RoleAttribute.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="attr_type"){printf_message("RoleAttribute.csv中字段[attr_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="attr_value"){printf_message("RoleAttribute.csv中字段[attr_value]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="attr_add"){printf_message("RoleAttribute.csv中字段[attr_add]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			RoleAttributeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.config_id=(int)atoi(vecLine[1].c_str());
			member.comment=vecLine[2];
			member.attr_type=(int)atoi(vecLine[3].c_str());
			member.attr_value=(int)atoi(vecLine[4].c_str());
			member.attr_add=(int)atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
