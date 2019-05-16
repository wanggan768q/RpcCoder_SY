
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBStringNotice.cs
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


//通知通知封装类
[System.Serializable]
public class StringNoticeRpcNoticeNotifyWraper
{

	//构造函数
	public StringNoticeRpcNoticeNotifyWraper()
	{
		 m_ConfigId = -1;
		m_Param = new List<string>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfigId = -1;
		m_Param = new List<string>();

	}

 	//转化成Protobuffer类型函数
	public StringNoticeRpcNoticeNotify ToPB()
	{
		StringNoticeRpcNoticeNotify v = new StringNoticeRpcNoticeNotify();
		v.ConfigId = m_ConfigId;
		for (int i=0; i<(int)m_Param.Count; i++)
			v.Param.Add( m_Param[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(StringNoticeRpcNoticeNotify v)
	{
        if (v == null)
            return;
		m_ConfigId = v.ConfigId;
		m_Param.Clear();
		for( int i=0; i<v.Param.Count; i++)
			m_Param.Add(v.Param[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<StringNoticeRpcNoticeNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		StringNoticeRpcNoticeNotify pb = ProtoBuf.Serializer.Deserialize<StringNoticeRpcNoticeNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//文本ID
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//参数
	public List<string> m_Param;
	public int SizeParam()
	{
		return m_Param.Count;
	}
	public List<string> GetParam()
	{
		return m_Param;
	}
	public string GetParam(int Index)
	{
		if(Index<0 || Index>=(int)m_Param.Count)
			return "";
		return m_Param[Index];
	}
	public void SetParam( List<string> v )
	{
		m_Param=v;
	}
	public void SetParam( int Index, string v )
	{
		if(Index<0 || Index>=(int)m_Param.Count)
			return;
		m_Param[Index] = v;
	}
	public void AddParam( string v )
	{
		m_Param.Add(v);
	}
	public void ClearParam( )
	{
		m_Param.Clear();
	}


};
