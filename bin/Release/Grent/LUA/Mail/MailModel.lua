--将变量写入下方
local ModuleId = 30;
local RPC_CODE_MAIL_INITMAIL_REQUEST = 3051
local RPC_CODE_MAIL_READMAIL_REQUEST = 3052
local RPC_CODE_MAIL_DELETEMAIL_REQUEST = 3053
local RPC_CODE_MAIL_GETMAIL_REQUEST = 3054
local RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY = 3055;





require("app.Mail.MailRpc_pb")

MailModel = class("MailModel",BaseModel)

function MailModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MailModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MailModel:ctor()
	MailModel.super.ctor(self)
	self.rpc_pb = MailRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY,handler(self,self.SyncMailInfoCB))

  


end

-- 更新数据
function MailModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function InitMail(self,_hanlder)
	local PB = self.rpc_pb.MailRpcInitMailAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MAIL_INITMAIL_REQUEST",RPC_CODE_MAIL_INITMAIL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcInitMailReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mail => InitMail ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_INITMAIL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MAIL_INITMAIL_REQUEST",RPC_CODE_MAIL_INITMAIL_REQUEST)
end
function ReadMail(self,Mail_type,Mail_id,_hanlder)
	local PB = self.rpc_pb.MailRpcReadMailAsk()
	PB.Mail_type = Mail_type
	PB.Mail_id = Mail_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MAIL_READMAIL_REQUEST",RPC_CODE_MAIL_READMAIL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcReadMailReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mail => ReadMail ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_READMAIL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MAIL_READMAIL_REQUEST",RPC_CODE_MAIL_READMAIL_REQUEST)
end
function DeleteMail(self,Mail_type,Mail_id,_hanlder)
	local PB = self.rpc_pb.MailRpcDeleteMailAsk()
	PB.Mail_type = Mail_type
	PB.Mail_id = Mail_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MAIL_DELETEMAIL_REQUEST",RPC_CODE_MAIL_DELETEMAIL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcDeleteMailReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mail => DeleteMail ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_DELETEMAIL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MAIL_DELETEMAIL_REQUEST",RPC_CODE_MAIL_DELETEMAIL_REQUEST)
end
function GetMail(self,Mail_type,Mail_id,_hanlder)
	local PB = self.rpc_pb.MailRpcGetMailAsk()
	PB.Mail_type = Mail_type
	PB.Mail_id = Mail_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_MAIL_GETMAIL_REQUEST",RPC_CODE_MAIL_GETMAIL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcGetMailReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Mail => GetMail ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_GETMAIL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_MAIL_GETMAIL_REQUEST",RPC_CODE_MAIL_GETMAIL_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerSyncMailInfoCBNotify(self,_hanlder)
	if not self.SyncMailInfoCBNotifyCallBack then
		self.SyncMailInfoCBNotifyCallBack = {}
	end
	table.insert(self.SyncMailInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SyncMailInfoCB(self,notifyMsg)
	if self.SyncMailInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MailRpcSyncMailInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncMailInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSyncMailInfoCBNotify(self,_hanlder)
	if nil ~= self.SyncMailInfoCBNotifyCallBack then
		for i,callback in ipairs(self.SyncMailInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncMailInfoCBNotifyCallBack, i )
			end
		end
	end
end





askList.Mail = {}

local t = {}
t.name = "InitMail"
t.para = {}
t.hand = MailModel.InitMail
t.pb = MailRpc_pb.MailRpcInitMailAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "ReadMail"
t.para = {{name="Mail_type",t=1},{name="Mail_id",t=1}}
t.hand = MailModel.ReadMail
t.pb = MailRpc_pb.MailRpcReadMailAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "DeleteMail"
t.para = {{name="Mail_type",t=1},{name="Mail_id",t=1}}
t.hand = MailModel.DeleteMail
t.pb = MailRpc_pb.MailRpcDeleteMailAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "GetMail"
t.para = {{name="Mail_type",t=1},{name="Mail_id",t=1}}
t.hand = MailModel.GetMail
t.pb = MailRpc_pb.MailRpcGetMailAsk()
table.insert(askList.Mail,t)

