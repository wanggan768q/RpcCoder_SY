--将变量写入下方
local ModuleId = 31;
local RPC_CODE_PET_PETSYNC_REQUEST = 3151
local RPC_CODE_PET_UNSUMMON_REQUEST = 3152
local RPC_CODE_PET_LEVELUPGRADE_REQUEST = 3153
local RPC_CODE_PET_STARUPGRADE_REQUEST = 3154
local RPC_CODE_PET_CHANGENAME_REQUEST = 3155
local RPC_CODE_PET_INHERIT_REQUEST = 3156
local RPC_CODE_PET_SKILLINHERIT_REQUEST = 3157
local RPC_CODE_PET_PASSIVESKILLS_REQUEST = 3158
local RPC_CODE_PET_STUDYSKILL_REQUEST = 3159
local RPC_CODE_PET_LOCKSKILL_REQUEST = 3160
local RPC_CODE_PET_UNLOCKSKILL_REQUEST = 3161





require("app.Pet.PetRpc_pb")

PetModel = class("PetModel",BaseModel)

function PetModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=PetModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function PetModel:ctor()
	PetModel.super.ctor(self)
	self.rpc_pb = PetRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function PetModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function PetSync(self,_hanlder)
	local PB = self.rpc_pb.PetRpcPetSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_PETSYNC_REQUEST",RPC_CODE_PET_PETSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcPetSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => PetSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_PETSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_PETSYNC_REQUEST",RPC_CODE_PET_PETSYNC_REQUEST)
end
function UnSummon(self,_hanlder)
	local PB = self.rpc_pb.PetRpcUnSummonAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_UNSUMMON_REQUEST",RPC_CODE_PET_UNSUMMON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcUnSummonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => UnSummon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_UNSUMMON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_UNSUMMON_REQUEST",RPC_CODE_PET_UNSUMMON_REQUEST)
end
function LevelUpgrade(self,Guid,ItemCount,_hanlder)
	local PB = self.rpc_pb.PetRpcLevelUpgradeAsk()
	PB.Guid = Guid
	for i,v in ipairs(ItemCount) do
		table.insert(PB.ItemCount,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_LEVELUPGRADE_REQUEST",RPC_CODE_PET_LEVELUPGRADE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcLevelUpgradeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => LevelUpgrade ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_LEVELUPGRADE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_LEVELUPGRADE_REQUEST",RPC_CODE_PET_LEVELUPGRADE_REQUEST)
end
function StarUpgrade(self,Guid,UseGuid,_hanlder)
	local PB = self.rpc_pb.PetRpcStarUpgradeAsk()
	PB.Guid = Guid
	PB.UseGuid = UseGuid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_STARUPGRADE_REQUEST",RPC_CODE_PET_STARUPGRADE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcStarUpgradeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => StarUpgrade ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_STARUPGRADE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_STARUPGRADE_REQUEST",RPC_CODE_PET_STARUPGRADE_REQUEST)
end
function ChangeName(self,Guid,NewName,_hanlder)
	local PB = self.rpc_pb.PetRpcChangeNameAsk()
	PB.Guid = Guid
	PB.NewName = NewName
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_CHANGENAME_REQUEST",RPC_CODE_PET_CHANGENAME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcChangeNameReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => ChangeName ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_CHANGENAME_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_CHANGENAME_REQUEST",RPC_CODE_PET_CHANGENAME_REQUEST)
end
function Inherit(self,Guid,UseGuid,_hanlder)
	local PB = self.rpc_pb.PetRpcInheritAsk()
	PB.Guid = Guid
	PB.UseGuid = UseGuid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_INHERIT_REQUEST",RPC_CODE_PET_INHERIT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcInheritReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => Inherit ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_INHERIT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_INHERIT_REQUEST",RPC_CODE_PET_INHERIT_REQUEST)
end
function SkillInherit(self,Guid,UseGuid,_hanlder)
	local PB = self.rpc_pb.PetRpcSkillInheritAsk()
	PB.Guid = Guid
	PB.UseGuid = UseGuid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_SKILLINHERIT_REQUEST",RPC_CODE_PET_SKILLINHERIT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcSkillInheritReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => SkillInherit ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_SKILLINHERIT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_SKILLINHERIT_REQUEST",RPC_CODE_PET_SKILLINHERIT_REQUEST)
