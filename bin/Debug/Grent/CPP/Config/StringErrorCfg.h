#ifndef __STRINGERROR_CONFIG_H
#define __STRINGERROR_CONFIG_H

#include "BaseDef.h"



using namespace std;

//错误码表配置数据结构
struct StringErrorElement
{
	friend class StringErrorTable;
	int id;                      	//序号	需要必须为负值
	int is_display;              	//是否显示	标示该错误码是否已文本提示框的形式显示在游戏中 0.不显示 1.显示
	string comment;              	//文本内容备注	文本内容备注
	string sc;                   	//简体中文	简体中文文本

private:

public:

	StringErrorElement()
	{
		id = -1;

	}
};

//错误码表配置封装类
class StringErrorTable
{
	public:
	typedef std::unique_ptr<StringErrorElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	StringErrorTable();
	~StringErrorTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static StringErrorTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const StringErrorElement* GetElement(int key);

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
