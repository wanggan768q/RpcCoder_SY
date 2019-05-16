/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleDropItem.cs
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


public class DropItemRPC
{
	public const int ModuleId = 20;
	
	public const int RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY = 2051;

	
	private static DropItemRPC m_Instance = null;
	public static DropItemRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new DropItemRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, DropItemData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY, DropTtemsCB);


		return true;
	}



	/**
	*掉落-->掉落通知 服务器通知回调
	*/
	public static void DropTtemsCB( ModMessage notifyMsg )
	{
		DropItemRpcDropTtemsNotifyWraper notifyPBWraper = new DropItemRpcDropTtemsNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DropTtemsCBDelegate != null )
			DropTtemsCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DropTtemsCBDelegate = null;



}

public class DropItemData
{
	public enum SyncIdE
	{

	}
	
	private static DropItemData m_Instance = null;
	public static DropItemData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new DropItemData();
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
			Ex.Logger.Log("DropItemData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
