/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperEventObj.h
* Author:       甘业清
* Description:  EventObjRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EVENTOBJ_H
#define __RPC_WRAPER_EVENTOBJ_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "EventObjRpc.pb.h"



//EventObj类的枚举定义
enum ConstEventObjE
{
	MODULE_ID_EVENTOBJ                           = 16,	//EventObj模块ID
	RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST         = 1651,	//EventObj-->EventBegin-->请求
	RPC_CODE_EVENTOBJ_EVENTEND_REQUEST           = 1652,	//EventObj-->EventEnd-->请求
	RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST          = 1653,	//EventObj-->EventStop-->请求
	RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY     = 1654,	//EventObj-->交互停止通知-->通知


};


//EventStop请求封装类
class EventObjRpcEventStopAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventStopAskWraper()
	{
		
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventStopAskWraper(const EventObjRpcEventStopAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventStopAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventStopAsk ToPB() const
	{
		EventObjRpcEventStopAsk v;
		v.set_objid( m_ObjId );

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
		EventObjRpcEventStopAsk pb;
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
	void Init(const EventObjRpcEventStopAsk& v)
	{
		m_ObjId = v.objid();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//EventStop回应封装类
class EventObjRpcEventStopReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventStopReplyWraper()
	{
		
		m_Result = -1;
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventStopReplyWraper(const EventObjRpcEventStopReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventStopReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventStopReply ToPB() const
	{
		EventObjRpcEventStopReply v;
		v.set_result( m_Result );
		v.set_objid( m_ObjId );

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
		EventObjRpcEventStopReply pb;
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
	void Init(const EventObjRpcEventStopReply& v)
	{
		m_Result = v.result();
		m_ObjId = v.objid();

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
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//交互停止通知通知封装类
class EventObjRpcEventStopNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventStopNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	EventObjRpcEventStopNotifyNotifyWraper(const EventObjRpcEventStopNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventStopNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventStopNotifyNotify ToPB() const
	{
		EventObjRpcEventStopNotifyNotify v;

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
		EventObjRpcEventStopNotifyNotify pb;
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
	void Init(const EventObjRpcEventStopNotifyNotify& v)
	{

	}


};
//EventEnd回应封装类
class EventObjRpcEventEndReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventEndReplyWraper()
	{
		
		m_Result = -9999;
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventEndReplyWraper(const EventObjRpcEventEndReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventEndReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventEndReply ToPB() const
	{
		EventObjRpcEventEndReply v;
		v.set_result( m_Result );
		v.set_objid( m_ObjId );

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
		EventObjRpcEventEndReply pb;
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
	void Init(const EventObjRpcEventEndReply& v)
	{
		m_Result = v.result();
		m_ObjId = v.objid();

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
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//EventBegin请求封装类
class EventObjRpcEventBeginAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventBeginAskWraper()
	{
		
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventBeginAskWraper(const EventObjRpcEventBeginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventBeginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventBeginAsk ToPB() const
	{
		EventObjRpcEventBeginAsk v;
		v.set_objid( m_ObjId );

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
		EventObjRpcEventBeginAsk pb;
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
	void Init(const EventObjRpcEventBeginAsk& v)
	{
		m_ObjId = v.objid();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//EventBegin回应封装类
class EventObjRpcEventBeginReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventBeginReplyWraper()
	{
		
		m_Result = -9999;
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventBeginReplyWraper(const EventObjRpcEventBeginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventBeginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventBeginReply ToPB() const
	{
		EventObjRpcEventBeginReply v;
		v.set_result( m_Result );
		v.set_objid( m_ObjId );

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
		EventObjRpcEventBeginReply pb;
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
	void Init(const EventObjRpcEventBeginReply& v)
	{
		m_Result = v.result();
		m_ObjId = v.objid();

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
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};
//EventEnd请求封装类
class EventObjRpcEventEndAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventObjRpcEventEndAskWraper()
	{
		
		m_ObjId = -1;

	}
	//赋值构造函数
	EventObjRpcEventEndAskWraper(const EventObjRpcEventEndAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EventObjRpcEventEndAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventObjRpcEventEndAsk ToPB() const
	{
		EventObjRpcEventEndAsk v;
		v.set_objid( m_ObjId );

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
		EventObjRpcEventEndAsk pb;
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
	void Init(const EventObjRpcEventEndAsk& v)
	{
		m_ObjId = v.objid();

	}

private:
	//id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<EventObjRpcEventStopNotifyNotifyWraper>{ enum{ID=RPC_CODE_EVENTOBJ_EVENTSTOPNOTIFY_NOTIFY};};


#endif
