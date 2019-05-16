#ifndef __ITEMSOURCE_CONFIG_H
#define __ITEMSOURCE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//道具来源配置数据结构
struct ItemSourceElement
{
	friend class ItemSourceTable;
	int id;                      	//道具ID	最好和itemProto保持一致
	string comment;              	//道具注释	策划用
	int count;                   	//来源数量	该道具来源条目数量
	vector<int> source_1;        	//来源1	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_2;        	//来源2	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_3;        	//来源3	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_4;        	//来源4	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_5;        	//来源5	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_6;        	//来源6	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_7;        	//来源7	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_8;        	//来源8	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_9;        	//来源9	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_10;       	//来源10	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_11;       	//来源11	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_12;       	//来源12	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_13;       	//来源13	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_14;       	//来源14	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	vector<int> source_15;       	//来源15	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留

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
	ItemSourceElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//道具来源配置封装类
class ItemSourceTable
{
	friend class TableData;
private:
	ItemSourceTable(){}
	~ItemSourceTable(){}
	map<int, ItemSourceElement>	m_mapElements;
	vector<ItemSourceElement>	m_vecAllElements;
	ItemSourceElement m_emptyItem;
public:
	static ItemSourceTable& Instance()
	{
		static ItemSourceTable sInstance;
		return sInstance;
	}

	ItemSourceElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ItemSourceElement>&	GetAllElement()
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
		if( LoadConfigContent("ItemSource.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ItemSource.bin", strTableContent ) )
		{
			printf_message("配置文件[ItemSource.bin]未找到");
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
		if(vecLine.size() != 18)
		{
			printf_message("ItemSource.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ItemSource.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ItemSource.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="count"){printf_message("ItemSource.csv中字段[count]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="source_1"){printf_message("ItemSource.csv中字段[source_1]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="source_2"){printf_message("ItemSource.csv中字段[source_2]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="source_3"){printf_message("ItemSource.csv中字段[source_3]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="source_4"){printf_message("ItemSource.csv中字段[source_4]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="source_5"){printf_message("ItemSource.csv中字段[source_5]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="source_6"){printf_message("ItemSource.csv中字段[source_6]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="source_7"){printf_message("ItemSource.csv中字段[source_7]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="source_8"){printf_message("ItemSource.csv中字段[source_8]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="source_9"){printf_message("ItemSource.csv中字段[source_9]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="source_10"){printf_message("ItemSource.csv中字段[source_10]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="source_11"){printf_message("ItemSource.csv中字段[source_11]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="source_12"){printf_message("ItemSource.csv中字段[source_12]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="source_13"){printf_message("ItemSource.csv中字段[source_13]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="source_14"){printf_message("ItemSource.csv中字段[source_14]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="source_15"){printf_message("ItemSource.csv中字段[source_15]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)18)
			{
				assert(false);
				return false;
			}
			ItemSourceElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.count=(int)atoi(vecLine[2].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
