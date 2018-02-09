
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
