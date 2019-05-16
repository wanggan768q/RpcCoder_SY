#ifndef __OPERATION_CONFIG_H
#define __OPERATION_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//activities_运营活动表配置数据结构
struct OperationElement
{
	friend class OperationTable;
	int id;                      	//主键id	活动id
	string comment;              	//注释	策划用
	int name;                    	//名称ID	对应stringui表文字ID，显示在福利的右标签页上
	int entry_location;          	//界面入口位置	1. 福利界面 2. 主界面 3. 运营活动界面
	string main_pic;             	//背景图	Entry_location为1的话，此列无效 Entry_location为2的话，配置的是主界面入口的图标 Entry_location为3的话，配置的是界面的背景图 
	int activity_type;           	//活动类型	1：七日任务
	int activity_time_type;      	//七日目标时间类型	0：从角色进入游戏时开始计时 1：配置指定日期
	string target_type;          	//活动开始时间	如果activity_type列配置为0，此列不填
	int recorded_data_days;      	//记录数据天数	配置天数
	int get_rewards_days;        	//活动结束天数	配置天数，玩家在此天数内可以领奖，如果超过此天数那么活动将会直接结束，从界面上消失
	int level_min;               	//最低等级限制	可参与最低等级
	vector<int> parameter1;      	//1日目标	对应目标表中的ID
	vector<int> parameter2;      	//2日目标	对应目标表中的ID
	vector<int> parameter3;      	//3日目标	对应目标表中的ID
	vector<int> parameter4;      	//4日目标	对应目标表中的ID
	vector<int> parameter5;      	//5日目标	对应目标表中的ID
	vector<int> parameter6;      	//6日目标	对应目标表中的ID
	vector<int> parameter7;      	//7日目标	对应目标表中的ID
	vector<int> accumulate_point_quest_id;	//积分奖励	积分奖励是用任务的方式来实现，我会在此列中配置5个任务，这5个任务分别对应界面上的5个积分奖励
	int Model_table;             	//模型表格	配置Model_display列的数据去哪个表格读取： 1：CharacterCustomize_角色自定义 2：CharacterConfig_模型配置
	int Model_display;           	//模型展示	配置左侧展示的模型，对应模型表ID。
	vector<int> accumulate_point;	//积分奖励显示	客户端用，用于配置每个奖励要求的积分值

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
	OperationElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//activities_运营活动表配置封装类
class OperationTable
{
	friend class TableData;
private:
	OperationTable(){}
	~OperationTable(){}
	map<int, OperationElement>	m_mapElements;
	vector<OperationElement>	m_vecAllElements;
	OperationElement m_emptyItem;
public:
	static OperationTable& Instance()
	{
		static OperationTable sInstance;
		return sInstance;
	}

	OperationElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<OperationElement>&	GetAllElement()
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
		if( LoadConfigContent("Operation.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Operation.bin", strTableContent ) )
		{
			printf_message("配置文件[Operation.bin]未找到");
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
			printf_message("Operation.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Operation.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Operation.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("Operation.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="entry_location"){printf_message("Operation.csv中字段[entry_location]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="main_pic"){printf_message("Operation.csv中字段[main_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="activity_type"){printf_message("Operation.csv中字段[activity_type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="activity_time_type"){printf_message("Operation.csv中字段[activity_time_type]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="target_type"){printf_message("Operation.csv中字段[target_type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="recorded_data_days"){printf_message("Operation.csv中字段[recorded_data_days]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="get_rewards_days"){printf_message("Operation.csv中字段[get_rewards_days]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="level_min"){printf_message("Operation.csv中字段[level_min]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="parameter1"){printf_message("Operation.csv中字段[parameter1]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="parameter2"){printf_message("Operation.csv中字段[parameter2]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="parameter3"){printf_message("Operation.csv中字段[parameter3]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="parameter4"){printf_message("Operation.csv中字段[parameter4]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="parameter5"){printf_message("Operation.csv中字段[parameter5]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="parameter6"){printf_message("Operation.csv中字段[parameter6]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="parameter7"){printf_message("Operation.csv中字段[parameter7]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="accumulate_point_quest_id"){printf_message("Operation.csv中字段[accumulate_point_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="Model_table"){printf_message("Operation.csv中字段[Model_table]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="Model_display"){printf_message("Operation.csv中字段[Model_display]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="accumulate_point"){printf_message("Operation.csv中字段[accumulate_point]位置不对应 ");assert(false); return false; }

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
			OperationElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.entry_location=(int)atoi(vecLine[3].c_str());
			member.main_pic=vecLine[4];
			member.activity_type=(int)atoi(vecLine[5].c_str());
			member.activity_time_type=(int)atoi(vecLine[6].c_str());
			member.target_type=vecLine[7];
			member.recorded_data_days=(int)atoi(vecLine[8].c_str());
			member.get_rewards_days=(int)atoi(vecLine[9].c_str());
			member.level_min=(int)atoi(vecLine[10].c_str());
			member.Model_table=(int)atoi(vecLine[19].c_str());
			member.Model_display=(int)atoi(vecLine[20].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
