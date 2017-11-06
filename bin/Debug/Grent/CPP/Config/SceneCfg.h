#ifndef __SCENE_CONFIG_H
#define __SCENE_CONFIG_H

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


//场景配置数据结构
struct SceneElement
{
	friend class SceneTable;
	int id;                      	//序号	序号
	string comment;              	//	
	int name;                    	//场景名称	文本id
	int description;             	//场景描述	文本相关id
	string background_pic;       	//场景介绍图片	场景介绍图片
	string loading_pic;          	//场景读取图片	如果不填则显示默认图
	int thread_id;               	//线程ID	线程ID
	int scene_type;              	//副本类型	0：场景 1：副本 
	float valid_pos_x;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	float valid_pos_z;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	string scene_resource;       	//场景资源	资源路径
	int required_level;          	//所需等级	解锁该场景需要的等级
	float required_score;        	//所需战力	解锁该场景需要的战力
	int pre_quest;               	//前置任务	解锁该场景需要的任务
	int teleport_id;             	//默认生成点ID	如果没有指定生成的位置，玩家会默认出现在该点
	int camera_type;             	//摄像机类型	0：强制2.5D 1：3D&2.5D
	string pre_music;            	//前奏音乐	进入场景时播放的音乐前奏
	string loop_music;           	//循环音乐	在该场景循环播放的音乐

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
	unordered_map<int, SceneElement>	m_mapElements;
	vector<SceneElement>	m_vecAllElements;
	SceneElement m_emptyItem;
public:
	static SceneTable& Instance()
	{
		static SceneTable sInstance;
		return sInstance;
	}

	const SceneElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			SceneElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("SceneTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("SceneTable: ") + std::to_string(key)).c_str());
		return NULL;
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
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			SceneElement	member;

						member.id=p.get<int>("id");
			member.comment=p.get<string>("comment");
			member.name=p.get<int>("name");
			member.description=p.get<int>("description");
			member.background_pic=p.get<string>("background_pic");
			member.loading_pic=p.get<string>("loading_pic");
			member.thread_id=p.get<int>("thread_id");
			member.scene_type=p.get<int>("scene_type");
			member.valid_pos_x=p.get<float>("valid_pos_x");
			member.valid_pos_z=p.get<float>("valid_pos_z");
			member.scene_resource=p.get<string>("scene_resource");
			member.required_level=p.get<int>("required_level");
			member.required_score=p.get<float>("required_score");
			member.pre_quest=p.get<int>("pre_quest");
			member.teleport_id=p.get<int>("teleport_id");
			member.camera_type=p.get<int>("camera_type");
			member.pre_music=p.get<string>("pre_music");
			member.loop_music=p.get<string>("loop_music");


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
		if(vecLine.size() != 18)
		{
			printf_message("Scene.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Scene.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Scene.csv中字段[comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("Scene.csv中字段[name]位置不对应");assert(false); return false; }
		if(vecLine[3]!="description"){printf_message("Scene.csv中字段[description]位置不对应");assert(false); return false; }
		if(vecLine[4]!="background_pic"){printf_message("Scene.csv中字段[background_pic]位置不对应");assert(false); return false; }
		if(vecLine[5]!="loading_pic"){printf_message("Scene.csv中字段[loading_pic]位置不对应");assert(false); return false; }
		if(vecLine[6]!="thread_id"){printf_message("Scene.csv中字段[thread_id]位置不对应");assert(false); return false; }
		if(vecLine[7]!="scene_type"){printf_message("Scene.csv中字段[scene_type]位置不对应");assert(false); return false; }
		if(vecLine[8]!="valid_pos_x"){printf_message("Scene.csv中字段[valid_pos_x]位置不对应");assert(false); return false; }
		if(vecLine[9]!="valid_pos_z"){printf_message("Scene.csv中字段[valid_pos_z]位置不对应");assert(false); return false; }
		if(vecLine[10]!="scene_resource"){printf_message("Scene.csv中字段[scene_resource]位置不对应");assert(false); return false; }
		if(vecLine[11]!="required_level"){printf_message("Scene.csv中字段[required_level]位置不对应");assert(false); return false; }
		if(vecLine[12]!="required_score"){printf_message("Scene.csv中字段[required_score]位置不对应");assert(false); return false; }
		if(vecLine[13]!="pre_quest"){printf_message("Scene.csv中字段[pre_quest]位置不对应");assert(false); return false; }
		if(vecLine[14]!="teleport_id"){printf_message("Scene.csv中字段[teleport_id]位置不对应");assert(false); return false; }
		if(vecLine[15]!="camera_type"){printf_message("Scene.csv中字段[camera_type]位置不对应");assert(false); return false; }
		if(vecLine[16]!="pre_music"){printf_message("Scene.csv中字段[pre_music]位置不对应");assert(false); return false; }
		if(vecLine[17]!="loop_music"){printf_message("Scene.csv中字段[loop_music]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)18)
			{
				assert(false);
				return false;
			}
			SceneElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.description=(int)atoi(vecLine[3].c_str());
			member.background_pic=vecLine[4];
			member.loading_pic=vecLine[5];
			member.thread_id=(int)atoi(vecLine[6].c_str());
			member.scene_type=(int)atoi(vecLine[7].c_str());
			member.valid_pos_x=(float)atof(vecLine[8].c_str());
			member.valid_pos_z=(float)atof(vecLine[9].c_str());
			member.scene_resource=vecLine[10];
			member.required_level=(int)atoi(vecLine[11].c_str());
			member.required_score=(float)atof(vecLine[12].c_str());
			member.pre_quest=(int)atoi(vecLine[13].c_str());
			member.teleport_id=(int)atoi(vecLine[14].c_str());
			member.camera_type=(int)atoi(vecLine[15].c_str());
			member.pre_music=vecLine[16];
			member.loop_music=vecLine[17];

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
