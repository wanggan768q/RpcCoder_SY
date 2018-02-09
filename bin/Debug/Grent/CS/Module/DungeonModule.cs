/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleDungeon.cs
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


public class DungeonRPC
{
	public const int ModuleId = 6;
	
	public const int RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST = 651;
	public const int RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST = 652;
	public const int RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST = 653;
	public const int RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654;
	public const int RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY = 655;

	
	private static DungeonRPC m_Instance = null;
	public static DungeonRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new DungeonRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, DungeonData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY, SettlementCB);


		return true;
	}


	/**
	*副本-->CreateDungeon RPC请求
	*/
	public void CreateDungeon(UInt64 RoleId, int DungeonConfigId, ReplyHandler replyCB)
	{
		DungeonRpcCreateDungeonAskWraper askPBWraper = new DungeonRpcCreateDungeonAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.DungeonConfigId = DungeonConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			DungeonRpcCreateDungeonReplyWraper replyPBWraper = new DungeonRpcCreateDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*副本-->退出副本 RPC请求
	*/
	public void ExitDungeon(UInt64 RoleId, int SceneId, ReplyHandler replyCB)
	{
		DungeonRpcExitDungeonAskWraper askPBWraper = new DungeonRpcExitDungeonAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			DungeonRpcExitDungeonReplyWraper replyPBWraper = new DungeonRpcExitDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*副本-->进入副本通知 RPC请求
	*/
	public void EnterDungeon(int SceneId, int DungeonConfigId, ReplyHandler replyCB)
	{
		DungeonRpcEnterDungeonAskWraper askPBWraper = new DungeonRpcEnterDungeonAskWraper();
		askPBWraper.SceneId = SceneId;
		askPBWraper.DungeonConfigId = DungeonConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			DungeonRpcEnterDungeonReplyWraper replyPBWraper = new DungeonRpcEnterDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*副本-->队长创建副本以后通知我 RPC请求
	*/
	public void InformCreateDungeon(UInt64 RoleId, int TargetSceneId, int DungeonConfigId, int CurSceneId, int Result, List<UInt64> RoleIds, ReplyHandler replyCB)
	{
		DungeonRpcInformCreateDungeonAskWraper askPBWraper = new DungeonRpcInformCreateDungeonAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.TargetSceneId = TargetSceneId;
		askPBWraper.DungeonConfigId = DungeonConfigId;
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.Result = Result;
		askPBWraper.SetRoleIds(RoleIds);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			DungeonRpcInformCreateDungeonReplyWraper replyPBWraper = new DungeonRpcInformCreateDungeonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*副本-->Settlement 服务器通知回调
	*/
	public static void SettlementCB( ModMessage notifyMsg )
	{
		DungeonRpcSettlementNotifyWraper notifyPBWraper = new DungeonRpcSettlementNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SettlementCBDelegate != null )
			SettlementCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SettlementCBDelegate = null;



}

public class DungeonData
{
	public enum SyncIdE
	{

	}
	
	private static DungeonData m_Instance = null;
	public static DungeonData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new DungeonData();
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
			Ex.Logger.Log("DungeonData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
