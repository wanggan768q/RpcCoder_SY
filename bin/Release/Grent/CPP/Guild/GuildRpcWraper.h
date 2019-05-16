/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperGuild.h
* Author:       甘业清
* Description:  公会RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_GUILD_H
#define __RPC_WRAPER_GUILD_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "GuildRpc.pb.h"



//公会类的枚举定义
enum ConstGuildE
{
	MODULE_ID_GUILD                              = 38,	//公会模块ID
	RPC_CODE_GUILD_GUILDBASEINFO_REQUEST         = 3851,	//公会-->公会基本信息-->请求
	RPC_CODE_GUILD_KICKMEMBER_REQUEST            = 3852,	//公会-->逐出成员-->请求
	RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY       = 3853,	//公会-->逐出公会推送-->通知
	RPC_CODE_GUILD_ASKVACATION_REQUEST           = 3854,	//公会-->请假或取消申请-->请求
	RPC_CODE_GUILD_VACATION_NOTIFY               = 3855,	//公会-->请假广播（广播给管理者）-->通知
	RPC_CODE_GUILD_REPLYVACATION_NOTIFY          = 3856,	//公会-->请假广播（广播给请假人）-->通知
	RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST          = 3857,	//公会-->请求公会申请列表-->请求
	RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST   = 3858,	//公会-->入会操作-->请求
	RPC_CODE_GUILD_APPLYGUILD_NOTIFY             = 3859,	//公会-->申请入会推送（推送给申请者）-->通知
	RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST     = 3860,	//公会-->限制入会条件-->请求
	RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST   = 3861,	//公会-->权限列表申请-->请求
	RPC_CODE_GUILD_SETJURISDICTION_REQUEST       = 3862,	//公会-->设置权限-->请求
	RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST       = 3863,	//公会-->请假审批列表-->请求
	RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST= 3864,	//公会-->请假操作-->请求
	RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY     = 3865,	//公会-->申请推送（广播给管理者）-->通知
	RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST       = 3866,	//公会-->请求公会建筑信息-->请求
	RPC_CODE_GUILD_BUILDINGLVUP_REQUEST          = 3867,	//公会-->公会建筑升级-->请求
	RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST     = 3868,	//公会-->公会建筑加速升级-->请求
	RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST= 3869,	//公会-->建筑贡献榜请求-->请求
	RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY        = 3870,	//公会-->建筑可升级推送（推送管理者）-->通知
	RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST     = 3871,	//公会-->获取公会事件列表-->请求
	RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST      = 3872,	//公会-->获取公会列表-->请求
	RPC_CODE_GUILD_SEARCHGUILD_REQUEST           = 3873,	//公会-->搜索公会-->请求
	RPC_CODE_GUILD_JOINGUILD_REQUEST             = 3874,	//公会-->申请入会-->请求
	RPC_CODE_GUILD_CREATEGUILD_REQUEST           = 3875,	//公会-->建立公会-->请求
	RPC_CODE_GUILD_CHANGEFLAG_REQUEST            = 3876,	//公会-->更换公会旗帜-->请求
	RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST       = 3877,	//公会-->公会改名-->请求
	RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST        = 3878,	//公会-->获取公会成员列表-->请求
	RPC_CODE_GUILD_QUITEGUILD_REQUEST            = 3879,	//公会-->退出公会-->请求
	RPC_CODE_GUILD_SETOFFICE_REQUEST             = 3880,	//公会-->设置职位-->请求
	RPC_CODE_GUILD_OFFICECHANGE_NOTIFY           = 3881,	//公会-->职位变化推送-->通知
	RPC_CODE_GUILD_CHANGECREED_REQUEST           = 3882,	//公会-->修改帮会宗旨-->请求
	RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST         = 3883,	//公会-->公会禁言-->请求
	RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY      = 3884,	//公会-->建筑升级完成-->通知
	RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY    = 3885,	//公会-->公会货币变化推送-->通知


};


