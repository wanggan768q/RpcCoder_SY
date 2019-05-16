#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class QuestRpcOnAcceptQuestNotifyWraperHelper
{
	public QuestDataWraper AcceptQuest;
}
[System.Serializable]
public class QuestRpcCompleteQuestStepAskWraperHelper
{
	public int QuestConfigId;
	public int QuestStep;
	public int TargetId;
	public int QuestStepEventType;
}
[System.Serializable]
public class QuestRpcOnCompleteQuestNotifyWraperHelper
{
	public QuestDataWraper QuestData;
}
[System.Serializable]
public class QuestRpcCallClientLuaNotifyWraperHelper
{
	public string Str;
}
[System.Serializable]
public class QuestRpcUpdateQuestNotifyWraperHelper
{
	public QuestDataWraper Quest;
}
[System.Serializable]
public class QuestRpcGiveUpQuestAskWraperHelper
{
	public int QuestConfigId;
}
[System.Serializable]
public class QuestRpcCompleteQuestAskWraperHelper
{
	public int QuestConfigId;
	public int TargetId;
	public int QuestEventType;
}
[System.Serializable]
public class QuestRpcCompleteAcceptChatMenuAskWraperHelper
{
	public int QuestConfigId;
}
[System.Serializable]
public class QuestRpcAcceptQuestAskWraperHelper
{
	public int Type;
	public int QuestConfigId;
}
[System.Serializable]
public class QuestRpcSyncQuestAskWraperHelper
{
}
[System.Serializable]
public class QuestRpcGetRewardAskWraperHelper
{
	public int QuestConfigId;
}
[System.Serializable]
public class QuestRpcRemoveQuestNotifyNotifyWraperHelper
{
	public List<int> QuestConfigId;
}
[System.Serializable]
public class QuestRpcGetQuestDataAskWraperHelper
{
	public List<int> QuestConfigId;
}
[System.Serializable]
public class QuestRpcSyncDailyQuestAskWraperHelper
{
}
[System.Serializable]
public class QuestRpcDailyQuestUpdateNotifyWraperHelper
{
	public DailyQuestWraper AtivityQuestData;
}
[System.Serializable]
public class QuestRpcConsumeItemAskWraperHelper
{
	public int QuestConfigId;
	public List<ItemSimpleDataWraper> ItemData;
}
[System.Serializable]
public class QuestRpcQuestMaxListAskWraperHelper
{
}
[System.Serializable]
public class QuestRpcQuestMaxListNotifyNotifyWraperHelper
{
	public QuestMaxQuestListWraper QuestList;
}
[System.Serializable]
public class QuestRpcSyncCompleteQuestIdsAskWraperHelper
{
}
[System.Serializable]
public class QuestRpcCompleteQuestIdsNotifyNotifyWraperHelper
{
	public CompletedQuestListWraper CompleteQuestIds;
}
[System.Serializable]
public class QuestRpcEliteFinishCountAskWraperHelper
{
}
[System.Serializable]
public class QuestRpcSyncCanAcceptQuestNotifyWraperHelper
{
	public List<int> CanAcceptQuest;
}



public class QuestTestHelper : MonoBehaviour
{
	public QuestRpcOnAcceptQuestNotifyWraperHelper QuestRpcOnAcceptQuestNotifyWraperVar;
	public QuestRpcCompleteQuestStepAskWraperHelper QuestRpcCompleteQuestStepAskWraperVar;
	public QuestRpcOnCompleteQuestNotifyWraperHelper QuestRpcOnCompleteQuestNotifyWraperVar;
	public QuestRpcCallClientLuaNotifyWraperHelper QuestRpcCallClientLuaNotifyWraperVar;
	public QuestRpcUpdateQuestNotifyWraperHelper QuestRpcUpdateQuestNotifyWraperVar;
	public QuestRpcGiveUpQuestAskWraperHelper QuestRpcGiveUpQuestAskWraperVar;
	public QuestRpcCompleteQuestAskWraperHelper QuestRpcCompleteQuestAskWraperVar;
	public QuestRpcCompleteAcceptChatMenuAskWraperHelper QuestRpcCompleteAcceptChatMenuAskWraperVar;
	public QuestRpcAcceptQuestAskWraperHelper QuestRpcAcceptQuestAskWraperVar;
	public QuestRpcSyncQuestAskWraperHelper QuestRpcSyncQuestAskWraperVar;
	public QuestRpcGetRewardAskWraperHelper QuestRpcGetRewardAskWraperVar;
	public QuestRpcRemoveQuestNotifyNotifyWraperHelper QuestRpcRemoveQuestNotifyNotifyWraperVar;
	public QuestRpcGetQuestDataAskWraperHelper QuestRpcGetQuestDataAskWraperVar;
	public QuestRpcSyncDailyQuestAskWraperHelper QuestRpcSyncDailyQuestAskWraperVar;
	public QuestRpcDailyQuestUpdateNotifyWraperHelper QuestRpcDailyQuestUpdateNotifyWraperVar;
	public QuestRpcConsumeItemAskWraperHelper QuestRpcConsumeItemAskWraperVar;
	public QuestRpcQuestMaxListAskWraperHelper QuestRpcQuestMaxListAskWraperVar;
	public QuestRpcQuestMaxListNotifyNotifyWraperHelper QuestRpcQuestMaxListNotifyNotifyWraperVar;
	public QuestRpcSyncCompleteQuestIdsAskWraperHelper QuestRpcSyncCompleteQuestIdsAskWraperVar;
	public QuestRpcCompleteQuestIdsNotifyNotifyWraperHelper QuestRpcCompleteQuestIdsNotifyNotifyWraperVar;
	public QuestRpcEliteFinishCountAskWraperHelper QuestRpcEliteFinishCountAskWraperVar;
	public QuestRpcSyncCanAcceptQuestNotifyWraperHelper QuestRpcSyncCanAcceptQuestNotifyWraperVar;


