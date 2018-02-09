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
