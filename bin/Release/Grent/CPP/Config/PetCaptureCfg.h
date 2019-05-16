#ifndef __PETCAPTURE_CONFIG_H
#define __PETCAPTURE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宠物捕获表配置数据结构
struct PetCaptureElement
{
	friend class PetCaptureTable;
	int id;                      	//宠物npcid	填写ID即可
	string comment;              	//注释	策划用
	int name;                    	//宠物名称	显示的宠物原型ID StringItem_道具文本表
	int npcid;                   	//宠物NPCID	显示的宠物NPCID 已经无用，从场景内随机
	vector<int> rate_up;         	//精灵球增益值	用普通球|大师球捕获时的增益值
	vector<int> rate;            	//掉落包阈值	增益值达到这个值使用下个掉落包
	vector<int> reward_id;       	//宠物掉落包	低级球每一个区间使用的掉落包
	vector<int> highreword_id;   	//宠物掉落包高级球	高级球每一个区间使用的掉落包
	int equip_id;                	//宠物原型ID	获得此类宠物道具后，该宠物npc刷新
	vector<int> scene_id;        	//刷新场景ID	宠物npc在刷新的场景顺序
	string refresh;              	//刷新时间	宠物npc在第一个场景刷新的时间
	int time;                    	//掉落生命周期	显示的宠物掉落存在时间 

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
	PetCaptureElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宠物捕获表配置封装类
class PetCaptureTable
{
	friend class TableData;
private:
	PetCaptureTable(){}
	~PetCaptureTable(){}
	map<int, PetCaptureElement>	m_mapElements;
	vector<PetCaptureElement>	m_vecAllElements;
	PetCaptureElement m_emptyItem;
public:
	static PetCaptureTable& Instance()
	{
		static PetCaptureTable sInstance;
		return sInstance;
	}

	PetCaptureElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<PetCaptureElement>&	GetAllElement()
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
		if( LoadConfigContent("PetCapture.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("PetCapture.bin", strTableContent ) )
		{
			printf_message("配置文件[PetCapture.bin]未找到");
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
			printf_message("PetCapture.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("PetCapture.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("PetCapture.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("PetCapture.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="npcid"){printf_message("PetCapture.csv中字段[npcid]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="rate_up"){printf_message("PetCapture.csv中字段[rate_up]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="rate"){printf_message("PetCapture.csv中字段[rate]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="reward_id"){printf_message("PetCapture.csv中字段[reward_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="highreword_id"){printf_message("PetCapture.csv中字段[highreword_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="equip_id"){printf_message("PetCapture.csv中字段[equip_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="scene_id"){printf_message("PetCapture.csv中字段[scene_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="refresh"){printf_message("PetCapture.csv中字段[refresh]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="time"){printf_message("PetCapture.csv中字段[time]位置不对应 ");assert(false); return false; }

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
			PetCaptureElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.npcid=(int)atoi(vecLine[3].c_str());
			member.equip_id=(int)atoi(vecLine[8].c_str());
			member.refresh=vecLine[10];
			member.time=(int)atoi(vecLine[11].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
