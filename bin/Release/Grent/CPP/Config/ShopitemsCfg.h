#ifndef __SHOPITEMS_CONFIG_H
#define __SHOPITEMS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//积分商品表配置数据结构
struct ShopitemsElement
{
	friend class ShopitemsTable;
	int id;                      	//ID	填写ID即可
	string comment;              	//注释	策划用
	int item_id;                 	//道具ID	道具ID
	string name;                 	//道具名称	策划用
	int shop_id;                 	//商店ID	商店ID
	int order;                   	//道具展示顺序	道具按数字从小到大排序，数字不可跳。 从“0”开始！！
	int limit_type;              	//购买限制	0无1日2周
	int limit_num;               	//数量限购	不填写则不限购
	int price;                   	//价格	填写数量
	int exchange_type;           	//限制类型	1为历史数量-废弃 2为任务是否完成填写-1则不限制
	int exchange_condition;      	//购买限制	填写任务表id填写-1则不限制 exchange_type=2时填写任务ID

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
	ShopitemsElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//积分商品表配置封装类
class ShopitemsTable
{
	friend class TableData;
private:
	ShopitemsTable(){}
	~ShopitemsTable(){}
	map<int, ShopitemsElement>	m_mapElements;
	vector<ShopitemsElement>	m_vecAllElements;
	ShopitemsElement m_emptyItem;
public:
	static ShopitemsTable& Instance()
	{
		static ShopitemsTable sInstance;
		return sInstance;
	}

	ShopitemsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ShopitemsElement>&	GetAllElement()
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
		if( LoadConfigContent("Shopitems.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Shopitems.bin", strTableContent ) )
		{
			printf_message("配置文件[Shopitems.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("Shopitems.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Shopitems.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Shopitems.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="item_id"){printf_message("Shopitems.csv中字段[item_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("Shopitems.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="shop_id"){printf_message("Shopitems.csv中字段[shop_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="order"){printf_message("Shopitems.csv中字段[order]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="limit_type"){printf_message("Shopitems.csv中字段[limit_type]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="limit_num"){printf_message("Shopitems.csv中字段[limit_num]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="price"){printf_message("Shopitems.csv中字段[price]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="exchange_type"){printf_message("Shopitems.csv中字段[exchange_type]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="exchange_condition"){printf_message("Shopitems.csv中字段[exchange_condition]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			ShopitemsElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.item_id=(int)atoi(vecLine[2].c_str());
			member.name=vecLine[3];
			member.shop_id=(int)atoi(vecLine[4].c_str());
			member.order=(int)atoi(vecLine[5].c_str());
			member.limit_type=(int)atoi(vecLine[6].c_str());
			member.limit_num=(int)atoi(vecLine[7].c_str());
			member.price=(int)atoi(vecLine[8].c_str());
			member.exchange_type=(int)atoi(vecLine[9].c_str());
			member.exchange_condition=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
