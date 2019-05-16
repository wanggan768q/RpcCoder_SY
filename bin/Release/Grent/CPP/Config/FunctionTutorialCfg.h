#ifndef __FUNCTIONTUTORIAL_CONFIG_H
#define __FUNCTIONTUTORIAL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//功能引导表配置数据结构
struct FunctionTutorialElement
{
	friend class FunctionTutorialTable;
	int id;                      	//引导条目	界面或者按钮的id id = function * 100 +index
	string comment;              	//引导描述	不使用
	int is_on;                   	//引导开关	0.未开启 1.开启 未开启的引导在游戏中不使用  只针对index为1的生效
	int function_id;             	//功能条目	用来标识该引导对应的功能，无特殊意义
	int index;                   	//引导步骤	用来生成id 无特殊意义
	int trigger_type;            	//引导触发条件	枚举如下 1.完成任务 2.领取任务 3.打开界面 4.等级提升 5.装备等级(无法使用) 6.背包充满 7.获得道具 8.使用道具
	int trigger_param;           	//条件参数	根据枚举类型决定 1.任务ID 2.任务ID 3.不填—调用prefab字段 4.等级 5.装备等级 6.不填 7.道具ID 8.道具ID
	int next_step;               	//下一步骤	引导完成后触发下一引导的id  如果不填，表示该引导没有下一步，完成后该引导内容结束
	int tutor_type;              	//引导类型	根据枚举确认引导类型 0.强制引导； 1.非强制引导-文本提示； 2.非强制引导-按钮闪烁
	int is_key_step;             	//是否是关键步骤	如果为1,则为代表这个步骤完成则本条引导完成
	string prefab;               	//界面资源名称	对应该引导需要影响到的界面
	vector<string> resource;     	//资源名称	填入资源对应的名字 对应界面 界面中的原件名称 如果是List中的资源,则listview的名字|cell的index|cell中的按钮的名称
	int show_all_btn;            	//是否显示全部按钮	0 - 隐藏 1 - 显示
	int action_type;             	//响应条件	强制引导响应玩家的方式 1.点击按钮；（点击对应按钮的功能后该引导结束） 2.点击指定区域；（点击对应区域，不触发该页面的按钮功能该引导结束） 3.点击任意区域；（点击任意区域，不触发该页面的按钮功能该引导结束）  非强制引导都是点击按钮
	int zone_shape;              	//指引区形状	该指引区显示时的形状 0.圆形 1.矩形
	vector<float> zone_pos;      	//指定区域位置	x|y  以屏幕中心为0|0点计算
	vector<float> zone_scale;    	//指引区缩放	百分比 宽度|高度 1=100%  不填代表 1|1  action_type不为1的话,代表像素大小
	int zone_focus;              	//是否聚焦	0.无聚焦 1.有聚焦效果
	float zone_delay;            	//指引区延迟显示时间	
	int text_type;               	//指引文本类型	强制引导枚举如下 1：附带讲解员图片 2：不附带讲解员图片 3：绑定按钮  非强制引导都是绑定按钮
	int text_position;           	//文字位置	文字位置根据指引类型不同而有不同的含义 text_type为1时  1：界面左侧  2：界面右侧 text_type为2时 由1-9决定文字在界面中的位置 963 852 741 text_type为3时 由1-4决定文字相对于按钮的位置    1                     2    △                     △   ┌────────┐     │要显示的文字│   └────────┘     ▽                     ▽       3                     4
	vector<int> text_offset;     	//文本框偏移量	数组，对应像素（需自适应） 横向偏移量|纵向偏移量 
	int text_string;             	//指引文本	对应StringGuide表中的id

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
	FunctionTutorialElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//功能引导表配置封装类
class FunctionTutorialTable
{
	friend class TableData;
private:
	FunctionTutorialTable(){}
	~FunctionTutorialTable(){}
	map<int, FunctionTutorialElement>	m_mapElements;
	vector<FunctionTutorialElement>	m_vecAllElements;
	FunctionTutorialElement m_emptyItem;
public:
	static FunctionTutorialTable& Instance()
	{
		static FunctionTutorialTable sInstance;
		return sInstance;
	}

	FunctionTutorialElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<FunctionTutorialElement>&	GetAllElement()
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
		if( LoadConfigContent("FunctionTutorial.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("FunctionTutorial.bin", strTableContent ) )
		{
			printf_message("配置文件[FunctionTutorial.bin]未找到");
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
		if(vecLine.size() != 23)
		{
			printf_message("FunctionTutorial.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("FunctionTutorial.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("FunctionTutorial.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="is_on"){printf_message("FunctionTutorial.csv中字段[is_on]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="function_id"){printf_message("FunctionTutorial.csv中字段[function_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="index"){printf_message("FunctionTutorial.csv中字段[index]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="trigger_type"){printf_message("FunctionTutorial.csv中字段[trigger_type]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="trigger_param"){printf_message("FunctionTutorial.csv中字段[trigger_param]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="next_step"){printf_message("FunctionTutorial.csv中字段[next_step]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="tutor_type"){printf_message("FunctionTutorial.csv中字段[tutor_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="is_key_step"){printf_message("FunctionTutorial.csv中字段[is_key_step]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="prefab"){printf_message("FunctionTutorial.csv中字段[prefab]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="resource"){printf_message("FunctionTutorial.csv中字段[resource]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="show_all_btn"){printf_message("FunctionTutorial.csv中字段[show_all_btn]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="action_type"){printf_message("FunctionTutorial.csv中字段[action_type]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="zone_shape"){printf_message("FunctionTutorial.csv中字段[zone_shape]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="zone_pos"){printf_message("FunctionTutorial.csv中字段[zone_pos]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="zone_scale"){printf_message("FunctionTutorial.csv中字段[zone_scale]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="zone_focus"){printf_message("FunctionTutorial.csv中字段[zone_focus]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="zone_delay"){printf_message("FunctionTutorial.csv中字段[zone_delay]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="text_type"){printf_message("FunctionTutorial.csv中字段[text_type]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="text_position"){printf_message("FunctionTutorial.csv中字段[text_position]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="text_offset"){printf_message("FunctionTutorial.csv中字段[text_offset]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="text_string"){printf_message("FunctionTutorial.csv中字段[text_string]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)23)
			{
				assert(false);
				return false;
			}
			FunctionTutorialElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.is_on=(int)atoi(vecLine[2].c_str());
			member.function_id=(int)atoi(vecLine[3].c_str());
			member.index=(int)atoi(vecLine[4].c_str());
			member.trigger_type=(int)atoi(vecLine[5].c_str());
			member.trigger_param=(int)atoi(vecLine[6].c_str());
			member.next_step=(int)atoi(vecLine[7].c_str());
			member.tutor_type=(int)atoi(vecLine[8].c_str());
			member.is_key_step=(int)atoi(vecLine[9].c_str());
			member.prefab=vecLine[10];
			member.show_all_btn=(int)atoi(vecLine[12].c_str());
			member.action_type=(int)atoi(vecLine[13].c_str());
			member.zone_shape=(int)atoi(vecLine[14].c_str());
			member.zone_focus=(int)atoi(vecLine[17].c_str());
			member.zone_delay=(float)atof(vecLine[18].c_str());
			member.text_type=(int)atoi(vecLine[19].c_str());
			member.text_position=(int)atoi(vecLine[20].c_str());
			member.text_string=(int)atoi(vecLine[22].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
