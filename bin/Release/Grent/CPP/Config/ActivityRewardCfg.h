#ifndef __ACTIVITYREWARD_CONFIG_H
#define __ACTIVITYREWARD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//活动奖励表配置数据结构
struct ActivityRewardElement
{
	friend class ActivityRewardTable;
	int id;                      	//主键id	活动奖励id
	string comment;              	//注释	活跃度奖励
	int active_value;            	//活跃度	
	string icon;                 	//宝箱图标	
	string icon_open;            	//宝箱图标开启后	
	int quest_id;                	//奖励包id	

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
	ActivityRewardElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//活动奖励表配置封装类
class ActivityRewardTable
{
	friend class TableData;
private:
	ActivityRewardTable(){}
	~ActivityRewardTable(){}
	map<int, ActivityRewardElement>	m_mapElements;
	vector<ActivityRewardElement>	m_vecAllElements;
	ActivityRewardElement m_emptyItem;
public:
	static ActivityRewardTable& Instance()
	{
		static ActivityRewardTable sInstance;
		return sInstance;
	}

	ActivityRewardElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ActivityRewardElement>&	GetAllElement()
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
		if( LoadConfigContent("ActivityReward.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ActivityReward.bin", strTableContent ) )
		{
			printf_message("配置文件[ActivityReward.bin]未找到");
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
		if(vecLine.size() != 6)
		{
			printf_message("ActivityReward.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ActivityReward.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ActivityReward.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="active_value"){printf_message("ActivityReward.csv中字段[active_value]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="icon"){printf_message("ActivityReward.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon_open"){printf_message("ActivityReward.csv中字段[icon_open]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="quest_id"){printf_message("ActivityReward.csv中字段[quest_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			ActivityRewardElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.active_value=(int)atoi(vecLine[2].c_str());
			member.icon=vecLine[3];
			member.icon_open=vecLine[4];
			member.quest_id=(int)atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
