/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperWorldServer.h
* Author:       甘业清
* Description:  世界服务器模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_WORLDSERVER_H
#define __RPC_WRAPER_WORLDSERVER_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "WorldServerRpc.pb.h"



//世界服务器模块类的枚举定义
enum ConstWorldServerE
{
	MODULE_ID_WORLDSERVER                        = 8,	//世界服务器模块模块ID
	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST  = 851,	//世界服务器模块-->UpdateRoleInfo-->请求
	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST= 852,	//世界服务器模块-->CreateDungeonNotify-->请求
	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST     = 853,	//世界服务器模块-->ExitDungeon-->请求
	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST  = 854,	//世界服务器模块-->UpdateTeamInfo-->请求
	RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST      = 855,	//世界服务器模块-->播放动画 队伍-->请求
	RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST        = 856,	//世界服务器模块-->发送邮件-->请求
	RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST  = 857,	//世界服务器模块-->改变队伍类型-->请求
	RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST       = 858,	//世界服务器模块-->自动匹配-->请求
	RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST     = 859,	//世界服务器模块-->取消匹配-->请求
	RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST = 860,	//世界服务器模块-->登录服务器-->请求
	RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST= 861,	//世界服务器模块-->LoginGameServer-->请求
	RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST   = 862,	//世界服务器模块-->获取玩家信息-->请求


};


