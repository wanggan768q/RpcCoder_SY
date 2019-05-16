#ifndef __CURRENCY_CONFIG_H
#define __CURRENCY_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//货币表配置数据结构
struct CurrencyElement
{
	friend class CurrencyTable;
	int id;                      	//货币id	货币id
	string comment;              	//说明	注释
	int item_id;                 	//对应道具表中id	对应道具表中id
	int name;                    	//货币名	stringid
	string icon;                 	//货币图标	图标名
	string color;                	//货币颜色	色值
	int belong;                  	//从属关系	1=玩家 2=公会
	int show;                    	//是否在货币界面展示	1=显示，按id顺序 为空不显示

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
	CurrencyElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//货币表配置封装类
class CurrencyTable
{
	friend class TableData;
private:
	CurrencyTable(){}
	~CurrencyTable(){}
	map<int, CurrencyElement>	m_mapElements;
	vector<CurrencyElement>	m_vecAllElements;
	CurrencyElement m_emptyItem;
public:
	static CurrencyTable& Instance()
	{
		static CurrencyTable sInstance;
		return sInstance;
	}

	CurrencyElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CurrencyElement>&	GetAllElement()
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
		if( LoadConfigContent("Currency.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Currency.bin", strTableContent ) )
		{
			printf_message("配置文件[Currency.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("Currency.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Currency.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Currency.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="item_id"){printf_message("Currency.csv中字段[item_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("Currency.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon"){printf_message("Currency.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="color"){printf_message("Currency.csv中字段[color]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="belong"){printf_message("Currency.csv中字段[belong]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="show"){printf_message("Currency.csv中字段[show]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			CurrencyElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.item_id=(int)atoi(vecLine[2].c_str());
			member.name=(int)atoi(vecLine[3].c_str());
			member.icon=vecLine[4];
			member.color=vecLine[5];
			member.belong=(int)atoi(vecLine[6].c_str());
			member.show=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
