
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
		 m_RoleInfo = new CharacterInfoWraper();
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleInfo = new CharacterInfoWraper();
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLoadSceneCompleteReply ToPB()
	{
		SceneRpcLoadSceneCompleteReply v = new SceneRpcLoadSceneCompleteReply();
		v.Result = m_Result;
		v.RoleInfo = m_RoleInfo.ToPB();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLoadSceneCompleteReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleInfo.FromPB(v.RoleInfo);
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;

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
	//人物信息
	public CharacterInfoWraper m_RoleInfo;
	public CharacterInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}
	//玩家objid
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
		 m_SceneId = -1;
		 m_MapId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_SceneId = -1;
		 m_MapId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcConnectGameServerReply ToPB()
	{
		SceneRpcConnectGameServerReply v = new SceneRpcConnectGameServerReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;
		v.MapId = m_MapId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcConnectGameServerReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;
		m_MapId = v.MapId;

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
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//表当中的mapid
	public int m_MapId;
	public int MapId
	{
		get { return m_MapId;}
		set { m_MapId = value; }
	}


};
//多线程移除场景上的玩家请求封装类
[System.Serializable]
public class SceneRpcChangeSceneAskWraper
{

	//构造函数
	public SceneRpcChangeSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcChangeSceneAsk ToPB()
	{
		SceneRpcChangeSceneAsk v = new SceneRpcChangeSceneAsk();
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcChangeSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcChangeSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcChangeSceneAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcChangeSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}


};
//多线程移除场景上的玩家回应封装类
[System.Serializable]
public class SceneRpcChangeSceneReplyWraper
{

	//构造函数
	public SceneRpcChangeSceneReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcChangeSceneReply ToPB()
	{
		SceneRpcChangeSceneReply v = new SceneRpcChangeSceneReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcChangeSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcChangeSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcChangeSceneReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcChangeSceneReply>(protoMS);
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
	//玩家的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//场景id
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}


};
//创建物体通知封装类
[System.Serializable]
public class SceneRpcCreateObjNotifyWraper
{

	//构造函数
	public SceneRpcCreateObjNotifyWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new V3Wraper();
		 m_Dir = (float)-1;
		 m_ObjType = -1;
		 m_ConfigId = -1;
		 m_Status = -1;
		 m_MoveSpeed = (float)-1;
		 m_RoleId = 0;
		 m_NickName = "";
		 m_Hp = -1;
		 m_TargetPos = new V3Wraper();
		 m_HpMax = -1;

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
		 m_RoleId = 0;
		 m_NickName = "";
		 m_Hp = -1;
		 m_TargetPos = new V3Wraper();
		 m_HpMax = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCreateObjNotify ToPB()
	{
		SceneRpcCreateObjNotify v = new SceneRpcCreateObjNotify();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjType = m_ObjType;
		v.ConfigId = m_ConfigId;
		v.Status = m_Status;
		v.MoveSpeed = m_MoveSpeed;
		v.RoleId = m_RoleId;
		v.NickName = m_NickName;
		v.Hp = m_Hp;
		v.TargetPos = m_TargetPos.ToPB();
		v.HpMax = m_HpMax;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCreateObjNotify v)
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
		m_RoleId = v.RoleId;
		m_NickName = v.NickName;
		m_Hp = v.Hp;
		m_TargetPos.FromPB(v.TargetPos);
		m_HpMax = v.HpMax;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcCreateObjNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcCreateObjNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcCreateObjNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
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
	//类型
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
	//MoveSpeed
	public float m_MoveSpeed;
	public float MoveSpeed
	{
		get { return m_MoveSpeed;}
		set { m_MoveSpeed = value; }
	}
	//玩家唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//名字昵称
	public string m_NickName;
	public string NickName
	{
		get { return m_NickName;}
		set { m_NickName = value; }
	}
	//血量
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//目标点（针对npc）
	public V3Wraper m_TargetPos;
	public V3Wraper TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}
	//血量上限
	public int m_HpMax;
	public int HpMax
	{
		get { return m_HpMax;}
		set { m_HpMax = value; }
	}


};
//SurroundingHuman请求封装类
[System.Serializable]
public class SceneRpcSurroundingHumanAskWraper
{

