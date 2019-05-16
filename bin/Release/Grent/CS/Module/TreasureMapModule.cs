/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleTreasureMap.cs
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


public class TreasureMapRPC
{
	public const int ModuleId = 35;
	
	public const int RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST = 3551;
	public const int RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY = 3552;

	
	private static TreasureMapRPC m_Instance = null;
	public static TreasureMapRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TreasureMapRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, TreasureMapData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY, TreasureMapChangeCB);


		return true;
	}


	/**
	*藏宝图-->同步 RPC请求
	*/
	public void TreasureMapSync(ReplyHandler replyCB)
	{
		TreasureMapRpcTreasureMapSyncAskWraper askPBWraper = new TreasureMapRpcTreasureMapSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TreasureMapRpcTreasureMapSyncReplyWraper replyPBWraper = new TreasureMapRpcTreasureMapSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*藏宝图-->变化 服务器通知回调
	*/
	public static void TreasureMapChangeCB( ModMessage notifyMsg )
	{
		TreasureMapRpcTreasureMapChangeNotifyWraper notifyPBWraper = new TreasureMapRpcTreasureMapChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TreasureMapChangeCBDelegate != null )
			TreasureMapChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TreasureMapChangeCBDelegate = null;



}

public class TreasureMapData
{
	public enum SyncIdE
	{

	}
	
	private static TreasureMapData m_Instance = null;
	public static TreasureMapData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TreasureMapData();
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
			Ex.Logger.Log("TreasureMapData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
