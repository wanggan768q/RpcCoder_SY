#ifndef __MIRROR_CONFIG_H
#define __MIRROR_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//镜像表配置数据结构
struct MirrorElement
{
	friend class MirrorTable;
	int id;                      	//序号	5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：珀希洛斯岛 25：艾尔拉诺 26：燃烧沙漠 27：弗罗林王都
	string comment;              	//备注	备注
	int map_id;                  	//地图ID	该镜像所在的地图ID，程序在此与玩家实际所在的场景ID进行判断，如果不符，则无法创建镜像
	int trigger_type;            	//触发类型	1为路点，2为事件区域，3为脚本 后一个数字代表对应的ID，脚本的话填写0即可
	vector<int> trigger_list;    	//触发ID	前一列数字代表触发类型：1为路点id，2为事件区域id，3为脚本 后一个数字代表对应的ID，不用填
	vector<int> quest_id;        	//绑定任务id	所需的任务ID，只有当玩家拥有该任务以及符合下面的quest_step的条件时，该事件才会起作用。
	int quest_step;              	//任务状态	 1：为任务接受后，目标完成前可触发（任务表中的target相关列）；  2：任务目标完成后可触发  3：指定任务完成后可触发 
	int mirror_type;             	//镜像类型	1：单人镜像 2：组队镜像 3：世界镜像
	int cg_id;                   	//需要播放的cg动画	需要播放的cg动画
	string music;                	//所改变的背景音乐	所改变的背景音乐
	string script;               	//脚本路径	脚本路径
	int effect_type;             	//进入镜像时的特效标识	1：火焰 2：冰冻 3：水波纹 4：模糊（梦境） 
	int ending_boss_id;          	//结束bossID	该boss死亡后自动退出镜像
	int can_exit;                	//是否可以显示退出按钮	界面上是否会显示退出镜像的按钮 
	int Hunt_id;                 	//猎魔id	猎魔表
	vector<int> area_id;         	//区域id	区域Id
	int monster_delay;           	//刷怪延迟	创建n秒后进行刷怪  单位：秒
	int survival_tm;             	//存在时间	创建后镜像存在的时间  单位：秒

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
	MirrorElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//镜像表配置封装类
class MirrorTable
{
	friend class TableData;
private:
	MirrorTable(){}
	~MirrorTable(){}
	map<int, MirrorElement>	m_mapElements;
	vector<MirrorElement>	m_vecAllElements;
	MirrorElement m_emptyItem;
public:
	static MirrorTable& Instance()
	{
		static MirrorTable sInstance;
		return sInstance;
	}

	MirrorElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MirrorElement>&	GetAllElement()
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
		if( LoadConfigContent("Mirror.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Mirror.bin", strTableContent ) )
		{
			printf_message("配置文件[Mirror.bin]未找到");
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
		if(vecLine.size() != 18)
		{
			printf_message("Mirror.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Mirror.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Mirror.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="map_id"){printf_message("Mirror.csv中字段[map_id]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="trigger_type"){printf_message("Mirror.csv中字段[trigger_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="trigger_list"){printf_message("Mirror.csv中字段[trigger_list]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="quest_id"){printf_message("Mirror.csv中字段[quest_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="quest_step"){printf_message("Mirror.csv中字段[quest_step]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="mirror_type"){printf_message("Mirror.csv中字段[mirror_type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="cg_id"){printf_message("Mirror.csv中字段[cg_id]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="music"){printf_message("Mirror.csv中字段[music]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="script"){printf_message("Mirror.csv中字段[script]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="effect_type"){printf_message("Mirror.csv中字段[effect_type]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="ending_boss_id"){printf_message("Mirror.csv中字段[ending_boss_id]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="can_exit"){printf_message("Mirror.csv中字段[can_exit]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="Hunt_id"){printf_message("Mirror.csv中字段[Hunt_id]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="area_id"){printf_message("Mirror.csv中字段[area_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="monster_delay"){printf_message("Mirror.csv中字段[monster_delay]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="survival_tm"){printf_message("Mirror.csv中字段[survival_tm]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)18)
			{
				assert(false);
				return false;
			}
			MirrorElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.map_id=(int)atoi(vecLine[2].c_str());
			member.trigger_type=(int)atoi(vecLine[3].c_str());
			member.quest_step=(int)atoi(vecLine[6].c_str());
			member.mirror_type=(int)atoi(vecLine[7].c_str());
			member.cg_id=(int)atoi(vecLine[8].c_str());
			member.music=vecLine[9];
			member.script=vecLine[10];
			member.effect_type=(int)atoi(vecLine[11].c_str());
			member.ending_boss_id=(int)atoi(vecLine[12].c_str());
			member.can_exit=(int)atoi(vecLine[13].c_str());
			member.Hunt_id=(int)atoi(vecLine[14].c_str());
			member.monster_delay=(int)atoi(vecLine[16].c_str());
			member.survival_tm=(int)atoi(vecLine[17].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
