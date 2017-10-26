#ifndef __WAYPOINT_CONFIG_H
#define __WAYPOINT_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//路点表配置数据结构
struct WayPointElement
{
	friend class WayPointTable;
	int waypoint_id;             	//路点ID	路点ID
	int  spawn_map_id;           	//路点所在的场景号	路点所在的场景号
	float spawn_x;               	//路点所处的场景的X坐标	路点所处的场景的X坐标
	float spawn_y;               	//路点所处的场景的Y坐标	路点所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	int waypoint_next_id;        	//下一个路点ID	下一个路点ID
	string waypoint_animation;   	//到达路点后播放的动画路径	到达路点后播放的动画路径
	int waypoint_delay;          	//到达路点后停留的时间	到达路点后停留的时间

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
	WayPointElement()
	{
		waypoint_id = -1;
		m_bIsValidate=false;
	}
};

//路点表配置封装类
class WayPointTable
{
	friend class TableData;
private:
	WayPointTable(){}
	~WayPointTable(){}
	map<int, WayPointElement>	m_mapElements;
	vector<WayPointElement>	m_vecAllElements;
	WayPointElement m_emptyItem;
public:
	static WayPointTable& Instance()
	{
		static WayPointTable sInstance;
		return sInstance;
	}

	WayPointElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<WayPointElement>&	GetAllElement()
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
		return LoadJson("WayPoint.json");
		#else
		string strTableContent;
		if( LoadConfigContent("WayPoint.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("WayPoint.bin", strTableContent ) )
		{
			printf_message("配置文件[WayPoint.bin]未找到");
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

			WayPointElement	member;

						member.waypoint_id=p.get<int>("waypoint_id");
			member. spawn_map_id=p.get<int>(" spawn_map_id");
			member.spawn_x=p.get<float>("spawn_x");
			member.spawn_y=p.get<float>("spawn_y");
			member.spawn_z=p.get<float>("spawn_z");
			member.waypoint_next_id=p.get<int>("waypoint_next_id");
			member.waypoint_animation=p.get<string>("waypoint_animation");
			member.waypoint_delay=p.get<int>("waypoint_delay");


			member.SetIsValidate(true);
			m_mapElements[member.waypoint_id] = member;
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
			printf_message("WayPoint.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="waypoint_id"){printf_message("WayPoint.csv中字段[waypoint_id]位置不对应");assert(false); return false; }
		if(vecLine[1]!=" spawn_map_id"){printf_message("WayPoint.csv中字段[ spawn_map_id]位置不对应");assert(false); return false; }
		if(vecLine[2]!="spawn_x"){printf_message("WayPoint.csv中字段[spawn_x]位置不对应");assert(false); return false; }
		if(vecLine[3]!="spawn_y"){printf_message("WayPoint.csv中字段[spawn_y]位置不对应");assert(false); return false; }
		if(vecLine[4]!="spawn_z"){printf_message("WayPoint.csv中字段[spawn_z]位置不对应");assert(false); return false; }
		if(vecLine[5]!="waypoint_next_id"){printf_message("WayPoint.csv中字段[waypoint_next_id]位置不对应");assert(false); return false; }
		if(vecLine[6]!="waypoint_animation"){printf_message("WayPoint.csv中字段[waypoint_animation]位置不对应");assert(false); return false; }
		if(vecLine[7]!="waypoint_delay"){printf_message("WayPoint.csv中字段[waypoint_delay]位置不对应");assert(false); return false; }

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
			WayPointElement	member;
			member.waypoint_id=(int)atoi(vecLine[0].c_str());
			member. spawn_map_id=(int)atoi(vecLine[1].c_str());
			member.spawn_x=(float)atof(vecLine[2].c_str());
			member.spawn_y=(float)atof(vecLine[3].c_str());
			member.spawn_z=(float)atof(vecLine[4].c_str());
			member.waypoint_next_id=(int)atoi(vecLine[5].c_str());
			member.waypoint_animation=vecLine[6];
			member.waypoint_delay=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.waypoint_id] = member;
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
