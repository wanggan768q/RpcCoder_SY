-- SceneModel.lua
--Author:郭晓波
--Email:ambitiongxb@foxmail.com
--2018年10月8日11:05:21

--将变量写入下方
local ModuleId = 3;
local RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST = 351
local RPC_CODE_SCENE_DELETEPLAYER_NOTIFY = 352;
local RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST = 353
local RPC_CODE_SCENE_CREATEOBJ_NOTIFY = 354;
local RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST = 355
local RPC_CODE_SCENE_CENTERSCENE_NOTIFY = 356;
local RPC_CODE_SCENE_SENTERSCENE_NOTIFY = 357;
local RPC_CODE_SCENE_OBJDIE_NOTIFY = 358;
local RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST = 359
local RPC_CODE_SCENE_ENTERMIRROR_REQUEST = 360
local RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY = 361;
local RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST = 362
local RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY = 363;
local RPC_CODE_SCENE_CHANGELINE_REQUEST = 364
local RPC_CODE_SCENE_PING_REQUEST = 365
local RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY = 366;
local RPC_CODE_SCENE_LOGOUTGAME_REQUEST = 367
local RPC_CODE_SCENE_KICKOUTGAME_NOTIFY = 368;
local RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST = 369
local RPC_CODE_SCENE_SPECOBJPOS_REQUEST = 370
local RPC_CODE_SCENE_DAYNIGHTCHANGE_NOTIFY = 371;
local RPC_CODE_SCENE_WEATHERCHANGE_NOTIFY = 372;
local RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST = 373
local RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST = 374



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
require("3rd/pblua/SceneRpc_pb")
local  SceneRpc_pb = SceneRpc_pb
module("SceneModel")





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
	self.rpc_pb = SceneRpc_pb
  --注册
  --MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_DELETEPLAYER_NOTIFY,handler(self,self.DeletePlayerCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_CREATEOBJ_NOTIFY,handler(self,self.CreateObjCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_SENTERSCENE_NOTIFY,handler(self,self.SEnterSceneCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_OBJDIE_NOTIFY,handler(self,self.ObjDieCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY,handler(self,self.SEnterMirrorSceneCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY,handler(self,self.ChangeSceneLeaveCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY,handler(self,self.SyncSceneLineStatsCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_KICKOUTGAME_NOTIFY,handler(self,self.KickOutGameCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_DAYNIGHTCHANGE_NOTIFY,handler(self,self.DayNightChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_SCENE_WEATHERCHANGE_NOTIFY,handler(self,self.WeatherChangeCB))

  


end

-- 更新数据
function UpdateField(self,uf,oldData,isNotify,isForceUpdate,main)

end


-- 业务事件
function LoadSceneComplete(self,RoleId,SceneId,_hanlder)
	local PB = self.rpc_pb.SceneRpcLoadSceneCompleteAsk()
	PB.RoleId = RoleId
	PB.SceneId = SceneId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST',RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcLoadSceneCompleteReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => LoadSceneComplete ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST',RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST)
end
function ConnectGameServer(self,RoleId,Key,SceneID,LineID,GameToken,_hanlder)
	local PB = self.rpc_pb.SceneRpcConnectGameServerAsk()
	PB.RoleId = RoleId
	PB.Key = Key
	PB.SceneID = SceneID
	PB.LineID = LineID
	PB.GameToken = GameToken
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST',RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcConnectGameServerReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => ConnectGameServer ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST',RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST)
end
function SurroundingHuman(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcSurroundingHumanAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST',RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcSurroundingHumanReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => SurroundingHuman ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST',RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST)
end
function Collide_ChangeScene(self,Collide_id,_hanlder)
	local PB = self.rpc_pb.SceneRpcCollide_ChangeSceneAsk()
	PB.Collide_id = Collide_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST',RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcCollide_ChangeSceneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => Collide_ChangeScene ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST',RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST)
end
function EnterMirror(self,MirrorID,_hanlder)
	local PB = self.rpc_pb.SceneRpcEnterMirrorAsk()
	PB.MirrorID = MirrorID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_ENTERMIRROR_REQUEST',RPC_CODE_SCENE_ENTERMIRROR_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcEnterMirrorReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => EnterMirror ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_ENTERMIRROR_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_ENTERMIRROR_REQUEST',RPC_CODE_SCENE_ENTERMIRROR_REQUEST)
end
function ExitMirrorScene(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcExitMirrorSceneAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST',RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcExitMirrorSceneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => ExitMirrorScene ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST',RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST)
end
function ChangeLine(self,LineID,MapID,_hanlder)
	local PB = self.rpc_pb.SceneRpcChangeLineAsk()
	PB.LineID = LineID
	PB.MapID = MapID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_CHANGELINE_REQUEST',RPC_CODE_SCENE_CHANGELINE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcChangeLineReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => ChangeLine ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_CHANGELINE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_CHANGELINE_REQUEST',RPC_CODE_SCENE_CHANGELINE_REQUEST)
end
function Ping(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcPingAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_PING_REQUEST',RPC_CODE_SCENE_PING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcPingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => Ping ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_PING_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_PING_REQUEST',RPC_CODE_SCENE_PING_REQUEST)
end
function LogOutGame(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcLogOutGameAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_LOGOUTGAME_REQUEST',RPC_CODE_SCENE_LOGOUTGAME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcLogOutGameReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => LogOutGame ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_LOGOUTGAME_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_LOGOUTGAME_REQUEST',RPC_CODE_SCENE_LOGOUTGAME_REQUEST)
end
function ShowFilmFinish(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcShowFilmFinishAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST',RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcShowFilmFinishReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => ShowFilmFinish ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST',RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST)
end
function SpecObjPos(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcSpecObjPosAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_SPECOBJPOS_REQUEST',RPC_CODE_SCENE_SPECOBJPOS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcSpecObjPosReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => SpecObjPos ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_SPECOBJPOS_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_SPECOBJPOS_REQUEST',RPC_CODE_SCENE_SPECOBJPOS_REQUEST)
end
function WantChangeZone(self,Zoneid,_hanlder)
	local PB = self.rpc_pb.SceneRpcWantChangeZoneAsk()
	PB.Zoneid = Zoneid
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST',RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcWantChangeZoneReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => WantChangeZone ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST',RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST)
end
function ReturnSrcServer(self,_hanlder)
	local PB = self.rpc_pb.SceneRpcReturnSrcServerAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,'RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST',RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.SceneRpcReturnSrcServerReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg,"[Scene => ReturnSrcServer ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST, pb_data, callback)
	showNetTip(self,'RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST',RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerDeletePlayerCBNotify(self,_hanlder)
	if not self.DeletePlayerCBNotifyCallBack then
		self.DeletePlayerCBNotifyCallBack = {}
	end
	table.insert(self.DeletePlayerCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DeletePlayerCB(self,notifyMsg)
	if self.DeletePlayerCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcDeletePlayerNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DeletePlayerCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDeletePlayerCBNotify(self,_hanlder)
	if nil ~= self.DeletePlayerCBNotifyCallBack then
		for i,callback in ipairs(self.DeletePlayerCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DeletePlayerCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerCreateObjCBNotify(self,_hanlder)
	if not self.CreateObjCBNotifyCallBack then
		self.CreateObjCBNotifyCallBack = {}
	end
	table.insert(self.CreateObjCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function CreateObjCB(self,notifyMsg)
	if self.CreateObjCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcCreateObjNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CreateObjCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterCreateObjCBNotify(self,_hanlder)
	if nil ~= self.CreateObjCBNotifyCallBack then
		for i,callback in ipairs(self.CreateObjCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CreateObjCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function CEnterSceneNotify(self,SceneId,MapId,LineId)
	local PB = self.rpc_pb.SceneRpcCEnterSceneNotify()
	PB.SceneId = SceneId
	PB.MapId = MapId
	PB.LineId = LineId
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_SCENE_CENTERSCENE_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function registerSEnterSceneCBNotify(self,_hanlder)
	if not self.SEnterSceneCBNotifyCallBack then
		self.SEnterSceneCBNotifyCallBack = {}
	end
	table.insert(self.SEnterSceneCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SEnterSceneCB(self,notifyMsg)
	if self.SEnterSceneCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcSEnterSceneNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SEnterSceneCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSEnterSceneCBNotify(self,_hanlder)
	if nil ~= self.SEnterSceneCBNotifyCallBack then
		for i,callback in ipairs(self.SEnterSceneCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SEnterSceneCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerObjDieCBNotify(self,_hanlder)
	if not self.ObjDieCBNotifyCallBack then
		self.ObjDieCBNotifyCallBack = {}
	end
	table.insert(self.ObjDieCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ObjDieCB(self,notifyMsg)
	if self.ObjDieCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcObjDieNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ObjDieCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterObjDieCBNotify(self,_hanlder)
	if nil ~= self.ObjDieCBNotifyCallBack then
		for i,callback in ipairs(self.ObjDieCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ObjDieCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSEnterMirrorSceneCBNotify(self,_hanlder)
	if not self.SEnterMirrorSceneCBNotifyCallBack then
		self.SEnterMirrorSceneCBNotifyCallBack = {}
	end
	table.insert(self.SEnterMirrorSceneCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SEnterMirrorSceneCB(self,notifyMsg)
	if self.SEnterMirrorSceneCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcSEnterMirrorSceneNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SEnterMirrorSceneCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSEnterMirrorSceneCBNotify(self,_hanlder)
	if nil ~= self.SEnterMirrorSceneCBNotifyCallBack then
		for i,callback in ipairs(self.SEnterMirrorSceneCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SEnterMirrorSceneCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerChangeSceneLeaveCBNotify(self,_hanlder)
	if not self.ChangeSceneLeaveCBNotifyCallBack then
		self.ChangeSceneLeaveCBNotifyCallBack = {}
	end
	table.insert(self.ChangeSceneLeaveCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChangeSceneLeaveCB(self,notifyMsg)
	if self.ChangeSceneLeaveCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcChangeSceneLeaveNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ChangeSceneLeaveCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterChangeSceneLeaveCBNotify(self,_hanlder)
	if nil ~= self.ChangeSceneLeaveCBNotifyCallBack then
		for i,callback in ipairs(self.ChangeSceneLeaveCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ChangeSceneLeaveCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSyncSceneLineStatsCBNotify(self,_hanlder)
	if not self.SyncSceneLineStatsCBNotifyCallBack then
		self.SyncSceneLineStatsCBNotifyCallBack = {}
	end
	table.insert(self.SyncSceneLineStatsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SyncSceneLineStatsCB(self,notifyMsg)
	if self.SyncSceneLineStatsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcSyncSceneLineStatsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncSceneLineStatsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSyncSceneLineStatsCBNotify(self,_hanlder)
	if nil ~= self.SyncSceneLineStatsCBNotifyCallBack then
		for i,callback in ipairs(self.SyncSceneLineStatsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncSceneLineStatsCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerKickOutGameCBNotify(self,_hanlder)
	if not self.KickOutGameCBNotifyCallBack then
		self.KickOutGameCBNotifyCallBack = {}
	end
	table.insert(self.KickOutGameCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function KickOutGameCB(self,notifyMsg)
	if self.KickOutGameCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcKickOutGameNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.KickOutGameCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterKickOutGameCBNotify(self,_hanlder)
	if nil ~= self.KickOutGameCBNotifyCallBack then
		for i,callback in ipairs(self.KickOutGameCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.KickOutGameCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDayNightChangeCBNotify(self,_hanlder)
	if not self.DayNightChangeCBNotifyCallBack then
		self.DayNightChangeCBNotifyCallBack = {}
	end
	table.insert(self.DayNightChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DayNightChangeCB(self,notifyMsg)
	if self.DayNightChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcDayNightChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DayNightChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDayNightChangeCBNotify(self,_hanlder)
	if nil ~= self.DayNightChangeCBNotifyCallBack then
		for i,callback in ipairs(self.DayNightChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DayNightChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerWeatherChangeCBNotify(self,_hanlder)
	if not self.WeatherChangeCBNotifyCallBack then
		self.WeatherChangeCBNotifyCallBack = {}
	end
	table.insert(self.WeatherChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function WeatherChangeCB(self,notifyMsg)
	if self.WeatherChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.SceneRpcWeatherChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.WeatherChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterWeatherChangeCBNotify(self,_hanlder)
	if nil ~= self.WeatherChangeCBNotifyCallBack then
		for i,callback in ipairs(self.WeatherChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.WeatherChangeCBNotifyCallBack, i )
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
askList.Scene = {}

local t = {}
t.name = "LoadSceneComplete"
t.para = {{name="RoleId",t=1},{name="SceneId",t=1}}
t.hand = SceneModel.LoadSceneComplete
t.pb = SceneRpc_pb.SceneRpcLoadSceneCompleteAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ConnectGameServer"
t.para = {{name="RoleId",t=1},{name="Key",t=2},{name="SceneID",t=1},{name="LineID",t=1},{name="GameToken",t=2}}
t.hand = SceneModel.ConnectGameServer
t.pb = SceneRpc_pb.SceneRpcConnectGameServerAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "SurroundingHuman"
t.para = {}
t.hand = SceneModel.SurroundingHuman
t.pb = SceneRpc_pb.SceneRpcSurroundingHumanAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "Collide_ChangeScene"
t.para = {{name="Collide_id",t=1}}
t.hand = SceneModel.Collide_ChangeScene
t.pb = SceneRpc_pb.SceneRpcCollide_ChangeSceneAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "EnterMirror"
t.para = {{name="MirrorID",t=1}}
t.hand = SceneModel.EnterMirror
t.pb = SceneRpc_pb.SceneRpcEnterMirrorAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ExitMirrorScene"
t.para = {}
t.hand = SceneModel.ExitMirrorScene
t.pb = SceneRpc_pb.SceneRpcExitMirrorSceneAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ChangeLine"
t.para = {{name="LineID",t=1},{name="MapID",t=1}}
t.hand = SceneModel.ChangeLine
t.pb = SceneRpc_pb.SceneRpcChangeLineAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "Ping"
t.para = {}
t.hand = SceneModel.Ping
t.pb = SceneRpc_pb.SceneRpcPingAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "LogOutGame"
t.para = {}
t.hand = SceneModel.LogOutGame
t.pb = SceneRpc_pb.SceneRpcLogOutGameAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ShowFilmFinish"
t.para = {}
t.hand = SceneModel.ShowFilmFinish
t.pb = SceneRpc_pb.SceneRpcShowFilmFinishAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "SpecObjPos"
t.para = {}
t.hand = SceneModel.SpecObjPos
t.pb = SceneRpc_pb.SceneRpcSpecObjPosAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "WantChangeZone"
t.para = {{name="Zoneid",t=1}}
t.hand = SceneModel.WantChangeZone
t.pb = SceneRpc_pb.SceneRpcWantChangeZoneAsk()
table.insert(askList.Scene,t)

local t = {}
t.name = "ReturnSrcServer"
t.para = {}
t.hand = SceneModel.ReturnSrcServer
t.pb = SceneRpc_pb.SceneRpcReturnSrcServerAsk()
table.insert(askList.Scene,t)

--]]

