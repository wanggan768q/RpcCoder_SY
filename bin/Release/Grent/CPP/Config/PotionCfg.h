#ifndef __POTION_CONFIG_H
#define __POTION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//药剂表配置数据结构
struct PotionElement
{
	friend class PotionTable;
	int id;                      	//id	药剂功能的id
	string comment;              	//注释	该数据的功能
	int type;                    	//药剂类型	对应该道具是血池还是药剂 0 --血池 1 --药剂
	int item_id;                 	//道具id	对应的道具的id

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
	PotionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//药剂表配置封装类
class PotionTable
{
	friend class TableData;
private:
	PotionTable(){}
	~PotionTable(){}
	map<int, PotionElement>	m_mapElements;
	vector<PotionElement>	m_vecAllElements;
	PotionElement m_emptyItem;
public:
	static PotionTable& Instance()
	{
		static PotionTable sInstance;
		return sInstance;
	}

	PotionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PotionElement>&	GetAllElement()
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
		if( LoadConfigContent("Potion.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Potion.bin", strTableContent ) )
		{
			printf_message("配置文件[Potion.bin]未找到");
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
		if(vecLine.size() != 4)
		{
			printf_message("Potion.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Potion.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Potion.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="type"){printf_message("Potion.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="item_id"){printf_message("Potion.csv中字段[item_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			PotionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.type=(int)atoi(vecLine[2].c_str());
			member.item_id=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
