#ifndef __ITEMPROTO_CONFIG_H
#define __ITEMPROTO_CONFIG_H

#include "CommonDefine.h"
#include "DK_Assertx.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//道具原型配置数据结构
struct ItemProtoElement
{
	friend class ItemProtoTable;
	int id;                      	//道具ID	在中转中表示圣骑士所获得的道具id
	string comment;              	//道具注释	策划用
	int name;                    	//道具名称	文本id
	int description;             	//道具描述	文本id
	string icon;                 	//道具图标	资源路径
	int model;                   	//道具模型	资源路径
	int type;                    	//道具大类	1货币 2装备 3材料 4宝石 5一般用品 6药品 7礼包
	int subtype;                 	//道具子类	
	int level;                   	//道具等级	0表示无等级限制
	int rank;                    	//道具品质	0白 1绿 2蓝 3紫 4橙
	int price;                   	//系统回收价格	对应的银币价格
	int exchange_bottom;         	//交易最低价格	对应金币价格
	int exchange_init;           	//交易初始价格	对应金币价格
	int exchange_currency;       	//交易货币类型	0通用 1交易货币 2硬货币
	int occupation;              	//职业限制	二进制位运算转成的十进制数，从最高位到最低位对应 【战士】=32 【刺客】=16 【游侠】=8 【魔法师】=4 【圣骑士】=2 【神秘使】=1
	vector<int> transfer_id;     	//中转id	进行道具中专时 对应的道具 按照顺序代表【法师】【游侠】【神秘使】【战士】
	int stack;                   	//堆叠数量	1~65535
	int bind;                    	//绑定形式	0不绑定 1拾取绑定 2使用绑定
	int merge_item;              	//对应绑定道具	非绑定道具合并时转化为对应id的道具  0表示不会转化
	int pickup_type;             	//拾取形式	0常规拾取 1拾取后立刻使用 2拾取后弹出快捷使用界面 3拾取后归属于工会
	string item_effect;          	//物品效果	更新中 不填表示无法使用
	int required_scene;          	//使用需求场景	0无需求 1城镇 2野外 3副本
	int use_destory;             	//使用后销毁	0不销毁 1销毁
	int batch_use;               	//批量使用	0不可批量使用 1可批量使用 2可快速使用
	int use_when_dead;           	//死亡后使用	0不可以 1可以
	int timer_type;              	//使用后销毁	0不记时 1入手计时 2使用计时
	int life_time;               	//道具寿命	单位为分 如果可叠加则不生效
	int expire_time;             	//过期时间	填入时间 填0则表示没有过期时间
	int cross_scene_destory;     	//切换区域销毁	0不销毁 1销毁
	int store_type;              	//存储类型	0不存背包 1存通用背包
	int tag;                     	//背包标签	对于不存背包的道具无效
	int pickup_notice;           	//过期时间	0不公告 1公告

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
	typedef unordered_map<int, ItemProtoElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<ItemProtoElement>	m_vecAllElements;
	ItemProtoElement m_emptyItem;
public:
	static ItemProtoTable& Instance()
	{
		static ItemProtoTable sInstance;
		return sInstance;
	}

	const ItemProtoElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("ItemProtoTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
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
		#ifdef CONFIG_JSON
		return LoadJson("ItemProto.json");
		#else
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
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			ItemProtoElement	member;

						member.id=p.get<int>("id");
			member.comment=p.get<string>("comment");
			member.name=p.get<int>("name");
			member.description=p.get<int>("description");
			member.icon=p.get<string>("icon");
			member.model=p.get<int>("model");
			member.type=p.get<int>("type");
			member.subtype=p.get<int>("subtype");
			member.level=p.get<int>("level");
			member.rank=p.get<int>("rank");
			member.price=p.get<int>("price");
			member.exchange_bottom=p.get<int>("exchange_bottom");
			member.exchange_init=p.get<int>("exchange_init");
			member.exchange_currency=p.get<int>("exchange_currency");
			member.occupation=p.get<int>("occupation");
			boost::property_tree::ptree sms_array_childtransfer_id = p.get_child("transfer_id");
			for (BOOST_AUTO(pos, sms_array_childtransfer_id.begin()); pos != sms_array_childtransfer_id.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.transfer_id.push_back(n);
			}
			member.stack=p.get<int>("stack");
			member.bind=p.get<int>("bind");
			member.merge_item=p.get<int>("merge_item");
			member.pickup_type=p.get<int>("pickup_type");
			member.item_effect=p.get<string>("item_effect");
			member.required_scene=p.get<int>("required_scene");
			member.use_destory=p.get<int>("use_destory");
			member.batch_use=p.get<int>("batch_use");
			member.use_when_dead=p.get<int>("use_when_dead");
			member.timer_type=p.get<int>("timer_type");
			member.life_time=p.get<int>("life_time");
			member.expire_time=p.get<int>("expire_time");
			member.cross_scene_destory=p.get<int>("cross_scene_destory");
			member.store_type=p.get<int>("store_type");
			member.tag=p.get<int>("tag");
			member.pickup_notice=p.get<int>("pickup_notice");


			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}

