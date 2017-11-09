#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class WorldServerRpcChangeSceneAskWraperHelper
{
	public UInt64 RoleId;
	public int CurSceneId;
	public int TargetSceneId;
	public int MemId;
}
[System.Serializable]
public class WorldServerRpcEnterSceneAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
}



public class WorldServerTestHelper : MonoBehaviour
{
	public WorldServerRpcChangeSceneAskWraperHelper WorldServerRpcChangeSceneAskWraperVar;
	public WorldServerRpcEnterSceneAskWraperHelper WorldServerRpcEnterSceneAskWraperVar;


	public void TestChangeScene()
	{
		WorldServerRPC.Instance.ChangeScene(WorldServerRpcChangeSceneAskWraperVar.RoleId,WorldServerRpcChangeSceneAskWraperVar.CurSceneId,WorldServerRpcChangeSceneAskWraperVar.TargetSceneId,WorldServerRpcChangeSceneAskWraperVar.MemId,delegate(object obj){});
	}
	public void TestEnterScene()
	{
		WorldServerRPC.Instance.EnterScene(WorldServerRpcEnterSceneAskWraperVar.RoleId,WorldServerRpcEnterSceneAskWraperVar.SceneId,delegate(object obj){});
	}


}

[CustomEditor(typeof(WorldServerTestHelper))]
public class WorldServerTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("ChangeScene"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestChangeScene();
		}
		if (GUILayout.Button("EnterScene"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestEnterScene();
		}


    }

}
#endif