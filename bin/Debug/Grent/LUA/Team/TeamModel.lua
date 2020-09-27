-- TeamModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 10;
local RPC_CODE_TEAM_LEAVETEAM_REQUEST = 1051
local RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST = 1052
local RPC_CODE_TEAM_CREATETEAM_REQUEST = 1053
local RPC_CODE_TEAM_DISSMISSTEAM_REQUEST = 1054
local RPC_CODE_TEAM_NEWLEADER_NOTIFY = 1055;
local RPC_CODE_TEAM_KICKMEMBER_REQUEST = 1056
local RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY = 1057;
local RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY = 1058;
local RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY = 1059;
local RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY = 1060;
local RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST = 1061
local RPC_CODE_TEAM_APPLYTEAM_REQUEST = 1062
local RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY = 1063;
local RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST = 1064
local RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY = 1065;
local RPC_CODE_TEAM_TEAMINFO_NOTIFY = 1066;
local RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY = 1067;
local RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST = 1068
local RPC_CODE_TEAM_SUMMONMEMBER_REQUEST = 1069
local RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY = 1070;
local RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST = 1071
local RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY = 1072;
local RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST = 1073
local RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY = 1074;
local RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST = 1075
local RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY = 1076;
local RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY = 1077;
local RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST = 1078
local RPC_CODE_TEAM_REFUSEMEMBER_REQUEST = 1079
local RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST = 1080
local RPC_CODE_TEAM_NOTEAMINVITE_REQUEST = 1081
local RPC_CODE_TEAM_REJECTINVITE_REQUEST = 1082
local RPC_CODE_TEAM_ENTERAUTOCOMBAT_NOTIFY = 1083;
local RPC_CODE_TEAM_HANGUPAUTOCOMBAT_NOTIFY = 1084;
local RPC_CODE_TEAM_UPDATETEAMHPINFO_NOTIFY = 1085;
local RPC_CODE_TEAM_UPDATETEAMPOSINFO_NOTIFY = 1086;
local RPC_CODE_TEAM_UPDATETEAMBUFFINFO_NOTIFY = 1087;
local RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST = 1088
local RPC_CODE_TEAM_GOONFOLLOW_REQUEST = 1089
local RPC_CODE_TEAM_UPDATEFOLLOWSTATUS_NOTIFY = 1090;
local RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST = 1091
local RPC_CODE_TEAM_ENTERTEAMFOLLOW_NOTIFY = 1092;
local RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST = 1093



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
require("3rd/pblua/TeamRpc_pb")
local  TeamRpc_pb = TeamRpc_pb
module("TeamModel")





function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			callback(Id,Index)
		end
	end
