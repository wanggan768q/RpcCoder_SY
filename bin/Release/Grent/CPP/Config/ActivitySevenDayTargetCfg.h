#ifndef __ACTIVITYSEVENDAYTARGET_CONFIG_H
#define __ACTIVITYSEVENDAYTARGET_CONFIG_H


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


//七日目标表配置数据结构
struct ActivitySevenDayTargetElement
{
	friend class ActivitySevenDayTargetTable;
	int id;                      	//主键id	活动id
	string comment;              	//注释	策划用
	int name;                    	//名称ID	对应stringui表文字ID，显示在福利的右标签页上
	string main_pic;             	//背景图	配置资源图的名字
	int activity_type;           	//七日目标时间类型	0：从角色进入游戏时开始计时 1：配置指定日期
	string target_type;          	//活动开始时间	如果activity_type列配置为0，此列不填
	int recorded_data_days;      	//记录数据天数	配置天数
	int get_rewards_days;        	//活动结束天数	配置天数，玩家在此天数内可以领奖，如果超过此天数那么活动将会直接结束，从界面上消失
	int level_min;               	//最低等级限制	可参与最低等级
	vector<int> target1;         	//1日目标	对应目标表中的ID
	vector<int> target2;         	//2日目标	对应目标表中的ID
	vector<int> target3;         	//3日目标	对应目标表中的ID
	vector<int> target4;         	//4日目标	对应目标表中的ID
	vector<int> target5;         	//5日目标	对应目标表中的ID
	vector<int> target6;         	//6日目标	对应目标表中的ID
	vector<int> target7;         	//7日目标	对应目标表中的ID
	int accumulate_point_id;     	//积分道具ID	对应物品表中的ID
	vector<int> accumulate_point_requirement;	//积分奖励要求	配置每个阶段奖励要求的积分数量
	vector<int> accumulate_point_reward;	//积分奖励详情	道具ID1|数量1|是否中转|道具ID2|数量2|是否中转
	vector<int> ultimate_prize_requirement;	//最终大奖积分要求	道具1积分要求|道具2积分要求
	vector<int> ultimate_prize_reward;	//最终大奖详情	道具ID1|数量1|是否中转|道具ID2|数量2|是否中转
	string ultimate_prize_show1; 	//最终大奖领取前图片资源	仅客户端使用，对应资源表图片ID
	string ultimate_prize_show2; 	//最终大奖领取后图片资源	仅客户端使用，对应资源表图片ID
	string ultimate_prize_item;  	//最终大奖展示物品	仅客户端使用，点击最终大奖处的图标时，会显示配在此处的物品的tips

private:

public:

	ActivitySevenDayTargetElement()
	{
		id = -1;
		
	}
};

//七日目标表配置封装类
class ActivitySevenDayTargetTable
{
	public:
	typedef unordered_map<int, ActivitySevenDayTargetElement*> MapElementMap;
	typedef vector<ActivitySevenDayTargetElement> vec_type;
	typedef std::function<void()> ReloadCallback;
	typedef vector<ReloadCallback> reload_vec_type;
private:
	ActivitySevenDayTargetTable(){}
	~ActivitySevenDayTargetTable(){}
	
	MapElementMap	m_mapElements;
	vector<ActivitySevenDayTargetElement>	m_vecAllElements;
	reload_vec_type m_vReLoadCb;

public:
	friend class TableData;
	static ActivitySevenDayTargetTable& Instance()
	{
		static ActivitySevenDayTargetTable sInstance;
		return sInstance;
	}

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	const ActivitySevenDayTargetElement* GetElement(int key)
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

