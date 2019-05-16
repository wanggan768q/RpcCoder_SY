--将变量写入下方
local ModuleId = 38;
local RPC_CODE_GUILD_GUILDBASEINFO_REQUEST = 3851
local RPC_CODE_GUILD_KICKMEMBER_REQUEST = 3852
local RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY = 3853;
local RPC_CODE_GUILD_ASKVACATION_REQUEST = 3854
local RPC_CODE_GUILD_VACATION_NOTIFY = 3855;
local RPC_CODE_GUILD_REPLYVACATION_NOTIFY = 3856;
local RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST = 3857
local RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST = 3858
local RPC_CODE_GUILD_APPLYGUILD_NOTIFY = 3859;
local RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST = 3860
local RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST = 3861
local RPC_CODE_GUILD_SETJURISDICTION_REQUEST = 3862
local RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST = 3863
local RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST = 3864
local RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY = 3865;
local RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST = 3866
local RPC_CODE_GUILD_BUILDINGLVUP_REQUEST = 3867
local RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST = 3868
local RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST = 3869
local RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY = 3870;
local RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST = 3871
local RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST = 3872
local RPC_CODE_GUILD_SEARCHGUILD_REQUEST = 3873
local RPC_CODE_GUILD_JOINGUILD_REQUEST = 3874
local RPC_CODE_GUILD_CREATEGUILD_REQUEST = 3875
local RPC_CODE_GUILD_CHANGEFLAG_REQUEST = 3876
local RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST = 3877
local RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST = 3878
local RPC_CODE_GUILD_QUITEGUILD_REQUEST = 3879
local RPC_CODE_GUILD_SETOFFICE_REQUEST = 3880
local RPC_CODE_GUILD_OFFICECHANGE_NOTIFY = 3881;
local RPC_CODE_GUILD_CHANGECREED_REQUEST = 3882
local RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST = 3883
local RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY = 3884;
local RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY = 3885;





require("app.Guild.GuildRpc_pb")

GuildModel = class("GuildModel",BaseModel)

function GuildModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GuildModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function GuildModel:ctor()
	GuildModel.super.ctor(self)
	self.rpc_pb = GuildRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY,handler(self,self.KickMemberNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_VACATION_NOTIFY,handler(self,self.VacationCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_REPLYVACATION_NOTIFY,handler(self,self.ReplyVacationCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_APPLYGUILD_NOTIFY,handler(self,self.ApplyGuildCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY,handler(self,self.ApplyGuildToOfficeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY,handler(self,self.BuildingCanLvUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_OFFICECHANGE_NOTIFY,handler(self,self.OfficeChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY,handler(self,self.BuildLvUpCompleteCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY,handler(self,self.GuildCurrencyChangeCB))

  


end

-- 更新数据
function GuildModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function GuildBaseInfo(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcGuildBaseInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_GUILDBASEINFO_REQUEST",RPC_CODE_GUILD_GUILDBASEINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcGuildBaseInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => GuildBaseInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_GUILDBASEINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_GUILDBASEINFO_REQUEST",RPC_CODE_GUILD_GUILDBASEINFO_REQUEST)
end
function KickMember(self,Guid,KickReason,ReasonType,_hanlder)
	local PB = self.rpc_pb.GuildRpcKickMemberAsk()
	PB.Guid = Guid
	PB.KickReason = KickReason
	PB.ReasonType = ReasonType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_KICKMEMBER_REQUEST",RPC_CODE_GUILD_KICKMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcKickMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => KickMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_KICKMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_KICKMEMBER_REQUEST",RPC_CODE_GUILD_KICKMEMBER_REQUEST)
end
function AskVacation(self,Guid,Reason,Type,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskVacationAsk()
	PB.Guid = Guid
	PB.Reason = Reason
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKVACATION_REQUEST",RPC_CODE_GUILD_ASKVACATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskVacationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskVacation ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKVACATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKVACATION_REQUEST",RPC_CODE_GUILD_ASKVACATION_REQUEST)
end
function AskApplyList(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskApplyListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST",RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskApplyListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskApplyList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST",RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST)
end
function ApplyGuildOperation(self,Guid,Operation,_hanlder)
	local PB = self.rpc_pb.GuildRpcApplyGuildOperationAsk()
	PB.Guid = Guid
	PB.Operation = Operation
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST",RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcApplyGuildOperationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => ApplyGuildOperation ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST",RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST)
end
function ApplyLimitSetting(self,IsAutoJoin,_hanlder)
	local PB = self.rpc_pb.GuildRpcApplyLimitSettingAsk()
	PB.IsAutoJoin = IsAutoJoin
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST",RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcApplyLimitSettingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => ApplyLimitSetting ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST",RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST)
end
function AskJurisdictionList(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskJurisdictionListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST",RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskJurisdictionListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskJurisdictionList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST",RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST)
end
function SetJurisdiction(self,SetList,_hanlder)
	local PB = self.rpc_pb.GuildRpcSetJurisdictionAsk()
	PB.SetList.OfficeType = SetList.OfficeType
	for i = 1, #SetList.JurisdictionList do
		table.insert( PB.SetList.JurisdictionList,SetList.JurisdictionList[i] )
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_SETJURISDICTION_REQUEST",RPC_CODE_GUILD_SETJURISDICTION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcSetJurisdictionReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => SetJurisdiction ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_SETJURISDICTION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_SETJURISDICTION_REQUEST",RPC_CODE_GUILD_SETJURISDICTION_REQUEST)
end
function AskVacationList(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskVacationListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST",RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskVacationListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskVacationList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST",RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST)
end
function VacationGuildOperation(self,Guid,Operation,_hanlder)
	local PB = self.rpc_pb.GuildRpcVacationGuildOperationAsk()
	PB.Guid = Guid
	PB.Operation = Operation
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST",RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcVacationGuildOperationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => VacationGuildOperation ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST",RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST)
end
function AskBuildingInfo(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskBuildingInfoAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST",RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskBuildingInfoReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskBuildingInfo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST",RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST)
end
function BuildingLvUp(self,BuildingType,_hanlder)
	local PB = self.rpc_pb.GuildRpcBuildingLvUpAsk()
	PB.BuildingType = BuildingType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_BUILDINGLVUP_REQUEST",RPC_CODE_GUILD_BUILDINGLVUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcBuildingLvUpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => BuildingLvUp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_BUILDINGLVUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_BUILDINGLVUP_REQUEST",RPC_CODE_GUILD_BUILDINGLVUP_REQUEST)
end
function BuildingLvSpeedUp(self,BuildingType,Time,_hanlder)
	local PB = self.rpc_pb.GuildRpcBuildingLvSpeedUpAsk()
	PB.BuildingType = BuildingType
	PB.Time = Time
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST",RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcBuildingLvSpeedUpReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => BuildingLvSpeedUp ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST",RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST)
end
function AskBuildingContributionList(self,BuildingType,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskBuildingContributionListAsk()
	PB.BuildingType = BuildingType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST",RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskBuildingContributionListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskBuildingContributionList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST",RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST)
end
function AskGuildEventList(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskGuildEventListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST",RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskGuildEventListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskGuildEventList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST",RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST)
end
function AskGuildInfoList(self,PageIndex,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskGuildInfoListAsk()
	PB.PageIndex = PageIndex
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST",RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskGuildInfoListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskGuildInfoList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST",RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST)
end
function SearchGuild(self,Text,_hanlder)
	local PB = self.rpc_pb.GuildRpcSearchGuildAsk()
	PB.Text = Text
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_SEARCHGUILD_REQUEST",RPC_CODE_GUILD_SEARCHGUILD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcSearchGuildReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => SearchGuild ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_SEARCHGUILD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_SEARCHGUILD_REQUEST",RPC_CODE_GUILD_SEARCHGUILD_REQUEST)
end
function JoinGuild(self,Guid,Type,_hanlder)
	local PB = self.rpc_pb.GuildRpcJoinGuildAsk()
	PB.Guid = Guid
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_JOINGUILD_REQUEST",RPC_CODE_GUILD_JOINGUILD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcJoinGuildReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => JoinGuild ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_JOINGUILD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_JOINGUILD_REQUEST",RPC_CODE_GUILD_JOINGUILD_REQUEST)
end
function CreateGuild(self,GuildName,GuildCreed,_hanlder)
	local PB = self.rpc_pb.GuildRpcCreateGuildAsk()
	PB.GuildName = GuildName
	PB.GuildCreed = GuildCreed
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_CREATEGUILD_REQUEST",RPC_CODE_GUILD_CREATEGUILD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcCreateGuildReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => CreateGuild ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CREATEGUILD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_CREATEGUILD_REQUEST",RPC_CODE_GUILD_CREATEGUILD_REQUEST)
end
function ChangeFlag(self,FlagConfigID,_hanlder)
	local PB = self.rpc_pb.GuildRpcChangeFlagAsk()
	PB.FlagConfigID = FlagConfigID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_CHANGEFLAG_REQUEST",RPC_CODE_GUILD_CHANGEFLAG_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcChangeFlagReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => ChangeFlag ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CHANGEFLAG_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_CHANGEFLAG_REQUEST",RPC_CODE_GUILD_CHANGEFLAG_REQUEST)
