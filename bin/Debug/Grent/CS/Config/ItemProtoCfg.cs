using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//道具原型配置数据类
public class ItemProtoElement
{
	public int id;               	//道具ID	{equip(0)}_{class(0)}_{lv(000)}_{rank(0)}_{suit(0)}_{part(0)}:    equip-2,    class-0_物理;1_法术;2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼;8_模板    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    suit-0_非套装;1_1天赋;2_2天赋    part-1_武器;2_耳环;3_项链;4_戒指;5_帽子;6_盔甲;7_臂甲;8_腿甲    ”part(class=8)-0_装备;1_武器;2_饰品;3_防具
	public int name;             	//道具名称	文本id
	public int description;      	//道具描述	文本id
	public string icon;          	//道具图标	资源路径
	public int model;            	//道具模型	模型表ID
	public int type;             	//道具大类	见ItemType_道具类型
	public int subtype;          	//道具子类	见ItemType_道具类型
	public int subtype_name;     	//子类名称	用于显示， 从StringItem表中获取
	public int level;            	//道具等级	0表示无等级限制
	public int rank;             	//道具品质	0白 1绿 2蓝 3紫 4橙 5红
	public int marquee;          	//获取跑马灯	0无跑马灯 1有跑马灯
	public int time_remind;      	//队伍提醒	0无队伍提醒 1有队伍提醒
	public int price;            	//系统回收价格	对应的银币价格
	public int exchange_bottom;  	//交易最低价格	对应金币价格
	public int exchange_init;    	//是否可交易	0：不可交易 1：可交易
	public int exchange_currency;	//交易货币类型	0通用 1交易货币 2硬货币
	public li occupation;        	//职业限制	1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使
	public li transfer_id;       	//中转id	进行道具中专时 对应的道具 按照顺序代表【战士】【刺客】【游侠】【法师】【圣骑士】【神秘使】
	public int stack;            	//堆叠数量	1~65535
	public int bind;             	//绑定形式	0拾取绑定 1存在多态的绑定形式 具体绑定形式由掉落决定
	public int can_lock;         	//可上锁	0不可以 1可以上锁
	public int pickup_type;      	//拾取形式	0常规拾取 1拾取后立刻使用 2拾取后弹出快捷使用界面 3拾取后归属于工会
	public li item_effect;       	//物品使用效果	如果该字段有内容，表示点击使用按扭不会调用server_script  数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public string behaviac;      	//副本行为树	Config/behaviac/下的目录
	public string server_script_id;	//物品使用效果	更新中 不填表示无法使用
	public lf effect_param;      	//效果参数	物品效果触发时所传入的参数，可以是多个数值
	public int required_scene;   	//使用需求场景	0无需求 1城镇 2野外 3副本
	public int relations;        	//使用目标与玩家自己的敌我关系	0自身 1敌人 2友方
	public int target_type;      	//可使用的目标类型	0玩家 1NPC/怪物 2obj
	public int use_destory;      	//使用后销毁	0不销毁 1销毁
	public int global_cd;        	//全局CD	使用该道具产生的公共CD 单位为毫秒
	public int group;            	//道具组	用来判断公共CD或同类互斥功能
	public int batch_use;        	//批量使用	0不可批量使用 1可批量使用
	public int fast_use;         	//快速使用	道具是否会弹出快速使用弹窗 0.不会 1.会
	public int use_when_dead;    	//死亡后使用	0不可以 1可以
	public int timer_type;       	//计时器类型	0不记时 1入手计时 2使用计时
	public int life_time;        	//道具寿命	单位为分 如果可叠加则不生效
	public int expire_time;      	//过期时间	填入时间 填0则表示没有过期时间
	public int cross_scene_destory;	//切换区域销毁	0不销毁 1销毁
	public int store_type;       	//存储类型	0不存背包 1存通用背包 2宠物背包
	public int tag;              	//背包标签	对于不存背包的道具无效 1代表第二个页签；2代表第三个页签；3代表第四个页签
	public int pickup_notice;    	//过期时间	0不公告 1公告
	public int external_id;      	//外链id	如果是装备，则对应装备表的id 如果是宝石，则对应宝石表的id 如果是宠物，测对应宠物表的id 如果是宠物技能书，则对应宠物技能书表 等等…
	public int can_mix;          	//合成标签	0不可合成 或填写合成表中的 道具id 
	public int can_break;        	//分解标签	0不可分解 1可分解
	public li break_get;         	//分解获得道具	分解获得的道具id
	public li break_count;       	//分解获得道具数量	分解获得的道具数量 需要和break_get对应
	public int unlock_lv;        	//生活技能解锁等级	生活技能制作该道具所需生活技能等级，不填写或0则非生活技能道具
	public int source_id;        	//来源表ID	对应道具来源表的id
	public int cast_skill;       	//释放技能ID	释放技能ID
	public int bi_log;           	//BI打点用	填0或不填上报BI 填1不上报

