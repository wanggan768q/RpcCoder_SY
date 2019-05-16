/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleWelfare.cs
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


public class WelfareRPC
{
	public const int ModuleId = 42;
	
	public const int RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST = 4251;
	public const int RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST = 4252;
	public const int RPC_CODE_WELFARE_ONLINEBONUS_REQUEST = 4253;
	public const int RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST = 4254;
	public const int RPC_CODE_WELFARE_LEVELBONUS_REQUEST = 4255;
	public const int RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST = 4256;
	public const int RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST = 4257;
	public const int RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST = 4258;
	public const int RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY = 4259;
	public const int RPC_CODE_WELFARE_SPECLOGIN_NOTIFY = 4260;
	public const int RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST = 4261;

	
	private static WelfareRPC m_Instance = null;
	public static WelfareRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WelfareRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, WelfareData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY, TodaySignInCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_WELFARE_SPECLOGIN_NOTIFY, SpecLoginCB);


		return true;
	}


	/**
	*福利-->累计登陆福利 RPC请求
	*/
	public void AccumulateSignIn(ReplyHandler replyCB)
	{
		WelfareRpcAccumulateSignInAskWraper askPBWraper = new WelfareRpcAccumulateSignInAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcAccumulateSignInReplyWraper replyPBWraper = new WelfareRpcAccumulateSignInReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->领取累计登陆奖励 RPC请求
	*/
	public void AccumulateGetReward(int ID, ReplyHandler replyCB)
	{
		WelfareRpcAccumulateGetRewardAskWraper askPBWraper = new WelfareRpcAccumulateGetRewardAskWraper();
		askPBWraper.ID = ID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcAccumulateGetRewardReplyWraper replyPBWraper = new WelfareRpcAccumulateGetRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->今日在线福利 RPC请求
	*/
	public void OnlineBonus(ReplyHandler replyCB)
	{
		WelfareRpcOnlineBonusAskWraper askPBWraper = new WelfareRpcOnlineBonusAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_ONLINEBONUS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcOnlineBonusReplyWraper replyPBWraper = new WelfareRpcOnlineBonusReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->领取今日在线奖励 RPC请求
	*/
	public void OnlineGetReward(int ID, ReplyHandler replyCB)
	{
		WelfareRpcOnlineGetRewardAskWraper askPBWraper = new WelfareRpcOnlineGetRewardAskWraper();
		askPBWraper.ID = ID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcOnlineGetRewardReplyWraper replyPBWraper = new WelfareRpcOnlineGetRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->等级福利 RPC请求
	*/
	public void LevelBonus(ReplyHandler replyCB)
	{
		WelfareRpcLevelBonusAskWraper askPBWraper = new WelfareRpcLevelBonusAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_LEVELBONUS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcLevelBonusReplyWraper replyPBWraper = new WelfareRpcLevelBonusReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->领取等级福利奖励 RPC请求
	*/
	public void LevelBonusReward(int ID, ReplyHandler replyCB)
	{
		WelfareRpcLevelBonusRewardAskWraper askPBWraper = new WelfareRpcLevelBonusRewardAskWraper();
		askPBWraper.ID = ID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcLevelBonusRewardReplyWraper replyPBWraper = new WelfareRpcLevelBonusRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->签到福利 RPC请求
	*/
	public void MonthSignInBonus(ReplyHandler replyCB)
	{
		WelfareRpcMonthSignInBonusAskWraper askPBWraper = new WelfareRpcMonthSignInBonusAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcMonthSignInBonusReplyWraper replyPBWraper = new WelfareRpcMonthSignInBonusReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->签到 RPC请求
	*/
	public void MonthSignInReward(int ID, ReplyHandler replyCB)
	{
		WelfareRpcMonthSignInRewardAskWraper askPBWraper = new WelfareRpcMonthSignInRewardAskWraper();
		askPBWraper.ID = ID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcMonthSignInRewardReplyWraper replyPBWraper = new WelfareRpcMonthSignInRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*福利-->运营登录活动领取奖励 RPC请求
	*/
	public void SpecLoginReward(int Id, int Index, ReplyHandler replyCB)
	{
		WelfareRpcSpecLoginRewardAskWraper askPBWraper = new WelfareRpcSpecLoginRewardAskWraper();
		askPBWraper.Id = Id;
		askPBWraper.Index = Index;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			WelfareRpcSpecLoginRewardReplyWraper replyPBWraper = new WelfareRpcSpecLoginRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*福利-->今日签到提醒 服务器通知回调
	*/
	public static void TodaySignInCB( ModMessage notifyMsg )
	{
		WelfareRpcTodaySignInNotifyWraper notifyPBWraper = new WelfareRpcTodaySignInNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TodaySignInCBDelegate != null )
			TodaySignInCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TodaySignInCBDelegate = null;
	/**
	*福利-->运营登录活动 服务器通知回调
	*/
	public static void SpecLoginCB( ModMessage notifyMsg )
	{
		WelfareRpcSpecLoginNotifyWraper notifyPBWraper = new WelfareRpcSpecLoginNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SpecLoginCBDelegate != null )
			SpecLoginCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SpecLoginCBDelegate = null;



}

public class WelfareData
{
	public enum SyncIdE
	{

	}
	
	private static WelfareData m_Instance = null;
	public static WelfareData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new WelfareData();
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
			Ex.Logger.Log("WelfareData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
