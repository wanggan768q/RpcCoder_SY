#ifndef __WORLDBOSS_CONFIG_H
#define __WORLDBOSS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//野外首领配置数据结构
struct WorldBossElement
{
	friend class WorldBossTable;
	int id;                      	//	
	int creature_id;             	//NPCid	
	string comment;              	//备注	
	string boss_icon;            	//首领图标路径	圆形小图标
	vector<int> boss_level_range;	//boss的等级区间	所在地图等级区间 min|max
	int boss_spawn_id;           	//boss的出生ID	boss的出生ID
	vector<int> player_level_range;	//获得奖励的等级区间	min|max
	int birth_area_name_id;      	//出生地点文本ID	
	int boss_discrible_id;       	//描述文本ID	
	int boss_disappear_time;     	//首领删除时长	秒
	vector<int> boss_refresh_time;	//每日刷新时间	每日首次刷新时间 hh|mm|ss
	int refresh_interval;        	//刷新间隔	每次刷新的时间间隔 单位min
	int refresh_times;           	//刷新次数	每天刷新次数
	int birth_waypoint_id;       	//出生路点id	
	vector<int> player_waypoint_range;	//圆环寻路点区域半径	min|max （单位m）
	vector<int> reward_attend;   	//参与奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	vector<int> display_attend;  	//参与奖显示	道具显示
	vector<int> reward_final;    	//最后一击奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	vector<int> display_final;   	//最后一击奖显示	道具显示
	vector<int> reward_highest_damage;	//最高伤害奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	vector<int> display_highest_damage;	//最高伤害奖显示	道具显示
	vector<int> rank_1_range;    	//第1阶梯排名范围	min|max
	vector<int> reward_rank1;    	//第1阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	vector<int> rank_2_range;    	//第2阶梯排名范围	min|max
	vector<int> reward_rank2;    	//第2阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	vector<int> rank_3_range;    	//第3阶梯排名范围	min|max
	vector<int> reward_rank3;    	//第3阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	int leaderboardindexid;      	//对应排行榜索引表Id	关联排行榜索引表Id

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
	WorldBossElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//野外首领配置封装类
class WorldBossTable
{
	friend class TableData;
private:
	WorldBossTable(){}
	~WorldBossTable(){}
	map<int, WorldBossElement>	m_mapElements;
	vector<WorldBossElement>	m_vecAllElements;
	WorldBossElement m_emptyItem;
public:
	static WorldBossTable& Instance()
	{
		static WorldBossTable sInstance;
		return sInstance;
	}

	WorldBossElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<WorldBossElement>&	GetAllElement()
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
		if( LoadConfigContent("WorldBoss.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("WorldBoss.bin", strTableContent ) )
		{
			printf_message("配置文件[WorldBoss.bin]未找到");
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
		if(vecLine.size() != 28)
		{
			printf_message("WorldBoss.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("WorldBoss.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="creature_id"){printf_message("WorldBoss.csv中字段[creature_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="comment"){printf_message("WorldBoss.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="boss_icon"){printf_message("WorldBoss.csv中字段[boss_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="boss_level_range"){printf_message("WorldBoss.csv中字段[boss_level_range]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="boss_spawn_id"){printf_message("WorldBoss.csv中字段[boss_spawn_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="player_level_range"){printf_message("WorldBoss.csv中字段[player_level_range]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="birth_area_name_id"){printf_message("WorldBoss.csv中字段[birth_area_name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="boss_discrible_id"){printf_message("WorldBoss.csv中字段[boss_discrible_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="boss_disappear_time"){printf_message("WorldBoss.csv中字段[boss_disappear_time]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="boss_refresh_time"){printf_message("WorldBoss.csv中字段[boss_refresh_time]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="refresh_interval"){printf_message("WorldBoss.csv中字段[refresh_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="refresh_times"){printf_message("WorldBoss.csv中字段[refresh_times]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="birth_waypoint_id"){printf_message("WorldBoss.csv中字段[birth_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="player_waypoint_range"){printf_message("WorldBoss.csv中字段[player_waypoint_range]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="reward_attend"){printf_message("WorldBoss.csv中字段[reward_attend]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="display_attend"){printf_message("WorldBoss.csv中字段[display_attend]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="reward_final"){printf_message("WorldBoss.csv中字段[reward_final]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="display_final"){printf_message("WorldBoss.csv中字段[display_final]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="reward_highest_damage"){printf_message("WorldBoss.csv中字段[reward_highest_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="display_highest_damage"){printf_message("WorldBoss.csv中字段[display_highest_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="rank_1_range"){printf_message("WorldBoss.csv中字段[rank_1_range]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="reward_rank1"){printf_message("WorldBoss.csv中字段[reward_rank1]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="rank_2_range"){printf_message("WorldBoss.csv中字段[rank_2_range]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="reward_rank2"){printf_message("WorldBoss.csv中字段[reward_rank2]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="rank_3_range"){printf_message("WorldBoss.csv中字段[rank_3_range]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="reward_rank3"){printf_message("WorldBoss.csv中字段[reward_rank3]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="leaderboardindexid"){printf_message("WorldBoss.csv中字段[leaderboardindexid]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)28)
			{
				assert(false);
				return false;
			}
			WorldBossElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.creature_id=(int)atoi(vecLine[1].c_str());
			member.comment=vecLine[2];
			member.boss_icon=vecLine[3];
			member.boss_spawn_id=(int)atoi(vecLine[5].c_str());
			member.birth_area_name_id=(int)atoi(vecLine[7].c_str());
			member.boss_discrible_id=(int)atoi(vecLine[8].c_str());
			member.boss_disappear_time=(int)atoi(vecLine[9].c_str());
			member.refresh_interval=(int)atoi(vecLine[11].c_str());
			member.refresh_times=(int)atoi(vecLine[12].c_str());
			member.birth_waypoint_id=(int)atoi(vecLine[13].c_str());
			member.leaderboardindexid=(int)atoi(vecLine[27].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
