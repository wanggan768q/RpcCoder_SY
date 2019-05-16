/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleRiding.cs
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


public class RidingRPC
{
	public const int ModuleId = 40;
	
	public const int RPC_CODE_RIDING_RIDING_REQUEST = 4051;
	public const int RPC_CODE_RIDING_UNRIDING_REQUEST = 4052;

	
	private static RidingRPC m_Instance = null;
	public static RidingRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RidingRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, RidingData.Instance.UpdateField );
		


		return true;
	}


	/**
	*坐骑-->上马 RPC请求
	*/
	public void Riding(ReplyHandler replyCB)
	{
		RidingRpcRidingAskWraper askPBWraper = new RidingRpcRidingAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_RIDING_RIDING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			RidingRpcRidingReplyWraper replyPBWraper = new RidingRpcRidingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*坐骑-->下马 RPC请求
	*/
	public void UnRiding(ReplyHandler replyCB)
	{
		RidingRpcUnRidingAskWraper askPBWraper = new RidingRpcUnRidingAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_RIDING_UNRIDING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			RidingRpcUnRidingReplyWraper replyPBWraper = new RidingRpcUnRidingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class RidingData
{
	public enum SyncIdE
	{

	}
	
	private static RidingData m_Instance = null;
	public static RidingData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RidingData();
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
			Ex.Logger.Log("RidingData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
