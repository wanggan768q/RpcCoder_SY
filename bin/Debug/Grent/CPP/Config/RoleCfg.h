#ifndef __ROLE_CONFIG_H
#define __ROLE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//角色属性配置数据结构
struct RoleElement
{
	friend class RoleTable;
	int id;                      	//id	种族*100000+职业*10+性别
	string comment;              	//注释	注释
	int race;                    	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	int occupation;              	//职业	1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士 6：神秘使
	string characteristic;       	//职业特色	职业特色
	int gender;                  	//性别	1:男性 2:女性
	string race_icon;            	//种族图标	已被废弃 种族图标
	int race_name;               	//种族名称	种族名称
	int race_desc;               	//种族介绍	种族介绍
	string occu_icon;            	//职业图标	职业图标
	vector<string> create_occu_icon;	//创建界面图标	专门用在创建界面的 职业头像 对应未选中和选中两个状态
	vector<string> select_occu_icon;	//选择界面图标	专门用在选择界面的 职业标示 对应未选中和选中两个状态
	int occu_name;               	//职业名称	职业名称
	int occu_desc;               	//职业介绍	职业介绍
	string occu_evaluate;        	//职业评估	对应每个职业特性图路径
	int show_model;              	//展示模型id	在角色创建界面上显示的模型id
	string default_headshot;     	//默认头像	默认在游戏中使用的头像
	string default_portrait;     	//默认肖像	默认在游戏中使用的全身像
	string default_gaine;        	//默认半身像	默认在游戏中使用的半身像
	int model_id;                	//初始模型id	初始模型id
	float leisure_pro;           	//播放休闲动画几率	1=100%
	string select_model;         	//临时选择角色显示模型	目前在属性界面中调用
	float animation;             	//出场动画时间(秒)	出场动画时间(秒)
	int initial_face;            	//初始面部模型	
	int initial_head;            	//初始头部模型	
	int initial_body;            	//初始身体模型	
	int initial_weapon;          	//初始武器模型	
	float camera_size;           	//属性界面摄像机的缩放参数	数值越大角色模型显示越小 默认为1
	vector<float> camera_pos;    	//属性界面摄像机的位移参数	分别表示摄像机的X和Y轴偏移 默认为0|0
	int attack_type;             	//角色普攻类型	0.物理 1.魔法
	int initial_level;           	//初始等级	初始等级
	int initial_weapon_equip;    	//初始武器	初始武器
	int initial_head_equip;      	//初始头盔	初始头盔
	int initial_earring_equip;   	//初始耳环	初始耳环
	int initial_chest_equip;     	//初始胸甲	初始胸甲
	int initial_necklace_equip;  	//初始项链	初始项链
	int initial_hand_equip;      	//初始手甲	初始手甲
	int initial_ring_equip;      	//初始戒指	初始戒指
	int initial_foot_equip;      	//初始靴子	初始靴子
	int initial_quest;           	//初始任务	初始任务
	int nomorl_attack;           	//普攻id	
	float hp_stand_height;       	//玩家站立时血条高度	该高度以玩家脚的位置为起点计算
	float hp_sit_height;         	//玩家坐下时血条高度	该高度以玩家脚的位置为起点计算
	vector<string> footsteps_list_run;	//跑步	脚步声列表-跑步对应的三个天气，分别是雨雪正常天
	vector<string> footsteps_list_dash;	//疾跑	疾跑对应的三个天气，分别是雨雪正常天
	string footsteps_par;        	//参数	参数
	string sound_die;            	//死亡音效	死亡音效文件名
	int short_id;                	//缩略版id	用在特殊的地方 种族*100+职业*10+性别
	int profession_id;           	//技能id	对应专精表的id信息
	int talent_id;               	//天赋id	对应天赋表的天赋信息
	vector<float> scare_mine;    	//铁镐缩放	铁镐缩放
	vector<float> scare_fishing; 	//鱼竿缩放	鱼竿缩放
	vector<int> profession_colour;	//职业颜色	用于战斗统计显示
	vector<int> profession_life; 	//生活技能ID组	生活技能用
	vector<int> profession_skill;	//对应skillID	生活技能用 采药|钓鱼|挖矿 顺序不能变
	vector<int> profession_wq;   	//对应使用武器	生活技能用 填模型ID 采药|钓鱼|挖矿 顺序不能变
	vector<float> yugan_position;	//鱼竿模型旋转	偏移坐标
	vector<int> yugan_rotation;  	//鱼竿模型旋转	偏移坐标
	vector<int> yugan_scale;     	//鱼竿模型旋转	偏移坐标
	vector<float> kuangchan_position;	//矿铲模型旋转	偏移坐标
	vector<int> kuangchan_rotation;	//矿铲模型旋转	偏移坐标
	vector<int> kuangchan_scale; 	//矿铲模型旋转	偏移坐标
	string dash_performance;     	//进入疾跑时的特效	疾跑特效

private:

public:

	RoleElement()
	{
		id = -1;

	}
};

//角色属性配置封装类
class RoleTable
{
	public:
	typedef std::unique_ptr<RoleElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	RoleTable();
	~RoleTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static RoleTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const RoleElement* GetElement(int key);

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