end
function GuildChangeName(self,GuildNewName,_hanlder)
	local PB = self.rpc_pb.GuildRpcGuildChangeNameAsk()
	PB.GuildNewName = GuildNewName
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST",RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcGuildChangeNameReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => GuildChangeName ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST",RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST)
end
function AskGuildMember(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcAskGuildMemberAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST",RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAskGuildMemberReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => AskGuildMember ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST",RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST)
end
function QuiteGuild(self,_hanlder)
	local PB = self.rpc_pb.GuildRpcQuiteGuildAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_QUITEGUILD_REQUEST",RPC_CODE_GUILD_QUITEGUILD_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcQuiteGuildReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => QuiteGuild ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_QUITEGUILD_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_QUITEGUILD_REQUEST",RPC_CODE_GUILD_QUITEGUILD_REQUEST)
end
function SetOffice(self,Guid,TargetGuid,OfficeType,_hanlder)
	local PB = self.rpc_pb.GuildRpcSetOfficeAsk()
	PB.Guid = Guid
	PB.TargetGuid = TargetGuid
	PB.OfficeType = OfficeType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_SETOFFICE_REQUEST",RPC_CODE_GUILD_SETOFFICE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcSetOfficeReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => SetOffice ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_SETOFFICE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_SETOFFICE_REQUEST",RPC_CODE_GUILD_SETOFFICE_REQUEST)