//改变队伍类型请求封装类
class WorldServerRpcChangeTeamTypeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcChangeTeamTypeAskWraper()
	{
		
		m_TeamId = 0;
		m_RoleId = 0;
		m_Result = -1;
		m_TeamType = -1;
		m_Target = TeamTargetWraper();

	}
	//赋值构造函数
	WorldServerRpcChangeTeamTypeAskWraper(const WorldServerRpcChangeTeamTypeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeTeamTypeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeTeamTypeAsk ToPB() const
	{
		WorldServerRpcChangeTeamTypeAsk v;
		v.set_teamid( m_TeamId );
		v.set_roleid( m_RoleId );
		v.set_result( m_Result );
		v.set_teamtype( m_TeamType );
		*v.mutable_target()= m_Target.ToPB();

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
		WorldServerRpcChangeTeamTypeAsk pb;
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
	void Init(const WorldServerRpcChangeTeamTypeAsk& v)
	{
		m_TeamId = v.teamid();
		m_RoleId = v.roleid();
		m_Result = v.result();
		m_TeamType = v.teamtype();
		m_Target = v.target();

	}

private:
	//队伍id
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
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
	//队伍类型
	INT32 m_TeamType;
public:
	void SetTeamType( INT32 v)
	{
		m_TeamType=v;
	}
	INT32 GetTeamType()
	{
		return m_TeamType;
	}
	INT32 GetTeamType() const
	{
		return m_TeamType;
	}
private:
	//目标
	TeamTargetWraper m_Target;
public:
	void SetTarget( const TeamTargetWraper& v)
	{
		m_Target=v;
	}
	TeamTargetWraper GetTarget()
	{
		return m_Target;
	}
	TeamTargetWraper GetTarget() const
	{
		return m_Target;
	}

};
//改变队伍类型回应封装类
class WorldServerRpcChangeTeamTypeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcChangeTeamTypeReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcChangeTeamTypeReplyWraper(const WorldServerRpcChangeTeamTypeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeTeamTypeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeTeamTypeReply ToPB() const
	{
		WorldServerRpcChangeTeamTypeReply v;
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
		WorldServerRpcChangeTeamTypeReply pb;
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
	void Init(const WorldServerRpcChangeTeamTypeReply& v)
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
//自动匹配请求封装类
class WorldServerRpcAutoMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcAutoMatchAskWraper()
	{
		
		m_MemberInfo = TeamMemberInfoWraper();
		m_MatchInfo = PlayerMatchDataWraper();
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcAutoMatchAskWraper(const WorldServerRpcAutoMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAutoMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAutoMatchAsk ToPB() const
	{
		WorldServerRpcAutoMatchAsk v;
		*v.mutable_memberinfo()= m_MemberInfo.ToPB();
		*v.mutable_matchinfo()= m_MatchInfo.ToPB();
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
		WorldServerRpcAutoMatchAsk pb;
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
	void Init(const WorldServerRpcAutoMatchAsk& v)
	{
		m_MemberInfo = v.memberinfo();
		m_MatchInfo = v.matchinfo();
		m_Result = v.result();

	}

private:
	//玩家队伍信息
	TeamMemberInfoWraper m_MemberInfo;
public:
	void SetMemberInfo( const TeamMemberInfoWraper& v)
	{
		m_MemberInfo=v;
	}
	TeamMemberInfoWraper GetMemberInfo()
	{
		return m_MemberInfo;
	}
	TeamMemberInfoWraper GetMemberInfo() const
	{
		return m_MemberInfo;
	}
private:
	//匹配信息
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
//播放动画 队伍回应封装类
class WorldServerRpcPlayCgTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcPlayCgTeamReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcPlayCgTeamReplyWraper(const WorldServerRpcPlayCgTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcPlayCgTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcPlayCgTeamReply ToPB() const
	{
		WorldServerRpcPlayCgTeamReply v;
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
		WorldServerRpcPlayCgTeamReply pb;
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
	void Init(const WorldServerRpcPlayCgTeamReply& v)
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
//发送邮件请求封装类
class WorldServerRpcSendMailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcSendMailAskWraper()
	{
		
		m_Mail = MailInfoWraper();
		m_GlobalMailID = 0;

	}
	//赋值构造函数
	WorldServerRpcSendMailAskWraper(const WorldServerRpcSendMailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcSendMailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcSendMailAsk ToPB() const
	{
		WorldServerRpcSendMailAsk v;
		*v.mutable_mail()= m_Mail.ToPB();
		v.set_globalmailid( m_GlobalMailID );

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
		WorldServerRpcSendMailAsk pb;
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
	void Init(const WorldServerRpcSendMailAsk& v)
	{
		m_Mail = v.mail();
		m_GlobalMailID = v.globalmailid();

	}

private:
	//邮件列表
	MailInfoWraper m_Mail;
public:
	void SetMail( const MailInfoWraper& v)
	{
		m_Mail=v;
	}
	MailInfoWraper GetMail()
	{
		return m_Mail;
	}
	MailInfoWraper GetMail() const
	{
		return m_Mail;
	}
private:
	//全服邮件ID
	uint64_t m_GlobalMailID;
public:
	void SetGlobalMailID( uint64_t v)
	{
		m_GlobalMailID=v;
	}
	uint64_t GetGlobalMailID()
	{
		return m_GlobalMailID;
	}
	uint64_t GetGlobalMailID() const
	{
		return m_GlobalMailID;
	}

};
//发送邮件回应封装类
class WorldServerRpcSendMailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcSendMailReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcSendMailReplyWraper(const WorldServerRpcSendMailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcSendMailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcSendMailReply ToPB() const
	{
		WorldServerRpcSendMailReply v;
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
		WorldServerRpcSendMailReply pb;
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
	void Init(const WorldServerRpcSendMailReply& v)
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
//自动匹配回应封装类
class WorldServerRpcAutoMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcAutoMatchReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcAutoMatchReplyWraper(const WorldServerRpcAutoMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAutoMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAutoMatchReply ToPB() const
	{
		WorldServerRpcAutoMatchReply v;
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
		WorldServerRpcAutoMatchReply pb;
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
	void Init(const WorldServerRpcAutoMatchReply& v)
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
//LoginGameServer回应封装类
class WorldServerRpcLogoutGameServerReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcLogoutGameServerReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcLogoutGameServerReplyWraper(const WorldServerRpcLogoutGameServerReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLogoutGameServerReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLogoutGameServerReply ToPB() const
	{
		WorldServerRpcLogoutGameServerReply v;
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
		WorldServerRpcLogoutGameServerReply pb;
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
	void Init(const WorldServerRpcLogoutGameServerReply& v)
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
//获取玩家信息请求封装类
class WorldServerRpcGetPlayerInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcGetPlayerInfoAskWraper()
	{
		
		m_Player_guid = 0;

	}
	//赋值构造函数
	WorldServerRpcGetPlayerInfoAskWraper(const WorldServerRpcGetPlayerInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcGetPlayerInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcGetPlayerInfoAsk ToPB() const
	{
		WorldServerRpcGetPlayerInfoAsk v;
		v.set_player_guid( m_Player_guid );

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
		WorldServerRpcGetPlayerInfoAsk pb;
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
	void Init(const WorldServerRpcGetPlayerInfoAsk& v)
	{
		m_Player_guid = v.player_guid();

	}

private:
	//玩家guid
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}

};
//获取玩家信息回应封装类
class WorldServerRpcGetPlayerInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcGetPlayerInfoReplyWraper()
	{
		
		m_Result = -1;
		m_Player_name = "";
		m_Player_guid = 0;
		m_Avatar_id = -1;
		m_Player_level = -1;
		m_Avatar_frame_id = -1;
		m_Config_id = -1;
		m_Guild_id = 0;
		m_Guild_name = "";
		m_BattleScore = -1;
		m_Pet_item_data = ItemDataWraper();
		m_TreasureHair = -1;
		m_TreasureHead = -1;
		m_TreasureBody = -1;
		m_TreasureWeapon = -1;
		m_TreasureWing = -1;
		m_TeamId = 0;

	}
	//赋值构造函数
	WorldServerRpcGetPlayerInfoReplyWraper(const WorldServerRpcGetPlayerInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcGetPlayerInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcGetPlayerInfoReply ToPB() const
	{
		WorldServerRpcGetPlayerInfoReply v;
		v.set_result( m_Result );
		v.set_player_name( m_Player_name );
		v.set_player_guid( m_Player_guid );
		v.set_avatar_id( m_Avatar_id );
		v.set_player_level( m_Player_level );
		v.set_avatar_frame_id( m_Avatar_frame_id );
		v.set_config_id( m_Config_id );
		v.set_guild_id( m_Guild_id );
		v.set_guild_name( m_Guild_name );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
		}
		v.mutable_suit_infos()->Reserve(m_Suit_infos.size());
		for (int i=0; i<(int)m_Suit_infos.size(); i++)
		{
			*v.add_suit_infos() = m_Suit_infos[i].ToPB();
		}
		v.mutable_equipslotdata()->Reserve(m_EquipSlotData.size());
		for (int i=0; i<(int)m_EquipSlotData.size(); i++)
		{
			*v.add_equipslotdata() = m_EquipSlotData[i].ToPB();
		}
		v.mutable_equipslotstarlist()->Reserve(m_EquipSlotStarList.size());
		for (int i=0; i<(int)m_EquipSlotStarList.size(); i++)
		{
			*v.add_equipslotstarlist() = m_EquipSlotStarList[i].ToPB();
		}
		v.mutable_jewelinfos()->Reserve(m_JewelInfos.size());
		for (int i=0; i<(int)m_JewelInfos.size(); i++)
		{
			*v.add_jewelinfos() = m_JewelInfos[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );
		*v.mutable_pet_item_data()= m_Pet_item_data.ToPB();
		v.set_treasurehair( m_TreasureHair );
		v.set_treasurehead( m_TreasureHead );
		v.set_treasurebody( m_TreasureBody );
		v.set_treasureweapon( m_TreasureWeapon );
		v.set_treasurewing( m_TreasureWing );
		v.set_teamid( m_TeamId );

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
		WorldServerRpcGetPlayerInfoReply pb;
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
	void Init(const WorldServerRpcGetPlayerInfoReply& v)
	{
		m_Result = v.result();
		m_Player_name = v.player_name();
		m_Player_guid = v.player_guid();
		m_Avatar_id = v.avatar_id();
		m_Player_level = v.player_level();
		m_Avatar_frame_id = v.avatar_frame_id();
		m_Config_id = v.config_id();
		m_Guild_id = v.guild_id();
		m_Guild_name = v.guild_name();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));
		m_Suit_infos.clear();
		m_Suit_infos.reserve(v.suit_infos_size());
		for( int i=0; i<v.suit_infos_size(); i++)
			m_Suit_infos.push_back(v.suit_infos(i));
		m_EquipSlotData.clear();
		m_EquipSlotData.reserve(v.equipslotdata_size());
		for( int i=0; i<v.equipslotdata_size(); i++)
			m_EquipSlotData.push_back(v.equipslotdata(i));
		m_EquipSlotStarList.clear();
		m_EquipSlotStarList.reserve(v.equipslotstarlist_size());
		for( int i=0; i<v.equipslotstarlist_size(); i++)
			m_EquipSlotStarList.push_back(v.equipslotstarlist(i));
		m_JewelInfos.clear();
		m_JewelInfos.reserve(v.jewelinfos_size());
		for( int i=0; i<v.jewelinfos_size(); i++)
			m_JewelInfos.push_back(v.jewelinfos(i));
		m_BattleScore = v.battlescore();
		m_Pet_item_data = v.pet_item_data();
		m_TreasureHair = v.treasurehair();
		m_TreasureHead = v.treasurehead();
		m_TreasureBody = v.treasurebody();
		m_TreasureWeapon = v.treasureweapon();
		m_TreasureWing = v.treasurewing();
		m_TeamId = v.teamid();

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
	//玩家名字
	string m_Player_name;
public:
	void SetPlayer_name( const string& v)
	{
		m_Player_name=v;
	}
	string GetPlayer_name()
	{
		return m_Player_name;
	}
	string GetPlayer_name() const
	{
		return m_Player_name;
	}
private:
	//玩家GUID
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}
private:
	//头像ID
	INT32 m_Avatar_id;
public:
	void SetAvatar_id( INT32 v)
	{
		m_Avatar_id=v;
	}
	INT32 GetAvatar_id()
	{
		return m_Avatar_id;
	}
	INT32 GetAvatar_id() const
	{
		return m_Avatar_id;
	}
private:
	//等级
	INT32 m_Player_level;
public:
	void SetPlayer_level( INT32 v)
	{
		m_Player_level=v;
	}
	INT32 GetPlayer_level()
	{
		return m_Player_level;
	}
	INT32 GetPlayer_level() const
	{
		return m_Player_level;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id;
public:
	void SetAvatar_frame_id( INT32 v)
	{
		m_Avatar_frame_id=v;
	}
	INT32 GetAvatar_frame_id()
	{
		return m_Avatar_frame_id;
	}
	INT32 GetAvatar_frame_id() const
	{
		return m_Avatar_frame_id;
	}
private:
	//角色配置ID
	INT32 m_Config_id;
public:
	void SetConfig_id( INT32 v)
	{
		m_Config_id=v;
	}
	INT32 GetConfig_id()
	{
		return m_Config_id;
	}
	INT32 GetConfig_id() const
	{
		return m_Config_id;
	}
private:
	//公会id
	uint64_t m_Guild_id;
public:
	void SetGuild_id( uint64_t v)
	{
		m_Guild_id=v;
	}
	uint64_t GetGuild_id()
	{
		return m_Guild_id;
	}
	uint64_t GetGuild_id() const
	{
		return m_Guild_id;
	}
private:
	//公会名字
	string m_Guild_name;
public:
	void SetGuild_name( const string& v)
	{
		m_Guild_name=v;
	}
	string GetGuild_name()
	{
		return m_Guild_name;
	}
	string GetGuild_name() const
	{
		return m_Guild_name;
	}
private:
	//装备信息
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}
private:
	//Suit_infos
	vector<SuitInfoWraper> m_Suit_infos;
public:
	int SizeSuit_infos()
	{
		return m_Suit_infos.size();
	}
	const vector<SuitInfoWraper>& GetSuit_infos() const
	{
		return m_Suit_infos;
	}
	SuitInfoWraper GetSuit_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_Suit_infos[Index];
	}
	void SetSuit_infos( const vector<SuitInfoWraper>& v )
	{
		m_Suit_infos=v;
	}
	void ClearSuit_infos( )
	{
		m_Suit_infos.clear();
	}
	void SetSuit_infos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return;
		}
		m_Suit_infos[Index] = v;
	}
	void AddSuit_infos( const SuitInfoWraper& v )
	{
		m_Suit_infos.push_back(v);
	}
private:
	//装备槽信息
	vector<EquipSlotInfoWraper> m_EquipSlotData;
public:
	int SizeEquipSlotData()
	{
		return m_EquipSlotData.size();
	}
	const vector<EquipSlotInfoWraper>& GetEquipSlotData() const
	{
		return m_EquipSlotData;
	}
	EquipSlotInfoWraper GetEquipSlotData(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return EquipSlotInfoWraper();
		}
		return m_EquipSlotData[Index];
	}
	void SetEquipSlotData( const vector<EquipSlotInfoWraper>& v )
	{
		m_EquipSlotData=v;
	}
	void ClearEquipSlotData( )
	{
		m_EquipSlotData.clear();
	}
	void SetEquipSlotData( int Index, const EquipSlotInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotData[Index] = v;
	}
	void AddEquipSlotData( const EquipSlotInfoWraper& v )
	{
		m_EquipSlotData.push_back(v);
	}
private:
	//装备槽星级列表
	vector<EquipSlotStarInfoWraper> m_EquipSlotStarList;
public:
	int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.size();
	}
	const vector<EquipSlotStarInfoWraper>& GetEquipSlotStarList() const
	{
		return m_EquipSlotStarList;
	}
	EquipSlotStarInfoWraper GetEquipSlotStarList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return EquipSlotStarInfoWraper();
		}
		return m_EquipSlotStarList[Index];
	}
	void SetEquipSlotStarList( const vector<EquipSlotStarInfoWraper>& v )
	{
		m_EquipSlotStarList=v;
	}
	void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.clear();
	}
	void SetEquipSlotStarList( int Index, const EquipSlotStarInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotStarList[Index] = v;
	}
	void AddEquipSlotStarList( const EquipSlotStarInfoWraper& v )
	{
		m_EquipSlotStarList.push_back(v);
	}
private:
	//宝石信息
	vector<JewelInfoWraper> m_JewelInfos;
public:
	int SizeJewelInfos()
	{
		return m_JewelInfos.size();
	}
	const vector<JewelInfoWraper>& GetJewelInfos() const
	{
		return m_JewelInfos;
	}
	JewelInfoWraper GetJewelInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_JewelInfos.size())
		{
			assert(false);
			return JewelInfoWraper();
		}
		return m_JewelInfos[Index];
	}
	void SetJewelInfos( const vector<JewelInfoWraper>& v )
	{
		m_JewelInfos=v;
	}
	void ClearJewelInfos( )
	{
		m_JewelInfos.clear();
	}
	void SetJewelInfos( int Index, const JewelInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_JewelInfos.size())
		{
			assert(false);
			return;
		}
		m_JewelInfos[Index] = v;
	}
	void AddJewelInfos( const JewelInfoWraper& v )
	{
		m_JewelInfos.push_back(v);
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//宠物数据
	ItemDataWraper m_Pet_item_data;
public:
	void SetPet_item_data( const ItemDataWraper& v)
	{
		m_Pet_item_data=v;
	}
	ItemDataWraper GetPet_item_data()
	{
		return m_Pet_item_data;
	}
	ItemDataWraper GetPet_item_data() const
	{
		return m_Pet_item_data;
	}
private:
	//头发时装ID
	INT32 m_TreasureHair;
public:
	void SetTreasureHair( INT32 v)
	{
		m_TreasureHair=v;
	}
	INT32 GetTreasureHair()
	{
		return m_TreasureHair;
	}
	INT32 GetTreasureHair() const
	{
		return m_TreasureHair;
	}
private:
	//头部时装ID
	INT32 m_TreasureHead;
public:
	void SetTreasureHead( INT32 v)
	{
		m_TreasureHead=v;
	}
	INT32 GetTreasureHead()
	{
		return m_TreasureHead;
	}
	INT32 GetTreasureHead() const
	{
		return m_TreasureHead;
	}
private:
	//身体时装
	INT32 m_TreasureBody;
public:
	void SetTreasureBody( INT32 v)
	{
		m_TreasureBody=v;
	}
	INT32 GetTreasureBody()
	{
		return m_TreasureBody;
	}
	INT32 GetTreasureBody() const
	{
		return m_TreasureBody;
	}
private:
	//武器时装
	INT32 m_TreasureWeapon;
public:
	void SetTreasureWeapon( INT32 v)
	{
		m_TreasureWeapon=v;
	}
	INT32 GetTreasureWeapon()
	{
		return m_TreasureWeapon;
	}
	INT32 GetTreasureWeapon() const
	{
		return m_TreasureWeapon;
	}
private:
	//翅膀时装
	INT32 m_TreasureWing;
public:
	void SetTreasureWing( INT32 v)
	{
		m_TreasureWing=v;
	}
	INT32 GetTreasureWing()
	{
		return m_TreasureWing;
	}
	INT32 GetTreasureWing() const
	{
		return m_TreasureWing;
	}
private:
	//队伍id
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
	}

};
//取消匹配请求封装类
class WorldServerRpcCancelMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcCancelMatchAskWraper()
	{
		
		m_RoleId = 0;
		m_Result = -1;
		m_IsNotify = 0;

	}
	//赋值构造函数
	WorldServerRpcCancelMatchAskWraper(const WorldServerRpcCancelMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCancelMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCancelMatchAsk ToPB() const
	{
		WorldServerRpcCancelMatchAsk v;
		v.set_roleid( m_RoleId );
		v.set_result( m_Result );
		v.set_isnotify( m_IsNotify );

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
		WorldServerRpcCancelMatchAsk pb;
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
	void Init(const WorldServerRpcCancelMatchAsk& v)
	{
		m_RoleId = v.roleid();
		m_Result = v.result();
		m_IsNotify = v.isnotify();

	}

private:
	//被拒绝RoleId
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
	//是否是通知
	INT32 m_IsNotify;
public:
	void SetIsNotify( INT32 v)
	{
		m_IsNotify=v;
	}
	INT32 GetIsNotify()
	{
		return m_IsNotify;
	}
	INT32 GetIsNotify() const
	{
		return m_IsNotify;
	}

};
//取消匹配回应封装类
class WorldServerRpcCancelMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcCancelMatchReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WorldServerRpcCancelMatchReplyWraper(const WorldServerRpcCancelMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCancelMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCancelMatchReply ToPB() const
	{
		WorldServerRpcCancelMatchReply v;
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
		WorldServerRpcCancelMatchReply pb;
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
	void Init(const WorldServerRpcCancelMatchReply& v)
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
//登录服务器回应封装类
class WorldServerRpcLoginGameServerReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcLoginGameServerReplyWraper()
	{
		
		m_Result = -1;
		m_Team = TeamInfoWraper();
		m_RoleInfo = OnlineUserInfoWraper();
		m_Location = CharacterLocationWraper();

	}
	//赋值构造函数
	WorldServerRpcLoginGameServerReplyWraper(const WorldServerRpcLoginGameServerReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLoginGameServerReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLoginGameServerReply ToPB() const
	{
		WorldServerRpcLoginGameServerReply v;
		v.set_result( m_Result );
		*v.mutable_team()= m_Team.ToPB();
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();
		*v.mutable_location()= m_Location.ToPB();

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
		WorldServerRpcLoginGameServerReply pb;
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
	void Init(const WorldServerRpcLoginGameServerReply& v)
	{
		m_Result = v.result();
		m_Team = v.team();
		m_RoleInfo = v.roleinfo();
		m_Location = v.location();

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
	//Team
	TeamInfoWraper m_Team;
public:
	void SetTeam( const TeamInfoWraper& v)
	{
		m_Team=v;
	}
	TeamInfoWraper GetTeam()
	{
		return m_Team;
	}
	TeamInfoWraper GetTeam() const
	{
		return m_Team;
	}
private:
	//RoleInfo
	OnlineUserInfoWraper m_RoleInfo;
public:
	void SetRoleInfo( const OnlineUserInfoWraper& v)
	{
		m_RoleInfo=v;
	}
	OnlineUserInfoWraper GetRoleInfo()
	{
		return m_RoleInfo;
	}
	OnlineUserInfoWraper GetRoleInfo() const
	{
		return m_RoleInfo;
	}
private:
	//玩家位置信息
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}

};
//Login回应封装类
class WorldServerRpcLogoutGameServerAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcLogoutGameServerAskWraper()
	{
		
		m_Result = -9999;
		m_RoleInfo = OnlineUserInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcLogoutGameServerAskWraper(const WorldServerRpcLogoutGameServerAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLogoutGameServerAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLogoutGameServerAsk ToPB() const
	{
		WorldServerRpcLogoutGameServerAsk v;
		v.set_result( m_Result );
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();

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
		WorldServerRpcLogoutGameServerAsk pb;
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
	void Init(const WorldServerRpcLogoutGameServerAsk& v)
	{
		m_Result = v.result();
		m_RoleInfo = v.roleinfo();

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
	//RoleInfo
	OnlineUserInfoWraper m_RoleInfo;
public:
	void SetRoleInfo( const OnlineUserInfoWraper& v)
	{
		m_RoleInfo=v;
	}
	OnlineUserInfoWraper GetRoleInfo()
	{
		return m_RoleInfo;
	}
	OnlineUserInfoWraper GetRoleInfo() const
	{
		return m_RoleInfo;
	}

};
//UpdateRoleInfo请求封装类
class WorldServerRpcUpdateRoleInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcUpdateRoleInfoAskWraper()
	{
		
		m_RoleInfo = OnlineUserInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcUpdateRoleInfoAskWraper(const WorldServerRpcUpdateRoleInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcUpdateRoleInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcUpdateRoleInfoAsk ToPB() const
	{
		WorldServerRpcUpdateRoleInfoAsk v;
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();

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
		WorldServerRpcUpdateRoleInfoAsk pb;
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
	void Init(const WorldServerRpcUpdateRoleInfoAsk& v)
	{
		m_RoleInfo = v.roleinfo();

	}

private:
	//RoleInfo
	OnlineUserInfoWraper m_RoleInfo;
public:
	void SetRoleInfo( const OnlineUserInfoWraper& v)
	{
		m_RoleInfo=v;
	}
	OnlineUserInfoWraper GetRoleInfo()
	{
		return m_RoleInfo;
	}
	OnlineUserInfoWraper GetRoleInfo() const
	{
		return m_RoleInfo;
	}

};
//UpdateRoleInfo回应封装类
class WorldServerRpcUpdateRoleInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcUpdateRoleInfoReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcUpdateRoleInfoReplyWraper(const WorldServerRpcUpdateRoleInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcUpdateRoleInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcUpdateRoleInfoReply ToPB() const
	{
		WorldServerRpcUpdateRoleInfoReply v;
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
		WorldServerRpcUpdateRoleInfoReply pb;
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
	void Init(const WorldServerRpcUpdateRoleInfoReply& v)
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
//进入场景请求封装类
class WorldServerRpcEnterSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcEnterSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_Location = CharacterLocationWraper();

	}
	//赋值构造函数
	WorldServerRpcEnterSceneAskWraper(const WorldServerRpcEnterSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcEnterSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcEnterSceneAsk ToPB() const
	{
		WorldServerRpcEnterSceneAsk v;
		v.set_roleid( m_RoleId );
		*v.mutable_location()= m_Location.ToPB();

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
		WorldServerRpcEnterSceneAsk pb;
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
	void Init(const WorldServerRpcEnterSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_Location = v.location();

	}

private:
	//角色id
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
	//玩家位置信息
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}

};
//进入场景回应封装类
class WorldServerRpcEnterSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcEnterSceneReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcEnterSceneReplyWraper(const WorldServerRpcEnterSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcEnterSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcEnterSceneReply ToPB() const
	{
		WorldServerRpcEnterSceneReply v;
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
		WorldServerRpcEnterSceneReply pb;
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
	void Init(const WorldServerRpcEnterSceneReply& v)
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
//Login请求封装类
class WorldServerRpcLoginGameServerAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcLoginGameServerAskWraper()
	{
		
		m_Team = TeamInfoWraper();
		m_RoleInfo = OnlineUserInfoWraper();
		m_Location = CharacterLocationWraper();

	}
	//赋值构造函数
	WorldServerRpcLoginGameServerAskWraper(const WorldServerRpcLoginGameServerAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLoginGameServerAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLoginGameServerAsk ToPB() const
	{
		WorldServerRpcLoginGameServerAsk v;
		*v.mutable_team()= m_Team.ToPB();
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();
		*v.mutable_location()= m_Location.ToPB();

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
		WorldServerRpcLoginGameServerAsk pb;
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
	void Init(const WorldServerRpcLoginGameServerAsk& v)
	{
		m_Team = v.team();
		m_RoleInfo = v.roleinfo();
		m_Location = v.location();

	}

private:
	//Team
	TeamInfoWraper m_Team;
public:
	void SetTeam( const TeamInfoWraper& v)
	{
		m_Team=v;
	}
	TeamInfoWraper GetTeam()
	{
		return m_Team;
	}
	TeamInfoWraper GetTeam() const
	{
		return m_Team;
	}
private:
	//RoleInfo
	OnlineUserInfoWraper m_RoleInfo;
public:
	void SetRoleInfo( const OnlineUserInfoWraper& v)
	{
		m_RoleInfo=v;
	}
	OnlineUserInfoWraper GetRoleInfo()
	{
		return m_RoleInfo;
	}
	OnlineUserInfoWraper GetRoleInfo() const
	{
		return m_RoleInfo;
	}
private:
	//玩家位置信息
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}

};
//CreateDungeonNotify请求封装类
class WorldServerRpcCreateDungeonNotifyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcCreateDungeonNotifyAskWraper()
	{
		
		m_CurSceneId = -1;
		m_RoleId = 0;
		m_TargetSceneId = -1;

	}
	//赋值构造函数
	WorldServerRpcCreateDungeonNotifyAskWraper(const WorldServerRpcCreateDungeonNotifyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateDungeonNotifyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateDungeonNotifyAsk ToPB() const
	{
		WorldServerRpcCreateDungeonNotifyAsk v;
		v.set_cursceneid( m_CurSceneId );
		v.set_roleid( m_RoleId );
		v.set_targetsceneid( m_TargetSceneId );

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
		WorldServerRpcCreateDungeonNotifyAsk pb;
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
	void Init(const WorldServerRpcCreateDungeonNotifyAsk& v)
	{
		m_CurSceneId = v.cursceneid();
		m_RoleId = v.roleid();
		m_TargetSceneId = v.targetsceneid();

	}

private:
	//场景id
	INT32 m_CurSceneId;
public:
	void SetCurSceneId( INT32 v)
	{
		m_CurSceneId=v;
	}
	INT32 GetCurSceneId()
	{
		return m_CurSceneId;
	}
	INT32 GetCurSceneId() const
	{
		return m_CurSceneId;
	}
private:
	//玩家的唯一id
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
	//场景id
	INT32 m_TargetSceneId;
public:
	void SetTargetSceneId( INT32 v)
	{
		m_TargetSceneId=v;
	}
	INT32 GetTargetSceneId()
	{
		return m_TargetSceneId;
	}
	INT32 GetTargetSceneId() const
	{
		return m_TargetSceneId;
	}

};
//UpdateTeamInfo请求封装类
class WorldServerRpcUpdateTeamInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcUpdateTeamInfoAskWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();
		m_RoleId = 0;
		m_Team = TeamInfoWraper();
		m_TeamType = -1;

	}
	//赋值构造函数
	WorldServerRpcUpdateTeamInfoAskWraper(const WorldServerRpcUpdateTeamInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcUpdateTeamInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcUpdateTeamInfoAsk ToPB() const
	{
		WorldServerRpcUpdateTeamInfoAsk v;
		*v.mutable_teammember()= m_TeamMember.ToPB();
		v.set_roleid( m_RoleId );
		*v.mutable_team()= m_Team.ToPB();
		v.set_teamtype( m_TeamType );

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
		WorldServerRpcUpdateTeamInfoAsk pb;
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
	void Init(const WorldServerRpcUpdateTeamInfoAsk& v)
	{
		m_TeamMember = v.teammember();
		m_RoleId = v.roleid();
		m_Team = v.team();
		m_TeamType = v.teamtype();

	}

private:
	//TeamMember
	TeamMemberInfoWraper m_TeamMember;
public:
	void SetTeamMember( const TeamMemberInfoWraper& v)
	{
		m_TeamMember=v;
	}
	TeamMemberInfoWraper GetTeamMember()
	{
		return m_TeamMember;
	}
	TeamMemberInfoWraper GetTeamMember() const
	{
		return m_TeamMember;
	}
private:
	//MemId
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
	//队伍信息
	TeamInfoWraper m_Team;
public:
	void SetTeam( const TeamInfoWraper& v)
	{
		m_Team=v;
	}
	TeamInfoWraper GetTeam()
	{
		return m_Team;
	}
	TeamInfoWraper GetTeam() const
	{
		return m_Team;
	}
private:
	//队伍类型
	INT32 m_TeamType;
public:
	void SetTeamType( INT32 v)
	{
		m_TeamType=v;
	}
	INT32 GetTeamType()
	{
		return m_TeamType;
	}
	INT32 GetTeamType() const
	{
		return m_TeamType;
	}

};
//UpdateTeamInfo回应封装类
class WorldServerRpcUpdateTeamInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcUpdateTeamInfoReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcUpdateTeamInfoReplyWraper(const WorldServerRpcUpdateTeamInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcUpdateTeamInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcUpdateTeamInfoReply ToPB() const
	{
		WorldServerRpcUpdateTeamInfoReply v;
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
		WorldServerRpcUpdateTeamInfoReply pb;
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
	void Init(const WorldServerRpcUpdateTeamInfoReply& v)
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
//播放动画 队伍请求封装类
class WorldServerRpcPlayCgTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcPlayCgTeamAskWraper()
	{
		
		m_PlayRoleId = 0;
		m_CgId = -1;
		m_State = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	WorldServerRpcPlayCgTeamAskWraper(const WorldServerRpcPlayCgTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcPlayCgTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcPlayCgTeamAsk ToPB() const
	{
		WorldServerRpcPlayCgTeamAsk v;
		v.set_playroleid( m_PlayRoleId );
		v.set_cgid( m_CgId );
		v.set_state( m_State );
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
		WorldServerRpcPlayCgTeamAsk pb;
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
	void Init(const WorldServerRpcPlayCgTeamAsk& v)
	{
		m_PlayRoleId = v.playroleid();
		m_CgId = v.cgid();
		m_State = v.state();
		m_RoleId = v.roleid();

	}

private:
	//角色ID
	uint64_t m_PlayRoleId;
public:
	void SetPlayRoleId( uint64_t v)
	{
		m_PlayRoleId=v;
	}
	uint64_t GetPlayRoleId()
	{
		return m_PlayRoleId;
	}
	uint64_t GetPlayRoleId() const
	{
		return m_PlayRoleId;
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
private:
	//状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//处理消息的roleID
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
//CreateDungeonNotify回应封装类
class WorldServerRpcCreateDungeonNotifyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcCreateDungeonNotifyReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcCreateDungeonNotifyReplyWraper(const WorldServerRpcCreateDungeonNotifyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateDungeonNotifyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateDungeonNotifyReply ToPB() const
	{
		WorldServerRpcCreateDungeonNotifyReply v;
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
		WorldServerRpcCreateDungeonNotifyReply pb;
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
	void Init(const WorldServerRpcCreateDungeonNotifyReply& v)
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
//ExitDungeon请求封装类
class WorldServerRpcExitDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcExitDungeonAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	WorldServerRpcExitDungeonAskWraper(const WorldServerRpcExitDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcExitDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcExitDungeonAsk ToPB() const
	{
		WorldServerRpcExitDungeonAsk v;
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
		WorldServerRpcExitDungeonAsk pb;
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
	void Init(const WorldServerRpcExitDungeonAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//玩家的唯一id
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
//ExitDungeon回应封装类
class WorldServerRpcExitDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcExitDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcExitDungeonReplyWraper(const WorldServerRpcExitDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcExitDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcExitDungeonReply ToPB() const
	{
		WorldServerRpcExitDungeonReply v;
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
		WorldServerRpcExitDungeonReply pb;
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
	void Init(const WorldServerRpcExitDungeonReply& v)
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