		return LoadJson("ActivitySevenDayTarget.json");		
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
                ActivitySevenDayTargetElement	& member = m_vecAllElements[m_nIndex];
			member.id=p["id"].asInt();
			member.comment=p["comment"].asString();
			member.name=p["name"].asInt();
			member.main_pic=p["main_pic"].asString();
			member.activity_type=p["activity_type"].asInt();
			member.target_type=p["target_type"].asString();
			member.recorded_data_days=p["recorded_data_days"].asInt();
			member.get_rewards_days=p["get_rewards_days"].asInt();
			member.level_min=p["level_min"].asInt();
			Json::ValueIterator end_target1 = p["target1"].end();
			for (Json::ValueIterator jt = p["target1"].begin(); jt != end_target1; ++jt)
			{
				int n = (*jt).asInt();
				member.target1.push_back(n);
			}
			Json::ValueIterator end_target2 = p["target2"].end();
			for (Json::ValueIterator jt = p["target2"].begin(); jt != end_target2; ++jt)
			{
				int n = (*jt).asInt();
				member.target2.push_back(n);
			}
			Json::ValueIterator end_target3 = p["target3"].end();
			for (Json::ValueIterator jt = p["target3"].begin(); jt != end_target3; ++jt)
			{
				int n = (*jt).asInt();
				member.target3.push_back(n);
			}
			Json::ValueIterator end_target4 = p["target4"].end();
			for (Json::ValueIterator jt = p["target4"].begin(); jt != end_target4; ++jt)
			{
				int n = (*jt).asInt();
				member.target4.push_back(n);
			}
			Json::ValueIterator end_target5 = p["target5"].end();
			for (Json::ValueIterator jt = p["target5"].begin(); jt != end_target5; ++jt)
			{
				int n = (*jt).asInt();
				member.target5.push_back(n);
			}
			Json::ValueIterator end_target6 = p["target6"].end();
			for (Json::ValueIterator jt = p["target6"].begin(); jt != end_target6; ++jt)
			{
				int n = (*jt).asInt();
				member.target6.push_back(n);
			}
			Json::ValueIterator end_target7 = p["target7"].end();
			for (Json::ValueIterator jt = p["target7"].begin(); jt != end_target7; ++jt)
			{
				int n = (*jt).asInt();
				member.target7.push_back(n);
			}
			member.accumulate_point_id=p["accumulate_point_id"].asInt();
			Json::ValueIterator end_accumulate_point_requirement = p["accumulate_point_requirement"].end();
			for (Json::ValueIterator jt = p["accumulate_point_requirement"].begin(); jt != end_accumulate_point_requirement; ++jt)
			{
				int n = (*jt).asInt();
				member.accumulate_point_requirement.push_back(n);
			}
			Json::ValueIterator end_accumulate_point_reward = p["accumulate_point_reward"].end();
			for (Json::ValueIterator jt = p["accumulate_point_reward"].begin(); jt != end_accumulate_point_reward; ++jt)
			{
				int n = (*jt).asInt();
				member.accumulate_point_reward.push_back(n);
			}
			Json::ValueIterator end_ultimate_prize_requirement = p["ultimate_prize_requirement"].end();
			for (Json::ValueIterator jt = p["ultimate_prize_requirement"].begin(); jt != end_ultimate_prize_requirement; ++jt)
			{
				int n = (*jt).asInt();
				member.ultimate_prize_requirement.push_back(n);
			}
			Json::ValueIterator end_ultimate_prize_reward = p["ultimate_prize_reward"].end();
			for (Json::ValueIterator jt = p["ultimate_prize_reward"].begin(); jt != end_ultimate_prize_reward; ++jt)
			{
				int n = (*jt).asInt();
				member.ultimate_prize_reward.push_back(n);
			}
			member.ultimate_prize_show1=p["ultimate_prize_show1"].asString();
			member.ultimate_prize_show2=p["ultimate_prize_show2"].asString();
			member.ultimate_prize_item=p["ultimate_prize_item"].asString();



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
        std::ifstream is(std::string(CONFIG_PATH) + "ActivitySevenDayTarget.json");

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
                ActivitySevenDayTargetElement	 member;
			member.id=p["id"].asInt();
			member.comment=p["comment"].asString();
			member.name=p["name"].asInt();
			member.main_pic=p["main_pic"].asString();
			member.activity_type=p["activity_type"].asInt();
			member.target_type=p["target_type"].asString();
			member.recorded_data_days=p["recorded_data_days"].asInt();
			member.get_rewards_days=p["get_rewards_days"].asInt();
			member.level_min=p["level_min"].asInt();
			Json::ValueIterator end_target1 = p["target1"].end();
			for (Json::ValueIterator jt = p["target1"].begin(); jt != end_target1; ++jt)
			{
				int n = (*jt).asInt();
				member.target1.push_back(n);
			}
			Json::ValueIterator end_target2 = p["target2"].end();
			for (Json::ValueIterator jt = p["target2"].begin(); jt != end_target2; ++jt)
			{
				int n = (*jt).asInt();
				member.target2.push_back(n);
			}
			Json::ValueIterator end_target3 = p["target3"].end();
			for (Json::ValueIterator jt = p["target3"].begin(); jt != end_target3; ++jt)
			{
				int n = (*jt).asInt();
				member.target3.push_back(n);
			}
			Json::ValueIterator end_target4 = p["target4"].end();
			for (Json::ValueIterator jt = p["target4"].begin(); jt != end_target4; ++jt)
			{
				int n = (*jt).asInt();
				member.target4.push_back(n);
			}
			Json::ValueIterator end_target5 = p["target5"].end();
			for (Json::ValueIterator jt = p["target5"].begin(); jt != end_target5; ++jt)
			{
				int n = (*jt).asInt();
				member.target5.push_back(n);
			}
			Json::ValueIterator end_target6 = p["target6"].end();
			for (Json::ValueIterator jt = p["target6"].begin(); jt != end_target6; ++jt)
			{
				int n = (*jt).asInt();
				member.target6.push_back(n);
			}
			Json::ValueIterator end_target7 = p["target7"].end();
			for (Json::ValueIterator jt = p["target7"].begin(); jt != end_target7; ++jt)
			{
				int n = (*jt).asInt();
				member.target7.push_back(n);
			}
			member.accumulate_point_id=p["accumulate_point_id"].asInt();
			Json::ValueIterator end_accumulate_point_requirement = p["accumulate_point_requirement"].end();
			for (Json::ValueIterator jt = p["accumulate_point_requirement"].begin(); jt != end_accumulate_point_requirement; ++jt)
			{
				int n = (*jt).asInt();
				member.accumulate_point_requirement.push_back(n);
			}
			Json::ValueIterator end_accumulate_point_reward = p["accumulate_point_reward"].end();
			for (Json::ValueIterator jt = p["accumulate_point_reward"].begin(); jt != end_accumulate_point_reward; ++jt)
			{
				int n = (*jt).asInt();
				member.accumulate_point_reward.push_back(n);
			}
			Json::ValueIterator end_ultimate_prize_requirement = p["ultimate_prize_requirement"].end();
			for (Json::ValueIterator jt = p["ultimate_prize_requirement"].begin(); jt != end_ultimate_prize_requirement; ++jt)
			{
				int n = (*jt).asInt();
				member.ultimate_prize_requirement.push_back(n);
			}
			Json::ValueIterator end_ultimate_prize_reward = p["ultimate_prize_reward"].end();
			for (Json::ValueIterator jt = p["ultimate_prize_reward"].begin(); jt != end_ultimate_prize_reward; ++jt)
			{
				int n = (*jt).asInt();
				member.ultimate_prize_reward.push_back(n);
			}
			member.ultimate_prize_show1=p["ultimate_prize_show1"].asString();
			member.ultimate_prize_show2=p["ultimate_prize_show2"].asString();
			member.ultimate_prize_item=p["ultimate_prize_item"].asString();


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
