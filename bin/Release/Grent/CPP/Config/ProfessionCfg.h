#ifndef __PROFESSION_CONFIG_H
#define __PROFESSION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//专精表配置数据结构
struct ProfessionElement
{
	friend class ProfessionTable;
	int id;                      	//专精ID	1-防战2-狂战，3-敏锐贼4-战斗贼，5-射击猎6-生存猎，7-火法8-冰法，9-防骑10-奶骑，11-鸟德12-奶德，13-火法男14-冰法男，15-射击猎女16生存猎女。
	int name;                    	//显示名称	关联文本表ID
	int des;                     	//专精描述	关联文本表ID
	int profession_config;       	//专精职能	枚举 1.坦克 2.治疗 3.输出人数
	int role_id;                 	//角色ID	关联角色ID
	vector<string> icon;         	//图标资源	
	int skill_normal;            	//普攻技能ID	关联技能表
	vector<int> skill_id;        	//默认技能ID	
	int roll_skill_id;           	//翻滚技能ID	
	int order;                   	//显示位置	0：左（同时会被设置为职业默认专精） 1：右
	int lv;                      	//解锁级别	
	vector<int> add_buff;        	//添加buff	关联Buff表

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
	ProfessionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//专精表配置封装类
class ProfessionTable
{
	friend class TableData;
private:
	ProfessionTable(){}
	~ProfessionTable(){}
	map<int, ProfessionElement>	m_mapElements;
	vector<ProfessionElement>	m_vecAllElements;
	ProfessionElement m_emptyItem;
public:
	static ProfessionTable& Instance()
	{
		static ProfessionTable sInstance;
		return sInstance;
	}

	ProfessionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ProfessionElement>&	GetAllElement()
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
		if( LoadConfigContent("Profession.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Profession.bin", strTableContent ) )
		{
			printf_message("配置文件[Profession.bin]未找到");
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
		if(vecLine.size() != 12)
		{
			printf_message("Profession.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Profession.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("Profession.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="des"){printf_message("Profession.csv中字段[des]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="profession_config"){printf_message("Profession.csv中字段[profession_config]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="role_id"){printf_message("Profession.csv中字段[role_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="icon"){printf_message("Profession.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="skill_normal"){printf_message("Profession.csv中字段[skill_normal]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="skill_id"){printf_message("Profession.csv中字段[skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="roll_skill_id"){printf_message("Profession.csv中字段[roll_skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="order"){printf_message("Profession.csv中字段[order]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="lv"){printf_message("Profession.csv中字段[lv]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="add_buff"){printf_message("Profession.csv中字段[add_buff]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			ProfessionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name=(int)atoi(vecLine[1].c_str());
			member.des=(int)atoi(vecLine[2].c_str());
			member.profession_config=(int)atoi(vecLine[3].c_str());
			member.role_id=(int)atoi(vecLine[4].c_str());
			member.skill_normal=(int)atoi(vecLine[6].c_str());
			member.roll_skill_id=(int)atoi(vecLine[8].c_str());
			member.order=(int)atoi(vecLine[9].c_str());
			member.lv=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
