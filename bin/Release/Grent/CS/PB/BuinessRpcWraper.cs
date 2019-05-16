
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBBuiness.cs
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


//初始化请求封装类
[System.Serializable]
public class BuinessRpcBuinessSyncAskWraper
{

	//构造函数
	public BuinessRpcBuinessSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessSyncAsk ToPB()
	{
		BuinessRpcBuinessSyncAsk v = new BuinessRpcBuinessSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessSyncAsk pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//初始化回应封装类
[System.Serializable]
public class BuinessRpcBuinessSyncReplyWraper
{

	//构造函数
	public BuinessRpcBuinessSyncReplyWraper()
	{
		 m_Result = -1;
		m_SkillDatas = new List<BuinessSkillDataWraper>();
		m_UnLockInfos = new List<BuinessUnlockInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_SkillDatas = new List<BuinessSkillDataWraper>();
		m_UnLockInfos = new List<BuinessUnlockInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessSyncReply ToPB()
	{
		BuinessRpcBuinessSyncReply v = new BuinessRpcBuinessSyncReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_SkillDatas.Count; i++)
			v.SkillDatas.Add( m_SkillDatas[i].ToPB());
		for (int i=0; i<(int)m_UnLockInfos.Count; i++)
			v.UnLockInfos.Add( m_UnLockInfos[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SkillDatas.Clear();
		for( int i=0; i<v.SkillDatas.Count; i++)
			m_SkillDatas.Add( new BuinessSkillDataWraper());
		for( int i=0; i<v.SkillDatas.Count; i++)
			m_SkillDatas[i].FromPB(v.SkillDatas[i]);
		m_UnLockInfos.Clear();
		for( int i=0; i<v.UnLockInfos.Count; i++)
			m_UnLockInfos.Add( new BuinessUnlockInfoWraper());
		for( int i=0; i<v.UnLockInfos.Count; i++)
			m_UnLockInfos[i].FromPB(v.UnLockInfos[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessSyncReply pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessSyncReply>(protoMS);
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
	//生活技能列表
	public List<BuinessSkillDataWraper> m_SkillDatas;
	public int SizeSkillDatas()
	{
		return m_SkillDatas.Count;
	}
	public List<BuinessSkillDataWraper> GetSkillDatas()
	{
		return m_SkillDatas;
	}
	public BuinessSkillDataWraper GetSkillDatas(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillDatas.Count)
			return new BuinessSkillDataWraper();
		return m_SkillDatas[Index];
	}
	public void SetSkillDatas( List<BuinessSkillDataWraper> v )
	{
		m_SkillDatas=v;
	}
	public void SetSkillDatas( int Index, BuinessSkillDataWraper v )
	{
		if(Index<0 || Index>=(int)m_SkillDatas.Count)
			return;
		m_SkillDatas[Index] = v;
	}
	public void AddSkillDatas( BuinessSkillDataWraper v )
	{
		m_SkillDatas.Add(v);
	}
	public void ClearSkillDatas( )
	{
		m_SkillDatas.Clear();
	}
	//解锁剩余时间
	public List<BuinessUnlockInfoWraper> m_UnLockInfos;
	public int SizeUnLockInfos()
	{
		return m_UnLockInfos.Count;
	}
	public List<BuinessUnlockInfoWraper> GetUnLockInfos()
	{
		return m_UnLockInfos;
	}
	public BuinessUnlockInfoWraper GetUnLockInfos(int Index)
	{
		if(Index<0 || Index>=(int)m_UnLockInfos.Count)
			return new BuinessUnlockInfoWraper();
		return m_UnLockInfos[Index];
	}
	public void SetUnLockInfos( List<BuinessUnlockInfoWraper> v )
	{
		m_UnLockInfos=v;
	}
	public void SetUnLockInfos( int Index, BuinessUnlockInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_UnLockInfos.Count)
			return;
		m_UnLockInfos[Index] = v;
	}
	public void AddUnLockInfos( BuinessUnlockInfoWraper v )
	{
		m_UnLockInfos.Add(v);
	}
	public void ClearUnLockInfos( )
	{
		m_UnLockInfos.Clear();
	}


};
//解锁请求封装类
[System.Serializable]
public class BuinessRpcBuinessUnlockAskWraper
{

	//构造函数
	public BuinessRpcBuinessUnlockAskWraper()
	{
		 m_SkillID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillID = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessUnlockAsk ToPB()
	{
		BuinessRpcBuinessUnlockAsk v = new BuinessRpcBuinessUnlockAsk();
		v.SkillID = m_SkillID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessUnlockAsk v)
	{
        if (v == null)
            return;
		m_SkillID = v.SkillID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessUnlockAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessUnlockAsk pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessUnlockAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要解锁的ID
	public int m_SkillID;
	public int SkillID
	{
		get { return m_SkillID;}
		set { m_SkillID = value; }
	}


};
//解锁回应封装类
[System.Serializable]
public class BuinessRpcBuinessUnlockReplyWraper
{

	//构造函数
	public BuinessRpcBuinessUnlockReplyWraper()
	{
		 m_Result = -1;
		m_ChangeSkillDatas = new List<BuinessSkillDataWraper>();
		 m_UnLockInfo = new BuinessUnlockInfoWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_ChangeSkillDatas = new List<BuinessSkillDataWraper>();
		 m_UnLockInfo = new BuinessUnlockInfoWraper();

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessUnlockReply ToPB()
	{
		BuinessRpcBuinessUnlockReply v = new BuinessRpcBuinessUnlockReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_ChangeSkillDatas.Count; i++)
			v.ChangeSkillDatas.Add( m_ChangeSkillDatas[i].ToPB());
		v.UnLockInfo = m_UnLockInfo.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessUnlockReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ChangeSkillDatas.Clear();
		for( int i=0; i<v.ChangeSkillDatas.Count; i++)
			m_ChangeSkillDatas.Add( new BuinessSkillDataWraper());
		for( int i=0; i<v.ChangeSkillDatas.Count; i++)
			m_ChangeSkillDatas[i].FromPB(v.ChangeSkillDatas[i]);
		m_UnLockInfo.FromPB(v.UnLockInfo);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessUnlockReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessUnlockReply pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessUnlockReply>(protoMS);
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
	//改变的技能
	public List<BuinessSkillDataWraper> m_ChangeSkillDatas;
	public int SizeChangeSkillDatas()
	{
		return m_ChangeSkillDatas.Count;
	}
	public List<BuinessSkillDataWraper> GetChangeSkillDatas()
	{
		return m_ChangeSkillDatas;
	}
	public BuinessSkillDataWraper GetChangeSkillDatas(int Index)
	{
		if(Index<0 || Index>=(int)m_ChangeSkillDatas.Count)
			return new BuinessSkillDataWraper();
		return m_ChangeSkillDatas[Index];
	}
	public void SetChangeSkillDatas( List<BuinessSkillDataWraper> v )
	{
		m_ChangeSkillDatas=v;
	}
	public void SetChangeSkillDatas( int Index, BuinessSkillDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ChangeSkillDatas.Count)
			return;
		m_ChangeSkillDatas[Index] = v;
	}
	public void AddChangeSkillDatas( BuinessSkillDataWraper v )
	{
		m_ChangeSkillDatas.Add(v);
	}
	public void ClearChangeSkillDatas( )
	{
		m_ChangeSkillDatas.Clear();
	}
	//解锁信息
	public BuinessUnlockInfoWraper m_UnLockInfo;
	public BuinessUnlockInfoWraper UnLockInfo
	{
		get { return m_UnLockInfo;}
		set { m_UnLockInfo = value; }
	}


};
//学习技能请求封装类
[System.Serializable]
public class BuinessRpcBuinessStudyAskWraper
{

	//构造函数
	public BuinessRpcBuinessStudyAskWraper()
	{
		 m_SkillID = -1;
		 m_StudyType = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillID = -1;
		 m_StudyType = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessStudyAsk ToPB()
	{
		BuinessRpcBuinessStudyAsk v = new BuinessRpcBuinessStudyAsk();
		v.SkillID = m_SkillID;
		v.StudyType = m_StudyType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessStudyAsk v)
	{
        if (v == null)
            return;
		m_SkillID = v.SkillID;
		m_StudyType = v.StudyType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessStudyAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessStudyAsk pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessStudyAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//技能ID
	public int m_SkillID;
	public int SkillID
	{
		get { return m_SkillID;}
		set { m_SkillID = value; }
	}
	//学习类型
	public int m_StudyType;
	public int StudyType
	{
		get { return m_StudyType;}
		set { m_StudyType = value; }
	}


};
//学习技能回应封装类
[System.Serializable]
public class BuinessRpcBuinessStudyReplyWraper
{

	//构造函数
	public BuinessRpcBuinessStudyReplyWraper()
	{
		 m_Result = -1;
		 m_SkillData = new BuinessSkillDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_SkillData = new BuinessSkillDataWraper();

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessStudyReply ToPB()
	{
		BuinessRpcBuinessStudyReply v = new BuinessRpcBuinessStudyReply();
		v.Result = m_Result;
		v.SkillData = m_SkillData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessStudyReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_SkillData.FromPB(v.SkillData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessStudyReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessStudyReply pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessStudyReply>(protoMS);
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
	//技能新属性
	public BuinessSkillDataWraper m_SkillData;
	public BuinessSkillDataWraper SkillData
	{
		get { return m_SkillData;}
		set { m_SkillData = value; }
	}


};
//制作请求封装类
[System.Serializable]
public class BuinessRpcBuinessMakeAskWraper
{

	//构造函数
	public BuinessRpcBuinessMakeAskWraper()
	{
		 m_SkillID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SkillID = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessMakeAsk ToPB()
	{
		BuinessRpcBuinessMakeAsk v = new BuinessRpcBuinessMakeAsk();
		v.SkillID = m_SkillID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessMakeAsk v)
	{
        if (v == null)
            return;
		m_SkillID = v.SkillID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessMakeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessMakeAsk pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessMakeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//使用哪个技能
	public int m_SkillID;
	public int SkillID
	{
		get { return m_SkillID;}
		set { m_SkillID = value; }
	}


};
//制作回应封装类
[System.Serializable]
public class BuinessRpcBuinessMakeReplyWraper
{

	//构造函数
	public BuinessRpcBuinessMakeReplyWraper()
	{
		 m_Result = -1;
		 m_ItemID = -1;
		 m_ItemCount = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemID = -1;
		 m_ItemCount = -1;

	}

 	//转化成Protobuffer类型函数
	public BuinessRpcBuinessMakeReply ToPB()
	{
		BuinessRpcBuinessMakeReply v = new BuinessRpcBuinessMakeReply();
		v.Result = m_Result;
		v.ItemID = m_ItemID;
		v.ItemCount = m_ItemCount;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BuinessRpcBuinessMakeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemID = v.ItemID;
		m_ItemCount = v.ItemCount;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BuinessRpcBuinessMakeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BuinessRpcBuinessMakeReply pb = ProtoBuf.Serializer.Deserialize<BuinessRpcBuinessMakeReply>(protoMS);
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
	//道具ID
	public int m_ItemID;
	public int ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//数量
	public int m_ItemCount;
	public int ItemCount
	{
		get { return m_ItemCount;}
		set { m_ItemCount = value; }
	}


};
