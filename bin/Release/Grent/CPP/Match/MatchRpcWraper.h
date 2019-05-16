/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMatch.h
* Author:       甘业清
* Description:  匹配模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MATCH_H
#define __RPC_WRAPER_MATCH_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MatchRpc.pb.h"



//匹配模块类的枚举定义
enum ConstMatchE
{
	MODULE_ID_MATCH                              = 39,	//匹配模块模块ID
	RPC_CODE_MATCH_AUTOMATCH_REQUEST             = 3951,	//匹配模块-->匹配-->请求
	RPC_CODE_MATCH_CANCELMATCH_REQUEST           = 3952,	//匹配模块-->取消匹配-->请求
	RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY      = 3953,	//匹配模块-->取消匹配通知-->通知
	RPC_CODE_MATCH_PREPAREROOM_NOTIFY            = 3954,	//匹配模块-->开始准备进入房间-->通知
	RPC_CODE_MATCH_READY_REQUEST                 = 3955,	//匹配模块-->准备-->请求
	RPC_CODE_MATCH_CANCELREADY_REQUEST           = 3956,	//匹配模块-->取消准备-->请求
	RPC_CODE_MATCH_ROOMCANCEL_NOTIFY             = 3957,	//匹配模块-->房间取消-->通知
	RPC_CODE_MATCH_MEMBERREADY_NOTIFY            = 3958,	//匹配模块-->成员准备-->通知


};


