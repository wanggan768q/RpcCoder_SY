--将变量写入下方
local ModuleId = 19;
local RPC_CODE_CURRENCY_TRANSFROM_REQUEST = 1951
local RPC_CODE_CURRENCY_SHOW_REQUEST = 1952





require("app.Currency.CurrencyRpc_pb")

CurrencyModel = class("CurrencyModel",BaseModel)

function CurrencyModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=CurrencyModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function CurrencyModel:ctor()
	CurrencyModel.super.ctor(self)
	self.rpc_pb = CurrencyRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function CurrencyModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Transfrom(self,To_type,From_type,From_num,Diamond_bind_num,_hanlder)
	local PB = self.rpc_pb.CurrencyRpcTransfromAsk()
	PB.To_type = To_type
	PB.From_type = From_type
	PB.From_num = From_num
	PB.Diamond_bind_num = Diamond_bind_num
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CURRENCY_TRANSFROM_REQUEST",RPC_CODE_CURRENCY_TRANSFROM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CurrencyRpcTransfromReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Currency => Transfrom ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CURRENCY_TRANSFROM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CURRENCY_TRANSFROM_REQUEST",RPC_CODE_CURRENCY_TRANSFROM_REQUEST)
end
function Show(self,_hanlder)
	local PB = self.rpc_pb.CurrencyRpcShowAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CURRENCY_SHOW_REQUEST",RPC_CODE_CURRENCY_SHOW_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CurrencyRpcShowReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Currency => Show ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CURRENCY_SHOW_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CURRENCY_SHOW_REQUEST",RPC_CODE_CURRENCY_SHOW_REQUEST)
end








askList.Currency = {}

local t = {}
t.name = "Transfrom"
t.para = {{name="To_type",t=1},{name="From_type",t=1},{name="From_num",t=1},{name="Diamond_bind_num",t=1}}
t.hand = CurrencyModel.Transfrom
t.pb = CurrencyRpc_pb.CurrencyRpcTransfromAsk()
table.insert(askList.Currency,t)

local t = {}
t.name = "Show"
t.para = {}
t.hand = CurrencyModel.Show
t.pb = CurrencyRpc_pb.CurrencyRpcShowAsk()
table.insert(askList.Currency,t)

