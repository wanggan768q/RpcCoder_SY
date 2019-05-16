#ifndef __BUINESS_CONFIG_H
#define __BUINESS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//生活技能细则配置数据结构
struct BuinessElement
{
	friend class BuinessTable;
	int id;                      	//生活技能子等级id	id=生活技能idx10+等级
	int type;                    	//对应生活技能ID	对应生活技能ID
	int lv;                      	//等级	等级
	int exp;                     	//级别所需exp	升至该等级所需
	int cost;                    	//级段对应制作消耗精力值	暂无精力相关
	vector<int> item;            	//可制造道具	道具表中id
	int unlock_lv;               	//解锁新道具等级	等级
	int unlock_item;             	//解锁新道具ID	道具表中id
	int loot_item;               	//制作时产出道具	填写DropWeight_权值掉落表的掉落ID

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
	BuinessElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//生活技能细则配置封装类
class BuinessTable
{
	friend class TableData;
private:
	BuinessTable(){}
	~BuinessTable(){}
	map<int, BuinessElement>	m_mapElements;
	vector<BuinessElement>	m_vecAllElements;
	BuinessElement m_emptyItem;
public:
	static BuinessTable& Instance()
	{
		static BuinessTable sInstance;
		return sInstance;
	}

	BuinessElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuinessElement>&	GetAllElement()
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
		if( LoadConfigContent("Buiness.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Buiness.bin", strTableContent ) )
		{
			printf_message("配置文件[Buiness.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("Buiness.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Buiness.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="type"){printf_message("Buiness.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="lv"){printf_message("Buiness.csv中字段[lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="exp"){printf_message("Buiness.csv中字段[exp]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="cost"){printf_message("Buiness.csv中字段[cost]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="item"){printf_message("Buiness.csv中字段[item]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="unlock_lv"){printf_message("Buiness.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="unlock_item"){printf_message("Buiness.csv中字段[unlock_item]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="loot_item"){printf_message("Buiness.csv中字段[loot_item]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			BuinessElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.type=(int)atoi(vecLine[1].c_str());
			member.lv=(int)atoi(vecLine[2].c_str());
			member.exp=(int)atoi(vecLine[3].c_str());
			member.cost=(int)atoi(vecLine[4].c_str());
			member.unlock_lv=(int)atoi(vecLine[6].c_str());
			member.unlock_item=(int)atoi(vecLine[7].c_str());
			member.loot_item=(int)atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
