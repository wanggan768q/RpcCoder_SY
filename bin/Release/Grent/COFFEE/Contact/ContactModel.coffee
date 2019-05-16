ProtoBuf = require("./../network/protobuf");
ByteArray = ProtoBuf.ByteBuffer
Long = ProtoBuf.Long
mLayerMgr = require("./../network/MLayerMgr.coffee")
NetTipController=require("./../util/NetTipController.coffee")


Proto = null
updateFieldCB = null
RpcAgreeApplicationNotifyNotifyCB = null
RpcNewFriendNotifyCB = null
RpcApplyListNotifyCB = null
RpcBeRejectApplyNotifyCB = null
RpcBeCancelRelationShipNotifyCB = null
RpcBeAddBlackListNotifyCB = null
RpcRoleDataUpdateNotifyCB = null
RpcContactLoginNotifyCB = null
RpcContactLogoutNotifyCB = null
RpcDeleteRoleDataNotifyCB = null
RpcUnAcquireGiftPointNotifyCB = null
RpcAddRoleDataNotifyCB = null
RpcSetGiftPointNotifyCB = null
RpcContactsGroupsNotifyCB = null
RpcNewChatMsgNotifyCB = null


ModuleId = 48
RPC_CODE_ADDFRIEND_REQUEST = 4851
RPC_CODE_CANCELRELATIONSHIP_REQUEST = 4852
RPC_CODE_ADDBLACKLIST_REQUEST = 4853
RPC_CODE_SYNCADDRESSBOOK_REQUEST = 4854
RPC_CODE_CONTACTSETTING_REQUEST = 4855
RPC_CODE_CREATEFRIENDGROUP_REQUEST = 4856
RPC_CODE_MOVETOFRIENDGROUP_REQUEST = 4857
RPC_CODE_REMOVEFRIENDGROUP_REQUEST = 4858
RPC_CODE_RENAMEGROUP_REQUEST = 4859
RPC_CODE_AGREEAPPLICATION_REQUEST = 4860
RPC_CODE_AGREEAPPLICATIONNOTIFY_NOTIFY = 4861
RPC_CODE_SETFRIENDGROUP_REQUEST = 4862
RPC_CODE_NEWFRIEND_NOTIFY = 4863
RPC_CODE_APPLYLIST_NOTIFY = 4864
RPC_CODE_REJECTAPPLY_REQUEST = 4865
RPC_CODE_BEREJECTAPPLY_NOTIFY = 4866
RPC_CODE_BECANCELRELATIONSHIP_NOTIFY = 4867
RPC_CODE_BEADDBLACKLIST_NOTIFY = 4868
RPC_CODE_RECOMMENDCONTACT_REQUEST = 4869
RPC_CODE_REJECTALL_REQUEST = 4870
RPC_CODE_ADDFRIENDSHIPPOINT_REQUEST = 4871
RPC_CODE_ROLEDATAUPDATE_NOTIFY = 4872
RPC_CODE_CONTACTLOGIN_NOTIFY = 4873
RPC_CODE_CONTACTLOGOUT_NOTIFY = 4874
RPC_CODE_DELETEROLEDATA_NOTIFY = 4875
RPC_CODE_SORTGROUP_REQUEST = 4876
RPC_CODE_SETFRIENDALIAS_REQUEST = 4877
RPC_CODE_SENDFRIENDGIFTPOINT_REQUEST = 4878
RPC_CODE_ACQUIREGIFTPOINT_REQUEST = 4879
RPC_CODE_UNACQUIREGIFTPOINT_NOTIFY = 4880
RPC_CODE_SENDALLFRIENDGIFTPOINT_REQUEST = 4881
RPC_CODE_ACQUIREALLGIFTPOINT_REQUEST = 4882
RPC_CODE_DELETEGROUPROLE_REQUEST = 4883
RPC_CODE_ADDROLEDATA_NOTIFY = 4884
RPC_CODE_SETGIFTPOINT_NOTIFY = 4885
RPC_CODE_CONTACTSGROUPS_NOTIFY = 4886
RPC_CODE_AGREEALLAPPLICATION_REQUEST = 4887
RPC_CODE_CHATTO_REQUEST = 4888
RPC_CODE_NEWCHATMSG_NOTIFY = 4889
RPC_CODE_READMSG_REQUEST = 4890

