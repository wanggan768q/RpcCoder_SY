#ifndef __CREATURECOMBATCOE_CONFIG_H
#define __CREATURECOMBATCOE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//NPC战斗系数表配置数据结构
struct CreatureCombatCoeElement
{
	friend class CreatureCombatCoeTable;
	int id;                      	//ID号	关联Creature
	string comment;              	//中文注释	
	int template_id;             	//对应模板	关联CreatureCombatbasic
	float maxhp_rate;            	//生命比例	
	float physic_attack_rate;    	//物理攻击力比例	参数1：攻击类型系数，怪物都同时具有物理攻击和魔法攻击 参数2：怪物数量系数，每组怪有多少只
	float physic_defense_rate;   	//物理防御力比例	
	float magic_attack_rate;     	//魔法攻击力比例	
	float magic_defense_rate;    	//魔法防御力比例	
	float exp_rate;              	//经验比例	

private:

public:

	CreatureCombatCoeElement()
	{
		id = -1;

	}
};

//NPC战斗系数表配置封装类
class CreatureCombatCoeTable
{
	public:
	typedef std::unique_ptr<CreatureCombatCoeElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureCombatCoeTable();
	~CreatureCombatCoeTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureCombatCoeTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureCombatCoeElement* GetElement(int key);

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
