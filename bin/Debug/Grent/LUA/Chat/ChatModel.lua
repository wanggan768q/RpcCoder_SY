-- ChatModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 13;
local RPC_CODE_CHAT_CHAT_REQUEST = 1351
local RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY = 1352;
local RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY = 1353;
local RPC_CODE_CHAT_SAY_NOTIFY = 1354;
local RPC_CODE_CHAT_SERVERCHAT_NOTIFY = 1355;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
local error = error
local Event = Event
local removeTableData = removeTableData
local copyTableData = copyTableData
local NetE = EventDefine.NetE
require("Common/EventDefine")
local CommonE = EventDefine.CommonE
require("3rd/pblua/ChatRpc_pb")
local  ChatRpc_pb = ChatRpc_pb
module("ChatModel")





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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = ChatRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY,handler(self,self.PushChatUpdatesCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY,handler(self,self.PushMarqueeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SAY_NOTIFY,handler(self,self.SayCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SERVERCHAT_NOTIFY,handler(self,self.ServerChatCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function Chat(self,Chat_msg,Chat_channel,_hanlder)
	local PB = self.rpc_pb.ChatRpcChatAsk()
	PB.Chat_msg.Chat_content = Chat_msg.Chat_content
	PB.Chat_msg.Chat_voice_url = Chat_msg.Chat_voice_url
	PB.Chat_msg.Chat_voice_secs = Chat_msg.Chat_voice_secs
	for i = 1, #Chat_msg.Items do
		table.insert( PB.Chat_msg.Items,Chat_msg.Items[i] )
	end
	PB.Chat_msg.StringUIConfigId = Chat_msg.StringUIConfigId
	for i = 1, #Chat_msg.Params do
		table.insert( PB.Chat_msg.Params,Chat_msg.Params[i] )
	end
	PB.Chat_channel = Chat_channel
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_CHAT_CHAT_REQUEST',RPC_CODE_CHAT_CHAT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ChatRpcChatReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Chat => Chat ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CHAT_CHAT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_CHAT_CHAT_REQUEST',RPC_CODE_CHAT_CHAT_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerPushChatUpdatesCBNotify(self,_hanlder)
	if not self.PushChatUpdatesCBNotifyCallBack then
		self.PushChatUpdatesCBNotifyCallBack = {}
	end
	table.insert(self.PushChatUpdatesCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PushChatUpdatesCB(self,notifyMsg)
	if self.PushChatUpdatesCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcPushChatUpdatesNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PushChatUpdatesCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPushChatUpdatesCBNotify(self,_hanlder)
	if nil ~= self.PushChatUpdatesCBNotifyCallBack then
		for i,callback in ipairs(self.PushChatUpdatesCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PushChatUpdatesCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerPushMarqueeCBNotify(self,_hanlder)
	if not self.PushMarqueeCBNotifyCallBack then
		self.PushMarqueeCBNotifyCallBack = {}
	end
	table.insert(self.PushMarqueeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PushMarqueeCB(self,notifyMsg)
	if self.PushMarqueeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcPushMarqueeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PushMarqueeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPushMarqueeCBNotify(self,_hanlder)
	if nil ~= self.PushMarqueeCBNotifyCallBack then
		for i,callback in ipairs(self.PushMarqueeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PushMarqueeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSayCBNotify(self,_hanlder)
	if not self.SayCBNotifyCallBack then
		self.SayCBNotifyCallBack = {}
	end
	table.insert(self.SayCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SayCB(self,notifyMsg)
	if self.SayCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcSayNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SayCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSayCBNotify(self,_hanlder)
	if nil ~= self.SayCBNotifyCallBack then
		for i,callback in ipairs(self.SayCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SayCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerServerChatCBNotify(self,_hanlder)
	if not self.ServerChatCBNotifyCallBack then
		self.ServerChatCBNotifyCallBack = {}
	end
	table.insert(self.ServerChatCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ServerChatCB(self,notifyMsg)
	if self.ServerChatCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcServerChatNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ServerChatCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterServerChatCBNotify(self,_hanlder)
	if nil ~= self.ServerChatCBNotifyCallBack then
		for i,callback in ipairs(self.ServerChatCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ServerChatCBNotifyCallBack, i )
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
askList.Chat = {}

local t = {}
t.name = "Chat"
t.para = {{name="Chat_msg",t=3},{name="Chat_channel",t=1}}
t.hand = ChatModel.Chat
t.pb = ChatRpc_pb.ChatRpcChatAsk()
table.insert(askList.Chat,t)

--]]

