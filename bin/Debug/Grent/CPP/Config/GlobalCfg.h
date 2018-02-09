#ifndef __GLOBAL_CONFIG_H
#define __GLOBAL_CONFIG_H

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


//全局配置配置数据结构
struct GlobalElement
{
	friend class GlobalTable;
	int id;                      	//id	数据的id
	string comment;              	//注释	该数据的功能
	int int_value;               	//整型数据	整型数据
	float float_value;           	//浮点数据	浮点数据
	string string_value;         	//字符串数据	字符串数据
	vector<int> list_int_value;  	//数组整型数据	数组整型数据
	vector<float> list_float_value;	//数组浮点数据	数组浮点数据
	vector<string> list_string_value;	//数组字符串数据	数组字符串数据

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
	GlobalElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//全局配置配置封装类
class GlobalTable
{
	friend class TableData;
private:
	GlobalTable(){}
	~GlobalTable(){}
	typedef unordered_map<int, GlobalElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<GlobalElement>	m_vecAllElements;
	GlobalElement m_emptyItem;
public:
	static GlobalTable& Instance()
	{
		static GlobalTable sInstance;
		return sInstance;
	}

	const GlobalElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("GlobalTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GlobalElement>&	GetAllElement()
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
		return LoadJson("Global.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Global.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Global.bin", strTableContent ) )
		{
			printf_message("配置文件[Global.bin]未找到");
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

			GlobalElement	member;

						member.id=p.get<int>("id");
			member.comment=p.get<string>("comment");
			member.int_value=p.get<int>("int_value");
			member.float_value=p.get<float>("float_value");
			member.string_value=p.get<string>("string_value");
			boost::property_tree::ptree sms_array_childlist_int_value = p.get_child("list_int_value");
			for (BOOST_AUTO(pos, sms_array_childlist_int_value.begin()); pos != sms_array_childlist_int_value.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.list_int_value.push_back(n);
			}
			boost::property_tree::ptree sms_array_childlist_float_value = p.get_child("list_float_value");
			for (BOOST_AUTO(pos, sms_array_childlist_float_value.begin()); pos != sms_array_childlist_float_value.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.list_float_value.push_back(n);
			}
			boost::property_tree::ptree sms_array_childlist_string_value = p.get_child("list_string_value");
			for (BOOST_AUTO(pos, sms_array_childlist_string_value.begin()); pos != sms_array_childlist_string_value.end(); ++pos)
			{
				string n = pos->second.get_value<string>(); 
				member.list_string_value.push_back(n);
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
		if(vecLine.size() != 8)
		{
			printf_message("Global.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Global.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Global.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="int_value"){printf_message("Global.csv中字段[int_value]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="float_value"){printf_message("Global.csv中字段[float_value]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="string_value"){printf_message("Global.csv中字段[string_value]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="list_int_value"){printf_message("Global.csv中字段[list_int_value]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="list_float_value"){printf_message("Global.csv中字段[list_float_value]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="list_string_value"){printf_message("Global.csv中字段[list_string_value]位置不对应 ");assert(false); return false; }

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
			GlobalElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.int_value=(int)atoi(vecLine[2].c_str());
			member.float_value=(float)atof(vecLine[3].c_str());
			member.string_value=vecLine[4];

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
