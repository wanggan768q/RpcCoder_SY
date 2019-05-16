#ifndef __EQUIPRESONANCE_CONFIG_H
#define __EQUIPRESONANCE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备共鸣配置数据结构
struct EquipResonanceElement
{
	friend class EquipResonanceTable;
	int id;                      	//阶级ID	每个阶级所对应的唯一ID
	string comment;              	//阶级注释	策划用
	int marquee;                 	//跑马灯	0不显示 1显示
	string roman_picture;        	//罗马数字图片	左侧菜单中的罗马数字图片资源
	string roman_picture2;       	//罗马数字底图	底板中的罗马数字图片资源
	int ui_text1;                	//界面文本1	按照id引用string_ui表中的文本信息
	int ui_text2;                	//界面文本2	按照id引用string_ui表中的文本信息
	int ui_text3;                	//界面文本3	按照id引用string_ui表中的文本信息
	vector<int> occupation;      	//适用职业	1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使
	int rank;                    	//级别	
	int unlock_level;            	//解锁等级	该阶级解锁所需要的装备的等级
	int unlock_rank;             	//解锁稀有度	该阶级解锁所需要的装备的稀有度 2：蓝色（稀有） 3：紫色（史诗） 4：橙色（传说）
	vector<float> attribute1;    	//属性条目/对应系数1	属性条目id|属性等级系数
	vector<float> attribute2;    	//属性条目/对应系数2	属性条目id|属性等级系数
	vector<float> attribute3;    	//属性条目/对应系数3	属性条目id|属性等级系数
	vector<float> attribute4;    	//属性条目/对应系数4	属性条目id|属性等级系数
	vector<float> single_interval;	//单项区间	区间下限|区间上限
	vector<float> sum_interval;  	//和区间	和区间下限|和区间上限
	int first_level;             	//初始等级	解锁该阶级时所有属性的初始等级
	int level_limit;             	//等级上限	该阶级所有属性等级的上限值
	int item_cost;               	//消耗道具ID	进行属性培养时消耗的道具ID
	int num;                     	//数量	消耗的道具数量

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
	EquipResonanceElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备共鸣配置封装类
class EquipResonanceTable
{
	friend class TableData;
private:
	EquipResonanceTable(){}
	~EquipResonanceTable(){}
	map<int, EquipResonanceElement>	m_mapElements;
	vector<EquipResonanceElement>	m_vecAllElements;
	EquipResonanceElement m_emptyItem;
public:
	static EquipResonanceTable& Instance()
	{
		static EquipResonanceTable sInstance;
		return sInstance;
	}

	EquipResonanceElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipResonanceElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipResonance.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipResonance.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipResonance.bin]未找到");
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
		if(vecLine.size() != 22)
		{
			printf_message("EquipResonance.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipResonance.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipResonance.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="marquee"){printf_message("EquipResonance.csv中字段[marquee]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="roman_picture"){printf_message("EquipResonance.csv中字段[roman_picture]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="roman_picture2"){printf_message("EquipResonance.csv中字段[roman_picture2]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="ui_text1"){printf_message("EquipResonance.csv中字段[ui_text1]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="ui_text2"){printf_message("EquipResonance.csv中字段[ui_text2]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="ui_text3"){printf_message("EquipResonance.csv中字段[ui_text3]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="occupation"){printf_message("EquipResonance.csv中字段[occupation]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="rank"){printf_message("EquipResonance.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="unlock_level"){printf_message("EquipResonance.csv中字段[unlock_level]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="unlock_rank"){printf_message("EquipResonance.csv中字段[unlock_rank]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="attribute1"){printf_message("EquipResonance.csv中字段[attribute1]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="attribute2"){printf_message("EquipResonance.csv中字段[attribute2]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="attribute3"){printf_message("EquipResonance.csv中字段[attribute3]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="attribute4"){printf_message("EquipResonance.csv中字段[attribute4]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="single_interval"){printf_message("EquipResonance.csv中字段[single_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="sum_interval"){printf_message("EquipResonance.csv中字段[sum_interval]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="first_level"){printf_message("EquipResonance.csv中字段[first_level]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="level_limit"){printf_message("EquipResonance.csv中字段[level_limit]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="item_cost"){printf_message("EquipResonance.csv中字段[item_cost]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="num"){printf_message("EquipResonance.csv中字段[num]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)22)
			{
				assert(false);
				return false;
			}
			EquipResonanceElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.marquee=(int)atoi(vecLine[2].c_str());
			member.roman_picture=vecLine[3];
			member.roman_picture2=vecLine[4];
			member.ui_text1=(int)atoi(vecLine[5].c_str());
			member.ui_text2=(int)atoi(vecLine[6].c_str());
			member.ui_text3=(int)atoi(vecLine[7].c_str());
			member.rank=(int)atoi(vecLine[9].c_str());
			member.unlock_level=(int)atoi(vecLine[10].c_str());
			member.unlock_rank=(int)atoi(vecLine[11].c_str());
			member.first_level=(int)atoi(vecLine[18].c_str());
			member.level_limit=(int)atoi(vecLine[19].c_str());
			member.item_cost=(int)atoi(vecLine[20].c_str());
			member.num=(int)atoi(vecLine[21].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
