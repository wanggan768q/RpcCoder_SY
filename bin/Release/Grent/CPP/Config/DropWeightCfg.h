#ifndef __DROPWEIGHT_CONFIG_H
#define __DROPWEIGHT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//权值掉落表配置数据结构
struct DropWeightElement
{
	friend class DropWeightTable;
	int id;                      	//掉落id	掉落id
	string comment;              	//掉落注释	策划用
	int transit_tag;             	//中转标签	0：不需要中转 1：需要中转
	int pick_num;                	//选择数量	选择数量 （在所有Drop_info中选择的数量）
	int Binding;                 	//是否绑定	该掉落包中的绑定状态 0：不绑定 1：拾取绑定 2：装备绑定 
	vector<int> drop_info1;      	//掉落信息1	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info2;      	//掉落信息2	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info3;      	//掉落信息3	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info4;      	//掉落信息4	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info5;      	//掉落信息5	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info6;      	//掉落信息6	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info7;      	//掉落信息7	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info8;      	//掉落信息8	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info9;      	//掉落信息9	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info10;     	//掉落信息10	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info11;     	//掉落信息11	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info12;     	//掉落信息12	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info13;     	//掉落信息13	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info14;     	//掉落信息14	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info15;     	//掉落信息15	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info16;     	//掉落信息16	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info17;     	//掉落信息17	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info18;     	//掉落信息18	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info19;     	//掉落信息19	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用
	vector<int> drop_info20;     	//掉落信息20	掉落类型|掉落ID|掉落数量|权值 0：物品ID 1：单独掉落包ID 2：权值掉落包ID 如果掉落类型是1或2，则掉落数量不使用

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
	DropWeightElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//权值掉落表配置封装类
class DropWeightTable
{
	friend class TableData;
private:
	DropWeightTable(){}
	~DropWeightTable(){}
	map<int, DropWeightElement>	m_mapElements;
	vector<DropWeightElement>	m_vecAllElements;
	DropWeightElement m_emptyItem;
public:
	static DropWeightTable& Instance()
	{
		static DropWeightTable sInstance;
		return sInstance;
	}

	DropWeightElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DropWeightElement>&	GetAllElement()
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
		if( LoadConfigContent("DropWeight.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("DropWeight.bin", strTableContent ) )
		{
			printf_message("配置文件[DropWeight.bin]未找到");
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
		if(vecLine.size() != 25)
		{
			printf_message("DropWeight.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("DropWeight.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("DropWeight.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="transit_tag"){printf_message("DropWeight.csv中字段[transit_tag]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="pick_num"){printf_message("DropWeight.csv中字段[pick_num]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="Binding"){printf_message("DropWeight.csv中字段[Binding]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="drop_info1"){printf_message("DropWeight.csv中字段[drop_info1]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="drop_info2"){printf_message("DropWeight.csv中字段[drop_info2]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="drop_info3"){printf_message("DropWeight.csv中字段[drop_info3]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="drop_info4"){printf_message("DropWeight.csv中字段[drop_info4]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="drop_info5"){printf_message("DropWeight.csv中字段[drop_info5]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="drop_info6"){printf_message("DropWeight.csv中字段[drop_info6]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="drop_info7"){printf_message("DropWeight.csv中字段[drop_info7]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="drop_info8"){printf_message("DropWeight.csv中字段[drop_info8]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="drop_info9"){printf_message("DropWeight.csv中字段[drop_info9]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="drop_info10"){printf_message("DropWeight.csv中字段[drop_info10]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="drop_info11"){printf_message("DropWeight.csv中字段[drop_info11]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="drop_info12"){printf_message("DropWeight.csv中字段[drop_info12]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="drop_info13"){printf_message("DropWeight.csv中字段[drop_info13]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="drop_info14"){printf_message("DropWeight.csv中字段[drop_info14]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="drop_info15"){printf_message("DropWeight.csv中字段[drop_info15]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="drop_info16"){printf_message("DropWeight.csv中字段[drop_info16]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="drop_info17"){printf_message("DropWeight.csv中字段[drop_info17]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="drop_info18"){printf_message("DropWeight.csv中字段[drop_info18]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="drop_info19"){printf_message("DropWeight.csv中字段[drop_info19]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="drop_info20"){printf_message("DropWeight.csv中字段[drop_info20]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)25)
			{
				assert(false);
				return false;
			}
			DropWeightElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.transit_tag=(int)atoi(vecLine[2].c_str());
			member.pick_num=(int)atoi(vecLine[3].c_str());
			member.Binding=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
