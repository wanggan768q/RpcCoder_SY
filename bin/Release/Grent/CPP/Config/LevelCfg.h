#ifndef __LEVEL_CONFIG_H
#define __LEVEL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//等级表配置数据结构
struct LevelElement
{
	friend class LevelTable;
	int id;                      	//主键id	
	string comment;              	//任务备注	玩家等级
	vector<int> racequest_id_first_day;	//占星任务第一天	任务id 可以分段，但任务id中间必须是连续的，12025|12036|12050|12081
	vector<int> racequest_id_head_3;	//占星任务id前三次	任务id
	vector<int> racequest_id_tail_7;	//占星任务后七次	任务id
	vector<int> hunt_quest_id;   	//猎魔任务id	任务id
	vector<int> treasure_map_1_id;	//低级藏宝图map id	treasuremap_id
	vector<int> treasure_map_2_id;	//高级藏宝图map id	treasuremap_id
	vector<int> treasure_monster_1_id;	//低级藏宝图怪物id	怪物id
	vector<int> treasure_monster_2_id;	//高级藏宝图怪物id	怪物id
	vector<int> battle_quest_id; 	//世界战场活跃度箱子	任务id
	vector<int> elite_quest_id;  	//精英怪任务id	任务id
	vector<int> arena_quest_id;  	//竞技场活动任务	任务id
	vector<int> daily_quest_id;  	//世界战场和爬塔活动 积分计数任务	每天刷新 自动会接到的任务 以下填任务id
	vector<int> battle_quest_2_id;	//世界战场活动任务	以下填任务id

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
	LevelElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//等级表配置封装类
class LevelTable
{
	friend class TableData;
private:
	LevelTable(){}
	~LevelTable(){}
	map<int, LevelElement>	m_mapElements;
	vector<LevelElement>	m_vecAllElements;
	LevelElement m_emptyItem;
public:
	static LevelTable& Instance()
	{
		static LevelTable sInstance;
		return sInstance;
	}

	LevelElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LevelElement>&	GetAllElement()
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
		if( LoadConfigContent("Level.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Level.bin", strTableContent ) )
		{
			printf_message("配置文件[Level.bin]未找到");
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
			printf_message("Level.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Level.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Level.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="racequest_id_first_day"){printf_message("Level.csv中字段[racequest_id_first_day]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="racequest_id_head_3"){printf_message("Level.csv中字段[racequest_id_head_3]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="racequest_id_tail_7"){printf_message("Level.csv中字段[racequest_id_tail_7]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="hunt_quest_id"){printf_message("Level.csv中字段[hunt_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="treasure_map_1_id"){printf_message("Level.csv中字段[treasure_map_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="treasure_map_2_id"){printf_message("Level.csv中字段[treasure_map_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="treasure_monster_1_id"){printf_message("Level.csv中字段[treasure_monster_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="treasure_monster_2_id"){printf_message("Level.csv中字段[treasure_monster_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="battle_quest_id"){printf_message("Level.csv中字段[battle_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="elite_quest_id"){printf_message("Level.csv中字段[elite_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="arena_quest_id"){printf_message("Level.csv中字段[arena_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="daily_quest_id"){printf_message("Level.csv中字段[daily_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="battle_quest_2_id"){printf_message("Level.csv中字段[battle_quest_2_id]位置不对应 ");assert(false); return false; }

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
			LevelElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
