--将变量写入下方
local ModuleId = 3;
local RPC_CODE_SCENE_ENTERSCENE_REQUEST = 351
local RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 352
local RPC_CODE_SCENE_NEWPLAYER_NOTIFY = 353;
local RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 354;
local RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 355





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
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
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_NEWPLAYER_NOTIFY,handler(self,self.NewPlayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY,handler(self,self.DeletePlayerCB))

  


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



-- 给c层 注册服务器通知回调
function registerNewPlayerCBNotify(self,_hanlder)
	if not self.NewPlayerCBNotifyCallBack then
		self.NewPlayerCBNotifyCallBack = {}
	end
	table.insert(self.NewPlayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewPlayerCB(self,notifyMsg)
	if self.NewPlayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcNewPlayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewPlayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewPlayerCBNotify(self,_hanlder)
	if nil ~= self.NewPlayerCBNotifyCallBack then
		for i,callback in ipairs(self.NewPlayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewPlayerCBNotifyCallBack, i )
			end
		end
	end
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

--]]