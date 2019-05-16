/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleServerModel.cs
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


public class ServerModelRPC
{
	public const int ModuleId = 3;
	
	public const int RPC_CODE_SERVERMODEL_LOGIN_REQUEST = 351;

	
	private static ServerModelRPC m_Instance = null;
	public static ServerModelRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ServerModelRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ServerModelData.Instance.UpdateField );
		


		return true;
	}


	/**
	*服务器内部模块-->服务器使用登录 RPC请求
	*/
	public void Login(int Result, int Type, string TestString, ReplyHandler replyCB)
	{
		ServerModelRpcLoginAskWraper askPBWraper = new ServerModelRpcLoginAskWraper();
		askPBWraper.Result = Result;
		askPBWraper.Type = Type;
		askPBWraper.TestString = TestString;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_SERVERMODEL_LOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ServerModelRpcLoginReplyWraper replyPBWraper = new ServerModelRpcLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class ServerModelData
{
	public enum SyncIdE
	{

	}
	
	private static ServerModelData m_Instance = null;
	public static ServerModelData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ServerModelData();
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
			Ex.Logger.Log("ServerModelData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
