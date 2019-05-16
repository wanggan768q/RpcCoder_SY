
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBSkill.cs
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


//技能信息请求封装类
[System.Serializable]
public class SkillRpcSkillInfoAskWraper
{

	//构造函数
	public SkillRpcSkillInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SkillRpcSkillInfoAsk ToPB()
	{
		SkillRpcSkillInfoAsk v = new SkillRpcSkillInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcSkillInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcSkillInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcSkillInfoAsk pb = ProtoBuf.Serializer.Deserialize<SkillRpcSkillInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//技能信息回应封装类
[System.Serializable]
public class SkillRpcSkillInfoReplyWraper
{

	//构造函数
	public SkillRpcSkillInfoReplyWraper()
	{
		 m_Result = -1;
		 m_CurUseMastery = -1;
		m_ProfessionInfos = new List<ProfessionInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_CurUseMastery = -1;
		m_ProfessionInfos = new List<ProfessionInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillRpcSkillInfoReply ToPB()
	{
		SkillRpcSkillInfoReply v = new SkillRpcSkillInfoReply();
		v.Result = m_Result;
		v.CurUseMastery = m_CurUseMastery;
		for (int i=0; i<(int)m_ProfessionInfos.Count; i++)
			v.ProfessionInfos.Add( m_ProfessionInfos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcSkillInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_CurUseMastery = v.CurUseMastery;
		m_ProfessionInfos.Clear();
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos.Add( new ProfessionInfoWraper());
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos[i].FromPB(v.ProfessionInfos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcSkillInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcSkillInfoReply pb = ProtoBuf.Serializer.Deserialize<SkillRpcSkillInfoReply>(protoMS);
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
	//当前使用专精
	public int m_CurUseMastery;
	public int CurUseMastery
	{
		get { return m_CurUseMastery;}
		set { m_CurUseMastery = value; }
	}
	//技能信息
	public List<ProfessionInfoWraper> m_ProfessionInfos;
	public int SizeProfessionInfos()
	{
		return m_ProfessionInfos.Count;
	}
	public List<ProfessionInfoWraper> GetProfessionInfos()
	{
		return m_ProfessionInfos;
	}
	public ProfessionInfoWraper GetProfessionInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return new ProfessionInfoWraper();
		return m_ProfessionInfos[Index];
	}
	public void SetProfessionInfos( List<ProfessionInfoWraper> v )
	{
		m_ProfessionInfos=v;
	}
	public void SetProfessionInfos( int Index, ProfessionInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return;
		m_ProfessionInfos[Index] = v;
	}
	public void AddProfessionInfos( ProfessionInfoWraper v )
	{
		m_ProfessionInfos.Add(v);
	}
	public void ClearProfessionInfos( )
	{
		m_ProfessionInfos.Clear();
	}


};
//更新技能信息请求封装类
[System.Serializable]
public class SkillRpcUpdateSkillInfoAskWraper
{

	//构造函数
	public SkillRpcUpdateSkillInfoAskWraper()
	{
		m_ProfessionInfos = new List<ProfessionInfoWraper>();
		 m_CurUseMastery = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_ProfessionInfos = new List<ProfessionInfoWraper>();
		 m_CurUseMastery = -1;

	}

 	//转化成Protobuffer类型函数
	public SkillRpcUpdateSkillInfoAsk ToPB()
	{
		SkillRpcUpdateSkillInfoAsk v = new SkillRpcUpdateSkillInfoAsk();
		for (int i=0; i<(int)m_ProfessionInfos.Count; i++)
			v.ProfessionInfos.Add( m_ProfessionInfos[i].ToPB());
		v.CurUseMastery = m_CurUseMastery;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcUpdateSkillInfoAsk v)
	{
        if (v == null)
            return;
		m_ProfessionInfos.Clear();
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos.Add( new ProfessionInfoWraper());
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos[i].FromPB(v.ProfessionInfos[i]);
		m_CurUseMastery = v.CurUseMastery;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcUpdateSkillInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcUpdateSkillInfoAsk pb = ProtoBuf.Serializer.Deserialize<SkillRpcUpdateSkillInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能信息
	public List<ProfessionInfoWraper> m_ProfessionInfos;
	public int SizeProfessionInfos()
	{
		return m_ProfessionInfos.Count;
	}
	public List<ProfessionInfoWraper> GetProfessionInfos()
	{
		return m_ProfessionInfos;
	}
	public ProfessionInfoWraper GetProfessionInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return new ProfessionInfoWraper();
		return m_ProfessionInfos[Index];
	}
	public void SetProfessionInfos( List<ProfessionInfoWraper> v )
	{
		m_ProfessionInfos=v;
	}
	public void SetProfessionInfos( int Index, ProfessionInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return;
		m_ProfessionInfos[Index] = v;
	}
	public void AddProfessionInfos( ProfessionInfoWraper v )
	{
		m_ProfessionInfos.Add(v);
	}
	public void ClearProfessionInfos( )
	{
		m_ProfessionInfos.Clear();
	}
	//使用中的专精
	public int m_CurUseMastery;
	public int CurUseMastery
	{
		get { return m_CurUseMastery;}
		set { m_CurUseMastery = value; }
	}


};
//更新技能信息回应封装类
[System.Serializable]
public class SkillRpcUpdateSkillInfoReplyWraper
{

	//构造函数
	public SkillRpcUpdateSkillInfoReplyWraper()
	{
		 m_Result = -1;
		 m_CurUseMastery = -1;
		m_ProfessionInfos = new List<ProfessionInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_CurUseMastery = -1;
		m_ProfessionInfos = new List<ProfessionInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillRpcUpdateSkillInfoReply ToPB()
	{
		SkillRpcUpdateSkillInfoReply v = new SkillRpcUpdateSkillInfoReply();
		v.Result = m_Result;
		v.CurUseMastery = m_CurUseMastery;
		for (int i=0; i<(int)m_ProfessionInfos.Count; i++)
			v.ProfessionInfos.Add( m_ProfessionInfos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcUpdateSkillInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_CurUseMastery = v.CurUseMastery;
		m_ProfessionInfos.Clear();
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos.Add( new ProfessionInfoWraper());
		for( int i=0; i<v.ProfessionInfos.Count; i++)
			m_ProfessionInfos[i].FromPB(v.ProfessionInfos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcUpdateSkillInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcUpdateSkillInfoReply pb = ProtoBuf.Serializer.Deserialize<SkillRpcUpdateSkillInfoReply>(protoMS);
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
	//当前使用的专精页
	public int m_CurUseMastery;
	public int CurUseMastery
	{
		get { return m_CurUseMastery;}
		set { m_CurUseMastery = value; }
	}
	//最新的技能信息
	public List<ProfessionInfoWraper> m_ProfessionInfos;
	public int SizeProfessionInfos()
	{
		return m_ProfessionInfos.Count;
	}
	public List<ProfessionInfoWraper> GetProfessionInfos()
	{
		return m_ProfessionInfos;
	}
	public ProfessionInfoWraper GetProfessionInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return new ProfessionInfoWraper();
		return m_ProfessionInfos[Index];
	}
	public void SetProfessionInfos( List<ProfessionInfoWraper> v )
	{
		m_ProfessionInfos=v;
	}
	public void SetProfessionInfos( int Index, ProfessionInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.Count)
			return;
		m_ProfessionInfos[Index] = v;
	}
	public void AddProfessionInfos( ProfessionInfoWraper v )
	{
		m_ProfessionInfos.Add(v);
	}
	public void ClearProfessionInfos( )
	{
		m_ProfessionInfos.Clear();
	}


};
//技能栏位升级请求封装类
[System.Serializable]
public class SkillRpcLevelUpSkillPosAskWraper
{

	//构造函数
	public SkillRpcLevelUpSkillPosAskWraper()
	{
		 m_SkillPos = 0;
		 m_IsAuto = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillPos = 0;
		 m_IsAuto = false;

	}

 	//转化成Protobuffer类型函数
	public SkillRpcLevelUpSkillPosAsk ToPB()
	{
		SkillRpcLevelUpSkillPosAsk v = new SkillRpcLevelUpSkillPosAsk();
		v.SkillPos = m_SkillPos;
		v.IsAuto = m_IsAuto;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcLevelUpSkillPosAsk v)
	{
        if (v == null)
            return;
		m_SkillPos = v.SkillPos;
		m_IsAuto = v.IsAuto;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcLevelUpSkillPosAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcLevelUpSkillPosAsk pb = ProtoBuf.Serializer.Deserialize<SkillRpcLevelUpSkillPosAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能栏位
	public int m_SkillPos;
	public int SkillPos
	{
		get { return m_SkillPos;}
		set { m_SkillPos = value; }
	}
	//是否一键升级
	public bool m_IsAuto;
	public bool IsAuto
	{
		get { return m_IsAuto;}
		set { m_IsAuto = value; }
	}


};
//技能栏位升级回应封装类
[System.Serializable]
public class SkillRpcLevelUpSkillPosReplyWraper
{

	//构造函数
	public SkillRpcLevelUpSkillPosReplyWraper()
	{
		 m_Result = -1;
		m_PosInfo = new List<SkillPosInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_PosInfo = new List<SkillPosInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillRpcLevelUpSkillPosReply ToPB()
	{
		SkillRpcLevelUpSkillPosReply v = new SkillRpcLevelUpSkillPosReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_PosInfo.Count; i++)
			v.PosInfo.Add( m_PosInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcLevelUpSkillPosReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_PosInfo.Clear();
		for( int i=0; i<v.PosInfo.Count; i++)
			m_PosInfo.Add( new SkillPosInfoWraper());
		for( int i=0; i<v.PosInfo.Count; i++)
			m_PosInfo[i].FromPB(v.PosInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcLevelUpSkillPosReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcLevelUpSkillPosReply pb = ProtoBuf.Serializer.Deserialize<SkillRpcLevelUpSkillPosReply>(protoMS);
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
	//技能位置信息
	public List<SkillPosInfoWraper> m_PosInfo;
	public int SizePosInfo()
	{
		return m_PosInfo.Count;
	}
	public List<SkillPosInfoWraper> GetPosInfo()
	{
		return m_PosInfo;
	}
	public SkillPosInfoWraper GetPosInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_PosInfo.Count)
			return new SkillPosInfoWraper();
		return m_PosInfo[Index];
	}
	public void SetPosInfo( List<SkillPosInfoWraper> v )
	{
		m_PosInfo=v;
	}
	public void SetPosInfo( int Index, SkillPosInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_PosInfo.Count)
			return;
		m_PosInfo[Index] = v;
	}
	public void AddPosInfo( SkillPosInfoWraper v )
	{
		m_PosInfo.Add(v);
	}
	public void ClearPosInfo( )
	{
		m_PosInfo.Clear();
	}


};
//技能栏位等级信息请求封装类
[System.Serializable]
public class SkillRpcSkillLevelInfoAskWraper
{

	//构造函数
	public SkillRpcSkillLevelInfoAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public SkillRpcSkillLevelInfoAsk ToPB()
	{
		SkillRpcSkillLevelInfoAsk v = new SkillRpcSkillLevelInfoAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcSkillLevelInfoAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcSkillLevelInfoAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcSkillLevelInfoAsk pb = ProtoBuf.Serializer.Deserialize<SkillRpcSkillLevelInfoAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//技能栏位等级信息回应封装类
[System.Serializable]
public class SkillRpcSkillLevelInfoReplyWraper
{

	//构造函数
	public SkillRpcSkillLevelInfoReplyWraper()
	{
		 m_Result = -1;
		m_PosInfo = new List<SkillPosInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_PosInfo = new List<SkillPosInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public SkillRpcSkillLevelInfoReply ToPB()
	{
		SkillRpcSkillLevelInfoReply v = new SkillRpcSkillLevelInfoReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_PosInfo.Count; i++)
			v.PosInfo.Add( m_PosInfo[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(SkillRpcSkillLevelInfoReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_PosInfo.Clear();
		for( int i=0; i<v.PosInfo.Count; i++)
			m_PosInfo.Add( new SkillPosInfoWraper());
		for( int i=0; i<v.PosInfo.Count; i++)
			m_PosInfo[i].FromPB(v.PosInfo[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SkillRpcSkillLevelInfoReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		SkillRpcSkillLevelInfoReply pb = ProtoBuf.Serializer.Deserialize<SkillRpcSkillLevelInfoReply>(protoMS);
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
	//技能位置信息
	public List<SkillPosInfoWraper> m_PosInfo;
	public int SizePosInfo()
	{
		return m_PosInfo.Count;
	}
	public List<SkillPosInfoWraper> GetPosInfo()
	{
		return m_PosInfo;
	}
	public SkillPosInfoWraper GetPosInfo(int Index)
	{
		if(Index<0 || Index>=(int)m_PosInfo.Count)
			return new SkillPosInfoWraper();
		return m_PosInfo[Index];
	}
	public void SetPosInfo( List<SkillPosInfoWraper> v )
	{
		m_PosInfo=v;
	}
	public void SetPosInfo( int Index, SkillPosInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_PosInfo.Count)
			return;
		m_PosInfo[Index] = v;
	}
	public void AddPosInfo( SkillPosInfoWraper v )
	{
		m_PosInfo.Add(v);
	}
	public void ClearPosInfo( )
	{
		m_PosInfo.Clear();
	}


};
