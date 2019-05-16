#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class TreasureMapRpcTreasureMapSyncAskWraperHelper
{
}
[System.Serializable]
public class TreasureMapRpcTreasureMapChangeNotifyWraperHelper
{
	public int TreasureMapId;
	public int HighTreasureMapId;
}



public class TreasureMapTestHelper : MonoBehaviour
{
	public TreasureMapRpcTreasureMapSyncAskWraperHelper TreasureMapRpcTreasureMapSyncAskWraperVar;
	public TreasureMapRpcTreasureMapChangeNotifyWraperHelper TreasureMapRpcTreasureMapChangeNotifyWraperVar;


	public void TestTreasureMapSync()
	{
		TreasureMapRPC.Instance.TreasureMapSync(delegate(object obj){});
	}


}

[CustomEditor(typeof(TreasureMapTestHelper))]
public class TreasureMapTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("TreasureMapSync"))
		{
			TreasureMapTestHelper rpc = target as TreasureMapTestHelper;
			if( rpc ) rpc.TestTreasureMapSync();
		}


    }

}
#endif