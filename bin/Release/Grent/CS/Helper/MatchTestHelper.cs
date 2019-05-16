#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class MatchRpcAutoMatchAskWraperHelper
{
	public PlayerMatchDataWraper MatchInfo;
}
[System.Serializable]
public class MatchRpcCancelMatchAskWraperHelper
{
}
[System.Serializable]
public class MatchRpcCancelMatchNotifyNotifyWraperHelper
{
}
[System.Serializable]
public class MatchRpcPrepareRoomNotifyWraperHelper
{
	public PBMatchRoomWraper ReadyRoom;
}
[System.Serializable]
public class MatchRpcReadyAskWraperHelper
{
	public int MatchType;
	public UInt64 RoomId;
}
[System.Serializable]
public class MatchRpcCancelReadyAskWraperHelper
{
	public int MatchType;
	public UInt64 RoomId;
}
[System.Serializable]
public class MatchRpcRoomCancelNotifyWraperHelper
{
}
[System.Serializable]
public class MatchRpcMemberReadyNotifyWraperHelper
{
	public UInt64 RoleId;
}



public class MatchTestHelper : MonoBehaviour
{
	public MatchRpcAutoMatchAskWraperHelper MatchRpcAutoMatchAskWraperVar;
	public MatchRpcCancelMatchAskWraperHelper MatchRpcCancelMatchAskWraperVar;
	public MatchRpcCancelMatchNotifyNotifyWraperHelper MatchRpcCancelMatchNotifyNotifyWraperVar;
	public MatchRpcPrepareRoomNotifyWraperHelper MatchRpcPrepareRoomNotifyWraperVar;
	public MatchRpcReadyAskWraperHelper MatchRpcReadyAskWraperVar;
	public MatchRpcCancelReadyAskWraperHelper MatchRpcCancelReadyAskWraperVar;
	public MatchRpcRoomCancelNotifyWraperHelper MatchRpcRoomCancelNotifyWraperVar;
	public MatchRpcMemberReadyNotifyWraperHelper MatchRpcMemberReadyNotifyWraperVar;


	public void TestAutoMatch()
	{
		MatchRPC.Instance.AutoMatch(MatchRpcAutoMatchAskWraperVar.MatchInfo,delegate(object obj){});
	}
	public void TestCancelMatch()
	{
		MatchRPC.Instance.CancelMatch(delegate(object obj){});
	}
	public void TestReady()
	{
		MatchRPC.Instance.Ready(MatchRpcReadyAskWraperVar.MatchType,MatchRpcReadyAskWraperVar.RoomId,delegate(object obj){});
	}
	public void TestCancelReady()
	{
		MatchRPC.Instance.CancelReady(MatchRpcCancelReadyAskWraperVar.MatchType,MatchRpcCancelReadyAskWraperVar.RoomId,delegate(object obj){});
	}


}

[CustomEditor(typeof(MatchTestHelper))]
public class MatchTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("AutoMatch"))
		{
			MatchTestHelper rpc = target as MatchTestHelper;
			if( rpc ) rpc.TestAutoMatch();
		}
		if (GUILayout.Button("CancelMatch"))
		{
			MatchTestHelper rpc = target as MatchTestHelper;
			if( rpc ) rpc.TestCancelMatch();
		}
		if (GUILayout.Button("Ready"))
		{
			MatchTestHelper rpc = target as MatchTestHelper;
			if( rpc ) rpc.TestReady();
		}
		if (GUILayout.Button("CancelReady"))
		{
			MatchTestHelper rpc = target as MatchTestHelper;
			if( rpc ) rpc.TestCancelReady();
		}


    }

}
#endif