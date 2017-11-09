--将变量写入下方
local ModuleId = 7;
local RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 751


BASEATTR_EXP = 701
BASEATTR_LEVEL = 703
BASEATTR_SERVERTIME = 704
BASEATTR_ROLEID = 705


require("3rd/pblua/BaseAttrV1Data_pb")
local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
require("3rd/pblua/BaseAttrRpc_pb")
local  BaseAttrRpc_pb = BaseAttrRpc_pb
module("BaseAttrModel")

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
	self.rpc_pb = BaseAttrRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=BaseAttrV1Data_pb
	self.m_Exp = 0
	self.m_Level = 0
	self.m_ServerTime = 0
	self.m_RoleId = 0


end

-- 更新数据
function UpdateField(self,Id, data, Index, len)
	if  Id == BASEATTR_EXP then
		local num = ReadVarint32(data)
		self.m_Exp = num
	elseif  Id == BASEATTR_LEVEL then
		local num = ReadVarint32(data)
		self.m_Level = num
	elseif  Id == BASEATTR_SERVERTIME then
		local num = ReadVarint32(data)
		self.m_ServerTime = num
	elseif  Id == BASEATTR_ROLEID then
		local num = ReadVarint32(data)
		self.m_RoleId = num
	else
		 print("error Updata")
	end

	
	dataCallback(self,Id,Index)
end


-- 业务事件
function SyncData(self,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_SYNCDATA_REQUEST, pb_data, callback)
end







--[[
askList.BaseAttr = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = BaseAttrModel.SyncData
t.pb = BaseAttrRpc_pb.BaseAttrRpcSyncDataAsk()
table.insert(askList.BaseAttr,t)

--]]