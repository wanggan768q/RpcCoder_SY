/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModulePet.cs
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


public class PetRPC
{
	public const int ModuleId = 31;
	
	public const int RPC_CODE_PET_PETSYNC_REQUEST = 3151;
	public const int RPC_CODE_PET_UNSUMMON_REQUEST = 3152;
	public const int RPC_CODE_PET_LEVELUPGRADE_REQUEST = 3153;
	public const int RPC_CODE_PET_STARUPGRADE_REQUEST = 3154;
	public const int RPC_CODE_PET_CHANGENAME_REQUEST = 3155;
	public const int RPC_CODE_PET_INHERIT_REQUEST = 3156;
	public const int RPC_CODE_PET_SKILLINHERIT_REQUEST = 3157;
	public const int RPC_CODE_PET_PASSIVESKILLS_REQUEST = 3158;
	public const int RPC_CODE_PET_STUDYSKILL_REQUEST = 3159;
	public const int RPC_CODE_PET_LOCKSKILL_REQUEST = 3160;
	public const int RPC_CODE_PET_UNLOCKSKILL_REQUEST = 3161;

	
	private static PetRPC m_Instance = null;
	public static PetRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PetRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, PetData.Instance.UpdateField );
		


		return true;
	}


	/**
	*宠物模块-->同步 RPC请求
	*/
	public void PetSync(ReplyHandler replyCB)
	{
		PetRpcPetSyncAskWraper askPBWraper = new PetRpcPetSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_PETSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcPetSyncReplyWraper replyPBWraper = new PetRpcPetSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->召回 RPC请求
	*/
	public void UnSummon(ReplyHandler replyCB)
	{
		PetRpcUnSummonAskWraper askPBWraper = new PetRpcUnSummonAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_UNSUMMON_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcUnSummonReplyWraper replyPBWraper = new PetRpcUnSummonReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->升级 RPC请求
	*/
	public void LevelUpgrade(UInt64 Guid, List<int> ItemCount, ReplyHandler replyCB)
	{
		PetRpcLevelUpgradeAskWraper askPBWraper = new PetRpcLevelUpgradeAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.SetItemCount(ItemCount);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_LEVELUPGRADE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcLevelUpgradeReplyWraper replyPBWraper = new PetRpcLevelUpgradeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->升星 RPC请求
	*/
	public void StarUpgrade(UInt64 Guid, UInt64 UseGuid, ReplyHandler replyCB)
	{
		PetRpcStarUpgradeAskWraper askPBWraper = new PetRpcStarUpgradeAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.UseGuid = UseGuid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_STARUPGRADE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcStarUpgradeReplyWraper replyPBWraper = new PetRpcStarUpgradeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->改名 RPC请求
	*/
	public void ChangeName(UInt64 Guid, string NewName, ReplyHandler replyCB)
	{
		PetRpcChangeNameAskWraper askPBWraper = new PetRpcChangeNameAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.NewName = NewName;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_CHANGENAME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcChangeNameReplyWraper replyPBWraper = new PetRpcChangeNameReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->传承 RPC请求
	*/
	public void Inherit(UInt64 Guid, UInt64 UseGuid, ReplyHandler replyCB)
	{
		PetRpcInheritAskWraper askPBWraper = new PetRpcInheritAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.UseGuid = UseGuid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_INHERIT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcInheritReplyWraper replyPBWraper = new PetRpcInheritReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->技能继承 RPC请求
	*/
	public void SkillInherit(UInt64 Guid, UInt64 UseGuid, ReplyHandler replyCB)
	{
		PetRpcSkillInheritAskWraper askPBWraper = new PetRpcSkillInheritAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.UseGuid = UseGuid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_SKILLINHERIT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcSkillInheritReplyWraper replyPBWraper = new PetRpcSkillInheritReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->宠物被动技能列表 RPC请求
	*/
	public void PassiveSkills(UInt64 Guid, ReplyHandler replyCB)
	{
		PetRpcPassiveSkillsAskWraper askPBWraper = new PetRpcPassiveSkillsAskWraper();
		askPBWraper.Guid = Guid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_PASSIVESKILLS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcPassiveSkillsReplyWraper replyPBWraper = new PetRpcPassiveSkillsReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->学习被动技能 RPC请求
	*/
	public void StudySkill(UInt64 Guid, int ItemId, ReplyHandler replyCB)
	{
		PetRpcStudySkillAskWraper askPBWraper = new PetRpcStudySkillAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.ItemId = ItemId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_STUDYSKILL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcStudySkillReplyWraper replyPBWraper = new PetRpcStudySkillReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->锁定技能 RPC请求
	*/
	public void LockSkill(UInt64 Guid, int SkillId, ReplyHandler replyCB)
	{
		PetRpcLockSkillAskWraper askPBWraper = new PetRpcLockSkillAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.SkillId = SkillId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_LOCKSKILL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcLockSkillReplyWraper replyPBWraper = new PetRpcLockSkillReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*宠物模块-->解除技能锁定 RPC请求
	*/
	public void UnLockSkill(UInt64 Guid, int SkillId, ReplyHandler replyCB)
	{
		PetRpcUnLockSkillAskWraper askPBWraper = new PetRpcUnLockSkillAskWraper();
		askPBWraper.Guid = Guid;
		askPBWraper.SkillId = SkillId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_PET_UNLOCKSKILL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PetRpcUnLockSkillReplyWraper replyPBWraper = new PetRpcUnLockSkillReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class PetData
{
	public enum SyncIdE
	{

	}
	
	private static PetData m_Instance = null;
	public static PetData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PetData();
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
			Ex.Logger.Log("PetData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
