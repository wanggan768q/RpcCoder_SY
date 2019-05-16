
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBShop.cs
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


//BuyItem请求封装类
[System.Serializable]
public class ShopRpcBuyItemAskWraper
{

	//构造函数
	public ShopRpcBuyItemAskWraper()
	{
		 m_ShopItemId = -1;
		 m_ItemNum = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ShopItemId = -1;
		 m_ItemNum = -1;

	}

 	//转化成Protobuffer类型函数
	public ShopRpcBuyItemAsk ToPB()
	{
		ShopRpcBuyItemAsk v = new ShopRpcBuyItemAsk();
		v.ShopItemId = m_ShopItemId;
		v.ItemNum = m_ItemNum;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ShopRpcBuyItemAsk v)
	{
        if (v == null)
            return;
		m_ShopItemId = v.ShopItemId;
		m_ItemNum = v.ItemNum;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ShopRpcBuyItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ShopRpcBuyItemAsk pb = ProtoBuf.Serializer.Deserialize<ShopRpcBuyItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ShopItemId
	public int m_ShopItemId;
	public int ShopItemId
	{
		get { return m_ShopItemId;}
		set { m_ShopItemId = value; }
	}
	//ItemNum
	public int m_ItemNum;
	public int ItemNum
	{
		get { return m_ItemNum;}
		set { m_ItemNum = value; }
	}


};
//BuyItem回应封装类
[System.Serializable]
public class ShopRpcBuyItemReplyWraper
{

	//构造函数
	public ShopRpcBuyItemReplyWraper()
	{
		 m_Result = -1;
		 m_ItemInfo = new ShopItemWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemInfo = new ShopItemWraper();

	}

 	//转化成Protobuffer类型函数
	public ShopRpcBuyItemReply ToPB()
	{
		ShopRpcBuyItemReply v = new ShopRpcBuyItemReply();
		v.Result = m_Result;
		v.ItemInfo = m_ItemInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ShopRpcBuyItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemInfo.FromPB(v.ItemInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ShopRpcBuyItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ShopRpcBuyItemReply pb = ProtoBuf.Serializer.Deserialize<ShopRpcBuyItemReply>(protoMS);
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
	//ItemInfo
	public ShopItemWraper m_ItemInfo;
	public ShopItemWraper ItemInfo
	{
		get { return m_ItemInfo;}
		set { m_ItemInfo = value; }
	}


};
//ShopInfo请求封装类
[System.Serializable]
public class ShopRpcShopInfoAskWraper
{

	//构造函数
	public ShopRpcShopInfoAskWraper()
	{
		 m_RoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public ShopRpcShopInfoAsk ToPB()
	{
		ShopRpcShopInfoAsk v = new ShopRpcShopInfoAsk();
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ShopRpcShopInfoAsk v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ShopRpcShopInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ShopRpcShopInfoAsk pb = ProtoBuf.Serializer.Deserialize<ShopRpcShopInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public int m_RoleID;
	public int RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//ShopInfo回应封装类
[System.Serializable]
public class ShopRpcShopInfoReplyWraper
{

	//构造函数
	public ShopRpcShopInfoReplyWraper()
	{
		 m_Result = -1;
		m_ItemInfo = new List<ShopItemWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ItemInfo = new List<ShopItemWraper>();

	}

 	//转化成Protobuffer类型函数
	public ShopRpcShopInfoReply ToPB()
	{
		ShopRpcShopInfoReply v = new ShopRpcShopInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ItemInfo.Count; i++)
			v.ItemInfo.Add( m_ItemInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ShopRpcShopInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemInfo.Clear();
		for( int i=0; i<v.ItemInfo.Count; i++)
			m_ItemInfo.Add( new ShopItemWraper());
		for( int i=0; i<v.ItemInfo.Count; i++)
			m_ItemInfo[i].FromPB(v.ItemInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ShopRpcShopInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ShopRpcShopInfoReply pb = ProtoBuf.Serializer.Deserialize<ShopRpcShopInfoReply>(protoMS);
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
	//ItemInfo
	public List<ShopItemWraper> m_ItemInfo;
	public int SizeItemInfo()
	{
		return m_ItemInfo.Count;
	}
	public List<ShopItemWraper> GetItemInfo()
	{
		return m_ItemInfo;
	}
	public ShopItemWraper GetItemInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemInfo.Count)
			return new ShopItemWraper();
		return m_ItemInfo[Index];
	}
	public void SetItemInfo( List<ShopItemWraper> v )
	{
		m_ItemInfo=v;
	}
	public void SetItemInfo( int Index, ShopItemWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemInfo.Count)
			return;
		m_ItemInfo[Index] = v;
	}
	public void AddItemInfo( ShopItemWraper v )
	{
		m_ItemInfo.Add(v);
	}
	public void ClearItemInfo( )
	{
		m_ItemInfo.Clear();
	}


};
