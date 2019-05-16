/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleLobbyServer.cs
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


public class LobbyServerRPC
{
	public const int ModuleId = 36;
	
	public const int RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST = 3651;

	
	private static LobbyServerRPC m_Instance = null;
	public static LobbyServerRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LobbyServerRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, LobbyServerData.Instance.UpdateField );
		


		return true;
	}


	/**
	*大厅服务器-->获取服务器列表 RPC请求
	*/
	public void GetServerList(string Sdk_user_id, ReplyHandler replyCB)
	{
		LobbyServerRpcGetServerListAskWraper askPBWraper = new LobbyServerRpcGetServerListAskWraper();
		askPBWraper.Sdk_user_id = Sdk_user_id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LobbyServerRpcGetServerListReplyWraper replyPBWraper = new LobbyServerRpcGetServerListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class LobbyServerData
{
	public enum SyncIdE
	{

	}
	
	private static LobbyServerData m_Instance = null;
	public static LobbyServerData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LobbyServerData();
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
			Ex.Logger.Log("LobbyServerData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
