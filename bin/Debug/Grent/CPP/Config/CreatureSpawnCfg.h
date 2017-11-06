#ifndef __CREATURESPAWN_CONFIG_H
#define __CREATURESPAWN_CONFIG_H

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


//NPC位置表配置数据结构
struct CreatureSpawnElement
{
	friend class CreatureSpawnTable;
	int spawn_id;                	//序号	序号
	int npc_entry_id;            	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	int spawn_map_id;            	//NPC所处的场景号	NPC所处的场景号
	float spawn_x;               	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	float spawn_y;               	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	int refresh_time;            	//NPC死亡后的刷新时间	NPC死亡后的刷新时间
	int refresh_type;            	//NPC死亡后的刷新类型	NPC死亡后的刷新类型
	string animation_default;    	//默认动画路径	默认动画路径
	string animation_delay;      	//动画延迟时间	动画延迟时间

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
	CreatureSpawnElement()
	{
		spawn_id = -1;
		m_bIsValidate=false;
	}
};

//NPC位置表配置封装类
class CreatureSpawnTable
{
	friend class TableData;
private:
	CreatureSpawnTable(){}
	~CreatureSpawnTable(){}
	unordered_map<int, CreatureSpawnElement>	m_mapElements;
	vector<CreatureSpawnElement>	m_vecAllElements;
	CreatureSpawnElement m_emptyItem;
public:
	static CreatureSpawnTable& Instance()
	{
		static CreatureSpawnTable sInstance;
		return sInstance;
	}

	const CreatureSpawnElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			CreatureSpawnElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("CreatureSpawnTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("CreatureSpawnTable: ") + std::to_string(key)).c_str());
		return NULL;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureSpawnElement>&	GetAllElement()
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
		return LoadJson("CreatureSpawn.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreatureSpawn.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureSpawn.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureSpawn.bin]未找到");
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

			CreatureSpawnElement	member;

						member.spawn_id=p.get<int>("spawn_id");
			member.npc_entry_id=p.get<int>("npc_entry_id");
			member.spawn_map_id=p.get<int>("spawn_map_id");
			member.spawn_x=p.get<float>("spawn_x");
			member.spawn_y=p.get<float>("spawn_y");
			member.spawn_z=p.get<float>("spawn_z");
			member.refresh_time=p.get<int>("refresh_time");
			member.refresh_type=p.get<int>("refresh_type");
			member.animation_default=p.get<string>("animation_default");
			member.animation_delay=p.get<string>("animation_delay");


			member.SetIsValidate(true);
			m_mapElements[member.spawn_id] = member;
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
		if(vecLine.size() != 10)
		{
			printf_message("CreatureSpawn.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="spawn_id"){printf_message("CreatureSpawn.csv中字段[spawn_id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="npc_entry_id"){printf_message("CreatureSpawn.csv中字段[npc_entry_id]位置不对应");assert(false); return false; }
		if(vecLine[2]!="spawn_map_id"){printf_message("CreatureSpawn.csv中字段[spawn_map_id]位置不对应");assert(false); return false; }
		if(vecLine[3]!="spawn_x"){printf_message("CreatureSpawn.csv中字段[spawn_x]位置不对应");assert(false); return false; }
		if(vecLine[4]!="spawn_y"){printf_message("CreatureSpawn.csv中字段[spawn_y]位置不对应");assert(false); return false; }
		if(vecLine[5]!="spawn_z"){printf_message("CreatureSpawn.csv中字段[spawn_z]位置不对应");assert(false); return false; }
		if(vecLine[6]!="refresh_time"){printf_message("CreatureSpawn.csv中字段[refresh_time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="refresh_type"){printf_message("CreatureSpawn.csv中字段[refresh_type]位置不对应");assert(false); return false; }
		if(vecLine[8]!="animation_default"){printf_message("CreatureSpawn.csv中字段[animation_default]位置不对应");assert(false); return false; }
		if(vecLine[9]!="animation_delay"){printf_message("CreatureSpawn.csv中字段[animation_delay]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			CreatureSpawnElement	member;
			member.spawn_id=(int)atoi(vecLine[0].c_str());
			member.npc_entry_id=(int)atoi(vecLine[1].c_str());
			member.spawn_map_id=(int)atoi(vecLine[2].c_str());
			member.spawn_x=(float)atof(vecLine[3].c_str());
			member.spawn_y=(float)atof(vecLine[4].c_str());
			member.spawn_z=(float)atof(vecLine[5].c_str());
			member.refresh_time=(int)atoi(vecLine[6].c_str());
			member.refresh_type=(int)atoi(vecLine[7].c_str());
			member.animation_default=vecLine[8];
			member.animation_delay=vecLine[9];

			member.SetIsValidate(true);
			m_mapElements[member.spawn_id] = member;
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
