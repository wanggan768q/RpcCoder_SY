using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//载具表配置数据类
public class VechicleElement
{
	public int id;               	//序号	ID段规则：5位数起，跟随场景ID规则而定 5位数以前为测试用
	public string comment;       	//坐骑备注	仅策划用
	public int type;             	//坐骑类型	1为变身型载具 2为挂点连接型载具（人移动） 3为挂点连接型载具（载具移动）
	public int model_id;         	//模型ID	用于规定所使用的模型 如果type=1，关联character_config表； 如果type=2或3，关联CharacterCustomize表
	public string shapeshift_animation_caster;	//变身动画-释放者动作	取自Raw_Animation_Monster
	public string shapeshift_animation_target;	//变身动画-变身后衔接动作	取自Raw_Animation_Monster
	public string shapeshift_effect;	//变身特效	取自Res_Prefabs_Effect_Skill
	public int shapeshift_time;  	//变身时长	单位毫秒
	public int change_skill;     	//是否切换技能	0：不切换 1：切换
	public li skill_list;        	//切换的技能列表	格式：skillid|skillid|skillid
	public int not_in_battle;    	//是否能在战斗状态使用	如果为1，代表该功能可以在战斗中使用；2为禁止在战斗中使用。标识为2后，如果玩家进入战斗或释放技能，则自动回到玩家的初始状态（即移除模型变化、技能变化）
	public int can_move;         	//是否可自由移动	是否可自由移动 0：不可移动 1：可移动
	public int player_move_speed;	//移动速度	交互后玩家的移动速度，0为不允许移动
	public int can_exit;         	//是否可手动退出	是否可以手动退出载具状态： 1为可以，且在屏幕上出现退出图标；同时到达最终路点后不会自动退出载具 2为不可以。（任务需要额外注意）；同时到达最终路点后会自动退出载具
	public string shapeshift_exit_animation_caster;	//取消变身动画-释放者	取自Raw_Animation_Monster
	public string shapeshift_exit_animation_tatget;	//取消变身动画-变身后衔接动画	取自Raw_Animation_Monster
	public string shapeshift_exit_effect;	//取消变身特效	取自Res_Prefabs_Effect_Skill
	public int shapeshift_exit_time;	//取消变身时长	单位毫秒
	public int quest_id;         	//任务ID	所绑定的任务ID，当玩家身上没有该任务时，无法触发载具功能。如果玩家在载具状态下，任务完成，则要回归到玩家的初始状态。
	public li waypoint_list;     	//路点列表	填写起始路点|最终路点 如果有值，则在交互后，自动将玩家或其改变的模型放置在起始路点，并开始沿着下一个路点移动，直到最终路点。玩家无法自由移动。 路点与路点之间使用|作为间隔。 路点表增加fly_height列，规定飞行的高度
	public int visible_type;     	//可见类型	1. 飞行不可见 2. 地面可见 3. 地面不可见 
	public float initial_velocity;	//初始速率	坐骑动画的默认速率（m/s）

	public bool IsValidate = false;
	public VechicleElement()
	{
		id = -1;
	}
};

//载具表配置封装类
public class VechicleTable
{

	private VechicleTable()
	{
		m_mapElements = new Dictionary<int, VechicleElement>();
		m_emptyItem = new VechicleElement();
		m_vecAllElements = new List<VechicleElement>();
	}
	private Dictionary<int, VechicleElement> m_mapElements = null;
	private List<VechicleElement>	m_vecAllElements = null;
	private VechicleElement m_emptyItem = null;
	private static VechicleTable sInstance = null;

