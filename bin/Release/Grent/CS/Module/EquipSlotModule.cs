/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEquipSlot.cs
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


public class EquipSlotRPC
{
	public const int ModuleId = 27;
	
	public const int RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST = 2751;
	public const int RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST = 2752;
	public const int RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST = 2753;
	public const int RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST = 2754;

	
	private static EquipSlotRPC m_Instance = null;
	public static EquipSlotRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipSlotRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EquipSlotData.Instance.UpdateField );
		


		return true;
	}


	/**
	*装备槽-->同步装备槽相关 RPC请求
	*/
	public void SyncEquipSlot(ReplyHandler replyCB)
	{
		EquipSlotRpcSyncEquipSlotAskWraper askPBWraper = new EquipSlotRpcSyncEquipSlotAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipSlotRpcSyncEquipSlotReplyWraper replyPBWraper = new EquipSlotRpcSyncEquipSlotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备槽-->装备槽强化 RPC请求
	*/
	public void EnhanceEquipSlot(int Slot_Type, List<ItemSimpleDataWraper> CostItemList, ReplyHandler replyCB)
	{
		EquipSlotRpcEnhanceEquipSlotAskWraper askPBWraper = new EquipSlotRpcEnhanceEquipSlotAskWraper();
		askPBWraper.Slot_Type = Slot_Type;
		askPBWraper.SetCostItemList(CostItemList);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipSlotRpcEnhanceEquipSlotReplyWraper replyPBWraper = new EquipSlotRpcEnhanceEquipSlotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备槽-->同步装备槽星 RPC请求
	*/
	public void SyncEquipSlotStar(ReplyHandler replyCB)
	{
		EquipSlotRpcSyncEquipSlotStarAskWraper askPBWraper = new EquipSlotRpcSyncEquipSlotStarAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipSlotRpcSyncEquipSlotStarReplyWraper replyPBWraper = new EquipSlotRpcSyncEquipSlotStarReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备槽-->装备槽升星 RPC请求
	*/
	public void UpStarEquipSlot(int Slot_Type, bool IsProtection, ReplyHandler replyCB)
	{
		EquipSlotRpcUpStarEquipSlotAskWraper askPBWraper = new EquipSlotRpcUpStarEquipSlotAskWraper();
		askPBWraper.Slot_Type = Slot_Type;
		askPBWraper.IsProtection = IsProtection;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipSlotRpcUpStarEquipSlotReplyWraper replyPBWraper = new EquipSlotRpcUpStarEquipSlotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class EquipSlotData
{
	public enum SyncIdE
	{

	}
	
	private static EquipSlotData m_Instance = null;
	public static EquipSlotData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipSlotData();
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
			Ex.Logger.Log("EquipSlotData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
