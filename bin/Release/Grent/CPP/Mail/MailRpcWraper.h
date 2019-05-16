/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMail.h
* Author:       甘业清
* Description:  邮件RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MAIL_H
#define __RPC_WRAPER_MAIL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MailRpc.pb.h"



//邮件类的枚举定义
enum ConstMailE
{
	MODULE_ID_MAIL                               = 30,	//邮件模块ID
	RPC_CODE_MAIL_INITMAIL_REQUEST               = 3051,	//邮件-->初始化邮件信息-->请求
	RPC_CODE_MAIL_READMAIL_REQUEST               = 3052,	//邮件-->已读邮件-->请求
	RPC_CODE_MAIL_DELETEMAIL_REQUEST             = 3053,	//邮件-->删除邮件-->请求
	RPC_CODE_MAIL_GETMAIL_REQUEST                = 3054,	//邮件-->领取邮件-->请求
	RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY            = 3055,	//邮件-->同步邮件信息-->通知


};


//领取邮件请求封装类
class MailRpcGetMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcGetMailAskWraper()
	{
		
		m_Mail_type = -1;
		m_Mail_id = -1;

	}
	//赋值构造函数
	MailRpcGetMailAskWraper(const MailRpcGetMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcGetMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcGetMailAsk ToPB() const
	{
		MailRpcGetMailAsk v;
		v.set_mail_type( m_Mail_type );
		v.set_mail_id( m_Mail_id );

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
		MailRpcGetMailAsk pb;
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
	void Init(const MailRpcGetMailAsk& v)
	{
		m_Mail_type = v.mail_type();
		m_Mail_id = v.mail_id();

	}

private:
	//邮件类型
	INT32 m_Mail_type;
public:
	void SetMail_type( INT32 v)
	{
		m_Mail_type=v;
	}
	INT32 GetMail_type()
	{
		return m_Mail_type;
	}
	INT32 GetMail_type() const
	{
		return m_Mail_type;
	}
private:
	//主键id
	INT32 m_Mail_id;
public:
	void SetMail_id( INT32 v)
	{
		m_Mail_id=v;
	}
	INT32 GetMail_id()
	{
		return m_Mail_id;
	}
	INT32 GetMail_id() const
	{
		return m_Mail_id;
	}

};
//删除邮件回应封装类
class MailRpcDeleteMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcDeleteMailReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MailRpcDeleteMailReplyWraper(const MailRpcDeleteMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcDeleteMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcDeleteMailReply ToPB() const
	{
		MailRpcDeleteMailReply v;
		v.set_result( m_Result );
		v.mutable_system_mail_ids()->Reserve(m_System_mail_ids.size());
		for (int i=0; i<(int)m_System_mail_ids.size(); i++)
		{
			v.add_system_mail_ids(m_System_mail_ids[i]);
		}
		v.mutable_private_mail_ids()->Reserve(m_Private_mail_ids.size());
		for (int i=0; i<(int)m_Private_mail_ids.size(); i++)
		{
			v.add_private_mail_ids(m_Private_mail_ids[i]);
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
		MailRpcDeleteMailReply pb;
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
	void Init(const MailRpcDeleteMailReply& v)
	{
		m_Result = v.result();
		m_System_mail_ids.clear();
		m_System_mail_ids.reserve(v.system_mail_ids_size());
		for( int i=0; i<v.system_mail_ids_size(); i++)
			m_System_mail_ids.push_back(v.system_mail_ids(i));
		m_Private_mail_ids.clear();
		m_Private_mail_ids.reserve(v.private_mail_ids_size());
		for( int i=0; i<v.private_mail_ids_size(); i++)
			m_Private_mail_ids.push_back(v.private_mail_ids(i));

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
	//已读系统邮件
	vector<INT32> m_System_mail_ids;
public:
	int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.size();
	}
	const vector<INT32>& GetSystem_mail_ids() const
	{
		return m_System_mail_ids;
	}
	INT32 GetSystem_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_System_mail_ids[Index];
	}
	void SetSystem_mail_ids( const vector<INT32>& v )
	{
		m_System_mail_ids=v;
	}
	void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.clear();
	}
	void SetSystem_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_System_mail_ids[Index] = v;
	}
	void AddSystem_mail_ids( INT32 v = -1 )
	{
		m_System_mail_ids.push_back(v);
	}
private:
	//已读私有邮件
	vector<INT32> m_Private_mail_ids;
public:
	int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.size();
	}
	const vector<INT32>& GetPrivate_mail_ids() const
	{
		return m_Private_mail_ids;
	}
	INT32 GetPrivate_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_Private_mail_ids[Index];
	}
	void SetPrivate_mail_ids( const vector<INT32>& v )
	{
		m_Private_mail_ids=v;
	}
	void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.clear();
	}
	void SetPrivate_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_Private_mail_ids[Index] = v;
	}
	void AddPrivate_mail_ids( INT32 v = -1 )
	{
		m_Private_mail_ids.push_back(v);
	}

};
//同步邮件信息通知封装类
class MailRpcSyncMailInfoNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcSyncMailInfoNotifyWraper()
	{
		

	}
	//赋值构造函数
	MailRpcSyncMailInfoNotifyWraper(const MailRpcSyncMailInfoNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcSyncMailInfoNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcSyncMailInfoNotify ToPB() const
	{
		MailRpcSyncMailInfoNotify v;
		v.mutable_infolist()->Reserve(m_InfoList.size());
		for (int i=0; i<(int)m_InfoList.size(); i++)
		{
			*v.add_infolist() = m_InfoList[i].ToPB();
		}
		v.mutable_guidlist()->Reserve(m_GuidList.size());
		for (int i=0; i<(int)m_GuidList.size(); i++)
		{
			v.add_guidlist(m_GuidList[i]);
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
		MailRpcSyncMailInfoNotify pb;
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
	void Init(const MailRpcSyncMailInfoNotify& v)
	{
		m_InfoList.clear();
		m_InfoList.reserve(v.infolist_size());
		for( int i=0; i<v.infolist_size(); i++)
			m_InfoList.push_back(v.infolist(i));
		m_GuidList.clear();
		m_GuidList.reserve(v.guidlist_size());
		for( int i=0; i<v.guidlist_size(); i++)
			m_GuidList.push_back(v.guidlist(i));

	}

private:
	//更新的邮件信息列表
	vector<MailInfoWraper> m_InfoList;
public:
	int SizeInfoList()
	{
		return m_InfoList.size();
	}
	const vector<MailInfoWraper>& GetInfoList() const
	{
		return m_InfoList;
	}
	MailInfoWraper GetInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_InfoList.size())
		{
			assert(false);
			return MailInfoWraper();
		}
		return m_InfoList[Index];
	}
	void SetInfoList( const vector<MailInfoWraper>& v )
	{
		m_InfoList=v;
	}
	void ClearInfoList( )
	{
		m_InfoList.clear();
	}
	void SetInfoList( int Index, const MailInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_InfoList.size())
		{
			assert(false);
			return;
		}
		m_InfoList[Index] = v;
	}
	void AddInfoList( const MailInfoWraper& v )
	{
		m_InfoList.push_back(v);
	}
