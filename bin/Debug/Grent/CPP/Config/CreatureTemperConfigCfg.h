#ifndef __CREATURETEMPERCONFIG_CONFIG_H
#define __CREATURETEMPERCONFIG_CONFIG_H

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


//NPC行为参数配置数据结构
struct CreatureTemperConfigElement
{
	friend class CreatureTemperConfigTable;
	int ai_style;                	//性格ID	关联Creature
	string remark;               	//备注	仅策划用
	int search_style;            	// 索敌类型	0=范围索敌 1=全图索敌
	int hatred_range;            	//仇恨清除半径	大于该距离清除0仇恨角色 单位：米 “-1”=无限距离
	float search_distance;       	//锁敌距离	单位：米
	int chase_type;              	//追敌类型	0=范围追敌 1=全图追敌
	int chase_distance;          	//追击距离	单位：米
	int chase_time;              	//回归时间	单位：毫秒
	float chase_speed;           	//回归加速度	单位：米/秒
	float patrol_range;          	//巡逻范围	单位：米
	int patrol_interval;         	//巡逻间隔	单位：毫秒
	float harass_range;          	//绕敌圈半径	单位：米
	int harass_probability1;     	//在绕敌圈内绕敌几率	10000=%100
	int harass_probability2;     	//在绕地圈外绕敌几率	10000=%100
	float harass_distance;       	// 绕敌半径	单位：米
	float harass_angle;          	// 绕敌角度	单位：度
	int harass_timeout;          	// 绕敌超时时间	单位：毫秒
	float cd_chase_dist;         	//技能cd时追敌距离	停止在拒敌x米处
	float harass_speed;          	//加速绕敌速度	单位：米/秒

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
	CreatureTemperConfigElement()
	{
		ai_style = -1;
		m_bIsValidate=false;
	}
};

//NPC行为参数配置封装类
class CreatureTemperConfigTable
{
	friend class TableData;
private:
	CreatureTemperConfigTable(){}
	~CreatureTemperConfigTable(){}
	typedef unordered_map<int, CreatureTemperConfigElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<CreatureTemperConfigElement>	m_vecAllElements;
	CreatureTemperConfigElement m_emptyItem;
public:
	static CreatureTemperConfigTable& Instance()
	{
		static CreatureTemperConfigTable sInstance;
		return sInstance;
	}

	const CreatureTemperConfigElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("CreatureTemperConfigTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureTemperConfigElement>&	GetAllElement()
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
		return LoadJson("CreatureTemperConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreatureTemperConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureTemperConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureTemperConfig.bin]未找到");
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

			CreatureTemperConfigElement	member;

						member.ai_style=p.get<int>("ai_style");
			member.remark=p.get<string>("remark");
			member.search_style=p.get<int>("search_style");
			member.hatred_range=p.get<int>("hatred_range");
			member.search_distance=p.get<float>("search_distance");
			member.chase_type=p.get<int>("chase_type");
			member.chase_distance=p.get<int>("chase_distance");
			member.chase_time=p.get<int>("chase_time");
			member.chase_speed=p.get<float>("chase_speed");
			member.patrol_range=p.get<float>("patrol_range");
			member.patrol_interval=p.get<int>("patrol_interval");
			member.harass_range=p.get<float>("harass_range");
			member.harass_probability1=p.get<int>("harass_probability1");
			member.harass_probability2=p.get<int>("harass_probability2");
			member.harass_distance=p.get<float>("harass_distance");
			member.harass_angle=p.get<float>("harass_angle");
			member.harass_timeout=p.get<int>("harass_timeout");
			member.cd_chase_dist=p.get<float>("cd_chase_dist");
			member.harass_speed=p.get<float>("harass_speed");


			member.SetIsValidate(true);
			m_mapElements[member.ai_style] = member;
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
		if(vecLine.size() != 19)
		{
			printf_message("CreatureTemperConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ai_style"){printf_message("CreatureTemperConfig.csv中字段[ai_style]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="remark"){printf_message("CreatureTemperConfig.csv中字段[remark]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="search_style"){printf_message("CreatureTemperConfig.csv中字段[search_style]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="hatred_range"){printf_message("CreatureTemperConfig.csv中字段[hatred_range]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="search_distance"){printf_message("CreatureTemperConfig.csv中字段[search_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="chase_type"){printf_message("CreatureTemperConfig.csv中字段[chase_type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="chase_distance"){printf_message("CreatureTemperConfig.csv中字段[chase_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="chase_time"){printf_message("CreatureTemperConfig.csv中字段[chase_time]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="chase_speed"){printf_message("CreatureTemperConfig.csv中字段[chase_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="patrol_range"){printf_message("CreatureTemperConfig.csv中字段[patrol_range]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="patrol_interval"){printf_message("CreatureTemperConfig.csv中字段[patrol_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="harass_range"){printf_message("CreatureTemperConfig.csv中字段[harass_range]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="harass_probability1"){printf_message("CreatureTemperConfig.csv中字段[harass_probability1]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="harass_probability2"){printf_message("CreatureTemperConfig.csv中字段[harass_probability2]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="harass_distance"){printf_message("CreatureTemperConfig.csv中字段[harass_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="harass_angle"){printf_message("CreatureTemperConfig.csv中字段[harass_angle]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="harass_timeout"){printf_message("CreatureTemperConfig.csv中字段[harass_timeout]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="cd_chase_dist"){printf_message("CreatureTemperConfig.csv中字段[cd_chase_dist]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="harass_speed"){printf_message("CreatureTemperConfig.csv中字段[harass_speed]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)19)
			{
				assert(false);
				return false;
			}
			CreatureTemperConfigElement	member;
			member.ai_style=(int)atoi(vecLine[0].c_str());
			member.remark=vecLine[1];
			member.search_style=(int)atoi(vecLine[2].c_str());
			member.hatred_range=(int)atoi(vecLine[3].c_str());
			member.search_distance=(float)atof(vecLine[4].c_str());
			member.chase_type=(int)atoi(vecLine[5].c_str());
			member.chase_distance=(int)atoi(vecLine[6].c_str());
			member.chase_time=(int)atoi(vecLine[7].c_str());
			member.chase_speed=(float)atof(vecLine[8].c_str());
			member.patrol_range=(float)atof(vecLine[9].c_str());
			member.patrol_interval=(int)atoi(vecLine[10].c_str());
			member.harass_range=(float)atof(vecLine[11].c_str());
			member.harass_probability1=(int)atoi(vecLine[12].c_str());
			member.harass_probability2=(int)atoi(vecLine[13].c_str());
			member.harass_distance=(float)atof(vecLine[14].c_str());
			member.harass_angle=(float)atof(vecLine[15].c_str());
			member.harass_timeout=(int)atoi(vecLine[16].c_str());
			member.cd_chase_dist=(float)atof(vecLine[17].c_str());
			member.harass_speed=(float)atof(vecLine[18].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ai_style] = member;
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
