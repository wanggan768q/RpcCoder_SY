
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBQuest.cs
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


//OnAcceptQuest通知封装类
[System.Serializable]
public class QuestRpcOnAcceptQuestNotifyWraper
{

	//构造函数
	public QuestRpcOnAcceptQuestNotifyWraper()
	{
		 m_AcceptQuest = new QuestDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AcceptQuest = new QuestDataWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcOnAcceptQuestNotify ToPB()
	{
		QuestRpcOnAcceptQuestNotify v = new QuestRpcOnAcceptQuestNotify();
		v.AcceptQuest = m_AcceptQuest.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcOnAcceptQuestNotify v)
	{
        if (v == null)
            return;
		m_AcceptQuest.FromPB(v.AcceptQuest);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcOnAcceptQuestNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcOnAcceptQuestNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcOnAcceptQuestNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新接受的任务
	public QuestDataWraper m_AcceptQuest;
	public QuestDataWraper AcceptQuest
	{
		get { return m_AcceptQuest;}
		set { m_AcceptQuest = value; }
	}


};
//CompleteQuestStep请求封装类
[System.Serializable]
public class QuestRpcCompleteQuestStepAskWraper
{

	//构造函数
	public QuestRpcCompleteQuestStepAskWraper()
	{
		 m_QuestConfigId = -1;
		 m_QuestStep = -1;
		 m_TargetId = -1;
		 m_QuestStepEventType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;
		 m_QuestStep = -1;
		 m_TargetId = -1;
		 m_QuestStepEventType = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteQuestStepAsk ToPB()
	{
		QuestRpcCompleteQuestStepAsk v = new QuestRpcCompleteQuestStepAsk();
		v.QuestConfigId = m_QuestConfigId;
		v.QuestStep = m_QuestStep;
		v.TargetId = m_TargetId;
		v.QuestStepEventType = m_QuestStepEventType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteQuestStepAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;
		m_QuestStep = v.QuestStep;
		m_TargetId = v.TargetId;
		m_QuestStepEventType = v.QuestStepEventType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteQuestStepAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteQuestStepAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteQuestStepAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务表的id
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}
	//QuestStep
	public int m_QuestStep;
	public int QuestStep
	{
		get { return m_QuestStep;}
		set { m_QuestStep = value; }
	}
	//NpcConfigId
	public int m_TargetId;
	public int TargetId
	{
		get { return m_TargetId;}
		set { m_TargetId = value; }
	}
	//事件类型
	public int m_QuestStepEventType;
	public int QuestStepEventType
	{
		get { return m_QuestStepEventType;}
		set { m_QuestStepEventType = value; }
	}


};
//CompleteQuestStep回应封装类
[System.Serializable]
public class QuestRpcCompleteQuestStepReplyWraper
{

	//构造函数
	public QuestRpcCompleteQuestStepReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteQuestStepReply ToPB()
	{
		QuestRpcCompleteQuestStepReply v = new QuestRpcCompleteQuestStepReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteQuestStepReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteQuestStepReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteQuestStepReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteQuestStepReply>(protoMS);
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
//OnCompleteQuest通知封装类
[System.Serializable]
public class QuestRpcOnCompleteQuestNotifyWraper
{

	//构造函数
	public QuestRpcOnCompleteQuestNotifyWraper()
	{
		 m_QuestData = new QuestDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestData = new QuestDataWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcOnCompleteQuestNotify ToPB()
	{
		QuestRpcOnCompleteQuestNotify v = new QuestRpcOnCompleteQuestNotify();
		v.QuestData = m_QuestData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcOnCompleteQuestNotify v)
	{
        if (v == null)
            return;
		m_QuestData.FromPB(v.QuestData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcOnCompleteQuestNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcOnCompleteQuestNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcOnCompleteQuestNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务数据
	public QuestDataWraper m_QuestData;
	public QuestDataWraper QuestData
	{
		get { return m_QuestData;}
		set { m_QuestData = value; }
	}


};
//调用客户端Lua通知封装类
[System.Serializable]
public class QuestRpcCallClientLuaNotifyWraper
{

	//构造函数
	public QuestRpcCallClientLuaNotifyWraper()
	{
		 m_Str = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Str = "";

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCallClientLuaNotify ToPB()
	{
		QuestRpcCallClientLuaNotify v = new QuestRpcCallClientLuaNotify();
		v.Str = m_Str;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCallClientLuaNotify v)
	{
        if (v == null)
            return;
		m_Str = v.Str;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCallClientLuaNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCallClientLuaNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcCallClientLuaNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//lua函数字符串
	public string m_Str;
	public string Str
	{
		get { return m_Str;}
		set { m_Str = value; }
	}


};
//更新任务通知封装类
[System.Serializable]
public class QuestRpcUpdateQuestNotifyWraper
{

	//构造函数
	public QuestRpcUpdateQuestNotifyWraper()
	{
		 m_Quest = new QuestDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Quest = new QuestDataWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcUpdateQuestNotify ToPB()
	{
		QuestRpcUpdateQuestNotify v = new QuestRpcUpdateQuestNotify();
		v.Quest = m_Quest.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcUpdateQuestNotify v)
	{
        if (v == null)
            return;
		m_Quest.FromPB(v.Quest);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcUpdateQuestNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcUpdateQuestNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcUpdateQuestNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务数据
	public QuestDataWraper m_Quest;
	public QuestDataWraper Quest
	{
		get { return m_Quest;}
		set { m_Quest = value; }
	}


};
//放弃任务请求封装类
[System.Serializable]
public class QuestRpcGiveUpQuestAskWraper
{

	//构造函数
	public QuestRpcGiveUpQuestAskWraper()
	{
		 m_QuestConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGiveUpQuestAsk ToPB()
	{
		QuestRpcGiveUpQuestAsk v = new QuestRpcGiveUpQuestAsk();
		v.QuestConfigId = m_QuestConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGiveUpQuestAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGiveUpQuestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGiveUpQuestAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcGiveUpQuestAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务表的id
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}


};
//放弃任务回应封装类
[System.Serializable]
public class QuestRpcGiveUpQuestReplyWraper
{

	//构造函数
	public QuestRpcGiveUpQuestReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGiveUpQuestReply ToPB()
	{
		QuestRpcGiveUpQuestReply v = new QuestRpcGiveUpQuestReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGiveUpQuestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGiveUpQuestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGiveUpQuestReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcGiveUpQuestReply>(protoMS);
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
//完成任务请求封装类
[System.Serializable]
public class QuestRpcCompleteQuestAskWraper
{

	//构造函数
	public QuestRpcCompleteQuestAskWraper()
	{
		 m_QuestConfigId = -1;
		 m_TargetId = -1;
		 m_QuestEventType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;
		 m_TargetId = -1;
		 m_QuestEventType = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteQuestAsk ToPB()
	{
		QuestRpcCompleteQuestAsk v = new QuestRpcCompleteQuestAsk();
		v.QuestConfigId = m_QuestConfigId;
		v.TargetId = m_TargetId;
		v.QuestEventType = m_QuestEventType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteQuestAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;
		m_TargetId = v.TargetId;
		m_QuestEventType = v.QuestEventType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteQuestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteQuestAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteQuestAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务表的id
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}
	//NpcConfigId
	public int m_TargetId;
	public int TargetId
	{
		get { return m_TargetId;}
		set { m_TargetId = value; }
	}
	//事件类型
	public int m_QuestEventType;
	public int QuestEventType
	{
		get { return m_QuestEventType;}
		set { m_QuestEventType = value; }
	}


};
//完成任务回应封装类
[System.Serializable]
public class QuestRpcCompleteQuestReplyWraper
{

	//构造函数
	public QuestRpcCompleteQuestReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteQuestReply ToPB()
	{
		QuestRpcCompleteQuestReply v = new QuestRpcCompleteQuestReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteQuestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteQuestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteQuestReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteQuestReply>(protoMS);
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
//完成接受任务对话框请求封装类
[System.Serializable]
public class QuestRpcCompleteAcceptChatMenuAskWraper
{

	//构造函数
	public QuestRpcCompleteAcceptChatMenuAskWraper()
	{
		 m_QuestConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteAcceptChatMenuAsk ToPB()
	{
		QuestRpcCompleteAcceptChatMenuAsk v = new QuestRpcCompleteAcceptChatMenuAsk();
		v.QuestConfigId = m_QuestConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteAcceptChatMenuAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteAcceptChatMenuAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteAcceptChatMenuAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteAcceptChatMenuAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务表的id
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}


};
//完成接受任务对话框回应封装类
[System.Serializable]
public class QuestRpcCompleteAcceptChatMenuReplyWraper
{

	//构造函数
	public QuestRpcCompleteAcceptChatMenuReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteAcceptChatMenuReply ToPB()
	{
		QuestRpcCompleteAcceptChatMenuReply v = new QuestRpcCompleteAcceptChatMenuReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteAcceptChatMenuReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteAcceptChatMenuReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteAcceptChatMenuReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteAcceptChatMenuReply>(protoMS);
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
//客户端接受任务请求封装类
[System.Serializable]
public class QuestRpcAcceptQuestAskWraper
{

	//构造函数
	public QuestRpcAcceptQuestAskWraper()
	{
		 m_Type = -1;
		 m_QuestConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;
		 m_QuestConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcAcceptQuestAsk ToPB()
	{
		QuestRpcAcceptQuestAsk v = new QuestRpcAcceptQuestAsk();
		v.Type = m_Type;
		v.QuestConfigId = m_QuestConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcAcceptQuestAsk v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_QuestConfigId = v.QuestConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcAcceptQuestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcAcceptQuestAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcAcceptQuestAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//接受任务表
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}


};
//客户端接受任务回应封装类
[System.Serializable]
public class QuestRpcAcceptQuestReplyWraper
{

	//构造函数
	public QuestRpcAcceptQuestReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcAcceptQuestReply ToPB()
	{
		QuestRpcAcceptQuestReply v = new QuestRpcAcceptQuestReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcAcceptQuestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcAcceptQuestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcAcceptQuestReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcAcceptQuestReply>(protoMS);
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
//SyncQuest请求封装类
[System.Serializable]
public class QuestRpcSyncQuestAskWraper
{

	//构造函数
	public QuestRpcSyncQuestAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncQuestAsk ToPB()
	{
		QuestRpcSyncQuestAsk v = new QuestRpcSyncQuestAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncQuestAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncQuestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncQuestAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncQuestAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//SyncQuest回应封装类
[System.Serializable]
public class QuestRpcSyncQuestReplyWraper
{

	//构造函数
	public QuestRpcSyncQuestReplyWraper()
	{
		 m_Result = -1;
		 m_QuestList = new QuestListDataWraper();
		m_CompleteQuestIdsList = new List<int>();
		m_CanAcceptQuest = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_QuestList = new QuestListDataWraper();
		m_CompleteQuestIdsList = new List<int>();
		m_CanAcceptQuest = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncQuestReply ToPB()
	{
		QuestRpcSyncQuestReply v = new QuestRpcSyncQuestReply();
		v.Result = m_Result;
		v.QuestList = m_QuestList.ToPB();
		for (int i=0; i<(int)m_CompleteQuestIdsList.Count; i++)
			v.CompleteQuestIdsList.Add( m_CompleteQuestIdsList[i]);
		for (int i=0; i<(int)m_CanAcceptQuest.Count; i++)
			v.CanAcceptQuest.Add( m_CanAcceptQuest[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncQuestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_QuestList.FromPB(v.QuestList);
		m_CompleteQuestIdsList.Clear();
		for( int i=0; i<v.CompleteQuestIdsList.Count; i++)
			m_CompleteQuestIdsList.Add(v.CompleteQuestIdsList[i]);
		m_CanAcceptQuest.Clear();
		for( int i=0; i<v.CanAcceptQuest.Count; i++)
			m_CanAcceptQuest.Add(v.CanAcceptQuest[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncQuestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncQuestReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncQuestReply>(protoMS);
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
	//任务列表
	public QuestListDataWraper m_QuestList;
	public QuestListDataWraper QuestList
	{
		get { return m_QuestList;}
		set { m_QuestList = value; }
	}
	//完成任务列表
	public List<int> m_CompleteQuestIdsList;
	public int SizeCompleteQuestIdsList()
	{
		return m_CompleteQuestIdsList.Count;
	}
	public List<int> GetCompleteQuestIdsList()
	{
		return m_CompleteQuestIdsList;
	}
	public int GetCompleteQuestIdsList(int Index)
	{
		if(Index<0 || Index>=(int)m_CompleteQuestIdsList.Count)
			return -1;
		return m_CompleteQuestIdsList[Index];
	}
	public void SetCompleteQuestIdsList( List<int> v )
	{
		m_CompleteQuestIdsList=v;
	}
	public void SetCompleteQuestIdsList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_CompleteQuestIdsList.Count)
			return;
		m_CompleteQuestIdsList[Index] = v;
	}
	public void AddCompleteQuestIdsList( int v=-1 )
	{
		m_CompleteQuestIdsList.Add(v);
	}
	public void ClearCompleteQuestIdsList( )
	{
		m_CompleteQuestIdsList.Clear();
	}
	//可接的任务
	public List<int> m_CanAcceptQuest;
	public int SizeCanAcceptQuest()
	{
		return m_CanAcceptQuest.Count;
	}
	public List<int> GetCanAcceptQuest()
	{
		return m_CanAcceptQuest;
	}
	public int GetCanAcceptQuest(int Index)
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.Count)
			return -1;
		return m_CanAcceptQuest[Index];
	}
	public void SetCanAcceptQuest( List<int> v )
	{
		m_CanAcceptQuest=v;
	}
	public void SetCanAcceptQuest( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.Count)
			return;
		m_CanAcceptQuest[Index] = v;
	}
	public void AddCanAcceptQuest( int v=-1 )
	{
		m_CanAcceptQuest.Add(v);
	}
	public void ClearCanAcceptQuest( )
	{
		m_CanAcceptQuest.Clear();
	}


};
//GetReward请求封装类
[System.Serializable]
public class QuestRpcGetRewardAskWraper
{

	//构造函数
	public QuestRpcGetRewardAskWraper()
	{
		 m_QuestConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGetRewardAsk ToPB()
	{
		QuestRpcGetRewardAsk v = new QuestRpcGetRewardAsk();
		v.QuestConfigId = m_QuestConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGetRewardAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGetRewardAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGetRewardAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcGetRewardAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//接受任务表
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}


};
//GetReward回应封装类
[System.Serializable]
public class QuestRpcGetRewardReplyWraper
{

	//构造函数
	public QuestRpcGetRewardReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGetRewardReply ToPB()
	{
		QuestRpcGetRewardReply v = new QuestRpcGetRewardReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGetRewardReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGetRewardReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGetRewardReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcGetRewardReply>(protoMS);
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
//上次任务通知通知封装类
[System.Serializable]
public class QuestRpcRemoveQuestNotifyNotifyWraper
{

	//构造函数
	public QuestRpcRemoveQuestNotifyNotifyWraper()
	{
		m_QuestConfigId = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_QuestConfigId = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcRemoveQuestNotifyNotify ToPB()
	{
		QuestRpcRemoveQuestNotifyNotify v = new QuestRpcRemoveQuestNotifyNotify();
		for (int i=0; i<(int)m_QuestConfigId.Count; i++)
			v.QuestConfigId.Add( m_QuestConfigId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcRemoveQuestNotifyNotify v)
	{
        if (v == null)
            return;
		m_QuestConfigId.Clear();
		for( int i=0; i<v.QuestConfigId.Count; i++)
			m_QuestConfigId.Add(v.QuestConfigId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcRemoveQuestNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcRemoveQuestNotifyNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcRemoveQuestNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//接受任务表
	public List<int> m_QuestConfigId;
	public int SizeQuestConfigId()
	{
		return m_QuestConfigId.Count;
	}
	public List<int> GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	public int GetQuestConfigId(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.Count)
			return -1;
		return m_QuestConfigId[Index];
	}
	public void SetQuestConfigId( List<int> v )
	{
		m_QuestConfigId=v;
	}
	public void SetQuestConfigId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.Count)
			return;
		m_QuestConfigId[Index] = v;
	}
	public void AddQuestConfigId( int v=-1 )
	{
		m_QuestConfigId.Add(v);
	}
	public void ClearQuestConfigId( )
	{
		m_QuestConfigId.Clear();
	}


};
//获取某个任务数据请求封装类
[System.Serializable]
public class QuestRpcGetQuestDataAskWraper
{

	//构造函数
	public QuestRpcGetQuestDataAskWraper()
	{
		m_QuestConfigId = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_QuestConfigId = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGetQuestDataAsk ToPB()
	{
		QuestRpcGetQuestDataAsk v = new QuestRpcGetQuestDataAsk();
		for (int i=0; i<(int)m_QuestConfigId.Count; i++)
			v.QuestConfigId.Add( m_QuestConfigId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGetQuestDataAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId.Clear();
		for( int i=0; i<v.QuestConfigId.Count; i++)
			m_QuestConfigId.Add(v.QuestConfigId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGetQuestDataAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGetQuestDataAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcGetQuestDataAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//接受任务表
	public List<int> m_QuestConfigId;
	public int SizeQuestConfigId()
	{
		return m_QuestConfigId.Count;
	}
	public List<int> GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	public int GetQuestConfigId(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.Count)
			return -1;
		return m_QuestConfigId[Index];
	}
	public void SetQuestConfigId( List<int> v )
	{
		m_QuestConfigId=v;
	}
	public void SetQuestConfigId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.Count)
			return;
		m_QuestConfigId[Index] = v;
	}
	public void AddQuestConfigId( int v=-1 )
	{
		m_QuestConfigId.Add(v);
	}
	public void ClearQuestConfigId( )
	{
		m_QuestConfigId.Clear();
	}


};
//获取某个任务数据回应封装类
[System.Serializable]
public class QuestRpcGetQuestDataReplyWraper
{

	//构造函数
	public QuestRpcGetQuestDataReplyWraper()
	{
		 m_Result = -1;
		m_QuestList = new List<QuestDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_QuestList = new List<QuestDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcGetQuestDataReply ToPB()
	{
		QuestRpcGetQuestDataReply v = new QuestRpcGetQuestDataReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_QuestList.Count; i++)
			v.QuestList.Add( m_QuestList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcGetQuestDataReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_QuestList.Clear();
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList.Add( new QuestDataWraper());
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList[i].FromPB(v.QuestList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcGetQuestDataReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcGetQuestDataReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcGetQuestDataReply>(protoMS);
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
	//返回给客户端的任务列表
	public List<QuestDataWraper> m_QuestList;
	public int SizeQuestList()
	{
		return m_QuestList.Count;
	}
	public List<QuestDataWraper> GetQuestList()
	{
		return m_QuestList;
	}
	public QuestDataWraper GetQuestList(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return new QuestDataWraper();
		return m_QuestList[Index];
	}
	public void SetQuestList( List<QuestDataWraper> v )
	{
		m_QuestList=v;
	}
	public void SetQuestList( int Index, QuestDataWraper v )
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return;
		m_QuestList[Index] = v;
	}
	public void AddQuestList( QuestDataWraper v )
	{
		m_QuestList.Add(v);
	}
	public void ClearQuestList( )
	{
		m_QuestList.Clear();
	}


};
//每日活动请求封装类
[System.Serializable]
public class QuestRpcSyncDailyQuestAskWraper
{

	//构造函数
	public QuestRpcSyncDailyQuestAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncDailyQuestAsk ToPB()
	{
		QuestRpcSyncDailyQuestAsk v = new QuestRpcSyncDailyQuestAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncDailyQuestAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncDailyQuestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncDailyQuestAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncDailyQuestAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//每日活动回应封装类
[System.Serializable]
public class QuestRpcSyncDailyQuestReplyWraper
{

	//构造函数
	public QuestRpcSyncDailyQuestReplyWraper()
	{
		 m_Result = -1;
		 m_DailyQuestList = new DailyQuestListWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_DailyQuestList = new DailyQuestListWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncDailyQuestReply ToPB()
	{
		QuestRpcSyncDailyQuestReply v = new QuestRpcSyncDailyQuestReply();
		v.Result = m_Result;
		v.DailyQuestList = m_DailyQuestList.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncDailyQuestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_DailyQuestList.FromPB(v.DailyQuestList);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncDailyQuestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncDailyQuestReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncDailyQuestReply>(protoMS);
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
	//DailyQuestList
	public DailyQuestListWraper m_DailyQuestList;
	public DailyQuestListWraper DailyQuestList
	{
		get { return m_DailyQuestList;}
		set { m_DailyQuestList = value; }
	}


};
//每日活动任务更新通知封装类
[System.Serializable]
public class QuestRpcDailyQuestUpdateNotifyWraper
{

	//构造函数
	public QuestRpcDailyQuestUpdateNotifyWraper()
	{
		 m_AtivityQuestData = new DailyQuestWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AtivityQuestData = new DailyQuestWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcDailyQuestUpdateNotify ToPB()
	{
		QuestRpcDailyQuestUpdateNotify v = new QuestRpcDailyQuestUpdateNotify();
		v.AtivityQuestData = m_AtivityQuestData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcDailyQuestUpdateNotify v)
	{
        if (v == null)
            return;
		m_AtivityQuestData.FromPB(v.AtivityQuestData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcDailyQuestUpdateNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcDailyQuestUpdateNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcDailyQuestUpdateNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//每日活动数据
	public DailyQuestWraper m_AtivityQuestData;
	public DailyQuestWraper AtivityQuestData
	{
		get { return m_AtivityQuestData;}
		set { m_AtivityQuestData = value; }
	}


};
//任务消耗物品请求封装类
[System.Serializable]
public class QuestRpcConsumeItemAskWraper
{

	//构造函数
	public QuestRpcConsumeItemAskWraper()
	{
		 m_QuestConfigId = -1;
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestConfigId = -1;
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcConsumeItemAsk ToPB()
	{
		QuestRpcConsumeItemAsk v = new QuestRpcConsumeItemAsk();
		v.QuestConfigId = m_QuestConfigId;
		for (int i=0; i<(int)m_ItemData.Count; i++)
			v.ItemData.Add( m_ItemData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcConsumeItemAsk v)
	{
        if (v == null)
            return;
		m_QuestConfigId = v.QuestConfigId;
		m_ItemData.Clear();
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData[i].FromPB(v.ItemData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcConsumeItemAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcConsumeItemAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcConsumeItemAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务表的id
	public int m_QuestConfigId;
	public int QuestConfigId
	{
		get { return m_QuestConfigId;}
		set { m_QuestConfigId = value; }
	}
	//物品id
	public List<ItemSimpleDataWraper> m_ItemData;
	public int SizeItemData()
	{
		return m_ItemData.Count;
	}
	public List<ItemSimpleDataWraper> GetItemData()
	{
		return m_ItemData;
	}
	public ItemSimpleDataWraper GetItemData(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return new ItemSimpleDataWraper();
		return m_ItemData[Index];
	}
	public void SetItemData( List<ItemSimpleDataWraper> v )
	{
		m_ItemData=v;
	}
	public void SetItemData( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return;
		m_ItemData[Index] = v;
	}
	public void AddItemData( ItemSimpleDataWraper v )
	{
		m_ItemData.Add(v);
	}
	public void ClearItemData( )
	{
		m_ItemData.Clear();
	}


};
//任务消耗物品回应封装类
[System.Serializable]
public class QuestRpcConsumeItemReplyWraper
{

	//构造函数
	public QuestRpcConsumeItemReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcConsumeItemReply ToPB()
	{
		QuestRpcConsumeItemReply v = new QuestRpcConsumeItemReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcConsumeItemReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcConsumeItemReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcConsumeItemReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcConsumeItemReply>(protoMS);
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
//任务列表请求封装类
[System.Serializable]
public class QuestRpcQuestMaxListAskWraper
{

	//构造函数
	public QuestRpcQuestMaxListAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public QuestRpcQuestMaxListAsk ToPB()
	{
		QuestRpcQuestMaxListAsk v = new QuestRpcQuestMaxListAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcQuestMaxListAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcQuestMaxListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcQuestMaxListAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcQuestMaxListAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//任务列表回应封装类
[System.Serializable]
public class QuestRpcQuestMaxListReplyWraper
{

	//构造函数
	public QuestRpcQuestMaxListReplyWraper()
	{
		 m_Result = -1;
		 m_QuestList = new QuestMaxQuestListWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_QuestList = new QuestMaxQuestListWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcQuestMaxListReply ToPB()
	{
		QuestRpcQuestMaxListReply v = new QuestRpcQuestMaxListReply();
		v.Result = m_Result;
		v.QuestList = m_QuestList.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcQuestMaxListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_QuestList.FromPB(v.QuestList);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcQuestMaxListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcQuestMaxListReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcQuestMaxListReply>(protoMS);
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
	//任务列表
	public QuestMaxQuestListWraper m_QuestList;
	public QuestMaxQuestListWraper QuestList
	{
		get { return m_QuestList;}
		set { m_QuestList = value; }
	}


};
//最大类型任务通知通知封装类
[System.Serializable]
public class QuestRpcQuestMaxListNotifyNotifyWraper
{

	//构造函数
	public QuestRpcQuestMaxListNotifyNotifyWraper()
	{
		 m_QuestList = new QuestMaxQuestListWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestList = new QuestMaxQuestListWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcQuestMaxListNotifyNotify ToPB()
	{
		QuestRpcQuestMaxListNotifyNotify v = new QuestRpcQuestMaxListNotifyNotify();
		v.QuestList = m_QuestList.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcQuestMaxListNotifyNotify v)
	{
        if (v == null)
            return;
		m_QuestList.FromPB(v.QuestList);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcQuestMaxListNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcQuestMaxListNotifyNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcQuestMaxListNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务列表
	public QuestMaxQuestListWraper m_QuestList;
	public QuestMaxQuestListWraper QuestList
	{
		get { return m_QuestList;}
		set { m_QuestList = value; }
	}


};
//完成任务id请求请求封装类
[System.Serializable]
public class QuestRpcSyncCompleteQuestIdsAskWraper
{

	//构造函数
	public QuestRpcSyncCompleteQuestIdsAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncCompleteQuestIdsAsk ToPB()
	{
		QuestRpcSyncCompleteQuestIdsAsk v = new QuestRpcSyncCompleteQuestIdsAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncCompleteQuestIdsAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncCompleteQuestIdsAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncCompleteQuestIdsAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncCompleteQuestIdsAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//完成任务id请求回应封装类
[System.Serializable]
public class QuestRpcSyncCompleteQuestIdsReplyWraper
{

	//构造函数
	public QuestRpcSyncCompleteQuestIdsReplyWraper()
	{
		 m_Result = -1;
		 m_CompleteQuestIds = new CompletedQuestListWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_CompleteQuestIds = new CompletedQuestListWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncCompleteQuestIdsReply ToPB()
	{
		QuestRpcSyncCompleteQuestIdsReply v = new QuestRpcSyncCompleteQuestIdsReply();
		v.Result = m_Result;
		v.CompleteQuestIds = m_CompleteQuestIds.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncCompleteQuestIdsReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_CompleteQuestIds.FromPB(v.CompleteQuestIds);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncCompleteQuestIdsReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncCompleteQuestIdsReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncCompleteQuestIdsReply>(protoMS);
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
	//完成的任务列表
	public CompletedQuestListWraper m_CompleteQuestIds;
	public CompletedQuestListWraper CompleteQuestIds
	{
		get { return m_CompleteQuestIds;}
		set { m_CompleteQuestIds = value; }
	}


};
//完成的任务列表通知封装类
[System.Serializable]
public class QuestRpcCompleteQuestIdsNotifyNotifyWraper
{

	//构造函数
	public QuestRpcCompleteQuestIdsNotifyNotifyWraper()
	{
		 m_CompleteQuestIds = new CompletedQuestListWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CompleteQuestIds = new CompletedQuestListWraper();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcCompleteQuestIdsNotifyNotify ToPB()
	{
		QuestRpcCompleteQuestIdsNotifyNotify v = new QuestRpcCompleteQuestIdsNotifyNotify();
		v.CompleteQuestIds = m_CompleteQuestIds.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcCompleteQuestIdsNotifyNotify v)
	{
        if (v == null)
            return;
		m_CompleteQuestIds.FromPB(v.CompleteQuestIds);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcCompleteQuestIdsNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcCompleteQuestIdsNotifyNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcCompleteQuestIdsNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//完成的任务列表
	public CompletedQuestListWraper m_CompleteQuestIds;
	public CompletedQuestListWraper CompleteQuestIds
	{
		get { return m_CompleteQuestIds;}
		set { m_CompleteQuestIds = value; }
	}


};
//精英怪击杀次数请求封装类
[System.Serializable]
public class QuestRpcEliteFinishCountAskWraper
{

	//构造函数
	public QuestRpcEliteFinishCountAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public QuestRpcEliteFinishCountAsk ToPB()
	{
		QuestRpcEliteFinishCountAsk v = new QuestRpcEliteFinishCountAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcEliteFinishCountAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcEliteFinishCountAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcEliteFinishCountAsk pb = ProtoBuf.Serializer.Deserialize<QuestRpcEliteFinishCountAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//精英怪击杀次数回应封装类
[System.Serializable]
public class QuestRpcEliteFinishCountReplyWraper
{

	//构造函数
	public QuestRpcEliteFinishCountReplyWraper()
	{
		 m_Result = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public QuestRpcEliteFinishCountReply ToPB()
	{
		QuestRpcEliteFinishCountReply v = new QuestRpcEliteFinishCountReply();
		v.Result = m_Result;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcEliteFinishCountReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcEliteFinishCountReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcEliteFinishCountReply pb = ProtoBuf.Serializer.Deserialize<QuestRpcEliteFinishCountReply>(protoMS);
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
	//精英怪击杀次数
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//通知新可接任务通知封装类
[System.Serializable]
public class QuestRpcSyncCanAcceptQuestNotifyWraper
{

	//构造函数
	public QuestRpcSyncCanAcceptQuestNotifyWraper()
	{
		m_CanAcceptQuest = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_CanAcceptQuest = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public QuestRpcSyncCanAcceptQuestNotify ToPB()
	{
		QuestRpcSyncCanAcceptQuestNotify v = new QuestRpcSyncCanAcceptQuestNotify();
		for (int i=0; i<(int)m_CanAcceptQuest.Count; i++)
			v.CanAcceptQuest.Add( m_CanAcceptQuest[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestRpcSyncCanAcceptQuestNotify v)
	{
        if (v == null)
            return;
		m_CanAcceptQuest.Clear();
		for( int i=0; i<v.CanAcceptQuest.Count; i++)
			m_CanAcceptQuest.Add(v.CanAcceptQuest[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestRpcSyncCanAcceptQuestNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestRpcSyncCanAcceptQuestNotify pb = ProtoBuf.Serializer.Deserialize<QuestRpcSyncCanAcceptQuestNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//新的可接任务
	public List<int> m_CanAcceptQuest;
	public int SizeCanAcceptQuest()
	{
		return m_CanAcceptQuest.Count;
	}
	public List<int> GetCanAcceptQuest()
	{
		return m_CanAcceptQuest;
	}
	public int GetCanAcceptQuest(int Index)
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.Count)
			return -1;
		return m_CanAcceptQuest[Index];
	}
	public void SetCanAcceptQuest( List<int> v )
	{
		m_CanAcceptQuest=v;
	}
	public void SetCanAcceptQuest( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.Count)
			return;
		m_CanAcceptQuest[Index] = v;
	}
	public void AddCanAcceptQuest( int v=-1 )
	{
		m_CanAcceptQuest.Add(v);
	}
	public void ClearCanAcceptQuest( )
	{
		m_CanAcceptQuest.Clear();
	}


};
