#ifndef __PETSKILL_CONFIG_H
#define __PETSKILL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物技能表配置数据结构
struct PetSkillElement
{
	friend class PetSkillTable;
	int id;                      	//宠物技能id	填写ID即可
	string comment;              	//注释	策划用
	int name;                    	//技能名称	对应显示在界面升的名称  StringSkill_技能文本表
	int desc;                    	//技能描述	对应显示在界面上的表述文本 StringSkill_技能文本表
	string icon;                 	//技能图标	对应显示在界面上的图标  可以和道具的图标一致
	int power;                   	//技能战力	该技能书所提供的战力加成
	int skill_id;                	//技能id	该技能对应的buffid
	int skill_group;             	//技能组	用来区分哪些技能是属于同一个类型
	int skill_level;             	//技能等级	技能的等级
	int attr_id;                 	//属性id	该技能添加的属性id 对应AttributeFormatConfig表的id 不填则表示没有该效果
	vector<float> attr_value;    	//属性值	该技能为宠物添加的属性具体值 百分比|值 如果attr_id字段不填则没有效果
	int attack_id;               	//技能效果id	该技能会给角色添加的光环，对应attack表的id 不填则表示没有该效果
	int buff_id;                 	//添加buff	该技能添加的buff 对应buff标的id 不填则表示没有该效果
	int item_proto;              	//对应道具	用来区分哪些技能是属于同一个类型

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
	PetSkillElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物技能表配置封装类
class PetSkillTable
{
	friend class TableData;
private:
	PetSkillTable(){}
	~PetSkillTable(){}
	map<int, PetSkillElement>	m_mapElements;
	vector<PetSkillElement>	m_vecAllElements;
	PetSkillElement m_emptyItem;
public:
	static PetSkillTable& Instance()
	{
		static PetSkillTable sInstance;
		return sInstance;
	}

	PetSkillElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetSkillElement>&	GetAllElement()
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
		if( LoadConfigContent("PetSkill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetSkill.bin", strTableContent ) )
		{
			printf_message("配置文件[PetSkill.bin]未找到");
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
		if(vecLine.size() != 14)
		{
			printf_message("PetSkill.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetSkill.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetSkill.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("PetSkill.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("PetSkill.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon"){printf_message("PetSkill.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="power"){printf_message("PetSkill.csv中字段[power]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="skill_id"){printf_message("PetSkill.csv中字段[skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="skill_group"){printf_message("PetSkill.csv中字段[skill_group]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="skill_level"){printf_message("PetSkill.csv中字段[skill_level]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="attr_id"){printf_message("PetSkill.csv中字段[attr_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="attr_value"){printf_message("PetSkill.csv中字段[attr_value]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="attack_id"){printf_message("PetSkill.csv中字段[attack_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="buff_id"){printf_message("PetSkill.csv中字段[buff_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="item_proto"){printf_message("PetSkill.csv中字段[item_proto]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)14)
			{
				assert(false);
				return false;
			}
			PetSkillElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.desc=(int)atoi(vecLine[3].c_str());
			member.icon=vecLine[4];
			member.power=(int)atoi(vecLine[5].c_str());
			member.skill_id=(int)atoi(vecLine[6].c_str());
			member.skill_group=(int)atoi(vecLine[7].c_str());
			member.skill_level=(int)atoi(vecLine[8].c_str());
			member.attr_id=(int)atoi(vecLine[9].c_str());
			member.attack_id=(int)atoi(vecLine[11].c_str());
			member.buff_id=(int)atoi(vecLine[12].c_str());
			member.item_proto=(int)atoi(vecLine[13].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
