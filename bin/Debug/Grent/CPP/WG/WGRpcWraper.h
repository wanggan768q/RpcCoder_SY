/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperWG.h
* Author:       郭晓波
* Description:  WGRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_WG_H
#define __RPC_WRAPER_WG_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "WGRpc.pb.h"



//WG类的枚举定义
enum ConstWGE
{
	MODULE_ID_WG                                 = 11,	//WG模块ID
	RPC_CODE_WG_INFORMCREATETEAM_REQUEST         = 1151,	//WG-->InformCreateTeam-->请求
	RPC_CODE_WG_INFORMJOINTEAM_REQUEST           = 1152,	//WG-->InformJoinTeam-->请求
	RPC_CODE_WG_INFORMLEAVE_REQUEST              = 1153,	//WG-->InformLeave-->请求
	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST  = 1154,	//WG-->InformAppointTeamLeader-->请求
	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST     = 1155,	//WG-->InformKickTeamMember-->请求
	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST       = 1156,	//WG-->InformDissmissTeam-->请求
	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST          = 1157,	//WG-->InformApply-->请求
	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST       = 1158,	//WG-->AgreeTeamApplicant-->请求
	RPC_CODE_WG_INFORMLOGIN_REQUEST              = 1159,	//WG-->InformLogin-->请求


};


