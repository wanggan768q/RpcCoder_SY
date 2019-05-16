#ifndef __CREATURECOMBATCOE_CONFIG_H
#define __CREATURECOMBATCOE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//NPC战斗系数表配置数据结构
struct CreatureCombatCoeElement
{
	friend class CreatureCombatCoeTable;
	int id;                      	//ID号	关联Creature
	string comment;              	//中文注释	
	int template_id;             	//对应模板	关联CreatureCombatbasic
	float maxhp_rate;            	//生命比例	
	float physic_attack_rate;    	//物理攻击力比例	参数1：攻击类型系数，怪物都同时具有物理攻击和魔法攻击 参数2：怪物数量系数，每组怪有多少只
	float physic_defense_rate;   	//物理防御力比例	
	float magic_attack_rate;     	//魔法攻击力比例	
	float magic_defense_rate;    	//魔法防御力比例	
	float exp_rate;              	//经验比例	

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
	CreatureCombatCoeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC战斗系数表配置封装类
class CreatureCombatCoeTable
{
	friend class TableData;
private:
	CreatureCombatCoeTable(){}
	~CreatureCombatCoeTable(){}
	map<int, CreatureCombatCoeElement>	m_mapElements;
	vector<CreatureCombatCoeElement>	m_vecAllElements;
	CreatureCombatCoeElement m_emptyItem;
public:
	static CreatureCombatCoeTable& Instance()
	{
		static CreatureCombatCoeTable sInstance;
		return sInstance;
	}

	CreatureCombatCoeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureCombatCoeElement>&	GetAllElement()
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
		if( LoadConfigContent("CreatureCombatCoe.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureCombatCoe.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureCombatCoe.bin]未找到");
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
			printf_message("CreatureCombatCoe.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreatureCombatCoe.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CreatureCombatCoe.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="template_id"){printf_message("CreatureCombatCoe.csv中字段[template_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="maxhp_rate"){printf_message("CreatureCombatCoe.csv中字段[maxhp_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="physic_attack_rate"){printf_message("CreatureCombatCoe.csv中字段[physic_attack_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="physic_defense_rate"){printf_message("CreatureCombatCoe.csv中字段[physic_defense_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="magic_attack_rate"){printf_message("CreatureCombatCoe.csv中字段[magic_attack_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="magic_defense_rate"){printf_message("CreatureCombatCoe.csv中字段[magic_defense_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="exp_rate"){printf_message("CreatureCombatCoe.csv中字段[exp_rate]位置不对应 ");assert(false); return false; }

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
			CreatureCombatCoeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.template_id=(int)atoi(vecLine[2].c_str());
			member.maxhp_rate=(float)atof(vecLine[3].c_str());
			member.physic_attack_rate=(float)atof(vecLine[4].c_str());
			member.physic_defense_rate=(float)atof(vecLine[5].c_str());
			member.magic_attack_rate=(float)atof(vecLine[6].c_str());
			member.magic_defense_rate=(float)atof(vecLine[7].c_str());
			member.exp_rate=(float)atof(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
