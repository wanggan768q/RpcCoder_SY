/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleMercenary.cs
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


public class MercenaryRPC
{
	public const int ModuleId = 51;
	
	public const int RPC_CODE_MERCENARY_INQUEUE_REQUEST = 5151;
	public const int RPC_CODE_MERCENARY_OUTQUEUE_REQUEST = 5152;
	public const int RPC_CODE_MERCENARY_AUTOSET_REQUEST = 5153;
	public const int RPC_CODE_MERCENARY_INFO_REQUEST = 5154;

	
	private static MercenaryRPC m_Instance = null;
	public static MercenaryRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MercenaryRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, MercenaryData.Instance.UpdateField );
		


		return true;
	}


	/**
	*佣兵-->入队 RPC请求
	*/
	public void InQueue(int Id, ReplyHandler replyCB)
	{
		MercenaryRpcInQueueAskWraper askPBWraper = new MercenaryRpcInQueueAskWraper();
		askPBWraper.Id = Id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MERCENARY_INQUEUE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MercenaryRpcInQueueReplyWraper replyPBWraper = new MercenaryRpcInQueueReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*佣兵-->出队 RPC请求
	*/
	public void OutQueue(int Id, ReplyHandler replyCB)
	{
		MercenaryRpcOutQueueAskWraper askPBWraper = new MercenaryRpcOutQueueAskWraper();
		askPBWraper.Id = Id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MERCENARY_OUTQUEUE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MercenaryRpcOutQueueReplyWraper replyPBWraper = new MercenaryRpcOutQueueReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*佣兵-->自动配置 RPC请求
	*/
	public void AutoSet(ReplyHandler replyCB)
	{
		MercenaryRpcAutoSetAskWraper askPBWraper = new MercenaryRpcAutoSetAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MERCENARY_AUTOSET_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MercenaryRpcAutoSetReplyWraper replyPBWraper = new MercenaryRpcAutoSetReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*佣兵-->请求佣兵信息 RPC请求
	*/
	public void Info(ReplyHandler replyCB)
	{
		MercenaryRpcInfoAskWraper askPBWraper = new MercenaryRpcInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MERCENARY_INFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MercenaryRpcInfoReplyWraper replyPBWraper = new MercenaryRpcInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class MercenaryData
{
	public enum SyncIdE
	{

	}
	
	private static MercenaryData m_Instance = null;
	public static MercenaryData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MercenaryData();
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
			Ex.Logger.Log("MercenaryData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
