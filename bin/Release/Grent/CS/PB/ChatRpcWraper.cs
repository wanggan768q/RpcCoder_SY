
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBChat.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//Chat请求封装类
[System.Serializable]
public class ChatRpcChatAskWraper
{

	//构造函数
	public ChatRpcChatAskWraper()
	{
		 m_Chat_msg = new ChatMsgWraper();
		 m_Chat_channel = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Chat_msg = new ChatMsgWraper();
		 m_Chat_channel = -1;

	}

 	//转化成Protobuffer类型函数
	public ChatRpcChatAsk ToPB()
	{
		ChatRpcChatAsk v = new ChatRpcChatAsk();
		v.Chat_msg = m_Chat_msg.ToPB();
		v.Chat_channel = m_Chat_channel;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcChatAsk v)
	{
        if (v == null)
            return;
		m_Chat_msg.FromPB(v.Chat_msg);
		m_Chat_channel = v.Chat_channel;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcChatAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcChatAsk pb = ProtoBuf.Serializer.Deserialize<ChatRpcChatAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//chat_msg
	public ChatMsgWraper m_Chat_msg;
	public ChatMsgWraper Chat_msg
	{
		get { return m_Chat_msg;}
		set { m_Chat_msg = value; }
	}
	//Chat_channel
	public int m_Chat_channel;
	public int Chat_channel
	{
		get { return m_Chat_channel;}
		set { m_Chat_channel = value; }
	}


};
//Chat回应封装类
[System.Serializable]
public class ChatRpcChatReplyWraper
{

	//构造函数
	public ChatRpcChatReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public ChatRpcChatReply ToPB()
	{
		ChatRpcChatReply v = new ChatRpcChatReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcChatReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcChatReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcChatReply pb = ProtoBuf.Serializer.Deserialize<ChatRpcChatReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//PushChatUpdates通知封装类
[System.Serializable]
public class ChatRpcPushChatUpdatesNotifyWraper
{

	//构造函数
	public ChatRpcPushChatUpdatesNotifyWraper()
	{
		m_Chat_channels = new List<ChatChannelDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Chat_channels = new List<ChatChannelDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ChatRpcPushChatUpdatesNotify ToPB()
	{
		ChatRpcPushChatUpdatesNotify v = new ChatRpcPushChatUpdatesNotify();
		for (int i=0; i<(int)m_Chat_channels.Count; i++)
			v.Chat_channels.Add( m_Chat_channels[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcPushChatUpdatesNotify v)
	{
        if (v == null)
            return;
		m_Chat_channels.Clear();
		for( int i=0; i<v.Chat_channels.Count; i++)
			m_Chat_channels.Add( new ChatChannelDataWraper());
		for( int i=0; i<v.Chat_channels.Count; i++)
			m_Chat_channels[i].FromPB(v.Chat_channels[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcPushChatUpdatesNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcPushChatUpdatesNotify pb = ProtoBuf.Serializer.Deserialize<ChatRpcPushChatUpdatesNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//聊天频道列表
	public List<ChatChannelDataWraper> m_Chat_channels;
	public int SizeChat_channels()
	{
		return m_Chat_channels.Count;
	}
	public List<ChatChannelDataWraper> GetChat_channels()
	{
		return m_Chat_channels;
	}
	public ChatChannelDataWraper GetChat_channels(int Index)
	{
		if(Index<0 || Index>=(int)m_Chat_channels.Count)
			return new ChatChannelDataWraper();
		return m_Chat_channels[Index];
	}
	public void SetChat_channels( List<ChatChannelDataWraper> v )
	{
		m_Chat_channels=v;
	}
	public void SetChat_channels( int Index, ChatChannelDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Chat_channels.Count)
			return;
		m_Chat_channels[Index] = v;
	}
	public void AddChat_channels( ChatChannelDataWraper v )
	{
		m_Chat_channels.Add(v);
	}
	public void ClearChat_channels( )
	{
		m_Chat_channels.Clear();
	}


};
//推送跑马灯通知封装类
[System.Serializable]
public class ChatRpcPushMarqueeNotifyWraper
{

	//构造函数
	public ChatRpcPushMarqueeNotifyWraper()
	{
		m_Marquee = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Marquee = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public ChatRpcPushMarqueeNotify ToPB()
	{
		ChatRpcPushMarqueeNotify v = new ChatRpcPushMarqueeNotify();
		for (int i=0; i<(int)m_Marquee.Count; i++)
			v.Marquee.Add( m_Marquee[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcPushMarqueeNotify v)
	{
        if (v == null)
            return;
		m_Marquee.Clear();
		for( int i=0; i<v.Marquee.Count; i++)
			m_Marquee.Add(v.Marquee[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcPushMarqueeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcPushMarqueeNotify pb = ProtoBuf.Serializer.Deserialize<ChatRpcPushMarqueeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//跑马灯
	public List<string> m_Marquee;
	public int SizeMarquee()
	{
		return m_Marquee.Count;
	}
	public List<string> GetMarquee()
	{
		return m_Marquee;
	}
	public string GetMarquee(int Index)
	{
		if(Index<0 || Index>=(int)m_Marquee.Count)
			return "";
		return m_Marquee[Index];
	}
	public void SetMarquee( List<string> v )
	{
		m_Marquee=v;
	}
	public void SetMarquee( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_Marquee.Count)
			return;
		m_Marquee[Index] = v;
	}
	public void AddMarquee( string v )
	{
		m_Marquee.Add(v);
	}
	public void ClearMarquee( )
	{
		m_Marquee.Clear();
	}


};
//玩家或NPC对象说话通知封装类
[System.Serializable]
public class ChatRpcSayNotifyWraper
{

	//构造函数
	public ChatRpcSayNotifyWraper()
	{
		 m_ObjId = 0;
		 m_ChatId = 0;
		 m_Duration = 0;
		 m_ChatType = 0;
		 m_Interval = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_ChatId = 0;
		 m_Duration = 0;
		 m_ChatType = 0;
		 m_Interval = 0;

	}

 	//转化成Protobuffer类型函数
	public ChatRpcSayNotify ToPB()
	{
		ChatRpcSayNotify v = new ChatRpcSayNotify();
		v.ObjId = m_ObjId;
		v.ChatId = m_ChatId;
		v.Duration = m_Duration;
		v.ChatType = m_ChatType;
		v.Interval = m_Interval;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcSayNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_ChatId = v.ChatId;
		m_Duration = v.Duration;
		m_ChatType = v.ChatType;
		m_Interval = v.Interval;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcSayNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcSayNotify pb = ProtoBuf.Serializer.Deserialize<ChatRpcSayNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//说话人的objId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//String_ChatMenu表id
	public int m_ChatId;
	public int ChatId
	{
		get { return m_ChatId;}
		set { m_ChatId = value; }
	}
	//该聊天内容停留时间
	public int m_Duration;
	public int Duration
	{
		get { return m_Duration;}
		set { m_Duration = value; }
	}
	//对话显示类型：0：单次显示，1：循环显示
	public int m_ChatType;
	public int ChatType
	{
		get { return m_ChatType;}
		set { m_ChatType = value; }
	}
	//循环显示类型下的两次气泡的间隔时间
	public int m_Interval;
	public int Interval
	{
		get { return m_Interval;}
		set { m_Interval = value; }
	}


};
