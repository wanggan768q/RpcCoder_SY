
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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;
		 m_Nickname = "";
		 m_ConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public CharacterInfo ToPB()
	{
		CharacterInfo v = new CharacterInfo();
		v.RoleId = m_RoleId;
		v.Nickname = m_Nickname;
		v.ConfigId = m_ConfigId;

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


};
