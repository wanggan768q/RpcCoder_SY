#ifndef __QTEUI_CONFIG_H
#define __QTEUI_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//快速反应界面表配置数据结构
struct QteUiElement
{
	friend class QteUiTable;
	int id;                      	//数据索引	
	string comment;              	//任务备注	仅策划用
	int ui_display_type;         	//qte所使用的UI展现类型	1：雷达型 2：计量表型 3：旋转显示型 4：点击型 5: 涂抹型
	int delay_close_time;        	//qte成功后延迟多久关闭	单位为毫秒，0为立刻关闭 -1为不关闭（动画会循环播放）
	string main_ui;              	//主UI	QTE触发后所弹出的主UI：图片名称
	vector<string> ui_1;         	//第1个ui素材	QTE成功后，所展现的第一个ui素材
	vector<float> ui_1_location; 	//第1个ui的位置	以屏幕正中为0|0 尽量填整数
	int ui_1_value_1;            	//对应值1	
	int ui_1_value_2;            	//对应值2	
	vector<string> ui_2;         	//第2个ui素材	QTE成功后，所展现的第2个ui素材
	vector<float> ui_2_location; 	//第2个ui的位置	以屏幕正中为0|0
	int ui_2_value_1;            	//对应值1	
	vector<float> ui_2_value_2;  	//对应值2	
	vector<string> ui_3;         	//第3个ui素材	QTE成功后，所展现的第3个ui素材
	vector<float> ui_3_location; 	//第3个ui的位置	以屏幕正中为0|0
	int ui_3_value_1;            	//对应值1	
	int ui_3_value_2;            	//对应值2	
	string dialog_img;           	//对话框背景图	
	vector<float> dialog_position;	//对话框的位置	以屏幕正中为0|0
	int dialog_value_1;          	//对话内容	StringNotice的ID
	int dialog_value_2;          	//	暂时无用

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
	QteUiElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//快速反应界面表配置封装类
class QteUiTable
{
	friend class TableData;
private:
	QteUiTable(){}
	~QteUiTable(){}
	map<int, QteUiElement>	m_mapElements;
	vector<QteUiElement>	m_vecAllElements;
	QteUiElement m_emptyItem;
public:
	static QteUiTable& Instance()
	{
		static QteUiTable sInstance;
		return sInstance;
	}

	QteUiElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<QteUiElement>&	GetAllElement()
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
		if( LoadConfigContent("QteUi.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("QteUi.bin", strTableContent ) )
		{
			printf_message("配置文件[QteUi.bin]未找到");
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
		if(vecLine.size() != 21)
		{
			printf_message("QteUi.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("QteUi.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("QteUi.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="ui_display_type"){printf_message("QteUi.csv中字段[ui_display_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="delay_close_time"){printf_message("QteUi.csv中字段[delay_close_time]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="main_ui"){printf_message("QteUi.csv中字段[main_ui]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="ui_1"){printf_message("QteUi.csv中字段[ui_1]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="ui_1_location"){printf_message("QteUi.csv中字段[ui_1_location]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="ui_1_value_1"){printf_message("QteUi.csv中字段[ui_1_value_1]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="ui_1_value_2"){printf_message("QteUi.csv中字段[ui_1_value_2]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="ui_2"){printf_message("QteUi.csv中字段[ui_2]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="ui_2_location"){printf_message("QteUi.csv中字段[ui_2_location]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="ui_2_value_1"){printf_message("QteUi.csv中字段[ui_2_value_1]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="ui_2_value_2"){printf_message("QteUi.csv中字段[ui_2_value_2]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="ui_3"){printf_message("QteUi.csv中字段[ui_3]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="ui_3_location"){printf_message("QteUi.csv中字段[ui_3_location]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="ui_3_value_1"){printf_message("QteUi.csv中字段[ui_3_value_1]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="ui_3_value_2"){printf_message("QteUi.csv中字段[ui_3_value_2]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="dialog_img"){printf_message("QteUi.csv中字段[dialog_img]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="dialog_position"){printf_message("QteUi.csv中字段[dialog_position]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="dialog_value_1"){printf_message("QteUi.csv中字段[dialog_value_1]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="dialog_value_2"){printf_message("QteUi.csv中字段[dialog_value_2]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)21)
			{
				assert(false);
				return false;
			}
			QteUiElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.ui_display_type=(int)atoi(vecLine[2].c_str());
			member.delay_close_time=(int)atoi(vecLine[3].c_str());
			member.main_ui=vecLine[4];
			member.ui_1_value_1=(int)atoi(vecLine[7].c_str());
			member.ui_1_value_2=(int)atoi(vecLine[8].c_str());
			member.ui_2_value_1=(int)atoi(vecLine[11].c_str());
			member.ui_3_value_1=(int)atoi(vecLine[15].c_str());
			member.ui_3_value_2=(int)atoi(vecLine[16].c_str());
			member.dialog_img=vecLine[17];
			member.dialog_value_1=(int)atoi(vecLine[19].c_str());
			member.dialog_value_2=(int)atoi(vecLine[20].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