//申请入会回应封装类
class GuildRpcJoinGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcJoinGuildReplyWraper()
	{
		
		m_Result = -1;
		m_Guid = 0;

	}
	//赋值构造函数
	GuildRpcJoinGuildReplyWraper(const GuildRpcJoinGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcJoinGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcJoinGuildReply ToPB() const
	{
		GuildRpcJoinGuildReply v;
		v.set_result( m_Result );
		v.set_guid( m_Guid );

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
		GuildRpcJoinGuildReply pb;
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
	void Init(const GuildRpcJoinGuildReply& v)
	{
		m_Result = v.result();
		m_Guid = v.guid();

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
	//guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}

};
//申请入会请求封装类
class GuildRpcJoinGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcJoinGuildAskWraper()
	{
		
		m_Guid = 0;
		m_Type = -1;

	}
	//赋值构造函数
	GuildRpcJoinGuildAskWraper(const GuildRpcJoinGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcJoinGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcJoinGuildAsk ToPB() const
	{
		GuildRpcJoinGuildAsk v;
		v.set_guid( m_Guid );
		v.set_type( m_Type );

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
		GuildRpcJoinGuildAsk pb;
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
	void Init(const GuildRpcJoinGuildAsk& v)
	{
		m_Guid = v.guid();
		m_Type = v.type();

	}

private:
	//guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//1申请，2一键加入
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//搜索公会回应封装类
class GuildRpcSearchGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSearchGuildReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcSearchGuildReplyWraper(const GuildRpcSearchGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSearchGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSearchGuildReply ToPB() const
	{
		GuildRpcSearchGuildReply v;
		v.set_result( m_Result );
		v.mutable_guildinfolist()->Reserve(m_GuildInfoList.size());
		for (int i=0; i<(int)m_GuildInfoList.size(); i++)
		{
			*v.add_guildinfolist() = m_GuildInfoList[i].ToPB();
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
		GuildRpcSearchGuildReply pb;
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
	void Init(const GuildRpcSearchGuildReply& v)
	{
		m_Result = v.result();
		m_GuildInfoList.clear();
		m_GuildInfoList.reserve(v.guildinfolist_size());
		for( int i=0; i<v.guildinfolist_size(); i++)
			m_GuildInfoList.push_back(v.guildinfolist(i));

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
	//查找后的公会列表
	vector<GuildInfoWraper> m_GuildInfoList;
public:
	int SizeGuildInfoList()
	{
		return m_GuildInfoList.size();
	}
	const vector<GuildInfoWraper>& GetGuildInfoList() const
	{
		return m_GuildInfoList;
	}
	GuildInfoWraper GetGuildInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.size())
		{
			assert(false);
			return GuildInfoWraper();
		}
		return m_GuildInfoList[Index];
	}
	void SetGuildInfoList( const vector<GuildInfoWraper>& v )
	{
		m_GuildInfoList=v;
	}
	void ClearGuildInfoList( )
	{
		m_GuildInfoList.clear();
	}
	void SetGuildInfoList( int Index, const GuildInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.size())
		{
			assert(false);
			return;
		}
		m_GuildInfoList[Index] = v;
	}
	void AddGuildInfoList( const GuildInfoWraper& v )
	{
		m_GuildInfoList.push_back(v);
	}

};
//建立公会请求封装类
class GuildRpcCreateGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildAskWraper()
	{
		
		m_GuildName = "";
		m_GuildCreed = "";

	}
	//赋值构造函数
	GuildRpcCreateGuildAskWraper(const GuildRpcCreateGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildAsk ToPB() const
	{
		GuildRpcCreateGuildAsk v;
		v.set_guildname( m_GuildName );
		v.set_guildcreed( m_GuildCreed );

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
		GuildRpcCreateGuildAsk pb;
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
	void Init(const GuildRpcCreateGuildAsk& v)
	{
		m_GuildName = v.guildname();
		m_GuildCreed = v.guildcreed();

	}

private:
	//公会名称
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//公会宗旨
	string m_GuildCreed;
public:
	void SetGuildCreed( const string& v)
	{
		m_GuildCreed=v;
	}
	string GetGuildCreed()
	{
		return m_GuildCreed;
	}
	string GetGuildCreed() const
	{
		return m_GuildCreed;
	}

};
//更换公会旗帜回应封装类
class GuildRpcChangeFlagReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeFlagReplyWraper()
	{
		
		m_Result = -1;
		m_GuildMoney = -1;
		m_Flag = GuildFlagWraper();

	}
	//赋值构造函数
	GuildRpcChangeFlagReplyWraper(const GuildRpcChangeFlagReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeFlagReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeFlagReply ToPB() const
	{
		GuildRpcChangeFlagReply v;
		v.set_result( m_Result );
		v.set_guildmoney( m_GuildMoney );
		*v.mutable_flag()= m_Flag.ToPB();

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
		GuildRpcChangeFlagReply pb;
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
	void Init(const GuildRpcChangeFlagReply& v)
	{
		m_Result = v.result();
		m_GuildMoney = v.guildmoney();
		m_Flag = v.flag();

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
	//公会资金
	INT32 m_GuildMoney;
public:
	void SetGuildMoney( INT32 v)
	{
		m_GuildMoney=v;
	}
	INT32 GetGuildMoney()
	{
		return m_GuildMoney;
	}
	INT32 GetGuildMoney() const
	{
		return m_GuildMoney;
	}
private:
	//公会旗帜
	GuildFlagWraper m_Flag;
public:
	void SetFlag( const GuildFlagWraper& v)
	{
		m_Flag=v;
	}
	GuildFlagWraper GetFlag()
	{
		return m_Flag;
	}
	GuildFlagWraper GetFlag() const
	{
		return m_Flag;
	}

};
//更换公会旗帜请求封装类
class GuildRpcChangeFlagAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeFlagAskWraper()
	{
		
		m_FlagConfigID = -1;

	}
	//赋值构造函数
	GuildRpcChangeFlagAskWraper(const GuildRpcChangeFlagAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeFlagAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeFlagAsk ToPB() const
	{
		GuildRpcChangeFlagAsk v;
		v.set_flagconfigid( m_FlagConfigID );

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
		GuildRpcChangeFlagAsk pb;
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
	void Init(const GuildRpcChangeFlagAsk& v)
	{
		m_FlagConfigID = v.flagconfigid();

	}

private:
	//旗帜ID
	INT32 m_FlagConfigID;
public:
	void SetFlagConfigID( INT32 v)
	{
		m_FlagConfigID=v;
	}
	INT32 GetFlagConfigID()
	{
		return m_FlagConfigID;
	}
	INT32 GetFlagConfigID() const
	{
		return m_FlagConfigID;
	}

};
//建立公会回应封装类
class GuildRpcCreateGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcCreateGuildReplyWraper()
	{
		
		m_Result = -1;
		m_GuildBaseInfo = GuildInfoWraper();

	}
	//赋值构造函数
	GuildRpcCreateGuildReplyWraper(const GuildRpcCreateGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcCreateGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcCreateGuildReply ToPB() const
	{
		GuildRpcCreateGuildReply v;
		v.set_result( m_Result );
		*v.mutable_guildbaseinfo()= m_GuildBaseInfo.ToPB();

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
		GuildRpcCreateGuildReply pb;
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
	void Init(const GuildRpcCreateGuildReply& v)
	{
		m_Result = v.result();
		m_GuildBaseInfo = v.guildbaseinfo();

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
	//公会信息
	GuildInfoWraper m_GuildBaseInfo;
public:
	void SetGuildBaseInfo( const GuildInfoWraper& v)
	{
		m_GuildBaseInfo=v;
	}
	GuildInfoWraper GetGuildBaseInfo()
	{
		return m_GuildBaseInfo;
	}
	GuildInfoWraper GetGuildBaseInfo() const
	{
		return m_GuildBaseInfo;
	}

};
//搜索公会请求封装类
class GuildRpcSearchGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSearchGuildAskWraper()
	{
		
		m_Text = "";

	}
	//赋值构造函数
	GuildRpcSearchGuildAskWraper(const GuildRpcSearchGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSearchGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSearchGuildAsk ToPB() const
	{
		GuildRpcSearchGuildAsk v;
		v.set_text( m_Text );

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
		GuildRpcSearchGuildAsk pb;
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
	void Init(const GuildRpcSearchGuildAsk& v)
	{
		m_Text = v.text();

	}

private:
	//输入的文本
	string m_Text;
public:
	void SetText( const string& v)
	{
		m_Text=v;
	}
	string GetText()
	{
		return m_Text;
	}
	string GetText() const
	{
		return m_Text;
	}

};
//建筑可升级推送（推送管理者）通知封装类
class GuildRpcBuildingCanLvUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildingCanLvUpNotifyWraper()
	{
		
		m_BuildingType = -1;

	}
	//赋值构造函数
	GuildRpcBuildingCanLvUpNotifyWraper(const GuildRpcBuildingCanLvUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildingCanLvUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildingCanLvUpNotify ToPB() const
	{
		GuildRpcBuildingCanLvUpNotify v;
		v.set_buildingtype( m_BuildingType );

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
		GuildRpcBuildingCanLvUpNotify pb;
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
	void Init(const GuildRpcBuildingCanLvUpNotify& v)
	{
		m_BuildingType = v.buildingtype();

	}

private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}

};
//建筑贡献榜请求回应封装类
class GuildRpcAskBuildingContributionListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskBuildingContributionListReplyWraper()
	{
		
		m_Result = -1;
		m_BuildingType = -1;

	}
	//赋值构造函数
	GuildRpcAskBuildingContributionListReplyWraper(const GuildRpcAskBuildingContributionListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskBuildingContributionListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskBuildingContributionListReply ToPB() const
	{
		GuildRpcAskBuildingContributionListReply v;
		v.set_result( m_Result );
		v.mutable_contributionlist()->Reserve(m_ContributionList.size());
		for (int i=0; i<(int)m_ContributionList.size(); i++)
		{
			*v.add_contributionlist() = m_ContributionList[i].ToPB();
		}
		v.set_buildingtype( m_BuildingType );

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
		GuildRpcAskBuildingContributionListReply pb;
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
	void Init(const GuildRpcAskBuildingContributionListReply& v)
	{
		m_Result = v.result();
		m_ContributionList.clear();
		m_ContributionList.reserve(v.contributionlist_size());
		for( int i=0; i<v.contributionlist_size(); i++)
			m_ContributionList.push_back(v.contributionlist(i));
		m_BuildingType = v.buildingtype();

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
	//贡献榜列表
	vector<GuildBuildingContributionInfoWraper> m_ContributionList;
public:
	int SizeContributionList()
	{
		return m_ContributionList.size();
	}
	const vector<GuildBuildingContributionInfoWraper>& GetContributionList() const
	{
		return m_ContributionList;
	}
	GuildBuildingContributionInfoWraper GetContributionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContributionList.size())
		{
			assert(false);
			return GuildBuildingContributionInfoWraper();
		}
		return m_ContributionList[Index];
	}
	void SetContributionList( const vector<GuildBuildingContributionInfoWraper>& v )
	{
		m_ContributionList=v;
	}
	void ClearContributionList( )
	{
		m_ContributionList.clear();
	}
	void SetContributionList( int Index, const GuildBuildingContributionInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContributionList.size())
		{
			assert(false);
			return;
		}
		m_ContributionList[Index] = v;
	}
	void AddContributionList( const GuildBuildingContributionInfoWraper& v )
	{
		m_ContributionList.push_back(v);
	}
private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}

};
//建筑贡献榜请求请求封装类
class GuildRpcAskBuildingContributionListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskBuildingContributionListAskWraper()
	{
		
		m_BuildingType = -1;

	}
	//赋值构造函数
	GuildRpcAskBuildingContributionListAskWraper(const GuildRpcAskBuildingContributionListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskBuildingContributionListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskBuildingContributionListAsk ToPB() const
	{
		GuildRpcAskBuildingContributionListAsk v;
		v.set_buildingtype( m_BuildingType );

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
		GuildRpcAskBuildingContributionListAsk pb;
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
	void Init(const GuildRpcAskBuildingContributionListAsk& v)
	{
		m_BuildingType = v.buildingtype();

	}

private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}

};
//获取公会事件列表请求封装类
class GuildRpcAskGuildEventListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildEventListAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskGuildEventListAskWraper(const GuildRpcAskGuildEventListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildEventListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildEventListAsk ToPB() const
	{
		GuildRpcAskGuildEventListAsk v;

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
		GuildRpcAskGuildEventListAsk pb;
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
	void Init(const GuildRpcAskGuildEventListAsk& v)
	{

	}


};
//获取公会列表回应封装类
class GuildRpcAskGuildInfoListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildInfoListReplyWraper()
	{
		
		m_Result = -1;
		m_PageIndex = -1;
		m_TotalGuildCount = -1;

	}
	//赋值构造函数
	GuildRpcAskGuildInfoListReplyWraper(const GuildRpcAskGuildInfoListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildInfoListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildInfoListReply ToPB() const
	{
		GuildRpcAskGuildInfoListReply v;
		v.set_result( m_Result );
		v.mutable_guildinfolist()->Reserve(m_GuildInfoList.size());
		for (int i=0; i<(int)m_GuildInfoList.size(); i++)
		{
			*v.add_guildinfolist() = m_GuildInfoList[i].ToPB();
		}
		v.set_pageindex( m_PageIndex );
		v.set_totalguildcount( m_TotalGuildCount );

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
		GuildRpcAskGuildInfoListReply pb;
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
	void Init(const GuildRpcAskGuildInfoListReply& v)
	{
		m_Result = v.result();
		m_GuildInfoList.clear();
		m_GuildInfoList.reserve(v.guildinfolist_size());
		for( int i=0; i<v.guildinfolist_size(); i++)
			m_GuildInfoList.push_back(v.guildinfolist(i));
		m_PageIndex = v.pageindex();
		m_TotalGuildCount = v.totalguildcount();

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
	//公会信息列表
	vector<GuildInfoWraper> m_GuildInfoList;
public:
	int SizeGuildInfoList()
	{
		return m_GuildInfoList.size();
	}
	const vector<GuildInfoWraper>& GetGuildInfoList() const
	{
		return m_GuildInfoList;
	}
	GuildInfoWraper GetGuildInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.size())
		{
			assert(false);
			return GuildInfoWraper();
		}
		return m_GuildInfoList[Index];
	}
	void SetGuildInfoList( const vector<GuildInfoWraper>& v )
	{
		m_GuildInfoList=v;
	}
	void ClearGuildInfoList( )
	{
		m_GuildInfoList.clear();
	}
	void SetGuildInfoList( int Index, const GuildInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildInfoList.size())
		{
			assert(false);
			return;
		}
		m_GuildInfoList[Index] = v;
	}
	void AddGuildInfoList( const GuildInfoWraper& v )
	{
		m_GuildInfoList.push_back(v);
	}
private:
	//页码（索引从1开始）
	INT32 m_PageIndex;
public:
	void SetPageIndex( INT32 v)
	{
		m_PageIndex=v;
	}
	INT32 GetPageIndex()
	{
		return m_PageIndex;
	}
	INT32 GetPageIndex() const
	{
		return m_PageIndex;
	}
private:
	//本服务器公会总数
	INT32 m_TotalGuildCount;
public:
	void SetTotalGuildCount( INT32 v)
	{
		m_TotalGuildCount=v;
	}
	INT32 GetTotalGuildCount()
	{
		return m_TotalGuildCount;
	}
	INT32 GetTotalGuildCount() const
	{
		return m_TotalGuildCount;
	}

};
//获取公会列表请求封装类
class GuildRpcAskGuildInfoListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildInfoListAskWraper()
	{
		
		m_PageIndex = -1;

	}
	//赋值构造函数
	GuildRpcAskGuildInfoListAskWraper(const GuildRpcAskGuildInfoListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildInfoListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildInfoListAsk ToPB() const
	{
		GuildRpcAskGuildInfoListAsk v;
		v.set_pageindex( m_PageIndex );

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
		GuildRpcAskGuildInfoListAsk pb;
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
	void Init(const GuildRpcAskGuildInfoListAsk& v)
	{
		m_PageIndex = v.pageindex();

	}

private:
	//页码（索引从1开始）
	INT32 m_PageIndex;
public:
	void SetPageIndex( INT32 v)
	{
		m_PageIndex=v;
	}
	INT32 GetPageIndex()
	{
		return m_PageIndex;
	}
	INT32 GetPageIndex() const
	{
		return m_PageIndex;
	}

};
//获取公会事件列表回应封装类
class GuildRpcAskGuildEventListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildEventListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcAskGuildEventListReplyWraper(const GuildRpcAskGuildEventListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildEventListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildEventListReply ToPB() const
	{
		GuildRpcAskGuildEventListReply v;
		v.set_result( m_Result );
		v.mutable_guildeventlist()->Reserve(m_GuildEventList.size());
		for (int i=0; i<(int)m_GuildEventList.size(); i++)
		{
			*v.add_guildeventlist() = m_GuildEventList[i].ToPB();
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
		GuildRpcAskGuildEventListReply pb;
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
	void Init(const GuildRpcAskGuildEventListReply& v)
	{
		m_Result = v.result();
		m_GuildEventList.clear();
		m_GuildEventList.reserve(v.guildeventlist_size());
		for( int i=0; i<v.guildeventlist_size(); i++)
			m_GuildEventList.push_back(v.guildeventlist(i));

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
	//公会事件列表
	vector<GuildEventWraper> m_GuildEventList;
public:
	int SizeGuildEventList()
	{
		return m_GuildEventList.size();
	}
	const vector<GuildEventWraper>& GetGuildEventList() const
	{
		return m_GuildEventList;
	}
	GuildEventWraper GetGuildEventList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildEventList.size())
		{
			assert(false);
			return GuildEventWraper();
		}
		return m_GuildEventList[Index];
	}
	void SetGuildEventList( const vector<GuildEventWraper>& v )
	{
		m_GuildEventList=v;
	}
	void ClearGuildEventList( )
	{
		m_GuildEventList.clear();
	}
	void SetGuildEventList( int Index, const GuildEventWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildEventList.size())
		{
			assert(false);
			return;
		}
		m_GuildEventList[Index] = v;
	}
	void AddGuildEventList( const GuildEventWraper& v )
	{
		m_GuildEventList.push_back(v);
	}

};
//修改帮会宗旨回应封装类
class GuildRpcChangeCreedReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeCreedReplyWraper()
	{
		
		m_Result = -1;
		m_Content = "";

	}
	//赋值构造函数
	GuildRpcChangeCreedReplyWraper(const GuildRpcChangeCreedReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeCreedReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeCreedReply ToPB() const
	{
		GuildRpcChangeCreedReply v;
		v.set_result( m_Result );
		v.set_content( m_Content );

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
		GuildRpcChangeCreedReply pb;
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
	void Init(const GuildRpcChangeCreedReply& v)
	{
		m_Result = v.result();
		m_Content = v.content();

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
	//宗旨内容
	string m_Content;
public:
	void SetContent( const string& v)
	{
		m_Content=v;
	}
	string GetContent()
	{
		return m_Content;
	}
	string GetContent() const
	{
		return m_Content;
	}

};
//修改帮会宗旨请求封装类
class GuildRpcChangeCreedAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcChangeCreedAskWraper()
	{
		
		m_Content = "";

	}
	//赋值构造函数
	GuildRpcChangeCreedAskWraper(const GuildRpcChangeCreedAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcChangeCreedAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcChangeCreedAsk ToPB() const
	{
		GuildRpcChangeCreedAsk v;
		v.set_content( m_Content );

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
		GuildRpcChangeCreedAsk pb;
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
	void Init(const GuildRpcChangeCreedAsk& v)
	{
		m_Content = v.content();

	}

private:
	//宗旨内容
	string m_Content;
public:
	void SetContent( const string& v)
	{
		m_Content=v;
	}
	string GetContent()
	{
		return m_Content;
	}
	string GetContent() const
	{
		return m_Content;
	}

};
//职位变化推送通知封装类
class GuildRpcOfficeChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcOfficeChangeNotifyWraper()
	{
		
		m_OfficeType = -1;
		m_Optguid = 0;
		m_OptOfficeType = -1;

	}
	//赋值构造函数
	GuildRpcOfficeChangeNotifyWraper(const GuildRpcOfficeChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcOfficeChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcOfficeChangeNotify ToPB() const
	{
		GuildRpcOfficeChangeNotify v;
		v.set_officetype( m_OfficeType );
		v.set_optguid( m_Optguid );
		v.set_optofficetype( m_OptOfficeType );

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
		GuildRpcOfficeChangeNotify pb;
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
	void Init(const GuildRpcOfficeChangeNotify& v)
	{
		m_OfficeType = v.officetype();
		m_Optguid = v.optguid();
		m_OptOfficeType = v.optofficetype();

	}

private:
	//职位枚举
	INT32 m_OfficeType;
public:
	void SetOfficeType( INT32 v)
	{
		m_OfficeType=v;
	}
	INT32 GetOfficeType()
	{
		return m_OfficeType;
	}
	INT32 GetOfficeType() const
	{
		return m_OfficeType;
	}
private:
	//委任者ID
	uint64_t m_Optguid;
public:
	void SetOptguid( uint64_t v)
	{
		m_Optguid=v;
	}
	uint64_t GetOptguid()
	{
		return m_Optguid;
	}
	uint64_t GetOptguid() const
	{
		return m_Optguid;
	}
private:
	//委任者职位
	INT32 m_OptOfficeType;
public:
	void SetOptOfficeType( INT32 v)
	{
		m_OptOfficeType=v;
	}
	INT32 GetOptOfficeType()
	{
		return m_OptOfficeType;
	}
	INT32 GetOptOfficeType() const
	{
		return m_OptOfficeType;
	}

};
//公会禁言请求封装类
class GuildRpcForbiddenChatAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcForbiddenChatAskWraper()
	{
		
		m_Playerguid = -1;
		m_IsForbidden = false;

	}
	//赋值构造函数
	GuildRpcForbiddenChatAskWraper(const GuildRpcForbiddenChatAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcForbiddenChatAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcForbiddenChatAsk ToPB() const
	{
		GuildRpcForbiddenChatAsk v;
		v.set_playerguid( m_Playerguid );
		v.set_isforbidden( m_IsForbidden );

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
		GuildRpcForbiddenChatAsk pb;
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
	void Init(const GuildRpcForbiddenChatAsk& v)
	{
		m_Playerguid = v.playerguid();
		m_IsForbidden = v.isforbidden();

	}

private:
	//playerguid
	int64_t m_Playerguid;
public:
	void SetPlayerguid( int64_t v)
	{
		m_Playerguid=v;
	}
	int64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	int64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//禁言
	bool m_IsForbidden;
public:
	void SetIsForbidden( bool v)
	{
		m_IsForbidden=v;
	}
	bool GetIsForbidden()
	{
		return m_IsForbidden;
	}
	bool GetIsForbidden() const
	{
		return m_IsForbidden;
	}

};
//公会货币变化推送通知封装类
class GuildRpcGuildCurrencyChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildCurrencyChangeNotifyWraper()
	{
		
		m_GuildProsper = -1;
		m_GuildMoney = -1;
		m_GuildResource = -1;
		m_GuildWelfare = -1;
		m_MaintainCost = -1;

	}
	//赋值构造函数
	GuildRpcGuildCurrencyChangeNotifyWraper(const GuildRpcGuildCurrencyChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildCurrencyChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildCurrencyChangeNotify ToPB() const
	{
		GuildRpcGuildCurrencyChangeNotify v;
		v.set_guildprosper( m_GuildProsper );
		v.set_guildmoney( m_GuildMoney );
		v.set_guildresource( m_GuildResource );
		v.set_guildwelfare( m_GuildWelfare );
		v.set_maintaincost( m_MaintainCost );

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
		GuildRpcGuildCurrencyChangeNotify pb;
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
	void Init(const GuildRpcGuildCurrencyChangeNotify& v)
	{
		m_GuildProsper = v.guildprosper();
		m_GuildMoney = v.guildmoney();
		m_GuildResource = v.guildresource();
		m_GuildWelfare = v.guildwelfare();
		m_MaintainCost = v.maintaincost();

	}

private:
	//公会繁荣度
	INT32 m_GuildProsper;
public:
	void SetGuildProsper( INT32 v)
	{
		m_GuildProsper=v;
	}
	INT32 GetGuildProsper()
	{
		return m_GuildProsper;
	}
	INT32 GetGuildProsper() const
	{
		return m_GuildProsper;
	}
private:
	//公会资金
	INT32 m_GuildMoney;
public:
	void SetGuildMoney( INT32 v)
	{
		m_GuildMoney=v;
	}
	INT32 GetGuildMoney()
	{
		return m_GuildMoney;
	}
	INT32 GetGuildMoney() const
	{
		return m_GuildMoney;
	}
private:
	//公会资源
	INT32 m_GuildResource;
public:
	void SetGuildResource( INT32 v)
	{
		m_GuildResource=v;
	}
	INT32 GetGuildResource()
	{
		return m_GuildResource;
	}
	INT32 GetGuildResource() const
	{
		return m_GuildResource;
	}
private:
	//公会福利
	INT32 m_GuildWelfare;
public:
	void SetGuildWelfare( INT32 v)
	{
		m_GuildWelfare=v;
	}
	INT32 GetGuildWelfare()
	{
		return m_GuildWelfare;
	}
	INT32 GetGuildWelfare() const
	{
		return m_GuildWelfare;
	}
private:
	//维护费用
	INT32 m_MaintainCost;
public:
	void SetMaintainCost( INT32 v)
	{
		m_MaintainCost=v;
	}
	INT32 GetMaintainCost()
	{
		return m_MaintainCost;
	}
	INT32 GetMaintainCost() const
	{
		return m_MaintainCost;
	}

};
//建筑升级完成通知封装类
class GuildRpcBuildLvUpCompleteNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildLvUpCompleteNotifyWraper()
	{
		
		m_GuildBuildingInfo = GuildBuildingInfoWraper();

	}
	//赋值构造函数
	GuildRpcBuildLvUpCompleteNotifyWraper(const GuildRpcBuildLvUpCompleteNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildLvUpCompleteNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildLvUpCompleteNotify ToPB() const
	{
		GuildRpcBuildLvUpCompleteNotify v;
		*v.mutable_guildbuildinginfo()= m_GuildBuildingInfo.ToPB();

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
		GuildRpcBuildLvUpCompleteNotify pb;
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
	void Init(const GuildRpcBuildLvUpCompleteNotify& v)
	{
		m_GuildBuildingInfo = v.guildbuildinginfo();

	}

private:
	//公会建筑信息
	GuildBuildingInfoWraper m_GuildBuildingInfo;
public:
	void SetGuildBuildingInfo( const GuildBuildingInfoWraper& v)
	{
		m_GuildBuildingInfo=v;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo()
	{
		return m_GuildBuildingInfo;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo() const
	{
		return m_GuildBuildingInfo;
	}

};
//公会禁言回应封装类
class GuildRpcForbiddenChatReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcForbiddenChatReplyWraper()
	{
		
		m_Result = -1;
		m_Playerguid = -1;
		m_IsForbidden = false;

	}
	//赋值构造函数
	GuildRpcForbiddenChatReplyWraper(const GuildRpcForbiddenChatReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcForbiddenChatReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcForbiddenChatReply ToPB() const
	{
		GuildRpcForbiddenChatReply v;
		v.set_result( m_Result );
		v.set_playerguid( m_Playerguid );
		v.set_isforbidden( m_IsForbidden );

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
		GuildRpcForbiddenChatReply pb;
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
	void Init(const GuildRpcForbiddenChatReply& v)
	{
		m_Result = v.result();
		m_Playerguid = v.playerguid();
		m_IsForbidden = v.isforbidden();

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
	//playerguid
	int64_t m_Playerguid;
public:
	void SetPlayerguid( int64_t v)
	{
		m_Playerguid=v;
	}
	int64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	int64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//禁言
	bool m_IsForbidden;
public:
	void SetIsForbidden( bool v)
	{
		m_IsForbidden=v;
	}
	bool GetIsForbidden()
	{
		return m_IsForbidden;
	}
	bool GetIsForbidden() const
	{
		return m_IsForbidden;
	}

};
//设置职位回应封装类
class GuildRpcSetOfficeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSetOfficeReplyWraper()
	{
		
		m_Result = -1;
		m_SelfOfficeType = -1;
		m_TargetOfficeType = -1;
		m_TargetGuid = 0;

	}
	//赋值构造函数
	GuildRpcSetOfficeReplyWraper(const GuildRpcSetOfficeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSetOfficeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSetOfficeReply ToPB() const
	{
		GuildRpcSetOfficeReply v;
		v.set_result( m_Result );
		v.set_selfofficetype( m_SelfOfficeType );
		v.set_targetofficetype( m_TargetOfficeType );
		v.set_targetguid( m_TargetGuid );

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
		GuildRpcSetOfficeReply pb;
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
	void Init(const GuildRpcSetOfficeReply& v)
	{
		m_Result = v.result();
		m_SelfOfficeType = v.selfofficetype();
		m_TargetOfficeType = v.targetofficetype();
		m_TargetGuid = v.targetguid();

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
	//自己的职位枚举
	INT32 m_SelfOfficeType;
public:
	void SetSelfOfficeType( INT32 v)
	{
		m_SelfOfficeType=v;
	}
	INT32 GetSelfOfficeType()
	{
		return m_SelfOfficeType;
	}
	INT32 GetSelfOfficeType() const
	{
		return m_SelfOfficeType;
	}
private:
	//目标人的职位枚举
	INT32 m_TargetOfficeType;
public:
	void SetTargetOfficeType( INT32 v)
	{
		m_TargetOfficeType=v;
	}
	INT32 GetTargetOfficeType()
	{
		return m_TargetOfficeType;
	}
	INT32 GetTargetOfficeType() const
	{
		return m_TargetOfficeType;
	}
private:
	//guid
	uint64_t m_TargetGuid;
public:
	void SetTargetGuid( uint64_t v)
	{
		m_TargetGuid=v;
	}
	uint64_t GetTargetGuid()
	{
		return m_TargetGuid;
	}
	uint64_t GetTargetGuid() const
	{
		return m_TargetGuid;
	}

};
//获取公会成员列表请求封装类
class GuildRpcAskGuildMemberAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildMemberAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskGuildMemberAskWraper(const GuildRpcAskGuildMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildMemberAsk ToPB() const
	{
		GuildRpcAskGuildMemberAsk v;

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
		GuildRpcAskGuildMemberAsk pb;
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
	void Init(const GuildRpcAskGuildMemberAsk& v)
	{

	}


};
//公会改名回应封装类
class GuildRpcGuildChangeNameReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildChangeNameReplyWraper()
	{
		
		m_Result = -1;
		m_GuildNewName = "";
		m_GuildOldName = "";

	}
	//赋值构造函数
	GuildRpcGuildChangeNameReplyWraper(const GuildRpcGuildChangeNameReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildChangeNameReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildChangeNameReply ToPB() const
	{
		GuildRpcGuildChangeNameReply v;
		v.set_result( m_Result );
		v.set_guildnewname( m_GuildNewName );
		v.set_guildoldname( m_GuildOldName );

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
		GuildRpcGuildChangeNameReply pb;
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
	void Init(const GuildRpcGuildChangeNameReply& v)
	{
		m_Result = v.result();
		m_GuildNewName = v.guildnewname();
		m_GuildOldName = v.guildoldname();

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
	//公会新名字
	string m_GuildNewName;
public:
	void SetGuildNewName( const string& v)
	{
		m_GuildNewName=v;
	}
	string GetGuildNewName()
	{
		return m_GuildNewName;
	}
	string GetGuildNewName() const
	{
		return m_GuildNewName;
	}
private:
	//曾用名
	string m_GuildOldName;
public:
	void SetGuildOldName( const string& v)
	{
		m_GuildOldName=v;
	}
	string GetGuildOldName()
	{
		return m_GuildOldName;
	}
	string GetGuildOldName() const
	{
		return m_GuildOldName;
	}

};
//公会改名请求封装类
class GuildRpcGuildChangeNameAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildChangeNameAskWraper()
	{
		
		m_GuildNewName = "";

	}
	//赋值构造函数
	GuildRpcGuildChangeNameAskWraper(const GuildRpcGuildChangeNameAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildChangeNameAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildChangeNameAsk ToPB() const
	{
		GuildRpcGuildChangeNameAsk v;
		v.set_guildnewname( m_GuildNewName );

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
		GuildRpcGuildChangeNameAsk pb;
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
	void Init(const GuildRpcGuildChangeNameAsk& v)
	{
		m_GuildNewName = v.guildnewname();

	}

private:
	//公会新名字
	string m_GuildNewName;
public:
	void SetGuildNewName( const string& v)
	{
		m_GuildNewName=v;
	}
	string GetGuildNewName()
	{
		return m_GuildNewName;
	}
	string GetGuildNewName() const
	{
		return m_GuildNewName;
	}

};
//获取公会成员列表回应封装类
class GuildRpcAskGuildMemberReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskGuildMemberReplyWraper()
	{
		
		m_Result = -1;
		m_OnlineCount = -1;
		m_MemberCount = -1;

	}
	//赋值构造函数
	GuildRpcAskGuildMemberReplyWraper(const GuildRpcAskGuildMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskGuildMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskGuildMemberReply ToPB() const
	{
		GuildRpcAskGuildMemberReply v;
		v.set_result( m_Result );
		v.mutable_guildmemberinfolist()->Reserve(m_GuildMemberInfoList.size());
		for (int i=0; i<(int)m_GuildMemberInfoList.size(); i++)
		{
			*v.add_guildmemberinfolist() = m_GuildMemberInfoList[i].ToPB();
		}
		v.set_onlinecount( m_OnlineCount );
		v.set_membercount( m_MemberCount );

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
		GuildRpcAskGuildMemberReply pb;
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
	void Init(const GuildRpcAskGuildMemberReply& v)
	{
		m_Result = v.result();
		m_GuildMemberInfoList.clear();
		m_GuildMemberInfoList.reserve(v.guildmemberinfolist_size());
		for( int i=0; i<v.guildmemberinfolist_size(); i++)
			m_GuildMemberInfoList.push_back(v.guildmemberinfolist(i));
		m_OnlineCount = v.onlinecount();
		m_MemberCount = v.membercount();

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
	//公会成员列表信息
	vector<GuildMemberInfoWraper> m_GuildMemberInfoList;
public:
	int SizeGuildMemberInfoList()
	{
		return m_GuildMemberInfoList.size();
	}
	const vector<GuildMemberInfoWraper>& GetGuildMemberInfoList() const
	{
		return m_GuildMemberInfoList;
	}
	GuildMemberInfoWraper GetGuildMemberInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildMemberInfoList.size())
		{
			assert(false);
			return GuildMemberInfoWraper();
		}
		return m_GuildMemberInfoList[Index];
	}
	void SetGuildMemberInfoList( const vector<GuildMemberInfoWraper>& v )
	{
		m_GuildMemberInfoList=v;
	}
	void ClearGuildMemberInfoList( )
	{
		m_GuildMemberInfoList.clear();
	}
	void SetGuildMemberInfoList( int Index, const GuildMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildMemberInfoList.size())
		{
			assert(false);
			return;
		}
		m_GuildMemberInfoList[Index] = v;
	}
	void AddGuildMemberInfoList( const GuildMemberInfoWraper& v )
	{
		m_GuildMemberInfoList.push_back(v);
	}
private:
	//在线人数
	INT32 m_OnlineCount;
public:
	void SetOnlineCount( INT32 v)
	{
		m_OnlineCount=v;
	}
	INT32 GetOnlineCount()
	{
		return m_OnlineCount;
	}
	INT32 GetOnlineCount() const
	{
		return m_OnlineCount;
	}
private:
	//成员数量
	INT32 m_MemberCount;
public:
	void SetMemberCount( INT32 v)
	{
		m_MemberCount=v;
	}
	INT32 GetMemberCount()
	{
		return m_MemberCount;
	}
	INT32 GetMemberCount() const
	{
		return m_MemberCount;
	}

};
//设置职位请求封装类
class GuildRpcSetOfficeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSetOfficeAskWraper()
	{
		
		m_Guid = 0;
		m_TargetGuid = 0;
		m_OfficeType = -1;

	}
	//赋值构造函数
	GuildRpcSetOfficeAskWraper(const GuildRpcSetOfficeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSetOfficeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSetOfficeAsk ToPB() const
	{
		GuildRpcSetOfficeAsk v;
		v.set_guid( m_Guid );
		v.set_targetguid( m_TargetGuid );
		v.set_officetype( m_OfficeType );

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
		GuildRpcSetOfficeAsk pb;
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
	void Init(const GuildRpcSetOfficeAsk& v)
	{
		m_Guid = v.guid();
		m_TargetGuid = v.targetguid();
		m_OfficeType = v.officetype();

	}

private:
	//guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//guid
	uint64_t m_TargetGuid;
public:
	void SetTargetGuid( uint64_t v)
	{
		m_TargetGuid=v;
	}
	uint64_t GetTargetGuid()
	{
		return m_TargetGuid;
	}
	uint64_t GetTargetGuid() const
	{
		return m_TargetGuid;
	}
private:
	//职位枚举
	INT32 m_OfficeType;
public:
	void SetOfficeType( INT32 v)
	{
		m_OfficeType=v;
	}
	INT32 GetOfficeType()
	{
		return m_OfficeType;
	}
	INT32 GetOfficeType() const
	{
		return m_OfficeType;
	}

};
//退出公会回应封装类
class GuildRpcQuiteGuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcQuiteGuildReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcQuiteGuildReplyWraper(const GuildRpcQuiteGuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcQuiteGuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcQuiteGuildReply ToPB() const
	{
		GuildRpcQuiteGuildReply v;
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
		GuildRpcQuiteGuildReply pb;
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
	void Init(const GuildRpcQuiteGuildReply& v)
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
//退出公会请求封装类
class GuildRpcQuiteGuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcQuiteGuildAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcQuiteGuildAskWraper(const GuildRpcQuiteGuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcQuiteGuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcQuiteGuildAsk ToPB() const
	{
		GuildRpcQuiteGuildAsk v;

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
		GuildRpcQuiteGuildAsk pb;
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
	void Init(const GuildRpcQuiteGuildAsk& v)
	{

	}


};
//公会建筑加速升级回应封装类
class GuildRpcBuildingLvSpeedUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildingLvSpeedUpReplyWraper()
	{
		
		m_Result = -1;
		m_GuildBuildingInfo = GuildBuildingInfoWraper();

	}
	//赋值构造函数
	GuildRpcBuildingLvSpeedUpReplyWraper(const GuildRpcBuildingLvSpeedUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildingLvSpeedUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildingLvSpeedUpReply ToPB() const
	{
		GuildRpcBuildingLvSpeedUpReply v;
		v.set_result( m_Result );
		*v.mutable_guildbuildinginfo()= m_GuildBuildingInfo.ToPB();

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
		GuildRpcBuildingLvSpeedUpReply pb;
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
	void Init(const GuildRpcBuildingLvSpeedUpReply& v)
	{
		m_Result = v.result();
		m_GuildBuildingInfo = v.guildbuildinginfo();

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
	//公会建筑信息
	GuildBuildingInfoWraper m_GuildBuildingInfo;
public:
	void SetGuildBuildingInfo( const GuildBuildingInfoWraper& v)
	{
		m_GuildBuildingInfo=v;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo()
	{
		return m_GuildBuildingInfo;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo() const
	{
		return m_GuildBuildingInfo;
	}

};
//请求公会申请列表回应封装类
class GuildRpcAskApplyListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskApplyListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcAskApplyListReplyWraper(const GuildRpcAskApplyListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskApplyListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskApplyListReply ToPB() const
	{
		GuildRpcAskApplyListReply v;
		v.set_result( m_Result );
		v.mutable_guildmembertinyinfolist()->Reserve(m_GuildMemberTinyInfoList.size());
		for (int i=0; i<(int)m_GuildMemberTinyInfoList.size(); i++)
		{
			*v.add_guildmembertinyinfolist() = m_GuildMemberTinyInfoList[i].ToPB();
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
		GuildRpcAskApplyListReply pb;
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
	void Init(const GuildRpcAskApplyListReply& v)
	{
		m_Result = v.result();
		m_GuildMemberTinyInfoList.clear();
		m_GuildMemberTinyInfoList.reserve(v.guildmembertinyinfolist_size());
		for( int i=0; i<v.guildmembertinyinfolist_size(); i++)
			m_GuildMemberTinyInfoList.push_back(v.guildmembertinyinfolist(i));

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
	//申请入会玩家简要信息列表
	vector<GuildMemberTinyInfoWraper> m_GuildMemberTinyInfoList;
public:
	int SizeGuildMemberTinyInfoList()
	{
		return m_GuildMemberTinyInfoList.size();
	}
	const vector<GuildMemberTinyInfoWraper>& GetGuildMemberTinyInfoList() const
	{
		return m_GuildMemberTinyInfoList;
	}
	GuildMemberTinyInfoWraper GetGuildMemberTinyInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_GuildMemberTinyInfoList.size())
		{
			assert(false);
			return GuildMemberTinyInfoWraper();
		}
		return m_GuildMemberTinyInfoList[Index];
	}
	void SetGuildMemberTinyInfoList( const vector<GuildMemberTinyInfoWraper>& v )
	{
		m_GuildMemberTinyInfoList=v;
	}
	void ClearGuildMemberTinyInfoList( )
	{
		m_GuildMemberTinyInfoList.clear();
	}
	void SetGuildMemberTinyInfoList( int Index, const GuildMemberTinyInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_GuildMemberTinyInfoList.size())
		{
			assert(false);
			return;
		}
		m_GuildMemberTinyInfoList[Index] = v;
	}
	void AddGuildMemberTinyInfoList( const GuildMemberTinyInfoWraper& v )
	{
		m_GuildMemberTinyInfoList.push_back(v);
	}

};
//请求公会申请列表请求封装类
class GuildRpcAskApplyListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskApplyListAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskApplyListAskWraper(const GuildRpcAskApplyListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskApplyListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskApplyListAsk ToPB() const
	{
		GuildRpcAskApplyListAsk v;

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
		GuildRpcAskApplyListAsk pb;
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
	void Init(const GuildRpcAskApplyListAsk& v)
	{

	}


};
//请假广播（广播给请假人）通知封装类
class GuildRpcReplyVacationNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcReplyVacationNotifyWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcReplyVacationNotifyWraper(const GuildRpcReplyVacationNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcReplyVacationNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcReplyVacationNotify ToPB() const
	{
		GuildRpcReplyVacationNotify v;

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
		GuildRpcReplyVacationNotify pb;
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
	void Init(const GuildRpcReplyVacationNotify& v)
	{

	}


};
//入会操作请求封装类
class GuildRpcApplyGuildOperationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildOperationAskWraper()
	{
		
		m_Guid = 0;
		m_Operation = -1;

	}
	//赋值构造函数
	GuildRpcApplyGuildOperationAskWraper(const GuildRpcApplyGuildOperationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildOperationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildOperationAsk ToPB() const
	{
		GuildRpcApplyGuildOperationAsk v;
		v.set_guid( m_Guid );
		v.set_operation( m_Operation );

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
		GuildRpcApplyGuildOperationAsk pb;
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
	void Init(const GuildRpcApplyGuildOperationAsk& v)
	{
		m_Guid = v.guid();
		m_Operation = v.operation();

	}

private:
	//Guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	INT32 m_Operation;
public:
	void SetOperation( INT32 v)
	{
		m_Operation=v;
	}
	INT32 GetOperation()
	{
		return m_Operation;
	}
	INT32 GetOperation() const
	{
		return m_Operation;
	}

};
//限制入会条件请求封装类
class GuildRpcApplyLimitSettingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyLimitSettingAskWraper()
	{
		
		m_IsAutoJoin = false;

	}
	//赋值构造函数
	GuildRpcApplyLimitSettingAskWraper(const GuildRpcApplyLimitSettingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyLimitSettingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyLimitSettingAsk ToPB() const
	{
		GuildRpcApplyLimitSettingAsk v;
		v.set_isautojoin( m_IsAutoJoin );

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
		GuildRpcApplyLimitSettingAsk pb;
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
	void Init(const GuildRpcApplyLimitSettingAsk& v)
	{
		m_IsAutoJoin = v.isautojoin();

	}

private:
	//是否允许自动入会
	bool m_IsAutoJoin;
public:
	void SetIsAutoJoin( bool v)
	{
		m_IsAutoJoin=v;
	}
	bool GetIsAutoJoin()
	{
		return m_IsAutoJoin;
	}
	bool GetIsAutoJoin() const
	{
		return m_IsAutoJoin;
	}

};
//申请入会推送（推送给申请者）通知封装类
class GuildRpcApplyGuildNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildNotifyWraper()
	{
		
		m_GuildID = 0;
		m_GuildName = "";

	}
	//赋值构造函数
	GuildRpcApplyGuildNotifyWraper(const GuildRpcApplyGuildNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildNotify ToPB() const
	{
		GuildRpcApplyGuildNotify v;
		v.set_guildid( m_GuildID );
		v.set_guildname( m_GuildName );

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
		GuildRpcApplyGuildNotify pb;
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
	void Init(const GuildRpcApplyGuildNotify& v)
	{
		m_GuildID = v.guildid();
		m_GuildName = v.guildname();

	}

private:
	//公会ID
	uint64_t m_GuildID;
public:
	void SetGuildID( uint64_t v)
	{
		m_GuildID=v;
	}
	uint64_t GetGuildID()
	{
		return m_GuildID;
	}
	uint64_t GetGuildID() const
	{
		return m_GuildID;
	}
private:
	//公会名字
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}

};
//入会操作回应封装类
class GuildRpcApplyGuildOperationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildOperationReplyWraper()
	{
		
		m_Result = -1;
		m_Operation = -1;
		m_OnlineCount = -1;
		m_MemberCount = -1;

	}
	//赋值构造函数
	GuildRpcApplyGuildOperationReplyWraper(const GuildRpcApplyGuildOperationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildOperationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildOperationReply ToPB() const
	{
		GuildRpcApplyGuildOperationReply v;
		v.set_result( m_Result );
		v.set_operation( m_Operation );
		v.mutable_memberinfolist()->Reserve(m_MemberInfoList.size());
		for (int i=0; i<(int)m_MemberInfoList.size(); i++)
		{
			*v.add_memberinfolist() = m_MemberInfoList[i].ToPB();
		}
		v.set_onlinecount( m_OnlineCount );
		v.set_membercount( m_MemberCount );

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
		GuildRpcApplyGuildOperationReply pb;
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
	void Init(const GuildRpcApplyGuildOperationReply& v)
	{
		m_Result = v.result();
		m_Operation = v.operation();
		m_MemberInfoList.clear();
		m_MemberInfoList.reserve(v.memberinfolist_size());
		for( int i=0; i<v.memberinfolist_size(); i++)
			m_MemberInfoList.push_back(v.memberinfolist(i));
		m_OnlineCount = v.onlinecount();
		m_MemberCount = v.membercount();

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
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	INT32 m_Operation;
public:
	void SetOperation( INT32 v)
	{
		m_Operation=v;
	}
	INT32 GetOperation()
	{
		return m_Operation;
	}
	INT32 GetOperation() const
	{
		return m_Operation;
	}
private:
	//操作列表
	vector<GuildMemberInfoWraper> m_MemberInfoList;
public:
	int SizeMemberInfoList()
	{
		return m_MemberInfoList.size();
	}
	const vector<GuildMemberInfoWraper>& GetMemberInfoList() const
	{
		return m_MemberInfoList;
	}
	GuildMemberInfoWraper GetMemberInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_MemberInfoList.size())
		{
			assert(false);
			return GuildMemberInfoWraper();
		}
		return m_MemberInfoList[Index];
	}
	void SetMemberInfoList( const vector<GuildMemberInfoWraper>& v )
	{
		m_MemberInfoList=v;
	}
	void ClearMemberInfoList( )
	{
		m_MemberInfoList.clear();
	}
	void SetMemberInfoList( int Index, const GuildMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_MemberInfoList.size())
		{
			assert(false);
			return;
		}
		m_MemberInfoList[Index] = v;
	}
	void AddMemberInfoList( const GuildMemberInfoWraper& v )
	{
		m_MemberInfoList.push_back(v);
	}
private:
	//在线人数
	INT32 m_OnlineCount;
public:
	void SetOnlineCount( INT32 v)
	{
		m_OnlineCount=v;
	}
	INT32 GetOnlineCount()
	{
		return m_OnlineCount;
	}
	INT32 GetOnlineCount() const
	{
		return m_OnlineCount;
	}
private:
	//成员数量
	INT32 m_MemberCount;
public:
	void SetMemberCount( INT32 v)
	{
		m_MemberCount=v;
	}
	INT32 GetMemberCount()
	{
		return m_MemberCount;
	}
	INT32 GetMemberCount() const
	{
		return m_MemberCount;
	}

};
//请假广播通知（广播给管理者）封装类
class GuildRpcVacationNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcVacationNotifyWraper()
	{
		
		m_VacationInfo = GuildVacationInfoWraper();
		m_Type = -1;

	}
	//赋值构造函数
	GuildRpcVacationNotifyWraper(const GuildRpcVacationNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcVacationNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcVacationNotify ToPB() const
	{
		GuildRpcVacationNotify v;
		*v.mutable_vacationinfo()= m_VacationInfo.ToPB();
		v.set_type( m_Type );

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
		GuildRpcVacationNotify pb;
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
	void Init(const GuildRpcVacationNotify& v)
	{
		m_VacationInfo = v.vacationinfo();
		m_Type = v.type();

	}

private:
	//请假信息
	GuildVacationInfoWraper m_VacationInfo;
public:
	void SetVacationInfo( const GuildVacationInfoWraper& v)
	{
		m_VacationInfo=v;
	}
	GuildVacationInfoWraper GetVacationInfo()
	{
		return m_VacationInfo;
	}
	GuildVacationInfoWraper GetVacationInfo() const
	{
		return m_VacationInfo;
	}
private:
	//请假推送类型（1请假，2取消请假）
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//逐出成员请求封装类
class GuildRpcKickMemberAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKickMemberAskWraper()
	{
		
		m_Guid = -1;
		m_KickReason = "";
		m_ReasonType = -1;

	}
	//赋值构造函数
	GuildRpcKickMemberAskWraper(const GuildRpcKickMemberAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKickMemberAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKickMemberAsk ToPB() const
	{
		GuildRpcKickMemberAsk v;
		v.set_guid( m_Guid );
		v.set_kickreason( m_KickReason );
		v.set_reasontype( m_ReasonType );

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
		GuildRpcKickMemberAsk pb;
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
	void Init(const GuildRpcKickMemberAsk& v)
	{
		m_Guid = v.guid();
		m_KickReason = v.kickreason();
		m_ReasonType = v.reasontype();

	}

private:
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//逐出理由
	string m_KickReason;
public:
	void SetKickReason( const string& v)
	{
		m_KickReason=v;
	}
	string GetKickReason()
	{
		return m_KickReason;
	}
	string GetKickReason() const
	{
		return m_KickReason;
	}
private:
	//理由枚举
	INT32 m_ReasonType;
public:
	void SetReasonType( INT32 v)
	{
		m_ReasonType=v;
	}
	INT32 GetReasonType()
	{
		return m_ReasonType;
	}
	INT32 GetReasonType() const
	{
		return m_ReasonType;
	}

};
//公会基本信息回应封装类
class GuildRpcGuildBaseInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildBaseInfoReplyWraper()
	{
		
		m_Result = -1;
		m_GuildBaseInfo = GuildInfoWraper();

	}
	//赋值构造函数
	GuildRpcGuildBaseInfoReplyWraper(const GuildRpcGuildBaseInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildBaseInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildBaseInfoReply ToPB() const
	{
		GuildRpcGuildBaseInfoReply v;
		v.set_result( m_Result );
		*v.mutable_guildbaseinfo()= m_GuildBaseInfo.ToPB();

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
		GuildRpcGuildBaseInfoReply pb;
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
	void Init(const GuildRpcGuildBaseInfoReply& v)
	{
		m_Result = v.result();
		m_GuildBaseInfo = v.guildbaseinfo();

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
	//公会信息
	GuildInfoWraper m_GuildBaseInfo;
public:
	void SetGuildBaseInfo( const GuildInfoWraper& v)
	{
		m_GuildBaseInfo=v;
	}
	GuildInfoWraper GetGuildBaseInfo()
	{
		return m_GuildBaseInfo;
	}
	GuildInfoWraper GetGuildBaseInfo() const
	{
		return m_GuildBaseInfo;
	}

};
//公会基本信息请求封装类
class GuildRpcGuildBaseInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcGuildBaseInfoAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcGuildBaseInfoAskWraper(const GuildRpcGuildBaseInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcGuildBaseInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcGuildBaseInfoAsk ToPB() const
	{
		GuildRpcGuildBaseInfoAsk v;

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
		GuildRpcGuildBaseInfoAsk pb;
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
	void Init(const GuildRpcGuildBaseInfoAsk& v)
	{

	}


};
//逐出成员回应封装类
class GuildRpcKickMemberReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKickMemberReplyWraper()
	{
		
		m_Result = -1;
		m_Guid = -1;
		m_OnlineCount = -1;
		m_MemberCount = -1;

	}
	//赋值构造函数
	GuildRpcKickMemberReplyWraper(const GuildRpcKickMemberReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKickMemberReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKickMemberReply ToPB() const
	{
		GuildRpcKickMemberReply v;
		v.set_result( m_Result );
		v.set_guid( m_Guid );
		v.set_onlinecount( m_OnlineCount );
		v.set_membercount( m_MemberCount );

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
		GuildRpcKickMemberReply pb;
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
	void Init(const GuildRpcKickMemberReply& v)
	{
		m_Result = v.result();
		m_Guid = v.guid();
		m_OnlineCount = v.onlinecount();
		m_MemberCount = v.membercount();

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
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//在线人数
	INT32 m_OnlineCount;
public:
	void SetOnlineCount( INT32 v)
	{
		m_OnlineCount=v;
	}
	INT32 GetOnlineCount()
	{
		return m_OnlineCount;
	}
	INT32 GetOnlineCount() const
	{
		return m_OnlineCount;
	}
private:
	//成员数量
	INT32 m_MemberCount;
public:
	void SetMemberCount( INT32 v)
	{
		m_MemberCount=v;
	}
	INT32 GetMemberCount()
	{
		return m_MemberCount;
	}
	INT32 GetMemberCount() const
	{
		return m_MemberCount;
	}

};
//请假或取消回应封装类
class GuildRpcAskVacationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskVacationReplyWraper()
	{
		
		m_Result = -1;
		m_Guid = -1;
		m_Type = -1;

	}
	//赋值构造函数
	GuildRpcAskVacationReplyWraper(const GuildRpcAskVacationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskVacationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskVacationReply ToPB() const
	{
		GuildRpcAskVacationReply v;
		v.set_result( m_Result );
		v.set_guid( m_Guid );
		v.set_type( m_Type );

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
		GuildRpcAskVacationReply pb;
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
	void Init(const GuildRpcAskVacationReply& v)
	{
		m_Result = v.result();
		m_Guid = v.guid();
		m_Type = v.type();

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
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//请假推送类型（1请假，2取消请假）
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//请假或取消请求封装类
class GuildRpcAskVacationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskVacationAskWraper()
	{
		
		m_Guid = -1;
		m_Reason = "";
		m_Type = -1;

	}
	//赋值构造函数
	GuildRpcAskVacationAskWraper(const GuildRpcAskVacationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskVacationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskVacationAsk ToPB() const
	{
		GuildRpcAskVacationAsk v;
		v.set_guid( m_Guid );
		v.set_reason( m_Reason );
		v.set_type( m_Type );

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
		GuildRpcAskVacationAsk pb;
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
	void Init(const GuildRpcAskVacationAsk& v)
	{
		m_Guid = v.guid();
		m_Reason = v.reason();
		m_Type = v.type();

	}

private:
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//请假理由
	string m_Reason;
public:
	void SetReason( const string& v)
	{
		m_Reason=v;
	}
	string GetReason()
	{
		return m_Reason;
	}
	string GetReason() const
	{
		return m_Reason;
	}
private:
	//请假推送类型（1请假，2取消请假）
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//逐出公会推送通知封装类
class GuildRpcKickMemberNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcKickMemberNotifyNotifyWraper()
	{
		
		m_KickReason = "";
		m_ReasonType = -1;

	}
	//赋值构造函数
	GuildRpcKickMemberNotifyNotifyWraper(const GuildRpcKickMemberNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcKickMemberNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcKickMemberNotifyNotify ToPB() const
	{
		GuildRpcKickMemberNotifyNotify v;
		v.set_kickreason( m_KickReason );
		v.set_reasontype( m_ReasonType );

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
		GuildRpcKickMemberNotifyNotify pb;
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
	void Init(const GuildRpcKickMemberNotifyNotify& v)
	{
		m_KickReason = v.kickreason();
		m_ReasonType = v.reasontype();

	}

private:
	//逐出理由
	string m_KickReason;
public:
	void SetKickReason( const string& v)
	{
		m_KickReason=v;
	}
	string GetKickReason()
	{
		return m_KickReason;
	}
	string GetKickReason() const
	{
		return m_KickReason;
	}
private:
	//理由枚举
	INT32 m_ReasonType;
public:
	void SetReasonType( INT32 v)
	{
		m_ReasonType=v;
	}
	INT32 GetReasonType()
	{
		return m_ReasonType;
	}
	INT32 GetReasonType() const
	{
		return m_ReasonType;
	}

};
//请求公会建筑信息请求封装类
class GuildRpcAskBuildingInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskBuildingInfoAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskBuildingInfoAskWraper(const GuildRpcAskBuildingInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskBuildingInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskBuildingInfoAsk ToPB() const
	{
		GuildRpcAskBuildingInfoAsk v;

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
		GuildRpcAskBuildingInfoAsk pb;
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
	void Init(const GuildRpcAskBuildingInfoAsk& v)
	{

	}


};
//申请推送（广播给管理者）通知封装类
class GuildRpcApplyGuildToOfficeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyGuildToOfficeNotifyWraper()
	{
		
		m_GuildMemberTinyInfo = GuildMemberTinyInfoWraper();

	}
	//赋值构造函数
	GuildRpcApplyGuildToOfficeNotifyWraper(const GuildRpcApplyGuildToOfficeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyGuildToOfficeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyGuildToOfficeNotify ToPB() const
	{
		GuildRpcApplyGuildToOfficeNotify v;
		*v.mutable_guildmembertinyinfo()= m_GuildMemberTinyInfo.ToPB();

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
		GuildRpcApplyGuildToOfficeNotify pb;
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
	void Init(const GuildRpcApplyGuildToOfficeNotify& v)
	{
		m_GuildMemberTinyInfo = v.guildmembertinyinfo();

	}

private:
	//申请入会玩家信息
	GuildMemberTinyInfoWraper m_GuildMemberTinyInfo;
public:
	void SetGuildMemberTinyInfo( const GuildMemberTinyInfoWraper& v)
	{
		m_GuildMemberTinyInfo=v;
	}
	GuildMemberTinyInfoWraper GetGuildMemberTinyInfo()
	{
		return m_GuildMemberTinyInfo;
	}
	GuildMemberTinyInfoWraper GetGuildMemberTinyInfo() const
	{
		return m_GuildMemberTinyInfo;
	}

};
//请假操作回应封装类
class GuildRpcVacationGuildOperationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcVacationGuildOperationReplyWraper()
	{
		
		m_Result = -1;
		m_Guid = 0;
		m_Operation = -1;

	}
	//赋值构造函数
	GuildRpcVacationGuildOperationReplyWraper(const GuildRpcVacationGuildOperationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcVacationGuildOperationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcVacationGuildOperationReply ToPB() const
	{
		GuildRpcVacationGuildOperationReply v;
		v.set_result( m_Result );
		v.set_guid( m_Guid );
		v.set_operation( m_Operation );

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
		GuildRpcVacationGuildOperationReply pb;
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
	void Init(const GuildRpcVacationGuildOperationReply& v)
	{
		m_Result = v.result();
		m_Guid = v.guid();
		m_Operation = v.operation();

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
	//Guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	INT32 m_Operation;
public:
	void SetOperation( INT32 v)
	{
		m_Operation=v;
	}
	INT32 GetOperation()
	{
		return m_Operation;
	}
	INT32 GetOperation() const
	{
		return m_Operation;
	}

};
//请求公会建筑信息回应封装类
class GuildRpcAskBuildingInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskBuildingInfoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcAskBuildingInfoReplyWraper(const GuildRpcAskBuildingInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskBuildingInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskBuildingInfoReply ToPB() const
	{
		GuildRpcAskBuildingInfoReply v;
		v.set_result( m_Result );
		v.mutable_buildinginfolist()->Reserve(m_BuildingInfoList.size());
		for (int i=0; i<(int)m_BuildingInfoList.size(); i++)
		{
			*v.add_buildinginfolist() = m_BuildingInfoList[i].ToPB();
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
		GuildRpcAskBuildingInfoReply pb;
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
	void Init(const GuildRpcAskBuildingInfoReply& v)
	{
		m_Result = v.result();
		m_BuildingInfoList.clear();
		m_BuildingInfoList.reserve(v.buildinginfolist_size());
		for( int i=0; i<v.buildinginfolist_size(); i++)
			m_BuildingInfoList.push_back(v.buildinginfolist(i));

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
	//公会建筑信息列表
	vector<GuildBuildingInfoWraper> m_BuildingInfoList;
public:
	int SizeBuildingInfoList()
	{
		return m_BuildingInfoList.size();
	}
	const vector<GuildBuildingInfoWraper>& GetBuildingInfoList() const
	{
		return m_BuildingInfoList;
	}
	GuildBuildingInfoWraper GetBuildingInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuildingInfoList.size())
		{
			assert(false);
			return GuildBuildingInfoWraper();
		}
		return m_BuildingInfoList[Index];
	}
	void SetBuildingInfoList( const vector<GuildBuildingInfoWraper>& v )
	{
		m_BuildingInfoList=v;
	}
	void ClearBuildingInfoList( )
	{
		m_BuildingInfoList.clear();
	}
	void SetBuildingInfoList( int Index, const GuildBuildingInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_BuildingInfoList.size())
		{
			assert(false);
			return;
		}
		m_BuildingInfoList[Index] = v;
	}
	void AddBuildingInfoList( const GuildBuildingInfoWraper& v )
	{
		m_BuildingInfoList.push_back(v);
	}

};
//公会建筑加速升级请求封装类
class GuildRpcBuildingLvSpeedUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildingLvSpeedUpAskWraper()
	{
		
		m_BuildingType = -1;
		m_Time = -1;

	}
	//赋值构造函数
	GuildRpcBuildingLvSpeedUpAskWraper(const GuildRpcBuildingLvSpeedUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildingLvSpeedUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildingLvSpeedUpAsk ToPB() const
	{
		GuildRpcBuildingLvSpeedUpAsk v;
		v.set_buildingtype( m_BuildingType );
		v.set_time( m_Time );

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
		GuildRpcBuildingLvSpeedUpAsk pb;
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
	void Init(const GuildRpcBuildingLvSpeedUpAsk& v)
	{
		m_BuildingType = v.buildingtype();
		m_Time = v.time();

	}

private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}
private:
	//加速时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//公会建筑升级回应封装类
class GuildRpcBuildingLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildingLvUpReplyWraper()
	{
		
		m_Result = -1;
		m_GuildBuildingInfo = GuildBuildingInfoWraper();
		m_GuildMoney = -1;
		m_GuildResource = -1;

	}
	//赋值构造函数
	GuildRpcBuildingLvUpReplyWraper(const GuildRpcBuildingLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildingLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildingLvUpReply ToPB() const
	{
		GuildRpcBuildingLvUpReply v;
		v.set_result( m_Result );
		*v.mutable_guildbuildinginfo()= m_GuildBuildingInfo.ToPB();
		v.set_guildmoney( m_GuildMoney );
		v.set_guildresource( m_GuildResource );

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
		GuildRpcBuildingLvUpReply pb;
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
	void Init(const GuildRpcBuildingLvUpReply& v)
	{
		m_Result = v.result();
		m_GuildBuildingInfo = v.guildbuildinginfo();
		m_GuildMoney = v.guildmoney();
		m_GuildResource = v.guildresource();

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
	//公会建筑信息
	GuildBuildingInfoWraper m_GuildBuildingInfo;
public:
	void SetGuildBuildingInfo( const GuildBuildingInfoWraper& v)
	{
		m_GuildBuildingInfo=v;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo()
	{
		return m_GuildBuildingInfo;
	}
	GuildBuildingInfoWraper GetGuildBuildingInfo() const
	{
		return m_GuildBuildingInfo;
	}
private:
	//公会资金
	INT32 m_GuildMoney;
public:
	void SetGuildMoney( INT32 v)
	{
		m_GuildMoney=v;
	}
	INT32 GetGuildMoney()
	{
		return m_GuildMoney;
	}
	INT32 GetGuildMoney() const
	{
		return m_GuildMoney;
	}
private:
	//公会资源
	INT32 m_GuildResource;
public:
	void SetGuildResource( INT32 v)
	{
		m_GuildResource=v;
	}
	INT32 GetGuildResource()
	{
		return m_GuildResource;
	}
	INT32 GetGuildResource() const
	{
		return m_GuildResource;
	}

};
//公会建筑升级请求封装类
class GuildRpcBuildingLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcBuildingLvUpAskWraper()
	{
		
		m_BuildingType = -1;

	}
	//赋值构造函数
	GuildRpcBuildingLvUpAskWraper(const GuildRpcBuildingLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcBuildingLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcBuildingLvUpAsk ToPB() const
	{
		GuildRpcBuildingLvUpAsk v;
		v.set_buildingtype( m_BuildingType );

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
		GuildRpcBuildingLvUpAsk pb;
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
	void Init(const GuildRpcBuildingLvUpAsk& v)
	{
		m_BuildingType = v.buildingtype();

	}

private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}

};
//请假操作请求封装类
class GuildRpcVacationGuildOperationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcVacationGuildOperationAskWraper()
	{
		
		m_Guid = 0;
		m_Operation = -1;

	}
	//赋值构造函数
	GuildRpcVacationGuildOperationAskWraper(const GuildRpcVacationGuildOperationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcVacationGuildOperationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcVacationGuildOperationAsk ToPB() const
	{
		GuildRpcVacationGuildOperationAsk v;
		v.set_guid( m_Guid );
		v.set_operation( m_Operation );

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
		GuildRpcVacationGuildOperationAsk pb;
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
	void Init(const GuildRpcVacationGuildOperationAsk& v)
	{
		m_Guid = v.guid();
		m_Operation = v.operation();

	}

private:
	//Guid
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//操作信息（1同意，2拒绝，3一键同意，4一键拒绝）
	INT32 m_Operation;
public:
	void SetOperation( INT32 v)
	{
		m_Operation=v;
	}
	INT32 GetOperation()
	{
		return m_Operation;
	}
	INT32 GetOperation() const
	{
		return m_Operation;
	}

};
//权限列表申请回应封装类
class GuildRpcAskJurisdictionListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskJurisdictionListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcAskJurisdictionListReplyWraper(const GuildRpcAskJurisdictionListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskJurisdictionListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskJurisdictionListReply ToPB() const
	{
		GuildRpcAskJurisdictionListReply v;
		v.set_result( m_Result );
		v.mutable_jurisdictionlist()->Reserve(m_JurisdictionList.size());
		for (int i=0; i<(int)m_JurisdictionList.size(); i++)
		{
			*v.add_jurisdictionlist() = m_JurisdictionList[i].ToPB();
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
		GuildRpcAskJurisdictionListReply pb;
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
	void Init(const GuildRpcAskJurisdictionListReply& v)
	{
		m_Result = v.result();
		m_JurisdictionList.clear();
		m_JurisdictionList.reserve(v.jurisdictionlist_size());
		for( int i=0; i<v.jurisdictionlist_size(); i++)
			m_JurisdictionList.push_back(v.jurisdictionlist(i));

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
	//权限列表
	vector<GuildOfficeJurisdictionWraper> m_JurisdictionList;
public:
	int SizeJurisdictionList()
	{
		return m_JurisdictionList.size();
	}
	const vector<GuildOfficeJurisdictionWraper>& GetJurisdictionList() const
	{
		return m_JurisdictionList;
	}
	GuildOfficeJurisdictionWraper GetJurisdictionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.size())
		{
			assert(false);
			return GuildOfficeJurisdictionWraper();
		}
		return m_JurisdictionList[Index];
	}
	void SetJurisdictionList( const vector<GuildOfficeJurisdictionWraper>& v )
	{
		m_JurisdictionList=v;
	}
	void ClearJurisdictionList( )
	{
		m_JurisdictionList.clear();
	}
	void SetJurisdictionList( int Index, const GuildOfficeJurisdictionWraper& v )
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.size())
		{
			assert(false);
			return;
		}
		m_JurisdictionList[Index] = v;
	}
	void AddJurisdictionList( const GuildOfficeJurisdictionWraper& v )
	{
		m_JurisdictionList.push_back(v);
	}

};
//权限列表申请请求封装类
class GuildRpcAskJurisdictionListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskJurisdictionListAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskJurisdictionListAskWraper(const GuildRpcAskJurisdictionListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskJurisdictionListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskJurisdictionListAsk ToPB() const
	{
		GuildRpcAskJurisdictionListAsk v;

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
		GuildRpcAskJurisdictionListAsk pb;
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
	void Init(const GuildRpcAskJurisdictionListAsk& v)
	{

	}


};
//限制入会条件回应封装类
class GuildRpcApplyLimitSettingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcApplyLimitSettingReplyWraper()
	{
		
		m_Result = -1;
		m_IsAutoJoin = false;

	}
	//赋值构造函数
	GuildRpcApplyLimitSettingReplyWraper(const GuildRpcApplyLimitSettingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcApplyLimitSettingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcApplyLimitSettingReply ToPB() const
	{
		GuildRpcApplyLimitSettingReply v;
		v.set_result( m_Result );
		v.set_isautojoin( m_IsAutoJoin );

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
		GuildRpcApplyLimitSettingReply pb;
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
	void Init(const GuildRpcApplyLimitSettingReply& v)
	{
		m_Result = v.result();
		m_IsAutoJoin = v.isautojoin();

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
	//是否允许自动入会
	bool m_IsAutoJoin;
public:
	void SetIsAutoJoin( bool v)
	{
		m_IsAutoJoin=v;
	}
	bool GetIsAutoJoin()
	{
		return m_IsAutoJoin;
	}
	bool GetIsAutoJoin() const
	{
		return m_IsAutoJoin;
	}

};
//设置权限请求封装类
class GuildRpcSetJurisdictionAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSetJurisdictionAskWraper()
	{
		
		m_SetList = GuildOfficeJurisdictionWraper();

	}
	//赋值构造函数
	GuildRpcSetJurisdictionAskWraper(const GuildRpcSetJurisdictionAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSetJurisdictionAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSetJurisdictionAsk ToPB() const
	{
		GuildRpcSetJurisdictionAsk v;
		*v.mutable_setlist()= m_SetList.ToPB();

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
		GuildRpcSetJurisdictionAsk pb;
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
	void Init(const GuildRpcSetJurisdictionAsk& v)
	{
		m_SetList = v.setlist();

	}

private:
	//权限列表
	GuildOfficeJurisdictionWraper m_SetList;
public:
	void SetSetList( const GuildOfficeJurisdictionWraper& v)
	{
		m_SetList=v;
	}
	GuildOfficeJurisdictionWraper GetSetList()
	{
		return m_SetList;
	}
	GuildOfficeJurisdictionWraper GetSetList() const
	{
		return m_SetList;
	}

};
//请假审批列表回应封装类
class GuildRpcAskVacationListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskVacationListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GuildRpcAskVacationListReplyWraper(const GuildRpcAskVacationListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskVacationListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskVacationListReply ToPB() const
	{
		GuildRpcAskVacationListReply v;
		v.set_result( m_Result );
		v.mutable_vacationlist()->Reserve(m_VacationList.size());
		for (int i=0; i<(int)m_VacationList.size(); i++)
		{
			*v.add_vacationlist() = m_VacationList[i].ToPB();
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
		GuildRpcAskVacationListReply pb;
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
	void Init(const GuildRpcAskVacationListReply& v)
	{
		m_Result = v.result();
		m_VacationList.clear();
		m_VacationList.reserve(v.vacationlist_size());
		for( int i=0; i<v.vacationlist_size(); i++)
			m_VacationList.push_back(v.vacationlist(i));

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
	//请假列表
	vector<GuildVacationInfoWraper> m_VacationList;
public:
	int SizeVacationList()
	{
		return m_VacationList.size();
	}
	const vector<GuildVacationInfoWraper>& GetVacationList() const
	{
		return m_VacationList;
	}
	GuildVacationInfoWraper GetVacationList(int Index) const
	{
		if(Index<0 || Index>=(int)m_VacationList.size())
		{
			assert(false);
			return GuildVacationInfoWraper();
		}
		return m_VacationList[Index];
	}
	void SetVacationList( const vector<GuildVacationInfoWraper>& v )
	{
		m_VacationList=v;
	}
	void ClearVacationList( )
	{
		m_VacationList.clear();
	}
	void SetVacationList( int Index, const GuildVacationInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_VacationList.size())
		{
			assert(false);
			return;
		}
		m_VacationList[Index] = v;
	}
	void AddVacationList( const GuildVacationInfoWraper& v )
	{
		m_VacationList.push_back(v);
	}

};
//请假审批列表请求封装类
class GuildRpcAskVacationListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcAskVacationListAskWraper()
	{
		

	}
	//赋值构造函数
	GuildRpcAskVacationListAskWraper(const GuildRpcAskVacationListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcAskVacationListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcAskVacationListAsk ToPB() const
	{
		GuildRpcAskVacationListAsk v;

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
		GuildRpcAskVacationListAsk pb;
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
	void Init(const GuildRpcAskVacationListAsk& v)
	{

	}


};
//设置权限回应封装类
class GuildRpcSetJurisdictionReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GuildRpcSetJurisdictionReplyWraper()
	{
		
		m_Result = -1;
		m_SetList = GuildOfficeJurisdictionWraper();

	}
	//赋值构造函数
	GuildRpcSetJurisdictionReplyWraper(const GuildRpcSetJurisdictionReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildRpcSetJurisdictionReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildRpcSetJurisdictionReply ToPB() const
	{
		GuildRpcSetJurisdictionReply v;
		v.set_result( m_Result );
		*v.mutable_setlist()= m_SetList.ToPB();

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
		GuildRpcSetJurisdictionReply pb;
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
	void Init(const GuildRpcSetJurisdictionReply& v)
	{
		m_Result = v.result();
		m_SetList = v.setlist();

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
	//权限列表
	GuildOfficeJurisdictionWraper m_SetList;
public:
	void SetSetList( const GuildOfficeJurisdictionWraper& v)
	{
		m_SetList=v;
	}
	GuildOfficeJurisdictionWraper GetSetList()
	{
		return m_SetList;
	}
	GuildOfficeJurisdictionWraper GetSetList() const
	{
		return m_SetList;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<GuildRpcKickMemberNotifyNotifyWraper>{ enum{ID=RPC_CODE_GUILD_KICKMEMBERNOTIFY_NOTIFY};};
template<> struct MessageIdT<GuildRpcVacationNotifyWraper>{ enum{ID=RPC_CODE_GUILD_VACATION_NOTIFY};};
template<> struct MessageIdT<GuildRpcReplyVacationNotifyWraper>{ enum{ID=RPC_CODE_GUILD_REPLYVACATION_NOTIFY};};
template<> struct MessageIdT<GuildRpcApplyGuildNotifyWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILD_NOTIFY};};
template<> struct MessageIdT<GuildRpcApplyGuildToOfficeNotifyWraper>{ enum{ID=RPC_CODE_GUILD_APPLYGUILDTOOFFICE_NOTIFY};};
template<> struct MessageIdT<GuildRpcBuildingCanLvUpNotifyWraper>{ enum{ID=RPC_CODE_GUILD_BUILDINGCANLVUP_NOTIFY};};
template<> struct MessageIdT<GuildRpcOfficeChangeNotifyWraper>{ enum{ID=RPC_CODE_GUILD_OFFICECHANGE_NOTIFY};};
template<> struct MessageIdT<GuildRpcBuildLvUpCompleteNotifyWraper>{ enum{ID=RPC_CODE_GUILD_BUILDLVUPCOMPLETE_NOTIFY};};
template<> struct MessageIdT<GuildRpcGuildCurrencyChangeNotifyWraper>{ enum{ID=RPC_CODE_GUILD_GUILDCURRENCYCHANGE_NOTIFY};};


#endif
