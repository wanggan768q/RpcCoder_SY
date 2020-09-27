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
	public TeamTargetWraper TTarget;
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
	public TeamInfoWraper Team;
}
[System.Serializable]
public class TeamRpcDissmissTeamNotifyNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcSurroundingTeamAskWraperHelper
{
	public int TargetGroupId;
	public int TargetGroup;
}
[System.Serializable]
public class TeamRpcApplyTeamAskWraperHelper
{
	public UInt64 TeamId;
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
	public int FollowTeamLeader;
}
[System.Serializable]
public class TeamRpcUpdateTeamMemInfoNotifyWraperHelper
{
	public TeamMemberInfoWraper TeamMember;
}
[System.Serializable]
public class TeamRpcFollowTeamLeaderAskWraperHelper
{
	public int FollowTeamLeader;
}
[System.Serializable]
public class TeamRpcSummonMemberAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcSummonMemberNotifyNotifyWraperHelper
{
	public int StringNoticeId;
}
[System.Serializable]
public class TeamRpcChangeTeamTargetAskWraperHelper
{
	public TeamTargetWraper Target;
}
[System.Serializable]
public class TeamRpcChangeTeamTargetNotifyNotifyWraperHelper
{
	public TeamTargetWraper TeamTarget;
}
[System.Serializable]
public class TeamRpcChangTeamTypeAskWraperHelper
{
	public int TeamType;
}
[System.Serializable]
public class TeamRpcChangeTeamTypeNotifyNotifyWraperHelper
{
	public int TeamType;
	public TeamTargetWraper TeamTarget;
}
[System.Serializable]
public class TeamRpcInviteTeamMemberAskWraperHelper
{
	public List<UInt64> RoleId;
}
[System.Serializable]
public class TeamRpcInviteTeamMemberNotifyNotifyWraperHelper
{
	public UInt64 TeamId;
	public int IsLeader;
	public TeamMemberInfoWraper InviteMemberInfo;
}
[System.Serializable]
public class TeamRpcApplyListNotifyNotifyWraperHelper
{
	public List<TeamMemberInfoWraper> ApplyList;
}
[System.Serializable]
public class TeamRpcAgreeJoinTeamAskWraperHelper
{
	public UInt64 TeamId;
	public int IsLeader;
}
[System.Serializable]
public class TeamRpcRefuseMemberAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class TeamRpcClearApplyListAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcNoTeamInviteAskWraperHelper
{
	public int TeamType;
	public TeamTargetWraper TTarget;
	public UInt64 InviteRoleId;
}
[System.Serializable]
public class TeamRpcRejectInviteAskWraperHelper
{
	public UInt64 RoleId;
	public string Name;
}
[System.Serializable]
public class TeamRpcEnterAutoCombatNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcHangUpAutoCombatNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcUpdateTeamHpInfoNotifyWraperHelper
{
	public TeamMemberHpInfoWraper Member;
}
[System.Serializable]
public class TeamRpcUpdateTeamPosInfoNotifyWraperHelper
{
	public TeamMemberPosWraper Member;
}
[System.Serializable]
public class TeamRpcUpdateTeamBuffInfoNotifyWraperHelper
{
	public TeanMemberBuffWraper Member;
}
[System.Serializable]
public class TeamRpcHangeUpFollowAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcGoOnFollowAskWraperHelper
{
}
[System.Serializable]
public class TeamRpcUpdateFollowStatusNotifyWraperHelper
{
	public int FollowStatus;
}
[System.Serializable]
public class TeamRpcRequestNoTeamMemberListAskWraperHelper
{
	public int RequestType;
}
[System.Serializable]
public class TeamRpcEnterTeamFollowNotifyWraperHelper
{
}
[System.Serializable]
public class TeamRpcEnterLeaderSceneAskWraperHelper
{
}



