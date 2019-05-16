#ifndef __QUESTRANDOM_CONFIG_H
#define __QUESTRANDOM_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//等级表配置数据结构
struct QuestRandomElement
{
	friend class QuestRandomTable;
	int id;                      	//主键id	
	string comment;              	//任务备注	玩家等级
	vector<int> racequest_id;    	//师门任务id	任务id
	vector<int> hunt_quest_id;   	//猎魔任务id	任务id
	vector<int> treasure_monster_1_id;	//低级藏宝图怪物id	怪物id
	vector<int> treasure_monster_2_id;	//高级藏宝图怪物id	怪物id
	vector<int> battle_quest_id; 	//阵营战id	怪物id

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
	QuestRandomElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//等级表配置封装类
class QuestRandomTable
{
	friend class TableData;
private:
	QuestRandomTable(){}
	~QuestRandomTable(){}
	map<int, QuestRandomElement>	m_mapElements;
	vector<QuestRandomElement>	m_vecAllElements;
	QuestRandomElement m_emptyItem;
public:
	static QuestRandomTable& Instance()
	{
		static QuestRandomTable sInstance;
		return sInstance;
	}

	QuestRandomElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QuestRandomElement>&	GetAllElement()
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
		if( LoadConfigContent("QuestRandom.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("QuestRandom.bin", strTableContent ) )
		{
			printf_message("配置文件[QuestRandom.bin]未找到");
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
			printf_message("QuestRandom.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("QuestRandom.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("QuestRandom.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="racequest_id"){printf_message("QuestRandom.csv中字段[racequest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="hunt_quest_id"){printf_message("QuestRandom.csv中字段[hunt_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="treasure_monster_1_id"){printf_message("QuestRandom.csv中字段[treasure_monster_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="treasure_monster_2_id"){printf_message("QuestRandom.csv中字段[treasure_monster_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="battle_quest_id"){printf_message("QuestRandom.csv中字段[battle_quest_id]位置不对应 ");assert(false); return false; }

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
			QuestRandomElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
