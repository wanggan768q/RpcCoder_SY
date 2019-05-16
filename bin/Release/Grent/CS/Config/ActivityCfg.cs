using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//活动表配置数据类
public class ActivityElement
{
	public int id;               	//主键id	活动id
	public string comment;       	//注释	
	public int tab_id;           	//标签编号	活动所属标签
	public li bi_id;             	//bi统计用类型	bi类型|对应类型名
	public int weight;           	//权重	标签列表内的显示权重
	public li weekly;            	//周历提醒	不填写则不会出现在日历中 不用展示每天都开放的活动 1天最大显示4个活动
	public int name_id;          	//名称id	活动名称id
	public int describe_id;      	//描述文本id	
	public int race_id;          	//是否相关种族	是否需要判断玩家种族来显示对话按钮,0表示否，1表示是
	public string main_icon;     	//主图名称	选中页签图标
	public string sub_icon;      	//副图名称	未选中页签图标
	public int function_on;      	//是否开启	0 不开启 1 开启
	public int recommend;        	//是否开启推荐	0 不开启 1 开启
	public int call;             	//支持开启弹窗提醒	0 不开启 1 开启（全天类型1活动不需要开启弹窗提醒）
	public int call_tm;          	//时间	活动开启前多久进行通知-0不用通知
	public int call_str;         	//提示文本	StringUi_界面文本表配置
	public int push;             	//支持开启推送提醒	0 不开启 1 开启
	public int push_tm;          	//时间	活动开启前多久进行通知-0不用通知
	public int push_str;         	//提示文本	StringUi_界面文本表配置
	public int marquee;          	//活动开启前是否有跑马灯提醒	0 没有 1 有
	public li marquee_tm;        	//时间	活动开启前多久进行通知-0不用通知
	public int marquee_str;      	//开始预告提示文本	StringUi_界面文本表配置
	public int marquee_end;      	//活动结束前是否有跑马灯提醒	0 没有 1 有
	public li marquee_end_tm;    	//时间	活动开启前多久进行通知-0不用通知
	public int marquee_end_str;  	//结束预告提示文本	StringUi_界面文本表配置
	public int open_type;        	//时间类型	1 全天开放 2 限时开放 3 跨天持续开放 4 月循环开放 5 固定日期开放 
	public li open_in_week;      	//开放周次	限时开放时使用 （例）2|4 3跨天：1|3，周一和周三开，持续时间为2160分钟即36小时，也就是周一9：00开，持续36小时后关闭，跨天不会重置该活动 4月循环开：2|6，第二周的周六开启 5固定日期开放：26，每个月26号开启
	public li open_in_day;       	//开放时间	限时开放时使用 默认59秒结束 （例 00:00 - 23:59） 0|0|23|59
	public int duration;         	//持续时间（分钟）	填写分钟
	public int level_min;        	//最低等级限制	
	public int player_min;       	//最低组队玩家数量	
	public int active_value;     	//活跃度奖励	完成每环任务获得的活跃度
	public int rounds_max;       	//轮次数上限	该活动每天可做的任务总数=环×轮
	public int times_max;        	//环次数上限	在HUD任务区域显示对应的环数
	public li drop_rounds;       	//每轮掉落奖励	计算方式|掉落包id （掉落计算：0概率；1权值）
	public li drop_times;        	//每环掉落奖励	计算方式|掉落包id （掉落计算：0概率；1权值）
	public li drop_display;      	//奖励显示	
	public int friendship_add;   	//友好度增加	好友组队进行活动增加的友好度值（猎魔等活动以一轮为一次完成单位）
	public li scene_id;          	//场景id	活动涉及的所有场景id
	public int quest_id;         	//记录任务id	记录活跃度的任务id
	public int huoyue;           	//活跃度	单个任务活跃度（服务器暂时没用到）
	public int open_tm;          	//时间	活动开启前多久进行通知-0不用通知
	public int waypoint;         	//地点	自动寻路路点id
	public int creature_id;      	//活动NPC	
	public li item_list;         	//道具id	点击活动使用的道具id
	public li item_dec;          	//说明id	道具需要显示说明文字的id（需要和道具id对应） StringUi
	public ls item_icon;         	//道具背景图	快捷使用界面对应道具的背景图

