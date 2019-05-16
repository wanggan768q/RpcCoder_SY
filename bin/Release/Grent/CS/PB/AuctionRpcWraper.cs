
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBAuction.cs
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


//级别封装类
[System.Serializable]
public class AuctionRpcAuctionInfoAskWraper
{

	//构造函数
	public AuctionRpcAuctionInfoAskWraper()
	{
		 m_ItemId = -1;
		 m_QueueType = -1;
		 m_CurPage = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;
		 m_QueueType = -1;
		 m_CurPage = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcAuctionInfoAsk ToPB()
	{
		AuctionRpcAuctionInfoAsk v = new AuctionRpcAuctionInfoAsk();
		v.ItemId = m_ItemId;
		v.QueueType = m_QueueType;
		v.CurPage = m_CurPage;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcAuctionInfoAsk v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_QueueType = v.QueueType;
		m_CurPage = v.CurPage;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcAuctionInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcAuctionInfoAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcAuctionInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具id
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//排序类型
	public int m_QueueType;
	public int QueueType
	{
		get { return m_QueueType;}
		set { m_QueueType = value; }
	}
	//当前页
	public int m_CurPage;
	public int CurPage
	{
		get { return m_CurPage;}
		set { m_CurPage = value; }
	}


};
//查询拍卖行信息回应封装类
[System.Serializable]
public class AuctionRpcAuctionInfoReplyWraper
{

	//构造函数
	public AuctionRpcAuctionInfoReplyWraper()
	{
		 m_Result = -1;
		m_AuctionItem = new List<AuctionItemWraper>();
		 m_TotalPage = 1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_AuctionItem = new List<AuctionItemWraper>();
		 m_TotalPage = 1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcAuctionInfoReply ToPB()
	{
		AuctionRpcAuctionInfoReply v = new AuctionRpcAuctionInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_AuctionItem.Count; i++)
			v.AuctionItem.Add( m_AuctionItem[i].ToPB());
		v.TotalPage = m_TotalPage;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcAuctionInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AuctionItem.Clear();
		for( int i=0; i<v.AuctionItem.Count; i++)
			m_AuctionItem.Add( new AuctionItemWraper());
		for( int i=0; i<v.AuctionItem.Count; i++)
			m_AuctionItem[i].FromPB(v.AuctionItem[i]);
		m_TotalPage = v.TotalPage;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcAuctionInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcAuctionInfoReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcAuctionInfoReply>(protoMS);
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
	//查询到的信息
	public List<AuctionItemWraper> m_AuctionItem;
	public int SizeAuctionItem()
	{
		return m_AuctionItem.Count;
	}
	public List<AuctionItemWraper> GetAuctionItem()
	{
		return m_AuctionItem;
	}
	public AuctionItemWraper GetAuctionItem(int Index)
	{
		if(Index<0 || Index>=(int)m_AuctionItem.Count)
			return new AuctionItemWraper();
		return m_AuctionItem[Index];
	}
	public void SetAuctionItem( List<AuctionItemWraper> v )
	{
		m_AuctionItem=v;
	}
	public void SetAuctionItem( int Index, AuctionItemWraper v )
	{
		if(Index<0 || Index>=(int)m_AuctionItem.Count)
			return;
		m_AuctionItem[Index] = v;
	}
	public void AddAuctionItem( AuctionItemWraper v )
	{
		m_AuctionItem.Add(v);
	}
	public void ClearAuctionItem( )
	{
		m_AuctionItem.Clear();
	}
	//道具总页数
	public int m_TotalPage;
	public int TotalPage
	{
		get { return m_TotalPage;}
		set { m_TotalPage = value; }
	}


};
//请求上架请求封装类
[System.Serializable]
public class AuctionRpcSellItemAskWraper
{

	//构造函数
	public AuctionRpcSellItemAskWraper()
	{
		 m_ItemGuid = 0;
		 m_ItemId = -1;
		 m_Price = 0;
		 m_Currency = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemGuid = 0;
		 m_ItemId = -1;
		 m_Price = 0;
		 m_Currency = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSellItemAsk ToPB()
	{
		AuctionRpcSellItemAsk v = new AuctionRpcSellItemAsk();
		v.ItemGuid = m_ItemGuid;
		v.ItemId = m_ItemId;
		v.Price = m_Price;
		v.Currency = m_Currency;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSellItemAsk v)
	{
        if (v == null)
            return;
		m_ItemGuid = v.ItemGuid;
		m_ItemId = v.ItemId;
		m_Price = v.Price;
		m_Currency = v.Currency;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSellItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSellItemAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSellItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//出售道具guid
	public UInt64 m_ItemGuid;
	public UInt64 ItemGuid
	{
		get { return m_ItemGuid;}
		set { m_ItemGuid = value; }
	}
	//ItemId
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//拍卖价格
	public int m_Price;
	public int Price
	{
		get { return m_Price;}
		set { m_Price = value; }
	}
	//交易钱币类型
	public int m_Currency;
	public int Currency
	{
		get { return m_Currency;}
		set { m_Currency = value; }
	}
	//交易数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//请求上架回应封装类
[System.Serializable]
public class AuctionRpcSellItemReplyWraper
{

	//构造函数
	public AuctionRpcSellItemReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSellItemReply ToPB()
	{
		AuctionRpcSellItemReply v = new AuctionRpcSellItemReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSellItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSellItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSellItemReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSellItemReply>(protoMS);
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
//购买请求封装类
[System.Serializable]
public class AuctionRpcBuyAskWraper
{

	//构造函数
	public AuctionRpcBuyAskWraper()
	{
		 m_ItemGuid = 0;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemGuid = 0;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcBuyAsk ToPB()
	{
		AuctionRpcBuyAsk v = new AuctionRpcBuyAsk();
		v.ItemGuid = m_ItemGuid;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcBuyAsk v)
	{
        if (v == null)
            return;
		m_ItemGuid = v.ItemGuid;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcBuyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcBuyAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcBuyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//购买道具的guid
	public UInt64 m_ItemGuid;
	public UInt64 ItemGuid
	{
		get { return m_ItemGuid;}
		set { m_ItemGuid = value; }
	}
	//买入数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//购买回应封装类
[System.Serializable]
public class AuctionRpcBuyReplyWraper
{

	//构造函数
	public AuctionRpcBuyReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcBuyReply ToPB()
	{
		AuctionRpcBuyReply v = new AuctionRpcBuyReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcBuyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcBuyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcBuyReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcBuyReply>(protoMS);
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
//重新上架请求封装类
[System.Serializable]
public class AuctionRpcSellAgainAskWraper
{

	//构造函数
	public AuctionRpcSellAgainAskWraper()
	{
		 m_ItemGuid = 0;
		 m_Price = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemGuid = 0;
		 m_Price = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSellAgainAsk ToPB()
	{
		AuctionRpcSellAgainAsk v = new AuctionRpcSellAgainAsk();
		v.ItemGuid = m_ItemGuid;
		v.Price = m_Price;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSellAgainAsk v)
	{
        if (v == null)
            return;
		m_ItemGuid = v.ItemGuid;
		m_Price = v.Price;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSellAgainAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSellAgainAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSellAgainAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//再次销售物品guid
	public UInt64 m_ItemGuid;
	public UInt64 ItemGuid
	{
		get { return m_ItemGuid;}
		set { m_ItemGuid = value; }
	}
	//价格
	public int m_Price;
	public int Price
	{
		get { return m_Price;}
		set { m_Price = value; }
	}


};
//重新上架回应封装类
[System.Serializable]
public class AuctionRpcSellAgainReplyWraper
{

	//构造函数
	public AuctionRpcSellAgainReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSellAgainReply ToPB()
	{
		AuctionRpcSellAgainReply v = new AuctionRpcSellAgainReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSellAgainReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSellAgainReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSellAgainReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSellAgainReply>(protoMS);
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
//取回交易记录中物品封装类
[System.Serializable]
public class AuctionRpcGetItemAskWraper
{

	//构造函数
	public AuctionRpcGetItemAskWraper()
	{
		m_BuyRecGuid = new List<UInt64>();
		m_SaleRecGuid = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_BuyRecGuid = new List<UInt64>();
		m_SaleRecGuid = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetItemAsk ToPB()
	{
		AuctionRpcGetItemAsk v = new AuctionRpcGetItemAsk();
		for (int i=0; i<(int)m_BuyRecGuid.Count; i++)
			v.BuyRecGuid.Add( m_BuyRecGuid[i]);
		for (int i=0; i<(int)m_SaleRecGuid.Count; i++)
			v.SaleRecGuid.Add( m_SaleRecGuid[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetItemAsk v)
	{
        if (v == null)
            return;
		m_BuyRecGuid.Clear();
		for( int i=0; i<v.BuyRecGuid.Count; i++)
			m_BuyRecGuid.Add(v.BuyRecGuid[i]);
		m_SaleRecGuid.Clear();
		for( int i=0; i<v.SaleRecGuid.Count; i++)
			m_SaleRecGuid.Add(v.SaleRecGuid[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetItemAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//拍卖行的商品guid
	public List<UInt64> m_BuyRecGuid;
	public int SizeBuyRecGuid()
	{
		return m_BuyRecGuid.Count;
	}
	public List<UInt64> GetBuyRecGuid()
	{
		return m_BuyRecGuid;
	}
	public UInt64 GetBuyRecGuid(int Index)
	{
		if(Index<0 || Index>=(int)m_BuyRecGuid.Count)
			return 0;
		return m_BuyRecGuid[Index];
	}
	public void SetBuyRecGuid( List<UInt64> v )
	{
		m_BuyRecGuid=v;
	}
	public void SetBuyRecGuid( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_BuyRecGuid.Count)
			return;
		m_BuyRecGuid[Index] = v;
	}
	public void AddBuyRecGuid( UInt64 v=0 )
	{
		m_BuyRecGuid.Add(v);
	}
	public void ClearBuyRecGuid( )
	{
		m_BuyRecGuid.Clear();
	}
	//卖的记录guid
	public List<UInt64> m_SaleRecGuid;
	public int SizeSaleRecGuid()
	{
		return m_SaleRecGuid.Count;
	}
	public List<UInt64> GetSaleRecGuid()
	{
		return m_SaleRecGuid;
	}
	public UInt64 GetSaleRecGuid(int Index)
	{
		if(Index<0 || Index>=(int)m_SaleRecGuid.Count)
			return 0;
		return m_SaleRecGuid[Index];
	}
	public void SetSaleRecGuid( List<UInt64> v )
	{
		m_SaleRecGuid=v;
	}
	public void SetSaleRecGuid( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_SaleRecGuid.Count)
			return;
		m_SaleRecGuid[Index] = v;
	}
	public void AddSaleRecGuid( UInt64 v=0 )
	{
		m_SaleRecGuid.Add(v);
	}
	public void ClearSaleRecGuid( )
	{
		m_SaleRecGuid.Clear();
	}


};
//取回拍卖道具回应封装类
[System.Serializable]
public class AuctionRpcGetItemReplyWraper
{

	//构造函数
	public AuctionRpcGetItemReplyWraper()
	{
		 m_Result = -1;
		m_Record = new List<AuctionRecSimpleWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Record = new List<AuctionRecSimpleWraper>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetItemReply ToPB()
	{
		AuctionRpcGetItemReply v = new AuctionRpcGetItemReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Record.Count; i++)
			v.Record.Add( m_Record[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Record.Clear();
		for( int i=0; i<v.Record.Count; i++)
			m_Record.Add( new AuctionRecSimpleWraper());
		for( int i=0; i<v.Record.Count; i++)
			m_Record[i].FromPB(v.Record[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetItemReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetItemReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//返回道具的信息
	public List<AuctionRecSimpleWraper> m_Record;
	public int SizeRecord()
	{
		return m_Record.Count;
	}
	public List<AuctionRecSimpleWraper> GetRecord()
	{
		return m_Record;
	}
	public AuctionRecSimpleWraper GetRecord(int Index)
	{
		if(Index<0 || Index>=(int)m_Record.Count)
			return new AuctionRecSimpleWraper();
		return m_Record[Index];
	}
	public void SetRecord( List<AuctionRecSimpleWraper> v )
	{
		m_Record=v;
	}
	public void SetRecord( int Index, AuctionRecSimpleWraper v )
	{
		if(Index<0 || Index>=(int)m_Record.Count)
			return;
		m_Record[Index] = v;
	}
	public void AddRecord( AuctionRecSimpleWraper v )
	{
		m_Record.Add(v);
	}
	public void ClearRecord( )
	{
		m_Record.Clear();
	}


};
//交易记录请求封装类
[System.Serializable]
public class AuctionRpcRecordAskWraper
{

	//构造函数
	public AuctionRpcRecordAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcRecordAsk ToPB()
	{
		AuctionRpcRecordAsk v = new AuctionRpcRecordAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcRecordAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcRecordAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcRecordAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcRecordAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//交易记录回应封装类
[System.Serializable]
public class AuctionRpcRecordReplyWraper
{

	//构造函数
	public AuctionRpcRecordReplyWraper()
	{
		 m_Result = -1;
		m_Record = new List<AuctionRecSimpleWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Record = new List<AuctionRecSimpleWraper>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcRecordReply ToPB()
	{
		AuctionRpcRecordReply v = new AuctionRpcRecordReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Record.Count; i++)
			v.Record.Add( m_Record[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcRecordReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Record.Clear();
		for( int i=0; i<v.Record.Count; i++)
			m_Record.Add( new AuctionRecSimpleWraper());
		for( int i=0; i<v.Record.Count; i++)
			m_Record[i].FromPB(v.Record[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcRecordReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcRecordReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcRecordReply>(protoMS);
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
	//交易记录简单信息
	public List<AuctionRecSimpleWraper> m_Record;
	public int SizeRecord()
	{
		return m_Record.Count;
	}
	public List<AuctionRecSimpleWraper> GetRecord()
	{
		return m_Record;
	}
	public AuctionRecSimpleWraper GetRecord(int Index)
	{
		if(Index<0 || Index>=(int)m_Record.Count)
			return new AuctionRecSimpleWraper();
		return m_Record[Index];
	}
	public void SetRecord( List<AuctionRecSimpleWraper> v )
	{
		m_Record=v;
	}
	public void SetRecord( int Index, AuctionRecSimpleWraper v )
	{
		if(Index<0 || Index>=(int)m_Record.Count)
			return;
		m_Record[Index] = v;
	}
	public void AddRecord( AuctionRecSimpleWraper v )
	{
		m_Record.Add(v);
	}
	public void ClearRecord( )
	{
		m_Record.Clear();
	}


};
//按类别查询简单信息请求封装类
[System.Serializable]
public class AuctionRpcItemInfoByClassAskWraper
{

	//构造函数
	public AuctionRpcItemInfoByClassAskWraper()
	{
		 m_ItemClass = -1;
		m_ItemId = new List<int>();
		 m_ItemSubClass = -1;
		 m_Prof = -1;
		 m_Level = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemClass = -1;
		m_ItemId = new List<int>();
		 m_ItemSubClass = -1;
		 m_Prof = -1;
		 m_Level = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcItemInfoByClassAsk ToPB()
	{
		AuctionRpcItemInfoByClassAsk v = new AuctionRpcItemInfoByClassAsk();
		v.ItemClass = m_ItemClass;
		for (int i=0; i<(int)m_ItemId.Count; i++)
			v.ItemId.Add( m_ItemId[i]);
		v.ItemSubClass = m_ItemSubClass;
		v.Prof = m_Prof;
		v.Level = m_Level;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcItemInfoByClassAsk v)
	{
        if (v == null)
            return;
		m_ItemClass = v.ItemClass;
		m_ItemId.Clear();
		for( int i=0; i<v.ItemId.Count; i++)
			m_ItemId.Add(v.ItemId[i]);
		m_ItemSubClass = v.ItemSubClass;
		m_Prof = v.Prof;
		m_Level = v.Level;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcItemInfoByClassAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcItemInfoByClassAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcItemInfoByClassAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//商品类别(关注，装备，道具，宠物)
	public int m_ItemClass;
	public int ItemClass
	{
		get { return m_ItemClass;}
		set { m_ItemClass = value; }
	}
	//关注物品的id
	public List<int> m_ItemId;
	public int SizeItemId()
	{
		return m_ItemId.Count;
	}
	public List<int> GetItemId()
	{
		return m_ItemId;
	}
	public int GetItemId(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemId.Count)
			return -1;
		return m_ItemId[Index];
	}
	public void SetItemId( List<int> v )
	{
		m_ItemId=v;
	}
	public void SetItemId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ItemId.Count)
			return;
		m_ItemId[Index] = v;
	}
	public void AddItemId( int v=-1 )
	{
		m_ItemId.Add(v);
	}
	public void ClearItemId( )
	{
		m_ItemId.Clear();
	}
	//子类别
	public int m_ItemSubClass;
	public int ItemSubClass
	{
		get { return m_ItemSubClass;}
		set { m_ItemSubClass = value; }
	}
	//职业
	public int m_Prof;
	public int Prof
	{
		get { return m_Prof;}
		set { m_Prof = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}


};
//按类别查询简单信息回应封装类
[System.Serializable]
public class AuctionRpcItemInfoByClassReplyWraper
{

	//构造函数
	public AuctionRpcItemInfoByClassReplyWraper()
	{
		 m_Result = -1;
		m_ItemCount = new List<AuctionItemCntWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ItemCount = new List<AuctionItemCntWraper>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcItemInfoByClassReply ToPB()
	{
		AuctionRpcItemInfoByClassReply v = new AuctionRpcItemInfoByClassReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ItemCount.Count; i++)
			v.ItemCount.Add( m_ItemCount[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcItemInfoByClassReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemCount.Clear();
		for( int i=0; i<v.ItemCount.Count; i++)
			m_ItemCount.Add( new AuctionItemCntWraper());
		for( int i=0; i<v.ItemCount.Count; i++)
			m_ItemCount[i].FromPB(v.ItemCount[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcItemInfoByClassReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcItemInfoByClassReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcItemInfoByClassReply>(protoMS);
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
	//道具数量信息
	public List<AuctionItemCntWraper> m_ItemCount;
	public int SizeItemCount()
	{
		return m_ItemCount.Count;
	}
	public List<AuctionItemCntWraper> GetItemCount()
	{
		return m_ItemCount;
	}
	public AuctionItemCntWraper GetItemCount(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemCount.Count)
			return new AuctionItemCntWraper();
		return m_ItemCount[Index];
	}
	public void SetItemCount( List<AuctionItemCntWraper> v )
	{
		m_ItemCount=v;
	}
	public void SetItemCount( int Index, AuctionItemCntWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemCount.Count)
			return;
		m_ItemCount[Index] = v;
	}
	public void AddItemCount( AuctionItemCntWraper v )
	{
		m_ItemCount.Add(v);
	}
	public void ClearItemCount( )
	{
		m_ItemCount.Clear();
	}


};
//预上架请求封装类
[System.Serializable]
public class AuctionRpcSalePrepareAskWraper
{

	//构造函数
	public AuctionRpcSalePrepareAskWraper()
	{
		 m_ItemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSalePrepareAsk ToPB()
	{
		AuctionRpcSalePrepareAsk v = new AuctionRpcSalePrepareAsk();
		v.ItemId = m_ItemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSalePrepareAsk v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSalePrepareAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSalePrepareAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSalePrepareAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//预上架物品ID
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}


};
//预上架回应封装类
[System.Serializable]
public class AuctionRpcSalePrepareReplyWraper
{

	//构造函数
	public AuctionRpcSalePrepareReplyWraper()
	{
		 m_Result = -1;
		 m_ItemId = -1;
		 m_BasePrice = 0;
		m_GoldGroup = new List<int>();
		m_DiamondGroup = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemId = -1;
		 m_BasePrice = 0;
		m_GoldGroup = new List<int>();
		m_DiamondGroup = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcSalePrepareReply ToPB()
	{
		AuctionRpcSalePrepareReply v = new AuctionRpcSalePrepareReply();
		v.Result = m_Result;
		v.ItemId = m_ItemId;
		v.BasePrice = m_BasePrice;
		for (int i=0; i<(int)m_GoldGroup.Count; i++)
			v.GoldGroup.Add( m_GoldGroup[i]);
		for (int i=0; i<(int)m_DiamondGroup.Count; i++)
			v.DiamondGroup.Add( m_DiamondGroup[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcSalePrepareReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemId = v.ItemId;
		m_BasePrice = v.BasePrice;
		m_GoldGroup.Clear();
		for( int i=0; i<v.GoldGroup.Count; i++)
			m_GoldGroup.Add(v.GoldGroup[i]);
		m_DiamondGroup.Clear();
		for( int i=0; i<v.DiamondGroup.Count; i++)
			m_DiamondGroup.Add(v.DiamondGroup[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcSalePrepareReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcSalePrepareReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcSalePrepareReply>(protoMS);
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
	//商品ID 
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//基准价
	public int m_BasePrice;
	public int BasePrice
	{
		get { return m_BasePrice;}
		set { m_BasePrice = value; }
	}
	//GoldGroup
	public List<int> m_GoldGroup;
	public int SizeGoldGroup()
	{
		return m_GoldGroup.Count;
	}
	public List<int> GetGoldGroup()
	{
		return m_GoldGroup;
	}
	public int GetGoldGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_GoldGroup.Count)
			return -1;
		return m_GoldGroup[Index];
	}
	public void SetGoldGroup( List<int> v )
	{
		m_GoldGroup=v;
	}
	public void SetGoldGroup( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GoldGroup.Count)
			return;
		m_GoldGroup[Index] = v;
	}
	public void AddGoldGroup( int v=-1 )
	{
		m_GoldGroup.Add(v);
	}
	public void ClearGoldGroup( )
	{
		m_GoldGroup.Clear();
	}
	//DiamondGroup
	public List<int> m_DiamondGroup;
	public int SizeDiamondGroup()
	{
		return m_DiamondGroup.Count;
	}
	public List<int> GetDiamondGroup()
	{
		return m_DiamondGroup;
	}
	public int GetDiamondGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_DiamondGroup.Count)
			return -1;
		return m_DiamondGroup[Index];
	}
	public void SetDiamondGroup( List<int> v )
	{
		m_DiamondGroup=v;
	}
	public void SetDiamondGroup( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_DiamondGroup.Count)
			return;
		m_DiamondGroup[Index] = v;
	}
	public void AddDiamondGroup( int v=-1 )
	{
		m_DiamondGroup.Add(v);
	}
	public void ClearDiamondGroup( )
	{
		m_DiamondGroup.Clear();
	}


};
//取回上架物品请求封装类
[System.Serializable]
public class AuctionRpcGetItemBackAskWraper
{

	//构造函数
	public AuctionRpcGetItemBackAskWraper()
	{
		 m_ItemGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetItemBackAsk ToPB()
	{
		AuctionRpcGetItemBackAsk v = new AuctionRpcGetItemBackAsk();
		v.ItemGuid = m_ItemGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetItemBackAsk v)
	{
        if (v == null)
            return;
		m_ItemGuid = v.ItemGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetItemBackAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetItemBackAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetItemBackAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具Guid
	public UInt64 m_ItemGuid;
	public UInt64 ItemGuid
	{
		get { return m_ItemGuid;}
		set { m_ItemGuid = value; }
	}


};
//取回上架物品回应封装类
[System.Serializable]
public class AuctionRpcGetItemBackReplyWraper
{

	//构造函数
	public AuctionRpcGetItemBackReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetItemBackReply ToPB()
	{
		AuctionRpcGetItemBackReply v = new AuctionRpcGetItemBackReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetItemBackReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetItemBackReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetItemBackReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetItemBackReply>(protoMS);
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
//玩家当前拍卖列表请求封装类
[System.Serializable]
public class AuctionRpcGetMySaleListAskWraper
{

	//构造函数
	public AuctionRpcGetMySaleListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetMySaleListAsk ToPB()
	{
		AuctionRpcGetMySaleListAsk v = new AuctionRpcGetMySaleListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetMySaleListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetMySaleListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetMySaleListAsk pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetMySaleListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//玩家当前拍卖列表回应封装类
[System.Serializable]
public class AuctionRpcGetMySaleListReplyWraper
{

	//构造函数
	public AuctionRpcGetMySaleListReplyWraper()
	{
		 m_Result = -1;
		m_AuctionItem = new List<AuctionItemWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_AuctionItem = new List<AuctionItemWraper>();

	}

 	//转化成Protobuffer类型函数
	public AuctionRpcGetMySaleListReply ToPB()
	{
		AuctionRpcGetMySaleListReply v = new AuctionRpcGetMySaleListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_AuctionItem.Count; i++)
			v.AuctionItem.Add( m_AuctionItem[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRpcGetMySaleListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AuctionItem.Clear();
		for( int i=0; i<v.AuctionItem.Count; i++)
			m_AuctionItem.Add( new AuctionItemWraper());
		for( int i=0; i<v.AuctionItem.Count; i++)
			m_AuctionItem[i].FromPB(v.AuctionItem[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRpcGetMySaleListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRpcGetMySaleListReply pb = ProtoBuf.Serializer.Deserialize<AuctionRpcGetMySaleListReply>(protoMS);
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
	//道具信息
	public List<AuctionItemWraper> m_AuctionItem;
	public int SizeAuctionItem()
	{
		return m_AuctionItem.Count;
	}
	public List<AuctionItemWraper> GetAuctionItem()
	{
		return m_AuctionItem;
	}
	public AuctionItemWraper GetAuctionItem(int Index)
	{
		if(Index<0 || Index>=(int)m_AuctionItem.Count)
			return new AuctionItemWraper();
		return m_AuctionItem[Index];
	}
	public void SetAuctionItem( List<AuctionItemWraper> v )
	{
		m_AuctionItem=v;
	}
	public void SetAuctionItem( int Index, AuctionItemWraper v )
	{
		if(Index<0 || Index>=(int)m_AuctionItem.Count)
			return;
		m_AuctionItem[Index] = v;
	}
	public void AddAuctionItem( AuctionItemWraper v )
	{
		m_AuctionItem.Add(v);
	}
	public void ClearAuctionItem( )
	{
		m_AuctionItem.Clear();
	}


};
