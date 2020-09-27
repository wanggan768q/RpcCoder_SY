-- WGModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 11;
local RPC_CODE_WG_INFORMJOINTEAM_REQUEST = 1151
local RPC_CODE_WG_INFORMLEAVE_REQUEST = 1152
local RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST = 1153
local RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST = 1154
local RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST = 1155
local RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST = 1156
local RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST = 1157
local RPC_CODE_WG_INFORMLOGIN_REQUEST = 1158



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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = WGRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function InformJoinTeam(self,Member,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcInformJoinTeamAsk()
	PB.Member.RoleId = Member.RoleId
	PB.Member.Level = Member.Level
	PB.Member.Name = Member.Name
	PB.Member.ConfigId = Member.ConfigId
	PB.Member.Hp = Member.Hp
	PB.Member.Status = Member.Status
	PB.Member.MaxHp = Member.MaxHp
	PB.Member.Location = Member.Location
	PB.Member.ProfessionId = Member.ProfessionId
	PB.Member.OnLine = Member.OnLine
	PB.Member.FollowTeam = Member.FollowTeam
	for i = 1, #Member.BuffIdList do
		table.insert( PB.Member.BuffIdList,Member.BuffIdList[i] )
	end
	PB.Member.Robot = Member.Robot
	PB.Member.Camp = Member.Camp
	PB.Member.GuildGuid = Member.GuildGuid
	PB.Member.BattleScore = Member.BattleScore
	PB.Member.Treasureinfo = Member.Treasureinfo
	PB.Member.GhostGuid = Member.GhostGuid
	PB.Member.Occupation = Member.Occupation
	PB.Member.PinchData = Member.PinchData
	PB.Member.WillLeaveTime = Member.WillLeaveTime
	PB.Member.LastLogoutTime = Member.LastLogoutTime
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMJOINTEAM_REQUEST',RPC_CODE_WG_INFORMJOINTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformJoinTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformJoinTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMJOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMJOINTEAM_REQUEST',RPC_CODE_WG_INFORMJOINTEAM_REQUEST)
end
function InformLeave(self,RoleId,NewLeaderRoleId,Result,_hanlder)
	local PB = self.rpc_pb.WGRpcInformLeaveAsk()
	PB.RoleId = RoleId
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMLEAVE_REQUEST',RPC_CODE_WG_INFORMLEAVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLeaveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformLeave ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLEAVE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMLEAVE_REQUEST',RPC_CODE_WG_INFORMLEAVE_REQUEST)
end
function InformAppointTeamLeader(self,Result,NewLeaderRoleId,OldLeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformAppointTeamLeaderAsk()
	PB.Result = Result
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.OldLeaderRoleId = OldLeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST',RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformAppointTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST',RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST)
end
function InformKickTeamMember(self,Result,KickedMemberRoleId,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformKickTeamMemberAsk()
	PB.Result = Result
	PB.KickedMemberRoleId = KickedMemberRoleId
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST',RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformKickTeamMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformKickTeamMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST',RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST)
end
function InformDissmissTeam(self,Result,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformDissmissTeamAsk()
	PB.Result = Result
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST',RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformDissmissTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST',RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST)
end
function InformApplyTeam(self,TeamMember,Result,TeamId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformApplyTeamAsk()
	PB.TeamMember.RoleId = TeamMember.RoleId
	PB.TeamMember.Level = TeamMember.Level
	PB.TeamMember.Name = TeamMember.Name
	PB.TeamMember.ConfigId = TeamMember.ConfigId
	PB.TeamMember.Hp = TeamMember.Hp
	PB.TeamMember.Status = TeamMember.Status
	PB.TeamMember.MaxHp = TeamMember.MaxHp
	PB.TeamMember.Location = TeamMember.Location
	PB.TeamMember.ProfessionId = TeamMember.ProfessionId
	PB.TeamMember.OnLine = TeamMember.OnLine
	PB.TeamMember.FollowTeam = TeamMember.FollowTeam
	for i = 1, #TeamMember.BuffIdList do
		table.insert( PB.TeamMember.BuffIdList,TeamMember.BuffIdList[i] )
	end
	PB.TeamMember.Robot = TeamMember.Robot
	PB.TeamMember.Camp = TeamMember.Camp
	PB.TeamMember.GuildGuid = TeamMember.GuildGuid
	PB.TeamMember.BattleScore = TeamMember.BattleScore
	PB.TeamMember.Treasureinfo = TeamMember.Treasureinfo
	PB.TeamMember.GhostGuid = TeamMember.GhostGuid
	PB.TeamMember.Occupation = TeamMember.Occupation
	PB.TeamMember.PinchData = TeamMember.PinchData
	PB.TeamMember.WillLeaveTime = TeamMember.WillLeaveTime
	PB.TeamMember.LastLogoutTime = TeamMember.LastLogoutTime
	PB.Result = Result
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST',RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformApplyTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformApplyTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST',RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST)
end
function AgreeTeamApplicant(self,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcAgreeTeamApplicantAsk()
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST',RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcAgreeTeamApplicantReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => AgreeTeamApplicant ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST',RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST)
end
function InformLogin(self,Team,_hanlder)
	local PB = self.rpc_pb.WGRpcInformLoginAsk()
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_WG_INFORMLOGIN_REQUEST',RPC_CODE_WG_INFORMLOGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLoginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[WG => InformLogin ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLOGIN_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_WG_INFORMLOGIN_REQUEST',RPC_CODE_WG_INFORMLOGIN_REQUEST)
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

