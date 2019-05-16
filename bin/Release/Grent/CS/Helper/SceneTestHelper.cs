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
	public List<ObjDeleteInfoWraper> Delete_list;
}
[System.Serializable]
public class SceneRpcConnectGameServerAskWraperHelper
{
	public UInt64 RoleId;
	public string Key;
	public int SceneID;
	public int LineID;
}
[System.Serializable]
public class SceneRpcCreateObjNotifyWraperHelper
{
	public List<ObjCreateInfoWraper> Create_list;
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
	public int LineId;
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
	public int LineId;
	public List<IntPairWraper> TypeConfig;
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
[System.Serializable]
public class SceneRpcEnterMirrorAskWraperHelper
{
	public int MirrorID;
}
[System.Serializable]
public class SceneRpcSEnterMirrorSceneNotifyWraperHelper
{
	public int MapID;
	public int MirrorID;
}
[System.Serializable]
public class SceneRpcExitMirrorSceneAskWraperHelper
{
}
[System.Serializable]
public class SceneRpcChangeSceneLeaveNotifyWraperHelper
{
	public int TargetLineID;
	public int TargetMapID;
	public UInt64 RoleID;
	public int CopyID;
}
[System.Serializable]
public class SceneRpcChangeLineAskWraperHelper
{
	public int LineID;
	public int MapID;
}
[System.Serializable]
public class SceneRpcPingAskWraperHelper
{
}
[System.Serializable]
public class SceneRpcSyncSceneLineStatsNotifyWraperHelper
{
	public SceneStatsWraper Scene_stats;
	public int Player_lineId;
}
[System.Serializable]
public class SceneRpcLogOutGameAskWraperHelper
{
}
[System.Serializable]
public class SceneRpcKickOutGameNotifyWraperHelper
{
	public string Kick_reason;
	public int Reason_id;
}
[System.Serializable]
public class SceneRpcShowFilmFinishAskWraperHelper
{
}
[System.Serializable]
public class SceneRpcSpecObjPosAskWraperHelper
{
}



public class SceneTestHelper : MonoBehaviour
{
	public SceneRpcLoadSceneCompleteAskWraperHelper SceneRpcLoadSceneCompleteAskWraperVar;
	public SceneRpcDeletePlayerNotifyWraperHelper SceneRpcDeletePlayerNotifyWraperVar;
	public SceneRpcConnectGameServerAskWraperHelper SceneRpcConnectGameServerAskWraperVar;
	public SceneRpcCreateObjNotifyWraperHelper SceneRpcCreateObjNotifyWraperVar;
	public SceneRpcSurroundingHumanAskWraperHelper SceneRpcSurroundingHumanAskWraperVar;
	public SceneRpcCEnterSceneNotifyWraperHelper SceneRpcCEnterSceneNotifyWraperVar;
	public SceneRpcSEnterSceneNotifyWraperHelper SceneRpcSEnterSceneNotifyWraperVar;
	public SceneRpcObjDieNotifyWraperHelper SceneRpcObjDieNotifyWraperVar;
	public SceneRpcCollide_ChangeSceneAskWraperHelper SceneRpcCollide_ChangeSceneAskWraperVar;
	public SceneRpcEnterMirrorAskWraperHelper SceneRpcEnterMirrorAskWraperVar;
	public SceneRpcSEnterMirrorSceneNotifyWraperHelper SceneRpcSEnterMirrorSceneNotifyWraperVar;
	public SceneRpcExitMirrorSceneAskWraperHelper SceneRpcExitMirrorSceneAskWraperVar;
	public SceneRpcChangeSceneLeaveNotifyWraperHelper SceneRpcChangeSceneLeaveNotifyWraperVar;
	public SceneRpcChangeLineAskWraperHelper SceneRpcChangeLineAskWraperVar;
	public SceneRpcPingAskWraperHelper SceneRpcPingAskWraperVar;
	public SceneRpcSyncSceneLineStatsNotifyWraperHelper SceneRpcSyncSceneLineStatsNotifyWraperVar;
	public SceneRpcLogOutGameAskWraperHelper SceneRpcLogOutGameAskWraperVar;
	public SceneRpcKickOutGameNotifyWraperHelper SceneRpcKickOutGameNotifyWraperVar;
	public SceneRpcShowFilmFinishAskWraperHelper SceneRpcShowFilmFinishAskWraperVar;
	public SceneRpcSpecObjPosAskWraperHelper SceneRpcSpecObjPosAskWraperVar;


	public void TestLoadSceneComplete()
	{
		SceneRPC.Instance.LoadSceneComplete(SceneRpcLoadSceneCompleteAskWraperVar.RoleId,SceneRpcLoadSceneCompleteAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestConnectGameServer()
	{
		SceneRPC.Instance.ConnectGameServer(SceneRpcConnectGameServerAskWraperVar.RoleId,SceneRpcConnectGameServerAskWraperVar.Key,SceneRpcConnectGameServerAskWraperVar.SceneID,SceneRpcConnectGameServerAskWraperVar.LineID,delegate(object obj){});
	}
	public void TestSurroundingHuman()
	{
		SceneRPC.Instance.SurroundingHuman(delegate(object obj){});
	}
	public void TestCEnterScene()
	{
		SceneRPC.Instance.CEnterScene(SceneRpcCEnterSceneNotifyWraperVar.SceneId,SceneRpcCEnterSceneNotifyWraperVar.MapId,SceneRpcCEnterSceneNotifyWraperVar.LineId);
	}
	public void TestCollide_ChangeScene()
	{
		SceneRPC.Instance.Collide_ChangeScene(SceneRpcCollide_ChangeSceneAskWraperVar.Collide_id,delegate(object obj){});
	}
	public void TestEnterMirror()
	{
		SceneRPC.Instance.EnterMirror(SceneRpcEnterMirrorAskWraperVar.MirrorID,delegate(object obj){});
	}
	public void TestExitMirrorScene()
	{
		SceneRPC.Instance.ExitMirrorScene(delegate(object obj){});
	}
	public void TestChangeLine()
	{
		SceneRPC.Instance.ChangeLine(SceneRpcChangeLineAskWraperVar.LineID,SceneRpcChangeLineAskWraperVar.MapID,delegate(object obj){});
	}
	public void TestPing()
	{
		SceneRPC.Instance.Ping(delegate(object obj){});
	}
	public void TestLogOutGame()
	{
		SceneRPC.Instance.LogOutGame(delegate(object obj){});
	}
	public void TestShowFilmFinish()
	{
		SceneRPC.Instance.ShowFilmFinish(delegate(object obj){});
	}
	public void TestSpecObjPos()
	{
		SceneRPC.Instance.SpecObjPos(delegate(object obj){});
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
		if (GUILayout.Button("EnterMirror"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestEnterMirror();
		}
		if (GUILayout.Button("ExitMirrorScene"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestExitMirrorScene();
		}
		if (GUILayout.Button("ChangeLine"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestChangeLine();
		}
		if (GUILayout.Button("Ping"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestPing();
		}
		if (GUILayout.Button("LogOutGame"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestLogOutGame();
		}
		if (GUILayout.Button("ShowFilmFinish"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestShowFilmFinish();
		}
		if (GUILayout.Button("SpecObjPos"))
		{
			SceneTestHelper rpc = target as SceneTestHelper;
			if( rpc ) rpc.TestSpecObjPos();
		}


    }

}
#endif