AddFriendAskPB = null
AddFriendReplyPB = null
CancelRelationShipAskPB = null
CancelRelationShipReplyPB = null
AddBlackListAskPB = null
AddBlackListReplyPB = null
SyncAddressBookAskPB = null
SyncAddressBookReplyPB = null
ContactSettingAskPB = null
ContactSettingReplyPB = null
CreateFriendGroupAskPB = null
CreateFriendGroupReplyPB = null
MoveToFriendGroupAskPB = null
MoveToFriendGroupReplyPB = null
RemoveFriendGroupAskPB = null
RemoveFriendGroupReplyPB = null
RenameGroupAskPB = null
RenameGroupReplyPB = null
AgreeApplicationAskPB = null
AgreeApplicationReplyPB = null
AgreeApplicationNotifyNotifyPB = null
SetFriendGroupAskPB = null
SetFriendGroupReplyPB = null
NewFriendNotifyPB = null
ApplyListNotifyPB = null
RejectApplyAskPB = null
RejectApplyReplyPB = null
BeRejectApplyNotifyPB = null
BeCancelRelationShipNotifyPB = null
BeAddBlackListNotifyPB = null
RecommendContactAskPB = null
RecommendContactReplyPB = null
RejectAllAskPB = null
RejectAllReplyPB = null
AddFriendShipPointAskPB = null
AddFriendShipPointReplyPB = null
RoleDataUpdateNotifyPB = null
ContactLoginNotifyPB = null
ContactLogoutNotifyPB = null
DeleteRoleDataNotifyPB = null
SortGroupAskPB = null
SortGroupReplyPB = null
SetFriendAliasAskPB = null
SetFriendAliasReplyPB = null
SendFriendGiftPointAskPB = null
SendFriendGiftPointReplyPB = null
AcquireGiftPointAskPB = null
AcquireGiftPointReplyPB = null
UnAcquireGiftPointNotifyPB = null
SendAllFriendGiftPointAskPB = null
SendAllFriendGiftPointReplyPB = null
AcquireAllGiftPointAskPB = null
AcquireAllGiftPointReplyPB = null
DeleteGroupRoleAskPB = null
DeleteGroupRoleReplyPB = null
AddRoleDataNotifyPB = null
SetGiftPointNotifyPB = null
ContactsGroupsNotifyPB = null
AgreeAllApplicationAskPB = null
AgreeAllApplicationReplyPB = null
ChatToAskPB = null
ChatToReplyPB = null
NewChatMsgNotifyPB = null
ReadMsgAskPB = null
ReadMsgReplyPB = null

