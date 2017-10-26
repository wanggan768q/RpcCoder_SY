/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 Module$Template$.cs
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


public class $Template$RPC
{
	public const int ModuleId = $ModId$;
	
$MsgIdList$
	
	private static $Template$RPC m_Instance = null;
	public static $Template$RPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new $Template$RPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, $Template$Data.Instance.UpdateField );
		
$RegisterCB$

		return true;
	}

$NotifyRpc$
$InteractRpc$
$NotifyCallback$


}

public class $Template$Data
{
	public enum SyncIdE
	{
$SyncIdList$
	}
	
	private static $Template$Data m_Instance = null;
	public static $Template$Data Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new $Template$Data();
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
$updateSyncField$
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
			Ex.Logger.Log("$Template$Data.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  
$masterDataWraper$

}