end
function ChangeCreed(self,Content,_hanlder)
	local PB = self.rpc_pb.GuildRpcChangeCreedAsk()
	PB.Content = Content
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_CHANGECREED_REQUEST",RPC_CODE_GUILD_CHANGECREED_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcChangeCreedReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => ChangeCreed ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CHANGECREED_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_CHANGECREED_REQUEST",RPC_CODE_GUILD_CHANGECREED_REQUEST)
end
function ForbiddenChat(self,Playerguid,IsForbidden,_hanlder)
	local PB = self.rpc_pb.GuildRpcForbiddenChatAsk()
	PB.Playerguid = Playerguid
	PB.IsForbidden = IsForbidden
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST",RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcForbiddenChatReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Guild => ForbiddenChat ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST",RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerKickMemberNotifyCBNotify(self,_hanlder)
	if not self.KickMemberNotifyCBNotifyCallBack then
		self.KickMemberNotifyCBNotifyCallBack = {}
	end
	table.insert(self.KickMemberNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function KickMemberNotifyCB(self,notifyMsg)
	if self.KickMemberNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcKickMemberNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.KickMemberNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterKickMemberNotifyCBNotify(self,_hanlder)
	if nil ~= self.KickMemberNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.KickMemberNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.KickMemberNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerVacationCBNotify(self,_hanlder)
	if not self.VacationCBNotifyCallBack then
		self.VacationCBNotifyCallBack = {}
	end
	table.insert(self.VacationCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function VacationCB(self,notifyMsg)
	if self.VacationCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcVacationNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.VacationCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterVacationCBNotify(self,_hanlder)
	if nil ~= self.VacationCBNotifyCallBack then
		for i,callback in ipairs(self.VacationCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.VacationCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerReplyVacationCBNotify(self,_hanlder)
	if not self.ReplyVacationCBNotifyCallBack then
		self.ReplyVacationCBNotifyCallBack = {}
	end
	table.insert(self.ReplyVacationCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ReplyVacationCB(self,notifyMsg)
	if self.ReplyVacationCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcReplyVacationNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ReplyVacationCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterReplyVacationCBNotify(self,_hanlder)
	if nil ~= self.ReplyVacationCBNotifyCallBack then
		for i,callback in ipairs(self.ReplyVacationCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ReplyVacationCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerApplyGuildCBNotify(self,_hanlder)
	if not self.ApplyGuildCBNotifyCallBack then
		self.ApplyGuildCBNotifyCallBack = {}
	end
	table.insert(self.ApplyGuildCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ApplyGuildCB(self,notifyMsg)
	if self.ApplyGuildCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcApplyGuildNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyGuildCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterApplyGuildCBNotify(self,_hanlder)
	if nil ~= self.ApplyGuildCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyGuildCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyGuildCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerApplyGuildToOfficeCBNotify(self,_hanlder)
	if not self.ApplyGuildToOfficeCBNotifyCallBack then
		self.ApplyGuildToOfficeCBNotifyCallBack = {}
	end
	table.insert(self.ApplyGuildToOfficeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ApplyGuildToOfficeCB(self,notifyMsg)
	if self.ApplyGuildToOfficeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcApplyGuildToOfficeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyGuildToOfficeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterApplyGuildToOfficeCBNotify(self,_hanlder)
	if nil ~= self.ApplyGuildToOfficeCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyGuildToOfficeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyGuildToOfficeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBuildingCanLvUpCBNotify(self,_hanlder)
	if not self.BuildingCanLvUpCBNotifyCallBack then
		self.BuildingCanLvUpCBNotifyCallBack = {}
	end
	table.insert(self.BuildingCanLvUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BuildingCanLvUpCB(self,notifyMsg)
	if self.BuildingCanLvUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcBuildingCanLvUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BuildingCanLvUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBuildingCanLvUpCBNotify(self,_hanlder)
	if nil ~= self.BuildingCanLvUpCBNotifyCallBack then
		for i,callback in ipairs(self.BuildingCanLvUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BuildingCanLvUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerOfficeChangeCBNotify(self,_hanlder)
	if not self.OfficeChangeCBNotifyCallBack then
		self.OfficeChangeCBNotifyCallBack = {}
	end
	table.insert(self.OfficeChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OfficeChangeCB(self,notifyMsg)
	if self.OfficeChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcOfficeChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OfficeChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterOfficeChangeCBNotify(self,_hanlder)
	if nil ~= self.OfficeChangeCBNotifyCallBack then
		for i,callback in ipairs(self.OfficeChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OfficeChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBuildLvUpCompleteCBNotify(self,_hanlder)
	if not self.BuildLvUpCompleteCBNotifyCallBack then
		self.BuildLvUpCompleteCBNotifyCallBack = {}
	end
	table.insert(self.BuildLvUpCompleteCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BuildLvUpCompleteCB(self,notifyMsg)
	if self.BuildLvUpCompleteCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcBuildLvUpCompleteNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BuildLvUpCompleteCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBuildLvUpCompleteCBNotify(self,_hanlder)
	if nil ~= self.BuildLvUpCompleteCBNotifyCallBack then
		for i,callback in ipairs(self.BuildLvUpCompleteCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BuildLvUpCompleteCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerGuildCurrencyChangeCBNotify(self,_hanlder)
	if not self.GuildCurrencyChangeCBNotifyCallBack then
		self.GuildCurrencyChangeCBNotifyCallBack = {}
	end
	table.insert(self.GuildCurrencyChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildCurrencyChangeCB(self,notifyMsg)
	if self.GuildCurrencyChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcGuildCurrencyChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.GuildCurrencyChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterGuildCurrencyChangeCBNotify(self,_hanlder)
	if nil ~= self.GuildCurrencyChangeCBNotifyCallBack then
		for i,callback in ipairs(self.GuildCurrencyChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.GuildCurrencyChangeCBNotifyCallBack, i )
			end
		end
	end
end





askList.Guild = {}

local t = {}
t.name = "GuildBaseInfo"
t.para = {}
t.hand = GuildModel.GuildBaseInfo
t.pb = GuildRpc_pb.GuildRpcGuildBaseInfoAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "KickMember"
t.para = {{name="Guid",t=1},{name="KickReason",t=2},{name="ReasonType",t=1}}
t.hand = GuildModel.KickMember
t.pb = GuildRpc_pb.GuildRpcKickMemberAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskVacation"
t.para = {{name="Guid",t=1},{name="Reason",t=2},{name="Type",t=1}}
t.hand = GuildModel.AskVacation
t.pb = GuildRpc_pb.GuildRpcAskVacationAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskApplyList"
t.para = {}
t.hand = GuildModel.AskApplyList
t.pb = GuildRpc_pb.GuildRpcAskApplyListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ApplyGuildOperation"
t.para = {{name="Guid",t=1},{name="Operation",t=1}}
t.hand = GuildModel.ApplyGuildOperation
t.pb = GuildRpc_pb.GuildRpcApplyGuildOperationAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ApplyLimitSetting"
t.para = {{name="IsAutoJoin",t=3}}
t.hand = GuildModel.ApplyLimitSetting
t.pb = GuildRpc_pb.GuildRpcApplyLimitSettingAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskJurisdictionList"
t.para = {}
t.hand = GuildModel.AskJurisdictionList
t.pb = GuildRpc_pb.GuildRpcAskJurisdictionListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "SetJurisdiction"
t.para = {{name="SetList",t=3}}
t.hand = GuildModel.SetJurisdiction
t.pb = GuildRpc_pb.GuildRpcSetJurisdictionAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskVacationList"
t.para = {}
t.hand = GuildModel.AskVacationList
t.pb = GuildRpc_pb.GuildRpcAskVacationListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "VacationGuildOperation"
t.para = {{name="Guid",t=1},{name="Operation",t=1}}
t.hand = GuildModel.VacationGuildOperation
t.pb = GuildRpc_pb.GuildRpcVacationGuildOperationAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskBuildingInfo"
t.para = {}
t.hand = GuildModel.AskBuildingInfo
t.pb = GuildRpc_pb.GuildRpcAskBuildingInfoAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "BuildingLvUp"
t.para = {{name="BuildingType",t=1}}
t.hand = GuildModel.BuildingLvUp
t.pb = GuildRpc_pb.GuildRpcBuildingLvUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "BuildingLvSpeedUp"
t.para = {{name="BuildingType",t=1},{name="Time",t=1}}
t.hand = GuildModel.BuildingLvSpeedUp
t.pb = GuildRpc_pb.GuildRpcBuildingLvSpeedUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskBuildingContributionList"
t.para = {{name="BuildingType",t=1}}
t.hand = GuildModel.AskBuildingContributionList
t.pb = GuildRpc_pb.GuildRpcAskBuildingContributionListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskGuildEventList"
t.para = {}
t.hand = GuildModel.AskGuildEventList
t.pb = GuildRpc_pb.GuildRpcAskGuildEventListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskGuildInfoList"
t.para = {{name="PageIndex",t=1}}
t.hand = GuildModel.AskGuildInfoList
t.pb = GuildRpc_pb.GuildRpcAskGuildInfoListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "SearchGuild"
t.para = {{name="Text",t=2}}
t.hand = GuildModel.SearchGuild
t.pb = GuildRpc_pb.GuildRpcSearchGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "JoinGuild"
t.para = {{name="Guid",t=1},{name="Type",t=1}}
t.hand = GuildModel.JoinGuild
t.pb = GuildRpc_pb.GuildRpcJoinGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "CreateGuild"
t.para = {{name="GuildName",t=2},{name="GuildCreed",t=2}}
t.hand = GuildModel.CreateGuild
t.pb = GuildRpc_pb.GuildRpcCreateGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ChangeFlag"
t.para = {{name="FlagConfigID",t=1}}
t.hand = GuildModel.ChangeFlag
t.pb = GuildRpc_pb.GuildRpcChangeFlagAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "GuildChangeName"
t.para = {{name="GuildNewName",t=2}}
t.hand = GuildModel.GuildChangeName
t.pb = GuildRpc_pb.GuildRpcGuildChangeNameAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AskGuildMember"
t.para = {}
t.hand = GuildModel.AskGuildMember
t.pb = GuildRpc_pb.GuildRpcAskGuildMemberAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "QuiteGuild"
t.para = {}
t.hand = GuildModel.QuiteGuild
t.pb = GuildRpc_pb.GuildRpcQuiteGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "SetOffice"
t.para = {{name="Guid",t=1},{name="TargetGuid",t=1},{name="OfficeType",t=1}}
t.hand = GuildModel.SetOffice
t.pb = GuildRpc_pb.GuildRpcSetOfficeAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ChangeCreed"
t.para = {{name="Content",t=2}}
t.hand = GuildModel.ChangeCreed
t.pb = GuildRpc_pb.GuildRpcChangeCreedAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ForbiddenChat"
t.para = {{name="Playerguid",t=1},{name="IsForbidden",t=3}}
t.hand = GuildModel.ForbiddenChat
t.pb = GuildRpc_pb.GuildRpcForbiddenChatAsk()
table.insert(askList.Guild,t)

