#ifndef __CREATUREHIDE_CONFIG_H
#define __CREATUREHIDE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//NPC或OBJ显示隐藏表配置数据结构
struct CreatureHideElement
{
	friend class CreatureHideTable;
	int id;                      	//序号	唯一值
	string comment;              	//任务备注	仅策划用
	int quest_id;                	//任务id	任务状态为0时，该列为0任务表中对应ID
	int quest_status;            	//任务状态	0=接取前 1=进行中 2=任务结束
	int quest_step_1;            	//任务步骤1	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标1是否完成 0=未完成 1=完成
	int quest_step_2;            	//任务步骤2	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标2是否完成 0=未完成 1=完成
	int quest_step_3;            	//任务步骤3	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标3是否完成 0=未完成 1=完成
	int quest_step_4;            	//任务步骤4	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标4是否完成 0=未完成 1=完成
	int quest_step_5;            	//任务步骤5	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标5是否完成 0=未完成 1=完成
	int creature_status;         	//NPC状态	0=显示 1=隐藏

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
	CreatureHideElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//NPC或OBJ显示隐藏表配置封装类
class CreatureHideTable
{
	friend class TableData;
private:
	CreatureHideTable(){}
	~CreatureHideTable(){}
	map<int, CreatureHideElement>	m_mapElements;
	vector<CreatureHideElement>	m_vecAllElements;
	CreatureHideElement m_emptyItem;
public:
	static CreatureHideTable& Instance()
	{
		static CreatureHideTable sInstance;
		return sInstance;
	}

	CreatureHideElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CreatureHideElement>&	GetAllElement()
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
		if( LoadConfigContent("CreatureHide.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CreatureHide.bin", strTableContent ) )
		{
			printf_message("配置文件[CreatureHide.bin]未找到");
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
			printf_message("CreatureHide.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CreatureHide.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CreatureHide.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="quest_id"){printf_message("CreatureHide.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="quest_status"){printf_message("CreatureHide.csv中字段[quest_status]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="quest_step_1"){printf_message("CreatureHide.csv中字段[quest_step_1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="quest_step_2"){printf_message("CreatureHide.csv中字段[quest_step_2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="quest_step_3"){printf_message("CreatureHide.csv中字段[quest_step_3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="quest_step_4"){printf_message("CreatureHide.csv中字段[quest_step_4]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="quest_step_5"){printf_message("CreatureHide.csv中字段[quest_step_5]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="creature_status"){printf_message("CreatureHide.csv中字段[creature_status]位置不对应 ");assert(false); return false; }

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
			CreatureHideElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.quest_id=(int)atoi(vecLine[2].c_str());
			member.quest_status=(int)atoi(vecLine[3].c_str());
			member.quest_step_1=(int)atoi(vecLine[4].c_str());
			member.quest_step_2=(int)atoi(vecLine[5].c_str());
			member.quest_step_3=(int)atoi(vecLine[6].c_str());
			member.quest_step_4=(int)atoi(vecLine[7].c_str());
			member.quest_step_5=(int)atoi(vecLine[8].c_str());
			member.creature_status=(int)atoi(vecLine[9].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
