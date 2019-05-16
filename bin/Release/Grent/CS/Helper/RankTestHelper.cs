#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class RankRpcRankAskWraperHelper
{
	public int RankType;
	public int RankSubType;
}



public class RankTestHelper : MonoBehaviour
{
	public RankRpcRankAskWraperHelper RankRpcRankAskWraperVar;


	public void TestRank()
	{
		RankRPC.Instance.Rank(RankRpcRankAskWraperVar.RankType,RankRpcRankAskWraperVar.RankSubType,delegate(object obj){});
	}


}

[CustomEditor(typeof(RankTestHelper))]
public class RankTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Rank"))
		{
			RankTestHelper rpc = target as RankTestHelper;
			if( rpc ) rpc.TestRank();
		}


    }

}
#endif