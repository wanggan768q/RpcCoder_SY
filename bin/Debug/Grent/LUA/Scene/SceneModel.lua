--将变量写入下方
local ModuleId = 3;
local RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 351
local RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 352;
local RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 353
local RPC_CODE_SCENE_CHANGESCENE_REQUEST = 354
local RPC_CODE_SCENE_CREATEOBJ_NOTIFY = 355;
local RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST = 356
local RPC_CODE_SCENE_CENTERSCENE_NOTIFY = 357;
local RPC_CODE_SCENE_SENTERSCENE_NOTIFY = 358;
local RPC_CODE_SCENE_OBJDIE_NOTIFY = 359;
local RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST = 360



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/SceneRpc_pb")
local  SceneRpc_pb = SceneRpc_pb
module("SceneModel")





function handler(obj,method)
	return function ( ... )
		return method(obj,...)
	end
end

local function dataCallback(self,Id,Index)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			callback(Id,Index)
		end
	end
end

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = SceneRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY,handler(self,self.DeletePlayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_CREATEOBJ_NOTIFY,handler(self,self.CreateObjCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_SENTERSCENE_NOTIFY,handler(self,self.SEnterSceneCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_OBJDIE_NOTIFY,handler(self,self.ObjDieCB))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
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
function SurroundingHuman(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcSurroundingHumanAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcSurroundingHumanReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, pb_data, callback)
	showNetTip(self)
end
function Collide_ChangeScene(self,Collide_id,_hanlder)
	local PB = self.rpc_pb.SceneRpcCollide_ChangeSceneAsk()
	PB.Collide_id = Collide_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcCollide_ChangeSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, pb_data, callback)
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
function registerCreateObjCBNotify(self,_hanlder)
	if not self.CreateObjCBNotifyCallBack then
		self.CreateObjCBNotifyCallBack = {}
	end
	table.insert(self.CreateObjCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CreateObjCB(self,notifyMsg)
	if self.CreateObjCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcCreateObjNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CreateObjCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCreateObjCBNotify(self,_hanlder)
	if nil ~= self.CreateObjCBNotifyCallBack then
		for i,callback in ipairs(self.CreateObjCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CreateObjCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function CEnterSceneNotify(self,SceneId,MapId)
	local PB = self.rpc_pb.SceneRpcCEnterSceneNotify()
	PB.SceneId = SceneId
	PB.MapId = MapId
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_SCENE_CENTERSCENE_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerSEnterSceneCBNotify(self,_hanlder)
	if not self.SEnterSceneCBNotifyCallBack then
		self.SEnterSceneCBNotifyCallBack = {}
	end
	table.insert(self.SEnterSceneCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SEnterSceneCB(self,notifyMsg)
	if self.SEnterSceneCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcSEnterSceneNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SEnterSceneCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSEnterSceneCBNotify(self,_hanlder)
	if nil ~= self.SEnterSceneCBNotifyCallBack then
		for i,callback in ipairs(self.SEnterSceneCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SEnterSceneCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerObjDieCBNotify(self,_hanlder)
	if not self.ObjDieCBNotifyCallBack then
		self.ObjDieCBNotifyCallBack = {}
	end
	table.insert(self.ObjDieCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ObjDieCB(self,notifyMsg)
	if self.ObjDieCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcObjDieNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ObjDieCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterObjDieCBNotify(self,_hanlder)
	if nil ~= self.ObjDieCBNotifyCallBack then
		for i,callback in ipairs(self.ObjDieCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ObjDieCBNotifyCallBack, i )
			end
		end
	end
end


function registerDataCallback(self,_hanlder)
	if not self.DataCallback then
		self.DataCallback = {}
	end
	table.insert(self.DataCallback,_hanlder)
end

function unregisterDataCallback(self,_hanlder)
	if nil ~= self.DataCallback then
		for i,callback in ipairs(self.DataCallback ) do
			if callback == _hanlder then
				table.remove(self.DataCallback, i )
			end
		end
	end
end

function GetValue(self, Id,Index )
	-- body
	
end

--[[
askList.Scene = {}

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

local t = {}
t.name = "SurroundingHuman"
t.para = {}
t.hand = SceneModel.SurroundingHuman
t.pb = SceneRpc_pb.SceneRpcSurroundingHumanAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "Collide_ChangeScene"
t.para = {{name="Collide_id",t=1}}
t.hand = SceneModel.Collide_ChangeScene
t.pb = SceneRpc_pb.SceneRpcCollide_ChangeSceneAsk()
table.insert(askList.Scene,t)

--]]

