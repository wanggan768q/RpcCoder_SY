#ifndef __QUEST_CONFIG_H
#define __QUEST_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//任务总表配置数据结构
struct QuestElement
{
	friend class QuestTable;
	int id;                      	//数据索引	5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：珀希洛斯岛 15：科尔努斯 19：斯佩齐亚 24：序章
	string comment;              	//任务备注	仅策划用
	int npc_accept;              	//接任务npc	接任务的npcid，没有填写0
	int waypoint_accept;         	//接任务地点	接任务的路点id，没有填写0
	int group_quest;             	//线性任务组	同样大小的数字为同一组
	vector<int> pre_quest;       	//前置任务	需要完成以下任务后才能接取对应任务
	int numpl_quest;             	//人数要求	需要几个人才能获取任务
	int recur_quest;             	//是否重复	0为否，1为是
	int prohibit_abandon_quest;  	//是否禁止放弃	0 可以放弃任务，1禁止放弃
	int quest_type;              	//任务类型	1：主线 2：引导 3：占星 4：世界战场活跃度宝箱 5：精英怪 6：猎魔 11：积分商店（自动接） 12：藏宝图 13：活跃进度任务 14：限时任务 15：活跃度计量任务 16：支线任务 17：竞技场任务(3v3,5v5均可) 18：世界任务 19：世界战场 悬赏活动 20：世界战场 勇闯敌营  21：世界战场 抢夺物资 22 :活动普通任务 23：星耀王座
	int renew_type;              	//刷新类型	0：不刷新，1：每日刷新，2：每周刷新，3：每月刷新
	int quest_required_level;    	//所需等级	仅程序用
	vector<int> quest_next_id;   	//下一任务ID	
	int is_auto_awarded;         	//自动领奖	1为是0为否
	int quest_award;             	//任务奖励	填对应掉落表ID
	int quest_level;             	//等级奖励	判定是否读取等级奖励
	int quest_cycle;             	//环系数	任务奖励随环进度的提升（以10000为单位1）
	vector<int> reward_preview;  	//奖励预览	填对应的道具ID, 通过|间隔
	vector<int> reward_amount_preview;	//奖励数量预览	填对应奖励预览道具的数量, 通过|间隔
	int chatmenu_accept_id;      	//接任务字幕	chatmenu表的字幕ID
	int chatmenu_complete_id;    	//交任务字幕	chatmenu表的字幕ID
	int quest_limit_time;        	//任务限制时间	单位秒
	int quest_hide_type;         	//任务是否显示	0 不显示 1 显示
	int quest_accept_qte_id;     	//接任务qte_id	关联qte快速反应事件表
	int quest_accept_cg_id;      	//接任务cg_id	0为没有cg
	int complete_quest_add_progress_type_;	//完成任务cg_id	自身完成后给被需求到的任务增加任务进度积分X（看目标类型23）
	int dungeon_config_id;       	//副本表id	这个任务必须在哪个副本触发条件进度
	int scene_config_id;         	//场景表id	这个任务必须在哪个场景触发条件进度
	int is_auto;                 	//是否自动进行下一个任务	0：不自动 1：自动
	int share_target_amount;     	//	是否给同场景的小队成员共享任务目标计数 0 不共享 1  共享
	int target_1_type;           	//第一个任务目标的类型	0为服务器给出 1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子类型任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务 18为活跃度 19 世界战场活跃度 20为怪物死亡，玩家任务完成 21为保护类型任务，击杀指定波次或者维持指定时长(取自任务时间限制)完成任务 22完成一次竞技场（3V3,5V5均可） 23 需求任意一个目标ID任务的积分 24加入公会 25世界频道发言 26装备血池 27添加好友 28积分商店购买物品 29宝石强化等级 30装备强化等级 31用精力制作任何一个物品 32穿戴装备 33单人爬塔到几层 34拍卖行出售多少商品 35拍卖行购买多少件商品 36装备洗练 37竞技场段位 38获得宠物 39宠物升级 40解锁n套装备 41装备升星 
	int target_1_waypoint_id;    	//第一个任务目标的寻路点	WayPoint_路点表ID,代表该任务目标的自动寻路点
	vector<int> target_1_id;     	//第一个任务目标的相关ID	如果类型为0，是服务器给出 如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级； 如果类型是7，则填写副本ID（副本表）； 如果类型是8，则为活动的ID； 如果类型是9，则为0； 如果类型是10，则填写货币类型 如果类型是11，则填写限定的场景ID 如果类型是12，填写任务类型代号 如果类型是16，填写弹出的QTE ID         如果类型是23，填写的是任务ID
	int target_1_amount_type;    	//是否直接更新目标数量	0:累计数量,行为次数 (如每次计数加1) 1:更新数量,拥有数量 (如每次用当前拥有的数量去检测)
	int target_1_amount;         	//第一个任务目标的数量	类型为6时，该列也填写目标等级。
	int target_1_chatmenu;       	//第一个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	int target_1_cg_id;          	//目标剧情动画	完成第一个目标后，播放的剧情动画
	int target_1_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	int target_1_is_display;     	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	int target_2_type;           	//第二个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	int target_2_waypoint_id;    	//第二个任务目标的寻路点	WayPoint_路点表ID
	vector<int> target_2_id;     	//第二个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	int target_2_amount_type;    	//	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	int target_2_amount;         	//第二个任务目标的数量	类型为6时，该列也填写目标等级。
	int target_2_chatmenu;       	//第二个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	int target_2_cg_id;          	//目标剧情动画	完成第2个目标后，播放的剧情动画
	int target_2_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	int target_2_is_display;     	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	int target_3_type;           	//第三个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	int target_3_waypoint_id;    	//第三个任务目标的寻路点	WayPoint_路点表ID
	vector<int> target_3_id;     	//第三个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	int target_3_amount_type;    	//第三个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	int target_3_amount;         	//第三个任务目标的数量	类型为6时，该列也填写目标等级。
	int target_3_chatmenu;       	//第三个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	int target_3_cg_id;          	//目标剧情动画	完成第3个目标后，播放的剧情动画
	int target_3_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	int target_3_is_display;     	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	int target_4_type;           	//第四个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	int target_4_waypoint_id;    	//第四个任务目标的寻路点	WayPoint_路点表ID
	vector<int> target_4_id;     	//第四个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	int target_4_amount_type;    	//第四个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	int target_4_amount;         	//第四个任务目标的数量	类型为6时，该列也填写目标等级。
	int target_4_chatmenu;       	//第四个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	int target_4_cg_id;          	//目标剧情动画	完成第4个目标后，播放的剧情动画
	int target_4_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	int target_4_is_display;     	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	int target_5_type;           	//第五个任务目标的类型	1为杀怪类型； 2为与obj互动类型； 3为对话类型； 4为事件类型； 5为提交类型； 6为升级类型； 7为通关副本； 8为限时活动； 9为高倍奖励判断； 10为积累货币型积分商店判断； 11为杀玩家 12为完成一个子任务 13为阵营战等级相关的积分商店判断 14为提交道具类型任务 15为到达指定地点 16为QTE任务 17为限时类任务
	int target_5_waypoint_id;    	//第五个任务目标的寻路点	WayPoint_路点表ID
	vector<int> target_5_id;     	//第五个任务目标的相关ID	如果类型为1，则是怪物的ID； 如果类型为2；则是obj的ID； 如果类型为3，则是NPC的 ID； 如果是4，则为事件ID；（未实现） 如果类型是5，则为需要提交的itemID； 如果类型是6，则为要提升的等级
	int target_5_amount_type;    	//第五个任务目标的数量	0:累计数量 (如每次计数加1) 1:更新数量 (如每次用当前拥有的数量去检测)
	int target_5_amount;         	//第五个任务目标的数量	类型为6时，该列也填写目标等级。
	int target_5_chatmenu;       	//第五个任务目标的字幕	0：不触发字幕； 其余数字为字幕的ID
	int target_5_cg_id;          	//目标剧情动画	完成第5个目标后，播放的剧情动画
	int target_5_headicon_display;	//目标是否显示头标	0：不显示头标 1：显示头标
	int target_5_is_display;     	//是否显示在追踪面板	1：显示在追踪面板 0：不显示在追踪面板
	int string_title;            	//任务的标题文本	在任务追踪UI显示 StringQuest_任务文本表ID
	int string_simple_description;	//任务的简单描述	在任务追踪UI显示 StringQuest_任务文本表ID
	int string_detail_description;	//任务的详细描述	在任务UI显示 StringQuest_任务文本表ID
	int string_target_1;         	//任务目标1	在任务追踪UI显示 StringQuest_任务文本表ID
	int string_target_2;         	//任务目标2	StringQuest_任务文本表ID
	int string_target_3;         	//任务目标3	StringQuest_任务文本表ID
	int string_target_4;         	//任务目标4	StringQuest_任务文本表ID
	int string_target_5;         	//任务目标5	StringQuest_任务文本表ID
	string ServerScriptId;       	//脚本	StringQuest_任务文本表ID

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
	QuestElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//任务总表配置封装类
class QuestTable
{
	friend class TableData;
private:
	QuestTable(){}
	~QuestTable(){}
	map<int, QuestElement>	m_mapElements;
	vector<QuestElement>	m_vecAllElements;
	QuestElement m_emptyItem;
public:
	static QuestTable& Instance()
	{
		static QuestTable sInstance;
		return sInstance;
	}

	QuestElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QuestElement>&	GetAllElement()
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
		if( LoadConfigContent("Quest.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Quest.bin", strTableContent ) )
		{
			printf_message("配置文件[Quest.bin]未找到");
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
		if(vecLine.size() != 84)
		{
			printf_message("Quest.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Quest.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Quest.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="npc_accept"){printf_message("Quest.csv中字段[npc_accept]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="waypoint_accept"){printf_message("Quest.csv中字段[waypoint_accept]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="group_quest"){printf_message("Quest.csv中字段[group_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="pre_quest"){printf_message("Quest.csv中字段[pre_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="numpl_quest"){printf_message("Quest.csv中字段[numpl_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="recur_quest"){printf_message("Quest.csv中字段[recur_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="prohibit_abandon_quest"){printf_message("Quest.csv中字段[prohibit_abandon_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="quest_type"){printf_message("Quest.csv中字段[quest_type]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="renew_type"){printf_message("Quest.csv中字段[renew_type]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="quest_required_level"){printf_message("Quest.csv中字段[quest_required_level]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="quest_next_id"){printf_message("Quest.csv中字段[quest_next_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="is_auto_awarded"){printf_message("Quest.csv中字段[is_auto_awarded]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="quest_award"){printf_message("Quest.csv中字段[quest_award]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="quest_level"){printf_message("Quest.csv中字段[quest_level]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="quest_cycle"){printf_message("Quest.csv中字段[quest_cycle]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="reward_preview"){printf_message("Quest.csv中字段[reward_preview]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="reward_amount_preview"){printf_message("Quest.csv中字段[reward_amount_preview]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="chatmenu_accept_id"){printf_message("Quest.csv中字段[chatmenu_accept_id]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="chatmenu_complete_id"){printf_message("Quest.csv中字段[chatmenu_complete_id]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="quest_limit_time"){printf_message("Quest.csv中字段[quest_limit_time]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="quest_hide_type"){printf_message("Quest.csv中字段[quest_hide_type]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="quest_accept_qte_id"){printf_message("Quest.csv中字段[quest_accept_qte_id]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="quest_accept_cg_id"){printf_message("Quest.csv中字段[quest_accept_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="complete_quest_add_progress_type_"){printf_message("Quest.csv中字段[complete_quest_add_progress_type_]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="dungeon_config_id"){printf_message("Quest.csv中字段[dungeon_config_id]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="scene_config_id"){printf_message("Quest.csv中字段[scene_config_id]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="is_auto"){printf_message("Quest.csv中字段[is_auto]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="share_target_amount"){printf_message("Quest.csv中字段[share_target_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="target_1_type"){printf_message("Quest.csv中字段[target_1_type]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="target_1_waypoint_id"){printf_message("Quest.csv中字段[target_1_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="target_1_id"){printf_message("Quest.csv中字段[target_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="target_1_amount_type"){printf_message("Quest.csv中字段[target_1_amount_type]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="target_1_amount"){printf_message("Quest.csv中字段[target_1_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="target_1_chatmenu"){printf_message("Quest.csv中字段[target_1_chatmenu]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="target_1_cg_id"){printf_message("Quest.csv中字段[target_1_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="target_1_headicon_display"){printf_message("Quest.csv中字段[target_1_headicon_display]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="target_1_is_display"){printf_message("Quest.csv中字段[target_1_is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="target_2_type"){printf_message("Quest.csv中字段[target_2_type]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="target_2_waypoint_id"){printf_message("Quest.csv中字段[target_2_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="target_2_id"){printf_message("Quest.csv中字段[target_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="target_2_amount_type"){printf_message("Quest.csv中字段[target_2_amount_type]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="target_2_amount"){printf_message("Quest.csv中字段[target_2_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="target_2_chatmenu"){printf_message("Quest.csv中字段[target_2_chatmenu]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="target_2_cg_id"){printf_message("Quest.csv中字段[target_2_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="target_2_headicon_display"){printf_message("Quest.csv中字段[target_2_headicon_display]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="target_2_is_display"){printf_message("Quest.csv中字段[target_2_is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="target_3_type"){printf_message("Quest.csv中字段[target_3_type]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="target_3_waypoint_id"){printf_message("Quest.csv中字段[target_3_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="target_3_id"){printf_message("Quest.csv中字段[target_3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="target_3_amount_type"){printf_message("Quest.csv中字段[target_3_amount_type]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="target_3_amount"){printf_message("Quest.csv中字段[target_3_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="target_3_chatmenu"){printf_message("Quest.csv中字段[target_3_chatmenu]位置不对应 ");assert(false); return false; }
		if(vecLine[54]!="target_3_cg_id"){printf_message("Quest.csv中字段[target_3_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[55]!="target_3_headicon_display"){printf_message("Quest.csv中字段[target_3_headicon_display]位置不对应 ");assert(false); return false; }
		if(vecLine[56]!="target_3_is_display"){printf_message("Quest.csv中字段[target_3_is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[57]!="target_4_type"){printf_message("Quest.csv中字段[target_4_type]位置不对应 ");assert(false); return false; }
		if(vecLine[58]!="target_4_waypoint_id"){printf_message("Quest.csv中字段[target_4_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[59]!="target_4_id"){printf_message("Quest.csv中字段[target_4_id]位置不对应 ");assert(false); return false; }
		if(vecLine[60]!="target_4_amount_type"){printf_message("Quest.csv中字段[target_4_amount_type]位置不对应 ");assert(false); return false; }
		if(vecLine[61]!="target_4_amount"){printf_message("Quest.csv中字段[target_4_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[62]!="target_4_chatmenu"){printf_message("Quest.csv中字段[target_4_chatmenu]位置不对应 ");assert(false); return false; }
		if(vecLine[63]!="target_4_cg_id"){printf_message("Quest.csv中字段[target_4_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[64]!="target_4_headicon_display"){printf_message("Quest.csv中字段[target_4_headicon_display]位置不对应 ");assert(false); return false; }
		if(vecLine[65]!="target_4_is_display"){printf_message("Quest.csv中字段[target_4_is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[66]!="target_5_type"){printf_message("Quest.csv中字段[target_5_type]位置不对应 ");assert(false); return false; }
		if(vecLine[67]!="target_5_waypoint_id"){printf_message("Quest.csv中字段[target_5_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[68]!="target_5_id"){printf_message("Quest.csv中字段[target_5_id]位置不对应 ");assert(false); return false; }
		if(vecLine[69]!="target_5_amount_type"){printf_message("Quest.csv中字段[target_5_amount_type]位置不对应 ");assert(false); return false; }
		if(vecLine[70]!="target_5_amount"){printf_message("Quest.csv中字段[target_5_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[71]!="target_5_chatmenu"){printf_message("Quest.csv中字段[target_5_chatmenu]位置不对应 ");assert(false); return false; }
		if(vecLine[72]!="target_5_cg_id"){printf_message("Quest.csv中字段[target_5_cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[73]!="target_5_headicon_display"){printf_message("Quest.csv中字段[target_5_headicon_display]位置不对应 ");assert(false); return false; }
		if(vecLine[74]!="target_5_is_display"){printf_message("Quest.csv中字段[target_5_is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[75]!="string_title"){printf_message("Quest.csv中字段[string_title]位置不对应 ");assert(false); return false; }
		if(vecLine[76]!="string_simple_description"){printf_message("Quest.csv中字段[string_simple_description]位置不对应 ");assert(false); return false; }
		if(vecLine[77]!="string_detail_description"){printf_message("Quest.csv中字段[string_detail_description]位置不对应 ");assert(false); return false; }
		if(vecLine[78]!="string_target_1"){printf_message("Quest.csv中字段[string_target_1]位置不对应 ");assert(false); return false; }
		if(vecLine[79]!="string_target_2"){printf_message("Quest.csv中字段[string_target_2]位置不对应 ");assert(false); return false; }
		if(vecLine[80]!="string_target_3"){printf_message("Quest.csv中字段[string_target_3]位置不对应 ");assert(false); return false; }
		if(vecLine[81]!="string_target_4"){printf_message("Quest.csv中字段[string_target_4]位置不对应 ");assert(false); return false; }
		if(vecLine[82]!="string_target_5"){printf_message("Quest.csv中字段[string_target_5]位置不对应 ");assert(false); return false; }
		if(vecLine[83]!="ServerScriptId"){printf_message("Quest.csv中字段[ServerScriptId]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)84)
			{
				assert(false);
				return false;
			}
			QuestElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.npc_accept=(int)atoi(vecLine[2].c_str());
			member.waypoint_accept=(int)atoi(vecLine[3].c_str());
			member.group_quest=(int)atoi(vecLine[4].c_str());
			member.numpl_quest=(int)atoi(vecLine[6].c_str());
			member.recur_quest=(int)atoi(vecLine[7].c_str());
			member.prohibit_abandon_quest=(int)atoi(vecLine[8].c_str());
			member.quest_type=(int)atoi(vecLine[9].c_str());
			member.renew_type=(int)atoi(vecLine[10].c_str());
			member.quest_required_level=(int)atoi(vecLine[11].c_str());
			member.is_auto_awarded=(int)atoi(vecLine[13].c_str());
			member.quest_award=(int)atoi(vecLine[14].c_str());
			member.quest_level=(int)atoi(vecLine[15].c_str());
			member.quest_cycle=(int)atoi(vecLine[16].c_str());
			member.chatmenu_accept_id=(int)atoi(vecLine[19].c_str());
			member.chatmenu_complete_id=(int)atoi(vecLine[20].c_str());
			member.quest_limit_time=(int)atoi(vecLine[21].c_str());
			member.quest_hide_type=(int)atoi(vecLine[22].c_str());
			member.quest_accept_qte_id=(int)atoi(vecLine[23].c_str());
			member.quest_accept_cg_id=(int)atoi(vecLine[24].c_str());
			member.complete_quest_add_progress_type_=(int)atoi(vecLine[25].c_str());
			member.dungeon_config_id=(int)atoi(vecLine[26].c_str());
			member.scene_config_id=(int)atoi(vecLine[27].c_str());
			member.is_auto=(int)atoi(vecLine[28].c_str());
			member.share_target_amount=(int)atoi(vecLine[29].c_str());
			member.target_1_type=(int)atoi(vecLine[30].c_str());
			member.target_1_waypoint_id=(int)atoi(vecLine[31].c_str());
			member.target_1_amount_type=(int)atoi(vecLine[33].c_str());
			member.target_1_amount=(int)atoi(vecLine[34].c_str());
			member.target_1_chatmenu=(int)atoi(vecLine[35].c_str());
			member.target_1_cg_id=(int)atoi(vecLine[36].c_str());
			member.target_1_headicon_display=(int)atoi(vecLine[37].c_str());
			member.target_1_is_display=(int)atoi(vecLine[38].c_str());
			member.target_2_type=(int)atoi(vecLine[39].c_str());
			member.target_2_waypoint_id=(int)atoi(vecLine[40].c_str());
			member.target_2_amount_type=(int)atoi(vecLine[42].c_str());
			member.target_2_amount=(int)atoi(vecLine[43].c_str());
			member.target_2_chatmenu=(int)atoi(vecLine[44].c_str());
			member.target_2_cg_id=(int)atoi(vecLine[45].c_str());
			member.target_2_headicon_display=(int)atoi(vecLine[46].c_str());
			member.target_2_is_display=(int)atoi(vecLine[47].c_str());
			member.target_3_type=(int)atoi(vecLine[48].c_str());
			member.target_3_waypoint_id=(int)atoi(vecLine[49].c_str());
			member.target_3_amount_type=(int)atoi(vecLine[51].c_str());
			member.target_3_amount=(int)atoi(vecLine[52].c_str());
			member.target_3_chatmenu=(int)atoi(vecLine[53].c_str());
			member.target_3_cg_id=(int)atoi(vecLine[54].c_str());
			member.target_3_headicon_display=(int)atoi(vecLine[55].c_str());
			member.target_3_is_display=(int)atoi(vecLine[56].c_str());
			member.target_4_type=(int)atoi(vecLine[57].c_str());
			member.target_4_waypoint_id=(int)atoi(vecLine[58].c_str());
			member.target_4_amount_type=(int)atoi(vecLine[60].c_str());
			member.target_4_amount=(int)atoi(vecLine[61].c_str());
			member.target_4_chatmenu=(int)atoi(vecLine[62].c_str());
			member.target_4_cg_id=(int)atoi(vecLine[63].c_str());
			member.target_4_headicon_display=(int)atoi(vecLine[64].c_str());
			member.target_4_is_display=(int)atoi(vecLine[65].c_str());
			member.target_5_type=(int)atoi(vecLine[66].c_str());
			member.target_5_waypoint_id=(int)atoi(vecLine[67].c_str());
			member.target_5_amount_type=(int)atoi(vecLine[69].c_str());
			member.target_5_amount=(int)atoi(vecLine[70].c_str());
			member.target_5_chatmenu=(int)atoi(vecLine[71].c_str());
			member.target_5_cg_id=(int)atoi(vecLine[72].c_str());
			member.target_5_headicon_display=(int)atoi(vecLine[73].c_str());
			member.target_5_is_display=(int)atoi(vecLine[74].c_str());
			member.string_title=(int)atoi(vecLine[75].c_str());
			member.string_simple_description=(int)atoi(vecLine[76].c_str());
			member.string_detail_description=(int)atoi(vecLine[77].c_str());
			member.string_target_1=(int)atoi(vecLine[78].c_str());
			member.string_target_2=(int)atoi(vecLine[79].c_str());
			member.string_target_3=(int)atoi(vecLine[80].c_str());
			member.string_target_4=(int)atoi(vecLine[81].c_str());
			member.string_target_5=(int)atoi(vecLine[82].c_str());
			member.ServerScriptId=vecLine[83];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
