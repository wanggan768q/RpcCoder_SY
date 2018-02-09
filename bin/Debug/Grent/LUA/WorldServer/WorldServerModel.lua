--将变量写入下方
local ModuleId = 8;
local RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST = 851
local RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST = 852
local RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST = 853
local RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST = 854
local RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST = 855
local RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST = 856
local RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST = 857
local RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST = 858
local RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST = 859
local RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST = 860
local RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST = 861
local RPC_CODE_WORLDSERVER_LOGIN_REQUEST = 862
local RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST = 863
local RPC_CODE_WORLDSERVER_LOGOUT_REQUEST = 864
local RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST = 865
local RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST = 866
local RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST = 867



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/WorldServerRpc_pb")
local  WorldServerRpc_pb = WorldServerRpc_pb
module("WorldServerModel")





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
	self.rpc_pb = WorldServerRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function ChangeScene(self,RoleId,CurSceneId,TargetSceneId,MemId,SceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcChangeSceneAsk()
	PB.RoleId = RoleId
	PB.CurSceneId = CurSceneId
	PB.TargetSceneId = TargetSceneId
	PB.MemId = MemId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcChangeSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function EnterScene(self,RoleId,SceneId,MemId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcEnterSceneAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	PB.MemId = MemId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcEnterSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CreateDungeon(self,RoleId,TargetSceneId,MemId,DungeonConfigId,CurSceneId,Result,RoleIds,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcCreateDungeonAsk()
	PB.RoleId = RoleId
	PB.TargetSceneId = TargetSceneId
	PB.MemId = MemId
	PB.DungeonConfigId = DungeonConfigId
	PB.CurSceneId = CurSceneId
	PB.Result = Result
	for i,v in ipairs(RoleIds) do
		table.insert(PB.RoleIds,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CreateTeam(self,TeamType,TeamMember,Result,Team,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcCreateTeamAsk()
	PB.TeamType = TeamType
	PB.TeamMember = TeamMember
	PB.Result = Result
	PB.Team = Team
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcCreateTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function JoinTeam(self,TeamId,Result,TeamMember,Team,TeamType,MemId,SceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcJoinTeamAsk()
	PB.TeamId = TeamId
	PB.Result = Result
	PB.TeamMember = TeamMember
	PB.Team = Team
	PB.TeamType = TeamType
	PB.MemId = MemId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcJoinTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function LeaveTeam(self,TeamId,RoleId,MemId,SceneId,NewLeaderRoleId,Result,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcLeaveTeamAsk()
	PB.TeamId = TeamId
	PB.RoleId = RoleId
	PB.MemId = MemId
	PB.SceneId = SceneId
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcLeaveTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function AppointTeamLeader(self,NewLeaderRoleId,MemId,SceneId,CurLeaderRoleId,TeamId,Result,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcAppointTeamLeaderAsk()
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.MemId = MemId
	PB.SceneId = SceneId
	PB.CurLeaderRoleId = CurLeaderRoleId
	PB.TeamId = TeamId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function DismissTeam(self,SceneId,MemId,RoleId,TeamId,Result,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcDismissTeamAsk()
	PB.SceneId = SceneId
	PB.MemId = MemId
	PB.RoleId = RoleId
	PB.TeamId = TeamId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcDismissTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function KickMember(self,KickMemberRoleId,MemId,SceneId,TeamId,LeaderRoleId,Result,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcKickMemberAsk()
	PB.KickMemberRoleId = KickMemberRoleId
	PB.MemId = MemId
	PB.SceneId = SceneId
	PB.TeamId = TeamId
	PB.LeaderRoleId = LeaderRoleId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcKickMemberReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ApplyTeam(self,TeamId,Result,TeamMember,MemId,SceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcApplyTeamAsk()
	PB.TeamId = TeamId
	PB.Result = Result
	PB.TeamMember = TeamMember
	PB.MemId = MemId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcApplyTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self)
end
function AgreeTeamApplicant(self,RoleId,LeaderRoleId,Result,MemId,SceneId,Team,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcAgreeTeamApplicantAsk()
	PB.RoleId = RoleId
	PB.LeaderRoleId = LeaderRoleId
	PB.Result = Result
	PB.MemId = MemId
	PB.SceneId = SceneId
	PB.Team = Team
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcAgreeTeamApplicantReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Login(self,Team,MemId,SceneId,RoleInfo,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcLoginAsk()
	PB.Team = Team
	PB.MemId = MemId
	PB.SceneId = SceneId
	PB.RoleInfo = RoleInfo
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcLoginReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_LOGIN_REQUEST, pb_data, callback)
	showNetTip(self)
end
function UpdateRoleInfo(self,RoleInfo,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcUpdateRoleInfoAsk()
	PB.RoleInfo = RoleInfo
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcUpdateRoleInfoReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Logout(self,RoleInfo,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcLogoutAsk()
	PB.RoleInfo = RoleInfo
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcLogoutReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_LOGOUT_REQUEST, pb_data, callback)
	showNetTip(self)
end
function CreateDungeonNotify(self,CurSceneId,RoleId,MemId,TargetSceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcCreateDungeonNotifyAsk()
	PB.CurSceneId = CurSceneId
	PB.RoleId = RoleId
	PB.MemId = MemId
	PB.TargetSceneId = TargetSceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcCreateDungeonNotifyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ExitDungeon(self,RoleId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcExitDungeonAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcExitDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ReleaseDungeon(self,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcReleaseDungeonAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcReleaseDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST, pb_data, callback)
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
askList.WorldServer = {}

local t = {}
t.name = "ChangeScene"
t.para = {{name="RoleId",t=1},{name="CurSceneId",t=1},{name="TargetSceneId",t=1},{name="MemId",t=1},{name="SceneId",t=1}}
t.hand = WorldServerModel.ChangeScene
t.pb = WorldServerRpc_pb.WorldServerRpcChangeSceneAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "EnterScene"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1},{name="MemId",t=1}}
t.hand = WorldServerModel.EnterScene
t.pb = WorldServerRpc_pb.WorldServerRpcEnterSceneAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "CreateDungeon"
t.para = {{name="RoleId",t=1},{name="TargetSceneId",t=1},{name="MemId",t=1},{name="DungeonConfigId",t=1},{name="CurSceneId",t=1},{name="Result",t=1},{name="RoleIds",t=1}}
t.hand = WorldServerModel.CreateDungeon
t.pb = WorldServerRpc_pb.WorldServerRpcCreateDungeonAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "CreateTeam"
t.para = {{name="TeamType",t=1},{name="TeamMember",t=3},{name="Result",t=1},{name="Team",t=3}}
t.hand = WorldServerModel.CreateTeam
t.pb = WorldServerRpc_pb.WorldServerRpcCreateTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "JoinTeam"
t.para = {{name="TeamId",t=1},{name="Result",t=1},{name="TeamMember",t=3},{name="Team",t=3},{name="TeamType",t=1},{name="MemId",t=1},{name="SceneId",t=1}}
t.hand = WorldServerModel.JoinTeam
t.pb = WorldServerRpc_pb.WorldServerRpcJoinTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "LeaveTeam"
t.para = {{name="TeamId",t=1},{name="RoleId",t=1},{name="MemId",t=1},{name="SceneId",t=1},{name="NewLeaderRoleId",t=1},{name="Result",t=1}}
t.hand = WorldServerModel.LeaveTeam
t.pb = WorldServerRpc_pb.WorldServerRpcLeaveTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "AppointTeamLeader"
t.para = {{name="NewLeaderRoleId",t=1},{name="MemId",t=1},{name="SceneId",t=1},{name="CurLeaderRoleId",t=1},{name="TeamId",t=1},{name="Result",t=1}}
t.hand = WorldServerModel.AppointTeamLeader
t.pb = WorldServerRpc_pb.WorldServerRpcAppointTeamLeaderAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "DismissTeam"
t.para = {{name="SceneId",t=1},{name="MemId",t=1},{name="RoleId",t=1},{name="TeamId",t=1},{name="Result",t=1}}
t.hand = WorldServerModel.DismissTeam
t.pb = WorldServerRpc_pb.WorldServerRpcDismissTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "KickMember"
t.para = {{name="KickMemberRoleId",t=1},{name="MemId",t=1},{name="SceneId",t=1},{name="TeamId",t=1},{name="LeaderRoleId",t=1},{name="Result",t=1}}
t.hand = WorldServerModel.KickMember
t.pb = WorldServerRpc_pb.WorldServerRpcKickMemberAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "ApplyTeam"
t.para = {{name="TeamId",t=1},{name="Result",t=1},{name="TeamMember",t=3},{name="MemId",t=1},{name="SceneId",t=1}}
t.hand = WorldServerModel.ApplyTeam
t.pb = WorldServerRpc_pb.WorldServerRpcApplyTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "AgreeTeamApplicant"
t.para = {{name="RoleId",t=1},{name="LeaderRoleId",t=1},{name="Result",t=1},{name="MemId",t=1},{name="SceneId",t=1},{name="Team",t=3}}
t.hand = WorldServerModel.AgreeTeamApplicant
t.pb = WorldServerRpc_pb.WorldServerRpcAgreeTeamApplicantAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "Login"
t.para = {{name="Team",t=3},{name="MemId",t=1},{name="SceneId",t=1},{name="RoleInfo",t=3}}
t.hand = WorldServerModel.Login
t.pb = WorldServerRpc_pb.WorldServerRpcLoginAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "UpdateRoleInfo"
t.para = {{name="RoleInfo",t=3}}
t.hand = WorldServerModel.UpdateRoleInfo
t.pb = WorldServerRpc_pb.WorldServerRpcUpdateRoleInfoAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "Logout"
t.para = {{name="RoleInfo",t=3}}
t.hand = WorldServerModel.Logout
t.pb = WorldServerRpc_pb.WorldServerRpcLogoutAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "CreateDungeonNotify"
t.para = {{name="CurSceneId",t=1},{name="RoleId",t=1},{name="MemId",t=1},{name="TargetSceneId",t=1}}
t.hand = WorldServerModel.CreateDungeonNotify
t.pb = WorldServerRpc_pb.WorldServerRpcCreateDungeonNotifyAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "ExitDungeon"
t.para = {{name="RoleId",t=1}}
t.hand = WorldServerModel.ExitDungeon
t.pb = WorldServerRpc_pb.WorldServerRpcExitDungeonAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "ReleaseDungeon"
t.para = {}
t.hand = WorldServerModel.ReleaseDungeon
t.pb = WorldServerRpc_pb.WorldServerRpcReleaseDungeonAsk()
table.insert(askList.WorldServer,t)

--]]

