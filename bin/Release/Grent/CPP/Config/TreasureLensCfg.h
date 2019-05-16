#ifndef __TREASURELENS_CONFIG_H
#define __TREASURELENS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝物库镜头表配置数据结构
struct TreasureLensElement
{
	friend class TreasureLensTable;
	int id;                      	//ID	
	string comment;              	//道具注释	策划用
	float lens_depression;       	//镜头俯角	主摄像机的俯角
	float lens_distance;         	//镜头距人物距离	主摄像机距离人物的距离

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
	TreasureLensElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宝物库镜头表配置封装类
class TreasureLensTable
{
	friend class TableData;
private:
	TreasureLensTable(){}
	~TreasureLensTable(){}
	map<int, TreasureLensElement>	m_mapElements;
	vector<TreasureLensElement>	m_vecAllElements;
	TreasureLensElement m_emptyItem;
public:
	static TreasureLensTable& Instance()
	{
		static TreasureLensTable sInstance;
		return sInstance;
	}

	TreasureLensElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TreasureLensElement>&	GetAllElement()
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
		if( LoadConfigContent("TreasureLens.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TreasureLens.bin", strTableContent ) )
		{
			printf_message("配置文件[TreasureLens.bin]未找到");
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
			printf_message("TreasureLens.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TreasureLens.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("TreasureLens.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="lens_depression"){printf_message("TreasureLens.csv中字段[lens_depression]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="lens_distance"){printf_message("TreasureLens.csv中字段[lens_distance]位置不对应 ");assert(false); return false; }

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
			TreasureLensElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.lens_depression=(float)atof(vecLine[2].c_str());
			member.lens_distance=(float)atof(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
