/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBag.cs
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


public class BagRPC
{
	public const int ModuleId = 12;
	
	public const int RPC_CODE_BAG_USEITEM_REQUEST = 1251;
	public const int RPC_CODE_BAG_SALEITEM_REQUEST = 1252;
	public const int RPC_CODE_BAG_LOCKITEM_REQUEST = 1253;
	public const int RPC_CODE_BAG_DEBLOCKING_REQUEST = 1254;
	public const int RPC_CODE_BAG_TAKEITEM_REQUEST = 1255;
	public const int RPC_CODE_BAG_TIDY_REQUEST = 1256;
	public const int RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST = 1257;
	public const int RPC_CODE_BAG_BAGCHANGE_NOTIFY = 1258;
	public const int RPC_CODE_BAG_MERGEITEM_REQUEST = 1259;
	public const int RPC_CODE_BAG_BAGSYNC_REQUEST = 1260;
	public const int RPC_CODE_BAG_ADDITEM_NOTIFY = 1261;
	public const int RPC_CODE_BAG_CONSUMEITEM_REQUEST = 1262;
	public const int RPC_CODE_BAG_ITEMCHANGE_NOTIFY = 1263;
	public const int RPC_CODE_BAG_CLICKITEM_REQUEST = 1264;

	
	private static BagRPC m_Instance = null;
	public static BagRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BagRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BagData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_BAG_BAGCHANGE_NOTIFY, BagChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_BAG_ADDITEM_NOTIFY, AddItemCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_BAG_ITEMCHANGE_NOTIFY, ItemChangeCB);


		return true;
	}


	/**
	*Bag-->UseItem RPC请求
	*/
	public void UseItem(int Count, int Pos, int BagType, ReplyHandler replyCB)
	{
		BagRpcUseItemAskWraper askPBWraper = new BagRpcUseItemAskWraper();
		askPBWraper.Count = Count;
		askPBWraper.Pos = Pos;
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_USEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcUseItemReplyWraper replyPBWraper = new BagRpcUseItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->SaleItem RPC请求
	*/
	public void SaleItem(int Pos, int Count, int BagType, ReplyHandler replyCB)
	{
		BagRpcSaleItemAskWraper askPBWraper = new BagRpcSaleItemAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.Count = Count;
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_SALEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcSaleItemReplyWraper replyPBWraper = new BagRpcSaleItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->LockItem RPC请求
	*/
	public void LockItem(int Pos, bool IsLock, int BagType, ReplyHandler replyCB)
	{
		BagRpcLockItemAskWraper askPBWraper = new BagRpcLockItemAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.IsLock = IsLock;
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_LOCKITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcLockItemReplyWraper replyPBWraper = new BagRpcLockItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->解锁背包格子 RPC请求
	*/
	public void Deblocking(int BagType, ReplyHandler replyCB)
	{
		BagRpcDeblockingAskWraper askPBWraper = new BagRpcDeblockingAskWraper();
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_DEBLOCKING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcDeblockingReplyWraper replyPBWraper = new BagRpcDeblockingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->TakeItem RPC请求
	*/
	public void TakeItem(int FromBagType, int ToBagType, int FromPos, ReplyHandler replyCB)
	{
		BagRpcTakeItemAskWraper askPBWraper = new BagRpcTakeItemAskWraper();
		askPBWraper.FromBagType = FromBagType;
		askPBWraper.ToBagType = ToBagType;
		askPBWraper.FromPos = FromPos;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_TAKEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcTakeItemReplyWraper replyPBWraper = new BagRpcTakeItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->整理 RPC请求
	*/
	public void Tidy(int BagType, ReplyHandler replyCB)
	{
		BagRpcTidyAskWraper askPBWraper = new BagRpcTidyAskWraper();
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_TIDY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcTidyReplyWraper replyPBWraper = new BagRpcTidyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->临时背包全部取回 RPC请求
	*/
	public void TakeAllBackBags(ReplyHandler replyCB)
	{
		BagRpcTakeAllBackBagsAskWraper askPBWraper = new BagRpcTakeAllBackBagsAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcTakeAllBackBagsReplyWraper replyPBWraper = new BagRpcTakeAllBackBagsReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->MergeItem RPC请求
	*/
	public void MergeItem(int Pos, int BagType, ReplyHandler replyCB)
	{
		BagRpcMergeItemAskWraper askPBWraper = new BagRpcMergeItemAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.BagType = BagType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_MERGEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcMergeItemReplyWraper replyPBWraper = new BagRpcMergeItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->背包数据初始化 RPC请求
	*/
	public void BagSync(ReplyHandler replyCB)
	{
		BagRpcBagSyncAskWraper askPBWraper = new BagRpcBagSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_BAGSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcBagSyncReplyWraper replyPBWraper = new BagRpcBagSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->根据物品id使用物品 RPC请求
	*/
	public void ConsumeItem(List<int> ConfigId, List<ItemSimpleDataWraper> ItemData, ReplyHandler replyCB)
	{
		BagRpcConsumeItemAskWraper askPBWraper = new BagRpcConsumeItemAskWraper();
		askPBWraper.SetConfigId(ConfigId);
		askPBWraper.SetItemData(ItemData);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_CONSUMEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcConsumeItemReplyWraper replyPBWraper = new BagRpcConsumeItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Bag-->点击物品 RPC请求
	*/
	public void ClickItem(UInt64 Guid, ReplyHandler replyCB)
	{
		BagRpcClickItemAskWraper askPBWraper = new BagRpcClickItemAskWraper();
		askPBWraper.Guid = Guid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_CLICKITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcClickItemReplyWraper replyPBWraper = new BagRpcClickItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*Bag-->背包数据推送 服务器通知回调
	*/
	public static void BagChangeCB( ModMessage notifyMsg )
	{
		BagRpcBagChangeNotifyWraper notifyPBWraper = new BagRpcBagChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BagChangeCBDelegate != null )
			BagChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BagChangeCBDelegate = null;
	/**
	*Bag-->新加物品 服务器通知回调
	*/
	public static void AddItemCB( ModMessage notifyMsg )
	{
		BagRpcAddItemNotifyWraper notifyPBWraper = new BagRpcAddItemNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( AddItemCBDelegate != null )
			AddItemCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback AddItemCBDelegate = null;
	/**
	*Bag-->物品改变 服务器通知回调
	*/
	public static void ItemChangeCB( ModMessage notifyMsg )
	{
		BagRpcItemChangeNotifyWraper notifyPBWraper = new BagRpcItemChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ItemChangeCBDelegate != null )
			ItemChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ItemChangeCBDelegate = null;



}

public class BagData
{
	public enum SyncIdE
	{

	}
	
	private static BagData m_Instance = null;
	public static BagData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BagData();
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
			Ex.Logger.Log("BagData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
