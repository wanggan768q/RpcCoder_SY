/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperContact.h
* Author:       甘业清
* Description:  联系人RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CONTACT_H
#define __RPC_WRAPER_CONTACT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ContactRpc.pb.h"



//联系人类的枚举定义
enum ConstContactE
{
	MODULE_ID_CONTACT                            = 48,	//联系人模块ID
	RPC_CODE_CONTACT_ADDFRIEND_REQUEST           = 4851,	//联系人-->添加好友-->请求
	RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST  = 4852,	//联系人-->删除好友-->请求
	RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST        = 4853,	//联系人-->加入黑名单-->请求
	RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST     = 4854,	//联系人-->通讯录数据-->请求
	RPC_CODE_CONTACT_CONTACTSETTING_REQUEST      = 4855,	//联系人-->联系人设置-->请求
	RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST   = 4856,	//联系人-->创建好友分组-->请求
	RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST   = 4857,	//联系人-->移动到分组-->请求
	RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST   = 4858,	//联系人-->删除好友分组-->请求
	RPC_CODE_CONTACT_RENAMEGROUP_REQUEST         = 4859,	//联系人-->重命名分组-->请求
	RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST    = 4860,	//联系人-->同意申请加为好友-->请求
	RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY= 4861,	//联系人-->同意申请通知-->通知
	RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST      = 4862,	//联系人-->设置分组-->请求
	RPC_CODE_CONTACT_NEWFRIEND_NOTIFY            = 4863,	//联系人-->新朋友-->通知
	RPC_CODE_CONTACT_APPLYLIST_NOTIFY            = 4864,	//联系人-->申请列表-->通知
	RPC_CODE_CONTACT_REJECTAPPLY_REQUEST         = 4865,	//联系人-->拒绝申请-->请求
	RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY        = 4866,	//联系人-->被拒绝-->通知
	RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY = 4867,	//联系人-->被删除好友-->通知
	RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY       = 4868,	//联系人-->被加入黑名单-->通知
	RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST    = 4869,	//联系人-->推荐联系人-->请求
	RPC_CODE_CONTACT_REJECTALL_REQUEST           = 4870,	//联系人-->拒绝所有申请-->请求
	RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST  = 4871,	//联系人-->添加好友度-->请求
	RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY       = 4872,	//联系人-->玩家数据更新-->通知
	RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY         = 4873,	//联系人-->联系人登录-->通知
	RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY        = 4874,	//联系人-->联系人退出游戏-->通知
	RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY       = 4875,	//联系人-->删除联系人数据-->通知
	RPC_CODE_CONTACT_SORTGROUP_REQUEST           = 4876,	//联系人-->排序分组-->请求
	RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST      = 4877,	//联系人-->设置好友名字-->请求
	RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST = 4878,	//联系人-->发送好友点-->请求
	RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST    = 4879,	//联系人-->获取点数-->请求
	RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY   = 4880,	//联系人-->刷新未获取点数-->通知
	RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST= 4881,	//联系人-->一键赠送-->请求
	RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST = 4882,	//联系人-->一键收取-->请求
	RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST     = 4883,	//联系人-->移出列表-->请求
	RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY          = 4884,	//联系人-->新加玩家数据-->通知
	RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY         = 4885,	//联系人-->设置友情点数据-->通知
	RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY       = 4886,	//联系人-->刷新组-->通知
	RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST = 4887,	//联系人-->同意所有申请-->请求
	RPC_CODE_CONTACT_CHATTO_REQUEST              = 4888,	//联系人-->聊天-->请求
	RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY           = 4889,	//联系人-->新的聊天信息-->通知
	RPC_CODE_CONTACT_READMSG_REQUEST             = 4890,	//联系人-->读取信息-->请求


};


