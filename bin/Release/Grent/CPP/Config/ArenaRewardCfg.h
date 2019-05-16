#ifndef __ARENAREWARD_CONFIG_H
#define __ARENAREWARD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//竞技场结算奖励配置数据结构
struct ArenaRewardElement
{
	friend class ArenaRewardTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int stage_name;              	//段位名称	文本ID
	int stage;                   	//段位类型	暂时不用
	int required_star;           	//星级	升到下一段位需要获得的星数
	string comment_next;         	//备注	下赛季对应的段位
	int next_season_stage;       	//段位	下赛季继承的对应段位的ID序号
	int next_season_required_star;	//星级	下赛季继承段位的初始星数
	vector<int> round_win_reward1_id;	//单场奖励1（胜利）	道具ID|数量|是否需要中转
	vector<int> round_win_reward2_id;	//单场奖励2（胜利）	道具ID|数量|是否需要中转
	vector<int> round_win_reward3_id;	//单场奖励3（胜利）	道具ID|数量|是否需要中转
	vector<int> round_win_reward4_id;	//单场奖励4（胜利）	道具ID|数量|是否需要中转
	vector<int> round_win_reward5_id;	//单场奖励1（失败）	道具ID|数量|是否需要中转
	vector<int> round_win_reward6_id;	//单场奖励2（失败）	道具ID|数量|是否需要中转
	vector<int> round_win_reward7_id;	//单场奖励3（失败）	道具ID|数量|是否需要中转
	vector<int> round_win_reward8_id;	//单场奖励4（失败）	道具ID|数量|是否需要中转
	vector<int> season_reward1_id;	//本赛季最高段位奖励1	道具ID|数量|是否需要中转
	vector<int> season_reward2_id;	//本赛季最高段位奖励2	道具ID|数量|是否需要中转
	vector<int> season_reward3_id;	//本赛季最高段位奖励3	道具ID|数量|是否需要中转
	vector<int> season_reward4_id;	//本赛季最高段位奖励4	道具ID|数量|是否需要中转
	string icon;                 	//图标	图标

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
	ArenaRewardElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//竞技场结算奖励配置封装类
class ArenaRewardTable
{
	friend class TableData;
private:
	ArenaRewardTable(){}
	~ArenaRewardTable(){}
	map<int, ArenaRewardElement>	m_mapElements;
	vector<ArenaRewardElement>	m_vecAllElements;
	ArenaRewardElement m_emptyItem;
public:
	static ArenaRewardTable& Instance()
	{
		static ArenaRewardTable sInstance;
		return sInstance;
	}

	ArenaRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ArenaRewardElement>&	GetAllElement()
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
		if( LoadConfigContent("ArenaReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ArenaReward.bin", strTableContent ) )
		{
			printf_message("配置文件[ArenaReward.bin]未找到");
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
		if(vecLine.size() != 21)
		{
			printf_message("ArenaReward.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ArenaReward.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ArenaReward.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="stage_name"){printf_message("ArenaReward.csv中字段[stage_name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="stage"){printf_message("ArenaReward.csv中字段[stage]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="required_star"){printf_message("ArenaReward.csv中字段[required_star]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="comment_next"){printf_message("ArenaReward.csv中字段[comment_next]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="next_season_stage"){printf_message("ArenaReward.csv中字段[next_season_stage]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="next_season_required_star"){printf_message("ArenaReward.csv中字段[next_season_required_star]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="round_win_reward1_id"){printf_message("ArenaReward.csv中字段[round_win_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="round_win_reward2_id"){printf_message("ArenaReward.csv中字段[round_win_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="round_win_reward3_id"){printf_message("ArenaReward.csv中字段[round_win_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="round_win_reward4_id"){printf_message("ArenaReward.csv中字段[round_win_reward4_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="round_win_reward5_id"){printf_message("ArenaReward.csv中字段[round_win_reward5_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="round_win_reward6_id"){printf_message("ArenaReward.csv中字段[round_win_reward6_id]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="round_win_reward7_id"){printf_message("ArenaReward.csv中字段[round_win_reward7_id]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="round_win_reward8_id"){printf_message("ArenaReward.csv中字段[round_win_reward8_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="season_reward1_id"){printf_message("ArenaReward.csv中字段[season_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="season_reward2_id"){printf_message("ArenaReward.csv中字段[season_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="season_reward3_id"){printf_message("ArenaReward.csv中字段[season_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="season_reward4_id"){printf_message("ArenaReward.csv中字段[season_reward4_id]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="icon"){printf_message("ArenaReward.csv中字段[icon]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)21)
			{
				assert(false);
				return false;
			}
			ArenaRewardElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.stage_name=(int)atoi(vecLine[2].c_str());
			member.stage=(int)atoi(vecLine[3].c_str());
			member.required_star=(int)atoi(vecLine[4].c_str());
			member.comment_next=vecLine[5];
			member.next_season_stage=(int)atoi(vecLine[6].c_str());
			member.next_season_required_star=(int)atoi(vecLine[7].c_str());
			member.icon=vecLine[20];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
