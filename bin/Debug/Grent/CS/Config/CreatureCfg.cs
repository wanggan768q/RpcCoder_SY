using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//总NPC表配置数据类
public class CreatureElement
{
	public int entry_id;         	//序号	序号
	public int script_ID;        	//脚本ID	脚本ID填写为NPC的ID -1为没有脚本
	public int combat_coe_id;    	//战斗系数ID	战斗系数ID
	public int combat_attributes_id;	//战斗属性ID	战斗属性ID
	public int temper_id;        	//AI类型ID	关联 CreatureTemperConfig
	public string gd_comment;    	//策划备注	策划备注
	public int name_id;          	//名字文本ID	名字文本ID
	public int sub_name_id;      	//子名字文本ID	子名字文本ID
	public int model_id;         	//模型id	模型id
	public string mapping_path;  	//贴图路径	贴图路径
	public float scale;          	//NPC大小	NPC大小
	public float opacity;        	//透明度	透明度
	public string icon;          	//图标路径	图标路径
	public int health_bar_display;	//血条显示	血条显示
	public int name_bar_display; 	//名字显示	名字显示
	public int creature_level;   	//怪物等级	怪物等级
	public int creature_type;    	//怪物类型	怪物类型
	public int faction;          	//阵营	阵营
	public int race;             	//种族	种族
	public float boundary_length;	//包围盒底部长度	包围盒底部长度
	public float boundary_width; 	//包围盒底部宽度	包围盒底部宽度
	public float boundary_height;	//包围盒高度	包围盒高度
	public float walk_speed;     	//走路速度	走路速度
	public float run_speed;      	//跑步速度	跑步速度
	public int can_be_targeted;  	//是否可以被攻击或选中	是否可以被攻击或选中
	public int can_attack;       	//是否可以进行攻击	是否可以进行攻击
	public int pool_skill_num;   	//从技能池里随机出来的数量	从技能池里随机出来的数量
	public string selected_sound;	//被选中音效	被选中音效
	public string death_sound;   	//死亡音效	死亡音效
	public li initial_skill;     	//NPC的技能数组	关联之后的技能，如果没有技能则不填
	public int skill_1;          	//技能1	仅策划用
	public int skill_2;          	//技能2	仅策划用
	public int skill_3;          	//技能3	仅策划用
	public int skill_4;          	//技能4	仅策划用
	public int skill_5;          	//技能5	仅策划用
	public li rebirth_buffs;     	//出生的时候释放buff	出生的时候释放buff
	public string verification;  	//技能验证	仅策划用 二进制检验
	public int is_wondering;     	//是否在范围内漫步	是否在范围内漫步
	public int is_play_born_animation;	//是否需要播放出生动画	是否需要播放出生动画
	public int born_anim_duration_buff;	//出生动画持续时的效果buff ID	出生动画持续时的效果buff ID
	public int born_anim_effect_buff;	//出生动画持续时的时长buff ID	出生动画持续时的时长buff ID
	public string born_animation_name;	//出生动画名称	出生动画名称
	public string combat_entry_skill;	//进入战斗的技能	进入战斗的技能
	public int corpse_vanish_time;	//尸体消失时间	尸体消失时间

