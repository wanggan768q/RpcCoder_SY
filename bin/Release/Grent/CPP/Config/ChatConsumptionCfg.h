#ifndef __CHATCONSUMPTION_CONFIG_H
#define __CHATCONSUMPTION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//聊天消耗配置表配置数据结构
struct ChatConsumptionElement
{
	friend class ChatConsumptionTable;
	int id;                      	//id	数据的id
	string comment;              	//注释	该数据的功能
	int int_value1;              	//消耗类型(1道具2货币)	整型数据
	int int_value2;              	//消耗ID 银币 0  金币 1  钻石 2 绑定钻石3	整型数据
	int int_value3;              	//消耗数量	整型数据

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
	ChatConsumptionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//聊天消耗配置表配置封装类
class ChatConsumptionTable
{
	friend class TableData;
private:
	ChatConsumptionTable(){}
	~ChatConsumptionTable(){}
	map<int, ChatConsumptionElement>	m_mapElements;
	vector<ChatConsumptionElement>	m_vecAllElements;
	ChatConsumptionElement m_emptyItem;
public:
	static ChatConsumptionTable& Instance()
	{
		static ChatConsumptionTable sInstance;
		return sInstance;
	}

	ChatConsumptionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ChatConsumptionElement>&	GetAllElement()
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
		if( LoadConfigContent("ChatConsumption.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ChatConsumption.bin", strTableContent ) )
		{
			printf_message("配置文件[ChatConsumption.bin]未找到");
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
		if(vecLine.size() != 5)
		{
			printf_message("ChatConsumption.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ChatConsumption.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ChatConsumption.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="int_value1"){printf_message("ChatConsumption.csv中字段[int_value1]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="int_value2"){printf_message("ChatConsumption.csv中字段[int_value2]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="int_value3"){printf_message("ChatConsumption.csv中字段[int_value3]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)5)
			{
				assert(false);
				return false;
			}
			ChatConsumptionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.int_value1=(int)atoi(vecLine[2].c_str());
			member.int_value2=(int)atoi(vecLine[3].c_str());
			member.int_value3=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
