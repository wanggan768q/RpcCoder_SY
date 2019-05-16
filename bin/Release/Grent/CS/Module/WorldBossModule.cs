/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleWorldBoss.cs
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


public class WorldBossRPC
{
	public const int ModuleId = 23;
	
	public const int RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST = 2351;
	public const int RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST = 2352;

	
	private static WorldBossRPC m_Instance = null;
	public static WorldBossRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldBossRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, WorldBossData.Instance.UpdateField );
		


		return true;
	}


	/**
	*世界BOSS模块-->世界BOSS信息 RPC请求
	*/
	public void WorldBossInfo(int BossID, ReplyHandler replyCB)
	{
		WorldBossRpcWorldBossInfoAskWraper askPBWraper = new WorldBossRpcWorldBossInfoAskWraper();
		askPBWraper.BossID = BossID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldBossRpcWorldBossInfoReplyWraper replyPBWraper = new WorldBossRpcWorldBossInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界BOSS模块-->世界BOSS排行榜信息 RPC请求
	*/
	public void WorldBossRankInfo(int BossID, int Occupation, ReplyHandler replyCB)
	{
		WorldBossRpcWorldBossRankInfoAskWraper askPBWraper = new WorldBossRpcWorldBossRankInfoAskWraper();
		askPBWraper.BossID = BossID;
		askPBWraper.Occupation = Occupation;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldBossRpcWorldBossRankInfoReplyWraper replyPBWraper = new WorldBossRpcWorldBossRankInfoReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class WorldBossData
{
	public enum SyncIdE
	{

	}
	
	private static WorldBossData m_Instance = null;
	public static WorldBossData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldBossData();
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
			Ex.Logger.Log("WorldBossData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
