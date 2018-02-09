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
	public int SceneId;
}
[System.Serializable]
public class WorldServerRpcEnterSceneAskWraperHelper
{
	public UInt64 RoleId;
	public int SceneId;
	public int MemId;
}
[System.Serializable]
public class WorldServerRpcCreateDungeonAskWraperHelper
{
	public UInt64 RoleId;
	public int TargetSceneId;
	public int MemId;
	public int DungeonConfigId;
	public int CurSceneId;
	public int Result;
	public List<UInt64> RoleIds;
}
[System.Serializable]
public class WorldServerRpcCreateTeamAskWraperHelper
{
	public int TeamType;
	public TeamMemberInfoWraper TeamMember;
	public int Result;
	public TeamInfoWraper Team;
}
[System.Serializable]
public class WorldServerRpcJoinTeamAskWraperHelper
{
	public int TeamId;
	public int Result;
	public TeamMemberInfoWraper TeamMember;
	public TeamInfoWraper Team;
	public int TeamType;
	public int MemId;
	public int SceneId;
}
[System.Serializable]
public class WorldServerRpcLeaveTeamAskWraperHelper
{
	public int TeamId;
	public UInt64 RoleId;
	public int MemId;
	public int SceneId;
	public UInt64 NewLeaderRoleId;
	public int Result;
}
[System.Serializable]
public class WorldServerRpcAppointTeamLeaderAskWraperHelper
{
	public UInt64 NewLeaderRoleId;
	public int MemId;
	public int SceneId;
	public UInt64 CurLeaderRoleId;
	public int TeamId;
	public int Result;
}
[System.Serializable]
public class WorldServerRpcDismissTeamAskWraperHelper
{
	public int SceneId;
	public int MemId;
	public UInt64 RoleId;
	public int TeamId;
	public int Result;
}
[System.Serializable]
public class WorldServerRpcKickMemberAskWraperHelper
{
	public UInt64 KickMemberRoleId;
	public int MemId;
	public int SceneId;
	public int TeamId;
	public UInt64 LeaderRoleId;
	public int Result;
}
[System.Serializable]
public class WorldServerRpcApplyTeamAskWraperHelper
{
	public int TeamId;
	public int Result;
	public TeamMemberInfoWraper TeamMember;
	public int MemId;
	public int SceneId;
}
[System.Serializable]
public class WorldServerRpcAgreeTeamApplicantAskWraperHelper
{
	public UInt64 RoleId;
	public UInt64 LeaderRoleId;
	public int Result;
	public int MemId;
	public int SceneId;
	public TeamInfoWraper Team;
}
[System.Serializable]
public class WorldServerRpcLoginAskWraperHelper
{
	public TeamInfoWraper Team;
	public int MemId;
	public int SceneId;
	public OnlineUserInfoWraper RoleInfo;
}
[System.Serializable]
public class WorldServerRpcUpdateRoleInfoAskWraperHelper
{
	public OnlineUserInfoWraper RoleInfo;
}
[System.Serializable]
public class WorldServerRpcLogoutAskWraperHelper
{
	public OnlineUserInfoWraper RoleInfo;
}
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyAskWraperHelper
{
	public int CurSceneId;
	public UInt64 RoleId;
	public int MemId;
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
public class WorldServerRpcReleaseDungeonAskWraperHelper
{
}



public class WorldServerTestHelper : MonoBehaviour
{
	public WorldServerRpcChangeSceneAskWraperHelper WorldServerRpcChangeSceneAskWraperVar;
	public WorldServerRpcEnterSceneAskWraperHelper WorldServerRpcEnterSceneAskWraperVar;
	public WorldServerRpcCreateDungeonAskWraperHelper WorldServerRpcCreateDungeonAskWraperVar;
	public WorldServerRpcCreateTeamAskWraperHelper WorldServerRpcCreateTeamAskWraperVar;
	public WorldServerRpcJoinTeamAskWraperHelper WorldServerRpcJoinTeamAskWraperVar;
	public WorldServerRpcLeaveTeamAskWraperHelper WorldServerRpcLeaveTeamAskWraperVar;
	public WorldServerRpcAppointTeamLeaderAskWraperHelper WorldServerRpcAppointTeamLeaderAskWraperVar;
	public WorldServerRpcDismissTeamAskWraperHelper WorldServerRpcDismissTeamAskWraperVar;
	public WorldServerRpcKickMemberAskWraperHelper WorldServerRpcKickMemberAskWraperVar;
	public WorldServerRpcApplyTeamAskWraperHelper WorldServerRpcApplyTeamAskWraperVar;
	public WorldServerRpcAgreeTeamApplicantAskWraperHelper WorldServerRpcAgreeTeamApplicantAskWraperVar;
	public WorldServerRpcLoginAskWraperHelper WorldServerRpcLoginAskWraperVar;
	public WorldServerRpcUpdateRoleInfoAskWraperHelper WorldServerRpcUpdateRoleInfoAskWraperVar;
	public WorldServerRpcLogoutAskWraperHelper WorldServerRpcLogoutAskWraperVar;
	public WorldServerRpcCreateDungeonNotifyAskWraperHelper WorldServerRpcCreateDungeonNotifyAskWraperVar;
	public WorldServerRpcCreateDungeonNotifyReplyWraperHelper WorldServerRpcCreateDungeonNotifyReplyWraperVar;
	public WorldServerRpcExitDungeonAskWraperHelper WorldServerRpcExitDungeonAskWraperVar;
	public WorldServerRpcReleaseDungeonAskWraperHelper WorldServerRpcReleaseDungeonAskWraperVar;


	public void TestChangeScene()
	{
		WorldServerRPC.Instance.ChangeScene(WorldServerRpcChangeSceneAskWraperVar.RoleId,WorldServerRpcChangeSceneAskWraperVar.CurSceneId,WorldServerRpcChangeSceneAskWraperVar.TargetSceneId,WorldServerRpcChangeSceneAskWraperVar.MemId,WorldServerRpcChangeSceneAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestEnterScene()
	{
		WorldServerRPC.Instance.EnterScene(WorldServerRpcEnterSceneAskWraperVar.RoleId,WorldServerRpcEnterSceneAskWraperVar.SceneId,WorldServerRpcEnterSceneAskWraperVar.MemId,delegate(object obj){});
	}
	public void TestCreateDungeon()
	{
		WorldServerRPC.Instance.CreateDungeon(WorldServerRpcCreateDungeonAskWraperVar.RoleId,WorldServerRpcCreateDungeonAskWraperVar.TargetSceneId,WorldServerRpcCreateDungeonAskWraperVar.MemId,WorldServerRpcCreateDungeonAskWraperVar.DungeonConfigId,WorldServerRpcCreateDungeonAskWraperVar.CurSceneId,WorldServerRpcCreateDungeonAskWraperVar.Result,WorldServerRpcCreateDungeonAskWraperVar.RoleIds,delegate(object obj){});
	}
	public void TestCreateTeam()
	{
		WorldServerRPC.Instance.CreateTeam(WorldServerRpcCreateTeamAskWraperVar.TeamType,WorldServerRpcCreateTeamAskWraperVar.TeamMember,WorldServerRpcCreateTeamAskWraperVar.Result,WorldServerRpcCreateTeamAskWraperVar.Team,delegate(object obj){});
	}
	public void TestJoinTeam()
	{
		WorldServerRPC.Instance.JoinTeam(WorldServerRpcJoinTeamAskWraperVar.TeamId,WorldServerRpcJoinTeamAskWraperVar.Result,WorldServerRpcJoinTeamAskWraperVar.TeamMember,WorldServerRpcJoinTeamAskWraperVar.Team,WorldServerRpcJoinTeamAskWraperVar.TeamType,WorldServerRpcJoinTeamAskWraperVar.MemId,WorldServerRpcJoinTeamAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestLeaveTeam()
	{
		WorldServerRPC.Instance.LeaveTeam(WorldServerRpcLeaveTeamAskWraperVar.TeamId,WorldServerRpcLeaveTeamAskWraperVar.RoleId,WorldServerRpcLeaveTeamAskWraperVar.MemId,WorldServerRpcLeaveTeamAskWraperVar.SceneId,WorldServerRpcLeaveTeamAskWraperVar.NewLeaderRoleId,WorldServerRpcLeaveTeamAskWraperVar.Result,delegate(object obj){});
	}
	public void TestAppointTeamLeader()
	{
		WorldServerRPC.Instance.AppointTeamLeader(WorldServerRpcAppointTeamLeaderAskWraperVar.NewLeaderRoleId,WorldServerRpcAppointTeamLeaderAskWraperVar.MemId,WorldServerRpcAppointTeamLeaderAskWraperVar.SceneId,WorldServerRpcAppointTeamLeaderAskWraperVar.CurLeaderRoleId,WorldServerRpcAppointTeamLeaderAskWraperVar.TeamId,WorldServerRpcAppointTeamLeaderAskWraperVar.Result,delegate(object obj){});
	}
	public void TestDismissTeam()
	{
		WorldServerRPC.Instance.DismissTeam(WorldServerRpcDismissTeamAskWraperVar.SceneId,WorldServerRpcDismissTeamAskWraperVar.MemId,WorldServerRpcDismissTeamAskWraperVar.RoleId,WorldServerRpcDismissTeamAskWraperVar.TeamId,WorldServerRpcDismissTeamAskWraperVar.Result,delegate(object obj){});
	}
	public void TestKickMember()
	{
		WorldServerRPC.Instance.KickMember(WorldServerRpcKickMemberAskWraperVar.KickMemberRoleId,WorldServerRpcKickMemberAskWraperVar.MemId,WorldServerRpcKickMemberAskWraperVar.SceneId,WorldServerRpcKickMemberAskWraperVar.TeamId,WorldServerRpcKickMemberAskWraperVar.LeaderRoleId,WorldServerRpcKickMemberAskWraperVar.Result,delegate(object obj){});
	}
	public void TestApplyTeam()
	{
		WorldServerRPC.Instance.ApplyTeam(WorldServerRpcApplyTeamAskWraperVar.TeamId,WorldServerRpcApplyTeamAskWraperVar.Result,WorldServerRpcApplyTeamAskWraperVar.TeamMember,WorldServerRpcApplyTeamAskWraperVar.MemId,WorldServerRpcApplyTeamAskWraperVar.SceneId,delegate(object obj){});
	}
	public void TestAgreeTeamApplicant()
	{
		WorldServerRPC.Instance.AgreeTeamApplicant(WorldServerRpcAgreeTeamApplicantAskWraperVar.RoleId,WorldServerRpcAgreeTeamApplicantAskWraperVar.LeaderRoleId,WorldServerRpcAgreeTeamApplicantAskWraperVar.Result,WorldServerRpcAgreeTeamApplicantAskWraperVar.MemId,WorldServerRpcAgreeTeamApplicantAskWraperVar.SceneId,WorldServerRpcAgreeTeamApplicantAskWraperVar.Team,delegate(object obj){});
	}
	public void TestLogin()
	{
		WorldServerRPC.Instance.Login(WorldServerRpcLoginAskWraperVar.Team,WorldServerRpcLoginAskWraperVar.MemId,WorldServerRpcLoginAskWraperVar.SceneId,WorldServerRpcLoginAskWraperVar.RoleInfo,delegate(object obj){});
	}
	public void TestUpdateRoleInfo()
	{
		WorldServerRPC.Instance.UpdateRoleInfo(WorldServerRpcUpdateRoleInfoAskWraperVar.RoleInfo,delegate(object obj){});
	}
	public void TestLogout()
	{
		WorldServerRPC.Instance.Logout(WorldServerRpcLogoutAskWraperVar.RoleInfo,delegate(object obj){});
	}
	public void TestCreateDungeonNotify()
	{
		WorldServerRPC.Instance.CreateDungeonNotify(WorldServerRpcCreateDungeonNotifyAskWraperVar.CurSceneId,WorldServerRpcCreateDungeonNotifyAskWraperVar.RoleId,WorldServerRpcCreateDungeonNotifyAskWraperVar.MemId,WorldServerRpcCreateDungeonNotifyAskWraperVar.TargetSceneId,delegate(object obj){});
	}
	public void TestExitDungeon()
	{
		WorldServerRPC.Instance.ExitDungeon(WorldServerRpcExitDungeonAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestReleaseDungeon()
	{
		WorldServerRPC.Instance.ReleaseDungeon(delegate(object obj){});
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
		if (GUILayout.Button("CreateDungeon"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestCreateDungeon();
		}
		if (GUILayout.Button("CreateTeam"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestCreateTeam();
		}
		if (GUILayout.Button("JoinTeam"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestJoinTeam();
		}
		if (GUILayout.Button("LeaveTeam"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestLeaveTeam();
		}
		if (GUILayout.Button("AppointTeamLeader"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestAppointTeamLeader();
		}
		if (GUILayout.Button("DismissTeam"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestDismissTeam();
		}
		if (GUILayout.Button("KickMember"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestKickMember();
		}
		if (GUILayout.Button("ApplyTeam"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestApplyTeam();
		}
		if (GUILayout.Button("AgreeTeamApplicant"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestAgreeTeamApplicant();
		}
		if (GUILayout.Button("Login"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestLogin();
		}
		if (GUILayout.Button("UpdateRoleInfo"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestUpdateRoleInfo();
		}
		if (GUILayout.Button("Logout"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestLogout();
		}
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
		if (GUILayout.Button("ReleaseDungeon"))
		{
			WorldServerTestHelper rpc = target as WorldServerTestHelper;
			if( rpc ) rpc.TestReleaseDungeon();
		}


    }

}
#endif