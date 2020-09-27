#ifndef __ITEMPROTO_CONFIG_H
#define __ITEMPROTO_CONFIG_H

#include "BaseDef.h"



using namespace std;

//道具原型配置数据结构
struct ItemProtoElement
{
	friend class ItemProtoTable;
	int id;                      	//道具ID	{equip(0)}_{class(0)}_{lv(000)}_{rank(0)}_{suit(0)}_{part(0)}:    equip-2,    class-0_物理;1_法术;2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼;8_模板    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    suit-0_非套装;1_1天赋;2_2天赋    part-1_武器;2_耳环;3_项链;4_戒指;5_帽子;6_盔甲;7_臂甲;8_腿甲    ”part(class=8)-0_装备;1_武器;2_饰品;3_防具
	string comment;              	//道具注释	策划用
	int name;                    	//道具名称	文本id
	int description;             	//道具描述	文本id
	string icon;                 	//道具图标	资源路径
	int model;                   	//道具模型	模型表ID
	int type;                    	//道具大类	见ItemType_道具类型
	int subtype;                 	//道具子类	见ItemType_道具类型
	int subtype_name;            	//子类名称	用于显示， 从StringItem表中获取
	int level;                   	//道具等级	0表示无等级限制
	int rank;                    	//道具品质	0白 1绿 2蓝 3紫 4橙 5红
	int marquee;                 	//获取跑马灯	0无跑马灯 1有跑马灯
	int time_remind;             	//队伍提醒	0无队伍提醒 1有队伍提醒
	int price;                   	//系统回收价格	对应的银币价格
	int exchange_bottom;         	//交易最低价格	对应金币价格
	int exchange_init;           	//是否可交易	0：不可交易 1：可交易
	int exchange_currency;       	//交易货币类型	0通用 1交易货币 2硬货币
	vector<int> occupation;      	//职业限制	1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使
	vector<int> transfer_id;     	//中转id	进行道具中专时 对应的道具 按照顺序代表【战士】【刺客】【游侠】【法师】【圣骑士】【神秘使】
	int stack;                   	//堆叠数量	1~65535
	int bind;                    	//绑定形式	0拾取绑定 1存在多态的绑定形式 具体绑定形式由掉落决定
	int can_lock;                	//可上锁	0不可以 1可以上锁
	int pickup_type;             	//拾取形式	0常规拾取 1拾取后立刻使用 2拾取后弹出快捷使用界面 3拾取后归属于工会
	vector<int> item_effect;     	//物品使用效果	如果该字段有内容，表示点击使用按扭不会调用server_script  数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	string behaviac;             	//副本行为树	Config/behaviac/下的目录
	string server_script_id;     	//物品使用效果	更新中 不填表示无法使用
	vector<float> effect_param;  	//效果参数	物品效果触发时所传入的参数，可以是多个数值
	int required_scene;          	//使用需求场景	0无需求 1城镇 2野外 3副本
	int relations;               	//使用目标与玩家自己的敌我关系	0自身 1敌人 2友方
	int target_type;             	//可使用的目标类型	0玩家 1NPC/怪物 2obj
	int use_destory;             	//使用后销毁	0不销毁 1销毁
	int global_cd;               	//全局CD	使用该道具产生的公共CD 单位为毫秒
	int group;                   	//道具组	用来判断公共CD或同类互斥功能
	int batch_use;               	//批量使用	0不可批量使用 1可批量使用
	int fast_use;                	//快速使用	道具是否会弹出快速使用弹窗 0.不会 1.会
	int use_when_dead;           	//死亡后使用	0不可以 1可以
	int timer_type;              	//计时器类型	0不记时 1入手计时 2使用计时
	int life_time;               	//道具寿命	单位为分 如果可叠加则不生效
	int expire_time;             	//过期时间	填入时间 填0则表示没有过期时间
	int cross_scene_destory;     	//切换区域销毁	0不销毁 1销毁
	int store_type;              	//存储类型	0不存背包 1存通用背包 2宠物背包
	int tag;                     	//背包标签	对于不存背包的道具无效 1代表第二个页签；2代表第三个页签；3代表第四个页签
	int pickup_notice;           	//过期时间	0不公告 1公告
	int external_id;             	//外链id	如果是装备，则对应装备表的id 如果是宝石，则对应宝石表的id 如果是宠物，测对应宠物表的id 如果是宠物技能书，则对应宠物技能书表 等等…
	int can_mix;                 	//合成标签	0不可合成 或填写合成表中的 道具id 
	int can_break;               	//分解标签	0不可分解 1可分解
	vector<int> break_get;       	//分解获得道具	分解获得的道具id
	vector<int> break_count;     	//分解获得道具数量	分解获得的道具数量 需要和break_get对应
	int unlock_lv;               	//生活技能解锁等级	生活技能制作该道具所需生活技能等级，不填写或0则非生活技能道具
	int source_id;               	//来源表ID	对应道具来源表的id
	int cast_skill;              	//释放技能ID	释放技能ID
	int bi_log;                  	//BI打点用	填0或不填上报BI 填1不上报

private:

public:

	ItemProtoElement()
	{
		id = -1;

	}
};

//道具原型配置封装类
class ItemProtoTable
{
	public:
	typedef std::unique_ptr<ItemProtoElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	ItemProtoTable();
	~ItemProtoTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static ItemProtoTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const ItemProtoElement* GetElement(int key);

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
