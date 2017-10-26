#ifndef __CREATURE_CONFIG_H
#define __CREATURE_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//总NPC表配置数据结构
struct CreatureElement
{
	friend class CreatureTable;
	int entry_id;                	//序号	序号
	int combat_coe_id;           	//战斗系数ID	战斗系数ID
	string gd_comment;           	//策划备注	策划备注
	int name_id;                 	//名字文本ID	名字文本ID
	int sub_name_id;             	//子名字文本ID	子名字文本ID
	string model_path;           	//模型路径	模型路径
	string mapping_path;         	//贴图路径	贴图路径
	float scale;                 	//NPC大小	NPC大小
	float opacity;               	//透明度	透明度
	string icon;                 	//图标路径	图标路径
	int health_bar_display;      	//血条显示	血条显示
	int name_bar_display;        	//名字显示	名字显示
	int creature_level;          	//怪物等级	怪物等级
	int creature_type;           	//怪物类型	怪物类型
	int faction;                 	//阵营	阵营
	int race;                    	//种族	种族
	float boundary_length;       	//包围盒底部长度	包围盒底部长度
	float boundary_width;        	//包围盒底部宽度	包围盒底部宽度
	float boundary_height;       	//包围盒高度	包围盒高度
	float walk_speed;            	//走路速度	走路速度
	float run_speed;             	//跑步速度	跑步速度
	string script_location;      	//脚本路径	脚本路径
	int can_be_targeted;         	//是否可以被攻击或选中	是否可以被攻击或选中
	int can_attack;              	//是否可以进行攻击	是否可以进行攻击
	int pool_skill_num;          	//从技能池里随机出来的数量	从技能池里随机出来的数量
	string selected_sound;       	//被选中音效	被选中音效
	string death_sound;          	//死亡音效	死亡音效

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
	CreatureElement()
	{
		entry_id = -1;
		m_bIsValidate=false;
	}
};

//总NPC表配置封装类
class CreatureTable
{
	friend class TableData;
private:
	CreatureTable(){}
	~CreatureTable(){}
	map<int, CreatureElement>	m_mapElements;
	vector<CreatureElement>	m_vecAllElements;
	CreatureElement m_emptyItem;
public:
	static CreatureTable& Instance()
	{
		static CreatureTable sInstance;
		return sInstance;
	}

	CreatureElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureElement>&	GetAllElement()
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
		return LoadJson("Creature.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Creature.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Creature.bin", strTableContent ) )
		{
			printf_message("配置文件[Creature.bin]未找到");
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

			CreatureElement	member;

						member.entry_id=p.get<int>("entry_id");
			member.combat_coe_id=p.get<int>("combat_coe_id");
			member.gd_comment=p.get<string>("gd_comment");
			member.name_id=p.get<int>("name_id");
			member.sub_name_id=p.get<int>("sub_name_id");
			member.model_path=p.get<string>("model_path");
			member.mapping_path=p.get<string>("mapping_path");
			member.scale=p.get<float>("scale");
			member.opacity=p.get<float>("opacity");
			member.icon=p.get<string>("icon");
			member.health_bar_display=p.get<int>("health_bar_display");
			member.name_bar_display=p.get<int>("name_bar_display");
			member.creature_level=p.get<int>("creature_level");
			member.creature_type=p.get<int>("creature_type");
			member.faction=p.get<int>("faction");
			member.race=p.get<int>("race");
			member.boundary_length=p.get<float>("boundary_length");
			member.boundary_width=p.get<float>("boundary_width");
			member.boundary_height=p.get<float>("boundary_height");
			member.walk_speed=p.get<float>("walk_speed");
			member.run_speed=p.get<float>("run_speed");
			member.script_location=p.get<string>("script_location");
			member.can_be_targeted=p.get<int>("can_be_targeted");
			member.can_attack=p.get<int>("can_attack");
			member.pool_skill_num=p.get<int>("pool_skill_num");
			member.selected_sound=p.get<string>("selected_sound");
			member.death_sound=p.get<string>("death_sound");


			member.SetIsValidate(true);
			m_mapElements[member.entry_id] = member;
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
		if(vecLine.size() != 27)
		{
			printf_message("Creature.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="entry_id"){printf_message("Creature.csv中字段[entry_id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="combat_coe_id"){printf_message("Creature.csv中字段[combat_coe_id]位置不对应");assert(false); return false; }
		if(vecLine[2]!="gd_comment"){printf_message("Creature.csv中字段[gd_comment]位置不对应");assert(false); return false; }
		if(vecLine[3]!="name_id"){printf_message("Creature.csv中字段[name_id]位置不对应");assert(false); return false; }
		if(vecLine[4]!="sub_name_id"){printf_message("Creature.csv中字段[sub_name_id]位置不对应");assert(false); return false; }
		if(vecLine[5]!="model_path"){printf_message("Creature.csv中字段[model_path]位置不对应");assert(false); return false; }
		if(vecLine[6]!="mapping_path"){printf_message("Creature.csv中字段[mapping_path]位置不对应");assert(false); return false; }
		if(vecLine[7]!="scale"){printf_message("Creature.csv中字段[scale]位置不对应");assert(false); return false; }
		if(vecLine[8]!="opacity"){printf_message("Creature.csv中字段[opacity]位置不对应");assert(false); return false; }
		if(vecLine[9]!="icon"){printf_message("Creature.csv中字段[icon]位置不对应");assert(false); return false; }
		if(vecLine[10]!="health_bar_display"){printf_message("Creature.csv中字段[health_bar_display]位置不对应");assert(false); return false; }
		if(vecLine[11]!="name_bar_display"){printf_message("Creature.csv中字段[name_bar_display]位置不对应");assert(false); return false; }
		if(vecLine[12]!="creature_level"){printf_message("Creature.csv中字段[creature_level]位置不对应");assert(false); return false; }
		if(vecLine[13]!="creature_type"){printf_message("Creature.csv中字段[creature_type]位置不对应");assert(false); return false; }
		if(vecLine[14]!="faction"){printf_message("Creature.csv中字段[faction]位置不对应");assert(false); return false; }
		if(vecLine[15]!="race"){printf_message("Creature.csv中字段[race]位置不对应");assert(false); return false; }
		if(vecLine[16]!="boundary_length"){printf_message("Creature.csv中字段[boundary_length]位置不对应");assert(false); return false; }
		if(vecLine[17]!="boundary_width"){printf_message("Creature.csv中字段[boundary_width]位置不对应");assert(false); return false; }
		if(vecLine[18]!="boundary_height"){printf_message("Creature.csv中字段[boundary_height]位置不对应");assert(false); return false; }
		if(vecLine[19]!="walk_speed"){printf_message("Creature.csv中字段[walk_speed]位置不对应");assert(false); return false; }
		if(vecLine[20]!="run_speed"){printf_message("Creature.csv中字段[run_speed]位置不对应");assert(false); return false; }
		if(vecLine[21]!="script_location"){printf_message("Creature.csv中字段[script_location]位置不对应");assert(false); return false; }
		if(vecLine[22]!="can_be_targeted"){printf_message("Creature.csv中字段[can_be_targeted]位置不对应");assert(false); return false; }
		if(vecLine[23]!="can_attack"){printf_message("Creature.csv中字段[can_attack]位置不对应");assert(false); return false; }
		if(vecLine[24]!="pool_skill_num"){printf_message("Creature.csv中字段[pool_skill_num]位置不对应");assert(false); return false; }
		if(vecLine[25]!="selected_sound"){printf_message("Creature.csv中字段[selected_sound]位置不对应");assert(false); return false; }
		if(vecLine[26]!="death_sound"){printf_message("Creature.csv中字段[death_sound]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)27)
			{
				assert(false);
				return false;
			}
			CreatureElement	member;
			member.entry_id=(int)atoi(vecLine[0].c_str());
			member.combat_coe_id=(int)atoi(vecLine[1].c_str());
			member.gd_comment=vecLine[2];
			member.name_id=(int)atoi(vecLine[3].c_str());
			member.sub_name_id=(int)atoi(vecLine[4].c_str());
			member.model_path=vecLine[5];
			member.mapping_path=vecLine[6];
			member.scale=(float)atof(vecLine[7].c_str());
			member.opacity=(float)atof(vecLine[8].c_str());
			member.icon=vecLine[9];
			member.health_bar_display=(int)atoi(vecLine[10].c_str());
			member.name_bar_display=(int)atoi(vecLine[11].c_str());
			member.creature_level=(int)atoi(vecLine[12].c_str());
			member.creature_type=(int)atoi(vecLine[13].c_str());
			member.faction=(int)atoi(vecLine[14].c_str());
			member.race=(int)atoi(vecLine[15].c_str());
			member.boundary_length=(float)atof(vecLine[16].c_str());
			member.boundary_width=(float)atof(vecLine[17].c_str());
			member.boundary_height=(float)atof(vecLine[18].c_str());
			member.walk_speed=(float)atof(vecLine[19].c_str());
			member.run_speed=(float)atof(vecLine[20].c_str());
			member.script_location=vecLine[21];
			member.can_be_targeted=(int)atoi(vecLine[22].c_str());
			member.can_attack=(int)atoi(vecLine[23].c_str());
			member.pool_skill_num=(int)atoi(vecLine[24].c_str());
			member.selected_sound=vecLine[25];
			member.death_sound=vecLine[26];

			member.SetIsValidate(true);
			m_mapElements[member.entry_id] = member;
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
