using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//任务总表配置数据类
public class QuestElement
{
	public int id;               	//数据索引	5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：珀希洛斯岛 15：科尔努斯 19：斯佩齐亚 24：序章
	public string comment;       	//任务备注	仅策划用
	public int npc_accept;       	//接任务npc	接任务的npcid，没有填写0
	public int waypoint_accept;  	//接任务地点	接任务的路点id，没有填写0
	public int group_quest;      	//线性任务组	同样大小的数字为同一组
	public li pre_quest;         	//前置任务	需要完成以下任务后才能接取对应任务
	public int numpl_quest;      	//人数要求	需要几个人才能获取任务
	public int recur_quest;      	//是否重复	0为否，1为是
	public int prohibit_abandon_quest;	//是否禁止放弃	0 可以放弃任务，1禁止放弃
	public int quest_type;       	//任务类型	1：主线 2：引导 3：占星 4：世界战场活跃度宝箱 5：精英怪 6：猎魔 11：积分商店（自动接） 12：藏宝图 13：活跃进度任务 14：限时任务 15：活跃度计量任务 16：支线任务 17：竞技场任务(3v3,5v5均可) 18：世界任务 19：世界战场 悬赏活动 20：世界战场 勇闯敌营  21：世界战场 抢夺物资 22 :活动普通任务 23：星耀王座
	public int renew_type;       	//刷新类型	0：不刷新，1：每日刷新，2：每周刷新，3：每月刷新
	public int quest_required_level;	//所需等级	仅程序用
	public li quest_next_id;     	//下一任务ID	
	public int is_auto_awarded;  	//自动领奖	1为是0为否
	public int quest_award;      	//任务奖励	填对应掉落表ID
	public int quest_level;      	//等级奖励	判定是否读取等级奖励
	public int quest_cycle;      	//环系数	任务奖励随环进度的提升（以10000为单位1）
	public li reward_preview;    	//奖励预览	填对应的道具ID, 通过|间隔
	public li reward_amount_preview;	//奖励数量预览	填对应奖励预览道具的数量, 通过|间隔
	public int chatmenu_accept_id;	//接任务字幕	chatmenu表的字幕ID
	public int chatmenu_complete_id;	//交任务字幕	chatmenu表的字幕ID
	public int quest_limit_time; 	//任务限制时间	单位秒
	public int quest_hide_type;  	//任务是否显示	0 不显示 1 显示
	public int quest_accept_qte_id;	//接任务qte_id	关联qte快速反应事件表
	public int quest_accept_cg_id;	//接任务cg_id	0为没有cg
	public int complete_quest_add_progress_type_;	//完成任务cg_id	自身完成后给被需求到的任务增加任务进度积分X（看目标类型23）
	public int dungeon_config_id;	//副本表id	这个任务必须在哪个副本触发条件进度
	public int scene_config_id;  	//场景表id	这个任务必须在哪个场景触发条件进度
	public int is_auto;          	//是否自动进行下一个任务	0：不自动 1：自动
	public int share_target_amount;	//	是否给同场景的小队成员共享任务目标计数 0 不共享 1  共享
	public int target_1_type;    	//第一个任务目标的类型	0为服务器给出 1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子类型任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务 18为活跃度 19 世界战场活跃度 20为怪物死亡，玩家任务完成 21为保护类型任务，击杀指定波次或者维持指定时长(取自任务时间限制)完成任务 22完成一次竞技场（3V3,5V5均可） 23 需求任意一个目标ID任务的积分 24加入公会 25世界频道发言 26装备血池 27添加好友 28积分商店购买物品 29宝石强化等级 30装备强化等级 31用精力制作任何一个物品 32穿戴装备 33单人爬塔到几层 34拍卖行出售多少商品 35拍卖行购买多少件商品 36装备洗练 37竞技场段位 38获得宠物 39宠物升级 40解锁n套装备 41装备升星 
	public int target_1_waypoint_id;	//第一个任务目标的寻路点	WayPoint_路点表ID,代表该任务目标的自动寻路点
	public li target_1_id;       	//第一个任务目标的相关ID	如果类型为0，是服务器给出 如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级； 如果类型是7，则填写副本ID（副本表）； 如果类型是8，则为活动的ID； 如果类型是9，则为0； 如果类型是10，则填写货币类型 如果类型是11，则填写限定的场景ID 如果类型是12，填写任务类型代号 如果类型是16，填写弹出的QTE ID         如果类型是23，填写的是任务ID
	public int target_1_amount_type;	//是否直接更新目标数量	0:累计数量,行为次数 (如每次计数加1) 1:更新数量,拥有数量 (如每次用当前拥有的数量去检测)
	public int target_1_amount;  	//第一个任务目标的数量	类型为6时，该列也填写目标等级。
	public int target_1_chatmenu;	//第一个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	public int target_1_cg_id;   	//目标剧情动画	完成第一个目标后，播放的剧情动画
	public int target_1_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	public int target_1_is_display;	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	public int target_2_type;    	//第二个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	public int target_2_waypoint_id;	//第二个任务目标的寻路点	WayPoint_路点表ID
	public li target_2_id;       	//第二个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	public int target_2_amount_type;	//	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	public int target_2_amount;  	//第二个任务目标的数量	类型为6时，该列也填写目标等级。
	public int target_2_chatmenu;	//第二个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	public int target_2_cg_id;   	//目标剧情动画	完成第2个目标后，播放的剧情动画
	public int target_2_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	public int target_2_is_display;	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	public int target_3_type;    	//第三个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	public int target_3_waypoint_id;	//第三个任务目标的寻路点	WayPoint_路点表ID
	public li target_3_id;       	//第三个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	public int target_3_amount_type;	//第三个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	public int target_3_amount;  	//第三个任务目标的数量	类型为6时，该列也填写目标等级。
	public int target_3_chatmenu;	//第三个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	public int target_3_cg_id;   	//目标剧情动画	完成第3个目标后，播放的剧情动画
	public int target_3_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	public int target_3_is_display;	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	public int target_4_type;    	//第四个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	public int target_4_waypoint_id;	//第四个任务目标的寻路点	WayPoint_路点表ID
	public li target_4_id;       	//第四个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	public int target_4_amount_type;	//第四个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	public int target_4_amount;  	//第四个任务目标的数量	类型为6时，该列也填写目标等级。
	public int target_4_chatmenu;	//第四个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	public int target_4_cg_id;   	//目标剧情动画	完成第4个目标后，播放的剧情动画
	public int target_4_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	public int target_4_is_display;	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	public int target_5_type;    	//第五个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	public int target_5_waypoint_id;	//第五个任务目标的寻路点	WayPoint_路点表ID
	public li target_5_id;       	//第五个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	public int target_5_amount_type;	//第五个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	public int target_5_amount;  	//第五个任务目标的数量	类型为6时，该列也填写目标等级。
	public int target_5_chatmenu;	//第五个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	public int target_5_cg_id;   	//目标剧情动画	完成第5个目标后，播放的剧情动画
	public int target_5_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	public int target_5_is_display;	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	public int string_title;     	//任务的标题文本	在任务追踪UI显示 StringQuest_任务文本表ID
	public int string_simple_description;	//任务的简单描述	在任务追踪UI显示 StringQuest_任务文本表ID
	public int string_detail_description;	//任务的详细描述	在任务UI显示 StringQuest_任务文本表ID
	public int string_target_1;  	//任务目标1	在任务追踪UI显示 StringQuest_任务文本表ID
	public int string_target_2;  	//任务目标2	StringQuest_任务文本表ID
	public int string_target_3;  	//任务目标3	StringQuest_任务文本表ID
	public int string_target_4;  	//任务目标4	StringQuest_任务文本表ID
	public int string_target_5;  	//任务目标5	StringQuest_任务文本表ID
	public string ServerScriptId;	//脚本	StringQuest_任务文本表ID

