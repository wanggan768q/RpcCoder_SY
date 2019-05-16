#ifndef __PETTALENT_CONFIG_H
#define __PETTALENT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物资质表配置数据结构
struct PetTalentElement
{
	friend class PetTalentTable;
	int id;                      	//宠物资质id	宠物资质区间id
	string comment;              	//注释	策划用
	int talent_1;                	//宠物资质1	对应资质表中的id 生命
	vector<int> talent_1_value;  	//宠物资质1值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	int talent_2;                	//宠物资质2	对应资质表中的id 攻击
	vector<int> talent_2_value;  	//宠物资质2值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	int talent_3;                	//宠物资质3	对应资质表中的id 防御
	vector<int> talent_3_value;  	//宠物资质3值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	int talent_4;                	//宠物资质4	对应资质表中的id 爆发
	vector<int> talent_4_value;  	//宠物资质4值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	int talent_5;                	//宠物资质5	对应资质表中的id 忍耐
	vector<int> talent_5_value;  	//宠物资质5值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限

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
	PetTalentElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物资质表配置封装类
class PetTalentTable
{
	friend class TableData;
private:
	PetTalentTable(){}
	~PetTalentTable(){}
	map<int, PetTalentElement>	m_mapElements;
	vector<PetTalentElement>	m_vecAllElements;
	PetTalentElement m_emptyItem;
public:
	static PetTalentTable& Instance()
	{
		static PetTalentTable sInstance;
		return sInstance;
	}

	PetTalentElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetTalentElement>&	GetAllElement()
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
		if( LoadConfigContent("PetTalent.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetTalent.bin", strTableContent ) )
		{
			printf_message("配置文件[PetTalent.bin]未找到");
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
			printf_message("PetTalent.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetTalent.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetTalent.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="talent_1"){printf_message("PetTalent.csv中字段[talent_1]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="talent_1_value"){printf_message("PetTalent.csv中字段[talent_1_value]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="talent_2"){printf_message("PetTalent.csv中字段[talent_2]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="talent_2_value"){printf_message("PetTalent.csv中字段[talent_2_value]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="talent_3"){printf_message("PetTalent.csv中字段[talent_3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="talent_3_value"){printf_message("PetTalent.csv中字段[talent_3_value]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="talent_4"){printf_message("PetTalent.csv中字段[talent_4]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="talent_4_value"){printf_message("PetTalent.csv中字段[talent_4_value]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="talent_5"){printf_message("PetTalent.csv中字段[talent_5]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="talent_5_value"){printf_message("PetTalent.csv中字段[talent_5_value]位置不对应 ");assert(false); return false; }

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
			PetTalentElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.talent_1=(int)atoi(vecLine[2].c_str());
			member.talent_2=(int)atoi(vecLine[4].c_str());
			member.talent_3=(int)atoi(vecLine[6].c_str());
			member.talent_4=(int)atoi(vecLine[8].c_str());
			member.talent_5=(int)atoi(vecLine[10].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
