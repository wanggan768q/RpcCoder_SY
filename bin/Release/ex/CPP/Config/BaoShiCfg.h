#ifndef __BAOSHI_CONFIG_H
#define __BAOSHI_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝石配置数据结构
struct BaoShiElement
{
	friend class BaoShiTable;
	int ID;                      	//编号	宝石ID
	int Type;                    	//宝石类别	宝石类别
	int Lv;                      	//宝石等级	宝石等级
	int Limit;                   	//镶嵌限制	镶嵌限制
	ls AttrWuQi;                 	//属性类别-武器	属性类别-武器
	li NumWuQi;                  	//属性参数1	属性参数1
	lf AttrOther;                	//属性类别-其他	属性类别-其他
	string NumOther;             	//属性参数2	属性参数2
	int HeCheng;                 	//合成后的宝石	合成后的宝石

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
	BaoShiElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//宝石配置封装类
class BaoShiTable
{
	friend class TableData;
private:
	BaoShiTable(){}
	~BaoShiTable(){}
	map<int, BaoShiElement>	m_mapElements;
	vector<BaoShiElement>	m_vecAllElements;
	BaoShiElement m_emptyItem;
public:
	static BaoShiTable& Instance()
	{
		static BaoShiTable sInstance;
		return sInstance;
	}

	BaoShiElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BaoShiElement>&	GetAllElement()
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
		if( LoadConfigContent("BaoShi.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BaoShi.bin", strTableContent ) )
		{
			printf_message("配置文件[BaoShi.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("BaoShi.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BaoShi.csv中字段[ID]位置不对应");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("BaoShi.csv中字段[Type]位置不对应");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("BaoShi.csv中字段[Lv]位置不对应");assert(false); return false; }
		if(vecLine[3]!="Limit"){printf_message("BaoShi.csv中字段[Limit]位置不对应");assert(false); return false; }
		if(vecLine[4]!="AttrWuQi"){printf_message("BaoShi.csv中字段[AttrWuQi]位置不对应");assert(false); return false; }
		if(vecLine[5]!="NumWuQi"){printf_message("BaoShi.csv中字段[NumWuQi]位置不对应");assert(false); return false; }
		if(vecLine[6]!="AttrOther"){printf_message("BaoShi.csv中字段[AttrOther]位置不对应");assert(false); return false; }
		if(vecLine[7]!="NumOther"){printf_message("BaoShi.csv中字段[NumOther]位置不对应");assert(false); return false; }
		if(vecLine[8]!="HeCheng"){printf_message("BaoShi.csv中字段[HeCheng]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			BaoShiElement	member;
			member.ID=atoi(vecLine[0].c_str());
			member.Type=atoi(vecLine[1].c_str());
			member.Lv=atoi(vecLine[2].c_str());
			member.Limit=atoi(vecLine[3].c_str());
			member.AttrWuQi=vecLine[4];
			member.NumWuQi=vecLine[5];
			member.AttrOther=vecLine[6];
			member.NumOther=vecLine[7];
			member.HeCheng=atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
		}
		return true;
	}
};

#endif
