#ifndef __CREATURE_CONFIG_H
#define __CREATURE_CONFIG_H

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


//总NPC表配置数据结构
struct CreatureElement
{
	friend class CreatureTable;
	int entry_id;                	//序号	序号
	int script_ID;               	//脚本ID	脚本ID填写为NPC的ID -1为没有脚本
	int combat_coe_id;           	//战斗系数ID	战斗系数ID
	int combat_attributes_id;    	//战斗属性ID	战斗属性ID
	int temper_id;               	//AI类型ID	关联 CreatureTemperConfig
	string gd_comment;           	//策划备注	策划备注
	int name_id;                 	//名字文本ID	名字文本ID
	int sub_name_id;             	//子名字文本ID	子名字文本ID
	int model_id;                	//模型id	模型id
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
	int can_be_targeted;         	//是否可以被攻击或选中	是否可以被攻击或选中
	int can_attack;              	//是否可以进行攻击	是否可以进行攻击
	int pool_skill_num;          	//从技能池里随机出来的数量	从技能池里随机出来的数量
	string selected_sound;       	//被选中音效	被选中音效
	string death_sound;          	//死亡音效	死亡音效
	vector<int> initial_skill;   	//NPC的技能数组	关联之后的技能，如果没有技能则不填
	int skill_1;                 	//技能1	仅策划用
	int skill_2;                 	//技能2	仅策划用
	int skill_3;                 	//技能3	仅策划用
	int skill_4;                 	//技能4	仅策划用
	int skill_5;                 	//技能5	仅策划用
	vector<int> rebirth_buffs;   	//出生的时候释放buff	出生的时候释放buff
	string verification;         	//技能验证	仅策划用 二进制检验
	int is_wondering;            	//是否在范围内漫步	是否在范围内漫步
	int is_play_born_animation;  	//是否需要播放出生动画	是否需要播放出生动画
	int born_anim_duration_buff; 	//出生动画持续时的效果buff ID	出生动画持续时的效果buff ID
	int born_anim_effect_buff;   	//出生动画持续时的时长buff ID	出生动画持续时的时长buff ID
	string born_animation_name;  	//出生动画名称	出生动画名称
	string combat_entry_skill;   	//进入战斗的技能	进入战斗的技能
	int corpse_vanish_time;      	//尸体消失时间	尸体消失时间

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
	typedef unordered_map<int, CreatureElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<CreatureElement>	m_vecAllElements;
	CreatureElement m_emptyItem;
public:
	static CreatureTable& Instance()
	{
		static CreatureTable sInstance;
		return sInstance;
	}