class ContactModel
  Initialize : () ->
    Proto = ProtoBuf.loadProto("
      message  RpcAddFriendAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  ContactData
      {
        optional uint64 RoleId = 1[default=0];
        optional uint64 TeamId = 2[default=0];
        optional string Nickname = 3;
        optional int32 ConfigId = 4[default=-1];
        optional int32 Level = 5[default=1];
        optional int32 ResourceId = 6[default=-1];
        optional string Alias = 8;
        optional int32 FamiliarPoint = 10[default=0];
        optional int32 OnLine = 11[default=0];
        optional int32 CombatValue = 12[default=-1];
        optional int64 LastLoginTime = 13[default=-1];
      }
      message  ContactGroup
      {
        optional string GroupName = 1;
        repeated uint64 GroupRoleIds = 2;
        optional int32 GroupId = 3[default=-1];
      }
      message  RpcAddFriendReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactData NewFriendData = 3;
        optional ContactGroup MyFriendGroup = 4;
      }
      message  RpcCancelRelationShipAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcCancelRelationShipReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 DeleteRoleId = 2[default=0];
        repeated ContactGroup ContactGroups = 3;
      }
      message  RpcAddBlackListAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcAddBlackListReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ContactGroups = 2;
        optional uint64 RoleId = 3[default=0];
      }
      message  RpcSyncAddressBookAsk
      {
      }
      message  ContactSetting
      {
        optional int32 CloseApplyFriend = 1[default=-1];
        optional int32 ClearFirend = 2[default=-1];
      }
      message  FriendGiftPoint
      {
        optional uint64 Guid = 1[default=0];
        optional int32 Point = 2[default=0];
      }
      message  FriendGifPointList
      {
        repeated FriendGiftPoint SentGiftList = 1;
        repeated FriendGiftPoint AcquireGiftList = 2;
        repeated FriendGiftPoint UnAcquireGiftList = 3;
      }
      message  ChatMsg
      {
        optional string Chat_content = 1;
        optional string Chat_voice_url = 2;
        optional int32 Chat_voice_secs = 3[default=-1];
      }
      message  ChatInfo
      {
        optional string Player_name = 1;
        optional uint64 Player_guid = 2[default=0];
        optional int32 Avatar_id = 3[default=-1];
        optional int32 Player_level = 4[default=-1];
        optional int32 Avatar_frame_id = 5[default=-1];
        optional int32 Config_id = 6[default=-1];
        optional uint64 Timestamp = 7[default=0];
        optional ChatMsg Chat_msg = 8;
        optional uint64 Team_id = 9[default=0];
        optional uint64 Guild_guid = 10[default=0];
      }
      message  ContactsChatMsg
      {
        optional uint64 RoleId = 1[default=0];
        optional bool HasNewMsg = 2;
        repeated ChatInfo CharInfoList = 3;
      }
      message  AddressBook
      {
        repeated ContactData ContactDataList = 1;
        repeated ContactGroup ContactGroups = 2;
        optional ContactSetting Setting = 3;
        optional ContactData MyRoleData = 4;
        repeated int32 SortGroupId = 5;
        optional FriendGifPointList GiftPointList = 6;
        repeated ContactsChatMsg ChatMsgList = 7;
      }
      message  RpcSyncAddressBookReply
      {
        optional int32 Result = 1[default=-1];
        optional AddressBook AddressBock = 2;
      }
      message  RpcContactSettingAsk
      {
        optional ContactSetting NewSetting = 1;
      }
      message  RpcContactSettingReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactSetting NewSetting = 2;
      }
      message  RpcCreateFriendGroupAsk
      {
        optional string GroupName = 1;
        repeated uint64 RoleIds = 2;
      }
      message  RpcCreateFriendGroupReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ContactGroups = 2;
        repeated int32 GroupIds = 3;
      }
      message  RpcMoveToFriendGroupAsk
      {
        repeated uint64 RoleIds = 1;
        optional int32 FromGroupId = 2[default=-1];
        optional int32 ToGroupId = 3[default=-1];
      }
      message  RpcMoveToFriendGroupReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ChangeGroup = 2;
      }
      message  RpcRemoveFriendGroupAsk
      {
        optional int32 RemoveGroupId = 1[default=-1];
      }
      message  RpcRemoveFriendGroupReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactGroup MyFriendGroup = 3;
        optional int32 RemoveGroupId = 4[default=-1];
        repeated int32 GroupIds = 5;
      }
      message  RpcRenameGroupAsk
      {
        optional string Name = 1;
        optional int32 GroupId = 2[default=-1];
      }
      message  RpcRenameGroupReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactGroup DefineGroup = 2;
      }
      message  RpcAgreeApplicationAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcAgreeApplicationReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactData NewFriendData = 2;
        repeated ContactGroup MyFriendGroup = 3;
      }
      message  RpcAgreeApplicationNotifyNotify
      {
        repeated ContactGroup MyFriendGroup = 1;
        optional ContactData NewFriendData = 2;
      }
      message  RpcSetFriendGroupAsk
      {
        optional int32 GroupId = 1[default=-1];
        optional int32 RoleIds = 2[default=-1];
        optional bytes GroupName = 3;
      }
      message  RpcSetFriendGroupReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup FriendGroups = 2;
      }
      message  RpcNewFriendNotify
      {
        optional ContactData NewFriendData = 1;
        optional ContactGroup MyFriendGroup = 2;
      }
      message  RpcApplyListNotify
      {
        optional ContactData ApplyFriendData = 1;
        repeated ContactGroup ApplyGroups = 5;
      }
      message  RpcRejectApplyAsk
      {
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcRejectApplyReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ContactGroups = 8;
        optional uint64 DeleteRoleId = 9[default=0];
      }
      message  RpcBeRejectApplyNotify
      {
        optional ContactData DeleteFriendData = 1;
      }
      message  RpcBeCancelRelationShipNotify
      {
        optional uint64 DeleteRoleId = 1[default=0];
        repeated ContactGroup ContactGroups = 2;
      }
      message  RpcBeAddBlackListNotify
      {
        optional uint64 RoleId = 1[default=0];
        repeated ContactGroup ContactGroups = 2;
      }
      message  RpcRecommendContactAsk
      {
      }
      message  RpcRecommendContactReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactData Contact = 2;
        repeated uint64 ApplyedListId = 3;
      }
      message  RpcRejectAllAsk
      {
      }
      message  RpcRejectAllReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ContactGroups = 2;
        repeated uint64 DeleteRoleIds = 3;
      }
      message  ItemSimpleData
      {
        optional int32 ConfID = 1[default=-1];
        optional int32 Count = 2[default=-1];
      }
      message  RpcAddFriendShipPointAsk
      {
        optional uint64 FriendRoleId = 1[default=0];
        repeated ItemSimpleData ItemData = 2;
      }
      message  RpcAddFriendShipPointReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactData Contact = 2;
      }
      message  RpcRoleDataUpdateNotify
      {
        optional ContactData Contact = 1;
      }
      message  RpcContactLoginNotify
      {
        optional ContactData Contact = 1;
        repeated int32 GroupIds = 2;
      }
      message  RpcContactLogoutNotify
      {
        optional ContactData Contact = 1;
        repeated int32 GroupIds = 2;
      }
      message  RpcDeleteRoleDataNotify
      {
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcSortGroupAsk
      {
        repeated int32 GroupIds = 1;
      }
      message  RpcSortGroupReply
      {
        optional int32 Result = 1[default=-1];
        repeated int32 GroupIds = 2;
      }
      message  RpcSetFriendAliasAsk
      {
        optional string Name = 1;
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcSetFriendAliasReply
      {
        optional int32 Result = 1[default=-1];
        optional ContactData Contact = 2;
      }
      message  RpcSendFriendGiftPointAsk
      {
        optional uint64 SendRoleId = 1[default=0];
        optional int32 Point = 2[default=-1];
      }
      message  RpcSendFriendGiftPointReply
      {
        optional int32 Result = 1[default=-1];
        repeated FriendGiftPoint SentGiftList = 2;
      }
      message  RpcAcquireGiftPointAsk
      {
        optional uint64 AcquireRoleId = 1[default=0];
      }
      message  RpcAcquireGiftPointReply
      {
        optional int32 Result = 1[default=-1];
        repeated FriendGiftPoint AcquireGiftList = 2;
        repeated FriendGiftPoint UnAcquireGiftList = 3;
      }
      message  RpcUnAcquireGiftPointNotify
      {
        repeated FriendGiftPoint UnAcquireGiftList = 1;
      }
      message  RpcSendAllFriendGiftPointAsk
      {
      }
      message  RpcSendAllFriendGiftPointReply
      {
        optional int32 Result = 1[default=-1];
        repeated FriendGiftPoint SentGiftList = 2;
      }
      message  RpcAcquireAllGiftPointAsk
      {
      }
      message  RpcAcquireAllGiftPointReply
      {
        optional int32 Result = 1[default=-1];
        repeated FriendGiftPoint AcquireGiftList = 2;
        repeated FriendGiftPoint UnAcquireGiftList = 3;
      }
      message  RpcDeleteGroupRoleAsk
      {
        optional int32 GroupId = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcDeleteGroupRoleReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactGroup ContactGroups = 3;
      }
      message  RpcAddRoleDataNotify
      {
        optional ContactData NewRoleData = 1;
      }
      message  RpcSetGiftPointNotify
      {
        repeated FriendGiftPoint AcquireGiftList = 1;
        repeated FriendGiftPoint UnAcquireGiftList = 2;
        repeated FriendGiftPoint SentGiftList = 3;
      }
      message  RpcContactsGroupsNotify
      {
        repeated ContactGroup MyFriendGroup = 1;
      }
      message  RpcAgreeAllApplicationAsk
      {
      }
      message  RpcAgreeAllApplicationReply
      {
        optional int32 Result = 1[default=-1];
        repeated ContactData NewFriendData = 2;
        repeated ContactGroup MyFriendGroup = 3;
      }
      message  RpcChatToAsk
      {
        optional uint64 RoleId = 1[default=0];
        optional ChatMsg ChatMsg = 2;
      }
      message  RpcChatToReply
      {
        optional int32 Result = 1[default=-1];
      }
      message  RpcNewChatMsgNotify
      {
        optional ChatInfo ChatMsg = 1;
        optional uint64 RoleId = 2[default=0];
      }
      message  RpcReadMsgAsk
      {
        optional uint64 RoleId = 1[default=0];
      }
      message  RpcReadMsgReply
      {
        optional int32 Result = 1[default=-1];
        optional uint64 RoleId = 2[default=0];
      }
    ")
    mLayerMgr.registerUpdate(ModuleId,@updateDataField)
    AddFriendAskPB = Proto.build("RpcAddFriendAsk")
    AddFriendReplyPB = Proto.build("RpcAddFriendReply")
    CancelRelationShipAskPB = Proto.build("RpcCancelRelationShipAsk")
    CancelRelationShipReplyPB = Proto.build("RpcCancelRelationShipReply")
    AddBlackListAskPB = Proto.build("RpcAddBlackListAsk")
    AddBlackListReplyPB = Proto.build("RpcAddBlackListReply")
    SyncAddressBookAskPB = Proto.build("RpcSyncAddressBookAsk")
    SyncAddressBookReplyPB = Proto.build("RpcSyncAddressBookReply")
    ContactSettingAskPB = Proto.build("RpcContactSettingAsk")
    ContactSettingReplyPB = Proto.build("RpcContactSettingReply")
    CreateFriendGroupAskPB = Proto.build("RpcCreateFriendGroupAsk")
    CreateFriendGroupReplyPB = Proto.build("RpcCreateFriendGroupReply")
    MoveToFriendGroupAskPB = Proto.build("RpcMoveToFriendGroupAsk")
    MoveToFriendGroupReplyPB = Proto.build("RpcMoveToFriendGroupReply")
    RemoveFriendGroupAskPB = Proto.build("RpcRemoveFriendGroupAsk")
    RemoveFriendGroupReplyPB = Proto.build("RpcRemoveFriendGroupReply")
    RenameGroupAskPB = Proto.build("RpcRenameGroupAsk")
    RenameGroupReplyPB = Proto.build("RpcRenameGroupReply")
    AgreeApplicationAskPB = Proto.build("RpcAgreeApplicationAsk")
    AgreeApplicationReplyPB = Proto.build("RpcAgreeApplicationReply")
    AgreeApplicationNotifyNotifyPB = Proto.build("RpcAgreeApplicationNotifyNotify")
    mLayerMgr.registerNotify(RPC_CODE_AGREEAPPLICATIONNOTIFY_NOTIFY,@AgreeApplicationNotifyCB)
    SetFriendGroupAskPB = Proto.build("RpcSetFriendGroupAsk")
    SetFriendGroupReplyPB = Proto.build("RpcSetFriendGroupReply")
    NewFriendNotifyPB = Proto.build("RpcNewFriendNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWFRIEND_NOTIFY,@NewFriendCB)
    ApplyListNotifyPB = Proto.build("RpcApplyListNotify")
    mLayerMgr.registerNotify(RPC_CODE_APPLYLIST_NOTIFY,@ApplyListCB)
    RejectApplyAskPB = Proto.build("RpcRejectApplyAsk")
    RejectApplyReplyPB = Proto.build("RpcRejectApplyReply")
    BeRejectApplyNotifyPB = Proto.build("RpcBeRejectApplyNotify")
    mLayerMgr.registerNotify(RPC_CODE_BEREJECTAPPLY_NOTIFY,@BeRejectApplyCB)
    BeCancelRelationShipNotifyPB = Proto.build("RpcBeCancelRelationShipNotify")
    mLayerMgr.registerNotify(RPC_CODE_BECANCELRELATIONSHIP_NOTIFY,@BeCancelRelationShipCB)
    BeAddBlackListNotifyPB = Proto.build("RpcBeAddBlackListNotify")
    mLayerMgr.registerNotify(RPC_CODE_BEADDBLACKLIST_NOTIFY,@BeAddBlackListCB)
    RecommendContactAskPB = Proto.build("RpcRecommendContactAsk")
    RecommendContactReplyPB = Proto.build("RpcRecommendContactReply")
    RejectAllAskPB = Proto.build("RpcRejectAllAsk")
    RejectAllReplyPB = Proto.build("RpcRejectAllReply")
    AddFriendShipPointAskPB = Proto.build("RpcAddFriendShipPointAsk")
    AddFriendShipPointReplyPB = Proto.build("RpcAddFriendShipPointReply")
    RoleDataUpdateNotifyPB = Proto.build("RpcRoleDataUpdateNotify")
    mLayerMgr.registerNotify(RPC_CODE_ROLEDATAUPDATE_NOTIFY,@RoleDataUpdateCB)
    ContactLoginNotifyPB = Proto.build("RpcContactLoginNotify")
    mLayerMgr.registerNotify(RPC_CODE_CONTACTLOGIN_NOTIFY,@ContactLoginCB)
    ContactLogoutNotifyPB = Proto.build("RpcContactLogoutNotify")
    mLayerMgr.registerNotify(RPC_CODE_CONTACTLOGOUT_NOTIFY,@ContactLogoutCB)
    DeleteRoleDataNotifyPB = Proto.build("RpcDeleteRoleDataNotify")
    mLayerMgr.registerNotify(RPC_CODE_DELETEROLEDATA_NOTIFY,@DeleteRoleDataCB)
    SortGroupAskPB = Proto.build("RpcSortGroupAsk")
    SortGroupReplyPB = Proto.build("RpcSortGroupReply")
    SetFriendAliasAskPB = Proto.build("RpcSetFriendAliasAsk")
    SetFriendAliasReplyPB = Proto.build("RpcSetFriendAliasReply")
    SendFriendGiftPointAskPB = Proto.build("RpcSendFriendGiftPointAsk")
    SendFriendGiftPointReplyPB = Proto.build("RpcSendFriendGiftPointReply")
    AcquireGiftPointAskPB = Proto.build("RpcAcquireGiftPointAsk")
    AcquireGiftPointReplyPB = Proto.build("RpcAcquireGiftPointReply")
    UnAcquireGiftPointNotifyPB = Proto.build("RpcUnAcquireGiftPointNotify")
    mLayerMgr.registerNotify(RPC_CODE_UNACQUIREGIFTPOINT_NOTIFY,@UnAcquireGiftPointCB)
    SendAllFriendGiftPointAskPB = Proto.build("RpcSendAllFriendGiftPointAsk")
    SendAllFriendGiftPointReplyPB = Proto.build("RpcSendAllFriendGiftPointReply")
    AcquireAllGiftPointAskPB = Proto.build("RpcAcquireAllGiftPointAsk")
    AcquireAllGiftPointReplyPB = Proto.build("RpcAcquireAllGiftPointReply")
    DeleteGroupRoleAskPB = Proto.build("RpcDeleteGroupRoleAsk")
    DeleteGroupRoleReplyPB = Proto.build("RpcDeleteGroupRoleReply")
    AddRoleDataNotifyPB = Proto.build("RpcAddRoleDataNotify")
    mLayerMgr.registerNotify(RPC_CODE_ADDROLEDATA_NOTIFY,@AddRoleDataCB)
    SetGiftPointNotifyPB = Proto.build("RpcSetGiftPointNotify")
    mLayerMgr.registerNotify(RPC_CODE_SETGIFTPOINT_NOTIFY,@SetGiftPointCB)
    ContactsGroupsNotifyPB = Proto.build("RpcContactsGroupsNotify")
    mLayerMgr.registerNotify(RPC_CODE_CONTACTSGROUPS_NOTIFY,@ContactsGroupsCB)
    AgreeAllApplicationAskPB = Proto.build("RpcAgreeAllApplicationAsk")
    AgreeAllApplicationReplyPB = Proto.build("RpcAgreeAllApplicationReply")
    ChatToAskPB = Proto.build("RpcChatToAsk")
    ChatToReplyPB = Proto.build("RpcChatToReply")
    NewChatMsgNotifyPB = Proto.build("RpcNewChatMsgNotify")
    mLayerMgr.registerNotify(RPC_CODE_NEWCHATMSG_NOTIFY,@NewChatMsgCB)
    ReadMsgAskPB = Proto.build("RpcReadMsgAsk")
    ReadMsgReplyPB = Proto.build("RpcReadMsgReply")






  AddFriend : (RoleId,replyCB) ->
    AddFriendAsk = AddFriendAskPB.prototype
    AddFriendAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_ADDFRIEND_REQUEST,AddFriendAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AddFriendReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CancelRelationShip : (RoleId,replyCB) ->
    CancelRelationShipAsk = CancelRelationShipAskPB.prototype
    CancelRelationShipAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_CANCELRELATIONSHIP_REQUEST,CancelRelationShipAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CancelRelationShipReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AddBlackList : (RoleId,replyCB) ->
    AddBlackListAsk = AddBlackListAskPB.prototype
    AddBlackListAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_ADDBLACKLIST_REQUEST,AddBlackListAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AddBlackListReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SyncAddressBook : (replyCB) ->
    SyncAddressBookAsk = SyncAddressBookAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SYNCADDRESSBOOK_REQUEST,SyncAddressBookAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SyncAddressBookReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ContactSetting : (NewSetting,replyCB) ->
    ContactSettingAsk = ContactSettingAskPB.prototype
    ContactSettingAsk.setNewSetting NewSetting
    mLayerMgr.sendAsk(RPC_CODE_CONTACTSETTING_REQUEST,ContactSettingAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ContactSettingReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  CreateFriendGroup : (GroupName,RoleIds,replyCB) ->
    CreateFriendGroupAsk = CreateFriendGroupAskPB.prototype
    CreateFriendGroupAsk.setGroupName GroupName
    CreateFriendGroupAsk.setRoleIds RoleIds
    mLayerMgr.sendAsk(RPC_CODE_CREATEFRIENDGROUP_REQUEST,CreateFriendGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( CreateFriendGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  MoveToFriendGroup : (RoleIds,FromGroupId,ToGroupId,replyCB) ->
    MoveToFriendGroupAsk = MoveToFriendGroupAskPB.prototype
    MoveToFriendGroupAsk.setRoleIds RoleIds
    MoveToFriendGroupAsk.setFromGroupId FromGroupId
    MoveToFriendGroupAsk.setToGroupId ToGroupId
    mLayerMgr.sendAsk(RPC_CODE_MOVETOFRIENDGROUP_REQUEST,MoveToFriendGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( MoveToFriendGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RemoveFriendGroup : (RemoveGroupId,replyCB) ->
    RemoveFriendGroupAsk = RemoveFriendGroupAskPB.prototype
    RemoveFriendGroupAsk.setRemoveGroupId RemoveGroupId
    mLayerMgr.sendAsk(RPC_CODE_REMOVEFRIENDGROUP_REQUEST,RemoveFriendGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RemoveFriendGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RenameGroup : (Name,GroupId,replyCB) ->
    RenameGroupAsk = RenameGroupAskPB.prototype
    RenameGroupAsk.setName Name
    RenameGroupAsk.setGroupId GroupId
    mLayerMgr.sendAsk(RPC_CODE_RENAMEGROUP_REQUEST,RenameGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RenameGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeApplication : (RoleId,replyCB) ->
    AgreeApplicationAsk = AgreeApplicationAskPB.prototype
    AgreeApplicationAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_AGREEAPPLICATION_REQUEST,AgreeApplicationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeApplicationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SetFriendGroup : (GroupId,RoleIds,GroupName,replyCB) ->
    SetFriendGroupAsk = SetFriendGroupAskPB.prototype
    SetFriendGroupAsk.setGroupId GroupId
    SetFriendGroupAsk.setRoleIds RoleIds
    SetFriendGroupAsk.setGroupName GroupName
    mLayerMgr.sendAsk(RPC_CODE_SETFRIENDGROUP_REQUEST,SetFriendGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SetFriendGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RejectApply : (RoleId,replyCB) ->
    RejectApplyAsk = RejectApplyAskPB.prototype
    RejectApplyAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_REJECTAPPLY_REQUEST,RejectApplyAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RejectApplyReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RecommendContact : (replyCB) ->
    RecommendContactAsk = RecommendContactAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_RECOMMENDCONTACT_REQUEST,RecommendContactAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RecommendContactReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  RejectAll : (replyCB) ->
    RejectAllAsk = RejectAllAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_REJECTALL_REQUEST,RejectAllAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( RejectAllReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AddFriendShipPoint : (FriendRoleId,ItemData,replyCB) ->
    AddFriendShipPointAsk = AddFriendShipPointAskPB.prototype
    AddFriendShipPointAsk.setFriendRoleId FriendRoleId
    AddFriendShipPointAsk.setItemData ItemData
    mLayerMgr.sendAsk(RPC_CODE_ADDFRIENDSHIPPOINT_REQUEST,AddFriendShipPointAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AddFriendShipPointReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SortGroup : (GroupIds,replyCB) ->
    SortGroupAsk = SortGroupAskPB.prototype
    SortGroupAsk.setGroupIds GroupIds
    mLayerMgr.sendAsk(RPC_CODE_SORTGROUP_REQUEST,SortGroupAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SortGroupReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SetFriendAlias : (Name,RoleId,replyCB) ->
    SetFriendAliasAsk = SetFriendAliasAskPB.prototype
    SetFriendAliasAsk.setName Name
    SetFriendAliasAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_SETFRIENDALIAS_REQUEST,SetFriendAliasAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SetFriendAliasReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SendFriendGiftPoint : (SendRoleId,Point,replyCB) ->
    SendFriendGiftPointAsk = SendFriendGiftPointAskPB.prototype
    SendFriendGiftPointAsk.setSendRoleId SendRoleId
    SendFriendGiftPointAsk.setPoint Point
    mLayerMgr.sendAsk(RPC_CODE_SENDFRIENDGIFTPOINT_REQUEST,SendFriendGiftPointAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SendFriendGiftPointReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AcquireGiftPoint : (AcquireRoleId,replyCB) ->
    AcquireGiftPointAsk = AcquireGiftPointAskPB.prototype
    AcquireGiftPointAsk.setAcquireRoleId AcquireRoleId
    mLayerMgr.sendAsk(RPC_CODE_ACQUIREGIFTPOINT_REQUEST,AcquireGiftPointAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AcquireGiftPointReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  SendAllFriendGiftPoint : (replyCB) ->
    SendAllFriendGiftPointAsk = SendAllFriendGiftPointAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_SENDALLFRIENDGIFTPOINT_REQUEST,SendAllFriendGiftPointAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( SendAllFriendGiftPointReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AcquireAllGiftPoint : (replyCB) ->
    AcquireAllGiftPointAsk = AcquireAllGiftPointAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_ACQUIREALLGIFTPOINT_REQUEST,AcquireAllGiftPointAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AcquireAllGiftPointReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  DeleteGroupRole : (GroupId,RoleId,replyCB) ->
    DeleteGroupRoleAsk = DeleteGroupRoleAskPB.prototype
    DeleteGroupRoleAsk.setGroupId GroupId
    DeleteGroupRoleAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_DELETEGROUPROLE_REQUEST,DeleteGroupRoleAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( DeleteGroupRoleReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  AgreeAllApplication : (replyCB) ->
    AgreeAllApplicationAsk = AgreeAllApplicationAskPB.prototype
    mLayerMgr.sendAsk(RPC_CODE_AGREEALLAPPLICATION_REQUEST,AgreeAllApplicationAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( AgreeAllApplicationReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ChatTo : (RoleId,ChatMsg,replyCB) ->
    ChatToAsk = ChatToAskPB.prototype
    ChatToAsk.setRoleId RoleId
    ChatToAsk.setChatMsg ChatMsg
    mLayerMgr.sendAsk(RPC_CODE_CHATTO_REQUEST,ChatToAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ChatToReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()
  ReadMsg : (RoleId,replyCB) ->
    ReadMsgAsk = ReadMsgAskPB.prototype
    ReadMsgAsk.setRoleId RoleId
    mLayerMgr.sendAsk(RPC_CODE_READMSG_REQUEST,ReadMsgAsk, (data)->
      NetTipController.hideNetTip()
      replyCB( ReadMsgReplyPB.decode(data)) if typeof(replyCB) is "function"
    )
    NetTipController.showNetTip()


  updateDataField : (SyncId,Index,Data,dataLen)->

    updateFieldCB( SyncId, Index ) if typeof(updateFieldCB) is "function"


  SetUpdateFieldCB : ( cb ) -> updateFieldCB = cb
  SetAgreeApplicationNotifyNotifyCB : (cb) -> RpcAgreeApplicationNotifyNotifyCB = cb
  AgreeApplicationNotifyCB : (data)->
    RpcAgreeApplicationNotifyNotifyCB( AgreeApplicationNotifyNotifyPB.decode(data)) if typeof(RpcAgreeApplicationNotifyNotifyCB) is "function"
  SetNewFriendNotifyCB : (cb) -> RpcNewFriendNotifyCB = cb
  NewFriendCB : (data)->
    RpcNewFriendNotifyCB( NewFriendNotifyPB.decode(data)) if typeof(RpcNewFriendNotifyCB) is "function"
  SetApplyListNotifyCB : (cb) -> RpcApplyListNotifyCB = cb
  ApplyListCB : (data)->
    RpcApplyListNotifyCB( ApplyListNotifyPB.decode(data)) if typeof(RpcApplyListNotifyCB) is "function"
  SetBeRejectApplyNotifyCB : (cb) -> RpcBeRejectApplyNotifyCB = cb
  BeRejectApplyCB : (data)->
    RpcBeRejectApplyNotifyCB( BeRejectApplyNotifyPB.decode(data)) if typeof(RpcBeRejectApplyNotifyCB) is "function"
  SetBeCancelRelationShipNotifyCB : (cb) -> RpcBeCancelRelationShipNotifyCB = cb
  BeCancelRelationShipCB : (data)->
    RpcBeCancelRelationShipNotifyCB( BeCancelRelationShipNotifyPB.decode(data)) if typeof(RpcBeCancelRelationShipNotifyCB) is "function"
  SetBeAddBlackListNotifyCB : (cb) -> RpcBeAddBlackListNotifyCB = cb
  BeAddBlackListCB : (data)->
    RpcBeAddBlackListNotifyCB( BeAddBlackListNotifyPB.decode(data)) if typeof(RpcBeAddBlackListNotifyCB) is "function"
  SetRoleDataUpdateNotifyCB : (cb) -> RpcRoleDataUpdateNotifyCB = cb
  RoleDataUpdateCB : (data)->
    RpcRoleDataUpdateNotifyCB( RoleDataUpdateNotifyPB.decode(data)) if typeof(RpcRoleDataUpdateNotifyCB) is "function"
  SetContactLoginNotifyCB : (cb) -> RpcContactLoginNotifyCB = cb
  ContactLoginCB : (data)->
    RpcContactLoginNotifyCB( ContactLoginNotifyPB.decode(data)) if typeof(RpcContactLoginNotifyCB) is "function"
  SetContactLogoutNotifyCB : (cb) -> RpcContactLogoutNotifyCB = cb
  ContactLogoutCB : (data)->
    RpcContactLogoutNotifyCB( ContactLogoutNotifyPB.decode(data)) if typeof(RpcContactLogoutNotifyCB) is "function"
  SetDeleteRoleDataNotifyCB : (cb) -> RpcDeleteRoleDataNotifyCB = cb
  DeleteRoleDataCB : (data)->
    RpcDeleteRoleDataNotifyCB( DeleteRoleDataNotifyPB.decode(data)) if typeof(RpcDeleteRoleDataNotifyCB) is "function"
  SetUnAcquireGiftPointNotifyCB : (cb) -> RpcUnAcquireGiftPointNotifyCB = cb
  UnAcquireGiftPointCB : (data)->
    RpcUnAcquireGiftPointNotifyCB( UnAcquireGiftPointNotifyPB.decode(data)) if typeof(RpcUnAcquireGiftPointNotifyCB) is "function"
  SetAddRoleDataNotifyCB : (cb) -> RpcAddRoleDataNotifyCB = cb
  AddRoleDataCB : (data)->
    RpcAddRoleDataNotifyCB( AddRoleDataNotifyPB.decode(data)) if typeof(RpcAddRoleDataNotifyCB) is "function"
  SetSetGiftPointNotifyCB : (cb) -> RpcSetGiftPointNotifyCB = cb
  SetGiftPointCB : (data)->
    RpcSetGiftPointNotifyCB( SetGiftPointNotifyPB.decode(data)) if typeof(RpcSetGiftPointNotifyCB) is "function"
  SetContactsGroupsNotifyCB : (cb) -> RpcContactsGroupsNotifyCB = cb
  ContactsGroupsCB : (data)->
    RpcContactsGroupsNotifyCB( ContactsGroupsNotifyPB.decode(data)) if typeof(RpcContactsGroupsNotifyCB) is "function"
  SetNewChatMsgNotifyCB : (cb) -> RpcNewChatMsgNotifyCB = cb
  NewChatMsgCB : (data)->
    RpcNewChatMsgNotifyCB( NewChatMsgNotifyPB.decode(data)) if typeof(RpcNewChatMsgNotifyCB) is "function"


  GetCoffeeInfo: ->
      'CoffeeName': "ContactModel",
      'AskName': ["AddFriend",
                   "CancelRelationShip",
                   "AddBlackList",
                   "SyncAddressBook",
                   "ContactSetting",
                   "CreateFriendGroup",
                   "MoveToFriendGroup",
                   "RemoveFriendGroup",
                   "RenameGroup",
                   "AgreeApplication",
                   "SetFriendGroup",
                   "RejectApply",
                   "RecommendContact",
                   "RejectAll",
                   "AddFriendShipPoint",
                   "SortGroup",
                   "SetFriendAlias",
                   "SendFriendGiftPoint",
                   "AcquireGiftPoint",
                   "SendAllFriendGiftPoint",
                   "AcquireAllGiftPoint",
                   "DeleteGroupRole",
                   "AgreeAllApplication",
                   "ChatTo",
                   "ReadMsg"]
      'ParamterList': [["RoleId"],
                       ["RoleId"],
                       ["RoleId"],
                       [],
                       ["NewSetting"],
                       ["GroupName","RoleIds"],
                       ["RoleIds","FromGroupId","ToGroupId"],
                       ["RemoveGroupId"],
                       ["Name","GroupId"],
                       ["RoleId"],
                       ["GroupId","RoleIds","GroupName"],
                       ["RoleId"],
                       [],
                       [],
                       ["FriendRoleId","ItemData"],
                       ["GroupIds"],
                       ["Name","RoleId"],
                       ["SendRoleId","Point"],
                       ["AcquireRoleId"],
                       [],
                       [],
                       ["GroupId","RoleId"],
                       [],
                       ["RoleId","ChatMsg"],
                       ["RoleId"]]
      'AskList':[@AddFriend,
                 @CancelRelationShip,
                 @AddBlackList,
                 @SyncAddressBook,
                 @ContactSetting,
                 @CreateFriendGroup,
                 @MoveToFriendGroup,
                 @RemoveFriendGroup,
                 @RenameGroup,
                 @AgreeApplication,
                 @SetFriendGroup,
                 @RejectApply,
                 @RecommendContact,
                 @RejectAll,
                 @AddFriendShipPoint,
                 @SortGroup,
                 @SetFriendAlias,
                 @SendFriendGiftPoint,
                 @AcquireGiftPoint,
                 @SendAllFriendGiftPoint,
                 @AcquireAllGiftPoint,
                 @DeleteGroupRole,
                 @AgreeAllApplication,
                 @ChatTo,
                 @ReadMsg]
      'ParamterTypelist': [["uint64"],
                       ["uint64"],
                       ["uint64"],
                       [],
                       ["ContactSetting"],
                       ["string","uint64"],
                       ["uint64","int32","int32"],
                       ["int32"],
                       ["string","int32"],
                       ["uint64"],
                       ["int32","int32","bytes"],
                       ["uint64"],
                       [],
                       [],
                       ["uint64","ItemSimpleData"],
                       ["int32"],
                       ["string","uint64"],
                       ["uint64","int32"],
                       ["uint64"],
                       [],
                       [],
                       ["int32","uint64"],
                       [],
                       ["uint64","ChatMsg"],
                       ["uint64"]]


module.exports =(()->
  if not Contact?
    Contact = new ContactModel()
  Contact)()



  

  

  


