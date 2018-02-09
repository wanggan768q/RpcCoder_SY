#ifndef __BUFFCONFLICTCONFIG_CONFIG_H
#define __BUFFCONFLICTCONFIG_CONFIG_H

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


//Buff组关系配置数据结构
struct BuffConflictConfigElement
{
	friend class BuffConflictConfigTable;
	int id;                      	//组id	组id 必须保证ID 是顺序的
	string desc;                 	//组名	仅策划用
	string group;                	//组标识	1=冲抵, 2=免疫, 3=共存
	int g1;                      	//眩晕	无法移动 无法使用技能 晕眩动作
	int g2;                      	//霸体	免疫负面效果
	int g3;                      	//减速	减少移动速度
	vector<int> allgroup;        	//合并	公式不要手填！！！

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
	BuffConflictConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//Buff组关系配置封装类
class BuffConflictConfigTable
{
	friend class TableData;
private:
	BuffConflictConfigTable(){}
	~BuffConflictConfigTable(){}
	typedef unordered_map<int, BuffConflictConfigElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<BuffConflictConfigElement>	m_vecAllElements;
	BuffConflictConfigElement m_emptyItem;
public:
	static BuffConflictConfigTable& Instance()
	{
		static BuffConflictConfigTable sInstance;
		return sInstance;
	}

	const BuffConflictConfigElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("BuffConflictConfigTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffConflictConfigElement>&	GetAllElement()
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
		return LoadJson("BuffConflictConfig.json");
		#else
		string strTableContent;
		if( LoadConfigContent("BuffConflictConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BuffConflictConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[BuffConflictConfig.bin]未找到");
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

			BuffConflictConfigElement	member;

						member.id=p.get<int>("id");
			member.desc=p.get<string>("desc");
			member.group=p.get<string>("group");
			member.g1=p.get<int>("g1");
			member.g2=p.get<int>("g2");
			member.g3=p.get<int>("g3");
			boost::property_tree::ptree sms_array_childallgroup = p.get_child("allgroup");
			for (BOOST_AUTO(pos, sms_array_childallgroup.begin()); pos != sms_array_childallgroup.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.allgroup.push_back(n);
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
		if(vecLine.size() != 7)
		{
			printf_message("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("BuffConflictConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="desc"){printf_message("BuffConflictConfig.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="group"){printf_message("BuffConflictConfig.csv中字段[group]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="g1"){printf_message("BuffConflictConfig.csv中字段[g1]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="g2"){printf_message("BuffConflictConfig.csv中字段[g2]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="g3"){printf_message("BuffConflictConfig.csv中字段[g3]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="allgroup"){printf_message("BuffConflictConfig.csv中字段[allgroup]位置不对应 ");assert(false); return false; }

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
			BuffConflictConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.desc=vecLine[1];
			member.group=vecLine[2];
			member.g1=(int)atoi(vecLine[3].c_str());
			member.g2=(int)atoi(vecLine[4].c_str());
			member.g3=(int)atoi(vecLine[5].c_str());

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