	public bool IsValidate = false;
	public ItemProtoElement()
	{
		id = -1;
	}
};

//道具原型配置封装类
public class ItemProtoTable
{

	private ItemProtoTable()
	{
		m_mapElements = new Dictionary<int, ItemProtoElement>();
		m_emptyItem = new ItemProtoElement();
		m_vecAllElements = new List<ItemProtoElement>();
	}
	private Dictionary<int, ItemProtoElement> m_mapElements = null;
	private List<ItemProtoElement>	m_vecAllElements = null;
	private ItemProtoElement m_emptyItem = null;
	private static ItemProtoTable sInstance = null;

	public static ItemProtoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ItemProtoTable();
			return sInstance;
		}
	}

	public ItemProtoElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<ItemProtoElement> GetAllElement(Predicate<ItemProtoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ItemProto.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ItemProto.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ItemProto.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 51)
		{
			Ex.Logger.Log("ItemProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("ItemProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="description"){Ex.Logger.Log("ItemProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[3]!="icon"){Ex.Logger.Log("ItemProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[4]!="model"){Ex.Logger.Log("ItemProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("ItemProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="subtype"){Ex.Logger.Log("ItemProto.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[7]!="subtype_name"){Ex.Logger.Log("ItemProto.csv中字段[subtype_name]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("ItemProto.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("ItemProto.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="marquee"){Ex.Logger.Log("ItemProto.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[11]!="time_remind"){Ex.Logger.Log("ItemProto.csv中字段[time_remind]位置不对应"); return false; }
		if(vecLine[12]!="price"){Ex.Logger.Log("ItemProto.csv中字段[price]位置不对应"); return false; }
		if(vecLine[13]!="exchange_bottom"){Ex.Logger.Log("ItemProto.csv中字段[exchange_bottom]位置不对应"); return false; }
		if(vecLine[14]!="exchange_init"){Ex.Logger.Log("ItemProto.csv中字段[exchange_init]位置不对应"); return false; }
		if(vecLine[15]!="exchange_currency"){Ex.Logger.Log("ItemProto.csv中字段[exchange_currency]位置不对应"); return false; }
		if(vecLine[16]!="occupation"){Ex.Logger.Log("ItemProto.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[17]!="transfer_id"){Ex.Logger.Log("ItemProto.csv中字段[transfer_id]位置不对应"); return false; }
		if(vecLine[18]!="stack"){Ex.Logger.Log("ItemProto.csv中字段[stack]位置不对应"); return false; }
		if(vecLine[19]!="bind"){Ex.Logger.Log("ItemProto.csv中字段[bind]位置不对应"); return false; }
		if(vecLine[20]!="can_lock"){Ex.Logger.Log("ItemProto.csv中字段[can_lock]位置不对应"); return false; }
		if(vecLine[21]!="pickup_type"){Ex.Logger.Log("ItemProto.csv中字段[pickup_type]位置不对应"); return false; }
		if(vecLine[22]!="item_effect"){Ex.Logger.Log("ItemProto.csv中字段[item_effect]位置不对应"); return false; }
		if(vecLine[23]!="behaviac"){Ex.Logger.Log("ItemProto.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[24]!="server_script_id"){Ex.Logger.Log("ItemProto.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[25]!="effect_param"){Ex.Logger.Log("ItemProto.csv中字段[effect_param]位置不对应"); return false; }
		if(vecLine[26]!="required_scene"){Ex.Logger.Log("ItemProto.csv中字段[required_scene]位置不对应"); return false; }
		if(vecLine[27]!="relations"){Ex.Logger.Log("ItemProto.csv中字段[relations]位置不对应"); return false; }
		if(vecLine[28]!="target_type"){Ex.Logger.Log("ItemProto.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[29]!="use_destory"){Ex.Logger.Log("ItemProto.csv中字段[use_destory]位置不对应"); return false; }
		if(vecLine[30]!="global_cd"){Ex.Logger.Log("ItemProto.csv中字段[global_cd]位置不对应"); return false; }
		if(vecLine[31]!="group"){Ex.Logger.Log("ItemProto.csv中字段[group]位置不对应"); return false; }
		if(vecLine[32]!="batch_use"){Ex.Logger.Log("ItemProto.csv中字段[batch_use]位置不对应"); return false; }
		if(vecLine[33]!="fast_use"){Ex.Logger.Log("ItemProto.csv中字段[fast_use]位置不对应"); return false; }
		if(vecLine[34]!="use_when_dead"){Ex.Logger.Log("ItemProto.csv中字段[use_when_dead]位置不对应"); return false; }
		if(vecLine[35]!="timer_type"){Ex.Logger.Log("ItemProto.csv中字段[timer_type]位置不对应"); return false; }
		if(vecLine[36]!="life_time"){Ex.Logger.Log("ItemProto.csv中字段[life_time]位置不对应"); return false; }
		if(vecLine[37]!="expire_time"){Ex.Logger.Log("ItemProto.csv中字段[expire_time]位置不对应"); return false; }
		if(vecLine[38]!="cross_scene_destory"){Ex.Logger.Log("ItemProto.csv中字段[cross_scene_destory]位置不对应"); return false; }
		if(vecLine[39]!="store_type"){Ex.Logger.Log("ItemProto.csv中字段[store_type]位置不对应"); return false; }
		if(vecLine[40]!="tag"){Ex.Logger.Log("ItemProto.csv中字段[tag]位置不对应"); return false; }
		if(vecLine[41]!="pickup_notice"){Ex.Logger.Log("ItemProto.csv中字段[pickup_notice]位置不对应"); return false; }
		if(vecLine[42]!="external_id"){Ex.Logger.Log("ItemProto.csv中字段[external_id]位置不对应"); return false; }
		if(vecLine[43]!="can_mix"){Ex.Logger.Log("ItemProto.csv中字段[can_mix]位置不对应"); return false; }
		if(vecLine[44]!="can_break"){Ex.Logger.Log("ItemProto.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[45]!="break_get"){Ex.Logger.Log("ItemProto.csv中字段[break_get]位置不对应"); return false; }
		if(vecLine[46]!="break_count"){Ex.Logger.Log("ItemProto.csv中字段[break_count]位置不对应"); return false; }
		if(vecLine[47]!="unlock_lv"){Ex.Logger.Log("ItemProto.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[48]!="source_id"){Ex.Logger.Log("ItemProto.csv中字段[source_id]位置不对应"); return false; }
		if(vecLine[49]!="cast_skill"){Ex.Logger.Log("ItemProto.csv中字段[cast_skill]位置不对应"); return false; }
		if(vecLine[50]!="bi_log"){Ex.Logger.Log("ItemProto.csv中字段[bi_log]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ItemProtoElement member = new ItemProtoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.time_remind );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_bottom );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_init );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_currency );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occupation);
			readPos += GameAssist.ReadString( binContent, readPos, out member.transfer_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.bind );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_lock );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pickup_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_effect);
			readPos += GameAssist.ReadString( binContent, readPos, out member.behaviac);
			readPos += GameAssist.ReadString( binContent, readPos, out member.server_script_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.effect_param);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_scene );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.relations );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.use_destory );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.global_cd );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.batch_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.fast_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.use_when_dead );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.timer_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.life_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.expire_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cross_scene_destory );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.store_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tag );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pickup_notice );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.external_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_mix );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_break );
			readPos += GameAssist.ReadString( binContent, readPos, out member.break_get);
			readPos += GameAssist.ReadString( binContent, readPos, out member.break_count);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.source_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cast_skill );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.bi_log );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 51)
		{
			Ex.Logger.Log("ItemProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("ItemProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="description"){Ex.Logger.Log("ItemProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[3]!="icon"){Ex.Logger.Log("ItemProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[4]!="model"){Ex.Logger.Log("ItemProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("ItemProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="subtype"){Ex.Logger.Log("ItemProto.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[7]!="subtype_name"){Ex.Logger.Log("ItemProto.csv中字段[subtype_name]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("ItemProto.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("ItemProto.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="marquee"){Ex.Logger.Log("ItemProto.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[11]!="time_remind"){Ex.Logger.Log("ItemProto.csv中字段[time_remind]位置不对应"); return false; }
		if(vecLine[12]!="price"){Ex.Logger.Log("ItemProto.csv中字段[price]位置不对应"); return false; }
		if(vecLine[13]!="exchange_bottom"){Ex.Logger.Log("ItemProto.csv中字段[exchange_bottom]位置不对应"); return false; }
		if(vecLine[14]!="exchange_init"){Ex.Logger.Log("ItemProto.csv中字段[exchange_init]位置不对应"); return false; }
		if(vecLine[15]!="exchange_currency"){Ex.Logger.Log("ItemProto.csv中字段[exchange_currency]位置不对应"); return false; }
		if(vecLine[16]!="occupation"){Ex.Logger.Log("ItemProto.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[17]!="transfer_id"){Ex.Logger.Log("ItemProto.csv中字段[transfer_id]位置不对应"); return false; }
		if(vecLine[18]!="stack"){Ex.Logger.Log("ItemProto.csv中字段[stack]位置不对应"); return false; }
		if(vecLine[19]!="bind"){Ex.Logger.Log("ItemProto.csv中字段[bind]位置不对应"); return false; }
		if(vecLine[20]!="can_lock"){Ex.Logger.Log("ItemProto.csv中字段[can_lock]位置不对应"); return false; }
		if(vecLine[21]!="pickup_type"){Ex.Logger.Log("ItemProto.csv中字段[pickup_type]位置不对应"); return false; }
		if(vecLine[22]!="item_effect"){Ex.Logger.Log("ItemProto.csv中字段[item_effect]位置不对应"); return false; }
		if(vecLine[23]!="behaviac"){Ex.Logger.Log("ItemProto.csv中字段[behaviac]位置不对应"); return false; }
		if(vecLine[24]!="server_script_id"){Ex.Logger.Log("ItemProto.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[25]!="effect_param"){Ex.Logger.Log("ItemProto.csv中字段[effect_param]位置不对应"); return false; }
		if(vecLine[26]!="required_scene"){Ex.Logger.Log("ItemProto.csv中字段[required_scene]位置不对应"); return false; }
		if(vecLine[27]!="relations"){Ex.Logger.Log("ItemProto.csv中字段[relations]位置不对应"); return false; }
		if(vecLine[28]!="target_type"){Ex.Logger.Log("ItemProto.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[29]!="use_destory"){Ex.Logger.Log("ItemProto.csv中字段[use_destory]位置不对应"); return false; }
		if(vecLine[30]!="global_cd"){Ex.Logger.Log("ItemProto.csv中字段[global_cd]位置不对应"); return false; }
		if(vecLine[31]!="group"){Ex.Logger.Log("ItemProto.csv中字段[group]位置不对应"); return false; }
		if(vecLine[32]!="batch_use"){Ex.Logger.Log("ItemProto.csv中字段[batch_use]位置不对应"); return false; }
		if(vecLine[33]!="fast_use"){Ex.Logger.Log("ItemProto.csv中字段[fast_use]位置不对应"); return false; }
		if(vecLine[34]!="use_when_dead"){Ex.Logger.Log("ItemProto.csv中字段[use_when_dead]位置不对应"); return false; }
		if(vecLine[35]!="timer_type"){Ex.Logger.Log("ItemProto.csv中字段[timer_type]位置不对应"); return false; }
		if(vecLine[36]!="life_time"){Ex.Logger.Log("ItemProto.csv中字段[life_time]位置不对应"); return false; }
		if(vecLine[37]!="expire_time"){Ex.Logger.Log("ItemProto.csv中字段[expire_time]位置不对应"); return false; }
		if(vecLine[38]!="cross_scene_destory"){Ex.Logger.Log("ItemProto.csv中字段[cross_scene_destory]位置不对应"); return false; }
		if(vecLine[39]!="store_type"){Ex.Logger.Log("ItemProto.csv中字段[store_type]位置不对应"); return false; }
		if(vecLine[40]!="tag"){Ex.Logger.Log("ItemProto.csv中字段[tag]位置不对应"); return false; }
		if(vecLine[41]!="pickup_notice"){Ex.Logger.Log("ItemProto.csv中字段[pickup_notice]位置不对应"); return false; }
		if(vecLine[42]!="external_id"){Ex.Logger.Log("ItemProto.csv中字段[external_id]位置不对应"); return false; }
		if(vecLine[43]!="can_mix"){Ex.Logger.Log("ItemProto.csv中字段[can_mix]位置不对应"); return false; }
		if(vecLine[44]!="can_break"){Ex.Logger.Log("ItemProto.csv中字段[can_break]位置不对应"); return false; }
		if(vecLine[45]!="break_get"){Ex.Logger.Log("ItemProto.csv中字段[break_get]位置不对应"); return false; }
		if(vecLine[46]!="break_count"){Ex.Logger.Log("ItemProto.csv中字段[break_count]位置不对应"); return false; }
		if(vecLine[47]!="unlock_lv"){Ex.Logger.Log("ItemProto.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[48]!="source_id"){Ex.Logger.Log("ItemProto.csv中字段[source_id]位置不对应"); return false; }
		if(vecLine[49]!="cast_skill"){Ex.Logger.Log("ItemProto.csv中字段[cast_skill]位置不对应"); return false; }
		if(vecLine[50]!="bi_log"){Ex.Logger.Log("ItemProto.csv中字段[bi_log]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)51)
			{
				return false;
			}
			ItemProtoElement member = new ItemProtoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=Convert.ToInt32(vecLine[1]);
			member.description=Convert.ToInt32(vecLine[2]);
			member.icon=vecLine[3];
			member.model=Convert.ToInt32(vecLine[4]);
			member.type=Convert.ToInt32(vecLine[5]);
			member.subtype=Convert.ToInt32(vecLine[6]);
			member.subtype_name=Convert.ToInt32(vecLine[7]);
			member.level=Convert.ToInt32(vecLine[8]);
			member.rank=Convert.ToInt32(vecLine[9]);
			member.marquee=Convert.ToInt32(vecLine[10]);
			member.time_remind=Convert.ToInt32(vecLine[11]);
			member.price=Convert.ToInt32(vecLine[12]);
			member.exchange_bottom=Convert.ToInt32(vecLine[13]);
			member.exchange_init=Convert.ToInt32(vecLine[14]);
			member.exchange_currency=Convert.ToInt32(vecLine[15]);
			member.occupation=vecLine[16];
			member.transfer_id=vecLine[17];
			member.stack=Convert.ToInt32(vecLine[18]);
			member.bind=Convert.ToInt32(vecLine[19]);
			member.can_lock=Convert.ToInt32(vecLine[20]);
			member.pickup_type=Convert.ToInt32(vecLine[21]);
			member.item_effect=vecLine[22];
			member.behaviac=vecLine[23];
			member.server_script_id=vecLine[24];
			member.effect_param=vecLine[25];
			member.required_scene=Convert.ToInt32(vecLine[26]);
			member.relations=Convert.ToInt32(vecLine[27]);
			member.target_type=Convert.ToInt32(vecLine[28]);
			member.use_destory=Convert.ToInt32(vecLine[29]);
			member.global_cd=Convert.ToInt32(vecLine[30]);
			member.group=Convert.ToInt32(vecLine[31]);
			member.batch_use=Convert.ToInt32(vecLine[32]);
			member.fast_use=Convert.ToInt32(vecLine[33]);
			member.use_when_dead=Convert.ToInt32(vecLine[34]);
			member.timer_type=Convert.ToInt32(vecLine[35]);
			member.life_time=Convert.ToInt32(vecLine[36]);
			member.expire_time=Convert.ToInt32(vecLine[37]);
			member.cross_scene_destory=Convert.ToInt32(vecLine[38]);
			member.store_type=Convert.ToInt32(vecLine[39]);
			member.tag=Convert.ToInt32(vecLine[40]);
			member.pickup_notice=Convert.ToInt32(vecLine[41]);
			member.external_id=Convert.ToInt32(vecLine[42]);
			member.can_mix=Convert.ToInt32(vecLine[43]);
			member.can_break=Convert.ToInt32(vecLine[44]);
			member.break_get=vecLine[45];
			member.break_count=vecLine[46];
			member.unlock_lv=Convert.ToInt32(vecLine[47]);
			member.source_id=Convert.ToInt32(vecLine[48]);
			member.cast_skill=Convert.ToInt32(vecLine[49]);
			member.bi_log=Convert.ToInt32(vecLine[50]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
