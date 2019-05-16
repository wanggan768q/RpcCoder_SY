
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBJewel.cs
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


//同步请求封装类
[System.Serializable]
public class JewelRpcJewelSyncAskWraper
{

	//构造函数
	public JewelRpcJewelSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public JewelRpcJewelSyncAsk ToPB()
	{
		JewelRpcJewelSyncAsk v = new JewelRpcJewelSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcJewelSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcJewelSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcJewelSyncAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcJewelSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class JewelRpcJewelSyncReplyWraper
{

	//构造函数
	public JewelRpcJewelSyncReplyWraper()
	{
		 m_Result = -1;
		m_JewelInfos = new List<JewelInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_JewelInfos = new List<JewelInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public JewelRpcJewelSyncReply ToPB()
	{
		JewelRpcJewelSyncReply v = new JewelRpcJewelSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_JewelInfos.Count; i++)
			v.JewelInfos.Add( m_JewelInfos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcJewelSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelInfos.Clear();
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos.Add( new JewelInfoWraper());
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos[i].FromPB(v.JewelInfos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcJewelSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcJewelSyncReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcJewelSyncReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石信息
	public List<JewelInfoWraper> m_JewelInfos;
	public int SizeJewelInfos()
	{
		return m_JewelInfos.Count;
	}
	public List<JewelInfoWraper> GetJewelInfos()
	{
		return m_JewelInfos;
	}
	public JewelInfoWraper GetJewelInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_JewelInfos.Count)
			return new JewelInfoWraper();
		return m_JewelInfos[Index];
	}
	public void SetJewelInfos( List<JewelInfoWraper> v )
	{
		m_JewelInfos=v;
	}
	public void SetJewelInfos( int Index, JewelInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_JewelInfos.Count)
			return;
		m_JewelInfos[Index] = v;
	}
	public void AddJewelInfos( JewelInfoWraper v )
	{
		m_JewelInfos.Add(v);
	}
	public void ClearJewelInfos( )
	{
		m_JewelInfos.Clear();
	}


};
//镶嵌请求封装类
[System.Serializable]
public class JewelRpcInsetJewelAskWraper
{

	//构造函数
	public JewelRpcInsetJewelAskWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelId = -1;
		 m_JewelSlot = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelId = -1;
		 m_JewelSlot = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcInsetJewelAsk ToPB()
	{
		JewelRpcInsetJewelAsk v = new JewelRpcInsetJewelAsk();
		v.EquipSlot = m_EquipSlot;
		v.JewelId = m_JewelId;
		v.JewelSlot = m_JewelSlot;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcInsetJewelAsk v)
	{
        if (v == null)
            return;
		m_EquipSlot = v.EquipSlot;
		m_JewelId = v.JewelId;
		m_JewelSlot = v.JewelSlot;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcInsetJewelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcInsetJewelAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcInsetJewelAsk>(protoMS);
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
	//宝石ID
	public int m_JewelId;
	public int JewelId
	{
		get { return m_JewelId;}
		set { m_JewelId = value; }
	}
	//宝石位
	public int m_JewelSlot;
	public int JewelSlot
	{
		get { return m_JewelSlot;}
		set { m_JewelSlot = value; }
	}


};
//镶嵌回应封装类
[System.Serializable]
public class JewelRpcInsetJewelReplyWraper
{

	//构造函数
	public JewelRpcInsetJewelReplyWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public JewelRpcInsetJewelReply ToPB()
	{
		JewelRpcInsetJewelReply v = new JewelRpcInsetJewelReply();
		v.Result = m_Result;
		v.JewelInfo = m_JewelInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcInsetJewelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelInfo.FromPB(v.JewelInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcInsetJewelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcInsetJewelReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcInsetJewelReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石信息
	public JewelInfoWraper m_JewelInfo;
	public JewelInfoWraper JewelInfo
	{
		get { return m_JewelInfo;}
		set { m_JewelInfo = value; }
	}


};
//摘除宝石请求封装类
[System.Serializable]
public class JewelRpcRemoveJewelAskWraper
{

	//构造函数
	public JewelRpcRemoveJewelAskWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelSlot = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelSlot = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcRemoveJewelAsk ToPB()
	{
		JewelRpcRemoveJewelAsk v = new JewelRpcRemoveJewelAsk();
		v.EquipSlot = m_EquipSlot;
		v.JewelSlot = m_JewelSlot;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcRemoveJewelAsk v)
	{
        if (v == null)
            return;
		m_EquipSlot = v.EquipSlot;
		m_JewelSlot = v.JewelSlot;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcRemoveJewelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcRemoveJewelAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcRemoveJewelAsk>(protoMS);
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
	//宝石位置
	public int m_JewelSlot;
	public int JewelSlot
	{
		get { return m_JewelSlot;}
		set { m_JewelSlot = value; }
	}


};
//摘除宝石回应封装类
[System.Serializable]
public class JewelRpcRemoveJewelReplyWraper
{

	//构造函数
	public JewelRpcRemoveJewelReplyWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public JewelRpcRemoveJewelReply ToPB()
	{
		JewelRpcRemoveJewelReply v = new JewelRpcRemoveJewelReply();
		v.Result = m_Result;
		v.JewelInfo = m_JewelInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcRemoveJewelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelInfo.FromPB(v.JewelInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcRemoveJewelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcRemoveJewelReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcRemoveJewelReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石信息
	public JewelInfoWraper m_JewelInfo;
	public JewelInfoWraper JewelInfo
	{
		get { return m_JewelInfo;}
		set { m_JewelInfo = value; }
	}


};
//合成宝石请求封装类
[System.Serializable]
public class JewelRpcCompoundJewelAskWraper
{

	//构造函数
	public JewelRpcCompoundJewelAskWraper()
	{
		 m_JewelId = -1;
		 m_UseSafeItem = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_JewelId = -1;
		 m_UseSafeItem = false;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcCompoundJewelAsk ToPB()
	{
		JewelRpcCompoundJewelAsk v = new JewelRpcCompoundJewelAsk();
		v.JewelId = m_JewelId;
		v.UseSafeItem = m_UseSafeItem;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcCompoundJewelAsk v)
	{
        if (v == null)
            return;
		m_JewelId = v.JewelId;
		m_UseSafeItem = v.UseSafeItem;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcCompoundJewelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcCompoundJewelAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcCompoundJewelAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//使用的宝石ID
	public int m_JewelId;
	public int JewelId
	{
		get { return m_JewelId;}
		set { m_JewelId = value; }
	}
	//是否使用保底道具
	public bool m_UseSafeItem;
	public bool UseSafeItem
	{
		get { return m_UseSafeItem;}
		set { m_UseSafeItem = value; }
	}


};
//合成宝石回应封装类
[System.Serializable]
public class JewelRpcCompoundJewelReplyWraper
{

	//构造函数
	public JewelRpcCompoundJewelReplyWraper()
	{
		 m_Result = -1;
		 m_JewelId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_JewelId = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcCompoundJewelReply ToPB()
	{
		JewelRpcCompoundJewelReply v = new JewelRpcCompoundJewelReply();
		v.Result = m_Result;
		v.JewelId = m_JewelId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcCompoundJewelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelId = v.JewelId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcCompoundJewelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcCompoundJewelReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcCompoundJewelReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石ID
	public int m_JewelId;
	public int JewelId
	{
		get { return m_JewelId;}
		set { m_JewelId = value; }
	}


};
//对已镶嵌的宝石合成请求封装类
[System.Serializable]
public class JewelRpcCompoundSetJewelAskWraper
{

	//构造函数
	public JewelRpcCompoundSetJewelAskWraper()
	{
		 m_EquipType = -1;
		 m_JewelSlot = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipType = -1;
		 m_JewelSlot = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcCompoundSetJewelAsk ToPB()
	{
		JewelRpcCompoundSetJewelAsk v = new JewelRpcCompoundSetJewelAsk();
		v.EquipType = m_EquipType;
		v.JewelSlot = m_JewelSlot;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcCompoundSetJewelAsk v)
	{
        if (v == null)
            return;
		m_EquipType = v.EquipType;
		m_JewelSlot = v.JewelSlot;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcCompoundSetJewelAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcCompoundSetJewelAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcCompoundSetJewelAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备位
	public int m_EquipType;
	public int EquipType
	{
		get { return m_EquipType;}
		set { m_EquipType = value; }
	}
	//宝石位
	public int m_JewelSlot;
	public int JewelSlot
	{
		get { return m_JewelSlot;}
		set { m_JewelSlot = value; }
	}


};
//对已镶嵌的宝石合成回应封装类
[System.Serializable]
public class JewelRpcCompoundSetJewelReplyWraper
{

	//构造函数
	public JewelRpcCompoundSetJewelReplyWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public JewelRpcCompoundSetJewelReply ToPB()
	{
		JewelRpcCompoundSetJewelReply v = new JewelRpcCompoundSetJewelReply();
		v.Result = m_Result;
		v.JewelInfo = m_JewelInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcCompoundSetJewelReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelInfo.FromPB(v.JewelInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcCompoundSetJewelReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcCompoundSetJewelReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcCompoundSetJewelReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石信息
	public JewelInfoWraper m_JewelInfo;
	public JewelInfoWraper JewelInfo
	{
		get { return m_JewelInfo;}
		set { m_JewelInfo = value; }
	}


};
//解锁请求封装类
[System.Serializable]
public class JewelRpcUnlockJewelSlotAskWraper
{

	//构造函数
	public JewelRpcUnlockJewelSlotAskWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelSlot = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_EquipSlot = -1;
		 m_JewelSlot = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcUnlockJewelSlotAsk ToPB()
	{
		JewelRpcUnlockJewelSlotAsk v = new JewelRpcUnlockJewelSlotAsk();
		v.EquipSlot = m_EquipSlot;
		v.JewelSlot = m_JewelSlot;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcUnlockJewelSlotAsk v)
	{
        if (v == null)
            return;
		m_EquipSlot = v.EquipSlot;
		m_JewelSlot = v.JewelSlot;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcUnlockJewelSlotAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcUnlockJewelSlotAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcUnlockJewelSlotAsk>(protoMS);
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
	//槽位
	public int m_JewelSlot;
	public int JewelSlot
	{
		get { return m_JewelSlot;}
		set { m_JewelSlot = value; }
	}


};
//解锁回应封装类
[System.Serializable]
public class JewelRpcUnlockJewelSlotReplyWraper
{

	//构造函数
	public JewelRpcUnlockJewelSlotReplyWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_JewelInfo = new JewelInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public JewelRpcUnlockJewelSlotReply ToPB()
	{
		JewelRpcUnlockJewelSlotReply v = new JewelRpcUnlockJewelSlotReply();
		v.Result = m_Result;
		v.JewelInfo = m_JewelInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcUnlockJewelSlotReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_JewelInfo.FromPB(v.JewelInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcUnlockJewelSlotReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcUnlockJewelSlotReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcUnlockJewelSlotReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}
	//宝石信息
	public JewelInfoWraper m_JewelInfo;
	public JewelInfoWraper JewelInfo
	{
		get { return m_JewelInfo;}
		set { m_JewelInfo = value; }
	}


};
//快速合成请求封装类
[System.Serializable]
public class JewelRpcQuickCompoundAskWraper
{

	//构造函数
	public JewelRpcQuickCompoundAskWraper()
	{
		 m_JewelId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_JewelId = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcQuickCompoundAsk ToPB()
	{
		JewelRpcQuickCompoundAsk v = new JewelRpcQuickCompoundAsk();
		v.JewelId = m_JewelId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcQuickCompoundAsk v)
	{
        if (v == null)
            return;
		m_JewelId = v.JewelId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcQuickCompoundAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcQuickCompoundAsk pb = ProtoBuf.Serializer.Deserialize<JewelRpcQuickCompoundAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要合成谁
	public int m_JewelId;
	public int JewelId
	{
		get { return m_JewelId;}
		set { m_JewelId = value; }
	}


};
//快速合成回应封装类
[System.Serializable]
public class JewelRpcQuickCompoundReplyWraper
{

	//构造函数
	public JewelRpcQuickCompoundReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public JewelRpcQuickCompoundReply ToPB()
	{
		JewelRpcQuickCompoundReply v = new JewelRpcQuickCompoundReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(JewelRpcQuickCompoundReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<JewelRpcQuickCompoundReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		JewelRpcQuickCompoundReply pb = ProtoBuf.Serializer.Deserialize<JewelRpcQuickCompoundReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
