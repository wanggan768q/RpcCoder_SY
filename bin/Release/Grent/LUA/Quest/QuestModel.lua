--将变量写入下方
local ModuleId = 15;
local RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY = 1551;
local RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST = 1552
local RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY = 1553;
local RPC_CODE_QUEST_UPDATEQUEST_NOTIFY = 1554;
local RPC_CODE_QUEST_GIVEUPQUEST_REQUEST = 1555
local RPC_CODE_QUEST_COMPLETEQUEST_REQUEST = 1556
local RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST = 1557
local RPC_CODE_QUEST_ACCEPTQUEST_REQUEST = 1558
local RPC_CODE_QUEST_SYNCQUEST_REQUEST = 1559
local RPC_CODE_QUEST_GETREWARD_REQUEST = 1560
local RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY = 1561;
local RPC_CODE_QUEST_GETQUESTDATA_REQUEST = 1562
local RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST = 1563
local RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY = 1564;
local RPC_CODE_QUEST_CONSUMEITEM_REQUEST = 1565
local RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST = 1566
local RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY = 1567;
local RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST = 1568
local RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY = 1569;





require("app.Quest.QuestRpc_pb")

QuestModel = class("QuestModel",BaseModel)

function QuestModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=QuestModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function QuestModel:ctor()
	QuestModel.super.ctor(self)
	self.rpc_pb = QuestRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY,handler(self,self.OnAcceptQuestCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY,handler(self,self.OnCompleteQuestCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_UPDATEQUEST_NOTIFY,handler(self,self.UpdateQuestCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY,handler(self,self.RemoveQuestNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY,handler(self,self.DailyQuestUpdateCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY,handler(self,self.CompleteQuestIdsNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY,handler(self,self.SyncCanAcceptQuestCB))

  


end

-- 更新数据
function QuestModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function CompleteQuestStep(self,QuestConfigId,QuestStep,TargetId,QuestStepEventType,_hanlder)
	local PB = self.rpc_pb.QuestRpcCompleteQuestStepAsk()
	PB.QuestConfigId = QuestConfigId
	PB.QuestStep = QuestStep
	PB.TargetId = TargetId
	PB.QuestStepEventType = QuestStepEventType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST",RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcCompleteQuestStepReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => CompleteQuestStep ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST",RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST)
end
function GiveUpQuest(self,QuestConfigId,_hanlder)
	local PB = self.rpc_pb.QuestRpcGiveUpQuestAsk()
	PB.QuestConfigId = QuestConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_GIVEUPQUEST_REQUEST",RPC_CODE_QUEST_GIVEUPQUEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcGiveUpQuestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => GiveUpQuest ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_GIVEUPQUEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_GIVEUPQUEST_REQUEST",RPC_CODE_QUEST_GIVEUPQUEST_REQUEST)
end
function CompleteQuest(self,QuestConfigId,TargetId,QuestEventType,_hanlder)
	local PB = self.rpc_pb.QuestRpcCompleteQuestAsk()
	PB.QuestConfigId = QuestConfigId
	PB.TargetId = TargetId
	PB.QuestEventType = QuestEventType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_COMPLETEQUEST_REQUEST",RPC_CODE_QUEST_COMPLETEQUEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcCompleteQuestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => CompleteQuest ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_COMPLETEQUEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_COMPLETEQUEST_REQUEST",RPC_CODE_QUEST_COMPLETEQUEST_REQUEST)
end
function CompleteAcceptChatMenu(self,QuestConfigId,_hanlder)
	local PB = self.rpc_pb.QuestRpcCompleteAcceptChatMenuAsk()
	PB.QuestConfigId = QuestConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST",RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcCompleteAcceptChatMenuReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => CompleteAcceptChatMenu ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST",RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST)
end
function AcceptQuest(self,Type,QuestConfigId,_hanlder)
	local PB = self.rpc_pb.QuestRpcAcceptQuestAsk()
	PB.Type = Type
	PB.QuestConfigId = QuestConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_ACCEPTQUEST_REQUEST",RPC_CODE_QUEST_ACCEPTQUEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcAcceptQuestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => AcceptQuest ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_ACCEPTQUEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_ACCEPTQUEST_REQUEST",RPC_CODE_QUEST_ACCEPTQUEST_REQUEST)
end
function SyncQuest(self,_hanlder)
	local PB = self.rpc_pb.QuestRpcSyncQuestAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_SYNCQUEST_REQUEST",RPC_CODE_QUEST_SYNCQUEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcSyncQuestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => SyncQuest ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_SYNCQUEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_SYNCQUEST_REQUEST",RPC_CODE_QUEST_SYNCQUEST_REQUEST)
