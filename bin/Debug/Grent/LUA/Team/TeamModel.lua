--将变量写入下方
local ModuleId = 10;
local RPC_CODE_TEAM_JOINTEAM_REQUEST = 1051
local RPC_CODE_TEAM_LEAVETEAM_REQUEST = 1052
local RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST = 1053
local RPC_CODE_TEAM_CREATETEAM_REQUEST = 1054
local RPC_CODE_TEAM_DISSMISSTEAM_REQUEST = 1055
local RPC_CODE_TEAM_NEWLEADER_NOTIFY = 1056;
local RPC_CODE_TEAM_KICKMEMBER_REQUEST = 1057
local RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY = 1058;
local RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY = 1059;
local RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY = 1060;
local RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY = 1061;
local RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST = 1062
local RPC_CODE_TEAM_APPLYTEAM_REQUEST = 1063
local RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY = 1064;
local RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST = 1065
local RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY = 1066;
local RPC_CODE_TEAM_TEAMINFO_NOTIFY = 1067;
local RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY = 1068;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
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

local function showNetTip(self)

end

local function hideNetTip(self)

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

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function JoinTeam(self,TeamId,TeamType,Team,TeamMember,_hanlder)
	local PB = self.rpc_pb.TeamRpcJoinTeamAsk()
	PB.TeamId = TeamId
	PB.TeamType = TeamType
	PB.Team = Team
	PB.TeamMember = TeamMember
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcJoinTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_JOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function LeaveTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcLeaveTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcLeaveTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_LEAVETEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function AppointTeamLeader(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAppointTeamLeaderAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CreateTeam(self,TeamType,_hanlder)
	local PB = self.rpc_pb.TeamRpcCreateTeamAsk()
	PB.TeamType = TeamType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcCreateTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CREATETEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function DissmissTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcDissmissTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_DISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function KickMember(self,KickMemberRoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcKickMemberAsk()
	PB.KickMemberRoleId = KickMemberRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcKickMemberReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_KICKMEMBER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function SurroundingTeam(self,_hanlder)
	local PB = self.rpc_pb.TeamRpcSurroundingTeamAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcSurroundingTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ApplyTeam(self,TeamId,_hanlder)
	local PB = self.rpc_pb.TeamRpcApplyTeamAsk()
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcApplyTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function AgreeApplicant(self,RoleId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAgreeApplicantAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAgreeApplicantReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self)
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
t.name = "JoinTeam"
t.para = {{name="TeamId",t=1},{name="TeamType",t=1},{name="Team",t=3},{name="TeamMember",t=3}}
t.hand = TeamModel.JoinTeam
t.pb = TeamRpc_pb.TeamRpcJoinTeamAsk()
table.insert(askList.Team,t)

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
t.para = {{name="TeamType",t=1}}
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
t.para = {}
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

--]]

