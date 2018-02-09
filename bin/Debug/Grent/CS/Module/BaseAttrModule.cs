/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBaseAttr.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class BaseAttrRPC
{
	public const int ModuleId = 7;
	
	public const int RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 751;
	public const int RPC_CODE_BASEATTR_SYNC_NOTIFY = 752;

	
	private static BaseAttrRPC m_Instance = null;
	public static BaseAttrRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BaseAttrData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_BASEATTR_SYNC_NOTIFY, SyncCB);


		return true;
	}


	/**
	*基础数据-->同步玩家数据 RPC请求
	*/
	public void SyncData(ReplyHandler replyCB)
	{
		BaseAttrRpcSyncDataAskWraper askPBWraper = new BaseAttrRpcSyncDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BASEATTR_SYNCDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BaseAttrRpcSyncDataReplyWraper replyPBWraper = new BaseAttrRpcSyncDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*基础数据-->数据推送 服务器通知回调
	*/
	public static void SyncCB( ModMessage notifyMsg )
	{
		BaseAttrRpcSyncNotifyWraper notifyPBWraper = new BaseAttrRpcSyncNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SyncCBDelegate != null )
			SyncCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SyncCBDelegate = null;



}

public class BaseAttrData
{
	public enum SyncIdE
	{
 		EXP                                        = 701,  //经验
 		LEVEL                                      = 703,  //玩家等级
 		SERVERTIME                                 = 704,  //服务器时间
 		ROLEID                                     = 705,  //人物唯一ID
 		STRENGTH                                   = 707,  //力量
 		AGILITY                                    = 708,  //敏捷
 		INTELLECTUAL                               = 709,  //智力
 		ENDURANCE                                  = 710,  //耐力
 		SPIRIT                                     = 711,  //精神
 		HP                                         = 712,  //生命值
 		MAXHP                                      = 714,  //生命值
 		PHYSICATTACK                               = 715,  //物理攻击
 		PHYSICDEFENSE                              = 716,  //物理防御
 		MAGICATTACK                                = 719,  //魔法攻击
 		MAGICDEFENSE                               = 720,  //魔法防御
 		HIT                                        = 721,  //命中值
 		HITRATE                                    = 722,  //命中率
 		MISS                                       = 723,  //闪避值
 		MISSRATE                                   = 724,  //闪避率
 		CRITICAL                                   = 725,  //暴击值
 		CRITICALRATE                               = 726,  //暴击率
 		TENACITY                                   = 727,  //韧性值
 		TENACITYRATE                               = 728,  //韧性率
 		PENET                                      = 729,  //穿透值
 		PENETRATE                                  = 730,  //穿透率
 		DODG                                       = 731,  //格挡值
 		DODGRATE                                   = 732,  //格挡率
 		CRITICALADDITION                           = 733,  //暴击加伤值
 		CRITICALADDITIONRATE                       = 734,  //暴击加伤率
 		CRITICALIMMUNE                             = 735,  //暴击免伤
 		CRITICALIMMUNERATE                         = 736,  //暴击免伤率
 		MISSLEVEL                                  = 737,  //闪避等级
 		CRITICALLEVEL                              = 738,  //暴击等级
 		DODGLEVEL                                  = 739,  //格挡等级
 		MOVESPEED                                  = 740,  //移动速度
 		DIZZYSTATE                                 = 741,  //眩晕状态
 		GODSTATE                                   = 742,  //霸体状态
 		CANTMOVESTATE                              = 743,  //不能移动状态
 		PHYSICADDITION                             = 745,  //物理加伤值
 		MAGICADDITION                              = 746,  //魔法加伤值
 		PHYSICOPPOSE                               = 747,  //物理抗性
 		MAGICOPPOSE                                = 748,  //魔法抗性

	}
	
