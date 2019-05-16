#ifndef __SINGLETOWER_CONFIG_H
#define __SINGLETOWER_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//单人爬塔配置数据结构
struct SingleTowerElement
{
	friend class SingleTowerTable;
	int id;                      	//层数id	 所在层数，最小为1，为唯一值；
	vector<int> reward_1;        	//奖励1	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> reward_2;        	//奖励2	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> reward_3;        	//奖励3	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> reward_4;        	//奖励4	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> reward_5;        	//奖励5	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> first_reward_1;  	//首次通关奖励1	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> first_reward_2;  	//首次通关奖励2	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> first_reward_3;  	//首次通关奖励3	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> first_reward_4;  	//首次通关奖励4	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	vector<int> first_reward_5;  	//首次通关奖励5	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	int monster1_id;             	//怪物1id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster1_wave;           	//怪物1波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster1_count;          	//怪物1数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group1; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster2_id;             	//怪物2id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster2_wave;           	//怪物2波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster2_count;          	//怪物2数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group2; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster3_id;             	//怪物3id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster3_wave;           	//怪物3波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster3_count;          	//怪物3数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group3; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster4_id;             	//怪物4id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster4_wave;           	//怪物4波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster4_count;          	//怪物4数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group4; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster5_id;             	//怪物5id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster5_wave;           	//怪物5波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster5_count;          	//怪物5数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group5; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster6_id;             	//怪物6id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster6_wave;           	//怪物6波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster6_count;          	//怪物6数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group6; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster7_id;             	//怪物7id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster7_wave;           	//怪物7波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster7_count;          	//怪物7数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group7; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster8_id;             	//怪物8id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster8_wave;           	//怪物8波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster8_count;          	//怪物8数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group8; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	int monster9_id;             	//怪物9id	对应总npc表（Creature_总NPC表），没有则填-1
	int monster9_wave;           	//怪物9波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	int monster9_count;          	//怪物9数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	vector<int> waypoint_group9; 	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。

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
	SingleTowerElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//单人爬塔配置封装类
class SingleTowerTable
{
	friend class TableData;
private:
	SingleTowerTable(){}
	~SingleTowerTable(){}
	map<int, SingleTowerElement>	m_mapElements;
	vector<SingleTowerElement>	m_vecAllElements;
	SingleTowerElement m_emptyItem;
public:
	static SingleTowerTable& Instance()
	{
		static SingleTowerTable sInstance;
		return sInstance;
	}

	SingleTowerElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SingleTowerElement>&	GetAllElement()
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
		if( LoadConfigContent("SingleTower.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SingleTower.bin", strTableContent ) )
		{
			printf_message("配置文件[SingleTower.bin]未找到");
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
			printf_message("SingleTower.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("SingleTower.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="reward_1"){printf_message("SingleTower.csv中字段[reward_1]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="reward_2"){printf_message("SingleTower.csv中字段[reward_2]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="reward_3"){printf_message("SingleTower.csv中字段[reward_3]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="reward_4"){printf_message("SingleTower.csv中字段[reward_4]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="reward_5"){printf_message("SingleTower.csv中字段[reward_5]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="first_reward_1"){printf_message("SingleTower.csv中字段[first_reward_1]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="first_reward_2"){printf_message("SingleTower.csv中字段[first_reward_2]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="first_reward_3"){printf_message("SingleTower.csv中字段[first_reward_3]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="first_reward_4"){printf_message("SingleTower.csv中字段[first_reward_4]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="first_reward_5"){printf_message("SingleTower.csv中字段[first_reward_5]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="monster1_id"){printf_message("SingleTower.csv中字段[monster1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="monster1_wave"){printf_message("SingleTower.csv中字段[monster1_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="monster1_count"){printf_message("SingleTower.csv中字段[monster1_count]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="waypoint_group1"){printf_message("SingleTower.csv中字段[waypoint_group1]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="monster2_id"){printf_message("SingleTower.csv中字段[monster2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="monster2_wave"){printf_message("SingleTower.csv中字段[monster2_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="monster2_count"){printf_message("SingleTower.csv中字段[monster2_count]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="waypoint_group2"){printf_message("SingleTower.csv中字段[waypoint_group2]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="monster3_id"){printf_message("SingleTower.csv中字段[monster3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="monster3_wave"){printf_message("SingleTower.csv中字段[monster3_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="monster3_count"){printf_message("SingleTower.csv中字段[monster3_count]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="waypoint_group3"){printf_message("SingleTower.csv中字段[waypoint_group3]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="monster4_id"){printf_message("SingleTower.csv中字段[monster4_id]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="monster4_wave"){printf_message("SingleTower.csv中字段[monster4_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="monster4_count"){printf_message("SingleTower.csv中字段[monster4_count]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="waypoint_group4"){printf_message("SingleTower.csv中字段[waypoint_group4]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="monster5_id"){printf_message("SingleTower.csv中字段[monster5_id]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="monster5_wave"){printf_message("SingleTower.csv中字段[monster5_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="monster5_count"){printf_message("SingleTower.csv中字段[monster5_count]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="waypoint_group5"){printf_message("SingleTower.csv中字段[waypoint_group5]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="monster6_id"){printf_message("SingleTower.csv中字段[monster6_id]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="monster6_wave"){printf_message("SingleTower.csv中字段[monster6_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="monster6_count"){printf_message("SingleTower.csv中字段[monster6_count]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="waypoint_group6"){printf_message("SingleTower.csv中字段[waypoint_group6]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="monster7_id"){printf_message("SingleTower.csv中字段[monster7_id]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="monster7_wave"){printf_message("SingleTower.csv中字段[monster7_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="monster7_count"){printf_message("SingleTower.csv中字段[monster7_count]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="waypoint_group7"){printf_message("SingleTower.csv中字段[waypoint_group7]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="monster8_id"){printf_message("SingleTower.csv中字段[monster8_id]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="monster8_wave"){printf_message("SingleTower.csv中字段[monster8_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="monster8_count"){printf_message("SingleTower.csv中字段[monster8_count]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="waypoint_group8"){printf_message("SingleTower.csv中字段[waypoint_group8]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="monster9_id"){printf_message("SingleTower.csv中字段[monster9_id]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="monster9_wave"){printf_message("SingleTower.csv中字段[monster9_wave]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="monster9_count"){printf_message("SingleTower.csv中字段[monster9_count]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="waypoint_group9"){printf_message("SingleTower.csv中字段[waypoint_group9]位置不对应 ");assert(false); return false; }

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
			SingleTowerElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.monster1_id=(int)atoi(vecLine[11].c_str());
			member.monster1_wave=(int)atoi(vecLine[12].c_str());
			member.monster1_count=(int)atoi(vecLine[13].c_str());
			member.monster2_id=(int)atoi(vecLine[15].c_str());
			member.monster2_wave=(int)atoi(vecLine[16].c_str());
			member.monster2_count=(int)atoi(vecLine[17].c_str());
			member.monster3_id=(int)atoi(vecLine[19].c_str());
			member.monster3_wave=(int)atoi(vecLine[20].c_str());
			member.monster3_count=(int)atoi(vecLine[21].c_str());
			member.monster4_id=(int)atoi(vecLine[23].c_str());
			member.monster4_wave=(int)atoi(vecLine[24].c_str());
			member.monster4_count=(int)atoi(vecLine[25].c_str());
			member.monster5_id=(int)atoi(vecLine[27].c_str());
			member.monster5_wave=(int)atoi(vecLine[28].c_str());
			member.monster5_count=(int)atoi(vecLine[29].c_str());
			member.monster6_id=(int)atoi(vecLine[31].c_str());
			member.monster6_wave=(int)atoi(vecLine[32].c_str());
			member.monster6_count=(int)atoi(vecLine[33].c_str());
			member.monster7_id=(int)atoi(vecLine[35].c_str());
			member.monster7_wave=(int)atoi(vecLine[36].c_str());
			member.monster7_count=(int)atoi(vecLine[37].c_str());
			member.monster8_id=(int)atoi(vecLine[39].c_str());
			member.monster8_wave=(int)atoi(vecLine[40].c_str());
			member.monster8_count=(int)atoi(vecLine[41].c_str());
			member.monster9_id=(int)atoi(vecLine[43].c_str());
			member.monster9_wave=(int)atoi(vecLine[44].c_str());
			member.monster9_count=(int)atoi(vecLine[45].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
