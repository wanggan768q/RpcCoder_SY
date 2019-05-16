/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTeam.h
* Author:       甘业清
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
	RPC_CODE_TEAM_LEAVETEAM_REQUEST              = 1051,	//Team-->LeaveTeam-->请求
	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST      = 1052,	//Team-->AppointTeamLeader-->请求
	RPC_CODE_TEAM_CREATETEAM_REQUEST             = 1053,	//Team-->CreateTeam-->请求
	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST           = 1054,	//Team-->DissmissTeam-->请求
	RPC_CODE_TEAM_NEWLEADER_NOTIFY               = 1055,	//Team-->NewLeader-->通知
	RPC_CODE_TEAM_KICKMEMBER_REQUEST             = 1056,	//Team-->KickMember-->请求
	RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY      = 1057,	//Team-->DissmissTeamNotify-->通知
	RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY          = 1058,	//Team-->JoinTeamNotify-->通知
	RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY        = 1059,	//Team-->KickMemberNotify-->通知
	RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY         = 1060,	//Team-->LeaveTeam-->通知
	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST        = 1061,	//Team-->SurroundingTeam-->请求
	RPC_CODE_TEAM_APPLYTEAM_REQUEST              = 1062,	//Team-->ApplyTeam-->请求
	RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY         = 1063,	//Team-->ApplyTeamNotify-->通知
	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST         = 1064,	//Team-->AgreeApplicant-->请求
	RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY    = 1065,	//Team-->AgreeApplicantNotify-->通知
	RPC_CODE_TEAM_TEAMINFO_NOTIFY                = 1066,	//Team-->TeamInfo-->通知
	RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY       = 1067,	//Team-->UpdateTeamMemInfo-->通知
	RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST       = 1068,	//Team-->跟随队长-->请求
	RPC_CODE_TEAM_SUMMONMEMBER_REQUEST           = 1069,	//Team-->召唤队员-->请求
	RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY      = 1070,	//Team-->召唤队员-->通知
	RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST       = 1071,	//Team-->改变队伍目标-->请求
	RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY  = 1072,	//Team-->设置服务器目标-->通知
	RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST          = 1073,	//Team-->转换队伍团队-->请求
	RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY    = 1074,	//Team-->转换队伍团队协议-->通知
	RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST       = 1075,	//Team-->邀请玩家-->请求
	RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY  = 1076,	//Team-->邀请玩家广播-->通知
	RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY         = 1077,	//Team-->列表通知-->通知
	RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST          = 1078,	//Team-->AgreeJoinTeam-->请求
	RPC_CODE_TEAM_REFUSEMEMBER_REQUEST           = 1079,	//Team-->拒绝申请-->请求
	RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST         = 1080,	//Team-->清空申请列表-->请求
	RPC_CODE_TEAM_NOTEAMINVITE_REQUEST           = 1081,	//Team-->没有队伍邀请玩家-->请求
	RPC_CODE_TEAM_REJECTINVITE_REQUEST           = 1082,	//Team-->拒绝邀请-->请求


};


