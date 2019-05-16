#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class PvpRpcRankAskWraperHelper
{
	public int PvpType;
}
[System.Serializable]
public class PvpRpcMatchAskWraperHelper
{
	public int PvpType;
}
[System.Serializable]
public class PvpRpcMatchNotifyNotifyWraperHelper
{
}
[System.Serializable]
public class PvpRpcMatchCancleAskWraperHelper
{
}
[System.Serializable]
public class PvpRpcMatchCancleNotifyNotifyWraperHelper
{
	public UInt64 RoleId;
	public string Name;
	public int Reason;
}
[System.Serializable]
public class PvpRpcPlayerReadyAskWraperHelper
{
	public int OpreationType;
}
[System.Serializable]
public class PvpRpcPlayerReadyNotifyNotifyWraperHelper
{
	public UInt64 RoleId;
	public int OpType;
}
[System.Serializable]
public class PvpRpcReadyFaildNotifyWraperHelper
{
	public int Reason;
	public UInt64 RoleId;
}
[System.Serializable]
public class PvpRpcPvpBattleStartNotifyWraperHelper
{
	public int LeftKill;
	public int RightKill;
	public int NeedKill;
}
[System.Serializable]
public class PvpRpcPvpBattleEndNotifyWraperHelper
{
	public PvpBattleEndInfoWraper BattleEndInfo;
}
[System.Serializable]
public class PvpRpcMatchSucessNotifyWraperHelper
{
	public List<PvpPlayerInfoWraper> LeftTeam;
	public List<PvpPlayerInfoWraper> RightTeam;
	public int Time;
}
[System.Serializable]
public class PvpRpcRankChangeNotifyWraperHelper
{
	public int PvpType;
	public int BeforeRank;
	public int AfterRank;
	public int BeforeStar;
	public int AfterStar;
}
[System.Serializable]
public class PvpRpcReturnLastSceneAskWraperHelper
{
}
[System.Serializable]
public class PvpRpcArenaStartTimeNotifyWraperHelper
{
	public int NeedTime;
	public int TimeStamp;
}
[System.Serializable]
public class PvpRpcUpdateKillCountNotifyWraperHelper
{
	public int LeftTeamKill;
	public int RightTeamKill;
}
[System.Serializable]
public class PvpRpcArenaLeftTimeNotifyWraperHelper
{
	public int LeftTime;
}
[System.Serializable]
public class PvpRpcLastRankAskWraperHelper
{
	public int PvpType;
}
[System.Serializable]
public class PvpRpcNewSeasonNotifyWraperHelper
{
	public int LastRank;
	public int LastStar;
	public int LastRanking;
	public List<PvpBattleRewardInfoWraper> RewardList;
}
[System.Serializable]
public class PvpRpcGetSeasonRewardAskWraperHelper
{
}
[System.Serializable]
public class PvpRpcPvpBattleInfoSyncAskWraperHelper
{
}
[System.Serializable]
public class PvpRpcReconnectNotifyWraperHelper
{
	public int NeedKill;
	public int ArenaState;
	public int LeftTime;
	public int LeftKill;
	public int RightKill;
	public int Camp;
	public int TimeStamp;
}
[System.Serializable]
public class PvpRpcGetRewardAskWraperHelper
{
	public int PvPType;
	public int Rank;
}



