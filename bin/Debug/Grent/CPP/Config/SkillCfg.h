#ifndef __SKILL_CONFIG_H
#define __SKILL_CONFIG_H

#include "BaseDef.h"



using namespace std;

//技能配置数据结构
struct SkillElement
{
	friend class SkillTable;
	int id;                      	//技能ID	1100000~2999999为主角技能预留ID段 1=战士 2=盗贼 3=骑士 4=猎人 5=法师 6=神秘使 7 ~ 71 = 马鬃草原世界
	int name_id;                 	//技能名称ID	关联语言表
	int desc_id;                 	//技能描述ID	
	string comment;              	//技能名称	仅策划用
	int type;                    	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=原应激技能，已废弃，勿填 5=连击技能 6=宠物技能 7=多层技能 8=表情技能 9=死亡技能 10=交互技能
	int buff_count_type;         	//技能类型	用来给专门的buff使用。buff参数填的值，和这里配的值一致，且该技能释放，那么该buff计数1次 1、普通攻击 2、恶意技能 3、善意技能 4、翻滚技能
	int is_prepare;              	//是否是蓄力技能	技能是否是蓄力技能，0不是，1是 是否蓄力
	vector<int> is_prepare_par;  	//蓄力技能参数	蓄力技能参数： 最大蓄力时间|延迟时间|蓄力表中的ID
	string prepare_show;         	//蓄力阶段的展示动作	展示动作，不是蓄力的话填了也没用
	int class_restriction;       	//技能等级限制	需要角色或者怪物超过配置的等级后才能释放这个技能
	int max_stack;               	//最大技能层数	技能层数，若不是多层技能，则填1；若是，则填写最大技能层数
	int max_target_count;        	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	int caster_type;             	//技能释放者对象	技能释放者类型： 0 = 主角 1 = 怪物 2 = 坐骑
	int cast_target;             	//技能施法目标	影响技能释放目标和caster之间的阵营关系判断 0=不需要目标 1=自己 2=敌方单位 3=友方单位 4=敌方+友方 5=友方+自己 6=敌方+友方+自己
	int target_alive_status;     	//技能目标存活类型	0：技能只能对死亡目标生效 1：技能只能对活着的目标生效 2：会对死亡、存活的目标同时生效
	int can_interrupt;           	//能否被打断	0：不能被打断 1：能被打断 （只有NPC技能可被打断，玩家职业技能都无法被打断,默认无法被打断）
	int attack_empty;            	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 0=不允许空放 1=允许空放
	vector<int> former_skill_buff;	//技能释放前施加的buff	表示在attack生效前给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	int extra_former_condition_id;	//额外附加技能前效果条件ID	满足ID对应条件时，给自身额外施加buff 当前只支持主角天赋方向ID，后续待扩展
	vector<int> extra_former_buff;	//额外附加技能前buff	技能刚开始释放时给自身额外施加的附加buff效果ID，多个ID用“|”连接
	vector<int> latter_skill_buff;	//技能释放后施加的buff	表示在技能所有的attack生效后给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	int extra_latter_condition_id;	//额外附加技能后效果条件ID	满足ID对应条件时，给自身额外施加buff 当前只支持主角天赋方向ID，后续待扩展
	vector<int> extra_latter_buff;	//额外附加技能后buff	技能释放结束时给自身额外施加的附加buff效果ID，多个ID用“|”连接
	int cooldown_id;             	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	int cooldown_time;           	//冷却的时间	当技能类型为多层时，该字段表示恢复一层所需时间，其他类型表示正常的技能CD 单位：毫秒
	int common_cd_time;          	//公共CD时间	技能释放后，同冷却ID组的技能会共同按照该技能的公共CD事件进入冷却 单位：毫秒
	int continuity;              	//是否连续技能	0=非连续技能 1=连续技能
	int next_id;                 	//下一段技能ID	"-1"=没有下一段
	vector<int> atk_id_list;     	//普攻技能id随机列	普攻下一段可以播放的普攻id列表，多个技能id用连接符：”|“连结，没有填“-1”
	vector<float> atk_prob_list; 	//普攻技能id随机概率	atk_id_list中对应技能释放的概率，填写小数，多个概率值用连结符：“|”连结，多个概率总和需要等于1。没有填“-1”
	vector<int> skill_normal_all;	//普攻技能ID汇总	
	float attack_range;          	//技能释放距离	技能最大释放距离，显示为技能释放圆形范围
	int show_release;            	//显示技能最大范围提示	只有主角技能有效，是否显示技能范围 0=隐藏 1=显示
	int is_translate;            	//是否位移技能	判断这个技能，被定身后，是否还可以释放，根据类型判断 0：不包含位移，可以放，无影响 1：有translate位移，不能放 2：有translate位移，但是可以放，不能移动而已，战士和骑士的普攻用
	int loop_skill;              	//是否循环	默认为-1，不生效 1为循环技能   目前仅用于处理表情动作
	int rang_type;               	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	float rang_par1;             	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	float rang_par2;             	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	int release_type;            	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形 6=固定距离圆形 7=固定距离矩形 8=目标点连环圆
	string resources_release;    	//释放资源	打目标，无资源，空值 身前直线:SkillRangeStrip 基准点在中心位置的矩形:SkillRangeSquare_001 普通身前矩形:SkillRangeSquare_002 两边带角身前矩形:SkillRangeSquare_003 基准点在圆心位置的圆:SkillRangeCircular 基准点在切边位置的圆:SkillRangeCircular_001 基准点在两圆连接处:SkillRangeCircular_002 身前60度扇形:SkillRangeSector60 身前90度扇形:SkillRangeSector90 身前120度扇形:SkillRangeSector120 身前180度扇形:SkillRangeSector180 基准点在圆心的圆边:SkillRange
	string Resources;            	//动作资源	动作文件
	vector<int> attack_ID;       	//技能编辑器的attackID	仅策划查看用，修改需要在技能编辑器
	string resources_name;       	//对应资源	仅策划用
	string icon;                 	//图标资源	图标资源文件
	int can_break;               	//连击次数	1为是 0为否
	vector<int> repeatedly_skil_list;	//多段技能列表	多段技能列表 默认为空
	vector<float> interval_time; 	//多段技能每次反应的等待时间	多段技能每次等待的反应间隔时间,单位：ms
	int can_be_accelerate;       	//反应时间是否受急速影响	反应时间是否受急速影响，若受影响，则反应时间会受急速属性影响变快或变慢 1：受 0：不受 无需求默认填0
	int max_accumulate;          	//最大积攒能量上限	应激技能能量积攒上限
	int min_accumulate_use;      	//发动应激技能最低能量要求	发动应激技能最低能量数量
	int skill_trigger_type;      	//应激技能触发类型	（空=没有事件，不积攒能量） 1=格挡 2=暴击 3=命中
	float event_addEP;           	//事件增加能量数量	1=1点能量 不足1点用小数
	int skill_expend_point;      	//技能增强点数消耗	用于主角技能 技能可消耗增强点数 具体消耗的点数数值
	string expend_effect_resource;	//增强点特效资源	用于主角技能 技能达到增强点数消耗时 对应该技能位的特效资源
	vector<int> reduce_cd_ski_list;	//减少哪个技能cd	例（3.3.1 灼烧）
	int reduce_cd_type;          	//减少cd类型	1=固定值 2=百分比
	float reduce_cd_parameter;   	//减少cd参数	
	int notice_step_type;        	//提示时机	-1=没有提示 0=施法开始时 1=施法结束时
	int notice_id;               	//文本提示ID	关联文本提示表，没有则填-1
	int continuance;             	//提示消息持续时间	消息持续时间，单位ms，没有则填-1
	string script;               	//脚本名称	script不填的话则没有脚本
	int automation_priority;     	//自动战斗释放优先级	值越高，优先级越高
	vector<int> automation_type; 	//自动战斗技能类型	0：普通技能 1：治疗技能 2：复活技能
	int waiting_message;         	//等待服务器消息	主角技能生效，释放技能是否需要等待服务器消息返回后再开始， 1：需要等待服务器消息 0：客户端自行判断是否可放，不等待服务器消息返回
	vector<int> replace;         	//能否替代	替代技 第一个表示能否替代其他技能，0表示不可以，1表示可以；第二个数值表示能否被其他技能替代，0表示不可以，1表示可以
	int can_insert;              	//	后续技能 1：表示可以加入后续技能 -1：表示不可以加入
	int share_skillcd;           	//翻滚技能共用cd	翻滚技能共用cd，后翻滚技能，在这列，填对应的前翻滚技能ID
	int channel_time;            	//引导的时间(已无效）	已无效 单位：毫秒
	int charge_time;             	//吟唱的时间（已废弃）	单位：毫秒
	int charge_or_interval;      	//伤害段数（已废弃）	在一段时间之内， 释放多少次伤害（BUFF）
	string server_script_id;     	//技能脚本（已废弃）	该技能配置脚本的名称（无用字段）
	int move_limit;              	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离
	int pet_cast_position;       	//宠物释放位置	只有宠物技能使用 宠物在释放技能时的初始位置  0.当前位置 1.瞬间移动至玩家位置 2.瞬间移动至目标位置
	float pet_cast_position_offset;	//宠物释放位置偏移	当宠物释放技能时，该宠物延释放方向的偏移距离 单位米 不填代表无偏移
	int rune_name;               	//铭文名称	该技能对应的铭文名称备份 从stringSkill表中读取 如果不填表示没有铭文
	string rune_icon;            	//铭文图标	该铭文被选中时调用的图标资源
	string rune_icon_normal;     	//铭文默认图标	该铭文未被选中时所调用的图标资源

private:

public:

	SkillElement()
	{
		id = -1;

	}
};

//技能配置封装类
class SkillTable
{
	public:
	typedef std::unique_ptr<SkillElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	SkillTable();
	~SkillTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static SkillTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const SkillElement* GetElement(int key);

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
