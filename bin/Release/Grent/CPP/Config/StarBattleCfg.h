#ifndef __STARBATTLE_CONFIG_H
#define __STARBATTLE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//星耀王座配置数据结构
struct StarBattleElement
{
	friend class StarBattleTable;
	int id;                      	//主键id	进入npc的id乘以10+1
	string comment;              	//备注	
	int scene_id;                	//场景id	
	int npc_id;                  	//npc id	进入镜像的npc id
	int survival_tm;             	//npc存活时长	npc在场景存活的时长 单位：分钟
	vector<int> mirror_id;       	//镜像id	通过npc进入的镜像id
	vector<int> waypoint_id;     	//路点id	随机刷新的路点
	int team_num;                	//队伍数量	同一个npc可以进入最大的队伍数量
	string refresh;              	//刷新时间	宠物npc在第一个场景刷新的时间
	int reward;                  	//普通奖励	奖励id
	vector<int> high_reward;     	//高额奖励	前n名完成的队伍获得高额奖励 奖励id|数量

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
	StarBattleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//星耀王座配置封装类
class StarBattleTable
{
	friend class TableData;
private:
	StarBattleTable(){}
	~StarBattleTable(){}
	map<int, StarBattleElement>	m_mapElements;
	vector<StarBattleElement>	m_vecAllElements;
	StarBattleElement m_emptyItem;
public:
	static StarBattleTable& Instance()
	{
		static StarBattleTable sInstance;
		return sInstance;
	}

	StarBattleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StarBattleElement>&	GetAllElement()
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
		if( LoadConfigContent("StarBattle.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StarBattle.bin", strTableContent ) )
		{
			printf_message("配置文件[StarBattle.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("StarBattle.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StarBattle.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("StarBattle.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="scene_id"){printf_message("StarBattle.csv中字段[scene_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="npc_id"){printf_message("StarBattle.csv中字段[npc_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="survival_tm"){printf_message("StarBattle.csv中字段[survival_tm]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="mirror_id"){printf_message("StarBattle.csv中字段[mirror_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="waypoint_id"){printf_message("StarBattle.csv中字段[waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="team_num"){printf_message("StarBattle.csv中字段[team_num]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="refresh"){printf_message("StarBattle.csv中字段[refresh]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="reward"){printf_message("StarBattle.csv中字段[reward]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="high_reward"){printf_message("StarBattle.csv中字段[high_reward]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			StarBattleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.scene_id=(int)atoi(vecLine[2].c_str());
			member.npc_id=(int)atoi(vecLine[3].c_str());
			member.survival_tm=(int)atoi(vecLine[4].c_str());
			member.team_num=(int)atoi(vecLine[7].c_str());
			member.refresh=vecLine[8];
			member.reward=(int)atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
