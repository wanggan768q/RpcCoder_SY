#ifndef __PETINDEX_CONFIG_H
#define __PETINDEX_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物索引表配置数据结构
struct PetIndexElement
{
	friend class PetIndexTable;
	int id;                      	//宠物索引id	填写ID即可
	string comment;              	//注释	策划用
	int proto_id;                	//原型ID	宠物原型  对应宠物原型表的id
	int rank;                    	//宠物星级id	宠物当前的星级  对应宠物品质表的id
	int next_rank_item;          	//宠物下级道具	宠物升星后需要对应的道具
	int talent_id;               	//系数id	PetTalent_宠物资质id
	int npc_id;                  	//掉落显示的id	掉落显示的id

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
	PetIndexElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物索引表配置封装类
class PetIndexTable
{
	friend class TableData;
private:
	PetIndexTable(){}
	~PetIndexTable(){}
	map<int, PetIndexElement>	m_mapElements;
	vector<PetIndexElement>	m_vecAllElements;
	PetIndexElement m_emptyItem;
public:
	static PetIndexTable& Instance()
	{
		static PetIndexTable sInstance;
		return sInstance;
	}

	PetIndexElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetIndexElement>&	GetAllElement()
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
		if( LoadConfigContent("PetIndex.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetIndex.bin", strTableContent ) )
		{
			printf_message("配置文件[PetIndex.bin]未找到");
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
			printf_message("PetIndex.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetIndex.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetIndex.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="proto_id"){printf_message("PetIndex.csv中字段[proto_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="rank"){printf_message("PetIndex.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="next_rank_item"){printf_message("PetIndex.csv中字段[next_rank_item]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="talent_id"){printf_message("PetIndex.csv中字段[talent_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="npc_id"){printf_message("PetIndex.csv中字段[npc_id]位置不对应 ");assert(false); return false; }

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
			PetIndexElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.proto_id=(int)atoi(vecLine[2].c_str());
			member.rank=(int)atoi(vecLine[3].c_str());
			member.next_rank_item=(int)atoi(vecLine[4].c_str());
			member.talent_id=(int)atoi(vecLine[5].c_str());
			member.npc_id=(int)atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
