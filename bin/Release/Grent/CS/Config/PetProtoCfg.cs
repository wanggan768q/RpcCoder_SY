using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物原型表配置数据类
public class PetProtoElement
{
	public int id;               	//宠物id	填写ID即可
	public string comment;       	//注释	策划用
	public int is_display;       	//是否显示	是否在宠物图鉴中显示该宠物 0.不显示 1.显示
	public int name;             	//宠物名称	显示的宠物名称 StringItem_道具文本表
	public int description;      	//宠物描述	用于在宠物召唤界面和宠物图鉴中显示
	public string rarity;        	//宠物稀有度	稀有度对应的图片资源路径
	public int rarity_color;     	//稀有度颜色	宠物品质框显示的颜色 1.绿色 2.蓝色 3.紫色 4.橙色
	public int type;             	//宠物分类	用于区分宠物功能方面的分类 1.防御 2.辅助 3.物理 4.法术
	public string icon;          	//宠物图标	宠物显示时的头像
	public string model;         	//宠物模型	宠物在游戏中调用的模型
	public lf show_offside;      	//显示偏移	决定UI中的宠物偏移 X|Y|Z
	public int init_index_id;    	//最低级index的id	暂时用来显示宠物模型 只在图鉴中调用
	public float leisure_pro;    	//播放休闲动画几率	1=100%
	public string talent_pic;    	//资质雷达图	宠物对应的资质雷达图的资源名称
	public int speed;            	//移动速度	宠物默认移动速度
	public float run_rate;       	//移动速率	该宠物移动时播放动画的倍率 默认1.0
	public int spawn_action;     	//出生动画	宠物出生时的动画  对应技能表中不广播技能
	public int possesssed_action;	//附身动画	宠物进战时的动画  对应技能表中不广播技能
	public string transform_eff; 	//进战特效	宠物变成光球的特效
	public string lightsphere_eff;	//光球特效	光球飞行中的特效
	public string possesssed_buff;	//附身特效	宠物进战时播放的特效  对应buff表中配置
	public int leave_fight_action;	//脱战动画	宠物脱战时的动画  对应技能表中不广播技能
	public int interact_action;  	//交互动画	宠物交互时的动画  对应技能表中不广播技能
	public int level_up_action;  	//升级动画	宠物培养成功时的动画  对应技能表中不广播技能
	public int active_skill;     	//主动技能	宠物对应的主动技能的id
	public li passive_skill;     	//被动技能	宠物生成时自带被动技能的id 数组，最多8个

	public bool IsValidate = false;
	public PetProtoElement()
	{
		id = -1;
	}
};

//宠物原型表配置封装类
public class PetProtoTable
{

	private PetProtoTable()
	{
		m_mapElements = new Dictionary<int, PetProtoElement>();
		m_emptyItem = new PetProtoElement();
		m_vecAllElements = new List<PetProtoElement>();
	}
	private Dictionary<int, PetProtoElement> m_mapElements = null;
	private List<PetProtoElement>	m_vecAllElements = null;
	private PetProtoElement m_emptyItem = null;
	private static PetProtoTable sInstance = null;

