#ifndef __PROFESSIONCOMBOPOINT_CONFIG_H
#define __PROFESSIONCOMBOPOINT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//职业连击点配置表配置数据结构
struct ProfessionComboPointElement
{
	friend class ProfessionComboPointTable;
	int id;                      	//专精ID	1-防战2-狂战，3-敏锐贼4-战斗贼，5-射击猎6-生存猎，7-火法8-冰法，9-防骑10-奶骑，11-鸟德12-奶德，13-火法男14-冰法男，15-射击猎女16生存猎女。
	string comment;              	//备注	备注
	int has_point;               	//是否适用增强/连击点机制	是否有专精点/连击点 1：该专精有此机制 0：改专精没此机制
	vector<string> dim_resource_name;	//暗点儿资源名称	暗淡的连击点/的图片资源名称，每个资源图片名称用连接符“|”串联，无数据时保持空
	vector<string> bright_resource_name;	//亮点儿资源名称	亮起时的连击点/的图片资源名称，每个资源图片名称用连接符“|”串联，无数据时保持空
	string full_point_effect_name;	//满点儿特效名称	满连击点/的特效资源名称无数据时保持空
	int max_count;               	//最大点儿数值	最大点儿数值

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
	ProfessionComboPointElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//职业连击点配置表配置封装类
class ProfessionComboPointTable
{
	friend class TableData;
private:
	ProfessionComboPointTable(){}
	~ProfessionComboPointTable(){}
	map<int, ProfessionComboPointElement>	m_mapElements;
	vector<ProfessionComboPointElement>	m_vecAllElements;
	ProfessionComboPointElement m_emptyItem;
public:
	static ProfessionComboPointTable& Instance()
	{
		static ProfessionComboPointTable sInstance;
		return sInstance;
	}

	ProfessionComboPointElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ProfessionComboPointElement>&	GetAllElement()
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
		if( LoadConfigContent("ProfessionComboPoint.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ProfessionComboPoint.bin", strTableContent ) )
		{
			printf_message("配置文件[ProfessionComboPoint.bin]未找到");
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
		if(vecLine.size() != 7)
		{
			printf_message("ProfessionComboPoint.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ProfessionComboPoint.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ProfessionComboPoint.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="has_point"){printf_message("ProfessionComboPoint.csv中字段[has_point]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="dim_resource_name"){printf_message("ProfessionComboPoint.csv中字段[dim_resource_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="bright_resource_name"){printf_message("ProfessionComboPoint.csv中字段[bright_resource_name]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="full_point_effect_name"){printf_message("ProfessionComboPoint.csv中字段[full_point_effect_name]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="max_count"){printf_message("ProfessionComboPoint.csv中字段[max_count]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			ProfessionComboPointElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.has_point=(int)atoi(vecLine[2].c_str());
			member.full_point_effect_name=vecLine[5];
			member.max_count=(int)atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
