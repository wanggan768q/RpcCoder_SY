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





require("app.Team.TeamRpc_pb")

TeamModel = class("TeamModel",BaseModel)

function TeamModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TeamModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TeamModel:ctor()
	TeamModel.super.ctor(self)
	self.rpc_pb = TeamRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
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

  


end

-- 更新数据
function TeamModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function LeaveTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcLeaveTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_LEAVETEAM_REQUEST",RPC_CODE_TEAM_LEAVETEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcLeaveTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => LeaveTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_LEAVETEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_LEAVETEAM_REQUEST",RPC_CODE_TEAM_LEAVETEAM_REQUEST)
end
function AppointTeamLeader(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAppointTeamLeaderAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST",RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => AppointTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST",RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST)
end
function CreateTeam(self,TeamType,TTarget,_hanlder)
	local PB = self.rpc_pb.TeamRpcCreateTeamAsk()
	PB.TeamType = TeamType
	PB.TTarget.Id = TTarget.Id
	PB.TTarget.MinLevel = TTarget.MinLevel
	PB.TTarget.MaxLevel = TTarget.MaxLevel
	for i = 1, #TTarget.Function do
		table.insert( PB.TTarget.Function,TTarget.Function[i] )
	end
	PB.TTarget.TargetType = TTarget.TargetType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_CREATETEAM_REQUEST",RPC_CODE_TEAM_CREATETEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcCreateTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => CreateTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CREATETEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_CREATETEAM_REQUEST",RPC_CODE_TEAM_CREATETEAM_REQUEST)
end
function DissmissTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcDissmissTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_DISSMISSTEAM_REQUEST",RPC_CODE_TEAM_DISSMISSTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => DissmissTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_DISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_DISSMISSTEAM_REQUEST",RPC_CODE_TEAM_DISSMISSTEAM_REQUEST)
end
function KickMember(self,KickMemberRoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcKickMemberAsk()
	PB.KickMemberRoleId = KickMemberRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_KICKMEMBER_REQUEST",RPC_CODE_TEAM_KICKMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcKickMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => KickMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_KICKMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_KICKMEMBER_REQUEST",RPC_CODE_TEAM_KICKMEMBER_REQUEST)
end
function SurroundingTeam(self,TargetGroupId,TargetGroup,_hanlder)
	local PB = self.rpc_pb.TeamRpcSurroundingTeamAsk()
	PB.TargetGroupId = TargetGroupId
	PB.TargetGroup = TargetGroup
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST",RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcSurroundingTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => SurroundingTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST",RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST)
end
function ApplyTeam(self,TeamId,_hanlder)
	local PB = self.rpc_pb.TeamRpcApplyTeamAsk()
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_APPLYTEAM_REQUEST",RPC_CODE_TEAM_APPLYTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcApplyTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => ApplyTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_APPLYTEAM_REQUEST",RPC_CODE_TEAM_APPLYTEAM_REQUEST)
end
function AgreeApplicant(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAgreeApplicantAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST",RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAgreeApplicantReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => AgreeApplicant ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST",RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST)
end
function FollowTeamLeader(self,FollowTeamLeader,_hanlder)
	local PB = self.rpc_pb.TeamRpcFollowTeamLeaderAsk()
	PB.FollowTeamLeader = FollowTeamLeader
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST",RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcFollowTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => FollowTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST",RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST)
end
function SummonMember(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcSummonMemberAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_SUMMONMEMBER_REQUEST",RPC_CODE_TEAM_SUMMONMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcSummonMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => SummonMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_SUMMONMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_SUMMONMEMBER_REQUEST",RPC_CODE_TEAM_SUMMONMEMBER_REQUEST)
end
function ChangeTeamTarget(self,TargetType,Id,MinLevel,MaxLevel,Function,_hanlder)
	local PB = self.rpc_pb.TeamRpcChangeTeamTargetAsk()
	PB.TargetType = TargetType
	PB.Id = Id
	PB.MinLevel = MinLevel
	PB.MaxLevel = MaxLevel
	for i,v in ipairs(Function) do
		table.insert(PB.Function,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST",RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcChangeTeamTargetReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => ChangeTeamTarget ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST",RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST)
end
function ChangTeamType(self,TeamType,_hanlder)
	local PB = self.rpc_pb.TeamRpcChangTeamTypeAsk()
	PB.TeamType = TeamType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST",RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcChangTeamTypeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => ChangTeamType ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST",RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST)
end
function InviteTeamMember(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcInviteTeamMemberAsk()
	for i,v in ipairs(RoleId) do
		table.insert(PB.RoleId,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST",RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcInviteTeamMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => InviteTeamMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST",RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST)
end
function AgreeJoinTeam(self,TeamId,IsLeader,_hanlder)
	local PB = self.rpc_pb.TeamRpcAgreeJoinTeamAsk()
	PB.TeamId = TeamId
	PB.IsLeader = IsLeader
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST",RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAgreeJoinTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => AgreeJoinTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST",RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST)
end
function RefuseMember(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcRefuseMemberAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_REFUSEMEMBER_REQUEST",RPC_CODE_TEAM_REFUSEMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcRefuseMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => RefuseMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_REFUSEMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_REFUSEMEMBER_REQUEST",RPC_CODE_TEAM_REFUSEMEMBER_REQUEST)
end
function ClearApplyList(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcClearApplyListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST",RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcClearApplyListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => ClearApplyList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST",RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST)
end
function NoTeamInvite(self,TeamType,TTarget,InviteRoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcNoTeamInviteAsk()
	PB.TeamType = TeamType
	PB.TTarget.Id = TTarget.Id
	PB.TTarget.MinLevel = TTarget.MinLevel
	PB.TTarget.MaxLevel = TTarget.MaxLevel
	for i = 1, #TTarget.Function do
		table.insert( PB.TTarget.Function,TTarget.Function[i] )
	end
	PB.TTarget.TargetType = TTarget.TargetType
	PB.InviteRoleId = InviteRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_NOTEAMINVITE_REQUEST",RPC_CODE_TEAM_NOTEAMINVITE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcNoTeamInviteReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => NoTeamInvite ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_NOTEAMINVITE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_NOTEAMINVITE_REQUEST",RPC_CODE_TEAM_NOTEAMINVITE_REQUEST)
end
function RejectInvite(self,RoleId,Name,_hanlder)
	local PB = self.rpc_pb.TeamRpcRejectInviteAsk()
	PB.RoleId = RoleId
	PB.Name = Name
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_TEAM_REJECTINVITE_REQUEST",RPC_CODE_TEAM_REJECTINVITE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcRejectInviteReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Team => RejectInvite ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_REJECTINVITE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_TEAM_REJECTINVITE_REQUEST",RPC_CODE_TEAM_REJECTINVITE_REQUEST)
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
t.para = {{name="TargetType",t=1},{name="Id",t=1},{name="MinLevel",t=1},{name="MaxLevel",t=1},{name="Function",t=1}}
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

