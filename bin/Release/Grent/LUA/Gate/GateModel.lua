--将变量写入下方
local ModuleId = 43;
local RPC_CODE_GATE_PING_REQUEST = 4351





require("app.Gate.GateRpc_pb")

GateModel = class("GateModel",BaseModel)

function GateModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GateModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function GateModel:ctor()
	GateModel.super.ctor(self)
	self.rpc_pb = GateRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function GateModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Ping(self,Sequence,_hanlder)
	local PB = self.rpc_pb.GateRpcPingAsk()
	PB.Sequence = Sequence
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.GateRpcPingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Gate => Ping ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GATE_PING_REQUEST, pb_data, callback)
end








askList.Gate = {}

local t = {}
t.name = "Ping"
t.para = {{name="Sequence",t=1}}
t.hand = GateModel.Ping
t.pb = GateRpc_pb.GateRpcPingAsk()
table.insert(askList.Gate,t)

