#ifndef __ITEMPROTO_CONFIG_H
#define __ITEMPROTO_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//道具原型配置数据结构
struct ItemProtoElement
{
	friend class ItemProtoTable;
	int id;                      	//道具ID	{equip(0)}_{class(0)}_{lv(000)}_{rank(0)}_{suit(0)}_{part(0)}:    equip-2,    class-0_物理;1_法术;2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼;8_模板    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    suit-0_非套装;1_1天赋;2_2天赋    part-1_武器;2_耳环;3_项链;4_戒指;5_帽子;6_盔甲;7_臂甲;8_腿甲    ”part(class=8)-0_装备;1_武器;2_饰品;3_防具
	string comment;              	//道具注释	策划用
	int name;                    	//道具名称	文本id
	int description;             	//道具描述	文本id
	string icon;                 	//道具图标	资源路径
	int model;                   	//道具模型	模型表ID
	int type;                    	//道具大类	见ItemType_道具类型
	int subtype;                 	//道具子类	见ItemType_道具类型
	int subtype_name;            	//子类名称	用于显示， 从StringItem表中获取
	int level;                   	//道具等级	0表示无等级限制
	int rank;                    	//道具品质	0白 1绿 2蓝 3紫 4橙 5红
	int marquee;                 	//获取跑马灯	0无跑马灯 1有跑马灯
	int price;                   	//系统回收价格	对应的银币价格
	int exchange_bottom;         	//交易最低价格	对应金币价格
	int exchange_init;           	//是否可交易	0：不可交易 1：可交易
	int exchange_currency;       	//交易货币类型	0通用 1交易货币 2硬货币
	vector<int> occupation;      	//职业限制	1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使
	vector<int> transfer_id;     	//中转id	进行道具中专时 对应的道具 按照顺序代表【战士】【刺客】【游侠】【法师】【圣骑士】【神秘使】
	int stack;                   	//堆叠数量	1~65535
	int bind;                    	//绑定形式	0拾取绑定 1存在多态的绑定形式 具体绑定形式由掉落决定
	int can_lock;                	//可上锁	0不可以 1可以上锁
	int pickup_type;             	//拾取形式	0常规拾取 1拾取后立刻使用 2拾取后弹出快捷使用界面 3拾取后归属于工会
	vector<int> item_effect;     	//物品效果	如果该字段有内容，表示点击使用按扭不会调用server_script  数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	string server_script_id;     	//物品效果	更新中 不填表示无法使用
	vector<float> effect_param;  	//效果参数	物品效果触发时所传入的参数，可以是多个数值
	int required_scene;          	//使用需求场景	0无需求 1城镇 2野外 3副本
	int use_destory;             	//使用后销毁	0不销毁 1销毁
	int global_cd;               	//全局CD	使用该道具产生的公共CD 单位为毫秒
	int group;                   	//道具组	用来判断公共CD或同类互斥功能
	int batch_use;               	//批量使用	0不可批量使用 1可批量使用
	int fast_use;                	//快速使用	道具是否会弹出快速使用弹窗 0.不会 1.会
	int use_when_dead;           	//死亡后使用	0不可以 1可以
	int timer_type;              	//计时器类型	0不记时 1入手计时 2使用计时
	int life_time;               	//道具寿命	单位为分 如果可叠加则不生效
	int expire_time;             	//过期时间	填入时间 填0则表示没有过期时间
	int cross_scene_destory;     	//切换区域销毁	0不销毁 1销毁
	int store_type;              	//存储类型	0不存背包 1存通用背包 2宠物背包
	int tag;                     	//背包标签	对于不存背包的道具无效
	int pickup_notice;           	//过期时间	0不公告 1公告
	int external_id;             	//外链id	如果是装备，则对应装备表的id 如果是宝石，则对应宝石表的id 如果是宠物，测对应宠物表的id 如果是宠物技能书，则对应宠物技能书表 等等…
	int can_mix;                 	//合成标签	0不可合成 或填写合成表中的 道具id 
	int can_break;               	//分解标签	0不可分解 1可分解
	vector<int> break_get;       	//分解获得道具	分解获得的道具id
	vector<int> break_count;     	//分解获得道具数量	分解获得的道具数量 需要和break_get对应
	int unlock_lv;               	//生活技能解锁等级	生活技能制作该道具所需生活技能等级，不填写或0则非生活技能道具
	int source_id;               	//来源表ID	对应道具来源表的id

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	ItemProtoElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//道具原型配置封装类
class ItemProtoTable
{
	friend class TableData;
private:
	ItemProtoTable(){}
	~ItemProtoTable(){}
	map<int, ItemProtoElement>	m_mapElements;
	vector<ItemProtoElement>	m_vecAllElements;
	ItemProtoElement m_emptyItem;
public:
	static ItemProtoTable& Instance()
	{
		static ItemProtoTable sInstance;
		return sInstance;
	}

	ItemProtoElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<ItemProtoElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("ItemProto.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("ItemProto.bin", strTableContent ) )
		{
			printf_message("配置文件[ItemProto.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 46)
		{
			printf_message("ItemProto.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("ItemProto.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("ItemProto.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("ItemProto.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="description"){printf_message("ItemProto.csv中字段[description]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="icon"){printf_message("ItemProto.csv中字段[icon]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="model"){printf_message("ItemProto.csv中字段[model]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="type"){printf_message("ItemProto.csv中字段[type]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="subtype"){printf_message("ItemProto.csv中字段[subtype]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="subtype_name"){printf_message("ItemProto.csv中字段[subtype_name]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="level"){printf_message("ItemProto.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="rank"){printf_message("ItemProto.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="marquee"){printf_message("ItemProto.csv中字段[marquee]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="price"){printf_message("ItemProto.csv中字段[price]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="exchange_bottom"){printf_message("ItemProto.csv中字段[exchange_bottom]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="exchange_init"){printf_message("ItemProto.csv中字段[exchange_init]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="exchange_currency"){printf_message("ItemProto.csv中字段[exchange_currency]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="occupation"){printf_message("ItemProto.csv中字段[occupation]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="transfer_id"){printf_message("ItemProto.csv中字段[transfer_id]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="stack"){printf_message("ItemProto.csv中字段[stack]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="bind"){printf_message("ItemProto.csv中字段[bind]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="can_lock"){printf_message("ItemProto.csv中字段[can_lock]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="pickup_type"){printf_message("ItemProto.csv中字段[pickup_type]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="item_effect"){printf_message("ItemProto.csv中字段[item_effect]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="server_script_id"){printf_message("ItemProto.csv中字段[server_script_id]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="effect_param"){printf_message("ItemProto.csv中字段[effect_param]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="required_scene"){printf_message("ItemProto.csv中字段[required_scene]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="use_destory"){printf_message("ItemProto.csv中字段[use_destory]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="global_cd"){printf_message("ItemProto.csv中字段[global_cd]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="group"){printf_message("ItemProto.csv中字段[group]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="batch_use"){printf_message("ItemProto.csv中字段[batch_use]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="fast_use"){printf_message("ItemProto.csv中字段[fast_use]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="use_when_dead"){printf_message("ItemProto.csv中字段[use_when_dead]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="timer_type"){printf_message("ItemProto.csv中字段[timer_type]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="life_time"){printf_message("ItemProto.csv中字段[life_time]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="expire_time"){printf_message("ItemProto.csv中字段[expire_time]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="cross_scene_destory"){printf_message("ItemProto.csv中字段[cross_scene_destory]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="store_type"){printf_message("ItemProto.csv中字段[store_type]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="tag"){printf_message("ItemProto.csv中字段[tag]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="pickup_notice"){printf_message("ItemProto.csv中字段[pickup_notice]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="external_id"){printf_message("ItemProto.csv中字段[external_id]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="can_mix"){printf_message("ItemProto.csv中字段[can_mix]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="can_break"){printf_message("ItemProto.csv中字段[can_break]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="break_get"){printf_message("ItemProto.csv中字段[break_get]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="break_count"){printf_message("ItemProto.csv中字段[break_count]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="unlock_lv"){printf_message("ItemProto.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="source_id"){printf_message("ItemProto.csv中字段[source_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)46)
			{
				assert(false);
				return false;
			}
			ItemProtoElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.description=(int)atoi(vecLine[3].c_str());
			member.icon=vecLine[4];
			member.model=(int)atoi(vecLine[5].c_str());
			member.type=(int)atoi(vecLine[6].c_str());
			member.subtype=(int)atoi(vecLine[7].c_str());
			member.subtype_name=(int)atoi(vecLine[8].c_str());
			member.level=(int)atoi(vecLine[9].c_str());
			member.rank=(int)atoi(vecLine[10].c_str());
			member.marquee=(int)atoi(vecLine[11].c_str());
			member.price=(int)atoi(vecLine[12].c_str());
			member.exchange_bottom=(int)atoi(vecLine[13].c_str());
			member.exchange_init=(int)atoi(vecLine[14].c_str());
			member.exchange_currency=(int)atoi(vecLine[15].c_str());
			member.stack=(int)atoi(vecLine[18].c_str());
			member.bind=(int)atoi(vecLine[19].c_str());
			member.can_lock=(int)atoi(vecLine[20].c_str());
			member.pickup_type=(int)atoi(vecLine[21].c_str());
			member.server_script_id=vecLine[23];
			member.required_scene=(int)atoi(vecLine[25].c_str());
			member.use_destory=(int)atoi(vecLine[26].c_str());
			member.global_cd=(int)atoi(vecLine[27].c_str());
			member.group=(int)atoi(vecLine[28].c_str());
			member.batch_use=(int)atoi(vecLine[29].c_str());
			member.fast_use=(int)atoi(vecLine[30].c_str());
			member.use_when_dead=(int)atoi(vecLine[31].c_str());
			member.timer_type=(int)atoi(vecLine[32].c_str());
			member.life_time=(int)atoi(vecLine[33].c_str());
			member.expire_time=(int)atoi(vecLine[34].c_str());
			member.cross_scene_destory=(int)atoi(vecLine[35].c_str());
			member.store_type=(int)atoi(vecLine[36].c_str());
			member.tag=(int)atoi(vecLine[37].c_str());
			member.pickup_notice=(int)atoi(vecLine[38].c_str());
			member.external_id=(int)atoi(vecLine[39].c_str());
			member.can_mix=(int)atoi(vecLine[40].c_str());
			member.can_break=(int)atoi(vecLine[41].c_str());
			member.unlock_lv=(int)atoi(vecLine[44].c_str());
			member.source_id=(int)atoi(vecLine[45].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
