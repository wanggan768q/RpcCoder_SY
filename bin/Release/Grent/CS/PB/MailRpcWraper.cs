
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBMail.cs
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


//初始化邮件信息请求封装类
[System.Serializable]
public class MailRpcInitMailAskWraper
{

	//构造函数
	public MailRpcInitMailAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public MailRpcInitMailAsk ToPB()
	{
		MailRpcInitMailAsk v = new MailRpcInitMailAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcInitMailAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcInitMailAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcInitMailAsk pb = ProtoBuf.Serializer.Deserialize<MailRpcInitMailAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//初始化邮件信息回应封装类
[System.Serializable]
public class MailRpcInitMailReplyWraper
{

	//构造函数
	public MailRpcInitMailReplyWraper()
	{
		 m_Result = -1;
		m_InfoList = new List<MailInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_InfoList = new List<MailInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public MailRpcInitMailReply ToPB()
	{
		MailRpcInitMailReply v = new MailRpcInitMailReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_InfoList.Count; i++)
			v.InfoList.Add( m_InfoList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcInitMailReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_InfoList.Clear();
		for( int i=0; i<v.InfoList.Count; i++)
			m_InfoList.Add( new MailInfoWraper());
		for( int i=0; i<v.InfoList.Count; i++)
			m_InfoList[i].FromPB(v.InfoList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcInitMailReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcInitMailReply pb = ProtoBuf.Serializer.Deserialize<MailRpcInitMailReply>(protoMS);
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
	//邮件信息列表
	public List<MailInfoWraper> m_InfoList;
	public int SizeInfoList()
	{
		return m_InfoList.Count;
	}
	public List<MailInfoWraper> GetInfoList()
	{
		return m_InfoList;
	}
	public MailInfoWraper GetInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_InfoList.Count)
			return new MailInfoWraper();
		return m_InfoList[Index];
	}
	public void SetInfoList( List<MailInfoWraper> v )
	{
		m_InfoList=v;
	}
	public void SetInfoList( int Index, MailInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_InfoList.Count)
			return;
		m_InfoList[Index] = v;
	}
	public void AddInfoList( MailInfoWraper v )
	{
		m_InfoList.Add(v);
	}
	public void ClearInfoList( )
	{
		m_InfoList.Clear();
	}


};
//已读邮件请求封装类
[System.Serializable]
public class MailRpcReadMailAskWraper
{

	//构造函数
	public MailRpcReadMailAskWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

 	//转化成Protobuffer类型函数
	public MailRpcReadMailAsk ToPB()
	{
		MailRpcReadMailAsk v = new MailRpcReadMailAsk();
		v.Mail_type = m_Mail_type;
		v.Mail_id = m_Mail_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcReadMailAsk v)
	{
        if (v == null)
            return;
		m_Mail_type = v.Mail_type;
		m_Mail_id = v.Mail_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcReadMailAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcReadMailAsk pb = ProtoBuf.Serializer.Deserialize<MailRpcReadMailAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//邮件类型
	public int m_Mail_type;
	public int Mail_type
	{
		get { return m_Mail_type;}
		set { m_Mail_type = value; }
	}
	//主键id
	public int m_Mail_id;
	public int Mail_id
	{
		get { return m_Mail_id;}
		set { m_Mail_id = value; }
	}


};
//已读邮件回应封装类
[System.Serializable]
public class MailRpcReadMailReplyWraper
{

	//构造函数
	public MailRpcReadMailReplyWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public MailRpcReadMailReply ToPB()
	{
		MailRpcReadMailReply v = new MailRpcReadMailReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_System_mail_ids.Count; i++)
			v.System_mail_ids.Add( m_System_mail_ids[i]);
		for (int i=0; i<(int)m_Private_mail_ids.Count; i++)
			v.Private_mail_ids.Add( m_Private_mail_ids[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcReadMailReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_System_mail_ids.Clear();
		for( int i=0; i<v.System_mail_ids.Count; i++)
			m_System_mail_ids.Add(v.System_mail_ids[i]);
		m_Private_mail_ids.Clear();
		for( int i=0; i<v.Private_mail_ids.Count; i++)
			m_Private_mail_ids.Add(v.Private_mail_ids[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcReadMailReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcReadMailReply pb = ProtoBuf.Serializer.Deserialize<MailRpcReadMailReply>(protoMS);
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
	//已读系统邮件
	public List<int> m_System_mail_ids;
	public int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.Count;
	}
	public List<int> GetSystem_mail_ids()
	{
		return m_System_mail_ids;
	}
	public int GetSystem_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return -1;
		return m_System_mail_ids[Index];
	}
	public void SetSystem_mail_ids( List<int> v )
	{
		m_System_mail_ids=v;
	}
	public void SetSystem_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return;
		m_System_mail_ids[Index] = v;
	}
	public void AddSystem_mail_ids( int v=-1 )
	{
		m_System_mail_ids.Add(v);
	}
	public void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.Clear();
	}
	//已读私有邮件
	public List<int> m_Private_mail_ids;
	public int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.Count;
	}
	public List<int> GetPrivate_mail_ids()
	{
		return m_Private_mail_ids;
	}
	public int GetPrivate_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return -1;
		return m_Private_mail_ids[Index];
	}
	public void SetPrivate_mail_ids( List<int> v )
	{
		m_Private_mail_ids=v;
	}
	public void SetPrivate_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return;
		m_Private_mail_ids[Index] = v;
	}
	public void AddPrivate_mail_ids( int v=-1 )
	{
		m_Private_mail_ids.Add(v);
	}
	public void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.Clear();
	}


};
//删除邮件请求封装类
[System.Serializable]
public class MailRpcDeleteMailAskWraper
{

