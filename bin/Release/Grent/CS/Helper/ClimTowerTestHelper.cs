#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ClimTowerRpcOpenRuleNotifyWraperHelper
{
}
[System.Serializable]
public class ClimTowerRpcChallengeAskWraperHelper
{
	public int Layer;
}
[System.Serializable]
public class ClimTowerRpcEnterAskWraperHelper
{
}
[System.Serializable]
public class ClimTowerRpcRankAskWraperHelper
{
}
[System.Serializable]
public class ClimTowerRpcFirstVicRewardAskWraperHelper
{
	public int Layer;
}
[System.Serializable]
public class ClimTowerRpcNextLayerNotifyWraperHelper
{
	public int CurLayer;
}
[System.Serializable]
public class ClimTowerRpcChallengeEndNotifyWraperHelper
{
}
[System.Serializable]
public class ClimTowerRpcWaveRefreshNotifyWraperHelper
{
	public int AllWaves;
	public int CurWave;
}



public class ClimTowerTestHelper : MonoBehaviour
{
	public ClimTowerRpcOpenRuleNotifyWraperHelper ClimTowerRpcOpenRuleNotifyWraperVar;
	public ClimTowerRpcChallengeAskWraperHelper ClimTowerRpcChallengeAskWraperVar;
	public ClimTowerRpcEnterAskWraperHelper ClimTowerRpcEnterAskWraperVar;
	public ClimTowerRpcRankAskWraperHelper ClimTowerRpcRankAskWraperVar;
	public ClimTowerRpcFirstVicRewardAskWraperHelper ClimTowerRpcFirstVicRewardAskWraperVar;
	public ClimTowerRpcNextLayerNotifyWraperHelper ClimTowerRpcNextLayerNotifyWraperVar;
	public ClimTowerRpcChallengeEndNotifyWraperHelper ClimTowerRpcChallengeEndNotifyWraperVar;
	public ClimTowerRpcWaveRefreshNotifyWraperHelper ClimTowerRpcWaveRefreshNotifyWraperVar;


	public void TestEnter()
	{
		ClimTowerRPC.Instance.Enter(delegate(object obj){});
	}
	public void TestChallenge()
	{
		ClimTowerRPC.Instance.Challenge(ClimTowerRpcChallengeAskWraperVar.Layer,delegate(object obj){});
	}
	public void TestRank()
	{
		ClimTowerRPC.Instance.Rank(delegate(object obj){});
	}
	public void TestFirstVicReward()
	{
		ClimTowerRPC.Instance.FirstVicReward(ClimTowerRpcFirstVicRewardAskWraperVar.Layer,delegate(object obj){});
	}


}

[CustomEditor(typeof(ClimTowerTestHelper))]
public class ClimTowerTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Enter"))
		{
			ClimTowerTestHelper rpc = target as ClimTowerTestHelper;
			if( rpc ) rpc.TestEnter();
		}
		if (GUILayout.Button("Challenge"))
		{
			ClimTowerTestHelper rpc = target as ClimTowerTestHelper;
			if( rpc ) rpc.TestChallenge();
		}
		if (GUILayout.Button("Rank"))
		{
			ClimTowerTestHelper rpc = target as ClimTowerTestHelper;
			if( rpc ) rpc.TestRank();
		}
		if (GUILayout.Button("FirstVicReward"))
		{
			ClimTowerTestHelper rpc = target as ClimTowerTestHelper;
			if( rpc ) rpc.TestFirstVicReward();
		}


    }

}
#endif