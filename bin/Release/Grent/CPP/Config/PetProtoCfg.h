#ifndef __PETPROTO_CONFIG_H
#define __PETPROTO_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物原型表配置数据结构
struct PetProtoElement
{
	friend class PetProtoTable;
	int id;                      	//宠物id	填写ID即可
	string comment;              	//注释	策划用
	int is_display;              	//是否显示	是否在宠物图鉴中显示该宠物 0.不显示 1.显示
	int name;                    	//宠物名称	显示的宠物名称 StringItem_道具文本表
	int description;             	//宠物描述	用于在宠物召唤界面和宠物图鉴中显示
	string rarity;               	//宠物稀有度	稀有度对应的图片资源路径
	int rarity_color;            	//稀有度颜色	宠物品质框显示的颜色 1.绿色 2.蓝色 3.紫色 4.橙色
	int type;                    	//宠物分类	用于区分宠物功能方面的分类 1.防御 2.辅助 3.物理 4.法术
	string icon;                 	//宠物图标	宠物显示时的头像
	string model;                	//宠物模型	宠物在游戏中调用的模型
	vector<float> show_offside;  	//显示偏移	决定UI中的宠物偏移 X|Y|Z
	int init_index_id;           	//最低级index的id	暂时用来显示宠物模型 只在图鉴中调用
	float leisure_pro;           	//播放休闲动画几率	1=100%
	string talent_pic;           	//资质雷达图	宠物对应的资质雷达图的资源名称
	int speed;                   	//移动速度	宠物默认移动速度
	float run_rate;              	//移动速率	该宠物移动时播放动画的倍率 默认1.0
	int spawn_action;            	//出生动画	宠物出生时的动画  对应技能表中不广播技能
	int possesssed_action;       	//附身动画	宠物进战时的动画  对应技能表中不广播技能
	string transform_eff;        	//进战特效	宠物变成光球的特效
	string lightsphere_eff;      	//光球特效	光球飞行中的特效
	string possesssed_buff;      	//附身特效	宠物进战时播放的特效  对应buff表中配置
	int leave_fight_action;      	//脱战动画	宠物脱战时的动画  对应技能表中不广播技能
	int interact_action;         	//交互动画	宠物交互时的动画  对应技能表中不广播技能
	int level_up_action;         	//升级动画	宠物培养成功时的动画  对应技能表中不广播技能
	int active_skill;            	//主动技能	宠物对应的主动技能的id
	vector<int> passive_skill;   	//被动技能	宠物生成时自带被动技能的id 数组，最多8个

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
	PetProtoElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物原型表配置封装类
class PetProtoTable
{
	friend class TableData;
private:
	PetProtoTable(){}
	~PetProtoTable(){}
	map<int, PetProtoElement>	m_mapElements;
	vector<PetProtoElement>	m_vecAllElements;
	PetProtoElement m_emptyItem;
public:
	static PetProtoTable& Instance()
	{
		static PetProtoTable sInstance;
		return sInstance;
	}

	PetProtoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetProtoElement>&	GetAllElement()
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
		if( LoadConfigContent("PetProto.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetProto.bin", strTableContent ) )
		{
			printf_message("配置文件[PetProto.bin]未找到");
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
		if(vecLine.size() != 26)
		{
			printf_message("PetProto.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetProto.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetProto.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="is_display"){printf_message("PetProto.csv中字段[is_display]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("PetProto.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="description"){printf_message("PetProto.csv中字段[description]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="rarity"){printf_message("PetProto.csv中字段[rarity]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="rarity_color"){printf_message("PetProto.csv中字段[rarity_color]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="type"){printf_message("PetProto.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="icon"){printf_message("PetProto.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="model"){printf_message("PetProto.csv中字段[model]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="show_offside"){printf_message("PetProto.csv中字段[show_offside]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="init_index_id"){printf_message("PetProto.csv中字段[init_index_id]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="leisure_pro"){printf_message("PetProto.csv中字段[leisure_pro]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="talent_pic"){printf_message("PetProto.csv中字段[talent_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="speed"){printf_message("PetProto.csv中字段[speed]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="run_rate"){printf_message("PetProto.csv中字段[run_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="spawn_action"){printf_message("PetProto.csv中字段[spawn_action]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="possesssed_action"){printf_message("PetProto.csv中字段[possesssed_action]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="transform_eff"){printf_message("PetProto.csv中字段[transform_eff]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="lightsphere_eff"){printf_message("PetProto.csv中字段[lightsphere_eff]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="possesssed_buff"){printf_message("PetProto.csv中字段[possesssed_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="leave_fight_action"){printf_message("PetProto.csv中字段[leave_fight_action]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="interact_action"){printf_message("PetProto.csv中字段[interact_action]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="level_up_action"){printf_message("PetProto.csv中字段[level_up_action]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="active_skill"){printf_message("PetProto.csv中字段[active_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="passive_skill"){printf_message("PetProto.csv中字段[passive_skill]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)26)
			{
				assert(false);
				return false;
			}
			PetProtoElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.is_display=(int)atoi(vecLine[2].c_str());
			member.name=(int)atoi(vecLine[3].c_str());
			member.description=(int)atoi(vecLine[4].c_str());
			member.rarity=vecLine[5];
			member.rarity_color=(int)atoi(vecLine[6].c_str());
			member.type=(int)atoi(vecLine[7].c_str());
			member.icon=vecLine[8];
			member.model=vecLine[9];
			member.init_index_id=(int)atoi(vecLine[11].c_str());
			member.leisure_pro=(float)atof(vecLine[12].c_str());
			member.talent_pic=vecLine[13];
			member.speed=(int)atoi(vecLine[14].c_str());
			member.run_rate=(float)atof(vecLine[15].c_str());
			member.spawn_action=(int)atoi(vecLine[16].c_str());
			member.possesssed_action=(int)atoi(vecLine[17].c_str());
			member.transform_eff=vecLine[18];
			member.lightsphere_eff=vecLine[19];
			member.possesssed_buff=vecLine[20];
			member.leave_fight_action=(int)atoi(vecLine[21].c_str());
			member.interact_action=(int)atoi(vecLine[22].c_str());
			member.level_up_action=(int)atoi(vecLine[23].c_str());
			member.active_skill=(int)atoi(vecLine[24].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
