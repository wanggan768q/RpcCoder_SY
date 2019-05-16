--将变量写入下方
local ModuleId = 23;
local RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST = 2351
local RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST = 2352





require("app.WorldBoss.WorldBossRpc_pb")

WorldBossModel = class("WorldBossModel",BaseModel)

function WorldBossModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=WorldBossModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function WorldBossModel:ctor()
	WorldBossModel.super.ctor(self)
	self.rpc_pb = WorldBossRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function WorldBossModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function WorldBossInfo(self,BossID,_hanlder)
	local PB = self.rpc_pb.WorldBossRpcWorldBossInfoAsk()
	PB.BossID = BossID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST",RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldBossRpcWorldBossInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldBoss => WorldBossInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST",RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST)
end
function WorldBossRankInfo(self,BossID,Occupation,_hanlder)
	local PB = self.rpc_pb.WorldBossRpcWorldBossRankInfoAsk()
	PB.BossID = BossID
	PB.Occupation = Occupation
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST",RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.WorldBossRpcWorldBossRankInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[WorldBoss => WorldBossRankInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST",RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST)
end








askList.WorldBoss = {}

local t = {}
t.name = "WorldBossInfo"
t.para = {{name="BossID",t=1}}
t.hand = WorldBossModel.WorldBossInfo
t.pb = WorldBossRpc_pb.WorldBossRpcWorldBossInfoAsk()
table.insert(askList.WorldBoss,t)

local t = {}
t.name = "WorldBossRankInfo"
t.para = {{name="BossID",t=1},{name="Occupation",t=1}}
t.hand = WorldBossModel.WorldBossRankInfo
t.pb = WorldBossRpc_pb.WorldBossRpcWorldBossRankInfoAsk()
table.insert(askList.WorldBoss,t)

