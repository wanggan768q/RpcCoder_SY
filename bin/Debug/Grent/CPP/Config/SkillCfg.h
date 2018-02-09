#ifndef __SKILL_CONFIG_H
#define __SKILL_CONFIG_H

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


//技能配置数据结构
struct SkillElement
{
	friend class SkillTable;
	int id;                      	//技能ID	1000=战士 2000=盗贼 3000=骑士 4000=猎人 5000=法师 6000=神秘使
	int name_id;                 	//技能名称ID	关联语言表
	string name;                 	//技能名称	仅策划用
	int type;                    	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=事件技能
	int caster_type;             	//技能释放者对象	释放技能的对象类型： 0 = 主角 1 = 怪物
	int is_scene_event;          	//是否是放置类	0：不是 1：是
	int effect_target;           	//技能生效目标 	1=自己 2=敌方单位 4=友方单位 5=自己+友方
	int cast_target;             	//技能施法目标	0=对自己释放 1=对敌人施放 2=对自己&友方释放 3=对目标点释放 4=对面向释放
	int ligic_id;                	//释放的逻辑	0=暂时无效 1=释放Buff 2=召唤小怪
	vector<int> pars;            	//buff参数	buffID 释放逻辑-1，无效 释放逻辑1，伤害 释放逻辑2，延迟伤害 释放逻辑3，治疗 其他ID查看buff表
	int attack_empty;            	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 0=不允许空放 1=允许空放
	int charge_or_interval;      	//伤害段数	在一段时间之内， 释放多少次伤害（BUFF）
	int cooldown_id;             	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	int cooldown_time;           	//冷却的时间	单位：毫秒
	int common_cd_time;          	//公共CD时间	单位：毫秒
	int charge_time;             	//引唱的时间	单位：毫秒
	int channel_time;            	//引导的时间	单位：毫秒
	int attack_type;             	//攻击的类型	0:物理攻击, 1:法术攻击, 2:物理&法术攻击
	float attack_rate;           	//技能伤害系数	0=不计算伤害 1=100
	int attack_value;            	//技能伤害附加	技能伤害附加
	float attack_range;          	//技能释放距离	技能释放距离
	int continuity;              	//是否连续技能	0=非连续技能 1=连续技能
	int next_id;                 	//下一段技能ID	"-1"=没有下一段
	int move_limit;              	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离
	int rang_type;               	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形
	float rang_par1;             	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长
	float rang_par2;             	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽
	int release_type;            	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形
	string resources_release;    	//释放资源	0=-1 1=SkillRangeSector 2=SkillRangeStrip 3=SkillRange 4=SkillRangeCircular 5=SkillRangeLine
	string Resources;            	//动作资源	动作文件
	string resources_name;       	//对应资源	仅策划用
	string icon;                 	//图标资源	图标资源文件
	int summon_monster_amount;   	//召唤的小怪数量	
	vector<int> summon_monster_list1;	//召唤的小怪组1	
	vector<int> summon_monster_list2;	//召唤的小怪组2	
	vector<int> summon_monster_list3;	//召唤的小怪组3	
	int can_break;               	//连击次数	1为是 0为否
	vector<int> repeatedly_skil_list;	//多段技能列表	多段技能列表
	float interval_time;         	//多段技能每次间隔时间	多段技能每次间隔时间
	int max_accumulate;          	//最大积攒	
	int min_accumulate_use;      	//最低积攒使用	最低几个积攒能触发此技能
	int event;                   	//事件	1=格挡 2=暴击 3=命中
	int reduce_cd_type;          	//减少cd类型	1=固定值 2=百分比
	float reduce_cd_parameter;   	//减少cd参数	

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
	SkillElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//技能配置封装类
class SkillTable
{
	friend class TableData;
private:
	SkillTable(){}
	~SkillTable(){}
	typedef unordered_map<int, SkillElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<SkillElement>	m_vecAllElements;
	SkillElement m_emptyItem;
public:
	static SkillTable& Instance()
	{
		static SkillTable sInstance;
		return sInstance;
	}

