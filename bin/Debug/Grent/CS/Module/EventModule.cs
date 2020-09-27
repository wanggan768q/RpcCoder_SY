/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEvent.cs
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


public class EventRPC
{
	public const int ModuleId = 5;
	
	public const int RPC_CODE_EVENT_MOVE_NOTIFY = 551;
	public const int RPC_CODE_EVENT_STOPMOVE_NOTIFY = 552;
	public const int RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY = 553;
	public const int RPC_CODE_EVENT_COINCHANGE_NOTIFY = 554;
	public const int RPC_CODE_EVENT_MOVEPOS_NOTIFY = 555;
	public const int RPC_CODE_EVENT_DIR_NOTIFY = 556;
	public const int RPC_CODE_EVENT_STARTFADEOUT_NOTIFY = 557;
	public const int RPC_CODE_EVENT_CINEMATICSTART_NOTIFY = 558;
	public const int RPC_CODE_EVENT_CINEMATICEND_NOTIFY = 559;

	
	private static EventRPC m_Instance = null;
	public static EventRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EventData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_MOVE_NOTIFY, MoveCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_STOPMOVE_NOTIFY, StopMoveCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY, ObjAttrChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_COINCHANGE_NOTIFY, CoinChangeCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_MOVEPOS_NOTIFY, MovePosCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_DIR_NOTIFY, DirCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_STARTFADEOUT_NOTIFY, StartFadeoutCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_CINEMATICSTART_NOTIFY, CinematicStartCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_EVENT_CINEMATICEND_NOTIFY, CinematicEndCB);


		return true;
	}



	/**
	*事件模块-->ObjMove 服务器通知回调
	*/
	public static void MoveCB( ModMessage notifyMsg )
	{
		EventRpcMoveNotifyWraper notifyPBWraper = new EventRpcMoveNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MoveCBDelegate != null )
			MoveCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MoveCBDelegate = null;
	/**
	*事件模块-->ObjStopMove 服务器通知回调
	*/
	public static void StopMoveCB( ModMessage notifyMsg )
	{
		EventRpcStopMoveNotifyWraper notifyPBWraper = new EventRpcStopMoveNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( StopMoveCBDelegate != null )
			StopMoveCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback StopMoveCBDelegate = null;
	/**
	*事件模块-->属性改变 服务器通知回调
	*/
	public static void ObjAttrChangeCB( ModMessage notifyMsg )
	{
		EventRpcObjAttrChangeNotifyWraper notifyPBWraper = new EventRpcObjAttrChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ObjAttrChangeCBDelegate != null )
			ObjAttrChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ObjAttrChangeCBDelegate = null;
	/**
	*事件模块-->货币的变化通知 服务器通知回调
	*/
	public static void CoinChangeCB( ModMessage notifyMsg )
	{
		EventRpcCoinChangeNotifyWraper notifyPBWraper = new EventRpcCoinChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CoinChangeCBDelegate != null )
			CoinChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CoinChangeCBDelegate = null;
	/**
	*事件模块-->按点移动 服务器通知回调
	*/
	public static void MovePosCB( ModMessage notifyMsg )
	{
		EventRpcMovePosNotifyWraper notifyPBWraper = new EventRpcMovePosNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MovePosCBDelegate != null )
			MovePosCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MovePosCBDelegate = null;
	/**
	*事件模块-->朝向 服务器通知回调
	*/
	public static void DirCB( ModMessage notifyMsg )
	{
		EventRpcDirNotifyWraper notifyPBWraper = new EventRpcDirNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DirCBDelegate != null )
			DirCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DirCBDelegate = null;
	/**
	*事件模块-->开始淡出效果 服务器通知回调
	*/
	public static void StartFadeoutCB( ModMessage notifyMsg )
	{
		EventRpcStartFadeoutNotifyWraper notifyPBWraper = new EventRpcStartFadeoutNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( StartFadeoutCBDelegate != null )
			StartFadeoutCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback StartFadeoutCBDelegate = null;
	/**
	*事件模块-->通知表演开始 服务器通知回调
	*/
	public static void CinematicStartCB( ModMessage notifyMsg )
	{
		EventRpcCinematicStartNotifyWraper notifyPBWraper = new EventRpcCinematicStartNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CinematicStartCBDelegate != null )
			CinematicStartCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CinematicStartCBDelegate = null;
	/**
	*事件模块-->通知表演结束 服务器通知回调
	*/
	public static void CinematicEndCB( ModMessage notifyMsg )
	{
		EventRpcCinematicEndNotifyWraper notifyPBWraper = new EventRpcCinematicEndNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CinematicEndCBDelegate != null )
			CinematicEndCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CinematicEndCBDelegate = null;



}

public class EventData
{
	public enum SyncIdE
	{

	}
	
	private static EventData m_Instance = null;
	public static EventData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EventData();
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
			Ex.Logger.Log("EventData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
