/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperEventNpc.h
* Author:       甘业清
* Description:  可交互的怪 RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EVENTNPC_H
#define __RPC_WRAPER_EVENTNPC_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "EventNpcRpc.pb.h"



//可交互的怪 类的枚举定义
enum ConstEventNpcE
{
	MODULE_ID_EVENTNPC                           = 37,	//可交互的怪 模块ID
	RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST         = 3751,	//可交互的怪 -->开始交互-->请求
	RPC_CODE_EVENTNPC_ENDEVENT_REQUEST           = 3752,	//可交互的怪 -->交互结束-->请求
	RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY       = 3753,	//可交互的怪 -->活动开始-->通知


};


//交互结束回应封装类
class EventNpcRpcEndEventReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventNpcRpcEndEventReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	EventNpcRpcEndEventReplyWraper(const EventNpcRpcEndEventReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EventNpcRpcEndEventReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventNpcRpcEndEventReply ToPB() const
	{
		EventNpcRpcEndEventReply v;
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
		EventNpcRpcEndEventReply pb;
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
	void Init(const EventNpcRpcEndEventReply& v)
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
//活动开始通知封装类
class EventNpcRpcActivityBeginNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventNpcRpcActivityBeginNotifyWraper()
	{
		
		m_StartTime = -1;
		m_WayPoint = -1;

	}
	//赋值构造函数
	EventNpcRpcActivityBeginNotifyWraper(const EventNpcRpcActivityBeginNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventNpcRpcActivityBeginNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventNpcRpcActivityBeginNotify ToPB() const
	{
		EventNpcRpcActivityBeginNotify v;
		v.set_starttime( m_StartTime );
		v.set_waypoint( m_WayPoint );

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
		EventNpcRpcActivityBeginNotify pb;
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
	void Init(const EventNpcRpcActivityBeginNotify& v)
	{
		m_StartTime = v.starttime();
		m_WayPoint = v.waypoint();

	}

private:
	//开始时间
	INT32 m_StartTime;
public:
	void SetStartTime( INT32 v)
	{
		m_StartTime=v;
	}
	INT32 GetStartTime()
	{
		return m_StartTime;
	}
	INT32 GetStartTime() const
	{
		return m_StartTime;
	}
private:
	//路点ID
	INT32 m_WayPoint;
public:
	void SetWayPoint( INT32 v)
	{
		m_WayPoint=v;
	}
	INT32 GetWayPoint()
	{
		return m_WayPoint;
	}
	INT32 GetWayPoint() const
	{
		return m_WayPoint;
	}

};
//交互结束请求封装类
class EventNpcRpcEndEventAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventNpcRpcEndEventAskWraper()
	{
		

	}
	//赋值构造函数
	EventNpcRpcEndEventAskWraper(const EventNpcRpcEndEventAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EventNpcRpcEndEventAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventNpcRpcEndEventAsk ToPB() const
	{
		EventNpcRpcEndEventAsk v;

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
		EventNpcRpcEndEventAsk pb;
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
	void Init(const EventNpcRpcEndEventAsk& v)
	{

	}


};
//开始交互请求封装类
class EventNpcRpcBeginEventAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventNpcRpcBeginEventAskWraper()
	{
		
		m_EventIndex = -1;

	}
	//赋值构造函数
	EventNpcRpcBeginEventAskWraper(const EventNpcRpcBeginEventAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EventNpcRpcBeginEventAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventNpcRpcBeginEventAsk ToPB() const
	{
		EventNpcRpcBeginEventAsk v;
		v.set_eventindex( m_EventIndex );

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
		EventNpcRpcBeginEventAsk pb;
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
	void Init(const EventNpcRpcBeginEventAsk& v)
	{
		m_EventIndex = v.eventindex();

	}

private:
	//索引
	INT32 m_EventIndex;
public:
	void SetEventIndex( INT32 v)
	{
		m_EventIndex=v;
	}
	INT32 GetEventIndex()
	{
		return m_EventIndex;
	}
	INT32 GetEventIndex() const
	{
		return m_EventIndex;
	}

};
//开始交互回应封装类
class EventNpcRpcBeginEventReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventNpcRpcBeginEventReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	EventNpcRpcBeginEventReplyWraper(const EventNpcRpcBeginEventReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EventNpcRpcBeginEventReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventNpcRpcBeginEventReply ToPB() const
	{
		EventNpcRpcBeginEventReply v;
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
		EventNpcRpcBeginEventReply pb;
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
	void Init(const EventNpcRpcBeginEventReply& v)
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
template<> struct MessageIdT<EventNpcRpcActivityBeginNotifyWraper>{ enum{ID=RPC_CODE_EVENTNPC_ACTIVITYBEGIN_NOTIFY};};


#endif
