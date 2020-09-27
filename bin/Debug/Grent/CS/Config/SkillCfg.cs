using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能配置数据类
public class SkillElement
{
	public int id;               	//技能ID	1100000~2999999为主角技能预留ID段 1=战士 2=盗贼 3=骑士 4=猎人 5=法师 6=神秘使 7 ~ 71 = 马鬃草原世界
	public int name_id;          	//技能名称ID	关联语言表
	public int desc_id;          	//技能描述ID	
	public int type;             	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=原应激技能，已废弃，勿填 5=连击技能 6=宠物技能 7=多层技能 8=表情技能 9=死亡技能 10=交互技能
	public int buff_count_type;  	//技能类型	用来给专门的buff使用。buff参数填的值，和这里配的值一致，且该技能释放，那么该buff计数1次 1、普通攻击 2、恶意技能 3、善意技能 4、翻滚技能
	public int is_prepare;       	//是否是蓄力技能	技能是否是蓄力技能，0不是，1是 是否蓄力
	public li is_prepare_par;    	//蓄力技能参数	蓄力技能参数： 最大蓄力时间|延迟时间|蓄力表中的ID
	public string prepare_show;  	//蓄力阶段的展示动作	展示动作，不是蓄力的话填了也没用
	public int class_restriction;	//技能等级限制	需要角色或者怪物超过配置的等级后才能释放这个技能
	public int max_stack;        	//最大技能层数	技能层数，若不是多层技能，则填1；若是，则填写最大技能层数
	public int max_target_count; 	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	public int caster_type;      	//技能释放者对象	技能释放者类型： 0 = 主角 1 = 怪物 2 = 坐骑
	public int cast_target;      	//技能施法目标	影响技能释放目标和caster之间的阵营关系判断 0=不需要目标 1=自己 2=敌方单位 3=友方单位 4=敌方+友方 5=友方+自己 6=敌方+友方+自己
	public int target_alive_status;	//技能目标存活类型	0：技能只能对死亡目标生效 1：技能只能对活着的目标生效 2：会对死亡、存活的目标同时生效
	public int can_interrupt;    	//能否被打断	0：不能被打断 1：能被打断 （只有NPC技能可被打断，玩家职业技能都无法被打断,默认无法被打断）
	public int attack_empty;     	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 0=不允许空放 1=允许空放
	public li former_skill_buff; 	//技能释放前施加的buff	表示在attack生效前给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	public int extra_former_condition_id;	//额外附加技能前效果条件ID	满足ID对应条件时，给自身额外施加buff 当前只支持主角天赋方向ID，后续待扩展
	public li extra_former_buff; 	//额外附加技能前buff	技能刚开始释放时给自身额外施加的附加buff效果ID，多个ID用“|”连接
	public li latter_skill_buff; 	//技能释放后施加的buff	表示在技能所有的attack生效后给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	public int extra_latter_condition_id;	//额外附加技能后效果条件ID	满足ID对应条件时，给自身额外施加buff 当前只支持主角天赋方向ID，后续待扩展
	public li extra_latter_buff; 	//额外附加技能后buff	技能释放结束时给自身额外施加的附加buff效果ID，多个ID用“|”连接
	public int cooldown_id;      	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	public int cooldown_time;    	//冷却的时间	当技能类型为多层时，该字段表示恢复一层所需时间，其他类型表示正常的技能CD 单位：毫秒
	public int common_cd_time;   	//公共CD时间	技能释放后，同冷却ID组的技能会共同按照该技能的公共CD事件进入冷却 单位：毫秒
	public int continuity;       	//是否连续技能	0=非连续技能 1=连续技能
	public int next_id;          	//下一段技能ID	"-1"=没有下一段
	public li atk_id_list;       	//普攻技能id随机列	普攻下一段可以播放的普攻id列表，多个技能id用连接符：”|“连结，没有填“-1”
	public lf atk_prob_list;     	//普攻技能id随机概率	atk_id_list中对应技能释放的概率，填写小数，多个概率值用连结符：“|”连结，多个概率总和需要等于1。没有填“-1”
	public li skill_normal_all;  	//普攻技能ID汇总	
	public float attack_range;   	//技能释放距离	技能最大释放距离，显示为技能释放圆形范围
	public int show_release;     	//显示技能最大范围提示	只有主角技能有效，是否显示技能范围 0=隐藏 1=显示
	public int is_translate;     	//是否位移技能	判断这个技能，被定身后，是否还可以释放，根据类型判断 0：不包含位移，可以放，无影响 1：有translate位移，不能放 2：有translate位移，但是可以放，不能移动而已，战士和骑士的普攻用
	public int loop_skill;       	//是否循环	默认为-1，不生效 1为循环技能   目前仅用于处理表情动作
	public int rang_type;        	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	public float rang_par1;      	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	public float rang_par2;      	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	public int release_type;     	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形 6=固定距离圆形 7=固定距离矩形 8=目标点连环圆
	public string resources_release;	//释放资源	打目标，无资源，空值 身前直线:SkillRangeStrip 基准点在中心位置的矩形:SkillRangeSquare_001 普通身前矩形:SkillRangeSquare_002 两边带角身前矩形:SkillRangeSquare_003 基准点在圆心位置的圆:SkillRangeCircular 基准点在切边位置的圆:SkillRangeCircular_001 基准点在两圆连接处:SkillRangeCircular_002 身前60度扇形:SkillRangeSector60 身前90度扇形:SkillRangeSector90 身前120度扇形:SkillRangeSector120 身前180度扇形:SkillRangeSector180 基准点在圆心的圆边:SkillRange
	public string Resources;     	//动作资源	动作文件
	public li attack_ID;         	//技能编辑器的attackID	仅策划查看用，修改需要在技能编辑器
	public string resources_name;	//对应资源	仅策划用
	public string icon;          	//图标资源	图标资源文件
	public int can_break;        	//连击次数	1为是 0为否
	public li repeatedly_skil_list;	//多段技能列表	多段技能列表 默认为空
	public lf interval_time;     	//多段技能每次反应的等待时间	多段技能每次等待的反应间隔时间,单位：ms
	public int can_be_accelerate;	//反应时间是否受急速影响	反应时间是否受急速影响，若受影响，则反应时间会受急速属性影响变快或变慢 1：受 0：不受 无需求默认填0
	public int max_accumulate;   	//最大积攒能量上限	应激技能能量积攒上限
	public int min_accumulate_use;	//发动应激技能最低能量要求	发动应激技能最低能量数量
	public int skill_trigger_type;	//应激技能触发类型	（空=没有事件，不积攒能量） 1=格挡 2=暴击 3=命中
	public float event_addEP;    	//事件增加能量数量	1=1点能量 不足1点用小数
	public int skill_expend_point;	//技能增强点数消耗	用于主角技能 技能可消耗增强点数 具体消耗的点数数值
	public string expend_effect_resource;	//增强点特效资源	用于主角技能 技能达到增强点数消耗时 对应该技能位的特效资源
	public li reduce_cd_ski_list;	//减少哪个技能cd	例（3.3.1 灼烧）
	public int reduce_cd_type;   	//减少cd类型	1=固定值 2=百分比
	public float reduce_cd_parameter;	//减少cd参数	
	public int notice_step_type; 	//提示时机	-1=没有提示 0=施法开始时 1=施法结束时
	public int notice_id;        	//文本提示ID	关联文本提示表，没有则填-1
	public int continuance;      	//提示消息持续时间	消息持续时间，单位ms，没有则填-1
	public string script;        	//脚本名称	script不填的话则没有脚本
	public int automation_priority;	//自动战斗释放优先级	值越高，优先级越高
	public li automation_type;   	//自动战斗技能类型	0：普通技能 1：治疗技能 2：复活技能
	public int waiting_message;  	//等待服务器消息	主角技能生效，释放技能是否需要等待服务器消息返回后再开始， 1：需要等待服务器消息 0：客户端自行判断是否可放，不等待服务器消息返回
	public li replace;           	//能否替代	替代技 第一个表示能否替代其他技能，0表示不可以，1表示可以；第二个数值表示能否被其他技能替代，0表示不可以，1表示可以
	public int can_insert;       	//	后续技能 1：表示可以加入后续技能 -1：表示不可以加入
	public int share_skillcd;    	//翻滚技能共用cd	翻滚技能共用cd，后翻滚技能，在这列，填对应的前翻滚技能ID
	public int channel_time;     	//引导的时间(已无效）	已无效 单位：毫秒
	public int charge_time;      	//吟唱的时间（已废弃）	单位：毫秒
	public int charge_or_interval;	//伤害段数（已废弃）	在一段时间之内， 释放多少次伤害（BUFF）
	public string server_script_id;	//技能脚本（已废弃）	该技能配置脚本的名称（无用字段）
	public int move_limit;       	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离
	public int pet_cast_position;	//宠物释放位置	只有宠物技能使用 宠物在释放技能时的初始位置  0.当前位置 1.瞬间移动至玩家位置 2.瞬间移动至目标位置
	public float pet_cast_position_offset;	//宠物释放位置偏移	当宠物释放技能时，该宠物延释放方向的偏移距离 单位米 不填代表无偏移
	public int rune_name;        	//铭文名称	该技能对应的铭文名称备份 从stringSkill表中读取 如果不填表示没有铭文
	public string rune_icon;     	//铭文图标	该铭文被选中时调用的图标资源
	public string rune_icon_normal;	//铭文默认图标	该铭文未被选中时所调用的图标资源

