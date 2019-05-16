
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBPet.cs
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
public class PetRpcPetSyncAskWraper
{

	//构造函数
	public PetRpcPetSyncAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PetRpcPetSyncAsk ToPB()
	{
		PetRpcPetSyncAsk v = new PetRpcPetSyncAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcPetSyncAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcPetSyncAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcPetSyncAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcPetSyncAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//同步回应封装类
[System.Serializable]
public class PetRpcPetSyncReplyWraper
{

	//构造函数
	public PetRpcPetSyncReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcPetSyncReply ToPB()
	{
		PetRpcPetSyncReply v = new PetRpcPetSyncReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcPetSyncReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcPetSyncReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcPetSyncReply pb = ProtoBuf.Serializer.Deserialize<PetRpcPetSyncReply>(protoMS);
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
	//宠物数据
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//召回请求封装类
[System.Serializable]
public class PetRpcUnSummonAskWraper
{

	//构造函数
	public PetRpcUnSummonAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public PetRpcUnSummonAsk ToPB()
	{
		PetRpcUnSummonAsk v = new PetRpcUnSummonAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcUnSummonAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcUnSummonAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcUnSummonAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcUnSummonAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//召回回应封装类
[System.Serializable]
public class PetRpcUnSummonReplyWraper
{

	//构造函数
	public PetRpcUnSummonReplyWraper()
	{
		 m_Result = -1;
		 m_ItemObj = new ItemObjWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemObj = new ItemObjWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcUnSummonReply ToPB()
	{
		PetRpcUnSummonReply v = new PetRpcUnSummonReply();
		v.Result = m_Result;
		v.ItemObj = m_ItemObj.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcUnSummonReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemObj.FromPB(v.ItemObj);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcUnSummonReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcUnSummonReply pb = ProtoBuf.Serializer.Deserialize<PetRpcUnSummonReply>(protoMS);
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
	//ItemObj
	public ItemObjWraper m_ItemObj;
	public ItemObjWraper ItemObj
	{
		get { return m_ItemObj;}
		set { m_ItemObj = value; }
	}


};
//升级请求封装类
[System.Serializable]
public class PetRpcLevelUpgradeAskWraper
{

	//构造函数
	public PetRpcLevelUpgradeAskWraper()
	{
		 m_Guid = 0;
		m_ItemCount = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		m_ItemCount = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public PetRpcLevelUpgradeAsk ToPB()
	{
		PetRpcLevelUpgradeAsk v = new PetRpcLevelUpgradeAsk();
		v.Guid = m_Guid;
		for (int i=0; i<(int)m_ItemCount.Count; i++)
			v.ItemCount.Add( m_ItemCount[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcLevelUpgradeAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_ItemCount.Clear();
		for( int i=0; i<v.ItemCount.Count; i++)
			m_ItemCount.Add(v.ItemCount[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcLevelUpgradeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcLevelUpgradeAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcLevelUpgradeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//各类型道具数量
	public List<int> m_ItemCount;
	public int SizeItemCount()
	{
		return m_ItemCount.Count;
	}
	public List<int> GetItemCount()
	{
		return m_ItemCount;
	}
	public int GetItemCount(int Index)
	{
		if(Index<0 || Index>=(int)m_ItemCount.Count)
			return -1;
		return m_ItemCount[Index];
	}
	public void SetItemCount( List<int> v )
	{
		m_ItemCount=v;
	}
	public void SetItemCount( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ItemCount.Count)
			return;
		m_ItemCount[Index] = v;
	}
	public void AddItemCount( int v=-1 )
	{
		m_ItemCount.Add(v);
	}
	public void ClearItemCount( )
	{
		m_ItemCount.Clear();
	}


};
//升级回应封装类
[System.Serializable]
public class PetRpcLevelUpgradeReplyWraper
{

	//构造函数
	public PetRpcLevelUpgradeReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcLevelUpgradeReply ToPB()
	{
		PetRpcLevelUpgradeReply v = new PetRpcLevelUpgradeReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcLevelUpgradeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcLevelUpgradeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcLevelUpgradeReply pb = ProtoBuf.Serializer.Deserialize<PetRpcLevelUpgradeReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//升星请求封装类
[System.Serializable]
public class PetRpcStarUpgradeAskWraper
{

	//构造函数
	public PetRpcStarUpgradeAskWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public PetRpcStarUpgradeAsk ToPB()
	{
		PetRpcStarUpgradeAsk v = new PetRpcStarUpgradeAsk();
		v.Guid = m_Guid;
		v.UseGuid = m_UseGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcStarUpgradeAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_UseGuid = v.UseGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcStarUpgradeAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcStarUpgradeAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcStarUpgradeAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//Guid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//使用素材的GUID
	public UInt64 m_UseGuid;
	public UInt64 UseGuid
	{
		get { return m_UseGuid;}
		set { m_UseGuid = value; }
	}


};
//升星回应封装类
[System.Serializable]
public class PetRpcStarUpgradeReplyWraper
{

	//构造函数
	public PetRpcStarUpgradeReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcStarUpgradeReply ToPB()
	{
		PetRpcStarUpgradeReply v = new PetRpcStarUpgradeReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcStarUpgradeReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcStarUpgradeReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcStarUpgradeReply pb = ProtoBuf.Serializer.Deserialize<PetRpcStarUpgradeReply>(protoMS);
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
	//道具数据
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//改名请求封装类
[System.Serializable]
public class PetRpcChangeNameAskWraper
{

	//构造函数
	public PetRpcChangeNameAskWraper()
	{
		 m_Guid = 0;
		 m_NewName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_NewName = "";

	}

 	//转化成Protobuffer类型函数
	public PetRpcChangeNameAsk ToPB()
	{
		PetRpcChangeNameAsk v = new PetRpcChangeNameAsk();
		v.Guid = m_Guid;
		v.NewName = m_NewName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcChangeNameAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_NewName = v.NewName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcChangeNameAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcChangeNameAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcChangeNameAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//GUID
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//新名字
	public string m_NewName;
	public string NewName
	{
		get { return m_NewName;}
		set { m_NewName = value; }
	}


};
//改名回应封装类
[System.Serializable]
public class PetRpcChangeNameReplyWraper
{

	//构造函数
	public PetRpcChangeNameReplyWraper()
	{
		 m_Result = -1;
		 m_Name = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_Name = "";

	}

 	//转化成Protobuffer类型函数
	public PetRpcChangeNameReply ToPB()
	{
		PetRpcChangeNameReply v = new PetRpcChangeNameReply();
		v.Result = m_Result;
		v.Name = m_Name;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcChangeNameReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Name = v.Name;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcChangeNameReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcChangeNameReply pb = ProtoBuf.Serializer.Deserialize<PetRpcChangeNameReply>(protoMS);
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
	//名字
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}


};
//传承请求封装类
[System.Serializable]
public class PetRpcInheritAskWraper
{

	//构造函数
	public PetRpcInheritAskWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public PetRpcInheritAsk ToPB()
	{
		PetRpcInheritAsk v = new PetRpcInheritAsk();
		v.Guid = m_Guid;
		v.UseGuid = m_UseGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcInheritAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_UseGuid = v.UseGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcInheritAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcInheritAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcInheritAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要操作的道具GUid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//使用道具的GUid
	public UInt64 m_UseGuid;
	public UInt64 UseGuid
	{
		get { return m_UseGuid;}
		set { m_UseGuid = value; }
	}


};
//传承回应封装类
[System.Serializable]
public class PetRpcInheritReplyWraper
{

	//构造函数
	public PetRpcInheritReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcInheritReply ToPB()
	{
		PetRpcInheritReply v = new PetRpcInheritReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcInheritReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcInheritReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcInheritReply pb = ProtoBuf.Serializer.Deserialize<PetRpcInheritReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//技能继承请求封装类
[System.Serializable]
public class PetRpcSkillInheritAskWraper
{

	//构造函数
	public PetRpcSkillInheritAskWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_UseGuid = 0;

	}

 	//转化成Protobuffer类型函数
	public PetRpcSkillInheritAsk ToPB()
	{
		PetRpcSkillInheritAsk v = new PetRpcSkillInheritAsk();
		v.Guid = m_Guid;
		v.UseGuid = m_UseGuid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcSkillInheritAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_UseGuid = v.UseGuid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcSkillInheritAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcSkillInheritAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcSkillInheritAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//要操作的道具GUid
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//使用道具的GUid
	public UInt64 m_UseGuid;
	public UInt64 UseGuid
	{
		get { return m_UseGuid;}
		set { m_UseGuid = value; }
	}


};
//技能继承回应封装类
[System.Serializable]
public class PetRpcSkillInheritReplyWraper
{

	//构造函数
	public PetRpcSkillInheritReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcSkillInheritReply ToPB()
	{
		PetRpcSkillInheritReply v = new PetRpcSkillInheritReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcSkillInheritReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcSkillInheritReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcSkillInheritReply pb = ProtoBuf.Serializer.Deserialize<PetRpcSkillInheritReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//宠物被动技能列表请求封装类
[System.Serializable]
public class PetRpcPassiveSkillsAskWraper
{

	//构造函数
	public PetRpcPassiveSkillsAskWraper()
	{
		 m_Guid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;

	}

 	//转化成Protobuffer类型函数
	public PetRpcPassiveSkillsAsk ToPB()
	{
		PetRpcPassiveSkillsAsk v = new PetRpcPassiveSkillsAsk();
		v.Guid = m_Guid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcPassiveSkillsAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcPassiveSkillsAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcPassiveSkillsAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcPassiveSkillsAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//宠物唯一id
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}


};
//宠物被动技能列表回应封装类
[System.Serializable]
public class PetRpcPassiveSkillsReplyWraper
{

	//构造函数
	public PetRpcPassiveSkillsReplyWraper()
	{
		 m_Result = -1;
		m_Skills = new List<PetSkillWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_Skills = new List<PetSkillWraper>();

	}

 	//转化成Protobuffer类型函数
	public PetRpcPassiveSkillsReply ToPB()
	{
		PetRpcPassiveSkillsReply v = new PetRpcPassiveSkillsReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_Skills.Count; i++)
			v.Skills.Add( m_Skills[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcPassiveSkillsReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Skills.Clear();
		for( int i=0; i<v.Skills.Count; i++)
			m_Skills.Add( new PetSkillWraper());
		for( int i=0; i<v.Skills.Count; i++)
			m_Skills[i].FromPB(v.Skills[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcPassiveSkillsReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcPassiveSkillsReply pb = ProtoBuf.Serializer.Deserialize<PetRpcPassiveSkillsReply>(protoMS);
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
	//宠物被动技能列表
	public List<PetSkillWraper> m_Skills;
	public int SizeSkills()
	{
		return m_Skills.Count;
	}
	public List<PetSkillWraper> GetSkills()
	{
		return m_Skills;
	}
	public PetSkillWraper GetSkills(int Index)
	{
		if(Index<0 || Index>=(int)m_Skills.Count)
			return new PetSkillWraper();
		return m_Skills[Index];
	}
	public void SetSkills( List<PetSkillWraper> v )
	{
		m_Skills=v;
	}
	public void SetSkills( int Index, PetSkillWraper v )
	{
		if(Index<0 || Index>=(int)m_Skills.Count)
			return;
		m_Skills[Index] = v;
	}
	public void AddSkills( PetSkillWraper v )
	{
		m_Skills.Add(v);
	}
	public void ClearSkills( )
	{
		m_Skills.Clear();
	}


};
//学习被动技能请求封装类
[System.Serializable]
public class PetRpcStudySkillAskWraper
{

	//构造函数
	public PetRpcStudySkillAskWraper()
	{
		 m_Guid = 0;
		 m_ItemId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_ItemId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetRpcStudySkillAsk ToPB()
	{
		PetRpcStudySkillAsk v = new PetRpcStudySkillAsk();
		v.Guid = m_Guid;
		v.ItemId = m_ItemId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcStudySkillAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_ItemId = v.ItemId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcStudySkillAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcStudySkillAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcStudySkillAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品唯一id
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//道具id
	public int m_ItemId;
	public int ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}


};
//学习被动技能回应封装类
[System.Serializable]
public class PetRpcStudySkillReplyWraper
{

	//构造函数
	public PetRpcStudySkillReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();
		 m_ReplacedSkillId = -1;
		 m_Index = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();
		 m_ReplacedSkillId = -1;
		 m_Index = -1;

	}

 	//转化成Protobuffer类型函数
	public PetRpcStudySkillReply ToPB()
	{
		PetRpcStudySkillReply v = new PetRpcStudySkillReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();
		v.ReplacedSkillId = m_ReplacedSkillId;
		v.Index = m_Index;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcStudySkillReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);
		m_ReplacedSkillId = v.ReplacedSkillId;
		m_Index = v.Index;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcStudySkillReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcStudySkillReply pb = ProtoBuf.Serializer.Deserialize<PetRpcStudySkillReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}
	//替换掉的技能id
	public int m_ReplacedSkillId;
	public int ReplacedSkillId
	{
		get { return m_ReplacedSkillId;}
		set { m_ReplacedSkillId = value; }
	}
	//学习技能id
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}


};
//锁住技能请求封装类
[System.Serializable]
public class PetRpcLockSkillAskWraper
{

	//构造函数
	public PetRpcLockSkillAskWraper()
	{
		 m_Guid = 0;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetRpcLockSkillAsk ToPB()
	{
		PetRpcLockSkillAsk v = new PetRpcLockSkillAsk();
		v.Guid = m_Guid;
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcLockSkillAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcLockSkillAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcLockSkillAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcLockSkillAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品唯一id
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//锁住的技能id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//锁住技能回应封装类
[System.Serializable]
public class PetRpcLockSkillReplyWraper
{

	//构造函数
	public PetRpcLockSkillReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcLockSkillReply ToPB()
	{
		PetRpcLockSkillReply v = new PetRpcLockSkillReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcLockSkillReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcLockSkillReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcLockSkillReply pb = ProtoBuf.Serializer.Deserialize<PetRpcLockSkillReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
//解除技能锁定请求封装类
[System.Serializable]
public class PetRpcUnLockSkillAskWraper
{

	//构造函数
	public PetRpcUnLockSkillAskWraper()
	{
		 m_Guid = 0;
		 m_SkillId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Guid = 0;
		 m_SkillId = -1;

	}

 	//转化成Protobuffer类型函数
	public PetRpcUnLockSkillAsk ToPB()
	{
		PetRpcUnLockSkillAsk v = new PetRpcUnLockSkillAsk();
		v.Guid = m_Guid;
		v.SkillId = m_SkillId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcUnLockSkillAsk v)
	{
        if (v == null)
            return;
		m_Guid = v.Guid;
		m_SkillId = v.SkillId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcUnLockSkillAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcUnLockSkillAsk pb = ProtoBuf.Serializer.Deserialize<PetRpcUnLockSkillAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品唯一id
	public UInt64 m_Guid;
	public UInt64 Guid
	{
		get { return m_Guid;}
		set { m_Guid = value; }
	}
	//技能唯一id
	public int m_SkillId;
	public int SkillId
	{
		get { return m_SkillId;}
		set { m_SkillId = value; }
	}


};
//解除技能锁定回应封装类
[System.Serializable]
public class PetRpcUnLockSkillReplyWraper
{

	//构造函数
	public PetRpcUnLockSkillReplyWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		 m_ItemData = new ItemDataWraper();

	}

 	//转化成Protobuffer类型函数
	public PetRpcUnLockSkillReply ToPB()
	{
		PetRpcUnLockSkillReply v = new PetRpcUnLockSkillReply();
		v.Result = m_Result;
		v.ItemData = m_ItemData.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(PetRpcUnLockSkillReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_ItemData.FromPB(v.ItemData);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PetRpcUnLockSkillReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		PetRpcUnLockSkillReply pb = ProtoBuf.Serializer.Deserialize<PetRpcUnLockSkillReply>(protoMS);
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
	//道具属性
	public ItemDataWraper m_ItemData;
	public ItemDataWraper ItemData
	{
		get { return m_ItemData;}
		set { m_ItemData = value; }
	}


};
