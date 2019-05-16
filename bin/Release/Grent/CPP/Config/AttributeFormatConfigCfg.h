#ifndef __ATTRIBUTEFORMATCONFIG_CONFIG_H
#define __ATTRIBUTEFORMATCONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//战斗属性配置数据结构
struct AttributeFormatConfigElement
{
	friend class AttributeFormatConfigTable;
	int id;                      	//ID	添加需要 通知程序
	string comment;              	//属性中文名	仅策划用
	int nameid;                  	//属性名称ID	属性名称ID
	int type;                    	//属性显示	0：显示数字 1：显示百分比
	string des;                  	//属性说明	仅策划用
	int desid;                   	//属性说明ID	属性说明ID
	vector<float> weight;        	//战力权重	战力=[计算单位|战力权重]
	string refine_name;          	//洗练名称	对应该属性在装备后缀表的字段名

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
	AttributeFormatConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//战斗属性配置封装类
class AttributeFormatConfigTable
{
	friend class TableData;
private:
	AttributeFormatConfigTable(){}
	~AttributeFormatConfigTable(){}
	map<int, AttributeFormatConfigElement>	m_mapElements;
	vector<AttributeFormatConfigElement>	m_vecAllElements;
	AttributeFormatConfigElement m_emptyItem;
public:
	static AttributeFormatConfigTable& Instance()
	{
		static AttributeFormatConfigTable sInstance;
		return sInstance;
	}

	AttributeFormatConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AttributeFormatConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("AttributeFormatConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AttributeFormatConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[AttributeFormatConfig.bin]未找到");
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
			printf_message("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AttributeFormatConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("AttributeFormatConfig.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="nameid"){printf_message("AttributeFormatConfig.csv中字段[nameid]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("AttributeFormatConfig.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="des"){printf_message("AttributeFormatConfig.csv中字段[des]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="desid"){printf_message("AttributeFormatConfig.csv中字段[desid]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="weight"){printf_message("AttributeFormatConfig.csv中字段[weight]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="refine_name"){printf_message("AttributeFormatConfig.csv中字段[refine_name]位置不对应 ");assert(false); return false; }

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
			AttributeFormatConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.nameid=(int)atoi(vecLine[2].c_str());
			member.type=(int)atoi(vecLine[3].c_str());
			member.des=vecLine[4];
			member.desid=(int)atoi(vecLine[5].c_str());
			member.refine_name=vecLine[7];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
