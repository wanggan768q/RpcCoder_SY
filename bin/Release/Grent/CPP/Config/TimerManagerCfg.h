#ifndef __TIMERMANAGER_CONFIG_H
#define __TIMERMANAGER_CONFIG_H


#include "Logger.h"
#include "CommonDefine.h"
#include "DK_Assertx.h"



#include <vector>
#include <string>
#include <unordered_map>

#include "jsoncpp/json.h"
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//定时规则配置数据结构
struct TimerManagerElement
{
	friend class TimerManagerTable;
	int id;                      	//序号	主键id
	string comment;              	//注释	定时器描述
	int month_week;              	//每月第几周	0不用处理
	int month_week_range;        	//0无限制|正数前几周负数后几周	0无限制|正数前几周负数后几周
	vector<int> week;            	//0无星期限制|n星期n	0无星期限制|n星期n
	string timerbegin;           	//定时每天开始时间	定时每天开始时间
	int interval;                	//时间间隔	整数
	string timerend;             	//根据时间间隔+开始时间	此列暂时无用
	int nextbegin;               	//下次开始时间	下次重新执行时间逻辑0按照间隔继续，非0按照新时间
	string expired;              	//定时器是否可以失效	0 永不失效 其他失效时间
	string expired_date;         	//失效日期	0永不失效其他定时器失效日期
	int crossday;                	//跨天处理	0 不特殊处理 1 根据timerend跨天重新计算

private:

public:

	TimerManagerElement()
	{
		id = -1;
		
	}
};

//定时规则配置封装类
class TimerManagerTable
{
	public:
	typedef unordered_map<int, TimerManagerElement*> MapElementMap;
	typedef vector<TimerManagerElement> vec_type;
	typedef std::function<void()> ReloadCallback;
	typedef vector<ReloadCallback> reload_vec_type;
private:
	TimerManagerTable(){}
	~TimerManagerTable(){}
	
	MapElementMap	m_mapElements;
	vector<TimerManagerElement>	m_vecAllElements;
	reload_vec_type m_vReLoadCb;

public:
	friend class TableData;
	static TimerManagerTable& Instance()
	{
		static TimerManagerTable sInstance;
		return sInstance;
	}

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	const TimerManagerElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			return NULL;
		}
		return it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vec_type&	GetAllElement()
	{
		return m_vecAllElements;
	}
	bool Load()
	{

		return LoadJson("TimerManager.json");		
	}

	void NotifyCb()
	{
		for (auto it : m_vReLoadCb)
		{
			it();
		}
	}
	
	bool LoadJson(const std::string& jsonFile)
	{
		Json::Reader filereader(Json::Features::strictMode());
        Json::Value root;
        std::ifstream is(std::string(CONFIG_PATH) + jsonFile);

        if (is) {
            // get length of file:
            is.seekg(0, is.end);
            int length = (int)is.tellg();
            length = length + 1;
            is.seekg(0, is.beg);
            char * buffer = new char[length];
            memset(buffer, 0, length);
            // read data as a block:
            is.read(buffer, length);
            is.close();
            bool bRet = filereader.parse(buffer, buffer + length, root);
            if (!bRet)
			{
				ELOG("error config");
				Assert(false);
			}
            delete[] buffer;
        }

		m_vecAllElements.resize(root.size());
		int32_t m_nIndex = 0;
        for (Json::ValueIterator it = root.begin(); it != root.end(); ++it, ++m_nIndex)
        {
            try
            {
                auto p = (*it);
                TimerManagerElement	& member = m_vecAllElements[m_nIndex];
			member.id=p["id"].asInt();
			member.comment=p["comment"].asString();
			member.month_week=p["month_week"].asInt();
			member.month_week_range=p["month_week_range"].asInt();
			Json::ValueIterator end_week = p["week"].end();
			for (Json::ValueIterator jt = p["week"].begin(); jt != end_week; ++jt)
			{
				int n = (*jt).asInt();
				member.week.push_back(n);
			}
			member.timerbegin=p["timerbegin"].asString();
			member.interval=p["interval"].asInt();
			member.timerend=p["timerend"].asString();
			member.nextbegin=p["nextbegin"].asInt();
			member.expired=p["expired"].asString();
			member.expired_date=p["expired_date"].asString();
			member.crossday=p["crossday"].asInt();



				m_mapElements.emplace(member.id, &member);
            }
            catch (std::exception const & e)
            {
                ELOG("%s error config id : %d", e.what(), (*it)["id"].asInt());
                Assert(false);
            }
        }
		NotifyCb();
        return true;
	}



	bool ReLoad()
	{
		Json::Reader filereader;
        Json::Value root;
        std::ifstream is(std::string(CONFIG_PATH) + "TimerManager.json");

        if (is) {
            // get length of file:
            is.seekg(0, is.end);
            int length = (int)is.tellg();
            length = length + 1;
            is.seekg(0, is.beg);
            char * buffer = new char[length];
            memset(buffer, 0, length);
            // read data as a block:
            is.read(buffer, length);
            is.close();
            filereader.parse(buffer, buffer + length, root);
            delete[] buffer;
        }

        for (Json::ValueIterator it = root.begin(); it != root.end(); ++it )
        {
            try
            {
                auto p = (*it);
                TimerManagerElement	 member;
			member.id=p["id"].asInt();
			member.comment=p["comment"].asString();
			member.month_week=p["month_week"].asInt();
			member.month_week_range=p["month_week_range"].asInt();
			Json::ValueIterator end_week = p["week"].end();
			for (Json::ValueIterator jt = p["week"].begin(); jt != end_week; ++jt)
			{
				int n = (*jt).asInt();
				member.week.push_back(n);
			}
			member.timerbegin=p["timerbegin"].asString();
			member.interval=p["interval"].asInt();
			member.timerend=p["timerend"].asString();
			member.nextbegin=p["nextbegin"].asInt();
			member.expired=p["expired"].asString();
			member.expired_date=p["expired_date"].asString();
			member.crossday=p["crossday"].asInt();


				*m_mapElements[member.id] = member;
            }
            catch (std::exception const & e)
            {
                ELOG("%s error config id : %d", e.what(), (*it)["id"].asInt());
                Assert(false);
            }
        }
		NotifyCb();
		return true;
	}

};

#endif
