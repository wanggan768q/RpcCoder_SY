/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleQuest.cs
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


public class QuestRPC
{
	public const int ModuleId = 15;
	
	public const int RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY = 1551;
	public const int RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST = 1552;
	public const int RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY = 1553;
	public const int RPC_CODE_QUEST_UPDATEQUEST_NOTIFY = 1554;
	public const int RPC_CODE_QUEST_GIVEUPQUEST_REQUEST = 1555;
	public const int RPC_CODE_QUEST_COMPLETEQUEST_REQUEST = 1556;
	public const int RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST = 1557;
	public const int RPC_CODE_QUEST_ACCEPTQUEST_REQUEST = 1558;
	public const int RPC_CODE_QUEST_SYNCQUEST_REQUEST = 1559;
	public const int RPC_CODE_QUEST_GETREWARD_REQUEST = 1560;
	public const int RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY = 1561;
	public const int RPC_CODE_QUEST_GETQUESTDATA_REQUEST = 1562;
	public const int RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST = 1563;
	public const int RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY = 1564;
	public const int RPC_CODE_QUEST_CONSUMEITEM_REQUEST = 1565;
	public const int RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST = 1566;
	public const int RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY = 1567;
	public const int RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST = 1568;
	public const int RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY = 1569;

	
	private static QuestRPC m_Instance = null;
	public static QuestRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new QuestRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, QuestData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY, OnAcceptQuestCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY, OnCompleteQuestCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_UPDATEQUEST_NOTIFY, UpdateQuestCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY, RemoveQuestNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY, DailyQuestUpdateCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY, CompleteQuestIdsNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY, SyncCanAcceptQuestCB);


		return true;
	}


	/**
	*Quest-->CompleteQuestStep RPC请求
	*/
	public void CompleteQuestStep(int QuestConfigId, int QuestStep, int TargetId, int QuestStepEventType, ReplyHandler replyCB)
	{
		QuestRpcCompleteQuestStepAskWraper askPBWraper = new QuestRpcCompleteQuestStepAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		askPBWraper.QuestStep = QuestStep;
		askPBWraper.TargetId = TargetId;
		askPBWraper.QuestStepEventType = QuestStepEventType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcCompleteQuestStepReplyWraper replyPBWraper = new QuestRpcCompleteQuestStepReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->放弃任务 RPC请求
	*/
	public void GiveUpQuest(int QuestConfigId, ReplyHandler replyCB)
	{
		QuestRpcGiveUpQuestAskWraper askPBWraper = new QuestRpcGiveUpQuestAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_GIVEUPQUEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcGiveUpQuestReplyWraper replyPBWraper = new QuestRpcGiveUpQuestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->完成任务 RPC请求
	*/
	public void CompleteQuest(int QuestConfigId, int TargetId, int QuestEventType, ReplyHandler replyCB)
	{
		QuestRpcCompleteQuestAskWraper askPBWraper = new QuestRpcCompleteQuestAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		askPBWraper.TargetId = TargetId;
		askPBWraper.QuestEventType = QuestEventType;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_COMPLETEQUEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcCompleteQuestReplyWraper replyPBWraper = new QuestRpcCompleteQuestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->完成接受任务对话框 RPC请求
	*/
	public void CompleteAcceptChatMenu(int QuestConfigId, ReplyHandler replyCB)
	{
		QuestRpcCompleteAcceptChatMenuAskWraper askPBWraper = new QuestRpcCompleteAcceptChatMenuAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcCompleteAcceptChatMenuReplyWraper replyPBWraper = new QuestRpcCompleteAcceptChatMenuReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->客户端接受任务 RPC请求
	*/
	public void AcceptQuest(int Type, int QuestConfigId, ReplyHandler replyCB)
	{
		QuestRpcAcceptQuestAskWraper askPBWraper = new QuestRpcAcceptQuestAskWraper();
		askPBWraper.Type = Type;
		askPBWraper.QuestConfigId = QuestConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_ACCEPTQUEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcAcceptQuestReplyWraper replyPBWraper = new QuestRpcAcceptQuestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->SyncQuest RPC请求
	*/
	public void SyncQuest(ReplyHandler replyCB)
	{
		QuestRpcSyncQuestAskWraper askPBWraper = new QuestRpcSyncQuestAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_SYNCQUEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcSyncQuestReplyWraper replyPBWraper = new QuestRpcSyncQuestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->GetReward RPC请求
	*/
	public void GetReward(int QuestConfigId, ReplyHandler replyCB)
	{
		QuestRpcGetRewardAskWraper askPBWraper = new QuestRpcGetRewardAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_GETREWARD_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcGetRewardReplyWraper replyPBWraper = new QuestRpcGetRewardReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->获取某个任务数据 RPC请求
	*/
	public void GetQuestData(List<int> QuestConfigId, ReplyHandler replyCB)
	{
		QuestRpcGetQuestDataAskWraper askPBWraper = new QuestRpcGetQuestDataAskWraper();
		askPBWraper.SetQuestConfigId(QuestConfigId);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_GETQUESTDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcGetQuestDataReplyWraper replyPBWraper = new QuestRpcGetQuestDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->每日活动 RPC请求
	*/
	public void SyncDailyQuest(ReplyHandler replyCB)
	{
		QuestRpcSyncDailyQuestAskWraper askPBWraper = new QuestRpcSyncDailyQuestAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcSyncDailyQuestReplyWraper replyPBWraper = new QuestRpcSyncDailyQuestReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->任务消耗物品 RPC请求
	*/
	public void ConsumeItem(int QuestConfigId, List<ItemSimpleDataWraper> ItemData, ReplyHandler replyCB)
	{
		QuestRpcConsumeItemAskWraper askPBWraper = new QuestRpcConsumeItemAskWraper();
		askPBWraper.QuestConfigId = QuestConfigId;
		askPBWraper.SetItemData(ItemData);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_CONSUMEITEM_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcConsumeItemReplyWraper replyPBWraper = new QuestRpcConsumeItemReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->完成任务id请求 RPC请求
	*/
	public void SyncCompleteQuestIds(ReplyHandler replyCB)
	{
		QuestRpcSyncCompleteQuestIdsAskWraper askPBWraper = new QuestRpcSyncCompleteQuestIdsAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcSyncCompleteQuestIdsReplyWraper replyPBWraper = new QuestRpcSyncCompleteQuestIdsReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*Quest-->精英怪击杀次数 RPC请求
	*/
	public void EliteFinishCount(ReplyHandler replyCB)
	{
		QuestRpcEliteFinishCountAskWraper askPBWraper = new QuestRpcEliteFinishCountAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			QuestRpcEliteFinishCountReplyWraper replyPBWraper = new QuestRpcEliteFinishCountReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*Quest-->OnAcceptQuest 服务器通知回调
	*/
	public static void OnAcceptQuestCB( ModMessage notifyMsg )
	{
		QuestRpcOnAcceptQuestNotifyWraper notifyPBWraper = new QuestRpcOnAcceptQuestNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OnAcceptQuestCBDelegate != null )
			OnAcceptQuestCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OnAcceptQuestCBDelegate = null;
	/**
	*Quest-->OnCompleteQuest 服务器通知回调
	*/
	public static void OnCompleteQuestCB( ModMessage notifyMsg )
	{
		QuestRpcOnCompleteQuestNotifyWraper notifyPBWraper = new QuestRpcOnCompleteQuestNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( OnCompleteQuestCBDelegate != null )
			OnCompleteQuestCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback OnCompleteQuestCBDelegate = null;
	/**
	*Quest-->更新任务 服务器通知回调
	*/
	public static void UpdateQuestCB( ModMessage notifyMsg )
	{
		QuestRpcUpdateQuestNotifyWraper notifyPBWraper = new QuestRpcUpdateQuestNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UpdateQuestCBDelegate != null )
			UpdateQuestCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UpdateQuestCBDelegate = null;
	/**
	*Quest-->上次任务通知 服务器通知回调
	*/
	public static void RemoveQuestNotifyCB( ModMessage notifyMsg )
	{
		QuestRpcRemoveQuestNotifyNotifyWraper notifyPBWraper = new QuestRpcRemoveQuestNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RemoveQuestNotifyCBDelegate != null )
			RemoveQuestNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RemoveQuestNotifyCBDelegate = null;
	/**
	*Quest-->每日活动任务更新 服务器通知回调
	*/
	public static void DailyQuestUpdateCB( ModMessage notifyMsg )
	{
		QuestRpcDailyQuestUpdateNotifyWraper notifyPBWraper = new QuestRpcDailyQuestUpdateNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DailyQuestUpdateCBDelegate != null )
			DailyQuestUpdateCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DailyQuestUpdateCBDelegate = null;
	/**
	*Quest-->完成的任务列表 服务器通知回调
	*/
	public static void CompleteQuestIdsNotifyCB( ModMessage notifyMsg )
	{
		QuestRpcCompleteQuestIdsNotifyNotifyWraper notifyPBWraper = new QuestRpcCompleteQuestIdsNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( CompleteQuestIdsNotifyCBDelegate != null )
			CompleteQuestIdsNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback CompleteQuestIdsNotifyCBDelegate = null;
	/**
	*Quest-->通知新可接任务 服务器通知回调
	*/
	public static void SyncCanAcceptQuestCB( ModMessage notifyMsg )
	{
		QuestRpcSyncCanAcceptQuestNotifyWraper notifyPBWraper = new QuestRpcSyncCanAcceptQuestNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SyncCanAcceptQuestCBDelegate != null )
			SyncCanAcceptQuestCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SyncCanAcceptQuestCBDelegate = null;



}

public class QuestData
{
	public enum SyncIdE
	{

	}
	
	private static QuestData m_Instance = null;
	public static QuestData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new QuestData();
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
			Ex.Logger.Log("QuestData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
