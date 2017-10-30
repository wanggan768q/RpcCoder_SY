/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperLogin.h
* Author:       郭晓波
* Description:  登录模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_LOGIN_H
#define __RPC_WRAPER_LOGIN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "LoginRpc.pb.h"



//登录模块类的枚举定义
enum ConstLoginE
{
	MODULE_ID_LOGIN                              = 2,	//登录模块模块ID
	RPC_CODE_LOGIN_CONNECT_REQUEST               = 251,	//登录模块-->连接验证-->请求
	RPC_CODE_LOGIN_LOGIN_REQUEST                 = 252,	//登录模块-->登录-->请求
	RPC_CODE_LOGIN_CHARACTERLIST_REQUEST         = 253,	//登录模块-->角色列表-->请求
	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST       = 254,	//登录模块-->选择角色-->请求
	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST       = 255,	//登录模块-->创建角色-->请求


};


//选择角色请求封装类
class LoginRpcSelectCharacterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcSelectCharacterAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	LoginRpcSelectCharacterAskWraper(const LoginRpcSelectCharacterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcSelectCharacterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcSelectCharacterAsk ToPB() const
	{
		LoginRpcSelectCharacterAsk v;
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcSelectCharacterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcSelectCharacterAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//角色列表回应封装类
class LoginRpcCharacterListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCharacterListReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	LoginRpcCharacterListReplyWraper(const LoginRpcCharacterListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCharacterListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCharacterListReply ToPB() const
	{
		LoginRpcCharacterListReply v;
		v.set_result( m_Result );
		v.mutable_characterlist()->Reserve(m_CharacterList.size());
		for (int i=0; i<(int)m_CharacterList.size(); i++)
		{
			*v.add_characterlist() = m_CharacterList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcCharacterListReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcCharacterListReply& v)
	{
		m_Result = v.result();
		m_CharacterList.clear();
		m_CharacterList.reserve(v.characterlist_size());
		for( int i=0; i<v.characterlist_size(); i++)
			m_CharacterList.push_back(v.characterlist(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//所有角色信息
	vector<CharacterInfoWraper> m_CharacterList;
public:
	int SizeCharacterList()
	{
		return m_CharacterList.size();
	}
	const vector<CharacterInfoWraper>& GetCharacterList() const
	{
		return m_CharacterList;
	}
	CharacterInfoWraper GetCharacterList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CharacterList.size())
		{
			assert(false);
			return CharacterInfoWraper();
		}
		return m_CharacterList[Index];
	}
	void SetCharacterList( const vector<CharacterInfoWraper>& v )
	{
		m_CharacterList=v;
	}
	void ClearCharacterList( )
	{
		m_CharacterList.clear();
	}
	void SetCharacterList( int Index, const CharacterInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_CharacterList.size())
		{
			assert(false);
			return;
		}
		m_CharacterList[Index] = v;
	}
	void AddCharacterList( const CharacterInfoWraper& v )
	{
		m_CharacterList.push_back(v);
	}

};
//选择角色回应封装类
class LoginRpcSelectCharacterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcSelectCharacterReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_Ip = "";
		m_Port = 0;

	}
	//赋值构造函数
	LoginRpcSelectCharacterReplyWraper(const LoginRpcSelectCharacterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcSelectCharacterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcSelectCharacterReply ToPB() const
	{
		LoginRpcSelectCharacterReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_ip( m_Ip );
		v.set_port( m_Port );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcSelectCharacterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcSelectCharacterReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_Ip = v.ip();
		m_Port = v.port();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//ip
	string m_Ip;
public:
	void SetIp( const string& v)
	{
		m_Ip=v;
	}
	string GetIp()
	{
		return m_Ip;
	}
	string GetIp() const
	{
		return m_Ip;
	}
private:
	//端口
	INT32 m_Port;
public:
	void SetPort( INT32 v)
	{
		m_Port=v;
	}
	INT32 GetPort()
	{
		return m_Port;
	}
	INT32 GetPort() const
	{
		return m_Port;
	}

};
//创建角色回应封装类
class LoginRpcCreateCharacterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCreateCharacterReplyWraper()
	{
		
		m_Result = -9999;
		m_Roleid = 0;

	}
	//赋值构造函数
	LoginRpcCreateCharacterReplyWraper(const LoginRpcCreateCharacterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCreateCharacterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCreateCharacterReply ToPB() const
	{
		LoginRpcCreateCharacterReply v;
		v.set_result( m_Result );
		v.set_roleid( m_Roleid );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcCreateCharacterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcCreateCharacterReply& v)
	{
		m_Result = v.result();
		m_Roleid = v.roleid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//角色id
	uint64_t m_Roleid;
public:
	void SetRoleid( uint64_t v)
	{
		m_Roleid=v;
	}
	uint64_t GetRoleid()
	{
		return m_Roleid;
	}
	uint64_t GetRoleid() const
	{
		return m_Roleid;
	}

};
//创建角色请求封装类
class LoginRpcCreateCharacterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCreateCharacterAskWraper()
	{
		
		m_Nickname = "";
		m_ConfigId = -1;

	}
	//赋值构造函数
	LoginRpcCreateCharacterAskWraper(const LoginRpcCreateCharacterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCreateCharacterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCreateCharacterAsk ToPB() const
	{
		LoginRpcCreateCharacterAsk v;
		v.set_nickname( m_Nickname );
		v.set_configid( m_ConfigId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcCreateCharacterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcCreateCharacterAsk& v)
	{
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();

	}

private:
	//昵称
	string m_Nickname;
public:
	void SetNickname( const string& v)
	{
		m_Nickname=v;
	}
	string GetNickname()
	{
		return m_Nickname;
	}
	string GetNickname() const
	{
		return m_Nickname;
	}
private:
	//配置表id
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}

};
//连接验证回应封装类
class LoginRpcConnectReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcConnectReplyWraper()
	{
		
		m_Result = -9999;
		m_Type = 0;

	}
	//赋值构造函数
	LoginRpcConnectReplyWraper(const LoginRpcConnectReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcConnectReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcConnectReply ToPB() const
	{
		LoginRpcConnectReply v;
		v.set_result( m_Result );
		v.set_type( m_Type );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcConnectReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcConnectReply& v)
	{
		m_Result = v.result();
		m_Type = v.type();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//连接验证请求封装类
class LoginRpcConnectAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcConnectAskWraper()
	{
		
		m_Type = -1;

	}
	//赋值构造函数
	LoginRpcConnectAskWraper(const LoginRpcConnectAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcConnectAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcConnectAsk ToPB() const
	{
		LoginRpcConnectAsk v;
		v.set_type( m_Type );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcConnectAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcConnectAsk& v)
	{
		m_Type = v.type();

	}

private:
	//连接类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//登录请求封装类
class LoginRpcLoginAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginAskWraper()
	{
		
		m_Username = "";
		m_Passwd = "";

	}
	//赋值构造函数
	LoginRpcLoginAskWraper(const LoginRpcLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginAsk ToPB() const
	{
		LoginRpcLoginAsk v;
		v.set_username( m_Username );
		v.set_passwd( m_Passwd );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcLoginAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcLoginAsk& v)
	{
		m_Username = v.username();
		m_Passwd = v.passwd();

	}

private:
	//用户名
	string m_Username;
public:
	void SetUsername( const string& v)
	{
		m_Username=v;
	}
	string GetUsername()
	{
		return m_Username;
	}
	string GetUsername() const
	{
		return m_Username;
	}
private:
	//密码
	string m_Passwd;
public:
	void SetPasswd( const string& v)
	{
		m_Passwd=v;
	}
	string GetPasswd()
	{
		return m_Passwd;
	}
	string GetPasswd() const
	{
		return m_Passwd;
	}

};
//角色列表请求封装类
class LoginRpcCharacterListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCharacterListAskWraper()
	{
		
		m_Accountname  = "";

	}
	//赋值构造函数
	LoginRpcCharacterListAskWraper(const LoginRpcCharacterListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCharacterListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCharacterListAsk ToPB() const
	{
		LoginRpcCharacterListAsk v;
		v.set_accountname ( m_Accountname  );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcCharacterListAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcCharacterListAsk& v)
	{
		m_Accountname  = v.accountname ();

	}

private:
	//账号
	string m_Accountname ;
public:
	void SetAccountname ( const string& v)
	{
		m_Accountname =v;
	}
	string GetAccountname ()
	{
		return m_Accountname ;
	}
	string GetAccountname () const
	{
		return m_Accountname ;
	}

};
//登录回应封装类
class LoginRpcLoginReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;

	}
	//赋值构造函数
	LoginRpcLoginReplyWraper(const LoginRpcLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginReply ToPB() const
	{
		LoginRpcLoginReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		LoginRpcLoginReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcLoginReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//用户ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};

template<typename T> struct MessageIdT;


#endif
