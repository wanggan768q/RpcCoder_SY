#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class RedDotRpcSyncRedDotAskWraperHelper
{
}
[System.Serializable]
public class RedDotRpcRemoveRedDotAskWraperHelper
{
	public int Type;
}
[System.Serializable]
public class RedDotRpcUpdateRedDotNotifyWraperHelper
{
	public RedDotInfoWraper RedDotInfo;
}



public class RedDotTestHelper : MonoBehaviour
{
	public RedDotRpcSyncRedDotAskWraperHelper RedDotRpcSyncRedDotAskWraperVar;
	public RedDotRpcRemoveRedDotAskWraperHelper RedDotRpcRemoveRedDotAskWraperVar;
	public RedDotRpcUpdateRedDotNotifyWraperHelper RedDotRpcUpdateRedDotNotifyWraperVar;


	public void TestSyncRedDot()
	{
		RedDotRPC.Instance.SyncRedDot(delegate(object obj){});
	}
	public void TestRemoveRedDot()
	{
		RedDotRPC.Instance.RemoveRedDot(RedDotRpcRemoveRedDotAskWraperVar.Type,delegate(object obj){});
	}


}

[CustomEditor(typeof(RedDotTestHelper))]
public class RedDotTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncRedDot"))
		{
			RedDotTestHelper rpc = target as RedDotTestHelper;
			if( rpc ) rpc.TestSyncRedDot();
		}
		if (GUILayout.Button("RemoveRedDot"))
		{
			RedDotTestHelper rpc = target as RedDotTestHelper;
			if( rpc ) rpc.TestRemoveRedDot();
		}


    }

}
#endif