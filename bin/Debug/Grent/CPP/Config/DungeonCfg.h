#ifndef __DUNGEON_CONFIG_H
#define __DUNGEON_CONFIG_H

#include "BaseDef.h"



using namespace std;

//副本表配置数据结构
struct DungeonElement
{
	friend class DungeonTable;
	int id;                      	//序号	序号
	string comment;              	//备注	策划看
	int map_id;                  	//场景ID	对应Scene_场景表ID
	int dungeon_type;            	//副本类型	0：野外 1：2~5人普通 2：2~5人困难 3：单人（非剧情） 4：团队普通 5：团队困难 6：公会 7：单人爬塔 8：单人剧情 9：组队活动副本
	int rebotonoff;              	//是否创建机器人	0 不创建 1 创建 
	int auto_on;                 	//自动开启自动副本	进入副本后自动开启自动副本 1 自动开启 0 不自动开启
	int order;                   	//副本查找器索引	按等级开启顺序排序，同一副本的不同难度，按难度排序 -1：不在副本查找器中显示（特殊类型，如日常活动等）
	int enter_location;          	//副本入口传送门位置	野外场景，副本入口传送门的位置，对应路点表
	int difficult;               	//难度文本	野外碰触副本入口时弹出的UI中难度按钮文本。读StringUi表
	vector<int> level;           	//副本等级	进入副本所需玩家等级 等级下限|等级上限
	int tips_lv;                 	//弹窗需求等级	进入低级副本时的弹窗条件： 0  永远不弹 N  玩家当前等级-副本等级大于等于N时 弹窗
	int recommend_power;         	//推荐战力	UI显示用
	int rebirth_num;             	//原地复活次数	每次生成的副本每玩家允许原地复活的次数 0/不填  不允许 1~98  X次数 99  不限次 
	vector<int> open_day;        	//每周开放日	例如：2|4 每周二、四开放
	vector<int> player_config_list;	//玩家职业推荐	坦克人数|治疗人数|输出人数
	string obj_group;            	//怪物所属分组	此字段无用 ice_server\trunk\bin\Config\Scene相应文件夹下的monster文件
	int team_type;               	//队伍状态	进入副本需求当前队伍状态 0/不填  不限制 1  单人 2  小队 3  团队
	int min_num;                 	//最少玩家数量	进入副本至少需求X名玩家 默认为1
	int max_num;                 	//最多玩家数量	副本内最多可进入X名玩家默认为1 最大为10 （单人本需填写1，超过1则需要组队才能进入）
	int required_quest_id;       	//需接到任务	只有接到指定ID的任务才能进入该副本
	int required_last_dungeon_id;	//所需前置副本ID	只有通关指定的副本ID才能解锁该副本
	int reset_type;              	//重置类型	服务器没用此字段 1：每日早上5点重置 2：每周固定时间维护 3：每次副本销毁后重置 默认为1。重置后首通奖励重置且进度清空。
	int finish_amount;           	//允许玩家完成次数	服务器没用此字段允许玩家最多完成的副本次数，超出该次数不再获得奖励
	int halfway_join;            	//续排类型	是否允许中途进入副本 0 允许，可在任意阶段中途进入。 1 不允许，任意阶段都不允许中途进入。 2 只要有队员处于首领战状态就禁止进入，其余阶段可进入
	int friendship_add;          	//友好度增加	服务器没用此字段 好友组队进行副本增加的友好度数值
	int name_id;                 	//副本名字ID	对应StringUi_界面文本表
	int describle_id;            	//副本描述ID	对应StringUi_界面文本表
	int simple_describle_id;     	//副本简单描述ID	对应StringUi_界面文本表
	int story_describle_id;      	//剧情本结算描述	对应StringUi_界面文本表
	string mini_pic;             	//副本图片	野外碰触副本入口时弹出的UI中显示的副本图片 填图片资源名
	int First_reward_ui;         	//首通奖励礼包ID	服务器没用此字段
	int general_reward_ui;       	//非首通奖励礼包ID	服务器没用此字段
	vector<int> reward_display;  	//奖励显示	进副本时弹出的面板中展示的奖励图标，对应ItemProto_道具原型表，为数组
	int is_transfer;             	//是否需要装备中转表	服务器没用此字段
	string start_music;          	//开启音乐	此字段无用。音乐在场景表中。
	string loop_music;           	//循环音乐	此字段无用。音乐在场景表中。
	int kill_refresh;            	//击杀次数刷新	1=每日刷新 7=每周刷新 99=永不刷新（剧情本用）
	vector<int> boss_id;         	//bossid	最左边开始是1号BOSS
	vector<int> boss_kill_num;   	//boss可击杀次数	同难度同序号BOSS共享次数（剧情副本则是每个副本单独计数、不共享）
	vector<int> all_rewards;     	//此难度奖励总览	展示道具id，UI显示用
	string map_pic;              	//地图图片	雷达图
	vector<int> boss_rewards;    	//boss掉落展示	固定5个（全局表ID40配置） 副本内有3个BOSS掉落数量3、5、4的填法如下 1|2|3|0|0|1|2|3|4|5|1|2|3|4|0 副本内有2个BOSS掉落数量3、5的填法如下 1|2|3|0|0|1|2|3|4|5
	int endingboss_id;           	//最后boss ID	对应Creature_总NPC表
	int automatic_entry;         	//是否自动进入	配置0不自动准备 配置1自动准备  默认为0
	int duration_time;           	//副本总时长	 脚本未配置才读这里. 副本从创建到销毁的总时长 单位秒
	int prepare_time;            	//副本准备时间	脚本未配置才读这里. 副本生成后，最开始的准备时间单位秒
	int reward_time;             	//副本结算时间	脚本未配置才读这里. 单位秒
	int conclusion_delayed;      	//结算动画延迟时间	结算时间到后延迟多少秒播放结算动画 单位为秒
	int start_time;              	//副本开启时间	服务器没用此字段
	int end_time;                	//副本关闭时间	服务器没用此字段
	int teleport_id;             	//通关传送门ID	
	int teleport_location;       	//传送门生成路点	对应WayPoint_路点表ID
	string teleporteffect;       	//传送门特效	
	int exit_waypoint;           	//胜利后的传出位置	副本胜利后传出的位置。 对应WayPoint_路点表ID
	int defeat_exit_waypoint;    	//未胜利的传出位置	副本失败/中途退出/中途离线后传出的位置。 对应WayPoint_路点表ID
	string monster_id;           	//副本怪物ID	不同难度副本对应的不同的Monster.json文件，-1表示未配置Monster.json文件
	string dungeon_lua;          	//副本脚本	对应 ice_server\trunk\bin\Config\Script\Dungeon下的脚本
	string behaviac;             	//副本行为树	Config/behaviac/下的目录
	vector<int> area_id;         	//区域id	
	int monster_delay;           	//刷怪延迟	创建副本后n秒刷怪  单位：秒
	int second_verification;     	//二次确认	副本最低进入人数＞1该字段生效 效果是进入副本时是否弹出二次确认面板 0需要 1不需要
	int display_point;           	//副本展示点	关联路点表，填id使用有亮相的结算类型，不填id使用无结算的类型。
	int display_damage;          	//伤害显示	副本内是否显示伤害累计  1为显示，0或不填为不显示
	int activity_id;             	//活动id	关联的活动id  空或-1则没有关联
	int team_id;                 	//组队界面id	关联的组队界面id （点击组队按钮跳转组队UI用） 空或-1则没有关联
	int team_jump;               	//组队界面跳转	该副本点击挑战按钮是否会跳转到组队界面（副本圆球进入界面） 0：不跳转 1：跳转
	int canuse_blood;            	//是否可用血瓶	龙魂神殿副本不可使用血瓶功能 0或不填：可用 1：不可用

private:

public:

	DungeonElement()
	{
		id = -1;

	}
};

//副本表配置封装类
class DungeonTable
{
	public:
	typedef std::unique_ptr<DungeonElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	DungeonTable();
	~DungeonTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static DungeonTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const DungeonElement* GetElement(int key);

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
