#ifndef __CREATUREDUMMY_CONFIG_H
#define __CREATUREDUMMY_CONFIG_H

#include "BaseDef.h"



using namespace std;

//多NPC巡逻盒子表配置数据结构
struct CreatureDummyElement
{
	friend class CreatureDummyTable;
	int id;                      	//序号	序号
	int spawn_map_id;            	//dummy所在的场景ID	dummy所在的场景ID
	float spawn_x;               	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	float spawn_y;               	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	float move_speed;            	//dummy的移动速度	dummy的移动速度
	int attached_npc_01;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_02;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_03;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_04;         	//所附带的NPC ID	所附带的NPC ID
	int attached_npc_05;         	//所附带的NPC ID	所附带的NPC ID
	int waypoint_start;          	//dummy的出生路点	dummy的出生路点

private:

public:

	CreatureDummyElement()
	{
		id = -1;

	}
};

//多NPC巡逻盒子表配置封装类
class CreatureDummyTable
{
	public:
	typedef std::unique_ptr<CreatureDummyElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureDummyTable();
	~CreatureDummyTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureDummyTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureDummyElement* GetElement(int key);

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
