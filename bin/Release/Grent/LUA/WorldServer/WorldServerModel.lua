--将变量写入下方
local ModuleId = 8;
local RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST = 851
local RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST = 852
local RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST = 853
local RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST = 854
local RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST = 855
local RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST = 856
local RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST = 857
local RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST = 858
local RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST = 859
local RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST = 860
local RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST = 861
local RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST = 862





require("app.WorldServer.WorldServerRpc_pb")

WorldServerModel = class("WorldServerModel",BaseModel)

function WorldServerModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=WorldServerModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function WorldServerModel:ctor()
	WorldServerModel.super.ctor(self)
	self.rpc_pb = WorldServerRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function WorldServerModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function UpdateRoleInfo(self,RoleInfo,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcUpdateRoleInfoAsk()
	PB.RoleInfo.RoleId = RoleInfo.RoleId
	PB.RoleInfo.Level = RoleInfo.Level
	PB.RoleInfo.Location = RoleInfo.Location
	PB.RoleInfo.Guildguid = RoleInfo.Guildguid
	PB.RoleInfo.PlayerMatchData = RoleInfo.PlayerMatchData
	PB.RoleInfo.RoleName = RoleInfo.RoleName
	PB.RoleInfo.ConfigID = RoleInfo.ConfigID
	PB.RoleInfo.TreasureCount = RoleInfo.TreasureCount
	PB.RoleInfo.TreasureLevel = RoleInfo.TreasureLevel
	PB.RoleInfo.PetConfigID = RoleInfo.PetConfigID
	PB.RoleInfo.PetLevel = RoleInfo.PetLevel
	PB.RoleInfo.PvP3v3WinCount = RoleInfo.PvP3v3WinCount
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST",RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcUpdateRoleInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => UpdateRoleInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST",RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST)
end
function CreateDungeonNotify(self,CurSceneId,RoleId,TargetSceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcCreateDungeonNotifyAsk()
	PB.CurSceneId = CurSceneId
	PB.RoleId = RoleId
	PB.TargetSceneId = TargetSceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST",RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcCreateDungeonNotifyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => CreateDungeonNotify ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST",RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST)
end
function ExitDungeon(self,RoleId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcExitDungeonAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST",RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcExitDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => ExitDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST",RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST)
end
function UpdateTeamInfo(self,TeamMember,RoleId,Team,TeamType,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcUpdateTeamInfoAsk()
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
	PB.RoleId = RoleId
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	PB.TeamType = TeamType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST",RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcUpdateTeamInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => UpdateTeamInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST",RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST)
end
function PlayCgTeam(self,PlayRoleId,CgId,State,RoleId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcPlayCgTeamAsk()
	PB.PlayRoleId = PlayRoleId
	PB.CgId = CgId
	PB.State = State
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST",RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcPlayCgTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => PlayCgTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST",RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST)
end
function SendMail(self,Mail,GlobalMailID,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcSendMailAsk()
	PB.Mail.Mail_type = Mail.Mail_type
	PB.Mail.Mail_id = Mail.Mail_id
	PB.Mail.IsRead = Mail.IsRead
	PB.Mail.IsGet = Mail.IsGet
	PB.Mail.Title = Mail.Title
	PB.Mail.Salutation = Mail.Salutation
	PB.Mail.Content = Mail.Content
	PB.Mail.Sender_name = Mail.Sender_name
	for i = 1, #Mail.ItemList do
		table.insert( PB.Mail.ItemList,Mail.ItemList[i] )
	end
	PB.Mail.Sender_id = Mail.Sender_id
	PB.Mail.Start_time = Mail.Start_time
	PB.Mail.Expire_time = Mail.Expire_time
	PB.Mail.Receiver_id = Mail.Receiver_id
	PB.GlobalMailID = GlobalMailID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST",RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcSendMailReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => SendMail ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST",RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST)
