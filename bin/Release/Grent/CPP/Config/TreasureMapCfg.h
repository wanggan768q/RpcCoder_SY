#ifndef __TREASUREMAP_CONFIG_H
#define __TREASUREMAP_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//藏宝图表配置数据结构
struct TreasureMapElement
{
	friend class TreasureMapTable;
	int id;                      	//主键id	场景+编号
	string comment;              	//注释	场景+位置说明
	int waypoint_id;             	//路点id	
	vector<int> trigger_id;      	//触发id	10001|20001|30001 掉落包id|怪物id|宝箱id
	vector<int> range;           	//刷怪权重	5|3|2 直接掉落|刷怪权重|刷宝箱权重

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
	TreasureMapElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//藏宝图表配置封装类
class TreasureMapTable
{
	friend class TableData;
private:
	TreasureMapTable(){}
	~TreasureMapTable(){}
	map<int, TreasureMapElement>	m_mapElements;
	vector<TreasureMapElement>	m_vecAllElements;
	TreasureMapElement m_emptyItem;
public:
	static TreasureMapTable& Instance()
	{
		static TreasureMapTable sInstance;
		return sInstance;
	}

	TreasureMapElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TreasureMapElement>&	GetAllElement()
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
		if( LoadConfigContent("TreasureMap.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TreasureMap.bin", strTableContent ) )
		{
			printf_message("配置文件[TreasureMap.bin]未找到");
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
			printf_message("TreasureMap.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TreasureMap.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("TreasureMap.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="waypoint_id"){printf_message("TreasureMap.csv中字段[waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="trigger_id"){printf_message("TreasureMap.csv中字段[trigger_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="range"){printf_message("TreasureMap.csv中字段[range]位置不对应 ");assert(false); return false; }

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
			TreasureMapElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.waypoint_id=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
