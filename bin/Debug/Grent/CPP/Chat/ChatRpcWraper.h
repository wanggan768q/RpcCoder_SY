/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperChat.h
* Author:       郭晓波
* Description:  ChatRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CHAT_H
#define __RPC_WRAPER_CHAT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ChatRpc.pb.h"



//Chat类的枚举定义
enum ConstChatE
{
	MODULE_ID_CHAT                               = 13,	//Chat模块ID
	RPC_CODE_CHAT_CHAT_REQUEST                   = 1351,	//Chat-->Chat-->请求
	RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY         = 1352,	//Chat-->PushChatUpdates-->通知


};


//PushChatUpdates通知封装类
class ChatRpcPushChatUpdatesNotifyWraper
{
public:
	//构造函数
	ChatRpcPushChatUpdatesNotifyWraper()
	{
		

	}
	//赋值构造函数
	ChatRpcPushChatUpdatesNotifyWraper(const ChatRpcPushChatUpdatesNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcPushChatUpdatesNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcPushChatUpdatesNotify ToPB() const
	{
		ChatRpcPushChatUpdatesNotify v;
		v.mutable_chat_channels()->Reserve(m_Chat_channels.size());
		for (int i=0; i<(int)m_Chat_channels.size(); i++)
		{
			*v.add_chat_channels() = m_Chat_channels[i].ToPB();
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
		ChatRpcPushChatUpdatesNotify pb;
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
	void Init(const ChatRpcPushChatUpdatesNotify& v)
	{
		m_Chat_channels.clear();
		m_Chat_channels.reserve(v.chat_channels_size());
		for( int i=0; i<v.chat_channels_size(); i++)
			m_Chat_channels.push_back(v.chat_channels(i));

	}

private:
	//聊天频道列表
	vector<ChatChannelDataWraper> m_Chat_channels;
public:
	int SizeChat_channels()
	{
		return m_Chat_channels.size();
	}
	const vector<ChatChannelDataWraper>& GetChat_channels() const
	{
		return m_Chat_channels;
	}
	ChatChannelDataWraper GetChat_channels(int Index) const
	{
		if(Index<0 || Index>=(int)m_Chat_channels.size())
		{
			assert(false);
			return ChatChannelDataWraper();
		}
		return m_Chat_channels[Index];
	}
	void SetChat_channels( const vector<ChatChannelDataWraper>& v )
	{
		m_Chat_channels=v;
	}
	void ClearChat_channels( )
	{
		m_Chat_channels.clear();
	}
	void SetChat_channels( int Index, const ChatChannelDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Chat_channels.size())
		{
			assert(false);
			return;
		}
		m_Chat_channels[Index] = v;
	}
	void AddChat_channels( const ChatChannelDataWraper& v )
	{
		m_Chat_channels.push_back(v);
	}

};
//Chat回应封装类
class ChatRpcChatReplyWraper
{
public:
	//构造函数
	ChatRpcChatReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ChatRpcChatReplyWraper(const ChatRpcChatReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcChatReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcChatReply ToPB() const
	{
		ChatRpcChatReply v;
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
		ChatRpcChatReply pb;
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
	void Init(const ChatRpcChatReply& v)
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
//Chat请求封装类
class ChatRpcChatAskWraper
{
public:
	//构造函数
	ChatRpcChatAskWraper()
	{
		
		m_Chat_msg = ChatMsgWraper();
		m_Chat_channel = -1;

	}
	//赋值构造函数
	ChatRpcChatAskWraper(const ChatRpcChatAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcChatAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcChatAsk ToPB() const
	{
		ChatRpcChatAsk v;
		*v.mutable_chat_msg()= m_Chat_msg.ToPB();
		v.set_chat_channel( m_Chat_channel );

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
		ChatRpcChatAsk pb;
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
	void Init(const ChatRpcChatAsk& v)
	{
		m_Chat_msg = v.chat_msg();
		m_Chat_channel = v.chat_channel();

	}

private:
	//chat_msg
	ChatMsgWraper m_Chat_msg;
public:
	void SetChat_msg( const ChatMsgWraper& v)
	{
		m_Chat_msg=v;
	}
	ChatMsgWraper GetChat_msg()
	{
		return m_Chat_msg;
	}
	ChatMsgWraper GetChat_msg() const
	{
		return m_Chat_msg;
	}
private:
	//Chat_channel
	INT32 m_Chat_channel;
public:
	void SetChat_channel( INT32 v)
	{
		m_Chat_channel=v;
	}
	INT32 GetChat_channel()
	{
		return m_Chat_channel;
	}
	INT32 GetChat_channel() const
	{
		return m_Chat_channel;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ChatRpcPushChatUpdatesNotifyWraper>{ enum{ID=RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY};};


#endif
