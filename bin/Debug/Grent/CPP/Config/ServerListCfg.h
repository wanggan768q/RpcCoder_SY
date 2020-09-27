#ifndef __SERVERLIST_CONFIG_H
#define __SERVERLIST_CONFIG_H

#include "BaseDef.h"



using namespace std;

//服务器列表配置配置数据结构
struct ServerListElement
{
	friend class ServerListTable;
	int id;                      	//id	服务器的id
	string comment;              	//注释	
	int region;                  	//区域	该服务器处于哪个大区
	int name;                    	//名称	对应文本表中的id
	int status;                  	//状态	对应服务器的状态 0.正常 1.爆满
	int promo;                   	//推荐	该服务器是否为推荐服 0.不推荐 1.推荐
	string ip;                   	//服务器ip	该服务器的ip
	int port;                    	//端口	该服务器的端口

private:

public:

	ServerListElement()
	{
		id = -1;

	}
};

//服务器列表配置配置封装类
class ServerListTable
{
	public:
	typedef std::unique_ptr<ServerListElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	ServerListTable();
	~ServerListTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static ServerListTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const ServerListElement* GetElement(int key);

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
