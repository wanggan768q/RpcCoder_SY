
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


};
//v3封装类
[System.Serializable]
public class V3Wraper
{

	//构造函数
	public V3Wraper()
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
	public V3 ToPB()
	{
		V3 v = new V3();
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(V3 v)
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
		ProtoBuf.Serializer.Serialize<V3>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		V3 pb = ProtoBuf.Serializer.Deserialize<V3>(protoMS);
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
		 m_SceneId = -1;
		 m_Level = -1;
		 m_Name = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_Mp = -1;
		 m_Status = -1;
		 m_MemId = -1;
		 m_MaxHp = -1;
		 m_MaxMp = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_SceneId = -1;
		 m_Level = -1;
		 m_Name = "";
		 m_ConfigId = -1;
		 m_Hp = -1;
		 m_Mp = -1;
		 m_Status = -1;
		 m_MemId = -1;
		 m_MaxHp = -1;
		 m_MaxMp = -1;

	}

 	//转化成Protobuffer类型函数
	public TeamMemberInfo ToPB()
	{
		TeamMemberInfo v = new TeamMemberInfo();
		v.RoleId = m_RoleId;
		v.SceneId = m_SceneId;
		v.Level = m_Level;
		v.Name = m_Name;
		v.ConfigId = m_ConfigId;
		v.Hp = m_Hp;
		v.Mp = m_Mp;
		v.Status = m_Status;
		v.MemId = m_MemId;
		v.MaxHp = m_MaxHp;
		v.MaxMp = m_MaxMp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TeamMemberInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_SceneId = v.SceneId;
		m_Level = v.Level;
		m_Name = v.Name;
		m_ConfigId = v.ConfigId;
		m_Hp = v.Hp;
		m_Mp = v.Mp;
		m_Status = v.Status;
		m_MemId = v.MemId;
		m_MaxHp = v.MaxHp;
		m_MaxMp = v.MaxMp;

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
	//队员场景id
	public int m_SceneId;
	public int SceneId
	{
		get { return m_SceneId;}
		set { m_SceneId = value; }
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
	//Mp
	public int m_Mp;
	public int Mp
	{
		get { return m_Mp;}
		set { m_Mp = value; }
	}
	//Status
	public int m_Status;
	public int Status
	{
		get { return m_Status;}
		set { m_Status = value; }
	}
	//MemId
	public int m_MemId;
	public int MemId
	{
		get { return m_MemId;}
		set { m_MemId = value; }
	}
	//生命值
	public Int64 m_MaxHp;
	public Int64 MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}
	//生命值
	public Int64 m_MaxMp;
	public Int64 MaxMp
	{
		get { return m_MaxMp;}
		set { m_MaxMp = value; }
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
		 m_TeamId = -1;
		 m_TeamType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_Members = new List<TeamMemberInfoWraper>();
		 m_LeaderRoleId = 0;
		 m_TeamId = -1;
		 m_TeamType = -1;

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
	public int m_TeamId;
	public int TeamId
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
		 m_Scene_id = -1;
		 m_Memid = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Level = -1;
		 m_Scene_id = -1;
		 m_Memid = -1;

	}

 	//转化成Protobuffer类型函数
	public OnlineUserInfo ToPB()
	{
		OnlineUserInfo v = new OnlineUserInfo();
		v.RoleId = m_RoleId;
		v.Level = m_Level;
		v.Scene_id = m_Scene_id;
		v.Memid = m_Memid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(OnlineUserInfo v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;
		m_Level = v.Level;
		m_Scene_id = v.Scene_id;
		m_Memid = v.Memid;

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
	//scene_id
	public int m_Scene_id;
	public int Scene_id
	{
		get { return m_Scene_id;}
		set { m_Scene_id = value; }
	}
	//Memid
	public int m_Memid;
	public int Memid
	{
		get { return m_Memid;}
		set { m_Memid = value; }
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public AttrKeyValue ToPB()
	{
		AttrKeyValue v = new AttrKeyValue();
		v.Key = m_Key;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(AttrKeyValue v)
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


};
//ItemAttr封装类
[System.Serializable]
public class ItemAttrWraper
{

	//构造函数
	public ItemAttrWraper()
	{
		m_BaseAttr = new List<AttrKeyValueWraper>();
		m_ExtraAttr = new List<AttrKeyValueWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_BaseAttr = new List<AttrKeyValueWraper>();
		m_ExtraAttr = new List<AttrKeyValueWraper>();

	}

 	//转化成Protobuffer类型函数
	public ItemAttr ToPB()
	{
		ItemAttr v = new ItemAttr();
		for (int i=0; i<(int)m_BaseAttr.Count; i++)
			v.BaseAttr.Add( m_BaseAttr[i].ToPB());
		for (int i=0; i<(int)m_ExtraAttr.Count; i++)
			v.ExtraAttr.Add( m_ExtraAttr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemAttr v)
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

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ItemAttr>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ItemAttr pb = ProtoBuf.Serializer.Deserialize<ItemAttr>(protoMS);
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
	//ExtraAttr
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


};
//ItemData封装类
[System.Serializable]
public class ItemDataWraper
{

	//构造函数
	public ItemDataWraper()
	{
		 m_Guid = 0;
		 m_IsLock = false;
		 m_OverlayCount = -1;
		 m_ConfigId = -1;
		 m_Attr = new ItemAttrWraper();
		 m_BattleScore = -1;
		 m_IsNull = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_IsLock = false;
		 m_OverlayCount = -1;
		 m_ConfigId = -1;
		 m_Attr = new ItemAttrWraper();
		 m_BattleScore = -1;
		 m_IsNull = false;

	}

 	//转化成Protobuffer类型函数
	public ItemData ToPB()
	{
		ItemData v = new ItemData();
		v.Guid = m_Guid;
		v.IsLock = m_IsLock;
		v.OverlayCount = m_OverlayCount;
		v.ConfigId = m_ConfigId;
		v.Attr = m_Attr.ToPB();
		v.BattleScore = m_BattleScore;
		v.IsNull = m_IsNull;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemData v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_IsLock = v.IsLock;
		m_OverlayCount = v.OverlayCount;
		m_ConfigId = v.ConfigId;
		m_Attr.FromPB(v.Attr);
		m_BattleScore = v.BattleScore;
		m_IsNull = v.IsNull;

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

	//物品GUID
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
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
	public ItemAttrWraper m_Attr;
	public ItemAttrWraper Attr
	{
		get { return m_Attr;}
		set { m_Attr = value; }
	}
	//装备评分
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//是否是空
	public bool m_IsNull;
	public bool IsNull
	{
		get { return m_IsNull;}
		set { m_IsNull = value; }
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
//ItemObj封装类
[System.Serializable]
public class ItemObjWraper
{

	//构造函数
	public ItemObjWraper()
	{
		 m_Pos = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public ItemObj ToPB()
	{
		ItemObj v = new ItemObj();
		v.Pos = m_Pos;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ItemObj v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;
		m_ItemData.FromPB(v.ItemData);

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
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Timestamp = 0;
		 m_Chat_msg = new ChatMsgWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Timestamp = 0;
		 m_Chat_msg = new ChatMsgWraper();

	}

 	//转化成Protobuffer类型函数
	public ChatInfo ToPB()
	{
		ChatInfo v = new ChatInfo();
		v.Player_name = m_Player_name;
		v.Player_guid = m_Player_guid;
		v.Avatar_id = m_Avatar_id;
		v.Avatar_frame_id = m_Avatar_frame_id;
		v.Config_id = m_Config_id;
		v.Timestamp = m_Timestamp;
		v.Chat_msg = m_Chat_msg.ToPB();

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
		m_Avatar_frame_id = v.Avatar_frame_id;
		m_Config_id = v.Config_id;
		m_Timestamp = v.Timestamp;
		m_Chat_msg.FromPB(v.Chat_msg);

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
