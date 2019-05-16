#ifndef __SUMMONMONSTER_CONFIG_H
#define __SUMMONMONSTER_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//召唤小怪表配置数据结构
struct SummonMonsterElement
{
	friend class SummonMonsterTable;
	int id;                      	//序号	序号
	float group_id;              	//规定召唤怪的组	规定召唤怪的组
	int npc_entry_id;            	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	int map_id;                  	//NPC所处的场景号	NPC所处的场景号
	float location_x;            	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	float location_y;            	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	float location_z;            	//路点所处的场景的Z坐标	路点所处的场景的Z坐标

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
	SummonMonsterElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//召唤小怪表配置封装类
class SummonMonsterTable
{
	friend class TableData;
private:
	SummonMonsterTable(){}
	~SummonMonsterTable(){}
	map<int, SummonMonsterElement>	m_mapElements;
	vector<SummonMonsterElement>	m_vecAllElements;
	SummonMonsterElement m_emptyItem;
public:
	static SummonMonsterTable& Instance()
	{
		static SummonMonsterTable sInstance;
		return sInstance;
	}

	SummonMonsterElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SummonMonsterElement>&	GetAllElement()
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
		if( LoadConfigContent("SummonMonster.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SummonMonster.bin", strTableContent ) )
		{
			printf_message("配置文件[SummonMonster.bin]未找到");
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
			printf_message("SummonMonster.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("SummonMonster.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="group_id"){printf_message("SummonMonster.csv中字段[group_id]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="npc_entry_id"){printf_message("SummonMonster.csv中字段[npc_entry_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="map_id"){printf_message("SummonMonster.csv中字段[map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="location_x"){printf_message("SummonMonster.csv中字段[location_x]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="location_y"){printf_message("SummonMonster.csv中字段[location_y]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="location_z"){printf_message("SummonMonster.csv中字段[location_z]位置不对应 ");assert(false); return false; }

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
			SummonMonsterElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.group_id=(float)atof(vecLine[1].c_str());
			member.npc_entry_id=(int)atoi(vecLine[2].c_str());
			member.map_id=(int)atoi(vecLine[3].c_str());
			member.location_x=(float)atof(vecLine[4].c_str());
			member.location_y=(float)atof(vecLine[5].c_str());
			member.location_z=(float)atof(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
