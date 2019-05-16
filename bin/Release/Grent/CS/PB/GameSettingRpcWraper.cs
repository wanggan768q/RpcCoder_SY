
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBGameSetting.cs
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


//同步请求封装类
[System.Serializable]
public class GameSettingRpcSyncGameSettingAskWraper
{

	//构造函数
	public GameSettingRpcSyncGameSettingAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GameSettingRpcSyncGameSettingAsk ToPB()
	{
		GameSettingRpcSyncGameSettingAsk v = new GameSettingRpcSyncGameSettingAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameSettingRpcSyncGameSettingAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameSettingRpcSyncGameSettingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameSettingRpcSyncGameSettingAsk pb = ProtoBuf.Serializer.Deserialize<GameSettingRpcSyncGameSettingAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class GameSettingRpcSyncGameSettingReplyWraper
{

	//构造函数
	public GameSettingRpcSyncGameSettingReplyWraper()
	{
		 m_Result = -1;
		 m_GameSetting = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_GameSetting = "";

	}

 	//转化成Protobuffer类型函数
	public GameSettingRpcSyncGameSettingReply ToPB()
	{
		GameSettingRpcSyncGameSettingReply v = new GameSettingRpcSyncGameSettingReply();
		v.Result = m_Result;
		v.GameSetting = m_GameSetting;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameSettingRpcSyncGameSettingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_GameSetting = v.GameSetting;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameSettingRpcSyncGameSettingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameSettingRpcSyncGameSettingReply pb = ProtoBuf.Serializer.Deserialize<GameSettingRpcSyncGameSettingReply>(protoMS);
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
	//设置info
	public string m_GameSetting;
	public string GameSetting
	{
		get { return m_GameSetting;}
		set { m_GameSetting = value; }
	}


};
//设置请求封装类
[System.Serializable]
public class GameSettingRpcSettingAskWraper
{

	//构造函数
	public GameSettingRpcSettingAskWraper()
	{
		 m_GameSetting = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GameSetting = "";

	}

 	//转化成Protobuffer类型函数
	public GameSettingRpcSettingAsk ToPB()
	{
		GameSettingRpcSettingAsk v = new GameSettingRpcSettingAsk();
		v.GameSetting = m_GameSetting;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameSettingRpcSettingAsk v)
	{
        if (v == null)
            return;
		m_GameSetting = v.GameSetting;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameSettingRpcSettingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameSettingRpcSettingAsk pb = ProtoBuf.Serializer.Deserialize<GameSettingRpcSettingAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要设置的
	public string m_GameSetting;
	public string GameSetting
	{
		get { return m_GameSetting;}
		set { m_GameSetting = value; }
	}


};
//设置回应封装类
[System.Serializable]
public class GameSettingRpcSettingReplyWraper
{

	//构造函数
	public GameSettingRpcSettingReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public GameSettingRpcSettingReply ToPB()
	{
		GameSettingRpcSettingReply v = new GameSettingRpcSettingReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameSettingRpcSettingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameSettingRpcSettingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameSettingRpcSettingReply pb = ProtoBuf.Serializer.Deserialize<GameSettingRpcSettingReply>(protoMS);
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
//设置 通知通知封装类
[System.Serializable]
public class GameSettingRpcGameSettingNotifyNotifyWraper
{

	//构造函数
	public GameSettingRpcGameSettingNotifyNotifyWraper()
	{
		 m_GameSetting = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GameSetting = "";

	}

 	//转化成Protobuffer类型函数
	public GameSettingRpcGameSettingNotifyNotify ToPB()
	{
		GameSettingRpcGameSettingNotifyNotify v = new GameSettingRpcGameSettingNotifyNotify();
		v.GameSetting = m_GameSetting;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GameSettingRpcGameSettingNotifyNotify v)
	{
        if (v == null)
            return;
		m_GameSetting = v.GameSetting;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GameSettingRpcGameSettingNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GameSettingRpcGameSettingNotifyNotify pb = ProtoBuf.Serializer.Deserialize<GameSettingRpcGameSettingNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//设置
	public string m_GameSetting;
	public string GameSetting
	{
		get { return m_GameSetting;}
		set { m_GameSetting = value; }
	}


};
