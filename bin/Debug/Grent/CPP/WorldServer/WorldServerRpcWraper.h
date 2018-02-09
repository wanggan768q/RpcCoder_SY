/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperWorldServer.h
* Author:       郭晓波
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
	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST     = 851,	//世界服务器模块-->通知世界服务器切换场景-->请求
	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST      = 852,	//世界服务器模块-->进入场景-->请求
	RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST   = 853,	//世界服务器模块-->创建副本通知-->请求
	RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST      = 854,	//世界服务器模块-->CreateTeam-->请求
	RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST        = 855,	//世界服务器模块-->JoinTeam-->请求
	RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST       = 856,	//世界服务器模块-->LeaveTeam-->请求
	RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST= 857,	//世界服务器模块-->AppointTeamLeader-->请求
	RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST     = 858,	//世界服务器模块-->DismissTeam-->请求
	RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST      = 859,	//世界服务器模块-->KickMember-->请求
	RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST       = 860,	//世界服务器模块-->ApplyTeam-->请求
	RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST= 861,	//世界服务器模块-->AgreeTeamApplicant-->请求
	RPC_CODE_WORLDSERVER_LOGIN_REQUEST           = 862,	//世界服务器模块-->Login-->请求
	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST  = 863,	//世界服务器模块-->UpdateRoleInfo-->请求
	RPC_CODE_WORLDSERVER_LOGOUT_REQUEST          = 864,	//世界服务器模块-->Logout-->请求
	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST= 865,	//世界服务器模块-->CreateDungeonNotify-->请求
	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST     = 866,	//世界服务器模块-->ExitDungeon-->请求
	RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST  = 867,	//世界服务器模块-->ReleaseDungeon-->请求


};


