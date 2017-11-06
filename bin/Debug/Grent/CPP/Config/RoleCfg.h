#ifndef __ROLE_CONFIG_H
#define __ROLE_CONFIG_H

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


//角色属性配置数据结构
struct RoleElement
{
	friend class RoleTable;
	int id;                      	//id	种族*100000+职业*10+性别
	string comment;              	//注释	注释
	int race;                    	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	int occupation;              	//职业	1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士 6：神秘使
	int gender;                  	//性别	1:男性 2:女性
	string race_icon;            	//种族图标	种族图标
	int race_name;               	//种族名称	种族名称
	int race_desc;               	//种族介绍	种族介绍
	string occu_icon;            	//职业图标	职业图标
	vector<string> create_occu_icon;	//创选界面图标	专门用在创选界面的职业图标 对应未选中和选中两个状态
	int occu_name;               	//职业名称	职业名称
	int occu_desc;               	//职业介绍	职业介绍
	vector<int> occu_evaluate;   	//职业评估	输出|生存|治疗|操作难度 0~10对应0到5格
	int model_id;                	//初始模型id	初始模型id
	int strength;                	//力量	力量
	int speed ;                  	//敏捷	敏捷
	int agile;                   	//智力	智力
	int stamina;                 	//耐力	耐力
	int spirit;                  	//精神	精神
	int maxhp;                   	//最大基础血量	最大基础血量
	int maxmp;                   	//最大魔法量	最大魔法量
	int physic_attack;           	//物理攻击	物理攻击
	int physic_defense;          	//物理防御	物理防御
	int magic_attack;            	//魔法攻击	魔法攻击
	int magic_defense;           	//魔法防御	魔法防御
	int hit_value;               	//命中值	命中值
	int hit_rate;                	//命中率	命中率
	int miss_value;              	//闪避值	闪避值
	int miss_rate;               	//闪避率	闪避率
	int critical_value;          	//暴击值	暴击值
	int critical_rate;           	//暴击率	暴击率
	int tenacity_value;          	//韧性值	韧性值
	int tenacity_rate;           	//韧性率	韧性率
	int dodge_value;             	//格挡值	格挡值
	int dodge_rate;              	//格挡率	格挡率
	int penetrate_value;         	//穿透值	穿透值
	int penetrate_rate;          	//穿透率	穿透率
	int miss_level;              	//闪避等级	闪避等级
	int critical_level;          	//暴击等级	暴击等级
	int dodge_level;             	//格挡等级	格挡等级
	int move_speed;              	//移动速度	移动速度
	int physic_oppose;           	//物理抗性	物理抗性
	int magic_oppose;            	//魔法抗性	魔法抗性
	int physic_add;              	//物理追加	物理追加
	int magic_add;               	//魔法追加	魔法追加
	int scene_id;                	//初始场景id	初始场景id
	float posx;                  	//初始x坐标	初始x坐标
	float posz;                  	//初始z坐标	初始z坐标
	float direct;                	//角色朝向	角色朝向

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
	unordered_map<int, RoleElement>	m_mapElements;
	vector<RoleElement>	m_vecAllElements;
	RoleElement m_emptyItem;
public:
	static RoleTable& Instance()
	{
		static RoleTable sInstance;
		return sInstance;
	}

	const RoleElement* GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return &m_mapElements[key];
		if (m_mapElements.count(key) > 0)
		{
			RoleElement* temp = &m_mapElements[key];
			AssertEx(temp, std::string(std::string("RoleTable: ") + std::to_string(key)).c_str());
			return temp;
		}
		AssertEx(false, std::string(std::string("RoleTable: ") + std::to_string(key)).c_str());
		return NULL;
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
		#ifdef CONFIG_JSON
		return LoadJson("Role.json");
		#else
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

			RoleElement	member;