	const CreatureElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("CreatureTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
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
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CreatureElement	member;

						member.entry_id=p.get<int>("entry_id");
			member.script_ID=p.get<int>("script_ID");
			member.combat_coe_id=p.get<int>("combat_coe_id");
			member.combat_attributes_id=p.get<int>("combat_attributes_id");
			member.temper_id=p.get<int>("temper_id");
			member.gd_comment=p.get<string>("gd_comment");
			member.name_id=p.get<int>("name_id");
			member.sub_name_id=p.get<int>("sub_name_id");
			member.model_id=p.get<int>("model_id");
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
			member.can_be_targeted=p.get<int>("can_be_targeted");
			member.can_attack=p.get<int>("can_attack");
			member.pool_skill_num=p.get<int>("pool_skill_num");
			member.selected_sound=p.get<string>("selected_sound");
			member.death_sound=p.get<string>("death_sound");
			boost::property_tree::ptree sms_array_childinitial_skill = p.get_child("initial_skill");
			for (BOOST_AUTO(pos, sms_array_childinitial_skill.begin()); pos != sms_array_childinitial_skill.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.initial_skill.push_back(n);
			}
			member.skill_1=p.get<int>("skill_1");
			member.skill_2=p.get<int>("skill_2");
			member.skill_3=p.get<int>("skill_3");
			member.skill_4=p.get<int>("skill_4");
			member.skill_5=p.get<int>("skill_5");
			boost::property_tree::ptree sms_array_childrebirth_buffs = p.get_child("rebirth_buffs");
			for (BOOST_AUTO(pos, sms_array_childrebirth_buffs.begin()); pos != sms_array_childrebirth_buffs.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.rebirth_buffs.push_back(n);
			}
			member.verification=p.get<string>("verification");
			member.is_wondering=p.get<int>("is_wondering");
			member.is_play_born_animation=p.get<int>("is_play_born_animation");
			member.born_anim_duration_buff=p.get<int>("born_anim_duration_buff");
			member.born_anim_effect_buff=p.get<int>("born_anim_effect_buff");
			member.born_animation_name=p.get<string>("born_animation_name");
			member.combat_entry_skill=p.get<string>("combat_entry_skill");
			member.corpse_vanish_time=p.get<int>("corpse_vanish_time");


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
		if(vecLine.size() != 44)
		{
			printf_message("Creature.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="entry_id"){printf_message("Creature.csv中字段[entry_id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="script_ID"){printf_message("Creature.csv中字段[script_ID]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="combat_coe_id"){printf_message("Creature.csv中字段[combat_coe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="combat_attributes_id"){printf_message("Creature.csv中字段[combat_attributes_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="temper_id"){printf_message("Creature.csv中字段[temper_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="gd_comment"){printf_message("Creature.csv中字段[gd_comment]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="name_id"){printf_message("Creature.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="sub_name_id"){printf_message("Creature.csv中字段[sub_name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="model_id"){printf_message("Creature.csv中字段[model_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="mapping_path"){printf_message("Creature.csv中字段[mapping_path]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="scale"){printf_message("Creature.csv中字段[scale]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="opacity"){printf_message("Creature.csv中字段[opacity]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="icon"){printf_message("Creature.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="health_bar_display"){printf_message("Creature.csv中字段[health_bar_display]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="name_bar_display"){printf_message("Creature.csv中字段[name_bar_display]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="creature_level"){printf_message("Creature.csv中字段[creature_level]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="creature_type"){printf_message("Creature.csv中字段[creature_type]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="faction"){printf_message("Creature.csv中字段[faction]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="race"){printf_message("Creature.csv中字段[race]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="boundary_length"){printf_message("Creature.csv中字段[boundary_length]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="boundary_width"){printf_message("Creature.csv中字段[boundary_width]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="boundary_height"){printf_message("Creature.csv中字段[boundary_height]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="walk_speed"){printf_message("Creature.csv中字段[walk_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="run_speed"){printf_message("Creature.csv中字段[run_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="can_be_targeted"){printf_message("Creature.csv中字段[can_be_targeted]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="can_attack"){printf_message("Creature.csv中字段[can_attack]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="pool_skill_num"){printf_message("Creature.csv中字段[pool_skill_num]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="selected_sound"){printf_message("Creature.csv中字段[selected_sound]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="death_sound"){printf_message("Creature.csv中字段[death_sound]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="initial_skill"){printf_message("Creature.csv中字段[initial_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="skill_1"){printf_message("Creature.csv中字段[skill_1]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="skill_2"){printf_message("Creature.csv中字段[skill_2]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="skill_3"){printf_message("Creature.csv中字段[skill_3]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="skill_4"){printf_message("Creature.csv中字段[skill_4]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="skill_5"){printf_message("Creature.csv中字段[skill_5]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="rebirth_buffs"){printf_message("Creature.csv中字段[rebirth_buffs]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="verification"){printf_message("Creature.csv中字段[verification]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="is_wondering"){printf_message("Creature.csv中字段[is_wondering]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="is_play_born_animation"){printf_message("Creature.csv中字段[is_play_born_animation]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="born_anim_duration_buff"){printf_message("Creature.csv中字段[born_anim_duration_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="born_anim_effect_buff"){printf_message("Creature.csv中字段[born_anim_effect_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="born_animation_name"){printf_message("Creature.csv中字段[born_animation_name]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="combat_entry_skill"){printf_message("Creature.csv中字段[combat_entry_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="corpse_vanish_time"){printf_message("Creature.csv中字段[corpse_vanish_time]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)44)
			{
				assert(false);
				return false;
			}
			CreatureElement	member;
			member.entry_id=(int)atoi(vecLine[0].c_str());
			member.script_ID=(int)atoi(vecLine[1].c_str());
			member.combat_coe_id=(int)atoi(vecLine[2].c_str());
			member.combat_attributes_id=(int)atoi(vecLine[3].c_str());
			member.temper_id=(int)atoi(vecLine[4].c_str());
			member.gd_comment=vecLine[5];
			member.name_id=(int)atoi(vecLine[6].c_str());
			member.sub_name_id=(int)atoi(vecLine[7].c_str());
			member.model_id=(int)atoi(vecLine[8].c_str());
			member.mapping_path=vecLine[9];
			member.scale=(float)atof(vecLine[10].c_str());
			member.opacity=(float)atof(vecLine[11].c_str());
			member.icon=vecLine[12];
			member.health_bar_display=(int)atoi(vecLine[13].c_str());
			member.name_bar_display=(int)atoi(vecLine[14].c_str());
			member.creature_level=(int)atoi(vecLine[15].c_str());
			member.creature_type=(int)atoi(vecLine[16].c_str());
			member.faction=(int)atoi(vecLine[17].c_str());
			member.race=(int)atoi(vecLine[18].c_str());
			member.boundary_length=(float)atof(vecLine[19].c_str());
			member.boundary_width=(float)atof(vecLine[20].c_str());
			member.boundary_height=(float)atof(vecLine[21].c_str());
			member.walk_speed=(float)atof(vecLine[22].c_str());
			member.run_speed=(float)atof(vecLine[23].c_str());
			member.can_be_targeted=(int)atoi(vecLine[24].c_str());
			member.can_attack=(int)atoi(vecLine[25].c_str());
			member.pool_skill_num=(int)atoi(vecLine[26].c_str());
			member.selected_sound=vecLine[27];
			member.death_sound=vecLine[28];
			member.skill_1=(int)atoi(vecLine[30].c_str());
			member.skill_2=(int)atoi(vecLine[31].c_str());
			member.skill_3=(int)atoi(vecLine[32].c_str());
			member.skill_4=(int)atoi(vecLine[33].c_str());
			member.skill_5=(int)atoi(vecLine[34].c_str());
			member.verification=vecLine[36];
			member.is_wondering=(int)atoi(vecLine[37].c_str());
			member.is_play_born_animation=(int)atoi(vecLine[38].c_str());
			member.born_anim_duration_buff=(int)atoi(vecLine[39].c_str());
			member.born_anim_effect_buff=(int)atoi(vecLine[40].c_str());
			member.born_animation_name=vecLine[41];
			member.combat_entry_skill=vecLine[42];
			member.corpse_vanish_time=(int)atoi(vecLine[43].c_str());

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
