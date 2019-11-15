#ifndef __$TEMPLATE$_CONFIG_H
#define __$TEMPLATE$_CONFIG_H

#include "BaseDef.h"



using namespace std;

//$CNName$配置数据结构
struct $Template$Element
{
	friend class $Template$Table;
$FieldDefine$
private:

public:

	$Template$Element()
	{
		$InitPrimaryField$

	}
};

//$CNName$配置封装类
class $Template$Table
{
	public:
	typedef std::unique_ptr<$Template$Element> ele_ptr_type;
	typedef std::unordered_map<$PrimaryType$, ele_ptr_type> MapElementMap;
	typedef vector<$PrimaryType$> vec_type;
	//typedef std::set<$PrimaryType$> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	$Template$Table();
	~$Template$Table();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static $Template$Table& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const $Template$Element* GetElement($PrimaryType$ key);

	bool HasElement($PrimaryType$ key);

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

};

#endif
