#ifndef __DROPRATE_CONFIG_H
#define __DROPRATE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//概率掉落表配置数据结构
struct DropRateElement
{
	friend class DropRateTable;
	int id;                      	//掉落id	掉落id
	string comment;              	//掉落注释	策划用
	int experience;              	//经验值	掉落的经验值
	int transit_tag;             	//中转标签	0表示不需要中转 1表示需要中转
	float gold_rate;             	//银币掉率	掉落银币的概率
	vector<int> gold_range;      	//银币区间	区间下限|区间上限
	vector<int> heap_range;      	//银币堆数区间	堆数区间1|堆数区间2
	int Binding;                 	//是否绑定	该掉落包中的绑定状态 0：不绑定 1：拾取绑定 2：装备绑定 
	vector<int> drop_info1;      	//掉落信息1	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和2时，掉落数量无效
	vector<int> drop_info2;      	//掉落信息2	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和3时，掉落数量无效
	vector<int> drop_info3;      	//掉落信息3	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和4时，掉落数量无效
	vector<int> drop_info4;      	//掉落信息4	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和5时，掉落数量无效
	vector<int> drop_info5;      	//掉落信息5	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和6时，掉落数量无效
	vector<int> drop_info6;      	//掉落信息6	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和7时，掉落数量无效
	vector<int> drop_info7;      	//掉落信息7	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和8时，掉落数量无效
	vector<int> drop_info8;      	//掉落信息8	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和9时，掉落数量无效
	vector<int> drop_info9;      	//掉落信息9	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和10时，掉落数量无效
	vector<int> drop_info10;     	//掉落信息10	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和11时，掉落数量无效
	vector<int> drop_info11;     	//掉落信息11	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和12时，掉落数量无效
	vector<int> drop_info12;     	//掉落信息12	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和13时，掉落数量无效
	vector<int> drop_info13;     	//掉落信息13	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和14时，掉落数量无效
	vector<int> drop_info14;     	//掉落信息14	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和15时，掉落数量无效
	vector<int> drop_info15;     	//掉落信息15	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和16时，掉落数量无效
	vector<int> drop_info16;     	//掉落信息16	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和17时，掉落数量无效
	vector<int> drop_info17;     	//掉落信息17	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和18时，掉落数量无效
	vector<int> drop_info18;     	//掉落信息18	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和19时，掉落数量无效
	vector<int> drop_info19;     	//掉落信息19	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和20时，掉落数量无效
	vector<int> drop_info20;     	//掉落信息20	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和21时，掉落数量无效

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
	DropRateElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//概率掉落表配置封装类
class DropRateTable
{
	friend class TableData;
private:
	DropRateTable(){}
	~DropRateTable(){}
	map<int, DropRateElement>	m_mapElements;
	vector<DropRateElement>	m_vecAllElements;
	DropRateElement m_emptyItem;
public:
	static DropRateTable& Instance()
	{
		static DropRateTable sInstance;
		return sInstance;
	}

	DropRateElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DropRateElement>&	GetAllElement()
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
		if( LoadConfigContent("DropRate.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("DropRate.bin", strTableContent ) )
		{
			printf_message("配置文件[DropRate.bin]未找到");
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
		if(vecLine.size() != 28)
		{
			printf_message("DropRate.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("DropRate.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("DropRate.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="experience"){printf_message("DropRate.csv中字段[experience]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="transit_tag"){printf_message("DropRate.csv中字段[transit_tag]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="gold_rate"){printf_message("DropRate.csv中字段[gold_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="gold_range"){printf_message("DropRate.csv中字段[gold_range]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="heap_range"){printf_message("DropRate.csv中字段[heap_range]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="Binding"){printf_message("DropRate.csv中字段[Binding]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="drop_info1"){printf_message("DropRate.csv中字段[drop_info1]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="drop_info2"){printf_message("DropRate.csv中字段[drop_info2]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="drop_info3"){printf_message("DropRate.csv中字段[drop_info3]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="drop_info4"){printf_message("DropRate.csv中字段[drop_info4]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="drop_info5"){printf_message("DropRate.csv中字段[drop_info5]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="drop_info6"){printf_message("DropRate.csv中字段[drop_info6]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="drop_info7"){printf_message("DropRate.csv中字段[drop_info7]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="drop_info8"){printf_message("DropRate.csv中字段[drop_info8]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="drop_info9"){printf_message("DropRate.csv中字段[drop_info9]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="drop_info10"){printf_message("DropRate.csv中字段[drop_info10]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="drop_info11"){printf_message("DropRate.csv中字段[drop_info11]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="drop_info12"){printf_message("DropRate.csv中字段[drop_info12]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="drop_info13"){printf_message("DropRate.csv中字段[drop_info13]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="drop_info14"){printf_message("DropRate.csv中字段[drop_info14]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="drop_info15"){printf_message("DropRate.csv中字段[drop_info15]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="drop_info16"){printf_message("DropRate.csv中字段[drop_info16]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="drop_info17"){printf_message("DropRate.csv中字段[drop_info17]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="drop_info18"){printf_message("DropRate.csv中字段[drop_info18]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="drop_info19"){printf_message("DropRate.csv中字段[drop_info19]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="drop_info20"){printf_message("DropRate.csv中字段[drop_info20]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)28)
			{
				assert(false);
				return false;
			}
			DropRateElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.experience=(int)atoi(vecLine[2].c_str());
			member.transit_tag=(int)atoi(vecLine[3].c_str());
			member.gold_rate=(float)atof(vecLine[4].c_str());
			member.Binding=(int)atoi(vecLine[7].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
