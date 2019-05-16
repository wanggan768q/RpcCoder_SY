
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBGG.cs
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


//GGChangeScene通知封装类
[System.Serializable]
public class GGRpcGGChangeSceneNotifyWraper
{

	//构造函数
	public GGRpcGGChangeSceneNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public GGRpcGGChangeSceneNotify ToPB()
	{
		GGRpcGGChangeSceneNotify v = new GGRpcGGChangeSceneNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(GGRpcGGChangeSceneNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<GGRpcGGChangeSceneNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		GGRpcGGChangeSceneNotify pb = ProtoBuf.Serializer.Deserialize<GGRpcGGChangeSceneNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
