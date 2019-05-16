/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleActivity.cs
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


public class ActivityRPC
{
	public const int ModuleId = 24;
	
	public const int RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY = 2451;
	public const int RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST = 2452;
	public const int RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY = 2453;
	public const int RPC_CODE_ACTIVITY_XINGYAO_REQUEST = 2454;
	public const int RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY = 2455;
	public const int RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST = 2456;
	public const int RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST = 2457;
	public const int RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY = 2458;
	public const int RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY = 2459;

	
	private static ActivityRPC m_Instance = null;
	public static ActivityRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ActivityRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ActivityData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY, EliteMonsterInfoCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY, OpenActivityCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY, ActivityTimeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY, XingyaoRewardCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY, OperationTimeCB);


		return true;
	}


	/**
	*活动-->生成对象 RPC请求
	*/
	public void CreateObj(int CommonId, ReplyHandler replyCB)
	{
		ActivityRpcCreateObjAskWraper askPBWraper = new ActivityRpcCreateObjAskWraper();
		askPBWraper.CommonId = CommonId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ActivityRpcCreateObjReplyWraper replyPBWraper = new ActivityRpcCreateObjReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*活动-->星耀王座进入 RPC请求
	*/
	public void Xingyao(int NPCid, ReplyHandler replyCB)
	{
		ActivityRpcXingyaoAskWraper askPBWraper = new ActivityRpcXingyaoAskWraper();
		askPBWraper.NPCid = NPCid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ACTIVITY_XINGYAO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ActivityRpcXingyaoReplyWraper replyPBWraper = new ActivityRpcXingyaoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*活动-->请求获取活动时间 RPC请求
	*/
	public void ReqActivityTime(ReplyHandler replyCB)
	{
		ActivityRpcReqActivityTimeAskWraper askPBWraper = new ActivityRpcReqActivityTimeAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ActivityRpcReqActivityTimeReplyWraper replyPBWraper = new ActivityRpcReqActivityTimeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*活动-->星耀NPC RPC请求
	*/
	public void XingyaoNPC(ReplyHandler replyCB)
	{
		ActivityRpcXingyaoNPCAskWraper askPBWraper = new ActivityRpcXingyaoNPCAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ActivityRpcXingyaoNPCReplyWraper replyPBWraper = new ActivityRpcXingyaoNPCReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*活动-->精英怪信息 服务器通知回调
	*/
	public static void EliteMonsterInfoCB( ModMessage notifyMsg )
	{
		ActivityRpcEliteMonsterInfoNotifyWraper notifyPBWraper = new ActivityRpcEliteMonsterInfoNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( EliteMonsterInfoCBDelegate != null )
			EliteMonsterInfoCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback EliteMonsterInfoCBDelegate = null;
	/**
	*活动-->活动开启前通知 服务器通知回调
	*/
	public static void OpenActivityCB( ModMessage notifyMsg )
	{
		ActivityRpcOpenActivityNotifyWraper notifyPBWraper = new ActivityRpcOpenActivityNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OpenActivityCBDelegate != null )
			OpenActivityCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OpenActivityCBDelegate = null;
	/**
	*活动-->活动时间信息 服务器通知回调
	*/
	public static void ActivityTimeCB( ModMessage notifyMsg )
	{
		ActivityRpcActivityTimeNotifyWraper notifyPBWraper = new ActivityRpcActivityTimeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ActivityTimeCBDelegate != null )
			ActivityTimeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ActivityTimeCBDelegate = null;
	/**
	*活动-->星耀高额奖励 服务器通知回调
	*/
	public static void XingyaoRewardCB( ModMessage notifyMsg )
	{
		ActivityRpcXingyaoRewardNotifyWraper notifyPBWraper = new ActivityRpcXingyaoRewardNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( XingyaoRewardCBDelegate != null )
			XingyaoRewardCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback XingyaoRewardCBDelegate = null;
	/**
	*活动-->operation活动表时间 服务器通知回调
	*/
	public static void OperationTimeCB( ModMessage notifyMsg )
	{
		ActivityRpcOperationTimeNotifyWraper notifyPBWraper = new ActivityRpcOperationTimeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OperationTimeCBDelegate != null )
			OperationTimeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OperationTimeCBDelegate = null;



}

public class ActivityData
{
	public enum SyncIdE
	{

	}
	
	private static ActivityData m_Instance = null;
	public static ActivityData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ActivityData();
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
			Ex.Logger.Log("ActivityData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
