/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperDungeon.h
* Author:       郭晓波
* Description:  副本RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DUNGEON_H
#define __RPC_WRAPER_DUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DungeonRpc.pb.h"



//副本类的枚举定义
enum ConstDungeonE
{
	MODULE_ID_DUNGEON                            = 6,	//副本模块ID
	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST       = 651,	//副本-->CreateDungeon-->请求
	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST         = 652,	//副本-->退出副本-->请求


};


//退出副本请求封装类
class DungeonRpcExitDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcExitDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;

	}
	//赋值构造函数
	DungeonRpcExitDungeonAskWraper(const DungeonRpcExitDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcExitDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcExitDungeonAsk ToPB() const
	{
		DungeonRpcExitDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_sceneid( m_SceneId );

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
		DungeonRpcExitDungeonAsk pb;
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
	void Init(const DungeonRpcExitDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();

	}

private:
	//HumanRoleId
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
	//场景id
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}

};
//退出副本回应封装类
class DungeonRpcExitDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcExitDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	DungeonRpcExitDungeonReplyWraper(const DungeonRpcExitDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcExitDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcExitDungeonReply ToPB() const
	{
		DungeonRpcExitDungeonReply v;
		v.set_result( m_Result );

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
		DungeonRpcExitDungeonReply pb;
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
	void Init(const DungeonRpcExitDungeonReply& v)
	{
		m_Result = v.result();

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

};
//CreateDungeon请求封装类
class DungeonRpcCreateDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcCreateDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_DungeonConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonAskWraper(const DungeonRpcCreateDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonAsk ToPB() const
	{
		DungeonRpcCreateDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_dungeonconfigid( m_DungeonConfigId );

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
		DungeonRpcCreateDungeonAsk pb;
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
	void Init(const DungeonRpcCreateDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_DungeonConfigId = v.dungeonconfigid();

	}

private:
	//HumanRoleId
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
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}

};
//CreateDungeon回应封装类
class DungeonRpcCreateDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcCreateDungeonReplyWraper()
	{
		
		m_Result = -9999;
		m_DungeonConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonReplyWraper(const DungeonRpcCreateDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonReply ToPB() const
	{
		DungeonRpcCreateDungeonReply v;
		v.set_result( m_Result );
		v.set_dungeonconfigid( m_DungeonConfigId );

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
		DungeonRpcCreateDungeonReply pb;
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
	void Init(const DungeonRpcCreateDungeonReply& v)
	{
		m_Result = v.result();
		m_DungeonConfigId = v.dungeonconfigid();

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
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}

};

template<typename T> struct MessageIdT;


#endif