private:
	//删除的主键id列表
	vector<uint64_t> m_GuidList;
public:
	int SizeGuidList()
	{
		return m_GuidList.size();
	}
	const vector<uint64_t>& GetGuidList() const
	{
		return m_GuidList;
	}
	uint64_t GetGuidList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuidList.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_GuidList[Index];
	}
	void SetGuidList( const vector<uint64_t>& v )
	{
		m_GuidList=v;
	}
	void ClearGuidList( )
	{
		m_GuidList.clear();
	}
	void SetGuidList( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_GuidList.size())
		{
			assert(false);
			return;
		}
		m_GuidList[Index] = v;
	}
	void AddGuidList( uint64_t v = 0 )
	{
		m_GuidList.push_back(v);
	}

};
//领取邮件回应封装类
class MailRpcGetMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcGetMailReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MailRpcGetMailReplyWraper(const MailRpcGetMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcGetMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcGetMailReply ToPB() const
	{
		MailRpcGetMailReply v;
		v.set_result( m_Result );
		v.mutable_system_mail_ids()->Reserve(m_System_mail_ids.size());
		for (int i=0; i<(int)m_System_mail_ids.size(); i++)
		{
			v.add_system_mail_ids(m_System_mail_ids[i]);
		}
		v.mutable_private_mail_ids()->Reserve(m_Private_mail_ids.size());
		for (int i=0; i<(int)m_Private_mail_ids.size(); i++)
		{
			v.add_private_mail_ids(m_Private_mail_ids[i]);
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
		MailRpcGetMailReply pb;
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
	void Init(const MailRpcGetMailReply& v)
	{
		m_Result = v.result();
		m_System_mail_ids.clear();
		m_System_mail_ids.reserve(v.system_mail_ids_size());
		for( int i=0; i<v.system_mail_ids_size(); i++)
			m_System_mail_ids.push_back(v.system_mail_ids(i));
		m_Private_mail_ids.clear();
		m_Private_mail_ids.reserve(v.private_mail_ids_size());
		for( int i=0; i<v.private_mail_ids_size(); i++)
			m_Private_mail_ids.push_back(v.private_mail_ids(i));

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
	//已读系统邮件
	vector<INT32> m_System_mail_ids;
public:
	int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.size();
	}
	const vector<INT32>& GetSystem_mail_ids() const
	{
		return m_System_mail_ids;
	}
	INT32 GetSystem_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_System_mail_ids[Index];
	}
	void SetSystem_mail_ids( const vector<INT32>& v )
	{
		m_System_mail_ids=v;
	}
	void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.clear();
	}
	void SetSystem_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_System_mail_ids[Index] = v;
	}
	void AddSystem_mail_ids( INT32 v = -1 )
	{
		m_System_mail_ids.push_back(v);
	}