	//构造函数
	public MailRpcDeleteMailAskWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

 	//转化成Protobuffer类型函数
	public MailRpcDeleteMailAsk ToPB()
	{
		MailRpcDeleteMailAsk v = new MailRpcDeleteMailAsk();
		v.Mail_type = m_Mail_type;
		v.Mail_id = m_Mail_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcDeleteMailAsk v)
	{
        if (v == null)
            return;
		m_Mail_type = v.Mail_type;
		m_Mail_id = v.Mail_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcDeleteMailAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcDeleteMailAsk pb = ProtoBuf.Serializer.Deserialize<MailRpcDeleteMailAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//邮件类型
	public int m_Mail_type;
	public int Mail_type
	{
		get { return m_Mail_type;}
		set { m_Mail_type = value; }
	}
	//主键id
	public int m_Mail_id;
	public int Mail_id
	{
		get { return m_Mail_id;}
		set { m_Mail_id = value; }
	}


};
//删除邮件回应封装类
[System.Serializable]
public class MailRpcDeleteMailReplyWraper
{

	//构造函数
	public MailRpcDeleteMailReplyWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public MailRpcDeleteMailReply ToPB()
	{
		MailRpcDeleteMailReply v = new MailRpcDeleteMailReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_System_mail_ids.Count; i++)
			v.System_mail_ids.Add( m_System_mail_ids[i]);
		for (int i=0; i<(int)m_Private_mail_ids.Count; i++)
			v.Private_mail_ids.Add( m_Private_mail_ids[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcDeleteMailReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_System_mail_ids.Clear();
		for( int i=0; i<v.System_mail_ids.Count; i++)
			m_System_mail_ids.Add(v.System_mail_ids[i]);
		m_Private_mail_ids.Clear();
		for( int i=0; i<v.Private_mail_ids.Count; i++)
			m_Private_mail_ids.Add(v.Private_mail_ids[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcDeleteMailReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcDeleteMailReply pb = ProtoBuf.Serializer.Deserialize<MailRpcDeleteMailReply>(protoMS);
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
	//已读系统邮件
	public List<int> m_System_mail_ids;
	public int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.Count;
	}
	public List<int> GetSystem_mail_ids()
	{
		return m_System_mail_ids;
	}
	public int GetSystem_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return -1;
		return m_System_mail_ids[Index];
	}
	public void SetSystem_mail_ids( List<int> v )
	{
		m_System_mail_ids=v;
	}
	public void SetSystem_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return;
		m_System_mail_ids[Index] = v;
	}
	public void AddSystem_mail_ids( int v=-1 )
	{
		m_System_mail_ids.Add(v);
	}
	public void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.Clear();
	}
	//已读私有邮件
	public List<int> m_Private_mail_ids;
	public int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.Count;
	}
	public List<int> GetPrivate_mail_ids()
	{
		return m_Private_mail_ids;
	}
	public int GetPrivate_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return -1;
		return m_Private_mail_ids[Index];
	}
	public void SetPrivate_mail_ids( List<int> v )
	{
		m_Private_mail_ids=v;
	}
	public void SetPrivate_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return;
		m_Private_mail_ids[Index] = v;
	}
	public void AddPrivate_mail_ids( int v=-1 )
	{
		m_Private_mail_ids.Add(v);
	}
	public void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.Clear();
	}


};
//领取邮件请求封装类
[System.Serializable]
public class MailRpcGetMailAskWraper
{

