/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperTeam.h
* Author:       郭晓波
* Description:  TeamRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TEAM_H
#define __RPC_WRAPER_TEAM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TeamRpc.pb.h"



//Team类的枚举定义
enum ConstTeamE
{
	MODULE_ID_TEAM                               = 10,	//Team模块ID
	RPC_CODE_TEAM_JOINTEAM_REQUEST               = 1051,	//Team-->加入队伍-->请求
	RPC_CODE_TEAM_LEAVETEAM_REQUEST              = 1052,	//Team-->LeaveTeam-->请求
	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST      = 1053,	//Team-->AppointTeamLeader-->请求
	RPC_CODE_TEAM_CREATETEAM_REQUEST             = 1054,	//Team-->CreateTeam-->请求
	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST           = 1055,	//Team-->DissmissTeam-->请求
	RPC_CODE_TEAM_NEWLEADER_NOTIFY               = 1056,	//Team-->NewLeader-->通知
	RPC_CODE_TEAM_KICKMEMBER_REQUEST             = 1057,	//Team-->KickMember-->请求
	RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY      = 1058,	//Team-->DissmissTeamNotify-->通知
	RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY          = 1059,	//Team-->JoinTeamNotify-->通知
	RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY        = 1060,	//Team-->KickMemberNotify-->通知
	RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY         = 1061,	//Team-->LeaveTeam-->通知
	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST        = 1062,	//Team-->SurroundingTeam-->请求
	RPC_CODE_TEAM_APPLYTEAM_REQUEST              = 1063,	//Team-->ApplyTeam-->请求
	RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY         = 1064,	//Team-->ApplyTeamNotify-->通知
	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST         = 1065,	//Team-->AgreeApplicant-->请求
	RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY    = 1066,	//Team-->AgreeApplicantNotify-->通知
	RPC_CODE_TEAM_TEAMINFO_NOTIFY                = 1067,	//Team-->TeamInfo-->通知
	RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY       = 1068,	//Team-->UpdateTeamMemInfo-->通知


};


