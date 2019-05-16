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
	public string comment;       	//技能名称	仅策划用
	public int type;             	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=事件技能 5=连击技能 6=宠物技能 7=多层技能
	public int class_restriction;	//技能等级限制	需要角色或者怪物超过配置的等级后才能释放这个技能
	public int max_stack;        	//最大技能层数	技能层数，若不是多层技能，则填1；若是，则填写最大技能层数
	public int max_target_count; 	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	public int caster_type;      	//技能释放者对象	技能释放者类型：  0= 主角 1 = 怪物
	public int cast_target;      	//技能施法目标	影响技能释放目标和caster之间的阵营关系判断 1=自己 2=敌方单位 3=友方单位 4=敌方+友方 5=友方+自己 6=敌方+友方+自己
	public int target_alive_status;	//技能目标存活类型	0：技能只能对死亡目标生效 1：技能只能对活着的目标生效 2：会对死亡、存活的目标同时生效
	public int can_interrupt;    	//能否被打断	0：不能被打断 1：能被打断 （只有NPC技能可被打断，玩家职业技能都无法被打断,默认无法被打断）
	public int attack_empty;     	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 =不允许空放 1=允许空放
	public li former_skill_buff; 	//技能释放前施加的buff	表示在attack生效前给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	public li latter_skill_buff; 	//技能释放后施加的buff	表示在技能所有的attack生效后给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	public int cooldown_id;      	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	public int cooldown_time;    	//冷却的时间	当技能类型为多层时，该字段表示恢复一层所需时间，其他类型表示正常的技能CD 单位：毫秒
	public int common_cd_time;   	//公共CD时间	技能释放后，同冷却ID组的技能会共同按照该技能的公共CD事件进入冷却 单位：毫秒
	public int continuity;       	//是否连续技能	0=非连续技能 1=连续技能
	public int next_id;          	//下一段技能ID	"-1"=没有下一段
	public li atk_id_list;       	//普攻技能id随机列	普攻下一段可以播放的普攻id列表，多个技能id用连接符：”|“连结，没有填“-1”
	public lf atk_prob_list;     	//普攻技能id随机概率	atk_id_list中对应技能释放的概率，填写小数，多个概率值用连结符：“|”连结，多个概率总和需要等于1。没有填“-1”
	public li skill_normal_all;  	//普攻技能ID汇总	
	public float attack_range;   	//技能释放距离	技能最大释放距离，显示为技能释放圆形范围
	public int rang_type;        	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	public float rang_par1;      	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	public float rang_par2;      	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	public int release_type;     	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形 6=固定距离圆形 7=固定距离矩形 8=目标点连环圆
	public string resources_release;	//释放资源	0=空值 1=SkillRangeSector 2=SkillRangeStrip 3=SkillRange 4=SkillRangeCircular 5=SkillRangeSquare_001 6=SkillRangeCircular_001 7=SkillRangeSquare_002 8=SkillRangeSquare_003 9=SkillRangeCircular_002
	public string Resources;     	//动作资源	动作文件
	public li attack_ID;         	//技能编辑器的attackID	仅策划查看用，修改需要在技能编辑器
	public string resources_name;	//对应资源	仅策划用
	public string server_script_id;	//技能脚本	该技能配置脚本的名称
	public string icon;          	//图标资源	图标资源文件
	public int can_break;        	//连击次数	1为是 0为否
	public li repeatedly_skil_list;	//多段技能列表	多段技能列表 默认为空
	public lf interval_time;     	//多段技能每次反应的等待时间	多段技能每次等待的反应间隔时间,单位：ms
	public int max_accumulate;   	//最大积攒能量上限	应激技能能量积攒上限
	public int min_accumulate_use;	//发动应激技能最低能量要求	发动应激技能最低能量数量
	public int skill_trigger_type;	//应激技能触发类型	（空=没有事件，不积攒能量） 1=格挡 2=暴击 3=命中
	public float event_addEP;    	//事件增加能量数量	1=1点能量 不足1点用小数
	public li reduce_cd_ski_list;	//减少哪个技能cd	例（3.3.1 灼烧）
	public int reduce_cd_type;   	//减少cd类型	1=固定值 2=百分比
	public float reduce_cd_parameter;	//减少cd参数	
	public int notice_step_type; 	//提示时机	-1=没有提示 0=施法开始时 1=施法结束时
	public int notice_id;        	//文本提示ID	关联文本提示表，没有则填-1
	public int continuance;      	//提示消息持续时间	消息持续时间，单位ms，没有则填-1
	public string script;        	//脚本名称	script不填的话则没有脚本
	public int automation_priority;	//自动战斗释放优先级	值越高，优先级越高
	public li automation_type;   	//自动战斗技能类型	0：普通技能 1：治疗技能 2：复活技能
	public int channel_time;     	//引导的时间(已无效）	已无效 单位：毫秒
	public int charge_time;      	//吟唱的时间	单位：毫秒
	public int charge_or_interval;	//伤害段数	在一段时间之内， 释放多少次伤害（BUFF）
	public int move_limit;       	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离

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
		if(vecLine.Count != 54)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("Skill.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="comment"){Ex.Logger.Log("Skill.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[4]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[5]!="class_restriction"){Ex.Logger.Log("Skill.csv中字段[class_restriction]位置不对应"); return false; }
		if(vecLine[6]!="max_stack"){Ex.Logger.Log("Skill.csv中字段[max_stack]位置不对应"); return false; }
		if(vecLine[7]!="max_target_count"){Ex.Logger.Log("Skill.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[8]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[9]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[10]!="target_alive_status"){Ex.Logger.Log("Skill.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[11]!="can_interrupt"){Ex.Logger.Log("Skill.csv中字段[can_interrupt]位置不对应"); return false; }
		if(vecLine[12]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[13]!="former_skill_buff"){Ex.Logger.Log("Skill.csv中字段[former_skill_buff]位置不对应"); return false; }
		if(vecLine[14]!="latter_skill_buff"){Ex.Logger.Log("Skill.csv中字段[latter_skill_buff]位置不对应"); return false; }
		if(vecLine[15]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[16]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[17]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[18]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[19]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[20]!="atk_id_list"){Ex.Logger.Log("Skill.csv中字段[atk_id_list]位置不对应"); return false; }
		if(vecLine[21]!="atk_prob_list"){Ex.Logger.Log("Skill.csv中字段[atk_prob_list]位置不对应"); return false; }
		if(vecLine[22]!="skill_normal_all"){Ex.Logger.Log("Skill.csv中字段[skill_normal_all]位置不对应"); return false; }
		if(vecLine[23]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[24]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[25]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[26]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[27]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[28]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[29]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[30]!="attack_ID"){Ex.Logger.Log("Skill.csv中字段[attack_ID]位置不对应"); return false; }
		if(vecLine[31]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[32]!="server_script_id"){Ex.Logger.Log("Skill.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[33]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[34]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[35]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[36]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[37]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[38]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[39]!="skill_trigger_type"){Ex.Logger.Log("Skill.csv中字段[skill_trigger_type]位置不对应"); return false; }
		if(vecLine[40]!="event_addEP"){Ex.Logger.Log("Skill.csv中字段[event_addEP]位置不对应"); return false; }
		if(vecLine[41]!="reduce_cd_ski_list"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_ski_list]位置不对应"); return false; }
		if(vecLine[42]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }
		if(vecLine[44]!="notice_step_type"){Ex.Logger.Log("Skill.csv中字段[notice_step_type]位置不对应"); return false; }
		if(vecLine[45]!="notice_id"){Ex.Logger.Log("Skill.csv中字段[notice_id]位置不对应"); return false; }
		if(vecLine[46]!="continuance"){Ex.Logger.Log("Skill.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[47]!="script"){Ex.Logger.Log("Skill.csv中字段[script]位置不对应"); return false; }
		if(vecLine[48]!="automation_priority"){Ex.Logger.Log("Skill.csv中字段[automation_priority]位置不对应"); return false; }
		if(vecLine[49]!="automation_type"){Ex.Logger.Log("Skill.csv中字段[automation_type]位置不对应"); return false; }
		if(vecLine[50]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[51]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[52]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[53]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillElement member = new SkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.class_restriction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_stack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_target_count );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.caster_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cast_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_alive_status );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_interrupt );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_empty );
			readPos += GameAssist.ReadString( binContent, readPos, out member.former_skill_buff);
			readPos += GameAssist.ReadString( binContent, readPos, out member.latter_skill_buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.common_cd_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuity );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.atk_id_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.atk_prob_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_normal_all);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attack_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rang_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par1);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.release_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_release);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Resources);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attack_ID);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.server_script_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_break );
			readPos += GameAssist.ReadString( binContent, readPos, out member.repeatedly_skil_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.interval_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_accumulate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.min_accumulate_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_trigger_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.event_addEP);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reduce_cd_ski_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reduce_cd_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.reduce_cd_parameter);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.notice_step_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.notice_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.automation_priority );
			readPos += GameAssist.ReadString( binContent, readPos, out member.automation_type);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.channel_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_or_interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.move_limit );

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
		if(vecLine.Count != 54)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="desc_id"){Ex.Logger.Log("Skill.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[3]!="comment"){Ex.Logger.Log("Skill.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[4]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[5]!="class_restriction"){Ex.Logger.Log("Skill.csv中字段[class_restriction]位置不对应"); return false; }
		if(vecLine[6]!="max_stack"){Ex.Logger.Log("Skill.csv中字段[max_stack]位置不对应"); return false; }
		if(vecLine[7]!="max_target_count"){Ex.Logger.Log("Skill.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[8]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[9]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[10]!="target_alive_status"){Ex.Logger.Log("Skill.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[11]!="can_interrupt"){Ex.Logger.Log("Skill.csv中字段[can_interrupt]位置不对应"); return false; }
		if(vecLine[12]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[13]!="former_skill_buff"){Ex.Logger.Log("Skill.csv中字段[former_skill_buff]位置不对应"); return false; }
		if(vecLine[14]!="latter_skill_buff"){Ex.Logger.Log("Skill.csv中字段[latter_skill_buff]位置不对应"); return false; }
		if(vecLine[15]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[16]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[17]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[18]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[19]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[20]!="atk_id_list"){Ex.Logger.Log("Skill.csv中字段[atk_id_list]位置不对应"); return false; }
		if(vecLine[21]!="atk_prob_list"){Ex.Logger.Log("Skill.csv中字段[atk_prob_list]位置不对应"); return false; }
		if(vecLine[22]!="skill_normal_all"){Ex.Logger.Log("Skill.csv中字段[skill_normal_all]位置不对应"); return false; }
		if(vecLine[23]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[24]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[25]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[26]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[27]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[28]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[29]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[30]!="attack_ID"){Ex.Logger.Log("Skill.csv中字段[attack_ID]位置不对应"); return false; }
		if(vecLine[31]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[32]!="server_script_id"){Ex.Logger.Log("Skill.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[33]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[34]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[35]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[36]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[37]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[38]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[39]!="skill_trigger_type"){Ex.Logger.Log("Skill.csv中字段[skill_trigger_type]位置不对应"); return false; }
		if(vecLine[40]!="event_addEP"){Ex.Logger.Log("Skill.csv中字段[event_addEP]位置不对应"); return false; }
		if(vecLine[41]!="reduce_cd_ski_list"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_ski_list]位置不对应"); return false; }
		if(vecLine[42]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }
		if(vecLine[44]!="notice_step_type"){Ex.Logger.Log("Skill.csv中字段[notice_step_type]位置不对应"); return false; }
		if(vecLine[45]!="notice_id"){Ex.Logger.Log("Skill.csv中字段[notice_id]位置不对应"); return false; }
		if(vecLine[46]!="continuance"){Ex.Logger.Log("Skill.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[47]!="script"){Ex.Logger.Log("Skill.csv中字段[script]位置不对应"); return false; }
		if(vecLine[48]!="automation_priority"){Ex.Logger.Log("Skill.csv中字段[automation_priority]位置不对应"); return false; }
		if(vecLine[49]!="automation_type"){Ex.Logger.Log("Skill.csv中字段[automation_type]位置不对应"); return false; }
		if(vecLine[50]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[51]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[52]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[53]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)54)
			{
				return false;
			}
			SkillElement member = new SkillElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name_id=Convert.ToInt32(vecLine[1]);
			member.desc_id=Convert.ToInt32(vecLine[2]);
			member.comment=vecLine[3];
			member.type=Convert.ToInt32(vecLine[4]);
			member.class_restriction=Convert.ToInt32(vecLine[5]);
			member.max_stack=Convert.ToInt32(vecLine[6]);
			member.max_target_count=Convert.ToInt32(vecLine[7]);
			member.caster_type=Convert.ToInt32(vecLine[8]);
			member.cast_target=Convert.ToInt32(vecLine[9]);
			member.target_alive_status=Convert.ToInt32(vecLine[10]);
			member.can_interrupt=Convert.ToInt32(vecLine[11]);
			member.attack_empty=Convert.ToInt32(vecLine[12]);
			member.former_skill_buff=vecLine[13];
			member.latter_skill_buff=vecLine[14];
			member.cooldown_id=Convert.ToInt32(vecLine[15]);
			member.cooldown_time=Convert.ToInt32(vecLine[16]);
			member.common_cd_time=Convert.ToInt32(vecLine[17]);
			member.continuity=Convert.ToInt32(vecLine[18]);
			member.next_id=Convert.ToInt32(vecLine[19]);
			member.atk_id_list=vecLine[20];
			member.atk_prob_list=vecLine[21];
			member.skill_normal_all=vecLine[22];
			member.attack_range=Convert.ToSingle(vecLine[23]);
			member.rang_type=Convert.ToInt32(vecLine[24]);
			member.rang_par1=Convert.ToSingle(vecLine[25]);
			member.rang_par2=Convert.ToSingle(vecLine[26]);
			member.release_type=Convert.ToInt32(vecLine[27]);
			member.resources_release=vecLine[28];
			member.Resources=vecLine[29];
			member.attack_ID=vecLine[30];
			member.resources_name=vecLine[31];
			member.server_script_id=vecLine[32];
			member.icon=vecLine[33];
			member.can_break=Convert.ToInt32(vecLine[34]);
			member.repeatedly_skil_list=vecLine[35];
			member.interval_time=vecLine[36];
			member.max_accumulate=Convert.ToInt32(vecLine[37]);
			member.min_accumulate_use=Convert.ToInt32(vecLine[38]);
			member.skill_trigger_type=Convert.ToInt32(vecLine[39]);
			member.event_addEP=Convert.ToSingle(vecLine[40]);
			member.reduce_cd_ski_list=vecLine[41];
			member.reduce_cd_type=Convert.ToInt32(vecLine[42]);
			member.reduce_cd_parameter=Convert.ToSingle(vecLine[43]);
			member.notice_step_type=Convert.ToInt32(vecLine[44]);
			member.notice_id=Convert.ToInt32(vecLine[45]);
			member.continuance=Convert.ToInt32(vecLine[46]);
			member.script=vecLine[47];
			member.automation_priority=Convert.ToInt32(vecLine[48]);
			member.automation_type=vecLine[49];
			member.channel_time=Convert.ToInt32(vecLine[50]);
			member.charge_time=Convert.ToInt32(vecLine[51]);
			member.charge_or_interval=Convert.ToInt32(vecLine[52]);
			member.move_limit=Convert.ToInt32(vecLine[53]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
