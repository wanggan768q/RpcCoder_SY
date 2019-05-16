#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class GuildRpcGuildBaseInfoAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcKickMemberAskWraperHelper
{
	public int Guid;
	public string KickReason;
	public int ReasonType;
}
[System.Serializable]
public class GuildRpcKickMemberNotifyNotifyWraperHelper
{
	public string KickReason;
	public int ReasonType;
}
[System.Serializable]
public class GuildRpcAskVacationAskWraperHelper
{
	public int Guid;
	public string Reason;
	public int Type;
}
[System.Serializable]
public class GuildRpcAskVacationReplyWraperHelper
{
	public int Result;
	public int Guid;
	public int Type;
}
[System.Serializable]
public class GuildRpcVacationNotifyWraperHelper
{
	public GuildVacationInfoWraper VacationInfo;
	public int Type;
}
[System.Serializable]
public class GuildRpcReplyVacationNotifyWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskApplyListAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskApplyListReplyWraperHelper
{
	public int Result;
	public List<GuildMemberTinyInfoWraper> GuildMemberTinyInfoList;
}
[System.Serializable]
public class GuildRpcApplyGuildOperationAskWraperHelper
{
	public UInt64 Guid;
	public int Operation;
}
[System.Serializable]
public class GuildRpcApplyGuildNotifyWraperHelper
{
	public UInt64 GuildID;
	public string GuildName;
}
[System.Serializable]
public class GuildRpcApplyLimitSettingAskWraperHelper
{
	public bool IsAutoJoin;
}
[System.Serializable]
public class GuildRpcAskJurisdictionListAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskJurisdictionListReplyWraperHelper
{
	public int Result;
	public List<GuildOfficeJurisdictionWraper> JurisdictionList;
}
[System.Serializable]
public class GuildRpcSetJurisdictionAskWraperHelper
{
	public GuildOfficeJurisdictionWraper SetList;
}
[System.Serializable]
public class GuildRpcAskVacationListAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskVacationListReplyWraperHelper
{
	public int Result;
	public List<GuildVacationInfoWraper> VacationList;
}
[System.Serializable]
public class GuildRpcVacationGuildOperationAskWraperHelper
{
	public UInt64 Guid;
	public int Operation;
}
[System.Serializable]
public class GuildRpcApplyGuildToOfficeNotifyWraperHelper
{
	public GuildMemberTinyInfoWraper GuildMemberTinyInfo;
}
[System.Serializable]
public class GuildRpcAskBuildingInfoAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskBuildingInfoReplyWraperHelper
{
	public int Result;
	public List<GuildBuildingInfoWraper> BuildingInfoList;
}
[System.Serializable]
public class GuildRpcBuildingLvUpAskWraperHelper
{
	public int BuildingType;
}
[System.Serializable]
public class GuildRpcBuildingLvSpeedUpAskWraperHelper
{
	public int BuildingType;
	public int Time;
}
[System.Serializable]
public class GuildRpcAskBuildingContributionListAskWraperHelper
{
	public int BuildingType;
}
[System.Serializable]
public class GuildRpcAskBuildingContributionListReplyWraperHelper
{
	public int Result;
	public List<GuildBuildingContributionInfoWraper> ContributionList;
	public int BuildingType;
}
[System.Serializable]
public class GuildRpcBuildingCanLvUpNotifyWraperHelper
{
	public int BuildingType;
}
[System.Serializable]
public class GuildRpcAskGuildEventListAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskGuildEventListReplyWraperHelper
{
	public int Result;
	public List<GuildEventWraper> GuildEventList;
}
[System.Serializable]
public class GuildRpcAskGuildInfoListAskWraperHelper
{
	public int PageIndex;
}
[System.Serializable]
public class GuildRpcAskGuildInfoListReplyWraperHelper
{
	public int Result;
	public List<GuildInfoWraper> GuildInfoList;
	public int PageIndex;
	public int TotalGuildCount;
}
[System.Serializable]
public class GuildRpcSearchGuildAskWraperHelper
{
	public string Text;
}
[System.Serializable]
public class GuildRpcJoinGuildAskWraperHelper
{
	public UInt64 Guid;
	public int Type;
}
[System.Serializable]
public class GuildRpcCreateGuildAskWraperHelper
{
	public string GuildName;
	public string GuildCreed;
}
[System.Serializable]
public class GuildRpcChangeFlagAskWraperHelper
{
	public int FlagConfigID;
}
[System.Serializable]
public class GuildRpcGuildChangeNameAskWraperHelper
{
	public string GuildNewName;
}
[System.Serializable]
public class GuildRpcAskGuildMemberAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcAskGuildMemberReplyWraperHelper
{
	public int Result;
	public List<GuildMemberInfoWraper> GuildMemberInfoList;
	public int OnlineCount;
	public int MemberCount;
}
[System.Serializable]
public class GuildRpcQuiteGuildAskWraperHelper
{
}
[System.Serializable]
public class GuildRpcSetOfficeAskWraperHelper
{
	public UInt64 Guid;
	public UInt64 TargetGuid;
	public int OfficeType;
}
[System.Serializable]
public class GuildRpcOfficeChangeNotifyWraperHelper
{
	public int OfficeType;
	public UInt64 Optguid;
	public int OptOfficeType;
}
[System.Serializable]
public class GuildRpcChangeCreedAskWraperHelper
{
	public string Content;
}
[System.Serializable]
public class GuildRpcForbiddenChatAskWraperHelper
{
	public Int64 Playerguid;
	public bool IsForbidden;
}
[System.Serializable]
public class GuildRpcBuildLvUpCompleteNotifyWraperHelper
{
	public GuildBuildingInfoWraper GuildBuildingInfo;
}
[System.Serializable]
public class GuildRpcGuildCurrencyChangeNotifyWraperHelper
{
	public int GuildProsper;
	public int GuildMoney;
	public int GuildResource;
	public int GuildWelfare;
	public int MaintainCost;
}



