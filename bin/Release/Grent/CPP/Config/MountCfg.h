#ifndef __MOUNT_CONFIG_H
#define __MOUNT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//坐骑表配置数据结构
struct MountElement
{
	friend class MountTable;
	int id;                      	//配置ID	ID需与角色自定义表 中的坐骑一一对应
	string comment;              	//注释	仅策划用
	vector<string> animation_list;	//动画列表	坐骑的动画状态
	float initial_velocity;      	//初始速率（废弃）	坐骑动画的默认速率（m/s）

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
	MountElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//坐骑表配置封装类
class MountTable
{
	friend class TableData;
private:
	MountTable(){}
	~MountTable(){}
	map<int, MountElement>	m_mapElements;
	vector<MountElement>	m_vecAllElements;
	MountElement m_emptyItem;
public:
	static MountTable& Instance()
	{
		static MountTable sInstance;
		return sInstance;
	}

	MountElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MountElement>&	GetAllElement()
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
		if( LoadConfigContent("Mount.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Mount.bin", strTableContent ) )
		{
			printf_message("配置文件[Mount.bin]未找到");
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
		if(vecLine.size() != 4)
		{
			printf_message("Mount.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Mount.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Mount.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="animation_list"){printf_message("Mount.csv中字段[animation_list]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="initial_velocity"){printf_message("Mount.csv中字段[initial_velocity]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)4)
			{
				assert(false);
				return false;
			}
			MountElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.initial_velocity=(float)atof(vecLine[3].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
