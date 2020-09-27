#ifndef __CREATURECOMBATBASIC_CONFIG_H
#define __CREATURECOMBATBASIC_CONFIG_H

#include "BaseDef.h"



using namespace std;

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
	float stun_rate;             	//眩晕命中	眩晕命中率
	float stun_res_rate;         	//眩晕抵抗	眩晕抵抗率
	float immobilize_rate;       	//定身命中	定身命中率
	float immobilize_res_rate;   	//定身抵抗	定身抵抗率
	float hit_fly_rate;          	//击飞命中	击飞命中率
	float hit_fly_res_rate;      	//击飞抵抗	击飞抵抗率
	float freeze_rate;           	//冰冻命中	冰冻命中率
	float freeze_res_rate;       	//冰冻抵抗	冰冻抵抗率
	float purify_rate;           	//净化命中	净化命中率
	float purify_res_rate;       	//净化抵抗	净化抵抗率
	float dispel_rate;           	//驱散命中	驱散命中率
	float dispel_res_rate;       	//驱散抵抗	驱散抵抗率
	float slience_rate;          	//沉默命中	沉默命中率
	float slience_res_rate;      	//沉默抵抗	沉默抵抗率
	float break_rate;            	//打断命中	打断命中率
	float break_res_rate;        	//打断抵抗	打断抵抗率
	float damp_heal_rate;        	//禁疗命中	禁疗命中率
	float damp_heal_res_rate;    	//禁疗抵抗	禁疗抵抗率
	int cri_dmg_value;           	//暴击加伤值	暴击加伤值
	int cri_res_dmg_value;       	//暴击免伤值	暴击免伤值
	float block_dmg_value;       	//格挡减伤值	格挡减伤值
	float block_dmg_rate;        	//格挡减伤率	格挡减伤率
	float block_res_dmg_value;   	//格挡破伤值	格挡破伤值
	float block_res_dmg_rate;    	//格挡破伤率	格挡破伤率
	float to_player_dmg_rate;    	//对玩家伤害倍率	对玩家伤害倍率
	float from_player_dmg_rate;  	//受到玩家伤害倍率	受到玩家伤害倍率
	float to_monster_dmg_rate;   	//对所有怪物伤害倍率	对所有怪物伤害倍率
	float from_monster_dmg_rate; 	//受到所有怪物伤害倍率	受到所有怪物伤害倍率
	float to_boss_dmg_rate;      	//对BOSS伤害倍率	对BOSS伤害倍率
	float from_boss_dmg_rate;    	//受到BOSS伤害倍率	受到BOSS伤害倍率

private:

public:

	CreatureCombatBasicElement()
	{
		id = -1;

	}
};

//NPC战斗属性表配置封装类
class CreatureCombatBasicTable
{
	public:
	typedef std::unique_ptr<CreatureCombatBasicElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureCombatBasicTable();
	~CreatureCombatBasicTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureCombatBasicTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureCombatBasicElement* GetElement(int key);

	bool HasElement(int key);

	const vec_type& GetAllID() const;

	const MapElementMap& GetAllElement() const;
	bool Load();

	void NotifyCb();

	bool LoadJson(const std::string& jsonFile);


	bool ReLoad();
	

  int32_t min_table_id()const;
  int32_t max_table_id()const;
 private:
   int32_t min_table_id_{INT32_MAX};
   int32_t max_table_id_{INT32_MIN};
   bool m_bLoad{false};

};

#endif
