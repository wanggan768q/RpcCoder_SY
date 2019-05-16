#ifndef __TEAMMATCHINGGROUP_CONFIG_H
#define __TEAMMATCHINGGROUP_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//队伍匹配目标组表配置数据结构
struct TeamMatchingGroupElement
{
	friend class TeamMatchingGroupTable;
	int id;                      	//匹配ID	ID
	int group_name;              	//匹配目标组名称	客户端分类专用，配置文字ID
	string group_comment;        	//匹配目标组名称（策划用）	策划用
	int group_type;              	//针对队伍类型	0：5人小队 1：多人团队
	vector<int> parameter;       	//目标ID	对应队伍匹配目标表中的ID，多个活动用|分隔

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
	TeamMatchingGroupElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//队伍匹配目标组表配置封装类
class TeamMatchingGroupTable
{
	friend class TableData;
private:
	TeamMatchingGroupTable(){}
	~TeamMatchingGroupTable(){}
	map<int, TeamMatchingGroupElement>	m_mapElements;
	vector<TeamMatchingGroupElement>	m_vecAllElements;
	TeamMatchingGroupElement m_emptyItem;
public:
	static TeamMatchingGroupTable& Instance()
	{
		static TeamMatchingGroupTable sInstance;
		return sInstance;
	}

	TeamMatchingGroupElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TeamMatchingGroupElement>&	GetAllElement()
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
		if( LoadConfigContent("TeamMatchingGroup.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TeamMatchingGroup.bin", strTableContent ) )
		{
			printf_message("配置文件[TeamMatchingGroup.bin]未找到");
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
		if(vecLine.size() != 5)
		{
			printf_message("TeamMatchingGroup.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TeamMatchingGroup.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="group_name"){printf_message("TeamMatchingGroup.csv中字段[group_name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="group_comment"){printf_message("TeamMatchingGroup.csv中字段[group_comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="group_type"){printf_message("TeamMatchingGroup.csv中字段[group_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="parameter"){printf_message("TeamMatchingGroup.csv中字段[parameter]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)5)
			{
				assert(false);
				return false;
			}
			TeamMatchingGroupElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.group_name=(int)atoi(vecLine[1].c_str());
			member.group_comment=vecLine[2];
			member.group_type=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
