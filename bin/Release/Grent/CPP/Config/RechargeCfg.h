#ifndef __RECHARGE_CONFIG_H
#define __RECHARGE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//充值商品表配置数据结构
struct RechargeElement
{
	friend class RechargeTable;
	int id;                      	//主键id	商品id
	string comment;              	//注释	
	int weight;                  	//页面显示权重	必须是 1～N
	int nameId;                  	//名称id	
	string iconName;             	//图片名称	
	int active;                  	//是否可用	0 禁用 1 启用
	int recommend;               	//是否推荐	0 禁用 1 启用
	int productType;             	//商品类型	1 货币 2 礼包
	int productPrice;            	//商品价格	人民币
	int productDiamond;          	//商品钻石数	
	int productBindDiamond;      	//商品数	
	int productBagId;            	//商品礼包id	

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
	RechargeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//充值商品表配置封装类
class RechargeTable
{
	friend class TableData;
private:
	RechargeTable(){}
	~RechargeTable(){}
	map<int, RechargeElement>	m_mapElements;
	vector<RechargeElement>	m_vecAllElements;
	RechargeElement m_emptyItem;
public:
	static RechargeTable& Instance()
	{
		static RechargeTable sInstance;
		return sInstance;
	}

	RechargeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RechargeElement>&	GetAllElement()
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
		if( LoadConfigContent("Recharge.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Recharge.bin", strTableContent ) )
		{
			printf_message("配置文件[Recharge.bin]未找到");
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
		if(vecLine.size() != 12)
		{
			printf_message("Recharge.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Recharge.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Recharge.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="weight"){printf_message("Recharge.csv中字段[weight]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="nameId"){printf_message("Recharge.csv中字段[nameId]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="iconName"){printf_message("Recharge.csv中字段[iconName]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="active"){printf_message("Recharge.csv中字段[active]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="recommend"){printf_message("Recharge.csv中字段[recommend]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="productType"){printf_message("Recharge.csv中字段[productType]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="productPrice"){printf_message("Recharge.csv中字段[productPrice]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="productDiamond"){printf_message("Recharge.csv中字段[productDiamond]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="productBindDiamond"){printf_message("Recharge.csv中字段[productBindDiamond]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="productBagId"){printf_message("Recharge.csv中字段[productBagId]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			RechargeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.weight=(int)atoi(vecLine[2].c_str());
			member.nameId=(int)atoi(vecLine[3].c_str());
			member.iconName=vecLine[4];
			member.active=(int)atoi(vecLine[5].c_str());
			member.recommend=(int)atoi(vecLine[6].c_str());
			member.productType=(int)atoi(vecLine[7].c_str());
			member.productPrice=(int)atoi(vecLine[8].c_str());
			member.productDiamond=(int)atoi(vecLine[9].c_str());
			member.productBindDiamond=(int)atoi(vecLine[10].c_str());
			member.productBagId=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
