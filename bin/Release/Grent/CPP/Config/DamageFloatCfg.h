#ifndef __DAMAGEFLOAT_CONFIG_H
#define __DAMAGEFLOAT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//冒字显示配置数据结构
struct DamageFloatElement
{
	friend class DamageFloatTable;
	int id;                      	//冒字顺序	冒字顺序
	string desc;                 	//参数说明	仅说明
	int faction;                 	//阵营	1：通用 2：玩家 3 : 敌人
	int type;                    	//冒字类型	1 - 普通伤害 2 - 暴击 3 - 格挡 4 - 暴击加格挡 5 - 恢复 6 - 闪避 7 - 眩晕 8 - 减速 9 - 定身 10 - 冰冻 11 - 沉默 12 - 无敌
	int subtype;                 	//对应的BuffID	对应的BuffID
	int desc_id;                 	//文本	StringBuff_buff_id
	string icon;                 	//要显示的图标	图标显示在文字的前面,图标要添加需要找程序从新打图集
	string res_colour;           	//颜色	资源名称
	string res_frame;            	//边框	资源名称
	string res_animation;        	//动画	资源名称

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
	DamageFloatElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//冒字显示配置封装类
class DamageFloatTable
{
	friend class TableData;
private:
	DamageFloatTable(){}
	~DamageFloatTable(){}
	map<int, DamageFloatElement>	m_mapElements;
	vector<DamageFloatElement>	m_vecAllElements;
	DamageFloatElement m_emptyItem;
public:
	static DamageFloatTable& Instance()
	{
		static DamageFloatTable sInstance;
		return sInstance;
	}

	DamageFloatElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<DamageFloatElement>&	GetAllElement()
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
		if( LoadConfigContent("DamageFloat.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("DamageFloat.bin", strTableContent ) )
		{
			printf_message("配置文件[DamageFloat.bin]未找到");
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
		if(vecLine.size() != 10)
		{
			printf_message("DamageFloat.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("DamageFloat.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="desc"){printf_message("DamageFloat.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="faction"){printf_message("DamageFloat.csv中字段[faction]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="type"){printf_message("DamageFloat.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="subtype"){printf_message("DamageFloat.csv中字段[subtype]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="desc_id"){printf_message("DamageFloat.csv中字段[desc_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="icon"){printf_message("DamageFloat.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="res_colour"){printf_message("DamageFloat.csv中字段[res_colour]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="res_frame"){printf_message("DamageFloat.csv中字段[res_frame]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="res_animation"){printf_message("DamageFloat.csv中字段[res_animation]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)10)
			{
				assert(false);
				return false;
			}
			DamageFloatElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.desc=vecLine[1];
			member.faction=(int)atoi(vecLine[2].c_str());
			member.type=(int)atoi(vecLine[3].c_str());
			member.subtype=(int)atoi(vecLine[4].c_str());
			member.desc_id=(int)atoi(vecLine[5].c_str());
			member.icon=vecLine[6];
			member.res_colour=vecLine[7];
			member.res_frame=vecLine[8];
			member.res_animation=vecLine[9];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
