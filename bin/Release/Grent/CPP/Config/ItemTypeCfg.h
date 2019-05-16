#ifndef __ITEMTYPE_CONFIG_H
#define __ITEMTYPE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//道具类型配置数据结构
struct ItemTypeElement
{
	friend class ItemTypeTable;
	int id;                      	//类型ID	道具类型ID
	int type;                    	//道具大类	道具大类ID
	string type_name;            	//大类名称	策划用
	int subtype;                 	//道具子类	道具子类ID
	string comment;              	//子类名称	策划用
	int name_id;                 	//类名称	用于显示， 从StringItem表中获取
	int auction;                 	//是否可	0:不可交易 1:可交易

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
	ItemTypeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//道具类型配置封装类
class ItemTypeTable
{
	friend class TableData;
private:
	ItemTypeTable(){}
	~ItemTypeTable(){}
	map<int, ItemTypeElement>	m_mapElements;
	vector<ItemTypeElement>	m_vecAllElements;
	ItemTypeElement m_emptyItem;
public:
	static ItemTypeTable& Instance()
	{
		static ItemTypeTable sInstance;
		return sInstance;
	}

	ItemTypeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ItemTypeElement>&	GetAllElement()
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
		if( LoadConfigContent("ItemType.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ItemType.bin", strTableContent ) )
		{
			printf_message("配置文件[ItemType.bin]未找到");
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
		if(vecLine.size() != 7)
		{
			printf_message("ItemType.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ItemType.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="type"){printf_message("ItemType.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="type_name"){printf_message("ItemType.csv中字段[type_name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="subtype"){printf_message("ItemType.csv中字段[subtype]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="comment"){printf_message("ItemType.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="name_id"){printf_message("ItemType.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="auction"){printf_message("ItemType.csv中字段[auction]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			ItemTypeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.type=(int)atoi(vecLine[1].c_str());
			member.type_name=vecLine[2];
			member.subtype=(int)atoi(vecLine[3].c_str());
			member.comment=vecLine[4];
			member.name_id=(int)atoi(vecLine[5].c_str());
			member.auction=(int)atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
