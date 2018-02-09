/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleHuman.cs
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


public class HumanRPC
{
	public const int ModuleId = 4;
	
	public const int RPC_CODE_HUMAN_MOVE_REQUEST = 451;
	public const int RPC_CODE_HUMAN_STOPMOVE_REQUEST = 452;
	public const int RPC_CODE_HUMAN_MOVECHECK_NOTIFY = 453;
	public const int RPC_CODE_HUMAN_MOVEBYPOS_NOTIFY = 454;
	public const int RPC_CODE_HUMAN_RESPAWN_REQUEST = 455;

	
	private static HumanRPC m_Instance = null;
	public static HumanRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new HumanRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, HumanData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_MOVECHECK_NOTIFY, MoveCheckCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_MOVEBYPOS_NOTIFY, MoveByPosCB);


		return true;
	}

	/**
	*玩家模块-->移动检测 RPC通知
	*/
	public void MoveCheck(int ObjId, float Dir, float X, float Y)
	{
		HumanRpcMoveCheckNotifyWraper notifyPBWraper = new HumanRpcMoveCheckNotifyWraper();
		notifyPBWraper.ObjId = ObjId;
		notifyPBWraper.Dir = Dir;
		notifyPBWraper.X = X;
		notifyPBWraper.Y = Y;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_HUMAN_MOVECHECK_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}


	/**
	*玩家模块-->human move RPC请求
	*/
	public void Move(float Dir, float X, float Z, ReplyHandler replyCB)
	{
		HumanRpcMoveAskWraper askPBWraper = new HumanRpcMoveAskWraper();
		askPBWraper.Dir = Dir;
		askPBWraper.X = X;
		askPBWraper.Z = Z;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_MOVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcMoveReplyWraper replyPBWraper = new HumanRpcMoveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->客户端停止移动 RPC请求
	*/
	public void StopMove(float Dir, float X, float Z, ReplyHandler replyCB)
	{
		HumanRpcStopMoveAskWraper askPBWraper = new HumanRpcStopMoveAskWraper();
		askPBWraper.Dir = Dir;
		askPBWraper.X = X;
		askPBWraper.Z = Z;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_STOPMOVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcStopMoveReplyWraper replyPBWraper = new HumanRpcStopMoveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->Respawn RPC请求
	*/
	public void Respawn(ReplyHandler replyCB)
	{
		HumanRpcRespawnAskWraper askPBWraper = new HumanRpcRespawnAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_RESPAWN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcRespawnReplyWraper replyPBWraper = new HumanRpcRespawnReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*玩家模块-->移动检测 服务器通知回调
	*/
	public static void MoveCheckCB( ModMessage notifyMsg )
	{
		HumanRpcMoveCheckNotifyWraper notifyPBWraper = new HumanRpcMoveCheckNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MoveCheckCBDelegate != null )
			MoveCheckCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MoveCheckCBDelegate = null;
	/**
	*玩家模块-->按照点来移动 服务器通知回调
	*/
	public static void MoveByPosCB( ModMessage notifyMsg )
	{
		HumanRpcMoveByPosNotifyWraper notifyPBWraper = new HumanRpcMoveByPosNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MoveByPosCBDelegate != null )
			MoveByPosCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MoveByPosCBDelegate = null;



}

public class HumanData
{
	public enum SyncIdE
	{

	}
	
	private static HumanData m_Instance = null;
	public static HumanData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new HumanData();
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
			Ex.Logger.Log("HumanData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
