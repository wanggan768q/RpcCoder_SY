/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleVechicle.cs
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


public class VechicleRPC
{
	public const int ModuleId = 41;
	
	public const int RPC_CODE_VECHICLE_QUITVECHILE_REQUEST = 4151;

	
	private static VechicleRPC m_Instance = null;
	public static VechicleRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new VechicleRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, VechicleData.Instance.UpdateField );
		


		return true;
	}


	/**
	*载具（变身）-->退出载具 RPC请求
	*/
	public void QuitVechile(ReplyHandler replyCB)
	{
		VechicleRpcQuitVechileAskWraper askPBWraper = new VechicleRpcQuitVechileAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_VECHICLE_QUITVECHILE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			VechicleRpcQuitVechileReplyWraper replyPBWraper = new VechicleRpcQuitVechileReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class VechicleData
{
	public enum SyncIdE
	{

	}
	
	private static VechicleData m_Instance = null;
	public static VechicleData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new VechicleData();
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
			Ex.Logger.Log("VechicleData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