//取消准备请求封装类
class MatchRpcCancelReadyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcCancelReadyAskWraper()
	{
		
		m_MatchType = -1;
		m_RoomId = 0;

	}
	//赋值构造函数
	MatchRpcCancelReadyAskWraper(const MatchRpcCancelReadyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcCancelReadyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcCancelReadyAsk ToPB() const
	{
		MatchRpcCancelReadyAsk v;
		v.set_matchtype( m_MatchType );
		v.set_roomid( m_RoomId );

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
		MatchRpcCancelReadyAsk pb;
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
	void Init(const MatchRpcCancelReadyAsk& v)
	{
		m_MatchType = v.matchtype();
		m_RoomId = v.roomid();

	}

private:
	//匹配类型
	INT32 m_MatchType;
public:
	void SetMatchType( INT32 v)
	{
		m_MatchType=v;
	}
	INT32 GetMatchType()
	{
		return m_MatchType;
	}
	INT32 GetMatchType() const
	{
		return m_MatchType;
	}
private:
	//房间的id
	uint64_t m_RoomId;
public:
	void SetRoomId( uint64_t v)
	{
		m_RoomId=v;
	}
	uint64_t GetRoomId()
	{
		return m_RoomId;
	}
	uint64_t GetRoomId() const
	{
		return m_RoomId;
	}

};
//准备回应封装类
class MatchRpcReadyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcReadyReplyWraper()
	{
		
		m_Result = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	MatchRpcReadyReplyWraper(const MatchRpcReadyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcReadyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcReadyReply ToPB() const
	{
		MatchRpcReadyReply v;
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
		MatchRpcReadyReply pb;
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
	void Init(const MatchRpcReadyReply& v)
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
	//玩家id
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

};
//准备请求封装类
class MatchRpcReadyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcReadyAskWraper()
	{
		
		m_MatchType = -1;
		m_RoomId = 0;

	}
	//赋值构造函数
	MatchRpcReadyAskWraper(const MatchRpcReadyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcReadyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcReadyAsk ToPB() const
	{
		MatchRpcReadyAsk v;
		v.set_matchtype( m_MatchType );
		v.set_roomid( m_RoomId );

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
		MatchRpcReadyAsk pb;
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
	void Init(const MatchRpcReadyAsk& v)
	{
		m_MatchType = v.matchtype();
		m_RoomId = v.roomid();

	}

private:
	//匹配类型
	INT32 m_MatchType;
public:
	void SetMatchType( INT32 v)
	{
		m_MatchType=v;
	}
	INT32 GetMatchType()
	{
		return m_MatchType;
	}
	INT32 GetMatchType() const
	{
		return m_MatchType;
	}
private:
	//房间的id
	uint64_t m_RoomId;
public:
	void SetRoomId( uint64_t v)
	{
		m_RoomId=v;
	}
	uint64_t GetRoomId()
	{
		return m_RoomId;
	}
	uint64_t GetRoomId() const
	{
		return m_RoomId;
	}

};
//成员准备通知封装类
class MatchRpcMemberReadyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcMemberReadyNotifyWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	MatchRpcMemberReadyNotifyWraper(const MatchRpcMemberReadyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcMemberReadyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcMemberReadyNotify ToPB() const
	{
		MatchRpcMemberReadyNotify v;
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
		MatchRpcMemberReadyNotify pb;
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
	void Init(const MatchRpcMemberReadyNotify& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//准备的玩家
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

};
//房间取消通知封装类
class MatchRpcRoomCancelNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcRoomCancelNotifyWraper()
	{
		

	}
	//赋值构造函数
	MatchRpcRoomCancelNotifyWraper(const MatchRpcRoomCancelNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcRoomCancelNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcRoomCancelNotify ToPB() const
	{
		MatchRpcRoomCancelNotify v;

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
		MatchRpcRoomCancelNotify pb;
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
	void Init(const MatchRpcRoomCancelNotify& v)
	{

	}


};
//取消准备回应封装类
class MatchRpcCancelReadyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcCancelReadyReplyWraper()
	{
		
		m_Result = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	MatchRpcCancelReadyReplyWraper(const MatchRpcCancelReadyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcCancelReadyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcCancelReadyReply ToPB() const
	{
		MatchRpcCancelReadyReply v;
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
		MatchRpcCancelReadyReply pb;
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
	void Init(const MatchRpcCancelReadyReply& v)
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
	//玩家Id
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

};
//取消匹配请求封装类
class MatchRpcCancelMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcCancelMatchAskWraper()
	{
		

	}
	//赋值构造函数
	MatchRpcCancelMatchAskWraper(const MatchRpcCancelMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcCancelMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcCancelMatchAsk ToPB() const
	{
		MatchRpcCancelMatchAsk v;

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
		MatchRpcCancelMatchAsk pb;
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
	void Init(const MatchRpcCancelMatchAsk& v)
	{

	}


};
//匹配回应封装类
class MatchRpcAutoMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcAutoMatchReplyWraper()
	{
		
		m_Result = -1;
		m_MatchInfo = PlayerMatchDataWraper();

	}
	//赋值构造函数
	MatchRpcAutoMatchReplyWraper(const MatchRpcAutoMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcAutoMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcAutoMatchReply ToPB() const
	{
		MatchRpcAutoMatchReply v;
		v.set_result( m_Result );
		*v.mutable_matchinfo()= m_MatchInfo.ToPB();

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
		MatchRpcAutoMatchReply pb;
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
	void Init(const MatchRpcAutoMatchReply& v)
	{
		m_Result = v.result();
		m_MatchInfo = v.matchinfo();

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
	//匹配参数
	PlayerMatchDataWraper m_MatchInfo;
public:
	void SetMatchInfo( const PlayerMatchDataWraper& v)
	{
		m_MatchInfo=v;
	}
	PlayerMatchDataWraper GetMatchInfo()
	{
		return m_MatchInfo;
	}
	PlayerMatchDataWraper GetMatchInfo() const
	{
		return m_MatchInfo;
	}

};
//匹配请求封装类
class MatchRpcAutoMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcAutoMatchAskWraper()
	{
		
		m_MatchInfo = PlayerMatchDataWraper();

	}
	//赋值构造函数
	MatchRpcAutoMatchAskWraper(const MatchRpcAutoMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcAutoMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcAutoMatchAsk ToPB() const
	{
		MatchRpcAutoMatchAsk v;
		*v.mutable_matchinfo()= m_MatchInfo.ToPB();

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
		MatchRpcAutoMatchAsk pb;
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
	void Init(const MatchRpcAutoMatchAsk& v)
	{
		m_MatchInfo = v.matchinfo();

	}

private:
	//匹配参数
	PlayerMatchDataWraper m_MatchInfo;
public:
	void SetMatchInfo( const PlayerMatchDataWraper& v)
	{
		m_MatchInfo=v;
	}
	PlayerMatchDataWraper GetMatchInfo()
	{
		return m_MatchInfo;
	}
	PlayerMatchDataWraper GetMatchInfo() const
	{
		return m_MatchInfo;
	}

};
//开始准备进入房间通知封装类
class MatchRpcPrepareRoomNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcPrepareRoomNotifyWraper()
	{
		
		m_ReadyRoom = PBMatchRoomWraper();

	}
	//赋值构造函数
	MatchRpcPrepareRoomNotifyWraper(const MatchRpcPrepareRoomNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcPrepareRoomNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcPrepareRoomNotify ToPB() const
	{
		MatchRpcPrepareRoomNotify v;
		*v.mutable_readyroom()= m_ReadyRoom.ToPB();

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
		MatchRpcPrepareRoomNotify pb;
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
	void Init(const MatchRpcPrepareRoomNotify& v)
	{
		m_ReadyRoom = v.readyroom();

	}

private:
	//准备界面
	PBMatchRoomWraper m_ReadyRoom;
public:
	void SetReadyRoom( const PBMatchRoomWraper& v)
	{
		m_ReadyRoom=v;
	}
	PBMatchRoomWraper GetReadyRoom()
	{
		return m_ReadyRoom;
	}
	PBMatchRoomWraper GetReadyRoom() const
	{
		return m_ReadyRoom;
	}

};
//取消匹配通知通知封装类
class MatchRpcCancelMatchNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcCancelMatchNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	MatchRpcCancelMatchNotifyNotifyWraper(const MatchRpcCancelMatchNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcCancelMatchNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcCancelMatchNotifyNotify ToPB() const
	{
		MatchRpcCancelMatchNotifyNotify v;

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
		MatchRpcCancelMatchNotifyNotify pb;
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
	void Init(const MatchRpcCancelMatchNotifyNotify& v)
	{

	}


};
//取消匹配回应封装类
class MatchRpcCancelMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MatchRpcCancelMatchReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MatchRpcCancelMatchReplyWraper(const MatchRpcCancelMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRpcCancelMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRpcCancelMatchReply ToPB() const
	{
		MatchRpcCancelMatchReply v;
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
		MatchRpcCancelMatchReply pb;
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
	void Init(const MatchRpcCancelMatchReply& v)
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
template<> struct MessageIdT<MatchRpcCancelMatchNotifyNotifyWraper>{ enum{ID=RPC_CODE_MATCH_CANCELMATCHNOTIFY_NOTIFY};};
template<> struct MessageIdT<MatchRpcPrepareRoomNotifyWraper>{ enum{ID=RPC_CODE_MATCH_PREPAREROOM_NOTIFY};};
template<> struct MessageIdT<MatchRpcRoomCancelNotifyWraper>{ enum{ID=RPC_CODE_MATCH_ROOMCANCEL_NOTIFY};};
template<> struct MessageIdT<MatchRpcMemberReadyNotifyWraper>{ enum{ID=RPC_CODE_MATCH_MEMBERREADY_NOTIFY};};


#endif
