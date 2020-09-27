#ifndef __VALUE_CONFIG_H
#define __VALUE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//参数配置数据结构
struct ValueElement
{
	friend class ValueTable;
	int id;                      	//序号	序号
	int value;                   	//值	值
	string comment;              	//描述	描述

private:

public:

	ValueElement()
	{
		id = -1;

	}
};

//参数配置封装类
class ValueTable
{
	public:
	typedef std::unique_ptr<ValueElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	ValueTable();
	~ValueTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static ValueTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const ValueElement* GetElement(int key);

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
