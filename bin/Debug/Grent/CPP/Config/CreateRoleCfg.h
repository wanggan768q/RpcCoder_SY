#ifndef __CREATEROLE_CONFIG_H
#define __CREATEROLE_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//角色配置数据结构
struct CreateRoleElement
{
	friend class CreateRoleTable;
	int id;                      	//种族	种族
	vector<int> occupation;      	//职业	1:战士 2:法师
	vector<int> sex;             	//性别	1:男性 2:女性

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
	CreateRoleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色配置封装类
class CreateRoleTable
{
	friend class TableData;
private:
	CreateRoleTable(){}
	~CreateRoleTable(){}
	map<int, CreateRoleElement>	m_mapElements;
	vector<CreateRoleElement>	m_vecAllElements;
	CreateRoleElement m_emptyItem;
public:
	static CreateRoleTable& Instance()
	{
		static CreateRoleTable sInstance;
		return sInstance;
	}

	CreateRoleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreateRoleElement>&	GetAllElement()
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
		return LoadJson("CreateRole.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreateRole.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreateRole.bin", strTableContent ) )
		{
			printf_message("配置文件[CreateRole.bin]未找到");
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

			CreateRoleElement	member;

						member.id=p.get<int>("id");
			boost::property_tree::ptree sms_array_childoccupation = p.get_child("occupation");
			for (BOOST_AUTO(pos, sms_array_childoccupation.begin()); pos != sms_array_childoccupation.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.occupation.push_back(n);
			}
			boost::property_tree::ptree sms_array_childsex = p.get_child("sex");
			for (BOOST_AUTO(pos, sms_array_childsex.begin()); pos != sms_array_childsex.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.sex.push_back(n);
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
			printf_message("CreateRole.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreateRole.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="occupation"){printf_message("CreateRole.csv中字段[occupation]位置不对应");assert(false); return false; }
		if(vecLine[2]!="sex"){printf_message("CreateRole.csv中字段[sex]位置不对应");assert(false); return false; }

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
			CreateRoleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());

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
