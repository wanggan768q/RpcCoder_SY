#ifndef __MONTHLYSIGNIN_CONFIG_H
#define __MONTHLYSIGNIN_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//月签表配置数据结构
struct MonthlySignInElement
{
	friend class MonthlySignInTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int required_days;           	//需求签到天数	
	vector<int> signin_reward1_id;	//签到奖励1	道具ID|数量|是否需要中转
	vector<int> signin_reward2_id;	//签到奖励2	道具ID|数量|是否需要中转
	vector<int> signin_reward3_id;	//签到奖励3	道具ID|数量|是否需要中转
	vector<int> signin_reward4_id;	//签到奖励4	道具ID|数量|是否需要中转

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
	MonthlySignInElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//月签表配置封装类
class MonthlySignInTable
{
	friend class TableData;
private:
	MonthlySignInTable(){}
	~MonthlySignInTable(){}
	map<int, MonthlySignInElement>	m_mapElements;
	vector<MonthlySignInElement>	m_vecAllElements;
	MonthlySignInElement m_emptyItem;
public:
	static MonthlySignInTable& Instance()
	{
		static MonthlySignInTable sInstance;
		return sInstance;
	}

	MonthlySignInElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MonthlySignInElement>&	GetAllElement()
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
		if( LoadConfigContent("MonthlySignIn.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("MonthlySignIn.bin", strTableContent ) )
		{
			printf_message("配置文件[MonthlySignIn.bin]未找到");
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
			printf_message("MonthlySignIn.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("MonthlySignIn.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("MonthlySignIn.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="required_days"){printf_message("MonthlySignIn.csv中字段[required_days]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="signin_reward1_id"){printf_message("MonthlySignIn.csv中字段[signin_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="signin_reward2_id"){printf_message("MonthlySignIn.csv中字段[signin_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="signin_reward3_id"){printf_message("MonthlySignIn.csv中字段[signin_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="signin_reward4_id"){printf_message("MonthlySignIn.csv中字段[signin_reward4_id]位置不对应 ");assert(false); return false; }

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
			MonthlySignInElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.required_days=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
