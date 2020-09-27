ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcNewLeaderNotifyCB = null
RpcDissmissTeamNotifyNotifyCB = null
RpcJoinTeamNotifyNotifyCB = null
RpcKickMemberNotifyNotifyCB = null
RpcLeaveTeamNotifyNotifyCB = null
RpcApplyTeamNotifyNotifyCB = null
RpcAgreeApplicantNotifyNotifyCB = null
RpcTeamInfoNotifyCB = null
RpcUpdateTeamMemInfoNotifyCB = null
RpcSummonMemberNotifyNotifyCB = null
RpcChangeTeamTargetNotifyNotifyCB = null
RpcChangeTeamTypeNotifyNotifyCB = null
RpcInviteTeamMemberNotifyNotifyCB = null
RpcApplyListNotifyNotifyCB = null
RpcEnterAutoCombatNotifyCB = null
RpcHangUpAutoCombatNotifyCB = null
RpcUpdateTeamHpInfoNotifyCB = null
RpcUpdateTeamPosInfoNotifyCB = null
RpcUpdateTeamBuffInfoNotifyCB = null
RpcUpdateFollowStatusNotifyCB = null
RpcEnterTeamFollowNotifyCB = null


ModuleId = 10
RPC_CODE_LEAVETEAM_REQUEST = 1051
RPC_CODE_APPOINTTEAMLEADER_REQUEST = 1052
RPC_CODE_CREATETEAM_REQUEST = 1053
RPC_CODE_DISSMISSTEAM_REQUEST = 1054
RPC_CODE_NEWLEADER_NOTIFY = 1055
RPC_CODE_KICKMEMBER_REQUEST = 1056
RPC_CODE_DISSMISSTEAMNOTIFY_NOTIFY = 1057
RPC_CODE_JOINTEAMNOTIFY_NOTIFY = 1058
RPC_CODE_KICKMEMBERNOTIFY_NOTIFY = 1059
RPC_CODE_LEAVETEAMNOTIFY_NOTIFY = 1060
RPC_CODE_SURROUNDINGTEAM_REQUEST = 1061
RPC_CODE_APPLYTEAM_REQUEST = 1062
RPC_CODE_APPLYTEAMNOTIFY_NOTIFY = 1063
RPC_CODE_AGREEAPPLICANT_REQUEST = 1064
RPC_CODE_AGREEAPPLICANTNOTIFY_NOTIFY = 1065
RPC_CODE_TEAMINFO_NOTIFY = 1066
RPC_CODE_UPDATETEAMMEMINFO_NOTIFY = 1067
RPC_CODE_FOLLOWTEAMLEADER_REQUEST = 1068
RPC_CODE_SUMMONMEMBER_REQUEST = 1069
RPC_CODE_SUMMONMEMBERNOTIFY_NOTIFY = 1070
RPC_CODE_CHANGETEAMTARGET_REQUEST = 1071
RPC_CODE_CHANGETEAMTARGETNOTIFY_NOTIFY = 1072
RPC_CODE_CHANGTEAMTYPE_REQUEST = 1073
RPC_CODE_CHANGETEAMTYPENOTIFY_NOTIFY = 1074
RPC_CODE_INVITETEAMMEMBER_REQUEST = 1075
RPC_CODE_INVITETEAMMEMBERNOTIFY_NOTIFY = 1076
RPC_CODE_APPLYLISTNOTIFY_NOTIFY = 1077
RPC_CODE_AGREEJOINTEAM_REQUEST = 1078
RPC_CODE_REFUSEMEMBER_REQUEST = 1079
RPC_CODE_CLEARAPPLYLIST_REQUEST = 1080
RPC_CODE_NOTEAMINVITE_REQUEST = 1081
RPC_CODE_REJECTINVITE_REQUEST = 1082
RPC_CODE_ENTERAUTOCOMBAT_NOTIFY = 1083
RPC_CODE_HANGUPAUTOCOMBAT_NOTIFY = 1084
RPC_CODE_UPDATETEAMHPINFO_NOTIFY = 1085
RPC_CODE_UPDATETEAMPOSINFO_NOTIFY = 1086
RPC_CODE_UPDATETEAMBUFFINFO_NOTIFY = 1087
RPC_CODE_HANGEUPFOLLOW_REQUEST = 1088
RPC_CODE_GOONFOLLOW_REQUEST = 1089
RPC_CODE_UPDATEFOLLOWSTATUS_NOTIFY = 1090
RPC_CODE_REQUESTNOTEAMMEMBERLIST_REQUEST = 1091
RPC_CODE_ENTERTEAMFOLLOW_NOTIFY = 1092

