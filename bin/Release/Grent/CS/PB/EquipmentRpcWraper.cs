
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBEquipment.cs
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


//装备请求封装类
[System.Serializable]
public class EquipmentRpcEquipAskWraper
{

	//构造函数
	public EquipmentRpcEquipAskWraper()
	{
		 m_Pos = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Pos = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipAsk ToPB()
	{
		EquipmentRpcEquipAsk v = new EquipmentRpcEquipAsk();
		v.Pos = m_Pos;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipAsk v)
	{
        if (v == null)
            return;
		m_Pos = v.Pos;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//背包位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
//装备回应封装类
[System.Serializable]
public class EquipmentRpcEquipReplyWraper
{

	//构造函数
	public EquipmentRpcEquipReplyWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		 m_SlotType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		 m_SlotType = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipReply ToPB()
	{
		EquipmentRpcEquipReply v = new EquipmentRpcEquipReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());
		for (int i=0; i<(int)m_Suit_infos.Count; i++)
			v.Suit_infos.Add( m_Suit_infos[i].ToPB());
		v.SlotType = m_SlotType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);
		m_Suit_infos.Clear();
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos.Add( new SuitInfoWraper());
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos[i].FromPB(v.Suit_infos[i]);
		m_SlotType = v.SlotType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipReply>(protoMS);
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
	//更新背包
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}
	//Suit_infos
	public List<SuitInfoWraper> m_Suit_infos;
	public int SizeSuit_infos()
	{
		return m_Suit_infos.Count;
	}
	public List<SuitInfoWraper> GetSuit_infos()
	{
		return m_Suit_infos;
	}
	public SuitInfoWraper GetSuit_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return new SuitInfoWraper();
		return m_Suit_infos[Index];
	}
	public void SetSuit_infos( List<SuitInfoWraper> v )
	{
		m_Suit_infos=v;
	}
	public void SetSuit_infos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return;
		m_Suit_infos[Index] = v;
	}
	public void AddSuit_infos( SuitInfoWraper v )
	{
		m_Suit_infos.Add(v);
	}
	public void ClearSuit_infos( )
	{
		m_Suit_infos.Clear();
	}
	//SlotType
	public int m_SlotType;
	public int SlotType
	{
		get { return m_SlotType;}
		set { m_SlotType = value; }
	}


};
//卸载装备请求封装类
[System.Serializable]
public class EquipmentRpcUnEquipAskWraper
{

	//构造函数
	public EquipmentRpcUnEquipAskWraper()
	{
		 m_SlotType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SlotType = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcUnEquipAsk ToPB()
	{
		EquipmentRpcUnEquipAsk v = new EquipmentRpcUnEquipAsk();
		v.SlotType = m_SlotType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcUnEquipAsk v)
	{
        if (v == null)
            return;
		m_SlotType = v.SlotType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcUnEquipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcUnEquipAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcUnEquipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备槽类型
	public int m_SlotType;
	public int SlotType
	{
		get { return m_SlotType;}
		set { m_SlotType = value; }
	}


};
//卸载装备回应封装类
[System.Serializable]
public class EquipmentRpcUnEquipReplyWraper
{

	//构造函数
	public EquipmentRpcUnEquipReplyWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		 m_SlotType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		 m_SlotType = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcUnEquipReply ToPB()
	{
		EquipmentRpcUnEquipReply v = new EquipmentRpcUnEquipReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());
		for (int i=0; i<(int)m_Suit_infos.Count; i++)
			v.Suit_infos.Add( m_Suit_infos[i].ToPB());
		v.SlotType = m_SlotType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcUnEquipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);
		m_Suit_infos.Clear();
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos.Add( new SuitInfoWraper());
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos[i].FromPB(v.Suit_infos[i]);
		m_SlotType = v.SlotType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcUnEquipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcUnEquipReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcUnEquipReply>(protoMS);
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
	//更新背包s
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}
	//Suit_infos
	public List<SuitInfoWraper> m_Suit_infos;
	public int SizeSuit_infos()
	{
		return m_Suit_infos.Count;
	}
	public List<SuitInfoWraper> GetSuit_infos()
	{
		return m_Suit_infos;
	}
	public SuitInfoWraper GetSuit_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return new SuitInfoWraper();
		return m_Suit_infos[Index];
	}
	public void SetSuit_infos( List<SuitInfoWraper> v )
	{
		m_Suit_infos=v;
	}
	public void SetSuit_infos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return;
		m_Suit_infos[Index] = v;
	}
	public void AddSuit_infos( SuitInfoWraper v )
	{
		m_Suit_infos.Add(v);
	}
	public void ClearSuit_infos( )
	{
		m_Suit_infos.Clear();
	}
	//SlotType
	public int m_SlotType;
	public int SlotType
	{
		get { return m_SlotType;}
		set { m_SlotType = value; }
	}


};
//切换装备套装请求封装类
[System.Serializable]
public class EquipmentRpcSwitchEquipSetAskWraper
{

