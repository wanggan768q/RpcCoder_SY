#ifndef __CHARACTERCONFIG_CONFIG_H
#define __CHARACTERCONFIG_CONFIG_H

#include "BaseDef.h"



using namespace std;

//模型配置配置数据结构
struct CharacterConfigElement
{
	friend class CharacterConfigTable;
	int id;                      	//配置ID	ID段划分： 0-1000特殊； 1000-9999角色； 10000-29999怪物； 30000-39999静物； 40000-49999npc； 50000-59999宠物
	string comment;              	//描述	仅策划用
	string filename;             	//模型文件名	模型文件名
	string  material;            	//材质	需要更换的材质文件 （时装染色）
	vector<float> camera_point;  	//	镜头位置特殊xyz
	vector<float> zoom;          	//缩放比例	X|Y|Z坐标
	vector<float> bound_center;  	//包围盒中心点	X|Y|Z坐标 别全拉公式！！ 有不是公式导的！
	vector<float> bound_size;    	//包围盒大小	X|Y|Z坐标 实测结果：影响OBJ交互范围
	vector<float> near_effect_scale;	//特效大小	X|Y|Z坐标 实测结果：影响OBJ靠近时播放的特效大小
	int projection;              	//界面投影类型	0 透视 1 正交
	vector<float> render_position;	//界面投影坐标	关联Unity中Myrender下父级Model中的Position X|Y|Z
	vector<float> render_rotation;	//界面投影角度	关联Unity中Myrender下子级Model中的Rotation X|Y|Z
	vector<float> render_scale;  	//界面投影比例	关联Unity中Myrender下子级Model中的Scale X|Y|Z
	int standup_time;            	//起身时间	模型被击倒后起身的动作时间(单位:ms)
	int hurt_time;               	//受击时长	模型受击动作时长(单位:ms)
	float hp_height;             	//模型头顶信息基础高度	该值和模型中的H_World_03点Y轴值匹配 该高度以npc脚的位置为起点计算

private:

public:

	CharacterConfigElement()
	{
		id = -1;

	}
};

//模型配置配置封装类
class CharacterConfigTable
{
	public:
	typedef std::unique_ptr<CharacterConfigElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CharacterConfigTable();
	~CharacterConfigTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CharacterConfigTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CharacterConfigElement* GetElement(int key);

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
