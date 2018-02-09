#ifndef __BAOSHI_CONFIG_H
#define __BAOSHI_CONFIG_H

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


//宝石配置数据结构
struct BaoShiElement
{
	friend class BaoShiTable;
	int ID;                      	//编号	宝石ID
	int Type;                    	//宝石类别	宝石类别
	int Lv;                      	//宝石等级	宝石等级
	int Limit;                   	//镶嵌限制	镶嵌限制
	vector<string> AttrWuQi;     	//属性类别-武器	属性类别-武器
	vector<int> NumWuQi;         	//属性参数1	属性参数1
	vector<float> AttrOther;     	//属性类别-其他	属性类别-其他
	string NumOther;             	//属性参数2	属性参数2
	int HeCheng;                 	//合成后的宝石	合成后的宝石

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
	BaoShiElement()
	{
		ID = -1;
		m_bIsValidate=false;
	}
};

//宝石配置封装类
class BaoShiTable
{
	friend class TableData;
private:
	BaoShiTable(){}
	~BaoShiTable(){}
	typedef unordered_map<int, BaoShiElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<BaoShiElement>	m_vecAllElements;
	BaoShiElement m_emptyItem;
public:
	static BaoShiTable& Instance()
	{
		static BaoShiTable sInstance;
		return sInstance;
	}

	const BaoShiElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("BaoShiTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BaoShiElement>&	GetAllElement()
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
		return LoadJson("BaoShi.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BaoShi.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BaoShi.bin", strTableContent ) )
		{
			printf_message("配置文件[BaoShi.bin]未找到");
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

			BaoShiElement	member;

						member.ID=p.get<int>("ID");
			member.Type=p.get<int>("Type");
			member.Lv=p.get<int>("Lv");
			member.Limit=p.get<int>("Limit");
			boost::property_tree::ptree sms_array_childAttrWuQi = p.get_child("AttrWuQi");
			for (BOOST_AUTO(pos, sms_array_childAttrWuQi.begin()); pos != sms_array_childAttrWuQi.end(); ++pos)
			{
				string n = pos->second.get_value<string>(); 
				member.AttrWuQi.push_back(n);
			}
			boost::property_tree::ptree sms_array_childNumWuQi = p.get_child("NumWuQi");
			for (BOOST_AUTO(pos, sms_array_childNumWuQi.begin()); pos != sms_array_childNumWuQi.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.NumWuQi.push_back(n);
			}
			boost::property_tree::ptree sms_array_childAttrOther = p.get_child("AttrOther");
			for (BOOST_AUTO(pos, sms_array_childAttrOther.begin()); pos != sms_array_childAttrOther.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.AttrOther.push_back(n);
			}
			member.NumOther=p.get<string>("NumOther");
			member.HeCheng=p.get<int>("HeCheng");


			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
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
		if(vecLine.size() != 9)
		{
			printf_message("BaoShi.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="ID"){printf_message("BaoShi.csv中字段[ID]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="Type"){printf_message("BaoShi.csv中字段[Type]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="Lv"){printf_message("BaoShi.csv中字段[Lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="Limit"){printf_message("BaoShi.csv中字段[Limit]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="AttrWuQi"){printf_message("BaoShi.csv中字段[AttrWuQi]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="NumWuQi"){printf_message("BaoShi.csv中字段[NumWuQi]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="AttrOther"){printf_message("BaoShi.csv中字段[AttrOther]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="NumOther"){printf_message("BaoShi.csv中字段[NumOther]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="HeCheng"){printf_message("BaoShi.csv中字段[HeCheng]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			BaoShiElement	member;
			member.ID=(int)atoi(vecLine[0].c_str());
			member.Type=(int)atoi(vecLine[1].c_str());
			member.Lv=(int)atoi(vecLine[2].c_str());
			member.Limit=(int)atoi(vecLine[3].c_str());
			member.NumOther=vecLine[7];
			member.HeCheng=(int)atoi(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.ID] = member;
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
