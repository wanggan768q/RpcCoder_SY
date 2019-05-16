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
[System.Serializable]
public class DungeonRpcDungeonDataNotifyWraperHelper
{
	public int BeginTime;
}
[System.Serializable]
public class DungeonRpcDungeonSyncAskWraperHelper
{
}
[System.Serializable]
public class DungeonRpcDungeonListInfoAskWraperHelper
{
}
[System.Serializable]
public class DungeonRpcCreateTutorialAskWraperHelper
{
	public UInt64 RoleId;
	public int DungeonConfigId;
}
[System.Serializable]
public class DungeonRpcQuitTutorialAskWraperHelper
{
}
[System.Serializable]
public class DungeonRpcDungeonTargetNotifyWraperHelper
{
	public List<DungeonTargetWraper> DungeonTarget;
}
[System.Serializable]
public class DungeonRpcTargetContentChangeNotifyWraperHelper
{
	public int Index;
	public int SubIndex;
	public int CurCount;
}
[System.Serializable]
public class DungeonRpcDungeon_NotifyNotifyWraperHelper
{
	public int TextId;
}



public class DungeonTestHelper : MonoBehaviour
{
	public DungeonRpcCreateDungeonAskWraperHelper DungeonRpcCreateDungeonAskWraperVar;
	public DungeonRpcExitDungeonAskWraperHelper DungeonRpcExitDungeonAskWraperVar;
	public DungeonRpcInformCreateDungeonAskWraperHelper DungeonRpcInformCreateDungeonAskWraperVar;
	public DungeonRpcSettlementNotifyWraperHelper DungeonRpcSettlementNotifyWraperVar;
	public DungeonRpcEnterDungeonAskWraperHelper DungeonRpcEnterDungeonAskWraperVar;
	public DungeonRpcDungeonDataNotifyWraperHelper DungeonRpcDungeonDataNotifyWraperVar;
	public DungeonRpcDungeonSyncAskWraperHelper DungeonRpcDungeonSyncAskWraperVar;
	public DungeonRpcDungeonListInfoAskWraperHelper DungeonRpcDungeonListInfoAskWraperVar;
	public DungeonRpcCreateTutorialAskWraperHelper DungeonRpcCreateTutorialAskWraperVar;
	public DungeonRpcQuitTutorialAskWraperHelper DungeonRpcQuitTutorialAskWraperVar;
	public DungeonRpcDungeonTargetNotifyWraperHelper DungeonRpcDungeonTargetNotifyWraperVar;
	public DungeonRpcTargetContentChangeNotifyWraperHelper DungeonRpcTargetContentChangeNotifyWraperVar;
	public DungeonRpcDungeon_NotifyNotifyWraperHelper DungeonRpcDungeon_NotifyNotifyWraperVar;


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
	public void TestDungeonSync()
	{
		DungeonRPC.Instance.DungeonSync(delegate(object obj){});
	}
	public void TestDungeonListInfo()
	{
		DungeonRPC.Instance.DungeonListInfo(delegate(object obj){});
	}
	public void TestCreateTutorial()
	{
		DungeonRPC.Instance.CreateTutorial(DungeonRpcCreateTutorialAskWraperVar.RoleId,DungeonRpcCreateTutorialAskWraperVar.DungeonConfigId,delegate(object obj){});
	}
	public void TestQuitTutorial()
	{
		DungeonRPC.Instance.QuitTutorial(delegate(object obj){});
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
		if (GUILayout.Button("DungeonSync"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestDungeonSync();
		}
		if (GUILayout.Button("DungeonListInfo"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestDungeonListInfo();
		}
		if (GUILayout.Button("CreateTutorial"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestCreateTutorial();
		}
		if (GUILayout.Button("QuitTutorial"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestQuitTutorial();
		}


    }

}
#endif