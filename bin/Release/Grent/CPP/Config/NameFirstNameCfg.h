#ifndef __NAMEFIRSTNAME_CONFIG_H
#define __NAMEFIRSTNAME_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色名字配置数据结构
struct NameFirstNameElement
{
	friend class NameFirstNameTable;
	int id;                      	//序号	序号 = 性别*10000+备注
	string comment;              	//备注	标记用
	int gender;                  	//性别	用来区分随机名称的性别 0.通用 1.男性 2.女性
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
	NameFirstNameElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色名字配置封装类
class NameFirstNameTable
{
	friend class TableData;
private:
	NameFirstNameTable(){}
	~NameFirstNameTable(){}
	map<int, NameFirstNameElement>	m_mapElements;
	vector<NameFirstNameElement>	m_vecAllElements;
	NameFirstNameElement m_emptyItem;
public:
	static NameFirstNameTable& Instance()
	{
		static NameFirstNameTable sInstance;
		return sInstance;
	}

	NameFirstNameElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<NameFirstNameElement>&	GetAllElement()
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
		if( LoadConfigContent("NameFirstName.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("NameFirstName.bin", strTableContent ) )
		{
			printf_message("配置文件[NameFirstName.bin]未找到");
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
			printf_message("NameFirstName.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("NameFirstName.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("NameFirstName.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="gender"){printf_message("NameFirstName.csv中字段[gender]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="sc"){printf_message("NameFirstName.csv中字段[sc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="en"){printf_message("NameFirstName.csv中字段[en]位置不对应 ");assert(false); return false; }

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
			NameFirstNameElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.gender=(int)atoi(vecLine[2].c_str());
			member.sc=vecLine[3];
			member.en=vecLine[4];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
