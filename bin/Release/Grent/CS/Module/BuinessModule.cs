/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBuiness.cs
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


public class BuinessRPC
{
	public const int ModuleId = 22;
	
	public const int RPC_CODE_BUINESS_BUINESSSYNC_REQUEST = 2251;
	public const int RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST = 2252;
	public const int RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST = 2253;
	public const int RPC_CODE_BUINESS_BUINESSMAKE_REQUEST = 2254;

	
	private static BuinessRPC m_Instance = null;
	public static BuinessRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BuinessRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BuinessData.Instance.UpdateField );
		


		return true;
	}


	/**
	*生活技能-->初始化 RPC请求
	*/
	public void BuinessSync(ReplyHandler replyCB)
	{
		BuinessRpcBuinessSyncAskWraper askPBWraper = new BuinessRpcBuinessSyncAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BUINESS_BUINESSSYNC_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BuinessRpcBuinessSyncReplyWraper replyPBWraper = new BuinessRpcBuinessSyncReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*生活技能-->解锁 RPC请求
	*/
	public void BuinessUnlock(int SkillID, ReplyHandler replyCB)
	{
		BuinessRpcBuinessUnlockAskWraper askPBWraper = new BuinessRpcBuinessUnlockAskWraper();
		askPBWraper.SkillID = SkillID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BuinessRpcBuinessUnlockReplyWraper replyPBWraper = new BuinessRpcBuinessUnlockReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*生活技能-->学习技能 RPC请求
	*/
	public void BuinessStudy(int SkillID, int StudyType, ReplyHandler replyCB)
	{
		BuinessRpcBuinessStudyAskWraper askPBWraper = new BuinessRpcBuinessStudyAskWraper();
		askPBWraper.SkillID = SkillID;
		askPBWraper.StudyType = StudyType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BuinessRpcBuinessStudyReplyWraper replyPBWraper = new BuinessRpcBuinessStudyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*生活技能-->制作 RPC请求
	*/
	public void BuinessMake(int SkillID, ReplyHandler replyCB)
	{
		BuinessRpcBuinessMakeAskWraper askPBWraper = new BuinessRpcBuinessMakeAskWraper();
		askPBWraper.SkillID = SkillID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BUINESS_BUINESSMAKE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BuinessRpcBuinessMakeReplyWraper replyPBWraper = new BuinessRpcBuinessMakeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class BuinessData
{
	public enum SyncIdE
	{

	}
	
	private static BuinessData m_Instance = null;
	public static BuinessData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BuinessData();
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
			Ex.Logger.Log("BuinessData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
