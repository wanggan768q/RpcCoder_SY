#ifndef __SERVERSCRIPT_CONFIG_H
#define __SERVERSCRIPT_CONFIG_H

#include "BaseDef.h"



using namespace std;

//服务器脚本配置数据结构
struct ServerScriptElement
{
	friend class ServerScriptTable;
	int id;                      	//脚本id	脚本id
	string file;                 	//	

private:

public:

	ServerScriptElement()
	{
		id = -1;

	}
};

//服务器脚本配置封装类
class ServerScriptTable
{
	public:
	typedef std::unique_ptr<ServerScriptElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	ServerScriptTable();
	~ServerScriptTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static ServerScriptTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const ServerScriptElement* GetElement(int key);

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
