/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleExpressionAction.cs
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


public class ExpressionActionRPC
{
	public const int ModuleId = 49;
	
	public const int RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST = 4951;
	public const int RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST = 4952;
	public const int RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST = 4953;
	public const int RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY = 4954;

	
	private static ExpressionActionRPC m_Instance = null;
	public static ExpressionActionRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ExpressionActionRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ExpressionActionData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY, UseActionNotifyCB);


		return true;
	}


	/**
	*表情动作-->数据同步 RPC请求
	*/
	public void Sync(ReplyHandler replyCB)
	{
		ExpressionActionRpcSyncAskWraper askPBWraper = new ExpressionActionRpcSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ExpressionActionRpcSyncReplyWraper replyPBWraper = new ExpressionActionRpcSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*表情动作-->设置轮盘 RPC请求
	*/
	public void SetWheel(int Index, int ActionId, ReplyHandler replyCB)
	{
		ExpressionActionRpcSetWheelAskWraper askPBWraper = new ExpressionActionRpcSetWheelAskWraper();
		askPBWraper.Index = Index;
		askPBWraper.ActionId = ActionId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ExpressionActionRpcSetWheelReplyWraper replyPBWraper = new ExpressionActionRpcSetWheelReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*表情动作-->使用表情 RPC请求
	*/
	public void UseAction(int ActionId, ReplyHandler replyCB)
	{
		ExpressionActionRpcUseActionAskWraper askPBWraper = new ExpressionActionRpcUseActionAskWraper();
		askPBWraper.ActionId = ActionId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ExpressionActionRpcUseActionReplyWraper replyPBWraper = new ExpressionActionRpcUseActionReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*表情动作-->使用表情通知 服务器通知回调
	*/
	public static void UseActionNotifyCB( ModMessage notifyMsg )
	{
		ExpressionActionRpcUseActionNotifyNotifyWraper notifyPBWraper = new ExpressionActionRpcUseActionNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UseActionNotifyCBDelegate != null )
			UseActionNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UseActionNotifyCBDelegate = null;



}

public class ExpressionActionData
{
	public enum SyncIdE
	{

	}
	
	private static ExpressionActionData m_Instance = null;
	public static ExpressionActionData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ExpressionActionData();
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
			Ex.Logger.Log("ExpressionActionData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
