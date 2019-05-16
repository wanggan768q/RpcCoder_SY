
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBMedicament.cs
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


//使用物品填充hp池请求封装类
[System.Serializable]
public class MedicamentRpcFillHpAskWraper
{

	//构造函数
	public MedicamentRpcFillHpAskWraper()
	{
		 m_ItemData = new ItemSimpleDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemData = new ItemSimpleDataWraper();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcFillHpAsk ToPB()
	{
		MedicamentRpcFillHpAsk v = new MedicamentRpcFillHpAsk();
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcFillHpAsk v)
	{
        if (v == null)
            return;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcFillHpAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcFillHpAsk pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcFillHpAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品id
	public ItemSimpleDataWraper m_ItemData;
	public ItemSimpleDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//使用物品填充hp池回应封装类
[System.Serializable]
public class MedicamentRpcFillHpReplyWraper
{

	//构造函数
	public MedicamentRpcFillHpReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcFillHpReply ToPB()
	{
		MedicamentRpcFillHpReply v = new MedicamentRpcFillHpReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcFillHpReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcFillHpReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcFillHpReply pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcFillHpReply>(protoMS);
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
//一键添加请求封装类
[System.Serializable]
public class MedicamentRpcOneStepFillHpAskWraper
{

	//构造函数
	public MedicamentRpcOneStepFillHpAskWraper()
	{
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_ItemData = new List<ItemSimpleDataWraper>();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcOneStepFillHpAsk ToPB()
	{
		MedicamentRpcOneStepFillHpAsk v = new MedicamentRpcOneStepFillHpAsk();
		for (int i=0; i<(int)m_ItemData.Count; i++)
			v.ItemData.Add( m_ItemData[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcOneStepFillHpAsk v)
	{
        if (v == null)
            return;
		m_ItemData.Clear();
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData.Add( new ItemSimpleDataWraper());
		for( int i=0; i<v.ItemData.Count; i++)
			m_ItemData[i].FromPB(v.ItemData[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcOneStepFillHpAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcOneStepFillHpAsk pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcOneStepFillHpAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品id
	public List<ItemSimpleDataWraper> m_ItemData;
	public int SizeItemData()
	{
		return m_ItemData.Count;
	}
	public List<ItemSimpleDataWraper> GetItemData()
	{
		return m_ItemData;
	}
	public ItemSimpleDataWraper GetItemData(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return new ItemSimpleDataWraper();
		return m_ItemData[Index];
	}
	public void SetItemData( List<ItemSimpleDataWraper> v )
	{
		m_ItemData=v;
	}
	public void SetItemData( int Index, ItemSimpleDataWraper v )
	{
		if(Index<0 || Index>=(int)m_ItemData.Count)
			return;
		m_ItemData[Index] = v;
	}
	public void AddItemData( ItemSimpleDataWraper v )
	{
		m_ItemData.Add(v);
	}
	public void ClearItemData( )
	{
		m_ItemData.Clear();
	}


};
//一键添加回应封装类
[System.Serializable]
public class MedicamentRpcOneStepFillHpReplyWraper
{

	//构造函数
	public MedicamentRpcOneStepFillHpReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcOneStepFillHpReply ToPB()
	{
		MedicamentRpcOneStepFillHpReply v = new MedicamentRpcOneStepFillHpReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcOneStepFillHpReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcOneStepFillHpReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcOneStepFillHpReply pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcOneStepFillHpReply>(protoMS);
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
//客户端刷新药剂请求封装类
[System.Serializable]
public class MedicamentRpcClientRefreshMedicamentAskWraper
{

	//构造函数
	public MedicamentRpcClientRefreshMedicamentAskWraper()
	{
		 m_Medicament = new RecoverMedicamentWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Medicament = new RecoverMedicamentWraper();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcClientRefreshMedicamentAsk ToPB()
	{
		MedicamentRpcClientRefreshMedicamentAsk v = new MedicamentRpcClientRefreshMedicamentAsk();
		v.Medicament = m_Medicament.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcClientRefreshMedicamentAsk v)
	{
        if (v == null)
            return;
		m_Medicament.FromPB(v.Medicament);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcClientRefreshMedicamentAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcClientRefreshMedicamentAsk pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcClientRefreshMedicamentAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//药剂
	public RecoverMedicamentWraper m_Medicament;
	public RecoverMedicamentWraper Medicament
	{
		get { return m_Medicament;}
		set { m_Medicament = value; }
	}


};
//客户端刷新药剂回应封装类
[System.Serializable]
public class MedicamentRpcClientRefreshMedicamentReplyWraper
{

	//构造函数
	public MedicamentRpcClientRefreshMedicamentReplyWraper()
	{
		 m_Result = -1;
		 m_Medicament = new RecoverMedicamentWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Medicament = new RecoverMedicamentWraper();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcClientRefreshMedicamentReply ToPB()
	{
		MedicamentRpcClientRefreshMedicamentReply v = new MedicamentRpcClientRefreshMedicamentReply();
		v.Result = m_Result;
		v.Medicament = m_Medicament.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcClientRefreshMedicamentReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Medicament.FromPB(v.Medicament);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcClientRefreshMedicamentReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcClientRefreshMedicamentReply pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcClientRefreshMedicamentReply>(protoMS);
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
	//药剂
	public RecoverMedicamentWraper m_Medicament;
	public RecoverMedicamentWraper Medicament
	{
		get { return m_Medicament;}
		set { m_Medicament = value; }
	}


};
//服务器刷新药剂通知封装类
[System.Serializable]
public class MedicamentRpcServerRefreshMedicamentNotifyWraper
{

	//构造函数
	public MedicamentRpcServerRefreshMedicamentNotifyWraper()
	{
		 m_Medicament = new RecoverMedicamentWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Medicament = new RecoverMedicamentWraper();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcServerRefreshMedicamentNotify ToPB()
	{
		MedicamentRpcServerRefreshMedicamentNotify v = new MedicamentRpcServerRefreshMedicamentNotify();
		v.Medicament = m_Medicament.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcServerRefreshMedicamentNotify v)
	{
        if (v == null)
            return;
		m_Medicament.FromPB(v.Medicament);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcServerRefreshMedicamentNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcServerRefreshMedicamentNotify pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcServerRefreshMedicamentNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//药剂
	public RecoverMedicamentWraper m_Medicament;
	public RecoverMedicamentWraper Medicament
	{
		get { return m_Medicament;}
		set { m_Medicament = value; }
	}


};
//请求数据请求封装类
[System.Serializable]
public class MedicamentRpcSyncMedicamentDataAskWraper
{

	//构造函数
	public MedicamentRpcSyncMedicamentDataAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcSyncMedicamentDataAsk ToPB()
	{
		MedicamentRpcSyncMedicamentDataAsk v = new MedicamentRpcSyncMedicamentDataAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcSyncMedicamentDataAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcSyncMedicamentDataAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcSyncMedicamentDataAsk pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcSyncMedicamentDataAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//请求数据回应封装类
[System.Serializable]
public class MedicamentRpcSyncMedicamentDataReplyWraper
{

	//构造函数
	public MedicamentRpcSyncMedicamentDataReplyWraper()
	{
		 m_Result = -1;
		 m_Medicament = new RecoverMedicamentWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Medicament = new RecoverMedicamentWraper();

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcSyncMedicamentDataReply ToPB()
	{
		MedicamentRpcSyncMedicamentDataReply v = new MedicamentRpcSyncMedicamentDataReply();
		v.Result = m_Result;
		v.Medicament = m_Medicament.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcSyncMedicamentDataReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Medicament.FromPB(v.Medicament);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcSyncMedicamentDataReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcSyncMedicamentDataReply pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcSyncMedicamentDataReply>(protoMS);
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
	//药剂
	public RecoverMedicamentWraper m_Medicament;
	public RecoverMedicamentWraper Medicament
	{
		get { return m_Medicament;}
		set { m_Medicament = value; }
	}


};
//药剂CD请求封装类
[System.Serializable]
public class MedicamentRpcMedicamentCDAskWraper
{

	//构造函数
	public MedicamentRpcMedicamentCDAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcMedicamentCDAsk ToPB()
	{
		MedicamentRpcMedicamentCDAsk v = new MedicamentRpcMedicamentCDAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcMedicamentCDAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcMedicamentCDAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcMedicamentCDAsk pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcMedicamentCDAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//药剂CD回应封装类
[System.Serializable]
public class MedicamentRpcMedicamentCDReplyWraper
{

	//构造函数
	public MedicamentRpcMedicamentCDReplyWraper()
	{
		 m_Result = -1;
		 m_LeftTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_LeftTime = -1;

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcMedicamentCDReply ToPB()
	{
		MedicamentRpcMedicamentCDReply v = new MedicamentRpcMedicamentCDReply();
		v.Result = m_Result;
		v.LeftTime = m_LeftTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcMedicamentCDReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_LeftTime = v.LeftTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcMedicamentCDReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcMedicamentCDReply pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcMedicamentCDReply>(protoMS);
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
	//剩余时间
	public int m_LeftTime;
	public int LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}


};
//通知CD通知封装类
[System.Serializable]
public class MedicamentRpcMedicamentCDNotifyNotifyWraper
{

	//构造函数
	public MedicamentRpcMedicamentCDNotifyNotifyWraper()
	{
		 m_LeftTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LeftTime = -1;

	}

 	//转化成Protobuffer类型函数
	public MedicamentRpcMedicamentCDNotifyNotify ToPB()
	{
		MedicamentRpcMedicamentCDNotifyNotify v = new MedicamentRpcMedicamentCDNotifyNotify();
		v.LeftTime = m_LeftTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MedicamentRpcMedicamentCDNotifyNotify v)
	{
        if (v == null)
            return;
		m_LeftTime = v.LeftTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MedicamentRpcMedicamentCDNotifyNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MedicamentRpcMedicamentCDNotifyNotify pb = ProtoBuf.Serializer.Deserialize<MedicamentRpcMedicamentCDNotifyNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//剩余时间
	public int m_LeftTime;
	public int LeftTime
	{
		get { return m_LeftTime;}
		set { m_LeftTime = value; }
	}


};
