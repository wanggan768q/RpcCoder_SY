#ifndef __ATTRIBUTEFORMATCONFIG_CONFIG_H
#define __ATTRIBUTEFORMATCONFIG_CONFIG_H

#include "CommonDefine.h"
#include "DK_Assertx.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//战斗属性配置数据结构
struct AttributeFormatConfigElement
{
	friend class AttributeFormatConfigTable;
	int id;                      	//ID	添加需要 通知程序
	string name;                 	//属性中文名	仅策划用
	int nameid;                  	//属性名称ID	属性名称ID
	string des;                  	//属性说明	仅策划用
	int desid;                   	//属性说明ID	属性说明ID
	vector<float> weight;        	//战力权重	格式=[参数1,参数2] 战力等于=[参数2/参数1]

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
	typedef unordered_map<int, AttributeFormatConfigElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<AttributeFormatConfigElement>	m_vecAllElements;
	AttributeFormatConfigElement m_emptyItem;
public:
	static AttributeFormatConfigTable& Instance()
	{
		static AttributeFormatConfigTable sInstance;
		return sInstance;
	}

	const AttributeFormatConfigElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("AttributeFormatConfigTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
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
		#ifdef CONFIG_JSON
		return LoadJson("AttributeFormatConfig.json");
		#else
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
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			AttributeFormatConfigElement	member;

						member.id=p.get<int>("id");
			member.name=p.get<string>("name");
			member.nameid=p.get<int>("nameid");
			member.des=p.get<string>("des");
			member.desid=p.get<int>("desid");
			boost::property_tree::ptree sms_array_childweight = p.get_child("weight");
			for (BOOST_AUTO(pos, sms_array_childweight.begin()); pos != sms_array_childweight.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.weight.push_back(n);
			}


			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}

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
			printf_message("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AttributeFormatConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("AttributeFormatConfig.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="nameid"){printf_message("AttributeFormatConfig.csv中字段[nameid]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="des"){printf_message("AttributeFormatConfig.csv中字段[des]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="desid"){printf_message("AttributeFormatConfig.csv中字段[desid]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="weight"){printf_message("AttributeFormatConfig.csv中字段[weight]位置不对应 ");assert(false); return false; }

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
			AttributeFormatConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name=vecLine[1];
			member.nameid=(int)atoi(vecLine[2].c_str());
			member.des=vecLine[3];
			member.desid=(int)atoi(vecLine[4].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}

	vector<string> ReadCsvLine(string strContent,int contentOffset)
	{
		vector<string> temp;
		return temp;

	}
};

#endif
