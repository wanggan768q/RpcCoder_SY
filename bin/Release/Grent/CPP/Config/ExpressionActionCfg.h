#ifndef __EXPRESSIONACTION_CONFIG_H
#define __EXPRESSIONACTION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//表情动作表配置数据结构
struct ExpressionActionElement
{
	friend class ExpressionActionTable;
	int id;                      	//表情ID	表情所对应的ID
	string comment;              	//备注	仅策划用
	int role_sort;               	//角色分类	对应role表中的角色分类  该ID由种族、职业、性别组成
	string action_resource;      	//动作资源	表情对应动作资源的文件名
	int skill_id;                	//技能id	表情对应技能的ID
	int expression_sort;         	//表情分类	表情对应的分类 1：基础 2：嘲讽 3：特殊
	int name_text;               	//名称文本	对应string_ui表中的ID
	int description_text;        	//描述文本	对应string_ui表中的ID
	vector<int> unlock_condition;	//解锁条件	 条件类型|条件内容  条件类型 1：外显 2：成就

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
	ExpressionActionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//表情动作表配置封装类
class ExpressionActionTable
{
	friend class TableData;
private:
	ExpressionActionTable(){}
	~ExpressionActionTable(){}
	map<int, ExpressionActionElement>	m_mapElements;
	vector<ExpressionActionElement>	m_vecAllElements;
	ExpressionActionElement m_emptyItem;
public:
	static ExpressionActionTable& Instance()
	{
		static ExpressionActionTable sInstance;
		return sInstance;
	}

	ExpressionActionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ExpressionActionElement>&	GetAllElement()
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
		if( LoadConfigContent("ExpressionAction.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ExpressionAction.bin", strTableContent ) )
		{
			printf_message("配置文件[ExpressionAction.bin]未找到");
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
			printf_message("ExpressionAction.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ExpressionAction.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ExpressionAction.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="role_sort"){printf_message("ExpressionAction.csv中字段[role_sort]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="action_resource"){printf_message("ExpressionAction.csv中字段[action_resource]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="skill_id"){printf_message("ExpressionAction.csv中字段[skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="expression_sort"){printf_message("ExpressionAction.csv中字段[expression_sort]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="name_text"){printf_message("ExpressionAction.csv中字段[name_text]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="description_text"){printf_message("ExpressionAction.csv中字段[description_text]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="unlock_condition"){printf_message("ExpressionAction.csv中字段[unlock_condition]位置不对应 ");assert(false); return false; }

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
			ExpressionActionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.role_sort=(int)atoi(vecLine[2].c_str());
			member.action_resource=vecLine[3];
			member.skill_id=(int)atoi(vecLine[4].c_str());
			member.expression_sort=(int)atoi(vecLine[5].c_str());
			member.name_text=(int)atoi(vecLine[6].c_str());
			member.description_text=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
