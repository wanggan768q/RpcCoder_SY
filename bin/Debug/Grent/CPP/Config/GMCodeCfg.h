#ifndef __GMCODE_CONFIG_H
#define __GMCODE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//GM指令配置数据结构
struct GMCodeElement
{
	friend class GMCodeTable;
	int id;                      	//指令id	序号
	string  code;                	//指令名称	值 需要服务器处理的前缀为. 只需要客户端处理的前缀为/
	string name;                 	//中文名称	描述
	string desc;                 	//功能说明	策划使用
	int param1;                  	//指令参数1	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param2;                  	//指令参数2	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param3;                  	//指令参数3	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param4;                  	//指令参数4	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int code_catalog;            	//指令分类	0.未分类 1.角色 2.移动 3.战斗 4.其它
	string param_example;        	//参数解释	
	string param_desc;           	//参数说明	
	string comment;              	//其他信息	

private:

public:

	GMCodeElement()
	{
		id = -1;

	}
};

//GM指令配置封装类
class GMCodeTable
{
	public:
	typedef std::unique_ptr<GMCodeElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	GMCodeTable();
	~GMCodeTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static GMCodeTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const GMCodeElement* GetElement(int key);

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