//转换队伍团队请求封装类
class TeamRpcChangTeamTypeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangTeamTypeAskWraper()
	{
		
		m_TeamType = -1;

	}
	//赋值构造函数
	TeamRpcChangTeamTypeAskWraper(const TeamRpcChangTeamTypeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangTeamTypeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangTeamTypeAsk ToPB() const
	{
		TeamRpcChangTeamTypeAsk v;
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
		TeamRpcChangTeamTypeAsk pb;
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
	void Init(const TeamRpcChangTeamTypeAsk& v)
	{
		m_TeamType = v.teamtype();

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
//设置服务器目标通知封装类
class TeamRpcChangeTeamTargetNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTargetNotifyNotifyWraper()
	{
		
		m_TeamTarget = TeamTargetWraper();

	}
	//赋值构造函数
	TeamRpcChangeTeamTargetNotifyNotifyWraper(const TeamRpcChangeTeamTargetNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTargetNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTargetNotifyNotify ToPB() const
	{
		TeamRpcChangeTeamTargetNotifyNotify v;
		*v.mutable_teamtarget()= m_TeamTarget.ToPB();

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
		TeamRpcChangeTeamTargetNotifyNotify pb;
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
	void Init(const TeamRpcChangeTeamTargetNotifyNotify& v)
	{
		m_TeamTarget = v.teamtarget();

	}

private:
	//队伍目标
	TeamTargetWraper m_TeamTarget;
public:
	void SetTeamTarget( const TeamTargetWraper& v)
	{
		m_TeamTarget=v;
	}
	TeamTargetWraper GetTeamTarget()
	{
		return m_TeamTarget;
	}
	TeamTargetWraper GetTeamTarget() const
	{
		return m_TeamTarget;
	}

};
//改变队伍目标封装类
class TeamRpcChangeTeamTargetAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTargetAskWraper()
	{
		
		m_TargetType = -1;
		m_Id = -1;
		m_MinLevel = -1;
		m_MaxLevel = -1;

	}
	//赋值构造函数
	TeamRpcChangeTeamTargetAskWraper(const TeamRpcChangeTeamTargetAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTargetAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTargetAsk ToPB() const
	{
		TeamRpcChangeTeamTargetAsk v;
		v.set_targettype( m_TargetType );
		v.set_id( m_Id );
		v.set_minlevel( m_MinLevel );
		v.set_maxlevel( m_MaxLevel );
		v.mutable_function()->Reserve(m_Function.size());
		for (int i=0; i<(int)m_Function.size(); i++)
		{
			v.add_function(m_Function[i]);
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
		TeamRpcChangeTeamTargetAsk pb;
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
	void Init(const TeamRpcChangeTeamTargetAsk& v)
	{
		m_TargetType = v.targettype();
		m_Id = v.id();
		m_MinLevel = v.minlevel();
		m_MaxLevel = v.maxlevel();
		m_Function.clear();
		m_Function.reserve(v.function_size());
		for( int i=0; i<v.function_size(); i++)
			m_Function.push_back(v.function(i));

	}

private:
	//目标类型
	INT32 m_TargetType;
public:
	void SetTargetType( INT32 v)
	{
		m_TargetType=v;
	}
	INT32 GetTargetType()
	{
		return m_TargetType;
	}
	INT32 GetTargetType() const
	{
		return m_TargetType;
	}
private:
	//副本ID or 活动ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//最小等级
	INT32 m_MinLevel;
public:
	void SetMinLevel( INT32 v)
	{
		m_MinLevel=v;
	}
	INT32 GetMinLevel()
	{
		return m_MinLevel;
	}
	INT32 GetMinLevel() const
	{
		return m_MinLevel;
	}
private:
	//最大等级
	INT32 m_MaxLevel;
public:
	void SetMaxLevel( INT32 v)
	{
		m_MaxLevel=v;
	}
	INT32 GetMaxLevel()
	{
		return m_MaxLevel;
	}
	INT32 GetMaxLevel() const
	{
		return m_MaxLevel;
	}
private:
	//职能
	vector<INT32> m_Function;
public:
	int SizeFunction()
	{
		return m_Function.size();
	}
	const vector<INT32>& GetFunction() const
	{
		return m_Function;
	}
	INT32 GetFunction(int Index) const
	{
		if(Index<0 || Index>=(int)m_Function.size())
		{
			assert(false);
			return INT32();
		}
		return m_Function[Index];
	}
	void SetFunction( const vector<INT32>& v )
	{
		m_Function=v;
	}
	void ClearFunction( )
	{
		m_Function.clear();
	}
	void SetFunction( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_Function.size())
		{
			assert(false);
			return;
		}
		m_Function[Index] = v;
	}
	void AddFunction( INT32 v = -1 )
	{
		m_Function.push_back(v);
	}

};
//邀请玩家请求封装类
class TeamRpcInviteTeamMemberAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteTeamMemberAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcInviteTeamMemberAskWraper(const TeamRpcInviteTeamMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteTeamMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteTeamMemberAsk ToPB() const
	{
		TeamRpcInviteTeamMemberAsk v;
		v.mutable_roleid()->Reserve(m_RoleId.size());
		for (int i=0; i<(int)m_RoleId.size(); i++)
		{
			v.add_roleid(m_RoleId[i]);
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
		TeamRpcInviteTeamMemberAsk pb;
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
	void Init(const TeamRpcInviteTeamMemberAsk& v)
	{
		m_RoleId.clear();
		m_RoleId.reserve(v.roleid_size());
		for( int i=0; i<v.roleid_size(); i++)
			m_RoleId.push_back(v.roleid(i));

	}

private:
	//角色ID列表
	vector<uint64_t> m_RoleId;
public:
	int SizeRoleId()
	{
		return m_RoleId.size();
	}
	const vector<uint64_t>& GetRoleId() const
	{
		return m_RoleId;
	}
	uint64_t GetRoleId(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleId.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleId[Index];
	}
	void SetRoleId( const vector<uint64_t>& v )
	{
		m_RoleId=v;
	}
	void ClearRoleId( )
	{
		m_RoleId.clear();
	}
	void SetRoleId( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleId.size())
		{
			assert(false);
			return;
		}
		m_RoleId[Index] = v;
	}
	void AddRoleId( uint64_t v = 0 )
	{
		m_RoleId.push_back(v);
	}

};
//转换队伍团队协议通知封装类
class TeamRpcChangeTeamTypeNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTypeNotifyNotifyWraper()
	{
		
		m_TeamType = -1;
		m_TeamTarget = TeamTargetWraper();

	}
	//赋值构造函数
	TeamRpcChangeTeamTypeNotifyNotifyWraper(const TeamRpcChangeTeamTypeNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTypeNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTypeNotifyNotify ToPB() const
	{
		TeamRpcChangeTeamTypeNotifyNotify v;
		v.set_teamtype( m_TeamType );
		*v.mutable_teamtarget()= m_TeamTarget.ToPB();

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
		TeamRpcChangeTeamTypeNotifyNotify pb;
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
	void Init(const TeamRpcChangeTeamTypeNotifyNotify& v)
	{
		m_TeamType = v.teamtype();
		m_TeamTarget = v.teamtarget();

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
	//队伍目标
	TeamTargetWraper m_TeamTarget;
public:
	void SetTeamTarget( const TeamTargetWraper& v)
	{
		m_TeamTarget=v;
	}
	TeamTargetWraper GetTeamTarget()
	{
		return m_TeamTarget;
	}
	TeamTargetWraper GetTeamTarget() const
	{
		return m_TeamTarget;
	}

};
//转换队伍团队回应封装类
class TeamRpcChangTeamTypeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangTeamTypeReplyWraper()
	{
		
		m_Result = -1;
		m_TeamType = -1;
		m_TeamTarget = TeamTargetWraper();

	}
	//赋值构造函数
	TeamRpcChangTeamTypeReplyWraper(const TeamRpcChangTeamTypeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangTeamTypeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangTeamTypeReply ToPB() const
	{
		TeamRpcChangTeamTypeReply v;
		v.set_result( m_Result );
		v.set_teamtype( m_TeamType );
		*v.mutable_teamtarget()= m_TeamTarget.ToPB();

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
		TeamRpcChangTeamTypeReply pb;
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
	void Init(const TeamRpcChangTeamTypeReply& v)
	{
		m_Result = v.result();
		m_TeamType = v.teamtype();
		m_TeamTarget = v.teamtarget();

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
	//队伍目标
	TeamTargetWraper m_TeamTarget;
public:
	void SetTeamTarget( const TeamTargetWraper& v)
	{
		m_TeamTarget=v;
	}
	TeamTargetWraper GetTeamTarget()
	{
		return m_TeamTarget;
	}
	TeamTargetWraper GetTeamTarget() const
	{
		return m_TeamTarget;
	}

};
//召唤队员请求封装类
class TeamRpcSummonMemberAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcSummonMemberAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcSummonMemberAskWraper(const TeamRpcSummonMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSummonMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSummonMemberAsk ToPB() const
	{
		TeamRpcSummonMemberAsk v;

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
		TeamRpcSummonMemberAsk pb;
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
	void Init(const TeamRpcSummonMemberAsk& v)
	{

	}


};
//跟随队长回应封装类
class TeamRpcFollowTeamLeaderReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcFollowTeamLeaderReplyWraper()
	{
		
		m_Result = -1;
		m_FollowTeamLeader = -1;

	}
	//赋值构造函数
	TeamRpcFollowTeamLeaderReplyWraper(const TeamRpcFollowTeamLeaderReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcFollowTeamLeaderReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcFollowTeamLeaderReply ToPB() const
	{
		TeamRpcFollowTeamLeaderReply v;
		v.set_result( m_Result );
		v.set_followteamleader( m_FollowTeamLeader );

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
		TeamRpcFollowTeamLeaderReply pb;
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
	void Init(const TeamRpcFollowTeamLeaderReply& v)
	{
		m_Result = v.result();
		m_FollowTeamLeader = v.followteamleader();

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
	//跟随队长
	INT32 m_FollowTeamLeader;
public:
	void SetFollowTeamLeader( INT32 v)
	{
		m_FollowTeamLeader=v;
	}
	INT32 GetFollowTeamLeader()
	{
		return m_FollowTeamLeader;
	}
	INT32 GetFollowTeamLeader() const
	{
		return m_FollowTeamLeader;
	}

};
//跟随队长请求封装类
class TeamRpcFollowTeamLeaderAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcFollowTeamLeaderAskWraper()
	{
		
		m_FollowTeamLeader = -1;

	}
	//赋值构造函数
	TeamRpcFollowTeamLeaderAskWraper(const TeamRpcFollowTeamLeaderAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcFollowTeamLeaderAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcFollowTeamLeaderAsk ToPB() const
	{
		TeamRpcFollowTeamLeaderAsk v;
		v.set_followteamleader( m_FollowTeamLeader );

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
		TeamRpcFollowTeamLeaderAsk pb;
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
	void Init(const TeamRpcFollowTeamLeaderAsk& v)
	{
		m_FollowTeamLeader = v.followteamleader();

	}

private:
	//跟随队长
	INT32 m_FollowTeamLeader;
public:
	void SetFollowTeamLeader( INT32 v)
	{
		m_FollowTeamLeader=v;
	}
	INT32 GetFollowTeamLeader()
	{
		return m_FollowTeamLeader;
	}
	INT32 GetFollowTeamLeader() const
	{
		return m_FollowTeamLeader;
	}

};
//改变队伍目标封装类
class TeamRpcChangeTeamTargetReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcChangeTeamTargetReplyWraper()
	{
		
		m_Result = -1;
		m_TeamTarget = TeamTargetWraper();

	}
	//赋值构造函数
	TeamRpcChangeTeamTargetReplyWraper(const TeamRpcChangeTeamTargetReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcChangeTeamTargetReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcChangeTeamTargetReply ToPB() const
	{
		TeamRpcChangeTeamTargetReply v;
		v.set_result( m_Result );
		*v.mutable_teamtarget()= m_TeamTarget.ToPB();

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
		TeamRpcChangeTeamTargetReply pb;
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
	void Init(const TeamRpcChangeTeamTargetReply& v)
	{
		m_Result = v.result();
		m_TeamTarget = v.teamtarget();

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
	//队伍目标
	TeamTargetWraper m_TeamTarget;
public:
	void SetTeamTarget( const TeamTargetWraper& v)
	{
		m_TeamTarget=v;
	}
	TeamTargetWraper GetTeamTarget()
	{
		return m_TeamTarget;
	}
	TeamTargetWraper GetTeamTarget() const
	{
		return m_TeamTarget;
	}

};
//召唤队员通知封装类
class TeamRpcSummonMemberNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcSummonMemberNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcSummonMemberNotifyNotifyWraper(const TeamRpcSummonMemberNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSummonMemberNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSummonMemberNotifyNotify ToPB() const
	{
		TeamRpcSummonMemberNotifyNotify v;

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
		TeamRpcSummonMemberNotifyNotify pb;
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
	void Init(const TeamRpcSummonMemberNotifyNotify& v)
	{

	}


};
//召唤队员回应封装类
class TeamRpcSummonMemberReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcSummonMemberReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcSummonMemberReplyWraper(const TeamRpcSummonMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSummonMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSummonMemberReply ToPB() const
	{
		TeamRpcSummonMemberReply v;
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
		TeamRpcSummonMemberReply pb;
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
	void Init(const TeamRpcSummonMemberReply& v)
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
//邀请玩家回应封装类
class TeamRpcInviteTeamMemberReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteTeamMemberReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcInviteTeamMemberReplyWraper(const TeamRpcInviteTeamMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteTeamMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteTeamMemberReply ToPB() const
	{
		TeamRpcInviteTeamMemberReply v;
		v.set_result( m_Result );
		v.mutable_roleid()->Reserve(m_RoleId.size());
		for (int i=0; i<(int)m_RoleId.size(); i++)
		{
			v.add_roleid(m_RoleId[i]);
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
		TeamRpcInviteTeamMemberReply pb;
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
	void Init(const TeamRpcInviteTeamMemberReply& v)
	{
		m_Result = v.result();
		m_RoleId.clear();
		m_RoleId.reserve(v.roleid_size());
		for( int i=0; i<v.roleid_size(); i++)
			m_RoleId.push_back(v.roleid(i));

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
	//角色ID列表
	vector<uint64_t> m_RoleId;
public:
	int SizeRoleId()
	{
		return m_RoleId.size();
	}
	const vector<uint64_t>& GetRoleId() const
	{
		return m_RoleId;
	}
	uint64_t GetRoleId(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleId.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleId[Index];
	}
	void SetRoleId( const vector<uint64_t>& v )
	{
		m_RoleId=v;
	}
	void ClearRoleId( )
	{
		m_RoleId.clear();
	}
	void SetRoleId( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleId.size())
		{
			assert(false);
			return;
		}
		m_RoleId[Index] = v;
	}
	void AddRoleId( uint64_t v = 0 )
	{
		m_RoleId.push_back(v);
	}

};
//没有队伍邀请玩家请求封装类
class TeamRpcNoTeamInviteAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNoTeamInviteAskWraper()
	{
		
		m_TeamType = -1;
		m_TTarget = TeamTargetWraper();
		m_InviteRoleId = 0;

	}
	//赋值构造函数
	TeamRpcNoTeamInviteAskWraper(const TeamRpcNoTeamInviteAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNoTeamInviteAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNoTeamInviteAsk ToPB() const
	{
		TeamRpcNoTeamInviteAsk v;
		v.set_teamtype( m_TeamType );
		*v.mutable_ttarget()= m_TTarget.ToPB();
		v.set_inviteroleid( m_InviteRoleId );

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
		TeamRpcNoTeamInviteAsk pb;
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
	void Init(const TeamRpcNoTeamInviteAsk& v)
	{
		m_TeamType = v.teamtype();
		m_TTarget = v.ttarget();
		m_InviteRoleId = v.inviteroleid();

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
	//队伍目标
	TeamTargetWraper m_TTarget;
public:
	void SetTTarget( const TeamTargetWraper& v)
	{
		m_TTarget=v;
	}
	TeamTargetWraper GetTTarget()
	{
		return m_TTarget;
	}
	TeamTargetWraper GetTTarget() const
	{
		return m_TTarget;
	}
private:
	//邀请人id
	uint64_t m_InviteRoleId;
public:
	void SetInviteRoleId( uint64_t v)
	{
		m_InviteRoleId=v;
	}
	uint64_t GetInviteRoleId()
	{
		return m_InviteRoleId;
	}
	uint64_t GetInviteRoleId() const
	{
		return m_InviteRoleId;
	}

};
//清空申请列表请求封装类
class TeamRpcClearApplyListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcClearApplyListAskWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcClearApplyListAskWraper(const TeamRpcClearApplyListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcClearApplyListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcClearApplyListAsk ToPB() const
	{
		TeamRpcClearApplyListAsk v;

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
		TeamRpcClearApplyListAsk pb;
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
	void Init(const TeamRpcClearApplyListAsk& v)
	{

	}


};
//清空申请列表回应封装类
class TeamRpcClearApplyListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcClearApplyListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcClearApplyListReplyWraper(const TeamRpcClearApplyListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcClearApplyListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcClearApplyListReply ToPB() const
	{
		TeamRpcClearApplyListReply v;
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
		TeamRpcClearApplyListReply pb;
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
	void Init(const TeamRpcClearApplyListReply& v)
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
//拒绝邀请回应封装类
class TeamRpcRejectInviteReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcRejectInviteReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcRejectInviteReplyWraper(const TeamRpcRejectInviteReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcRejectInviteReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcRejectInviteReply ToPB() const
	{
		TeamRpcRejectInviteReply v;
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
		TeamRpcRejectInviteReply pb;
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
	void Init(const TeamRpcRejectInviteReply& v)
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
//拒绝邀请请求封装类
class TeamRpcRejectInviteAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcRejectInviteAskWraper()
	{
		
		m_RoleId = 0;
		m_Name = "";

	}
	//赋值构造函数
	TeamRpcRejectInviteAskWraper(const TeamRpcRejectInviteAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcRejectInviteAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcRejectInviteAsk ToPB() const
	{
		TeamRpcRejectInviteAsk v;
		v.set_roleid( m_RoleId );
		v.set_name( m_Name );

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
		TeamRpcRejectInviteAsk pb;
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
	void Init(const TeamRpcRejectInviteAsk& v)
	{
		m_RoleId = v.roleid();
		m_Name = v.name();

	}

private:
	//玩家名字
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
	//玩家名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}

};
//没有队伍邀请玩家回应封装类
class TeamRpcNoTeamInviteReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcNoTeamInviteReplyWraper()
	{
		
		m_Result = -1;
		m_Team = TeamInfoWraper();

	}
	//赋值构造函数
	TeamRpcNoTeamInviteReplyWraper(const TeamRpcNoTeamInviteReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcNoTeamInviteReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcNoTeamInviteReply ToPB() const
	{
		TeamRpcNoTeamInviteReply v;
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
		TeamRpcNoTeamInviteReply pb;
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
	void Init(const TeamRpcNoTeamInviteReply& v)
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
//AgreeJoinTeam请求封装类
class TeamRpcAgreeJoinTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcAgreeJoinTeamAskWraper()
	{
		
		m_TeamId = 0;
		m_IsLeader = -1;

	}
	//赋值构造函数
	TeamRpcAgreeJoinTeamAskWraper(const TeamRpcAgreeJoinTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAgreeJoinTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAgreeJoinTeamAsk ToPB() const
	{
		TeamRpcAgreeJoinTeamAsk v;
		v.set_teamid( m_TeamId );
		v.set_isleader( m_IsLeader );

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
		TeamRpcAgreeJoinTeamAsk pb;
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
	void Init(const TeamRpcAgreeJoinTeamAsk& v)
	{
		m_TeamId = v.teamid();
		m_IsLeader = v.isleader();

	}

private:
	//TeamId
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
	//IsLeader
	INT32 m_IsLeader;
public:
	void SetIsLeader( INT32 v)
	{
		m_IsLeader=v;
	}
	INT32 GetIsLeader()
	{
		return m_IsLeader;
	}
	INT32 GetIsLeader() const
	{
		return m_IsLeader;
	}

};
//列表通知通知封装类
class TeamRpcApplyListNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyListNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	TeamRpcApplyListNotifyNotifyWraper(const TeamRpcApplyListNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcApplyListNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcApplyListNotifyNotify ToPB() const
	{
		TeamRpcApplyListNotifyNotify v;
		v.mutable_applylist()->Reserve(m_ApplyList.size());
		for (int i=0; i<(int)m_ApplyList.size(); i++)
		{
			*v.add_applylist() = m_ApplyList[i].ToPB();
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
		TeamRpcApplyListNotifyNotify pb;
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
	void Init(const TeamRpcApplyListNotifyNotify& v)
	{
		m_ApplyList.clear();
		m_ApplyList.reserve(v.applylist_size());
		for( int i=0; i<v.applylist_size(); i++)
			m_ApplyList.push_back(v.applylist(i));

	}

private:
	//成员列表
	vector<TeamMemberInfoWraper> m_ApplyList;
public:
	int SizeApplyList()
	{
		return m_ApplyList.size();
	}
	const vector<TeamMemberInfoWraper>& GetApplyList() const
	{
		return m_ApplyList;
	}
	TeamMemberInfoWraper GetApplyList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return TeamMemberInfoWraper();
		}
		return m_ApplyList[Index];
	}
	void SetApplyList( const vector<TeamMemberInfoWraper>& v )
	{
		m_ApplyList=v;
	}
	void ClearApplyList( )
	{
		m_ApplyList.clear();
	}
	void SetApplyList( int Index, const TeamMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ApplyList.size())
		{
			assert(false);
			return;
		}
		m_ApplyList[Index] = v;
	}
	void AddApplyList( const TeamMemberInfoWraper& v )
	{
		m_ApplyList.push_back(v);
	}

};
//邀请玩家广播通知封装类
class TeamRpcInviteTeamMemberNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcInviteTeamMemberNotifyNotifyWraper()
	{
		
		m_TeamId = 0;
		m_IsLeader = -1;
		m_InviteMemberInfo = TeamMemberInfoWraper();

	}
	//赋值构造函数
	TeamRpcInviteTeamMemberNotifyNotifyWraper(const TeamRpcInviteTeamMemberNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcInviteTeamMemberNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcInviteTeamMemberNotifyNotify ToPB() const
	{
		TeamRpcInviteTeamMemberNotifyNotify v;
		v.set_teamid( m_TeamId );
		v.set_isleader( m_IsLeader );
		*v.mutable_invitememberinfo()= m_InviteMemberInfo.ToPB();

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
		TeamRpcInviteTeamMemberNotifyNotify pb;
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
	void Init(const TeamRpcInviteTeamMemberNotifyNotify& v)
	{
		m_TeamId = v.teamid();
		m_IsLeader = v.isleader();
		m_InviteMemberInfo = v.invitememberinfo();

	}

private:
	//队伍ID
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
	//是否队长邀请
	INT32 m_IsLeader;
public:
	void SetIsLeader( INT32 v)
	{
		m_IsLeader=v;
	}
	INT32 GetIsLeader()
	{
		return m_IsLeader;
	}
	INT32 GetIsLeader() const
	{
		return m_IsLeader;
	}
private:
	//邀请人的信息
	TeamMemberInfoWraper m_InviteMemberInfo;
public:
	void SetInviteMemberInfo( const TeamMemberInfoWraper& v)
	{
		m_InviteMemberInfo=v;
	}
	TeamMemberInfoWraper GetInviteMemberInfo()
	{
		return m_InviteMemberInfo;
	}
	TeamMemberInfoWraper GetInviteMemberInfo() const
	{
		return m_InviteMemberInfo;
	}

};
//拒绝申请回应封装类
class TeamRpcRefuseMemberReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcRefuseMemberReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcRefuseMemberReplyWraper(const TeamRpcRefuseMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcRefuseMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcRefuseMemberReply ToPB() const
	{
		TeamRpcRefuseMemberReply v;
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
		TeamRpcRefuseMemberReply pb;
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
	void Init(const TeamRpcRefuseMemberReply& v)
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
//拒绝申请请求封装类
class TeamRpcRefuseMemberAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcRefuseMemberAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	TeamRpcRefuseMemberAskWraper(const TeamRpcRefuseMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcRefuseMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcRefuseMemberAsk ToPB() const
	{
		TeamRpcRefuseMemberAsk v;
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
		TeamRpcRefuseMemberAsk pb;
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
	void Init(const TeamRpcRefuseMemberAsk& v)
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
//AgreeJoinTeam回应封装类
class TeamRpcAgreeJoinTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcAgreeJoinTeamReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TeamRpcAgreeJoinTeamReplyWraper(const TeamRpcAgreeJoinTeamReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcAgreeJoinTeamReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcAgreeJoinTeamReply ToPB() const
	{
		TeamRpcAgreeJoinTeamReply v;
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
		TeamRpcAgreeJoinTeamReply pb;
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
	void Init(const TeamRpcAgreeJoinTeamReply& v)
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
//UpdateTeamMemInfo通知封装类
class TeamRpcUpdateTeamMemInfoNotifyWraper : public DataWraperInterface 
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
//KickMember回应封装类
class TeamRpcKickMemberReplyWraper : public DataWraperInterface 
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
//KickMember请求封装类
class TeamRpcKickMemberAskWraper : public DataWraperInterface 
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
//NewLeader通知封装类
class TeamRpcNewLeaderNotifyWraper : public DataWraperInterface 
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
//AppointTeamLeader通知封装类
class TeamRpcAppointTeamLeaderNotifyWraper : public DataWraperInterface 
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
	void Init(const TeamRpcAppointTeamLeaderNotify& v)
	{

	}


};
//DissmissTeam回应封装类
class TeamRpcDissmissTeamReplyWraper : public DataWraperInterface 
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
//DissmissTeam请求封装类
class TeamRpcDissmissTeamAskWraper : public DataWraperInterface 
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
	void Init(const TeamRpcDissmissTeamAsk& v)
	{

	}


};
//LeaveTeam请求封装类
class TeamRpcLeaveTeamAskWraper : public DataWraperInterface 
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
	void Init(const TeamRpcLeaveTeamAsk& v)
	{

	}


};
//创建队伍创建副本回应封装类
class TeamRpcCreateTeamReplyWraper : public DataWraperInterface 
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
//创建队伍创建副本请求封装类
class TeamRpcCreateTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcCreateTeamAskWraper()
	{
		
		m_TeamType = -1;
		m_TTarget = TeamTargetWraper();

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
		*v.mutable_ttarget()= m_TTarget.ToPB();

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
	void Init(const TeamRpcCreateTeamAsk& v)
	{
		m_TeamType = v.teamtype();
		m_TTarget = v.ttarget();

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
	//队伍目标
	TeamTargetWraper m_TTarget;
public:
	void SetTTarget( const TeamTargetWraper& v)
	{
		m_TTarget=v;
	}
	TeamTargetWraper GetTTarget()
	{
		return m_TTarget;
	}
	TeamTargetWraper GetTTarget() const
	{
		return m_TTarget;
	}

};
//AppointTeamLeader回应封装类
class TeamRpcAppointTeamLeaderReplyWraper : public DataWraperInterface 
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
//AppointTeamLeader请求封装类
class TeamRpcAppointTeamLeaderAskWraper : public DataWraperInterface 
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
//LeaveTeam回应封装类
class TeamRpcLeaveTeamReplyWraper : public DataWraperInterface 
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
//KickMemberNotify通知封装类
class TeamRpcKickMemberNotifyNotifyWraper : public DataWraperInterface 
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
//AgreeApplicant请求封装类
class TeamRpcAgreeApplicantAskWraper : public DataWraperInterface 
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
//ApplyTeamNotify通知封装类
class TeamRpcApplyTeamNotifyNotifyWraper : public DataWraperInterface 
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
//ApplyTeam回应封装类
class TeamRpcApplyTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_TeamId = 0;

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
//TeamInfo通知封装类
class TeamRpcTeamInfoNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcTeamInfoNotifyWraper()
	{
		
		m_Team = TeamInfoWraper();
		m_FollowTeamLeader = -1;

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
		v.set_followteamleader( m_FollowTeamLeader );

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
	void Init(const TeamRpcTeamInfoNotify& v)
	{
		m_Team = v.team();
		m_FollowTeamLeader = v.followteamleader();

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
	//跟随队长
	INT32 m_FollowTeamLeader;
public:
	void SetFollowTeamLeader( INT32 v)
	{
		m_FollowTeamLeader=v;
	}
	INT32 GetFollowTeamLeader()
	{
		return m_FollowTeamLeader;
	}
	INT32 GetFollowTeamLeader() const
	{
		return m_FollowTeamLeader;
	}

};
//AgreeApplicantNotify通知封装类
class TeamRpcAgreeApplicantNotifyNotifyWraper : public DataWraperInterface 
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
//AgreeApplicant回应封装类
class TeamRpcAgreeApplicantReplyWraper : public DataWraperInterface 
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
//DissmissTeamNotify通知封装类
class TeamRpcDissmissTeamNotifyNotifyWraper : public DataWraperInterface 
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
	void Init(const TeamRpcDissmissTeamNotifyNotify& v)
	{

	}


};
//JoinTeamNotify通知封装类
class TeamRpcJoinTeamNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcJoinTeamNotifyNotifyWraper()
	{
		
		m_TeamMember = TeamMemberInfoWraper();
		m_Team = TeamInfoWraper();

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
		TeamRpcJoinTeamNotifyNotify pb;
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
	void Init(const TeamRpcJoinTeamNotifyNotify& v)
	{
		m_TeamMember = v.teammember();
		m_Team = v.team();

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
//LeaveTeam通知封装类
class TeamRpcLeaveTeamNotifyNotifyWraper : public DataWraperInterface 
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
//ApplyTeam请求封装类
class TeamRpcApplyTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcApplyTeamAskWraper()
	{
		
		m_TeamId = 0;

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
	void Init(const TeamRpcApplyTeamAsk& v)
	{
		m_TeamId = v.teamid();

	}

private:
	//TeamId
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
//SurroundingTeam回应封装类
class TeamRpcSurroundingTeamReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcSurroundingTeamReplyWraper()
	{
		
		m_Result = -9999;
		m_TargetGroupId = -1;
		m_TargetGroup = 0;

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
		v.set_targetgroupid( m_TargetGroupId );
		v.set_targetgroup( m_TargetGroup );

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
	void Init(const TeamRpcSurroundingTeamReply& v)
	{
		m_Result = v.result();
		m_TeamsInfo.clear();
		m_TeamsInfo.reserve(v.teamsinfo_size());
		for( int i=0; i<v.teamsinfo_size(); i++)
			m_TeamsInfo.push_back(v.teamsinfo(i));
		m_TargetGroupId = v.targetgroupid();
		m_TargetGroup = v.targetgroup();

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
private:
	//队伍类型
	INT32 m_TargetGroupId;
public:
	void SetTargetGroupId( INT32 v)
	{
		m_TargetGroupId=v;
	}
	INT32 GetTargetGroupId()
	{
		return m_TargetGroupId;
	}
	INT32 GetTargetGroupId() const
	{
		return m_TargetGroupId;
	}
private:
	//副本ID or 活动ID 
	INT32 m_TargetGroup;
public:
	void SetTargetGroup( INT32 v)
	{
		m_TargetGroup=v;
	}
	INT32 GetTargetGroup()
	{
		return m_TargetGroup;
	}
	INT32 GetTargetGroup() const
	{
		return m_TargetGroup;
	}

};
//SurroundingTeam请求封装类
class TeamRpcSurroundingTeamAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TeamRpcSurroundingTeamAskWraper()
	{
		
		m_TargetGroupId = -1;
		m_TargetGroup = 0;

	}
	//赋值构造函数
	TeamRpcSurroundingTeamAskWraper(const TeamRpcSurroundingTeamAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamRpcSurroundingTeamAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamRpcSurroundingTeamAsk ToPB() const
	{
		TeamRpcSurroundingTeamAsk v;
		v.set_targetgroupid( m_TargetGroupId );
		v.set_targetgroup( m_TargetGroup );

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
	void Init(const TeamRpcSurroundingTeamAsk& v)
	{
		m_TargetGroupId = v.targetgroupid();
		m_TargetGroup = v.targetgroup();

	}

private:
	//队伍类型
	INT32 m_TargetGroupId;
public:
	void SetTargetGroupId( INT32 v)
	{
		m_TargetGroupId=v;
	}
	INT32 GetTargetGroupId()
	{
		return m_TargetGroupId;
	}
	INT32 GetTargetGroupId() const
	{
		return m_TargetGroupId;
	}
private:
	//副本ID or 活动ID 
	INT32 m_TargetGroup;
public:
	void SetTargetGroup( INT32 v)
	{
		m_TargetGroup=v;
	}
	INT32 GetTargetGroup()
	{
		return m_TargetGroup;
	}
	INT32 GetTargetGroup() const
	{
		return m_TargetGroup;
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
template<> struct MessageIdT<TeamRpcSummonMemberNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcChangeTeamTargetNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcChangeTeamTypeNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcInviteTeamMemberNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcApplyListNotifyNotifyWraper>{ enum{ID=RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY};};


#endif
