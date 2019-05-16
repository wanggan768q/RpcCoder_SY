--将变量写入下方
local ModuleId = 13;
local RPC_CODE_CHAT_CHAT_REQUEST = 1351
local RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY = 1352;
local RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY = 1353;
local RPC_CODE_CHAT_SAY_NOTIFY = 1354;





require("app.Chat.ChatRpc_pb")

ChatModel = class("ChatModel",BaseModel)

function ChatModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ChatModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ChatModel:ctor()
	ChatModel.super.ctor(self)
	self.rpc_pb = ChatRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY,handler(self,self.PushChatUpdatesCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY,handler(self,self.PushMarqueeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SAY_NOTIFY,handler(self,self.SayCB))

  


end

-- 更新数据
function ChatModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Chat(self,Chat_msg,Chat_channel,_hanlder)
	local PB = self.rpc_pb.ChatRpcChatAsk()
	PB.Chat_msg.Chat_content = Chat_msg.Chat_content
	PB.Chat_msg.Chat_voice_url = Chat_msg.Chat_voice_url
	PB.Chat_msg.Chat_voice_secs = Chat_msg.Chat_voice_secs
	PB.Chat_channel = Chat_channel
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CHAT_CHAT_REQUEST",RPC_CODE_CHAT_CHAT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ChatRpcChatReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Chat => Chat ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CHAT_CHAT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CHAT_CHAT_REQUEST",RPC_CODE_CHAT_CHAT_REQUEST)
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





askList.Chat = {}

local t = {}
t.name = "Chat"
t.para = {{name="Chat_msg",t=3},{name="Chat_channel",t=1}}
t.hand = ChatModel.Chat
t.pb = ChatRpc_pb.ChatRpcChatAsk()
table.insert(askList.Chat,t)