end
function ChangeTeamType(self,TeamId,RoleId,Result,TeamType,Target,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcChangeTeamTypeAsk()
	PB.TeamId = TeamId
	PB.RoleId = RoleId
	PB.Result = Result
	PB.TeamType = TeamType
	PB.Target.Id = Target.Id
	PB.Target.MinLevel = Target.MinLevel
	PB.Target.MaxLevel = Target.MaxLevel
	for i = 1, #Target.Function do
		table.insert( PB.Target.Function,Target.Function[i] )
	end
	PB.Target.TargetType = Target.TargetType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST",RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcChangeTeamTypeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => ChangeTeamType ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST",RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST)
end
function AutoMatch(self,MemberInfo,MatchInfo,Result,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcAutoMatchAsk()
	PB.MemberInfo.RoleId = MemberInfo.RoleId
	PB.MemberInfo.Level = MemberInfo.Level
	PB.MemberInfo.Name = MemberInfo.Name
	PB.MemberInfo.ConfigId = MemberInfo.ConfigId
	PB.MemberInfo.Hp = MemberInfo.Hp
	PB.MemberInfo.Status = MemberInfo.Status
	PB.MemberInfo.MaxHp = MemberInfo.MaxHp
	PB.MemberInfo.Location = MemberInfo.Location
	PB.MemberInfo.ProfessionId = MemberInfo.ProfessionId
	PB.MemberInfo.OnLine = MemberInfo.OnLine
	PB.MemberInfo.FollowTeam = MemberInfo.FollowTeam
	for i = 1, #MemberInfo.BuffIdList do
		table.insert( PB.MemberInfo.BuffIdList,MemberInfo.BuffIdList[i] )
	end
	PB.MatchInfo.MatchType = MatchInfo.MatchType
	PB.MatchInfo.Elo = MatchInfo.Elo
	PB.MatchInfo.Auto = MatchInfo.Auto
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST",RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcAutoMatchReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => AutoMatch ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST",RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST)
end
function CancelMatch(self,RoleId,Result,IsNotify,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcCancelMatchAsk()
	PB.RoleId = RoleId
	PB.Result = Result
	PB.IsNotify = IsNotify
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST",RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcCancelMatchReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => CancelMatch ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST",RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST)
end
function LoginGameServer(self,Team,RoleInfo,Location,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcLoginGameServerAsk()
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	PB.RoleInfo.RoleId = RoleInfo.RoleId
	PB.RoleInfo.Level = RoleInfo.Level
	PB.RoleInfo.Location = RoleInfo.Location
	PB.RoleInfo.Guildguid = RoleInfo.Guildguid
	PB.RoleInfo.PlayerMatchData = RoleInfo.PlayerMatchData
	PB.RoleInfo.RoleName = RoleInfo.RoleName
	PB.RoleInfo.ConfigID = RoleInfo.ConfigID
	PB.RoleInfo.TreasureCount = RoleInfo.TreasureCount
	PB.RoleInfo.TreasureLevel = RoleInfo.TreasureLevel
	PB.RoleInfo.PetConfigID = RoleInfo.PetConfigID
	PB.RoleInfo.PetLevel = RoleInfo.PetLevel
	PB.RoleInfo.PvP3v3WinCount = RoleInfo.PvP3v3WinCount
	PB.Location.SceneId = Location.SceneId
	PB.Location.Pos = Location.Pos
	PB.Location.MapId = Location.MapId
	PB.Location.DungeonConfigId = Location.DungeonConfigId
	PB.Location.LineId = Location.LineId
	PB.Location.SceneConfigId = Location.SceneConfigId
	PB.Location.MirrorId = Location.MirrorId
	PB.Location.ServerId = Location.ServerId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST",RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcLoginGameServerReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => LoginGameServer ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST",RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST)
