--将变量写入下方
local ModuleId = 6;
local RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST = 651
local RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST = 652
local RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST = 653
local RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654
local RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY = 655;
local RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY = 656;
local RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST = 657
local RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST = 658
local RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST = 659
local RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST = 660
local RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY = 661;
local RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY = 662;
local RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY = 663;





require("app.Dungeon.DungeonRpc_pb")

DungeonModel = class("DungeonModel",BaseModel)

function DungeonModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DungeonModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function DungeonModel:ctor()
	DungeonModel.super.ctor(self)
	self.rpc_pb = DungeonRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY,handler(self,self.SettlementCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY,handler(self,self.DungeonDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY,handler(self,self.DungeonTargetCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY,handler(self,self.TargetContentChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY,handler(self,self.Dungeon_NotifyCB))

  


end

-- 更新数据
function DungeonModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function CreateDungeon(self,RoleId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateDungeonAsk()
	PB.RoleId = RoleId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST",RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => CreateDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST",RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST)
end
function ExitDungeon(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcExitDungeonAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST",RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcExitDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => ExitDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST",RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST)
end
function EnterDungeon(self,SceneId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcEnterDungeonAsk()
	PB.SceneId = SceneId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST",RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcEnterDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => EnterDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST",RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST)
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
		hideNetTip(self,"RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST",RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcInformCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => InformCreateDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST",RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST)
end
function DungeonSync(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcDungeonSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST",RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcDungeonSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => DungeonSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST",RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST)
end
function DungeonListInfo(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcDungeonListInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST",RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcDungeonListInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => DungeonListInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST",RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST)
end
function CreateTutorial(self,RoleId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateTutorialAsk()
	PB.RoleId = RoleId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST",RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateTutorialReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => CreateTutorial ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST",RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST)
end
function QuitTutorial(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcQuitTutorialAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST",RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcQuitTutorialReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Dungeon => QuitTutorial ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST",RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST)
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
-- 给c层 注册服务器通知回调
function registerDungeonDataCBNotify(self,_hanlder)
	if not self.DungeonDataCBNotifyCallBack then
		self.DungeonDataCBNotifyCallBack = {}
	end
	table.insert(self.DungeonDataCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonDataCB(self,notifyMsg)
	if self.DungeonDataCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcDungeonDataNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DungeonDataCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDungeonDataCBNotify(self,_hanlder)
	if nil ~= self.DungeonDataCBNotifyCallBack then
		for i,callback in ipairs(self.DungeonDataCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DungeonDataCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDungeonTargetCBNotify(self,_hanlder)
	if not self.DungeonTargetCBNotifyCallBack then
		self.DungeonTargetCBNotifyCallBack = {}
	end
	table.insert(self.DungeonTargetCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonTargetCB(self,notifyMsg)
	if self.DungeonTargetCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcDungeonTargetNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DungeonTargetCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDungeonTargetCBNotify(self,_hanlder)
	if nil ~= self.DungeonTargetCBNotifyCallBack then
		for i,callback in ipairs(self.DungeonTargetCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DungeonTargetCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerTargetContentChangeCBNotify(self,_hanlder)
	if not self.TargetContentChangeCBNotifyCallBack then
		self.TargetContentChangeCBNotifyCallBack = {}
	end
	table.insert(self.TargetContentChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TargetContentChangeCB(self,notifyMsg)
	if self.TargetContentChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcTargetContentChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TargetContentChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterTargetContentChangeCBNotify(self,_hanlder)
	if nil ~= self.TargetContentChangeCBNotifyCallBack then
		for i,callback in ipairs(self.TargetContentChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TargetContentChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDungeon_NotifyCBNotify(self,_hanlder)
	if not self.Dungeon_NotifyCBNotifyCallBack then
		self.Dungeon_NotifyCBNotifyCallBack = {}
	end
	table.insert(self.Dungeon_NotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function Dungeon_NotifyCB(self,notifyMsg)
	if self.Dungeon_NotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcDungeon_NotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.Dungeon_NotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDungeon_NotifyCBNotify(self,_hanlder)
	if nil ~= self.Dungeon_NotifyCBNotifyCallBack then
		for i,callback in ipairs(self.Dungeon_NotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.Dungeon_NotifyCBNotifyCallBack, i )
			end
		end
	end
end





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

local t = {}
t.name = "DungeonSync"
t.para = {}
t.hand = DungeonModel.DungeonSync
t.pb = DungeonRpc_pb.DungeonRpcDungeonSyncAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "DungeonListInfo"
t.para = {}
t.hand = DungeonModel.DungeonListInfo
t.pb = DungeonRpc_pb.DungeonRpcDungeonListInfoAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "CreateTutorial"
t.para = {{name="RoleId",t=1},{name="DungeonConfigId",t=1}}
t.hand = DungeonModel.CreateTutorial
t.pb = DungeonRpc_pb.DungeonRpcCreateTutorialAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "QuitTutorial"
t.para = {}
t.hand = DungeonModel.QuitTutorial
t.pb = DungeonRpc_pb.DungeonRpcQuitTutorialAsk()
table.insert(askList.Dungeon,t)

