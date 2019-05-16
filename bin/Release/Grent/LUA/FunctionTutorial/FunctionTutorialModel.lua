--将变量写入下方
local ModuleId = 45;
local RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST = 4551
local RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST = 4552
local RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST = 4553





require("app.FunctionTutorial.FunctionTutorialRpc_pb")

FunctionTutorialModel = class("FunctionTutorialModel",BaseModel)

function FunctionTutorialModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=FunctionTutorialModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function FunctionTutorialModel:ctor()
	FunctionTutorialModel.super.ctor(self)
	self.rpc_pb = FunctionTutorialRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function FunctionTutorialModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SyncFunctionStep(self,_hanlder)
	local PB = self.rpc_pb.FunctionTutorialRpcSyncFunctionStepAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FunctionTutorialRpcSyncFunctionStepReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[FunctionTutorial => SyncFunctionStep ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST)
end
function FinishStep(self,FunctionID,_hanlder)
	local PB = self.rpc_pb.FunctionTutorialRpcFinishStepAsk()
	PB.FunctionID = FunctionID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FunctionTutorialRpcFinishStepReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[FunctionTutorial => FinishStep ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST)
end
function ActiveStep(self,FunctionID,_hanlder)
	local PB = self.rpc_pb.FunctionTutorialRpcActiveStepAsk()
	PB.FunctionID = FunctionID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.FunctionTutorialRpcActiveStepReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[FunctionTutorial => ActiveStep ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST",RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST)
end








askList.FunctionTutorial = {}

local t = {}
t.name = "SyncFunctionStep"
t.para = {}
t.hand = FunctionTutorialModel.SyncFunctionStep
t.pb = FunctionTutorialRpc_pb.FunctionTutorialRpcSyncFunctionStepAsk()
table.insert(askList.FunctionTutorial,t)

local t = {}
t.name = "FinishStep"
t.para = {{name="FunctionID",t=1}}
t.hand = FunctionTutorialModel.FinishStep
t.pb = FunctionTutorialRpc_pb.FunctionTutorialRpcFinishStepAsk()
table.insert(askList.FunctionTutorial,t)

local t = {}
t.name = "ActiveStep"
t.para = {{name="FunctionID",t=1}}
t.hand = FunctionTutorialModel.ActiveStep
t.pb = FunctionTutorialRpc_pb.FunctionTutorialRpcActiveStepAsk()
table.insert(askList.FunctionTutorial,t)

