/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleSkill.cs
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


public class SkillRPC
{
	public const int ModuleId = 21;
	
	public const int RPC_CODE_SKILL_SKILLINFO_REQUEST = 2151;
	public const int RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST = 2152;
	public const int RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST = 2153;
	public const int RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST = 2154;

	
	private static SkillRPC m_Instance = null;
	public static SkillRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SkillRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, SkillData.Instance.UpdateField );
		


		return true;
	}


	/**
	*技能模块-->技能信息 RPC请求
	*/
	public void SkillInfo(ReplyHandler replyCB)
	{
		SkillRpcSkillInfoAskWraper askPBWraper = new SkillRpcSkillInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SKILL_SKILLINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SkillRpcSkillInfoReplyWraper replyPBWraper = new SkillRpcSkillInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*技能模块-->更新技能信息 RPC请求
	*/
	public void UpdateSkillInfo(List<ProfessionInfoWraper> ProfessionInfos, int CurUseMastery, ReplyHandler replyCB)
	{
		SkillRpcUpdateSkillInfoAskWraper askPBWraper = new SkillRpcUpdateSkillInfoAskWraper();
		askPBWraper.SetProfessionInfos(ProfessionInfos);
		askPBWraper.CurUseMastery = CurUseMastery;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SkillRpcUpdateSkillInfoReplyWraper replyPBWraper = new SkillRpcUpdateSkillInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*技能模块-->技能栏位升级 RPC请求
	*/
	public void LevelUpSkillPos(int SkillPos, bool IsAuto, ReplyHandler replyCB)
	{
		SkillRpcLevelUpSkillPosAskWraper askPBWraper = new SkillRpcLevelUpSkillPosAskWraper();
		askPBWraper.SkillPos = SkillPos;
		askPBWraper.IsAuto = IsAuto;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SkillRpcLevelUpSkillPosReplyWraper replyPBWraper = new SkillRpcLevelUpSkillPosReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*技能模块-->技能栏位等级信息 RPC请求
	*/
	public void SkillLevelInfo(ReplyHandler replyCB)
	{
		SkillRpcSkillLevelInfoAskWraper askPBWraper = new SkillRpcSkillLevelInfoAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SkillRpcSkillLevelInfoReplyWraper replyPBWraper = new SkillRpcSkillLevelInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class SkillData
{
	public enum SyncIdE
	{

	}
	
	private static SkillData m_Instance = null;
	public static SkillData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SkillData();
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
			Ex.Logger.Log("SkillData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
