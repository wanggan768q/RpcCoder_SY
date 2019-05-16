--将变量写入下方
local ModuleId = 21;
local RPC_CODE_SKILL_SKILLINFO_REQUEST = 2151
local RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST = 2152
local RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST = 2153
local RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST = 2154





require("app.Skill.SkillRpc_pb")

SkillModel = class("SkillModel",BaseModel)

function SkillModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=SkillModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function SkillModel:ctor()
	SkillModel.super.ctor(self)
	self.rpc_pb = SkillRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function SkillModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SkillInfo(self,_hanlder)
	local PB = self.rpc_pb.SkillRpcSkillInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SKILL_SKILLINFO_REQUEST",RPC_CODE_SKILL_SKILLINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcSkillInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Skill => SkillInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_SKILLINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SKILL_SKILLINFO_REQUEST",RPC_CODE_SKILL_SKILLINFO_REQUEST)
end
function UpdateSkillInfo(self,ProfessionInfos,CurUseMastery,_hanlder)
	local PB = self.rpc_pb.SkillRpcUpdateSkillInfoAsk()
	for i,v in ipairs(ProfessionInfos) do
		table.insert(PB.ProfessionInfos,v)
	end
	PB.CurUseMastery = CurUseMastery
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST",RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcUpdateSkillInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Skill => UpdateSkillInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST",RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST)
end
function LevelUpSkillPos(self,SkillPos,IsAuto,_hanlder)
	local PB = self.rpc_pb.SkillRpcLevelUpSkillPosAsk()
	PB.SkillPos = SkillPos
	PB.IsAuto = IsAuto
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST",RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcLevelUpSkillPosReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Skill => LevelUpSkillPos ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST",RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST)
end
function SkillLevelInfo(self,_hanlder)
	local PB = self.rpc_pb.SkillRpcSkillLevelInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST",RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcSkillLevelInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Skill => SkillLevelInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST",RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST)
end








askList.Skill = {}

local t = {}
t.name = "SkillInfo"
t.para = {}
t.hand = SkillModel.SkillInfo
t.pb = SkillRpc_pb.SkillRpcSkillInfoAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "UpdateSkillInfo"
t.para = {{name="ProfessionInfos",t=3},{name="CurUseMastery",t=1}}
t.hand = SkillModel.UpdateSkillInfo
t.pb = SkillRpc_pb.SkillRpcUpdateSkillInfoAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "LevelUpSkillPos"
t.para = {{name="SkillPos",t=1},{name="IsAuto",t=3}}
t.hand = SkillModel.LevelUpSkillPos
t.pb = SkillRpc_pb.SkillRpcLevelUpSkillPosAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "SkillLevelInfo"
t.para = {}
t.hand = SkillModel.SkillLevelInfo
t.pb = SkillRpc_pb.SkillRpcSkillLevelInfoAsk()
table.insert(askList.Skill,t)

