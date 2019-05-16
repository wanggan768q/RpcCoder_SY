
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBContact.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//添加好友请求封装类
[System.Serializable]
public class ContactRpcAddFriendAskWraper
{

	//构造函数
	public ContactRpcAddFriendAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddFriendAsk ToPB()
	{
		ContactRpcAddFriendAsk v = new ContactRpcAddFriendAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddFriendAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddFriendAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddFriendAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddFriendAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//新加朋友的id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//添加好友回应封装类
[System.Serializable]
public class ContactRpcAddFriendReplyWraper
{

	//构造函数
	public ContactRpcAddFriendReplyWraper()
	{
		 m_Result = -1;
		 m_NewFriendData = new ContactDataWraper();
		 m_MyFriendGroup = new ContactGroupWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_NewFriendData = new ContactDataWraper();
		 m_MyFriendGroup = new ContactGroupWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddFriendReply ToPB()
	{
		ContactRpcAddFriendReply v = new ContactRpcAddFriendReply();
		v.Result = m_Result;
		v.NewFriendData = m_NewFriendData.ToPB();
		v.MyFriendGroup = m_MyFriendGroup.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddFriendReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewFriendData.FromPB(v.NewFriendData);
		m_MyFriendGroup.FromPB(v.MyFriendGroup);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddFriendReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddFriendReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddFriendReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//新玩家数据
	public ContactDataWraper m_NewFriendData;
	public ContactDataWraper NewFriendData
	{
		get { return m_NewFriendData;}
		set { m_NewFriendData = value; }
	}
	//好友分组
	public ContactGroupWraper m_MyFriendGroup;
	public ContactGroupWraper MyFriendGroup
	{
		get { return m_MyFriendGroup;}
		set { m_MyFriendGroup = value; }
	}


};
//删除好友请求封装类
[System.Serializable]
public class ContactRpcCancelRelationShipAskWraper
{

	//构造函数
	public ContactRpcCancelRelationShipAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcCancelRelationShipAsk ToPB()
	{
		ContactRpcCancelRelationShipAsk v = new ContactRpcCancelRelationShipAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcCancelRelationShipAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcCancelRelationShipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcCancelRelationShipAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcCancelRelationShipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//删除的好友
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//删除好友回应封装类
[System.Serializable]
public class ContactRpcCancelRelationShipReplyWraper
{

	//构造函数
	public ContactRpcCancelRelationShipReplyWraper()
	{
		 m_Result = -1;
		 m_DeleteRoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_DeleteRoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcCancelRelationShipReply ToPB()
	{
		ContactRpcCancelRelationShipReply v = new ContactRpcCancelRelationShipReply();
		v.Result = m_Result;
		v.DeleteRoleId = m_DeleteRoleId;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcCancelRelationShipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DeleteRoleId = v.DeleteRoleId;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcCancelRelationShipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcCancelRelationShipReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcCancelRelationShipReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//删除的数据
	public UInt64 m_DeleteRoleId;
	public UInt64 DeleteRoleId
	{
		get { return m_DeleteRoleId;}
		set { m_DeleteRoleId = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}


};
//加入黑名单请求封装类
[System.Serializable]
public class ContactRpcAddBlackListAskWraper
{

	//构造函数
	public ContactRpcAddBlackListAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddBlackListAsk ToPB()
	{
		ContactRpcAddBlackListAsk v = new ContactRpcAddBlackListAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddBlackListAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddBlackListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddBlackListAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddBlackListAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//删除的好友
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//加入黑名单回应封装类
[System.Serializable]
public class ContactRpcAddBlackListReplyWraper
{

	//构造函数
	public ContactRpcAddBlackListReplyWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddBlackListReply ToPB()
	{
		ContactRpcAddBlackListReply v = new ContactRpcAddBlackListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddBlackListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddBlackListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddBlackListReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddBlackListReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}
	//删除的数据
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//通讯录数据请求封装类
[System.Serializable]
public class ContactRpcSyncAddressBookAskWraper
{

	//构造函数
	public ContactRpcSyncAddressBookAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSyncAddressBookAsk ToPB()
	{
		ContactRpcSyncAddressBookAsk v = new ContactRpcSyncAddressBookAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSyncAddressBookAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSyncAddressBookAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSyncAddressBookAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSyncAddressBookAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//通讯录数据回应封装类
[System.Serializable]
public class ContactRpcSyncAddressBookReplyWraper
{

	//构造函数
	public ContactRpcSyncAddressBookReplyWraper()
	{
		 m_Result = -1;
		 m_AddressBock = new AddressBookWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_AddressBock = new AddressBookWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSyncAddressBookReply ToPB()
	{
		ContactRpcSyncAddressBookReply v = new ContactRpcSyncAddressBookReply();
		v.Result = m_Result;
		v.AddressBock = m_AddressBock.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSyncAddressBookReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AddressBock.FromPB(v.AddressBock);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSyncAddressBookReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSyncAddressBookReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSyncAddressBookReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//通讯录数据
	public AddressBookWraper m_AddressBock;
	public AddressBookWraper AddressBock
	{
		get { return m_AddressBock;}
		set { m_AddressBock = value; }
	}


};
//联系人设置请求封装类
[System.Serializable]
public class ContactRpcContactSettingAskWraper
{

	//构造函数
	public ContactRpcContactSettingAskWraper()
	{
		 m_NewSetting = new ContactSettingWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NewSetting = new ContactSettingWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcContactSettingAsk ToPB()
	{
		ContactRpcContactSettingAsk v = new ContactRpcContactSettingAsk();
		v.NewSetting = m_NewSetting.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcContactSettingAsk v)
	{
        if (v == null)
            return;
		m_NewSetting.FromPB(v.NewSetting);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcContactSettingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcContactSettingAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcContactSettingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//新设置
	public ContactSettingWraper m_NewSetting;
	public ContactSettingWraper NewSetting
	{
		get { return m_NewSetting;}
		set { m_NewSetting = value; }
	}


};
//联系人设置回应封装类
[System.Serializable]
public class ContactRpcContactSettingReplyWraper
{

	//构造函数
	public ContactRpcContactSettingReplyWraper()
	{
		 m_Result = -1;
		 m_NewSetting = new ContactSettingWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_NewSetting = new ContactSettingWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcContactSettingReply ToPB()
	{
		ContactRpcContactSettingReply v = new ContactRpcContactSettingReply();
		v.Result = m_Result;
		v.NewSetting = m_NewSetting.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcContactSettingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewSetting.FromPB(v.NewSetting);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcContactSettingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcContactSettingReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcContactSettingReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//新设置
	public ContactSettingWraper m_NewSetting;
	public ContactSettingWraper NewSetting
	{
		get { return m_NewSetting;}
		set { m_NewSetting = value; }
	}


};
//创建好友分组请求封装类
[System.Serializable]
public class ContactRpcCreateFriendGroupAskWraper
{

	//构造函数
	public ContactRpcCreateFriendGroupAskWraper()
	{
		 m_GroupName = "";
		m_RoleIds = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GroupName = "";
		m_RoleIds = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcCreateFriendGroupAsk ToPB()
	{
		ContactRpcCreateFriendGroupAsk v = new ContactRpcCreateFriendGroupAsk();
		v.GroupName = m_GroupName;
		for (int i=0; i<(int)m_RoleIds.Count; i++)
			v.RoleIds.Add( m_RoleIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcCreateFriendGroupAsk v)
	{
        if (v == null)
            return;
		m_GroupName = v.GroupName;
		m_RoleIds.Clear();
		for( int i=0; i<v.RoleIds.Count; i++)
			m_RoleIds.Add(v.RoleIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcCreateFriendGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcCreateFriendGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcCreateFriendGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组名字
	public string m_GroupName;
	public string GroupName
	{
		get { return m_GroupName;}
		set { m_GroupName = value; }
	}
	//分组玩家id
	public List<UInt64> m_RoleIds;
	public int SizeRoleIds()
	{
		return m_RoleIds.Count;
	}
	public List<UInt64> GetRoleIds()
	{
		return m_RoleIds;
	}
	public UInt64 GetRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return 0;
		return m_RoleIds[Index];
	}
	public void SetRoleIds( List<UInt64> v )
	{
		m_RoleIds=v;
	}
	public void SetRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return;
		m_RoleIds[Index] = v;
	}
	public void AddRoleIds( UInt64 v=0 )
	{
		m_RoleIds.Add(v);
	}
	public void ClearRoleIds( )
	{
		m_RoleIds.Clear();
	}


};
//创建好友分组回应封装类
[System.Serializable]
public class ContactRpcCreateFriendGroupReplyWraper
{

	//构造函数
	public ContactRpcCreateFriendGroupReplyWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcCreateFriendGroupReply ToPB()
	{
		ContactRpcCreateFriendGroupReply v = new ContactRpcCreateFriendGroupReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcCreateFriendGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcCreateFriendGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcCreateFriendGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcCreateFriendGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}
	//排序分组id
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//移动到分组请求封装类
[System.Serializable]
public class ContactRpcMoveToFriendGroupAskWraper
{

	//构造函数
	public ContactRpcMoveToFriendGroupAskWraper()
	{
		m_RoleIds = new List<UInt64>();
		 m_FromGroupId = -1;
		 m_ToGroupId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_RoleIds = new List<UInt64>();
		 m_FromGroupId = -1;
		 m_ToGroupId = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcMoveToFriendGroupAsk ToPB()
	{
		ContactRpcMoveToFriendGroupAsk v = new ContactRpcMoveToFriendGroupAsk();
		for (int i=0; i<(int)m_RoleIds.Count; i++)
			v.RoleIds.Add( m_RoleIds[i]);
		v.FromGroupId = m_FromGroupId;
		v.ToGroupId = m_ToGroupId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcMoveToFriendGroupAsk v)
	{
        if (v == null)
            return;
		m_RoleIds.Clear();
		for( int i=0; i<v.RoleIds.Count; i++)
			m_RoleIds.Add(v.RoleIds[i]);
		m_FromGroupId = v.FromGroupId;
		m_ToGroupId = v.ToGroupId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcMoveToFriendGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcMoveToFriendGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcMoveToFriendGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家Id
	public List<UInt64> m_RoleIds;
	public int SizeRoleIds()
	{
		return m_RoleIds.Count;
	}
	public List<UInt64> GetRoleIds()
	{
		return m_RoleIds;
	}
	public UInt64 GetRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return 0;
		return m_RoleIds[Index];
	}
	public void SetRoleIds( List<UInt64> v )
	{
		m_RoleIds=v;
	}
	public void SetRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return;
		m_RoleIds[Index] = v;
	}
	public void AddRoleIds( UInt64 v=0 )
	{
		m_RoleIds.Add(v);
	}
	public void ClearRoleIds( )
	{
		m_RoleIds.Clear();
	}
	//源组ID
	public int m_FromGroupId;
	public int FromGroupId
	{
		get { return m_FromGroupId;}
		set { m_FromGroupId = value; }
	}
	//目标组
	public int m_ToGroupId;
	public int ToGroupId
	{
		get { return m_ToGroupId;}
		set { m_ToGroupId = value; }
	}


};
//移动到分组回应封装类
[System.Serializable]
public class ContactRpcMoveToFriendGroupReplyWraper
{

	//构造函数
	public ContactRpcMoveToFriendGroupReplyWraper()
	{
		 m_Result = -1;
		m_ChangeGroup = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ChangeGroup = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcMoveToFriendGroupReply ToPB()
	{
		ContactRpcMoveToFriendGroupReply v = new ContactRpcMoveToFriendGroupReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ChangeGroup.Count; i++)
			v.ChangeGroup.Add( m_ChangeGroup[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcMoveToFriendGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ChangeGroup.Clear();
		for( int i=0; i<v.ChangeGroup.Count; i++)
			m_ChangeGroup.Add( new ContactGroupWraper());
		for( int i=0; i<v.ChangeGroup.Count; i++)
			m_ChangeGroup[i].FromPB(v.ChangeGroup[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcMoveToFriendGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcMoveToFriendGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcMoveToFriendGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//移动来源组
	public List<ContactGroupWraper> m_ChangeGroup;
	public int SizeChangeGroup()
	{
		return m_ChangeGroup.Count;
	}
	public List<ContactGroupWraper> GetChangeGroup()
	{
		return m_ChangeGroup;
	}
	public ContactGroupWraper GetChangeGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_ChangeGroup.Count)
			return new ContactGroupWraper();
		return m_ChangeGroup[Index];
	}
	public void SetChangeGroup( List<ContactGroupWraper> v )
	{
		m_ChangeGroup=v;
	}
	public void SetChangeGroup( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ChangeGroup.Count)
			return;
		m_ChangeGroup[Index] = v;
	}
	public void AddChangeGroup( ContactGroupWraper v )
	{
		m_ChangeGroup.Add(v);
	}
	public void ClearChangeGroup( )
	{
		m_ChangeGroup.Clear();
	}


};
//删除好友分组请求封装类
[System.Serializable]
public class ContactRpcRemoveFriendGroupAskWraper
{

	//构造函数
	public ContactRpcRemoveFriendGroupAskWraper()
	{
		 m_RemoveGroupId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RemoveGroupId = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRemoveFriendGroupAsk ToPB()
	{
		ContactRpcRemoveFriendGroupAsk v = new ContactRpcRemoveFriendGroupAsk();
		v.RemoveGroupId = m_RemoveGroupId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRemoveFriendGroupAsk v)
	{
        if (v == null)
            return;
		m_RemoveGroupId = v.RemoveGroupId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRemoveFriendGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRemoveFriendGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcRemoveFriendGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//源组ID
	public int m_RemoveGroupId;
	public int RemoveGroupId
	{
		get { return m_RemoveGroupId;}
		set { m_RemoveGroupId = value; }
	}


};
//删除好友分组回应封装类
[System.Serializable]
public class ContactRpcRemoveFriendGroupReplyWraper
{

	//构造函数
	public ContactRpcRemoveFriendGroupReplyWraper()
	{
		 m_Result = -1;
		 m_MyFriendGroup = new ContactGroupWraper();
		 m_RemoveGroupId = -1;
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_MyFriendGroup = new ContactGroupWraper();
		 m_RemoveGroupId = -1;
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRemoveFriendGroupReply ToPB()
	{
		ContactRpcRemoveFriendGroupReply v = new ContactRpcRemoveFriendGroupReply();
		v.Result = m_Result;
		v.MyFriendGroup = m_MyFriendGroup.ToPB();
		v.RemoveGroupId = m_RemoveGroupId;
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRemoveFriendGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_MyFriendGroup.FromPB(v.MyFriendGroup);
		m_RemoveGroupId = v.RemoveGroupId;
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRemoveFriendGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRemoveFriendGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcRemoveFriendGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//移动来源组
	public ContactGroupWraper m_MyFriendGroup;
	public ContactGroupWraper MyFriendGroup
	{
		get { return m_MyFriendGroup;}
		set { m_MyFriendGroup = value; }
	}
	//源组ID
	public int m_RemoveGroupId;
	public int RemoveGroupId
	{
		get { return m_RemoveGroupId;}
		set { m_RemoveGroupId = value; }
	}
	//排序分组id
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//重命名分组请求封装类
[System.Serializable]
public class ContactRpcRenameGroupAskWraper
{

	//构造函数
	public ContactRpcRenameGroupAskWraper()
	{
		 m_Name = "";
		 m_GroupId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Name = "";
		 m_GroupId = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRenameGroupAsk ToPB()
	{
		ContactRpcRenameGroupAsk v = new ContactRpcRenameGroupAsk();
		v.Name = m_Name;
		v.GroupId = m_GroupId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRenameGroupAsk v)
	{
        if (v == null)
            return;
		m_Name = v.Name;
		m_GroupId = v.GroupId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRenameGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRenameGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcRenameGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//设置名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//重命名分组
	public int m_GroupId;
	public int GroupId
	{
		get { return m_GroupId;}
		set { m_GroupId = value; }
	}


};
//重命名分组回应封装类
[System.Serializable]
public class ContactRpcRenameGroupReplyWraper
{

	//构造函数
	public ContactRpcRenameGroupReplyWraper()
	{
		 m_Result = -1;
		 m_DefineGroup = new ContactGroupWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_DefineGroup = new ContactGroupWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRenameGroupReply ToPB()
	{
		ContactRpcRenameGroupReply v = new ContactRpcRenameGroupReply();
		v.Result = m_Result;
		v.DefineGroup = m_DefineGroup.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRenameGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DefineGroup.FromPB(v.DefineGroup);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRenameGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRenameGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcRenameGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//重命名的分组
	public ContactGroupWraper m_DefineGroup;
	public ContactGroupWraper DefineGroup
	{
		get { return m_DefineGroup;}
		set { m_DefineGroup = value; }
	}


};
//同意申请加为好友请求封装类
[System.Serializable]
public class ContactRpcAgreeApplicationAskWraper
{

	//构造函数
	public ContactRpcAgreeApplicationAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAgreeApplicationAsk ToPB()
	{
		ContactRpcAgreeApplicationAsk v = new ContactRpcAgreeApplicationAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAgreeApplicationAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAgreeApplicationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAgreeApplicationAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAgreeApplicationAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//同意申请加为好友回应封装类
[System.Serializable]
public class ContactRpcAgreeApplicationReplyWraper
{

	//构造函数
	public ContactRpcAgreeApplicationReplyWraper()
	{
		 m_Result = -1;
		 m_NewFriendData = new ContactDataWraper();
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_NewFriendData = new ContactDataWraper();
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAgreeApplicationReply ToPB()
	{
		ContactRpcAgreeApplicationReply v = new ContactRpcAgreeApplicationReply();
		v.Result = m_Result;
		v.NewFriendData = m_NewFriendData.ToPB();
		for (int i=0; i<(int)m_MyFriendGroup.Count; i++)
			v.MyFriendGroup.Add( m_MyFriendGroup[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAgreeApplicationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewFriendData.FromPB(v.NewFriendData);
		m_MyFriendGroup.Clear();
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup.Add( new ContactGroupWraper());
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup[i].FromPB(v.MyFriendGroup[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAgreeApplicationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAgreeApplicationReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAgreeApplicationReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//新玩家数据
	public ContactDataWraper m_NewFriendData;
	public ContactDataWraper NewFriendData
	{
		get { return m_NewFriendData;}
		set { m_NewFriendData = value; }
	}
	//移动来源组
	public List<ContactGroupWraper> m_MyFriendGroup;
	public int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.Count;
	}
	public List<ContactGroupWraper> GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	public ContactGroupWraper GetMyFriendGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return new ContactGroupWraper();
		return m_MyFriendGroup[Index];
	}
	public void SetMyFriendGroup( List<ContactGroupWraper> v )
	{
		m_MyFriendGroup=v;
	}
	public void SetMyFriendGroup( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return;
		m_MyFriendGroup[Index] = v;
	}
	public void AddMyFriendGroup( ContactGroupWraper v )
	{
		m_MyFriendGroup.Add(v);
	}
	public void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.Clear();
	}


};
//同意申请通知通知封装类
[System.Serializable]
public class ContactRpcAgreeApplicationNotifyNotifyWraper
{

	//构造函数
	public ContactRpcAgreeApplicationNotifyNotifyWraper()
	{
		m_MyFriendGroup = new List<ContactGroupWraper>();
		 m_NewFriendData = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		m_MyFriendGroup = new List<ContactGroupWraper>();
		 m_NewFriendData = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAgreeApplicationNotifyNotify ToPB()
	{
		ContactRpcAgreeApplicationNotifyNotify v = new ContactRpcAgreeApplicationNotifyNotify();
		for (int i=0; i<(int)m_MyFriendGroup.Count; i++)
			v.MyFriendGroup.Add( m_MyFriendGroup[i].ToPB());
		v.NewFriendData = m_NewFriendData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAgreeApplicationNotifyNotify v)
	{
        if (v == null)
            return;
		m_MyFriendGroup.Clear();
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup.Add( new ContactGroupWraper());
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup[i].FromPB(v.MyFriendGroup[i]);
		m_NewFriendData.FromPB(v.NewFriendData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAgreeApplicationNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAgreeApplicationNotifyNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcAgreeApplicationNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组信息
	public List<ContactGroupWraper> m_MyFriendGroup;
	public int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.Count;
	}
	public List<ContactGroupWraper> GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	public ContactGroupWraper GetMyFriendGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return new ContactGroupWraper();
		return m_MyFriendGroup[Index];
	}
	public void SetMyFriendGroup( List<ContactGroupWraper> v )
	{
		m_MyFriendGroup=v;
	}
	public void SetMyFriendGroup( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return;
		m_MyFriendGroup[Index] = v;
	}
	public void AddMyFriendGroup( ContactGroupWraper v )
	{
		m_MyFriendGroup.Add(v);
	}
	public void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.Clear();
	}
	//新玩家数据
	public ContactDataWraper m_NewFriendData;
	public ContactDataWraper NewFriendData
	{
		get { return m_NewFriendData;}
		set { m_NewFriendData = value; }
	}


};
//设置分组请求封装类
[System.Serializable]
public class ContactRpcSetFriendGroupAskWraper
{

	//构造函数
	public ContactRpcSetFriendGroupAskWraper()
	{
		 m_GroupId = -1;
		 m_RoleIds = -1;
		 m_GroupName = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GroupId = -1;
		 m_RoleIds = -1;
		 m_GroupName = new byte[0];

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSetFriendGroupAsk ToPB()
	{
		ContactRpcSetFriendGroupAsk v = new ContactRpcSetFriendGroupAsk();
		v.GroupId = m_GroupId;
		v.RoleIds = m_RoleIds;
		v.GroupName = m_GroupName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSetFriendGroupAsk v)
	{
        if (v == null)
            return;
		m_GroupId = v.GroupId;
		m_RoleIds = v.RoleIds;
		m_GroupName = v.GroupName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSetFriendGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSetFriendGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSetFriendGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组ID
	public int m_GroupId;
	public int GroupId
	{
		get { return m_GroupId;}
		set { m_GroupId = value; }
	}
	//好友id
	public int m_RoleIds;
	public int RoleIds
	{
		get { return m_RoleIds;}
		set { m_RoleIds = value; }
	}
	//分组名字
	public byte[] m_GroupName;
	public byte[] GroupName
	{
		get { return m_GroupName;}
		set { m_GroupName = value; }
	}


};
//设置分组回应封装类
[System.Serializable]
public class ContactRpcSetFriendGroupReplyWraper
{

	//构造函数
	public ContactRpcSetFriendGroupReplyWraper()
	{
		 m_Result = -1;
		m_FriendGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_FriendGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSetFriendGroupReply ToPB()
	{
		ContactRpcSetFriendGroupReply v = new ContactRpcSetFriendGroupReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_FriendGroups.Count; i++)
			v.FriendGroups.Add( m_FriendGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSetFriendGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_FriendGroups.Clear();
		for( int i=0; i<v.FriendGroups.Count; i++)
			m_FriendGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.FriendGroups.Count; i++)
			m_FriendGroups[i].FromPB(v.FriendGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSetFriendGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSetFriendGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSetFriendGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//分组信息
	public List<ContactGroupWraper> m_FriendGroups;
	public int SizeFriendGroups()
	{
		return m_FriendGroups.Count;
	}
	public List<ContactGroupWraper> GetFriendGroups()
	{
		return m_FriendGroups;
	}
	public ContactGroupWraper GetFriendGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_FriendGroups.Count)
			return new ContactGroupWraper();
		return m_FriendGroups[Index];
	}
	public void SetFriendGroups( List<ContactGroupWraper> v )
	{
		m_FriendGroups=v;
	}
	public void SetFriendGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_FriendGroups.Count)
			return;
		m_FriendGroups[Index] = v;
	}
	public void AddFriendGroups( ContactGroupWraper v )
	{
		m_FriendGroups.Add(v);
	}
	public void ClearFriendGroups( )
	{
		m_FriendGroups.Clear();
	}


};
//新联系人通知,不是朋友封装类
[System.Serializable]
public class ContactRpcNewFriendNotifyWraper
{

	//构造函数
	public ContactRpcNewFriendNotifyWraper()
	{
		 m_NewFriendData = new ContactDataWraper();
		 m_MyFriendGroup = new ContactGroupWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NewFriendData = new ContactDataWraper();
		 m_MyFriendGroup = new ContactGroupWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcNewFriendNotify ToPB()
	{
		ContactRpcNewFriendNotify v = new ContactRpcNewFriendNotify();
		v.NewFriendData = m_NewFriendData.ToPB();
		v.MyFriendGroup = m_MyFriendGroup.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcNewFriendNotify v)
	{
        if (v == null)
            return;
		m_NewFriendData.FromPB(v.NewFriendData);
		m_MyFriendGroup.FromPB(v.MyFriendGroup);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcNewFriendNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcNewFriendNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcNewFriendNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新的联系人数据
	public ContactDataWraper m_NewFriendData;
	public ContactDataWraper NewFriendData
	{
		get { return m_NewFriendData;}
		set { m_NewFriendData = value; }
	}
	//新的联系人改变的组
	public ContactGroupWraper m_MyFriendGroup;
	public ContactGroupWraper MyFriendGroup
	{
		get { return m_MyFriendGroup;}
		set { m_MyFriendGroup = value; }
	}


};
//申请列表通知封装类
[System.Serializable]
public class ContactRpcApplyListNotifyWraper
{

	//构造函数
	public ContactRpcApplyListNotifyWraper()
	{
		 m_ApplyFriendData = new ContactDataWraper();
		m_ApplyGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ApplyFriendData = new ContactDataWraper();
		m_ApplyGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcApplyListNotify ToPB()
	{
		ContactRpcApplyListNotify v = new ContactRpcApplyListNotify();
		v.ApplyFriendData = m_ApplyFriendData.ToPB();
		for (int i=0; i<(int)m_ApplyGroups.Count; i++)
			v.ApplyGroups.Add( m_ApplyGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcApplyListNotify v)
	{
        if (v == null)
            return;
		m_ApplyFriendData.FromPB(v.ApplyFriendData);
		m_ApplyGroups.Clear();
		for( int i=0; i<v.ApplyGroups.Count; i++)
			m_ApplyGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ApplyGroups.Count; i++)
			m_ApplyGroups[i].FromPB(v.ApplyGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcApplyListNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcApplyListNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcApplyListNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新玩家数据
	public ContactDataWraper m_ApplyFriendData;
	public ContactDataWraper ApplyFriendData
	{
		get { return m_ApplyFriendData;}
		set { m_ApplyFriendData = value; }
	}
	//分组信息
	public List<ContactGroupWraper> m_ApplyGroups;
	public int SizeApplyGroups()
	{
		return m_ApplyGroups.Count;
	}
	public List<ContactGroupWraper> GetApplyGroups()
	{
		return m_ApplyGroups;
	}
	public ContactGroupWraper GetApplyGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ApplyGroups.Count)
			return new ContactGroupWraper();
		return m_ApplyGroups[Index];
	}
	public void SetApplyGroups( List<ContactGroupWraper> v )
	{
		m_ApplyGroups=v;
	}
	public void SetApplyGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ApplyGroups.Count)
			return;
		m_ApplyGroups[Index] = v;
	}
	public void AddApplyGroups( ContactGroupWraper v )
	{
		m_ApplyGroups.Add(v);
	}
	public void ClearApplyGroups( )
	{
		m_ApplyGroups.Clear();
	}


};
//拒绝申请请求封装类
[System.Serializable]
public class ContactRpcRejectApplyAskWraper
{

	//构造函数
	public ContactRpcRejectApplyAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRejectApplyAsk ToPB()
	{
		ContactRpcRejectApplyAsk v = new ContactRpcRejectApplyAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRejectApplyAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRejectApplyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRejectApplyAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcRejectApplyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//拒绝申请回应封装类
[System.Serializable]
public class ContactRpcRejectApplyReplyWraper
{

	//构造函数
	public ContactRpcRejectApplyReplyWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_DeleteRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_DeleteRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRejectApplyReply ToPB()
	{
		ContactRpcRejectApplyReply v = new ContactRpcRejectApplyReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());
		v.DeleteRoleId = m_DeleteRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRejectApplyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);
		m_DeleteRoleId = v.DeleteRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRejectApplyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRejectApplyReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcRejectApplyReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}
	//删除的id
	public UInt64 m_DeleteRoleId;
	public UInt64 DeleteRoleId
	{
		get { return m_DeleteRoleId;}
		set { m_DeleteRoleId = value; }
	}


};
//被拒绝通知封装类
[System.Serializable]
public class ContactRpcBeRejectApplyNotifyWraper
{

	//构造函数
	public ContactRpcBeRejectApplyNotifyWraper()
	{
		 m_DeleteFriendData = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DeleteFriendData = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcBeRejectApplyNotify ToPB()
	{
		ContactRpcBeRejectApplyNotify v = new ContactRpcBeRejectApplyNotify();
		v.DeleteFriendData = m_DeleteFriendData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcBeRejectApplyNotify v)
	{
        if (v == null)
            return;
		m_DeleteFriendData.FromPB(v.DeleteFriendData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcBeRejectApplyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcBeRejectApplyNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcBeRejectApplyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//被拒绝的人信息,不要加到role data里面
	public ContactDataWraper m_DeleteFriendData;
	public ContactDataWraper DeleteFriendData
	{
		get { return m_DeleteFriendData;}
		set { m_DeleteFriendData = value; }
	}


};
//被删除好友通知封装类
[System.Serializable]
public class ContactRpcBeCancelRelationShipNotifyWraper
{

	//构造函数
	public ContactRpcBeCancelRelationShipNotifyWraper()
	{
		 m_DeleteRoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DeleteRoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcBeCancelRelationShipNotify ToPB()
	{
		ContactRpcBeCancelRelationShipNotify v = new ContactRpcBeCancelRelationShipNotify();
		v.DeleteRoleId = m_DeleteRoleId;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcBeCancelRelationShipNotify v)
	{
        if (v == null)
            return;
		m_DeleteRoleId = v.DeleteRoleId;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcBeCancelRelationShipNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcBeCancelRelationShipNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcBeCancelRelationShipNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//删除的数据
	public UInt64 m_DeleteRoleId;
	public UInt64 DeleteRoleId
	{
		get { return m_DeleteRoleId;}
		set { m_DeleteRoleId = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}


};
//被加入黑名单通知封装类
[System.Serializable]
public class ContactRpcBeAddBlackListNotifyWraper
{

	//构造函数
	public ContactRpcBeAddBlackListNotifyWraper()
	{
		 m_RoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcBeAddBlackListNotify ToPB()
	{
		ContactRpcBeAddBlackListNotify v = new ContactRpcBeAddBlackListNotify();
		v.RoleId = m_RoleId;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcBeAddBlackListNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcBeAddBlackListNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcBeAddBlackListNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcBeAddBlackListNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//删除的数据
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}


};
//推荐联系人请求封装类
[System.Serializable]
public class ContactRpcRecommendContactAskWraper
{

	//构造函数
	public ContactRpcRecommendContactAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRecommendContactAsk ToPB()
	{
		ContactRpcRecommendContactAsk v = new ContactRpcRecommendContactAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRecommendContactAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRecommendContactAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRecommendContactAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcRecommendContactAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//推荐联系人回应封装类
[System.Serializable]
public class ContactRpcRecommendContactReplyWraper
{

	//构造函数
	public ContactRpcRecommendContactReplyWraper()
	{
		 m_Result = -1;
		m_Contact = new List<ContactDataWraper>();
		m_ApplyedListId = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Contact = new List<ContactDataWraper>();
		m_ApplyedListId = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRecommendContactReply ToPB()
	{
		ContactRpcRecommendContactReply v = new ContactRpcRecommendContactReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Contact.Count; i++)
			v.Contact.Add( m_Contact[i].ToPB());
		for (int i=0; i<(int)m_ApplyedListId.Count; i++)
			v.ApplyedListId.Add( m_ApplyedListId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRecommendContactReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Contact.Clear();
		for( int i=0; i<v.Contact.Count; i++)
			m_Contact.Add( new ContactDataWraper());
		for( int i=0; i<v.Contact.Count; i++)
			m_Contact[i].FromPB(v.Contact[i]);
		m_ApplyedListId.Clear();
		for( int i=0; i<v.ApplyedListId.Count; i++)
			m_ApplyedListId.Add(v.ApplyedListId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRecommendContactReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRecommendContactReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcRecommendContactReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//推荐的人
	public List<ContactDataWraper> m_Contact;
	public int SizeContact()
	{
		return m_Contact.Count;
	}
	public List<ContactDataWraper> GetContact()
	{
		return m_Contact;
	}
	public ContactDataWraper GetContact(int Index)
	{
		if(Index<0 || Index>=(int)m_Contact.Count)
			return new ContactDataWraper();
		return m_Contact[Index];
	}
	public void SetContact( List<ContactDataWraper> v )
	{
		m_Contact=v;
	}
	public void SetContact( int Index, ContactDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Contact.Count)
			return;
		m_Contact[Index] = v;
	}
	public void AddContact( ContactDataWraper v )
	{
		m_Contact.Add(v);
	}
	public void ClearContact( )
	{
		m_Contact.Clear();
	}
	//已经申请过的人的id
	public List<UInt64> m_ApplyedListId;
	public int SizeApplyedListId()
	{
		return m_ApplyedListId.Count;
	}
	public List<UInt64> GetApplyedListId()
	{
		return m_ApplyedListId;
	}
	public UInt64 GetApplyedListId(int Index)
	{
		if(Index<0 || Index>=(int)m_ApplyedListId.Count)
			return 0;
		return m_ApplyedListId[Index];
	}
	public void SetApplyedListId( List<UInt64> v )
	{
		m_ApplyedListId=v;
	}
	public void SetApplyedListId( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_ApplyedListId.Count)
			return;
		m_ApplyedListId[Index] = v;
	}
	public void AddApplyedListId( UInt64 v=0 )
	{
		m_ApplyedListId.Add(v);
	}
	public void ClearApplyedListId( )
	{
		m_ApplyedListId.Clear();
	}


};
//拒绝所有申请请求封装类
[System.Serializable]
public class ContactRpcRejectAllAskWraper
{

	//构造函数
	public ContactRpcRejectAllAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRejectAllAsk ToPB()
	{
		ContactRpcRejectAllAsk v = new ContactRpcRejectAllAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRejectAllAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRejectAllAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRejectAllAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcRejectAllAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//拒绝所有申请回应封装类
[System.Serializable]
public class ContactRpcRejectAllReplyWraper
{

	//构造函数
	public ContactRpcRejectAllReplyWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		m_DeleteRoleIds = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();
		m_DeleteRoleIds = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRejectAllReply ToPB()
	{
		ContactRpcRejectAllReply v = new ContactRpcRejectAllReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());
		for (int i=0; i<(int)m_DeleteRoleIds.Count; i++)
			v.DeleteRoleIds.Add( m_DeleteRoleIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRejectAllReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);
		m_DeleteRoleIds.Clear();
		for( int i=0; i<v.DeleteRoleIds.Count; i++)
			m_DeleteRoleIds.Add(v.DeleteRoleIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRejectAllReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRejectAllReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcRejectAllReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}
	//删除的id
	public List<UInt64> m_DeleteRoleIds;
	public int SizeDeleteRoleIds()
	{
		return m_DeleteRoleIds.Count;
	}
	public List<UInt64> GetDeleteRoleIds()
	{
		return m_DeleteRoleIds;
	}
	public UInt64 GetDeleteRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_DeleteRoleIds.Count)
			return 0;
		return m_DeleteRoleIds[Index];
	}
	public void SetDeleteRoleIds( List<UInt64> v )
	{
		m_DeleteRoleIds=v;
	}
	public void SetDeleteRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_DeleteRoleIds.Count)
			return;
		m_DeleteRoleIds[Index] = v;
	}
	public void AddDeleteRoleIds( UInt64 v=0 )
	{
		m_DeleteRoleIds.Add(v);
	}
	public void ClearDeleteRoleIds( )
	{
		m_DeleteRoleIds.Clear();
	}


};
//添加好友度请求封装类
[System.Serializable]
public class ContactRpcAddFriendShipPointAskWraper
{

	//构造函数
	public ContactRpcAddFriendShipPointAskWraper()
	{
		 m_FriendRoleId = 0;
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FriendRoleId = 0;
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddFriendShipPointAsk ToPB()
	{
		ContactRpcAddFriendShipPointAsk v = new ContactRpcAddFriendShipPointAsk();
		v.FriendRoleId = m_FriendRoleId;
		for (int i=0; i<(int)m_ItemData.Count; i++)
			v.ItemData.Add( m_ItemData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddFriendShipPointAsk v)
	{
        if (v == null)
            return;
		m_FriendRoleId = v.FriendRoleId;
		m_ItemData.Clear();
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData[i].FromPB(v.ItemData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddFriendShipPointAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddFriendShipPointAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddFriendShipPointAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//好友Guid
	public UInt64 m_FriendRoleId;
	public UInt64 FriendRoleId
	{
		get { return m_FriendRoleId;}
		set { m_FriendRoleId = value; }
	}
	//物品id
	public List<ItemSimpleDataWraper> m_ItemData;
	public int SizeItemData()
	{
		return m_ItemData.Count;
	}
	public List<ItemSimpleDataWraper> GetItemData()
	{
		return m_ItemData;
	}
	public ItemSimpleDataWraper GetItemData(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return new ItemSimpleDataWraper();
		return m_ItemData[Index];
	}
	public void SetItemData( List<ItemSimpleDataWraper> v )
	{
		m_ItemData=v;
	}
	public void SetItemData( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return;
		m_ItemData[Index] = v;
	}
	public void AddItemData( ItemSimpleDataWraper v )
	{
		m_ItemData.Add(v);
	}
	public void ClearItemData( )
	{
		m_ItemData.Clear();
	}


};
//添加好友度回应封装类
[System.Serializable]
public class ContactRpcAddFriendShipPointReplyWraper
{

	//构造函数
	public ContactRpcAddFriendShipPointReplyWraper()
	{
		 m_Result = -1;
		 m_Contact = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Contact = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddFriendShipPointReply ToPB()
	{
		ContactRpcAddFriendShipPointReply v = new ContactRpcAddFriendShipPointReply();
		v.Result = m_Result;
		v.Contact = m_Contact.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddFriendShipPointReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Contact.FromPB(v.Contact);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddFriendShipPointReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddFriendShipPointReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddFriendShipPointReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//更新的人
	public ContactDataWraper m_Contact;
	public ContactDataWraper Contact
	{
		get { return m_Contact;}
		set { m_Contact = value; }
	}


};
//玩家数据更新通知封装类
[System.Serializable]
public class ContactRpcRoleDataUpdateNotifyWraper
{

	//构造函数
	public ContactRpcRoleDataUpdateNotifyWraper()
	{
		 m_Contact = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Contact = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcRoleDataUpdateNotify ToPB()
	{
		ContactRpcRoleDataUpdateNotify v = new ContactRpcRoleDataUpdateNotify();
		v.Contact = m_Contact.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcRoleDataUpdateNotify v)
	{
        if (v == null)
            return;
		m_Contact.FromPB(v.Contact);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcRoleDataUpdateNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcRoleDataUpdateNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcRoleDataUpdateNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//更新的人
	public ContactDataWraper m_Contact;
	public ContactDataWraper Contact
	{
		get { return m_Contact;}
		set { m_Contact = value; }
	}


};
//联系人登录通知封装类
[System.Serializable]
public class ContactRpcContactLoginNotifyWraper
{

	//构造函数
	public ContactRpcContactLoginNotifyWraper()
	{
		 m_Contact = new ContactDataWraper();
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Contact = new ContactDataWraper();
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcContactLoginNotify ToPB()
	{
		ContactRpcContactLoginNotify v = new ContactRpcContactLoginNotify();
		v.Contact = m_Contact.ToPB();
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcContactLoginNotify v)
	{
        if (v == null)
            return;
		m_Contact.FromPB(v.Contact);
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcContactLoginNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcContactLoginNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcContactLoginNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//更新的人
	public ContactDataWraper m_Contact;
	public ContactDataWraper Contact
	{
		get { return m_Contact;}
		set { m_Contact = value; }
	}
	//改变的分组
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//联系人退出游戏通知封装类
[System.Serializable]
public class ContactRpcContactLogoutNotifyWraper
{

	//构造函数
	public ContactRpcContactLogoutNotifyWraper()
	{
		 m_Contact = new ContactDataWraper();
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Contact = new ContactDataWraper();
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcContactLogoutNotify ToPB()
	{
		ContactRpcContactLogoutNotify v = new ContactRpcContactLogoutNotify();
		v.Contact = m_Contact.ToPB();
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcContactLogoutNotify v)
	{
        if (v == null)
            return;
		m_Contact.FromPB(v.Contact);
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcContactLogoutNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcContactLogoutNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcContactLogoutNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//更新的人
	public ContactDataWraper m_Contact;
	public ContactDataWraper Contact
	{
		get { return m_Contact;}
		set { m_Contact = value; }
	}
	//改变的分组
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//删除联系人数据通知封装类
[System.Serializable]
public class ContactRpcDeleteRoleDataNotifyWraper
{

	//构造函数
	public ContactRpcDeleteRoleDataNotifyWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcDeleteRoleDataNotify ToPB()
	{
		ContactRpcDeleteRoleDataNotify v = new ContactRpcDeleteRoleDataNotify();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcDeleteRoleDataNotify v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcDeleteRoleDataNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcDeleteRoleDataNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcDeleteRoleDataNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//删除的玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//排序分组请求封装类
[System.Serializable]
public class ContactRpcSortGroupAskWraper
{

	//构造函数
	public ContactRpcSortGroupAskWraper()
	{
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSortGroupAsk ToPB()
	{
		ContactRpcSortGroupAsk v = new ContactRpcSortGroupAsk();
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSortGroupAsk v)
	{
        if (v == null)
            return;
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSortGroupAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSortGroupAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSortGroupAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组id
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//排序分组回应封装类
[System.Serializable]
public class ContactRpcSortGroupReplyWraper
{

	//构造函数
	public ContactRpcSortGroupReplyWraper()
	{
		 m_Result = -1;
		m_GroupIds = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_GroupIds = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSortGroupReply ToPB()
	{
		ContactRpcSortGroupReply v = new ContactRpcSortGroupReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_GroupIds.Count; i++)
			v.GroupIds.Add( m_GroupIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSortGroupReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GroupIds.Clear();
		for( int i=0; i<v.GroupIds.Count; i++)
			m_GroupIds.Add(v.GroupIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSortGroupReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSortGroupReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSortGroupReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//分组id
	public List<int> m_GroupIds;
	public int SizeGroupIds()
	{
		return m_GroupIds.Count;
	}
	public List<int> GetGroupIds()
	{
		return m_GroupIds;
	}
	public int GetGroupIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return -1;
		return m_GroupIds[Index];
	}
	public void SetGroupIds( List<int> v )
	{
		m_GroupIds=v;
	}
	public void SetGroupIds( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.Count)
			return;
		m_GroupIds[Index] = v;
	}
	public void AddGroupIds( int v=-1 )
	{
		m_GroupIds.Add(v);
	}
	public void ClearGroupIds( )
	{
		m_GroupIds.Clear();
	}


};
//设置好友名字请求封装类
[System.Serializable]
public class ContactRpcSetFriendAliasAskWraper
{

	//构造函数
	public ContactRpcSetFriendAliasAskWraper()
	{
		 m_Name = "";
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Name = "";
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSetFriendAliasAsk ToPB()
	{
		ContactRpcSetFriendAliasAsk v = new ContactRpcSetFriendAliasAsk();
		v.Name = m_Name;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSetFriendAliasAsk v)
	{
        if (v == null)
            return;
		m_Name = v.Name;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSetFriendAliasAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSetFriendAliasAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSetFriendAliasAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//设置的玩家Id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//设置好友名字回应封装类
[System.Serializable]
public class ContactRpcSetFriendAliasReplyWraper
{

	//构造函数
	public ContactRpcSetFriendAliasReplyWraper()
	{
		 m_Result = -1;
		 m_Contact = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Contact = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSetFriendAliasReply ToPB()
	{
		ContactRpcSetFriendAliasReply v = new ContactRpcSetFriendAliasReply();
		v.Result = m_Result;
		v.Contact = m_Contact.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSetFriendAliasReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Contact.FromPB(v.Contact);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSetFriendAliasReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSetFriendAliasReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSetFriendAliasReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//更新的人
	public ContactDataWraper m_Contact;
	public ContactDataWraper Contact
	{
		get { return m_Contact;}
		set { m_Contact = value; }
	}


};
//发送好友点请求封装类
[System.Serializable]
public class ContactRpcSendFriendGiftPointAskWraper
{

	//构造函数
	public ContactRpcSendFriendGiftPointAskWraper()
	{
		 m_SendRoleId = 0;
		 m_Point = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SendRoleId = 0;
		 m_Point = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSendFriendGiftPointAsk ToPB()
	{
		ContactRpcSendFriendGiftPointAsk v = new ContactRpcSendFriendGiftPointAsk();
		v.SendRoleId = m_SendRoleId;
		v.Point = m_Point;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSendFriendGiftPointAsk v)
	{
        if (v == null)
            return;
		m_SendRoleId = v.SendRoleId;
		m_Point = v.Point;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSendFriendGiftPointAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSendFriendGiftPointAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSendFriendGiftPointAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//给谁送
	public UInt64 m_SendRoleId;
	public UInt64 SendRoleId
	{
		get { return m_SendRoleId;}
		set { m_SendRoleId = value; }
	}
	//友情点
	public int m_Point;
	public int Point
	{
		get { return m_Point;}
		set { m_Point = value; }
	}


};
//发送好友点回应封装类
[System.Serializable]
public class ContactRpcSendFriendGiftPointReplyWraper
{

	//构造函数
	public ContactRpcSendFriendGiftPointReplyWraper()
	{
		 m_Result = -1;
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSendFriendGiftPointReply ToPB()
	{
		ContactRpcSendFriendGiftPointReply v = new ContactRpcSendFriendGiftPointReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_SentGiftList.Count; i++)
			v.SentGiftList.Add( m_SentGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSendFriendGiftPointReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SentGiftList.Clear();
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList[i].FromPB(v.SentGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSendFriendGiftPointReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSendFriendGiftPointReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSendFriendGiftPointReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//已经赠送列表
	public List<FriendGiftPointWraper> m_SentGiftList;
	public int SizeSentGiftList()
	{
		return m_SentGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetSentGiftList()
	{
		return m_SentGiftList;
	}
	public FriendGiftPointWraper GetSentGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return new FriendGiftPointWraper();
		return m_SentGiftList[Index];
	}
	public void SetSentGiftList( List<FriendGiftPointWraper> v )
	{
		m_SentGiftList=v;
	}
	public void SetSentGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return;
		m_SentGiftList[Index] = v;
	}
	public void AddSentGiftList( FriendGiftPointWraper v )
	{
		m_SentGiftList.Add(v);
	}
	public void ClearSentGiftList( )
	{
		m_SentGiftList.Clear();
	}


};
//获取点数请求封装类
[System.Serializable]
public class ContactRpcAcquireGiftPointAskWraper
{

	//构造函数
	public ContactRpcAcquireGiftPointAskWraper()
	{
		 m_AcquireRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AcquireRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAcquireGiftPointAsk ToPB()
	{
		ContactRpcAcquireGiftPointAsk v = new ContactRpcAcquireGiftPointAsk();
		v.AcquireRoleId = m_AcquireRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAcquireGiftPointAsk v)
	{
        if (v == null)
            return;
		m_AcquireRoleId = v.AcquireRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAcquireGiftPointAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAcquireGiftPointAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAcquireGiftPointAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//给谁送
	public UInt64 m_AcquireRoleId;
	public UInt64 AcquireRoleId
	{
		get { return m_AcquireRoleId;}
		set { m_AcquireRoleId = value; }
	}


};
//获取点数回应封装类
[System.Serializable]
public class ContactRpcAcquireGiftPointReplyWraper
{

	//构造函数
	public ContactRpcAcquireGiftPointReplyWraper()
	{
		 m_Result = -1;
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAcquireGiftPointReply ToPB()
	{
		ContactRpcAcquireGiftPointReply v = new ContactRpcAcquireGiftPointReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_AcquireGiftList.Count; i++)
			v.AcquireGiftList.Add( m_AcquireGiftList[i].ToPB());
		for (int i=0; i<(int)m_UnAcquireGiftList.Count; i++)
			v.UnAcquireGiftList.Add( m_UnAcquireGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAcquireGiftPointReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AcquireGiftList.Clear();
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList[i].FromPB(v.AcquireGiftList[i]);
		m_UnAcquireGiftList.Clear();
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList[i].FromPB(v.UnAcquireGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAcquireGiftPointReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAcquireGiftPointReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAcquireGiftPointReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//已经收取列表
	public List<FriendGiftPointWraper> m_AcquireGiftList;
	public int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetAcquireGiftList()
	{
		return m_AcquireGiftList;
	}
	public FriendGiftPointWraper GetAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_AcquireGiftList[Index];
	}
	public void SetAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_AcquireGiftList=v;
	}
	public void SetAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return;
		m_AcquireGiftList[Index] = v;
	}
	public void AddAcquireGiftList( FriendGiftPointWraper v )
	{
		m_AcquireGiftList.Add(v);
	}
	public void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.Clear();
	}
	//未收取赠送列表
	public List<FriendGiftPointWraper> m_UnAcquireGiftList;
	public int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetUnAcquireGiftList()
	{
		return m_UnAcquireGiftList;
	}
	public FriendGiftPointWraper GetUnAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_UnAcquireGiftList[Index];
	}
	public void SetUnAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_UnAcquireGiftList=v;
	}
	public void SetUnAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return;
		m_UnAcquireGiftList[Index] = v;
	}
	public void AddUnAcquireGiftList( FriendGiftPointWraper v )
	{
		m_UnAcquireGiftList.Add(v);
	}
	public void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.Clear();
	}


};
//刷新未获取点数通知封装类
[System.Serializable]
public class ContactRpcUnAcquireGiftPointNotifyWraper
{

	//构造函数
	public ContactRpcUnAcquireGiftPointNotifyWraper()
	{
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcUnAcquireGiftPointNotify ToPB()
	{
		ContactRpcUnAcquireGiftPointNotify v = new ContactRpcUnAcquireGiftPointNotify();
		for (int i=0; i<(int)m_UnAcquireGiftList.Count; i++)
			v.UnAcquireGiftList.Add( m_UnAcquireGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcUnAcquireGiftPointNotify v)
	{
        if (v == null)
            return;
		m_UnAcquireGiftList.Clear();
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList[i].FromPB(v.UnAcquireGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcUnAcquireGiftPointNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcUnAcquireGiftPointNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcUnAcquireGiftPointNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//未收取赠送列表
	public List<FriendGiftPointWraper> m_UnAcquireGiftList;
	public int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetUnAcquireGiftList()
	{
		return m_UnAcquireGiftList;
	}
	public FriendGiftPointWraper GetUnAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_UnAcquireGiftList[Index];
	}
	public void SetUnAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_UnAcquireGiftList=v;
	}
	public void SetUnAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return;
		m_UnAcquireGiftList[Index] = v;
	}
	public void AddUnAcquireGiftList( FriendGiftPointWraper v )
	{
		m_UnAcquireGiftList.Add(v);
	}
	public void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.Clear();
	}


};
//一键赠送请求封装类
[System.Serializable]
public class ContactRpcSendAllFriendGiftPointAskWraper
{

	//构造函数
	public ContactRpcSendAllFriendGiftPointAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSendAllFriendGiftPointAsk ToPB()
	{
		ContactRpcSendAllFriendGiftPointAsk v = new ContactRpcSendAllFriendGiftPointAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSendAllFriendGiftPointAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSendAllFriendGiftPointAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSendAllFriendGiftPointAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcSendAllFriendGiftPointAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//一键赠送回应封装类
[System.Serializable]
public class ContactRpcSendAllFriendGiftPointReplyWraper
{

	//构造函数
	public ContactRpcSendAllFriendGiftPointReplyWraper()
	{
		 m_Result = -1;
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSendAllFriendGiftPointReply ToPB()
	{
		ContactRpcSendAllFriendGiftPointReply v = new ContactRpcSendAllFriendGiftPointReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_SentGiftList.Count; i++)
			v.SentGiftList.Add( m_SentGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSendAllFriendGiftPointReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SentGiftList.Clear();
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList[i].FromPB(v.SentGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSendAllFriendGiftPointReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSendAllFriendGiftPointReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcSendAllFriendGiftPointReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//已经赠送列表
	public List<FriendGiftPointWraper> m_SentGiftList;
	public int SizeSentGiftList()
	{
		return m_SentGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetSentGiftList()
	{
		return m_SentGiftList;
	}
	public FriendGiftPointWraper GetSentGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return new FriendGiftPointWraper();
		return m_SentGiftList[Index];
	}
	public void SetSentGiftList( List<FriendGiftPointWraper> v )
	{
		m_SentGiftList=v;
	}
	public void SetSentGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return;
		m_SentGiftList[Index] = v;
	}
	public void AddSentGiftList( FriendGiftPointWraper v )
	{
		m_SentGiftList.Add(v);
	}
	public void ClearSentGiftList( )
	{
		m_SentGiftList.Clear();
	}


};
//一键收取请求封装类
[System.Serializable]
public class ContactRpcAcquireAllGiftPointAskWraper
{

	//构造函数
	public ContactRpcAcquireAllGiftPointAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAcquireAllGiftPointAsk ToPB()
	{
		ContactRpcAcquireAllGiftPointAsk v = new ContactRpcAcquireAllGiftPointAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAcquireAllGiftPointAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAcquireAllGiftPointAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAcquireAllGiftPointAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAcquireAllGiftPointAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//一键收取回应封装类
[System.Serializable]
public class ContactRpcAcquireAllGiftPointReplyWraper
{

	//构造函数
	public ContactRpcAcquireAllGiftPointReplyWraper()
	{
		 m_Result = -1;
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAcquireAllGiftPointReply ToPB()
	{
		ContactRpcAcquireAllGiftPointReply v = new ContactRpcAcquireAllGiftPointReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_AcquireGiftList.Count; i++)
			v.AcquireGiftList.Add( m_AcquireGiftList[i].ToPB());
		for (int i=0; i<(int)m_UnAcquireGiftList.Count; i++)
			v.UnAcquireGiftList.Add( m_UnAcquireGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAcquireAllGiftPointReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AcquireGiftList.Clear();
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList[i].FromPB(v.AcquireGiftList[i]);
		m_UnAcquireGiftList.Clear();
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList[i].FromPB(v.UnAcquireGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAcquireAllGiftPointReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAcquireAllGiftPointReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAcquireAllGiftPointReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//已经收取列表
	public List<FriendGiftPointWraper> m_AcquireGiftList;
	public int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetAcquireGiftList()
	{
		return m_AcquireGiftList;
	}
	public FriendGiftPointWraper GetAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_AcquireGiftList[Index];
	}
	public void SetAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_AcquireGiftList=v;
	}
	public void SetAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return;
		m_AcquireGiftList[Index] = v;
	}
	public void AddAcquireGiftList( FriendGiftPointWraper v )
	{
		m_AcquireGiftList.Add(v);
	}
	public void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.Clear();
	}
	//未收取赠送列表
	public List<FriendGiftPointWraper> m_UnAcquireGiftList;
	public int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetUnAcquireGiftList()
	{
		return m_UnAcquireGiftList;
	}
	public FriendGiftPointWraper GetUnAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_UnAcquireGiftList[Index];
	}
	public void SetUnAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_UnAcquireGiftList=v;
	}
	public void SetUnAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return;
		m_UnAcquireGiftList[Index] = v;
	}
	public void AddUnAcquireGiftList( FriendGiftPointWraper v )
	{
		m_UnAcquireGiftList.Add(v);
	}
	public void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.Clear();
	}


};
//移出列表请求封装类
[System.Serializable]
public class ContactRpcDeleteGroupRoleAskWraper
{

	//构造函数
	public ContactRpcDeleteGroupRoleAskWraper()
	{
		 m_GroupId = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GroupId = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcDeleteGroupRoleAsk ToPB()
	{
		ContactRpcDeleteGroupRoleAsk v = new ContactRpcDeleteGroupRoleAsk();
		v.GroupId = m_GroupId;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcDeleteGroupRoleAsk v)
	{
        if (v == null)
            return;
		m_GroupId = v.GroupId;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcDeleteGroupRoleAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcDeleteGroupRoleAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcDeleteGroupRoleAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组Id
	public int m_GroupId;
	public int GroupId
	{
		get { return m_GroupId;}
		set { m_GroupId = value; }
	}
	//玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//移出列表回应封装类
[System.Serializable]
public class ContactRpcDeleteGroupRoleReplyWraper
{

	//构造函数
	public ContactRpcDeleteGroupRoleReplyWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ContactGroups = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcDeleteGroupRoleReply ToPB()
	{
		ContactRpcDeleteGroupRoleReply v = new ContactRpcDeleteGroupRoleReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcDeleteGroupRoleReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcDeleteGroupRoleReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcDeleteGroupRoleReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcDeleteGroupRoleReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//改变的分组
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}


};
//新加玩家数据通知封装类
[System.Serializable]
public class ContactRpcAddRoleDataNotifyWraper
{

	//构造函数
	public ContactRpcAddRoleDataNotifyWraper()
	{
		 m_NewRoleData = new ContactDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NewRoleData = new ContactDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAddRoleDataNotify ToPB()
	{
		ContactRpcAddRoleDataNotify v = new ContactRpcAddRoleDataNotify();
		v.NewRoleData = m_NewRoleData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAddRoleDataNotify v)
	{
        if (v == null)
            return;
		m_NewRoleData.FromPB(v.NewRoleData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAddRoleDataNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAddRoleDataNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcAddRoleDataNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新的联系人数据
	public ContactDataWraper m_NewRoleData;
	public ContactDataWraper NewRoleData
	{
		get { return m_NewRoleData;}
		set { m_NewRoleData = value; }
	}


};
//设置友情点数据通知封装类
[System.Serializable]
public class ContactRpcSetGiftPointNotifyWraper
{

	//构造函数
	public ContactRpcSetGiftPointNotifyWraper()
	{
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();
		m_SentGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcSetGiftPointNotify ToPB()
	{
		ContactRpcSetGiftPointNotify v = new ContactRpcSetGiftPointNotify();
		for (int i=0; i<(int)m_AcquireGiftList.Count; i++)
			v.AcquireGiftList.Add( m_AcquireGiftList[i].ToPB());
		for (int i=0; i<(int)m_UnAcquireGiftList.Count; i++)
			v.UnAcquireGiftList.Add( m_UnAcquireGiftList[i].ToPB());
		for (int i=0; i<(int)m_SentGiftList.Count; i++)
			v.SentGiftList.Add( m_SentGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcSetGiftPointNotify v)
	{
        if (v == null)
            return;
		m_AcquireGiftList.Clear();
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList[i].FromPB(v.AcquireGiftList[i]);
		m_UnAcquireGiftList.Clear();
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList[i].FromPB(v.UnAcquireGiftList[i]);
		m_SentGiftList.Clear();
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList[i].FromPB(v.SentGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcSetGiftPointNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcSetGiftPointNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcSetGiftPointNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//已经收取列表
	public List<FriendGiftPointWraper> m_AcquireGiftList;
	public int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetAcquireGiftList()
	{
		return m_AcquireGiftList;
	}
	public FriendGiftPointWraper GetAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_AcquireGiftList[Index];
	}
	public void SetAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_AcquireGiftList=v;
	}
	public void SetAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return;
		m_AcquireGiftList[Index] = v;
	}
	public void AddAcquireGiftList( FriendGiftPointWraper v )
	{
		m_AcquireGiftList.Add(v);
	}
	public void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.Clear();
	}
	//未收取赠送列表
	public List<FriendGiftPointWraper> m_UnAcquireGiftList;
	public int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetUnAcquireGiftList()
	{
		return m_UnAcquireGiftList;
	}
	public FriendGiftPointWraper GetUnAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_UnAcquireGiftList[Index];
	}
	public void SetUnAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_UnAcquireGiftList=v;
	}
	public void SetUnAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return;
		m_UnAcquireGiftList[Index] = v;
	}
	public void AddUnAcquireGiftList( FriendGiftPointWraper v )
	{
		m_UnAcquireGiftList.Add(v);
	}
	public void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.Clear();
	}
	//已经赠送列表
	public List<FriendGiftPointWraper> m_SentGiftList;
	public int SizeSentGiftList()
	{
		return m_SentGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetSentGiftList()
	{
		return m_SentGiftList;
	}
	public FriendGiftPointWraper GetSentGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return new FriendGiftPointWraper();
		return m_SentGiftList[Index];
	}
	public void SetSentGiftList( List<FriendGiftPointWraper> v )
	{
		m_SentGiftList=v;
	}
	public void SetSentGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return;
		m_SentGiftList[Index] = v;
	}
	public void AddSentGiftList( FriendGiftPointWraper v )
	{
		m_SentGiftList.Add(v);
	}
	public void ClearSentGiftList( )
	{
		m_SentGiftList.Clear();
	}


};
//刷新组通知封装类
[System.Serializable]
public class ContactRpcContactsGroupsNotifyWraper
{

	//构造函数
	public ContactRpcContactsGroupsNotifyWraper()
	{
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcContactsGroupsNotify ToPB()
	{
		ContactRpcContactsGroupsNotify v = new ContactRpcContactsGroupsNotify();
		for (int i=0; i<(int)m_MyFriendGroup.Count; i++)
			v.MyFriendGroup.Add( m_MyFriendGroup[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcContactsGroupsNotify v)
	{
        if (v == null)
            return;
		m_MyFriendGroup.Clear();
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup.Add( new ContactGroupWraper());
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup[i].FromPB(v.MyFriendGroup[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcContactsGroupsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcContactsGroupsNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcContactsGroupsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组信息
	public List<ContactGroupWraper> m_MyFriendGroup;
	public int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.Count;
	}
	public List<ContactGroupWraper> GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	public ContactGroupWraper GetMyFriendGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return new ContactGroupWraper();
		return m_MyFriendGroup[Index];
	}
	public void SetMyFriendGroup( List<ContactGroupWraper> v )
	{
		m_MyFriendGroup=v;
	}
	public void SetMyFriendGroup( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return;
		m_MyFriendGroup[Index] = v;
	}
	public void AddMyFriendGroup( ContactGroupWraper v )
	{
		m_MyFriendGroup.Add(v);
	}
	public void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.Clear();
	}


};
//同意所有申请请求封装类
[System.Serializable]
public class ContactRpcAgreeAllApplicationAskWraper
{

	//构造函数
	public ContactRpcAgreeAllApplicationAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAgreeAllApplicationAsk ToPB()
	{
		ContactRpcAgreeAllApplicationAsk v = new ContactRpcAgreeAllApplicationAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAgreeAllApplicationAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAgreeAllApplicationAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAgreeAllApplicationAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcAgreeAllApplicationAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同意所有申请回应封装类
[System.Serializable]
public class ContactRpcAgreeAllApplicationReplyWraper
{

	//构造函数
	public ContactRpcAgreeAllApplicationReplyWraper()
	{
		 m_Result = -1;
		m_NewFriendData = new List<ContactDataWraper>();
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_NewFriendData = new List<ContactDataWraper>();
		m_MyFriendGroup = new List<ContactGroupWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcAgreeAllApplicationReply ToPB()
	{
		ContactRpcAgreeAllApplicationReply v = new ContactRpcAgreeAllApplicationReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_NewFriendData.Count; i++)
			v.NewFriendData.Add( m_NewFriendData[i].ToPB());
		for (int i=0; i<(int)m_MyFriendGroup.Count; i++)
			v.MyFriendGroup.Add( m_MyFriendGroup[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcAgreeAllApplicationReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewFriendData.Clear();
		for( int i=0; i<v.NewFriendData.Count; i++)
			m_NewFriendData.Add( new ContactDataWraper());
		for( int i=0; i<v.NewFriendData.Count; i++)
			m_NewFriendData[i].FromPB(v.NewFriendData[i]);
		m_MyFriendGroup.Clear();
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup.Add( new ContactGroupWraper());
		for( int i=0; i<v.MyFriendGroup.Count; i++)
			m_MyFriendGroup[i].FromPB(v.MyFriendGroup[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcAgreeAllApplicationReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcAgreeAllApplicationReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcAgreeAllApplicationReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//新玩家数据
	public List<ContactDataWraper> m_NewFriendData;
	public int SizeNewFriendData()
	{
		return m_NewFriendData.Count;
	}
	public List<ContactDataWraper> GetNewFriendData()
	{
		return m_NewFriendData;
	}
	public ContactDataWraper GetNewFriendData(int Index)
	{
		if(Index<0 || Index>=(int)m_NewFriendData.Count)
			return new ContactDataWraper();
		return m_NewFriendData[Index];
	}
	public void SetNewFriendData( List<ContactDataWraper> v )
	{
		m_NewFriendData=v;
	}
	public void SetNewFriendData( int Index, ContactDataWraper v )
	{
		if(Index<0 || Index>=(int)m_NewFriendData.Count)
			return;
		m_NewFriendData[Index] = v;
	}
	public void AddNewFriendData( ContactDataWraper v )
	{
		m_NewFriendData.Add(v);
	}
	public void ClearNewFriendData( )
	{
		m_NewFriendData.Clear();
	}
	//移动来源组
	public List<ContactGroupWraper> m_MyFriendGroup;
	public int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.Count;
	}
	public List<ContactGroupWraper> GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	public ContactGroupWraper GetMyFriendGroup(int Index)
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return new ContactGroupWraper();
		return m_MyFriendGroup[Index];
	}
	public void SetMyFriendGroup( List<ContactGroupWraper> v )
	{
		m_MyFriendGroup=v;
	}
	public void SetMyFriendGroup( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.Count)
			return;
		m_MyFriendGroup[Index] = v;
	}
	public void AddMyFriendGroup( ContactGroupWraper v )
	{
		m_MyFriendGroup.Add(v);
	}
	public void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.Clear();
	}


};
//聊天请求封装类
[System.Serializable]
public class ContactRpcChatToAskWraper
{

	//构造函数
	public ContactRpcChatToAskWraper()
	{
		 m_RoleId = 0;
		 m_ChatMsg = new ChatMsgWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_ChatMsg = new ChatMsgWraper();

	}

 	//转化成Protobuffer类型函数
	public ContactRpcChatToAsk ToPB()
	{
		ContactRpcChatToAsk v = new ContactRpcChatToAsk();
		v.RoleId = m_RoleId;
		v.ChatMsg = m_ChatMsg.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcChatToAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_ChatMsg.FromPB(v.ChatMsg);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcChatToAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcChatToAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcChatToAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//需要发送信息的人的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//聊天信息
	public ChatMsgWraper m_ChatMsg;
	public ChatMsgWraper ChatMsg
	{
		get { return m_ChatMsg;}
		set { m_ChatMsg = value; }
	}


};
//聊天回应封装类
[System.Serializable]
public class ContactRpcChatToReplyWraper
{

	//构造函数
	public ContactRpcChatToReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcChatToReply ToPB()
	{
		ContactRpcChatToReply v = new ContactRpcChatToReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcChatToReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcChatToReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcChatToReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcChatToReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//新的聊天信息通知封装类
[System.Serializable]
public class ContactRpcNewChatMsgNotifyWraper
{

	//构造函数
	public ContactRpcNewChatMsgNotifyWraper()
	{
		 m_ChatMsg = new ChatInfoWraper();
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ChatMsg = new ChatInfoWraper();
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcNewChatMsgNotify ToPB()
	{
		ContactRpcNewChatMsgNotify v = new ContactRpcNewChatMsgNotify();
		v.ChatMsg = m_ChatMsg.ToPB();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcNewChatMsgNotify v)
	{
        if (v == null)
            return;
		m_ChatMsg.FromPB(v.ChatMsg);
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcNewChatMsgNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcNewChatMsgNotify pb = ProtoBuf.Serializer.Deserialize<ContactRpcNewChatMsgNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新的聊天信息
	public ChatInfoWraper m_ChatMsg;
	public ChatInfoWraper ChatMsg
	{
		get { return m_ChatMsg;}
		set { m_ChatMsg = value; }
	}
	//聊天Id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//读取信息请求封装类
[System.Serializable]
public class ContactRpcReadMsgAskWraper
{

	//构造函数
	public ContactRpcReadMsgAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcReadMsgAsk ToPB()
	{
		ContactRpcReadMsgAsk v = new ContactRpcReadMsgAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcReadMsgAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcReadMsgAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcReadMsgAsk pb = ProtoBuf.Serializer.Deserialize<ContactRpcReadMsgAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//已读玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//读取信息回应封装类
[System.Serializable]
public class ContactRpcReadMsgReplyWraper
{

	//构造函数
	public ContactRpcReadMsgReplyWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public ContactRpcReadMsgReply ToPB()
	{
		ContactRpcReadMsgReply v = new ContactRpcReadMsgReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactRpcReadMsgReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactRpcReadMsgReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactRpcReadMsgReply pb = ProtoBuf.Serializer.Deserialize<ContactRpcReadMsgReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//已读玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