public class GuildTestHelper : MonoBehaviour
{
	public GuildRpcGuildBaseInfoAskWraperHelper GuildRpcGuildBaseInfoAskWraperVar;
	public GuildRpcKickMemberAskWraperHelper GuildRpcKickMemberAskWraperVar;
	public GuildRpcKickMemberNotifyNotifyWraperHelper GuildRpcKickMemberNotifyNotifyWraperVar;
	public GuildRpcAskVacationAskWraperHelper GuildRpcAskVacationAskWraperVar;
	public GuildRpcAskVacationReplyWraperHelper GuildRpcAskVacationReplyWraperVar;
	public GuildRpcVacationNotifyWraperHelper GuildRpcVacationNotifyWraperVar;
	public GuildRpcReplyVacationNotifyWraperHelper GuildRpcReplyVacationNotifyWraperVar;
	public GuildRpcAskApplyListAskWraperHelper GuildRpcAskApplyListAskWraperVar;
	public GuildRpcAskApplyListReplyWraperHelper GuildRpcAskApplyListReplyWraperVar;
	public GuildRpcApplyGuildOperationAskWraperHelper GuildRpcApplyGuildOperationAskWraperVar;
	public GuildRpcApplyGuildNotifyWraperHelper GuildRpcApplyGuildNotifyWraperVar;
	public GuildRpcApplyLimitSettingAskWraperHelper GuildRpcApplyLimitSettingAskWraperVar;
	public GuildRpcAskJurisdictionListAskWraperHelper GuildRpcAskJurisdictionListAskWraperVar;
	public GuildRpcAskJurisdictionListReplyWraperHelper GuildRpcAskJurisdictionListReplyWraperVar;
	public GuildRpcSetJurisdictionAskWraperHelper GuildRpcSetJurisdictionAskWraperVar;
	public GuildRpcAskVacationListAskWraperHelper GuildRpcAskVacationListAskWraperVar;
	public GuildRpcAskVacationListReplyWraperHelper GuildRpcAskVacationListReplyWraperVar;
	public GuildRpcVacationGuildOperationAskWraperHelper GuildRpcVacationGuildOperationAskWraperVar;
	public GuildRpcApplyGuildToOfficeNotifyWraperHelper GuildRpcApplyGuildToOfficeNotifyWraperVar;
	public GuildRpcAskBuildingInfoAskWraperHelper GuildRpcAskBuildingInfoAskWraperVar;
	public GuildRpcAskBuildingInfoReplyWraperHelper GuildRpcAskBuildingInfoReplyWraperVar;
	public GuildRpcBuildingLvUpAskWraperHelper GuildRpcBuildingLvUpAskWraperVar;
	public GuildRpcBuildingLvSpeedUpAskWraperHelper GuildRpcBuildingLvSpeedUpAskWraperVar;
	public GuildRpcAskBuildingContributionListAskWraperHelper GuildRpcAskBuildingContributionListAskWraperVar;
	public GuildRpcAskBuildingContributionListReplyWraperHelper GuildRpcAskBuildingContributionListReplyWraperVar;
	public GuildRpcBuildingCanLvUpNotifyWraperHelper GuildRpcBuildingCanLvUpNotifyWraperVar;
	public GuildRpcAskGuildEventListAskWraperHelper GuildRpcAskGuildEventListAskWraperVar;
	public GuildRpcAskGuildEventListReplyWraperHelper GuildRpcAskGuildEventListReplyWraperVar;
	public GuildRpcAskGuildInfoListAskWraperHelper GuildRpcAskGuildInfoListAskWraperVar;
	public GuildRpcAskGuildInfoListReplyWraperHelper GuildRpcAskGuildInfoListReplyWraperVar;
	public GuildRpcSearchGuildAskWraperHelper GuildRpcSearchGuildAskWraperVar;
	public GuildRpcJoinGuildAskWraperHelper GuildRpcJoinGuildAskWraperVar;
	public GuildRpcCreateGuildAskWraperHelper GuildRpcCreateGuildAskWraperVar;
	public GuildRpcChangeFlagAskWraperHelper GuildRpcChangeFlagAskWraperVar;
	public GuildRpcGuildChangeNameAskWraperHelper GuildRpcGuildChangeNameAskWraperVar;
	public GuildRpcAskGuildMemberAskWraperHelper GuildRpcAskGuildMemberAskWraperVar;
	public GuildRpcAskGuildMemberReplyWraperHelper GuildRpcAskGuildMemberReplyWraperVar;
	public GuildRpcQuiteGuildAskWraperHelper GuildRpcQuiteGuildAskWraperVar;
	public GuildRpcSetOfficeAskWraperHelper GuildRpcSetOfficeAskWraperVar;
	public GuildRpcOfficeChangeNotifyWraperHelper GuildRpcOfficeChangeNotifyWraperVar;
	public GuildRpcChangeCreedAskWraperHelper GuildRpcChangeCreedAskWraperVar;
	public GuildRpcForbiddenChatAskWraperHelper GuildRpcForbiddenChatAskWraperVar;
	public GuildRpcBuildLvUpCompleteNotifyWraperHelper GuildRpcBuildLvUpCompleteNotifyWraperVar;
	public GuildRpcGuildCurrencyChangeNotifyWraperHelper GuildRpcGuildCurrencyChangeNotifyWraperVar;


