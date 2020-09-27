#ifndef __CREATURE_CONFIG_H
#define __CREATURE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//总NPC表配置数据结构
struct CreatureElement
{
	friend class CreatureTable;
	int id;                      	//序号	作者: ID段分类： 1,000,000（100W）以上的字段，代表拥有功能性（特殊数值）的怪物 1开头为精英怪，2为世界boss 100W以下的字段，为世界怪物，测试怪物，任务怪物，副本怪物 左边第一个数字，代表场景， 1为人族领地，2为demo副本 3为狼人种族领地，4为奥斯提姆 5位马鬃草原野外，6为马鬃草原副本 7为新手村，8为精灵种族领地 9为精灵之森世界，10为精灵之森副本 11为野外战场 左边第三个数字，代表阵营： 0为友善，2为敌对
	string comment;              	//策划备注	策划备注
	string script_ID;            	//脚本ID	填写脚本文件所在路径和文件名，没有则为空 脚本路径从Script文件夹开始
	string behaviac;             	//副本行为树	Config/behaviac/下的目录
	int combat_coe_id;           	//战斗系数ID	战斗系数ID
	float leisure_pro;           	//播放休闲动画几率	1=100%
	int combat_attributes_id;    	//战斗属性ID	战斗属性ID
	int temper_id;               	//AI类型ID	关联 CreatureTemperConfig
	int name_id;                 	//名字文本ID	名字文本表 ID
	int title_id;                	//称号ID	关联 StringCreature_NPC文本表
	int name_bar_display;        	//名字显示	（包括title称号） 0 不显示 1 一直显示 2 挨打时显示，脱战后消失
	vector<int> npcintroduec_id; 	//NPC剧情介绍文本	关联 StringCreature_NPC文本表 第1行文本|第2行文本|第3行文本 如果只想显示2、3行，则不显示的行填-1 都不显示则空着即可
	int describe_id;             	//boss简介ID	大概是stringUI
	int model_id;                	//模型id	模型id
	string mapping_path;         	//贴图路径	贴图路径
	float scale;                 	//NPC大小	NPC大小
	float opacity;               	//透明度	透明度
	string minimap_icon;         	//小地图怪物图标	配置怪物在小地图上显示的图标
	int minimap_name;            	//小地图左侧名字显示	显示对应图标的名字
	string icon;                 	//图标路径	界面上的图标
	string head_icon;            	//头顶图标	头顶的功能图标路径，配了才显示，不配不显示 显示优先级低于任务头顶提示
	int creature_level;          	//怪物等级	怪物等级
	int level_type;              	//等级类型	0、不填：正常配置 1：队伍最高等级 2：队伍最低等级 3：队伍平均等级
	int creature_type;           	//怪物类型	1为普通小怪，血条在怪物的头顶 2为精英NPC，血条在怪物的头顶 3为副本boss 4为技能NPC，不显示在游戏中，用于放区域技能 5为世界NPC，不具有攻击举动 6为血条特殊显示NPC 7为功能性NPC 8为世界boss，位于一般场景，血条显示与副本boss相同 9创建光球特效npc（宠物） 10宠物捕获npc 11跟随类NPC 12保护类NPC 13巡逻类 14公会BOSS 15召唤类宝宝，弓箭手的召唤狼用 16坐骑捕获npc 17世界精英npc 18挂机怪 19可交互怪（QTE踢雪球）
	int health_type;             	//血条样式	10小怪 20精英怪 关联HeadHealthres_头顶血条资源表id，必填字段，否则显示时报错 配表公式参照“血条类型对照”页签自动生成结果
	int health_hud_display;      	//顶部血条显示	不填：不显示顶部血条 1：显示顶部血条  
	int health_bar_display;      	//血条显示	0 不显示 1 挨打时显示 脱战后消失 2 一直显示
	int display_priority;        	//血条显示优先级	默认不填
	int hp_level;                	//多条血条	怪物血条数目
	int faction;                 	//阵营	阵营
	int race;                    	//种族	种族
	int move_mode;               	//初始移动类型	0-初始走路 1-初始跑步
	float normal_walk_speed;     	//走路速度	走路速度（暂未实现）
	float walk_speed;            	//跑步速度	跑步速度
	float run_speed;             	//战斗跑步速度	战斗跑步速度
	int can_be_selected;         	//是否可以被选中	是否可以被选中 0:不可被选中 1:可以被选中
	int can_be_attacked;         	//是否可以被攻击	是否可以被攻击 0:不可被攻击 1:可以被攻击
	int can_attack;              	//是否可以进行攻击	是否可以进行攻击
	string selected_sound;       	//被选中音效	被选中音效
	string death_sound;          	//死亡音效	死亡音效
	vector<int> initial_skill;   	//NPC的技能数组	关联之后的技能，如果没有技能则不填 技能顺序按照技能CD依次排序
	vector<int> weight;          	//技能组中每个技能的权重	跟技能组一一对应，默认权重1
	int special_skill;           	//特殊技能	出生释放技能 （目前只用在宠物抓捕活动）
	vector<int> rebirth_buffs;   	//出生的时候释放buff	出生的时候释放buff
	string verification;         	//技能验证	仅策划用 二进制检验
	int is_wondering;            	//是否在范围内漫步	是否在范围内漫步
	int born_skill;              	//出生技能	关联技能表
	int dead_skill;              	//死亡技能	关联技能表
	string sound_die;            	//死亡音效	声音文件名
	vector<string> footsteps_list_run;	//跑步音效	声音文件名  填写格式  soundname1|soundname2|soundname3 对应的三个天气，分别是雨雪正常天、如不需区分三个填写相同文件
	vector<string> footsteps_list_dash;	//快跑音效	声音文件名  填写格式  soundname1|soundname2|soundname3 对应的三个天气，分别是雨雪正常天、如不需区分三个填写相同文件
	string footsteps_par;        	//参数	预留参数控制，暂时无用
	string sound_hit;            	//受击音效	声音文件名
	string combat_entry_sound;   	//进入战斗的音效	进入战斗的音效
	string combat_entry_BGM;     	//进入战斗的BGM	进入战斗的BGM
	int return_back_full_hp;     	//脱战是否回血	默认0回血，1不回血
	string combat_entry_skill;   	//进入战斗的技能	进入战斗的技能
	int corpse_vanish_time;      	//尸体消失时间	尸体消失时间
	int corpse_dissolve_time;    	//死亡后多久开始消融	死亡后多久开始消融
	int fade_in_delay;           	//渐现延迟	调用消失之后,多久开始渐现 单位为毫秒 使用本功能,需新增NPC,并将NPC默认刷新状态改为默认隐藏(0) 0:立即开始渐现 -1:本参数不生效
	int fade_in_duration;        	//渐现过程时长	渐现过程时长 单位为毫秒 0,-1:本参数不生效,NPC为立即出现
	int fade_out_delay;          	//渐隐延迟	调用消失之后,多久开始渐隐 单位为毫秒 0:立即开始渐隐 -1:本参数不生效
	int fade_out_duration;       	//渐隐过程时长	渐隐过程时长 单位为毫秒 默认建议配为1000 0,-1:本参数不生效,NPC为立即消失
	int fade_out_point;          	//渐隐时跑向的路点	用于配置启动渐隐时,NPC走向的路点ID 当配置为0,-1时不生效 
	float fade_run_speed;        	//渐隐时跑向路点的速度	用于配置启动渐隐时,NPC走向的路点的速度 当前方未配置消失路点时,本参数无效,NPC不移动 当前方配置有效路点,且配置参数≤0时候,NPC使用walk_speed的默认速度
	int fade_isrun;              	//渐隐时是否用跑动作移动	
	int quest_choose;            	//任务计数方式选择	0  最后一击 1  参与战斗（在仇恨列表里）
	int network_type;            	//掉落广播类型	广播的类型（ 0：只看到自己的掉落表现 1：可以看到自己和队伍成员的掉落表现 2：可以看到自己和团队成员的掉落表现 3：可以看到所有的掉落表现
	int right_choose;            	//掉落权利方式选择	掉落权利判定的类型（ 0：最后一击 1：参与战斗 2：伤害统计 3：场景内均获得）
	int belong_choose;           	//归属选择	归属判定的类型（ 0:个人归属 1：组队归属（掉落权利不能填“参与战斗”） 2：公会归属） 3：挂机野怪归属
	vector<int> drop1;           	//掉落1	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop2;           	//掉落2	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop3;           	//掉落3	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop4;           	//掉落4	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop5;           	//掉落5	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	int is_double;               	//是否使用双倍经验	0：不使用 1：使用
	int conversation_default;    	//默认对话	与NPC交互时触发的默认对话 字幕ID    任务对话表ID 0:没有对话 ID:chatmenu表中的Id
	vector<int> quest_list;      	//任务列表	与NPC交互时会判断该NPC是否由有任务要接
	vector<int> activitiy_id;    	//活动id	选择该项后触发活动 相当于“前往”功能 关联活动表
	vector<int> ui_id;           	//界面id	选择该项后弹出界面 关联界面t表
	vector<int> teleportfb_id;   	//传送副本id	选择该项后传送至副本 关联Dungeon_副本表
	vector<int> teleport_id;     	//传送id	选择该项后传送至场景 关联teleport_target表
	vector<int> CreatureHide_id; 	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	int CreatureDefaultHide;     	//默认显示隐藏	0为隐藏 1为显示 默认为1
	int quick_uicategory_id;     	//快速打开UI界面	关联"UICategory_界面类型"表里的id -1或不填为不调用此功能
	vector<int> first_mission;   	//有指定任务不扣奖励次数	身上有通关某副本的任务时，获得掉落不扣除次数，没有次数时额外获得一次奖励。 填数组，第一位任务id，第二位步骤数
	int sub_name_id;             	//子名字文本ID	子名字文本ID
	vector<int> ActionEvent;     	//动画事件表id	替换动作用这个，得改状态机
	int FuncBelong;              	//可见归属	用来做显示隐藏的属性 用脚本来控制是否可见 0或不配则标识所有人可见 1表示仅自己可见 2表示仅队友/团队可见 3空着没意义 4表示仅当前公会可见
	int Shout;                   	//怪物冒泡	用于配置怪物冒泡喊话 填入Shout_喊话表中的ID
	int material_hit_sound_type; 	//材质受击音效类型	影响受击后播放什么材质的受击音效 0：肉体 1：木头 2：石头 3：金属 4：幽灵 5：骨头 
	int Title_display;           	//title组件的显示和隐藏	性能优化部分，用于前端是否需要计算显示title组件 不填或者0：不显示title组件 1：显示title组件  
	float interact_duration;     	//交互读条时间	玩家点击交互按钮后，读条需要的时间，秒
	string icon_path;            	//交互图标路径	2D资源路径
	string interact_skill_id;    	//自定义交互动作	与怪物交互时播放的动作（仅自己能看见），名称在技能编辑器中的action文件处查询
	int is_death_type;           	//怪物死亡后是否显示特殊效果	对应效果见attack表 0：常规消融 1：显示特殊死亡效果
	vector<float> camo_channel_1;	//NPC换色通道1	NPC换色参数 格式为R|G|B 取值范围0-255
	vector<float> camo_channel_2;	//NPC换色通道2	NPC换色参数 格式为R|G|B 取值范围0-255
	vector<float> camo_channel_3;	//NPC换色通道3	NPC换色参数 格式为R|G|B 取值范围0-255
	vector<float> camo_channel_4;	//NPC换色通道4	NPC换色参数 格式为R|G|B 取值范围0-255

private:

public:

	CreatureElement()
	{
		id = -1;

	}
};

//总NPC表配置封装类
class CreatureTable
{
	public:
	typedef std::unique_ptr<CreatureElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreatureTable();
	~CreatureTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreatureTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreatureElement* GetElement(int key);

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
