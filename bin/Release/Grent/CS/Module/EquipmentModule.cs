/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEquipment.cs
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


public class EquipmentRPC
{
	public const int ModuleId = 18;
	
	public const int RPC_CODE_EQUIPMENT_EQUIP_REQUEST = 1851;
	public const int RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST = 1852;
	public const int RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST = 1853;
	public const int RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST = 1854;
	public const int RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST = 1855;
	public const int RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST = 1856;
	public const int RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST = 1857;
	public const int RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST = 1858;
	public const int RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST = 1859;
	public const int RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST = 1860;
	public const int RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST = 1861;
	public const int RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST = 1862;
	public const int RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST = 1863;
	public const int RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST = 1864;
	public const int RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST = 1865;

	
	private static EquipmentRPC m_Instance = null;
	public static EquipmentRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipmentRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EquipmentData.Instance.UpdateField );
		


		return true;
	}


	/**
	*装备-->Equip RPC请求
	*/
	public void Equip(int Pos, ReplyHandler replyCB)
	{
		EquipmentRpcEquipAskWraper askPBWraper = new EquipmentRpcEquipAskWraper();
		askPBWraper.Pos = Pos;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipReplyWraper replyPBWraper = new EquipmentRpcEquipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->UnEquip RPC请求
	*/
	public void UnEquip(int SlotType, ReplyHandler replyCB)
	{
		EquipmentRpcUnEquipAskWraper askPBWraper = new EquipmentRpcUnEquipAskWraper();
		askPBWraper.SlotType = SlotType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcUnEquipReplyWraper replyPBWraper = new EquipmentRpcUnEquipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->SwitchEquipSet RPC请求
	*/
	public void SwitchEquipSet(int To_index, ReplyHandler replyCB)
	{
		EquipmentRpcSwitchEquipSetAskWraper askPBWraper = new EquipmentRpcSwitchEquipSetAskWraper();
		askPBWraper.To_index = To_index;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcSwitchEquipSetReplyWraper replyPBWraper = new EquipmentRpcSwitchEquipSetReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->Equip RPC请求
	*/
	public void SyncEquip(ReplyHandler replyCB)
	{
		EquipmentRpcSyncEquipAskWraper askPBWraper = new EquipmentRpcSyncEquipAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcSyncEquipReplyWraper replyPBWraper = new EquipmentRpcSyncEquipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->激活共鸣 RPC请求
	*/
	public void ResonanceUnlock(int ConfId, ReplyHandler replyCB)
	{
		EquipmentRpcResonanceUnlockAskWraper askPBWraper = new EquipmentRpcResonanceUnlockAskWraper();
		askPBWraper.ConfId = ConfId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcResonanceUnlockReplyWraper replyPBWraper = new EquipmentRpcResonanceUnlockReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->共鸣洗练 RPC请求
	*/
	public void EquipDoResonance(int ConfId, ReplyHandler replyCB)
	{
		EquipmentRpcEquipDoResonanceAskWraper askPBWraper = new EquipmentRpcEquipDoResonanceAskWraper();
		askPBWraper.ConfId = ConfId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipDoResonanceReplyWraper replyPBWraper = new EquipmentRpcEquipDoResonanceReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->保存共鸣属性 RPC请求
	*/
	public void EquipResonanceSave(int ConfId, ReplyHandler replyCB)
	{
		EquipmentRpcEquipResonanceSaveAskWraper askPBWraper = new EquipmentRpcEquipResonanceSaveAskWraper();
		askPBWraper.ConfId = ConfId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipResonanceSaveReplyWraper replyPBWraper = new EquipmentRpcEquipResonanceSaveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->初始化 RPC请求
	*/
	public void EquipResonanceSync(ReplyHandler replyCB)
	{
		EquipmentRpcEquipResonanceSyncAskWraper askPBWraper = new EquipmentRpcEquipResonanceSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipResonanceSyncReplyWraper replyPBWraper = new EquipmentRpcEquipResonanceSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->初始化洗练数据 RPC请求
	*/
	public void EquipWashSync(ReplyHandler replyCB)
	{
		EquipmentRpcEquipWashSyncAskWraper askPBWraper = new EquipmentRpcEquipWashSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipWashSyncReplyWraper replyPBWraper = new EquipmentRpcEquipWashSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->请求洗练 RPC请求
	*/
	public void EquipWash(UInt64 Guid, List<int> LockedIndex, ReplyHandler replyCB)
	{
		EquipmentRpcEquipWashAskWraper askPBWraper = new EquipmentRpcEquipWashAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.SetLockedIndex(LockedIndex);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipWashReplyWraper replyPBWraper = new EquipmentRpcEquipWashReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->保存 RPC请求
	*/
	public void EquipWashSave(UInt64 Guid, ReplyHandler replyCB)
	{
		EquipmentRpcEquipWashSaveAskWraper askPBWraper = new EquipmentRpcEquipWashSaveAskWraper();
		askPBWraper.Guid = Guid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipWashSaveReplyWraper replyPBWraper = new EquipmentRpcEquipWashSaveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->装备打造 RPC请求
	*/
	public void EquipBuildSync(ReplyHandler replyCB)
	{
		EquipmentRpcEquipBuildSyncAskWraper askPBWraper = new EquipmentRpcEquipBuildSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipBuildSyncReplyWraper replyPBWraper = new EquipmentRpcEquipBuildSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->打造请求 RPC请求
	*/
	public void EquipBuild(int Level, int Occupation, int Slot_type, ReplyHandler replyCB)
	{
		EquipmentRpcEquipBuildAskWraper askPBWraper = new EquipmentRpcEquipBuildAskWraper();
		askPBWraper.Level = Level;
		askPBWraper.Occupation = Occupation;
		askPBWraper.Slot_type = Slot_type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipBuildReplyWraper replyPBWraper = new EquipmentRpcEquipBuildReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->获取其他玩家信息 RPC请求
	*/
	public void GetPlayerInfo(UInt64 Player_guid, ReplyHandler replyCB)
	{
		EquipmentRpcGetPlayerInfoAskWraper askPBWraper = new EquipmentRpcGetPlayerInfoAskWraper();
		askPBWraper.Player_guid = Player_guid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcGetPlayerInfoReplyWraper replyPBWraper = new EquipmentRpcGetPlayerInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->装备继承 RPC请求
	*/
	public void EquipInherit(UInt64 ToGuid, UInt64 FromGuid, ReplyHandler replyCB)
	{
		EquipmentRpcEquipInheritAskWraper askPBWraper = new EquipmentRpcEquipInheritAskWraper();
		askPBWraper.ToGuid = ToGuid;
		askPBWraper.FromGuid = FromGuid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipInheritReplyWraper replyPBWraper = new EquipmentRpcEquipInheritReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class EquipmentData
{
	public enum SyncIdE
	{

	}
	
	private static EquipmentData m_Instance = null;
	public static EquipmentData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipmentData();
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
			Ex.Logger.Log("EquipmentData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
