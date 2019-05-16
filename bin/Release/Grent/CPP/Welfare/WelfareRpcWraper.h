/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperWelfare.h
* Author:       甘业清
* Description:  福利RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_WELFARE_H
#define __RPC_WRAPER_WELFARE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "WelfareRpc.pb.h"



//福利类的枚举定义
enum ConstWelfareE
{
	MODULE_ID_WELFARE                            = 42,	//福利模块ID
	RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST    = 4251,	//福利-->累计登陆福利-->请求
	RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST = 4252,	//福利-->领取累计登陆奖励-->请求
	RPC_CODE_WELFARE_ONLINEBONUS_REQUEST         = 4253,	//福利-->今日在线福利-->请求
	RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST     = 4254,	//福利-->领取今日在线奖励-->请求
	RPC_CODE_WELFARE_LEVELBONUS_REQUEST          = 4255,	//福利-->等级福利-->请求
	RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST    = 4256,	//福利-->领取等级福利奖励-->请求
	RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST    = 4257,	//福利-->签到福利-->请求
	RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST   = 4258,	//福利-->签到-->请求
	RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY          = 4259,	//福利-->今日签到提醒-->通知
	RPC_CODE_WELFARE_SPECLOGIN_NOTIFY            = 4260,	//福利-->运营登录活动-->通知
	RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST     = 4261,	//福利-->运营登录活动领取奖励-->请求


};


