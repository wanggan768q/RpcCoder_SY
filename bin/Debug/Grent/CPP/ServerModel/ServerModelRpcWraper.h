/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperServerModel.h
* Author:       郭晓波
* Description:  服务器内部模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SERVERMODEL_H
#define __RPC_WRAPER_SERVERMODEL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ServerModelRpc.pb.h"



//服务器内部模块类的枚举定义
enum ConstServerModelE
{
	MODULE_ID_SERVERMODEL                        = 3,	//服务器内部模块模块ID
	RPC_CODE_SERVERMODEL_LOGIN_REQUEST           = 351,	//服务器内部模块-->服务器使用登录-->请求


};


//服务器使用登录回应封装类
class ServerModelRpcLoginReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ServerModelRpcLoginReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ServerModelRpcLoginReplyWraper(const ServerModelRpcLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ServerModelRpcLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ServerModelRpcLoginReply ToPB() const
	{
		ServerModelRpcLoginReply v;
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
		ServerModelRpcLoginReply pb;
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
	void Init(const ServerModelRpcLoginReply& v)
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
//服务器使用登录请求封装类
class ServerModelRpcLoginAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ServerModelRpcLoginAskWraper()
	{
		
		m_Result = -1;
		m_Type = -1;
		m_TestString = "";

	}
	//赋值构造函数
	ServerModelRpcLoginAskWraper(const ServerModelRpcLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ServerModelRpcLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ServerModelRpcLoginAsk ToPB() const
	{
		ServerModelRpcLoginAsk v;
		v.set_result( m_Result );
		v.set_type( m_Type );
		v.set_teststring( m_TestString );

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
		ServerModelRpcLoginAsk pb;
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
	void Init(const ServerModelRpcLoginAsk& v)
	{
		m_Result = v.result();
		m_Type = v.type();
		m_TestString = v.teststring();

	}

private:
	//1111
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
private:
	//TestString
	string m_TestString;
public:
	void SetTestString( const string& v)
	{
		m_TestString=v;
	}
	string GetTestString()
	{
		return m_TestString;
	}
	string GetTestString() const
	{
		return m_TestString;
	}

};

template<typename T> struct MessageIdT;


#endif
