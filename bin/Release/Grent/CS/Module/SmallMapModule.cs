/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleSmallMap.cs
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


public class SmallMapRPC
{
	public const int ModuleId = 14;
	
	public const int RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY = 1451;
	public const int RPC_CODE_SMALLMAP_DELOBJ_NOTIFY = 1452;

	
	private static SmallMapRPC m_Instance = null;
	public static SmallMapRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SmallMapRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, SmallMapData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY, NewObjCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_SMALLMAP_DELOBJ_NOTIFY, DelObjCB);


		return true;
	}



	/**
	*小地图相关-->新的对象创建 服务器通知回调
	*/
	public static void NewObjCB( ModMessage notifyMsg )
	{
		SmallMapRpcNewObjNotifyWraper notifyPBWraper = new SmallMapRpcNewObjNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewObjCBDelegate != null )
			NewObjCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewObjCBDelegate = null;
	/**
	*小地图相关-->删除obj 服务器通知回调
	*/
	public static void DelObjCB( ModMessage notifyMsg )
	{
		SmallMapRpcDelObjNotifyWraper notifyPBWraper = new SmallMapRpcDelObjNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DelObjCBDelegate != null )
			DelObjCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DelObjCBDelegate = null;



}

public class SmallMapData
{
	public enum SyncIdE
	{

	}
	
	private static SmallMapData m_Instance = null;
	public static SmallMapData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SmallMapData();
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
			Ex.Logger.Log("SmallMapData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
