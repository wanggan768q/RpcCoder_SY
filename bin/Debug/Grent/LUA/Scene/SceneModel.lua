--将变量写入下方
local ModuleId = 3;
local RPC_CODE_SCENE_ENTERSCENE_REQUEST = 351
local RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 352
local RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 353;
local RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 354
local RPC_CODE_SCENE_CHANGESCENE_REQUEST = 355
local RPC_CODE_SCENE_NEWOBJ_NOTIFY = 356;





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
require("3rd/pblua/SceneRpc_pb")
local  SceneRpc_pb = SceneRpc_pb
module("SceneModel")

function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)

end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = SceneRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY,handler(self,self.DeletePlayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_NEWOBJ_NOTIFY,handler(self,self.NewObjCB))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function EnterScene(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.SceneRpcEnterSceneAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcEnterSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_ENTERSCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function LoadSceneComplete(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.SceneRpcLoadSceneCompleteAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcLoadSceneCompleteReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ConnectGameServer(self,RoleId,Key,_hanlder)
	local PB = self.rpc_pb.SceneRpcConnectGameServerAsk()
	PB.RoleId = RoleId
	PB.Key = Key
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcConnectGameServerReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ChangeScene(self,RoleId,CurSceneId,TargetSceneId,_hanlder)
	local PB = self.rpc_pb.SceneRpcChangeSceneAsk()
	PB.RoleId = RoleId
	PB.CurSceneId = CurSceneId
	PB.TargetSceneId = TargetSceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcChangeSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_CHANGESCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end



-- 给c层 注册服务器通知回调
function registerDeletePlayerCBNotify(self,_hanlder)
	if not self.DeletePlayerCBNotifyCallBack then
		self.DeletePlayerCBNotifyCallBack = {}
	end
	table.insert(self.DeletePlayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DeletePlayerCB(self,notifyMsg)
	if self.DeletePlayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcDeletePlayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DeletePlayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDeletePlayerCBNotify(self,_hanlder)
	if nil ~= self.DeletePlayerCBNotifyCallBack then
		for i,callback in ipairs(self.DeletePlayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DeletePlayerCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNewObjCBNotify(self,_hanlder)
	if not self.NewObjCBNotifyCallBack then
		self.NewObjCBNotifyCallBack = {}
	end
	table.insert(self.NewObjCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewObjCB(self,notifyMsg)
	if self.NewObjCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcNewObjNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewObjCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewObjCBNotify(self,_hanlder)
	if nil ~= self.NewObjCBNotifyCallBack then
		for i,callback in ipairs(self.NewObjCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewObjCBNotifyCallBack, i )
			end
		end
	end
end




--[[
askList.Scene = {}

local t = {}
t.name = "EnterScene"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1}}
t.hand = SceneModel.EnterScene
t.pb = SceneRpc_pb.SceneRpcEnterSceneAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "LoadSceneComplete"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1}}
t.hand = SceneModel.LoadSceneComplete
t.pb = SceneRpc_pb.SceneRpcLoadSceneCompleteAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ConnectGameServer"
t.para = {{name="RoleId",t=1},{name="Key",t=2}}
t.hand = SceneModel.ConnectGameServer
t.pb = SceneRpc_pb.SceneRpcConnectGameServerAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ChangeScene"
t.para = {{name="RoleId",t=1},{name="CurSceneId",t=1},{name="TargetSceneId",t=1}}
t.hand = SceneModel.ChangeScene
t.pb = SceneRpc_pb.SceneRpcChangeSceneAsk()
table.insert(askList.Scene,t)

--]]