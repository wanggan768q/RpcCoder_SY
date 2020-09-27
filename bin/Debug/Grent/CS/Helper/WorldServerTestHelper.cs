#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class WorldServerRpcEnterSceneAskWraperHelper
{
	public UInt64 RoleId;
	public CharacterLocationWraper Location;
}
[System.Serializable]
public class WorldServerRpcLoginGameServerAskWraperHelper
{
	public TeamInfoWraper Team;
	public OnlineUserInfoWraper RoleInfo;
	public CharacterLocationWraper Location;
	public int GateId;
}
[System.Serializable]
public class WorldServerRpcLogoutGameServerAskWraperHelper
{
	public int Result;
	public OnlineUserInfoWraper RoleInfo;
}
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyAskWraperHelper
{
	public int CurSceneId;
	public UInt64 RoleId;
	public int TargetSceneId;
}
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyReplyWraperHelper
{
	public int Result;
}
[System.Serializable]
public class WorldServerRpcExitDungeonAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class WorldServerRpcUpdateTeamInfoAskWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
	public UInt64 RoleId;
	public TeamInfoWraper Team;
	public int TeamType;
}
[System.Serializable]
public class WorldServerRpcSendMailAskWraperHelper
{
	public MailInfoWraper Mail;
	public UInt64 GlobalMailID;
}
[System.Serializable]
public class WorldServerRpcChangeTeamTypeAskWraperHelper
{
	public UInt64 TeamId;
	public UInt64 RoleId;
	public int Result;
	public int TeamType;
	public TeamTargetWraper Target;
}
[System.Serializable]
public class WorldServerRpcAutoMatchAskWraperHelper
{
	public TeamMemberInfoWraper MemberInfo;
	public PlayerMatchDataWraper MatchInfo;
	public int Result;
}
[System.Serializable]
public class WorldServerRpcCancelMatchAskWraperHelper
{
	public UInt64 RoleId;
	public int Result;
	public int IsNotify;
}
[System.Serializable]
public class WorldServerRpcGetPlayerInfoAskWraperHelper
{
	public UInt64 Player_guid;
}



public class WorldServerTestHelper : MonoBehaviour
{
	public WorldServerRpcEnterSceneAskWraperHelper WorldServerRpcEnterSceneAskWraperVar;
	public WorldServerRpcLoginGameServerAskWraperHelper WorldServerRpcLoginGameServerAskWraperVar;
	public WorldServerRpcLogoutGameServerAskWraperHelper WorldServerRpcLogoutGameServerAskWraperVar;
	public WorldServerRpcCreateDungeonNotifyAskWraperHelper WorldServerRpcCreateDungeonNotifyAskWraperVar;
	public WorldServerRpcCreateDungeonNotifyReplyWraperHelper WorldServerRpcCreateDungeonNotifyReplyWraperVar;
	public WorldServerRpcExitDungeonAskWraperHelper WorldServerRpcExitDungeonAskWraperVar;
	public WorldServerRpcUpdateTeamInfoAskWraperHelper WorldServerRpcUpdateTeamInfoAskWraperVar;
	public WorldServerRpcSendMailAskWraperHelper WorldServerRpcSendMailAskWraperVar;
	public WorldServerRpcChangeTeamTypeAskWraperHelper WorldServerRpcChangeTeamTypeAskWraperVar;
	public WorldServerRpcAutoMatchAskWraperHelper WorldServerRpcAutoMatchAskWraperVar;
	public WorldServerRpcCancelMatchAskWraperHelper WorldServerRpcCancelMatchAskWraperVar;
	public WorldServerRpcGetPlayerInfoAskWraperHelper WorldServerRpcGetPlayerInfoAskWraperVar;


