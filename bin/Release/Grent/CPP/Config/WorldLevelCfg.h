#ifndef __WORLDLEVEL_CONFIG_H
#define __WORLDLEVEL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//世界等级配置数据结构
struct WorldLevelElement
{
	friend class WorldLevelTable;
	int id;                      	//等级区间ID	
	string comment;              	//备注	
	int level_min;               	//等级差下限	
	int level_max;               	//等级差上限	
	float exp_ratio;             	//经验获取比例	

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
	WorldLevelElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//世界等级配置封装类
class WorldLevelTable
{
	friend class TableData;
private:
	WorldLevelTable(){}
	~WorldLevelTable(){}
	map<int, WorldLevelElement>	m_mapElements;
	vector<WorldLevelElement>	m_vecAllElements;
	WorldLevelElement m_emptyItem;
public:
	static WorldLevelTable& Instance()
	{
		static WorldLevelTable sInstance;
		return sInstance;
	}

	WorldLevelElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<WorldLevelElement>&	GetAllElement()
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
		if( LoadConfigContent("WorldLevel.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("WorldLevel.bin", strTableContent ) )
		{
			printf_message("配置文件[WorldLevel.bin]未找到");
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
			printf_message("WorldLevel.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("WorldLevel.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("WorldLevel.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="level_min"){printf_message("WorldLevel.csv中字段[level_min]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="level_max"){printf_message("WorldLevel.csv中字段[level_max]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="exp_ratio"){printf_message("WorldLevel.csv中字段[exp_ratio]位置不对应 ");assert(false); return false; }

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
			WorldLevelElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.level_min=(int)atoi(vecLine[2].c_str());
			member.level_max=(int)atoi(vecLine[3].c_str());
			member.exp_ratio=(float)atof(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
