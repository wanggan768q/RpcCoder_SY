#ifndef __MIXINFO_CONFIG_H
#define __MIXINFO_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//合成数据表配置数据结构
struct MixInfoElement
{
	friend class MixInfoTable;
	int id;                      	//合成道具id	该道具的id
	string comment;              	//阶级注释	策划用
	int type;                    	//合成类型	道具所属的标签类型
	int ytpe_name;               	//类型名称	道具所属的标签类型名称 对应string_ui
	vector<int> demand1;         	//合成信息1	合成所需物品的id|数量|失败消耗数
	vector<int> demand2;         	//合成信息2	合成所需物品的id|数量|失败消耗数
	vector<int> demand3;         	//合成信息3	合成所需物品的id|数量|失败消耗数
	int mix_cost;                	//合成花费	合成所需花费的银币数量
	int mix_probability;         	//合成成功率	合成该道具的成功率（暂不使用）
	int avoid_fail;              	//保护道具	可防止合成失败的道具id(暂不使用）
	int avoid_num;               	//保护道具数量	防止合成失败的道具数量（暂不使用）

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
	MixInfoElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//合成数据表配置封装类
class MixInfoTable
{
	friend class TableData;
private:
	MixInfoTable(){}
	~MixInfoTable(){}
	map<int, MixInfoElement>	m_mapElements;
	vector<MixInfoElement>	m_vecAllElements;
	MixInfoElement m_emptyItem;
public:
	static MixInfoTable& Instance()
	{
		static MixInfoTable sInstance;
		return sInstance;
	}

	MixInfoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MixInfoElement>&	GetAllElement()
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
		if( LoadConfigContent("MixInfo.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("MixInfo.bin", strTableContent ) )
		{
			printf_message("配置文件[MixInfo.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("MixInfo.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("MixInfo.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("MixInfo.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="type"){printf_message("MixInfo.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="ytpe_name"){printf_message("MixInfo.csv中字段[ytpe_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="demand1"){printf_message("MixInfo.csv中字段[demand1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="demand2"){printf_message("MixInfo.csv中字段[demand2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="demand3"){printf_message("MixInfo.csv中字段[demand3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="mix_cost"){printf_message("MixInfo.csv中字段[mix_cost]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="mix_probability"){printf_message("MixInfo.csv中字段[mix_probability]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="avoid_fail"){printf_message("MixInfo.csv中字段[avoid_fail]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="avoid_num"){printf_message("MixInfo.csv中字段[avoid_num]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			MixInfoElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.type=(int)atoi(vecLine[2].c_str());
			member.ytpe_name=(int)atoi(vecLine[3].c_str());
			member.mix_cost=(int)atoi(vecLine[7].c_str());
			member.mix_probability=(int)atoi(vecLine[8].c_str());
			member.avoid_fail=(int)atoi(vecLine[9].c_str());
			member.avoid_num=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
