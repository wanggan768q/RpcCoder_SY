#ifndef __EVENTOBJ_CONFIG_H
#define __EVENTOBJ_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//场景obj配置数据结构
struct EventObjElement
{
	friend class EventObjTable;
	int id;                      	//序号	OBJ表主键序号
	string comment;              	//备注	备注（仅策划用）
	int name;                    	//名称	调用StringCreature表的对应数据
	int quest_id;                	//任务id	有此任务才能交互
	int quest_step;              	//任务步骤	所在任务中的步骤
	int model_id;                	//模型路径	OBJ模型路径
	float leisure_pro;           	//播放休闲动画几率	1=100%
	int belong_type;             	//归属情况	0为所有玩家 1为当前玩家 2为当前队伍 3为当前团队 4为当前公会 5为当前阵营
	int state_type;              	//OBJ状态	0为出生状态，1为交互状态，2为交互完毕，3为消失时
	string icon_path;            	//交互图标路径	2D资源路径
	int popup_id;                	//气泡框id	该OBJ交互时弹出的气泡框
	string head_icon_path;       	//头标路径	头标路径
	string minimap_display_icon; 	//雷达图标	在雷达地图中显示的图标路径
	int allow_multi_player;      	//多玩家交互	1为是，0为否
	int interact_skill_id;       	//技能	交互时播放的技能
	vector<int> loot_list;       	//掉落物品id	互动后掉落物品id集合 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量
	int is_vanish;               	//自动消失	该交互后是否自动消失 1为是 0为否
	int vanish_time;             	//消失时间	交互后消失时间 (单位s）
	vector<string> buff_id_list; 	//该OBJ在交互后给玩家套上的buff id集合	该OBJ在交互后给玩家套上的buff id集合
	int obj_type;                	//OBJ类型	0 可交互非阻挡类 1 非交互可阻挡类 2 非交互非阻挡类      
	vector<int> obj_size;        	//OBJ大小	如果该obj为阻挡型obj，则在此规定他的 长度|高度|宽度      
	int qte_id;                  	//qte的id	0为无qte，关联qte表      
	string script_id;            	//obj脚本id	obj需要执行的脚本id
	int cg_id;                   	//交互后触发的cg	cg的id
	vector<int> CreatureHide_id; 	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	int auto_interact;           	//是否自动交互	0为不自动交互 1为可自动交互

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
	EventObjElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//场景obj配置封装类
class EventObjTable
{
	friend class TableData;
private:
	EventObjTable(){}
	~EventObjTable(){}
	map<int, EventObjElement>	m_mapElements;
	vector<EventObjElement>	m_vecAllElements;
	EventObjElement m_emptyItem;
public:
	static EventObjTable& Instance()
	{
		static EventObjTable sInstance;
		return sInstance;
	}

	EventObjElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<EventObjElement>&	GetAllElement()
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
		if( LoadConfigContent("EventObj.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("EventObj.bin", strTableContent ) )
		{
			printf_message("配置文件[EventObj.bin]未找到");
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
		if(vecLine.size() != 26)
		{
			printf_message("EventObj.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("EventObj.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("EventObj.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("EventObj.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="quest_id"){printf_message("EventObj.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="quest_step"){printf_message("EventObj.csv中字段[quest_step]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="model_id"){printf_message("EventObj.csv中字段[model_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="leisure_pro"){printf_message("EventObj.csv中字段[leisure_pro]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="belong_type"){printf_message("EventObj.csv中字段[belong_type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="state_type"){printf_message("EventObj.csv中字段[state_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="icon_path"){printf_message("EventObj.csv中字段[icon_path]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="popup_id"){printf_message("EventObj.csv中字段[popup_id]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="head_icon_path"){printf_message("EventObj.csv中字段[head_icon_path]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="minimap_display_icon"){printf_message("EventObj.csv中字段[minimap_display_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="allow_multi_player"){printf_message("EventObj.csv中字段[allow_multi_player]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="interact_skill_id"){printf_message("EventObj.csv中字段[interact_skill_id]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="loot_list"){printf_message("EventObj.csv中字段[loot_list]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="is_vanish"){printf_message("EventObj.csv中字段[is_vanish]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="vanish_time"){printf_message("EventObj.csv中字段[vanish_time]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="buff_id_list"){printf_message("EventObj.csv中字段[buff_id_list]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="obj_type"){printf_message("EventObj.csv中字段[obj_type]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="obj_size"){printf_message("EventObj.csv中字段[obj_size]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="qte_id"){printf_message("EventObj.csv中字段[qte_id]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="script_id"){printf_message("EventObj.csv中字段[script_id]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="cg_id"){printf_message("EventObj.csv中字段[cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="CreatureHide_id"){printf_message("EventObj.csv中字段[CreatureHide_id]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="auto_interact"){printf_message("EventObj.csv中字段[auto_interact]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)26)
			{
				assert(false);
				return false;
			}
			EventObjElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.quest_id=(int)atoi(vecLine[3].c_str());
			member.quest_step=(int)atoi(vecLine[4].c_str());
			member.model_id=(int)atoi(vecLine[5].c_str());
			member.leisure_pro=(float)atof(vecLine[6].c_str());
			member.belong_type=(int)atoi(vecLine[7].c_str());
			member.state_type=(int)atoi(vecLine[8].c_str());
			member.icon_path=vecLine[9];
			member.popup_id=(int)atoi(vecLine[10].c_str());
			member.head_icon_path=vecLine[11];
			member.minimap_display_icon=vecLine[12];
			member.allow_multi_player=(int)atoi(vecLine[13].c_str());
			member.interact_skill_id=(int)atoi(vecLine[14].c_str());
			member.is_vanish=(int)atoi(vecLine[16].c_str());
			member.vanish_time=(int)atoi(vecLine[17].c_str());
			member.obj_type=(int)atoi(vecLine[19].c_str());
			member.qte_id=(int)atoi(vecLine[21].c_str());
			member.script_id=vecLine[22];
			member.cg_id=(int)atoi(vecLine[23].c_str());
			member.auto_interact=(int)atoi(vecLine[25].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