	public void TestGuildBaseInfo()
	{
		GuildRPC.Instance.GuildBaseInfo(delegate(object obj){});
	}
	public void TestKickMember()
	{
		GuildRPC.Instance.KickMember(GuildRpcKickMemberAskWraperVar.Guid,GuildRpcKickMemberAskWraperVar.KickReason,GuildRpcKickMemberAskWraperVar.ReasonType,delegate(object obj){});
	}
	public void TestAskVacation()
	{
		GuildRPC.Instance.AskVacation(GuildRpcAskVacationAskWraperVar.Guid,GuildRpcAskVacationAskWraperVar.Reason,GuildRpcAskVacationAskWraperVar.Type,delegate(object obj){});
	}
	public void TestAskApplyList()
	{
		GuildRPC.Instance.AskApplyList(delegate(object obj){});
	}
	public void TestApplyGuildOperation()
	{
		GuildRPC.Instance.ApplyGuildOperation(GuildRpcApplyGuildOperationAskWraperVar.Guid,GuildRpcApplyGuildOperationAskWraperVar.Operation,delegate(object obj){});
	}
	public void TestApplyLimitSetting()
	{
		GuildRPC.Instance.ApplyLimitSetting(GuildRpcApplyLimitSettingAskWraperVar.IsAutoJoin,delegate(object obj){});
	}
	public void TestAskJurisdictionList()
	{
		GuildRPC.Instance.AskJurisdictionList(delegate(object obj){});
	}
	public void TestSetJurisdiction()
	{
		GuildRPC.Instance.SetJurisdiction(GuildRpcSetJurisdictionAskWraperVar.SetList,delegate(object obj){});
	}
	public void TestAskVacationList()
	{
		GuildRPC.Instance.AskVacationList(delegate(object obj){});
	}
	public void TestVacationGuildOperation()
	{
		GuildRPC.Instance.VacationGuildOperation(GuildRpcVacationGuildOperationAskWraperVar.Guid,GuildRpcVacationGuildOperationAskWraperVar.Operation,delegate(object obj){});
	}
	public void TestAskBuildingInfo()
	{
		GuildRPC.Instance.AskBuildingInfo(delegate(object obj){});
	}
	public void TestBuildingLvUp()
	{
		GuildRPC.Instance.BuildingLvUp(GuildRpcBuildingLvUpAskWraperVar.BuildingType,delegate(object obj){});
	}
	public void TestBuildingLvSpeedUp()
	{
		GuildRPC.Instance.BuildingLvSpeedUp(GuildRpcBuildingLvSpeedUpAskWraperVar.BuildingType,GuildRpcBuildingLvSpeedUpAskWraperVar.Time,delegate(object obj){});
	}
	public void TestAskBuildingContributionList()
	{
		GuildRPC.Instance.AskBuildingContributionList(GuildRpcAskBuildingContributionListAskWraperVar.BuildingType,delegate(object obj){});
	}
	public void TestAskGuildEventList()
	{
		GuildRPC.Instance.AskGuildEventList(delegate(object obj){});
	}
	public void TestAskGuildInfoList()
	{
		GuildRPC.Instance.AskGuildInfoList(GuildRpcAskGuildInfoListAskWraperVar.PageIndex,delegate(object obj){});
	}
	public void TestSearchGuild()
	{
		GuildRPC.Instance.SearchGuild(GuildRpcSearchGuildAskWraperVar.Text,delegate(object obj){});
	}
	public void TestJoinGuild()
	{
		GuildRPC.Instance.JoinGuild(GuildRpcJoinGuildAskWraperVar.Guid,GuildRpcJoinGuildAskWraperVar.Type,delegate(object obj){});
	}
	public void TestCreateGuild()
	{
		GuildRPC.Instance.CreateGuild(GuildRpcCreateGuildAskWraperVar.GuildName,GuildRpcCreateGuildAskWraperVar.GuildCreed,delegate(object obj){});
	}
	public void TestChangeFlag()
	{
		GuildRPC.Instance.ChangeFlag(GuildRpcChangeFlagAskWraperVar.FlagConfigID,delegate(object obj){});
	}
	public void TestGuildChangeName()
	{
		GuildRPC.Instance.GuildChangeName(GuildRpcGuildChangeNameAskWraperVar.GuildNewName,delegate(object obj){});
	}
	public void TestAskGuildMember()
	{
		GuildRPC.Instance.AskGuildMember(delegate(object obj){});
	}
	public void TestQuiteGuild()
	{
		GuildRPC.Instance.QuiteGuild(delegate(object obj){});
	}
	public void TestSetOffice()
	{
		GuildRPC.Instance.SetOffice(GuildRpcSetOfficeAskWraperVar.Guid,GuildRpcSetOfficeAskWraperVar.TargetGuid,GuildRpcSetOfficeAskWraperVar.OfficeType,delegate(object obj){});
	}
	public void TestChangeCreed()
	{
		GuildRPC.Instance.ChangeCreed(GuildRpcChangeCreedAskWraperVar.Content,delegate(object obj){});
	}
	public void TestForbiddenChat()
	{
		GuildRPC.Instance.ForbiddenChat(GuildRpcForbiddenChatAskWraperVar.Playerguid,GuildRpcForbiddenChatAskWraperVar.IsForbidden,delegate(object obj){});
	}


}

