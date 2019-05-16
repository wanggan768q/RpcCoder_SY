/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleContact.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class ContactRPC
{
	public const int ModuleId = 48;
	
	public const int RPC_CODE_CONTACT_ADDFRIEND_REQUEST = 4851;
	public const int RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST = 4852;
	public const int RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST = 4853;
	public const int RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST = 4854;
	public const int RPC_CODE_CONTACT_CONTACTSETTING_REQUEST = 4855;
	public const int RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST = 4856;
	public const int RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST = 4857;
	public const int RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST = 4858;
	public const int RPC_CODE_CONTACT_RENAMEGROUP_REQUEST = 4859;
	public const int RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST = 4860;
	public const int RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY = 4861;
	public const int RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST = 4862;
	public const int RPC_CODE_CONTACT_NEWFRIEND_NOTIFY = 4863;
	public const int RPC_CODE_CONTACT_APPLYLIST_NOTIFY = 4864;
	public const int RPC_CODE_CONTACT_REJECTAPPLY_REQUEST = 4865;
	public const int RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY = 4866;
	public const int RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY = 4867;
	public const int RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY = 4868;
	public const int RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST = 4869;
	public const int RPC_CODE_CONTACT_REJECTALL_REQUEST = 4870;
	public const int RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST = 4871;
	public const int RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY = 4872;
	public const int RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY = 4873;
	public const int RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY = 4874;
	public const int RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY = 4875;
	public const int RPC_CODE_CONTACT_SORTGROUP_REQUEST = 4876;
	public const int RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST = 4877;
	public const int RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST = 4878;
	public const int RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST = 4879;
	public const int RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY = 4880;
	public const int RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST = 4881;
	public const int RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST = 4882;
	public const int RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST = 4883;
	public const int RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY = 4884;
	public const int RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY = 4885;
	public const int RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY = 4886;
	public const int RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST = 4887;
	public const int RPC_CODE_CONTACT_CHATTO_REQUEST = 4888;
	public const int RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY = 4889;
	public const int RPC_CODE_CONTACT_READMSG_REQUEST = 4890;

	
	private static ContactRPC m_Instance = null;
	public static ContactRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ContactRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ContactData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY, AgreeApplicationNotifyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_NEWFRIEND_NOTIFY, NewFriendCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_APPLYLIST_NOTIFY, ApplyListCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY, BeRejectApplyCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY, BeCancelRelationShipCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY, BeAddBlackListCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY, RoleDataUpdateCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY, ContactLoginCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY, ContactLogoutCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY, DeleteRoleDataCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY, UnAcquireGiftPointCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY, AddRoleDataCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY, SetGiftPointCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY, ContactsGroupsCB);
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY, NewChatMsgCB);


		return true;
	}


	/**
	*联系人-->添加好友 RPC请求
	*/
	public void AddFriend(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcAddFriendAskWraper askPBWraper = new ContactRpcAddFriendAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_ADDFRIEND_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAddFriendReplyWraper replyPBWraper = new ContactRpcAddFriendReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->删除好友 RPC请求
	*/
	public void CancelRelationShip(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcCancelRelationShipAskWraper askPBWraper = new ContactRpcCancelRelationShipAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcCancelRelationShipReplyWraper replyPBWraper = new ContactRpcCancelRelationShipReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->加入黑名单 RPC请求
	*/
	public void AddBlackList(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcAddBlackListAskWraper askPBWraper = new ContactRpcAddBlackListAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAddBlackListReplyWraper replyPBWraper = new ContactRpcAddBlackListReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->通讯录数据 RPC请求
	*/
	public void SyncAddressBook(ReplyHandler replyCB)
	{
		ContactRpcSyncAddressBookAskWraper askPBWraper = new ContactRpcSyncAddressBookAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSyncAddressBookReplyWraper replyPBWraper = new ContactRpcSyncAddressBookReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->联系人设置 RPC请求
	*/
	public void ContactSetting(ContactSettingWraper NewSetting, ReplyHandler replyCB)
	{
		ContactRpcContactSettingAskWraper askPBWraper = new ContactRpcContactSettingAskWraper();
		askPBWraper.NewSetting = NewSetting;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_CONTACTSETTING_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcContactSettingReplyWraper replyPBWraper = new ContactRpcContactSettingReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->创建好友分组 RPC请求
	*/
	public void CreateFriendGroup(string GroupName, List<UInt64> RoleIds, ReplyHandler replyCB)
	{
		ContactRpcCreateFriendGroupAskWraper askPBWraper = new ContactRpcCreateFriendGroupAskWraper();
		askPBWraper.GroupName = GroupName;
		askPBWraper.SetRoleIds(RoleIds);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcCreateFriendGroupReplyWraper replyPBWraper = new ContactRpcCreateFriendGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->移动到分组 RPC请求
	*/
	public void MoveToFriendGroup(List<UInt64> RoleIds, int FromGroupId, int ToGroupId, ReplyHandler replyCB)
	{
		ContactRpcMoveToFriendGroupAskWraper askPBWraper = new ContactRpcMoveToFriendGroupAskWraper();
		askPBWraper.SetRoleIds(RoleIds);
		askPBWraper.FromGroupId = FromGroupId;
		askPBWraper.ToGroupId = ToGroupId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcMoveToFriendGroupReplyWraper replyPBWraper = new ContactRpcMoveToFriendGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->删除好友分组 RPC请求
	*/
	public void RemoveFriendGroup(int RemoveGroupId, ReplyHandler replyCB)
	{
		ContactRpcRemoveFriendGroupAskWraper askPBWraper = new ContactRpcRemoveFriendGroupAskWraper();
		askPBWraper.RemoveGroupId = RemoveGroupId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcRemoveFriendGroupReplyWraper replyPBWraper = new ContactRpcRemoveFriendGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->重命名分组 RPC请求
	*/
	public void RenameGroup(string Name, int GroupId, ReplyHandler replyCB)
	{
		ContactRpcRenameGroupAskWraper askPBWraper = new ContactRpcRenameGroupAskWraper();
		askPBWraper.Name = Name;
		askPBWraper.GroupId = GroupId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_RENAMEGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcRenameGroupReplyWraper replyPBWraper = new ContactRpcRenameGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->同意申请加为好友 RPC请求
	*/
	public void AgreeApplication(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcAgreeApplicationAskWraper askPBWraper = new ContactRpcAgreeApplicationAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAgreeApplicationReplyWraper replyPBWraper = new ContactRpcAgreeApplicationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->设置分组 RPC请求
	*/
	public void SetFriendGroup(int GroupId, int RoleIds, byte[] GroupName, ReplyHandler replyCB)
	{
		ContactRpcSetFriendGroupAskWraper askPBWraper = new ContactRpcSetFriendGroupAskWraper();
		askPBWraper.GroupId = GroupId;
		askPBWraper.RoleIds = RoleIds;
		askPBWraper.GroupName = GroupName;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSetFriendGroupReplyWraper replyPBWraper = new ContactRpcSetFriendGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->拒绝申请 RPC请求
	*/
	public void RejectApply(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcRejectApplyAskWraper askPBWraper = new ContactRpcRejectApplyAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_REJECTAPPLY_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcRejectApplyReplyWraper replyPBWraper = new ContactRpcRejectApplyReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->推荐联系人 RPC请求
	*/
	public void RecommendContact(ReplyHandler replyCB)
	{
		ContactRpcRecommendContactAskWraper askPBWraper = new ContactRpcRecommendContactAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcRecommendContactReplyWraper replyPBWraper = new ContactRpcRecommendContactReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->拒绝所有申请 RPC请求
	*/
	public void RejectAll(ReplyHandler replyCB)
	{
		ContactRpcRejectAllAskWraper askPBWraper = new ContactRpcRejectAllAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_REJECTALL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcRejectAllReplyWraper replyPBWraper = new ContactRpcRejectAllReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->添加好友度 RPC请求
	*/
	public void AddFriendShipPoint(UInt64 FriendRoleId, List<ItemSimpleDataWraper> ItemData, ReplyHandler replyCB)
	{
		ContactRpcAddFriendShipPointAskWraper askPBWraper = new ContactRpcAddFriendShipPointAskWraper();
		askPBWraper.FriendRoleId = FriendRoleId;
		askPBWraper.SetItemData(ItemData);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAddFriendShipPointReplyWraper replyPBWraper = new ContactRpcAddFriendShipPointReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->排序分组 RPC请求
	*/
	public void SortGroup(List<int> GroupIds, ReplyHandler replyCB)
	{
		ContactRpcSortGroupAskWraper askPBWraper = new ContactRpcSortGroupAskWraper();
		askPBWraper.SetGroupIds(GroupIds);
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SORTGROUP_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSortGroupReplyWraper replyPBWraper = new ContactRpcSortGroupReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->设置好友名字 RPC请求
	*/
	public void SetFriendAlias(string Name, UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcSetFriendAliasAskWraper askPBWraper = new ContactRpcSetFriendAliasAskWraper();
		askPBWraper.Name = Name;
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSetFriendAliasReplyWraper replyPBWraper = new ContactRpcSetFriendAliasReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->发送好友点 RPC请求
	*/
	public void SendFriendGiftPoint(UInt64 SendRoleId, int Point, ReplyHandler replyCB)
	{
		ContactRpcSendFriendGiftPointAskWraper askPBWraper = new ContactRpcSendFriendGiftPointAskWraper();
		askPBWraper.SendRoleId = SendRoleId;
		askPBWraper.Point = Point;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSendFriendGiftPointReplyWraper replyPBWraper = new ContactRpcSendFriendGiftPointReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->获取点数 RPC请求
	*/
	public void AcquireGiftPoint(UInt64 AcquireRoleId, ReplyHandler replyCB)
	{
		ContactRpcAcquireGiftPointAskWraper askPBWraper = new ContactRpcAcquireGiftPointAskWraper();
		askPBWraper.AcquireRoleId = AcquireRoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAcquireGiftPointReplyWraper replyPBWraper = new ContactRpcAcquireGiftPointReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->一键赠送 RPC请求
	*/
	public void SendAllFriendGiftPoint(ReplyHandler replyCB)
	{
		ContactRpcSendAllFriendGiftPointAskWraper askPBWraper = new ContactRpcSendAllFriendGiftPointAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcSendAllFriendGiftPointReplyWraper replyPBWraper = new ContactRpcSendAllFriendGiftPointReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->一键收取 RPC请求
	*/
	public void AcquireAllGiftPoint(ReplyHandler replyCB)
	{
		ContactRpcAcquireAllGiftPointAskWraper askPBWraper = new ContactRpcAcquireAllGiftPointAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAcquireAllGiftPointReplyWraper replyPBWraper = new ContactRpcAcquireAllGiftPointReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->移出列表 RPC请求
	*/
	public void DeleteGroupRole(int GroupId, UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcDeleteGroupRoleAskWraper askPBWraper = new ContactRpcDeleteGroupRoleAskWraper();
		askPBWraper.GroupId = GroupId;
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcDeleteGroupRoleReplyWraper replyPBWraper = new ContactRpcDeleteGroupRoleReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->同意所有申请 RPC请求
	*/
	public void AgreeAllApplication(ReplyHandler replyCB)
	{
		ContactRpcAgreeAllApplicationAskWraper askPBWraper = new ContactRpcAgreeAllApplicationAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcAgreeAllApplicationReplyWraper replyPBWraper = new ContactRpcAgreeAllApplicationReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->聊天 RPC请求
	*/
	public void ChatTo(UInt64 RoleId, ChatMsgWraper ChatMsg, ReplyHandler replyCB)
	{
		ContactRpcChatToAskWraper askPBWraper = new ContactRpcChatToAskWraper();
		askPBWraper.RoleId = RoleId;
		askPBWraper.ChatMsg = ChatMsg;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_CHATTO_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcChatToReplyWraper replyPBWraper = new ContactRpcChatToReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*联系人-->读取信息 RPC请求
	*/
	public void ReadMsg(UInt64 RoleId, ReplyHandler replyCB)
	{
		ContactRpcReadMsgAskWraper askPBWraper = new ContactRpcReadMsgAskWraper();
		askPBWraper.RoleId = RoleId;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_CONTACT_READMSG_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ContactRpcReadMsgReplyWraper replyPBWraper = new ContactRpcReadMsgReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*联系人-->同意申请通知 服务器通知回调
	*/
	public static void AgreeApplicationNotifyCB( ModMessage notifyMsg )
	{
		ContactRpcAgreeApplicationNotifyNotifyWraper notifyPBWraper = new ContactRpcAgreeApplicationNotifyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( AgreeApplicationNotifyCBDelegate != null )
			AgreeApplicationNotifyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback AgreeApplicationNotifyCBDelegate = null;
	/**
	*联系人-->新朋友 服务器通知回调
	*/
	public static void NewFriendCB( ModMessage notifyMsg )
	{
		ContactRpcNewFriendNotifyWraper notifyPBWraper = new ContactRpcNewFriendNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewFriendCBDelegate != null )
			NewFriendCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewFriendCBDelegate = null;
	/**
	*联系人-->申请列表 服务器通知回调
	*/
	public static void ApplyListCB( ModMessage notifyMsg )
	{
		ContactRpcApplyListNotifyWraper notifyPBWraper = new ContactRpcApplyListNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ApplyListCBDelegate != null )
			ApplyListCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ApplyListCBDelegate = null;
	/**
	*联系人-->被拒绝 服务器通知回调
	*/
	public static void BeRejectApplyCB( ModMessage notifyMsg )
	{
		ContactRpcBeRejectApplyNotifyWraper notifyPBWraper = new ContactRpcBeRejectApplyNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BeRejectApplyCBDelegate != null )
			BeRejectApplyCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BeRejectApplyCBDelegate = null;
	/**
	*联系人-->被删除好友 服务器通知回调
	*/
	public static void BeCancelRelationShipCB( ModMessage notifyMsg )
	{
		ContactRpcBeCancelRelationShipNotifyWraper notifyPBWraper = new ContactRpcBeCancelRelationShipNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BeCancelRelationShipCBDelegate != null )
			BeCancelRelationShipCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BeCancelRelationShipCBDelegate = null;
	/**
	*联系人-->被加入黑名单 服务器通知回调
	*/
	public static void BeAddBlackListCB( ModMessage notifyMsg )
	{
		ContactRpcBeAddBlackListNotifyWraper notifyPBWraper = new ContactRpcBeAddBlackListNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( BeAddBlackListCBDelegate != null )
			BeAddBlackListCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback BeAddBlackListCBDelegate = null;
	/**
	*联系人-->玩家数据更新 服务器通知回调
	*/
	public static void RoleDataUpdateCB( ModMessage notifyMsg )
	{
		ContactRpcRoleDataUpdateNotifyWraper notifyPBWraper = new ContactRpcRoleDataUpdateNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( RoleDataUpdateCBDelegate != null )
			RoleDataUpdateCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback RoleDataUpdateCBDelegate = null;
	/**
	*联系人-->联系人登录 服务器通知回调
	*/
	public static void ContactLoginCB( ModMessage notifyMsg )
	{
		ContactRpcContactLoginNotifyWraper notifyPBWraper = new ContactRpcContactLoginNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ContactLoginCBDelegate != null )
			ContactLoginCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ContactLoginCBDelegate = null;
	/**
	*联系人-->联系人退出游戏 服务器通知回调
	*/
	public static void ContactLogoutCB( ModMessage notifyMsg )
	{
		ContactRpcContactLogoutNotifyWraper notifyPBWraper = new ContactRpcContactLogoutNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ContactLogoutCBDelegate != null )
			ContactLogoutCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ContactLogoutCBDelegate = null;
	/**
	*联系人-->删除联系人数据 服务器通知回调
	*/
	public static void DeleteRoleDataCB( ModMessage notifyMsg )
	{
		ContactRpcDeleteRoleDataNotifyWraper notifyPBWraper = new ContactRpcDeleteRoleDataNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( DeleteRoleDataCBDelegate != null )
			DeleteRoleDataCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback DeleteRoleDataCBDelegate = null;
	/**
	*联系人-->刷新未获取点数 服务器通知回调
	*/
	public static void UnAcquireGiftPointCB( ModMessage notifyMsg )
	{
		ContactRpcUnAcquireGiftPointNotifyWraper notifyPBWraper = new ContactRpcUnAcquireGiftPointNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( UnAcquireGiftPointCBDelegate != null )
			UnAcquireGiftPointCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback UnAcquireGiftPointCBDelegate = null;
	/**
	*联系人-->新加玩家数据 服务器通知回调
	*/
	public static void AddRoleDataCB( ModMessage notifyMsg )
	{
		ContactRpcAddRoleDataNotifyWraper notifyPBWraper = new ContactRpcAddRoleDataNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( AddRoleDataCBDelegate != null )
			AddRoleDataCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback AddRoleDataCBDelegate = null;
	/**
	*联系人-->设置友情点数据 服务器通知回调
	*/
	public static void SetGiftPointCB( ModMessage notifyMsg )
	{
		ContactRpcSetGiftPointNotifyWraper notifyPBWraper = new ContactRpcSetGiftPointNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SetGiftPointCBDelegate != null )
			SetGiftPointCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SetGiftPointCBDelegate = null;
	/**
	*联系人-->刷新组 服务器通知回调
	*/
	public static void ContactsGroupsCB( ModMessage notifyMsg )
	{
		ContactRpcContactsGroupsNotifyWraper notifyPBWraper = new ContactRpcContactsGroupsNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( ContactsGroupsCBDelegate != null )
			ContactsGroupsCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback ContactsGroupsCBDelegate = null;
	/**
	*联系人-->新的聊天信息 服务器通知回调
	*/
	public static void NewChatMsgCB( ModMessage notifyMsg )
	{
		ContactRpcNewChatMsgNotifyWraper notifyPBWraper = new ContactRpcNewChatMsgNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( NewChatMsgCBDelegate != null )
			NewChatMsgCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback NewChatMsgCBDelegate = null;



}

public class ContactData
{
	public enum SyncIdE
	{

	}
	
	private static ContactData m_Instance = null;
	public static ContactData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ContactData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Ex.Logger.Log("ContactData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  


}
