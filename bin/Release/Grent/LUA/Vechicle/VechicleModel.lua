--将变量写入下方
local ModuleId = 41;
local RPC_CODE_VECHICLE_QUITVECHILE_REQUEST = 4151





require("app.Vechicle.VechicleRpc_pb")

VechicleModel = class("VechicleModel",BaseModel)

function VechicleModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=VechicleModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function VechicleModel:ctor()
	VechicleModel.super.ctor(self)
	self.rpc_pb = VechicleRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function VechicleModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function QuitVechile(self,_hanlder)
	local PB = self.rpc_pb.VechicleRpcQuitVechileAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_VECHICLE_QUITVECHILE_REQUEST",RPC_CODE_VECHICLE_QUITVECHILE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.VechicleRpcQuitVechileReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Vechicle => QuitVechile ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_VECHICLE_QUITVECHILE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_VECHICLE_QUITVECHILE_REQUEST",RPC_CODE_VECHICLE_QUITVECHILE_REQUEST)
end








askList.Vechicle = {}

local t = {}
t.name = "QuitVechile"
t.para = {}
t.hand = VechicleModel.QuitVechile
t.pb = VechicleRpc_pb.VechicleRpcQuitVechileAsk()
table.insert(askList.Vechicle,t)

