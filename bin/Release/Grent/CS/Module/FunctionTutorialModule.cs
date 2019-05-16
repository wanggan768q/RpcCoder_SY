/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleFunctionTutorial.cs
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


public class FunctionTutorialRPC
{
	public const int ModuleId = 45;
	
	public const int RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST = 4551;
	public const int RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST = 4552;
	public const int RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST = 4553;

	
	private static FunctionTutorialRPC m_Instance = null;
	public static FunctionTutorialRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FunctionTutorialRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, FunctionTutorialData.Instance.UpdateField );
		


		return true;
	}


	/**
	*功能引导-->同步 RPC请求
	*/
	public void SyncFunctionStep(ReplyHandler replyCB)
	{
		FunctionTutorialRpcSyncFunctionStepAskWraper askPBWraper = new FunctionTutorialRpcSyncFunctionStepAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FunctionTutorialRpcSyncFunctionStepReplyWraper replyPBWraper = new FunctionTutorialRpcSyncFunctionStepReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*功能引导-->完成 RPC请求
	*/
	public void FinishStep(int FunctionID, ReplyHandler replyCB)
	{
		FunctionTutorialRpcFinishStepAskWraper askPBWraper = new FunctionTutorialRpcFinishStepAskWraper();
		askPBWraper.FunctionID = FunctionID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FunctionTutorialRpcFinishStepReplyWraper replyPBWraper = new FunctionTutorialRpcFinishStepReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*功能引导-->激活步骤 RPC请求
	*/
	public void ActiveStep(int FunctionID, ReplyHandler replyCB)
	{
		FunctionTutorialRpcActiveStepAskWraper askPBWraper = new FunctionTutorialRpcActiveStepAskWraper();
		askPBWraper.FunctionID = FunctionID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FunctionTutorialRpcActiveStepReplyWraper replyPBWraper = new FunctionTutorialRpcActiveStepReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class FunctionTutorialData
{
	public enum SyncIdE
	{

	}
	
	private static FunctionTutorialData m_Instance = null;
	public static FunctionTutorialData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FunctionTutorialData();
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
			Ex.Logger.Log("FunctionTutorialData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
