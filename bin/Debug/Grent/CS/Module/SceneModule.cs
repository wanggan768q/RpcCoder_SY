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
	
	public const int RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 351;
	public const int RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 352;
	public const int RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 353;
	public const int RPC_CODE_SCENE_CHANGESCENE_REQUEST = 354;
	public const int RPC_CODE_SCENE_CREATEOBJ_NOTIFY = 355;
	public const int RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST = 356;
	public const int RPC_CODE_SCENE_CENTERSCENE_NOTIFY = 357;
	public const int RPC_CODE_SCENE_SENTERSCENE_NOTIFY = 358;
	public const int RPC_CODE_SCENE_OBJDIE_NOTIFY = 359;
	public const int RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST = 360;

	
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
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY, DeletePlayerCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_CREATEOBJ_NOTIFY, CreateObjCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_SENTERSCENE_NOTIFY, SEnterSceneCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_OBJDIE_NOTIFY, ObjDieCB);


		return true;
	}

	/**
	*场景模块-->进入场景 RPC通知
	*/
	public void CEnterScene(int SceneId, int MapId)
	{
		SceneRpcCEnterSceneNotifyWraper notifyPBWraper = new SceneRpcCEnterSceneNotifyWraper();
		notifyPBWraper.SceneId = SceneId;
		notifyPBWraper.MapId = MapId;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_SCENE_CENTERSCENE_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
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
	*场景模块-->多线程移除场景上的玩家 RPC请求
	*/
	public void ChangeScene(UInt64 RoleId, int CurSceneId, int TargetSceneId, ReplyHandler replyCB)
	{
		SceneRpcChangeSceneAskWraper askPBWraper = new SceneRpcChangeSceneAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.CurSceneId = CurSceneId;
		askPBWraper.TargetSceneId = TargetSceneId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_CHANGESCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcChangeSceneReplyWraper replyPBWraper = new SceneRpcChangeSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->SurroundingHuman RPC请求
	*/
	public void SurroundingHuman(ReplyHandler replyCB)
	{
		SceneRpcSurroundingHumanAskWraper askPBWraper = new SceneRpcSurroundingHumanAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcSurroundingHumanReplyWraper replyPBWraper = new SceneRpcSurroundingHumanReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->collide 场景切换 RPC请求
	*/
	public void Collide_ChangeScene(int Collide_id, ReplyHandler replyCB)
	{
		SceneRpcCollide_ChangeSceneAskWraper askPBWraper = new SceneRpcCollide_ChangeSceneAskWraper();
		askPBWraper.Collide_id = Collide_id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcCollide_ChangeSceneReplyWraper replyPBWraper = new SceneRpcCollide_ChangeSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


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
	/**
	*场景模块-->创建物体 服务器通知回调
	*/
	public static void CreateObjCB( ModMessage notifyMsg )
	{
		SceneRpcCreateObjNotifyWraper notifyPBWraper = new SceneRpcCreateObjNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CreateObjCBDelegate != null )
			CreateObjCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CreateObjCBDelegate = null;
	/**
	*场景模块-->进入场景返回 服务器通知回调
	*/
	public static void SEnterSceneCB( ModMessage notifyMsg )
	{
		SceneRpcSEnterSceneNotifyWraper notifyPBWraper = new SceneRpcSEnterSceneNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SEnterSceneCBDelegate != null )
			SEnterSceneCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SEnterSceneCBDelegate = null;
	/**
	*场景模块-->ObjDie 服务器通知回调
	*/
	public static void ObjDieCB( ModMessage notifyMsg )
	{
		SceneRpcObjDieNotifyWraper notifyPBWraper = new SceneRpcObjDieNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ObjDieCBDelegate != null )
			ObjDieCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ObjDieCBDelegate = null;



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
