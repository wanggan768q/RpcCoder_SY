using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//副本表配置数据类
public class DungeonElement
{
	public int id;               	//序号	序号
	public string comment;       	//	
	public int map_id;           	//场景ID	对应Scene_场景表
	public int dungeon_type;     	//副本类型	
	public int order;            	//副本查找器索引	副本查找器索引顺序
	public int enter_location;   	//进入副本路点	野外地图进入副本传送门的位置，对应路点表
	public int difficult;        	//难度文本	对应StringUi_界面文本表
	public li level;             	//玩家等级	所需玩家等级 等级下限|等级上限
	public li player_config_list;	//玩家职能推荐	坦克人数|治疗人数|输出人数
	public string obj_group;     	//	怪物所属分组，
	public int min_num;          	//最小玩家数量	默认为1
	public int max_num;          	//最大玩家数量	默认为1
	public int required_last_dungeon_id;	//所需前置副本ID	
	public int reset_type;       	//重置类型	
	public int finish_amount;    	//允许玩家完成次数	
	public int friendship_add;   	//友好度增加	好友组队进行副本增加的友好度数值
	public int name_id;          	//副本名字ID	对应StringUi_界面文本表
	public int describle_id;     	//副本描述ID	对应StringUi_界面文本表
	public int simple_describle_id;	//副本简单描述ID	对应StringUi_界面文本表
	public int mini_pic;         	//进副时弹出的面板中的副本图片	
	public int First_reward_ui;  	//首通奖励礼包ID	
	public int general_reward__ui;	//非首通奖励礼包ID	
	public int is_transfer;      	//是否需要装备中转表	
	public string start_music;   	//开启音乐	
	public string loop_music;    	//循环音乐	
	public int endingboss_id;    	//最后boss ID	对应Creature_总NPC表
	public int duration_time;    	//副本存活时间	
	public int destroy_time;     	//副本摧毁时间	秒为单位
	public int conclusion_time;  	//副本结算时间	s为单位
	public int start_time;       	//副本开启时间	
	public int end_time;         	//副本关闭时间	
	public int teleport_id;      	//通关传送门ID	
	public int teleport_location;	//传送门生成路点	对应WayPoint_路点表ID
	public string teleporteffect;	//传送门特效	
	public int exit_waypoint;    	//退出副本后的路点	对应WayPoint_路点表ID
	public string monster_id;    	//副本怪物ID	不同难度副本对应的不同的Monster.json文件，-1表示未配置Monster.json文件
	public string dungeon_lua;   	//副本脚本	对应 ice_server\trunk\bin\Config\Script\Dungeon下的脚本
	public li area_id;           	//区域id	
	public int monster_delay;    	//刷怪延迟	创建副本后n秒刷怪  单位：秒
	public int second_verification;	//二次确认	副本最低进入人数＞1该字段生效 效果是进入副本时是否弹出二次确认面板 0需要 1不需要

	public bool IsValidate = false;
	public DungeonElement()
	{
		id = -1;
	}
};

//副本表配置封装类
public class DungeonTable
{

	private DungeonTable()
	{
		m_mapElements = new Dictionary<int, DungeonElement>();
		m_emptyItem = new DungeonElement();
		m_vecAllElements = new List<DungeonElement>();
	}
	private Dictionary<int, DungeonElement> m_mapElements = null;
	private List<DungeonElement>	m_vecAllElements = null;
	private DungeonElement m_emptyItem = null;
	private static DungeonTable sInstance = null;