end
function GetReward(self,QuestConfigId,_hanlder)
	local PB = self.rpc_pb.QuestRpcGetRewardAsk()
	PB.QuestConfigId = QuestConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_GETREWARD_REQUEST",RPC_CODE_QUEST_GETREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcGetRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => GetReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_GETREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_GETREWARD_REQUEST",RPC_CODE_QUEST_GETREWARD_REQUEST)
end
function GetQuestData(self,QuestConfigId,_hanlder)
	local PB = self.rpc_pb.QuestRpcGetQuestDataAsk()
	for i,v in ipairs(QuestConfigId) do
		table.insert(PB.QuestConfigId,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_GETQUESTDATA_REQUEST",RPC_CODE_QUEST_GETQUESTDATA_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcGetQuestDataReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => GetQuestData ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_GETQUESTDATA_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_GETQUESTDATA_REQUEST",RPC_CODE_QUEST_GETQUESTDATA_REQUEST)
end
function SyncDailyQuest(self,_hanlder)
	local PB = self.rpc_pb.QuestRpcSyncDailyQuestAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST",RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcSyncDailyQuestReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => SyncDailyQuest ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST",RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST)
end
function ConsumeItem(self,QuestConfigId,ItemData,_hanlder)
	local PB = self.rpc_pb.QuestRpcConsumeItemAsk()
	PB.QuestConfigId = QuestConfigId
	for i,v in ipairs(ItemData) do
		table.insert(PB.ItemData,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_CONSUMEITEM_REQUEST",RPC_CODE_QUEST_CONSUMEITEM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcConsumeItemReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => ConsumeItem ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_CONSUMEITEM_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_CONSUMEITEM_REQUEST",RPC_CODE_QUEST_CONSUMEITEM_REQUEST)
end
function SyncCompleteQuestIds(self,_hanlder)
	local PB = self.rpc_pb.QuestRpcSyncCompleteQuestIdsAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST",RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcSyncCompleteQuestIdsReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => SyncCompleteQuestIds ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST",RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST)
