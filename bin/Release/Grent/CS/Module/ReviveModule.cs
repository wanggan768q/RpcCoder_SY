/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleRevive.cs
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


public class ReviveRPC
{
	public const int ModuleId = 35;
	
	public const int RPC_CODE_REVIVE_DIENOTIFY_NOTIFY = 3551;
	public const int RPC_CODE_REVIVE_SCENEREVIVE_REQUEST = 3552;

	
	private static ReviveRPC m_Instance = null;
	public static ReviveRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ReviveRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ReviveData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_REVIVE_DIENOTIFY_NOTIFY, DieNotifyCB);


		return true;
	}


	/**
	*复活-->请求复活 RPC请求
	*/
	public void SceneRevive(int ReviveType, ReplyHandler replyCB)
	{
		ReviveRpcSceneReviveAskWraper askPBWraper = new ReviveRpcSceneReviveAskWraper();
		askPBWraper.ReviveType = ReviveType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_REVIVE_SCENEREVIVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ReviveRpcSceneReviveReplyWraper replyPBWraper = new ReviveRpcSceneReviveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyMsg.MsgNum==1?true:false,replyPBWraper);
		});
	}


	/**
	*复活-->死亡信息 服务器通知回调
	*/
	public static void DieNotifyCB( ModMessage notifyMsg )
	{
		ReviveRpcDieNotifyNotifyWraper notifyPBWraper = new ReviveRpcDieNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DieNotifyCBDelegate != null )
			DieNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DieNotifyCBDelegate = null;



}

public class ReviveData
{
	public enum SyncIdE
	{

	}
	
	private static ReviveData m_Instance = null;
	public static ReviveData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ReviveData();
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
			Ex.Logger.Log("ReviveData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