	const SkillElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("SkillTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillElement>&	GetAllElement()
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
		return LoadJson("Skill.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Skill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Skill.bin", strTableContent ) )
		{
			printf_message("配置文件[Skill.bin]未找到");
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

			SkillElement	member;

						member.id=p.get<int>("id");
			member.name_id=p.get<int>("name_id");
			member.name=p.get<string>("name");
			member.type=p.get<int>("type");
			member.caster_type=p.get<int>("caster_type");
			member.is_scene_event=p.get<int>("is_scene_event");
			member.effect_target=p.get<int>("effect_target");
			member.cast_target=p.get<int>("cast_target");
			member.ligic_id=p.get<int>("ligic_id");
			boost::property_tree::ptree sms_array_childpars = p.get_child("pars");
			for (BOOST_AUTO(pos, sms_array_childpars.begin()); pos != sms_array_childpars.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.pars.push_back(n);
			}
			member.attack_empty=p.get<int>("attack_empty");
			member.charge_or_interval=p.get<int>("charge_or_interval");
			member.cooldown_id=p.get<int>("cooldown_id");
			member.cooldown_time=p.get<int>("cooldown_time");
			member.common_cd_time=p.get<int>("common_cd_time");
			member.charge_time=p.get<int>("charge_time");
			member.channel_time=p.get<int>("channel_time");
			member.attack_type=p.get<int>("attack_type");
			member.attack_rate=p.get<float>("attack_rate");
			member.attack_value=p.get<int>("attack_value");
			member.attack_range=p.get<float>("attack_range");
			member.continuity=p.get<int>("continuity");
			member.next_id=p.get<int>("next_id");
			member.move_limit=p.get<int>("move_limit");
			member.rang_type=p.get<int>("rang_type");
			member.rang_par1=p.get<float>("rang_par1");
			member.rang_par2=p.get<float>("rang_par2");
			member.release_type=p.get<int>("release_type");
			member.resources_release=p.get<string>("resources_release");
			member.Resources=p.get<string>("Resources");
			member.resources_name=p.get<string>("resources_name");
			member.icon=p.get<string>("icon");
			member.summon_monster_amount=p.get<int>("summon_monster_amount");
			boost::property_tree::ptree sms_array_childsummon_monster_list1 = p.get_child("summon_monster_list1");
			for (BOOST_AUTO(pos, sms_array_childsummon_monster_list1.begin()); pos != sms_array_childsummon_monster_list1.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.summon_monster_list1.push_back(n);
			}
			boost::property_tree::ptree sms_array_childsummon_monster_list2 = p.get_child("summon_monster_list2");
			for (BOOST_AUTO(pos, sms_array_childsummon_monster_list2.begin()); pos != sms_array_childsummon_monster_list2.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.summon_monster_list2.push_back(n);
			}
			boost::property_tree::ptree sms_array_childsummon_monster_list3 = p.get_child("summon_monster_list3");
			for (BOOST_AUTO(pos, sms_array_childsummon_monster_list3.begin()); pos != sms_array_childsummon_monster_list3.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.summon_monster_list3.push_back(n);
			}
			member.can_break=p.get<int>("can_break");
			boost::property_tree::ptree sms_array_childrepeatedly_skil_list = p.get_child("repeatedly_skil_list");
			for (BOOST_AUTO(pos, sms_array_childrepeatedly_skil_list.begin()); pos != sms_array_childrepeatedly_skil_list.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.repeatedly_skil_list.push_back(n);
			}
			member.interval_time=p.get<float>("interval_time");
			member.max_accumulate=p.get<int>("max_accumulate");
			member.min_accumulate_use=p.get<int>("min_accumulate_use");
			member.event=p.get<int>("event");
			member.reduce_cd_type=p.get<int>("reduce_cd_type");
			member.reduce_cd_parameter=p.get<float>("reduce_cd_parameter");


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
		if(vecLine.size() != 44)
		{
			printf_message("Skill.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Skill.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name_id"){printf_message("Skill.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("Skill.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("Skill.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="caster_type"){printf_message("Skill.csv中字段[caster_type]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="is_scene_event"){printf_message("Skill.csv中字段[is_scene_event]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="effect_target"){printf_message("Skill.csv中字段[effect_target]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="cast_target"){printf_message("Skill.csv中字段[cast_target]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="ligic_id"){printf_message("Skill.csv中字段[ligic_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="pars"){printf_message("Skill.csv中字段[pars]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="attack_empty"){printf_message("Skill.csv中字段[attack_empty]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="charge_or_interval"){printf_message("Skill.csv中字段[charge_or_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="cooldown_id"){printf_message("Skill.csv中字段[cooldown_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="cooldown_time"){printf_message("Skill.csv中字段[cooldown_time]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="common_cd_time"){printf_message("Skill.csv中字段[common_cd_time]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="charge_time"){printf_message("Skill.csv中字段[charge_time]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="channel_time"){printf_message("Skill.csv中字段[channel_time]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="attack_type"){printf_message("Skill.csv中字段[attack_type]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="attack_rate"){printf_message("Skill.csv中字段[attack_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="attack_value"){printf_message("Skill.csv中字段[attack_value]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="attack_range"){printf_message("Skill.csv中字段[attack_range]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="continuity"){printf_message("Skill.csv中字段[continuity]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="next_id"){printf_message("Skill.csv中字段[next_id]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="move_limit"){printf_message("Skill.csv中字段[move_limit]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="rang_type"){printf_message("Skill.csv中字段[rang_type]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="rang_par1"){printf_message("Skill.csv中字段[rang_par1]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="rang_par2"){printf_message("Skill.csv中字段[rang_par2]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="release_type"){printf_message("Skill.csv中字段[release_type]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="resources_release"){printf_message("Skill.csv中字段[resources_release]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="Resources"){printf_message("Skill.csv中字段[Resources]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="resources_name"){printf_message("Skill.csv中字段[resources_name]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="icon"){printf_message("Skill.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="summon_monster_amount"){printf_message("Skill.csv中字段[summon_monster_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="summon_monster_list1"){printf_message("Skill.csv中字段[summon_monster_list1]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="summon_monster_list2"){printf_message("Skill.csv中字段[summon_monster_list2]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="summon_monster_list3"){printf_message("Skill.csv中字段[summon_monster_list3]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="can_break"){printf_message("Skill.csv中字段[can_break]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="repeatedly_skil_list"){printf_message("Skill.csv中字段[repeatedly_skil_list]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="interval_time"){printf_message("Skill.csv中字段[interval_time]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="max_accumulate"){printf_message("Skill.csv中字段[max_accumulate]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="min_accumulate_use"){printf_message("Skill.csv中字段[min_accumulate_use]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="event"){printf_message("Skill.csv中字段[event]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="reduce_cd_type"){printf_message("Skill.csv中字段[reduce_cd_type]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){printf_message("Skill.csv中字段[reduce_cd_parameter]位置不对应 ");assert(false); return false; }

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
			SkillElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name_id=(int)atoi(vecLine[1].c_str());
			member.name=vecLine[2];
			member.type=(int)atoi(vecLine[3].c_str());
			member.caster_type=(int)atoi(vecLine[4].c_str());
			member.is_scene_event=(int)atoi(vecLine[5].c_str());
			member.effect_target=(int)atoi(vecLine[6].c_str());
			member.cast_target=(int)atoi(vecLine[7].c_str());
			member.ligic_id=(int)atoi(vecLine[8].c_str());
			member.attack_empty=(int)atoi(vecLine[10].c_str());
			member.charge_or_interval=(int)atoi(vecLine[11].c_str());
			member.cooldown_id=(int)atoi(vecLine[12].c_str());
			member.cooldown_time=(int)atoi(vecLine[13].c_str());
			member.common_cd_time=(int)atoi(vecLine[14].c_str());
			member.charge_time=(int)atoi(vecLine[15].c_str());
			member.channel_time=(int)atoi(vecLine[16].c_str());
			member.attack_type=(int)atoi(vecLine[17].c_str());
			member.attack_rate=(float)atof(vecLine[18].c_str());
			member.attack_value=(int)atoi(vecLine[19].c_str());
			member.attack_range=(float)atof(vecLine[20].c_str());
			member.continuity=(int)atoi(vecLine[21].c_str());
			member.next_id=(int)atoi(vecLine[22].c_str());
			member.move_limit=(int)atoi(vecLine[23].c_str());
			member.rang_type=(int)atoi(vecLine[24].c_str());
			member.rang_par1=(float)atof(vecLine[25].c_str());
			member.rang_par2=(float)atof(vecLine[26].c_str());
			member.release_type=(int)atoi(vecLine[27].c_str());
			member.resources_release=vecLine[28];
			member.Resources=vecLine[29];
			member.resources_name=vecLine[30];
			member.icon=vecLine[31];
			member.summon_monster_amount=(int)atoi(vecLine[32].c_str());
			member.can_break=(int)atoi(vecLine[36].c_str());
			member.interval_time=(float)atof(vecLine[38].c_str());
			member.max_accumulate=(int)atoi(vecLine[39].c_str());
			member.min_accumulate_use=(int)atoi(vecLine[40].c_str());
			member.event=(int)atoi(vecLine[41].c_str());
			member.reduce_cd_type=(int)atoi(vecLine[42].c_str());
			member.reduce_cd_parameter=(float)atof(vecLine[43].c_str());

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
