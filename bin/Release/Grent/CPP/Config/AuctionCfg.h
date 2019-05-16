#ifndef __AUCTION_CONFIG_H
#define __AUCTION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//交易行表配置数据结构
struct AuctionElement
{
	friend class AuctionTable;
	int id;                      	//道具ID	道具ID
	string comment;              	//道具注释	策划用
	string type;                 	//道具1级类	策划用
	int type_name;               	//大类名称	用于显示， 从StringItem表中获取
	string subtype;              	//道具子类	策划用
	int subtype_name;            	//子类名称	用于显示， 从StringItem表中获取
	vector<int> price_range;     	//道具推荐单价幅度	可交易道具的价值区间 单位为金币
	vector<int> price_range_diamond;	//道具推荐单价幅度	可交易道具的价值区间 单位为钻石
	int is_publicity;            	//是否需要公示	0：上架无需上架 1：上架需要公示(可堆叠道具不可配置公示)
	int type_coin;               	//可交易货币类型	1：仅金币交易 2：仅钻石交易 -1：金币和钻石交易
	int benchmark_price;         	//开服基准价	0：非定价商品
	vector<int> benchmark_price_range;	//基准价浮动范围	基准价浮动范围
	vector<float> benchmark_price_ratio;	//基准价浮动系数	基准价浮动系数
	int type_item;               	//归属类型道具	归属类型道具

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
	AuctionElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//交易行表配置封装类
class AuctionTable
{
	friend class TableData;
private:
	AuctionTable(){}
	~AuctionTable(){}
	map<int, AuctionElement>	m_mapElements;
	vector<AuctionElement>	m_vecAllElements;
	AuctionElement m_emptyItem;
public:
	static AuctionTable& Instance()
	{
		static AuctionTable sInstance;
		return sInstance;
	}

	AuctionElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AuctionElement>&	GetAllElement()
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
		if( LoadConfigContent("Auction.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Auction.bin", strTableContent ) )
		{
			printf_message("配置文件[Auction.bin]未找到");
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
		if(vecLine.size() != 14)
		{
			printf_message("Auction.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Auction.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Auction.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="type"){printf_message("Auction.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type_name"){printf_message("Auction.csv中字段[type_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="subtype"){printf_message("Auction.csv中字段[subtype]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="subtype_name"){printf_message("Auction.csv中字段[subtype_name]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="price_range"){printf_message("Auction.csv中字段[price_range]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="price_range_diamond"){printf_message("Auction.csv中字段[price_range_diamond]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="is_publicity"){printf_message("Auction.csv中字段[is_publicity]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="type_coin"){printf_message("Auction.csv中字段[type_coin]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="benchmark_price"){printf_message("Auction.csv中字段[benchmark_price]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="benchmark_price_range"){printf_message("Auction.csv中字段[benchmark_price_range]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="benchmark_price_ratio"){printf_message("Auction.csv中字段[benchmark_price_ratio]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="type_item"){printf_message("Auction.csv中字段[type_item]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)14)
			{
				assert(false);
				return false;
			}
			AuctionElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.type=vecLine[2];
			member.type_name=(int)atoi(vecLine[3].c_str());
			member.subtype=vecLine[4];
			member.subtype_name=(int)atoi(vecLine[5].c_str());
			member.is_publicity=(int)atoi(vecLine[8].c_str());
			member.type_coin=(int)atoi(vecLine[9].c_str());
			member.benchmark_price=(int)atoi(vecLine[10].c_str());
			member.type_item=(int)atoi(vecLine[13].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
