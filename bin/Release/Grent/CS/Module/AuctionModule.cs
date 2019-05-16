/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleAuction.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class AuctionRPC
{
	public const int ModuleId = 52;
	
	public const int RPC_CODE_AUCTION_AUCTIONINFO_REQUEST = 5251;
	public const int RPC_CODE_AUCTION_SELLITEM_REQUEST = 5252;
	public const int RPC_CODE_AUCTION_SELLAGAIN_REQUEST = 5253;
	public const int RPC_CODE_AUCTION_BUY_REQUEST = 5254;
	public const int RPC_CODE_AUCTION_GETITEM_REQUEST = 5255;
	public const int RPC_CODE_AUCTION_RECORD_REQUEST = 5256;
	public const int RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST = 5257;
	public const int RPC_CODE_AUCTION_SALEPREPARE_REQUEST = 5258;
	public const int RPC_CODE_AUCTION_GETITEMBACK_REQUEST = 5259;
	public const int RPC_CODE_AUCTION_GETMYSALELIST_REQUEST = 5260;

	
	private static AuctionRPC m_Instance = null;
	public static AuctionRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new AuctionRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, AuctionData.Instance.UpdateField );
		


		return true;
	}


	/**
	*拍卖行-->查询拍卖行信息 RPC请求
	*/
	public void AuctionInfo(int ItemId, int QueueType, int CurPage, ReplyHandler replyCB)
	{
		AuctionRpcAuctionInfoAskWraper askPBWraper = new AuctionRpcAuctionInfoAskWraper();
		askPBWraper.ItemId = ItemId;
		askPBWraper.QueueType = QueueType;
		askPBWraper.CurPage = CurPage;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_AUCTIONINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcAuctionInfoReplyWraper replyPBWraper = new AuctionRpcAuctionInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->请求上架 RPC请求
	*/
	public void SellItem(UInt64 ItemGuid, int ItemId, int Price, int Currency, int Count, ReplyHandler replyCB)
	{
		AuctionRpcSellItemAskWraper askPBWraper = new AuctionRpcSellItemAskWraper();
		askPBWraper.ItemGuid = ItemGuid;
		askPBWraper.ItemId = ItemId;
		askPBWraper.Price = Price;
		askPBWraper.Currency = Currency;
		askPBWraper.Count = Count;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_SELLITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcSellItemReplyWraper replyPBWraper = new AuctionRpcSellItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->重新上架 RPC请求
	*/
	public void SellAgain(UInt64 ItemGuid, int Price, ReplyHandler replyCB)
	{
		AuctionRpcSellAgainAskWraper askPBWraper = new AuctionRpcSellAgainAskWraper();
		askPBWraper.ItemGuid = ItemGuid;
		askPBWraper.Price = Price;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_SELLAGAIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcSellAgainReplyWraper replyPBWraper = new AuctionRpcSellAgainReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->购买 RPC请求
	*/
	public void Buy(UInt64 ItemGuid, int Count, ReplyHandler replyCB)
	{
		AuctionRpcBuyAskWraper askPBWraper = new AuctionRpcBuyAskWraper();
		askPBWraper.ItemGuid = ItemGuid;
		askPBWraper.Count = Count;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_BUY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcBuyReplyWraper replyPBWraper = new AuctionRpcBuyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->取回拍卖道具 RPC请求
	*/
	public void GetItem(List<UInt64> BuyRecGuid, List<UInt64> SaleRecGuid, ReplyHandler replyCB)
	{
		AuctionRpcGetItemAskWraper askPBWraper = new AuctionRpcGetItemAskWraper();
		askPBWraper.SetBuyRecGuid(BuyRecGuid);
		askPBWraper.SetSaleRecGuid(SaleRecGuid);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_GETITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcGetItemReplyWraper replyPBWraper = new AuctionRpcGetItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->交易记录 RPC请求
	*/
	public void Record(ReplyHandler replyCB)
	{
		AuctionRpcRecordAskWraper askPBWraper = new AuctionRpcRecordAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_RECORD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcRecordReplyWraper replyPBWraper = new AuctionRpcRecordReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->按类别查询简单信息 RPC请求
	*/
	public void ItemInfoByClass(int ItemClass, List<int> ItemId, int ItemSubClass, int Prof, int Level, ReplyHandler replyCB)
	{
		AuctionRpcItemInfoByClassAskWraper askPBWraper = new AuctionRpcItemInfoByClassAskWraper();
		askPBWraper.ItemClass = ItemClass;
		askPBWraper.SetItemId(ItemId);
		askPBWraper.ItemSubClass = ItemSubClass;
		askPBWraper.Prof = Prof;
		askPBWraper.Level = Level;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcItemInfoByClassReplyWraper replyPBWraper = new AuctionRpcItemInfoByClassReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->预上架 RPC请求
	*/
	public void SalePrepare(int ItemId, ReplyHandler replyCB)
	{
		AuctionRpcSalePrepareAskWraper askPBWraper = new AuctionRpcSalePrepareAskWraper();
		askPBWraper.ItemId = ItemId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_SALEPREPARE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcSalePrepareReplyWraper replyPBWraper = new AuctionRpcSalePrepareReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->取回上架物品 RPC请求
	*/
	public void GetItemBack(UInt64 ItemGuid, ReplyHandler replyCB)
	{
		AuctionRpcGetItemBackAskWraper askPBWraper = new AuctionRpcGetItemBackAskWraper();
		askPBWraper.ItemGuid = ItemGuid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_GETITEMBACK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcGetItemBackReplyWraper replyPBWraper = new AuctionRpcGetItemBackReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*拍卖行-->玩家当前拍卖列表 RPC请求
	*/
	public void GetMySaleList(ReplyHandler replyCB)
	{
		AuctionRpcGetMySaleListAskWraper askPBWraper = new AuctionRpcGetMySaleListAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_AUCTION_GETMYSALELIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuctionRpcGetMySaleListReplyWraper replyPBWraper = new AuctionRpcGetMySaleListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class AuctionData
{
	public enum SyncIdE
	{

	}
	
	private static AuctionData m_Instance = null;
	public static AuctionData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new AuctionData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Ex.Logger.Log("AuctionData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
