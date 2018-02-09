#ifndef __DUNGEON_CONFIG_H
#define __DUNGEON_CONFIG_H

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


//副本表配置数据结构
struct DungeonElement
{
	friend class DungeonTable;
	int id;                      	//序号	序号
	string comment;              	//	
	int map_id;                  	//场景ID	
	int dungeon_type;            	//副本类型	0：野外 1：5人副本 2：竞技场 3：团队本 4：战场
	int difficult;               	//难度	
	int required_num;            	//所需玩家数量	
	int required_last_dungeon_id;	//所需前置副本ID	
	int reset_type;              	//重置类型	
	int finish_amount;           	//允许玩家完成次数	
	int name_id;                 	//副本名字ID	
	int describle_id;            	//副本描述ID	
	string reward_boss_ui;       	//boss掉落数组	
	int First_reward_ui;         	//首通奖励礼包ID	
	int general_reward__ui;      	//非首通奖励礼包ID	
	int is_transfer;             	//是否需要装备中转表	
	string start_music;          	//开启音乐	
	string loop_music;           	//循环音乐	
	int endingboss_id;           	//最后boss ID	
	int duration_time;           	//副本存活时间	
	int conclusion_time;         	//副本结算时间	
	int start_time;              	//副本开启时间	
	int end_time;                	//副本关闭时间	
	int exit_waypoint;           	//退出副本后的路点	

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
	DungeonElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//副本表配置封装类
class DungeonTable
{
	friend class TableData;
private:
	DungeonTable(){}
	~DungeonTable(){}
	typedef unordered_map<int, DungeonElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<DungeonElement>	m_vecAllElements;
	DungeonElement m_emptyItem;
public:
	static DungeonTable& Instance()
	{
		static DungeonTable sInstance;
		return sInstance;
	}

	const DungeonElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("DungeonTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DungeonElement>&	GetAllElement()
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
		return LoadJson("Dungeon.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Dungeon.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Dungeon.bin", strTableContent ) )
		{
			printf_message("配置文件[Dungeon.bin]未找到");
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

			DungeonElement	member;

						member.id=p.get<int>("id");
			member.comment=p.get<string>("comment");
			member.map_id=p.get<int>("map_id");
			member.dungeon_type=p.get<int>("dungeon_type");
			member.difficult=p.get<int>("difficult");
			member.required_num=p.get<int>("required_num");
			member.required_last_dungeon_id=p.get<int>("required_last_dungeon_id");
			member.reset_type=p.get<int>("reset_type");
			member.finish_amount=p.get<int>("finish_amount");
			member.name_id=p.get<int>("name_id");
			member.describle_id=p.get<int>("describle_id");
			member.reward_boss_ui=p.get<string>("reward_boss_ui");
			member.First_reward_ui=p.get<int>("First_reward_ui");
			member.general_reward__ui=p.get<int>("general_reward__ui");
			member.is_transfer=p.get<int>("is_transfer");
			member.start_music=p.get<string>("start_music");
			member.loop_music=p.get<string>("loop_music");
			member.endingboss_id=p.get<int>("endingboss_id");
			member.duration_time=p.get<int>("duration_time");
			member.conclusion_time=p.get<int>("conclusion_time");
			member.start_time=p.get<int>("start_time");
			member.end_time=p.get<int>("end_time");
			member.exit_waypoint=p.get<int>("exit_waypoint");


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
		if(vecLine.size() != 23)
		{
			printf_message("Dungeon.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Dungeon.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Dungeon.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="map_id"){printf_message("Dungeon.csv中字段[map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="dungeon_type"){printf_message("Dungeon.csv中字段[dungeon_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="difficult"){printf_message("Dungeon.csv中字段[difficult]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="required_num"){printf_message("Dungeon.csv中字段[required_num]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="required_last_dungeon_id"){printf_message("Dungeon.csv中字段[required_last_dungeon_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="reset_type"){printf_message("Dungeon.csv中字段[reset_type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="finish_amount"){printf_message("Dungeon.csv中字段[finish_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="name_id"){printf_message("Dungeon.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="describle_id"){printf_message("Dungeon.csv中字段[describle_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="reward_boss_ui"){printf_message("Dungeon.csv中字段[reward_boss_ui]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="First_reward_ui"){printf_message("Dungeon.csv中字段[First_reward_ui]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="general_reward__ui"){printf_message("Dungeon.csv中字段[general_reward__ui]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="is_transfer"){printf_message("Dungeon.csv中字段[is_transfer]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="start_music"){printf_message("Dungeon.csv中字段[start_music]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="loop_music"){printf_message("Dungeon.csv中字段[loop_music]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="endingboss_id"){printf_message("Dungeon.csv中字段[endingboss_id]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="duration_time"){printf_message("Dungeon.csv中字段[duration_time]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="conclusion_time"){printf_message("Dungeon.csv中字段[conclusion_time]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="start_time"){printf_message("Dungeon.csv中字段[start_time]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="end_time"){printf_message("Dungeon.csv中字段[end_time]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="exit_waypoint"){printf_message("Dungeon.csv中字段[exit_waypoint]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)23)
			{
				assert(false);
				return false;
			}
			DungeonElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.map_id=(int)atoi(vecLine[2].c_str());
			member.dungeon_type=(int)atoi(vecLine[3].c_str());
			member.difficult=(int)atoi(vecLine[4].c_str());
			member.required_num=(int)atoi(vecLine[5].c_str());
			member.required_last_dungeon_id=(int)atoi(vecLine[6].c_str());
			member.reset_type=(int)atoi(vecLine[7].c_str());
			member.finish_amount=(int)atoi(vecLine[8].c_str());
			member.name_id=(int)atoi(vecLine[9].c_str());
			member.describle_id=(int)atoi(vecLine[10].c_str());
			member.reward_boss_ui=vecLine[11];
			member.First_reward_ui=(int)atoi(vecLine[12].c_str());
			member.general_reward__ui=(int)atoi(vecLine[13].c_str());
			member.is_transfer=(int)atoi(vecLine[14].c_str());
			member.start_music=vecLine[15];
			member.loop_music=vecLine[16];
			member.endingboss_id=(int)atoi(vecLine[17].c_str());
			member.duration_time=(int)atoi(vecLine[18].c_str());
			member.conclusion_time=(int)atoi(vecLine[19].c_str());
			member.start_time=(int)atoi(vecLine[20].c_str());
			member.end_time=(int)atoi(vecLine[21].c_str());
			member.exit_waypoint=(int)atoi(vecLine[22].c_str());

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