	//构造函数
	public MailRpcGetMailAskWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Mail_type = -1;
		 m_Mail_id = -1;

	}

 	//转化成Protobuffer类型函数
	public MailRpcGetMailAsk ToPB()
	{
		MailRpcGetMailAsk v = new MailRpcGetMailAsk();
		v.Mail_type = m_Mail_type;
		v.Mail_id = m_Mail_id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcGetMailAsk v)
	{
        if (v == null)
            return;
		m_Mail_type = v.Mail_type;
		m_Mail_id = v.Mail_id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcGetMailAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcGetMailAsk pb = ProtoBuf.Serializer.Deserialize<MailRpcGetMailAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//邮件类型
	public int m_Mail_type;
	public int Mail_type
	{
		get { return m_Mail_type;}
		set { m_Mail_type = value; }
	}
	//主键id
	public int m_Mail_id;
	public int Mail_id
	{
		get { return m_Mail_id;}
		set { m_Mail_id = value; }
	}


};
//领取邮件回应封装类
[System.Serializable]
public class MailRpcGetMailReplyWraper
{

	//构造函数
	public MailRpcGetMailReplyWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_System_mail_ids = new List<int>();
		m_Private_mail_ids = new List<int>();

	}

 	//转化成Protobuffer类型函数
	public MailRpcGetMailReply ToPB()
	{
		MailRpcGetMailReply v = new MailRpcGetMailReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_System_mail_ids.Count; i++)
			v.System_mail_ids.Add( m_System_mail_ids[i]);
		for (int i=0; i<(int)m_Private_mail_ids.Count; i++)
			v.Private_mail_ids.Add( m_Private_mail_ids[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcGetMailReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_System_mail_ids.Clear();
		for( int i=0; i<v.System_mail_ids.Count; i++)
			m_System_mail_ids.Add(v.System_mail_ids[i]);
		m_Private_mail_ids.Clear();
		for( int i=0; i<v.Private_mail_ids.Count; i++)
			m_Private_mail_ids.Add(v.Private_mail_ids[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcGetMailReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcGetMailReply pb = ProtoBuf.Serializer.Deserialize<MailRpcGetMailReply>(protoMS);
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
	//已读系统邮件
	public List<int> m_System_mail_ids;
	public int SizeSystem_mail_ids()
	{
		return m_System_mail_ids.Count;
	}
	public List<int> GetSystem_mail_ids()
	{
		return m_System_mail_ids;
	}
	public int GetSystem_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return -1;
		return m_System_mail_ids[Index];
	}
	public void SetSystem_mail_ids( List<int> v )
	{
		m_System_mail_ids=v;
	}
	public void SetSystem_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_System_mail_ids.Count)
			return;
		m_System_mail_ids[Index] = v;
	}
	public void AddSystem_mail_ids( int v=-1 )
	{
		m_System_mail_ids.Add(v);
	}
	public void ClearSystem_mail_ids( )
	{
		m_System_mail_ids.Clear();
	}
	//已读私有邮件
	public List<int> m_Private_mail_ids;
	public int SizePrivate_mail_ids()
	{
		return m_Private_mail_ids.Count;
	}
	public List<int> GetPrivate_mail_ids()
	{
		return m_Private_mail_ids;
	}
	public int GetPrivate_mail_ids(int Index)
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return -1;
		return m_Private_mail_ids[Index];
	}
	public void SetPrivate_mail_ids( List<int> v )
	{
		m_Private_mail_ids=v;
	}
	public void SetPrivate_mail_ids( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_Private_mail_ids.Count)
			return;
		m_Private_mail_ids[Index] = v;
	}
	public void AddPrivate_mail_ids( int v=-1 )
	{
		m_Private_mail_ids.Add(v);
	}
	public void ClearPrivate_mail_ids( )
	{
		m_Private_mail_ids.Clear();
	}


};
//同步邮件信息通知封装类
[System.Serializable]
public class MailRpcSyncMailInfoNotifyWraper
{

