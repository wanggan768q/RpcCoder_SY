#ifndef __FACTION_CONFIG_H
#define __FACTION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//阵营组关系配置数据结构
struct FactionElement
{
	friend class FactionTable;
	int id;                      	//组id	组id 必须保证ID 是顺序的
	string comment;              	//组名	仅策划用
	string group;                	//组标识	0=无效 1=友好 2=中立 3=敌对
	int g0;                      	//0	
	int g1;                      	//通用阵营	
	int g2;                      	//中立阵营	
	int g3;                      	//敌对阵营	
	int g4;                      	//野外战场阵营A	
	int g5;                      	//野外战场阵营B	
	int g6;                      	//阵营战阵营关系	
	vector<int> allgroup;        	//合并	公式不要手填！！！

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
	FactionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//阵营组关系配置封装类
class FactionTable
{
	friend class TableData;
private:
	FactionTable(){}
	~FactionTable(){}
	map<int, FactionElement>	m_mapElements;
	vector<FactionElement>	m_vecAllElements;
	FactionElement m_emptyItem;
public:
	static FactionTable& Instance()
	{
		static FactionTable sInstance;
		return sInstance;
	}

	FactionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FactionElement>&	GetAllElement()
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
		if( LoadConfigContent("Faction.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Faction.bin", strTableContent ) )
		{
			printf_message("配置文件[Faction.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("Faction.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Faction.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Faction.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="group"){printf_message("Faction.csv中字段[group]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="g0"){printf_message("Faction.csv中字段[g0]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="g1"){printf_message("Faction.csv中字段[g1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="g2"){printf_message("Faction.csv中字段[g2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="g3"){printf_message("Faction.csv中字段[g3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="g4"){printf_message("Faction.csv中字段[g4]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="g5"){printf_message("Faction.csv中字段[g5]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="g6"){printf_message("Faction.csv中字段[g6]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="allgroup"){printf_message("Faction.csv中字段[allgroup]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			FactionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.group=vecLine[2];
			member.g0=(int)atoi(vecLine[3].c_str());
			member.g1=(int)atoi(vecLine[4].c_str());
			member.g2=(int)atoi(vecLine[5].c_str());
			member.g3=(int)atoi(vecLine[6].c_str());
			member.g4=(int)atoi(vecLine[7].c_str());
			member.g5=(int)atoi(vecLine[8].c_str());
			member.g6=(int)atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
