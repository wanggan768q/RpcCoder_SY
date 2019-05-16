--将变量写入下方
local ModuleId = 36;
local RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST = 3651





require("app.LobbyServer.LobbyServerRpc_pb")

LobbyServerModel = class("LobbyServerModel",BaseModel)

function LobbyServerModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=LobbyServerModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function LobbyServerModel:ctor()
	LobbyServerModel.super.ctor(self)
	self.rpc_pb = LobbyServerRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function LobbyServerModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function GetServerList(self,Sdk_user_id,_hanlder)
	local PB = self.rpc_pb.LobbyServerRpcGetServerListAsk()
	PB.Sdk_user_id = Sdk_user_id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST",RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.LobbyServerRpcGetServerListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[LobbyServer => GetServerList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST",RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST)
end








askList.LobbyServer = {}

local t = {}
t.name = "GetServerList"
t.para = {{name="Sdk_user_id",t=2}}
t.hand = LobbyServerModel.GetServerList
t.pb = LobbyServerRpc_pb.LobbyServerRpcGetServerListAsk()
table.insert(askList.LobbyServer,t)