	public void TestCompleteQuestStep()
	{
		QuestRPC.Instance.CompleteQuestStep(QuestRpcCompleteQuestStepAskWraperVar.QuestConfigId,QuestRpcCompleteQuestStepAskWraperVar.QuestStep,QuestRpcCompleteQuestStepAskWraperVar.TargetId,QuestRpcCompleteQuestStepAskWraperVar.QuestStepEventType,delegate(object obj){});
	}
	public void TestGiveUpQuest()
	{
		QuestRPC.Instance.GiveUpQuest(QuestRpcGiveUpQuestAskWraperVar.QuestConfigId,delegate(object obj){});
	}
	public void TestCompleteQuest()
	{
		QuestRPC.Instance.CompleteQuest(QuestRpcCompleteQuestAskWraperVar.QuestConfigId,QuestRpcCompleteQuestAskWraperVar.TargetId,QuestRpcCompleteQuestAskWraperVar.QuestEventType,delegate(object obj){});
	}
	public void TestCompleteAcceptChatMenu()
	{
		QuestRPC.Instance.CompleteAcceptChatMenu(QuestRpcCompleteAcceptChatMenuAskWraperVar.QuestConfigId,delegate(object obj){});
	}
	public void TestAcceptQuest()
	{
		QuestRPC.Instance.AcceptQuest(QuestRpcAcceptQuestAskWraperVar.Type,QuestRpcAcceptQuestAskWraperVar.QuestConfigId,delegate(object obj){});
	}
	public void TestSyncQuest()
	{
		QuestRPC.Instance.SyncQuest(delegate(object obj){});
	}
	public void TestGetReward()
	{
		QuestRPC.Instance.GetReward(QuestRpcGetRewardAskWraperVar.QuestConfigId,delegate(object obj){});
	}
	public void TestGetQuestData()
	{
		QuestRPC.Instance.GetQuestData(QuestRpcGetQuestDataAskWraperVar.QuestConfigId,delegate(object obj){});
	}
	public void TestSyncDailyQuest()
	{
		QuestRPC.Instance.SyncDailyQuest(delegate(object obj){});
	}
	public void TestConsumeItem()
	{
		QuestRPC.Instance.ConsumeItem(QuestRpcConsumeItemAskWraperVar.QuestConfigId,QuestRpcConsumeItemAskWraperVar.ItemData,delegate(object obj){});
	}
	public void TestSyncCompleteQuestIds()
	{
		QuestRPC.Instance.SyncCompleteQuestIds(delegate(object obj){});
	}
	public void TestEliteFinishCount()
	{
		QuestRPC.Instance.EliteFinishCount(delegate(object obj){});
	}


}

[CustomEditor(typeof(QuestTestHelper))]
public class QuestTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("CompleteQuestStep"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestCompleteQuestStep();
		}
		if (GUILayout.Button("GiveUpQuest"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestGiveUpQuest();
		}
		if (GUILayout.Button("CompleteQuest"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestCompleteQuest();
		}
		if (GUILayout.Button("CompleteAcceptChatMenu"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestCompleteAcceptChatMenu();
		}
		if (GUILayout.Button("AcceptQuest"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestAcceptQuest();
		}
		if (GUILayout.Button("SyncQuest"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestSyncQuest();
		}
		if (GUILayout.Button("GetReward"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestGetReward();
		}
		if (GUILayout.Button("GetQuestData"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestGetQuestData();
		}
		if (GUILayout.Button("SyncDailyQuest"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestSyncDailyQuest();
		}
		if (GUILayout.Button("ConsumeItem"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestConsumeItem();
		}
		if (GUILayout.Button("SyncCompleteQuestIds"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestSyncCompleteQuestIds();
		}
		if (GUILayout.Button("EliteFinishCount"))
		{
			QuestTestHelper rpc = target as QuestTestHelper;
			if( rpc ) rpc.TestEliteFinishCount();
		}


    }

}
#endif