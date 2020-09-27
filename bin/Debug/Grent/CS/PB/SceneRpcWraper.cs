
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
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_ObjData = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_ObjData = new byte[0];

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLoadSceneCompleteReply ToPB()
	{
		SceneRpcLoadSceneCompleteReply v = new SceneRpcLoadSceneCompleteReply();
		v.Result = m_Result;
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.ObjData = m_ObjData;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLoadSceneCompleteReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;
		m_ObjData = v.ObjData;

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
	//玩家objid
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//位置
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
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
	//Obj 数据
	public byte[] m_ObjData;
	public byte[] ObjData
	{
		get { return m_ObjData;}
		set { m_ObjData = value; }
	}


};
//删除玩家通知封装类
[System.Serializable]
public class SceneRpcDeletePlayerNotifyWraper
{

	//构造函数
	public SceneRpcDeletePlayerNotifyWraper()
	{
		m_Delete_list = new List<ObjDeleteInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Delete_list = new List<ObjDeleteInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SceneRpcDeletePlayerNotify ToPB()
	{
		SceneRpcDeletePlayerNotify v = new SceneRpcDeletePlayerNotify();
		for (int i=0; i<(int)m_Delete_list.Count; i++)
			v.Delete_list.Add( m_Delete_list[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcDeletePlayerNotify v)
	{
        if (v == null)
            return;
		m_Delete_list.Clear();
		for( int i=0; i<v.Delete_list.Count; i++)
			m_Delete_list.Add( new ObjDeleteInfoWraper());
		for( int i=0; i<v.Delete_list.Count; i++)
			m_Delete_list[i].FromPB(v.Delete_list[i]);

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

	//删除信息列表
	public List<ObjDeleteInfoWraper> m_Delete_list;
	public int SizeDelete_list()
	{
		return m_Delete_list.Count;
	}
	public List<ObjDeleteInfoWraper> GetDelete_list()
	{
		return m_Delete_list;
	}
	public ObjDeleteInfoWraper GetDelete_list(int Index)
	{
		if(Index<0 || Index>=(int)m_Delete_list.Count)
			return new ObjDeleteInfoWraper();
		return m_Delete_list[Index];
	}
	public void SetDelete_list( List<ObjDeleteInfoWraper> v )
	{
		m_Delete_list=v;
	}
	public void SetDelete_list( int Index, ObjDeleteInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Delete_list.Count)
			return;
		m_Delete_list[Index] = v;
	}
	public void AddDelete_list( ObjDeleteInfoWraper v )
	{
		m_Delete_list.Add(v);
	}
	public void ClearDelete_list( )
	{
		m_Delete_list.Clear();
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
		 m_SceneID = -1;
		 m_LineID = -1;
		 m_GameToken = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Key = "";
		 m_SceneID = -1;
		 m_LineID = -1;
		 m_GameToken = "";

	}

 	//转化成Protobuffer类型函数
	public SceneRpcConnectGameServerAsk ToPB()
	{
		SceneRpcConnectGameServerAsk v = new SceneRpcConnectGameServerAsk();
		v.RoleId = m_RoleId;
		v.Key = m_Key;
		v.SceneID = m_SceneID;
		v.LineID = m_LineID;
		v.GameToken = m_GameToken;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcConnectGameServerAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Key = v.Key;
		m_SceneID = v.SceneID;
		m_LineID = v.LineID;
		m_GameToken = v.GameToken;

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
	//SceneID
	public int m_SceneID;
	public int SceneID
	{
		get { return m_SceneID;}
		set { m_SceneID = value; }
	}
	//LineID
	public int m_LineID;
	public int LineID
	{
		get { return m_LineID;}
		set { m_LineID = value; }
	}
	//GameToken
	public string m_GameToken;
	public string GameToken
	{
		get { return m_GameToken;}
		set { m_GameToken = value; }
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
		 m_GameToken = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_SceneId = -1;
		 m_MapId = -1;
		 m_GameToken = "";

	}

 	//转化成Protobuffer类型函数
	public SceneRpcConnectGameServerReply ToPB()
	{
		SceneRpcConnectGameServerReply v = new SceneRpcConnectGameServerReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;
		v.MapId = m_MapId;
		v.GameToken = m_GameToken;

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
		m_GameToken = v.GameToken;

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
	//GameToken
	public string m_GameToken;
	public string GameToken
	{
		get { return m_GameToken;}
		set { m_GameToken = value; }
	}


};
//创建物体通知封装类
[System.Serializable]
public class SceneRpcCreateObjNotifyWraper
{

	//构造函数
	public SceneRpcCreateObjNotifyWraper()
	{
		m_Create_list = new List<ObjCreateInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Create_list = new List<ObjCreateInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCreateObjNotify ToPB()
	{
		SceneRpcCreateObjNotify v = new SceneRpcCreateObjNotify();
		for (int i=0; i<(int)m_Create_list.Count; i++)
			v.Create_list.Add( m_Create_list[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCreateObjNotify v)
	{
        if (v == null)
            return;
		m_Create_list.Clear();
		for( int i=0; i<v.Create_list.Count; i++)
			m_Create_list.Add( new ObjCreateInfoWraper());
		for( int i=0; i<v.Create_list.Count; i++)
			m_Create_list[i].FromPB(v.Create_list[i]);

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

	//创建信息列表
	public List<ObjCreateInfoWraper> m_Create_list;
	public int SizeCreate_list()
	{
		return m_Create_list.Count;
	}
	public List<ObjCreateInfoWraper> GetCreate_list()
	{
		return m_Create_list;
	}
	public ObjCreateInfoWraper GetCreate_list(int Index)
	{
		if(Index<0 || Index>=(int)m_Create_list.Count)
			return new ObjCreateInfoWraper();
		return m_Create_list[Index];
	}
	public void SetCreate_list( List<ObjCreateInfoWraper> v )
	{
		m_Create_list=v;
	}
	public void SetCreate_list( int Index, ObjCreateInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Create_list.Count)
			return;
		m_Create_list[Index] = v;
	}
	public void AddCreate_list( ObjCreateInfoWraper v )
	{
		m_Create_list.Add(v);
	}
	public void ClearCreate_list( )
	{
		m_Create_list.Clear();
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
		 m_LineId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_MapId = -1;
		 m_LineId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcCEnterSceneNotify ToPB()
	{
		SceneRpcCEnterSceneNotify v = new SceneRpcCEnterSceneNotify();
		v.SceneId = m_SceneId;
		v.MapId = m_MapId;
		v.LineId = m_LineId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcCEnterSceneNotify v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_MapId = v.MapId;
		m_LineId = v.LineId;

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
	//LineId
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
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
		 m_LineId = -1;
		m_TypeConfig = new List<IntPairWraper>();

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
		 m_LineId = -1;
		m_TypeConfig = new List<IntPairWraper>();

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
		v.LineId = m_LineId;
		for (int i=0; i<(int)m_TypeConfig.Count; i++)
			v.TypeConfig.Add( m_TypeConfig[i].ToPB());

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
		m_LineId = v.LineId;
		m_TypeConfig.Clear();
		for( int i=0; i<v.TypeConfig.Count; i++)
			m_TypeConfig.Add( new IntPairWraper());
		for( int i=0; i<v.TypeConfig.Count; i++)
			m_TypeConfig[i].FromPB(v.TypeConfig[i]);

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
	//LineId
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
	}
	//key是场景类型，value配置表
	public List<IntPairWraper> m_TypeConfig;
	public int SizeTypeConfig()
	{
		return m_TypeConfig.Count;
	}
	public List<IntPairWraper> GetTypeConfig()
	{
		return m_TypeConfig;
	}
	public IntPairWraper GetTypeConfig(int Index)
	{
		if(Index<0 || Index>=(int)m_TypeConfig.Count)
			return new IntPairWraper();
		return m_TypeConfig[Index];
	}
	public void SetTypeConfig( List<IntPairWraper> v )
	{
		m_TypeConfig=v;
	}
	public void SetTypeConfig( int Index, IntPairWraper v )
	{
		if(Index<0 || Index>=(int)m_TypeConfig.Count)
			return;
		m_TypeConfig[Index] = v;
	}
	public void AddTypeConfig( IntPairWraper v )
	{
		m_TypeConfig.Add(v);
	}
	public void ClearTypeConfig( )
	{
		m_TypeConfig.Clear();
	}


};
//ObjDie通知封装类
[System.Serializable]
public class SceneRpcObjDieNotifyWraper
{

	//构造函数
	public SceneRpcObjDieNotifyWraper()
	{
		 m_ObjId = 0;
		 m_RespawnTime = -1;
		 m_ConfigId = -1;
		 m_ObjType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
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
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
//进入镜像请求封装类
[System.Serializable]
public class SceneRpcEnterMirrorAskWraper
{

	//构造函数
	public SceneRpcEnterMirrorAskWraper()
	{
		 m_MirrorID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MirrorID = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcEnterMirrorAsk ToPB()
	{
		SceneRpcEnterMirrorAsk v = new SceneRpcEnterMirrorAsk();
		v.MirrorID = m_MirrorID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcEnterMirrorAsk v)
	{
        if (v == null)
            return;
		m_MirrorID = v.MirrorID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcEnterMirrorAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcEnterMirrorAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcEnterMirrorAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//镜像ID
	public int m_MirrorID;
	public int MirrorID
	{
		get { return m_MirrorID;}
		set { m_MirrorID = value; }
	}


};
//进入镜像回应封装类
[System.Serializable]
public class SceneRpcEnterMirrorReplyWraper
{

	//构造函数
	public SceneRpcEnterMirrorReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcEnterMirrorReply ToPB()
	{
		SceneRpcEnterMirrorReply v = new SceneRpcEnterMirrorReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcEnterMirrorReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcEnterMirrorReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcEnterMirrorReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcEnterMirrorReply>(protoMS);
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
//进入镜像场景通知封装类
[System.Serializable]
public class SceneRpcSEnterMirrorSceneNotifyWraper
{

	//构造函数
	public SceneRpcSEnterMirrorSceneNotifyWraper()
	{
		 m_MapID = -1;
		 m_MirrorID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MapID = -1;
		 m_MirrorID = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSEnterMirrorSceneNotify ToPB()
	{
		SceneRpcSEnterMirrorSceneNotify v = new SceneRpcSEnterMirrorSceneNotify();
		v.MapID = m_MapID;
		v.MirrorID = m_MirrorID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSEnterMirrorSceneNotify v)
	{
        if (v == null)
            return;
		m_MapID = v.MapID;
		m_MirrorID = v.MirrorID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSEnterMirrorSceneNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSEnterMirrorSceneNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcSEnterMirrorSceneNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//地图ID
	public int m_MapID;
	public int MapID
	{
		get { return m_MapID;}
		set { m_MapID = value; }
	}
	//镜像ID
	public int m_MirrorID;
	public int MirrorID
	{
		get { return m_MirrorID;}
		set { m_MirrorID = value; }
	}


};
//退出镜像请求封装类
[System.Serializable]
public class SceneRpcExitMirrorSceneAskWraper
{

	//构造函数
	public SceneRpcExitMirrorSceneAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcExitMirrorSceneAsk ToPB()
	{
		SceneRpcExitMirrorSceneAsk v = new SceneRpcExitMirrorSceneAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcExitMirrorSceneAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcExitMirrorSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcExitMirrorSceneAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcExitMirrorSceneAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//退出镜像回应封装类
[System.Serializable]
public class SceneRpcExitMirrorSceneReplyWraper
{

	//构造函数
	public SceneRpcExitMirrorSceneReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcExitMirrorSceneReply ToPB()
	{
		SceneRpcExitMirrorSceneReply v = new SceneRpcExitMirrorSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcExitMirrorSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcExitMirrorSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcExitMirrorSceneReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcExitMirrorSceneReply>(protoMS);
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
//ChangeSceneLeave通知封装类
[System.Serializable]
public class SceneRpcChangeSceneLeaveNotifyWraper
{

	//构造函数
	public SceneRpcChangeSceneLeaveNotifyWraper()
	{
		 m_TargetLineID = -1;
		 m_TargetMapID = -1;
		 m_RoleID = 0;
		 m_CopyID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TargetLineID = -1;
		 m_TargetMapID = -1;
		 m_RoleID = 0;
		 m_CopyID = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcChangeSceneLeaveNotify ToPB()
	{
		SceneRpcChangeSceneLeaveNotify v = new SceneRpcChangeSceneLeaveNotify();
		v.TargetLineID = m_TargetLineID;
		v.TargetMapID = m_TargetMapID;
		v.RoleID = m_RoleID;
		v.CopyID = m_CopyID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcChangeSceneLeaveNotify v)
	{
        if (v == null)
            return;
		m_TargetLineID = v.TargetLineID;
		m_TargetMapID = v.TargetMapID;
		m_RoleID = v.RoleID;
		m_CopyID = v.CopyID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcChangeSceneLeaveNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcChangeSceneLeaveNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcChangeSceneLeaveNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//TargetLineID
	public int m_TargetLineID;
	public int TargetLineID
	{
		get { return m_TargetLineID;}
		set { m_TargetLineID = value; }
	}
	//TargetMapID
	public int m_TargetMapID;
	public int TargetMapID
	{
		get { return m_TargetMapID;}
		set { m_TargetMapID = value; }
	}
	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//CopyID
	public int m_CopyID;
	public int CopyID
	{
		get { return m_CopyID;}
		set { m_CopyID = value; }
	}


};
//ChangeLine请求封装类
[System.Serializable]
public class SceneRpcChangeLineAskWraper
{

	//构造函数
	public SceneRpcChangeLineAskWraper()
	{
		 m_LineID = -1;
		 m_MapID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LineID = -1;
		 m_MapID = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcChangeLineAsk ToPB()
	{
		SceneRpcChangeLineAsk v = new SceneRpcChangeLineAsk();
		v.LineID = m_LineID;
		v.MapID = m_MapID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcChangeLineAsk v)
	{
        if (v == null)
            return;
		m_LineID = v.LineID;
		m_MapID = v.MapID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcChangeLineAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcChangeLineAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcChangeLineAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//LineID
	public int m_LineID;
	public int LineID
	{
		get { return m_LineID;}
		set { m_LineID = value; }
	}
	//MapID
	public int m_MapID;
	public int MapID
	{
		get { return m_MapID;}
		set { m_MapID = value; }
	}


};
//ChangeLine回应封装类
[System.Serializable]
public class SceneRpcChangeLineReplyWraper
{

	//构造函数
	public SceneRpcChangeLineReplyWraper()
	{
		 m_Result = -1;
		 m_LineID = -1;
		 m_MapID = -1;
		 m_RoleID = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_LineID = -1;
		 m_MapID = -1;
		 m_RoleID = 0;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcChangeLineReply ToPB()
	{
		SceneRpcChangeLineReply v = new SceneRpcChangeLineReply();
		v.Result = m_Result;
		v.LineID = m_LineID;
		v.MapID = m_MapID;
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcChangeLineReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_LineID = v.LineID;
		m_MapID = v.MapID;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcChangeLineReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcChangeLineReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcChangeLineReply>(protoMS);
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
	//LineID
	public int m_LineID;
	public int LineID
	{
		get { return m_LineID;}
		set { m_LineID = value; }
	}
	//MapID
	public int m_MapID;
	public int MapID
	{
		get { return m_MapID;}
		set { m_MapID = value; }
	}
	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//ping请求封装类
[System.Serializable]
public class SceneRpcPingAskWraper
{

	//构造函数
	public SceneRpcPingAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcPingAsk ToPB()
	{
		SceneRpcPingAsk v = new SceneRpcPingAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcPingAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcPingAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcPingAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcPingAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//ping回应封装类
[System.Serializable]
public class SceneRpcPingReplyWraper
{

	//构造函数
	public SceneRpcPingReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcPingReply ToPB()
	{
		SceneRpcPingReply v = new SceneRpcPingReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcPingReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcPingReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcPingReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcPingReply>(protoMS);
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
//同步场景分线繁忙状态通知封装类
[System.Serializable]
public class SceneRpcSyncSceneLineStatsNotifyWraper
{

	//构造函数
	public SceneRpcSyncSceneLineStatsNotifyWraper()
	{
		 m_Scene_stats = new SceneStatsWraper();
		 m_Player_lineId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Scene_stats = new SceneStatsWraper();
		 m_Player_lineId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSyncSceneLineStatsNotify ToPB()
	{
		SceneRpcSyncSceneLineStatsNotify v = new SceneRpcSyncSceneLineStatsNotify();
		v.Scene_stats = m_Scene_stats.ToPB();
		v.Player_lineId = m_Player_lineId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSyncSceneLineStatsNotify v)
	{
        if (v == null)
            return;
		m_Scene_stats.FromPB(v.Scene_stats);
		m_Player_lineId = v.Player_lineId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSyncSceneLineStatsNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSyncSceneLineStatsNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcSyncSceneLineStatsNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//场景状态
	public SceneStatsWraper m_Scene_stats;
	public SceneStatsWraper Scene_stats
	{
		get { return m_Scene_stats;}
		set { m_Scene_stats = value; }
	}
	//玩家所在线Id
	public int m_Player_lineId;
	public int Player_lineId
	{
		get { return m_Player_lineId;}
		set { m_Player_lineId = value; }
	}


};
//离开GameServer请求封装类
[System.Serializable]
public class SceneRpcLogOutGameAskWraper
{

	//构造函数
	public SceneRpcLogOutGameAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLogOutGameAsk ToPB()
	{
		SceneRpcLogOutGameAsk v = new SceneRpcLogOutGameAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLogOutGameAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcLogOutGameAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcLogOutGameAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcLogOutGameAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//离开GameServer回应封装类
[System.Serializable]
public class SceneRpcLogOutGameReplyWraper
{

	//构造函数
	public SceneRpcLogOutGameReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcLogOutGameReply ToPB()
	{
		SceneRpcLogOutGameReply v = new SceneRpcLogOutGameReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcLogOutGameReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcLogOutGameReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcLogOutGameReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcLogOutGameReply>(protoMS);
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
//被提出场景通知封装类
[System.Serializable]
public class SceneRpcKickOutGameNotifyWraper
{

	//构造函数
	public SceneRpcKickOutGameNotifyWraper()
	{
		 m_Kick_reason = new AppendStringWraper();
		 m_Reason_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Kick_reason = new AppendStringWraper();
		 m_Reason_id = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcKickOutGameNotify ToPB()
	{
		SceneRpcKickOutGameNotify v = new SceneRpcKickOutGameNotify();
		v.Kick_reason = m_Kick_reason.ToPB();
		v.Reason_id = m_Reason_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcKickOutGameNotify v)
	{
        if (v == null)
            return;
		m_Kick_reason.FromPB(v.Kick_reason);
		m_Reason_id = v.Reason_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcKickOutGameNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcKickOutGameNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcKickOutGameNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//原因
	public AppendStringWraper m_Kick_reason;
	public AppendStringWraper Kick_reason
	{
		get { return m_Kick_reason;}
		set { m_Kick_reason = value; }
	}
	//踢人原因id
	public int m_Reason_id;
	public int Reason_id
	{
		get { return m_Reason_id;}
		set { m_Reason_id = value; }
	}


};
//前端通知后端剧情动画播放完毕请求封装类
[System.Serializable]
public class SceneRpcShowFilmFinishAskWraper
{

	//构造函数
	public SceneRpcShowFilmFinishAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcShowFilmFinishAsk ToPB()
	{
		SceneRpcShowFilmFinishAsk v = new SceneRpcShowFilmFinishAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcShowFilmFinishAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcShowFilmFinishAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcShowFilmFinishAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcShowFilmFinishAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//前端通知后端剧情动画播放完毕回应封装类
[System.Serializable]
public class SceneRpcShowFilmFinishReplyWraper
{

	//构造函数
	public SceneRpcShowFilmFinishReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcShowFilmFinishReply ToPB()
	{
		SceneRpcShowFilmFinishReply v = new SceneRpcShowFilmFinishReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcShowFilmFinishReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcShowFilmFinishReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcShowFilmFinishReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcShowFilmFinishReply>(protoMS);
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
//SpecObjPos请求封装类
[System.Serializable]
public class SceneRpcSpecObjPosAskWraper
{

	//构造函数
	public SceneRpcSpecObjPosAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSpecObjPosAsk ToPB()
	{
		SceneRpcSpecObjPosAsk v = new SceneRpcSpecObjPosAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSpecObjPosAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSpecObjPosAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSpecObjPosAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcSpecObjPosAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//SpecObjPos回应封装类
[System.Serializable]
public class SceneRpcSpecObjPosReplyWraper
{

	//构造函数
	public SceneRpcSpecObjPosReplyWraper()
	{
		 m_Result = -1;
		m_PosInfos = new List<ObjPosInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_PosInfos = new List<ObjPosInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SceneRpcSpecObjPosReply ToPB()
	{
		SceneRpcSpecObjPosReply v = new SceneRpcSpecObjPosReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_PosInfos.Count; i++)
			v.PosInfos.Add( m_PosInfos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcSpecObjPosReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_PosInfos.Clear();
		for( int i=0; i<v.PosInfos.Count; i++)
			m_PosInfos.Add( new ObjPosInfoWraper());
		for( int i=0; i<v.PosInfos.Count; i++)
			m_PosInfos[i].FromPB(v.PosInfos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcSpecObjPosReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcSpecObjPosReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcSpecObjPosReply>(protoMS);
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
	//PosInfs
	public List<ObjPosInfoWraper> m_PosInfos;
	public int SizePosInfos()
	{
		return m_PosInfos.Count;
	}
	public List<ObjPosInfoWraper> GetPosInfos()
	{
		return m_PosInfos;
	}
	public ObjPosInfoWraper GetPosInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_PosInfos.Count)
			return new ObjPosInfoWraper();
		return m_PosInfos[Index];
	}
	public void SetPosInfos( List<ObjPosInfoWraper> v )
	{
		m_PosInfos=v;
	}
	public void SetPosInfos( int Index, ObjPosInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_PosInfos.Count)
			return;
		m_PosInfos[Index] = v;
	}
	public void AddPosInfos( ObjPosInfoWraper v )
	{
		m_PosInfos.Add(v);
	}
	public void ClearPosInfos( )
	{
		m_PosInfos.Clear();
	}


};
//昼夜变化通知封装类
[System.Serializable]
public class SceneRpcDayNightChangeNotifyWraper
{

	//构造函数
	public SceneRpcDayNightChangeNotifyWraper()
	{
		 m_DayStage = -1;
		 m_Remaining = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DayStage = -1;
		 m_Remaining = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcDayNightChangeNotify ToPB()
	{
		SceneRpcDayNightChangeNotify v = new SceneRpcDayNightChangeNotify();
		v.DayStage = m_DayStage;
		v.Remaining = m_Remaining;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcDayNightChangeNotify v)
	{
        if (v == null)
            return;
		m_DayStage = v.DayStage;
		m_Remaining = v.Remaining;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcDayNightChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcDayNightChangeNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcDayNightChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//昼夜阶段索引
	public int m_DayStage;
	public int DayStage
	{
		get { return m_DayStage;}
		set { m_DayStage = value; }
	}
	//阶段剩余时间
	public int m_Remaining;
	public int Remaining
	{
		get { return m_Remaining;}
		set { m_Remaining = value; }
	}


};
//天气变化通知封装类
[System.Serializable]
public class SceneRpcWeatherChangeNotifyWraper
{

	//构造函数
	public SceneRpcWeatherChangeNotifyWraper()
	{
		 m_WeatherId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_WeatherId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcWeatherChangeNotify ToPB()
	{
		SceneRpcWeatherChangeNotify v = new SceneRpcWeatherChangeNotify();
		v.WeatherId = m_WeatherId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcWeatherChangeNotify v)
	{
        if (v == null)
            return;
		m_WeatherId = v.WeatherId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcWeatherChangeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcWeatherChangeNotify pb = ProtoBuf.Serializer.Deserialize<SceneRpcWeatherChangeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//天气id
	public int m_WeatherId;
	public int WeatherId
	{
		get { return m_WeatherId;}
		set { m_WeatherId = value; }
	}


};
//ChangeZone请求封装类
[System.Serializable]
public class SceneRpcWantChangeZoneAskWraper
{

	//构造函数
	public SceneRpcWantChangeZoneAskWraper()
	{
		 m_Zoneid = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Zoneid = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcWantChangeZoneAsk ToPB()
	{
		SceneRpcWantChangeZoneAsk v = new SceneRpcWantChangeZoneAsk();
		v.Zoneid = m_Zoneid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcWantChangeZoneAsk v)
	{
        if (v == null)
            return;
		m_Zoneid = v.Zoneid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcWantChangeZoneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcWantChangeZoneAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcWantChangeZoneAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//zoneid
	public int m_Zoneid;
	public int Zoneid
	{
		get { return m_Zoneid;}
		set { m_Zoneid = value; }
	}


};
//ChangeZone回应封装类
[System.Serializable]
public class SceneRpcWantChangeZoneReplyWraper
{

	//构造函数
	public SceneRpcWantChangeZoneReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcWantChangeZoneReply ToPB()
	{
		SceneRpcWantChangeZoneReply v = new SceneRpcWantChangeZoneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcWantChangeZoneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcWantChangeZoneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcWantChangeZoneReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcWantChangeZoneReply>(protoMS);
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
//返回源服请求封装类
[System.Serializable]
public class SceneRpcReturnSrcServerAskWraper
{

	//构造函数
	public SceneRpcReturnSrcServerAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SceneRpcReturnSrcServerAsk ToPB()
	{
		SceneRpcReturnSrcServerAsk v = new SceneRpcReturnSrcServerAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcReturnSrcServerAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcReturnSrcServerAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcReturnSrcServerAsk pb = ProtoBuf.Serializer.Deserialize<SceneRpcReturnSrcServerAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//返回源服回应封装类
[System.Serializable]
public class SceneRpcReturnSrcServerReplyWraper
{

	//构造函数
	public SceneRpcReturnSrcServerReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneRpcReturnSrcServerReply ToPB()
	{
		SceneRpcReturnSrcServerReply v = new SceneRpcReturnSrcServerReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneRpcReturnSrcServerReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneRpcReturnSrcServerReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneRpcReturnSrcServerReply pb = ProtoBuf.Serializer.Deserialize<SceneRpcReturnSrcServerReply>(protoMS);
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
