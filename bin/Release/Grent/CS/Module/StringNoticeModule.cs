/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleStringNotice.cs
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


public class StringNoticeRPC
{
	public const int ModuleId = 55;
	
	public const int RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY = 5551;

	
	private static StringNoticeRPC m_Instance = null;
	public static StringNoticeRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new StringNoticeRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, StringNoticeData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY, NoticeCB);


		return true;
	}



	/**
	*文本提示-->通知 服务器通知回调
	*/
	public static void NoticeCB( ModMessage notifyMsg )
	{
		StringNoticeRpcNoticeNotifyWraper notifyPBWraper = new StringNoticeRpcNoticeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NoticeCBDelegate != null )
			NoticeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NoticeCBDelegate = null;



}

public class StringNoticeData
{
	public enum SyncIdE
	{

	}
	
	private static StringNoticeData m_Instance = null;
	public static StringNoticeData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new StringNoticeData();
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
			Ex.Logger.Log("StringNoticeData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
