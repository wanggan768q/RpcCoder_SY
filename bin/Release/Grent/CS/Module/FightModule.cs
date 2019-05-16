/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleFight.cs
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


public class FightRPC
{
	public const int ModuleId = 9;
	
	public const int RPC_CODE_FIGHT_USESKILLACTION_NOTIFY = 951;
	public const int RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY = 952;
	public const int RPC_CODE_FIGHT_BUFFACTION_NOTIFY = 953;
	public const int RPC_CODE_FIGHT_STATEACTION_NOTIFY = 954;
	public const int RPC_CODE_FIGHT_REVIVEACTION_NOTIFY = 955;
	public const int RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY = 956;
	public const int RPC_CODE_FIGHT_DROPACTION_NOTIFY = 957;
	public const int RPC_CODE_FIGHT_USEITEMACTION_NOTIFY = 958;
	public const int RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY = 959;
	public const int RPC_CODE_FIGHT_USESKILL_REQUEST = 960;
	public const int RPC_CODE_FIGHT_HURTACTION_NOTIFY = 961;
	public const int RPC_CODE_FIGHT_REPELACTION_NOTIFY = 962;
	public const int RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY = 963;
	public const int RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY = 964;
	public const int RPC_CODE_FIGHT_BUFFLIST_NOTIFY = 965;
	public const int RPC_CODE_FIGHT_REDUCECD_NOTIFY = 966;
	public const int RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY = 967;

	
	private static FightRPC m_Instance = null;
	public static FightRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FightRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, FightData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_USESKILLACTION_NOTIFY, UseSkillActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_SHOWEXPACTION_NOTIFY, ShowExpActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_BUFFACTION_NOTIFY, BuffActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_STATEACTION_NOTIFY, StateActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_REVIVEACTION_NOTIFY, ReviveActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_COMBOSKILLACTION_NOTIFY, ComboSkillActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_DROPACTION_NOTIFY, DropActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_USEITEMACTION_NOTIFY, UseItemActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_HPCHANGEACTION_NOTIFY, HpChangeActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_HURTACTION_NOTIFY, HurtActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_REPELACTION_NOTIFY, RepelActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_OBJDEADACTION_NOTIFY, ObjDeadActionCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_FIGHTTIPS_NOTIFY, FightTipsCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_BUFFLIST_NOTIFY, BuffListCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_REDUCECD_NOTIFY, ReduceCDCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_FIGHT_RELIVENOTIFY_NOTIFY, ReliveNotifyCB);


		return true;
	}


	/**
	*战斗-->使用技能请求 RPC请求
	*/
	public void UseSkill(List<int> ObjTargetId, int SkillId, float CastingDir, float X, float Y, float Z, int MomentIndex, CustomSkiDataWraper CustomSkiData, ReplyHandler replyCB)
	{
		FightRpcUseSkillAskWraper askPBWraper = new FightRpcUseSkillAskWraper();
		askPBWraper.SetObjTargetId(ObjTargetId);
		askPBWraper.SkillId = SkillId;
		askPBWraper.CastingDir = CastingDir;
		askPBWraper.X = X;
		askPBWraper.Y = Y;
		askPBWraper.Z = Z;
		askPBWraper.MomentIndex = MomentIndex;
		askPBWraper.CustomSkiData = CustomSkiData;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_FIGHT_USESKILL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcUseSkillReplyWraper replyPBWraper = new FightRpcUseSkillReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*战斗-->使用技能动作 服务器通知回调
	*/
	public static void UseSkillActionCB( ModMessage notifyMsg )
	{
		FightRpcUseSkillActionNotifyWraper notifyPBWraper = new FightRpcUseSkillActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UseSkillActionCBDelegate != null )
			UseSkillActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UseSkillActionCBDelegate = null;
	/**
	*战斗-->显示经验 服务器通知回调
	*/
	public static void ShowExpActionCB( ModMessage notifyMsg )
	{
		FightRpcShowExpActionNotifyWraper notifyPBWraper = new FightRpcShowExpActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ShowExpActionCBDelegate != null )
			ShowExpActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ShowExpActionCBDelegate = null;
	/**
	*战斗-->buf 服务器通知回调
	*/
	public static void BuffActionCB( ModMessage notifyMsg )
	{
		FightRpcBuffActionNotifyWraper notifyPBWraper = new FightRpcBuffActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BuffActionCBDelegate != null )
			BuffActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BuffActionCBDelegate = null;
	/**
	*战斗-->状态事件 服务器通知回调
	*/
	public static void StateActionCB( ModMessage notifyMsg )
	{
		FightRpcStateActionNotifyWraper notifyPBWraper = new FightRpcStateActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( StateActionCBDelegate != null )
			StateActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback StateActionCBDelegate = null;
	/**
	*战斗-->复活事件 服务器通知回调
	*/
	public static void ReviveActionCB( ModMessage notifyMsg )
	{
		FightRpcReviveActionNotifyWraper notifyPBWraper = new FightRpcReviveActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReviveActionCBDelegate != null )
			ReviveActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReviveActionCBDelegate = null;
	/**
	*战斗-->连击技能 服务器通知回调
	*/
	public static void ComboSkillActionCB( ModMessage notifyMsg )
	{
		FightRpcComboSkillActionNotifyWraper notifyPBWraper = new FightRpcComboSkillActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ComboSkillActionCBDelegate != null )
			ComboSkillActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ComboSkillActionCBDelegate = null;
	/**
	*战斗-->掉落 服务器通知回调
	*/
	public static void DropActionCB( ModMessage notifyMsg )
	{
		FightRpcDropActionNotifyWraper notifyPBWraper = new FightRpcDropActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DropActionCBDelegate != null )
			DropActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DropActionCBDelegate = null;
	/**
	*战斗-->使用道具 服务器通知回调
	*/
	public static void UseItemActionCB( ModMessage notifyMsg )
	{
		FightRpcUseItemActionNotifyWraper notifyPBWraper = new FightRpcUseItemActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UseItemActionCBDelegate != null )
			UseItemActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UseItemActionCBDelegate = null;
	/**
	*战斗-->血量改变 服务器通知回调
	*/
	public static void HpChangeActionCB( ModMessage notifyMsg )
	{
		FightRpcHpChangeActionNotifyWraper notifyPBWraper = new FightRpcHpChangeActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( HpChangeActionCBDelegate != null )
			HpChangeActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback HpChangeActionCBDelegate = null;
	/**
	*战斗-->伤害事件 服务器通知回调
	*/
	public static void HurtActionCB( ModMessage notifyMsg )
	{
		FightRpcHurtActionNotifyWraper notifyPBWraper = new FightRpcHurtActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( HurtActionCBDelegate != null )
			HurtActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback HurtActionCBDelegate = null;
	/**
	*战斗-->战斗击 退、飞、撞、拉 通知 服务器通知回调
	*/
	public static void RepelActionCB( ModMessage notifyMsg )
	{
		FightRpcRepelActionNotifyWraper notifyPBWraper = new FightRpcRepelActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RepelActionCBDelegate != null )
			RepelActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RepelActionCBDelegate = null;
	/**
	*战斗-->obj死亡通知 服务器通知回调
	*/
	public static void ObjDeadActionCB( ModMessage notifyMsg )
	{
		FightRpcObjDeadActionNotifyWraper notifyPBWraper = new FightRpcObjDeadActionNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ObjDeadActionCBDelegate != null )
			ObjDeadActionCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ObjDeadActionCBDelegate = null;
	/**
	*战斗-->战斗辅助tips 服务器通知回调
	*/
	public static void FightTipsCB( ModMessage notifyMsg )
	{
		FightRpcFightTipsNotifyWraper notifyPBWraper = new FightRpcFightTipsNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( FightTipsCBDelegate != null )
			FightTipsCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback FightTipsCBDelegate = null;
	/**
	*战斗-->BuffList 服务器通知回调
	*/
	public static void BuffListCB( ModMessage notifyMsg )
	{
		FightRpcBuffListNotifyWraper notifyPBWraper = new FightRpcBuffListNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BuffListCBDelegate != null )
			BuffListCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BuffListCBDelegate = null;
	/**
	*战斗-->减少cd 服务器通知回调
	*/
	public static void ReduceCDCB( ModMessage notifyMsg )
	{
		FightRpcReduceCDNotifyWraper notifyPBWraper = new FightRpcReduceCDNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReduceCDCBDelegate != null )
			ReduceCDCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReduceCDCBDelegate = null;
	/**
	*战斗-->复活通知 服务器通知回调
	*/
	public static void ReliveNotifyCB( ModMessage notifyMsg )
	{
		FightRpcReliveNotifyNotifyWraper notifyPBWraper = new FightRpcReliveNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ReliveNotifyCBDelegate != null )
			ReliveNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ReliveNotifyCBDelegate = null;



}

public class FightData
{
	public enum SyncIdE
	{

	}
	
	private static FightData m_Instance = null;
	public static FightData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FightData();
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
			Ex.Logger.Log("FightData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
