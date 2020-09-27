
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
		 m_Forbid_endtime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Forbid_endtime = -1;

	}

 	//转化成Protobuffer类型函数
	public ChatRpcChatReply ToPB()
	{
		ChatRpcChatReply v = new ChatRpcChatReply();
		v.Result = m_Result;
		v.Forbid_endtime = m_Forbid_endtime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcChatReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Forbid_endtime = v.Forbid_endtime;

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
	//禁言截至时间
	public int m_Forbid_endtime;
	public int Forbid_endtime
	{
		get { return m_Forbid_endtime;}
		set { m_Forbid_endtime = value; }
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
		m_Marquee = new List<AppendStringWraper>();
		 m_Priority = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Marquee = new List<AppendStringWraper>();
		 m_Priority = -1;

	}

 	//转化成Protobuffer类型函数
	public ChatRpcPushMarqueeNotify ToPB()
	{
		ChatRpcPushMarqueeNotify v = new ChatRpcPushMarqueeNotify();
		for (int i=0; i<(int)m_Marquee.Count; i++)
			v.Marquee.Add( m_Marquee[i].ToPB());
		v.Priority = m_Priority;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcPushMarqueeNotify v)
	{
        if (v == null)
            return;
		m_Marquee.Clear();
		for( int i=0; i<v.Marquee.Count; i++)
			m_Marquee.Add( new AppendStringWraper());
		for( int i=0; i<v.Marquee.Count; i++)
			m_Marquee[i].FromPB(v.Marquee[i]);
		m_Priority = v.Priority;

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
	public List<AppendStringWraper> m_Marquee;
	public int SizeMarquee()
	{
		return m_Marquee.Count;
	}
	public List<AppendStringWraper> GetMarquee()
	{
		return m_Marquee;
	}
	public AppendStringWraper GetMarquee(int Index)
	{
		if(Index<0 || Index>=(int)m_Marquee.Count)
			return new AppendStringWraper();
		return m_Marquee[Index];
	}
	public void SetMarquee( List<AppendStringWraper> v )
	{
		m_Marquee=v;
	}
	public void SetMarquee( int Index, AppendStringWraper v )
	{
		if(Index<0 || Index>=(int)m_Marquee.Count)
			return;
		m_Marquee[Index] = v;
	}
	public void AddMarquee( AppendStringWraper v )
	{
		m_Marquee.Add(v);
	}
	public void ClearMarquee( )
	{
		m_Marquee.Clear();
	}
	//优先级
	public int m_Priority;
	public int Priority
	{
		get { return m_Priority;}
		set { m_Priority = value; }
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
//服务器通知封装类
[System.Serializable]
public class ChatRpcServerChatNotifyWraper
{

	//构造函数
	public ChatRpcServerChatNotifyWraper()
	{
		 m_Id = -1;
		 m_Channel = -1;
		m_IParams = new List<int>();
		m_SParams = new List<string>();
		m_Items = new List<ItemDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Channel = -1;
		m_IParams = new List<int>();
		m_SParams = new List<string>();
		m_Items = new List<ItemDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ChatRpcServerChatNotify ToPB()
	{
		ChatRpcServerChatNotify v = new ChatRpcServerChatNotify();
		v.Id = m_Id;
		v.Channel = m_Channel;
		for (int i=0; i<(int)m_IParams.Count; i++)
			v.IParams.Add( m_IParams[i]);
		for (int i=0; i<(int)m_SParams.Count; i++)
			v.SParams.Add( m_SParams[i]);
		for (int i=0; i<(int)m_Items.Count; i++)
			v.Items.Add( m_Items[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRpcServerChatNotify v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Channel = v.Channel;
		m_IParams.Clear();
		for( int i=0; i<v.IParams.Count; i++)
			m_IParams.Add(v.IParams[i]);
		m_SParams.Clear();
		for( int i=0; i<v.SParams.Count; i++)
			m_SParams.Add(v.SParams[i]);
		m_Items.Clear();
		for( int i=0; i<v.Items.Count; i++)
			m_Items.Add( new ItemDataWraper());
		for( int i=0; i<v.Items.Count; i++)
			m_Items[i].FromPB(v.Items[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRpcServerChatNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRpcServerChatNotify pb = ProtoBuf.Serializer.Deserialize<ChatRpcServerChatNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//StringUi的id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//频道
	public int m_Channel;
	public int Channel
	{
		get { return m_Channel;}
		set { m_Channel = value; }
	}
	//整型参数
	public List<int> m_IParams;
	public int SizeIParams()
	{
		return m_IParams.Count;
	}
	public List<int> GetIParams()
	{
		return m_IParams;
	}
	public int GetIParams(int Index)
	{
		if(Index<0 || Index>=(int)m_IParams.Count)
			return -1;
		return m_IParams[Index];
	}
	public void SetIParams( List<int> v )
	{
		m_IParams=v;
	}
	public void SetIParams( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_IParams.Count)
			return;
		m_IParams[Index] = v;
	}
	public void AddIParams( int v=-1 )
	{
		m_IParams.Add(v);
	}
	public void ClearIParams( )
	{
		m_IParams.Clear();
	}
	//字串参数
	public List<string> m_SParams;
	public int SizeSParams()
	{
		return m_SParams.Count;
	}
	public List<string> GetSParams()
	{
		return m_SParams;
	}
	public string GetSParams(int Index)
	{
		if(Index<0 || Index>=(int)m_SParams.Count)
			return "";
		return m_SParams[Index];
	}
	public void SetSParams( List<string> v )
	{
		m_SParams=v;
	}
	public void SetSParams( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_SParams.Count)
			return;
		m_SParams[Index] = v;
	}
	public void AddSParams( string v )
	{
		m_SParams.Add(v);
	}
	public void ClearSParams( )
	{
		m_SParams.Clear();
	}
	//道具列表
	public List<ItemDataWraper> m_Items;
	public int SizeItems()
	{
		return m_Items.Count;
	}
	public List<ItemDataWraper> GetItems()
	{
		return m_Items;
	}
	public ItemDataWraper GetItems(int Index)
	{
		if(Index<0 || Index>=(int)m_Items.Count)
			return new ItemDataWraper();
		return m_Items[Index];
	}
	public void SetItems( List<ItemDataWraper> v )
	{
		m_Items=v;
	}
	public void SetItems( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Items.Count)
			return;
		m_Items[Index] = v;
	}
	public void AddItems( ItemDataWraper v )
	{
		m_Items.Add(v);
	}
	public void ClearItems( )
	{
		m_Items.Clear();
	}


};
