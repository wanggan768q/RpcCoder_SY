#ifndef __GLOBAL_CONFIG_H
#define __GLOBAL_CONFIG_H

#include "BaseDef.h"



using namespace std;

//全局配置配置数据结构
struct GlobalElement
{
	friend class GlobalTable;
	int id;                      	//id	数据的id
	string comment;              	//注释	该数据的功能
	int int_value;               	//整型数据	整型数据
	float float_value;           	//浮点数据	浮点数据
	string string_value;         	//字符串数据	特效：资源名称
	vector<int> list_int_value;  	//数组整型数据	数组整型数据
	vector<float> list_float_value;	//数组浮点数据	数组浮点数据
	vector<string> list_string_value;	//数组字符串数据	数组字符串数据

private:

public:

	GlobalElement()
	{
		id = -1;

	}
};

//全局配置配置封装类
class GlobalTable
{
	public:
	typedef std::unique_ptr<GlobalElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	GlobalTable();
	~GlobalTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static GlobalTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const GlobalElement* GetElement(int key);

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