	//构造函数
	public SceneRpcSurroundingHumanAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSurroundingHumanAsk ToPB()
	{
		SceneRpcSurroundingHumanAsk v = new SceneRpcSurroundingHumanAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSurroundingHumanAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSurroundingHumanAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSurroundingHumanAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcSurroundingHumanAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//SurroundingHuman回应封装类
[System.Serializable]
public class SceneRpcSurroundingHumanReplyWraper
{

	//构造函数
	public SceneRpcSurroundingHumanReplyWraper()
	{
		 m_Result = -9999;
		m_RoleList = new List<CharacterInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_RoleList = new List<CharacterInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSurroundingHumanReply ToPB()
	{
		SceneRpcSurroundingHumanReply v = new SceneRpcSurroundingHumanReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_RoleList.Count; i++)
			v.RoleList.Add( m_RoleList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSurroundingHumanReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleList.Clear();
		for( int i=0; i<v.RoleList.Count; i++)
			m_RoleList.Add( new CharacterInfoWraper());
		for( int i=0; i<v.RoleList.Count; i++)
			m_RoleList[i].FromPB(v.RoleList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSurroundingHumanReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSurroundingHumanReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcSurroundingHumanReply>(protoMS);
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
	//RoleList
	public List<CharacterInfoWraper> m_RoleList;
	public int SizeRoleList()
	{
		return m_RoleList.Count;
	}
	public List<CharacterInfoWraper> GetRoleList()
	{
		return m_RoleList;
	}
	public CharacterInfoWraper GetRoleList(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleList.Count)
			return new CharacterInfoWraper();
		return m_RoleList[Index];
	}
	public void SetRoleList( List<CharacterInfoWraper> v )
	{
		m_RoleList=v;
	}
	public void SetRoleList( int Index, CharacterInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RoleList.Count)
			return;
		m_RoleList[Index] = v;
	}
	public void AddRoleList( CharacterInfoWraper v )
	{
		m_RoleList.Add(v);
	}
	public void ClearRoleList( )
	{
		m_RoleList.Clear();
	}


};
//进入场景通知封装类
[System.Serializable]
public class SceneRpcCEnterSceneNotifyWraper
{

	//构造函数
	public SceneRpcCEnterSceneNotifyWraper()
	{
		 m_SceneId = -1;
		 m_MapId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_MapId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCEnterSceneNotify ToPB()
	{
		SceneRpcCEnterSceneNotify v = new SceneRpcCEnterSceneNotify();
		v.SceneId = m_SceneId;
		v.MapId = m_MapId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCEnterSceneNotify v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_MapId = v.MapId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcCEnterSceneNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcCEnterSceneNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcCEnterSceneNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//表当中的mapid
	public int m_MapId;
	public int MapId
	{
		get { return m_MapId;}
		set { m_MapId = value; }
	}


};
//进入场景返回通知封装类
[System.Serializable]
public class SceneRpcSEnterSceneNotifyWraper
{

	//构造函数
	public SceneRpcSEnterSceneNotifyWraper()
	{
		 m_Result = -9999;
		 m_SceneId = -1;
		 m_SceneConfigId = -1;
		 m_MapId = -1;
		 m_RoleId = 0;
		 m_DungeonConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_SceneId = -1;
		 m_SceneConfigId = -1;
		 m_MapId = -1;
		 m_RoleId = 0;
		 m_DungeonConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSEnterSceneNotify ToPB()
	{
		SceneRpcSEnterSceneNotify v = new SceneRpcSEnterSceneNotify();
		v.Result = m_Result;
		v.SceneId = m_SceneId;
		v.SceneConfigId = m_SceneConfigId;
		v.MapId = m_MapId;
		v.RoleId = m_RoleId;
		v.DungeonConfigId = m_DungeonConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSEnterSceneNotify v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SceneId = v.SceneId;
		m_SceneConfigId = v.SceneConfigId;
		m_MapId = v.MapId;
		m_RoleId = v.RoleId;
		m_DungeonConfigId = v.DungeonConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSEnterSceneNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSEnterSceneNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcSEnterSceneNotify>(protoMS);
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
	//当返回不能进入，用这个来重新进入
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//SceneConfigId
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
	}
	//表当中的mapid
	public int m_MapId;
	public int MapId
	{
		get { return m_MapId;}
		set { m_MapId = value; }
	}
	//roleID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//DungeonConfigId
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}


};
//ObjDie通知封装类
[System.Serializable]
public class SceneRpcObjDieNotifyWraper
{

	//构造函数
	public SceneRpcObjDieNotifyWraper()
	{
		 m_ObjId = -1;
		 m_RespawnTime = -1;
		 m_ConfigId = -1;
		 m_ObjType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_RespawnTime = -1;
		 m_ConfigId = -1;
		 m_ObjType = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcObjDieNotify ToPB()
	{
		SceneRpcObjDieNotify v = new SceneRpcObjDieNotify();
		v.ObjId = m_ObjId;
		v.RespawnTime = m_RespawnTime;
		v.ConfigId = m_ConfigId;
		v.ObjType = m_ObjType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcObjDieNotify v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_RespawnTime = v.RespawnTime;
		m_ConfigId = v.ConfigId;
		m_ObjType = v.ObjType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcObjDieNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcObjDieNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcObjDieNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//ObjId
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//Respawn
	public int m_RespawnTime;
	public int RespawnTime
	{
		get { return m_RespawnTime;}
		set { m_RespawnTime = value; }
	}
	//ConfigId
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//ObjType
	public int m_ObjType;
	public int ObjType
	{
		get { return m_ObjType;}
		set { m_ObjType = value; }
	}


};
//collide请求封装类
[System.Serializable]
public class SceneRpcCollide_ChangeSceneAskWraper
{

	//构造函数
	public SceneRpcCollide_ChangeSceneAskWraper()
	{
		 m_Collide_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Collide_id = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCollide_ChangeSceneAsk ToPB()
	{
		SceneRpcCollide_ChangeSceneAsk v = new SceneRpcCollide_ChangeSceneAsk();
		v.Collide_id = m_Collide_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCollide_ChangeSceneAsk v)
	{
        if (v == null)
            return;
		m_Collide_id = v.Collide_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcCollide_ChangeSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcCollide_ChangeSceneAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcCollide_ChangeSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//碰撞点的ID
	public int m_Collide_id;
	public int Collide_id
	{
		get { return m_Collide_id;}
		set { m_Collide_id = value; }
	}


};
//collide回应封装类
[System.Serializable]
public class SceneRpcCollide_ChangeSceneReplyWraper
{

	//构造函数
	public SceneRpcCollide_ChangeSceneReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCollide_ChangeSceneReply ToPB()
	{
		SceneRpcCollide_ChangeSceneReply v = new SceneRpcCollide_ChangeSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCollide_ChangeSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcCollide_ChangeSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcCollide_ChangeSceneReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcCollide_ChangeSceneReply>(protoMS);
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
