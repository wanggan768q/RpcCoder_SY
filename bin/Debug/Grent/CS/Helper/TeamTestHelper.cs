#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class TeamRpcCreateTeamAskWraperHelper
{
	public int TeamType;
}
[System.Serializable]
public class TeamRpcJoinTeamAskWraperHelper
{
	public int TeamId;
	public int TeamType;
	public TeamInfoWraper Team;
	public TeamMemberInfoWraper TeamMember;
}
[System.Serializable]
public class TeamRpcLeaveTeamAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcAppointTeamLeaderAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class TeamRpcNewLeaderNotifyWraperHelper
{
	public UInt64 Newleaderroleid;
}
[System.Serializable]
public class TeamRpcKickMemberAskWraperHelper
{
	public UInt64 KickMemberRoleId;
}
[System.Serializable]
public class TeamRpcDissmissTeamAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcAppointTeamLeaderNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcKickMemberNotifyNotifyWraperHelper
{
	public UInt64 KickedMemberRoleId;
}
[System.Serializable]
public class TeamRpcLeaveTeamNotifyNotifyWraperHelper
{
	public UInt64 RoleId;
	public UInt64 NewLeaderRoleId;
}
[System.Serializable]
public class TeamRpcJoinTeamNotifyNotifyWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
}
[System.Serializable]
public class TeamRpcDissmissTeamNotifyNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcSurroundingTeamAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcApplyTeamAskWraperHelper
{
	public int TeamId;
}
[System.Serializable]
public class TeamRpcApplyTeamNotifyNotifyWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
}
[System.Serializable]
public class TeamRpcAgreeApplicantAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class TeamRpcAgreeApplicantNotifyNotifyWraperHelper
{
	public TeamInfoWraper Team;
}
[System.Serializable]
public class TeamRpcTeamInfoNotifyWraperHelper
{
	public TeamInfoWraper Team;
}
[System.Serializable]
public class TeamRpcUpdateTeamMemInfoNotifyWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
}



public class TeamTestHelper : MonoBehaviour
{
	public TeamRpcCreateTeamAskWraperHelper TeamRpcCreateTeamAskWraperVar;
	public TeamRpcJoinTeamAskWraperHelper TeamRpcJoinTeamAskWraperVar;
	public TeamRpcLeaveTeamAskWraperHelper TeamRpcLeaveTeamAskWraperVar;
	public TeamRpcAppointTeamLeaderAskWraperHelper TeamRpcAppointTeamLeaderAskWraperVar;
	public TeamRpcNewLeaderNotifyWraperHelper TeamRpcNewLeaderNotifyWraperVar;
	public TeamRpcKickMemberAskWraperHelper TeamRpcKickMemberAskWraperVar;
	public TeamRpcDissmissTeamAskWraperHelper TeamRpcDissmissTeamAskWraperVar;
	public TeamRpcAppointTeamLeaderNotifyWraperHelper TeamRpcAppointTeamLeaderNotifyWraperVar;
	public TeamRpcKickMemberNotifyNotifyWraperHelper TeamRpcKickMemberNotifyNotifyWraperVar;
	public TeamRpcLeaveTeamNotifyNotifyWraperHelper TeamRpcLeaveTeamNotifyNotifyWraperVar;
	public TeamRpcJoinTeamNotifyNotifyWraperHelper TeamRpcJoinTeamNotifyNotifyWraperVar;
	public TeamRpcDissmissTeamNotifyNotifyWraperHelper TeamRpcDissmissTeamNotifyNotifyWraperVar;
	public TeamRpcSurroundingTeamAskWraperHelper TeamRpcSurroundingTeamAskWraperVar;
	public TeamRpcApplyTeamAskWraperHelper TeamRpcApplyTeamAskWraperVar;
	public TeamRpcApplyTeamNotifyNotifyWraperHelper TeamRpcApplyTeamNotifyNotifyWraperVar;
	public TeamRpcAgreeApplicantAskWraperHelper TeamRpcAgreeApplicantAskWraperVar;
	public TeamRpcAgreeApplicantNotifyNotifyWraperHelper TeamRpcAgreeApplicantNotifyNotifyWraperVar;
	public TeamRpcTeamInfoNotifyWraperHelper TeamRpcTeamInfoNotifyWraperVar;
	public TeamRpcUpdateTeamMemInfoNotifyWraperHelper TeamRpcUpdateTeamMemInfoNotifyWraperVar;


	public void TestJoinTeam()
	{
		TeamRPC.Instance.JoinTeam(TeamRpcJoinTeamAskWraperVar.TeamId,TeamRpcJoinTeamAskWraperVar.TeamType,TeamRpcJoinTeamAskWraperVar.Team,TeamRpcJoinTeamAskWraperVar.TeamMember,delegate(object obj){});
	}
	public void TestLeaveTeam()
	{
		TeamRPC.Instance.LeaveTeam(delegate(object obj){});
	}
	public void TestAppointTeamLeader()
	{
		TeamRPC.Instance.AppointTeamLeader(TeamRpcAppointTeamLeaderAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestCreateTeam()
	{
		TeamRPC.Instance.CreateTeam(TeamRpcCreateTeamAskWraperVar.TeamType,delegate(object obj){});
	}
	public void TestDissmissTeam()
	{
		TeamRPC.Instance.DissmissTeam(delegate(object obj){});
	}
	public void TestKickMember()
	{
		TeamRPC.Instance.KickMember(TeamRpcKickMemberAskWraperVar.KickMemberRoleId,delegate(object obj){});
	}
	public void TestSurroundingTeam()
	{
		TeamRPC.Instance.SurroundingTeam(delegate(object obj){});
	}
	public void TestApplyTeam()
	{
		TeamRPC.Instance.ApplyTeam(TeamRpcApplyTeamAskWraperVar.TeamId,delegate(object obj){});
	}
	public void TestAgreeApplicant()
	{
		TeamRPC.Instance.AgreeApplicant(TeamRpcAgreeApplicantAskWraperVar.RoleId,delegate(object obj){});
	}


}

[CustomEditor(typeof(TeamTestHelper))]
public class TeamTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("JoinTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestJoinTeam();
		}
		if (GUILayout.Button("LeaveTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestLeaveTeam();
		}
		if (GUILayout.Button("AppointTeamLeader"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestAppointTeamLeader();
		}
		if (GUILayout.Button("CreateTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestCreateTeam();
		}
		if (GUILayout.Button("DissmissTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestDissmissTeam();
		}
		if (GUILayout.Button("KickMember"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestKickMember();
		}
		if (GUILayout.Button("SurroundingTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestSurroundingTeam();
		}
		if (GUILayout.Button("ApplyTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestApplyTeam();
		}
		if (GUILayout.Button("AgreeApplicant"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestAgreeApplicant();
		}


    }

}
#endif