end
function EliteFinishCount(self,_hanlder)
	local PB = self.rpc_pb.QuestRpcEliteFinishCountAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST",RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.QuestRpcEliteFinishCountReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Quest => EliteFinishCount ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST",RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerOnAcceptQuestCBNotify(self,_hanlder)
	if not self.OnAcceptQuestCBNotifyCallBack then
		self.OnAcceptQuestCBNotifyCallBack = {}
	end
	table.insert(self.OnAcceptQuestCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OnAcceptQuestCB(self,notifyMsg)
	if self.OnAcceptQuestCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcOnAcceptQuestNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OnAcceptQuestCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOnAcceptQuestCBNotify(self,_hanlder)
	if nil ~= self.OnAcceptQuestCBNotifyCallBack then
		for i,callback in ipairs(self.OnAcceptQuestCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OnAcceptQuestCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerOnCompleteQuestCBNotify(self,_hanlder)
	if not self.OnCompleteQuestCBNotifyCallBack then
		self.OnCompleteQuestCBNotifyCallBack = {}
	end
	table.insert(self.OnCompleteQuestCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OnCompleteQuestCB(self,notifyMsg)
	if self.OnCompleteQuestCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcOnCompleteQuestNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OnCompleteQuestCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOnCompleteQuestCBNotify(self,_hanlder)
	if nil ~= self.OnCompleteQuestCBNotifyCallBack then
		for i,callback in ipairs(self.OnCompleteQuestCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OnCompleteQuestCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateQuestCBNotify(self,_hanlder)
	if not self.UpdateQuestCBNotifyCallBack then
		self.UpdateQuestCBNotifyCallBack = {}
	end
	table.insert(self.UpdateQuestCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateQuestCB(self,notifyMsg)
	if self.UpdateQuestCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcUpdateQuestNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateQuestCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateQuestCBNotify(self,_hanlder)
	if nil ~= self.UpdateQuestCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateQuestCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateQuestCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRemoveQuestNotifyCBNotify(self,_hanlder)
	if not self.RemoveQuestNotifyCBNotifyCallBack then
		self.RemoveQuestNotifyCBNotifyCallBack = {}
	end
	table.insert(self.RemoveQuestNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RemoveQuestNotifyCB(self,notifyMsg)
	if self.RemoveQuestNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcRemoveQuestNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RemoveQuestNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRemoveQuestNotifyCBNotify(self,_hanlder)
	if nil ~= self.RemoveQuestNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.RemoveQuestNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RemoveQuestNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDailyQuestUpdateCBNotify(self,_hanlder)
	if not self.DailyQuestUpdateCBNotifyCallBack then
		self.DailyQuestUpdateCBNotifyCallBack = {}
	end
	table.insert(self.DailyQuestUpdateCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DailyQuestUpdateCB(self,notifyMsg)
	if self.DailyQuestUpdateCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcDailyQuestUpdateNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DailyQuestUpdateCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDailyQuestUpdateCBNotify(self,_hanlder)
	if nil ~= self.DailyQuestUpdateCBNotifyCallBack then
		for i,callback in ipairs(self.DailyQuestUpdateCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DailyQuestUpdateCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCompleteQuestIdsNotifyCBNotify(self,_hanlder)
	if not self.CompleteQuestIdsNotifyCBNotifyCallBack then
		self.CompleteQuestIdsNotifyCBNotifyCallBack = {}
	end
	table.insert(self.CompleteQuestIdsNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CompleteQuestIdsNotifyCB(self,notifyMsg)
	if self.CompleteQuestIdsNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcCompleteQuestIdsNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CompleteQuestIdsNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCompleteQuestIdsNotifyCBNotify(self,_hanlder)
	if nil ~= self.CompleteQuestIdsNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.CompleteQuestIdsNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CompleteQuestIdsNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSyncCanAcceptQuestCBNotify(self,_hanlder)
	if not self.SyncCanAcceptQuestCBNotifyCallBack then
		self.SyncCanAcceptQuestCBNotifyCallBack = {}
	end
	table.insert(self.SyncCanAcceptQuestCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SyncCanAcceptQuestCB(self,notifyMsg)
	if self.SyncCanAcceptQuestCBNotifyCallBack then
		local ret_msg = self.rpc_pb.QuestRpcSyncCanAcceptQuestNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncCanAcceptQuestCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSyncCanAcceptQuestCBNotify(self,_hanlder)
	if nil ~= self.SyncCanAcceptQuestCBNotifyCallBack then
		for i,callback in ipairs(self.SyncCanAcceptQuestCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncCanAcceptQuestCBNotifyCallBack, i )
			end
		end
	end
end





askList.Quest = {}

local t = {}
t.name = "CompleteQuestStep"
t.para = {{name="QuestConfigId",t=1},{name="QuestStep",t=1},{name="TargetId",t=1},{name="QuestStepEventType",t=1}}
t.hand = QuestModel.CompleteQuestStep
t.pb = QuestRpc_pb.QuestRpcCompleteQuestStepAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "GiveUpQuest"
t.para = {{name="QuestConfigId",t=1}}
t.hand = QuestModel.GiveUpQuest
t.pb = QuestRpc_pb.QuestRpcGiveUpQuestAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "CompleteQuest"
t.para = {{name="QuestConfigId",t=1},{name="TargetId",t=1},{name="QuestEventType",t=1}}
t.hand = QuestModel.CompleteQuest
t.pb = QuestRpc_pb.QuestRpcCompleteQuestAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "CompleteAcceptChatMenu"
t.para = {{name="QuestConfigId",t=1}}
t.hand = QuestModel.CompleteAcceptChatMenu
t.pb = QuestRpc_pb.QuestRpcCompleteAcceptChatMenuAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "AcceptQuest"
t.para = {{name="Type",t=1},{name="QuestConfigId",t=1}}
t.hand = QuestModel.AcceptQuest
t.pb = QuestRpc_pb.QuestRpcAcceptQuestAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "SyncQuest"
t.para = {}
t.hand = QuestModel.SyncQuest
t.pb = QuestRpc_pb.QuestRpcSyncQuestAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "GetReward"
t.para = {{name="QuestConfigId",t=1}}
t.hand = QuestModel.GetReward
t.pb = QuestRpc_pb.QuestRpcGetRewardAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "GetQuestData"
t.para = {{name="QuestConfigId",t=1}}
t.hand = QuestModel.GetQuestData
t.pb = QuestRpc_pb.QuestRpcGetQuestDataAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "SyncDailyQuest"
t.para = {}
t.hand = QuestModel.SyncDailyQuest
t.pb = QuestRpc_pb.QuestRpcSyncDailyQuestAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "ConsumeItem"
t.para = {{name="QuestConfigId",t=1},{name="ItemData",t=3}}
t.hand = QuestModel.ConsumeItem
t.pb = QuestRpc_pb.QuestRpcConsumeItemAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "SyncCompleteQuestIds"
t.para = {}
t.hand = QuestModel.SyncCompleteQuestIds
t.pb = QuestRpc_pb.QuestRpcSyncCompleteQuestIdsAsk()
table.insert(askList.Quest,t)

local t = {}
t.name = "EliteFinishCount"
t.para = {}
t.hand = QuestModel.EliteFinishCount
t.pb = QuestRpc_pb.QuestRpcEliteFinishCountAsk()
table.insert(askList.Quest,t)

