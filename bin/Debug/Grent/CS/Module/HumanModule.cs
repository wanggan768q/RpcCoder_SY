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
	public const int RPC_CODE_HUMAN_RESPAWN_REQUEST = 454;
	public const int RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY = 455;
	public const int RPC_CODE_HUMAN_MOVEPOS_REQUEST = 456;
	public const int RPC_CODE_HUMAN_ROLEDIE_NOTIFY = 457;
	public const int RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY = 458;
	public const int RPC_CODE_HUMAN_FUNCNOTICE_REQUEST = 459;
	public const int RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST = 460;
	public const int RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY = 461;
	public const int RPC_CODE_HUMAN_TIMECHECK_NOTIFY = 462;
	public const int RPC_CODE_HUMAN_MOTIONFLAGS_NOTIFY = 463;
	public const int RPC_CODE_HUMAN_RUSH_REQUEST = 464;
	public const int RPC_CODE_HUMAN_STARE_REQUEST = 465;
	public const int RPC_CODE_HUMAN_CHANGEPOSITION_NOTIFY = 466;
	public const int RPC_CODE_HUMAN_ATTRCHANGE_NOTIFY = 467;
	public const int RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST = 468;
	public const int RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST = 469;

	
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
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_RESPAWNOTHER_NOTIFY, RespawnOtherCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_ROLEDIE_NOTIFY, RoleDieCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, ClientAttributesCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_MOTIONFLAGS_NOTIFY, MotionFlagsCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_CHANGEPOSITION_NOTIFY, ChangePositionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_HUMAN_ATTRCHANGE_NOTIFY, AttrChangeCB);


		return true;
	}

	/**
	*玩家模块-->移动检测 RPC通知
	*/
	public void MoveCheck(UInt64 ObjId, float Dir, float X, float Y)
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
	*玩家模块-->改变动画状态 纯客户端 RPC通知
	*/
	public void ChangeAnimationState(bool AnimationState)
	{
		HumanRpcChangeAnimationStateNotifyWraper notifyPBWraper = new HumanRpcChangeAnimationStateNotifyWraper();
		notifyPBWraper.AnimationState = AnimationState;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	/**
	*玩家模块-->客户端属性双向通知 RPC通知
	*/
	public void ClientAttributes(UInt64 ObjId, bool IsTouchJoyStick, bool IsHold)
	{
		HumanRpcClientAttributesNotifyWraper notifyPBWraper = new HumanRpcClientAttributesNotifyWraper();
		notifyPBWraper.ObjId = ObjId;
		notifyPBWraper.IsTouchJoyStick = IsTouchJoyStick;
		notifyPBWraper.IsHold = IsHold;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	/**
	*玩家模块-->加速检测 RPC通知
	*/
	public void TimeCheck(Int64 Data)
	{
		HumanRpcTimeCheckNotifyWraper notifyPBWraper = new HumanRpcTimeCheckNotifyWraper();
		notifyPBWraper.Data = Data;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_HUMAN_TIMECHECK_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}


	/**
	*玩家模块-->human move RPC请求
	*/
	public void Move(float Dir, float X, float Z, UInt64 ObjId, ReplyHandler replyCB)
	{
		HumanRpcMoveAskWraper askPBWraper = new HumanRpcMoveAskWraper();
		askPBWraper.Dir = Dir;
		askPBWraper.X = X;
		askPBWraper.Z = Z;
		askPBWraper.ObjId = ObjId;
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
	public void StopMove(float Dir, int X, int Z, UInt64 ObjId, bool BrakeRush, ReplyHandler replyCB)
	{
		HumanRpcStopMoveAskWraper askPBWraper = new HumanRpcStopMoveAskWraper();
		askPBWraper.Dir = Dir;
		askPBWraper.X = X;
		askPBWraper.Z = Z;
		askPBWraper.ObjId = ObjId;
		askPBWraper.BrakeRush = BrakeRush;
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
	*玩家模块-->复活 RPC请求
	*/
	public void Respawn(int ReviveType, ReplyHandler replyCB)
	{
		HumanRpcRespawnAskWraper askPBWraper = new HumanRpcRespawnAskWraper();
		askPBWraper.ReviveType = ReviveType;
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
	*玩家模块-->MovePos RPC请求
	*/
	public void MovePos(List<Vector3IntWraper> PosList, float Dir, UInt64 ObjId, bool IsAllowChangeRunAnimation, bool IsLookAtMoving, int FromX, int FromZ, ReplyHandler replyCB)
	{
		HumanRpcMovePosAskWraper askPBWraper = new HumanRpcMovePosAskWraper();
		askPBWraper.SetPosList(PosList);
		askPBWraper.Dir = Dir;
		askPBWraper.ObjId = ObjId;
		askPBWraper.IsAllowChangeRunAnimation = IsAllowChangeRunAnimation;
		askPBWraper.IsLookAtMoving = IsLookAtMoving;
		askPBWraper.FromX = FromX;
		askPBWraper.FromZ = FromZ;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_MOVEPOS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcMovePosReplyWraper replyPBWraper = new HumanRpcMovePosReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->玩家功能预告 RPC请求
	*/
	public void FuncNotice(ReplyHandler replyCB)
	{
		HumanRpcFuncNoticeAskWraper askPBWraper = new HumanRpcFuncNoticeAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_FUNCNOTICE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcFuncNoticeReplyWraper replyPBWraper = new HumanRpcFuncNoticeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->玩家功能预告 RPC请求
	*/
	public void FuncNoticeChange(ReplyHandler replyCB)
	{
		HumanRpcFuncNoticeChangeAskWraper askPBWraper = new HumanRpcFuncNoticeChangeAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcFuncNoticeChangeReplyWraper replyPBWraper = new HumanRpcFuncNoticeChangeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->疾跑 RPC请求
	*/
	public void Rush(bool Apply, ReplyHandler replyCB)
	{
		HumanRpcRushAskWraper askPBWraper = new HumanRpcRushAskWraper();
		askPBWraper.Apply = Apply;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_RUSH_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcRushReplyWraper replyPBWraper = new HumanRpcRushReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->盯防 RPC请求
	*/
	public void Stare(bool Apply, UInt64 TargetID, float Dir, ReplyHandler replyCB)
	{
		HumanRpcStareAskWraper askPBWraper = new HumanRpcStareAskWraper();
		askPBWraper.Apply = Apply;
		askPBWraper.TargetID = TargetID;
		askPBWraper.Dir = Dir;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_STARE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcStareReplyWraper replyPBWraper = new HumanRpcStareReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->托管 RPC请求
	*/
	public void Trusteeship(bool Open, ReplyHandler replyCB)
	{
		HumanRpcTrusteeshipAskWraper askPBWraper = new HumanRpcTrusteeshipAskWraper();
		askPBWraper.Open = Open;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_TRUSTEESHIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcTrusteeshipReplyWraper replyPBWraper = new HumanRpcTrusteeshipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*玩家模块-->改名 RPC请求
	*/
	public void ChangePlayerName(string PlayerName, ReplyHandler replyCB)
	{
		HumanRpcChangePlayerNameAskWraper askPBWraper = new HumanRpcChangePlayerNameAskWraper();
		askPBWraper.PlayerName = PlayerName;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_HUMAN_CHANGEPLAYERNAME_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HumanRpcChangePlayerNameReplyWraper replyPBWraper = new HumanRpcChangePlayerNameReplyWraper();
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
	*玩家模块-->复活其他玩家通知 服务器通知回调
	*/
	public static void RespawnOtherCB( ModMessage notifyMsg )
	{
		HumanRpcRespawnOtherNotifyWraper notifyPBWraper = new HumanRpcRespawnOtherNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RespawnOtherCBDelegate != null )
			RespawnOtherCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RespawnOtherCBDelegate = null;
	/**
	*玩家模块-->死亡通知 服务器通知回调
	*/
	public static void RoleDieCB( ModMessage notifyMsg )
	{
		HumanRpcRoleDieNotifyWraper notifyPBWraper = new HumanRpcRoleDieNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RoleDieCBDelegate != null )
			RoleDieCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RoleDieCBDelegate = null;
	/**
	*玩家模块-->客户端属性双向通知 服务器通知回调
	*/
	public static void ClientAttributesCB( ModMessage notifyMsg )
	{
		HumanRpcClientAttributesNotifyWraper notifyPBWraper = new HumanRpcClientAttributesNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ClientAttributesCBDelegate != null )
			ClientAttributesCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ClientAttributesCBDelegate = null;
	/**
	*玩家模块-->移动标志刷新 服务器通知回调
	*/
	public static void MotionFlagsCB( ModMessage notifyMsg )
	{
		HumanRpcMotionFlagsNotifyWraper notifyPBWraper = new HumanRpcMotionFlagsNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MotionFlagsCBDelegate != null )
			MotionFlagsCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MotionFlagsCBDelegate = null;
	/**
	*玩家模块-->瞬移 服务器通知回调
	*/
	public static void ChangePositionCB( ModMessage notifyMsg )
	{
		HumanRpcChangePositionNotifyWraper notifyPBWraper = new HumanRpcChangePositionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ChangePositionCBDelegate != null )
			ChangePositionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ChangePositionCBDelegate = null;
	/**
	*玩家模块-->属性变化值 服务器通知回调
	*/
	public static void AttrChangeCB( ModMessage notifyMsg )
	{
		HumanRpcAttrChangeNotifyWraper notifyPBWraper = new HumanRpcAttrChangeNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( AttrChangeCBDelegate != null )
			AttrChangeCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback AttrChangeCBDelegate = null;



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
