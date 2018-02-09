--将变量写入下方
local ModuleId = 13;
local RPC_CODE_CHAT_CHAT_REQUEST = 1351
local RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY = 1352;



local require = require
local table = table
local tostring = tostring
local MLayerMgr = HS_MLayerMgr
local typeof = typeof
local ipairs = ipairs
local print = print
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

local function showNetTip(self)

end

local function hideNetTip(self)

end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = ChatRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY,handler(self,self.PushChatUpdatesCB))

  


end

-- 更新数据
function UpdateField(self,uf)

end


-- 业务事件
function Chat(self,Chat_msg,Chat_channel,_hanlder)
	local PB = self.rpc_pb.ChatRpcChatAsk()
	PB.Chat_msg = Chat_msg
	PB.Chat_channel = Chat_channel
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self)
		if _hanlder then
			local ret_msg = self.rpc_pb.ChatRpcChatReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CHAT_CHAT_REQUEST, pb_data, callback)
	showNetTip(self)
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

