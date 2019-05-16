/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleRank.cs
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


public class RankRPC
{
	public const int ModuleId = 56;
	
	public const int RPC_CODE_RANK_RANK_REQUEST = 5651;

	
	private static RankRPC m_Instance = null;
	public static RankRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RankRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, RankData.Instance.UpdateField );
		


		return true;
	}


	/**
	*排行榜-->请求排行榜 RPC请求
	*/
	public void Rank(int RankType, int RankSubType, ReplyHandler replyCB)
	{
		RankRpcRankAskWraper askPBWraper = new RankRpcRankAskWraper();
		askPBWraper.RankType = RankType;
		askPBWraper.RankSubType = RankSubType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_RANK_RANK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			RankRpcRankReplyWraper replyPBWraper = new RankRpcRankReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class RankData
{
	public enum SyncIdE
	{

	}
	
	private static RankData m_Instance = null;
	public static RankData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RankData();
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
			Ex.Logger.Log("RankData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