//签到福利回应封装类
class WelfareRpcMonthSignInBonusReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcMonthSignInBonusReplyWraper()
	{
		
		m_Result = -1;
		m_Year = -1;
		m_Month = -1;
		m_Date = -1;
		m_FixSignInTimes = -1;
		m_Day = -1;
		m_TodaySignIn = false;
		m_FixSignInDays = -1;

	}
	//赋值构造函数
	WelfareRpcMonthSignInBonusReplyWraper(const WelfareRpcMonthSignInBonusReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcMonthSignInBonusReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcMonthSignInBonusReply ToPB() const
	{
		WelfareRpcMonthSignInBonusReply v;
		v.set_result( m_Result );
		v.set_year( m_Year );
		v.set_month( m_Month );
		v.set_date( m_Date );
		v.set_fixsignintimes( m_FixSignInTimes );
		v.mutable_monthsigninlist()->Reserve(m_MonthSignInList.size());
		for (int i=0; i<(int)m_MonthSignInList.size(); i++)
		{
			*v.add_monthsigninlist() = m_MonthSignInList[i].ToPB();
		}
		v.set_day( m_Day );
		v.set_todaysignin( m_TodaySignIn );
		v.set_fixsignindays( m_FixSignInDays );

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
		WelfareRpcMonthSignInBonusReply pb;
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
	void Init(const WelfareRpcMonthSignInBonusReply& v)
	{
		m_Result = v.result();
		m_Year = v.year();
		m_Month = v.month();
		m_Date = v.date();
		m_FixSignInTimes = v.fixsignintimes();
		m_MonthSignInList.clear();
		m_MonthSignInList.reserve(v.monthsigninlist_size());
		for( int i=0; i<v.monthsigninlist_size(); i++)
			m_MonthSignInList.push_back(v.monthsigninlist(i));
		m_Day = v.day();
		m_TodaySignIn = v.todaysignin();
		m_FixSignInDays = v.fixsignindays();

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
	//年
	INT32 m_Year;
public:
	void SetYear( INT32 v)
	{
		m_Year=v;
	}
	INT32 GetYear()
	{
		return m_Year;
	}
	INT32 GetYear() const
	{
		return m_Year;
	}
private:
	//月
	INT32 m_Month;
public:
	void SetMonth( INT32 v)
	{
		m_Month=v;
	}
	INT32 GetMonth()
	{
		return m_Month;
	}
	INT32 GetMonth() const
	{
		return m_Month;
	}
private:
	//日
	INT32 m_Date;
public:
	void SetDate( INT32 v)
	{
		m_Date=v;
	}
	INT32 GetDate()
	{
		return m_Date;
	}
	INT32 GetDate() const
	{
		return m_Date;
	}
private:
	//补签剩余次数
	INT32 m_FixSignInTimes;
public:
	void SetFixSignInTimes( INT32 v)
	{
		m_FixSignInTimes=v;
	}
	INT32 GetFixSignInTimes()
	{
		return m_FixSignInTimes;
	}
	INT32 GetFixSignInTimes() const
	{
		return m_FixSignInTimes;
	}
private:
	//签到福利信息
	vector<MonthSignInInfoWraper> m_MonthSignInList;
public:
	int SizeMonthSignInList()
	{
		return m_MonthSignInList.size();
	}
	const vector<MonthSignInInfoWraper>& GetMonthSignInList() const
	{
		return m_MonthSignInList;
	}
	MonthSignInInfoWraper GetMonthSignInList(int Index) const
	{
		if(Index<0 || Index>=(int)m_MonthSignInList.size())
		{
			assert(false);
			return MonthSignInInfoWraper();
		}
		return m_MonthSignInList[Index];
	}
	void SetMonthSignInList( const vector<MonthSignInInfoWraper>& v )
	{
		m_MonthSignInList=v;
	}
	void ClearMonthSignInList( )
	{
		m_MonthSignInList.clear();
	}
	void SetMonthSignInList( int Index, const MonthSignInInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_MonthSignInList.size())
		{
			assert(false);
			return;
		}
		m_MonthSignInList[Index] = v;
	}
	void AddMonthSignInList( const MonthSignInInfoWraper& v )
	{
		m_MonthSignInList.push_back(v);
	}
private:
	//周几
	INT32 m_Day;
public:
	void SetDay( INT32 v)
	{
		m_Day=v;
	}
	INT32 GetDay()
	{
		return m_Day;
	}
	INT32 GetDay() const
	{
		return m_Day;
	}
private:
	//今天是否签到
	bool m_TodaySignIn;
public:
	void SetTodaySignIn( bool v)
	{
		m_TodaySignIn=v;
	}
	bool GetTodaySignIn()
	{
		return m_TodaySignIn;
	}
	bool GetTodaySignIn() const
	{
		return m_TodaySignIn;
	}
private:
	//可补签的最后一天
	INT32 m_FixSignInDays;
public:
	void SetFixSignInDays( INT32 v)
	{
		m_FixSignInDays=v;
	}
	INT32 GetFixSignInDays()
	{
		return m_FixSignInDays;
	}
	INT32 GetFixSignInDays() const
	{
		return m_FixSignInDays;
	}

};
//签到请求封装类
class WelfareRpcMonthSignInRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcMonthSignInRewardAskWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	WelfareRpcMonthSignInRewardAskWraper(const WelfareRpcMonthSignInRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcMonthSignInRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcMonthSignInRewardAsk ToPB() const
	{
		WelfareRpcMonthSignInRewardAsk v;
		v.set_id( m_ID );

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
		WelfareRpcMonthSignInRewardAsk pb;
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
	void Init(const WelfareRpcMonthSignInRewardAsk& v)
	{
		m_ID = v.id();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//签到福利请求封装类
class WelfareRpcMonthSignInBonusAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcMonthSignInBonusAskWraper()
	{
		

	}
	//赋值构造函数
	WelfareRpcMonthSignInBonusAskWraper(const WelfareRpcMonthSignInBonusAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcMonthSignInBonusAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcMonthSignInBonusAsk ToPB() const
	{
		WelfareRpcMonthSignInBonusAsk v;

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
		WelfareRpcMonthSignInBonusAsk pb;
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
	void Init(const WelfareRpcMonthSignInBonusAsk& v)
	{

	}


};
//领取等级福利奖励请求封装类
class WelfareRpcLevelBonusRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcLevelBonusRewardAskWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	WelfareRpcLevelBonusRewardAskWraper(const WelfareRpcLevelBonusRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcLevelBonusRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcLevelBonusRewardAsk ToPB() const
	{
		WelfareRpcLevelBonusRewardAsk v;
		v.set_id( m_ID );

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
		WelfareRpcLevelBonusRewardAsk pb;
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
	void Init(const WelfareRpcLevelBonusRewardAsk& v)
	{
		m_ID = v.id();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//领取等级福利奖励回应封装类
class WelfareRpcLevelBonusRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcLevelBonusRewardReplyWraper()
	{
		
		m_Result = -1;
		m_RewardID = -1;

	}
	//赋值构造函数
	WelfareRpcLevelBonusRewardReplyWraper(const WelfareRpcLevelBonusRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcLevelBonusRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcLevelBonusRewardReply ToPB() const
	{
		WelfareRpcLevelBonusRewardReply v;
		v.set_result( m_Result );
		v.set_rewardid( m_RewardID );

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
		WelfareRpcLevelBonusRewardReply pb;
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
	void Init(const WelfareRpcLevelBonusRewardReply& v)
	{
		m_Result = v.result();
		m_RewardID = v.rewardid();

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
	//奖励ID
	INT32 m_RewardID;
public:
	void SetRewardID( INT32 v)
	{
		m_RewardID=v;
	}
	INT32 GetRewardID()
	{
		return m_RewardID;
	}
	INT32 GetRewardID() const
	{
		return m_RewardID;
	}

};
//运营登录活动领取奖励请求封装类
class WelfareRpcSpecLoginRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcSpecLoginRewardAskWraper()
	{
		
		m_Id = -1;
		m_Index = -1;

	}
	//赋值构造函数
	WelfareRpcSpecLoginRewardAskWraper(const WelfareRpcSpecLoginRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcSpecLoginRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcSpecLoginRewardAsk ToPB() const
	{
		WelfareRpcSpecLoginRewardAsk v;
		v.set_id( m_Id );
		v.set_index( m_Index );

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
		WelfareRpcSpecLoginRewardAsk pb;
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
	void Init(const WelfareRpcSpecLoginRewardAsk& v)
	{
		m_Id = v.id();
		m_Index = v.index();

	}

private:
	//活动id
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
	//索引
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}

};
//运营登录活动领取奖励回应封装类
class WelfareRpcSpecLoginRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcSpecLoginRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WelfareRpcSpecLoginRewardReplyWraper(const WelfareRpcSpecLoginRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcSpecLoginRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcSpecLoginRewardReply ToPB() const
	{
		WelfareRpcSpecLoginRewardReply v;
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
		WelfareRpcSpecLoginRewardReply pb;
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
	void Init(const WelfareRpcSpecLoginRewardReply& v)
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
//运营登录活动通知封装类
class WelfareRpcSpecLoginNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcSpecLoginNotifyWraper()
	{
		

	}
	//赋值构造函数
	WelfareRpcSpecLoginNotifyWraper(const WelfareRpcSpecLoginNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcSpecLoginNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcSpecLoginNotify ToPB() const
	{
		WelfareRpcSpecLoginNotify v;
		v.mutable_speclogin()->Reserve(m_SpecLogin.size());
		for (int i=0; i<(int)m_SpecLogin.size(); i++)
		{
			*v.add_speclogin() = m_SpecLogin[i].ToPB();
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
		WelfareRpcSpecLoginNotify pb;
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
	void Init(const WelfareRpcSpecLoginNotify& v)
	{
		m_SpecLogin.clear();
		m_SpecLogin.reserve(v.speclogin_size());
		for( int i=0; i<v.speclogin_size(); i++)
			m_SpecLogin.push_back(v.speclogin(i));

	}

private:
	//运营登录活动消息
	vector<SpecLoginInfoWraper> m_SpecLogin;
public:
	int SizeSpecLogin()
	{
		return m_SpecLogin.size();
	}
	const vector<SpecLoginInfoWraper>& GetSpecLogin() const
	{
		return m_SpecLogin;
	}
	SpecLoginInfoWraper GetSpecLogin(int Index) const
	{
		if(Index<0 || Index>=(int)m_SpecLogin.size())
		{
			assert(false);
			return SpecLoginInfoWraper();
		}
		return m_SpecLogin[Index];
	}
	void SetSpecLogin( const vector<SpecLoginInfoWraper>& v )
	{
		m_SpecLogin=v;
	}
	void ClearSpecLogin( )
	{
		m_SpecLogin.clear();
	}
	void SetSpecLogin( int Index, const SpecLoginInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_SpecLogin.size())
		{
			assert(false);
			return;
		}
		m_SpecLogin[Index] = v;
	}
	void AddSpecLogin( const SpecLoginInfoWraper& v )
	{
		m_SpecLogin.push_back(v);
	}

};
//签到回应封装类
class WelfareRpcMonthSignInRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcMonthSignInRewardReplyWraper()
	{
		
		m_Result = -1;
		m_RewardID = -1;
		m_FixSignInTimes = -1;

	}
	//赋值构造函数
	WelfareRpcMonthSignInRewardReplyWraper(const WelfareRpcMonthSignInRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcMonthSignInRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcMonthSignInRewardReply ToPB() const
	{
		WelfareRpcMonthSignInRewardReply v;
		v.set_result( m_Result );
		v.set_rewardid( m_RewardID );
		v.set_fixsignintimes( m_FixSignInTimes );

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
		WelfareRpcMonthSignInRewardReply pb;
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
	void Init(const WelfareRpcMonthSignInRewardReply& v)
	{
		m_Result = v.result();
		m_RewardID = v.rewardid();
		m_FixSignInTimes = v.fixsignintimes();

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
	//奖励ID
	INT32 m_RewardID;
public:
	void SetRewardID( INT32 v)
	{
		m_RewardID=v;
	}
	INT32 GetRewardID()
	{
		return m_RewardID;
	}
	INT32 GetRewardID() const
	{
		return m_RewardID;
	}
private:
	//可补签天数
	INT32 m_FixSignInTimes;
public:
	void SetFixSignInTimes( INT32 v)
	{
		m_FixSignInTimes=v;
	}
	INT32 GetFixSignInTimes()
	{
		return m_FixSignInTimes;
	}
	INT32 GetFixSignInTimes() const
	{
		return m_FixSignInTimes;
	}

};
//今日签到提醒通知封装类
class WelfareRpcTodaySignInNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcTodaySignInNotifyWraper()
	{
		
		m_TodaySignIn = false;

	}
	//赋值构造函数
	WelfareRpcTodaySignInNotifyWraper(const WelfareRpcTodaySignInNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcTodaySignInNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcTodaySignInNotify ToPB() const
	{
		WelfareRpcTodaySignInNotify v;
		v.set_todaysignin( m_TodaySignIn );

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
		WelfareRpcTodaySignInNotify pb;
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
	void Init(const WelfareRpcTodaySignInNotify& v)
	{
		m_TodaySignIn = v.todaysignin();

	}

private:
	//今日是否已签到
	bool m_TodaySignIn;
public:
	void SetTodaySignIn( bool v)
	{
		m_TodaySignIn=v;
	}
	bool GetTodaySignIn()
	{
		return m_TodaySignIn;
	}
	bool GetTodaySignIn() const
	{
		return m_TodaySignIn;
	}

};
//领取累计登陆奖励回应封装类
class WelfareRpcAccumulateGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcAccumulateGetRewardReplyWraper()
	{
		
		m_Result = -1;
		m_RewardID = -1;

	}
	//赋值构造函数
	WelfareRpcAccumulateGetRewardReplyWraper(const WelfareRpcAccumulateGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcAccumulateGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcAccumulateGetRewardReply ToPB() const
	{
		WelfareRpcAccumulateGetRewardReply v;
		v.set_result( m_Result );
		v.set_rewardid( m_RewardID );

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
		WelfareRpcAccumulateGetRewardReply pb;
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
	void Init(const WelfareRpcAccumulateGetRewardReply& v)
	{
		m_Result = v.result();
		m_RewardID = v.rewardid();

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
	//奖励ID
	INT32 m_RewardID;
public:
	void SetRewardID( INT32 v)
	{
		m_RewardID=v;
	}
	INT32 GetRewardID()
	{
		return m_RewardID;
	}
	INT32 GetRewardID() const
	{
		return m_RewardID;
	}

};
//今日在线福利请求封装类
class WelfareRpcOnlineBonusAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcOnlineBonusAskWraper()
	{
		

	}
	//赋值构造函数
	WelfareRpcOnlineBonusAskWraper(const WelfareRpcOnlineBonusAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcOnlineBonusAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcOnlineBonusAsk ToPB() const
	{
		WelfareRpcOnlineBonusAsk v;

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
		WelfareRpcOnlineBonusAsk pb;
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
	void Init(const WelfareRpcOnlineBonusAsk& v)
	{

	}


};
//领取累计登陆奖励请求封装类
class WelfareRpcAccumulateGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcAccumulateGetRewardAskWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	WelfareRpcAccumulateGetRewardAskWraper(const WelfareRpcAccumulateGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcAccumulateGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcAccumulateGetRewardAsk ToPB() const
	{
		WelfareRpcAccumulateGetRewardAsk v;
		v.set_id( m_ID );

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
		WelfareRpcAccumulateGetRewardAsk pb;
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
	void Init(const WelfareRpcAccumulateGetRewardAsk& v)
	{
		m_ID = v.id();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//累计登陆福利请求封装类
class WelfareRpcAccumulateSignInAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcAccumulateSignInAskWraper()
	{
		

	}
	//赋值构造函数
	WelfareRpcAccumulateSignInAskWraper(const WelfareRpcAccumulateSignInAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcAccumulateSignInAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcAccumulateSignInAsk ToPB() const
	{
		WelfareRpcAccumulateSignInAsk v;

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
		WelfareRpcAccumulateSignInAsk pb;
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
	void Init(const WelfareRpcAccumulateSignInAsk& v)
	{

	}


};
//累计登陆福利回应封装类
class WelfareRpcAccumulateSignInReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcAccumulateSignInReplyWraper()
	{
		
		m_Result = -1;
		m_AccumulateDays = -1;

	}
	//赋值构造函数
	WelfareRpcAccumulateSignInReplyWraper(const WelfareRpcAccumulateSignInReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcAccumulateSignInReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcAccumulateSignInReply ToPB() const
	{
		WelfareRpcAccumulateSignInReply v;
		v.set_result( m_Result );
		v.mutable_accumulatelist()->Reserve(m_AccumulateList.size());
		for (int i=0; i<(int)m_AccumulateList.size(); i++)
		{
			*v.add_accumulatelist() = m_AccumulateList[i].ToPB();
		}
		v.set_accumulatedays( m_AccumulateDays );

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
		WelfareRpcAccumulateSignInReply pb;
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
	void Init(const WelfareRpcAccumulateSignInReply& v)
	{
		m_Result = v.result();
		m_AccumulateList.clear();
		m_AccumulateList.reserve(v.accumulatelist_size());
		for( int i=0; i<v.accumulatelist_size(); i++)
			m_AccumulateList.push_back(v.accumulatelist(i));
		m_AccumulateDays = v.accumulatedays();

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
	//累计登陆信息
	vector<AccumulateSignInfoWraper> m_AccumulateList;
public:
	int SizeAccumulateList()
	{
		return m_AccumulateList.size();
	}
	const vector<AccumulateSignInfoWraper>& GetAccumulateList() const
	{
		return m_AccumulateList;
	}
	AccumulateSignInfoWraper GetAccumulateList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AccumulateList.size())
		{
			assert(false);
			return AccumulateSignInfoWraper();
		}
		return m_AccumulateList[Index];
	}
	void SetAccumulateList( const vector<AccumulateSignInfoWraper>& v )
	{
		m_AccumulateList=v;
	}
	void ClearAccumulateList( )
	{
		m_AccumulateList.clear();
	}
	void SetAccumulateList( int Index, const AccumulateSignInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_AccumulateList.size())
		{
			assert(false);
			return;
		}
		m_AccumulateList[Index] = v;
	}
	void AddAccumulateList( const AccumulateSignInfoWraper& v )
	{
		m_AccumulateList.push_back(v);
	}
private:
	//累计登陆天数
	INT32 m_AccumulateDays;
public:
	void SetAccumulateDays( INT32 v)
	{
		m_AccumulateDays=v;
	}
	INT32 GetAccumulateDays()
	{
		return m_AccumulateDays;
	}
	INT32 GetAccumulateDays() const
	{
		return m_AccumulateDays;
	}

};
//等级福利请求封装类
class WelfareRpcLevelBonusAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcLevelBonusAskWraper()
	{
		

	}
	//赋值构造函数
	WelfareRpcLevelBonusAskWraper(const WelfareRpcLevelBonusAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcLevelBonusAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcLevelBonusAsk ToPB() const
	{
		WelfareRpcLevelBonusAsk v;

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
		WelfareRpcLevelBonusAsk pb;
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
	void Init(const WelfareRpcLevelBonusAsk& v)
	{

	}


};
//等级福利回应封装类
class WelfareRpcLevelBonusReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcLevelBonusReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	WelfareRpcLevelBonusReplyWraper(const WelfareRpcLevelBonusReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcLevelBonusReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcLevelBonusReply ToPB() const
	{
		WelfareRpcLevelBonusReply v;
		v.set_result( m_Result );
		v.mutable_levelbonuslist()->Reserve(m_LevelBonusList.size());
		for (int i=0; i<(int)m_LevelBonusList.size(); i++)
		{
			*v.add_levelbonuslist() = m_LevelBonusList[i].ToPB();
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
		WelfareRpcLevelBonusReply pb;
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
	void Init(const WelfareRpcLevelBonusReply& v)
	{
		m_Result = v.result();
		m_LevelBonusList.clear();
		m_LevelBonusList.reserve(v.levelbonuslist_size());
		for( int i=0; i<v.levelbonuslist_size(); i++)
			m_LevelBonusList.push_back(v.levelbonuslist(i));

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
	//等级福利信息
	vector<LevelInfoWraper> m_LevelBonusList;
public:
	int SizeLevelBonusList()
	{
		return m_LevelBonusList.size();
	}
	const vector<LevelInfoWraper>& GetLevelBonusList() const
	{
		return m_LevelBonusList;
	}
	LevelInfoWraper GetLevelBonusList(int Index) const
	{
		if(Index<0 || Index>=(int)m_LevelBonusList.size())
		{
			assert(false);
			return LevelInfoWraper();
		}
		return m_LevelBonusList[Index];
	}
	void SetLevelBonusList( const vector<LevelInfoWraper>& v )
	{
		m_LevelBonusList=v;
	}
	void ClearLevelBonusList( )
	{
		m_LevelBonusList.clear();
	}
	void SetLevelBonusList( int Index, const LevelInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_LevelBonusList.size())
		{
			assert(false);
			return;
		}
		m_LevelBonusList[Index] = v;
	}
	void AddLevelBonusList( const LevelInfoWraper& v )
	{
		m_LevelBonusList.push_back(v);
	}

};
//领取今日在线奖励回应封装类
class WelfareRpcOnlineGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcOnlineGetRewardReplyWraper()
	{
		
		m_Result = -1;
		m_RewardID = -1;

	}
	//赋值构造函数
	WelfareRpcOnlineGetRewardReplyWraper(const WelfareRpcOnlineGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcOnlineGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcOnlineGetRewardReply ToPB() const
	{
		WelfareRpcOnlineGetRewardReply v;
		v.set_result( m_Result );
		v.set_rewardid( m_RewardID );

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
		WelfareRpcOnlineGetRewardReply pb;
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
	void Init(const WelfareRpcOnlineGetRewardReply& v)
	{
		m_Result = v.result();
		m_RewardID = v.rewardid();

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
	//奖励ID
	INT32 m_RewardID;
public:
	void SetRewardID( INT32 v)
	{
		m_RewardID=v;
	}
	INT32 GetRewardID()
	{
		return m_RewardID;
	}
	INT32 GetRewardID() const
	{
		return m_RewardID;
	}

};
//今日在线福利回应封装类
class WelfareRpcOnlineBonusReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcOnlineBonusReplyWraper()
	{
		
		m_Result = -1;
		m_TodayOnlineTime = -1;

	}
	//赋值构造函数
	WelfareRpcOnlineBonusReplyWraper(const WelfareRpcOnlineBonusReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcOnlineBonusReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcOnlineBonusReply ToPB() const
	{
		WelfareRpcOnlineBonusReply v;
		v.set_result( m_Result );
		v.mutable_onlinebonuslist()->Reserve(m_OnlineBonusList.size());
		for (int i=0; i<(int)m_OnlineBonusList.size(); i++)
		{
			*v.add_onlinebonuslist() = m_OnlineBonusList[i].ToPB();
		}
		v.set_todayonlinetime( m_TodayOnlineTime );

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
		WelfareRpcOnlineBonusReply pb;
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
	void Init(const WelfareRpcOnlineBonusReply& v)
	{
		m_Result = v.result();
		m_OnlineBonusList.clear();
		m_OnlineBonusList.reserve(v.onlinebonuslist_size());
		for( int i=0; i<v.onlinebonuslist_size(); i++)
			m_OnlineBonusList.push_back(v.onlinebonuslist(i));
		m_TodayOnlineTime = v.todayonlinetime();

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
	//今日在线福利信息
	vector<OnlineInfoWraper> m_OnlineBonusList;
public:
	int SizeOnlineBonusList()
	{
		return m_OnlineBonusList.size();
	}
	const vector<OnlineInfoWraper>& GetOnlineBonusList() const
	{
		return m_OnlineBonusList;
	}
	OnlineInfoWraper GetOnlineBonusList(int Index) const
	{
		if(Index<0 || Index>=(int)m_OnlineBonusList.size())
		{
			assert(false);
			return OnlineInfoWraper();
		}
		return m_OnlineBonusList[Index];
	}
	void SetOnlineBonusList( const vector<OnlineInfoWraper>& v )
	{
		m_OnlineBonusList=v;
	}
	void ClearOnlineBonusList( )
	{
		m_OnlineBonusList.clear();
	}
	void SetOnlineBonusList( int Index, const OnlineInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_OnlineBonusList.size())
		{
			assert(false);
			return;
		}
		m_OnlineBonusList[Index] = v;
	}
	void AddOnlineBonusList( const OnlineInfoWraper& v )
	{
		m_OnlineBonusList.push_back(v);
	}
private:
	//今日在线时间
	INT32 m_TodayOnlineTime;
public:
	void SetTodayOnlineTime( INT32 v)
	{
		m_TodayOnlineTime=v;
	}
	INT32 GetTodayOnlineTime()
	{
		return m_TodayOnlineTime;
	}
	INT32 GetTodayOnlineTime() const
	{
		return m_TodayOnlineTime;
	}

};
//领取今日在线奖励请求封装类
class WelfareRpcOnlineGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WelfareRpcOnlineGetRewardAskWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	WelfareRpcOnlineGetRewardAskWraper(const WelfareRpcOnlineGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareRpcOnlineGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareRpcOnlineGetRewardAsk ToPB() const
	{
		WelfareRpcOnlineGetRewardAsk v;
		v.set_id( m_ID );

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
		WelfareRpcOnlineGetRewardAsk pb;
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
	void Init(const WelfareRpcOnlineGetRewardAsk& v)
	{
		m_ID = v.id();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<WelfareRpcTodaySignInNotifyWraper>{ enum{ID=RPC_CODE_WELFARE_TODAYSIGNIN_NOTIFY};};
template<> struct MessageIdT<WelfareRpcSpecLoginNotifyWraper>{ enum{ID=RPC_CODE_WELFARE_SPECLOGIN_NOTIFY};};


#endif
