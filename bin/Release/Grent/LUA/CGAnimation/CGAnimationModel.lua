--将变量写入下方
local ModuleId = 29;
local RPC_CODE_CGANIMATION_CGPLAY_REQUEST = 2951
local RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY = 2952;
local RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY = 2953;
local RPC_CODE_CGANIMATION_CGSKIP_REQUEST = 2954
local RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY = 2955;





require("app.CGAnimation.CGAnimationRpc_pb")

CGAnimationModel = class("CGAnimationModel",BaseModel)

function CGAnimationModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=CGAnimationModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function CGAnimationModel:ctor()
	CGAnimationModel.super.ctor(self)
	self.rpc_pb = CGAnimationRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY,handler(self,self.CgPlayNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY,handler(self,self.CgOverNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY,handler(self,self.ScriptPlayCB))

  


end

-- 更新数据
function CGAnimationModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function CgPlay(self,CgId,_hanlder)
	local PB = self.rpc_pb.CGAnimationRpcCgPlayAsk()
	PB.CgId = CgId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CGANIMATION_CGPLAY_REQUEST",RPC_CODE_CGANIMATION_CGPLAY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CGAnimationRpcCgPlayReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CGAnimation => CgPlay ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CGANIMATION_CGPLAY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CGANIMATION_CGPLAY_REQUEST",RPC_CODE_CGANIMATION_CGPLAY_REQUEST)
end
function CgSkip(self,_hanlder)
	local PB = self.rpc_pb.CGAnimationRpcCgSkipAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CGANIMATION_CGSKIP_REQUEST",RPC_CODE_CGANIMATION_CGSKIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CGAnimationRpcCgSkipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CGAnimation => CgSkip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CGANIMATION_CGSKIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CGANIMATION_CGSKIP_REQUEST",RPC_CODE_CGANIMATION_CGSKIP_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerCgPlayNotifyCBNotify(self,_hanlder)
	if not self.CgPlayNotifyCBNotifyCallBack then
		self.CgPlayNotifyCBNotifyCallBack = {}
	end
	table.insert(self.CgPlayNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CgPlayNotifyCB(self,notifyMsg)
	if self.CgPlayNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CGAnimationRpcCgPlayNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CgPlayNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCgPlayNotifyCBNotify(self,_hanlder)
	if nil ~= self.CgPlayNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.CgPlayNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CgPlayNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCgOverNotifyCBNotify(self,_hanlder)
	if not self.CgOverNotifyCBNotifyCallBack then
		self.CgOverNotifyCBNotifyCallBack = {}
	end
	table.insert(self.CgOverNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CgOverNotifyCB(self,notifyMsg)
	if self.CgOverNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CGAnimationRpcCgOverNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CgOverNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCgOverNotifyCBNotify(self,_hanlder)
	if nil ~= self.CgOverNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.CgOverNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CgOverNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerScriptPlayCBNotify(self,_hanlder)
	if not self.ScriptPlayCBNotifyCallBack then
		self.ScriptPlayCBNotifyCallBack = {}
	end
	table.insert(self.ScriptPlayCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ScriptPlayCB(self,notifyMsg)
	if self.ScriptPlayCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CGAnimationRpcScriptPlayNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ScriptPlayCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterScriptPlayCBNotify(self,_hanlder)
	if nil ~= self.ScriptPlayCBNotifyCallBack then
		for i,callback in ipairs(self.ScriptPlayCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ScriptPlayCBNotifyCallBack, i )
			end
		end
	end
end





askList.CGAnimation = {}

local t = {}
t.name = "CgPlay"
t.para = {{name="CgId",t=1}}
t.hand = CGAnimationModel.CgPlay
t.pb = CGAnimationRpc_pb.CGAnimationRpcCgPlayAsk()
table.insert(askList.CGAnimation,t)

local t = {}
t.name = "CgSkip"
t.para = {}
t.hand = CGAnimationModel.CgSkip
t.pb = CGAnimationRpc_pb.CGAnimationRpcCgSkipAsk()
table.insert(askList.CGAnimation,t)

