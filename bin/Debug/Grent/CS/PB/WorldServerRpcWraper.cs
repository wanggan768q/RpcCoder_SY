
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBWorldServer.cs
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


//通知世界服务器切换场景请求封装类
[System.Serializable]
public class WorldServerRpcChangeSceneAskWraper
{

	//构造函数
	public WorldServerRpcChangeSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeSceneAsk ToPB()
	{
		WorldServerRpcChangeSceneAsk v = new WorldServerRpcChangeSceneAsk();
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeSceneAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeSceneAsk>(protoMS);
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
	//玩家的内存id
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//通知世界服务器切换场景回应封装类
[System.Serializable]
public class WorldServerRpcChangeSceneReplyWraper
{

	//构造函数
	public WorldServerRpcChangeSceneReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_CurSceneId = -1;
		 m_TargetSceneId = -1;
		 m_MemId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeSceneReply ToPB()
	{
		WorldServerRpcChangeSceneReply v = new WorldServerRpcChangeSceneReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.CurSceneId = m_CurSceneId;
		v.TargetSceneId = m_TargetSceneId;
		v.MemId = m_MemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_CurSceneId = v.CurSceneId;
		m_TargetSceneId = v.TargetSceneId;
		m_MemId = v.MemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeSceneReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeSceneReply>(protoMS);
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
	//玩家的内存id
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}


};
//进入场景请求封装类
[System.Serializable]
public class WorldServerRpcEnterSceneAskWraper
{

	//构造函数
	public WorldServerRpcEnterSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;
		 m_MemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;
		 m_MemId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcEnterSceneAsk ToPB()
	{
		WorldServerRpcEnterSceneAsk v = new WorldServerRpcEnterSceneAsk();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;
		v.MemId = m_MemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcEnterSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;
		m_MemId = v.MemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcEnterSceneAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcEnterSceneAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcEnterSceneAsk>(protoMS);
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
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}


};
//进入场景回应封装类
[System.Serializable]
public class WorldServerRpcEnterSceneReplyWraper
{

	//构造函数
	public WorldServerRpcEnterSceneReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcEnterSceneReply ToPB()
	{
		WorldServerRpcEnterSceneReply v = new WorldServerRpcEnterSceneReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcEnterSceneReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcEnterSceneReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcEnterSceneReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcEnterSceneReply>(protoMS);
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
//创建副本通知请求封装类
[System.Serializable]
public class WorldServerRpcCreateDungeonAskWraper
{

	//构造函数
	public WorldServerRpcCreateDungeonAskWraper()
	{
		 m_RoleId = 0;
		 m_TargetSceneId = -1;
		 m_MemId = -1;
		 m_DungeonConfigId = -1;
		 m_CurSceneId = -1;
		 m_Result = -9999;
		m_RoleIds = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_TargetSceneId = -1;
		 m_MemId = -1;
		 m_DungeonConfigId = -1;
		 m_CurSceneId = -1;
		 m_Result = -9999;
		m_RoleIds = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateDungeonAsk ToPB()
	{
		WorldServerRpcCreateDungeonAsk v = new WorldServerRpcCreateDungeonAsk();
		v.RoleId = m_RoleId;
		v.TargetSceneId = m_TargetSceneId;
		v.MemId = m_MemId;
		v.DungeonConfigId = m_DungeonConfigId;
		v.CurSceneId = m_CurSceneId;
		v.Result = m_Result;
		for (int i=0; i<(int)m_RoleIds.Count; i++)
			v.RoleIds.Add( m_RoleIds[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateDungeonAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_TargetSceneId = v.TargetSceneId;
		m_MemId = v.MemId;
		m_DungeonConfigId = v.DungeonConfigId;
		m_CurSceneId = v.CurSceneId;
		m_Result = v.Result;
		m_RoleIds.Clear();
		for( int i=0; i<v.RoleIds.Count; i++)
			m_RoleIds.Add(v.RoleIds[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateDungeonAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateDungeonAsk>(protoMS);
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
	//目标场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}
	//玩家的内存id
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//副本配置id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//队员当前场景
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//玩家的唯一id
	public List<UInt64> m_RoleIds;
	public int SizeRoleIds()
	{
		return m_RoleIds.Count;
	}
	public List<UInt64> GetRoleIds()
	{
		return m_RoleIds;
	}
	public UInt64 GetRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return 0;
		return m_RoleIds[Index];
	}
	public void SetRoleIds( List<UInt64> v )
	{
		m_RoleIds=v;
	}
	public void SetRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.Count)
			return;
		m_RoleIds[Index] = v;
	}
	public void AddRoleIds( UInt64 v=0 )
	{
		m_RoleIds.Add(v);
	}
	public void ClearRoleIds( )
	{
		m_RoleIds.Clear();
	}


};
//创建副本通知回应封装类
[System.Serializable]
public class WorldServerRpcCreateDungeonReplyWraper
{

	//构造函数
	public WorldServerRpcCreateDungeonReplyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateDungeonReply ToPB()
	{
		WorldServerRpcCreateDungeonReply v = new WorldServerRpcCreateDungeonReply();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateDungeonReply v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateDungeonReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateDungeonReply>(protoMS);
		FromPB(pb);
		return true;
	}



};
//CreateTeam请求封装类
[System.Serializable]
public class WorldServerRpcCreateTeamAskWraper
{

	//构造函数
	public WorldServerRpcCreateTeamAskWraper()
	{
		 m_TeamType = -1;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Result = -9999;
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamType = -1;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Result = -9999;
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateTeamAsk ToPB()
	{
		WorldServerRpcCreateTeamAsk v = new WorldServerRpcCreateTeamAsk();
		v.TeamType = m_TeamType;
		v.TeamMember = m_TeamMember.ToPB();
		v.Result = m_Result;
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamType = v.TeamType;
		m_TeamMember.FromPB(v.TeamMember);
		m_Result = v.Result;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//TeamMember
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//PbTeam
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//CreateTeam回应封装类
[System.Serializable]
public class WorldServerRpcCreateTeamReplyWraper
{

	//构造函数
	public WorldServerRpcCreateTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateTeamReply ToPB()
	{
		WorldServerRpcCreateTeamReply v = new WorldServerRpcCreateTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateTeamReply>(protoMS);
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
//JoinTeam请求封装类
[System.Serializable]
public class WorldServerRpcJoinTeamAskWraper
{

	//构造函数
	public WorldServerRpcJoinTeamAskWraper()
	{
		 m_TeamId = -1;
		 m_Result = -9999;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();
		 m_TeamType = -1;
		 m_MemId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = -1;
		 m_Result = -9999;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_Team = new TeamInfoWraper();
		 m_TeamType = -1;
		 m_MemId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcJoinTeamAsk ToPB()
	{
		WorldServerRpcJoinTeamAsk v = new WorldServerRpcJoinTeamAsk();
		v.TeamId = m_TeamId;
		v.Result = m_Result;
		v.TeamMember = m_TeamMember.ToPB();
		v.Team = m_Team.ToPB();
		v.TeamType = m_TeamType;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcJoinTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_Result = v.Result;
		m_TeamMember.FromPB(v.TeamMember);
		m_Team.FromPB(v.Team);
		m_TeamType = v.TeamType;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcJoinTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcJoinTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcJoinTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//Member
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}
	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}
	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//JoinTeam回应封装类
[System.Serializable]
public class WorldServerRpcJoinTeamReplyWraper
{

	//构造函数
	public WorldServerRpcJoinTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcJoinTeamReply ToPB()
	{
		WorldServerRpcJoinTeamReply v = new WorldServerRpcJoinTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcJoinTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcJoinTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcJoinTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcJoinTeamReply>(protoMS);
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
//LeaveTeam请求封装类
[System.Serializable]
public class WorldServerRpcLeaveTeamAskWraper
{

	//构造函数
	public WorldServerRpcLeaveTeamAskWraper()
	{
		 m_TeamId = -1;
		 m_RoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_NewLeaderRoleId = 0;
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = -1;
		 m_RoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_NewLeaderRoleId = 0;
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLeaveTeamAsk ToPB()
	{
		WorldServerRpcLeaveTeamAsk v = new WorldServerRpcLeaveTeamAsk();
		v.TeamId = m_TeamId;
		v.RoleId = m_RoleId;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;
		v.NewLeaderRoleId = m_NewLeaderRoleId;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLeaveTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_RoleId = v.RoleId;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;
		m_NewLeaderRoleId = v.NewLeaderRoleId;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLeaveTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLeaveTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLeaveTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//NewLeader
	public UInt64 m_NewLeaderRoleId;
	public UInt64 NewLeaderRoleId
	{
		get { return m_NewLeaderRoleId;}
		set { m_NewLeaderRoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//LeaveTeam回应封装类
[System.Serializable]
public class WorldServerRpcLeaveTeamReplyWraper
{

	//构造函数
	public WorldServerRpcLeaveTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLeaveTeamReply ToPB()
	{
		WorldServerRpcLeaveTeamReply v = new WorldServerRpcLeaveTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLeaveTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLeaveTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLeaveTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLeaveTeamReply>(protoMS);
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
//AppointTeamLeader请求封装类
[System.Serializable]
public class WorldServerRpcAppointTeamLeaderAskWraper
{

	//构造函数
	public WorldServerRpcAppointTeamLeaderAskWraper()
	{
		 m_NewLeaderRoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_CurLeaderRoleId = 0;
		 m_TeamId = -1;
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NewLeaderRoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_CurLeaderRoleId = 0;
		 m_TeamId = -1;
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAppointTeamLeaderAsk ToPB()
	{
		WorldServerRpcAppointTeamLeaderAsk v = new WorldServerRpcAppointTeamLeaderAsk();
		v.NewLeaderRoleId = m_NewLeaderRoleId;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;
		v.CurLeaderRoleId = m_CurLeaderRoleId;
		v.TeamId = m_TeamId;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAppointTeamLeaderAsk v)
	{
        if (v == null)
            return;
		m_NewLeaderRoleId = v.NewLeaderRoleId;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;
		m_CurLeaderRoleId = v.CurLeaderRoleId;
		m_TeamId = v.TeamId;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAppointTeamLeaderAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAppointTeamLeaderAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAppointTeamLeaderAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleId
	public UInt64 m_NewLeaderRoleId;
	public UInt64 NewLeaderRoleId
	{
		get { return m_NewLeaderRoleId;}
		set { m_NewLeaderRoleId = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//CurLeaderRoleId
	public UInt64 m_CurLeaderRoleId;
	public UInt64 CurLeaderRoleId
	{
		get { return m_CurLeaderRoleId;}
		set { m_CurLeaderRoleId = value; }
	}
	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//AppointTeamLeader回应封装类
[System.Serializable]
public class WorldServerRpcAppointTeamLeaderReplyWraper
{

	//构造函数
	public WorldServerRpcAppointTeamLeaderReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAppointTeamLeaderReply ToPB()
	{
		WorldServerRpcAppointTeamLeaderReply v = new WorldServerRpcAppointTeamLeaderReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAppointTeamLeaderReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAppointTeamLeaderReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAppointTeamLeaderReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAppointTeamLeaderReply>(protoMS);
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
//DismissTeam请求封装类
[System.Serializable]
public class WorldServerRpcDismissTeamAskWraper
{

	//构造函数
	public WorldServerRpcDismissTeamAskWraper()
	{
		 m_SceneId = -1;
		 m_MemId = -1;
		 m_RoleId = 0;
		 m_TeamId = -1;
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_MemId = -1;
		 m_RoleId = 0;
		 m_TeamId = -1;
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcDismissTeamAsk ToPB()
	{
		WorldServerRpcDismissTeamAsk v = new WorldServerRpcDismissTeamAsk();
		v.SceneId = m_SceneId;
		v.MemId = m_MemId;
		v.RoleId = m_RoleId;
		v.TeamId = m_TeamId;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcDismissTeamAsk v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_MemId = v.MemId;
		m_RoleId = v.RoleId;
		m_TeamId = v.TeamId;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcDismissTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcDismissTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcDismissTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//DismissTeam回应封装类
[System.Serializable]
public class WorldServerRpcDismissTeamReplyWraper
{

	//构造函数
	public WorldServerRpcDismissTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcDismissTeamReply ToPB()
	{
		WorldServerRpcDismissTeamReply v = new WorldServerRpcDismissTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcDismissTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcDismissTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcDismissTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcDismissTeamReply>(protoMS);
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
//KickMember请求封装类
[System.Serializable]
public class WorldServerRpcKickMemberAskWraper
{

	//构造函数
	public WorldServerRpcKickMemberAskWraper()
	{
		 m_KickMemberRoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_TeamId = -1;
		 m_LeaderRoleId = 0;
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KickMemberRoleId = 0;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_TeamId = -1;
		 m_LeaderRoleId = 0;
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcKickMemberAsk ToPB()
	{
		WorldServerRpcKickMemberAsk v = new WorldServerRpcKickMemberAsk();
		v.KickMemberRoleId = m_KickMemberRoleId;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;
		v.TeamId = m_TeamId;
		v.LeaderRoleId = m_LeaderRoleId;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcKickMemberAsk v)
	{
        if (v == null)
            return;
		m_KickMemberRoleId = v.KickMemberRoleId;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;
		m_TeamId = v.TeamId;
		m_LeaderRoleId = v.LeaderRoleId;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcKickMemberAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcKickMemberAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcKickMemberAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//KickMemberRoleId
	public UInt64 m_KickMemberRoleId;
	public UInt64 KickMemberRoleId
	{
		get { return m_KickMemberRoleId;}
		set { m_KickMemberRoleId = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//RoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//KickMember回应封装类
[System.Serializable]
public class WorldServerRpcKickMemberReplyWraper
{

	//构造函数
	public WorldServerRpcKickMemberReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcKickMemberReply ToPB()
	{
		WorldServerRpcKickMemberReply v = new WorldServerRpcKickMemberReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcKickMemberReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcKickMemberReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcKickMemberReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcKickMemberReply>(protoMS);
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
//ApplyTeam请求封装类
[System.Serializable]
public class WorldServerRpcApplyTeamAskWraper
{

	//构造函数
	public WorldServerRpcApplyTeamAskWraper()
	{
		 m_TeamId = -1;
		 m_Result = -9999;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_MemId = -1;
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = -1;
		 m_Result = -9999;
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_MemId = -1;
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcApplyTeamAsk ToPB()
	{
		WorldServerRpcApplyTeamAsk v = new WorldServerRpcApplyTeamAsk();
		v.TeamId = m_TeamId;
		v.Result = m_Result;
		v.TeamMember = m_TeamMember.ToPB();
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcApplyTeamAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_Result = v.Result;
		m_TeamMember.FromPB(v.TeamMember);
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcApplyTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcApplyTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcApplyTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamId
	public int m_TeamId;
	public int TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//TeamMember
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//ApplyTeam回应封装类
[System.Serializable]
public class WorldServerRpcApplyTeamReplyWraper
{

	//构造函数
	public WorldServerRpcApplyTeamReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcApplyTeamReply ToPB()
	{
		WorldServerRpcApplyTeamReply v = new WorldServerRpcApplyTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcApplyTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcApplyTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcApplyTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcApplyTeamReply>(protoMS);
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
//AgreeTeamApplicant请求封装类
[System.Serializable]
public class WorldServerRpcAgreeTeamApplicantAskWraper
{

	//构造函数
	public WorldServerRpcAgreeTeamApplicantAskWraper()
	{
		 m_RoleId = 0;
		 m_LeaderRoleId = 0;
		 m_Result = -9999;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_Team = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_LeaderRoleId = 0;
		 m_Result = -9999;
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_Team = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAgreeTeamApplicantAsk ToPB()
	{
		WorldServerRpcAgreeTeamApplicantAsk v = new WorldServerRpcAgreeTeamApplicantAsk();
		v.RoleId = m_RoleId;
		v.LeaderRoleId = m_LeaderRoleId;
		v.Result = m_Result;
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;
		v.Team = m_Team.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAgreeTeamApplicantAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_LeaderRoleId = v.LeaderRoleId;
		m_Result = v.Result;
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;
		m_Team.FromPB(v.Team);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAgreeTeamApplicantAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAgreeTeamApplicantAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAgreeTeamApplicantAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//RoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}


};
//AgreeTeamApplicant回应封装类
[System.Serializable]
public class WorldServerRpcAgreeTeamApplicantReplyWraper
{

	//构造函数
	public WorldServerRpcAgreeTeamApplicantReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAgreeTeamApplicantReply ToPB()
	{
		WorldServerRpcAgreeTeamApplicantReply v = new WorldServerRpcAgreeTeamApplicantReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAgreeTeamApplicantReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAgreeTeamApplicantReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAgreeTeamApplicantReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAgreeTeamApplicantReply>(protoMS);
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
//Login请求封装类
[System.Serializable]
public class WorldServerRpcLoginAskWraper
{

	//构造函数
	public WorldServerRpcLoginAskWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_MemId = -1;
		 m_SceneId = -1;
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLoginAsk ToPB()
	{
		WorldServerRpcLoginAsk v = new WorldServerRpcLoginAsk();
		v.Team = m_Team.ToPB();
		v.MemId = m_MemId;
		v.SceneId = m_SceneId;
		v.RoleInfo = m_RoleInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLoginAsk v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);
		m_MemId = v.MemId;
		m_SceneId = v.SceneId;
		m_RoleInfo.FromPB(v.RoleInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLoginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLoginAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLoginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//SceneId
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}


};
//Login回应封装类
[System.Serializable]
public class WorldServerRpcLoginReplyWraper
{

	//构造函数
	public WorldServerRpcLoginReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLoginReply ToPB()
	{
		WorldServerRpcLoginReply v = new WorldServerRpcLoginReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLoginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLoginReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLoginReply>(protoMS);
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
//UpdateRoleInfo请求封装类
[System.Serializable]
public class WorldServerRpcUpdateRoleInfoAskWraper
{

	//构造函数
	public WorldServerRpcUpdateRoleInfoAskWraper()
	{
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcUpdateRoleInfoAsk ToPB()
	{
		WorldServerRpcUpdateRoleInfoAsk v = new WorldServerRpcUpdateRoleInfoAsk();
		v.RoleInfo = m_RoleInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcUpdateRoleInfoAsk v)
	{
        if (v == null)
            return;
		m_RoleInfo.FromPB(v.RoleInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcUpdateRoleInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcUpdateRoleInfoAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcUpdateRoleInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}


};
//UpdateRoleInfo回应封装类
[System.Serializable]
public class WorldServerRpcUpdateRoleInfoReplyWraper
{

	//构造函数
	public WorldServerRpcUpdateRoleInfoReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcUpdateRoleInfoReply ToPB()
	{
		WorldServerRpcUpdateRoleInfoReply v = new WorldServerRpcUpdateRoleInfoReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcUpdateRoleInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcUpdateRoleInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcUpdateRoleInfoReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcUpdateRoleInfoReply>(protoMS);
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
//Logout请求封装类
[System.Serializable]
public class WorldServerRpcLogoutAskWraper
{

	//构造函数
	public WorldServerRpcLogoutAskWraper()
	{
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLogoutAsk ToPB()
	{
		WorldServerRpcLogoutAsk v = new WorldServerRpcLogoutAsk();
		v.RoleInfo = m_RoleInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLogoutAsk v)
	{
        if (v == null)
            return;
		m_RoleInfo.FromPB(v.RoleInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLogoutAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLogoutAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLogoutAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}


};
//Logout回应封装类
[System.Serializable]
public class WorldServerRpcLogoutReplyWraper
{

	//构造函数
	public WorldServerRpcLogoutReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLogoutReply ToPB()
	{
		WorldServerRpcLogoutReply v = new WorldServerRpcLogoutReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLogoutReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLogoutReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLogoutReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLogoutReply>(protoMS);
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
//CreateDungeonNotify请求封装类
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyAskWraper
{

	//构造函数
	public WorldServerRpcCreateDungeonNotifyAskWraper()
	{
		 m_CurSceneId = -1;
		 m_RoleId = 0;
		 m_MemId = -1;
		 m_TargetSceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CurSceneId = -1;
		 m_RoleId = 0;
		 m_MemId = -1;
		 m_TargetSceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateDungeonNotifyAsk ToPB()
	{
		WorldServerRpcCreateDungeonNotifyAsk v = new WorldServerRpcCreateDungeonNotifyAsk();
		v.CurSceneId = m_CurSceneId;
		v.RoleId = m_RoleId;
		v.MemId = m_MemId;
		v.TargetSceneId = m_TargetSceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateDungeonNotifyAsk v)
	{
        if (v == null)
            return;
		m_CurSceneId = v.CurSceneId;
		m_RoleId = v.RoleId;
		m_MemId = v.MemId;
		m_TargetSceneId = v.TargetSceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateDungeonNotifyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateDungeonNotifyAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateDungeonNotifyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//场景id
	public int m_CurSceneId;
	public int CurSceneId
	{
		get { return m_CurSceneId;}
		set { m_CurSceneId = value; }
	}
	//玩家的唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//场景id
	public int m_TargetSceneId;
	public int TargetSceneId
	{
		get { return m_TargetSceneId;}
		set { m_TargetSceneId = value; }
	}


};
//CreateDungeonNotify回应封装类
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyReplyWraper
{

	//构造函数
	public WorldServerRpcCreateDungeonNotifyReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateDungeonNotifyReply ToPB()
	{
		WorldServerRpcCreateDungeonNotifyReply v = new WorldServerRpcCreateDungeonNotifyReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCreateDungeonNotifyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCreateDungeonNotifyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCreateDungeonNotifyReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCreateDungeonNotifyReply>(protoMS);
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
//ExitDungeon请求封装类
[System.Serializable]
public class WorldServerRpcExitDungeonAskWraper
{

	//构造函数
	public WorldServerRpcExitDungeonAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcExitDungeonAsk ToPB()
	{
		WorldServerRpcExitDungeonAsk v = new WorldServerRpcExitDungeonAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcExitDungeonAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcExitDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcExitDungeonAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcExitDungeonAsk>(protoMS);
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


};
//ExitDungeon回应封装类
[System.Serializable]
public class WorldServerRpcExitDungeonReplyWraper
{

	//构造函数
	public WorldServerRpcExitDungeonReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcExitDungeonReply ToPB()
	{
		WorldServerRpcExitDungeonReply v = new WorldServerRpcExitDungeonReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcExitDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcExitDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcExitDungeonReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcExitDungeonReply>(protoMS);
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
//ReleaseDungeon请求封装类
[System.Serializable]
public class WorldServerRpcReleaseDungeonAskWraper
{

	//构造函数
	public WorldServerRpcReleaseDungeonAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcReleaseDungeonAsk ToPB()
	{
		WorldServerRpcReleaseDungeonAsk v = new WorldServerRpcReleaseDungeonAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcReleaseDungeonAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcReleaseDungeonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcReleaseDungeonAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcReleaseDungeonAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//ReleaseDungeon回应封装类
[System.Serializable]
public class WorldServerRpcReleaseDungeonReplyWraper
{

	//构造函数
	public WorldServerRpcReleaseDungeonReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcReleaseDungeonReply ToPB()
	{
		WorldServerRpcReleaseDungeonReply v = new WorldServerRpcReleaseDungeonReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcReleaseDungeonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcReleaseDungeonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcReleaseDungeonReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcReleaseDungeonReply>(protoMS);
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
