#ifndef __STRINGCHATMENU_CONFIG_H
#define __STRINGCHATMENU_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//任务对话表配置数据结构
struct StringChatmenuElement
{
	friend class StringChatmenuTable;
	int id;                      	//序号	序号
	string comment;              	//文本内容备注	文本内容备注
	int npc;                     	//发言者	填写NPC的ID，0为玩家自己
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
	StringChatmenuElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//任务对话表配置封装类
class StringChatmenuTable
{
	friend class TableData;
private:
	StringChatmenuTable(){}
	~StringChatmenuTable(){}
	map<int, StringChatmenuElement>	m_mapElements;
	vector<StringChatmenuElement>	m_vecAllElements;
	StringChatmenuElement m_emptyItem;
public:
	static StringChatmenuTable& Instance()
	{
		static StringChatmenuTable sInstance;
		return sInstance;
	}

	StringChatmenuElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<StringChatmenuElement>&	GetAllElement()
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
		if( LoadConfigContent("StringChatmenu.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("StringChatmenu.bin", strTableContent ) )
		{
			printf_message("配置文件[StringChatmenu.bin]未找到");
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
			printf_message("StringChatmenu.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("StringChatmenu.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("StringChatmenu.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="npc"){printf_message("StringChatmenu.csv中字段[npc]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="sc"){printf_message("StringChatmenu.csv中字段[sc]位置不对应 ");assert(false); return false; }

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
			StringChatmenuElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.npc=(int)atoi(vecLine[2].c_str());
			member.sc=vecLine[3];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
