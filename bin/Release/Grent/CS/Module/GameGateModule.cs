/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleGameGate.cs
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


public class GameGateRPC
{
	public const int ModuleId = 24;
	
	public const int RPC_CODE_GAMEGATE_GAMEGATECHANGESCENE_NOTIFY = 2451;

	
	private static GameGateRPC m_Instance = null;
	public static GameGateRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GameGateRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, GameGateData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GAMEGATE_GAMEGATECHANGESCENE_NOTIFY, GameGateChangeSceneCB);


		return true;
	}



	/**
	*游戏网关间消息-->GameGateChangeScene 服务器通知回调
	*/
	public static void GameGateChangeSceneCB( ModMessage notifyMsg )
	{
		GameGateRpcGameGateChangeSceneNotifyWraper notifyPBWraper = new GameGateRpcGameGateChangeSceneNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( GameGateChangeSceneCBDelegate != null )
			GameGateChangeSceneCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback GameGateChangeSceneCBDelegate = null;



}

public class GameGateData
{
	public enum SyncIdE
	{

	}
	
	private static GameGateData m_Instance = null;
	public static GameGateData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GameGateData();
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
			Ex.Logger.Log("GameGateData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
