#ifndef __ARENARANKREWARD_CONFIG_H
#define __ARENARANKREWARD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//竞技场排行奖励配置数据结构
struct ArenaRankRewardElement
{
	friend class ArenaRankRewardTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int rank_min;                	//最低区间	最低区间
	int rank_max;                	//最高区间	最高区间
	vector<int> reward1_id;      	//排名奖励1	道具ID|数量|是否需要中转
	vector<int> reward2_id;      	//排名奖励2	道具ID|数量|是否需要中转
	vector<int> reward3_id;      	//排名奖励3	道具ID|数量|是否需要中转
	vector<int> reward4_id;      	//排名奖励4	道具ID|数量|是否需要中转

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
	ArenaRankRewardElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//竞技场排行奖励配置封装类
class ArenaRankRewardTable
{
	friend class TableData;
private:
	ArenaRankRewardTable(){}
	~ArenaRankRewardTable(){}
	map<int, ArenaRankRewardElement>	m_mapElements;
	vector<ArenaRankRewardElement>	m_vecAllElements;
	ArenaRankRewardElement m_emptyItem;
public:
	static ArenaRankRewardTable& Instance()
	{
		static ArenaRankRewardTable sInstance;
		return sInstance;
	}

	ArenaRankRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ArenaRankRewardElement>&	GetAllElement()
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
		if( LoadConfigContent("ArenaRankReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ArenaRankReward.bin", strTableContent ) )
		{
			printf_message("配置文件[ArenaRankReward.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("ArenaRankReward.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ArenaRankReward.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ArenaRankReward.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rank_min"){printf_message("ArenaRankReward.csv中字段[rank_min]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="rank_max"){printf_message("ArenaRankReward.csv中字段[rank_max]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="reward1_id"){printf_message("ArenaRankReward.csv中字段[reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="reward2_id"){printf_message("ArenaRankReward.csv中字段[reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="reward3_id"){printf_message("ArenaRankReward.csv中字段[reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="reward4_id"){printf_message("ArenaRankReward.csv中字段[reward4_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			ArenaRankRewardElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.rank_min=(int)atoi(vecLine[2].c_str());
			member.rank_max=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
