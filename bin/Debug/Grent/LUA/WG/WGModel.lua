--将变量写入下方
local ModuleId = 11;
local RPC_CODE_WG_INFORMCREATETEAM_REQUEST = 1151
local RPC_CODE_WG_INFORMJOINTEAM_REQUEST = 1152
local RPC_CODE_WG_INFORMLEAVE_REQUEST = 1153
local RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST = 1154
local RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST = 1155
local RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST = 1156
local RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST = 1157
local RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST = 1158
local RPC_CODE_WG_INFORMLOGIN_REQUEST = 1159



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/WGRpc_pb")
local  WGRpc_pb = WGRpc_pb
module("WGModel")





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
	self.rpc_pb = WGRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function InformCreateTeam(self,Team,Result,_hanlder)
	local PB = self.rpc_pb.WGRpcInformCreateTeamAsk()
	PB.Team = Team
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformCreateTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMCREATETEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformJoinTeam(self,Member,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcInformJoinTeamAsk()
	PB.Member = Member
	PB.Team = Team
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformJoinTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMJOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformLeave(self,RoleId,NewLeaderRoleId,Result,_hanlder)
	local PB = self.rpc_pb.WGRpcInformLeaveAsk()
	PB.RoleId = RoleId
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLeaveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLEAVE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformAppointTeamLeader(self,Result,NewLeaderRoleId,OldLeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformAppointTeamLeaderAsk()
	PB.Result = Result
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.OldLeaderRoleId = OldLeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformKickTeamMember(self,Result,KickedMemberRoleId,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformKickTeamMemberAsk()
	PB.Result = Result
	PB.KickedMemberRoleId = KickedMemberRoleId
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformKickTeamMemberReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformDissmissTeam(self,Result,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformDissmissTeamAsk()
	PB.Result = Result
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformApplyTeam(self,TeamMember,Result,TeamId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformApplyTeamAsk()
	PB.TeamMember = TeamMember
	PB.Result = Result
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformApplyTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function AgreeTeamApplicant(self,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcAgreeTeamApplicantAsk()
	PB.Team = Team
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcAgreeTeamApplicantReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformLogin(self,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcInformLoginAsk()
	PB.Team = Team
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLoginReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLOGIN_REQUEST, pb_data, callback)
	showNetTip(self)
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
askList.WG = {}

local t = {}
t.name = "InformCreateTeam"
t.para = {{name="Team",t=3},{name="Result",t=1}}
t.hand = WGModel.InformCreateTeam
t.pb = WGRpc_pb.WGRpcInformCreateTeamAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformJoinTeam"
t.para = {{name="Member",t=3},{name="Team",t=3}}
t.hand = WGModel.InformJoinTeam
t.pb = WGRpc_pb.WGRpcInformJoinTeamAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformLeave"
t.para = {{name="RoleId",t=1},{name="NewLeaderRoleId",t=1},{name="Result",t=1}}
t.hand = WGModel.InformLeave
t.pb = WGRpc_pb.WGRpcInformLeaveAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformAppointTeamLeader"
t.para = {{name="Result",t=1},{name="NewLeaderRoleId",t=1},{name="OldLeaderRoleId",t=1}}
t.hand = WGModel.InformAppointTeamLeader
t.pb = WGRpc_pb.WGRpcInformAppointTeamLeaderAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformKickTeamMember"
t.para = {{name="Result",t=1},{name="KickedMemberRoleId",t=1},{name="LeaderRoleId",t=1}}
t.hand = WGModel.InformKickTeamMember
t.pb = WGRpc_pb.WGRpcInformKickTeamMemberAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformDissmissTeam"
t.para = {{name="Result",t=1},{name="LeaderRoleId",t=1}}
t.hand = WGModel.InformDissmissTeam
t.pb = WGRpc_pb.WGRpcInformDissmissTeamAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformApplyTeam"
t.para = {{name="TeamMember",t=3},{name="Result",t=1},{name="TeamId",t=1}}
t.hand = WGModel.InformApplyTeam
t.pb = WGRpc_pb.WGRpcInformApplyTeamAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "AgreeTeamApplicant"
t.para = {{name="Team",t=3}}
t.hand = WGModel.AgreeTeamApplicant
t.pb = WGRpc_pb.WGRpcAgreeTeamApplicantAsk()
table.insert(askList.WG,t)

local t = {}
t.name = "InformLogin"
t.para = {{name="Team",t=3}}
t.hand = WGModel.InformLogin
t.pb = WGRpc_pb.WGRpcInformLoginAsk()
table.insert(askList.WG,t)

--]]