//InformDissmissTeam回应封装类
class WGRpcInformDissmissTeamReplyWraper
{
public:
	//构造函数
	WGRpcInformDissmissTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformDissmissTeamReplyWraper(const WGRpcInformDissmissTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformDissmissTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformDissmissTeamReply ToPB() const
	{
		WGRpcInformDissmissTeamReply v;
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
		WGRpcInformDissmissTeamReply pb;
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
	void Init(const WGRpcInformDissmissTeamReply& v)
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
//InformApply请求封装类
class WGRpcInformApplyTeamAskWraper
{
public:
	//构造函数
	WGRpcInformApplyTeamAskWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();
		m_Result = -9999;
		m_TeamId = -1;

	}
	//赋值构造函数
	WGRpcInformApplyTeamAskWraper(const WGRpcInformApplyTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformApplyTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformApplyTeamAsk ToPB() const
	{
		WGRpcInformApplyTeamAsk v;
		*v.mutable_teammember()= m_TeamMember.ToPB();
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
		WGRpcInformApplyTeamAsk pb;
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
	void Init(const WGRpcInformApplyTeamAsk& v)
	{
		m_TeamMember = v.teammember();
		m_Result = v.result();
		m_TeamId = v.teamid();

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
//InformKickTeamMember回应封装类
class WGRpcInformKickTeamMemberReplyWraper
{
public:
	//构造函数
	WGRpcInformKickTeamMemberReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformKickTeamMemberReplyWraper(const WGRpcInformKickTeamMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformKickTeamMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformKickTeamMemberReply ToPB() const
	{
		WGRpcInformKickTeamMemberReply v;
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
		WGRpcInformKickTeamMemberReply pb;
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
	void Init(const WGRpcInformKickTeamMemberReply& v)
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
//InformDissmissTeam请求封装类
class WGRpcInformDissmissTeamAskWraper
{
public:
	//构造函数
	WGRpcInformDissmissTeamAskWraper()
	{
		
		m_Result = -9999;
		m_LeaderRoleId = 0;

	}
	//赋值构造函数
	WGRpcInformDissmissTeamAskWraper(const WGRpcInformDissmissTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformDissmissTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformDissmissTeamAsk ToPB() const
	{
		WGRpcInformDissmissTeamAsk v;
		v.set_result( m_Result );
		v.set_leaderroleid( m_LeaderRoleId );

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
		WGRpcInformDissmissTeamAsk pb;
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
	void Init(const WGRpcInformDissmissTeamAsk& v)
	{
		m_Result = v.result();
		m_LeaderRoleId = v.leaderroleid();

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
	//LeaderRoleId
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

};
//InformApply回应封装类
class WGRpcInformApplyTeamReplyWraper
{
public:
	//构造函数
	WGRpcInformApplyTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformApplyTeamReplyWraper(const WGRpcInformApplyTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformApplyTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformApplyTeamReply ToPB() const
	{
		WGRpcInformApplyTeamReply v;
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
		WGRpcInformApplyTeamReply pb;
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
	void Init(const WGRpcInformApplyTeamReply& v)
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
//InformLogin请求封装类
class WGRpcInformLoginAskWraper
{
public:
	//构造函数
	WGRpcInformLoginAskWraper()
	{
		
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	WGRpcInformLoginAskWraper(const WGRpcInformLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformLoginAsk ToPB() const
	{
		WGRpcInformLoginAsk v;
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
		WGRpcInformLoginAsk pb;
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
	void Init(const WGRpcInformLoginAsk& v)
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
//InformLogin回应封装类
class WGRpcInformLoginReplyWraper
{
public:
	//构造函数
	WGRpcInformLoginReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformLoginReplyWraper(const WGRpcInformLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformLoginReply ToPB() const
	{
		WGRpcInformLoginReply v;
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
		WGRpcInformLoginReply pb;
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
	void Init(const WGRpcInformLoginReply& v)
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
class WGRpcAgreeTeamApplicantAskWraper
{
public:
	//构造函数
	WGRpcAgreeTeamApplicantAskWraper()
	{
		
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	WGRpcAgreeTeamApplicantAskWraper(const WGRpcAgreeTeamApplicantAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcAgreeTeamApplicantAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcAgreeTeamApplicantAsk ToPB() const
	{
		WGRpcAgreeTeamApplicantAsk v;
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
		WGRpcAgreeTeamApplicantAsk pb;
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
	void Init(const WGRpcAgreeTeamApplicantAsk& v)
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
//AgreeTeamApplicant回应封装类
class WGRpcAgreeTeamApplicantReplyWraper
{
public:
	//构造函数
	WGRpcAgreeTeamApplicantReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcAgreeTeamApplicantReplyWraper(const WGRpcAgreeTeamApplicantReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcAgreeTeamApplicantReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcAgreeTeamApplicantReply ToPB() const
	{
		WGRpcAgreeTeamApplicantReply v;
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
		WGRpcAgreeTeamApplicantReply pb;
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
	void Init(const WGRpcAgreeTeamApplicantReply& v)
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
//InformJoinTeam请求封装类
class WGRpcInformJoinTeamAskWraper
{
public:
	//构造函数
	WGRpcInformJoinTeamAskWraper()
	{
		
		m_Member = TeamMemberInfoWraper();
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	WGRpcInformJoinTeamAskWraper(const WGRpcInformJoinTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformJoinTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformJoinTeamAsk ToPB() const
	{
		WGRpcInformJoinTeamAsk v;
		*v.mutable_member()= m_Member.ToPB();
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
		WGRpcInformJoinTeamAsk pb;
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
	void Init(const WGRpcInformJoinTeamAsk& v)
	{
		m_Member = v.member();
		m_Team = v.team();

	}

private:
	//TeamMember
	TeamMemberInfoWraper m_Member;
public:
	void SetMember( const TeamMemberInfoWraper& v)
	{
		m_Member=v;
	}
	TeamMemberInfoWraper GetMember()
	{
		return m_Member;
	}
	TeamMemberInfoWraper GetMember() const
	{
		return m_Member;
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
//InformJoinTeam回应封装类
class WGRpcInformJoinTeamReplyWraper
{
public:
	//构造函数
	WGRpcInformJoinTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformJoinTeamReplyWraper(const WGRpcInformJoinTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformJoinTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformJoinTeamReply ToPB() const
	{
		WGRpcInformJoinTeamReply v;
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
		WGRpcInformJoinTeamReply pb;
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
	void Init(const WGRpcInformJoinTeamReply& v)
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
//InformCreateTeam请求封装类
class WGRpcInformCreateTeamAskWraper
{
public:
	//构造函数
	WGRpcInformCreateTeamAskWraper()
	{
		
		m_Team = TeamInfoWraper();
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformCreateTeamAskWraper(const WGRpcInformCreateTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformCreateTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformCreateTeamAsk ToPB() const
	{
		WGRpcInformCreateTeamAsk v;
		*v.mutable_team()= m_Team.ToPB();
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
		WGRpcInformCreateTeamAsk pb;
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
	void Init(const WGRpcInformCreateTeamAsk& v)
	{
		m_Team = v.team();
		m_Result = v.result();

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
//InformCreateTeam回应封装类
class WGRpcInformCreateTeamReplyWraper
{
public:
	//构造函数
	WGRpcInformCreateTeamReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformCreateTeamReplyWraper(const WGRpcInformCreateTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformCreateTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformCreateTeamReply ToPB() const
	{
		WGRpcInformCreateTeamReply v;
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
		WGRpcInformCreateTeamReply pb;
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
	void Init(const WGRpcInformCreateTeamReply& v)
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
//InformLeave请求封装类
class WGRpcInformLeaveAskWraper
{
public:
	//构造函数
	WGRpcInformLeaveAskWraper()
	{
		
		m_RoleId = 0;
		m_NewLeaderRoleId = 0;
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformLeaveAskWraper(const WGRpcInformLeaveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformLeaveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformLeaveAsk ToPB() const
	{
		WGRpcInformLeaveAsk v;
		v.set_roleid( m_RoleId );
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
		WGRpcInformLeaveAsk pb;
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
	void Init(const WGRpcInformLeaveAsk& v)
	{
		m_RoleId = v.roleid();
		m_NewLeaderRoleId = v.newleaderroleid();
		m_Result = v.result();

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
//InformAppointTeamLeader回应封装类
class WGRpcInformAppointTeamLeaderReplyWraper
{
public:
	//构造函数
	WGRpcInformAppointTeamLeaderReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformAppointTeamLeaderReplyWraper(const WGRpcInformAppointTeamLeaderReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformAppointTeamLeaderReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformAppointTeamLeaderReply ToPB() const
	{
		WGRpcInformAppointTeamLeaderReply v;
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
		WGRpcInformAppointTeamLeaderReply pb;
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
	void Init(const WGRpcInformAppointTeamLeaderReply& v)
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
//InformKickTeamMember请求封装类
class WGRpcInformKickTeamMemberAskWraper
{
public:
	//构造函数
	WGRpcInformKickTeamMemberAskWraper()
	{
		
		m_Result = -9999;
		m_KickedMemberRoleId = 0;
		m_LeaderRoleId = 0;

	}
	//赋值构造函数
	WGRpcInformKickTeamMemberAskWraper(const WGRpcInformKickTeamMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformKickTeamMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformKickTeamMemberAsk ToPB() const
	{
		WGRpcInformKickTeamMemberAsk v;
		v.set_result( m_Result );
		v.set_kickedmemberroleid( m_KickedMemberRoleId );
		v.set_leaderroleid( m_LeaderRoleId );

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
		WGRpcInformKickTeamMemberAsk pb;
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
	void Init(const WGRpcInformKickTeamMemberAsk& v)
	{
		m_Result = v.result();
		m_KickedMemberRoleId = v.kickedmemberroleid();
		m_LeaderRoleId = v.leaderroleid();

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
private:
	//LeaderRoleId
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

};
//InformLeave回应封装类
class WGRpcInformLeaveReplyWraper
{
public:
	//构造函数
	WGRpcInformLeaveReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WGRpcInformLeaveReplyWraper(const WGRpcInformLeaveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformLeaveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformLeaveReply ToPB() const
	{
		WGRpcInformLeaveReply v;
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
		WGRpcInformLeaveReply pb;
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
	void Init(const WGRpcInformLeaveReply& v)
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
//InformAppointTeamLeader请求封装类
class WGRpcInformAppointTeamLeaderAskWraper
{
public:
	//构造函数
	WGRpcInformAppointTeamLeaderAskWraper()
	{
		
		m_Result = -9999;
		m_NewLeaderRoleId = 0;
		m_OldLeaderRoleId = 0;

	}
	//赋值构造函数
	WGRpcInformAppointTeamLeaderAskWraper(const WGRpcInformAppointTeamLeaderAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WGRpcInformAppointTeamLeaderAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WGRpcInformAppointTeamLeaderAsk ToPB() const
	{
		WGRpcInformAppointTeamLeaderAsk v;
		v.set_result( m_Result );
		v.set_newleaderroleid( m_NewLeaderRoleId );
		v.set_oldleaderroleid( m_OldLeaderRoleId );

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
		WGRpcInformAppointTeamLeaderAsk pb;
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
	void Init(const WGRpcInformAppointTeamLeaderAsk& v)
	{
		m_Result = v.result();
		m_NewLeaderRoleId = v.newleaderroleid();
		m_OldLeaderRoleId = v.oldleaderroleid();

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
	//OldLeaderRoleId
	uint64_t m_OldLeaderRoleId;
public:
	void SetOldLeaderRoleId( uint64_t v)
	{
		m_OldLeaderRoleId=v;
	}
	uint64_t GetOldLeaderRoleId()
	{
		return m_OldLeaderRoleId;
	}
	uint64_t GetOldLeaderRoleId() const
	{
		return m_OldLeaderRoleId;
	}

};

template<typename T> struct MessageIdT;


#endif