		return true;
	}

	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 32)
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
		if(vecLine[8]!="level"){printf_message("ItemProto.csv中字段[level]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="rank"){printf_message("ItemProto.csv中字段[rank]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="price"){printf_message("ItemProto.csv中字段[price]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="exchange_bottom"){printf_message("ItemProto.csv中字段[exchange_bottom]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="exchange_init"){printf_message("ItemProto.csv中字段[exchange_init]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="exchange_currency"){printf_message("ItemProto.csv中字段[exchange_currency]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="occupation"){printf_message("ItemProto.csv中字段[occupation]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="transfer_id"){printf_message("ItemProto.csv中字段[transfer_id]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="stack"){printf_message("ItemProto.csv中字段[stack]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="bind"){printf_message("ItemProto.csv中字段[bind]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="merge_item"){printf_message("ItemProto.csv中字段[merge_item]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="pickup_type"){printf_message("ItemProto.csv中字段[pickup_type]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="item_effect"){printf_message("ItemProto.csv中字段[item_effect]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="required_scene"){printf_message("ItemProto.csv中字段[required_scene]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="use_destory"){printf_message("ItemProto.csv中字段[use_destory]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="batch_use"){printf_message("ItemProto.csv中字段[batch_use]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="use_when_dead"){printf_message("ItemProto.csv中字段[use_when_dead]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="timer_type"){printf_message("ItemProto.csv中字段[timer_type]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="life_time"){printf_message("ItemProto.csv中字段[life_time]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="expire_time"){printf_message("ItemProto.csv中字段[expire_time]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="cross_scene_destory"){printf_message("ItemProto.csv中字段[cross_scene_destory]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="store_type"){printf_message("ItemProto.csv中字段[store_type]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="tag"){printf_message("ItemProto.csv中字段[tag]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="pickup_notice"){printf_message("ItemProto.csv中字段[pickup_notice]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)32)
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
			member.level=(int)atoi(vecLine[8].c_str());
			member.rank=(int)atoi(vecLine[9].c_str());
			member.price=(int)atoi(vecLine[10].c_str());
			member.exchange_bottom=(int)atoi(vecLine[11].c_str());
			member.exchange_init=(int)atoi(vecLine[12].c_str());
			member.exchange_currency=(int)atoi(vecLine[13].c_str());
			member.occupation=(int)atoi(vecLine[14].c_str());
			member.stack=(int)atoi(vecLine[16].c_str());
			member.bind=(int)atoi(vecLine[17].c_str());
			member.merge_item=(int)atoi(vecLine[18].c_str());
			member.pickup_type=(int)atoi(vecLine[19].c_str());
			member.item_effect=vecLine[20];
			member.required_scene=(int)atoi(vecLine[21].c_str());
			member.use_destory=(int)atoi(vecLine[22].c_str());
			member.batch_use=(int)atoi(vecLine[23].c_str());
			member.use_when_dead=(int)atoi(vecLine[24].c_str());
			member.timer_type=(int)atoi(vecLine[25].c_str());
			member.life_time=(int)atoi(vecLine[26].c_str());
			member.expire_time=(int)atoi(vecLine[27].c_str());
			member.cross_scene_destory=(int)atoi(vecLine[28].c_str());
			member.store_type=(int)atoi(vecLine[29].c_str());
			member.tag=(int)atoi(vecLine[30].c_str());
			member.pickup_notice=(int)atoi(vecLine[31].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}

	vector<string> ReadCsvLine(string strContent,int contentOffset)
	{
		vector<string> temp;
		return temp;

	}
};

#endif
