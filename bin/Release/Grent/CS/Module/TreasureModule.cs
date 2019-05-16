/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleTreasure.cs
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


public class TreasureRPC
{
	public const int ModuleId = 32;
	
	public const int RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST = 3251;
	public const int RPC_CODE_TREASURE_TREASUREINFO_REQUEST = 3252;
	public const int RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST = 3253;
	public const int RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST = 3254;
	public const int RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST = 3255;
	public const int RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST = 3256;
	public const int RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST = 3257;
	public const int RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY = 3258;
	public const int RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST = 3259;
	public const int RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY = 3260;

	
	private static TreasureRPC m_Instance = null;
	public static TreasureRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TreasureRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, TreasureData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY, TreasureEquipedIDCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY, TreasureUnlockEquipCB);


		return true;
	}


	/**
	*珍宝阁-->珍宝阁数据 RPC请求
	*/
	public void TreasureDepotInfo(ReplyHandler replyCB)
	{
		TreasureRpcTreasureDepotInfoAskWraper askPBWraper = new TreasureRpcTreasureDepotInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureDepotInfoReplyWraper replyPBWraper = new TreasureRpcTreasureDepotInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->珍宝数据 RPC请求
	*/
	public void TreasureInfo(int Type, ReplyHandler replyCB)
	{
		TreasureRpcTreasureInfoAskWraper askPBWraper = new TreasureRpcTreasureInfoAskWraper();
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureInfoReplyWraper replyPBWraper = new TreasureRpcTreasureInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->珍宝解锁 RPC请求
	*/
	public void TreasureUnlock(int Id, int Color_Type, int Time_Type, ReplyHandler replyCB)
	{
		TreasureRpcTreasureUnlockAskWraper askPBWraper = new TreasureRpcTreasureUnlockAskWraper();
		askPBWraper.Id = Id;
		askPBWraper.Color_Type = Color_Type;
		askPBWraper.Time_Type = Time_Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureUnlockReplyWraper replyPBWraper = new TreasureRpcTreasureUnlockReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->珍宝穿戴 RPC请求
	*/
	public void TreasureEquip(int Id, int Color_Type, int Time_Type, ReplyHandler replyCB)
	{
		TreasureRpcTreasureEquipAskWraper askPBWraper = new TreasureRpcTreasureEquipAskWraper();
		askPBWraper.Id = Id;
		askPBWraper.Color_Type = Color_Type;
		askPBWraper.Time_Type = Time_Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureEquipReplyWraper replyPBWraper = new TreasureRpcTreasureEquipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->穿戴的珍宝 RPC请求
	*/
	public void TreasureEquipSyc(ReplyHandler replyCB)
	{
		TreasureRpcTreasureEquipSycAskWraper askPBWraper = new TreasureRpcTreasureEquipSycAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureEquipSycReplyWraper replyPBWraper = new TreasureRpcTreasureEquipSycReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->珍宝阁升级 RPC请求
	*/
	public void TreasureDepotLvUp(ReplyHandler replyCB)
	{
		TreasureRpcTreasureDepotLvUpAskWraper askPBWraper = new TreasureRpcTreasureDepotLvUpAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureDepotLvUpReplyWraper replyPBWraper = new TreasureRpcTreasureDepotLvUpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->卸下珍宝 RPC请求
	*/
	public void TreasureUnEquip(int Id, int Color_Type, int Time_Type, ReplyHandler replyCB)
	{
		TreasureRpcTreasureUnEquipAskWraper askPBWraper = new TreasureRpcTreasureUnEquipAskWraper();
		askPBWraper.Id = Id;
		askPBWraper.Color_Type = Color_Type;
		askPBWraper.Time_Type = Time_Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureUnEquipReplyWraper replyPBWraper = new TreasureRpcTreasureUnEquipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*珍宝阁-->续期 RPC请求
	*/
	public void TreasureDelayTime(int Id, int Color_Type, int Time_Type, ReplyHandler replyCB)
	{
		TreasureRpcTreasureDelayTimeAskWraper askPBWraper = new TreasureRpcTreasureDelayTimeAskWraper();
		askPBWraper.Id = Id;
		askPBWraper.Color_Type = Color_Type;
		askPBWraper.Time_Type = Time_Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureRpcTreasureDelayTimeReplyWraper replyPBWraper = new TreasureRpcTreasureDelayTimeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*珍宝阁-->已装备时装ID 服务器通知回调
	*/
	public static void TreasureEquipedIDCB( ModMessage notifyMsg )
	{
		TreasureRpcTreasureEquipedIDNotifyWraper notifyPBWraper = new TreasureRpcTreasureEquipedIDNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TreasureEquipedIDCBDelegate != null )
			TreasureEquipedIDCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TreasureEquipedIDCBDelegate = null;
	/**
	*珍宝阁-->解锁并穿戴 服务器通知回调
	*/
	public static void TreasureUnlockEquipCB( ModMessage notifyMsg )
	{
		TreasureRpcTreasureUnlockEquipNotifyWraper notifyPBWraper = new TreasureRpcTreasureUnlockEquipNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TreasureUnlockEquipCBDelegate != null )
			TreasureUnlockEquipCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TreasureUnlockEquipCBDelegate = null;



}

public class TreasureData
{
	public enum SyncIdE
	{

	}
	
	private static TreasureData m_Instance = null;
	public static TreasureData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TreasureData();
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
			Ex.Logger.Log("TreasureData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
