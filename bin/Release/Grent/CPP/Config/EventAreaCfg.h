#ifndef __EVENTAREA_CONFIG_H
#define __EVENTAREA_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//事件区域表配置数据结构
struct EventAreaElement
{
	friend class EventAreaTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	vector<int> location_point_list;	//该区域的位置集合	此处填写4个路点位置，该事件区域通过这4个路点的位置来生成，该4个路点必须在同一个地图内,如果是圆，只填一个中心点
	int area_type;               	//区域类型	0:多边形（最多六边，必须凸多边形）1:圆
	float radius;                	//圆的半径	
	int quest_id;                	//绑定任务id	所需的任务ID，只有当玩家拥有该任务以及符合下面的quest_step的条件时，该事件才会起作用。如果为0则代表没有任务限制
	int quest_state;             	//任务状态	0：代表没有限制 1：为任务接受后，完成前可触发 2：为任务完成后可触发 
	int switchType;              	//开关类型	1：场景加载时就打开 2：默认关闭
	int event_type;              	//出生类型	1为副本型：该类型事件只能触发一次，副本重置后会消除该限制 2队伍型：该类型事件可反复触发，且只能由队长触发 3. 单人型：该类型事件可反复触发，没有队长和队员的限制 
	vector<int> entry_buff_add;  	//进入时附加的buff	进入该区域后给玩家上的buff和持续时间 buffID|buffDuration
	int leave_buff_remove;       	//离开时删除的buff	离开该区域后删除玩家身上的buff buffID
	int entry_mirror_id;         	//进入该区域后是否自动切换到镜像的ID	0为不切换
	int leave_mirror_id;         	//离开该区域后是否脱离镜像（如果之前在镜像中）	1为脱离 2为不脱离 0为缺省
	int cg_id;                   	//需要播放的cg动画	需要播放的cg动画
	string music;                	//所改变的背景音乐	所改变的背景音乐
	string teleport_id;          	//所传送到的路点	所传送到的路点
	int is_wall;                 	//是否为物理墙（火墙），玩家无法穿过该区域	1为火墙 2为不是火墙
	string script;               	//脚本路径	脚本路径
	vector<int> quest_accept;    	//可接任务	区域内可能触发的任务,0为没有

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
	EventAreaElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//事件区域表配置封装类
class EventAreaTable
{
	friend class TableData;
private:
	EventAreaTable(){}
	~EventAreaTable(){}
	map<int, EventAreaElement>	m_mapElements;
	vector<EventAreaElement>	m_vecAllElements;
	EventAreaElement m_emptyItem;
public:
	static EventAreaTable& Instance()
	{
		static EventAreaTable sInstance;
		return sInstance;
	}

	EventAreaElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EventAreaElement>&	GetAllElement()
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
		if( LoadConfigContent("EventArea.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EventArea.bin", strTableContent ) )
		{
			printf_message("配置文件[EventArea.bin]未找到");
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
		if(vecLine.size() != 19)
		{
			printf_message("EventArea.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EventArea.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EventArea.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="location_point_list"){printf_message("EventArea.csv中字段[location_point_list]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="area_type"){printf_message("EventArea.csv中字段[area_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="radius"){printf_message("EventArea.csv中字段[radius]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="quest_id"){printf_message("EventArea.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="quest_state"){printf_message("EventArea.csv中字段[quest_state]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="switchType"){printf_message("EventArea.csv中字段[switchType]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="event_type"){printf_message("EventArea.csv中字段[event_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="entry_buff_add"){printf_message("EventArea.csv中字段[entry_buff_add]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="leave_buff_remove"){printf_message("EventArea.csv中字段[leave_buff_remove]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="entry_mirror_id"){printf_message("EventArea.csv中字段[entry_mirror_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="leave_mirror_id"){printf_message("EventArea.csv中字段[leave_mirror_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="cg_id"){printf_message("EventArea.csv中字段[cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="music"){printf_message("EventArea.csv中字段[music]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="teleport_id"){printf_message("EventArea.csv中字段[teleport_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="is_wall"){printf_message("EventArea.csv中字段[is_wall]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="script"){printf_message("EventArea.csv中字段[script]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="quest_accept"){printf_message("EventArea.csv中字段[quest_accept]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)19)
			{
				assert(false);
				return false;
			}
			EventAreaElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.area_type=(int)atoi(vecLine[3].c_str());
			member.radius=(float)atof(vecLine[4].c_str());
			member.quest_id=(int)atoi(vecLine[5].c_str());
			member.quest_state=(int)atoi(vecLine[6].c_str());
			member.switchType=(int)atoi(vecLine[7].c_str());
			member.event_type=(int)atoi(vecLine[8].c_str());
			member.leave_buff_remove=(int)atoi(vecLine[10].c_str());
			member.entry_mirror_id=(int)atoi(vecLine[11].c_str());
			member.leave_mirror_id=(int)atoi(vecLine[12].c_str());
			member.cg_id=(int)atoi(vecLine[13].c_str());
			member.music=vecLine[14];
			member.teleport_id=vecLine[15];
			member.is_wall=(int)atoi(vecLine[16].c_str());
			member.script=vecLine[17];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
