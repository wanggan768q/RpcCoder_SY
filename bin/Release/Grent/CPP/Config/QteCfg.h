#ifndef __QTE_CONFIG_H
#define __QTE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//快速反应事件表配置数据结构
struct QteElement
{
	friend class QteTable;
	int id;                      	//数据索引	1：测试 5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：帕尔派岛 15：科尔努斯 
	string comment;              	//任务备注	仅策划用
	int duration;                	//事件时长	规定qte的持续时间，单位为毫秒
	int qte_type;                	//qte类型	1：单次点击类型 2：连续点击类型 3：hold点击类型 4：拼图型 5：刷卡型 6：旋转型 7: 涂抹型
	int qteui_id;                	//qte界面表ID	
	vector<int> start_pos;       	//qte起始位置	x|y,以屏幕中心点为0，0点，正上方为y轴正方向计算
	int deviation_value;         	//qte起始点的偏差值	允许偏差的范围 以点击的位置为中心，半径为该字段值的圆形区域
	int click_counts;            	//连点次数	当qte_type为2时，该字段规定连续点击的次数
	int click_up_factor;         	//连点上升系数	达到目标APM,水银柱条每秒增加该字段点数,,水银柱条最大值100
	int click_down_factor;       	//连点下降系数	未达到目标APM,水银柱条每秒减少该字段点数,下降系数不可大于上升系数
	int click_hold_time;         	//按住时间	当qte_type为3时，该字段规定点击至少需要的时间。只要时间到达，即算成功（跟抬手时机无关），单位为毫秒。填写0代表该字段不生效
	int swap_target_angle;       	//刷卡方向角度	以起始位置为中心，正上方为y轴正方向做计算的刷卡方向角度
	int swap_target_deviation;   	//刷卡方向偏差值	允许偏差的范围 以起始的位置为中心，偏转角度（绝对值） 最大为180，代表无方向规定
	int swap_distance;           	//刷卡的距离	大于该距离算成功，单位为像素
	vector<int> puzzle_orignal_size;	//起始位置的宽高	宽高为像素
	vector<int> puzzle_target_size;	//目标位置的坐标和宽高	以屏幕正中为0，0 宽高为像素
	int puzzle_target_deviation; 	//目标位置的偏差值	允许偏差的范围 以目标的位置为中心，半径为该字段值的圆形区域
	int puzzle_name;             	//拼图碎片的资源名	由美术提供的资源名
	int rotate_type;             	//旋转类型	1为顺时针，2为逆时针
	int rotate_max_range;        	//点击和旋转时检测的最大半径	起始位置为中心，允许产生的最大偏差值
	int rotate_min_range;        	//点击和旋转时检测的最小半径	起始位置为中心，允许产生的最小偏差值
	int rotate_angle;            	//旋转角度	所旋转的角度，超过了该角度即视为成功，与抬手时机无关
	int wipep_length;            	//涂抹长度	在屏幕上涂抹的长度,单位:像素

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
	QteElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//快速反应事件表配置封装类
class QteTable
{
	friend class TableData;
private:
	QteTable(){}
	~QteTable(){}
	map<int, QteElement>	m_mapElements;
	vector<QteElement>	m_vecAllElements;
	QteElement m_emptyItem;
public:
	static QteTable& Instance()
	{
		static QteTable sInstance;
		return sInstance;
	}

	QteElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QteElement>&	GetAllElement()
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
		if( LoadConfigContent("Qte.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Qte.bin", strTableContent ) )
		{
			printf_message("配置文件[Qte.bin]未找到");
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
			printf_message("Qte.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Qte.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Qte.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="duration"){printf_message("Qte.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="qte_type"){printf_message("Qte.csv中字段[qte_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="qteui_id"){printf_message("Qte.csv中字段[qteui_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="start_pos"){printf_message("Qte.csv中字段[start_pos]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="deviation_value"){printf_message("Qte.csv中字段[deviation_value]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="click_counts"){printf_message("Qte.csv中字段[click_counts]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="click_up_factor"){printf_message("Qte.csv中字段[click_up_factor]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="click_down_factor"){printf_message("Qte.csv中字段[click_down_factor]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="click_hold_time"){printf_message("Qte.csv中字段[click_hold_time]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="swap_target_angle"){printf_message("Qte.csv中字段[swap_target_angle]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="swap_target_deviation"){printf_message("Qte.csv中字段[swap_target_deviation]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="swap_distance"){printf_message("Qte.csv中字段[swap_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="puzzle_orignal_size"){printf_message("Qte.csv中字段[puzzle_orignal_size]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="puzzle_target_size"){printf_message("Qte.csv中字段[puzzle_target_size]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="puzzle_target_deviation"){printf_message("Qte.csv中字段[puzzle_target_deviation]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="puzzle_name"){printf_message("Qte.csv中字段[puzzle_name]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="rotate_type"){printf_message("Qte.csv中字段[rotate_type]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="rotate_max_range"){printf_message("Qte.csv中字段[rotate_max_range]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="rotate_min_range"){printf_message("Qte.csv中字段[rotate_min_range]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="rotate_angle"){printf_message("Qte.csv中字段[rotate_angle]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="wipep_length"){printf_message("Qte.csv中字段[wipep_length]位置不对应 ");assert(false); return false; }

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
			QteElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.duration=(int)atoi(vecLine[2].c_str());
			member.qte_type=(int)atoi(vecLine[3].c_str());
			member.qteui_id=(int)atoi(vecLine[4].c_str());
			member.deviation_value=(int)atoi(vecLine[6].c_str());
			member.click_counts=(int)atoi(vecLine[7].c_str());
			member.click_up_factor=(int)atoi(vecLine[8].c_str());
			member.click_down_factor=(int)atoi(vecLine[9].c_str());
			member.click_hold_time=(int)atoi(vecLine[10].c_str());
			member.swap_target_angle=(int)atoi(vecLine[11].c_str());
			member.swap_target_deviation=(int)atoi(vecLine[12].c_str());
			member.swap_distance=(int)atoi(vecLine[13].c_str());
			member.puzzle_target_deviation=(int)atoi(vecLine[16].c_str());
			member.puzzle_name=(int)atoi(vecLine[17].c_str());
			member.rotate_type=(int)atoi(vecLine[18].c_str());
			member.rotate_max_range=(int)atoi(vecLine[19].c_str());
			member.rotate_min_range=(int)atoi(vecLine[20].c_str());
			member.rotate_angle=(int)atoi(vecLine[21].c_str());
			member.wipep_length=(int)atoi(vecLine[22].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
