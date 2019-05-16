
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = -1;
		 m_Quality = -1;

	}

 	//转化成Protobuffer类型函数
	public AttrKeyValue ToPB()
	{
		AttrKeyValue v = new AttrKeyValue();
		v.Key = m_Key;
		v.Value = m_Value;
		v.Quality = m_Quality;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Chat_content = "";
		 m_Chat_voice_url = "";
		 m_Chat_voice_secs = -1;

	}

 	//转化成Protobuffer类型函数
	public ChatMsg ToPB()
	{
		ChatMsg v = new ChatMsg();
		v.Chat_content = m_Chat_content;
		v.Chat_voice_url = m_Chat_voice_url;
		v.Chat_voice_secs = m_Chat_voice_secs;

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
		 m_QuestIndex = -1;
		 m_QuestMaxIndex = -1;
		 m_QuestBeginTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfigId = -1;
		 m_Status = -1;
		m_QuestSteps = new List<QuestStepDataWraper>();
		 m_QuestIndex = -1;
		 m_QuestMaxIndex = -1;
		 m_QuestBeginTime = -1;

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
		 m_Status = -1;
		 m_Progress  = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Status = -1;
		 m_Progress  = -1;

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
//世界BOSS信息封装类
[System.Serializable]
public class WorldBossInfoWraper
{

	//构造函数
	public WorldBossInfoWraper()
	{
		 m_LineID = -1;
		 m_HPRate = -1;
		 m_LastDamage = new WorldBossScoreInfoWraper();
		 m_MaxDamage = new WorldBossScoreInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LineID = -1;
		 m_HPRate = -1;
		 m_LastDamage = new WorldBossScoreInfoWraper();
		 m_MaxDamage = new WorldBossScoreInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public WorldBossInfo ToPB()
	{
		WorldBossInfo v = new WorldBossInfo();
		v.LineID = m_LineID;
		v.HPRate = m_HPRate;
		v.LastDamage = m_LastDamage.ToPB();
		v.MaxDamage = m_MaxDamage.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(WorldBossInfo v)
	{
        if (v == null)
            return;
		m_LineID = v.LineID;
		m_HPRate = v.HPRate;
		m_LastDamage.FromPB(v.LastDamage);
		m_MaxDamage.FromPB(v.MaxDamage);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<WorldBossInfo>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		WorldBossInfo pb = ProtoBuf.Serializer.Deserialize<WorldBossInfo>(protoMS);
		FromPB(pb);
		return true;
	}

	//分线ID
	public int m_LineID;
	public int LineID
	{
		get { return m_LineID;}
		set { m_LineID = value; }
	}
	//当前血量百分比
	public int m_HPRate;
	public int HPRate
	{
		get { return m_HPRate;}
		set { m_HPRate = value; }
	}
	//最后一击
	public WorldBossScoreInfoWraper m_LastDamage;
	public WorldBossScoreInfoWraper LastDamage
	{
		get { return m_LastDamage;}
		set { m_LastDamage = value; }
	}
	//最高伤害
	public WorldBossScoreInfoWraper m_MaxDamage;
	public WorldBossScoreInfoWraper MaxDamage
	{
		get { return m_MaxDamage;}
		set { m_MaxDamage = value; }
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
		 m_Title = "";
		 m_Salutation = "";
		 m_Content = "";
		 m_Sender_name = "";
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
		 m_Title = "";
		 m_Salutation = "";
		 m_Content = "";
		 m_Sender_name = "";
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
		v.Title = m_Title;
		v.Salutation = m_Salutation;
		v.Content = m_Content;
		v.Sender_name = m_Sender_name;
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
		m_Title = v.Title;
		m_Salutation = v.Salutation;
		m_Content = v.Content;
		m_Sender_name = v.Sender_name;
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
	public string m_Title;
	public string Title
	{
		get { return m_Title;}
		set { m_Title = value; }
	}
	//称呼
	public string m_Salutation;
	public string Salutation
	{
		get { return m_Salutation;}
		set { m_Salutation = value; }
	}
	//内容
	public string m_Content;
	public string Content
	{
		get { return m_Content;}
		set { m_Content = value; }
	}
	//发送人
	public string m_Sender_name;
	public string Sender_name
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
		 m_IsActive = false;
		 m_TalentScore = -1;

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
		 m_IsActive = false;
		 m_TalentScore = -1;

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
		v.IsActive = m_IsActive;
		v.TalentScore = m_TalentScore;

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
		m_IsActive = v.IsActive;
		m_TalentScore = v.TalentScore;

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
	//出站状态
	public bool m_IsActive;
	public bool IsActive
	{
		get { return m_IsActive;}
		set { m_IsActive = value; }
	}
	//资质评分
	public int m_TalentScore;
	public int TalentScore
	{
		get { return m_TalentScore;}
		set { m_TalentScore = value; }
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = 1;
		 m_Point = 0;
		m_Treasure_Data = new List<TreasureDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public TreasureDepotData ToPB()
	{
		TreasureDepotData v = new TreasureDepotData();
		v.Level = m_Level;
		v.Point = m_Point;
		for (int i=0; i<(int)m_Treasure_Data.Count; i++)
			v.Treasure_Data.Add( m_Treasure_Data[i].ToPB());

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
		 m_QuestType = -1;
		m_QuestIdList = new List<int>();
		 m_DayPorgress = -1;
		 m_LastCompleteTime = -1;
		m_RandomListQuestId = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_QuestType = -1;
		m_QuestIdList = new List<int>();
		 m_DayPorgress = -1;
		 m_LastCompleteTime = -1;
		m_RandomListQuestId = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public RandomQuestData ToPB()
	{
		RandomQuestData v = new RandomQuestData();
		v.QuestType = m_QuestType;
		for (int i=0; i<(int)m_QuestIdList.Count; i++)
			v.QuestIdList.Add( m_QuestIdList[i]);
		v.DayPorgress = m_DayPorgress;
		v.LastCompleteTime = m_LastCompleteTime;
		for (int i=0; i<(int)m_RandomListQuestId.Count; i++)
			v.RandomListQuestId.Add( m_RandomListQuestId[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(RandomQuestData v)
	{
        if (v == null)
            return;
		m_QuestType = v.QuestType;
		m_QuestIdList.Clear();
		for( int i=0; i<v.QuestIdList.Count; i++)
			m_QuestIdList.Add(v.QuestIdList[i]);
		m_DayPorgress = v.DayPorgress;
		m_LastCompleteTime = v.LastCompleteTime;
		m_RandomListQuestId.Clear();
		for( int i=0; i<v.RandomListQuestId.Count; i++)
			m_RandomListQuestId.Add(v.RandomListQuestId[i]);

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

	//任务类型
	public int m_QuestType;
	public int QuestType
	{
		get { return m_QuestType;}
		set { m_QuestType = value; }
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
public class DungeonSituationDataWraper
{

	//构造函数
	public DungeonSituationDataWraper()
	{
		 m_Name = -1;
		m_PlayerData = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Name = -1;
		m_PlayerData = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public DungeonSituationData ToPB()
	{
		DungeonSituationData v = new DungeonSituationData();
		v.Name = m_Name;
		for (int i=0; i<(int)m_PlayerData.Count; i++)
			v.PlayerData.Add( m_PlayerData[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonSituationData v)
	{
        if (v == null)
            return;
		m_Name = v.Name;
		m_PlayerData.Clear();
		for( int i=0; i<v.PlayerData.Count; i++)
			m_PlayerData.Add(v.PlayerData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DungeonSituationData>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DungeonSituationData pb = ProtoBuf.Serializer.Deserialize<DungeonSituationData>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家名字
	public int m_Name;
	public int Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//数据列表
	public List<int> m_PlayerData;
	public int SizePlayerData()
	{
		return m_PlayerData.Count;
	}
	public List<int> GetPlayerData()
	{
		return m_PlayerData;
	}
	public int GetPlayerData(int Index)
	{
		if(Index<0 || Index>=(int)m_PlayerData.Count)
			return -1;
		return m_PlayerData[Index];
	}
	public void SetPlayerData( List<int> v )
	{
		m_PlayerData=v;
	}
	public void SetPlayerData( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_PlayerData.Count)
			return;
		m_PlayerData[Index] = v;
	}
	public void AddPlayerData( int v=-1 )
	{
		m_PlayerData.Add(v);
	}
	public void ClearPlayerData( )
	{
		m_PlayerData.Clear();
	}


};
//副本数据封装类
[System.Serializable]
public class DungeonDataWraper
{

	//构造函数
	public DungeonDataWraper()
	{
		m_Data = new List<DungeonSituationDataWraper>();
		 m_DurationMentTime = -1;
		 m_ConclusionTime = -1;
		 m_PrepareTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Data = new List<DungeonSituationDataWraper>();
		 m_DurationMentTime = -1;
		 m_ConclusionTime = -1;
		 m_PrepareTime = -1;

	}

 	//转化成Protobuffer类型函数
	public DungeonData ToPB()
	{
		DungeonData v = new DungeonData();
		for (int i=0; i<(int)m_Data.Count; i++)
			v.Data.Add( m_Data[i].ToPB());
		v.DurationMentTime = m_DurationMentTime;
		v.ConclusionTime = m_ConclusionTime;
		v.PrepareTime = m_PrepareTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DungeonData v)
	{
        if (v == null)
            return;
		m_Data.Clear();
		for( int i=0; i<v.Data.Count; i++)
			m_Data.Add( new DungeonSituationDataWraper());
		for( int i=0; i<v.Data.Count; i++)
			m_Data[i].FromPB(v.Data[i]);
		m_DurationMentTime = v.DurationMentTime;
		m_ConclusionTime = v.ConclusionTime;
		m_PrepareTime = v.PrepareTime;

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

	//副本数据
	public List<DungeonSituationDataWraper> m_Data;
	public int SizeData()
	{
		return m_Data.Count;
	}
	public List<DungeonSituationDataWraper> GetData()
	{
		return m_Data;
	}
	public DungeonSituationDataWraper GetData(int Index)
	{
		if(Index<0 || Index>=(int)m_Data.Count)
			return new DungeonSituationDataWraper();
		return m_Data[Index];
	}
	public void SetData( List<DungeonSituationDataWraper> v )
	{
		m_Data=v;
	}
	public void SetData( int Index, DungeonSituationDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Data.Count)
			return;
		m_Data[Index] = v;
	}
	public void AddData( DungeonSituationDataWraper v )
	{
		m_Data.Add(v);
	}
	public void ClearData( )
	{
		m_Data.Clear();
	}
	//副本释放
	public Int64 m_DurationMentTime;
	public Int64 DurationMentTime
	{
		get { return m_DurationMentTime;}
		set { m_DurationMentTime = value; }
	}
	//副本结算时间
	public Int64 m_ConclusionTime;
	public Int64 ConclusionTime
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
		m_Function = new List<int>();
		 m_TargetType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = 0;
		 m_MinLevel = 0;
		 m_MaxLevel = 0;
		m_Function = new List<int>();
		 m_TargetType = 0;

	}

 	//转化成Protobuffer类型函数
	public TeamTarget ToPB()
	{
		TeamTarget v = new TeamTarget();
		v.Id = m_Id;
		v.MinLevel = m_MinLevel;
		v.MaxLevel = m_MaxLevel;
		for (int i=0; i<(int)m_Function.Count; i++)
			v.Function.Add( m_Function[i]);
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
		m_Function.Clear();
		for( int i=0; i<v.Function.Count; i++)
			m_Function.Add(v.Function[i]);
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
	public List<int> m_Function;
	public int SizeFunction()
	{
		return m_Function.Count;
	}
	public List<int> GetFunction()
	{
		return m_Function;
	}
	public int GetFunction(int Index)
	{
		if(Index<0 || Index>=(int)m_Function.Count)
			return -1;
		return m_Function[Index];
	}
	public void SetFunction( List<int> v )
	{
		m_Function=v;
	}
	public void SetFunction( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Function.Count)
			return;
		m_Function[Index] = v;
	}
	public void AddFunction( int v=-1 )
	{
		m_Function.Add(v);
	}
	public void ClearFunction( )
	{
		m_Function.Clear();
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
		 m_ObjId = -1;
		 m_CasterId = -1;
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
		 m_ObjId = -1;
		 m_CasterId = -1;
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
	public int m_ObjId;
	public int ObjId
	{
		get { return m_ObjId;}
		set { m_ObjId = value; }
	}
	//Buff释放者ID
	public int m_CasterId;
	public int CasterId
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

	//头发
	public int m_TreasureHair;
	public int TreasureHair
	{
		get { return m_TreasureHair;}
		set { m_TreasureHair = value; }
	}
	//头部
	public int m_TreasureHead;
	public int TreasureHead
	{
		get { return m_TreasureHead;}
		set { m_TreasureHead = value; }
	}
	//身体
	public int m_TreasureBody;
	public int TreasureBody
	{
		get { return m_TreasureBody;}
		set { m_TreasureBody = value; }
	}
	//武器
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

	}

	//重置函数
	public void ResetWraper()
	{
		m_Camps = new List<MatchRoomCampsWraper>();
		 m_MatchTarget = new MatchTargetInfoWraper();
		 m_RoomId = 0;
		 m_MatchType = -1;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Bossid = -1;
		 m_Number = -1;
		 m_Dungeonid = -1;
		 m_MaxNumber = -1;
		 m_RefreshType = -1;

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
		 m_NextLevel = -1;
		m_CurLevelAttr = new List<AttrKeyValueWraper>();
		m_NextLevelAttr = new List<AttrKeyValueWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_CurLevel = -1;
		 m_NextLevel = -1;
		m_CurLevelAttr = new List<AttrKeyValueWraper>();
		m_NextLevelAttr = new List<AttrKeyValueWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillPosInfo ToPB()
	{
		SkillPosInfo v = new SkillPosInfo();
		v.Pos = m_Pos;
		v.CurLevel = m_CurLevel;
		v.NextLevel = m_NextLevel;
		for (int i=0; i<(int)m_CurLevelAttr.Count; i++)
			v.CurLevelAttr.Add( m_CurLevelAttr[i].ToPB());
		for (int i=0; i<(int)m_NextLevelAttr.Count; i++)
			v.NextLevelAttr.Add( m_NextLevelAttr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillPosInfo v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_CurLevel = v.CurLevel;
		m_NextLevel = v.NextLevel;
		m_CurLevelAttr.Clear();
		for( int i=0; i<v.CurLevelAttr.Count; i++)
			m_CurLevelAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.CurLevelAttr.Count; i++)
			m_CurLevelAttr[i].FromPB(v.CurLevelAttr[i]);
		m_NextLevelAttr.Clear();
		for( int i=0; i<v.NextLevelAttr.Count; i++)
			m_NextLevelAttr.Add( new AttrKeyValueWraper());
		for( int i=0; i<v.NextLevelAttr.Count; i++)
			m_NextLevelAttr[i].FromPB(v.NextLevelAttr[i]);

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
	//技能位置下一个等级
	public int m_NextLevel;
	public int NextLevel
	{
		get { return m_NextLevel;}
		set { m_NextLevel = value; }
	}
	//当前等级属性加成
	public List<AttrKeyValueWraper> m_CurLevelAttr;
	public int SizeCurLevelAttr()
	{
		return m_CurLevelAttr.Count;
	}
	public List<AttrKeyValueWraper> GetCurLevelAttr()
	{
		return m_CurLevelAttr;
	}
	public AttrKeyValueWraper GetCurLevelAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_CurLevelAttr.Count)
			return new AttrKeyValueWraper();
		return m_CurLevelAttr[Index];
	}
	public void SetCurLevelAttr( List<AttrKeyValueWraper> v )
	{
		m_CurLevelAttr=v;
	}
	public void SetCurLevelAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_CurLevelAttr.Count)
			return;
		m_CurLevelAttr[Index] = v;
	}
	public void AddCurLevelAttr( AttrKeyValueWraper v )
	{
		m_CurLevelAttr.Add(v);
	}
	public void ClearCurLevelAttr( )
	{
		m_CurLevelAttr.Clear();
	}
	//下一等级属性加成
	public List<AttrKeyValueWraper> m_NextLevelAttr;
	public int SizeNextLevelAttr()
	{
		return m_NextLevelAttr.Count;
	}
	public List<AttrKeyValueWraper> GetNextLevelAttr()
	{
		return m_NextLevelAttr;
	}
	public AttrKeyValueWraper GetNextLevelAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_NextLevelAttr.Count)
			return new AttrKeyValueWraper();
		return m_NextLevelAttr[Index];
	}
	public void SetNextLevelAttr( List<AttrKeyValueWraper> v )
	{
		m_NextLevelAttr=v;
	}
	public void SetNextLevelAttr( int Index, AttrKeyValueWraper v )
	{
		if(Index<0 || Index>=(int)m_NextLevelAttr.Count)
			return;
		m_NextLevelAttr[Index] = v;
	}
	public void AddNextLevelAttr( AttrKeyValueWraper v )
	{
		m_NextLevelAttr.Add(v);
	}
	public void ClearNextLevelAttr( )
	{
		m_NextLevelAttr.Clear();
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LastTime = 0;
		 m_CurLayer = 1;
		 m_MaxLayer = 0;
		 m_ResetLayerTime = 0;
		m_FirstGet = new List<FirstVicGetWraper>();

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
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;

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
	public int m_Id;
	public int Id
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Index = -1;
		 m_TemplateId = -1;
		 m_MaxCount = -1;
		 m_CurCount = -1;
		 m_Description = -1;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TypeId = -1;
		 m_Index = -1;
		m_TargetContent = new List<DungeonTargetContentWraper>();
		 m_Description = -1;

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
		 m_ObjId = -1;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_Status = -1;
		 m_TargetPos = new Vector3Wraper();
		 m_ObjData = new byte[0];

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Pos = new Vector3Wraper();
		 m_Dir = (float)-1;
		 m_Status = -1;
		 m_TargetPos = new Vector3Wraper();
		 m_ObjData = new byte[0];

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
	public int m_ObjId;
	public int ObjId
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


};
//删除obj所需信息封装类
[System.Serializable]
public class ObjDeleteInfoWraper
{

	//构造函数
	public ObjDeleteInfoWraper()
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
	public ObjDeleteInfo ToPB()
	{
		ObjDeleteInfo v = new ObjDeleteInfo();
		v.ObjId = m_ObjId;
		v.SceneId = m_SceneId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ObjDeleteInfo v)
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DungeonConfigId = -1;
		 m_SceneConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public MatchTargetInfo ToPB()
	{
		MatchTargetInfo v = new MatchTargetInfo();
		v.DungeonConfigId = m_DungeonConfigId;
		v.SceneConfigId = m_SceneConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MatchTargetInfo v)
	{
        if (v == null)
            return;
		m_DungeonConfigId = v.DungeonConfigId;
		m_SceneConfigId = v.SceneConfigId;

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
	public Int64 m_Begin;
	public Int64 Begin
	{
		get { return m_Begin;}
		set { m_Begin = value; }
	}
	//活动结束时间
	public Int64 m_End;
	public Int64 End
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
		 m_BeginTime = -1;
		 m_EndTime = -1;
		m_RewardInfo = new List<SpecLoginRewardWraper>();
		 m_State = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_BeginTime = -1;
		 m_EndTime = -1;
		m_RewardInfo = new List<SpecLoginRewardWraper>();
		 m_State = -1;

	}

 	//转化成Protobuffer类型函数
	public SpecLoginInfo ToPB()
	{
		SpecLoginInfo v = new SpecLoginInfo();
		v.Id = m_Id;
		v.BeginTime = m_BeginTime;
		v.EndTime = m_EndTime;
		for (int i=0; i<(int)m_RewardInfo.Count; i++)
			v.RewardInfo.Add( m_RewardInfo[i].ToPB());
		v.State = m_State;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SpecLoginInfo v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_BeginTime = v.BeginTime;
		m_EndTime = v.EndTime;
		m_RewardInfo.Clear();
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo.Add( new SpecLoginRewardWraper());
		for( int i=0; i<v.RewardInfo.Count; i++)
			m_RewardInfo[i].FromPB(v.RewardInfo[i]);
		m_State = v.State;

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
	//活动开始时间
	public Int64 m_BeginTime;
	public Int64 BeginTime
	{
		get { return m_BeginTime;}
		set { m_BeginTime = value; }
	}
	//活动结束时间
	public Int64 m_EndTime;
	public Int64 EndTime
	{
		get { return m_EndTime;}
		set { m_EndTime = value; }
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
	//状态
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
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
		 m_Key = -1;
		m_StringList = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		m_StringList = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public AppendString ToPB()
	{
		AppendString v = new AppendString();
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ServerFast = new StarBattleTeamInfoWraper();
		 m_ServerFirst = new StarBattleTeamInfoWraper();
		 m_ServerWeekFast = new StarBattleTeamInfoWraper();
		 m_Id = -1;
		 m_Npcid = -1;

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

	//本服最快通关
	public StarBattleTeamInfoWraper m_ServerFast;
	public StarBattleTeamInfoWraper ServerFast
	{
		get { return m_ServerFast;}
		set { m_ServerFast = value; }
	}
	//本服首通
	public StarBattleTeamInfoWraper m_ServerFirst;
	public StarBattleTeamInfoWraper ServerFirst
	{
		get { return m_ServerFirst;}
		set { m_ServerFirst = value; }
	}
	//本周最快
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
		 m_ObjId = -1;
		 m_Id = -1;
		 m_X = -1;
		 m_Z = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjId = -1;
		 m_Id = -1;
		 m_X = -1;
		 m_Z = -1;

	}

 	//转化成Protobuffer类型函数
	public ObjPosInfo ToPB()
	{
		ObjPosInfo v = new ObjPosInfo();
		v.ObjId = m_ObjId;
		v.Id = m_Id;
		v.X = m_X;
		v.Z = m_Z;

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
	public int m_ObjId;
	public int ObjId
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


};
