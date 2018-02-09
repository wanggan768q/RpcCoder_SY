#ifndef __VALUE_CONFIG_H
#define __VALUE_CONFIG_H

#include "CommonDefine.h"
#include "DK_Assertx.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//参数配置数据结构
struct ValueElement
{
	friend class ValueTable;
	int id;                      	//序号	序号
	int value;                   	//值	值
	string interpretation;       	//描述	描述

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
	ValueElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//参数配置封装类
class ValueTable
{
	friend class TableData;
private:
	ValueTable(){}
	~ValueTable(){}
	typedef unordered_map<int, ValueElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<ValueElement>	m_vecAllElements;
	ValueElement m_emptyItem;
public:
	static ValueTable& Instance()
	{
		static ValueTable sInstance;
		return sInstance;
	}

	const ValueElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("ValueTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ValueElement>&	GetAllElement()
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
		return LoadJson("Value.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Value.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Value.bin", strTableContent ) )
		{
			printf_message("配置文件[Value.bin]未找到");
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

			ValueElement	member;

						member.id=p.get<int>("id");
			member.value=p.get<int>("value");
			member.interpretation=p.get<string>("interpretation");


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
			printf_message("Value.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Value.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="value"){printf_message("Value.csv中字段[value]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="interpretation"){printf_message("Value.csv中字段[interpretation]位置不对应 ");assert(false); return false; }

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
			ValueElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.value=(int)atoi(vecLine[1].c_str());
			member.interpretation=vecLine[2];

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
