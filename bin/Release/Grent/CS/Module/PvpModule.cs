/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModulePvp.cs
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


public class PvpRPC
{
	public const int ModuleId = 34;
	
	public const int RPC_CODE_PVP_RANK_REQUEST = 3451;
	public const int RPC_CODE_PVP_MATCH_REQUEST = 3452;
	public const int RPC_CODE_PVP_MATCHNOTIFY_NOTIFY = 3453;
	public const int RPC_CODE_PVP_MATCHCANCLE_REQUEST = 3454;
	public const int RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY = 3455;
	public const int RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST = 3456;
	public const int RPC_CODE_PVP_PVPBATTLESTART_NOTIFY = 3457;
	public const int RPC_CODE_PVP_PVPBATTLEEND_NOTIFY = 3458;
	public const int RPC_CODE_PVP_PLAYERREADY_REQUEST = 3459;
	public const int RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY = 3460;
	public const int RPC_CODE_PVP_READYFAILD_NOTIFY = 3461;
	public const int RPC_CODE_PVP_MATCHSUCESS_NOTIFY = 3462;
	public const int RPC_CODE_PVP_RANKCHANGE_NOTIFY = 3463;
	public const int RPC_CODE_PVP_RETURNLASTSCENE_REQUEST = 3464;
	public const int RPC_CODE_PVP_ARENASTARTTIME_NOTIFY = 3465;
	public const int RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY = 3466;
	public const int RPC_CODE_PVP_ARENALEFTTIME_NOTIFY = 3467;
	public const int RPC_CODE_PVP_LASTRANK_REQUEST = 3468;
	public const int RPC_CODE_PVP_NEWSEASON_NOTIFY = 3469;
	public const int RPC_CODE_PVP_GETSEASONREWARD_REQUEST = 3470;
	public const int RPC_CODE_PVP_RECONNECT_NOTIFY = 3471;
	public const int RPC_CODE_PVP_GETREWARD_REQUEST = 3472;

	
	private static PvpRPC m_Instance = null;
	public static PvpRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PvpRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, PvpData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_MATCHNOTIFY_NOTIFY, MatchNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY, MatchCancleNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_PVPBATTLESTART_NOTIFY, PvpBattleStartCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_PVPBATTLEEND_NOTIFY, PvpBattleEndCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY, PlayerReadyNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_READYFAILD_NOTIFY, ReadyFaildCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_MATCHSUCESS_NOTIFY, MatchSucessCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_RANKCHANGE_NOTIFY, RankChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_ARENASTARTTIME_NOTIFY, ArenaStartTimeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY, UpdateKillCountCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_ARENALEFTTIME_NOTIFY, ArenaLeftTimeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_NEWSEASON_NOTIFY, NewSeasonCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PVP_RECONNECT_NOTIFY, ReconnectCB);


		return true;
	}


	/**
	*Pvp-->Rank RPC请求
	*/
	public void Rank(int PvpType, ReplyHandler replyCB)
	{
		PvpRpcRankAskWraper askPBWraper = new PvpRpcRankAskWraper();
		askPBWraper.PvpType = PvpType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_RANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcRankReplyWraper replyPBWraper = new PvpRpcRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->匹配 RPC请求
	*/
	public void Match(int PvpType, ReplyHandler replyCB)
	{
		PvpRpcMatchAskWraper askPBWraper = new PvpRpcMatchAskWraper();
		askPBWraper.PvpType = PvpType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_MATCH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcMatchReplyWraper replyPBWraper = new PvpRpcMatchReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->取消匹配 RPC请求
	*/
	public void MatchCancle(ReplyHandler replyCB)
	{
		PvpRpcMatchCancleAskWraper askPBWraper = new PvpRpcMatchCancleAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_MATCHCANCLE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcMatchCancleReplyWraper replyPBWraper = new PvpRpcMatchCancleReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->请求战斗信息 RPC请求
	*/
	public void PvpBattleInfoSync(ReplyHandler replyCB)
	{
		PvpRpcPvpBattleInfoSyncAskWraper askPBWraper = new PvpRpcPvpBattleInfoSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcPvpBattleInfoSyncReplyWraper replyPBWraper = new PvpRpcPvpBattleInfoSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->PlayerReady RPC请求
	*/
	public void PlayerReady(int OpreationType, ReplyHandler replyCB)
	{
		PvpRpcPlayerReadyAskWraper askPBWraper = new PvpRpcPlayerReadyAskWraper();
		askPBWraper.OpreationType = OpreationType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_PLAYERREADY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcPlayerReadyReplyWraper replyPBWraper = new PvpRpcPlayerReadyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->返回 RPC请求
	*/
	public void ReturnLastScene(ReplyHandler replyCB)
	{
		PvpRpcReturnLastSceneAskWraper askPBWraper = new PvpRpcReturnLastSceneAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_RETURNLASTSCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcReturnLastSceneReplyWraper replyPBWraper = new PvpRpcReturnLastSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->上个赛季的排行 RPC请求
	*/
	public void LastRank(int PvpType, ReplyHandler replyCB)
	{
		PvpRpcLastRankAskWraper askPBWraper = new PvpRpcLastRankAskWraper();
		askPBWraper.PvpType = PvpType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_LASTRANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcLastRankReplyWraper replyPBWraper = new PvpRpcLastRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->领取奖励 RPC请求
	*/
	public void GetSeasonReward(ReplyHandler replyCB)
	{
		PvpRpcGetSeasonRewardAskWraper askPBWraper = new PvpRpcGetSeasonRewardAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_GETSEASONREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcGetSeasonRewardReplyWraper replyPBWraper = new PvpRpcGetSeasonRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Pvp-->获取奖励 RPC请求
	*/
	public void GetReward(int PvPType, int Rank, ReplyHandler replyCB)
	{
		PvpRpcGetRewardAskWraper askPBWraper = new PvpRpcGetRewardAskWraper();
		askPBWraper.PvPType = PvPType;
		askPBWraper.Rank = Rank;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PVP_GETREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PvpRpcGetRewardReplyWraper replyPBWraper = new PvpRpcGetRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*Pvp-->匹配的通知 服务器通知回调
	*/
	public static void MatchNotifyCB( ModMessage notifyMsg )
	{
		PvpRpcMatchNotifyNotifyWraper notifyPBWraper = new PvpRpcMatchNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MatchNotifyCBDelegate != null )
			MatchNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MatchNotifyCBDelegate = null;
	/**
	*Pvp-->取消匹配通知 服务器通知回调
	*/
	public static void MatchCancleNotifyCB( ModMessage notifyMsg )
	{
		PvpRpcMatchCancleNotifyNotifyWraper notifyPBWraper = new PvpRpcMatchCancleNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MatchCancleNotifyCBDelegate != null )
			MatchCancleNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MatchCancleNotifyCBDelegate = null;
	/**
	*Pvp-->PvpBattleStart 服务器通知回调
	*/
	public static void PvpBattleStartCB( ModMessage notifyMsg )
	{
		PvpRpcPvpBattleStartNotifyWraper notifyPBWraper = new PvpRpcPvpBattleStartNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PvpBattleStartCBDelegate != null )
			PvpBattleStartCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PvpBattleStartCBDelegate = null;
	/**
	*Pvp-->PvpBattleEnd 服务器通知回调
	*/
	public static void PvpBattleEndCB( ModMessage notifyMsg )
	{
		PvpRpcPvpBattleEndNotifyWraper notifyPBWraper = new PvpRpcPvpBattleEndNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PvpBattleEndCBDelegate != null )
			PvpBattleEndCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PvpBattleEndCBDelegate = null;
	/**
	*Pvp-->玩家准备的通知 服务器通知回调
	*/
	public static void PlayerReadyNotifyCB( ModMessage notifyMsg )
	{
		PvpRpcPlayerReadyNotifyNotifyWraper notifyPBWraper = new PvpRpcPlayerReadyNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PlayerReadyNotifyCBDelegate != null )
			PlayerReadyNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PlayerReadyNotifyCBDelegate = null;
	/**
	*Pvp-->等待确认超时 服务器通知回调
	*/
	public static void ReadyFaildCB( ModMessage notifyMsg )
	{
		PvpRpcReadyFaildNotifyWraper notifyPBWraper = new PvpRpcReadyFaildNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReadyFaildCBDelegate != null )
			ReadyFaildCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReadyFaildCBDelegate = null;
	/**
	*Pvp-->匹配完成 服务器通知回调
	*/
	public static void MatchSucessCB( ModMessage notifyMsg )
	{
		PvpRpcMatchSucessNotifyWraper notifyPBWraper = new PvpRpcMatchSucessNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MatchSucessCBDelegate != null )
			MatchSucessCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MatchSucessCBDelegate = null;
	/**
	*Pvp-->段位变化 服务器通知回调
	*/
	public static void RankChangeCB( ModMessage notifyMsg )
	{
		PvpRpcRankChangeNotifyWraper notifyPBWraper = new PvpRpcRankChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RankChangeCBDelegate != null )
			RankChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RankChangeCBDelegate = null;
	/**
	*Pvp-->通知开始时间 服务器通知回调
	*/
	public static void ArenaStartTimeCB( ModMessage notifyMsg )
	{
		PvpRpcArenaStartTimeNotifyWraper notifyPBWraper = new PvpRpcArenaStartTimeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ArenaStartTimeCBDelegate != null )
			ArenaStartTimeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ArenaStartTimeCBDelegate = null;
	/**
	*Pvp-->更新击杀数量 服务器通知回调
	*/
	public static void UpdateKillCountCB( ModMessage notifyMsg )
	{
		PvpRpcUpdateKillCountNotifyWraper notifyPBWraper = new PvpRpcUpdateKillCountNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UpdateKillCountCBDelegate != null )
			UpdateKillCountCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UpdateKillCountCBDelegate = null;
	/**
	*Pvp-->剩余时间 服务器通知回调
	*/
	public static void ArenaLeftTimeCB( ModMessage notifyMsg )
	{
		PvpRpcArenaLeftTimeNotifyWraper notifyPBWraper = new PvpRpcArenaLeftTimeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ArenaLeftTimeCBDelegate != null )
			ArenaLeftTimeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ArenaLeftTimeCBDelegate = null;
	/**
	*Pvp-->新赛季通知 服务器通知回调
	*/
	public static void NewSeasonCB( ModMessage notifyMsg )
	{
		PvpRpcNewSeasonNotifyWraper notifyPBWraper = new PvpRpcNewSeasonNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewSeasonCBDelegate != null )
			NewSeasonCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewSeasonCBDelegate = null;
	/**
	*Pvp-->重连 服务器通知回调
	*/
	public static void ReconnectCB( ModMessage notifyMsg )
	{
		PvpRpcReconnectNotifyWraper notifyPBWraper = new PvpRpcReconnectNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReconnectCBDelegate != null )
			ReconnectCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReconnectCBDelegate = null;



}

public class PvpData
{
	public enum SyncIdE
	{

	}
	
	private static PvpData m_Instance = null;
	public static PvpData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PvpData();
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
			Ex.Logger.Log("PvpData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
