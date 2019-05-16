#ifndef __TREASURELEVEL_CONFIG_H
#define __TREASURELEVEL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝物库等级表配置数据结构
struct TreasureLevelElement
{
	friend class TreasureLevelTable;
	int id;                      	//ID	
	string comment;              	//道具注释	策划用
	int up_points;               	//宝物库升级点数	宝库库升级到 下一级所需的点数
	int up_consume;              	//升级消耗银币数量	升级消耗的银币数值
	vector<int> attribute_info1; 	//属性信息1	属性ID|属性数值
	vector<int> attribute_info2; 	//属性信息2	属性ID|属性数值
	vector<int> attribute_info3; 	//属性信息3	属性ID|属性数值
	vector<int> attribute_info4; 	//属性信息4	属性ID|属性数值
	vector<int> attribute_info5; 	//属性信息5	属性ID|属性数值
	vector<int> attribute_info6; 	//属性信息6	属性ID|属性数值
	vector<int> attribute_info7; 	//属性信息7	属性ID|属性数值
	vector<int> attribute_info8_physical;	//属性信息8_物理攻击	属性ID|属性数值
	vector<int> attribute_info8_magic;	//属性信息8_魔法攻击	属性ID|属性数值

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
	TreasureLevelElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宝物库等级表配置封装类
class TreasureLevelTable
{
	friend class TableData;
private:
	TreasureLevelTable(){}
	~TreasureLevelTable(){}
	map<int, TreasureLevelElement>	m_mapElements;
	vector<TreasureLevelElement>	m_vecAllElements;
	TreasureLevelElement m_emptyItem;
public:
	static TreasureLevelTable& Instance()
	{
		static TreasureLevelTable sInstance;
		return sInstance;
	}

	TreasureLevelElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TreasureLevelElement>&	GetAllElement()
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
		if( LoadConfigContent("TreasureLevel.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TreasureLevel.bin", strTableContent ) )
		{
			printf_message("配置文件[TreasureLevel.bin]未找到");
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
		if(vecLine.size() != 13)
		{
			printf_message("TreasureLevel.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TreasureLevel.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("TreasureLevel.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="up_points"){printf_message("TreasureLevel.csv中字段[up_points]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="up_consume"){printf_message("TreasureLevel.csv中字段[up_consume]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="attribute_info1"){printf_message("TreasureLevel.csv中字段[attribute_info1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="attribute_info2"){printf_message("TreasureLevel.csv中字段[attribute_info2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="attribute_info3"){printf_message("TreasureLevel.csv中字段[attribute_info3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="attribute_info4"){printf_message("TreasureLevel.csv中字段[attribute_info4]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="attribute_info5"){printf_message("TreasureLevel.csv中字段[attribute_info5]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="attribute_info6"){printf_message("TreasureLevel.csv中字段[attribute_info6]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="attribute_info7"){printf_message("TreasureLevel.csv中字段[attribute_info7]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="attribute_info8_physical"){printf_message("TreasureLevel.csv中字段[attribute_info8_physical]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="attribute_info8_magic"){printf_message("TreasureLevel.csv中字段[attribute_info8_magic]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			TreasureLevelElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.up_points=(int)atoi(vecLine[2].c_str());
			member.up_consume=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
