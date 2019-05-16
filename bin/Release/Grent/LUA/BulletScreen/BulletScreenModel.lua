--将变量写入下方
local ModuleId = 50;
local RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST = 5051
local RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST = 5052
local RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST = 5053





require("app.BulletScreen.BulletScreenRpc_pb")

BulletScreenModel = class("BulletScreenModel",BaseModel)

function BulletScreenModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BulletScreenModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function BulletScreenModel:ctor()
	BulletScreenModel.super.ctor(self)
	self.rpc_pb = BulletScreenRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function BulletScreenModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BulletScreenOpt(self,BulletScreenType,OptType,_hanlder)
	local PB = self.rpc_pb.BulletScreenRpcBulletScreenOptAsk()
	PB.BulletScreenType = BulletScreenType
	PB.OptType = OptType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST",RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BulletScreenRpcBulletScreenOptReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[BulletScreen => BulletScreenOpt ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST",RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST)
end
function CGBulletScreen(self,CGid,_hanlder)
	local PB = self.rpc_pb.BulletScreenRpcCGBulletScreenAsk()
	PB.CGid = CGid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST",RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BulletScreenRpcCGBulletScreenReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[BulletScreen => CGBulletScreen ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST",RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST)
end
function SendBulletScreenCG(self,CGid,Content,_hanlder)
	local PB = self.rpc_pb.BulletScreenRpcSendBulletScreenCGAsk()
	PB.CGid = CGid
	PB.Content = Content
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST",RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.BulletScreenRpcSendBulletScreenCGReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[BulletScreen => SendBulletScreenCG ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST",RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST)
end








askList.BulletScreen = {}

local t = {}
t.name = "BulletScreenOpt"
t.para = {{name="BulletScreenType",t=1},{name="OptType",t=1}}
t.hand = BulletScreenModel.BulletScreenOpt
t.pb = BulletScreenRpc_pb.BulletScreenRpcBulletScreenOptAsk()
table.insert(askList.BulletScreen,t)

local t = {}
t.name = "CGBulletScreen"
t.para = {{name="CGid",t=1}}
t.hand = BulletScreenModel.CGBulletScreen
t.pb = BulletScreenRpc_pb.BulletScreenRpcCGBulletScreenAsk()
table.insert(askList.BulletScreen,t)

local t = {}
t.name = "SendBulletScreenCG"
t.para = {{name="CGid",t=1},{name="Content",t=2}}
t.hand = BulletScreenModel.SendBulletScreenCG
t.pb = BulletScreenRpc_pb.BulletScreenRpcSendBulletScreenCGAsk()
table.insert(askList.BulletScreen,t)

