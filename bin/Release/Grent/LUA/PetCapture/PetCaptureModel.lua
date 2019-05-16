--将变量写入下方
local ModuleId = 44;
local RPC_CODE_PETCAPTURE_CAPTURE_REQUEST = 4451
local RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY = 4452;
local RPC_CODE_PETCAPTURE_LOGIN_NOTIFY = 4453;
local RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST = 4454





require("app.PetCapture.PetCaptureRpc_pb")

PetCaptureModel = class("PetCaptureModel",BaseModel)

function PetCaptureModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=PetCaptureModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function PetCaptureModel:ctor()
	PetCaptureModel.super.ctor(self)
	self.rpc_pb = PetCaptureRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY,handler(self,self.CapturePetCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PETCAPTURE_LOGIN_NOTIFY,handler(self,self.LoginCB))

  


end

-- 更新数据
function PetCaptureModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Capture(self,BallType,_hanlder)
	local PB = self.rpc_pb.PetCaptureRpcCaptureAsk()
	PB.BallType = BallType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PETCAPTURE_CAPTURE_REQUEST",RPC_CODE_PETCAPTURE_CAPTURE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetCaptureRpcCaptureReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[PetCapture => Capture ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PETCAPTURE_CAPTURE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PETCAPTURE_CAPTURE_REQUEST",RPC_CODE_PETCAPTURE_CAPTURE_REQUEST)
end
function PetLocation(self,LineId,_hanlder)
	local PB = self.rpc_pb.PetCaptureRpcPetLocationAsk()
	PB.LineId = LineId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST",RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PetCaptureRpcPetLocationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[PetCapture => PetLocation ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST",RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerCapturePetCBNotify(self,_hanlder)
	if not self.CapturePetCBNotifyCallBack then
		self.CapturePetCBNotifyCallBack = {}
	end
	table.insert(self.CapturePetCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CapturePetCB(self,notifyMsg)
	if self.CapturePetCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PetCaptureRpcCapturePetNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CapturePetCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCapturePetCBNotify(self,_hanlder)
	if nil ~= self.CapturePetCBNotifyCallBack then
		for i,callback in ipairs(self.CapturePetCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CapturePetCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLoginCBNotify(self,_hanlder)
	if not self.LoginCBNotifyCallBack then
		self.LoginCBNotifyCallBack = {}
	end
	table.insert(self.LoginCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LoginCB(self,notifyMsg)
	if self.LoginCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PetCaptureRpcLoginNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LoginCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLoginCBNotify(self,_hanlder)
	if nil ~= self.LoginCBNotifyCallBack then
		for i,callback in ipairs(self.LoginCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LoginCBNotifyCallBack, i )
			end
		end
	end
end





askList.PetCapture = {}

local t = {}
t.name = "Capture"
t.para = {{name="BallType",t=1}}
t.hand = PetCaptureModel.Capture
t.pb = PetCaptureRpc_pb.PetCaptureRpcCaptureAsk()
table.insert(askList.PetCapture,t)

local t = {}
t.name = "PetLocation"
t.para = {{name="LineId",t=1}}
t.hand = PetCaptureModel.PetLocation
t.pb = PetCaptureRpc_pb.PetCaptureRpcPetLocationAsk()
table.insert(askList.PetCapture,t)

