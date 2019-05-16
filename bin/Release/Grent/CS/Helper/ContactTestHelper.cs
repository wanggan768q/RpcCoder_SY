#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ContactRpcAddFriendAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcCancelRelationShipAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcAddBlackListAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcSyncAddressBookAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcContactSettingAskWraperHelper
{
	public ContactSettingWraper NewSetting;
}
[System.Serializable]
public class ContactRpcCreateFriendGroupAskWraperHelper
{
	public string GroupName;
	public List<UInt64> RoleIds;
}
[System.Serializable]
public class ContactRpcMoveToFriendGroupAskWraperHelper
{
	public List<UInt64> RoleIds;
	public int FromGroupId;
	public int ToGroupId;
}
[System.Serializable]
public class ContactRpcRemoveFriendGroupAskWraperHelper
{
	public int RemoveGroupId;
}
[System.Serializable]
public class ContactRpcRenameGroupAskWraperHelper
{
	public string Name;
	public int GroupId;
}
[System.Serializable]
public class ContactRpcAgreeApplicationAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcAgreeApplicationNotifyNotifyWraperHelper
{
	public List<ContactGroupWraper> MyFriendGroup;
	public ContactDataWraper NewFriendData;
}
[System.Serializable]
public class ContactRpcSetFriendGroupAskWraperHelper
{
	public int GroupId;
	public int RoleIds;
	public byte[] GroupName;
}
[System.Serializable]
public class ContactRpcNewFriendNotifyWraperHelper
{
	public ContactDataWraper NewFriendData;
	public ContactGroupWraper MyFriendGroup;
}
[System.Serializable]
public class ContactRpcApplyListNotifyWraperHelper
{
	public ContactDataWraper ApplyFriendData;
	public List<ContactGroupWraper> ApplyGroups;
}
[System.Serializable]
public class ContactRpcRejectApplyAskWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcBeRejectApplyNotifyWraperHelper
{
	public ContactDataWraper DeleteFriendData;
}
[System.Serializable]
public class ContactRpcBeCancelRelationShipNotifyWraperHelper
{
	public UInt64 DeleteRoleId;
	public List<ContactGroupWraper> ContactGroups;
}
[System.Serializable]
public class ContactRpcBeAddBlackListNotifyWraperHelper
{
	public UInt64 RoleId;
	public List<ContactGroupWraper> ContactGroups;
}
[System.Serializable]
public class ContactRpcRecommendContactAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcRejectAllAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcAddFriendShipPointAskWraperHelper
{
	public UInt64 FriendRoleId;
	public List<ItemSimpleDataWraper> ItemData;
}
[System.Serializable]
public class ContactRpcRoleDataUpdateNotifyWraperHelper
{
	public ContactDataWraper Contact;
}
[System.Serializable]
public class ContactRpcContactLoginNotifyWraperHelper
{
	public ContactDataWraper Contact;
	public List<int> GroupIds;
}
[System.Serializable]
public class ContactRpcContactLogoutNotifyWraperHelper
{
	public ContactDataWraper Contact;
	public List<int> GroupIds;
}
[System.Serializable]
public class ContactRpcDeleteRoleDataNotifyWraperHelper
{
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcSortGroupAskWraperHelper
{
	public List<int> GroupIds;
}
[System.Serializable]
public class ContactRpcSetFriendAliasAskWraperHelper
{
	public string Name;
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcSendFriendGiftPointAskWraperHelper
{
	public UInt64 SendRoleId;
	public int Point;
}
[System.Serializable]
public class ContactRpcAcquireGiftPointAskWraperHelper
{
	public UInt64 AcquireRoleId;
}
[System.Serializable]
public class ContactRpcUnAcquireGiftPointNotifyWraperHelper
{
	public List<FriendGiftPointWraper> UnAcquireGiftList;
}
[System.Serializable]
public class ContactRpcSendAllFriendGiftPointAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcAcquireAllGiftPointAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcDeleteGroupRoleAskWraperHelper
{
	public int GroupId;
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcAddRoleDataNotifyWraperHelper
{
	public ContactDataWraper NewRoleData;
}
[System.Serializable]
public class ContactRpcSetGiftPointNotifyWraperHelper
{
	public List<FriendGiftPointWraper> AcquireGiftList;
	public List<FriendGiftPointWraper> UnAcquireGiftList;
	public List<FriendGiftPointWraper> SentGiftList;
}
[System.Serializable]
public class ContactRpcContactsGroupsNotifyWraperHelper
{
	public List<ContactGroupWraper> MyFriendGroup;
}
[System.Serializable]
public class ContactRpcAgreeAllApplicationAskWraperHelper
{
}
[System.Serializable]
public class ContactRpcChatToAskWraperHelper
{
	public UInt64 RoleId;
	public ChatMsgWraper ChatMsg;
}
[System.Serializable]
public class ContactRpcNewChatMsgNotifyWraperHelper
{
	public ChatInfoWraper ChatMsg;
	public UInt64 RoleId;
}
[System.Serializable]
public class ContactRpcReadMsgAskWraperHelper
{
	public UInt64 RoleId;
}



public class ContactTestHelper : MonoBehaviour
{
	public ContactRpcAddFriendAskWraperHelper ContactRpcAddFriendAskWraperVar;
	public ContactRpcCancelRelationShipAskWraperHelper ContactRpcCancelRelationShipAskWraperVar;
	public ContactRpcAddBlackListAskWraperHelper ContactRpcAddBlackListAskWraperVar;
	public ContactRpcSyncAddressBookAskWraperHelper ContactRpcSyncAddressBookAskWraperVar;
	public ContactRpcContactSettingAskWraperHelper ContactRpcContactSettingAskWraperVar;
	public ContactRpcCreateFriendGroupAskWraperHelper ContactRpcCreateFriendGroupAskWraperVar;
	public ContactRpcMoveToFriendGroupAskWraperHelper ContactRpcMoveToFriendGroupAskWraperVar;
	public ContactRpcRemoveFriendGroupAskWraperHelper ContactRpcRemoveFriendGroupAskWraperVar;
	public ContactRpcRenameGroupAskWraperHelper ContactRpcRenameGroupAskWraperVar;
	public ContactRpcAgreeApplicationAskWraperHelper ContactRpcAgreeApplicationAskWraperVar;
	public ContactRpcAgreeApplicationNotifyNotifyWraperHelper ContactRpcAgreeApplicationNotifyNotifyWraperVar;
	public ContactRpcSetFriendGroupAskWraperHelper ContactRpcSetFriendGroupAskWraperVar;
	public ContactRpcNewFriendNotifyWraperHelper ContactRpcNewFriendNotifyWraperVar;
	public ContactRpcApplyListNotifyWraperHelper ContactRpcApplyListNotifyWraperVar;
	public ContactRpcRejectApplyAskWraperHelper ContactRpcRejectApplyAskWraperVar;
	public ContactRpcBeRejectApplyNotifyWraperHelper ContactRpcBeRejectApplyNotifyWraperVar;
	public ContactRpcBeCancelRelationShipNotifyWraperHelper ContactRpcBeCancelRelationShipNotifyWraperVar;
	public ContactRpcBeAddBlackListNotifyWraperHelper ContactRpcBeAddBlackListNotifyWraperVar;
	public ContactRpcRecommendContactAskWraperHelper ContactRpcRecommendContactAskWraperVar;
	public ContactRpcRejectAllAskWraperHelper ContactRpcRejectAllAskWraperVar;
	public ContactRpcAddFriendShipPointAskWraperHelper ContactRpcAddFriendShipPointAskWraperVar;
	public ContactRpcRoleDataUpdateNotifyWraperHelper ContactRpcRoleDataUpdateNotifyWraperVar;
	public ContactRpcContactLoginNotifyWraperHelper ContactRpcContactLoginNotifyWraperVar;
	public ContactRpcContactLogoutNotifyWraperHelper ContactRpcContactLogoutNotifyWraperVar;
	public ContactRpcDeleteRoleDataNotifyWraperHelper ContactRpcDeleteRoleDataNotifyWraperVar;
	public ContactRpcSortGroupAskWraperHelper ContactRpcSortGroupAskWraperVar;
	public ContactRpcSetFriendAliasAskWraperHelper ContactRpcSetFriendAliasAskWraperVar;
	public ContactRpcSendFriendGiftPointAskWraperHelper ContactRpcSendFriendGiftPointAskWraperVar;
	public ContactRpcAcquireGiftPointAskWraperHelper ContactRpcAcquireGiftPointAskWraperVar;
	public ContactRpcUnAcquireGiftPointNotifyWraperHelper ContactRpcUnAcquireGiftPointNotifyWraperVar;
	public ContactRpcSendAllFriendGiftPointAskWraperHelper ContactRpcSendAllFriendGiftPointAskWraperVar;
	public ContactRpcAcquireAllGiftPointAskWraperHelper ContactRpcAcquireAllGiftPointAskWraperVar;
	public ContactRpcDeleteGroupRoleAskWraperHelper ContactRpcDeleteGroupRoleAskWraperVar;
	public ContactRpcAddRoleDataNotifyWraperHelper ContactRpcAddRoleDataNotifyWraperVar;
	public ContactRpcSetGiftPointNotifyWraperHelper ContactRpcSetGiftPointNotifyWraperVar;
	public ContactRpcContactsGroupsNotifyWraperHelper ContactRpcContactsGroupsNotifyWraperVar;
	public ContactRpcAgreeAllApplicationAskWraperHelper ContactRpcAgreeAllApplicationAskWraperVar;
	public ContactRpcChatToAskWraperHelper ContactRpcChatToAskWraperVar;
	public ContactRpcNewChatMsgNotifyWraperHelper ContactRpcNewChatMsgNotifyWraperVar;
	public ContactRpcReadMsgAskWraperHelper ContactRpcReadMsgAskWraperVar;


