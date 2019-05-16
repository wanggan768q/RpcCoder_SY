#ifndef __PETRANK_CONFIG_H
#define __PETRANK_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物星级表配置数据结构
struct PetRankElement
{
	friend class PetRankTable;
	int id;                      	//宠物星级id	对应宠物星级数量
	string comment;              	//注释	策划用
	vector<string> rank_lv;      	//星级层数	该星级对应的资源 1为星 2为月 3为日 已填充|未填充
	int rank_star;               	//星级星数	该星级对应的显示星数 1~5
	float attribute_scale;       	//升级属性加成	每次升级属性增加倍率 1表示为100%
	int unlock_lv;               	//锁定等级	星级锁定等级

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
	PetRankElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物星级表配置封装类
class PetRankTable
{
	friend class TableData;
private:
	PetRankTable(){}
	~PetRankTable(){}
	map<int, PetRankElement>	m_mapElements;
	vector<PetRankElement>	m_vecAllElements;
	PetRankElement m_emptyItem;
public:
	static PetRankTable& Instance()
	{
		static PetRankTable sInstance;
		return sInstance;
	}

	PetRankElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetRankElement>&	GetAllElement()
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
		if( LoadConfigContent("PetRank.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetRank.bin", strTableContent ) )
		{
			printf_message("配置文件[PetRank.bin]未找到");
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
		if(vecLine.size() != 6)
		{
			printf_message("PetRank.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetRank.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetRank.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="rank_lv"){printf_message("PetRank.csv中字段[rank_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="rank_star"){printf_message("PetRank.csv中字段[rank_star]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="attribute_scale"){printf_message("PetRank.csv中字段[attribute_scale]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="unlock_lv"){printf_message("PetRank.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			PetRankElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.rank_star=(int)atoi(vecLine[3].c_str());
			member.attribute_scale=(float)atof(vecLine[4].c_str());
			member.unlock_lv=(int)atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
