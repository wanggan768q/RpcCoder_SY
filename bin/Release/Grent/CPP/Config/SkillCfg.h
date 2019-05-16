#ifndef __SKILL_CONFIG_H
#define __SKILL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//技能配置数据结构
struct SkillElement
{
	friend class SkillTable;
	int id;                      	//技能ID	1100000~2999999为主角技能预留ID段 1=战士 2=盗贼 3=骑士 4=猎人 5=法师 6=神秘使 7 ~ 71 = 马鬃草原世界
	int name_id;                 	//技能名称ID	关联语言表
	int desc_id;                 	//技能描述ID	
	string comment;              	//技能名称	仅策划用
	int type;                    	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=事件技能 5=连击技能 6=宠物技能 7=多层技能
	int class_restriction;       	//技能等级限制	需要角色或者怪物超过配置的等级后才能释放这个技能
	int max_stack;               	//最大技能层数	技能层数，若不是多层技能，则填1；若是，则填写最大技能层数
	int max_target_count;        	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	int caster_type;             	//技能释放者对象	技能释放者类型：  0= 主角 1 = 怪物
	int cast_target;             	//技能施法目标	影响技能释放目标和caster之间的阵营关系判断 1=自己 2=敌方单位 3=友方单位 4=敌方+友方 5=友方+自己 6=敌方+友方+自己
	int target_alive_status;     	//技能目标存活类型	0：技能只能对死亡目标生效 1：技能只能对活着的目标生效 2：会对死亡、存活的目标同时生效
	int can_interrupt;           	//能否被打断	0：不能被打断 1：能被打断 （只有NPC技能可被打断，玩家职业技能都无法被打断,默认无法被打断）
	int attack_empty;            	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 =不允许空放 1=允许空放
	vector<int> former_skill_buff;	//技能释放前施加的buff	表示在attack生效前给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	vector<int> latter_skill_buff;	//技能释放后施加的buff	表示在技能所有的attack生效后给caster添加的buff，多个buff用连接符“|”连接，没有触发的buff时，保持空值
	int cooldown_id;             	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	int cooldown_time;           	//冷却的时间	当技能类型为多层时，该字段表示恢复一层所需时间，其他类型表示正常的技能CD 单位：毫秒
	int common_cd_time;          	//公共CD时间	技能释放后，同冷却ID组的技能会共同按照该技能的公共CD事件进入冷却 单位：毫秒
	int continuity;              	//是否连续技能	0=非连续技能 1=连续技能
	int next_id;                 	//下一段技能ID	"-1"=没有下一段
	vector<int> atk_id_list;     	//普攻技能id随机列	普攻下一段可以播放的普攻id列表，多个技能id用连接符：”|“连结，没有填“-1”
	vector<float> atk_prob_list; 	//普攻技能id随机概率	atk_id_list中对应技能释放的概率，填写小数，多个概率值用连结符：“|”连结，多个概率总和需要等于1。没有填“-1”
	vector<int> skill_normal_all;	//普攻技能ID汇总	
	float attack_range;          	//技能释放距离	技能最大释放距离，显示为技能释放圆形范围
	int rang_type;               	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	float rang_par1;             	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	float rang_par2;             	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	int release_type;            	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形 6=固定距离圆形 7=固定距离矩形 8=目标点连环圆
	string resources_release;    	//释放资源	0=空值 1=SkillRangeSector 2=SkillRangeStrip 3=SkillRange 4=SkillRangeCircular 5=SkillRangeSquare_001 6=SkillRangeCircular_001 7=SkillRangeSquare_002 8=SkillRangeSquare_003 9=SkillRangeCircular_002
	string Resources;            	//动作资源	动作文件
	vector<int> attack_ID;       	//技能编辑器的attackID	仅策划查看用，修改需要在技能编辑器
	string resources_name;       	//对应资源	仅策划用
	string server_script_id;     	//技能脚本	该技能配置脚本的名称
	string icon;                 	//图标资源	图标资源文件
	int can_break;               	//连击次数	1为是 0为否
	vector<int> repeatedly_skil_list;	//多段技能列表	多段技能列表 默认为空
	vector<float> interval_time; 	//多段技能每次反应的等待时间	多段技能每次等待的反应间隔时间,单位：ms
	int max_accumulate;          	//最大积攒能量上限	应激技能能量积攒上限
	int min_accumulate_use;      	//发动应激技能最低能量要求	发动应激技能最低能量数量
	int skill_trigger_type;      	//应激技能触发类型	（空=没有事件，不积攒能量） 1=格挡 2=暴击 3=命中
	float event_addEP;           	//事件增加能量数量	1=1点能量 不足1点用小数
	vector<int> reduce_cd_ski_list;	//减少哪个技能cd	例（3.3.1 灼烧）
	int reduce_cd_type;          	//减少cd类型	1=固定值 2=百分比
	float reduce_cd_parameter;   	//减少cd参数	
	int notice_step_type;        	//提示时机	-1=没有提示 0=施法开始时 1=施法结束时
	int notice_id;               	//文本提示ID	关联文本提示表，没有则填-1
	int continuance;             	//提示消息持续时间	消息持续时间，单位ms，没有则填-1
	string script;               	//脚本名称	script不填的话则没有脚本
	int automation_priority;     	//自动战斗释放优先级	值越高，优先级越高
	vector<int> automation_type; 	//自动战斗技能类型	0：普通技能 1：治疗技能 2：复活技能
	int channel_time;            	//引导的时间(已无效）	已无效 单位：毫秒
	int charge_time;             	//吟唱的时间	单位：毫秒
	int charge_or_interval;      	//伤害段数	在一段时间之内， 释放多少次伤害（BUFF）
	int move_limit;              	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离

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
	SkillElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//技能配置封装类
class SkillTable
{
	friend class TableData;
private:
	SkillTable(){}
	~SkillTable(){}
	map<int, SkillElement>	m_mapElements;
	vector<SkillElement>	m_vecAllElements;
	SkillElement m_emptyItem;
public:
	static SkillTable& Instance()
	{
		static SkillTable sInstance;
		return sInstance;
	}

	SkillElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillElement>&	GetAllElement()
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
		if( LoadConfigContent("Skill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Skill.bin", strTableContent ) )
		{
			printf_message("配置文件[Skill.bin]未找到");
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
		if(vecLine.size() != 54)
		{
			printf_message("Skill.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Skill.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name_id"){printf_message("Skill.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="desc_id"){printf_message("Skill.csv中字段[desc_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="comment"){printf_message("Skill.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="type"){printf_message("Skill.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="class_restriction"){printf_message("Skill.csv中字段[class_restriction]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="max_stack"){printf_message("Skill.csv中字段[max_stack]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="max_target_count"){printf_message("Skill.csv中字段[max_target_count]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="caster_type"){printf_message("Skill.csv中字段[caster_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="cast_target"){printf_message("Skill.csv中字段[cast_target]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="target_alive_status"){printf_message("Skill.csv中字段[target_alive_status]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="can_interrupt"){printf_message("Skill.csv中字段[can_interrupt]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="attack_empty"){printf_message("Skill.csv中字段[attack_empty]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="former_skill_buff"){printf_message("Skill.csv中字段[former_skill_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="latter_skill_buff"){printf_message("Skill.csv中字段[latter_skill_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="cooldown_id"){printf_message("Skill.csv中字段[cooldown_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="cooldown_time"){printf_message("Skill.csv中字段[cooldown_time]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="common_cd_time"){printf_message("Skill.csv中字段[common_cd_time]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="continuity"){printf_message("Skill.csv中字段[continuity]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="next_id"){printf_message("Skill.csv中字段[next_id]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="atk_id_list"){printf_message("Skill.csv中字段[atk_id_list]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="atk_prob_list"){printf_message("Skill.csv中字段[atk_prob_list]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="skill_normal_all"){printf_message("Skill.csv中字段[skill_normal_all]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="attack_range"){printf_message("Skill.csv中字段[attack_range]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="rang_type"){printf_message("Skill.csv中字段[rang_type]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="rang_par1"){printf_message("Skill.csv中字段[rang_par1]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="rang_par2"){printf_message("Skill.csv中字段[rang_par2]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="release_type"){printf_message("Skill.csv中字段[release_type]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="resources_release"){printf_message("Skill.csv中字段[resources_release]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="Resources"){printf_message("Skill.csv中字段[Resources]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="attack_ID"){printf_message("Skill.csv中字段[attack_ID]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="resources_name"){printf_message("Skill.csv中字段[resources_name]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="server_script_id"){printf_message("Skill.csv中字段[server_script_id]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="icon"){printf_message("Skill.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="can_break"){printf_message("Skill.csv中字段[can_break]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="repeatedly_skil_list"){printf_message("Skill.csv中字段[repeatedly_skil_list]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="interval_time"){printf_message("Skill.csv中字段[interval_time]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="max_accumulate"){printf_message("Skill.csv中字段[max_accumulate]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="min_accumulate_use"){printf_message("Skill.csv中字段[min_accumulate_use]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="skill_trigger_type"){printf_message("Skill.csv中字段[skill_trigger_type]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="event_addEP"){printf_message("Skill.csv中字段[event_addEP]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="reduce_cd_ski_list"){printf_message("Skill.csv中字段[reduce_cd_ski_list]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="reduce_cd_type"){printf_message("Skill.csv中字段[reduce_cd_type]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){printf_message("Skill.csv中字段[reduce_cd_parameter]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="notice_step_type"){printf_message("Skill.csv中字段[notice_step_type]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="notice_id"){printf_message("Skill.csv中字段[notice_id]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="continuance"){printf_message("Skill.csv中字段[continuance]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="script"){printf_message("Skill.csv中字段[script]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="automation_priority"){printf_message("Skill.csv中字段[automation_priority]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="automation_type"){printf_message("Skill.csv中字段[automation_type]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="channel_time"){printf_message("Skill.csv中字段[channel_time]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="charge_time"){printf_message("Skill.csv中字段[charge_time]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="charge_or_interval"){printf_message("Skill.csv中字段[charge_or_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="move_limit"){printf_message("Skill.csv中字段[move_limit]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)54)
			{
				assert(false);
				return false;
			}
			SkillElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name_id=(int)atoi(vecLine[1].c_str());
			member.desc_id=(int)atoi(vecLine[2].c_str());
			member.comment=vecLine[3];
			member.type=(int)atoi(vecLine[4].c_str());
			member.class_restriction=(int)atoi(vecLine[5].c_str());
			member.max_stack=(int)atoi(vecLine[6].c_str());
			member.max_target_count=(int)atoi(vecLine[7].c_str());
			member.caster_type=(int)atoi(vecLine[8].c_str());
			member.cast_target=(int)atoi(vecLine[9].c_str());
			member.target_alive_status=(int)atoi(vecLine[10].c_str());
			member.can_interrupt=(int)atoi(vecLine[11].c_str());
			member.attack_empty=(int)atoi(vecLine[12].c_str());
			member.cooldown_id=(int)atoi(vecLine[15].c_str());
			member.cooldown_time=(int)atoi(vecLine[16].c_str());
			member.common_cd_time=(int)atoi(vecLine[17].c_str());
			member.continuity=(int)atoi(vecLine[18].c_str());
			member.next_id=(int)atoi(vecLine[19].c_str());
			member.attack_range=(float)atof(vecLine[23].c_str());
			member.rang_type=(int)atoi(vecLine[24].c_str());
			member.rang_par1=(float)atof(vecLine[25].c_str());
			member.rang_par2=(float)atof(vecLine[26].c_str());
			member.release_type=(int)atoi(vecLine[27].c_str());
			member.resources_release=vecLine[28];
			member.Resources=vecLine[29];
			member.resources_name=vecLine[31];
			member.server_script_id=vecLine[32];
			member.icon=vecLine[33];
			member.can_break=(int)atoi(vecLine[34].c_str());
			member.max_accumulate=(int)atoi(vecLine[37].c_str());
			member.min_accumulate_use=(int)atoi(vecLine[38].c_str());
			member.skill_trigger_type=(int)atoi(vecLine[39].c_str());
			member.event_addEP=(float)atof(vecLine[40].c_str());
			member.reduce_cd_type=(int)atoi(vecLine[42].c_str());
			member.reduce_cd_parameter=(float)atof(vecLine[43].c_str());
			member.notice_step_type=(int)atoi(vecLine[44].c_str());
			member.notice_id=(int)atoi(vecLine[45].c_str());
			member.continuance=(int)atoi(vecLine[46].c_str());
			member.script=vecLine[47];
			member.automation_priority=(int)atoi(vecLine[48].c_str());
			member.channel_time=(int)atoi(vecLine[50].c_str());
			member.charge_time=(int)atoi(vecLine[51].c_str());
			member.charge_or_interval=(int)atoi(vecLine[52].c_str());
			member.move_limit=(int)atoi(vecLine[53].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