end
function LogoutGameServer(self,Result,RoleInfo,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcLogoutGameServerAsk()
	PB.Result = Result
	PB.RoleInfo.RoleId = RoleInfo.RoleId
	PB.RoleInfo.Level = RoleInfo.Level
	PB.RoleInfo.Location = RoleInfo.Location
	PB.RoleInfo.Guildguid = RoleInfo.Guildguid
	PB.RoleInfo.PlayerMatchData = RoleInfo.PlayerMatchData
	PB.RoleInfo.RoleName = RoleInfo.RoleName
	PB.RoleInfo.ConfigID = RoleInfo.ConfigID
	PB.RoleInfo.TreasureCount = RoleInfo.TreasureCount
	PB.RoleInfo.TreasureLevel = RoleInfo.TreasureLevel
	PB.RoleInfo.PetConfigID = RoleInfo.PetConfigID
	PB.RoleInfo.PetLevel = RoleInfo.PetLevel
	PB.RoleInfo.PvP3v3WinCount = RoleInfo.PvP3v3WinCount
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST",RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcLogoutGameServerReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => LogoutGameServer ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST",RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST)
end
function GetPlayerInfo(self,Player_guid,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcGetPlayerInfoAsk()
	PB.Player_guid = Player_guid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST",RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcGetPlayerInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldServer => GetPlayerInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST",RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST)
end








askList.WorldServer = {}

local t = {}
t.name = "UpdateRoleInfo"
t.para = {{name="RoleInfo",t=3}}
t.hand = WorldServerModel.UpdateRoleInfo
t.pb = WorldServerRpc_pb.WorldServerRpcUpdateRoleInfoAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "CreateDungeonNotify"
t.para = {{name="CurSceneId",t=1},{name="RoleId",t=1},{name="TargetSceneId",t=1}}
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
t.name = "UpdateTeamInfo"
t.para = {{name="TeamMember",t=3},{name="RoleId",t=1},{name="Team",t=3},{name="TeamType",t=1}}
t.hand = WorldServerModel.UpdateTeamInfo
t.pb = WorldServerRpc_pb.WorldServerRpcUpdateTeamInfoAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "PlayCgTeam"
t.para = {{name="PlayRoleId",t=1},{name="CgId",t=1},{name="State",t=1},{name="RoleId",t=1}}
t.hand = WorldServerModel.PlayCgTeam
t.pb = WorldServerRpc_pb.WorldServerRpcPlayCgTeamAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "SendMail"
t.para = {{name="Mail",t=3},{name="GlobalMailID",t=1}}
t.hand = WorldServerModel.SendMail
t.pb = WorldServerRpc_pb.WorldServerRpcSendMailAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "ChangeTeamType"
t.para = {{name="TeamId",t=1},{name="RoleId",t=1},{name="Result",t=1},{name="TeamType",t=1},{name="Target",t=3}}
t.hand = WorldServerModel.ChangeTeamType
t.pb = WorldServerRpc_pb.WorldServerRpcChangeTeamTypeAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "AutoMatch"
t.para = {{name="MemberInfo",t=3},{name="MatchInfo",t=3},{name="Result",t=1}}
t.hand = WorldServerModel.AutoMatch
t.pb = WorldServerRpc_pb.WorldServerRpcAutoMatchAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "CancelMatch"
t.para = {{name="RoleId",t=1},{name="Result",t=1},{name="IsNotify",t=1}}
t.hand = WorldServerModel.CancelMatch
t.pb = WorldServerRpc_pb.WorldServerRpcCancelMatchAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "LoginGameServer"
t.para = {{name="Team",t=3},{name="RoleInfo",t=3},{name="Location",t=3}}
t.hand = WorldServerModel.LoginGameServer
t.pb = WorldServerRpc_pb.WorldServerRpcLoginGameServerAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "LogoutGameServer"
t.para = {{name="Result",t=1},{name="RoleInfo",t=3}}
t.hand = WorldServerModel.LogoutGameServer
t.pb = WorldServerRpc_pb.WorldServerRpcLogoutGameServerAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "GetPlayerInfo"
t.para = {{name="Player_guid",t=1}}
t.hand = WorldServerModel.GetPlayerInfo
t.pb = WorldServerRpc_pb.WorldServerRpcGetPlayerInfoAsk()
table.insert(askList.WorldServer,t)

