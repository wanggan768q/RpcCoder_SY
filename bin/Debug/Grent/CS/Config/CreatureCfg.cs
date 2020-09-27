using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//总NPC表配置数据类
public class CreatureElement
{
	public int id;               	//序号	作者: ID段分类： 1,000,000（100W）以上的字段，代表拥有功能性（特殊数值）的怪物 1开头为精英怪，2为世界boss 100W以下的字段，为世界怪物，测试怪物，任务怪物，副本怪物 左边第一个数字，代表场景， 1为人族领地，2为demo副本 3为狼人种族领地，4为奥斯提姆 5位马鬃草原野外，6为马鬃草原副本 7为新手村，8为精灵种族领地 9为精灵之森世界，10为精灵之森副本 11为野外战场 左边第三个数字，代表阵营： 0为友善，2为敌对
	public string script_ID;     	//脚本ID	填写脚本文件所在路径和文件名，没有则为空 脚本路径从Script文件夹开始
	public string behaviac;      	//副本行为树	Config/behaviac/下的目录
	public int combat_coe_id;    	//战斗系数ID	战斗系数ID
	public float leisure_pro;    	//播放休闲动画几率	1=100%
	public int combat_attributes_id;	//战斗属性ID	战斗属性ID
	public int temper_id;        	//AI类型ID	关联 CreatureTemperConfig
	public int name_id;          	//名字文本ID	名字文本表 ID
	public int title_id;         	//称号ID	关联 StringCreature_NPC文本表
	public int name_bar_display; 	//名字显示	（包括title称号） 0 不显示 1 一直显示 2 挨打时显示，脱战后消失
	public li npcintroduec_id;   	//NPC剧情介绍文本	关联 StringCreature_NPC文本表 第1行文本|第2行文本|第3行文本 如果只想显示2、3行，则不显示的行填-1 都不显示则空着即可
	public int describe_id;      	//boss简介ID	大概是stringUI
	public int model_id;         	//模型id	模型id
	public string mapping_path;  	//贴图路径	贴图路径
	public float scale;          	//NPC大小	NPC大小
	public float opacity;        	//透明度	透明度
	public string minimap_icon;  	//小地图怪物图标	配置怪物在小地图上显示的图标
	public int minimap_name;     	//小地图左侧名字显示	显示对应图标的名字
	public string icon;          	//图标路径	界面上的图标
	public string head_icon;     	//头顶图标	头顶的功能图标路径，配了才显示，不配不显示 显示优先级低于任务头顶提示
	public int creature_level;   	//怪物等级	怪物等级
	public int level_type;       	//等级类型	0、不填：正常配置 1：队伍最高等级 2：队伍最低等级 3：队伍平均等级
	public int creature_type;    	//怪物类型	1为普通小怪，血条在怪物的头顶 2为精英NPC，血条在怪物的头顶 3为副本boss 4为技能NPC，不显示在游戏中，用于放区域技能 5为世界NPC，不具有攻击举动 6为血条特殊显示NPC 7为功能性NPC 8为世界boss，位于一般场景，血条显示与副本boss相同 9创建光球特效npc（宠物） 10宠物捕获npc 11跟随类NPC 12保护类NPC 13巡逻类 14公会BOSS 15召唤类宝宝，弓箭手的召唤狼用 16坐骑捕获npc 17世界精英npc 18挂机怪 19可交互怪（QTE踢雪球）
	public int health_type;      	//血条样式	10小怪 20精英怪 关联HeadHealthres_头顶血条资源表id，必填字段，否则显示时报错 配表公式参照“血条类型对照”页签自动生成结果
	public int health_hud_display;	//顶部血条显示	不填：不显示顶部血条 1：显示顶部血条  
	public int health_bar_display;	//血条显示	0 不显示 1 挨打时显示 脱战后消失 2 一直显示
	public int display_priority; 	//血条显示优先级	默认不填
	public int hp_level;         	//多条血条	怪物血条数目
	public int faction;          	//阵营	阵营
	public int race;             	//种族	种族
	public int move_mode;        	//初始移动类型	0-初始走路 1-初始跑步
	public float normal_walk_speed;	//走路速度	走路速度（暂未实现）
	public float walk_speed;     	//跑步速度	跑步速度
	public float run_speed;      	//战斗跑步速度	战斗跑步速度
	public int can_be_selected;  	//是否可以被选中	是否可以被选中 0:不可被选中 1:可以被选中
	public int can_be_attacked;  	//是否可以被攻击	是否可以被攻击 0:不可被攻击 1:可以被攻击
	public int can_attack;       	//是否可以进行攻击	是否可以进行攻击
	public string selected_sound;	//被选中音效	被选中音效
	public string death_sound;   	//死亡音效	死亡音效
	public li initial_skill;     	//NPC的技能数组	关联之后的技能，如果没有技能则不填 技能顺序按照技能CD依次排序
	public li weight;            	//技能组中每个技能的权重	跟技能组一一对应，默认权重1
	public int special_skill;    	//特殊技能	出生释放技能 （目前只用在宠物抓捕活动）
	public li rebirth_buffs;     	//出生的时候释放buff	出生的时候释放buff
	public string verification;  	//技能验证	仅策划用 二进制检验
	public int is_wondering;     	//是否在范围内漫步	是否在范围内漫步
	public int born_skill;       	//出生技能	关联技能表
	public int dead_skill;       	//死亡技能	关联技能表
	public string sound_die;     	//死亡音效	声音文件名
	public ls footsteps_list_run;	//跑步音效	声音文件名  填写格式  soundname1|soundname2|soundname3 对应的三个天气，分别是雨雪正常天、如不需区分三个填写相同文件
	public ls footsteps_list_dash;	//快跑音效	声音文件名  填写格式  soundname1|soundname2|soundname3 对应的三个天气，分别是雨雪正常天、如不需区分三个填写相同文件
	public string footsteps_par; 	//参数	预留参数控制，暂时无用
	public string sound_hit;     	//受击音效	声音文件名
	public string combat_entry_sound;	//进入战斗的音效	进入战斗的音效
	public string combat_entry_BGM;	//进入战斗的BGM	进入战斗的BGM
	public int return_back_full_hp;	//脱战是否回血	默认0回血，1不回血
	public string combat_entry_skill;	//进入战斗的技能	进入战斗的技能
	public int corpse_vanish_time;	//尸体消失时间	尸体消失时间
	public int corpse_dissolve_time;	//死亡后多久开始消融	死亡后多久开始消融
	public int fade_in_delay;    	//渐现延迟	调用消失之后,多久开始渐现 单位为毫秒 使用本功能,需新增NPC,并将NPC默认刷新状态改为默认隐藏(0) 0:立即开始渐现 -1:本参数不生效
	public int fade_in_duration; 	//渐现过程时长	渐现过程时长 单位为毫秒 0,-1:本参数不生效,NPC为立即出现
	public int fade_out_delay;   	//渐隐延迟	调用消失之后,多久开始渐隐 单位为毫秒 0:立即开始渐隐 -1:本参数不生效
	public int fade_out_duration;	//渐隐过程时长	渐隐过程时长 单位为毫秒 默认建议配为1000 0,-1:本参数不生效,NPC为立即消失
	public int fade_out_point;   	//渐隐时跑向的路点	用于配置启动渐隐时,NPC走向的路点ID 当配置为0,-1时不生效 
	public float fade_run_speed; 	//渐隐时跑向路点的速度	用于配置启动渐隐时,NPC走向的路点的速度 当前方未配置消失路点时,本参数无效,NPC不移动 当前方配置有效路点,且配置参数≤0时候,NPC使用walk_speed的默认速度
	public int fade_isrun;       	//渐隐时是否用跑动作移动	
	public int quest_choose;     	//任务计数方式选择	0  最后一击 1  参与战斗（在仇恨列表里）
	public int network_type;     	//掉落广播类型	广播的类型（ 0：只看到自己的掉落表现 1：可以看到自己和队伍成员的掉落表现 2：可以看到自己和团队成员的掉落表现 3：可以看到所有的掉落表现
	public int right_choose;     	//掉落权利方式选择	掉落权利判定的类型（ 0：最后一击 1：参与战斗 2：伤害统计 3：场景内均获得）
	public int belong_choose;    	//归属选择	归属判定的类型（ 0:个人归属 1：组队归属（掉落权利不能填“参与战斗”） 2：公会归属） 3：挂机野怪归属
	public li drop1;             	//掉落1	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop2;             	//掉落2	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop3;             	//掉落3	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop4;             	//掉落4	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop5;             	//掉落5	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public int is_double;        	//是否使用双倍经验	0：不使用 1：使用
	public int conversation_default;	//默认对话	与NPC交互时触发的默认对话 字幕ID    任务对话表ID 0:没有对话 ID:chatmenu表中的Id
	public li quest_list;        	//任务列表	与NPC交互时会判断该NPC是否由有任务要接
	public li activitiy_id;      	//活动id	选择该项后触发活动 相当于“前往”功能 关联活动表
	public li ui_id;             	//界面id	选择该项后弹出界面 关联界面t表
	public li teleportfb_id;     	//传送副本id	选择该项后传送至副本 关联Dungeon_副本表
	public li teleport_id;       	//传送id	选择该项后传送至场景 关联teleport_target表
	public li CreatureHide_id;   	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	public int CreatureDefaultHide;	//默认显示隐藏	0为隐藏 1为显示 默认为1
	public int quick_uicategory_id;	//快速打开UI界面	关联"UICategory_界面类型"表里的id -1或不填为不调用此功能
	public li first_mission;     	//有指定任务不扣奖励次数	身上有通关某副本的任务时，获得掉落不扣除次数，没有次数时额外获得一次奖励。 填数组，第一位任务id，第二位步骤数
	public int sub_name_id;      	//子名字文本ID	子名字文本ID
	public li ActionEvent;       	//动画事件表id	替换动作用这个，得改状态机
	public int FuncBelong;       	//可见归属	用来做显示隐藏的属性 用脚本来控制是否可见 0或不配则标识所有人可见 1表示仅自己可见 2表示仅队友/团队可见 3空着没意义 4表示仅当前公会可见
	public int Shout;            	//怪物冒泡	用于配置怪物冒泡喊话 填入Shout_喊话表中的ID
	public int material_hit_sound_type;	//材质受击音效类型	影响受击后播放什么材质的受击音效 0：肉体 1：木头 2：石头 3：金属 4：幽灵 5：骨头 
	public int Title_display;    	//title组件的显示和隐藏	性能优化部分，用于前端是否需要计算显示title组件 不填或者0：不显示title组件 1：显示title组件  
	public float interact_duration;	//交互读条时间	玩家点击交互按钮后，读条需要的时间，秒
	public string icon_path;     	//交互图标路径	2D资源路径
	public string interact_skill_id;	//自定义交互动作	与怪物交互时播放的动作（仅自己能看见），名称在技能编辑器中的action文件处查询
	public int is_death_type;    	//怪物死亡后是否显示特殊效果	对应效果见attack表 0：常规消融 1：显示特殊死亡效果
	public lf camo_channel_1;    	//NPC换色通道1	NPC换色参数 格式为R|G|B 取值范围0-255
	public lf camo_channel_2;    	//NPC换色通道2	NPC换色参数 格式为R|G|B 取值范围0-255
	public lf camo_channel_3;    	//NPC换色通道3	NPC换色参数 格式为R|G|B 取值范围0-255
	public lf camo_channel_4;    	//NPC换色通道4	NPC换色参数 格式为R|G|B 取值范围0-255

