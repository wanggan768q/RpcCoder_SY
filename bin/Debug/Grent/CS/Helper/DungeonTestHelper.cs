#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class DungeonRpcCreateDungeonAskWraperHelper
{
	public UInt64 RoleId;
	public int DungeonConfigId;
}
[System.Serializable]
public class DungeonRpcExitDungeonAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
}



public class DungeonTestHelper : MonoBehaviour
{
	public DungeonRpcCreateDungeonAskWraperHelper DungeonRpcCreateDungeonAskWraperVar;
	public DungeonRpcExitDungeonAskWraperHelper DungeonRpcExitDungeonAskWraperVar;


	public void TestCreateDungeon()
	{
		DungeonRPC.Instance.CreateDungeon(DungeonRpcCreateDungeonAskWraperVar.RoleId,DungeonRpcCreateDungeonAskWraperVar.DungeonConfigId,delegate(object obj){});
	}
	public void TestExitDungeon()
	{
		DungeonRPC.Instance.ExitDungeon(DungeonRpcExitDungeonAskWraperVar.RoleId,DungeonRpcExitDungeonAskWraperVar.SceneId,delegate(object obj){});
	}


}

[CustomEditor(typeof(DungeonTestHelper))]
public class DungeonTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("CreateDungeon"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestCreateDungeon();
		}
		if (GUILayout.Button("ExitDungeon"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestExitDungeon();
		}


    }

}
#endif