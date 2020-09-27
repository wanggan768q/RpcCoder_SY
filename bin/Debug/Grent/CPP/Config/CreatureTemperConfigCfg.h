#ifndef __CREATURETEMPERCONFIG_CONFIG_H
#define __CREATURETEMPERCONFIG_CONFIG_H

#include "BaseDef.h"



using namespace std;

//NPC行为参数配置数据结构
struct CreatureTemperConfigElement
{
	friend class CreatureTemperConfigTable;
	int id;                      	//性格ID	关联Creature
	string comment;              	//备注	仅策划用
	int search_style;            	// 索敌类型	0=范围索敌 1=全图索敌
	int hatred_range;            	//仇恨清除半径	废弃，没用
	float search_distance;       	//锁敌距离	单位：米 进战半径 被动怪=0
	int chase_type;              	//追敌类型	0=范围追敌 1=全图追敌
	int chase_distance;          	//脱战半径	类型0有用 类型1没用 单位M
	int chase_time;              	//回归时间	单位：毫秒
	float chase_speed;           	//回归加速度	单位：米/秒
	int hatred_area;             	//仇恨区域	进战后定期为区域内的玩家增加仇恨值 单位：米（半径） 别用！
	int delay_min;               	//攻击延迟最小时间	两次攻击之间的延迟 单位：ms
	int delay;                   	//攻击延迟最大时间	两次攻击之间的延迟 单位：ms
	float detection_distance;    	//后退检测距离	攻击结束后检测目标包围盒与自己的距离小于该值后进行后退
	float back_distance;         	//后退距离	注意后退距离要小于自己的攻击距离
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

public:

	CreatureTemperConfigElement()
	{
		id = -1;

	}
};

//NPC行为参数配置封装类
class CreatureTemperConfigTable
{
	public:
	typedef std::unique_ptr<CreatureTemperConfigElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureTemperConfigTable();
	~CreatureTemperConfigTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureTemperConfigTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureTemperConfigElement* GetElement(int key);

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
