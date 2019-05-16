/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperChat.h
* Author:       甘业清
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
	RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY             = 1353,	//Chat-->推送跑马灯-->通知
	RPC_CODE_CHAT_SAY_NOTIFY                     = 1354,	//Chat-->玩家或NPC对象说话-->通知


};


//推送跑马灯通知封装类
class ChatRpcPushMarqueeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcPushMarqueeNotifyWraper()
	{
		

	}
	//赋值构造函数
	ChatRpcPushMarqueeNotifyWraper(const ChatRpcPushMarqueeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcPushMarqueeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcPushMarqueeNotify ToPB() const
	{
		ChatRpcPushMarqueeNotify v;
		v.mutable_marquee()->Reserve(m_Marquee.size());
		for (int i=0; i<(int)m_Marquee.size(); i++)
		{
			v.add_marquee( m_Marquee[i]);
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
		ChatRpcPushMarqueeNotify pb;
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
	void Init(const ChatRpcPushMarqueeNotify& v)
	{
		m_Marquee.clear();
		m_Marquee.reserve(v.marquee_size());
		for( int i=0; i<v.marquee_size(); i++)
			m_Marquee.push_back(v.marquee(i));

	}

private:
	//跑马灯
	vector<string> m_Marquee;
public:
	int SizeMarquee()
	{
		return m_Marquee.size();
	}
	const vector<string>& GetMarquee() const
	{
		return m_Marquee;
	}
	string GetMarquee(int Index) const
	{
		if(Index<0 || Index>=(int)m_Marquee.size())
		{
			assert(false);
			return string();
		}
		return m_Marquee[Index];
	}
	void SetMarquee( const vector<string>& v )
	{
		m_Marquee=v;
	}
	void ClearMarquee( )
	{
		m_Marquee.clear();
	}
	void SetMarquee( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_Marquee.size())
		{
			assert(false);
			return;
		}
		m_Marquee[Index] = v;
	}
	void AddMarquee( const string& v )
	{
		m_Marquee.push_back(v);
	}

};
//玩家或NPC对象说话通知封装类
class ChatRpcSayNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ChatRpcSayNotifyWraper()
	{
		
		m_ObjId = 0;
		m_ChatId = 0;
		m_Duration = 0;
		m_ChatType = 0;
		m_Interval = 0;

	}
	//赋值构造函数
	ChatRpcSayNotifyWraper(const ChatRpcSayNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcSayNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcSayNotify ToPB() const
	{
		ChatRpcSayNotify v;
		v.set_objid( m_ObjId );
		v.set_chatid( m_ChatId );
		v.set_duration( m_Duration );
		v.set_chattype( m_ChatType );
		v.set_interval( m_Interval );

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
		ChatRpcSayNotify pb;
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
	void Init(const ChatRpcSayNotify& v)
	{
		m_ObjId = v.objid();
		m_ChatId = v.chatid();
		m_Duration = v.duration();
		m_ChatType = v.chattype();
		m_Interval = v.interval();

	}

private:
	//说话人的objId
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//String_ChatMenu表id
	INT32 m_ChatId;
public:
	void SetChatId( INT32 v)
	{
		m_ChatId=v;
	}
	INT32 GetChatId()
	{
		return m_ChatId;
	}
	INT32 GetChatId() const
	{
		return m_ChatId;
	}
private:
	//该聊天内容停留时间
	INT32 m_Duration;
public:
	void SetDuration( INT32 v)
	{
		m_Duration=v;
	}
	INT32 GetDuration()
	{
		return m_Duration;
	}
	INT32 GetDuration() const
	{
		return m_Duration;
	}
private:
	//对话显示类型：0：单次显示，1：循环显示
	INT32 m_ChatType;
public:
	void SetChatType( INT32 v)
	{
		m_ChatType=v;
	}
	INT32 GetChatType()
	{
		return m_ChatType;
	}
	INT32 GetChatType() const
	{
		return m_ChatType;
	}
private:
	//循环显示类型下的两次气泡的间隔时间
	INT32 m_Interval;
public:
	void SetInterval( INT32 v)
	{
		m_Interval=v;
	}
	INT32 GetInterval()
	{
		return m_Interval;
	}
	INT32 GetInterval() const
	{
		return m_Interval;
	}

};
//PushChatUpdates通知封装类
class ChatRpcPushChatUpdatesNotifyWraper : public DataWraperInterface 
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
//Chat请求封装类
class ChatRpcChatAskWraper : public DataWraperInterface 
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
//Chat回应封装类
class ChatRpcChatReplyWraper : public DataWraperInterface 
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ChatRpcPushChatUpdatesNotifyWraper>{ enum{ID=RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY};};
template<> struct MessageIdT<ChatRpcPushMarqueeNotifyWraper>{ enum{ID=RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY};};
template<> struct MessageIdT<ChatRpcSayNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SAY_NOTIFY};};


#endif
