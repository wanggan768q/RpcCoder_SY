#ifndef __WAYPOINT_CONFIG_H
#define __WAYPOINT_CONFIG_H

#include "BaseDef.h"



using namespace std;

//路点表配置数据结构
struct WayPointElement
{
	friend class WayPointTable;
	int id;                      	//路点ID	路点ID
	string comment;              	//	
	int spawn_map_id;            	//路点所在的场景号	路点所在的场景号
	float spawn_x;               	//路点所处的场景的X坐标	路点所处的场景的X坐标
	float spawn_y;               	//路点所处的场景的Y坐标	路点所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	int face_rotate;             	//生成点朝向	用角度表示角色传送/复活的朝向，采用unity中生成点Y轴的旋转量 MOVE TO WAYPONIT接口会用这个路点的角度，填-1是不改变当前角度
	int waypoint_next_id;        	//下一个路点ID	下一个路点ID
	string waypoint_animation;   	//到达路点后播放的动画路径	到达路点后播放的动画路径
	int waypoint_delay;          	//到达路点后停留的时间	到达路点后停留的时间
	float fly_height;            	//飞行坐骑高度	飞行坐骑高度
	int pet_start;               	//宠物捕获路点标识	是宠物捕获的起始路点为1 不是为0

private:

public:

	WayPointElement()
	{
		id = -1;

	}
};

//路点表配置封装类
class WayPointTable
{
	public:
	typedef std::unique_ptr<WayPointElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	WayPointTable();
	~WayPointTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static WayPointTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const WayPointElement* GetElement(int key);

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
