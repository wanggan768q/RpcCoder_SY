/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperVechicle.h
* Author:       甘业清
* Description:  载具（变身）RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_VECHICLE_H
#define __RPC_WRAPER_VECHICLE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "VechicleRpc.pb.h"



//载具（变身）类的枚举定义
enum ConstVechicleE
{
	MODULE_ID_VECHICLE                           = 41,	//载具（变身）模块ID
	RPC_CODE_VECHICLE_QUITVECHILE_REQUEST        = 4151,	//载具（变身）-->退出载具-->请求


};


//退出载具回应封装类
class VechicleRpcQuitVechileReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	VechicleRpcQuitVechileReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	VechicleRpcQuitVechileReplyWraper(const VechicleRpcQuitVechileReply& v){ Init(v); }
	//等号重载函数
	void operator = (const VechicleRpcQuitVechileReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	VechicleRpcQuitVechileReply ToPB() const
	{
		VechicleRpcQuitVechileReply v;
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
		VechicleRpcQuitVechileReply pb;
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
	void Init(const VechicleRpcQuitVechileReply& v)
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
//退出载具请求封装类
class VechicleRpcQuitVechileAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	VechicleRpcQuitVechileAskWraper()
	{
		

	}
	//赋值构造函数
	VechicleRpcQuitVechileAskWraper(const VechicleRpcQuitVechileAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const VechicleRpcQuitVechileAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	VechicleRpcQuitVechileAsk ToPB() const
	{
		VechicleRpcQuitVechileAsk v;

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
		VechicleRpcQuitVechileAsk pb;
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
	void Init(const VechicleRpcQuitVechileAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;


#endif