	public void TestCreateDungeonNotify()
	{
		WorldServerRPC.Instance.CreateDungeonNotify(WorldServerRpcCreateDungeonNotifyAskWraperVar.CurSceneId,WorldServerRpcCreateDungeonNotifyAskWraperVar.RoleId,WorldServerRpcCreateDungeonNotifyAskWraperVar.TargetSceneId,delegate(bool connedServer,object obj){});
	}
	public void TestExitDungeon()
	{
		WorldServerRPC.Instance.ExitDungeon(WorldServerRpcExitDungeonAskWraperVar.RoleId,delegate(bool connedServer,object obj){});
	}
	public void TestUpdateTeamInfo()
	{
		WorldServerRPC.Instance.UpdateTeamInfo(WorldServerRpcUpdateTeamInfoAskWraperVar.TeamMember,WorldServerRpcUpdateTeamInfoAskWraperVar.RoleId,WorldServerRpcUpdateTeamInfoAskWraperVar.Team,WorldServerRpcUpdateTeamInfoAskWraperVar.TeamType,delegate(bool connedServer,object obj){});
	}
	public void TestSendMail()
	{
		WorldServerRPC.Instance.SendMail(WorldServerRpcSendMailAskWraperVar.Mail,WorldServerRpcSendMailAskWraperVar.GlobalMailID,delegate(bool connedServer,object obj){});
	}
	public void TestChangeTeamType()
	{
		WorldServerRPC.Instance.ChangeTeamType(WorldServerRpcChangeTeamTypeAskWraperVar.TeamId,WorldServerRpcChangeTeamTypeAskWraperVar.RoleId,WorldServerRpcChangeTeamTypeAskWraperVar.Result,WorldServerRpcChangeTeamTypeAskWraperVar.TeamType,WorldServerRpcChangeTeamTypeAskWraperVar.Target,delegate(bool connedServer,object obj){});
	}
	public void TestAutoMatch()
	{
		WorldServerRPC.Instance.AutoMatch(WorldServerRpcAutoMatchAskWraperVar.MemberInfo,WorldServerRpcAutoMatchAskWraperVar.MatchInfo,WorldServerRpcAutoMatchAskWraperVar.Result,delegate(bool connedServer,object obj){});
	}
	public void TestCancelMatch()
	{
		WorldServerRPC.Instance.CancelMatch(WorldServerRpcCancelMatchAskWraperVar.RoleId,WorldServerRpcCancelMatchAskWraperVar.Result,WorldServerRpcCancelMatchAskWraperVar.IsNotify,delegate(bool connedServer,object obj){});
	}
	public void TestLoginGameServer()
	{
		WorldServerRPC.Instance.LoginGameServer(WorldServerRpcLoginGameServerAskWraperVar.Team,WorldServerRpcLoginGameServerAskWraperVar.RoleInfo,WorldServerRpcLoginGameServerAskWraperVar.Location,WorldServerRpcLoginGameServerAskWraperVar.GateId,delegate(bool connedServer,object obj){});
	}
	public void TestLogoutGameServer()
	{
		WorldServerRPC.Instance.LogoutGameServer(WorldServerRpcLogoutGameServerAskWraperVar.Result,WorldServerRpcLogoutGameServerAskWraperVar.RoleInfo,delegate(bool connedServer,object obj){});
	}
	public void TestGetPlayerInfo()
	{
		WorldServerRPC.Instance.GetPlayerInfo(WorldServerRpcGetPlayerInfoAskWraperVar.Player_guid,delegate(bool connedServer,object obj){});
	}


}

[CustomEditor(typeof(WorldServerTestHelper))]
public class WorldServerTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("CreateDungeonNotify"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestCreateDungeonNotify();
		}
		if (GUILayout.Button("ExitDungeon"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestExitDungeon();
		}
		if (GUILayout.Button("UpdateTeamInfo"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestUpdateTeamInfo();
		}
		if (GUILayout.Button("SendMail"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestSendMail();
		}
		if (GUILayout.Button("ChangeTeamType"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestChangeTeamType();
		}
		if (GUILayout.Button("AutoMatch"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestAutoMatch();
		}
		if (GUILayout.Button("CancelMatch"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestCancelMatch();
		}
		if (GUILayout.Button("LoginGameServer"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestLoginGameServer();
		}
		if (GUILayout.Button("LogoutGameServer"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestLogoutGameServer();
		}
		if (GUILayout.Button("GetPlayerInfo"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestGetPlayerInfo();
		}


    }

}
#endif