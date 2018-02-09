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
[System.Serializable]
public class DungeonRpcInformCreateDungeonAskWraperHelper
{
	public UInt64 RoleId;
	public int TargetSceneId;
	public int DungeonConfigId;
	public int CurSceneId;
	public int Result;
	public List<UInt64> RoleIds;
}
[System.Serializable]
public class DungeonRpcSettlementNotifyWraperHelper
{
	public int SettlementResult;
}
[System.Serializable]
public class DungeonRpcEnterDungeonAskWraperHelper
{
	public int SceneId;
	public int DungeonConfigId;
}



public class DungeonTestHelper : MonoBehaviour
{
	public DungeonRpcCreateDungeonAskWraperHelper DungeonRpcCreateDungeonAskWraperVar;
	public DungeonRpcExitDungeonAskWraperHelper DungeonRpcExitDungeonAskWraperVar;
	public DungeonRpcInformCreateDungeonAskWraperHelper DungeonRpcInformCreateDungeonAskWraperVar;
	public DungeonRpcSettlementNotifyWraperHelper DungeonRpcSettlementNotifyWraperVar;
	public DungeonRpcEnterDungeonAskWraperHelper DungeonRpcEnterDungeonAskWraperVar;


	public void TestCreateDungeon()
	{
		DungeonRPC.Instance.CreateDungeon(DungeonRpcCreateDungeonAskWraperVar.RoleId,DungeonRpcCreateDungeonAskWraperVar.DungeonConfigId,delegate(object obj){});
	}
	public void TestExitDungeon()
	{
		DungeonRPC.Instance.ExitDungeon(DungeonRpcExitDungeonAskWraperVar.RoleId,DungeonRpcExitDungeonAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestEnterDungeon()
	{
		DungeonRPC.Instance.EnterDungeon(DungeonRpcEnterDungeonAskWraperVar.SceneId,DungeonRpcEnterDungeonAskWraperVar.DungeonConfigId,delegate(object obj){});
	}
	public void TestInformCreateDungeon()
	{
		DungeonRPC.Instance.InformCreateDungeon(DungeonRpcInformCreateDungeonAskWraperVar.RoleId,DungeonRpcInformCreateDungeonAskWraperVar.TargetSceneId,DungeonRpcInformCreateDungeonAskWraperVar.DungeonConfigId,DungeonRpcInformCreateDungeonAskWraperVar.CurSceneId,DungeonRpcInformCreateDungeonAskWraperVar.Result,DungeonRpcInformCreateDungeonAskWraperVar.RoleIds,delegate(object obj){});
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
		if (GUILayout.Button("EnterDungeon"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestEnterDungeon();
		}
		if (GUILayout.Button("InformCreateDungeon"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestInformCreateDungeon();
		}


    }

}
#endif