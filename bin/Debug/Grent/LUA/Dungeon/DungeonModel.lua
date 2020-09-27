-- DungeonModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

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
local RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST = 664
local RPC_CODE_DUNGEON_FORCEENTERNEXTDUNGEONLAYER_NOTIFY = 665;
local RPC_CODE_DUNGEON_DUNGEONREWARDUPDATE_NOTIFY = 666;
local RPC_CODE_DUNGEON_VICTORYOFALLLAYER_NOTIFY = 667;
local RPC_CODE_DUNGEON_LAYERBEGIN_NOTIFY = 668;
local RPC_CODE_DUNGEON_LAYERSETTLEMENT_NOTIFY = 669;
local RPC_CODE_DUNGEON_SCENEOPERATORN_NOTIFY = 670;
local RPC_CODE_DUNGEON_ENTERLAYERDUNGEON_NOTIFY = 671;
local RPC_CODE_DUNGEON_DUNGEONEXPLOITS_NOTIFY = 672;
local RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST = 673
local RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST = 674



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

local function showNetTip(self,...)
	Event.Brocast(NetE.Ask,...)
end

local function hideNetTip(self,...)
	Event.Brocast(NetE.Reply,...)
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function Initialize(self)
	self.rpc_pb = DungeonRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY,handler(self,self.SettlementCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY,handler(self,self.DungeonDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY,handler(self,self.DungeonTargetCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY,handler(self,self.TargetContentChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY,handler(self,self.Dungeon_NotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_FORCEENTERNEXTDUNGEONLAYER_NOTIFY,handler(self,self.ForceEnterNextDungeonLayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONREWARDUPDATE_NOTIFY,handler(self,self.DungeonRewardUpdateCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_VICTORYOFALLLAYER_NOTIFY,handler(self,self.VictoryOfAllLayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_LAYERBEGIN_NOTIFY,handler(self,self.LayerBeginCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_LAYERSETTLEMENT_NOTIFY,handler(self,self.LayerSettlementCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_SCENEOPERATORN_NOTIFY,handler(self,self.SceneOperatorNCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_ENTERLAYERDUNGEON_NOTIFY,handler(self,self.EnterLayerDungeonCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_DUNGEONEXPLOITS_NOTIFY,handler(self,self.DungeonExploitsCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function CreateDungeon(self,RoleId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateDungeonAsk()
	PB.RoleId = RoleId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST',RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => CreateDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST',RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST)
end
function ExitDungeon(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcExitDungeonAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST',RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcExitDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => ExitDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST',RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST)
end
function EnterDungeon(self,SceneId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcEnterDungeonAsk()
	PB.SceneId = SceneId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST',RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcEnterDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => EnterDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST',RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST)
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
		hideNetTip(self,'RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST',RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcInformCreateDungeonReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => InformCreateDungeon ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST',RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST)
end
function DungeonSync(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcDungeonSyncAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST',RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcDungeonSyncReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => DungeonSync ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST',RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST)
end
function DungeonListInfo(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcDungeonListInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST',RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcDungeonListInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => DungeonListInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST',RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST)
end
function CreateTutorial(self,RoleId,DungeonConfigId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateTutorialAsk()
	PB.RoleId = RoleId
	PB.DungeonConfigId = DungeonConfigId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST',RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateTutorialReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => CreateTutorial ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST',RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST)
end
function QuitTutorial(self,_hanlder)
	local PB = self.rpc_pb.DungeonRpcQuitTutorialAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST',RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcQuitTutorialReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => QuitTutorial ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST',RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST)
end
function SceneOperator1(self,OpCode,OpExtraParam,_hanlder)
	local PB = self.rpc_pb.DungeonRpcSceneOperator1Ask()
	PB.OpCode = OpCode
	PB.OpExtraParam = OpExtraParam
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST',RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcSceneOperator1Reply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => SceneOperator1 ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST',RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST)
end
function CreateDungeonWithRobot(self,DungeonConfigId,RoleId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcCreateDungeonWithRobotAsk()
	PB.DungeonConfigId = DungeonConfigId
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST',RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcCreateDungeonWithRobotReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => CreateDungeonWithRobot ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST',RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST)
end
function UseBossNum(self,BUse,_hanlder)
	local PB = self.rpc_pb.DungeonRpcUseBossNumAsk()
	PB.BUse = BUse
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST',RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcUseBossNumReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Dungeon => UseBossNum ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST',RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST)
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
-- 给c层 注册服务器通知回调
function registerForceEnterNextDungeonLayerCBNotify(self,_hanlder)
	if not self.ForceEnterNextDungeonLayerCBNotifyCallBack then
		self.ForceEnterNextDungeonLayerCBNotifyCallBack = {}
	end
	table.insert(self.ForceEnterNextDungeonLayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ForceEnterNextDungeonLayerCB(self,notifyMsg)
	if self.ForceEnterNextDungeonLayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcForceEnterNextDungeonLayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ForceEnterNextDungeonLayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterForceEnterNextDungeonLayerCBNotify(self,_hanlder)
	if nil ~= self.ForceEnterNextDungeonLayerCBNotifyCallBack then
		for i,callback in ipairs(self.ForceEnterNextDungeonLayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ForceEnterNextDungeonLayerCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDungeonRewardUpdateCBNotify(self,_hanlder)
	if not self.DungeonRewardUpdateCBNotifyCallBack then
		self.DungeonRewardUpdateCBNotifyCallBack = {}
	end
	table.insert(self.DungeonRewardUpdateCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonRewardUpdateCB(self,notifyMsg)
	if self.DungeonRewardUpdateCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcDungeonRewardUpdateNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DungeonRewardUpdateCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDungeonRewardUpdateCBNotify(self,_hanlder)
	if nil ~= self.DungeonRewardUpdateCBNotifyCallBack then
		for i,callback in ipairs(self.DungeonRewardUpdateCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DungeonRewardUpdateCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerVictoryOfAllLayerCBNotify(self,_hanlder)
	if not self.VictoryOfAllLayerCBNotifyCallBack then
		self.VictoryOfAllLayerCBNotifyCallBack = {}
	end
	table.insert(self.VictoryOfAllLayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function VictoryOfAllLayerCB(self,notifyMsg)
	if self.VictoryOfAllLayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcVictoryOfAllLayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.VictoryOfAllLayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterVictoryOfAllLayerCBNotify(self,_hanlder)
	if nil ~= self.VictoryOfAllLayerCBNotifyCallBack then
		for i,callback in ipairs(self.VictoryOfAllLayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.VictoryOfAllLayerCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLayerBeginCBNotify(self,_hanlder)
	if not self.LayerBeginCBNotifyCallBack then
		self.LayerBeginCBNotifyCallBack = {}
	end
	table.insert(self.LayerBeginCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LayerBeginCB(self,notifyMsg)
	if self.LayerBeginCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcLayerBeginNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LayerBeginCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLayerBeginCBNotify(self,_hanlder)
	if nil ~= self.LayerBeginCBNotifyCallBack then
		for i,callback in ipairs(self.LayerBeginCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LayerBeginCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerLayerSettlementCBNotify(self,_hanlder)
	if not self.LayerSettlementCBNotifyCallBack then
		self.LayerSettlementCBNotifyCallBack = {}
	end
	table.insert(self.LayerSettlementCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LayerSettlementCB(self,notifyMsg)
	if self.LayerSettlementCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcLayerSettlementNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LayerSettlementCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterLayerSettlementCBNotify(self,_hanlder)
	if nil ~= self.LayerSettlementCBNotifyCallBack then
		for i,callback in ipairs(self.LayerSettlementCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LayerSettlementCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSceneOperatorNCBNotify(self,_hanlder)
	if not self.SceneOperatorNCBNotifyCallBack then
		self.SceneOperatorNCBNotifyCallBack = {}
	end
	table.insert(self.SceneOperatorNCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SceneOperatorNCB(self,notifyMsg)
	if self.SceneOperatorNCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcSceneOperatorNNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SceneOperatorNCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSceneOperatorNCBNotify(self,_hanlder)
	if nil ~= self.SceneOperatorNCBNotifyCallBack then
		for i,callback in ipairs(self.SceneOperatorNCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SceneOperatorNCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerEnterLayerDungeonCBNotify(self,_hanlder)
	if not self.EnterLayerDungeonCBNotifyCallBack then
		self.EnterLayerDungeonCBNotifyCallBack = {}
	end
	table.insert(self.EnterLayerDungeonCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function EnterLayerDungeonCB(self,notifyMsg)
	if self.EnterLayerDungeonCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcEnterLayerDungeonNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.EnterLayerDungeonCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterEnterLayerDungeonCBNotify(self,_hanlder)
	if nil ~= self.EnterLayerDungeonCBNotifyCallBack then
		for i,callback in ipairs(self.EnterLayerDungeonCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.EnterLayerDungeonCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDungeonExploitsCBNotify(self,_hanlder)
	if not self.DungeonExploitsCBNotifyCallBack then
		self.DungeonExploitsCBNotifyCallBack = {}
	end
	table.insert(self.DungeonExploitsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonExploitsCB(self,notifyMsg)
	if self.DungeonExploitsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcDungeonExploitsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DungeonExploitsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDungeonExploitsCBNotify(self,_hanlder)
	if nil ~= self.DungeonExploitsCBNotifyCallBack then
		for i,callback in ipairs(self.DungeonExploitsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DungeonExploitsCBNotifyCallBack, i )
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

local t = {}
t.name = "SceneOperator1"
t.para = {{name="OpCode",t=1},{name="OpExtraParam",t=1}}
t.hand = DungeonModel.SceneOperator1
t.pb = DungeonRpc_pb.DungeonRpcSceneOperator1Ask()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "CreateDungeonWithRobot"
t.para = {{name="DungeonConfigId",t=1},{name="RoleId",t=1}}
t.hand = DungeonModel.CreateDungeonWithRobot
t.pb = DungeonRpc_pb.DungeonRpcCreateDungeonWithRobotAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "UseBossNum"
t.para = {{name="BUse",t=3}}
t.hand = DungeonModel.UseBossNum
t.pb = DungeonRpc_pb.DungeonRpcUseBossNumAsk()
table.insert(askList.Dungeon,t)

--]]

