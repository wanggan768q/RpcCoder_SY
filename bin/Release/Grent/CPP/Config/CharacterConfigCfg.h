#ifndef __CHARACTERCONFIG_CONFIG_H
#define __CHARACTERCONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//模型配置配置数据结构
struct CharacterConfigElement
{
	friend class CharacterConfigTable;
	int id;                      	//配置ID	ID段划分： 0-1000特殊； 1000-9999角色； 10000-29999怪物； 30000-39999静物； 40000-49999npc； 50000-59999宠物
	string comment;              	//描述	仅策划用
	string filename;             	//模型文件名	模型文件名
	string  material;            	//材质	需要更换的材质文件 （时装染色）
	vector<float> zoom;          	//缩放比例	X|Y|Z坐标
	vector<float> bound_center;  	//包围盒中心点	X|Y|Z坐标
	vector<float> bound_size;    	//包围盒大小	X|Y|Z坐标
	vector<float> render_position;	//界面投影坐标	X|Y|Z
	vector<float> render_rotation;	//界面投影角度	X|Y|Z
	vector<float> render_scale;  	//界面投影比例	X|Y|Z
	int standup_time;            	//起身时间	模型被击倒后起身的动作时间(单位:ms)
	int hurt_time;               	//受击时长	模型受击动作时长(单位:ms)

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
	CharacterConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//模型配置配置封装类
class CharacterConfigTable
{
	friend class TableData;
private:
	CharacterConfigTable(){}
	~CharacterConfigTable(){}
	map<int, CharacterConfigElement>	m_mapElements;
	vector<CharacterConfigElement>	m_vecAllElements;
	CharacterConfigElement m_emptyItem;
public:
	static CharacterConfigTable& Instance()
	{
		static CharacterConfigTable sInstance;
		return sInstance;
	}

	CharacterConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CharacterConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("CharacterConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CharacterConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[CharacterConfig.bin]未找到");
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
			printf_message("CharacterConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CharacterConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CharacterConfig.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="filename"){printf_message("CharacterConfig.csv中字段[filename]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!=" material"){printf_message("CharacterConfig.csv中字段[ material]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="zoom"){printf_message("CharacterConfig.csv中字段[zoom]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="bound_center"){printf_message("CharacterConfig.csv中字段[bound_center]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="bound_size"){printf_message("CharacterConfig.csv中字段[bound_size]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="render_position"){printf_message("CharacterConfig.csv中字段[render_position]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="render_rotation"){printf_message("CharacterConfig.csv中字段[render_rotation]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="render_scale"){printf_message("CharacterConfig.csv中字段[render_scale]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="standup_time"){printf_message("CharacterConfig.csv中字段[standup_time]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="hurt_time"){printf_message("CharacterConfig.csv中字段[hurt_time]位置不对应 ");assert(false); return false; }

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
			CharacterConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.filename=vecLine[2];
			member. material=vecLine[3];
			member.standup_time=(int)atoi(vecLine[10].c_str());
			member.hurt_time=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