[CustomEditor(typeof(GuildTestHelper))]
public class GuildTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("GuildBaseInfo"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestGuildBaseInfo();
		}
		if (GUILayout.Button("KickMember"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestKickMember();
		}
		if (GUILayout.Button("AskVacation"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskVacation();
		}
		if (GUILayout.Button("AskApplyList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskApplyList();
		}
		if (GUILayout.Button("ApplyGuildOperation"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestApplyGuildOperation();
		}
		if (GUILayout.Button("ApplyLimitSetting"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestApplyLimitSetting();
		}
		if (GUILayout.Button("AskJurisdictionList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskJurisdictionList();
		}
		if (GUILayout.Button("SetJurisdiction"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestSetJurisdiction();
		}
		if (GUILayout.Button("AskVacationList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskVacationList();
		}
		if (GUILayout.Button("VacationGuildOperation"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestVacationGuildOperation();
		}
		if (GUILayout.Button("AskBuildingInfo"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskBuildingInfo();
		}
		if (GUILayout.Button("BuildingLvUp"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestBuildingLvUp();
		}
		if (GUILayout.Button("BuildingLvSpeedUp"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestBuildingLvSpeedUp();
		}
		if (GUILayout.Button("AskBuildingContributionList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskBuildingContributionList();
		}
		if (GUILayout.Button("AskGuildEventList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskGuildEventList();
		}
		if (GUILayout.Button("AskGuildInfoList"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskGuildInfoList();
		}
		if (GUILayout.Button("SearchGuild"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestSearchGuild();
		}
		if (GUILayout.Button("JoinGuild"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestJoinGuild();
		}
		if (GUILayout.Button("CreateGuild"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestCreateGuild();
		}
		if (GUILayout.Button("ChangeFlag"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestChangeFlag();
		}
		if (GUILayout.Button("GuildChangeName"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestGuildChangeName();
		}
		if (GUILayout.Button("AskGuildMember"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestAskGuildMember();
		}
		if (GUILayout.Button("QuiteGuild"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestQuiteGuild();
		}
		if (GUILayout.Button("SetOffice"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestSetOffice();
		}
		if (GUILayout.Button("ChangeCreed"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestChangeCreed();
		}
		if (GUILayout.Button("ForbiddenChat"))
		{
			GuildTestHelper rpc = target as GuildTestHelper;
			if( rpc ) rpc.TestForbiddenChat();
		}


    }

}
#endif