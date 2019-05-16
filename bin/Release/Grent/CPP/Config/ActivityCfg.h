#ifndef __ACTIVITY_CONFIG_H
#define __ACTIVITY_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//活动表配置数据结构
struct ActivityElement
{
	friend class ActivityTable;
	int id;                      	//主键id	活动id
	string comment;              	//注释	
	int tab_id;                  	//标签编号	活动所属标签
	vector<int> bi_id;           	//bi统计用类型	bi类型|对应类型名
	int weight;                  	//权重	标签列表内的显示权重
	vector<int> weekly;          	//周历提醒	不填写则不会出现在日历中 不用展示每天都开放的活动 1天最大显示4个活动
	int name_id;                 	//名称id	活动名称id
	int describe_id;             	//描述文本id	
	int race_id;                 	//是否相关种族	是否需要判断玩家种族来显示对话按钮,0表示否，1表示是
	string main_icon;            	//主图名称	选中页签图标
	string sub_icon;             	//副图名称	未选中页签图标
	int function_on;             	//是否开启	0 不开启 1 开启
	int recommend;               	//是否开启推荐	0 不开启 1 开启
	int call;                    	//支持开启弹窗提醒	0 不开启 1 开启（全天类型1活动不需要开启弹窗提醒）
	int call_tm;                 	//时间	活动开启前多久进行通知-0不用通知
	int call_str;                	//提示文本	StringUi_界面文本表配置
	int push;                    	//支持开启推送提醒	0 不开启 1 开启
	int push_tm;                 	//时间	活动开启前多久进行通知-0不用通知
	int push_str;                	//提示文本	StringUi_界面文本表配置
	int marquee;                 	//活动开启前是否有跑马灯提醒	0 没有 1 有
	vector<int> marquee_tm;      	//时间	活动开启前多久进行通知-0不用通知
	int marquee_str;             	//开始预告提示文本	StringUi_界面文本表配置
	int marquee_end;             	//活动结束前是否有跑马灯提醒	0 没有 1 有
	vector<int> marquee_end_tm;  	//时间	活动开启前多久进行通知-0不用通知
	int marquee_end_str;         	//结束预告提示文本	StringUi_界面文本表配置
	int open_type;               	//时间类型	1 全天开放 2 限时开放 3 跨天持续开放 4 月循环开放 5 固定日期开放 
	vector<int> open_in_week;    	//开放周次	限时开放时使用 （例）2|4 3跨天：1|3，周一和周三开，持续时间为2160分钟即36小时，也就是周一9：00开，持续36小时后关闭，跨天不会重置该活动 4月循环开：2|6，第二周的周六开启 5固定日期开放：26，每个月26号开启
	vector<int> open_in_day;     	//开放时间	限时开放时使用 默认59秒结束 （例 00:00 - 23:59） 0|0|23|59
	int duration;                	//持续时间（分钟）	填写分钟
	int level_min;               	//最低等级限制	
	int player_min;              	//最低组队玩家数量	
	int active_value;            	//活跃度奖励	完成每环任务获得的活跃度
	int rounds_max;              	//轮次数上限	该活动每天可做的任务总数=环×轮
	int times_max;               	//环次数上限	在HUD任务区域显示对应的环数
	vector<int> drop_rounds;     	//每轮掉落奖励	计算方式|掉落包id （掉落计算：0概率；1权值）
	vector<int> drop_times;      	//每环掉落奖励	计算方式|掉落包id （掉落计算：0概率；1权值）
	vector<int> drop_display;    	//奖励显示	
	int friendship_add;          	//友好度增加	好友组队进行活动增加的友好度值（猎魔等活动以一轮为一次完成单位）
	vector<int> scene_id;        	//场景id	活动涉及的所有场景id
	int quest_id;                	//记录任务id	记录活跃度的任务id
	int huoyue;                  	//活跃度	单个任务活跃度（服务器暂时没用到）
	int open_tm;                 	//时间	活动开启前多久进行通知-0不用通知
	int waypoint;                	//地点	自动寻路路点id
	int creature_id;             	//活动NPC	
	vector<int> item_list;       	//道具id	点击活动使用的道具id
	vector<int> item_dec;        	//说明id	道具需要显示说明文字的id（需要和道具id对应） StringUi
	vector<string> item_icon;    	//道具背景图	快捷使用界面对应道具的背景图

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
	ActivityElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//活动表配置封装类
class ActivityTable
{
	friend class TableData;
private:
	ActivityTable(){}
	~ActivityTable(){}
	map<int, ActivityElement>	m_mapElements;
	vector<ActivityElement>	m_vecAllElements;
	ActivityElement m_emptyItem;
public:
	static ActivityTable& Instance()
	{
		static ActivityTable sInstance;
		return sInstance;
	}

	ActivityElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ActivityElement>&	GetAllElement()
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
		if( LoadConfigContent("Activity.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Activity.bin", strTableContent ) )
		{
			printf_message("配置文件[Activity.bin]未找到");
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
		if(vecLine.size() != 47)
		{
			printf_message("Activity.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Activity.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Activity.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="tab_id"){printf_message("Activity.csv中字段[tab_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="bi_id"){printf_message("Activity.csv中字段[bi_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="weight"){printf_message("Activity.csv中字段[weight]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="weekly"){printf_message("Activity.csv中字段[weekly]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="name_id"){printf_message("Activity.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="describe_id"){printf_message("Activity.csv中字段[describe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="race_id"){printf_message("Activity.csv中字段[race_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="main_icon"){printf_message("Activity.csv中字段[main_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="sub_icon"){printf_message("Activity.csv中字段[sub_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="function_on"){printf_message("Activity.csv中字段[function_on]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="recommend"){printf_message("Activity.csv中字段[recommend]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="call"){printf_message("Activity.csv中字段[call]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="call_tm"){printf_message("Activity.csv中字段[call_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="call_str"){printf_message("Activity.csv中字段[call_str]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="push"){printf_message("Activity.csv中字段[push]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="push_tm"){printf_message("Activity.csv中字段[push_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="push_str"){printf_message("Activity.csv中字段[push_str]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="marquee"){printf_message("Activity.csv中字段[marquee]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="marquee_tm"){printf_message("Activity.csv中字段[marquee_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="marquee_str"){printf_message("Activity.csv中字段[marquee_str]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="marquee_end"){printf_message("Activity.csv中字段[marquee_end]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="marquee_end_tm"){printf_message("Activity.csv中字段[marquee_end_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="marquee_end_str"){printf_message("Activity.csv中字段[marquee_end_str]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="open_type"){printf_message("Activity.csv中字段[open_type]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="open_in_week"){printf_message("Activity.csv中字段[open_in_week]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="open_in_day"){printf_message("Activity.csv中字段[open_in_day]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="duration"){printf_message("Activity.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="level_min"){printf_message("Activity.csv中字段[level_min]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="player_min"){printf_message("Activity.csv中字段[player_min]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="active_value"){printf_message("Activity.csv中字段[active_value]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="rounds_max"){printf_message("Activity.csv中字段[rounds_max]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="times_max"){printf_message("Activity.csv中字段[times_max]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="drop_rounds"){printf_message("Activity.csv中字段[drop_rounds]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="drop_times"){printf_message("Activity.csv中字段[drop_times]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="drop_display"){printf_message("Activity.csv中字段[drop_display]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="friendship_add"){printf_message("Activity.csv中字段[friendship_add]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="scene_id"){printf_message("Activity.csv中字段[scene_id]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="quest_id"){printf_message("Activity.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="huoyue"){printf_message("Activity.csv中字段[huoyue]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="open_tm"){printf_message("Activity.csv中字段[open_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="waypoint"){printf_message("Activity.csv中字段[waypoint]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="creature_id"){printf_message("Activity.csv中字段[creature_id]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="item_list"){printf_message("Activity.csv中字段[item_list]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="item_dec"){printf_message("Activity.csv中字段[item_dec]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="item_icon"){printf_message("Activity.csv中字段[item_icon]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)47)
			{
				assert(false);
				return false;
			}
			ActivityElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.tab_id=(int)atoi(vecLine[2].c_str());
			member.weight=(int)atoi(vecLine[4].c_str());
			member.name_id=(int)atoi(vecLine[6].c_str());
			member.describe_id=(int)atoi(vecLine[7].c_str());
			member.race_id=(int)atoi(vecLine[8].c_str());
			member.main_icon=vecLine[9];
			member.sub_icon=vecLine[10];
			member.function_on=(int)atoi(vecLine[11].c_str());
			member.recommend=(int)atoi(vecLine[12].c_str());
			member.call=(int)atoi(vecLine[13].c_str());
			member.call_tm=(int)atoi(vecLine[14].c_str());
			member.call_str=(int)atoi(vecLine[15].c_str());
			member.push=(int)atoi(vecLine[16].c_str());
			member.push_tm=(int)atoi(vecLine[17].c_str());
			member.push_str=(int)atoi(vecLine[18].c_str());
			member.marquee=(int)atoi(vecLine[19].c_str());
			member.marquee_str=(int)atoi(vecLine[21].c_str());
			member.marquee_end=(int)atoi(vecLine[22].c_str());
			member.marquee_end_str=(int)atoi(vecLine[24].c_str());
			member.open_type=(int)atoi(vecLine[25].c_str());
			member.duration=(int)atoi(vecLine[28].c_str());
			member.level_min=(int)atoi(vecLine[29].c_str());
			member.player_min=(int)atoi(vecLine[30].c_str());
			member.active_value=(int)atoi(vecLine[31].c_str());
			member.rounds_max=(int)atoi(vecLine[32].c_str());
			member.times_max=(int)atoi(vecLine[33].c_str());
			member.friendship_add=(int)atoi(vecLine[37].c_str());
			member.quest_id=(int)atoi(vecLine[39].c_str());
			member.huoyue=(int)atoi(vecLine[40].c_str());
			member.open_tm=(int)atoi(vecLine[41].c_str());
			member.waypoint=(int)atoi(vecLine[42].c_str());
			member.creature_id=(int)atoi(vecLine[43].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
