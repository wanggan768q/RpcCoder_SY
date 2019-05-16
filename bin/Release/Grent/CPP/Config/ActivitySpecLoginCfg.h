#ifndef __ACTIVITYSPECLOGIN_CONFIG_H
#define __ACTIVITYSPECLOGIN_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//运营登录活动表配置数据结构
struct ActivitySpecLoginElement
{
	friend class ActivitySpecLoginTable;
	int id;                      	//主键id	活动id
	string comment;              	//注释	策划用
	string main_pic;             	//主图名称	填写图片名
	string sub_pic;              	//文字图	填写文本图片名
	int function_on;             	//是否开启	0 不开启 1 开启
	int call;                    	//支持开启弹窗提醒	0 不开启 1 开启
	int group;                   	//组别	同活动填写同组ID
	int weight;                  	//权重	标签列表内的显示权重
	int level_min;               	//最低等级限制	可参与最低等级
	int name_id;                 	//名称id	string_UI
	int describe_id;             	//描述文本id	string_UI
	int open_type;               	//时间类型	1-开服后开启 2-固定日期开启
	string open_time;            	//开启活动日期 默认服务器时间0点开启	type=1，该列-1 type=2，活动第1天年月日
	int days;                    	//活动所需登录天数	填写整数
	int duration;                	//活动持续天数	填写整数
	vector<int> day1_rewards;    	//道具ID|数量|是否中转	60013001|1|0
	vector<int> day2_rewards;    	//道具ID|数量|是否中转	60012001|1|0
	vector<int> day3_rewards;    	//道具ID|数量|是否中转	80432005|1|0
	vector<int> day4_rewards;    	//道具ID|数量|是否中转	60030001|1|0
	vector<int> day5_rewards;    	//道具ID|数量|是否中转	71000005|1|0
	vector<int> day6_rewards;    	//道具ID|数量|是否中转	60011001|1|0
	vector<int> day7_rewards;    	//道具ID|数量|是否中转	71000005|1|0

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
	ActivitySpecLoginElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//运营登录活动表配置封装类
class ActivitySpecLoginTable
{
	friend class TableData;
private:
	ActivitySpecLoginTable(){}
	~ActivitySpecLoginTable(){}
	map<int, ActivitySpecLoginElement>	m_mapElements;
	vector<ActivitySpecLoginElement>	m_vecAllElements;
	ActivitySpecLoginElement m_emptyItem;
public:
	static ActivitySpecLoginTable& Instance()
	{
		static ActivitySpecLoginTable sInstance;
		return sInstance;
	}

	ActivitySpecLoginElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ActivitySpecLoginElement>&	GetAllElement()
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
		if( LoadConfigContent("ActivitySpecLogin.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ActivitySpecLogin.bin", strTableContent ) )
		{
			printf_message("配置文件[ActivitySpecLogin.bin]未找到");
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
			printf_message("ActivitySpecLogin.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ActivitySpecLogin.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ActivitySpecLogin.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="main_pic"){printf_message("ActivitySpecLogin.csv中字段[main_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="sub_pic"){printf_message("ActivitySpecLogin.csv中字段[sub_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="function_on"){printf_message("ActivitySpecLogin.csv中字段[function_on]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="call"){printf_message("ActivitySpecLogin.csv中字段[call]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="group"){printf_message("ActivitySpecLogin.csv中字段[group]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="weight"){printf_message("ActivitySpecLogin.csv中字段[weight]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="level_min"){printf_message("ActivitySpecLogin.csv中字段[level_min]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="name_id"){printf_message("ActivitySpecLogin.csv中字段[name_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="describe_id"){printf_message("ActivitySpecLogin.csv中字段[describe_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="open_type"){printf_message("ActivitySpecLogin.csv中字段[open_type]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="open_time"){printf_message("ActivitySpecLogin.csv中字段[open_time]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="days"){printf_message("ActivitySpecLogin.csv中字段[days]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="duration"){printf_message("ActivitySpecLogin.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="day1_rewards"){printf_message("ActivitySpecLogin.csv中字段[day1_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="day2_rewards"){printf_message("ActivitySpecLogin.csv中字段[day2_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="day3_rewards"){printf_message("ActivitySpecLogin.csv中字段[day3_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="day4_rewards"){printf_message("ActivitySpecLogin.csv中字段[day4_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="day5_rewards"){printf_message("ActivitySpecLogin.csv中字段[day5_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="day6_rewards"){printf_message("ActivitySpecLogin.csv中字段[day6_rewards]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="day7_rewards"){printf_message("ActivitySpecLogin.csv中字段[day7_rewards]位置不对应 ");assert(false); return false; }

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
			ActivitySpecLoginElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.main_pic=vecLine[2];
			member.sub_pic=vecLine[3];
			member.function_on=(int)atoi(vecLine[4].c_str());
			member.call=(int)atoi(vecLine[5].c_str());
			member.group=(int)atoi(vecLine[6].c_str());
			member.weight=(int)atoi(vecLine[7].c_str());
			member.level_min=(int)atoi(vecLine[8].c_str());
			member.name_id=(int)atoi(vecLine[9].c_str());
			member.describe_id=(int)atoi(vecLine[10].c_str());
			member.open_type=(int)atoi(vecLine[11].c_str());
			member.open_time=vecLine[12];
			member.days=(int)atoi(vecLine[13].c_str());
			member.duration=(int)atoi(vecLine[14].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
