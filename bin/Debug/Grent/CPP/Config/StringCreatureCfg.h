#ifndef __STRINGCREATURE_CONFIG_H
#define __STRINGCREATURE_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//NPC文本表配置数据结构
struct StringCreatureElement
{
	friend class StringCreatureTable;
	int id;                      	//序号	序号
	string sc;                   	//简体中文	简体中文

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
	StringCreatureElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC文本表配置封装类
class StringCreatureTable
{
	friend class TableData;
private:
	StringCreatureTable(){}
	~StringCreatureTable(){}
	map<int, StringCreatureElement>	m_mapElements;
	vector<StringCreatureElement>	m_vecAllElements;
	StringCreatureElement m_emptyItem;
public:
	static StringCreatureTable& Instance()
	{
		static StringCreatureTable sInstance;
		return sInstance;
	}

	StringCreatureElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringCreatureElement>&	GetAllElement()
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
		return LoadJson("StringCreature.json");
		#else
		string strTableContent;
		if( LoadConfigContent("StringCreature.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringCreature.bin", strTableContent ) )
		{
			printf_message("配置文件[StringCreature.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree parse;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, parse);
		boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			StringCreatureElement	member;

						member.id=p.get<int>("id");
			member.sc=p.get<string>("sc");


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
		if(vecLine.size() != 2)
		{
			printf_message("StringCreature.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringCreature.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="sc"){printf_message("StringCreature.csv中字段[sc]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)2)
			{
				assert(false);
				return false;
			}
			StringCreatureElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.sc=vecLine[1];

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
