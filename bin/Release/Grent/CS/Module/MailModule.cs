/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleMail.cs
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


public class MailRPC
{
	public const int ModuleId = 30;
	
	public const int RPC_CODE_MAIL_INITMAIL_REQUEST = 3051;
	public const int RPC_CODE_MAIL_READMAIL_REQUEST = 3052;
	public const int RPC_CODE_MAIL_DELETEMAIL_REQUEST = 3053;
	public const int RPC_CODE_MAIL_GETMAIL_REQUEST = 3054;
	public const int RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY = 3055;

	
	private static MailRPC m_Instance = null;
	public static MailRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MailRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, MailData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY, SyncMailInfoCB);


		return true;
	}


	/**
	*邮件-->初始化邮件信息 RPC请求
	*/
	public void InitMail(ReplyHandler replyCB)
	{
		MailRpcInitMailAskWraper askPBWraper = new MailRpcInitMailAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MAIL_INITMAIL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MailRpcInitMailReplyWraper replyPBWraper = new MailRpcInitMailReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*邮件-->已读邮件 RPC请求
	*/
	public void ReadMail(int Mail_type, int Mail_id, ReplyHandler replyCB)
	{
		MailRpcReadMailAskWraper askPBWraper = new MailRpcReadMailAskWraper();
		askPBWraper.Mail_type = Mail_type;
		askPBWraper.Mail_id = Mail_id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MAIL_READMAIL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MailRpcReadMailReplyWraper replyPBWraper = new MailRpcReadMailReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*邮件-->删除邮件 RPC请求
	*/
	public void DeleteMail(int Mail_type, int Mail_id, ReplyHandler replyCB)
	{
		MailRpcDeleteMailAskWraper askPBWraper = new MailRpcDeleteMailAskWraper();
		askPBWraper.Mail_type = Mail_type;
		askPBWraper.Mail_id = Mail_id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MAIL_DELETEMAIL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MailRpcDeleteMailReplyWraper replyPBWraper = new MailRpcDeleteMailReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*邮件-->领取邮件 RPC请求
	*/
	public void GetMail(int Mail_type, int Mail_id, ReplyHandler replyCB)
	{
		MailRpcGetMailAskWraper askPBWraper = new MailRpcGetMailAskWraper();
		askPBWraper.Mail_type = Mail_type;
		askPBWraper.Mail_id = Mail_id;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MAIL_GETMAIL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MailRpcGetMailReplyWraper replyPBWraper = new MailRpcGetMailReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*邮件-->同步邮件信息 服务器通知回调
	*/
	public static void SyncMailInfoCB( ModMessage notifyMsg )
	{
		MailRpcSyncMailInfoNotifyWraper notifyPBWraper = new MailRpcSyncMailInfoNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SyncMailInfoCBDelegate != null )
			SyncMailInfoCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SyncMailInfoCBDelegate = null;



}

public class MailData
{
	public enum SyncIdE
	{

	}
	
	private static MailData m_Instance = null;
	public static MailData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MailData();
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
			Ex.Logger.Log("MailData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
