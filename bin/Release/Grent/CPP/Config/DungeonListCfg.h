#ifndef __DUNGEONLIST_CONFIG_H
#define __DUNGEONLIST_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//副本查找器地下城手册配置数据结构
struct DungeonListElement
{
	friend class DungeonListTable;
	int id;                      	//序号	序号
	string comment;              	//策划用	备注
	int dungeon_type;            	//副本类型	1=5人 2=10人
	int dungeon_name;            	//副本名	string_id
	int unlock_lv;               	//解锁等级	整数
	int kill_refresh;            	//击杀次数刷新时间	1=每日刷新 7=每周刷新
	int single_id;               	//单人难度id	填写ID
	vector<int> single_bossid;   	//单人bossid	填写副本表bossid
	vector<int> single_number;   	//单人boss挑战次数	填写每日获得奖励次数
	vector<int> single_rewards;  	//单人难度奖励	展示道具id
	int normal_id;               	//普通难度id	填写ID
	vector<int> normal_bossid;   	//普通bossid	填写副本表bossid
	vector<int> normal_number;   	//普通boss挑战次数	填写每日获得奖励次数
	vector<int> normal_rewards;  	//普通难度奖励	展示道具id
	int hero_id;                 	//英雄难度id	填写ID
	vector<int> hero_bossid;     	//英雄bossid	填写副本表bossid
	vector<int> hero_number;     	//英雄boss挑战次数	填写每日获得奖励次数
	vector<int> hero_rewards;    	//英雄难度奖励	展示道具id
	string map_pic;              	//地图图片	填写图片名
	vector<int> boss1_single;    	//boss1单人模式奖励展示	展示道具id
	vector<int> boss1_normal;    	//boss1普通模式奖励展示	展示道具id
	vector<int> boss1_hero;      	//boss1英雄模式奖励展示	展示道具id
	vector<int> boss2_single;    	//boss2单人模式奖励展示	展示道具id
	vector<int> boss2_normal;    	//boss2普通模式奖励展示	展示道具id
	vector<int> boss2_hero;      	//boss2英雄模式奖励展示	展示道具id

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
	DungeonListElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//副本查找器地下城手册配置封装类
class DungeonListTable
{
	friend class TableData;
private:
	DungeonListTable(){}
	~DungeonListTable(){}
	map<int, DungeonListElement>	m_mapElements;
	vector<DungeonListElement>	m_vecAllElements;
	DungeonListElement m_emptyItem;
public:
	static DungeonListTable& Instance()
	{
		static DungeonListTable sInstance;
		return sInstance;
	}

	DungeonListElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DungeonListElement>&	GetAllElement()
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
		if( LoadConfigContent("DungeonList.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("DungeonList.bin", strTableContent ) )
		{
			printf_message("配置文件[DungeonList.bin]未找到");
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
		if(vecLine.size() != 25)
		{
			printf_message("DungeonList.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("DungeonList.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("DungeonList.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="dungeon_type"){printf_message("DungeonList.csv中字段[dungeon_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="dungeon_name"){printf_message("DungeonList.csv中字段[dungeon_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="unlock_lv"){printf_message("DungeonList.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="kill_refresh"){printf_message("DungeonList.csv中字段[kill_refresh]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="single_id"){printf_message("DungeonList.csv中字段[single_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="single_bossid"){printf_message("DungeonList.csv中字段[single_bossid]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="single_number"){printf_message("DungeonList.csv中字段[single_number]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="single_rewards"){printf_message("DungeonList.csv中字段[single_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="normal_id"){printf_message("DungeonList.csv中字段[normal_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="normal_bossid"){printf_message("DungeonList.csv中字段[normal_bossid]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="normal_number"){printf_message("DungeonList.csv中字段[normal_number]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="normal_rewards"){printf_message("DungeonList.csv中字段[normal_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="hero_id"){printf_message("DungeonList.csv中字段[hero_id]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="hero_bossid"){printf_message("DungeonList.csv中字段[hero_bossid]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="hero_number"){printf_message("DungeonList.csv中字段[hero_number]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="hero_rewards"){printf_message("DungeonList.csv中字段[hero_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="map_pic"){printf_message("DungeonList.csv中字段[map_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="boss1_single"){printf_message("DungeonList.csv中字段[boss1_single]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="boss1_normal"){printf_message("DungeonList.csv中字段[boss1_normal]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="boss1_hero"){printf_message("DungeonList.csv中字段[boss1_hero]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="boss2_single"){printf_message("DungeonList.csv中字段[boss2_single]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="boss2_normal"){printf_message("DungeonList.csv中字段[boss2_normal]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="boss2_hero"){printf_message("DungeonList.csv中字段[boss2_hero]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)25)
			{
				assert(false);
				return false;
			}
			DungeonListElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.dungeon_type=(int)atoi(vecLine[2].c_str());
			member.dungeon_name=(int)atoi(vecLine[3].c_str());
			member.unlock_lv=(int)atoi(vecLine[4].c_str());
			member.kill_refresh=(int)atoi(vecLine[5].c_str());
			member.single_id=(int)atoi(vecLine[6].c_str());
			member.normal_id=(int)atoi(vecLine[10].c_str());
			member.hero_id=(int)atoi(vecLine[14].c_str());
			member.map_pic=vecLine[18];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
