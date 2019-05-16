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





require("app.WG.WGRpc_pb")

WGModel = class("WGModel",BaseModel)

function WGModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=WGModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function WGModel:ctor()
	WGModel.super.ctor(self)
	self.rpc_pb = WGRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function WGModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
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
	for i = 1, #Team.Members do
		table.insert( PB.Team.Members,Team.Members[i] )
	end
	PB.Team.LeaderRoleId = Team.LeaderRoleId
	PB.Team.TeamId = Team.TeamId
	PB.Team.TeamType = Team.TeamType
	PB.Team.TeamTarget = Team.TeamTarget
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMJOINTEAM_REQUEST",RPC_CODE_WG_INFORMJOINTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformJoinTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformJoinTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMJOINTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMJOINTEAM_REQUEST",RPC_CODE_WG_INFORMJOINTEAM_REQUEST)
end
function InformLeave(self,RoleId,NewLeaderRoleId,Result,_hanlder)
	local PB = self.rpc_pb.WGRpcInformLeaveAsk()
	PB.RoleId = RoleId
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.Result = Result
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMLEAVE_REQUEST",RPC_CODE_WG_INFORMLEAVE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLeaveReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformLeave ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLEAVE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMLEAVE_REQUEST",RPC_CODE_WG_INFORMLEAVE_REQUEST)
end
function InformAppointTeamLeader(self,Result,NewLeaderRoleId,OldLeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformAppointTeamLeaderAsk()
	PB.Result = Result
	PB.NewLeaderRoleId = NewLeaderRoleId
	PB.OldLeaderRoleId = OldLeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST",RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformAppointTeamLeaderReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformAppointTeamLeader ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST",RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST)
end
function InformKickTeamMember(self,Result,KickedMemberRoleId,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformKickTeamMemberAsk()
	PB.Result = Result
	PB.KickedMemberRoleId = KickedMemberRoleId
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST",RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformKickTeamMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformKickTeamMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST",RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST)
end
function InformDissmissTeam(self,Result,LeaderRoleId,_hanlder)
	local PB = self.rpc_pb.WGRpcInformDissmissTeamAsk()
	PB.Result = Result
	PB.LeaderRoleId = LeaderRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST",RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformDissmissTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformDissmissTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST",RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST)
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
	PB.Result = Result
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST",RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformApplyTeamReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformApplyTeam ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST",RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST)
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
		hideNetTip(self,"RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST",RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcAgreeTeamApplicantReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => AgreeTeamApplicant ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST",RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST)
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
		hideNetTip(self,"RPC_CODE_WG_INFORMLOGIN_REQUEST",RPC_CODE_WG_INFORMLOGIN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WGRpcInformLoginReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WG => InformLogin ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WG_INFORMLOGIN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WG_INFORMLOGIN_REQUEST",RPC_CODE_WG_INFORMLOGIN_REQUEST)
end








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