	public bool IsValidate = false;
	public CreatureElement()
	{
		entry_id = -1;
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
		if(vecLine.Count != 44)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="entry_id"){Ex.Logger.Log("Creature.csv中字段[entry_id]位置不对应"); return false; }
		if(vecLine[1]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[2]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[3]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[4]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[5]!="gd_comment"){Ex.Logger.Log("Creature.csv中字段[gd_comment]位置不对应"); return false; }
		if(vecLine[6]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[7]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[8]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[9]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[10]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[11]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[12]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[13]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[14]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[15]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[16]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[17]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[18]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[19]!="boundary_length"){Ex.Logger.Log("Creature.csv中字段[boundary_length]位置不对应"); return false; }
		if(vecLine[20]!="boundary_width"){Ex.Logger.Log("Creature.csv中字段[boundary_width]位置不对应"); return false; }
		if(vecLine[21]!="boundary_height"){Ex.Logger.Log("Creature.csv中字段[boundary_height]位置不对应"); return false; }
		if(vecLine[22]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[23]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[24]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[25]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[26]!="pool_skill_num"){Ex.Logger.Log("Creature.csv中字段[pool_skill_num]位置不对应"); return false; }
		if(vecLine[27]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[28]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[29]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[30]!="skill_1"){Ex.Logger.Log("Creature.csv中字段[skill_1]位置不对应"); return false; }
		if(vecLine[31]!="skill_2"){Ex.Logger.Log("Creature.csv中字段[skill_2]位置不对应"); return false; }
		if(vecLine[32]!="skill_3"){Ex.Logger.Log("Creature.csv中字段[skill_3]位置不对应"); return false; }
		if(vecLine[33]!="skill_4"){Ex.Logger.Log("Creature.csv中字段[skill_4]位置不对应"); return false; }
		if(vecLine[34]!="skill_5"){Ex.Logger.Log("Creature.csv中字段[skill_5]位置不对应"); return false; }
		if(vecLine[35]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[36]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[37]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[38]!="is_play_born_animation"){Ex.Logger.Log("Creature.csv中字段[is_play_born_animation]位置不对应"); return false; }
		if(vecLine[39]!="born_anim_duration_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_duration_buff]位置不对应"); return false; }
		if(vecLine[40]!="born_anim_effect_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_effect_buff]位置不对应"); return false; }
		if(vecLine[41]!="born_animation_name"){Ex.Logger.Log("Creature.csv中字段[born_animation_name]位置不对应"); return false; }
		if(vecLine[42]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[43]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureElement member = new CreatureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.entry_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.script_ID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_coe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_attributes_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.temper_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.gd_comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sub_name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mapping_path);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.scale);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.opacity);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.health_bar_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_bar_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.faction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.boundary_length);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.boundary_width);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.boundary_height);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.walk_speed);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.run_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_targeted );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_attack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pool_skill_num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.selected_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.death_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.initial_skill);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_5 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rebirth_buffs);
			readPos += GameAssist.ReadString( binContent, readPos, out member.verification);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_wondering );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_play_born_animation );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.born_anim_duration_buff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.born_anim_effect_buff );
			readPos += GameAssist.ReadString( binContent, readPos, out member.born_animation_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.combat_entry_skill);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.corpse_vanish_time );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.entry_id] = member;
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
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="entry_id"){Ex.Logger.Log("Creature.csv中字段[entry_id]位置不对应"); return false; }
		if(vecLine[1]!="script_ID"){Ex.Logger.Log("Creature.csv中字段[script_ID]位置不对应"); return false; }
		if(vecLine[2]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[3]!="combat_attributes_id"){Ex.Logger.Log("Creature.csv中字段[combat_attributes_id]位置不对应"); return false; }
		if(vecLine[4]!="temper_id"){Ex.Logger.Log("Creature.csv中字段[temper_id]位置不对应"); return false; }
		if(vecLine[5]!="gd_comment"){Ex.Logger.Log("Creature.csv中字段[gd_comment]位置不对应"); return false; }
		if(vecLine[6]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[7]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[8]!="model_id"){Ex.Logger.Log("Creature.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[9]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[10]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[11]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[12]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[13]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[14]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[15]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[16]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[17]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[18]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[19]!="boundary_length"){Ex.Logger.Log("Creature.csv中字段[boundary_length]位置不对应"); return false; }
		if(vecLine[20]!="boundary_width"){Ex.Logger.Log("Creature.csv中字段[boundary_width]位置不对应"); return false; }
		if(vecLine[21]!="boundary_height"){Ex.Logger.Log("Creature.csv中字段[boundary_height]位置不对应"); return false; }
		if(vecLine[22]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[23]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[24]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[25]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[26]!="pool_skill_num"){Ex.Logger.Log("Creature.csv中字段[pool_skill_num]位置不对应"); return false; }
		if(vecLine[27]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[28]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }
		if(vecLine[29]!="initial_skill"){Ex.Logger.Log("Creature.csv中字段[initial_skill]位置不对应"); return false; }
		if(vecLine[30]!="skill_1"){Ex.Logger.Log("Creature.csv中字段[skill_1]位置不对应"); return false; }
		if(vecLine[31]!="skill_2"){Ex.Logger.Log("Creature.csv中字段[skill_2]位置不对应"); return false; }
		if(vecLine[32]!="skill_3"){Ex.Logger.Log("Creature.csv中字段[skill_3]位置不对应"); return false; }
		if(vecLine[33]!="skill_4"){Ex.Logger.Log("Creature.csv中字段[skill_4]位置不对应"); return false; }
		if(vecLine[34]!="skill_5"){Ex.Logger.Log("Creature.csv中字段[skill_5]位置不对应"); return false; }
		if(vecLine[35]!="rebirth_buffs"){Ex.Logger.Log("Creature.csv中字段[rebirth_buffs]位置不对应"); return false; }
		if(vecLine[36]!="verification"){Ex.Logger.Log("Creature.csv中字段[verification]位置不对应"); return false; }
		if(vecLine[37]!="is_wondering"){Ex.Logger.Log("Creature.csv中字段[is_wondering]位置不对应"); return false; }
		if(vecLine[38]!="is_play_born_animation"){Ex.Logger.Log("Creature.csv中字段[is_play_born_animation]位置不对应"); return false; }
		if(vecLine[39]!="born_anim_duration_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_duration_buff]位置不对应"); return false; }
		if(vecLine[40]!="born_anim_effect_buff"){Ex.Logger.Log("Creature.csv中字段[born_anim_effect_buff]位置不对应"); return false; }
		if(vecLine[41]!="born_animation_name"){Ex.Logger.Log("Creature.csv中字段[born_animation_name]位置不对应"); return false; }
		if(vecLine[42]!="combat_entry_skill"){Ex.Logger.Log("Creature.csv中字段[combat_entry_skill]位置不对应"); return false; }
		if(vecLine[43]!="corpse_vanish_time"){Ex.Logger.Log("Creature.csv中字段[corpse_vanish_time]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)44)
			{
				return false;
			}
			CreatureElement member = new CreatureElement();
			member.entry_id=Convert.ToInt32(vecLine[0]);
			member.script_ID=Convert.ToInt32(vecLine[1]);
			member.combat_coe_id=Convert.ToInt32(vecLine[2]);
			member.combat_attributes_id=Convert.ToInt32(vecLine[3]);
			member.temper_id=Convert.ToInt32(vecLine[4]);
			member.gd_comment=vecLine[5];
			member.name_id=Convert.ToInt32(vecLine[6]);
			member.sub_name_id=Convert.ToInt32(vecLine[7]);
			member.model_id=Convert.ToInt32(vecLine[8]);
			member.mapping_path=vecLine[9];
			member.scale=Convert.ToSingle(vecLine[10]);
			member.opacity=Convert.ToSingle(vecLine[11]);
			member.icon=vecLine[12];
			member.health_bar_display=Convert.ToInt32(vecLine[13]);
			member.name_bar_display=Convert.ToInt32(vecLine[14]);
			member.creature_level=Convert.ToInt32(vecLine[15]);
			member.creature_type=Convert.ToInt32(vecLine[16]);
			member.faction=Convert.ToInt32(vecLine[17]);
			member.race=Convert.ToInt32(vecLine[18]);
			member.boundary_length=Convert.ToSingle(vecLine[19]);
			member.boundary_width=Convert.ToSingle(vecLine[20]);
			member.boundary_height=Convert.ToSingle(vecLine[21]);
			member.walk_speed=Convert.ToSingle(vecLine[22]);
			member.run_speed=Convert.ToSingle(vecLine[23]);
			member.can_be_targeted=Convert.ToInt32(vecLine[24]);
			member.can_attack=Convert.ToInt32(vecLine[25]);
			member.pool_skill_num=Convert.ToInt32(vecLine[26]);
			member.selected_sound=vecLine[27];
			member.death_sound=vecLine[28];
			member.initial_skill=vecLine[29];
			member.skill_1=Convert.ToInt32(vecLine[30]);
			member.skill_2=Convert.ToInt32(vecLine[31]);
			member.skill_3=Convert.ToInt32(vecLine[32]);
			member.skill_4=Convert.ToInt32(vecLine[33]);
			member.skill_5=Convert.ToInt32(vecLine[34]);
			member.rebirth_buffs=vecLine[35];
			member.verification=vecLine[36];
			member.is_wondering=Convert.ToInt32(vecLine[37]);
			member.is_play_born_animation=Convert.ToInt32(vecLine[38]);
			member.born_anim_duration_buff=Convert.ToInt32(vecLine[39]);
			member.born_anim_effect_buff=Convert.ToInt32(vecLine[40]);
			member.born_animation_name=vecLine[41];
			member.combat_entry_skill=vecLine[42];
			member.corpse_vanish_time=Convert.ToInt32(vecLine[43]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.entry_id] = member;
		}
		return true;
	}
};
