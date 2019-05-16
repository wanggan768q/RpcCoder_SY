#ifndef __RUNE_CONFIG_H
#define __RUNE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//铭文表配置数据结构
struct RuneElement
{
	friend class RuneTable;
	int id;                      	//铭文ID	
	int name;                    	//显示名称	关联stringskill文本表的ID
	int zj_id;                   	//专精ID1	关联专精ID-1
	int zj_id_2;                 	//专精ID2	关联专精ID-2
	int skill_id;                	//技能ID	关联技能D
	int desc;                    	//文本表ID	StringSkill_技能文本表
	string icon;                 	//图标资源	铭文图标，以后主界面技能图标用此列数据
	string rune_icon;            	//图标资源	铭文图标，以后铭文界面显示的图标用此列的配置
	string skill_frame;          	//技能图标边框	主界面技能图标的边框
	int leftOrder;               	//左侧技能位置	
	int rightOrder;              	//铭文位置	
	int lv;                      	//解锁级别	
	int unlock_animation;        	//是否显示技能解锁动画	0不显示，1显示
	string showResources;        	//表现动作资源	
	string targetModel;          	//被击模型	
	float targetDistance;        	//被击者距离	

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
	RuneElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//铭文表配置封装类
class RuneTable
{
	friend class TableData;
private:
	RuneTable(){}
	~RuneTable(){}
	map<int, RuneElement>	m_mapElements;
	vector<RuneElement>	m_vecAllElements;
	RuneElement m_emptyItem;
public:
	static RuneTable& Instance()
	{
		static RuneTable sInstance;
		return sInstance;
	}

	RuneElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<RuneElement>&	GetAllElement()
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
		if( LoadConfigContent("Rune.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Rune.bin", strTableContent ) )
		{
			printf_message("配置文件[Rune.bin]未找到");
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
		if(vecLine.size() != 16)
		{
			printf_message("Rune.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Rune.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="name"){printf_message("Rune.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="zj_id"){printf_message("Rune.csv中字段[zj_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="zj_id_2"){printf_message("Rune.csv中字段[zj_id_2]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="skill_id"){printf_message("Rune.csv中字段[skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="desc"){printf_message("Rune.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="icon"){printf_message("Rune.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="rune_icon"){printf_message("Rune.csv中字段[rune_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="skill_frame"){printf_message("Rune.csv中字段[skill_frame]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="leftOrder"){printf_message("Rune.csv中字段[leftOrder]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="rightOrder"){printf_message("Rune.csv中字段[rightOrder]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="lv"){printf_message("Rune.csv中字段[lv]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="unlock_animation"){printf_message("Rune.csv中字段[unlock_animation]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="showResources"){printf_message("Rune.csv中字段[showResources]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="targetModel"){printf_message("Rune.csv中字段[targetModel]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="targetDistance"){printf_message("Rune.csv中字段[targetDistance]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)16)
			{
				assert(false);
				return false;
			}
			RuneElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.name=(int)atoi(vecLine[1].c_str());
			member.zj_id=(int)atoi(vecLine[2].c_str());
			member.zj_id_2=(int)atoi(vecLine[3].c_str());
			member.skill_id=(int)atoi(vecLine[4].c_str());
			member.desc=(int)atoi(vecLine[5].c_str());
			member.icon=vecLine[6];
			member.rune_icon=vecLine[7];
			member.skill_frame=vecLine[8];
			member.leftOrder=(int)atoi(vecLine[9].c_str());
			member.rightOrder=(int)atoi(vecLine[10].c_str());
			member.lv=(int)atoi(vecLine[11].c_str());
			member.unlock_animation=(int)atoi(vecLine[12].c_str());
			member.showResources=vecLine[13];
			member.targetModel=vecLine[14];
			member.targetDistance=(float)atof(vecLine[15].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
