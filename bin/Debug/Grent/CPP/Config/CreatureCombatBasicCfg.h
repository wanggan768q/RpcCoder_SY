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
	int maxhp_min;               	//生命下限	生命下限
	int maxhp_max;               	//生命上限	生命上限
	int physic_attack_min;       	//物理攻击力下限	物理攻击力下限
	int physic_attack_max;       	//物理攻击力上限	物理攻击力上限
	int physic_defense;          	//物理防御力	物理防御力
	int magic_attack_min;        	//魔法攻击力下限	魔法攻击力下限
	int magic_attack_max;        	//魔法攻击力上限	魔法攻击力上限
	int magic_defense;           	//魔法防御力	魔法防御力
	int hit_value;               	//命中值	命中值
	int miss_value;              	//闪避值	闪避值
	int critical_value;          	//暴击值	暴击值
	int tenacity_value;          	//韧性值	韧性值
	int penetrate_value;         	//穿透值	穿透值
	int dodge_value;             	//格挡值	格挡值
	float life_per_sec;          	//生命恢复速度	生命恢复速度
	float life_steal_chance;     	//生命偷取几率	生命偷取几率
	float life_steal_rate;       	//生命偷取比例	生命偷取比例
	float thorns_chance;         	//反弹率	反弹率
	int thorns_amount;           	//反弹值	反弹值
	int exp;                     	//经验值	经验值
	float knockback_res;         	//击退抵抗率	击退抵抗率
	float hit_rate;              	//命中率	命中率
	float miss_rate;             	//闪避率	闪避率
	float critical_rate;         	//暴击率	暴击率
	float tenacity_rate;         	//韧性率	韧性率
	float penetrate_rate;        	//穿透率	穿透率
	float dodge_rate;            	//格挡率	格挡率
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
	typedef unordered_map<int, CreatureCombatBasicElement> MapElementMap;
	MapElementMap	m_mapElements;
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
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("CreatureCombatBasicTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
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
			member.maxhp_min=p.get<int>("maxhp_min");
			member.maxhp_max=p.get<int>("maxhp_max");
			member.physic_attack_min=p.get<int>("physic_attack_min");
			member.physic_attack_max=p.get<int>("physic_attack_max");
			member.physic_defense=p.get<int>("physic_defense");
			member.magic_attack_min=p.get<int>("magic_attack_min");
			member.magic_attack_max=p.get<int>("magic_attack_max");
			member.magic_defense=p.get<int>("magic_defense");
			member.hit_value=p.get<int>("hit_value");
			member.miss_value=p.get<int>("miss_value");
			member.critical_value=p.get<int>("critical_value");
			member.tenacity_value=p.get<int>("tenacity_value");
			member.penetrate_value=p.get<int>("penetrate_value");
			member.dodge_value=p.get<int>("dodge_value");
			member.life_per_sec=p.get<float>("life_per_sec");
			member.life_steal_chance=p.get<float>("life_steal_chance");
			member.life_steal_rate=p.get<float>("life_steal_rate");
			member.thorns_chance=p.get<float>("thorns_chance");
			member.thorns_amount=p.get<int>("thorns_amount");
			member.exp=p.get<int>("exp");
			member.knockback_res=p.get<float>("knockback_res");
			member.hit_rate=p.get<float>("hit_rate");
			member.miss_rate=p.get<float>("miss_rate");
			member.critical_rate=p.get<float>("critical_rate");
			member.tenacity_rate=p.get<float>("tenacity_rate");
			member.penetrate_rate=p.get<float>("penetrate_rate");
			member.dodge_rate=p.get<float>("dodge_rate");
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
		if(vecLine[0]!="id"){printf_message("CreatureCombatBasic.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="note"){printf_message("CreatureCombatBasic.csv中字段[note]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="maxhp_min"){printf_message("CreatureCombatBasic.csv中字段[maxhp_min]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="maxhp_max"){printf_message("CreatureCombatBasic.csv中字段[maxhp_max]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="physic_attack_min"){printf_message("CreatureCombatBasic.csv中字段[physic_attack_min]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="physic_attack_max"){printf_message("CreatureCombatBasic.csv中字段[physic_attack_max]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="physic_defense"){printf_message("CreatureCombatBasic.csv中字段[physic_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="magic_attack_min"){printf_message("CreatureCombatBasic.csv中字段[magic_attack_min]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="magic_attack_max"){printf_message("CreatureCombatBasic.csv中字段[magic_attack_max]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="magic_defense"){printf_message("CreatureCombatBasic.csv中字段[magic_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="hit_value"){printf_message("CreatureCombatBasic.csv中字段[hit_value]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="miss_value"){printf_message("CreatureCombatBasic.csv中字段[miss_value]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="critical_value"){printf_message("CreatureCombatBasic.csv中字段[critical_value]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="tenacity_value"){printf_message("CreatureCombatBasic.csv中字段[tenacity_value]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="penetrate_value"){printf_message("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="dodge_value"){printf_message("CreatureCombatBasic.csv中字段[dodge_value]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="life_per_sec"){printf_message("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="life_steal_chance"){printf_message("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="life_steal_rate"){printf_message("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="thorns_chance"){printf_message("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="thorns_amount"){printf_message("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="exp"){printf_message("CreatureCombatBasic.csv中字段[exp]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="knockback_res"){printf_message("CreatureCombatBasic.csv中字段[knockback_res]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="hit_rate"){printf_message("CreatureCombatBasic.csv中字段[hit_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="miss_rate"){printf_message("CreatureCombatBasic.csv中字段[miss_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="critical_rate"){printf_message("CreatureCombatBasic.csv中字段[critical_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="tenacity_rate"){printf_message("CreatureCombatBasic.csv中字段[tenacity_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="penetrate_rate"){printf_message("CreatureCombatBasic.csv中字段[penetrate_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="dodge_rate"){printf_message("CreatureCombatBasic.csv中字段[dodge_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="crit_dmg"){printf_message("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="crit_res"){printf_message("CreatureCombatBasic.csv中字段[crit_res]位置不对应 ");assert(false); return false; }

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
			member.maxhp_min=(int)atoi(vecLine[2].c_str());
			member.maxhp_max=(int)atoi(vecLine[3].c_str());
			member.physic_attack_min=(int)atoi(vecLine[4].c_str());
			member.physic_attack_max=(int)atoi(vecLine[5].c_str());
			member.physic_defense=(int)atoi(vecLine[6].c_str());
			member.magic_attack_min=(int)atoi(vecLine[7].c_str());
			member.magic_attack_max=(int)atoi(vecLine[8].c_str());
			member.magic_defense=(int)atoi(vecLine[9].c_str());
			member.hit_value=(int)atoi(vecLine[10].c_str());
			member.miss_value=(int)atoi(vecLine[11].c_str());
			member.critical_value=(int)atoi(vecLine[12].c_str());
			member.tenacity_value=(int)atoi(vecLine[13].c_str());
			member.penetrate_value=(int)atoi(vecLine[14].c_str());
			member.dodge_value=(int)atoi(vecLine[15].c_str());
			member.life_per_sec=(float)atof(vecLine[16].c_str());
			member.life_steal_chance=(float)atof(vecLine[17].c_str());
			member.life_steal_rate=(float)atof(vecLine[18].c_str());
			member.thorns_chance=(float)atof(vecLine[19].c_str());
			member.thorns_amount=(int)atoi(vecLine[20].c_str());
			member.exp=(int)atoi(vecLine[21].c_str());
			member.knockback_res=(float)atof(vecLine[22].c_str());
			member.hit_rate=(float)atof(vecLine[23].c_str());
			member.miss_rate=(float)atof(vecLine[24].c_str());
			member.critical_rate=(float)atof(vecLine[25].c_str());
			member.tenacity_rate=(float)atof(vecLine[26].c_str());
			member.penetrate_rate=(float)atof(vecLine[27].c_str());
			member.dodge_rate=(float)atof(vecLine[28].c_str());
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
