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





}

public class BaseAttrData
{
	public enum SyncIdE
	{
 		EXP                                        = 701,  //经验
 		LEVEL                                      = 703,  //玩家等级
 		SERVERTIME                                 = 704,  //服务器时间
 		ROLEID                                     = 705,  //人物唯一ID

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
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.ServerTime = iValue;
				break;
			case SyncIdE.ROLEID:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.RoleId = iValue;
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
		 m_Exp = -1;
		 m_Level = -1;
		 m_ServerTime = -1;
		 m_RoleId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Exp = -1;
		 m_Level = -1;
		 m_ServerTime = -1;
		 m_RoleId = -1;

	}

 	//转化成Protobuffer类型函数
	public BaseAttrUserDataV1 ToPB()
	{
		BaseAttrUserDataV1 v = new BaseAttrUserDataV1();
		v.Exp = m_Exp;
		v.Level = m_Level;
		v.ServerTime = m_ServerTime;
		v.RoleId = m_RoleId;

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
	public int m_ServerTime;
	public int ServerTime
	{
		get { return m_ServerTime;}
		set { m_ServerTime = value; }
	}
	//人物唯一ID
	public int m_RoleId;
	public int RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}



}