public class TeamTestHelper : MonoBehaviour
{
	public TeamRpcCreateTeamAskWraperHelper TeamRpcCreateTeamAskWraperVar;
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
	public TeamRpcFollowTeamLeaderAskWraperHelper TeamRpcFollowTeamLeaderAskWraperVar;
	public TeamRpcSummonMemberAskWraperHelper TeamRpcSummonMemberAskWraperVar;
	public TeamRpcSummonMemberNotifyNotifyWraperHelper TeamRpcSummonMemberNotifyNotifyWraperVar;
	public TeamRpcChangeTeamTargetAskWraperHelper TeamRpcChangeTeamTargetAskWraperVar;
	public TeamRpcChangeTeamTargetNotifyNotifyWraperHelper TeamRpcChangeTeamTargetNotifyNotifyWraperVar;
	public TeamRpcChangTeamTypeAskWraperHelper TeamRpcChangTeamTypeAskWraperVar;
	public TeamRpcChangeTeamTypeNotifyNotifyWraperHelper TeamRpcChangeTeamTypeNotifyNotifyWraperVar;
	public TeamRpcInviteTeamMemberAskWraperHelper TeamRpcInviteTeamMemberAskWraperVar;
	public TeamRpcInviteTeamMemberNotifyNotifyWraperHelper TeamRpcInviteTeamMemberNotifyNotifyWraperVar;
	public TeamRpcApplyListNotifyNotifyWraperHelper TeamRpcApplyListNotifyNotifyWraperVar;
	public TeamRpcAgreeJoinTeamAskWraperHelper TeamRpcAgreeJoinTeamAskWraperVar;
	public TeamRpcRefuseMemberAskWraperHelper TeamRpcRefuseMemberAskWraperVar;
	public TeamRpcClearApplyListAskWraperHelper TeamRpcClearApplyListAskWraperVar;
	public TeamRpcNoTeamInviteAskWraperHelper TeamRpcNoTeamInviteAskWraperVar;
	public TeamRpcRejectInviteAskWraperHelper TeamRpcRejectInviteAskWraperVar;
	public TeamRpcEnterAutoCombatNotifyWraperHelper TeamRpcEnterAutoCombatNotifyWraperVar;
	public TeamRpcHangUpAutoCombatNotifyWraperHelper TeamRpcHangUpAutoCombatNotifyWraperVar;
	public TeamRpcUpdateTeamHpInfoNotifyWraperHelper TeamRpcUpdateTeamHpInfoNotifyWraperVar;
	public TeamRpcUpdateTeamPosInfoNotifyWraperHelper TeamRpcUpdateTeamPosInfoNotifyWraperVar;
	public TeamRpcUpdateTeamBuffInfoNotifyWraperHelper TeamRpcUpdateTeamBuffInfoNotifyWraperVar;
	public TeamRpcHangeUpFollowAskWraperHelper TeamRpcHangeUpFollowAskWraperVar;
	public TeamRpcGoOnFollowAskWraperHelper TeamRpcGoOnFollowAskWraperVar;
	public TeamRpcUpdateFollowStatusNotifyWraperHelper TeamRpcUpdateFollowStatusNotifyWraperVar;
	public TeamRpcRequestNoTeamMemberListAskWraperHelper TeamRpcRequestNoTeamMemberListAskWraperVar;
	public TeamRpcEnterTeamFollowNotifyWraperHelper TeamRpcEnterTeamFollowNotifyWraperVar;
	public TeamRpcEnterLeaderSceneAskWraperHelper TeamRpcEnterLeaderSceneAskWraperVar;


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
		TeamRPC.Instance.CreateTeam(TeamRpcCreateTeamAskWraperVar.TeamType,TeamRpcCreateTeamAskWraperVar.TTarget,delegate(object obj){});
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
		TeamRPC.Instance.SurroundingTeam(TeamRpcSurroundingTeamAskWraperVar.TargetGroupId,TeamRpcSurroundingTeamAskWraperVar.TargetGroup,delegate(object obj){});
	}
	public void TestApplyTeam()
	{
		TeamRPC.Instance.ApplyTeam(TeamRpcApplyTeamAskWraperVar.TeamId,delegate(object obj){});
	}
	public void TestAgreeApplicant()
	{
		TeamRPC.Instance.AgreeApplicant(TeamRpcAgreeApplicantAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestFollowTeamLeader()
	{
		TeamRPC.Instance.FollowTeamLeader(TeamRpcFollowTeamLeaderAskWraperVar.FollowTeamLeader,delegate(object obj){});
	}
	public void TestSummonMember()
	{
		TeamRPC.Instance.SummonMember(delegate(object obj){});
	}
	public void TestChangeTeamTarget()
	{
		TeamRPC.Instance.ChangeTeamTarget(TeamRpcChangeTeamTargetAskWraperVar.Target,delegate(object obj){});
	}
	public void TestChangTeamType()
	{
		TeamRPC.Instance.ChangTeamType(TeamRpcChangTeamTypeAskWraperVar.TeamType,delegate(object obj){});
	}
	public void TestInviteTeamMember()
	{
		TeamRPC.Instance.InviteTeamMember(TeamRpcInviteTeamMemberAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestAgreeJoinTeam()
	{
		TeamRPC.Instance.AgreeJoinTeam(TeamRpcAgreeJoinTeamAskWraperVar.TeamId,TeamRpcAgreeJoinTeamAskWraperVar.IsLeader,delegate(object obj){});
	}
	public void TestRefuseMember()
	{
		TeamRPC.Instance.RefuseMember(TeamRpcRefuseMemberAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestClearApplyList()
	{
		TeamRPC.Instance.ClearApplyList(delegate(object obj){});
	}
	public void TestNoTeamInvite()
	{
		TeamRPC.Instance.NoTeamInvite(TeamRpcNoTeamInviteAskWraperVar.TeamType,TeamRpcNoTeamInviteAskWraperVar.TTarget,TeamRpcNoTeamInviteAskWraperVar.InviteRoleId,delegate(object obj){});
	}
	public void TestRejectInvite()
	{
		TeamRPC.Instance.RejectInvite(TeamRpcRejectInviteAskWraperVar.RoleId,TeamRpcRejectInviteAskWraperVar.Name,delegate(object obj){});
	}
	public void TestHangeUpFollow()
	{
		TeamRPC.Instance.HangeUpFollow(delegate(object obj){});
	}
	public void TestGoOnFollow()
	{
		TeamRPC.Instance.GoOnFollow(delegate(object obj){});
	}
	public void TestRequestNoTeamMemberList()
	{
		TeamRPC.Instance.RequestNoTeamMemberList(TeamRpcRequestNoTeamMemberListAskWraperVar.RequestType,delegate(object obj){});
	}
	public void TestEnterLeaderScene()
	{
		TeamRPC.Instance.EnterLeaderScene(delegate(object obj){});
	}


}

[CustomEditor(typeof(TeamTestHelper))]
public class TeamTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
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
		if (GUILayout.Button("FollowTeamLeader"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestFollowTeamLeader();
		}
		if (GUILayout.Button("SummonMember"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestSummonMember();
		}
		if (GUILayout.Button("ChangeTeamTarget"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestChangeTeamTarget();
		}
		if (GUILayout.Button("ChangTeamType"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestChangTeamType();
		}
		if (GUILayout.Button("InviteTeamMember"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestInviteTeamMember();
		}
		if (GUILayout.Button("AgreeJoinTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestAgreeJoinTeam();
		}
		if (GUILayout.Button("RefuseMember"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestRefuseMember();
		}
		if (GUILayout.Button("ClearApplyList"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestClearApplyList();
		}
		if (GUILayout.Button("NoTeamInvite"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestNoTeamInvite();
		}
		if (GUILayout.Button("RejectInvite"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestRejectInvite();
		}
		if (GUILayout.Button("HangeUpFollow"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestHangeUpFollow();
		}
		if (GUILayout.Button("GoOnFollow"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestGoOnFollow();
		}
		if (GUILayout.Button("RequestNoTeamMemberList"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestRequestNoTeamMemberList();
		}
		if (GUILayout.Button("EnterLeaderScene"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestEnterLeaderScene();
		}


    }

}
#endif