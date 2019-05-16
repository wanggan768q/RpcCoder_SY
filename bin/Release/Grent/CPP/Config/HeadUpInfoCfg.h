#ifndef __HEADUPINFO_CONFIG_H
#define __HEADUPINFO_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//头顶信息表配置数据结构
struct HeadUpInfoElement
{
	friend class HeadUpInfoTable;
	int id;                      	//序号	
	string comment;              	//注释	策划用
	int priority;                	//显示优先级	优先级越低，显示位置越靠下
	float interspace;            	//元件间距	该元件距离下一层元件中心的距离（3D数值）

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
	HeadUpInfoElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//头顶信息表配置封装类
class HeadUpInfoTable
{
	friend class TableData;
private:
	HeadUpInfoTable(){}
	~HeadUpInfoTable(){}
	map<int, HeadUpInfoElement>	m_mapElements;
	vector<HeadUpInfoElement>	m_vecAllElements;
	HeadUpInfoElement m_emptyItem;
public:
	static HeadUpInfoTable& Instance()
	{
		static HeadUpInfoTable sInstance;
		return sInstance;
	}

	HeadUpInfoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<HeadUpInfoElement>&	GetAllElement()
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
		if( LoadConfigContent("HeadUpInfo.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("HeadUpInfo.bin", strTableContent ) )
		{
			printf_message("配置文件[HeadUpInfo.bin]未找到");
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
			printf_message("HeadUpInfo.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("HeadUpInfo.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("HeadUpInfo.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="priority"){printf_message("HeadUpInfo.csv中字段[priority]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="interspace"){printf_message("HeadUpInfo.csv中字段[interspace]位置不对应 ");assert(false); return false; }

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
			HeadUpInfoElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.priority=(int)atoi(vecLine[2].c_str());
			member.interspace=(float)atof(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
