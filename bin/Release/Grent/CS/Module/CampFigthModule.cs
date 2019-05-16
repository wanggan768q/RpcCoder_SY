/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleCampFigth.cs
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


public class CampFigthRPC
{
	public const int ModuleId = 26;
	
	public const int RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST = 2651;
	public const int RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY = 2652;
	public const int RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY = 2653;
	public const int RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY = 2654;
	public const int RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST = 2655;
	public const int RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY = 2656;
	public const int RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST = 2657;
	public const int RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST = 2658;
	public const int RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY = 2659;
	public const int RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST = 2660;
	public const int RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST = 2661;
	public const int RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST = 2662;

	
	private static CampFigthRPC m_Instance = null;
	public static CampFigthRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CampFigthRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, CampFigthData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY, CampFightContributionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY, ObjKillBroadcastCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY, NpcBirthCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY, KillDeadInfoCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY, NewSeasonCB);


		return true;
	}


	/**
	*CampFigth-->MilitaryBroken RPC请求
	*/
	public void MilitaryBroken(int RoleID, ReplyHandler replyCB)
	{
		CampFigthRpcMilitaryBrokenAskWraper askPBWraper = new CampFigthRpcMilitaryBrokenAskWraper();
		askPBWraper.RoleID = RoleID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcMilitaryBrokenReplyWraper replyPBWraper = new CampFigthRpcMilitaryBrokenReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->GetMilitaryValue RPC请求
	*/
	public void GetMilitaryValue(int RoleID, ReplyHandler replyCB)
	{
		CampFigthRpcGetMilitaryValueAskWraper askPBWraper = new CampFigthRpcGetMilitaryValueAskWraper();
		askPBWraper.RoleID = RoleID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcGetMilitaryValueReplyWraper replyPBWraper = new CampFigthRpcGetMilitaryValueReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->Worship RPC请求
	*/
	public void Worship(int WorshipRoleID, ReplyHandler replyCB)
	{
		CampFigthRpcWorshipAskWraper askPBWraper = new CampFigthRpcWorshipAskWraper();
		askPBWraper.WorshipRoleID = WorshipRoleID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcWorshipReplyWraper replyPBWraper = new CampFigthRpcWorshipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->WorshipRank RPC请求
	*/
	public void WorshipRank(int RoleID, ReplyHandler replyCB)
	{
		CampFigthRpcWorshipRankAskWraper askPBWraper = new CampFigthRpcWorshipRankAskWraper();
		askPBWraper.RoleID = RoleID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcWorshipRankReplyWraper replyPBWraper = new CampFigthRpcWorshipRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->同步段位奖励 RPC请求
	*/
	public void SyncRankReward(ReplyHandler replyCB)
	{
		CampFigthRpcSyncRankRewardAskWraper askPBWraper = new CampFigthRpcSyncRankRewardAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcSyncRankRewardReplyWraper replyPBWraper = new CampFigthRpcSyncRankRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->获取段位奖励 RPC请求
	*/
	public void GetRankReward(int Rank, ReplyHandler replyCB)
	{
		CampFigthRpcGetRankRewardAskWraper askPBWraper = new CampFigthRpcGetRankRewardAskWraper();
		askPBWraper.Rank = Rank;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcGetRankRewardReplyWraper replyPBWraper = new CampFigthRpcGetRankRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*CampFigth-->进入战场 RPC请求
	*/
	public void EnterBattleScene(ReplyHandler replyCB)
	{
		CampFigthRpcEnterBattleSceneAskWraper askPBWraper = new CampFigthRpcEnterBattleSceneAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CampFigthRpcEnterBattleSceneReplyWraper replyPBWraper = new CampFigthRpcEnterBattleSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*CampFigth-->CampFightContribution 服务器通知回调
	*/
	public static void CampFightContributionCB( ModMessage notifyMsg )
	{
		CampFigthRpcCampFightContributionNotifyWraper notifyPBWraper = new CampFigthRpcCampFightContributionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CampFightContributionCBDelegate != null )
			CampFightContributionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CampFightContributionCBDelegate = null;
	/**
	*CampFigth-->ObjKillBroadcast 服务器通知回调
	*/
	public static void ObjKillBroadcastCB( ModMessage notifyMsg )
	{
		CampFigthRpcObjKillBroadcastNotifyWraper notifyPBWraper = new CampFigthRpcObjKillBroadcastNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ObjKillBroadcastCBDelegate != null )
			ObjKillBroadcastCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ObjKillBroadcastCBDelegate = null;
	/**
	*CampFigth-->NpcBirth 服务器通知回调
	*/
	public static void NpcBirthCB( ModMessage notifyMsg )
	{
		CampFigthRpcNpcBirthNotifyWraper notifyPBWraper = new CampFigthRpcNpcBirthNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NpcBirthCBDelegate != null )
			NpcBirthCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NpcBirthCBDelegate = null;
	/**
	*CampFigth-->KillDeadInfo 服务器通知回调
	*/
	public static void KillDeadInfoCB( ModMessage notifyMsg )
	{
		CampFigthRpcKillDeadInfoNotifyWraper notifyPBWraper = new CampFigthRpcKillDeadInfoNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( KillDeadInfoCBDelegate != null )
			KillDeadInfoCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback KillDeadInfoCBDelegate = null;
	/**
	*CampFigth-->新赛季 服务器通知回调
	*/
	public static void NewSeasonCB( ModMessage notifyMsg )
	{
		CampFigthRpcNewSeasonNotifyWraper notifyPBWraper = new CampFigthRpcNewSeasonNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewSeasonCBDelegate != null )
			NewSeasonCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewSeasonCBDelegate = null;



}

public class CampFigthData
{
	public enum SyncIdE
	{

	}
	
	private static CampFigthData m_Instance = null;
	public static CampFigthData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CampFigthData();
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
			Ex.Logger.Log("CampFigthData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
