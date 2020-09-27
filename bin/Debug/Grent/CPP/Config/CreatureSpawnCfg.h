#ifndef __CREATURESPAWN_CONFIG_H
#define __CREATURESPAWN_CONFIG_H

#include "BaseDef.h"



using namespace std;

//NPC位置表配置数据结构
struct CreatureSpawnElement
{
	friend class CreatureSpawnTable;
	int id;                      	//序号	序号
	int npc_entry_id;            	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	int spawn_map_id;            	//NPC所处的场景号	NPC所处的场景号
	float spawn_x;               	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	float spawn_y;               	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	int refresh_time;            	//NPC死亡后的刷新时间	NPC死亡后的刷新时间
	int refresh_type;            	//NPC死亡后的刷新类型	NPC死亡后的刷新类型
	string animation_default;    	//默认动画路径	默认动画路径
	string animation_delay;      	//动画延迟时间	动画延迟时间
	string waypoint_id;          	//该NPC的起始路点	该NPC的起始路点

private:

public:

	CreatureSpawnElement()
	{
		id = -1;

	}
};

//NPC位置表配置封装类
class CreatureSpawnTable
{
	public:
	typedef std::unique_ptr<CreatureSpawnElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureSpawnTable();
	~CreatureSpawnTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureSpawnTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureSpawnElement* GetElement(int key);

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
