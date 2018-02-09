
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Count = -1;
		 m_Pos = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcUseItemAsk ToPB()
	{
		BagRpcUseItemAsk v = new BagRpcUseItemAsk();
		v.Count = m_Count;
		v.Pos = m_Pos;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcUseItemAsk v)
	{
        if (v == null)
            return;
		m_Count = v.Count;
		m_Pos = v.Pos;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Item = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public BagRpcUseItemReply ToPB()
	{
		BagRpcUseItemReply v = new BagRpcUseItemReply();
		v.Result = m_Result;
		v.Item = m_Item.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcUseItemReply v)
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


};
//请求背包数据请求封装类
[System.Serializable]
public class BagRpcSyncAskWraper
{

	//构造函数
	public BagRpcSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public BagRpcSyncAsk ToPB()
	{
		BagRpcSyncAsk v = new BagRpcSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRpcSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcSyncAsk pb = ProtoBuf.Serializer.Deserialize<BagRpcSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求背包数据回应封装类
[System.Serializable]
public class BagRpcSyncReplyWraper
{

	//构造函数
	public BagRpcSyncReplyWraper()
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
	public BagRpcSyncReply ToPB()
	{
		BagRpcSyncReply v = new BagRpcSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Bags.Count; i++)
			v.Bags.Add( m_Bags[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcSyncReply v)
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
		ProtoBuf.Serializer.Serialize<BagRpcSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRpcSyncReply pb = ProtoBuf.Serializer.Deserialize<BagRpcSyncReply>(protoMS);
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
//SaleItem请求封装类
[System.Serializable]
public class BagRpcSaleItemAskWraper
{

	//构造函数
	public BagRpcSaleItemAskWraper()
	{
		 m_Pos = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcSaleItemAsk ToPB()
	{
		BagRpcSaleItemAsk v = new BagRpcSaleItemAsk();
		v.Pos = m_Pos;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcSaleItemAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_Count = v.Count;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_IsLock = false;

	}

 	//转化成Protobuffer类型函数
	public BagRpcLockItemAsk ToPB()
	{
		BagRpcLockItemAsk v = new BagRpcLockItemAsk();
		v.Pos = m_Pos;
		v.IsLock = m_IsLock;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcLockItemAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_IsLock = v.IsLock;

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
		m_Bags = new List<BagDataWraper>();
		 m_BagType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Bags = new List<BagDataWraper>();
		 m_BagType = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRpcTidyReply ToPB()
	{
		BagRpcTidyReply v = new BagRpcTidyReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Bags.Count; i++)
			v.Bags.Add( m_Bags[i].ToPB());
		v.BagType = m_BagType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRpcTidyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Bags.Clear();
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags.Add( new BagDataWraper());
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags[i].FromPB(v.Bags[i]);
		m_BagType = v.BagType;

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
	//BagType
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
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
