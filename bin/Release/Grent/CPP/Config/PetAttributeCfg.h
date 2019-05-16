#ifndef __PETATTRIBUTE_CONFIG_H
#define __PETATTRIBUTE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物属性表配置数据结构
struct PetAttributeElement
{
	friend class PetAttributeTable;
	int id;                      	//属性条目id	填写ID即可
	string comment;              	//注释	策划用
	int experience;              	//升级经验	升级经验
	int total_exp;               	//升级经验总和	一级到当前经验的和
	vector<int> max_hp;          	//生命上限	初始生命上限
	vector<int> phy_damage;      	//物理攻击	初始物理攻击
	vector<int> mag_damage;      	//魔法攻击	初始魔法攻击
	vector<int> phy_defense;     	//物理防御	初始物理防御
	vector<int> mag_defense;     	//魔法防御	初始魔法防御
	vector<int> critical;        	//暴击值	初始暴击值
	vector<int> tenacity;        	//韧性值	初始韧性值
	vector<int> penetrait;       	//穿透值	初始穿透值
	vector<int> block;           	//格挡值	初始格挡值

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
	PetAttributeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物属性表配置封装类
class PetAttributeTable
{
	friend class TableData;
private:
	PetAttributeTable(){}
	~PetAttributeTable(){}
	map<int, PetAttributeElement>	m_mapElements;
	vector<PetAttributeElement>	m_vecAllElements;
	PetAttributeElement m_emptyItem;
public:
	static PetAttributeTable& Instance()
	{
		static PetAttributeTable sInstance;
		return sInstance;
	}

	PetAttributeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetAttributeElement>&	GetAllElement()
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
		if( LoadConfigContent("PetAttribute.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetAttribute.bin", strTableContent ) )
		{
			printf_message("配置文件[PetAttribute.bin]未找到");
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
		if(vecLine.size() != 13)
		{
			printf_message("PetAttribute.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetAttribute.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetAttribute.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="experience"){printf_message("PetAttribute.csv中字段[experience]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="total_exp"){printf_message("PetAttribute.csv中字段[total_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="max_hp"){printf_message("PetAttribute.csv中字段[max_hp]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="phy_damage"){printf_message("PetAttribute.csv中字段[phy_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="mag_damage"){printf_message("PetAttribute.csv中字段[mag_damage]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="phy_defense"){printf_message("PetAttribute.csv中字段[phy_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="mag_defense"){printf_message("PetAttribute.csv中字段[mag_defense]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="critical"){printf_message("PetAttribute.csv中字段[critical]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="tenacity"){printf_message("PetAttribute.csv中字段[tenacity]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="penetrait"){printf_message("PetAttribute.csv中字段[penetrait]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="block"){printf_message("PetAttribute.csv中字段[block]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			PetAttributeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.experience=(int)atoi(vecLine[2].c_str());
			member.total_exp=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
