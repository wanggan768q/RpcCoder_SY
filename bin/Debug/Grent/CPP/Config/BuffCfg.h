#ifndef __BUFF_CONFIG_H
#define __BUFF_CONFIG_H

#include "BaseDef.h"



using namespace std;

//效果配置数据结构
struct BuffElement
{
	friend class BuffTable;
	int id;                      	//数据索引	数据索引
	int buffID;                  	//对应的BuffID	仅程序用
	string descPars;             	//参数说明	仅说明
	string desc_type;            	//Buff效果	仅程序用
	string comment;              	//备注	jius
	int on_phase;                	//生效阶段	指buff对应阶段逻辑是否生效，二进制标志位，可拓展，无特殊需求需填全部生效:7 1：buff开始时生效 2：buff每次在间隔时间生效 4：buff结束时生效 如：7 = 1 + 2 + 4，buff从开始到每跳到结束全上一次，
	int oper;                    	//Buff关系	0=叠加 1=冲抵 2=免疫 3=不同caster共存,相同caster叠加 4=不同caster免疫,相同caster叠加
	int operPars;                	//关系参数	若叠加类=最大叠加次数（最小层数是1）
	int overTimed;               	//是否持续Buff	0-非持续（BUFF会直接上身，1-持续（会走mutexID字段进行判断），若不需要判断BUFF组关系，在mutexID字段配置-1即可
	int continuance;             	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算 持续：-1，永久
	int interval;                	//间隔时间ms	间隔时间
	int mutexID;                 	//Buff组ID	-1表示跟谁都不是一组的
	int subMutexID;              	//副Buff组ID	当buff组ID一致，且组间关系是共存时，新旧buff判断该列的ID一致时，会按照该副buff组ID进行分组，按照优先级决定是否顶替，新buff优先级大于等于旧buff优先级时，才会顶替 平时无特殊需求的buff，该列填写-1
	vector<string> buffEffect;   	//buff特效	buff特效名称，多个数据用“|”连接，无数据保持空值
	vector<int> follow_rotation; 	//跟随旋转	数据对应buff特效的个数，特效是否跟随玩家旋转，若有多个特效资源，则用“|”连接 -1旋转 0不旋转
	vector<int> buffMount;       	//buff特效挂载点	无数据保持空值，数据数量需要和buff特效个数一致，多个数据用“|”连接 所有部位数字0-20 0：左脚 1：右脚 2：左手 3：右手 4：头 5：胸部受击点 18：世界脚 19：世界胸 20：世界头 99:UI特效专用
	vector<string> buffEndEffect;	//buff消失特效	buff消失特效名称，若有多个小时特效，则用“|”串联填写，无数据保持空值
	vector<int> buffEndMount;    	//buff消失特效挂载点	所有部位数字0-20，99位UI特效专用，消失特效的挂点个数需要和buff消失特效数量一致，无数据保持空值
	vector<int> buffEndEffectDuring;	//buff消失特效持续时间	buff消失时播放的特效持续的时间，单位：ms 数据个数需要和消失特效数量一致，无数据保持空值
	int groupPriority;           	//组中优先级	0为最低
	vector<float> pars;          	//参数	具体参数说明见文档《BUFF系统》
	vector<int> pars_2;          	//参数_2	特殊buff所需参数，可触发Buff的Buff类型ID
	vector<string> pars_3;       	//参数_3	特殊buff所需字符串类型参数，具体填写规则见《BUFF系统》
	int isDebuff;                	//是否减益	1：减益debuff 0：增益buff
	int buff_delete;             	//buff删除时机	0：不删除 1：下线删除 2：场景删除 4：死亡删除 8：怪回归删除（仅对怪有效）
	int displayPriority;         	//buff显示优先级	填写>=0整数，用于图标、特效等显示优先级，数字越大优先级越高
	int buffNameId;              	//buff名称ID	对应stringBuff表中的文本ID
	int specialBuffNameId;       	//计时buff简述特殊名称ID	对应stringBuff表中的文本ID
	int descId;                  	//buff描述ID	对应stringBuff表中的文本ID
	string iconName;             	//图标名称	图标名称
	int is_broadcast;            	//是否广播消息	0：否 1：是 是否需要将buff消息进行广播。 有特效需要让所有人看见的话，则填1，否则填0
	int is_tell_client;          	//是否告知客户端	0：否 1：是 需要显示受到图标、连击点、计时条等客户端需处理内容，则填1，否则填0（只修改属性，可填0）
	int buff_show_rule;          	//buff显示规则	0：全部不显示 1：闲置 2：显示图标 4：显示计时条（前提是显示图标） 8：自然使专用BUFF 16：显示冒字 32：隐藏图标处时间 如：14=图标、计时条、自然使专用buff均显示
	string script;               	//脚本路径	脚本路径
	int performance_buff_id;     	//链接技能表现	连接技能表现表，给buff宿主加效果
	int skill_slot_mod_id;       	//技能槽修改技能效果id	填写《SkillValueMod_技能数值成长表》中的ID
	int is_ignore_res;           	//是否忽略抗性属性计算	1：上buff时，忽略抗性属性计算 0：上buff时，先计算抗性属性 默认填0，当前已有抗性属性：眩晕、冰冻、击飞、定身、净化、驱散、沉默、打断、禁疗
	int is_visible;              	//是否可以忽略特效数量限制	0=不能 1=忽略数量限制，有就显示
	int quality;                 	//buff品质	爬塔buff选择时用，客户端显示，对应stringui表

private:

public:

	BuffElement()
	{
		id = -1;

	}
};

//效果配置封装类
class BuffTable
{
	public:
	typedef std::unique_ptr<BuffElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	BuffTable();
	~BuffTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static BuffTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const BuffElement* GetElement(int key);

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