	public static PetProtoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetProtoTable();
			return sInstance;
		}
	}

	public PetProtoElement GetElement(int key)
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

  public List<PetProtoElement> GetAllElement(Predicate<PetProtoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetProto.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetProto.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetProto.bin]未找到");
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
		if(vecLine.Count != 26)
		{
			Ex.Logger.Log("PetProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_display"){Ex.Logger.Log("PetProto.csv中字段[is_display]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("PetProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="description"){Ex.Logger.Log("PetProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[5]!="rarity"){Ex.Logger.Log("PetProto.csv中字段[rarity]位置不对应"); return false; }
		if(vecLine[6]!="rarity_color"){Ex.Logger.Log("PetProto.csv中字段[rarity_color]位置不对应"); return false; }
		if(vecLine[7]!="type"){Ex.Logger.Log("PetProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[8]!="icon"){Ex.Logger.Log("PetProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[9]!="model"){Ex.Logger.Log("PetProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[10]!="show_offside"){Ex.Logger.Log("PetProto.csv中字段[show_offside]位置不对应"); return false; }
		if(vecLine[11]!="init_index_id"){Ex.Logger.Log("PetProto.csv中字段[init_index_id]位置不对应"); return false; }
		if(vecLine[12]!="leisure_pro"){Ex.Logger.Log("PetProto.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[13]!="talent_pic"){Ex.Logger.Log("PetProto.csv中字段[talent_pic]位置不对应"); return false; }
		if(vecLine[14]!="speed"){Ex.Logger.Log("PetProto.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[15]!="run_rate"){Ex.Logger.Log("PetProto.csv中字段[run_rate]位置不对应"); return false; }
		if(vecLine[16]!="spawn_action"){Ex.Logger.Log("PetProto.csv中字段[spawn_action]位置不对应"); return false; }
		if(vecLine[17]!="possesssed_action"){Ex.Logger.Log("PetProto.csv中字段[possesssed_action]位置不对应"); return false; }
		if(vecLine[18]!="transform_eff"){Ex.Logger.Log("PetProto.csv中字段[transform_eff]位置不对应"); return false; }
		if(vecLine[19]!="lightsphere_eff"){Ex.Logger.Log("PetProto.csv中字段[lightsphere_eff]位置不对应"); return false; }
		if(vecLine[20]!="possesssed_buff"){Ex.Logger.Log("PetProto.csv中字段[possesssed_buff]位置不对应"); return false; }
		if(vecLine[21]!="leave_fight_action"){Ex.Logger.Log("PetProto.csv中字段[leave_fight_action]位置不对应"); return false; }
		if(vecLine[22]!="interact_action"){Ex.Logger.Log("PetProto.csv中字段[interact_action]位置不对应"); return false; }
		if(vecLine[23]!="level_up_action"){Ex.Logger.Log("PetProto.csv中字段[level_up_action]位置不对应"); return false; }
		if(vecLine[24]!="active_skill"){Ex.Logger.Log("PetProto.csv中字段[active_skill]位置不对应"); return false; }
		if(vecLine[25]!="passive_skill"){Ex.Logger.Log("PetProto.csv中字段[passive_skill]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetProtoElement member = new PetProtoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rarity);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rarity_color );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.model);
			readPos += GameAssist.ReadString( binContent, readPos, out member.show_offside);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.init_index_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.leisure_pro);
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.speed );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.run_rate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spawn_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.possesssed_action );
			readPos += GameAssist.ReadString( binContent, readPos, out member.transform_eff);
			readPos += GameAssist.ReadString( binContent, readPos, out member.lightsphere_eff);
			readPos += GameAssist.ReadString( binContent, readPos, out member.possesssed_buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_fight_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interact_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_up_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.active_skill );
			readPos += GameAssist.ReadString( binContent, readPos, out member.passive_skill);

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
		if(vecLine.Count != 26)
		{
			Ex.Logger.Log("PetProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_display"){Ex.Logger.Log("PetProto.csv中字段[is_display]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("PetProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="description"){Ex.Logger.Log("PetProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[5]!="rarity"){Ex.Logger.Log("PetProto.csv中字段[rarity]位置不对应"); return false; }
		if(vecLine[6]!="rarity_color"){Ex.Logger.Log("PetProto.csv中字段[rarity_color]位置不对应"); return false; }
		if(vecLine[7]!="type"){Ex.Logger.Log("PetProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[8]!="icon"){Ex.Logger.Log("PetProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[9]!="model"){Ex.Logger.Log("PetProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[10]!="show_offside"){Ex.Logger.Log("PetProto.csv中字段[show_offside]位置不对应"); return false; }
		if(vecLine[11]!="init_index_id"){Ex.Logger.Log("PetProto.csv中字段[init_index_id]位置不对应"); return false; }
		if(vecLine[12]!="leisure_pro"){Ex.Logger.Log("PetProto.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[13]!="talent_pic"){Ex.Logger.Log("PetProto.csv中字段[talent_pic]位置不对应"); return false; }
		if(vecLine[14]!="speed"){Ex.Logger.Log("PetProto.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[15]!="run_rate"){Ex.Logger.Log("PetProto.csv中字段[run_rate]位置不对应"); return false; }
		if(vecLine[16]!="spawn_action"){Ex.Logger.Log("PetProto.csv中字段[spawn_action]位置不对应"); return false; }
		if(vecLine[17]!="possesssed_action"){Ex.Logger.Log("PetProto.csv中字段[possesssed_action]位置不对应"); return false; }
		if(vecLine[18]!="transform_eff"){Ex.Logger.Log("PetProto.csv中字段[transform_eff]位置不对应"); return false; }
		if(vecLine[19]!="lightsphere_eff"){Ex.Logger.Log("PetProto.csv中字段[lightsphere_eff]位置不对应"); return false; }
		if(vecLine[20]!="possesssed_buff"){Ex.Logger.Log("PetProto.csv中字段[possesssed_buff]位置不对应"); return false; }
		if(vecLine[21]!="leave_fight_action"){Ex.Logger.Log("PetProto.csv中字段[leave_fight_action]位置不对应"); return false; }
		if(vecLine[22]!="interact_action"){Ex.Logger.Log("PetProto.csv中字段[interact_action]位置不对应"); return false; }
		if(vecLine[23]!="level_up_action"){Ex.Logger.Log("PetProto.csv中字段[level_up_action]位置不对应"); return false; }
		if(vecLine[24]!="active_skill"){Ex.Logger.Log("PetProto.csv中字段[active_skill]位置不对应"); return false; }
		if(vecLine[25]!="passive_skill"){Ex.Logger.Log("PetProto.csv中字段[passive_skill]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)26)
			{
				return false;
			}
			PetProtoElement member = new PetProtoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.is_display=Convert.ToInt32(vecLine[2]);
			member.name=Convert.ToInt32(vecLine[3]);
			member.description=Convert.ToInt32(vecLine[4]);
			member.rarity=vecLine[5];
			member.rarity_color=Convert.ToInt32(vecLine[6]);
			member.type=Convert.ToInt32(vecLine[7]);
			member.icon=vecLine[8];
			member.model=vecLine[9];
			member.show_offside=vecLine[10];
			member.init_index_id=Convert.ToInt32(vecLine[11]);
			member.leisure_pro=Convert.ToSingle(vecLine[12]);
			member.talent_pic=vecLine[13];
			member.speed=Convert.ToInt32(vecLine[14]);
			member.run_rate=Convert.ToSingle(vecLine[15]);
			member.spawn_action=Convert.ToInt32(vecLine[16]);
			member.possesssed_action=Convert.ToInt32(vecLine[17]);
			member.transform_eff=vecLine[18];
			member.lightsphere_eff=vecLine[19];
			member.possesssed_buff=vecLine[20];
			member.leave_fight_action=Convert.ToInt32(vecLine[21]);
			member.interact_action=Convert.ToInt32(vecLine[22]);
			member.level_up_action=Convert.ToInt32(vecLine[23]);
			member.active_skill=Convert.ToInt32(vecLine[24]);
			member.passive_skill=vecLine[25];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
