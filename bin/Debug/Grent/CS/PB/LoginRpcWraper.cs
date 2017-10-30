
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


//连接验证请求封装类
[System.Serializable]
public class LoginRpcConnectAskWraper
{

	//构造函数
	public LoginRpcConnectAskWraper()
	{
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcConnectAsk ToPB()
	{
		LoginRpcConnectAsk v = new LoginRpcConnectAsk();
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcConnectAsk v)
	{
        if (v == null)
            return;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcConnectAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcConnectAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcConnectAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//连接类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//连接验证回应封装类
[System.Serializable]
public class LoginRpcConnectReplyWraper
{

	//构造函数
	public LoginRpcConnectReplyWraper()
	{
		 m_Result = -9999;
		 m_Type = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Type = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcConnectReply ToPB()
	{
		LoginRpcConnectReply v = new LoginRpcConnectReply();
		v.Result = m_Result;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcConnectReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcConnectReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcConnectReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcConnectReply>(protoMS);
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
	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//登录请求封装类
[System.Serializable]
public class LoginRpcLoginAskWraper
{

	//构造函数
	public LoginRpcLoginAskWraper()
	{
		 m_Username = "";
		 m_Passwd = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Username = "";
		 m_Passwd = "";

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginAsk ToPB()
	{
		LoginRpcLoginAsk v = new LoginRpcLoginAsk();
		v.Username = m_Username;
		v.Passwd = m_Passwd;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginAsk v)
	{
        if (v == null)
            return;
		m_Username = v.Username;
		m_Passwd = v.Passwd;

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

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcLoginReply ToPB()
	{
		LoginRpcLoginReply v = new LoginRpcLoginReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcLoginReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;

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


};
//角色列表请求封装类
[System.Serializable]
public class LoginRpcCharacterListAskWraper
{

	//构造函数
	public LoginRpcCharacterListAskWraper()
	{
		 m_Accountname  = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Accountname  = "";

	}

 	//转化成Protobuffer类型函数
	public LoginRpcCharacterListAsk ToPB()
	{
		LoginRpcCharacterListAsk v = new LoginRpcCharacterListAsk();
		v.Accountname  = m_Accountname ;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcCharacterListAsk v)
	{
        if (v == null)
            return;
		m_Accountname  = v.Accountname ;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcCharacterListAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcCharacterListAsk pb = ProtoBuf.Serializer.Deserialize<LoginRpcCharacterListAsk>(protoMS);
		FromPB(pb);
		return true;
	}

	//账号
	public string m_Accountname ;
	public string Accountname 
	{
		get { return m_Accountname ;}
		set { m_Accountname  = value; }
	}


};
//角色列表回应封装类
[System.Serializable]
public class LoginRpcCharacterListReplyWraper
{

	//构造函数
	public LoginRpcCharacterListReplyWraper()
	{
		 m_Result = -9999;
		m_CharacterList = new List<CharacterInfoWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		m_CharacterList = new List<CharacterInfoWraper>();

	}

 	//转化成Protobuffer类型函数
	public LoginRpcCharacterListReply ToPB()
	{
		LoginRpcCharacterListReply v = new LoginRpcCharacterListReply();
		v.Result = m_Result;
		for (int i=0; i<(int)m_CharacterList.Count; i++)
			v.CharacterList.Add( m_CharacterList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcCharacterListReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_CharacterList.Clear();
		for( int i=0; i<v.CharacterList.Count; i++)
			m_CharacterList.Add( new CharacterInfoWraper());
		for( int i=0; i<v.CharacterList.Count; i++)
			m_CharacterList[i].FromPB(v.CharacterList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcCharacterListReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		LoginRpcCharacterListReply pb = ProtoBuf.Serializer.Deserialize<LoginRpcCharacterListReply>(protoMS);
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
		 m_Ip = "";
		 m_Port = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_RoleId = 0;
		 m_Ip = "";
		 m_Port = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcSelectCharacterReply ToPB()
	{
		LoginRpcSelectCharacterReply v = new LoginRpcSelectCharacterReply();
		v.Result = m_Result;
		v.RoleId = m_RoleId;
		v.Ip = m_Ip;
		v.Port = m_Port;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcSelectCharacterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_RoleId = v.RoleId;
		m_Ip = v.Ip;
		m_Port = v.Port;

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
	//ip
	public string m_Ip;
	public string Ip
	{
		get { return m_Ip;}
		set { m_Ip = value; }
	}
	//端口
	public int m_Port;
	public int Port
	{
		get { return m_Port;}
		set { m_Port = value; }
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
		 m_Roleid = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;
		 m_Roleid = 0;

	}

 	//转化成Protobuffer类型函数
	public LoginRpcCreateCharacterReply ToPB()
	{
		LoginRpcCreateCharacterReply v = new LoginRpcCreateCharacterReply();
		v.Result = m_Result;
		v.Roleid = m_Roleid;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(LoginRpcCreateCharacterReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;
		m_Roleid = v.Roleid;

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
	public UInt64 m_Roleid;
	public UInt64 Roleid
	{
		get { return m_Roleid;}
		set { m_Roleid = value; }
	}


};