//Login请求封装类
class WorldServerRpcLoginAskWraper
{
public:
	//构造函数
	WorldServerRpcLoginAskWraper()
	{
		
		m_Team = TeamInfoWraper();
		m_MemId = -1;
		m_SceneId = -1;
		m_RoleInfo = OnlineUserInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcLoginAskWraper(const WorldServerRpcLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLoginAsk ToPB() const
	{
		WorldServerRpcLoginAsk v;
		*v.mutable_team()= m_Team.ToPB();
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );
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
		WorldServerRpcLoginAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLoginAsk& v)
	{
		m_Team = v.team();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();
		m_RoleInfo = v.roleinfo();

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
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
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
//AgreeTeamApplicant回应封装类
class WorldServerRpcAgreeTeamApplicantReplyWraper
{
public:
	//构造函数
	WorldServerRpcAgreeTeamApplicantReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcAgreeTeamApplicantReplyWraper(const WorldServerRpcAgreeTeamApplicantReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAgreeTeamApplicantReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAgreeTeamApplicantReply ToPB() const
	{
		WorldServerRpcAgreeTeamApplicantReply v;
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
		WorldServerRpcAgreeTeamApplicantReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcAgreeTeamApplicantReply& v)
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
//UpdateRoleInfo请求封装类
class WorldServerRpcUpdateRoleInfoAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//Login回应封装类
class WorldServerRpcLoginReplyWraper
{
public:
	//构造函数
	WorldServerRpcLoginReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcLoginReplyWraper(const WorldServerRpcLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLoginReply ToPB() const
	{
		WorldServerRpcLoginReply v;
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
		WorldServerRpcLoginReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLoginReply& v)
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
//ApplyTeam请求封装类
class WorldServerRpcApplyTeamAskWraper
{
public:
	//构造函数
	WorldServerRpcApplyTeamAskWraper()
	{
		
		m_TeamId = -1;
		m_Result = -9999;
		m_TeamMember = TeamMemberInfoWraper();
		m_MemId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	WorldServerRpcApplyTeamAskWraper(const WorldServerRpcApplyTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcApplyTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcApplyTeamAsk ToPB() const
	{
		WorldServerRpcApplyTeamAsk v;
		v.set_teamid( m_TeamId );
		v.set_result( m_Result );
		*v.mutable_teammember()= m_TeamMember.ToPB();
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );

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
		WorldServerRpcApplyTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcApplyTeamAsk& v)
	{
		m_TeamId = v.teamid();
		m_Result = v.result();
		m_TeamMember = v.teammember();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();

	}

private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
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
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}

};
//KickMember回应封装类
class WorldServerRpcKickMemberReplyWraper
{
public:
	//构造函数
	WorldServerRpcKickMemberReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcKickMemberReplyWraper(const WorldServerRpcKickMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcKickMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcKickMemberReply ToPB() const
	{
		WorldServerRpcKickMemberReply v;
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
		WorldServerRpcKickMemberReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcKickMemberReply& v)
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
//AgreeTeamApplicant请求封装类
class WorldServerRpcAgreeTeamApplicantAskWraper
{
public:
	//构造函数
	WorldServerRpcAgreeTeamApplicantAskWraper()
	{
		
		m_RoleId = 0;
		m_LeaderRoleId = 0;
		m_Result = -9999;
		m_MemId = -1;
		m_SceneId = -1;
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcAgreeTeamApplicantAskWraper(const WorldServerRpcAgreeTeamApplicantAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAgreeTeamApplicantAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAgreeTeamApplicantAsk ToPB() const
	{
		WorldServerRpcAgreeTeamApplicantAsk v;
		v.set_roleid( m_RoleId );
		v.set_leaderroleid( m_LeaderRoleId );
		v.set_result( m_Result );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );
		*v.mutable_team()= m_Team.ToPB();

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
		WorldServerRpcAgreeTeamApplicantAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcAgreeTeamApplicantAsk& v)
	{
		m_RoleId = v.roleid();
		m_LeaderRoleId = v.leaderroleid();
		m_Result = v.result();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();
		m_Team = v.team();

	}

private:
	//RoleId
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
	//RoleId
	uint64_t m_LeaderRoleId;
public:
	void SetLeaderRoleId( uint64_t v)
	{
		m_LeaderRoleId=v;
	}
	uint64_t GetLeaderRoleId()
	{
		return m_LeaderRoleId;
	}
	uint64_t GetLeaderRoleId() const
	{
		return m_LeaderRoleId;
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
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
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

};
//ApplyTeam回应封装类
class WorldServerRpcApplyTeamReplyWraper
{
public:
	//构造函数
	WorldServerRpcApplyTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcApplyTeamReplyWraper(const WorldServerRpcApplyTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcApplyTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcApplyTeamReply ToPB() const
	{
		WorldServerRpcApplyTeamReply v;
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
		WorldServerRpcApplyTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcApplyTeamReply& v)
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
//UpdateRoleInfo回应封装类
class WorldServerRpcUpdateRoleInfoReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//ExitDungeon回应封装类
class WorldServerRpcExitDungeonReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//ExitDungeon请求封装类
class WorldServerRpcExitDungeonAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//ReleaseDungeon回应封装类
class WorldServerRpcReleaseDungeonReplyWraper
{
public:
	//构造函数
	WorldServerRpcReleaseDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcReleaseDungeonReplyWraper(const WorldServerRpcReleaseDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcReleaseDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcReleaseDungeonReply ToPB() const
	{
		WorldServerRpcReleaseDungeonReply v;
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
		WorldServerRpcReleaseDungeonReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcReleaseDungeonReply& v)
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
//ReleaseDungeon请求封装类
class WorldServerRpcReleaseDungeonAskWraper
{
public:
	//构造函数
	WorldServerRpcReleaseDungeonAskWraper()
	{
		

	}
	//赋值构造函数
	WorldServerRpcReleaseDungeonAskWraper(const WorldServerRpcReleaseDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcReleaseDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcReleaseDungeonAsk ToPB() const
	{
		WorldServerRpcReleaseDungeonAsk v;

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
		WorldServerRpcReleaseDungeonAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcReleaseDungeonAsk& v)
	{

	}


};
//Logout回应封装类
class WorldServerRpcLogoutReplyWraper
{
public:
	//构造函数
	WorldServerRpcLogoutReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcLogoutReplyWraper(const WorldServerRpcLogoutReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLogoutReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLogoutReply ToPB() const
	{
		WorldServerRpcLogoutReply v;
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
		WorldServerRpcLogoutReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLogoutReply& v)
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
//Logout请求封装类
class WorldServerRpcLogoutAskWraper
{
public:
	//构造函数
	WorldServerRpcLogoutAskWraper()
	{
		
		m_RoleInfo = OnlineUserInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcLogoutAskWraper(const WorldServerRpcLogoutAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLogoutAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLogoutAsk ToPB() const
	{
		WorldServerRpcLogoutAsk v;
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
		WorldServerRpcLogoutAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLogoutAsk& v)
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
//CreateDungeonNotify回应封装类
class WorldServerRpcCreateDungeonNotifyReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//CreateDungeonNotify请求封装类
class WorldServerRpcCreateDungeonNotifyAskWraper
{
public:
	//构造函数
	WorldServerRpcCreateDungeonNotifyAskWraper()
	{
		
		m_CurSceneId = -1;
		m_RoleId = 0;
		m_MemId = -1;
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
		v.set_memid( m_MemId );
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcCreateDungeonNotifyAsk& v)
	{
		m_CurSceneId = v.cursceneid();
		m_RoleId = v.roleid();
		m_MemId = v.memid();
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
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
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
//创建副本通知回应封装类
class WorldServerRpcCreateDungeonReplyWraper
{
public:
	//构造函数
	WorldServerRpcCreateDungeonReplyWraper()
	{
		

	}
	//赋值构造函数
	WorldServerRpcCreateDungeonReplyWraper(const WorldServerRpcCreateDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateDungeonReply ToPB() const
	{
		WorldServerRpcCreateDungeonReply v;

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
		WorldServerRpcCreateDungeonReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcCreateDungeonReply& v)
	{

	}


};
//创建副本通知请求封装类
class WorldServerRpcCreateDungeonAskWraper
{
public:
	//构造函数
	WorldServerRpcCreateDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_TargetSceneId = -1;
		m_MemId = -1;
		m_DungeonConfigId = -1;
		m_CurSceneId = -1;
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcCreateDungeonAskWraper(const WorldServerRpcCreateDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateDungeonAsk ToPB() const
	{
		WorldServerRpcCreateDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_memid( m_MemId );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_cursceneid( m_CurSceneId );
		v.set_result( m_Result );
		v.mutable_roleids()->Reserve(m_RoleIds.size());
		for (int i=0; i<(int)m_RoleIds.size(); i++)
		{
			v.add_roleids(m_RoleIds[i]);
		}

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
		WorldServerRpcCreateDungeonAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcCreateDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_TargetSceneId = v.targetsceneid();
		m_MemId = v.memid();
		m_DungeonConfigId = v.dungeonconfigid();
		m_CurSceneId = v.cursceneid();
		m_Result = v.result();
		m_RoleIds.clear();
		m_RoleIds.reserve(v.roleids_size());
		for( int i=0; i<v.roleids_size(); i++)
			m_RoleIds.push_back(v.roleids(i));

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
	//目标场景id
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
private:
	//玩家的内存id
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}
private:
	//队员当前场景
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
	//玩家的唯一id
	vector<uint64_t> m_RoleIds;
public:
	int SizeRoleIds()
	{
		return m_RoleIds.size();
	}
	const vector<uint64_t>& GetRoleIds() const
	{
		return m_RoleIds;
	}
	uint64_t GetRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleIds[Index];
	}
	void SetRoleIds( const vector<uint64_t>& v )
	{
		m_RoleIds=v;
	}
	void ClearRoleIds( )
	{
		m_RoleIds.clear();
	}
	void SetRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return;
		}
		m_RoleIds[Index] = v;
	}
	void AddRoleIds( uint64_t v = 0 )
	{
		m_RoleIds.push_back(v);
	}

};
//CreateTeam回应封装类
class WorldServerRpcCreateTeamReplyWraper
{
public:
	//构造函数
	WorldServerRpcCreateTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcCreateTeamReplyWraper(const WorldServerRpcCreateTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateTeamReply ToPB() const
	{
		WorldServerRpcCreateTeamReply v;
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
		WorldServerRpcCreateTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcCreateTeamReply& v)
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
//CreateTeam请求封装类
class WorldServerRpcCreateTeamAskWraper
{
public:
	//构造函数
	WorldServerRpcCreateTeamAskWraper()
	{
		
		m_TeamType = -1;
		m_TeamMember = TeamMemberInfoWraper();
		m_Result = -9999;
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	WorldServerRpcCreateTeamAskWraper(const WorldServerRpcCreateTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcCreateTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcCreateTeamAsk ToPB() const
	{
		WorldServerRpcCreateTeamAsk v;
		v.set_teamtype( m_TeamType );
		*v.mutable_teammember()= m_TeamMember.ToPB();
		v.set_result( m_Result );
		*v.mutable_team()= m_Team.ToPB();

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
		WorldServerRpcCreateTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcCreateTeamAsk& v)
	{
		m_TeamType = v.teamtype();
		m_TeamMember = v.teammember();
		m_Result = v.result();
		m_Team = v.team();

	}

private:
	//TeamType
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
	//PbTeam
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

};
//通知世界服务器切换场景回应封装类
class WorldServerRpcChangeSceneReplyWraper
{
public:
	//构造函数
	WorldServerRpcChangeSceneReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;
		m_MemId = -1;

	}
	//赋值构造函数
	WorldServerRpcChangeSceneReplyWraper(const WorldServerRpcChangeSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeSceneReply ToPB() const
	{
		WorldServerRpcChangeSceneReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_memid( m_MemId );

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
		WorldServerRpcChangeSceneReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcChangeSceneReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();
		m_MemId = v.memid();

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
	//目标场景id
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
private:
	//玩家的内存id
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}

};
//通知世界服务器切换场景请求封装类
class WorldServerRpcChangeSceneAskWraper
{
public:
	//构造函数
	WorldServerRpcChangeSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;
		m_MemId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	WorldServerRpcChangeSceneAskWraper(const WorldServerRpcChangeSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeSceneAsk ToPB() const
	{
		WorldServerRpcChangeSceneAsk v;
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );

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
		WorldServerRpcChangeSceneAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcChangeSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();

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
	//目标场景id
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
private:
	//玩家的内存id
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//场景id
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}

};
//进入场景回应封装类
class WorldServerRpcEnterSceneReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//进入场景请求封装类
class WorldServerRpcEnterSceneAskWraper
{
public:
	//构造函数
	WorldServerRpcEnterSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;
		m_MemId = -1;

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
		v.set_sceneid( m_SceneId );
		v.set_memid( m_MemId );

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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcEnterSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();
		m_MemId = v.memid();

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
	//场景id
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}

};
//JoinTeam请求封装类
class WorldServerRpcJoinTeamAskWraper
{
public:
	//构造函数
	WorldServerRpcJoinTeamAskWraper()
	{
		
		m_TeamId = -1;
		m_Result = -9999;
		m_TeamMember = TeamMemberInfoWraper();
		m_Team = TeamInfoWraper();
		m_TeamType = -1;
		m_MemId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	WorldServerRpcJoinTeamAskWraper(const WorldServerRpcJoinTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcJoinTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcJoinTeamAsk ToPB() const
	{
		WorldServerRpcJoinTeamAsk v;
		v.set_teamid( m_TeamId );
		v.set_result( m_Result );
		*v.mutable_teammember()= m_TeamMember.ToPB();
		*v.mutable_team()= m_Team.ToPB();
		v.set_teamtype( m_TeamType );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );

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
		WorldServerRpcJoinTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcJoinTeamAsk& v)
	{
		m_TeamId = v.teamid();
		m_Result = v.result();
		m_TeamMember = v.teammember();
		m_Team = v.team();
		m_TeamType = v.teamtype();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();

	}

private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
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
	//Member
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
	//TeamType
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
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}

};
//DismissTeam请求封装类
class WorldServerRpcDismissTeamAskWraper
{
public:
	//构造函数
	WorldServerRpcDismissTeamAskWraper()
	{
		
		m_SceneId = -1;
		m_MemId = -1;
		m_RoleId = 0;
		m_TeamId = -1;
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcDismissTeamAskWraper(const WorldServerRpcDismissTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcDismissTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcDismissTeamAsk ToPB() const
	{
		WorldServerRpcDismissTeamAsk v;
		v.set_sceneid( m_SceneId );
		v.set_memid( m_MemId );
		v.set_roleid( m_RoleId );
		v.set_teamid( m_TeamId );
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
		WorldServerRpcDismissTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcDismissTeamAsk& v)
	{
		m_SceneId = v.sceneid();
		m_MemId = v.memid();
		m_RoleId = v.roleid();
		m_TeamId = v.teamid();
		m_Result = v.result();

	}

private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//RoleId
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
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
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
//AppointTeamLeader回应封装类
class WorldServerRpcAppointTeamLeaderReplyWraper
{
public:
	//构造函数
	WorldServerRpcAppointTeamLeaderReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcAppointTeamLeaderReplyWraper(const WorldServerRpcAppointTeamLeaderReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAppointTeamLeaderReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAppointTeamLeaderReply ToPB() const
	{
		WorldServerRpcAppointTeamLeaderReply v;
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
		WorldServerRpcAppointTeamLeaderReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcAppointTeamLeaderReply& v)
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
//KickMember请求封装类
class WorldServerRpcKickMemberAskWraper
{
public:
	//构造函数
	WorldServerRpcKickMemberAskWraper()
	{
		
		m_KickMemberRoleId = 0;
		m_MemId = -1;
		m_SceneId = -1;
		m_TeamId = -1;
		m_LeaderRoleId = 0;
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcKickMemberAskWraper(const WorldServerRpcKickMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcKickMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcKickMemberAsk ToPB() const
	{
		WorldServerRpcKickMemberAsk v;
		v.set_kickmemberroleid( m_KickMemberRoleId );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );
		v.set_teamid( m_TeamId );
		v.set_leaderroleid( m_LeaderRoleId );
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
		WorldServerRpcKickMemberAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcKickMemberAsk& v)
	{
		m_KickMemberRoleId = v.kickmemberroleid();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();
		m_TeamId = v.teamid();
		m_LeaderRoleId = v.leaderroleid();
		m_Result = v.result();

	}

private:
	//KickMemberRoleId
	uint64_t m_KickMemberRoleId;
public:
	void SetKickMemberRoleId( uint64_t v)
	{
		m_KickMemberRoleId=v;
	}
	uint64_t GetKickMemberRoleId()
	{
		return m_KickMemberRoleId;
	}
	uint64_t GetKickMemberRoleId() const
	{
		return m_KickMemberRoleId;
	}
private:
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//RoleId
	uint64_t m_LeaderRoleId;
public:
	void SetLeaderRoleId( uint64_t v)
	{
		m_LeaderRoleId=v;
	}
	uint64_t GetLeaderRoleId()
	{
		return m_LeaderRoleId;
	}
	uint64_t GetLeaderRoleId() const
	{
		return m_LeaderRoleId;
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
//DismissTeam回应封装类
class WorldServerRpcDismissTeamReplyWraper
{
public:
	//构造函数
	WorldServerRpcDismissTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcDismissTeamReplyWraper(const WorldServerRpcDismissTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcDismissTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcDismissTeamReply ToPB() const
	{
		WorldServerRpcDismissTeamReply v;
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
		WorldServerRpcDismissTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcDismissTeamReply& v)
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
//LeaveTeam请求封装类
class WorldServerRpcLeaveTeamAskWraper
{
public:
	//构造函数
	WorldServerRpcLeaveTeamAskWraper()
	{
		
		m_TeamId = -1;
		m_RoleId = 0;
		m_MemId = -1;
		m_SceneId = -1;
		m_NewLeaderRoleId = 0;
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcLeaveTeamAskWraper(const WorldServerRpcLeaveTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLeaveTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLeaveTeamAsk ToPB() const
	{
		WorldServerRpcLeaveTeamAsk v;
		v.set_teamid( m_TeamId );
		v.set_roleid( m_RoleId );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );
		v.set_newleaderroleid( m_NewLeaderRoleId );
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
		WorldServerRpcLeaveTeamAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLeaveTeamAsk& v)
	{
		m_TeamId = v.teamid();
		m_RoleId = v.roleid();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();
		m_NewLeaderRoleId = v.newleaderroleid();
		m_Result = v.result();

	}

private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//RoleId
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
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//NewLeader
	uint64_t m_NewLeaderRoleId;
public:
	void SetNewLeaderRoleId( uint64_t v)
	{
		m_NewLeaderRoleId=v;
	}
	uint64_t GetNewLeaderRoleId()
	{
		return m_NewLeaderRoleId;
	}
	uint64_t GetNewLeaderRoleId() const
	{
		return m_NewLeaderRoleId;
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
//JoinTeam回应封装类
class WorldServerRpcJoinTeamReplyWraper
{
public:
	//构造函数
	WorldServerRpcJoinTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcJoinTeamReplyWraper(const WorldServerRpcJoinTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcJoinTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcJoinTeamReply ToPB() const
	{
		WorldServerRpcJoinTeamReply v;
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
		WorldServerRpcJoinTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcJoinTeamReply& v)
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
//AppointTeamLeader请求封装类
class WorldServerRpcAppointTeamLeaderAskWraper
{
public:
	//构造函数
	WorldServerRpcAppointTeamLeaderAskWraper()
	{
		
		m_NewLeaderRoleId = 0;
		m_MemId = -1;
		m_SceneId = -1;
		m_CurLeaderRoleId = 0;
		m_TeamId = -1;
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcAppointTeamLeaderAskWraper(const WorldServerRpcAppointTeamLeaderAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcAppointTeamLeaderAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcAppointTeamLeaderAsk ToPB() const
	{
		WorldServerRpcAppointTeamLeaderAsk v;
		v.set_newleaderroleid( m_NewLeaderRoleId );
		v.set_memid( m_MemId );
		v.set_sceneid( m_SceneId );
		v.set_curleaderroleid( m_CurLeaderRoleId );
		v.set_teamid( m_TeamId );
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
		WorldServerRpcAppointTeamLeaderAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcAppointTeamLeaderAsk& v)
	{
		m_NewLeaderRoleId = v.newleaderroleid();
		m_MemId = v.memid();
		m_SceneId = v.sceneid();
		m_CurLeaderRoleId = v.curleaderroleid();
		m_TeamId = v.teamid();
		m_Result = v.result();

	}

private:
	//RoleId
	uint64_t m_NewLeaderRoleId;
public:
	void SetNewLeaderRoleId( uint64_t v)
	{
		m_NewLeaderRoleId=v;
	}
	uint64_t GetNewLeaderRoleId()
	{
		return m_NewLeaderRoleId;
	}
	uint64_t GetNewLeaderRoleId() const
	{
		return m_NewLeaderRoleId;
	}
private:
	//MemId
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}
private:
	//SceneId
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//CurLeaderRoleId
	uint64_t m_CurLeaderRoleId;
public:
	void SetCurLeaderRoleId( uint64_t v)
	{
		m_CurLeaderRoleId=v;
	}
	uint64_t GetCurLeaderRoleId()
	{
		return m_CurLeaderRoleId;
	}
	uint64_t GetCurLeaderRoleId() const
	{
		return m_CurLeaderRoleId;
	}
private:
	//TeamId
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
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
//LeaveTeam回应封装类
class WorldServerRpcLeaveTeamReplyWraper
{
public:
	//构造函数
	WorldServerRpcLeaveTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcLeaveTeamReplyWraper(const WorldServerRpcLeaveTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcLeaveTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcLeaveTeamReply ToPB() const
	{
		WorldServerRpcLeaveTeamReply v;
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
		WorldServerRpcLeaveTeamReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldServerRpcLeaveTeamReply& v)
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
