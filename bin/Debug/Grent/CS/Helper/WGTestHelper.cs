#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class WGRpcInformCreateTeamAskWraperHelper
{
	public TeamInfoWraper Team;
	public int Result;
}
[System.Serializable]
public class WGRpcInformJoinTeamAskWraperHelper
{
	public TeamMemberInfoWraper Member;
	public TeamInfoWraper Team;
}
[System.Serializable]
public class WGRpcInformLeaveAskWraperHelper
{
	public UInt64 RoleId;
	public UInt64 NewLeaderRoleId;
	public int Result;
}
[System.Serializable]
public class WGRpcInformAppointTeamLeaderAskWraperHelper
{
	public int Result;
	public UInt64 NewLeaderRoleId;
	public UInt64 OldLeaderRoleId;
}
[System.Serializable]
public class WGRpcInformKickTeamMemberAskWraperHelper
{
	public int Result;
	public UInt64 KickedMemberRoleId;
	public UInt64 LeaderRoleId;
}
[System.Serializable]
public class WGRpcInformDissmissTeamAskWraperHelper
{
	public int Result;
	public UInt64 LeaderRoleId;
}
[System.Serializable]
public class WGRpcInformApplyTeamAskWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
	public int Result;
	public int TeamId;
}
[System.Serializable]
public class WGRpcAgreeTeamApplicantAskWraperHelper
{
	public TeamInfoWraper Team;
}
[System.Serializable]
public class WGRpcInformLoginAskWraperHelper
{
	public TeamInfoWraper Team;
}



public class WGTestHelper : MonoBehaviour
{
	public WGRpcInformCreateTeamAskWraperHelper WGRpcInformCreateTeamAskWraperVar;
	public WGRpcInformJoinTeamAskWraperHelper WGRpcInformJoinTeamAskWraperVar;
	public WGRpcInformLeaveAskWraperHelper WGRpcInformLeaveAskWraperVar;
	public WGRpcInformAppointTeamLeaderAskWraperHelper WGRpcInformAppointTeamLeaderAskWraperVar;
	public WGRpcInformKickTeamMemberAskWraperHelper WGRpcInformKickTeamMemberAskWraperVar;
	public WGRpcInformDissmissTeamAskWraperHelper WGRpcInformDissmissTeamAskWraperVar;
	public WGRpcInformApplyTeamAskWraperHelper WGRpcInformApplyTeamAskWraperVar;
	public WGRpcAgreeTeamApplicantAskWraperHelper WGRpcAgreeTeamApplicantAskWraperVar;
	public WGRpcInformLoginAskWraperHelper WGRpcInformLoginAskWraperVar;


	public void TestInformCreateTeam()
	{
		WGRPC.Instance.InformCreateTeam(WGRpcInformCreateTeamAskWraperVar.Team,WGRpcInformCreateTeamAskWraperVar.Result,delegate(object obj){});
	}
	public void TestInformJoinTeam()
	{
		WGRPC.Instance.InformJoinTeam(WGRpcInformJoinTeamAskWraperVar.Member,WGRpcInformJoinTeamAskWraperVar.Team,delegate(object obj){});
	}
	public void TestInformLeave()
	{
		WGRPC.Instance.InformLeave(WGRpcInformLeaveAskWraperVar.RoleId,WGRpcInformLeaveAskWraperVar.NewLeaderRoleId,WGRpcInformLeaveAskWraperVar.Result,delegate(object obj){});
	}
	public void TestInformAppointTeamLeader()
	{
		WGRPC.Instance.InformAppointTeamLeader(WGRpcInformAppointTeamLeaderAskWraperVar.Result,WGRpcInformAppointTeamLeaderAskWraperVar.NewLeaderRoleId,WGRpcInformAppointTeamLeaderAskWraperVar.OldLeaderRoleId,delegate(object obj){});
	}
	public void TestInformKickTeamMember()
	{
		WGRPC.Instance.InformKickTeamMember(WGRpcInformKickTeamMemberAskWraperVar.Result,WGRpcInformKickTeamMemberAskWraperVar.KickedMemberRoleId,WGRpcInformKickTeamMemberAskWraperVar.LeaderRoleId,delegate(object obj){});
	}
	public void TestInformDissmissTeam()
	{
		WGRPC.Instance.InformDissmissTeam(WGRpcInformDissmissTeamAskWraperVar.Result,WGRpcInformDissmissTeamAskWraperVar.LeaderRoleId,delegate(object obj){});
	}
	public void TestInformApplyTeam()
	{
		WGRPC.Instance.InformApplyTeam(WGRpcInformApplyTeamAskWraperVar.TeamMember,WGRpcInformApplyTeamAskWraperVar.Result,WGRpcInformApplyTeamAskWraperVar.TeamId,delegate(object obj){});
	}
	public void TestAgreeTeamApplicant()
	{
		WGRPC.Instance.AgreeTeamApplicant(WGRpcAgreeTeamApplicantAskWraperVar.Team,delegate(object obj){});
	}
	public void TestInformLogin()
	{
		WGRPC.Instance.InformLogin(WGRpcInformLoginAskWraperVar.Team,delegate(object obj){});
	}


}

[CustomEditor(typeof(WGTestHelper))]
public class WGTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("InformCreateTeam"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformCreateTeam();
		}
		if (GUILayout.Button("InformJoinTeam"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformJoinTeam();
		}
		if (GUILayout.Button("InformLeave"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformLeave();
		}
		if (GUILayout.Button("InformAppointTeamLeader"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformAppointTeamLeader();
		}
		if (GUILayout.Button("InformKickTeamMember"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformKickTeamMember();
		}
		if (GUILayout.Button("InformDissmissTeam"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformDissmissTeam();
		}
		if (GUILayout.Button("InformApplyTeam"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformApplyTeam();
		}
		if (GUILayout.Button("AgreeTeamApplicant"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestAgreeTeamApplicant();
		}
		if (GUILayout.Button("InformLogin"))
		{
			WGTestHelper rpc = target as WGTestHelper;
			if( rpc ) rpc.TestInformLogin();
		}


    }

}
#endif