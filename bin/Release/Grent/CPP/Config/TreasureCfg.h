#ifndef __TREASURE_CONFIG_H
#define __TREASURE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝物库表配置数据结构
struct TreasureElement
{
	friend class TreasureTable;
	int id;                      	//ID	
	string comment;              	//道具注释	策划用  附加信息说明： A、B、C代表外显使用时限 1、2、3、4代表外显不同配色
	string icon_resources;       	//图标资源	外显图标资源路径
	int explicit_sort;           	//外显分类	外显对应的分类 1：头部 2：时装 3：武器 4：翅膀 5：坐骑 6：脚印 7.技能特效
	int name;                    	//名字	外显名称 文本表ID
	int description;             	//描述	外显对应的描述文本 
	int site;                    	//所属部位	如果外显分类为1，该字段才生效 1：头部时装 2：衣服时装
	vector<int> occupation;      	//所属职业	该时装所属的职业ID 1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使 
	int quality;                 	//品质	1=绿色 2=蓝色 3=紫色
	int effect_judge;            	//是否具有特效	该外显是否有特殊效果 0：没有 1：有
	string effect_info;          	//特效信息	特效分类|特效名称|特效描述|特效ID 特效分类： 1：技能特效 2：嘲讽动作 3：脚印效果
	vector<int> extra_infoa1;    	//附加信息A1	 颜色（如：red、blue、green） 附加信息脚本（解锁时间）
	vector<int> resource_patha1; 	//资源路径A1	该外显的资源路径
	int treasure_pointsa1;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditiona11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditiona12;	//解锁条件2	
	vector<int> unlock_conditiona13;	//解锁条件3	
	vector<int> unlock_conditiona14;	//解锁条件4	
	vector<int> unlock_conditiona15;	//解锁条件5	
	vector<int> extra_infoa2;    	//附加信息A2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_patha2; 	//资源路径	该外显的资源路径
	int treasure_pointsa2;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditiona21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditiona22;	//解锁条件2	
	vector<int> unlock_conditiona23;	//解锁条件3	
	vector<int> unlock_conditiona24;	//解锁条件4	
	vector<int> unlock_conditiona25;	//解锁条件5	
	vector<int> extra_infoa3;    	//附加信息A3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_patha3; 	//资源路径	该外显的资源路径
	int treasure_pointsa3;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditiona31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditiona32;	//解锁条件2	
	vector<int> unlock_conditiona33;	//解锁条件3	
	vector<int> unlock_conditiona34;	//解锁条件4	
	vector<int> unlock_conditiona35;	//解锁条件5	
	vector<int> extra_infoa4;    	//附加信息A4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_patha4; 	//资源路径	该外显的资源路径
	int treasure_pointsa4;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditiona41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditiona42;	//解锁条件2	
	vector<int> unlock_conditiona43;	//解锁条件3	
	vector<int> unlock_conditiona44;	//解锁条件4	
	vector<int> unlock_conditiona45;	//解锁条件5	
	vector<int> extra_infob1;    	//附加信息B1	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathb1; 	//资源路径	该外显的资源路径
	int treasure_pointsb1;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionb11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionb12;	//解锁条件2	
	vector<int> unlock_conditionb13;	//解锁条件3	
	vector<int> unlock_conditionb14;	//解锁条件4	
	vector<int> unlock_conditionb15;	//解锁条件5	
	vector<int> extra_infob2;    	//附加信息B2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathb2; 	//资源路径	该外显的资源路径
	int treasure_pointsb2;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionb21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionb22;	//解锁条件2	
	vector<int> unlock_conditionb23;	//解锁条件3	
	vector<int> unlock_conditionb24;	//解锁条件4	
	vector<int> unlock_conditionb25;	//解锁条件5	
	vector<int> extra_infob3;    	//附加信息B3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathb3; 	//资源路径	该外显的资源路径
	int treasure_pointsb3;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionb31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionb32;	//解锁条件2	
	vector<int> unlock_conditionb33;	//解锁条件3	
	vector<int> unlock_conditionb34;	//解锁条件4	
	vector<int> unlock_conditionb35;	//解锁条件5	
	vector<int> extra_infob4;    	//附加信息B4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathb4; 	//资源路径	该外显的资源路径
	int treasure_pointsb4;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionb41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionb42;	//解锁条件2	
	vector<int> unlock_conditionb43;	//解锁条件3	
	vector<int> unlock_conditionb44;	//解锁条件4	
	vector<int> unlock_conditionb45;	//解锁条件5	
	vector<int> extra_infoc1;    	//附加信息C1	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathc1; 	//资源路径	该外显的资源路径
	int treasure_pointsc1;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionc11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionc12;	//解锁条件2	
	vector<int> unlock_conditionc13;	//解锁条件3	
	vector<int> unlock_conditionc14;	//解锁条件4	
	vector<int> unlock_conditionc15;	//解锁条件5	
	vector<int> extra_infoc2;    	//附加信息C2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathc2; 	//资源路径	该外显的资源路径
	int treasure_pointsc2;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionc21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionc22;	//解锁条件2	
	vector<int> unlock_conditionc23;	//解锁条件3	
	vector<int> unlock_conditionc24;	//解锁条件4	
	vector<int> unlock_conditionc25;	//解锁条件5	
	vector<int> extra_infoc3;    	//附加信息C3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathc3; 	//资源路径	该外显的资源路径
	int treasure_pointsc3;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionc31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionc32;	//解锁条件2	
	vector<int> unlock_conditionc33;	//解锁条件3	
	vector<int> unlock_conditionc34;	//解锁条件4	
	vector<int> unlock_conditionc35;	//解锁条件5	
	vector<int> extra_infoc4;    	//附加信息C4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	vector<int> resource_pathc4; 	//资源路径	该外显的资源路径
	int treasure_pointsc4;       	//宝物点数	该外显提供的宝物点数
	vector<int> unlock_conditionc41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	vector<int> unlock_conditionc42;	//解锁条件2	
	vector<int> unlock_conditionc43;	//解锁条件3	
	vector<int> unlock_conditionc44;	//解锁条件4	
	vector<int> unlock_conditionc45;	//解锁条件5	

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
	TreasureElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宝物库表配置封装类
class TreasureTable
{
	friend class TableData;
private:
	TreasureTable(){}
	~TreasureTable(){}
	map<int, TreasureElement>	m_mapElements;
	vector<TreasureElement>	m_vecAllElements;
	TreasureElement m_emptyItem;
public:
	static TreasureTable& Instance()
	{
		static TreasureTable sInstance;
		return sInstance;
	}

	TreasureElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TreasureElement>&	GetAllElement()
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
		if( LoadConfigContent("Treasure.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Treasure.bin", strTableContent ) )
		{
			printf_message("配置文件[Treasure.bin]未找到");
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
		if(vecLine.size() != 107)
		{
			printf_message("Treasure.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Treasure.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Treasure.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="icon_resources"){printf_message("Treasure.csv中字段[icon_resources]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="explicit_sort"){printf_message("Treasure.csv中字段[explicit_sort]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="name"){printf_message("Treasure.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="description"){printf_message("Treasure.csv中字段[description]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="site"){printf_message("Treasure.csv中字段[site]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="occupation"){printf_message("Treasure.csv中字段[occupation]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="quality"){printf_message("Treasure.csv中字段[quality]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="effect_judge"){printf_message("Treasure.csv中字段[effect_judge]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="effect_info"){printf_message("Treasure.csv中字段[effect_info]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="extra_infoa1"){printf_message("Treasure.csv中字段[extra_infoa1]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="resource_patha1"){printf_message("Treasure.csv中字段[resource_patha1]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="treasure_pointsa1"){printf_message("Treasure.csv中字段[treasure_pointsa1]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="unlock_conditiona11"){printf_message("Treasure.csv中字段[unlock_conditiona11]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="unlock_conditiona12"){printf_message("Treasure.csv中字段[unlock_conditiona12]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="unlock_conditiona13"){printf_message("Treasure.csv中字段[unlock_conditiona13]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="unlock_conditiona14"){printf_message("Treasure.csv中字段[unlock_conditiona14]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="unlock_conditiona15"){printf_message("Treasure.csv中字段[unlock_conditiona15]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="extra_infoa2"){printf_message("Treasure.csv中字段[extra_infoa2]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="resource_patha2"){printf_message("Treasure.csv中字段[resource_patha2]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="treasure_pointsa2"){printf_message("Treasure.csv中字段[treasure_pointsa2]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="unlock_conditiona21"){printf_message("Treasure.csv中字段[unlock_conditiona21]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="unlock_conditiona22"){printf_message("Treasure.csv中字段[unlock_conditiona22]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="unlock_conditiona23"){printf_message("Treasure.csv中字段[unlock_conditiona23]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="unlock_conditiona24"){printf_message("Treasure.csv中字段[unlock_conditiona24]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="unlock_conditiona25"){printf_message("Treasure.csv中字段[unlock_conditiona25]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="extra_infoa3"){printf_message("Treasure.csv中字段[extra_infoa3]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="resource_patha3"){printf_message("Treasure.csv中字段[resource_patha3]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="treasure_pointsa3"){printf_message("Treasure.csv中字段[treasure_pointsa3]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="unlock_conditiona31"){printf_message("Treasure.csv中字段[unlock_conditiona31]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="unlock_conditiona32"){printf_message("Treasure.csv中字段[unlock_conditiona32]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="unlock_conditiona33"){printf_message("Treasure.csv中字段[unlock_conditiona33]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="unlock_conditiona34"){printf_message("Treasure.csv中字段[unlock_conditiona34]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="unlock_conditiona35"){printf_message("Treasure.csv中字段[unlock_conditiona35]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="extra_infoa4"){printf_message("Treasure.csv中字段[extra_infoa4]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="resource_patha4"){printf_message("Treasure.csv中字段[resource_patha4]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="treasure_pointsa4"){printf_message("Treasure.csv中字段[treasure_pointsa4]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="unlock_conditiona41"){printf_message("Treasure.csv中字段[unlock_conditiona41]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="unlock_conditiona42"){printf_message("Treasure.csv中字段[unlock_conditiona42]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="unlock_conditiona43"){printf_message("Treasure.csv中字段[unlock_conditiona43]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="unlock_conditiona44"){printf_message("Treasure.csv中字段[unlock_conditiona44]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="unlock_conditiona45"){printf_message("Treasure.csv中字段[unlock_conditiona45]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="extra_infob1"){printf_message("Treasure.csv中字段[extra_infob1]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="resource_pathb1"){printf_message("Treasure.csv中字段[resource_pathb1]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="treasure_pointsb1"){printf_message("Treasure.csv中字段[treasure_pointsb1]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="unlock_conditionb11"){printf_message("Treasure.csv中字段[unlock_conditionb11]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="unlock_conditionb12"){printf_message("Treasure.csv中字段[unlock_conditionb12]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="unlock_conditionb13"){printf_message("Treasure.csv中字段[unlock_conditionb13]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="unlock_conditionb14"){printf_message("Treasure.csv中字段[unlock_conditionb14]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="unlock_conditionb15"){printf_message("Treasure.csv中字段[unlock_conditionb15]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="extra_infob2"){printf_message("Treasure.csv中字段[extra_infob2]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="resource_pathb2"){printf_message("Treasure.csv中字段[resource_pathb2]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="treasure_pointsb2"){printf_message("Treasure.csv中字段[treasure_pointsb2]位置不对应 ");assert(false); return false; }
		if(vecLine[54]!="unlock_conditionb21"){printf_message("Treasure.csv中字段[unlock_conditionb21]位置不对应 ");assert(false); return false; }
		if(vecLine[55]!="unlock_conditionb22"){printf_message("Treasure.csv中字段[unlock_conditionb22]位置不对应 ");assert(false); return false; }
		if(vecLine[56]!="unlock_conditionb23"){printf_message("Treasure.csv中字段[unlock_conditionb23]位置不对应 ");assert(false); return false; }
		if(vecLine[57]!="unlock_conditionb24"){printf_message("Treasure.csv中字段[unlock_conditionb24]位置不对应 ");assert(false); return false; }
		if(vecLine[58]!="unlock_conditionb25"){printf_message("Treasure.csv中字段[unlock_conditionb25]位置不对应 ");assert(false); return false; }
		if(vecLine[59]!="extra_infob3"){printf_message("Treasure.csv中字段[extra_infob3]位置不对应 ");assert(false); return false; }
		if(vecLine[60]!="resource_pathb3"){printf_message("Treasure.csv中字段[resource_pathb3]位置不对应 ");assert(false); return false; }
		if(vecLine[61]!="treasure_pointsb3"){printf_message("Treasure.csv中字段[treasure_pointsb3]位置不对应 ");assert(false); return false; }
		if(vecLine[62]!="unlock_conditionb31"){printf_message("Treasure.csv中字段[unlock_conditionb31]位置不对应 ");assert(false); return false; }
		if(vecLine[63]!="unlock_conditionb32"){printf_message("Treasure.csv中字段[unlock_conditionb32]位置不对应 ");assert(false); return false; }
		if(vecLine[64]!="unlock_conditionb33"){printf_message("Treasure.csv中字段[unlock_conditionb33]位置不对应 ");assert(false); return false; }
		if(vecLine[65]!="unlock_conditionb34"){printf_message("Treasure.csv中字段[unlock_conditionb34]位置不对应 ");assert(false); return false; }
		if(vecLine[66]!="unlock_conditionb35"){printf_message("Treasure.csv中字段[unlock_conditionb35]位置不对应 ");assert(false); return false; }
		if(vecLine[67]!="extra_infob4"){printf_message("Treasure.csv中字段[extra_infob4]位置不对应 ");assert(false); return false; }
		if(vecLine[68]!="resource_pathb4"){printf_message("Treasure.csv中字段[resource_pathb4]位置不对应 ");assert(false); return false; }
		if(vecLine[69]!="treasure_pointsb4"){printf_message("Treasure.csv中字段[treasure_pointsb4]位置不对应 ");assert(false); return false; }
		if(vecLine[70]!="unlock_conditionb41"){printf_message("Treasure.csv中字段[unlock_conditionb41]位置不对应 ");assert(false); return false; }
		if(vecLine[71]!="unlock_conditionb42"){printf_message("Treasure.csv中字段[unlock_conditionb42]位置不对应 ");assert(false); return false; }
		if(vecLine[72]!="unlock_conditionb43"){printf_message("Treasure.csv中字段[unlock_conditionb43]位置不对应 ");assert(false); return false; }
		if(vecLine[73]!="unlock_conditionb44"){printf_message("Treasure.csv中字段[unlock_conditionb44]位置不对应 ");assert(false); return false; }
		if(vecLine[74]!="unlock_conditionb45"){printf_message("Treasure.csv中字段[unlock_conditionb45]位置不对应 ");assert(false); return false; }
		if(vecLine[75]!="extra_infoc1"){printf_message("Treasure.csv中字段[extra_infoc1]位置不对应 ");assert(false); return false; }
		if(vecLine[76]!="resource_pathc1"){printf_message("Treasure.csv中字段[resource_pathc1]位置不对应 ");assert(false); return false; }
		if(vecLine[77]!="treasure_pointsc1"){printf_message("Treasure.csv中字段[treasure_pointsc1]位置不对应 ");assert(false); return false; }
		if(vecLine[78]!="unlock_conditionc11"){printf_message("Treasure.csv中字段[unlock_conditionc11]位置不对应 ");assert(false); return false; }
		if(vecLine[79]!="unlock_conditionc12"){printf_message("Treasure.csv中字段[unlock_conditionc12]位置不对应 ");assert(false); return false; }
		if(vecLine[80]!="unlock_conditionc13"){printf_message("Treasure.csv中字段[unlock_conditionc13]位置不对应 ");assert(false); return false; }
		if(vecLine[81]!="unlock_conditionc14"){printf_message("Treasure.csv中字段[unlock_conditionc14]位置不对应 ");assert(false); return false; }
		if(vecLine[82]!="unlock_conditionc15"){printf_message("Treasure.csv中字段[unlock_conditionc15]位置不对应 ");assert(false); return false; }
		if(vecLine[83]!="extra_infoc2"){printf_message("Treasure.csv中字段[extra_infoc2]位置不对应 ");assert(false); return false; }
		if(vecLine[84]!="resource_pathc2"){printf_message("Treasure.csv中字段[resource_pathc2]位置不对应 ");assert(false); return false; }
		if(vecLine[85]!="treasure_pointsc2"){printf_message("Treasure.csv中字段[treasure_pointsc2]位置不对应 ");assert(false); return false; }
		if(vecLine[86]!="unlock_conditionc21"){printf_message("Treasure.csv中字段[unlock_conditionc21]位置不对应 ");assert(false); return false; }
		if(vecLine[87]!="unlock_conditionc22"){printf_message("Treasure.csv中字段[unlock_conditionc22]位置不对应 ");assert(false); return false; }
		if(vecLine[88]!="unlock_conditionc23"){printf_message("Treasure.csv中字段[unlock_conditionc23]位置不对应 ");assert(false); return false; }
		if(vecLine[89]!="unlock_conditionc24"){printf_message("Treasure.csv中字段[unlock_conditionc24]位置不对应 ");assert(false); return false; }
		if(vecLine[90]!="unlock_conditionc25"){printf_message("Treasure.csv中字段[unlock_conditionc25]位置不对应 ");assert(false); return false; }
		if(vecLine[91]!="extra_infoc3"){printf_message("Treasure.csv中字段[extra_infoc3]位置不对应 ");assert(false); return false; }
		if(vecLine[92]!="resource_pathc3"){printf_message("Treasure.csv中字段[resource_pathc3]位置不对应 ");assert(false); return false; }
		if(vecLine[93]!="treasure_pointsc3"){printf_message("Treasure.csv中字段[treasure_pointsc3]位置不对应 ");assert(false); return false; }
		if(vecLine[94]!="unlock_conditionc31"){printf_message("Treasure.csv中字段[unlock_conditionc31]位置不对应 ");assert(false); return false; }
		if(vecLine[95]!="unlock_conditionc32"){printf_message("Treasure.csv中字段[unlock_conditionc32]位置不对应 ");assert(false); return false; }
		if(vecLine[96]!="unlock_conditionc33"){printf_message("Treasure.csv中字段[unlock_conditionc33]位置不对应 ");assert(false); return false; }
		if(vecLine[97]!="unlock_conditionc34"){printf_message("Treasure.csv中字段[unlock_conditionc34]位置不对应 ");assert(false); return false; }
		if(vecLine[98]!="unlock_conditionc35"){printf_message("Treasure.csv中字段[unlock_conditionc35]位置不对应 ");assert(false); return false; }
		if(vecLine[99]!="extra_infoc4"){printf_message("Treasure.csv中字段[extra_infoc4]位置不对应 ");assert(false); return false; }
		if(vecLine[100]!="resource_pathc4"){printf_message("Treasure.csv中字段[resource_pathc4]位置不对应 ");assert(false); return false; }
		if(vecLine[101]!="treasure_pointsc4"){printf_message("Treasure.csv中字段[treasure_pointsc4]位置不对应 ");assert(false); return false; }
		if(vecLine[102]!="unlock_conditionc41"){printf_message("Treasure.csv中字段[unlock_conditionc41]位置不对应 ");assert(false); return false; }
		if(vecLine[103]!="unlock_conditionc42"){printf_message("Treasure.csv中字段[unlock_conditionc42]位置不对应 ");assert(false); return false; }
		if(vecLine[104]!="unlock_conditionc43"){printf_message("Treasure.csv中字段[unlock_conditionc43]位置不对应 ");assert(false); return false; }
		if(vecLine[105]!="unlock_conditionc44"){printf_message("Treasure.csv中字段[unlock_conditionc44]位置不对应 ");assert(false); return false; }
		if(vecLine[106]!="unlock_conditionc45"){printf_message("Treasure.csv中字段[unlock_conditionc45]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)107)
			{
				assert(false);
				return false;
			}
			TreasureElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.icon_resources=vecLine[2];
			member.explicit_sort=(int)atoi(vecLine[3].c_str());
			member.name=(int)atoi(vecLine[4].c_str());
			member.description=(int)atoi(vecLine[5].c_str());
			member.site=(int)atoi(vecLine[6].c_str());
			member.quality=(int)atoi(vecLine[8].c_str());
			member.effect_judge=(int)atoi(vecLine[9].c_str());
			member.effect_info=vecLine[10];
			member.treasure_pointsa1=(int)atoi(vecLine[13].c_str());
			member.treasure_pointsa2=(int)atoi(vecLine[21].c_str());
			member.treasure_pointsa3=(int)atoi(vecLine[29].c_str());
			member.treasure_pointsa4=(int)atoi(vecLine[37].c_str());
			member.treasure_pointsb1=(int)atoi(vecLine[45].c_str());
			member.treasure_pointsb2=(int)atoi(vecLine[53].c_str());
			member.treasure_pointsb3=(int)atoi(vecLine[61].c_str());
			member.treasure_pointsb4=(int)atoi(vecLine[69].c_str());
			member.treasure_pointsc1=(int)atoi(vecLine[77].c_str());
			member.treasure_pointsc2=(int)atoi(vecLine[85].c_str());
			member.treasure_pointsc3=(int)atoi(vecLine[93].c_str());
			member.treasure_pointsc4=(int)atoi(vecLine[101].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
