using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//道具原型配置数据类
public class ItemProtoElement
{
	public int id;               	//道具ID	在中转中表示圣骑士所获得的道具id
	public string comment;       	//道具注释	策划用
	public int name;             	//道具名称	文本id
	public int description;      	//道具描述	文本id
	public string icon;          	//道具图标	资源路径
	public int model;            	//道具模型	资源路径
	public int type;             	//道具大类	1货币 2装备 3材料 4宝石 5一般用品 6药品 7礼包
	public int subtype;          	//道具子类	
	public int level;            	//道具等级	0表示无等级限制
	public int rank;             	//道具品质	0白 1绿 2蓝 3紫 4橙
	public int price;            	//系统回收价格	对应的银币价格
	public int exchange_bottom;  	//交易最低价格	对应金币价格
	public int exchange_init;    	//交易初始价格	对应金币价格
	public int exchange_currency;	//交易货币类型	0通用 1交易货币 2硬货币
	public int occupation;       	//职业限制	二进制位运算转成的十进制数，从最高位到最低位对应 【战士】=32 【刺客】=16 【游侠】=8 【魔法师】=4 【圣骑士】=2 【神秘使】=1
	public li transfer_id;       	//中转id	进行道具中专时 对应的道具 按照顺序代表【法师】【游侠】【神秘使】【战士】
	public int stack;            	//堆叠数量	1~65535
	public int bind;             	//绑定形式	0不绑定 1拾取绑定 2使用绑定
	public int merge_item;       	//对应绑定道具	非绑定道具合并时转化为对应id的道具  0表示不会转化
	public int pickup_type;      	//拾取形式	0常规拾取 1拾取后立刻使用 2拾取后弹出快捷使用界面 3拾取后归属于工会
	public string item_effect;   	//物品效果	更新中 不填表示无法使用
	public int required_scene;   	//使用需求场景	0无需求 1城镇 2野外 3副本
	public int use_destory;      	//使用后销毁	0不销毁 1销毁
	public int batch_use;        	//批量使用	0不可批量使用 1可批量使用 2可快速使用
	public int use_when_dead;    	//死亡后使用	0不可以 1可以
	public int timer_type;       	//使用后销毁	0不记时 1入手计时 2使用计时
	public int life_time;        	//道具寿命	单位为分 如果可叠加则不生效
	public int expire_time;      	//过期时间	填入时间 填0则表示没有过期时间
	public int cross_scene_destory;	//切换区域销毁	0不销毁 1销毁
	public int store_type;       	//存储类型	0不存背包 1存通用背包
	public int tag;              	//背包标签	对于不存背包的道具无效
	public int pickup_notice;    	//过期时间	0不公告 1公告

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
		if(vecLine.Count != 32)
		{
			Ex.Logger.Log("ItemProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ItemProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ItemProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="description"){Ex.Logger.Log("ItemProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("ItemProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="model"){Ex.Logger.Log("ItemProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[6]!="type"){Ex.Logger.Log("ItemProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[7]!="subtype"){Ex.Logger.Log("ItemProto.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("ItemProto.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("ItemProto.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="price"){Ex.Logger.Log("ItemProto.csv中字段[price]位置不对应"); return false; }
		if(vecLine[11]!="exchange_bottom"){Ex.Logger.Log("ItemProto.csv中字段[exchange_bottom]位置不对应"); return false; }
		if(vecLine[12]!="exchange_init"){Ex.Logger.Log("ItemProto.csv中字段[exchange_init]位置不对应"); return false; }
		if(vecLine[13]!="exchange_currency"){Ex.Logger.Log("ItemProto.csv中字段[exchange_currency]位置不对应"); return false; }
		if(vecLine[14]!="occupation"){Ex.Logger.Log("ItemProto.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[15]!="transfer_id"){Ex.Logger.Log("ItemProto.csv中字段[transfer_id]位置不对应"); return false; }
		if(vecLine[16]!="stack"){Ex.Logger.Log("ItemProto.csv中字段[stack]位置不对应"); return false; }
		if(vecLine[17]!="bind"){Ex.Logger.Log("ItemProto.csv中字段[bind]位置不对应"); return false; }
		if(vecLine[18]!="merge_item"){Ex.Logger.Log("ItemProto.csv中字段[merge_item]位置不对应"); return false; }
		if(vecLine[19]!="pickup_type"){Ex.Logger.Log("ItemProto.csv中字段[pickup_type]位置不对应"); return false; }
		if(vecLine[20]!="item_effect"){Ex.Logger.Log("ItemProto.csv中字段[item_effect]位置不对应"); return false; }
		if(vecLine[21]!="required_scene"){Ex.Logger.Log("ItemProto.csv中字段[required_scene]位置不对应"); return false; }
		if(vecLine[22]!="use_destory"){Ex.Logger.Log("ItemProto.csv中字段[use_destory]位置不对应"); return false; }
		if(vecLine[23]!="batch_use"){Ex.Logger.Log("ItemProto.csv中字段[batch_use]位置不对应"); return false; }
		if(vecLine[24]!="use_when_dead"){Ex.Logger.Log("ItemProto.csv中字段[use_when_dead]位置不对应"); return false; }
		if(vecLine[25]!="timer_type"){Ex.Logger.Log("ItemProto.csv中字段[timer_type]位置不对应"); return false; }
		if(vecLine[26]!="life_time"){Ex.Logger.Log("ItemProto.csv中字段[life_time]位置不对应"); return false; }
		if(vecLine[27]!="expire_time"){Ex.Logger.Log("ItemProto.csv中字段[expire_time]位置不对应"); return false; }
		if(vecLine[28]!="cross_scene_destory"){Ex.Logger.Log("ItemProto.csv中字段[cross_scene_destory]位置不对应"); return false; }
		if(vecLine[29]!="store_type"){Ex.Logger.Log("ItemProto.csv中字段[store_type]位置不对应"); return false; }
		if(vecLine[30]!="tag"){Ex.Logger.Log("ItemProto.csv中字段[tag]位置不对应"); return false; }
		if(vecLine[31]!="pickup_notice"){Ex.Logger.Log("ItemProto.csv中字段[pickup_notice]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ItemProtoElement member = new ItemProtoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.price );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_bottom );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_init );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exchange_currency );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occupation );
			readPos += GameAssist.ReadString( binContent, readPos, out member.transfer_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.bind );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.merge_item );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pickup_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_effect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_scene );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.use_destory );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.batch_use );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.use_when_dead );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.timer_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.life_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.expire_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cross_scene_destory );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.store_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tag );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pickup_notice );

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
		if(vecLine.Count != 32)
		{
			Ex.Logger.Log("ItemProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ItemProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ItemProto.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="description"){Ex.Logger.Log("ItemProto.csv中字段[description]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("ItemProto.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="model"){Ex.Logger.Log("ItemProto.csv中字段[model]位置不对应"); return false; }
		if(vecLine[6]!="type"){Ex.Logger.Log("ItemProto.csv中字段[type]位置不对应"); return false; }
		if(vecLine[7]!="subtype"){Ex.Logger.Log("ItemProto.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[8]!="level"){Ex.Logger.Log("ItemProto.csv中字段[level]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("ItemProto.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="price"){Ex.Logger.Log("ItemProto.csv中字段[price]位置不对应"); return false; }
		if(vecLine[11]!="exchange_bottom"){Ex.Logger.Log("ItemProto.csv中字段[exchange_bottom]位置不对应"); return false; }
		if(vecLine[12]!="exchange_init"){Ex.Logger.Log("ItemProto.csv中字段[exchange_init]位置不对应"); return false; }
		if(vecLine[13]!="exchange_currency"){Ex.Logger.Log("ItemProto.csv中字段[exchange_currency]位置不对应"); return false; }
		if(vecLine[14]!="occupation"){Ex.Logger.Log("ItemProto.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[15]!="transfer_id"){Ex.Logger.Log("ItemProto.csv中字段[transfer_id]位置不对应"); return false; }
		if(vecLine[16]!="stack"){Ex.Logger.Log("ItemProto.csv中字段[stack]位置不对应"); return false; }
		if(vecLine[17]!="bind"){Ex.Logger.Log("ItemProto.csv中字段[bind]位置不对应"); return false; }
		if(vecLine[18]!="merge_item"){Ex.Logger.Log("ItemProto.csv中字段[merge_item]位置不对应"); return false; }
		if(vecLine[19]!="pickup_type"){Ex.Logger.Log("ItemProto.csv中字段[pickup_type]位置不对应"); return false; }
		if(vecLine[20]!="item_effect"){Ex.Logger.Log("ItemProto.csv中字段[item_effect]位置不对应"); return false; }
		if(vecLine[21]!="required_scene"){Ex.Logger.Log("ItemProto.csv中字段[required_scene]位置不对应"); return false; }
		if(vecLine[22]!="use_destory"){Ex.Logger.Log("ItemProto.csv中字段[use_destory]位置不对应"); return false; }
		if(vecLine[23]!="batch_use"){Ex.Logger.Log("ItemProto.csv中字段[batch_use]位置不对应"); return false; }
		if(vecLine[24]!="use_when_dead"){Ex.Logger.Log("ItemProto.csv中字段[use_when_dead]位置不对应"); return false; }
		if(vecLine[25]!="timer_type"){Ex.Logger.Log("ItemProto.csv中字段[timer_type]位置不对应"); return false; }
		if(vecLine[26]!="life_time"){Ex.Logger.Log("ItemProto.csv中字段[life_time]位置不对应"); return false; }
		if(vecLine[27]!="expire_time"){Ex.Logger.Log("ItemProto.csv中字段[expire_time]位置不对应"); return false; }
		if(vecLine[28]!="cross_scene_destory"){Ex.Logger.Log("ItemProto.csv中字段[cross_scene_destory]位置不对应"); return false; }
		if(vecLine[29]!="store_type"){Ex.Logger.Log("ItemProto.csv中字段[store_type]位置不对应"); return false; }
		if(vecLine[30]!="tag"){Ex.Logger.Log("ItemProto.csv中字段[tag]位置不对应"); return false; }
		if(vecLine[31]!="pickup_notice"){Ex.Logger.Log("ItemProto.csv中字段[pickup_notice]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)32)
			{
				return false;
			}
			ItemProtoElement member = new ItemProtoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.description=Convert.ToInt32(vecLine[3]);
			member.icon=vecLine[4];
			member.model=Convert.ToInt32(vecLine[5]);
			member.type=Convert.ToInt32(vecLine[6]);
			member.subtype=Convert.ToInt32(vecLine[7]);
			member.level=Convert.ToInt32(vecLine[8]);
			member.rank=Convert.ToInt32(vecLine[9]);
			member.price=Convert.ToInt32(vecLine[10]);
			member.exchange_bottom=Convert.ToInt32(vecLine[11]);
			member.exchange_init=Convert.ToInt32(vecLine[12]);
			member.exchange_currency=Convert.ToInt32(vecLine[13]);
			member.occupation=Convert.ToInt32(vecLine[14]);
			member.transfer_id=vecLine[15];
			member.stack=Convert.ToInt32(vecLine[16]);
			member.bind=Convert.ToInt32(vecLine[17]);
			member.merge_item=Convert.ToInt32(vecLine[18]);
			member.pickup_type=Convert.ToInt32(vecLine[19]);
			member.item_effect=vecLine[20];
			member.required_scene=Convert.ToInt32(vecLine[21]);
			member.use_destory=Convert.ToInt32(vecLine[22]);
			member.batch_use=Convert.ToInt32(vecLine[23]);
			member.use_when_dead=Convert.ToInt32(vecLine[24]);
			member.timer_type=Convert.ToInt32(vecLine[25]);
			member.life_time=Convert.ToInt32(vecLine[26]);
			member.expire_time=Convert.ToInt32(vecLine[27]);
			member.cross_scene_destory=Convert.ToInt32(vecLine[28]);
			member.store_type=Convert.ToInt32(vecLine[29]);
			member.tag=Convert.ToInt32(vecLine[30]);
			member.pickup_notice=Convert.ToInt32(vecLine[31]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
