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
	RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY             = 1353,	//Chat-->推送跑马灯-->通知
	RPC_CODE_CHAT_SAY_NOTIFY                     = 1354,	//Chat-->玩家或NPC对象说话-->通知
	RPC_CODE_CHAT_SERVERCHAT_NOTIFY              = 1355,	//Chat-->服务器通知-->通知


};


//推送跑马灯通知封装类
class ChatRpcPushMarqueeNotifyWraper
{
public:
	//构造函数
	ChatRpcPushMarqueeNotifyWraper()
	{
		
		m_Priority = -1;

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
			*v.add_marquee() = m_Marquee[i].ToPB();
		}
		v.set_priority( m_Priority );

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
	void Init(const ChatRpcPushMarqueeNotify& v)
	{
		m_Marquee.clear();
		m_Marquee.reserve(v.marquee_size());
		for( int i=0; i<v.marquee_size(); i++)
			m_Marquee.push_back(v.marquee(i));
		m_Priority = v.priority();

	}

private:
	//跑马灯
	vector<AppendStringWraper> m_Marquee;
public:
	int SizeMarquee()
	{
		return m_Marquee.size();
	}
	const vector<AppendStringWraper>& GetMarquee() const
	{
		return m_Marquee;
	}
	AppendStringWraper GetMarquee(int Index) const
	{
		if(Index<0 || Index>=(int)m_Marquee.size())
		{
			assert(false);
			return AppendStringWraper();
		}
		return m_Marquee[Index];
	}
	void SetMarquee( const vector<AppendStringWraper>& v )
	{
		m_Marquee=v;
	}
	void ClearMarquee( )
	{
		m_Marquee.clear();
	}
	void SetMarquee( int Index, const AppendStringWraper& v )
	{
		if(Index<0 || Index>=(int)m_Marquee.size())
		{
			assert(false);
			return;
		}
		m_Marquee[Index] = v;
	}
	void AddMarquee( const AppendStringWraper& v )
	{
		m_Marquee.push_back(v);
	}
private:
	//优先级
	INT32 m_Priority;
public:
	void SetPriority( INT32 v)
	{
		m_Priority=v;
	}
	INT32 GetPriority()
	{
		return m_Priority;
	}
	INT32 GetPriority() const
	{
		return m_Priority;
	}

};
//玩家或NPC对象说话通知封装类
class ChatRpcSayNotifyWraper
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
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
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
//服务器通知封装类
class ChatRpcServerChatNotifyWraper
{
public:
	//构造函数
	ChatRpcServerChatNotifyWraper()
	{
		
		m_Id = -1;
		m_Channel = -1;

	}
	//赋值构造函数
	ChatRpcServerChatNotifyWraper(const ChatRpcServerChatNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRpcServerChatNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRpcServerChatNotify ToPB() const
	{
		ChatRpcServerChatNotify v;
		v.set_id( m_Id );
		v.set_channel( m_Channel );
		v.mutable_iparams()->Reserve(m_IParams.size());
		for (int i=0; i<(int)m_IParams.size(); i++)
		{
			v.add_iparams(m_IParams[i]);
		}
		v.mutable_sparams()->Reserve(m_SParams.size());
		for (int i=0; i<(int)m_SParams.size(); i++)
		{
			v.add_sparams( m_SParams[i]);
		}
		v.mutable_items()->Reserve(m_Items.size());
		for (int i=0; i<(int)m_Items.size(); i++)
		{
			*v.add_items() = m_Items[i].ToPB();
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
		ChatRpcServerChatNotify pb;
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
	void Init(const ChatRpcServerChatNotify& v)
	{
		m_Id = v.id();
		m_Channel = v.channel();
		m_IParams.clear();
		m_IParams.reserve(v.iparams_size());
		for( int i=0; i<v.iparams_size(); i++)
			m_IParams.push_back(v.iparams(i));
		m_SParams.clear();
		m_SParams.reserve(v.sparams_size());
		for( int i=0; i<v.sparams_size(); i++)
			m_SParams.push_back(v.sparams(i));
		m_Items.clear();
		m_Items.reserve(v.items_size());
		for( int i=0; i<v.items_size(); i++)
			m_Items.push_back(v.items(i));

	}

private:
	//StringUi的id
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
	//频道
	INT32 m_Channel;
public:
	void SetChannel( INT32 v)
	{
		m_Channel=v;
	}
	INT32 GetChannel()
	{
		return m_Channel;
	}
	INT32 GetChannel() const
	{
		return m_Channel;
	}
private:
	//整型参数
	vector<INT32> m_IParams;
public:
	int SizeIParams()
	{
		return m_IParams.size();
	}
	const vector<INT32>& GetIParams() const
	{
		return m_IParams;
	}
	INT32 GetIParams(int Index) const
	{
		if(Index<0 || Index>=(int)m_IParams.size())
		{
			assert(false);
			return INT32();
		}
		return m_IParams[Index];
	}
	void SetIParams( const vector<INT32>& v )
	{
		m_IParams=v;
	}
	void ClearIParams( )
	{
		m_IParams.clear();
	}
	void SetIParams( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_IParams.size())
		{
			assert(false);
			return;
		}
		m_IParams[Index] = v;
	}
	void AddIParams( INT32 v = -1 )
	{
		m_IParams.push_back(v);
	}
private:
	//字串参数
	vector<string> m_SParams;
public:
	int SizeSParams()
	{
		return m_SParams.size();
	}
	const vector<string>& GetSParams() const
	{
		return m_SParams;
	}
	string GetSParams(int Index) const
	{
		if(Index<0 || Index>=(int)m_SParams.size())
		{
			assert(false);
			return string();
		}
		return m_SParams[Index];
	}
	void SetSParams( const vector<string>& v )
	{
		m_SParams=v;
	}
	void ClearSParams( )
	{
		m_SParams.clear();
	}
	void SetSParams( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_SParams.size())
		{
			assert(false);
			return;
		}
		m_SParams[Index] = v;
	}
	void AddSParams( const string& v )
	{
		m_SParams.push_back(v);
	}
private:
	//道具列表
	vector<ItemDataWraper> m_Items;
public:
	int SizeItems()
	{
		return m_Items.size();
	}
	const vector<ItemDataWraper>& GetItems() const
	{
		return m_Items;
	}
	ItemDataWraper GetItems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Items[Index];
	}
	void SetItems( const vector<ItemDataWraper>& v )
	{
		m_Items=v;
	}
	void ClearItems( )
	{
		m_Items.clear();
	}
	void SetItems( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return;
		}
		m_Items[Index] = v;
	}
	void AddItems( const ItemDataWraper& v )
	{
		m_Items.push_back(v);
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
//Chat回应封装类
class ChatRpcChatReplyWraper
{
public:
	//构造函数
	ChatRpcChatReplyWraper()
	{
		
		m_Result = -9999;
		m_Forbid_endtime = -1;

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
		v.set_forbid_endtime( m_Forbid_endtime );

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
		m_Forbid_endtime = v.forbid_endtime();

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
	//禁言截至时间
	INT32 m_Forbid_endtime;
public:
	void SetForbid_endtime( INT32 v)
	{
		m_Forbid_endtime=v;
	}
	INT32 GetForbid_endtime()
	{
		return m_Forbid_endtime;
	}
	INT32 GetForbid_endtime() const
	{
		return m_Forbid_endtime;
	}

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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ChatRpcPushChatUpdatesNotifyWraper>{ enum{ID=RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY};};
template<> struct MessageIdT<ChatRpcPushMarqueeNotifyWraper>{ enum{ID=RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY};};
template<> struct MessageIdT<ChatRpcSayNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SAY_NOTIFY};};
template<> struct MessageIdT<ChatRpcServerChatNotifyWraper>{ enum{ID=RPC_CODE_CHAT_SERVERCHAT_NOTIFY};};


#endif
