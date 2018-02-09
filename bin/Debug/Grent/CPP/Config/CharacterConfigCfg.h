#ifndef __CHARACTERCONFIG_CONFIG_H
#define __CHARACTERCONFIG_CONFIG_H

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


//模型配置配置数据结构
struct CharacterConfigElement
{
	friend class CharacterConfigTable;
	int id;                      	//配置ID	ID段划分： 0-1000特殊； 1000-9999角色； 10000-29999怪物； 30000-39999静物； 40000-49999npc； 50000-59999宠物
	string desc;                 	//描述	仅策划用
	string filename;             	//模型文件名	模型文件名
	string  material;            	//材质	需要更换的材质文件 （时装染色）
	vector<float> zoom;          	//缩放比例	X|Y|Z坐标
	vector<float> bound_center;  	//包围盒中心点	X|Y|Z坐标
	vector<float> bound_size;    	//包围盒大小	X|Y|Z坐标

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
	CharacterConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//模型配置配置封装类
class CharacterConfigTable
{
	friend class TableData;
private:
	CharacterConfigTable(){}
	~CharacterConfigTable(){}
	typedef unordered_map<int, CharacterConfigElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<CharacterConfigElement>	m_vecAllElements;
	CharacterConfigElement m_emptyItem;
public:
	static CharacterConfigTable& Instance()
	{
		static CharacterConfigTable sInstance;
		return sInstance;
	}

	const CharacterConfigElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("CharacterConfigTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CharacterConfigElement>&	GetAllElement()
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
		return LoadJson("CharacterConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CharacterConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CharacterConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[CharacterConfig.bin]未找到");
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

			CharacterConfigElement	member;

						member.id=p.get<int>("id");
			member.desc=p.get<string>("desc");
			member.filename=p.get<string>("filename");
			member. material=p.get<string>(" material");
			boost::property_tree::ptree sms_array_childzoom = p.get_child("zoom");
			for (BOOST_AUTO(pos, sms_array_childzoom.begin()); pos != sms_array_childzoom.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.zoom.push_back(n);
			}
			boost::property_tree::ptree sms_array_childbound_center = p.get_child("bound_center");
			for (BOOST_AUTO(pos, sms_array_childbound_center.begin()); pos != sms_array_childbound_center.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.bound_center.push_back(n);
			}
			boost::property_tree::ptree sms_array_childbound_size = p.get_child("bound_size");
			for (BOOST_AUTO(pos, sms_array_childbound_size.begin()); pos != sms_array_childbound_size.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.bound_size.push_back(n);
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
		if(vecLine.size() != 7)
		{
			printf_message("CharacterConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CharacterConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="desc"){printf_message("CharacterConfig.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="filename"){printf_message("CharacterConfig.csv中字段[filename]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!=" material"){printf_message("CharacterConfig.csv中字段[ material]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="zoom"){printf_message("CharacterConfig.csv中字段[zoom]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="bound_center"){printf_message("CharacterConfig.csv中字段[bound_center]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="bound_size"){printf_message("CharacterConfig.csv中字段[bound_size]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			CharacterConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.desc=vecLine[1];
			member.filename=vecLine[2];
			member. material=vecLine[3];

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
