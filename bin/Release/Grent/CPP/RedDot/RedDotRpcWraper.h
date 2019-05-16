/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperRedDot.h
* Author:       甘业清
* Description:  红点系统RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_REDDOT_H
#define __RPC_WRAPER_REDDOT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "RedDotRpc.pb.h"



//红点系统类的枚举定义
enum ConstRedDotE
{
	MODULE_ID_REDDOT                             = 54,	//红点系统模块ID
	RPC_CODE_REDDOT_SYNCREDDOT_REQUEST           = 5451,	//红点系统-->同步-->请求
	RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST         = 5452,	//红点系统-->删除红点-->请求
	RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY          = 5453,	//红点系统-->更新-->通知


};


//删除红点回应封装类
class RedDotRpcRemoveRedDotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RedDotRpcRemoveRedDotReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	RedDotRpcRemoveRedDotReplyWraper(const RedDotRpcRemoveRedDotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotRpcRemoveRedDotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotRpcRemoveRedDotReply ToPB() const
	{
		RedDotRpcRemoveRedDotReply v;
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
		RedDotRpcRemoveRedDotReply pb;
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
	void Init(const RedDotRpcRemoveRedDotReply& v)
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
//更新通知封装类
class RedDotRpcUpdateRedDotNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RedDotRpcUpdateRedDotNotifyWraper()
	{
		
		m_RedDotInfo = RedDotInfoWraper();

	}
	//赋值构造函数
	RedDotRpcUpdateRedDotNotifyWraper(const RedDotRpcUpdateRedDotNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotRpcUpdateRedDotNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotRpcUpdateRedDotNotify ToPB() const
	{
		RedDotRpcUpdateRedDotNotify v;
		*v.mutable_reddotinfo()= m_RedDotInfo.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		RedDotRpcUpdateRedDotNotify pb;
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
	void Init(const RedDotRpcUpdateRedDotNotify& v)
	{
		m_RedDotInfo = v.reddotinfo();

	}

private:
	//需要更新的红点信息
	RedDotInfoWraper m_RedDotInfo;
public:
	void SetRedDotInfo( const RedDotInfoWraper& v)
	{
		m_RedDotInfo=v;
	}
	RedDotInfoWraper GetRedDotInfo()
	{
		return m_RedDotInfo;
	}
	RedDotInfoWraper GetRedDotInfo() const
	{
		return m_RedDotInfo;
	}

};
//删除红点请求封装类
class RedDotRpcRemoveRedDotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	RedDotRpcRemoveRedDotAskWraper()
	{
		
		m_Type = -1;

	}
	//赋值构造函数
	RedDotRpcRemoveRedDotAskWraper(const RedDotRpcRemoveRedDotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotRpcRemoveRedDotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotRpcRemoveRedDotAsk ToPB() const
	{
		RedDotRpcRemoveRedDotAsk v;
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
		RedDotRpcRemoveRedDotAsk pb;
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
	void Init(const RedDotRpcRemoveRedDotAsk& v)
	{
		m_Type = v.type();

	}

private:
	//类型
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
//同步请求封装类
class RedDotRpcSyncRedDotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	RedDotRpcSyncRedDotAskWraper()
	{
		

	}
	//赋值构造函数
	RedDotRpcSyncRedDotAskWraper(const RedDotRpcSyncRedDotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotRpcSyncRedDotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotRpcSyncRedDotAsk ToPB() const
	{
		RedDotRpcSyncRedDotAsk v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		RedDotRpcSyncRedDotAsk pb;
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
	void Init(const RedDotRpcSyncRedDotAsk& v)
	{

	}


};
//同步回应封装类
class RedDotRpcSyncRedDotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RedDotRpcSyncRedDotReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	RedDotRpcSyncRedDotReplyWraper(const RedDotRpcSyncRedDotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotRpcSyncRedDotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotRpcSyncRedDotReply ToPB() const
	{
		RedDotRpcSyncRedDotReply v;
		v.set_result( m_Result );
		v.mutable_reddotinfolist()->Reserve(m_RedDotInfoList.size());
		for (int i=0; i<(int)m_RedDotInfoList.size(); i++)
		{
			*v.add_reddotinfolist() = m_RedDotInfoList[i].ToPB();
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
		RedDotRpcSyncRedDotReply pb;
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
	void Init(const RedDotRpcSyncRedDotReply& v)
	{
		m_Result = v.result();
		m_RedDotInfoList.clear();
		m_RedDotInfoList.reserve(v.reddotinfolist_size());
		for( int i=0; i<v.reddotinfolist_size(); i++)
			m_RedDotInfoList.push_back(v.reddotinfolist(i));

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
	//红点列表
	vector<RedDotInfoWraper> m_RedDotInfoList;
public:
	int SizeRedDotInfoList()
	{
		return m_RedDotInfoList.size();
	}
	const vector<RedDotInfoWraper>& GetRedDotInfoList() const
	{
		return m_RedDotInfoList;
	}
	RedDotInfoWraper GetRedDotInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RedDotInfoList.size())
		{
			assert(false);
			return RedDotInfoWraper();
		}
		return m_RedDotInfoList[Index];
	}
	void SetRedDotInfoList( const vector<RedDotInfoWraper>& v )
	{
		m_RedDotInfoList=v;
	}
	void ClearRedDotInfoList( )
	{
		m_RedDotInfoList.clear();
	}
	void SetRedDotInfoList( int Index, const RedDotInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RedDotInfoList.size())
		{
			assert(false);
			return;
		}
		m_RedDotInfoList[Index] = v;
	}
	void AddRedDotInfoList( const RedDotInfoWraper& v )
	{
		m_RedDotInfoList.push_back(v);
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<RedDotRpcUpdateRedDotNotifyWraper>{ enum{ID=RPC_CODE_REDDOT_UPDATEREDDOT_NOTIFY};};


#endif
