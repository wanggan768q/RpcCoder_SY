#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class CampFigthRpcMilitaryBrokenAskWraperHelper
{
	public int RoleID;
}
[System.Serializable]
public class CampFigthRpcCampFightContributionNotifyWraperHelper
{
	public int Camp;
	public int ContributionValue;
}
[System.Serializable]
public class CampFigthRpcObjKillBroadcastNotifyWraperHelper
{
	public int KillerObjID;
	public int KillerName;
	public int DeadObjID;
	public int DeadObjResID;
}
[System.Serializable]
public class CampFigthRpcNpcBirthNotifyWraperHelper
{
	public int Camp;
	public int BirthObjID;
	public int BirthObjResID;
}
[System.Serializable]
public class CampFigthRpcGetMilitaryValueAskWraperHelper
{
	public int RoleID;
}
[System.Serializable]
public class CampFigthRpcKillDeadInfoNotifyWraperHelper
{
	public int KillNum;
	public int DeadNum;
	public int Rank;
	public int Exp;
	public int Star;
}
[System.Serializable]
public class CampFigthRpcWorshipAskWraperHelper
{
	public int WorshipRoleID;
}
[System.Serializable]
public class CampFigthRpcWorshipRankAskWraperHelper
{
	public int RoleID;
}
[System.Serializable]
public class CampFigthRpcNewSeasonNotifyWraperHelper
{
	public int Rank;
	public int Star;
	public int RankIndex;
	public List<PvpBattleRewardInfoWraper> RewardList;
	public int Lastseason;
}
[System.Serializable]
public class CampFigthRpcSyncRankRewardAskWraperHelper
{
}
[System.Serializable]
public class CampFigthRpcGetRankRewardAskWraperHelper
{
	public int Rank;
}
[System.Serializable]
public class CampFigthRpcEnterBattleSceneAskWraperHelper
{
}



public class CampFigthTestHelper : MonoBehaviour
{
	public CampFigthRpcMilitaryBrokenAskWraperHelper CampFigthRpcMilitaryBrokenAskWraperVar;
	public CampFigthRpcCampFightContributionNotifyWraperHelper CampFigthRpcCampFightContributionNotifyWraperVar;
	public CampFigthRpcObjKillBroadcastNotifyWraperHelper CampFigthRpcObjKillBroadcastNotifyWraperVar;
	public CampFigthRpcNpcBirthNotifyWraperHelper CampFigthRpcNpcBirthNotifyWraperVar;
	public CampFigthRpcGetMilitaryValueAskWraperHelper CampFigthRpcGetMilitaryValueAskWraperVar;
	public CampFigthRpcKillDeadInfoNotifyWraperHelper CampFigthRpcKillDeadInfoNotifyWraperVar;
	public CampFigthRpcWorshipAskWraperHelper CampFigthRpcWorshipAskWraperVar;
	public CampFigthRpcWorshipRankAskWraperHelper CampFigthRpcWorshipRankAskWraperVar;
	public CampFigthRpcNewSeasonNotifyWraperHelper CampFigthRpcNewSeasonNotifyWraperVar;
	public CampFigthRpcSyncRankRewardAskWraperHelper CampFigthRpcSyncRankRewardAskWraperVar;
	public CampFigthRpcGetRankRewardAskWraperHelper CampFigthRpcGetRankRewardAskWraperVar;
	public CampFigthRpcEnterBattleSceneAskWraperHelper CampFigthRpcEnterBattleSceneAskWraperVar;


	public void TestMilitaryBroken()
	{
		CampFigthRPC.Instance.MilitaryBroken(CampFigthRpcMilitaryBrokenAskWraperVar.RoleID,delegate(object obj){});
	}
	public void TestGetMilitaryValue()
	{
		CampFigthRPC.Instance.GetMilitaryValue(CampFigthRpcGetMilitaryValueAskWraperVar.RoleID,delegate(object obj){});
	}
	public void TestWorship()
	{
		CampFigthRPC.Instance.Worship(CampFigthRpcWorshipAskWraperVar.WorshipRoleID,delegate(object obj){});
	}
	public void TestWorshipRank()
	{
		CampFigthRPC.Instance.WorshipRank(CampFigthRpcWorshipRankAskWraperVar.RoleID,delegate(object obj){});
	}
	public void TestSyncRankReward()
	{
		CampFigthRPC.Instance.SyncRankReward(delegate(object obj){});
	}
	public void TestGetRankReward()
	{
		CampFigthRPC.Instance.GetRankReward(CampFigthRpcGetRankRewardAskWraperVar.Rank,delegate(object obj){});
	}
	public void TestEnterBattleScene()
	{
		CampFigthRPC.Instance.EnterBattleScene(delegate(object obj){});
	}


}

[CustomEditor(typeof(CampFigthTestHelper))]
public class CampFigthTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("MilitaryBroken"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestMilitaryBroken();
		}
		if (GUILayout.Button("GetMilitaryValue"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestGetMilitaryValue();
		}
		if (GUILayout.Button("Worship"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestWorship();
		}
		if (GUILayout.Button("WorshipRank"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestWorshipRank();
		}
		if (GUILayout.Button("SyncRankReward"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestSyncRankReward();
		}
		if (GUILayout.Button("GetRankReward"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestGetRankReward();
		}
		if (GUILayout.Button("EnterBattleScene"))
		{
			CampFigthTestHelper rpc = target as CampFigthTestHelper;
			if( rpc ) rpc.TestEnterBattleScene();
		}


    }

}
#endif