#ifndef __SERVERSCRIPT_CONFIG_H
#define __SERVERSCRIPT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//服务器脚本配置数据结构
struct ServerScriptElement
{
	friend class ServerScriptTable;
	int id;                      	//脚本id	脚本id
	string file;                 	//	

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
	ServerScriptElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//服务器脚本配置封装类
class ServerScriptTable
{
	friend class TableData;
private:
	ServerScriptTable(){}
	~ServerScriptTable(){}
	map<int, ServerScriptElement>	m_mapElements;
	vector<ServerScriptElement>	m_vecAllElements;
	ServerScriptElement m_emptyItem;
public:
	static ServerScriptTable& Instance()
	{
		static ServerScriptTable sInstance;
		return sInstance;
	}

	ServerScriptElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ServerScriptElement>&	GetAllElement()
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
		if( LoadConfigContent("ServerScript.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ServerScript.bin", strTableContent ) )
		{
			printf_message("配置文件[ServerScript.bin]未找到");
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
		if(vecLine.size() != 2)
		{
			printf_message("ServerScript.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ServerScript.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="file"){printf_message("ServerScript.csv中字段[file]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)2)
			{
				assert(false);
				return false;
			}
			ServerScriptElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.file=vecLine[1];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
