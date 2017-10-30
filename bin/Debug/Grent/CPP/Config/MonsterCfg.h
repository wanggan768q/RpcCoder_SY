#ifndef __MONSTER_CONFIG_H
#define __MONSTER_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//怪物模板配置数据结构
struct MonsterElement
{
	friend class MonsterTable;
	int id;                      	//序号	序号
	string name;                 	//名字	名字
	vector<int> skills;          	//属性参数1	属性参数1

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
	MonsterElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//怪物模板配置封装类
class MonsterTable
{
	friend class TableData;
private:
	MonsterTable(){}
	~MonsterTable(){}
	map<int, MonsterElement>	m_mapElements;
	vector<MonsterElement>	m_vecAllElements;
	MonsterElement m_emptyItem;
public:
	static MonsterTable& Instance()
	{
		static MonsterTable sInstance;
		return sInstance;
	}

	const MonsterElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		return NULL;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MonsterElement>&	GetAllElement()
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
		#ifdef CONFIG_JSON
		return LoadJson("Monster.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Monster.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Monster.bin", strTableContent ) )
		{
			printf_message("配置文件[Monster.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			MonsterElement	member;

						member.id=p.get<int>("id");
			member.name=p.get<string>("name");
			boost::property_tree::ptree sms_array_childskills = p.get_child("skills");
			for (BOOST_AUTO(pos, sms_array_childskills.begin()); pos != sms_array_childskills.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.skills.push_back(n);
			}


			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}

		return true;
	}

	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 3)
		{
			printf_message("Monster.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Monster.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("Monster.csv中字段[name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="skills"){printf_message("Monster.csv中字段[skills]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)3)
			{
				assert(false);
				return false;
			}
			MonsterElement	member;
			member.id=atoi(vecLine[0].c_str());
			member.name=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}

	vector<string> ReadCsvLine(string strContent,int contentOffset)
	{
		vector<string> temp;
		return temp;

	}
};

#endif
