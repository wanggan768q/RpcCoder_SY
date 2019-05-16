--将变量写入下方
local ModuleId = 48;
local RPC_CODE_CONTACT_ADDFRIEND_REQUEST = 4851
local RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST = 4852
local RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST = 4853
local RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST = 4854
local RPC_CODE_CONTACT_CONTACTSETTING_REQUEST = 4855
local RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST = 4856
local RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST = 4857
local RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST = 4858
local RPC_CODE_CONTACT_RENAMEGROUP_REQUEST = 4859
local RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST = 4860
local RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY = 4861;
local RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST = 4862
local RPC_CODE_CONTACT_NEWFRIEND_NOTIFY = 4863;
local RPC_CODE_CONTACT_APPLYLIST_NOTIFY = 4864;
local RPC_CODE_CONTACT_REJECTAPPLY_REQUEST = 4865
local RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY = 4866;
local RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY = 4867;
local RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY = 4868;
local RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST = 4869
local RPC_CODE_CONTACT_REJECTALL_REQUEST = 4870
local RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST = 4871
local RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY = 4872;
local RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY = 4873;
local RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY = 4874;
local RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY = 4875;
local RPC_CODE_CONTACT_SORTGROUP_REQUEST = 4876
local RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST = 4877
local RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST = 4878
local RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST = 4879
local RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY = 4880;
local RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST = 4881
local RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST = 4882
local RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST = 4883
local RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY = 4884;
local RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY = 4885;
local RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY = 4886;
local RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST = 4887
local RPC_CODE_CONTACT_CHATTO_REQUEST = 4888
local RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY = 4889;
local RPC_CODE_CONTACT_READMSG_REQUEST = 4890





require("app.Contact.ContactRpc_pb")

ContactModel = class("ContactModel",BaseModel)

function ContactModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ContactModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ContactModel:ctor()
	ContactModel.super.ctor(self)
	self.rpc_pb = ContactRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY,handler(self,self.AgreeApplicationNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_NEWFRIEND_NOTIFY,handler(self,self.NewFriendCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_APPLYLIST_NOTIFY,handler(self,self.ApplyListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY,handler(self,self.BeRejectApplyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY,handler(self,self.BeCancelRelationShipCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY,handler(self,self.BeAddBlackListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY,handler(self,self.RoleDataUpdateCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY,handler(self,self.ContactLoginCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY,handler(self,self.ContactLogoutCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY,handler(self,self.DeleteRoleDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY,handler(self,self.UnAcquireGiftPointCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY,handler(self,self.AddRoleDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY,handler(self,self.SetGiftPointCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY,handler(self,self.ContactsGroupsCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY,handler(self,self.NewChatMsgCB))

  


end

-- 更新数据
function ContactModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function AddFriend(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcAddFriendAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_ADDFRIEND_REQUEST",RPC_CODE_CONTACT_ADDFRIEND_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAddFriendReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AddFriend ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_ADDFRIEND_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_ADDFRIEND_REQUEST",RPC_CODE_CONTACT_ADDFRIEND_REQUEST)
end
function CancelRelationShip(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcCancelRelationShipAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST",RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcCancelRelationShipReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => CancelRelationShip ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST",RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST)
end
function AddBlackList(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcAddBlackListAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST",RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAddBlackListReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AddBlackList ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST",RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST)
end
function SyncAddressBook(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcSyncAddressBookAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST",RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSyncAddressBookReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SyncAddressBook ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST",RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST)
end
function ContactSetting(self,NewSetting,_hanlder)
	local PB = self.rpc_pb.ContactRpcContactSettingAsk()
	PB.NewSetting.CloseApplyFriend = NewSetting.CloseApplyFriend
	PB.NewSetting.ClearFirend = NewSetting.ClearFirend
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_CONTACTSETTING_REQUEST",RPC_CODE_CONTACT_CONTACTSETTING_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcContactSettingReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => ContactSetting ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_CONTACTSETTING_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_CONTACTSETTING_REQUEST",RPC_CODE_CONTACT_CONTACTSETTING_REQUEST)
end
function CreateFriendGroup(self,GroupName,RoleIds,_hanlder)
	local PB = self.rpc_pb.ContactRpcCreateFriendGroupAsk()
	PB.GroupName = GroupName
	for i,v in ipairs(RoleIds) do
		table.insert(PB.RoleIds,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcCreateFriendGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => CreateFriendGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST)
end
function MoveToFriendGroup(self,RoleIds,FromGroupId,ToGroupId,_hanlder)
	local PB = self.rpc_pb.ContactRpcMoveToFriendGroupAsk()
	for i,v in ipairs(RoleIds) do
		table.insert(PB.RoleIds,v)
	end
	PB.FromGroupId = FromGroupId
	PB.ToGroupId = ToGroupId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcMoveToFriendGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => MoveToFriendGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST)
end
function RemoveFriendGroup(self,RemoveGroupId,_hanlder)
	local PB = self.rpc_pb.ContactRpcRemoveFriendGroupAsk()
	PB.RemoveGroupId = RemoveGroupId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcRemoveFriendGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => RemoveFriendGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST)
end
function RenameGroup(self,Name,GroupId,_hanlder)
	local PB = self.rpc_pb.ContactRpcRenameGroupAsk()
	PB.Name = Name
	PB.GroupId = GroupId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_RENAMEGROUP_REQUEST",RPC_CODE_CONTACT_RENAMEGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcRenameGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => RenameGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_RENAMEGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_RENAMEGROUP_REQUEST",RPC_CODE_CONTACT_RENAMEGROUP_REQUEST)
end
function AgreeApplication(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcAgreeApplicationAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST",RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAgreeApplicationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AgreeApplication ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST",RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST)
end
function SetFriendGroup(self,GroupId,RoleIds,GroupName,_hanlder)
	local PB = self.rpc_pb.ContactRpcSetFriendGroupAsk()
	PB.GroupId = GroupId
	PB.RoleIds = RoleIds
	PB.GroupName = GroupName
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSetFriendGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SetFriendGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST",RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST)
end
function RejectApply(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcRejectApplyAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_REJECTAPPLY_REQUEST",RPC_CODE_CONTACT_REJECTAPPLY_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcRejectApplyReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => RejectApply ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_REJECTAPPLY_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_REJECTAPPLY_REQUEST",RPC_CODE_CONTACT_REJECTAPPLY_REQUEST)
end
function RecommendContact(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcRecommendContactAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST",RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcRecommendContactReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => RecommendContact ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST",RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST)
end
function RejectAll(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcRejectAllAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_REJECTALL_REQUEST",RPC_CODE_CONTACT_REJECTALL_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcRejectAllReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => RejectAll ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_REJECTALL_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_REJECTALL_REQUEST",RPC_CODE_CONTACT_REJECTALL_REQUEST)
end
function AddFriendShipPoint(self,FriendRoleId,ItemData,_hanlder)
	local PB = self.rpc_pb.ContactRpcAddFriendShipPointAsk()
	PB.FriendRoleId = FriendRoleId
	for i,v in ipairs(ItemData) do
		table.insert(PB.ItemData,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST",RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAddFriendShipPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AddFriendShipPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST",RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST)
end
function SortGroup(self,GroupIds,_hanlder)
	local PB = self.rpc_pb.ContactRpcSortGroupAsk()
	for i,v in ipairs(GroupIds) do
		table.insert(PB.GroupIds,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SORTGROUP_REQUEST",RPC_CODE_CONTACT_SORTGROUP_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSortGroupReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SortGroup ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SORTGROUP_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SORTGROUP_REQUEST",RPC_CODE_CONTACT_SORTGROUP_REQUEST)
end
function SetFriendAlias(self,Name,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcSetFriendAliasAsk()
	PB.Name = Name
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST",RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSetFriendAliasReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SetFriendAlias ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST",RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST)
end
function SendFriendGiftPoint(self,SendRoleId,Point,_hanlder)
	local PB = self.rpc_pb.ContactRpcSendFriendGiftPointAsk()
	PB.SendRoleId = SendRoleId
	PB.Point = Point
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST",RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSendFriendGiftPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SendFriendGiftPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST",RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST)
end
function AcquireGiftPoint(self,AcquireRoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcAcquireGiftPointAsk()
	PB.AcquireRoleId = AcquireRoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST",RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAcquireGiftPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AcquireGiftPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST",RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST)
end
function SendAllFriendGiftPoint(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcSendAllFriendGiftPointAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST",RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcSendAllFriendGiftPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => SendAllFriendGiftPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST",RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST)
end
function AcquireAllGiftPoint(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcAcquireAllGiftPointAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST",RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAcquireAllGiftPointReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AcquireAllGiftPoint ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST",RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST)
end
function DeleteGroupRole(self,GroupId,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcDeleteGroupRoleAsk()
	PB.GroupId = GroupId
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST",RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcDeleteGroupRoleReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => DeleteGroupRole ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST",RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST)
end
function AgreeAllApplication(self,_hanlder)
	local PB = self.rpc_pb.ContactRpcAgreeAllApplicationAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST",RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcAgreeAllApplicationReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => AgreeAllApplication ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST",RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST)
end
function ChatTo(self,RoleId,ChatMsg,_hanlder)
	local PB = self.rpc_pb.ContactRpcChatToAsk()
	PB.RoleId = RoleId
	PB.ChatMsg.Chat_content = ChatMsg.Chat_content
	PB.ChatMsg.Chat_voice_url = ChatMsg.Chat_voice_url
	PB.ChatMsg.Chat_voice_secs = ChatMsg.Chat_voice_secs
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_CHATTO_REQUEST",RPC_CODE_CONTACT_CHATTO_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcChatToReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => ChatTo ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_CHATTO_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_CHATTO_REQUEST",RPC_CODE_CONTACT_CHATTO_REQUEST)
end
function ReadMsg(self,RoleId,_hanlder)
	local PB = self.rpc_pb.ContactRpcReadMsgAsk()
	PB.RoleId = RoleId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		hideNetTip(self,"RPC_CODE_CONTACT_READMSG_REQUEST",RPC_CODE_CONTACT_READMSG_REQUEST)
		if _hanlder then
			local ret_msg = self.rpc_pb.ContactRpcReadMsgReply()
			ret_msg:ParseFromString(_data)
			if ret_msg.Result < 1 then
				Event.Brocast(CommonE.ErrorCode,ret_msg.Result,"[Contact => ReadMsg ]")
			end
			_hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CONTACT_READMSG_REQUEST, pb_data, callback)
	showNetTip(self,"RPC_CODE_CONTACT_READMSG_REQUEST",RPC_CODE_CONTACT_READMSG_REQUEST)
end



-- 给c层 注册服务器通知回调
function registerAgreeApplicationNotifyCBNotify(self,_hanlder)
	if not self.AgreeApplicationNotifyCBNotifyCallBack then
		self.AgreeApplicationNotifyCBNotifyCallBack = {}
	end
	table.insert(self.AgreeApplicationNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AgreeApplicationNotifyCB(self,notifyMsg)
	if self.AgreeApplicationNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcAgreeApplicationNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AgreeApplicationNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAgreeApplicationNotifyCBNotify(self,_hanlder)
	if nil ~= self.AgreeApplicationNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.AgreeApplicationNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AgreeApplicationNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNewFriendCBNotify(self,_hanlder)
	if not self.NewFriendCBNotifyCallBack then
		self.NewFriendCBNotifyCallBack = {}
	end
	table.insert(self.NewFriendCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewFriendCB(self,notifyMsg)
	if self.NewFriendCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcNewFriendNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewFriendCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewFriendCBNotify(self,_hanlder)
	if nil ~= self.NewFriendCBNotifyCallBack then
		for i,callback in ipairs(self.NewFriendCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewFriendCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerApplyListCBNotify(self,_hanlder)
	if not self.ApplyListCBNotifyCallBack then
		self.ApplyListCBNotifyCallBack = {}
	end
	table.insert(self.ApplyListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ApplyListCB(self,notifyMsg)
	if self.ApplyListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcApplyListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterApplyListCBNotify(self,_hanlder)
	if nil ~= self.ApplyListCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBeRejectApplyCBNotify(self,_hanlder)
	if not self.BeRejectApplyCBNotifyCallBack then
		self.BeRejectApplyCBNotifyCallBack = {}
	end
	table.insert(self.BeRejectApplyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BeRejectApplyCB(self,notifyMsg)
	if self.BeRejectApplyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcBeRejectApplyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeRejectApplyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBeRejectApplyCBNotify(self,_hanlder)
	if nil ~= self.BeRejectApplyCBNotifyCallBack then
		for i,callback in ipairs(self.BeRejectApplyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeRejectApplyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBeCancelRelationShipCBNotify(self,_hanlder)
	if not self.BeCancelRelationShipCBNotifyCallBack then
		self.BeCancelRelationShipCBNotifyCallBack = {}
	end
	table.insert(self.BeCancelRelationShipCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BeCancelRelationShipCB(self,notifyMsg)
	if self.BeCancelRelationShipCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcBeCancelRelationShipNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeCancelRelationShipCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBeCancelRelationShipCBNotify(self,_hanlder)
	if nil ~= self.BeCancelRelationShipCBNotifyCallBack then
		for i,callback in ipairs(self.BeCancelRelationShipCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeCancelRelationShipCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerBeAddBlackListCBNotify(self,_hanlder)
	if not self.BeAddBlackListCBNotifyCallBack then
		self.BeAddBlackListCBNotifyCallBack = {}
	end
	table.insert(self.BeAddBlackListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BeAddBlackListCB(self,notifyMsg)
	if self.BeAddBlackListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcBeAddBlackListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeAddBlackListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterBeAddBlackListCBNotify(self,_hanlder)
	if nil ~= self.BeAddBlackListCBNotifyCallBack then
		for i,callback in ipairs(self.BeAddBlackListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeAddBlackListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerRoleDataUpdateCBNotify(self,_hanlder)
	if not self.RoleDataUpdateCBNotifyCallBack then
		self.RoleDataUpdateCBNotifyCallBack = {}
	end
	table.insert(self.RoleDataUpdateCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function RoleDataUpdateCB(self,notifyMsg)
	if self.RoleDataUpdateCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcRoleDataUpdateNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RoleDataUpdateCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterRoleDataUpdateCBNotify(self,_hanlder)
	if nil ~= self.RoleDataUpdateCBNotifyCallBack then
		for i,callback in ipairs(self.RoleDataUpdateCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RoleDataUpdateCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerContactLoginCBNotify(self,_hanlder)
	if not self.ContactLoginCBNotifyCallBack then
		self.ContactLoginCBNotifyCallBack = {}
	end
	table.insert(self.ContactLoginCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ContactLoginCB(self,notifyMsg)
	if self.ContactLoginCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcContactLoginNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ContactLoginCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterContactLoginCBNotify(self,_hanlder)
	if nil ~= self.ContactLoginCBNotifyCallBack then
		for i,callback in ipairs(self.ContactLoginCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ContactLoginCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerContactLogoutCBNotify(self,_hanlder)
	if not self.ContactLogoutCBNotifyCallBack then
		self.ContactLogoutCBNotifyCallBack = {}
	end
	table.insert(self.ContactLogoutCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ContactLogoutCB(self,notifyMsg)
	if self.ContactLogoutCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcContactLogoutNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ContactLogoutCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterContactLogoutCBNotify(self,_hanlder)
	if nil ~= self.ContactLogoutCBNotifyCallBack then
		for i,callback in ipairs(self.ContactLogoutCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ContactLogoutCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerDeleteRoleDataCBNotify(self,_hanlder)
	if not self.DeleteRoleDataCBNotifyCallBack then
		self.DeleteRoleDataCBNotifyCallBack = {}
	end
	table.insert(self.DeleteRoleDataCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DeleteRoleDataCB(self,notifyMsg)
	if self.DeleteRoleDataCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcDeleteRoleDataNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DeleteRoleDataCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterDeleteRoleDataCBNotify(self,_hanlder)
	if nil ~= self.DeleteRoleDataCBNotifyCallBack then
		for i,callback in ipairs(self.DeleteRoleDataCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DeleteRoleDataCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerUnAcquireGiftPointCBNotify(self,_hanlder)
	if not self.UnAcquireGiftPointCBNotifyCallBack then
		self.UnAcquireGiftPointCBNotifyCallBack = {}
	end
	table.insert(self.UnAcquireGiftPointCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function UnAcquireGiftPointCB(self,notifyMsg)
	if self.UnAcquireGiftPointCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcUnAcquireGiftPointNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UnAcquireGiftPointCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterUnAcquireGiftPointCBNotify(self,_hanlder)
	if nil ~= self.UnAcquireGiftPointCBNotifyCallBack then
		for i,callback in ipairs(self.UnAcquireGiftPointCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UnAcquireGiftPointCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerAddRoleDataCBNotify(self,_hanlder)
	if not self.AddRoleDataCBNotifyCallBack then
		self.AddRoleDataCBNotifyCallBack = {}
	end
	table.insert(self.AddRoleDataCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function AddRoleDataCB(self,notifyMsg)
	if self.AddRoleDataCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcAddRoleDataNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AddRoleDataCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterAddRoleDataCBNotify(self,_hanlder)
	if nil ~= self.AddRoleDataCBNotifyCallBack then
		for i,callback in ipairs(self.AddRoleDataCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AddRoleDataCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerSetGiftPointCBNotify(self,_hanlder)
	if not self.SetGiftPointCBNotifyCallBack then
		self.SetGiftPointCBNotifyCallBack = {}
	end
	table.insert(self.SetGiftPointCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function SetGiftPointCB(self,notifyMsg)
	if self.SetGiftPointCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcSetGiftPointNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SetGiftPointCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterSetGiftPointCBNotify(self,_hanlder)
	if nil ~= self.SetGiftPointCBNotifyCallBack then
		for i,callback in ipairs(self.SetGiftPointCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SetGiftPointCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerContactsGroupsCBNotify(self,_hanlder)
	if not self.ContactsGroupsCBNotifyCallBack then
		self.ContactsGroupsCBNotifyCallBack = {}
	end
	table.insert(self.ContactsGroupsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ContactsGroupsCB(self,notifyMsg)
	if self.ContactsGroupsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcContactsGroupsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ContactsGroupsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterContactsGroupsCBNotify(self,_hanlder)
	if nil ~= self.ContactsGroupsCBNotifyCallBack then
		for i,callback in ipairs(self.ContactsGroupsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ContactsGroupsCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function registerNewChatMsgCBNotify(self,_hanlder)
	if not self.NewChatMsgCBNotifyCallBack then
		self.NewChatMsgCBNotifyCallBack = {}
	end
	table.insert(self.NewChatMsgCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function NewChatMsgCB(self,notifyMsg)
	if self.NewChatMsgCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ContactRpcNewChatMsgNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewChatMsgCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function unregisterNewChatMsgCBNotify(self,_hanlder)
	if nil ~= self.NewChatMsgCBNotifyCallBack then
		for i,callback in ipairs(self.NewChatMsgCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewChatMsgCBNotifyCallBack, i )
			end
		end
	end
end





askList.Contact = {}

local t = {}
t.name = "AddFriend"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.AddFriend
t.pb = ContactRpc_pb.ContactRpcAddFriendAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "CancelRelationShip"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.CancelRelationShip
t.pb = ContactRpc_pb.ContactRpcCancelRelationShipAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AddBlackList"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.AddBlackList
t.pb = ContactRpc_pb.ContactRpcAddBlackListAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SyncAddressBook"
t.para = {}
t.hand = ContactModel.SyncAddressBook
t.pb = ContactRpc_pb.ContactRpcSyncAddressBookAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "ContactSetting"
t.para = {{name="NewSetting",t=3}}
t.hand = ContactModel.ContactSetting
t.pb = ContactRpc_pb.ContactRpcContactSettingAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "CreateFriendGroup"
t.para = {{name="GroupName",t=2},{name="RoleIds",t=1}}
t.hand = ContactModel.CreateFriendGroup
t.pb = ContactRpc_pb.ContactRpcCreateFriendGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "MoveToFriendGroup"
t.para = {{name="RoleIds",t=1},{name="FromGroupId",t=1},{name="ToGroupId",t=1}}
t.hand = ContactModel.MoveToFriendGroup
t.pb = ContactRpc_pb.ContactRpcMoveToFriendGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "RemoveFriendGroup"
t.para = {{name="RemoveGroupId",t=1}}
t.hand = ContactModel.RemoveFriendGroup
t.pb = ContactRpc_pb.ContactRpcRemoveFriendGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "RenameGroup"
t.para = {{name="Name",t=2},{name="GroupId",t=1}}
t.hand = ContactModel.RenameGroup
t.pb = ContactRpc_pb.ContactRpcRenameGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AgreeApplication"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.AgreeApplication
t.pb = ContactRpc_pb.ContactRpcAgreeApplicationAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SetFriendGroup"
t.para = {{name="GroupId",t=1},{name="RoleIds",t=1},{name="GroupName",t=3}}
t.hand = ContactModel.SetFriendGroup
t.pb = ContactRpc_pb.ContactRpcSetFriendGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "RejectApply"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.RejectApply
t.pb = ContactRpc_pb.ContactRpcRejectApplyAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "RecommendContact"
t.para = {}
t.hand = ContactModel.RecommendContact
t.pb = ContactRpc_pb.ContactRpcRecommendContactAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "RejectAll"
t.para = {}
t.hand = ContactModel.RejectAll
t.pb = ContactRpc_pb.ContactRpcRejectAllAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AddFriendShipPoint"
t.para = {{name="FriendRoleId",t=1},{name="ItemData",t=3}}
t.hand = ContactModel.AddFriendShipPoint
t.pb = ContactRpc_pb.ContactRpcAddFriendShipPointAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SortGroup"
t.para = {{name="GroupIds",t=1}}
t.hand = ContactModel.SortGroup
t.pb = ContactRpc_pb.ContactRpcSortGroupAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SetFriendAlias"
t.para = {{name="Name",t=2},{name="RoleId",t=1}}
t.hand = ContactModel.SetFriendAlias
t.pb = ContactRpc_pb.ContactRpcSetFriendAliasAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SendFriendGiftPoint"
t.para = {{name="SendRoleId",t=1},{name="Point",t=1}}
t.hand = ContactModel.SendFriendGiftPoint
t.pb = ContactRpc_pb.ContactRpcSendFriendGiftPointAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AcquireGiftPoint"
t.para = {{name="AcquireRoleId",t=1}}
t.hand = ContactModel.AcquireGiftPoint
t.pb = ContactRpc_pb.ContactRpcAcquireGiftPointAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "SendAllFriendGiftPoint"
t.para = {}
t.hand = ContactModel.SendAllFriendGiftPoint
t.pb = ContactRpc_pb.ContactRpcSendAllFriendGiftPointAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AcquireAllGiftPoint"
t.para = {}
t.hand = ContactModel.AcquireAllGiftPoint
t.pb = ContactRpc_pb.ContactRpcAcquireAllGiftPointAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "DeleteGroupRole"
t.para = {{name="GroupId",t=1},{name="RoleId",t=1}}
t.hand = ContactModel.DeleteGroupRole
t.pb = ContactRpc_pb.ContactRpcDeleteGroupRoleAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "AgreeAllApplication"
t.para = {}
t.hand = ContactModel.AgreeAllApplication
t.pb = ContactRpc_pb.ContactRpcAgreeAllApplicationAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "ChatTo"
t.para = {{name="RoleId",t=1},{name="ChatMsg",t=3}}
t.hand = ContactModel.ChatTo
t.pb = ContactRpc_pb.ContactRpcChatToAsk()
table.insert(askList.Contact,t)

local t = {}
t.name = "ReadMsg"
t.para = {{name="RoleId",t=1}}
t.hand = ContactModel.ReadMsg
t.pb = ContactRpc_pb.ContactRpcReadMsgAsk()
table.insert(askList.Contact,t)

