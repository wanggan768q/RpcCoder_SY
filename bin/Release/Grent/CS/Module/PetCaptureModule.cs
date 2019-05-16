/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModulePetCapture.cs
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


public class PetCaptureRPC
{
	public const int ModuleId = 44;
	
	public const int RPC_CODE_PETCAPTURE_CAPTURE_REQUEST = 4451;
	public const int RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY = 4452;
	public const int RPC_CODE_PETCAPTURE_LOGIN_NOTIFY = 4453;
	public const int RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST = 4454;

	
	private static PetCaptureRPC m_Instance = null;
	public static PetCaptureRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PetCaptureRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, PetCaptureData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY, CapturePetCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_PETCAPTURE_LOGIN_NOTIFY, LoginCB);


		return true;
	}


	/**
	*宠物捕获-->宠物捕获 RPC请求
	*/
	public void Capture(int BallType, ReplyHandler replyCB)
	{
		PetCaptureRpcCaptureAskWraper askPBWraper = new PetCaptureRpcCaptureAskWraper();
		askPBWraper.BallType = BallType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PETCAPTURE_CAPTURE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetCaptureRpcCaptureReplyWraper replyPBWraper = new PetCaptureRpcCaptureReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物捕获-->宠物npc位置 RPC请求
	*/
	public void PetLocation(int LineId, ReplyHandler replyCB)
	{
		PetCaptureRpcPetLocationAskWraper askPBWraper = new PetCaptureRpcPetLocationAskWraper();
		askPBWraper.LineId = LineId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetCaptureRpcPetLocationReplyWraper replyPBWraper = new PetCaptureRpcPetLocationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*宠物捕获-->捕获到宠物广播 服务器通知回调
	*/
	public static void CapturePetCB( ModMessage notifyMsg )
	{
		PetCaptureRpcCapturePetNotifyWraper notifyPBWraper = new PetCaptureRpcCapturePetNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CapturePetCBDelegate != null )
			CapturePetCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CapturePetCBDelegate = null;
	/**
	*宠物捕获-->宠物捕获登录 服务器通知回调
	*/
	public static void LoginCB( ModMessage notifyMsg )
	{
		PetCaptureRpcLoginNotifyWraper notifyPBWraper = new PetCaptureRpcLoginNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( LoginCBDelegate != null )
			LoginCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback LoginCBDelegate = null;



}

public class PetCaptureData
{
	public enum SyncIdE
	{

	}
	
	private static PetCaptureData m_Instance = null;
	public static PetCaptureData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PetCaptureData();
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
			Ex.Logger.Log("PetCaptureData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
