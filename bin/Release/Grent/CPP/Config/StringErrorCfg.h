#ifndef __STRINGERROR_CONFIG_H
#define __STRINGERROR_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//错误码表配置数据结构
struct StringErrorElement
{
	friend class StringErrorTable;
	int id;                      	//序号	需要必须为负值
	int is_display;              	//是否显示	标示该错误码是否已文本提示框的形式显示在游戏中 0.不显示 1.显示
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
	StringErrorElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//错误码表配置封装类
class StringErrorTable
{
	friend class TableData;
private:
	StringErrorTable(){}
	~StringErrorTable(){}
	map<int, StringErrorElement>	m_mapElements;
	vector<StringErrorElement>	m_vecAllElements;
	StringErrorElement m_emptyItem;
public:
	static StringErrorTable& Instance()
	{
		static StringErrorTable sInstance;
		return sInstance;
	}

	StringErrorElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringErrorElement>&	GetAllElement()
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
		if( LoadConfigContent("StringError.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringError.bin", strTableContent ) )
		{
			printf_message("配置文件[StringError.bin]未找到");
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
		if(vecLine.size() != 4)
		{
			printf_message("StringError.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringError.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="is_display"){printf_message("StringError.csv中字段[is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="comment"){printf_message("StringError.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="sc"){printf_message("StringError.csv中字段[sc]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			StringErrorElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.is_display=(int)atoi(vecLine[1].c_str());
			member.comment=vecLine[2];
			member.sc=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
