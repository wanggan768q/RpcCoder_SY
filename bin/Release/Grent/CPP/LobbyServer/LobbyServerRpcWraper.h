/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperLobbyServer.h
* Author:       甘业清
* Description:  大厅服务器RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_LOBBYSERVER_H
#define __RPC_WRAPER_LOBBYSERVER_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "LobbyServerRpc.pb.h"



//大厅服务器类的枚举定义
enum ConstLobbyServerE
{
	MODULE_ID_LOBBYSERVER                        = 36,	//大厅服务器模块ID
	RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST   = 3651,	//大厅服务器-->获取服务器列表-->请求


};


//获取服务器列表回应封装类
class LobbyServerRpcGetServerListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LobbyServerRpcGetServerListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	LobbyServerRpcGetServerListReplyWraper(const LobbyServerRpcGetServerListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LobbyServerRpcGetServerListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LobbyServerRpcGetServerListReply ToPB() const
	{
		LobbyServerRpcGetServerListReply v;
		v.set_result( m_Result );
		v.mutable_server_list()->Reserve(m_Server_list.size());
		for (int i=0; i<(int)m_Server_list.size(); i++)
		{
			*v.add_server_list() = m_Server_list[i].ToPB();
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
		LobbyServerRpcGetServerListReply pb;
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
	void Init(const LobbyServerRpcGetServerListReply& v)
	{
		m_Result = v.result();
		m_Server_list.clear();
		m_Server_list.reserve(v.server_list_size());
		for( int i=0; i<v.server_list_size(); i++)
			m_Server_list.push_back(v.server_list(i));

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
	//服务器列表
	vector<ServerInfoWraper> m_Server_list;
public:
	int SizeServer_list()
	{
		return m_Server_list.size();
	}
	const vector<ServerInfoWraper>& GetServer_list() const
	{
		return m_Server_list;
	}
	ServerInfoWraper GetServer_list(int Index) const
	{
		if(Index<0 || Index>=(int)m_Server_list.size())
		{
			assert(false);
			return ServerInfoWraper();
		}
		return m_Server_list[Index];
	}
	void SetServer_list( const vector<ServerInfoWraper>& v )
	{
		m_Server_list=v;
	}
	void ClearServer_list( )
	{
		m_Server_list.clear();
	}
	void SetServer_list( int Index, const ServerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Server_list.size())
		{
			assert(false);
			return;
		}
		m_Server_list[Index] = v;
	}
	void AddServer_list( const ServerInfoWraper& v )
	{
		m_Server_list.push_back(v);
	}

};
//获取服务器列表请求封装类
class LobbyServerRpcGetServerListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LobbyServerRpcGetServerListAskWraper()
	{
		
		m_Sdk_user_id = "";

	}
	//赋值构造函数
	LobbyServerRpcGetServerListAskWraper(const LobbyServerRpcGetServerListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LobbyServerRpcGetServerListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LobbyServerRpcGetServerListAsk ToPB() const
	{
		LobbyServerRpcGetServerListAsk v;
		v.set_sdk_user_id( m_Sdk_user_id );

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
		LobbyServerRpcGetServerListAsk pb;
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
	void Init(const LobbyServerRpcGetServerListAsk& v)
	{
		m_Sdk_user_id = v.sdk_user_id();

	}

private:
	//sdk_user_id
	string m_Sdk_user_id;
public:
	void SetSdk_user_id( const string& v)
	{
		m_Sdk_user_id=v;
	}
	string GetSdk_user_id()
	{
		return m_Sdk_user_id;
	}
	string GetSdk_user_id() const
	{
		return m_Sdk_user_id;
	}

};

template<typename T> struct MessageIdT;


#endif
