#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ReviveRpcDieNotifyNotifyWraperHelper
{
	public int KillerId;
	public string KillerName;
	public int LeftTime;
	public int KillerType;
}
[System.Serializable]
public class ReviveRpcSceneReviveAskWraperHelper
{
	public int ReviveType;
}



public class ReviveTestHelper : MonoBehaviour
{
	public ReviveRpcDieNotifyNotifyWraperHelper ReviveRpcDieNotifyNotifyWraperVar;
	public ReviveRpcSceneReviveAskWraperHelper ReviveRpcSceneReviveAskWraperVar;


	public void TestSceneRevive()
	{
		ReviveRPC.Instance.SceneRevive(ReviveRpcSceneReviveAskWraperVar.ReviveType,delegate(bool connedServer,object obj){});
	}


}

[CustomEditor(typeof(ReviveTestHelper))]
public class ReviveTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SceneRevive"))
		{
			ReviveTestHelper rpc = target as ReviveTestHelper;
			if( rpc ) rpc.TestSceneRevive();
		}


    }

}
#endif