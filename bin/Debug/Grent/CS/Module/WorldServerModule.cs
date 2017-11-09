/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleWorldServer.cs
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


public class WorldServerRPC
{
	public const int ModuleId = 8;
	
	public const int RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST = 851;
	public const int RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST = 852;

	
	private static WorldServerRPC m_Instance = null;
	public static WorldServerRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldServerRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, WorldServerData.Instance.UpdateField );
		


		return true;
	}


	/**
	*世界服务器模块-->通知世界服务器切换场景 RPC请求
	*/
	public void ChangeScene(UInt64 RoleId, int CurSceneId, int TargetSceneId, int MemId, ReplyHandler replyCB)
	{
		WorldServerRpcChangeSceneAskWraper askPBWraper = new WorldServerRpcChangeSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.TargetSceneId = TargetSceneId;
		askPBWraper.MemId = MemId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcChangeSceneReplyWraper replyPBWraper = new WorldServerRpcChangeSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*世界服务器模块-->进入场景 RPC请求
	*/
	public void EnterScene(UInt64 RoleId, int SceneId, ReplyHandler replyCB)
	{
		WorldServerRpcEnterSceneAskWraper askPBWraper = new WorldServerRpcEnterSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WorldServerRpcEnterSceneReplyWraper replyPBWraper = new WorldServerRpcEnterSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class WorldServerData
{
	public enum SyncIdE
	{

	}
	
	private static WorldServerData m_Instance = null;
	public static WorldServerData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WorldServerData();
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
			Ex.Logger.Log("WorldServerData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
