--将变量写入下方
local ModuleId = 56;
local RPC_CODE_RANK_RANK_REQUEST = 5651





require("app.Rank.RankRpc_pb")

RankModel = class("RankModel",BaseModel)

function RankModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=RankModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function RankModel:ctor()
	RankModel.super.ctor(self)
	self.rpc_pb = RankRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function RankModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function Rank(self,RankType,RankSubType,_hanlder)
	local PB = self.rpc_pb.RankRpcRankAsk()
	PB.RankType = RankType
	PB.RankSubType = RankSubType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_RANK_RANK_REQUEST",RPC_CODE_RANK_RANK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.RankRpcRankReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Rank => Rank ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_RANK_RANK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_RANK_RANK_REQUEST",RPC_CODE_RANK_RANK_REQUEST)
end








askList.Rank = {}

local t = {}
t.name = "Rank"
t.para = {{name="RankType",t=1},{name="RankSubType",t=1}}
t.hand = RankModel.Rank
t.pb = RankRpc_pb.RankRpcRankAsk()
table.insert(askList.Rank,t)

