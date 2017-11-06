#ifndef __SKILL_CONFIG_H
#define __SKILL_CONFIG_H

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


//技能配置数据结构
struct SkillElement
{
	friend class SkillTable;
	int id;                      	//技能ID	技能ID
	int ligic_id;                	//技能释放的逻辑：	技能释放的逻辑：
	int charge_or_interval;      	//在一段时间之内，释放多少次伤害（BUFF）	在一段时间之内，释放多少次伤害（BUFF）
	int cooldown_id;             	//冷却ID组ID（-1：表示没有冷却组）	冷却ID组ID（-1：表示没有冷却组）
	int cooldown_time;           	//冷却的时间(毫秒单位)	冷却的时间(毫秒单位)
	int charge_time;             	//引唱的时间（毫秒为单位）	引唱的时间（毫秒为单位）
	int channel_time;            	//引导的时间（毫秒为单位）	引导的时间（毫秒为单位）
	vector<int> pars;            	//参数	参数
	int attack_type;             	//攻击的类型:0:物理攻击,1:法术攻击,2:物理&法术攻击	攻击的类型:0:物理攻击,1:法术攻击,2:物理&法术攻击
	int attack_rate;             	//技能伤害系数	技能伤害系数
	int attack_value;            	//技能伤害附加	技能伤害附加
	int attack_range;            	//技能释放距离	技能释放距离

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
	SkillElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//技能配置封装类
class SkillTable
{
	friend class TableData;
private:
	SkillTable(){}
	~SkillTable(){}
	unordered_map<int, SkillElement>	m_mapElements;
	vector<SkillElement>	m_vecAllElements;
	SkillElement m_emptyItem;
public:
	static SkillTable& Instance()
	{
		static SkillTable sInstance;
		return sInstance;
	}

	const SkillElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			SkillElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("SkillTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("SkillTable: ") + std::to_string(key)).c_str());
		return NULL;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SkillElement>&	GetAllElement()
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
		return LoadJson("Skill.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Skill.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Skill.bin", strTableContent ) )
		{
			printf_message("配置文件[Skill.bin]未找到");
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

			SkillElement	member;

						member.id=p.get<int>("id");
			member.ligic_id=p.get<int>("ligic_id");
			member.charge_or_interval=p.get<int>("charge_or_interval");
			member.cooldown_id=p.get<int>("cooldown_id");
			member.cooldown_time=p.get<int>("cooldown_time");
			member.charge_time=p.get<int>("charge_time");
			member.channel_time=p.get<int>("channel_time");
			boost::property_tree::ptree sms_array_childpars = p.get_child("pars");
			for (BOOST_AUTO(pos, sms_array_childpars.begin()); pos != sms_array_childpars.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.pars.push_back(n);
			}
			member.attack_type=p.get<int>("attack_type");
			member.attack_rate=p.get<int>("attack_rate");
			member.attack_value=p.get<int>("attack_value");
			member.attack_range=p.get<int>("attack_range");


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
		if(vecLine.size() != 12)
		{
			printf_message("Skill.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Skill.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="ligic_id"){printf_message("Skill.csv中字段[ligic_id]位置不对应");assert(false); return false; }
		if(vecLine[2]!="charge_or_interval"){printf_message("Skill.csv中字段[charge_or_interval]位置不对应");assert(false); return false; }
		if(vecLine[3]!="cooldown_id"){printf_message("Skill.csv中字段[cooldown_id]位置不对应");assert(false); return false; }
		if(vecLine[4]!="cooldown_time"){printf_message("Skill.csv中字段[cooldown_time]位置不对应");assert(false); return false; }
		if(vecLine[5]!="charge_time"){printf_message("Skill.csv中字段[charge_time]位置不对应");assert(false); return false; }
		if(vecLine[6]!="channel_time"){printf_message("Skill.csv中字段[channel_time]位置不对应");assert(false); return false; }
		if(vecLine[7]!="pars"){printf_message("Skill.csv中字段[pars]位置不对应");assert(false); return false; }
		if(vecLine[8]!="attack_type"){printf_message("Skill.csv中字段[attack_type]位置不对应");assert(false); return false; }
		if(vecLine[9]!="attack_rate"){printf_message("Skill.csv中字段[attack_rate]位置不对应");assert(false); return false; }
		if(vecLine[10]!="attack_value"){printf_message("Skill.csv中字段[attack_value]位置不对应");assert(false); return false; }
		if(vecLine[11]!="attack_range"){printf_message("Skill.csv中字段[attack_range]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			SkillElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.ligic_id=(int)atoi(vecLine[1].c_str());
			member.charge_or_interval=(int)atoi(vecLine[2].c_str());
			member.cooldown_id=(int)atoi(vecLine[3].c_str());
			member.cooldown_time=(int)atoi(vecLine[4].c_str());
			member.charge_time=(int)atoi(vecLine[5].c_str());
			member.channel_time=(int)atoi(vecLine[6].c_str());
			member.attack_type=(int)atoi(vecLine[8].c_str());
			member.attack_rate=(int)atoi(vecLine[9].c_str());
			member.attack_value=(int)atoi(vecLine[10].c_str());
			member.attack_range=(int)atoi(vecLine[11].c_str());

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
