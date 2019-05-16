#ifndef __SERVERLIST_CONFIG_H
#define __SERVERLIST_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//服务器列表配置配置数据结构
struct ServerListElement
{
	friend class ServerListTable;
	int id;                      	//id	服务器的id
	string comment;              	//注释	
	int region;                  	//区域	该服务器处于哪个大区
	int name;                    	//名称	对应文本表中的id
	int status;                  	//状态	对应服务器的状态 0.正常 1.爆满
	int promo;                   	//推荐	该服务器是否为推荐服 0.不推荐 1.推荐
	string ip;                   	//服务器ip	该服务器的ip
	int port;                    	//端口	该服务器的端口

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
	ServerListElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//服务器列表配置配置封装类
class ServerListTable
{
	friend class TableData;
private:
	ServerListTable(){}
	~ServerListTable(){}
	map<int, ServerListElement>	m_mapElements;
	vector<ServerListElement>	m_vecAllElements;
	ServerListElement m_emptyItem;
public:
	static ServerListTable& Instance()
	{
		static ServerListTable sInstance;
		return sInstance;
	}

	ServerListElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ServerListElement>&	GetAllElement()
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
		if( LoadConfigContent("ServerList.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ServerList.bin", strTableContent ) )
		{
			printf_message("配置文件[ServerList.bin]未找到");
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
			printf_message("ServerList.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ServerList.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ServerList.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="region"){printf_message("ServerList.csv中字段[region]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("ServerList.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="status"){printf_message("ServerList.csv中字段[status]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="promo"){printf_message("ServerList.csv中字段[promo]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="ip"){printf_message("ServerList.csv中字段[ip]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="port"){printf_message("ServerList.csv中字段[port]位置不对应 ");assert(false); return false; }

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
			ServerListElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.region=(int)atoi(vecLine[2].c_str());
			member.name=(int)atoi(vecLine[3].c_str());
			member.status=(int)atoi(vecLine[4].c_str());
			member.promo=(int)atoi(vecLine[5].c_str());
			member.ip=vecLine[6];
			member.port=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
