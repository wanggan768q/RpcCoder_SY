--将变量写入下方
local ModuleId = 6;
local RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST = 651
local RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST = 652
local RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST = 653
local RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654
local RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY = 655;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
require("3rd/pblua/DungeonRpc_pb")
local  DungeonRpc_pb = DungeonRpc_pb
module("DungeonModel")





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
	self.rpc_pb = DungeonRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY,handler(self,self.SettlementCB))

  


end

-- 更新数据
function UpdateField(self,uf)

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
function EnterDungeon(self,SceneId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcEnterDungeonAsk()
	PB.SceneId = SceneId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcEnterDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end
function InformCreateDungeon(self,RoleId,TargetSceneId,DungeonConfigId,CurSceneId,Result,RoleIds,_hanlder)
	local PB = self.rpc_pb.DungeonRpcInformCreateDungeonAsk()
	PB.RoleId = RoleId
	PB.TargetSceneId = TargetSceneId
	PB.DungeonConfigId = DungeonConfigId
	PB.CurSceneId = CurSceneId
	PB.Result = Result
	for i,v in ipairs(RoleIds) do
		table.insert(PB.RoleIds,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcInformCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self)
end



-- 给c层 注册服务器通知回调
function registerSettlementCBNotify(self,_hanlder)
	if not self.SettlementCBNotifyCallBack then
		self.SettlementCBNotifyCallBack = {}
	end
	table.insert(self.SettlementCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SettlementCB(self,notifyMsg)
	if self.SettlementCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcSettlementNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SettlementCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSettlementCBNotify(self,_hanlder)
	if nil ~= self.SettlementCBNotifyCallBack then
		for i,callback in ipairs(self.SettlementCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SettlementCBNotifyCallBack, i )
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

local t = {}
t.name = "EnterDungeon"
t.para = {{name="SceneId",t=1},{name="DungeonConfigId",t=1}}
t.hand = DungeonModel.EnterDungeon
t.pb = DungeonRpc_pb.DungeonRpcEnterDungeonAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "InformCreateDungeon"
t.para = {{name="RoleId",t=1},{name="TargetSceneId",t=1},{name="DungeonConfigId",t=1},{name="CurSceneId",t=1},{name="Result",t=1},{name="RoleIds",t=1}}
t.hand = DungeonModel.InformCreateDungeon
t.pb = DungeonRpc_pb.DungeonRpcInformCreateDungeonAsk()
table.insert(askList.Dungeon,t)

--]]

