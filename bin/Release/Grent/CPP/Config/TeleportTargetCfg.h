#ifndef __TELEPORTTARGET_CONFIG_H
#define __TELEPORTTARGET_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//传送目标表配置数据结构
struct TeleportTargetElement
{
	friend class TeleportTargetTable;
	int id;                      	//序号	代表玩家传送到的目标点
	string comment;              	//备注	
	int map_id;                  	//代表地图号id	
	vector<float> location;      	//代表untiy中的世界坐标	x|y|z
	int face_rotate;             	//生成点朝向	用角度表示角色传送后的朝向，采用unity中生成点Y轴的旋转量
	int type;                    	//该出生点的类型	1为地图传送，代表从大地图传送到该图时，都会传送到该点 2为常规传送代表正常的一对一传送 3为地图和常规传送都会是这个点
	int string_name;             	//传送点名称	在此填写传送到的位置名称
	string icon;                 	//传送点图标	该传送点在地图上显示的图标

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
	TeleportTargetElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//传送目标表配置封装类
class TeleportTargetTable
{
	friend class TableData;
private:
	TeleportTargetTable(){}
	~TeleportTargetTable(){}
	map<int, TeleportTargetElement>	m_mapElements;
	vector<TeleportTargetElement>	m_vecAllElements;
	TeleportTargetElement m_emptyItem;
public:
	static TeleportTargetTable& Instance()
	{
		static TeleportTargetTable sInstance;
		return sInstance;
	}

	TeleportTargetElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TeleportTargetElement>&	GetAllElement()
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
		if( LoadConfigContent("TeleportTarget.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("TeleportTarget.bin", strTableContent ) )
		{
			printf_message("配置文件[TeleportTarget.bin]未找到");
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
		if(vecLine.size() != 8)
		{
			printf_message("TeleportTarget.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("TeleportTarget.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("TeleportTarget.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="map_id"){printf_message("TeleportTarget.csv中字段[map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="location"){printf_message("TeleportTarget.csv中字段[location]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="face_rotate"){printf_message("TeleportTarget.csv中字段[face_rotate]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="type"){printf_message("TeleportTarget.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="string_name"){printf_message("TeleportTarget.csv中字段[string_name]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="icon"){printf_message("TeleportTarget.csv中字段[icon]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)8)
			{
				assert(false);
				return false;
			}
			TeleportTargetElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.map_id=(int)atoi(vecLine[2].c_str());
			member.face_rotate=(int)atoi(vecLine[4].c_str());
			member.type=(int)atoi(vecLine[5].c_str());
			member.string_name=(int)atoi(vecLine[6].c_str());
			member.icon=vecLine[7];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
