/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleJewel.cs
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


public class JewelRPC
{
	public const int ModuleId = 25;
	
	public const int RPC_CODE_JEWEL_JEWELSYNC_REQUEST = 2551;
	public const int RPC_CODE_JEWEL_INSETJEWEL_REQUEST = 2552;
	public const int RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST = 2553;
	public const int RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST = 2554;
	public const int RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST = 2555;
	public const int RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST = 2556;
	public const int RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST = 2557;

	
	private static JewelRPC m_Instance = null;
	public static JewelRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new JewelRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, JewelData.Instance.UpdateField );
		


		return true;
	}


	/**
	*宝石模块-->同步 RPC请求
	*/
	public void JewelSync(ReplyHandler replyCB)
	{
		JewelRpcJewelSyncAskWraper askPBWraper = new JewelRpcJewelSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_JEWELSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcJewelSyncReplyWraper replyPBWraper = new JewelRpcJewelSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->镶嵌 RPC请求
	*/
	public void InsetJewel(int EquipSlot, int JewelId, int JewelSlot, ReplyHandler replyCB)
	{
		JewelRpcInsetJewelAskWraper askPBWraper = new JewelRpcInsetJewelAskWraper();
		askPBWraper.EquipSlot = EquipSlot;
		askPBWraper.JewelId = JewelId;
		askPBWraper.JewelSlot = JewelSlot;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_INSETJEWEL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcInsetJewelReplyWraper replyPBWraper = new JewelRpcInsetJewelReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->摘除宝石 RPC请求
	*/
	public void RemoveJewel(int EquipSlot, int JewelSlot, ReplyHandler replyCB)
	{
		JewelRpcRemoveJewelAskWraper askPBWraper = new JewelRpcRemoveJewelAskWraper();
		askPBWraper.EquipSlot = EquipSlot;
		askPBWraper.JewelSlot = JewelSlot;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcRemoveJewelReplyWraper replyPBWraper = new JewelRpcRemoveJewelReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->合成宝石 RPC请求
	*/
	public void CompoundJewel(int JewelId, bool UseSafeItem, ReplyHandler replyCB)
	{
		JewelRpcCompoundJewelAskWraper askPBWraper = new JewelRpcCompoundJewelAskWraper();
		askPBWraper.JewelId = JewelId;
		askPBWraper.UseSafeItem = UseSafeItem;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcCompoundJewelReplyWraper replyPBWraper = new JewelRpcCompoundJewelReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->对已镶嵌的宝石合成 RPC请求
	*/
	public void CompoundSetJewel(int EquipType, int JewelSlot, ReplyHandler replyCB)
	{
		JewelRpcCompoundSetJewelAskWraper askPBWraper = new JewelRpcCompoundSetJewelAskWraper();
		askPBWraper.EquipType = EquipType;
		askPBWraper.JewelSlot = JewelSlot;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcCompoundSetJewelReplyWraper replyPBWraper = new JewelRpcCompoundSetJewelReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->解锁 RPC请求
	*/
	public void UnlockJewelSlot(int EquipSlot, int JewelSlot, ReplyHandler replyCB)
	{
		JewelRpcUnlockJewelSlotAskWraper askPBWraper = new JewelRpcUnlockJewelSlotAskWraper();
		askPBWraper.EquipSlot = EquipSlot;
		askPBWraper.JewelSlot = JewelSlot;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcUnlockJewelSlotReplyWraper replyPBWraper = new JewelRpcUnlockJewelSlotReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宝石模块-->快速合成 RPC请求
	*/
	public void QuickCompound(int JewelId, ReplyHandler replyCB)
	{
		JewelRpcQuickCompoundAskWraper askPBWraper = new JewelRpcQuickCompoundAskWraper();
		askPBWraper.JewelId = JewelId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			JewelRpcQuickCompoundReplyWraper replyPBWraper = new JewelRpcQuickCompoundReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class JewelData
{
	public enum SyncIdE
	{

	}
	
	private static JewelData m_Instance = null;
	public static JewelData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new JewelData();
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
			Ex.Logger.Log("JewelData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
