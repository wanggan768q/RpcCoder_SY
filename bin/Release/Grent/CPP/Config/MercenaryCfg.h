#ifndef __MERCENARY_CONFIG_H
#define __MERCENARY_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//佣兵配置配置数据结构
struct MercenaryElement
{
	friend class MercenaryTable;
	int id;                      	//佣兵id	主键
	string comment;              	//注释	策划用
	int name;                    	//佣兵名称	显示用的名称
	int desc;                    	//佣兵描述	佣兵的功能和背景描述
	string portrait;             	//佣兵立绘	界面内显示的图片
	string prefab;               	//佣兵模型	调用的模型prefab
	string class_icon;           	//佣兵职业	显示的职业图标
	int profession;              	//佣兵职能	枚举，用来对应佣兵的能力 1.坦克 2.治疗 3.输出
	int normal_skill_1;          	//普攻技能1	对应的技能ID
	int normal_skill_2;          	//普攻技能2	对应的技能ID
	int normal_skill_3;          	//普攻技能3	对应的技能ID
	int profession_skill_1;      	//职业技能1	对应的技能ID
	int profession_skill_2;      	//职业技能2	对应的技能ID
	int profession_skill_3;      	//职业技能3	对应的技能ID
	int profession_skill_4;      	//职业技能4	对应的技能ID
	int combat_coe_id;           	//战斗属性id	对应了CreatureCombatCoe表内的条目 属性计算方式和怪物保持一致

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
	MercenaryElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//佣兵配置配置封装类
class MercenaryTable
{
	friend class TableData;
private:
	MercenaryTable(){}
	~MercenaryTable(){}
	map<int, MercenaryElement>	m_mapElements;
	vector<MercenaryElement>	m_vecAllElements;
	MercenaryElement m_emptyItem;
public:
	static MercenaryTable& Instance()
	{
		static MercenaryTable sInstance;
		return sInstance;
	}

	MercenaryElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MercenaryElement>&	GetAllElement()
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
		if( LoadConfigContent("Mercenary.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Mercenary.bin", strTableContent ) )
		{
			printf_message("配置文件[Mercenary.bin]未找到");
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
		if(vecLine.size() != 16)
		{
			printf_message("Mercenary.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Mercenary.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Mercenary.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("Mercenary.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("Mercenary.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="portrait"){printf_message("Mercenary.csv中字段[portrait]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="prefab"){printf_message("Mercenary.csv中字段[prefab]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="class_icon"){printf_message("Mercenary.csv中字段[class_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="profession"){printf_message("Mercenary.csv中字段[profession]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="normal_skill_1"){printf_message("Mercenary.csv中字段[normal_skill_1]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="normal_skill_2"){printf_message("Mercenary.csv中字段[normal_skill_2]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="normal_skill_3"){printf_message("Mercenary.csv中字段[normal_skill_3]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="profession_skill_1"){printf_message("Mercenary.csv中字段[profession_skill_1]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="profession_skill_2"){printf_message("Mercenary.csv中字段[profession_skill_2]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="profession_skill_3"){printf_message("Mercenary.csv中字段[profession_skill_3]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="profession_skill_4"){printf_message("Mercenary.csv中字段[profession_skill_4]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="combat_coe_id"){printf_message("Mercenary.csv中字段[combat_coe_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)16)
			{
				assert(false);
				return false;
			}
			MercenaryElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.desc=(int)atoi(vecLine[3].c_str());
			member.portrait=vecLine[4];
			member.prefab=vecLine[5];
			member.class_icon=vecLine[6];
			member.profession=(int)atoi(vecLine[7].c_str());
			member.normal_skill_1=(int)atoi(vecLine[8].c_str());
			member.normal_skill_2=(int)atoi(vecLine[9].c_str());
			member.normal_skill_3=(int)atoi(vecLine[10].c_str());
			member.profession_skill_1=(int)atoi(vecLine[11].c_str());
			member.profession_skill_2=(int)atoi(vecLine[12].c_str());
			member.profession_skill_3=(int)atoi(vecLine[13].c_str());
			member.profession_skill_4=(int)atoi(vecLine[14].c_str());
			member.combat_coe_id=(int)atoi(vecLine[15].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
