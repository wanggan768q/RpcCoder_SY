#ifndef __UICATEGORY_CONFIG_H
#define __UICATEGORY_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//界面类型配置数据结构
struct UICategoryElement
{
	friend class UICategoryTable;
	int id;                      	//数据id	界面或者按钮的id (来源表引用， 一旦定下， 最好不要再修改)
	string comment;              	//注释	该界面的功能
	int is_on;                   	//功能开关	表示该功能在版本中是否启用  0.未启用 1.启用
	int order;                   	//序列	无意义 用来对id进行生成
	int type;                    	//分类	用来区分枚举 0.HUD 1.背包 2.培养 3.打造 4.宠物 5.宠物提升 6.宝石合成 7.活动 8.积分商店 9.珍宝阁 10.生活技能 11.赠送礼物 12.拍卖行
	int category;                	//	0.UI 1.button
	int unlock_lv;               	//解锁等级	当玩家达到这个等级时解锁这个功能 等级默认为1
	int unlock_quest;            	//解锁任务	当玩家完成该任务后，会解锁这个功能 和等级共同生效 可不填
	int name;                    	//界面名称	该界面对应StringUI表的id
	string icon;                 	//界面标示	该界面对应的图标名称
	string btn_name;             	//按钮名称	如果是按钮类型，则需要填写该字段，以识别按钮对象
	string prefab;               	//界面资源	该界面对应的prefab名称
	int tab;                     	//界面标签页	界面标签页对应的枚举 需要按照功能进行分配  另外用来定义每个页面中各个页签的上下顺序

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
	UICategoryElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//界面类型配置封装类
class UICategoryTable
{
	friend class TableData;
private:
	UICategoryTable(){}
	~UICategoryTable(){}
	map<int, UICategoryElement>	m_mapElements;
	vector<UICategoryElement>	m_vecAllElements;
	UICategoryElement m_emptyItem;
public:
	static UICategoryTable& Instance()
	{
		static UICategoryTable sInstance;
		return sInstance;
	}

	UICategoryElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<UICategoryElement>&	GetAllElement()
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
		if( LoadConfigContent("UICategory.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("UICategory.bin", strTableContent ) )
		{
			printf_message("配置文件[UICategory.bin]未找到");
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
		if(vecLine.size() != 13)
		{
			printf_message("UICategory.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("UICategory.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("UICategory.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="is_on"){printf_message("UICategory.csv中字段[is_on]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="order"){printf_message("UICategory.csv中字段[order]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="type"){printf_message("UICategory.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="category"){printf_message("UICategory.csv中字段[category]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="unlock_lv"){printf_message("UICategory.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="unlock_quest"){printf_message("UICategory.csv中字段[unlock_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="name"){printf_message("UICategory.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="icon"){printf_message("UICategory.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="btn_name"){printf_message("UICategory.csv中字段[btn_name]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="prefab"){printf_message("UICategory.csv中字段[prefab]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="tab"){printf_message("UICategory.csv中字段[tab]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)13)
			{
				assert(false);
				return false;
			}
			UICategoryElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.is_on=(int)atoi(vecLine[2].c_str());
			member.order=(int)atoi(vecLine[3].c_str());
			member.type=(int)atoi(vecLine[4].c_str());
			member.category=(int)atoi(vecLine[5].c_str());
			member.unlock_lv=(int)atoi(vecLine[6].c_str());
			member.unlock_quest=(int)atoi(vecLine[7].c_str());
			member.name=(int)atoi(vecLine[8].c_str());
			member.icon=vecLine[9];
			member.btn_name=vecLine[10];
			member.prefab=vecLine[11];
			member.tab=(int)atoi(vecLine[12].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