	//构造函数
	public MailRpcSyncMailInfoNotifyWraper()
	{
		m_InfoList = new List<MailInfoWraper>();
		m_GuidList = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_InfoList = new List<MailInfoWraper>();
		m_GuidList = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public MailRpcSyncMailInfoNotify ToPB()
	{
		MailRpcSyncMailInfoNotify v = new MailRpcSyncMailInfoNotify();
		for (int i=0; i<(int)m_InfoList.Count; i++)
			v.InfoList.Add( m_InfoList[i].ToPB());
		for (int i=0; i<(int)m_GuidList.Count; i++)
			v.GuidList.Add( m_GuidList[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MailRpcSyncMailInfoNotify v)
	{
        if (v == null)
            return;
		m_InfoList.Clear();
		for( int i=0; i<v.InfoList.Count; i++)
			m_InfoList.Add( new MailInfoWraper());
		for( int i=0; i<v.InfoList.Count; i++)
			m_InfoList[i].FromPB(v.InfoList[i]);
		m_GuidList.Clear();
		for( int i=0; i<v.GuidList.Count; i++)
			m_GuidList.Add(v.GuidList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MailRpcSyncMailInfoNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MailRpcSyncMailInfoNotify pb = ProtoBuf.Serializer.Deserialize<MailRpcSyncMailInfoNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//更新的邮件信息列表
	public List<MailInfoWraper> m_InfoList;
	public int SizeInfoList()
	{
		return m_InfoList.Count;
	}
	public List<MailInfoWraper> GetInfoList()
	{
		return m_InfoList;
	}
	public MailInfoWraper GetInfoList(int Index)
	{
		if(Index<0 || Index>=(int)m_InfoList.Count)
			return new MailInfoWraper();
		return m_InfoList[Index];
	}
	public void SetInfoList( List<MailInfoWraper> v )
	{
		m_InfoList=v;
	}
	public void SetInfoList( int Index, MailInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_InfoList.Count)
			return;
		m_InfoList[Index] = v;
	}
	public void AddInfoList( MailInfoWraper v )
	{
		m_InfoList.Add(v);
	}
	public void ClearInfoList( )
	{
		m_InfoList.Clear();
	}
	//删除的主键id列表
	public List<UInt64> m_GuidList;
	public int SizeGuidList()
	{
		return m_GuidList.Count;
	}
	public List<UInt64> GetGuidList()
	{
		return m_GuidList;
	}
	public UInt64 GetGuidList(int Index)
	{
		if(Index<0 || Index>=(int)m_GuidList.Count)
			return 0;
		return m_GuidList[Index];
	}
	public void SetGuidList( List<UInt64> v )
	{
		m_GuidList=v;
	}
	public void SetGuidList( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_GuidList.Count)
			return;
		m_GuidList[Index] = v;
	}
	public void AddGuidList( UInt64 v=0 )
	{
		m_GuidList.Add(v);
	}
	public void ClearGuidList( )
	{
		m_GuidList.Clear();
	}


};