	public bool IsValidate = false;
	public SkillElement()
	{
		id = -1;
	}
};

//技能配置封装类
public class SkillTable
{

	private SkillTable()
	{
		m_mapElements = new Dictionary<int, SkillElement>();
		m_emptyItem = new SkillElement();
		m_vecAllElements = new List<SkillElement>();
	}
	private Dictionary<int, SkillElement> m_mapElements = null;
	private List<SkillElement>	m_vecAllElements = null;
	private SkillElement m_emptyItem = null;
	private static SkillTable sInstance = null;

	public static SkillTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SkillTable();
			return sInstance;
		}
	}

	public SkillElement GetElement(int key)
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

  public List<SkillElement> GetAllElement(Predicate<SkillElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Skill.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Skill.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Skill.bin]未找到");
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
		if(vecLine.Count != 76)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("Skill.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="buff_count_type"){Ex.Logger.Log("Skill.csv中字段[buff_count_type]位置不对应"); return false; }
		if(vecLine[5]!="is_prepare"){Ex.Logger.Log("Skill.csv中字段[is_prepare]位置不对应"); return false; }
		if(vecLine[6]!="is_prepare_par"){Ex.Logger.Log("Skill.csv中字段[is_prepare_par]位置不对应"); return false; }
		if(vecLine[7]!="prepare_show"){Ex.Logger.Log("Skill.csv中字段[prepare_show]位置不对应"); return false; }
		if(vecLine[8]!="class_restriction"){Ex.Logger.Log("Skill.csv中字段[class_restriction]位置不对应"); return false; }
		if(vecLine[9]!="max_stack"){Ex.Logger.Log("Skill.csv中字段[max_stack]位置不对应"); return false; }
		if(vecLine[10]!="max_target_count"){Ex.Logger.Log("Skill.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[11]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[12]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[13]!="target_alive_status"){Ex.Logger.Log("Skill.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[14]!="can_interrupt"){Ex.Logger.Log("Skill.csv中字段[can_interrupt]位置不对应"); return false; }
		if(vecLine[15]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[16]!="former_skill_buff"){Ex.Logger.Log("Skill.csv中字段[former_skill_buff]位置不对应"); return false; }
		if(vecLine[17]!="extra_former_condition_id"){Ex.Logger.Log("Skill.csv中字段[extra_former_condition_id]位置不对应"); return false; }
		if(vecLine[18]!="extra_former_buff"){Ex.Logger.Log("Skill.csv中字段[extra_former_buff]位置不对应"); return false; }
		if(vecLine[19]!="latter_skill_buff"){Ex.Logger.Log("Skill.csv中字段[latter_skill_buff]位置不对应"); return false; }
		if(vecLine[20]!="extra_latter_condition_id"){Ex.Logger.Log("Skill.csv中字段[extra_latter_condition_id]位置不对应"); return false; }
		if(vecLine[21]!="extra_latter_buff"){Ex.Logger.Log("Skill.csv中字段[extra_latter_buff]位置不对应"); return false; }
		if(vecLine[22]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[23]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[24]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[25]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[26]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[27]!="atk_id_list"){Ex.Logger.Log("Skill.csv中字段[atk_id_list]位置不对应"); return false; }
		if(vecLine[28]!="atk_prob_list"){Ex.Logger.Log("Skill.csv中字段[atk_prob_list]位置不对应"); return false; }
		if(vecLine[29]!="skill_normal_all"){Ex.Logger.Log("Skill.csv中字段[skill_normal_all]位置不对应"); return false; }
		if(vecLine[30]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[31]!="show_release"){Ex.Logger.Log("Skill.csv中字段[show_release]位置不对应"); return false; }
		if(vecLine[32]!="is_translate"){Ex.Logger.Log("Skill.csv中字段[is_translate]位置不对应"); return false; }
		if(vecLine[33]!="loop_skill"){Ex.Logger.Log("Skill.csv中字段[loop_skill]位置不对应"); return false; }
		if(vecLine[34]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[35]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[36]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[37]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[38]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[39]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[40]!="attack_ID"){Ex.Logger.Log("Skill.csv中字段[attack_ID]位置不对应"); return false; }
		if(vecLine[41]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[42]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[43]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[44]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[45]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[46]!="can_be_accelerate"){Ex.Logger.Log("Skill.csv中字段[can_be_accelerate]位置不对应"); return false; }
		if(vecLine[47]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[48]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[49]!="skill_trigger_type"){Ex.Logger.Log("Skill.csv中字段[skill_trigger_type]位置不对应"); return false; }
		if(vecLine[50]!="event_addEP"){Ex.Logger.Log("Skill.csv中字段[event_addEP]位置不对应"); return false; }
		if(vecLine[51]!="skill_expend_point"){Ex.Logger.Log("Skill.csv中字段[skill_expend_point]位置不对应"); return false; }
		if(vecLine[52]!="expend_effect_resource"){Ex.Logger.Log("Skill.csv中字段[expend_effect_resource]位置不对应"); return false; }
		if(vecLine[53]!="reduce_cd_ski_list"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_ski_list]位置不对应"); return false; }
		if(vecLine[54]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[55]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }
		if(vecLine[56]!="notice_step_type"){Ex.Logger.Log("Skill.csv中字段[notice_step_type]位置不对应"); return false; }
		if(vecLine[57]!="notice_id"){Ex.Logger.Log("Skill.csv中字段[notice_id]位置不对应"); return false; }
		if(vecLine[58]!="continuance"){Ex.Logger.Log("Skill.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[59]!="script"){Ex.Logger.Log("Skill.csv中字段[script]位置不对应"); return false; }
		if(vecLine[60]!="automation_priority"){Ex.Logger.Log("Skill.csv中字段[automation_priority]位置不对应"); return false; }
		if(vecLine[61]!="automation_type"){Ex.Logger.Log("Skill.csv中字段[automation_type]位置不对应"); return false; }
		if(vecLine[62]!="waiting_message"){Ex.Logger.Log("Skill.csv中字段[waiting_message]位置不对应"); return false; }
		if(vecLine[63]!="replace"){Ex.Logger.Log("Skill.csv中字段[replace]位置不对应"); return false; }
		if(vecLine[64]!="can_insert"){Ex.Logger.Log("Skill.csv中字段[can_insert]位置不对应"); return false; }
		if(vecLine[65]!="share_skillcd"){Ex.Logger.Log("Skill.csv中字段[share_skillcd]位置不对应"); return false; }
		if(vecLine[66]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[67]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[68]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[69]!="server_script_id"){Ex.Logger.Log("Skill.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[70]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }
		if(vecLine[71]!="pet_cast_position"){Ex.Logger.Log("Skill.csv中字段[pet_cast_position]位置不对应"); return false; }
		if(vecLine[72]!="pet_cast_position_offset"){Ex.Logger.Log("Skill.csv中字段[pet_cast_position_offset]位置不对应"); return false; }
		if(vecLine[73]!="rune_name"){Ex.Logger.Log("Skill.csv中字段[rune_name]位置不对应"); return false; }
		if(vecLine[74]!="rune_icon"){Ex.Logger.Log("Skill.csv中字段[rune_icon]位置不对应"); return false; }
		if(vecLine[75]!="rune_icon_normal"){Ex.Logger.Log("Skill.csv中字段[rune_icon_normal]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillElement member = new SkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_count_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_prepare );
			readPos += GameAssist.ReadString( binContent, readPos, out member.is_prepare_par);
			readPos += GameAssist.ReadString( binContent, readPos, out member.prepare_show);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.class_restriction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_stack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_target_count );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.caster_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cast_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_alive_status );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_interrupt );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_empty );
			readPos += GameAssist.ReadString( binContent, readPos, out member.former_skill_buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.extra_former_condition_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_former_buff);
			readPos += GameAssist.ReadString( binContent, readPos, out member.latter_skill_buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.extra_latter_condition_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_latter_buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.common_cd_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuity );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.atk_id_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.atk_prob_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_normal_all);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attack_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.show_release );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_translate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.loop_skill );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rang_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par1);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.release_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_release);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Resources);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attack_ID);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_break );
			readPos += GameAssist.ReadString( binContent, readPos, out member.repeatedly_skil_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.interval_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_accelerate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_accumulate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.min_accumulate_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_trigger_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.event_addEP);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_expend_point );
			readPos += GameAssist.ReadString( binContent, readPos, out member.expend_effect_resource);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reduce_cd_ski_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reduce_cd_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.reduce_cd_parameter);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.notice_step_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.notice_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.automation_priority );
			readPos += GameAssist.ReadString( binContent, readPos, out member.automation_type);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waiting_message );
			readPos += GameAssist.ReadString( binContent, readPos, out member.replace);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_insert );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.share_skillcd );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.channel_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_or_interval );
			readPos += GameAssist.ReadString( binContent, readPos, out member.server_script_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.move_limit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pet_cast_position );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.pet_cast_position_offset);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rune_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rune_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rune_icon_normal);

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
		if(vecLine.Count != 76)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("Skill.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="buff_count_type"){Ex.Logger.Log("Skill.csv中字段[buff_count_type]位置不对应"); return false; }
		if(vecLine[5]!="is_prepare"){Ex.Logger.Log("Skill.csv中字段[is_prepare]位置不对应"); return false; }
		if(vecLine[6]!="is_prepare_par"){Ex.Logger.Log("Skill.csv中字段[is_prepare_par]位置不对应"); return false; }
		if(vecLine[7]!="prepare_show"){Ex.Logger.Log("Skill.csv中字段[prepare_show]位置不对应"); return false; }
		if(vecLine[8]!="class_restriction"){Ex.Logger.Log("Skill.csv中字段[class_restriction]位置不对应"); return false; }
		if(vecLine[9]!="max_stack"){Ex.Logger.Log("Skill.csv中字段[max_stack]位置不对应"); return false; }
		if(vecLine[10]!="max_target_count"){Ex.Logger.Log("Skill.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[11]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[12]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[13]!="target_alive_status"){Ex.Logger.Log("Skill.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[14]!="can_interrupt"){Ex.Logger.Log("Skill.csv中字段[can_interrupt]位置不对应"); return false; }
		if(vecLine[15]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[16]!="former_skill_buff"){Ex.Logger.Log("Skill.csv中字段[former_skill_buff]位置不对应"); return false; }
		if(vecLine[17]!="extra_former_condition_id"){Ex.Logger.Log("Skill.csv中字段[extra_former_condition_id]位置不对应"); return false; }
		if(vecLine[18]!="extra_former_buff"){Ex.Logger.Log("Skill.csv中字段[extra_former_buff]位置不对应"); return false; }
		if(vecLine[19]!="latter_skill_buff"){Ex.Logger.Log("Skill.csv中字段[latter_skill_buff]位置不对应"); return false; }
		if(vecLine[20]!="extra_latter_condition_id"){Ex.Logger.Log("Skill.csv中字段[extra_latter_condition_id]位置不对应"); return false; }
		if(vecLine[21]!="extra_latter_buff"){Ex.Logger.Log("Skill.csv中字段[extra_latter_buff]位置不对应"); return false; }
		if(vecLine[22]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[23]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[24]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[25]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[26]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[27]!="atk_id_list"){Ex.Logger.Log("Skill.csv中字段[atk_id_list]位置不对应"); return false; }
		if(vecLine[28]!="atk_prob_list"){Ex.Logger.Log("Skill.csv中字段[atk_prob_list]位置不对应"); return false; }
		if(vecLine[29]!="skill_normal_all"){Ex.Logger.Log("Skill.csv中字段[skill_normal_all]位置不对应"); return false; }
		if(vecLine[30]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[31]!="show_release"){Ex.Logger.Log("Skill.csv中字段[show_release]位置不对应"); return false; }
		if(vecLine[32]!="is_translate"){Ex.Logger.Log("Skill.csv中字段[is_translate]位置不对应"); return false; }
		if(vecLine[33]!="loop_skill"){Ex.Logger.Log("Skill.csv中字段[loop_skill]位置不对应"); return false; }
		if(vecLine[34]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[35]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[36]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[37]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[38]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[39]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[40]!="attack_ID"){Ex.Logger.Log("Skill.csv中字段[attack_ID]位置不对应"); return false; }
		if(vecLine[41]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[42]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[43]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[44]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[45]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[46]!="can_be_accelerate"){Ex.Logger.Log("Skill.csv中字段[can_be_accelerate]位置不对应"); return false; }
		if(vecLine[47]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[48]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[49]!="skill_trigger_type"){Ex.Logger.Log("Skill.csv中字段[skill_trigger_type]位置不对应"); return false; }
		if(vecLine[50]!="event_addEP"){Ex.Logger.Log("Skill.csv中字段[event_addEP]位置不对应"); return false; }
		if(vecLine[51]!="skill_expend_point"){Ex.Logger.Log("Skill.csv中字段[skill_expend_point]位置不对应"); return false; }
		if(vecLine[52]!="expend_effect_resource"){Ex.Logger.Log("Skill.csv中字段[expend_effect_resource]位置不对应"); return false; }
		if(vecLine[53]!="reduce_cd_ski_list"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_ski_list]位置不对应"); return false; }
		if(vecLine[54]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[55]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }
		if(vecLine[56]!="notice_step_type"){Ex.Logger.Log("Skill.csv中字段[notice_step_type]位置不对应"); return false; }
		if(vecLine[57]!="notice_id"){Ex.Logger.Log("Skill.csv中字段[notice_id]位置不对应"); return false; }
		if(vecLine[58]!="continuance"){Ex.Logger.Log("Skill.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[59]!="script"){Ex.Logger.Log("Skill.csv中字段[script]位置不对应"); return false; }
		if(vecLine[60]!="automation_priority"){Ex.Logger.Log("Skill.csv中字段[automation_priority]位置不对应"); return false; }
		if(vecLine[61]!="automation_type"){Ex.Logger.Log("Skill.csv中字段[automation_type]位置不对应"); return false; }
		if(vecLine[62]!="waiting_message"){Ex.Logger.Log("Skill.csv中字段[waiting_message]位置不对应"); return false; }
		if(vecLine[63]!="replace"){Ex.Logger.Log("Skill.csv中字段[replace]位置不对应"); return false; }
		if(vecLine[64]!="can_insert"){Ex.Logger.Log("Skill.csv中字段[can_insert]位置不对应"); return false; }
		if(vecLine[65]!="share_skillcd"){Ex.Logger.Log("Skill.csv中字段[share_skillcd]位置不对应"); return false; }
		if(vecLine[66]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[67]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[68]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[69]!="server_script_id"){Ex.Logger.Log("Skill.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[70]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }
		if(vecLine[71]!="pet_cast_position"){Ex.Logger.Log("Skill.csv中字段[pet_cast_position]位置不对应"); return false; }
		if(vecLine[72]!="pet_cast_position_offset"){Ex.Logger.Log("Skill.csv中字段[pet_cast_position_offset]位置不对应"); return false; }
		if(vecLine[73]!="rune_name"){Ex.Logger.Log("Skill.csv中字段[rune_name]位置不对应"); return false; }
		if(vecLine[74]!="rune_icon"){Ex.Logger.Log("Skill.csv中字段[rune_icon]位置不对应"); return false; }
		if(vecLine[75]!="rune_icon_normal"){Ex.Logger.Log("Skill.csv中字段[rune_icon_normal]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)76)
			{
				return false;
			}
			SkillElement member = new SkillElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name_id=Convert.ToInt32(vecLine[1]);
			member.desc_id=Convert.ToInt32(vecLine[2]);
			member.type=Convert.ToInt32(vecLine[3]);
			member.buff_count_type=Convert.ToInt32(vecLine[4]);
			member.is_prepare=Convert.ToInt32(vecLine[5]);
			member.is_prepare_par=vecLine[6];
			member.prepare_show=vecLine[7];
			member.class_restriction=Convert.ToInt32(vecLine[8]);
			member.max_stack=Convert.ToInt32(vecLine[9]);
			member.max_target_count=Convert.ToInt32(vecLine[10]);
			member.caster_type=Convert.ToInt32(vecLine[11]);
			member.cast_target=Convert.ToInt32(vecLine[12]);
			member.target_alive_status=Convert.ToInt32(vecLine[13]);
			member.can_interrupt=Convert.ToInt32(vecLine[14]);
			member.attack_empty=Convert.ToInt32(vecLine[15]);
			member.former_skill_buff=vecLine[16];
			member.extra_former_condition_id=Convert.ToInt32(vecLine[17]);
			member.extra_former_buff=vecLine[18];
			member.latter_skill_buff=vecLine[19];
			member.extra_latter_condition_id=Convert.ToInt32(vecLine[20]);
			member.extra_latter_buff=vecLine[21];
			member.cooldown_id=Convert.ToInt32(vecLine[22]);
			member.cooldown_time=Convert.ToInt32(vecLine[23]);
			member.common_cd_time=Convert.ToInt32(vecLine[24]);
			member.continuity=Convert.ToInt32(vecLine[25]);
			member.next_id=Convert.ToInt32(vecLine[26]);
			member.atk_id_list=vecLine[27];
			member.atk_prob_list=vecLine[28];
			member.skill_normal_all=vecLine[29];
			member.attack_range=Convert.ToSingle(vecLine[30]);
			member.show_release=Convert.ToInt32(vecLine[31]);
			member.is_translate=Convert.ToInt32(vecLine[32]);
			member.loop_skill=Convert.ToInt32(vecLine[33]);
			member.rang_type=Convert.ToInt32(vecLine[34]);
			member.rang_par1=Convert.ToSingle(vecLine[35]);
			member.rang_par2=Convert.ToSingle(vecLine[36]);
			member.release_type=Convert.ToInt32(vecLine[37]);
			member.resources_release=vecLine[38];
			member.Resources=vecLine[39];
			member.attack_ID=vecLine[40];
			member.resources_name=vecLine[41];
			member.icon=vecLine[42];
			member.can_break=Convert.ToInt32(vecLine[43]);
			member.repeatedly_skil_list=vecLine[44];
			member.interval_time=vecLine[45];
			member.can_be_accelerate=Convert.ToInt32(vecLine[46]);
			member.max_accumulate=Convert.ToInt32(vecLine[47]);
			member.min_accumulate_use=Convert.ToInt32(vecLine[48]);
			member.skill_trigger_type=Convert.ToInt32(vecLine[49]);
			member.event_addEP=Convert.ToSingle(vecLine[50]);
			member.skill_expend_point=Convert.ToInt32(vecLine[51]);
			member.expend_effect_resource=vecLine[52];
			member.reduce_cd_ski_list=vecLine[53];
			member.reduce_cd_type=Convert.ToInt32(vecLine[54]);
			member.reduce_cd_parameter=Convert.ToSingle(vecLine[55]);
			member.notice_step_type=Convert.ToInt32(vecLine[56]);
			member.notice_id=Convert.ToInt32(vecLine[57]);
			member.continuance=Convert.ToInt32(vecLine[58]);
			member.script=vecLine[59];
			member.automation_priority=Convert.ToInt32(vecLine[60]);
			member.automation_type=vecLine[61];
			member.waiting_message=Convert.ToInt32(vecLine[62]);
			member.replace=vecLine[63];
			member.can_insert=Convert.ToInt32(vecLine[64]);
			member.share_skillcd=Convert.ToInt32(vecLine[65]);
			member.channel_time=Convert.ToInt32(vecLine[66]);
			member.charge_time=Convert.ToInt32(vecLine[67]);
			member.charge_or_interval=Convert.ToInt32(vecLine[68]);
			member.server_script_id=vecLine[69];
			member.move_limit=Convert.ToInt32(vecLine[70]);
			member.pet_cast_position=Convert.ToInt32(vecLine[71]);
			member.pet_cast_position_offset=Convert.ToSingle(vecLine[72]);
			member.rune_name=Convert.ToInt32(vecLine[73]);
			member.rune_icon=vecLine[74];
			member.rune_icon_normal=vecLine[75];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