	private static BaseAttrData m_Instance = null;
	public static BaseAttrData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{
			case SyncIdE.EXP:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Exp = iValue;
				break;
			case SyncIdE.LEVEL:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.Level = iValue;
				break;
			case SyncIdE.SERVERTIME:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ServerTime = lValue;
				break;
			case SyncIdE.ROLEID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RoleId = lValue;
				break;
			case SyncIdE.STRENGTH:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Strength = lValue;
				break;
			case SyncIdE.AGILITY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Agility = lValue;
				break;
			case SyncIdE.INTELLECTUAL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Intellectual = lValue;
				break;
			case SyncIdE.ENDURANCE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Endurance = lValue;
				break;
			case SyncIdE.SPIRIT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Spirit = lValue;
				break;
			case SyncIdE.HP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Hp = lValue;
				break;
			case SyncIdE.MAXHP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MaxHp = lValue;
				break;
			case SyncIdE.PHYSICATTACK:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PhysicAttack = lValue;
				break;
			case SyncIdE.PHYSICDEFENSE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PhysicDefense = lValue;
				break;
			case SyncIdE.MAGICATTACK:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MagicAttack = lValue;
				break;
			case SyncIdE.MAGICDEFENSE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MagicDefense = lValue;
				break;
			case SyncIdE.HIT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Hit = lValue;
				break;
			case SyncIdE.HITRATE:
				m_Instance.HitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MISS:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Miss = lValue;
				break;
			case SyncIdE.MISSRATE:
				m_Instance.MissRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICAL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Critical = lValue;
				break;
			case SyncIdE.CRITICALRATE:
				m_Instance.CriticalRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.TENACITY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Tenacity = lValue;
				break;
			case SyncIdE.TENACITYRATE:
				m_Instance.TenacityRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.PENET:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Penet = lValue;
				break;
			case SyncIdE.PENETRATE:
				m_Instance.PenetRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DODG:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Dodg = lValue;
				break;
			case SyncIdE.DODGRATE:
				m_Instance.DodgRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICALADDITION:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalAddition = lValue;
				break;
			case SyncIdE.CRITICALADDITIONRATE:
				m_Instance.CriticalAdditionRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICALIMMUNE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalImmune = lValue;
				break;
			case SyncIdE.CRITICALIMMUNERATE:
				m_Instance.CriticalImmuneRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MISSLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MissLevel = lValue;
				break;
			case SyncIdE.CRITICALLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalLevel = lValue;
				break;
			case SyncIdE.DODGLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DodgLevel = lValue;
				break;
			case SyncIdE.MOVESPEED:
				m_Instance.MoveSpeed = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DIZZYSTATE:
				m_Instance.DizzyState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.GODSTATE:
				m_Instance.GodState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.CANTMOVESTATE:
				m_Instance.CantMoveState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.PHYSICADDITION:
				m_Instance.PhysicAddition = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MAGICADDITION:
				m_Instance.MagicAddition = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.PHYSICOPPOSE:
				m_Instance.PhysicOppose = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MAGICOPPOSE:
				m_Instance.MagicOppose = BitConverter.ToSingle(updateBuffer,0);
				break;

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Ex.Logger.Log("BaseAttrData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public BaseAttrData()
	{
		 m_Exp = 0;
		 m_Level = 0;
		 m_ServerTime = -1;
		 m_RoleId = -1;
		 m_Strength = 0;
		 m_Agility = 0;
		 m_Intellectual = 0;
		 m_Endurance = 0;
		 m_Spirit = 0;
		 m_Hp = 0;
		 m_MaxHp = 0;
		 m_PhysicAttack = 0;
		 m_PhysicDefense = 0;
		 m_MagicAttack = 0;
		 m_MagicDefense = 0;
		 m_Hit = 0;
		 m_HitRate = (float)0;
		 m_Miss = 0;
		 m_MissRate = (float)0;
		 m_Critical = 0;
		 m_CriticalRate = (float)0;
		 m_Tenacity = 0;
		 m_TenacityRate = (float)0;
		 m_Penet = 0;
		 m_PenetRate = (float)0;
		 m_Dodg = 0;
		 m_DodgRate = (float)0;
		 m_CriticalAddition = 0;
		 m_CriticalAdditionRate = (float)0;
		 m_CriticalImmune = 0;
		 m_CriticalImmuneRate = (float)0;
		 m_MissLevel = 0;
		 m_CriticalLevel = 0;
		 m_DodgLevel = 0;
		 m_MoveSpeed = (float)0;
		 m_DizzyState = false;
		 m_GodState = false;
		 m_CantMoveState = false;
		 m_PhysicAddition = (float)0;
		 m_MagicAddition = (float)0;
		 m_PhysicOppose = (float)0;
		 m_MagicOppose = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Exp = 0;
		 m_Level = 0;
		 m_ServerTime = -1;
		 m_RoleId = -1;
		 m_Strength = 0;
		 m_Agility = 0;
		 m_Intellectual = 0;
		 m_Endurance = 0;
		 m_Spirit = 0;
		 m_Hp = 0;
		 m_MaxHp = 0;
		 m_PhysicAttack = 0;
		 m_PhysicDefense = 0;
		 m_MagicAttack = 0;
		 m_MagicDefense = 0;
		 m_Hit = 0;
		 m_HitRate = (float)0;
		 m_Miss = 0;
		 m_MissRate = (float)0;
		 m_Critical = 0;
		 m_CriticalRate = (float)0;
		 m_Tenacity = 0;
		 m_TenacityRate = (float)0;
		 m_Penet = 0;
		 m_PenetRate = (float)0;
		 m_Dodg = 0;
		 m_DodgRate = (float)0;
		 m_CriticalAddition = 0;
		 m_CriticalAdditionRate = (float)0;
		 m_CriticalImmune = 0;
		 m_CriticalImmuneRate = (float)0;
		 m_MissLevel = 0;
		 m_CriticalLevel = 0;
		 m_DodgLevel = 0;
		 m_MoveSpeed = (float)0;
		 m_DizzyState = false;
		 m_GodState = false;
		 m_CantMoveState = false;
		 m_PhysicAddition = (float)0;
		 m_MagicAddition = (float)0;
		 m_PhysicOppose = (float)0;
		 m_MagicOppose = (float)0;

	}

 	//转化成Protobuffer类型函数
	public BaseAttrUserDataV1 ToPB()
	{
		BaseAttrUserDataV1 v = new BaseAttrUserDataV1();
		v.Exp = m_Exp;
		v.Level = m_Level;
		v.ServerTime = m_ServerTime;
		v.RoleId = m_RoleId;
		v.Strength = m_Strength;
		v.Agility = m_Agility;
		v.Intellectual = m_Intellectual;
		v.Endurance = m_Endurance;
		v.Spirit = m_Spirit;
		v.Hp = m_Hp;
		v.MaxHp = m_MaxHp;
		v.PhysicAttack = m_PhysicAttack;
		v.PhysicDefense = m_PhysicDefense;
		v.MagicAttack = m_MagicAttack;
		v.MagicDefense = m_MagicDefense;
		v.Hit = m_Hit;
		v.HitRate = m_HitRate;
		v.Miss = m_Miss;
		v.MissRate = m_MissRate;
		v.Critical = m_Critical;
		v.CriticalRate = m_CriticalRate;
		v.Tenacity = m_Tenacity;
		v.TenacityRate = m_TenacityRate;
		v.Penet = m_Penet;
		v.PenetRate = m_PenetRate;
		v.Dodg = m_Dodg;
		v.DodgRate = m_DodgRate;
		v.CriticalAddition = m_CriticalAddition;
		v.CriticalAdditionRate = m_CriticalAdditionRate;
		v.CriticalImmune = m_CriticalImmune;
		v.CriticalImmuneRate = m_CriticalImmuneRate;
		v.MissLevel = m_MissLevel;
		v.CriticalLevel = m_CriticalLevel;
		v.DodgLevel = m_DodgLevel;
		v.MoveSpeed = m_MoveSpeed;
		v.DizzyState = m_DizzyState;
		v.GodState = m_GodState;
		v.CantMoveState = m_CantMoveState;
		v.PhysicAddition = m_PhysicAddition;
		v.MagicAddition = m_MagicAddition;
		v.PhysicOppose = m_PhysicOppose;
		v.MagicOppose = m_MagicOppose;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrUserDataV1 v)
	{
        if (v == null)
            return;
		m_Exp = v.Exp;
		m_Level = v.Level;
		m_ServerTime = v.ServerTime;
		m_RoleId = v.RoleId;
		m_Strength = v.Strength;
		m_Agility = v.Agility;
		m_Intellectual = v.Intellectual;
		m_Endurance = v.Endurance;
		m_Spirit = v.Spirit;
		m_Hp = v.Hp;
		m_MaxHp = v.MaxHp;
		m_PhysicAttack = v.PhysicAttack;
		m_PhysicDefense = v.PhysicDefense;
		m_MagicAttack = v.MagicAttack;
		m_MagicDefense = v.MagicDefense;
		m_Hit = v.Hit;
		m_HitRate = v.HitRate;
		m_Miss = v.Miss;
		m_MissRate = v.MissRate;
		m_Critical = v.Critical;
		m_CriticalRate = v.CriticalRate;
		m_Tenacity = v.Tenacity;
		m_TenacityRate = v.TenacityRate;
		m_Penet = v.Penet;
		m_PenetRate = v.PenetRate;
		m_Dodg = v.Dodg;
		m_DodgRate = v.DodgRate;
		m_CriticalAddition = v.CriticalAddition;
		m_CriticalAdditionRate = v.CriticalAdditionRate;
		m_CriticalImmune = v.CriticalImmune;
		m_CriticalImmuneRate = v.CriticalImmuneRate;
		m_MissLevel = v.MissLevel;
		m_CriticalLevel = v.CriticalLevel;
		m_DodgLevel = v.DodgLevel;
		m_MoveSpeed = v.MoveSpeed;
		m_DizzyState = v.DizzyState;
		m_GodState = v.GodState;
		m_CantMoveState = v.CantMoveState;
		m_PhysicAddition = v.PhysicAddition;
		m_MagicAddition = v.MagicAddition;
		m_PhysicOppose = v.PhysicOppose;
		m_MagicOppose = v.MagicOppose;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrUserDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrUserDataV1 pb = ProtoBuf.Serializer.Deserialize<BaseAttrUserDataV1>(protoMS);
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
	//玩家等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//服务器时间
	public Int64 m_ServerTime;
	public Int64 ServerTime
	{
		get { return m_ServerTime;}
		set { m_ServerTime = value; }
	}
	//人物唯一ID
	public Int64 m_RoleId;
	public Int64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//力量
	public int m_Strength;
	public int Strength
	{
		get { return m_Strength;}
		set { m_Strength = value; }
	}
	//敏捷
	public int m_Agility;
	public int Agility
	{
		get { return m_Agility;}
		set { m_Agility = value; }
	}
	//智力
	public int m_Intellectual;
	public int Intellectual
	{
		get { return m_Intellectual;}
		set { m_Intellectual = value; }
	}
	//耐力
	public int m_Endurance;
	public int Endurance
	{
		get { return m_Endurance;}
		set { m_Endurance = value; }
	}
	//精神
	public int m_Spirit;
	public int Spirit
	{
		get { return m_Spirit;}
		set { m_Spirit = value; }
	}
	//生命值
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//生命值
	public int m_MaxHp;
	public int MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}
	//物理攻击
	public int m_PhysicAttack;
	public int PhysicAttack
	{
		get { return m_PhysicAttack;}
		set { m_PhysicAttack = value; }
	}
	//物理防御
	public int m_PhysicDefense;
	public int PhysicDefense
	{
		get { return m_PhysicDefense;}
		set { m_PhysicDefense = value; }
	}
	//魔法攻击
	public int m_MagicAttack;
	public int MagicAttack
	{
		get { return m_MagicAttack;}
		set { m_MagicAttack = value; }
	}
	//魔法防御
	public int m_MagicDefense;
	public int MagicDefense
	{
		get { return m_MagicDefense;}
		set { m_MagicDefense = value; }
	}
	//命中值
	public int m_Hit;
	public int Hit
	{
		get { return m_Hit;}
		set { m_Hit = value; }
	}
	//命中率
	public float m_HitRate;
	public float HitRate
	{
		get { return m_HitRate;}
		set { m_HitRate = value; }
	}
	//闪避值
	public int m_Miss;
	public int Miss
	{
		get { return m_Miss;}
		set { m_Miss = value; }
	}
	//闪避率
	public float m_MissRate;
	public float MissRate
	{
		get { return m_MissRate;}
		set { m_MissRate = value; }
	}
	//暴击值
	public int m_Critical;
	public int Critical
	{
		get { return m_Critical;}
		set { m_Critical = value; }
	}
	//暴击率
	public float m_CriticalRate;
	public float CriticalRate
	{
		get { return m_CriticalRate;}
		set { m_CriticalRate = value; }
	}
	//韧性值
	public int m_Tenacity;
	public int Tenacity
	{
		get { return m_Tenacity;}
		set { m_Tenacity = value; }
	}
	//韧性率
	public float m_TenacityRate;
	public float TenacityRate
	{
		get { return m_TenacityRate;}
		set { m_TenacityRate = value; }
	}
	//穿透值
	public int m_Penet;
	public int Penet
	{
		get { return m_Penet;}
		set { m_Penet = value; }
	}
	//穿透率
	public float m_PenetRate;
	public float PenetRate
	{
		get { return m_PenetRate;}
		set { m_PenetRate = value; }
	}
	//格挡值
	public int m_Dodg;
	public int Dodg
	{
		get { return m_Dodg;}
		set { m_Dodg = value; }
	}
	//格挡率
	public float m_DodgRate;
	public float DodgRate
	{
		get { return m_DodgRate;}
		set { m_DodgRate = value; }
	}
	//暴击加伤值
	public int m_CriticalAddition;
	public int CriticalAddition
	{
		get { return m_CriticalAddition;}
		set { m_CriticalAddition = value; }
	}
	//暴击加伤率
	public float m_CriticalAdditionRate;
	public float CriticalAdditionRate
	{
		get { return m_CriticalAdditionRate;}
		set { m_CriticalAdditionRate = value; }
	}
	//暴击免伤
	public int m_CriticalImmune;
	public int CriticalImmune
	{
		get { return m_CriticalImmune;}
		set { m_CriticalImmune = value; }
	}
	//暴击免伤率
	public float m_CriticalImmuneRate;
	public float CriticalImmuneRate
	{
		get { return m_CriticalImmuneRate;}
		set { m_CriticalImmuneRate = value; }
	}
	//闪避等级
	public int m_MissLevel;
	public int MissLevel
	{
		get { return m_MissLevel;}
		set { m_MissLevel = value; }
	}
	//暴击等级
	public int m_CriticalLevel;
	public int CriticalLevel
	{
		get { return m_CriticalLevel;}
		set { m_CriticalLevel = value; }
	}
	//格挡等级
	public int m_DodgLevel;
	public int DodgLevel
	{
		get { return m_DodgLevel;}
		set { m_DodgLevel = value; }
	}
	//移动速度
	public float m_MoveSpeed;
	public float MoveSpeed
	{
		get { return m_MoveSpeed;}
		set { m_MoveSpeed = value; }
	}
	//眩晕状态
	public bool m_DizzyState;
	public bool DizzyState
	{
		get { return m_DizzyState;}
		set { m_DizzyState = value; }
	}
	//霸体状态
	public bool m_GodState;
	public bool GodState
	{
		get { return m_GodState;}
		set { m_GodState = value; }
	}
	//不能移动状态
	public bool m_CantMoveState;
	public bool CantMoveState
	{
		get { return m_CantMoveState;}
		set { m_CantMoveState = value; }
	}
	//物理加伤值
	public float m_PhysicAddition;
	public float PhysicAddition
	{
		get { return m_PhysicAddition;}
		set { m_PhysicAddition = value; }
	}
	//魔法加伤值
	public float m_MagicAddition;
	public float MagicAddition
	{
		get { return m_MagicAddition;}
		set { m_MagicAddition = value; }
	}
	//物理抗性
	public float m_PhysicOppose;
	public float PhysicOppose
	{
		get { return m_PhysicOppose;}
		set { m_PhysicOppose = value; }
	}
	//魔法抗性
	public float m_MagicOppose;
	public float MagicOppose
	{
		get { return m_MagicOppose;}
		set { m_MagicOppose = value; }
	}



}
