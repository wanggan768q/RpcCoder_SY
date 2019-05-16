/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleItemOperation.cs
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


public class ItemOperationRPC
{
	public const int ModuleId = 17;
	
	public const int RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST = 1751;
	public const int RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST = 1752;
	public const int RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST = 1753;
	public const int RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST = 1754;
	public const int RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST = 1755;

	
	private static ItemOperationRPC m_Instance = null;
	public static ItemOperationRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ItemOperationRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ItemOperationData.Instance.UpdateField );
		


		return true;
	}


	/**
	*道具操作-->道具分解界面初始化 RPC请求
	*/
	public void ItemResolveSettingSync(ReplyHandler replyCB)
	{
		ItemOperationRpcItemResolveSettingSyncAskWraper askPBWraper = new ItemOperationRpcItemResolveSettingSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ItemOperationRpcItemResolveSettingSyncReplyWraper replyPBWraper = new ItemOperationRpcItemResolveSettingSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*道具操作-->道具分解 RPC请求
	*/
	public void ItemResolve(int ItemPos, int Count, ReplyHandler replyCB)
	{
		ItemOperationRpcItemResolveAskWraper askPBWraper = new ItemOperationRpcItemResolveAskWraper();
		askPBWraper.ItemPos = ItemPos;
		askPBWraper.Count = Count;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ItemOperationRpcItemResolveReplyWraper replyPBWraper = new ItemOperationRpcItemResolveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*道具操作-->更改设置 RPC请求
	*/
	public void ChangeSetting(List<ItemResolveDataWraper> SettingList, ReplyHandler replyCB)
	{
		ItemOperationRpcChangeSettingAskWraper askPBWraper = new ItemOperationRpcChangeSettingAskWraper();
		askPBWraper.SetSettingList(SettingList);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ItemOperationRpcChangeSettingReplyWraper replyPBWraper = new ItemOperationRpcChangeSettingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*道具操作-->一键分解 RPC请求
	*/
	public void BatchResolve(int Qulity, ReplyHandler replyCB)
	{
		ItemOperationRpcBatchResolveAskWraper askPBWraper = new ItemOperationRpcBatchResolveAskWraper();
		askPBWraper.Qulity = Qulity;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ItemOperationRpcBatchResolveReplyWraper replyPBWraper = new ItemOperationRpcBatchResolveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*道具操作-->道具合成 RPC请求
	*/
	public void ItemCompound(int ItemConfID, ReplyHandler replyCB)
	{
		ItemOperationRpcItemCompoundAskWraper askPBWraper = new ItemOperationRpcItemCompoundAskWraper();
		askPBWraper.ItemConfID = ItemConfID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ItemOperationRpcItemCompoundReplyWraper replyPBWraper = new ItemOperationRpcItemCompoundReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class ItemOperationData
{
	public enum SyncIdE
	{

	}
	
	private static ItemOperationData m_Instance = null;
	public static ItemOperationData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ItemOperationData();
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
			Ex.Logger.Log("ItemOperationData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
