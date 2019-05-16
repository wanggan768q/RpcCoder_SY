#ifndef __SHOPLIST_CONFIG_H
#define __SHOPLIST_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//积分商店表配置数据结构
struct ShoplistElement
{
	friend class ShoplistTable;
	int id;                      	//商店ID	填写ID即可
	string comment;              	//注释	策划用
	int shop_name;               	//商店名	填写文本ID
	int order;                   	//商店顺序	从低至高排列
	int currency;                	//货币ID	货币表货币ID
	int condition;               	//限制条件文本	填写文本ID
	vector<int> source;          	//货币来源	类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留

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
	ShoplistElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//积分商店表配置封装类
class ShoplistTable
{
	friend class TableData;
private:
	ShoplistTable(){}
	~ShoplistTable(){}
	map<int, ShoplistElement>	m_mapElements;
	vector<ShoplistElement>	m_vecAllElements;
	ShoplistElement m_emptyItem;
public:
	static ShoplistTable& Instance()
	{
		static ShoplistTable sInstance;
		return sInstance;
	}

	ShoplistElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ShoplistElement>&	GetAllElement()
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
		if( LoadConfigContent("Shoplist.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Shoplist.bin", strTableContent ) )
		{
			printf_message("配置文件[Shoplist.bin]未找到");
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
			printf_message("Shoplist.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Shoplist.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Shoplist.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="shop_name"){printf_message("Shoplist.csv中字段[shop_name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="order"){printf_message("Shoplist.csv中字段[order]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="currency"){printf_message("Shoplist.csv中字段[currency]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="condition"){printf_message("Shoplist.csv中字段[condition]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="source"){printf_message("Shoplist.csv中字段[source]位置不对应 ");assert(false); return false; }

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
			ShoplistElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.shop_name=(int)atoi(vecLine[2].c_str());
			member.order=(int)atoi(vecLine[3].c_str());
			member.currency=(int)atoi(vecLine[4].c_str());
			member.condition=(int)atoi(vecLine[5].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
