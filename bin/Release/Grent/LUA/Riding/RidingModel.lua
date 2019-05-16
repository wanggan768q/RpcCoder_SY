--将变量写入下方
local ModuleId = 40;
local RPC_CODE_RIDING_RIDING_REQUEST = 4051
local RPC_CODE_RIDING_UNRIDING_REQUEST = 4052





require("app.Riding.RidingRpc_pb")

RidingModel = class("RidingModel",BaseModel)

function RidingModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=RidingModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function RidingModel:ctor()
	RidingModel.super.ctor(self)
	self.rpc_pb = RidingRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function RidingModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Riding(self,_hanlder)
	local PB = self.rpc_pb.RidingRpcRidingAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_RIDING_RIDING_REQUEST",RPC_CODE_RIDING_RIDING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.RidingRpcRidingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Riding => Riding ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_RIDING_RIDING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_RIDING_RIDING_REQUEST",RPC_CODE_RIDING_RIDING_REQUEST)
end
function UnRiding(self,_hanlder)
	local PB = self.rpc_pb.RidingRpcUnRidingAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_RIDING_UNRIDING_REQUEST",RPC_CODE_RIDING_UNRIDING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.RidingRpcUnRidingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Riding => UnRiding ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_RIDING_UNRIDING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_RIDING_UNRIDING_REQUEST",RPC_CODE_RIDING_UNRIDING_REQUEST)
end








askList.Riding = {}

local t = {}
t.name = "Riding"
t.para = {}
t.hand = RidingModel.Riding
t.pb = RidingRpc_pb.RidingRpcRidingAsk()
table.insert(askList.Riding,t)

local t = {}
t.name = "UnRiding"
t.para = {}
t.hand = RidingModel.UnRiding
t.pb = RidingRpc_pb.RidingRpcUnRidingAsk()
table.insert(askList.Riding,t)

