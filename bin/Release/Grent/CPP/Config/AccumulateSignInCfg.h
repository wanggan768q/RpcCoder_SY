#ifndef __ACCUMULATESIGNIN_CONFIG_H
#define __ACCUMULATESIGNIN_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//累计登陆奖励表配置数据结构
struct AccumulateSignInElement
{
	friend class AccumulateSignInTable;
	int id;                      	//序号	序号
	string comment;              	//备注	备注
	int required_signin;         	//需求累计登陆天数	
	int required_lv;             	//需求角色等级	
	string icon1;                	//奖励图	资源路径
	string icon2;                	//美术字	
	vector<int> signin_reward1_id;	//等级奖励1	道具ID|数量|是否需要中转
	vector<int> signin_reward2_id;	//等级奖励2	道具ID|数量|是否需要中转
	vector<int> signin_reward3_id;	//等级奖励3	道具ID|数量|是否需要中转
	vector<int> signin_reward4_id;	//等级奖励4	道具ID|数量|是否需要中转
	vector<int> resource_id;     	//3D模型展示	此处填模型配置表里的ID，时装只填不同职业的男性ID，女性ID=男性ID+100 从左往右的顺序为下方职业从上往下的顺序，刺客暂时没有就填0 1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士6：神秘使
	vector<float> scale;         	//3D模型缩放	X|Y|Z
	vector<float> position;      	//3D模型位置	X|Y|Z
	vector<float> rotation;      	//3D模型默认旋转	X|Y|Z

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
	AccumulateSignInElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//累计登陆奖励表配置封装类
class AccumulateSignInTable
{
	friend class TableData;
private:
	AccumulateSignInTable(){}
	~AccumulateSignInTable(){}
	map<int, AccumulateSignInElement>	m_mapElements;
	vector<AccumulateSignInElement>	m_vecAllElements;
	AccumulateSignInElement m_emptyItem;
public:
	static AccumulateSignInTable& Instance()
	{
		static AccumulateSignInTable sInstance;
		return sInstance;
	}

	AccumulateSignInElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AccumulateSignInElement>&	GetAllElement()
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
		if( LoadConfigContent("AccumulateSignIn.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("AccumulateSignIn.bin", strTableContent ) )
		{
			printf_message("配置文件[AccumulateSignIn.bin]未找到");
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
		if(vecLine.size() != 14)
		{
			printf_message("AccumulateSignIn.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("AccumulateSignIn.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("AccumulateSignIn.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="required_signin"){printf_message("AccumulateSignIn.csv中字段[required_signin]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="required_lv"){printf_message("AccumulateSignIn.csv中字段[required_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon1"){printf_message("AccumulateSignIn.csv中字段[icon1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="icon2"){printf_message("AccumulateSignIn.csv中字段[icon2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="signin_reward1_id"){printf_message("AccumulateSignIn.csv中字段[signin_reward1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="signin_reward2_id"){printf_message("AccumulateSignIn.csv中字段[signin_reward2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="signin_reward3_id"){printf_message("AccumulateSignIn.csv中字段[signin_reward3_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="signin_reward4_id"){printf_message("AccumulateSignIn.csv中字段[signin_reward4_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="resource_id"){printf_message("AccumulateSignIn.csv中字段[resource_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="scale"){printf_message("AccumulateSignIn.csv中字段[scale]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="position"){printf_message("AccumulateSignIn.csv中字段[position]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="rotation"){printf_message("AccumulateSignIn.csv中字段[rotation]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)14)
			{
				assert(false);
				return false;
			}
			AccumulateSignInElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.required_signin=(int)atoi(vecLine[2].c_str());
			member.required_lv=(int)atoi(vecLine[3].c_str());
			member.icon1=vecLine[4];
			member.icon2=vecLine[5];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
