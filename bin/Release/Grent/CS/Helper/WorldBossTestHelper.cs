#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class WorldBossRpcWorldBossInfoAskWraperHelper
{
	public int BossID;
}
[System.Serializable]
public class WorldBossRpcWorldBossRankInfoAskWraperHelper
{
	public int BossID;
	public int Occupation;
}



public class WorldBossTestHelper : MonoBehaviour
{
	public WorldBossRpcWorldBossInfoAskWraperHelper WorldBossRpcWorldBossInfoAskWraperVar;
	public WorldBossRpcWorldBossRankInfoAskWraperHelper WorldBossRpcWorldBossRankInfoAskWraperVar;


	public void TestWorldBossInfo()
	{
		WorldBossRPC.Instance.WorldBossInfo(WorldBossRpcWorldBossInfoAskWraperVar.BossID,delegate(object obj){});
	}
	public void TestWorldBossRankInfo()
	{
		WorldBossRPC.Instance.WorldBossRankInfo(WorldBossRpcWorldBossRankInfoAskWraperVar.BossID,WorldBossRpcWorldBossRankInfoAskWraperVar.Occupation,delegate(object obj){});
	}


}

[CustomEditor(typeof(WorldBossTestHelper))]
public class WorldBossTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("WorldBossInfo"))
		{
			WorldBossTestHelper rpc = target as WorldBossTestHelper;
			if( rpc ) rpc.TestWorldBossInfo();
		}
		if (GUILayout.Button("WorldBossRankInfo"))
		{
			WorldBossTestHelper rpc = target as WorldBossTestHelper;
			if( rpc ) rpc.TestWorldBossRankInfo();
		}


    }

}
#endif