LeaveTeamAskPB = null
LeaveTeamReplyPB = null
AppointTeamLeaderAskPB = null
AppointTeamLeaderReplyPB = null
CreateTeamAskPB = null
CreateTeamReplyPB = null
DissmissTeamAskPB = null
DissmissTeamReplyPB = null
NewLeaderNotifyPB = null
KickMemberAskPB = null
KickMemberReplyPB = null
DissmissTeamNotifyNotifyPB = null
JoinTeamNotifyNotifyPB = null
KickMemberNotifyNotifyPB = null
LeaveTeamNotifyNotifyPB = null
SurroundingTeamAskPB = null
SurroundingTeamReplyPB = null
ApplyTeamAskPB = null
ApplyTeamReplyPB = null
ApplyTeamNotifyNotifyPB = null
AgreeApplicantAskPB = null
AgreeApplicantReplyPB = null
AgreeApplicantNotifyNotifyPB = null
TeamInfoNotifyPB = null
UpdateTeamMemInfoNotifyPB = null
FollowTeamLeaderAskPB = null
FollowTeamLeaderReplyPB = null
SummonMemberAskPB = null
SummonMemberReplyPB = null
SummonMemberNotifyNotifyPB = null
ChangeTeamTargetAskPB = null
ChangeTeamTargetReplyPB = null
ChangeTeamTargetNotifyNotifyPB = null
ChangTeamTypeAskPB = null
ChangTeamTypeReplyPB = null
ChangeTeamTypeNotifyNotifyPB = null
InviteTeamMemberAskPB = null
InviteTeamMemberReplyPB = null
InviteTeamMemberNotifyNotifyPB = null
ApplyListNotifyNotifyPB = null
AgreeJoinTeamAskPB = null
AgreeJoinTeamReplyPB = null
RefuseMemberAskPB = null
RefuseMemberReplyPB = null
ClearApplyListAskPB = null
ClearApplyListReplyPB = null
NoTeamInviteAskPB = null
NoTeamInviteReplyPB = null
RejectInviteAskPB = null
RejectInviteReplyPB = null
EnterAutoCombatNotifyPB = null
HangUpAutoCombatNotifyPB = null
UpdateTeamHpInfoNotifyPB = null
UpdateTeamPosInfoNotifyPB = null
UpdateTeamBuffInfoNotifyPB = null
HangeUpFollowAskPB = null
HangeUpFollowReplyPB = null
GoOnFollowAskPB = null
GoOnFollowReplyPB = null
UpdateFollowStatusNotifyPB = null
RequestNoTeamMemberListAskPB = null
RequestNoTeamMemberListReplyPB = null
EnterTeamFollowNotifyPB = null

class TeamModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcLeaveTeamAsk
      {
      }
      message  RpcLeaveTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcAppointTeamLeaderAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcAppointTeamLeaderReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 NewLeaderId = 2[default=0];
      }
      message  TeamProfessionTarget
      {
        optional int32 ProfessionId = 1[default=-1];
        optional int32 Size = 2[default=-1];
      }
      message  TeamTarget
      {
        optional int32 Id = 1[default=0];
        optional int32 MinLevel = 2[default=0];
        optional int32 MaxLevel = 3[default=0];
        repeated TeamProfessionTarget Profession = 4;
        optional int32 TargetType = 5[default=0];
      }
      message  RpcCreateTeamAsk
      {
        optional int32 TeamType = 2[default=-1];
        optional TeamTarget TTarget = 6;
      }
      message  Vector3
      {
        optional float X = 1;
        optional float Y = 2;
        optional float Z = 3;
      }
      message  CharacterLocation
      {
        optional int32 SceneId = 2[default=-1];
        optional Vector3 Pos = 3;
        optional int32 MapId = 5[default=-1];
        optional int32 DungeonConfigId = 6[default=-1];
        optional int32 LineId = 7[default=-1];
        optional int32 SceneConfigId = 8[default=-1];
        optional int32 MirrorId = 9[default=-1];
        optional int32 ServerId = 10[default=-1];
      }
      message  TreasureEquipedID
      {
        optional int32 TreasureHair = 1[default=-1];
        optional int32 TreasureHead = 2[default=-1];
        optional int32 TreasureBody = 3[default=-1];
        optional int32 TreasureWeapon = 4[default=-1];
        optional int32 TreasureWing = 5[default=-1];
        optional int32 TreasureRiding = 6[default=-1];
        optional int32 TreasureFootPrint = 7[default=-1];
        optional int32 EquipHair = 8[default=-1];
        optional int32 EquipHead = 9[default=-1];
        optional int32 EquipBody = 10[default=-1];
        optional int32 EquipWeapon = 11[default=-1];
        optional bool Headdisplayswitch = 12;
        optional bool Fashiondisplayswitch = 13;
        optional int32 InitHair = 14[default=-1];
        optional int32 InitHead = 15[default=-1];
      }
      message  Color
      {
        optional float R = 1;
        optional float G = 2;
        optional float B = 3;
        optional float A = 4;
      }
      message  PinchFaceBase
      {
        optional int32 Id = 1[default=-1];
        optional float Value = 2;
        optional Color Color = 4;
      }
      message  PinchFaceData
      {
        repeated PinchFaceBase DataInfo = 1;
      }
      message  TeamMemberInfo
      {
        optional uint64 RoleId = 1[default=0];
        optional int32 Level = 3[default=0];
        optional string Name = 4;
        optional int32 ConfigId = 5[default=-1];
        optional int32 Hp = 6[default=-1];
        optional int32 Status = 8[default=-1];
        optional int64 MaxHp = 11[default=-1];
        optional CharacterLocation Location = 15;
        optional int32 ProfessionId = 16[default=-1];
        optional int32 OnLine = 17[default=1];
        optional int32 FollowTeam = 18[default=-1];
        repeated int32 BuffIdList = 19;
        optional bool Robot = 20;
        optional int32 Camp = 21[default=-1];
        optional uint64 GuildGuid = 22[default=0];
        optional int32 BattleScore = 23[default=-1];
        optional TreasureEquipedID Treasureinfo = 24;
        optional uint64 GhostGuid = 25[default=0];
        optional int32 Occupation = 26[default=-1];
        optional PinchFaceData PinchData = 27;
      }
      message  TeamInfo
      {
        repeated TeamMemberInfo Members = 1;
        optional uint64 LeaderRoleId = 2[default=0];
        optional uint64 TeamId = 3[default=0];
        optional int32 TeamType = 4[default=-1];
        optional TeamTarget TeamTarget = 5;
      }
      message  RpcCreateTeamReply
      {
        optional int32 Result = 1[default=-9999];
        optional TeamInfo Team = 2;
      }
      message  RpcDissmissTeamAsk
      {
      }
      message  RpcDissmissTeamReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcNewLeaderNotify
      {
        optional uint64 Newleaderroleid = 1[default=0];
      }
      message  RpcKickMemberAsk
      {
        optional uint64 KickMemberRoleId = 1[default=0];
      }
      message  RpcKickMemberReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcDissmissTeamNotifyNotify
      {
      }
      message  RpcJoinTeamNotifyNotify
      {
        optional TeamMemberInfo TeamMember = 1;
        optional TeamInfo Team = 2;
      }
      message  RpcKickMemberNotifyNotify
      {
        optional uint64 KickedMemberRoleId = 1[default=0];
      }
      message  RpcLeaveTeamNotifyNotify
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 NewLeaderRoleId = 2[default=0];
      }
      message  RpcSurroundingTeamAsk
      {
        optional int32 TargetGroupId = 2[default=-1];
        optional int32 TargetGroup = 3[default=0];
      }
      message  RpcSurroundingTeamReply
      {
        optional int32 Result = 1[default=-9999];
        repeated TeamInfo TeamsInfo = 2;
        optional int32 TargetGroupId = 5[default=-1];
        optional int32 TargetGroup = 6[default=0];
      }
      message  RpcApplyTeamAsk
      {
        optional uint64 TeamId = 1[default=0];
      }
      message  RpcApplyTeamReply
      {
        optional int32 Result = 1[default=-9999];
        optional uint64 TeamId = 2[default=0];
      }
      message  RpcApplyTeamNotifyNotify
      {
        optional TeamMemberInfo TeamMember = 1;
      }
      message  RpcAgreeApplicantAsk
      {
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcAgreeApplicantReply
      {
        optional int32 Result = 1[default=-9999];
      }
      message  RpcAgreeApplicantNotifyNotify
      {
        optional TeamInfo Team = 1;
      }
      message  RpcTeamInfoNotify
      {
        optional TeamInfo Team = 1;
        optional int32 FollowTeamLeader = 2[default=-1];
      }
      message  RpcUpdateTeamMemInfoNotify
      {
        optional TeamMemberInfo TeamMember = 1;
      }
      message  RpcFollowTeamLeaderAsk
      {
        optional int32 FollowTeamLeader = 1[default=-1];
      }
      message  RpcFollowTeamLeaderReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 FollowTeamLeader = 2[default=-1];
      }
      message  RpcSummonMemberAsk
      {
      }
      message  RpcSummonMemberReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcSummonMemberNotifyNotify
      {
        optional int32 StringNoticeId = 1[default=-1];
      }
      message  RpcChangeTeamTargetAsk
      {
        optional TeamTarget Target = 6;
      }
      message  RpcChangeTeamTargetReply
      {
        optional int32 Result = 1[default=-1];
        optional TeamTarget TeamTarget = 2;
      }
      message  RpcChangeTeamTargetNotifyNotify
      {
        optional TeamTarget TeamTarget = 1;
      }
      message  RpcChangTeamTypeAsk
      {
        optional int32 TeamType = 1[default=-1];
      }
      message  RpcChangTeamTypeReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 TeamType = 2[default=-1];
        optional TeamTarget TeamTarget = 3;
      }
      message  RpcChangeTeamTypeNotifyNotify
      {
        optional int32 TeamType = 1[default=-1];
        optional TeamTarget TeamTarget = 2;
      }
      message  RpcInviteTeamMemberAsk
      {
        repeated uint64 RoleId = 1;
      }
      message  RpcInviteTeamMemberReply
      {
        optional int32 Result = 1[default=-1];
        repeated uint64 RoleId = 2;
      }
      message  RpcInviteTeamMemberNotifyNotify
      {
        optional uint64 TeamId = 1[default=0];
        optional int32 IsLeader = 5[default=-1];
        optional TeamMemberInfo InviteMemberInfo = 6;
      }
      message  RpcApplyListNotifyNotify
      {
        repeated TeamMemberInfo ApplyList = 1;
      }
      message  RpcAgreeJoinTeamAsk
      {
        optional uint64 TeamId = 1[default=0];
        optional int32 IsLeader = 2[default=-1];
      }
      message  RpcAgreeJoinTeamReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcRefuseMemberAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcRefuseMemberReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcClearApplyListAsk
      {
      }
      message  RpcClearApplyListReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcNoTeamInviteAsk
      {
        optional int32 TeamType = 1[default=-1];
        optional TeamTarget TTarget = 2;
        optional uint64 InviteRoleId = 3[default=0];
      }
      message  RpcNoTeamInviteReply
      {
        optional int32 Result = 1[default=-1];
        optional TeamInfo Team = 2;
      }
      message  RpcRejectInviteAsk
      {
        optional uint64 RoleId = 3[default=0];
        optional string Name = 4;
      }
      message  RpcRejectInviteReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcEnterAutoCombatNotify
      {
      }
      message  RpcHangUpAutoCombatNotify
      {
      }
      message  TeamMemberHpInfo
      {
        optional int32 Hp = 1[default=-1];
        optional int64 MaxHp = 3[default=-1];
        optional uint64 RoleId = 4[default=0];
      }
      message  RpcUpdateTeamHpInfoNotify
      {
        optional TeamMemberHpInfo Member = 1;
      }
      message  TeamMemberPos
      {
        optional Vector3 Pos = 1;
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcUpdateTeamPosInfoNotify
      {
        optional TeamMemberPos Member = 1;
      }
      message  TeanMemberBuff
      {
        optional uint64 RoleId = 1[default=0];
        repeated int32 BuffIdList = 2;
      }
      message  RpcUpdateTeamBuffInfoNotify
      {
        optional TeanMemberBuff Member = 1;
      }
      message  RpcHangeUpFollowAsk
      {
      }
      message  RpcHangeUpFollowReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 FollowStatus = 2[default=-1];
      }
      message  RpcGoOnFollowAsk
      {
      }
      message  RpcGoOnFollowReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 FollowStatus = 2[default=-1];
      }
      message  RpcUpdateFollowStatusNotify
      {
        optional int32 FollowStatus = 1[default=-1];
      }
      message  RpcRequestNoTeamMemberListAsk
      {
        optional int32 RequestType = 1[default=-1];
      }
      message  RpcRequestNoTeamMemberListReply
      {
        optional int32 Result = 1[default=-1];
        optional int32 RequestType = 2[default=-1];
        repeated TeamMemberInfo MemberList = 3;
      }
      message  RpcEnterTeamFollowNotify
      {
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    LeaveTeamAskPB = Proto.build("RpcLeaveTeamAsk")
    LeaveTeamReplyPB = Proto.build("RpcLeaveTeamReply")
    AppointTeamLeaderAskPB = Proto.build("RpcAppointTeamLeaderAsk")
    AppointTeamLeaderReplyPB = Proto.build("RpcAppointTeamLeaderReply")
    CreateTeamAskPB = Proto.build("RpcCreateTeamAsk")
    CreateTeamReplyPB = Proto.build("RpcCreateTeamReply")
    DissmissTeamAskPB = Proto.build("RpcDissmissTeamAsk")
    DissmissTeamReplyPB = Proto.build("RpcDissmissTeamReply")
    NewLeaderNotifyPB = Proto.build("RpcNewLeaderNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWLEADER_NOTIFY,@NewLeaderCB)
    KickMemberAskPB = Proto.build("RpcKickMemberAsk")
    KickMemberReplyPB = Proto.build("RpcKickMemberReply")
    DissmissTeamNotifyNotifyPB = Proto.build("RpcDissmissTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_DISSMISSTEAMNOTIFY_NOTIFY,@DissmissTeamNotifyCB)
    JoinTeamNotifyNotifyPB = Proto.build("RpcJoinTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_JOINTEAMNOTIFY_NOTIFY,@JoinTeamNotifyCB)
    KickMemberNotifyNotifyPB = Proto.build("RpcKickMemberNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_KICKMEMBERNOTIFY_NOTIFY,@KickMemberNotifyCB)
    LeaveTeamNotifyNotifyPB = Proto.build("RpcLeaveTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_LEAVETEAMNOTIFY_NOTIFY,@LeaveTeamNotifyCB)
    SurroundingTeamAskPB = Proto.build("RpcSurroundingTeamAsk")
    SurroundingTeamReplyPB = Proto.build("RpcSurroundingTeamReply")
    ApplyTeamAskPB = Proto.build("RpcApplyTeamAsk")
    ApplyTeamReplyPB = Proto.build("RpcApplyTeamReply")
    ApplyTeamNotifyNotifyPB = Proto.build("RpcApplyTeamNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYTEAMNOTIFY_NOTIFY,@ApplyTeamNotifyCB)
    AgreeApplicantAskPB = Proto.build("RpcAgreeApplicantAsk")
    AgreeApplicantReplyPB = Proto.build("RpcAgreeApplicantReply")
    AgreeApplicantNotifyNotifyPB = Proto.build("RpcAgreeApplicantNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_AGREEAPPLICANTNOTIFY_NOTIFY,@AgreeApplicantNotifyCB)
    TeamInfoNotifyPB = Proto.build("RpcTeamInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_TEAMINFO_NOTIFY,@TeamInfoCB)
    UpdateTeamMemInfoNotifyPB = Proto.build("RpcUpdateTeamMemInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATETEAMMEMINFO_NOTIFY,@UpdateTeamMemInfoCB)
    FollowTeamLeaderAskPB = Proto.build("RpcFollowTeamLeaderAsk")
    FollowTeamLeaderReplyPB = Proto.build("RpcFollowTeamLeaderReply")
    SummonMemberAskPB = Proto.build("RpcSummonMemberAsk")
    SummonMemberReplyPB = Proto.build("RpcSummonMemberReply")
    SummonMemberNotifyNotifyPB = Proto.build("RpcSummonMemberNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_SUMMONMEMBERNOTIFY_NOTIFY,@SummonMemberNotifyCB)
    ChangeTeamTargetAskPB = Proto.build("RpcChangeTeamTargetAsk")
    ChangeTeamTargetReplyPB = Proto.build("RpcChangeTeamTargetReply")
    ChangeTeamTargetNotifyNotifyPB = Proto.build("RpcChangeTeamTargetNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGETEAMTARGETNOTIFY_NOTIFY,@ChangeTeamTargetNotifyCB)
    ChangTeamTypeAskPB = Proto.build("RpcChangTeamTypeAsk")
    ChangTeamTypeReplyPB = Proto.build("RpcChangTeamTypeReply")
    ChangeTeamTypeNotifyNotifyPB = Proto.build("RpcChangeTeamTypeNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_CHANGETEAMTYPENOTIFY_NOTIFY,@ChangeTeamTypeNotifyCB)
    InviteTeamMemberAskPB = Proto.build("RpcInviteTeamMemberAsk")
    InviteTeamMemberReplyPB = Proto.build("RpcInviteTeamMemberReply")
    InviteTeamMemberNotifyNotifyPB = Proto.build("RpcInviteTeamMemberNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_INVITETEAMMEMBERNOTIFY_NOTIFY,@InviteTeamMemberNotifyCB)
    ApplyListNotifyNotifyPB = Proto.build("RpcApplyListNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYLISTNOTIFY_NOTIFY,@ApplyListNotifyCB)
    AgreeJoinTeamAskPB = Proto.build("RpcAgreeJoinTeamAsk")
    AgreeJoinTeamReplyPB = Proto.build("RpcAgreeJoinTeamReply")
    RefuseMemberAskPB = Proto.build("RpcRefuseMemberAsk")
    RefuseMemberReplyPB = Proto.build("RpcRefuseMemberReply")
    ClearApplyListAskPB = Proto.build("RpcClearApplyListAsk")
    ClearApplyListReplyPB = Proto.build("RpcClearApplyListReply")
    NoTeamInviteAskPB = Proto.build("RpcNoTeamInviteAsk")
    NoTeamInviteReplyPB = Proto.build("RpcNoTeamInviteReply")
    RejectInviteAskPB = Proto.build("RpcRejectInviteAsk")
    RejectInviteReplyPB = Proto.build("RpcRejectInviteReply")
    EnterAutoCombatNotifyPB = Proto.build("RpcEnterAutoCombatNotify")
    mLayerMgr.registerNotify(RPC_CODE_ENTERAUTOCOMBAT_NOTIFY,@EnterAutoCombatCB)
    HangUpAutoCombatNotifyPB = Proto.build("RpcHangUpAutoCombatNotify")
    mLayerMgr.registerNotify(RPC_CODE_HANGUPAUTOCOMBAT_NOTIFY,@HangUpAutoCombatCB)
    UpdateTeamHpInfoNotifyPB = Proto.build("RpcUpdateTeamHpInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATETEAMHPINFO_NOTIFY,@UpdateTeamHpInfoCB)
    UpdateTeamPosInfoNotifyPB = Proto.build("RpcUpdateTeamPosInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATETEAMPOSINFO_NOTIFY,@UpdateTeamPosInfoCB)
    UpdateTeamBuffInfoNotifyPB = Proto.build("RpcUpdateTeamBuffInfoNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATETEAMBUFFINFO_NOTIFY,@UpdateTeamBuffInfoCB)
    HangeUpFollowAskPB = Proto.build("RpcHangeUpFollowAsk")
    HangeUpFollowReplyPB = Proto.build("RpcHangeUpFollowReply")
    GoOnFollowAskPB = Proto.build("RpcGoOnFollowAsk")
    GoOnFollowReplyPB = Proto.build("RpcGoOnFollowReply")
    UpdateFollowStatusNotifyPB = Proto.build("RpcUpdateFollowStatusNotify")
    mLayerMgr.registerNotify(RPC_CODE_UPDATEFOLLOWSTATUS_NOTIFY,@UpdateFollowStatusCB)
    RequestNoTeamMemberListAskPB = Proto.build("RpcRequestNoTeamMemberListAsk")
    RequestNoTeamMemberListReplyPB = Proto.build("RpcRequestNoTeamMemberListReply")
    EnterTeamFollowNotifyPB = Proto.build("RpcEnterTeamFollowNotify")
    mLayerMgr.registerNotify(RPC_CODE_ENTERTEAMFOLLOW_NOTIFY,@EnterTeamFollowCB)






  LeaveTeam : (replyCB) ->
    LeaveTeamAsk = LeaveTeamAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_LEAVETEAM_REQUEST,LeaveTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( LeaveTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AppointTeamLeader : (RoleId,replyCB) ->
    AppointTeamLeaderAsk = AppointTeamLeaderAskPB.prototype
    AppointTeamLeaderAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_APPOINTTEAMLEADER_REQUEST,AppointTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AppointTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateTeam : (TeamType,TTarget,replyCB) ->
    CreateTeamAsk = CreateTeamAskPB.prototype
    CreateTeamAsk.setTeamType TeamType
    CreateTeamAsk.setTTarget TTarget
    mLayerMgr.sendAsk(RPC_CODE_CREATETEAM_REQUEST,CreateTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DissmissTeam : (replyCB) ->
    DissmissTeamAsk = DissmissTeamAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_DISSMISSTEAM_REQUEST,DissmissTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DissmissTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  KickMember : (KickMemberRoleId,replyCB) ->
    KickMemberAsk = KickMemberAskPB.prototype
    KickMemberAsk.setKickMemberRoleId KickMemberRoleId
    mLayerMgr.sendAsk(RPC_CODE_KICKMEMBER_REQUEST,KickMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( KickMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SurroundingTeam : (TargetGroupId,TargetGroup,replyCB) ->
    SurroundingTeamAsk = SurroundingTeamAskPB.prototype
    SurroundingTeamAsk.setTargetGroupId TargetGroupId
    SurroundingTeamAsk.setTargetGroup TargetGroup
    mLayerMgr.sendAsk(RPC_CODE_SURROUNDINGTEAM_REQUEST,SurroundingTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SurroundingTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ApplyTeam : (TeamId,replyCB) ->
    ApplyTeamAsk = ApplyTeamAskPB.prototype
    ApplyTeamAsk.setTeamId TeamId
    mLayerMgr.sendAsk(RPC_CODE_APPLYTEAM_REQUEST,ApplyTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ApplyTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeApplicant : (RoleId,replyCB) ->
    AgreeApplicantAsk = AgreeApplicantAskPB.prototype
    AgreeApplicantAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_AGREEAPPLICANT_REQUEST,AgreeApplicantAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeApplicantReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  FollowTeamLeader : (FollowTeamLeader,replyCB) ->
    FollowTeamLeaderAsk = FollowTeamLeaderAskPB.prototype
    FollowTeamLeaderAsk.setFollowTeamLeader FollowTeamLeader
    mLayerMgr.sendAsk(RPC_CODE_FOLLOWTEAMLEADER_REQUEST,FollowTeamLeaderAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( FollowTeamLeaderReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SummonMember : (replyCB) ->
    SummonMemberAsk = SummonMemberAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SUMMONMEMBER_REQUEST,SummonMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SummonMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangeTeamTarget : (Target,replyCB) ->
    ChangeTeamTargetAsk = ChangeTeamTargetAskPB.prototype
    ChangeTeamTargetAsk.setTarget Target
    mLayerMgr.sendAsk(RPC_CODE_CHANGETEAMTARGET_REQUEST,ChangeTeamTargetAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangeTeamTargetReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChangTeamType : (TeamType,replyCB) ->
    ChangTeamTypeAsk = ChangTeamTypeAskPB.prototype
    ChangTeamTypeAsk.setTeamType TeamType
    mLayerMgr.sendAsk(RPC_CODE_CHANGTEAMTYPE_REQUEST,ChangTeamTypeAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChangTeamTypeReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  InviteTeamMember : (RoleId,replyCB) ->
    InviteTeamMemberAsk = InviteTeamMemberAskPB.prototype
    InviteTeamMemberAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_INVITETEAMMEMBER_REQUEST,InviteTeamMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( InviteTeamMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeJoinTeam : (TeamId,IsLeader,replyCB) ->
    AgreeJoinTeamAsk = AgreeJoinTeamAskPB.prototype
    AgreeJoinTeamAsk.setTeamId TeamId
    AgreeJoinTeamAsk.setIsLeader IsLeader
    mLayerMgr.sendAsk(RPC_CODE_AGREEJOINTEAM_REQUEST,AgreeJoinTeamAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeJoinTeamReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RefuseMember : (RoleId,replyCB) ->
    RefuseMemberAsk = RefuseMemberAskPB.prototype
    RefuseMemberAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_REFUSEMEMBER_REQUEST,RefuseMemberAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RefuseMemberReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ClearApplyList : (replyCB) ->
    ClearApplyListAsk = ClearApplyListAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_CLEARAPPLYLIST_REQUEST,ClearApplyListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ClearApplyListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  NoTeamInvite : (TeamType,TTarget,InviteRoleId,replyCB) ->
    NoTeamInviteAsk = NoTeamInviteAskPB.prototype
    NoTeamInviteAsk.setTeamType TeamType
    NoTeamInviteAsk.setTTarget TTarget
    NoTeamInviteAsk.setInviteRoleId InviteRoleId
    mLayerMgr.sendAsk(RPC_CODE_NOTEAMINVITE_REQUEST,NoTeamInviteAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( NoTeamInviteReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RejectInvite : (RoleId,Name,replyCB) ->
    RejectInviteAsk = RejectInviteAskPB.prototype
    RejectInviteAsk.setRoleId RoleId
    RejectInviteAsk.setName Name
    mLayerMgr.sendAsk(RPC_CODE_REJECTINVITE_REQUEST,RejectInviteAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RejectInviteReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  HangeUpFollow : (replyCB) ->
    HangeUpFollowAsk = HangeUpFollowAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_HANGEUPFOLLOW_REQUEST,HangeUpFollowAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( HangeUpFollowReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  GoOnFollow : (replyCB) ->
    GoOnFollowAsk = GoOnFollowAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_GOONFOLLOW_REQUEST,GoOnFollowAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( GoOnFollowReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RequestNoTeamMemberList : (RequestType,replyCB) ->
    RequestNoTeamMemberListAsk = RequestNoTeamMemberListAskPB.prototype
    RequestNoTeamMemberListAsk.setRequestType RequestType
    mLayerMgr.sendAsk(RPC_CODE_REQUESTNOTEAMMEMBERLIST_REQUEST,RequestNoTeamMemberListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RequestNoTeamMemberListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetNewLeaderNotifyCB : (cb) -> RpcNewLeaderNotifyCB = cb
  NewLeaderCB : (data)->
    RpcNewLeaderNotifyCB( NewLeaderNotifyPB.decode(data)) if typeof(RpcNewLeaderNotifyCB) is "function"
  SetDissmissTeamNotifyNotifyCB : (cb) -> RpcDissmissTeamNotifyNotifyCB = cb
  DissmissTeamNotifyCB : (data)->
    RpcDissmissTeamNotifyNotifyCB( DissmissTeamNotifyNotifyPB.decode(data)) if typeof(RpcDissmissTeamNotifyNotifyCB) is "function"
  SetJoinTeamNotifyNotifyCB : (cb) -> RpcJoinTeamNotifyNotifyCB = cb
  JoinTeamNotifyCB : (data)->
    RpcJoinTeamNotifyNotifyCB( JoinTeamNotifyNotifyPB.decode(data)) if typeof(RpcJoinTeamNotifyNotifyCB) is "function"
  SetKickMemberNotifyNotifyCB : (cb) -> RpcKickMemberNotifyNotifyCB = cb
  KickMemberNotifyCB : (data)->
    RpcKickMemberNotifyNotifyCB( KickMemberNotifyNotifyPB.decode(data)) if typeof(RpcKickMemberNotifyNotifyCB) is "function"
  SetLeaveTeamNotifyNotifyCB : (cb) -> RpcLeaveTeamNotifyNotifyCB = cb
  LeaveTeamNotifyCB : (data)->
    RpcLeaveTeamNotifyNotifyCB( LeaveTeamNotifyNotifyPB.decode(data)) if typeof(RpcLeaveTeamNotifyNotifyCB) is "function"
  SetApplyTeamNotifyNotifyCB : (cb) -> RpcApplyTeamNotifyNotifyCB = cb
  ApplyTeamNotifyCB : (data)->
    RpcApplyTeamNotifyNotifyCB( ApplyTeamNotifyNotifyPB.decode(data)) if typeof(RpcApplyTeamNotifyNotifyCB) is "function"
  SetAgreeApplicantNotifyNotifyCB : (cb) -> RpcAgreeApplicantNotifyNotifyCB = cb
  AgreeApplicantNotifyCB : (data)->
    RpcAgreeApplicantNotifyNotifyCB( AgreeApplicantNotifyNotifyPB.decode(data)) if typeof(RpcAgreeApplicantNotifyNotifyCB) is "function"
  SetTeamInfoNotifyCB : (cb) -> RpcTeamInfoNotifyCB = cb
  TeamInfoCB : (data)->
    RpcTeamInfoNotifyCB( TeamInfoNotifyPB.decode(data)) if typeof(RpcTeamInfoNotifyCB) is "function"
  SetUpdateTeamMemInfoNotifyCB : (cb) -> RpcUpdateTeamMemInfoNotifyCB = cb
  UpdateTeamMemInfoCB : (data)->
    RpcUpdateTeamMemInfoNotifyCB( UpdateTeamMemInfoNotifyPB.decode(data)) if typeof(RpcUpdateTeamMemInfoNotifyCB) is "function"
  SetSummonMemberNotifyNotifyCB : (cb) -> RpcSummonMemberNotifyNotifyCB = cb
  SummonMemberNotifyCB : (data)->
    RpcSummonMemberNotifyNotifyCB( SummonMemberNotifyNotifyPB.decode(data)) if typeof(RpcSummonMemberNotifyNotifyCB) is "function"
  SetChangeTeamTargetNotifyNotifyCB : (cb) -> RpcChangeTeamTargetNotifyNotifyCB = cb
  ChangeTeamTargetNotifyCB : (data)->
    RpcChangeTeamTargetNotifyNotifyCB( ChangeTeamTargetNotifyNotifyPB.decode(data)) if typeof(RpcChangeTeamTargetNotifyNotifyCB) is "function"
  SetChangeTeamTypeNotifyNotifyCB : (cb) -> RpcChangeTeamTypeNotifyNotifyCB = cb
  ChangeTeamTypeNotifyCB : (data)->
    RpcChangeTeamTypeNotifyNotifyCB( ChangeTeamTypeNotifyNotifyPB.decode(data)) if typeof(RpcChangeTeamTypeNotifyNotifyCB) is "function"
  SetInviteTeamMemberNotifyNotifyCB : (cb) -> RpcInviteTeamMemberNotifyNotifyCB = cb
  InviteTeamMemberNotifyCB : (data)->
    RpcInviteTeamMemberNotifyNotifyCB( InviteTeamMemberNotifyNotifyPB.decode(data)) if typeof(RpcInviteTeamMemberNotifyNotifyCB) is "function"
  SetApplyListNotifyNotifyCB : (cb) -> RpcApplyListNotifyNotifyCB = cb
  ApplyListNotifyCB : (data)->
    RpcApplyListNotifyNotifyCB( ApplyListNotifyNotifyPB.decode(data)) if typeof(RpcApplyListNotifyNotifyCB) is "function"
  SetEnterAutoCombatNotifyCB : (cb) -> RpcEnterAutoCombatNotifyCB = cb
  EnterAutoCombatCB : (data)->
    RpcEnterAutoCombatNotifyCB( EnterAutoCombatNotifyPB.decode(data)) if typeof(RpcEnterAutoCombatNotifyCB) is "function"
  SetHangUpAutoCombatNotifyCB : (cb) -> RpcHangUpAutoCombatNotifyCB = cb
  HangUpAutoCombatCB : (data)->
    RpcHangUpAutoCombatNotifyCB( HangUpAutoCombatNotifyPB.decode(data)) if typeof(RpcHangUpAutoCombatNotifyCB) is "function"
  SetUpdateTeamHpInfoNotifyCB : (cb) -> RpcUpdateTeamHpInfoNotifyCB = cb
  UpdateTeamHpInfoCB : (data)->
    RpcUpdateTeamHpInfoNotifyCB( UpdateTeamHpInfoNotifyPB.decode(data)) if typeof(RpcUpdateTeamHpInfoNotifyCB) is "function"
  SetUpdateTeamPosInfoNotifyCB : (cb) -> RpcUpdateTeamPosInfoNotifyCB = cb
  UpdateTeamPosInfoCB : (data)->
    RpcUpdateTeamPosInfoNotifyCB( UpdateTeamPosInfoNotifyPB.decode(data)) if typeof(RpcUpdateTeamPosInfoNotifyCB) is "function"
  SetUpdateTeamBuffInfoNotifyCB : (cb) -> RpcUpdateTeamBuffInfoNotifyCB = cb
  UpdateTeamBuffInfoCB : (data)->
    RpcUpdateTeamBuffInfoNotifyCB( UpdateTeamBuffInfoNotifyPB.decode(data)) if typeof(RpcUpdateTeamBuffInfoNotifyCB) is "function"
  SetUpdateFollowStatusNotifyCB : (cb) -> RpcUpdateFollowStatusNotifyCB = cb
  UpdateFollowStatusCB : (data)->
    RpcUpdateFollowStatusNotifyCB( UpdateFollowStatusNotifyPB.decode(data)) if typeof(RpcUpdateFollowStatusNotifyCB) is "function"
  SetEnterTeamFollowNotifyCB : (cb) -> RpcEnterTeamFollowNotifyCB = cb
  EnterTeamFollowCB : (data)->
    RpcEnterTeamFollowNotifyCB( EnterTeamFollowNotifyPB.decode(data)) if typeof(RpcEnterTeamFollowNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "TeamModel",
      'AskName': ["LeaveTeam",
                   "AppointTeamLeader",
                   "CreateTeam",
                   "DissmissTeam",
                   "KickMember",
                   "SurroundingTeam",
                   "ApplyTeam",
                   "AgreeApplicant",
                   "FollowTeamLeader",
                   "SummonMember",
                   "ChangeTeamTarget",
                   "ChangTeamType",
                   "InviteTeamMember",
                   "AgreeJoinTeam",
                   "RefuseMember",
                   "ClearApplyList",
                   "NoTeamInvite",
                   "RejectInvite",
                   "HangeUpFollow",
                   "GoOnFollow",
                   "RequestNoTeamMemberList"]
      'ParamterList': [[],
                       ["RoleId"],
                       ["TeamType","TTarget"],
                       [],
                       ["KickMemberRoleId"],
                       ["TargetGroupId","TargetGroup"],
                       ["TeamId"],
                       ["RoleId"],
                       ["FollowTeamLeader"],
                       [],
                       ["Target"],
                       ["TeamType"],
                       ["RoleId"],
                       ["TeamId","IsLeader"],
                       ["RoleId"],
                       [],
                       ["TeamType","TTarget","InviteRoleId"],
                       ["RoleId","Name"],
                       [],
                       [],
                       ["RequestType"]]
      'AskList':[@LeaveTeam,
                 @AppointTeamLeader,
                 @CreateTeam,
                 @DissmissTeam,
                 @KickMember,
                 @SurroundingTeam,
                 @ApplyTeam,
                 @AgreeApplicant,
                 @FollowTeamLeader,
                 @SummonMember,
                 @ChangeTeamTarget,
                 @ChangTeamType,
                 @InviteTeamMember,
                 @AgreeJoinTeam,
                 @RefuseMember,
                 @ClearApplyList,
                 @NoTeamInvite,
                 @RejectInvite,
                 @HangeUpFollow,
                 @GoOnFollow,
                 @RequestNoTeamMemberList]
      'ParamterTypelist': [[],
                       ["uint64"],
                       ["int32","TeamTarget"],
                       [],
                       ["uint64"],
                       ["int32","int32"],
                       ["uint64"],
                       ["uint64"],
                       ["int32"],
                       [],
                       ["TeamTarget"],
                       ["int32"],
                       ["uint64"],
                       ["uint64","int32"],
                       ["uint64"],
                       [],
                       ["int32","TeamTarget","uint64"],
                       ["uint64","string"],
                       [],
                       [],
                       ["int32"]]


module.exports =(()->
  if not Team?
    Team = new TeamModel()
  Team)()



  

  

  


