/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperScene.h
* Author:       郭晓波
* Description:  场景模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SCENE_H
#define __RPC_WRAPER_SCENE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "SceneRpc.pb.h"



//场景模块类的枚举定义
enum ConstSceneE
{
	MODULE_ID_SCENE                              = 3,	//场景模块模块ID
	RPC_CODE_SCENE_ENTERSCENE_REQUEST            = 351,	//场景模块-->进入场景-->请求
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 352,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_NEWPLAYER_NOTIFY              = 353,	//场景模块-->新玩家进入视野-->通知
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 354,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 355,	//场景模块-->连接场景服务器-->请求


};


//删除玩家通知封装类
class SceneRpcDeletePlayerNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcDeletePlayerNotifyWraper()
	{
		
		m_ObjId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	SceneRpcDeletePlayerNotifyWraper(const SceneRpcDeletePlayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcDeletePlayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcDeletePlayerNotify ToPB() const
	{
		SceneRpcDeletePlayerNotify v;
		v.set_objid( m_ObjId );
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
		SceneRpcDeletePlayerNotify pb;
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
	void Init(const SceneRpcDeletePlayerNotify& v)
	{
		m_ObjId = v.objid();
		m_SceneId = v.sceneid();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
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
//新玩家进入视野通知封装类
class SceneRpcNewPlayerNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcNewPlayerNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_Dir = -1;
		m_ObjType = -1;
		m_ConfigId = -1;
		m_Status = -1;
		m_MoveSpeed = -1;

	}
	//赋值构造函数
	SceneRpcNewPlayerNotifyWraper(const SceneRpcNewPlayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcNewPlayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcNewPlayerNotify ToPB() const
	{
		SceneRpcNewPlayerNotify v;
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );
		v.set_objtype( m_ObjType );
		v.set_configid( m_ConfigId );
		v.set_status( m_Status );
		v.set_movespeed( m_MoveSpeed );

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
		SceneRpcNewPlayerNotify pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);
		tmpLine.Fmt("<li>MoveSpeed：%.2ff</li>\r\n",m_MoveSpeed);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcNewPlayerNotify& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();
		m_ObjType = v.objtype();
		m_ConfigId = v.configid();
		m_Status = v.status();
		m_MoveSpeed = v.movespeed();

	}

private:
	//obj id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//obj type
	INT32 m_ObjType;
public:
	void SetObjType( INT32 v)
	{
		m_ObjType=v;
	}
	INT32 GetObjType()
	{
		return m_ObjType;
	}
	INT32 GetObjType() const
	{
		return m_ObjType;
	}
private:
	//config id
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
private:
	//状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//移动速度
	float m_MoveSpeed;
public:
	void SetMoveSpeed( float v)
	{
		m_MoveSpeed=v;
	}
	float GetMoveSpeed()
	{
		return m_MoveSpeed;
	}
	float GetMoveSpeed() const
	{
		return m_MoveSpeed;
	}

};
//连接场景服务器回应封装类
class SceneRpcConnectGameServerReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcConnectGameServerReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;

	}
	//赋值构造函数
	SceneRpcConnectGameServerReplyWraper(const SceneRpcConnectGameServerReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcConnectGameServerReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcConnectGameServerReply ToPB() const
	{
		SceneRpcConnectGameServerReply v;
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
		SceneRpcConnectGameServerReply pb;
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
	void Init(const SceneRpcConnectGameServerReply& v)
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

};
//连接场景服务器请求封装类
class SceneRpcConnectGameServerAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcConnectGameServerAskWraper()
	{
		
		m_RoleId = 0;
		m_Key = "";

	}
	//赋值构造函数
	SceneRpcConnectGameServerAskWraper(const SceneRpcConnectGameServerAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcConnectGameServerAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcConnectGameServerAsk ToPB() const
	{
		SceneRpcConnectGameServerAsk v;
		v.set_roleid( m_RoleId );
		v.set_key( m_Key );

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
		SceneRpcConnectGameServerAsk pb;
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
	void Init(const SceneRpcConnectGameServerAsk& v)
	{
		m_RoleId = v.roleid();
		m_Key = v.key();

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
	//key
	string m_Key;
public:
	void SetKey( const string& v)
	{
		m_Key=v;
	}
	string GetKey()
	{
		return m_Key;
	}
	string GetKey() const
	{
		return m_Key;
	}

};
//进入场景回应封装类
class SceneRpcEnterSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcEnterSceneReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleInfo = CharacterInfoWraper();

	}
	//赋值构造函数
	SceneRpcEnterSceneReplyWraper(const SceneRpcEnterSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcEnterSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcEnterSceneReply ToPB() const
	{
		SceneRpcEnterSceneReply v;
		v.set_result( m_Result );
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();

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
		SceneRpcEnterSceneReply pb;
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
	void Init(const SceneRpcEnterSceneReply& v)
	{
		m_Result = v.result();
		m_RoleInfo = v.roleinfo();

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
	//人物信息
	CharacterInfoWraper m_RoleInfo;
public:
	void SetRoleInfo( const CharacterInfoWraper& v)
	{
		m_RoleInfo=v;
	}
	CharacterInfoWraper GetRoleInfo()
	{
		return m_RoleInfo;
	}
	CharacterInfoWraper GetRoleInfo() const
	{
		return m_RoleInfo;
	}

};
//进入场景请求封装类
class SceneRpcEnterSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcEnterSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;

	}
	//赋值构造函数
	SceneRpcEnterSceneAskWraper(const SceneRpcEnterSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcEnterSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcEnterSceneAsk ToPB() const
	{
		SceneRpcEnterSceneAsk v;
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
		SceneRpcEnterSceneAsk pb;
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
	void Init(const SceneRpcEnterSceneAsk& v)
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
//进入场景完成回应封装类
class SceneRpcLoadSceneCompleteReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcLoadSceneCompleteReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SceneRpcLoadSceneCompleteReplyWraper(const SceneRpcLoadSceneCompleteReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcLoadSceneCompleteReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcLoadSceneCompleteReply ToPB() const
	{
		SceneRpcLoadSceneCompleteReply v;
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
		SceneRpcLoadSceneCompleteReply pb;
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
	void Init(const SceneRpcLoadSceneCompleteReply& v)
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
//进入场景完成请求封装类
class SceneRpcLoadSceneCompleteAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcLoadSceneCompleteAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;

	}
	//赋值构造函数
	SceneRpcLoadSceneCompleteAskWraper(const SceneRpcLoadSceneCompleteAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcLoadSceneCompleteAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcLoadSceneCompleteAsk ToPB() const
	{
		SceneRpcLoadSceneCompleteAsk v;
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
		SceneRpcLoadSceneCompleteAsk pb;
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
	void Init(const SceneRpcLoadSceneCompleteAsk& v)
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SceneRpcNewPlayerNotifyWraper>{ enum{ID=RPC_CODE_SCENE_NEWPLAYER_NOTIFY};};
template<> struct MessageIdT<SceneRpcDeletePlayerNotifyWraper>{ enum{ID=RPC_CODE_SCENE_DELETEPLAYER_NOTIFY};};


#endif
