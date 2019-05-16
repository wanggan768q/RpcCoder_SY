#ifndef __CREATURE_CONFIG_H
#define __CREATURE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//总NPC表配置数据结构
struct CreatureElement
{
	friend class CreatureTable;
	int id;                      	//序号	作者: ID段分类： 1,000,000（100W）以上的字段，代表拥有功能性（特殊数值）的怪物 1开头为精英怪，2为世界boss 100W以下的字段，为世界怪物，测试怪物，任务怪物，副本怪物 左边第一个数字，代表场景， 1为人族领地，2为demo副本 3为狼人种族领地，4为奥斯提温 5位马鬃草原野外，6为马鬃草原副本 7为新手村，8为精灵种族领地 9为精灵之森世界，10为精灵之森副本 11为野外战场 左边第三个数字，代表阵营： 0为友善，2为敌对
	string comment;              	//策划备注	策划备注
	string script_ID;            	//脚本ID	脚本ID填写为NPC的ID -1为没有脚本
	int combat_coe_id;           	//战斗系数ID	战斗系数ID
	float leisure_pro;           	//播放休闲动画几率	1=100%
	int combat_attributes_id;    	//战斗属性ID	战斗属性ID
	int temper_id;               	//AI类型ID	关联 CreatureTemperConfig
	int name_id;                 	//名字文本ID	名字文本ID
	int sub_name_id;             	//子名字文本ID	子名字文本ID
	int describe_id;             	//boss简介ID	大概是stringUI
	int model_id;                	//模型id	模型id
	string mapping_path;         	//贴图路径	贴图路径
	float scale;                 	//NPC大小	NPC大小
	float opacity;               	//透明度	透明度
	string icon;                 	//图标路径	图标路径
	int health_bar_display;      	//血条显示	0 不显示 1 挨打时显示 脱战后消失 2 一直显示
	int name_bar_display;        	//名字显示	名字显示
	int creature_level;          	//怪物等级	怪物等级
	int creature_type;           	//怪物类型	1为普通小怪，血条在怪物的头顶 2为精英NPC，血条在怪物的头顶 3为副本boss，血条会显示在屏幕从上往下1/4的位置。 4为技能NPC，不显示在游戏中，用于放区域技能 5为世界NPC，不具有攻击举动 6为血条特殊显示NPC 7为功能性NPC 8为世界boss，位于一般场景，血条显示与副本boss相同 9创建光球特效npc（宠物） 10宠物捕获npc 11跟随类NPC 12保护类NPC 13巡逻类
	string minimap_icon;         	//小地图怪物图标	配置怪物在小地图上显示的图标
	int faction;                 	//阵营	阵营
	int race;                    	//种族	种族
	float walk_speed;            	//走路速度	走路速度
	float run_speed;             	//跑步速度	跑步速度
	int can_be_targeted;         	//是否可以被攻击或选中	是否可以被攻击或选中
	int can_attack;              	//是否可以进行攻击	是否可以进行攻击
	string selected_sound;       	//被选中音效	被选中音效
	string death_sound;          	//死亡音效	死亡音效
	vector<int> initial_skill;   	//NPC的技能数组	关联之后的技能，如果没有技能则不填
	vector<int> weight;          	//技能组中每个技能的权重	跟技能组一一对应，默认权重1
	int special_skill;           	//特殊技能	出生释放技能 （目前只用在宠物抓捕活动）
	vector<int> rebirth_buffs;   	//出生的时候释放buff	出生的时候释放buff
	string verification;         	//技能验证	仅策划用 二进制检验
	int is_wondering;            	//是否在范围内漫步	是否在范围内漫步
	int born_skill;              	//出生技能	关联技能表
	int dead_skill;              	//死亡技能	关联技能表
	int return_back_full_hp;     	//脱战是否回血	默认0回血，1不回血
	int is_play_born_animation;  	//是否需要播放出生动画	是否需要播放出生动画
	int born_anim_duration_buff; 	//出生动画持续时的效果buff ID	出生动画持续时的效果buff ID
	int born_anim_effect_buff;   	//出生动画持续时的时长buff ID	出生动画持续时的时长buff ID
	string born_animation_name;  	//出生动画名称	出生动画名称
	string combat_entry_skill;   	//进入战斗的技能	进入战斗的技能
	int corpse_vanish_time;      	//尸体消失时间	尸体消失时间
	int network_type;            	//掉落广播类型	广播的类型（ 0：只看到自己的掉落表现 1：可以看到自己和队伍成员的掉落表现 2：可以看到自己和团队成员的掉落表现 3：可以看到所有的掉落表现
	int right_choose;            	//掉落权利方式选择	掉落权利判定的类型（ 0：最后一击 1：参与战斗 2：伤害统计）
	int belong_choose;           	//归属选择	归属判定的类型（ 0:个人归属 1：组队归属 2：公会归属）
	vector<int> drop1;           	//掉落1	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop2;           	//掉落2	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop3;           	//掉落3	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop4;           	//掉落4	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	vector<int> drop5;           	//掉落5	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	int conversation_default;    	//默认对话	与NPC交互时触发的默认对话 字幕ID
	vector<int> quest_list;      	//任务列表	与NPC交互时会判断该NPC是否由有任务要接
	vector<int> activitiy_id;    	//活动id	选择该项后触发活动 相当于“前往”功能 关联活动表
	vector<int> ui_id;           	//界面id	选择该项后弹出界面 关联界面t表
	vector<int> teleportfb_id;   	//传送副本id	选择该项后传送至副本 关联Dungeon_副本表
	vector<int> teleport_id;     	//传送id	选择该项后传送至场景 关联teleport_target表
	vector<int> CreatureHide_id; 	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	int CreatureDefaultHide;     	//默认显示隐藏	0为隐藏 1为显示 默认为1

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	CreatureElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//总NPC表配置封装类
class CreatureTable
{
	friend class TableData;
private:
	CreatureTable(){}
	~CreatureTable(){}
	map<int, CreatureElement>	m_mapElements;
	vector<CreatureElement>	m_vecAllElements;
	CreatureElement m_emptyItem;
public:
	static CreatureTable& Instance()
	{
		static CreatureTable sInstance;
		return sInstance;
	}

	CreatureElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("Creature.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Creature.bin", strTableContent ) )
		{
			printf_message("配置文件[Creature.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 59)
		{
			printf_message("Creature.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Creature.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Creature.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="script_ID"){printf_message("Creature.csv中字段[script_ID]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="combat_coe_id"){printf_message("Creature.csv中字段[combat_coe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="leisure_pro"){printf_message("Creature.csv中字段[leisure_pro]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="combat_attributes_id"){printf_message("Creature.csv中字段[combat_attributes_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="temper_id"){printf_message("Creature.csv中字段[temper_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="name_id"){printf_message("Creature.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="sub_name_id"){printf_message("Creature.csv中字段[sub_name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="describe_id"){printf_message("Creature.csv中字段[describe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="model_id"){printf_message("Creature.csv中字段[model_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="mapping_path"){printf_message("Creature.csv中字段[mapping_path]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="scale"){printf_message("Creature.csv中字段[scale]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="opacity"){printf_message("Creature.csv中字段[opacity]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="icon"){printf_message("Creature.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="health_bar_display"){printf_message("Creature.csv中字段[health_bar_display]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="name_bar_display"){printf_message("Creature.csv中字段[name_bar_display]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="creature_level"){printf_message("Creature.csv中字段[creature_level]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="creature_type"){printf_message("Creature.csv中字段[creature_type]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="minimap_icon"){printf_message("Creature.csv中字段[minimap_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="faction"){printf_message("Creature.csv中字段[faction]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="race"){printf_message("Creature.csv中字段[race]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="walk_speed"){printf_message("Creature.csv中字段[walk_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="run_speed"){printf_message("Creature.csv中字段[run_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="can_be_targeted"){printf_message("Creature.csv中字段[can_be_targeted]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="can_attack"){printf_message("Creature.csv中字段[can_attack]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="selected_sound"){printf_message("Creature.csv中字段[selected_sound]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="death_sound"){printf_message("Creature.csv中字段[death_sound]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="initial_skill"){printf_message("Creature.csv中字段[initial_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="weight"){printf_message("Creature.csv中字段[weight]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="special_skill"){printf_message("Creature.csv中字段[special_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="rebirth_buffs"){printf_message("Creature.csv中字段[rebirth_buffs]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="verification"){printf_message("Creature.csv中字段[verification]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="is_wondering"){printf_message("Creature.csv中字段[is_wondering]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="born_skill"){printf_message("Creature.csv中字段[born_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="dead_skill"){printf_message("Creature.csv中字段[dead_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="return_back_full_hp"){printf_message("Creature.csv中字段[return_back_full_hp]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="is_play_born_animation"){printf_message("Creature.csv中字段[is_play_born_animation]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="born_anim_duration_buff"){printf_message("Creature.csv中字段[born_anim_duration_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="born_anim_effect_buff"){printf_message("Creature.csv中字段[born_anim_effect_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="born_animation_name"){printf_message("Creature.csv中字段[born_animation_name]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="combat_entry_skill"){printf_message("Creature.csv中字段[combat_entry_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="corpse_vanish_time"){printf_message("Creature.csv中字段[corpse_vanish_time]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="network_type"){printf_message("Creature.csv中字段[network_type]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="right_choose"){printf_message("Creature.csv中字段[right_choose]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="belong_choose"){printf_message("Creature.csv中字段[belong_choose]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="drop1"){printf_message("Creature.csv中字段[drop1]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="drop2"){printf_message("Creature.csv中字段[drop2]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="drop3"){printf_message("Creature.csv中字段[drop3]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="drop4"){printf_message("Creature.csv中字段[drop4]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="drop5"){printf_message("Creature.csv中字段[drop5]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="conversation_default"){printf_message("Creature.csv中字段[conversation_default]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="quest_list"){printf_message("Creature.csv中字段[quest_list]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="activitiy_id"){printf_message("Creature.csv中字段[activitiy_id]位置不对应 ");assert(false); return false; }
		if(vecLine[54]!="ui_id"){printf_message("Creature.csv中字段[ui_id]位置不对应 ");assert(false); return false; }
		if(vecLine[55]!="teleportfb_id"){printf_message("Creature.csv中字段[teleportfb_id]位置不对应 ");assert(false); return false; }
		if(vecLine[56]!="teleport_id"){printf_message("Creature.csv中字段[teleport_id]位置不对应 ");assert(false); return false; }
		if(vecLine[57]!="CreatureHide_id"){printf_message("Creature.csv中字段[CreatureHide_id]位置不对应 ");assert(false); return false; }
		if(vecLine[58]!="CreatureDefaultHide"){printf_message("Creature.csv中字段[CreatureDefaultHide]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)59)
			{
				assert(false);
				return false;
			}
			CreatureElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.script_ID=vecLine[2];
			member.combat_coe_id=(int)atoi(vecLine[3].c_str());
			member.leisure_pro=(float)atof(vecLine[4].c_str());
			member.combat_attributes_id=(int)atoi(vecLine[5].c_str());
			member.temper_id=(int)atoi(vecLine[6].c_str());
			member.name_id=(int)atoi(vecLine[7].c_str());
			member.sub_name_id=(int)atoi(vecLine[8].c_str());
			member.describe_id=(int)atoi(vecLine[9].c_str());
			member.model_id=(int)atoi(vecLine[10].c_str());
			member.mapping_path=vecLine[11];
			member.scale=(float)atof(vecLine[12].c_str());
			member.opacity=(float)atof(vecLine[13].c_str());
			member.icon=vecLine[14];
			member.health_bar_display=(int)atoi(vecLine[15].c_str());
			member.name_bar_display=(int)atoi(vecLine[16].c_str());
			member.creature_level=(int)atoi(vecLine[17].c_str());
			member.creature_type=(int)atoi(vecLine[18].c_str());
			member.minimap_icon=vecLine[19];
			member.faction=(int)atoi(vecLine[20].c_str());
			member.race=(int)atoi(vecLine[21].c_str());
			member.walk_speed=(float)atof(vecLine[22].c_str());
			member.run_speed=(float)atof(vecLine[23].c_str());
			member.can_be_targeted=(int)atoi(vecLine[24].c_str());
			member.can_attack=(int)atoi(vecLine[25].c_str());
			member.selected_sound=vecLine[26];
			member.death_sound=vecLine[27];
			member.special_skill=(int)atoi(vecLine[30].c_str());
			member.verification=vecLine[32];
			member.is_wondering=(int)atoi(vecLine[33].c_str());
			member.born_skill=(int)atoi(vecLine[34].c_str());
			member.dead_skill=(int)atoi(vecLine[35].c_str());
			member.return_back_full_hp=(int)atoi(vecLine[36].c_str());
			member.is_play_born_animation=(int)atoi(vecLine[37].c_str());
			member.born_anim_duration_buff=(int)atoi(vecLine[38].c_str());
			member.born_anim_effect_buff=(int)atoi(vecLine[39].c_str());
			member.born_animation_name=vecLine[40];
			member.combat_entry_skill=vecLine[41];
			member.corpse_vanish_time=(int)atoi(vecLine[42].c_str());
			member.network_type=(int)atoi(vecLine[43].c_str());
			member.right_choose=(int)atoi(vecLine[44].c_str());
			member.belong_choose=(int)atoi(vecLine[45].c_str());
			member.conversation_default=(int)atoi(vecLine[51].c_str());
			member.CreatureDefaultHide=(int)atoi(vecLine[58].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
