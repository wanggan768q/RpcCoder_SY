/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperGate.h
* Author:       甘业清
* Description:  网关模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_GATE_H
#define __RPC_WRAPER_GATE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "GateRpc.pb.h"



//网关模块类的枚举定义
enum ConstGateE
{
	MODULE_ID_GATE                               = 43,	//网关模块模块ID
	RPC_CODE_GATE_PING_REQUEST                   = 4351,	//网关模块-->Ping-->请求


};


//Ping回应封装类
class GateRpcPingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GateRpcPingReplyWraper()
	{
		
		m_Result = -1;
		m_Sequence = 0;

	}
	//赋值构造函数
	GateRpcPingReplyWraper(const GateRpcPingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GateRpcPingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GateRpcPingReply ToPB() const
	{
		GateRpcPingReply v;
		v.set_result( m_Result );
		v.set_sequence( m_Sequence );

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
		GateRpcPingReply pb;
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
	void Init(const GateRpcPingReply& v)
	{
		m_Result = v.result();
		m_Sequence = v.sequence();

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
	//序列
	uint64_t m_Sequence;
public:
	void SetSequence( uint64_t v)
	{
		m_Sequence=v;
	}
	uint64_t GetSequence()
	{
		return m_Sequence;
	}
	uint64_t GetSequence() const
	{
		return m_Sequence;
	}

};
//Ping请求封装类
class GateRpcPingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GateRpcPingAskWraper()
	{
		
		m_Sequence = 0;

	}
	//赋值构造函数
	GateRpcPingAskWraper(const GateRpcPingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GateRpcPingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GateRpcPingAsk ToPB() const
	{
		GateRpcPingAsk v;
		v.set_sequence( m_Sequence );

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
		GateRpcPingAsk pb;
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
	void Init(const GateRpcPingAsk& v)
	{
		m_Sequence = v.sequence();

	}

private:
	//序列
	uint64_t m_Sequence;
public:
	void SetSequence( uint64_t v)
	{
		m_Sequence=v;
	}
	uint64_t GetSequence()
	{
		return m_Sequence;
	}
	uint64_t GetSequence() const
	{
		return m_Sequence;
	}

};

template<typename T> struct MessageIdT;


#endif
