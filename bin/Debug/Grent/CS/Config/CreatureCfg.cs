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
	public int combat_coe_id;    	//战斗系数ID	战斗系数ID
	public string gd_comment;    	//策划备注	策划备注
	public int name_id;          	//名字文本ID	名字文本ID
	public int sub_name_id;      	//子名字文本ID	子名字文本ID
	public string model_path;    	//模型路径	模型路径
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
	public string script_location;	//脚本路径	脚本路径
	public int can_be_targeted;  	//是否可以被攻击或选中	是否可以被攻击或选中
	public int can_attack;       	//是否可以进行攻击	是否可以进行攻击
	public int pool_skill_num;   	//从技能池里随机出来的数量	从技能池里随机出来的数量
	public string selected_sound;	//被选中音效	被选中音效
	public string death_sound;   	//死亡音效	死亡音效

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
		if(vecLine.Count != 27)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="entry_id"){Ex.Logger.Log("Creature.csv中字段[entry_id]位置不对应"); return false; }
		if(vecLine[1]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[2]!="gd_comment"){Ex.Logger.Log("Creature.csv中字段[gd_comment]位置不对应"); return false; }
		if(vecLine[3]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[4]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[5]!="model_path"){Ex.Logger.Log("Creature.csv中字段[model_path]位置不对应"); return false; }
		if(vecLine[6]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[7]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[8]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[9]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[10]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[11]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[12]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[13]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[14]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[15]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[16]!="boundary_length"){Ex.Logger.Log("Creature.csv中字段[boundary_length]位置不对应"); return false; }
		if(vecLine[17]!="boundary_width"){Ex.Logger.Log("Creature.csv中字段[boundary_width]位置不对应"); return false; }
		if(vecLine[18]!="boundary_height"){Ex.Logger.Log("Creature.csv中字段[boundary_height]位置不对应"); return false; }
		if(vecLine[19]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[20]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[21]!="script_location"){Ex.Logger.Log("Creature.csv中字段[script_location]位置不对应"); return false; }
		if(vecLine[22]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[23]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[24]!="pool_skill_num"){Ex.Logger.Log("Creature.csv中字段[pool_skill_num]位置不对应"); return false; }
		if(vecLine[25]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[26]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureElement member = new CreatureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.entry_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_coe_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.gd_comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sub_name_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.model_path);
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
			readPos += GameAssist.ReadString( binContent, readPos, out member.script_location);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_be_targeted );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_attack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pool_skill_num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.selected_sound);
			readPos += GameAssist.ReadString( binContent, readPos, out member.death_sound);

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
		if(vecLine.Count != 27)
		{
			Ex.Logger.Log("Creature.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="entry_id"){Ex.Logger.Log("Creature.csv中字段[entry_id]位置不对应"); return false; }
		if(vecLine[1]!="combat_coe_id"){Ex.Logger.Log("Creature.csv中字段[combat_coe_id]位置不对应"); return false; }
		if(vecLine[2]!="gd_comment"){Ex.Logger.Log("Creature.csv中字段[gd_comment]位置不对应"); return false; }
		if(vecLine[3]!="name_id"){Ex.Logger.Log("Creature.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[4]!="sub_name_id"){Ex.Logger.Log("Creature.csv中字段[sub_name_id]位置不对应"); return false; }
		if(vecLine[5]!="model_path"){Ex.Logger.Log("Creature.csv中字段[model_path]位置不对应"); return false; }
		if(vecLine[6]!="mapping_path"){Ex.Logger.Log("Creature.csv中字段[mapping_path]位置不对应"); return false; }
		if(vecLine[7]!="scale"){Ex.Logger.Log("Creature.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[8]!="opacity"){Ex.Logger.Log("Creature.csv中字段[opacity]位置不对应"); return false; }
		if(vecLine[9]!="icon"){Ex.Logger.Log("Creature.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[10]!="health_bar_display"){Ex.Logger.Log("Creature.csv中字段[health_bar_display]位置不对应"); return false; }
		if(vecLine[11]!="name_bar_display"){Ex.Logger.Log("Creature.csv中字段[name_bar_display]位置不对应"); return false; }
		if(vecLine[12]!="creature_level"){Ex.Logger.Log("Creature.csv中字段[creature_level]位置不对应"); return false; }
		if(vecLine[13]!="creature_type"){Ex.Logger.Log("Creature.csv中字段[creature_type]位置不对应"); return false; }
		if(vecLine[14]!="faction"){Ex.Logger.Log("Creature.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[15]!="race"){Ex.Logger.Log("Creature.csv中字段[race]位置不对应"); return false; }
		if(vecLine[16]!="boundary_length"){Ex.Logger.Log("Creature.csv中字段[boundary_length]位置不对应"); return false; }
		if(vecLine[17]!="boundary_width"){Ex.Logger.Log("Creature.csv中字段[boundary_width]位置不对应"); return false; }
		if(vecLine[18]!="boundary_height"){Ex.Logger.Log("Creature.csv中字段[boundary_height]位置不对应"); return false; }
		if(vecLine[19]!="walk_speed"){Ex.Logger.Log("Creature.csv中字段[walk_speed]位置不对应"); return false; }
		if(vecLine[20]!="run_speed"){Ex.Logger.Log("Creature.csv中字段[run_speed]位置不对应"); return false; }
		if(vecLine[21]!="script_location"){Ex.Logger.Log("Creature.csv中字段[script_location]位置不对应"); return false; }
		if(vecLine[22]!="can_be_targeted"){Ex.Logger.Log("Creature.csv中字段[can_be_targeted]位置不对应"); return false; }
		if(vecLine[23]!="can_attack"){Ex.Logger.Log("Creature.csv中字段[can_attack]位置不对应"); return false; }
		if(vecLine[24]!="pool_skill_num"){Ex.Logger.Log("Creature.csv中字段[pool_skill_num]位置不对应"); return false; }
		if(vecLine[25]!="selected_sound"){Ex.Logger.Log("Creature.csv中字段[selected_sound]位置不对应"); return false; }
		if(vecLine[26]!="death_sound"){Ex.Logger.Log("Creature.csv中字段[death_sound]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)27)
			{
				return false;
			}
			CreatureElement member = new CreatureElement();
			member.entry_id=Convert.ToInt32(vecLine[0]);
			member.combat_coe_id=Convert.ToInt32(vecLine[1]);
			member.gd_comment=vecLine[2];
			member.name_id=Convert.ToInt32(vecLine[3]);
			member.sub_name_id=Convert.ToInt32(vecLine[4]);
			member.model_path=vecLine[5];
			member.mapping_path=vecLine[6];
			member.scale=Convert.ToSingle(vecLine[7]);
			member.opacity=Convert.ToSingle(vecLine[8]);
			member.icon=vecLine[9];
			member.health_bar_display=Convert.ToInt32(vecLine[10]);
			member.name_bar_display=Convert.ToInt32(vecLine[11]);
			member.creature_level=Convert.ToInt32(vecLine[12]);
			member.creature_type=Convert.ToInt32(vecLine[13]);
			member.faction=Convert.ToInt32(vecLine[14]);
			member.race=Convert.ToInt32(vecLine[15]);
			member.boundary_length=Convert.ToSingle(vecLine[16]);
			member.boundary_width=Convert.ToSingle(vecLine[17]);
			member.boundary_height=Convert.ToSingle(vecLine[18]);
			member.walk_speed=Convert.ToSingle(vecLine[19]);
			member.run_speed=Convert.ToSingle(vecLine[20]);
			member.script_location=vecLine[21];
			member.can_be_targeted=Convert.ToInt32(vecLine[22]);
			member.can_attack=Convert.ToInt32(vecLine[23]);
			member.pool_skill_num=Convert.ToInt32(vecLine[24]);
			member.selected_sound=vecLine[25];
			member.death_sound=vecLine[26];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.entry_id] = member;
		}
		return true;
	}
};
