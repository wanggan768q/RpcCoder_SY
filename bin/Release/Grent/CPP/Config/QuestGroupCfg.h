#ifndef __QUESTGROUP_CONFIG_H
#define __QUESTGROUP_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//任务组配置数据结构
struct QuestGroupElement
{
	friend class QuestGroupTable;
	int id;                      	//任务组id	对应任务组别
	string comment;              	//注释	备注
	vector<int> quest_range_id;  	//任务段	关联quest表

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
	QuestGroupElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//任务组配置封装类
class QuestGroupTable
{
	friend class TableData;
private:
	QuestGroupTable(){}
	~QuestGroupTable(){}
	map<int, QuestGroupElement>	m_mapElements;
	vector<QuestGroupElement>	m_vecAllElements;
	QuestGroupElement m_emptyItem;
public:
	static QuestGroupTable& Instance()
	{
		static QuestGroupTable sInstance;
		return sInstance;
	}

	QuestGroupElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QuestGroupElement>&	GetAllElement()
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
		if( LoadConfigContent("QuestGroup.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("QuestGroup.bin", strTableContent ) )
		{
			printf_message("配置文件[QuestGroup.bin]未找到");
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
		if(vecLine.size() != 3)
		{
			printf_message("QuestGroup.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("QuestGroup.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("QuestGroup.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="quest_range_id"){printf_message("QuestGroup.csv中字段[quest_range_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)3)
			{
				assert(false);
				return false;
			}
			QuestGroupElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
