/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTreasureMap.h
* Author:       甘业清
* Description:  藏宝图RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TREASUREMAP_H
#define __RPC_WRAPER_TREASUREMAP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TreasureMapRpc.pb.h"



//藏宝图类的枚举定义
enum ConstTreasureMapE
{
	MODULE_ID_TREASUREMAP                        = 35,	//藏宝图模块ID
	RPC_CODE_TREASUREMAP_TREASUREMAPSYNC_REQUEST = 3551,	//藏宝图-->同步-->请求
	RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY= 3552,	//藏宝图-->变化-->通知


};


//变化通知封装类
class TreasureMapRpcTreasureMapChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureMapRpcTreasureMapChangeNotifyWraper()
	{
		
		m_TreasureMapId = -1;
		m_HighTreasureMapId = -1;

	}
	//赋值构造函数
	TreasureMapRpcTreasureMapChangeNotifyWraper(const TreasureMapRpcTreasureMapChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureMapRpcTreasureMapChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureMapRpcTreasureMapChangeNotify ToPB() const
	{
		TreasureMapRpcTreasureMapChangeNotify v;
		v.set_treasuremapid( m_TreasureMapId );
		v.set_hightreasuremapid( m_HighTreasureMapId );

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
		TreasureMapRpcTreasureMapChangeNotify pb;
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
	void Init(const TreasureMapRpcTreasureMapChangeNotify& v)
	{
		m_TreasureMapId = v.treasuremapid();
		m_HighTreasureMapId = v.hightreasuremapid();

	}

private:
	//id
	INT32 m_TreasureMapId;
public:
	void SetTreasureMapId( INT32 v)
	{
		m_TreasureMapId=v;
	}
	INT32 GetTreasureMapId()
	{
		return m_TreasureMapId;
	}
	INT32 GetTreasureMapId() const
	{
		return m_TreasureMapId;
	}
private:
	//高级藏宝图ID
	INT32 m_HighTreasureMapId;
public:
	void SetHighTreasureMapId( INT32 v)
	{
		m_HighTreasureMapId=v;
	}
	INT32 GetHighTreasureMapId()
	{
		return m_HighTreasureMapId;
	}
	INT32 GetHighTreasureMapId() const
	{
		return m_HighTreasureMapId;
	}

};
//同步回应封装类
class TreasureMapRpcTreasureMapSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureMapRpcTreasureMapSyncReplyWraper()
	{
		
		m_Result = -1;
		m_TreasureMapId = -1;
		m_HighTreasureMapId = -1;

	}
	//赋值构造函数
	TreasureMapRpcTreasureMapSyncReplyWraper(const TreasureMapRpcTreasureMapSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureMapRpcTreasureMapSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureMapRpcTreasureMapSyncReply ToPB() const
	{
		TreasureMapRpcTreasureMapSyncReply v;
		v.set_result( m_Result );
		v.set_treasuremapid( m_TreasureMapId );
		v.set_hightreasuremapid( m_HighTreasureMapId );

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
		TreasureMapRpcTreasureMapSyncReply pb;
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
	void Init(const TreasureMapRpcTreasureMapSyncReply& v)
	{
		m_Result = v.result();
		m_TreasureMapId = v.treasuremapid();
		m_HighTreasureMapId = v.hightreasuremapid();

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
	//藏宝图ID
	INT32 m_TreasureMapId;
public:
	void SetTreasureMapId( INT32 v)
	{
		m_TreasureMapId=v;
	}
	INT32 GetTreasureMapId()
	{
		return m_TreasureMapId;
	}
	INT32 GetTreasureMapId() const
	{
		return m_TreasureMapId;
	}
private:
	//高级藏宝图ID
	INT32 m_HighTreasureMapId;
public:
	void SetHighTreasureMapId( INT32 v)
	{
		m_HighTreasureMapId=v;
	}
	INT32 GetHighTreasureMapId()
	{
		return m_HighTreasureMapId;
	}
	INT32 GetHighTreasureMapId() const
	{
		return m_HighTreasureMapId;
	}

};
//同步请求封装类
class TreasureMapRpcTreasureMapSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureMapRpcTreasureMapSyncAskWraper()
	{
		

	}
	//赋值构造函数
	TreasureMapRpcTreasureMapSyncAskWraper(const TreasureMapRpcTreasureMapSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureMapRpcTreasureMapSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureMapRpcTreasureMapSyncAsk ToPB() const
	{
		TreasureMapRpcTreasureMapSyncAsk v;

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
		TreasureMapRpcTreasureMapSyncAsk pb;
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
	void Init(const TreasureMapRpcTreasureMapSyncAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TreasureMapRpcTreasureMapChangeNotifyWraper>{ enum{ID=RPC_CODE_TREASUREMAP_TREASUREMAPCHANGE_NOTIFY};};


#endif
