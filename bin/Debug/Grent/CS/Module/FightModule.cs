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


		return true;
	}

	/**
	*战斗-->使用技能动作 RPC通知
	*/
	public void UseSkillAction(int ObjTargetId, int SkillId, int X, int Y, int Dir)
	{
		FightRpcUseSkillActionNotifyWraper notifyPBWraper = new FightRpcUseSkillActionNotifyWraper();
		notifyPBWraper.ObjTargetId = ObjTargetId;
		notifyPBWraper.SkillId = SkillId;
		notifyPBWraper.X = X;
		notifyPBWraper.Y = Y;
		notifyPBWraper.Dir = Dir;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = RPC_CODE_FIGHT_USESKILLACTION_NOTIFY;
		notifyMsg.protoMS = notifyPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendNotify(notifyMsg);
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
