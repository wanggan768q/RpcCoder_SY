/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleShop.cs
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


public class ShopRPC
{
	public const int ModuleId = 33;
	
	public const int RPC_CODE_SHOP_BUYITEM_REQUEST = 3351;
	public const int RPC_CODE_SHOP_SHOPINFO_REQUEST = 3352;

	
	private static ShopRPC m_Instance = null;
	public static ShopRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ShopRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ShopData.Instance.UpdateField );
		


		return true;
	}


	/**
	*商店-->BuyItem RPC请求
	*/
	public void BuyItem(int ShopItemId, int ItemNum, ReplyHandler replyCB)
	{
		ShopRpcBuyItemAskWraper askPBWraper = new ShopRpcBuyItemAskWraper();
		askPBWraper.ShopItemId = ShopItemId;
		askPBWraper.ItemNum = ItemNum;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SHOP_BUYITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ShopRpcBuyItemReplyWraper replyPBWraper = new ShopRpcBuyItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*商店-->ShopInfo RPC请求
	*/
	public void ShopInfo(int RoleID, ReplyHandler replyCB)
	{
		ShopRpcShopInfoAskWraper askPBWraper = new ShopRpcShopInfoAskWraper();
		askPBWraper.RoleID = RoleID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SHOP_SHOPINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ShopRpcShopInfoReplyWraper replyPBWraper = new ShopRpcShopInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class ShopData
{
	public enum SyncIdE
	{

	}
	
	private static ShopData m_Instance = null;
	public static ShopData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ShopData();
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
			Ex.Logger.Log("ShopData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