						member.id=p.get<int>("id");
			member.comment=p.get<string>("comment");
			member.race=p.get<int>("race");
			member.occupation=p.get<int>("occupation");
			member.gender=p.get<int>("gender");
			member.race_icon=p.get<string>("race_icon");
			member.race_name=p.get<int>("race_name");
			member.race_desc=p.get<int>("race_desc");
			member.occu_icon=p.get<string>("occu_icon");
			boost::property_tree::ptree sms_array_childcreate_occu_icon = p.get_child("create_occu_icon");
			for (BOOST_AUTO(pos, sms_array_childcreate_occu_icon.begin()); pos != sms_array_childcreate_occu_icon.end(); ++pos)
			{
				string n = pos->second.get_value<string>(); 
				member.create_occu_icon.push_back(n);
			}
			member.occu_name=p.get<int>("occu_name");
			member.occu_desc=p.get<int>("occu_desc");
			boost::property_tree::ptree sms_array_childoccu_evaluate = p.get_child("occu_evaluate");
			for (BOOST_AUTO(pos, sms_array_childoccu_evaluate.begin()); pos != sms_array_childoccu_evaluate.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.occu_evaluate.push_back(n);
			}
			member.model_id=p.get<int>("model_id");
			member.strength=p.get<int>("strength");
			member.speed =p.get<int>("speed ");
			member.agile=p.get<int>("agile");
			member.stamina=p.get<int>("stamina");
			member.spirit=p.get<int>("spirit");
			member.maxhp=p.get<int>("maxhp");
			member.maxmp=p.get<int>("maxmp");
			member.physic_attack=p.get<int>("physic_attack");
			member.physic_defense=p.get<int>("physic_defense");
			member.magic_attack=p.get<int>("magic_attack");
			member.magic_defense=p.get<int>("magic_defense");
			member.hit_value=p.get<int>("hit_value");
			member.hit_rate=p.get<int>("hit_rate");
			member.miss_value=p.get<int>("miss_value");
			member.miss_rate=p.get<int>("miss_rate");
			member.critical_value=p.get<int>("critical_value");
			member.critical_rate=p.get<int>("critical_rate");
			member.tenacity_value=p.get<int>("tenacity_value");
			member.tenacity_rate=p.get<int>("tenacity_rate");
			member.dodge_value=p.get<int>("dodge_value");
			member.dodge_rate=p.get<int>("dodge_rate");
			member.penetrate_value=p.get<int>("penetrate_value");
			member.penetrate_rate=p.get<int>("penetrate_rate");
			member.miss_level=p.get<int>("miss_level");
			member.critical_level=p.get<int>("critical_level");
			member.dodge_level=p.get<int>("dodge_level");
			member.move_speed=p.get<int>("move_speed");
			member.physic_oppose=p.get<int>("physic_oppose");
			member.magic_oppose=p.get<int>("magic_oppose");
			member.physic_add=p.get<int>("physic_add");
			member.magic_add=p.get<int>("magic_add");
			member.scene_id=p.get<int>("scene_id");
			member.posx=p.get<float>("posx");
			member.posz=p.get<float>("posz");
			member.direct=p.get<float>("direct");


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
		if(vecLine.size() != 49)
		{
			printf_message("Role.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Role.csv中字段[id]位置不对应");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Role.csv中字段[comment]位置不对应");assert(false); return false; }
		if(vecLine[2]!="race"){printf_message("Role.csv中字段[race]位置不对应");assert(false); return false; }
		if(vecLine[3]!="occupation"){printf_message("Role.csv中字段[occupation]位置不对应");assert(false); return false; }
		if(vecLine[4]!="gender"){printf_message("Role.csv中字段[gender]位置不对应");assert(false); return false; }
		if(vecLine[5]!="race_icon"){printf_message("Role.csv中字段[race_icon]位置不对应");assert(false); return false; }
		if(vecLine[6]!="race_name"){printf_message("Role.csv中字段[race_name]位置不对应");assert(false); return false; }
		if(vecLine[7]!="race_desc"){printf_message("Role.csv中字段[race_desc]位置不对应");assert(false); return false; }
		if(vecLine[8]!="occu_icon"){printf_message("Role.csv中字段[occu_icon]位置不对应");assert(false); return false; }
		if(vecLine[9]!="create_occu_icon"){printf_message("Role.csv中字段[create_occu_icon]位置不对应");assert(false); return false; }
		if(vecLine[10]!="occu_name"){printf_message("Role.csv中字段[occu_name]位置不对应");assert(false); return false; }
		if(vecLine[11]!="occu_desc"){printf_message("Role.csv中字段[occu_desc]位置不对应");assert(false); return false; }
		if(vecLine[12]!="occu_evaluate"){printf_message("Role.csv中字段[occu_evaluate]位置不对应");assert(false); return false; }
		if(vecLine[13]!="model_id"){printf_message("Role.csv中字段[model_id]位置不对应");assert(false); return false; }
		if(vecLine[14]!="strength"){printf_message("Role.csv中字段[strength]位置不对应");assert(false); return false; }
		if(vecLine[15]!="speed "){printf_message("Role.csv中字段[speed ]位置不对应");assert(false); return false; }
		if(vecLine[16]!="agile"){printf_message("Role.csv中字段[agile]位置不对应");assert(false); return false; }
		if(vecLine[17]!="stamina"){printf_message("Role.csv中字段[stamina]位置不对应");assert(false); return false; }
		if(vecLine[18]!="spirit"){printf_message("Role.csv中字段[spirit]位置不对应");assert(false); return false; }
		if(vecLine[19]!="maxhp"){printf_message("Role.csv中字段[maxhp]位置不对应");assert(false); return false; }
		if(vecLine[20]!="maxmp"){printf_message("Role.csv中字段[maxmp]位置不对应");assert(false); return false; }
		if(vecLine[21]!="physic_attack"){printf_message("Role.csv中字段[physic_attack]位置不对应");assert(false); return false; }
		if(vecLine[22]!="physic_defense"){printf_message("Role.csv中字段[physic_defense]位置不对应");assert(false); return false; }
		if(vecLine[23]!="magic_attack"){printf_message("Role.csv中字段[magic_attack]位置不对应");assert(false); return false; }
		if(vecLine[24]!="magic_defense"){printf_message("Role.csv中字段[magic_defense]位置不对应");assert(false); return false; }
		if(vecLine[25]!="hit_value"){printf_message("Role.csv中字段[hit_value]位置不对应");assert(false); return false; }
		if(vecLine[26]!="hit_rate"){printf_message("Role.csv中字段[hit_rate]位置不对应");assert(false); return false; }
		if(vecLine[27]!="miss_value"){printf_message("Role.csv中字段[miss_value]位置不对应");assert(false); return false; }
		if(vecLine[28]!="miss_rate"){printf_message("Role.csv中字段[miss_rate]位置不对应");assert(false); return false; }
		if(vecLine[29]!="critical_value"){printf_message("Role.csv中字段[critical_value]位置不对应");assert(false); return false; }
		if(vecLine[30]!="critical_rate"){printf_message("Role.csv中字段[critical_rate]位置不对应");assert(false); return false; }
		if(vecLine[31]!="tenacity_value"){printf_message("Role.csv中字段[tenacity_value]位置不对应");assert(false); return false; }
		if(vecLine[32]!="tenacity_rate"){printf_message("Role.csv中字段[tenacity_rate]位置不对应");assert(false); return false; }
		if(vecLine[33]!="dodge_value"){printf_message("Role.csv中字段[dodge_value]位置不对应");assert(false); return false; }
		if(vecLine[34]!="dodge_rate"){printf_message("Role.csv中字段[dodge_rate]位置不对应");assert(false); return false; }
		if(vecLine[35]!="penetrate_value"){printf_message("Role.csv中字段[penetrate_value]位置不对应");assert(false); return false; }
		if(vecLine[36]!="penetrate_rate"){printf_message("Role.csv中字段[penetrate_rate]位置不对应");assert(false); return false; }
		if(vecLine[37]!="miss_level"){printf_message("Role.csv中字段[miss_level]位置不对应");assert(false); return false; }
		if(vecLine[38]!="critical_level"){printf_message("Role.csv中字段[critical_level]位置不对应");assert(false); return false; }
		if(vecLine[39]!="dodge_level"){printf_message("Role.csv中字段[dodge_level]位置不对应");assert(false); return false; }
		if(vecLine[40]!="move_speed"){printf_message("Role.csv中字段[move_speed]位置不对应");assert(false); return false; }
		if(vecLine[41]!="physic_oppose"){printf_message("Role.csv中字段[physic_oppose]位置不对应");assert(false); return false; }
		if(vecLine[42]!="magic_oppose"){printf_message("Role.csv中字段[magic_oppose]位置不对应");assert(false); return false; }
		if(vecLine[43]!="physic_add"){printf_message("Role.csv中字段[physic_add]位置不对应");assert(false); return false; }
		if(vecLine[44]!="magic_add"){printf_message("Role.csv中字段[magic_add]位置不对应");assert(false); return false; }
		if(vecLine[45]!="scene_id"){printf_message("Role.csv中字段[scene_id]位置不对应");assert(false); return false; }
		if(vecLine[46]!="posx"){printf_message("Role.csv中字段[posx]位置不对应");assert(false); return false; }
		if(vecLine[47]!="posz"){printf_message("Role.csv中字段[posz]位置不对应");assert(false); return false; }
		if(vecLine[48]!="direct"){printf_message("Role.csv中字段[direct]位置不对应");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)49)
			{
				assert(false);
				return false;
			}
			RoleElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.race=(int)atoi(vecLine[2].c_str());
			member.occupation=(int)atoi(vecLine[3].c_str());
			member.gender=(int)atoi(vecLine[4].c_str());
			member.race_icon=vecLine[5];
			member.race_name=(int)atoi(vecLine[6].c_str());
			member.race_desc=(int)atoi(vecLine[7].c_str());
			member.occu_icon=vecLine[8];
			member.occu_name=(int)atoi(vecLine[10].c_str());
			member.occu_desc=(int)atoi(vecLine[11].c_str());
			member.model_id=(int)atoi(vecLine[13].c_str());
			member.strength=(int)atoi(vecLine[14].c_str());
			member.speed =(int)atoi(vecLine[15].c_str());
			member.agile=(int)atoi(vecLine[16].c_str());
			member.stamina=(int)atoi(vecLine[17].c_str());
			member.spirit=(int)atoi(vecLine[18].c_str());
			member.maxhp=(int)atoi(vecLine[19].c_str());
			member.maxmp=(int)atoi(vecLine[20].c_str());
			member.physic_attack=(int)atoi(vecLine[21].c_str());
			member.physic_defense=(int)atoi(vecLine[22].c_str());
			member.magic_attack=(int)atoi(vecLine[23].c_str());
			member.magic_defense=(int)atoi(vecLine[24].c_str());
			member.hit_value=(int)atoi(vecLine[25].c_str());
			member.hit_rate=(int)atoi(vecLine[26].c_str());
			member.miss_value=(int)atoi(vecLine[27].c_str());
			member.miss_rate=(int)atoi(vecLine[28].c_str());
			member.critical_value=(int)atoi(vecLine[29].c_str());
			member.critical_rate=(int)atoi(vecLine[30].c_str());
			member.tenacity_value=(int)atoi(vecLine[31].c_str());
			member.tenacity_rate=(int)atoi(vecLine[32].c_str());
			member.dodge_value=(int)atoi(vecLine[33].c_str());
			member.dodge_rate=(int)atoi(vecLine[34].c_str());
			member.penetrate_value=(int)atoi(vecLine[35].c_str());
			member.penetrate_rate=(int)atoi(vecLine[36].c_str());
			member.miss_level=(int)atoi(vecLine[37].c_str());
			member.critical_level=(int)atoi(vecLine[38].c_str());
			member.dodge_level=(int)atoi(vecLine[39].c_str());
			member.move_speed=(int)atoi(vecLine[40].c_str());
			member.physic_oppose=(int)atoi(vecLine[41].c_str());
			member.magic_oppose=(int)atoi(vecLine[42].c_str());
			member.physic_add=(int)atoi(vecLine[43].c_str());
			member.magic_add=(int)atoi(vecLine[44].c_str());
			member.scene_id=(int)atoi(vecLine[45].c_str());
			member.posx=(float)atof(vecLine[46].c_str());
			member.posz=(float)atof(vecLine[47].c_str());
			member.direct=(float)atof(vecLine[48].c_str());

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
