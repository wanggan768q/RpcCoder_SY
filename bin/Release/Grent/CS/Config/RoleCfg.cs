using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色属性配置数据类
public class RoleElement
{
	public int id;               	//id	种族*100000+职业*10+性别
	public string comment;       	//注释	注释
	public int race;             	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	public int occupation;       	//职业	1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士 6：神秘使
	public string characteristic;	//职业特色	职业特色
	public int gender;           	//性别	1:男性 2:女性
	public string race_icon;     	//种族图标	种族图标
	public int race_name;        	//种族名称	种族名称
	public int race_desc;        	//种族介绍	种族介绍
	public string occu_icon;     	//职业图标	职业图标
	public ls concentrate1_icon; 	//专精1图标	专精1图标
	public int concentrate1_name;	//专精1名称	专精1名称
	public int concentrate1_desc;	//专精1介绍	专精1介绍
	public ls concentrate2_icon; 	//专精2图标	专精2图标
	public int concentrate2_name;	//专精2名称	专精2名称
	public int concentrate2_desc;	//专精2介绍	专精2介绍
	public ls create_occu_icon;  	//创建界面图标	专门用在创建界面的 职业头像 对应未选中和选中两个状态
	public ls select_occu_icon;  	//选择界面图标	专门用在选择界面的 职业标示 对应未选中和选中两个状态
	public int occu_name;        	//职业名称	职业名称
	public int occu_desc;        	//职业介绍	职业介绍
	public string occu_evaluate; 	//职业评估	对应每个职业特性图路径
	public int show_model;       	//展示模型id	在角色创建界面上显示的模型id
	public string default_headshot;	//默认头像	默认在游戏中使用的头像
	public string default_portrait;	//默认肖像	默认在游戏中使用的全身像
	public int model_id;         	//初始模型id	初始模型id
	public float leisure_pro;    	//播放休闲动画几率	1=100%
	public string select_model;  	//临时选择角色显示模型	目前在属性界面中调用
	public float animation;      	//出场动画时间(秒)	出场动画时间(秒)
	public string initial_skeleton;	//角色初始骨骼	
	public int initial_face;     	//初始面部模型	
	public int initial_head;     	//初始头部模型	
	public int initial_body;     	//初始身体模型	
	public int initial_weapon;   	//初始武器模型	
	public float camera_size;    	//属性界面摄像机的缩放参数	数值越大角色模型显示越小 默认为1
	public lf camera_pos;        	//属性界面摄像机的位移参数	分别表示摄像机的X和Y轴偏移 默认为0|0
	public int attack_type;      	//角色普攻类型	0.物理 1.魔法
	public int initial_level;    	//初始等级	初始等级
	public int initial_weapon_equip;	//初始武器	初始武器
	public int initial_head_equip;	//初始头盔	初始头盔
	public int initial_earring_equip;	//初始耳环	初始耳环
	public int initial_chest_equip;	//初始胸甲	初始胸甲
	public int initial_necklace_equip;	//初始项链	初始项链
	public int initial_hand_equip;	//初始手甲	初始手甲
	public int initial_ring_equip;	//初始戒指	初始戒指
	public int initial_foot_equip;	//初始靴子	初始靴子
	public int initial_quest;    	//初始任务	初始任务
	public int nomorl_attack;    	//普攻id	

	public bool IsValidate = false;
	public RoleElement()
	{
		id = -1;
	}
};

//角色属性配置封装类
public class RoleTable
{

	private RoleTable()
	{
		m_mapElements = new Dictionary<int, RoleElement>();
		m_emptyItem = new RoleElement();
		m_vecAllElements = new List<RoleElement>();
	}
	private Dictionary<int, RoleElement> m_mapElements = null;
	private List<RoleElement>	m_vecAllElements = null;
	private RoleElement m_emptyItem = null;
	private static RoleTable sInstance = null;