	public bool IsValidate = false;
	public ActivityElement()
	{
		id = -1;
	}
};

//活动表配置封装类
public class ActivityTable
{

	private ActivityTable()
	{
		m_mapElements = new Dictionary<int, ActivityElement>();
		m_emptyItem = new ActivityElement();
		m_vecAllElements = new List<ActivityElement>();
	}
	private Dictionary<int, ActivityElement> m_mapElements = null;
	private List<ActivityElement>	m_vecAllElements = null;
	private ActivityElement m_emptyItem = null;
	private static ActivityTable sInstance = null;

	public static ActivityTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ActivityTable();
			return sInstance;
		}
	}

	public ActivityElement GetElement(int key)
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

  public List<ActivityElement> GetAllElement(Predicate<ActivityElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Activity.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Activity.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Activity.bin]未找到");
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
			Ex.Logger.Log("Activity.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Activity.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Activity.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="tab_id"){Ex.Logger.Log("Activity.csv中字段[tab_id]位置不对应"); return false; }
		if(vecLine[3]!="bi_id"){Ex.Logger.Log("Activity.csv中字段[bi_id]位置不对应"); return false; }
		if(vecLine[4]!="weight"){Ex.Logger.Log("Activity.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[5]!="weekly"){Ex.Logger.Log("Activity.csv中字段[weekly]位置不对应"); return false; }
		if(vecLine[6]!="name_id"){Ex.Logger.Log("Activity.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[7]!="describe_id"){Ex.Logger.Log("Activity.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[8]!="race_id"){Ex.Logger.Log("Activity.csv中字段[race_id]位置不对应"); return false; }
		if(vecLine[9]!="main_icon"){Ex.Logger.Log("Activity.csv中字段[main_icon]位置不对应"); return false; }
		if(vecLine[10]!="sub_icon"){Ex.Logger.Log("Activity.csv中字段[sub_icon]位置不对应"); return false; }
		if(vecLine[11]!="function_on"){Ex.Logger.Log("Activity.csv中字段[function_on]位置不对应"); return false; }
		if(vecLine[12]!="recommend"){Ex.Logger.Log("Activity.csv中字段[recommend]位置不对应"); return false; }
		if(vecLine[13]!="call"){Ex.Logger.Log("Activity.csv中字段[call]位置不对应"); return false; }
		if(vecLine[14]!="call_tm"){Ex.Logger.Log("Activity.csv中字段[call_tm]位置不对应"); return false; }
		if(vecLine[15]!="call_str"){Ex.Logger.Log("Activity.csv中字段[call_str]位置不对应"); return false; }
		if(vecLine[16]!="push"){Ex.Logger.Log("Activity.csv中字段[push]位置不对应"); return false; }
		if(vecLine[17]!="push_tm"){Ex.Logger.Log("Activity.csv中字段[push_tm]位置不对应"); return false; }
		if(vecLine[18]!="push_str"){Ex.Logger.Log("Activity.csv中字段[push_str]位置不对应"); return false; }
		if(vecLine[19]!="marquee"){Ex.Logger.Log("Activity.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[20]!="marquee_tm"){Ex.Logger.Log("Activity.csv中字段[marquee_tm]位置不对应"); return false; }
		if(vecLine[21]!="marquee_str"){Ex.Logger.Log("Activity.csv中字段[marquee_str]位置不对应"); return false; }
		if(vecLine[22]!="marquee_end"){Ex.Logger.Log("Activity.csv中字段[marquee_end]位置不对应"); return false; }
		if(vecLine[23]!="marquee_end_tm"){Ex.Logger.Log("Activity.csv中字段[marquee_end_tm]位置不对应"); return false; }
		if(vecLine[24]!="marquee_end_str"){Ex.Logger.Log("Activity.csv中字段[marquee_end_str]位置不对应"); return false; }
		if(vecLine[25]!="open_type"){Ex.Logger.Log("Activity.csv中字段[open_type]位置不对应"); return false; }
		if(vecLine[26]!="open_in_week"){Ex.Logger.Log("Activity.csv中字段[open_in_week]位置不对应"); return false; }
		if(vecLine[27]!="open_in_day"){Ex.Logger.Log("Activity.csv中字段[open_in_day]位置不对应"); return false; }
		if(vecLine[28]!="duration"){Ex.Logger.Log("Activity.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[29]!="level_min"){Ex.Logger.Log("Activity.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[30]!="player_min"){Ex.Logger.Log("Activity.csv中字段[player_min]位置不对应"); return false; }
		if(vecLine[31]!="active_value"){Ex.Logger.Log("Activity.csv中字段[active_value]位置不对应"); return false; }
		if(vecLine[32]!="rounds_max"){Ex.Logger.Log("Activity.csv中字段[rounds_max]位置不对应"); return false; }
		if(vecLine[33]!="times_max"){Ex.Logger.Log("Activity.csv中字段[times_max]位置不对应"); return false; }
		if(vecLine[34]!="drop_rounds"){Ex.Logger.Log("Activity.csv中字段[drop_rounds]位置不对应"); return false; }
		if(vecLine[35]!="drop_times"){Ex.Logger.Log("Activity.csv中字段[drop_times]位置不对应"); return false; }
		if(vecLine[36]!="drop_display"){Ex.Logger.Log("Activity.csv中字段[drop_display]位置不对应"); return false; }
		if(vecLine[37]!="friendship_add"){Ex.Logger.Log("Activity.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[38]!="scene_id"){Ex.Logger.Log("Activity.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[39]!="quest_id"){Ex.Logger.Log("Activity.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[40]!="huoyue"){Ex.Logger.Log("Activity.csv中字段[huoyue]位置不对应"); return false; }
		if(vecLine[41]!="open_tm"){Ex.Logger.Log("Activity.csv中字段[open_tm]位置不对应"); return false; }
		if(vecLine[42]!="waypoint"){Ex.Logger.Log("Activity.csv中字段[waypoint]位置不对应"); return false; }
		if(vecLine[43]!="creature_id"){Ex.Logger.Log("Activity.csv中字段[creature_id]位置不对应"); return false; }
		if(vecLine[44]!="item_list"){Ex.Logger.Log("Activity.csv中字段[item_list]位置不对应"); return false; }
		if(vecLine[45]!="item_dec"){Ex.Logger.Log("Activity.csv中字段[item_dec]位置不对应"); return false; }
		if(vecLine[46]!="item_icon"){Ex.Logger.Log("Activity.csv中字段[item_icon]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ActivityElement member = new ActivityElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tab_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.bi_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.weight );
			readPos += GameAssist.ReadString( binContent, readPos, out member.weekly);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.main_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sub_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.function_on );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recommend );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.call );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.call_tm );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.call_str );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.push );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.push_tm );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.push_str );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee );
			readPos += GameAssist.ReadString( binContent, readPos, out member.marquee_tm);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee_str );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee_end );
			readPos += GameAssist.ReadString( binContent, readPos, out member.marquee_end_tm);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee_end_str );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.open_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.open_in_week);
			readPos += GameAssist.ReadString( binContent, readPos, out member.open_in_day);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.player_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.active_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rounds_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.times_max );
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_rounds);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_times);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_display);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.friendship_add );
			readPos += GameAssist.ReadString( binContent, readPos, out member.scene_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.huoyue );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.open_tm );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_list);
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_dec);
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_icon);

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
			Ex.Logger.Log("Activity.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Activity.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Activity.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="tab_id"){Ex.Logger.Log("Activity.csv中字段[tab_id]位置不对应"); return false; }
		if(vecLine[3]!="bi_id"){Ex.Logger.Log("Activity.csv中字段[bi_id]位置不对应"); return false; }
		if(vecLine[4]!="weight"){Ex.Logger.Log("Activity.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[5]!="weekly"){Ex.Logger.Log("Activity.csv中字段[weekly]位置不对应"); return false; }
		if(vecLine[6]!="name_id"){Ex.Logger.Log("Activity.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[7]!="describe_id"){Ex.Logger.Log("Activity.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[8]!="race_id"){Ex.Logger.Log("Activity.csv中字段[race_id]位置不对应"); return false; }
		if(vecLine[9]!="main_icon"){Ex.Logger.Log("Activity.csv中字段[main_icon]位置不对应"); return false; }
		if(vecLine[10]!="sub_icon"){Ex.Logger.Log("Activity.csv中字段[sub_icon]位置不对应"); return false; }
		if(vecLine[11]!="function_on"){Ex.Logger.Log("Activity.csv中字段[function_on]位置不对应"); return false; }
		if(vecLine[12]!="recommend"){Ex.Logger.Log("Activity.csv中字段[recommend]位置不对应"); return false; }
		if(vecLine[13]!="call"){Ex.Logger.Log("Activity.csv中字段[call]位置不对应"); return false; }
		if(vecLine[14]!="call_tm"){Ex.Logger.Log("Activity.csv中字段[call_tm]位置不对应"); return false; }
		if(vecLine[15]!="call_str"){Ex.Logger.Log("Activity.csv中字段[call_str]位置不对应"); return false; }
		if(vecLine[16]!="push"){Ex.Logger.Log("Activity.csv中字段[push]位置不对应"); return false; }
		if(vecLine[17]!="push_tm"){Ex.Logger.Log("Activity.csv中字段[push_tm]位置不对应"); return false; }
		if(vecLine[18]!="push_str"){Ex.Logger.Log("Activity.csv中字段[push_str]位置不对应"); return false; }
		if(vecLine[19]!="marquee"){Ex.Logger.Log("Activity.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[20]!="marquee_tm"){Ex.Logger.Log("Activity.csv中字段[marquee_tm]位置不对应"); return false; }
		if(vecLine[21]!="marquee_str"){Ex.Logger.Log("Activity.csv中字段[marquee_str]位置不对应"); return false; }
		if(vecLine[22]!="marquee_end"){Ex.Logger.Log("Activity.csv中字段[marquee_end]位置不对应"); return false; }
		if(vecLine[23]!="marquee_end_tm"){Ex.Logger.Log("Activity.csv中字段[marquee_end_tm]位置不对应"); return false; }
		if(vecLine[24]!="marquee_end_str"){Ex.Logger.Log("Activity.csv中字段[marquee_end_str]位置不对应"); return false; }
		if(vecLine[25]!="open_type"){Ex.Logger.Log("Activity.csv中字段[open_type]位置不对应"); return false; }
		if(vecLine[26]!="open_in_week"){Ex.Logger.Log("Activity.csv中字段[open_in_week]位置不对应"); return false; }
		if(vecLine[27]!="open_in_day"){Ex.Logger.Log("Activity.csv中字段[open_in_day]位置不对应"); return false; }
		if(vecLine[28]!="duration"){Ex.Logger.Log("Activity.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[29]!="level_min"){Ex.Logger.Log("Activity.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[30]!="player_min"){Ex.Logger.Log("Activity.csv中字段[player_min]位置不对应"); return false; }
		if(vecLine[31]!="active_value"){Ex.Logger.Log("Activity.csv中字段[active_value]位置不对应"); return false; }
		if(vecLine[32]!="rounds_max"){Ex.Logger.Log("Activity.csv中字段[rounds_max]位置不对应"); return false; }
		if(vecLine[33]!="times_max"){Ex.Logger.Log("Activity.csv中字段[times_max]位置不对应"); return false; }
		if(vecLine[34]!="drop_rounds"){Ex.Logger.Log("Activity.csv中字段[drop_rounds]位置不对应"); return false; }
		if(vecLine[35]!="drop_times"){Ex.Logger.Log("Activity.csv中字段[drop_times]位置不对应"); return false; }
		if(vecLine[36]!="drop_display"){Ex.Logger.Log("Activity.csv中字段[drop_display]位置不对应"); return false; }
		if(vecLine[37]!="friendship_add"){Ex.Logger.Log("Activity.csv中字段[friendship_add]位置不对应"); return false; }
		if(vecLine[38]!="scene_id"){Ex.Logger.Log("Activity.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[39]!="quest_id"){Ex.Logger.Log("Activity.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[40]!="huoyue"){Ex.Logger.Log("Activity.csv中字段[huoyue]位置不对应"); return false; }
		if(vecLine[41]!="open_tm"){Ex.Logger.Log("Activity.csv中字段[open_tm]位置不对应"); return false; }
		if(vecLine[42]!="waypoint"){Ex.Logger.Log("Activity.csv中字段[waypoint]位置不对应"); return false; }
		if(vecLine[43]!="creature_id"){Ex.Logger.Log("Activity.csv中字段[creature_id]位置不对应"); return false; }
		if(vecLine[44]!="item_list"){Ex.Logger.Log("Activity.csv中字段[item_list]位置不对应"); return false; }
		if(vecLine[45]!="item_dec"){Ex.Logger.Log("Activity.csv中字段[item_dec]位置不对应"); return false; }
		if(vecLine[46]!="item_icon"){Ex.Logger.Log("Activity.csv中字段[item_icon]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)47)
			{
				return false;
			}
			ActivityElement member = new ActivityElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.tab_id=Convert.ToInt32(vecLine[2]);
			member.bi_id=vecLine[3];
			member.weight=Convert.ToInt32(vecLine[4]);
			member.weekly=vecLine[5];
			member.name_id=Convert.ToInt32(vecLine[6]);
			member.describe_id=Convert.ToInt32(vecLine[7]);
			member.race_id=Convert.ToInt32(vecLine[8]);
			member.main_icon=vecLine[9];
			member.sub_icon=vecLine[10];
			member.function_on=Convert.ToInt32(vecLine[11]);
			member.recommend=Convert.ToInt32(vecLine[12]);
			member.call=Convert.ToInt32(vecLine[13]);
			member.call_tm=Convert.ToInt32(vecLine[14]);
			member.call_str=Convert.ToInt32(vecLine[15]);
			member.push=Convert.ToInt32(vecLine[16]);
			member.push_tm=Convert.ToInt32(vecLine[17]);
			member.push_str=Convert.ToInt32(vecLine[18]);
			member.marquee=Convert.ToInt32(vecLine[19]);
			member.marquee_tm=vecLine[20];
			member.marquee_str=Convert.ToInt32(vecLine[21]);
			member.marquee_end=Convert.ToInt32(vecLine[22]);
			member.marquee_end_tm=vecLine[23];
			member.marquee_end_str=Convert.ToInt32(vecLine[24]);
			member.open_type=Convert.ToInt32(vecLine[25]);
			member.open_in_week=vecLine[26];
			member.open_in_day=vecLine[27];
			member.duration=Convert.ToInt32(vecLine[28]);
			member.level_min=Convert.ToInt32(vecLine[29]);
			member.player_min=Convert.ToInt32(vecLine[30]);
			member.active_value=Convert.ToInt32(vecLine[31]);
			member.rounds_max=Convert.ToInt32(vecLine[32]);
			member.times_max=Convert.ToInt32(vecLine[33]);
			member.drop_rounds=vecLine[34];
			member.drop_times=vecLine[35];
			member.drop_display=vecLine[36];
			member.friendship_add=Convert.ToInt32(vecLine[37]);
			member.scene_id=vecLine[38];
			member.quest_id=Convert.ToInt32(vecLine[39]);
			member.huoyue=Convert.ToInt32(vecLine[40]);
			member.open_tm=Convert.ToInt32(vecLine[41]);
			member.waypoint=Convert.ToInt32(vecLine[42]);
			member.creature_id=Convert.ToInt32(vecLine[43]);
			member.item_list=vecLine[44];
			member.item_dec=vecLine[45];
			member.item_icon=vecLine[46];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
