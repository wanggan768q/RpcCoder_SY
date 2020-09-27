
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperPubPBCommon.cs
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


//角色信息封装类
[System.Serializable]
public class CharacterInfoWraper
{

	//构造函数
	public CharacterInfoWraper()
	{
		 m_RoleId = 0;
		 m_Nickname = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_HpMax = -1;
		 m_Level = -1;
		 m_TreasureEquiped = new TreasureEquipedIDWraper();
		 m_PinchData = new PinchFaceDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Nickname = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_HpMax = -1;
		 m_Level = -1;
		 m_TreasureEquiped = new TreasureEquipedIDWraper();
		 m_PinchData = new PinchFaceDataWraper();

	}

 	//转化成Protobuffer类型函数
	public CharacterInfo ToPB()
	{
		CharacterInfo v = new CharacterInfo();
		v.RoleId = m_RoleId;
		v.Nickname = m_Nickname;
		v.ConfigId = m_ConfigId;
		v.Hp = m_Hp;
		v.HpMax = m_HpMax;
		v.Level = m_Level;
		v.TreasureEquiped = m_TreasureEquiped.ToPB();
		v.PinchData = m_PinchData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CharacterInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Nickname = v.Nickname;
		m_ConfigId = v.ConfigId;
		m_Hp = v.Hp;
		m_HpMax = v.HpMax;
		m_Level = v.Level;
		m_TreasureEquiped.FromPB(v.TreasureEquiped);
		m_PinchData.FromPB(v.PinchData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CharacterInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CharacterInfo pb = ProtoBuf.Serializer.Deserialize<CharacterInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//roleID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//昵称
	public string m_Nickname;
	public string Nickname
	{
		get { return m_Nickname;}
		set { m_Nickname = value; }
	}
	//配置表id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//血量
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//血量上限
	public int m_HpMax;
	public int HpMax
	{
		get { return m_HpMax;}
		set { m_HpMax = value; }
	}
	//Level
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//穿戴的时装
	public TreasureEquipedIDWraper m_TreasureEquiped;
	public TreasureEquipedIDWraper TreasureEquiped
	{
		get { return m_TreasureEquiped;}
		set { m_TreasureEquiped = value; }
	}
	//捏脸
	public PinchFaceDataWraper m_PinchData;
	public PinchFaceDataWraper PinchData
	{
		get { return m_PinchData;}
		set { m_PinchData = value; }
	}


};
//v3封装类
[System.Serializable]
public class Vector3Wraper
{

	//构造函数
	public Vector3Wraper()
	{
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)-1;
		 m_Y = (float)-1;
		 m_Z = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public Vector3 ToPB()
	{
		Vector3 v = new Vector3();
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(Vector3 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<Vector3>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		Vector3 pb = ProtoBuf.Serializer.Deserialize<Vector3>(protoMS);
		FromPB(pb);
		return true;
	}

	//x
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//TeamMemberInfo封装类
[System.Serializable]
public class TeamMemberInfoWraper
{

	//构造函数
	public TeamMemberInfoWraper()
	{
		 m_RoleId = 0;
		 m_Level = 0;
		 m_Name = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_MaxHp = -1;
		 m_Location = new CharacterLocationWraper();
		 m_ProfessionId = -1;
		 m_OnLine = 1;
		 m_FollowTeam = -1;
		m_BuffIdList = new List<int>();
		 m_Robot = false;
		 m_Camp = -1;
		 m_GuildGuid = 0;
		 m_BattleScore = -1;
		 m_Treasureinfo = new TreasureEquipedIDWraper();
		 m_GhostGuid = 0;
		 m_Occupation = -1;
		 m_PinchData = new PinchFaceDataWraper();
		 m_WillLeaveTime = 0;
		 m_LastLogoutTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Level = 0;
		 m_Name = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_Status = -1;
		 m_MaxHp = -1;
		 m_Location = new CharacterLocationWraper();
		 m_ProfessionId = -1;
		 m_OnLine = 1;
		 m_FollowTeam = -1;
		m_BuffIdList = new List<int>();
		 m_Robot = false;
		 m_Camp = -1;
		 m_GuildGuid = 0;
		 m_BattleScore = -1;
		 m_Treasureinfo = new TreasureEquipedIDWraper();
		 m_GhostGuid = 0;
		 m_Occupation = -1;
		 m_PinchData = new PinchFaceDataWraper();
		 m_WillLeaveTime = 0;
		 m_LastLogoutTime = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamMemberInfo ToPB()
	{
		TeamMemberInfo v = new TeamMemberInfo();
		v.RoleId = m_RoleId;
		v.Level = m_Level;
		v.Name = m_Name;
		v.ConfigId = m_ConfigId;
		v.Hp = m_Hp;
		v.Status = m_Status;
		v.MaxHp = m_MaxHp;
		v.Location = m_Location.ToPB();
		v.ProfessionId = m_ProfessionId;
		v.OnLine = m_OnLine;
		v.FollowTeam = m_FollowTeam;
		for (int i=0; i<(int)m_BuffIdList.Count; i++)
			v.BuffIdList.Add( m_BuffIdList[i]);
		v.Robot = m_Robot;
		v.Camp = m_Camp;
		v.GuildGuid = m_GuildGuid;
		v.BattleScore = m_BattleScore;
		v.Treasureinfo = m_Treasureinfo.ToPB();
		v.GhostGuid = m_GhostGuid;
		v.Occupation = m_Occupation;
		v.PinchData = m_PinchData.ToPB();
		v.WillLeaveTime = m_WillLeaveTime;
		v.LastLogoutTime = m_LastLogoutTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamMemberInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Level = v.Level;
		m_Name = v.Name;
		m_ConfigId = v.ConfigId;
		m_Hp = v.Hp;
		m_Status = v.Status;
		m_MaxHp = v.MaxHp;
		m_Location.FromPB(v.Location);
		m_ProfessionId = v.ProfessionId;
		m_OnLine = v.OnLine;
		m_FollowTeam = v.FollowTeam;
		m_BuffIdList.Clear();
		for( int i=0; i<v.BuffIdList.Count; i++)
			m_BuffIdList.Add(v.BuffIdList[i]);
		m_Robot = v.Robot;
		m_Camp = v.Camp;
		m_GuildGuid = v.GuildGuid;
		m_BattleScore = v.BattleScore;
		m_Treasureinfo.FromPB(v.Treasureinfo);
		m_GhostGuid = v.GhostGuid;
		m_Occupation = v.Occupation;
		m_PinchData.FromPB(v.PinchData);
		m_WillLeaveTime = v.WillLeaveTime;
		m_LastLogoutTime = v.LastLogoutTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamMemberInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamMemberInfo pb = ProtoBuf.Serializer.Deserialize<TeamMemberInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//队员RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//队员等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//name
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//configid
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//生命值
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//Status
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//生命值
	public Int64 m_MaxHp;
	public Int64 MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}
	//Location
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
	}
	//专精ID
	public int m_ProfessionId;
	public int ProfessionId
	{
		get { return m_ProfessionId;}
		set { m_ProfessionId = value; }
	}
	//在线
	public int m_OnLine;
	public int OnLine
	{
		get { return m_OnLine;}
		set { m_OnLine = value; }
	}
	//队员是否跟随队长
	public int m_FollowTeam;
	public int FollowTeam
	{
		get { return m_FollowTeam;}
		set { m_FollowTeam = value; }
	}
	//buff
	public List<int> m_BuffIdList;
	public int SizeBuffIdList()
	{
		return m_BuffIdList.Count;
	}
	public List<int> GetBuffIdList()
	{
		return m_BuffIdList;
	}
	public int GetBuffIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_BuffIdList.Count)
			return -1;
		return m_BuffIdList[Index];
	}
	public void SetBuffIdList( List<int> v )
	{
		m_BuffIdList=v;
	}
	public void SetBuffIdList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_BuffIdList.Count)
			return;
		m_BuffIdList[Index] = v;
	}
	public void AddBuffIdList( int v=-1 )
	{
		m_BuffIdList.Add(v);
	}
	public void ClearBuffIdList( )
	{
		m_BuffIdList.Clear();
	}
	//是否是机器人
	public bool m_Robot;
	public bool Robot
	{
		get { return m_Robot;}
		set { m_Robot = value; }
	}
	//阵营
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//公会GUID
	public UInt64 m_GuildGuid;
	public UInt64 GuildGuid
	{
		get { return m_GuildGuid;}
		set { m_GuildGuid = value; }
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//外显
	public TreasureEquipedIDWraper m_Treasureinfo;
	public TreasureEquipedIDWraper Treasureinfo
	{
		get { return m_Treasureinfo;}
		set { m_Treasureinfo = value; }
	}
	//幽灵ID
	public UInt64 m_GhostGuid;
	public UInt64 GhostGuid
	{
		get { return m_GhostGuid;}
		set { m_GhostGuid = value; }
	}
	//MT TT DPS
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}
	//捏脸数据
	public PinchFaceDataWraper m_PinchData;
	public PinchFaceDataWraper PinchData
	{
		get { return m_PinchData;}
		set { m_PinchData = value; }
	}
	//将要在什么时候离开缔约团
	public Int64 m_WillLeaveTime;
	public Int64 WillLeaveTime
	{
		get { return m_WillLeaveTime;}
		set { m_WillLeaveTime = value; }
	}
	//最后登出时间
	public Int64 m_LastLogoutTime;
	public Int64 LastLogoutTime
	{
		get { return m_LastLogoutTime;}
		set { m_LastLogoutTime = value; }
	}


};
//TeamInfo封装类
[System.Serializable]
public class TeamInfoWraper
{

	//构造函数
	public TeamInfoWraper()
	{
		m_Members = new List<TeamMemberInfoWraper>();
		 m_LeaderRoleId = 0;
		 m_TeamId = 0;
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Members = new List<TeamMemberInfoWraper>();
		 m_LeaderRoleId = 0;
		 m_TeamId = 0;
		 m_TeamType = -1;
		 m_TeamTarget = new TeamTargetWraper();

	}

 	//转化成Protobuffer类型函数
	public TeamInfo ToPB()
	{
		TeamInfo v = new TeamInfo();
		for (int i=0; i<(int)m_Members.Count; i++)
			v.Members.Add( m_Members[i].ToPB());
		v.LeaderRoleId = m_LeaderRoleId;
		v.TeamId = m_TeamId;
		v.TeamType = m_TeamType;
		v.TeamTarget = m_TeamTarget.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamInfo v)
	{
        if (v == null)
            return;
		m_Members.Clear();
		for( int i=0; i<v.Members.Count; i++)
			m_Members.Add( new TeamMemberInfoWraper());
		for( int i=0; i<v.Members.Count; i++)
			m_Members[i].FromPB(v.Members[i]);
		m_LeaderRoleId = v.LeaderRoleId;
		m_TeamId = v.TeamId;
		m_TeamType = v.TeamType;
		m_TeamTarget.FromPB(v.TeamTarget);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamInfo pb = ProtoBuf.Serializer.Deserialize<TeamInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//Members
	public List<TeamMemberInfoWraper> m_Members;
	public int SizeMembers()
	{
		return m_Members.Count;
	}
	public List<TeamMemberInfoWraper> GetMembers()
	{
		return m_Members;
	}
	public TeamMemberInfoWraper GetMembers(int Index)
	{
		if(Index<0 || Index>=(int)m_Members.Count)
			return new TeamMemberInfoWraper();
		return m_Members[Index];
	}
	public void SetMembers( List<TeamMemberInfoWraper> v )
	{
		m_Members=v;
	}
	public void SetMembers( int Index, TeamMemberInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Members.Count)
			return;
		m_Members[Index] = v;
	}
	public void AddMembers( TeamMemberInfoWraper v )
	{
		m_Members.Add(v);
	}
	public void ClearMembers( )
	{
		m_Members.Clear();
	}
	//LeaderRoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}
	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//队伍目标
	public TeamTargetWraper m_TeamTarget;
	public TeamTargetWraper TeamTarget
	{
		get { return m_TeamTarget;}
		set { m_TeamTarget = value; }
	}


};
//OnlineUserInfo封装类
[System.Serializable]
public class OnlineUserInfoWraper
{

	//构造函数
	public OnlineUserInfoWraper()
	{
		 m_RoleId = 0;
		 m_Level = -1;
		 m_Location = new CharacterLocationWraper();
		 m_Guildguid = 0;
		 m_PlayerMatchData = new PlayerMatchDataWraper();
		 m_RoleName = "";
		 m_ConfigID = -1;
		 m_TreasureCount = -1;
		 m_TreasureLevel = -1;
		 m_PetConfigID = -1;
		 m_PetLevel = -1;
		 m_PvP3v3WinCount = -1;
		 m_PvP5v5WinCount = -1;
		 m_Roam_zone = -1;
		 m_Account = "";
		 m_ProfessionId = -1;
		m_PvPBattleInfoList = new List<PvpBattleInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Level = -1;
		 m_Location = new CharacterLocationWraper();
		 m_Guildguid = 0;
		 m_PlayerMatchData = new PlayerMatchDataWraper();
		 m_RoleName = "";
		 m_ConfigID = -1;
		 m_TreasureCount = -1;
		 m_TreasureLevel = -1;
		 m_PetConfigID = -1;
		 m_PetLevel = -1;
		 m_PvP3v3WinCount = -1;
		 m_PvP5v5WinCount = -1;
		 m_Roam_zone = -1;
		 m_Account = "";
		 m_ProfessionId = -1;
		m_PvPBattleInfoList = new List<PvpBattleInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public OnlineUserInfo ToPB()
	{
		OnlineUserInfo v = new OnlineUserInfo();
		v.RoleId = m_RoleId;
		v.Level = m_Level;
		v.Location = m_Location.ToPB();
		v.Guildguid = m_Guildguid;
		v.PlayerMatchData = m_PlayerMatchData.ToPB();
		v.RoleName = m_RoleName;
		v.ConfigID = m_ConfigID;
		v.TreasureCount = m_TreasureCount;
		v.TreasureLevel = m_TreasureLevel;
		v.PetConfigID = m_PetConfigID;
		v.PetLevel = m_PetLevel;
		v.PvP3v3WinCount = m_PvP3v3WinCount;
		v.PvP5v5WinCount = m_PvP5v5WinCount;
		v.Roam_zone = m_Roam_zone;
		v.Account = m_Account;
		v.ProfessionId = m_ProfessionId;
		for (int i=0; i<(int)m_PvPBattleInfoList.Count; i++)
			v.PvPBattleInfoList.Add( m_PvPBattleInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(OnlineUserInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Level = v.Level;
		m_Location.FromPB(v.Location);
		m_Guildguid = v.Guildguid;
		m_PlayerMatchData.FromPB(v.PlayerMatchData);
		m_RoleName = v.RoleName;
		m_ConfigID = v.ConfigID;
		m_TreasureCount = v.TreasureCount;
		m_TreasureLevel = v.TreasureLevel;
		m_PetConfigID = v.PetConfigID;
		m_PetLevel = v.PetLevel;
		m_PvP3v3WinCount = v.PvP3v3WinCount;
		m_PvP5v5WinCount = v.PvP5v5WinCount;
		m_Roam_zone = v.Roam_zone;
		m_Account = v.Account;
		m_ProfessionId = v.ProfessionId;
		m_PvPBattleInfoList.Clear();
		for( int i=0; i<v.PvPBattleInfoList.Count; i++)
			m_PvPBattleInfoList.Add( new PvpBattleInfoWraper());
		for( int i=0; i<v.PvPBattleInfoList.Count; i++)
			m_PvPBattleInfoList[i].FromPB(v.PvPBattleInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<OnlineUserInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		OnlineUserInfo pb = ProtoBuf.Serializer.Deserialize<OnlineUserInfo>(protoMS);
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
	//level
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//Location
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
	}
	//公会ID
	public UInt64 m_Guildguid;
	public UInt64 Guildguid
	{
		get { return m_Guildguid;}
		set { m_Guildguid = value; }
	}
	//玩家匹配信息
	public PlayerMatchDataWraper m_PlayerMatchData;
	public PlayerMatchDataWraper PlayerMatchData
	{
		get { return m_PlayerMatchData;}
		set { m_PlayerMatchData = value; }
	}
	//角色名
	public string m_RoleName;
	public string RoleName
	{
		get { return m_RoleName;}
		set { m_RoleName = value; }
	}
	//角色ID
	public int m_ConfigID;
	public int ConfigID
	{
		get { return m_ConfigID;}
		set { m_ConfigID = value; }
	}
	//珍宝阁
	public int m_TreasureCount;
	public int TreasureCount
	{
		get { return m_TreasureCount;}
		set { m_TreasureCount = value; }
	}
	//珍宝阁等级
	public int m_TreasureLevel;
	public int TreasureLevel
	{
		get { return m_TreasureLevel;}
		set { m_TreasureLevel = value; }
	}
	//宠物id
	public int m_PetConfigID;
	public int PetConfigID
	{
		get { return m_PetConfigID;}
		set { m_PetConfigID = value; }
	}
	//宠物等级
	public int m_PetLevel;
	public int PetLevel
	{
		get { return m_PetLevel;}
		set { m_PetLevel = value; }
	}
	//竞技场胜场数
	public int m_PvP3v3WinCount;
	public int PvP3v3WinCount
	{
		get { return m_PvP3v3WinCount;}
		set { m_PvP3v3WinCount = value; }
	}
	//5V5胜利次数
	public int m_PvP5v5WinCount;
	public int PvP5v5WinCount
	{
		get { return m_PvP5v5WinCount;}
		set { m_PvP5v5WinCount = value; }
	}
	//跨服zoneid
	public int m_Roam_zone;
	public int Roam_zone
	{
		get { return m_Roam_zone;}
		set { m_Roam_zone = value; }
	}
	//账号
	public string m_Account;
	public string Account
	{
		get { return m_Account;}
		set { m_Account = value; }
	}
	//专精ID
	public int m_ProfessionId;
	public int ProfessionId
	{
		get { return m_ProfessionId;}
		set { m_ProfessionId = value; }
	}
	//PVP信息
	public List<PvpBattleInfoWraper> m_PvPBattleInfoList;
	public int SizePvPBattleInfoList()
	{
		return m_PvPBattleInfoList.Count;
	}
	public List<PvpBattleInfoWraper> GetPvPBattleInfoList()
	{
		return m_PvPBattleInfoList;
	}
	public PvpBattleInfoWraper GetPvPBattleInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_PvPBattleInfoList.Count)
			return new PvpBattleInfoWraper();
		return m_PvPBattleInfoList[Index];
	}
	public void SetPvPBattleInfoList( List<PvpBattleInfoWraper> v )
	{
		m_PvPBattleInfoList=v;
	}
	public void SetPvPBattleInfoList( int Index, PvpBattleInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_PvPBattleInfoList.Count)
			return;
		m_PvPBattleInfoList[Index] = v;
	}
	public void AddPvPBattleInfoList( PvpBattleInfoWraper v )
	{
		m_PvPBattleInfoList.Add(v);
	}
	public void ClearPvPBattleInfoList( )
	{
		m_PvPBattleInfoList.Clear();
	}


};
//ItemData封装类
[System.Serializable]
public class ItemDataWraper
{

	//构造函数
	public ItemDataWraper()
	{
		 m_IsLock = false;
		 m_OverlayCount = -1;
		 m_ConfigId = -1;
		 m_EquipAttr = new EquipAttrWraper();
		 m_IsBind = true;
		 m_Guid = 0;
		 m_PetData = new PetDataWraper();
		 m_BindRule = 1;
		 m_SaleCD = 0;
		 m_SoulStone = new SoulStoneDataWraper();
		 m_RefineData = new RefineDataWraper();
		 m_CacheAttr = new EquipAttrWraper();
		 m_WaysOfObtaining = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_IsLock = false;
		 m_OverlayCount = -1;
		 m_ConfigId = -1;
		 m_EquipAttr = new EquipAttrWraper();
		 m_IsBind = true;
		 m_Guid = 0;
		 m_PetData = new PetDataWraper();
		 m_BindRule = 1;
		 m_SaleCD = 0;
		 m_SoulStone = new SoulStoneDataWraper();
		 m_RefineData = new RefineDataWraper();
		 m_CacheAttr = new EquipAttrWraper();
		 m_WaysOfObtaining = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemData ToPB()
	{
		ItemData v = new ItemData();
		v.IsLock = m_IsLock;
		v.OverlayCount = m_OverlayCount;
		v.ConfigId = m_ConfigId;
		v.EquipAttr = m_EquipAttr.ToPB();
		v.IsBind = m_IsBind;
		v.Guid = m_Guid;
		v.PetData = m_PetData.ToPB();
		v.BindRule = m_BindRule;
		v.SaleCD = m_SaleCD;
		v.SoulStone = m_SoulStone.ToPB();
		v.RefineData = m_RefineData.ToPB();
		v.CacheAttr = m_CacheAttr.ToPB();
		v.WaysOfObtaining = m_WaysOfObtaining;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemData v)
	{
        if (v == null)
            return;
		m_IsLock = v.IsLock;
		m_OverlayCount = v.OverlayCount;
		m_ConfigId = v.ConfigId;
		m_EquipAttr.FromPB(v.EquipAttr);
		m_IsBind = v.IsBind;
		m_Guid = v.Guid;
		m_PetData.FromPB(v.PetData);
		m_BindRule = v.BindRule;
		m_SaleCD = v.SaleCD;
		m_SoulStone.FromPB(v.SoulStone);
		m_RefineData.FromPB(v.RefineData);
		m_CacheAttr.FromPB(v.CacheAttr);
		m_WaysOfObtaining = v.WaysOfObtaining;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemData pb = ProtoBuf.Serializer.Deserialize<ItemData>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品锁
	public bool m_IsLock;
	public bool IsLock
	{
		get { return m_IsLock;}
		set { m_IsLock = value; }
	}
	//物品叠加数量
	public int m_OverlayCount;
	public int OverlayCount
	{
		get { return m_OverlayCount;}
		set { m_OverlayCount = value; }
	}
	//物品表的id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//装备属性
	public EquipAttrWraper m_EquipAttr;
	public EquipAttrWraper EquipAttr
	{
		get { return m_EquipAttr;}
		set { m_EquipAttr = value; }
	}
	//是否绑定
	public bool m_IsBind;
	public bool IsBind
	{
		get { return m_IsBind;}
		set { m_IsBind = value; }
	}
	//物品guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//宠物的数据
	public PetDataWraper m_PetData;
	public PetDataWraper PetData
	{
		get { return m_PetData;}
		set { m_PetData = value; }
	}
	//绑定规则
	public int m_BindRule;
	public int BindRule
	{
		get { return m_BindRule;}
		set { m_BindRule = value; }
	}
	//交易cd
	public int m_SaleCD;
	public int SaleCD
	{
		get { return m_SaleCD;}
		set { m_SaleCD = value; }
	}
	//魂石
	public SoulStoneDataWraper m_SoulStone;
	public SoulStoneDataWraper SoulStone
	{
		get { return m_SoulStone;}
		set { m_SoulStone = value; }
	}
	//精炼数据
	public RefineDataWraper m_RefineData;
	public RefineDataWraper RefineData
	{
		get { return m_RefineData;}
		set { m_RefineData = value; }
	}
	//缓存属性
	public EquipAttrWraper m_CacheAttr;
	public EquipAttrWraper CacheAttr
	{
		get { return m_CacheAttr;}
		set { m_CacheAttr = value; }
	}
	//WaysOfObtaining
	public int m_WaysOfObtaining;
	public int WaysOfObtaining
	{
		get { return m_WaysOfObtaining;}
		set { m_WaysOfObtaining = value; }
	}


};
//AttrKeyValue封装类
[System.Serializable]
public class AttrKeyValueWraper
{

	//构造函数
	public AttrKeyValueWraper()
	{
		 m_Key = -1;
		 m_Value = -1;
		 m_Quality = -1;
		 m_Key2 = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = -1;
		 m_Quality = -1;
		 m_Key2 = -1;

	}

 	//转化成Protobuffer类型函数
	public AttrKeyValue ToPB()
	{
		AttrKeyValue v = new AttrKeyValue();
		v.Key = m_Key;
		v.Value = m_Value;
		v.Quality = m_Quality;
		v.Key2 = m_Key2;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AttrKeyValue v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_Value = v.Value;
		m_Quality = v.Quality;
		m_Key2 = v.Key2;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AttrKeyValue>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AttrKeyValue pb = ProtoBuf.Serializer.Deserialize<AttrKeyValue>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性的key
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//Value
	public Int64 m_Value;
	public Int64 Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}
	//quality
	public int m_Quality;
	public int Quality
	{
		get { return m_Quality;}
		set { m_Quality = value; }
	}
	//附加key
	public int m_Key2;
	public int Key2
	{
		get { return m_Key2;}
		set { m_Key2 = value; }
	}


};
//BagData封装类
[System.Serializable]
public class BagDataWraper
{

	//构造函数
	public BagDataWraper()
	{
		m_Items = new List<ItemObjWraper>();
		 m_BagType = -1;
		 m_CurCapacity = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Items = new List<ItemObjWraper>();
		 m_BagType = -1;
		 m_CurCapacity = -1;

	}

 	//转化成Protobuffer类型函数
	public BagData ToPB()
	{
		BagData v = new BagData();
		for (int i=0; i<(int)m_Items.Count; i++)
			v.Items.Add( m_Items[i].ToPB());
		v.BagType = m_BagType;
		v.CurCapacity = m_CurCapacity;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagData v)
	{
        if (v == null)
            return;
		m_Items.Clear();
		for( int i=0; i<v.Items.Count; i++)
			m_Items.Add( new ItemObjWraper());
		for( int i=0; i<v.Items.Count; i++)
			m_Items[i].FromPB(v.Items[i]);
		m_BagType = v.BagType;
		m_CurCapacity = v.CurCapacity;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagData pb = ProtoBuf.Serializer.Deserialize<BagData>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品列表
	public List<ItemObjWraper> m_Items;
	public int SizeItems()
	{
		return m_Items.Count;
	}
	public List<ItemObjWraper> GetItems()
	{
		return m_Items;
	}
	public ItemObjWraper GetItems(int Index)
	{
		if(Index<0 || Index>=(int)m_Items.Count)
			return new ItemObjWraper();
		return m_Items[Index];
	}
	public void SetItems( List<ItemObjWraper> v )
	{
		m_Items=v;
	}
	public void SetItems( int Index, ItemObjWraper v )
	{
		if(Index<0 || Index>=(int)m_Items.Count)
			return;
		m_Items[Index] = v;
	}
	public void AddItems( ItemObjWraper v )
	{
		m_Items.Add(v);
	}
	public void ClearItems( )
	{
		m_Items.Clear();
	}
	//背包类型:0背包,1仓库,2临时背包
	public int m_BagType;
	public int BagType
	{
		get { return m_BagType;}
		set { m_BagType = value; }
	}
	//当前的容量
	public int m_CurCapacity;
	public int CurCapacity
	{
		get { return m_CurCapacity;}
		set { m_CurCapacity = value; }
	}


};
//EquipAttr封装类
[System.Serializable]
public class EquipAttrWraper
{

	//构造函数
	public EquipAttrWraper()
	{
		m_BaseAttr = new List<AttrKeyValueWraper>();
		m_ExtraAttr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_BaseAttr = new List<AttrKeyValueWraper>();
		m_ExtraAttr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipAttr ToPB()
	{
		EquipAttr v = new EquipAttr();
		for (int i=0; i<(int)m_BaseAttr.Count; i++)
			v.BaseAttr.Add( m_BaseAttr[i].ToPB());
		for (int i=0; i<(int)m_ExtraAttr.Count; i++)
			v.ExtraAttr.Add( m_ExtraAttr[i].ToPB());
		v.BattleScore = m_BattleScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipAttr v)
	{
        if (v == null)
            return;
		m_BaseAttr.Clear();
		for( int i=0; i<v.BaseAttr.Count; i++)
			m_BaseAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.BaseAttr.Count; i++)
			m_BaseAttr[i].FromPB(v.BaseAttr[i]);
		m_ExtraAttr.Clear();
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr[i].FromPB(v.ExtraAttr[i]);
		m_BattleScore = v.BattleScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipAttr>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipAttr pb = ProtoBuf.Serializer.Deserialize<EquipAttr>(protoMS);
		FromPB(pb);
		return true;
	}

	//基础属性
	public List<AttrKeyValueWraper> m_BaseAttr;
	public int SizeBaseAttr()
	{
		return m_BaseAttr.Count;
	}
	public List<AttrKeyValueWraper> GetBaseAttr()
	{
		return m_BaseAttr;
	}
	public AttrKeyValueWraper GetBaseAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_BaseAttr.Count)
			return new AttrKeyValueWraper();
		return m_BaseAttr[Index];
	}
	public void SetBaseAttr( List<AttrKeyValueWraper> v )
	{
		m_BaseAttr=v;
	}
	public void SetBaseAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_BaseAttr.Count)
			return;
		m_BaseAttr[Index] = v;
	}
	public void AddBaseAttr( AttrKeyValueWraper v )
	{
		m_BaseAttr.Add(v);
	}
	public void ClearBaseAttr( )
	{
		m_BaseAttr.Clear();
	}
	//高级属性
	public List<AttrKeyValueWraper> m_ExtraAttr;
	public int SizeExtraAttr()
	{
		return m_ExtraAttr.Count;
	}
	public List<AttrKeyValueWraper> GetExtraAttr()
	{
		return m_ExtraAttr;
	}
	public AttrKeyValueWraper GetExtraAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return new AttrKeyValueWraper();
		return m_ExtraAttr[Index];
	}
	public void SetExtraAttr( List<AttrKeyValueWraper> v )
	{
		m_ExtraAttr=v;
	}
	public void SetExtraAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return;
		m_ExtraAttr[Index] = v;
	}
	public void AddExtraAttr( AttrKeyValueWraper v )
	{
		m_ExtraAttr.Add(v);
	}
	public void ClearExtraAttr( )
	{
		m_ExtraAttr.Clear();
	}
	//装备评分
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}


};
//ItemObj封装类
[System.Serializable]
public class ItemObjWraper
{

	//构造函数
	public ItemObjWraper()
	{
		 m_Pos = -1;
		 m_ItemData = new ItemDataWraper();
		 m_RedPoint = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_ItemData = new ItemDataWraper();
		 m_RedPoint = false;

	}

 	//转化成Protobuffer类型函数
	public ItemObj ToPB()
	{
		ItemObj v = new ItemObj();
		v.Pos = m_Pos;
		v.ItemData = m_ItemData.ToPB();
		v.RedPoint = m_RedPoint;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemObj v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_ItemData.FromPB(v.ItemData);
		m_RedPoint = v.RedPoint;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemObj pb = ProtoBuf.Serializer.Deserialize<ItemObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//Pos
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//ItemData
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}
	//是否有红点
	public bool m_RedPoint;
	public bool RedPoint
	{
		get { return m_RedPoint;}
		set { m_RedPoint = value; }
	}


};
//ChatMsg封装类
[System.Serializable]
public class ChatMsgWraper
{

	//构造函数
	public ChatMsgWraper()
	{
		 m_Chat_content = "";
		 m_Chat_voice_url = "";
		 m_Chat_voice_secs = -1;
		m_Items = new List<ItemDataWraper>();
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Chat_content = "";
		 m_Chat_voice_url = "";
		 m_Chat_voice_secs = -1;
		m_Items = new List<ItemDataWraper>();
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public ChatMsg ToPB()
	{
		ChatMsg v = new ChatMsg();
		v.Chat_content = m_Chat_content;
		v.Chat_voice_url = m_Chat_voice_url;
		v.Chat_voice_secs = m_Chat_voice_secs;
		for (int i=0; i<(int)m_Items.Count; i++)
			v.Items.Add( m_Items[i].ToPB());
		v.StringUIConfigId = m_StringUIConfigId;
		for (int i=0; i<(int)m_Params.Count; i++)
			v.Params.Add( m_Params[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatMsg v)
	{
        if (v == null)
            return;
		m_Chat_content = v.Chat_content;
		m_Chat_voice_url = v.Chat_voice_url;
		m_Chat_voice_secs = v.Chat_voice_secs;
		m_Items.Clear();
		for( int i=0; i<v.Items.Count; i++)
			m_Items.Add( new ItemDataWraper());
		for( int i=0; i<v.Items.Count; i++)
			m_Items[i].FromPB(v.Items[i]);
		m_StringUIConfigId = v.StringUIConfigId;
		m_Params.Clear();
		for( int i=0; i<v.Params.Count; i++)
			m_Params.Add(v.Params[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatMsg>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatMsg pb = ProtoBuf.Serializer.Deserialize<ChatMsg>(protoMS);
		FromPB(pb);
		return true;
	}

	//文字内容
	public string m_Chat_content;
	public string Chat_content
	{
		get { return m_Chat_content;}
		set { m_Chat_content = value; }
	}
	//音频URL
	public string m_Chat_voice_url;
	public string Chat_voice_url
	{
		get { return m_Chat_voice_url;}
		set { m_Chat_voice_url = value; }
	}
	//音频秒数
	public int m_Chat_voice_secs;
	public int Chat_voice_secs
	{
		get { return m_Chat_voice_secs;}
		set { m_Chat_voice_secs = value; }
	}
	//items
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
	//StringUIConfigId
	public int m_StringUIConfigId;
	public int StringUIConfigId
	{
		get { return m_StringUIConfigId;}
		set { m_StringUIConfigId = value; }
	}
	//Params
	public List<string> m_Params;
	public int SizeParams()
	{
		return m_Params.Count;
	}
	public List<string> GetParams()
	{
		return m_Params;
	}
	public string GetParams(int Index)
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return "";
		return m_Params[Index];
	}
	public void SetParams( List<string> v )
	{
		m_Params=v;
	}
	public void SetParams( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return;
		m_Params[Index] = v;
	}
	public void AddParams( string v )
	{
		m_Params.Add(v);
	}
	public void ClearParams( )
	{
		m_Params.Clear();
	}


};
//ChatInfo封装类
[System.Serializable]
public class ChatInfoWraper
{

	//构造函数
	public ChatInfoWraper()
	{
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Timestamp = 0;
		 m_Chat_msg = new ChatMsgWraper();
		 m_Team_id = 0;
		 m_Guild_guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Timestamp = 0;
		 m_Chat_msg = new ChatMsgWraper();
		 m_Team_id = 0;
		 m_Guild_guid = 0;

	}

 	//转化成Protobuffer类型函数
	public ChatInfo ToPB()
	{
		ChatInfo v = new ChatInfo();
		v.Player_name = m_Player_name;
		v.Player_guid = m_Player_guid;
		v.Avatar_id = m_Avatar_id;
		v.Player_level = m_Player_level;
		v.Avatar_frame_id = m_Avatar_frame_id;
		v.Config_id = m_Config_id;
		v.Timestamp = m_Timestamp;
		v.Chat_msg = m_Chat_msg.ToPB();
		v.Team_id = m_Team_id;
		v.Guild_guid = m_Guild_guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatInfo v)
	{
        if (v == null)
            return;
		m_Player_name = v.Player_name;
		m_Player_guid = v.Player_guid;
		m_Avatar_id = v.Avatar_id;
		m_Player_level = v.Player_level;
		m_Avatar_frame_id = v.Avatar_frame_id;
		m_Config_id = v.Config_id;
		m_Timestamp = v.Timestamp;
		m_Chat_msg.FromPB(v.Chat_msg);
		m_Team_id = v.Team_id;
		m_Guild_guid = v.Guild_guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatInfo pb = ProtoBuf.Serializer.Deserialize<ChatInfo>(protoMS);
		FromPB(pb);
		return true;
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
	//时间戳
	public UInt64 m_Timestamp;
	public UInt64 Timestamp
	{
		get { return m_Timestamp;}
		set { m_Timestamp = value; }
	}
	//聊天消息
	public ChatMsgWraper m_Chat_msg;
	public ChatMsgWraper Chat_msg
	{
		get { return m_Chat_msg;}
		set { m_Chat_msg = value; }
	}
	//队伍id
	public UInt64 m_Team_id;
	public UInt64 Team_id
	{
		get { return m_Team_id;}
		set { m_Team_id = value; }
	}
	//公会id 0表示无公会
	public UInt64 m_Guild_guid;
	public UInt64 Guild_guid
	{
		get { return m_Guild_guid;}
		set { m_Guild_guid = value; }
	}


};
//ChatChannelData封装类
[System.Serializable]
public class ChatChannelDataWraper
{

	//构造函数
	public ChatChannelDataWraper()
	{
		 m_Chat_channel = -1;
		m_Chat_infos = new List<ChatInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Chat_channel = -1;
		m_Chat_infos = new List<ChatInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public ChatChannelData ToPB()
	{
		ChatChannelData v = new ChatChannelData();
		v.Chat_channel = m_Chat_channel;
		for (int i=0; i<(int)m_Chat_infos.Count; i++)
			v.Chat_infos.Add( m_Chat_infos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatChannelData v)
	{
        if (v == null)
            return;
		m_Chat_channel = v.Chat_channel;
		m_Chat_infos.Clear();
		for( int i=0; i<v.Chat_infos.Count; i++)
			m_Chat_infos.Add( new ChatInfoWraper());
		for( int i=0; i<v.Chat_infos.Count; i++)
			m_Chat_infos[i].FromPB(v.Chat_infos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatChannelData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatChannelData pb = ProtoBuf.Serializer.Deserialize<ChatChannelData>(protoMS);
		FromPB(pb);
		return true;
	}

	//聊天频道
	public int m_Chat_channel;
	public int Chat_channel
	{
		get { return m_Chat_channel;}
		set { m_Chat_channel = value; }
	}
	//聊天消息列表
	public List<ChatInfoWraper> m_Chat_infos;
	public int SizeChat_infos()
	{
		return m_Chat_infos.Count;
	}
	public List<ChatInfoWraper> GetChat_infos()
	{
		return m_Chat_infos;
	}
	public ChatInfoWraper GetChat_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Chat_infos.Count)
			return new ChatInfoWraper();
		return m_Chat_infos[Index];
	}
	public void SetChat_infos( List<ChatInfoWraper> v )
	{
		m_Chat_infos=v;
	}
	public void SetChat_infos( int Index, ChatInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Chat_infos.Count)
			return;
		m_Chat_infos[Index] = v;
	}
	public void AddChat_infos( ChatInfoWraper v )
	{
		m_Chat_infos.Add(v);
	}
	public void ClearChat_infos( )
	{
		m_Chat_infos.Clear();
	}


};
//CharacterLocation封装类
[System.Serializable]
public class CharacterLocationWraper
{

	//构造函数
	public CharacterLocationWraper()
	{
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();
		 m_MapId = -1;
		 m_DungeonConfigId = -1;
		 m_LineId = -1;
		 m_SceneConfigId = -1;
		 m_MirrorId = -1;
		 m_ServerId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SceneId = -1;
		 m_Pos = new Vector3Wraper();
		 m_MapId = -1;
		 m_DungeonConfigId = -1;
		 m_LineId = -1;
		 m_SceneConfigId = -1;
		 m_MirrorId = -1;
		 m_ServerId = -1;

	}

 	//转化成Protobuffer类型函数
	public CharacterLocation ToPB()
	{
		CharacterLocation v = new CharacterLocation();
		v.SceneId = m_SceneId;
		v.Pos = m_Pos.ToPB();
		v.MapId = m_MapId;
		v.DungeonConfigId = m_DungeonConfigId;
		v.LineId = m_LineId;
		v.SceneConfigId = m_SceneConfigId;
		v.MirrorId = m_MirrorId;
		v.ServerId = m_ServerId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CharacterLocation v)
	{
        if (v == null)
            return;
		m_SceneId = v.SceneId;
		m_Pos.FromPB(v.Pos);
		m_MapId = v.MapId;
		m_DungeonConfigId = v.DungeonConfigId;
		m_LineId = v.LineId;
		m_SceneConfigId = v.SceneConfigId;
		m_MirrorId = v.MirrorId;
		m_ServerId = v.ServerId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CharacterLocation>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CharacterLocation pb = ProtoBuf.Serializer.Deserialize<CharacterLocation>(protoMS);
		FromPB(pb);
		return true;
	}

	//队员场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}
	//Pos
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//场景id
	public int m_MapId;
	public int MapId
	{
		get { return m_MapId;}
		set { m_MapId = value; }
	}
	//副本配置表id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//线Id
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
	}
	//场景的配置表id
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
	}
	//场景的配置Id
	public int m_MirrorId;
	public int MirrorId
	{
		get { return m_MirrorId;}
		set { m_MirrorId = value; }
	}
	//服务器Id
	public int m_ServerId;
	public int ServerId
	{
		get { return m_ServerId;}
		set { m_ServerId = value; }
	}


};
//QuestData封装类
[System.Serializable]
public class QuestDataWraper
{

	//构造函数
	public QuestDataWraper()
	{
		 m_ConfigId = -1;
		 m_Status = -1;
		m_QuestSteps = new List<QuestStepDataWraper>();
		 m_QuestIndex = 0;
		 m_QuestMaxIndex = 0;
		 m_QuestBeginTime = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfigId = -1;
		 m_Status = -1;
		m_QuestSteps = new List<QuestStepDataWraper>();
		 m_QuestIndex = 0;
		 m_QuestMaxIndex = 0;
		 m_QuestBeginTime = 0;

	}

 	//转化成Protobuffer类型函数
	public QuestData ToPB()
	{
		QuestData v = new QuestData();
		v.ConfigId = m_ConfigId;
		v.Status = m_Status;
		for (int i=0; i<(int)m_QuestSteps.Count; i++)
			v.QuestSteps.Add( m_QuestSteps[i].ToPB());
		v.QuestIndex = m_QuestIndex;
		v.QuestMaxIndex = m_QuestMaxIndex;
		v.QuestBeginTime = m_QuestBeginTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestData v)
	{
        if (v == null)
            return;
		m_ConfigId = v.ConfigId;
		m_Status = v.Status;
		m_QuestSteps.Clear();
		for( int i=0; i<v.QuestSteps.Count; i++)
			m_QuestSteps.Add( new QuestStepDataWraper());
		for( int i=0; i<v.QuestSteps.Count; i++)
			m_QuestSteps[i].FromPB(v.QuestSteps[i]);
		m_QuestIndex = v.QuestIndex;
		m_QuestMaxIndex = v.QuestMaxIndex;
		m_QuestBeginTime = v.QuestBeginTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestData pb = ProtoBuf.Serializer.Deserialize<QuestData>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品表的id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//Status
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//QuestSteps
	public List<QuestStepDataWraper> m_QuestSteps;
	public int SizeQuestSteps()
	{
		return m_QuestSteps.Count;
	}
	public List<QuestStepDataWraper> GetQuestSteps()
	{
		return m_QuestSteps;
	}
	public QuestStepDataWraper GetQuestSteps(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestSteps.Count)
			return new QuestStepDataWraper();
		return m_QuestSteps[Index];
	}
	public void SetQuestSteps( List<QuestStepDataWraper> v )
	{
		m_QuestSteps=v;
	}
	public void SetQuestSteps( int Index, QuestStepDataWraper v )
	{
		if(Index<0 || Index>=(int)m_QuestSteps.Count)
			return;
		m_QuestSteps[Index] = v;
	}
	public void AddQuestSteps( QuestStepDataWraper v )
	{
		m_QuestSteps.Add(v);
	}
	public void ClearQuestSteps( )
	{
		m_QuestSteps.Clear();
	}
	//第几部任务
	public int m_QuestIndex;
	public int QuestIndex
	{
		get { return m_QuestIndex;}
		set { m_QuestIndex = value; }
	}
	//任务最大值
	public int m_QuestMaxIndex;
	public int QuestMaxIndex
	{
		get { return m_QuestMaxIndex;}
		set { m_QuestMaxIndex = value; }
	}
	//任务开始时间
	public Int64 m_QuestBeginTime;
	public Int64 QuestBeginTime
	{
		get { return m_QuestBeginTime;}
		set { m_QuestBeginTime = value; }
	}


};
//技能自定义数据封装类
[System.Serializable]
public class CustomSkiDataWraper
{

	//构造函数
	public CustomSkiDataWraper()
	{
		 m_Key = "";
		 m_KeyType = -1;
		 m_IntV = 0;
		 m_BoolV = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = "";
		 m_KeyType = -1;
		 m_IntV = 0;
		 m_BoolV = false;

	}

 	//转化成Protobuffer类型函数
	public CustomSkiData ToPB()
	{
		CustomSkiData v = new CustomSkiData();
		v.Key = m_Key;
		v.KeyType = m_KeyType;
		v.IntV = m_IntV;
		v.BoolV = m_BoolV;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CustomSkiData v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_KeyType = v.KeyType;
		m_IntV = v.IntV;
		m_BoolV = v.BoolV;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CustomSkiData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CustomSkiData pb = ProtoBuf.Serializer.Deserialize<CustomSkiData>(protoMS);
		FromPB(pb);
		return true;
	}

	//key
	public string m_Key;
	public string Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//type
	public int m_KeyType;
	public int KeyType
	{
		get { return m_KeyType;}
		set { m_KeyType = value; }
	}
	//int
	public int m_IntV;
	public int IntV
	{
		get { return m_IntV;}
		set { m_IntV = value; }
	}
	//bool
	public bool m_BoolV;
	public bool BoolV
	{
		get { return m_BoolV;}
		set { m_BoolV = value; }
	}


};
//QuestStepData封装类
[System.Serializable]
public class QuestStepDataWraper
{

	//构造函数
	public QuestStepDataWraper()
	{
		 m_Status = 0;
		 m_Progress  = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Status = 0;
		 m_Progress  = 0;

	}

 	//转化成Protobuffer类型函数
	public QuestStepData ToPB()
	{
		QuestStepData v = new QuestStepData();
		v.Status = m_Status;
		v.Progress  = m_Progress ;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestStepData v)
	{
        if (v == null)
            return;
		m_Status = v.Status;
		m_Progress  = v.Progress ;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestStepData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestStepData pb = ProtoBuf.Serializer.Deserialize<QuestStepData>(protoMS);
		FromPB(pb);
		return true;
	}

	//Status
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//进度
	public int m_Progress ;
	public int Progress 
	{
		get { return m_Progress ;}
		set { m_Progress  = value; }
	}


};
//QuestListData封装类
[System.Serializable]
public class QuestListDataWraper
{

	//构造函数
	public QuestListDataWraper()
	{
		m_QuestsList = new List<QuestDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_QuestsList = new List<QuestDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public QuestListData ToPB()
	{
		QuestListData v = new QuestListData();
		for (int i=0; i<(int)m_QuestsList.Count; i++)
			v.QuestsList.Add( m_QuestsList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestListData v)
	{
        if (v == null)
            return;
		m_QuestsList.Clear();
		for( int i=0; i<v.QuestsList.Count; i++)
			m_QuestsList.Add( new QuestDataWraper());
		for( int i=0; i<v.QuestsList.Count; i++)
			m_QuestsList[i].FromPB(v.QuestsList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestListData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestListData pb = ProtoBuf.Serializer.Deserialize<QuestListData>(protoMS);
		FromPB(pb);
		return true;
	}

	//QuestsList
	public List<QuestDataWraper> m_QuestsList;
	public int SizeQuestsList()
	{
		return m_QuestsList.Count;
	}
	public List<QuestDataWraper> GetQuestsList()
	{
		return m_QuestsList;
	}
	public QuestDataWraper GetQuestsList(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestsList.Count)
			return new QuestDataWraper();
		return m_QuestsList[Index];
	}
	public void SetQuestsList( List<QuestDataWraper> v )
	{
		m_QuestsList=v;
	}
	public void SetQuestsList( int Index, QuestDataWraper v )
	{
		if(Index<0 || Index>=(int)m_QuestsList.Count)
			return;
		m_QuestsList[Index] = v;
	}
	public void AddQuestsList( QuestDataWraper v )
	{
		m_QuestsList.Add(v);
	}
	public void ClearQuestsList( )
	{
		m_QuestsList.Clear();
	}


};
//数据库背包封装类
[System.Serializable]
public class DBBagsWraper
{

	//构造函数
	public DBBagsWraper()
	{
		m_Bags = new List<BagDataWraper>();
		m_RedPointGuids = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Bags = new List<BagDataWraper>();
		m_RedPointGuids = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public DBBags ToPB()
	{
		DBBags v = new DBBags();
		for (int i=0; i<(int)m_Bags.Count; i++)
			v.Bags.Add( m_Bags[i].ToPB());
		for (int i=0; i<(int)m_RedPointGuids.Count; i++)
			v.RedPointGuids.Add( m_RedPointGuids[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DBBags v)
	{
        if (v == null)
            return;
		m_Bags.Clear();
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags.Add( new BagDataWraper());
		for( int i=0; i<v.Bags.Count; i++)
			m_Bags[i].FromPB(v.Bags[i]);
		m_RedPointGuids.Clear();
		for( int i=0; i<v.RedPointGuids.Count; i++)
			m_RedPointGuids.Add(v.RedPointGuids[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DBBags>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DBBags pb = ProtoBuf.Serializer.Deserialize<DBBags>(protoMS);
		FromPB(pb);
		return true;
	}

	//背包列表
	public List<BagDataWraper> m_Bags;
	public int SizeBags()
	{
		return m_Bags.Count;
	}
	public List<BagDataWraper> GetBags()
	{
		return m_Bags;
	}
	public BagDataWraper GetBags(int Index)
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return new BagDataWraper();
		return m_Bags[Index];
	}
	public void SetBags( List<BagDataWraper> v )
	{
		m_Bags=v;
	}
	public void SetBags( int Index, BagDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Bags.Count)
			return;
		m_Bags[Index] = v;
	}
	public void AddBags( BagDataWraper v )
	{
		m_Bags.Add(v);
	}
	public void ClearBags( )
	{
		m_Bags.Clear();
	}
	//红点系统
	public List<UInt64> m_RedPointGuids;
	public int SizeRedPointGuids()
	{
		return m_RedPointGuids.Count;
	}
	public List<UInt64> GetRedPointGuids()
	{
		return m_RedPointGuids;
	}
	public UInt64 GetRedPointGuids(int Index)
	{
		if(Index<0 || Index>=(int)m_RedPointGuids.Count)
			return 0;
		return m_RedPointGuids[Index];
	}
	public void SetRedPointGuids( List<UInt64> v )
	{
		m_RedPointGuids=v;
	}
	public void SetRedPointGuids( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_RedPointGuids.Count)
			return;
		m_RedPointGuids[Index] = v;
	}
	public void AddRedPointGuids( UInt64 v=0 )
	{
		m_RedPointGuids.Add(v);
	}
	public void ClearRedPointGuids( )
	{
		m_RedPointGuids.Clear();
	}


};
//道具分解设定数据封装类
[System.Serializable]
public class ItemResolveDataWraper
{

	//构造函数
	public ItemResolveDataWraper()
	{
		 m_Qulity = -1;
		 m_IsResolve = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Qulity = -1;
		 m_IsResolve = 0;

	}

 	//转化成Protobuffer类型函数
	public ItemResolveData ToPB()
	{
		ItemResolveData v = new ItemResolveData();
		v.Qulity = m_Qulity;
		v.IsResolve = m_IsResolve;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemResolveData v)
	{
        if (v == null)
            return;
		m_Qulity = v.Qulity;
		m_IsResolve = v.IsResolve;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemResolveData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemResolveData pb = ProtoBuf.Serializer.Deserialize<ItemResolveData>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具品质
	public int m_Qulity;
	public int Qulity
	{
		get { return m_Qulity;}
		set { m_Qulity = value; }
	}
	//是否设定自动分解
	public int m_IsResolve;
	public int IsResolve
	{
		get { return m_IsResolve;}
		set { m_IsResolve = value; }
	}


};
//道具简易数据封装类
[System.Serializable]
public class ItemSimpleDataWraper
{

	//构造函数
	public ItemSimpleDataWraper()
	{
		 m_ConfID = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfID = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public ItemSimpleData ToPB()
	{
		ItemSimpleData v = new ItemSimpleData();
		v.ConfID = m_ConfID;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemSimpleData v)
	{
        if (v == null)
            return;
		m_ConfID = v.ConfID;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemSimpleData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemSimpleData pb = ProtoBuf.Serializer.Deserialize<ItemSimpleData>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ConfID
	public int m_ConfID;
	public int ConfID
	{
		get { return m_ConfID;}
		set { m_ConfID = value; }
	}
	//数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//物品分解数据封装类
[System.Serializable]
public class ItemAutoOperatorDataWraper
{

	//构造函数
	public ItemAutoOperatorDataWraper()
	{
		m_AutoSaleDisassemble = new List<ItemResolveDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_AutoSaleDisassemble = new List<ItemResolveDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemAutoOperatorData ToPB()
	{
		ItemAutoOperatorData v = new ItemAutoOperatorData();
		for (int i=0; i<(int)m_AutoSaleDisassemble.Count; i++)
			v.AutoSaleDisassemble.Add( m_AutoSaleDisassemble[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemAutoOperatorData v)
	{
        if (v == null)
            return;
		m_AutoSaleDisassemble.Clear();
		for( int i=0; i<v.AutoSaleDisassemble.Count; i++)
			m_AutoSaleDisassemble.Add( new ItemResolveDataWraper());
		for( int i=0; i<v.AutoSaleDisassemble.Count; i++)
			m_AutoSaleDisassemble[i].FromPB(v.AutoSaleDisassemble[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemAutoOperatorData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemAutoOperatorData pb = ProtoBuf.Serializer.Deserialize<ItemAutoOperatorData>(protoMS);
		FromPB(pb);
		return true;
	}

	//是否一键售卖列表
	public List<ItemResolveDataWraper> m_AutoSaleDisassemble;
	public int SizeAutoSaleDisassemble()
	{
		return m_AutoSaleDisassemble.Count;
	}
	public List<ItemResolveDataWraper> GetAutoSaleDisassemble()
	{
		return m_AutoSaleDisassemble;
	}
	public ItemResolveDataWraper GetAutoSaleDisassemble(int Index)
	{
		if(Index<0 || Index>=(int)m_AutoSaleDisassemble.Count)
			return new ItemResolveDataWraper();
		return m_AutoSaleDisassemble[Index];
	}
	public void SetAutoSaleDisassemble( List<ItemResolveDataWraper> v )
	{
		m_AutoSaleDisassemble=v;
	}
	public void SetAutoSaleDisassemble( int Index, ItemResolveDataWraper v )
	{
		if(Index<0 || Index>=(int)m_AutoSaleDisassemble.Count)
			return;
		m_AutoSaleDisassemble[Index] = v;
	}
	public void AddAutoSaleDisassemble( ItemResolveDataWraper v )
	{
		m_AutoSaleDisassemble.Add(v);
	}
	public void ClearAutoSaleDisassemble( )
	{
		m_AutoSaleDisassemble.Clear();
	}


};
//技能集合封装类
[System.Serializable]
public class SkillContainerWraper
{

	//构造函数
	public SkillContainerWraper()
	{
		m_SkillObjList = new List<SkillObjWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SkillObjList = new List<SkillObjWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillContainer ToPB()
	{
		SkillContainer v = new SkillContainer();
		for (int i=0; i<(int)m_SkillObjList.Count; i++)
			v.SkillObjList.Add( m_SkillObjList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillContainer v)
	{
        if (v == null)
            return;
		m_SkillObjList.Clear();
		for( int i=0; i<v.SkillObjList.Count; i++)
			m_SkillObjList.Add( new SkillObjWraper());
		for( int i=0; i<v.SkillObjList.Count; i++)
			m_SkillObjList[i].FromPB(v.SkillObjList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillContainer>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillContainer pb = ProtoBuf.Serializer.Deserialize<SkillContainer>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能集合
	public List<SkillObjWraper> m_SkillObjList;
	public int SizeSkillObjList()
	{
		return m_SkillObjList.Count;
	}
	public List<SkillObjWraper> GetSkillObjList()
	{
		return m_SkillObjList;
	}
	public SkillObjWraper GetSkillObjList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillObjList.Count)
			return new SkillObjWraper();
		return m_SkillObjList[Index];
	}
	public void SetSkillObjList( List<SkillObjWraper> v )
	{
		m_SkillObjList=v;
	}
	public void SetSkillObjList( int Index, SkillObjWraper v )
	{
		if(Index<0 || Index>=(int)m_SkillObjList.Count)
			return;
		m_SkillObjList[Index] = v;
	}
	public void AddSkillObjList( SkillObjWraper v )
	{
		m_SkillObjList.Add(v);
	}
	public void ClearSkillObjList( )
	{
		m_SkillObjList.Clear();
	}


};
//技能数据封装类
[System.Serializable]
public class SkillDataWraper
{

	//构造函数
	public SkillDataWraper()
	{
		m_SkillContainerList = new List<SkillContainerWraper>();
		 m_CurUseContainer = -1;
		m_SkillSlotLevel = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SkillContainerList = new List<SkillContainerWraper>();
		 m_CurUseContainer = -1;
		m_SkillSlotLevel = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public SkillData ToPB()
	{
		SkillData v = new SkillData();
		for (int i=0; i<(int)m_SkillContainerList.Count; i++)
			v.SkillContainerList.Add( m_SkillContainerList[i].ToPB());
		v.CurUseContainer = m_CurUseContainer;
		for (int i=0; i<(int)m_SkillSlotLevel.Count; i++)
			v.SkillSlotLevel.Add( m_SkillSlotLevel[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillData v)
	{
        if (v == null)
            return;
		m_SkillContainerList.Clear();
		for( int i=0; i<v.SkillContainerList.Count; i++)
			m_SkillContainerList.Add( new SkillContainerWraper());
		for( int i=0; i<v.SkillContainerList.Count; i++)
			m_SkillContainerList[i].FromPB(v.SkillContainerList[i]);
		m_CurUseContainer = v.CurUseContainer;
		m_SkillSlotLevel.Clear();
		for( int i=0; i<v.SkillSlotLevel.Count; i++)
			m_SkillSlotLevel.Add(v.SkillSlotLevel[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillData pb = ProtoBuf.Serializer.Deserialize<SkillData>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能分类集合
	public List<SkillContainerWraper> m_SkillContainerList;
	public int SizeSkillContainerList()
	{
		return m_SkillContainerList.Count;
	}
	public List<SkillContainerWraper> GetSkillContainerList()
	{
		return m_SkillContainerList;
	}
	public SkillContainerWraper GetSkillContainerList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillContainerList.Count)
			return new SkillContainerWraper();
		return m_SkillContainerList[Index];
	}
	public void SetSkillContainerList( List<SkillContainerWraper> v )
	{
		m_SkillContainerList=v;
	}
	public void SetSkillContainerList( int Index, SkillContainerWraper v )
	{
		if(Index<0 || Index>=(int)m_SkillContainerList.Count)
			return;
		m_SkillContainerList[Index] = v;
	}
	public void AddSkillContainerList( SkillContainerWraper v )
	{
		m_SkillContainerList.Add(v);
	}
	public void ClearSkillContainerList( )
	{
		m_SkillContainerList.Clear();
	}
	//当前使用的技能专精
	public int m_CurUseContainer;
	public int CurUseContainer
	{
		get { return m_CurUseContainer;}
		set { m_CurUseContainer = value; }
	}
	//技能栏位等级
	public List<int> m_SkillSlotLevel;
	public int SizeSkillSlotLevel()
	{
		return m_SkillSlotLevel.Count;
	}
	public List<int> GetSkillSlotLevel()
	{
		return m_SkillSlotLevel;
	}
	public int GetSkillSlotLevel(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillSlotLevel.Count)
			return 0;
		return m_SkillSlotLevel[Index];
	}
	public void SetSkillSlotLevel( List<int> v )
	{
		m_SkillSlotLevel=v;
	}
	public void SetSkillSlotLevel( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_SkillSlotLevel.Count)
			return;
		m_SkillSlotLevel[Index] = v;
	}
	public void AddSkillSlotLevel( int v=0 )
	{
		m_SkillSlotLevel.Add(v);
	}
	public void ClearSkillSlotLevel( )
	{
		m_SkillSlotLevel.Clear();
	}


};
//技能对象封装类
[System.Serializable]
public class SkillObjWraper
{

	//构造函数
	public SkillObjWraper()
	{
		 m_Pos = -1;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public SkillObj ToPB()
	{
		SkillObj v = new SkillObj();
		v.Pos = m_Pos;
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillObj v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillObj pb = ProtoBuf.Serializer.Deserialize<SkillObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能位置(0-4)
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//技能数据
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//套装信息封装类
[System.Serializable]
public class SuitInfoWraper
{

	//构造函数
	public SuitInfoWraper()
	{
		 m_Suit_id = -1;
		 m_Collect_num = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Suit_id = -1;
		 m_Collect_num = -1;

	}

 	//转化成Protobuffer类型函数
	public SuitInfo ToPB()
	{
		SuitInfo v = new SuitInfo();
		v.Suit_id = m_Suit_id;
		v.Collect_num = m_Collect_num;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SuitInfo v)
	{
        if (v == null)
            return;
		m_Suit_id = v.Suit_id;
		m_Collect_num = v.Collect_num;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SuitInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SuitInfo pb = ProtoBuf.Serializer.Deserialize<SuitInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//套装ID
	public int m_Suit_id;
	public int Suit_id
	{
		get { return m_Suit_id;}
		set { m_Suit_id = value; }
	}
	//套装集齐数
	public int m_Collect_num;
	public int Collect_num
	{
		get { return m_Collect_num;}
		set { m_Collect_num = value; }
	}


};
//排名显示信息封装类
[System.Serializable]
public class WorldBossRankInfoWraper
{

	//构造函数
	public WorldBossRankInfoWraper()
	{
		 m_Rank = -1;
		 m_Name = "";
		 m_Level = -1;
		 m_Score = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Rank = -1;
		 m_Name = "";
		 m_Level = -1;
		 m_Score = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRankInfo ToPB()
	{
		WorldBossRankInfo v = new WorldBossRankInfo();
		v.Rank = m_Rank;
		v.Name = m_Name;
		v.Level = m_Level;
		v.Score = m_Score;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRankInfo v)
	{
        if (v == null)
            return;
		m_Rank = v.Rank;
		m_Name = v.Name;
		m_Level = v.Level;
		m_Score = v.Score;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRankInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRankInfo pb = ProtoBuf.Serializer.Deserialize<WorldBossRankInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//排名
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//玩家名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//积分
	public int m_Score;
	public int Score
	{
		get { return m_Score;}
		set { m_Score = value; }
	}


};
//共鸣数据封装类
[System.Serializable]
public class EquipResonanceInfoWraper
{

	//构造函数
	public EquipResonanceInfoWraper()
	{
		 m_ConfId = -1;
		m_ResonanceAttr = new List<AttrKeyValueWraper>();
		m_NewResonanceAttr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		 m_NewBattleScore = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfId = -1;
		m_ResonanceAttr = new List<AttrKeyValueWraper>();
		m_NewResonanceAttr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		 m_NewBattleScore = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipResonanceInfo ToPB()
	{
		EquipResonanceInfo v = new EquipResonanceInfo();
		v.ConfId = m_ConfId;
		for (int i=0; i<(int)m_ResonanceAttr.Count; i++)
			v.ResonanceAttr.Add( m_ResonanceAttr[i].ToPB());
		for (int i=0; i<(int)m_NewResonanceAttr.Count; i++)
			v.NewResonanceAttr.Add( m_NewResonanceAttr[i].ToPB());
		v.BattleScore = m_BattleScore;
		v.NewBattleScore = m_NewBattleScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipResonanceInfo v)
	{
        if (v == null)
            return;
		m_ConfId = v.ConfId;
		m_ResonanceAttr.Clear();
		for( int i=0; i<v.ResonanceAttr.Count; i++)
			m_ResonanceAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.ResonanceAttr.Count; i++)
			m_ResonanceAttr[i].FromPB(v.ResonanceAttr[i]);
		m_NewResonanceAttr.Clear();
		for( int i=0; i<v.NewResonanceAttr.Count; i++)
			m_NewResonanceAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.NewResonanceAttr.Count; i++)
			m_NewResonanceAttr[i].FromPB(v.NewResonanceAttr[i]);
		m_BattleScore = v.BattleScore;
		m_NewBattleScore = v.NewBattleScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipResonanceInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipResonanceInfo pb = ProtoBuf.Serializer.Deserialize<EquipResonanceInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//表ID
	public int m_ConfId;
	public int ConfId
	{
		get { return m_ConfId;}
		set { m_ConfId = value; }
	}
	//属性列表
	public List<AttrKeyValueWraper> m_ResonanceAttr;
	public int SizeResonanceAttr()
	{
		return m_ResonanceAttr.Count;
	}
	public List<AttrKeyValueWraper> GetResonanceAttr()
	{
		return m_ResonanceAttr;
	}
	public AttrKeyValueWraper GetResonanceAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_ResonanceAttr.Count)
			return new AttrKeyValueWraper();
		return m_ResonanceAttr[Index];
	}
	public void SetResonanceAttr( List<AttrKeyValueWraper> v )
	{
		m_ResonanceAttr=v;
	}
	public void SetResonanceAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_ResonanceAttr.Count)
			return;
		m_ResonanceAttr[Index] = v;
	}
	public void AddResonanceAttr( AttrKeyValueWraper v )
	{
		m_ResonanceAttr.Add(v);
	}
	public void ClearResonanceAttr( )
	{
		m_ResonanceAttr.Clear();
	}
	//增加的属性
	public List<AttrKeyValueWraper> m_NewResonanceAttr;
	public int SizeNewResonanceAttr()
	{
		return m_NewResonanceAttr.Count;
	}
	public List<AttrKeyValueWraper> GetNewResonanceAttr()
	{
		return m_NewResonanceAttr;
	}
	public AttrKeyValueWraper GetNewResonanceAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_NewResonanceAttr.Count)
			return new AttrKeyValueWraper();
		return m_NewResonanceAttr[Index];
	}
	public void SetNewResonanceAttr( List<AttrKeyValueWraper> v )
	{
		m_NewResonanceAttr=v;
	}
	public void SetNewResonanceAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_NewResonanceAttr.Count)
			return;
		m_NewResonanceAttr[Index] = v;
	}
	public void AddNewResonanceAttr( AttrKeyValueWraper v )
	{
		m_NewResonanceAttr.Add(v);
	}
	public void ClearNewResonanceAttr( )
	{
		m_NewResonanceAttr.Clear();
	}
	//战力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//新的战斗力
	public int m_NewBattleScore;
	public int NewBattleScore
	{
		get { return m_NewBattleScore;}
		set { m_NewBattleScore = value; }
	}


};
//装备共鸣数据封装类
[System.Serializable]
public class EquipResonanceDataWraper
{

	//构造函数
	public EquipResonanceDataWraper()
	{
		m_ResonanceList = new List<EquipResonanceInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ResonanceList = new List<EquipResonanceInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipResonanceData ToPB()
	{
		EquipResonanceData v = new EquipResonanceData();
		for (int i=0; i<(int)m_ResonanceList.Count; i++)
			v.ResonanceList.Add( m_ResonanceList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipResonanceData v)
	{
        if (v == null)
            return;
		m_ResonanceList.Clear();
		for( int i=0; i<v.ResonanceList.Count; i++)
			m_ResonanceList.Add( new EquipResonanceInfoWraper());
		for( int i=0; i<v.ResonanceList.Count; i++)
			m_ResonanceList[i].FromPB(v.ResonanceList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipResonanceData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipResonanceData pb = ProtoBuf.Serializer.Deserialize<EquipResonanceData>(protoMS);
		FromPB(pb);
		return true;
	}

	//数据列表
	public List<EquipResonanceInfoWraper> m_ResonanceList;
	public int SizeResonanceList()
	{
		return m_ResonanceList.Count;
	}
	public List<EquipResonanceInfoWraper> GetResonanceList()
	{
		return m_ResonanceList;
	}
	public EquipResonanceInfoWraper GetResonanceList(int Index)
	{
		if(Index<0 || Index>=(int)m_ResonanceList.Count)
			return new EquipResonanceInfoWraper();
		return m_ResonanceList[Index];
	}
	public void SetResonanceList( List<EquipResonanceInfoWraper> v )
	{
		m_ResonanceList=v;
	}
	public void SetResonanceList( int Index, EquipResonanceInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ResonanceList.Count)
			return;
		m_ResonanceList[Index] = v;
	}
	public void AddResonanceList( EquipResonanceInfoWraper v )
	{
		m_ResonanceList.Add(v);
	}
	public void ClearResonanceList( )
	{
		m_ResonanceList.Clear();
	}


};
//装备洗练属性封装类
[System.Serializable]
public class EquipWashInfoWraper
{

	//构造函数
	public EquipWashInfoWraper()
	{
		 m_EquipGuid = 0;
		m_ExtraAttr = new List<AttrKeyValueWraper>();
		m_LockedIndex = new List<int>();
		 m_BattleScore = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipGuid = 0;
		m_ExtraAttr = new List<AttrKeyValueWraper>();
		m_LockedIndex = new List<int>();
		 m_BattleScore = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipWashInfo ToPB()
	{
		EquipWashInfo v = new EquipWashInfo();
		v.EquipGuid = m_EquipGuid;
		for (int i=0; i<(int)m_ExtraAttr.Count; i++)
			v.ExtraAttr.Add( m_ExtraAttr[i].ToPB());
		for (int i=0; i<(int)m_LockedIndex.Count; i++)
			v.LockedIndex.Add( m_LockedIndex[i]);
		v.BattleScore = m_BattleScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipWashInfo v)
	{
        if (v == null)
            return;
		m_EquipGuid = v.EquipGuid;
		m_ExtraAttr.Clear();
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr[i].FromPB(v.ExtraAttr[i]);
		m_LockedIndex.Clear();
		for( int i=0; i<v.LockedIndex.Count; i++)
			m_LockedIndex.Add(v.LockedIndex[i]);
		m_BattleScore = v.BattleScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipWashInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipWashInfo pb = ProtoBuf.Serializer.Deserialize<EquipWashInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//GUID
	public UInt64 m_EquipGuid;
	public UInt64 EquipGuid
	{
		get { return m_EquipGuid;}
		set { m_EquipGuid = value; }
	}
	//新的附加属性
	public List<AttrKeyValueWraper> m_ExtraAttr;
	public int SizeExtraAttr()
	{
		return m_ExtraAttr.Count;
	}
	public List<AttrKeyValueWraper> GetExtraAttr()
	{
		return m_ExtraAttr;
	}
	public AttrKeyValueWraper GetExtraAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return new AttrKeyValueWraper();
		return m_ExtraAttr[Index];
	}
	public void SetExtraAttr( List<AttrKeyValueWraper> v )
	{
		m_ExtraAttr=v;
	}
	public void SetExtraAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return;
		m_ExtraAttr[Index] = v;
	}
	public void AddExtraAttr( AttrKeyValueWraper v )
	{
		m_ExtraAttr.Add(v);
	}
	public void ClearExtraAttr( )
	{
		m_ExtraAttr.Clear();
	}
	//锁的属性
	public List<int> m_LockedIndex;
	public int SizeLockedIndex()
	{
		return m_LockedIndex.Count;
	}
	public List<int> GetLockedIndex()
	{
		return m_LockedIndex;
	}
	public int GetLockedIndex(int Index)
	{
		if(Index<0 || Index>=(int)m_LockedIndex.Count)
			return -1;
		return m_LockedIndex[Index];
	}
	public void SetLockedIndex( List<int> v )
	{
		m_LockedIndex=v;
	}
	public void SetLockedIndex( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_LockedIndex.Count)
			return;
		m_LockedIndex[Index] = v;
	}
	public void AddLockedIndex( int v=-1 )
	{
		m_LockedIndex.Add(v);
	}
	public void ClearLockedIndex( )
	{
		m_LockedIndex.Clear();
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}


};
//装备洗练数据封装类
[System.Serializable]
public class EquipWashDataWraper
{

	//构造函数
	public EquipWashDataWraper()
	{
		m_EquipWashInfoList = new List<EquipWashInfoWraper>();
		 m_LeftTimes = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_EquipWashInfoList = new List<EquipWashInfoWraper>();
		 m_LeftTimes = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipWashData ToPB()
	{
		EquipWashData v = new EquipWashData();
		for (int i=0; i<(int)m_EquipWashInfoList.Count; i++)
			v.EquipWashInfoList.Add( m_EquipWashInfoList[i].ToPB());
		v.LeftTimes = m_LeftTimes;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipWashData v)
	{
        if (v == null)
            return;
		m_EquipWashInfoList.Clear();
		for( int i=0; i<v.EquipWashInfoList.Count; i++)
			m_EquipWashInfoList.Add( new EquipWashInfoWraper());
		for( int i=0; i<v.EquipWashInfoList.Count; i++)
			m_EquipWashInfoList[i].FromPB(v.EquipWashInfoList[i]);
		m_LeftTimes = v.LeftTimes;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipWashData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipWashData pb = ProtoBuf.Serializer.Deserialize<EquipWashData>(protoMS);
		FromPB(pb);
		return true;
	}

	//洗练数据列表
	public List<EquipWashInfoWraper> m_EquipWashInfoList;
	public int SizeEquipWashInfoList()
	{
		return m_EquipWashInfoList.Count;
	}
	public List<EquipWashInfoWraper> GetEquipWashInfoList()
	{
		return m_EquipWashInfoList;
	}
	public EquipWashInfoWraper GetEquipWashInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipWashInfoList.Count)
			return new EquipWashInfoWraper();
		return m_EquipWashInfoList[Index];
	}
	public void SetEquipWashInfoList( List<EquipWashInfoWraper> v )
	{
		m_EquipWashInfoList=v;
	}
	public void SetEquipWashInfoList( int Index, EquipWashInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipWashInfoList.Count)
			return;
		m_EquipWashInfoList[Index] = v;
	}
	public void AddEquipWashInfoList( EquipWashInfoWraper v )
	{
		m_EquipWashInfoList.Add(v);
	}
	public void ClearEquipWashInfoList( )
	{
		m_EquipWashInfoList.Clear();
	}
	//当日洗炼剩余次数
	public int m_LeftTimes;
	public int LeftTimes
	{
		get { return m_LeftTimes;}
		set { m_LeftTimes = value; }
	}


};
//Resource封装类
[System.Serializable]
public class ResourceWraper
{

	//构造函数
	public ResourceWraper()
	{
		 m_Type = 0;
		 m_Value = 0;
		 m_TodayValue = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = 0;
		 m_Value = 0;
		 m_TodayValue = -1;

	}

 	//转化成Protobuffer类型函数
	public Resource ToPB()
	{
		Resource v = new Resource();
		v.Type = m_Type;
		v.Value = m_Value;
		v.TodayValue = m_TodayValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(Resource v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_Value = v.Value;
		m_TodayValue = v.TodayValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<Resource>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		Resource pb = ProtoBuf.Serializer.Deserialize<Resource>(protoMS);
		FromPB(pb);
		return true;
	}

	//资源类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//Value
	public Int64 m_Value;
	public Int64 Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}
	//当日获得的
	public Int64 m_TodayValue;
	public Int64 TodayValue
	{
		get { return m_TodayValue;}
		set { m_TodayValue = value; }
	}


};
//生活技能封装类
[System.Serializable]
public class BuinessSkillDataWraper
{

	//构造函数
	public BuinessSkillDataWraper()
	{
		 m_SkillID = -1;
		 m_SkillLv = -1;
		 m_Locked = -1;
		 m_SkillExp = -1;
		 m_UseCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillID = -1;
		 m_SkillLv = -1;
		 m_Locked = -1;
		 m_SkillExp = -1;
		 m_UseCount = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessSkillData ToPB()
	{
		BuinessSkillData v = new BuinessSkillData();
		v.SkillID = m_SkillID;
		v.SkillLv = m_SkillLv;
		v.Locked = m_Locked;
		v.SkillExp = m_SkillExp;
		v.UseCount = m_UseCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessSkillData v)
	{
        if (v == null)
            return;
		m_SkillID = v.SkillID;
		m_SkillLv = v.SkillLv;
		m_Locked = v.Locked;
		m_SkillExp = v.SkillExp;
		m_UseCount = v.UseCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessSkillData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessSkillData pb = ProtoBuf.Serializer.Deserialize<BuinessSkillData>(protoMS);
		FromPB(pb);
		return true;
	}

	//生活技能ID
	public int m_SkillID;
	public int SkillID
	{
		get { return m_SkillID;}
		set { m_SkillID = value; }
	}
	//等级
	public int m_SkillLv;
	public int SkillLv
	{
		get { return m_SkillLv;}
		set { m_SkillLv = value; }
	}
	//是否锁
	public int m_Locked;
	public int Locked
	{
		get { return m_Locked;}
		set { m_Locked = value; }
	}
	//当前经验
	public int m_SkillExp;
	public int SkillExp
	{
		get { return m_SkillExp;}
		set { m_SkillExp = value; }
	}
	//使用技能书的次数
	public int m_UseCount;
	public int UseCount
	{
		get { return m_UseCount;}
		set { m_UseCount = value; }
	}


};
//生活技能解锁封装类
[System.Serializable]
public class BuinessUnlockInfoWraper
{

	//构造函数
	public BuinessUnlockInfoWraper()
	{
		 m_Mutual = -1;
		 m_EndTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mutual = -1;
		 m_EndTime = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessUnlockInfo ToPB()
	{
		BuinessUnlockInfo v = new BuinessUnlockInfo();
		v.Mutual = m_Mutual;
		v.EndTime = m_EndTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessUnlockInfo v)
	{
        if (v == null)
            return;
		m_Mutual = v.Mutual;
		m_EndTime = v.EndTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessUnlockInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessUnlockInfo pb = ProtoBuf.Serializer.Deserialize<BuinessUnlockInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//互斥类型
	public int m_Mutual;
	public int Mutual
	{
		get { return m_Mutual;}
		set { m_Mutual = value; }
	}
	//解锁的结束时间
	public Int64 m_EndTime;
	public Int64 EndTime
	{
		get { return m_EndTime;}
		set { m_EndTime = value; }
	}


};
//CompletedQuestList封装类
[System.Serializable]
public class CompletedQuestListWraper
{

	//构造函数
	public CompletedQuestListWraper()
	{
		m_IdList = new List<int>();
		m_MaxCompleteIdList = new List<MaxQuestCompleteIdWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_IdList = new List<int>();
		m_MaxCompleteIdList = new List<MaxQuestCompleteIdWraper>();

	}

 	//转化成Protobuffer类型函数
	public CompletedQuestList ToPB()
	{
		CompletedQuestList v = new CompletedQuestList();
		for (int i=0; i<(int)m_IdList.Count; i++)
			v.IdList.Add( m_IdList[i]);
		for (int i=0; i<(int)m_MaxCompleteIdList.Count; i++)
			v.MaxCompleteIdList.Add( m_MaxCompleteIdList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CompletedQuestList v)
	{
        if (v == null)
            return;
		m_IdList.Clear();
		for( int i=0; i<v.IdList.Count; i++)
			m_IdList.Add(v.IdList[i]);
		m_MaxCompleteIdList.Clear();
		for( int i=0; i<v.MaxCompleteIdList.Count; i++)
			m_MaxCompleteIdList.Add( new MaxQuestCompleteIdWraper());
		for( int i=0; i<v.MaxCompleteIdList.Count; i++)
			m_MaxCompleteIdList[i].FromPB(v.MaxCompleteIdList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CompletedQuestList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CompletedQuestList pb = ProtoBuf.Serializer.Deserialize<CompletedQuestList>(protoMS);
		FromPB(pb);
		return true;
	}

	//IdList
	public List<int> m_IdList;
	public int SizeIdList()
	{
		return m_IdList.Count;
	}
	public List<int> GetIdList()
	{
		return m_IdList;
	}
	public int GetIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_IdList.Count)
			return -1;
		return m_IdList[Index];
	}
	public void SetIdList( List<int> v )
	{
		m_IdList=v;
	}
	public void SetIdList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_IdList.Count)
			return;
		m_IdList[Index] = v;
	}
	public void AddIdList( int v=-1 )
	{
		m_IdList.Add(v);
	}
	public void ClearIdList( )
	{
		m_IdList.Clear();
	}
	//完成任务最大类型
	public List<MaxQuestCompleteIdWraper> m_MaxCompleteIdList;
	public int SizeMaxCompleteIdList()
	{
		return m_MaxCompleteIdList.Count;
	}
	public List<MaxQuestCompleteIdWraper> GetMaxCompleteIdList()
	{
		return m_MaxCompleteIdList;
	}
	public MaxQuestCompleteIdWraper GetMaxCompleteIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_MaxCompleteIdList.Count)
			return new MaxQuestCompleteIdWraper();
		return m_MaxCompleteIdList[Index];
	}
	public void SetMaxCompleteIdList( List<MaxQuestCompleteIdWraper> v )
	{
		m_MaxCompleteIdList=v;
	}
	public void SetMaxCompleteIdList( int Index, MaxQuestCompleteIdWraper v )
	{
		if(Index<0 || Index>=(int)m_MaxCompleteIdList.Count)
			return;
		m_MaxCompleteIdList[Index] = v;
	}
	public void AddMaxCompleteIdList( MaxQuestCompleteIdWraper v )
	{
		m_MaxCompleteIdList.Add(v);
	}
	public void ClearMaxCompleteIdList( )
	{
		m_MaxCompleteIdList.Clear();
	}


};
//精英怪信息封装类
[System.Serializable]
public class EliteMonsterInfoWraper
{

	//构造函数
	public EliteMonsterInfoWraper()
	{
		 m_FinishTime = -1;
		 m_CommonId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FinishTime = -1;
		 m_CommonId = -1;

	}

 	//转化成Protobuffer类型函数
	public EliteMonsterInfo ToPB()
	{
		EliteMonsterInfo v = new EliteMonsterInfo();
		v.FinishTime = m_FinishTime;
		v.CommonId = m_CommonId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EliteMonsterInfo v)
	{
        if (v == null)
            return;
		m_FinishTime = v.FinishTime;
		m_CommonId = v.CommonId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EliteMonsterInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EliteMonsterInfo pb = ProtoBuf.Serializer.Deserialize<EliteMonsterInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//完成次数
	public int m_FinishTime;
	public int FinishTime
	{
		get { return m_FinishTime;}
		set { m_FinishTime = value; }
	}
	//当前精英怪任务id
	public int m_CommonId;
	public int CommonId
	{
		get { return m_CommonId;}
		set { m_CommonId = value; }
	}


};
//宝石槽位信息封装类
[System.Serializable]
public class JewelSlotWraper
{

	//构造函数
	public JewelSlotWraper()
	{
		 m_ItemId = -1;
		 m_Unlocked = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;
		 m_Unlocked = false;

	}

 	//转化成Protobuffer类型函数
	public JewelSlot ToPB()
	{
		JewelSlot v = new JewelSlot();
		v.ItemId = m_ItemId;
		v.Unlocked = m_Unlocked;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelSlot v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_Unlocked = v.Unlocked;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelSlot>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelSlot pb = ProtoBuf.Serializer.Deserialize<JewelSlot>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ID
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//是否解锁
	public bool m_Unlocked;
	public bool Unlocked
	{
		get { return m_Unlocked;}
		set { m_Unlocked = value; }
	}


};
//宝石信息封装类
[System.Serializable]
public class JewelInfoWraper
{

	//构造函数
	public JewelInfoWraper()
	{
		 m_EquipSlot = -1;
		m_JewelSlots = new List<JewelSlotWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipSlot = -1;
		m_JewelSlots = new List<JewelSlotWraper>();

	}

 	//转化成Protobuffer类型函数
	public JewelInfo ToPB()
	{
		JewelInfo v = new JewelInfo();
		v.EquipSlot = m_EquipSlot;
		for (int i=0; i<(int)m_JewelSlots.Count; i++)
			v.JewelSlots.Add( m_JewelSlots[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelInfo v)
	{
        if (v == null)
            return;
		m_EquipSlot = v.EquipSlot;
		m_JewelSlots.Clear();
		for( int i=0; i<v.JewelSlots.Count; i++)
			m_JewelSlots.Add( new JewelSlotWraper());
		for( int i=0; i<v.JewelSlots.Count; i++)
			m_JewelSlots[i].FromPB(v.JewelSlots[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelInfo pb = ProtoBuf.Serializer.Deserialize<JewelInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备位
	public int m_EquipSlot;
	public int EquipSlot
	{
		get { return m_EquipSlot;}
		set { m_EquipSlot = value; }
	}
	//该位置宝石信息
	public List<JewelSlotWraper> m_JewelSlots;
	public int SizeJewelSlots()
	{
		return m_JewelSlots.Count;
	}
	public List<JewelSlotWraper> GetJewelSlots()
	{
		return m_JewelSlots;
	}
	public JewelSlotWraper GetJewelSlots(int Index)
	{
		if(Index<0 || Index>=(int)m_JewelSlots.Count)
			return new JewelSlotWraper();
		return m_JewelSlots[Index];
	}
	public void SetJewelSlots( List<JewelSlotWraper> v )
	{
		m_JewelSlots=v;
	}
	public void SetJewelSlots( int Index, JewelSlotWraper v )
	{
		if(Index<0 || Index>=(int)m_JewelSlots.Count)
			return;
		m_JewelSlots[Index] = v;
	}
	public void AddJewelSlots( JewelSlotWraper v )
	{
		m_JewelSlots.Add(v);
	}
	public void ClearJewelSlots( )
	{
		m_JewelSlots.Clear();
	}


};
//装备槽封装类
[System.Serializable]
public class EquipSlotInfoWraper
{

	//构造函数
	public EquipSlotInfoWraper()
	{
		 m_Enhance_Level = -1;
		 m_Enhance_Exp = -1;
		m_Enhance_Attr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		 m_Slot_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Enhance_Level = -1;
		 m_Enhance_Exp = -1;
		m_Enhance_Attr = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		 m_Slot_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipSlotInfo ToPB()
	{
		EquipSlotInfo v = new EquipSlotInfo();
		v.Enhance_Level = m_Enhance_Level;
		v.Enhance_Exp = m_Enhance_Exp;
		for (int i=0; i<(int)m_Enhance_Attr.Count; i++)
			v.Enhance_Attr.Add( m_Enhance_Attr[i].ToPB());
		v.BattleScore = m_BattleScore;
		v.Slot_Type = m_Slot_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotInfo v)
	{
        if (v == null)
            return;
		m_Enhance_Level = v.Enhance_Level;
		m_Enhance_Exp = v.Enhance_Exp;
		m_Enhance_Attr.Clear();
		for( int i=0; i<v.Enhance_Attr.Count; i++)
			m_Enhance_Attr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.Enhance_Attr.Count; i++)
			m_Enhance_Attr[i].FromPB(v.Enhance_Attr[i]);
		m_BattleScore = v.BattleScore;
		m_Slot_Type = v.Slot_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotInfo pb = ProtoBuf.Serializer.Deserialize<EquipSlotInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//强化等级
	public int m_Enhance_Level;
	public int Enhance_Level
	{
		get { return m_Enhance_Level;}
		set { m_Enhance_Level = value; }
	}
	//当前段位强化经验
	public int m_Enhance_Exp;
	public int Enhance_Exp
	{
		get { return m_Enhance_Exp;}
		set { m_Enhance_Exp = value; }
	}
	//强化属性
	public List<AttrKeyValueWraper> m_Enhance_Attr;
	public int SizeEnhance_Attr()
	{
		return m_Enhance_Attr.Count;
	}
	public List<AttrKeyValueWraper> GetEnhance_Attr()
	{
		return m_Enhance_Attr;
	}
	public AttrKeyValueWraper GetEnhance_Attr(int Index)
	{
		if(Index<0 || Index>=(int)m_Enhance_Attr.Count)
			return new AttrKeyValueWraper();
		return m_Enhance_Attr[Index];
	}
	public void SetEnhance_Attr( List<AttrKeyValueWraper> v )
	{
		m_Enhance_Attr=v;
	}
	public void SetEnhance_Attr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_Enhance_Attr.Count)
			return;
		m_Enhance_Attr[Index] = v;
	}
	public void AddEnhance_Attr( AttrKeyValueWraper v )
	{
		m_Enhance_Attr.Add(v);
	}
	public void ClearEnhance_Attr( )
	{
		m_Enhance_Attr.Clear();
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//装备槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}


};
//军衔排行信息封装类
[System.Serializable]
public class WorshipPlayerDataWraper
{

	//构造函数
	public WorshipPlayerDataWraper()
	{
		 m_Role_id = -1;
		 m_Role_name = "";
		 m_Rank_level = -1;
		 m_Worship_cout = -1;
		 m_Rank = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Role_id = -1;
		 m_Role_name = "";
		 m_Rank_level = -1;
		 m_Worship_cout = -1;
		 m_Rank = -1;

	}

 	//转化成Protobuffer类型函数
	public WorshipPlayerData ToPB()
	{
		WorshipPlayerData v = new WorshipPlayerData();
		v.Role_id = m_Role_id;
		v.Role_name = m_Role_name;
		v.Rank_level = m_Rank_level;
		v.Worship_cout = m_Worship_cout;
		v.Rank = m_Rank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorshipPlayerData v)
	{
        if (v == null)
            return;
		m_Role_id = v.Role_id;
		m_Role_name = v.Role_name;
		m_Rank_level = v.Rank_level;
		m_Worship_cout = v.Worship_cout;
		m_Rank = v.Rank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorshipPlayerData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorshipPlayerData pb = ProtoBuf.Serializer.Deserialize<WorshipPlayerData>(protoMS);
		FromPB(pb);
		return true;
	}

	//role_id
	public int m_Role_id;
	public int Role_id
	{
		get { return m_Role_id;}
		set { m_Role_id = value; }
	}
	//Role_name
	public string m_Role_name;
	public string Role_name
	{
		get { return m_Role_name;}
		set { m_Role_name = value; }
	}
	//Rank_level
	public int m_Rank_level;
	public int Rank_level
	{
		get { return m_Rank_level;}
		set { m_Rank_level = value; }
	}
	//Worship_cout
	public int m_Worship_cout;
	public int Worship_cout
	{
		get { return m_Worship_cout;}
		set { m_Worship_cout = value; }
	}
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}


};
//药剂封装类
[System.Serializable]
public class RecoverMedicamentWraper
{

	//构造函数
	public RecoverMedicamentWraper()
	{
		m_HpMedicamentList = new List<int>();
		 m_AutoHpMedicament = -1;
		 m_HpPercentage = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_HpMedicamentList = new List<int>();
		 m_AutoHpMedicament = -1;
		 m_HpPercentage = -1;

	}

 	//转化成Protobuffer类型函数
	public RecoverMedicament ToPB()
	{
		RecoverMedicament v = new RecoverMedicament();
		for (int i=0; i<(int)m_HpMedicamentList.Count; i++)
			v.HpMedicamentList.Add( m_HpMedicamentList[i]);
		v.AutoHpMedicament = m_AutoHpMedicament;
		v.HpPercentage = m_HpPercentage;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RecoverMedicament v)
	{
        if (v == null)
            return;
		m_HpMedicamentList.Clear();
		for( int i=0; i<v.HpMedicamentList.Count; i++)
			m_HpMedicamentList.Add(v.HpMedicamentList[i]);
		m_AutoHpMedicament = v.AutoHpMedicament;
		m_HpPercentage = v.HpPercentage;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RecoverMedicament>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RecoverMedicament pb = ProtoBuf.Serializer.Deserialize<RecoverMedicament>(protoMS);
		FromPB(pb);
		return true;
	}

	//HpMedicamentList
	public List<int> m_HpMedicamentList;
	public int SizeHpMedicamentList()
	{
		return m_HpMedicamentList.Count;
	}
	public List<int> GetHpMedicamentList()
	{
		return m_HpMedicamentList;
	}
	public int GetHpMedicamentList(int Index)
	{
		if(Index<0 || Index>=(int)m_HpMedicamentList.Count)
			return -1;
		return m_HpMedicamentList[Index];
	}
	public void SetHpMedicamentList( List<int> v )
	{
		m_HpMedicamentList=v;
	}
	public void SetHpMedicamentList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_HpMedicamentList.Count)
			return;
		m_HpMedicamentList[Index] = v;
	}
	public void AddHpMedicamentList( int v=-1 )
	{
		m_HpMedicamentList.Add(v);
	}
	public void ClearHpMedicamentList( )
	{
		m_HpMedicamentList.Clear();
	}
	//自动使用
	public int m_AutoHpMedicament;
	public int AutoHpMedicament
	{
		get { return m_AutoHpMedicament;}
		set { m_AutoHpMedicament = value; }
	}
	//血量低于百分之几
	public int m_HpPercentage;
	public int HpPercentage
	{
		get { return m_HpPercentage;}
		set { m_HpPercentage = value; }
	}


};
//邮件信息封装类
[System.Serializable]
public class MailInfoWraper
{

	//构造函数
	public MailInfoWraper()
	{
		 m_Mail_type = 0;
		 m_Mail_id = 0;
		 m_IsRead = false;
		 m_IsGet = false;
		 m_Title = new AppendStringWraper();
		 m_Salutation = new AppendStringWraper();
		 m_Content = new AppendStringWraper();
		 m_Sender_name = new AppendStringWraper();
		m_ItemList = new List<MailItemWraper>();
		 m_Sender_id = 0;
		 m_Start_time = -1;
		 m_Expire_time = -1;
		 m_Receiver_id = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mail_type = 0;
		 m_Mail_id = 0;
		 m_IsRead = false;
		 m_IsGet = false;
		 m_Title = new AppendStringWraper();
		 m_Salutation = new AppendStringWraper();
		 m_Content = new AppendStringWraper();
		 m_Sender_name = new AppendStringWraper();
		m_ItemList = new List<MailItemWraper>();
		 m_Sender_id = 0;
		 m_Start_time = -1;
		 m_Expire_time = -1;
		 m_Receiver_id = 0;

	}

 	//转化成Protobuffer类型函数
	public MailInfo ToPB()
	{
		MailInfo v = new MailInfo();
		v.Mail_type = m_Mail_type;
		v.Mail_id = m_Mail_id;
		v.IsRead = m_IsRead;
		v.IsGet = m_IsGet;
		v.Title = m_Title.ToPB();
		v.Salutation = m_Salutation.ToPB();
		v.Content = m_Content.ToPB();
		v.Sender_name = m_Sender_name.ToPB();
		for (int i=0; i<(int)m_ItemList.Count; i++)
			v.ItemList.Add( m_ItemList[i].ToPB());
		v.Sender_id = m_Sender_id;
		v.Start_time = m_Start_time;
		v.Expire_time = m_Expire_time;
		v.Receiver_id = m_Receiver_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailInfo v)
	{
        if (v == null)
            return;
		m_Mail_type = v.Mail_type;
		m_Mail_id = v.Mail_id;
		m_IsRead = v.IsRead;
		m_IsGet = v.IsGet;
		m_Title.FromPB(v.Title);
		m_Salutation.FromPB(v.Salutation);
		m_Content.FromPB(v.Content);
		m_Sender_name.FromPB(v.Sender_name);
		m_ItemList.Clear();
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList.Add( new MailItemWraper());
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList[i].FromPB(v.ItemList[i]);
		m_Sender_id = v.Sender_id;
		m_Start_time = v.Start_time;
		m_Expire_time = v.Expire_time;
		m_Receiver_id = v.Receiver_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailInfo pb = ProtoBuf.Serializer.Deserialize<MailInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//邮件类型
	public int m_Mail_type;
	public int Mail_type
	{
		get { return m_Mail_type;}
		set { m_Mail_type = value; }
	}
	//邮件id
	public int m_Mail_id;
	public int Mail_id
	{
		get { return m_Mail_id;}
		set { m_Mail_id = value; }
	}
	//已读
	public bool m_IsRead;
	public bool IsRead
	{
		get { return m_IsRead;}
		set { m_IsRead = value; }
	}
	//已领
	public bool m_IsGet;
	public bool IsGet
	{
		get { return m_IsGet;}
		set { m_IsGet = value; }
	}
	//标题
	public AppendStringWraper m_Title;
	public AppendStringWraper Title
	{
		get { return m_Title;}
		set { m_Title = value; }
	}
	//称呼
	public AppendStringWraper m_Salutation;
	public AppendStringWraper Salutation
	{
		get { return m_Salutation;}
		set { m_Salutation = value; }
	}
	//内容
	public AppendStringWraper m_Content;
	public AppendStringWraper Content
	{
		get { return m_Content;}
		set { m_Content = value; }
	}
	//发送人
	public AppendStringWraper m_Sender_name;
	public AppendStringWraper Sender_name
	{
		get { return m_Sender_name;}
		set { m_Sender_name = value; }
	}
	//物品id列表
	public List<MailItemWraper> m_ItemList;
	public int SizeItemList()
	{
		return m_ItemList.Count;
	}
	public List<MailItemWraper> GetItemList()
	{
		return m_ItemList;
	}
	public MailItemWraper GetItemList(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return new MailItemWraper();
		return m_ItemList[Index];
	}
	public void SetItemList( List<MailItemWraper> v )
	{
		m_ItemList=v;
	}
	public void SetItemList( int Index, MailItemWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return;
		m_ItemList[Index] = v;
	}
	public void AddItemList( MailItemWraper v )
	{
		m_ItemList.Add(v);
	}
	public void ClearItemList( )
	{
		m_ItemList.Clear();
	}
	//发送角色id
	public UInt64 m_Sender_id;
	public UInt64 Sender_id
	{
		get { return m_Sender_id;}
		set { m_Sender_id = value; }
	}
	//开始时间戳
	public int m_Start_time;
	public int Start_time
	{
		get { return m_Start_time;}
		set { m_Start_time = value; }
	}
	//失效时间戳
	public int m_Expire_time;
	public int Expire_time
	{
		get { return m_Expire_time;}
		set { m_Expire_time = value; }
	}
	//接收角色id
	public UInt64 m_Receiver_id;
	public UInt64 Receiver_id
	{
		get { return m_Receiver_id;}
		set { m_Receiver_id = value; }
	}


};
//装备槽星封装类
[System.Serializable]
public class EquipSlotStarInfoWraper
{

	//构造函数
	public EquipSlotStarInfoWraper()
	{
		 m_RankUp_Level = -1;
		 m_Slot_Type = -1;
		 m_BattleScore = -1;
		 m_NextBattleScore = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RankUp_Level = -1;
		 m_Slot_Type = -1;
		 m_BattleScore = -1;
		 m_NextBattleScore = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipSlotStarInfo ToPB()
	{
		EquipSlotStarInfo v = new EquipSlotStarInfo();
		v.RankUp_Level = m_RankUp_Level;
		v.Slot_Type = m_Slot_Type;
		v.BattleScore = m_BattleScore;
		v.NextBattleScore = m_NextBattleScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipSlotStarInfo v)
	{
        if (v == null)
            return;
		m_RankUp_Level = v.RankUp_Level;
		m_Slot_Type = v.Slot_Type;
		m_BattleScore = v.BattleScore;
		m_NextBattleScore = v.NextBattleScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipSlotStarInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipSlotStarInfo pb = ProtoBuf.Serializer.Deserialize<EquipSlotStarInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//星级
	public int m_RankUp_Level;
	public int RankUp_Level
	{
		get { return m_RankUp_Level;}
		set { m_RankUp_Level = value; }
	}
	//装备槽类型
	public int m_Slot_Type;
	public int Slot_Type
	{
		get { return m_Slot_Type;}
		set { m_Slot_Type = value; }
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//高一星战斗力
	public int m_NextBattleScore;
	public int NextBattleScore
	{
		get { return m_NextBattleScore;}
		set { m_NextBattleScore = value; }
	}


};
//掉落物品封装类
[System.Serializable]
public class DropItemWraper
{

	//构造函数
	public DropItemWraper()
	{
		 m_ItemType = -1;
		 m_ItemID = -1;
		 m_ItemNum = -1;
		 m_Bind = false;
		 m_Transit = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemType = -1;
		 m_ItemID = -1;
		 m_ItemNum = -1;
		 m_Bind = false;
		 m_Transit = false;

	}

 	//转化成Protobuffer类型函数
	public DropItem ToPB()
	{
		DropItem v = new DropItem();
		v.ItemType = m_ItemType;
		v.ItemID = m_ItemID;
		v.ItemNum = m_ItemNum;
		v.Bind = m_Bind;
		v.Transit = m_Transit;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DropItem v)
	{
        if (v == null)
            return;
		m_ItemType = v.ItemType;
		m_ItemID = v.ItemID;
		m_ItemNum = v.ItemNum;
		m_Bind = v.Bind;
		m_Transit = v.Transit;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DropItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DropItem pb = ProtoBuf.Serializer.Deserialize<DropItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品类型
	public int m_ItemType;
	public int ItemType
	{
		get { return m_ItemType;}
		set { m_ItemType = value; }
	}
	//物品编号
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//物品数量
	public int m_ItemNum;
	public int ItemNum
	{
		get { return m_ItemNum;}
		set { m_ItemNum = value; }
	}
	//是否绑定
	public bool m_Bind;
	public bool Bind
	{
		get { return m_Bind;}
		set { m_Bind = value; }
	}
	//transit
	public bool m_Transit;
	public bool Transit
	{
		get { return m_Transit;}
		set { m_Transit = value; }
	}


};
//宠物数据封装类
[System.Serializable]
public class PetDataWraper
{

	//构造函数
	public PetDataWraper()
	{
		 m_Exp = -1;
		 m_Level = -1;
		 m_Name = "";
		m_Attrs = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		m_Talent = new List<AttrKeyValueWraper>();
		m_SkillList = new List<PetSkillWraper>();
		 m_TalentScore = -1;
		 m_Wild = false;
		 m_FeedData = new PetFeedDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Exp = -1;
		 m_Level = -1;
		 m_Name = "";
		m_Attrs = new List<AttrKeyValueWraper>();
		 m_BattleScore = -1;
		m_Talent = new List<AttrKeyValueWraper>();
		m_SkillList = new List<PetSkillWraper>();
		 m_TalentScore = -1;
		 m_Wild = false;
		 m_FeedData = new PetFeedDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetData ToPB()
	{
		PetData v = new PetData();
		v.Exp = m_Exp;
		v.Level = m_Level;
		v.Name = m_Name;
		for (int i=0; i<(int)m_Attrs.Count; i++)
			v.Attrs.Add( m_Attrs[i].ToPB());
		v.BattleScore = m_BattleScore;
		for (int i=0; i<(int)m_Talent.Count; i++)
			v.Talent.Add( m_Talent[i].ToPB());
		for (int i=0; i<(int)m_SkillList.Count; i++)
			v.SkillList.Add( m_SkillList[i].ToPB());
		v.TalentScore = m_TalentScore;
		v.Wild = m_Wild;
		v.FeedData = m_FeedData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetData v)
	{
        if (v == null)
            return;
		m_Exp = v.Exp;
		m_Level = v.Level;
		m_Name = v.Name;
		m_Attrs.Clear();
		for( int i=0; i<v.Attrs.Count; i++)
			m_Attrs.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.Attrs.Count; i++)
			m_Attrs[i].FromPB(v.Attrs[i]);
		m_BattleScore = v.BattleScore;
		m_Talent.Clear();
		for( int i=0; i<v.Talent.Count; i++)
			m_Talent.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.Talent.Count; i++)
			m_Talent[i].FromPB(v.Talent[i]);
		m_SkillList.Clear();
		for( int i=0; i<v.SkillList.Count; i++)
			m_SkillList.Add( new PetSkillWraper());
		for( int i=0; i<v.SkillList.Count; i++)
			m_SkillList[i].FromPB(v.SkillList[i]);
		m_TalentScore = v.TalentScore;
		m_Wild = v.Wild;
		m_FeedData.FromPB(v.FeedData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetData pb = ProtoBuf.Serializer.Deserialize<PetData>(protoMS);
		FromPB(pb);
		return true;
	}

	//经验
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//属性
	public List<AttrKeyValueWraper> m_Attrs;
	public int SizeAttrs()
	{
		return m_Attrs.Count;
	}
	public List<AttrKeyValueWraper> GetAttrs()
	{
		return m_Attrs;
	}
	public AttrKeyValueWraper GetAttrs(int Index)
	{
		if(Index<0 || Index>=(int)m_Attrs.Count)
			return new AttrKeyValueWraper();
		return m_Attrs[Index];
	}
	public void SetAttrs( List<AttrKeyValueWraper> v )
	{
		m_Attrs=v;
	}
	public void SetAttrs( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_Attrs.Count)
			return;
		m_Attrs[Index] = v;
	}
	public void AddAttrs( AttrKeyValueWraper v )
	{
		m_Attrs.Add(v);
	}
	public void ClearAttrs( )
	{
		m_Attrs.Clear();
	}
	//战力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//资质
	public List<AttrKeyValueWraper> m_Talent;
	public int SizeTalent()
	{
		return m_Talent.Count;
	}
	public List<AttrKeyValueWraper> GetTalent()
	{
		return m_Talent;
	}
	public AttrKeyValueWraper GetTalent(int Index)
	{
		if(Index<0 || Index>=(int)m_Talent.Count)
			return new AttrKeyValueWraper();
		return m_Talent[Index];
	}
	public void SetTalent( List<AttrKeyValueWraper> v )
	{
		m_Talent=v;
	}
	public void SetTalent( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_Talent.Count)
			return;
		m_Talent[Index] = v;
	}
	public void AddTalent( AttrKeyValueWraper v )
	{
		m_Talent.Add(v);
	}
	public void ClearTalent( )
	{
		m_Talent.Clear();
	}
	//技能列表
	public List<PetSkillWraper> m_SkillList;
	public int SizeSkillList()
	{
		return m_SkillList.Count;
	}
	public List<PetSkillWraper> GetSkillList()
	{
		return m_SkillList;
	}
	public PetSkillWraper GetSkillList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return new PetSkillWraper();
		return m_SkillList[Index];
	}
	public void SetSkillList( List<PetSkillWraper> v )
	{
		m_SkillList=v;
	}
	public void SetSkillList( int Index, PetSkillWraper v )
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return;
		m_SkillList[Index] = v;
	}
	public void AddSkillList( PetSkillWraper v )
	{
		m_SkillList.Add(v);
	}
	public void ClearSkillList( )
	{
		m_SkillList.Clear();
	}
	//资质评分
	public int m_TalentScore;
	public int TalentScore
	{
		get { return m_TalentScore;}
		set { m_TalentScore = value; }
	}
	//是否野生
	public bool m_Wild;
	public bool Wild
	{
		get { return m_Wild;}
		set { m_Wild = value; }
	}
	//宠物喂养数据
	public PetFeedDataWraper m_FeedData;
	public PetFeedDataWraper FeedData
	{
		get { return m_FeedData;}
		set { m_FeedData = value; }
	}


};
//装备打造神器值封装类
[System.Serializable]
public class EquipBuildAtfWraper
{

	//构造函数
	public EquipBuildAtfWraper()
	{
		 m_Level = -1;
		 m_Atf_value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = -1;
		 m_Atf_value = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipBuildAtf ToPB()
	{
		EquipBuildAtf v = new EquipBuildAtf();
		v.Level = m_Level;
		v.Atf_value = m_Atf_value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipBuildAtf v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Atf_value = v.Atf_value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipBuildAtf>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipBuildAtf pb = ProtoBuf.Serializer.Deserialize<EquipBuildAtf>(protoMS);
		FromPB(pb);
		return true;
	}

	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//神器值
	public int m_Atf_value;
	public int Atf_value
	{
		get { return m_Atf_value;}
		set { m_Atf_value = value; }
	}


};
//珍宝数据封装类
[System.Serializable]
public class TreasureDataWraper
{

	//构造函数
	public TreasureDataWraper()
	{
		 m_ID = -1;
		m_Extra_Info = new List<TreasureExtraInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		m_Extra_Info = new List<TreasureExtraInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public TreasureData ToPB()
	{
		TreasureData v = new TreasureData();
		v.ID = m_ID;
		for (int i=0; i<(int)m_Extra_Info.Count; i++)
			v.Extra_Info.Add( m_Extra_Info[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureData v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_Extra_Info.Clear();
		for( int i=0; i<v.Extra_Info.Count; i++)
			m_Extra_Info.Add( new TreasureExtraInfoWraper());
		for( int i=0; i<v.Extra_Info.Count; i++)
			m_Extra_Info[i].FromPB(v.Extra_Info[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureData pb = ProtoBuf.Serializer.Deserialize<TreasureData>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//珍宝附加信息
	public List<TreasureExtraInfoWraper> m_Extra_Info;
	public int SizeExtra_Info()
	{
		return m_Extra_Info.Count;
	}
	public List<TreasureExtraInfoWraper> GetExtra_Info()
	{
		return m_Extra_Info;
	}
	public TreasureExtraInfoWraper GetExtra_Info(int Index)
	{
		if(Index<0 || Index>=(int)m_Extra_Info.Count)
			return new TreasureExtraInfoWraper();
		return m_Extra_Info[Index];
	}
	public void SetExtra_Info( List<TreasureExtraInfoWraper> v )
	{
		m_Extra_Info=v;
	}
	public void SetExtra_Info( int Index, TreasureExtraInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Extra_Info.Count)
			return;
		m_Extra_Info[Index] = v;
	}
	public void AddExtra_Info( TreasureExtraInfoWraper v )
	{
		m_Extra_Info.Add(v);
	}
	public void ClearExtra_Info( )
	{
		m_Extra_Info.Clear();
	}


};
//珍宝附加信息数据封装类
[System.Serializable]
public class TreasureExtraInfoWraper
{

	//构造函数
	public TreasureExtraInfoWraper()
	{
		 m_Color_Type = -1;
		 m_Time_Type = -1;
		 m_State = 0;
		 m_Expier_Time = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Color_Type = -1;
		 m_Time_Type = -1;
		 m_State = 0;
		 m_Expier_Time = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureExtraInfo ToPB()
	{
		TreasureExtraInfo v = new TreasureExtraInfo();
		v.Color_Type = m_Color_Type;
		v.Time_Type = m_Time_Type;
		v.State = m_State;
		v.Expier_Time = m_Expier_Time;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureExtraInfo v)
	{
        if (v == null)
            return;
		m_Color_Type = v.Color_Type;
		m_Time_Type = v.Time_Type;
		m_State = v.State;
		m_Expier_Time = v.Expier_Time;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureExtraInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureExtraInfo pb = ProtoBuf.Serializer.Deserialize<TreasureExtraInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//颜色类型
	public int m_Color_Type;
	public int Color_Type
	{
		get { return m_Color_Type;}
		set { m_Color_Type = value; }
	}
	//时限类型
	public int m_Time_Type;
	public int Time_Type
	{
		get { return m_Time_Type;}
		set { m_Time_Type = value; }
	}
	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//解锁到期时间
	public Int64 m_Expier_Time;
	public Int64 Expier_Time
	{
		get { return m_Expier_Time;}
		set { m_Expier_Time = value; }
	}


};
//珍宝阁数据信息封装类
[System.Serializable]
public class TreasureDepotDataWraper
{

	//构造函数
	public TreasureDepotDataWraper()
	{
		 m_Level = 1;
		 m_Point = 0;
		m_Treasure_Data = new List<TreasureDataWraper>();
		 m_UnlockCount = -1;
		 m_TotalPoint = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 1;
		 m_Point = 0;
		m_Treasure_Data = new List<TreasureDataWraper>();
		 m_UnlockCount = -1;
		 m_TotalPoint = 0;

	}

 	//转化成Protobuffer类型函数
	public TreasureDepotData ToPB()
	{
		TreasureDepotData v = new TreasureDepotData();
		v.Level = m_Level;
		v.Point = m_Point;
		for (int i=0; i<(int)m_Treasure_Data.Count; i++)
			v.Treasure_Data.Add( m_Treasure_Data[i].ToPB());
		v.UnlockCount = m_UnlockCount;
		v.TotalPoint = m_TotalPoint;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureDepotData v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Point = v.Point;
		m_Treasure_Data.Clear();
		for( int i=0; i<v.Treasure_Data.Count; i++)
			m_Treasure_Data.Add( new TreasureDataWraper());
		for( int i=0; i<v.Treasure_Data.Count; i++)
			m_Treasure_Data[i].FromPB(v.Treasure_Data[i]);
		m_UnlockCount = v.UnlockCount;
		m_TotalPoint = v.TotalPoint;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureDepotData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureDepotData pb = ProtoBuf.Serializer.Deserialize<TreasureDepotData>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝阁等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//珍宝阁点数
	public int m_Point;
	public int Point
	{
		get { return m_Point;}
		set { m_Point = value; }
	}
	//珍宝
	public List<TreasureDataWraper> m_Treasure_Data;
	public int SizeTreasure_Data()
	{
		return m_Treasure_Data.Count;
	}
	public List<TreasureDataWraper> GetTreasure_Data()
	{
		return m_Treasure_Data;
	}
	public TreasureDataWraper GetTreasure_Data(int Index)
	{
		if(Index<0 || Index>=(int)m_Treasure_Data.Count)
			return new TreasureDataWraper();
		return m_Treasure_Data[Index];
	}
	public void SetTreasure_Data( List<TreasureDataWraper> v )
	{
		m_Treasure_Data=v;
	}
	public void SetTreasure_Data( int Index, TreasureDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Treasure_Data.Count)
			return;
		m_Treasure_Data[Index] = v;
	}
	public void AddTreasure_Data( TreasureDataWraper v )
	{
		m_Treasure_Data.Add(v);
	}
	public void ClearTreasure_Data( )
	{
		m_Treasure_Data.Clear();
	}
	//已解锁的外显总数
	public int m_UnlockCount;
	public int UnlockCount
	{
		get { return m_UnlockCount;}
		set { m_UnlockCount = value; }
	}
	//解锁总共获得的点数
	public int m_TotalPoint;
	public int TotalPoint
	{
		get { return m_TotalPoint;}
		set { m_TotalPoint = value; }
	}


};
//ShopItem封装类
[System.Serializable]
public class ShopItemWraper
{

	//构造函数
	public ShopItemWraper()
	{
		 m_ShopItemID = -1;
		 m_TotalBuyCount = -1;
		 m_BuyCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ShopItemID = -1;
		 m_TotalBuyCount = -1;
		 m_BuyCount = -1;

	}

 	//转化成Protobuffer类型函数
	public ShopItem ToPB()
	{
		ShopItem v = new ShopItem();
		v.ShopItemID = m_ShopItemID;
		v.TotalBuyCount = m_TotalBuyCount;
		v.BuyCount = m_BuyCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ShopItem v)
	{
        if (v == null)
            return;
		m_ShopItemID = v.ShopItemID;
		m_TotalBuyCount = v.TotalBuyCount;
		m_BuyCount = v.BuyCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ShopItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ShopItem pb = ProtoBuf.Serializer.Deserialize<ShopItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//ShopItemID
	public int m_ShopItemID;
	public int ShopItemID
	{
		get { return m_ShopItemID;}
		set { m_ShopItemID = value; }
	}
	//TotalBuyCount
	public int m_TotalBuyCount;
	public int TotalBuyCount
	{
		get { return m_TotalBuyCount;}
		set { m_TotalBuyCount = value; }
	}
	//本次购买的数量
	public int m_BuyCount;
	public int BuyCount
	{
		get { return m_BuyCount;}
		set { m_BuyCount = value; }
	}


};
//RandomQuestData封装类
[System.Serializable]
public class RandomQuestDataWraper
{

	//构造函数
	public RandomQuestDataWraper()
	{
		 m_ActivityId = -1;
		m_QuestIdList = new List<int>();
		 m_DayPorgress = 0;
		 m_LastCompleteTime = -1;
		m_RandomListQuestId = new List<int>();
		 m_HoldPorgress = 0;
		 m_HumanLevel = 0;
		 m_ExtraTime = 0;
		m_CurentAcceptList = new List<int>();
		 m_LastAcceptQuestTime = 0;
		 m_DailyActivity = 0;
		 m_LastTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ActivityId = -1;
		m_QuestIdList = new List<int>();
		 m_DayPorgress = 0;
		 m_LastCompleteTime = -1;
		m_RandomListQuestId = new List<int>();
		 m_HoldPorgress = 0;
		 m_HumanLevel = 0;
		 m_ExtraTime = 0;
		m_CurentAcceptList = new List<int>();
		 m_LastAcceptQuestTime = 0;
		 m_DailyActivity = 0;
		 m_LastTime = -1;

	}

 	//转化成Protobuffer类型函数
	public RandomQuestData ToPB()
	{
		RandomQuestData v = new RandomQuestData();
		v.ActivityId = m_ActivityId;
		for (int i=0; i<(int)m_QuestIdList.Count; i++)
			v.QuestIdList.Add( m_QuestIdList[i]);
		v.DayPorgress = m_DayPorgress;
		v.LastCompleteTime = m_LastCompleteTime;
		for (int i=0; i<(int)m_RandomListQuestId.Count; i++)
			v.RandomListQuestId.Add( m_RandomListQuestId[i]);
		v.HoldPorgress = m_HoldPorgress;
		v.HumanLevel = m_HumanLevel;
		v.ExtraTime = m_ExtraTime;
		for (int i=0; i<(int)m_CurentAcceptList.Count; i++)
			v.CurentAcceptList.Add( m_CurentAcceptList[i]);
		v.LastAcceptQuestTime = m_LastAcceptQuestTime;
		v.DailyActivity = m_DailyActivity;
		v.LastTime = m_LastTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RandomQuestData v)
	{
        if (v == null)
            return;
		m_ActivityId = v.ActivityId;
		m_QuestIdList.Clear();
		for( int i=0; i<v.QuestIdList.Count; i++)
			m_QuestIdList.Add(v.QuestIdList[i]);
		m_DayPorgress = v.DayPorgress;
		m_LastCompleteTime = v.LastCompleteTime;
		m_RandomListQuestId.Clear();
		for( int i=0; i<v.RandomListQuestId.Count; i++)
			m_RandomListQuestId.Add(v.RandomListQuestId[i]);
		m_HoldPorgress = v.HoldPorgress;
		m_HumanLevel = v.HumanLevel;
		m_ExtraTime = v.ExtraTime;
		m_CurentAcceptList.Clear();
		for( int i=0; i<v.CurentAcceptList.Count; i++)
			m_CurentAcceptList.Add(v.CurentAcceptList[i]);
		m_LastAcceptQuestTime = v.LastAcceptQuestTime;
		m_DailyActivity = v.DailyActivity;
		m_LastTime = v.LastTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RandomQuestData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RandomQuestData pb = ProtoBuf.Serializer.Deserialize<RandomQuestData>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动id
	public int m_ActivityId;
	public int ActivityId
	{
		get { return m_ActivityId;}
		set { m_ActivityId = value; }
	}
	//任务列表id
	public List<int> m_QuestIdList;
	public int SizeQuestIdList()
	{
		return m_QuestIdList.Count;
	}
	public List<int> GetQuestIdList()
	{
		return m_QuestIdList;
	}
	public int GetQuestIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestIdList.Count)
			return -1;
		return m_QuestIdList[Index];
	}
	public void SetQuestIdList( List<int> v )
	{
		m_QuestIdList=v;
	}
	public void SetQuestIdList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_QuestIdList.Count)
			return;
		m_QuestIdList[Index] = v;
	}
	public void AddQuestIdList( int v=-1 )
	{
		m_QuestIdList.Add(v);
	}
	public void ClearQuestIdList( )
	{
		m_QuestIdList.Clear();
	}
	//日次数
	public int m_DayPorgress;
	public int DayPorgress
	{
		get { return m_DayPorgress;}
		set { m_DayPorgress = value; }
	}
	//活动最后完成时间
	public Int64 m_LastCompleteTime;
	public Int64 LastCompleteTime
	{
		get { return m_LastCompleteTime;}
		set { m_LastCompleteTime = value; }
	}
	//记录完成的任务用
	public List<int> m_RandomListQuestId;
	public int SizeRandomListQuestId()
	{
		return m_RandomListQuestId.Count;
	}
	public List<int> GetRandomListQuestId()
	{
		return m_RandomListQuestId;
	}
	public int GetRandomListQuestId(int Index)
	{
		if(Index<0 || Index>=(int)m_RandomListQuestId.Count)
			return -1;
		return m_RandomListQuestId[Index];
	}
	public void SetRandomListQuestId( List<int> v )
	{
		m_RandomListQuestId=v;
	}
	public void SetRandomListQuestId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_RandomListQuestId.Count)
			return;
		m_RandomListQuestId[Index] = v;
	}
	public void AddRandomListQuestId( int v=-1 )
	{
		m_RandomListQuestId.Add(v);
	}
	public void ClearRandomListQuestId( )
	{
		m_RandomListQuestId.Clear();
	}
	//找回次数
	public int m_HoldPorgress;
	public int HoldPorgress
	{
		get { return m_HoldPorgress;}
		set { m_HoldPorgress = value; }
	}
	//资源找回等级
	public int m_HumanLevel;
	public int HumanLevel
	{
		get { return m_HumanLevel;}
		set { m_HumanLevel = value; }
	}
	//额外次数
	public int m_ExtraTime;
	public int ExtraTime
	{
		get { return m_ExtraTime;}
		set { m_ExtraTime = value; }
	}
	//当前接受了的任务，防止升级后和表的任务对应不上
	public List<int> m_CurentAcceptList;
	public int SizeCurentAcceptList()
	{
		return m_CurentAcceptList.Count;
	}
	public List<int> GetCurentAcceptList()
	{
		return m_CurentAcceptList;
	}
	public int GetCurentAcceptList(int Index)
	{
		if(Index<0 || Index>=(int)m_CurentAcceptList.Count)
			return -1;
		return m_CurentAcceptList[Index];
	}
	public void SetCurentAcceptList( List<int> v )
	{
		m_CurentAcceptList=v;
	}
	public void SetCurentAcceptList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_CurentAcceptList.Count)
			return;
		m_CurentAcceptList[Index] = v;
	}
	public void AddCurentAcceptList( int v=-1 )
	{
		m_CurentAcceptList.Add(v);
	}
	public void ClearCurentAcceptList( )
	{
		m_CurentAcceptList.Clear();
	}
	//上次接此活动的时间
	public Int64 m_LastAcceptQuestTime;
	public Int64 LastAcceptQuestTime
	{
		get { return m_LastAcceptQuestTime;}
		set { m_LastAcceptQuestTime = value; }
	}
	//每日已经获得活跃度
	public int m_DailyActivity;
	public int DailyActivity
	{
		get { return m_DailyActivity;}
		set { m_DailyActivity = value; }
	}
	//LastTime
	public Int64 m_LastTime;
	public Int64 LastTime
	{
		get { return m_LastTime;}
		set { m_LastTime = value; }
	}


};
//随机任务数据库封装类
[System.Serializable]
public class RandomQuestListDataWraper
{

	//构造函数
	public RandomQuestListDataWraper()
	{
		m_QuestList = new List<RandomQuestDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_QuestList = new List<RandomQuestDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public RandomQuestListData ToPB()
	{
		RandomQuestListData v = new RandomQuestListData();
		for (int i=0; i<(int)m_QuestList.Count; i++)
			v.QuestList.Add( m_QuestList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RandomQuestListData v)
	{
        if (v == null)
            return;
		m_QuestList.Clear();
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList.Add( new RandomQuestDataWraper());
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList[i].FromPB(v.QuestList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RandomQuestListData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RandomQuestListData pb = ProtoBuf.Serializer.Deserialize<RandomQuestListData>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务列表
	public List<RandomQuestDataWraper> m_QuestList;
	public int SizeQuestList()
	{
		return m_QuestList.Count;
	}
	public List<RandomQuestDataWraper> GetQuestList()
	{
		return m_QuestList;
	}
	public RandomQuestDataWraper GetQuestList(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return new RandomQuestDataWraper();
		return m_QuestList[Index];
	}
	public void SetQuestList( List<RandomQuestDataWraper> v )
	{
		m_QuestList=v;
	}
	public void SetQuestList( int Index, RandomQuestDataWraper v )
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return;
		m_QuestList[Index] = v;
	}
	public void AddQuestList( RandomQuestDataWraper v )
	{
		m_QuestList.Add(v);
	}
	public void ClearQuestList( )
	{
		m_QuestList.Clear();
	}


};
//PvpBattleInfo封装类
[System.Serializable]
public class PvpBattleInfoWraper
{

	//构造函数
	public PvpBattleInfoWraper()
	{
		 m_WinCount = -1;
		 m_LoseCount = -1;
		 m_DrawCount = -1;
		 m_ContinuityWinCount = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Elo = -1;
		 m_BattleCount = -1;
		m_RewardList = new List<int>();
		 m_HistoryRank = -1;
		 m_TodayFirst = false;
		 m_ContinuityLoseCount = -1;
		 m_DailyWinCount = -1;
		 m_DailyBattleCount = -1;
		m_DailyReward = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_WinCount = -1;
		 m_LoseCount = -1;
		 m_DrawCount = -1;
		 m_ContinuityWinCount = -1;
		 m_Rank = -1;
		 m_Star = -1;
		 m_Elo = -1;
		 m_BattleCount = -1;
		m_RewardList = new List<int>();
		 m_HistoryRank = -1;
		 m_TodayFirst = false;
		 m_ContinuityLoseCount = -1;
		 m_DailyWinCount = -1;
		 m_DailyBattleCount = -1;
		m_DailyReward = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public PvpBattleInfo ToPB()
	{
		PvpBattleInfo v = new PvpBattleInfo();
		v.WinCount = m_WinCount;
		v.LoseCount = m_LoseCount;
		v.DrawCount = m_DrawCount;
		v.ContinuityWinCount = m_ContinuityWinCount;
		v.Rank = m_Rank;
		v.Star = m_Star;
		v.Elo = m_Elo;
		v.BattleCount = m_BattleCount;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i]);
		v.HistoryRank = m_HistoryRank;
		v.TodayFirst = m_TodayFirst;
		v.ContinuityLoseCount = m_ContinuityLoseCount;
		v.DailyWinCount = m_DailyWinCount;
		v.DailyBattleCount = m_DailyBattleCount;
		for (int i=0; i<(int)m_DailyReward.Count; i++)
			v.DailyReward.Add( m_DailyReward[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpBattleInfo v)
	{
        if (v == null)
            return;
		m_WinCount = v.WinCount;
		m_LoseCount = v.LoseCount;
		m_DrawCount = v.DrawCount;
		m_ContinuityWinCount = v.ContinuityWinCount;
		m_Rank = v.Rank;
		m_Star = v.Star;
		m_Elo = v.Elo;
		m_BattleCount = v.BattleCount;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add(v.RewardList[i]);
		m_HistoryRank = v.HistoryRank;
		m_TodayFirst = v.TodayFirst;
		m_ContinuityLoseCount = v.ContinuityLoseCount;
		m_DailyWinCount = v.DailyWinCount;
		m_DailyBattleCount = v.DailyBattleCount;
		m_DailyReward.Clear();
		for( int i=0; i<v.DailyReward.Count; i++)
			m_DailyReward.Add(v.DailyReward[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpBattleInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpBattleInfo pb = ProtoBuf.Serializer.Deserialize<PvpBattleInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//WinCount
	public int m_WinCount;
	public int WinCount
	{
		get { return m_WinCount;}
		set { m_WinCount = value; }
	}
	//LoseCount
	public int m_LoseCount;
	public int LoseCount
	{
		get { return m_LoseCount;}
		set { m_LoseCount = value; }
	}
	//DrawCount
	public int m_DrawCount;
	public int DrawCount
	{
		get { return m_DrawCount;}
		set { m_DrawCount = value; }
	}
	//ContinuityWinCount
	public int m_ContinuityWinCount;
	public int ContinuityWinCount
	{
		get { return m_ContinuityWinCount;}
		set { m_ContinuityWinCount = value; }
	}
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//Star
	public int m_Star;
	public int Star
	{
		get { return m_Star;}
		set { m_Star = value; }
	}
	//Elo
	public int m_Elo;
	public int Elo
	{
		get { return m_Elo;}
		set { m_Elo = value; }
	}
	//对局次数
	public int m_BattleCount;
	public int BattleCount
	{
		get { return m_BattleCount;}
		set { m_BattleCount = value; }
	}
	//领取过的段位奖励
	public List<int> m_RewardList;
	public int SizeRewardList()
	{
		return m_RewardList.Count;
	}
	public List<int> GetRewardList()
	{
		return m_RewardList;
	}
	public int GetRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return -1;
		return m_RewardList[Index];
	}
	public void SetRewardList( List<int> v )
	{
		m_RewardList=v;
	}
	public void SetRewardList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return;
		m_RewardList[Index] = v;
	}
	public void AddRewardList( int v=-1 )
	{
		m_RewardList.Add(v);
	}
	public void ClearRewardList( )
	{
		m_RewardList.Clear();
	}
	//历史最高段位
	public int m_HistoryRank;
	public int HistoryRank
	{
		get { return m_HistoryRank;}
		set { m_HistoryRank = value; }
	}
	//每日首胜
	public bool m_TodayFirst;
	public bool TodayFirst
	{
		get { return m_TodayFirst;}
		set { m_TodayFirst = value; }
	}
	//连败场次
	public int m_ContinuityLoseCount;
	public int ContinuityLoseCount
	{
		get { return m_ContinuityLoseCount;}
		set { m_ContinuityLoseCount = value; }
	}
	//今日胜利次数
	public int m_DailyWinCount;
	public int DailyWinCount
	{
		get { return m_DailyWinCount;}
		set { m_DailyWinCount = value; }
	}
	//今日参与次数
	public int m_DailyBattleCount;
	public int DailyBattleCount
	{
		get { return m_DailyBattleCount;}
		set { m_DailyBattleCount = value; }
	}
	//领过的每日奖励
	public List<int> m_DailyReward;
	public int SizeDailyReward()
	{
		return m_DailyReward.Count;
	}
	public List<int> GetDailyReward()
	{
		return m_DailyReward;
	}
	public int GetDailyReward(int Index)
	{
		if(Index<0 || Index>=(int)m_DailyReward.Count)
			return -1;
		return m_DailyReward[Index];
	}
	public void SetDailyReward( List<int> v )
	{
		m_DailyReward=v;
	}
	public void SetDailyReward( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_DailyReward.Count)
			return;
		m_DailyReward[Index] = v;
	}
	public void AddDailyReward( int v=-1 )
	{
		m_DailyReward.Add(v);
	}
	public void ClearDailyReward( )
	{
		m_DailyReward.Clear();
	}


};
//PvpPlayerInfo封装类
[System.Serializable]
public class PvpPlayerInfoWraper
{

	//构造函数
	public PvpPlayerInfoWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_Level = -1;
		 m_Rank = -1;
		 m_PvpInfo = new PvpBattleInfoWraper();
		 m_GuildName = "";
		 m_ConfigID = -1;
		 m_Robot = false;
		 m_ProfessionId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_Level = -1;
		 m_Rank = -1;
		 m_PvpInfo = new PvpBattleInfoWraper();
		 m_GuildName = "";
		 m_ConfigID = -1;
		 m_Robot = false;
		 m_ProfessionId = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpPlayerInfo ToPB()
	{
		PvpPlayerInfo v = new PvpPlayerInfo();
		v.RoleID = m_RoleID;
		v.RoleName = m_RoleName;
		v.Level = m_Level;
		v.Rank = m_Rank;
		v.PvpInfo = m_PvpInfo.ToPB();
		v.GuildName = m_GuildName;
		v.ConfigID = m_ConfigID;
		v.Robot = m_Robot;
		v.ProfessionId = m_ProfessionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpPlayerInfo v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_RoleName = v.RoleName;
		m_Level = v.Level;
		m_Rank = v.Rank;
		m_PvpInfo.FromPB(v.PvpInfo);
		m_GuildName = v.GuildName;
		m_ConfigID = v.ConfigID;
		m_Robot = v.Robot;
		m_ProfessionId = v.ProfessionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpPlayerInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpPlayerInfo pb = ProtoBuf.Serializer.Deserialize<PvpPlayerInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//RoleName
	public string m_RoleName;
	public string RoleName
	{
		get { return m_RoleName;}
		set { m_RoleName = value; }
	}
	//Level
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//Rank
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}
	//PvpInfo
	public PvpBattleInfoWraper m_PvpInfo;
	public PvpBattleInfoWraper PvpInfo
	{
		get { return m_PvpInfo;}
		set { m_PvpInfo = value; }
	}
	//GuildName
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//ConfigID
	public int m_ConfigID;
	public int ConfigID
	{
		get { return m_ConfigID;}
		set { m_ConfigID = value; }
	}
	//是否机器人
	public bool m_Robot;
	public bool Robot
	{
		get { return m_Robot;}
		set { m_Robot = value; }
	}
	//专精ID
	public int m_ProfessionId;
	public int ProfessionId
	{
		get { return m_ProfessionId;}
		set { m_ProfessionId = value; }
	}


};
//玩家准备状态封装类
[System.Serializable]
public class PvpPlayerStateWraper
{

	//构造函数
	public PvpPlayerStateWraper()
	{
		 m_RoleID = 0;
		 m_State = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_State = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpPlayerState ToPB()
	{
		PvpPlayerState v = new PvpPlayerState();
		v.RoleID = m_RoleID;
		v.State = m_State;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpPlayerState v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_State = v.State;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpPlayerState>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpPlayerState pb = ProtoBuf.Serializer.Deserialize<PvpPlayerState>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//State
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}


};
//PvpEndPlayer封装类
[System.Serializable]
public class PvpEndPlayerWraper
{

	//构造函数
	public PvpEndPlayerWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_DeadCount = -1;
		 m_KillCount = -1;
		 m_LiveCount = -1;
		 m_ConfigId = -1;
		 m_DamageCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_DeadCount = -1;
		 m_KillCount = -1;
		 m_LiveCount = -1;
		 m_ConfigId = -1;
		 m_DamageCount = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpEndPlayer ToPB()
	{
		PvpEndPlayer v = new PvpEndPlayer();
		v.RoleID = m_RoleID;
		v.RoleName = m_RoleName;
		v.DeadCount = m_DeadCount;
		v.KillCount = m_KillCount;
		v.LiveCount = m_LiveCount;
		v.ConfigId = m_ConfigId;
		v.DamageCount = m_DamageCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpEndPlayer v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_RoleName = v.RoleName;
		m_DeadCount = v.DeadCount;
		m_KillCount = v.KillCount;
		m_LiveCount = v.LiveCount;
		m_ConfigId = v.ConfigId;
		m_DamageCount = v.DamageCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpEndPlayer>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpEndPlayer pb = ProtoBuf.Serializer.Deserialize<PvpEndPlayer>(protoMS);
		FromPB(pb);
		return true;
	}

	//RoleID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//RoleName
	public string m_RoleName;
	public string RoleName
	{
		get { return m_RoleName;}
		set { m_RoleName = value; }
	}
	//DeadCount
	public int m_DeadCount;
	public int DeadCount
	{
		get { return m_DeadCount;}
		set { m_DeadCount = value; }
	}
	//KillCount
	public int m_KillCount;
	public int KillCount
	{
		get { return m_KillCount;}
		set { m_KillCount = value; }
	}
	//LiveCount
	public int m_LiveCount;
	public int LiveCount
	{
		get { return m_LiveCount;}
		set { m_LiveCount = value; }
	}
	//ConfigId
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//伤害量
	public int m_DamageCount;
	public int DamageCount
	{
		get { return m_DamageCount;}
		set { m_DamageCount = value; }
	}


};
//日常任务封装类
[System.Serializable]
public class DailyQuestWraper
{

	//构造函数
	public DailyQuestWraper()
	{
		 m_MainQuest = new QuestDataWraper();
		 m_AtivityQuest = new QuestDataWraper();
		 m_RewardTimes = -1;
		 m_ActivityId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MainQuest = new QuestDataWraper();
		 m_AtivityQuest = new QuestDataWraper();
		 m_RewardTimes = -1;
		 m_ActivityId = -1;

	}

 	//转化成Protobuffer类型函数
	public DailyQuest ToPB()
	{
		DailyQuest v = new DailyQuest();
		v.MainQuest = m_MainQuest.ToPB();
		v.AtivityQuest = m_AtivityQuest.ToPB();
		v.RewardTimes = m_RewardTimes;
		v.ActivityId = m_ActivityId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DailyQuest v)
	{
        if (v == null)
            return;
		m_MainQuest.FromPB(v.MainQuest);
		m_AtivityQuest.FromPB(v.AtivityQuest);
		m_RewardTimes = v.RewardTimes;
		m_ActivityId = v.ActivityId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DailyQuest>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DailyQuest pb = ProtoBuf.Serializer.Deserialize<DailyQuest>(protoMS);
		FromPB(pb);
		return true;
	}

	//主任务
	public QuestDataWraper m_MainQuest;
	public QuestDataWraper MainQuest
	{
		get { return m_MainQuest;}
		set { m_MainQuest = value; }
	}
	//活跃度任务
	public QuestDataWraper m_AtivityQuest;
	public QuestDataWraper AtivityQuest
	{
		get { return m_AtivityQuest;}
		set { m_AtivityQuest = value; }
	}
	//奖励倍数
	public int m_RewardTimes;
	public int RewardTimes
	{
		get { return m_RewardTimes;}
		set { m_RewardTimes = value; }
	}
	//ActivityId
	public int m_ActivityId;
	public int ActivityId
	{
		get { return m_ActivityId;}
		set { m_ActivityId = value; }
	}


};
//DailyQuestList封装类
[System.Serializable]
public class DailyQuestListWraper
{

	//构造函数
	public DailyQuestListWraper()
	{
		m_DailyQuestList = new List<DailyQuestWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_DailyQuestList = new List<DailyQuestWraper>();

	}

 	//转化成Protobuffer类型函数
	public DailyQuestList ToPB()
	{
		DailyQuestList v = new DailyQuestList();
		for (int i=0; i<(int)m_DailyQuestList.Count; i++)
			v.DailyQuestList.Add( m_DailyQuestList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DailyQuestList v)
	{
        if (v == null)
            return;
		m_DailyQuestList.Clear();
		for( int i=0; i<v.DailyQuestList.Count; i++)
			m_DailyQuestList.Add( new DailyQuestWraper());
		for( int i=0; i<v.DailyQuestList.Count; i++)
			m_DailyQuestList[i].FromPB(v.DailyQuestList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DailyQuestList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DailyQuestList pb = ProtoBuf.Serializer.Deserialize<DailyQuestList>(protoMS);
		FromPB(pb);
		return true;
	}

	//DailyQuestList
	public List<DailyQuestWraper> m_DailyQuestList;
	public int SizeDailyQuestList()
	{
		return m_DailyQuestList.Count;
	}
	public List<DailyQuestWraper> GetDailyQuestList()
	{
		return m_DailyQuestList;
	}
	public DailyQuestWraper GetDailyQuestList(int Index)
	{
		if(Index<0 || Index>=(int)m_DailyQuestList.Count)
			return new DailyQuestWraper();
		return m_DailyQuestList[Index];
	}
	public void SetDailyQuestList( List<DailyQuestWraper> v )
	{
		m_DailyQuestList=v;
	}
	public void SetDailyQuestList( int Index, DailyQuestWraper v )
	{
		if(Index<0 || Index>=(int)m_DailyQuestList.Count)
			return;
		m_DailyQuestList[Index] = v;
	}
	public void AddDailyQuestList( DailyQuestWraper v )
	{
		m_DailyQuestList.Add(v);
	}
	public void ClearDailyQuestList( )
	{
		m_DailyQuestList.Clear();
	}


};
//副本数据封装类
[System.Serializable]
public class DungeonDataWraper
{

	//构造函数
	public DungeonDataWraper()
	{
		 m_DurationMentTime = 0;
		 m_ConclusionTime = 0;
		 m_PrepareTime = 0;
		 m_RewardTime = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DurationMentTime = 0;
		 m_ConclusionTime = 0;
		 m_PrepareTime = 0;
		 m_RewardTime = 0;

	}

 	//转化成Protobuffer类型函数
	public DungeonData ToPB()
	{
		DungeonData v = new DungeonData();
		v.DurationMentTime = m_DurationMentTime;
		v.ConclusionTime = m_ConclusionTime;
		v.PrepareTime = m_PrepareTime;
		v.RewardTime = m_RewardTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonData v)
	{
        if (v == null)
            return;
		m_DurationMentTime = v.DurationMentTime;
		m_ConclusionTime = v.ConclusionTime;
		m_PrepareTime = v.PrepareTime;
		m_RewardTime = v.RewardTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonData pb = ProtoBuf.Serializer.Deserialize<DungeonData>(protoMS);
		FromPB(pb);
		return true;
	}

	//副本释放
	public int m_DurationMentTime;
	public int DurationMentTime
	{
		get { return m_DurationMentTime;}
		set { m_DurationMentTime = value; }
	}
	//副本结算时间
	public int m_ConclusionTime;
	public int ConclusionTime
	{
		get { return m_ConclusionTime;}
		set { m_ConclusionTime = value; }
	}
	//副本准备时间
	public int m_PrepareTime;
	public int PrepareTime
	{
		get { return m_PrepareTime;}
		set { m_PrepareTime = value; }
	}
	//奖励时间
	public int m_RewardTime;
	public int RewardTime
	{
		get { return m_RewardTime;}
		set { m_RewardTime = value; }
	}


};
//目标队伍封装类
[System.Serializable]
public class TeamTargetWraper
{

	//构造函数
	public TeamTargetWraper()
	{
		 m_Id = 0;
		 m_MinLevel = 0;
		 m_MaxLevel = 0;
		m_Profession = new List<TeamProfessionTargetWraper>();
		 m_TargetType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = 0;
		 m_MinLevel = 0;
		 m_MaxLevel = 0;
		m_Profession = new List<TeamProfessionTargetWraper>();
		 m_TargetType = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamTarget ToPB()
	{
		TeamTarget v = new TeamTarget();
		v.Id = m_Id;
		v.MinLevel = m_MinLevel;
		v.MaxLevel = m_MaxLevel;
		for (int i=0; i<(int)m_Profession.Count; i++)
			v.Profession.Add( m_Profession[i].ToPB());
		v.TargetType = m_TargetType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamTarget v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_MinLevel = v.MinLevel;
		m_MaxLevel = v.MaxLevel;
		m_Profession.Clear();
		for( int i=0; i<v.Profession.Count; i++)
			m_Profession.Add( new TeamProfessionTargetWraper());
		for( int i=0; i<v.Profession.Count; i++)
			m_Profession[i].FromPB(v.Profession[i]);
		m_TargetType = v.TargetType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamTarget>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamTarget pb = ProtoBuf.Serializer.Deserialize<TeamTarget>(protoMS);
		FromPB(pb);
		return true;
	}

	//唯一标识　全部队伍：0
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//最小等级
	public int m_MinLevel;
	public int MinLevel
	{
		get { return m_MinLevel;}
		set { m_MinLevel = value; }
	}
	//最大等级
	public int m_MaxLevel;
	public int MaxLevel
	{
		get { return m_MaxLevel;}
		set { m_MaxLevel = value; }
	}
	//职能
	public List<TeamProfessionTargetWraper> m_Profession;
	public int SizeProfession()
	{
		return m_Profession.Count;
	}
	public List<TeamProfessionTargetWraper> GetProfession()
	{
		return m_Profession;
	}
	public TeamProfessionTargetWraper GetProfession(int Index)
	{
		if(Index<0 || Index>=(int)m_Profession.Count)
			return new TeamProfessionTargetWraper();
		return m_Profession[Index];
	}
	public void SetProfession( List<TeamProfessionTargetWraper> v )
	{
		m_Profession=v;
	}
	public void SetProfession( int Index, TeamProfessionTargetWraper v )
	{
		if(Index<0 || Index>=(int)m_Profession.Count)
			return;
		m_Profession[Index] = v;
	}
	public void AddProfession( TeamProfessionTargetWraper v )
	{
		m_Profession.Add(v);
	}
	public void ClearProfession( )
	{
		m_Profession.Clear();
	}
	//目标类型
	public int m_TargetType;
	public int TargetType
	{
		get { return m_TargetType;}
		set { m_TargetType = value; }
	}


};
//buff信息封装类
[System.Serializable]
public class BuffInfoWraper
{

	//构造函数
	public BuffInfoWraper()
	{
		 m_ObjId = 0;
		 m_CasterId = 0;
		 m_OpType = -1;
		 m_BufId = -1;
		 m_RemainTime = -1;
		 m_BuffLv = -1;
		 m_Sn = -1;
		 m_LayerCount = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_CasterId = 0;
		 m_OpType = -1;
		 m_BufId = -1;
		 m_RemainTime = -1;
		 m_BuffLv = -1;
		 m_Sn = -1;
		 m_LayerCount = 0;

	}

 	//转化成Protobuffer类型函数
	public BuffInfo ToPB()
	{
		BuffInfo v = new BuffInfo();
		v.ObjId = m_ObjId;
		v.CasterId = m_CasterId;
		v.OpType = m_OpType;
		v.BufId = m_BufId;
		v.RemainTime = m_RemainTime;
		v.BuffLv = m_BuffLv;
		v.Sn = m_Sn;
		v.LayerCount = m_LayerCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuffInfo v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_CasterId = v.CasterId;
		m_OpType = v.OpType;
		m_BufId = v.BufId;
		m_RemainTime = v.RemainTime;
		m_BuffLv = v.BuffLv;
		m_Sn = v.Sn;
		m_LayerCount = v.LayerCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuffInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuffInfo pb = ProtoBuf.Serializer.Deserialize<BuffInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//持有者ID
	public UInt64 m_ObjId;
	public UInt64 ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//Buff释放者ID
	public UInt64 m_CasterId;
	public UInt64 CasterId
	{
		get { return m_CasterId;}
		set { m_CasterId = value; }
	}
	//操作类型
	public int m_OpType;
	public int OpType
	{
		get { return m_OpType;}
		set { m_OpType = value; }
	}
	//bufid
	public int m_BufId;
	public int BufId
	{
		get { return m_BufId;}
		set { m_BufId = value; }
	}
	//剩余时间
	public int m_RemainTime;
	public int RemainTime
	{
		get { return m_RemainTime;}
		set { m_RemainTime = value; }
	}
	//buf 等级
	public int m_BuffLv;
	public int BuffLv
	{
		get { return m_BuffLv;}
		set { m_BuffLv = value; }
	}
	//buff序列号
	public int m_Sn;
	public int Sn
	{
		get { return m_Sn;}
		set { m_Sn = value; }
	}
	//层数
	public int m_LayerCount;
	public int LayerCount
	{
		get { return m_LayerCount;}
		set { m_LayerCount = value; }
	}


};
//匹配信息封装类
[System.Serializable]
public class MatchInfoWraper
{

	//构造函数
	public MatchInfoWraper()
	{
		 m_RoleId = 0;
		 m_Level = 0;
		 m_ConfigId = -1;
		 m_ProfessionId = -1;
		 m_Name = "";
		 m_Ready = -1;
		 m_Camp = 0;
		 m_Integral = 0;
		 m_Section = 0;
		 m_Robot = false;
		 m_GhostGuid = 0;
		 m_Guild = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Level = 0;
		 m_ConfigId = -1;
		 m_ProfessionId = -1;
		 m_Name = "";
		 m_Ready = -1;
		 m_Camp = 0;
		 m_Integral = 0;
		 m_Section = 0;
		 m_Robot = false;
		 m_GhostGuid = 0;
		 m_Guild = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchInfo ToPB()
	{
		MatchInfo v = new MatchInfo();
		v.RoleId = m_RoleId;
		v.Level = m_Level;
		v.ConfigId = m_ConfigId;
		v.ProfessionId = m_ProfessionId;
		v.Name = m_Name;
		v.Ready = m_Ready;
		v.Camp = m_Camp;
		v.Integral = m_Integral;
		v.Section = m_Section;
		v.Robot = m_Robot;
		v.GhostGuid = m_GhostGuid;
		v.Guild = m_Guild;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Level = v.Level;
		m_ConfigId = v.ConfigId;
		m_ProfessionId = v.ProfessionId;
		m_Name = v.Name;
		m_Ready = v.Ready;
		m_Camp = v.Camp;
		m_Integral = v.Integral;
		m_Section = v.Section;
		m_Robot = v.Robot;
		m_GhostGuid = v.GhostGuid;
		m_Guild = v.Guild;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchInfo pb = ProtoBuf.Serializer.Deserialize<MatchInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//玩家等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//configid
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//专精ID
	public int m_ProfessionId;
	public int ProfessionId
	{
		get { return m_ProfessionId;}
		set { m_ProfessionId = value; }
	}
	//name
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//准备
	public int m_Ready;
	public int Ready
	{
		get { return m_Ready;}
		set { m_Ready = value; }
	}
	//阵营
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//积分
	public int m_Integral;
	public int Integral
	{
		get { return m_Integral;}
		set { m_Integral = value; }
	}
	//段位
	public int m_Section;
	public int Section
	{
		get { return m_Section;}
		set { m_Section = value; }
	}
	//机器人
	public bool m_Robot;
	public bool Robot
	{
		get { return m_Robot;}
		set { m_Robot = value; }
	}
	//幽灵
	public UInt64 m_GhostGuid;
	public UInt64 GhostGuid
	{
		get { return m_GhostGuid;}
		set { m_GhostGuid = value; }
	}
	//帮会id
	public UInt64 m_Guild;
	public UInt64 Guild
	{
		get { return m_Guild;}
		set { m_Guild = value; }
	}


};
//装备时装ID封装类
[System.Serializable]
public class TreasureEquipedIDWraper
{

	//构造函数
	public TreasureEquipedIDWraper()
	{
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TreasureRiding = -1;
		 m_TreasureFootPrint = -1;
		 m_EquipHair = -1;
		 m_EquipHead = -1;
		 m_EquipBody = -1;
		 m_EquipWeapon = -1;
		 m_Headdisplayswitch = true;
		 m_Fashiondisplayswitch = true;
		 m_InitHair = -1;
		 m_InitHead = -1;
		 m_InitBody = -1;
		 m_InitWeapon = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TreasureRiding = -1;
		 m_TreasureFootPrint = -1;
		 m_EquipHair = -1;
		 m_EquipHead = -1;
		 m_EquipBody = -1;
		 m_EquipWeapon = -1;
		 m_Headdisplayswitch = true;
		 m_Fashiondisplayswitch = true;
		 m_InitHair = -1;
		 m_InitHead = -1;
		 m_InitBody = -1;
		 m_InitWeapon = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureEquipedID ToPB()
	{
		TreasureEquipedID v = new TreasureEquipedID();
		v.TreasureHair = m_TreasureHair;
		v.TreasureHead = m_TreasureHead;
		v.TreasureBody = m_TreasureBody;
		v.TreasureWeapon = m_TreasureWeapon;
		v.TreasureWing = m_TreasureWing;
		v.TreasureRiding = m_TreasureRiding;
		v.TreasureFootPrint = m_TreasureFootPrint;
		v.EquipHair = m_EquipHair;
		v.EquipHead = m_EquipHead;
		v.EquipBody = m_EquipBody;
		v.EquipWeapon = m_EquipWeapon;
		v.Headdisplayswitch = m_Headdisplayswitch;
		v.Fashiondisplayswitch = m_Fashiondisplayswitch;
		v.InitHair = m_InitHair;
		v.InitHead = m_InitHead;
		v.InitBody = m_InitBody;
		v.InitWeapon = m_InitWeapon;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureEquipedID v)
	{
        if (v == null)
            return;
		m_TreasureHair = v.TreasureHair;
		m_TreasureHead = v.TreasureHead;
		m_TreasureBody = v.TreasureBody;
		m_TreasureWeapon = v.TreasureWeapon;
		m_TreasureWing = v.TreasureWing;
		m_TreasureRiding = v.TreasureRiding;
		m_TreasureFootPrint = v.TreasureFootPrint;
		m_EquipHair = v.EquipHair;
		m_EquipHead = v.EquipHead;
		m_EquipBody = v.EquipBody;
		m_EquipWeapon = v.EquipWeapon;
		m_Headdisplayswitch = v.Headdisplayswitch;
		m_Fashiondisplayswitch = v.Fashiondisplayswitch;
		m_InitHair = v.InitHair;
		m_InitHead = v.InitHead;
		m_InitBody = v.InitBody;
		m_InitWeapon = v.InitWeapon;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureEquipedID>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureEquipedID pb = ProtoBuf.Serializer.Deserialize<TreasureEquipedID>(protoMS);
		FromPB(pb);
		return true;
	}

	//头发(时装)
	public int m_TreasureHair;
	public int TreasureHair
	{
		get { return m_TreasureHair;}
		set { m_TreasureHair = value; }
	}
	//头部(时装)
	public int m_TreasureHead;
	public int TreasureHead
	{
		get { return m_TreasureHead;}
		set { m_TreasureHead = value; }
	}
	//身体(时装)
	public int m_TreasureBody;
	public int TreasureBody
	{
		get { return m_TreasureBody;}
		set { m_TreasureBody = value; }
	}
	//武器(时装)
	public int m_TreasureWeapon;
	public int TreasureWeapon
	{
		get { return m_TreasureWeapon;}
		set { m_TreasureWeapon = value; }
	}
	//翅膀
	public int m_TreasureWing;
	public int TreasureWing
	{
		get { return m_TreasureWing;}
		set { m_TreasureWing = value; }
	}
	//坐骑
	public int m_TreasureRiding;
	public int TreasureRiding
	{
		get { return m_TreasureRiding;}
		set { m_TreasureRiding = value; }
	}
	//步尘
	public int m_TreasureFootPrint;
	public int TreasureFootPrint
	{
		get { return m_TreasureFootPrint;}
		set { m_TreasureFootPrint = value; }
	}
	//头发(真实)(服务器存库用)
	public int m_EquipHair;
	public int EquipHair
	{
		get { return m_EquipHair;}
		set { m_EquipHair = value; }
	}
	//头部(真实)(服务器存库用)
	public int m_EquipHead;
	public int EquipHead
	{
		get { return m_EquipHead;}
		set { m_EquipHead = value; }
	}
	//身体(真实)(服务器存库用)
	public int m_EquipBody;
	public int EquipBody
	{
		get { return m_EquipBody;}
		set { m_EquipBody = value; }
	}
	//武器(真实)(服务器存库用)
	public int m_EquipWeapon;
	public int EquipWeapon
	{
		get { return m_EquipWeapon;}
		set { m_EquipWeapon = value; }
	}
	//头部显示开关
	public bool m_Headdisplayswitch;
	public bool Headdisplayswitch
	{
		get { return m_Headdisplayswitch;}
		set { m_Headdisplayswitch = value; }
	}
	//时装显示开关
	public bool m_Fashiondisplayswitch;
	public bool Fashiondisplayswitch
	{
		get { return m_Fashiondisplayswitch;}
		set { m_Fashiondisplayswitch = value; }
	}
	//默认头发(服务器存库用)
	public int m_InitHair;
	public int InitHair
	{
		get { return m_InitHair;}
		set { m_InitHair = value; }
	}
	//默认脸(服务器存库用)
	public int m_InitHead;
	public int InitHead
	{
		get { return m_InitHead;}
		set { m_InitHead = value; }
	}
	//默认护甲(服务器存库用)
	public int m_InitBody;
	public int InitBody
	{
		get { return m_InitBody;}
		set { m_InitBody = value; }
	}
	//默认武器(服务器存库用)
	public int m_InitWeapon;
	public int InitWeapon
	{
		get { return m_InitWeapon;}
		set { m_InitWeapon = value; }
	}


};
//ServerInfo封装类
[System.Serializable]
public class ServerInfoWraper
{

	//构造函数
	public ServerInfoWraper()
	{
		 m_Id = -1;
		 m_Name = "";
		 m_Region = -1;
		 m_Status = -1;
		 m_Promo = -1;
		 m_Ip = "";
		 m_Port = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Name = "";
		 m_Region = -1;
		 m_Status = -1;
		 m_Promo = -1;
		 m_Ip = "";
		 m_Port = -1;

	}

 	//转化成Protobuffer类型函数
	public ServerInfo ToPB()
	{
		ServerInfo v = new ServerInfo();
		v.Id = m_Id;
		v.Name = m_Name;
		v.Region = m_Region;
		v.Status = m_Status;
		v.Promo = m_Promo;
		v.Ip = m_Ip;
		v.Port = m_Port;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ServerInfo v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Name = v.Name;
		m_Region = v.Region;
		m_Status = v.Status;
		m_Promo = v.Promo;
		m_Ip = v.Ip;
		m_Port = v.Port;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ServerInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ServerInfo pb = ProtoBuf.Serializer.Deserialize<ServerInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//服务器名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//大区
	public int m_Region;
	public int Region
	{
		get { return m_Region;}
		set { m_Region = value; }
	}
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//推荐
	public int m_Promo;
	public int Promo
	{
		get { return m_Promo;}
		set { m_Promo = value; }
	}
	//ip地址
	public string m_Ip;
	public string Ip
	{
		get { return m_Ip;}
		set { m_Ip = value; }
	}
	//端口
	public int m_Port;
	public int Port
	{
		get { return m_Port;}
		set { m_Port = value; }
	}


};
//公会信息封装类
[System.Serializable]
public class GuildInfoWraper
{

	//构造函数
	public GuildInfoWraper()
	{
		 m_Guid = 0;
		 m_GuildName = "";
		 m_GuildLeader = "";
		 m_GuildLevel = -1;
		 m_MemberCount = -1;
		 m_OnlineCount = -1;
		 m_GuildProsper = -1;
		 m_GuildMoney = -1;
		 m_GuildResource = -1;
		 m_GuildCreed = "";
		 m_Flag = new GuildFlagWraper();
		m_News = new List<GuildNewsWraper>();
		 m_IsAutoJoin = false;
		 m_GuildOldName = "";
		 m_GuildCreater = "";
		 m_SelfOffice = -1;
		 m_TotalCount = -1;
		 m_IsVacation = false;
		 m_HaveApplied = false;
		 m_MaintainCost = -1;
		 m_GuildWelfare = -1;
		 m_LeaderGuid = 0;
		 m_CampEndTime = 0;
		 m_Guildcamp = 2;
		 m_GuildShortName = "";
		 m_GuildShortColorID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_GuildName = "";
		 m_GuildLeader = "";
		 m_GuildLevel = -1;
		 m_MemberCount = -1;
		 m_OnlineCount = -1;
		 m_GuildProsper = -1;
		 m_GuildMoney = -1;
		 m_GuildResource = -1;
		 m_GuildCreed = "";
		 m_Flag = new GuildFlagWraper();
		m_News = new List<GuildNewsWraper>();
		 m_IsAutoJoin = false;
		 m_GuildOldName = "";
		 m_GuildCreater = "";
		 m_SelfOffice = -1;
		 m_TotalCount = -1;
		 m_IsVacation = false;
		 m_HaveApplied = false;
		 m_MaintainCost = -1;
		 m_GuildWelfare = -1;
		 m_LeaderGuid = 0;
		 m_CampEndTime = 0;
		 m_Guildcamp = 2;
		 m_GuildShortName = "";
		 m_GuildShortColorID = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildInfo ToPB()
	{
		GuildInfo v = new GuildInfo();
		v.Guid = m_Guid;
		v.GuildName = m_GuildName;
		v.GuildLeader = m_GuildLeader;
		v.GuildLevel = m_GuildLevel;
		v.MemberCount = m_MemberCount;
		v.OnlineCount = m_OnlineCount;
		v.GuildProsper = m_GuildProsper;
		v.GuildMoney = m_GuildMoney;
		v.GuildResource = m_GuildResource;
		v.GuildCreed = m_GuildCreed;
		v.Flag = m_Flag.ToPB();
		for (int i=0; i<(int)m_News.Count; i++)
			v.News.Add( m_News[i].ToPB());
		v.IsAutoJoin = m_IsAutoJoin;
		v.GuildOldName = m_GuildOldName;
		v.GuildCreater = m_GuildCreater;
		v.SelfOffice = m_SelfOffice;
		v.TotalCount = m_TotalCount;
		v.IsVacation = m_IsVacation;
		v.HaveApplied = m_HaveApplied;
		v.MaintainCost = m_MaintainCost;
		v.GuildWelfare = m_GuildWelfare;
		v.LeaderGuid = m_LeaderGuid;
		v.CampEndTime = m_CampEndTime;
		v.Guildcamp = m_Guildcamp;
		v.GuildShortName = m_GuildShortName;
		v.GuildShortColorID = m_GuildShortColorID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildInfo v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_GuildName = v.GuildName;
		m_GuildLeader = v.GuildLeader;
		m_GuildLevel = v.GuildLevel;
		m_MemberCount = v.MemberCount;
		m_OnlineCount = v.OnlineCount;
		m_GuildProsper = v.GuildProsper;
		m_GuildMoney = v.GuildMoney;
		m_GuildResource = v.GuildResource;
		m_GuildCreed = v.GuildCreed;
		m_Flag.FromPB(v.Flag);
		m_News.Clear();
		for( int i=0; i<v.News.Count; i++)
			m_News.Add( new GuildNewsWraper());
		for( int i=0; i<v.News.Count; i++)
			m_News[i].FromPB(v.News[i]);
		m_IsAutoJoin = v.IsAutoJoin;
		m_GuildOldName = v.GuildOldName;
		m_GuildCreater = v.GuildCreater;
		m_SelfOffice = v.SelfOffice;
		m_TotalCount = v.TotalCount;
		m_IsVacation = v.IsVacation;
		m_HaveApplied = v.HaveApplied;
		m_MaintainCost = v.MaintainCost;
		m_GuildWelfare = v.GuildWelfare;
		m_LeaderGuid = v.LeaderGuid;
		m_CampEndTime = v.CampEndTime;
		m_Guildcamp = v.Guildcamp;
		m_GuildShortName = v.GuildShortName;
		m_GuildShortColorID = v.GuildShortColorID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildInfo pb = ProtoBuf.Serializer.Deserialize<GuildInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//公会名称
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//公会会长
	public string m_GuildLeader;
	public string GuildLeader
	{
		get { return m_GuildLeader;}
		set { m_GuildLeader = value; }
	}
	//公会等级
	public int m_GuildLevel;
	public int GuildLevel
	{
		get { return m_GuildLevel;}
		set { m_GuildLevel = value; }
	}
	//成员数量
	public int m_MemberCount;
	public int MemberCount
	{
		get { return m_MemberCount;}
		set { m_MemberCount = value; }
	}
	//在线人数
	public int m_OnlineCount;
	public int OnlineCount
	{
		get { return m_OnlineCount;}
		set { m_OnlineCount = value; }
	}
	//公会繁荣度
	public int m_GuildProsper;
	public int GuildProsper
	{
		get { return m_GuildProsper;}
		set { m_GuildProsper = value; }
	}
	//公会资金
	public int m_GuildMoney;
	public int GuildMoney
	{
		get { return m_GuildMoney;}
		set { m_GuildMoney = value; }
	}
	//公会资源
	public int m_GuildResource;
	public int GuildResource
	{
		get { return m_GuildResource;}
		set { m_GuildResource = value; }
	}
	//公会宗旨
	public string m_GuildCreed;
	public string GuildCreed
	{
		get { return m_GuildCreed;}
		set { m_GuildCreed = value; }
	}
	//公会旗帜
	public GuildFlagWraper m_Flag;
	public GuildFlagWraper Flag
	{
		get { return m_Flag;}
		set { m_Flag = value; }
	}
	//公会新闻
	public List<GuildNewsWraper> m_News;
	public int SizeNews()
	{
		return m_News.Count;
	}
	public List<GuildNewsWraper> GetNews()
	{
		return m_News;
	}
	public GuildNewsWraper GetNews(int Index)
	{
		if(Index<0 || Index>=(int)m_News.Count)
			return new GuildNewsWraper();
		return m_News[Index];
	}
	public void SetNews( List<GuildNewsWraper> v )
	{
		m_News=v;
	}
	public void SetNews( int Index, GuildNewsWraper v )
	{
		if(Index<0 || Index>=(int)m_News.Count)
			return;
		m_News[Index] = v;
	}
	public void AddNews( GuildNewsWraper v )
	{
		m_News.Add(v);
	}
	public void ClearNews( )
	{
		m_News.Clear();
	}
	//是否允许自动入会
	public bool m_IsAutoJoin;
	public bool IsAutoJoin
	{
		get { return m_IsAutoJoin;}
		set { m_IsAutoJoin = value; }
	}
	//公会曾用名
	public string m_GuildOldName;
	public string GuildOldName
	{
		get { return m_GuildOldName;}
		set { m_GuildOldName = value; }
	}
	//公会创始人
	public string m_GuildCreater;
	public string GuildCreater
	{
		get { return m_GuildCreater;}
		set { m_GuildCreater = value; }
	}
	//自己的公会职位
	public int m_SelfOffice;
	public int SelfOffice
	{
		get { return m_SelfOffice;}
		set { m_SelfOffice = value; }
	}
	//公会目前可容纳人员总数
	public int m_TotalCount;
	public int TotalCount
	{
		get { return m_TotalCount;}
		set { m_TotalCount = value; }
	}
	//是否请假
	public bool m_IsVacation;
	public bool IsVacation
	{
		get { return m_IsVacation;}
		set { m_IsVacation = value; }
	}
	//是否已申请
	public bool m_HaveApplied;
	public bool HaveApplied
	{
		get { return m_HaveApplied;}
		set { m_HaveApplied = value; }
	}
	//维护费用
	public int m_MaintainCost;
	public int MaintainCost
	{
		get { return m_MaintainCost;}
		set { m_MaintainCost = value; }
	}
	//公会福利
	public int m_GuildWelfare;
	public int GuildWelfare
	{
		get { return m_GuildWelfare;}
		set { m_GuildWelfare = value; }
	}
	//会长guid
	public UInt64 m_LeaderGuid;
	public UInt64 LeaderGuid
	{
		get { return m_LeaderGuid;}
		set { m_LeaderGuid = value; }
	}
	//阵营转换结束时间
	public UInt64 m_CampEndTime;
	public UInt64 CampEndTime
	{
		get { return m_CampEndTime;}
		set { m_CampEndTime = value; }
	}
	//公会阵营(2中立 4神圣 5自由)
	public int m_Guildcamp;
	public int Guildcamp
	{
		get { return m_Guildcamp;}
		set { m_Guildcamp = value; }
	}
	//公会简称
	public string m_GuildShortName;
	public string GuildShortName
	{
		get { return m_GuildShortName;}
		set { m_GuildShortName = value; }
	}
	//公会简称颜色
	public int m_GuildShortColorID;
	public int GuildShortColorID
	{
		get { return m_GuildShortColorID;}
		set { m_GuildShortColorID = value; }
	}


};
//公会旗帜封装类
[System.Serializable]
public class GuildFlagWraper
{

	//构造函数
	public GuildFlagWraper()
	{
		 m_FlagEquiped = -1;
		m_FlagUnlocked = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FlagEquiped = -1;
		m_FlagUnlocked = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public GuildFlag ToPB()
	{
		GuildFlag v = new GuildFlag();
		v.FlagEquiped = m_FlagEquiped;
		for (int i=0; i<(int)m_FlagUnlocked.Count; i++)
			v.FlagUnlocked.Add( m_FlagUnlocked[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildFlag v)
	{
        if (v == null)
            return;
		m_FlagEquiped = v.FlagEquiped;
		m_FlagUnlocked.Clear();
		for( int i=0; i<v.FlagUnlocked.Count; i++)
			m_FlagUnlocked.Add(v.FlagUnlocked[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildFlag>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildFlag pb = ProtoBuf.Serializer.Deserialize<GuildFlag>(protoMS);
		FromPB(pb);
		return true;
	}

	//显示的旗帜
	public int m_FlagEquiped;
	public int FlagEquiped
	{
		get { return m_FlagEquiped;}
		set { m_FlagEquiped = value; }
	}
	//已解锁的旗帜
	public List<int> m_FlagUnlocked;
	public int SizeFlagUnlocked()
	{
		return m_FlagUnlocked.Count;
	}
	public List<int> GetFlagUnlocked()
	{
		return m_FlagUnlocked;
	}
	public int GetFlagUnlocked(int Index)
	{
		if(Index<0 || Index>=(int)m_FlagUnlocked.Count)
			return -1;
		return m_FlagUnlocked[Index];
	}
	public void SetFlagUnlocked( List<int> v )
	{
		m_FlagUnlocked=v;
	}
	public void SetFlagUnlocked( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_FlagUnlocked.Count)
			return;
		m_FlagUnlocked[Index] = v;
	}
	public void AddFlagUnlocked( int v=-1 )
	{
		m_FlagUnlocked.Add(v);
	}
	public void ClearFlagUnlocked( )
	{
		m_FlagUnlocked.Clear();
	}


};
//公会新闻封装类
[System.Serializable]
public class GuildNewsWraper
{

	//构造函数
	public GuildNewsWraper()
	{
		 m_OptionType = -1;
		m_EventsParm = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OptionType = -1;
		m_EventsParm = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public GuildNews ToPB()
	{
		GuildNews v = new GuildNews();
		v.OptionType = m_OptionType;
		for (int i=0; i<(int)m_EventsParm.Count; i++)
			v.EventsParm.Add( m_EventsParm[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildNews v)
	{
        if (v == null)
            return;
		m_OptionType = v.OptionType;
		m_EventsParm.Clear();
		for( int i=0; i<v.EventsParm.Count; i++)
			m_EventsParm.Add(v.EventsParm[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildNews>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildNews pb = ProtoBuf.Serializer.Deserialize<GuildNews>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会新闻类型
	public int m_OptionType;
	public int OptionType
	{
		get { return m_OptionType;}
		set { m_OptionType = value; }
	}
	//事件参数
	public List<string> m_EventsParm;
	public int SizeEventsParm()
	{
		return m_EventsParm.Count;
	}
	public List<string> GetEventsParm()
	{
		return m_EventsParm;
	}
	public string GetEventsParm(int Index)
	{
		if(Index<0 || Index>=(int)m_EventsParm.Count)
			return "";
		return m_EventsParm[Index];
	}
	public void SetEventsParm( List<string> v )
	{
		m_EventsParm=v;
	}
	public void SetEventsParm( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_EventsParm.Count)
			return;
		m_EventsParm[Index] = v;
	}
	public void AddEventsParm( string v )
	{
		m_EventsParm.Add(v);
	}
	public void ClearEventsParm( )
	{
		m_EventsParm.Clear();
	}


};
//申请入公会玩家简要信息封装类
[System.Serializable]
public class GuildMemberTinyInfoWraper
{

	//构造函数
	public GuildMemberTinyInfoWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_Occupition = -1;
		 m_Level = -1;
		 m_FightScore = -1;
		 m_TotalContribute = -1;
		 m_RoleConfigID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_Occupition = -1;
		 m_Level = -1;
		 m_FightScore = -1;
		 m_TotalContribute = -1;
		 m_RoleConfigID = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildMemberTinyInfo ToPB()
	{
		GuildMemberTinyInfo v = new GuildMemberTinyInfo();
		v.Guid = m_Guid;
		v.PlayerName = m_PlayerName;
		v.Occupition = m_Occupition;
		v.Level = m_Level;
		v.FightScore = m_FightScore;
		v.TotalContribute = m_TotalContribute;
		v.RoleConfigID = m_RoleConfigID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildMemberTinyInfo v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_PlayerName = v.PlayerName;
		m_Occupition = v.Occupition;
		m_Level = v.Level;
		m_FightScore = v.FightScore;
		m_TotalContribute = v.TotalContribute;
		m_RoleConfigID = v.RoleConfigID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildMemberTinyInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildMemberTinyInfo pb = ProtoBuf.Serializer.Deserialize<GuildMemberTinyInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//玩家名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}
	//职业
	public int m_Occupition;
	public int Occupition
	{
		get { return m_Occupition;}
		set { m_Occupition = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//战力
	public int m_FightScore;
	public int FightScore
	{
		get { return m_FightScore;}
		set { m_FightScore = value; }
	}
	//玩家总帮贡
	public int m_TotalContribute;
	public int TotalContribute
	{
		get { return m_TotalContribute;}
		set { m_TotalContribute = value; }
	}
	//角色configid
	public int m_RoleConfigID;
	public int RoleConfigID
	{
		get { return m_RoleConfigID;}
		set { m_RoleConfigID = value; }
	}


};
//帮会成员信息封装类
[System.Serializable]
public class GuildMemberInfoWraper
{

	//构造函数
	public GuildMemberInfoWraper()
	{
		 m_OfficeType = -1;
		 m_WeekContribute = -1;
		 m_HistoryContribute = -1;
		 m_TotalContribute = -1;
		 m_WeekQuestCount = -1;
		 m_WeekCampCount = -1;
		 m_InTime = -1;
		 m_GuildTinyInfo = new GuildMemberTinyInfoWraper();
		 m_LeaveTime = 0;
		 m_IsVacation = false;
		 m_IsForbiddenChat = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OfficeType = -1;
		 m_WeekContribute = -1;
		 m_HistoryContribute = -1;
		 m_TotalContribute = -1;
		 m_WeekQuestCount = -1;
		 m_WeekCampCount = -1;
		 m_InTime = -1;
		 m_GuildTinyInfo = new GuildMemberTinyInfoWraper();
		 m_LeaveTime = 0;
		 m_IsVacation = false;
		 m_IsForbiddenChat = false;

	}

 	//转化成Protobuffer类型函数
	public GuildMemberInfo ToPB()
	{
		GuildMemberInfo v = new GuildMemberInfo();
		v.OfficeType = m_OfficeType;
		v.WeekContribute = m_WeekContribute;
		v.HistoryContribute = m_HistoryContribute;
		v.TotalContribute = m_TotalContribute;
		v.WeekQuestCount = m_WeekQuestCount;
		v.WeekCampCount = m_WeekCampCount;
		v.InTime = m_InTime;
		v.GuildTinyInfo = m_GuildTinyInfo.ToPB();
		v.LeaveTime = m_LeaveTime;
		v.IsVacation = m_IsVacation;
		v.IsForbiddenChat = m_IsForbiddenChat;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildMemberInfo v)
	{
        if (v == null)
            return;
		m_OfficeType = v.OfficeType;
		m_WeekContribute = v.WeekContribute;
		m_HistoryContribute = v.HistoryContribute;
		m_TotalContribute = v.TotalContribute;
		m_WeekQuestCount = v.WeekQuestCount;
		m_WeekCampCount = v.WeekCampCount;
		m_InTime = v.InTime;
		m_GuildTinyInfo.FromPB(v.GuildTinyInfo);
		m_LeaveTime = v.LeaveTime;
		m_IsVacation = v.IsVacation;
		m_IsForbiddenChat = v.IsForbiddenChat;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildMemberInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildMemberInfo pb = ProtoBuf.Serializer.Deserialize<GuildMemberInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//职务
	public int m_OfficeType;
	public int OfficeType
	{
		get { return m_OfficeType;}
		set { m_OfficeType = value; }
	}
	//本周帮贡
	public int m_WeekContribute;
	public int WeekContribute
	{
		get { return m_WeekContribute;}
		set { m_WeekContribute = value; }
	}
	//历史帮贡
	public int m_HistoryContribute;
	public int HistoryContribute
	{
		get { return m_HistoryContribute;}
		set { m_HistoryContribute = value; }
	}
	//总帮贡
	public int m_TotalContribute;
	public int TotalContribute
	{
		get { return m_TotalContribute;}
		set { m_TotalContribute = value; }
	}
	//本周内政
	public int m_WeekQuestCount;
	public int WeekQuestCount
	{
		get { return m_WeekQuestCount;}
		set { m_WeekQuestCount = value; }
	}
	//本周内政
	public int m_WeekCampCount;
	public int WeekCampCount
	{
		get { return m_WeekCampCount;}
		set { m_WeekCampCount = value; }
	}
	//入会时间
	public Int64 m_InTime;
	public Int64 InTime
	{
		get { return m_InTime;}
		set { m_InTime = value; }
	}
	//成员简要信息
	public GuildMemberTinyInfoWraper m_GuildTinyInfo;
	public GuildMemberTinyInfoWraper GuildTinyInfo
	{
		get { return m_GuildTinyInfo;}
		set { m_GuildTinyInfo = value; }
	}
	//离线时间
	public UInt64 m_LeaveTime;
	public UInt64 LeaveTime
	{
		get { return m_LeaveTime;}
		set { m_LeaveTime = value; }
	}
	//是否请假
	public bool m_IsVacation;
	public bool IsVacation
	{
		get { return m_IsVacation;}
		set { m_IsVacation = value; }
	}
	//是否被禁言
	public bool m_IsForbiddenChat;
	public bool IsForbiddenChat
	{
		get { return m_IsForbiddenChat;}
		set { m_IsForbiddenChat = value; }
	}


};
//公会权限封装类
[System.Serializable]
public class GuildJurisdictionWraper
{

	//构造函数
	public GuildJurisdictionWraper()
	{
		 m_ConfigID = -1;
		 m_CurState = false;
		 m_IsCanSet = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfigID = -1;
		 m_CurState = false;
		 m_IsCanSet = false;

	}

 	//转化成Protobuffer类型函数
	public GuildJurisdiction ToPB()
	{
		GuildJurisdiction v = new GuildJurisdiction();
		v.ConfigID = m_ConfigID;
		v.CurState = m_CurState;
		v.IsCanSet = m_IsCanSet;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildJurisdiction v)
	{
        if (v == null)
            return;
		m_ConfigID = v.ConfigID;
		m_CurState = v.CurState;
		m_IsCanSet = v.IsCanSet;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildJurisdiction>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildJurisdiction pb = ProtoBuf.Serializer.Deserialize<GuildJurisdiction>(protoMS);
		FromPB(pb);
		return true;
	}

	//权限id
	public int m_ConfigID;
	public int ConfigID
	{
		get { return m_ConfigID;}
		set { m_ConfigID = value; }
	}
	//当前状态
	public bool m_CurState;
	public bool CurState
	{
		get { return m_CurState;}
		set { m_CurState = value; }
	}
	//是否可被操作
	public bool m_IsCanSet;
	public bool IsCanSet
	{
		get { return m_IsCanSet;}
		set { m_IsCanSet = value; }
	}


};
//职业权限封装类
[System.Serializable]
public class GuildOfficeJurisdictionWraper
{

	//构造函数
	public GuildOfficeJurisdictionWraper()
	{
		 m_OfficeType = -1;
		m_JurisdictionList = new List<GuildJurisdictionWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OfficeType = -1;
		m_JurisdictionList = new List<GuildJurisdictionWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildOfficeJurisdiction ToPB()
	{
		GuildOfficeJurisdiction v = new GuildOfficeJurisdiction();
		v.OfficeType = m_OfficeType;
		for (int i=0; i<(int)m_JurisdictionList.Count; i++)
			v.JurisdictionList.Add( m_JurisdictionList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildOfficeJurisdiction v)
	{
        if (v == null)
            return;
		m_OfficeType = v.OfficeType;
		m_JurisdictionList.Clear();
		for( int i=0; i<v.JurisdictionList.Count; i++)
			m_JurisdictionList.Add( new GuildJurisdictionWraper());
		for( int i=0; i<v.JurisdictionList.Count; i++)
			m_JurisdictionList[i].FromPB(v.JurisdictionList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildOfficeJurisdiction>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildOfficeJurisdiction pb = ProtoBuf.Serializer.Deserialize<GuildOfficeJurisdiction>(protoMS);
		FromPB(pb);
		return true;
	}

	//职位枚举
	public int m_OfficeType;
	public int OfficeType
	{
		get { return m_OfficeType;}
		set { m_OfficeType = value; }
	}
	//权力列表
	public List<GuildJurisdictionWraper> m_JurisdictionList;
	public int SizeJurisdictionList()
	{
		return m_JurisdictionList.Count;
	}
	public List<GuildJurisdictionWraper> GetJurisdictionList()
	{
		return m_JurisdictionList;
	}
	public GuildJurisdictionWraper GetJurisdictionList(int Index)
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.Count)
			return new GuildJurisdictionWraper();
		return m_JurisdictionList[Index];
	}
	public void SetJurisdictionList( List<GuildJurisdictionWraper> v )
	{
		m_JurisdictionList=v;
	}
	public void SetJurisdictionList( int Index, GuildJurisdictionWraper v )
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.Count)
			return;
		m_JurisdictionList[Index] = v;
	}
	public void AddJurisdictionList( GuildJurisdictionWraper v )
	{
		m_JurisdictionList.Add(v);
	}
	public void ClearJurisdictionList( )
	{
		m_JurisdictionList.Clear();
	}


};
//请假信息封装类
[System.Serializable]
public class GuildVacationInfoWraper
{

	//构造函数
	public GuildVacationInfoWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_Level = -1;
		 m_Reason = "";
		 m_LeftTime = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_Level = -1;
		 m_Reason = "";
		 m_LeftTime = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildVacationInfo ToPB()
	{
		GuildVacationInfo v = new GuildVacationInfo();
		v.Guid = m_Guid;
		v.PlayerName = m_PlayerName;
		v.Level = m_Level;
		v.Reason = m_Reason;
		v.LeftTime = m_LeftTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildVacationInfo v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_PlayerName = v.PlayerName;
		m_Level = v.Level;
		m_Reason = v.Reason;
		m_LeftTime = v.LeftTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildVacationInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildVacationInfo pb = ProtoBuf.Serializer.Deserialize<GuildVacationInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//玩家名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//请假理由
	public string m_Reason;
	public string Reason
	{
		get { return m_Reason;}
		set { m_Reason = value; }
	}
	//审批倒计时
	public UInt64 m_LeftTime;
	public UInt64 LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}


};
//公会建筑信息封装类
[System.Serializable]
public class GuildBuildingInfoWraper
{

	//构造函数
	public GuildBuildingInfoWraper()
	{
		 m_BuildingType = -1;
		 m_BuildingLv = -1;
		 m_LeftTime = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuildingType = -1;
		 m_BuildingLv = -1;
		 m_LeftTime = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildBuildingInfo ToPB()
	{
		GuildBuildingInfo v = new GuildBuildingInfo();
		v.BuildingType = m_BuildingType;
		v.BuildingLv = m_BuildingLv;
		v.LeftTime = m_LeftTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildBuildingInfo v)
	{
        if (v == null)
            return;
		m_BuildingType = v.BuildingType;
		m_BuildingLv = v.BuildingLv;
		m_LeftTime = v.LeftTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildBuildingInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildBuildingInfo pb = ProtoBuf.Serializer.Deserialize<GuildBuildingInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//建筑类型
	public int m_BuildingType;
	public int BuildingType
	{
		get { return m_BuildingType;}
		set { m_BuildingType = value; }
	}
	//建筑等级
	public int m_BuildingLv;
	public int BuildingLv
	{
		get { return m_BuildingLv;}
		set { m_BuildingLv = value; }
	}
	//升级剩余时间
	public UInt64 m_LeftTime;
	public UInt64 LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}


};
//公会建筑贡献信息封装类
[System.Serializable]
public class GuildBuildingContributionInfoWraper
{

	//构造函数
	public GuildBuildingContributionInfoWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_SpeedTime = -1;
		 m_Date = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_PlayerName = "";
		 m_SpeedTime = -1;
		 m_Date = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildBuildingContributionInfo ToPB()
	{
		GuildBuildingContributionInfo v = new GuildBuildingContributionInfo();
		v.Guid = m_Guid;
		v.PlayerName = m_PlayerName;
		v.SpeedTime = m_SpeedTime;
		v.Date = m_Date;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildBuildingContributionInfo v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_PlayerName = v.PlayerName;
		m_SpeedTime = v.SpeedTime;
		m_Date = v.Date;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildBuildingContributionInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildBuildingContributionInfo pb = ProtoBuf.Serializer.Deserialize<GuildBuildingContributionInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//玩家名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}
	//加速时长
	public int m_SpeedTime;
	public int SpeedTime
	{
		get { return m_SpeedTime;}
		set { m_SpeedTime = value; }
	}
	//加速日期
	public UInt64 m_Date;
	public UInt64 Date
	{
		get { return m_Date;}
		set { m_Date = value; }
	}


};
//公会事件封装类
[System.Serializable]
public class GuildEventWraper
{

	//构造函数
	public GuildEventWraper()
	{
		 m_Guid = 0;
		 m_Date = 0;
		 m_OptionType = -1;
		m_EventsParm = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_Date = 0;
		 m_OptionType = -1;
		m_EventsParm = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public GuildEvent ToPB()
	{
		GuildEvent v = new GuildEvent();
		v.Guid = m_Guid;
		v.Date = m_Date;
		v.OptionType = m_OptionType;
		for (int i=0; i<(int)m_EventsParm.Count; i++)
			v.EventsParm.Add( m_EventsParm[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildEvent v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Date = v.Date;
		m_OptionType = v.OptionType;
		m_EventsParm.Clear();
		for( int i=0; i<v.EventsParm.Count; i++)
			m_EventsParm.Add(v.EventsParm[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildEvent>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildEvent pb = ProtoBuf.Serializer.Deserialize<GuildEvent>(protoMS);
		FromPB(pb);
		return true;
	}

	//guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//加速日期
	public UInt64 m_Date;
	public UInt64 Date
	{
		get { return m_Date;}
		set { m_Date = value; }
	}
	//公会新闻类型
	public int m_OptionType;
	public int OptionType
	{
		get { return m_OptionType;}
		set { m_OptionType = value; }
	}
	//事件参数
	public List<string> m_EventsParm;
	public int SizeEventsParm()
	{
		return m_EventsParm.Count;
	}
	public List<string> GetEventsParm()
	{
		return m_EventsParm;
	}
	public string GetEventsParm(int Index)
	{
		if(Index<0 || Index>=(int)m_EventsParm.Count)
			return "";
		return m_EventsParm[Index];
	}
	public void SetEventsParm( List<string> v )
	{
		m_EventsParm=v;
	}
	public void SetEventsParm( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_EventsParm.Count)
			return;
		m_EventsParm[Index] = v;
	}
	public void AddEventsParm( string v )
	{
		m_EventsParm.Add(v);
	}
	public void ClearEventsParm( )
	{
		m_EventsParm.Clear();
	}


};
//匹配出来的房间封装类
[System.Serializable]
public class PBMatchRoomWraper
{

	//构造函数
	public PBMatchRoomWraper()
	{
		m_Camps = new List<MatchRoomCampsWraper>();
		 m_MatchTarget = new MatchTargetInfoWraper();
		 m_RoomId = 0;
		 m_MatchType = -1;
		 m_EndTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Camps = new List<MatchRoomCampsWraper>();
		 m_MatchTarget = new MatchTargetInfoWraper();
		 m_RoomId = 0;
		 m_MatchType = -1;
		 m_EndTime = -1;

	}

 	//转化成Protobuffer类型函数
	public PBMatchRoom ToPB()
	{
		PBMatchRoom v = new PBMatchRoom();
		for (int i=0; i<(int)m_Camps.Count; i++)
			v.Camps.Add( m_Camps[i].ToPB());
		v.MatchTarget = m_MatchTarget.ToPB();
		v.RoomId = m_RoomId;
		v.MatchType = m_MatchType;
		v.EndTime = m_EndTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PBMatchRoom v)
	{
        if (v == null)
            return;
		m_Camps.Clear();
		for( int i=0; i<v.Camps.Count; i++)
			m_Camps.Add( new MatchRoomCampsWraper());
		for( int i=0; i<v.Camps.Count; i++)
			m_Camps[i].FromPB(v.Camps[i]);
		m_MatchTarget.FromPB(v.MatchTarget);
		m_RoomId = v.RoomId;
		m_MatchType = v.MatchType;
		m_EndTime = v.EndTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PBMatchRoom>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PBMatchRoom pb = ProtoBuf.Serializer.Deserialize<PBMatchRoom>(protoMS);
		FromPB(pb);
		return true;
	}

	//阵营列表
	public List<MatchRoomCampsWraper> m_Camps;
	public int SizeCamps()
	{
		return m_Camps.Count;
	}
	public List<MatchRoomCampsWraper> GetCamps()
	{
		return m_Camps;
	}
	public MatchRoomCampsWraper GetCamps(int Index)
	{
		if(Index<0 || Index>=(int)m_Camps.Count)
			return new MatchRoomCampsWraper();
		return m_Camps[Index];
	}
	public void SetCamps( List<MatchRoomCampsWraper> v )
	{
		m_Camps=v;
	}
	public void SetCamps( int Index, MatchRoomCampsWraper v )
	{
		if(Index<0 || Index>=(int)m_Camps.Count)
			return;
		m_Camps[Index] = v;
	}
	public void AddCamps( MatchRoomCampsWraper v )
	{
		m_Camps.Add(v);
	}
	public void ClearCamps( )
	{
		m_Camps.Clear();
	}
	//匹配目标
	public MatchTargetInfoWraper m_MatchTarget;
	public MatchTargetInfoWraper MatchTarget
	{
		get { return m_MatchTarget;}
		set { m_MatchTarget = value; }
	}
	//匹配的房间id
	public UInt64 m_RoomId;
	public UInt64 RoomId
	{
		get { return m_RoomId;}
		set { m_RoomId = value; }
	}
	//匹配类型
	public int m_MatchType;
	public int MatchType
	{
		get { return m_MatchType;}
		set { m_MatchType = value; }
	}
	//EndTime
	public Int64 m_EndTime;
	public Int64 EndTime
	{
		get { return m_EndTime;}
		set { m_EndTime = value; }
	}


};
//匹配房间的阵营列表封装类
[System.Serializable]
public class MatchRoomCampsWraper
{

	//构造函数
	public MatchRoomCampsWraper()
	{
		m_Players = new List<MatchInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Players = new List<MatchInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public MatchRoomCamps ToPB()
	{
		MatchRoomCamps v = new MatchRoomCamps();
		for (int i=0; i<(int)m_Players.Count; i++)
			v.Players.Add( m_Players[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRoomCamps v)
	{
        if (v == null)
            return;
		m_Players.Clear();
		for( int i=0; i<v.Players.Count; i++)
			m_Players.Add( new MatchInfoWraper());
		for( int i=0; i<v.Players.Count; i++)
			m_Players[i].FromPB(v.Players[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRoomCamps>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRoomCamps pb = ProtoBuf.Serializer.Deserialize<MatchRoomCamps>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家
	public List<MatchInfoWraper> m_Players;
	public int SizePlayers()
	{
		return m_Players.Count;
	}
	public List<MatchInfoWraper> GetPlayers()
	{
		return m_Players;
	}
	public MatchInfoWraper GetPlayers(int Index)
	{
		if(Index<0 || Index>=(int)m_Players.Count)
			return new MatchInfoWraper();
		return m_Players[Index];
	}
	public void SetPlayers( List<MatchInfoWraper> v )
	{
		m_Players=v;
	}
	public void SetPlayers( int Index, MatchInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Players.Count)
			return;
		m_Players[Index] = v;
	}
	public void AddPlayers( MatchInfoWraper v )
	{
		m_Players.Add(v);
	}
	public void ClearPlayers( )
	{
		m_Players.Clear();
	}


};
//玩家匹配信息封装类
[System.Serializable]
public class PlayerMatchDataWraper
{

	//构造函数
	public PlayerMatchDataWraper()
	{
		 m_MatchType = 0;
		 m_Elo = 0;
		 m_Auto = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MatchType = 0;
		 m_Elo = 0;
		 m_Auto = 0;

	}

 	//转化成Protobuffer类型函数
	public PlayerMatchData ToPB()
	{
		PlayerMatchData v = new PlayerMatchData();
		v.MatchType = m_MatchType;
		v.Elo = m_Elo;
		v.Auto = m_Auto;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PlayerMatchData v)
	{
        if (v == null)
            return;
		m_MatchType = v.MatchType;
		m_Elo = v.Elo;
		m_Auto = v.Auto;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PlayerMatchData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PlayerMatchData pb = ProtoBuf.Serializer.Deserialize<PlayerMatchData>(protoMS);
		FromPB(pb);
		return true;
	}

	//匹配类型
	public int m_MatchType;
	public int MatchType
	{
		get { return m_MatchType;}
		set { m_MatchType = value; }
	}
	//匹配elo
	public int m_Elo;
	public int Elo
	{
		get { return m_Elo;}
		set { m_Elo = value; }
	}
	//是否自动匹配
	public int m_Auto;
	public int Auto
	{
		get { return m_Auto;}
		set { m_Auto = value; }
	}


};
//完成任务id封装类
[System.Serializable]
public class MaxQuestCompleteIdWraper
{

	//构造函数
	public MaxQuestCompleteIdWraper()
	{
		 m_QuestType = -1;
		 m_MaxConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestType = -1;
		 m_MaxConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public MaxQuestCompleteId ToPB()
	{
		MaxQuestCompleteId v = new MaxQuestCompleteId();
		v.QuestType = m_QuestType;
		v.MaxConfigId = m_MaxConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MaxQuestCompleteId v)
	{
        if (v == null)
            return;
		m_QuestType = v.QuestType;
		m_MaxConfigId = v.MaxConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MaxQuestCompleteId>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MaxQuestCompleteId pb = ProtoBuf.Serializer.Deserialize<MaxQuestCompleteId>(protoMS);
		FromPB(pb);
		return true;
	}

	//任务类型
	public int m_QuestType;
	public int QuestType
	{
		get { return m_QuestType;}
		set { m_QuestType = value; }
	}
	//最大任务id
	public int m_MaxConfigId;
	public int MaxConfigId
	{
		get { return m_MaxConfigId;}
		set { m_MaxConfigId = value; }
	}


};
//最大任务列表封装类
[System.Serializable]
public class QuestMaxQuestListWraper
{

	//构造函数
	public QuestMaxQuestListWraper()
	{
		m_QuestList = new List<CompletedQuestListWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_QuestList = new List<CompletedQuestListWraper>();

	}

 	//转化成Protobuffer类型函数
	public QuestMaxQuestList ToPB()
	{
		QuestMaxQuestList v = new QuestMaxQuestList();
		for (int i=0; i<(int)m_QuestList.Count; i++)
			v.QuestList.Add( m_QuestList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(QuestMaxQuestList v)
	{
        if (v == null)
            return;
		m_QuestList.Clear();
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList.Add( new CompletedQuestListWraper());
		for( int i=0; i<v.QuestList.Count; i++)
			m_QuestList[i].FromPB(v.QuestList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<QuestMaxQuestList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		QuestMaxQuestList pb = ProtoBuf.Serializer.Deserialize<QuestMaxQuestList>(protoMS);
		FromPB(pb);
		return true;
	}

	//最大任务列表
	public List<CompletedQuestListWraper> m_QuestList;
	public int SizeQuestList()
	{
		return m_QuestList.Count;
	}
	public List<CompletedQuestListWraper> GetQuestList()
	{
		return m_QuestList;
	}
	public CompletedQuestListWraper GetQuestList(int Index)
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return new CompletedQuestListWraper();
		return m_QuestList[Index];
	}
	public void SetQuestList( List<CompletedQuestListWraper> v )
	{
		m_QuestList=v;
	}
	public void SetQuestList( int Index, CompletedQuestListWraper v )
	{
		if(Index<0 || Index>=(int)m_QuestList.Count)
			return;
		m_QuestList[Index] = v;
	}
	public void AddQuestList( CompletedQuestListWraper v )
	{
		m_QuestList.Add(v);
	}
	public void ClearQuestList( )
	{
		m_QuestList.Clear();
	}


};
//场景线的状态封装类
[System.Serializable]
public class LineStatsWraper
{

	//构造函数
	public LineStatsWraper()
	{
		 m_LineId = -1;
		 m_LineStats = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LineId = -1;
		 m_LineStats = -1;

	}

 	//转化成Protobuffer类型函数
	public LineStats ToPB()
	{
		LineStats v = new LineStats();
		v.LineId = m_LineId;
		v.LineStats = m_LineStats;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LineStats v)
	{
        if (v == null)
            return;
		m_LineId = v.LineId;
		m_LineStats = v.LineStats;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LineStats>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LineStats pb = ProtoBuf.Serializer.Deserialize<LineStats>(protoMS);
		FromPB(pb);
		return true;
	}

	//线id
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
	}
	//线的状态
	public int m_LineStats;
	public int LineStats
	{
		get { return m_LineStats;}
		set { m_LineStats = value; }
	}


};
//场景状态封装类
[System.Serializable]
public class SceneStatsWraper
{

	//构造函数
	public SceneStatsWraper()
	{
		m_Lines = new List<LineStatsWraper>();
		 m_SceneId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Lines = new List<LineStatsWraper>();
		 m_SceneId = -1;

	}

 	//转化成Protobuffer类型函数
	public SceneStats ToPB()
	{
		SceneStats v = new SceneStats();
		for (int i=0; i<(int)m_Lines.Count; i++)
			v.Lines.Add( m_Lines[i].ToPB());
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SceneStats v)
	{
        if (v == null)
            return;
		m_Lines.Clear();
		for( int i=0; i<v.Lines.Count; i++)
			m_Lines.Add( new LineStatsWraper());
		for( int i=0; i<v.Lines.Count; i++)
			m_Lines[i].FromPB(v.Lines[i]);
		m_SceneId = v.SceneId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SceneStats>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SceneStats pb = ProtoBuf.Serializer.Deserialize<SceneStats>(protoMS);
		FromPB(pb);
		return true;
	}

	//场景下线的状态
	public List<LineStatsWraper> m_Lines;
	public int SizeLines()
	{
		return m_Lines.Count;
	}
	public List<LineStatsWraper> GetLines()
	{
		return m_Lines;
	}
	public LineStatsWraper GetLines(int Index)
	{
		if(Index<0 || Index>=(int)m_Lines.Count)
			return new LineStatsWraper();
		return m_Lines[Index];
	}
	public void SetLines( List<LineStatsWraper> v )
	{
		m_Lines=v;
	}
	public void SetLines( int Index, LineStatsWraper v )
	{
		if(Index<0 || Index>=(int)m_Lines.Count)
			return;
		m_Lines[Index] = v;
	}
	public void AddLines( LineStatsWraper v )
	{
		m_Lines.Add(v);
	}
	public void ClearLines( )
	{
		m_Lines.Clear();
	}
	//场景Id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
	}


};
//副本BOSS挑战信息封装类
[System.Serializable]
public class DungeonBossInfoWraper
{

	//构造函数
	public DungeonBossInfoWraper()
	{
		 m_Bossid = -1;
		 m_Number = -1;
		 m_Dungeonid = -1;
		 m_MaxNumber = -1;
		 m_RefreshType = -1;
		 m_HoldNum = 0;
		 m_Killed = 0;
		 m_DungeonType = -1;
		 m_BossIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Bossid = -1;
		 m_Number = -1;
		 m_Dungeonid = -1;
		 m_MaxNumber = -1;
		 m_RefreshType = -1;
		 m_HoldNum = 0;
		 m_Killed = 0;
		 m_DungeonType = -1;
		 m_BossIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonBossInfo ToPB()
	{
		DungeonBossInfo v = new DungeonBossInfo();
		v.Bossid = m_Bossid;
		v.Number = m_Number;
		v.Dungeonid = m_Dungeonid;
		v.MaxNumber = m_MaxNumber;
		v.RefreshType = m_RefreshType;
		v.HoldNum = m_HoldNum;
		v.Killed = m_Killed;
		v.DungeonType = m_DungeonType;
		v.BossIndex = m_BossIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonBossInfo v)
	{
        if (v == null)
            return;
		m_Bossid = v.Bossid;
		m_Number = v.Number;
		m_Dungeonid = v.Dungeonid;
		m_MaxNumber = v.MaxNumber;
		m_RefreshType = v.RefreshType;
		m_HoldNum = v.HoldNum;
		m_Killed = v.Killed;
		m_DungeonType = v.DungeonType;
		m_BossIndex = v.BossIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonBossInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonBossInfo pb = ProtoBuf.Serializer.Deserialize<DungeonBossInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//BOSSID
	public int m_Bossid;
	public int Bossid
	{
		get { return m_Bossid;}
		set { m_Bossid = value; }
	}
	//BOSS挑战次数
	public int m_Number;
	public int Number
	{
		get { return m_Number;}
		set { m_Number = value; }
	}
	//副本ID
	public int m_Dungeonid;
	public int Dungeonid
	{
		get { return m_Dungeonid;}
		set { m_Dungeonid = value; }
	}
	//挑战最大次数
	public int m_MaxNumber;
	public int MaxNumber
	{
		get { return m_MaxNumber;}
		set { m_MaxNumber = value; }
	}
	//刷新类型
	public int m_RefreshType;
	public int RefreshType
	{
		get { return m_RefreshType;}
		set { m_RefreshType = value; }
	}
	//找回次数
	public int m_HoldNum;
	public int HoldNum
	{
		get { return m_HoldNum;}
		set { m_HoldNum = value; }
	}
	//击杀标记
	public int m_Killed;
	public int Killed
	{
		get { return m_Killed;}
		set { m_Killed = value; }
	}
	//副本类型
	public int m_DungeonType;
	public int DungeonType
	{
		get { return m_DungeonType;}
		set { m_DungeonType = value; }
	}
	//BOSS次序
	public int m_BossIndex;
	public int BossIndex
	{
		get { return m_BossIndex;}
		set { m_BossIndex = value; }
	}


};
//技能位置信息封装类
[System.Serializable]
public class SkillPosInfoWraper
{

	//构造函数
	public SkillPosInfoWraper()
	{
		 m_Pos = -1;
		 m_CurLevel = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_CurLevel = -1;

	}

 	//转化成Protobuffer类型函数
	public SkillPosInfo ToPB()
	{
		SkillPosInfo v = new SkillPosInfo();
		v.Pos = m_Pos;
		v.CurLevel = m_CurLevel;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillPosInfo v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_CurLevel = v.CurLevel;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillPosInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillPosInfo pb = ProtoBuf.Serializer.Deserialize<SkillPosInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//技能位置当前等级
	public int m_CurLevel;
	public int CurLevel
	{
		get { return m_CurLevel;}
		set { m_CurLevel = value; }
	}


};
//福利奖励封装类
[System.Serializable]
public class WelfareRewardWraper
{

	//构造函数
	public WelfareRewardWraper()
	{
		 m_RewardID = -1;
		 m_RewardNum = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RewardID = -1;
		 m_RewardNum = -1;

	}

 	//转化成Protobuffer类型函数
	public WelfareReward ToPB()
	{
		WelfareReward v = new WelfareReward();
		v.RewardID = m_RewardID;
		v.RewardNum = m_RewardNum;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WelfareReward v)
	{
        if (v == null)
            return;
		m_RewardID = v.RewardID;
		m_RewardNum = v.RewardNum;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WelfareReward>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WelfareReward pb = ProtoBuf.Serializer.Deserialize<WelfareReward>(protoMS);
		FromPB(pb);
		return true;
	}

	//奖励ID
	public int m_RewardID;
	public int RewardID
	{
		get { return m_RewardID;}
		set { m_RewardID = value; }
	}
	//奖励数量
	public int m_RewardNum;
	public int RewardNum
	{
		get { return m_RewardNum;}
		set { m_RewardNum = value; }
	}


};
//累计登陆福利信息封装类
[System.Serializable]
public class AccumulateSignInfoWraper
{

	//构造函数
	public AccumulateSignInfoWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

 	//转化成Protobuffer类型函数
	public AccumulateSignInfo ToPB()
	{
		AccumulateSignInfo v = new AccumulateSignInfo();
		v.ID = m_ID;
		v.State = m_State;
		v.RewardInfo = m_RewardInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AccumulateSignInfo v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_State = v.State;
		m_RewardInfo.FromPB(v.RewardInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AccumulateSignInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AccumulateSignInfo pb = ProtoBuf.Serializer.Deserialize<AccumulateSignInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//是否已领取
	public bool m_State;
	public bool State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//奖励信息
	public WelfareRewardWraper m_RewardInfo;
	public WelfareRewardWraper RewardInfo
	{
		get { return m_RewardInfo;}
		set { m_RewardInfo = value; }
	}


};
//今日在线福利信息封装类
[System.Serializable]
public class OnlineInfoWraper
{

	//构造函数
	public OnlineInfoWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

 	//转化成Protobuffer类型函数
	public OnlineInfo ToPB()
	{
		OnlineInfo v = new OnlineInfo();
		v.ID = m_ID;
		v.State = m_State;
		v.RewardInfo = m_RewardInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(OnlineInfo v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_State = v.State;
		m_RewardInfo.FromPB(v.RewardInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<OnlineInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		OnlineInfo pb = ProtoBuf.Serializer.Deserialize<OnlineInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//是否已领取
	public bool m_State;
	public bool State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//奖励信息
	public WelfareRewardWraper m_RewardInfo;
	public WelfareRewardWraper RewardInfo
	{
		get { return m_RewardInfo;}
		set { m_RewardInfo = value; }
	}


};
//等级福利信息封装类
[System.Serializable]
public class LevelInfoWraper
{

	//构造函数
	public LevelInfoWraper()
	{
		 m_ID = -1;
		 m_State = false;
		m_RewardInfo = new List<WelfareRewardWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		 m_State = false;
		m_RewardInfo = new List<WelfareRewardWraper>();

	}

 	//转化成Protobuffer类型函数
	public LevelInfo ToPB()
	{
		LevelInfo v = new LevelInfo();
		v.ID = m_ID;
		v.State = m_State;
		for (int i=0; i<(int)m_RewardInfo.Count; i++)
			v.RewardInfo.Add( m_RewardInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LevelInfo v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_State = v.State;
		m_RewardInfo.Clear();
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo.Add( new WelfareRewardWraper());
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo[i].FromPB(v.RewardInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LevelInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LevelInfo pb = ProtoBuf.Serializer.Deserialize<LevelInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//是否已领取
	public bool m_State;
	public bool State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//奖励信息
	public List<WelfareRewardWraper> m_RewardInfo;
	public int SizeRewardInfo()
	{
		return m_RewardInfo.Count;
	}
	public List<WelfareRewardWraper> GetRewardInfo()
	{
		return m_RewardInfo;
	}
	public WelfareRewardWraper GetRewardInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardInfo.Count)
			return new WelfareRewardWraper();
		return m_RewardInfo[Index];
	}
	public void SetRewardInfo( List<WelfareRewardWraper> v )
	{
		m_RewardInfo=v;
	}
	public void SetRewardInfo( int Index, WelfareRewardWraper v )
	{
		if(Index<0 || Index>=(int)m_RewardInfo.Count)
			return;
		m_RewardInfo[Index] = v;
	}
	public void AddRewardInfo( WelfareRewardWraper v )
	{
		m_RewardInfo.Add(v);
	}
	public void ClearRewardInfo( )
	{
		m_RewardInfo.Clear();
	}


};
//签到福利信息封装类
[System.Serializable]
public class MonthSignInInfoWraper
{

	//构造函数
	public MonthSignInInfoWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		 m_State = false;
		 m_RewardInfo = new WelfareRewardWraper();

	}

 	//转化成Protobuffer类型函数
	public MonthSignInInfo ToPB()
	{
		MonthSignInInfo v = new MonthSignInInfo();
		v.ID = m_ID;
		v.State = m_State;
		v.RewardInfo = m_RewardInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MonthSignInInfo v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_State = v.State;
		m_RewardInfo.FromPB(v.RewardInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MonthSignInInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MonthSignInInfo pb = ProtoBuf.Serializer.Deserialize<MonthSignInInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//是否已领取
	public bool m_State;
	public bool State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//奖励信息
	public WelfareRewardWraper m_RewardInfo;
	public WelfareRewardWraper RewardInfo
	{
		get { return m_RewardInfo;}
		set { m_RewardInfo = value; }
	}


};
//队伍快速更新信息封装类
[System.Serializable]
public class TeamMemberQuickUpdateInfoWraper
{

	//构造函数
	public TeamMemberQuickUpdateInfoWraper()
	{
		 m_Location = new CharacterLocationWraper();
		 m_MaxMp = -1;
		 m_MaxHp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Location = new CharacterLocationWraper();
		 m_MaxMp = -1;
		 m_MaxHp = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamMemberQuickUpdateInfo ToPB()
	{
		TeamMemberQuickUpdateInfo v = new TeamMemberQuickUpdateInfo();
		v.Location = m_Location.ToPB();
		v.MaxMp = m_MaxMp;
		v.MaxHp = m_MaxHp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamMemberQuickUpdateInfo v)
	{
        if (v == null)
            return;
		m_Location.FromPB(v.Location);
		m_MaxMp = v.MaxMp;
		m_MaxHp = v.MaxHp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamMemberQuickUpdateInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamMemberQuickUpdateInfo pb = ProtoBuf.Serializer.Deserialize<TeamMemberQuickUpdateInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//Location
	public CharacterLocationWraper m_Location;
	public CharacterLocationWraper Location
	{
		get { return m_Location;}
		set { m_Location = value; }
	}
	//生命值
	public Int64 m_MaxMp;
	public Int64 MaxMp
	{
		get { return m_MaxMp;}
		set { m_MaxMp = value; }
	}
	//生命值
	public Int64 m_MaxHp;
	public Int64 MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}


};
//世界BOSS得分信息封装类
[System.Serializable]
public class WorldBossScoreInfoWraper
{

	//构造函数
	public WorldBossScoreInfoWraper()
	{
		 m_Playerguid = 0;
		 m_Level = -1;
		 m_Name = "";
		 m_Occupation = -1;
		 m_RankAll = -1;
		 m_RankOccupation = -1;
		 m_Score = -1;
		 m_Capacity = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Playerguid = 0;
		 m_Level = -1;
		 m_Name = "";
		 m_Occupation = -1;
		 m_RankAll = -1;
		 m_RankOccupation = -1;
		 m_Score = -1;
		 m_Capacity = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossScoreInfo ToPB()
	{
		WorldBossScoreInfo v = new WorldBossScoreInfo();
		v.Playerguid = m_Playerguid;
		v.Level = m_Level;
		v.Name = m_Name;
		v.Occupation = m_Occupation;
		v.RankAll = m_RankAll;
		v.RankOccupation = m_RankOccupation;
		v.Score = m_Score;
		v.Capacity = m_Capacity;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossScoreInfo v)
	{
        if (v == null)
            return;
		m_Playerguid = v.Playerguid;
		m_Level = v.Level;
		m_Name = v.Name;
		m_Occupation = v.Occupation;
		m_RankAll = v.RankAll;
		m_RankOccupation = v.RankOccupation;
		m_Score = v.Score;
		m_Capacity = v.Capacity;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossScoreInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossScoreInfo pb = ProtoBuf.Serializer.Deserialize<WorldBossScoreInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//playerguid
	public UInt64 m_Playerguid;
	public UInt64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//职业
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}
	//所有排名
	public int m_RankAll;
	public int RankAll
	{
		get { return m_RankAll;}
		set { m_RankAll = value; }
	}
	//职业排名
	public int m_RankOccupation;
	public int RankOccupation
	{
		get { return m_RankOccupation;}
		set { m_RankOccupation = value; }
	}
	//积分
	public int m_Score;
	public int Score
	{
		get { return m_Score;}
		set { m_Score = value; }
	}
	//战力
	public int m_Capacity;
	public int Capacity
	{
		get { return m_Capacity;}
		set { m_Capacity = value; }
	}


};
//世界BOSS排行榜封装类
[System.Serializable]
public class WorldBossRankWraper
{

	//构造函数
	public WorldBossRankWraper()
	{
		m_ScoreInfo = new List<WorldBossScoreInfoWraper>();
		 m_Occupation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_ScoreInfo = new List<WorldBossScoreInfoWraper>();
		 m_Occupation = -1;

	}

 	//转化成Protobuffer类型函数
	public WorldBossRank ToPB()
	{
		WorldBossRank v = new WorldBossRank();
		for (int i=0; i<(int)m_ScoreInfo.Count; i++)
			v.ScoreInfo.Add( m_ScoreInfo[i].ToPB());
		v.Occupation = m_Occupation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossRank v)
	{
        if (v == null)
            return;
		m_ScoreInfo.Clear();
		for( int i=0; i<v.ScoreInfo.Count; i++)
			m_ScoreInfo.Add( new WorldBossScoreInfoWraper());
		for( int i=0; i<v.ScoreInfo.Count; i++)
			m_ScoreInfo[i].FromPB(v.ScoreInfo[i]);
		m_Occupation = v.Occupation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossRank>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossRank pb = ProtoBuf.Serializer.Deserialize<WorldBossRank>(protoMS);
		FromPB(pb);
		return true;
	}

	//世界BOSS积分信息
	public List<WorldBossScoreInfoWraper> m_ScoreInfo;
	public int SizeScoreInfo()
	{
		return m_ScoreInfo.Count;
	}
	public List<WorldBossScoreInfoWraper> GetScoreInfo()
	{
		return m_ScoreInfo;
	}
	public WorldBossScoreInfoWraper GetScoreInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_ScoreInfo.Count)
			return new WorldBossScoreInfoWraper();
		return m_ScoreInfo[Index];
	}
	public void SetScoreInfo( List<WorldBossScoreInfoWraper> v )
	{
		m_ScoreInfo=v;
	}
	public void SetScoreInfo( int Index, WorldBossScoreInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ScoreInfo.Count)
			return;
		m_ScoreInfo[Index] = v;
	}
	public void AddScoreInfo( WorldBossScoreInfoWraper v )
	{
		m_ScoreInfo.Add(v);
	}
	public void ClearScoreInfo( )
	{
		m_ScoreInfo.Clear();
	}
	//职业类型(为0时是总排行榜)
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}


};
//宠物被动技能封装类
[System.Serializable]
public class PetSkillWraper
{

	//构造函数
	public PetSkillWraper()
	{
		 m_SkillId = -1;
		 m_Lock = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillId = -1;
		 m_Lock = -1;

	}

 	//转化成Protobuffer类型函数
	public PetSkill ToPB()
	{
		PetSkill v = new PetSkill();
		v.SkillId = m_SkillId;
		v.Lock = m_Lock;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetSkill v)
	{
        if (v == null)
            return;
		m_SkillId = v.SkillId;
		m_Lock = v.Lock;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetSkill>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetSkill pb = ProtoBuf.Serializer.Deserialize<PetSkill>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//宠物技能锁 0未加锁1加锁
	public int m_Lock;
	public int Lock
	{
		get { return m_Lock;}
		set { m_Lock = value; }
	}


};
//结算信息封装类
[System.Serializable]
public class PvpBattleEndInfoWraper
{

	//构造函数
	public PvpBattleEndInfoWraper()
	{
		 m_WinState = -1;
		 m_BeforeRank = -1;
		 m_BeforeStar = -1;
		 m_AfterRank = -1;
		 m_AfterStar = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();
		m_LeftPlayerList = new List<PvpEndPlayerWraper>();
		m_RightPlayerList = new List<PvpEndPlayerWraper>();
		 m_BattleTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_WinState = -1;
		 m_BeforeRank = -1;
		 m_BeforeStar = -1;
		 m_AfterRank = -1;
		 m_AfterStar = -1;
		m_RewardList = new List<PvpBattleRewardInfoWraper>();
		m_LeftPlayerList = new List<PvpEndPlayerWraper>();
		m_RightPlayerList = new List<PvpEndPlayerWraper>();
		 m_BattleTime = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpBattleEndInfo ToPB()
	{
		PvpBattleEndInfo v = new PvpBattleEndInfo();
		v.WinState = m_WinState;
		v.BeforeRank = m_BeforeRank;
		v.BeforeStar = m_BeforeStar;
		v.AfterRank = m_AfterRank;
		v.AfterStar = m_AfterStar;
		for (int i=0; i<(int)m_RewardList.Count; i++)
			v.RewardList.Add( m_RewardList[i].ToPB());
		for (int i=0; i<(int)m_LeftPlayerList.Count; i++)
			v.LeftPlayerList.Add( m_LeftPlayerList[i].ToPB());
		for (int i=0; i<(int)m_RightPlayerList.Count; i++)
			v.RightPlayerList.Add( m_RightPlayerList[i].ToPB());
		v.BattleTime = m_BattleTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpBattleEndInfo v)
	{
        if (v == null)
            return;
		m_WinState = v.WinState;
		m_BeforeRank = v.BeforeRank;
		m_BeforeStar = v.BeforeStar;
		m_AfterRank = v.AfterRank;
		m_AfterStar = v.AfterStar;
		m_RewardList.Clear();
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList.Add( new PvpBattleRewardInfoWraper());
		for( int i=0; i<v.RewardList.Count; i++)
			m_RewardList[i].FromPB(v.RewardList[i]);
		m_LeftPlayerList.Clear();
		for( int i=0; i<v.LeftPlayerList.Count; i++)
			m_LeftPlayerList.Add( new PvpEndPlayerWraper());
		for( int i=0; i<v.LeftPlayerList.Count; i++)
			m_LeftPlayerList[i].FromPB(v.LeftPlayerList[i]);
		m_RightPlayerList.Clear();
		for( int i=0; i<v.RightPlayerList.Count; i++)
			m_RightPlayerList.Add( new PvpEndPlayerWraper());
		for( int i=0; i<v.RightPlayerList.Count; i++)
			m_RightPlayerList[i].FromPB(v.RightPlayerList[i]);
		m_BattleTime = v.BattleTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpBattleEndInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpBattleEndInfo pb = ProtoBuf.Serializer.Deserialize<PvpBattleEndInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//输赢
	public int m_WinState;
	public int WinState
	{
		get { return m_WinState;}
		set { m_WinState = value; }
	}
	//上一次的段位
	public int m_BeforeRank;
	public int BeforeRank
	{
		get { return m_BeforeRank;}
		set { m_BeforeRank = value; }
	}
	//上一次的星级
	public int m_BeforeStar;
	public int BeforeStar
	{
		get { return m_BeforeStar;}
		set { m_BeforeStar = value; }
	}
	//当前段位
	public int m_AfterRank;
	public int AfterRank
	{
		get { return m_AfterRank;}
		set { m_AfterRank = value; }
	}
	//当前星级
	public int m_AfterStar;
	public int AfterStar
	{
		get { return m_AfterStar;}
		set { m_AfterStar = value; }
	}
	//奖励列表
	public List<PvpBattleRewardInfoWraper> m_RewardList;
	public int SizeRewardList()
	{
		return m_RewardList.Count;
	}
	public List<PvpBattleRewardInfoWraper> GetRewardList()
	{
		return m_RewardList;
	}
	public PvpBattleRewardInfoWraper GetRewardList(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return new PvpBattleRewardInfoWraper();
		return m_RewardList[Index];
	}
	public void SetRewardList( List<PvpBattleRewardInfoWraper> v )
	{
		m_RewardList=v;
	}
	public void SetRewardList( int Index, PvpBattleRewardInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_RewardList.Count)
			return;
		m_RewardList[Index] = v;
	}
	public void AddRewardList( PvpBattleRewardInfoWraper v )
	{
		m_RewardList.Add(v);
	}
	public void ClearRewardList( )
	{
		m_RewardList.Clear();
	}
	//左侧玩家列表
	public List<PvpEndPlayerWraper> m_LeftPlayerList;
	public int SizeLeftPlayerList()
	{
		return m_LeftPlayerList.Count;
	}
	public List<PvpEndPlayerWraper> GetLeftPlayerList()
	{
		return m_LeftPlayerList;
	}
	public PvpEndPlayerWraper GetLeftPlayerList(int Index)
	{
		if(Index<0 || Index>=(int)m_LeftPlayerList.Count)
			return new PvpEndPlayerWraper();
		return m_LeftPlayerList[Index];
	}
	public void SetLeftPlayerList( List<PvpEndPlayerWraper> v )
	{
		m_LeftPlayerList=v;
	}
	public void SetLeftPlayerList( int Index, PvpEndPlayerWraper v )
	{
		if(Index<0 || Index>=(int)m_LeftPlayerList.Count)
			return;
		m_LeftPlayerList[Index] = v;
	}
	public void AddLeftPlayerList( PvpEndPlayerWraper v )
	{
		m_LeftPlayerList.Add(v);
	}
	public void ClearLeftPlayerList( )
	{
		m_LeftPlayerList.Clear();
	}
	//右侧玩家列表
	public List<PvpEndPlayerWraper> m_RightPlayerList;
	public int SizeRightPlayerList()
	{
		return m_RightPlayerList.Count;
	}
	public List<PvpEndPlayerWraper> GetRightPlayerList()
	{
		return m_RightPlayerList;
	}
	public PvpEndPlayerWraper GetRightPlayerList(int Index)
	{
		if(Index<0 || Index>=(int)m_RightPlayerList.Count)
			return new PvpEndPlayerWraper();
		return m_RightPlayerList[Index];
	}
	public void SetRightPlayerList( List<PvpEndPlayerWraper> v )
	{
		m_RightPlayerList=v;
	}
	public void SetRightPlayerList( int Index, PvpEndPlayerWraper v )
	{
		if(Index<0 || Index>=(int)m_RightPlayerList.Count)
			return;
		m_RightPlayerList[Index] = v;
	}
	public void AddRightPlayerList( PvpEndPlayerWraper v )
	{
		m_RightPlayerList.Add(v);
	}
	public void ClearRightPlayerList( )
	{
		m_RightPlayerList.Clear();
	}
	//战斗时间
	public int m_BattleTime;
	public int BattleTime
	{
		get { return m_BattleTime;}
		set { m_BattleTime = value; }
	}


};
//竞技场奖励信息封装类
[System.Serializable]
public class PvpBattleRewardInfoWraper
{

	//构造函数
	public PvpBattleRewardInfoWraper()
	{
		 m_ItemID = -1;
		 m_ItemCout = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemID = -1;
		 m_ItemCout = -1;

	}

 	//转化成Protobuffer类型函数
	public PvpBattleRewardInfo ToPB()
	{
		PvpBattleRewardInfo v = new PvpBattleRewardInfo();
		v.ItemID = m_ItemID;
		v.ItemCout = m_ItemCout;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PvpBattleRewardInfo v)
	{
        if (v == null)
            return;
		m_ItemID = v.ItemID;
		m_ItemCout = v.ItemCout;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PvpBattleRewardInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PvpBattleRewardInfo pb = ProtoBuf.Serializer.Deserialize<PvpBattleRewardInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//道具数量
	public int m_ItemCout;
	public int ItemCout
	{
		get { return m_ItemCout;}
		set { m_ItemCout = value; }
	}


};
//联系人数据结构封装类
[System.Serializable]
public class ContactDataWraper
{

	//构造函数
	public ContactDataWraper()
	{
		 m_RoleId = 0;
		 m_TeamId = 0;
		 m_Nickname = "";
		 m_ConfigId = -1;
		 m_Level = 1;
		 m_ResourceId = -1;
		 m_Alias = "";
		 m_FamiliarPoint = 0;
		 m_OnLine = 0;
		 m_CombatValue = -1;
		 m_LastLoginTime = -1;
		 m_PopularPoint = 0;
		 m_UnionId = 0;
		 m_UnionName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_TeamId = 0;
		 m_Nickname = "";
		 m_ConfigId = -1;
		 m_Level = 1;
		 m_ResourceId = -1;
		 m_Alias = "";
		 m_FamiliarPoint = 0;
		 m_OnLine = 0;
		 m_CombatValue = -1;
		 m_LastLoginTime = -1;
		 m_PopularPoint = 0;
		 m_UnionId = 0;
		 m_UnionName = "";

	}

 	//转化成Protobuffer类型函数
	public ContactData ToPB()
	{
		ContactData v = new ContactData();
		v.RoleId = m_RoleId;
		v.TeamId = m_TeamId;
		v.Nickname = m_Nickname;
		v.ConfigId = m_ConfigId;
		v.Level = m_Level;
		v.ResourceId = m_ResourceId;
		v.Alias = m_Alias;
		v.FamiliarPoint = m_FamiliarPoint;
		v.OnLine = m_OnLine;
		v.CombatValue = m_CombatValue;
		v.LastLoginTime = m_LastLoginTime;
		v.PopularPoint = m_PopularPoint;
		v.UnionId = m_UnionId;
		v.UnionName = m_UnionName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactData v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_TeamId = v.TeamId;
		m_Nickname = v.Nickname;
		m_ConfigId = v.ConfigId;
		m_Level = v.Level;
		m_ResourceId = v.ResourceId;
		m_Alias = v.Alias;
		m_FamiliarPoint = v.FamiliarPoint;
		m_OnLine = v.OnLine;
		m_CombatValue = v.CombatValue;
		m_LastLoginTime = v.LastLoginTime;
		m_PopularPoint = v.PopularPoint;
		m_UnionId = v.UnionId;
		m_UnionName = v.UnionName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactData pb = ProtoBuf.Serializer.Deserialize<ContactData>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//玩家队伍Id
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//昵称
	public string m_Nickname;
	public string Nickname
	{
		get { return m_Nickname;}
		set { m_Nickname = value; }
	}
	//配置表id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//Level
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//资源Id
	public int m_ResourceId;
	public int ResourceId
	{
		get { return m_ResourceId;}
		set { m_ResourceId = value; }
	}
	//别名
	public string m_Alias;
	public string Alias
	{
		get { return m_Alias;}
		set { m_Alias = value; }
	}
	//亲密度
	public int m_FamiliarPoint;
	public int FamiliarPoint
	{
		get { return m_FamiliarPoint;}
		set { m_FamiliarPoint = value; }
	}
	//是否在线
	public int m_OnLine;
	public int OnLine
	{
		get { return m_OnLine;}
		set { m_OnLine = value; }
	}
	//战斗力
	public int m_CombatValue;
	public int CombatValue
	{
		get { return m_CombatValue;}
		set { m_CombatValue = value; }
	}
	//最后登录状态
	public Int64 m_LastLoginTime;
	public Int64 LastLoginTime
	{
		get { return m_LastLoginTime;}
		set { m_LastLoginTime = value; }
	}
	//人气值
	public int m_PopularPoint;
	public int PopularPoint
	{
		get { return m_PopularPoint;}
		set { m_PopularPoint = value; }
	}
	//UnionId
	public UInt64 m_UnionId;
	public UInt64 UnionId
	{
		get { return m_UnionId;}
		set { m_UnionId = value; }
	}
	//UnionName
	public string m_UnionName;
	public string UnionName
	{
		get { return m_UnionName;}
		set { m_UnionName = value; }
	}


};
//好友分组封装类
[System.Serializable]
public class ContactGroupWraper
{

	//构造函数
	public ContactGroupWraper()
	{
		 m_GroupName = "";
		m_GroupRoleIds = new List<UInt64>();
		 m_GroupId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GroupName = "";
		m_GroupRoleIds = new List<UInt64>();
		 m_GroupId = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactGroup ToPB()
	{
		ContactGroup v = new ContactGroup();
		v.GroupName = m_GroupName;
		for (int i=0; i<(int)m_GroupRoleIds.Count; i++)
			v.GroupRoleIds.Add( m_GroupRoleIds[i]);
		v.GroupId = m_GroupId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactGroup v)
	{
        if (v == null)
            return;
		m_GroupName = v.GroupName;
		m_GroupRoleIds.Clear();
		for( int i=0; i<v.GroupRoleIds.Count; i++)
			m_GroupRoleIds.Add(v.GroupRoleIds[i]);
		m_GroupId = v.GroupId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactGroup>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactGroup pb = ProtoBuf.Serializer.Deserialize<ContactGroup>(protoMS);
		FromPB(pb);
		return true;
	}

	//分组名字
	public string m_GroupName;
	public string GroupName
	{
		get { return m_GroupName;}
		set { m_GroupName = value; }
	}
	//分组好友Id
	public List<UInt64> m_GroupRoleIds;
	public int SizeGroupRoleIds()
	{
		return m_GroupRoleIds.Count;
	}
	public List<UInt64> GetGroupRoleIds()
	{
		return m_GroupRoleIds;
	}
	public UInt64 GetGroupRoleIds(int Index)
	{
		if(Index<0 || Index>=(int)m_GroupRoleIds.Count)
			return 0;
		return m_GroupRoleIds[Index];
	}
	public void SetGroupRoleIds( List<UInt64> v )
	{
		m_GroupRoleIds=v;
	}
	public void SetGroupRoleIds( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_GroupRoleIds.Count)
			return;
		m_GroupRoleIds[Index] = v;
	}
	public void AddGroupRoleIds( UInt64 v=0 )
	{
		m_GroupRoleIds.Add(v);
	}
	public void ClearGroupRoleIds( )
	{
		m_GroupRoleIds.Clear();
	}
	//组Id
	public int m_GroupId;
	public int GroupId
	{
		get { return m_GroupId;}
		set { m_GroupId = value; }
	}


};
//每日计数封装类
[System.Serializable]
public class DailyCountWraper
{

	//构造函数
	public DailyCountWraper()
	{
		 m_Count = 0;
		 m_Time = 0;
		 m_TimeId = 0;
		 m_Flag = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Count = 0;
		 m_Time = 0;
		 m_TimeId = 0;
		 m_Flag = -1;

	}

 	//转化成Protobuffer类型函数
	public DailyCount ToPB()
	{
		DailyCount v = new DailyCount();
		v.Count = m_Count;
		v.Time = m_Time;
		v.TimeId = m_TimeId;
		v.Flag = m_Flag;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DailyCount v)
	{
        if (v == null)
            return;
		m_Count = v.Count;
		m_Time = v.Time;
		m_TimeId = v.TimeId;
		m_Flag = v.Flag;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DailyCount>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DailyCount pb = ProtoBuf.Serializer.Deserialize<DailyCount>(protoMS);
		FromPB(pb);
		return true;
	}

	//计数
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}
	//时间
	public Int64 m_Time;
	public Int64 Time
	{
		get { return m_Time;}
		set { m_Time = value; }
	}
	//时间id 保留字段
	public int m_TimeId;
	public int TimeId
	{
		get { return m_TimeId;}
		set { m_TimeId = value; }
	}
	//计数标识
	public int m_Flag;
	public int Flag
	{
		get { return m_Flag;}
		set { m_Flag = value; }
	}


};
//爬塔信息封装类
[System.Serializable]
public class ClimTowerInfoWraper
{

	//构造函数
	public ClimTowerInfoWraper()
	{
		 m_LastTime = 0;
		 m_CurLayer = 1;
		 m_MaxLayer = 0;
		 m_ResetLayerTime = 0;
		m_FirstGet = new List<FirstVicGetWraper>();
		 m_HoldLayer = 0;
		 m_EnterPlay = 0;
		 m_CurWave = -1;
		m_BuffLists = new List<ClimTowerBuffListWraper>();
		 m_RefreshCount = -1;
		 m_SweepCount = -1;
		m_BufSelHistory = new List<ClimTowerBufWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LastTime = 0;
		 m_CurLayer = 1;
		 m_MaxLayer = 0;
		 m_ResetLayerTime = 0;
		m_FirstGet = new List<FirstVicGetWraper>();
		 m_HoldLayer = 0;
		 m_EnterPlay = 0;
		 m_CurWave = -1;
		m_BuffLists = new List<ClimTowerBuffListWraper>();
		 m_RefreshCount = -1;
		 m_SweepCount = -1;
		m_BufSelHistory = new List<ClimTowerBufWraper>();

	}

 	//转化成Protobuffer类型函数
	public ClimTowerInfo ToPB()
	{
		ClimTowerInfo v = new ClimTowerInfo();
		v.LastTime = m_LastTime;
		v.CurLayer = m_CurLayer;
		v.MaxLayer = m_MaxLayer;
		v.ResetLayerTime = m_ResetLayerTime;
		for (int i=0; i<(int)m_FirstGet.Count; i++)
			v.FirstGet.Add( m_FirstGet[i].ToPB());
		v.HoldLayer = m_HoldLayer;
		v.EnterPlay = m_EnterPlay;
		v.CurWave = m_CurWave;
		for (int i=0; i<(int)m_BuffLists.Count; i++)
			v.BuffLists.Add( m_BuffLists[i].ToPB());
		v.RefreshCount = m_RefreshCount;
		v.SweepCount = m_SweepCount;
		for (int i=0; i<(int)m_BufSelHistory.Count; i++)
			v.BufSelHistory.Add( m_BufSelHistory[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerInfo v)
	{
        if (v == null)
            return;
		m_LastTime = v.LastTime;
		m_CurLayer = v.CurLayer;
		m_MaxLayer = v.MaxLayer;
		m_ResetLayerTime = v.ResetLayerTime;
		m_FirstGet.Clear();
		for( int i=0; i<v.FirstGet.Count; i++)
			m_FirstGet.Add( new FirstVicGetWraper());
		for( int i=0; i<v.FirstGet.Count; i++)
			m_FirstGet[i].FromPB(v.FirstGet[i]);
		m_HoldLayer = v.HoldLayer;
		m_EnterPlay = v.EnterPlay;
		m_CurWave = v.CurWave;
		m_BuffLists.Clear();
		for( int i=0; i<v.BuffLists.Count; i++)
			m_BuffLists.Add( new ClimTowerBuffListWraper());
		for( int i=0; i<v.BuffLists.Count; i++)
			m_BuffLists[i].FromPB(v.BuffLists[i]);
		m_RefreshCount = v.RefreshCount;
		m_SweepCount = v.SweepCount;
		m_BufSelHistory.Clear();
		for( int i=0; i<v.BufSelHistory.Count; i++)
			m_BufSelHistory.Add( new ClimTowerBufWraper());
		for( int i=0; i<v.BufSelHistory.Count; i++)
			m_BufSelHistory[i].FromPB(v.BufSelHistory[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerInfo pb = ProtoBuf.Serializer.Deserialize<ClimTowerInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//每次爬塔时间
	public Int64 m_LastTime;
	public Int64 LastTime
	{
		get { return m_LastTime;}
		set { m_LastTime = value; }
	}
	//玩家当前层
	public int m_CurLayer;
	public int CurLayer
	{
		get { return m_CurLayer;}
		set { m_CurLayer = value; }
	}
	//已挑战完成最大层
	public int m_MaxLayer;
	public int MaxLayer
	{
		get { return m_MaxLayer;}
		set { m_MaxLayer = value; }
	}
	//最高层重置时间
	public Int64 m_ResetLayerTime;
	public Int64 ResetLayerTime
	{
		get { return m_ResetLayerTime;}
		set { m_ResetLayerTime = value; }
	}
	//首次胜利领取奖励标识
	public List<FirstVicGetWraper> m_FirstGet;
	public int SizeFirstGet()
	{
		return m_FirstGet.Count;
	}
	public List<FirstVicGetWraper> GetFirstGet()
	{
		return m_FirstGet;
	}
	public FirstVicGetWraper GetFirstGet(int Index)
	{
		if(Index<0 || Index>=(int)m_FirstGet.Count)
			return new FirstVicGetWraper();
		return m_FirstGet[Index];
	}
	public void SetFirstGet( List<FirstVicGetWraper> v )
	{
		m_FirstGet=v;
	}
	public void SetFirstGet( int Index, FirstVicGetWraper v )
	{
		if(Index<0 || Index>=(int)m_FirstGet.Count)
			return;
		m_FirstGet[Index] = v;
	}
	public void AddFirstGet( FirstVicGetWraper v )
	{
		m_FirstGet.Add(v);
	}
	public void ClearFirstGet( )
	{
		m_FirstGet.Clear();
	}
	//找回奖励层数
	public int m_HoldLayer;
	public int HoldLayer
	{
		get { return m_HoldLayer;}
		set { m_HoldLayer = value; }
	}
	//当天是否进入过系统
	public int m_EnterPlay;
	public int EnterPlay
	{
		get { return m_EnterPlay;}
		set { m_EnterPlay = value; }
	}
	//当前第几波怪
	public int m_CurWave;
	public int CurWave
	{
		get { return m_CurWave;}
		set { m_CurWave = value; }
	}
	//Buff列表
	public List<ClimTowerBuffListWraper> m_BuffLists;
	public int SizeBuffLists()
	{
		return m_BuffLists.Count;
	}
	public List<ClimTowerBuffListWraper> GetBuffLists()
	{
		return m_BuffLists;
	}
	public ClimTowerBuffListWraper GetBuffLists(int Index)
	{
		if(Index<0 || Index>=(int)m_BuffLists.Count)
			return new ClimTowerBuffListWraper();
		return m_BuffLists[Index];
	}
	public void SetBuffLists( List<ClimTowerBuffListWraper> v )
	{
		m_BuffLists=v;
	}
	public void SetBuffLists( int Index, ClimTowerBuffListWraper v )
	{
		if(Index<0 || Index>=(int)m_BuffLists.Count)
			return;
		m_BuffLists[Index] = v;
	}
	public void AddBuffLists( ClimTowerBuffListWraper v )
	{
		m_BuffLists.Add(v);
	}
	public void ClearBuffLists( )
	{
		m_BuffLists.Clear();
	}
	//Buff刷新次数
	public int m_RefreshCount;
	public int RefreshCount
	{
		get { return m_RefreshCount;}
		set { m_RefreshCount = value; }
	}
	//一键扫荡次数
	public int m_SweepCount;
	public int SweepCount
	{
		get { return m_SweepCount;}
		set { m_SweepCount = value; }
	}
	//buf选择记录
	public List<ClimTowerBufWraper> m_BufSelHistory;
	public int SizeBufSelHistory()
	{
		return m_BufSelHistory.Count;
	}
	public List<ClimTowerBufWraper> GetBufSelHistory()
	{
		return m_BufSelHistory;
	}
	public ClimTowerBufWraper GetBufSelHistory(int Index)
	{
		if(Index<0 || Index>=(int)m_BufSelHistory.Count)
			return new ClimTowerBufWraper();
		return m_BufSelHistory[Index];
	}
	public void SetBufSelHistory( List<ClimTowerBufWraper> v )
	{
		m_BufSelHistory=v;
	}
	public void SetBufSelHistory( int Index, ClimTowerBufWraper v )
	{
		if(Index<0 || Index>=(int)m_BufSelHistory.Count)
			return;
		m_BufSelHistory[Index] = v;
	}
	public void AddBufSelHistory( ClimTowerBufWraper v )
	{
		m_BufSelHistory.Add(v);
	}
	public void ClearBufSelHistory( )
	{
		m_BufSelHistory.Clear();
	}


};
//联系人设置封装类
[System.Serializable]
public class ContactSettingWraper
{

	//构造函数
	public ContactSettingWraper()
	{
		 m_CloseApplyFriend = -1;
		 m_ClearFirend = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_CloseApplyFriend = -1;
		 m_ClearFirend = -1;

	}

 	//转化成Protobuffer类型函数
	public ContactSetting ToPB()
	{
		ContactSetting v = new ContactSetting();
		v.CloseApplyFriend = m_CloseApplyFriend;
		v.ClearFirend = m_ClearFirend;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactSetting v)
	{
        if (v == null)
            return;
		m_CloseApplyFriend = v.CloseApplyFriend;
		m_ClearFirend = v.ClearFirend;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactSetting>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactSetting pb = ProtoBuf.Serializer.Deserialize<ContactSetting>(protoMS);
		FromPB(pb);
		return true;
	}

	//好友申请
	public int m_CloseApplyFriend;
	public int CloseApplyFriend
	{
		get { return m_CloseApplyFriend;}
		set { m_CloseApplyFriend = value; }
	}
	//自动清除好友
	public int m_ClearFirend;
	public int ClearFirend
	{
		get { return m_ClearFirend;}
		set { m_ClearFirend = value; }
	}


};
//首次胜利领取封装类
[System.Serializable]
public class FirstVicGetWraper
{

	//构造函数
	public FirstVicGetWraper()
	{
		 m_Id = -1;
		 m_Get = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Get = 0;

	}

 	//转化成Protobuffer类型函数
	public FirstVicGet ToPB()
	{
		FirstVicGet v = new FirstVicGet();
		v.Id = m_Id;
		v.Get = m_Get;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FirstVicGet v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Get = v.Get;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FirstVicGet>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FirstVicGet pb = ProtoBuf.Serializer.Deserialize<FirstVicGet>(protoMS);
		FromPB(pb);
		return true;
	}

	//层数
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//是否领取
	public int m_Get;
	public int Get
	{
		get { return m_Get;}
		set { m_Get = value; }
	}


};
//表情动作信息封装类
[System.Serializable]
public class ExpressionActionInfoWraper
{

	//构造函数
	public ExpressionActionInfoWraper()
	{
		 m_ActionId = -1;
		 m_UnLock = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ActionId = -1;
		 m_UnLock = false;

	}

 	//转化成Protobuffer类型函数
	public ExpressionActionInfo ToPB()
	{
		ExpressionActionInfo v = new ExpressionActionInfo();
		v.ActionId = m_ActionId;
		v.UnLock = m_UnLock;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionActionInfo v)
	{
        if (v == null)
            return;
		m_ActionId = v.ActionId;
		m_UnLock = v.UnLock;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionActionInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionActionInfo pb = ProtoBuf.Serializer.Deserialize<ExpressionActionInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//Id
	public int m_ActionId;
	public int ActionId
	{
		get { return m_ActionId;}
		set { m_ActionId = value; }
	}
	//是否解锁
	public bool m_UnLock;
	public bool UnLock
	{
		get { return m_UnLock;}
		set { m_UnLock = value; }
	}


};
//32位程序封装类
[System.Serializable]
public class IntPairWraper
{

	//构造函数
	public IntPairWraper()
	{
		 m_Key = -1;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public IntPair ToPB()
	{
		IntPair v = new IntPair();
		v.Key = m_Key;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(IntPair v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<IntPair>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		IntPair pb = ProtoBuf.Serializer.Deserialize<IntPair>(protoMS);
		FromPB(pb);
		return true;
	}

	//键值
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//值
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//通讯录封装类
[System.Serializable]
public class AddressBookWraper
{

	//构造函数
	public AddressBookWraper()
	{
		m_ContactDataList = new List<ContactDataWraper>();
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_Setting = new ContactSettingWraper();
		 m_MyRoleData = new ContactDataWraper();
		m_SortGroupId = new List<int>();
		 m_GiftPointList = new FriendGifPointListWraper();
		m_ChatMsgList = new List<ContactsChatMsgWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ContactDataList = new List<ContactDataWraper>();
		m_ContactGroups = new List<ContactGroupWraper>();
		 m_Setting = new ContactSettingWraper();
		 m_MyRoleData = new ContactDataWraper();
		m_SortGroupId = new List<int>();
		 m_GiftPointList = new FriendGifPointListWraper();
		m_ChatMsgList = new List<ContactsChatMsgWraper>();

	}

 	//转化成Protobuffer类型函数
	public AddressBook ToPB()
	{
		AddressBook v = new AddressBook();
		for (int i=0; i<(int)m_ContactDataList.Count; i++)
			v.ContactDataList.Add( m_ContactDataList[i].ToPB());
		for (int i=0; i<(int)m_ContactGroups.Count; i++)
			v.ContactGroups.Add( m_ContactGroups[i].ToPB());
		v.Setting = m_Setting.ToPB();
		v.MyRoleData = m_MyRoleData.ToPB();
		for (int i=0; i<(int)m_SortGroupId.Count; i++)
			v.SortGroupId.Add( m_SortGroupId[i]);
		v.GiftPointList = m_GiftPointList.ToPB();
		for (int i=0; i<(int)m_ChatMsgList.Count; i++)
			v.ChatMsgList.Add( m_ChatMsgList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AddressBook v)
	{
        if (v == null)
            return;
		m_ContactDataList.Clear();
		for( int i=0; i<v.ContactDataList.Count; i++)
			m_ContactDataList.Add( new ContactDataWraper());
		for( int i=0; i<v.ContactDataList.Count; i++)
			m_ContactDataList[i].FromPB(v.ContactDataList[i]);
		m_ContactGroups.Clear();
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups.Add( new ContactGroupWraper());
		for( int i=0; i<v.ContactGroups.Count; i++)
			m_ContactGroups[i].FromPB(v.ContactGroups[i]);
		m_Setting.FromPB(v.Setting);
		m_MyRoleData.FromPB(v.MyRoleData);
		m_SortGroupId.Clear();
		for( int i=0; i<v.SortGroupId.Count; i++)
			m_SortGroupId.Add(v.SortGroupId[i]);
		m_GiftPointList.FromPB(v.GiftPointList);
		m_ChatMsgList.Clear();
		for( int i=0; i<v.ChatMsgList.Count; i++)
			m_ChatMsgList.Add( new ContactsChatMsgWraper());
		for( int i=0; i<v.ChatMsgList.Count; i++)
			m_ChatMsgList[i].FromPB(v.ChatMsgList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AddressBook>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AddressBook pb = ProtoBuf.Serializer.Deserialize<AddressBook>(protoMS);
		FromPB(pb);
		return true;
	}

	//联系人列表
	public List<ContactDataWraper> m_ContactDataList;
	public int SizeContactDataList()
	{
		return m_ContactDataList.Count;
	}
	public List<ContactDataWraper> GetContactDataList()
	{
		return m_ContactDataList;
	}
	public ContactDataWraper GetContactDataList(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactDataList.Count)
			return new ContactDataWraper();
		return m_ContactDataList[Index];
	}
	public void SetContactDataList( List<ContactDataWraper> v )
	{
		m_ContactDataList=v;
	}
	public void SetContactDataList( int Index, ContactDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactDataList.Count)
			return;
		m_ContactDataList[Index] = v;
	}
	public void AddContactDataList( ContactDataWraper v )
	{
		m_ContactDataList.Add(v);
	}
	public void ClearContactDataList( )
	{
		m_ContactDataList.Clear();
	}
	//联系人分组数据
	public List<ContactGroupWraper> m_ContactGroups;
	public int SizeContactGroups()
	{
		return m_ContactGroups.Count;
	}
	public List<ContactGroupWraper> GetContactGroups()
	{
		return m_ContactGroups;
	}
	public ContactGroupWraper GetContactGroups(int Index)
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return new ContactGroupWraper();
		return m_ContactGroups[Index];
	}
	public void SetContactGroups( List<ContactGroupWraper> v )
	{
		m_ContactGroups=v;
	}
	public void SetContactGroups( int Index, ContactGroupWraper v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.Count)
			return;
		m_ContactGroups[Index] = v;
	}
	public void AddContactGroups( ContactGroupWraper v )
	{
		m_ContactGroups.Add(v);
	}
	public void ClearContactGroups( )
	{
		m_ContactGroups.Clear();
	}
	//好友设置
	public ContactSettingWraper m_Setting;
	public ContactSettingWraper Setting
	{
		get { return m_Setting;}
		set { m_Setting = value; }
	}
	//我自己的数据
	public ContactDataWraper m_MyRoleData;
	public ContactDataWraper MyRoleData
	{
		get { return m_MyRoleData;}
		set { m_MyRoleData = value; }
	}
	//排序的id
	public List<int> m_SortGroupId;
	public int SizeSortGroupId()
	{
		return m_SortGroupId.Count;
	}
	public List<int> GetSortGroupId()
	{
		return m_SortGroupId;
	}
	public int GetSortGroupId(int Index)
	{
		if(Index<0 || Index>=(int)m_SortGroupId.Count)
			return -1;
		return m_SortGroupId[Index];
	}
	public void SetSortGroupId( List<int> v )
	{
		m_SortGroupId=v;
	}
	public void SetSortGroupId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_SortGroupId.Count)
			return;
		m_SortGroupId[Index] = v;
	}
	public void AddSortGroupId( int v=-1 )
	{
		m_SortGroupId.Add(v);
	}
	public void ClearSortGroupId( )
	{
		m_SortGroupId.Clear();
	}
	//友情点
	public FriendGifPointListWraper m_GiftPointList;
	public FriendGifPointListWraper GiftPointList
	{
		get { return m_GiftPointList;}
		set { m_GiftPointList = value; }
	}
	//玩家聊天信息
	public List<ContactsChatMsgWraper> m_ChatMsgList;
	public int SizeChatMsgList()
	{
		return m_ChatMsgList.Count;
	}
	public List<ContactsChatMsgWraper> GetChatMsgList()
	{
		return m_ChatMsgList;
	}
	public ContactsChatMsgWraper GetChatMsgList(int Index)
	{
		if(Index<0 || Index>=(int)m_ChatMsgList.Count)
			return new ContactsChatMsgWraper();
		return m_ChatMsgList[Index];
	}
	public void SetChatMsgList( List<ContactsChatMsgWraper> v )
	{
		m_ChatMsgList=v;
	}
	public void SetChatMsgList( int Index, ContactsChatMsgWraper v )
	{
		if(Index<0 || Index>=(int)m_ChatMsgList.Count)
			return;
		m_ChatMsgList[Index] = v;
	}
	public void AddChatMsgList( ContactsChatMsgWraper v )
	{
		m_ChatMsgList.Add(v);
	}
	public void ClearChatMsgList( )
	{
		m_ChatMsgList.Clear();
	}


};
//拍卖的商品封装类
[System.Serializable]
public class AuctionItemWraper
{

	//构造函数
	public AuctionItemWraper()
	{
		 m_OwnerGuid = 0;
		 m_Price = 1;
		 m_Currency = 1;
		 m_ItemData = new ItemDataWraper();
		 m_Status = 0;
		 m_SaleTS = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_OwnerGuid = 0;
		 m_Price = 1;
		 m_Currency = 1;
		 m_ItemData = new ItemDataWraper();
		 m_Status = 0;
		 m_SaleTS = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionItem ToPB()
	{
		AuctionItem v = new AuctionItem();
		v.OwnerGuid = m_OwnerGuid;
		v.Price = m_Price;
		v.Currency = m_Currency;
		v.ItemData = m_ItemData.ToPB();
		v.Status = m_Status;
		v.SaleTS = m_SaleTS;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionItem v)
	{
        if (v == null)
            return;
		m_OwnerGuid = v.OwnerGuid;
		m_Price = v.Price;
		m_Currency = v.Currency;
		m_ItemData.FromPB(v.ItemData);
		m_Status = v.Status;
		m_SaleTS = v.SaleTS;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionItem pb = ProtoBuf.Serializer.Deserialize<AuctionItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//拍卖商品的人guid
	public UInt64 m_OwnerGuid;
	public UInt64 OwnerGuid
	{
		get { return m_OwnerGuid;}
		set { m_OwnerGuid = value; }
	}
	//拍卖报价
	public int m_Price;
	public int Price
	{
		get { return m_Price;}
		set { m_Price = value; }
	}
	//钱币种类
	public int m_Currency;
	public int Currency
	{
		get { return m_Currency;}
		set { m_Currency = value; }
	}
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}
	//道具状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//上架时间
	public int m_SaleTS;
	public int SaleTS
	{
		get { return m_SaleTS;}
		set { m_SaleTS = value; }
	}


};
//交易记录封装类
[System.Serializable]
public class AuctionRecSimpleWraper
{

	//构造函数
	public AuctionRecSimpleWraper()
	{
		 m_RecGuid = 0;
		 m_SoldTS = -1;
		 m_ItemId = -1;
		 m_Count = -1;
		 m_Currency = -1;
		 m_Cost = -1;
		 m_SoldType = -1;
		 m_Tax = -1;
		 m_IsGot = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RecGuid = 0;
		 m_SoldTS = -1;
		 m_ItemId = -1;
		 m_Count = -1;
		 m_Currency = -1;
		 m_Cost = -1;
		 m_SoldType = -1;
		 m_Tax = -1;
		 m_IsGot = false;

	}

 	//转化成Protobuffer类型函数
	public AuctionRecSimple ToPB()
	{
		AuctionRecSimple v = new AuctionRecSimple();
		v.RecGuid = m_RecGuid;
		v.SoldTS = m_SoldTS;
		v.ItemId = m_ItemId;
		v.Count = m_Count;
		v.Currency = m_Currency;
		v.Cost = m_Cost;
		v.SoldType = m_SoldType;
		v.Tax = m_Tax;
		v.IsGot = m_IsGot;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRecSimple v)
	{
        if (v == null)
            return;
		m_RecGuid = v.RecGuid;
		m_SoldTS = v.SoldTS;
		m_ItemId = v.ItemId;
		m_Count = v.Count;
		m_Currency = v.Currency;
		m_Cost = v.Cost;
		m_SoldType = v.SoldType;
		m_Tax = v.Tax;
		m_IsGot = v.IsGot;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRecSimple>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRecSimple pb = ProtoBuf.Serializer.Deserialize<AuctionRecSimple>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品guid
	public UInt64 m_RecGuid;
	public UInt64 RecGuid
	{
		get { return m_RecGuid;}
		set { m_RecGuid = value; }
	}
	//交易时间
	public int m_SoldTS;
	public int SoldTS
	{
		get { return m_SoldTS;}
		set { m_SoldTS = value; }
	}
	//商品itemID
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}
	//货币类型
	public int m_Currency;
	public int Currency
	{
		get { return m_Currency;}
		set { m_Currency = value; }
	}
	//货币数量
	public int m_Cost;
	public int Cost
	{
		get { return m_Cost;}
		set { m_Cost = value; }
	}
	//交易类型
	public int m_SoldType;
	public int SoldType
	{
		get { return m_SoldType;}
		set { m_SoldType = value; }
	}
	//税
	public int m_Tax;
	public int Tax
	{
		get { return m_Tax;}
		set { m_Tax = value; }
	}
	//是不是交付
	public bool m_IsGot;
	public bool IsGot
	{
		get { return m_IsGot;}
		set { m_IsGot = value; }
	}


};
//交易记录详细封装类
[System.Serializable]
public class AuctionRecDetailWraper
{

	//构造函数
	public AuctionRecDetailWraper()
	{
		 m_BuyGuid = 0;
		 m_SoldTS = -1;
		 m_AuctionItem = new AuctionItemWraper();
		 m_IsGot = false;
		 m_Cost = -1;
		 m_Tax = -1;
		 m_Currency = -1;
		 m_RecGuid = 0;
		 m_NewItemGuid = false;
		 m_SoldType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BuyGuid = 0;
		 m_SoldTS = -1;
		 m_AuctionItem = new AuctionItemWraper();
		 m_IsGot = false;
		 m_Cost = -1;
		 m_Tax = -1;
		 m_Currency = -1;
		 m_RecGuid = 0;
		 m_NewItemGuid = false;
		 m_SoldType = -1;

	}

 	//转化成Protobuffer类型函数
	public AuctionRecDetail ToPB()
	{
		AuctionRecDetail v = new AuctionRecDetail();
		v.BuyGuid = m_BuyGuid;
		v.SoldTS = m_SoldTS;
		v.AuctionItem = m_AuctionItem.ToPB();
		v.IsGot = m_IsGot;
		v.Cost = m_Cost;
		v.Tax = m_Tax;
		v.Currency = m_Currency;
		v.RecGuid = m_RecGuid;
		v.NewItemGuid = m_NewItemGuid;
		v.SoldType = m_SoldType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionRecDetail v)
	{
        if (v == null)
            return;
		m_BuyGuid = v.BuyGuid;
		m_SoldTS = v.SoldTS;
		m_AuctionItem.FromPB(v.AuctionItem);
		m_IsGot = v.IsGot;
		m_Cost = v.Cost;
		m_Tax = v.Tax;
		m_Currency = v.Currency;
		m_RecGuid = v.RecGuid;
		m_NewItemGuid = v.NewItemGuid;
		m_SoldType = v.SoldType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionRecDetail>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionRecDetail pb = ProtoBuf.Serializer.Deserialize<AuctionRecDetail>(protoMS);
		FromPB(pb);
		return true;
	}

	//购买人guid
	public UInt64 m_BuyGuid;
	public UInt64 BuyGuid
	{
		get { return m_BuyGuid;}
		set { m_BuyGuid = value; }
	}
	//购买时间
	public int m_SoldTS;
	public int SoldTS
	{
		get { return m_SoldTS;}
		set { m_SoldTS = value; }
	}
	//商品信息
	public AuctionItemWraper m_AuctionItem;
	public AuctionItemWraper AuctionItem
	{
		get { return m_AuctionItem;}
		set { m_AuctionItem = value; }
	}
	//商品是否交付
	public bool m_IsGot;
	public bool IsGot
	{
		get { return m_IsGot;}
		set { m_IsGot = value; }
	}
	//花费
	public int m_Cost;
	public int Cost
	{
		get { return m_Cost;}
		set { m_Cost = value; }
	}
	//税
	public int m_Tax;
	public int Tax
	{
		get { return m_Tax;}
		set { m_Tax = value; }
	}
	//货币种类
	public int m_Currency;
	public int Currency
	{
		get { return m_Currency;}
		set { m_Currency = value; }
	}
	//RecGuid
	public UInt64 m_RecGuid;
	public UInt64 RecGuid
	{
		get { return m_RecGuid;}
		set { m_RecGuid = value; }
	}
	//商品获得时是不是新guid
	public bool m_NewItemGuid;
	public bool NewItemGuid
	{
		get { return m_NewItemGuid;}
		set { m_NewItemGuid = value; }
	}
	//买还是卖
	public int m_SoldType;
	public int SoldType
	{
		get { return m_SoldType;}
		set { m_SoldType = value; }
	}


};
//佣兵信息封装类
[System.Serializable]
public class MercenaryInfoWraper
{

	//构造函数
	public MercenaryInfoWraper()
	{
		 m_Id = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = 0;

	}

 	//转化成Protobuffer类型函数
	public MercenaryInfo ToPB()
	{
		MercenaryInfo v = new MercenaryInfo();
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MercenaryInfo v)
	{
        if (v == null)
            return;
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MercenaryInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MercenaryInfo pb = ProtoBuf.Serializer.Deserialize<MercenaryInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//佣兵id
	public UInt64 m_Id;
	public UInt64 Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
//排行榜信息封装类
[System.Serializable]
public class RankInfoWraper
{

	//构造函数
	public RankInfoWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_ConfigID = -1;
		 m_GuildID = 0;
		 m_GuildName = "";
		 m_PetID = -1;
		 m_PetLevel = -1;
		 m_TreasureCount = -1;
		 m_TreasureLevel = -1;
		 m_Score = -1;
		 m_Level = -1;
		 m_GuildFlagID = -1;
		 m_WinCount = -1;
		 m_GuildDungeonLayer = -1;
		 m_GuildDungeonTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_RoleName = "";
		 m_ConfigID = -1;
		 m_GuildID = 0;
		 m_GuildName = "";
		 m_PetID = -1;
		 m_PetLevel = -1;
		 m_TreasureCount = -1;
		 m_TreasureLevel = -1;
		 m_Score = -1;
		 m_Level = -1;
		 m_GuildFlagID = -1;
		 m_WinCount = -1;
		 m_GuildDungeonLayer = -1;
		 m_GuildDungeonTime = -1;

	}

 	//转化成Protobuffer类型函数
	public RankInfo ToPB()
	{
		RankInfo v = new RankInfo();
		v.RoleID = m_RoleID;
		v.RoleName = m_RoleName;
		v.ConfigID = m_ConfigID;
		v.GuildID = m_GuildID;
		v.GuildName = m_GuildName;
		v.PetID = m_PetID;
		v.PetLevel = m_PetLevel;
		v.TreasureCount = m_TreasureCount;
		v.TreasureLevel = m_TreasureLevel;
		v.Score = m_Score;
		v.Level = m_Level;
		v.GuildFlagID = m_GuildFlagID;
		v.WinCount = m_WinCount;
		v.GuildDungeonLayer = m_GuildDungeonLayer;
		v.GuildDungeonTime = m_GuildDungeonTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RankInfo v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_RoleName = v.RoleName;
		m_ConfigID = v.ConfigID;
		m_GuildID = v.GuildID;
		m_GuildName = v.GuildName;
		m_PetID = v.PetID;
		m_PetLevel = v.PetLevel;
		m_TreasureCount = v.TreasureCount;
		m_TreasureLevel = v.TreasureLevel;
		m_Score = v.Score;
		m_Level = v.Level;
		m_GuildFlagID = v.GuildFlagID;
		m_WinCount = v.WinCount;
		m_GuildDungeonLayer = v.GuildDungeonLayer;
		m_GuildDungeonTime = v.GuildDungeonTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RankInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RankInfo pb = ProtoBuf.Serializer.Deserialize<RankInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色唯一ID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//角色名
	public string m_RoleName;
	public string RoleName
	{
		get { return m_RoleName;}
		set { m_RoleName = value; }
	}
	//职业ID
	public int m_ConfigID;
	public int ConfigID
	{
		get { return m_ConfigID;}
		set { m_ConfigID = value; }
	}
	//工会ID
	public UInt64 m_GuildID;
	public UInt64 GuildID
	{
		get { return m_GuildID;}
		set { m_GuildID = value; }
	}
	//工会名
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//宠物ID
	public int m_PetID;
	public int PetID
	{
		get { return m_PetID;}
		set { m_PetID = value; }
	}
	//宠物等级
	public int m_PetLevel;
	public int PetLevel
	{
		get { return m_PetLevel;}
		set { m_PetLevel = value; }
	}
	//外观数量
	public int m_TreasureCount;
	public int TreasureCount
	{
		get { return m_TreasureCount;}
		set { m_TreasureCount = value; }
	}
	//宝物库等级
	public int m_TreasureLevel;
	public int TreasureLevel
	{
		get { return m_TreasureLevel;}
		set { m_TreasureLevel = value; }
	}
	//排行分数
	public int m_Score;
	public int Score
	{
		get { return m_Score;}
		set { m_Score = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//工会旗帜ID
	public int m_GuildFlagID;
	public int GuildFlagID
	{
		get { return m_GuildFlagID;}
		set { m_GuildFlagID = value; }
	}
	//胜场数
	public int m_WinCount;
	public int WinCount
	{
		get { return m_WinCount;}
		set { m_WinCount = value; }
	}
	//工会爬塔层数
	public int m_GuildDungeonLayer;
	public int GuildDungeonLayer
	{
		get { return m_GuildDungeonLayer;}
		set { m_GuildDungeonLayer = value; }
	}
	//工会爬塔时间
	public int m_GuildDungeonTime;
	public int GuildDungeonTime
	{
		get { return m_GuildDungeonTime;}
		set { m_GuildDungeonTime = value; }
	}


};
//拍卖行商品数量信息封装类
[System.Serializable]
public class AuctionItemCntWraper
{

	//构造函数
	public AuctionItemCntWraper()
	{
		 m_ItemId = -1;
		 m_Count = -1;
		 m_InShow = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;
		 m_Count = -1;
		 m_InShow = false;

	}

 	//转化成Protobuffer类型函数
	public AuctionItemCnt ToPB()
	{
		AuctionItemCnt v = new AuctionItemCnt();
		v.ItemId = m_ItemId;
		v.Count = m_Count;
		v.InShow = m_InShow;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AuctionItemCnt v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_Count = v.Count;
		m_InShow = v.InShow;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuctionItemCnt>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AuctionItemCnt pb = ProtoBuf.Serializer.Deserialize<AuctionItemCnt>(protoMS);
		FromPB(pb);
		return true;
	}

	//商品id
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//商品数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}
	//InShow
	public bool m_InShow;
	public bool InShow
	{
		get { return m_InShow;}
		set { m_InShow = value; }
	}


};
//红点信息封装类
[System.Serializable]
public class RedDotInfoWraper
{

	//构造函数
	public RedDotInfoWraper()
	{
		 m_Type = -1;
		 m_IsLight = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;
		 m_IsLight = -1;

	}

 	//转化成Protobuffer类型函数
	public RedDotInfo ToPB()
	{
		RedDotInfo v = new RedDotInfo();
		v.Type = m_Type;
		v.IsLight = m_IsLight;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RedDotInfo v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_IsLight = v.IsLight;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RedDotInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RedDotInfo pb = ProtoBuf.Serializer.Deserialize<RedDotInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//是否亮
	public int m_IsLight;
	public int IsLight
	{
		get { return m_IsLight;}
		set { m_IsLight = value; }
	}


};
//礼物点数封装类
[System.Serializable]
public class FriendGiftPointWraper
{

	//构造函数
	public FriendGiftPointWraper()
	{
		 m_Guid = 0;
		 m_Point = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_Point = 0;

	}

 	//转化成Protobuffer类型函数
	public FriendGiftPoint ToPB()
	{
		FriendGiftPoint v = new FriendGiftPoint();
		v.Guid = m_Guid;
		v.Point = m_Point;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FriendGiftPoint v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_Point = v.Point;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FriendGiftPoint>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FriendGiftPoint pb = ProtoBuf.Serializer.Deserialize<FriendGiftPoint>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//点数
	public int m_Point;
	public int Point
	{
		get { return m_Point;}
		set { m_Point = value; }
	}


};
//收到赠送列表封装类
[System.Serializable]
public class FriendGifPointListWraper
{

	//构造函数
	public FriendGifPointListWraper()
	{
		m_SentGiftList = new List<FriendGiftPointWraper>();
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_SentGiftList = new List<FriendGiftPointWraper>();
		m_AcquireGiftList = new List<FriendGiftPointWraper>();
		m_UnAcquireGiftList = new List<FriendGiftPointWraper>();

	}

 	//转化成Protobuffer类型函数
	public FriendGifPointList ToPB()
	{
		FriendGifPointList v = new FriendGifPointList();
		for (int i=0; i<(int)m_SentGiftList.Count; i++)
			v.SentGiftList.Add( m_SentGiftList[i].ToPB());
		for (int i=0; i<(int)m_AcquireGiftList.Count; i++)
			v.AcquireGiftList.Add( m_AcquireGiftList[i].ToPB());
		for (int i=0; i<(int)m_UnAcquireGiftList.Count; i++)
			v.UnAcquireGiftList.Add( m_UnAcquireGiftList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FriendGifPointList v)
	{
        if (v == null)
            return;
		m_SentGiftList.Clear();
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.SentGiftList.Count; i++)
			m_SentGiftList[i].FromPB(v.SentGiftList[i]);
		m_AcquireGiftList.Clear();
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.AcquireGiftList.Count; i++)
			m_AcquireGiftList[i].FromPB(v.AcquireGiftList[i]);
		m_UnAcquireGiftList.Clear();
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList.Add( new FriendGiftPointWraper());
		for( int i=0; i<v.UnAcquireGiftList.Count; i++)
			m_UnAcquireGiftList[i].FromPB(v.UnAcquireGiftList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FriendGifPointList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FriendGifPointList pb = ProtoBuf.Serializer.Deserialize<FriendGifPointList>(protoMS);
		FromPB(pb);
		return true;
	}

	//已经赠送列表
	public List<FriendGiftPointWraper> m_SentGiftList;
	public int SizeSentGiftList()
	{
		return m_SentGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetSentGiftList()
	{
		return m_SentGiftList;
	}
	public FriendGiftPointWraper GetSentGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return new FriendGiftPointWraper();
		return m_SentGiftList[Index];
	}
	public void SetSentGiftList( List<FriendGiftPointWraper> v )
	{
		m_SentGiftList=v;
	}
	public void SetSentGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.Count)
			return;
		m_SentGiftList[Index] = v;
	}
	public void AddSentGiftList( FriendGiftPointWraper v )
	{
		m_SentGiftList.Add(v);
	}
	public void ClearSentGiftList( )
	{
		m_SentGiftList.Clear();
	}
	//已经收取列表
	public List<FriendGiftPointWraper> m_AcquireGiftList;
	public int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetAcquireGiftList()
	{
		return m_AcquireGiftList;
	}
	public FriendGiftPointWraper GetAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_AcquireGiftList[Index];
	}
	public void SetAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_AcquireGiftList=v;
	}
	public void SetAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.Count)
			return;
		m_AcquireGiftList[Index] = v;
	}
	public void AddAcquireGiftList( FriendGiftPointWraper v )
	{
		m_AcquireGiftList.Add(v);
	}
	public void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.Clear();
	}
	//可收取
	public List<FriendGiftPointWraper> m_UnAcquireGiftList;
	public int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.Count;
	}
	public List<FriendGiftPointWraper> GetUnAcquireGiftList()
	{
		return m_UnAcquireGiftList;
	}
	public FriendGiftPointWraper GetUnAcquireGiftList(int Index)
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return new FriendGiftPointWraper();
		return m_UnAcquireGiftList[Index];
	}
	public void SetUnAcquireGiftList( List<FriendGiftPointWraper> v )
	{
		m_UnAcquireGiftList=v;
	}
	public void SetUnAcquireGiftList( int Index, FriendGiftPointWraper v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.Count)
			return;
		m_UnAcquireGiftList[Index] = v;
	}
	public void AddUnAcquireGiftList( FriendGiftPointWraper v )
	{
		m_UnAcquireGiftList.Add(v);
	}
	public void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.Clear();
	}


};
//当前完成数量封装类
[System.Serializable]
public class DungeonTargetContentWraper
{

	//构造函数
	public DungeonTargetContentWraper()
	{
		 m_Index = -1;
		 m_TemplateId = -1;
		 m_MaxCount = -1;
		 m_CurCount = -1;
		 m_Description = -1;
		 m_IParam = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_TemplateId = -1;
		 m_MaxCount = -1;
		 m_CurCount = -1;
		 m_Description = -1;
		 m_IParam = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonTargetContent ToPB()
	{
		DungeonTargetContent v = new DungeonTargetContent();
		v.Index = m_Index;
		v.TemplateId = m_TemplateId;
		v.MaxCount = m_MaxCount;
		v.CurCount = m_CurCount;
		v.Description = m_Description;
		v.IParam = m_IParam;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonTargetContent v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_TemplateId = v.TemplateId;
		m_MaxCount = v.MaxCount;
		m_CurCount = v.CurCount;
		m_Description = v.Description;
		m_IParam = v.IParam;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonTargetContent>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonTargetContent pb = ProtoBuf.Serializer.Deserialize<DungeonTargetContent>(protoMS);
		FromPB(pb);
		return true;
	}

	//子任务序号
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//模板id
	public int m_TemplateId;
	public int TemplateId
	{
		get { return m_TemplateId;}
		set { m_TemplateId = value; }
	}
	//目标数量
	public int m_MaxCount;
	public int MaxCount
	{
		get { return m_MaxCount;}
		set { m_MaxCount = value; }
	}
	//当前完成数量
	public int m_CurCount;
	public int CurCount
	{
		get { return m_CurCount;}
		set { m_CurCount = value; }
	}
	//描述文字Id
	public int m_Description;
	public int Description
	{
		get { return m_Description;}
		set { m_Description = value; }
	}
	//目标参数
	public int m_IParam;
	public int IParam
	{
		get { return m_IParam;}
		set { m_IParam = value; }
	}


};
//副本任务目标封装类
[System.Serializable]
public class DungeonTargetWraper
{

	//构造函数
	public DungeonTargetWraper()
	{
		 m_TypeId = -1;
		 m_Index = -1;
		m_TargetContent = new List<DungeonTargetContentWraper>();
		 m_Description = -1;
		 m_IParam = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TypeId = -1;
		 m_Index = -1;
		m_TargetContent = new List<DungeonTargetContentWraper>();
		 m_Description = -1;
		 m_IParam = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonTarget ToPB()
	{
		DungeonTarget v = new DungeonTarget();
		v.TypeId = m_TypeId;
		v.Index = m_Index;
		for (int i=0; i<(int)m_TargetContent.Count; i++)
			v.TargetContent.Add( m_TargetContent[i].ToPB());
		v.Description = m_Description;
		v.IParam = m_IParam;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonTarget v)
	{
        if (v == null)
            return;
		m_TypeId = v.TypeId;
		m_Index = v.Index;
		m_TargetContent.Clear();
		for( int i=0; i<v.TargetContent.Count; i++)
			m_TargetContent.Add( new DungeonTargetContentWraper());
		for( int i=0; i<v.TargetContent.Count; i++)
			m_TargetContent[i].FromPB(v.TargetContent[i]);
		m_Description = v.Description;
		m_IParam = v.IParam;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonTarget>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonTarget pb = ProtoBuf.Serializer.Deserialize<DungeonTarget>(protoMS);
		FromPB(pb);
		return true;
	}

	//目标类型
	public int m_TypeId;
	public int TypeId
	{
		get { return m_TypeId;}
		set { m_TypeId = value; }
	}
	//目标序号
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//子任务
	public List<DungeonTargetContentWraper> m_TargetContent;
	public int SizeTargetContent()
	{
		return m_TargetContent.Count;
	}
	public List<DungeonTargetContentWraper> GetTargetContent()
	{
		return m_TargetContent;
	}
	public DungeonTargetContentWraper GetTargetContent(int Index)
	{
		if(Index<0 || Index>=(int)m_TargetContent.Count)
			return new DungeonTargetContentWraper();
		return m_TargetContent[Index];
	}
	public void SetTargetContent( List<DungeonTargetContentWraper> v )
	{
		m_TargetContent=v;
	}
	public void SetTargetContent( int Index, DungeonTargetContentWraper v )
	{
		if(Index<0 || Index>=(int)m_TargetContent.Count)
			return;
		m_TargetContent[Index] = v;
	}
	public void AddTargetContent( DungeonTargetContentWraper v )
	{
		m_TargetContent.Add(v);
	}
	public void ClearTargetContent( )
	{
		m_TargetContent.Clear();
	}
	//副本目标描述Id
	public int m_Description;
	public int Description
	{
		get { return m_Description;}
		set { m_Description = value; }
	}
	//副本目标参数
	public int m_IParam;
	public int IParam
	{
		get { return m_IParam;}
		set { m_IParam = value; }
	}


};
//MailItem封装类
[System.Serializable]
public class MailItemWraper
{

	//构造函数
	public MailItemWraper()
	{
		 m_ItemID = -1;
		 m_ItemCount = -1;
		 m_Transit = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemID = -1;
		 m_ItemCount = -1;
		 m_Transit = false;

	}

 	//转化成Protobuffer类型函数
	public MailItem ToPB()
	{
		MailItem v = new MailItem();
		v.ItemID = m_ItemID;
		v.ItemCount = m_ItemCount;
		v.Transit = m_Transit;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailItem v)
	{
        if (v == null)
            return;
		m_ItemID = v.ItemID;
		m_ItemCount = v.ItemCount;
		m_Transit = v.Transit;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailItem pb = ProtoBuf.Serializer.Deserialize<MailItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//道具数量
	public int m_ItemCount;
	public int ItemCount
	{
		get { return m_ItemCount;}
		set { m_ItemCount = value; }
	}
	//transit
	public bool m_Transit;
	public bool Transit
	{
		get { return m_Transit;}
		set { m_Transit = value; }
	}


};
//obj创建需要信息封装类
[System.Serializable]
public class ObjCreateInfoWraper
{

	//构造函数
	public ObjCreateInfoWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_Status = -1;
		 m_TargetPos = new Vector3Wraper();
		 m_ObjData = new byte[0];
		 m_Motion = new MotionInfoWraper();
		 m_IsNew = false;
		 m_SkillPrepareId = -1;
		 m_SkillPrepareTime = -1;
		 m_LoopSkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_Status = -1;
		 m_TargetPos = new Vector3Wraper();
		 m_ObjData = new byte[0];
		 m_Motion = new MotionInfoWraper();
		 m_IsNew = false;
		 m_SkillPrepareId = -1;
		 m_SkillPrepareTime = -1;
		 m_LoopSkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public ObjCreateInfo ToPB()
	{
		ObjCreateInfo v = new ObjCreateInfo();
		v.ObjId = m_ObjId;
		v.Pos = m_Pos.ToPB();
		v.Dir = m_Dir;
		v.Status = m_Status;
		v.TargetPos = m_TargetPos.ToPB();
		v.ObjData = m_ObjData;
		v.Motion = m_Motion.ToPB();
		v.IsNew = m_IsNew;
		v.SkillPrepareId = m_SkillPrepareId;
		v.SkillPrepareTime = m_SkillPrepareTime;
		v.LoopSkillId = m_LoopSkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ObjCreateInfo v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Pos.FromPB(v.Pos);
		m_Dir = v.Dir;
		m_Status = v.Status;
		m_TargetPos.FromPB(v.TargetPos);
		m_ObjData = v.ObjData;
		m_Motion.FromPB(v.Motion);
		m_IsNew = v.IsNew;
		m_SkillPrepareId = v.SkillPrepareId;
		m_SkillPrepareTime = v.SkillPrepareTime;
		m_LoopSkillId = v.LoopSkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ObjCreateInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ObjCreateInfo pb = ProtoBuf.Serializer.Deserialize<ObjCreateInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
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
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//目标点（针对npc）
	public Vector3Wraper m_TargetPos;
	public Vector3Wraper TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}
	//Obj 数据
	public byte[] m_ObjData;
	public byte[] ObjData
	{
		get { return m_ObjData;}
		set { m_ObjData = value; }
	}
	//移动信息
	public MotionInfoWraper m_Motion;
	public MotionInfoWraper Motion
	{
		get { return m_Motion;}
		set { m_Motion = value; }
	}
	//是否为新创建的obj
	public bool m_IsNew;
	public bool IsNew
	{
		get { return m_IsNew;}
		set { m_IsNew = value; }
	}
	//蓄力技能Id
	public int m_SkillPrepareId;
	public int SkillPrepareId
	{
		get { return m_SkillPrepareId;}
		set { m_SkillPrepareId = value; }
	}
	//蓄力技能时间
	public int m_SkillPrepareTime;
	public int SkillPrepareTime
	{
		get { return m_SkillPrepareTime;}
		set { m_SkillPrepareTime = value; }
	}
	//循环动作技能Id
	public int m_LoopSkillId;
	public int LoopSkillId
	{
		get { return m_LoopSkillId;}
		set { m_LoopSkillId = value; }
	}


};
//删除obj所需信息封装类
[System.Serializable]
public class ObjDeleteInfoWraper
{

	//构造函数
	public ObjDeleteInfoWraper()
	{
		 m_ObjId = 0;
		 m_SceneId = -1;
		 m_ObjData = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_SceneId = -1;
		 m_ObjData = new byte[0];

	}

 	//转化成Protobuffer类型函数
	public ObjDeleteInfo ToPB()
	{
		ObjDeleteInfo v = new ObjDeleteInfo();
		v.ObjId = m_ObjId;
		v.SceneId = m_SceneId;
		v.ObjData = m_ObjData;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ObjDeleteInfo v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_SceneId = v.SceneId;
		m_ObjData = v.ObjData;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ObjDeleteInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ObjDeleteInfo pb = ProtoBuf.Serializer.Deserialize<ObjDeleteInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//obj id
	public UInt64 m_ObjId;
	public UInt64 ObjId
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
	//obj数据
	public byte[] m_ObjData;
	public byte[] ObjData
	{
		get { return m_ObjData;}
		set { m_ObjData = value; }
	}


};
//MatchLimit封装类
[System.Serializable]
public class MatchLimitWraper
{

	//构造函数
	public MatchLimitWraper()
	{
		 m_MinIntegral = 0;
		 m_MinSection = 0;
		 m_MinLevel = 0;
		 m_MaxLevel = 0;
		 m_MaxIntegral = 0;
		 m_MaxSection = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MinIntegral = 0;
		 m_MinSection = 0;
		 m_MinLevel = 0;
		 m_MaxLevel = 0;
		 m_MaxIntegral = 0;
		 m_MaxSection = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchLimit ToPB()
	{
		MatchLimit v = new MatchLimit();
		v.MinIntegral = m_MinIntegral;
		v.MinSection = m_MinSection;
		v.MinLevel = m_MinLevel;
		v.MaxLevel = m_MaxLevel;
		v.MaxIntegral = m_MaxIntegral;
		v.MaxSection = m_MaxSection;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchLimit v)
	{
        if (v == null)
            return;
		m_MinIntegral = v.MinIntegral;
		m_MinSection = v.MinSection;
		m_MinLevel = v.MinLevel;
		m_MaxLevel = v.MaxLevel;
		m_MaxIntegral = v.MaxIntegral;
		m_MaxSection = v.MaxSection;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchLimit>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchLimit pb = ProtoBuf.Serializer.Deserialize<MatchLimit>(protoMS);
		FromPB(pb);
		return true;
	}

	//最小积分
	public int m_MinIntegral;
	public int MinIntegral
	{
		get { return m_MinIntegral;}
		set { m_MinIntegral = value; }
	}
	//最小段位
	public int m_MinSection;
	public int MinSection
	{
		get { return m_MinSection;}
		set { m_MinSection = value; }
	}
	//最低等级
	public int m_MinLevel;
	public int MinLevel
	{
		get { return m_MinLevel;}
		set { m_MinLevel = value; }
	}
	//最高等级
	public int m_MaxLevel;
	public int MaxLevel
	{
		get { return m_MaxLevel;}
		set { m_MaxLevel = value; }
	}
	//最大积分
	public int m_MaxIntegral;
	public int MaxIntegral
	{
		get { return m_MaxIntegral;}
		set { m_MaxIntegral = value; }
	}
	//最大段位
	public int m_MaxSection;
	public int MaxSection
	{
		get { return m_MaxSection;}
		set { m_MaxSection = value; }
	}


};
//排位匹配条件封装类
[System.Serializable]
public class MatchRankInfoWraper
{

	//构造函数
	public MatchRankInfoWraper()
	{
		 m_Integral = 0;
		 m_Section = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Integral = 0;
		 m_Section = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchRankInfo ToPB()
	{
		MatchRankInfo v = new MatchRankInfo();
		v.Integral = m_Integral;
		v.Section = m_Section;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchRankInfo v)
	{
        if (v == null)
            return;
		m_Integral = v.Integral;
		m_Section = v.Section;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchRankInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchRankInfo pb = ProtoBuf.Serializer.Deserialize<MatchRankInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//积分
	public int m_Integral;
	public int Integral
	{
		get { return m_Integral;}
		set { m_Integral = value; }
	}
	//段位
	public int m_Section;
	public int Section
	{
		get { return m_Section;}
		set { m_Section = value; }
	}


};
//进入的目标封装类
[System.Serializable]
public class MatchTargetInfoWraper
{

	//构造函数
	public MatchTargetInfoWraper()
	{
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;
		 m_SceneType = 0;
		 m_MirrorConfigId = -1;
		 m_Starbattleid = -1;
		 m_FuntionId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;
		 m_SceneType = 0;
		 m_MirrorConfigId = -1;
		 m_Starbattleid = -1;
		 m_FuntionId = 0;

	}

 	//转化成Protobuffer类型函数
	public MatchTargetInfo ToPB()
	{
		MatchTargetInfo v = new MatchTargetInfo();
		v.DungeonConfigId = m_DungeonConfigId;
		v.SceneConfigId = m_SceneConfigId;
		v.SceneType = m_SceneType;
		v.MirrorConfigId = m_MirrorConfigId;
		v.Starbattleid = m_Starbattleid;
		v.FuntionId = m_FuntionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchTargetInfo v)
	{
        if (v == null)
            return;
		m_DungeonConfigId = v.DungeonConfigId;
		m_SceneConfigId = v.SceneConfigId;
		m_SceneType = v.SceneType;
		m_MirrorConfigId = v.MirrorConfigId;
		m_Starbattleid = v.Starbattleid;
		m_FuntionId = v.FuntionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchTargetInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MatchTargetInfo pb = ProtoBuf.Serializer.Deserialize<MatchTargetInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//副本id
	public int m_DungeonConfigId;
	public int DungeonConfigId
	{
		get { return m_DungeonConfigId;}
		set { m_DungeonConfigId = value; }
	}
	//场景配置Id
	public int m_SceneConfigId;
	public int SceneConfigId
	{
		get { return m_SceneConfigId;}
		set { m_SceneConfigId = value; }
	}
	//副本类型
	public int m_SceneType;
	public int SceneType
	{
		get { return m_SceneType;}
		set { m_SceneType = value; }
	}
	//镜像id
	public int m_MirrorConfigId;
	public int MirrorConfigId
	{
		get { return m_MirrorConfigId;}
		set { m_MirrorConfigId = value; }
	}
	//星耀NPCid
	public int m_Starbattleid;
	public int Starbattleid
	{
		get { return m_Starbattleid;}
		set { m_Starbattleid = value; }
	}
	//FuntionId
	public int m_FuntionId;
	public int FuntionId
	{
		get { return m_FuntionId;}
		set { m_FuntionId = value; }
	}


};
//活动时间信息封装类
[System.Serializable]
public class ActivityTimeWraper
{

	//构造函数
	public ActivityTimeWraper()
	{
		 m_Begin = -1;
		 m_End = -1;
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Begin = -1;
		 m_End = -1;
		 m_Id = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityTime ToPB()
	{
		ActivityTime v = new ActivityTime();
		v.Begin = m_Begin;
		v.End = m_End;
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityTime v)
	{
        if (v == null)
            return;
		m_Begin = v.Begin;
		m_End = v.End;
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityTime>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityTime pb = ProtoBuf.Serializer.Deserialize<ActivityTime>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动开始时间
	public int m_Begin;
	public int Begin
	{
		get { return m_Begin;}
		set { m_Begin = value; }
	}
	//活动结束时间
	public int m_End;
	public int End
	{
		get { return m_End;}
		set { m_End = value; }
	}
	//活动id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
//专精信息封装类
[System.Serializable]
public class ProfessionInfoWraper
{

	//构造函数
	public ProfessionInfoWraper()
	{
		 m_Index = -1;
		m_SkillList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		m_SkillList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ProfessionInfo ToPB()
	{
		ProfessionInfo v = new ProfessionInfo();
		v.Index = m_Index;
		for (int i=0; i<(int)m_SkillList.Count; i++)
			v.SkillList.Add( m_SkillList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ProfessionInfo v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_SkillList.Clear();
		for( int i=0; i<v.SkillList.Count; i++)
			m_SkillList.Add(v.SkillList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ProfessionInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ProfessionInfo pb = ProtoBuf.Serializer.Deserialize<ProfessionInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//技能列表
	public List<int> m_SkillList;
	public int SizeSkillList()
	{
		return m_SkillList.Count;
	}
	public List<int> GetSkillList()
	{
		return m_SkillList;
	}
	public int GetSkillList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return -1;
		return m_SkillList[Index];
	}
	public void SetSkillList( List<int> v )
	{
		m_SkillList=v;
	}
	public void SetSkillList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return;
		m_SkillList[Index] = v;
	}
	public void AddSkillList( int v=-1 )
	{
		m_SkillList.Add(v);
	}
	public void ClearSkillList( )
	{
		m_SkillList.Clear();
	}


};
//运营登录封装类
[System.Serializable]
public class SpecLoginRewardWraper
{

	//构造函数
	public SpecLoginRewardWraper()
	{
		 m_Index = -1;
		 m_Get = -1;
		 m_SetTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_Get = -1;
		 m_SetTime = -1;

	}

 	//转化成Protobuffer类型函数
	public SpecLoginReward ToPB()
	{
		SpecLoginReward v = new SpecLoginReward();
		v.Index = m_Index;
		v.Get = m_Get;
		v.SetTime = m_SetTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SpecLoginReward v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_Get = v.Get;
		m_SetTime = v.SetTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SpecLoginReward>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SpecLoginReward pb = ProtoBuf.Serializer.Deserialize<SpecLoginReward>(protoMS);
		FromPB(pb);
		return true;
	}

	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//是否领取0未领取1领取
	public int m_Get;
	public int Get
	{
		get { return m_Get;}
		set { m_Get = value; }
	}
	//设置时间
	public Int64 m_SetTime;
	public Int64 SetTime
	{
		get { return m_SetTime;}
		set { m_SetTime = value; }
	}


};
//运营活动登录信息封装类
[System.Serializable]
public class SpecLoginInfoWraper
{

	//构造函数
	public SpecLoginInfoWraper()
	{
		 m_Id = -1;
		m_RewardInfo = new List<SpecLoginRewardWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		m_RewardInfo = new List<SpecLoginRewardWraper>();

	}

 	//转化成Protobuffer类型函数
	public SpecLoginInfo ToPB()
	{
		SpecLoginInfo v = new SpecLoginInfo();
		v.Id = m_Id;
		for (int i=0; i<(int)m_RewardInfo.Count; i++)
			v.RewardInfo.Add( m_RewardInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SpecLoginInfo v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_RewardInfo.Clear();
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo.Add( new SpecLoginRewardWraper());
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo[i].FromPB(v.RewardInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SpecLoginInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SpecLoginInfo pb = ProtoBuf.Serializer.Deserialize<SpecLoginInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//领奖信息
	public List<SpecLoginRewardWraper> m_RewardInfo;
	public int SizeRewardInfo()
	{
		return m_RewardInfo.Count;
	}
	public List<SpecLoginRewardWraper> GetRewardInfo()
	{
		return m_RewardInfo;
	}
	public SpecLoginRewardWraper GetRewardInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_RewardInfo.Count)
			return new SpecLoginRewardWraper();
		return m_RewardInfo[Index];
	}
	public void SetRewardInfo( List<SpecLoginRewardWraper> v )
	{
		m_RewardInfo=v;
	}
	public void SetRewardInfo( int Index, SpecLoginRewardWraper v )
	{
		if(Index<0 || Index>=(int)m_RewardInfo.Count)
			return;
		m_RewardInfo[Index] = v;
	}
	public void AddRewardInfo( SpecLoginRewardWraper v )
	{
		m_RewardInfo.Add(v);
	}
	public void ClearRewardInfo( )
	{
		m_RewardInfo.Clear();
	}


};
//聊天联系人数据封装类
[System.Serializable]
public class ContactsChatMsgWraper
{

	//构造函数
	public ContactsChatMsgWraper()
	{
		 m_RoleId = 0;
		 m_HasNewMsg = false;
		m_CharInfoList = new List<ChatInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_HasNewMsg = false;
		m_CharInfoList = new List<ChatInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public ContactsChatMsg ToPB()
	{
		ContactsChatMsg v = new ContactsChatMsg();
		v.RoleId = m_RoleId;
		v.HasNewMsg = m_HasNewMsg;
		for (int i=0; i<(int)m_CharInfoList.Count; i++)
			v.CharInfoList.Add( m_CharInfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ContactsChatMsg v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_HasNewMsg = v.HasNewMsg;
		m_CharInfoList.Clear();
		for( int i=0; i<v.CharInfoList.Count; i++)
			m_CharInfoList.Add( new ChatInfoWraper());
		for( int i=0; i<v.CharInfoList.Count; i++)
			m_CharInfoList[i].FromPB(v.CharInfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ContactsChatMsg>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ContactsChatMsg pb = ProtoBuf.Serializer.Deserialize<ContactsChatMsg>(protoMS);
		FromPB(pb);
		return true;
	}

	//聊天Id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//HasNewMsg
	public bool m_HasNewMsg;
	public bool HasNewMsg
	{
		get { return m_HasNewMsg;}
		set { m_HasNewMsg = value; }
	}
	//聊天信息
	public List<ChatInfoWraper> m_CharInfoList;
	public int SizeCharInfoList()
	{
		return m_CharInfoList.Count;
	}
	public List<ChatInfoWraper> GetCharInfoList()
	{
		return m_CharInfoList;
	}
	public ChatInfoWraper GetCharInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_CharInfoList.Count)
			return new ChatInfoWraper();
		return m_CharInfoList[Index];
	}
	public void SetCharInfoList( List<ChatInfoWraper> v )
	{
		m_CharInfoList=v;
	}
	public void SetCharInfoList( int Index, ChatInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_CharInfoList.Count)
			return;
		m_CharInfoList[Index] = v;
	}
	public void AddCharInfoList( ChatInfoWraper v )
	{
		m_CharInfoList.Add(v);
	}
	public void ClearCharInfoList( )
	{
		m_CharInfoList.Clear();
	}


};
//整形坐标 需要除100封装类
[System.Serializable]
public class Vector3IntWraper
{

	//构造函数
	public Vector3IntWraper()
	{
		 m_X = -1;
		 m_Z = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = -1;
		 m_Z = -1;

	}

 	//转化成Protobuffer类型函数
	public Vector3Int ToPB()
	{
		Vector3Int v = new Vector3Int();
		v.X = m_X;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(Vector3Int v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<Vector3Int>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		Vector3Int pb = ProtoBuf.Serializer.Deserialize<Vector3Int>(protoMS);
		FromPB(pb);
		return true;
	}

	//X
	public int m_X;
	public int X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Z
	public int m_Z;
	public int Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//拼接字符串封装类
[System.Serializable]
public class AppendStringWraper
{

	//构造函数
	public AppendStringWraper()
	{
		 m_TransID = -1;
		 m_Key = -1;
		m_StringList = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TransID = -1;
		 m_Key = -1;
		m_StringList = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public AppendString ToPB()
	{
		AppendString v = new AppendString();
		v.TransID = m_TransID;
		v.Key = m_Key;
		for (int i=0; i<(int)m_StringList.Count; i++)
			v.StringList.Add( m_StringList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AppendString v)
	{
        if (v == null)
            return;
		m_TransID = v.TransID;
		m_Key = v.Key;
		m_StringList.Clear();
		for( int i=0; i<v.StringList.Count; i++)
			m_StringList.Add(v.StringList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AppendString>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AppendString pb = ProtoBuf.Serializer.Deserialize<AppendString>(protoMS);
		FromPB(pb);
		return true;
	}

	//transid
	public int m_TransID;
	public int TransID
	{
		get { return m_TransID;}
		set { m_TransID = value; }
	}
	//key
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//StringList
	public List<string> m_StringList;
	public int SizeStringList()
	{
		return m_StringList.Count;
	}
	public List<string> GetStringList()
	{
		return m_StringList;
	}
	public string GetStringList(int Index)
	{
		if(Index<0 || Index>=(int)m_StringList.Count)
			return "";
		return m_StringList[Index];
	}
	public void SetStringList( List<string> v )
	{
		m_StringList=v;
	}
	public void SetStringList( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_StringList.Count)
			return;
		m_StringList[Index] = v;
	}
	public void AddStringList( string v )
	{
		m_StringList.Add(v);
	}
	public void ClearStringList( )
	{
		m_StringList.Clear();
	}


};
//拼接字符串List封装类
[System.Serializable]
public class AppendStringListWraper
{

	//构造函数
	public AppendStringListWraper()
	{
		m_StringAppendList = new List<AppendStringWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_StringAppendList = new List<AppendStringWraper>();

	}

 	//转化成Protobuffer类型函数
	public AppendStringList ToPB()
	{
		AppendStringList v = new AppendStringList();
		for (int i=0; i<(int)m_StringAppendList.Count; i++)
			v.StringAppendList.Add( m_StringAppendList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AppendStringList v)
	{
        if (v == null)
            return;
		m_StringAppendList.Clear();
		for( int i=0; i<v.StringAppendList.Count; i++)
			m_StringAppendList.Add( new AppendStringWraper());
		for( int i=0; i<v.StringAppendList.Count; i++)
			m_StringAppendList[i].FromPB(v.StringAppendList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AppendStringList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		AppendStringList pb = ProtoBuf.Serializer.Deserialize<AppendStringList>(protoMS);
		FromPB(pb);
		return true;
	}

	//拼接字符串
	public List<AppendStringWraper> m_StringAppendList;
	public int SizeStringAppendList()
	{
		return m_StringAppendList.Count;
	}
	public List<AppendStringWraper> GetStringAppendList()
	{
		return m_StringAppendList;
	}
	public AppendStringWraper GetStringAppendList(int Index)
	{
		if(Index<0 || Index>=(int)m_StringAppendList.Count)
			return new AppendStringWraper();
		return m_StringAppendList[Index];
	}
	public void SetStringAppendList( List<AppendStringWraper> v )
	{
		m_StringAppendList=v;
	}
	public void SetStringAppendList( int Index, AppendStringWraper v )
	{
		if(Index<0 || Index>=(int)m_StringAppendList.Count)
			return;
		m_StringAppendList[Index] = v;
	}
	public void AddStringAppendList( AppendStringWraper v )
	{
		m_StringAppendList.Add(v);
	}
	public void ClearStringAppendList( )
	{
		m_StringAppendList.Clear();
	}


};
//星耀玩家信息封装类
[System.Serializable]
public class StarBattlePlayerInfoWraper
{

	//构造函数
	public StarBattlePlayerInfoWraper()
	{
		 m_Playerguid = 0;
		 m_Playername = "";
		 m_Level = -1;
		 m_RoleID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Playerguid = 0;
		 m_Playername = "";
		 m_Level = -1;
		 m_RoleID = -1;

	}

 	//转化成Protobuffer类型函数
	public StarBattlePlayerInfo ToPB()
	{
		StarBattlePlayerInfo v = new StarBattlePlayerInfo();
		v.Playerguid = m_Playerguid;
		v.Playername = m_Playername;
		v.Level = m_Level;
		v.RoleID = m_RoleID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(StarBattlePlayerInfo v)
	{
        if (v == null)
            return;
		m_Playerguid = v.Playerguid;
		m_Playername = v.Playername;
		m_Level = v.Level;
		m_RoleID = v.RoleID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<StarBattlePlayerInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		StarBattlePlayerInfo pb = ProtoBuf.Serializer.Deserialize<StarBattlePlayerInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//playerguid
	public UInt64 m_Playerguid;
	public UInt64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//playername
	public string m_Playername;
	public string Playername
	{
		get { return m_Playername;}
		set { m_Playername = value; }
	}
	//Level
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//RoleID
	public int m_RoleID;
	public int RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}


};
//星耀信息封装类
[System.Serializable]
public class StarBattleInfoWraper
{

	//构造函数
	public StarBattleInfoWraper()
	{
		 m_ServerFast = new StarBattleTeamInfoWraper();
		 m_ServerFirst = new StarBattleTeamInfoWraper();
		 m_ServerWeekFast = new StarBattleTeamInfoWraper();
		 m_Id = -1;
		 m_Npcid = -1;
		 m_LeftCount = -1;
		 m_Incount = 0;
		 m_Wincount = 0;
		 m_Npcindex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ServerFast = new StarBattleTeamInfoWraper();
		 m_ServerFirst = new StarBattleTeamInfoWraper();
		 m_ServerWeekFast = new StarBattleTeamInfoWraper();
		 m_Id = -1;
		 m_Npcid = -1;
		 m_LeftCount = -1;
		 m_Incount = 0;
		 m_Wincount = 0;
		 m_Npcindex = -1;

	}

 	//转化成Protobuffer类型函数
	public StarBattleInfo ToPB()
	{
		StarBattleInfo v = new StarBattleInfo();
		v.ServerFast = m_ServerFast.ToPB();
		v.ServerFirst = m_ServerFirst.ToPB();
		v.ServerWeekFast = m_ServerWeekFast.ToPB();
		v.Id = m_Id;
		v.Npcid = m_Npcid;
		v.LeftCount = m_LeftCount;
		v.Incount = m_Incount;
		v.Wincount = m_Wincount;
		v.Npcindex = m_Npcindex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(StarBattleInfo v)
	{
        if (v == null)
            return;
		m_ServerFast.FromPB(v.ServerFast);
		m_ServerFirst.FromPB(v.ServerFirst);
		m_ServerWeekFast.FromPB(v.ServerWeekFast);
		m_Id = v.Id;
		m_Npcid = v.Npcid;
		m_LeftCount = v.LeftCount;
		m_Incount = v.Incount;
		m_Wincount = v.Wincount;
		m_Npcindex = v.Npcindex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<StarBattleInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		StarBattleInfo pb = ProtoBuf.Serializer.Deserialize<StarBattleInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//本服最快通关(不用了)
	public StarBattleTeamInfoWraper m_ServerFast;
	public StarBattleTeamInfoWraper ServerFast
	{
		get { return m_ServerFast;}
		set { m_ServerFast = value; }
	}
	//本服首通(不用了)
	public StarBattleTeamInfoWraper m_ServerFirst;
	public StarBattleTeamInfoWraper ServerFirst
	{
		get { return m_ServerFirst;}
		set { m_ServerFirst = value; }
	}
	//本周最快(不用了)
	public StarBattleTeamInfoWraper m_ServerWeekFast;
	public StarBattleTeamInfoWraper ServerWeekFast
	{
		get { return m_ServerWeekFast;}
		set { m_ServerWeekFast = value; }
	}
	//id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//NPCID
	public int m_Npcid;
	public int Npcid
	{
		get { return m_Npcid;}
		set { m_Npcid = value; }
	}
	//星耀剩余次数（不用了）
	public int m_LeftCount;
	public int LeftCount
	{
		get { return m_LeftCount;}
		set { m_LeftCount = value; }
	}
	//当前进入镜像的队伍数
	public int m_Incount;
	public int Incount
	{
		get { return m_Incount;}
		set { m_Incount = value; }
	}
	//已经胜利的队伍数
	public int m_Wincount;
	public int Wincount
	{
		get { return m_Wincount;}
		set { m_Wincount = value; }
	}
	//第几个NPC
	public int m_Npcindex;
	public int Npcindex
	{
		get { return m_Npcindex;}
		set { m_Npcindex = value; }
	}


};
//星耀通关队伍信息封装类
[System.Serializable]
public class StarBattleTeamInfoWraper
{

	//构造函数
	public StarBattleTeamInfoWraper()
	{
		 m_PassTime = -1;
		 m_PassUseTime = -1;
		m_MemberInfo = new List<StarBattlePlayerInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PassTime = -1;
		 m_PassUseTime = -1;
		m_MemberInfo = new List<StarBattlePlayerInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public StarBattleTeamInfo ToPB()
	{
		StarBattleTeamInfo v = new StarBattleTeamInfo();
		v.PassTime = m_PassTime;
		v.PassUseTime = m_PassUseTime;
		for (int i=0; i<(int)m_MemberInfo.Count; i++)
			v.MemberInfo.Add( m_MemberInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(StarBattleTeamInfo v)
	{
        if (v == null)
            return;
		m_PassTime = v.PassTime;
		m_PassUseTime = v.PassUseTime;
		m_MemberInfo.Clear();
		for( int i=0; i<v.MemberInfo.Count; i++)
			m_MemberInfo.Add( new StarBattlePlayerInfoWraper());
		for( int i=0; i<v.MemberInfo.Count; i++)
			m_MemberInfo[i].FromPB(v.MemberInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<StarBattleTeamInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		StarBattleTeamInfo pb = ProtoBuf.Serializer.Deserialize<StarBattleTeamInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//通关时间
	public Int64 m_PassTime;
	public Int64 PassTime
	{
		get { return m_PassTime;}
		set { m_PassTime = value; }
	}
	//通关用时
	public int m_PassUseTime;
	public int PassUseTime
	{
		get { return m_PassUseTime;}
		set { m_PassUseTime = value; }
	}
	//通关队员信息
	public List<StarBattlePlayerInfoWraper> m_MemberInfo;
	public int SizeMemberInfo()
	{
		return m_MemberInfo.Count;
	}
	public List<StarBattlePlayerInfoWraper> GetMemberInfo()
	{
		return m_MemberInfo;
	}
	public StarBattlePlayerInfoWraper GetMemberInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_MemberInfo.Count)
			return new StarBattlePlayerInfoWraper();
		return m_MemberInfo[Index];
	}
	public void SetMemberInfo( List<StarBattlePlayerInfoWraper> v )
	{
		m_MemberInfo=v;
	}
	public void SetMemberInfo( int Index, StarBattlePlayerInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_MemberInfo.Count)
			return;
		m_MemberInfo[Index] = v;
	}
	public void AddMemberInfo( StarBattlePlayerInfoWraper v )
	{
		m_MemberInfo.Add(v);
	}
	public void ClearMemberInfo( )
	{
		m_MemberInfo.Clear();
	}


};
//ObjPosInfo封装类
[System.Serializable]
public class ObjPosInfoWraper
{

	//构造函数
	public ObjPosInfoWraper()
	{
		 m_ObjId = 0;
		 m_Id = -1;
		 m_X = -1;
		 m_Z = -1;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = 0;
		 m_Id = -1;
		 m_X = -1;
		 m_Z = -1;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public ObjPosInfo ToPB()
	{
		ObjPosInfo v = new ObjPosInfo();
		v.ObjId = m_ObjId;
		v.Id = m_Id;
		v.X = m_X;
		v.Z = m_Z;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ObjPosInfo v)
	{
        if (v == null)
            return;
		m_ObjId = v.ObjId;
		m_Id = v.Id;
		m_X = v.X;
		m_Z = v.Z;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ObjPosInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ObjPosInfo pb = ProtoBuf.Serializer.Deserialize<ObjPosInfo>(protoMS);
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
	//Id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//z
	public int m_X;
	public int X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//z
	public int m_Z;
	public int Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//类型(1eventobj,2creature)
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//队伍快速刷新信息封装类
[System.Serializable]
public class TeamMemberHpInfoWraper
{

	//构造函数
	public TeamMemberHpInfoWraper()
	{
		 m_Hp = -1;
		 m_MaxHp = -1;
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Hp = -1;
		 m_MaxHp = -1;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamMemberHpInfo ToPB()
	{
		TeamMemberHpInfo v = new TeamMemberHpInfo();
		v.Hp = m_Hp;
		v.MaxHp = m_MaxHp;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamMemberHpInfo v)
	{
        if (v == null)
            return;
		m_Hp = v.Hp;
		m_MaxHp = v.MaxHp;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamMemberHpInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamMemberHpInfo pb = ProtoBuf.Serializer.Deserialize<TeamMemberHpInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//生命值
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//生命值
	public Int64 m_MaxHp;
	public Int64 MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}
	//队员RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//队伍位置封装类
[System.Serializable]
public class TeamMemberPosWraper
{

	//构造函数
	public TeamMemberPosWraper()
	{
		 m_Pos = new Vector3Wraper();
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = new Vector3Wraper();
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamMemberPos ToPB()
	{
		TeamMemberPos v = new TeamMemberPos();
		v.Pos = m_Pos.ToPB();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamMemberPos v)
	{
        if (v == null)
            return;
		m_Pos.FromPB(v.Pos);
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamMemberPos>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamMemberPos pb = ProtoBuf.Serializer.Deserialize<TeamMemberPos>(protoMS);
		FromPB(pb);
		return true;
	}

	//Pos
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//队员RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//队伍bufflist封装类
[System.Serializable]
public class TeanMemberBuffWraper
{

	//构造函数
	public TeanMemberBuffWraper()
	{
		 m_RoleId = 0;
		m_BuffIdList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		m_BuffIdList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public TeanMemberBuff ToPB()
	{
		TeanMemberBuff v = new TeanMemberBuff();
		v.RoleId = m_RoleId;
		for (int i=0; i<(int)m_BuffIdList.Count; i++)
			v.BuffIdList.Add( m_BuffIdList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeanMemberBuff v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_BuffIdList.Clear();
		for( int i=0; i<v.BuffIdList.Count; i++)
			m_BuffIdList.Add(v.BuffIdList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeanMemberBuff>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeanMemberBuff pb = ProtoBuf.Serializer.Deserialize<TeanMemberBuff>(protoMS);
		FromPB(pb);
		return true;
	}

	//队员RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//buff
	public List<int> m_BuffIdList;
	public int SizeBuffIdList()
	{
		return m_BuffIdList.Count;
	}
	public List<int> GetBuffIdList()
	{
		return m_BuffIdList;
	}
	public int GetBuffIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_BuffIdList.Count)
			return -1;
		return m_BuffIdList[Index];
	}
	public void SetBuffIdList( List<int> v )
	{
		m_BuffIdList=v;
	}
	public void SetBuffIdList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_BuffIdList.Count)
			return;
		m_BuffIdList[Index] = v;
	}
	public void AddBuffIdList( int v=-1 )
	{
		m_BuffIdList.Add(v);
	}
	public void ClearBuffIdList( )
	{
		m_BuffIdList.Clear();
	}


};
//队伍专精目标封装类
[System.Serializable]
public class TeamProfessionTargetWraper
{

	//构造函数
	public TeamProfessionTargetWraper()
	{
		 m_ProfessionId = -1;
		 m_Size = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ProfessionId = -1;
		 m_Size = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamProfessionTarget ToPB()
	{
		TeamProfessionTarget v = new TeamProfessionTarget();
		v.ProfessionId = m_ProfessionId;
		v.Size = m_Size;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamProfessionTarget v)
	{
        if (v == null)
            return;
		m_ProfessionId = v.ProfessionId;
		m_Size = v.Size;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamProfessionTarget>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TeamProfessionTarget pb = ProtoBuf.Serializer.Deserialize<TeamProfessionTarget>(protoMS);
		FromPB(pb);
		return true;
	}

	//专精id
	public int m_ProfessionId;
	public int ProfessionId
	{
		get { return m_ProfessionId;}
		set { m_ProfessionId = value; }
	}
	//个数
	public int m_Size;
	public int Size
	{
		get { return m_Size;}
		set { m_Size = value; }
	}


};
//资源找回信息封装类
[System.Serializable]
public class RewardRecoveryInfoWraper
{

	//构造函数
	public RewardRecoveryInfoWraper()
	{
		 m_Id = -1;
		m_ItemNormal = new List<RewardRecoveryItemWraper>();
		m_ItemPerfect = new List<RewardRecoveryItemWraper>();
		 m_NormalState = 0;
		 m_PerfectState = -1;
		 m_CostItemNormal = new RewardRecoveryItemWraper();
		 m_CostItemPerfect = new RewardRecoveryItemWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		m_ItemNormal = new List<RewardRecoveryItemWraper>();
		m_ItemPerfect = new List<RewardRecoveryItemWraper>();
		 m_NormalState = 0;
		 m_PerfectState = -1;
		 m_CostItemNormal = new RewardRecoveryItemWraper();
		 m_CostItemPerfect = new RewardRecoveryItemWraper();

	}

 	//转化成Protobuffer类型函数
	public RewardRecoveryInfo ToPB()
	{
		RewardRecoveryInfo v = new RewardRecoveryInfo();
		v.Id = m_Id;
		for (int i=0; i<(int)m_ItemNormal.Count; i++)
			v.ItemNormal.Add( m_ItemNormal[i].ToPB());
		for (int i=0; i<(int)m_ItemPerfect.Count; i++)
			v.ItemPerfect.Add( m_ItemPerfect[i].ToPB());
		v.NormalState = m_NormalState;
		v.PerfectState = m_PerfectState;
		v.CostItemNormal = m_CostItemNormal.ToPB();
		v.CostItemPerfect = m_CostItemPerfect.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RewardRecoveryInfo v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_ItemNormal.Clear();
		for( int i=0; i<v.ItemNormal.Count; i++)
			m_ItemNormal.Add( new RewardRecoveryItemWraper());
		for( int i=0; i<v.ItemNormal.Count; i++)
			m_ItemNormal[i].FromPB(v.ItemNormal[i]);
		m_ItemPerfect.Clear();
		for( int i=0; i<v.ItemPerfect.Count; i++)
			m_ItemPerfect.Add( new RewardRecoveryItemWraper());
		for( int i=0; i<v.ItemPerfect.Count; i++)
			m_ItemPerfect[i].FromPB(v.ItemPerfect[i]);
		m_NormalState = v.NormalState;
		m_PerfectState = v.PerfectState;
		m_CostItemNormal.FromPB(v.CostItemNormal);
		m_CostItemPerfect.FromPB(v.CostItemPerfect);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RewardRecoveryInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RewardRecoveryInfo pb = ProtoBuf.Serializer.Deserialize<RewardRecoveryInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//资源找回ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//普通找回物品
	public List<RewardRecoveryItemWraper> m_ItemNormal;
	public int SizeItemNormal()
	{
		return m_ItemNormal.Count;
	}
	public List<RewardRecoveryItemWraper> GetItemNormal()
	{
		return m_ItemNormal;
	}
	public RewardRecoveryItemWraper GetItemNormal(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemNormal.Count)
			return new RewardRecoveryItemWraper();
		return m_ItemNormal[Index];
	}
	public void SetItemNormal( List<RewardRecoveryItemWraper> v )
	{
		m_ItemNormal=v;
	}
	public void SetItemNormal( int Index, RewardRecoveryItemWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemNormal.Count)
			return;
		m_ItemNormal[Index] = v;
	}
	public void AddItemNormal( RewardRecoveryItemWraper v )
	{
		m_ItemNormal.Add(v);
	}
	public void ClearItemNormal( )
	{
		m_ItemNormal.Clear();
	}
	//完美找回物品
	public List<RewardRecoveryItemWraper> m_ItemPerfect;
	public int SizeItemPerfect()
	{
		return m_ItemPerfect.Count;
	}
	public List<RewardRecoveryItemWraper> GetItemPerfect()
	{
		return m_ItemPerfect;
	}
	public RewardRecoveryItemWraper GetItemPerfect(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemPerfect.Count)
			return new RewardRecoveryItemWraper();
		return m_ItemPerfect[Index];
	}
	public void SetItemPerfect( List<RewardRecoveryItemWraper> v )
	{
		m_ItemPerfect=v;
	}
	public void SetItemPerfect( int Index, RewardRecoveryItemWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemPerfect.Count)
			return;
		m_ItemPerfect[Index] = v;
	}
	public void AddItemPerfect( RewardRecoveryItemWraper v )
	{
		m_ItemPerfect.Add(v);
	}
	public void ClearItemPerfect( )
	{
		m_ItemPerfect.Clear();
	}
	//找回状态普通
	public int m_NormalState;
	public int NormalState
	{
		get { return m_NormalState;}
		set { m_NormalState = value; }
	}
	//找回状态完美
	public int m_PerfectState;
	public int PerfectState
	{
		get { return m_PerfectState;}
		set { m_PerfectState = value; }
	}
	//找回消耗类型普通
	public RewardRecoveryItemWraper m_CostItemNormal;
	public RewardRecoveryItemWraper CostItemNormal
	{
		get { return m_CostItemNormal;}
		set { m_CostItemNormal = value; }
	}
	//找回消耗类型完美
	public RewardRecoveryItemWraper m_CostItemPerfect;
	public RewardRecoveryItemWraper CostItemPerfect
	{
		get { return m_CostItemPerfect;}
		set { m_CostItemPerfect = value; }
	}


};
//奖励找回物品信息封装类
[System.Serializable]
public class RewardRecoveryItemWraper
{

	//构造函数
	public RewardRecoveryItemWraper()
	{
		 m_ItemID = -1;
		 m_ItemNum = -1;
		 m_ItemType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemID = -1;
		 m_ItemNum = -1;
		 m_ItemType = 0;

	}

 	//转化成Protobuffer类型函数
	public RewardRecoveryItem ToPB()
	{
		RewardRecoveryItem v = new RewardRecoveryItem();
		v.ItemID = m_ItemID;
		v.ItemNum = m_ItemNum;
		v.ItemType = m_ItemType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RewardRecoveryItem v)
	{
        if (v == null)
            return;
		m_ItemID = v.ItemID;
		m_ItemNum = v.ItemNum;
		m_ItemType = v.ItemType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RewardRecoveryItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RewardRecoveryItem pb = ProtoBuf.Serializer.Deserialize<RewardRecoveryItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//物品个数
	public int m_ItemNum;
	public int ItemNum
	{
		get { return m_ItemNum;}
		set { m_ItemNum = value; }
	}
	//掉落类型
	public int m_ItemType;
	public int ItemType
	{
		get { return m_ItemType;}
		set { m_ItemType = value; }
	}


};
//轮盘数据封装类
[System.Serializable]
public class ExpressionWheelInfoWraper
{

	//构造函数
	public ExpressionWheelInfoWraper()
	{
		 m_Index = -1;
		 m_ActionID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_ActionID = -1;

	}

 	//转化成Protobuffer类型函数
	public ExpressionWheelInfo ToPB()
	{
		ExpressionWheelInfo v = new ExpressionWheelInfo();
		v.Index = m_Index;
		v.ActionID = m_ActionID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExpressionWheelInfo v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_ActionID = v.ActionID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExpressionWheelInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExpressionWheelInfo pb = ProtoBuf.Serializer.Deserialize<ExpressionWheelInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//ID
	public int m_ActionID;
	public int ActionID
	{
		get { return m_ActionID;}
		set { m_ActionID = value; }
	}


};
//副本奖励数据封装类
[System.Serializable]
public class PBUIRewardDataWraper
{

	//构造函数
	public PBUIRewardDataWraper()
	{
		 m_ItemId = 0;
		 m_ItemCount = 0;
		 m_RoleId = 0;
		 m_PlayerName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = 0;
		 m_ItemCount = 0;
		 m_RoleId = 0;
		 m_PlayerName = "";

	}

 	//转化成Protobuffer类型函数
	public PBUIRewardData ToPB()
	{
		PBUIRewardData v = new PBUIRewardData();
		v.ItemId = m_ItemId;
		v.ItemCount = m_ItemCount;
		v.RoleId = m_RoleId;
		v.PlayerName = m_PlayerName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PBUIRewardData v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_ItemCount = v.ItemCount;
		m_RoleId = v.RoleId;
		m_PlayerName = v.PlayerName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PBUIRewardData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PBUIRewardData pb = ProtoBuf.Serializer.Deserialize<PBUIRewardData>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品id
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//物品数量
	public int m_ItemCount;
	public int ItemCount
	{
		get { return m_ItemCount;}
		set { m_ItemCount = value; }
	}
	//玩家唯一id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//玩家名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}


};
//魂石套装封装类
[System.Serializable]
public class SoulStoneSuitWraper
{

	//构造函数
	public SoulStoneSuitWraper()
	{
		 m_SoulInfo = new SuitInfoWraper();
		m_StoneInfo = new List<SoulStoneDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SoulInfo = new SuitInfoWraper();
		m_StoneInfo = new List<SoulStoneDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public SoulStoneSuit ToPB()
	{
		SoulStoneSuit v = new SoulStoneSuit();
		v.SoulInfo = m_SoulInfo.ToPB();
		for (int i=0; i<(int)m_StoneInfo.Count; i++)
			v.StoneInfo.Add( m_StoneInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SoulStoneSuit v)
	{
        if (v == null)
            return;
		m_SoulInfo.FromPB(v.SoulInfo);
		m_StoneInfo.Clear();
		for( int i=0; i<v.StoneInfo.Count; i++)
			m_StoneInfo.Add( new SoulStoneDataWraper());
		for( int i=0; i<v.StoneInfo.Count; i++)
			m_StoneInfo[i].FromPB(v.StoneInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SoulStoneSuit>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SoulStoneSuit pb = ProtoBuf.Serializer.Deserialize<SoulStoneSuit>(protoMS);
		FromPB(pb);
		return true;
	}

	//套装信息
	public SuitInfoWraper m_SoulInfo;
	public SuitInfoWraper SoulInfo
	{
		get { return m_SoulInfo;}
		set { m_SoulInfo = value; }
	}
	//魂石数据
	public List<SoulStoneDataWraper> m_StoneInfo;
	public int SizeStoneInfo()
	{
		return m_StoneInfo.Count;
	}
	public List<SoulStoneDataWraper> GetStoneInfo()
	{
		return m_StoneInfo;
	}
	public SoulStoneDataWraper GetStoneInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_StoneInfo.Count)
			return new SoulStoneDataWraper();
		return m_StoneInfo[Index];
	}
	public void SetStoneInfo( List<SoulStoneDataWraper> v )
	{
		m_StoneInfo=v;
	}
	public void SetStoneInfo( int Index, SoulStoneDataWraper v )
	{
		if(Index<0 || Index>=(int)m_StoneInfo.Count)
			return;
		m_StoneInfo[Index] = v;
	}
	public void AddStoneInfo( SoulStoneDataWraper v )
	{
		m_StoneInfo.Add(v);
	}
	public void ClearStoneInfo( )
	{
		m_StoneInfo.Clear();
	}


};
//魂石数据封装类
[System.Serializable]
public class SoulStoneDataWraper
{

	//构造函数
	public SoulStoneDataWraper()
	{
		m_Attr = new List<AttrKeyValueWraper>();
		 m_SuitId = -1;
		 m_BattleScore = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Attr = new List<AttrKeyValueWraper>();
		 m_SuitId = -1;
		 m_BattleScore = 0;

	}

 	//转化成Protobuffer类型函数
	public SoulStoneData ToPB()
	{
		SoulStoneData v = new SoulStoneData();
		for (int i=0; i<(int)m_Attr.Count; i++)
			v.Attr.Add( m_Attr[i].ToPB());
		v.SuitId = m_SuitId;
		v.BattleScore = m_BattleScore;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SoulStoneData v)
	{
        if (v == null)
            return;
		m_Attr.Clear();
		for( int i=0; i<v.Attr.Count; i++)
			m_Attr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.Attr.Count; i++)
			m_Attr[i].FromPB(v.Attr[i]);
		m_SuitId = v.SuitId;
		m_BattleScore = v.BattleScore;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SoulStoneData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SoulStoneData pb = ProtoBuf.Serializer.Deserialize<SoulStoneData>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性
	public List<AttrKeyValueWraper> m_Attr;
	public int SizeAttr()
	{
		return m_Attr.Count;
	}
	public List<AttrKeyValueWraper> GetAttr()
	{
		return m_Attr;
	}
	public AttrKeyValueWraper GetAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_Attr.Count)
			return new AttrKeyValueWraper();
		return m_Attr[Index];
	}
	public void SetAttr( List<AttrKeyValueWraper> v )
	{
		m_Attr=v;
	}
	public void SetAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_Attr.Count)
			return;
		m_Attr[Index] = v;
	}
	public void AddAttr( AttrKeyValueWraper v )
	{
		m_Attr.Add(v);
	}
	public void ClearAttr( )
	{
		m_Attr.Clear();
	}
	//套装id
	public int m_SuitId;
	public int SuitId
	{
		get { return m_SuitId;}
		set { m_SuitId = value; }
	}
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}


};
//公会BOSS排行榜信息封装类
[System.Serializable]
public class GuildBossRankInfoWraper
{

	//构造函数
	public GuildBossRankInfoWraper()
	{
		 m_Playerguid = 0;
		 m_Configid = -1;
		 m_Playername = "";
		 m_Score = -1;
		 m_Rank = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Playerguid = 0;
		 m_Configid = -1;
		 m_Playername = "";
		 m_Score = -1;
		 m_Rank = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildBossRankInfo ToPB()
	{
		GuildBossRankInfo v = new GuildBossRankInfo();
		v.Playerguid = m_Playerguid;
		v.Configid = m_Configid;
		v.Playername = m_Playername;
		v.Score = m_Score;
		v.Rank = m_Rank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildBossRankInfo v)
	{
        if (v == null)
            return;
		m_Playerguid = v.Playerguid;
		m_Configid = v.Configid;
		m_Playername = v.Playername;
		m_Score = v.Score;
		m_Rank = v.Rank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildBossRankInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildBossRankInfo pb = ProtoBuf.Serializer.Deserialize<GuildBossRankInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//playerguid
	public UInt64 m_Playerguid;
	public UInt64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//role表configid
	public int m_Configid;
	public int Configid
	{
		get { return m_Configid;}
		set { m_Configid = value; }
	}
	//playername
	public string m_Playername;
	public string Playername
	{
		get { return m_Playername;}
		set { m_Playername = value; }
	}
	//伤害
	public int m_Score;
	public int Score
	{
		get { return m_Score;}
		set { m_Score = value; }
	}
	//排名
	public int m_Rank;
	public int Rank
	{
		get { return m_Rank;}
		set { m_Rank = value; }
	}


};
//行当任务信息封装类
[System.Serializable]
public class BusinessQuestInfoWraper
{

	//构造函数
	public BusinessQuestInfoWraper()
	{
		 m_NpcID = -1;
		 m_QuestID = -1;
		m_ItemList = new List<BusinessQuestItemWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NpcID = -1;
		 m_QuestID = -1;
		m_ItemList = new List<BusinessQuestItemWraper>();

	}

 	//转化成Protobuffer类型函数
	public BusinessQuestInfo ToPB()
	{
		BusinessQuestInfo v = new BusinessQuestInfo();
		v.NpcID = m_NpcID;
		v.QuestID = m_QuestID;
		for (int i=0; i<(int)m_ItemList.Count; i++)
			v.ItemList.Add( m_ItemList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BusinessQuestInfo v)
	{
        if (v == null)
            return;
		m_NpcID = v.NpcID;
		m_QuestID = v.QuestID;
		m_ItemList.Clear();
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList.Add( new BusinessQuestItemWraper());
		for( int i=0; i<v.ItemList.Count; i++)
			m_ItemList[i].FromPB(v.ItemList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BusinessQuestInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BusinessQuestInfo pb = ProtoBuf.Serializer.Deserialize<BusinessQuestInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//NPCID
	public int m_NpcID;
	public int NpcID
	{
		get { return m_NpcID;}
		set { m_NpcID = value; }
	}
	//任务ID
	public int m_QuestID;
	public int QuestID
	{
		get { return m_QuestID;}
		set { m_QuestID = value; }
	}
	//需要提交的道具列表
	public List<BusinessQuestItemWraper> m_ItemList;
	public int SizeItemList()
	{
		return m_ItemList.Count;
	}
	public List<BusinessQuestItemWraper> GetItemList()
	{
		return m_ItemList;
	}
	public BusinessQuestItemWraper GetItemList(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return new BusinessQuestItemWraper();
		return m_ItemList[Index];
	}
	public void SetItemList( List<BusinessQuestItemWraper> v )
	{
		m_ItemList=v;
	}
	public void SetItemList( int Index, BusinessQuestItemWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemList.Count)
			return;
		m_ItemList[Index] = v;
	}
	public void AddItemList( BusinessQuestItemWraper v )
	{
		m_ItemList.Add(v);
	}
	public void ClearItemList( )
	{
		m_ItemList.Clear();
	}


};
//行当数据封装类
[System.Serializable]
public class BusinessQuestDataWraper
{

	//构造函数
	public BusinessQuestDataWraper()
	{
		 m_BusinessQuestInfo = new BusinessQuestInfoWraper();
		 m_CompleteCount = -1;
		 m_ResetCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BusinessQuestInfo = new BusinessQuestInfoWraper();
		 m_CompleteCount = -1;
		 m_ResetCount = -1;

	}

 	//转化成Protobuffer类型函数
	public BusinessQuestData ToPB()
	{
		BusinessQuestData v = new BusinessQuestData();
		v.BusinessQuestInfo = m_BusinessQuestInfo.ToPB();
		v.CompleteCount = m_CompleteCount;
		v.ResetCount = m_ResetCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BusinessQuestData v)
	{
        if (v == null)
            return;
		m_BusinessQuestInfo.FromPB(v.BusinessQuestInfo);
		m_CompleteCount = v.CompleteCount;
		m_ResetCount = v.ResetCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BusinessQuestData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BusinessQuestData pb = ProtoBuf.Serializer.Deserialize<BusinessQuestData>(protoMS);
		FromPB(pb);
		return true;
	}

	//当前任务的信息
	public BusinessQuestInfoWraper m_BusinessQuestInfo;
	public BusinessQuestInfoWraper BusinessQuestInfo
	{
		get { return m_BusinessQuestInfo;}
		set { m_BusinessQuestInfo = value; }
	}
	//完成次数
	public int m_CompleteCount;
	public int CompleteCount
	{
		get { return m_CompleteCount;}
		set { m_CompleteCount = value; }
	}
	//重置次数
	public int m_ResetCount;
	public int ResetCount
	{
		get { return m_ResetCount;}
		set { m_ResetCount = value; }
	}


};
//行当道具信息封装类
[System.Serializable]
public class BusinessQuestItemWraper
{

	//构造函数
	public BusinessQuestItemWraper()
	{
		 m_ItemID = -1;
		 m_Count = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemID = -1;
		 m_Count = -1;

	}

 	//转化成Protobuffer类型函数
	public BusinessQuestItem ToPB()
	{
		BusinessQuestItem v = new BusinessQuestItem();
		v.ItemID = m_ItemID;
		v.Count = m_Count;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BusinessQuestItem v)
	{
        if (v == null)
            return;
		m_ItemID = v.ItemID;
		m_Count = v.Count;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BusinessQuestItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BusinessQuestItem pb = ProtoBuf.Serializer.Deserialize<BusinessQuestItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//需求数量
	public int m_Count;
	public int Count
	{
		get { return m_Count;}
		set { m_Count = value; }
	}


};
//实时副本战绩数据封装类
[System.Serializable]
public class PlayerRealTimeExploitWraper
{

	//构造函数
	public PlayerRealTimeExploitWraper()
	{
		 m_RoleId = 0;
		 m_PlayerLevel = 0;
		 m_PlayerName = "";
		 m_Occupation = 0;
		 m_ExploitsValue = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_PlayerLevel = 0;
		 m_PlayerName = "";
		 m_Occupation = 0;
		 m_ExploitsValue = 0;

	}

 	//转化成Protobuffer类型函数
	public PlayerRealTimeExploit ToPB()
	{
		PlayerRealTimeExploit v = new PlayerRealTimeExploit();
		v.RoleId = m_RoleId;
		v.PlayerLevel = m_PlayerLevel;
		v.PlayerName = m_PlayerName;
		v.Occupation = m_Occupation;
		v.ExploitsValue = m_ExploitsValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PlayerRealTimeExploit v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_PlayerLevel = v.PlayerLevel;
		m_PlayerName = v.PlayerName;
		m_Occupation = v.Occupation;
		m_ExploitsValue = v.ExploitsValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PlayerRealTimeExploit>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PlayerRealTimeExploit pb = ProtoBuf.Serializer.Deserialize<PlayerRealTimeExploit>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//玩家等级
	public int m_PlayerLevel;
	public int PlayerLevel
	{
		get { return m_PlayerLevel;}
		set { m_PlayerLevel = value; }
	}
	//玩家名字
	public string m_PlayerName;
	public string PlayerName
	{
		get { return m_PlayerName;}
		set { m_PlayerName = value; }
	}
	//职业
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}
	//数据
	public int m_ExploitsValue;
	public int ExploitsValue
	{
		get { return m_ExploitsValue;}
		set { m_ExploitsValue = value; }
	}


};
//实时战绩封装类
[System.Serializable]
public class RealTimeExploitsWraper
{

	//构造函数
	public RealTimeExploitsWraper()
	{
		m_PlayerList = new List<PlayerRealTimeExploitWraper>();
		 m_ExploitsType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		m_PlayerList = new List<PlayerRealTimeExploitWraper>();
		 m_ExploitsType = 0;

	}

 	//转化成Protobuffer类型函数
	public RealTimeExploits ToPB()
	{
		RealTimeExploits v = new RealTimeExploits();
		for (int i=0; i<(int)m_PlayerList.Count; i++)
			v.PlayerList.Add( m_PlayerList[i].ToPB());
		v.ExploitsType = m_ExploitsType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RealTimeExploits v)
	{
        if (v == null)
            return;
		m_PlayerList.Clear();
		for( int i=0; i<v.PlayerList.Count; i++)
			m_PlayerList.Add( new PlayerRealTimeExploitWraper());
		for( int i=0; i<v.PlayerList.Count; i++)
			m_PlayerList[i].FromPB(v.PlayerList[i]);
		m_ExploitsType = v.ExploitsType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RealTimeExploits>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RealTimeExploits pb = ProtoBuf.Serializer.Deserialize<RealTimeExploits>(protoMS);
		FromPB(pb);
		return true;
	}

	//数据
	public List<PlayerRealTimeExploitWraper> m_PlayerList;
	public int SizePlayerList()
	{
		return m_PlayerList.Count;
	}
	public List<PlayerRealTimeExploitWraper> GetPlayerList()
	{
		return m_PlayerList;
	}
	public PlayerRealTimeExploitWraper GetPlayerList(int Index)
	{
		if(Index<0 || Index>=(int)m_PlayerList.Count)
			return new PlayerRealTimeExploitWraper();
		return m_PlayerList[Index];
	}
	public void SetPlayerList( List<PlayerRealTimeExploitWraper> v )
	{
		m_PlayerList=v;
	}
	public void SetPlayerList( int Index, PlayerRealTimeExploitWraper v )
	{
		if(Index<0 || Index>=(int)m_PlayerList.Count)
			return;
		m_PlayerList[Index] = v;
	}
	public void AddPlayerList( PlayerRealTimeExploitWraper v )
	{
		m_PlayerList.Add(v);
	}
	public void ClearPlayerList( )
	{
		m_PlayerList.Clear();
	}
	//数据
	public int m_ExploitsType;
	public int ExploitsType
	{
		get { return m_ExploitsType;}
		set { m_ExploitsType = value; }
	}


};
//移动信息封装类
[System.Serializable]
public class MotionInfoWraper
{

	//构造函数
	public MotionInfoWraper()
	{
		 m_MotionType = -1;
		m_MotionPath = new List<Vector3IntWraper>();
		 m_IsAllowChangeRunAnimation = false;
		 m_IsFollow = false;
		 m_IsLookAtMoving = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MotionType = -1;
		m_MotionPath = new List<Vector3IntWraper>();
		 m_IsAllowChangeRunAnimation = false;
		 m_IsFollow = false;
		 m_IsLookAtMoving = false;

	}

 	//转化成Protobuffer类型函数
	public MotionInfo ToPB()
	{
		MotionInfo v = new MotionInfo();
		v.MotionType = m_MotionType;
		for (int i=0; i<(int)m_MotionPath.Count; i++)
			v.MotionPath.Add( m_MotionPath[i].ToPB());
		v.IsAllowChangeRunAnimation = m_IsAllowChangeRunAnimation;
		v.IsFollow = m_IsFollow;
		v.IsLookAtMoving = m_IsLookAtMoving;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MotionInfo v)
	{
        if (v == null)
            return;
		m_MotionType = v.MotionType;
		m_MotionPath.Clear();
		for( int i=0; i<v.MotionPath.Count; i++)
			m_MotionPath.Add( new Vector3IntWraper());
		for( int i=0; i<v.MotionPath.Count; i++)
			m_MotionPath[i].FromPB(v.MotionPath[i]);
		m_IsAllowChangeRunAnimation = v.IsAllowChangeRunAnimation;
		m_IsFollow = v.IsFollow;
		m_IsLookAtMoving = v.IsLookAtMoving;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MotionInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MotionInfo pb = ProtoBuf.Serializer.Deserialize<MotionInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//移动类型
	public int m_MotionType;
	public int MotionType
	{
		get { return m_MotionType;}
		set { m_MotionType = value; }
	}
	//移动路点
	public List<Vector3IntWraper> m_MotionPath;
	public int SizeMotionPath()
	{
		return m_MotionPath.Count;
	}
	public List<Vector3IntWraper> GetMotionPath()
	{
		return m_MotionPath;
	}
	public Vector3IntWraper GetMotionPath(int Index)
	{
		if(Index<0 || Index>=(int)m_MotionPath.Count)
			return new Vector3IntWraper();
		return m_MotionPath[Index];
	}
	public void SetMotionPath( List<Vector3IntWraper> v )
	{
		m_MotionPath=v;
	}
	public void SetMotionPath( int Index, Vector3IntWraper v )
	{
		if(Index<0 || Index>=(int)m_MotionPath.Count)
			return;
		m_MotionPath[Index] = v;
	}
	public void AddMotionPath( Vector3IntWraper v )
	{
		m_MotionPath.Add(v);
	}
	public void ClearMotionPath( )
	{
		m_MotionPath.Clear();
	}
	//是否允许改变动画
	public bool m_IsAllowChangeRunAnimation;
	public bool IsAllowChangeRunAnimation
	{
		get { return m_IsAllowChangeRunAnimation;}
		set { m_IsAllowChangeRunAnimation = value; }
	}
	//是否跟随状态
	public bool m_IsFollow;
	public bool IsFollow
	{
		get { return m_IsFollow;}
		set { m_IsFollow = value; }
	}
	//是否朝向移动目标点
	public bool m_IsLookAtMoving;
	public bool IsLookAtMoving
	{
		get { return m_IsLookAtMoving;}
		set { m_IsLookAtMoving = value; }
	}


};
//副本战绩封装类
[System.Serializable]
public class DungeonExploitsWraper
{

	//构造函数
	public DungeonExploitsWraper()
	{
		m_Exploits = new List<RealTimeExploitsWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_Exploits = new List<RealTimeExploitsWraper>();

	}

 	//转化成Protobuffer类型函数
	public DungeonExploits ToPB()
	{
		DungeonExploits v = new DungeonExploits();
		for (int i=0; i<(int)m_Exploits.Count; i++)
			v.Exploits.Add( m_Exploits[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonExploits v)
	{
        if (v == null)
            return;
		m_Exploits.Clear();
		for( int i=0; i<v.Exploits.Count; i++)
			m_Exploits.Add( new RealTimeExploitsWraper());
		for( int i=0; i<v.Exploits.Count; i++)
			m_Exploits[i].FromPB(v.Exploits[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonExploits>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonExploits pb = ProtoBuf.Serializer.Deserialize<DungeonExploits>(protoMS);
		FromPB(pb);
		return true;
	}

	//战绩数据
	public List<RealTimeExploitsWraper> m_Exploits;
	public int SizeExploits()
	{
		return m_Exploits.Count;
	}
	public List<RealTimeExploitsWraper> GetExploits()
	{
		return m_Exploits;
	}
	public RealTimeExploitsWraper GetExploits(int Index)
	{
		if(Index<0 || Index>=(int)m_Exploits.Count)
			return new RealTimeExploitsWraper();
		return m_Exploits[Index];
	}
	public void SetExploits( List<RealTimeExploitsWraper> v )
	{
		m_Exploits=v;
	}
	public void SetExploits( int Index, RealTimeExploitsWraper v )
	{
		if(Index<0 || Index>=(int)m_Exploits.Count)
			return;
		m_Exploits[Index] = v;
	}
	public void AddExploits( RealTimeExploitsWraper v )
	{
		m_Exploits.Add(v);
	}
	public void ClearExploits( )
	{
		m_Exploits.Clear();
	}


};
//兑换活动信息封装类
[System.Serializable]
public class ExchangeInfoWraper
{

	//构造函数
	public ExchangeInfoWraper()
	{
		 m_ConfId = -1;
		 m_ExchangeCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfId = -1;
		 m_ExchangeCount = -1;

	}

 	//转化成Protobuffer类型函数
	public ExchangeInfo ToPB()
	{
		ExchangeInfo v = new ExchangeInfo();
		v.ConfId = m_ConfId;
		v.ExchangeCount = m_ExchangeCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ExchangeInfo v)
	{
        if (v == null)
            return;
		m_ConfId = v.ConfId;
		m_ExchangeCount = v.ExchangeCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ExchangeInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ExchangeInfo pb = ProtoBuf.Serializer.Deserialize<ExchangeInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//兑换项Id
	public int m_ConfId;
	public int ConfId
	{
		get { return m_ConfId;}
		set { m_ConfId = value; }
	}
	//兑换次数
	public int m_ExchangeCount;
	public int ExchangeCount
	{
		get { return m_ExchangeCount;}
		set { m_ExchangeCount = value; }
	}


};
//星耀NPCinfo封装类
[System.Serializable]
public class StarBattleNPCWraper
{

	//构造函数
	public StarBattleNPCWraper()
	{
		 m_Id = -1;
		 m_Waypointid = -1;
		 m_Index = -1;
		 m_Incount = 0;
		 m_Wincount = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Waypointid = -1;
		 m_Index = -1;
		 m_Incount = 0;
		 m_Wincount = 0;

	}

 	//转化成Protobuffer类型函数
	public StarBattleNPC ToPB()
	{
		StarBattleNPC v = new StarBattleNPC();
		v.Id = m_Id;
		v.Waypointid = m_Waypointid;
		v.Index = m_Index;
		v.Incount = m_Incount;
		v.Wincount = m_Wincount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(StarBattleNPC v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Waypointid = v.Waypointid;
		m_Index = v.Index;
		m_Incount = v.Incount;
		m_Wincount = v.Wincount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<StarBattleNPC>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		StarBattleNPC pb = ProtoBuf.Serializer.Deserialize<StarBattleNPC>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//waypointid(不用了)
	public int m_Waypointid;
	public int Waypointid
	{
		get { return m_Waypointid;}
		set { m_Waypointid = value; }
	}
	//index(星耀表里第几个NPC)
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//进入的队伍数
	public int m_Incount;
	public int Incount
	{
		get { return m_Incount;}
		set { m_Incount = value; }
	}
	//胜利的队伍数
	public int m_Wincount;
	public int Wincount
	{
		get { return m_Wincount;}
		set { m_Wincount = value; }
	}


};
//技能cd数据封装类
[System.Serializable]
public class SkillCDInfoWraper
{

	//构造函数
	public SkillCDInfoWraper()
	{
		 m_SkillId = -1;
		 m_SurplusTime = -1;
		 m_CommonSurplusTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillId = -1;
		 m_SurplusTime = -1;
		 m_CommonSurplusTime = -1;

	}

 	//转化成Protobuffer类型函数
	public SkillCDInfo ToPB()
	{
		SkillCDInfo v = new SkillCDInfo();
		v.SkillId = m_SkillId;
		v.SurplusTime = m_SurplusTime;
		v.CommonSurplusTime = m_CommonSurplusTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillCDInfo v)
	{
        if (v == null)
            return;
		m_SkillId = v.SkillId;
		m_SurplusTime = v.SurplusTime;
		m_CommonSurplusTime = v.CommonSurplusTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillCDInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillCDInfo pb = ProtoBuf.Serializer.Deserialize<SkillCDInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能Id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//剩余CD时间
	public int m_SurplusTime;
	public int SurplusTime
	{
		get { return m_SurplusTime;}
		set { m_SurplusTime = value; }
	}
	//公共CD剩余时间
	public int m_CommonSurplusTime;
	public int CommonSurplusTime
	{
		get { return m_CommonSurplusTime;}
		set { m_CommonSurplusTime = value; }
	}


};
//捏脸数据结构封装类
[System.Serializable]
public class PinchFaceDataWraper
{

	//构造函数
	public PinchFaceDataWraper()
	{
		m_DataInfo = new List<PinchFaceBaseWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_DataInfo = new List<PinchFaceBaseWraper>();

	}

 	//转化成Protobuffer类型函数
	public PinchFaceData ToPB()
	{
		PinchFaceData v = new PinchFaceData();
		for (int i=0; i<(int)m_DataInfo.Count; i++)
			v.DataInfo.Add( m_DataInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PinchFaceData v)
	{
        if (v == null)
            return;
		m_DataInfo.Clear();
		for( int i=0; i<v.DataInfo.Count; i++)
			m_DataInfo.Add( new PinchFaceBaseWraper());
		for( int i=0; i<v.DataInfo.Count; i++)
			m_DataInfo[i].FromPB(v.DataInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PinchFaceData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PinchFaceData pb = ProtoBuf.Serializer.Deserialize<PinchFaceData>(protoMS);
		FromPB(pb);
		return true;
	}

	//捏脸数据
	public List<PinchFaceBaseWraper> m_DataInfo;
	public int SizeDataInfo()
	{
		return m_DataInfo.Count;
	}
	public List<PinchFaceBaseWraper> GetDataInfo()
	{
		return m_DataInfo;
	}
	public PinchFaceBaseWraper GetDataInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_DataInfo.Count)
			return new PinchFaceBaseWraper();
		return m_DataInfo[Index];
	}
	public void SetDataInfo( List<PinchFaceBaseWraper> v )
	{
		m_DataInfo=v;
	}
	public void SetDataInfo( int Index, PinchFaceBaseWraper v )
	{
		if(Index<0 || Index>=(int)m_DataInfo.Count)
			return;
		m_DataInfo[Index] = v;
	}
	public void AddDataInfo( PinchFaceBaseWraper v )
	{
		m_DataInfo.Add(v);
	}
	public void ClearDataInfo( )
	{
		m_DataInfo.Clear();
	}


};
//宠物自动转化封装类
[System.Serializable]
public class PetItemAutoBreakInfoWraper
{

	//构造函数
	public PetItemAutoBreakInfoWraper()
	{
		 m_ProtoId = -1;
		 m_BreakType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ProtoId = -1;
		 m_BreakType = -1;

	}

 	//转化成Protobuffer类型函数
	public PetItemAutoBreakInfo ToPB()
	{
		PetItemAutoBreakInfo v = new PetItemAutoBreakInfo();
		v.ProtoId = m_ProtoId;
		v.BreakType = m_BreakType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetItemAutoBreakInfo v)
	{
        if (v == null)
            return;
		m_ProtoId = v.ProtoId;
		m_BreakType = v.BreakType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetItemAutoBreakInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetItemAutoBreakInfo pb = ProtoBuf.Serializer.Deserialize<PetItemAutoBreakInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//宠物类型ID
	public int m_ProtoId;
	public int ProtoId
	{
		get { return m_ProtoId;}
		set { m_ProtoId = value; }
	}
	//转化类型
	public int m_BreakType;
	public int BreakType
	{
		get { return m_BreakType;}
		set { m_BreakType = value; }
	}


};
//捏脸基础结构封装类
[System.Serializable]
public class PinchFaceBaseWraper
{

	//构造函数
	public PinchFaceBaseWraper()
	{
		 m_Id = -1;
		 m_Value = (float)-1;
		 m_Color = new ColorWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Value = (float)-1;
		 m_Color = new ColorWraper();

	}

 	//转化成Protobuffer类型函数
	public PinchFaceBase ToPB()
	{
		PinchFaceBase v = new PinchFaceBase();
		v.Id = m_Id;
		v.Value = m_Value;
		v.Color = m_Color.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PinchFaceBase v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Value = v.Value;
		m_Color.FromPB(v.Color);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PinchFaceBase>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PinchFaceBase pb = ProtoBuf.Serializer.Deserialize<PinchFaceBase>(protoMS);
		FromPB(pb);
		return true;
	}

	//配置id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//值
	public float m_Value;
	public float Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}
	//颜色
	public ColorWraper m_Color;
	public ColorWraper Color
	{
		get { return m_Color;}
		set { m_Color = value; }
	}


};
//颜色封装类
[System.Serializable]
public class ColorWraper
{

	//构造函数
	public ColorWraper()
	{
		 m_R = (float)-1;
		 m_G = (float)-1;
		 m_B = (float)-1;
		 m_A = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_R = (float)-1;
		 m_G = (float)-1;
		 m_B = (float)-1;
		 m_A = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public Color ToPB()
	{
		Color v = new Color();
		v.R = m_R;
		v.G = m_G;
		v.B = m_B;
		v.A = m_A;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(Color v)
	{
        if (v == null)
            return;
		m_R = v.R;
		m_G = v.G;
		m_B = v.B;
		m_A = v.A;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<Color>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		Color pb = ProtoBuf.Serializer.Deserialize<Color>(protoMS);
		FromPB(pb);
		return true;
	}

	//红
	public float m_R;
	public float R
	{
		get { return m_R;}
		set { m_R = value; }
	}
	//绿
	public float m_G;
	public float G
	{
		get { return m_G;}
		set { m_G = value; }
	}
	//蓝
	public float m_B;
	public float B
	{
		get { return m_B;}
		set { m_B = value; }
	}
	//透明度
	public float m_A;
	public float A
	{
		get { return m_A;}
		set { m_A = value; }
	}


};
//称号数据结构封装类
[System.Serializable]
public class CTitleDataWraper
{

	//构造函数
	public CTitleDataWraper()
	{
		 m_TitleId = -1;
		 m_TimeStamp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TitleId = -1;
		 m_TimeStamp = -1;

	}

 	//转化成Protobuffer类型函数
	public CTitleData ToPB()
	{
		CTitleData v = new CTitleData();
		v.TitleId = m_TitleId;
		v.TimeStamp = m_TimeStamp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(CTitleData v)
	{
        if (v == null)
            return;
		m_TitleId = v.TitleId;
		m_TimeStamp = v.TimeStamp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<CTitleData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		CTitleData pb = ProtoBuf.Serializer.Deserialize<CTitleData>(protoMS);
		FromPB(pb);
		return true;
	}

	//称号id
	public int m_TitleId;
	public int TitleId
	{
		get { return m_TitleId;}
		set { m_TitleId = value; }
	}
	//称号过期时间
	public int m_TimeStamp;
	public int TimeStamp
	{
		get { return m_TimeStamp;}
		set { m_TimeStamp = value; }
	}


};
//技能方案信息封装类
[System.Serializable]
public class SkillPlanInfoWraper
{

	//构造函数
	public SkillPlanInfoWraper()
	{
		m_RuneIDList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_RuneIDList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public SkillPlanInfo ToPB()
	{
		SkillPlanInfo v = new SkillPlanInfo();
		for (int i=0; i<(int)m_RuneIDList.Count; i++)
			v.RuneIDList.Add( m_RuneIDList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillPlanInfo v)
	{
        if (v == null)
            return;
		m_RuneIDList.Clear();
		for( int i=0; i<v.RuneIDList.Count; i++)
			m_RuneIDList.Add(v.RuneIDList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillPlanInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillPlanInfo pb = ProtoBuf.Serializer.Deserialize<SkillPlanInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//铭文ID的集合
	public List<int> m_RuneIDList;
	public int SizeRuneIDList()
	{
		return m_RuneIDList.Count;
	}
	public List<int> GetRuneIDList()
	{
		return m_RuneIDList;
	}
	public int GetRuneIDList(int Index)
	{
		if(Index<0 || Index>=(int)m_RuneIDList.Count)
			return -1;
		return m_RuneIDList[Index];
	}
	public void SetRuneIDList( List<int> v )
	{
		m_RuneIDList=v;
	}
	public void SetRuneIDList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_RuneIDList.Count)
			return;
		m_RuneIDList[Index] = v;
	}
	public void AddRuneIDList( int v=-1 )
	{
		m_RuneIDList.Add(v);
	}
	public void ClearRuneIDList( )
	{
		m_RuneIDList.Clear();
	}


};
//时装装备属性封装类
[System.Serializable]
public class TreasureEquipAttrWraper
{

	//构造函数
	public TreasureEquipAttrWraper()
	{
		 m_Key = -1;
		 m_AddType = -1;
		 m_Value = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_AddType = -1;
		 m_Value = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public TreasureEquipAttr ToPB()
	{
		TreasureEquipAttr v = new TreasureEquipAttr();
		v.Key = m_Key;
		v.AddType = m_AddType;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureEquipAttr v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_AddType = v.AddType;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureEquipAttr>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureEquipAttr pb = ProtoBuf.Serializer.Deserialize<TreasureEquipAttr>(protoMS);
		FromPB(pb);
		return true;
	}

	//key
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//加值类型(0:值 1:百分比)
	public int m_AddType;
	public int AddType
	{
		get { return m_AddType;}
		set { m_AddType = value; }
	}
	//value
	public float m_Value;
	public float Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//公会副本玩家数据封装类
[System.Serializable]
public class GuildDungeonPlayerDataWraper
{

	//构造函数
	public GuildDungeonPlayerDataWraper()
	{
		 m_HistoryMaxLayer = 0;
		 m_CurrMaxLayer = 0;
		 m_CurrRewardLayer = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_HistoryMaxLayer = 0;
		 m_CurrMaxLayer = 0;
		 m_CurrRewardLayer = 0;

	}

 	//转化成Protobuffer类型函数
	public GuildDungeonPlayerData ToPB()
	{
		GuildDungeonPlayerData v = new GuildDungeonPlayerData();
		v.HistoryMaxLayer = m_HistoryMaxLayer;
		v.CurrMaxLayer = m_CurrMaxLayer;
		v.CurrRewardLayer = m_CurrRewardLayer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildDungeonPlayerData v)
	{
        if (v == null)
            return;
		m_HistoryMaxLayer = v.HistoryMaxLayer;
		m_CurrMaxLayer = v.CurrMaxLayer;
		m_CurrRewardLayer = v.CurrRewardLayer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildDungeonPlayerData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildDungeonPlayerData pb = ProtoBuf.Serializer.Deserialize<GuildDungeonPlayerData>(protoMS);
		FromPB(pb);
		return true;
	}

	//历史最高层数
	public int m_HistoryMaxLayer;
	public int HistoryMaxLayer
	{
		get { return m_HistoryMaxLayer;}
		set { m_HistoryMaxLayer = value; }
	}
	//当次活动最高层数
	public int m_CurrMaxLayer;
	public int CurrMaxLayer
	{
		get { return m_CurrMaxLayer;}
		set { m_CurrMaxLayer = value; }
	}
	//当次活动领奖层数
	public int m_CurrRewardLayer;
	public int CurrRewardLayer
	{
		get { return m_CurrRewardLayer;}
		set { m_CurrRewardLayer = value; }
	}


};
//公会副本活动数据封装类
[System.Serializable]
public class GuildDungeonActDataWraper
{

	//构造函数
	public GuildDungeonActDataWraper()
	{
		m_LayerInfo = new List<GuildDungeonLayerDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_LayerInfo = new List<GuildDungeonLayerDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public GuildDungeonActData ToPB()
	{
		GuildDungeonActData v = new GuildDungeonActData();
		for (int i=0; i<(int)m_LayerInfo.Count; i++)
			v.LayerInfo.Add( m_LayerInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildDungeonActData v)
	{
        if (v == null)
            return;
		m_LayerInfo.Clear();
		for( int i=0; i<v.LayerInfo.Count; i++)
			m_LayerInfo.Add( new GuildDungeonLayerDataWraper());
		for( int i=0; i<v.LayerInfo.Count; i++)
			m_LayerInfo[i].FromPB(v.LayerInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildDungeonActData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildDungeonActData pb = ProtoBuf.Serializer.Deserialize<GuildDungeonActData>(protoMS);
		FromPB(pb);
		return true;
	}

	//公会副本各层信息
	public List<GuildDungeonLayerDataWraper> m_LayerInfo;
	public int SizeLayerInfo()
	{
		return m_LayerInfo.Count;
	}
	public List<GuildDungeonLayerDataWraper> GetLayerInfo()
	{
		return m_LayerInfo;
	}
	public GuildDungeonLayerDataWraper GetLayerInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_LayerInfo.Count)
			return new GuildDungeonLayerDataWraper();
		return m_LayerInfo[Index];
	}
	public void SetLayerInfo( List<GuildDungeonLayerDataWraper> v )
	{
		m_LayerInfo=v;
	}
	public void SetLayerInfo( int Index, GuildDungeonLayerDataWraper v )
	{
		if(Index<0 || Index>=(int)m_LayerInfo.Count)
			return;
		m_LayerInfo[Index] = v;
	}
	public void AddLayerInfo( GuildDungeonLayerDataWraper v )
	{
		m_LayerInfo.Add(v);
	}
	public void ClearLayerInfo( )
	{
		m_LayerInfo.Clear();
	}


};
//公会副本每层数据封装类
[System.Serializable]
public class GuildDungeonLayerDataWraper
{

	//构造函数
	public GuildDungeonLayerDataWraper()
	{
		 m_LayerIndex = 1;
		 m_GuildName = "";
		 m_PassTeamInfo = new TeamInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LayerIndex = 1;
		 m_GuildName = "";
		 m_PassTeamInfo = new TeamInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public GuildDungeonLayerData ToPB()
	{
		GuildDungeonLayerData v = new GuildDungeonLayerData();
		v.LayerIndex = m_LayerIndex;
		v.GuildName = m_GuildName;
		v.PassTeamInfo = m_PassTeamInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildDungeonLayerData v)
	{
        if (v == null)
            return;
		m_LayerIndex = v.LayerIndex;
		m_GuildName = v.GuildName;
		m_PassTeamInfo.FromPB(v.PassTeamInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildDungeonLayerData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildDungeonLayerData pb = ProtoBuf.Serializer.Deserialize<GuildDungeonLayerData>(protoMS);
		FromPB(pb);
		return true;
	}

	//层数
	public int m_LayerIndex;
	public int LayerIndex
	{
		get { return m_LayerIndex;}
		set { m_LayerIndex = value; }
	}
	//最先通关公会名称
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//最先通关队伍
	public TeamInfoWraper m_PassTeamInfo;
	public TeamInfoWraper PassTeamInfo
	{
		get { return m_PassTeamInfo;}
		set { m_PassTeamInfo = value; }
	}


};
//天赋技能信息封装类
[System.Serializable]
public class TalentSkillInfoWraper
{

	//构造函数
	public TalentSkillInfoWraper()
	{
		 m_TalentSkillId = -1;
		 m_TalentSkillLevelID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TalentSkillId = -1;
		 m_TalentSkillLevelID = -1;

	}

 	//转化成Protobuffer类型函数
	public TalentSkillInfo ToPB()
	{
		TalentSkillInfo v = new TalentSkillInfo();
		v.TalentSkillId = m_TalentSkillId;
		v.TalentSkillLevelID = m_TalentSkillLevelID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TalentSkillInfo v)
	{
        if (v == null)
            return;
		m_TalentSkillId = v.TalentSkillId;
		m_TalentSkillLevelID = v.TalentSkillLevelID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TalentSkillInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TalentSkillInfo pb = ProtoBuf.Serializer.Deserialize<TalentSkillInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//天赋技能ID
	public int m_TalentSkillId;
	public int TalentSkillId
	{
		get { return m_TalentSkillId;}
		set { m_TalentSkillId = value; }
	}
	//天赋技能等级ID
	public int m_TalentSkillLevelID;
	public int TalentSkillLevelID
	{
		get { return m_TalentSkillLevelID;}
		set { m_TalentSkillLevelID = value; }
	}


};
//天赋预设信息封装类
[System.Serializable]
public class TalentPlanInfoWraper
{

	//构造函数
	public TalentPlanInfoWraper()
	{
		 m_TalentDirection = -1;
		m_TalentSkillIdList = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TalentDirection = -1;
		m_TalentSkillIdList = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public TalentPlanInfo ToPB()
	{
		TalentPlanInfo v = new TalentPlanInfo();
		v.TalentDirection = m_TalentDirection;
		for (int i=0; i<(int)m_TalentSkillIdList.Count; i++)
			v.TalentSkillIdList.Add( m_TalentSkillIdList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TalentPlanInfo v)
	{
        if (v == null)
            return;
		m_TalentDirection = v.TalentDirection;
		m_TalentSkillIdList.Clear();
		for( int i=0; i<v.TalentSkillIdList.Count; i++)
			m_TalentSkillIdList.Add(v.TalentSkillIdList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TalentPlanInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TalentPlanInfo pb = ProtoBuf.Serializer.Deserialize<TalentPlanInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//职业方向
	public int m_TalentDirection;
	public int TalentDirection
	{
		get { return m_TalentDirection;}
		set { m_TalentDirection = value; }
	}
	//使用的天赋技能ID
	public List<int> m_TalentSkillIdList;
	public int SizeTalentSkillIdList()
	{
		return m_TalentSkillIdList.Count;
	}
	public List<int> GetTalentSkillIdList()
	{
		return m_TalentSkillIdList;
	}
	public int GetTalentSkillIdList(int Index)
	{
		if(Index<0 || Index>=(int)m_TalentSkillIdList.Count)
			return -1;
		return m_TalentSkillIdList[Index];
	}
	public void SetTalentSkillIdList( List<int> v )
	{
		m_TalentSkillIdList=v;
	}
	public void SetTalentSkillIdList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_TalentSkillIdList.Count)
			return;
		m_TalentSkillIdList[Index] = v;
	}
	public void AddTalentSkillIdList( int v=-1 )
	{
		m_TalentSkillIdList.Add(v);
	}
	public void ClearTalentSkillIdList( )
	{
		m_TalentSkillIdList.Clear();
	}


};
//生活技能数据封装类
[System.Serializable]
public class LifeSkillDataWraper
{

	//构造函数
	public LifeSkillDataWraper()
	{
		 m_SkillID = -1;
		 m_SkillLevel = -1;
		 m_SkillExp = -1;
		m_Formula = new List<LifeFormulaDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillID = -1;
		 m_SkillLevel = -1;
		 m_SkillExp = -1;
		m_Formula = new List<LifeFormulaDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public LifeSkillData ToPB()
	{
		LifeSkillData v = new LifeSkillData();
		v.SkillID = m_SkillID;
		v.SkillLevel = m_SkillLevel;
		v.SkillExp = m_SkillExp;
		for (int i=0; i<(int)m_Formula.Count; i++)
			v.Formula.Add( m_Formula[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LifeSkillData v)
	{
        if (v == null)
            return;
		m_SkillID = v.SkillID;
		m_SkillLevel = v.SkillLevel;
		m_SkillExp = v.SkillExp;
		m_Formula.Clear();
		for( int i=0; i<v.Formula.Count; i++)
			m_Formula.Add( new LifeFormulaDataWraper());
		for( int i=0; i<v.Formula.Count; i++)
			m_Formula[i].FromPB(v.Formula[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LifeSkillData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LifeSkillData pb = ProtoBuf.Serializer.Deserialize<LifeSkillData>(protoMS);
		FromPB(pb);
		return true;
	}

	//生活技能id
	public int m_SkillID;
	public int SkillID
	{
		get { return m_SkillID;}
		set { m_SkillID = value; }
	}
	//生活技能等级
	public int m_SkillLevel;
	public int SkillLevel
	{
		get { return m_SkillLevel;}
		set { m_SkillLevel = value; }
	}
	//生活技能经验
	public int m_SkillExp;
	public int SkillExp
	{
		get { return m_SkillExp;}
		set { m_SkillExp = value; }
	}
	//配方信息
	public List<LifeFormulaDataWraper> m_Formula;
	public int SizeFormula()
	{
		return m_Formula.Count;
	}
	public List<LifeFormulaDataWraper> GetFormula()
	{
		return m_Formula;
	}
	public LifeFormulaDataWraper GetFormula(int Index)
	{
		if(Index<0 || Index>=(int)m_Formula.Count)
			return new LifeFormulaDataWraper();
		return m_Formula[Index];
	}
	public void SetFormula( List<LifeFormulaDataWraper> v )
	{
		m_Formula=v;
	}
	public void SetFormula( int Index, LifeFormulaDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Formula.Count)
			return;
		m_Formula[Index] = v;
	}
	public void AddFormula( LifeFormulaDataWraper v )
	{
		m_Formula.Add(v);
	}
	public void ClearFormula( )
	{
		m_Formula.Clear();
	}


};
//生活配方数据封装类
[System.Serializable]
public class LifeFormulaDataWraper
{

	//构造函数
	public LifeFormulaDataWraper()
	{
		 m_FormulaID = -1;
		 m_LastRefreshTime = -1;
		 m_MakeTimes = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_FormulaID = -1;
		 m_LastRefreshTime = -1;
		 m_MakeTimes = -1;

	}

 	//转化成Protobuffer类型函数
	public LifeFormulaData ToPB()
	{
		LifeFormulaData v = new LifeFormulaData();
		v.FormulaID = m_FormulaID;
		v.LastRefreshTime = m_LastRefreshTime;
		v.MakeTimes = m_MakeTimes;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LifeFormulaData v)
	{
        if (v == null)
            return;
		m_FormulaID = v.FormulaID;
		m_LastRefreshTime = v.LastRefreshTime;
		m_MakeTimes = v.MakeTimes;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LifeFormulaData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LifeFormulaData pb = ProtoBuf.Serializer.Deserialize<LifeFormulaData>(protoMS);
		FromPB(pb);
		return true;
	}

	//配方id
	public int m_FormulaID;
	public int FormulaID
	{
		get { return m_FormulaID;}
		set { m_FormulaID = value; }
	}
	//上次刷新时间
	public int m_LastRefreshTime;
	public int LastRefreshTime
	{
		get { return m_LastRefreshTime;}
		set { m_LastRefreshTime = value; }
	}
	//当前配方制作次数
	public int m_MakeTimes;
	public int MakeTimes
	{
		get { return m_MakeTimes;}
		set { m_MakeTimes = value; }
	}


};
//机器人封装类
[System.Serializable]
public class RobotWraper
{

	//构造函数
	public RobotWraper()
	{
		 m_ConfigID = -1;
		 m_Name = "";
		 m_Level = -1;
		 m_Guid = 0;
		 m_Occupation = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfigID = -1;
		 m_Name = "";
		 m_Level = -1;
		 m_Guid = 0;
		 m_Occupation = -1;

	}

 	//转化成Protobuffer类型函数
	public Robot ToPB()
	{
		Robot v = new Robot();
		v.ConfigID = m_ConfigID;
		v.Name = m_Name;
		v.Level = m_Level;
		v.Guid = m_Guid;
		v.Occupation = m_Occupation;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(Robot v)
	{
        if (v == null)
            return;
		m_ConfigID = v.ConfigID;
		m_Name = v.Name;
		m_Level = v.Level;
		m_Guid = v.Guid;
		m_Occupation = v.Occupation;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<Robot>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		Robot pb = ProtoBuf.Serializer.Deserialize<Robot>(protoMS);
		FromPB(pb);
		return true;
	}

	//配置id
	public int m_ConfigID;
	public int ConfigID
	{
		get { return m_ConfigID;}
		set { m_ConfigID = value; }
	}
	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//roleid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//MT TT DPS
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}


};
//声望数据封装类
[System.Serializable]
public class ReputationInfoPBWraper
{

	//构造函数
	public ReputationInfoPBWraper()
	{
		 m_ID = -1;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ID = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public ReputationInfoPB ToPB()
	{
		ReputationInfoPB v = new ReputationInfoPB();
		v.ID = m_ID;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ReputationInfoPB v)
	{
        if (v == null)
            return;
		m_ID = v.ID;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ReputationInfoPB>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ReputationInfoPB pb = ProtoBuf.Serializer.Deserialize<ReputationInfoPB>(protoMS);
		FromPB(pb);
		return true;
	}

	//声望id
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//声望数值
	public Int64 m_Value;
	public Int64 Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//KeyValue结构封装类
[System.Serializable]
public class KeyValueWraper
{

	//构造函数
	public KeyValueWraper()
	{
		 m_KeyId = -1;
		 m_KeyValue = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_KeyId = -1;
		 m_KeyValue = -1;

	}

 	//转化成Protobuffer类型函数
	public KeyValue ToPB()
	{
		KeyValue v = new KeyValue();
		v.KeyId = m_KeyId;
		v.KeyValue = m_KeyValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(KeyValue v)
	{
        if (v == null)
            return;
		m_KeyId = v.KeyId;
		m_KeyValue = v.KeyValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<KeyValue>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		KeyValue pb = ProtoBuf.Serializer.Deserialize<KeyValue>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_KeyId;
	public int KeyId
	{
		get { return m_KeyId;}
		set { m_KeyId = value; }
	}
	//value
	public int m_KeyValue;
	public int KeyValue
	{
		get { return m_KeyValue;}
		set { m_KeyValue = value; }
	}


};
//召唤物数据封装类
[System.Serializable]
public class SummonDataWraper
{

	//构造函数
	public SummonDataWraper()
	{
		 m_SummonId = -1;
		 m_ExpiredTime = -1;
		 m_Index = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SummonId = -1;
		 m_ExpiredTime = -1;
		 m_Index = -1;

	}

 	//转化成Protobuffer类型函数
	public SummonData ToPB()
	{
		SummonData v = new SummonData();
		v.SummonId = m_SummonId;
		v.ExpiredTime = m_ExpiredTime;
		v.Index = m_Index;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SummonData v)
	{
        if (v == null)
            return;
		m_SummonId = v.SummonId;
		m_ExpiredTime = v.ExpiredTime;
		m_Index = v.Index;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SummonData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SummonData pb = ProtoBuf.Serializer.Deserialize<SummonData>(protoMS);
		FromPB(pb);
		return true;
	}

	//召唤表id
	public int m_SummonId;
	public int SummonId
	{
		get { return m_SummonId;}
		set { m_SummonId = value; }
	}
	//到期时间
	public Int64 m_ExpiredTime;
	public Int64 ExpiredTime
	{
		get { return m_ExpiredTime;}
		set { m_ExpiredTime = value; }
	}
	//召唤索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}


};
//分解列表封装类
[System.Serializable]
public class ItemResolveDataListWraper
{

	//构造函数
	public ItemResolveDataListWraper()
	{
		m_ResolveList = new List<ResolveUnitWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ResolveList = new List<ResolveUnitWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemResolveDataList ToPB()
	{
		ItemResolveDataList v = new ItemResolveDataList();
		for (int i=0; i<(int)m_ResolveList.Count; i++)
			v.ResolveList.Add( m_ResolveList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemResolveDataList v)
	{
        if (v == null)
            return;
		m_ResolveList.Clear();
		for( int i=0; i<v.ResolveList.Count; i++)
			m_ResolveList.Add( new ResolveUnitWraper());
		for( int i=0; i<v.ResolveList.Count; i++)
			m_ResolveList[i].FromPB(v.ResolveList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemResolveDataList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemResolveDataList pb = ProtoBuf.Serializer.Deserialize<ItemResolveDataList>(protoMS);
		FromPB(pb);
		return true;
	}

	//分解数据列表
	public List<ResolveUnitWraper> m_ResolveList;
	public int SizeResolveList()
	{
		return m_ResolveList.Count;
	}
	public List<ResolveUnitWraper> GetResolveList()
	{
		return m_ResolveList;
	}
	public ResolveUnitWraper GetResolveList(int Index)
	{
		if(Index<0 || Index>=(int)m_ResolveList.Count)
			return new ResolveUnitWraper();
		return m_ResolveList[Index];
	}
	public void SetResolveList( List<ResolveUnitWraper> v )
	{
		m_ResolveList=v;
	}
	public void SetResolveList( int Index, ResolveUnitWraper v )
	{
		if(Index<0 || Index>=(int)m_ResolveList.Count)
			return;
		m_ResolveList[Index] = v;
	}
	public void AddResolveList( ResolveUnitWraper v )
	{
		m_ResolveList.Add(v);
	}
	public void ClearResolveList( )
	{
		m_ResolveList.Clear();
	}


};
//ResolveUnit封装类
[System.Serializable]
public class ResolveUnitWraper
{

	//构造函数
	public ResolveUnitWraper()
	{
		m_ResolveList = new List<ItemResolveDataWraper>();
		 m_ItemType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_ResolveList = new List<ItemResolveDataWraper>();
		 m_ItemType = -1;

	}

 	//转化成Protobuffer类型函数
	public ResolveUnit ToPB()
	{
		ResolveUnit v = new ResolveUnit();
		for (int i=0; i<(int)m_ResolveList.Count; i++)
			v.ResolveList.Add( m_ResolveList[i].ToPB());
		v.ItemType = m_ItemType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ResolveUnit v)
	{
        if (v == null)
            return;
		m_ResolveList.Clear();
		for( int i=0; i<v.ResolveList.Count; i++)
			m_ResolveList.Add( new ItemResolveDataWraper());
		for( int i=0; i<v.ResolveList.Count; i++)
			m_ResolveList[i].FromPB(v.ResolveList[i]);
		m_ItemType = v.ItemType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ResolveUnit>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ResolveUnit pb = ProtoBuf.Serializer.Deserialize<ResolveUnit>(protoMS);
		FromPB(pb);
		return true;
	}

	//分解数据列表
	public List<ItemResolveDataWraper> m_ResolveList;
	public int SizeResolveList()
	{
		return m_ResolveList.Count;
	}
	public List<ItemResolveDataWraper> GetResolveList()
	{
		return m_ResolveList;
	}
	public ItemResolveDataWraper GetResolveList(int Index)
	{
		if(Index<0 || Index>=(int)m_ResolveList.Count)
			return new ItemResolveDataWraper();
		return m_ResolveList[Index];
	}
	public void SetResolveList( List<ItemResolveDataWraper> v )
	{
		m_ResolveList=v;
	}
	public void SetResolveList( int Index, ItemResolveDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ResolveList.Count)
			return;
		m_ResolveList[Index] = v;
	}
	public void AddResolveList( ItemResolveDataWraper v )
	{
		m_ResolveList.Add(v);
	}
	public void ClearResolveList( )
	{
		m_ResolveList.Clear();
	}
	//物品类型
	public int m_ItemType;
	public int ItemType
	{
		get { return m_ItemType;}
		set { m_ItemType = value; }
	}


};
//世界BOSS得分玩家简要信息封装类
[System.Serializable]
public class WorldBossScoreTinyInfoWraper
{

	//构造函数
	public WorldBossScoreTinyInfoWraper()
	{
		 m_Playerguid = 0;
		 m_Score = -1;
		 m_Damage = 0;
		 m_Capacity = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Playerguid = 0;
		 m_Score = -1;
		 m_Damage = 0;
		 m_Capacity = 0;

	}

 	//转化成Protobuffer类型函数
	public WorldBossScoreTinyInfo ToPB()
	{
		WorldBossScoreTinyInfo v = new WorldBossScoreTinyInfo();
		v.Playerguid = m_Playerguid;
		v.Score = m_Score;
		v.Damage = m_Damage;
		v.Capacity = m_Capacity;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossScoreTinyInfo v)
	{
        if (v == null)
            return;
		m_Playerguid = v.Playerguid;
		m_Score = v.Score;
		m_Damage = v.Damage;
		m_Capacity = v.Capacity;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossScoreTinyInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossScoreTinyInfo pb = ProtoBuf.Serializer.Deserialize<WorldBossScoreTinyInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//playerguid
	public UInt64 m_Playerguid;
	public UInt64 Playerguid
	{
		get { return m_Playerguid;}
		set { m_Playerguid = value; }
	}
	//score
	public int m_Score;
	public int Score
	{
		get { return m_Score;}
		set { m_Score = value; }
	}
	//damage(用于最后一击)
	public int m_Damage;
	public int Damage
	{
		get { return m_Damage;}
		set { m_Damage = value; }
	}
	//战力
	public int m_Capacity;
	public int Capacity
	{
		get { return m_Capacity;}
		set { m_Capacity = value; }
	}


};
//功能和UI开关封装类
[System.Serializable]
public class UICategoryDataWraper
{

	//构造函数
	public UICategoryDataWraper()
	{
		 m_Index = -1;
		 m_Locked = true;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_Locked = true;

	}

 	//转化成Protobuffer类型函数
	public UICategoryData ToPB()
	{
		UICategoryData v = new UICategoryData();
		v.Index = m_Index;
		v.Locked = m_Locked;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(UICategoryData v)
	{
        if (v == null)
            return;
		m_Index = v.Index;
		m_Locked = v.Locked;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<UICategoryData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		UICategoryData pb = ProtoBuf.Serializer.Deserialize<UICategoryData>(protoMS);
		FromPB(pb);
		return true;
	}

	//功能或UI在UICategory中的索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//是否锁定
	public bool m_Locked;
	public bool Locked
	{
		get { return m_Locked;}
		set { m_Locked = value; }
	}


};
//UI和功能开关数据封装类
[System.Serializable]
public class UICategoryDBListWraper
{

	//构造函数
	public UICategoryDBListWraper()
	{
		m_Data = new List<UICategoryDataWraper>();
		 m_OpenAll = false;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Data = new List<UICategoryDataWraper>();
		 m_OpenAll = false;

	}

 	//转化成Protobuffer类型函数
	public UICategoryDBList ToPB()
	{
		UICategoryDBList v = new UICategoryDBList();
		for (int i=0; i<(int)m_Data.Count; i++)
			v.Data.Add( m_Data[i].ToPB());
		v.OpenAll = m_OpenAll;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(UICategoryDBList v)
	{
        if (v == null)
            return;
		m_Data.Clear();
		for( int i=0; i<v.Data.Count; i++)
			m_Data.Add( new UICategoryDataWraper());
		for( int i=0; i<v.Data.Count; i++)
			m_Data[i].FromPB(v.Data[i]);
		m_OpenAll = v.OpenAll;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<UICategoryDBList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		UICategoryDBList pb = ProtoBuf.Serializer.Deserialize<UICategoryDBList>(protoMS);
		FromPB(pb);
		return true;
	}

	//某项UI和功能解锁
	public List<UICategoryDataWraper> m_Data;
	public int SizeData()
	{
		return m_Data.Count;
	}
	public List<UICategoryDataWraper> GetData()
	{
		return m_Data;
	}
	public UICategoryDataWraper GetData(int Index)
	{
		if(Index<0 || Index>=(int)m_Data.Count)
			return new UICategoryDataWraper();
		return m_Data[Index];
	}
	public void SetData( List<UICategoryDataWraper> v )
	{
		m_Data=v;
	}
	public void SetData( int Index, UICategoryDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Data.Count)
			return;
		m_Data[Index] = v;
	}
	public void AddData( UICategoryDataWraper v )
	{
		m_Data.Add(v);
	}
	public void ClearData( )
	{
		m_Data.Clear();
	}
	//是否全开放
	public bool m_OpenAll;
	public bool OpenAll
	{
		get { return m_OpenAll;}
		set { m_OpenAll = value; }
	}


};
//公会货币信息封装类
[System.Serializable]
public class GuildCurrencyWraper
{

	//构造函数
	public GuildCurrencyWraper()
	{
		 m_Currencytype = -1;
		 m_CurrencyChangeNum = -1;
		 m_CurrencyTotalNum = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Currencytype = -1;
		 m_CurrencyChangeNum = -1;
		 m_CurrencyTotalNum = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildCurrency ToPB()
	{
		GuildCurrency v = new GuildCurrency();
		v.Currencytype = m_Currencytype;
		v.CurrencyChangeNum = m_CurrencyChangeNum;
		v.CurrencyTotalNum = m_CurrencyTotalNum;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildCurrency v)
	{
        if (v == null)
            return;
		m_Currencytype = v.Currencytype;
		m_CurrencyChangeNum = v.CurrencyChangeNum;
		m_CurrencyTotalNum = v.CurrencyTotalNum;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildCurrency>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildCurrency pb = ProtoBuf.Serializer.Deserialize<GuildCurrency>(protoMS);
		FromPB(pb);
		return true;
	}

	//货币类型
	public int m_Currencytype;
	public int Currencytype
	{
		get { return m_Currencytype;}
		set { m_Currencytype = value; }
	}
	//货币改变数量
	public int m_CurrencyChangeNum;
	public int CurrencyChangeNum
	{
		get { return m_CurrencyChangeNum;}
		set { m_CurrencyChangeNum = value; }
	}
	//货币总数
	public int m_CurrencyTotalNum;
	public int CurrencyTotalNum
	{
		get { return m_CurrencyTotalNum;}
		set { m_CurrencyTotalNum = value; }
	}


};
//公会技能封装类
[System.Serializable]
public class GuildSkillWraper
{

	//构造函数
	public GuildSkillWraper()
	{
		 m_Id = -1;
		 m_GuildSkillLevel = -1;
		 m_GuildSkillExp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_GuildSkillLevel = -1;
		 m_GuildSkillExp = -1;

	}

 	//转化成Protobuffer类型函数
	public GuildSkill ToPB()
	{
		GuildSkill v = new GuildSkill();
		v.Id = m_Id;
		v.GuildSkillLevel = m_GuildSkillLevel;
		v.GuildSkillExp = m_GuildSkillExp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GuildSkill v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_GuildSkillLevel = v.GuildSkillLevel;
		m_GuildSkillExp = v.GuildSkillExp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GuildSkill>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GuildSkill pb = ProtoBuf.Serializer.Deserialize<GuildSkill>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//技能等级
	public int m_GuildSkillLevel;
	public int GuildSkillLevel
	{
		get { return m_GuildSkillLevel;}
		set { m_GuildSkillLevel = value; }
	}
	//技能经验
	public int m_GuildSkillExp;
	public int GuildSkillExp
	{
		get { return m_GuildSkillExp;}
		set { m_GuildSkillExp = value; }
	}


};
//精炼数据封装类
[System.Serializable]
public class RefineDataWraper
{

	//构造函数
	public RefineDataWraper()
	{
		 m_Level = 0;
		 m_Extend = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 0;
		 m_Extend = 0;

	}

 	//转化成Protobuffer类型函数
	public RefineData ToPB()
	{
		RefineData v = new RefineData();
		v.Level = m_Level;
		v.Extend = m_Extend;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RefineData v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Extend = v.Extend;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RefineData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RefineData pb = ProtoBuf.Serializer.Deserialize<RefineData>(protoMS);
		FromPB(pb);
		return true;
	}

	//精炼等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//精炼度
	public int m_Extend;
	public int Extend
	{
		get { return m_Extend;}
		set { m_Extend = value; }
	}


};
//房间基础信息封装类
[System.Serializable]
public class RoomBaseInfoWraper
{

	//构造函数
	public RoomBaseInfoWraper()
	{
		 m_Name = "";
		 m_ManageRoleId = 0;
		 m_Announcement = "";
		 m_RoomId = 0;
		 m_RoomType = 0;
		 m_LastChatTime = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Name = "";
		 m_ManageRoleId = 0;
		 m_Announcement = "";
		 m_RoomId = 0;
		 m_RoomType = 0;
		 m_LastChatTime = 0;

	}

 	//转化成Protobuffer类型函数
	public RoomBaseInfo ToPB()
	{
		RoomBaseInfo v = new RoomBaseInfo();
		v.Name = m_Name;
		v.ManageRoleId = m_ManageRoleId;
		v.Announcement = m_Announcement;
		v.RoomId = m_RoomId;
		v.RoomType = m_RoomType;
		v.LastChatTime = m_LastChatTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RoomBaseInfo v)
	{
        if (v == null)
            return;
		m_Name = v.Name;
		m_ManageRoleId = v.ManageRoleId;
		m_Announcement = v.Announcement;
		m_RoomId = v.RoomId;
		m_RoomType = v.RoomType;
		m_LastChatTime = v.LastChatTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RoomBaseInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RoomBaseInfo pb = ProtoBuf.Serializer.Deserialize<RoomBaseInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//房间名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//群主名字
	public UInt64 m_ManageRoleId;
	public UInt64 ManageRoleId
	{
		get { return m_ManageRoleId;}
		set { m_ManageRoleId = value; }
	}
	//公告
	public string m_Announcement;
	public string Announcement
	{
		get { return m_Announcement;}
		set { m_Announcement = value; }
	}
	//房间唯一id
	public UInt64 m_RoomId;
	public UInt64 RoomId
	{
		get { return m_RoomId;}
		set { m_RoomId = value; }
	}
	//RoomType
	public int m_RoomType;
	public int RoomType
	{
		get { return m_RoomType;}
		set { m_RoomType = value; }
	}
	//LastChatTime
	public Int64 m_LastChatTime;
	public Int64 LastChatTime
	{
		get { return m_LastChatTime;}
		set { m_LastChatTime = value; }
	}


};
//ChatRoomPlayerData封装类
[System.Serializable]
public class ChatRoomPlayerDataWraper
{

	//构造函数
	public ChatRoomPlayerDataWraper()
	{
		 m_PlayerContact = new ContactDataWraper();
		 m_NewMsgCount = 0;
		 m_LastReadTime = -1;
		 m_JoinTime = 0;
		 m_ClearIndex = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_PlayerContact = new ContactDataWraper();
		 m_NewMsgCount = 0;
		 m_LastReadTime = -1;
		 m_JoinTime = 0;
		 m_ClearIndex = 0;

	}

 	//转化成Protobuffer类型函数
	public ChatRoomPlayerData ToPB()
	{
		ChatRoomPlayerData v = new ChatRoomPlayerData();
		v.PlayerContact = m_PlayerContact.ToPB();
		v.NewMsgCount = m_NewMsgCount;
		v.LastReadTime = m_LastReadTime;
		v.JoinTime = m_JoinTime;
		v.ClearIndex = m_ClearIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRoomPlayerData v)
	{
        if (v == null)
            return;
		m_PlayerContact.FromPB(v.PlayerContact);
		m_NewMsgCount = v.NewMsgCount;
		m_LastReadTime = v.LastReadTime;
		m_JoinTime = v.JoinTime;
		m_ClearIndex = v.ClearIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRoomPlayerData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRoomPlayerData pb = ProtoBuf.Serializer.Deserialize<ChatRoomPlayerData>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家信息
	public ContactDataWraper m_PlayerContact;
	public ContactDataWraper PlayerContact
	{
		get { return m_PlayerContact;}
		set { m_PlayerContact = value; }
	}
	//NewMsgCount
	public int m_NewMsgCount;
	public int NewMsgCount
	{
		get { return m_NewMsgCount;}
		set { m_NewMsgCount = value; }
	}
	//LastReadTime
	public Int64 m_LastReadTime;
	public Int64 LastReadTime
	{
		get { return m_LastReadTime;}
		set { m_LastReadTime = value; }
	}
	//JoinTime
	public Int64 m_JoinTime;
	public Int64 JoinTime
	{
		get { return m_JoinTime;}
		set { m_JoinTime = value; }
	}
	//ClearIndex
	public int m_ClearIndex;
	public int ClearIndex
	{
		get { return m_ClearIndex;}
		set { m_ClearIndex = value; }
	}


};
//坐骑信息封装类
[System.Serializable]
public class MountDataWraper
{

	//构造函数
	public MountDataWraper()
	{
		 m_MountId = -1;
		 m_MountState = -1;
		 m_MountLevelData = new MountLevelDataWraper();
		 m_MountIntimateData = new MountIntimateDataWraper();
		 m_BattleScore = -1;
		 m_MountSkinId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MountId = -1;
		 m_MountState = -1;
		 m_MountLevelData = new MountLevelDataWraper();
		 m_MountIntimateData = new MountIntimateDataWraper();
		 m_BattleScore = -1;
		 m_MountSkinId = -1;

	}

 	//转化成Protobuffer类型函数
	public MountData ToPB()
	{
		MountData v = new MountData();
		v.MountId = m_MountId;
		v.MountState = m_MountState;
		v.MountLevelData = m_MountLevelData.ToPB();
		v.MountIntimateData = m_MountIntimateData.ToPB();
		v.BattleScore = m_BattleScore;
		v.MountSkinId = m_MountSkinId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MountData v)
	{
        if (v == null)
            return;
		m_MountId = v.MountId;
		m_MountState = v.MountState;
		m_MountLevelData.FromPB(v.MountLevelData);
		m_MountIntimateData.FromPB(v.MountIntimateData);
		m_BattleScore = v.BattleScore;
		m_MountSkinId = v.MountSkinId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MountData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MountData pb = ProtoBuf.Serializer.Deserialize<MountData>(protoMS);
		FromPB(pb);
		return true;
	}

	//坐骑ID
	public int m_MountId;
	public int MountId
	{
		get { return m_MountId;}
		set { m_MountId = value; }
	}
	//坐骑状态
	public int m_MountState;
	public int MountState
	{
		get { return m_MountState;}
		set { m_MountState = value; }
	}
	//等级数据
	public MountLevelDataWraper m_MountLevelData;
	public MountLevelDataWraper MountLevelData
	{
		get { return m_MountLevelData;}
		set { m_MountLevelData = value; }
	}
	//请密度数据
	public MountIntimateDataWraper m_MountIntimateData;
	public MountIntimateDataWraper MountIntimateData
	{
		get { return m_MountIntimateData;}
		set { m_MountIntimateData = value; }
	}
	//战力值
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//坐骑皮肤
	public int m_MountSkinId;
	public int MountSkinId
	{
		get { return m_MountSkinId;}
		set { m_MountSkinId = value; }
	}


};
//坐骑等级数据封装类
[System.Serializable]
public class MountLevelDataWraper
{

	//构造函数
	public MountLevelDataWraper()
	{
		 m_Level = 1;
		 m_Experience = 0;
		m_DevelopHistory = new List<MountDevItemWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 1;
		 m_Experience = 0;
		m_DevelopHistory = new List<MountDevItemWraper>();

	}

 	//转化成Protobuffer类型函数
	public MountLevelData ToPB()
	{
		MountLevelData v = new MountLevelData();
		v.Level = m_Level;
		v.Experience = m_Experience;
		for (int i=0; i<(int)m_DevelopHistory.Count; i++)
			v.DevelopHistory.Add( m_DevelopHistory[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MountLevelData v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Experience = v.Experience;
		m_DevelopHistory.Clear();
		for( int i=0; i<v.DevelopHistory.Count; i++)
			m_DevelopHistory.Add( new MountDevItemWraper());
		for( int i=0; i<v.DevelopHistory.Count; i++)
			m_DevelopHistory[i].FromPB(v.DevelopHistory[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MountLevelData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MountLevelData pb = ProtoBuf.Serializer.Deserialize<MountLevelData>(protoMS);
		FromPB(pb);
		return true;
	}

	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//经验
	public int m_Experience;
	public int Experience
	{
		get { return m_Experience;}
		set { m_Experience = value; }
	}
	//养成历史
	public List<MountDevItemWraper> m_DevelopHistory;
	public int SizeDevelopHistory()
	{
		return m_DevelopHistory.Count;
	}
	public List<MountDevItemWraper> GetDevelopHistory()
	{
		return m_DevelopHistory;
	}
	public MountDevItemWraper GetDevelopHistory(int Index)
	{
		if(Index<0 || Index>=(int)m_DevelopHistory.Count)
			return new MountDevItemWraper();
		return m_DevelopHistory[Index];
	}
	public void SetDevelopHistory( List<MountDevItemWraper> v )
	{
		m_DevelopHistory=v;
	}
	public void SetDevelopHistory( int Index, MountDevItemWraper v )
	{
		if(Index<0 || Index>=(int)m_DevelopHistory.Count)
			return;
		m_DevelopHistory[Index] = v;
	}
	public void AddDevelopHistory( MountDevItemWraper v )
	{
		m_DevelopHistory.Add(v);
	}
	public void ClearDevelopHistory( )
	{
		m_DevelopHistory.Clear();
	}


};
//坐骑亲密度封装类
[System.Serializable]
public class MountIntimateDataWraper
{

	//构造函数
	public MountIntimateDataWraper()
	{
		 m_Level = 1;
		 m_Experience = 0;
		m_FeedHistory = new List<MountDevItemWraper>();
		 m_TodayExp = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 1;
		 m_Experience = 0;
		m_FeedHistory = new List<MountDevItemWraper>();
		 m_TodayExp = 0;

	}

 	//转化成Protobuffer类型函数
	public MountIntimateData ToPB()
	{
		MountIntimateData v = new MountIntimateData();
		v.Level = m_Level;
		v.Experience = m_Experience;
		for (int i=0; i<(int)m_FeedHistory.Count; i++)
			v.FeedHistory.Add( m_FeedHistory[i].ToPB());
		v.TodayExp = m_TodayExp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MountIntimateData v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Experience = v.Experience;
		m_FeedHistory.Clear();
		for( int i=0; i<v.FeedHistory.Count; i++)
			m_FeedHistory.Add( new MountDevItemWraper());
		for( int i=0; i<v.FeedHistory.Count; i++)
			m_FeedHistory[i].FromPB(v.FeedHistory[i]);
		m_TodayExp = v.TodayExp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MountIntimateData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MountIntimateData pb = ProtoBuf.Serializer.Deserialize<MountIntimateData>(protoMS);
		FromPB(pb);
		return true;
	}

	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//经验
	public int m_Experience;
	public int Experience
	{
		get { return m_Experience;}
		set { m_Experience = value; }
	}
	//喂养记录
	public List<MountDevItemWraper> m_FeedHistory;
	public int SizeFeedHistory()
	{
		return m_FeedHistory.Count;
	}
	public List<MountDevItemWraper> GetFeedHistory()
	{
		return m_FeedHistory;
	}
	public MountDevItemWraper GetFeedHistory(int Index)
	{
		if(Index<0 || Index>=(int)m_FeedHistory.Count)
			return new MountDevItemWraper();
		return m_FeedHistory[Index];
	}
	public void SetFeedHistory( List<MountDevItemWraper> v )
	{
		m_FeedHistory=v;
	}
	public void SetFeedHistory( int Index, MountDevItemWraper v )
	{
		if(Index<0 || Index>=(int)m_FeedHistory.Count)
			return;
		m_FeedHistory[Index] = v;
	}
	public void AddFeedHistory( MountDevItemWraper v )
	{
		m_FeedHistory.Add(v);
	}
	public void ClearFeedHistory( )
	{
		m_FeedHistory.Clear();
	}
	//今日喂养所得经验
	public int m_TodayExp;
	public int TodayExp
	{
		get { return m_TodayExp;}
		set { m_TodayExp = value; }
	}


};
//坐骑喂养宠物道具记录封装类
[System.Serializable]
public class MountDevItemWraper
{

	//构造函数
	public MountDevItemWraper()
	{
		 m_ItemId = -1;
		 m_ItemCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;
		 m_ItemCount = -1;

	}

 	//转化成Protobuffer类型函数
	public MountDevItem ToPB()
	{
		MountDevItem v = new MountDevItem();
		v.ItemId = m_ItemId;
		v.ItemCount = m_ItemCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MountDevItem v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_ItemCount = v.ItemCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MountDevItem>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MountDevItem pb = ProtoBuf.Serializer.Deserialize<MountDevItem>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具ID
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//道具数量
	public int m_ItemCount;
	public int ItemCount
	{
		get { return m_ItemCount;}
		set { m_ItemCount = value; }
	}


};
//ChatRoomPBInfo封装类
[System.Serializable]
public class ChatRoomPBInfoWraper
{

	//构造函数
	public ChatRoomPBInfoWraper()
	{
		m_PlayerList = new List<ChatRoomPlayerDataWraper>();
		 m_RoomBaseInfoPB = new RoomBaseInfoWraper();
		m_ChatMsg = new List<ChatInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_PlayerList = new List<ChatRoomPlayerDataWraper>();
		 m_RoomBaseInfoPB = new RoomBaseInfoWraper();
		m_ChatMsg = new List<ChatInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public ChatRoomPBInfo ToPB()
	{
		ChatRoomPBInfo v = new ChatRoomPBInfo();
		for (int i=0; i<(int)m_PlayerList.Count; i++)
			v.PlayerList.Add( m_PlayerList[i].ToPB());
		v.RoomBaseInfoPB = m_RoomBaseInfoPB.ToPB();
		for (int i=0; i<(int)m_ChatMsg.Count; i++)
			v.ChatMsg.Add( m_ChatMsg[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatRoomPBInfo v)
	{
        if (v == null)
            return;
		m_PlayerList.Clear();
		for( int i=0; i<v.PlayerList.Count; i++)
			m_PlayerList.Add( new ChatRoomPlayerDataWraper());
		for( int i=0; i<v.PlayerList.Count; i++)
			m_PlayerList[i].FromPB(v.PlayerList[i]);
		m_RoomBaseInfoPB.FromPB(v.RoomBaseInfoPB);
		m_ChatMsg.Clear();
		for( int i=0; i<v.ChatMsg.Count; i++)
			m_ChatMsg.Add( new ChatInfoWraper());
		for( int i=0; i<v.ChatMsg.Count; i++)
			m_ChatMsg[i].FromPB(v.ChatMsg[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatRoomPBInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatRoomPBInfo pb = ProtoBuf.Serializer.Deserialize<ChatRoomPBInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//PlayerList
	public List<ChatRoomPlayerDataWraper> m_PlayerList;
	public int SizePlayerList()
	{
		return m_PlayerList.Count;
	}
	public List<ChatRoomPlayerDataWraper> GetPlayerList()
	{
		return m_PlayerList;
	}
	public ChatRoomPlayerDataWraper GetPlayerList(int Index)
	{
		if(Index<0 || Index>=(int)m_PlayerList.Count)
			return new ChatRoomPlayerDataWraper();
		return m_PlayerList[Index];
	}
	public void SetPlayerList( List<ChatRoomPlayerDataWraper> v )
	{
		m_PlayerList=v;
	}
	public void SetPlayerList( int Index, ChatRoomPlayerDataWraper v )
	{
		if(Index<0 || Index>=(int)m_PlayerList.Count)
			return;
		m_PlayerList[Index] = v;
	}
	public void AddPlayerList( ChatRoomPlayerDataWraper v )
	{
		m_PlayerList.Add(v);
	}
	public void ClearPlayerList( )
	{
		m_PlayerList.Clear();
	}
	//RoomBaseInfoPB
	public RoomBaseInfoWraper m_RoomBaseInfoPB;
	public RoomBaseInfoWraper RoomBaseInfoPB
	{
		get { return m_RoomBaseInfoPB;}
		set { m_RoomBaseInfoPB = value; }
	}
	//ChatMsg
	public List<ChatInfoWraper> m_ChatMsg;
	public int SizeChatMsg()
	{
		return m_ChatMsg.Count;
	}
	public List<ChatInfoWraper> GetChatMsg()
	{
		return m_ChatMsg;
	}
	public ChatInfoWraper GetChatMsg(int Index)
	{
		if(Index<0 || Index>=(int)m_ChatMsg.Count)
			return new ChatInfoWraper();
		return m_ChatMsg[Index];
	}
	public void SetChatMsg( List<ChatInfoWraper> v )
	{
		m_ChatMsg=v;
	}
	public void SetChatMsg( int Index, ChatInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ChatMsg.Count)
			return;
		m_ChatMsg[Index] = v;
	}
	public void AddChatMsg( ChatInfoWraper v )
	{
		m_ChatMsg.Add(v);
	}
	public void ClearChatMsg( )
	{
		m_ChatMsg.Clear();
	}


};
//ChatEventMsg封装类
[System.Serializable]
public class ChatEventMsgWraper
{

	//构造函数
	public ChatEventMsgWraper()
	{
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public ChatEventMsg ToPB()
	{
		ChatEventMsg v = new ChatEventMsg();
		v.StringUIConfigId = m_StringUIConfigId;
		for (int i=0; i<(int)m_Params.Count; i++)
			v.Params.Add( m_Params[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatEventMsg v)
	{
        if (v == null)
            return;
		m_StringUIConfigId = v.StringUIConfigId;
		m_Params.Clear();
		for( int i=0; i<v.Params.Count; i++)
			m_Params.Add(v.Params[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatEventMsg>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatEventMsg pb = ProtoBuf.Serializer.Deserialize<ChatEventMsg>(protoMS);
		FromPB(pb);
		return true;
	}

	//StringUIConfigId
	public int m_StringUIConfigId;
	public int StringUIConfigId
	{
		get { return m_StringUIConfigId;}
		set { m_StringUIConfigId = value; }
	}
	//Params
	public List<string> m_Params;
	public int SizeParams()
	{
		return m_Params.Count;
	}
	public List<string> GetParams()
	{
		return m_Params;
	}
	public string GetParams(int Index)
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return "";
		return m_Params[Index];
	}
	public void SetParams( List<string> v )
	{
		m_Params=v;
	}
	public void SetParams( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return;
		m_Params[Index] = v;
	}
	public void AddParams( string v )
	{
		m_Params.Add(v);
	}
	public void ClearParams( )
	{
		m_Params.Clear();
	}


};
//RelationUnionInfo封装类
[System.Serializable]
public class RelationUnionInfoWraper
{

	//构造函数
	public RelationUnionInfoWraper()
	{
		 m_LeaderRoleId = 0;
		 m_TeamId = 0;
		 m_TeamType = -1;
		m_MemberEvent = new List<ChatInfoVoteWraper>();
		 m_RelationUnionName = "";
		m_Members = new List<TeamMemberInfoWraper>();
		 m_UnionValue = 0;
		m_VoteEvent = new List<ChatInfoVoteWraper>();
		 m_MergeUnionId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LeaderRoleId = 0;
		 m_TeamId = 0;
		 m_TeamType = -1;
		m_MemberEvent = new List<ChatInfoVoteWraper>();
		 m_RelationUnionName = "";
		m_Members = new List<TeamMemberInfoWraper>();
		 m_UnionValue = 0;
		m_VoteEvent = new List<ChatInfoVoteWraper>();
		 m_MergeUnionId = 0;

	}

 	//转化成Protobuffer类型函数
	public RelationUnionInfo ToPB()
	{
		RelationUnionInfo v = new RelationUnionInfo();
		v.LeaderRoleId = m_LeaderRoleId;
		v.TeamId = m_TeamId;
		v.TeamType = m_TeamType;
		for (int i=0; i<(int)m_MemberEvent.Count; i++)
			v.MemberEvent.Add( m_MemberEvent[i].ToPB());
		v.RelationUnionName = m_RelationUnionName;
		for (int i=0; i<(int)m_Members.Count; i++)
			v.Members.Add( m_Members[i].ToPB());
		v.UnionValue = m_UnionValue;
		for (int i=0; i<(int)m_VoteEvent.Count; i++)
			v.VoteEvent.Add( m_VoteEvent[i].ToPB());
		v.MergeUnionId = m_MergeUnionId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RelationUnionInfo v)
	{
        if (v == null)
            return;
		m_LeaderRoleId = v.LeaderRoleId;
		m_TeamId = v.TeamId;
		m_TeamType = v.TeamType;
		m_MemberEvent.Clear();
		for( int i=0; i<v.MemberEvent.Count; i++)
			m_MemberEvent.Add( new ChatInfoVoteWraper());
		for( int i=0; i<v.MemberEvent.Count; i++)
			m_MemberEvent[i].FromPB(v.MemberEvent[i]);
		m_RelationUnionName = v.RelationUnionName;
		m_Members.Clear();
		for( int i=0; i<v.Members.Count; i++)
			m_Members.Add( new TeamMemberInfoWraper());
		for( int i=0; i<v.Members.Count; i++)
			m_Members[i].FromPB(v.Members[i]);
		m_UnionValue = v.UnionValue;
		m_VoteEvent.Clear();
		for( int i=0; i<v.VoteEvent.Count; i++)
			m_VoteEvent.Add( new ChatInfoVoteWraper());
		for( int i=0; i<v.VoteEvent.Count; i++)
			m_VoteEvent[i].FromPB(v.VoteEvent[i]);
		m_MergeUnionId = v.MergeUnionId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<RelationUnionInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		RelationUnionInfo pb = ProtoBuf.Serializer.Deserialize<RelationUnionInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//LeaderRoleId
	public UInt64 m_LeaderRoleId;
	public UInt64 LeaderRoleId
	{
		get { return m_LeaderRoleId;}
		set { m_LeaderRoleId = value; }
	}
	//TeamId
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//TeamType
	public int m_TeamType;
	public int TeamType
	{
		get { return m_TeamType;}
		set { m_TeamType = value; }
	}
	//MemberEvent
	public List<ChatInfoVoteWraper> m_MemberEvent;
	public int SizeMemberEvent()
	{
		return m_MemberEvent.Count;
	}
	public List<ChatInfoVoteWraper> GetMemberEvent()
	{
		return m_MemberEvent;
	}
	public ChatInfoVoteWraper GetMemberEvent(int Index)
	{
		if(Index<0 || Index>=(int)m_MemberEvent.Count)
			return new ChatInfoVoteWraper();
		return m_MemberEvent[Index];
	}
	public void SetMemberEvent( List<ChatInfoVoteWraper> v )
	{
		m_MemberEvent=v;
	}
	public void SetMemberEvent( int Index, ChatInfoVoteWraper v )
	{
		if(Index<0 || Index>=(int)m_MemberEvent.Count)
			return;
		m_MemberEvent[Index] = v;
	}
	public void AddMemberEvent( ChatInfoVoteWraper v )
	{
		m_MemberEvent.Add(v);
	}
	public void ClearMemberEvent( )
	{
		m_MemberEvent.Clear();
	}
	//缔约团
	public string m_RelationUnionName;
	public string RelationUnionName
	{
		get { return m_RelationUnionName;}
		set { m_RelationUnionName = value; }
	}
	//Members
	public List<TeamMemberInfoWraper> m_Members;
	public int SizeMembers()
	{
		return m_Members.Count;
	}
	public List<TeamMemberInfoWraper> GetMembers()
	{
		return m_Members;
	}
	public TeamMemberInfoWraper GetMembers(int Index)
	{
		if(Index<0 || Index>=(int)m_Members.Count)
			return new TeamMemberInfoWraper();
		return m_Members[Index];
	}
	public void SetMembers( List<TeamMemberInfoWraper> v )
	{
		m_Members=v;
	}
	public void SetMembers( int Index, TeamMemberInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Members.Count)
			return;
		m_Members[Index] = v;
	}
	public void AddMembers( TeamMemberInfoWraper v )
	{
		m_Members.Add(v);
	}
	public void ClearMembers( )
	{
		m_Members.Clear();
	}
	//UnionValue
	public UInt64 m_UnionValue;
	public UInt64 UnionValue
	{
		get { return m_UnionValue;}
		set { m_UnionValue = value; }
	}
	//MemberEvent
	public List<ChatInfoVoteWraper> m_VoteEvent;
	public int SizeVoteEvent()
	{
		return m_VoteEvent.Count;
	}
	public List<ChatInfoVoteWraper> GetVoteEvent()
	{
		return m_VoteEvent;
	}
	public ChatInfoVoteWraper GetVoteEvent(int Index)
	{
		if(Index<0 || Index>=(int)m_VoteEvent.Count)
			return new ChatInfoVoteWraper();
		return m_VoteEvent[Index];
	}
	public void SetVoteEvent( List<ChatInfoVoteWraper> v )
	{
		m_VoteEvent=v;
	}
	public void SetVoteEvent( int Index, ChatInfoVoteWraper v )
	{
		if(Index<0 || Index>=(int)m_VoteEvent.Count)
			return;
		m_VoteEvent[Index] = v;
	}
	public void AddVoteEvent( ChatInfoVoteWraper v )
	{
		m_VoteEvent.Add(v);
	}
	public void ClearVoteEvent( )
	{
		m_VoteEvent.Clear();
	}
	//MergeUnionId
	public UInt64 m_MergeUnionId;
	public UInt64 MergeUnionId
	{
		get { return m_MergeUnionId;}
		set { m_MergeUnionId = value; }
	}


};
//PBVote封装类
[System.Serializable]
public class PBVoteWraper
{

	//构造函数
	public PBVoteWraper()
	{
		 m_Type = 0;
		 m_RoleId = 0;
		m_VoteRole = new List<UInt64>();
		 m_VoteId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = 0;
		 m_RoleId = 0;
		m_VoteRole = new List<UInt64>();
		 m_VoteId = 0;

	}

 	//转化成Protobuffer类型函数
	public PBVote ToPB()
	{
		PBVote v = new PBVote();
		v.Type = m_Type;
		v.RoleId = m_RoleId;
		for (int i=0; i<(int)m_VoteRole.Count; i++)
			v.VoteRole.Add( m_VoteRole[i]);
		v.VoteId = m_VoteId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PBVote v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_RoleId = v.RoleId;
		m_VoteRole.Clear();
		for( int i=0; i<v.VoteRole.Count; i++)
			m_VoteRole.Add(v.VoteRole[i]);
		m_VoteId = v.VoteId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PBVote>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PBVote pb = ProtoBuf.Serializer.Deserialize<PBVote>(protoMS);
		FromPB(pb);
		return true;
	}

	//Type
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//RoleId
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//VoteRole
	public List<UInt64> m_VoteRole;
	public int SizeVoteRole()
	{
		return m_VoteRole.Count;
	}
	public List<UInt64> GetVoteRole()
	{
		return m_VoteRole;
	}
	public UInt64 GetVoteRole(int Index)
	{
		if(Index<0 || Index>=(int)m_VoteRole.Count)
			return 0;
		return m_VoteRole[Index];
	}
	public void SetVoteRole( List<UInt64> v )
	{
		m_VoteRole=v;
	}
	public void SetVoteRole( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_VoteRole.Count)
			return;
		m_VoteRole[Index] = v;
	}
	public void AddVoteRole( UInt64 v=0 )
	{
		m_VoteRole.Add(v);
	}
	public void ClearVoteRole( )
	{
		m_VoteRole.Clear();
	}
	//VoteId
	public UInt64 m_VoteId;
	public UInt64 VoteId
	{
		get { return m_VoteId;}
		set { m_VoteId = value; }
	}


};
//纹章盒封装类
[System.Serializable]
public class EmblemBoxDataWraper
{

	//构造函数
	public EmblemBoxDataWraper()
	{
		 m_Emblem_slot = new ItemDataWraper();
		 m_Diamante_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Emblem_slot = new ItemDataWraper();
		 m_Diamante_id = -1;

	}

 	//转化成Protobuffer类型函数
	public EmblemBoxData ToPB()
	{
		EmblemBoxData v = new EmblemBoxData();
		v.Emblem_slot = m_Emblem_slot.ToPB();
		v.Diamante_id = m_Diamante_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EmblemBoxData v)
	{
        if (v == null)
            return;
		m_Emblem_slot.FromPB(v.Emblem_slot);
		m_Diamante_id = v.Diamante_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EmblemBoxData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EmblemBoxData pb = ProtoBuf.Serializer.Deserialize<EmblemBoxData>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备纹章
	public ItemDataWraper m_Emblem_slot;
	public ItemDataWraper Emblem_slot
	{
		get { return m_Emblem_slot;}
		set { m_Emblem_slot = value; }
	}
	//镶钻id
	public int m_Diamante_id;
	public int Diamante_id
	{
		get { return m_Diamante_id;}
		set { m_Diamante_id = value; }
	}


};
//宠物成长度封装类
[System.Serializable]
public class PetFeedDataWraper
{

	//构造函数
	public PetFeedDataWraper()
	{
		 m_Level = 0;
		 m_Exp = 0;
		 m_FeedCount = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 0;
		 m_Exp = 0;
		 m_FeedCount = 0;

	}

 	//转化成Protobuffer类型函数
	public PetFeedData ToPB()
	{
		PetFeedData v = new PetFeedData();
		v.Level = m_Level;
		v.Exp = m_Exp;
		v.FeedCount = m_FeedCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetFeedData v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Exp = v.Exp;
		m_FeedCount = v.FeedCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetFeedData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetFeedData pb = ProtoBuf.Serializer.Deserialize<PetFeedData>(protoMS);
		FromPB(pb);
		return true;
	}

	//等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//经验
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//今日喂养次数
	public int m_FeedCount;
	public int FeedCount
	{
		get { return m_FeedCount;}
		set { m_FeedCount = value; }
	}


};
//投票信息封装类
[System.Serializable]
public class VoteMsgWraper
{

	//构造函数
	public VoteMsgWraper()
	{
		 m_VoteId = 0;
		m_Dt = new List<VoteDataWraper>();
		 m_VoteEndTime = 0;
		 m_Result = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_VoteId = 0;
		m_Dt = new List<VoteDataWraper>();
		 m_VoteEndTime = 0;
		 m_Result = 0;

	}

 	//转化成Protobuffer类型函数
	public VoteMsg ToPB()
	{
		VoteMsg v = new VoteMsg();
		v.VoteId = m_VoteId;
		for (int i=0; i<(int)m_Dt.Count; i++)
			v.Dt.Add( m_Dt[i].ToPB());
		v.VoteEndTime = m_VoteEndTime;
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(VoteMsg v)
	{
        if (v == null)
            return;
		m_VoteId = v.VoteId;
		m_Dt.Clear();
		for( int i=0; i<v.Dt.Count; i++)
			m_Dt.Add( new VoteDataWraper());
		for( int i=0; i<v.Dt.Count; i++)
			m_Dt[i].FromPB(v.Dt[i]);
		m_VoteEndTime = v.VoteEndTime;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<VoteMsg>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		VoteMsg pb = ProtoBuf.Serializer.Deserialize<VoteMsg>(protoMS);
		FromPB(pb);
		return true;
	}

	//投票id
	public UInt64 m_VoteId;
	public UInt64 VoteId
	{
		get { return m_VoteId;}
		set { m_VoteId = value; }
	}
	//投票数据
	public List<VoteDataWraper> m_Dt;
	public int SizeDt()
	{
		return m_Dt.Count;
	}
	public List<VoteDataWraper> GetDt()
	{
		return m_Dt;
	}
	public VoteDataWraper GetDt(int Index)
	{
		if(Index<0 || Index>=(int)m_Dt.Count)
			return new VoteDataWraper();
		return m_Dt[Index];
	}
	public void SetDt( List<VoteDataWraper> v )
	{
		m_Dt=v;
	}
	public void SetDt( int Index, VoteDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Dt.Count)
			return;
		m_Dt[Index] = v;
	}
	public void AddDt( VoteDataWraper v )
	{
		m_Dt.Add(v);
	}
	public void ClearDt( )
	{
		m_Dt.Clear();
	}
	//VoteEndTime
	public int m_VoteEndTime;
	public int VoteEndTime
	{
		get { return m_VoteEndTime;}
		set { m_VoteEndTime = value; }
	}
	//结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//投票数据封装类
[System.Serializable]
public class VoteDataWraper
{

	//构造函数
	public VoteDataWraper()
	{
		 m_Candidate = 0;
		m_VotePlayer = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Candidate = 0;
		m_VotePlayer = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public VoteData ToPB()
	{
		VoteData v = new VoteData();
		v.Candidate = m_Candidate;
		for (int i=0; i<(int)m_VotePlayer.Count; i++)
			v.VotePlayer.Add( m_VotePlayer[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(VoteData v)
	{
        if (v == null)
            return;
		m_Candidate = v.Candidate;
		m_VotePlayer.Clear();
		for( int i=0; i<v.VotePlayer.Count; i++)
			m_VotePlayer.Add(v.VotePlayer[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<VoteData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		VoteData pb = ProtoBuf.Serializer.Deserialize<VoteData>(protoMS);
		FromPB(pb);
		return true;
	}

	//投票id
	public UInt64 m_Candidate;
	public UInt64 Candidate
	{
		get { return m_Candidate;}
		set { m_Candidate = value; }
	}
	//投票过的人
	public List<UInt64> m_VotePlayer;
	public int SizeVotePlayer()
	{
		return m_VotePlayer.Count;
	}
	public List<UInt64> GetVotePlayer()
	{
		return m_VotePlayer;
	}
	public UInt64 GetVotePlayer(int Index)
	{
		if(Index<0 || Index>=(int)m_VotePlayer.Count)
			return 0;
		return m_VotePlayer[Index];
	}
	public void SetVotePlayer( List<UInt64> v )
	{
		m_VotePlayer=v;
	}
	public void SetVotePlayer( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_VotePlayer.Count)
			return;
		m_VotePlayer[Index] = v;
	}
	public void AddVotePlayer( UInt64 v=0 )
	{
		m_VotePlayer.Add(v);
	}
	public void ClearVotePlayer( )
	{
		m_VotePlayer.Clear();
	}


};
//全服目标奖励封装类
[System.Serializable]
public class ObjectiveAwardWraper
{

	//构造函数
	public ObjectiveAwardWraper()
	{
		 m_Id = -1;
		 m_State = -1;
		m_ItemId = new List<int>();
		 m_Type = -1;
		 m_NeedTime = -1;
		m_ItemNum = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_State = -1;
		m_ItemId = new List<int>();
		 m_Type = -1;
		 m_NeedTime = -1;
		m_ItemNum = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ObjectiveAward ToPB()
	{
		ObjectiveAward v = new ObjectiveAward();
		v.Id = m_Id;
		v.State = m_State;
		for (int i=0; i<(int)m_ItemId.Count; i++)
			v.ItemId.Add( m_ItemId[i]);
		v.Type = m_Type;
		v.NeedTime = m_NeedTime;
		for (int i=0; i<(int)m_ItemNum.Count; i++)
			v.ItemNum.Add( m_ItemNum[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ObjectiveAward v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_State = v.State;
		m_ItemId.Clear();
		for( int i=0; i<v.ItemId.Count; i++)
			m_ItemId.Add(v.ItemId[i]);
		m_Type = v.Type;
		m_NeedTime = v.NeedTime;
		m_ItemNum.Clear();
		for( int i=0; i<v.ItemNum.Count; i++)
			m_ItemNum.Add(v.ItemNum[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ObjectiveAward>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ObjectiveAward pb = ProtoBuf.Serializer.Deserialize<ObjectiveAward>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//物品
	public List<int> m_ItemId;
	public int SizeItemId()
	{
		return m_ItemId.Count;
	}
	public List<int> GetItemId()
	{
		return m_ItemId;
	}
	public int GetItemId(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemId.Count)
			return -1;
		return m_ItemId[Index];
	}
	public void SetItemId( List<int> v )
	{
		m_ItemId=v;
	}
	public void SetItemId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ItemId.Count)
			return;
		m_ItemId[Index] = v;
	}
	public void AddItemId( int v=-1 )
	{
		m_ItemId.Add(v);
	}
	public void ClearItemId( )
	{
		m_ItemId.Clear();
	}
	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//达成次数
	public int m_NeedTime;
	public int NeedTime
	{
		get { return m_NeedTime;}
		set { m_NeedTime = value; }
	}
	//物品个数
	public List<int> m_ItemNum;
	public int SizeItemNum()
	{
		return m_ItemNum.Count;
	}
	public List<int> GetItemNum()
	{
		return m_ItemNum;
	}
	public int GetItemNum(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemNum.Count)
			return -1;
		return m_ItemNum[Index];
	}
	public void SetItemNum( List<int> v )
	{
		m_ItemNum=v;
	}
	public void SetItemNum( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ItemNum.Count)
			return;
		m_ItemNum[Index] = v;
	}
	public void AddItemNum( int v=-1 )
	{
		m_ItemNum.Add(v);
	}
	public void ClearItemNum( )
	{
		m_ItemNum.Clear();
	}


};
//活动提醒通知封装类
[System.Serializable]
public class ActivityNoticeWraper
{

	//构造函数
	public ActivityNoticeWraper()
	{
		 m_ActId = -1;
		 m_Begin_time = -1;
		 m_End_time = -1;
		 m_Status = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ActId = -1;
		 m_Begin_time = -1;
		 m_End_time = -1;
		 m_Status = -1;

	}

 	//转化成Protobuffer类型函数
	public ActivityNotice ToPB()
	{
		ActivityNotice v = new ActivityNotice();
		v.ActId = m_ActId;
		v.Begin_time = m_Begin_time;
		v.End_time = m_End_time;
		v.Status = m_Status;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ActivityNotice v)
	{
        if (v == null)
            return;
		m_ActId = v.ActId;
		m_Begin_time = v.Begin_time;
		m_End_time = v.End_time;
		m_Status = v.Status;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ActivityNotice>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ActivityNotice pb = ProtoBuf.Serializer.Deserialize<ActivityNotice>(protoMS);
		FromPB(pb);
		return true;
	}

	//活动id
	public int m_ActId;
	public int ActId
	{
		get { return m_ActId;}
		set { m_ActId = value; }
	}
	//开启时间
	public int m_Begin_time;
	public int Begin_time
	{
		get { return m_Begin_time;}
		set { m_Begin_time = value; }
	}
	//结束时间
	public int m_End_time;
	public int End_time
	{
		get { return m_End_time;}
		set { m_End_time = value; }
	}
	//状态
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}


};
//节日boss 奖励封装类
[System.Serializable]
public class BossAwardWraper
{

	//构造函数
	public BossAwardWraper()
	{
		 m_Type = -1;
		 m_ItemId = -1;
		 m_ItemCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;
		 m_ItemId = -1;
		 m_ItemCount = -1;

	}

 	//转化成Protobuffer类型函数
	public BossAward ToPB()
	{
		BossAward v = new BossAward();
		v.Type = m_Type;
		v.ItemId = m_ItemId;
		v.ItemCount = m_ItemCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BossAward v)
	{
        if (v == null)
            return;
		m_Type = v.Type;
		m_ItemId = v.ItemId;
		m_ItemCount = v.ItemCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BossAward>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BossAward pb = ProtoBuf.Serializer.Deserialize<BossAward>(protoMS);
		FromPB(pb);
		return true;
	}

	//类型 [1 个人贡献 2 最后一击]
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//物品id
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//物品个数
	public int m_ItemCount;
	public int ItemCount
	{
		get { return m_ItemCount;}
		set { m_ItemCount = value; }
	}


};
//ChatMsgVote封装类
[System.Serializable]
public class ChatMsgVoteWraper
{

	//构造函数
	public ChatMsgVoteWraper()
	{
		 m_Chat_content = "";
		 m_Chat_voice_url = "";
		 m_Chat_voice_secs = -1;
		m_Items = new List<ItemDataWraper>();
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();
		 m_VoteMsgData = new VoteMsgWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Chat_content = "";
		 m_Chat_voice_url = "";
		 m_Chat_voice_secs = -1;
		m_Items = new List<ItemDataWraper>();
		 m_StringUIConfigId = -1;
		m_Params = new List<string>();
		 m_VoteMsgData = new VoteMsgWraper();

	}

 	//转化成Protobuffer类型函数
	public ChatMsgVote ToPB()
	{
		ChatMsgVote v = new ChatMsgVote();
		v.Chat_content = m_Chat_content;
		v.Chat_voice_url = m_Chat_voice_url;
		v.Chat_voice_secs = m_Chat_voice_secs;
		for (int i=0; i<(int)m_Items.Count; i++)
			v.Items.Add( m_Items[i].ToPB());
		v.StringUIConfigId = m_StringUIConfigId;
		for (int i=0; i<(int)m_Params.Count; i++)
			v.Params.Add( m_Params[i]);
		v.VoteMsgData = m_VoteMsgData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatMsgVote v)
	{
        if (v == null)
            return;
		m_Chat_content = v.Chat_content;
		m_Chat_voice_url = v.Chat_voice_url;
		m_Chat_voice_secs = v.Chat_voice_secs;
		m_Items.Clear();
		for( int i=0; i<v.Items.Count; i++)
			m_Items.Add( new ItemDataWraper());
		for( int i=0; i<v.Items.Count; i++)
			m_Items[i].FromPB(v.Items[i]);
		m_StringUIConfigId = v.StringUIConfigId;
		m_Params.Clear();
		for( int i=0; i<v.Params.Count; i++)
			m_Params.Add(v.Params[i]);
		m_VoteMsgData.FromPB(v.VoteMsgData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatMsgVote>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatMsgVote pb = ProtoBuf.Serializer.Deserialize<ChatMsgVote>(protoMS);
		FromPB(pb);
		return true;
	}

	//文字内容
	public string m_Chat_content;
	public string Chat_content
	{
		get { return m_Chat_content;}
		set { m_Chat_content = value; }
	}
	//音频URL
	public string m_Chat_voice_url;
	public string Chat_voice_url
	{
		get { return m_Chat_voice_url;}
		set { m_Chat_voice_url = value; }
	}
	//音频秒数
	public int m_Chat_voice_secs;
	public int Chat_voice_secs
	{
		get { return m_Chat_voice_secs;}
		set { m_Chat_voice_secs = value; }
	}
	//items
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
	//StringUIConfigId
	public int m_StringUIConfigId;
	public int StringUIConfigId
	{
		get { return m_StringUIConfigId;}
		set { m_StringUIConfigId = value; }
	}
	//Params
	public List<string> m_Params;
	public int SizeParams()
	{
		return m_Params.Count;
	}
	public List<string> GetParams()
	{
		return m_Params;
	}
	public string GetParams(int Index)
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return "";
		return m_Params[Index];
	}
	public void SetParams( List<string> v )
	{
		m_Params=v;
	}
	public void SetParams( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_Params.Count)
			return;
		m_Params[Index] = v;
	}
	public void AddParams( string v )
	{
		m_Params.Add(v);
	}
	public void ClearParams( )
	{
		m_Params.Clear();
	}
	//投票数据
	public VoteMsgWraper m_VoteMsgData;
	public VoteMsgWraper VoteMsgData
	{
		get { return m_VoteMsgData;}
		set { m_VoteMsgData = value; }
	}


};
//ChatInfoVote封装类
[System.Serializable]
public class ChatInfoVoteWraper
{

	//构造函数
	public ChatInfoVoteWraper()
	{
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Avatar_frame_id1 = -1;
		 m_Config_id = -1;
		 m_Timestamp = -1;
		 m_Chat_msg = new ChatMsgVoteWraper();
		 m_Team_id = 0;
		 m_Guild_guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Avatar_frame_id1 = -1;
		 m_Config_id = -1;
		 m_Timestamp = -1;
		 m_Chat_msg = new ChatMsgVoteWraper();
		 m_Team_id = 0;
		 m_Guild_guid = 0;

	}

 	//转化成Protobuffer类型函数
	public ChatInfoVote ToPB()
	{
		ChatInfoVote v = new ChatInfoVote();
		v.Player_name = m_Player_name;
		v.Player_guid = m_Player_guid;
		v.Avatar_id = m_Avatar_id;
		v.Player_level = m_Player_level;
		v.Avatar_frame_id = m_Avatar_frame_id;
		v.Avatar_frame_id1 = m_Avatar_frame_id1;
		v.Config_id = m_Config_id;
		v.Timestamp = m_Timestamp;
		v.Chat_msg = m_Chat_msg.ToPB();
		v.Team_id = m_Team_id;
		v.Guild_guid = m_Guild_guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ChatInfoVote v)
	{
        if (v == null)
            return;
		m_Player_name = v.Player_name;
		m_Player_guid = v.Player_guid;
		m_Avatar_id = v.Avatar_id;
		m_Player_level = v.Player_level;
		m_Avatar_frame_id = v.Avatar_frame_id;
		m_Avatar_frame_id1 = v.Avatar_frame_id1;
		m_Config_id = v.Config_id;
		m_Timestamp = v.Timestamp;
		m_Chat_msg.FromPB(v.Chat_msg);
		m_Team_id = v.Team_id;
		m_Guild_guid = v.Guild_guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ChatInfoVote>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ChatInfoVote pb = ProtoBuf.Serializer.Deserialize<ChatInfoVote>(protoMS);
		FromPB(pb);
		return true;
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
	//头像框ID
	public int m_Avatar_frame_id1;
	public int Avatar_frame_id1
	{
		get { return m_Avatar_frame_id1;}
		set { m_Avatar_frame_id1 = value; }
	}
	//角色配置ID
	public int m_Config_id;
	public int Config_id
	{
		get { return m_Config_id;}
		set { m_Config_id = value; }
	}
	//时间戳
	public Int64 m_Timestamp;
	public Int64 Timestamp
	{
		get { return m_Timestamp;}
		set { m_Timestamp = value; }
	}
	//聊天消息
	public ChatMsgVoteWraper m_Chat_msg;
	public ChatMsgVoteWraper Chat_msg
	{
		get { return m_Chat_msg;}
		set { m_Chat_msg = value; }
	}
	//队伍id
	public UInt64 m_Team_id;
	public UInt64 Team_id
	{
		get { return m_Team_id;}
		set { m_Team_id = value; }
	}
	//公会id 0表示无公会
	public UInt64 m_Guild_guid;
	public UInt64 Guild_guid
	{
		get { return m_Guild_guid;}
		set { m_Guild_guid = value; }
	}


};
//爬塔buf选择记录封装类
[System.Serializable]
public class ClimTowerBufWraper
{

	//构造函数
	public ClimTowerBufWraper()
	{
		 m_Layer = -1;
		 m_BuffId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Layer = -1;
		 m_BuffId = -1;

	}

 	//转化成Protobuffer类型函数
	public ClimTowerBuf ToPB()
	{
		ClimTowerBuf v = new ClimTowerBuf();
		v.Layer = m_Layer;
		v.BuffId = m_BuffId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerBuf v)
	{
        if (v == null)
            return;
		m_Layer = v.Layer;
		m_BuffId = v.BuffId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerBuf>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerBuf pb = ProtoBuf.Serializer.Deserialize<ClimTowerBuf>(protoMS);
		FromPB(pb);
		return true;
	}

	//爬塔层Id
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//选择的bufId
	public int m_BuffId;
	public int BuffId
	{
		get { return m_BuffId;}
		set { m_BuffId = value; }
	}


};
//每层随机到的3个备选buf封装类
[System.Serializable]
public class ClimTowerBuffListWraper
{

	//构造函数
	public ClimTowerBuffListWraper()
	{
		 m_Tower = -1;
		m_BuffId = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Tower = -1;
		m_BuffId = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public ClimTowerBuffList ToPB()
	{
		ClimTowerBuffList v = new ClimTowerBuffList();
		v.Tower = m_Tower;
		for (int i=0; i<(int)m_BuffId.Count; i++)
			v.BuffId.Add( m_BuffId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ClimTowerBuffList v)
	{
        if (v == null)
            return;
		m_Tower = v.Tower;
		m_BuffId.Clear();
		for( int i=0; i<v.BuffId.Count; i++)
			m_BuffId.Add(v.BuffId[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ClimTowerBuffList>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ClimTowerBuffList pb = ProtoBuf.Serializer.Deserialize<ClimTowerBuffList>(protoMS);
		FromPB(pb);
		return true;
	}

	//塔索引
	public int m_Tower;
	public int Tower
	{
		get { return m_Tower;}
		set { m_Tower = value; }
	}
	//每个塔备选BufId
	public List<int> m_BuffId;
	public int SizeBuffId()
	{
		return m_BuffId.Count;
	}
	public List<int> GetBuffId()
	{
		return m_BuffId;
	}
	public int GetBuffId(int Index)
	{
		if(Index<0 || Index>=(int)m_BuffId.Count)
			return -1;
		return m_BuffId[Index];
	}
	public void SetBuffId( List<int> v )
	{
		m_BuffId=v;
	}
	public void SetBuffId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_BuffId.Count)
			return;
		m_BuffId[Index] = v;
	}
	public void AddBuffId( int v=-1 )
	{
		m_BuffId.Add(v);
	}
	public void ClearBuffId( )
	{
		m_BuffId.Clear();
	}


};
