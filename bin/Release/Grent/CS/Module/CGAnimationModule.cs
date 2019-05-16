/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleCGAnimation.cs
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


public class CGAnimationRPC
{
	public const int ModuleId = 29;
	
	public const int RPC_CODE_CGANIMATION_CGPLAY_REQUEST = 2951;
	public const int RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY = 2952;
	public const int RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY = 2953;
	public const int RPC_CODE_CGANIMATION_CGSKIP_REQUEST = 2954;
	public const int RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY = 2955;

	
	private static CGAnimationRPC m_Instance = null;
	public static CGAnimationRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CGAnimationRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, CGAnimationData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY, CgPlayNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY, CgOverNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY, ScriptPlayCB);


		return true;
	}


	/**
	*动画播放模块-->动画开始播放 RPC请求
	*/
	public void CgPlay(int CgId, ReplyHandler replyCB)
	{
		CGAnimationRpcCgPlayAskWraper askPBWraper = new CGAnimationRpcCgPlayAskWraper();
		askPBWraper.CgId = CgId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CGANIMATION_CGPLAY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CGAnimationRpcCgPlayReplyWraper replyPBWraper = new CGAnimationRpcCgPlayReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*动画播放模块-->跳过CG RPC请求
	*/
	public void CgSkip(ReplyHandler replyCB)
	{
		CGAnimationRpcCgSkipAskWraper askPBWraper = new CGAnimationRpcCgSkipAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CGANIMATION_CGSKIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CGAnimationRpcCgSkipReplyWraper replyPBWraper = new CGAnimationRpcCgSkipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*动画播放模块-->通知 服务器通知回调
	*/
	public static void CgPlayNotifyCB( ModMessage notifyMsg )
	{
		CGAnimationRpcCgPlayNotifyNotifyWraper notifyPBWraper = new CGAnimationRpcCgPlayNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CgPlayNotifyCBDelegate != null )
			CgPlayNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CgPlayNotifyCBDelegate = null;
	/**
	*动画播放模块-->结束通知 服务器通知回调
	*/
	public static void CgOverNotifyCB( ModMessage notifyMsg )
	{
		CGAnimationRpcCgOverNotifyNotifyWraper notifyPBWraper = new CGAnimationRpcCgOverNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CgOverNotifyCBDelegate != null )
			CgOverNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CgOverNotifyCBDelegate = null;
	/**
	*动画播放模块-->脚本播放 服务器通知回调
	*/
	public static void ScriptPlayCB( ModMessage notifyMsg )
	{
		CGAnimationRpcScriptPlayNotifyWraper notifyPBWraper = new CGAnimationRpcScriptPlayNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ScriptPlayCBDelegate != null )
			ScriptPlayCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ScriptPlayCBDelegate = null;



}

public class CGAnimationData
{
	public enum SyncIdE
	{

	}
	
	private static CGAnimationData m_Instance = null;
	public static CGAnimationData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CGAnimationData();
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
			Ex.Logger.Log("CGAnimationData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
