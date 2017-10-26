#ifndef __SCENE_CONFIG_H
#define __SCENE_CONFIG_H

#include "CommonDefine.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <map>
using namespace std;


//场景配置数据结构
struct SceneElement
{
	friend class SceneTable;
	int id;                      	//序号	序号
	string name;                 	//名字	名字
	int thread_id;               	//线程ID	线程ID
	int is_dungeon;              	//是否是副本	是否是副本
	float valid_pos_x;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	float valid_pos_z;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	int dungeon_type;            	//副本类型	
	int difficult;               	//难度	
	int required_level;          	//所需等级	
	float required_score;        	//所需战力	
	int required_num;            	//所需玩家数量	
	int required_last_dungeon_id;	//所需前置副本ID	
	int reset_type;              	//重置类型	
	int finish_amount;           	//允许玩家完成次数	
	int name_id;                 	//副本名字ID	
	int describle_id;            	//副本描述ID	
	string picture_path;         	//副本图片路径	
	int teleport_id;             	//传送路点ID	
	string reward_boss_ui;       	//boss掉落数组	
	int First_reward_ui;         	//首通奖励礼包ID	
	int general_reward__ui;      	//非首通奖励礼包ID	
	int is_transfer;             	//是否需要装备中转表	
	string start_music;          	//开启音乐	
	string loop_music;           	//循环音乐	
	int endingboss_id;           	//最后boss ID	
	int duration_time;           	//副本存活时间	
	int end_time;                	//副本结算时间	

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
	SceneElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//场景配置封装类
class SceneTable
{
	friend class TableData;
private:
	SceneTable(){}
	~SceneTable(){}
	map<int, SceneElement>	m_mapElements;
	vector<SceneElement>	m_vecAllElements;
	SceneElement m_emptyItem;
public:
	static SceneTable& Instance()
	{
		static SceneTable sInstance;
		return sInstance;
	}

	SceneElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SceneElement>&	GetAllElement()
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
		return LoadJson("Scene.json");
		#else
		string strTableContent;
		if( LoadConfigContent("Scene.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Scene.bin", strTableContent ) )
		{
			printf_message("配置文件[Scene.bin]未找到");
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

			SceneElement	member;

						member.id=p.get<int>("id");
			member.name=p.get<string>("name");
			member.thread_id=p.get<int>("thread_id");
			member.is_dungeon=p.get<int>("is_dungeon");
			member.valid_pos_x=p.get<float>("valid_pos_x");
			member.valid_pos_z=p.get<float>("valid_pos_z");
			member.dungeon_type=p.get<int>("dungeon_type");
			member.difficult=p.get<int>("difficult");
			member.required_level=p.get<int>("required_level");
			member.required_score=p.get<float>("required_score");
			member.required_num=p.get<int>("required_num");
			member.required_last_dungeon_id=p.get<int>("required_last_dungeon_id");
			member.reset_type=p.get<int>("reset_type");
			member.finish_amount=p.get<int>("finish_amount");
			member.name_id=p.get<int>("name_id");
			member.describle_id=p.get<int>("describle_id");
			member.picture_path=p.get<string>("picture_path");
			member.teleport_id=p.get<int>("teleport_id");
			member.reward_boss_ui=p.get<string>("reward_boss_ui");
			member.First_reward_ui=p.get<int>("First_reward_ui");
			member.general_reward__ui=p.get<int>("general_reward__ui");
			member.is_transfer=p.get<int>("is_transfer");
			member.start_music=p.get<string>("start_music");
			member.loop_music=p.get<string>("loop_music");
			member.endingboss_id=p.get<int>("endingboss_id");
			member.duration_time=p.get<int>("duration_time");
			member.end_time=p.get<int>("end_time");


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
		if(vecLine.size() != 27)
		{
			printf_message("Scene.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Scene.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("Scene.csv中字段[name]位置不对应");assert(false); return false; }
		if(vecLine[2]!="thread_id"){printf_message("Scene.csv中字段[thread_id]位置不对应");assert(false); return false; }
		if(vecLine[3]!="is_dungeon"){printf_message("Scene.csv中字段[is_dungeon]位置不对应");assert(false); return false; }
		if(vecLine[4]!="valid_pos_x"){printf_message("Scene.csv中字段[valid_pos_x]位置不对应");assert(false); return false; }
		if(vecLine[5]!="valid_pos_z"){printf_message("Scene.csv中字段[valid_pos_z]位置不对应");assert(false); return false; }
		if(vecLine[6]!="dungeon_type"){printf_message("Scene.csv中字段[dungeon_type]位置不对应");assert(false); return false; }
		if(vecLine[7]!="difficult"){printf_message("Scene.csv中字段[difficult]位置不对应");assert(false); return false; }
		if(vecLine[8]!="required_level"){printf_message("Scene.csv中字段[required_level]位置不对应");assert(false); return false; }
		if(vecLine[9]!="required_score"){printf_message("Scene.csv中字段[required_score]位置不对应");assert(false); return false; }
		if(vecLine[10]!="required_num"){printf_message("Scene.csv中字段[required_num]位置不对应");assert(false); return false; }
		if(vecLine[11]!="required_last_dungeon_id"){printf_message("Scene.csv中字段[required_last_dungeon_id]位置不对应");assert(false); return false; }
		if(vecLine[12]!="reset_type"){printf_message("Scene.csv中字段[reset_type]位置不对应");assert(false); return false; }
		if(vecLine[13]!="finish_amount"){printf_message("Scene.csv中字段[finish_amount]位置不对应");assert(false); return false; }
		if(vecLine[14]!="name_id"){printf_message("Scene.csv中字段[name_id]位置不对应");assert(false); return false; }
		if(vecLine[15]!="describle_id"){printf_message("Scene.csv中字段[describle_id]位置不对应");assert(false); return false; }
		if(vecLine[16]!="picture_path"){printf_message("Scene.csv中字段[picture_path]位置不对应");assert(false); return false; }
		if(vecLine[17]!="teleport_id"){printf_message("Scene.csv中字段[teleport_id]位置不对应");assert(false); return false; }
		if(vecLine[18]!="reward_boss_ui"){printf_message("Scene.csv中字段[reward_boss_ui]位置不对应");assert(false); return false; }
		if(vecLine[19]!="First_reward_ui"){printf_message("Scene.csv中字段[First_reward_ui]位置不对应");assert(false); return false; }
		if(vecLine[20]!="general_reward__ui"){printf_message("Scene.csv中字段[general_reward__ui]位置不对应");assert(false); return false; }
		if(vecLine[21]!="is_transfer"){printf_message("Scene.csv中字段[is_transfer]位置不对应");assert(false); return false; }
		if(vecLine[22]!="start_music"){printf_message("Scene.csv中字段[start_music]位置不对应");assert(false); return false; }
		if(vecLine[23]!="loop_music"){printf_message("Scene.csv中字段[loop_music]位置不对应");assert(false); return false; }
		if(vecLine[24]!="endingboss_id"){printf_message("Scene.csv中字段[endingboss_id]位置不对应");assert(false); return false; }
		if(vecLine[25]!="duration_time"){printf_message("Scene.csv中字段[duration_time]位置不对应");assert(false); return false; }
		if(vecLine[26]!="end_time"){printf_message("Scene.csv中字段[end_time]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)27)
			{
				assert(false);
				return false;
			}
			SceneElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name=vecLine[1];
			member.thread_id=(int)atoi(vecLine[2].c_str());
			member.is_dungeon=(int)atoi(vecLine[3].c_str());
			member.valid_pos_x=(float)atof(vecLine[4].c_str());
			member.valid_pos_z=(float)atof(vecLine[5].c_str());
			member.dungeon_type=(int)atoi(vecLine[6].c_str());
			member.difficult=(int)atoi(vecLine[7].c_str());
			member.required_level=(int)atoi(vecLine[8].c_str());
			member.required_score=(float)atof(vecLine[9].c_str());
			member.required_num=(int)atoi(vecLine[10].c_str());
			member.required_last_dungeon_id=(int)atoi(vecLine[11].c_str());
			member.reset_type=(int)atoi(vecLine[12].c_str());
			member.finish_amount=(int)atoi(vecLine[13].c_str());
			member.name_id=(int)atoi(vecLine[14].c_str());
			member.describle_id=(int)atoi(vecLine[15].c_str());
			member.picture_path=vecLine[16];
			member.teleport_id=(int)atoi(vecLine[17].c_str());
			member.reward_boss_ui=vecLine[18];
			member.First_reward_ui=(int)atoi(vecLine[19].c_str());
			member.general_reward__ui=(int)atoi(vecLine[20].c_str());
			member.is_transfer=(int)atoi(vecLine[21].c_str());
			member.start_music=vecLine[22];
			member.loop_music=vecLine[23];
			member.endingboss_id=(int)atoi(vecLine[24].c_str());
			member.duration_time=(int)atoi(vecLine[25].c_str());
			member.end_time=(int)atoi(vecLine[26].c_str());

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
