
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBScene.cs
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


//进入场景请求封装类
[System.Serializable]
public class SceneRpcEnterSceneAskWraper
{

	//构造函数
	public SceneRpcEnterSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcEnterSceneAsk ToPB()
	{
		SceneRpcEnterSceneAsk v = new SceneRpcEnterSceneAsk();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcEnterSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcEnterSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcEnterSceneAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcEnterSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//进入场景回应封装类
[System.Serializable]
public class SceneRpcEnterSceneReplyWraper
{

	//构造函数
	public SceneRpcEnterSceneReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleInfo = new CharacterInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleInfo = new CharacterInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public SceneRpcEnterSceneReply ToPB()
	{
		SceneRpcEnterSceneReply v = new SceneRpcEnterSceneReply();
		v.Result = m_Result;
		v.RoleInfo = m_RoleInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcEnterSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleInfo.FromPB(v.RoleInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcEnterSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcEnterSceneReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcEnterSceneReply>(protoMS);
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
	//人物信息
	public CharacterInfoWraper m_RoleInfo;
	public CharacterInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}


};
//进入场景完成请求封装类
[System.Serializable]
public class SceneRpcLoadSceneCompleteAskWraper
{

	//构造函数
	public SceneRpcLoadSceneCompleteAskWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLoadSceneCompleteAsk ToPB()
	{
		SceneRpcLoadSceneCompleteAsk v = new SceneRpcLoadSceneCompleteAsk();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLoadSceneCompleteAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcLoadSceneCompleteAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcLoadSceneCompleteAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcLoadSceneCompleteAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//进入场景完成回应封装类
[System.Serializable]
public class SceneRpcLoadSceneCompleteReplyWraper
{

	//构造函数
	public SceneRpcLoadSceneCompleteReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLoadSceneCompleteReply ToPB()
	{
		SceneRpcLoadSceneCompleteReply v = new SceneRpcLoadSceneCompleteReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLoadSceneCompleteReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcLoadSceneCompleteReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcLoadSceneCompleteReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcLoadSceneCompleteReply>(protoMS);
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
//新玩家进入视野通知封装类
[System.Serializable]
public class SceneRpcNewPlayerNotifyWraper
{

	//构造函数
	public SceneRpcNewPlayerNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;
		 m_ObjType = -1;
		 m_ConfigId = -1;
		 m_Status = -1;
		 m_MoveSpeed = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;
		 m_ObjType = -1;
		 m_ConfigId = -1;
		 m_Status = -1;
		 m_MoveSpeed = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcNewPlayerNotify ToPB()
	{
		SceneRpcNewPlayerNotify v = new SceneRpcNewPlayerNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjType = m_ObjType;
		v.ConfigId = m_ConfigId;
		v.Status = m_Status;
		v.MoveSpeed = m_MoveSpeed;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcNewPlayerNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;
		m_ObjType = v.ObjType;
		m_ConfigId = v.ConfigId;
		m_Status = v.Status;
		m_MoveSpeed = v.MoveSpeed;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcNewPlayerNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcNewPlayerNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcNewPlayerNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
	public V3Wraper m_Pos;
	public V3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//方向
	public float m_Dir;
	public float Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}
	//obj type
	public int m_ObjType;
	public int ObjType
	{
		get { return m_ObjType;}
		set { m_ObjType = value; }
	}
	//config id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//移动速度
	public float m_MoveSpeed;
	public float MoveSpeed
	{
		get { return m_MoveSpeed;}
		set { m_MoveSpeed = value; }
	}


};
//删除玩家通知封装类
[System.Serializable]
public class SceneRpcDeletePlayerNotifyWraper
{

	//构造函数
	public SceneRpcDeletePlayerNotifyWraper()
	{
		 m_ObjId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcDeletePlayerNotify ToPB()
	{
		SceneRpcDeletePlayerNotify v = new SceneRpcDeletePlayerNotify();
		v.ObjId = m_ObjId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcDeletePlayerNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcDeletePlayerNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcDeletePlayerNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcDeletePlayerNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//连接场景服务器请求封装类
[System.Serializable]
public class SceneRpcConnectGameServerAskWraper
{

	//构造函数
	public SceneRpcConnectGameServerAskWraper()
	{
		 m_RoleId = 0;
		 m_Key = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Key = "";

	}

 	//转化成Protobuffer类型函数
	public SceneRpcConnectGameServerAsk ToPB()
	{
		SceneRpcConnectGameServerAsk v = new SceneRpcConnectGameServerAsk();
		v.RoleId = m_RoleId;
		v.Key = m_Key;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcConnectGameServerAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Key = v.Key;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcConnectGameServerAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcConnectGameServerAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcConnectGameServerAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//key
	public string m_Key;
	public string Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}


};
//连接场景服务器回应封装类
[System.Serializable]
public class SceneRpcConnectGameServerReplyWraper
{

	//构造函数
	public SceneRpcConnectGameServerReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcConnectGameServerReply ToPB()
	{
		SceneRpcConnectGameServerReply v = new SceneRpcConnectGameServerReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcConnectGameServerReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcConnectGameServerReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcConnectGameServerReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcConnectGameServerReply>(protoMS);
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
	//角色id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
