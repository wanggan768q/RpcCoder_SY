#ifndef __PETCAPTURESHOW_CONFIG_H
#define __PETCAPTURESHOW_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物捕获前端配置数据结构
struct PetCaptureShowElement
{
	friend class PetCaptureShowTable;
	int id;                      	//宠物id	填写ID即可
	string comment;              	//注释	策划用
	int name;                    	//宠物名称	显示的宠物名称 StringItem_道具文本表
	int description;             	//宠物描述	用于在宠物召唤界面和宠物图鉴中显示
	string rarity;               	//宠物稀有度	稀有度对应的图片资源路径
	int type;                    	//宠物分类	用于区分宠物功能方面的分类 1.防御 2.辅助 3.物理 4.法术
	string icon;                 	//宠物图标	宠物显示时的头像
	string model;                	//宠物模型	宠物在游戏中调用的模型
	string talent_pic;           	//资质雷达图	宠物对应的资质雷达图的资源名称
	int speed;                   	//移动速度	宠物默认移动速度
	int spawn_action;            	//出生动画	宠物出生时的动画  对应技能表中不广播技能
	int possesssed_action;       	//附身动画	宠物进战时的动画  对应技能表中不广播技能
	int possesssed_buff;         	//附身特效	宠物进战时播放的特效  对应buff表中配置
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
	PetCaptureShowElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物捕获前端配置封装类
class PetCaptureShowTable
{
	friend class TableData;
private:
	PetCaptureShowTable(){}
	~PetCaptureShowTable(){}
	map<int, PetCaptureShowElement>	m_mapElements;
	vector<PetCaptureShowElement>	m_vecAllElements;
	PetCaptureShowElement m_emptyItem;
public:
	static PetCaptureShowTable& Instance()
	{
		static PetCaptureShowTable sInstance;
		return sInstance;
	}

	PetCaptureShowElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetCaptureShowElement>&	GetAllElement()
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
		if( LoadConfigContent("PetCaptureShow.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetCaptureShow.bin", strTableContent ) )
		{
			printf_message("配置文件[PetCaptureShow.bin]未找到");
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
		if(vecLine.size() != 18)
		{
			printf_message("PetCaptureShow.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetCaptureShow.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetCaptureShow.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("PetCaptureShow.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="description"){printf_message("PetCaptureShow.csv中字段[description]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="rarity"){printf_message("PetCaptureShow.csv中字段[rarity]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="type"){printf_message("PetCaptureShow.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="icon"){printf_message("PetCaptureShow.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="model"){printf_message("PetCaptureShow.csv中字段[model]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="talent_pic"){printf_message("PetCaptureShow.csv中字段[talent_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="speed"){printf_message("PetCaptureShow.csv中字段[speed]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="spawn_action"){printf_message("PetCaptureShow.csv中字段[spawn_action]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="possesssed_action"){printf_message("PetCaptureShow.csv中字段[possesssed_action]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="possesssed_buff"){printf_message("PetCaptureShow.csv中字段[possesssed_buff]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="leave_fight_action"){printf_message("PetCaptureShow.csv中字段[leave_fight_action]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="interact_action"){printf_message("PetCaptureShow.csv中字段[interact_action]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="level_up_action"){printf_message("PetCaptureShow.csv中字段[level_up_action]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="active_skill"){printf_message("PetCaptureShow.csv中字段[active_skill]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="passive_skill"){printf_message("PetCaptureShow.csv中字段[passive_skill]位置不对应 ");assert(false); return false; }

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
			PetCaptureShowElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.description=(int)atoi(vecLine[3].c_str());
			member.rarity=vecLine[4];
			member.type=(int)atoi(vecLine[5].c_str());
			member.icon=vecLine[6];
			member.model=vecLine[7];
			member.talent_pic=vecLine[8];
			member.speed=(int)atoi(vecLine[9].c_str());
			member.spawn_action=(int)atoi(vecLine[10].c_str());
			member.possesssed_action=(int)atoi(vecLine[11].c_str());
			member.possesssed_buff=(int)atoi(vecLine[12].c_str());
			member.leave_fight_action=(int)atoi(vecLine[13].c_str());
			member.interact_action=(int)atoi(vecLine[14].c_str());
			member.level_up_action=(int)atoi(vecLine[15].c_str());
			member.active_skill=(int)atoi(vecLine[16].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
