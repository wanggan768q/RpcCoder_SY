/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperGameSetting.h
* Author:       甘业清
* Description:  游戏设置RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_GAMESETTING_H
#define __RPC_WRAPER_GAMESETTING_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "GameSettingRpc.pb.h"



//游戏设置类的枚举定义
enum ConstGameSettingE
{
	MODULE_ID_GAMESETTING                        = 53,	//游戏设置模块ID
	RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST = 5351,	//游戏设置-->同步-->请求
	RPC_CODE_GAMESETTING_SETTING_REQUEST         = 5352,	//游戏设置-->设置-->请求
	RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY= 5353,	//游戏设置-->设置 通知-->通知


};


//设置回应封装类
class GameSettingRpcSettingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GameSettingRpcSettingReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	GameSettingRpcSettingReplyWraper(const GameSettingRpcSettingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GameSettingRpcSettingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GameSettingRpcSettingReply ToPB() const
	{
		GameSettingRpcSettingReply v;
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
		GameSettingRpcSettingReply pb;
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
	void Init(const GameSettingRpcSettingReply& v)
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
//设置 通知通知封装类
class GameSettingRpcGameSettingNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GameSettingRpcGameSettingNotifyNotifyWraper()
	{
		
		m_GameSetting = "";

	}
	//赋值构造函数
	GameSettingRpcGameSettingNotifyNotifyWraper(const GameSettingRpcGameSettingNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const GameSettingRpcGameSettingNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GameSettingRpcGameSettingNotifyNotify ToPB() const
	{
		GameSettingRpcGameSettingNotifyNotify v;
		v.set_gamesetting( m_GameSetting );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		GameSettingRpcGameSettingNotifyNotify pb;
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
	void Init(const GameSettingRpcGameSettingNotifyNotify& v)
	{
		m_GameSetting = v.gamesetting();

	}

private:
	//设置
	string m_GameSetting;
public:
	void SetGameSetting( const string& v)
	{
		m_GameSetting=v;
	}
	string GetGameSetting()
	{
		return m_GameSetting;
	}
	string GetGameSetting() const
	{
		return m_GameSetting;
	}

};
//设置请求封装类
class GameSettingRpcSettingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GameSettingRpcSettingAskWraper()
	{
		
		m_GameSetting = "";

	}
	//赋值构造函数
	GameSettingRpcSettingAskWraper(const GameSettingRpcSettingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GameSettingRpcSettingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GameSettingRpcSettingAsk ToPB() const
	{
		GameSettingRpcSettingAsk v;
		v.set_gamesetting( m_GameSetting );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		GameSettingRpcSettingAsk pb;
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
	void Init(const GameSettingRpcSettingAsk& v)
	{
		m_GameSetting = v.gamesetting();

	}

private:
	//要设置的
	string m_GameSetting;
public:
	void SetGameSetting( const string& v)
	{
		m_GameSetting=v;
	}
	string GetGameSetting()
	{
		return m_GameSetting;
	}
	string GetGameSetting() const
	{
		return m_GameSetting;
	}

};
//同步请求封装类
class GameSettingRpcSyncGameSettingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GameSettingRpcSyncGameSettingAskWraper()
	{
		

	}
	//赋值构造函数
	GameSettingRpcSyncGameSettingAskWraper(const GameSettingRpcSyncGameSettingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GameSettingRpcSyncGameSettingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GameSettingRpcSyncGameSettingAsk ToPB() const
	{
		GameSettingRpcSyncGameSettingAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		GameSettingRpcSyncGameSettingAsk pb;
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
	void Init(const GameSettingRpcSyncGameSettingAsk& v)
	{

	}


};
//同步回应封装类
class GameSettingRpcSyncGameSettingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GameSettingRpcSyncGameSettingReplyWraper()
	{
		
		m_Result = -1;
		m_GameSetting = "";

	}
	//赋值构造函数
	GameSettingRpcSyncGameSettingReplyWraper(const GameSettingRpcSyncGameSettingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GameSettingRpcSyncGameSettingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GameSettingRpcSyncGameSettingReply ToPB() const
	{
		GameSettingRpcSyncGameSettingReply v;
		v.set_result( m_Result );
		v.set_gamesetting( m_GameSetting );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		GameSettingRpcSyncGameSettingReply pb;
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
	void Init(const GameSettingRpcSyncGameSettingReply& v)
	{
		m_Result = v.result();
		m_GameSetting = v.gamesetting();

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
	//设置info
	string m_GameSetting;
public:
	void SetGameSetting( const string& v)
	{
		m_GameSetting=v;
	}
	string GetGameSetting()
	{
		return m_GameSetting;
	}
	string GetGameSetting() const
	{
		return m_GameSetting;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<GameSettingRpcGameSettingNotifyNotifyWraper>{ enum{ID=RPC_CODE_GAMESETTING_GAMESETTINGNOTIFY_NOTIFY};};


#endif
