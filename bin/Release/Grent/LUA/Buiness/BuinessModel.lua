--将变量写入下方
local ModuleId = 22;
local RPC_CODE_BUINESS_BUINESSSYNC_REQUEST = 2251
local RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST = 2252
local RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST = 2253
local RPC_CODE_BUINESS_BUINESSMAKE_REQUEST = 2254





require("app.Buiness.BuinessRpc_pb")

BuinessModel = class("BuinessModel",BaseModel)

function BuinessModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BuinessModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function BuinessModel:ctor()
	BuinessModel.super.ctor(self)
	self.rpc_pb = BuinessRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function BuinessModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BuinessSync(self,_hanlder)
	local PB = self.rpc_pb.BuinessRpcBuinessSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BUINESS_BUINESSSYNC_REQUEST",RPC_CODE_BUINESS_BUINESSSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BuinessRpcBuinessSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Buiness => BuinessSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BUINESS_BUINESSSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BUINESS_BUINESSSYNC_REQUEST",RPC_CODE_BUINESS_BUINESSSYNC_REQUEST)
end
function BuinessUnlock(self,SkillID,_hanlder)
	local PB = self.rpc_pb.BuinessRpcBuinessUnlockAsk()
	PB.SkillID = SkillID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST",RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BuinessRpcBuinessUnlockReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Buiness => BuinessUnlock ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST",RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST)
end
function BuinessStudy(self,SkillID,StudyType,_hanlder)
	local PB = self.rpc_pb.BuinessRpcBuinessStudyAsk()
	PB.SkillID = SkillID
	PB.StudyType = StudyType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST",RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BuinessRpcBuinessStudyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Buiness => BuinessStudy ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST",RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST)
end
function BuinessMake(self,SkillID,_hanlder)
	local PB = self.rpc_pb.BuinessRpcBuinessMakeAsk()
	PB.SkillID = SkillID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BUINESS_BUINESSMAKE_REQUEST",RPC_CODE_BUINESS_BUINESSMAKE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BuinessRpcBuinessMakeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Buiness => BuinessMake ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BUINESS_BUINESSMAKE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BUINESS_BUINESSMAKE_REQUEST",RPC_CODE_BUINESS_BUINESSMAKE_REQUEST)
end








askList.Buiness = {}

local t = {}
t.name = "BuinessSync"
t.para = {}
t.hand = BuinessModel.BuinessSync
t.pb = BuinessRpc_pb.BuinessRpcBuinessSyncAsk()
table.insert(askList.Buiness,t)

local t = {}
t.name = "BuinessUnlock"
t.para = {{name="SkillID",t=1}}
t.hand = BuinessModel.BuinessUnlock
t.pb = BuinessRpc_pb.BuinessRpcBuinessUnlockAsk()
table.insert(askList.Buiness,t)

local t = {}
t.name = "BuinessStudy"
t.para = {{name="SkillID",t=1},{name="StudyType",t=1}}
t.hand = BuinessModel.BuinessStudy
t.pb = BuinessRpc_pb.BuinessRpcBuinessStudyAsk()
table.insert(askList.Buiness,t)

local t = {}
t.name = "BuinessMake"
t.para = {{name="SkillID",t=1}}
t.hand = BuinessModel.BuinessMake
t.pb = BuinessRpc_pb.BuinessRpcBuinessMakeAsk()
table.insert(askList.Buiness,t)

