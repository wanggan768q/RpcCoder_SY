#ifndef __SERVERSCRIPT_CONFIG_H
#define __SERVERSCRIPT_CONFIG_H

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


//服务器脚本配置数据结构
struct ServerScriptElement
{
	friend class ServerScriptTable;
	int lua_id;                  	//脚本id	脚本id
	string file;                 	//	

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
	ServerScriptElement()
	{
		lua_id = -1;
		m_bIsValidate=false;
	}
};

//服务器脚本配置封装类
class ServerScriptTable
{
	friend class TableData;
private:
	ServerScriptTable(){}
	~ServerScriptTable(){}
	typedef unordered_map<int, ServerScriptElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<ServerScriptElement>	m_vecAllElements;
	ServerScriptElement m_emptyItem;
public:
	static ServerScriptTable& Instance()
	{
		static ServerScriptTable sInstance;
		return sInstance;
	}

	const ServerScriptElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("ServerScriptTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ServerScriptElement>&	GetAllElement()
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
		return LoadJson("ServerScript.json");
		#else
		string strTableContent;
		if( LoadConfigContent("ServerScript.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ServerScript.bin", strTableContent ) )
		{
			printf_message("配置文件[ServerScript.bin]未找到");
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

			ServerScriptElement	member;

						member.lua_id=p.get<int>("lua_id");
			member.file=p.get<string>("file");


			member.SetIsValidate(true);
			m_mapElements[member.lua_id] = member;
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
			printf_message("ServerScript.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="lua_id"){printf_message("ServerScript.csv中字段[lua_id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="file"){printf_message("ServerScript.csv中字段[file]位置不对应 ");assert(false); return false; }

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
			ServerScriptElement	member;
			member.lua_id=(int)atoi(vecLine[0].c_str());
			member.file=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.lua_id] = member;
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
