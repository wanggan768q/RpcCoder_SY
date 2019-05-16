/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleGG.cs
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


public class GGRPC
{
	public const int ModuleId = 0;
	
	public const int RPC_CODE_GG_GGCHANGESCENE_NOTIFY = 51;

	
	private static GGRPC m_Instance = null;
	public static GGRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GGRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, GGData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GG_GGCHANGESCENE_NOTIFY, GGChangeSceneCB);


		return true;
	}



	/**
	*游戏网关间消息-->GGChangeScene 服务器通知回调
	*/
	public static void GGChangeSceneCB( ModMessage notifyMsg )
	{
		GGRpcGGChangeSceneNotifyWraper notifyPBWraper = new GGRpcGGChangeSceneNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( GGChangeSceneCBDelegate != null )
			GGChangeSceneCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback GGChangeSceneCBDelegate = null;



}

public class GGData
{
	public enum SyncIdE
	{

	}
	
	private static GGData m_Instance = null;
	public static GGData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GGData();
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
			Ex.Logger.Log("GGData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
