--将变量写入下方
local ModuleId = 26;
local RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST = 2651
local RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY = 2652;
local RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY = 2653;
local RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY = 2654;
local RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST = 2655
local RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY = 2656;
local RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST = 2657
local RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST = 2658
local RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY = 2659;
local RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST = 2660
local RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST = 2661
local RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST = 2662





require("app.CampFigth.CampFigthRpc_pb")

CampFigthModel = class("CampFigthModel",BaseModel)

function CampFigthModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=CampFigthModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function CampFigthModel:ctor()
	CampFigthModel.super.ctor(self)
	self.rpc_pb = CampFigthRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY,handler(self,self.CampFightContributionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY,handler(self,self.ObjKillBroadcastCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY,handler(self,self.NpcBirthCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY,handler(self,self.KillDeadInfoCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY,handler(self,self.NewSeasonCB))

  


end

-- 更新数据
function CampFigthModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function MilitaryBroken(self,RoleID,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcMilitaryBrokenAsk()
	PB.RoleID = RoleID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST",RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcMilitaryBrokenReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => MilitaryBroken ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST",RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST)
end
function GetMilitaryValue(self,RoleID,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcGetMilitaryValueAsk()
	PB.RoleID = RoleID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST",RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcGetMilitaryValueReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => GetMilitaryValue ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST",RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST)
end
function Worship(self,WorshipRoleID,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcWorshipAsk()
	PB.WorshipRoleID = WorshipRoleID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST",RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcWorshipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => Worship ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST",RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST)
end
function WorshipRank(self,RoleID,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcWorshipRankAsk()
	PB.RoleID = RoleID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST",RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcWorshipRankReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => WorshipRank ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST",RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST)
end
function SyncRankReward(self,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcSyncRankRewardAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST",RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcSyncRankRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => SyncRankReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST",RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST)
end
function GetRankReward(self,Rank,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcGetRankRewardAsk()
	PB.Rank = Rank
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST",RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcGetRankRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => GetRankReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST",RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST)
end
function EnterBattleScene(self,_hanlder)
	local PB = self.rpc_pb.CampFigthRpcEnterBattleSceneAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST",RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.CampFigthRpcEnterBattleSceneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[CampFigth => EnterBattleScene ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST",RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerCampFightContributionCBNotify(self,_hanlder)
	if not self.CampFightContributionCBNotifyCallBack then
		self.CampFightContributionCBNotifyCallBack = {}
	end
	table.insert(self.CampFightContributionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CampFightContributionCB(self,notifyMsg)
	if self.CampFightContributionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CampFigthRpcCampFightContributionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CampFightContributionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCampFightContributionCBNotify(self,_hanlder)
	if nil ~= self.CampFightContributionCBNotifyCallBack then
		for i,callback in ipairs(self.CampFightContributionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CampFightContributionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerObjKillBroadcastCBNotify(self,_hanlder)
	if not self.ObjKillBroadcastCBNotifyCallBack then
		self.ObjKillBroadcastCBNotifyCallBack = {}
	end
	table.insert(self.ObjKillBroadcastCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ObjKillBroadcastCB(self,notifyMsg)
	if self.ObjKillBroadcastCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CampFigthRpcObjKillBroadcastNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ObjKillBroadcastCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterObjKillBroadcastCBNotify(self,_hanlder)
	if nil ~= self.ObjKillBroadcastCBNotifyCallBack then
		for i,callback in ipairs(self.ObjKillBroadcastCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ObjKillBroadcastCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNpcBirthCBNotify(self,_hanlder)
	if not self.NpcBirthCBNotifyCallBack then
		self.NpcBirthCBNotifyCallBack = {}
	end
	table.insert(self.NpcBirthCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NpcBirthCB(self,notifyMsg)
	if self.NpcBirthCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CampFigthRpcNpcBirthNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NpcBirthCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNpcBirthCBNotify(self,_hanlder)
	if nil ~= self.NpcBirthCBNotifyCallBack then
		for i,callback in ipairs(self.NpcBirthCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NpcBirthCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerKillDeadInfoCBNotify(self,_hanlder)
	if not self.KillDeadInfoCBNotifyCallBack then
		self.KillDeadInfoCBNotifyCallBack = {}
	end
	table.insert(self.KillDeadInfoCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function KillDeadInfoCB(self,notifyMsg)
	if self.KillDeadInfoCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CampFigthRpcKillDeadInfoNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.KillDeadInfoCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterKillDeadInfoCBNotify(self,_hanlder)
	if nil ~= self.KillDeadInfoCBNotifyCallBack then
		for i,callback in ipairs(self.KillDeadInfoCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.KillDeadInfoCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNewSeasonCBNotify(self,_hanlder)
	if not self.NewSeasonCBNotifyCallBack then
		self.NewSeasonCBNotifyCallBack = {}
	end
	table.insert(self.NewSeasonCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewSeasonCB(self,notifyMsg)
	if self.NewSeasonCBNotifyCallBack then
		local ret_msg = self.rpc_pb.CampFigthRpcNewSeasonNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewSeasonCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewSeasonCBNotify(self,_hanlder)
	if nil ~= self.NewSeasonCBNotifyCallBack then
		for i,callback in ipairs(self.NewSeasonCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewSeasonCBNotifyCallBack, i )
			end
		end
	end
end





askList.CampFigth = {}

local t = {}
t.name = "MilitaryBroken"
t.para = {{name="RoleID",t=1}}
t.hand = CampFigthModel.MilitaryBroken
t.pb = CampFigthRpc_pb.CampFigthRpcMilitaryBrokenAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "GetMilitaryValue"
t.para = {{name="RoleID",t=1}}
t.hand = CampFigthModel.GetMilitaryValue
t.pb = CampFigthRpc_pb.CampFigthRpcGetMilitaryValueAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "Worship"
t.para = {{name="WorshipRoleID",t=1}}
t.hand = CampFigthModel.Worship
t.pb = CampFigthRpc_pb.CampFigthRpcWorshipAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "WorshipRank"
t.para = {{name="RoleID",t=1}}
t.hand = CampFigthModel.WorshipRank
t.pb = CampFigthRpc_pb.CampFigthRpcWorshipRankAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "SyncRankReward"
t.para = {}
t.hand = CampFigthModel.SyncRankReward
t.pb = CampFigthRpc_pb.CampFigthRpcSyncRankRewardAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "GetRankReward"
t.para = {{name="Rank",t=1}}
t.hand = CampFigthModel.GetRankReward
t.pb = CampFigthRpc_pb.CampFigthRpcGetRankRewardAsk()
table.insert(askList.CampFigth,t)

local t = {}
t.name = "EnterBattleScene"
t.para = {}
t.hand = CampFigthModel.EnterBattleScene
t.pb = CampFigthRpc_pb.CampFigthRpcEnterBattleSceneAsk()
table.insert(askList.CampFigth,t)

