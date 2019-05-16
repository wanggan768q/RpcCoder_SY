#ifndef __DUNGEON_CONFIG_H
#define __DUNGEON_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//副本表配置数据结构
struct DungeonElement
{
	friend class DungeonTable;
	int id;                      	//序号	序号
	string comment;              	//	
	int map_id;                  	//场景ID	对应Scene_场景表
	int dungeon_type;            	//副本类型	
	int order;                   	//副本查找器索引	副本查找器索引顺序
	int enter_location;          	//进入副本路点	野外地图进入副本传送门的位置，对应路点表
	int difficult;               	//难度文本	对应StringUi_界面文本表
	vector<int> level;           	//玩家等级	所需玩家等级 等级下限|等级上限
	vector<int> player_config_list;	//玩家职能推荐	坦克人数|治疗人数|输出人数
	string obj_group;            	//	怪物所属分组，
	int min_num;                 	//最小玩家数量	默认为1
	int max_num;                 	//最大玩家数量	默认为1
	int required_last_dungeon_id;	//所需前置副本ID	
	int reset_type;              	//重置类型	
	int finish_amount;           	//允许玩家完成次数	
	int friendship_add;          	//友好度增加	好友组队进行副本增加的友好度数值
	int name_id;                 	//副本名字ID	对应StringUi_界面文本表
	int describle_id;            	//副本描述ID	对应StringUi_界面文本表
	int simple_describle_id;     	//副本简单描述ID	对应StringUi_界面文本表
	int mini_pic;                	//进副时弹出的面板中的副本图片	
	int First_reward_ui;         	//首通奖励礼包ID	
	int general_reward__ui;      	//非首通奖励礼包ID	
	int is_transfer;             	//是否需要装备中转表	
	string start_music;          	//开启音乐	
	string loop_music;           	//循环音乐	
	int endingboss_id;           	//最后boss ID	对应Creature_总NPC表
	int duration_time;           	//副本存活时间	
	int destroy_time;            	//副本摧毁时间	秒为单位
	int conclusion_time;         	//副本结算时间	s为单位
	int start_time;              	//副本开启时间	
	int end_time;                	//副本关闭时间	
	int teleport_id;             	//通关传送门ID	
	int teleport_location;       	//传送门生成路点	对应WayPoint_路点表ID
	string teleporteffect;       	//传送门特效	
	int exit_waypoint;           	//退出副本后的路点	对应WayPoint_路点表ID
	string monster_id;           	//副本怪物ID	不同难度副本对应的不同的Monster.json文件，-1表示未配置Monster.json文件
	string dungeon_lua;          	//副本脚本	对应 ice_server\trunk\bin\Config\Script\Dungeon下的脚本
	vector<int> area_id;         	//区域id	
	int monster_delay;           	//刷怪延迟	创建副本后n秒刷怪  单位：秒
	int second_verification;     	//二次确认	副本最低进入人数＞1该字段生效 效果是进入副本时是否弹出二次确认面板 0需要 1不需要

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
	map<int, DungeonElement>	m_mapElements;
	vector<DungeonElement>	m_vecAllElements;
	DungeonElement m_emptyItem;
public:
	static DungeonTable& Instance()
	{
		static DungeonTable sInstance;
		return sInstance;
	}

	DungeonElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
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
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 40)
		{
			printf_message("Dungeon.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Dungeon.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Dungeon.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="map_id"){printf_message("Dungeon.csv中字段[map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="dungeon_type"){printf_message("Dungeon.csv中字段[dungeon_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="order"){printf_message("Dungeon.csv中字段[order]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="enter_location"){printf_message("Dungeon.csv中字段[enter_location]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="difficult"){printf_message("Dungeon.csv中字段[difficult]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="level"){printf_message("Dungeon.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="player_config_list"){printf_message("Dungeon.csv中字段[player_config_list]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="obj_group"){printf_message("Dungeon.csv中字段[obj_group]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="min_num"){printf_message("Dungeon.csv中字段[min_num]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="max_num"){printf_message("Dungeon.csv中字段[max_num]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="required_last_dungeon_id"){printf_message("Dungeon.csv中字段[required_last_dungeon_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="reset_type"){printf_message("Dungeon.csv中字段[reset_type]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="finish_amount"){printf_message("Dungeon.csv中字段[finish_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="friendship_add"){printf_message("Dungeon.csv中字段[friendship_add]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="name_id"){printf_message("Dungeon.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="describle_id"){printf_message("Dungeon.csv中字段[describle_id]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="simple_describle_id"){printf_message("Dungeon.csv中字段[simple_describle_id]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="mini_pic"){printf_message("Dungeon.csv中字段[mini_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="First_reward_ui"){printf_message("Dungeon.csv中字段[First_reward_ui]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="general_reward__ui"){printf_message("Dungeon.csv中字段[general_reward__ui]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="is_transfer"){printf_message("Dungeon.csv中字段[is_transfer]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="start_music"){printf_message("Dungeon.csv中字段[start_music]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="loop_music"){printf_message("Dungeon.csv中字段[loop_music]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="endingboss_id"){printf_message("Dungeon.csv中字段[endingboss_id]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="duration_time"){printf_message("Dungeon.csv中字段[duration_time]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="destroy_time"){printf_message("Dungeon.csv中字段[destroy_time]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="conclusion_time"){printf_message("Dungeon.csv中字段[conclusion_time]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="start_time"){printf_message("Dungeon.csv中字段[start_time]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="end_time"){printf_message("Dungeon.csv中字段[end_time]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="teleport_id"){printf_message("Dungeon.csv中字段[teleport_id]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="teleport_location"){printf_message("Dungeon.csv中字段[teleport_location]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="teleporteffect"){printf_message("Dungeon.csv中字段[teleporteffect]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="exit_waypoint"){printf_message("Dungeon.csv中字段[exit_waypoint]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="monster_id"){printf_message("Dungeon.csv中字段[monster_id]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="dungeon_lua"){printf_message("Dungeon.csv中字段[dungeon_lua]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="area_id"){printf_message("Dungeon.csv中字段[area_id]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="monster_delay"){printf_message("Dungeon.csv中字段[monster_delay]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="second_verification"){printf_message("Dungeon.csv中字段[second_verification]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)40)
			{
				assert(false);
				return false;
			}
			DungeonElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.map_id=(int)atoi(vecLine[2].c_str());
			member.dungeon_type=(int)atoi(vecLine[3].c_str());
			member.order=(int)atoi(vecLine[4].c_str());
			member.enter_location=(int)atoi(vecLine[5].c_str());
			member.difficult=(int)atoi(vecLine[6].c_str());
			member.obj_group=vecLine[9];
			member.min_num=(int)atoi(vecLine[10].c_str());
			member.max_num=(int)atoi(vecLine[11].c_str());
			member.required_last_dungeon_id=(int)atoi(vecLine[12].c_str());
			member.reset_type=(int)atoi(vecLine[13].c_str());
			member.finish_amount=(int)atoi(vecLine[14].c_str());
			member.friendship_add=(int)atoi(vecLine[15].c_str());
			member.name_id=(int)atoi(vecLine[16].c_str());
			member.describle_id=(int)atoi(vecLine[17].c_str());
			member.simple_describle_id=(int)atoi(vecLine[18].c_str());
			member.mini_pic=(int)atoi(vecLine[19].c_str());
			member.First_reward_ui=(int)atoi(vecLine[20].c_str());
			member.general_reward__ui=(int)atoi(vecLine[21].c_str());
			member.is_transfer=(int)atoi(vecLine[22].c_str());
			member.start_music=vecLine[23];
			member.loop_music=vecLine[24];
			member.endingboss_id=(int)atoi(vecLine[25].c_str());
			member.duration_time=(int)atoi(vecLine[26].c_str());
			member.destroy_time=(int)atoi(vecLine[27].c_str());
			member.conclusion_time=(int)atoi(vecLine[28].c_str());
			member.start_time=(int)atoi(vecLine[29].c_str());
			member.end_time=(int)atoi(vecLine[30].c_str());
			member.teleport_id=(int)atoi(vecLine[31].c_str());
			member.teleport_location=(int)atoi(vecLine[32].c_str());
			member.teleporteffect=vecLine[33];
			member.exit_waypoint=(int)atoi(vecLine[34].c_str());
			member.monster_id=vecLine[35];
			member.dungeon_lua=vecLine[36];
			member.monster_delay=(int)atoi(vecLine[38].c_str());
			member.second_verification=(int)atoi(vecLine[39].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
