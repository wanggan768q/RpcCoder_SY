
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBTreasure.cs
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


//珍宝阁数据请求封装类
[System.Serializable]
public class TreasureRpcTreasureDepotInfoAskWraper
{

	//构造函数
	public TreasureRpcTreasureDepotInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDepotInfoAsk ToPB()
	{
		TreasureRpcTreasureDepotInfoAsk v = new TreasureRpcTreasureDepotInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDepotInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDepotInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDepotInfoAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDepotInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//珍宝阁数据回应封装类
[System.Serializable]
public class TreasureRpcTreasureDepotInfoReplyWraper
{

	//构造函数
	public TreasureRpcTreasureDepotInfoReplyWraper()
	{
		 m_Result = -1;
		 m_Level = 1;
		 m_Point = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Level = 1;
		 m_Point = 0;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDepotInfoReply ToPB()
	{
		TreasureRpcTreasureDepotInfoReply v = new TreasureRpcTreasureDepotInfoReply();
		v.Result = m_Result;
		v.Level = m_Level;
		v.Point = m_Point;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDepotInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Level = v.Level;
		m_Point = v.Point;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDepotInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDepotInfoReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDepotInfoReply>(protoMS);
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
	//珍宝阁等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//珍宝阁点数
	public int m_Point;
	public int Point
	{
		get { return m_Point;}
		set { m_Point = value; }
	}


};
//珍宝数据请求封装类
[System.Serializable]
public class TreasureRpcTreasureInfoAskWraper
{

	//构造函数
	public TreasureRpcTreasureInfoAskWraper()
	{
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureInfoAsk ToPB()
	{
		TreasureRpcTreasureInfoAsk v = new TreasureRpcTreasureInfoAsk();
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureInfoAsk v)
	{
        if (v == null)
            return;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureInfoAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//珍宝数据回应封装类
[System.Serializable]
public class TreasureRpcTreasureInfoReplyWraper
{

	//构造函数
	public TreasureRpcTreasureInfoReplyWraper()
	{
		 m_Result = -1;
		m_Treasure_Info = new List<TreasureDataWraper>();
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Treasure_Info = new List<TreasureDataWraper>();
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureInfoReply ToPB()
	{
		TreasureRpcTreasureInfoReply v = new TreasureRpcTreasureInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Treasure_Info.Count; i++)
			v.Treasure_Info.Add( m_Treasure_Info[i].ToPB());
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Treasure_Info.Clear();
		for( int i=0; i<v.Treasure_Info.Count; i++)
			m_Treasure_Info.Add( new TreasureDataWraper());
		for( int i=0; i<v.Treasure_Info.Count; i++)
			m_Treasure_Info[i].FromPB(v.Treasure_Info[i]);
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureInfoReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureInfoReply>(protoMS);
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
	//珍宝数据
	public List<TreasureDataWraper> m_Treasure_Info;
	public int SizeTreasure_Info()
	{
		return m_Treasure_Info.Count;
	}
	public List<TreasureDataWraper> GetTreasure_Info()
	{
		return m_Treasure_Info;
	}
	public TreasureDataWraper GetTreasure_Info(int Index)
	{
		if(Index<0 || Index>=(int)m_Treasure_Info.Count)
			return new TreasureDataWraper();
		return m_Treasure_Info[Index];
	}
	public void SetTreasure_Info( List<TreasureDataWraper> v )
	{
		m_Treasure_Info=v;
	}
	public void SetTreasure_Info( int Index, TreasureDataWraper v )
	{
		if(Index<0 || Index>=(int)m_Treasure_Info.Count)
			return;
		m_Treasure_Info[Index] = v;
	}
	public void AddTreasure_Info( TreasureDataWraper v )
	{
		m_Treasure_Info.Add(v);
	}
	public void ClearTreasure_Info( )
	{
		m_Treasure_Info.Clear();
	}
	//珍宝类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//珍宝解锁请求封装类
[System.Serializable]
public class TreasureRpcTreasureUnlockAskWraper
{

	//构造函数
	public TreasureRpcTreasureUnlockAskWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureUnlockAsk ToPB()
	{
		TreasureRpcTreasureUnlockAsk v = new TreasureRpcTreasureUnlockAsk();
		v.Id = m_Id;
		v.Color_Type = m_Color_Type;
		v.Time_Type = m_Time_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureUnlockAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Color_Type = v.Color_Type;
		m_Time_Type = v.Time_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureUnlockAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureUnlockAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureUnlockAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//附加颜色类型
	public int m_Color_Type;
	public int Color_Type
	{
		get { return m_Color_Type;}
		set { m_Color_Type = value; }
	}
	//时限类型
	public int m_Time_Type;
	public int Time_Type
	{
		get { return m_Time_Type;}
		set { m_Time_Type = value; }
	}


};
//珍宝解锁回应封装类
[System.Serializable]
public class TreasureRpcTreasureUnlockReplyWraper
{

	//构造函数
	public TreasureRpcTreasureUnlockReplyWraper()
	{
		 m_Result = -1;
		 m_TreasureUnLocked = new TreasureDataWraper();
		 m_Points = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureUnLocked = new TreasureDataWraper();
		 m_Points = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureUnlockReply ToPB()
	{
		TreasureRpcTreasureUnlockReply v = new TreasureRpcTreasureUnlockReply();
		v.Result = m_Result;
		v.TreasureUnLocked = m_TreasureUnLocked.ToPB();
		v.Points = m_Points;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureUnlockReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureUnLocked.FromPB(v.TreasureUnLocked);
		m_Points = v.Points;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureUnlockReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureUnlockReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureUnlockReply>(protoMS);
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
	//已解锁的珍宝
	public TreasureDataWraper m_TreasureUnLocked;
	public TreasureDataWraper TreasureUnLocked
	{
		get { return m_TreasureUnLocked;}
		set { m_TreasureUnLocked = value; }
	}
	//珍宝阁点数
	public int m_Points;
	public int Points
	{
		get { return m_Points;}
		set { m_Points = value; }
	}


};
//珍宝穿戴请求封装类
[System.Serializable]
public class TreasureRpcTreasureEquipAskWraper
{

	//构造函数
	public TreasureRpcTreasureEquipAskWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureEquipAsk ToPB()
	{
		TreasureRpcTreasureEquipAsk v = new TreasureRpcTreasureEquipAsk();
		v.Id = m_Id;
		v.Color_Type = m_Color_Type;
		v.Time_Type = m_Time_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureEquipAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Color_Type = v.Color_Type;
		m_Time_Type = v.Time_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureEquipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureEquipAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureEquipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//珍宝颜色类型
	public int m_Color_Type;
	public int Color_Type
	{
		get { return m_Color_Type;}
		set { m_Color_Type = value; }
	}
	//时限类型
	public int m_Time_Type;
	public int Time_Type
	{
		get { return m_Time_Type;}
		set { m_Time_Type = value; }
	}


};
//珍宝穿戴回应封装类
[System.Serializable]
public class TreasureRpcTreasureEquipReplyWraper
{

	//构造函数
	public TreasureRpcTreasureEquipReplyWraper()
	{
		 m_Result = -1;
		 m_TreasureEquiped = new TreasureDataWraper();
		 m_TreasureUnequiped = new TreasureDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureEquiped = new TreasureDataWraper();
		 m_TreasureUnequiped = new TreasureDataWraper();

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureEquipReply ToPB()
	{
		TreasureRpcTreasureEquipReply v = new TreasureRpcTreasureEquipReply();
		v.Result = m_Result;
		v.TreasureEquiped = m_TreasureEquiped.ToPB();
		v.TreasureUnequiped = m_TreasureUnequiped.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureEquipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureEquiped.FromPB(v.TreasureEquiped);
		m_TreasureUnequiped.FromPB(v.TreasureUnequiped);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureEquipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureEquipReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureEquipReply>(protoMS);
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
	//穿戴的珍宝
	public TreasureDataWraper m_TreasureEquiped;
	public TreasureDataWraper TreasureEquiped
	{
		get { return m_TreasureEquiped;}
		set { m_TreasureEquiped = value; }
	}
	//脱掉的珍宝
	public TreasureDataWraper m_TreasureUnequiped;
	public TreasureDataWraper TreasureUnequiped
	{
		get { return m_TreasureUnequiped;}
		set { m_TreasureUnequiped = value; }
	}


};
//穿戴的珍宝请求封装类
[System.Serializable]
public class TreasureRpcTreasureEquipSycAskWraper
{

	//构造函数
	public TreasureRpcTreasureEquipSycAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureEquipSycAsk ToPB()
	{
		TreasureRpcTreasureEquipSycAsk v = new TreasureRpcTreasureEquipSycAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureEquipSycAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureEquipSycAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureEquipSycAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureEquipSycAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//穿戴的珍宝回应封装类
[System.Serializable]
public class TreasureRpcTreasureEquipSycReplyWraper
{

	//构造函数
	public TreasureRpcTreasureEquipSycReplyWraper()
	{
		 m_Result = -1;
		m_TreasueEquiped = new List<TreasureDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_TreasueEquiped = new List<TreasureDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureEquipSycReply ToPB()
	{
		TreasureRpcTreasureEquipSycReply v = new TreasureRpcTreasureEquipSycReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_TreasueEquiped.Count; i++)
			v.TreasueEquiped.Add( m_TreasueEquiped[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureEquipSycReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasueEquiped.Clear();
		for( int i=0; i<v.TreasueEquiped.Count; i++)
			m_TreasueEquiped.Add( new TreasureDataWraper());
		for( int i=0; i<v.TreasueEquiped.Count; i++)
			m_TreasueEquiped[i].FromPB(v.TreasueEquiped[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureEquipSycReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureEquipSycReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureEquipSycReply>(protoMS);
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
	//穿戴的珍宝信息
	public List<TreasureDataWraper> m_TreasueEquiped;
	public int SizeTreasueEquiped()
	{
		return m_TreasueEquiped.Count;
	}
	public List<TreasureDataWraper> GetTreasueEquiped()
	{
		return m_TreasueEquiped;
	}
	public TreasureDataWraper GetTreasueEquiped(int Index)
	{
		if(Index<0 || Index>=(int)m_TreasueEquiped.Count)
			return new TreasureDataWraper();
		return m_TreasueEquiped[Index];
	}
	public void SetTreasueEquiped( List<TreasureDataWraper> v )
	{
		m_TreasueEquiped=v;
	}
	public void SetTreasueEquiped( int Index, TreasureDataWraper v )
	{
		if(Index<0 || Index>=(int)m_TreasueEquiped.Count)
			return;
		m_TreasueEquiped[Index] = v;
	}
	public void AddTreasueEquiped( TreasureDataWraper v )
	{
		m_TreasueEquiped.Add(v);
	}
	public void ClearTreasueEquiped( )
	{
		m_TreasueEquiped.Clear();
	}


};
//珍宝阁升级请求封装类
[System.Serializable]
public class TreasureRpcTreasureDepotLvUpAskWraper
{

	//构造函数
	public TreasureRpcTreasureDepotLvUpAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDepotLvUpAsk ToPB()
	{
		TreasureRpcTreasureDepotLvUpAsk v = new TreasureRpcTreasureDepotLvUpAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDepotLvUpAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDepotLvUpAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDepotLvUpAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDepotLvUpAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//珍宝阁升级回应封装类
[System.Serializable]
public class TreasureRpcTreasureDepotLvUpReplyWraper
{

	//构造函数
	public TreasureRpcTreasureDepotLvUpReplyWraper()
	{
		 m_Result = -1;
		 m_Level = -1;
		 m_Point = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Level = -1;
		 m_Point = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDepotLvUpReply ToPB()
	{
		TreasureRpcTreasureDepotLvUpReply v = new TreasureRpcTreasureDepotLvUpReply();
		v.Result = m_Result;
		v.Level = m_Level;
		v.Point = m_Point;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDepotLvUpReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Level = v.Level;
		m_Point = v.Point;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDepotLvUpReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDepotLvUpReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDepotLvUpReply>(protoMS);
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
	//珍宝阁等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//珍宝阁点数
	public int m_Point;
	public int Point
	{
		get { return m_Point;}
		set { m_Point = value; }
	}


};
//卸下珍宝请求封装类
[System.Serializable]
public class TreasureRpcTreasureUnEquipAskWraper
{

	//构造函数
	public TreasureRpcTreasureUnEquipAskWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureUnEquipAsk ToPB()
	{
		TreasureRpcTreasureUnEquipAsk v = new TreasureRpcTreasureUnEquipAsk();
		v.Id = m_Id;
		v.Color_Type = m_Color_Type;
		v.Time_Type = m_Time_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureUnEquipAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Color_Type = v.Color_Type;
		m_Time_Type = v.Time_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureUnEquipAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureUnEquipAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureUnEquipAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//颜色类型
	public int m_Color_Type;
	public int Color_Type
	{
		get { return m_Color_Type;}
		set { m_Color_Type = value; }
	}
	//时限类型
	public int m_Time_Type;
	public int Time_Type
	{
		get { return m_Time_Type;}
		set { m_Time_Type = value; }
	}


};
//卸下珍宝回应封装类
[System.Serializable]
public class TreasureRpcTreasureUnEquipReplyWraper
{

	//构造函数
	public TreasureRpcTreasureUnEquipReplyWraper()
	{
		 m_Result = -1;
		 m_TreasureUnequiped = new TreasureDataWraper();
		 m_TreasureEquiped = new TreasureDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureUnequiped = new TreasureDataWraper();
		 m_TreasureEquiped = new TreasureDataWraper();

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureUnEquipReply ToPB()
	{
		TreasureRpcTreasureUnEquipReply v = new TreasureRpcTreasureUnEquipReply();
		v.Result = m_Result;
		v.TreasureUnequiped = m_TreasureUnequiped.ToPB();
		v.TreasureEquiped = m_TreasureEquiped.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureUnEquipReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureUnequiped.FromPB(v.TreasureUnequiped);
		m_TreasureEquiped.FromPB(v.TreasureEquiped);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureUnEquipReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureUnEquipReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureUnEquipReply>(protoMS);
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
	//卸下的珍宝
	public TreasureDataWraper m_TreasureUnequiped;
	public TreasureDataWraper TreasureUnequiped
	{
		get { return m_TreasureUnequiped;}
		set { m_TreasureUnequiped = value; }
	}
	//穿上的默认时装
	public TreasureDataWraper m_TreasureEquiped;
	public TreasureDataWraper TreasureEquiped
	{
		get { return m_TreasureEquiped;}
		set { m_TreasureEquiped = value; }
	}


};
//已装备时装ID通知封装类
[System.Serializable]
public class TreasureRpcTreasureEquipedIDNotifyWraper
{

	//构造函数
	public TreasureRpcTreasureEquipedIDNotifyWraper()
	{
		 m_TreasureID = new TreasureEquipedIDWraper();
		 m_ObjID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TreasureID = new TreasureEquipedIDWraper();
		 m_ObjID = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureEquipedIDNotify ToPB()
	{
		TreasureRpcTreasureEquipedIDNotify v = new TreasureRpcTreasureEquipedIDNotify();
		v.TreasureID = m_TreasureID.ToPB();
		v.ObjID = m_ObjID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureEquipedIDNotify v)
	{
        if (v == null)
            return;
		m_TreasureID.FromPB(v.TreasureID);
		m_ObjID = v.ObjID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureEquipedIDNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureEquipedIDNotify pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureEquipedIDNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备的时装ID
	public TreasureEquipedIDWraper m_TreasureID;
	public TreasureEquipedIDWraper TreasureID
	{
		get { return m_TreasureID;}
		set { m_TreasureID = value; }
	}
	//objid
	public int m_ObjID;
	public int ObjID
	{
		get { return m_ObjID;}
		set { m_ObjID = value; }
	}


};
//续期请求封装类
[System.Serializable]
public class TreasureRpcTreasureDelayTimeAskWraper
{

	//构造函数
	public TreasureRpcTreasureDelayTimeAskWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Id = -1;
		 m_Color_Type = -1;
		 m_Time_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDelayTimeAsk ToPB()
	{
		TreasureRpcTreasureDelayTimeAsk v = new TreasureRpcTreasureDelayTimeAsk();
		v.Id = m_Id;
		v.Color_Type = m_Color_Type;
		v.Time_Type = m_Time_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDelayTimeAsk v)
	{
        if (v == null)
            return;
		m_Id = v.Id;
		m_Color_Type = v.Color_Type;
		m_Time_Type = v.Time_Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDelayTimeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDelayTimeAsk pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDelayTimeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//珍宝ID
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}
	//附加颜色类型
	public int m_Color_Type;
	public int Color_Type
	{
		get { return m_Color_Type;}
		set { m_Color_Type = value; }
	}
	//时限类型
	public int m_Time_Type;
	public int Time_Type
	{
		get { return m_Time_Type;}
		set { m_Time_Type = value; }
	}


};
//续期回应封装类
[System.Serializable]
public class TreasureRpcTreasureDelayTimeReplyWraper
{

	//构造函数
	public TreasureRpcTreasureDelayTimeReplyWraper()
	{
		 m_Result = -1;
		 m_TreasureUnLocked = new TreasureDataWraper();
		 m_Points = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureUnLocked = new TreasureDataWraper();
		 m_Points = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureDelayTimeReply ToPB()
	{
		TreasureRpcTreasureDelayTimeReply v = new TreasureRpcTreasureDelayTimeReply();
		v.Result = m_Result;
		v.TreasureUnLocked = m_TreasureUnLocked.ToPB();
		v.Points = m_Points;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureDelayTimeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureUnLocked.FromPB(v.TreasureUnLocked);
		m_Points = v.Points;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureDelayTimeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureDelayTimeReply pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureDelayTimeReply>(protoMS);
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
	//已解锁的珍宝
	public TreasureDataWraper m_TreasureUnLocked;
	public TreasureDataWraper TreasureUnLocked
	{
		get { return m_TreasureUnLocked;}
		set { m_TreasureUnLocked = value; }
	}
	//珍宝阁点数
	public int m_Points;
	public int Points
	{
		get { return m_Points;}
		set { m_Points = value; }
	}


};
//解锁并穿戴通知封装类
[System.Serializable]
public class TreasureRpcTreasureUnlockEquipNotifyWraper
{

	//构造函数
	public TreasureRpcTreasureUnlockEquipNotifyWraper()
	{
		 m_Result = -1;
		 m_TreasureEquiped = new TreasureDataWraper();
		 m_TreasureUnequiped = new TreasureDataWraper();
		 m_Points = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_TreasureEquiped = new TreasureDataWraper();
		 m_TreasureUnequiped = new TreasureDataWraper();
		 m_Points = -1;

	}

 	//转化成Protobuffer类型函数
	public TreasureRpcTreasureUnlockEquipNotify ToPB()
	{
		TreasureRpcTreasureUnlockEquipNotify v = new TreasureRpcTreasureUnlockEquipNotify();
		v.Result = m_Result;
		v.TreasureEquiped = m_TreasureEquiped.ToPB();
		v.TreasureUnequiped = m_TreasureUnequiped.ToPB();
		v.Points = m_Points;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TreasureRpcTreasureUnlockEquipNotify v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_TreasureEquiped.FromPB(v.TreasureEquiped);
		m_TreasureUnequiped.FromPB(v.TreasureUnequiped);
		m_Points = v.Points;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TreasureRpcTreasureUnlockEquipNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TreasureRpcTreasureUnlockEquipNotify pb = ProtoBuf.Serializer.Deserialize<TreasureRpcTreasureUnlockEquipNotify>(protoMS);
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
	//穿戴的珍宝
	public TreasureDataWraper m_TreasureEquiped;
	public TreasureDataWraper TreasureEquiped
	{
		get { return m_TreasureEquiped;}
		set { m_TreasureEquiped = value; }
	}
	//脱掉的珍宝
	public TreasureDataWraper m_TreasureUnequiped;
	public TreasureDataWraper TreasureUnequiped
	{
		get { return m_TreasureUnequiped;}
		set { m_TreasureUnequiped = value; }
	}
	//珍宝阁点数
	public int m_Points;
	public int Points
	{
		get { return m_Points;}
		set { m_Points = value; }
	}


};
