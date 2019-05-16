#ifndef __ACTIVITYSEVENDAYTARGETDETAILS_CONFIG_H
#define __ACTIVITYSEVENDAYTARGETDETAILS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//七日目标详情表配置数据结构
struct ActivitySevenDayTargetDetailsElement
{
	friend class ActivitySevenDayTargetDetailsTable;
	int id;                      	//目标ID	活动id
	string comment;              	//注释	策划用
	int target_group_id;         	//前置目标ID	对应本表的活动ID，配置了此列数据后，需要前置活动奖励领取完成后，才会显示。
	int quest_id;                	//任务id	对应任务表中的ID
	int describe_id;             	//描述文本id	只用于界面上显示
	int describe_num;            	//目标最大计数	只用于界面上显示
	vector<int> drop_display;    	//奖励显示	只用于界面上显示
	int point_reward;            	//奖励积分（没用）	完成任务后奖励给玩家的积分数量
	int uicategory_id;           	//前往界面ID（客户端用）	对应界面类型表中的ID

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
	ActivitySevenDayTargetDetailsElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//七日目标详情表配置封装类
class ActivitySevenDayTargetDetailsTable
{
	friend class TableData;
private:
	ActivitySevenDayTargetDetailsTable(){}
	~ActivitySevenDayTargetDetailsTable(){}
	map<int, ActivitySevenDayTargetDetailsElement>	m_mapElements;
	vector<ActivitySevenDayTargetDetailsElement>	m_vecAllElements;
	ActivitySevenDayTargetDetailsElement m_emptyItem;
public:
	static ActivitySevenDayTargetDetailsTable& Instance()
	{
		static ActivitySevenDayTargetDetailsTable sInstance;
		return sInstance;
	}

	ActivitySevenDayTargetDetailsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ActivitySevenDayTargetDetailsElement>&	GetAllElement()
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
		if( LoadConfigContent("ActivitySevenDayTargetDetails.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ActivitySevenDayTargetDetails.bin", strTableContent ) )
		{
			printf_message("配置文件[ActivitySevenDayTargetDetails.bin]未找到");
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
			printf_message("ActivitySevenDayTargetDetails.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ActivitySevenDayTargetDetails.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ActivitySevenDayTargetDetails.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="target_group_id"){printf_message("ActivitySevenDayTargetDetails.csv中字段[target_group_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="quest_id"){printf_message("ActivitySevenDayTargetDetails.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="describe_id"){printf_message("ActivitySevenDayTargetDetails.csv中字段[describe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="describe_num"){printf_message("ActivitySevenDayTargetDetails.csv中字段[describe_num]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="drop_display"){printf_message("ActivitySevenDayTargetDetails.csv中字段[drop_display]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="point_reward"){printf_message("ActivitySevenDayTargetDetails.csv中字段[point_reward]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="uicategory_id"){printf_message("ActivitySevenDayTargetDetails.csv中字段[uicategory_id]位置不对应 ");assert(false); return false; }

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
			ActivitySevenDayTargetDetailsElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.target_group_id=(int)atoi(vecLine[2].c_str());
			member.quest_id=(int)atoi(vecLine[3].c_str());
			member.describe_id=(int)atoi(vecLine[4].c_str());
			member.describe_num=(int)atoi(vecLine[5].c_str());
			member.point_reward=(int)atoi(vecLine[7].c_str());
			member.uicategory_id=(int)atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
