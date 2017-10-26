#ifndef __$TEMPLATE$_CONFIG_H
#define __$TEMPLATE$_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//$CNName$配置数据结构
struct $Template$Element
{
	friend class $Template$Table;
$FieldDefine$
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
	$Template$Element()
	{
		$InitPrimaryField$
		m_bIsValidate=false;
	}
};

//$CNName$配置封装类
class $Template$Table
{
	friend class TableData;
private:
	$Template$Table(){}
	~$Template$Table(){}
	map<$PrimaryType$, $Template$Element>	m_mapElements;
	vector<$Template$Element>	m_vecAllElements;
	$Template$Element m_emptyItem;
public:
	static $Template$Table& Instance()
	{
		static $Template$Table sInstance;
		return sInstance;
	}

	$Template$Element GetElement($PrimaryType$ key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement($PrimaryType$ key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<$Template$Element>&	GetAllElement()
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
		if( LoadConfigContent("$Template$.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("$Template$.bin", strTableContent ) )
		{
			printf_message("配置文件[$Template$.bin]未找到");
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
		if(vecLine.size() != $ColCount$)
		{
			printf_message("$Template$.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
$CheckColName$
		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)$ColCount$)
			{
				assert(false);
				return false;
			}
			$Template$Element	member;
$ReadCsvColValue$
			member.SetIsValidate(true);
			m_mapElements[member.$PrimaryKey$] = member;
		}
		return true;
	}
};

#endif
