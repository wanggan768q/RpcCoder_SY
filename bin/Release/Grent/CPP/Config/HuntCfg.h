#ifndef __HUNT_CONFIG_H
#define __HUNT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//猎魔表配置数据结构
struct HuntElement
{
	friend class HuntTable;
	int id;                      	//主键id	
	string comment;              	//备注	
	int quest_id;                	//任务id	
	vector<int> monster_1_id;    	//小怪1	第一波
	vector<int> monster_2_id;    	//小怪2	第二波
	vector<int> monster_3_id;    	//小怪3	第三波
	vector<int> monster_4_id;    	//首领	boss波

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
	HuntElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//猎魔表配置封装类
class HuntTable
{
	friend class TableData;
private:
	HuntTable(){}
	~HuntTable(){}
	map<int, HuntElement>	m_mapElements;
	vector<HuntElement>	m_vecAllElements;
	HuntElement m_emptyItem;
public:
	static HuntTable& Instance()
	{
		static HuntTable sInstance;
		return sInstance;
	}

	HuntElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<HuntElement>&	GetAllElement()
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
		if( LoadConfigContent("Hunt.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Hunt.bin", strTableContent ) )
		{
			printf_message("配置文件[Hunt.bin]未找到");
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
			printf_message("Hunt.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Hunt.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Hunt.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="quest_id"){printf_message("Hunt.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="monster_1_id"){printf_message("Hunt.csv中字段[monster_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="monster_2_id"){printf_message("Hunt.csv中字段[monster_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="monster_3_id"){printf_message("Hunt.csv中字段[monster_3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="monster_4_id"){printf_message("Hunt.csv中字段[monster_4_id]位置不对应 ");assert(false); return false; }

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
			HuntElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.quest_id=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
