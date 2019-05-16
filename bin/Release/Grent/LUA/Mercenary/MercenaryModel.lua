--将变量写入下方
local ModuleId = 51;
local RPC_CODE_MERCENARY_INQUEUE_REQUEST = 5151
local RPC_CODE_MERCENARY_OUTQUEUE_REQUEST = 5152
local RPC_CODE_MERCENARY_AUTOSET_REQUEST = 5153
local RPC_CODE_MERCENARY_INFO_REQUEST = 5154





require("app.Mercenary.MercenaryRpc_pb")

MercenaryModel = class("MercenaryModel",BaseModel)

function MercenaryModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MercenaryModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MercenaryModel:ctor()
	MercenaryModel.super.ctor(self)
	self.rpc_pb = MercenaryRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function MercenaryModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function InQueue(self,Id,_hanlder)
	local PB = self.rpc_pb.MercenaryRpcInQueueAsk()
	PB.Id = Id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MERCENARY_INQUEUE_REQUEST",RPC_CODE_MERCENARY_INQUEUE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MercenaryRpcInQueueReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mercenary => InQueue ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MERCENARY_INQUEUE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MERCENARY_INQUEUE_REQUEST",RPC_CODE_MERCENARY_INQUEUE_REQUEST)
end
function OutQueue(self,Id,_hanlder)
	local PB = self.rpc_pb.MercenaryRpcOutQueueAsk()
	PB.Id = Id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MERCENARY_OUTQUEUE_REQUEST",RPC_CODE_MERCENARY_OUTQUEUE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MercenaryRpcOutQueueReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mercenary => OutQueue ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MERCENARY_OUTQUEUE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MERCENARY_OUTQUEUE_REQUEST",RPC_CODE_MERCENARY_OUTQUEUE_REQUEST)
end
function AutoSet(self,_hanlder)
	local PB = self.rpc_pb.MercenaryRpcAutoSetAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MERCENARY_AUTOSET_REQUEST",RPC_CODE_MERCENARY_AUTOSET_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MercenaryRpcAutoSetReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mercenary => AutoSet ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MERCENARY_AUTOSET_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MERCENARY_AUTOSET_REQUEST",RPC_CODE_MERCENARY_AUTOSET_REQUEST)
end
function Info(self,_hanlder)
	local PB = self.rpc_pb.MercenaryRpcInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MERCENARY_INFO_REQUEST",RPC_CODE_MERCENARY_INFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MercenaryRpcInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mercenary => Info ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MERCENARY_INFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MERCENARY_INFO_REQUEST",RPC_CODE_MERCENARY_INFO_REQUEST)
end








askList.Mercenary = {}

local t = {}
t.name = "InQueue"
t.para = {{name="Id",t=1}}
t.hand = MercenaryModel.InQueue
t.pb = MercenaryRpc_pb.MercenaryRpcInQueueAsk()
table.insert(askList.Mercenary,t)

local t = {}
t.name = "OutQueue"
t.para = {{name="Id",t=1}}
t.hand = MercenaryModel.OutQueue
t.pb = MercenaryRpc_pb.MercenaryRpcOutQueueAsk()
table.insert(askList.Mercenary,t)

local t = {}
t.name = "AutoSet"
t.para = {}
t.hand = MercenaryModel.AutoSet
t.pb = MercenaryRpc_pb.MercenaryRpcAutoSetAsk()
table.insert(askList.Mercenary,t)

local t = {}
t.name = "Info"
t.para = {}
t.hand = MercenaryModel.Info
t.pb = MercenaryRpc_pb.MercenaryRpcInfoAsk()
table.insert(askList.Mercenary,t)