end

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = TeamRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_NEWLEADER_NOTIFY,handler(self,self.NewLeaderCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY,handler(self,self.DissmissTeamNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY,handler(self,self.JoinTeamNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY,handler(self,self.KickMemberNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY,handler(self,self.LeaveTeamNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY,handler(self,self.ApplyTeamNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY,handler(self,self.AgreeApplicantNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_TEAMINFO_NOTIFY,handler(self,self.TeamInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY,handler(self,self.UpdateTeamMemInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY,handler(self,self.SummonMemberNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY,handler(self,self.ChangeTeamTargetNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY,handler(self,self.ChangeTeamTypeNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY,handler(self,self.InviteTeamMemberNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY,handler(self,self.ApplyListNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_ENTERAUTOCOMBAT_NOTIFY,handler(self,self.EnterAutoCombatCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_HANGUPAUTOCOMBAT_NOTIFY,handler(self,self.HangUpAutoCombatCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATETEAMHPINFO_NOTIFY,handler(self,self.UpdateTeamHpInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATETEAMPOSINFO_NOTIFY,handler(self,self.UpdateTeamPosInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATETEAMBUFFINFO_NOTIFY,handler(self,self.UpdateTeamBuffInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATEFOLLOWSTATUS_NOTIFY,handler(self,self.UpdateFollowStatusCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_ENTERTEAMFOLLOW_NOTIFY,handler(self,self.EnterTeamFollowCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function LeaveTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcLeaveTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_LEAVETEAM_REQUEST',RPC_CODE_TEAM_LEAVETEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcLeaveTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => LeaveTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_LEAVETEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_LEAVETEAM_REQUEST',RPC_CODE_TEAM_LEAVETEAM_REQUEST)
end
function AppointTeamLeader(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAppointTeamLeaderAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST',RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => AppointTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST',RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST)
end
function CreateTeam(self,TeamType,TTarget,_hanlder)
	local PB = self.rpc_pb.TeamRpcCreateTeamAsk()
	PB.TeamType = TeamType
	PB.TTarget.Id = TTarget.Id
	PB.TTarget.MinLevel = TTarget.MinLevel
	PB.TTarget.MaxLevel = TTarget.MaxLevel
	for i = 1, #TTarget.Profession do
		table.insert( PB.TTarget.Profession,TTarget.Profession[i] )
	end
	PB.TTarget.TargetType = TTarget.TargetType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_CREATETEAM_REQUEST',RPC_CODE_TEAM_CREATETEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcCreateTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => CreateTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CREATETEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_CREATETEAM_REQUEST',RPC_CODE_TEAM_CREATETEAM_REQUEST)
end
function DissmissTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcDissmissTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_DISSMISSTEAM_REQUEST',RPC_CODE_TEAM_DISSMISSTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => DissmissTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_DISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_DISSMISSTEAM_REQUEST',RPC_CODE_TEAM_DISSMISSTEAM_REQUEST)
end
function KickMember(self,KickMemberRoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcKickMemberAsk()
	PB.KickMemberRoleId = KickMemberRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_KICKMEMBER_REQUEST',RPC_CODE_TEAM_KICKMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcKickMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => KickMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_KICKMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_KICKMEMBER_REQUEST',RPC_CODE_TEAM_KICKMEMBER_REQUEST)
end
function SurroundingTeam(self,TargetGroupId,TargetGroup,_hanlder)
	local PB = self.rpc_pb.TeamRpcSurroundingTeamAsk()
	PB.TargetGroupId = TargetGroupId
	PB.TargetGroup = TargetGroup
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST',RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcSurroundingTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => SurroundingTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST',RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST)
end
function ApplyTeam(self,TeamId,_hanlder)
	local PB = self.rpc_pb.TeamRpcApplyTeamAsk()
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_APPLYTEAM_REQUEST',RPC_CODE_TEAM_APPLYTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcApplyTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => ApplyTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_APPLYTEAM_REQUEST',RPC_CODE_TEAM_APPLYTEAM_REQUEST)
end
function AgreeApplicant(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAgreeApplicantAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST',RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAgreeApplicantReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => AgreeApplicant ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST',RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST)
end
function FollowTeamLeader(self,FollowTeamLeader,_hanlder)
	local PB = self.rpc_pb.TeamRpcFollowTeamLeaderAsk()
	PB.FollowTeamLeader = FollowTeamLeader
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST',RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcFollowTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => FollowTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST',RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST)
end
function SummonMember(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcSummonMemberAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_SUMMONMEMBER_REQUEST',RPC_CODE_TEAM_SUMMONMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcSummonMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => SummonMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_SUMMONMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_SUMMONMEMBER_REQUEST',RPC_CODE_TEAM_SUMMONMEMBER_REQUEST)
end
function ChangeTeamTarget(self,Target,_hanlder)
	local PB = self.rpc_pb.TeamRpcChangeTeamTargetAsk()
	PB.Target.Id = Target.Id
	PB.Target.MinLevel = Target.MinLevel
	PB.Target.MaxLevel = Target.MaxLevel
	for i = 1, #Target.Profession do
		table.insert( PB.Target.Profession,Target.Profession[i] )
	end
	PB.Target.TargetType = Target.TargetType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST',RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcChangeTeamTargetReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => ChangeTeamTarget ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST',RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST)
end
function ChangTeamType(self,TeamType,_hanlder)
	local PB = self.rpc_pb.TeamRpcChangTeamTypeAsk()
	PB.TeamType = TeamType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST',RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcChangTeamTypeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => ChangTeamType ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST',RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST)
end
function InviteTeamMember(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcInviteTeamMemberAsk()
	for i,v in ipairs(RoleId) do
		table.insert(PB.RoleId,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST',RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcInviteTeamMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => InviteTeamMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST',RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST)
end
function AgreeJoinTeam(self,TeamId,IsLeader,_hanlder)
	local PB = self.rpc_pb.TeamRpcAgreeJoinTeamAsk()
	PB.TeamId = TeamId
	PB.IsLeader = IsLeader
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST',RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAgreeJoinTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => AgreeJoinTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST',RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST)
end
function RefuseMember(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcRefuseMemberAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_REFUSEMEMBER_REQUEST',RPC_CODE_TEAM_REFUSEMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcRefuseMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => RefuseMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_REFUSEMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_REFUSEMEMBER_REQUEST',RPC_CODE_TEAM_REFUSEMEMBER_REQUEST)
end
function ClearApplyList(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcClearApplyListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST',RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcClearApplyListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => ClearApplyList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST',RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST)
end
function NoTeamInvite(self,TeamType,TTarget,InviteRoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcNoTeamInviteAsk()
	PB.TeamType = TeamType
	PB.TTarget.Id = TTarget.Id
	PB.TTarget.MinLevel = TTarget.MinLevel
	PB.TTarget.MaxLevel = TTarget.MaxLevel
	for i = 1, #TTarget.Profession do
		table.insert( PB.TTarget.Profession,TTarget.Profession[i] )
	end
	PB.TTarget.TargetType = TTarget.TargetType
	PB.InviteRoleId = InviteRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_NOTEAMINVITE_REQUEST',RPC_CODE_TEAM_NOTEAMINVITE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcNoTeamInviteReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => NoTeamInvite ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_NOTEAMINVITE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_NOTEAMINVITE_REQUEST',RPC_CODE_TEAM_NOTEAMINVITE_REQUEST)
end
function RejectInvite(self,RoleId,Name,_hanlder)
	local PB = self.rpc_pb.TeamRpcRejectInviteAsk()
	PB.RoleId = RoleId
	PB.Name = Name
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_REJECTINVITE_REQUEST',RPC_CODE_TEAM_REJECTINVITE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcRejectInviteReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => RejectInvite ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_REJECTINVITE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_REJECTINVITE_REQUEST',RPC_CODE_TEAM_REJECTINVITE_REQUEST)
end
function HangeUpFollow(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcHangeUpFollowAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST',RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcHangeUpFollowReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => HangeUpFollow ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST',RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST)
end
function GoOnFollow(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcGoOnFollowAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_GOONFOLLOW_REQUEST',RPC_CODE_TEAM_GOONFOLLOW_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcGoOnFollowReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => GoOnFollow ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_GOONFOLLOW_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_GOONFOLLOW_REQUEST',RPC_CODE_TEAM_GOONFOLLOW_REQUEST)
end
function RequestNoTeamMemberList(self,RequestType,_hanlder)
	local PB = self.rpc_pb.TeamRpcRequestNoTeamMemberListAsk()
	PB.RequestType = RequestType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST',RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcRequestNoTeamMemberListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => RequestNoTeamMemberList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST',RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST)
end
function EnterLeaderScene(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcEnterLeaderSceneAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST',RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcEnterLeaderSceneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Team => EnterLeaderScene ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST',RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerNewLeaderCBNotify(self,_hanlder)
	if not self.NewLeaderCBNotifyCallBack then
		self.NewLeaderCBNotifyCallBack = {}
	end
	table.insert(self.NewLeaderCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewLeaderCB(self,notifyMsg)
	if self.NewLeaderCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcNewLeaderNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewLeaderCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewLeaderCBNotify(self,_hanlder)
	if nil ~= self.NewLeaderCBNotifyCallBack then
		for i,callback in ipairs(self.NewLeaderCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewLeaderCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDissmissTeamNotifyCBNotify(self,_hanlder)
	if not self.DissmissTeamNotifyCBNotifyCallBack then
		self.DissmissTeamNotifyCBNotifyCallBack = {}
	end
	table.insert(self.DissmissTeamNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DissmissTeamNotifyCB(self,notifyMsg)
	if self.DissmissTeamNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcDissmissTeamNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DissmissTeamNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDissmissTeamNotifyCBNotify(self,_hanlder)
	if nil ~= self.DissmissTeamNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.DissmissTeamNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DissmissTeamNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerJoinTeamNotifyCBNotify(self,_hanlder)
	if not self.JoinTeamNotifyCBNotifyCallBack then
		self.JoinTeamNotifyCBNotifyCallBack = {}
	end
	table.insert(self.JoinTeamNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function JoinTeamNotifyCB(self,notifyMsg)
	if self.JoinTeamNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcJoinTeamNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.JoinTeamNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterJoinTeamNotifyCBNotify(self,_hanlder)
	if nil ~= self.JoinTeamNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.JoinTeamNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.JoinTeamNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerKickMemberNotifyCBNotify(self,_hanlder)
	if not self.KickMemberNotifyCBNotifyCallBack then
		self.KickMemberNotifyCBNotifyCallBack = {}
	end
	table.insert(self.KickMemberNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function KickMemberNotifyCB(self,notifyMsg)
	if self.KickMemberNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcKickMemberNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.KickMemberNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterKickMemberNotifyCBNotify(self,_hanlder)
	if nil ~= self.KickMemberNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.KickMemberNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.KickMemberNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLeaveTeamNotifyCBNotify(self,_hanlder)
	if not self.LeaveTeamNotifyCBNotifyCallBack then
		self.LeaveTeamNotifyCBNotifyCallBack = {}
	end
	table.insert(self.LeaveTeamNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LeaveTeamNotifyCB(self,notifyMsg)
	if self.LeaveTeamNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcLeaveTeamNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LeaveTeamNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLeaveTeamNotifyCBNotify(self,_hanlder)
	if nil ~= self.LeaveTeamNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.LeaveTeamNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LeaveTeamNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerApplyTeamNotifyCBNotify(self,_hanlder)
	if not self.ApplyTeamNotifyCBNotifyCallBack then
		self.ApplyTeamNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ApplyTeamNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ApplyTeamNotifyCB(self,notifyMsg)
	if self.ApplyTeamNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcApplyTeamNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyTeamNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterApplyTeamNotifyCBNotify(self,_hanlder)
	if nil ~= self.ApplyTeamNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyTeamNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyTeamNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerAgreeApplicantNotifyCBNotify(self,_hanlder)
	if not self.AgreeApplicantNotifyCBNotifyCallBack then
		self.AgreeApplicantNotifyCBNotifyCallBack = {}
	end
	table.insert(self.AgreeApplicantNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AgreeApplicantNotifyCB(self,notifyMsg)
	if self.AgreeApplicantNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcAgreeApplicantNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AgreeApplicantNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAgreeApplicantNotifyCBNotify(self,_hanlder)
	if nil ~= self.AgreeApplicantNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.AgreeApplicantNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AgreeApplicantNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerTeamInfoCBNotify(self,_hanlder)
	if not self.TeamInfoCBNotifyCallBack then
		self.TeamInfoCBNotifyCallBack = {}
	end
	table.insert(self.TeamInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamInfoCB(self,notifyMsg)
	if self.TeamInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcTeamInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TeamInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTeamInfoCBNotify(self,_hanlder)
	if nil ~= self.TeamInfoCBNotifyCallBack then
		for i,callback in ipairs(self.TeamInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TeamInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateTeamMemInfoCBNotify(self,_hanlder)
	if not self.UpdateTeamMemInfoCBNotifyCallBack then
		self.UpdateTeamMemInfoCBNotifyCallBack = {}
	end
	table.insert(self.UpdateTeamMemInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateTeamMemInfoCB(self,notifyMsg)
	if self.UpdateTeamMemInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateTeamMemInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateTeamMemInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateTeamMemInfoCBNotify(self,_hanlder)
	if nil ~= self.UpdateTeamMemInfoCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateTeamMemInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateTeamMemInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSummonMemberNotifyCBNotify(self,_hanlder)
	if not self.SummonMemberNotifyCBNotifyCallBack then
		self.SummonMemberNotifyCBNotifyCallBack = {}
	end
	table.insert(self.SummonMemberNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SummonMemberNotifyCB(self,notifyMsg)
	if self.SummonMemberNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcSummonMemberNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SummonMemberNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSummonMemberNotifyCBNotify(self,_hanlder)
	if nil ~= self.SummonMemberNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.SummonMemberNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SummonMemberNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChangeTeamTargetNotifyCBNotify(self,_hanlder)
	if not self.ChangeTeamTargetNotifyCBNotifyCallBack then
		self.ChangeTeamTargetNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ChangeTeamTargetNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChangeTeamTargetNotifyCB(self,notifyMsg)
	if self.ChangeTeamTargetNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcChangeTeamTargetNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChangeTeamTargetNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChangeTeamTargetNotifyCBNotify(self,_hanlder)
	if nil ~= self.ChangeTeamTargetNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ChangeTeamTargetNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChangeTeamTargetNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChangeTeamTypeNotifyCBNotify(self,_hanlder)
	if not self.ChangeTeamTypeNotifyCBNotifyCallBack then
		self.ChangeTeamTypeNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ChangeTeamTypeNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChangeTeamTypeNotifyCB(self,notifyMsg)
	if self.ChangeTeamTypeNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcChangeTeamTypeNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChangeTeamTypeNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChangeTeamTypeNotifyCBNotify(self,_hanlder)
	if nil ~= self.ChangeTeamTypeNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ChangeTeamTypeNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChangeTeamTypeNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerInviteTeamMemberNotifyCBNotify(self,_hanlder)
	if not self.InviteTeamMemberNotifyCBNotifyCallBack then
		self.InviteTeamMemberNotifyCBNotifyCallBack = {}
	end
	table.insert(self.InviteTeamMemberNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function InviteTeamMemberNotifyCB(self,notifyMsg)
	if self.InviteTeamMemberNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcInviteTeamMemberNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.InviteTeamMemberNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterInviteTeamMemberNotifyCBNotify(self,_hanlder)
	if nil ~= self.InviteTeamMemberNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.InviteTeamMemberNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.InviteTeamMemberNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerApplyListNotifyCBNotify(self,_hanlder)
	if not self.ApplyListNotifyCBNotifyCallBack then
		self.ApplyListNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ApplyListNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ApplyListNotifyCB(self,notifyMsg)
	if self.ApplyListNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcApplyListNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyListNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterApplyListNotifyCBNotify(self,_hanlder)
	if nil ~= self.ApplyListNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyListNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyListNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerEnterAutoCombatCBNotify(self,_hanlder)
	if not self.EnterAutoCombatCBNotifyCallBack then
		self.EnterAutoCombatCBNotifyCallBack = {}
	end
	table.insert(self.EnterAutoCombatCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function EnterAutoCombatCB(self,notifyMsg)
	if self.EnterAutoCombatCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcEnterAutoCombatNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.EnterAutoCombatCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterEnterAutoCombatCBNotify(self,_hanlder)
	if nil ~= self.EnterAutoCombatCBNotifyCallBack then
		for i,callback in ipairs(self.EnterAutoCombatCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.EnterAutoCombatCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerHangUpAutoCombatCBNotify(self,_hanlder)
	if not self.HangUpAutoCombatCBNotifyCallBack then
		self.HangUpAutoCombatCBNotifyCallBack = {}
	end
	table.insert(self.HangUpAutoCombatCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function HangUpAutoCombatCB(self,notifyMsg)
	if self.HangUpAutoCombatCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcHangUpAutoCombatNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.HangUpAutoCombatCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterHangUpAutoCombatCBNotify(self,_hanlder)
	if nil ~= self.HangUpAutoCombatCBNotifyCallBack then
		for i,callback in ipairs(self.HangUpAutoCombatCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.HangUpAutoCombatCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateTeamHpInfoCBNotify(self,_hanlder)
	if not self.UpdateTeamHpInfoCBNotifyCallBack then
		self.UpdateTeamHpInfoCBNotifyCallBack = {}
	end
	table.insert(self.UpdateTeamHpInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateTeamHpInfoCB(self,notifyMsg)
	if self.UpdateTeamHpInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateTeamHpInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateTeamHpInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateTeamHpInfoCBNotify(self,_hanlder)
	if nil ~= self.UpdateTeamHpInfoCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateTeamHpInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateTeamHpInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateTeamPosInfoCBNotify(self,_hanlder)
	if not self.UpdateTeamPosInfoCBNotifyCallBack then
		self.UpdateTeamPosInfoCBNotifyCallBack = {}
	end
	table.insert(self.UpdateTeamPosInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateTeamPosInfoCB(self,notifyMsg)
	if self.UpdateTeamPosInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateTeamPosInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateTeamPosInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateTeamPosInfoCBNotify(self,_hanlder)
	if nil ~= self.UpdateTeamPosInfoCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateTeamPosInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateTeamPosInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateTeamBuffInfoCBNotify(self,_hanlder)
	if not self.UpdateTeamBuffInfoCBNotifyCallBack then
		self.UpdateTeamBuffInfoCBNotifyCallBack = {}
	end
	table.insert(self.UpdateTeamBuffInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateTeamBuffInfoCB(self,notifyMsg)
	if self.UpdateTeamBuffInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateTeamBuffInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateTeamBuffInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateTeamBuffInfoCBNotify(self,_hanlder)
	if nil ~= self.UpdateTeamBuffInfoCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateTeamBuffInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateTeamBuffInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateFollowStatusCBNotify(self,_hanlder)
	if not self.UpdateFollowStatusCBNotifyCallBack then
		self.UpdateFollowStatusCBNotifyCallBack = {}
	end
	table.insert(self.UpdateFollowStatusCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateFollowStatusCB(self,notifyMsg)
	if self.UpdateFollowStatusCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateFollowStatusNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateFollowStatusCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateFollowStatusCBNotify(self,_hanlder)
	if nil ~= self.UpdateFollowStatusCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateFollowStatusCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateFollowStatusCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerEnterTeamFollowCBNotify(self,_hanlder)
	if not self.EnterTeamFollowCBNotifyCallBack then
		self.EnterTeamFollowCBNotifyCallBack = {}
	end
	table.insert(self.EnterTeamFollowCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function EnterTeamFollowCB(self,notifyMsg)
	if self.EnterTeamFollowCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcEnterTeamFollowNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.EnterTeamFollowCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterEnterTeamFollowCBNotify(self,_hanlder)
	if nil ~= self.EnterTeamFollowCBNotifyCallBack then
		for i,callback in ipairs(self.EnterTeamFollowCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.EnterTeamFollowCBNotifyCallBack, i )
			end
		end
	end
end


function registerDataCallback(self,_hanlder)
	if not self.DataCallback then
		self.DataCallback = {}
	end
	table.insert(self.DataCallback,_hanlder)
end

function unregisterDataCallback(self,_hanlder)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			if callback == _hanlder then
				table.remove(self.DataCallback, i )
			end
		end
	end
end

function GetValue(self, Id,Index )
	-- body
	
end

--[[
askList.Team = {}

local t = {}
t.name = "LeaveTeam"
t.para = {}
t.hand = TeamModel.LeaveTeam
t.pb = TeamRpc_pb.TeamRpcLeaveTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "AppointTeamLeader"
t.para = {{name="RoleId",t=1}}
t.hand = TeamModel.AppointTeamLeader
t.pb = TeamRpc_pb.TeamRpcAppointTeamLeaderAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "CreateTeam"
t.para = {{name="TeamType",t=1},{name="TTarget",t=3}}
t.hand = TeamModel.CreateTeam
t.pb = TeamRpc_pb.TeamRpcCreateTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "DissmissTeam"
t.para = {}
t.hand = TeamModel.DissmissTeam
t.pb = TeamRpc_pb.TeamRpcDissmissTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "KickMember"
t.para = {{name="KickMemberRoleId",t=1}}
t.hand = TeamModel.KickMember
t.pb = TeamRpc_pb.TeamRpcKickMemberAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "SurroundingTeam"
t.para = {{name="TargetGroupId",t=1},{name="TargetGroup",t=1}}
t.hand = TeamModel.SurroundingTeam
t.pb = TeamRpc_pb.TeamRpcSurroundingTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ApplyTeam"
t.para = {{name="TeamId",t=1}}
t.hand = TeamModel.ApplyTeam
t.pb = TeamRpc_pb.TeamRpcApplyTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "AgreeApplicant"
t.para = {{name="RoleId",t=1}}
t.hand = TeamModel.AgreeApplicant
t.pb = TeamRpc_pb.TeamRpcAgreeApplicantAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "FollowTeamLeader"
t.para = {{name="FollowTeamLeader",t=1}}
t.hand = TeamModel.FollowTeamLeader
t.pb = TeamRpc_pb.TeamRpcFollowTeamLeaderAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "SummonMember"
t.para = {}
t.hand = TeamModel.SummonMember
t.pb = TeamRpc_pb.TeamRpcSummonMemberAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ChangeTeamTarget"
t.para = {{name="Target",t=3}}
t.hand = TeamModel.ChangeTeamTarget
t.pb = TeamRpc_pb.TeamRpcChangeTeamTargetAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ChangTeamType"
t.para = {{name="TeamType",t=1}}
t.hand = TeamModel.ChangTeamType
t.pb = TeamRpc_pb.TeamRpcChangTeamTypeAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "InviteTeamMember"
t.para = {{name="RoleId",t=1}}
t.hand = TeamModel.InviteTeamMember
t.pb = TeamRpc_pb.TeamRpcInviteTeamMemberAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "AgreeJoinTeam"
t.para = {{name="TeamId",t=1},{name="IsLeader",t=1}}
t.hand = TeamModel.AgreeJoinTeam
t.pb = TeamRpc_pb.TeamRpcAgreeJoinTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "RefuseMember"
t.para = {{name="RoleId",t=1}}
t.hand = TeamModel.RefuseMember
t.pb = TeamRpc_pb.TeamRpcRefuseMemberAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ClearApplyList"
t.para = {}
t.hand = TeamModel.ClearApplyList
t.pb = TeamRpc_pb.TeamRpcClearApplyListAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "NoTeamInvite"
t.para = {{name="TeamType",t=1},{name="TTarget",t=3},{name="InviteRoleId",t=1}}
t.hand = TeamModel.NoTeamInvite
t.pb = TeamRpc_pb.TeamRpcNoTeamInviteAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "RejectInvite"
t.para = {{name="RoleId",t=1},{name="Name",t=2}}
t.hand = TeamModel.RejectInvite
t.pb = TeamRpc_pb.TeamRpcRejectInviteAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "HangeUpFollow"
t.para = {}
t.hand = TeamModel.HangeUpFollow
t.pb = TeamRpc_pb.TeamRpcHangeUpFollowAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "GoOnFollow"
t.para = {}
t.hand = TeamModel.GoOnFollow
t.pb = TeamRpc_pb.TeamRpcGoOnFollowAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "RequestNoTeamMemberList"
t.para = {{name="RequestType",t=1}}
t.hand = TeamModel.RequestNoTeamMemberList
t.pb = TeamRpc_pb.TeamRpcRequestNoTeamMemberListAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "EnterLeaderScene"
t.para = {}
t.hand = TeamModel.EnterLeaderScene
t.pb = TeamRpc_pb.TeamRpcEnterLeaderSceneAsk()
table.insert(askList.Team,t)

--]]

