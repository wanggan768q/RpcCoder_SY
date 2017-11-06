--将变量写入下方
local ModuleId = 6;
local RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST = 651
local RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST = 652





local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
require("3rd/pblua/DungeonRpc_pb")
local  DungeonRpc_pb = DungeonRpc_pb
module("DungeonModel")

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
	self.rpc_pb = DungeonRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function CreateDungeon(self,RoleId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateDungeonAsk()
	PB.RoleId = RoleId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end
function ExitDungeon(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcExitDungeonAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcExitDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end







--[[
askList.Dungeon = {}

local t = {}
t.name = "CreateDungeon"
t.para = {{name="RoleId",t=1},{name="DungeonConfigId",t=1}}
t.hand = DungeonModel.CreateDungeon
t.pb = DungeonRpc_pb.DungeonRpcCreateDungeonAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "ExitDungeon"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1}}
t.hand = DungeonModel.ExitDungeon
t.pb = DungeonRpc_pb.DungeonRpcExitDungeonAsk()
table.insert(askList.Dungeon,t)

--]]