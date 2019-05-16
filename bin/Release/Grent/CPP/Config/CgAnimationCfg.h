#ifndef __CGANIMATION_CONFIG_H
#define __CGANIMATION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//动画表配置数据结构
struct CgAnimationElement
{
	friend class CgAnimationTable;
	int id;                      	// cg_id	动画id
	string comment;              	//注释	
	string animation_name;       	//动画文件	
	string path_name;            	//动画所需资源文件	
	int duration;                	//动画时长	单位s
	int can_skip;                	//是否可以跳过	
	string script;               	//脚本文件	
	int teleport_map;            	//	传送的地图Id
	vector<int> teleport_list;   	//传送位置	动画结束后传送到该位置 x|y|z
	int binding_monster_id;      	//绑定的怪物ID	
	int time_before_skip;        	//跳过时间	动画至少播放多少秒，才会出现跳过按钮
	int Type;                    	//Cg类型	0为默认 1为替换主角形象的 2为QTE类型 3为替换主角的QTE类型

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
	CgAnimationElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//动画表配置封装类
class CgAnimationTable
{
	friend class TableData;
private:
	CgAnimationTable(){}
	~CgAnimationTable(){}
	map<int, CgAnimationElement>	m_mapElements;
	vector<CgAnimationElement>	m_vecAllElements;
	CgAnimationElement m_emptyItem;
public:
	static CgAnimationTable& Instance()
	{
		static CgAnimationTable sInstance;
		return sInstance;
	}

	CgAnimationElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CgAnimationElement>&	GetAllElement()
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
		if( LoadConfigContent("CgAnimation.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CgAnimation.bin", strTableContent ) )
		{
			printf_message("配置文件[CgAnimation.bin]未找到");
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
			printf_message("CgAnimation.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CgAnimation.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CgAnimation.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="animation_name"){printf_message("CgAnimation.csv中字段[animation_name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="path_name"){printf_message("CgAnimation.csv中字段[path_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="duration"){printf_message("CgAnimation.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="can_skip"){printf_message("CgAnimation.csv中字段[can_skip]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="script"){printf_message("CgAnimation.csv中字段[script]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="teleport_map"){printf_message("CgAnimation.csv中字段[teleport_map]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="teleport_list"){printf_message("CgAnimation.csv中字段[teleport_list]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="binding_monster_id"){printf_message("CgAnimation.csv中字段[binding_monster_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="time_before_skip"){printf_message("CgAnimation.csv中字段[time_before_skip]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="Type"){printf_message("CgAnimation.csv中字段[Type]位置不对应 ");assert(false); return false; }

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
			CgAnimationElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.animation_name=vecLine[2];
			member.path_name=vecLine[3];
			member.duration=(int)atoi(vecLine[4].c_str());
			member.can_skip=(int)atoi(vecLine[5].c_str());
			member.script=vecLine[6];
			member.teleport_map=(int)atoi(vecLine[7].c_str());
			member.binding_monster_id=(int)atoi(vecLine[9].c_str());
			member.time_before_skip=(int)atoi(vecLine[10].c_str());
			member.Type=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