	public static DungeonTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new DungeonTable();
			return sInstance;
		}
	}

	public DungeonElement GetElement(int key)
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

  public List<DungeonElement> GetAllElement(Predicate<DungeonElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Dungeon.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Dungeon.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Dungeon.bin]未找到");
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
		if(vecLine.Count != 40)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Dungeon.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[4]!="order"){Ex.Logger.Log("Dungeon.csv中字段[order]位置不对应"); return false; }
		if(vecLine[5]!="enter_location"){Ex.Logger.Log("Dungeon.csv中字段[enter_location]位置不对应"); return false; }
		if(vecLine[6]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[7]!="level"){Ex.Logger.Log("Dungeon.csv中字段[level]位置不对应"); return false; }
		if(vecLine[8]!="player_config_list"){Ex.Logger.Log("Dungeon.csv中字段[player_config_list]位置不对应"); return false; }
		if(vecLine[9]!="obj_group"){Ex.Logger.Log("Dungeon.csv中字段[obj_group]位置不对应"); return false; }
		if(vecLine[10]!="min_num"){Ex.Logger.Log("Dungeon.csv中字段[min_num]位置不对应"); return false; }
		if(vecLine[11]!="max_num"){Ex.Logger.Log("Dungeon.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[12]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[13]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[14]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[15]!="friendship_add"){Ex.Logger.Log("Dungeon.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[16]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[17]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[18]!="simple_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[simple_describle_id]位置不对应"); return false; }
		if(vecLine[19]!="mini_pic"){Ex.Logger.Log("Dungeon.csv中字段[mini_pic]位置不对应"); return false; }
		if(vecLine[20]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[21]!="general_reward__ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[22]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[23]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[24]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[25]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[26]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[27]!="destroy_time"){Ex.Logger.Log("Dungeon.csv中字段[destroy_time]位置不对应"); return false; }
		if(vecLine[28]!="conclusion_time"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_time]位置不对应"); return false; }
		if(vecLine[29]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[30]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }
		if(vecLine[31]!="teleport_id"){Ex.Logger.Log("Dungeon.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[32]!="teleport_location"){Ex.Logger.Log("Dungeon.csv中字段[teleport_location]位置不对应"); return false; }
		if(vecLine[33]!="teleporteffect"){Ex.Logger.Log("Dungeon.csv中字段[teleporteffect]位置不对应"); return false; }
		if(vecLine[34]!="exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[exit_waypoint]位置不对应"); return false; }
		if(vecLine[35]!="monster_id"){Ex.Logger.Log("Dungeon.csv中字段[monster_id]位置不对应"); return false; }
		if(vecLine[36]!="dungeon_lua"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_lua]位置不对应"); return false; }
		if(vecLine[37]!="area_id"){Ex.Logger.Log("Dungeon.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[38]!="monster_delay"){Ex.Logger.Log("Dungeon.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[39]!="second_verification"){Ex.Logger.Log("Dungeon.csv中字段[second_verification]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DungeonElement member = new DungeonElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.enter_location );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.difficult );
			readPos += GameAssist.ReadString( binContent, readPos, out member.level);
			readPos += GameAssist.ReadString( binContent, readPos, out member.player_config_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.obj_group);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.min_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_last_dungeon_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reset_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.finish_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.friendship_add );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describle_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.simple_describle_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mini_pic );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.First_reward_ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.general_reward__ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_transfer );
			readPos += GameAssist.ReadString( binContent, readPos, out member.start_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.endingboss_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.destroy_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.conclusion_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.start_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.end_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_location );
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleporteffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exit_waypoint );
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.dungeon_lua);
			readPos += GameAssist.ReadString( binContent, readPos, out member.area_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster_delay );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.second_verification );

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
		if(vecLine.Count != 40)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Dungeon.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[4]!="order"){Ex.Logger.Log("Dungeon.csv中字段[order]位置不对应"); return false; }
		if(vecLine[5]!="enter_location"){Ex.Logger.Log("Dungeon.csv中字段[enter_location]位置不对应"); return false; }
		if(vecLine[6]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[7]!="level"){Ex.Logger.Log("Dungeon.csv中字段[level]位置不对应"); return false; }
		if(vecLine[8]!="player_config_list"){Ex.Logger.Log("Dungeon.csv中字段[player_config_list]位置不对应"); return false; }
		if(vecLine[9]!="obj_group"){Ex.Logger.Log("Dungeon.csv中字段[obj_group]位置不对应"); return false; }
		if(vecLine[10]!="min_num"){Ex.Logger.Log("Dungeon.csv中字段[min_num]位置不对应"); return false; }
		if(vecLine[11]!="max_num"){Ex.Logger.Log("Dungeon.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[12]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[13]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[14]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[15]!="friendship_add"){Ex.Logger.Log("Dungeon.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[16]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[17]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[18]!="simple_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[simple_describle_id]位置不对应"); return false; }
		if(vecLine[19]!="mini_pic"){Ex.Logger.Log("Dungeon.csv中字段[mini_pic]位置不对应"); return false; }
		if(vecLine[20]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[21]!="general_reward__ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[22]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[23]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[24]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[25]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[26]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[27]!="destroy_time"){Ex.Logger.Log("Dungeon.csv中字段[destroy_time]位置不对应"); return false; }
		if(vecLine[28]!="conclusion_time"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_time]位置不对应"); return false; }
		if(vecLine[29]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[30]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }
		if(vecLine[31]!="teleport_id"){Ex.Logger.Log("Dungeon.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[32]!="teleport_location"){Ex.Logger.Log("Dungeon.csv中字段[teleport_location]位置不对应"); return false; }
		if(vecLine[33]!="teleporteffect"){Ex.Logger.Log("Dungeon.csv中字段[teleporteffect]位置不对应"); return false; }
		if(vecLine[34]!="exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[exit_waypoint]位置不对应"); return false; }
		if(vecLine[35]!="monster_id"){Ex.Logger.Log("Dungeon.csv中字段[monster_id]位置不对应"); return false; }
		if(vecLine[36]!="dungeon_lua"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_lua]位置不对应"); return false; }
		if(vecLine[37]!="area_id"){Ex.Logger.Log("Dungeon.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[38]!="monster_delay"){Ex.Logger.Log("Dungeon.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[39]!="second_verification"){Ex.Logger.Log("Dungeon.csv中字段[second_verification]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)40)
			{
				return false;
			}
			DungeonElement member = new DungeonElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.map_id=Convert.ToInt32(vecLine[2]);
			member.dungeon_type=Convert.ToInt32(vecLine[3]);
			member.order=Convert.ToInt32(vecLine[4]);
			member.enter_location=Convert.ToInt32(vecLine[5]);
			member.difficult=Convert.ToInt32(vecLine[6]);
			member.level=vecLine[7];
			member.player_config_list=vecLine[8];
			member.obj_group=vecLine[9];
			member.min_num=Convert.ToInt32(vecLine[10]);
			member.max_num=Convert.ToInt32(vecLine[11]);
			member.required_last_dungeon_id=Convert.ToInt32(vecLine[12]);
			member.reset_type=Convert.ToInt32(vecLine[13]);
			member.finish_amount=Convert.ToInt32(vecLine[14]);
			member.friendship_add=Convert.ToInt32(vecLine[15]);
			member.name_id=Convert.ToInt32(vecLine[16]);
			member.describle_id=Convert.ToInt32(vecLine[17]);
			member.simple_describle_id=Convert.ToInt32(vecLine[18]);
			member.mini_pic=Convert.ToInt32(vecLine[19]);
			member.First_reward_ui=Convert.ToInt32(vecLine[20]);
			member.general_reward__ui=Convert.ToInt32(vecLine[21]);
			member.is_transfer=Convert.ToInt32(vecLine[22]);
			member.start_music=vecLine[23];
			member.loop_music=vecLine[24];
			member.endingboss_id=Convert.ToInt32(vecLine[25]);
			member.duration_time=Convert.ToInt32(vecLine[26]);
			member.destroy_time=Convert.ToInt32(vecLine[27]);
			member.conclusion_time=Convert.ToInt32(vecLine[28]);
			member.start_time=Convert.ToInt32(vecLine[29]);
			member.end_time=Convert.ToInt32(vecLine[30]);
			member.teleport_id=Convert.ToInt32(vecLine[31]);
			member.teleport_location=Convert.ToInt32(vecLine[32]);
			member.teleporteffect=vecLine[33];
			member.exit_waypoint=Convert.ToInt32(vecLine[34]);
			member.monster_id=vecLine[35];
			member.dungeon_lua=vecLine[36];
			member.area_id=vecLine[37];
			member.monster_delay=Convert.ToInt32(vecLine[38]);
			member.second_verification=Convert.ToInt32(vecLine[39]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
