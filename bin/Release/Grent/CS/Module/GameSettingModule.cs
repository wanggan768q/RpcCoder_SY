/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleGameSetting.cs
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


public class GameSettingRPC
{
	public const int ModuleId = 53;
	
	public const int RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST = 5351;
	public const int RPC_CODE_GAMESETTING_SETTING_REQUEST = 5352;
	public const int RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY = 5353;

	
	private static GameSettingRPC m_Instance = null;
	public static GameSettingRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GameSettingRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, GameSettingData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY, GameSettingNotifyCB);


		return true;
	}


	/**
	*游戏设置-->同步 RPC请求
	*/
	public void SyncGameSetting(ReplyHandler replyCB)
	{
		GameSettingRpcSyncGameSettingAskWraper askPBWraper = new GameSettingRpcSyncGameSettingAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GameSettingRpcSyncGameSettingReplyWraper replyPBWraper = new GameSettingRpcSyncGameSettingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*游戏设置-->设置 RPC请求
	*/
	public void Setting(string GameSetting, ReplyHandler replyCB)
	{
		GameSettingRpcSettingAskWraper askPBWraper = new GameSettingRpcSettingAskWraper();
		askPBWraper.GameSetting = GameSetting;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_GAMESETTING_SETTING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			GameSettingRpcSettingReplyWraper replyPBWraper = new GameSettingRpcSettingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*游戏设置-->设置 通知 服务器通知回调
	*/
	public static void GameSettingNotifyCB( ModMessage notifyMsg )
	{
		GameSettingRpcGameSettingNotifyNotifyWraper notifyPBWraper = new GameSettingRpcGameSettingNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( GameSettingNotifyCBDelegate != null )
			GameSettingNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback GameSettingNotifyCBDelegate = null;



}

public class GameSettingData
{
	public enum SyncIdE
	{

	}
	
	private static GameSettingData m_Instance = null;
	public static GameSettingData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GameSettingData();
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
			Ex.Logger.Log("GameSettingData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
