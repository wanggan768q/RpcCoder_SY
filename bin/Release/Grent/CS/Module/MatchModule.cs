/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleMatch.cs
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


public class MatchRPC
{
	public const int ModuleId = 39;
	
	public const int RPC_CODE_MATCH_AUTOMATCH_REQUEST = 3951;
	public const int RPC_CODE_MATCH_CANCELMATCH_REQUEST = 3952;
	public const int RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY = 3953;
	public const int RPC_CODE_MATCH_PREPAREROOM_NOTIFY = 3954;
	public const int RPC_CODE_MATCH_READY_REQUEST = 3955;
	public const int RPC_CODE_MATCH_CANCELREADY_REQUEST = 3956;
	public const int RPC_CODE_MATCH_ROOMCANCEL_NOTIFY = 3957;
	public const int RPC_CODE_MATCH_MEMBERREADY_NOTIFY = 3958;

	
	private static MatchRPC m_Instance = null;
	public static MatchRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MatchRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, MatchData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY, CancelMatchNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MATCH_PREPAREROOM_NOTIFY, PrepareRoomCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MATCH_ROOMCANCEL_NOTIFY, RoomCancelCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MATCH_MEMBERREADY_NOTIFY, MemberReadyCB);


		return true;
	}


	/**
	*匹配模块-->匹配 RPC请求
	*/
	public void AutoMatch(PlayerMatchDataWraper MatchInfo, ReplyHandler replyCB)
	{
		MatchRpcAutoMatchAskWraper askPBWraper = new MatchRpcAutoMatchAskWraper();
		askPBWraper.MatchInfo = MatchInfo;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MATCH_AUTOMATCH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchRpcAutoMatchReplyWraper replyPBWraper = new MatchRpcAutoMatchReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*匹配模块-->取消匹配 RPC请求
	*/
	public void CancelMatch(ReplyHandler replyCB)
	{
		MatchRpcCancelMatchAskWraper askPBWraper = new MatchRpcCancelMatchAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MATCH_CANCELMATCH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchRpcCancelMatchReplyWraper replyPBWraper = new MatchRpcCancelMatchReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*匹配模块-->准备 RPC请求
	*/
	public void Ready(int MatchType, UInt64 RoomId, ReplyHandler replyCB)
	{
		MatchRpcReadyAskWraper askPBWraper = new MatchRpcReadyAskWraper();
		askPBWraper.MatchType = MatchType;
		askPBWraper.RoomId = RoomId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MATCH_READY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchRpcReadyReplyWraper replyPBWraper = new MatchRpcReadyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*匹配模块-->取消准备 RPC请求
	*/
	public void CancelReady(int MatchType, UInt64 RoomId, ReplyHandler replyCB)
	{
		MatchRpcCancelReadyAskWraper askPBWraper = new MatchRpcCancelReadyAskWraper();
		askPBWraper.MatchType = MatchType;
		askPBWraper.RoomId = RoomId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MATCH_CANCELREADY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchRpcCancelReadyReplyWraper replyPBWraper = new MatchRpcCancelReadyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*匹配模块-->取消匹配通知 服务器通知回调
	*/
	public static void CancelMatchNotifyCB( ModMessage notifyMsg )
	{
		MatchRpcCancelMatchNotifyNotifyWraper notifyPBWraper = new MatchRpcCancelMatchNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CancelMatchNotifyCBDelegate != null )
			CancelMatchNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CancelMatchNotifyCBDelegate = null;
	/**
	*匹配模块-->开始准备进入房间 服务器通知回调
	*/
	public static void PrepareRoomCB( ModMessage notifyMsg )
	{
		MatchRpcPrepareRoomNotifyWraper notifyPBWraper = new MatchRpcPrepareRoomNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PrepareRoomCBDelegate != null )
			PrepareRoomCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PrepareRoomCBDelegate = null;
	/**
	*匹配模块-->房间取消 服务器通知回调
	*/
	public static void RoomCancelCB( ModMessage notifyMsg )
	{
		MatchRpcRoomCancelNotifyWraper notifyPBWraper = new MatchRpcRoomCancelNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RoomCancelCBDelegate != null )
			RoomCancelCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RoomCancelCBDelegate = null;
	/**
	*匹配模块-->成员准备 服务器通知回调
	*/
	public static void MemberReadyCB( ModMessage notifyMsg )
	{
		MatchRpcMemberReadyNotifyWraper notifyPBWraper = new MatchRpcMemberReadyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MemberReadyCBDelegate != null )
			MemberReadyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MemberReadyCBDelegate = null;



}

public class MatchData
{
	public enum SyncIdE
	{

	}
	
	private static MatchData m_Instance = null;
	public static MatchData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MatchData();
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
			Ex.Logger.Log("MatchData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
