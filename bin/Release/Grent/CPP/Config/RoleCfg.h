#ifndef __ROLE_CONFIG_H
#define __ROLE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色属性配置数据结构
struct RoleElement
{
	friend class RoleTable;
	int id;                      	//id	种族*100000+职业*10+性别
	string comment;              	//注释	注释
	int race;                    	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	int occupation;              	//职业	1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士 6：神秘使
	string characteristic;       	//职业特色	职业特色
	int gender;                  	//性别	1:男性 2:女性
	string race_icon;            	//种族图标	种族图标
	int race_name;               	//种族名称	种族名称
	int race_desc;               	//种族介绍	种族介绍
	string occu_icon;            	//职业图标	职业图标
	vector<string> concentrate1_icon;	//专精1图标	专精1图标
	int concentrate1_name;       	//专精1名称	专精1名称
	int concentrate1_desc;       	//专精1介绍	专精1介绍
	vector<string> concentrate2_icon;	//专精2图标	专精2图标
	int concentrate2_name;       	//专精2名称	专精2名称
	int concentrate2_desc;       	//专精2介绍	专精2介绍
	vector<string> create_occu_icon;	//创建界面图标	专门用在创建界面的 职业头像 对应未选中和选中两个状态
	vector<string> select_occu_icon;	//选择界面图标	专门用在选择界面的 职业标示 对应未选中和选中两个状态
	int occu_name;               	//职业名称	职业名称
	int occu_desc;               	//职业介绍	职业介绍
	string occu_evaluate;        	//职业评估	对应每个职业特性图路径
	int show_model;              	//展示模型id	在角色创建界面上显示的模型id
	string default_headshot;     	//默认头像	默认在游戏中使用的头像
	string default_portrait;     	//默认肖像	默认在游戏中使用的全身像
	int model_id;                	//初始模型id	初始模型id
	float leisure_pro;           	//播放休闲动画几率	1=100%
	string select_model;         	//临时选择角色显示模型	目前在属性界面中调用
	float animation;             	//出场动画时间(秒)	出场动画时间(秒)
	string initial_skeleton;     	//角色初始骨骼	
	int initial_face;            	//初始面部模型	
	int initial_head;            	//初始头部模型	
	int initial_body;            	//初始身体模型	
	int initial_weapon;          	//初始武器模型	
	float camera_size;           	//属性界面摄像机的缩放参数	数值越大角色模型显示越小 默认为1
	vector<float> camera_pos;    	//属性界面摄像机的位移参数	分别表示摄像机的X和Y轴偏移 默认为0|0
	int attack_type;             	//角色普攻类型	0.物理 1.魔法
	int initial_level;           	//初始等级	初始等级
	int initial_weapon_equip;    	//初始武器	初始武器
	int initial_head_equip;      	//初始头盔	初始头盔
	int initial_earring_equip;   	//初始耳环	初始耳环
	int initial_chest_equip;     	//初始胸甲	初始胸甲
	int initial_necklace_equip;  	//初始项链	初始项链
	int initial_hand_equip;      	//初始手甲	初始手甲
	int initial_ring_equip;      	//初始戒指	初始戒指
	int initial_foot_equip;      	//初始靴子	初始靴子
	int initial_quest;           	//初始任务	初始任务
	int nomorl_attack;           	//普攻id	

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
	RoleElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色属性配置封装类
class RoleTable
{
	friend class TableData;
private:
	RoleTable(){}
	~RoleTable(){}
	map<int, RoleElement>	m_mapElements;
	vector<RoleElement>	m_vecAllElements;
	RoleElement m_emptyItem;
public:
	static RoleTable& Instance()
	{
		static RoleTable sInstance;
		return sInstance;
	}

	RoleElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RoleElement>&	GetAllElement()
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
		if( LoadConfigContent("Role.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Role.bin", strTableContent ) )
		{
			printf_message("配置文件[Role.bin]未找到");
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
		if(vecLine.size() != 47)
		{
			printf_message("Role.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Role.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Role.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="race"){printf_message("Role.csv中字段[race]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="occupation"){printf_message("Role.csv中字段[occupation]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="characteristic"){printf_message("Role.csv中字段[characteristic]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="gender"){printf_message("Role.csv中字段[gender]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="race_icon"){printf_message("Role.csv中字段[race_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="race_name"){printf_message("Role.csv中字段[race_name]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="race_desc"){printf_message("Role.csv中字段[race_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="occu_icon"){printf_message("Role.csv中字段[occu_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="concentrate1_icon"){printf_message("Role.csv中字段[concentrate1_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="concentrate1_name"){printf_message("Role.csv中字段[concentrate1_name]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="concentrate1_desc"){printf_message("Role.csv中字段[concentrate1_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="concentrate2_icon"){printf_message("Role.csv中字段[concentrate2_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="concentrate2_name"){printf_message("Role.csv中字段[concentrate2_name]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="concentrate2_desc"){printf_message("Role.csv中字段[concentrate2_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="create_occu_icon"){printf_message("Role.csv中字段[create_occu_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="select_occu_icon"){printf_message("Role.csv中字段[select_occu_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="occu_name"){printf_message("Role.csv中字段[occu_name]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="occu_desc"){printf_message("Role.csv中字段[occu_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="occu_evaluate"){printf_message("Role.csv中字段[occu_evaluate]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="show_model"){printf_message("Role.csv中字段[show_model]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="default_headshot"){printf_message("Role.csv中字段[default_headshot]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="default_portrait"){printf_message("Role.csv中字段[default_portrait]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="model_id"){printf_message("Role.csv中字段[model_id]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="leisure_pro"){printf_message("Role.csv中字段[leisure_pro]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="select_model"){printf_message("Role.csv中字段[select_model]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="animation"){printf_message("Role.csv中字段[animation]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="initial_skeleton"){printf_message("Role.csv中字段[initial_skeleton]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="initial_face"){printf_message("Role.csv中字段[initial_face]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="initial_head"){printf_message("Role.csv中字段[initial_head]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="initial_body"){printf_message("Role.csv中字段[initial_body]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="initial_weapon"){printf_message("Role.csv中字段[initial_weapon]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="camera_size"){printf_message("Role.csv中字段[camera_size]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="camera_pos"){printf_message("Role.csv中字段[camera_pos]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="attack_type"){printf_message("Role.csv中字段[attack_type]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="initial_level"){printf_message("Role.csv中字段[initial_level]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="initial_weapon_equip"){printf_message("Role.csv中字段[initial_weapon_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="initial_head_equip"){printf_message("Role.csv中字段[initial_head_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="initial_earring_equip"){printf_message("Role.csv中字段[initial_earring_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="initial_chest_equip"){printf_message("Role.csv中字段[initial_chest_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="initial_necklace_equip"){printf_message("Role.csv中字段[initial_necklace_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="initial_hand_equip"){printf_message("Role.csv中字段[initial_hand_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="initial_ring_equip"){printf_message("Role.csv中字段[initial_ring_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="initial_foot_equip"){printf_message("Role.csv中字段[initial_foot_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="initial_quest"){printf_message("Role.csv中字段[initial_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="nomorl_attack"){printf_message("Role.csv中字段[nomorl_attack]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)47)
			{
				assert(false);
				return false;
			}
			RoleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.race=(int)atoi(vecLine[2].c_str());
			member.occupation=(int)atoi(vecLine[3].c_str());
			member.characteristic=vecLine[4];
			member.gender=(int)atoi(vecLine[5].c_str());
			member.race_icon=vecLine[6];
			member.race_name=(int)atoi(vecLine[7].c_str());
			member.race_desc=(int)atoi(vecLine[8].c_str());
			member.occu_icon=vecLine[9];
			member.concentrate1_name=(int)atoi(vecLine[11].c_str());
			member.concentrate1_desc=(int)atoi(vecLine[12].c_str());
			member.concentrate2_name=(int)atoi(vecLine[14].c_str());
			member.concentrate2_desc=(int)atoi(vecLine[15].c_str());
			member.occu_name=(int)atoi(vecLine[18].c_str());
			member.occu_desc=(int)atoi(vecLine[19].c_str());
			member.occu_evaluate=vecLine[20];
			member.show_model=(int)atoi(vecLine[21].c_str());
			member.default_headshot=vecLine[22];
			member.default_portrait=vecLine[23];
			member.model_id=(int)atoi(vecLine[24].c_str());
			member.leisure_pro=(float)atof(vecLine[25].c_str());
			member.select_model=vecLine[26];
			member.animation=(float)atof(vecLine[27].c_str());
			member.initial_skeleton=vecLine[28];
			member.initial_face=(int)atoi(vecLine[29].c_str());
			member.initial_head=(int)atoi(vecLine[30].c_str());
			member.initial_body=(int)atoi(vecLine[31].c_str());
			member.initial_weapon=(int)atoi(vecLine[32].c_str());
			member.camera_size=(float)atof(vecLine[33].c_str());
			member.attack_type=(int)atoi(vecLine[35].c_str());
			member.initial_level=(int)atoi(vecLine[36].c_str());
			member.initial_weapon_equip=(int)atoi(vecLine[37].c_str());
			member.initial_head_equip=(int)atoi(vecLine[38].c_str());
			member.initial_earring_equip=(int)atoi(vecLine[39].c_str());
			member.initial_chest_equip=(int)atoi(vecLine[40].c_str());
			member.initial_necklace_equip=(int)atoi(vecLine[41].c_str());
			member.initial_hand_equip=(int)atoi(vecLine[42].c_str());
			member.initial_ring_equip=(int)atoi(vecLine[43].c_str());
			member.initial_foot_equip=(int)atoi(vecLine[44].c_str());
			member.initial_quest=(int)atoi(vecLine[45].c_str());
			member.nomorl_attack=(int)atoi(vecLine[46].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
