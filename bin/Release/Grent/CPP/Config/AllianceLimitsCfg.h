#ifndef __ALLIANCELIMITS_CONFIG_H
#define __ALLIANCELIMITS_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//公会权限表配置数据结构
struct AllianceLimitsElement
{
	friend class AllianceLimitsTable;
	int id;                      	//ID	同gloal表
	string comment;              	//注释	策划用
	int stringid;                	//权限名	填写stringid
	int president;               	//会长	有该权限写1没有写-1会长可更改为2
	int vice_president;          	//副会长	有该权限写1没有写-1
	int officer;                 	//官员	有该权限写1没有写-1
	int member;                  	//会员	有该权限写1没有写-1
	int location;                	//权限位置	1为上2为下

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
	AllianceLimitsElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//公会权限表配置封装类
class AllianceLimitsTable
{
	friend class TableData;
private:
	AllianceLimitsTable(){}
	~AllianceLimitsTable(){}
	map<int, AllianceLimitsElement>	m_mapElements;
	vector<AllianceLimitsElement>	m_vecAllElements;
	AllianceLimitsElement m_emptyItem;
public:
	static AllianceLimitsTable& Instance()
	{
		static AllianceLimitsTable sInstance;
		return sInstance;
	}

	AllianceLimitsElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AllianceLimitsElement>&	GetAllElement()
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
		if( LoadConfigContent("AllianceLimits.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AllianceLimits.bin", strTableContent ) )
		{
			printf_message("配置文件[AllianceLimits.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("AllianceLimits.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AllianceLimits.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("AllianceLimits.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="stringid"){printf_message("AllianceLimits.csv中字段[stringid]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="president"){printf_message("AllianceLimits.csv中字段[president]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="vice_president"){printf_message("AllianceLimits.csv中字段[vice_president]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="officer"){printf_message("AllianceLimits.csv中字段[officer]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="member"){printf_message("AllianceLimits.csv中字段[member]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="location"){printf_message("AllianceLimits.csv中字段[location]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			AllianceLimitsElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.stringid=(int)atoi(vecLine[2].c_str());
			member.president=(int)atoi(vecLine[3].c_str());
			member.vice_president=(int)atoi(vecLine[4].c_str());
			member.officer=(int)atoi(vecLine[5].c_str());
			member.member=(int)atoi(vecLine[6].c_str());
			member.location=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
