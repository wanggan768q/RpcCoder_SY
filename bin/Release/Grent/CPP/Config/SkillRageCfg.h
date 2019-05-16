#ifndef __SKILLRAGE_CONFIG_H
#define __SKILLRAGE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//技能仇恨表配置数据结构
struct SkillRageElement
{
	friend class SkillRageTable;
	int id;                      	//技能ID	填写仇恨系数或仇恨值需要特殊处理的技能ID 未在本表中出现的技能，仇恨倍率和仇恨值默认均为1
	string skill_name;           	//技能名称	技能名称，策划用
	float rage_rate;             	//仇恨倍率	可正负，小数
	int rage_value;              	//仇恨值	可正负，整数
	string comment;              	//备注	备注

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
	SkillRageElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//技能仇恨表配置封装类
class SkillRageTable
{
	friend class TableData;
private:
	SkillRageTable(){}
	~SkillRageTable(){}
	map<int, SkillRageElement>	m_mapElements;
	vector<SkillRageElement>	m_vecAllElements;
	SkillRageElement m_emptyItem;
public:
	static SkillRageTable& Instance()
	{
		static SkillRageTable sInstance;
		return sInstance;
	}

	SkillRageElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillRageElement>&	GetAllElement()
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
		if( LoadConfigContent("SkillRage.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SkillRage.bin", strTableContent ) )
		{
			printf_message("配置文件[SkillRage.bin]未找到");
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
		if(vecLine.size() != 5)
		{
			printf_message("SkillRage.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("SkillRage.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="skill_name"){printf_message("SkillRage.csv中字段[skill_name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rage_rate"){printf_message("SkillRage.csv中字段[rage_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="rage_value"){printf_message("SkillRage.csv中字段[rage_value]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="comment"){printf_message("SkillRage.csv中字段[comment]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)5)
			{
				assert(false);
				return false;
			}
			SkillRageElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.skill_name=vecLine[1];
			member.rage_rate=(float)atof(vecLine[2].c_str());
			member.rage_value=(int)atoi(vecLine[3].c_str());
			member.comment=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
