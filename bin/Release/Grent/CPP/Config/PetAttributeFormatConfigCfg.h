#ifndef __PETATTRIBUTEFORMATCONFIG_CONFIG_H
#define __PETATTRIBUTEFORMATCONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物资质属性表配置数据结构
struct PetAttributeFormatConfigElement
{
	friend class PetAttributeFormatConfigTable;
	int id;                      	//ID	添加需要 通知程序
	string comment;              	//备注	仅策划用
	int name;                    	//属性名称ID	属性名称ID
	int type;                    	//属性显示	0：显示数字 1：显示百分比
	int desc;                    	//属性说明ID	属性说明ID
	vector<int> attr;            	//对应属性	该资质对应 生效的属性

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
	PetAttributeFormatConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物资质属性表配置封装类
class PetAttributeFormatConfigTable
{
	friend class TableData;
private:
	PetAttributeFormatConfigTable(){}
	~PetAttributeFormatConfigTable(){}
	map<int, PetAttributeFormatConfigElement>	m_mapElements;
	vector<PetAttributeFormatConfigElement>	m_vecAllElements;
	PetAttributeFormatConfigElement m_emptyItem;
public:
	static PetAttributeFormatConfigTable& Instance()
	{
		static PetAttributeFormatConfigTable sInstance;
		return sInstance;
	}

	PetAttributeFormatConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetAttributeFormatConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("PetAttributeFormatConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetAttributeFormatConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[PetAttributeFormatConfig.bin]未找到");
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
		if(vecLine.size() != 6)
		{
			printf_message("PetAttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetAttributeFormatConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetAttributeFormatConfig.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("PetAttributeFormatConfig.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("PetAttributeFormatConfig.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="desc"){printf_message("PetAttributeFormatConfig.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="attr"){printf_message("PetAttributeFormatConfig.csv中字段[attr]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)6)
			{
				assert(false);
				return false;
			}
			PetAttributeFormatConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.type=(int)atoi(vecLine[3].c_str());
			member.desc=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