//设置好友名字回应封装类
class ContactRpcSetFriendAliasReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSetFriendAliasReplyWraper()
	{
		
		m_Result = -1;
		m_Contact = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcSetFriendAliasReplyWraper(const ContactRpcSetFriendAliasReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSetFriendAliasReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSetFriendAliasReply ToPB() const
	{
		ContactRpcSetFriendAliasReply v;
		v.set_result( m_Result );
		*v.mutable_contact()= m_Contact.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSetFriendAliasReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSetFriendAliasReply& v)
	{
		m_Result = v.result();
		m_Contact = v.contact();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//更新的人
	ContactDataWraper m_Contact;
public:
	void SetContact( const ContactDataWraper& v)
	{
		m_Contact=v;
	}
	ContactDataWraper GetContact()
	{
		return m_Contact;
	}
	ContactDataWraper GetContact() const
	{
		return m_Contact;
	}

};
//发送好友点请求封装类
class ContactRpcSendFriendGiftPointAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSendFriendGiftPointAskWraper()
	{
		
		m_SendRoleId = 0;
		m_Point = -1;

	}
	//赋值构造函数
	ContactRpcSendFriendGiftPointAskWraper(const ContactRpcSendFriendGiftPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSendFriendGiftPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSendFriendGiftPointAsk ToPB() const
	{
		ContactRpcSendFriendGiftPointAsk v;
		v.set_sendroleid( m_SendRoleId );
		v.set_point( m_Point );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSendFriendGiftPointAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSendFriendGiftPointAsk& v)
	{
		m_SendRoleId = v.sendroleid();
		m_Point = v.point();

	}

private:
	//给谁送
	uint64_t m_SendRoleId;
public:
	void SetSendRoleId( uint64_t v)
	{
		m_SendRoleId=v;
	}
	uint64_t GetSendRoleId()
	{
		return m_SendRoleId;
	}
	uint64_t GetSendRoleId() const
	{
		return m_SendRoleId;
	}
private:
	//友情点
	INT32 m_Point;
public:
	void SetPoint( INT32 v)
	{
		m_Point=v;
	}
	INT32 GetPoint()
	{
		return m_Point;
	}
	INT32 GetPoint() const
	{
		return m_Point;
	}

};
//排序分组回应封装类
class ContactRpcSortGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSortGroupReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcSortGroupReplyWraper(const ContactRpcSortGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSortGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSortGroupReply ToPB() const
	{
		ContactRpcSortGroupReply v;
		v.set_result( m_Result );
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSortGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSortGroupReply& v)
	{
		m_Result = v.result();
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//分组id
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//设置好友名字请求封装类
class ContactRpcSetFriendAliasAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSetFriendAliasAskWraper()
	{
		
		m_Name = "";
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcSetFriendAliasAskWraper(const ContactRpcSetFriendAliasAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSetFriendAliasAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSetFriendAliasAsk ToPB() const
	{
		ContactRpcSetFriendAliasAsk v;
		v.set_name( m_Name );
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSetFriendAliasAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSetFriendAliasAsk& v)
	{
		m_Name = v.name();
		m_RoleId = v.roleid();

	}

private:
	//名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//设置的玩家Id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//获取点数回应封装类
class ContactRpcAcquireGiftPointReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAcquireGiftPointReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcAcquireGiftPointReplyWraper(const ContactRpcAcquireGiftPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAcquireGiftPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAcquireGiftPointReply ToPB() const
	{
		ContactRpcAcquireGiftPointReply v;
		v.set_result( m_Result );
		v.mutable_acquiregiftlist()->Reserve(m_AcquireGiftList.size());
		for (int i=0; i<(int)m_AcquireGiftList.size(); i++)
		{
			*v.add_acquiregiftlist() = m_AcquireGiftList[i].ToPB();
		}
		v.mutable_unacquiregiftlist()->Reserve(m_UnAcquireGiftList.size());
		for (int i=0; i<(int)m_UnAcquireGiftList.size(); i++)
		{
			*v.add_unacquiregiftlist() = m_UnAcquireGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAcquireGiftPointReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAcquireGiftPointReply& v)
	{
		m_Result = v.result();
		m_AcquireGiftList.clear();
		m_AcquireGiftList.reserve(v.acquiregiftlist_size());
		for( int i=0; i<v.acquiregiftlist_size(); i++)
			m_AcquireGiftList.push_back(v.acquiregiftlist(i));
		m_UnAcquireGiftList.clear();
		m_UnAcquireGiftList.reserve(v.unacquiregiftlist_size());
		for( int i=0; i<v.unacquiregiftlist_size(); i++)
			m_UnAcquireGiftList.push_back(v.unacquiregiftlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//已经收取列表
	vector<FriendGiftPointWraper> m_AcquireGiftList;
public:
	int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetAcquireGiftList() const
	{
		return m_AcquireGiftList;
	}
	FriendGiftPointWraper GetAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_AcquireGiftList[Index];
	}
	void SetAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_AcquireGiftList=v;
	}
	void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.clear();
	}
	void SetAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_AcquireGiftList[Index] = v;
	}
	void AddAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_AcquireGiftList.push_back(v);
	}
private:
	//未收取赠送列表
	vector<FriendGiftPointWraper> m_UnAcquireGiftList;
public:
	int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetUnAcquireGiftList() const
	{
		return m_UnAcquireGiftList;
	}
	FriendGiftPointWraper GetUnAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_UnAcquireGiftList[Index];
	}
	void SetUnAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_UnAcquireGiftList=v;
	}
	void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.clear();
	}
	void SetUnAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_UnAcquireGiftList[Index] = v;
	}
	void AddUnAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_UnAcquireGiftList.push_back(v);
	}

};
//刷新未获取点数通知封装类
class ContactRpcUnAcquireGiftPointNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcUnAcquireGiftPointNotifyWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcUnAcquireGiftPointNotifyWraper(const ContactRpcUnAcquireGiftPointNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcUnAcquireGiftPointNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcUnAcquireGiftPointNotify ToPB() const
	{
		ContactRpcUnAcquireGiftPointNotify v;
		v.mutable_unacquiregiftlist()->Reserve(m_UnAcquireGiftList.size());
		for (int i=0; i<(int)m_UnAcquireGiftList.size(); i++)
		{
			*v.add_unacquiregiftlist() = m_UnAcquireGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcUnAcquireGiftPointNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcUnAcquireGiftPointNotify& v)
	{
		m_UnAcquireGiftList.clear();
		m_UnAcquireGiftList.reserve(v.unacquiregiftlist_size());
		for( int i=0; i<v.unacquiregiftlist_size(); i++)
			m_UnAcquireGiftList.push_back(v.unacquiregiftlist(i));

	}

private:
	//未收取赠送列表
	vector<FriendGiftPointWraper> m_UnAcquireGiftList;
public:
	int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetUnAcquireGiftList() const
	{
		return m_UnAcquireGiftList;
	}
	FriendGiftPointWraper GetUnAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_UnAcquireGiftList[Index];
	}
	void SetUnAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_UnAcquireGiftList=v;
	}
	void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.clear();
	}
	void SetUnAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_UnAcquireGiftList[Index] = v;
	}
	void AddUnAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_UnAcquireGiftList.push_back(v);
	}

};
//发送好友点回应封装类
class ContactRpcSendFriendGiftPointReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSendFriendGiftPointReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcSendFriendGiftPointReplyWraper(const ContactRpcSendFriendGiftPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSendFriendGiftPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSendFriendGiftPointReply ToPB() const
	{
		ContactRpcSendFriendGiftPointReply v;
		v.set_result( m_Result );
		v.mutable_sentgiftlist()->Reserve(m_SentGiftList.size());
		for (int i=0; i<(int)m_SentGiftList.size(); i++)
		{
			*v.add_sentgiftlist() = m_SentGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSendFriendGiftPointReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSendFriendGiftPointReply& v)
	{
		m_Result = v.result();
		m_SentGiftList.clear();
		m_SentGiftList.reserve(v.sentgiftlist_size());
		for( int i=0; i<v.sentgiftlist_size(); i++)
			m_SentGiftList.push_back(v.sentgiftlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//已经赠送列表
	vector<FriendGiftPointWraper> m_SentGiftList;
public:
	int SizeSentGiftList()
	{
		return m_SentGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetSentGiftList() const
	{
		return m_SentGiftList;
	}
	FriendGiftPointWraper GetSentGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_SentGiftList[Index];
	}
	void SetSentGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_SentGiftList=v;
	}
	void ClearSentGiftList( )
	{
		m_SentGiftList.clear();
	}
	void SetSentGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return;
		}
		m_SentGiftList[Index] = v;
	}
	void AddSentGiftList( const FriendGiftPointWraper& v )
	{
		m_SentGiftList.push_back(v);
	}

};
//获取点数请求封装类
class ContactRpcAcquireGiftPointAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAcquireGiftPointAskWraper()
	{
		
		m_AcquireRoleId = 0;

	}
	//赋值构造函数
	ContactRpcAcquireGiftPointAskWraper(const ContactRpcAcquireGiftPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAcquireGiftPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAcquireGiftPointAsk ToPB() const
	{
		ContactRpcAcquireGiftPointAsk v;
		v.set_acquireroleid( m_AcquireRoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAcquireGiftPointAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAcquireGiftPointAsk& v)
	{
		m_AcquireRoleId = v.acquireroleid();

	}

private:
	//给谁送
	uint64_t m_AcquireRoleId;
public:
	void SetAcquireRoleId( uint64_t v)
	{
		m_AcquireRoleId=v;
	}
	uint64_t GetAcquireRoleId()
	{
		return m_AcquireRoleId;
	}
	uint64_t GetAcquireRoleId() const
	{
		return m_AcquireRoleId;
	}

};
//添加好友度回应封装类
class ContactRpcAddFriendShipPointReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddFriendShipPointReplyWraper()
	{
		
		m_Result = -1;
		m_Contact = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcAddFriendShipPointReplyWraper(const ContactRpcAddFriendShipPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddFriendShipPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddFriendShipPointReply ToPB() const
	{
		ContactRpcAddFriendShipPointReply v;
		v.set_result( m_Result );
		*v.mutable_contact()= m_Contact.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddFriendShipPointReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddFriendShipPointReply& v)
	{
		m_Result = v.result();
		m_Contact = v.contact();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//更新的人
	ContactDataWraper m_Contact;
public:
	void SetContact( const ContactDataWraper& v)
	{
		m_Contact=v;
	}
	ContactDataWraper GetContact()
	{
		return m_Contact;
	}
	ContactDataWraper GetContact() const
	{
		return m_Contact;
	}

};
//玩家数据更新通知封装类
class ContactRpcRoleDataUpdateNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRoleDataUpdateNotifyWraper()
	{
		
		m_Contact = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcRoleDataUpdateNotifyWraper(const ContactRpcRoleDataUpdateNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRoleDataUpdateNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRoleDataUpdateNotify ToPB() const
	{
		ContactRpcRoleDataUpdateNotify v;
		*v.mutable_contact()= m_Contact.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRoleDataUpdateNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRoleDataUpdateNotify& v)
	{
		m_Contact = v.contact();

	}

private:
	//更新的人
	ContactDataWraper m_Contact;
public:
	void SetContact( const ContactDataWraper& v)
	{
		m_Contact=v;
	}
	ContactDataWraper GetContact()
	{
		return m_Contact;
	}
	ContactDataWraper GetContact() const
	{
		return m_Contact;
	}

};
//拒绝所有申请回应封装类
class ContactRpcRejectAllReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRejectAllReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcRejectAllReplyWraper(const ContactRpcRejectAllReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRejectAllReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRejectAllReply ToPB() const
	{
		ContactRpcRejectAllReply v;
		v.set_result( m_Result );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}
		v.mutable_deleteroleids()->Reserve(m_DeleteRoleIds.size());
		for (int i=0; i<(int)m_DeleteRoleIds.size(); i++)
		{
			v.add_deleteroleids(m_DeleteRoleIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRejectAllReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRejectAllReply& v)
	{
		m_Result = v.result();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));
		m_DeleteRoleIds.clear();
		m_DeleteRoleIds.reserve(v.deleteroleids_size());
		for( int i=0; i<v.deleteroleids_size(); i++)
			m_DeleteRoleIds.push_back(v.deleteroleids(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}
private:
	//删除的id
	vector<uint64_t> m_DeleteRoleIds;
public:
	int SizeDeleteRoleIds()
	{
		return m_DeleteRoleIds.size();
	}
	const vector<uint64_t>& GetDeleteRoleIds() const
	{
		return m_DeleteRoleIds;
	}
	uint64_t GetDeleteRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_DeleteRoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_DeleteRoleIds[Index];
	}
	void SetDeleteRoleIds( const vector<uint64_t>& v )
	{
		m_DeleteRoleIds=v;
	}
	void ClearDeleteRoleIds( )
	{
		m_DeleteRoleIds.clear();
	}
	void SetDeleteRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_DeleteRoleIds.size())
		{
			assert(false);
			return;
		}
		m_DeleteRoleIds[Index] = v;
	}
	void AddDeleteRoleIds( uint64_t v = 0 )
	{
		m_DeleteRoleIds.push_back(v);
	}

};
//添加好友度请求封装类
class ContactRpcAddFriendShipPointAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddFriendShipPointAskWraper()
	{
		
		m_FriendRoleId = 0;

	}
	//赋值构造函数
	ContactRpcAddFriendShipPointAskWraper(const ContactRpcAddFriendShipPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddFriendShipPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddFriendShipPointAsk ToPB() const
	{
		ContactRpcAddFriendShipPointAsk v;
		v.set_friendroleid( m_FriendRoleId );
		v.mutable_itemdata()->Reserve(m_ItemData.size());
		for (int i=0; i<(int)m_ItemData.size(); i++)
		{
			*v.add_itemdata() = m_ItemData[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddFriendShipPointAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddFriendShipPointAsk& v)
	{
		m_FriendRoleId = v.friendroleid();
		m_ItemData.clear();
		m_ItemData.reserve(v.itemdata_size());
		for( int i=0; i<v.itemdata_size(); i++)
			m_ItemData.push_back(v.itemdata(i));

	}

private:
	//好友Guid
	uint64_t m_FriendRoleId;
public:
	void SetFriendRoleId( uint64_t v)
	{
		m_FriendRoleId=v;
	}
	uint64_t GetFriendRoleId()
	{
		return m_FriendRoleId;
	}
	uint64_t GetFriendRoleId() const
	{
		return m_FriendRoleId;
	}
private:
	//物品id
	vector<ItemSimpleDataWraper> m_ItemData;
public:
	int SizeItemData()
	{
		return m_ItemData.size();
	}
	const vector<ItemSimpleDataWraper>& GetItemData() const
	{
		return m_ItemData;
	}
	ItemSimpleDataWraper GetItemData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemData.size())
		{
			assert(false);
			return ItemSimpleDataWraper();
		}
		return m_ItemData[Index];
	}
	void SetItemData( const vector<ItemSimpleDataWraper>& v )
	{
		m_ItemData=v;
	}
	void ClearItemData( )
	{
		m_ItemData.clear();
	}
	void SetItemData( int Index, const ItemSimpleDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemData.size())
		{
			assert(false);
			return;
		}
		m_ItemData[Index] = v;
	}
	void AddItemData( const ItemSimpleDataWraper& v )
	{
		m_ItemData.push_back(v);
	}

};
//删除联系人数据通知封装类
class ContactRpcDeleteRoleDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcDeleteRoleDataNotifyWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcDeleteRoleDataNotifyWraper(const ContactRpcDeleteRoleDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcDeleteRoleDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcDeleteRoleDataNotify ToPB() const
	{
		ContactRpcDeleteRoleDataNotify v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcDeleteRoleDataNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcDeleteRoleDataNotify& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//删除的玩家id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//排序分组请求封装类
class ContactRpcSortGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSortGroupAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcSortGroupAskWraper(const ContactRpcSortGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSortGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSortGroupAsk ToPB() const
	{
		ContactRpcSortGroupAsk v;
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSortGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSortGroupAsk& v)
	{
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//分组id
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//联系人登录通知封装类
class ContactRpcContactLoginNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcContactLoginNotifyWraper()
	{
		
		m_Contact = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcContactLoginNotifyWraper(const ContactRpcContactLoginNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcContactLoginNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcContactLoginNotify ToPB() const
	{
		ContactRpcContactLoginNotify v;
		*v.mutable_contact()= m_Contact.ToPB();
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcContactLoginNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcContactLoginNotify& v)
	{
		m_Contact = v.contact();
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//更新的人
	ContactDataWraper m_Contact;
public:
	void SetContact( const ContactDataWraper& v)
	{
		m_Contact=v;
	}
	ContactDataWraper GetContact()
	{
		return m_Contact;
	}
	ContactDataWraper GetContact() const
	{
		return m_Contact;
	}
private:
	//改变的分组
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//联系人退出游戏通知封装类
class ContactRpcContactLogoutNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcContactLogoutNotifyWraper()
	{
		
		m_Contact = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcContactLogoutNotifyWraper(const ContactRpcContactLogoutNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcContactLogoutNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcContactLogoutNotify ToPB() const
	{
		ContactRpcContactLogoutNotify v;
		*v.mutable_contact()= m_Contact.ToPB();
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcContactLogoutNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcContactLogoutNotify& v)
	{
		m_Contact = v.contact();
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//更新的人
	ContactDataWraper m_Contact;
public:
	void SetContact( const ContactDataWraper& v)
	{
		m_Contact=v;
	}
	ContactDataWraper GetContact()
	{
		return m_Contact;
	}
	ContactDataWraper GetContact() const
	{
		return m_Contact;
	}
private:
	//改变的分组
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//同意所有申请回应封装类
class ContactRpcAgreeAllApplicationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAgreeAllApplicationReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcAgreeAllApplicationReplyWraper(const ContactRpcAgreeAllApplicationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAgreeAllApplicationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAgreeAllApplicationReply ToPB() const
	{
		ContactRpcAgreeAllApplicationReply v;
		v.set_result( m_Result );
		v.mutable_newfrienddata()->Reserve(m_NewFriendData.size());
		for (int i=0; i<(int)m_NewFriendData.size(); i++)
		{
			*v.add_newfrienddata() = m_NewFriendData[i].ToPB();
		}
		v.mutable_myfriendgroup()->Reserve(m_MyFriendGroup.size());
		for (int i=0; i<(int)m_MyFriendGroup.size(); i++)
		{
			*v.add_myfriendgroup() = m_MyFriendGroup[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAgreeAllApplicationReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAgreeAllApplicationReply& v)
	{
		m_Result = v.result();
		m_NewFriendData.clear();
		m_NewFriendData.reserve(v.newfrienddata_size());
		for( int i=0; i<v.newfrienddata_size(); i++)
			m_NewFriendData.push_back(v.newfrienddata(i));
		m_MyFriendGroup.clear();
		m_MyFriendGroup.reserve(v.myfriendgroup_size());
		for( int i=0; i<v.myfriendgroup_size(); i++)
			m_MyFriendGroup.push_back(v.myfriendgroup(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//新玩家数据
	vector<ContactDataWraper> m_NewFriendData;
public:
	int SizeNewFriendData()
	{
		return m_NewFriendData.size();
	}
	const vector<ContactDataWraper>& GetNewFriendData() const
	{
		return m_NewFriendData;
	}
	ContactDataWraper GetNewFriendData(int Index) const
	{
		if(Index<0 || Index>=(int)m_NewFriendData.size())
		{
			assert(false);
			return ContactDataWraper();
		}
		return m_NewFriendData[Index];
	}
	void SetNewFriendData( const vector<ContactDataWraper>& v )
	{
		m_NewFriendData=v;
	}
	void ClearNewFriendData( )
	{
		m_NewFriendData.clear();
	}
	void SetNewFriendData( int Index, const ContactDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_NewFriendData.size())
		{
			assert(false);
			return;
		}
		m_NewFriendData[Index] = v;
	}
	void AddNewFriendData( const ContactDataWraper& v )
	{
		m_NewFriendData.push_back(v);
	}
private:
	//移动来源组
	vector<ContactGroupWraper> m_MyFriendGroup;
public:
	int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.size();
	}
	const vector<ContactGroupWraper>& GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_MyFriendGroup[Index];
	}
	void SetMyFriendGroup( const vector<ContactGroupWraper>& v )
	{
		m_MyFriendGroup=v;
	}
	void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.clear();
	}
	void SetMyFriendGroup( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return;
		}
		m_MyFriendGroup[Index] = v;
	}
	void AddMyFriendGroup( const ContactGroupWraper& v )
	{
		m_MyFriendGroup.push_back(v);
	}

};
//聊天请求封装类
class ContactRpcChatToAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcChatToAskWraper()
	{
		
		m_RoleId = 0;
		m_ChatMsg = ChatMsgWraper();

	}
	//赋值构造函数
	ContactRpcChatToAskWraper(const ContactRpcChatToAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcChatToAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcChatToAsk ToPB() const
	{
		ContactRpcChatToAsk v;
		v.set_roleid( m_RoleId );
		*v.mutable_chatmsg()= m_ChatMsg.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcChatToAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcChatToAsk& v)
	{
		m_RoleId = v.roleid();
		m_ChatMsg = v.chatmsg();

	}

private:
	//需要发送信息的人的唯一id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//聊天信息
	ChatMsgWraper m_ChatMsg;
public:
	void SetChatMsg( const ChatMsgWraper& v)
	{
		m_ChatMsg=v;
	}
	ChatMsgWraper GetChatMsg()
	{
		return m_ChatMsg;
	}
	ChatMsgWraper GetChatMsg() const
	{
		return m_ChatMsg;
	}

};
//刷新组通知封装类
class ContactRpcContactsGroupsNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcContactsGroupsNotifyWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcContactsGroupsNotifyWraper(const ContactRpcContactsGroupsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcContactsGroupsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcContactsGroupsNotify ToPB() const
	{
		ContactRpcContactsGroupsNotify v;
		v.mutable_myfriendgroup()->Reserve(m_MyFriendGroup.size());
		for (int i=0; i<(int)m_MyFriendGroup.size(); i++)
		{
			*v.add_myfriendgroup() = m_MyFriendGroup[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcContactsGroupsNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcContactsGroupsNotify& v)
	{
		m_MyFriendGroup.clear();
		m_MyFriendGroup.reserve(v.myfriendgroup_size());
		for( int i=0; i<v.myfriendgroup_size(); i++)
			m_MyFriendGroup.push_back(v.myfriendgroup(i));

	}

private:
	//分组信息
	vector<ContactGroupWraper> m_MyFriendGroup;
public:
	int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.size();
	}
	const vector<ContactGroupWraper>& GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_MyFriendGroup[Index];
	}
	void SetMyFriendGroup( const vector<ContactGroupWraper>& v )
	{
		m_MyFriendGroup=v;
	}
	void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.clear();
	}
	void SetMyFriendGroup( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return;
		}
		m_MyFriendGroup[Index] = v;
	}
	void AddMyFriendGroup( const ContactGroupWraper& v )
	{
		m_MyFriendGroup.push_back(v);
	}

};
//同意所有申请请求封装类
class ContactRpcAgreeAllApplicationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAgreeAllApplicationAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcAgreeAllApplicationAskWraper(const ContactRpcAgreeAllApplicationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAgreeAllApplicationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAgreeAllApplicationAsk ToPB() const
	{
		ContactRpcAgreeAllApplicationAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAgreeAllApplicationAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAgreeAllApplicationAsk& v)
	{

	}


};
//读取信息请求封装类
class ContactRpcReadMsgAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcReadMsgAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcReadMsgAskWraper(const ContactRpcReadMsgAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcReadMsgAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcReadMsgAsk ToPB() const
	{
		ContactRpcReadMsgAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcReadMsgAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcReadMsgAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//已读玩家id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//读取信息回应封装类
class ContactRpcReadMsgReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcReadMsgReplyWraper()
	{
		
		m_Result = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcReadMsgReplyWraper(const ContactRpcReadMsgReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcReadMsgReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcReadMsgReply ToPB() const
	{
		ContactRpcReadMsgReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcReadMsgReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcReadMsgReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//已读玩家id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//聊天回应封装类
class ContactRpcChatToReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcChatToReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcChatToReplyWraper(const ContactRpcChatToReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcChatToReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcChatToReply ToPB() const
	{
		ContactRpcChatToReply v;
		v.set_result( m_Result );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcChatToReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcChatToReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//新的聊天信息通知封装类
class ContactRpcNewChatMsgNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcNewChatMsgNotifyWraper()
	{
		
		m_ChatMsg = ChatInfoWraper();
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcNewChatMsgNotifyWraper(const ContactRpcNewChatMsgNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcNewChatMsgNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcNewChatMsgNotify ToPB() const
	{
		ContactRpcNewChatMsgNotify v;
		*v.mutable_chatmsg()= m_ChatMsg.ToPB();
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcNewChatMsgNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcNewChatMsgNotify& v)
	{
		m_ChatMsg = v.chatmsg();
		m_RoleId = v.roleid();

	}

private:
	//新的聊天信息
	ChatInfoWraper m_ChatMsg;
public:
	void SetChatMsg( const ChatInfoWraper& v)
	{
		m_ChatMsg=v;
	}
	ChatInfoWraper GetChatMsg()
	{
		return m_ChatMsg;
	}
	ChatInfoWraper GetChatMsg() const
	{
		return m_ChatMsg;
	}
private:
	//聊天Id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//一键收取请求封装类
class ContactRpcAcquireAllGiftPointAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAcquireAllGiftPointAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcAcquireAllGiftPointAskWraper(const ContactRpcAcquireAllGiftPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAcquireAllGiftPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAcquireAllGiftPointAsk ToPB() const
	{
		ContactRpcAcquireAllGiftPointAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAcquireAllGiftPointAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAcquireAllGiftPointAsk& v)
	{

	}


};
//一键收取回应封装类
class ContactRpcAcquireAllGiftPointReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAcquireAllGiftPointReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcAcquireAllGiftPointReplyWraper(const ContactRpcAcquireAllGiftPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAcquireAllGiftPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAcquireAllGiftPointReply ToPB() const
	{
		ContactRpcAcquireAllGiftPointReply v;
		v.set_result( m_Result );
		v.mutable_acquiregiftlist()->Reserve(m_AcquireGiftList.size());
		for (int i=0; i<(int)m_AcquireGiftList.size(); i++)
		{
			*v.add_acquiregiftlist() = m_AcquireGiftList[i].ToPB();
		}
		v.mutable_unacquiregiftlist()->Reserve(m_UnAcquireGiftList.size());
		for (int i=0; i<(int)m_UnAcquireGiftList.size(); i++)
		{
			*v.add_unacquiregiftlist() = m_UnAcquireGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAcquireAllGiftPointReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAcquireAllGiftPointReply& v)
	{
		m_Result = v.result();
		m_AcquireGiftList.clear();
		m_AcquireGiftList.reserve(v.acquiregiftlist_size());
		for( int i=0; i<v.acquiregiftlist_size(); i++)
			m_AcquireGiftList.push_back(v.acquiregiftlist(i));
		m_UnAcquireGiftList.clear();
		m_UnAcquireGiftList.reserve(v.unacquiregiftlist_size());
		for( int i=0; i<v.unacquiregiftlist_size(); i++)
			m_UnAcquireGiftList.push_back(v.unacquiregiftlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//已经收取列表
	vector<FriendGiftPointWraper> m_AcquireGiftList;
public:
	int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetAcquireGiftList() const
	{
		return m_AcquireGiftList;
	}
	FriendGiftPointWraper GetAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_AcquireGiftList[Index];
	}
	void SetAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_AcquireGiftList=v;
	}
	void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.clear();
	}
	void SetAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_AcquireGiftList[Index] = v;
	}
	void AddAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_AcquireGiftList.push_back(v);
	}
private:
	//未收取赠送列表
	vector<FriendGiftPointWraper> m_UnAcquireGiftList;
public:
	int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetUnAcquireGiftList() const
	{
		return m_UnAcquireGiftList;
	}
	FriendGiftPointWraper GetUnAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_UnAcquireGiftList[Index];
	}
	void SetUnAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_UnAcquireGiftList=v;
	}
	void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.clear();
	}
	void SetUnAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_UnAcquireGiftList[Index] = v;
	}
	void AddUnAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_UnAcquireGiftList.push_back(v);
	}

};
//一键赠送请求封装类
class ContactRpcSendAllFriendGiftPointAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSendAllFriendGiftPointAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcSendAllFriendGiftPointAskWraper(const ContactRpcSendAllFriendGiftPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSendAllFriendGiftPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSendAllFriendGiftPointAsk ToPB() const
	{
		ContactRpcSendAllFriendGiftPointAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSendAllFriendGiftPointAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSendAllFriendGiftPointAsk& v)
	{

	}


};
//一键赠送回应封装类
class ContactRpcSendAllFriendGiftPointReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSendAllFriendGiftPointReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcSendAllFriendGiftPointReplyWraper(const ContactRpcSendAllFriendGiftPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSendAllFriendGiftPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSendAllFriendGiftPointReply ToPB() const
	{
		ContactRpcSendAllFriendGiftPointReply v;
		v.set_result( m_Result );
		v.mutable_sentgiftlist()->Reserve(m_SentGiftList.size());
		for (int i=0; i<(int)m_SentGiftList.size(); i++)
		{
			*v.add_sentgiftlist() = m_SentGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSendAllFriendGiftPointReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSendAllFriendGiftPointReply& v)
	{
		m_Result = v.result();
		m_SentGiftList.clear();
		m_SentGiftList.reserve(v.sentgiftlist_size());
		for( int i=0; i<v.sentgiftlist_size(); i++)
			m_SentGiftList.push_back(v.sentgiftlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//已经赠送列表
	vector<FriendGiftPointWraper> m_SentGiftList;
public:
	int SizeSentGiftList()
	{
		return m_SentGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetSentGiftList() const
	{
		return m_SentGiftList;
	}
	FriendGiftPointWraper GetSentGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_SentGiftList[Index];
	}
	void SetSentGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_SentGiftList=v;
	}
	void ClearSentGiftList( )
	{
		m_SentGiftList.clear();
	}
	void SetSentGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return;
		}
		m_SentGiftList[Index] = v;
	}
	void AddSentGiftList( const FriendGiftPointWraper& v )
	{
		m_SentGiftList.push_back(v);
	}

};
//新加玩家数据通知封装类
class ContactRpcAddRoleDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddRoleDataNotifyWraper()
	{
		
		m_NewRoleData = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcAddRoleDataNotifyWraper(const ContactRpcAddRoleDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddRoleDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddRoleDataNotify ToPB() const
	{
		ContactRpcAddRoleDataNotify v;
		*v.mutable_newroledata()= m_NewRoleData.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddRoleDataNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddRoleDataNotify& v)
	{
		m_NewRoleData = v.newroledata();

	}

private:
	//新的联系人数据
	ContactDataWraper m_NewRoleData;
public:
	void SetNewRoleData( const ContactDataWraper& v)
	{
		m_NewRoleData=v;
	}
	ContactDataWraper GetNewRoleData()
	{
		return m_NewRoleData;
	}
	ContactDataWraper GetNewRoleData() const
	{
		return m_NewRoleData;
	}

};
//设置友情点数据通知封装类
class ContactRpcSetGiftPointNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSetGiftPointNotifyWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcSetGiftPointNotifyWraper(const ContactRpcSetGiftPointNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSetGiftPointNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSetGiftPointNotify ToPB() const
	{
		ContactRpcSetGiftPointNotify v;
		v.mutable_acquiregiftlist()->Reserve(m_AcquireGiftList.size());
		for (int i=0; i<(int)m_AcquireGiftList.size(); i++)
		{
			*v.add_acquiregiftlist() = m_AcquireGiftList[i].ToPB();
		}
		v.mutable_unacquiregiftlist()->Reserve(m_UnAcquireGiftList.size());
		for (int i=0; i<(int)m_UnAcquireGiftList.size(); i++)
		{
			*v.add_unacquiregiftlist() = m_UnAcquireGiftList[i].ToPB();
		}
		v.mutable_sentgiftlist()->Reserve(m_SentGiftList.size());
		for (int i=0; i<(int)m_SentGiftList.size(); i++)
		{
			*v.add_sentgiftlist() = m_SentGiftList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSetGiftPointNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSetGiftPointNotify& v)
	{
		m_AcquireGiftList.clear();
		m_AcquireGiftList.reserve(v.acquiregiftlist_size());
		for( int i=0; i<v.acquiregiftlist_size(); i++)
			m_AcquireGiftList.push_back(v.acquiregiftlist(i));
		m_UnAcquireGiftList.clear();
		m_UnAcquireGiftList.reserve(v.unacquiregiftlist_size());
		for( int i=0; i<v.unacquiregiftlist_size(); i++)
			m_UnAcquireGiftList.push_back(v.unacquiregiftlist(i));
		m_SentGiftList.clear();
		m_SentGiftList.reserve(v.sentgiftlist_size());
		for( int i=0; i<v.sentgiftlist_size(); i++)
			m_SentGiftList.push_back(v.sentgiftlist(i));

	}

private:
	//已经收取列表
	vector<FriendGiftPointWraper> m_AcquireGiftList;
public:
	int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetAcquireGiftList() const
	{
		return m_AcquireGiftList;
	}
	FriendGiftPointWraper GetAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_AcquireGiftList[Index];
	}
	void SetAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_AcquireGiftList=v;
	}
	void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.clear();
	}
	void SetAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_AcquireGiftList[Index] = v;
	}
	void AddAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_AcquireGiftList.push_back(v);
	}
private:
	//未收取赠送列表
	vector<FriendGiftPointWraper> m_UnAcquireGiftList;
public:
	int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetUnAcquireGiftList() const
	{
		return m_UnAcquireGiftList;
	}
	FriendGiftPointWraper GetUnAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_UnAcquireGiftList[Index];
	}
	void SetUnAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_UnAcquireGiftList=v;
	}
	void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.clear();
	}
	void SetUnAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_UnAcquireGiftList[Index] = v;
	}
	void AddUnAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_UnAcquireGiftList.push_back(v);
	}
private:
	//已经赠送列表
	vector<FriendGiftPointWraper> m_SentGiftList;
public:
	int SizeSentGiftList()
	{
		return m_SentGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetSentGiftList() const
	{
		return m_SentGiftList;
	}
	FriendGiftPointWraper GetSentGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_SentGiftList[Index];
	}
	void SetSentGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_SentGiftList=v;
	}
	void ClearSentGiftList( )
	{
		m_SentGiftList.clear();
	}
	void SetSentGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return;
		}
		m_SentGiftList[Index] = v;
	}
	void AddSentGiftList( const FriendGiftPointWraper& v )
	{
		m_SentGiftList.push_back(v);
	}

};
//移出列表请求封装类
class ContactRpcDeleteGroupRoleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcDeleteGroupRoleAskWraper()
	{
		
		m_GroupId = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcDeleteGroupRoleAskWraper(const ContactRpcDeleteGroupRoleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcDeleteGroupRoleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcDeleteGroupRoleAsk ToPB() const
	{
		ContactRpcDeleteGroupRoleAsk v;
		v.set_groupid( m_GroupId );
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcDeleteGroupRoleAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcDeleteGroupRoleAsk& v)
	{
		m_GroupId = v.groupid();
		m_RoleId = v.roleid();

	}

private:
	//分组Id
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}
private:
	//玩家id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//移出列表回应封装类
class ContactRpcDeleteGroupRoleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcDeleteGroupRoleReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcDeleteGroupRoleReplyWraper(const ContactRpcDeleteGroupRoleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcDeleteGroupRoleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcDeleteGroupRoleReply ToPB() const
	{
		ContactRpcDeleteGroupRoleReply v;
		v.set_result( m_Result );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcDeleteGroupRoleReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcDeleteGroupRoleReply& v)
	{
		m_Result = v.result();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}

};
//拒绝所有申请请求封装类
class ContactRpcRejectAllAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRejectAllAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcRejectAllAskWraper(const ContactRpcRejectAllAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRejectAllAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRejectAllAsk ToPB() const
	{
		ContactRpcRejectAllAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRejectAllAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRejectAllAsk& v)
	{

	}


};
//创建好友分组请求封装类
class ContactRpcCreateFriendGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcCreateFriendGroupAskWraper()
	{
		
		m_GroupName = "";

	}
	//赋值构造函数
	ContactRpcCreateFriendGroupAskWraper(const ContactRpcCreateFriendGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcCreateFriendGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcCreateFriendGroupAsk ToPB() const
	{
		ContactRpcCreateFriendGroupAsk v;
		v.set_groupname( m_GroupName );
		v.mutable_roleids()->Reserve(m_RoleIds.size());
		for (int i=0; i<(int)m_RoleIds.size(); i++)
		{
			v.add_roleids(m_RoleIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcCreateFriendGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcCreateFriendGroupAsk& v)
	{
		m_GroupName = v.groupname();
		m_RoleIds.clear();
		m_RoleIds.reserve(v.roleids_size());
		for( int i=0; i<v.roleids_size(); i++)
			m_RoleIds.push_back(v.roleids(i));

	}

private:
	//分组名字
	string m_GroupName;
public:
	void SetGroupName( const string& v)
	{
		m_GroupName=v;
	}
	string GetGroupName()
	{
		return m_GroupName;
	}
	string GetGroupName() const
	{
		return m_GroupName;
	}
private:
	//分组玩家id
	vector<uint64_t> m_RoleIds;
public:
	int SizeRoleIds()
	{
		return m_RoleIds.size();
	}
	const vector<uint64_t>& GetRoleIds() const
	{
		return m_RoleIds;
	}
	uint64_t GetRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleIds[Index];
	}
	void SetRoleIds( const vector<uint64_t>& v )
	{
		m_RoleIds=v;
	}
	void ClearRoleIds( )
	{
		m_RoleIds.clear();
	}
	void SetRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return;
		}
		m_RoleIds[Index] = v;
	}
	void AddRoleIds( uint64_t v = 0 )
	{
		m_RoleIds.push_back(v);
	}

};
//创建好友分组回应封装类
class ContactRpcCreateFriendGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcCreateFriendGroupReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcCreateFriendGroupReplyWraper(const ContactRpcCreateFriendGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcCreateFriendGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcCreateFriendGroupReply ToPB() const
	{
		ContactRpcCreateFriendGroupReply v;
		v.set_result( m_Result );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcCreateFriendGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcCreateFriendGroupReply& v)
	{
		m_Result = v.result();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}
private:
	//排序分组id
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//联系人设置请求封装类
class ContactRpcContactSettingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcContactSettingAskWraper()
	{
		
		m_NewSetting = ContactSettingWraper();

	}
	//赋值构造函数
	ContactRpcContactSettingAskWraper(const ContactRpcContactSettingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcContactSettingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcContactSettingAsk ToPB() const
	{
		ContactRpcContactSettingAsk v;
		*v.mutable_newsetting()= m_NewSetting.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcContactSettingAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcContactSettingAsk& v)
	{
		m_NewSetting = v.newsetting();

	}

private:
	//新设置
	ContactSettingWraper m_NewSetting;
public:
	void SetNewSetting( const ContactSettingWraper& v)
	{
		m_NewSetting=v;
	}
	ContactSettingWraper GetNewSetting()
	{
		return m_NewSetting;
	}
	ContactSettingWraper GetNewSetting() const
	{
		return m_NewSetting;
	}

};
//联系人设置回应封装类
class ContactRpcContactSettingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcContactSettingReplyWraper()
	{
		
		m_Result = -1;
		m_NewSetting = ContactSettingWraper();

	}
	//赋值构造函数
	ContactRpcContactSettingReplyWraper(const ContactRpcContactSettingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcContactSettingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcContactSettingReply ToPB() const
	{
		ContactRpcContactSettingReply v;
		v.set_result( m_Result );
		*v.mutable_newsetting()= m_NewSetting.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcContactSettingReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcContactSettingReply& v)
	{
		m_Result = v.result();
		m_NewSetting = v.newsetting();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//新设置
	ContactSettingWraper m_NewSetting;
public:
	void SetNewSetting( const ContactSettingWraper& v)
	{
		m_NewSetting=v;
	}
	ContactSettingWraper GetNewSetting()
	{
		return m_NewSetting;
	}
	ContactSettingWraper GetNewSetting() const
	{
		return m_NewSetting;
	}

};
//删除好友分组请求封装类
class ContactRpcRemoveFriendGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRemoveFriendGroupAskWraper()
	{
		
		m_RemoveGroupId = -1;

	}
	//赋值构造函数
	ContactRpcRemoveFriendGroupAskWraper(const ContactRpcRemoveFriendGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRemoveFriendGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRemoveFriendGroupAsk ToPB() const
	{
		ContactRpcRemoveFriendGroupAsk v;
		v.set_removegroupid( m_RemoveGroupId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRemoveFriendGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRemoveFriendGroupAsk& v)
	{
		m_RemoveGroupId = v.removegroupid();

	}

private:
	//源组ID
	INT32 m_RemoveGroupId;
public:
	void SetRemoveGroupId( INT32 v)
	{
		m_RemoveGroupId=v;
	}
	INT32 GetRemoveGroupId()
	{
		return m_RemoveGroupId;
	}
	INT32 GetRemoveGroupId() const
	{
		return m_RemoveGroupId;
	}

};
//删除好友分组回应封装类
class ContactRpcRemoveFriendGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRemoveFriendGroupReplyWraper()
	{
		
		m_Result = -1;
		m_MyFriendGroup = ContactGroupWraper();
		m_RemoveGroupId = -1;

	}
	//赋值构造函数
	ContactRpcRemoveFriendGroupReplyWraper(const ContactRpcRemoveFriendGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRemoveFriendGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRemoveFriendGroupReply ToPB() const
	{
		ContactRpcRemoveFriendGroupReply v;
		v.set_result( m_Result );
		*v.mutable_myfriendgroup()= m_MyFriendGroup.ToPB();
		v.set_removegroupid( m_RemoveGroupId );
		v.mutable_groupids()->Reserve(m_GroupIds.size());
		for (int i=0; i<(int)m_GroupIds.size(); i++)
		{
			v.add_groupids(m_GroupIds[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRemoveFriendGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRemoveFriendGroupReply& v)
	{
		m_Result = v.result();
		m_MyFriendGroup = v.myfriendgroup();
		m_RemoveGroupId = v.removegroupid();
		m_GroupIds.clear();
		m_GroupIds.reserve(v.groupids_size());
		for( int i=0; i<v.groupids_size(); i++)
			m_GroupIds.push_back(v.groupids(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//移动来源组
	ContactGroupWraper m_MyFriendGroup;
public:
	void SetMyFriendGroup( const ContactGroupWraper& v)
	{
		m_MyFriendGroup=v;
	}
	ContactGroupWraper GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}
private:
	//源组ID
	INT32 m_RemoveGroupId;
public:
	void SetRemoveGroupId( INT32 v)
	{
		m_RemoveGroupId=v;
	}
	INT32 GetRemoveGroupId()
	{
		return m_RemoveGroupId;
	}
	INT32 GetRemoveGroupId() const
	{
		return m_RemoveGroupId;
	}
private:
	//排序分组id
	vector<INT32> m_GroupIds;
public:
	int SizeGroupIds()
	{
		return m_GroupIds.size();
	}
	const vector<INT32>& GetGroupIds() const
	{
		return m_GroupIds;
	}
	INT32 GetGroupIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return INT32();
		}
		return m_GroupIds[Index];
	}
	void SetGroupIds( const vector<INT32>& v )
	{
		m_GroupIds=v;
	}
	void ClearGroupIds( )
	{
		m_GroupIds.clear();
	}
	void SetGroupIds( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GroupIds.size())
		{
			assert(false);
			return;
		}
		m_GroupIds[Index] = v;
	}
	void AddGroupIds( INT32 v = -1 )
	{
		m_GroupIds.push_back(v);
	}

};
//移动到分组请求封装类
class ContactRpcMoveToFriendGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcMoveToFriendGroupAskWraper()
	{
		
		m_FromGroupId = -1;
		m_ToGroupId = -1;

	}
	//赋值构造函数
	ContactRpcMoveToFriendGroupAskWraper(const ContactRpcMoveToFriendGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcMoveToFriendGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcMoveToFriendGroupAsk ToPB() const
	{
		ContactRpcMoveToFriendGroupAsk v;
		v.mutable_roleids()->Reserve(m_RoleIds.size());
		for (int i=0; i<(int)m_RoleIds.size(); i++)
		{
			v.add_roleids(m_RoleIds[i]);
		}
		v.set_fromgroupid( m_FromGroupId );
		v.set_togroupid( m_ToGroupId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcMoveToFriendGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcMoveToFriendGroupAsk& v)
	{
		m_RoleIds.clear();
		m_RoleIds.reserve(v.roleids_size());
		for( int i=0; i<v.roleids_size(); i++)
			m_RoleIds.push_back(v.roleids(i));
		m_FromGroupId = v.fromgroupid();
		m_ToGroupId = v.togroupid();

	}

private:
	//玩家Id
	vector<uint64_t> m_RoleIds;
public:
	int SizeRoleIds()
	{
		return m_RoleIds.size();
	}
	const vector<uint64_t>& GetRoleIds() const
	{
		return m_RoleIds;
	}
	uint64_t GetRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleIds[Index];
	}
	void SetRoleIds( const vector<uint64_t>& v )
	{
		m_RoleIds=v;
	}
	void ClearRoleIds( )
	{
		m_RoleIds.clear();
	}
	void SetRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return;
		}
		m_RoleIds[Index] = v;
	}
	void AddRoleIds( uint64_t v = 0 )
	{
		m_RoleIds.push_back(v);
	}
private:
	//源组ID
	INT32 m_FromGroupId;
public:
	void SetFromGroupId( INT32 v)
	{
		m_FromGroupId=v;
	}
	INT32 GetFromGroupId()
	{
		return m_FromGroupId;
	}
	INT32 GetFromGroupId() const
	{
		return m_FromGroupId;
	}
private:
	//目标组
	INT32 m_ToGroupId;
public:
	void SetToGroupId( INT32 v)
	{
		m_ToGroupId=v;
	}
	INT32 GetToGroupId()
	{
		return m_ToGroupId;
	}
	INT32 GetToGroupId() const
	{
		return m_ToGroupId;
	}

};
//移动到分组回应封装类
class ContactRpcMoveToFriendGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcMoveToFriendGroupReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcMoveToFriendGroupReplyWraper(const ContactRpcMoveToFriendGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcMoveToFriendGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcMoveToFriendGroupReply ToPB() const
	{
		ContactRpcMoveToFriendGroupReply v;
		v.set_result( m_Result );
		v.mutable_changegroup()->Reserve(m_ChangeGroup.size());
		for (int i=0; i<(int)m_ChangeGroup.size(); i++)
		{
			*v.add_changegroup() = m_ChangeGroup[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcMoveToFriendGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcMoveToFriendGroupReply& v)
	{
		m_Result = v.result();
		m_ChangeGroup.clear();
		m_ChangeGroup.reserve(v.changegroup_size());
		for( int i=0; i<v.changegroup_size(); i++)
			m_ChangeGroup.push_back(v.changegroup(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//移动来源组
	vector<ContactGroupWraper> m_ChangeGroup;
public:
	int SizeChangeGroup()
	{
		return m_ChangeGroup.size();
	}
	const vector<ContactGroupWraper>& GetChangeGroup() const
	{
		return m_ChangeGroup;
	}
	ContactGroupWraper GetChangeGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_ChangeGroup.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ChangeGroup[Index];
	}
	void SetChangeGroup( const vector<ContactGroupWraper>& v )
	{
		m_ChangeGroup=v;
	}
	void ClearChangeGroup( )
	{
		m_ChangeGroup.clear();
	}
	void SetChangeGroup( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ChangeGroup.size())
		{
			assert(false);
			return;
		}
		m_ChangeGroup[Index] = v;
	}
	void AddChangeGroup( const ContactGroupWraper& v )
	{
		m_ChangeGroup.push_back(v);
	}

};
//删除好友请求封装类
class ContactRpcCancelRelationShipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcCancelRelationShipAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcCancelRelationShipAskWraper(const ContactRpcCancelRelationShipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcCancelRelationShipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcCancelRelationShipAsk ToPB() const
	{
		ContactRpcCancelRelationShipAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcCancelRelationShipAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcCancelRelationShipAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//删除的好友
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//删除好友回应封装类
class ContactRpcCancelRelationShipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcCancelRelationShipReplyWraper()
	{
		
		m_Result = -1;
		m_DeleteRoleId = 0;

	}
	//赋值构造函数
	ContactRpcCancelRelationShipReplyWraper(const ContactRpcCancelRelationShipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcCancelRelationShipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcCancelRelationShipReply ToPB() const
	{
		ContactRpcCancelRelationShipReply v;
		v.set_result( m_Result );
		v.set_deleteroleid( m_DeleteRoleId );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcCancelRelationShipReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcCancelRelationShipReply& v)
	{
		m_Result = v.result();
		m_DeleteRoleId = v.deleteroleid();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//删除的数据
	uint64_t m_DeleteRoleId;
public:
	void SetDeleteRoleId( uint64_t v)
	{
		m_DeleteRoleId=v;
	}
	uint64_t GetDeleteRoleId()
	{
		return m_DeleteRoleId;
	}
	uint64_t GetDeleteRoleId() const
	{
		return m_DeleteRoleId;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}

};
//添加好友请求封装类
class ContactRpcAddFriendAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddFriendAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcAddFriendAskWraper(const ContactRpcAddFriendAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddFriendAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddFriendAsk ToPB() const
	{
		ContactRpcAddFriendAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddFriendAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddFriendAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//新加朋友的id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//添加好友回应封装类
class ContactRpcAddFriendReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddFriendReplyWraper()
	{
		
		m_Result = -1;
		m_NewFriendData = ContactDataWraper();
		m_MyFriendGroup = ContactGroupWraper();

	}
	//赋值构造函数
	ContactRpcAddFriendReplyWraper(const ContactRpcAddFriendReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddFriendReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddFriendReply ToPB() const
	{
		ContactRpcAddFriendReply v;
		v.set_result( m_Result );
		*v.mutable_newfrienddata()= m_NewFriendData.ToPB();
		*v.mutable_myfriendgroup()= m_MyFriendGroup.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddFriendReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddFriendReply& v)
	{
		m_Result = v.result();
		m_NewFriendData = v.newfrienddata();
		m_MyFriendGroup = v.myfriendgroup();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//新玩家数据
	ContactDataWraper m_NewFriendData;
public:
	void SetNewFriendData( const ContactDataWraper& v)
	{
		m_NewFriendData=v;
	}
	ContactDataWraper GetNewFriendData()
	{
		return m_NewFriendData;
	}
	ContactDataWraper GetNewFriendData() const
	{
		return m_NewFriendData;
	}
private:
	//好友分组
	ContactGroupWraper m_MyFriendGroup;
public:
	void SetMyFriendGroup( const ContactGroupWraper& v)
	{
		m_MyFriendGroup=v;
	}
	ContactGroupWraper GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}

};
//通讯录数据请求封装类
class ContactRpcSyncAddressBookAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSyncAddressBookAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcSyncAddressBookAskWraper(const ContactRpcSyncAddressBookAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSyncAddressBookAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSyncAddressBookAsk ToPB() const
	{
		ContactRpcSyncAddressBookAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSyncAddressBookAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSyncAddressBookAsk& v)
	{

	}


};
//通讯录数据回应封装类
class ContactRpcSyncAddressBookReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSyncAddressBookReplyWraper()
	{
		
		m_Result = -1;
		m_AddressBock = AddressBookWraper();

	}
	//赋值构造函数
	ContactRpcSyncAddressBookReplyWraper(const ContactRpcSyncAddressBookReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSyncAddressBookReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSyncAddressBookReply ToPB() const
	{
		ContactRpcSyncAddressBookReply v;
		v.set_result( m_Result );
		*v.mutable_addressbock()= m_AddressBock.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSyncAddressBookReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSyncAddressBookReply& v)
	{
		m_Result = v.result();
		m_AddressBock = v.addressbock();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//通讯录数据
	AddressBookWraper m_AddressBock;
public:
	void SetAddressBock( const AddressBookWraper& v)
	{
		m_AddressBock=v;
	}
	AddressBookWraper GetAddressBock()
	{
		return m_AddressBock;
	}
	AddressBookWraper GetAddressBock() const
	{
		return m_AddressBock;
	}

};
//加入黑名单请求封装类
class ContactRpcAddBlackListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddBlackListAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcAddBlackListAskWraper(const ContactRpcAddBlackListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddBlackListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddBlackListAsk ToPB() const
	{
		ContactRpcAddBlackListAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddBlackListAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddBlackListAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//删除的好友
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//加入黑名单回应封装类
class ContactRpcAddBlackListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAddBlackListReplyWraper()
	{
		
		m_Result = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcAddBlackListReplyWraper(const ContactRpcAddBlackListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAddBlackListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAddBlackListReply ToPB() const
	{
		ContactRpcAddBlackListReply v;
		v.set_result( m_Result );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAddBlackListReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAddBlackListReply& v)
	{
		m_Result = v.result();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));
		m_RoleId = v.roleid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}
private:
	//删除的数据
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//拒绝申请回应封装类
class ContactRpcRejectApplyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRejectApplyReplyWraper()
	{
		
		m_Result = -1;
		m_DeleteRoleId = 0;

	}
	//赋值构造函数
	ContactRpcRejectApplyReplyWraper(const ContactRpcRejectApplyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRejectApplyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRejectApplyReply ToPB() const
	{
		ContactRpcRejectApplyReply v;
		v.set_result( m_Result );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}
		v.set_deleteroleid( m_DeleteRoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRejectApplyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRejectApplyReply& v)
	{
		m_Result = v.result();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));
		m_DeleteRoleId = v.deleteroleid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}
private:
	//删除的id
	uint64_t m_DeleteRoleId;
public:
	void SetDeleteRoleId( uint64_t v)
	{
		m_DeleteRoleId=v;
	}
	uint64_t GetDeleteRoleId()
	{
		return m_DeleteRoleId;
	}
	uint64_t GetDeleteRoleId() const
	{
		return m_DeleteRoleId;
	}

};
//被拒绝通知封装类
class ContactRpcBeRejectApplyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcBeRejectApplyNotifyWraper()
	{
		
		m_DeleteFriendData = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcBeRejectApplyNotifyWraper(const ContactRpcBeRejectApplyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcBeRejectApplyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcBeRejectApplyNotify ToPB() const
	{
		ContactRpcBeRejectApplyNotify v;
		*v.mutable_deletefrienddata()= m_DeleteFriendData.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcBeRejectApplyNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcBeRejectApplyNotify& v)
	{
		m_DeleteFriendData = v.deletefrienddata();

	}

private:
	//被拒绝的人信息,不要加到role data里面
	ContactDataWraper m_DeleteFriendData;
public:
	void SetDeleteFriendData( const ContactDataWraper& v)
	{
		m_DeleteFriendData=v;
	}
	ContactDataWraper GetDeleteFriendData()
	{
		return m_DeleteFriendData;
	}
	ContactDataWraper GetDeleteFriendData() const
	{
		return m_DeleteFriendData;
	}

};
//申请列表通知封装类
class ContactRpcApplyListNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcApplyListNotifyWraper()
	{
		
		m_ApplyFriendData = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcApplyListNotifyWraper(const ContactRpcApplyListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcApplyListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcApplyListNotify ToPB() const
	{
		ContactRpcApplyListNotify v;
		*v.mutable_applyfrienddata()= m_ApplyFriendData.ToPB();
		v.mutable_applygroups()->Reserve(m_ApplyGroups.size());
		for (int i=0; i<(int)m_ApplyGroups.size(); i++)
		{
			*v.add_applygroups() = m_ApplyGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcApplyListNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcApplyListNotify& v)
	{
		m_ApplyFriendData = v.applyfrienddata();
		m_ApplyGroups.clear();
		m_ApplyGroups.reserve(v.applygroups_size());
		for( int i=0; i<v.applygroups_size(); i++)
			m_ApplyGroups.push_back(v.applygroups(i));

	}

private:
	//新玩家数据
	ContactDataWraper m_ApplyFriendData;
public:
	void SetApplyFriendData( const ContactDataWraper& v)
	{
		m_ApplyFriendData=v;
	}
	ContactDataWraper GetApplyFriendData()
	{
		return m_ApplyFriendData;
	}
	ContactDataWraper GetApplyFriendData() const
	{
		return m_ApplyFriendData;
	}
private:
	//分组信息
	vector<ContactGroupWraper> m_ApplyGroups;
public:
	int SizeApplyGroups()
	{
		return m_ApplyGroups.size();
	}
	const vector<ContactGroupWraper>& GetApplyGroups() const
	{
		return m_ApplyGroups;
	}
	ContactGroupWraper GetApplyGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ApplyGroups[Index];
	}
	void SetApplyGroups( const vector<ContactGroupWraper>& v )
	{
		m_ApplyGroups=v;
	}
	void ClearApplyGroups( )
	{
		m_ApplyGroups.clear();
	}
	void SetApplyGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ApplyGroups.size())
		{
			assert(false);
			return;
		}
		m_ApplyGroups[Index] = v;
	}
	void AddApplyGroups( const ContactGroupWraper& v )
	{
		m_ApplyGroups.push_back(v);
	}

};
//拒绝申请请求封装类
class ContactRpcRejectApplyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRejectApplyAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcRejectApplyAskWraper(const ContactRpcRejectApplyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRejectApplyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRejectApplyAsk ToPB() const
	{
		ContactRpcRejectApplyAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRejectApplyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRejectApplyAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//玩家ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//推荐联系人请求封装类
class ContactRpcRecommendContactAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRecommendContactAskWraper()
	{
		

	}
	//赋值构造函数
	ContactRpcRecommendContactAskWraper(const ContactRpcRecommendContactAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRecommendContactAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRecommendContactAsk ToPB() const
	{
		ContactRpcRecommendContactAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRecommendContactAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRecommendContactAsk& v)
	{

	}


};
//推荐联系人回应封装类
class ContactRpcRecommendContactReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRecommendContactReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcRecommendContactReplyWraper(const ContactRpcRecommendContactReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRecommendContactReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRecommendContactReply ToPB() const
	{
		ContactRpcRecommendContactReply v;
		v.set_result( m_Result );
		v.mutable_contact()->Reserve(m_Contact.size());
		for (int i=0; i<(int)m_Contact.size(); i++)
		{
			*v.add_contact() = m_Contact[i].ToPB();
		}
		v.mutable_applyedlistid()->Reserve(m_ApplyedListId.size());
		for (int i=0; i<(int)m_ApplyedListId.size(); i++)
		{
			v.add_applyedlistid(m_ApplyedListId[i]);
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRecommendContactReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRecommendContactReply& v)
	{
		m_Result = v.result();
		m_Contact.clear();
		m_Contact.reserve(v.contact_size());
		for( int i=0; i<v.contact_size(); i++)
			m_Contact.push_back(v.contact(i));
		m_ApplyedListId.clear();
		m_ApplyedListId.reserve(v.applyedlistid_size());
		for( int i=0; i<v.applyedlistid_size(); i++)
			m_ApplyedListId.push_back(v.applyedlistid(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//推荐的人
	vector<ContactDataWraper> m_Contact;
public:
	int SizeContact()
	{
		return m_Contact.size();
	}
	const vector<ContactDataWraper>& GetContact() const
	{
		return m_Contact;
	}
	ContactDataWraper GetContact(int Index) const
	{
		if(Index<0 || Index>=(int)m_Contact.size())
		{
			assert(false);
			return ContactDataWraper();
		}
		return m_Contact[Index];
	}
	void SetContact( const vector<ContactDataWraper>& v )
	{
		m_Contact=v;
	}
	void ClearContact( )
	{
		m_Contact.clear();
	}
	void SetContact( int Index, const ContactDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Contact.size())
		{
			assert(false);
			return;
		}
		m_Contact[Index] = v;
	}
	void AddContact( const ContactDataWraper& v )
	{
		m_Contact.push_back(v);
	}
private:
	//已经申请过的人的id
	vector<uint64_t> m_ApplyedListId;
public:
	int SizeApplyedListId()
	{
		return m_ApplyedListId.size();
	}
	const vector<uint64_t>& GetApplyedListId() const
	{
		return m_ApplyedListId;
	}
	uint64_t GetApplyedListId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyedListId.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_ApplyedListId[Index];
	}
	void SetApplyedListId( const vector<uint64_t>& v )
	{
		m_ApplyedListId=v;
	}
	void ClearApplyedListId( )
	{
		m_ApplyedListId.clear();
	}
	void SetApplyedListId( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_ApplyedListId.size())
		{
			assert(false);
			return;
		}
		m_ApplyedListId[Index] = v;
	}
	void AddApplyedListId( uint64_t v = 0 )
	{
		m_ApplyedListId.push_back(v);
	}

};
//被删除好友通知封装类
class ContactRpcBeCancelRelationShipNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcBeCancelRelationShipNotifyWraper()
	{
		
		m_DeleteRoleId = 0;

	}
	//赋值构造函数
	ContactRpcBeCancelRelationShipNotifyWraper(const ContactRpcBeCancelRelationShipNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcBeCancelRelationShipNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcBeCancelRelationShipNotify ToPB() const
	{
		ContactRpcBeCancelRelationShipNotify v;
		v.set_deleteroleid( m_DeleteRoleId );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcBeCancelRelationShipNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcBeCancelRelationShipNotify& v)
	{
		m_DeleteRoleId = v.deleteroleid();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));

	}

private:
	//删除的数据
	uint64_t m_DeleteRoleId;
public:
	void SetDeleteRoleId( uint64_t v)
	{
		m_DeleteRoleId=v;
	}
	uint64_t GetDeleteRoleId()
	{
		return m_DeleteRoleId;
	}
	uint64_t GetDeleteRoleId() const
	{
		return m_DeleteRoleId;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}

};
//被加入黑名单通知封装类
class ContactRpcBeAddBlackListNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcBeAddBlackListNotifyWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcBeAddBlackListNotifyWraper(const ContactRpcBeAddBlackListNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcBeAddBlackListNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcBeAddBlackListNotify ToPB() const
	{
		ContactRpcBeAddBlackListNotify v;
		v.set_roleid( m_RoleId );
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcBeAddBlackListNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcBeAddBlackListNotify& v)
	{
		m_RoleId = v.roleid();
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));

	}

private:
	//删除的数据
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//改变的分组
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}

};
//同意申请加为好友请求封装类
class ContactRpcAgreeApplicationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAgreeApplicationAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	ContactRpcAgreeApplicationAskWraper(const ContactRpcAgreeApplicationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAgreeApplicationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAgreeApplicationAsk ToPB() const
	{
		ContactRpcAgreeApplicationAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAgreeApplicationAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAgreeApplicationAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//玩家ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//同意申请加为好友回应封装类
class ContactRpcAgreeApplicationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAgreeApplicationReplyWraper()
	{
		
		m_Result = -1;
		m_NewFriendData = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcAgreeApplicationReplyWraper(const ContactRpcAgreeApplicationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAgreeApplicationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAgreeApplicationReply ToPB() const
	{
		ContactRpcAgreeApplicationReply v;
		v.set_result( m_Result );
		*v.mutable_newfrienddata()= m_NewFriendData.ToPB();
		v.mutable_myfriendgroup()->Reserve(m_MyFriendGroup.size());
		for (int i=0; i<(int)m_MyFriendGroup.size(); i++)
		{
			*v.add_myfriendgroup() = m_MyFriendGroup[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAgreeApplicationReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAgreeApplicationReply& v)
	{
		m_Result = v.result();
		m_NewFriendData = v.newfrienddata();
		m_MyFriendGroup.clear();
		m_MyFriendGroup.reserve(v.myfriendgroup_size());
		for( int i=0; i<v.myfriendgroup_size(); i++)
			m_MyFriendGroup.push_back(v.myfriendgroup(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//新玩家数据
	ContactDataWraper m_NewFriendData;
public:
	void SetNewFriendData( const ContactDataWraper& v)
	{
		m_NewFriendData=v;
	}
	ContactDataWraper GetNewFriendData()
	{
		return m_NewFriendData;
	}
	ContactDataWraper GetNewFriendData() const
	{
		return m_NewFriendData;
	}
private:
	//移动来源组
	vector<ContactGroupWraper> m_MyFriendGroup;
public:
	int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.size();
	}
	const vector<ContactGroupWraper>& GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_MyFriendGroup[Index];
	}
	void SetMyFriendGroup( const vector<ContactGroupWraper>& v )
	{
		m_MyFriendGroup=v;
	}
	void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.clear();
	}
	void SetMyFriendGroup( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return;
		}
		m_MyFriendGroup[Index] = v;
	}
	void AddMyFriendGroup( const ContactGroupWraper& v )
	{
		m_MyFriendGroup.push_back(v);
	}

};
//重命名分组请求封装类
class ContactRpcRenameGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRenameGroupAskWraper()
	{
		
		m_Name = "";
		m_GroupId = -1;

	}
	//赋值构造函数
	ContactRpcRenameGroupAskWraper(const ContactRpcRenameGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRenameGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRenameGroupAsk ToPB() const
	{
		ContactRpcRenameGroupAsk v;
		v.set_name( m_Name );
		v.set_groupid( m_GroupId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRenameGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRenameGroupAsk& v)
	{
		m_Name = v.name();
		m_GroupId = v.groupid();

	}

private:
	//设置名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//重命名分组
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}

};
//重命名分组回应封装类
class ContactRpcRenameGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcRenameGroupReplyWraper()
	{
		
		m_Result = -1;
		m_DefineGroup = ContactGroupWraper();

	}
	//赋值构造函数
	ContactRpcRenameGroupReplyWraper(const ContactRpcRenameGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcRenameGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcRenameGroupReply ToPB() const
	{
		ContactRpcRenameGroupReply v;
		v.set_result( m_Result );
		*v.mutable_definegroup()= m_DefineGroup.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcRenameGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcRenameGroupReply& v)
	{
		m_Result = v.result();
		m_DefineGroup = v.definegroup();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//重命名的分组
	ContactGroupWraper m_DefineGroup;
public:
	void SetDefineGroup( const ContactGroupWraper& v)
	{
		m_DefineGroup=v;
	}
	ContactGroupWraper GetDefineGroup()
	{
		return m_DefineGroup;
	}
	ContactGroupWraper GetDefineGroup() const
	{
		return m_DefineGroup;
	}

};
//设置分组回应封装类
class ContactRpcSetFriendGroupReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSetFriendGroupReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ContactRpcSetFriendGroupReplyWraper(const ContactRpcSetFriendGroupReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSetFriendGroupReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSetFriendGroupReply ToPB() const
	{
		ContactRpcSetFriendGroupReply v;
		v.set_result( m_Result );
		v.mutable_friendgroups()->Reserve(m_FriendGroups.size());
		for (int i=0; i<(int)m_FriendGroups.size(); i++)
		{
			*v.add_friendgroups() = m_FriendGroups[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSetFriendGroupReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSetFriendGroupReply& v)
	{
		m_Result = v.result();
		m_FriendGroups.clear();
		m_FriendGroups.reserve(v.friendgroups_size());
		for( int i=0; i<v.friendgroups_size(); i++)
			m_FriendGroups.push_back(v.friendgroups(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//分组信息
	vector<ContactGroupWraper> m_FriendGroups;
public:
	int SizeFriendGroups()
	{
		return m_FriendGroups.size();
	}
	const vector<ContactGroupWraper>& GetFriendGroups() const
	{
		return m_FriendGroups;
	}
	ContactGroupWraper GetFriendGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_FriendGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_FriendGroups[Index];
	}
	void SetFriendGroups( const vector<ContactGroupWraper>& v )
	{
		m_FriendGroups=v;
	}
	void ClearFriendGroups( )
	{
		m_FriendGroups.clear();
	}
	void SetFriendGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_FriendGroups.size())
		{
			assert(false);
			return;
		}
		m_FriendGroups[Index] = v;
	}
	void AddFriendGroups( const ContactGroupWraper& v )
	{
		m_FriendGroups.push_back(v);
	}

};
//新联系人通知,不是朋友封装类
class ContactRpcNewFriendNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcNewFriendNotifyWraper()
	{
		
		m_NewFriendData = ContactDataWraper();
		m_MyFriendGroup = ContactGroupWraper();

	}
	//赋值构造函数
	ContactRpcNewFriendNotifyWraper(const ContactRpcNewFriendNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcNewFriendNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcNewFriendNotify ToPB() const
	{
		ContactRpcNewFriendNotify v;
		*v.mutable_newfrienddata()= m_NewFriendData.ToPB();
		*v.mutable_myfriendgroup()= m_MyFriendGroup.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcNewFriendNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcNewFriendNotify& v)
	{
		m_NewFriendData = v.newfrienddata();
		m_MyFriendGroup = v.myfriendgroup();

	}

private:
	//新的联系人数据
	ContactDataWraper m_NewFriendData;
public:
	void SetNewFriendData( const ContactDataWraper& v)
	{
		m_NewFriendData=v;
	}
	ContactDataWraper GetNewFriendData()
	{
		return m_NewFriendData;
	}
	ContactDataWraper GetNewFriendData() const
	{
		return m_NewFriendData;
	}
private:
	//新的联系人改变的组
	ContactGroupWraper m_MyFriendGroup;
public:
	void SetMyFriendGroup( const ContactGroupWraper& v)
	{
		m_MyFriendGroup=v;
	}
	ContactGroupWraper GetMyFriendGroup()
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}

};
//同意申请通知通知封装类
class ContactRpcAgreeApplicationNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcAgreeApplicationNotifyNotifyWraper()
	{
		
		m_NewFriendData = ContactDataWraper();

	}
	//赋值构造函数
	ContactRpcAgreeApplicationNotifyNotifyWraper(const ContactRpcAgreeApplicationNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcAgreeApplicationNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcAgreeApplicationNotifyNotify ToPB() const
	{
		ContactRpcAgreeApplicationNotifyNotify v;
		v.mutable_myfriendgroup()->Reserve(m_MyFriendGroup.size());
		for (int i=0; i<(int)m_MyFriendGroup.size(); i++)
		{
			*v.add_myfriendgroup() = m_MyFriendGroup[i].ToPB();
		}
		*v.mutable_newfrienddata()= m_NewFriendData.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcAgreeApplicationNotifyNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcAgreeApplicationNotifyNotify& v)
	{
		m_MyFriendGroup.clear();
		m_MyFriendGroup.reserve(v.myfriendgroup_size());
		for( int i=0; i<v.myfriendgroup_size(); i++)
			m_MyFriendGroup.push_back(v.myfriendgroup(i));
		m_NewFriendData = v.newfrienddata();

	}

private:
	//分组信息
	vector<ContactGroupWraper> m_MyFriendGroup;
public:
	int SizeMyFriendGroup()
	{
		return m_MyFriendGroup.size();
	}
	const vector<ContactGroupWraper>& GetMyFriendGroup() const
	{
		return m_MyFriendGroup;
	}
	ContactGroupWraper GetMyFriendGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_MyFriendGroup[Index];
	}
	void SetMyFriendGroup( const vector<ContactGroupWraper>& v )
	{
		m_MyFriendGroup=v;
	}
	void ClearMyFriendGroup( )
	{
		m_MyFriendGroup.clear();
	}
	void SetMyFriendGroup( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_MyFriendGroup.size())
		{
			assert(false);
			return;
		}
		m_MyFriendGroup[Index] = v;
	}
	void AddMyFriendGroup( const ContactGroupWraper& v )
	{
		m_MyFriendGroup.push_back(v);
	}
private:
	//新玩家数据
	ContactDataWraper m_NewFriendData;
public:
	void SetNewFriendData( const ContactDataWraper& v)
	{
		m_NewFriendData=v;
	}
	ContactDataWraper GetNewFriendData()
	{
		return m_NewFriendData;
	}
	ContactDataWraper GetNewFriendData() const
	{
		return m_NewFriendData;
	}

};
//设置分组请求封装类
class ContactRpcSetFriendGroupAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ContactRpcSetFriendGroupAskWraper()
	{
		
		m_GroupId = -1;
		m_RoleIds = -1;
		m_GroupName = "";

	}
	//赋值构造函数
	ContactRpcSetFriendGroupAskWraper(const ContactRpcSetFriendGroupAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactRpcSetFriendGroupAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactRpcSetFriendGroupAsk ToPB() const
	{
		ContactRpcSetFriendGroupAsk v;
		v.set_groupid( m_GroupId );
		v.set_roleids( m_RoleIds );
		v.set_groupname( m_GroupName );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		ContactRpcSetFriendGroupAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ContactRpcSetFriendGroupAsk& v)
	{
		m_GroupId = v.groupid();
		m_RoleIds = v.roleids();
		m_GroupName = v.groupname();

	}

private:
	//分组ID
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}
private:
	//好友id
	INT32 m_RoleIds;
public:
	void SetRoleIds( INT32 v)
	{
		m_RoleIds=v;
	}
	INT32 GetRoleIds()
	{
		return m_RoleIds;
	}
	INT32 GetRoleIds() const
	{
		return m_RoleIds;
	}
private:
	//分组名字
	string m_GroupName;
public:
	void SetGroupName( const string& v)
	{
		m_GroupName=v;
	}
	string GetGroupName()
	{
		return m_GroupName;
	}
	string GetGroupName() const
	{
		return m_GroupName;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ContactRpcAgreeApplicationNotifyNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_AGREEAPPLICATIONNOTIFY_NOTIFY};};
template<> struct MessageIdT<ContactRpcNewFriendNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_NEWFRIEND_NOTIFY};};
template<> struct MessageIdT<ContactRpcApplyListNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_APPLYLIST_NOTIFY};};
template<> struct MessageIdT<ContactRpcBeRejectApplyNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_BEREJECTAPPLY_NOTIFY};};
template<> struct MessageIdT<ContactRpcBeCancelRelationShipNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_BECANCELRELATIONSHIP_NOTIFY};};
template<> struct MessageIdT<ContactRpcBeAddBlackListNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_BEADDBLACKLIST_NOTIFY};};
template<> struct MessageIdT<ContactRpcRoleDataUpdateNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_ROLEDATAUPDATE_NOTIFY};};
template<> struct MessageIdT<ContactRpcContactLoginNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_CONTACTLOGIN_NOTIFY};};
template<> struct MessageIdT<ContactRpcContactLogoutNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_CONTACTLOGOUT_NOTIFY};};
template<> struct MessageIdT<ContactRpcDeleteRoleDataNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_DELETEROLEDATA_NOTIFY};};
template<> struct MessageIdT<ContactRpcUnAcquireGiftPointNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_UNACQUIREGIFTPOINT_NOTIFY};};
template<> struct MessageIdT<ContactRpcAddRoleDataNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_ADDROLEDATA_NOTIFY};};
template<> struct MessageIdT<ContactRpcSetGiftPointNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_SETGIFTPOINT_NOTIFY};};
template<> struct MessageIdT<ContactRpcContactsGroupsNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_CONTACTSGROUPS_NOTIFY};};
template<> struct MessageIdT<ContactRpcNewChatMsgNotifyWraper>{ enum{ID=RPC_CODE_CONTACT_NEWCHATMSG_NOTIFY};};


#endif