//SurroundingTeam请求封装类
class TeamRpcSurroundingTeamAskWraper
{
public:
	//构造函数
	TeamRpcSurroundingTeamAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcSurroundingTeamAskWraper(const TeamRpcSurroundingTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSurroundingTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSurroundingTeamAsk ToPB() const
	{
		TeamRpcSurroundingTeamAsk v;

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
		TeamRpcSurroundingTeamAsk pb;
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
	void Init(const TeamRpcSurroundingTeamAsk& v)
	{

	}


};
//SurroundingTeam回应封装类
class TeamRpcSurroundingTeamReplyWraper
{
public:
	//构造函数
	TeamRpcSurroundingTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcSurroundingTeamReplyWraper(const TeamRpcSurroundingTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSurroundingTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSurroundingTeamReply ToPB() const
	{
		TeamRpcSurroundingTeamReply v;
		v.set_result( m_Result );
		v.mutable_teamsinfo()->Reserve(m_TeamsInfo.size());
		for (int i=0; i<(int)m_TeamsInfo.size(); i++)
		{
			*v.add_teamsinfo() = m_TeamsInfo[i].ToPB();
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
		TeamRpcSurroundingTeamReply pb;
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
	void Init(const TeamRpcSurroundingTeamReply& v)
	{
		m_Result = v.result();
		m_TeamsInfo.clear();
		m_TeamsInfo.reserve(v.teamsinfo_size());
		for( int i=0; i<v.teamsinfo_size(); i++)
			m_TeamsInfo.push_back(v.teamsinfo(i));

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
	//TeamsInfo
	vector<TeamInfoWraper> m_TeamsInfo;
public:
	int SizeTeamsInfo()
	{
		return m_TeamsInfo.size();
	}
	const vector<TeamInfoWraper>& GetTeamsInfo() const
	{
		return m_TeamsInfo;
	}
	TeamInfoWraper GetTeamsInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_TeamsInfo.size())
		{
			assert(false);
			return TeamInfoWraper();
		}
		return m_TeamsInfo[Index];
	}
	void SetTeamsInfo( const vector<TeamInfoWraper>& v )
	{
		m_TeamsInfo=v;
	}
	void ClearTeamsInfo( )
	{
		m_TeamsInfo.clear();
	}
	void SetTeamsInfo( int Index, const TeamInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_TeamsInfo.size())
		{
			assert(false);
			return;
		}
		m_TeamsInfo[Index] = v;
	}
	void AddTeamsInfo( const TeamInfoWraper& v )
	{
		m_TeamsInfo.push_back(v);
	}

};
//ApplyTeam请求封装类
class TeamRpcApplyTeamAskWraper
{
public:
	//构造函数
	TeamRpcApplyTeamAskWraper()
	{
		
		m_TeamId = -1;

	}
	//赋值构造函数
	TeamRpcApplyTeamAskWraper(const TeamRpcApplyTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyTeamAsk ToPB() const
	{
		TeamRpcApplyTeamAsk v;
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
		TeamRpcApplyTeamAsk pb;
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
	void Init(const TeamRpcApplyTeamAsk& v)
	{
		m_TeamId = v.teamid();

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

};
//DissmissTeamNotify通知封装类
class TeamRpcDissmissTeamNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcDissmissTeamNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcDissmissTeamNotifyNotifyWraper(const TeamRpcDissmissTeamNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcDissmissTeamNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcDissmissTeamNotifyNotify ToPB() const
	{
		TeamRpcDissmissTeamNotifyNotify v;

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
		TeamRpcDissmissTeamNotifyNotify pb;
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
	void Init(const TeamRpcDissmissTeamNotifyNotify& v)
	{

	}


};
//KickMemberNotify通知封装类
class TeamRpcKickMemberNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcKickMemberNotifyNotifyWraper()
	{
		
		m_KickedMemberRoleId = 0;

	}
	//赋值构造函数
	TeamRpcKickMemberNotifyNotifyWraper(const TeamRpcKickMemberNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcKickMemberNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcKickMemberNotifyNotify ToPB() const
	{
		TeamRpcKickMemberNotifyNotify v;
		v.set_kickedmemberroleid( m_KickedMemberRoleId );

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
		TeamRpcKickMemberNotifyNotify pb;
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
	void Init(const TeamRpcKickMemberNotifyNotify& v)
	{
		m_KickedMemberRoleId = v.kickedmemberroleid();

	}

private:
	//KickMemberRoleId
	uint64_t m_KickedMemberRoleId;
public:
	void SetKickedMemberRoleId( uint64_t v)
	{
		m_KickedMemberRoleId=v;
	}
	uint64_t GetKickedMemberRoleId()
	{
		return m_KickedMemberRoleId;
	}
	uint64_t GetKickedMemberRoleId() const
	{
		return m_KickedMemberRoleId;
	}

};
//LeaveTeam通知封装类
class TeamRpcLeaveTeamNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcLeaveTeamNotifyNotifyWraper()
	{
		
		m_RoleId = 0;
		m_NewLeaderRoleId = 0;

	}
	//赋值构造函数
	TeamRpcLeaveTeamNotifyNotifyWraper(const TeamRpcLeaveTeamNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcLeaveTeamNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcLeaveTeamNotifyNotify ToPB() const
	{
		TeamRpcLeaveTeamNotifyNotify v;
		v.set_roleid( m_RoleId );
		v.set_newleaderroleid( m_NewLeaderRoleId );

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
		TeamRpcLeaveTeamNotifyNotify pb;
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
	void Init(const TeamRpcLeaveTeamNotifyNotify& v)
	{
		m_RoleId = v.roleid();
		m_NewLeaderRoleId = v.newleaderroleid();

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

};
//JoinTeamNotify通知封装类
class TeamRpcJoinTeamNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcJoinTeamNotifyNotifyWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();

	}
	//赋值构造函数
	TeamRpcJoinTeamNotifyNotifyWraper(const TeamRpcJoinTeamNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcJoinTeamNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcJoinTeamNotifyNotify ToPB() const
	{
		TeamRpcJoinTeamNotifyNotify v;
		*v.mutable_teammember()= m_TeamMember.ToPB();

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
		TeamRpcJoinTeamNotifyNotify pb;
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
	void Init(const TeamRpcJoinTeamNotifyNotify& v)
	{
		m_TeamMember = v.teammember();

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

};
//AgreeApplicantNotify通知封装类
class TeamRpcAgreeApplicantNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcAgreeApplicantNotifyNotifyWraper()
	{
		
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	TeamRpcAgreeApplicantNotifyNotifyWraper(const TeamRpcAgreeApplicantNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAgreeApplicantNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAgreeApplicantNotifyNotify ToPB() const
	{
		TeamRpcAgreeApplicantNotifyNotify v;
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
		TeamRpcAgreeApplicantNotifyNotify pb;
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
	void Init(const TeamRpcAgreeApplicantNotifyNotify& v)
	{
		m_Team = v.team();

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
//TeamInfo通知封装类
class TeamRpcTeamInfoNotifyWraper
{
public:
	//构造函数
	TeamRpcTeamInfoNotifyWraper()
	{
		
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	TeamRpcTeamInfoNotifyWraper(const TeamRpcTeamInfoNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcTeamInfoNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcTeamInfoNotify ToPB() const
	{
		TeamRpcTeamInfoNotify v;
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
		TeamRpcTeamInfoNotify pb;
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
	void Init(const TeamRpcTeamInfoNotify& v)
	{
		m_Team = v.team();

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
//UpdateTeamMemInfo通知封装类
class TeamRpcUpdateTeamMemInfoNotifyWraper
{
public:
	//构造函数
	TeamRpcUpdateTeamMemInfoNotifyWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();

	}
	//赋值构造函数
	TeamRpcUpdateTeamMemInfoNotifyWraper(const TeamRpcUpdateTeamMemInfoNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcUpdateTeamMemInfoNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcUpdateTeamMemInfoNotify ToPB() const
	{
		TeamRpcUpdateTeamMemInfoNotify v;
		*v.mutable_teammember()= m_TeamMember.ToPB();

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
		TeamRpcUpdateTeamMemInfoNotify pb;
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
	void Init(const TeamRpcUpdateTeamMemInfoNotify& v)
	{
		m_TeamMember = v.teammember();

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

};
//AgreeApplicant回应封装类
class TeamRpcAgreeApplicantReplyWraper
{
public:
	//构造函数
	TeamRpcAgreeApplicantReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcAgreeApplicantReplyWraper(const TeamRpcAgreeApplicantReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAgreeApplicantReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAgreeApplicantReply ToPB() const
	{
		TeamRpcAgreeApplicantReply v;
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
		TeamRpcAgreeApplicantReply pb;
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
	void Init(const TeamRpcAgreeApplicantReply& v)
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
//ApplyTeam回应封装类
class TeamRpcApplyTeamReplyWraper
{
public:
	//构造函数
	TeamRpcApplyTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_TeamId = -1;

	}
	//赋值构造函数
	TeamRpcApplyTeamReplyWraper(const TeamRpcApplyTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyTeamReply ToPB() const
	{
		TeamRpcApplyTeamReply v;
		v.set_result( m_Result );
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
		TeamRpcApplyTeamReply pb;
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
	void Init(const TeamRpcApplyTeamReply& v)
	{
		m_Result = v.result();
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

};
//ApplyTeamNotify通知封装类
class TeamRpcApplyTeamNotifyNotifyWraper
{
public:
	//构造函数
	TeamRpcApplyTeamNotifyNotifyWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();

	}
	//赋值构造函数
	TeamRpcApplyTeamNotifyNotifyWraper(const TeamRpcApplyTeamNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyTeamNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyTeamNotifyNotify ToPB() const
	{
		TeamRpcApplyTeamNotifyNotify v;
		*v.mutable_teammember()= m_TeamMember.ToPB();

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
		TeamRpcApplyTeamNotifyNotify pb;
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
	void Init(const TeamRpcApplyTeamNotifyNotify& v)
	{
		m_TeamMember = v.teammember();

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

};
//AgreeApplicant请求封装类
class TeamRpcAgreeApplicantAskWraper
{
public:
	//构造函数
	TeamRpcAgreeApplicantAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	TeamRpcAgreeApplicantAskWraper(const TeamRpcAgreeApplicantAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAgreeApplicantAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAgreeApplicantAsk ToPB() const
	{
		TeamRpcAgreeApplicantAsk v;
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
		TeamRpcAgreeApplicantAsk pb;
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
	void Init(const TeamRpcAgreeApplicantAsk& v)
	{
		m_RoleId = v.roleid();

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

};
//LeaveTeam请求封装类
class TeamRpcLeaveTeamAskWraper
{
public:
	//构造函数
	TeamRpcLeaveTeamAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcLeaveTeamAskWraper(const TeamRpcLeaveTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcLeaveTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcLeaveTeamAsk ToPB() const
	{
		TeamRpcLeaveTeamAsk v;

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
		TeamRpcLeaveTeamAsk pb;
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
	void Init(const TeamRpcLeaveTeamAsk& v)
	{

	}


};
//LeaveTeam回应封装类
class TeamRpcLeaveTeamReplyWraper
{
public:
	//构造函数
	TeamRpcLeaveTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcLeaveTeamReplyWraper(const TeamRpcLeaveTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcLeaveTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcLeaveTeamReply ToPB() const
	{
		TeamRpcLeaveTeamReply v;
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
		TeamRpcLeaveTeamReply pb;
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
	void Init(const TeamRpcLeaveTeamReply& v)
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
class TeamRpcAppointTeamLeaderAskWraper
{
public:
	//构造函数
	TeamRpcAppointTeamLeaderAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	TeamRpcAppointTeamLeaderAskWraper(const TeamRpcAppointTeamLeaderAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAppointTeamLeaderAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAppointTeamLeaderAsk ToPB() const
	{
		TeamRpcAppointTeamLeaderAsk v;
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
		TeamRpcAppointTeamLeaderAsk pb;
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
	void Init(const TeamRpcAppointTeamLeaderAsk& v)
	{
		m_RoleId = v.roleid();

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

};
//加入队伍回应封装类
class TeamRpcJoinTeamReplyWraper
{
public:
	//构造函数
	TeamRpcJoinTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	TeamRpcJoinTeamReplyWraper(const TeamRpcJoinTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcJoinTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcJoinTeamReply ToPB() const
	{
		TeamRpcJoinTeamReply v;
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
		TeamRpcJoinTeamReply pb;
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
	void Init(const TeamRpcJoinTeamReply& v)
	{
		m_Result = v.result();
		m_Team = v.team();

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

};
//创建队伍创建副本请求封装类
class TeamRpcCreateTeamAskWraper
{
public:
	//构造函数
	TeamRpcCreateTeamAskWraper()
	{
		
		m_TeamType = -1;

	}
	//赋值构造函数
	TeamRpcCreateTeamAskWraper(const TeamRpcCreateTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCreateTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCreateTeamAsk ToPB() const
	{
		TeamRpcCreateTeamAsk v;
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
		TeamRpcCreateTeamAsk pb;
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
	void Init(const TeamRpcCreateTeamAsk& v)
	{
		m_TeamType = v.teamtype();

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

};
//创建队伍创建副本回应封装类
class TeamRpcCreateTeamReplyWraper
{
public:
	//构造函数
	TeamRpcCreateTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	TeamRpcCreateTeamReplyWraper(const TeamRpcCreateTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcCreateTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcCreateTeamReply ToPB() const
	{
		TeamRpcCreateTeamReply v;
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
		TeamRpcCreateTeamReply pb;
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
	void Init(const TeamRpcCreateTeamReply& v)
	{
		m_Result = v.result();
		m_Team = v.team();

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
//加入队伍请求封装类
class TeamRpcJoinTeamAskWraper
{
public:
	//构造函数
	TeamRpcJoinTeamAskWraper()
	{
		
		m_TeamId = -1;
		m_TeamType = -1;
		m_Team = TeamInfoWraper();
		m_TeamMember = TeamMemberInfoWraper();

	}
	//赋值构造函数
	TeamRpcJoinTeamAskWraper(const TeamRpcJoinTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcJoinTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcJoinTeamAsk ToPB() const
	{
		TeamRpcJoinTeamAsk v;
		v.set_teamid( m_TeamId );
		v.set_teamtype( m_TeamType );
		*v.mutable_team()= m_Team.ToPB();
		*v.mutable_teammember()= m_TeamMember.ToPB();

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
		TeamRpcJoinTeamAsk pb;
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
	void Init(const TeamRpcJoinTeamAsk& v)
	{
		m_TeamId = v.teamid();
		m_TeamType = v.teamtype();
		m_Team = v.team();
		m_TeamMember = v.teammember();

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

};
//DissmissTeam请求封装类
class TeamRpcDissmissTeamAskWraper
{
public:
	//构造函数
	TeamRpcDissmissTeamAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcDissmissTeamAskWraper(const TeamRpcDissmissTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcDissmissTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcDissmissTeamAsk ToPB() const
	{
		TeamRpcDissmissTeamAsk v;

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
		TeamRpcDissmissTeamAsk pb;
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
	void Init(const TeamRpcDissmissTeamAsk& v)
	{

	}


};
//DissmissTeam回应封装类
class TeamRpcDissmissTeamReplyWraper
{
public:
	//构造函数
	TeamRpcDissmissTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcDissmissTeamReplyWraper(const TeamRpcDissmissTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcDissmissTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcDissmissTeamReply ToPB() const
	{
		TeamRpcDissmissTeamReply v;
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
		TeamRpcDissmissTeamReply pb;
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
	void Init(const TeamRpcDissmissTeamReply& v)
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
//AppointTeamLeader通知封装类
class TeamRpcAppointTeamLeaderNotifyWraper
{
public:
	//构造函数
	TeamRpcAppointTeamLeaderNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcAppointTeamLeaderNotifyWraper(const TeamRpcAppointTeamLeaderNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAppointTeamLeaderNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAppointTeamLeaderNotify ToPB() const
	{
		TeamRpcAppointTeamLeaderNotify v;

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
		TeamRpcAppointTeamLeaderNotify pb;
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
	void Init(const TeamRpcAppointTeamLeaderNotify& v)
	{

	}


};
//KickMember回应封装类
class TeamRpcKickMemberReplyWraper
{
public:
	//构造函数
	TeamRpcKickMemberReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TeamRpcKickMemberReplyWraper(const TeamRpcKickMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcKickMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcKickMemberReply ToPB() const
	{
		TeamRpcKickMemberReply v;
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
		TeamRpcKickMemberReply pb;
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
	void Init(const TeamRpcKickMemberReply& v)
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
//AppointTeamLeader回应封装类
class TeamRpcAppointTeamLeaderReplyWraper
{
public:
	//构造函数
	TeamRpcAppointTeamLeaderReplyWraper()
	{
		
		m_Result = -9999;
		m_NewLeaderId = 0;

	}
	//赋值构造函数
	TeamRpcAppointTeamLeaderReplyWraper(const TeamRpcAppointTeamLeaderReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAppointTeamLeaderReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAppointTeamLeaderReply ToPB() const
	{
		TeamRpcAppointTeamLeaderReply v;
		v.set_result( m_Result );
		v.set_newleaderid( m_NewLeaderId );

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
		TeamRpcAppointTeamLeaderReply pb;
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
	void Init(const TeamRpcAppointTeamLeaderReply& v)
	{
		m_Result = v.result();
		m_NewLeaderId = v.newleaderid();

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
	//NewLeaderId
	uint64_t m_NewLeaderId;
public:
	void SetNewLeaderId( uint64_t v)
	{
		m_NewLeaderId=v;
	}
	uint64_t GetNewLeaderId()
	{
		return m_NewLeaderId;
	}
	uint64_t GetNewLeaderId() const
	{
		return m_NewLeaderId;
	}

};
//NewLeader通知封装类
class TeamRpcNewLeaderNotifyWraper
{
public:
	//构造函数
	TeamRpcNewLeaderNotifyWraper()
	{
		
		m_Newleaderroleid = 0;

	}
	//赋值构造函数
	TeamRpcNewLeaderNotifyWraper(const TeamRpcNewLeaderNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNewLeaderNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNewLeaderNotify ToPB() const
	{
		TeamRpcNewLeaderNotify v;
		v.set_newleaderroleid( m_Newleaderroleid );

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
		TeamRpcNewLeaderNotify pb;
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
	void Init(const TeamRpcNewLeaderNotify& v)
	{
		m_Newleaderroleid = v.newleaderroleid();

	}

private:
	//newleaderroleid
	uint64_t m_Newleaderroleid;
public:
	void SetNewleaderroleid( uint64_t v)
	{
		m_Newleaderroleid=v;
	}
	uint64_t GetNewleaderroleid()
	{
		return m_Newleaderroleid;
	}
	uint64_t GetNewleaderroleid() const
	{
		return m_Newleaderroleid;
	}

};
//KickMember请求封装类
class TeamRpcKickMemberAskWraper
{
public:
	//构造函数
	TeamRpcKickMemberAskWraper()
	{
		
		m_KickMemberRoleId = 0;

	}
	//赋值构造函数
	TeamRpcKickMemberAskWraper(const TeamRpcKickMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcKickMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcKickMemberAsk ToPB() const
	{
		TeamRpcKickMemberAsk v;
		v.set_kickmemberroleid( m_KickMemberRoleId );

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
		TeamRpcKickMemberAsk pb;
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
	void Init(const TeamRpcKickMemberAsk& v)
	{
		m_KickMemberRoleId = v.kickmemberroleid();

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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TeamRpcNewLeaderNotifyWraper>{ enum{ID=RPC_CODE_TEAM_NEWLEADER_NOTIFY};};
template<> struct MessageIdT<TeamRpcDissmissTeamNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcJoinTeamNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcKickMemberNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcLeaveTeamNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcApplyTeamNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcAgreeApplicantNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcTeamInfoNotifyWraper>{ enum{ID=RPC_CODE_TEAM_TEAMINFO_NOTIFY};};
template<> struct MessageIdT<TeamRpcUpdateTeamMemInfoNotifyWraper>{ enum{ID=RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY};};


#endif
