/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleGate.cs
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


public class GateRPC
{
	public const int ModuleId = 43;
	
	public const int RPC_CODE_GATE_PING_REQUEST = 4351;

	
	private static GateRPC m_Instance = null;
	public static GateRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GateRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, GateData.Instance.UpdateField );
		


		return true;
	}


	/**
	*网关模块-->Ping RPC请求
	*/
	public void Ping(UInt64 Sequence, ReplyHandler replyCB)
	{
		GateRpcPingAskWraper askPBWraper = new GateRpcPingAskWraper();
		askPBWraper.Sequence = Sequence;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GATE_PING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GateRpcPingReplyWraper replyPBWraper = new GateRpcPingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class GateData
{
	public enum SyncIdE
	{

	}
	
	private static GateData m_Instance = null;
	public static GateData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GateData();
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
			Ex.Logger.Log("GateData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
