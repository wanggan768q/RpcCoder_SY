#ifndef __CHATMENU_CONFIG_H
#define __CHATMENU_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//字幕框配置数据结构
struct ChatmenuElement
{
	friend class ChatmenuTable;
	int id;                      	//对话id	地图*10000 + 区域 * 1000 + 对话序号
	string comment;              	//注释	对话备注
	int chat_content_id;         	//字幕内容	关联string_chatmenu表
	int chat_next_id;            	//下一字幕框id	下一块chatmenu的id
	int chat_title_id;           	//分支选项标题id	分支选项标题id，对应任务文本表
	vector<int> branch_option;   	//对应字幕框的分支选项文本	无分支为，为数组型，格式为chat_id|chat_id
	vector<int> unlock_branch_option;	//解锁需求分支	默认为，格式为chat_id|chat_id
	int avatar_npc_id;           	//NPC影像id	0为玩家影像 否则为npcID影像
	int required_quest_id;       	//所需任务id	
	vector<int> event_list;      	//字幕结束后所触发的事件	格式为event_type|id event_type为1，代表传送 id为所需传送的路点id
	int vo_path;                 	//VO路径	
	int is_can_skip;             	//是否可以跳过剧情	1代表可以跳过 0代表不可跳过
	int animation_path;          	//播放的NPC或玩家动画	为-1表示循环播放idel动画
	int animation_type;          	//播放的动画是否循环	1代表循环 0代表只播放一次

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
	ChatmenuElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//字幕框配置封装类
class ChatmenuTable
{
	friend class TableData;
private:
	ChatmenuTable(){}
	~ChatmenuTable(){}
	map<int, ChatmenuElement>	m_mapElements;
	vector<ChatmenuElement>	m_vecAllElements;
	ChatmenuElement m_emptyItem;
public:
	static ChatmenuTable& Instance()
	{
		static ChatmenuTable sInstance;
		return sInstance;
	}

	ChatmenuElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ChatmenuElement>&	GetAllElement()
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
		if( LoadConfigContent("Chatmenu.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Chatmenu.bin", strTableContent ) )
		{
			printf_message("配置文件[Chatmenu.bin]未找到");
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
			printf_message("Chatmenu.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Chatmenu.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Chatmenu.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="chat_content_id"){printf_message("Chatmenu.csv中字段[chat_content_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="chat_next_id"){printf_message("Chatmenu.csv中字段[chat_next_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="chat_title_id"){printf_message("Chatmenu.csv中字段[chat_title_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="branch_option"){printf_message("Chatmenu.csv中字段[branch_option]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="unlock_branch_option"){printf_message("Chatmenu.csv中字段[unlock_branch_option]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="avatar_npc_id"){printf_message("Chatmenu.csv中字段[avatar_npc_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="required_quest_id"){printf_message("Chatmenu.csv中字段[required_quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="event_list"){printf_message("Chatmenu.csv中字段[event_list]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="vo_path"){printf_message("Chatmenu.csv中字段[vo_path]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="is_can_skip"){printf_message("Chatmenu.csv中字段[is_can_skip]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="animation_path"){printf_message("Chatmenu.csv中字段[animation_path]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="animation_type"){printf_message("Chatmenu.csv中字段[animation_type]位置不对应 ");assert(false); return false; }

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
			ChatmenuElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.chat_content_id=(int)atoi(vecLine[2].c_str());
			member.chat_next_id=(int)atoi(vecLine[3].c_str());
			member.chat_title_id=(int)atoi(vecLine[4].c_str());
			member.avatar_npc_id=(int)atoi(vecLine[7].c_str());
			member.required_quest_id=(int)atoi(vecLine[8].c_str());
			member.vo_path=(int)atoi(vecLine[10].c_str());
			member.is_can_skip=(int)atoi(vecLine[11].c_str());
			member.animation_path=(int)atoi(vecLine[12].c_str());
			member.animation_type=(int)atoi(vecLine[13].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
