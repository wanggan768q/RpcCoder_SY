/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEventNpc.cs
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


public class EventNpcRPC
{
	public const int ModuleId = 37;
	
	public const int RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST = 3751;
	public const int RPC_CODE_EVENTNPC_ENDEVENT_REQUEST = 3752;
	public const int RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY = 3753;

	
	private static EventNpcRPC m_Instance = null;
	public static EventNpcRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventNpcRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EventNpcData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY, ActivityBeginCB);


		return true;
	}


	/**
	*可交互的怪 -->开始交互 RPC请求
	*/
	public void BeginEvent(int EventIndex, ReplyHandler replyCB)
	{
		EventNpcRpcBeginEventAskWraper askPBWraper = new EventNpcRpcBeginEventAskWraper();
		askPBWraper.EventIndex = EventIndex;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EventNpcRpcBeginEventReplyWraper replyPBWraper = new EventNpcRpcBeginEventReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*可交互的怪 -->交互结束 RPC请求
	*/
	public void EndEvent(ReplyHandler replyCB)
	{
		EventNpcRpcEndEventAskWraper askPBWraper = new EventNpcRpcEndEventAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EVENTNPC_ENDEVENT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EventNpcRpcEndEventReplyWraper replyPBWraper = new EventNpcRpcEndEventReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*可交互的怪 -->活动开始 服务器通知回调
	*/
	public static void ActivityBeginCB( ModMessage notifyMsg )
	{
		EventNpcRpcActivityBeginNotifyWraper notifyPBWraper = new EventNpcRpcActivityBeginNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ActivityBeginCBDelegate != null )
			ActivityBeginCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ActivityBeginCBDelegate = null;



}

public class EventNpcData
{
	public enum SyncIdE
	{

	}
	
	private static EventNpcData m_Instance = null;
	public static EventNpcData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventNpcData();
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
			Ex.Logger.Log("EventNpcData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
