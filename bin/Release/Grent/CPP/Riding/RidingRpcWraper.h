/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperRiding.h
* Author:       甘业清
* Description:  坐骑RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_RIDING_H
#define __RPC_WRAPER_RIDING_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "RidingRpc.pb.h"



//坐骑类的枚举定义
enum ConstRidingE
{
	MODULE_ID_RIDING                             = 40,	//坐骑模块ID
	RPC_CODE_RIDING_RIDING_REQUEST               = 4051,	//坐骑-->上马-->请求
	RPC_CODE_RIDING_UNRIDING_REQUEST             = 4052,	//坐骑-->下马-->请求


};


//下马请求封装类
class RidingRpcUnRidingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	RidingRpcUnRidingAskWraper()
	{
		

	}
	//赋值构造函数
	RidingRpcUnRidingAskWraper(const RidingRpcUnRidingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const RidingRpcUnRidingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RidingRpcUnRidingAsk ToPB() const
	{
		RidingRpcUnRidingAsk v;

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
		RidingRpcUnRidingAsk pb;
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
	void Init(const RidingRpcUnRidingAsk& v)
	{

	}


};
//下马回应封装类
class RidingRpcUnRidingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RidingRpcUnRidingReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	RidingRpcUnRidingReplyWraper(const RidingRpcUnRidingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const RidingRpcUnRidingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RidingRpcUnRidingReply ToPB() const
	{
		RidingRpcUnRidingReply v;
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
		RidingRpcUnRidingReply pb;
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
	void Init(const RidingRpcUnRidingReply& v)
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
//上马请求封装类
class RidingRpcRidingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	RidingRpcRidingAskWraper()
	{
		

	}
	//赋值构造函数
	RidingRpcRidingAskWraper(const RidingRpcRidingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const RidingRpcRidingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RidingRpcRidingAsk ToPB() const
	{
		RidingRpcRidingAsk v;

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
		RidingRpcRidingAsk pb;
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
	void Init(const RidingRpcRidingAsk& v)
	{

	}


};
//上马回应封装类
class RidingRpcRidingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RidingRpcRidingReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	RidingRpcRidingReplyWraper(const RidingRpcRidingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const RidingRpcRidingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RidingRpcRidingReply ToPB() const
	{
		RidingRpcRidingReply v;
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
		RidingRpcRidingReply pb;
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
	void Init(const RidingRpcRidingReply& v)
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

template<typename T> struct MessageIdT;


#endif
