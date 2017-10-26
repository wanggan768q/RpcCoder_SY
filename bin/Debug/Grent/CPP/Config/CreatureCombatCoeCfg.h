#ifndef __CREATURECOMBATCOE_CONFIG_H
#define __CREATURECOMBATCOE_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//NPC战斗系数表配置数据结构
struct CreatureCombatCoeElement
{
	friend class CreatureCombatCoeTable;
	int id;                      	//ID号	关联Creature
	string note;                 	//中文注释	
	int template_id;             	//对应模板	关联CreatureCombatbasic
	float hp_rate;               	//生命比例	
	float p_atk_rate;            	//物理攻击力比例	
	float p_def_rate;            	//物理防御力比例	
	float s_atk_rate;            	//魔法攻击力比例	
	float s_def_rate;            	//魔法防御力比例	
	float exp_rate;              	//经验比例	

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
	CreatureCombatCoeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC战斗系数表配置封装类
class CreatureCombatCoeTable
{
	friend class TableData;
private:
	CreatureCombatCoeTable(){}
	~CreatureCombatCoeTable(){}
	map<int, CreatureCombatCoeElement>	m_mapElements;
	vector<CreatureCombatCoeElement>	m_vecAllElements;
	CreatureCombatCoeElement m_emptyItem;
public:
	static CreatureCombatCoeTable& Instance()
	{
		static CreatureCombatCoeTable sInstance;
		return sInstance;
	}

	CreatureCombatCoeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureCombatCoeElement>&	GetAllElement()
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
		return LoadJson("CreatureCombatCoe.json");
		#else
		string strTableContent;
		if( LoadConfigContent("CreatureCombatCoe.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureCombatCoe.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureCombatCoe.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree parse;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, parse);
		boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CreatureCombatCoeElement	member;

						member.id=p.get<int>("id");
			member.note=p.get<string>("note");
			member.template_id=p.get<int>("template_id");
			member.hp_rate=p.get<float>("hp_rate");
			member.p_atk_rate=p.get<float>("p_atk_rate");
			member.p_def_rate=p.get<float>("p_def_rate");
			member.s_atk_rate=p.get<float>("s_atk_rate");
			member.s_def_rate=p.get<float>("s_def_rate");
			member.exp_rate=p.get<float>("exp_rate");


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
		if(vecLine.size() != 9)
		{
			printf_message("CreatureCombatCoe.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreatureCombatCoe.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="note"){printf_message("CreatureCombatCoe.csv中字段[note]位置不对应");assert(false); return false; }
		if(vecLine[2]!="template_id"){printf_message("CreatureCombatCoe.csv中字段[template_id]位置不对应");assert(false); return false; }
		if(vecLine[3]!="hp_rate"){printf_message("CreatureCombatCoe.csv中字段[hp_rate]位置不对应");assert(false); return false; }
		if(vecLine[4]!="p_atk_rate"){printf_message("CreatureCombatCoe.csv中字段[p_atk_rate]位置不对应");assert(false); return false; }
		if(vecLine[5]!="p_def_rate"){printf_message("CreatureCombatCoe.csv中字段[p_def_rate]位置不对应");assert(false); return false; }
		if(vecLine[6]!="s_atk_rate"){printf_message("CreatureCombatCoe.csv中字段[s_atk_rate]位置不对应");assert(false); return false; }
		if(vecLine[7]!="s_def_rate"){printf_message("CreatureCombatCoe.csv中字段[s_def_rate]位置不对应");assert(false); return false; }
		if(vecLine[8]!="exp_rate"){printf_message("CreatureCombatCoe.csv中字段[exp_rate]位置不对应");assert(false); return false; }

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
			CreatureCombatCoeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.note=vecLine[1];
			member.template_id=(int)atoi(vecLine[2].c_str());
			member.hp_rate=(float)atof(vecLine[3].c_str());
			member.p_atk_rate=(float)atof(vecLine[4].c_str());
			member.p_def_rate=(float)atof(vecLine[5].c_str());
			member.s_atk_rate=(float)atof(vecLine[6].c_str());
			member.s_def_rate=(float)atof(vecLine[7].c_str());
			member.exp_rate=(float)atof(vecLine[8].c_str());

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