private:
	//已读私有邮件
	vector<INT32> m_Private_mail_ids;
public:
	int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.size();
	}
	const vector<INT32>& GetPrivate_mail_ids() const
	{
		return m_Private_mail_ids;
	}
	INT32 GetPrivate_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_Private_mail_ids[Index];
	}
	void SetPrivate_mail_ids( const vector<INT32>& v )
	{
		m_Private_mail_ids=v;
	}
	void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.clear();
	}
	void SetPrivate_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_Private_mail_ids[Index] = v;
	}
	void AddPrivate_mail_ids( INT32 v = -1 )
	{
		m_Private_mail_ids.push_back(v);
	}

};
//删除邮件请求封装类
class MailRpcDeleteMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcDeleteMailAskWraper()
	{
		
		m_Mail_type = -1;
		m_Mail_id = -1;

	}
	//赋值构造函数
	MailRpcDeleteMailAskWraper(const MailRpcDeleteMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcDeleteMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcDeleteMailAsk ToPB() const
	{
		MailRpcDeleteMailAsk v;
		v.set_mail_type( m_Mail_type );
		v.set_mail_id( m_Mail_id );

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
		MailRpcDeleteMailAsk pb;
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
	void Init(const MailRpcDeleteMailAsk& v)
	{
		m_Mail_type = v.mail_type();
		m_Mail_id = v.mail_id();

	}

private:
	//邮件类型
	INT32 m_Mail_type;
public:
	void SetMail_type( INT32 v)
	{
		m_Mail_type=v;
	}
	INT32 GetMail_type()
	{
		return m_Mail_type;
	}
	INT32 GetMail_type() const
	{
		return m_Mail_type;
	}
private:
	//主键id
	INT32 m_Mail_id;
public:
	void SetMail_id( INT32 v)
	{
		m_Mail_id=v;
	}
	INT32 GetMail_id()
	{
		return m_Mail_id;
	}
	INT32 GetMail_id() const
	{
		return m_Mail_id;
	}

};
//初始化邮件信息回应封装类
class MailRpcInitMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcInitMailReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MailRpcInitMailReplyWraper(const MailRpcInitMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcInitMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcInitMailReply ToPB() const
	{
		MailRpcInitMailReply v;
		v.set_result( m_Result );
		v.mutable_infolist()->Reserve(m_InfoList.size());
		for (int i=0; i<(int)m_InfoList.size(); i++)
		{
			*v.add_infolist() = m_InfoList[i].ToPB();
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
		MailRpcInitMailReply pb;
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
	void Init(const MailRpcInitMailReply& v)
	{
		m_Result = v.result();
		m_InfoList.clear();
		m_InfoList.reserve(v.infolist_size());
		for( int i=0; i<v.infolist_size(); i++)
			m_InfoList.push_back(v.infolist(i));

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
	//邮件信息列表
	vector<MailInfoWraper> m_InfoList;
public:
	int SizeInfoList()
	{
		return m_InfoList.size();
	}
	const vector<MailInfoWraper>& GetInfoList() const
	{
		return m_InfoList;
	}
	MailInfoWraper GetInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_InfoList.size())
		{
			assert(false);
			return MailInfoWraper();
		}
		return m_InfoList[Index];
	}
	void SetInfoList( const vector<MailInfoWraper>& v )
	{
		m_InfoList=v;
	}
	void ClearInfoList( )
	{
		m_InfoList.clear();
	}
	void SetInfoList( int Index, const MailInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_InfoList.size())
		{
			assert(false);
			return;
		}
		m_InfoList[Index] = v;
	}
	void AddInfoList( const MailInfoWraper& v )
	{
		m_InfoList.push_back(v);
	}

};
//初始化邮件信息请求封装类
class MailRpcInitMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcInitMailAskWraper()
	{
		

	}
	//赋值构造函数
	MailRpcInitMailAskWraper(const MailRpcInitMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcInitMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcInitMailAsk ToPB() const
	{
		MailRpcInitMailAsk v;

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
		MailRpcInitMailAsk pb;
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
	void Init(const MailRpcInitMailAsk& v)
	{

	}


};
//已读邮件回应封装类
class MailRpcReadMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcReadMailReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MailRpcReadMailReplyWraper(const MailRpcReadMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcReadMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcReadMailReply ToPB() const
	{
		MailRpcReadMailReply v;
		v.set_result( m_Result );
		v.mutable_system_mail_ids()->Reserve(m_System_mail_ids.size());
		for (int i=0; i<(int)m_System_mail_ids.size(); i++)
		{
			v.add_system_mail_ids(m_System_mail_ids[i]);
		}
		v.mutable_private_mail_ids()->Reserve(m_Private_mail_ids.size());
		for (int i=0; i<(int)m_Private_mail_ids.size(); i++)
		{
			v.add_private_mail_ids(m_Private_mail_ids[i]);
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
		MailRpcReadMailReply pb;
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
	void Init(const MailRpcReadMailReply& v)
	{
		m_Result = v.result();
		m_System_mail_ids.clear();
		m_System_mail_ids.reserve(v.system_mail_ids_size());
		for( int i=0; i<v.system_mail_ids_size(); i++)
			m_System_mail_ids.push_back(v.system_mail_ids(i));
		m_Private_mail_ids.clear();
		m_Private_mail_ids.reserve(v.private_mail_ids_size());
		for( int i=0; i<v.private_mail_ids_size(); i++)
			m_Private_mail_ids.push_back(v.private_mail_ids(i));

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
	//已读系统邮件
	vector<INT32> m_System_mail_ids;
public:
	int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.size();
	}
	const vector<INT32>& GetSystem_mail_ids() const
	{
		return m_System_mail_ids;
	}
	INT32 GetSystem_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_System_mail_ids[Index];
	}
	void SetSystem_mail_ids( const vector<INT32>& v )
	{
		m_System_mail_ids=v;
	}
	void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.clear();
	}
	void SetSystem_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_System_mail_ids[Index] = v;
	}
	void AddSystem_mail_ids( INT32 v = -1 )
	{
		m_System_mail_ids.push_back(v);
	}
private:
	//已读私有邮件
	vector<INT32> m_Private_mail_ids;
public:
	int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.size();
	}
	const vector<INT32>& GetPrivate_mail_ids() const
	{
		return m_Private_mail_ids;
	}
	INT32 GetPrivate_mail_ids(int Index) const
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return INT32();
		}
		return m_Private_mail_ids[Index];
	}
	void SetPrivate_mail_ids( const vector<INT32>& v )
	{
		m_Private_mail_ids=v;
	}
	void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.clear();
	}
	void SetPrivate_mail_ids( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.size())
		{
			assert(false);
			return;
		}
		m_Private_mail_ids[Index] = v;
	}
	void AddPrivate_mail_ids( INT32 v = -1 )
	{
		m_Private_mail_ids.push_back(v);
	}

};
//已读邮件请求封装类
class MailRpcReadMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MailRpcReadMailAskWraper()
	{
		
		m_Mail_type = -1;
		m_Mail_id = -1;

	}
	//赋值构造函数
	MailRpcReadMailAskWraper(const MailRpcReadMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MailRpcReadMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailRpcReadMailAsk ToPB() const
	{
		MailRpcReadMailAsk v;
		v.set_mail_type( m_Mail_type );
		v.set_mail_id( m_Mail_id );

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
		MailRpcReadMailAsk pb;
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
	void Init(const MailRpcReadMailAsk& v)
	{
		m_Mail_type = v.mail_type();
		m_Mail_id = v.mail_id();

	}

private:
	//邮件类型
	INT32 m_Mail_type;
public:
	void SetMail_type( INT32 v)
	{
		m_Mail_type=v;
	}
	INT32 GetMail_type()
	{
		return m_Mail_type;
	}
	INT32 GetMail_type() const
	{
		return m_Mail_type;
	}
private:
	//主键id
	INT32 m_Mail_id;
public:
	void SetMail_id( INT32 v)
	{
		m_Mail_id=v;
	}
	INT32 GetMail_id()
	{
		return m_Mail_id;
	}
	INT32 GetMail_id() const
	{
		return m_Mail_id;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<MailRpcSyncMailInfoNotifyWraper>{ enum{ID=RPC_CODE_MAIL_SYNCMAILINFO_NOTIFY};};


#endif
