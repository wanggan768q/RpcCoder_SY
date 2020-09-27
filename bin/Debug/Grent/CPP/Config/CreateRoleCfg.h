#ifndef __CREATEROLE_CONFIG_H
#define __CREATEROLE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//角色配置数据结构
struct CreateRoleElement
{
	friend class CreateRoleTable;
	int id;                      	//id	id
	int race;                    	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	vector<int> sex;             	//可选性别	1:男性 2:女性
	int race_name;               	//种族名称	对应的名字的文本id
	int race_description;        	//种族介绍	对应介绍的文本id
	string race_icon;            	//种族图标	对应种族图标路径
	int desc_occupations;        	//可用职业介绍	对应可选职业介绍的文本id
	int default_gender;          	//默认性别	在玩家未选择性别时用于显示模型的字段
	int default_male_model;      	//默认显示男性模型	选择种族后显示的男性模型 萝莉族没有男性
	int default_female_model;    	//默认显示女性模型	选择种族后显示的女性模型 兽人族没有女性
	int default_male_id;         	//默认男性角色id	确定种族后默认选择的男性职业
	int default_female_id;       	//默认女性角色id	确定种族后默认选择的女性职业
	vector<int> male_role_id;    	//男性角色id1	如果没有男性则无用  对应该种族男性角色职业
	vector<int> female_role_id;  	//女性角色id1	如果没有女性则无用  对应该种族女性角色职业
	vector<string> create_occu_icon;	//创建界面图标	专门用在创建界面的 职业头像 对应未选中和选中两个状态
	vector<string> select_occu_icon;	//选择界面图标	专门用在选择界面的 职业标示 对应未选中和选中两个状态
	int role_id;                 	//新界面角色id	

private:

public:

	CreateRoleElement()
	{
		id = -1;

	}
};

//角色配置封装类
class CreateRoleTable
{
	public:
	typedef std::unique_ptr<CreateRoleElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CreateRoleTable();
	~CreateRoleTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CreateRoleTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CreateRoleElement* GetElement(int key);

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
