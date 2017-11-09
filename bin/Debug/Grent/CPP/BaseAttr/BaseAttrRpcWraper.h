/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperBaseAttr.h
* Author:       郭晓波
* Description:  基础数据RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BASEATTR_H
#define __RPC_WRAPER_BASEATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BaseAttrRpc.pb.h"



//基础数据类的枚举定义
enum ConstBaseAttrE
{
	MODULE_ID_BASEATTR                           = 7,	//基础数据模块ID
	RPC_CODE_BASEATTR_SYNCDATA_REQUEST           = 751,	//基础数据-->同步玩家数据-->请求


};


//同步玩家数据回应封装类
class BaseAttrRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BaseAttrRpcSyncDataReplyWraper(const BaseAttrRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcSyncDataReply ToPB() const
	{
		BaseAttrRpcSyncDataReply v;
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
		BaseAttrRpcSyncDataReply pb;
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
	void Init(const BaseAttrRpcSyncDataReply& v)
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
//同步玩家数据请求封装类
class BaseAttrRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BaseAttrRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	BaseAttrRpcSyncDataAskWraper(const BaseAttrRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BaseAttrRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BaseAttrRpcSyncDataAsk ToPB() const
	{
		BaseAttrRpcSyncDataAsk v;

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
		BaseAttrRpcSyncDataAsk pb;
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
	void Init(const BaseAttrRpcSyncDataAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;


#endif
