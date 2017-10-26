/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 Moduleaaaa.cs
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


public class aaaaRPC
{
	public const int ModuleId = 1;
	

	
	private static aaaaRPC m_Instance = null;
	public static aaaaRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new aaaaRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, aaaaData.Instance.UpdateField );
		


		return true;
	}






}

public class aaaaData
{
	public enum SyncIdE
	{

	}
	
	private static aaaaData m_Instance = null;
	public static aaaaData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new aaaaData();
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
			Ex.Logger.Log("aaaaData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public aaaaData()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public aaaassssssV1 ToPB()
	{
		aaaassssssV1 v = new aaaassssssV1();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(aaaassssssV1 v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<aaaassssssV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		aaaassssssV1 pb = ProtoBuf.Serializer.Deserialize<aaaassssssV1>(protoMS);
		FromPB(pb);
		return true;
	}




}
