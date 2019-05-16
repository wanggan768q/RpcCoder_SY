/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEventObj.cs
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


public class EventObjRPC
{
	public const int ModuleId = 16;
	
	public const int RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST = 1651;
	public const int RPC_CODE_EVENTOBJ_EVENTEND_REQUEST = 1652;
	public const int RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST = 1653;
	public const int RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY = 1654;

	
	private static EventObjRPC m_Instance = null;
	public static EventObjRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventObjRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EventObjData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY, EventStopNotifyCB);


		return true;
	}


	/**
	*EventObj-->EventBegin RPC请求
	*/
	public void EventBegin(int ObjId, ReplyHandler replyCB)
	{
		EventObjRpcEventBeginAskWraper askPBWraper = new EventObjRpcEventBeginAskWraper();
		askPBWraper.ObjId = ObjId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EventObjRpcEventBeginReplyWraper replyPBWraper = new EventObjRpcEventBeginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*EventObj-->EventEnd RPC请求
	*/
	public void EventEnd(int ObjId, ReplyHandler replyCB)
	{
		EventObjRpcEventEndAskWraper askPBWraper = new EventObjRpcEventEndAskWraper();
		askPBWraper.ObjId = ObjId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EVENTOBJ_EVENTEND_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EventObjRpcEventEndReplyWraper replyPBWraper = new EventObjRpcEventEndReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*EventObj-->EventStop RPC请求
	*/
	public void EventStop(int ObjId, ReplyHandler replyCB)
	{
		EventObjRpcEventStopAskWraper askPBWraper = new EventObjRpcEventStopAskWraper();
		askPBWraper.ObjId = ObjId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EventObjRpcEventStopReplyWraper replyPBWraper = new EventObjRpcEventStopReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*EventObj-->交互停止通知 服务器通知回调
	*/
	public static void EventStopNotifyCB( ModMessage notifyMsg )
	{
		EventObjRpcEventStopNotifyNotifyWraper notifyPBWraper = new EventObjRpcEventStopNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( EventStopNotifyCBDelegate != null )
			EventStopNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback EventStopNotifyCBDelegate = null;



}

public class EventObjData
{
	public enum SyncIdE
	{

	}
	
	private static EventObjData m_Instance = null;
	public static EventObjData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventObjData();
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
			Ex.Logger.Log("EventObjData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
