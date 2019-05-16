
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBLogin.cs
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


//登录请求封装类
[System.Serializable]
public class LoginRpcLoginAskWraper
{

	//构造函数
	public LoginRpcLoginAskWraper()
	{
		 m_Username = "";
		 m_Passwd = "";
		 m_SnId = "";
		 m_GameId = "";
		 m_Mac = "";
		 m_Token = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Username = "";
		 m_Passwd = "";
		 m_SnId = "";
		 m_GameId = "";
		 m_Mac = "";
		 m_Token = "";

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginAsk ToPB()
	{
		LoginRpcLoginAsk v = new LoginRpcLoginAsk();
		v.Username = m_Username;
		v.Passwd = m_Passwd;
		v.SnId = m_SnId;
		v.GameId = m_GameId;
		v.Mac = m_Mac;
		v.Token = m_Token;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginAsk v)
	{
        if (v == null)
            return;
		m_Username = v.Username;
		m_Passwd = v.Passwd;
		m_SnId = v.SnId;
		m_GameId = v.GameId;
		m_Mac = v.Mac;
		m_Token = v.Token;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//用户名
	public string m_Username;
	public string Username
	{
		get { return m_Username;}
		set { m_Username = value; }
	}
	//密码
	public string m_Passwd;
	public string Passwd
	{
		get { return m_Passwd;}
		set { m_Passwd = value; }
	}
	//渠道号
	public string m_SnId;
	public string SnId
	{
		get { return m_SnId;}
		set { m_SnId = value; }
	}
	//GameId
	public string m_GameId;
	public string GameId
	{
		get { return m_GameId;}
		set { m_GameId = value; }
	}
	//mac地址
	public string m_Mac;
	public string Mac
	{
		get { return m_Mac;}
		set { m_Mac = value; }
	}
	//Token
	public string m_Token;
	public string Token
	{
		get { return m_Token;}
		set { m_Token = value; }
	}


};
//登录回应封装类
[System.Serializable]
public class LoginRpcLoginReplyWraper
{

	//构造函数
	public LoginRpcLoginReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_Pos = new Vector3Wraper();
		m_CharacterList = new List<CharacterInfoWraper>();
		 m_LastSelectRoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_Pos = new Vector3Wraper();
		m_CharacterList = new List<CharacterInfoWraper>();
		 m_LastSelectRoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginReply ToPB()
	{
		LoginRpcLoginReply v = new LoginRpcLoginReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.Pos = m_Pos.ToPB();
		for (int i=0; i<(int)m_CharacterList.Count; i++)
			v.CharacterList.Add( m_CharacterList[i].ToPB());
		v.LastSelectRoleId = m_LastSelectRoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_Pos.FromPB(v.Pos);
		m_CharacterList.Clear();
		for( int i=0; i<v.CharacterList.Count; i++)
			m_CharacterList.Add( new CharacterInfoWraper());
		for( int i=0; i<v.CharacterList.Count; i++)
			m_CharacterList[i].FromPB(v.CharacterList[i]);
		m_LastSelectRoleId = v.LastSelectRoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginReply>(protoMS);
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
	//用户ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//测试引用
	public Vector3Wraper m_Pos;
	public Vector3Wraper Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//所有角色信息
	public List<CharacterInfoWraper> m_CharacterList;
	public int SizeCharacterList()
	{
		return m_CharacterList.Count;
	}
	public List<CharacterInfoWraper> GetCharacterList()
	{
		return m_CharacterList;
	}
	public CharacterInfoWraper GetCharacterList(int Index)
	{
		if(Index<0 || Index>=(int)m_CharacterList.Count)
			return new CharacterInfoWraper();
		return m_CharacterList[Index];
	}
	public void SetCharacterList( List<CharacterInfoWraper> v )
	{
		m_CharacterList=v;
	}
	public void SetCharacterList( int Index, CharacterInfoWraper v )
	{
		if(Index<0 || Index>=(int)m_CharacterList.Count)
			return;
		m_CharacterList[Index] = v;
	}
	public void AddCharacterList( CharacterInfoWraper v )
	{
		m_CharacterList.Add(v);
	}
	public void ClearCharacterList( )
	{
		m_CharacterList.Clear();
	}
	//最后一次选择的角色ID
	public UInt64 m_LastSelectRoleId;
	public UInt64 LastSelectRoleId
	{
		get { return m_LastSelectRoleId;}
		set { m_LastSelectRoleId = value; }
	}


};
//选择角色请求封装类
[System.Serializable]
public class LoginRpcSelectCharacterAskWraper
{

	//构造函数
	public LoginRpcSelectCharacterAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcSelectCharacterAsk ToPB()
	{
		LoginRpcSelectCharacterAsk v = new LoginRpcSelectCharacterAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcSelectCharacterAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcSelectCharacterAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcSelectCharacterAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcSelectCharacterAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//选择角色回应封装类
[System.Serializable]
public class LoginRpcSelectCharacterReplyWraper
{

	//构造函数
	public LoginRpcSelectCharacterReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_LastSceneID = -1;
		 m_Ban_Reason = "";
		 m_LineId = -1;
		 m_Ban_EndTime = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_LastSceneID = -1;
		 m_Ban_Reason = "";
		 m_LineId = -1;
		 m_Ban_EndTime = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcSelectCharacterReply ToPB()
	{
		LoginRpcSelectCharacterReply v = new LoginRpcSelectCharacterReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.LastSceneID = m_LastSceneID;
		v.Ban_Reason = m_Ban_Reason;
		v.LineId = m_LineId;
		v.Ban_EndTime = m_Ban_EndTime;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcSelectCharacterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_LastSceneID = v.LastSceneID;
		m_Ban_Reason = v.Ban_Reason;
		m_LineId = v.LineId;
		m_Ban_EndTime = v.Ban_EndTime;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcSelectCharacterReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcSelectCharacterReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcSelectCharacterReply>(protoMS);
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
	//id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//LastSceneID
	public int m_LastSceneID;
	public int LastSceneID
	{
		get { return m_LastSceneID;}
		set { m_LastSceneID = value; }
	}
	//禁止理由
	public string m_Ban_Reason;
	public string Ban_Reason
	{
		get { return m_Ban_Reason;}
		set { m_Ban_Reason = value; }
	}
	//线id
	public int m_LineId;
	public int LineId
	{
		get { return m_LineId;}
		set { m_LineId = value; }
	}
	//解封时间戳
	public int m_Ban_EndTime;
	public int Ban_EndTime
	{
		get { return m_Ban_EndTime;}
		set { m_Ban_EndTime = value; }
	}


};
//创建角色请求封装类
[System.Serializable]
public class LoginRpcCreateCharacterAskWraper
{

	//构造函数
	public LoginRpcCreateCharacterAskWraper()
	{
		 m_Nickname = "";
		 m_ConfigId = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Nickname = "";
		 m_ConfigId = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcCreateCharacterAsk ToPB()
	{
		LoginRpcCreateCharacterAsk v = new LoginRpcCreateCharacterAsk();
		v.Nickname = m_Nickname;
		v.ConfigId = m_ConfigId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcCreateCharacterAsk v)
	{
        if (v == null)
            return;
		m_Nickname = v.Nickname;
		m_ConfigId = v.ConfigId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcCreateCharacterAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcCreateCharacterAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcCreateCharacterAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//昵称
	public string m_Nickname;
	public string Nickname
	{
		get { return m_Nickname;}
		set { m_Nickname = value; }
	}
	//配置表id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}


};
//创建角色回应封装类
[System.Serializable]
public class LoginRpcCreateCharacterReplyWraper
{

	//构造函数
	public LoginRpcCreateCharacterReplyWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_TimeStamp = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_TimeStamp = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcCreateCharacterReply ToPB()
	{
		LoginRpcCreateCharacterReply v = new LoginRpcCreateCharacterReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.TimeStamp = m_TimeStamp;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcCreateCharacterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_TimeStamp = v.TimeStamp;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcCreateCharacterReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcCreateCharacterReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcCreateCharacterReply>(protoMS);
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
	//角色id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//创建角色时间
	public int m_TimeStamp;
	public int TimeStamp
	{
		get { return m_TimeStamp;}
		set { m_TimeStamp = value; }
	}


};
//删除角色请求封装类
[System.Serializable]
public class LoginRpcDeleteCharacterAskWraper
{

	//构造函数
	public LoginRpcDeleteCharacterAskWraper()
	{
		 m_RoleId = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcDeleteCharacterAsk ToPB()
	{
		LoginRpcDeleteCharacterAsk v = new LoginRpcDeleteCharacterAsk();
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcDeleteCharacterAsk v)
	{
        if (v == null)
            return;
		m_RoleId = v.RoleId;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcDeleteCharacterAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcDeleteCharacterAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcDeleteCharacterAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//id
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}


};
//删除角色回应封装类
[System.Serializable]
public class LoginRpcDeleteCharacterReplyWraper
{

	//构造函数
	public LoginRpcDeleteCharacterReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcDeleteCharacterReply ToPB()
	{
		LoginRpcDeleteCharacterReply v = new LoginRpcDeleteCharacterReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcDeleteCharacterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcDeleteCharacterReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcDeleteCharacterReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcDeleteCharacterReply>(protoMS);
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
//Test请求封装类
[System.Serializable]
public class LoginRpcTestAskWraper
{

	//构造函数
	public LoginRpcTestAskWraper()
	{
		m_A = new List<Int64>();
		m_B = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_A = new List<Int64>();
		m_B = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public LoginRpcTestAsk ToPB()
	{
		LoginRpcTestAsk v = new LoginRpcTestAsk();
		for (int i=0; i<(int)m_A.Count; i++)
			v.A.Add( m_A[i]);
		for (int i=0; i<(int)m_B.Count; i++)
			v.B.Add( m_B[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcTestAsk v)
	{
        if (v == null)
            return;
		m_A.Clear();
		for( int i=0; i<v.A.Count; i++)
			m_A.Add(v.A[i]);
		m_B.Clear();
		for( int i=0; i<v.B.Count; i++)
			m_B.Add(v.B[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcTestAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcTestAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcTestAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//A
	public List<Int64> m_A;
	public int SizeA()
	{
		return m_A.Count;
	}
	public List<Int64> GetA()
	{
		return m_A;
	}
	public Int64 GetA(int Index)
	{
		if(Index<0 || Index>=(int)m_A.Count)
			return -1;
		return m_A[Index];
	}
	public void SetA( List<Int64> v )
	{
		m_A=v;
	}
	public void SetA( int Index, Int64 v )
	{
		if(Index<0 || Index>=(int)m_A.Count)
			return;
		m_A[Index] = v;
	}
	public void AddA( Int64 v=-1 )
	{
		m_A.Add(v);
	}
	public void ClearA( )
	{
		m_A.Clear();
	}
	//B
	public List<UInt64> m_B;
	public int SizeB()
	{
		return m_B.Count;
	}
	public List<UInt64> GetB()
	{
		return m_B;
	}
	public UInt64 GetB(int Index)
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return 0;
		return m_B[Index];
	}
	public void SetB( List<UInt64> v )
	{
		m_B=v;
	}
	public void SetB( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return;
		m_B[Index] = v;
	}
	public void AddB( UInt64 v=0 )
	{
		m_B.Add(v);
	}
	public void ClearB( )
	{
		m_B.Clear();
	}


};
//Test回应封装类
[System.Serializable]
public class LoginRpcTestReplyWraper
{

	//构造函数
	public LoginRpcTestReplyWraper()
	{
		 m_Result = -1;
		m_A = new List<Int64>();
		m_B = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;
		m_A = new List<Int64>();
		m_B = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public LoginRpcTestReply ToPB()
	{
		LoginRpcTestReply v = new LoginRpcTestReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_A.Count; i++)
			v.A.Add( m_A[i]);
		for (int i=0; i<(int)m_B.Count; i++)
			v.B.Add( m_B[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcTestReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_A.Clear();
		for( int i=0; i<v.A.Count; i++)
			m_A.Add(v.A[i]);
		m_B.Clear();
		for( int i=0; i<v.B.Count; i++)
			m_B.Add(v.B[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcTestReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcTestReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcTestReply>(protoMS);
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
	//A
	public List<Int64> m_A;
	public int SizeA()
	{
		return m_A.Count;
	}
	public List<Int64> GetA()
	{
		return m_A;
	}
	public Int64 GetA(int Index)
	{
		if(Index<0 || Index>=(int)m_A.Count)
			return -1;
		return m_A[Index];
	}
	public void SetA( List<Int64> v )
	{
		m_A=v;
	}
	public void SetA( int Index, Int64 v )
	{
		if(Index<0 || Index>=(int)m_A.Count)
			return;
		m_A[Index] = v;
	}
	public void AddA( Int64 v=-1 )
	{
		m_A.Add(v);
	}
	public void ClearA( )
	{
		m_A.Clear();
	}
	//B
	public List<UInt64> m_B;
	public int SizeB()
	{
		return m_B.Count;
	}
	public List<UInt64> GetB()
	{
		return m_B;
	}
	public UInt64 GetB(int Index)
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return 0;
		return m_B[Index];
	}
	public void SetB( List<UInt64> v )
	{
		m_B=v;
	}
	public void SetB( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return;
		m_B[Index] = v;
	}
	public void AddB( UInt64 v=0 )
	{
		m_B.Add(v);
	}
	public void ClearB( )
	{
		m_B.Clear();
	}


};
//Test1请求封装类
[System.Serializable]
public class LoginRpcTest1AskWraper
{

	//构造函数
	public LoginRpcTest1AskWraper()
	{
		m_B = new List<UInt64>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_B = new List<UInt64>();

	}

 	//转化成Protobuffer类型函数
	public LoginRpcTest1Ask ToPB()
	{
		LoginRpcTest1Ask v = new LoginRpcTest1Ask();
		for (int i=0; i<(int)m_B.Count; i++)
			v.B.Add( m_B[i]);

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcTest1Ask v)
	{
        if (v == null)
            return;
		m_B.Clear();
		for( int i=0; i<v.B.Count; i++)
			m_B.Add(v.B[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcTest1Ask>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcTest1Ask pb = ProtoBuf.Serializer.Deserialize<LoginRpcTest1Ask>(protoMS);
		FromPB(pb);
		return true;
	}

	//B
	public List<UInt64> m_B;
	public int SizeB()
	{
		return m_B.Count;
	}
	public List<UInt64> GetB()
	{
		return m_B;
	}
	public UInt64 GetB(int Index)
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return 0;
		return m_B[Index];
	}
	public void SetB( List<UInt64> v )
	{
		m_B=v;
	}
	public void SetB( int Index, UInt64 v )
	{
		if(Index<0 || Index>=(int)m_B.Count)
			return;
		m_B[Index] = v;
	}
	public void AddB( UInt64 v=0 )
	{
		m_B.Add(v);
	}
	public void ClearB( )
	{
		m_B.Clear();
	}


};
//Test1回应封装类
[System.Serializable]
public class LoginRpcTest1ReplyWraper
{

	//构造函数
	public LoginRpcTest1ReplyWraper()
	{
		 m_Result = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcTest1Reply ToPB()
	{
		LoginRpcTest1Reply v = new LoginRpcTest1Reply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcTest1Reply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcTest1Reply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcTest1Reply pb = ProtoBuf.Serializer.Deserialize<LoginRpcTest1Reply>(protoMS);
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
//登录 排队通知通知封装类
[System.Serializable]
public class LoginRpcLoginLineUpNotifyWraper
{

	//构造函数
	public LoginRpcLoginLineUpNotifyWraper()
	{
		 m_LineUpIndex = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_LineUpIndex = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginLineUpNotify ToPB()
	{
		LoginRpcLoginLineUpNotify v = new LoginRpcLoginLineUpNotify();
		v.LineUpIndex = m_LineUpIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginLineUpNotify v)
	{
        if (v == null)
            return;
		m_LineUpIndex = v.LineUpIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginLineUpNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginLineUpNotify pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginLineUpNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//排队索引
	public int m_LineUpIndex;
	public int LineUpIndex
	{
		get { return m_LineUpIndex;}
		set { m_LineUpIndex = value; }
	}


};
//可以登录服务器的通知通知封装类
[System.Serializable]
public class LoginRpcLoginEnterGameNotifyWraper
{

	//构造函数
	public LoginRpcLoginEnterGameNotifyWraper()
	{
		 m_RoleID = 0;
		 m_LastSceneID = -1;
		 m_LineID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RoleID = 0;
		 m_LastSceneID = -1;
		 m_LineID = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginEnterGameNotify ToPB()
	{
		LoginRpcLoginEnterGameNotify v = new LoginRpcLoginEnterGameNotify();
		v.RoleID = m_RoleID;
		v.LastSceneID = m_LastSceneID;
		v.LineID = m_LineID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginEnterGameNotify v)
	{
        if (v == null)
            return;
		m_RoleID = v.RoleID;
		m_LastSceneID = v.LastSceneID;
		m_LineID = v.LineID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcLoginEnterGameNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcLoginEnterGameNotify pb = ProtoBuf.Serializer.Deserialize<LoginRpcLoginEnterGameNotify>(protoMS);
		FromPB(pb);
		return true;
	}

	//角色ID
	public UInt64 m_RoleID;
	public UInt64 RoleID
	{
		get { return m_RoleID;}
		set { m_RoleID = value; }
	}
	//最后场景
	public int m_LastSceneID;
	public int LastSceneID
	{
		get { return m_LastSceneID;}
		set { m_LastSceneID = value; }
	}
	//线
	public int m_LineID;
	public int LineID
	{
		get { return m_LineID;}
		set { m_LineID = value; }
	}


};
