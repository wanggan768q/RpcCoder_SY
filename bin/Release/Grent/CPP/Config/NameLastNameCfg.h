#ifndef __NAMELASTNAME_CONFIG_H
#define __NAMELASTNAME_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色姓氏配置数据结构
struct NameLastNameElement
{
	friend class NameLastNameTable;
	int id;                      	//序号	序号 =种族*10000+序号
	string comment;              	//备注	标记用
	int race;                    	//种族	用来区分随机名称的种族 暂时无作用 0.通用 1.人类 2.精灵 3.兽人 4.矮人
	string sc;                   	//中文文本	该条目对应的中文文本
	string en;                   	//英文文本	该条目对应的英文文本

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
	NameLastNameElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色姓氏配置封装类
class NameLastNameTable
{
	friend class TableData;
private:
	NameLastNameTable(){}
	~NameLastNameTable(){}
	map<int, NameLastNameElement>	m_mapElements;
	vector<NameLastNameElement>	m_vecAllElements;
	NameLastNameElement m_emptyItem;
public:
	static NameLastNameTable& Instance()
	{
		static NameLastNameTable sInstance;
		return sInstance;
	}

	NameLastNameElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<NameLastNameElement>&	GetAllElement()
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
		if( LoadConfigContent("NameLastName.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("NameLastName.bin", strTableContent ) )
		{
			printf_message("配置文件[NameLastName.bin]未找到");
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
			printf_message("NameLastName.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("NameLastName.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("NameLastName.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="race"){printf_message("NameLastName.csv中字段[race]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="sc"){printf_message("NameLastName.csv中字段[sc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="en"){printf_message("NameLastName.csv中字段[en]位置不对应 ");assert(false); return false; }

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
			NameLastNameElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.race=(int)atoi(vecLine[2].c_str());
			member.sc=vecLine[3];
			member.en=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
