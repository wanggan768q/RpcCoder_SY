#ifndef __EQUIPBUILDINDEX_CONFIG_H
#define __EQUIPBUILDINDEX_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//打造索引表配置数据结构
struct EquipBuildIndexElement
{
	friend class EquipBuildIndexTable;
	int id;                      	//配方ID	该配方内装备所对应的等级分组 4:40级 5:50级 6:60级 7:70级 8:80级 9:90级 10:100级
	int delta_level;             	//等级差	等级差
	vector<int> formula_mage;    	//法师对应配方	依次填入该等级该职业对应的配方，用|隔开
	vector<int> formula_paladin; 	//圣骑对应配方	依次填入该等级该职业对应的配方，用|隔开
	vector<int> formula_ranger;  	//游侠对应配方	依次填入该等级该职业对应的配方，用|隔开
	vector<int> formula_mystic;  	//神秘使对应配方	依次填入该等级该职业对应的配方，用|隔开
	vector<int> formula_berserker;	//狂战士对应配方	依次填入该等级该职业对应的配方，用|隔开
	int artifact_limit;          	//神器值上限	该配方对应的神器值上限

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
	EquipBuildIndexElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//打造索引表配置封装类
class EquipBuildIndexTable
{
	friend class TableData;
private:
	EquipBuildIndexTable(){}
	~EquipBuildIndexTable(){}
	map<int, EquipBuildIndexElement>	m_mapElements;
	vector<EquipBuildIndexElement>	m_vecAllElements;
	EquipBuildIndexElement m_emptyItem;
public:
	static EquipBuildIndexTable& Instance()
	{
		static EquipBuildIndexTable sInstance;
		return sInstance;
	}

	EquipBuildIndexElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipBuildIndexElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipBuildIndex.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipBuildIndex.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipBuildIndex.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("EquipBuildIndex.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipBuildIndex.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="delta_level"){printf_message("EquipBuildIndex.csv中字段[delta_level]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="formula_mage"){printf_message("EquipBuildIndex.csv中字段[formula_mage]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="formula_paladin"){printf_message("EquipBuildIndex.csv中字段[formula_paladin]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="formula_ranger"){printf_message("EquipBuildIndex.csv中字段[formula_ranger]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="formula_mystic"){printf_message("EquipBuildIndex.csv中字段[formula_mystic]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="formula_berserker"){printf_message("EquipBuildIndex.csv中字段[formula_berserker]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="artifact_limit"){printf_message("EquipBuildIndex.csv中字段[artifact_limit]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			EquipBuildIndexElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.delta_level=(int)atoi(vecLine[1].c_str());
			member.artifact_limit=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
