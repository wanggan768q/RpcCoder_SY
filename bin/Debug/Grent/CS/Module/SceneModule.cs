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
	public const int RPC_CODE_SCENE_CREATEOBJ_NOTIFY = 354;
	public const int RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST = 355;
	public const int RPC_CODE_SCENE_CENTERSCENE_NOTIFY = 356;
	public const int RPC_CODE_SCENE_SENTERSCENE_NOTIFY = 357;
	public const int RPC_CODE_SCENE_OBJDIE_NOTIFY = 358;
	public const int RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST = 359;
	public const int RPC_CODE_SCENE_ENTERMIRROR_REQUEST = 360;
	public const int RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY = 361;
	public const int RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST = 362;
	public const int RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY = 363;
	public const int RPC_CODE_SCENE_CHANGELINE_REQUEST = 364;
	public const int RPC_CODE_SCENE_PING_REQUEST = 365;
	public const int RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY = 366;
	public const int RPC_CODE_SCENE_LOGOUTGAME_REQUEST = 367;
	public const int RPC_CODE_SCENE_KICKOUTGAME_NOTIFY = 368;
	public const int RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST = 369;
	public const int RPC_CODE_SCENE_SPECOBJPOS_REQUEST = 370;
	public const int RPC_CODE_SCENE_DAYNIGHTCHANGE_NOTIFY = 371;
	public const int RPC_CODE_SCENE_WEATHERCHANGE_NOTIFY = 372;
	public const int RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST = 373;
	public const int RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST = 374;

	
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
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY, SEnterMirrorSceneCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY, ChangeSceneLeaveCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY, SyncSceneLineStatsCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_KICKOUTGAME_NOTIFY, KickOutGameCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_DAYNIGHTCHANGE_NOTIFY, DayNightChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SCENE_WEATHERCHANGE_NOTIFY, WeatherChangeCB);


		return true;
	}

	/**
	*场景模块-->进入场景 RPC通知
	*/
	public void CEnterScene(int SceneId, int MapId, int LineId)
	{
		SceneRpcCEnterSceneNotifyWraper notifyPBWraper = new SceneRpcCEnterSceneNotifyWraper();
		notifyPBWraper.SceneId = SceneId;
		notifyPBWraper.MapId = MapId;
		notifyPBWraper.LineId = LineId;
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
	public void ConnectGameServer(UInt64 RoleId, string Key, int SceneID, int LineID, string GameToken, ReplyHandler replyCB)
	{
		SceneRpcConnectGameServerAskWraper askPBWraper = new SceneRpcConnectGameServerAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.Key = Key;
		askPBWraper.SceneID = SceneID;
		askPBWraper.LineID = LineID;
		askPBWraper.GameToken = GameToken;
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
	*场景模块-->进入镜像 RPC请求
	*/
	public void EnterMirror(int MirrorID, ReplyHandler replyCB)
	{
		SceneRpcEnterMirrorAskWraper askPBWraper = new SceneRpcEnterMirrorAskWraper();
		askPBWraper.MirrorID = MirrorID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_ENTERMIRROR_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcEnterMirrorReplyWraper replyPBWraper = new SceneRpcEnterMirrorReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->退出镜像 RPC请求
	*/
	public void ExitMirrorScene(ReplyHandler replyCB)
	{
		SceneRpcExitMirrorSceneAskWraper askPBWraper = new SceneRpcExitMirrorSceneAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcExitMirrorSceneReplyWraper replyPBWraper = new SceneRpcExitMirrorSceneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->ChangeLine RPC请求
	*/
	public void ChangeLine(int LineID, int MapID, ReplyHandler replyCB)
	{
		SceneRpcChangeLineAskWraper askPBWraper = new SceneRpcChangeLineAskWraper();
		askPBWraper.LineID = LineID;
		askPBWraper.MapID = MapID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_CHANGELINE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcChangeLineReplyWraper replyPBWraper = new SceneRpcChangeLineReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->ping RPC请求
	*/
	public void Ping(ReplyHandler replyCB)
	{
		SceneRpcPingAskWraper askPBWraper = new SceneRpcPingAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_PING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcPingReplyWraper replyPBWraper = new SceneRpcPingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->离开GameServer RPC请求
	*/
	public void LogOutGame(ReplyHandler replyCB)
	{
		SceneRpcLogOutGameAskWraper askPBWraper = new SceneRpcLogOutGameAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_LOGOUTGAME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcLogOutGameReplyWraper replyPBWraper = new SceneRpcLogOutGameReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->前端通知后端剧情动画播放完毕 RPC请求
	*/
	public void ShowFilmFinish(ReplyHandler replyCB)
	{
		SceneRpcShowFilmFinishAskWraper askPBWraper = new SceneRpcShowFilmFinishAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcShowFilmFinishReplyWraper replyPBWraper = new SceneRpcShowFilmFinishReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->SpecObjPos RPC请求
	*/
	public void SpecObjPos(ReplyHandler replyCB)
	{
		SceneRpcSpecObjPosAskWraper askPBWraper = new SceneRpcSpecObjPosAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_SPECOBJPOS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcSpecObjPosReplyWraper replyPBWraper = new SceneRpcSpecObjPosReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->ChangeZone RPC请求
	*/
	public void WantChangeZone(int Zoneid, ReplyHandler replyCB)
	{
		SceneRpcWantChangeZoneAskWraper askPBWraper = new SceneRpcWantChangeZoneAskWraper();
		askPBWraper.Zoneid = Zoneid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcWantChangeZoneReplyWraper replyPBWraper = new SceneRpcWantChangeZoneReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*场景模块-->返回源服 RPC请求
	*/
	public void ReturnSrcServer(ReplyHandler replyCB)
	{
		SceneRpcReturnSrcServerAskWraper askPBWraper = new SceneRpcReturnSrcServerAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SceneRpcReturnSrcServerReplyWraper replyPBWraper = new SceneRpcReturnSrcServerReplyWraper();
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
	/**
	*场景模块-->进入镜像场景 服务器通知回调
	*/
	public static void SEnterMirrorSceneCB( ModMessage notifyMsg )
	{
		SceneRpcSEnterMirrorSceneNotifyWraper notifyPBWraper = new SceneRpcSEnterMirrorSceneNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SEnterMirrorSceneCBDelegate != null )
			SEnterMirrorSceneCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SEnterMirrorSceneCBDelegate = null;
	/**
	*场景模块-->ChangeSceneLeave 服务器通知回调
	*/
	public static void ChangeSceneLeaveCB( ModMessage notifyMsg )
	{
		SceneRpcChangeSceneLeaveNotifyWraper notifyPBWraper = new SceneRpcChangeSceneLeaveNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ChangeSceneLeaveCBDelegate != null )
			ChangeSceneLeaveCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ChangeSceneLeaveCBDelegate = null;
	/**
	*场景模块-->同步场景分线繁忙状态 服务器通知回调
	*/
	public static void SyncSceneLineStatsCB( ModMessage notifyMsg )
	{
		SceneRpcSyncSceneLineStatsNotifyWraper notifyPBWraper = new SceneRpcSyncSceneLineStatsNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SyncSceneLineStatsCBDelegate != null )
			SyncSceneLineStatsCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SyncSceneLineStatsCBDelegate = null;
	/**
	*场景模块-->被提出场景 服务器通知回调
	*/
	public static void KickOutGameCB( ModMessage notifyMsg )
	{
		SceneRpcKickOutGameNotifyWraper notifyPBWraper = new SceneRpcKickOutGameNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( KickOutGameCBDelegate != null )
			KickOutGameCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback KickOutGameCBDelegate = null;
	/**
	*场景模块-->昼夜变化 服务器通知回调
	*/
	public static void DayNightChangeCB( ModMessage notifyMsg )
	{
		SceneRpcDayNightChangeNotifyWraper notifyPBWraper = new SceneRpcDayNightChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DayNightChangeCBDelegate != null )
			DayNightChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DayNightChangeCBDelegate = null;
	/**
	*场景模块-->天气变化 服务器通知回调
	*/
	public static void WeatherChangeCB( ModMessage notifyMsg )
	{
		SceneRpcWeatherChangeNotifyWraper notifyPBWraper = new SceneRpcWeatherChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( WeatherChangeCBDelegate != null )
			WeatherChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback WeatherChangeCBDelegate = null;



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
