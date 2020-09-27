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
	
	public const int RPC_CODE_LOGIN_LOGIN_REQUEST = 251;
	public const int RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST = 252;
	public const int RPC_CODE_LOGIN_CREATECHARACTER_REQUEST = 253;
	public const int RPC_CODE_LOGIN_DELETECHARACTER_REQUEST = 254;
	public const int RPC_CODE_LOGIN_TEST_REQUEST = 255;
	public const int RPC_CODE_LOGIN_TEST1_REQUEST = 256;
	public const int RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY = 257;
	public const int RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY = 258;
	public const int RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST = 259;
	public const int RPC_CODE_LOGIN_REMOTELOGIN_REQUEST = 260;

	
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
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY, LoginLineUpCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY, LoginEnterGameCB);


		return true;
	}


	/**
	*登录模块-->登录 RPC请求
	*/
	public void Login(string Username, string Passwd, string SnId, string GameId, string Mac, string Token, string Version, ReplyHandler replyCB)
	{
		LoginRpcLoginAskWraper askPBWraper = new LoginRpcLoginAskWraper();
		askPBWraper.Username = Username;
		askPBWraper.Passwd = Passwd;
		askPBWraper.SnId = SnId;
		askPBWraper.GameId = GameId;
		askPBWraper.Mac = Mac;
		askPBWraper.Token = Token;
		askPBWraper.Version = Version;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_LOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcLoginReplyWraper replyPBWraper = new LoginRpcLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->选择角色 RPC请求
	*/
	public void SelectCharacter(UInt64 RoleId, ReplyHandler replyCB)
	{
		LoginRpcSelectCharacterAskWraper askPBWraper = new LoginRpcSelectCharacterAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcSelectCharacterReplyWraper replyPBWraper = new LoginRpcSelectCharacterReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->创建角色 RPC请求
	*/
	public void CreateCharacter(string Nickname, int ConfigId, PinchFaceDataWraper PinchData, string PushRegId, ReplyHandler replyCB)
	{
		LoginRpcCreateCharacterAskWraper askPBWraper = new LoginRpcCreateCharacterAskWraper();
		askPBWraper.Nickname = Nickname;
		askPBWraper.ConfigId = ConfigId;
		askPBWraper.PinchData = PinchData;
		askPBWraper.PushRegId = PushRegId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_CREATECHARACTER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcCreateCharacterReplyWraper replyPBWraper = new LoginRpcCreateCharacterReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->删除角色 RPC请求
	*/
	public void DeleteCharacter(UInt64 RoleId, ReplyHandler replyCB)
	{
		LoginRpcDeleteCharacterAskWraper askPBWraper = new LoginRpcDeleteCharacterAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_DELETECHARACTER_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcDeleteCharacterReplyWraper replyPBWraper = new LoginRpcDeleteCharacterReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->Test RPC请求
	*/
	public void Test(List<Int64> A, List<UInt64> B, ReplyHandler replyCB)
	{
		LoginRpcTestAskWraper askPBWraper = new LoginRpcTestAskWraper();
		askPBWraper.SetA(A);
		askPBWraper.SetB(B);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_TEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcTestReplyWraper replyPBWraper = new LoginRpcTestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->Test1 RPC请求
	*/
	public void Test1(List<UInt64> B, ReplyHandler replyCB)
	{
		LoginRpcTest1AskWraper askPBWraper = new LoginRpcTest1AskWraper();
		askPBWraper.SetB(B);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_TEST1_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcTest1ReplyWraper replyPBWraper = new LoginRpcTest1ReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->退出排队 RPC请求
	*/
	public void LoginQuitLineUp(ReplyHandler replyCB)
	{
		LoginRpcLoginQuitLineUpAskWraper askPBWraper = new LoginRpcLoginQuitLineUpAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_LOGINQUITLINEUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcLoginQuitLineUpReplyWraper replyPBWraper = new LoginRpcLoginQuitLineUpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*登录模块-->login RPC请求
	*/
	public void RemoteLogin(UInt64 Roleid, ReplyHandler replyCB)
	{
		LoginRpcRemoteLoginAskWraper askPBWraper = new LoginRpcRemoteLoginAskWraper();
		askPBWraper.Roleid = Roleid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_LOGIN_REMOTELOGIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcRemoteLoginReplyWraper replyPBWraper = new LoginRpcRemoteLoginReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*登录模块-->登录 排队通知 服务器通知回调
	*/
	public static void LoginLineUpCB( ModMessage notifyMsg )
	{
		LoginRpcLoginLineUpNotifyWraper notifyPBWraper = new LoginRpcLoginLineUpNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( LoginLineUpCBDelegate != null )
			LoginLineUpCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback LoginLineUpCBDelegate = null;
	/**
	*登录模块-->可以登录服务器的通知 服务器通知回调
	*/
	public static void LoginEnterGameCB( ModMessage notifyMsg )
	{
		LoginRpcLoginEnterGameNotifyWraper notifyPBWraper = new LoginRpcLoginEnterGameNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( LoginEnterGameCBDelegate != null )
			LoginEnterGameCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback LoginEnterGameCBDelegate = null;



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
