/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperBulletScreen.h
* Author:       甘业清
* Description:  弹幕RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BULLETSCREEN_H
#define __RPC_WRAPER_BULLETSCREEN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BulletScreenRpc.pb.h"



//弹幕类的枚举定义
enum ConstBulletScreenE
{
	MODULE_ID_BULLETSCREEN                       = 50,	//弹幕模块ID
	RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST= 5051,	//弹幕-->弹幕设置-->请求
	RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST = 5052,	//弹幕-->过场动画弹幕请求-->请求
	RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST= 5053,	//弹幕-->发布过场弹幕-->请求


};


//过场动画弹幕请求回应封装类
class BulletScreenRpcCGBulletScreenReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcCGBulletScreenReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BulletScreenRpcCGBulletScreenReplyWraper(const BulletScreenRpcCGBulletScreenReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcCGBulletScreenReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcCGBulletScreenReply ToPB() const
	{
		BulletScreenRpcCGBulletScreenReply v;
		v.set_result( m_Result );
		v.mutable_bulletscreencontent()->Reserve(m_BulletScreenContent.size());
		for (int i=0; i<(int)m_BulletScreenContent.size(); i++)
		{
			v.add_bulletscreencontent( m_BulletScreenContent[i]);
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
		BulletScreenRpcCGBulletScreenReply pb;
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
	void Init(const BulletScreenRpcCGBulletScreenReply& v)
	{
		m_Result = v.result();
		m_BulletScreenContent.clear();
		m_BulletScreenContent.reserve(v.bulletscreencontent_size());
		for( int i=0; i<v.bulletscreencontent_size(); i++)
			m_BulletScreenContent.push_back(v.bulletscreencontent(i));

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
	//弹幕内容
	vector<string> m_BulletScreenContent;
public:
	int SizeBulletScreenContent()
	{
		return m_BulletScreenContent.size();
	}
	const vector<string>& GetBulletScreenContent() const
	{
		return m_BulletScreenContent;
	}
	string GetBulletScreenContent(int Index) const
	{
		if(Index<0 || Index>=(int)m_BulletScreenContent.size())
		{
			assert(false);
			return string();
		}
		return m_BulletScreenContent[Index];
	}
	void SetBulletScreenContent( const vector<string>& v )
	{
		m_BulletScreenContent=v;
	}
	void ClearBulletScreenContent( )
	{
		m_BulletScreenContent.clear();
	}
	void SetBulletScreenContent( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_BulletScreenContent.size())
		{
			assert(false);
			return;
		}
		m_BulletScreenContent[Index] = v;
	}
	void AddBulletScreenContent( const string& v )
	{
		m_BulletScreenContent.push_back(v);
	}

};
//发布过场弹幕请求封装类
class BulletScreenRpcSendBulletScreenCGAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcSendBulletScreenCGAskWraper()
	{
		
		m_CGid = -1;
		m_Content = "";

	}
	//赋值构造函数
	BulletScreenRpcSendBulletScreenCGAskWraper(const BulletScreenRpcSendBulletScreenCGAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcSendBulletScreenCGAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcSendBulletScreenCGAsk ToPB() const
	{
		BulletScreenRpcSendBulletScreenCGAsk v;
		v.set_cgid( m_CGid );
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
		BulletScreenRpcSendBulletScreenCGAsk pb;
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
	void Init(const BulletScreenRpcSendBulletScreenCGAsk& v)
	{
		m_CGid = v.cgid();
		m_Content = v.content();

	}

private:
	//过场ID
	INT32 m_CGid;
public:
	void SetCGid( INT32 v)
	{
		m_CGid=v;
	}
	INT32 GetCGid()
	{
		return m_CGid;
	}
	INT32 GetCGid() const
	{
		return m_CGid;
	}
private:
	//发布内容
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
//发布过场弹幕回应封装类
class BulletScreenRpcSendBulletScreenCGReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcSendBulletScreenCGReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BulletScreenRpcSendBulletScreenCGReplyWraper(const BulletScreenRpcSendBulletScreenCGReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcSendBulletScreenCGReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcSendBulletScreenCGReply ToPB() const
	{
		BulletScreenRpcSendBulletScreenCGReply v;
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
		BulletScreenRpcSendBulletScreenCGReply pb;
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
	void Init(const BulletScreenRpcSendBulletScreenCGReply& v)
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
//弹幕设置请求封装类
class BulletScreenRpcBulletScreenOptAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcBulletScreenOptAskWraper()
	{
		
		m_BulletScreenType = -1;
		m_OptType = -1;

	}
	//赋值构造函数
	BulletScreenRpcBulletScreenOptAskWraper(const BulletScreenRpcBulletScreenOptAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcBulletScreenOptAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcBulletScreenOptAsk ToPB() const
	{
		BulletScreenRpcBulletScreenOptAsk v;
		v.set_bulletscreentype( m_BulletScreenType );
		v.set_opttype( m_OptType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BulletScreenRpcBulletScreenOptAsk pb;
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
	void Init(const BulletScreenRpcBulletScreenOptAsk& v)
	{
		m_BulletScreenType = v.bulletscreentype();
		m_OptType = v.opttype();

	}

private:
	//弹幕设置场景(1组队 2过场)
	INT32 m_BulletScreenType;
public:
	void SetBulletScreenType( INT32 v)
	{
		m_BulletScreenType=v;
	}
	INT32 GetBulletScreenType()
	{
		return m_BulletScreenType;
	}
	INT32 GetBulletScreenType() const
	{
		return m_BulletScreenType;
	}
private:
	//关闭打开(1关闭 2打开)
	INT32 m_OptType;
public:
	void SetOptType( INT32 v)
	{
		m_OptType=v;
	}
	INT32 GetOptType()
	{
		return m_OptType;
	}
	INT32 GetOptType() const
	{
		return m_OptType;
	}

};
//弹幕设置回应封装类
class BulletScreenRpcBulletScreenOptReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcBulletScreenOptReplyWraper()
	{
		
		m_Result = -1;
		m_BulletScreenType = -1;
		m_OptType = -1;

	}
	//赋值构造函数
	BulletScreenRpcBulletScreenOptReplyWraper(const BulletScreenRpcBulletScreenOptReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcBulletScreenOptReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcBulletScreenOptReply ToPB() const
	{
		BulletScreenRpcBulletScreenOptReply v;
		v.set_result( m_Result );
		v.set_bulletscreentype( m_BulletScreenType );
		v.set_opttype( m_OptType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BulletScreenRpcBulletScreenOptReply pb;
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
	void Init(const BulletScreenRpcBulletScreenOptReply& v)
	{
		m_Result = v.result();
		m_BulletScreenType = v.bulletscreentype();
		m_OptType = v.opttype();

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
	//弹幕设置场景(1组队 2过场)
	INT32 m_BulletScreenType;
public:
	void SetBulletScreenType( INT32 v)
	{
		m_BulletScreenType=v;
	}
	INT32 GetBulletScreenType()
	{
		return m_BulletScreenType;
	}
	INT32 GetBulletScreenType() const
	{
		return m_BulletScreenType;
	}
private:
	//关闭打开(1关闭 2打开)
	INT32 m_OptType;
public:
	void SetOptType( INT32 v)
	{
		m_OptType=v;
	}
	INT32 GetOptType()
	{
		return m_OptType;
	}
	INT32 GetOptType() const
	{
		return m_OptType;
	}

};
//过场动画弹幕请求请求封装类
class BulletScreenRpcCGBulletScreenAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BulletScreenRpcCGBulletScreenAskWraper()
	{
		
		m_CGid = -1;

	}
	//赋值构造函数
	BulletScreenRpcCGBulletScreenAskWraper(const BulletScreenRpcCGBulletScreenAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BulletScreenRpcCGBulletScreenAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BulletScreenRpcCGBulletScreenAsk ToPB() const
	{
		BulletScreenRpcCGBulletScreenAsk v;
		v.set_cgid( m_CGid );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		BulletScreenRpcCGBulletScreenAsk pb;
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
	void Init(const BulletScreenRpcCGBulletScreenAsk& v)
	{
		m_CGid = v.cgid();

	}

private:
	//过场ID
	INT32 m_CGid;
public:
	void SetCGid( INT32 v)
	{
		m_CGid=v;
	}
	INT32 GetCGid()
	{
		return m_CGid;
	}
	INT32 GetCGid() const
	{
		return m_CGid;
	}

};

template<typename T> struct MessageIdT;


#endif
