#ifndef __GIFT_CONFIG_H
#define __GIFT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//礼物表配置数据结构
struct GiftElement
{
	friend class GiftTable;
	int id;                      	//礼物ID	礼物对应的ID
	string comment;              	//注释	策划用
	int item_id;                 	//道具ID	对应道具表中的ID
	int gift_ytpe;               	//礼物类型	1：人气礼物 2：好友度礼物

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
	GiftElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//礼物表配置封装类
class GiftTable
{
	friend class TableData;
private:
	GiftTable(){}
	~GiftTable(){}
	map<int, GiftElement>	m_mapElements;
	vector<GiftElement>	m_vecAllElements;
	GiftElement m_emptyItem;
public:
	static GiftTable& Instance()
	{
		static GiftTable sInstance;
		return sInstance;
	}

	GiftElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GiftElement>&	GetAllElement()
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
		if( LoadConfigContent("Gift.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Gift.bin", strTableContent ) )
		{
			printf_message("配置文件[Gift.bin]未找到");
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
			printf_message("Gift.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Gift.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Gift.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="item_id"){printf_message("Gift.csv中字段[item_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="gift_ytpe"){printf_message("Gift.csv中字段[gift_ytpe]位置不对应 ");assert(false); return false; }

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
			GiftElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.item_id=(int)atoi(vecLine[2].c_str());
			member.gift_ytpe=(int)atoi(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