end
function PassiveSkills(self,Guid,_hanlder)
	local PB = self.rpc_pb.PetRpcPassiveSkillsAsk()
	PB.Guid = Guid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_PASSIVESKILLS_REQUEST",RPC_CODE_PET_PASSIVESKILLS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcPassiveSkillsReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => PassiveSkills ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_PASSIVESKILLS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_PASSIVESKILLS_REQUEST",RPC_CODE_PET_PASSIVESKILLS_REQUEST)
end
function StudySkill(self,Guid,ItemId,_hanlder)
	local PB = self.rpc_pb.PetRpcStudySkillAsk()
	PB.Guid = Guid
	PB.ItemId = ItemId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_STUDYSKILL_REQUEST",RPC_CODE_PET_STUDYSKILL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcStudySkillReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => StudySkill ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_STUDYSKILL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_STUDYSKILL_REQUEST",RPC_CODE_PET_STUDYSKILL_REQUEST)
end
function LockSkill(self,Guid,SkillId,_hanlder)
	local PB = self.rpc_pb.PetRpcLockSkillAsk()
	PB.Guid = Guid
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_LOCKSKILL_REQUEST",RPC_CODE_PET_LOCKSKILL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcLockSkillReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => LockSkill ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_LOCKSKILL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_LOCKSKILL_REQUEST",RPC_CODE_PET_LOCKSKILL_REQUEST)
end
function UnLockSkill(self,Guid,SkillId,_hanlder)
	local PB = self.rpc_pb.PetRpcUnLockSkillAsk()
	PB.Guid = Guid
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PET_UNLOCKSKILL_REQUEST",RPC_CODE_PET_UNLOCKSKILL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetRpcUnLockSkillReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pet => UnLockSkill ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PET_UNLOCKSKILL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PET_UNLOCKSKILL_REQUEST",RPC_CODE_PET_UNLOCKSKILL_REQUEST)
end








askList.Pet = {}

local t = {}
t.name = "PetSync"
t.para = {}
t.hand = PetModel.PetSync
t.pb = PetRpc_pb.PetRpcPetSyncAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "UnSummon"
t.para = {}
t.hand = PetModel.UnSummon
t.pb = PetRpc_pb.PetRpcUnSummonAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "LevelUpgrade"
t.para = {{name="Guid",t=1},{name="ItemCount",t=1}}
t.hand = PetModel.LevelUpgrade
t.pb = PetRpc_pb.PetRpcLevelUpgradeAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "StarUpgrade"
t.para = {{name="Guid",t=1},{name="UseGuid",t=1}}
t.hand = PetModel.StarUpgrade
t.pb = PetRpc_pb.PetRpcStarUpgradeAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "ChangeName"
t.para = {{name="Guid",t=1},{name="NewName",t=2}}
t.hand = PetModel.ChangeName
t.pb = PetRpc_pb.PetRpcChangeNameAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "Inherit"
t.para = {{name="Guid",t=1},{name="UseGuid",t=1}}
t.hand = PetModel.Inherit
t.pb = PetRpc_pb.PetRpcInheritAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "SkillInherit"
t.para = {{name="Guid",t=1},{name="UseGuid",t=1}}
t.hand = PetModel.SkillInherit
t.pb = PetRpc_pb.PetRpcSkillInheritAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "PassiveSkills"
t.para = {{name="Guid",t=1}}
t.hand = PetModel.PassiveSkills
t.pb = PetRpc_pb.PetRpcPassiveSkillsAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "StudySkill"
t.para = {{name="Guid",t=1},{name="ItemId",t=1}}
t.hand = PetModel.StudySkill
t.pb = PetRpc_pb.PetRpcStudySkillAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "LockSkill"
t.para = {{name="Guid",t=1},{name="SkillId",t=1}}
t.hand = PetModel.LockSkill
t.pb = PetRpc_pb.PetRpcLockSkillAsk()
table.insert(askList.Pet,t)

local t = {}
t.name = "UnLockSkill"
t.para = {{name="Guid",t=1},{name="SkillId",t=1}}
t.hand = PetModel.UnLockSkill
t.pb = PetRpc_pb.PetRpcUnLockSkillAsk()
table.insert(askList.Pet,t)

