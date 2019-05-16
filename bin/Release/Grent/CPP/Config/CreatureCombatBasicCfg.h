#ifndef __CREATURECOMBATBASIC_CONFIG_H
#define __CREATURECOMBATBASIC_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//NPC战斗属性表配置数据结构
struct CreatureCombatBasicElement
{
	friend class CreatureCombatBasicTable;
	int id;                      	//ID号	模板类*1000+等级 模板关联CreatureCombatCoe; 等级关联Creature
	string comment;              	//中文注释	中文注释
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
	map<int, CreatureCombatBasicElement>	m_mapElements;
	vector<CreatureCombatBasicElement>	m_vecAllElements;
	CreatureCombatBasicElement m_emptyItem;
public:
	static CreatureCombatBasicTable& Instance()
	{
		static CreatureCombatBasicTable sInstance;
		return sInstance;
	}

	CreatureCombatBasicElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
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
	}

	bool LoadBin(string strContent)
	{

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
		if(vecLine[1]!="comment"){printf_message("CreatureCombatBasic.csv中字段[comment]位置不对应 ");assert(false); return false; }
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
			member.comment=vecLine[1];
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
};

#endif
