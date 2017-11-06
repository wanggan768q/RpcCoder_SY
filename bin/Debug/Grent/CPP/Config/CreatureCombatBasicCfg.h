#ifndef __CREATURECOMBATBASIC_CONFIG_H
#define __CREATURECOMBATBASIC_CONFIG_H

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


//NPC战斗属性表配置数据结构
struct CreatureCombatBasicElement
{
	friend class CreatureCombatBasicTable;
	int id;                      	//ID号	模板类*1000+等级 模板关联CreatureCombatCoe; 等级关联Creature
	string note;                 	//中文注释	中文注释
	int hp_min;                  	//生命下限	生命下限
	int hp_max;                  	//生命上限	生命上限
	int p_atk_min;               	//物理攻击力下限	物理攻击力下限
	int p_atk_max;               	//物理攻击力上限	物理攻击力上限
	int p_def;                   	//物理防御力	物理防御力
	int s_atk_min;               	//魔法攻击力下限	魔法攻击力下限
	int s_atk_max;               	//魔法攻击力上限	魔法攻击力上限
	int s_def;                   	//魔法防御力	魔法防御力
	int hit_value;               	//命中值	命中值
	int dodge_value;             	//闪避值	闪避值
	int crit_value;              	//暴击值	暴击值
	int resilience_value;        	//韧性值	韧性值
	int penetrate_value;         	//穿透值	穿透值
	int block_value;             	//格挡值	格挡值
	float life_per_sec;          	//生命恢复速度	生命恢复速度
	float life_steal_chance;     	//生命偷取几率	生命偷取几率
	float life_steal_rate;       	//生命偷取比例	生命偷取比例
	float thorns_chance;         	//反弹率	反弹率
	int thorns_amount;           	//反弹值	反弹值
	int exp;                     	//经验值	经验值
	float knockback_res;         	//击退抵抗率	击退抵抗率
	float hit;                   	//命中率	命中率
	float dodge;                 	//闪避率	闪避率
	float crit;                  	//暴击率	暴击率
	float resilience;            	//韧性	韧性
	float penetrate;             	//穿透率	穿透率
	float block;                 	//格挡率	格挡率
	float crit_dmg;              	//暴击伤害	暴击伤害
	float crit_res;              	//暴击抵抗	暴击抵抗

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
	CreatureCombatBasicElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC战斗属性表配置封装类
class CreatureCombatBasicTable
{
	friend class TableData;
private:
	CreatureCombatBasicTable(){}
	~CreatureCombatBasicTable(){}
	unordered_map<int, CreatureCombatBasicElement>	m_mapElements;
	vector<CreatureCombatBasicElement>	m_vecAllElements;
	CreatureCombatBasicElement m_emptyItem;
public:
	static CreatureCombatBasicTable& Instance()
	{
		static CreatureCombatBasicTable sInstance;
		return sInstance;
	}

