#ifndef __BUFF_CONFIG_H
#define __BUFF_CONFIG_H

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


//效果配置数据结构
struct BuffElement
{
	friend class BuffTable;
	int id;                      	//数据索引	数据索引
	int buffID;                  	//对应的BuffID	对应的BuffID
	int overTimed;               	//是否是延时性Buff	是否是延时性Buff
	int continuance;             	//如果是延时的，那么延时时间是多少	如果是延时的，那么延时时间是多少
	vector<int> pars;            	//参数	参数

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
	BuffElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//效果配置封装类
class BuffTable
{
	friend class TableData;
private:
	BuffTable(){}
	~BuffTable(){}
	unordered_map<int, BuffElement>	m_mapElements;
	vector<BuffElement>	m_vecAllElements;
	BuffElement m_emptyItem;
public:
	static BuffTable& Instance()
	{
		static BuffTable sInstance;
		return sInstance;
	}

	const BuffElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			BuffElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("BuffTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("BuffTable: ") + std::to_string(key)).c_str());
		return NULL;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffElement>&	GetAllElement()
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
		return LoadJson("Buff.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Buff.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Buff.bin", strTableContent ) )
		{
			printf_message("配置文件[Buff.bin]未找到");
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

			BuffElement	member;

						member.id=p.get<int>("id");
			member.buffID=p.get<int>("buffID");
			member.overTimed=p.get<int>("overTimed");
			member.continuance=p.get<int>("continuance");
			boost::property_tree::ptree sms_array_childpars = p.get_child("pars");
			for (BOOST_AUTO(pos, sms_array_childpars.begin()); pos != sms_array_childpars.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.pars.push_back(n);
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
		if(vecLine.size() != 5)
		{
			printf_message("Buff.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Buff.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="buffID"){printf_message("Buff.csv中字段[buffID]位置不对应");assert(false); return false; }
		if(vecLine[2]!="overTimed"){printf_message("Buff.csv中字段[overTimed]位置不对应");assert(false); return false; }
		if(vecLine[3]!="continuance"){printf_message("Buff.csv中字段[continuance]位置不对应");assert(false); return false; }
		if(vecLine[4]!="pars"){printf_message("Buff.csv中字段[pars]位置不对应");assert(false); return false; }

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
			BuffElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.buffID=(int)atoi(vecLine[1].c_str());
			member.overTimed=(int)atoi(vecLine[2].c_str());
			member.continuance=(int)atoi(vecLine[3].c_str());

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
