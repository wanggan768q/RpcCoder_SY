/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleMedicament.cs
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


public class MedicamentRPC
{
	public const int ModuleId = 28;
	
	public const int RPC_CODE_MEDICAMENT_FILLHP_REQUEST = 2851;
	public const int RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST = 2852;
	public const int RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST = 2853;
	public const int RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY = 2854;
	public const int RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST = 2855;
	public const int RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST = 2856;
	public const int RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY = 2857;

	
	private static MedicamentRPC m_Instance = null;
	public static MedicamentRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MedicamentRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, MedicamentData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY, ServerRefreshMedicamentCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY, MedicamentCDNotifyCB);


		return true;
	}


	/**
	*药剂-->使用物品填充hp池 RPC请求
	*/
	public void FillHp(ItemSimpleDataWraper ItemData, ReplyHandler replyCB)
	{
		MedicamentRpcFillHpAskWraper askPBWraper = new MedicamentRpcFillHpAskWraper();
		askPBWraper.ItemData = ItemData;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MEDICAMENT_FILLHP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MedicamentRpcFillHpReplyWraper replyPBWraper = new MedicamentRpcFillHpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*药剂-->一键添加 RPC请求
	*/
	public void OneStepFillHp(List<ItemSimpleDataWraper> ItemData, ReplyHandler replyCB)
	{
		MedicamentRpcOneStepFillHpAskWraper askPBWraper = new MedicamentRpcOneStepFillHpAskWraper();
		askPBWraper.SetItemData(ItemData);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MedicamentRpcOneStepFillHpReplyWraper replyPBWraper = new MedicamentRpcOneStepFillHpReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*药剂-->客户端刷新药剂 RPC请求
	*/
	public void ClientRefreshMedicament(RecoverMedicamentWraper Medicament, ReplyHandler replyCB)
	{
		MedicamentRpcClientRefreshMedicamentAskWraper askPBWraper = new MedicamentRpcClientRefreshMedicamentAskWraper();
		askPBWraper.Medicament = Medicament;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MedicamentRpcClientRefreshMedicamentReplyWraper replyPBWraper = new MedicamentRpcClientRefreshMedicamentReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*药剂-->请求数据 RPC请求
	*/
	public void SyncMedicamentData(ReplyHandler replyCB)
	{
		MedicamentRpcSyncMedicamentDataAskWraper askPBWraper = new MedicamentRpcSyncMedicamentDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MedicamentRpcSyncMedicamentDataReplyWraper replyPBWraper = new MedicamentRpcSyncMedicamentDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*药剂-->药剂CD RPC请求
	*/
	public void MedicamentCD(ReplyHandler replyCB)
	{
		MedicamentRpcMedicamentCDAskWraper askPBWraper = new MedicamentRpcMedicamentCDAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MedicamentRpcMedicamentCDReplyWraper replyPBWraper = new MedicamentRpcMedicamentCDReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*药剂-->服务器刷新药剂 服务器通知回调
	*/
	public static void ServerRefreshMedicamentCB( ModMessage notifyMsg )
	{
		MedicamentRpcServerRefreshMedicamentNotifyWraper notifyPBWraper = new MedicamentRpcServerRefreshMedicamentNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ServerRefreshMedicamentCBDelegate != null )
			ServerRefreshMedicamentCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ServerRefreshMedicamentCBDelegate = null;
	/**
	*药剂-->通知CD 服务器通知回调
	*/
	public static void MedicamentCDNotifyCB( ModMessage notifyMsg )
	{
		MedicamentRpcMedicamentCDNotifyNotifyWraper notifyPBWraper = new MedicamentRpcMedicamentCDNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( MedicamentCDNotifyCBDelegate != null )
			MedicamentCDNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback MedicamentCDNotifyCBDelegate = null;



}

public class MedicamentData
{
	public enum SyncIdE
	{

	}
	
	private static MedicamentData m_Instance = null;
	public static MedicamentData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MedicamentData();
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
			Ex.Logger.Log("MedicamentData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
