#ifndef __LEADERBOARDINDEX_CONFIG_H
#define __LEADERBOARDINDEX_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//排行榜索引表配置数据结构
struct LeaderBoardIndexElement
{
	friend class LeaderBoardIndexTable;
	int id;                      	//分类id	对应到指定的分类ID
	string comment;              	//注释	策划用
	int list_id;                 	//所属榜单	该分类所属的榜单ID 排行榜id
	int index;                   	//服务器索引	对应的索引值
	int sort_name;               	//分类名称	对应string_ui表的ID
	int reward_judgment;         	//是否有奖励	0：没有奖励 1：有奖励
	int point_information;       	//提示信息	0：没有提示信息 或文本表id
	vector<int> reward_information1;	//奖励信息1	奖励道具|数量
	vector<int> reward_information2;	//奖励信息2	奖励道具|数量
	vector<int> reward_information3;	//奖励信息3	奖励道具|数量
	vector<int> reward_information4;	//奖励信息4	奖励道具|数量

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
	LeaderBoardIndexElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//排行榜索引表配置封装类
class LeaderBoardIndexTable
{
	friend class TableData;
private:
	LeaderBoardIndexTable(){}
	~LeaderBoardIndexTable(){}
	map<int, LeaderBoardIndexElement>	m_mapElements;
	vector<LeaderBoardIndexElement>	m_vecAllElements;
	LeaderBoardIndexElement m_emptyItem;
public:
	static LeaderBoardIndexTable& Instance()
	{
		static LeaderBoardIndexTable sInstance;
		return sInstance;
	}

	LeaderBoardIndexElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<LeaderBoardIndexElement>&	GetAllElement()
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
		if( LoadConfigContent("LeaderBoardIndex.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("LeaderBoardIndex.bin", strTableContent ) )
		{
			printf_message("配置文件[LeaderBoardIndex.bin]未找到");
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
		if(vecLine.size() != 11)
		{
			printf_message("LeaderBoardIndex.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("LeaderBoardIndex.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("LeaderBoardIndex.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="list_id"){printf_message("LeaderBoardIndex.csv中字段[list_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="index"){printf_message("LeaderBoardIndex.csv中字段[index]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="sort_name"){printf_message("LeaderBoardIndex.csv中字段[sort_name]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="reward_judgment"){printf_message("LeaderBoardIndex.csv中字段[reward_judgment]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="point_information"){printf_message("LeaderBoardIndex.csv中字段[point_information]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="reward_information1"){printf_message("LeaderBoardIndex.csv中字段[reward_information1]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="reward_information2"){printf_message("LeaderBoardIndex.csv中字段[reward_information2]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="reward_information3"){printf_message("LeaderBoardIndex.csv中字段[reward_information3]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="reward_information4"){printf_message("LeaderBoardIndex.csv中字段[reward_information4]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)11)
			{
				assert(false);
				return false;
			}
			LeaderBoardIndexElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.list_id=(int)atoi(vecLine[2].c_str());
			member.index=(int)atoi(vecLine[3].c_str());
			member.sort_name=(int)atoi(vecLine[4].c_str());
			member.reward_judgment=(int)atoi(vecLine[5].c_str());
			member.point_information=(int)atoi(vecLine[6].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
