/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBulletScreen.cs
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


public class BulletScreenRPC
{
	public const int ModuleId = 50;
	
	public const int RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST = 5051;
	public const int RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST = 5052;
	public const int RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST = 5053;

	
	private static BulletScreenRPC m_Instance = null;
	public static BulletScreenRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BulletScreenRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BulletScreenData.Instance.UpdateField );
		


		return true;
	}


	/**
	*弹幕-->弹幕设置 RPC请求
	*/
	public void BulletScreenOpt(int BulletScreenType, int OptType, ReplyHandler replyCB)
	{
		BulletScreenRpcBulletScreenOptAskWraper askPBWraper = new BulletScreenRpcBulletScreenOptAskWraper();
		askPBWraper.BulletScreenType = BulletScreenType;
		askPBWraper.OptType = OptType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BulletScreenRpcBulletScreenOptReplyWraper replyPBWraper = new BulletScreenRpcBulletScreenOptReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*弹幕-->过场动画弹幕请求 RPC请求
	*/
	public void CGBulletScreen(int CGid, ReplyHandler replyCB)
	{
		BulletScreenRpcCGBulletScreenAskWraper askPBWraper = new BulletScreenRpcCGBulletScreenAskWraper();
		askPBWraper.CGid = CGid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BulletScreenRpcCGBulletScreenReplyWraper replyPBWraper = new BulletScreenRpcCGBulletScreenReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*弹幕-->发布过场弹幕 RPC请求
	*/
	public void SendBulletScreenCG(int CGid, string Content, ReplyHandler replyCB)
	{
		BulletScreenRpcSendBulletScreenCGAskWraper askPBWraper = new BulletScreenRpcSendBulletScreenCGAskWraper();
		askPBWraper.CGid = CGid;
		askPBWraper.Content = Content;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BulletScreenRpcSendBulletScreenCGReplyWraper replyPBWraper = new BulletScreenRpcSendBulletScreenCGReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class BulletScreenData
{
	public enum SyncIdE
	{

	}
	
	private static BulletScreenData m_Instance = null;
	public static BulletScreenData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BulletScreenData();
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
			Ex.Logger.Log("BulletScreenData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
