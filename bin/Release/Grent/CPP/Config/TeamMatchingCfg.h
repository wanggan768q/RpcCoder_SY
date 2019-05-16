#ifndef __TEAMMATCHING_CONFIG_H
#define __TEAMMATCHING_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//队伍匹配配置表配置数据结构
struct TeamMatchingElement
{
	friend class TeamMatchingTable;
	int id;                      	//匹配ID	ID
	int name;                    	//匹配目标名称	客户端显示用，配置文字ID
	string comment;              	//匹配目标名称（策划用）	策划用
	int type;                    	//分类	1.活动 2.副本
	int parameter;               	//参数	如果分类是副本，那么就配置副本ID，如果分类是活动就配置活动ID
	vector<int> player_config_list;	//玩家职能推荐	坦克人数|治疗人数|输出人数

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
	TeamMatchingElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//队伍匹配配置表配置封装类
class TeamMatchingTable
{
	friend class TableData;
private:
	TeamMatchingTable(){}
	~TeamMatchingTable(){}
	map<int, TeamMatchingElement>	m_mapElements;
	vector<TeamMatchingElement>	m_vecAllElements;
	TeamMatchingElement m_emptyItem;
public:
	static TeamMatchingTable& Instance()
	{
		static TeamMatchingTable sInstance;
		return sInstance;
	}

	TeamMatchingElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TeamMatchingElement>&	GetAllElement()
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
		if( LoadConfigContent("TeamMatching.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TeamMatching.bin", strTableContent ) )
		{
			printf_message("配置文件[TeamMatching.bin]未找到");
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
			printf_message("TeamMatching.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TeamMatching.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("TeamMatching.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="comment"){printf_message("TeamMatching.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("TeamMatching.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="parameter"){printf_message("TeamMatching.csv中字段[parameter]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="player_config_list"){printf_message("TeamMatching.csv中字段[player_config_list]位置不对应 ");assert(false); return false; }

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
			TeamMatchingElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name=(int)atoi(vecLine[1].c_str());
			member.comment=vecLine[2];
			member.type=(int)atoi(vecLine[3].c_str());
			member.parameter=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
