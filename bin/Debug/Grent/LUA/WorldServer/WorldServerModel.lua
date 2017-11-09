--将变量写入下方
local ModuleId = 8;
local RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST = 851
local RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST = 852





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
require("3rd/pblua/WorldServerRpc_pb")
local  WorldServerRpc_pb = WorldServerRpc_pb
module("WorldServerModel")

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
	self.rpc_pb = WorldServerRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function ChangeScene(self,RoleId,CurSceneId,TargetSceneId,MemId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcChangeSceneAsk()
	PB.RoleId = RoleId
	PB.CurSceneId = CurSceneId
	PB.TargetSceneId = TargetSceneId
	PB.MemId = MemId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcChangeSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end
function EnterScene(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.WorldServerRpcEnterSceneAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldServerRpcEnterSceneReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, pb_data, callback)
	showNetTip(self)
end







--[[
askList.WorldServer = {}

local t = {}
t.name = "ChangeScene"
t.para = {{name="RoleId",t=1},{name="CurSceneId",t=1},{name="TargetSceneId",t=1},{name="MemId",t=1}}
t.hand = WorldServerModel.ChangeScene
t.pb = WorldServerRpc_pb.WorldServerRpcChangeSceneAsk()
table.insert(askList.WorldServer,t)

local t = {}
t.name = "EnterScene"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1}}
t.hand = WorldServerModel.EnterScene
t.pb = WorldServerRpc_pb.WorldServerRpcEnterSceneAsk()
table.insert(askList.WorldServer,t)

--]]