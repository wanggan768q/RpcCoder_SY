#ifndef __CREATURETEMPERCONFIG_CONFIG_H
#define __CREATURETEMPERCONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//NPC行为参数配置数据结构
struct CreatureTemperConfigElement
{
	friend class CreatureTemperConfigTable;
	int id;                      	//性格ID	关联Creature
	string comment;              	//备注	仅策划用
	int search_style;            	// 索敌类型	0=范围索敌 1=全图索敌
	int hatred_range;            	//仇恨清除半径	大于该距离清除0仇恨角色 单位：米 “-1”=无限距离
	float search_distance;       	//锁敌距离	单位：米
	int chase_type;              	//追敌类型	0=范围追敌 1=全图追敌
	int chase_distance;          	//追击距离	单位：米
	int chase_time;              	//回归时间	单位：毫秒
	float chase_speed;           	//回归加速度	单位：米/秒
	int hatred_area;             	//仇恨区域	进战后定期为区域内的玩家增加仇恨值 单位：米（半径） 慎用！
	float patrol_range;          	//巡逻范围	单位：米
	int patrol_interval;         	//巡逻间隔	单位：毫秒
	float harass_range;          	//绕敌圈半径	单位：米
	int harass_probability1;     	//在绕敌圈内绕敌几率	10000=%100
	int harass_probability2;     	//在绕地圈外绕敌几率	10000=%100
	float harass_distance;       	// 绕敌半径	单位：米
	float harass_angle;          	// 绕敌角度	单位：度
	int harass_timeout;          	// 绕敌超时时间	单位：毫秒
	float cd_chase_dist;         	//技能cd时追敌距离	停止在拒敌x米处
	float harass_speed;          	//加速绕敌速度	单位：米/秒

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
	CreatureTemperConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC行为参数配置封装类
class CreatureTemperConfigTable
{
	friend class TableData;
private:
	CreatureTemperConfigTable(){}
	~CreatureTemperConfigTable(){}
	map<int, CreatureTemperConfigElement>	m_mapElements;
	vector<CreatureTemperConfigElement>	m_vecAllElements;
	CreatureTemperConfigElement m_emptyItem;
public:
	static CreatureTemperConfigTable& Instance()
	{
		static CreatureTemperConfigTable sInstance;
		return sInstance;
	}

	CreatureTemperConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureTemperConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("CreatureTemperConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureTemperConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureTemperConfig.bin]未找到");
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
		if(vecLine.size() != 20)
		{
			printf_message("CreatureTemperConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreatureTemperConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CreatureTemperConfig.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="search_style"){printf_message("CreatureTemperConfig.csv中字段[search_style]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="hatred_range"){printf_message("CreatureTemperConfig.csv中字段[hatred_range]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="search_distance"){printf_message("CreatureTemperConfig.csv中字段[search_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="chase_type"){printf_message("CreatureTemperConfig.csv中字段[chase_type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="chase_distance"){printf_message("CreatureTemperConfig.csv中字段[chase_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="chase_time"){printf_message("CreatureTemperConfig.csv中字段[chase_time]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="chase_speed"){printf_message("CreatureTemperConfig.csv中字段[chase_speed]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="hatred_area"){printf_message("CreatureTemperConfig.csv中字段[hatred_area]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="patrol_range"){printf_message("CreatureTemperConfig.csv中字段[patrol_range]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="patrol_interval"){printf_message("CreatureTemperConfig.csv中字段[patrol_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="harass_range"){printf_message("CreatureTemperConfig.csv中字段[harass_range]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="harass_probability1"){printf_message("CreatureTemperConfig.csv中字段[harass_probability1]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="harass_probability2"){printf_message("CreatureTemperConfig.csv中字段[harass_probability2]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="harass_distance"){printf_message("CreatureTemperConfig.csv中字段[harass_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="harass_angle"){printf_message("CreatureTemperConfig.csv中字段[harass_angle]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="harass_timeout"){printf_message("CreatureTemperConfig.csv中字段[harass_timeout]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="cd_chase_dist"){printf_message("CreatureTemperConfig.csv中字段[cd_chase_dist]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="harass_speed"){printf_message("CreatureTemperConfig.csv中字段[harass_speed]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)20)
			{
				assert(false);
				return false;
			}
			CreatureTemperConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.search_style=(int)atoi(vecLine[2].c_str());
			member.hatred_range=(int)atoi(vecLine[3].c_str());
			member.search_distance=(float)atof(vecLine[4].c_str());
			member.chase_type=(int)atoi(vecLine[5].c_str());
			member.chase_distance=(int)atoi(vecLine[6].c_str());
			member.chase_time=(int)atoi(vecLine[7].c_str());
			member.chase_speed=(float)atof(vecLine[8].c_str());
			member.hatred_area=(int)atoi(vecLine[9].c_str());
			member.patrol_range=(float)atof(vecLine[10].c_str());
			member.patrol_interval=(int)atoi(vecLine[11].c_str());
			member.harass_range=(float)atof(vecLine[12].c_str());
			member.harass_probability1=(int)atoi(vecLine[13].c_str());
			member.harass_probability2=(int)atoi(vecLine[14].c_str());
			member.harass_distance=(float)atof(vecLine[15].c_str());
			member.harass_angle=(float)atof(vecLine[16].c_str());
			member.harass_timeout=(int)atoi(vecLine[17].c_str());
			member.cd_chase_dist=(float)atof(vecLine[18].c_str());
			member.harass_speed=(float)atof(vecLine[19].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
