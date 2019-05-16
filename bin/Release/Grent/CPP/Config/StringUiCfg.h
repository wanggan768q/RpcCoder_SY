#ifndef __STRINGUI_CONFIG_H
#define __STRINGUI_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//界面文本表配置数据结构
struct StringUiElement
{
	friend class StringUiTable;
	int id;                      	//序号	序号
	string comment;              	//文本内容备注	文本内容备注
	string sc;                   	//简体中文	简体中文

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
	StringUiElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//界面文本表配置封装类
class StringUiTable
{
	friend class TableData;
private:
	StringUiTable(){}
	~StringUiTable(){}
	map<int, StringUiElement>	m_mapElements;
	vector<StringUiElement>	m_vecAllElements;
	StringUiElement m_emptyItem;
public:
	static StringUiTable& Instance()
	{
		static StringUiTable sInstance;
		return sInstance;
	}

	StringUiElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringUiElement>&	GetAllElement()
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
		if( LoadConfigContent("StringUi.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringUi.bin", strTableContent ) )
		{
			printf_message("配置文件[StringUi.bin]未找到");
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
			printf_message("StringUi.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringUi.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("StringUi.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="sc"){printf_message("StringUi.csv中字段[sc]位置不对应 ");assert(false); return false; }

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
			StringUiElement	member;
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
