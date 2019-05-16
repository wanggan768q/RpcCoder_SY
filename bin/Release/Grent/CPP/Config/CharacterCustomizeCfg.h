#ifndef __CHARACTERCUSTOMIZE_CONFIG_H
#define __CHARACTERCUSTOMIZE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//角色自定义配置数据结构
struct CharacterCustomizeElement
{
	friend class CharacterCustomizeTable;
	int id;                      	//配置ID	ID段划分： 前3位-职业 4、5位-套装 6位-部位
	string comment;              	//描述	仅策划用
	string filename;             	//模型文件名	模型文件名
	string  material;            	//材质	需要更换的材质文件 （时装染色）
	float zoom;                  	//缩放比例	缩放比例
	float interface_zoom;        	//界面缩放	控制界面内的缩放比例 （缩放人物与坐骑整体）
	int part;                    	//模型对应的自定义部位	枚举定义 1.头部 2.面部 3.身体 4.武器 5.翅膀 6.坐骑
	float height;                	//高度	仅对坐骑生效 只针对飞行类坐骑
	float camera_height;         	//摄像机高度	仅对坐骑生效 提高坐骑相机高度

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
	CharacterCustomizeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//角色自定义配置封装类
class CharacterCustomizeTable
{
	friend class TableData;
private:
	CharacterCustomizeTable(){}
	~CharacterCustomizeTable(){}
	map<int, CharacterCustomizeElement>	m_mapElements;
	vector<CharacterCustomizeElement>	m_vecAllElements;
	CharacterCustomizeElement m_emptyItem;
public:
	static CharacterCustomizeTable& Instance()
	{
		static CharacterCustomizeTable sInstance;
		return sInstance;
	}

	CharacterCustomizeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CharacterCustomizeElement>&	GetAllElement()
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
		if( LoadConfigContent("CharacterCustomize.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CharacterCustomize.bin", strTableContent ) )
		{
			printf_message("配置文件[CharacterCustomize.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("CharacterCustomize.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CharacterCustomize.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CharacterCustomize.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="filename"){printf_message("CharacterCustomize.csv中字段[filename]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!=" material"){printf_message("CharacterCustomize.csv中字段[ material]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="zoom"){printf_message("CharacterCustomize.csv中字段[zoom]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="interface_zoom"){printf_message("CharacterCustomize.csv中字段[interface_zoom]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="part"){printf_message("CharacterCustomize.csv中字段[part]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="height"){printf_message("CharacterCustomize.csv中字段[height]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="camera_height"){printf_message("CharacterCustomize.csv中字段[camera_height]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			CharacterCustomizeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.filename=vecLine[2];
			member. material=vecLine[3];
			member.zoom=(float)atof(vecLine[4].c_str());
			member.interface_zoom=(float)atof(vecLine[5].c_str());
			member.part=(int)atoi(vecLine[6].c_str());
			member.height=(float)atof(vecLine[7].c_str());
			member.camera_height=(float)atof(vecLine[8].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
