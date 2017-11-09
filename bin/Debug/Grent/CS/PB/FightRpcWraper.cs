
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBFight.cs
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


//使用技能动作通知封装类
[System.Serializable]
public class FightRpcUseSkillActionNotifyWraper
{

	//构造函数
	public FightRpcUseSkillActionNotifyWraper()
	{
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_X = -1;
		 m_Y = -1;
		 m_Dir = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ObjTargetId = -1;
		 m_SkillId = -1;
		 m_X = -1;
		 m_Y = -1;
		 m_Dir = -1;

	}

 	//转化成Protobuffer类型函数
	public FightRpcUseSkillActionNotify ToPB()
	{
		FightRpcUseSkillActionNotify v = new FightRpcUseSkillActionNotify();
		v.ObjTargetId = m_ObjTargetId;
		v.SkillId = m_SkillId;
		v.X = m_X;
		v.Y = m_Y;
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(FightRpcUseSkillActionNotify v)
	{
        if (v == null)
            return;
		m_ObjTargetId = v.ObjTargetId;
		m_SkillId = v.SkillId;
		m_X = v.X;
		m_Y = v.Y;
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcUseSkillActionNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		FightRpcUseSkillActionNotify pb = ProtoBuf.Serializer.Deserialize<FightRpcUseSkillActionNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//objId
	public int m_ObjTargetId;
	public int ObjTargetId
	{
		get { return m_ObjTargetId;}
		set { m_ObjTargetId = value; }
	}
	//技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}
	//技能释放目标点
	public int m_X;
	public int X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//技能释放目标点
	public int m_Y;
	public int Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//技能释放方向
	public int m_Dir;
	public int Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
