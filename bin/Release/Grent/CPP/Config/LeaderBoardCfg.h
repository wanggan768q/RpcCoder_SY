#ifndef __LEADERBOARD_CONFIG_H
#define __LEADERBOARD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//排行榜表配置数据结构
struct LeaderBoardElement
{
	friend class LeaderBoardTable;
	int id;                      	//排行榜id	对应到具体每个主题、榜单
	string comment;              	//注释	策划用
	int theme;                   	//对应主题	1：综合 2：个人 3：公会 4：PVP 5：活动
	int theme_name;              	//排行榜名称	对应StringUi表中的ID
	vector<int> update_time;     	//更新时间	 1：分钟刷新 2：小时刷新 3：天刷新
	vector<int> settlement_time; 	//结算时间	分类|日期|时间 0：每天结算1次|几点|几分 1：每周结算1次|周几|几点 2：每月结算1次|几号|几点 3：每月固定0点结算2次|几号|几号
	int billing_empty;           	//结算清空	结算是否清空榜单数据 0：不清空 1：清空 
	int enable;                  	//是否启用	0：不启用 1：启用
	vector<int> sort_index;      	//分类索引	对应奖励表的ID

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
	LeaderBoardElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//排行榜表配置封装类
class LeaderBoardTable
{
	friend class TableData;
private:
	LeaderBoardTable(){}
	~LeaderBoardTable(){}
	map<int, LeaderBoardElement>	m_mapElements;
	vector<LeaderBoardElement>	m_vecAllElements;
	LeaderBoardElement m_emptyItem;
public:
	static LeaderBoardTable& Instance()
	{
		static LeaderBoardTable sInstance;
		return sInstance;
	}

	LeaderBoardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LeaderBoardElement>&	GetAllElement()
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
		if( LoadConfigContent("LeaderBoard.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LeaderBoard.bin", strTableContent ) )
		{
			printf_message("配置文件[LeaderBoard.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("LeaderBoard.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("LeaderBoard.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("LeaderBoard.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="theme"){printf_message("LeaderBoard.csv中字段[theme]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="theme_name"){printf_message("LeaderBoard.csv中字段[theme_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="update_time"){printf_message("LeaderBoard.csv中字段[update_time]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="settlement_time"){printf_message("LeaderBoard.csv中字段[settlement_time]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="billing_empty"){printf_message("LeaderBoard.csv中字段[billing_empty]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="enable"){printf_message("LeaderBoard.csv中字段[enable]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="sort_index"){printf_message("LeaderBoard.csv中字段[sort_index]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			LeaderBoardElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.theme=(int)atoi(vecLine[2].c_str());
			member.theme_name=(int)atoi(vecLine[3].c_str());
			member.billing_empty=(int)atoi(vecLine[6].c_str());
			member.enable=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
