#ifndef __STRINGHINT_CONFIG_H
#define __STRINGHINT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//加载信息表配置数据结构
struct StringHintElement
{
	friend class StringHintTable;
	int id;                      	//序号	
	string comment;              	//文本内容备注	文本内容备注
	string sc;                   	//简体中文	简体中文文本

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
	StringHintElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//加载信息表配置封装类
class StringHintTable
{
	friend class TableData;
private:
	StringHintTable(){}
	~StringHintTable(){}
	map<int, StringHintElement>	m_mapElements;
	vector<StringHintElement>	m_vecAllElements;
	StringHintElement m_emptyItem;
public:
	static StringHintTable& Instance()
	{
		static StringHintTable sInstance;
		return sInstance;
	}

	StringHintElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringHintElement>&	GetAllElement()
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
		if( LoadConfigContent("StringHint.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringHint.bin", strTableContent ) )
		{
			printf_message("配置文件[StringHint.bin]未找到");
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
		if(vecLine.size() != 3)
		{
			printf_message("StringHint.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringHint.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("StringHint.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="sc"){printf_message("StringHint.csv中字段[sc]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)3)
			{
				assert(false);
				return false;
			}
			StringHintElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.sc=vecLine[2];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
