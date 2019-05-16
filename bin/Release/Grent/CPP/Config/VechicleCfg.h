#ifndef __VECHICLE_CONFIG_H
#define __VECHICLE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//载具表配置数据结构
struct VechicleElement
{
	friend class VechicleTable;
	int id;                      	//序号	ID段规则：5位数起，跟随场景ID规则而定 5位数以前为测试用
	string comment;              	//坐骑备注	仅策划用
	int type;                    	//坐骑类型	1为变身型载具 2为挂点连接型载具（人移动） 3为挂点连接型载具（载具移动）
	int model_id;                	//模型ID	用于规定所使用的模型 如果type=1，关联character_config表； 如果type=2或3，关联CharacterCustomize表
	string shapeshift_animation_caster;	//变身动画-释放者动作	取自Raw_Animation_Monster
	string shapeshift_animation_target;	//变身动画-变身后衔接动作	取自Raw_Animation_Monster
	string shapeshift_effect;    	//变身特效	取自Res_Prefabs_Effect_Skill
	int shapeshift_time;         	//变身时长	单位毫秒
	int change_skill;            	//是否切换技能	0：不切换 1：切换
	vector<int> skill_list;      	//切换的技能列表	格式：skillid|skillid|skillid
	int not_in_battle;           	//是否能在战斗状态使用	如果为1，代表该功能可以在战斗中使用；2为禁止在战斗中使用。标识为2后，如果玩家进入战斗或释放技能，则自动回到玩家的初始状态（即移除模型变化、技能变化）
	int can_move;                	//是否可自由移动	是否可自由移动 0：不可移动 1：可移动
	int player_move_speed;       	//移动速度	交互后玩家的移动速度，0为不允许移动
	int can_exit;                	//是否可手动退出	是否可以手动退出载具状态： 1为可以，且在屏幕上出现退出图标；同时到达最终路点后不会自动退出载具 2为不可以。（任务需要额外注意）；同时到达最终路点后会自动退出载具
	string shapeshift_exit_animation_caster;	//取消变身动画-释放者	取自Raw_Animation_Monster
	string shapeshift_exit_animation_tatget;	//取消变身动画-变身后衔接动画	取自Raw_Animation_Monster
	string shapeshift_exit_effect;	//取消变身特效	取自Res_Prefabs_Effect_Skill
	int shapeshift_exit_time;    	//取消变身时长	单位毫秒
	int quest_id;                	//任务ID	所绑定的任务ID，当玩家身上没有该任务时，无法触发载具功能。如果玩家在载具状态下，任务完成，则要回归到玩家的初始状态。
	vector<int> waypoint_list;   	//路点列表	填写起始路点|最终路点 如果有值，则在交互后，自动将玩家或其改变的模型放置在起始路点，并开始沿着下一个路点移动，直到最终路点。玩家无法自由移动。 路点与路点之间使用|作为间隔。 路点表增加fly_height列，规定飞行的高度
	int visible_type;            	//可见类型	1. 飞行不可见 2. 地面可见 3. 地面不可见 
	float initial_velocity;      	//初始速率	坐骑动画的默认速率（m/s）

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
	VechicleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//载具表配置封装类
class VechicleTable
{
	friend class TableData;
private:
	VechicleTable(){}
	~VechicleTable(){}
	map<int, VechicleElement>	m_mapElements;
	vector<VechicleElement>	m_vecAllElements;
	VechicleElement m_emptyItem;
public:
	static VechicleTable& Instance()
	{
		static VechicleTable sInstance;
		return sInstance;
	}

	VechicleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<VechicleElement>&	GetAllElement()
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
		if( LoadConfigContent("Vechicle.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Vechicle.bin", strTableContent ) )
		{
			printf_message("配置文件[Vechicle.bin]未找到");
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
		if(vecLine.size() != 22)
		{
			printf_message("Vechicle.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Vechicle.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Vechicle.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="type"){printf_message("Vechicle.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="model_id"){printf_message("Vechicle.csv中字段[model_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="shapeshift_animation_caster"){printf_message("Vechicle.csv中字段[shapeshift_animation_caster]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="shapeshift_animation_target"){printf_message("Vechicle.csv中字段[shapeshift_animation_target]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="shapeshift_effect"){printf_message("Vechicle.csv中字段[shapeshift_effect]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="shapeshift_time"){printf_message("Vechicle.csv中字段[shapeshift_time]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="change_skill"){printf_message("Vechicle.csv中字段[change_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="skill_list"){printf_message("Vechicle.csv中字段[skill_list]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="not_in_battle"){printf_message("Vechicle.csv中字段[not_in_battle]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="can_move"){printf_message("Vechicle.csv中字段[can_move]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="player_move_speed"){printf_message("Vechicle.csv中字段[player_move_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="can_exit"){printf_message("Vechicle.csv中字段[can_exit]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="shapeshift_exit_animation_caster"){printf_message("Vechicle.csv中字段[shapeshift_exit_animation_caster]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="shapeshift_exit_animation_tatget"){printf_message("Vechicle.csv中字段[shapeshift_exit_animation_tatget]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="shapeshift_exit_effect"){printf_message("Vechicle.csv中字段[shapeshift_exit_effect]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="shapeshift_exit_time"){printf_message("Vechicle.csv中字段[shapeshift_exit_time]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="quest_id"){printf_message("Vechicle.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="waypoint_list"){printf_message("Vechicle.csv中字段[waypoint_list]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="visible_type"){printf_message("Vechicle.csv中字段[visible_type]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="initial_velocity"){printf_message("Vechicle.csv中字段[initial_velocity]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)22)
			{
				assert(false);
				return false;
			}
			VechicleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.type=(int)atoi(vecLine[2].c_str());
			member.model_id=(int)atoi(vecLine[3].c_str());
			member.shapeshift_animation_caster=vecLine[4];
			member.shapeshift_animation_target=vecLine[5];
			member.shapeshift_effect=vecLine[6];
			member.shapeshift_time=(int)atoi(vecLine[7].c_str());
			member.change_skill=(int)atoi(vecLine[8].c_str());
			member.not_in_battle=(int)atoi(vecLine[10].c_str());
			member.can_move=(int)atoi(vecLine[11].c_str());
			member.player_move_speed=(int)atoi(vecLine[12].c_str());
			member.can_exit=(int)atoi(vecLine[13].c_str());
			member.shapeshift_exit_animation_caster=vecLine[14];
			member.shapeshift_exit_animation_tatget=vecLine[15];
			member.shapeshift_exit_effect=vecLine[16];
			member.shapeshift_exit_time=(int)atoi(vecLine[17].c_str());
			member.quest_id=(int)atoi(vecLine[18].c_str());
			member.visible_type=(int)atoi(vecLine[20].c_str());
			member.initial_velocity=(float)atof(vecLine[21].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
