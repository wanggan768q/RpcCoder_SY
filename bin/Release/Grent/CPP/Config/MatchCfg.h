#ifndef __MATCH_CONFIG_H
#define __MATCH_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//匹配控制表配置数据结构
struct MatchElement
{
	friend class MatchTable;
	int id;                      	//匹配类型	对应任务组别
	string comment;              	//匹配类型描述	
	int per_camp_player_size;    	//每个阵营多少人	
	int per_room_camp_size;      	//每个房间多少阵营	
	int per_team_member_size;    	//每个队伍多少人	
	int is_rank;                 	//是否是排位	
	int rank_strategy;           	//0:使用匹配成直接入队 1:匹配成功创建房间	
	int extern_section;          	//扩展段位	
	int team_section_span;       	//段位跨度(如果一个队伍段位跨度超过这个，那么则不能匹配)	
	vector<int> sections_list;   	//段位数量	
	int member_leave_cancel_team;	//一人退出是否取消全队匹配	
	int profession_size;         	//职业个数,一般有一个队最好有几个不同职业,0为可以相同	
	int custom_room;             	//可不可以创建自定义模拟房间,只能程序改该值	
	int dungeon_configid;        	//副本id	
	int scene_configid;          	//场景id	

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
	MatchElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//匹配控制表配置封装类
class MatchTable
{
	friend class TableData;
private:
	MatchTable(){}
	~MatchTable(){}
	map<int, MatchElement>	m_mapElements;
	vector<MatchElement>	m_vecAllElements;
	MatchElement m_emptyItem;
public:
	static MatchTable& Instance()
	{
		static MatchTable sInstance;
		return sInstance;
	}

	MatchElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MatchElement>&	GetAllElement()
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
		if( LoadConfigContent("Match.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Match.bin", strTableContent ) )
		{
			printf_message("配置文件[Match.bin]未找到");
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
		if(vecLine.size() != 15)
		{
			printf_message("Match.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Match.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Match.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="per_camp_player_size"){printf_message("Match.csv中字段[per_camp_player_size]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="per_room_camp_size"){printf_message("Match.csv中字段[per_room_camp_size]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="per_team_member_size"){printf_message("Match.csv中字段[per_team_member_size]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="is_rank"){printf_message("Match.csv中字段[is_rank]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="rank_strategy"){printf_message("Match.csv中字段[rank_strategy]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="extern_section"){printf_message("Match.csv中字段[extern_section]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="team_section_span"){printf_message("Match.csv中字段[team_section_span]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="sections_list"){printf_message("Match.csv中字段[sections_list]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="member_leave_cancel_team"){printf_message("Match.csv中字段[member_leave_cancel_team]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="profession_size"){printf_message("Match.csv中字段[profession_size]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="custom_room"){printf_message("Match.csv中字段[custom_room]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="dungeon_configid"){printf_message("Match.csv中字段[dungeon_configid]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="scene_configid"){printf_message("Match.csv中字段[scene_configid]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)15)
			{
				assert(false);
				return false;
			}
			MatchElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.per_camp_player_size=(int)atoi(vecLine[2].c_str());
			member.per_room_camp_size=(int)atoi(vecLine[3].c_str());
			member.per_team_member_size=(int)atoi(vecLine[4].c_str());
			member.is_rank=(int)atoi(vecLine[5].c_str());
			member.rank_strategy=(int)atoi(vecLine[6].c_str());
			member.extern_section=(int)atoi(vecLine[7].c_str());
			member.team_section_span=(int)atoi(vecLine[8].c_str());
			member.member_leave_cancel_team=(int)atoi(vecLine[10].c_str());
			member.profession_size=(int)atoi(vecLine[11].c_str());
			member.custom_room=(int)atoi(vecLine[12].c_str());
			member.dungeon_configid=(int)atoi(vecLine[13].c_str());
			member.scene_configid=(int)atoi(vecLine[14].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