	public bool IsValidate = false;
	public QuestElement()
	{
		id = -1;
	}
};

//任务总表配置封装类
public class QuestTable
{

	private QuestTable()
	{
		m_mapElements = new Dictionary<int, QuestElement>();
		m_emptyItem = new QuestElement();
		m_vecAllElements = new List<QuestElement>();
	}
	private Dictionary<int, QuestElement> m_mapElements = null;
	private List<QuestElement>	m_vecAllElements = null;
	private QuestElement m_emptyItem = null;
	private static QuestTable sInstance = null;

	public static QuestTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new QuestTable();
			return sInstance;
		}
	}

	public QuestElement GetElement(int key)
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

  public List<QuestElement> GetAllElement(Predicate<QuestElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Quest.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Quest.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Quest.bin]未找到");
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
		if(vecLine.Count != 84)
		{
			Ex.Logger.Log("Quest.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Quest.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Quest.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="npc_accept"){Ex.Logger.Log("Quest.csv中字段[npc_accept]位置不对应"); return false; }
		if(vecLine[3]!="waypoint_accept"){Ex.Logger.Log("Quest.csv中字段[waypoint_accept]位置不对应"); return false; }
		if(vecLine[4]!="group_quest"){Ex.Logger.Log("Quest.csv中字段[group_quest]位置不对应"); return false; }
		if(vecLine[5]!="pre_quest"){Ex.Logger.Log("Quest.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[6]!="numpl_quest"){Ex.Logger.Log("Quest.csv中字段[numpl_quest]位置不对应"); return false; }
		if(vecLine[7]!="recur_quest"){Ex.Logger.Log("Quest.csv中字段[recur_quest]位置不对应"); return false; }
		if(vecLine[8]!="prohibit_abandon_quest"){Ex.Logger.Log("Quest.csv中字段[prohibit_abandon_quest]位置不对应"); return false; }
		if(vecLine[9]!="quest_type"){Ex.Logger.Log("Quest.csv中字段[quest_type]位置不对应"); return false; }
		if(vecLine[10]!="renew_type"){Ex.Logger.Log("Quest.csv中字段[renew_type]位置不对应"); return false; }
		if(vecLine[11]!="quest_required_level"){Ex.Logger.Log("Quest.csv中字段[quest_required_level]位置不对应"); return false; }
		if(vecLine[12]!="quest_next_id"){Ex.Logger.Log("Quest.csv中字段[quest_next_id]位置不对应"); return false; }
		if(vecLine[13]!="is_auto_awarded"){Ex.Logger.Log("Quest.csv中字段[is_auto_awarded]位置不对应"); return false; }
		if(vecLine[14]!="quest_award"){Ex.Logger.Log("Quest.csv中字段[quest_award]位置不对应"); return false; }
		if(vecLine[15]!="quest_level"){Ex.Logger.Log("Quest.csv中字段[quest_level]位置不对应"); return false; }
		if(vecLine[16]!="quest_cycle"){Ex.Logger.Log("Quest.csv中字段[quest_cycle]位置不对应"); return false; }
		if(vecLine[17]!="reward_preview"){Ex.Logger.Log("Quest.csv中字段[reward_preview]位置不对应"); return false; }
		if(vecLine[18]!="reward_amount_preview"){Ex.Logger.Log("Quest.csv中字段[reward_amount_preview]位置不对应"); return false; }
		if(vecLine[19]!="chatmenu_accept_id"){Ex.Logger.Log("Quest.csv中字段[chatmenu_accept_id]位置不对应"); return false; }
		if(vecLine[20]!="chatmenu_complete_id"){Ex.Logger.Log("Quest.csv中字段[chatmenu_complete_id]位置不对应"); return false; }
		if(vecLine[21]!="quest_limit_time"){Ex.Logger.Log("Quest.csv中字段[quest_limit_time]位置不对应"); return false; }
		if(vecLine[22]!="quest_hide_type"){Ex.Logger.Log("Quest.csv中字段[quest_hide_type]位置不对应"); return false; }
		if(vecLine[23]!="quest_accept_qte_id"){Ex.Logger.Log("Quest.csv中字段[quest_accept_qte_id]位置不对应"); return false; }
		if(vecLine[24]!="quest_accept_cg_id"){Ex.Logger.Log("Quest.csv中字段[quest_accept_cg_id]位置不对应"); return false; }
		if(vecLine[25]!="complete_quest_add_progress_type_"){Ex.Logger.Log("Quest.csv中字段[complete_quest_add_progress_type_]位置不对应"); return false; }
		if(vecLine[26]!="dungeon_config_id"){Ex.Logger.Log("Quest.csv中字段[dungeon_config_id]位置不对应"); return false; }
		if(vecLine[27]!="scene_config_id"){Ex.Logger.Log("Quest.csv中字段[scene_config_id]位置不对应"); return false; }
		if(vecLine[28]!="is_auto"){Ex.Logger.Log("Quest.csv中字段[is_auto]位置不对应"); return false; }
		if(vecLine[29]!="share_target_amount"){Ex.Logger.Log("Quest.csv中字段[share_target_amount]位置不对应"); return false; }
		if(vecLine[30]!="target_1_type"){Ex.Logger.Log("Quest.csv中字段[target_1_type]位置不对应"); return false; }
		if(vecLine[31]!="target_1_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_1_waypoint_id]位置不对应"); return false; }
		if(vecLine[32]!="target_1_id"){Ex.Logger.Log("Quest.csv中字段[target_1_id]位置不对应"); return false; }
		if(vecLine[33]!="target_1_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_1_amount_type]位置不对应"); return false; }
		if(vecLine[34]!="target_1_amount"){Ex.Logger.Log("Quest.csv中字段[target_1_amount]位置不对应"); return false; }
		if(vecLine[35]!="target_1_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_1_chatmenu]位置不对应"); return false; }
		if(vecLine[36]!="target_1_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_1_cg_id]位置不对应"); return false; }
		if(vecLine[37]!="target_1_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_1_headicon_display]位置不对应"); return false; }
		if(vecLine[38]!="target_1_is_display"){Ex.Logger.Log("Quest.csv中字段[target_1_is_display]位置不对应"); return false; }
		if(vecLine[39]!="target_2_type"){Ex.Logger.Log("Quest.csv中字段[target_2_type]位置不对应"); return false; }
		if(vecLine[40]!="target_2_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_2_waypoint_id]位置不对应"); return false; }
		if(vecLine[41]!="target_2_id"){Ex.Logger.Log("Quest.csv中字段[target_2_id]位置不对应"); return false; }
		if(vecLine[42]!="target_2_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_2_amount_type]位置不对应"); return false; }
		if(vecLine[43]!="target_2_amount"){Ex.Logger.Log("Quest.csv中字段[target_2_amount]位置不对应"); return false; }
		if(vecLine[44]!="target_2_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_2_chatmenu]位置不对应"); return false; }
		if(vecLine[45]!="target_2_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_2_cg_id]位置不对应"); return false; }
		if(vecLine[46]!="target_2_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_2_headicon_display]位置不对应"); return false; }
		if(vecLine[47]!="target_2_is_display"){Ex.Logger.Log("Quest.csv中字段[target_2_is_display]位置不对应"); return false; }
		if(vecLine[48]!="target_3_type"){Ex.Logger.Log("Quest.csv中字段[target_3_type]位置不对应"); return false; }
		if(vecLine[49]!="target_3_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_3_waypoint_id]位置不对应"); return false; }
		if(vecLine[50]!="target_3_id"){Ex.Logger.Log("Quest.csv中字段[target_3_id]位置不对应"); return false; }
		if(vecLine[51]!="target_3_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_3_amount_type]位置不对应"); return false; }
		if(vecLine[52]!="target_3_amount"){Ex.Logger.Log("Quest.csv中字段[target_3_amount]位置不对应"); return false; }
		if(vecLine[53]!="target_3_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_3_chatmenu]位置不对应"); return false; }
		if(vecLine[54]!="target_3_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_3_cg_id]位置不对应"); return false; }
		if(vecLine[55]!="target_3_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_3_headicon_display]位置不对应"); return false; }
		if(vecLine[56]!="target_3_is_display"){Ex.Logger.Log("Quest.csv中字段[target_3_is_display]位置不对应"); return false; }
		if(vecLine[57]!="target_4_type"){Ex.Logger.Log("Quest.csv中字段[target_4_type]位置不对应"); return false; }
		if(vecLine[58]!="target_4_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_4_waypoint_id]位置不对应"); return false; }
		if(vecLine[59]!="target_4_id"){Ex.Logger.Log("Quest.csv中字段[target_4_id]位置不对应"); return false; }
		if(vecLine[60]!="target_4_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_4_amount_type]位置不对应"); return false; }
		if(vecLine[61]!="target_4_amount"){Ex.Logger.Log("Quest.csv中字段[target_4_amount]位置不对应"); return false; }
		if(vecLine[62]!="target_4_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_4_chatmenu]位置不对应"); return false; }
		if(vecLine[63]!="target_4_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_4_cg_id]位置不对应"); return false; }
		if(vecLine[64]!="target_4_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_4_headicon_display]位置不对应"); return false; }
		if(vecLine[65]!="target_4_is_display"){Ex.Logger.Log("Quest.csv中字段[target_4_is_display]位置不对应"); return false; }
		if(vecLine[66]!="target_5_type"){Ex.Logger.Log("Quest.csv中字段[target_5_type]位置不对应"); return false; }
		if(vecLine[67]!="target_5_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_5_waypoint_id]位置不对应"); return false; }
		if(vecLine[68]!="target_5_id"){Ex.Logger.Log("Quest.csv中字段[target_5_id]位置不对应"); return false; }
		if(vecLine[69]!="target_5_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_5_amount_type]位置不对应"); return false; }
		if(vecLine[70]!="target_5_amount"){Ex.Logger.Log("Quest.csv中字段[target_5_amount]位置不对应"); return false; }
		if(vecLine[71]!="target_5_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_5_chatmenu]位置不对应"); return false; }
		if(vecLine[72]!="target_5_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_5_cg_id]位置不对应"); return false; }
		if(vecLine[73]!="target_5_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_5_headicon_display]位置不对应"); return false; }
		if(vecLine[74]!="target_5_is_display"){Ex.Logger.Log("Quest.csv中字段[target_5_is_display]位置不对应"); return false; }
		if(vecLine[75]!="string_title"){Ex.Logger.Log("Quest.csv中字段[string_title]位置不对应"); return false; }
		if(vecLine[76]!="string_simple_description"){Ex.Logger.Log("Quest.csv中字段[string_simple_description]位置不对应"); return false; }
		if(vecLine[77]!="string_detail_description"){Ex.Logger.Log("Quest.csv中字段[string_detail_description]位置不对应"); return false; }
		if(vecLine[78]!="string_target_1"){Ex.Logger.Log("Quest.csv中字段[string_target_1]位置不对应"); return false; }
		if(vecLine[79]!="string_target_2"){Ex.Logger.Log("Quest.csv中字段[string_target_2]位置不对应"); return false; }
		if(vecLine[80]!="string_target_3"){Ex.Logger.Log("Quest.csv中字段[string_target_3]位置不对应"); return false; }
		if(vecLine[81]!="string_target_4"){Ex.Logger.Log("Quest.csv中字段[string_target_4]位置不对应"); return false; }
		if(vecLine[82]!="string_target_5"){Ex.Logger.Log("Quest.csv中字段[string_target_5]位置不对应"); return false; }
		if(vecLine[83]!="ServerScriptId"){Ex.Logger.Log("Quest.csv中字段[ServerScriptId]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			QuestElement member = new QuestElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_accept );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_accept );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group_quest );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pre_quest);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.numpl_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recur_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.prohibit_abandon_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.renew_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_required_level );
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_next_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_auto_awarded );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_award );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_cycle );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_preview);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_amount_preview);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chatmenu_accept_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chatmenu_complete_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_limit_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_hide_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_accept_qte_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_accept_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.complete_quest_add_progress_type_ );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_config_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_config_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_auto );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.share_target_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_1_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_amount_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_chatmenu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_headicon_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_1_is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_2_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_amount_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_chatmenu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_headicon_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_2_is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_3_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_amount_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_chatmenu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_headicon_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_3_is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_4_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_amount_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_chatmenu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_headicon_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_4_is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_5_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_amount_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_chatmenu );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_cg_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_headicon_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_5_is_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_title );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_simple_description );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_detail_description );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_target_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_target_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_target_3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_target_4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_target_5 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ServerScriptId);

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
		if(vecLine.Count != 84)
		{
			Ex.Logger.Log("Quest.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Quest.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Quest.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="npc_accept"){Ex.Logger.Log("Quest.csv中字段[npc_accept]位置不对应"); return false; }
		if(vecLine[3]!="waypoint_accept"){Ex.Logger.Log("Quest.csv中字段[waypoint_accept]位置不对应"); return false; }
		if(vecLine[4]!="group_quest"){Ex.Logger.Log("Quest.csv中字段[group_quest]位置不对应"); return false; }
		if(vecLine[5]!="pre_quest"){Ex.Logger.Log("Quest.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[6]!="numpl_quest"){Ex.Logger.Log("Quest.csv中字段[numpl_quest]位置不对应"); return false; }
		if(vecLine[7]!="recur_quest"){Ex.Logger.Log("Quest.csv中字段[recur_quest]位置不对应"); return false; }
		if(vecLine[8]!="prohibit_abandon_quest"){Ex.Logger.Log("Quest.csv中字段[prohibit_abandon_quest]位置不对应"); return false; }
		if(vecLine[9]!="quest_type"){Ex.Logger.Log("Quest.csv中字段[quest_type]位置不对应"); return false; }
		if(vecLine[10]!="renew_type"){Ex.Logger.Log("Quest.csv中字段[renew_type]位置不对应"); return false; }
		if(vecLine[11]!="quest_required_level"){Ex.Logger.Log("Quest.csv中字段[quest_required_level]位置不对应"); return false; }
		if(vecLine[12]!="quest_next_id"){Ex.Logger.Log("Quest.csv中字段[quest_next_id]位置不对应"); return false; }
		if(vecLine[13]!="is_auto_awarded"){Ex.Logger.Log("Quest.csv中字段[is_auto_awarded]位置不对应"); return false; }
		if(vecLine[14]!="quest_award"){Ex.Logger.Log("Quest.csv中字段[quest_award]位置不对应"); return false; }
		if(vecLine[15]!="quest_level"){Ex.Logger.Log("Quest.csv中字段[quest_level]位置不对应"); return false; }
		if(vecLine[16]!="quest_cycle"){Ex.Logger.Log("Quest.csv中字段[quest_cycle]位置不对应"); return false; }
		if(vecLine[17]!="reward_preview"){Ex.Logger.Log("Quest.csv中字段[reward_preview]位置不对应"); return false; }
		if(vecLine[18]!="reward_amount_preview"){Ex.Logger.Log("Quest.csv中字段[reward_amount_preview]位置不对应"); return false; }
		if(vecLine[19]!="chatmenu_accept_id"){Ex.Logger.Log("Quest.csv中字段[chatmenu_accept_id]位置不对应"); return false; }
		if(vecLine[20]!="chatmenu_complete_id"){Ex.Logger.Log("Quest.csv中字段[chatmenu_complete_id]位置不对应"); return false; }
		if(vecLine[21]!="quest_limit_time"){Ex.Logger.Log("Quest.csv中字段[quest_limit_time]位置不对应"); return false; }
		if(vecLine[22]!="quest_hide_type"){Ex.Logger.Log("Quest.csv中字段[quest_hide_type]位置不对应"); return false; }
		if(vecLine[23]!="quest_accept_qte_id"){Ex.Logger.Log("Quest.csv中字段[quest_accept_qte_id]位置不对应"); return false; }
		if(vecLine[24]!="quest_accept_cg_id"){Ex.Logger.Log("Quest.csv中字段[quest_accept_cg_id]位置不对应"); return false; }
		if(vecLine[25]!="complete_quest_add_progress_type_"){Ex.Logger.Log("Quest.csv中字段[complete_quest_add_progress_type_]位置不对应"); return false; }
		if(vecLine[26]!="dungeon_config_id"){Ex.Logger.Log("Quest.csv中字段[dungeon_config_id]位置不对应"); return false; }
		if(vecLine[27]!="scene_config_id"){Ex.Logger.Log("Quest.csv中字段[scene_config_id]位置不对应"); return false; }
		if(vecLine[28]!="is_auto"){Ex.Logger.Log("Quest.csv中字段[is_auto]位置不对应"); return false; }
		if(vecLine[29]!="share_target_amount"){Ex.Logger.Log("Quest.csv中字段[share_target_amount]位置不对应"); return false; }
		if(vecLine[30]!="target_1_type"){Ex.Logger.Log("Quest.csv中字段[target_1_type]位置不对应"); return false; }
		if(vecLine[31]!="target_1_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_1_waypoint_id]位置不对应"); return false; }
		if(vecLine[32]!="target_1_id"){Ex.Logger.Log("Quest.csv中字段[target_1_id]位置不对应"); return false; }
		if(vecLine[33]!="target_1_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_1_amount_type]位置不对应"); return false; }
		if(vecLine[34]!="target_1_amount"){Ex.Logger.Log("Quest.csv中字段[target_1_amount]位置不对应"); return false; }
		if(vecLine[35]!="target_1_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_1_chatmenu]位置不对应"); return false; }
		if(vecLine[36]!="target_1_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_1_cg_id]位置不对应"); return false; }
		if(vecLine[37]!="target_1_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_1_headicon_display]位置不对应"); return false; }
		if(vecLine[38]!="target_1_is_display"){Ex.Logger.Log("Quest.csv中字段[target_1_is_display]位置不对应"); return false; }
		if(vecLine[39]!="target_2_type"){Ex.Logger.Log("Quest.csv中字段[target_2_type]位置不对应"); return false; }
		if(vecLine[40]!="target_2_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_2_waypoint_id]位置不对应"); return false; }
		if(vecLine[41]!="target_2_id"){Ex.Logger.Log("Quest.csv中字段[target_2_id]位置不对应"); return false; }
		if(vecLine[42]!="target_2_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_2_amount_type]位置不对应"); return false; }
		if(vecLine[43]!="target_2_amount"){Ex.Logger.Log("Quest.csv中字段[target_2_amount]位置不对应"); return false; }
		if(vecLine[44]!="target_2_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_2_chatmenu]位置不对应"); return false; }
		if(vecLine[45]!="target_2_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_2_cg_id]位置不对应"); return false; }
		if(vecLine[46]!="target_2_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_2_headicon_display]位置不对应"); return false; }
		if(vecLine[47]!="target_2_is_display"){Ex.Logger.Log("Quest.csv中字段[target_2_is_display]位置不对应"); return false; }
		if(vecLine[48]!="target_3_type"){Ex.Logger.Log("Quest.csv中字段[target_3_type]位置不对应"); return false; }
		if(vecLine[49]!="target_3_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_3_waypoint_id]位置不对应"); return false; }
		if(vecLine[50]!="target_3_id"){Ex.Logger.Log("Quest.csv中字段[target_3_id]位置不对应"); return false; }
		if(vecLine[51]!="target_3_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_3_amount_type]位置不对应"); return false; }
		if(vecLine[52]!="target_3_amount"){Ex.Logger.Log("Quest.csv中字段[target_3_amount]位置不对应"); return false; }
		if(vecLine[53]!="target_3_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_3_chatmenu]位置不对应"); return false; }
		if(vecLine[54]!="target_3_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_3_cg_id]位置不对应"); return false; }
		if(vecLine[55]!="target_3_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_3_headicon_display]位置不对应"); return false; }
		if(vecLine[56]!="target_3_is_display"){Ex.Logger.Log("Quest.csv中字段[target_3_is_display]位置不对应"); return false; }
		if(vecLine[57]!="target_4_type"){Ex.Logger.Log("Quest.csv中字段[target_4_type]位置不对应"); return false; }
		if(vecLine[58]!="target_4_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_4_waypoint_id]位置不对应"); return false; }
		if(vecLine[59]!="target_4_id"){Ex.Logger.Log("Quest.csv中字段[target_4_id]位置不对应"); return false; }
		if(vecLine[60]!="target_4_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_4_amount_type]位置不对应"); return false; }
		if(vecLine[61]!="target_4_amount"){Ex.Logger.Log("Quest.csv中字段[target_4_amount]位置不对应"); return false; }
		if(vecLine[62]!="target_4_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_4_chatmenu]位置不对应"); return false; }
		if(vecLine[63]!="target_4_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_4_cg_id]位置不对应"); return false; }
		if(vecLine[64]!="target_4_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_4_headicon_display]位置不对应"); return false; }
		if(vecLine[65]!="target_4_is_display"){Ex.Logger.Log("Quest.csv中字段[target_4_is_display]位置不对应"); return false; }
		if(vecLine[66]!="target_5_type"){Ex.Logger.Log("Quest.csv中字段[target_5_type]位置不对应"); return false; }
		if(vecLine[67]!="target_5_waypoint_id"){Ex.Logger.Log("Quest.csv中字段[target_5_waypoint_id]位置不对应"); return false; }
		if(vecLine[68]!="target_5_id"){Ex.Logger.Log("Quest.csv中字段[target_5_id]位置不对应"); return false; }
		if(vecLine[69]!="target_5_amount_type"){Ex.Logger.Log("Quest.csv中字段[target_5_amount_type]位置不对应"); return false; }
		if(vecLine[70]!="target_5_amount"){Ex.Logger.Log("Quest.csv中字段[target_5_amount]位置不对应"); return false; }
		if(vecLine[71]!="target_5_chatmenu"){Ex.Logger.Log("Quest.csv中字段[target_5_chatmenu]位置不对应"); return false; }
		if(vecLine[72]!="target_5_cg_id"){Ex.Logger.Log("Quest.csv中字段[target_5_cg_id]位置不对应"); return false; }
		if(vecLine[73]!="target_5_headicon_display"){Ex.Logger.Log("Quest.csv中字段[target_5_headicon_display]位置不对应"); return false; }
		if(vecLine[74]!="target_5_is_display"){Ex.Logger.Log("Quest.csv中字段[target_5_is_display]位置不对应"); return false; }
		if(vecLine[75]!="string_title"){Ex.Logger.Log("Quest.csv中字段[string_title]位置不对应"); return false; }
		if(vecLine[76]!="string_simple_description"){Ex.Logger.Log("Quest.csv中字段[string_simple_description]位置不对应"); return false; }
		if(vecLine[77]!="string_detail_description"){Ex.Logger.Log("Quest.csv中字段[string_detail_description]位置不对应"); return false; }
		if(vecLine[78]!="string_target_1"){Ex.Logger.Log("Quest.csv中字段[string_target_1]位置不对应"); return false; }
		if(vecLine[79]!="string_target_2"){Ex.Logger.Log("Quest.csv中字段[string_target_2]位置不对应"); return false; }
		if(vecLine[80]!="string_target_3"){Ex.Logger.Log("Quest.csv中字段[string_target_3]位置不对应"); return false; }
		if(vecLine[81]!="string_target_4"){Ex.Logger.Log("Quest.csv中字段[string_target_4]位置不对应"); return false; }
		if(vecLine[82]!="string_target_5"){Ex.Logger.Log("Quest.csv中字段[string_target_5]位置不对应"); return false; }
		if(vecLine[83]!="ServerScriptId"){Ex.Logger.Log("Quest.csv中字段[ServerScriptId]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)84)
			{
				return false;
			}
			QuestElement member = new QuestElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.npc_accept=Convert.ToInt32(vecLine[2]);
			member.waypoint_accept=Convert.ToInt32(vecLine[3]);
			member.group_quest=Convert.ToInt32(vecLine[4]);
			member.pre_quest=vecLine[5];
			member.numpl_quest=Convert.ToInt32(vecLine[6]);
			member.recur_quest=Convert.ToInt32(vecLine[7]);
			member.prohibit_abandon_quest=Convert.ToInt32(vecLine[8]);
			member.quest_type=Convert.ToInt32(vecLine[9]);
			member.renew_type=Convert.ToInt32(vecLine[10]);
			member.quest_required_level=Convert.ToInt32(vecLine[11]);
			member.quest_next_id=vecLine[12];
			member.is_auto_awarded=Convert.ToInt32(vecLine[13]);
			member.quest_award=Convert.ToInt32(vecLine[14]);
			member.quest_level=Convert.ToInt32(vecLine[15]);
			member.quest_cycle=Convert.ToInt32(vecLine[16]);
			member.reward_preview=vecLine[17];
			member.reward_amount_preview=vecLine[18];
			member.chatmenu_accept_id=Convert.ToInt32(vecLine[19]);
			member.chatmenu_complete_id=Convert.ToInt32(vecLine[20]);
			member.quest_limit_time=Convert.ToInt32(vecLine[21]);
			member.quest_hide_type=Convert.ToInt32(vecLine[22]);
			member.quest_accept_qte_id=Convert.ToInt32(vecLine[23]);
			member.quest_accept_cg_id=Convert.ToInt32(vecLine[24]);
			member.complete_quest_add_progress_type_=Convert.ToInt32(vecLine[25]);
			member.dungeon_config_id=Convert.ToInt32(vecLine[26]);
			member.scene_config_id=Convert.ToInt32(vecLine[27]);
			member.is_auto=Convert.ToInt32(vecLine[28]);
			member.share_target_amount=Convert.ToInt32(vecLine[29]);
			member.target_1_type=Convert.ToInt32(vecLine[30]);
			member.target_1_waypoint_id=Convert.ToInt32(vecLine[31]);
			member.target_1_id=vecLine[32];
			member.target_1_amount_type=Convert.ToInt32(vecLine[33]);
			member.target_1_amount=Convert.ToInt32(vecLine[34]);
			member.target_1_chatmenu=Convert.ToInt32(vecLine[35]);
			member.target_1_cg_id=Convert.ToInt32(vecLine[36]);
			member.target_1_headicon_display=Convert.ToInt32(vecLine[37]);
			member.target_1_is_display=Convert.ToInt32(vecLine[38]);
			member.target_2_type=Convert.ToInt32(vecLine[39]);
			member.target_2_waypoint_id=Convert.ToInt32(vecLine[40]);
			member.target_2_id=vecLine[41];
			member.target_2_amount_type=Convert.ToInt32(vecLine[42]);
			member.target_2_amount=Convert.ToInt32(vecLine[43]);
			member.target_2_chatmenu=Convert.ToInt32(vecLine[44]);
			member.target_2_cg_id=Convert.ToInt32(vecLine[45]);
			member.target_2_headicon_display=Convert.ToInt32(vecLine[46]);
			member.target_2_is_display=Convert.ToInt32(vecLine[47]);
			member.target_3_type=Convert.ToInt32(vecLine[48]);
			member.target_3_waypoint_id=Convert.ToInt32(vecLine[49]);
			member.target_3_id=vecLine[50];
			member.target_3_amount_type=Convert.ToInt32(vecLine[51]);
			member.target_3_amount=Convert.ToInt32(vecLine[52]);
			member.target_3_chatmenu=Convert.ToInt32(vecLine[53]);
			member.target_3_cg_id=Convert.ToInt32(vecLine[54]);
			member.target_3_headicon_display=Convert.ToInt32(vecLine[55]);
			member.target_3_is_display=Convert.ToInt32(vecLine[56]);
			member.target_4_type=Convert.ToInt32(vecLine[57]);
			member.target_4_waypoint_id=Convert.ToInt32(vecLine[58]);
			member.target_4_id=vecLine[59];
			member.target_4_amount_type=Convert.ToInt32(vecLine[60]);
			member.target_4_amount=Convert.ToInt32(vecLine[61]);
			member.target_4_chatmenu=Convert.ToInt32(vecLine[62]);
			member.target_4_cg_id=Convert.ToInt32(vecLine[63]);
			member.target_4_headicon_display=Convert.ToInt32(vecLine[64]);
			member.target_4_is_display=Convert.ToInt32(vecLine[65]);
			member.target_5_type=Convert.ToInt32(vecLine[66]);
			member.target_5_waypoint_id=Convert.ToInt32(vecLine[67]);
			member.target_5_id=vecLine[68];
			member.target_5_amount_type=Convert.ToInt32(vecLine[69]);
			member.target_5_amount=Convert.ToInt32(vecLine[70]);
			member.target_5_chatmenu=Convert.ToInt32(vecLine[71]);
			member.target_5_cg_id=Convert.ToInt32(vecLine[72]);
			member.target_5_headicon_display=Convert.ToInt32(vecLine[73]);
			member.target_5_is_display=Convert.ToInt32(vecLine[74]);
			member.string_title=Convert.ToInt32(vecLine[75]);
			member.string_simple_description=Convert.ToInt32(vecLine[76]);
			member.string_detail_description=Convert.ToInt32(vecLine[77]);
			member.string_target_1=Convert.ToInt32(vecLine[78]);
			member.string_target_2=Convert.ToInt32(vecLine[79]);
			member.string_target_3=Convert.ToInt32(vecLine[80]);
			member.string_target_4=Convert.ToInt32(vecLine[81]);
			member.string_target_5=Convert.ToInt32(vecLine[82]);
			member.ServerScriptId=vecLine[83];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
