#ifndef __STRINGUI_CONFIG_H
#define __STRINGUI_CONFIG_H

#include "BaseDef.h"



using namespace std;

//界面文本表配置数据结构
struct StringUiElement
{
	friend class StringUiTable;
	int id;                      	//序号	数字编号
	string comment;              	//文本内容备注	文本内容备注
	string sc;                   	//简体中文	简体中文

private:

public:

	StringUiElement()
	{
		id = -1;

	}
};

//界面文本表配置封装类
class StringUiTable
{
	public:
	typedef std::unique_ptr<StringUiElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	StringUiTable();
	~StringUiTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static StringUiTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const StringUiElement* GetElement(int key);

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
