#ifndef __STRINGGUIDE_CONFIG_H
#define __STRINGGUIDE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//引导文本表配置数据结构
struct StringGuideElement
{
	friend class StringGuideTable;
	int id;                      	//序号	序号
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
	StringGuideElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//引导文本表配置封装类
class StringGuideTable
{
	friend class TableData;
private:
	StringGuideTable(){}
	~StringGuideTable(){}
	map<int, StringGuideElement>	m_mapElements;
	vector<StringGuideElement>	m_vecAllElements;
	StringGuideElement m_emptyItem;
public:
	static StringGuideTable& Instance()
	{
		static StringGuideTable sInstance;
		return sInstance;
	}

	StringGuideElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringGuideElement>&	GetAllElement()
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
		if( LoadConfigContent("StringGuide.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringGuide.bin", strTableContent ) )
		{
			printf_message("配置文件[StringGuide.bin]未找到");
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
			printf_message("StringGuide.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringGuide.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("StringGuide.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="sc"){printf_message("StringGuide.csv中字段[sc]位置不对应 ");assert(false); return false; }

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
			StringGuideElement	member;
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
