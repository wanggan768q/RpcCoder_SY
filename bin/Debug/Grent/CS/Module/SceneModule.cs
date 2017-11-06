/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleScene.cs
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


public class SceneRPC
{
	public const int ModuleId = 3;
	
	public const int RPC_CODE_SCENE_ENTERSCENE_REQUEST = 351;
	public const int RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 352;
	public const int RPC_CODE_SCENE_NEWPLAYER_NOTIFY = 353;
	public const int RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 354;
	public const int RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 355;

	
	private static SceneRPC m_Instance = null;
	public static SceneRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SceneRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, SceneData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_NEWPLAYER_NOTIFY, NewPlayerCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY, DeletePlayerCB);


		return true;
	}


	/**
	*场景模块-->进入场景 RPC请求
	*/
	public void EnterScene(UInt64 RoleId, int SceneId, ReplyHandler replyCB)
	{
		SceneRpcEnterSceneAskWraper askPBWraper = new SceneRpcEnterSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_ENTERSCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcEnterSceneReplyWraper replyPBWraper = new SceneRpcEnterSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->进入场景完成 RPC请求
	*/
	public void LoadSceneComplete(UInt64 RoleId, int SceneId, ReplyHandler replyCB)
	{
		SceneRpcLoadSceneCompleteAskWraper askPBWraper = new SceneRpcLoadSceneCompleteAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.SceneId = SceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcLoadSceneCompleteReplyWraper replyPBWraper = new SceneRpcLoadSceneCompleteReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->连接场景服务器 RPC请求
	*/
	public void ConnectGameServer(UInt64 RoleId, string Key, ReplyHandler replyCB)
	{
		SceneRpcConnectGameServerAskWraper askPBWraper = new SceneRpcConnectGameServerAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.Key = Key;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcConnectGameServerReplyWraper replyPBWraper = new SceneRpcConnectGameServerReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*场景模块-->新玩家进入视野 服务器通知回调
	*/
	public static void NewPlayerCB( ModMessage notifyMsg )
	{
		SceneRpcNewPlayerNotifyWraper notifyPBWraper = new SceneRpcNewPlayerNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewPlayerCBDelegate != null )
			NewPlayerCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewPlayerCBDelegate = null;
	/**
	*场景模块-->玩家离开视野 服务器通知回调
	*/
	public static void DeletePlayerCB( ModMessage notifyMsg )
	{
		SceneRpcDeletePlayerNotifyWraper notifyPBWraper = new SceneRpcDeletePlayerNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DeletePlayerCBDelegate != null )
			DeletePlayerCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DeletePlayerCBDelegate = null;



}

public class SceneData
{
	public enum SyncIdE
	{

	}
	
	private static SceneData m_Instance = null;
	public static SceneData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SceneData();
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
			Ex.Logger.Log("SceneData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
