using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//总NPC表配置数据类
public class CreatureElement
{
	public int id;               	//序号	作者: ID段分类： 1,000,000（100W）以上的字段，代表拥有功能性（特殊数值）的怪物 1开头为精英怪，2为世界boss 100W以下的字段，为世界怪物，测试怪物，任务怪物，副本怪物 左边第一个数字，代表场景， 1为人族领地，2为demo副本 3为狼人种族领地，4为奥斯提温 5位马鬃草原野外，6为马鬃草原副本 7为新手村，8为精灵种族领地 9为精灵之森世界，10为精灵之森副本 11为野外战场 左边第三个数字，代表阵营： 0为友善，2为敌对
	public string comment;       	//策划备注	策划备注
	public string script_ID;     	//脚本ID	脚本ID填写为NPC的ID -1为没有脚本
	public int combat_coe_id;    	//战斗系数ID	战斗系数ID
	public float leisure_pro;    	//播放休闲动画几率	1=100%
	public int combat_attributes_id;	//战斗属性ID	战斗属性ID
	public int temper_id;        	//AI类型ID	关联 CreatureTemperConfig
	public int name_id;          	//名字文本ID	名字文本ID
	public int sub_name_id;      	//子名字文本ID	子名字文本ID
	public int describe_id;      	//boss简介ID	大概是stringUI
	public int model_id;         	//模型id	模型id
	public string mapping_path;  	//贴图路径	贴图路径
	public float scale;          	//NPC大小	NPC大小
	public float opacity;        	//透明度	透明度
	public string icon;          	//图标路径	图标路径
	public int health_bar_display;	//血条显示	0 不显示 1 挨打时显示 脱战后消失 2 一直显示
	public int name_bar_display; 	//名字显示	名字显示
	public int creature_level;   	//怪物等级	怪物等级
	public int creature_type;    	//怪物类型	1为普通小怪，血条在怪物的头顶 2为精英NPC，血条在怪物的头顶 3为副本boss，血条会显示在屏幕从上往下1/4的位置。 4为技能NPC，不显示在游戏中，用于放区域技能 5为世界NPC，不具有攻击举动 6为血条特殊显示NPC 7为功能性NPC 8为世界boss，位于一般场景，血条显示与副本boss相同 9创建光球特效npc（宠物） 10宠物捕获npc 11跟随类NPC 12保护类NPC 13巡逻类
	public string minimap_icon;  	//小地图怪物图标	配置怪物在小地图上显示的图标
	public int faction;          	//阵营	阵营
	public int race;             	//种族	种族
	public float walk_speed;     	//走路速度	走路速度
	public float run_speed;      	//跑步速度	跑步速度
	public int can_be_targeted;  	//是否可以被攻击或选中	是否可以被攻击或选中
	public int can_attack;       	//是否可以进行攻击	是否可以进行攻击
	public string selected_sound;	//被选中音效	被选中音效
	public string death_sound;   	//死亡音效	死亡音效
	public li initial_skill;     	//NPC的技能数组	关联之后的技能，如果没有技能则不填
	public li weight;            	//技能组中每个技能的权重	跟技能组一一对应，默认权重1
	public int special_skill;    	//特殊技能	出生释放技能 （目前只用在宠物抓捕活动）
	public li rebirth_buffs;     	//出生的时候释放buff	出生的时候释放buff
	public string verification;  	//技能验证	仅策划用 二进制检验
	public int is_wondering;     	//是否在范围内漫步	是否在范围内漫步
	public int born_skill;       	//出生技能	关联技能表
	public int dead_skill;       	//死亡技能	关联技能表
	public int return_back_full_hp;	//脱战是否回血	默认0回血，1不回血
	public int is_play_born_animation;	//是否需要播放出生动画	是否需要播放出生动画
	public int born_anim_duration_buff;	//出生动画持续时的效果buff ID	出生动画持续时的效果buff ID
	public int born_anim_effect_buff;	//出生动画持续时的时长buff ID	出生动画持续时的时长buff ID
	public string born_animation_name;	//出生动画名称	出生动画名称
	public string combat_entry_skill;	//进入战斗的技能	进入战斗的技能
	public int corpse_vanish_time;	//尸体消失时间	尸体消失时间
	public int network_type;     	//掉落广播类型	广播的类型（ 0：只看到自己的掉落表现 1：可以看到自己和队伍成员的掉落表现 2：可以看到自己和团队成员的掉落表现 3：可以看到所有的掉落表现
	public int right_choose;     	//掉落权利方式选择	掉落权利判定的类型（ 0：最后一击 1：参与战斗 2：伤害统计）
	public int belong_choose;    	//归属选择	归属判定的类型（ 0:个人归属 1：组队归属 2：公会归属）
	public li drop1;             	//掉落1	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop2;             	//掉落2	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop3;             	//掉落3	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop4;             	//掉落4	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public li drop5;             	//掉落5	掉落类型|掉落ID|掉落数量（ 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量）
	public int conversation_default;	//默认对话	与NPC交互时触发的默认对话 字幕ID
	public li quest_list;        	//任务列表	与NPC交互时会判断该NPC是否由有任务要接
	public li activitiy_id;      	//活动id	选择该项后触发活动 相当于“前往”功能 关联活动表
	public li ui_id;             	//界面id	选择该项后弹出界面 关联界面t表
	public li teleportfb_id;     	//传送副本id	选择该项后传送至副本 关联Dungeon_副本表
	public li teleport_id;       	//传送id	选择该项后传送至场景 关联teleport_target表
	public li CreatureHide_id;   	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	public int CreatureDefaultHide;	//默认显示隐藏	0为隐藏 1为显示 默认为1

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
		if(vecLine.Count != 59)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Creature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Creature.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[3]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[4]!="leisure_pro"){Ex.Logger.Log("Creature.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[5]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[6]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[7]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[8]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[9]!="describe_id"){Ex.Logger.Log("Creature.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[10]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[11]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[12]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[13]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[14]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[15]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[16]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[17]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[18]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[19]!="minimap_icon"){Ex.Logger.Log("Creature.csv中字段[minimap_icon]位置不对应"); return false; }
		if(vecLine[20]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[21]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[22]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[23]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[24]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[25]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[26]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[27]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[28]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[29]!="weight"){Ex.Logger.Log("Creature.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[30]!="special_skill"){Ex.Logger.Log("Creature.csv中字段[special_skill]位置不对应"); return false; }
		if(vecLine[31]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[32]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[33]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[34]!="born_skill"){Ex.Logger.Log("Creature.csv中字段[born_skill]位置不对应"); return false; }
		if(vecLine[35]!="dead_skill"){Ex.Logger.Log("Creature.csv中字段[dead_skill]位置不对应"); return false; }
		if(vecLine[36]!="return_back_full_hp"){Ex.Logger.Log("Creature.csv中字段[return_back_full_hp]位置不对应"); return false; }
		if(vecLine[37]!="is_play_born_animation"){Ex.Logger.Log("Creature.csv中字段[is_play_born_animation]位置不对应"); return false; }
		if(vecLine[38]!="born_anim_duration_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_duration_buff]位置不对应"); return false; }
		if(vecLine[39]!="born_anim_effect_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_effect_buff]位置不对应"); return false; }
		if(vecLine[40]!="born_animation_name"){Ex.Logger.Log("Creature.csv中字段[born_animation_name]位置不对应"); return false; }
		if(vecLine[41]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[42]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }
		if(vecLine[43]!="network_type"){Ex.Logger.Log("Creature.csv中字段[network_type]位置不对应"); return false; }
		if(vecLine[44]!="right_choose"){Ex.Logger.Log("Creature.csv中字段[right_choose]位置不对应"); return false; }
		if(vecLine[45]!="belong_choose"){Ex.Logger.Log("Creature.csv中字段[belong_choose]位置不对应"); return false; }
		if(vecLine[46]!="drop1"){Ex.Logger.Log("Creature.csv中字段[drop1]位置不对应"); return false; }
		if(vecLine[47]!="drop2"){Ex.Logger.Log("Creature.csv中字段[drop2]位置不对应"); return false; }
		if(vecLine[48]!="drop3"){Ex.Logger.Log("Creature.csv中字段[drop3]位置不对应"); return false; }
		if(vecLine[49]!="drop4"){Ex.Logger.Log("Creature.csv中字段[drop4]位置不对应"); return false; }
		if(vecLine[50]!="drop5"){Ex.Logger.Log("Creature.csv中字段[drop5]位置不对应"); return false; }
		if(vecLine[51]!="conversation_default"){Ex.Logger.Log("Creature.csv中字段[conversation_default]位置不对应"); return false; }
		if(vecLine[52]!="quest_list"){Ex.Logger.Log("Creature.csv中字段[quest_list]位置不对应"); return false; }
		if(vecLine[53]!="activitiy_id"){Ex.Logger.Log("Creature.csv中字段[activitiy_id]位置不对应"); return false; }
		if(vecLine[54]!="ui_id"){Ex.Logger.Log("Creature.csv中字段[ui_id]位置不对应"); return false; }
		if(vecLine[55]!="teleportfb_id"){Ex.Logger.Log("Creature.csv中字段[teleportfb_id]位置不对应"); return false; }
		if(vecLine[56]!="teleport_id"){Ex.Logger.Log("Creature.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[57]!="CreatureHide_id"){Ex.Logger.Log("Creature.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[58]!="CreatureDefaultHide"){Ex.Logger.Log("Creature.csv中字段[CreatureDefaultHide]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureElement member = new CreatureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.script_ID);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_coe_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.leisure_pro);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_attributes_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.temper_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sub_name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mapping_path);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.scale);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.opacity);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.health_bar_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_bar_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.minimap_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.faction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.walk_speed);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.run_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_targeted );
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
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.return_back_full_hp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_play_born_animation );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.born_anim_duration_buff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.born_anim_effect_buff );
			readPos += GameAssist.ReadString( binContent, readPos, out member.born_animation_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.combat_entry_skill);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.corpse_vanish_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.network_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.right_choose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.belong_choose );
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop5);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.conversation_default );
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.activitiy_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleportfb_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleport_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.CreatureHide_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.CreatureDefaultHide );

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
		if(vecLine.Count != 59)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Creature.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Creature.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[3]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[4]!="leisure_pro"){Ex.Logger.Log("Creature.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[5]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[6]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[7]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[8]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[9]!="describe_id"){Ex.Logger.Log("Creature.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[10]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[11]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[12]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[13]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[14]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[15]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[16]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[17]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[18]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[19]!="minimap_icon"){Ex.Logger.Log("Creature.csv中字段[minimap_icon]位置不对应"); return false; }
		if(vecLine[20]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[21]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[22]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[23]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[24]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[25]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[26]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[27]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[28]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[29]!="weight"){Ex.Logger.Log("Creature.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[30]!="special_skill"){Ex.Logger.Log("Creature.csv中字段[special_skill]位置不对应"); return false; }
		if(vecLine[31]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[32]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[33]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[34]!="born_skill"){Ex.Logger.Log("Creature.csv中字段[born_skill]位置不对应"); return false; }
		if(vecLine[35]!="dead_skill"){Ex.Logger.Log("Creature.csv中字段[dead_skill]位置不对应"); return false; }
		if(vecLine[36]!="return_back_full_hp"){Ex.Logger.Log("Creature.csv中字段[return_back_full_hp]位置不对应"); return false; }
		if(vecLine[37]!="is_play_born_animation"){Ex.Logger.Log("Creature.csv中字段[is_play_born_animation]位置不对应"); return false; }
		if(vecLine[38]!="born_anim_duration_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_duration_buff]位置不对应"); return false; }
		if(vecLine[39]!="born_anim_effect_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_effect_buff]位置不对应"); return false; }
		if(vecLine[40]!="born_animation_name"){Ex.Logger.Log("Creature.csv中字段[born_animation_name]位置不对应"); return false; }
		if(vecLine[41]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[42]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }
		if(vecLine[43]!="network_type"){Ex.Logger.Log("Creature.csv中字段[network_type]位置不对应"); return false; }
		if(vecLine[44]!="right_choose"){Ex.Logger.Log("Creature.csv中字段[right_choose]位置不对应"); return false; }
		if(vecLine[45]!="belong_choose"){Ex.Logger.Log("Creature.csv中字段[belong_choose]位置不对应"); return false; }
		if(vecLine[46]!="drop1"){Ex.Logger.Log("Creature.csv中字段[drop1]位置不对应"); return false; }
		if(vecLine[47]!="drop2"){Ex.Logger.Log("Creature.csv中字段[drop2]位置不对应"); return false; }
		if(vecLine[48]!="drop3"){Ex.Logger.Log("Creature.csv中字段[drop3]位置不对应"); return false; }
		if(vecLine[49]!="drop4"){Ex.Logger.Log("Creature.csv中字段[drop4]位置不对应"); return false; }
		if(vecLine[50]!="drop5"){Ex.Logger.Log("Creature.csv中字段[drop5]位置不对应"); return false; }
		if(vecLine[51]!="conversation_default"){Ex.Logger.Log("Creature.csv中字段[conversation_default]位置不对应"); return false; }
		if(vecLine[52]!="quest_list"){Ex.Logger.Log("Creature.csv中字段[quest_list]位置不对应"); return false; }
		if(vecLine[53]!="activitiy_id"){Ex.Logger.Log("Creature.csv中字段[activitiy_id]位置不对应"); return false; }
		if(vecLine[54]!="ui_id"){Ex.Logger.Log("Creature.csv中字段[ui_id]位置不对应"); return false; }
		if(vecLine[55]!="teleportfb_id"){Ex.Logger.Log("Creature.csv中字段[teleportfb_id]位置不对应"); return false; }
		if(vecLine[56]!="teleport_id"){Ex.Logger.Log("Creature.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[57]!="CreatureHide_id"){Ex.Logger.Log("Creature.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[58]!="CreatureDefaultHide"){Ex.Logger.Log("Creature.csv中字段[CreatureDefaultHide]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)59)
			{
				return false;
			}
			CreatureElement member = new CreatureElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.script_ID=vecLine[2];
			member.combat_coe_id=Convert.ToInt32(vecLine[3]);
			member.leisure_pro=Convert.ToSingle(vecLine[4]);
			member.combat_attributes_id=Convert.ToInt32(vecLine[5]);
			member.temper_id=Convert.ToInt32(vecLine[6]);
			member.name_id=Convert.ToInt32(vecLine[7]);
			member.sub_name_id=Convert.ToInt32(vecLine[8]);
			member.describe_id=Convert.ToInt32(vecLine[9]);
			member.model_id=Convert.ToInt32(vecLine[10]);
			member.mapping_path=vecLine[11];
			member.scale=Convert.ToSingle(vecLine[12]);
			member.opacity=Convert.ToSingle(vecLine[13]);
			member.icon=vecLine[14];
			member.health_bar_display=Convert.ToInt32(vecLine[15]);
			member.name_bar_display=Convert.ToInt32(vecLine[16]);
			member.creature_level=Convert.ToInt32(vecLine[17]);
			member.creature_type=Convert.ToInt32(vecLine[18]);
			member.minimap_icon=vecLine[19];
			member.faction=Convert.ToInt32(vecLine[20]);
			member.race=Convert.ToInt32(vecLine[21]);
			member.walk_speed=Convert.ToSingle(vecLine[22]);
			member.run_speed=Convert.ToSingle(vecLine[23]);
			member.can_be_targeted=Convert.ToInt32(vecLine[24]);
			member.can_attack=Convert.ToInt32(vecLine[25]);
			member.selected_sound=vecLine[26];
			member.death_sound=vecLine[27];
			member.initial_skill=vecLine[28];
			member.weight=vecLine[29];
			member.special_skill=Convert.ToInt32(vecLine[30]);
			member.rebirth_buffs=vecLine[31];
			member.verification=vecLine[32];
			member.is_wondering=Convert.ToInt32(vecLine[33]);
			member.born_skill=Convert.ToInt32(vecLine[34]);
			member.dead_skill=Convert.ToInt32(vecLine[35]);
			member.return_back_full_hp=Convert.ToInt32(vecLine[36]);
			member.is_play_born_animation=Convert.ToInt32(vecLine[37]);
			member.born_anim_duration_buff=Convert.ToInt32(vecLine[38]);
			member.born_anim_effect_buff=Convert.ToInt32(vecLine[39]);
			member.born_animation_name=vecLine[40];
			member.combat_entry_skill=vecLine[41];
			member.corpse_vanish_time=Convert.ToInt32(vecLine[42]);
			member.network_type=Convert.ToInt32(vecLine[43]);
			member.right_choose=Convert.ToInt32(vecLine[44]);
			member.belong_choose=Convert.ToInt32(vecLine[45]);
			member.drop1=vecLine[46];
			member.drop2=vecLine[47];
			member.drop3=vecLine[48];
			member.drop4=vecLine[49];
			member.drop5=vecLine[50];
			member.conversation_default=Convert.ToInt32(vecLine[51]);
			member.quest_list=vecLine[52];
			member.activitiy_id=vecLine[53];
			member.ui_id=vecLine[54];
			member.teleportfb_id=vecLine[55];
			member.teleport_id=vecLine[56];
			member.CreatureHide_id=vecLine[57];
			member.CreatureDefaultHide=Convert.ToInt32(vecLine[58]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