public class PvpTestHelper : MonoBehaviour
{
	public PvpRpcRankAskWraperHelper PvpRpcRankAskWraperVar;
	public PvpRpcMatchAskWraperHelper PvpRpcMatchAskWraperVar;
	public PvpRpcMatchNotifyNotifyWraperHelper PvpRpcMatchNotifyNotifyWraperVar;
	public PvpRpcMatchCancleAskWraperHelper PvpRpcMatchCancleAskWraperVar;
	public PvpRpcMatchCancleNotifyNotifyWraperHelper PvpRpcMatchCancleNotifyNotifyWraperVar;
	public PvpRpcPlayerReadyAskWraperHelper PvpRpcPlayerReadyAskWraperVar;
	public PvpRpcPlayerReadyNotifyNotifyWraperHelper PvpRpcPlayerReadyNotifyNotifyWraperVar;
	public PvpRpcReadyFaildNotifyWraperHelper PvpRpcReadyFaildNotifyWraperVar;
	public PvpRpcPvpBattleStartNotifyWraperHelper PvpRpcPvpBattleStartNotifyWraperVar;
	public PvpRpcPvpBattleEndNotifyWraperHelper PvpRpcPvpBattleEndNotifyWraperVar;
	public PvpRpcMatchSucessNotifyWraperHelper PvpRpcMatchSucessNotifyWraperVar;
	public PvpRpcRankChangeNotifyWraperHelper PvpRpcRankChangeNotifyWraperVar;
	public PvpRpcReturnLastSceneAskWraperHelper PvpRpcReturnLastSceneAskWraperVar;
	public PvpRpcArenaStartTimeNotifyWraperHelper PvpRpcArenaStartTimeNotifyWraperVar;
	public PvpRpcUpdateKillCountNotifyWraperHelper PvpRpcUpdateKillCountNotifyWraperVar;
	public PvpRpcArenaLeftTimeNotifyWraperHelper PvpRpcArenaLeftTimeNotifyWraperVar;
	public PvpRpcLastRankAskWraperHelper PvpRpcLastRankAskWraperVar;
	public PvpRpcNewSeasonNotifyWraperHelper PvpRpcNewSeasonNotifyWraperVar;
	public PvpRpcGetSeasonRewardAskWraperHelper PvpRpcGetSeasonRewardAskWraperVar;
	public PvpRpcPvpBattleInfoSyncAskWraperHelper PvpRpcPvpBattleInfoSyncAskWraperVar;
	public PvpRpcReconnectNotifyWraperHelper PvpRpcReconnectNotifyWraperVar;
	public PvpRpcGetRewardAskWraperHelper PvpRpcGetRewardAskWraperVar;


	public void TestRank()
	{
		PvpRPC.Instance.Rank(PvpRpcRankAskWraperVar.PvpType,delegate(object obj){});
	}
	public void TestMatch()
	{
		PvpRPC.Instance.Match(PvpRpcMatchAskWraperVar.PvpType,delegate(object obj){});
	}
	public void TestMatchCancle()
	{
		PvpRPC.Instance.MatchCancle(delegate(object obj){});
	}
	public void TestPvpBattleInfoSync()
	{
		PvpRPC.Instance.PvpBattleInfoSync(delegate(object obj){});
	}
	public void TestPlayerReady()
	{
		PvpRPC.Instance.PlayerReady(PvpRpcPlayerReadyAskWraperVar.OpreationType,delegate(object obj){});
	}
	public void TestReturnLastScene()
	{
		PvpRPC.Instance.ReturnLastScene(delegate(object obj){});
	}
	public void TestLastRank()
	{
		PvpRPC.Instance.LastRank(PvpRpcLastRankAskWraperVar.PvpType,delegate(object obj){});
	}
	public void TestGetSeasonReward()
	{
		PvpRPC.Instance.GetSeasonReward(delegate(object obj){});
	}
	public void TestGetReward()
	{
		PvpRPC.Instance.GetReward(PvpRpcGetRewardAskWraperVar.PvPType,PvpRpcGetRewardAskWraperVar.Rank,delegate(object obj){});
	}


}

[CustomEditor(typeof(PvpTestHelper))]
public class PvpTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Rank"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestRank();
		}
		if (GUILayout.Button("Match"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestMatch();
		}
		if (GUILayout.Button("MatchCancle"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestMatchCancle();
		}
		if (GUILayout.Button("PvpBattleInfoSync"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestPvpBattleInfoSync();
		}
		if (GUILayout.Button("PlayerReady"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestPlayerReady();
		}
		if (GUILayout.Button("ReturnLastScene"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestReturnLastScene();
		}
		if (GUILayout.Button("LastRank"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestLastRank();
		}
		if (GUILayout.Button("GetSeasonReward"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestGetSeasonReward();
		}
		if (GUILayout.Button("GetReward"))
		{
			PvpTestHelper rpc = target as PvpTestHelper;
			if( rpc ) rpc.TestGetReward();
		}


    }

}
#endif