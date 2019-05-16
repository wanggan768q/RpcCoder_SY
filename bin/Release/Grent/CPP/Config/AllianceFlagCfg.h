#ifndef __ALLIANCEFLAG_CONFIG_H
#define __ALLIANCEFLAG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//公会旗帜表配置数据结构
struct AllianceFlagElement
{
	friend class AllianceFlagTable;
	int id;                      	//ID	填写ID即可
	string comment;              	//注释	策划用
	string icon;                 	//旗帜图标	图片名
	string pic;                  	//旗帜图	图片名
	int price;                   	//旗帜价格	填写整数

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
	AllianceFlagElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//公会旗帜表配置封装类
class AllianceFlagTable
{
	friend class TableData;
private:
	AllianceFlagTable(){}
	~AllianceFlagTable(){}
	map<int, AllianceFlagElement>	m_mapElements;
	vector<AllianceFlagElement>	m_vecAllElements;
	AllianceFlagElement m_emptyItem;
public:
	static AllianceFlagTable& Instance()
	{
		static AllianceFlagTable sInstance;
		return sInstance;
	}

	AllianceFlagElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AllianceFlagElement>&	GetAllElement()
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
		if( LoadConfigContent("AllianceFlag.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AllianceFlag.bin", strTableContent ) )
		{
			printf_message("配置文件[AllianceFlag.bin]未找到");
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
			printf_message("AllianceFlag.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AllianceFlag.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("AllianceFlag.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="icon"){printf_message("AllianceFlag.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="pic"){printf_message("AllianceFlag.csv中字段[pic]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="price"){printf_message("AllianceFlag.csv中字段[price]位置不对应 ");assert(false); return false; }

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
			AllianceFlagElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.icon=vecLine[2];
			member.pic=vecLine[3];
			member.price=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
