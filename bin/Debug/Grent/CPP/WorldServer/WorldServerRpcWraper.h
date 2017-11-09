/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperWorldServer.h
* Author:       郭晓波
* Description:  世界服务器模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_WORLDSERVER_H
#define __RPC_WRAPER_WORLDSERVER_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "WorldServerRpc.pb.h"



//世界服务器模块类的枚举定义
enum ConstWorldServerE
{
	MODULE_ID_WORLDSERVER                        = 8,	//世界服务器模块模块ID
	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST     = 851,	//世界服务器模块-->通知世界服务器切换场景-->请求
	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST      = 852,	//世界服务器模块-->进入场景-->请求


};


//进入场景请求封装类
class WorldServerRpcEnterSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcEnterSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;

	}
	//赋值构造函数
	WorldServerRpcEnterSceneAskWraper(const WorldServerRpcEnterSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcEnterSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcEnterSceneAsk ToPB() const
	{
		WorldServerRpcEnterSceneAsk v;
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
		WorldServerRpcEnterSceneAsk pb;
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
	void Init(const WorldServerRpcEnterSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();

	}

private:
	//角色id
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
//进入场景回应封装类
class WorldServerRpcEnterSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcEnterSceneReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	WorldServerRpcEnterSceneReplyWraper(const WorldServerRpcEnterSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcEnterSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcEnterSceneReply ToPB() const
	{
		WorldServerRpcEnterSceneReply v;
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
		WorldServerRpcEnterSceneReply pb;
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
	void Init(const WorldServerRpcEnterSceneReply& v)
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
//通知世界服务器切换场景请求封装类
class WorldServerRpcChangeSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcChangeSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;
		m_MemId = -1;

	}
	//赋值构造函数
	WorldServerRpcChangeSceneAskWraper(const WorldServerRpcChangeSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeSceneAsk ToPB() const
	{
		WorldServerRpcChangeSceneAsk v;
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_memid( m_MemId );

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
		WorldServerRpcChangeSceneAsk pb;
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
	void Init(const WorldServerRpcChangeSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();
		m_MemId = v.memid();

	}

private:
	//玩家的唯一id
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
	INT32 m_CurSceneId;
public:
	void SetCurSceneId( INT32 v)
	{
		m_CurSceneId=v;
	}
	INT32 GetCurSceneId()
	{
		return m_CurSceneId;
	}
	INT32 GetCurSceneId() const
	{
		return m_CurSceneId;
	}
private:
	//目标场景id
	INT32 m_TargetSceneId;
public:
	void SetTargetSceneId( INT32 v)
	{
		m_TargetSceneId=v;
	}
	INT32 GetTargetSceneId()
	{
		return m_TargetSceneId;
	}
	INT32 GetTargetSceneId() const
	{
		return m_TargetSceneId;
	}
private:
	//玩家的内存id
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}

};
//通知世界服务器切换场景回应封装类
class WorldServerRpcChangeSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldServerRpcChangeSceneReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;
		m_MemId = -1;

	}
	//赋值构造函数
	WorldServerRpcChangeSceneReplyWraper(const WorldServerRpcChangeSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldServerRpcChangeSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldServerRpcChangeSceneReply ToPB() const
	{
		WorldServerRpcChangeSceneReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_memid( m_MemId );

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
		WorldServerRpcChangeSceneReply pb;
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
	void Init(const WorldServerRpcChangeSceneReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();
		m_MemId = v.memid();

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
	//玩家的唯一id
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
	INT32 m_CurSceneId;
public:
	void SetCurSceneId( INT32 v)
	{
		m_CurSceneId=v;
	}
	INT32 GetCurSceneId()
	{
		return m_CurSceneId;
	}
	INT32 GetCurSceneId() const
	{
		return m_CurSceneId;
	}
private:
	//目标场景id
	INT32 m_TargetSceneId;
public:
	void SetTargetSceneId( INT32 v)
	{
		m_TargetSceneId=v;
	}
	INT32 GetTargetSceneId()
	{
		return m_TargetSceneId;
	}
	INT32 GetTargetSceneId() const
	{
		return m_TargetSceneId;
	}
private:
	//玩家的内存id
	INT32 m_MemId;
public:
	void SetMemId( INT32 v)
	{
		m_MemId=v;
	}
	INT32 GetMemId()
	{
		return m_MemId;
	}
	INT32 GetMemId() const
	{
		return m_MemId;
	}

};

template<typename T> struct MessageIdT;


#endif
