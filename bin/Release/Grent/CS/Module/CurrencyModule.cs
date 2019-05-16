/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleCurrency.cs
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


public class CurrencyRPC
{
	public const int ModuleId = 19;
	
	public const int RPC_CODE_CURRENCY_TRANSFROM_REQUEST = 1951;
	public const int RPC_CODE_CURRENCY_SHOW_REQUEST = 1952;

	
	private static CurrencyRPC m_Instance = null;
	public static CurrencyRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CurrencyRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, CurrencyData.Instance.UpdateField );
		


		return true;
	}


	/**
	*货币-->货币兑换 RPC请求
	*/
	public void Transfrom(int To_type, int From_type, Int64 From_num, Int64 Diamond_bind_num, ReplyHandler replyCB)
	{
		CurrencyRpcTransfromAskWraper askPBWraper = new CurrencyRpcTransfromAskWraper();
		askPBWraper.To_type = To_type;
		askPBWraper.From_type = From_type;
		askPBWraper.From_num = From_num;
		askPBWraper.Diamond_bind_num = Diamond_bind_num;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CURRENCY_TRANSFROM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CurrencyRpcTransfromReplyWraper replyPBWraper = new CurrencyRpcTransfromReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*货币-->货币展示 RPC请求
	*/
	public void Show(ReplyHandler replyCB)
	{
		CurrencyRpcShowAskWraper askPBWraper = new CurrencyRpcShowAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CURRENCY_SHOW_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			CurrencyRpcShowReplyWraper replyPBWraper = new CurrencyRpcShowReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class CurrencyData
{
	public enum SyncIdE
	{

	}
	
	private static CurrencyData m_Instance = null;
	public static CurrencyData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new CurrencyData();
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
			Ex.Logger.Log("CurrencyData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
