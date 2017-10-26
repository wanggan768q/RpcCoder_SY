/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperLogin.h
* Author:       郭晓波
* Description:  登录模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_LOGIN_H
#define __RPC_WRAPER_LOGIN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "LoginRpc.pb.h"



//登录模块类的枚举定义
enum ConstLoginE
{
	MODULE_ID_LOGIN                              = 2,	//登录模块模块ID
	RPC_CODE_LOGIN_CONNECT_REQUEST               = 251,	//登录模块-->连接验证-->请求
	RPC_CODE_LOGIN_LOGIN_REQUEST                 = 252,	//登录模块-->登录-->请求


};


//登录请求封装类
class LoginRpcLoginAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginAskWraper()
	{
		
		m_Username = "";
		m_Passwd = "";

	}
	//赋值构造函数
	LoginRpcLoginAskWraper(const LoginRpcLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginAsk ToPB() const
	{
		LoginRpcLoginAsk v;
		v.set_username( m_Username );
		v.set_passwd( m_Passwd );

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
		LoginRpcLoginAsk pb;
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
	void Init(const LoginRpcLoginAsk& v)
	{
		m_Username = v.username();
		m_Passwd = v.passwd();

	}

private:
	//用户名
	string m_Username;
public:
	void SetUsername( const string& v)
	{
		m_Username=v;
	}
	string GetUsername()
	{
		return m_Username;
	}
	string GetUsername() const
	{
		return m_Username;
	}
private:
	//密码
	string m_Passwd;
public:
	void SetPasswd( const string& v)
	{
		m_Passwd=v;
	}
	string GetPasswd()
	{
		return m_Passwd;
	}
	string GetPasswd() const
	{
		return m_Passwd;
	}

};
//登录回应封装类
class LoginRpcLoginReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = -1;

	}
	//赋值构造函数
	LoginRpcLoginReplyWraper(const LoginRpcLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginReply ToPB() const
	{
		LoginRpcLoginReply v;
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
		LoginRpcLoginReply pb;
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
	void Init(const LoginRpcLoginReply& v)
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
	//用户ID
	INT64 m_RoleId;
public:
	void SetRoleId( INT64 v)
	{
		m_RoleId=v;
	}
	INT64 GetRoleId()
	{
		return m_RoleId;
	}
	INT64 GetRoleId() const
	{
		return m_RoleId;
	}

};
//连接验证请求封装类
class LoginRpcConnectAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcConnectAskWraper()
	{
		
		m_Type = -1;

	}
	//赋值构造函数
	LoginRpcConnectAskWraper(const LoginRpcConnectAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcConnectAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcConnectAsk ToPB() const
	{
		LoginRpcConnectAsk v;
		v.set_type( m_Type );

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
		LoginRpcConnectAsk pb;
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
	void Init(const LoginRpcConnectAsk& v)
	{
		m_Type = v.type();

	}

private:
	//连接类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//连接验证回应封装类
class LoginRpcConnectReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcConnectReplyWraper()
	{
		
		m_Result = -9999;
		m_Type = -1;

	}
	//赋值构造函数
	LoginRpcConnectReplyWraper(const LoginRpcConnectReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcConnectReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcConnectReply ToPB() const
	{
		LoginRpcConnectReply v;
		v.set_result( m_Result );
		v.set_type( m_Type );

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
		LoginRpcConnectReply pb;
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
	void Init(const LoginRpcConnectReply& v)
	{
		m_Result = v.result();
		m_Type = v.type();

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
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};

template<typename T> struct MessageIdT;


#endif
