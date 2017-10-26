/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleLogin.cs
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


public class LoginRPC
{
	public const int ModuleId = 2;
	
	public const int RPC_CODE_LOGIN_CONNECT_REQUEST = 251;
	public const int RPC_CODE_LOGIN_LOGIN_REQUEST = 252;

	
	private static LoginRPC m_Instance = null;
	public static LoginRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LoginRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, LoginData.Instance.UpdateField );
		


		return true;
	}


	/**
	*登录模块-->连接验证 RPC请求
	*/
	public void Connect(int Type, ReplyHandler replyCB)
	{
		LoginRpcConnectAskWraper askPBWraper = new LoginRpcConnectAskWraper();
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_CONNECT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcConnectReplyWraper replyPBWraper = new LoginRpcConnectReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->登录 RPC请求
	*/
	public void Login(string Username, string Passwd, ReplyHandler replyCB)
	{
		LoginRpcLoginAskWraper askPBWraper = new LoginRpcLoginAskWraper();
		askPBWraper.Username = Username;
		askPBWraper.Passwd = Passwd;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_LOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcLoginReplyWraper replyPBWraper = new LoginRpcLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class LoginData
{
	public enum SyncIdE
	{

	}
	
	private static LoginData m_Instance = null;
	public static LoginData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LoginData();
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
			Ex.Logger.Log("LoginData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