	const CreatureCombatBasicElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			CreatureCombatBasicElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("CreatureCombatBasicTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("CreatureCombatBasicTable: ") + std::to_string(key)).c_str());
		return NULL;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureCombatBasicElement>&	GetAllElement()
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
		return LoadJson("CreatureCombatBasic.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreatureCombatBasic.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureCombatBasic.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureCombatBasic.bin]未找到");
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

			CreatureCombatBasicElement	member;

						member.id=p.get<int>("id");
			member.note=p.get<string>("note");
			member.hp_min=p.get<int>("hp_min");
			member.hp_max=p.get<int>("hp_max");
			member.p_atk_min=p.get<int>("p_atk_min");
			member.p_atk_max=p.get<int>("p_atk_max");
			member.p_def=p.get<int>("p_def");
			member.s_atk_min=p.get<int>("s_atk_min");
			member.s_atk_max=p.get<int>("s_atk_max");
			member.s_def=p.get<int>("s_def");
			member.hit_value=p.get<int>("hit_value");
			member.dodge_value=p.get<int>("dodge_value");
			member.crit_value=p.get<int>("crit_value");
			member.resilience_value=p.get<int>("resilience_value");
			member.penetrate_value=p.get<int>("penetrate_value");
			member.block_value=p.get<int>("block_value");
			member.life_per_sec=p.get<float>("life_per_sec");
			member.life_steal_chance=p.get<float>("life_steal_chance");
			member.life_steal_rate=p.get<float>("life_steal_rate");
			member.thorns_chance=p.get<float>("thorns_chance");
			member.thorns_amount=p.get<int>("thorns_amount");
			member.exp=p.get<int>("exp");
			member.knockback_res=p.get<float>("knockback_res");
			member.hit=p.get<float>("hit");
			member.dodge=p.get<float>("dodge");
			member.crit=p.get<float>("crit");
			member.resilience=p.get<float>("resilience");
			member.penetrate=p.get<float>("penetrate");
			member.block=p.get<float>("block");
			member.crit_dmg=p.get<float>("crit_dmg");
			member.crit_res=p.get<float>("crit_res");


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
		if(vecLine.size() != 31)
		{
			printf_message("CreatureCombatBasic.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreatureCombatBasic.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="note"){printf_message("CreatureCombatBasic.csv中字段[note]位置不对应");assert(false); return false; }
		if(vecLine[2]!="hp_min"){printf_message("CreatureCombatBasic.csv中字段[hp_min]位置不对应");assert(false); return false; }
		if(vecLine[3]!="hp_max"){printf_message("CreatureCombatBasic.csv中字段[hp_max]位置不对应");assert(false); return false; }
		if(vecLine[4]!="p_atk_min"){printf_message("CreatureCombatBasic.csv中字段[p_atk_min]位置不对应");assert(false); return false; }
		if(vecLine[5]!="p_atk_max"){printf_message("CreatureCombatBasic.csv中字段[p_atk_max]位置不对应");assert(false); return false; }
		if(vecLine[6]!="p_def"){printf_message("CreatureCombatBasic.csv中字段[p_def]位置不对应");assert(false); return false; }
		if(vecLine[7]!="s_atk_min"){printf_message("CreatureCombatBasic.csv中字段[s_atk_min]位置不对应");assert(false); return false; }
		if(vecLine[8]!="s_atk_max"){printf_message("CreatureCombatBasic.csv中字段[s_atk_max]位置不对应");assert(false); return false; }
		if(vecLine[9]!="s_def"){printf_message("CreatureCombatBasic.csv中字段[s_def]位置不对应");assert(false); return false; }
		if(vecLine[10]!="hit_value"){printf_message("CreatureCombatBasic.csv中字段[hit_value]位置不对应");assert(false); return false; }
		if(vecLine[11]!="dodge_value"){printf_message("CreatureCombatBasic.csv中字段[dodge_value]位置不对应");assert(false); return false; }
		if(vecLine[12]!="crit_value"){printf_message("CreatureCombatBasic.csv中字段[crit_value]位置不对应");assert(false); return false; }
		if(vecLine[13]!="resilience_value"){printf_message("CreatureCombatBasic.csv中字段[resilience_value]位置不对应");assert(false); return false; }
		if(vecLine[14]!="penetrate_value"){printf_message("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应");assert(false); return false; }
		if(vecLine[15]!="block_value"){printf_message("CreatureCombatBasic.csv中字段[block_value]位置不对应");assert(false); return false; }
		if(vecLine[16]!="life_per_sec"){printf_message("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应");assert(false); return false; }
		if(vecLine[17]!="life_steal_chance"){printf_message("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应");assert(false); return false; }
		if(vecLine[18]!="life_steal_rate"){printf_message("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应");assert(false); return false; }
		if(vecLine[19]!="thorns_chance"){printf_message("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应");assert(false); return false; }
		if(vecLine[20]!="thorns_amount"){printf_message("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应");assert(false); return false; }
		if(vecLine[21]!="exp"){printf_message("CreatureCombatBasic.csv中字段[exp]位置不对应");assert(false); return false; }
		if(vecLine[22]!="knockback_res"){printf_message("CreatureCombatBasic.csv中字段[knockback_res]位置不对应");assert(false); return false; }
		if(vecLine[23]!="hit"){printf_message("CreatureCombatBasic.csv中字段[hit]位置不对应");assert(false); return false; }
		if(vecLine[24]!="dodge"){printf_message("CreatureCombatBasic.csv中字段[dodge]位置不对应");assert(false); return false; }
		if(vecLine[25]!="crit"){printf_message("CreatureCombatBasic.csv中字段[crit]位置不对应");assert(false); return false; }
		if(vecLine[26]!="resilience"){printf_message("CreatureCombatBasic.csv中字段[resilience]位置不对应");assert(false); return false; }
		if(vecLine[27]!="penetrate"){printf_message("CreatureCombatBasic.csv中字段[penetrate]位置不对应");assert(false); return false; }
		if(vecLine[28]!="block"){printf_message("CreatureCombatBasic.csv中字段[block]位置不对应");assert(false); return false; }
		if(vecLine[29]!="crit_dmg"){printf_message("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应");assert(false); return false; }
		if(vecLine[30]!="crit_res"){printf_message("CreatureCombatBasic.csv中字段[crit_res]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)31)
			{
				assert(false);
				return false;
			}
			CreatureCombatBasicElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.note=vecLine[1];
			member.hp_min=(int)atoi(vecLine[2].c_str());
			member.hp_max=(int)atoi(vecLine[3].c_str());
			member.p_atk_min=(int)atoi(vecLine[4].c_str());
			member.p_atk_max=(int)atoi(vecLine[5].c_str());
			member.p_def=(int)atoi(vecLine[6].c_str());
			member.s_atk_min=(int)atoi(vecLine[7].c_str());
			member.s_atk_max=(int)atoi(vecLine[8].c_str());
			member.s_def=(int)atoi(vecLine[9].c_str());
			member.hit_value=(int)atoi(vecLine[10].c_str());
			member.dodge_value=(int)atoi(vecLine[11].c_str());
			member.crit_value=(int)atoi(vecLine[12].c_str());
			member.resilience_value=(int)atoi(vecLine[13].c_str());
			member.penetrate_value=(int)atoi(vecLine[14].c_str());
			member.block_value=(int)atoi(vecLine[15].c_str());
			member.life_per_sec=(float)atof(vecLine[16].c_str());
			member.life_steal_chance=(float)atof(vecLine[17].c_str());
			member.life_steal_rate=(float)atof(vecLine[18].c_str());
			member.thorns_chance=(float)atof(vecLine[19].c_str());
			member.thorns_amount=(int)atoi(vecLine[20].c_str());
			member.exp=(int)atoi(vecLine[21].c_str());
			member.knockback_res=(float)atof(vecLine[22].c_str());
			member.hit=(float)atof(vecLine[23].c_str());
			member.dodge=(float)atof(vecLine[24].c_str());
			member.crit=(float)atof(vecLine[25].c_str());
			member.resilience=(float)atof(vecLine[26].c_str());
			member.penetrate=(float)atof(vecLine[27].c_str());
			member.block=(float)atof(vecLine[28].c_str());
			member.crit_dmg=(float)atof(vecLine[29].c_str());
			member.crit_res=(float)atof(vecLine[30].c_str());

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
