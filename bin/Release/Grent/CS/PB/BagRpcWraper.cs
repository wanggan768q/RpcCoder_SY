
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBBag.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//UseItem请求封装类
[System.Serializable]
public class BagRpcUseItemAskWraper
{

	//构造函数
	public BagRpcUseItemAskWraper()
	{
		 m_Count = -1;
		 m_Pos = -1;
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Count = -1;
		 m_Pos = -1;
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcUseItemAsk ToPB()
	{
		BagRpcUseItemAsk v = new BagRpcUseItemAsk();
		v.Count = m_Count;
		v.Pos = m_Pos;
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcUseItemAsk v)
	{
        if (v == null)
            return;
		m_Count = v.Count;
		m_Pos = v.Pos;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcUseItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcUseItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcUseItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}
	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//UseItem回应封装类
[System.Serializable]
public class BagRpcUseItemReplyWraper
{

	//构造函数
	public BagRpcUseItemReplyWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();
		 m_NowItem = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();
		 m_NowItem = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcUseItemReply ToPB()
	{
		BagRpcUseItemReply v = new BagRpcUseItemReply();
		v.Result = m_Result;
		v.Item = m_Item.ToPB();
		v.NowItem = m_NowItem.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcUseItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Item.FromPB(v.Item);
		m_NowItem.FromPB(v.NowItem);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcUseItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcUseItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcUseItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//位置
	public ItemObjWraper m_Item;
	public ItemObjWraper Item
	{
		get { return m_Item;}
		set { m_Item = value; }
	}
	//当前道具 
	public ItemObjWraper m_NowItem;
	public ItemObjWraper NowItem
	{
		get { return m_NowItem;}
		set { m_NowItem = value; }
	}


};
//SaleItem请求封装类
[System.Serializable]
public class BagRpcSaleItemAskWraper
{

	//构造函数
	public BagRpcSaleItemAskWraper()
	{
		 m_Pos = -1;
		 m_Count = -1;
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_Count = -1;
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcSaleItemAsk ToPB()
	{
		BagRpcSaleItemAsk v = new BagRpcSaleItemAsk();
		v.Pos = m_Pos;
		v.Count = m_Count;
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcSaleItemAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_Count = v.Count;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcSaleItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcSaleItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcSaleItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//卖出数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//SaleItem回应封装类
[System.Serializable]
public class BagRpcSaleItemReplyWraper
{

	//构造函数
	public BagRpcSaleItemReplyWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcSaleItemReply ToPB()
	{
		BagRpcSaleItemReply v = new BagRpcSaleItemReply();
		v.Result = m_Result;
		v.Item = m_Item.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcSaleItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Item.FromPB(v.Item);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcSaleItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcSaleItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcSaleItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//位置
	public ItemObjWraper m_Item;
	public ItemObjWraper Item
	{
		get { return m_Item;}
		set { m_Item = value; }
	}


};
//LockItem请求封装类
[System.Serializable]
public class BagRpcLockItemAskWraper
{

	//构造函数
	public BagRpcLockItemAskWraper()
	{
		 m_Pos = -1;
		 m_IsLock = false;
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_IsLock = false;
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcLockItemAsk ToPB()
	{
		BagRpcLockItemAsk v = new BagRpcLockItemAsk();
		v.Pos = m_Pos;
		v.IsLock = m_IsLock;
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcLockItemAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_IsLock = v.IsLock;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcLockItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcLockItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcLockItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//IsLock
	public bool m_IsLock;
	public bool IsLock
	{
		get { return m_IsLock;}
		set { m_IsLock = value; }
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//LockItem回应封装类
[System.Serializable]
public class BagRpcLockItemReplyWraper
{

	//构造函数
	public BagRpcLockItemReplyWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcLockItemReply ToPB()
	{
		BagRpcLockItemReply v = new BagRpcLockItemReply();
		v.Result = m_Result;
		v.Item = m_Item.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcLockItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Item.FromPB(v.Item);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcLockItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcLockItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcLockItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//位置
	public ItemObjWraper m_Item;
	public ItemObjWraper Item
	{
		get { return m_Item;}
		set { m_Item = value; }
	}


};
//解锁背包格子请求封装类
[System.Serializable]
public class BagRpcDeblockingAskWraper
{

	//构造函数
	public BagRpcDeblockingAskWraper()
	{
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcDeblockingAsk ToPB()
	{
		BagRpcDeblockingAsk v = new BagRpcDeblockingAsk();
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcDeblockingAsk v)
	{
        if (v == null)
            return;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcDeblockingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcDeblockingAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcDeblockingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//解锁背包格子回应封装类
[System.Serializable]
public class BagRpcDeblockingReplyWraper
{

	//构造函数
	public BagRpcDeblockingReplyWraper()
	{
		 m_Result = -9999;
		 m_BagType = -1;
		 m_CurCapacity = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_BagType = -1;
		 m_CurCapacity = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcDeblockingReply ToPB()
	{
		BagRpcDeblockingReply v = new BagRpcDeblockingReply();
		v.Result = m_Result;
		v.BagType = m_BagType;
		v.CurCapacity = m_CurCapacity;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcDeblockingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_BagType = v.BagType;
		m_CurCapacity = v.CurCapacity;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcDeblockingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcDeblockingReply pb = ProtoBuf.Serializer.Deserialize<BagRpcDeblockingReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}
	//当前的容量
	public int m_CurCapacity;
	public int CurCapacity
	{
		get { return m_CurCapacity;}
		set { m_CurCapacity = value; }
	}


};
//TakeItem请求封装类
[System.Serializable]
public class BagRpcTakeItemAskWraper
{

	//构造函数
	public BagRpcTakeItemAskWraper()
	{
		 m_FromBagType = -1;
		 m_ToBagType = -1;
		 m_FromPos = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FromBagType = -1;
		 m_ToBagType = -1;
		 m_FromPos = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcTakeItemAsk ToPB()
	{
		BagRpcTakeItemAsk v = new BagRpcTakeItemAsk();
		v.FromBagType = m_FromBagType;
		v.ToBagType = m_ToBagType;
		v.FromPos = m_FromPos;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTakeItemAsk v)
	{
        if (v == null)
            return;
		m_FromBagType = v.FromBagType;
		m_ToBagType = v.ToBagType;
		m_FromPos = v.FromPos;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTakeItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTakeItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcTakeItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//源背包
	public int m_FromBagType;
	public int FromBagType
	{
		get { return m_FromBagType;}
		set { m_FromBagType = value; }
	}
	//目标背包
	public int m_ToBagType;
	public int ToBagType
	{
		get { return m_ToBagType;}
		set { m_ToBagType = value; }
	}
	//源背包位置
	public int m_FromPos;
	public int FromPos
	{
		get { return m_FromPos;}
		set { m_FromPos = value; }
	}


};
//TakeItem回应封装类
[System.Serializable]
public class BagRpcTakeItemReplyWraper
{

	//构造函数
	public BagRpcTakeItemReplyWraper()
	{
		 m_Result = -9999;
		 m_ToItemObj = new ItemObjWraper();
		 m_FromItemObj = new ItemObjWraper();
		 m_FromBagType = -1;
		 m_ToBagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ToItemObj = new ItemObjWraper();
		 m_FromItemObj = new ItemObjWraper();
		 m_FromBagType = -1;
		 m_ToBagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcTakeItemReply ToPB()
	{
		BagRpcTakeItemReply v = new BagRpcTakeItemReply();
		v.Result = m_Result;
		v.ToItemObj = m_ToItemObj.ToPB();
		v.FromItemObj = m_FromItemObj.ToPB();
		v.FromBagType = m_FromBagType;
		v.ToBagType = m_ToBagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTakeItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ToItemObj.FromPB(v.ToItemObj);
		m_FromItemObj.FromPB(v.FromItemObj);
		m_FromBagType = v.FromBagType;
		m_ToBagType = v.ToBagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTakeItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTakeItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcTakeItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//目标背包道具
	public ItemObjWraper m_ToItemObj;
	public ItemObjWraper ToItemObj
	{
		get { return m_ToItemObj;}
		set { m_ToItemObj = value; }
	}
	//源背包道具
	public ItemObjWraper m_FromItemObj;
	public ItemObjWraper FromItemObj
	{
		get { return m_FromItemObj;}
		set { m_FromItemObj = value; }
	}
	//源背包
	public int m_FromBagType;
	public int FromBagType
	{
		get { return m_FromBagType;}
		set { m_FromBagType = value; }
	}
	//目标背包
	public int m_ToBagType;
	public int ToBagType
	{
		get { return m_ToBagType;}
		set { m_ToBagType = value; }
	}


};
//整理请求封装类
[System.Serializable]
public class BagRpcTidyAskWraper
{

	//构造函数
	public BagRpcTidyAskWraper()
	{
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcTidyAsk ToPB()
	{
		BagRpcTidyAsk v = new BagRpcTidyAsk();
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTidyAsk v)
	{
        if (v == null)
            return;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTidyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTidyAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcTidyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//整理回应封装类
[System.Serializable]
public class BagRpcTidyReplyWraper
{

	//构造函数
	public BagRpcTidyReplyWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcTidyReply ToPB()
	{
		BagRpcTidyReply v = new BagRpcTidyReply();
		v.Result = m_Result;
		v.Bags = m_Bags.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTidyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.FromPB(v.Bags);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTidyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTidyReply pb = ProtoBuf.Serializer.Deserialize<BagRpcTidyReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//整理后的背包数据
	public BagDataWraper m_Bags;
	public BagDataWraper Bags
	{
		get { return m_Bags;}
		set { m_Bags = value; }
	}


};
//临时背包全部取回请求封装类
[System.Serializable]
public class BagRpcTakeAllBackBagsAskWraper
{

	//构造函数
	public BagRpcTakeAllBackBagsAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public BagRpcTakeAllBackBagsAsk ToPB()
	{
		BagRpcTakeAllBackBagsAsk v = new BagRpcTakeAllBackBagsAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTakeAllBackBagsAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTakeAllBackBagsAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTakeAllBackBagsAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcTakeAllBackBagsAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//临时背包全部取回回应封装类
[System.Serializable]
public class BagRpcTakeAllBackBagsReplyWraper
{

	//构造函数
	public BagRpcTakeAllBackBagsReplyWraper()
	{
		 m_Result = -9999;
		m_Bags = new List<BagDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Bags = new List<BagDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public BagRpcTakeAllBackBagsReply ToPB()
	{
		BagRpcTakeAllBackBagsReply v = new BagRpcTakeAllBackBagsReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Bags.Count; i++)
			v.Bags.Add( m_Bags[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTakeAllBackBagsReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.Clear();
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags.Add( new BagDataWraper());
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags[i].FromPB(v.Bags[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcTakeAllBackBagsReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcTakeAllBackBagsReply pb = ProtoBuf.Serializer.Deserialize<BagRpcTakeAllBackBagsReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//所有背包数据
	public List<BagDataWraper> m_Bags;
	public int SizeBags()
	{
		return m_Bags.Count;
	}
	public List<BagDataWraper> GetBags()
	{
		return m_Bags;
	}
	public BagDataWraper GetBags(int Index)
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return new BagDataWraper();
		return m_Bags[Index];
	}
	public void SetBags( List<BagDataWraper> v )
	{
		m_Bags=v;
	}
	public void SetBags( int Index, BagDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return;
		m_Bags[Index] = v;
	}
	public void AddBags( BagDataWraper v )
	{
		m_Bags.Add(v);
	}
	public void ClearBags( )
	{
		m_Bags.Clear();
	}


};
//背包数据推送通知封装类
[System.Serializable]
public class BagRpcBagChangeNotifyWraper
{

	//构造函数
	public BagRpcBagChangeNotifyWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcBagChangeNotify ToPB()
	{
		BagRpcBagChangeNotify v = new BagRpcBagChangeNotify();
		v.Result = m_Result;
		v.Bags = m_Bags.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcBagChangeNotify v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.FromPB(v.Bags);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcBagChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcBagChangeNotify pb = ProtoBuf.Serializer.Deserialize<BagRpcBagChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//所有背包数据
	public BagDataWraper m_Bags;
	public BagDataWraper Bags
	{
		get { return m_Bags;}
		set { m_Bags = value; }
	}


};
//MergeItem请求封装类
[System.Serializable]
public class BagRpcMergeItemAskWraper
{

	//构造函数
	public BagRpcMergeItemAskWraper()
	{
		 m_Pos = -1;
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcMergeItemAsk ToPB()
	{
		BagRpcMergeItemAsk v = new BagRpcMergeItemAsk();
		v.Pos = m_Pos;
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcMergeItemAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcMergeItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcMergeItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcMergeItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//MergeItem回应封装类
[System.Serializable]
public class BagRpcMergeItemReplyWraper
{

	//构造函数
	public BagRpcMergeItemReplyWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Bags = new BagDataWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcMergeItemReply ToPB()
	{
		BagRpcMergeItemReply v = new BagRpcMergeItemReply();
		v.Result = m_Result;
		v.Bags = m_Bags.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcMergeItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.FromPB(v.Bags);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcMergeItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcMergeItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcMergeItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//所有背包数据
	public BagDataWraper m_Bags;
	public BagDataWraper Bags
	{
		get { return m_Bags;}
		set { m_Bags = value; }
	}


};
//背包数据初始化请求封装类
[System.Serializable]
public class BagRpcBagSyncAskWraper
{

	//构造函数
	public BagRpcBagSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public BagRpcBagSyncAsk ToPB()
	{
		BagRpcBagSyncAsk v = new BagRpcBagSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcBagSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcBagSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcBagSyncAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcBagSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//背包数据初始化回应封装类
[System.Serializable]
public class BagRpcBagSyncReplyWraper
{

	//构造函数
	public BagRpcBagSyncReplyWraper()
	{
		 m_Result = -1;
		m_Bags = new List<BagDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Bags = new List<BagDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public BagRpcBagSyncReply ToPB()
	{
		BagRpcBagSyncReply v = new BagRpcBagSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Bags.Count; i++)
			v.Bags.Add( m_Bags[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcBagSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.Clear();
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags.Add( new BagDataWraper());
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags[i].FromPB(v.Bags[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcBagSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcBagSyncReply pb = ProtoBuf.Serializer.Deserialize<BagRpcBagSyncReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//Bags
	public List<BagDataWraper> m_Bags;
	public int SizeBags()
	{
		return m_Bags.Count;
	}
	public List<BagDataWraper> GetBags()
	{
		return m_Bags;
	}
	public BagDataWraper GetBags(int Index)
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return new BagDataWraper();
		return m_Bags[Index];
	}
	public void SetBags( List<BagDataWraper> v )
	{
		m_Bags=v;
	}
	public void SetBags( int Index, BagDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return;
		m_Bags[Index] = v;
	}
	public void AddBags( BagDataWraper v )
	{
		m_Bags.Add(v);
	}
	public void ClearBags( )
	{
		m_Bags.Clear();
	}


};
//新加物品通知封装类
[System.Serializable]
public class BagRpcAddItemNotifyWraper
{

	//构造函数
	public BagRpcAddItemNotifyWraper()
	{
		m_Item = new List<ItemObjWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Item = new List<ItemObjWraper>();

	}

 	//转化成Protobuffer类型函数
	public BagRpcAddItemNotify ToPB()
	{
		BagRpcAddItemNotify v = new BagRpcAddItemNotify();
		for (int i=0; i<(int)m_Item.Count; i++)
			v.Item.Add( m_Item[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcAddItemNotify v)
	{
        if (v == null)
            return;
		m_Item.Clear();
		for( int i=0; i<v.Item.Count; i++)
			m_Item.Add( new ItemObjWraper());
		for( int i=0; i<v.Item.Count; i++)
			m_Item[i].FromPB(v.Item[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcAddItemNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcAddItemNotify pb = ProtoBuf.Serializer.Deserialize<BagRpcAddItemNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//位置
	public List<ItemObjWraper> m_Item;
	public int SizeItem()
	{
		return m_Item.Count;
	}
	public List<ItemObjWraper> GetItem()
	{
		return m_Item;
	}
	public ItemObjWraper GetItem(int Index)
	{
		if(Index<0 || Index>=(int)m_Item.Count)
			return new ItemObjWraper();
		return m_Item[Index];
	}
	public void SetItem( List<ItemObjWraper> v )
	{
		m_Item=v;
	}
	public void SetItem( int Index, ItemObjWraper v )
	{
		if(Index<0 || Index>=(int)m_Item.Count)
			return;
		m_Item[Index] = v;
	}
	public void AddItem( ItemObjWraper v )
	{
		m_Item.Add(v);
	}
	public void ClearItem( )
	{
		m_Item.Clear();
	}


};
//根据物品id使用物品请求封装类
[System.Serializable]
public class BagRpcConsumeItemAskWraper
{

	//构造函数
	public BagRpcConsumeItemAskWraper()
	{
		m_ConfigId = new List<int>();
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ConfigId = new List<int>();
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public BagRpcConsumeItemAsk ToPB()
	{
		BagRpcConsumeItemAsk v = new BagRpcConsumeItemAsk();
		for (int i=0; i<(int)m_ConfigId.Count; i++)
			v.ConfigId.Add( m_ConfigId[i]);
		for (int i=0; i<(int)m_ItemData.Count; i++)
			v.ItemData.Add( m_ItemData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcConsumeItemAsk v)
	{
        if (v == null)
            return;
		m_ConfigId.Clear();
		for( int i=0; i<v.ConfigId.Count; i++)
			m_ConfigId.Add(v.ConfigId[i]);
		m_ItemData.Clear();
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData[i].FromPB(v.ItemData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcConsumeItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcConsumeItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcConsumeItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品id
	public List<int> m_ConfigId;
	public int SizeConfigId()
	{
		return m_ConfigId.Count;
	}
	public List<int> GetConfigId()
	{
		return m_ConfigId;
	}
	public int GetConfigId(int Index)
	{
		if(Index<0 || Index>=(int)m_ConfigId.Count)
			return -1;
		return m_ConfigId[Index];
	}
	public void SetConfigId( List<int> v )
	{
		m_ConfigId=v;
	}
	public void SetConfigId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ConfigId.Count)
			return;
		m_ConfigId[Index] = v;
	}
	public void AddConfigId( int v=-1 )
	{
		m_ConfigId.Add(v);
	}
	public void ClearConfigId( )
	{
		m_ConfigId.Clear();
	}
	//物品id
	public List<ItemSimpleDataWraper> m_ItemData;
	public int SizeItemData()
	{
		return m_ItemData.Count;
	}
	public List<ItemSimpleDataWraper> GetItemData()
	{
		return m_ItemData;
	}
	public ItemSimpleDataWraper GetItemData(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return new ItemSimpleDataWraper();
		return m_ItemData[Index];
	}
	public void SetItemData( List<ItemSimpleDataWraper> v )
	{
		m_ItemData=v;
	}
	public void SetItemData( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return;
		m_ItemData[Index] = v;
	}
	public void AddItemData( ItemSimpleDataWraper v )
	{
		m_ItemData.Add(v);
	}
	public void ClearItemData( )
	{
		m_ItemData.Clear();
	}


};
//根据物品id使用物品回应封装类
[System.Serializable]
public class BagRpcConsumeItemReplyWraper
{

	//构造函数
	public BagRpcConsumeItemReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcConsumeItemReply ToPB()
	{
		BagRpcConsumeItemReply v = new BagRpcConsumeItemReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcConsumeItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcConsumeItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcConsumeItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcConsumeItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//物品改变通知封装类
[System.Serializable]
public class BagRpcItemChangeNotifyWraper
{

	//构造函数
	public BagRpcItemChangeNotifyWraper()
	{
		m_ItemList = new List<ItemObjWraper>();
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_ItemList = new List<ItemObjWraper>();
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcItemChangeNotify ToPB()
	{
		BagRpcItemChangeNotify v = new BagRpcItemChangeNotify();
		for (int i=0; i<(int)m_ItemList.Count; i++)
			v.ItemList.Add( m_ItemList[i].ToPB());
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcItemChangeNotify v)
	{
        if (v == null)
            return;
		m_ItemList.Clear();
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList.Add( new ItemObjWraper());
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList[i].FromPB(v.ItemList[i]);
		m_BagType = v.BagType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcItemChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcItemChangeNotify pb = ProtoBuf.Serializer.Deserialize<BagRpcItemChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//改变的物品
	public List<ItemObjWraper> m_ItemList;
	public int SizeItemList()
	{
		return m_ItemList.Count;
	}
	public List<ItemObjWraper> GetItemList()
	{
		return m_ItemList;
	}
	public ItemObjWraper GetItemList(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return new ItemObjWraper();
		return m_ItemList[Index];
	}
	public void SetItemList( List<ItemObjWraper> v )
	{
		m_ItemList=v;
	}
	public void SetItemList( int Index, ItemObjWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return;
		m_ItemList[Index] = v;
	}
	public void AddItemList( ItemObjWraper v )
	{
		m_ItemList.Add(v);
	}
	public void ClearItemList( )
	{
		m_ItemList.Clear();
	}
	//背包类型
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}


};
//点击物品请求封装类
[System.Serializable]
public class BagRpcClickItemAskWraper
{

	//构造函数
	public BagRpcClickItemAskWraper()
	{
		 m_Guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;

	}

 	//转化成Protobuffer类型函数
	public BagRpcClickItemAsk ToPB()
	{
		BagRpcClickItemAsk v = new BagRpcClickItemAsk();
		v.Guid = m_Guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcClickItemAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcClickItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcClickItemAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcClickItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品GUID
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}


};
//点击物品回应封装类
[System.Serializable]
public class BagRpcClickItemReplyWraper
{

	//构造函数
	public BagRpcClickItemReplyWraper()
	{
		 m_Result = -1;
		 m_Item = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Item = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcClickItemReply ToPB()
	{
		BagRpcClickItemReply v = new BagRpcClickItemReply();
		v.Result = m_Result;
		v.Item = m_Item.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcClickItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Item.FromPB(v.Item);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcClickItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcClickItemReply pb = ProtoBuf.Serializer.Deserialize<BagRpcClickItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//位置
	public ItemObjWraper m_Item;
	public ItemObjWraper Item
	{
		get { return m_Item;}
		set { m_Item = value; }
	}


};
