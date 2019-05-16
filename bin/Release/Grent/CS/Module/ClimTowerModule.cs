/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleClimTower.cs
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


public class ClimTowerRPC
{
	public const int ModuleId = 47;
	
	public const int RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY = 4751;
	public const int RPC_CODE_CLIMTOWER_ENTER_REQUEST = 4752;
	public const int RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST = 4753;
	public const int RPC_CODE_CLIMTOWER_RANK_REQUEST = 4754;
	public const int RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST = 4755;
	public const int RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY = 4756;
	public const int RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY = 4757;
	public const int RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY = 4758;

	
	private static ClimTowerRPC m_Instance = null;
	public static ClimTowerRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ClimTowerRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ClimTowerData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY, OpenRuleCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY, NextLayerCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY, ChallengeEndCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY, WaveRefreshCB);


		return true;
	}


	/**
	*爬塔玩法-->进入爬塔活动 RPC请求
	*/
	public void Enter(ReplyHandler replyCB)
	{
		ClimTowerRpcEnterAskWraper askPBWraper = new ClimTowerRpcEnterAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CLIMTOWER_ENTER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ClimTowerRpcEnterReplyWraper replyPBWraper = new ClimTowerRpcEnterReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*爬塔玩法-->挑战 RPC请求
	*/
	public void Challenge(int Layer, ReplyHandler replyCB)
	{
		ClimTowerRpcChallengeAskWraper askPBWraper = new ClimTowerRpcChallengeAskWraper();
		askPBWraper.Layer = Layer;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ClimTowerRpcChallengeReplyWraper replyPBWraper = new ClimTowerRpcChallengeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*爬塔玩法-->获取排行榜信息 RPC请求
	*/
	public void Rank(ReplyHandler replyCB)
	{
		ClimTowerRpcRankAskWraper askPBWraper = new ClimTowerRpcRankAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CLIMTOWER_RANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ClimTowerRpcRankReplyWraper replyPBWraper = new ClimTowerRpcRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*爬塔玩法-->首次通关奖励领奖 RPC请求
	*/
	public void FirstVicReward(int Layer, ReplyHandler replyCB)
	{
		ClimTowerRpcFirstVicRewardAskWraper askPBWraper = new ClimTowerRpcFirstVicRewardAskWraper();
		askPBWraper.Layer = Layer;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ClimTowerRpcFirstVicRewardReplyWraper replyPBWraper = new ClimTowerRpcFirstVicRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*爬塔玩法-->玩法开启规则 服务器通知回调
	*/
	public static void OpenRuleCB( ModMessage notifyMsg )
	{
		ClimTowerRpcOpenRuleNotifyWraper notifyPBWraper = new ClimTowerRpcOpenRuleNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OpenRuleCBDelegate != null )
			OpenRuleCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OpenRuleCBDelegate = null;
	/**
	*爬塔玩法-->下一层通知 服务器通知回调
	*/
	public static void NextLayerCB( ModMessage notifyMsg )
	{
		ClimTowerRpcNextLayerNotifyWraper notifyPBWraper = new ClimTowerRpcNextLayerNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NextLayerCBDelegate != null )
			NextLayerCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NextLayerCBDelegate = null;
	/**
	*爬塔玩法-->挑战结束 服务器通知回调
	*/
	public static void ChallengeEndCB( ModMessage notifyMsg )
	{
		ClimTowerRpcChallengeEndNotifyWraper notifyPBWraper = new ClimTowerRpcChallengeEndNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ChallengeEndCBDelegate != null )
			ChallengeEndCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ChallengeEndCBDelegate = null;
	/**
	*爬塔玩法-->每波怪物刷新通知 服务器通知回调
	*/
	public static void WaveRefreshCB( ModMessage notifyMsg )
	{
		ClimTowerRpcWaveRefreshNotifyWraper notifyPBWraper = new ClimTowerRpcWaveRefreshNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( WaveRefreshCBDelegate != null )
			WaveRefreshCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback WaveRefreshCBDelegate = null;



}

public class ClimTowerData
{
	public enum SyncIdE
	{

	}
	
	private static ClimTowerData m_Instance = null;
	public static ClimTowerData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ClimTowerData();
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
			Ex.Logger.Log("ClimTowerData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
