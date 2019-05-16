#ifndef __LIMIT_CONFIG_H
#define __LIMIT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//限定表配置数据结构
struct LimitElement
{
	friend class LimitTable;
	int id;                      	//主键id	
	string comment;              	//数据说明	判断说明
	int string_detail_description;	//任务的详细描述	在任务UI显示 StringQuest_任务文本表ID
	int type;                    	//数据类型	数据来源区分
	int sub_type;                	//条件	数值 1=eq 等于某个数值 2=gt 大于某个数值 3=lt 小于某个数值 4=le 小于等于某个数值 5=ge 大于等于某个数值 6=ne 不等于某个数值
	int value;                   	//条件值	数值

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
	LimitElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//限定表配置封装类
class LimitTable
{
	friend class TableData;
private:
	LimitTable(){}
	~LimitTable(){}
	map<int, LimitElement>	m_mapElements;
	vector<LimitElement>	m_vecAllElements;
	LimitElement m_emptyItem;
public:
	static LimitTable& Instance()
	{
		static LimitTable sInstance;
		return sInstance;
	}

	LimitElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LimitElement>&	GetAllElement()
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
		if( LoadConfigContent("Limit.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Limit.bin", strTableContent ) )
		{
			printf_message("配置文件[Limit.bin]未找到");
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
		if(vecLine.size() != 6)
		{
			printf_message("Limit.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Limit.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Limit.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="string_detail_description"){printf_message("Limit.csv中字段[string_detail_description]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("Limit.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="sub_type"){printf_message("Limit.csv中字段[sub_type]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="value"){printf_message("Limit.csv中字段[value]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			LimitElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.string_detail_description=(int)atoi(vecLine[2].c_str());
			member.type=(int)atoi(vecLine[3].c_str());
			member.sub_type=(int)atoi(vecLine[4].c_str());
			member.value=(int)atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
