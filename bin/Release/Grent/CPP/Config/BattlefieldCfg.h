#ifndef __BATTLEFIELD_CONFIG_H
#define __BATTLEFIELD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//战场配置表配置数据结构
struct BattlefieldElement
{
	friend class BattlefieldTable;
	int id;                      	//ID	ID
	string comment;              	//阶级注释	策划用
	int element_type;            	//元素类型	1：怪物 2：交互OBJ 3：传送点 4：玩家
	int element_id;              	//元素ID	与元素类型对应 如元素类型为1，则此处为总NPC表ID 如元素类型为2，则此处为场景obj表ID 如元素类型为3，则此处为teleport_target表的ID
	int ranked;                  	//获得军衔值	击杀该怪物或交互OBJ获得的军衔值数目
	int honored;                 	//获得荣誉值	击杀该怪物或交互OBJ获得的荣誉值数目
	int contribution;            	//获得贡献值	击杀该怪物或交互OBJ获得的贡献值数目
	int birth_reminder;          	//出生提示	该元素刷新时是否拥有提示 0：没有 1：有
	int death_reminder;          	//死亡提示	该元素死亡时是否拥有提示 0：没有 1：有
	int activity;                	//获得活跃度	击杀该怪物或交互OBJ获得的活跃度数目

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
	BattlefieldElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//战场配置表配置封装类
class BattlefieldTable
{
	friend class TableData;
private:
	BattlefieldTable(){}
	~BattlefieldTable(){}
	map<int, BattlefieldElement>	m_mapElements;
	vector<BattlefieldElement>	m_vecAllElements;
	BattlefieldElement m_emptyItem;
public:
	static BattlefieldTable& Instance()
	{
		static BattlefieldTable sInstance;
		return sInstance;
	}

	BattlefieldElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BattlefieldElement>&	GetAllElement()
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
		if( LoadConfigContent("Battlefield.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Battlefield.bin", strTableContent ) )
		{
			printf_message("配置文件[Battlefield.bin]未找到");
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
		if(vecLine.size() != 10)
		{
			printf_message("Battlefield.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Battlefield.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Battlefield.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="element_type"){printf_message("Battlefield.csv中字段[element_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="element_id"){printf_message("Battlefield.csv中字段[element_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="ranked"){printf_message("Battlefield.csv中字段[ranked]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="honored"){printf_message("Battlefield.csv中字段[honored]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="contribution"){printf_message("Battlefield.csv中字段[contribution]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="birth_reminder"){printf_message("Battlefield.csv中字段[birth_reminder]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="death_reminder"){printf_message("Battlefield.csv中字段[death_reminder]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="activity"){printf_message("Battlefield.csv中字段[activity]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			BattlefieldElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.element_type=(int)atoi(vecLine[2].c_str());
			member.element_id=(int)atoi(vecLine[3].c_str());
			member.ranked=(int)atoi(vecLine[4].c_str());
			member.honored=(int)atoi(vecLine[5].c_str());
			member.contribution=(int)atoi(vecLine[6].c_str());
			member.birth_reminder=(int)atoi(vecLine[7].c_str());
			member.death_reminder=(int)atoi(vecLine[8].c_str());
			member.activity=(int)atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
