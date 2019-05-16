#ifndef __CREATEROLE_CONFIG_H
#define __CREATEROLE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色配置数据结构
struct CreateRoleElement
{
	friend class CreateRoleTable;
	int id;                      	//id	id
	int race;                    	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	vector<int> sex;             	//可选性别	1:男性 2:女性
	int race_name;               	//种族名称	对应的名字的文本id
	int race_description;        	//种族介绍	对应介绍的文本id
	string race_icon;            	//种族图标	对应种族图标路径
	int desc_occupations;        	//可用职业介绍	对应可选职业介绍的文本id
	int default_gender;          	//默认性别	在玩家未选择性别时用于显示模型的字段
	int default_male_model;      	//默认显示男性模型	选择种族后显示的男性模型 萝莉族没有男性
	int default_female_model;    	//默认显示女性模型	选择种族后显示的女性模型 兽人族没有女性
	int default_male_id;         	//默认男性角色id	确定种族后默认选择的男性职业
	int default_female_id;       	//默认女性角色id	确定种族后默认选择的女性职业
	vector<int> male_role_id;    	//男性角色id1	如果没有男性则无用  对应该种族男性角色职业
	vector<int> female_role_id;  	//女性角色id1	如果没有女性则无用  对应该种族女性角色职业
	vector<string> create_occu_icon;	//创建界面图标	专门用在创建界面的 职业头像 对应未选中和选中两个状态
	vector<string> select_occu_icon;	//选择界面图标	专门用在选择界面的 职业标示 对应未选中和选中两个状态
	int role_id;                 	//新界面角色id	

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
	CreateRoleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色配置封装类
class CreateRoleTable
{
	friend class TableData;
private:
	CreateRoleTable(){}
	~CreateRoleTable(){}
	map<int, CreateRoleElement>	m_mapElements;
	vector<CreateRoleElement>	m_vecAllElements;
	CreateRoleElement m_emptyItem;
public:
	static CreateRoleTable& Instance()
	{
		static CreateRoleTable sInstance;
		return sInstance;
	}

	CreateRoleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreateRoleElement>&	GetAllElement()
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
		if( LoadConfigContent("CreateRole.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreateRole.bin", strTableContent ) )
		{
			printf_message("配置文件[CreateRole.bin]未找到");
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
		if(vecLine.size() != 17)
		{
			printf_message("CreateRole.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreateRole.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="race"){printf_message("CreateRole.csv中字段[race]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="sex"){printf_message("CreateRole.csv中字段[sex]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="race_name"){printf_message("CreateRole.csv中字段[race_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="race_description"){printf_message("CreateRole.csv中字段[race_description]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="race_icon"){printf_message("CreateRole.csv中字段[race_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="desc_occupations"){printf_message("CreateRole.csv中字段[desc_occupations]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="default_gender"){printf_message("CreateRole.csv中字段[default_gender]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="default_male_model"){printf_message("CreateRole.csv中字段[default_male_model]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="default_female_model"){printf_message("CreateRole.csv中字段[default_female_model]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="default_male_id"){printf_message("CreateRole.csv中字段[default_male_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="default_female_id"){printf_message("CreateRole.csv中字段[default_female_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="male_role_id"){printf_message("CreateRole.csv中字段[male_role_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="female_role_id"){printf_message("CreateRole.csv中字段[female_role_id]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="create_occu_icon"){printf_message("CreateRole.csv中字段[create_occu_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="select_occu_icon"){printf_message("CreateRole.csv中字段[select_occu_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="role_id"){printf_message("CreateRole.csv中字段[role_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)17)
			{
				assert(false);
				return false;
			}
			CreateRoleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.race=(int)atoi(vecLine[1].c_str());
			member.race_name=(int)atoi(vecLine[3].c_str());
			member.race_description=(int)atoi(vecLine[4].c_str());
			member.race_icon=vecLine[5];
			member.desc_occupations=(int)atoi(vecLine[6].c_str());
			member.default_gender=(int)atoi(vecLine[7].c_str());
			member.default_male_model=(int)atoi(vecLine[8].c_str());
			member.default_female_model=(int)atoi(vecLine[9].c_str());
			member.default_male_id=(int)atoi(vecLine[10].c_str());
			member.default_female_id=(int)atoi(vecLine[11].c_str());
			member.role_id=(int)atoi(vecLine[16].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
