#ifndef __CREATUREDUMMY_CONFIG_H
#define __CREATUREDUMMY_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//多NPC巡逻盒子表配置数据结构
struct CreatureDummyElement
{
	friend class CreatureDummyTable;
	int dummy_id;                	//序号	序号
	int spawn_map_id;            	//dummy所在的场景ID	dummy所在的场景ID
	float spawn_x;               	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	float spawn_y;               	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	float move_speed;            	//dummy的移动速度	dummy的移动速度
	int attached_npc_01;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_02;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_03;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_04;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_05;         	//所附带的NPC ID	所附带的NPC ID
	int waypoint_start;          	//dummy的出生路点	dummy的出生路点

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
	CreatureDummyElement()
	{
		dummy_id = -1;
		m_bIsValidate=false;
	}
};

//多NPC巡逻盒子表配置封装类
class CreatureDummyTable
{
	friend class TableData;
private:
	CreatureDummyTable(){}
	~CreatureDummyTable(){}
	map<int, CreatureDummyElement>	m_mapElements;
	vector<CreatureDummyElement>	m_vecAllElements;
	CreatureDummyElement m_emptyItem;
public:
	static CreatureDummyTable& Instance()
	{
		static CreatureDummyTable sInstance;
		return sInstance;
	}

	CreatureDummyElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureDummyElement>&	GetAllElement()
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
		return LoadJson("CreatureDummy.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreatureDummy.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureDummy.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureDummy.bin]未找到");
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

			CreatureDummyElement	member;

						member.dummy_id=p.get<int>("dummy_id");
			member.spawn_map_id=p.get<int>("spawn_map_id");
			member.spawn_x=p.get<float>("spawn_x");
			member.spawn_y=p.get<float>("spawn_y");
			member.spawn_z=p.get<float>("spawn_z");
			member.move_speed=p.get<float>("move_speed");
			member.attached_npc_01=p.get<int>("attached_npc_01");
			member.attached_npc_02=p.get<int>("attached_npc_02");
			member.attached_npc_03=p.get<int>("attached_npc_03");
			member.attached_npc_04=p.get<int>("attached_npc_04");
			member.attached_npc_05=p.get<int>("attached_npc_05");
			member.waypoint_start=p.get<int>("waypoint_start");


			member.SetIsValidate(true);
			m_mapElements[member.dummy_id] = member;
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
		if(vecLine.size() != 12)
		{
			printf_message("CreatureDummy.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="dummy_id"){printf_message("CreatureDummy.csv中字段[dummy_id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="spawn_map_id"){printf_message("CreatureDummy.csv中字段[spawn_map_id]位置不对应");assert(false); return false; }
		if(vecLine[2]!="spawn_x"){printf_message("CreatureDummy.csv中字段[spawn_x]位置不对应");assert(false); return false; }
		if(vecLine[3]!="spawn_y"){printf_message("CreatureDummy.csv中字段[spawn_y]位置不对应");assert(false); return false; }
		if(vecLine[4]!="spawn_z"){printf_message("CreatureDummy.csv中字段[spawn_z]位置不对应");assert(false); return false; }
		if(vecLine[5]!="move_speed"){printf_message("CreatureDummy.csv中字段[move_speed]位置不对应");assert(false); return false; }
		if(vecLine[6]!="attached_npc_01"){printf_message("CreatureDummy.csv中字段[attached_npc_01]位置不对应");assert(false); return false; }
		if(vecLine[7]!="attached_npc_02"){printf_message("CreatureDummy.csv中字段[attached_npc_02]位置不对应");assert(false); return false; }
		if(vecLine[8]!="attached_npc_03"){printf_message("CreatureDummy.csv中字段[attached_npc_03]位置不对应");assert(false); return false; }
		if(vecLine[9]!="attached_npc_04"){printf_message("CreatureDummy.csv中字段[attached_npc_04]位置不对应");assert(false); return false; }
		if(vecLine[10]!="attached_npc_05"){printf_message("CreatureDummy.csv中字段[attached_npc_05]位置不对应");assert(false); return false; }
		if(vecLine[11]!="waypoint_start"){printf_message("CreatureDummy.csv中字段[waypoint_start]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			CreatureDummyElement	member;
			member.dummy_id=(int)atoi(vecLine[0].c_str());
			member.spawn_map_id=(int)atoi(vecLine[1].c_str());
			member.spawn_x=(float)atof(vecLine[2].c_str());
			member.spawn_y=(float)atof(vecLine[3].c_str());
			member.spawn_z=(float)atof(vecLine[4].c_str());
			member.move_speed=(float)atof(vecLine[5].c_str());
			member.attached_npc_01=(int)atoi(vecLine[6].c_str());
			member.attached_npc_02=(int)atoi(vecLine[7].c_str());
			member.attached_npc_03=(int)atoi(vecLine[8].c_str());
			member.attached_npc_04=(int)atoi(vecLine[9].c_str());
			member.attached_npc_05=(int)atoi(vecLine[10].c_str());
			member.waypoint_start=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.dummy_id] = member;
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
