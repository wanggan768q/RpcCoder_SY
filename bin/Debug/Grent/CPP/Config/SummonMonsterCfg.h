#ifndef __SUMMONMONSTER_CONFIG_H
#define __SUMMONMONSTER_CONFIG_H

#include "BaseDef.h"



using namespace std;

//召唤小怪表配置数据结构
struct SummonMonsterElement
{
	friend class SummonMonsterTable;
	int id;                      	//同一个召唤组共享仇恨	同一个召唤组共享仇恨
	string comment;              	//策划备注	策划备注
	int type;                    	//类型，0固定位置，1随机，2召唤者位置偏移生成 ，3技能目标脚下生成	类型，0固定位置，1随机，2召唤者位置偏移生成
	int npc_entry_id;            	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	int num;                     	//数量	数量
	vector<int> pars;            	//参数，随机填半径，0原点 如果是召唤者位置偏移，填X|Z，一次召唤多个就顺序填，比如召唤2个，那么位置必须填成X1|Z1|X2|Z2	固定位置，路点id
	int dead_delete;             	//主人死亡是否删除，0不删除	主人死亡是否删除，0不删除
	int leave_fight_delete;      	//脱战是否删除，0不删除	脱战是否删除，0不删除
	int alive_time;              	//存活时间，-1无限，单位S	存活时间，-1无限，单位S
	int max_num;                 	//上限，达到上限不召唤	上限，达到上限不召唤
	int group_id;                	//给召唤ID分组，ID相同的为同组，同组内共享召唤上限，取组内召唤上限的最小值	给召唤ID分组，ID相同的为同组，同组内共享召唤上限，取组内召唤上限的最小值
	int follow_switch;           	//跟随切换地图，仅玩家角色召唤的怪物生效	0不跟随，1跟随

private:

public:

	SummonMonsterElement()
	{
		id = -1;

	}
};

//召唤小怪表配置封装类
class SummonMonsterTable
{
	public:
	typedef std::unique_ptr<SummonMonsterElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	SummonMonsterTable();
	~SummonMonsterTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static SummonMonsterTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const SummonMonsterElement* GetElement(int key);

	bool HasElement(int key);

	const vec_type& GetAllID() const;

	const MapElementMap& GetAllElement() const;
	bool Load();

	void NotifyCb();

	bool LoadJson(const std::string& jsonFile);


	bool ReLoad();
	

  int32_t min_table_id()const;
  int32_t max_table_id()const;
 private:
   int32_t min_table_id_{INT32_MAX};
   int32_t max_table_id_{INT32_MIN};
   bool m_bLoad{false};

};

#endif
