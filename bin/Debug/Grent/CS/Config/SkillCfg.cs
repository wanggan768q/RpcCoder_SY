using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能配置数据类
public class SkillElement
{
	public int id;               	//技能ID	1000=战士 2000=盗贼 3000=骑士 4000=猎人 5000=法师 6000=神秘使
	public int name_id;          	//技能名称ID	关联语言表
	public string name;          	//技能名称	仅策划用
	public int type;             	//技能类型	1=普通攻击 2=普通技能 3=多段技能 4=事件技能
	public int caster_type;      	//技能释放者对象	释放技能的对象类型： 0 = 主角 1 = 怪物
	public int is_scene_event;   	//是否是放置类	0：不是 1：是
	public int effect_target;    	//技能生效目标 	1=自己 2=敌方单位 4=友方单位 5=自己+友方
	public int cast_target;      	//技能施法目标	0=对自己释放 1=对敌人施放 2=对自己&友方释放 3=对目标点释放 4=对面向释放
	public int ligic_id;         	//释放的逻辑	0=暂时无效 1=释放Buff 2=召唤小怪
	public li pars;              	//buff参数	buffID 释放逻辑-1，无效 释放逻辑1，伤害 释放逻辑2，延迟伤害 释放逻辑3，治疗 其他ID查看buff表
	public int attack_empty;     	//是否允许空放	对目标释放的技能，当没有目标时是否允许空放 0=不允许空放 1=允许空放
	public int charge_or_interval;	//伤害段数	在一段时间之内， 释放多少次伤害（BUFF）
	public int cooldown_id;      	//冷却ID组ID	"-1"=表示没有冷却组，最大组ID位32767
	public int cooldown_time;    	//冷却的时间	单位：毫秒
	public int common_cd_time;   	//公共CD时间	单位：毫秒
	public int charge_time;      	//引唱的时间	单位：毫秒
	public int channel_time;     	//引导的时间	单位：毫秒
	public int attack_type;      	//攻击的类型	0:物理攻击, 1:法术攻击, 2:物理&法术攻击
	public float attack_rate;    	//技能伤害系数	0=不计算伤害 1=100
	public int attack_value;     	//技能伤害附加	技能伤害附加
	public float attack_range;   	//技能释放距离	技能释放距离
	public int continuity;       	//是否连续技能	0=非连续技能 1=连续技能
	public int next_id;          	//下一段技能ID	"-1"=没有下一段
	public int move_limit;       	//是否能够位移	0=不移动 1=走编辑器的距离配置值 2=玩家手动规定移动距离
	public int rang_type;        	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形
	public float rang_par1;      	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长
	public float rang_par2;      	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽
	public int release_type;     	//释放类型	0=选择目标 1=扇形范围 2=直线范围 3=圆形范围 4=目标点圆形 5=目标点矩形
	public string resources_release;	//释放资源	0=-1 1=SkillRangeSector 2=SkillRangeStrip 3=SkillRange 4=SkillRangeCircular 5=SkillRangeLine
	public string Resources;     	//动作资源	动作文件
	public string resources_name;	//对应资源	仅策划用
	public string icon;          	//图标资源	图标资源文件
	public int summon_monster_amount;	//召唤的小怪数量	
	public li summon_monster_list1;	//召唤的小怪组1	
	public li summon_monster_list2;	//召唤的小怪组2	
	public li summon_monster_list3;	//召唤的小怪组3	
	public int can_break;        	//连击次数	1为是 0为否
	public li repeatedly_skil_list;	//多段技能列表	多段技能列表
	public float interval_time;  	//多段技能每次间隔时间	多段技能每次间隔时间
	public int max_accumulate;   	//最大积攒	
	public int min_accumulate_use;	//最低积攒使用	最低几个积攒能触发此技能
	public int event;            	//事件	1=格挡 2=暴击 3=命中
	public int reduce_cd_type;   	//减少cd类型	1=固定值 2=百分比
	public float reduce_cd_parameter;	//减少cd参数	

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
		if(vecLine.Count != 44)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Skill.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[5]!="is_scene_event"){Ex.Logger.Log("Skill.csv中字段[is_scene_event]位置不对应"); return false; }
		if(vecLine[6]!="effect_target"){Ex.Logger.Log("Skill.csv中字段[effect_target]位置不对应"); return false; }
		if(vecLine[7]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[8]!="ligic_id"){Ex.Logger.Log("Skill.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[9]!="pars"){Ex.Logger.Log("Skill.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[10]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[11]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[12]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[13]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[14]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[15]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[16]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[17]!="attack_type"){Ex.Logger.Log("Skill.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[18]!="attack_rate"){Ex.Logger.Log("Skill.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[19]!="attack_value"){Ex.Logger.Log("Skill.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[20]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[21]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[22]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[23]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }
		if(vecLine[24]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[25]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[26]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[27]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[28]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[29]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[30]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[31]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[32]!="summon_monster_amount"){Ex.Logger.Log("Skill.csv中字段[summon_monster_amount]位置不对应"); return false; }
		if(vecLine[33]!="summon_monster_list1"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list1]位置不对应"); return false; }
		if(vecLine[34]!="summon_monster_list2"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list2]位置不对应"); return false; }
		if(vecLine[35]!="summon_monster_list3"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list3]位置不对应"); return false; }
		if(vecLine[36]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[37]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[38]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[39]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[40]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[41]!="event"){Ex.Logger.Log("Skill.csv中字段[event]位置不对应"); return false; }
		if(vecLine[42]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillElement member = new SkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.caster_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_scene_event );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cast_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ligic_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_empty );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_or_interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.common_cd_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.channel_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attack_rate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_value );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attack_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuity );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.move_limit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rang_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par1);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.release_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_release);
			readPos += GameAssist.ReadString( binContent, readPos, out member.Resources);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resources_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.summon_monster_amount );
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_break );
			readPos += GameAssist.ReadString( binContent, readPos, out member.repeatedly_skil_list);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.interval_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_accumulate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.min_accumulate_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.event );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reduce_cd_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.reduce_cd_parameter);

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
		if(vecLine.Count != 44)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name_id"){Ex.Logger.Log("Skill.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Skill.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Skill.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="caster_type"){Ex.Logger.Log("Skill.csv中字段[caster_type]位置不对应"); return false; }
		if(vecLine[5]!="is_scene_event"){Ex.Logger.Log("Skill.csv中字段[is_scene_event]位置不对应"); return false; }
		if(vecLine[6]!="effect_target"){Ex.Logger.Log("Skill.csv中字段[effect_target]位置不对应"); return false; }
		if(vecLine[7]!="cast_target"){Ex.Logger.Log("Skill.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[8]!="ligic_id"){Ex.Logger.Log("Skill.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[9]!="pars"){Ex.Logger.Log("Skill.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[10]!="attack_empty"){Ex.Logger.Log("Skill.csv中字段[attack_empty]位置不对应"); return false; }
		if(vecLine[11]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[12]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[13]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[14]!="common_cd_time"){Ex.Logger.Log("Skill.csv中字段[common_cd_time]位置不对应"); return false; }
		if(vecLine[15]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[16]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[17]!="attack_type"){Ex.Logger.Log("Skill.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[18]!="attack_rate"){Ex.Logger.Log("Skill.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[19]!="attack_value"){Ex.Logger.Log("Skill.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[20]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }
		if(vecLine[21]!="continuity"){Ex.Logger.Log("Skill.csv中字段[continuity]位置不对应"); return false; }
		if(vecLine[22]!="next_id"){Ex.Logger.Log("Skill.csv中字段[next_id]位置不对应"); return false; }
		if(vecLine[23]!="move_limit"){Ex.Logger.Log("Skill.csv中字段[move_limit]位置不对应"); return false; }
		if(vecLine[24]!="rang_type"){Ex.Logger.Log("Skill.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[25]!="rang_par1"){Ex.Logger.Log("Skill.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[26]!="rang_par2"){Ex.Logger.Log("Skill.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[27]!="release_type"){Ex.Logger.Log("Skill.csv中字段[release_type]位置不对应"); return false; }
		if(vecLine[28]!="resources_release"){Ex.Logger.Log("Skill.csv中字段[resources_release]位置不对应"); return false; }
		if(vecLine[29]!="Resources"){Ex.Logger.Log("Skill.csv中字段[Resources]位置不对应"); return false; }
		if(vecLine[30]!="resources_name"){Ex.Logger.Log("Skill.csv中字段[resources_name]位置不对应"); return false; }
		if(vecLine[31]!="icon"){Ex.Logger.Log("Skill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[32]!="summon_monster_amount"){Ex.Logger.Log("Skill.csv中字段[summon_monster_amount]位置不对应"); return false; }
		if(vecLine[33]!="summon_monster_list1"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list1]位置不对应"); return false; }
		if(vecLine[34]!="summon_monster_list2"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list2]位置不对应"); return false; }
		if(vecLine[35]!="summon_monster_list3"){Ex.Logger.Log("Skill.csv中字段[summon_monster_list3]位置不对应"); return false; }
		if(vecLine[36]!="can_break"){Ex.Logger.Log("Skill.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[37]!="repeatedly_skil_list"){Ex.Logger.Log("Skill.csv中字段[repeatedly_skil_list]位置不对应"); return false; }
		if(vecLine[38]!="interval_time"){Ex.Logger.Log("Skill.csv中字段[interval_time]位置不对应"); return false; }
		if(vecLine[39]!="max_accumulate"){Ex.Logger.Log("Skill.csv中字段[max_accumulate]位置不对应"); return false; }
		if(vecLine[40]!="min_accumulate_use"){Ex.Logger.Log("Skill.csv中字段[min_accumulate_use]位置不对应"); return false; }
		if(vecLine[41]!="event"){Ex.Logger.Log("Skill.csv中字段[event]位置不对应"); return false; }
		if(vecLine[42]!="reduce_cd_type"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_type]位置不对应"); return false; }
		if(vecLine[43]!="reduce_cd_parameter"){Ex.Logger.Log("Skill.csv中字段[reduce_cd_parameter]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)44)
			{
				return false;
			}
			SkillElement member = new SkillElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name_id=Convert.ToInt32(vecLine[1]);
			member.name=vecLine[2];
			member.type=Convert.ToInt32(vecLine[3]);
			member.caster_type=Convert.ToInt32(vecLine[4]);
			member.is_scene_event=Convert.ToInt32(vecLine[5]);
			member.effect_target=Convert.ToInt32(vecLine[6]);
			member.cast_target=Convert.ToInt32(vecLine[7]);
			member.ligic_id=Convert.ToInt32(vecLine[8]);
			member.pars=vecLine[9];
			member.attack_empty=Convert.ToInt32(vecLine[10]);
			member.charge_or_interval=Convert.ToInt32(vecLine[11]);
			member.cooldown_id=Convert.ToInt32(vecLine[12]);
			member.cooldown_time=Convert.ToInt32(vecLine[13]);
			member.common_cd_time=Convert.ToInt32(vecLine[14]);
			member.charge_time=Convert.ToInt32(vecLine[15]);
			member.channel_time=Convert.ToInt32(vecLine[16]);
			member.attack_type=Convert.ToInt32(vecLine[17]);
			member.attack_rate=Convert.ToSingle(vecLine[18]);
			member.attack_value=Convert.ToInt32(vecLine[19]);
			member.attack_range=Convert.ToSingle(vecLine[20]);
			member.continuity=Convert.ToInt32(vecLine[21]);
			member.next_id=Convert.ToInt32(vecLine[22]);
			member.move_limit=Convert.ToInt32(vecLine[23]);
			member.rang_type=Convert.ToInt32(vecLine[24]);
			member.rang_par1=Convert.ToSingle(vecLine[25]);
			member.rang_par2=Convert.ToSingle(vecLine[26]);
			member.release_type=Convert.ToInt32(vecLine[27]);
			member.resources_release=vecLine[28];
			member.Resources=vecLine[29];
			member.resources_name=vecLine[30];
			member.icon=vecLine[31];
			member.summon_monster_amount=Convert.ToInt32(vecLine[32]);
			member.summon_monster_list1=vecLine[33];
			member.summon_monster_list2=vecLine[34];
			member.summon_monster_list3=vecLine[35];
			member.can_break=Convert.ToInt32(vecLine[36]);
			member.repeatedly_skil_list=vecLine[37];
			member.interval_time=Convert.ToSingle(vecLine[38]);
			member.max_accumulate=Convert.ToInt32(vecLine[39]);
			member.min_accumulate_use=Convert.ToInt32(vecLine[40]);
			member.event=Convert.ToInt32(vecLine[41]);
			member.reduce_cd_type=Convert.ToInt32(vecLine[42]);
			member.reduce_cd_parameter=Convert.ToSingle(vecLine[43]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