	//构造函数
	public EquipmentRpcSwitchEquipSetAskWraper()
	{
		 m_To_index = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_To_index = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcSwitchEquipSetAsk ToPB()
	{
		EquipmentRpcSwitchEquipSetAsk v = new EquipmentRpcSwitchEquipSetAsk();
		v.To_index = m_To_index;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcSwitchEquipSetAsk v)
	{
        if (v == null)
            return;
		m_To_index = v.To_index;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcSwitchEquipSetAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcSwitchEquipSetAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcSwitchEquipSetAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//切换为几号套装
	public int m_To_index;
	public int To_index
	{
		get { return m_To_index;}
		set { m_To_index = value; }
	}


};
//切换装备套装回应封装类
[System.Serializable]
public class EquipmentRpcSwitchEquipSetReplyWraper
{

	//构造函数
	public EquipmentRpcSwitchEquipSetReplyWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcSwitchEquipSetReply ToPB()
	{
		EquipmentRpcSwitchEquipSetReply v = new EquipmentRpcSwitchEquipSetReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcSwitchEquipSetReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcSwitchEquipSetReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcSwitchEquipSetReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcSwitchEquipSetReply>(protoMS);
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
	//更新背包
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}


};
//同步装备套装请求封装类
[System.Serializable]
public class EquipmentRpcSyncEquipAskWraper
{

	//构造函数
	public EquipmentRpcSyncEquipAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcSyncEquipAsk ToPB()
	{
		EquipmentRpcSyncEquipAsk v = new EquipmentRpcSyncEquipAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcSyncEquipAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcSyncEquipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcSyncEquipAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcSyncEquipAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步装备套装回应封装类
[System.Serializable]
public class EquipmentRpcSyncEquipReplyWraper
{

	//构造函数
	public EquipmentRpcSyncEquipReplyWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcSyncEquipReply ToPB()
	{
		EquipmentRpcSyncEquipReply v = new EquipmentRpcSyncEquipReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());
		for (int i=0; i<(int)m_Suit_infos.Count; i++)
			v.Suit_infos.Add( m_Suit_infos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcSyncEquipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);
		m_Suit_infos.Clear();
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos.Add( new SuitInfoWraper());
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos[i].FromPB(v.Suit_infos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcSyncEquipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcSyncEquipReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcSyncEquipReply>(protoMS);
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
	//装备信息
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}
	//Suit_infos
	public List<SuitInfoWraper> m_Suit_infos;
	public int SizeSuit_infos()
	{
		return m_Suit_infos.Count;
	}
	public List<SuitInfoWraper> GetSuit_infos()
	{
		return m_Suit_infos;
	}
	public SuitInfoWraper GetSuit_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return new SuitInfoWraper();
		return m_Suit_infos[Index];
	}
	public void SetSuit_infos( List<SuitInfoWraper> v )
	{
		m_Suit_infos=v;
	}
	public void SetSuit_infos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return;
		m_Suit_infos[Index] = v;
	}
	public void AddSuit_infos( SuitInfoWraper v )
	{
		m_Suit_infos.Add(v);
	}
	public void ClearSuit_infos( )
	{
		m_Suit_infos.Clear();
	}


};
//激活共鸣请求封装类
[System.Serializable]
public class EquipmentRpcResonanceUnlockAskWraper
{

	//构造函数
	public EquipmentRpcResonanceUnlockAskWraper()
	{
		 m_ConfId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfId = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcResonanceUnlockAsk ToPB()
	{
		EquipmentRpcResonanceUnlockAsk v = new EquipmentRpcResonanceUnlockAsk();
		v.ConfId = m_ConfId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcResonanceUnlockAsk v)
	{
        if (v == null)
            return;
		m_ConfId = v.ConfId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcResonanceUnlockAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcResonanceUnlockAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcResonanceUnlockAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//ID
	public int m_ConfId;
	public int ConfId
	{
		get { return m_ConfId;}
		set { m_ConfId = value; }
	}


};
//激活共鸣回应封装类
[System.Serializable]
public class EquipmentRpcResonanceUnlockReplyWraper
{

	//构造函数
	public EquipmentRpcResonanceUnlockReplyWraper()
	{
		 m_Result = -1;
		 m_ResonanceInfo = new EquipResonanceInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ResonanceInfo = new EquipResonanceInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcResonanceUnlockReply ToPB()
	{
		EquipmentRpcResonanceUnlockReply v = new EquipmentRpcResonanceUnlockReply();
		v.Result = m_Result;
		v.ResonanceInfo = m_ResonanceInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcResonanceUnlockReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ResonanceInfo.FromPB(v.ResonanceInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcResonanceUnlockReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcResonanceUnlockReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcResonanceUnlockReply>(protoMS);
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
	//数据
	public EquipResonanceInfoWraper m_ResonanceInfo;
	public EquipResonanceInfoWraper ResonanceInfo
	{
		get { return m_ResonanceInfo;}
		set { m_ResonanceInfo = value; }
	}


};
//共鸣洗练请求封装类
[System.Serializable]
public class EquipmentRpcEquipDoResonanceAskWraper
{

	//构造函数
	public EquipmentRpcEquipDoResonanceAskWraper()
	{
		 m_ConfId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfId = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipDoResonanceAsk ToPB()
	{
		EquipmentRpcEquipDoResonanceAsk v = new EquipmentRpcEquipDoResonanceAsk();
		v.ConfId = m_ConfId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipDoResonanceAsk v)
	{
        if (v == null)
            return;
		m_ConfId = v.ConfId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipDoResonanceAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipDoResonanceAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipDoResonanceAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Id
	public int m_ConfId;
	public int ConfId
	{
		get { return m_ConfId;}
		set { m_ConfId = value; }
	}


};
//共鸣洗练回应封装类
[System.Serializable]
public class EquipmentRpcEquipDoResonanceReplyWraper
{

	//构造函数
	public EquipmentRpcEquipDoResonanceReplyWraper()
	{
		 m_Result = -1;
		 m_AddAttr = new EquipResonanceInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_AddAttr = new EquipResonanceInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipDoResonanceReply ToPB()
	{
		EquipmentRpcEquipDoResonanceReply v = new EquipmentRpcEquipDoResonanceReply();
		v.Result = m_Result;
		v.AddAttr = m_AddAttr.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipDoResonanceReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_AddAttr.FromPB(v.AddAttr);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipDoResonanceReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipDoResonanceReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipDoResonanceReply>(protoMS);
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
	//增加的属性
	public EquipResonanceInfoWraper m_AddAttr;
	public EquipResonanceInfoWraper AddAttr
	{
		get { return m_AddAttr;}
		set { m_AddAttr = value; }
	}


};
//保存共鸣属性请求封装类
[System.Serializable]
public class EquipmentRpcEquipResonanceSaveAskWraper
{

	//构造函数
	public EquipmentRpcEquipResonanceSaveAskWraper()
	{
		 m_ConfId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ConfId = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipResonanceSaveAsk ToPB()
	{
		EquipmentRpcEquipResonanceSaveAsk v = new EquipmentRpcEquipResonanceSaveAsk();
		v.ConfId = m_ConfId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipResonanceSaveAsk v)
	{
        if (v == null)
            return;
		m_ConfId = v.ConfId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipResonanceSaveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipResonanceSaveAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipResonanceSaveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Id
	public int m_ConfId;
	public int ConfId
	{
		get { return m_ConfId;}
		set { m_ConfId = value; }
	}


};
//保存共鸣属性回应封装类
[System.Serializable]
public class EquipmentRpcEquipResonanceSaveReplyWraper
{

	//构造函数
	public EquipmentRpcEquipResonanceSaveReplyWraper()
	{
		 m_Result = -1;
		 m_ResonanceInfo = new EquipResonanceInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ResonanceInfo = new EquipResonanceInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipResonanceSaveReply ToPB()
	{
		EquipmentRpcEquipResonanceSaveReply v = new EquipmentRpcEquipResonanceSaveReply();
		v.Result = m_Result;
		v.ResonanceInfo = m_ResonanceInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipResonanceSaveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ResonanceInfo.FromPB(v.ResonanceInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipResonanceSaveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipResonanceSaveReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipResonanceSaveReply>(protoMS);
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
	//最新的数据
	public EquipResonanceInfoWraper m_ResonanceInfo;
	public EquipResonanceInfoWraper ResonanceInfo
	{
		get { return m_ResonanceInfo;}
		set { m_ResonanceInfo = value; }
	}


};
//初始化请求封装类
[System.Serializable]
public class EquipmentRpcEquipResonanceSyncAskWraper
{

	//构造函数
	public EquipmentRpcEquipResonanceSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipResonanceSyncAsk ToPB()
	{
		EquipmentRpcEquipResonanceSyncAsk v = new EquipmentRpcEquipResonanceSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipResonanceSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipResonanceSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipResonanceSyncAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipResonanceSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//初始化回应封装类
[System.Serializable]
public class EquipmentRpcEquipResonanceSyncReplyWraper
{

	//构造函数
	public EquipmentRpcEquipResonanceSyncReplyWraper()
	{
		 m_Result = -1;
		 m_ResonanceData = new EquipResonanceDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ResonanceData = new EquipResonanceDataWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipResonanceSyncReply ToPB()
	{
		EquipmentRpcEquipResonanceSyncReply v = new EquipmentRpcEquipResonanceSyncReply();
		v.Result = m_Result;
		v.ResonanceData = m_ResonanceData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipResonanceSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ResonanceData.FromPB(v.ResonanceData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipResonanceSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipResonanceSyncReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipResonanceSyncReply>(protoMS);
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
	//数据
	public EquipResonanceDataWraper m_ResonanceData;
	public EquipResonanceDataWraper ResonanceData
	{
		get { return m_ResonanceData;}
		set { m_ResonanceData = value; }
	}


};
//初始化洗练数据请求封装类
[System.Serializable]
public class EquipmentRpcEquipWashSyncAskWraper
{

	//构造函数
	public EquipmentRpcEquipWashSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashSyncAsk ToPB()
	{
		EquipmentRpcEquipWashSyncAsk v = new EquipmentRpcEquipWashSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashSyncAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//初始化洗练数据回应封装类
[System.Serializable]
public class EquipmentRpcEquipWashSyncReplyWraper
{

	//构造函数
	public EquipmentRpcEquipWashSyncReplyWraper()
	{
		 m_Result = -1;
		 m_EquipWashData = new EquipWashDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_EquipWashData = new EquipWashDataWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashSyncReply ToPB()
	{
		EquipmentRpcEquipWashSyncReply v = new EquipmentRpcEquipWashSyncReply();
		v.Result = m_Result;
		v.EquipWashData = m_EquipWashData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipWashData.FromPB(v.EquipWashData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashSyncReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashSyncReply>(protoMS);
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
	//洗练数据
	public EquipWashDataWraper m_EquipWashData;
	public EquipWashDataWraper EquipWashData
	{
		get { return m_EquipWashData;}
		set { m_EquipWashData = value; }
	}


};
//请求洗练请求封装类
[System.Serializable]
public class EquipmentRpcEquipWashAskWraper
{

	//构造函数
	public EquipmentRpcEquipWashAskWraper()
	{
		 m_Guid = 0;
		m_LockedIndex = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		m_LockedIndex = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashAsk ToPB()
	{
		EquipmentRpcEquipWashAsk v = new EquipmentRpcEquipWashAsk();
		v.Guid = m_Guid;
		for (int i=0; i<(int)m_LockedIndex.Count; i++)
			v.LockedIndex.Add( m_LockedIndex[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_LockedIndex.Clear();
		for( int i=0; i<v.LockedIndex.Count; i++)
			m_LockedIndex.Add(v.LockedIndex[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//唯一id
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//锁的条目
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


};
//请求洗练回应封装类
[System.Serializable]
public class EquipmentRpcEquipWashReplyWraper
{

	//构造函数
	public EquipmentRpcEquipWashReplyWraper()
	{
		 m_Result = -1;
		 m_EquipWashInfo = new EquipWashInfoWraper();
		 m_LeftTimes = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_EquipWashInfo = new EquipWashInfoWraper();
		 m_LeftTimes = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashReply ToPB()
	{
		EquipmentRpcEquipWashReply v = new EquipmentRpcEquipWashReply();
		v.Result = m_Result;
		v.EquipWashInfo = m_EquipWashInfo.ToPB();
		v.LeftTimes = m_LeftTimes;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipWashInfo.FromPB(v.EquipWashInfo);
		m_LeftTimes = v.LeftTimes;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashReply>(protoMS);
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
	//洗练数据
	public EquipWashInfoWraper m_EquipWashInfo;
	public EquipWashInfoWraper EquipWashInfo
	{
		get { return m_EquipWashInfo;}
		set { m_EquipWashInfo = value; }
	}
	//剩余次数
	public int m_LeftTimes;
	public int LeftTimes
	{
		get { return m_LeftTimes;}
		set { m_LeftTimes = value; }
	}


};
//保存请求封装类
[System.Serializable]
public class EquipmentRpcEquipWashSaveAskWraper
{

	//构造函数
	public EquipmentRpcEquipWashSaveAskWraper()
	{
		 m_Guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashSaveAsk ToPB()
	{
		EquipmentRpcEquipWashSaveAsk v = new EquipmentRpcEquipWashSaveAsk();
		v.Guid = m_Guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashSaveAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashSaveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashSaveAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashSaveAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备GUID
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}


};
//保存回应封装类
[System.Serializable]
public class EquipmentRpcEquipWashSaveReplyWraper
{

	//构造函数
	public EquipmentRpcEquipWashSaveReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();
		m_LockedIndex = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();
		m_LockedIndex = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipWashSaveReply ToPB()
	{
		EquipmentRpcEquipWashSaveReply v = new EquipmentRpcEquipWashSaveReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();
		for (int i=0; i<(int)m_LockedIndex.Count; i++)
			v.LockedIndex.Add( m_LockedIndex[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipWashSaveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);
		m_LockedIndex.Clear();
		for( int i=0; i<v.LockedIndex.Count; i++)
			m_LockedIndex.Add(v.LockedIndex[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipWashSaveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipWashSaveReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipWashSaveReply>(protoMS);
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
	//保存后的道具数据
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}
	//锁定索引
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


};
//装备打造请求封装类
[System.Serializable]
public class EquipmentRpcEquipBuildSyncAskWraper
{

	//构造函数
	public EquipmentRpcEquipBuildSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipBuildSyncAsk ToPB()
	{
		EquipmentRpcEquipBuildSyncAsk v = new EquipmentRpcEquipBuildSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipBuildSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipBuildSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipBuildSyncAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipBuildSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//装备打造回应封装类
[System.Serializable]
public class EquipmentRpcEquipBuildSyncReplyWraper
{

	//构造函数
	public EquipmentRpcEquipBuildSyncReplyWraper()
	{
		 m_Result = -1;
		m_Atf_list = new List<EquipBuildAtfWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Atf_list = new List<EquipBuildAtfWraper>();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipBuildSyncReply ToPB()
	{
		EquipmentRpcEquipBuildSyncReply v = new EquipmentRpcEquipBuildSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Atf_list.Count; i++)
			v.Atf_list.Add( m_Atf_list[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipBuildSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Atf_list.Clear();
		for( int i=0; i<v.Atf_list.Count; i++)
			m_Atf_list.Add( new EquipBuildAtfWraper());
		for( int i=0; i<v.Atf_list.Count; i++)
			m_Atf_list[i].FromPB(v.Atf_list[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipBuildSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipBuildSyncReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipBuildSyncReply>(protoMS);
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
	//神器值列表
	public List<EquipBuildAtfWraper> m_Atf_list;
	public int SizeAtf_list()
	{
		return m_Atf_list.Count;
	}
	public List<EquipBuildAtfWraper> GetAtf_list()
	{
		return m_Atf_list;
	}
	public EquipBuildAtfWraper GetAtf_list(int Index)
	{
		if(Index<0 || Index>=(int)m_Atf_list.Count)
			return new EquipBuildAtfWraper();
		return m_Atf_list[Index];
	}
	public void SetAtf_list( List<EquipBuildAtfWraper> v )
	{
		m_Atf_list=v;
	}
	public void SetAtf_list( int Index, EquipBuildAtfWraper v )
	{
		if(Index<0 || Index>=(int)m_Atf_list.Count)
			return;
		m_Atf_list[Index] = v;
	}
	public void AddAtf_list( EquipBuildAtfWraper v )
	{
		m_Atf_list.Add(v);
	}
	public void ClearAtf_list( )
	{
		m_Atf_list.Clear();
	}


};
//打造请求请求封装类
[System.Serializable]
public class EquipmentRpcEquipBuildAskWraper
{

	//构造函数
	public EquipmentRpcEquipBuildAskWraper()
	{
		 m_Level = -1;
		 m_Occupation = -1;
		 m_Slot_type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Level = -1;
		 m_Occupation = -1;
		 m_Slot_type = -1;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipBuildAsk ToPB()
	{
		EquipmentRpcEquipBuildAsk v = new EquipmentRpcEquipBuildAsk();
		v.Level = m_Level;
		v.Occupation = m_Occupation;
		v.Slot_type = m_Slot_type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipBuildAsk v)
	{
        if (v == null)
            return;
		m_Level = v.Level;
		m_Occupation = v.Occupation;
		m_Slot_type = v.Slot_type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipBuildAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipBuildAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipBuildAsk>(protoMS);
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
	//职业
	public int m_Occupation;
	public int Occupation
	{
		get { return m_Occupation;}
		set { m_Occupation = value; }
	}
	//整备类型
	public int m_Slot_type;
	public int Slot_type
	{
		get { return m_Slot_type;}
		set { m_Slot_type = value; }
	}


};
//打造请求回应封装类
[System.Serializable]
public class EquipmentRpcEquipBuildReplyWraper
{

	//构造函数
	public EquipmentRpcEquipBuildReplyWraper()
	{
		 m_Result = -1;
		 m_EquipBuildAtf = new EquipBuildAtfWraper();
		 m_Equip = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_EquipBuildAtf = new EquipBuildAtfWraper();
		 m_Equip = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipBuildReply ToPB()
	{
		EquipmentRpcEquipBuildReply v = new EquipmentRpcEquipBuildReply();
		v.Result = m_Result;
		v.EquipBuildAtf = m_EquipBuildAtf.ToPB();
		v.Equip = m_Equip.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipBuildReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_EquipBuildAtf.FromPB(v.EquipBuildAtf);
		m_Equip.FromPB(v.Equip);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipBuildReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipBuildReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipBuildReply>(protoMS);
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
	//打造后的神器值
	public EquipBuildAtfWraper m_EquipBuildAtf;
	public EquipBuildAtfWraper EquipBuildAtf
	{
		get { return m_EquipBuildAtf;}
		set { m_EquipBuildAtf = value; }
	}
	//打造出的装备
	public ItemObjWraper m_Equip;
	public ItemObjWraper Equip
	{
		get { return m_Equip;}
		set { m_Equip = value; }
	}


};
//获取其他玩家信息请求封装类
[System.Serializable]
public class EquipmentRpcGetPlayerInfoAskWraper
{

	//构造函数
	public EquipmentRpcGetPlayerInfoAskWraper()
	{
		 m_Player_guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Player_guid = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcGetPlayerInfoAsk ToPB()
	{
		EquipmentRpcGetPlayerInfoAsk v = new EquipmentRpcGetPlayerInfoAsk();
		v.Player_guid = m_Player_guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcGetPlayerInfoAsk v)
	{
        if (v == null)
            return;
		m_Player_guid = v.Player_guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcGetPlayerInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcGetPlayerInfoAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcGetPlayerInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//玩家guid
	public UInt64 m_Player_guid;
	public UInt64 Player_guid
	{
		get { return m_Player_guid;}
		set { m_Player_guid = value; }
	}


};
//获取其他玩家信息回应封装类
[System.Serializable]
public class EquipmentRpcGetPlayerInfoReplyWraper
{

	//构造函数
	public EquipmentRpcGetPlayerInfoReplyWraper()
	{
		 m_Result = -1;
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Guild_id = 0;
		 m_Guild_name = "";
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		m_JewelInfos = new List<JewelInfoWraper>();
		 m_BattleScore = -1;
		 m_Pet_item_data = new ItemDataWraper();
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TeamId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Player_name = "";
		 m_Player_guid = 0;
		 m_Avatar_id = -1;
		 m_Player_level = -1;
		 m_Avatar_frame_id = -1;
		 m_Config_id = -1;
		 m_Guild_id = 0;
		 m_Guild_name = "";
		m_Equip_data = new List<ItemDataWraper>();
		m_Suit_infos = new List<SuitInfoWraper>();
		m_EquipSlotData = new List<EquipSlotInfoWraper>();
		m_EquipSlotStarList = new List<EquipSlotStarInfoWraper>();
		m_JewelInfos = new List<JewelInfoWraper>();
		 m_BattleScore = -1;
		 m_Pet_item_data = new ItemDataWraper();
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_TeamId = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcGetPlayerInfoReply ToPB()
	{
		EquipmentRpcGetPlayerInfoReply v = new EquipmentRpcGetPlayerInfoReply();
		v.Result = m_Result;
		v.Player_name = m_Player_name;
		v.Player_guid = m_Player_guid;
		v.Avatar_id = m_Avatar_id;
		v.Player_level = m_Player_level;
		v.Avatar_frame_id = m_Avatar_frame_id;
		v.Config_id = m_Config_id;
		v.Guild_id = m_Guild_id;
		v.Guild_name = m_Guild_name;
		for (int i=0; i<(int)m_Equip_data.Count; i++)
			v.Equip_data.Add( m_Equip_data[i].ToPB());
		for (int i=0; i<(int)m_Suit_infos.Count; i++)
			v.Suit_infos.Add( m_Suit_infos[i].ToPB());
		for (int i=0; i<(int)m_EquipSlotData.Count; i++)
			v.EquipSlotData.Add( m_EquipSlotData[i].ToPB());
		for (int i=0; i<(int)m_EquipSlotStarList.Count; i++)
			v.EquipSlotStarList.Add( m_EquipSlotStarList[i].ToPB());
		for (int i=0; i<(int)m_JewelInfos.Count; i++)
			v.JewelInfos.Add( m_JewelInfos[i].ToPB());
		v.BattleScore = m_BattleScore;
		v.Pet_item_data = m_Pet_item_data.ToPB();
		v.TreasureHair = m_TreasureHair;
		v.TreasureHead = m_TreasureHead;
		v.TreasureBody = m_TreasureBody;
		v.TreasureWeapon = m_TreasureWeapon;
		v.TreasureWing = m_TreasureWing;
		v.TeamId = m_TeamId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcGetPlayerInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Player_name = v.Player_name;
		m_Player_guid = v.Player_guid;
		m_Avatar_id = v.Avatar_id;
		m_Player_level = v.Player_level;
		m_Avatar_frame_id = v.Avatar_frame_id;
		m_Config_id = v.Config_id;
		m_Guild_id = v.Guild_id;
		m_Guild_name = v.Guild_name;
		m_Equip_data.Clear();
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data.Add( new ItemDataWraper());
		for( int i=0; i<v.Equip_data.Count; i++)
			m_Equip_data[i].FromPB(v.Equip_data[i]);
		m_Suit_infos.Clear();
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos.Add( new SuitInfoWraper());
		for( int i=0; i<v.Suit_infos.Count; i++)
			m_Suit_infos[i].FromPB(v.Suit_infos[i]);
		m_EquipSlotData.Clear();
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData.Add( new EquipSlotInfoWraper());
		for( int i=0; i<v.EquipSlotData.Count; i++)
			m_EquipSlotData[i].FromPB(v.EquipSlotData[i]);
		m_EquipSlotStarList.Clear();
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList.Add( new EquipSlotStarInfoWraper());
		for( int i=0; i<v.EquipSlotStarList.Count; i++)
			m_EquipSlotStarList[i].FromPB(v.EquipSlotStarList[i]);
		m_JewelInfos.Clear();
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos.Add( new JewelInfoWraper());
		for( int i=0; i<v.JewelInfos.Count; i++)
			m_JewelInfos[i].FromPB(v.JewelInfos[i]);
		m_BattleScore = v.BattleScore;
		m_Pet_item_data.FromPB(v.Pet_item_data);
		m_TreasureHair = v.TreasureHair;
		m_TreasureHead = v.TreasureHead;
		m_TreasureBody = v.TreasureBody;
		m_TreasureWeapon = v.TreasureWeapon;
		m_TreasureWing = v.TreasureWing;
		m_TeamId = v.TeamId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcGetPlayerInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcGetPlayerInfoReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcGetPlayerInfoReply>(protoMS);
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
	//公会id
	public UInt64 m_Guild_id;
	public UInt64 Guild_id
	{
		get { return m_Guild_id;}
		set { m_Guild_id = value; }
	}
	//公会名字
	public string m_Guild_name;
	public string Guild_name
	{
		get { return m_Guild_name;}
		set { m_Guild_name = value; }
	}
	//装备信息
	public List<ItemDataWraper> m_Equip_data;
	public int SizeEquip_data()
	{
		return m_Equip_data.Count;
	}
	public List<ItemDataWraper> GetEquip_data()
	{
		return m_Equip_data;
	}
	public ItemDataWraper GetEquip_data(int Index)
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return new ItemDataWraper();
		return m_Equip_data[Index];
	}
	public void SetEquip_data( List<ItemDataWraper> v )
	{
		m_Equip_data=v;
	}
	public void SetEquip_data( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.Count)
			return;
		m_Equip_data[Index] = v;
	}
	public void AddEquip_data( ItemDataWraper v )
	{
		m_Equip_data.Add(v);
	}
	public void ClearEquip_data( )
	{
		m_Equip_data.Clear();
	}
	//Suit_infos
	public List<SuitInfoWraper> m_Suit_infos;
	public int SizeSuit_infos()
	{
		return m_Suit_infos.Count;
	}
	public List<SuitInfoWraper> GetSuit_infos()
	{
		return m_Suit_infos;
	}
	public SuitInfoWraper GetSuit_infos(int Index)
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return new SuitInfoWraper();
		return m_Suit_infos[Index];
	}
	public void SetSuit_infos( List<SuitInfoWraper> v )
	{
		m_Suit_infos=v;
	}
	public void SetSuit_infos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.Count)
			return;
		m_Suit_infos[Index] = v;
	}
	public void AddSuit_infos( SuitInfoWraper v )
	{
		m_Suit_infos.Add(v);
	}
	public void ClearSuit_infos( )
	{
		m_Suit_infos.Clear();
	}
	//装备槽信息
	public List<EquipSlotInfoWraper> m_EquipSlotData;
	public int SizeEquipSlotData()
	{
		return m_EquipSlotData.Count;
	}
	public List<EquipSlotInfoWraper> GetEquipSlotData()
	{
		return m_EquipSlotData;
	}
	public EquipSlotInfoWraper GetEquipSlotData(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return new EquipSlotInfoWraper();
		return m_EquipSlotData[Index];
	}
	public void SetEquipSlotData( List<EquipSlotInfoWraper> v )
	{
		m_EquipSlotData=v;
	}
	public void SetEquipSlotData( int Index, EquipSlotInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.Count)
			return;
		m_EquipSlotData[Index] = v;
	}
	public void AddEquipSlotData( EquipSlotInfoWraper v )
	{
		m_EquipSlotData.Add(v);
	}
	public void ClearEquipSlotData( )
	{
		m_EquipSlotData.Clear();
	}
	//装备槽星级列表
	public List<EquipSlotStarInfoWraper> m_EquipSlotStarList;
	public int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.Count;
	}
	public List<EquipSlotStarInfoWraper> GetEquipSlotStarList()
	{
		return m_EquipSlotStarList;
	}
	public EquipSlotStarInfoWraper GetEquipSlotStarList(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return new EquipSlotStarInfoWraper();
		return m_EquipSlotStarList[Index];
	}
	public void SetEquipSlotStarList( List<EquipSlotStarInfoWraper> v )
	{
		m_EquipSlotStarList=v;
	}
	public void SetEquipSlotStarList( int Index, EquipSlotStarInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.Count)
			return;
		m_EquipSlotStarList[Index] = v;
	}
	public void AddEquipSlotStarList( EquipSlotStarInfoWraper v )
	{
		m_EquipSlotStarList.Add(v);
	}
	public void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.Clear();
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
	//战斗力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//宠物数据
	public ItemDataWraper m_Pet_item_data;
	public ItemDataWraper Pet_item_data
	{
		get { return m_Pet_item_data;}
		set { m_Pet_item_data = value; }
	}
	//头发时装ID
	public int m_TreasureHair;
	public int TreasureHair
	{
		get { return m_TreasureHair;}
		set { m_TreasureHair = value; }
	}
	//头部时装ID
	public int m_TreasureHead;
	public int TreasureHead
	{
		get { return m_TreasureHead;}
		set { m_TreasureHead = value; }
	}
	//身体时装
	public int m_TreasureBody;
	public int TreasureBody
	{
		get { return m_TreasureBody;}
		set { m_TreasureBody = value; }
	}
	//武器时装
	public int m_TreasureWeapon;
	public int TreasureWeapon
	{
		get { return m_TreasureWeapon;}
		set { m_TreasureWeapon = value; }
	}
	//翅膀时装
	public int m_TreasureWing;
	public int TreasureWing
	{
		get { return m_TreasureWing;}
		set { m_TreasureWing = value; }
	}
	//队伍id
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}


};
//装备继承请求封装类
[System.Serializable]
public class EquipmentRpcEquipInheritAskWraper
{

	//构造函数
	public EquipmentRpcEquipInheritAskWraper()
	{
		 m_ToGuid = 0;
		 m_FromGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ToGuid = 0;
		 m_FromGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipInheritAsk ToPB()
	{
		EquipmentRpcEquipInheritAsk v = new EquipmentRpcEquipInheritAsk();
		v.ToGuid = m_ToGuid;
		v.FromGuid = m_FromGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipInheritAsk v)
	{
        if (v == null)
            return;
		m_ToGuid = v.ToGuid;
		m_FromGuid = v.FromGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipInheritAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipInheritAsk pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipInheritAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//被继承的装备GUID
	public UInt64 m_ToGuid;
	public UInt64 ToGuid
	{
		get { return m_ToGuid;}
		set { m_ToGuid = value; }
	}
	//从哪个装备继承
	public UInt64 m_FromGuid;
	public UInt64 FromGuid
	{
		get { return m_FromGuid;}
		set { m_FromGuid = value; }
	}


};
//装备继承回应封装类
[System.Serializable]
public class EquipmentRpcEquipInheritReplyWraper
{

	//构造函数
	public EquipmentRpcEquipInheritReplyWraper()
	{
		 m_Result = -1;
		 m_NewEquip = new ItemDataWraper();
		m_EquipData = new List<ItemDataWraper>();
		m_SuitInfos = new List<SuitInfoWraper>();
		 m_FromGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_NewEquip = new ItemDataWraper();
		m_EquipData = new List<ItemDataWraper>();
		m_SuitInfos = new List<SuitInfoWraper>();
		 m_FromGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentRpcEquipInheritReply ToPB()
	{
		EquipmentRpcEquipInheritReply v = new EquipmentRpcEquipInheritReply();
		v.Result = m_Result;
		v.NewEquip = m_NewEquip.ToPB();
		for (int i=0; i<(int)m_EquipData.Count; i++)
			v.EquipData.Add( m_EquipData[i].ToPB());
		for (int i=0; i<(int)m_SuitInfos.Count; i++)
			v.SuitInfos.Add( m_SuitInfos[i].ToPB());
		v.FromGuid = m_FromGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentRpcEquipInheritReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_NewEquip.FromPB(v.NewEquip);
		m_EquipData.Clear();
		for( int i=0; i<v.EquipData.Count; i++)
			m_EquipData.Add( new ItemDataWraper());
		for( int i=0; i<v.EquipData.Count; i++)
			m_EquipData[i].FromPB(v.EquipData[i]);
		m_SuitInfos.Clear();
		for( int i=0; i<v.SuitInfos.Count; i++)
			m_SuitInfos.Add( new SuitInfoWraper());
		for( int i=0; i<v.SuitInfos.Count; i++)
			m_SuitInfos[i].FromPB(v.SuitInfos[i]);
		m_FromGuid = v.FromGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentRpcEquipInheritReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentRpcEquipInheritReply pb = ProtoBuf.Serializer.Deserialize<EquipmentRpcEquipInheritReply>(protoMS);
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
	//新装备
	public ItemDataWraper m_NewEquip;
	public ItemDataWraper NewEquip
	{
		get { return m_NewEquip;}
		set { m_NewEquip = value; }
	}
	//装备信息
	public List<ItemDataWraper> m_EquipData;
	public int SizeEquipData()
	{
		return m_EquipData.Count;
	}
	public List<ItemDataWraper> GetEquipData()
	{
		return m_EquipData;
	}
	public ItemDataWraper GetEquipData(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipData.Count)
			return new ItemDataWraper();
		return m_EquipData[Index];
	}
	public void SetEquipData( List<ItemDataWraper> v )
	{
		m_EquipData=v;
	}
	public void SetEquipData( int Index, ItemDataWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipData.Count)
			return;
		m_EquipData[Index] = v;
	}
	public void AddEquipData( ItemDataWraper v )
	{
		m_EquipData.Add(v);
	}
	public void ClearEquipData( )
	{
		m_EquipData.Clear();
	}
	//套装信息
	public List<SuitInfoWraper> m_SuitInfos;
	public int SizeSuitInfos()
	{
		return m_SuitInfos.Count;
	}
	public List<SuitInfoWraper> GetSuitInfos()
	{
		return m_SuitInfos;
	}
	public SuitInfoWraper GetSuitInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_SuitInfos.Count)
			return new SuitInfoWraper();
		return m_SuitInfos[Index];
	}
	public void SetSuitInfos( List<SuitInfoWraper> v )
	{
		m_SuitInfos=v;
	}
	public void SetSuitInfos( int Index, SuitInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_SuitInfos.Count)
			return;
		m_SuitInfos[Index] = v;
	}
	public void AddSuitInfos( SuitInfoWraper v )
	{
		m_SuitInfos.Add(v);
	}
	public void ClearSuitInfos( )
	{
		m_SuitInfos.Clear();
	}
	//FromGuid
	public UInt64 m_FromGuid;
	public UInt64 FromGuid
	{
		get { return m_FromGuid;}
		set { m_FromGuid = value; }
	}


};