	public void TestAddFriend()
	{
		ContactRPC.Instance.AddFriend(ContactRpcAddFriendAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestCancelRelationShip()
	{
		ContactRPC.Instance.CancelRelationShip(ContactRpcCancelRelationShipAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestAddBlackList()
	{
		ContactRPC.Instance.AddBlackList(ContactRpcAddBlackListAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestSyncAddressBook()
	{
		ContactRPC.Instance.SyncAddressBook(delegate(object obj){});
	}
	public void TestContactSetting()
	{
		ContactRPC.Instance.ContactSetting(ContactRpcContactSettingAskWraperVar.NewSetting,delegate(object obj){});
	}
	public void TestCreateFriendGroup()
	{
		ContactRPC.Instance.CreateFriendGroup(ContactRpcCreateFriendGroupAskWraperVar.GroupName,ContactRpcCreateFriendGroupAskWraperVar.RoleIds,delegate(object obj){});
	}
	public void TestMoveToFriendGroup()
	{
		ContactRPC.Instance.MoveToFriendGroup(ContactRpcMoveToFriendGroupAskWraperVar.RoleIds,ContactRpcMoveToFriendGroupAskWraperVar.FromGroupId,ContactRpcMoveToFriendGroupAskWraperVar.ToGroupId,delegate(object obj){});
	}
	public void TestRemoveFriendGroup()
	{
		ContactRPC.Instance.RemoveFriendGroup(ContactRpcRemoveFriendGroupAskWraperVar.RemoveGroupId,delegate(object obj){});
	}
	public void TestRenameGroup()
	{
		ContactRPC.Instance.RenameGroup(ContactRpcRenameGroupAskWraperVar.Name,ContactRpcRenameGroupAskWraperVar.GroupId,delegate(object obj){});
	}
	public void TestAgreeApplication()
	{
		ContactRPC.Instance.AgreeApplication(ContactRpcAgreeApplicationAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestSetFriendGroup()
	{
		ContactRPC.Instance.SetFriendGroup(ContactRpcSetFriendGroupAskWraperVar.GroupId,ContactRpcSetFriendGroupAskWraperVar.RoleIds,ContactRpcSetFriendGroupAskWraperVar.GroupName,delegate(object obj){});
	}
	public void TestRejectApply()
	{
		ContactRPC.Instance.RejectApply(ContactRpcRejectApplyAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestRecommendContact()
	{
		ContactRPC.Instance.RecommendContact(delegate(object obj){});
	}
	public void TestRejectAll()
	{
		ContactRPC.Instance.RejectAll(delegate(object obj){});
	}
	public void TestAddFriendShipPoint()
	{
		ContactRPC.Instance.AddFriendShipPoint(ContactRpcAddFriendShipPointAskWraperVar.FriendRoleId,ContactRpcAddFriendShipPointAskWraperVar.ItemData,delegate(object obj){});
	}
	public void TestSortGroup()
	{
		ContactRPC.Instance.SortGroup(ContactRpcSortGroupAskWraperVar.GroupIds,delegate(object obj){});
	}
	public void TestSetFriendAlias()
	{
		ContactRPC.Instance.SetFriendAlias(ContactRpcSetFriendAliasAskWraperVar.Name,ContactRpcSetFriendAliasAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestSendFriendGiftPoint()
	{
		ContactRPC.Instance.SendFriendGiftPoint(ContactRpcSendFriendGiftPointAskWraperVar.SendRoleId,ContactRpcSendFriendGiftPointAskWraperVar.Point,delegate(object obj){});
	}
	public void TestAcquireGiftPoint()
	{
		ContactRPC.Instance.AcquireGiftPoint(ContactRpcAcquireGiftPointAskWraperVar.AcquireRoleId,delegate(object obj){});
	}
	public void TestSendAllFriendGiftPoint()
	{
		ContactRPC.Instance.SendAllFriendGiftPoint(delegate(object obj){});
	}
	public void TestAcquireAllGiftPoint()
	{
		ContactRPC.Instance.AcquireAllGiftPoint(delegate(object obj){});
	}
	public void TestDeleteGroupRole()
	{
		ContactRPC.Instance.DeleteGroupRole(ContactRpcDeleteGroupRoleAskWraperVar.GroupId,ContactRpcDeleteGroupRoleAskWraperVar.RoleId,delegate(object obj){});
	}
	public void TestAgreeAllApplication()
	{
		ContactRPC.Instance.AgreeAllApplication(delegate(object obj){});
	}
	public void TestChatTo()
	{
		ContactRPC.Instance.ChatTo(ContactRpcChatToAskWraperVar.RoleId,ContactRpcChatToAskWraperVar.ChatMsg,delegate(object obj){});
	}
	public void TestReadMsg()
	{
		ContactRPC.Instance.ReadMsg(ContactRpcReadMsgAskWraperVar.RoleId,delegate(object obj){});
	}


}

[CustomEditor(typeof(ContactTestHelper))]
public class ContactTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("AddFriend"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAddFriend();
		}
		if (GUILayout.Button("CancelRelationShip"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestCancelRelationShip();
		}
		if (GUILayout.Button("AddBlackList"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAddBlackList();
		}
		if (GUILayout.Button("SyncAddressBook"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSyncAddressBook();
		}
		if (GUILayout.Button("ContactSetting"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestContactSetting();
		}
		if (GUILayout.Button("CreateFriendGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestCreateFriendGroup();
		}
		if (GUILayout.Button("MoveToFriendGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestMoveToFriendGroup();
		}
		if (GUILayout.Button("RemoveFriendGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestRemoveFriendGroup();
		}
		if (GUILayout.Button("RenameGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestRenameGroup();
		}
		if (GUILayout.Button("AgreeApplication"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAgreeApplication();
		}
		if (GUILayout.Button("SetFriendGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSetFriendGroup();
		}
		if (GUILayout.Button("RejectApply"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestRejectApply();
		}
		if (GUILayout.Button("RecommendContact"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestRecommendContact();
		}
		if (GUILayout.Button("RejectAll"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestRejectAll();
		}
		if (GUILayout.Button("AddFriendShipPoint"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAddFriendShipPoint();
		}
		if (GUILayout.Button("SortGroup"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSortGroup();
		}
		if (GUILayout.Button("SetFriendAlias"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSetFriendAlias();
		}
		if (GUILayout.Button("SendFriendGiftPoint"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSendFriendGiftPoint();
		}
		if (GUILayout.Button("AcquireGiftPoint"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAcquireGiftPoint();
		}
		if (GUILayout.Button("SendAllFriendGiftPoint"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestSendAllFriendGiftPoint();
		}
		if (GUILayout.Button("AcquireAllGiftPoint"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAcquireAllGiftPoint();
		}
		if (GUILayout.Button("DeleteGroupRole"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestDeleteGroupRole();
		}
		if (GUILayout.Button("AgreeAllApplication"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestAgreeAllApplication();
		}
		if (GUILayout.Button("ChatTo"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestChatTo();
		}
		if (GUILayout.Button("ReadMsg"))
		{
			ContactTestHelper rpc = target as ContactTestHelper;
			if( rpc ) rpc.TestReadMsg();
		}


    }

}
#endif