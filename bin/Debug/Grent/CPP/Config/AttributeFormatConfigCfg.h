#ifndef __ATTRIBUTEFORMATCONFIG_CONFIG_H
#define __ATTRIBUTEFORMATCONFIG_CONFIG_H

#include "BaseDef.h"



using namespace std;

//战斗属性配置数据结构
struct AttributeFormatConfigElement
{
	friend class AttributeFormatConfigTable;
	int id;                      	//ID	添加需要 通知程序
	string comment;              	//属性中文名	仅策划用
	int nameid;                  	//属性名称ID	属性名称ID
	int type;                    	//属性显示	0：显示数字 1：显示百分比
	string des;                  	//属性说明	仅策划用
	int desid;                   	//属性说明ID	属性说明ID
	vector<float> weight;        	//战力权重	战力=[计算单位|战力权重]
	string refine_name;          	//洗练名称	对应该属性在装备后缀表的字段名
	int attr_type;               	//属性类型	0.一级属性 1.二级属性 2.其他
	int attack_type;             	//属性的攻击类型	0.物理属性 1.魔法属性 2.通用
	int basic_display;           	//基础界面显示	0.不显示 >0.显示，并表示其优先级（数字大优先高） （同优先级按id顺序显示）
	int total_display;           	//完整界面显示	0.不显示 >0.显示，并表示其优先级（数字大优先高） （同优先级按id顺序显示）
	int total_category;          	//完整界面分类	对应AttributeCatagory表的某一条

private:

public:

	AttributeFormatConfigElement()
	{
		id = -1;

	}
};

//战斗属性配置封装类
class AttributeFormatConfigTable
{
	public:
	typedef std::unique_ptr<AttributeFormatConfigElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	AttributeFormatConfigTable();
	~AttributeFormatConfigTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static AttributeFormatConfigTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const AttributeFormatConfigElement* GetElement(int key);

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
