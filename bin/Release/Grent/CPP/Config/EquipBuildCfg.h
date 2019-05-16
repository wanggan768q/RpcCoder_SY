#ifndef __EQUIPBUILD_CONFIG_H
#define __EQUIPBUILD_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//打造配置表配置数据结构
struct EquipBuildElement
{
	friend class EquipBuildTable;
	int id;                      	//配方ID	每个配方所对应的ID值
	string comment;              	//注释	策划用
	string formula_picture;      	//配方图片	配方图标的图片资源
	int build_cost;              	//消耗货币	打造所消耗的货币数量
	vector<int> material1;       	//消耗材料1	打造所消耗的材料道具ID|消耗数量
	vector<int> material2;       	//消耗材料2	打造所消耗的材料道具ID|消耗数量
	int add_artifact;            	//增加神器值	每次打造增加的神器值
	int build_info;              	//打造装备信息	进行打造时的掉落包ID
	int assign_info;             	//指定装备信息	神器值已满时打造必定出现的掉落包ID
	vector<int> preview_infolist1;	//预览信息1	打造可能出现的装备道具ID
	int preview_infolist2;       	//预览信息2	神器值满可能出现的装备ID

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
	EquipBuildElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//打造配置表配置封装类
class EquipBuildTable
{
	friend class TableData;
private:
	EquipBuildTable(){}
	~EquipBuildTable(){}
	map<int, EquipBuildElement>	m_mapElements;
	vector<EquipBuildElement>	m_vecAllElements;
	EquipBuildElement m_emptyItem;
public:
	static EquipBuildTable& Instance()
	{
		static EquipBuildTable sInstance;
		return sInstance;
	}

	EquipBuildElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipBuildElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipBuild.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipBuild.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipBuild.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("EquipBuild.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipBuild.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipBuild.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="formula_picture"){printf_message("EquipBuild.csv中字段[formula_picture]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="build_cost"){printf_message("EquipBuild.csv中字段[build_cost]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="material1"){printf_message("EquipBuild.csv中字段[material1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="material2"){printf_message("EquipBuild.csv中字段[material2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="add_artifact"){printf_message("EquipBuild.csv中字段[add_artifact]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="build_info"){printf_message("EquipBuild.csv中字段[build_info]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="assign_info"){printf_message("EquipBuild.csv中字段[assign_info]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="preview_infolist1"){printf_message("EquipBuild.csv中字段[preview_infolist1]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="preview_infolist2"){printf_message("EquipBuild.csv中字段[preview_infolist2]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			EquipBuildElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.formula_picture=vecLine[2];
			member.build_cost=(int)atoi(vecLine[3].c_str());
			member.add_artifact=(int)atoi(vecLine[6].c_str());
			member.build_info=(int)atoi(vecLine[7].c_str());
			member.assign_info=(int)atoi(vecLine[8].c_str());
			member.preview_infolist2=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
