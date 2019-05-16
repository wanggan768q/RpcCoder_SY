/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperCGAnimation.h
* Author:       甘业清
* Description:  动画播放模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CGANIMATION_H
#define __RPC_WRAPER_CGANIMATION_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "CGAnimationRpc.pb.h"



//动画播放模块类的枚举定义
enum ConstCGAnimationE
{
	MODULE_ID_CGANIMATION                        = 29,	//动画播放模块模块ID
	RPC_CODE_CGANIMATION_CGPLAY_REQUEST          = 2951,	//动画播放模块-->动画开始播放-->请求
	RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY     = 2952,	//动画播放模块-->通知-->通知
	RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY     = 2953,	//动画播放模块-->结束通知-->通知
	RPC_CODE_CGANIMATION_CGSKIP_REQUEST          = 2954,	//动画播放模块-->跳过CG-->请求
	RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY       = 2955,	//动画播放模块-->脚本播放-->通知


};


//跳过CG请求封装类
class CGAnimationRpcCgSkipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgSkipAskWraper()
	{
		

	}
	//赋值构造函数
	CGAnimationRpcCgSkipAskWraper(const CGAnimationRpcCgSkipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgSkipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgSkipAsk ToPB() const
	{
		CGAnimationRpcCgSkipAsk v;

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
		CGAnimationRpcCgSkipAsk pb;
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
	void Init(const CGAnimationRpcCgSkipAsk& v)
	{

	}


};
//跳过CG回应封装类
class CGAnimationRpcCgSkipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgSkipReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CGAnimationRpcCgSkipReplyWraper(const CGAnimationRpcCgSkipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgSkipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgSkipReply ToPB() const
	{
		CGAnimationRpcCgSkipReply v;
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
		CGAnimationRpcCgSkipReply pb;
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
	void Init(const CGAnimationRpcCgSkipReply& v)
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
//脚本播放通知封装类
class CGAnimationRpcScriptPlayNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcScriptPlayNotifyWraper()
	{
		
		m_CasterGuid = 0;
		m_AnimantionName = "";
		m_Time = -1;
		m_IsLoop = -1;
		m_SingleTime = -1;

	}
	//赋值构造函数
	CGAnimationRpcScriptPlayNotifyWraper(const CGAnimationRpcScriptPlayNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcScriptPlayNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcScriptPlayNotify ToPB() const
	{
		CGAnimationRpcScriptPlayNotify v;
		v.set_casterguid( m_CasterGuid );
		v.set_animantionname( m_AnimantionName );
		v.set_time( m_Time );
		v.set_isloop( m_IsLoop );
		v.set_singletime( m_SingleTime );

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
		CGAnimationRpcScriptPlayNotify pb;
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
	void Init(const CGAnimationRpcScriptPlayNotify& v)
	{
		m_CasterGuid = v.casterguid();
		m_AnimantionName = v.animantionname();
		m_Time = v.time();
		m_IsLoop = v.isloop();
		m_SingleTime = v.singletime();

	}

private:
	//释放者
	uint64_t m_CasterGuid;
public:
	void SetCasterGuid( uint64_t v)
	{
		m_CasterGuid=v;
	}
	uint64_t GetCasterGuid()
	{
		return m_CasterGuid;
	}
	uint64_t GetCasterGuid() const
	{
		return m_CasterGuid;
	}
private:
	//动画名称
	string m_AnimantionName;
public:
	void SetAnimantionName( const string& v)
	{
		m_AnimantionName=v;
	}
	string GetAnimantionName()
	{
		return m_AnimantionName;
	}
	string GetAnimantionName() const
	{
		return m_AnimantionName;
	}
private:
	//总时长
	float m_Time;
public:
	void SetTime( float v)
	{
		m_Time=v;
	}
	float GetTime()
	{
		return m_Time;
	}
	float GetTime() const
	{
		return m_Time;
	}
private:
	//是否循环
	INT32 m_IsLoop;
public:
	void SetIsLoop( INT32 v)
	{
		m_IsLoop=v;
	}
	INT32 GetIsLoop()
	{
		return m_IsLoop;
	}
	INT32 GetIsLoop() const
	{
		return m_IsLoop;
	}
private:
	//单个时长
	INT32 m_SingleTime;
public:
	void SetSingleTime( INT32 v)
	{
		m_SingleTime=v;
	}
	INT32 GetSingleTime()
	{
		return m_SingleTime;
	}
	INT32 GetSingleTime() const
	{
		return m_SingleTime;
	}

};
//结束通知通知封装类
class CGAnimationRpcCgOverNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgOverNotifyNotifyWraper()
	{
		
		m_RoleId = 0;
		m_CgId = -1;

	}
	//赋值构造函数
	CGAnimationRpcCgOverNotifyNotifyWraper(const CGAnimationRpcCgOverNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgOverNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgOverNotifyNotify ToPB() const
	{
		CGAnimationRpcCgOverNotifyNotify v;
		v.set_roleid( m_RoleId );
		v.set_cgid( m_CgId );

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
		CGAnimationRpcCgOverNotifyNotify pb;
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
	void Init(const CGAnimationRpcCgOverNotifyNotify& v)
	{
		m_RoleId = v.roleid();
		m_CgId = v.cgid();

	}

private:
	//角色Id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//动画Id
	INT32 m_CgId;
public:
	void SetCgId( INT32 v)
	{
		m_CgId=v;
	}
	INT32 GetCgId()
	{
		return m_CgId;
	}
	INT32 GetCgId() const
	{
		return m_CgId;
	}

};
//动画开始播放请求封装类
class CGAnimationRpcCgPlayAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgPlayAskWraper()
	{
		
		m_CgId = -1;

	}
	//赋值构造函数
	CGAnimationRpcCgPlayAskWraper(const CGAnimationRpcCgPlayAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgPlayAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgPlayAsk ToPB() const
	{
		CGAnimationRpcCgPlayAsk v;
		v.set_cgid( m_CgId );

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
		CGAnimationRpcCgPlayAsk pb;
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
	void Init(const CGAnimationRpcCgPlayAsk& v)
	{
		m_CgId = v.cgid();

	}

private:
	//动画ID
	INT32 m_CgId;
public:
	void SetCgId( INT32 v)
	{
		m_CgId=v;
	}
	INT32 GetCgId()
	{
		return m_CgId;
	}
	INT32 GetCgId() const
	{
		return m_CgId;
	}

};
//动画开始播放回应封装类
class CGAnimationRpcCgPlayReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgPlayReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CGAnimationRpcCgPlayReplyWraper(const CGAnimationRpcCgPlayReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgPlayReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgPlayReply ToPB() const
	{
		CGAnimationRpcCgPlayReply v;
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
		CGAnimationRpcCgPlayReply pb;
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
	void Init(const CGAnimationRpcCgPlayReply& v)
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
//通知通知封装类
class CGAnimationRpcCgPlayNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CGAnimationRpcCgPlayNotifyNotifyWraper()
	{
		
		m_RoleId = 0;
		m_CgId = -1;

	}
	//赋值构造函数
	CGAnimationRpcCgPlayNotifyNotifyWraper(const CGAnimationRpcCgPlayNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CGAnimationRpcCgPlayNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CGAnimationRpcCgPlayNotifyNotify ToPB() const
	{
		CGAnimationRpcCgPlayNotifyNotify v;
		v.set_roleid( m_RoleId );
		v.set_cgid( m_CgId );

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
		CGAnimationRpcCgPlayNotifyNotify pb;
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
	void Init(const CGAnimationRpcCgPlayNotifyNotify& v)
	{
		m_RoleId = v.roleid();
		m_CgId = v.cgid();

	}

private:
	//角色ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//动画ID
	INT32 m_CgId;
public:
	void SetCgId( INT32 v)
	{
		m_CgId=v;
	}
	INT32 GetCgId()
	{
		return m_CgId;
	}
	INT32 GetCgId() const
	{
		return m_CgId;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<CGAnimationRpcCgPlayNotifyNotifyWraper>{ enum{ID=RPC_CODE_CGANIMATION_CGPLAYNOTIFY_NOTIFY};};
template<> struct MessageIdT<CGAnimationRpcCgOverNotifyNotifyWraper>{ enum{ID=RPC_CODE_CGANIMATION_CGOVERNOTIFY_NOTIFY};};
template<> struct MessageIdT<CGAnimationRpcScriptPlayNotifyWraper>{ enum{ID=RPC_CODE_CGANIMATION_SCRIPTPLAY_NOTIFY};};


#endif
