#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SceneRpcEnterSceneAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
}
[System.Serializable]
public class SceneRpcLoadSceneCompleteAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
}
[System.Serializable]
public class SceneRpcNewPlayerNotifyWraperHelper
{
	public int ObjId;
	public V3Wraper Pos;
	public float Dir;
	public int ObjType;
	public int ConfigId;
	public int Status;
	public float MoveSpeed;
}
[System.Serializable]
public class SceneRpcDeletePlayerNotifyWraperHelper
{
	public int ObjId;
	public int SceneId;
}
[System.Serializable]
public class SceneRpcConnectGameServerAskWraperHelper
{
	public UInt64 RoleId;
	public string Key;
}



public class SceneTestHelper : MonoBehaviour
{
	public SceneRpcEnterSceneAskWraperHelper SceneRpcEnterSceneAskWraperVar;
	public SceneRpcLoadSceneCompleteAskWraperHelper SceneRpcLoadSceneCompleteAskWraperVar;
	public SceneRpcNewPlayerNotifyWraperHelper SceneRpcNewPlayerNotifyWraperVar;
	public SceneRpcDeletePlayerNotifyWraperHelper SceneRpcDeletePlayerNotifyWraperVar;
	public SceneRpcConnectGameServerAskWraperHelper SceneRpcConnectGameServerAskWraperVar;


	public void TestEnterScene()
	{
		SceneRPC.Instance.EnterScene(SceneRpcEnterSceneAskWraperVar.RoleId,SceneRpcEnterSceneAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestLoadSceneComplete()
	{
		SceneRPC.Instance.LoadSceneComplete(SceneRpcLoadSceneCompleteAskWraperVar.RoleId,SceneRpcLoadSceneCompleteAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestConnectGameServer()
	{
		SceneRPC.Instance.ConnectGameServer(SceneRpcConnectGameServerAskWraperVar.RoleId,SceneRpcConnectGameServerAskWraperVar.Key,delegate(object obj){});
	}


}

[CustomEditor(typeof(SceneTestHelper))]
public class SceneTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("EnterScene"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestEnterScene();
		}
		if (GUILayout.Button("LoadSceneComplete"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestLoadSceneComplete();
		}
		if (GUILayout.Button("ConnectGameServer"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestConnectGameServer();
		}


    }

}
#endif