#ifndef __LEVELUPBONUS_CONFIG_H
#define __LEVELUPBONUS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//等级奖励表配置数据结构
struct LevelUpBonusElement
{
	friend class LevelUpBonusTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int required_lv;             	//需求角色等级	
	vector<int> lv_reward1_id;   	//等级奖励1	道具ID|数量|是否需要中转
	vector<int> lv_reward2_id;   	//等级奖励2	道具ID|数量|是否需要中转
	vector<int> lv_reward3_id;   	//等级奖励3	道具ID|数量|是否需要中转
	vector<int> lv_reward4_id;   	//等级奖励4	道具ID|数量|是否需要中转

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
	LevelUpBonusElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//等级奖励表配置封装类
class LevelUpBonusTable
{
	friend class TableData;
private:
	LevelUpBonusTable(){}
	~LevelUpBonusTable(){}
	map<int, LevelUpBonusElement>	m_mapElements;
	vector<LevelUpBonusElement>	m_vecAllElements;
	LevelUpBonusElement m_emptyItem;
public:
	static LevelUpBonusTable& Instance()
	{
		static LevelUpBonusTable sInstance;
		return sInstance;
	}

	LevelUpBonusElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LevelUpBonusElement>&	GetAllElement()
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
		if( LoadConfigContent("LevelUpBonus.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LevelUpBonus.bin", strTableContent ) )
		{
			printf_message("配置文件[LevelUpBonus.bin]未找到");
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
			printf_message("LevelUpBonus.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("LevelUpBonus.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("LevelUpBonus.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="required_lv"){printf_message("LevelUpBonus.csv中字段[required_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="lv_reward1_id"){printf_message("LevelUpBonus.csv中字段[lv_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="lv_reward2_id"){printf_message("LevelUpBonus.csv中字段[lv_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="lv_reward3_id"){printf_message("LevelUpBonus.csv中字段[lv_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="lv_reward4_id"){printf_message("LevelUpBonus.csv中字段[lv_reward4_id]位置不对应 ");assert(false); return false; }

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
			LevelUpBonusElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.required_lv=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
