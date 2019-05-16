#ifndef __EQUIPSUIT_CONFIG_H
#define __EQUIPSUIT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//装备套装配置数据结构
struct EquipSuitElement
{
	friend class EquipSuitTable;
	int id;                      	//套装id	标示套装等级，职业，品质 class{0}+level{000}+rank{0}+index{0}    class-2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    index-1_套装1;2_套装2
	string comment;              	//道具注释	策划用
	int name;                    	//套装名称	从String_Item表中进行查询
	int desc;                    	//套装描述	从String_Item表中进行查询
	vector<int> slot_1_equip;    	//对应武器	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_2_equip;    	//对应耳环	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_3_equip;    	//对应项链	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_4_equip;    	//对应戒指	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_5_equip;    	//对应帽子	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_6_equip;    	//对应胸甲	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_7_equip;    	//对应臂甲	item_proto中id 可以填入复数个 第一个为默认显示
	vector<int> slot_8_equip;    	//对应腿甲	item_proto中id 可以填入复数个 第一个为默认显示
	int effect_count;            	//效果数量	程序使用 用来计算套装的效果数量
	vector<string> suit_effect_1;	//套装效果1	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_2;	//套装效果2	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_3;	//套装效果3	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_4;	//套装效果4	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_5;	//套装效果5	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_6;	//套装效果6	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_7;	//套装效果7	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_8;	//套装效果8	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_9;	//套装效果9	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_10;	//套装效果10	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_11;	//套装效果11	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	vector<string> suit_effect_12;	//套装效果12	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值

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
	EquipSuitElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//装备套装配置封装类
class EquipSuitTable
{
	friend class TableData;
private:
	EquipSuitTable(){}
	~EquipSuitTable(){}
	map<int, EquipSuitElement>	m_mapElements;
	vector<EquipSuitElement>	m_vecAllElements;
	EquipSuitElement m_emptyItem;
public:
	static EquipSuitTable& Instance()
	{
		static EquipSuitTable sInstance;
		return sInstance;
	}

	EquipSuitElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EquipSuitElement>&	GetAllElement()
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
		if( LoadConfigContent("EquipSuit.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EquipSuit.bin", strTableContent ) )
		{
			printf_message("配置文件[EquipSuit.bin]未找到");
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
		if(vecLine.size() != 25)
		{
			printf_message("EquipSuit.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EquipSuit.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EquipSuit.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("EquipSuit.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("EquipSuit.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="slot_1_equip"){printf_message("EquipSuit.csv中字段[slot_1_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="slot_2_equip"){printf_message("EquipSuit.csv中字段[slot_2_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="slot_3_equip"){printf_message("EquipSuit.csv中字段[slot_3_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="slot_4_equip"){printf_message("EquipSuit.csv中字段[slot_4_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="slot_5_equip"){printf_message("EquipSuit.csv中字段[slot_5_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="slot_6_equip"){printf_message("EquipSuit.csv中字段[slot_6_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="slot_7_equip"){printf_message("EquipSuit.csv中字段[slot_7_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="slot_8_equip"){printf_message("EquipSuit.csv中字段[slot_8_equip]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="effect_count"){printf_message("EquipSuit.csv中字段[effect_count]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="suit_effect_1"){printf_message("EquipSuit.csv中字段[suit_effect_1]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="suit_effect_2"){printf_message("EquipSuit.csv中字段[suit_effect_2]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="suit_effect_3"){printf_message("EquipSuit.csv中字段[suit_effect_3]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="suit_effect_4"){printf_message("EquipSuit.csv中字段[suit_effect_4]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="suit_effect_5"){printf_message("EquipSuit.csv中字段[suit_effect_5]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="suit_effect_6"){printf_message("EquipSuit.csv中字段[suit_effect_6]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="suit_effect_7"){printf_message("EquipSuit.csv中字段[suit_effect_7]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="suit_effect_8"){printf_message("EquipSuit.csv中字段[suit_effect_8]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="suit_effect_9"){printf_message("EquipSuit.csv中字段[suit_effect_9]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="suit_effect_10"){printf_message("EquipSuit.csv中字段[suit_effect_10]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="suit_effect_11"){printf_message("EquipSuit.csv中字段[suit_effect_11]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="suit_effect_12"){printf_message("EquipSuit.csv中字段[suit_effect_12]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)25)
			{
				assert(false);
				return false;
			}
			EquipSuitElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.desc=(int)atoi(vecLine[3].c_str());
			member.effect_count=(int)atoi(vecLine[12].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
