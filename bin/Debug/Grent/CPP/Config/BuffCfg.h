#ifndef __BUFF_CONFIG_H
#define __BUFF_CONFIG_H

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


//效果配置数据结构
struct BuffElement
{
	friend class BuffTable;
	int id;                      	//数据索引	数据索引
	int buffID;                  	//对应的BuffID	仅程序用
	string desc_type;            	//Buff效果	仅程序用
	string desc;                 	//Buff名称	仅策划用
	int oper;                    	//Buff关系	0=叠加 1=冲抵 2=免疫
	int operPars;                	//关系参数	若叠加类=最大叠加次数
	int overTimed;               	//是否持续Buff	0=非持续 1=持续
	int continuance;             	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算
	int interval;                	//间隔时间ms	间隔时间
	int mutexID;                 	//Buff组ID	-1表示跟谁都不是一组的
	string buffEffect;           	//buff特效	buff特效名称
	int buffMount;               	//buff特效挂载点	所有部位数字0-19
	int groupPriority;           	//组中优先级	0为最低
	vector<int> pars;            	//参数	参数1
	int is_tell_client;          	//是否告知客户端	0：否 1：是

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
	BuffElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//效果配置封装类
class BuffTable
{
	friend class TableData;
private:
	BuffTable(){}
	~BuffTable(){}
	typedef unordered_map<int, BuffElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<BuffElement>	m_vecAllElements;
	BuffElement m_emptyItem;
public:
	static BuffTable& Instance()
	{
		static BuffTable sInstance;
		return sInstance;
	}

	const BuffElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("BuffTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffElement>&	GetAllElement()
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
		return LoadJson("Buff.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Buff.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Buff.bin", strTableContent ) )
		{
			printf_message("配置文件[Buff.bin]未找到");
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

			BuffElement	member;

						member.id=p.get<int>("id");
			member.buffID=p.get<int>("buffID");
			member.desc_type=p.get<string>("desc_type");
			member.desc=p.get<string>("desc");
			member.oper=p.get<int>("oper");
			member.operPars=p.get<int>("operPars");
			member.overTimed=p.get<int>("overTimed");
			member.continuance=p.get<int>("continuance");
			member.interval=p.get<int>("interval");
			member.mutexID=p.get<int>("mutexID");
			member.buffEffect=p.get<string>("buffEffect");
			member.buffMount=p.get<int>("buffMount");
			member.groupPriority=p.get<int>("groupPriority");
			boost::property_tree::ptree sms_array_childpars = p.get_child("pars");
			for (BOOST_AUTO(pos, sms_array_childpars.begin()); pos != sms_array_childpars.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.pars.push_back(n);
			}
			member.is_tell_client=p.get<int>("is_tell_client");


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
		if(vecLine.size() != 15)
		{
			printf_message("Buff.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Buff.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="buffID"){printf_message("Buff.csv中字段[buffID]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="desc_type"){printf_message("Buff.csv中字段[desc_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("Buff.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="oper"){printf_message("Buff.csv中字段[oper]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="operPars"){printf_message("Buff.csv中字段[operPars]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="overTimed"){printf_message("Buff.csv中字段[overTimed]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="continuance"){printf_message("Buff.csv中字段[continuance]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="interval"){printf_message("Buff.csv中字段[interval]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="mutexID"){printf_message("Buff.csv中字段[mutexID]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="buffEffect"){printf_message("Buff.csv中字段[buffEffect]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="buffMount"){printf_message("Buff.csv中字段[buffMount]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="groupPriority"){printf_message("Buff.csv中字段[groupPriority]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="pars"){printf_message("Buff.csv中字段[pars]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="is_tell_client"){printf_message("Buff.csv中字段[is_tell_client]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)15)
			{
				assert(false);
				return false;
			}
			BuffElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.buffID=(int)atoi(vecLine[1].c_str());
			member.desc_type=vecLine[2];
			member.desc=vecLine[3];
			member.oper=(int)atoi(vecLine[4].c_str());
			member.operPars=(int)atoi(vecLine[5].c_str());
			member.overTimed=(int)atoi(vecLine[6].c_str());
			member.continuance=(int)atoi(vecLine[7].c_str());
			member.interval=(int)atoi(vecLine[8].c_str());
			member.mutexID=(int)atoi(vecLine[9].c_str());
			member.buffEffect=vecLine[10];
			member.buffMount=(int)atoi(vecLine[11].c_str());
			member.groupPriority=(int)atoi(vecLine[12].c_str());
			member.is_tell_client=(int)atoi(vecLine[14].c_str());

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
