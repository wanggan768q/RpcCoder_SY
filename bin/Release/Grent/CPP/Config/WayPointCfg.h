#ifndef __WAYPOINT_CONFIG_H
#define __WAYPOINT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//路点表配置数据结构
struct WayPointElement
{
	friend class WayPointTable;
	int id;                      	//路点ID	路点ID
	string comment;              	//	
	int spawn_map_id;            	//路点所在的场景号	路点所在的场景号
	float spawn_x;               	//路点所处的场景的X坐标	路点所处的场景的X坐标
	float spawn_y;               	//路点所处的场景的Y坐标	路点所处的场景的Y坐标
	float spawn_z;               	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	int face_rotate;             	//生成点朝向	用角度表示角色传送后的朝向，采用unity中生成点Y轴的旋转量
	int waypoint_next_id;        	//下一个路点ID	下一个路点ID
	string waypoint_animation;   	//到达路点后播放的动画路径	到达路点后播放的动画路径
	int waypoint_delay;          	//到达路点后停留的时间	到达路点后停留的时间
	float fly_height;            	//飞行坐骑高度	飞行坐骑高度
	int pet_start;               	//宠物捕获路点标识	是宠物捕获的起始路点为1 不是为0

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
	WayPointElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//路点表配置封装类
class WayPointTable
{
	friend class TableData;
private:
	WayPointTable(){}
	~WayPointTable(){}
	map<int, WayPointElement>	m_mapElements;
	vector<WayPointElement>	m_vecAllElements;
	WayPointElement m_emptyItem;
public:
	static WayPointTable& Instance()
	{
		static WayPointTable sInstance;
		return sInstance;
	}

	WayPointElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<WayPointElement>&	GetAllElement()
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
		if( LoadConfigContent("WayPoint.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("WayPoint.bin", strTableContent ) )
		{
			printf_message("配置文件[WayPoint.bin]未找到");
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
		if(vecLine.size() != 12)
		{
			printf_message("WayPoint.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("WayPoint.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("WayPoint.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="spawn_map_id"){printf_message("WayPoint.csv中字段[spawn_map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="spawn_x"){printf_message("WayPoint.csv中字段[spawn_x]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="spawn_y"){printf_message("WayPoint.csv中字段[spawn_y]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="spawn_z"){printf_message("WayPoint.csv中字段[spawn_z]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="face_rotate"){printf_message("WayPoint.csv中字段[face_rotate]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="waypoint_next_id"){printf_message("WayPoint.csv中字段[waypoint_next_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="waypoint_animation"){printf_message("WayPoint.csv中字段[waypoint_animation]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="waypoint_delay"){printf_message("WayPoint.csv中字段[waypoint_delay]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="fly_height"){printf_message("WayPoint.csv中字段[fly_height]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="pet_start"){printf_message("WayPoint.csv中字段[pet_start]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			WayPointElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.spawn_map_id=(int)atoi(vecLine[2].c_str());
			member.spawn_x=(float)atof(vecLine[3].c_str());
			member.spawn_y=(float)atof(vecLine[4].c_str());
			member.spawn_z=(float)atof(vecLine[5].c_str());
			member.face_rotate=(int)atoi(vecLine[6].c_str());
			member.waypoint_next_id=(int)atoi(vecLine[7].c_str());
			member.waypoint_animation=vecLine[8];
			member.waypoint_delay=(int)atoi(vecLine[9].c_str());
			member.fly_height=(float)atof(vecLine[10].c_str());
			member.pet_start=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