	public static RoleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RoleTable();
			return sInstance;
		}
	}

	public RoleElement GetElement(int key)
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

  public List<RoleElement> GetAllElement(Predicate<RoleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Role.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Role.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Role.bin]未找到");
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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("Role.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Role.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Role.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="race"){Ex.Logger.Log("Role.csv中字段[race]位置不对应"); return false; }
		if(vecLine[3]!="occupation"){Ex.Logger.Log("Role.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[4]!="characteristic"){Ex.Logger.Log("Role.csv中字段[characteristic]位置不对应"); return false; }
		if(vecLine[5]!="gender"){Ex.Logger.Log("Role.csv中字段[gender]位置不对应"); return false; }
		if(vecLine[6]!="race_icon"){Ex.Logger.Log("Role.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[7]!="race_name"){Ex.Logger.Log("Role.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[8]!="race_desc"){Ex.Logger.Log("Role.csv中字段[race_desc]位置不对应"); return false; }
		if(vecLine[9]!="occu_icon"){Ex.Logger.Log("Role.csv中字段[occu_icon]位置不对应"); return false; }
		if(vecLine[10]!="concentrate1_icon"){Ex.Logger.Log("Role.csv中字段[concentrate1_icon]位置不对应"); return false; }
		if(vecLine[11]!="concentrate1_name"){Ex.Logger.Log("Role.csv中字段[concentrate1_name]位置不对应"); return false; }
		if(vecLine[12]!="concentrate1_desc"){Ex.Logger.Log("Role.csv中字段[concentrate1_desc]位置不对应"); return false; }
		if(vecLine[13]!="concentrate2_icon"){Ex.Logger.Log("Role.csv中字段[concentrate2_icon]位置不对应"); return false; }
		if(vecLine[14]!="concentrate2_name"){Ex.Logger.Log("Role.csv中字段[concentrate2_name]位置不对应"); return false; }
		if(vecLine[15]!="concentrate2_desc"){Ex.Logger.Log("Role.csv中字段[concentrate2_desc]位置不对应"); return false; }
		if(vecLine[16]!="create_occu_icon"){Ex.Logger.Log("Role.csv中字段[create_occu_icon]位置不对应"); return false; }
		if(vecLine[17]!="select_occu_icon"){Ex.Logger.Log("Role.csv中字段[select_occu_icon]位置不对应"); return false; }
		if(vecLine[18]!="occu_name"){Ex.Logger.Log("Role.csv中字段[occu_name]位置不对应"); return false; }
		if(vecLine[19]!="occu_desc"){Ex.Logger.Log("Role.csv中字段[occu_desc]位置不对应"); return false; }
		if(vecLine[20]!="occu_evaluate"){Ex.Logger.Log("Role.csv中字段[occu_evaluate]位置不对应"); return false; }
		if(vecLine[21]!="show_model"){Ex.Logger.Log("Role.csv中字段[show_model]位置不对应"); return false; }
		if(vecLine[22]!="default_headshot"){Ex.Logger.Log("Role.csv中字段[default_headshot]位置不对应"); return false; }
		if(vecLine[23]!="default_portrait"){Ex.Logger.Log("Role.csv中字段[default_portrait]位置不对应"); return false; }
		if(vecLine[24]!="model_id"){Ex.Logger.Log("Role.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[25]!="leisure_pro"){Ex.Logger.Log("Role.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[26]!="select_model"){Ex.Logger.Log("Role.csv中字段[select_model]位置不对应"); return false; }
		if(vecLine[27]!="animation"){Ex.Logger.Log("Role.csv中字段[animation]位置不对应"); return false; }
		if(vecLine[28]!="initial_skeleton"){Ex.Logger.Log("Role.csv中字段[initial_skeleton]位置不对应"); return false; }
		if(vecLine[29]!="initial_face"){Ex.Logger.Log("Role.csv中字段[initial_face]位置不对应"); return false; }
		if(vecLine[30]!="initial_head"){Ex.Logger.Log("Role.csv中字段[initial_head]位置不对应"); return false; }
		if(vecLine[31]!="initial_body"){Ex.Logger.Log("Role.csv中字段[initial_body]位置不对应"); return false; }
		if(vecLine[32]!="initial_weapon"){Ex.Logger.Log("Role.csv中字段[initial_weapon]位置不对应"); return false; }
		if(vecLine[33]!="camera_size"){Ex.Logger.Log("Role.csv中字段[camera_size]位置不对应"); return false; }
		if(vecLine[34]!="camera_pos"){Ex.Logger.Log("Role.csv中字段[camera_pos]位置不对应"); return false; }
		if(vecLine[35]!="attack_type"){Ex.Logger.Log("Role.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[36]!="initial_level"){Ex.Logger.Log("Role.csv中字段[initial_level]位置不对应"); return false; }
		if(vecLine[37]!="initial_weapon_equip"){Ex.Logger.Log("Role.csv中字段[initial_weapon_equip]位置不对应"); return false; }
		if(vecLine[38]!="initial_head_equip"){Ex.Logger.Log("Role.csv中字段[initial_head_equip]位置不对应"); return false; }
		if(vecLine[39]!="initial_earring_equip"){Ex.Logger.Log("Role.csv中字段[initial_earring_equip]位置不对应"); return false; }
		if(vecLine[40]!="initial_chest_equip"){Ex.Logger.Log("Role.csv中字段[initial_chest_equip]位置不对应"); return false; }
		if(vecLine[41]!="initial_necklace_equip"){Ex.Logger.Log("Role.csv中字段[initial_necklace_equip]位置不对应"); return false; }
		if(vecLine[42]!="initial_hand_equip"){Ex.Logger.Log("Role.csv中字段[initial_hand_equip]位置不对应"); return false; }
		if(vecLine[43]!="initial_ring_equip"){Ex.Logger.Log("Role.csv中字段[initial_ring_equip]位置不对应"); return false; }
		if(vecLine[44]!="initial_foot_equip"){Ex.Logger.Log("Role.csv中字段[initial_foot_equip]位置不对应"); return false; }
		if(vecLine[45]!="initial_quest"){Ex.Logger.Log("Role.csv中字段[initial_quest]位置不对应"); return false; }
		if(vecLine[46]!="nomorl_attack"){Ex.Logger.Log("Role.csv中字段[nomorl_attack]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RoleElement member = new RoleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occupation );
			readPos += GameAssist.ReadString( binContent, readPos, out member.characteristic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gender );
			readPos += GameAssist.ReadString( binContent, readPos, out member.race_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occu_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.concentrate1_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.concentrate1_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.concentrate1_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.concentrate2_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.concentrate2_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.concentrate2_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.create_occu_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.select_occu_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occu_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occu_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occu_evaluate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.show_model );
			readPos += GameAssist.ReadString( binContent, readPos, out member.default_headshot);
			readPos += GameAssist.ReadString( binContent, readPos, out member.default_portrait);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.leisure_pro);
			readPos += GameAssist.ReadString( binContent, readPos, out member.select_model);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.animation);
			readPos += GameAssist.ReadString( binContent, readPos, out member.initial_skeleton);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_face );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_head );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_body );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_weapon );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.camera_size);
			readPos += GameAssist.ReadString( binContent, readPos, out member.camera_pos);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_weapon_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_head_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_earring_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_chest_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_necklace_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_hand_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_ring_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_foot_equip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.initial_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.nomorl_attack );

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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("Role.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Role.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Role.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="race"){Ex.Logger.Log("Role.csv中字段[race]位置不对应"); return false; }
		if(vecLine[3]!="occupation"){Ex.Logger.Log("Role.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[4]!="characteristic"){Ex.Logger.Log("Role.csv中字段[characteristic]位置不对应"); return false; }
		if(vecLine[5]!="gender"){Ex.Logger.Log("Role.csv中字段[gender]位置不对应"); return false; }
		if(vecLine[6]!="race_icon"){Ex.Logger.Log("Role.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[7]!="race_name"){Ex.Logger.Log("Role.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[8]!="race_desc"){Ex.Logger.Log("Role.csv中字段[race_desc]位置不对应"); return false; }
		if(vecLine[9]!="occu_icon"){Ex.Logger.Log("Role.csv中字段[occu_icon]位置不对应"); return false; }
		if(vecLine[10]!="concentrate1_icon"){Ex.Logger.Log("Role.csv中字段[concentrate1_icon]位置不对应"); return false; }
		if(vecLine[11]!="concentrate1_name"){Ex.Logger.Log("Role.csv中字段[concentrate1_name]位置不对应"); return false; }
		if(vecLine[12]!="concentrate1_desc"){Ex.Logger.Log("Role.csv中字段[concentrate1_desc]位置不对应"); return false; }
		if(vecLine[13]!="concentrate2_icon"){Ex.Logger.Log("Role.csv中字段[concentrate2_icon]位置不对应"); return false; }
		if(vecLine[14]!="concentrate2_name"){Ex.Logger.Log("Role.csv中字段[concentrate2_name]位置不对应"); return false; }
		if(vecLine[15]!="concentrate2_desc"){Ex.Logger.Log("Role.csv中字段[concentrate2_desc]位置不对应"); return false; }
		if(vecLine[16]!="create_occu_icon"){Ex.Logger.Log("Role.csv中字段[create_occu_icon]位置不对应"); return false; }
		if(vecLine[17]!="select_occu_icon"){Ex.Logger.Log("Role.csv中字段[select_occu_icon]位置不对应"); return false; }
		if(vecLine[18]!="occu_name"){Ex.Logger.Log("Role.csv中字段[occu_name]位置不对应"); return false; }
		if(vecLine[19]!="occu_desc"){Ex.Logger.Log("Role.csv中字段[occu_desc]位置不对应"); return false; }
		if(vecLine[20]!="occu_evaluate"){Ex.Logger.Log("Role.csv中字段[occu_evaluate]位置不对应"); return false; }
		if(vecLine[21]!="show_model"){Ex.Logger.Log("Role.csv中字段[show_model]位置不对应"); return false; }
		if(vecLine[22]!="default_headshot"){Ex.Logger.Log("Role.csv中字段[default_headshot]位置不对应"); return false; }
		if(vecLine[23]!="default_portrait"){Ex.Logger.Log("Role.csv中字段[default_portrait]位置不对应"); return false; }
		if(vecLine[24]!="model_id"){Ex.Logger.Log("Role.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[25]!="leisure_pro"){Ex.Logger.Log("Role.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[26]!="select_model"){Ex.Logger.Log("Role.csv中字段[select_model]位置不对应"); return false; }
		if(vecLine[27]!="animation"){Ex.Logger.Log("Role.csv中字段[animation]位置不对应"); return false; }
		if(vecLine[28]!="initial_skeleton"){Ex.Logger.Log("Role.csv中字段[initial_skeleton]位置不对应"); return false; }
		if(vecLine[29]!="initial_face"){Ex.Logger.Log("Role.csv中字段[initial_face]位置不对应"); return false; }
		if(vecLine[30]!="initial_head"){Ex.Logger.Log("Role.csv中字段[initial_head]位置不对应"); return false; }
		if(vecLine[31]!="initial_body"){Ex.Logger.Log("Role.csv中字段[initial_body]位置不对应"); return false; }
		if(vecLine[32]!="initial_weapon"){Ex.Logger.Log("Role.csv中字段[initial_weapon]位置不对应"); return false; }
		if(vecLine[33]!="camera_size"){Ex.Logger.Log("Role.csv中字段[camera_size]位置不对应"); return false; }
		if(vecLine[34]!="camera_pos"){Ex.Logger.Log("Role.csv中字段[camera_pos]位置不对应"); return false; }
		if(vecLine[35]!="attack_type"){Ex.Logger.Log("Role.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[36]!="initial_level"){Ex.Logger.Log("Role.csv中字段[initial_level]位置不对应"); return false; }
		if(vecLine[37]!="initial_weapon_equip"){Ex.Logger.Log("Role.csv中字段[initial_weapon_equip]位置不对应"); return false; }
		if(vecLine[38]!="initial_head_equip"){Ex.Logger.Log("Role.csv中字段[initial_head_equip]位置不对应"); return false; }
		if(vecLine[39]!="initial_earring_equip"){Ex.Logger.Log("Role.csv中字段[initial_earring_equip]位置不对应"); return false; }
		if(vecLine[40]!="initial_chest_equip"){Ex.Logger.Log("Role.csv中字段[initial_chest_equip]位置不对应"); return false; }
		if(vecLine[41]!="initial_necklace_equip"){Ex.Logger.Log("Role.csv中字段[initial_necklace_equip]位置不对应"); return false; }
		if(vecLine[42]!="initial_hand_equip"){Ex.Logger.Log("Role.csv中字段[initial_hand_equip]位置不对应"); return false; }
		if(vecLine[43]!="initial_ring_equip"){Ex.Logger.Log("Role.csv中字段[initial_ring_equip]位置不对应"); return false; }
		if(vecLine[44]!="initial_foot_equip"){Ex.Logger.Log("Role.csv中字段[initial_foot_equip]位置不对应"); return false; }
		if(vecLine[45]!="initial_quest"){Ex.Logger.Log("Role.csv中字段[initial_quest]位置不对应"); return false; }
		if(vecLine[46]!="nomorl_attack"){Ex.Logger.Log("Role.csv中字段[nomorl_attack]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)47)
			{
				return false;
			}
			RoleElement member = new RoleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.race=Convert.ToInt32(vecLine[2]);
			member.occupation=Convert.ToInt32(vecLine[3]);
			member.characteristic=vecLine[4];
			member.gender=Convert.ToInt32(vecLine[5]);
			member.race_icon=vecLine[6];
			member.race_name=Convert.ToInt32(vecLine[7]);
			member.race_desc=Convert.ToInt32(vecLine[8]);
			member.occu_icon=vecLine[9];
			member.concentrate1_icon=vecLine[10];
			member.concentrate1_name=Convert.ToInt32(vecLine[11]);
			member.concentrate1_desc=Convert.ToInt32(vecLine[12]);
			member.concentrate2_icon=vecLine[13];
			member.concentrate2_name=Convert.ToInt32(vecLine[14]);
			member.concentrate2_desc=Convert.ToInt32(vecLine[15]);
			member.create_occu_icon=vecLine[16];
			member.select_occu_icon=vecLine[17];
			member.occu_name=Convert.ToInt32(vecLine[18]);
			member.occu_desc=Convert.ToInt32(vecLine[19]);
			member.occu_evaluate=vecLine[20];
			member.show_model=Convert.ToInt32(vecLine[21]);
			member.default_headshot=vecLine[22];
			member.default_portrait=vecLine[23];
			member.model_id=Convert.ToInt32(vecLine[24]);
			member.leisure_pro=Convert.ToSingle(vecLine[25]);
			member.select_model=vecLine[26];
			member.animation=Convert.ToSingle(vecLine[27]);
			member.initial_skeleton=vecLine[28];
			member.initial_face=Convert.ToInt32(vecLine[29]);
			member.initial_head=Convert.ToInt32(vecLine[30]);
			member.initial_body=Convert.ToInt32(vecLine[31]);
			member.initial_weapon=Convert.ToInt32(vecLine[32]);
			member.camera_size=Convert.ToSingle(vecLine[33]);
			member.camera_pos=vecLine[34];
			member.attack_type=Convert.ToInt32(vecLine[35]);
			member.initial_level=Convert.ToInt32(vecLine[36]);
			member.initial_weapon_equip=Convert.ToInt32(vecLine[37]);
			member.initial_head_equip=Convert.ToInt32(vecLine[38]);
			member.initial_earring_equip=Convert.ToInt32(vecLine[39]);
			member.initial_chest_equip=Convert.ToInt32(vecLine[40]);
			member.initial_necklace_equip=Convert.ToInt32(vecLine[41]);
			member.initial_hand_equip=Convert.ToInt32(vecLine[42]);
			member.initial_ring_equip=Convert.ToInt32(vecLine[43]);
			member.initial_foot_equip=Convert.ToInt32(vecLine[44]);
			member.initial_quest=Convert.ToInt32(vecLine[45]);
			member.nomorl_attack=Convert.ToInt32(vecLine[46]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
