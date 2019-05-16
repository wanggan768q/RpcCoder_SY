#ifndef __EXPERIENCE_CONFIG_H
#define __EXPERIENCE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色经验配置数据结构
struct ExperienceElement
{
	friend class ExperienceTable;
	int id;                      	//等级	等级
	int exp;                     	//本级经验	本级经验
	int total_exp;               	//经验总和	经验总和
	int blood_limit;             	//血池上限	血池上限
	int z_exp;                   	//占星经验值	1=10000
	int l_exp;                   	//猎魔经验值	1=10000
	int j_exp;                   	//精英怪经验值	1=10000
	int coe_tenacity;            	//治疗暴击修正参数	视为治疗韧性

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
	ExperienceElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色经验配置封装类
class ExperienceTable
{
	friend class TableData;
private:
	ExperienceTable(){}
	~ExperienceTable(){}
	map<int, ExperienceElement>	m_mapElements;
	vector<ExperienceElement>	m_vecAllElements;
	ExperienceElement m_emptyItem;
public:
	static ExperienceTable& Instance()
	{
		static ExperienceTable sInstance;
		return sInstance;
	}

	ExperienceElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ExperienceElement>&	GetAllElement()
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
		if( LoadConfigContent("Experience.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Experience.bin", strTableContent ) )
		{
			printf_message("配置文件[Experience.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("Experience.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Experience.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="exp"){printf_message("Experience.csv中字段[exp]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="total_exp"){printf_message("Experience.csv中字段[total_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="blood_limit"){printf_message("Experience.csv中字段[blood_limit]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="z_exp"){printf_message("Experience.csv中字段[z_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="l_exp"){printf_message("Experience.csv中字段[l_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="j_exp"){printf_message("Experience.csv中字段[j_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="coe_tenacity"){printf_message("Experience.csv中字段[coe_tenacity]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			ExperienceElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.exp=(int)atoi(vecLine[1].c_str());
			member.total_exp=(int)atoi(vecLine[2].c_str());
			member.blood_limit=(int)atoi(vecLine[3].c_str());
			member.z_exp=(int)atoi(vecLine[4].c_str());
			member.l_exp=(int)atoi(vecLine[5].c_str());
			member.j_exp=(int)atoi(vecLine[6].c_str());
			member.coe_tenacity=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
