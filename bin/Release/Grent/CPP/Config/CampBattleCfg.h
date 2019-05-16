#ifndef __CAMPBATTLE_CONFIG_H
#define __CAMPBATTLE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//阵营战军衔配置数据结构
struct CampBattleElement
{
	friend class CampBattleTable;
	int id;                      	//军衔ID	每个军衔所对应的唯一ID 军衔ID 不要变 从1开始顺序往下 中间不留空号
	string comment;              	//注释	策划用
	int rank_name;               	//段位名称	文本ID
	int rank;                    	//军阶级别	军阶级别对应的ID
	string rank_picture;         	//军阶图片	军阶对应图标的图片资源
	int stars;                   	//星级	一个级别中所包含的星数
	int stat_rankvalue;          	//升星军衔值	升星所消耗的军衔值
	vector<int> break_reward;    	//突破奖励	突破时所获得的奖励（ 道具ID1|道具ID2|道具ID3）
	vector<int> break_num;       	//突破奖励数量	突破时所获得的道具的数量，需与ID对应（道具数量1|道具数量2|道具数量3）
	vector<int> season_award;    	//赛季奖励	赛季结束时所获得的奖励（赛季奖励道具ID1|赛季奖励道具ID2|赛季奖励道具ID3）
	vector<int> season_num;      	//赛季奖励数量	赛季结束时所获得的奖励道具数量（赛季奖励道具数量1|赛季奖励道具数量2|赛季奖励道具数量3）
	vector<int> high_award;      	//赛季高级奖励	赛季结束时所获得的高级奖励（赛季奖励道具ID1|赛季奖励道具ID2|赛季奖励道具ID3）
	vector<int> high_num;        	//赛季高级奖励数量	赛季结束时所获得的高级奖励道具数量（赛季奖励道具数量1|赛季奖励道具数量2|赛季奖励道具数量3）

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
	CampBattleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//阵营战军衔配置封装类
class CampBattleTable
{
	friend class TableData;
private:
	CampBattleTable(){}
	~CampBattleTable(){}
	map<int, CampBattleElement>	m_mapElements;
	vector<CampBattleElement>	m_vecAllElements;
	CampBattleElement m_emptyItem;
public:
	static CampBattleTable& Instance()
	{
		static CampBattleTable sInstance;
		return sInstance;
	}

	CampBattleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CampBattleElement>&	GetAllElement()
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
		if( LoadConfigContent("CampBattle.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CampBattle.bin", strTableContent ) )
		{
			printf_message("配置文件[CampBattle.bin]未找到");
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
		if(vecLine.size() != 13)
		{
			printf_message("CampBattle.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CampBattle.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CampBattle.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rank_name"){printf_message("CampBattle.csv中字段[rank_name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="rank"){printf_message("CampBattle.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="rank_picture"){printf_message("CampBattle.csv中字段[rank_picture]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="stars"){printf_message("CampBattle.csv中字段[stars]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="stat_rankvalue"){printf_message("CampBattle.csv中字段[stat_rankvalue]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="break_reward"){printf_message("CampBattle.csv中字段[break_reward]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="break_num"){printf_message("CampBattle.csv中字段[break_num]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="season_award"){printf_message("CampBattle.csv中字段[season_award]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="season_num"){printf_message("CampBattle.csv中字段[season_num]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="high_award"){printf_message("CampBattle.csv中字段[high_award]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="high_num"){printf_message("CampBattle.csv中字段[high_num]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			CampBattleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.rank_name=(int)atoi(vecLine[2].c_str());
			member.rank=(int)atoi(vecLine[3].c_str());
			member.rank_picture=vecLine[4];
			member.stars=(int)atoi(vecLine[5].c_str());
			member.stat_rankvalue=(int)atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
