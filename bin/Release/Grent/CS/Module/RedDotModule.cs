/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleRedDot.cs
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


public class RedDotRPC
{
	public const int ModuleId = 54;
	
	public const int RPC_CODE_REDDOT_SYNCREDDOT_REQUEST = 5451;
	public const int RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST = 5452;
	public const int RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY = 5453;

	
	private static RedDotRPC m_Instance = null;
	public static RedDotRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RedDotRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, RedDotData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY, UpdateRedDotCB);


		return true;
	}


	/**
	*红点系统-->同步 RPC请求
	*/
	public void SyncRedDot(ReplyHandler replyCB)
	{
		RedDotRpcSyncRedDotAskWraper askPBWraper = new RedDotRpcSyncRedDotAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_REDDOT_SYNCREDDOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			RedDotRpcSyncRedDotReplyWraper replyPBWraper = new RedDotRpcSyncRedDotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*红点系统-->删除红点 RPC请求
	*/
	public void RemoveRedDot(int Type, ReplyHandler replyCB)
	{
		RedDotRpcRemoveRedDotAskWraper askPBWraper = new RedDotRpcRemoveRedDotAskWraper();
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			RedDotRpcRemoveRedDotReplyWraper replyPBWraper = new RedDotRpcRemoveRedDotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*红点系统-->更新 服务器通知回调
	*/
	public static void UpdateRedDotCB( ModMessage notifyMsg )
	{
		RedDotRpcUpdateRedDotNotifyWraper notifyPBWraper = new RedDotRpcUpdateRedDotNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UpdateRedDotCBDelegate != null )
			UpdateRedDotCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UpdateRedDotCBDelegate = null;



}

public class RedDotData
{
	public enum SyncIdE
	{

	}
	
	private static RedDotData m_Instance = null;
	public static RedDotData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RedDotData();
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
			Ex.Logger.Log("RedDotData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
