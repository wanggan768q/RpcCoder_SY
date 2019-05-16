
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


//进入场景请求封装类
[System.Serializable]
public class WorldServerRpcEnterSceneAskWraper
{

	//构造函数
	public WorldServerRpcEnterSceneAskWraper()
	{
		 m_RoleId = 0;
		 m_Location = new CharacterLocationWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Location = new CharacterLocationWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcEnterSceneAsk ToPB()
	{
		WorldServerRpcEnterSceneAsk v = new WorldServerRpcEnterSceneAsk();
		v.RoleId = m_RoleId;
		v.Location = m_Location.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcEnterSceneAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Location.FromPB(v.Location);

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
	//玩家位置信息
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
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
//Login请求封装类
[System.Serializable]
public class WorldServerRpcLoginGameServerAskWraper
{

	//构造函数
	public WorldServerRpcLoginGameServerAskWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_RoleInfo = new OnlineUserInfoWraper();
		 m_Location = new CharacterLocationWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Team = new TeamInfoWraper();
		 m_RoleInfo = new OnlineUserInfoWraper();
		 m_Location = new CharacterLocationWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLoginGameServerAsk ToPB()
	{
		WorldServerRpcLoginGameServerAsk v = new WorldServerRpcLoginGameServerAsk();
		v.Team = m_Team.ToPB();
		v.RoleInfo = m_RoleInfo.ToPB();
		v.Location = m_Location.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLoginGameServerAsk v)
	{
        if (v == null)
            return;
		m_Team.FromPB(v.Team);
		m_RoleInfo.FromPB(v.RoleInfo);
		m_Location.FromPB(v.Location);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLoginGameServerAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLoginGameServerAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLoginGameServerAsk>(protoMS);
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
	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}
	//玩家位置信息
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
	}


};
//Login回应封装类
[System.Serializable]
public class WorldServerRpcLogoutGameServerAskWraper
{

	//构造函数
	public WorldServerRpcLogoutGameServerAskWraper()
	{
		 m_Result = -9999;
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleInfo = new OnlineUserInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLogoutGameServerAsk ToPB()
	{
		WorldServerRpcLogoutGameServerAsk v = new WorldServerRpcLogoutGameServerAsk();
		v.Result = m_Result;
		v.RoleInfo = m_RoleInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLogoutGameServerAsk v)
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
		ProtoBuf.Serializer.Serialize<WorldServerRpcLogoutGameServerAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLogoutGameServerAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLogoutGameServerAsk>(protoMS);
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
	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
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
//CreateDungeonNotify请求封装类
[System.Serializable]
public class WorldServerRpcCreateDungeonNotifyAskWraper
{

	//构造函数
	public WorldServerRpcCreateDungeonNotifyAskWraper()
	{
		 m_CurSceneId = -1;
		 m_RoleId = 0;
		 m_TargetSceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CurSceneId = -1;
		 m_RoleId = 0;
		 m_TargetSceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCreateDungeonNotifyAsk ToPB()
	{
		WorldServerRpcCreateDungeonNotifyAsk v = new WorldServerRpcCreateDungeonNotifyAsk();
		v.CurSceneId = m_CurSceneId;
		v.RoleId = m_RoleId;
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
//UpdateTeamInfo请求封装类
[System.Serializable]
public class WorldServerRpcUpdateTeamInfoAskWraper
{

	//构造函数
	public WorldServerRpcUpdateTeamInfoAskWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_RoleId = 0;
		 m_Team = new TeamInfoWraper();
		 m_TeamType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamMember = new TeamMemberInfoWraper();
		 m_RoleId = 0;
		 m_Team = new TeamInfoWraper();
		 m_TeamType = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcUpdateTeamInfoAsk ToPB()
	{
		WorldServerRpcUpdateTeamInfoAsk v = new WorldServerRpcUpdateTeamInfoAsk();
		v.TeamMember = m_TeamMember.ToPB();
		v.RoleId = m_RoleId;
		v.Team = m_Team.ToPB();
		v.TeamType = m_TeamType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcUpdateTeamInfoAsk v)
	{
        if (v == null)
            return;
		m_TeamMember.FromPB(v.TeamMember);
		m_RoleId = v.RoleId;
		m_Team.FromPB(v.Team);
		m_TeamType = v.TeamType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcUpdateTeamInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcUpdateTeamInfoAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcUpdateTeamInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//TeamMember
	public TeamMemberInfoWraper m_TeamMember;
	public TeamMemberInfoWraper TeamMember
	{
		get { return m_TeamMember;}
		set { m_TeamMember = value; }
	}
	//MemId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//队伍信息
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}
	//队伍类型
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}


};
//UpdateTeamInfo回应封装类
[System.Serializable]
public class WorldServerRpcUpdateTeamInfoReplyWraper
{

	//构造函数
	public WorldServerRpcUpdateTeamInfoReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcUpdateTeamInfoReply ToPB()
	{
		WorldServerRpcUpdateTeamInfoReply v = new WorldServerRpcUpdateTeamInfoReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcUpdateTeamInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcUpdateTeamInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcUpdateTeamInfoReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcUpdateTeamInfoReply>(protoMS);
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
//播放动画 队伍请求封装类
[System.Serializable]
public class WorldServerRpcPlayCgTeamAskWraper
{

	//构造函数
	public WorldServerRpcPlayCgTeamAskWraper()
	{
		 m_PlayRoleId = 0;
		 m_CgId = -1;
		 m_State = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PlayRoleId = 0;
		 m_CgId = -1;
		 m_State = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcPlayCgTeamAsk ToPB()
	{
		WorldServerRpcPlayCgTeamAsk v = new WorldServerRpcPlayCgTeamAsk();
		v.PlayRoleId = m_PlayRoleId;
		v.CgId = m_CgId;
		v.State = m_State;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcPlayCgTeamAsk v)
	{
        if (v == null)
            return;
		m_PlayRoleId = v.PlayRoleId;
		m_CgId = v.CgId;
		m_State = v.State;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcPlayCgTeamAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcPlayCgTeamAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcPlayCgTeamAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID
	public UInt64 m_PlayRoleId;
	public UInt64 PlayRoleId
	{
		get { return m_PlayRoleId;}
		set { m_PlayRoleId = value; }
	}
	//动画ID
	public int m_CgId;
	public int CgId
	{
		get { return m_CgId;}
		set { m_CgId = value; }
	}
	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//处理消息的roleID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//播放动画 队伍回应封装类
[System.Serializable]
public class WorldServerRpcPlayCgTeamReplyWraper
{

	//构造函数
	public WorldServerRpcPlayCgTeamReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcPlayCgTeamReply ToPB()
	{
		WorldServerRpcPlayCgTeamReply v = new WorldServerRpcPlayCgTeamReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcPlayCgTeamReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcPlayCgTeamReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcPlayCgTeamReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcPlayCgTeamReply>(protoMS);
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
//发送邮件请求封装类
[System.Serializable]
public class WorldServerRpcSendMailAskWraper
{

	//构造函数
	public WorldServerRpcSendMailAskWraper()
	{
		 m_Mail = new MailInfoWraper();
		 m_GlobalMailID = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mail = new MailInfoWraper();
		 m_GlobalMailID = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcSendMailAsk ToPB()
	{
		WorldServerRpcSendMailAsk v = new WorldServerRpcSendMailAsk();
		v.Mail = m_Mail.ToPB();
		v.GlobalMailID = m_GlobalMailID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcSendMailAsk v)
	{
        if (v == null)
            return;
		m_Mail.FromPB(v.Mail);
		m_GlobalMailID = v.GlobalMailID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcSendMailAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcSendMailAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcSendMailAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//邮件列表
	public MailInfoWraper m_Mail;
	public MailInfoWraper Mail
	{
		get { return m_Mail;}
		set { m_Mail = value; }
	}
	//全服邮件ID
	public UInt64 m_GlobalMailID;
	public UInt64 GlobalMailID
	{
		get { return m_GlobalMailID;}
		set { m_GlobalMailID = value; }
	}


};
//发送邮件回应封装类
[System.Serializable]
public class WorldServerRpcSendMailReplyWraper
{

	//构造函数
	public WorldServerRpcSendMailReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcSendMailReply ToPB()
	{
		WorldServerRpcSendMailReply v = new WorldServerRpcSendMailReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcSendMailReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcSendMailReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcSendMailReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcSendMailReply>(protoMS);
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
//改变队伍类型请求封装类
[System.Serializable]
public class WorldServerRpcChangeTeamTypeAskWraper
{

	//构造函数
	public WorldServerRpcChangeTeamTypeAskWraper()
	{
		 m_TeamId = 0;
		 m_RoleId = 0;
		 m_Result = -1;
		 m_TeamType = -1;
		 m_Target = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TeamId = 0;
		 m_RoleId = 0;
		 m_Result = -1;
		 m_TeamType = -1;
		 m_Target = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeTeamTypeAsk ToPB()
	{
		WorldServerRpcChangeTeamTypeAsk v = new WorldServerRpcChangeTeamTypeAsk();
		v.TeamId = m_TeamId;
		v.RoleId = m_RoleId;
		v.Result = m_Result;
		v.TeamType = m_TeamType;
		v.Target = m_Target.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeTeamTypeAsk v)
	{
        if (v == null)
            return;
		m_TeamId = v.TeamId;
		m_RoleId = v.RoleId;
		m_Result = v.Result;
		m_TeamType = v.TeamType;
		m_Target.FromPB(v.Target);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeTeamTypeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeTeamTypeAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeTeamTypeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//队伍id
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//队伍类型
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//目标
	public TeamTargetWraper m_Target;
	public TeamTargetWraper Target
	{
		get { return m_Target;}
		set { m_Target = value; }
	}


};
//改变队伍类型回应封装类
[System.Serializable]
public class WorldServerRpcChangeTeamTypeReplyWraper
{

	//构造函数
	public WorldServerRpcChangeTeamTypeReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcChangeTeamTypeReply ToPB()
	{
		WorldServerRpcChangeTeamTypeReply v = new WorldServerRpcChangeTeamTypeReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcChangeTeamTypeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcChangeTeamTypeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcChangeTeamTypeReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcChangeTeamTypeReply>(protoMS);
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
//自动匹配请求封装类
[System.Serializable]
public class WorldServerRpcAutoMatchAskWraper
{

	//构造函数
	public WorldServerRpcAutoMatchAskWraper()
	{
		 m_MemberInfo = new TeamMemberInfoWraper();
		 m_MatchInfo = new PlayerMatchDataWraper();
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MemberInfo = new TeamMemberInfoWraper();
		 m_MatchInfo = new PlayerMatchDataWraper();
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAutoMatchAsk ToPB()
	{
		WorldServerRpcAutoMatchAsk v = new WorldServerRpcAutoMatchAsk();
		v.MemberInfo = m_MemberInfo.ToPB();
		v.MatchInfo = m_MatchInfo.ToPB();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAutoMatchAsk v)
	{
        if (v == null)
            return;
		m_MemberInfo.FromPB(v.MemberInfo);
		m_MatchInfo.FromPB(v.MatchInfo);
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAutoMatchAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAutoMatchAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAutoMatchAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家队伍信息
	public TeamMemberInfoWraper m_MemberInfo;
	public TeamMemberInfoWraper MemberInfo
	{
		get { return m_MemberInfo;}
		set { m_MemberInfo = value; }
	}
	//匹配信息
	public PlayerMatchDataWraper m_MatchInfo;
	public PlayerMatchDataWraper MatchInfo
	{
		get { return m_MatchInfo;}
		set { m_MatchInfo = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//自动匹配回应封装类
[System.Serializable]
public class WorldServerRpcAutoMatchReplyWraper
{

	//构造函数
	public WorldServerRpcAutoMatchReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcAutoMatchReply ToPB()
	{
		WorldServerRpcAutoMatchReply v = new WorldServerRpcAutoMatchReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcAutoMatchReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcAutoMatchReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcAutoMatchReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcAutoMatchReply>(protoMS);
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
//取消匹配请求封装类
[System.Serializable]
public class WorldServerRpcCancelMatchAskWraper
{

	//构造函数
	public WorldServerRpcCancelMatchAskWraper()
	{
		 m_RoleId = 0;
		 m_Result = -1;
		 m_IsNotify = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Result = -1;
		 m_IsNotify = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCancelMatchAsk ToPB()
	{
		WorldServerRpcCancelMatchAsk v = new WorldServerRpcCancelMatchAsk();
		v.RoleId = m_RoleId;
		v.Result = m_Result;
		v.IsNotify = m_IsNotify;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCancelMatchAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Result = v.Result;
		m_IsNotify = v.IsNotify;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCancelMatchAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCancelMatchAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCancelMatchAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//被拒绝RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//是否是通知
	public int m_IsNotify;
	public int IsNotify
	{
		get { return m_IsNotify;}
		set { m_IsNotify = value; }
	}


};
//取消匹配回应封装类
[System.Serializable]
public class WorldServerRpcCancelMatchReplyWraper
{

	//构造函数
	public WorldServerRpcCancelMatchReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcCancelMatchReply ToPB()
	{
		WorldServerRpcCancelMatchReply v = new WorldServerRpcCancelMatchReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcCancelMatchReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcCancelMatchReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcCancelMatchReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcCancelMatchReply>(protoMS);
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
//登录服务器回应封装类
[System.Serializable]
public class WorldServerRpcLoginGameServerReplyWraper
{

	//构造函数
	public WorldServerRpcLoginGameServerReplyWraper()
	{
		 m_Result = -1;
		 m_Team = new TeamInfoWraper();
		 m_RoleInfo = new OnlineUserInfoWraper();
		 m_Location = new CharacterLocationWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Team = new TeamInfoWraper();
		 m_RoleInfo = new OnlineUserInfoWraper();
		 m_Location = new CharacterLocationWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLoginGameServerReply ToPB()
	{
		WorldServerRpcLoginGameServerReply v = new WorldServerRpcLoginGameServerReply();
		v.Result = m_Result;
		v.Team = m_Team.ToPB();
		v.RoleInfo = m_RoleInfo.ToPB();
		v.Location = m_Location.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLoginGameServerReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Team.FromPB(v.Team);
		m_RoleInfo.FromPB(v.RoleInfo);
		m_Location.FromPB(v.Location);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLoginGameServerReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLoginGameServerReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLoginGameServerReply>(protoMS);
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
	//Team
	public TeamInfoWraper m_Team;
	public TeamInfoWraper Team
	{
		get { return m_Team;}
		set { m_Team = value; }
	}
	//RoleInfo
	public OnlineUserInfoWraper m_RoleInfo;
	public OnlineUserInfoWraper RoleInfo
	{
		get { return m_RoleInfo;}
		set { m_RoleInfo = value; }
	}
	//玩家位置信息
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
	}


};
//LoginGameServer回应封装类
[System.Serializable]
public class WorldServerRpcLogoutGameServerReplyWraper
{

	//构造函数
	public WorldServerRpcLogoutGameServerReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcLogoutGameServerReply ToPB()
	{
		WorldServerRpcLogoutGameServerReply v = new WorldServerRpcLogoutGameServerReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcLogoutGameServerReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcLogoutGameServerReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcLogoutGameServerReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcLogoutGameServerReply>(protoMS);
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
//获取玩家信息请求封装类
[System.Serializable]
public class WorldServerRpcGetPlayerInfoAskWraper
{

	//构造函数
	public WorldServerRpcGetPlayerInfoAskWraper()
	{
		 m_Player_guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Player_guid = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcGetPlayerInfoAsk ToPB()
	{
		WorldServerRpcGetPlayerInfoAsk v = new WorldServerRpcGetPlayerInfoAsk();
		v.Player_guid = m_Player_guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcGetPlayerInfoAsk v)
	{
        if (v == null)
            return;
		m_Player_guid = v.Player_guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcGetPlayerInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcGetPlayerInfoAsk pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcGetPlayerInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家guid
	public UInt64 m_Player_guid;
	public UInt64 Player_guid
	{
		get { return m_Player_guid;}
		set { m_Player_guid = value; }
	}


};
//获取玩家信息回应封装类
[System.Serializable]
public class WorldServerRpcGetPlayerInfoReplyWraper
{

	//构造函数
	public WorldServerRpcGetPlayerInfoReplyWraper()
	{
		 m_Result = -1;
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Guild_id = 0;
		 m_Guild_name = "";
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		m_JewelInfos = new List<JewelInfoWraper>();
		 m_BattleScore = -1;
		 m_Pet_item_data = new ItemDataWraper();
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TeamId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Guild_id = 0;
		 m_Guild_name = "";
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		m_JewelInfos = new List<JewelInfoWraper>();
		 m_BattleScore = -1;
		 m_Pet_item_data = new ItemDataWraper();
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TeamId = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldServerRpcGetPlayerInfoReply ToPB()
	{
		WorldServerRpcGetPlayerInfoReply v = new WorldServerRpcGetPlayerInfoReply();
		v.Result = m_Result;
		v.Player_name = m_Player_name;
		v.Player_guid = m_Player_guid;
		v.Avatar_id = m_Avatar_id;
		v.Player_level = m_Player_level;
		v.Avatar_frame_id = m_Avatar_frame_id;
		v.Config_id = m_Config_id;
		v.Guild_id = m_Guild_id;
		v.Guild_name = m_Guild_name;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());
		for (int i=0; i<(int)m_Suit_infos.Count; i++)
			v.Suit_infos.Add( m_Suit_infos[i].ToPB());
		for (int i=0; i<(int)m_EquipSlotData.Count; i++)
			v.EquipSlotData.Add( m_EquipSlotData[i].ToPB());
		for (int i=0; i<(int)m_EquipSlotStarList.Count; i++)
			v.EquipSlotStarList.Add( m_EquipSlotStarList[i].ToPB());
		for (int i=0; i<(int)m_JewelInfos.Count; i++)
			v.JewelInfos.Add( m_JewelInfos[i].ToPB());
		v.BattleScore = m_BattleScore;
		v.Pet_item_data = m_Pet_item_data.ToPB();
		v.TreasureHair = m_TreasureHair;
		v.TreasureHead = m_TreasureHead;
		v.TreasureBody = m_TreasureBody;
		v.TreasureWeapon = m_TreasureWeapon;
		v.TreasureWing = m_TreasureWing;
		v.TeamId = m_TeamId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldServerRpcGetPlayerInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Player_name = v.Player_name;
		m_Player_guid = v.Player_guid;
		m_Avatar_id = v.Avatar_id;
		m_Player_level = v.Player_level;
		m_Avatar_frame_id = v.Avatar_frame_id;
		m_Config_id = v.Config_id;
		m_Guild_id = v.Guild_id;
		m_Guild_name = v.Guild_name;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);
		m_Suit_infos.Clear();
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos.Add( new SuitInfoWraper());
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos[i].FromPB(v.Suit_infos[i]);
		m_EquipSlotData.Clear();
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData.Add( new EquipSlotInfoWraper());
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData[i].FromPB(v.EquipSlotData[i]);
		m_EquipSlotStarList.Clear();
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList.Add( new EquipSlotStarInfoWraper());
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList[i].FromPB(v.EquipSlotStarList[i]);
		m_JewelInfos.Clear();
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos.Add( new JewelInfoWraper());
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos[i].FromPB(v.JewelInfos[i]);
		m_BattleScore = v.BattleScore;
		m_Pet_item_data.FromPB(v.Pet_item_data);
		m_TreasureHair = v.TreasureHair;
		m_TreasureHead = v.TreasureHead;
		m_TreasureBody = v.TreasureBody;
		m_TreasureWeapon = v.TreasureWeapon;
		m_TreasureWing = v.TreasureWing;
		m_TeamId = v.TeamId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldServerRpcGetPlayerInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldServerRpcGetPlayerInfoReply pb = ProtoBuf.Serializer.Deserialize<WorldServerRpcGetPlayerInfoReply>(protoMS);
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
	//玩家名字
	public string m_Player_name;
	public string Player_name
	{
		get { return m_Player_name;}
		set { m_Player_name = value; }
	}
	//玩家GUID
	public UInt64 m_Player_guid;
	public UInt64 Player_guid
	{
		get { return m_Player_guid;}
		set { m_Player_guid = value; }
	}
	//头像ID
	public int m_Avatar_id;
	public int Avatar_id
	{
		get { return m_Avatar_id;}
		set { m_Avatar_id = value; }
	}
	//等级
	public int m_Player_level;
	public int Player_level
	{
		get { return m_Player_level;}
		set { m_Player_level = value; }
	}
	//头像框ID
	public int m_Avatar_frame_id;
	public int Avatar_frame_id
	{
		get { return m_Avatar_frame_id;}
		set { m_Avatar_frame_id = value; }
	}
	//角色配置ID
	public int m_Config_id;
	public int Config_id
	{
		get { return m_Config_id;}
		set { m_Config_id = value; }
	}
	//公会id
	public UInt64 m_Guild_id;
	public UInt64 Guild_id
	{
		get { return m_Guild_id;}
		set { m_Guild_id = value; }
	}
	//公会名字
	public string m_Guild_name;
	public string Guild_name
	{
		get { return m_Guild_name;}
		set { m_Guild_name = value; }
	}
	//装备信息
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}
	//Suit_infos
	public List<SuitInfoWraper> m_Suit_infos;
	public int SizeSuit_infos()
	{
		return m_Suit_infos.Count;
	}
	public List<SuitInfoWraper> GetSuit_infos()
	{
		return m_Suit_infos;
	}
	public SuitInfoWraper GetSuit_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return new SuitInfoWraper();
		return m_Suit_infos[Index];
	}
	public void SetSuit_infos( List<SuitInfoWraper> v )
	{
		m_Suit_infos=v;
	}
	public void SetSuit_infos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return;
		m_Suit_infos[Index] = v;
	}
	public void AddSuit_infos( SuitInfoWraper v )
	{
		m_Suit_infos.Add(v);
	}
	public void ClearSuit_infos( )
	{
		m_Suit_infos.Clear();
	}
	//装备槽信息
	public List<EquipSlotInfoWraper> m_EquipSlotData;
	public int SizeEquipSlotData()
	{
		return m_EquipSlotData.Count;
	}
	public List<EquipSlotInfoWraper> GetEquipSlotData()
	{
		return m_EquipSlotData;
	}
	public EquipSlotInfoWraper GetEquipSlotData(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return new EquipSlotInfoWraper();
		return m_EquipSlotData[Index];
	}
	public void SetEquipSlotData( List<EquipSlotInfoWraper> v )
	{
		m_EquipSlotData=v;
	}
	public void SetEquipSlotData( int Index, EquipSlotInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return;
		m_EquipSlotData[Index] = v;
	}
	public void AddEquipSlotData( EquipSlotInfoWraper v )
	{
		m_EquipSlotData.Add(v);
	}
	public void ClearEquipSlotData( )
	{
		m_EquipSlotData.Clear();
	}
	//装备槽星级列表
	public List<EquipSlotStarInfoWraper> m_EquipSlotStarList;
	public int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.Count;
	}
	public List<EquipSlotStarInfoWraper> GetEquipSlotStarList()
	{
		return m_EquipSlotStarList;
	}
	public EquipSlotStarInfoWraper GetEquipSlotStarList(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return new EquipSlotStarInfoWraper();
		return m_EquipSlotStarList[Index];
	}
	public void SetEquipSlotStarList( List<EquipSlotStarInfoWraper> v )
	{
		m_EquipSlotStarList=v;
	}
	public void SetEquipSlotStarList( int Index, EquipSlotStarInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return;
		m_EquipSlotStarList[Index] = v;
	}
	public void AddEquipSlotStarList( EquipSlotStarInfoWraper v )
	{
		m_EquipSlotStarList.Add(v);
	}
	public void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.Clear();
	}
	//宝石信息
	public List<JewelInfoWraper> m_JewelInfos;
	public int SizeJewelInfos()
	{
		return m_JewelInfos.Count;
	}
	public List<JewelInfoWraper> GetJewelInfos()
	{
		return m_JewelInfos;
	}
	public JewelInfoWraper GetJewelInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_JewelInfos.Count)
			return new JewelInfoWraper();
		return m_JewelInfos[Index];
	}
	public void SetJewelInfos( List<JewelInfoWraper> v )
	{
		m_JewelInfos=v;
	}
	public void SetJewelInfos( int Index, JewelInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_JewelInfos.Count)
			return;
		m_JewelInfos[Index] = v;
	}
	public void AddJewelInfos( JewelInfoWraper v )
	{
		m_JewelInfos.Add(v);
	}
	public void ClearJewelInfos( )
	{
		m_JewelInfos.Clear();
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//宠物数据
	public ItemDataWraper m_Pet_item_data;
	public ItemDataWraper Pet_item_data
	{
		get { return m_Pet_item_data;}
		set { m_Pet_item_data = value; }
	}
	//头发时装ID
	public int m_TreasureHair;
	public int TreasureHair
	{
		get { return m_TreasureHair;}
		set { m_TreasureHair = value; }
	}
	//头部时装ID
	public int m_TreasureHead;
	public int TreasureHead
	{
		get { return m_TreasureHead;}
		set { m_TreasureHead = value; }
	}
	//身体时装
	public int m_TreasureBody;
	public int TreasureBody
	{
		get { return m_TreasureBody;}
		set { m_TreasureBody = value; }
	}
	//武器时装
	public int m_TreasureWeapon;
	public int TreasureWeapon
	{
		get { return m_TreasureWeapon;}
		set { m_TreasureWeapon = value; }
	}
	//翅膀时装
	public int m_TreasureWing;
	public int TreasureWing
	{
		get { return m_TreasureWing;}
		set { m_TreasureWing = value; }
	}
	//队伍id
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}


};