	public static VechicleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new VechicleTable();
			return sInstance;
		}
	}

	public VechicleElement GetElement(int key)
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

  public List<VechicleElement> GetAllElement(Predicate<VechicleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Vechicle.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Vechicle.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Vechicle.bin]未找到");
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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("Vechicle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Vechicle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Vechicle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Vechicle.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="model_id"){Ex.Logger.Log("Vechicle.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[4]!="shapeshift_animation_caster"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_animation_caster]位置不对应"); return false; }
		if(vecLine[5]!="shapeshift_animation_target"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_animation_target]位置不对应"); return false; }
		if(vecLine[6]!="shapeshift_effect"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_effect]位置不对应"); return false; }
		if(vecLine[7]!="shapeshift_time"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_time]位置不对应"); return false; }
		if(vecLine[8]!="change_skill"){Ex.Logger.Log("Vechicle.csv中字段[change_skill]位置不对应"); return false; }
		if(vecLine[9]!="skill_list"){Ex.Logger.Log("Vechicle.csv中字段[skill_list]位置不对应"); return false; }
		if(vecLine[10]!="not_in_battle"){Ex.Logger.Log("Vechicle.csv中字段[not_in_battle]位置不对应"); return false; }
		if(vecLine[11]!="can_move"){Ex.Logger.Log("Vechicle.csv中字段[can_move]位置不对应"); return false; }
		if(vecLine[12]!="player_move_speed"){Ex.Logger.Log("Vechicle.csv中字段[player_move_speed]位置不对应"); return false; }
		if(vecLine[13]!="can_exit"){Ex.Logger.Log("Vechicle.csv中字段[can_exit]位置不对应"); return false; }
		if(vecLine[14]!="shapeshift_exit_animation_caster"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_animation_caster]位置不对应"); return false; }
		if(vecLine[15]!="shapeshift_exit_animation_tatget"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_animation_tatget]位置不对应"); return false; }
		if(vecLine[16]!="shapeshift_exit_effect"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_effect]位置不对应"); return false; }
		if(vecLine[17]!="shapeshift_exit_time"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_time]位置不对应"); return false; }
		if(vecLine[18]!="quest_id"){Ex.Logger.Log("Vechicle.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[19]!="waypoint_list"){Ex.Logger.Log("Vechicle.csv中字段[waypoint_list]位置不对应"); return false; }
		if(vecLine[20]!="visible_type"){Ex.Logger.Log("Vechicle.csv中字段[visible_type]位置不对应"); return false; }
		if(vecLine[21]!="initial_velocity"){Ex.Logger.Log("Vechicle.csv中字段[initial_velocity]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			VechicleElement member = new VechicleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_animation_caster);
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_animation_target);
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_effect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.shapeshift_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.change_skill );
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.not_in_battle );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_move );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.player_move_speed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_exit );
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_exit_animation_caster);
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_exit_animation_tatget);
			readPos += GameAssist.ReadString( binContent, readPos, out member.shapeshift_exit_effect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.shapeshift_exit_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.visible_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.initial_velocity);

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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("Vechicle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Vechicle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Vechicle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("Vechicle.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="model_id"){Ex.Logger.Log("Vechicle.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[4]!="shapeshift_animation_caster"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_animation_caster]位置不对应"); return false; }
		if(vecLine[5]!="shapeshift_animation_target"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_animation_target]位置不对应"); return false; }
		if(vecLine[6]!="shapeshift_effect"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_effect]位置不对应"); return false; }
		if(vecLine[7]!="shapeshift_time"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_time]位置不对应"); return false; }
		if(vecLine[8]!="change_skill"){Ex.Logger.Log("Vechicle.csv中字段[change_skill]位置不对应"); return false; }
		if(vecLine[9]!="skill_list"){Ex.Logger.Log("Vechicle.csv中字段[skill_list]位置不对应"); return false; }
		if(vecLine[10]!="not_in_battle"){Ex.Logger.Log("Vechicle.csv中字段[not_in_battle]位置不对应"); return false; }
		if(vecLine[11]!="can_move"){Ex.Logger.Log("Vechicle.csv中字段[can_move]位置不对应"); return false; }
		if(vecLine[12]!="player_move_speed"){Ex.Logger.Log("Vechicle.csv中字段[player_move_speed]位置不对应"); return false; }
		if(vecLine[13]!="can_exit"){Ex.Logger.Log("Vechicle.csv中字段[can_exit]位置不对应"); return false; }
		if(vecLine[14]!="shapeshift_exit_animation_caster"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_animation_caster]位置不对应"); return false; }
		if(vecLine[15]!="shapeshift_exit_animation_tatget"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_animation_tatget]位置不对应"); return false; }
		if(vecLine[16]!="shapeshift_exit_effect"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_effect]位置不对应"); return false; }
		if(vecLine[17]!="shapeshift_exit_time"){Ex.Logger.Log("Vechicle.csv中字段[shapeshift_exit_time]位置不对应"); return false; }
		if(vecLine[18]!="quest_id"){Ex.Logger.Log("Vechicle.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[19]!="waypoint_list"){Ex.Logger.Log("Vechicle.csv中字段[waypoint_list]位置不对应"); return false; }
		if(vecLine[20]!="visible_type"){Ex.Logger.Log("Vechicle.csv中字段[visible_type]位置不对应"); return false; }
		if(vecLine[21]!="initial_velocity"){Ex.Logger.Log("Vechicle.csv中字段[initial_velocity]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			VechicleElement member = new VechicleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.type=Convert.ToInt32(vecLine[2]);
			member.model_id=Convert.ToInt32(vecLine[3]);
			member.shapeshift_animation_caster=vecLine[4];
			member.shapeshift_animation_target=vecLine[5];
			member.shapeshift_effect=vecLine[6];
			member.shapeshift_time=Convert.ToInt32(vecLine[7]);
			member.change_skill=Convert.ToInt32(vecLine[8]);
			member.skill_list=vecLine[9];
			member.not_in_battle=Convert.ToInt32(vecLine[10]);
			member.can_move=Convert.ToInt32(vecLine[11]);
			member.player_move_speed=Convert.ToInt32(vecLine[12]);
			member.can_exit=Convert.ToInt32(vecLine[13]);
			member.shapeshift_exit_animation_caster=vecLine[14];
			member.shapeshift_exit_animation_tatget=vecLine[15];
			member.shapeshift_exit_effect=vecLine[16];
			member.shapeshift_exit_time=Convert.ToInt32(vecLine[17]);
			member.quest_id=Convert.ToInt32(vecLine[18]);
			member.waypoint_list=vecLine[19];
			member.visible_type=Convert.ToInt32(vecLine[20]);
			member.initial_velocity=Convert.ToSingle(vecLine[21]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
