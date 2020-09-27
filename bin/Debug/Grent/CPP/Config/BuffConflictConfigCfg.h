#ifndef __BUFFCONFLICTCONFIG_CONFIG_H
#define __BUFFCONFLICTCONFIG_CONFIG_H

#include "BaseDef.h"



using namespace std;

//Buff组关系配置数据结构
struct BuffConflictConfigElement
{
	friend class BuffConflictConfigTable;
	int id;                      	//组id	组id 必须保证ID 是顺序的
	string desc;                 	//组名	仅策划用 矩阵行表示已存在buff 矩阵列表示新加buff
	string group;                	//组标识	1=冲抵, 2=免疫, 3=共存
	int g1;                      	//驱散	驱散
	int g2;                      	//净化	净化
	int g3;                      	//嘲讽	嘲讽
	int g4;                      	//嘲讽	嘲讽
	int g5;                      	//可驱散晕眩	可驱散晕眩
	int g6;                      	//可驱散冰冻	可驱散冰冻
	int g7;                      	//可驱散沉默	可驱散沉默
	int g8;                      	//可驱散加速	可驱散加速
	int g9;                      	//可驱散减速	可驱散减速
	int g10;                     	//可驱散定身	可驱散定身
	int g11;                     	//可驱散吸血	可驱散吸血
	int g12;                     	//可驱散增加属性Buff	可驱散增加属性Buff
	int g13;                     	//可驱散减少属性Buff	可驱散减少属性Buff
	int g14;                     	//可驱散回血	可驱散回血
	int g15;                     	//可驱散吸收盾	可驱散吸收盾
	int g16;                     	//可驱散流血	可驱散扣血
	int g17;                     	//可驱散中毒	可驱散中毒
	int g18;                     	//可驱散灼烧	可驱散灼烧
	int g19;                     	//可驱散禁疗	可驱散禁疗
	int g20;                     	//Boss霸体	Boss霸体
	int g21;                     	//精英霸体	精英霸体
	int g22;                     	//精英可被打断（免击退）	精英可被打断（免击退）
	int g23;                     	//免疫	免疫
	int g24;                     	//无敌	无敌
	int g25;                     	//诅咒	诅咒
	int g26;                     	//免疫嘲讽	免疫嘲讽
	int g27;                     	//主角职业被动Buff1	主角职业被动Buff1
	int g28;                     	//主角职业被动Buff2	主角职业被动Buff2
	int g29;                     	//主角职业被动Buff3	主角职业被动Buff3
	int g30;                     	//弓手雷电祝福	弓手雷电祝福
	int g31;                     	//弓手自然祝福	弓手自然祝福
	int g32;                     	//弓手寒冰祝福	弓手寒冰祝福
	int g33;                     	//弓手飓风祝福	弓手飓风祝福
	int g34;                     	//幽灵狼消耗祝福	幽灵狼消耗祝福
	int g35;                     	//临时霸体	临时霸体
	int g36;                     	//临时击飞、拉拽	临时击飞、拉拽
	int g37;                     	//击退	击退
	int g38;                     	//不可驱散晕眩	不可驱散晕眩
	int g39;                     	//不可驱散冰冻	不可驱散冰冻
	int g40;                     	//不可驱散沉默	不可驱散沉默
	int g41;                     	//不可驱散加速	不可驱散加速
	int g42;                     	//不可驱散减速	不可驱散减速
	int g43;                     	//不可驱散定身	不可驱散定身
	int g44;                     	//不可驱散吸血	不可驱散吸血
	vector<int> allgroup;        	//合并	公式不要手填！！！

private:

public:

	BuffConflictConfigElement()
	{
		id = -1;

	}
};

//Buff组关系配置封装类
class BuffConflictConfigTable
{
	public:
	typedef std::unique_ptr<BuffConflictConfigElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	BuffConflictConfigTable();
	~BuffConflictConfigTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static BuffConflictConfigTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const BuffConflictConfigElement* GetElement(int key);

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
