#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SceneRpcLoadSceneCompleteAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
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
[System.Serializable]
public class SceneRpcChangeSceneAskWraperHelper
{
	public UInt64 RoleId;
	public int CurSceneId;
	public int TargetSceneId;
}
[System.Serializable]
public class SceneRpcCreateObjNotifyWraperHelper
{
	public int ObjId;
	public V3Wraper Pos;
	public float Dir;
	public int ObjType;
	public int ConfigId;
	public int Status;
	public float MoveSpeed;
	public UInt64 RoleId;
	public string NickName;
	public int Hp;
	public V3Wraper TargetPos;
	public int HpMax;
}
[System.Serializable]
public class SceneRpcSurroundingHumanAskWraperHelper
{
}
[System.Serializable]
public class SceneRpcCEnterSceneNotifyWraperHelper
{
	public int SceneId;
	public int MapId;
}
[System.Serializable]
public class SceneRpcSEnterSceneNotifyWraperHelper
{
	public int Result;
	public int SceneId;
	public int SceneConfigId;
	public int MapId;
	public UInt64 RoleId;
	public int DungeonConfigId;
}
[System.Serializable]
public class SceneRpcObjDieNotifyWraperHelper
{
	public int ObjId;
	public int RespawnTime;
	public int ConfigId;
	public int ObjType;
}
[System.Serializable]
public class SceneRpcCollide_ChangeSceneAskWraperHelper
{
	public int Collide_id;
}



public class SceneTestHelper : MonoBehaviour
{
	public SceneRpcLoadSceneCompleteAskWraperHelper SceneRpcLoadSceneCompleteAskWraperVar;
	public SceneRpcDeletePlayerNotifyWraperHelper SceneRpcDeletePlayerNotifyWraperVar;
	public SceneRpcConnectGameServerAskWraperHelper SceneRpcConnectGameServerAskWraperVar;
	public SceneRpcChangeSceneAskWraperHelper SceneRpcChangeSceneAskWraperVar;
	public SceneRpcCreateObjNotifyWraperHelper SceneRpcCreateObjNotifyWraperVar;
	public SceneRpcSurroundingHumanAskWraperHelper SceneRpcSurroundingHumanAskWraperVar;
	public SceneRpcCEnterSceneNotifyWraperHelper SceneRpcCEnterSceneNotifyWraperVar;
	public SceneRpcSEnterSceneNotifyWraperHelper SceneRpcSEnterSceneNotifyWraperVar;
	public SceneRpcObjDieNotifyWraperHelper SceneRpcObjDieNotifyWraperVar;
	public SceneRpcCollide_ChangeSceneAskWraperHelper SceneRpcCollide_ChangeSceneAskWraperVar;


	public void TestLoadSceneComplete()
	{
		SceneRPC.Instance.LoadSceneComplete(SceneRpcLoadSceneCompleteAskWraperVar.RoleId,SceneRpcLoadSceneCompleteAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestConnectGameServer()
	{
		SceneRPC.Instance.ConnectGameServer(SceneRpcConnectGameServerAskWraperVar.RoleId,SceneRpcConnectGameServerAskWraperVar.Key,delegate(object obj){});
	}
	public void TestChangeScene()
	{
		SceneRPC.Instance.ChangeScene(SceneRpcChangeSceneAskWraperVar.RoleId,SceneRpcChangeSceneAskWraperVar.CurSceneId,SceneRpcChangeSceneAskWraperVar.TargetSceneId,delegate(object obj){});
	}
	public void TestSurroundingHuman()
	{
		SceneRPC.Instance.SurroundingHuman(delegate(object obj){});
	}
	public void TestCEnterScene()
	{
		SceneRPC.Instance.CEnterScene(SceneRpcCEnterSceneNotifyWraperVar.SceneId,SceneRpcCEnterSceneNotifyWraperVar.MapId);
	}
	public void TestCollide_ChangeScene()
	{
		SceneRPC.Instance.Collide_ChangeScene(SceneRpcCollide_ChangeSceneAskWraperVar.Collide_id,delegate(object obj){});
	}


}

[CustomEditor(typeof(SceneTestHelper))]
public class SceneTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
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
		if (GUILayout.Button("ChangeScene"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestChangeScene();
		}
		if (GUILayout.Button("SurroundingHuman"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestSurroundingHuman();
		}
		if (GUILayout.Button("CEnterScene"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestCEnterScene();
		}
		if (GUILayout.Button("Collide_ChangeScene"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestCollide_ChangeScene();
		}


    }

}
#endif