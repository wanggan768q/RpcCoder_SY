--将变量写入下方
local ModuleId = 34;
local RPC_CODE_PVP_RANK_REQUEST = 3451
local RPC_CODE_PVP_MATCH_REQUEST = 3452
local RPC_CODE_PVP_MATCHNOTIFY_NOTIFY = 3453;
local RPC_CODE_PVP_MATCHCANCLE_REQUEST = 3454
local RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY = 3455;
local RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST = 3456
local RPC_CODE_PVP_PVPBATTLESTART_NOTIFY = 3457;
local RPC_CODE_PVP_PVPBATTLEEND_NOTIFY = 3458;
local RPC_CODE_PVP_PLAYERREADY_REQUEST = 3459
local RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY = 3460;
local RPC_CODE_PVP_READYFAILD_NOTIFY = 3461;
local RPC_CODE_PVP_MATCHSUCESS_NOTIFY = 3462;
local RPC_CODE_PVP_RANKCHANGE_NOTIFY = 3463;
local RPC_CODE_PVP_RETURNLASTSCENE_REQUEST = 3464
local RPC_CODE_PVP_ARENASTARTTIME_NOTIFY = 3465;
local RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY = 3466;
local RPC_CODE_PVP_ARENALEFTTIME_NOTIFY = 3467;
local RPC_CODE_PVP_LASTRANK_REQUEST = 3468
local RPC_CODE_PVP_NEWSEASON_NOTIFY = 3469;
local RPC_CODE_PVP_GETSEASONREWARD_REQUEST = 3470
local RPC_CODE_PVP_RECONNECT_NOTIFY = 3471;
local RPC_CODE_PVP_GETREWARD_REQUEST = 3472





require("app.Pvp.PvpRpc_pb")

PvpModel = class("PvpModel",BaseModel)

function PvpModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=PvpModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function PvpModel:ctor()
	PvpModel.super.ctor(self)
	self.rpc_pb = PvpRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_MATCHNOTIFY_NOTIFY,handler(self,self.MatchNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY,handler(self,self.MatchCancleNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_PVPBATTLESTART_NOTIFY,handler(self,self.PvpBattleStartCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_PVPBATTLEEND_NOTIFY,handler(self,self.PvpBattleEndCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY,handler(self,self.PlayerReadyNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_READYFAILD_NOTIFY,handler(self,self.ReadyFaildCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_MATCHSUCESS_NOTIFY,handler(self,self.MatchSucessCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_RANKCHANGE_NOTIFY,handler(self,self.RankChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_ARENASTARTTIME_NOTIFY,handler(self,self.ArenaStartTimeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY,handler(self,self.UpdateKillCountCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_ARENALEFTTIME_NOTIFY,handler(self,self.ArenaLeftTimeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_NEWSEASON_NOTIFY,handler(self,self.NewSeasonCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_PVP_RECONNECT_NOTIFY,handler(self,self.ReconnectCB))

  


end

-- 更新数据
function PvpModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Rank(self,PvpType,_hanlder)
	local PB = self.rpc_pb.PvpRpcRankAsk()
	PB.PvpType = PvpType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_RANK_REQUEST",RPC_CODE_PVP_RANK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcRankReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => Rank ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_RANK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_RANK_REQUEST",RPC_CODE_PVP_RANK_REQUEST)
end
function Match(self,PvpType,_hanlder)
	local PB = self.rpc_pb.PvpRpcMatchAsk()
	PB.PvpType = PvpType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_MATCH_REQUEST",RPC_CODE_PVP_MATCH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcMatchReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => Match ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_MATCH_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_MATCH_REQUEST",RPC_CODE_PVP_MATCH_REQUEST)
end
function MatchCancle(self,_hanlder)
	local PB = self.rpc_pb.PvpRpcMatchCancleAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_MATCHCANCLE_REQUEST",RPC_CODE_PVP_MATCHCANCLE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcMatchCancleReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => MatchCancle ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_MATCHCANCLE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_MATCHCANCLE_REQUEST",RPC_CODE_PVP_MATCHCANCLE_REQUEST)
end
function PvpBattleInfoSync(self,_hanlder)
	local PB = self.rpc_pb.PvpRpcPvpBattleInfoSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST",RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcPvpBattleInfoSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => PvpBattleInfoSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST",RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST)
end
function PlayerReady(self,OpreationType,_hanlder)
	local PB = self.rpc_pb.PvpRpcPlayerReadyAsk()
	PB.OpreationType = OpreationType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_PLAYERREADY_REQUEST",RPC_CODE_PVP_PLAYERREADY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcPlayerReadyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => PlayerReady ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_PLAYERREADY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_PLAYERREADY_REQUEST",RPC_CODE_PVP_PLAYERREADY_REQUEST)
end
function ReturnLastScene(self,_hanlder)
	local PB = self.rpc_pb.PvpRpcReturnLastSceneAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_RETURNLASTSCENE_REQUEST",RPC_CODE_PVP_RETURNLASTSCENE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcReturnLastSceneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => ReturnLastScene ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_RETURNLASTSCENE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_RETURNLASTSCENE_REQUEST",RPC_CODE_PVP_RETURNLASTSCENE_REQUEST)
end
function LastRank(self,PvpType,_hanlder)
	local PB = self.rpc_pb.PvpRpcLastRankAsk()
	PB.PvpType = PvpType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_LASTRANK_REQUEST",RPC_CODE_PVP_LASTRANK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcLastRankReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => LastRank ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_LASTRANK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_LASTRANK_REQUEST",RPC_CODE_PVP_LASTRANK_REQUEST)
end
function GetSeasonReward(self,_hanlder)
	local PB = self.rpc_pb.PvpRpcGetSeasonRewardAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_GETSEASONREWARD_REQUEST",RPC_CODE_PVP_GETSEASONREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcGetSeasonRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => GetSeasonReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_GETSEASONREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_GETSEASONREWARD_REQUEST",RPC_CODE_PVP_GETSEASONREWARD_REQUEST)
end
function GetReward(self,PvPType,Rank,_hanlder)
	local PB = self.rpc_pb.PvpRpcGetRewardAsk()
	PB.PvPType = PvPType
	PB.Rank = Rank
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_PVP_GETREWARD_REQUEST",RPC_CODE_PVP_GETREWARD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.PvpRpcGetRewardReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Pvp => GetReward ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PVP_GETREWARD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_PVP_GETREWARD_REQUEST",RPC_CODE_PVP_GETREWARD_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerMatchNotifyCBNotify(self,_hanlder)
	if not self.MatchNotifyCBNotifyCallBack then
		self.MatchNotifyCBNotifyCallBack = {}
	end
	table.insert(self.MatchNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MatchNotifyCB(self,notifyMsg)
	if self.MatchNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcMatchNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MatchNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMatchNotifyCBNotify(self,_hanlder)
	if nil ~= self.MatchNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.MatchNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MatchNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerMatchCancleNotifyCBNotify(self,_hanlder)
	if not self.MatchCancleNotifyCBNotifyCallBack then
		self.MatchCancleNotifyCBNotifyCallBack = {}
	end
	table.insert(self.MatchCancleNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MatchCancleNotifyCB(self,notifyMsg)
	if self.MatchCancleNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcMatchCancleNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MatchCancleNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMatchCancleNotifyCBNotify(self,_hanlder)
	if nil ~= self.MatchCancleNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.MatchCancleNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MatchCancleNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerPvpBattleStartCBNotify(self,_hanlder)
	if not self.PvpBattleStartCBNotifyCallBack then
		self.PvpBattleStartCBNotifyCallBack = {}
	end
	table.insert(self.PvpBattleStartCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PvpBattleStartCB(self,notifyMsg)
	if self.PvpBattleStartCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcPvpBattleStartNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PvpBattleStartCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPvpBattleStartCBNotify(self,_hanlder)
	if nil ~= self.PvpBattleStartCBNotifyCallBack then
		for i,callback in ipairs(self.PvpBattleStartCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PvpBattleStartCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerPvpBattleEndCBNotify(self,_hanlder)
	if not self.PvpBattleEndCBNotifyCallBack then
		self.PvpBattleEndCBNotifyCallBack = {}
	end
	table.insert(self.PvpBattleEndCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PvpBattleEndCB(self,notifyMsg)
	if self.PvpBattleEndCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcPvpBattleEndNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PvpBattleEndCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPvpBattleEndCBNotify(self,_hanlder)
	if nil ~= self.PvpBattleEndCBNotifyCallBack then
		for i,callback in ipairs(self.PvpBattleEndCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PvpBattleEndCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerPlayerReadyNotifyCBNotify(self,_hanlder)
	if not self.PlayerReadyNotifyCBNotifyCallBack then
		self.PlayerReadyNotifyCBNotifyCallBack = {}
	end
	table.insert(self.PlayerReadyNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function PlayerReadyNotifyCB(self,notifyMsg)
	if self.PlayerReadyNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcPlayerReadyNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PlayerReadyNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterPlayerReadyNotifyCBNotify(self,_hanlder)
	if nil ~= self.PlayerReadyNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.PlayerReadyNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PlayerReadyNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerReadyFaildCBNotify(self,_hanlder)
	if not self.ReadyFaildCBNotifyCallBack then
		self.ReadyFaildCBNotifyCallBack = {}
	end
	table.insert(self.ReadyFaildCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReadyFaildCB(self,notifyMsg)
	if self.ReadyFaildCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcReadyFaildNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReadyFaildCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReadyFaildCBNotify(self,_hanlder)
	if nil ~= self.ReadyFaildCBNotifyCallBack then
		for i,callback in ipairs(self.ReadyFaildCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReadyFaildCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerMatchSucessCBNotify(self,_hanlder)
	if not self.MatchSucessCBNotifyCallBack then
		self.MatchSucessCBNotifyCallBack = {}
	end
	table.insert(self.MatchSucessCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MatchSucessCB(self,notifyMsg)
	if self.MatchSucessCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcMatchSucessNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.MatchSucessCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterMatchSucessCBNotify(self,_hanlder)
	if nil ~= self.MatchSucessCBNotifyCallBack then
		for i,callback in ipairs(self.MatchSucessCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.MatchSucessCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRankChangeCBNotify(self,_hanlder)
	if not self.RankChangeCBNotifyCallBack then
		self.RankChangeCBNotifyCallBack = {}
	end
	table.insert(self.RankChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RankChangeCB(self,notifyMsg)
	if self.RankChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcRankChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RankChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRankChangeCBNotify(self,_hanlder)
	if nil ~= self.RankChangeCBNotifyCallBack then
		for i,callback in ipairs(self.RankChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RankChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerArenaStartTimeCBNotify(self,_hanlder)
	if not self.ArenaStartTimeCBNotifyCallBack then
		self.ArenaStartTimeCBNotifyCallBack = {}
	end
	table.insert(self.ArenaStartTimeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ArenaStartTimeCB(self,notifyMsg)
	if self.ArenaStartTimeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcArenaStartTimeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ArenaStartTimeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterArenaStartTimeCBNotify(self,_hanlder)
	if nil ~= self.ArenaStartTimeCBNotifyCallBack then
		for i,callback in ipairs(self.ArenaStartTimeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ArenaStartTimeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUpdateKillCountCBNotify(self,_hanlder)
	if not self.UpdateKillCountCBNotifyCallBack then
		self.UpdateKillCountCBNotifyCallBack = {}
	end
	table.insert(self.UpdateKillCountCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UpdateKillCountCB(self,notifyMsg)
	if self.UpdateKillCountCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcUpdateKillCountNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateKillCountCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUpdateKillCountCBNotify(self,_hanlder)
	if nil ~= self.UpdateKillCountCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateKillCountCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateKillCountCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerArenaLeftTimeCBNotify(self,_hanlder)
	if not self.ArenaLeftTimeCBNotifyCallBack then
		self.ArenaLeftTimeCBNotifyCallBack = {}
	end
	table.insert(self.ArenaLeftTimeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ArenaLeftTimeCB(self,notifyMsg)
	if self.ArenaLeftTimeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcArenaLeftTimeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ArenaLeftTimeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterArenaLeftTimeCBNotify(self,_hanlder)
	if nil ~= self.ArenaLeftTimeCBNotifyCallBack then
		for i,callback in ipairs(self.ArenaLeftTimeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ArenaLeftTimeCBNotifyCallBack, i )
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
		local ret_msg = self.rpc_pb.PvpRpcNewSeasonNotify() 
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
-- 给c层 注册服务器通知回调
function registerReconnectCBNotify(self,_hanlder)
	if not self.ReconnectCBNotifyCallBack then
		self.ReconnectCBNotifyCallBack = {}
	end
	table.insert(self.ReconnectCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReconnectCB(self,notifyMsg)
	if self.ReconnectCBNotifyCallBack then
		local ret_msg = self.rpc_pb.PvpRpcReconnectNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReconnectCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReconnectCBNotify(self,_hanlder)
	if nil ~= self.ReconnectCBNotifyCallBack then
		for i,callback in ipairs(self.ReconnectCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReconnectCBNotifyCallBack, i )
			end
		end
	end
end





askList.Pvp = {}

local t = {}
t.name = "Rank"
t.para = {{name="PvpType",t=1}}
t.hand = PvpModel.Rank
t.pb = PvpRpc_pb.PvpRpcRankAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "Match"
t.para = {{name="PvpType",t=1}}
t.hand = PvpModel.Match
t.pb = PvpRpc_pb.PvpRpcMatchAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "MatchCancle"
t.para = {}
t.hand = PvpModel.MatchCancle
t.pb = PvpRpc_pb.PvpRpcMatchCancleAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "PvpBattleInfoSync"
t.para = {}
t.hand = PvpModel.PvpBattleInfoSync
t.pb = PvpRpc_pb.PvpRpcPvpBattleInfoSyncAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "PlayerReady"
t.para = {{name="OpreationType",t=1}}
t.hand = PvpModel.PlayerReady
t.pb = PvpRpc_pb.PvpRpcPlayerReadyAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "ReturnLastScene"
t.para = {}
t.hand = PvpModel.ReturnLastScene
t.pb = PvpRpc_pb.PvpRpcReturnLastSceneAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "LastRank"
t.para = {{name="PvpType",t=1}}
t.hand = PvpModel.LastRank
t.pb = PvpRpc_pb.PvpRpcLastRankAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "GetSeasonReward"
t.para = {}
t.hand = PvpModel.GetSeasonReward
t.pb = PvpRpc_pb.PvpRpcGetSeasonRewardAsk()
table.insert(askList.Pvp,t)

local t = {}
t.name = "GetReward"
t.para = {{name="PvPType",t=1},{name="Rank",t=1}}
t.hand = PvpModel.GetReward
t.pb = PvpRpc_pb.PvpRpcGetRewardAsk()
table.insert(askList.Pvp,t)

