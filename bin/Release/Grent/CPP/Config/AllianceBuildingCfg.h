#ifndef __ALLIANCEBUILDING_CONFIG_H
#define __ALLIANCEBUILDING_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//公会建筑表配置数据结构
struct AllianceBuildingElement
{
	friend class AllianceBuildingTable;
	int id;                      	//ID	填写ID即可
	string comment;              	//注释	策划用
	int building;                	//建筑名不带等级	stringid
	int name;                    	//建筑名字	stringid
	int desc;                    	//建筑描述	stringid
	int type;                    	//类型	填写整数
	int cost;                    	//该建筑的维护费用	填写整数
	string pic;                  	//建筑图	图片名
	int level;                   	//建筑等级	建筑最小等级为1，0为配表通用型
	vector<int> buff;            	//建筑所加战斗属性	无写0 有写作用号|所加数值
	int currency;                	//升级至下一级需公会资金	填写整数
	int resource;                	//升级至下一级需公会资源	填写整数
	int time;                    	//升级所需时间	分钟为单位
	int up_currency;             	//加速1次所需绑钻	填写整数
	int up_time;                 	//加速1次减少时长	分钟为单位
	int up_rewards;              	//加速1次奖励的帮贡	整数
	vector<int> condition1;      	//升级所需条件	且关系
	vector<int> condition2;      	//升级所需条件	或关系
	int effect;                  	//升级带来效果	填写整数

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
	AllianceBuildingElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//公会建筑表配置封装类
class AllianceBuildingTable
{
	friend class TableData;
private:
	AllianceBuildingTable(){}
	~AllianceBuildingTable(){}
	map<int, AllianceBuildingElement>	m_mapElements;
	vector<AllianceBuildingElement>	m_vecAllElements;
	AllianceBuildingElement m_emptyItem;
public:
	static AllianceBuildingTable& Instance()
	{
		static AllianceBuildingTable sInstance;
		return sInstance;
	}

	AllianceBuildingElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AllianceBuildingElement>&	GetAllElement()
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
		if( LoadConfigContent("AllianceBuilding.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AllianceBuilding.bin", strTableContent ) )
		{
			printf_message("配置文件[AllianceBuilding.bin]未找到");
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
		if(vecLine.size() != 19)
		{
			printf_message("AllianceBuilding.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AllianceBuilding.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("AllianceBuilding.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="building"){printf_message("AllianceBuilding.csv中字段[building]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("AllianceBuilding.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="desc"){printf_message("AllianceBuilding.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="type"){printf_message("AllianceBuilding.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="cost"){printf_message("AllianceBuilding.csv中字段[cost]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="pic"){printf_message("AllianceBuilding.csv中字段[pic]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="level"){printf_message("AllianceBuilding.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="buff"){printf_message("AllianceBuilding.csv中字段[buff]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="currency"){printf_message("AllianceBuilding.csv中字段[currency]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="resource"){printf_message("AllianceBuilding.csv中字段[resource]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="time"){printf_message("AllianceBuilding.csv中字段[time]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="up_currency"){printf_message("AllianceBuilding.csv中字段[up_currency]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="up_time"){printf_message("AllianceBuilding.csv中字段[up_time]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="up_rewards"){printf_message("AllianceBuilding.csv中字段[up_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="condition1"){printf_message("AllianceBuilding.csv中字段[condition1]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="condition2"){printf_message("AllianceBuilding.csv中字段[condition2]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="effect"){printf_message("AllianceBuilding.csv中字段[effect]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)19)
			{
				assert(false);
				return false;
			}
			AllianceBuildingElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.building=(int)atoi(vecLine[2].c_str());
			member.name=(int)atoi(vecLine[3].c_str());
			member.desc=(int)atoi(vecLine[4].c_str());
			member.type=(int)atoi(vecLine[5].c_str());
			member.cost=(int)atoi(vecLine[6].c_str());
			member.pic=vecLine[7];
			member.level=(int)atoi(vecLine[8].c_str());
			member.currency=(int)atoi(vecLine[10].c_str());
			member.resource=(int)atoi(vecLine[11].c_str());
			member.time=(int)atoi(vecLine[12].c_str());
			member.up_currency=(int)atoi(vecLine[13].c_str());
			member.up_time=(int)atoi(vecLine[14].c_str());
			member.up_rewards=(int)atoi(vecLine[15].c_str());
			member.effect=(int)atoi(vecLine[18].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
