#ifndef __ONLINEBONUS_CONFIG_H
#define __ONLINEBONUS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//在线奖励表配置数据结构
struct OnlineBonusElement
{
	friend class OnlineBonusTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int required_time;           	//累计需求在线时间	单位秒
	vector<int> online_reward1_id;	//在线奖励1	道具ID|数量|是否需要中转
	vector<int> online_reward2_id;	//在线奖励2	道具ID|数量|是否需要中转
	vector<int> online_reward3_id;	//在线奖励3	道具ID|数量|是否需要中转
	vector<int> online_reward4_id;	//在线奖励4	道具ID|数量|是否需要中转

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
	OnlineBonusElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//在线奖励表配置封装类
class OnlineBonusTable
{
	friend class TableData;
private:
	OnlineBonusTable(){}
	~OnlineBonusTable(){}
	map<int, OnlineBonusElement>	m_mapElements;
	vector<OnlineBonusElement>	m_vecAllElements;
	OnlineBonusElement m_emptyItem;
public:
	static OnlineBonusTable& Instance()
	{
		static OnlineBonusTable sInstance;
		return sInstance;
	}

	OnlineBonusElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OnlineBonusElement>&	GetAllElement()
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
		if( LoadConfigContent("OnlineBonus.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("OnlineBonus.bin", strTableContent ) )
		{
			printf_message("配置文件[OnlineBonus.bin]未找到");
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
		if(vecLine.size() != 7)
		{
			printf_message("OnlineBonus.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("OnlineBonus.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("OnlineBonus.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="required_time"){printf_message("OnlineBonus.csv中字段[required_time]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="online_reward1_id"){printf_message("OnlineBonus.csv中字段[online_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="online_reward2_id"){printf_message("OnlineBonus.csv中字段[online_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="online_reward3_id"){printf_message("OnlineBonus.csv中字段[online_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="online_reward4_id"){printf_message("OnlineBonus.csv中字段[online_reward4_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			OnlineBonusElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.required_time=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
