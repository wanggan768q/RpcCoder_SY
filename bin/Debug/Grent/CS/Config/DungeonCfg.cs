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
	public int map_id;           	//场景ID	对应Scene_场景表ID
	public int dungeon_type;     	//副本类型	0：野外 1：2~5人普通 2：2~5人困难 3：单人（非剧情） 4：团队普通 5：团队困难 6：公会 7：单人爬塔 8：单人剧情 9：组队活动副本
	public int rebotonoff;       	//是否创建机器人	0 不创建 1 创建 
	public int auto_on;          	//自动开启自动副本	进入副本后自动开启自动副本 1 自动开启 0 不自动开启
	public int order;            	//副本查找器索引	按等级开启顺序排序，同一副本的不同难度，按难度排序 -1：不在副本查找器中显示（特殊类型，如日常活动等）
	public int enter_location;   	//副本入口传送门位置	野外场景，副本入口传送门的位置，对应路点表
	public int difficult;        	//难度文本	野外碰触副本入口时弹出的UI中难度按钮文本。读StringUi表
	public li level;             	//副本等级	进入副本所需玩家等级 等级下限|等级上限
	public int tips_lv;          	//弹窗需求等级	进入低级副本时的弹窗条件： 0  永远不弹 N  玩家当前等级-副本等级大于等于N时 弹窗
	public int recommend_power;  	//推荐战力	UI显示用
	public int rebirth_num;      	//原地复活次数	每次生成的副本每玩家允许原地复活的次数 0/不填  不允许 1~98  X次数 99  不限次 
	public li open_day;          	//每周开放日	例如：2|4 每周二、四开放
	public li player_config_list;	//玩家职业推荐	坦克人数|治疗人数|输出人数
	public string obj_group;     	//怪物所属分组	此字段无用 ice_server\trunk\bin\Config\Scene相应文件夹下的monster文件
	public int team_type;        	//队伍状态	进入副本需求当前队伍状态 0/不填  不限制 1  单人 2  小队 3  团队
	public int min_num;          	//最少玩家数量	进入副本至少需求X名玩家 默认为1
	public int max_num;          	//最多玩家数量	副本内最多可进入X名玩家默认为1 最大为10 （单人本需填写1，超过1则需要组队才能进入）
	public int required_quest_id;	//需接到任务	只有接到指定ID的任务才能进入该副本
	public int required_last_dungeon_id;	//所需前置副本ID	只有通关指定的副本ID才能解锁该副本
	public int reset_type;       	//重置类型	服务器没用此字段 1：每日早上5点重置 2：每周固定时间维护 3：每次副本销毁后重置 默认为1。重置后首通奖励重置且进度清空。
	public int finish_amount;    	//允许玩家完成次数	服务器没用此字段允许玩家最多完成的副本次数，超出该次数不再获得奖励
	public int halfway_join;     	//续排类型	是否允许中途进入副本 0 允许，可在任意阶段中途进入。 1 不允许，任意阶段都不允许中途进入。 2 只要有队员处于首领战状态就禁止进入，其余阶段可进入
	public int friendship_add;   	//友好度增加	服务器没用此字段 好友组队进行副本增加的友好度数值
	public int name_id;          	//副本名字ID	对应StringUi_界面文本表
	public int describle_id;     	//副本描述ID	对应StringUi_界面文本表
	public int simple_describle_id;	//副本简单描述ID	对应StringUi_界面文本表
	public int story_describle_id;	//剧情本结算描述	对应StringUi_界面文本表
	public string mini_pic;      	//副本图片	野外碰触副本入口时弹出的UI中显示的副本图片 填图片资源名
	public int First_reward_ui;  	//首通奖励礼包ID	服务器没用此字段
	public int general_reward_ui;	//非首通奖励礼包ID	服务器没用此字段
	public li reward_display;    	//奖励显示	进副本时弹出的面板中展示的奖励图标，对应ItemProto_道具原型表，为数组
	public int is_transfer;      	//是否需要装备中转表	服务器没用此字段
	public string start_music;   	//开启音乐	此字段无用。音乐在场景表中。
	public string loop_music;    	//循环音乐	此字段无用。音乐在场景表中。
	public int kill_refresh;     	//击杀次数刷新	1=每日刷新 7=每周刷新 99=永不刷新（剧情本用）
	public li boss_id;           	//bossid	最左边开始是1号BOSS
	public li boss_kill_num;     	//boss可击杀次数	同难度同序号BOSS共享次数（剧情副本则是每个副本单独计数、不共享）
	public li all_rewards;       	//此难度奖励总览	展示道具id，UI显示用
	public string map_pic;       	//地图图片	雷达图
	public li boss_rewards;      	//boss掉落展示	固定5个（全局表ID40配置） 副本内有3个BOSS掉落数量3、5、4的填法如下 1|2|3|0|0|1|2|3|4|5|1|2|3|4|0 副本内有2个BOSS掉落数量3、5的填法如下 1|2|3|0|0|1|2|3|4|5
	public int endingboss_id;    	//最后boss ID	对应Creature_总NPC表
	public int automatic_entry;  	//是否自动进入	配置0不自动准备 配置1自动准备  默认为0
	public int duration_time;    	//副本总时长	 脚本未配置才读这里. 副本从创建到销毁的总时长 单位秒
	public int prepare_time;     	//副本准备时间	脚本未配置才读这里. 副本生成后，最开始的准备时间单位秒
	public int reward_time;      	//副本结算时间	脚本未配置才读这里. 单位秒
	public int conclusion_delayed;	//结算动画延迟时间	结算时间到后延迟多少秒播放结算动画 单位为秒
	public int start_time;       	//副本开启时间	服务器没用此字段
	public int end_time;         	//副本关闭时间	服务器没用此字段
	public int teleport_id;      	//通关传送门ID	
	public int teleport_location;	//传送门生成路点	对应WayPoint_路点表ID
	public string teleporteffect;	//传送门特效	
	public int exit_waypoint;    	//胜利后的传出位置	副本胜利后传出的位置。 对应WayPoint_路点表ID
	public int defeat_exit_waypoint;	//未胜利的传出位置	副本失败/中途退出/中途离线后传出的位置。 对应WayPoint_路点表ID
	public string monster_id;    	//副本怪物ID	不同难度副本对应的不同的Monster.json文件，-1表示未配置Monster.json文件
	public string dungeon_lua;   	//副本脚本	对应 ice_server\trunk\bin\Config\Script\Dungeon下的脚本
	public string behaviac;      	//副本行为树	Config/behaviac/下的目录
	public li area_id;           	//区域id	
	public int monster_delay;    	//刷怪延迟	创建副本后n秒刷怪  单位：秒
	public int second_verification;	//二次确认	副本最低进入人数＞1该字段生效 效果是进入副本时是否弹出二次确认面板 0需要 1不需要
	public int display_point;    	//副本展示点	关联路点表，填id使用有亮相的结算类型，不填id使用无结算的类型。
	public int display_damage;   	//伤害显示	副本内是否显示伤害累计  1为显示，0或不填为不显示
	public int activity_id;      	//活动id	关联的活动id  空或-1则没有关联
	public int team_id;          	//组队界面id	关联的组队界面id （点击组队按钮跳转组队UI用） 空或-1则没有关联
	public int team_jump;        	//组队界面跳转	该副本点击挑战按钮是否会跳转到组队界面（副本圆球进入界面） 0：不跳转 1：跳转
	public int canuse_blood;     	//是否可用血瓶	龙魂神殿副本不可使用血瓶功能 0或不填：可用 1：不可用

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
		if(vecLine.Count != 66)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[2]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[3]!="rebotonoff"){Ex.Logger.Log("Dungeon.csv中字段[rebotonoff]位置不对应"); return false; }
		if(vecLine[4]!="auto_on"){Ex.Logger.Log("Dungeon.csv中字段[auto_on]位置不对应"); return false; }
		if(vecLine[5]!="order"){Ex.Logger.Log("Dungeon.csv中字段[order]位置不对应"); return false; }
		if(vecLine[6]!="enter_location"){Ex.Logger.Log("Dungeon.csv中字段[enter_location]位置不对应"); return false; }
		if(vecLine[7]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("Dungeon.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="tips_lv"){Ex.Logger.Log("Dungeon.csv中字段[tips_lv]位置不对应"); return false; }
		if(vecLine[10]!="recommend_power"){Ex.Logger.Log("Dungeon.csv中字段[recommend_power]位置不对应"); return false; }
		if(vecLine[11]!="rebirth_num"){Ex.Logger.Log("Dungeon.csv中字段[rebirth_num]位置不对应"); return false; }
		if(vecLine[12]!="open_day"){Ex.Logger.Log("Dungeon.csv中字段[open_day]位置不对应"); return false; }
		if(vecLine[13]!="player_config_list"){Ex.Logger.Log("Dungeon.csv中字段[player_config_list]位置不对应"); return false; }
		if(vecLine[14]!="obj_group"){Ex.Logger.Log("Dungeon.csv中字段[obj_group]位置不对应"); return false; }
		if(vecLine[15]!="team_type"){Ex.Logger.Log("Dungeon.csv中字段[team_type]位置不对应"); return false; }
		if(vecLine[16]!="min_num"){Ex.Logger.Log("Dungeon.csv中字段[min_num]位置不对应"); return false; }
		if(vecLine[17]!="max_num"){Ex.Logger.Log("Dungeon.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[18]!="required_quest_id"){Ex.Logger.Log("Dungeon.csv中字段[required_quest_id]位置不对应"); return false; }
		if(vecLine[19]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[20]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[21]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[22]!="halfway_join"){Ex.Logger.Log("Dungeon.csv中字段[halfway_join]位置不对应"); return false; }
		if(vecLine[23]!="friendship_add"){Ex.Logger.Log("Dungeon.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[24]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[25]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[26]!="simple_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[simple_describle_id]位置不对应"); return false; }
		if(vecLine[27]!="story_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[story_describle_id]位置不对应"); return false; }
		if(vecLine[28]!="mini_pic"){Ex.Logger.Log("Dungeon.csv中字段[mini_pic]位置不对应"); return false; }
		if(vecLine[29]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[30]!="general_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward_ui]位置不对应"); return false; }
		if(vecLine[31]!="reward_display"){Ex.Logger.Log("Dungeon.csv中字段[reward_display]位置不对应"); return false; }
		if(vecLine[32]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[33]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[34]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[35]!="kill_refresh"){Ex.Logger.Log("Dungeon.csv中字段[kill_refresh]位置不对应"); return false; }
		if(vecLine[36]!="boss_id"){Ex.Logger.Log("Dungeon.csv中字段[boss_id]位置不对应"); return false; }
		if(vecLine[37]!="boss_kill_num"){Ex.Logger.Log("Dungeon.csv中字段[boss_kill_num]位置不对应"); return false; }
		if(vecLine[38]!="all_rewards"){Ex.Logger.Log("Dungeon.csv中字段[all_rewards]位置不对应"); return false; }
		if(vecLine[39]!="map_pic"){Ex.Logger.Log("Dungeon.csv中字段[map_pic]位置不对应"); return false; }
		if(vecLine[40]!="boss_rewards"){Ex.Logger.Log("Dungeon.csv中字段[boss_rewards]位置不对应"); return false; }
		if(vecLine[41]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[42]!="automatic_entry"){Ex.Logger.Log("Dungeon.csv中字段[automatic_entry]位置不对应"); return false; }
		if(vecLine[43]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[44]!="prepare_time"){Ex.Logger.Log("Dungeon.csv中字段[prepare_time]位置不对应"); return false; }
		if(vecLine[45]!="reward_time"){Ex.Logger.Log("Dungeon.csv中字段[reward_time]位置不对应"); return false; }
		if(vecLine[46]!="conclusion_delayed"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_delayed]位置不对应"); return false; }
		if(vecLine[47]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[48]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }
		if(vecLine[49]!="teleport_id"){Ex.Logger.Log("Dungeon.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[50]!="teleport_location"){Ex.Logger.Log("Dungeon.csv中字段[teleport_location]位置不对应"); return false; }
		if(vecLine[51]!="teleporteffect"){Ex.Logger.Log("Dungeon.csv中字段[teleporteffect]位置不对应"); return false; }
		if(vecLine[52]!="exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[exit_waypoint]位置不对应"); return false; }
		if(vecLine[53]!="defeat_exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[defeat_exit_waypoint]位置不对应"); return false; }
		if(vecLine[54]!="monster_id"){Ex.Logger.Log("Dungeon.csv中字段[monster_id]位置不对应"); return false; }
		if(vecLine[55]!="dungeon_lua"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_lua]位置不对应"); return false; }
		if(vecLine[56]!="behaviac"){Ex.Logger.Log("Dungeon.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[57]!="area_id"){Ex.Logger.Log("Dungeon.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[58]!="monster_delay"){Ex.Logger.Log("Dungeon.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[59]!="second_verification"){Ex.Logger.Log("Dungeon.csv中字段[second_verification]位置不对应"); return false; }
		if(vecLine[60]!="display_point"){Ex.Logger.Log("Dungeon.csv中字段[display_point]位置不对应"); return false; }
		if(vecLine[61]!="display_damage"){Ex.Logger.Log("Dungeon.csv中字段[display_damage]位置不对应"); return false; }
		if(vecLine[62]!="activity_id"){Ex.Logger.Log("Dungeon.csv中字段[activity_id]位置不对应"); return false; }
		if(vecLine[63]!="team_id"){Ex.Logger.Log("Dungeon.csv中字段[team_id]位置不对应"); return false; }
		if(vecLine[64]!="team_jump"){Ex.Logger.Log("Dungeon.csv中字段[team_jump]位置不对应"); return false; }
		if(vecLine[65]!="canuse_blood"){Ex.Logger.Log("Dungeon.csv中字段[canuse_blood]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DungeonElement member = new DungeonElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rebotonoff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auto_on );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.enter_location );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.difficult );
			readPos += GameAssist.ReadString( binContent, readPos, out member.level);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tips_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recommend_power );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rebirth_num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.open_day);
			readPos += GameAssist.ReadString( binContent, readPos, out member.player_config_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.obj_group);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.team_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.min_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_last_dungeon_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reset_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.finish_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.halfway_join );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.friendship_add );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describle_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.simple_describle_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.story_describle_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mini_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.First_reward_ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.general_reward_ui );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_display);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_transfer );
			readPos += GameAssist.ReadString( binContent, readPos, out member.start_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.kill_refresh );
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_kill_num);
			readPos += GameAssist.ReadString( binContent, readPos, out member.all_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_pic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_rewards);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.endingboss_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.automatic_entry );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.prepare_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reward_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.conclusion_delayed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.start_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.end_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_location );
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleporteffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exit_waypoint );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.defeat_exit_waypoint );
			readPos += GameAssist.ReadString( binContent, readPos, out member.monster_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.dungeon_lua);
			readPos += GameAssist.ReadString( binContent, readPos, out member.behaviac);
			readPos += GameAssist.ReadString( binContent, readPos, out member.area_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster_delay );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.second_verification );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.display_point );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.display_damage );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.activity_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.team_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.team_jump );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.canuse_blood );

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
		if(vecLine.Count != 66)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[2]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[3]!="rebotonoff"){Ex.Logger.Log("Dungeon.csv中字段[rebotonoff]位置不对应"); return false; }
		if(vecLine[4]!="auto_on"){Ex.Logger.Log("Dungeon.csv中字段[auto_on]位置不对应"); return false; }
		if(vecLine[5]!="order"){Ex.Logger.Log("Dungeon.csv中字段[order]位置不对应"); return false; }
		if(vecLine[6]!="enter_location"){Ex.Logger.Log("Dungeon.csv中字段[enter_location]位置不对应"); return false; }
		if(vecLine[7]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("Dungeon.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="tips_lv"){Ex.Logger.Log("Dungeon.csv中字段[tips_lv]位置不对应"); return false; }
		if(vecLine[10]!="recommend_power"){Ex.Logger.Log("Dungeon.csv中字段[recommend_power]位置不对应"); return false; }
		if(vecLine[11]!="rebirth_num"){Ex.Logger.Log("Dungeon.csv中字段[rebirth_num]位置不对应"); return false; }
		if(vecLine[12]!="open_day"){Ex.Logger.Log("Dungeon.csv中字段[open_day]位置不对应"); return false; }
		if(vecLine[13]!="player_config_list"){Ex.Logger.Log("Dungeon.csv中字段[player_config_list]位置不对应"); return false; }
		if(vecLine[14]!="obj_group"){Ex.Logger.Log("Dungeon.csv中字段[obj_group]位置不对应"); return false; }
		if(vecLine[15]!="team_type"){Ex.Logger.Log("Dungeon.csv中字段[team_type]位置不对应"); return false; }
		if(vecLine[16]!="min_num"){Ex.Logger.Log("Dungeon.csv中字段[min_num]位置不对应"); return false; }
		if(vecLine[17]!="max_num"){Ex.Logger.Log("Dungeon.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[18]!="required_quest_id"){Ex.Logger.Log("Dungeon.csv中字段[required_quest_id]位置不对应"); return false; }
		if(vecLine[19]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[20]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[21]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[22]!="halfway_join"){Ex.Logger.Log("Dungeon.csv中字段[halfway_join]位置不对应"); return false; }
		if(vecLine[23]!="friendship_add"){Ex.Logger.Log("Dungeon.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[24]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[25]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[26]!="simple_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[simple_describle_id]位置不对应"); return false; }
		if(vecLine[27]!="story_describle_id"){Ex.Logger.Log("Dungeon.csv中字段[story_describle_id]位置不对应"); return false; }
		if(vecLine[28]!="mini_pic"){Ex.Logger.Log("Dungeon.csv中字段[mini_pic]位置不对应"); return false; }
		if(vecLine[29]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[30]!="general_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward_ui]位置不对应"); return false; }
		if(vecLine[31]!="reward_display"){Ex.Logger.Log("Dungeon.csv中字段[reward_display]位置不对应"); return false; }
		if(vecLine[32]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[33]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[34]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[35]!="kill_refresh"){Ex.Logger.Log("Dungeon.csv中字段[kill_refresh]位置不对应"); return false; }
		if(vecLine[36]!="boss_id"){Ex.Logger.Log("Dungeon.csv中字段[boss_id]位置不对应"); return false; }
		if(vecLine[37]!="boss_kill_num"){Ex.Logger.Log("Dungeon.csv中字段[boss_kill_num]位置不对应"); return false; }
		if(vecLine[38]!="all_rewards"){Ex.Logger.Log("Dungeon.csv中字段[all_rewards]位置不对应"); return false; }
		if(vecLine[39]!="map_pic"){Ex.Logger.Log("Dungeon.csv中字段[map_pic]位置不对应"); return false; }
		if(vecLine[40]!="boss_rewards"){Ex.Logger.Log("Dungeon.csv中字段[boss_rewards]位置不对应"); return false; }
		if(vecLine[41]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[42]!="automatic_entry"){Ex.Logger.Log("Dungeon.csv中字段[automatic_entry]位置不对应"); return false; }
		if(vecLine[43]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[44]!="prepare_time"){Ex.Logger.Log("Dungeon.csv中字段[prepare_time]位置不对应"); return false; }
		if(vecLine[45]!="reward_time"){Ex.Logger.Log("Dungeon.csv中字段[reward_time]位置不对应"); return false; }
		if(vecLine[46]!="conclusion_delayed"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_delayed]位置不对应"); return false; }
		if(vecLine[47]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[48]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }
		if(vecLine[49]!="teleport_id"){Ex.Logger.Log("Dungeon.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[50]!="teleport_location"){Ex.Logger.Log("Dungeon.csv中字段[teleport_location]位置不对应"); return false; }
		if(vecLine[51]!="teleporteffect"){Ex.Logger.Log("Dungeon.csv中字段[teleporteffect]位置不对应"); return false; }
		if(vecLine[52]!="exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[exit_waypoint]位置不对应"); return false; }
		if(vecLine[53]!="defeat_exit_waypoint"){Ex.Logger.Log("Dungeon.csv中字段[defeat_exit_waypoint]位置不对应"); return false; }
		if(vecLine[54]!="monster_id"){Ex.Logger.Log("Dungeon.csv中字段[monster_id]位置不对应"); return false; }
		if(vecLine[55]!="dungeon_lua"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_lua]位置不对应"); return false; }
		if(vecLine[56]!="behaviac"){Ex.Logger.Log("Dungeon.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[57]!="area_id"){Ex.Logger.Log("Dungeon.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[58]!="monster_delay"){Ex.Logger.Log("Dungeon.csv中字段[monster_delay]位置不对应"); return false; }
		if(vecLine[59]!="second_verification"){Ex.Logger.Log("Dungeon.csv中字段[second_verification]位置不对应"); return false; }
		if(vecLine[60]!="display_point"){Ex.Logger.Log("Dungeon.csv中字段[display_point]位置不对应"); return false; }
		if(vecLine[61]!="display_damage"){Ex.Logger.Log("Dungeon.csv中字段[display_damage]位置不对应"); return false; }
		if(vecLine[62]!="activity_id"){Ex.Logger.Log("Dungeon.csv中字段[activity_id]位置不对应"); return false; }
		if(vecLine[63]!="team_id"){Ex.Logger.Log("Dungeon.csv中字段[team_id]位置不对应"); return false; }
		if(vecLine[64]!="team_jump"){Ex.Logger.Log("Dungeon.csv中字段[team_jump]位置不对应"); return false; }
		if(vecLine[65]!="canuse_blood"){Ex.Logger.Log("Dungeon.csv中字段[canuse_blood]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)66)
			{
				return false;
			}
			DungeonElement member = new DungeonElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.map_id=Convert.ToInt32(vecLine[1]);
			member.dungeon_type=Convert.ToInt32(vecLine[2]);
			member.rebotonoff=Convert.ToInt32(vecLine[3]);
			member.auto_on=Convert.ToInt32(vecLine[4]);
			member.order=Convert.ToInt32(vecLine[5]);
			member.enter_location=Convert.ToInt32(vecLine[6]);
			member.difficult=Convert.ToInt32(vecLine[7]);
			member.level=vecLine[8];
			member.tips_lv=Convert.ToInt32(vecLine[9]);
			member.recommend_power=Convert.ToInt32(vecLine[10]);
			member.rebirth_num=Convert.ToInt32(vecLine[11]);
			member.open_day=vecLine[12];
			member.player_config_list=vecLine[13];
			member.obj_group=vecLine[14];
			member.team_type=Convert.ToInt32(vecLine[15]);
			member.min_num=Convert.ToInt32(vecLine[16]);
			member.max_num=Convert.ToInt32(vecLine[17]);
			member.required_quest_id=Convert.ToInt32(vecLine[18]);
			member.required_last_dungeon_id=Convert.ToInt32(vecLine[19]);
			member.reset_type=Convert.ToInt32(vecLine[20]);
			member.finish_amount=Convert.ToInt32(vecLine[21]);
			member.halfway_join=Convert.ToInt32(vecLine[22]);
			member.friendship_add=Convert.ToInt32(vecLine[23]);
			member.name_id=Convert.ToInt32(vecLine[24]);
			member.describle_id=Convert.ToInt32(vecLine[25]);
			member.simple_describle_id=Convert.ToInt32(vecLine[26]);
			member.story_describle_id=Convert.ToInt32(vecLine[27]);
			member.mini_pic=vecLine[28];
			member.First_reward_ui=Convert.ToInt32(vecLine[29]);
			member.general_reward_ui=Convert.ToInt32(vecLine[30]);
			member.reward_display=vecLine[31];
			member.is_transfer=Convert.ToInt32(vecLine[32]);
			member.start_music=vecLine[33];
			member.loop_music=vecLine[34];
			member.kill_refresh=Convert.ToInt32(vecLine[35]);
			member.boss_id=vecLine[36];
			member.boss_kill_num=vecLine[37];
			member.all_rewards=vecLine[38];
			member.map_pic=vecLine[39];
			member.boss_rewards=vecLine[40];
			member.endingboss_id=Convert.ToInt32(vecLine[41]);
			member.automatic_entry=Convert.ToInt32(vecLine[42]);
			member.duration_time=Convert.ToInt32(vecLine[43]);
			member.prepare_time=Convert.ToInt32(vecLine[44]);
			member.reward_time=Convert.ToInt32(vecLine[45]);
			member.conclusion_delayed=Convert.ToInt32(vecLine[46]);
			member.start_time=Convert.ToInt32(vecLine[47]);
			member.end_time=Convert.ToInt32(vecLine[48]);
			member.teleport_id=Convert.ToInt32(vecLine[49]);
			member.teleport_location=Convert.ToInt32(vecLine[50]);
			member.teleporteffect=vecLine[51];
			member.exit_waypoint=Convert.ToInt32(vecLine[52]);
			member.defeat_exit_waypoint=Convert.ToInt32(vecLine[53]);
			member.monster_id=vecLine[54];
			member.dungeon_lua=vecLine[55];
			member.behaviac=vecLine[56];
			member.area_id=vecLine[57];
			member.monster_delay=Convert.ToInt32(vecLine[58]);
			member.second_verification=Convert.ToInt32(vecLine[59]);
			member.display_point=Convert.ToInt32(vecLine[60]);
			member.display_damage=Convert.ToInt32(vecLine[61]);
			member.activity_id=Convert.ToInt32(vecLine[62]);
			member.team_id=Convert.ToInt32(vecLine[63]);
			member.team_jump=Convert.ToInt32(vecLine[64]);
			member.canuse_blood=Convert.ToInt32(vecLine[65]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