	public bool IsValidate = false;
	public CreatureElement()
	{
		id = -1;
	}
};

//总NPC表配置封装类
public class CreatureTable
{

	private CreatureTable()
	{
		m_mapElements = new Dictionary<int, CreatureElement>();
		m_emptyItem = new CreatureElement();
		m_vecAllElements = new List<CreatureElement>();
	}
	private Dictionary<int, CreatureElement> m_mapElements = null;
	private List<CreatureElement>	m_vecAllElements = null;
	private CreatureElement m_emptyItem = null;
	private static CreatureTable sInstance = null;

	public static CreatureTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureTable();
			return sInstance;
		}
	}

	public CreatureElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<CreatureElement> GetAllElement(Predicate<CreatureElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Creature.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Creature.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Creature.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 99)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Creature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[2]!="behaviac"){Ex.Logger.Log("Creature.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[3]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[4]!="leisure_pro"){Ex.Logger.Log("Creature.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[5]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[6]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[7]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[8]!="title_id"){Ex.Logger.Log("Creature.csv中字段[title_id]位置不对应"); return false; }
		if(vecLine[9]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[10]!="npcintroduec_id"){Ex.Logger.Log("Creature.csv中字段[npcintroduec_id]位置不对应"); return false; }
		if(vecLine[11]!="describe_id"){Ex.Logger.Log("Creature.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[12]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[13]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[14]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[15]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[16]!="minimap_icon"){Ex.Logger.Log("Creature.csv中字段[minimap_icon]位置不对应"); return false; }
		if(vecLine[17]!="minimap_name"){Ex.Logger.Log("Creature.csv中字段[minimap_name]位置不对应"); return false; }
		if(vecLine[18]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[19]!="head_icon"){Ex.Logger.Log("Creature.csv中字段[head_icon]位置不对应"); return false; }
		if(vecLine[20]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[21]!="level_type"){Ex.Logger.Log("Creature.csv中字段[level_type]位置不对应"); return false; }
		if(vecLine[22]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[23]!="health_type"){Ex.Logger.Log("Creature.csv中字段[health_type]位置不对应"); return false; }
		if(vecLine[24]!="health_hud_display"){Ex.Logger.Log("Creature.csv中字段[health_hud_display]位置不对应"); return false; }
		if(vecLine[25]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[26]!="display_priority"){Ex.Logger.Log("Creature.csv中字段[display_priority]位置不对应"); return false; }
		if(vecLine[27]!="hp_level"){Ex.Logger.Log("Creature.csv中字段[hp_level]位置不对应"); return false; }
		if(vecLine[28]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[29]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[30]!="move_mode"){Ex.Logger.Log("Creature.csv中字段[move_mode]位置不对应"); return false; }
		if(vecLine[31]!="normal_walk_speed"){Ex.Logger.Log("Creature.csv中字段[normal_walk_speed]位置不对应"); return false; }
		if(vecLine[32]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[33]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[34]!="can_be_selected"){Ex.Logger.Log("Creature.csv中字段[can_be_selected]位置不对应"); return false; }
		if(vecLine[35]!="can_be_attacked"){Ex.Logger.Log("Creature.csv中字段[can_be_attacked]位置不对应"); return false; }
		if(vecLine[36]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[37]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[38]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[39]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[40]!="weight"){Ex.Logger.Log("Creature.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[41]!="special_skill"){Ex.Logger.Log("Creature.csv中字段[special_skill]位置不对应"); return false; }
		if(vecLine[42]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[43]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[44]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[45]!="born_skill"){Ex.Logger.Log("Creature.csv中字段[born_skill]位置不对应"); return false; }
		if(vecLine[46]!="dead_skill"){Ex.Logger.Log("Creature.csv中字段[dead_skill]位置不对应"); return false; }
		if(vecLine[47]!="sound_die"){Ex.Logger.Log("Creature.csv中字段[sound_die]位置不对应"); return false; }
		if(vecLine[48]!="footsteps_list_run"){Ex.Logger.Log("Creature.csv中字段[footsteps_list_run]位置不对应"); return false; }
		if(vecLine[49]!="footsteps_list_dash"){Ex.Logger.Log("Creature.csv中字段[footsteps_list_dash]位置不对应"); return false; }
		if(vecLine[50]!="footsteps_par"){Ex.Logger.Log("Creature.csv中字段[footsteps_par]位置不对应"); return false; }
		if(vecLine[51]!="sound_hit"){Ex.Logger.Log("Creature.csv中字段[sound_hit]位置不对应"); return false; }
		if(vecLine[52]!="combat_entry_sound"){Ex.Logger.Log("Creature.csv中字段[combat_entry_sound]位置不对应"); return false; }
		if(vecLine[53]!="combat_entry_BGM"){Ex.Logger.Log("Creature.csv中字段[combat_entry_BGM]位置不对应"); return false; }
		if(vecLine[54]!="return_back_full_hp"){Ex.Logger.Log("Creature.csv中字段[return_back_full_hp]位置不对应"); return false; }
		if(vecLine[55]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[56]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }
		if(vecLine[57]!="corpse_dissolve_time"){Ex.Logger.Log("Creature.csv中字段[corpse_dissolve_time]位置不对应"); return false; }
		if(vecLine[58]!="fade_in_delay"){Ex.Logger.Log("Creature.csv中字段[fade_in_delay]位置不对应"); return false; }
		if(vecLine[59]!="fade_in_duration"){Ex.Logger.Log("Creature.csv中字段[fade_in_duration]位置不对应"); return false; }
		if(vecLine[60]!="fade_out_delay"){Ex.Logger.Log("Creature.csv中字段[fade_out_delay]位置不对应"); return false; }
		if(vecLine[61]!="fade_out_duration"){Ex.Logger.Log("Creature.csv中字段[fade_out_duration]位置不对应"); return false; }
		if(vecLine[62]!="fade_out_point"){Ex.Logger.Log("Creature.csv中字段[fade_out_point]位置不对应"); return false; }
		if(vecLine[63]!="fade_run_speed"){Ex.Logger.Log("Creature.csv中字段[fade_run_speed]位置不对应"); return false; }
		if(vecLine[64]!="fade_isrun"){Ex.Logger.Log("Creature.csv中字段[fade_isrun]位置不对应"); return false; }
		if(vecLine[65]!="quest_choose"){Ex.Logger.Log("Creature.csv中字段[quest_choose]位置不对应"); return false; }
		if(vecLine[66]!="network_type"){Ex.Logger.Log("Creature.csv中字段[network_type]位置不对应"); return false; }
		if(vecLine[67]!="right_choose"){Ex.Logger.Log("Creature.csv中字段[right_choose]位置不对应"); return false; }
		if(vecLine[68]!="belong_choose"){Ex.Logger.Log("Creature.csv中字段[belong_choose]位置不对应"); return false; }
		if(vecLine[69]!="drop1"){Ex.Logger.Log("Creature.csv中字段[drop1]位置不对应"); return false; }
		if(vecLine[70]!="drop2"){Ex.Logger.Log("Creature.csv中字段[drop2]位置不对应"); return false; }
		if(vecLine[71]!="drop3"){Ex.Logger.Log("Creature.csv中字段[drop3]位置不对应"); return false; }
		if(vecLine[72]!="drop4"){Ex.Logger.Log("Creature.csv中字段[drop4]位置不对应"); return false; }
		if(vecLine[73]!="drop5"){Ex.Logger.Log("Creature.csv中字段[drop5]位置不对应"); return false; }
		if(vecLine[74]!="is_double"){Ex.Logger.Log("Creature.csv中字段[is_double]位置不对应"); return false; }
		if(vecLine[75]!="conversation_default"){Ex.Logger.Log("Creature.csv中字段[conversation_default]位置不对应"); return false; }
		if(vecLine[76]!="quest_list"){Ex.Logger.Log("Creature.csv中字段[quest_list]位置不对应"); return false; }
		if(vecLine[77]!="activitiy_id"){Ex.Logger.Log("Creature.csv中字段[activitiy_id]位置不对应"); return false; }
		if(vecLine[78]!="ui_id"){Ex.Logger.Log("Creature.csv中字段[ui_id]位置不对应"); return false; }
		if(vecLine[79]!="teleportfb_id"){Ex.Logger.Log("Creature.csv中字段[teleportfb_id]位置不对应"); return false; }
		if(vecLine[80]!="teleport_id"){Ex.Logger.Log("Creature.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[81]!="CreatureHide_id"){Ex.Logger.Log("Creature.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[82]!="CreatureDefaultHide"){Ex.Logger.Log("Creature.csv中字段[CreatureDefaultHide]位置不对应"); return false; }
		if(vecLine[83]!="quick_uicategory_id"){Ex.Logger.Log("Creature.csv中字段[quick_uicategory_id]位置不对应"); return false; }
		if(vecLine[84]!="first_mission"){Ex.Logger.Log("Creature.csv中字段[first_mission]位置不对应"); return false; }
		if(vecLine[85]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[86]!="ActionEvent"){Ex.Logger.Log("Creature.csv中字段[ActionEvent]位置不对应"); return false; }
		if(vecLine[87]!="FuncBelong"){Ex.Logger.Log("Creature.csv中字段[FuncBelong]位置不对应"); return false; }
		if(vecLine[88]!="Shout"){Ex.Logger.Log("Creature.csv中字段[Shout]位置不对应"); return false; }
		if(vecLine[89]!="material_hit_sound_type"){Ex.Logger.Log("Creature.csv中字段[material_hit_sound_type]位置不对应"); return false; }
		if(vecLine[90]!="Title_display"){Ex.Logger.Log("Creature.csv中字段[Title_display]位置不对应"); return false; }
		if(vecLine[91]!="interact_duration"){Ex.Logger.Log("Creature.csv中字段[interact_duration]位置不对应"); return false; }
		if(vecLine[92]!="icon_path"){Ex.Logger.Log("Creature.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[93]!="interact_skill_id"){Ex.Logger.Log("Creature.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[94]!="is_death_type"){Ex.Logger.Log("Creature.csv中字段[is_death_type]位置不对应"); return false; }
		if(vecLine[95]!="camo_channel_1"){Ex.Logger.Log("Creature.csv中字段[camo_channel_1]位置不对应"); return false; }
		if(vecLine[96]!="camo_channel_2"){Ex.Logger.Log("Creature.csv中字段[camo_channel_2]位置不对应"); return false; }
		if(vecLine[97]!="camo_channel_3"){Ex.Logger.Log("Creature.csv中字段[camo_channel_3]位置不对应"); return false; }
		if(vecLine[98]!="camo_channel_4"){Ex.Logger.Log("Creature.csv中字段[camo_channel_4]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureElement member = new CreatureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script_ID);
			readPos += GameAssist.ReadString( binContent, readPos, out member.behaviac);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_coe_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.leisure_pro);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_attributes_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.temper_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.title_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_bar_display );
			readPos += GameAssist.ReadString( binContent, readPos, out member.npcintroduec_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mapping_path);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.scale);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.opacity);
			readPos += GameAssist.ReadString( binContent, readPos, out member.minimap_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.minimap_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.head_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.health_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.health_hud_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.health_bar_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.display_priority );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hp_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.faction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.move_mode );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.normal_walk_speed);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.walk_speed);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.run_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_selected );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_attacked );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_attack );
			readPos += GameAssist.ReadString( binContent, readPos, out member.selected_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.death_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.initial_skill);
			readPos += GameAssist.ReadString( binContent, readPos, out member.weight);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.special_skill );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rebirth_buffs);
			readPos += GameAssist.ReadString( binContent, readPos, out member.verification);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_wondering );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.born_skill );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dead_skill );
			readPos += GameAssist.ReadString( binContent, readPos, out member.sound_die);
			readPos += GameAssist.ReadString( binContent, readPos, out member.footsteps_list_run);
			readPos += GameAssist.ReadString( binContent, readPos, out member.footsteps_list_dash);
			readPos += GameAssist.ReadString( binContent, readPos, out member.footsteps_par);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sound_hit);
			readPos += GameAssist.ReadString( binContent, readPos, out member.combat_entry_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.combat_entry_BGM);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.return_back_full_hp );
			readPos += GameAssist.ReadString( binContent, readPos, out member.combat_entry_skill);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.corpse_vanish_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.corpse_dissolve_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_in_delay );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_in_duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_out_delay );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_out_duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_out_point );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fade_run_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fade_isrun );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_choose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.network_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.right_choose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.belong_choose );
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop5);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_double );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.conversation_default );
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.activitiy_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleportfb_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleport_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.CreatureHide_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CreatureDefaultHide );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quick_uicategory_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_mission);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sub_name_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ActionEvent);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.FuncBelong );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Shout );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.material_hit_sound_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Title_display );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.interact_duration);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon_path);
			readPos += GameAssist.ReadString( binContent, readPos, out member.interact_skill_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_death_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.camo_channel_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.camo_channel_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.camo_channel_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.camo_channel_4);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 99)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Creature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[2]!="behaviac"){Ex.Logger.Log("Creature.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[3]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[4]!="leisure_pro"){Ex.Logger.Log("Creature.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[5]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[6]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[7]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[8]!="title_id"){Ex.Logger.Log("Creature.csv中字段[title_id]位置不对应"); return false; }
		if(vecLine[9]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[10]!="npcintroduec_id"){Ex.Logger.Log("Creature.csv中字段[npcintroduec_id]位置不对应"); return false; }
		if(vecLine[11]!="describe_id"){Ex.Logger.Log("Creature.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[12]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[13]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[14]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[15]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[16]!="minimap_icon"){Ex.Logger.Log("Creature.csv中字段[minimap_icon]位置不对应"); return false; }
		if(vecLine[17]!="minimap_name"){Ex.Logger.Log("Creature.csv中字段[minimap_name]位置不对应"); return false; }
		if(vecLine[18]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[19]!="head_icon"){Ex.Logger.Log("Creature.csv中字段[head_icon]位置不对应"); return false; }
		if(vecLine[20]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[21]!="level_type"){Ex.Logger.Log("Creature.csv中字段[level_type]位置不对应"); return false; }
		if(vecLine[22]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[23]!="health_type"){Ex.Logger.Log("Creature.csv中字段[health_type]位置不对应"); return false; }
		if(vecLine[24]!="health_hud_display"){Ex.Logger.Log("Creature.csv中字段[health_hud_display]位置不对应"); return false; }
		if(vecLine[25]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[26]!="display_priority"){Ex.Logger.Log("Creature.csv中字段[display_priority]位置不对应"); return false; }
		if(vecLine[27]!="hp_level"){Ex.Logger.Log("Creature.csv中字段[hp_level]位置不对应"); return false; }
		if(vecLine[28]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[29]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[30]!="move_mode"){Ex.Logger.Log("Creature.csv中字段[move_mode]位置不对应"); return false; }
		if(vecLine[31]!="normal_walk_speed"){Ex.Logger.Log("Creature.csv中字段[normal_walk_speed]位置不对应"); return false; }
		if(vecLine[32]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[33]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[34]!="can_be_selected"){Ex.Logger.Log("Creature.csv中字段[can_be_selected]位置不对应"); return false; }
		if(vecLine[35]!="can_be_attacked"){Ex.Logger.Log("Creature.csv中字段[can_be_attacked]位置不对应"); return false; }
		if(vecLine[36]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[37]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[38]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[39]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[40]!="weight"){Ex.Logger.Log("Creature.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[41]!="special_skill"){Ex.Logger.Log("Creature.csv中字段[special_skill]位置不对应"); return false; }
		if(vecLine[42]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[43]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[44]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[45]!="born_skill"){Ex.Logger.Log("Creature.csv中字段[born_skill]位置不对应"); return false; }
		if(vecLine[46]!="dead_skill"){Ex.Logger.Log("Creature.csv中字段[dead_skill]位置不对应"); return false; }
		if(vecLine[47]!="sound_die"){Ex.Logger.Log("Creature.csv中字段[sound_die]位置不对应"); return false; }
		if(vecLine[48]!="footsteps_list_run"){Ex.Logger.Log("Creature.csv中字段[footsteps_list_run]位置不对应"); return false; }
		if(vecLine[49]!="footsteps_list_dash"){Ex.Logger.Log("Creature.csv中字段[footsteps_list_dash]位置不对应"); return false; }
		if(vecLine[50]!="footsteps_par"){Ex.Logger.Log("Creature.csv中字段[footsteps_par]位置不对应"); return false; }
		if(vecLine[51]!="sound_hit"){Ex.Logger.Log("Creature.csv中字段[sound_hit]位置不对应"); return false; }
		if(vecLine[52]!="combat_entry_sound"){Ex.Logger.Log("Creature.csv中字段[combat_entry_sound]位置不对应"); return false; }
		if(vecLine[53]!="combat_entry_BGM"){Ex.Logger.Log("Creature.csv中字段[combat_entry_BGM]位置不对应"); return false; }
		if(vecLine[54]!="return_back_full_hp"){Ex.Logger.Log("Creature.csv中字段[return_back_full_hp]位置不对应"); return false; }
		if(vecLine[55]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[56]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }
		if(vecLine[57]!="corpse_dissolve_time"){Ex.Logger.Log("Creature.csv中字段[corpse_dissolve_time]位置不对应"); return false; }
		if(vecLine[58]!="fade_in_delay"){Ex.Logger.Log("Creature.csv中字段[fade_in_delay]位置不对应"); return false; }
		if(vecLine[59]!="fade_in_duration"){Ex.Logger.Log("Creature.csv中字段[fade_in_duration]位置不对应"); return false; }
		if(vecLine[60]!="fade_out_delay"){Ex.Logger.Log("Creature.csv中字段[fade_out_delay]位置不对应"); return false; }
		if(vecLine[61]!="fade_out_duration"){Ex.Logger.Log("Creature.csv中字段[fade_out_duration]位置不对应"); return false; }
		if(vecLine[62]!="fade_out_point"){Ex.Logger.Log("Creature.csv中字段[fade_out_point]位置不对应"); return false; }
		if(vecLine[63]!="fade_run_speed"){Ex.Logger.Log("Creature.csv中字段[fade_run_speed]位置不对应"); return false; }
		if(vecLine[64]!="fade_isrun"){Ex.Logger.Log("Creature.csv中字段[fade_isrun]位置不对应"); return false; }
		if(vecLine[65]!="quest_choose"){Ex.Logger.Log("Creature.csv中字段[quest_choose]位置不对应"); return false; }
		if(vecLine[66]!="network_type"){Ex.Logger.Log("Creature.csv中字段[network_type]位置不对应"); return false; }
		if(vecLine[67]!="right_choose"){Ex.Logger.Log("Creature.csv中字段[right_choose]位置不对应"); return false; }
		if(vecLine[68]!="belong_choose"){Ex.Logger.Log("Creature.csv中字段[belong_choose]位置不对应"); return false; }
		if(vecLine[69]!="drop1"){Ex.Logger.Log("Creature.csv中字段[drop1]位置不对应"); return false; }
		if(vecLine[70]!="drop2"){Ex.Logger.Log("Creature.csv中字段[drop2]位置不对应"); return false; }
		if(vecLine[71]!="drop3"){Ex.Logger.Log("Creature.csv中字段[drop3]位置不对应"); return false; }
		if(vecLine[72]!="drop4"){Ex.Logger.Log("Creature.csv中字段[drop4]位置不对应"); return false; }
		if(vecLine[73]!="drop5"){Ex.Logger.Log("Creature.csv中字段[drop5]位置不对应"); return false; }
		if(vecLine[74]!="is_double"){Ex.Logger.Log("Creature.csv中字段[is_double]位置不对应"); return false; }
		if(vecLine[75]!="conversation_default"){Ex.Logger.Log("Creature.csv中字段[conversation_default]位置不对应"); return false; }
		if(vecLine[76]!="quest_list"){Ex.Logger.Log("Creature.csv中字段[quest_list]位置不对应"); return false; }
		if(vecLine[77]!="activitiy_id"){Ex.Logger.Log("Creature.csv中字段[activitiy_id]位置不对应"); return false; }
		if(vecLine[78]!="ui_id"){Ex.Logger.Log("Creature.csv中字段[ui_id]位置不对应"); return false; }
		if(vecLine[79]!="teleportfb_id"){Ex.Logger.Log("Creature.csv中字段[teleportfb_id]位置不对应"); return false; }
		if(vecLine[80]!="teleport_id"){Ex.Logger.Log("Creature.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[81]!="CreatureHide_id"){Ex.Logger.Log("Creature.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[82]!="CreatureDefaultHide"){Ex.Logger.Log("Creature.csv中字段[CreatureDefaultHide]位置不对应"); return false; }
		if(vecLine[83]!="quick_uicategory_id"){Ex.Logger.Log("Creature.csv中字段[quick_uicategory_id]位置不对应"); return false; }
		if(vecLine[84]!="first_mission"){Ex.Logger.Log("Creature.csv中字段[first_mission]位置不对应"); return false; }
		if(vecLine[85]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[86]!="ActionEvent"){Ex.Logger.Log("Creature.csv中字段[ActionEvent]位置不对应"); return false; }
		if(vecLine[87]!="FuncBelong"){Ex.Logger.Log("Creature.csv中字段[FuncBelong]位置不对应"); return false; }
		if(vecLine[88]!="Shout"){Ex.Logger.Log("Creature.csv中字段[Shout]位置不对应"); return false; }
		if(vecLine[89]!="material_hit_sound_type"){Ex.Logger.Log("Creature.csv中字段[material_hit_sound_type]位置不对应"); return false; }
		if(vecLine[90]!="Title_display"){Ex.Logger.Log("Creature.csv中字段[Title_display]位置不对应"); return false; }
		if(vecLine[91]!="interact_duration"){Ex.Logger.Log("Creature.csv中字段[interact_duration]位置不对应"); return false; }
		if(vecLine[92]!="icon_path"){Ex.Logger.Log("Creature.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[93]!="interact_skill_id"){Ex.Logger.Log("Creature.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[94]!="is_death_type"){Ex.Logger.Log("Creature.csv中字段[is_death_type]位置不对应"); return false; }
		if(vecLine[95]!="camo_channel_1"){Ex.Logger.Log("Creature.csv中字段[camo_channel_1]位置不对应"); return false; }
		if(vecLine[96]!="camo_channel_2"){Ex.Logger.Log("Creature.csv中字段[camo_channel_2]位置不对应"); return false; }
		if(vecLine[97]!="camo_channel_3"){Ex.Logger.Log("Creature.csv中字段[camo_channel_3]位置不对应"); return false; }
		if(vecLine[98]!="camo_channel_4"){Ex.Logger.Log("Creature.csv中字段[camo_channel_4]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)99)
			{
				return false;
			}
			CreatureElement member = new CreatureElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.script_ID=vecLine[1];
			member.behaviac=vecLine[2];
			member.combat_coe_id=Convert.ToInt32(vecLine[3]);
			member.leisure_pro=Convert.ToSingle(vecLine[4]);
			member.combat_attributes_id=Convert.ToInt32(vecLine[5]);
			member.temper_id=Convert.ToInt32(vecLine[6]);
			member.name_id=Convert.ToInt32(vecLine[7]);
			member.title_id=Convert.ToInt32(vecLine[8]);
			member.name_bar_display=Convert.ToInt32(vecLine[9]);
			member.npcintroduec_id=vecLine[10];
			member.describe_id=Convert.ToInt32(vecLine[11]);
			member.model_id=Convert.ToInt32(vecLine[12]);
			member.mapping_path=vecLine[13];
			member.scale=Convert.ToSingle(vecLine[14]);
			member.opacity=Convert.ToSingle(vecLine[15]);
			member.minimap_icon=vecLine[16];
			member.minimap_name=Convert.ToInt32(vecLine[17]);
			member.icon=vecLine[18];
			member.head_icon=vecLine[19];
			member.creature_level=Convert.ToInt32(vecLine[20]);
			member.level_type=Convert.ToInt32(vecLine[21]);
			member.creature_type=Convert.ToInt32(vecLine[22]);
			member.health_type=Convert.ToInt32(vecLine[23]);
			member.health_hud_display=Convert.ToInt32(vecLine[24]);
			member.health_bar_display=Convert.ToInt32(vecLine[25]);
			member.display_priority=Convert.ToInt32(vecLine[26]);
			member.hp_level=Convert.ToInt32(vecLine[27]);
			member.faction=Convert.ToInt32(vecLine[28]);
			member.race=Convert.ToInt32(vecLine[29]);
			member.move_mode=Convert.ToInt32(vecLine[30]);
			member.normal_walk_speed=Convert.ToSingle(vecLine[31]);
			member.walk_speed=Convert.ToSingle(vecLine[32]);
			member.run_speed=Convert.ToSingle(vecLine[33]);
			member.can_be_selected=Convert.ToInt32(vecLine[34]);
			member.can_be_attacked=Convert.ToInt32(vecLine[35]);
			member.can_attack=Convert.ToInt32(vecLine[36]);
			member.selected_sound=vecLine[37];
			member.death_sound=vecLine[38];
			member.initial_skill=vecLine[39];
			member.weight=vecLine[40];
			member.special_skill=Convert.ToInt32(vecLine[41]);
			member.rebirth_buffs=vecLine[42];
			member.verification=vecLine[43];
			member.is_wondering=Convert.ToInt32(vecLine[44]);
			member.born_skill=Convert.ToInt32(vecLine[45]);
			member.dead_skill=Convert.ToInt32(vecLine[46]);
			member.sound_die=vecLine[47];
			member.footsteps_list_run=vecLine[48];
			member.footsteps_list_dash=vecLine[49];
			member.footsteps_par=vecLine[50];
			member.sound_hit=vecLine[51];
			member.combat_entry_sound=vecLine[52];
			member.combat_entry_BGM=vecLine[53];
			member.return_back_full_hp=Convert.ToInt32(vecLine[54]);
			member.combat_entry_skill=vecLine[55];
			member.corpse_vanish_time=Convert.ToInt32(vecLine[56]);
			member.corpse_dissolve_time=Convert.ToInt32(vecLine[57]);
			member.fade_in_delay=Convert.ToInt32(vecLine[58]);
			member.fade_in_duration=Convert.ToInt32(vecLine[59]);
			member.fade_out_delay=Convert.ToInt32(vecLine[60]);
			member.fade_out_duration=Convert.ToInt32(vecLine[61]);
			member.fade_out_point=Convert.ToInt32(vecLine[62]);
			member.fade_run_speed=Convert.ToSingle(vecLine[63]);
			member.fade_isrun=Convert.ToInt32(vecLine[64]);
			member.quest_choose=Convert.ToInt32(vecLine[65]);
			member.network_type=Convert.ToInt32(vecLine[66]);
			member.right_choose=Convert.ToInt32(vecLine[67]);
			member.belong_choose=Convert.ToInt32(vecLine[68]);
			member.drop1=vecLine[69];
			member.drop2=vecLine[70];
			member.drop3=vecLine[71];
			member.drop4=vecLine[72];
			member.drop5=vecLine[73];
			member.is_double=Convert.ToInt32(vecLine[74]);
			member.conversation_default=Convert.ToInt32(vecLine[75]);
			member.quest_list=vecLine[76];
			member.activitiy_id=vecLine[77];
			member.ui_id=vecLine[78];
			member.teleportfb_id=vecLine[79];
			member.teleport_id=vecLine[80];
			member.CreatureHide_id=vecLine[81];
			member.CreatureDefaultHide=Convert.ToInt32(vecLine[82]);
			member.quick_uicategory_id=Convert.ToInt32(vecLine[83]);
			member.first_mission=vecLine[84];
			member.sub_name_id=Convert.ToInt32(vecLine[85]);
			member.ActionEvent=vecLine[86];
			member.FuncBelong=Convert.ToInt32(vecLine[87]);
			member.Shout=Convert.ToInt32(vecLine[88]);
			member.material_hit_sound_type=Convert.ToInt32(vecLine[89]);
			member.Title_display=Convert.ToInt32(vecLine[90]);
			member.interact_duration=Convert.ToSingle(vecLine[91]);
			member.icon_path=vecLine[92];
			member.interact_skill_id=vecLine[93];
			member.is_death_type=Convert.ToInt32(vecLine[94]);
			member.camo_channel_1=vecLine[95];
			member.camo_channel_2=vecLine[96];
			member.camo_channel_3=vecLine[97];
			member.camo_channel_4=vecLine[98];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
