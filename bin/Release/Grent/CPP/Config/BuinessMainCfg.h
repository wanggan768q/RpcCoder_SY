#ifndef __BUINESSMAIN_CONFIG_H
#define __BUINESSMAIN_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//生活技能总览配置数据结构
struct BuinessMainElement
{
	friend class BuinessMainTable;
	int id;                      	//生活技能ID	生活技能ID
	string comment;              	//注释	注释
	int name;                    	//生活技能名	文本id
	int desc;                    	//描述	文本id
	string icon;                 	//技能图标	资源名
	vector<int> expend;          	//升级所需货币	前帮贡|后银币
	int learn_desc;              	//学习二次确认	填写文本id
	int change_desc;             	//更换二次确认	填写文本id
	int info_desc;               	//更换界面文本	填写文本id
	int up_value;                	//学习1次增加经验值	1次经验值
	int need_lv;                 	//开启所需玩家等级	开启条件
	int mutual;                  	//互斥关系	同数互斥
	int item;                    	//技能书	界面扣除
	int item_times;              	//技能书每天可使用次数	填写次数
	int item_exp;                	//技能书使用获得经验	填写经验
	vector<int> make_items;      	//该技能可制作道具	填写道具组
	int change_type;             	//扣cd是1扣钱是2	填写1或2即可
	int cd_time;                 	//更换成功后的cd时间	填写时间小时为单位
	vector<int> currency;        	//更换所需货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	int change_tips;             	//扣钱或时间时提示	填写文本id

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
	BuinessMainElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//生活技能总览配置封装类
class BuinessMainTable
{
	friend class TableData;
private:
	BuinessMainTable(){}
	~BuinessMainTable(){}
	map<int, BuinessMainElement>	m_mapElements;
	vector<BuinessMainElement>	m_vecAllElements;
	BuinessMainElement m_emptyItem;
public:
	static BuinessMainTable& Instance()
	{
		static BuinessMainTable sInstance;
		return sInstance;
	}

	BuinessMainElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuinessMainElement>&	GetAllElement()
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
		if( LoadConfigContent("BuinessMain.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BuinessMain.bin", strTableContent ) )
		{
			printf_message("配置文件[BuinessMain.bin]未找到");
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
		if(vecLine.size() != 20)
		{
			printf_message("BuinessMain.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("BuinessMain.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("BuinessMain.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("BuinessMain.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("BuinessMain.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon"){printf_message("BuinessMain.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="expend"){printf_message("BuinessMain.csv中字段[expend]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="learn_desc"){printf_message("BuinessMain.csv中字段[learn_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="change_desc"){printf_message("BuinessMain.csv中字段[change_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="info_desc"){printf_message("BuinessMain.csv中字段[info_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="up_value"){printf_message("BuinessMain.csv中字段[up_value]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="need_lv"){printf_message("BuinessMain.csv中字段[need_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="mutual"){printf_message("BuinessMain.csv中字段[mutual]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="item"){printf_message("BuinessMain.csv中字段[item]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="item_times"){printf_message("BuinessMain.csv中字段[item_times]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="item_exp"){printf_message("BuinessMain.csv中字段[item_exp]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="make_items"){printf_message("BuinessMain.csv中字段[make_items]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="change_type"){printf_message("BuinessMain.csv中字段[change_type]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="cd_time"){printf_message("BuinessMain.csv中字段[cd_time]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="currency"){printf_message("BuinessMain.csv中字段[currency]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="change_tips"){printf_message("BuinessMain.csv中字段[change_tips]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)20)
			{
				assert(false);
				return false;
			}
			BuinessMainElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.desc=(int)atoi(vecLine[3].c_str());
			member.icon=vecLine[4];
			member.learn_desc=(int)atoi(vecLine[6].c_str());
			member.change_desc=(int)atoi(vecLine[7].c_str());
			member.info_desc=(int)atoi(vecLine[8].c_str());
			member.up_value=(int)atoi(vecLine[9].c_str());
			member.need_lv=(int)atoi(vecLine[10].c_str());
			member.mutual=(int)atoi(vecLine[11].c_str());
			member.item=(int)atoi(vecLine[12].c_str());
			member.item_times=(int)atoi(vecLine[13].c_str());
			member.item_exp=(int)atoi(vecLine[14].c_str());
			member.change_type=(int)atoi(vecLine[16].c_str());
			member.cd_time=(int)atoi(vecLine[17].c_str());
			member.change_tips=(int)atoi(vecLine[19].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
