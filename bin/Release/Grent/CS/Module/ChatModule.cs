/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleChat.cs
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


public class ChatRPC
{
	public const int ModuleId = 13;
	
	public const int RPC_CODE_CHAT_CHAT_REQUEST = 1351;
	public const int RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY = 1352;
	public const int RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY = 1353;
	public const int RPC_CODE_CHAT_SAY_NOTIFY = 1354;

	
	private static ChatRPC m_Instance = null;
	public static ChatRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ChatRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ChatData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY, PushChatUpdatesCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY, PushMarqueeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CHAT_SAY_NOTIFY, SayCB);


		return true;
	}


	/**
	*Chat-->Chat RPC请求
	*/
	public void Chat(ChatMsgWraper Chat_msg, int Chat_channel, ReplyHandler replyCB)
	{
		ChatRpcChatAskWraper askPBWraper = new ChatRpcChatAskWraper();
		askPBWraper.Chat_msg = Chat_msg;
		askPBWraper.Chat_channel = Chat_channel;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CHAT_CHAT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ChatRpcChatReplyWraper replyPBWraper = new ChatRpcChatReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*Chat-->PushChatUpdates 服务器通知回调
	*/
	public static void PushChatUpdatesCB( ModMessage notifyMsg )
	{
		ChatRpcPushChatUpdatesNotifyWraper notifyPBWraper = new ChatRpcPushChatUpdatesNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PushChatUpdatesCBDelegate != null )
			PushChatUpdatesCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PushChatUpdatesCBDelegate = null;
	/**
	*Chat-->推送跑马灯 服务器通知回调
	*/
	public static void PushMarqueeCB( ModMessage notifyMsg )
	{
		ChatRpcPushMarqueeNotifyWraper notifyPBWraper = new ChatRpcPushMarqueeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( PushMarqueeCBDelegate != null )
			PushMarqueeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback PushMarqueeCBDelegate = null;
	/**
	*Chat-->玩家或NPC对象说话 服务器通知回调
	*/
	public static void SayCB( ModMessage notifyMsg )
	{
		ChatRpcSayNotifyWraper notifyPBWraper = new ChatRpcSayNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SayCBDelegate != null )
			SayCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SayCBDelegate = null;



}

public class ChatData
{
	public enum SyncIdE
	{

	}
	
	private static ChatData m_Instance = null;
	public static ChatData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ChatData();
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
			Ex.Logger.Log("ChatData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
