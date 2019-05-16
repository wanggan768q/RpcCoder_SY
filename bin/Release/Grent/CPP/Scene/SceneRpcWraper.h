/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperScene.h
* Author:       甘业清
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
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 351,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 352,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 353,	//场景模块-->连接场景服务器-->请求
	RPC_CODE_SCENE_CREATEOBJ_NOTIFY              = 354,	//场景模块-->创建物体-->通知
	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST      = 355,	//场景模块-->SurroundingHuman-->请求
	RPC_CODE_SCENE_CENTERSCENE_NOTIFY            = 356,	//场景模块-->进入场景-->通知
	RPC_CODE_SCENE_SENTERSCENE_NOTIFY            = 357,	//场景模块-->进入场景返回-->通知
	RPC_CODE_SCENE_OBJDIE_NOTIFY                 = 358,	//场景模块-->ObjDie-->通知
	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST   = 359,	//场景模块-->collide 场景切换-->请求
	RPC_CODE_SCENE_ENTERMIRROR_REQUEST           = 360,	//场景模块-->进入镜像-->请求
	RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY      = 361,	//场景模块-->进入镜像场景-->通知
	RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST       = 362,	//场景模块-->退出镜像-->请求
	RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY       = 363,	//场景模块-->ChangeSceneLeave-->通知
	RPC_CODE_SCENE_CHANGELINE_REQUEST            = 364,	//场景模块-->ChangeLine-->请求
	RPC_CODE_SCENE_PING_REQUEST                  = 365,	//场景模块-->ping-->请求
	RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY     = 366,	//场景模块-->同步场景分线繁忙状态-->通知
	RPC_CODE_SCENE_LOGOUTGAME_REQUEST            = 367,	//场景模块-->离开GameServer-->请求
	RPC_CODE_SCENE_KICKOUTGAME_NOTIFY            = 368,	//场景模块-->被提出场景-->通知
	RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST        = 369,	//场景模块-->前端通知后端剧情动画播放完毕-->请求
	RPC_CODE_SCENE_SPECOBJPOS_REQUEST            = 370,	//场景模块-->SpecObjPos-->请求


};


//ChangeLine回应封装类
class SceneRpcChangeLineReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcChangeLineReplyWraper()
	{
		
		m_Result = -1;
		m_LineID = -1;
		m_MapID = -1;
		m_RoleID = 0;

	}
	//赋值构造函数
	SceneRpcChangeLineReplyWraper(const SceneRpcChangeLineReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcChangeLineReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcChangeLineReply ToPB() const
	{
		SceneRpcChangeLineReply v;
		v.set_result( m_Result );
		v.set_lineid( m_LineID );
		v.set_mapid( m_MapID );
		v.set_roleid( m_RoleID );

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
		SceneRpcChangeLineReply pb;
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
	void Init(const SceneRpcChangeLineReply& v)
	{
		m_Result = v.result();
		m_LineID = v.lineid();
		m_MapID = v.mapid();
		m_RoleID = v.roleid();

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
	//LineID
	INT32 m_LineID;
public:
	void SetLineID( INT32 v)
	{
		m_LineID=v;
	}
	INT32 GetLineID()
	{
		return m_LineID;
	}
	INT32 GetLineID() const
	{
		return m_LineID;
	}
private:
	//MapID
	INT32 m_MapID;
public:
	void SetMapID( INT32 v)
	{
		m_MapID=v;
	}
	INT32 GetMapID()
	{
		return m_MapID;
	}
	INT32 GetMapID() const
	{
		return m_MapID;
	}
private:
	//RoleID
	uint64_t m_RoleID;
public:
	void SetRoleID( uint64_t v)
	{
		m_RoleID=v;
	}
	uint64_t GetRoleID()
	{
		return m_RoleID;
	}
	uint64_t GetRoleID() const
	{
		return m_RoleID;
	}

};
//ping请求封装类
class SceneRpcPingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcPingAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcPingAskWraper(const SceneRpcPingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcPingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcPingAsk ToPB() const
	{
		SceneRpcPingAsk v;

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
		SceneRpcPingAsk pb;
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
	void Init(const SceneRpcPingAsk& v)
	{

	}


};
//ping回应封装类
class SceneRpcPingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcPingReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcPingReplyWraper(const SceneRpcPingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcPingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcPingReply ToPB() const
	{
		SceneRpcPingReply v;
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
		SceneRpcPingReply pb;
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
	void Init(const SceneRpcPingReply& v)
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
//ChangeLine请求封装类
class SceneRpcChangeLineAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcChangeLineAskWraper()
	{
		
		m_LineID = -1;
		m_MapID = -1;

	}
	//赋值构造函数
	SceneRpcChangeLineAskWraper(const SceneRpcChangeLineAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcChangeLineAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcChangeLineAsk ToPB() const
	{
		SceneRpcChangeLineAsk v;
		v.set_lineid( m_LineID );
		v.set_mapid( m_MapID );

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
		SceneRpcChangeLineAsk pb;
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
	void Init(const SceneRpcChangeLineAsk& v)
	{
		m_LineID = v.lineid();
		m_MapID = v.mapid();

	}

private:
	//LineID
	INT32 m_LineID;
public:
	void SetLineID( INT32 v)
	{
		m_LineID=v;
	}
	INT32 GetLineID()
	{
		return m_LineID;
	}
	INT32 GetLineID() const
	{
		return m_LineID;
	}
private:
	//MapID
	INT32 m_MapID;
public:
	void SetMapID( INT32 v)
	{
		m_MapID=v;
	}
	INT32 GetMapID()
	{
		return m_MapID;
	}
	INT32 GetMapID() const
	{
		return m_MapID;
	}

};
//退出镜像请求封装类
class SceneRpcExitMirrorSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcExitMirrorSceneAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcExitMirrorSceneAskWraper(const SceneRpcExitMirrorSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcExitMirrorSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcExitMirrorSceneAsk ToPB() const
	{
		SceneRpcExitMirrorSceneAsk v;

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
		SceneRpcExitMirrorSceneAsk pb;
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
	void Init(const SceneRpcExitMirrorSceneAsk& v)
	{

	}


};
//退出镜像回应封装类
class SceneRpcExitMirrorSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcExitMirrorSceneReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcExitMirrorSceneReplyWraper(const SceneRpcExitMirrorSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcExitMirrorSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcExitMirrorSceneReply ToPB() const
	{
		SceneRpcExitMirrorSceneReply v;
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
		SceneRpcExitMirrorSceneReply pb;
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
	void Init(const SceneRpcExitMirrorSceneReply& v)
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
//ChangeSceneLeave通知封装类
class SceneRpcChangeSceneLeaveNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcChangeSceneLeaveNotifyWraper()
	{
		
		m_TargetLineID = -1;
		m_TargetMapID = -1;
		m_RoleID = 0;
		m_CopyID = -1;

	}
	//赋值构造函数
	SceneRpcChangeSceneLeaveNotifyWraper(const SceneRpcChangeSceneLeaveNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcChangeSceneLeaveNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcChangeSceneLeaveNotify ToPB() const
	{
		SceneRpcChangeSceneLeaveNotify v;
		v.set_targetlineid( m_TargetLineID );
		v.set_targetmapid( m_TargetMapID );
		v.set_roleid( m_RoleID );
		v.set_copyid( m_CopyID );

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
		SceneRpcChangeSceneLeaveNotify pb;
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
	void Init(const SceneRpcChangeSceneLeaveNotify& v)
	{
		m_TargetLineID = v.targetlineid();
		m_TargetMapID = v.targetmapid();
		m_RoleID = v.roleid();
		m_CopyID = v.copyid();

	}

private:
	//TargetLineID
	INT32 m_TargetLineID;
public:
	void SetTargetLineID( INT32 v)
	{
		m_TargetLineID=v;
	}
	INT32 GetTargetLineID()
	{
		return m_TargetLineID;
	}
	INT32 GetTargetLineID() const
	{
		return m_TargetLineID;
	}
private:
	//TargetMapID
	INT32 m_TargetMapID;
public:
	void SetTargetMapID( INT32 v)
	{
		m_TargetMapID=v;
	}
	INT32 GetTargetMapID()
	{
		return m_TargetMapID;
	}
	INT32 GetTargetMapID() const
	{
		return m_TargetMapID;
	}
private:
	//RoleID
	uint64_t m_RoleID;
public:
	void SetRoleID( uint64_t v)
	{
		m_RoleID=v;
	}
	uint64_t GetRoleID()
	{
		return m_RoleID;
	}
	uint64_t GetRoleID() const
	{
		return m_RoleID;
	}
private:
	//CopyID
	INT32 m_CopyID;
public:
	void SetCopyID( INT32 v)
	{
		m_CopyID=v;
	}
	INT32 GetCopyID()
	{
		return m_CopyID;
	}
	INT32 GetCopyID() const
	{
		return m_CopyID;
	}

};
//同步场景分线繁忙状态通知封装类
class SceneRpcSyncSceneLineStatsNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSyncSceneLineStatsNotifyWraper()
	{
		
		m_Scene_stats = SceneStatsWraper();
		m_Player_lineId = -1;

	}
	//赋值构造函数
	SceneRpcSyncSceneLineStatsNotifyWraper(const SceneRpcSyncSceneLineStatsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSyncSceneLineStatsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSyncSceneLineStatsNotify ToPB() const
	{
		SceneRpcSyncSceneLineStatsNotify v;
		*v.mutable_scene_stats()= m_Scene_stats.ToPB();
		v.set_player_lineid( m_Player_lineId );

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
		SceneRpcSyncSceneLineStatsNotify pb;
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
	void Init(const SceneRpcSyncSceneLineStatsNotify& v)
	{
		m_Scene_stats = v.scene_stats();
		m_Player_lineId = v.player_lineid();

	}

private:
	//场景状态
	SceneStatsWraper m_Scene_stats;
public:
	void SetScene_stats( const SceneStatsWraper& v)
	{
		m_Scene_stats=v;
	}
	SceneStatsWraper GetScene_stats()
	{
		return m_Scene_stats;
	}
	SceneStatsWraper GetScene_stats() const
	{
		return m_Scene_stats;
	}
private:
	//玩家所在线Id
	INT32 m_Player_lineId;
public:
	void SetPlayer_lineId( INT32 v)
	{
		m_Player_lineId=v;
	}
	INT32 GetPlayer_lineId()
	{
		return m_Player_lineId;
	}
	INT32 GetPlayer_lineId() const
	{
		return m_Player_lineId;
	}

};
//前端通知后端剧情动画播放完毕回应封装类
class SceneRpcShowFilmFinishReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcShowFilmFinishReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcShowFilmFinishReplyWraper(const SceneRpcShowFilmFinishReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcShowFilmFinishReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcShowFilmFinishReply ToPB() const
	{
		SceneRpcShowFilmFinishReply v;
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
		SceneRpcShowFilmFinishReply pb;
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
	void Init(const SceneRpcShowFilmFinishReply& v)
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
//SpecObjPos请求封装类
class SceneRpcSpecObjPosAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSpecObjPosAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcSpecObjPosAskWraper(const SceneRpcSpecObjPosAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSpecObjPosAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSpecObjPosAsk ToPB() const
	{
		SceneRpcSpecObjPosAsk v;

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
		SceneRpcSpecObjPosAsk pb;
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
	void Init(const SceneRpcSpecObjPosAsk& v)
	{

	}


};
//SpecObjPos回应封装类
class SceneRpcSpecObjPosReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSpecObjPosReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcSpecObjPosReplyWraper(const SceneRpcSpecObjPosReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSpecObjPosReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSpecObjPosReply ToPB() const
	{
		SceneRpcSpecObjPosReply v;
		v.set_result( m_Result );
		v.mutable_posinfos()->Reserve(m_PosInfos.size());
		for (int i=0; i<(int)m_PosInfos.size(); i++)
		{
			*v.add_posinfos() = m_PosInfos[i].ToPB();
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
		SceneRpcSpecObjPosReply pb;
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
	void Init(const SceneRpcSpecObjPosReply& v)
	{
		m_Result = v.result();
		m_PosInfos.clear();
		m_PosInfos.reserve(v.posinfos_size());
		for( int i=0; i<v.posinfos_size(); i++)
			m_PosInfos.push_back(v.posinfos(i));

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
	//PosInfs
	vector<ObjPosInfoWraper> m_PosInfos;
public:
	int SizePosInfos()
	{
		return m_PosInfos.size();
	}
	const vector<ObjPosInfoWraper>& GetPosInfos() const
	{
		return m_PosInfos;
	}
	ObjPosInfoWraper GetPosInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_PosInfos.size())
		{
			assert(false);
			return ObjPosInfoWraper();
		}
		return m_PosInfos[Index];
	}
	void SetPosInfos( const vector<ObjPosInfoWraper>& v )
	{
		m_PosInfos=v;
	}
	void ClearPosInfos( )
	{
		m_PosInfos.clear();
	}
	void SetPosInfos( int Index, const ObjPosInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PosInfos.size())
		{
			assert(false);
			return;
		}
		m_PosInfos[Index] = v;
	}
	void AddPosInfos( const ObjPosInfoWraper& v )
	{
		m_PosInfos.push_back(v);
	}

};
//前端通知后端剧情动画播放完毕请求封装类
class SceneRpcShowFilmFinishAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcShowFilmFinishAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcShowFilmFinishAskWraper(const SceneRpcShowFilmFinishAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcShowFilmFinishAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcShowFilmFinishAsk ToPB() const
	{
		SceneRpcShowFilmFinishAsk v;

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
		SceneRpcShowFilmFinishAsk pb;
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
	void Init(const SceneRpcShowFilmFinishAsk& v)
	{

	}


};
//离开GameServer请求封装类
class SceneRpcLogOutGameAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcLogOutGameAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcLogOutGameAskWraper(const SceneRpcLogOutGameAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcLogOutGameAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcLogOutGameAsk ToPB() const
	{
		SceneRpcLogOutGameAsk v;

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
		SceneRpcLogOutGameAsk pb;
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
	void Init(const SceneRpcLogOutGameAsk& v)
	{

	}


};
//离开GameServer回应封装类
class SceneRpcLogOutGameReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcLogOutGameReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcLogOutGameReplyWraper(const SceneRpcLogOutGameReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcLogOutGameReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcLogOutGameReply ToPB() const
	{
		SceneRpcLogOutGameReply v;
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
		SceneRpcLogOutGameReply pb;
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
	void Init(const SceneRpcLogOutGameReply& v)
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
//被提出场景通知封装类
class SceneRpcKickOutGameNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcKickOutGameNotifyWraper()
	{
		
		m_Kick_reason = "";
		m_Reason_id = -1;

	}
	//赋值构造函数
	SceneRpcKickOutGameNotifyWraper(const SceneRpcKickOutGameNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcKickOutGameNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcKickOutGameNotify ToPB() const
	{
		SceneRpcKickOutGameNotify v;
		v.set_kick_reason( m_Kick_reason );
		v.set_reason_id( m_Reason_id );

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
		SceneRpcKickOutGameNotify pb;
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
	void Init(const SceneRpcKickOutGameNotify& v)
	{
		m_Kick_reason = v.kick_reason();
		m_Reason_id = v.reason_id();

	}

private:
	//原因
	string m_Kick_reason;
public:
	void SetKick_reason( const string& v)
	{
		m_Kick_reason=v;
	}
	string GetKick_reason()
	{
		return m_Kick_reason;
	}
	string GetKick_reason() const
	{
		return m_Kick_reason;
	}
private:
	//踢人原因id
	INT32 m_Reason_id;
public:
	void SetReason_id( INT32 v)
	{
		m_Reason_id=v;
	}
	INT32 GetReason_id()
	{
		return m_Reason_id;
	}
	INT32 GetReason_id() const
	{
		return m_Reason_id;
	}

};
//进入镜像场景通知封装类
class SceneRpcSEnterMirrorSceneNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSEnterMirrorSceneNotifyWraper()
	{
		
		m_MapID = -1;
		m_MirrorID = -1;

	}
	//赋值构造函数
	SceneRpcSEnterMirrorSceneNotifyWraper(const SceneRpcSEnterMirrorSceneNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSEnterMirrorSceneNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSEnterMirrorSceneNotify ToPB() const
	{
		SceneRpcSEnterMirrorSceneNotify v;
		v.set_mapid( m_MapID );
		v.set_mirrorid( m_MirrorID );

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
		SceneRpcSEnterMirrorSceneNotify pb;
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
	void Init(const SceneRpcSEnterMirrorSceneNotify& v)
	{
		m_MapID = v.mapid();
		m_MirrorID = v.mirrorid();

	}

private:
	//地图ID
	INT32 m_MapID;
public:
	void SetMapID( INT32 v)
	{
		m_MapID=v;
	}
	INT32 GetMapID()
	{
		return m_MapID;
	}
	INT32 GetMapID() const
	{
		return m_MapID;
	}
private:
	//镜像ID
	INT32 m_MirrorID;
public:
	void SetMirrorID( INT32 v)
	{
		m_MirrorID=v;
	}
	INT32 GetMirrorID()
	{
		return m_MirrorID;
	}
	INT32 GetMirrorID() const
	{
		return m_MirrorID;
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
		m_SceneId = -1;
		m_MapId = -1;

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
		v.set_sceneid( m_SceneId );
		v.set_mapid( m_MapId );

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
		m_SceneId = v.sceneid();
		m_MapId = v.mapid();

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
private:
	//SceneId
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
private:
	//表当中的mapid
	INT32 m_MapId;
public:
	void SetMapId( INT32 v)
	{
		m_MapId=v;
	}
	INT32 GetMapId()
	{
		return m_MapId;
	}
	INT32 GetMapId() const
	{
		return m_MapId;
	}

};
//创建物体通知封装类
class SceneRpcCreateObjNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcCreateObjNotifyWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcCreateObjNotifyWraper(const SceneRpcCreateObjNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcCreateObjNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcCreateObjNotify ToPB() const
	{
		SceneRpcCreateObjNotify v;
		v.mutable_create_list()->Reserve(m_Create_list.size());
		for (int i=0; i<(int)m_Create_list.size(); i++)
		{
			*v.add_create_list() = m_Create_list[i].ToPB();
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
		SceneRpcCreateObjNotify pb;
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
	void Init(const SceneRpcCreateObjNotify& v)
	{
		m_Create_list.clear();
		m_Create_list.reserve(v.create_list_size());
		for( int i=0; i<v.create_list_size(); i++)
			m_Create_list.push_back(v.create_list(i));

	}

private:
	//创建信息列表
	vector<ObjCreateInfoWraper> m_Create_list;
public:
	int SizeCreate_list()
	{
		return m_Create_list.size();
	}
	const vector<ObjCreateInfoWraper>& GetCreate_list() const
	{
		return m_Create_list;
	}
	ObjCreateInfoWraper GetCreate_list(int Index) const
	{
		if(Index<0 || Index>=(int)m_Create_list.size())
		{
			assert(false);
			return ObjCreateInfoWraper();
		}
		return m_Create_list[Index];
	}
	void SetCreate_list( const vector<ObjCreateInfoWraper>& v )
	{
		m_Create_list=v;
	}
	void ClearCreate_list( )
	{
		m_Create_list.clear();
	}
	void SetCreate_list( int Index, const ObjCreateInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Create_list.size())
		{
			assert(false);
			return;
		}
		m_Create_list[Index] = v;
	}
	void AddCreate_list( const ObjCreateInfoWraper& v )
	{
		m_Create_list.push_back(v);
	}

};
//SurroundingHuman请求封装类
class SceneRpcSurroundingHumanAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSurroundingHumanAskWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcSurroundingHumanAskWraper(const SceneRpcSurroundingHumanAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSurroundingHumanAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSurroundingHumanAsk ToPB() const
	{
		SceneRpcSurroundingHumanAsk v;

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
		SceneRpcSurroundingHumanAsk pb;
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
	void Init(const SceneRpcSurroundingHumanAsk& v)
	{

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
		m_SceneID = -1;
		m_LineID = -1;

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
		v.set_sceneid( m_SceneID );
		v.set_lineid( m_LineID );

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
		m_SceneID = v.sceneid();
		m_LineID = v.lineid();

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
private:
	//SceneID
	INT32 m_SceneID;
public:
	void SetSceneID( INT32 v)
	{
		m_SceneID=v;
	}
	INT32 GetSceneID()
	{
		return m_SceneID;
	}
	INT32 GetSceneID() const
	{
		return m_SceneID;
	}
private:
	//LineID
	INT32 m_LineID;
public:
	void SetLineID( INT32 v)
	{
		m_LineID=v;
	}
	INT32 GetLineID()
	{
		return m_LineID;
	}
	INT32 GetLineID() const
	{
		return m_LineID;
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
//进入场景完成回应封装类
class SceneRpcLoadSceneCompleteReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcLoadSceneCompleteReplyWraper()
	{
		
		m_Result = -9999;
		m_ObjId = -1;
		m_Pos = Vector3Wraper();
		m_Dir = -1;
		m_ObjData = "";

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
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );
		v.set_objdata( m_ObjData );

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
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();
		m_ObjData = v.objdata();

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
	//玩家objid
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
	Vector3Wraper m_Pos;
public:
	void SetPos( const Vector3Wraper& v)
	{
		m_Pos=v;
	}
	Vector3Wraper GetPos()
	{
		return m_Pos;
	}
	Vector3Wraper GetPos() const
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
	//Obj 数据
	string m_ObjData;
public:
	void SetObjData( const string& v)
	{
		m_ObjData=v;
	}
	string GetObjData()
	{
		return m_ObjData;
	}
	string GetObjData() const
	{
		return m_ObjData;
	}

};
//删除玩家通知封装类
class SceneRpcDeletePlayerNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcDeletePlayerNotifyWraper()
	{
		

	}
	//赋值构造函数
	SceneRpcDeletePlayerNotifyWraper(const SceneRpcDeletePlayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcDeletePlayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcDeletePlayerNotify ToPB() const
	{
		SceneRpcDeletePlayerNotify v;
		v.mutable_delete_list()->Reserve(m_Delete_list.size());
		for (int i=0; i<(int)m_Delete_list.size(); i++)
		{
			*v.add_delete_list() = m_Delete_list[i].ToPB();
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
		m_Delete_list.clear();
		m_Delete_list.reserve(v.delete_list_size());
		for( int i=0; i<v.delete_list_size(); i++)
			m_Delete_list.push_back(v.delete_list(i));

	}

private:
	//删除信息列表
	vector<ObjDeleteInfoWraper> m_Delete_list;
public:
	int SizeDelete_list()
	{
		return m_Delete_list.size();
	}
	const vector<ObjDeleteInfoWraper>& GetDelete_list() const
	{
		return m_Delete_list;
	}
	ObjDeleteInfoWraper GetDelete_list(int Index) const
	{
		if(Index<0 || Index>=(int)m_Delete_list.size())
		{
			assert(false);
			return ObjDeleteInfoWraper();
		}
		return m_Delete_list[Index];
	}
	void SetDelete_list( const vector<ObjDeleteInfoWraper>& v )
	{
		m_Delete_list=v;
	}
	void ClearDelete_list( )
	{
		m_Delete_list.clear();
	}
	void SetDelete_list( int Index, const ObjDeleteInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Delete_list.size())
		{
			assert(false);
			return;
		}
		m_Delete_list[Index] = v;
	}
	void AddDelete_list( const ObjDeleteInfoWraper& v )
	{
		m_Delete_list.push_back(v);
	}

};
//SurroundingHuman回应封装类
class SceneRpcSurroundingHumanReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSurroundingHumanReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SceneRpcSurroundingHumanReplyWraper(const SceneRpcSurroundingHumanReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSurroundingHumanReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSurroundingHumanReply ToPB() const
	{
		SceneRpcSurroundingHumanReply v;
		v.set_result( m_Result );
		v.mutable_rolelist()->Reserve(m_RoleList.size());
		for (int i=0; i<(int)m_RoleList.size(); i++)
		{
			*v.add_rolelist() = m_RoleList[i].ToPB();
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
		SceneRpcSurroundingHumanReply pb;
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
	void Init(const SceneRpcSurroundingHumanReply& v)
	{
		m_Result = v.result();
		m_RoleList.clear();
		m_RoleList.reserve(v.rolelist_size());
		for( int i=0; i<v.rolelist_size(); i++)
			m_RoleList.push_back(v.rolelist(i));

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
	//RoleList
	vector<CharacterInfoWraper> m_RoleList;
public:
	int SizeRoleList()
	{
		return m_RoleList.size();
	}
	const vector<CharacterInfoWraper>& GetRoleList() const
	{
		return m_RoleList;
	}
	CharacterInfoWraper GetRoleList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleList.size())
		{
			assert(false);
			return CharacterInfoWraper();
		}
		return m_RoleList[Index];
	}
	void SetRoleList( const vector<CharacterInfoWraper>& v )
	{
		m_RoleList=v;
	}
	void ClearRoleList( )
	{
		m_RoleList.clear();
	}
	void SetRoleList( int Index, const CharacterInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RoleList.size())
		{
			assert(false);
			return;
		}
		m_RoleList[Index] = v;
	}
	void AddRoleList( const CharacterInfoWraper& v )
	{
		m_RoleList.push_back(v);
	}

};
//collide回应封装类
class SceneRpcCollide_ChangeSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcCollide_ChangeSceneReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	SceneRpcCollide_ChangeSceneReplyWraper(const SceneRpcCollide_ChangeSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcCollide_ChangeSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcCollide_ChangeSceneReply ToPB() const
	{
		SceneRpcCollide_ChangeSceneReply v;
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
		SceneRpcCollide_ChangeSceneReply pb;
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
	void Init(const SceneRpcCollide_ChangeSceneReply& v)
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
//进入镜像请求封装类
class SceneRpcEnterMirrorAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcEnterMirrorAskWraper()
	{
		
		m_MirrorID = -1;

	}
	//赋值构造函数
	SceneRpcEnterMirrorAskWraper(const SceneRpcEnterMirrorAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcEnterMirrorAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcEnterMirrorAsk ToPB() const
	{
		SceneRpcEnterMirrorAsk v;
		v.set_mirrorid( m_MirrorID );

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
		SceneRpcEnterMirrorAsk pb;
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
	void Init(const SceneRpcEnterMirrorAsk& v)
	{
		m_MirrorID = v.mirrorid();

	}

private:
	//镜像ID
	INT32 m_MirrorID;
public:
	void SetMirrorID( INT32 v)
	{
		m_MirrorID=v;
	}
	INT32 GetMirrorID()
	{
		return m_MirrorID;
	}
	INT32 GetMirrorID() const
	{
		return m_MirrorID;
	}

};
//进入镜像回应封装类
class SceneRpcEnterMirrorReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcEnterMirrorReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SceneRpcEnterMirrorReplyWraper(const SceneRpcEnterMirrorReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcEnterMirrorReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcEnterMirrorReply ToPB() const
	{
		SceneRpcEnterMirrorReply v;
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
		SceneRpcEnterMirrorReply pb;
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
	void Init(const SceneRpcEnterMirrorReply& v)
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
//collide请求封装类
class SceneRpcCollide_ChangeSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcCollide_ChangeSceneAskWraper()
	{
		
		m_Collide_id = -1;

	}
	//赋值构造函数
	SceneRpcCollide_ChangeSceneAskWraper(const SceneRpcCollide_ChangeSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcCollide_ChangeSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcCollide_ChangeSceneAsk ToPB() const
	{
		SceneRpcCollide_ChangeSceneAsk v;
		v.set_collide_id( m_Collide_id );

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
		SceneRpcCollide_ChangeSceneAsk pb;
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
	void Init(const SceneRpcCollide_ChangeSceneAsk& v)
	{
		m_Collide_id = v.collide_id();

	}

private:
	//碰撞点的ID
	INT32 m_Collide_id;
public:
	void SetCollide_id( INT32 v)
	{
		m_Collide_id=v;
	}
	INT32 GetCollide_id()
	{
		return m_Collide_id;
	}
	INT32 GetCollide_id() const
	{
		return m_Collide_id;
	}

};
//进入场景通知封装类
class SceneRpcCEnterSceneNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcCEnterSceneNotifyWraper()
	{
		
		m_SceneId = -1;
		m_MapId = -1;
		m_LineId = -1;

	}
	//赋值构造函数
	SceneRpcCEnterSceneNotifyWraper(const SceneRpcCEnterSceneNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcCEnterSceneNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcCEnterSceneNotify ToPB() const
	{
		SceneRpcCEnterSceneNotify v;
		v.set_sceneid( m_SceneId );
		v.set_mapid( m_MapId );
		v.set_lineid( m_LineId );

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
		SceneRpcCEnterSceneNotify pb;
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
	void Init(const SceneRpcCEnterSceneNotify& v)
	{
		m_SceneId = v.sceneid();
		m_MapId = v.mapid();
		m_LineId = v.lineid();

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
private:
	//表当中的mapid
	INT32 m_MapId;
public:
	void SetMapId( INT32 v)
	{
		m_MapId=v;
	}
	INT32 GetMapId()
	{
		return m_MapId;
	}
	INT32 GetMapId() const
	{
		return m_MapId;
	}
private:
	//LineId
	INT32 m_LineId;
public:
	void SetLineId( INT32 v)
	{
		m_LineId=v;
	}
	INT32 GetLineId()
	{
		return m_LineId;
	}
	INT32 GetLineId() const
	{
		return m_LineId;
	}

};
//进入场景返回通知封装类
class SceneRpcSEnterSceneNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcSEnterSceneNotifyWraper()
	{
		
		m_Result = -9999;
		m_SceneId = -1;
		m_SceneConfigId = -1;
		m_MapId = -1;
		m_RoleId = 0;
		m_DungeonConfigId = -1;
		m_LineId = -1;

	}
	//赋值构造函数
	SceneRpcSEnterSceneNotifyWraper(const SceneRpcSEnterSceneNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcSEnterSceneNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcSEnterSceneNotify ToPB() const
	{
		SceneRpcSEnterSceneNotify v;
		v.set_result( m_Result );
		v.set_sceneid( m_SceneId );
		v.set_sceneconfigid( m_SceneConfigId );
		v.set_mapid( m_MapId );
		v.set_roleid( m_RoleId );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_lineid( m_LineId );
		v.mutable_typeconfig()->Reserve(m_TypeConfig.size());
		for (int i=0; i<(int)m_TypeConfig.size(); i++)
		{
			*v.add_typeconfig() = m_TypeConfig[i].ToPB();
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
		SceneRpcSEnterSceneNotify pb;
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
	void Init(const SceneRpcSEnterSceneNotify& v)
	{
		m_Result = v.result();
		m_SceneId = v.sceneid();
		m_SceneConfigId = v.sceneconfigid();
		m_MapId = v.mapid();
		m_RoleId = v.roleid();
		m_DungeonConfigId = v.dungeonconfigid();
		m_LineId = v.lineid();
		m_TypeConfig.clear();
		m_TypeConfig.reserve(v.typeconfig_size());
		for( int i=0; i<v.typeconfig_size(); i++)
			m_TypeConfig.push_back(v.typeconfig(i));

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
	//当返回不能进入，用这个来重新进入
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
private:
	//SceneConfigId
	INT32 m_SceneConfigId;
public:
	void SetSceneConfigId( INT32 v)
	{
		m_SceneConfigId=v;
	}
	INT32 GetSceneConfigId()
	{
		return m_SceneConfigId;
	}
	INT32 GetSceneConfigId() const
	{
		return m_SceneConfigId;
	}
private:
	//表当中的mapid
	INT32 m_MapId;
public:
	void SetMapId( INT32 v)
	{
		m_MapId=v;
	}
	INT32 GetMapId()
	{
		return m_MapId;
	}
	INT32 GetMapId() const
	{
		return m_MapId;
	}
private:
	//roleID
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
	//DungeonConfigId
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
private:
	//LineId
	INT32 m_LineId;
public:
	void SetLineId( INT32 v)
	{
		m_LineId=v;
	}
	INT32 GetLineId()
	{
		return m_LineId;
	}
	INT32 GetLineId() const
	{
		return m_LineId;
	}
private:
	//key是场景类型，value配置表
	vector<IntPairWraper> m_TypeConfig;
public:
	int SizeTypeConfig()
	{
		return m_TypeConfig.size();
	}
	const vector<IntPairWraper>& GetTypeConfig() const
	{
		return m_TypeConfig;
	}
	IntPairWraper GetTypeConfig(int Index) const
	{
		if(Index<0 || Index>=(int)m_TypeConfig.size())
		{
			assert(false);
			return IntPairWraper();
		}
		return m_TypeConfig[Index];
	}
	void SetTypeConfig( const vector<IntPairWraper>& v )
	{
		m_TypeConfig=v;
	}
	void ClearTypeConfig( )
	{
		m_TypeConfig.clear();
	}
	void SetTypeConfig( int Index, const IntPairWraper& v )
	{
		if(Index<0 || Index>=(int)m_TypeConfig.size())
		{
			assert(false);
			return;
		}
		m_TypeConfig[Index] = v;
	}
	void AddTypeConfig( const IntPairWraper& v )
	{
		m_TypeConfig.push_back(v);
	}

};
//ObjDie通知封装类
class SceneRpcObjDieNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SceneRpcObjDieNotifyWraper()
	{
		
		m_ObjId = -1;
		m_RespawnTime = -1;
		m_ConfigId = -1;
		m_ObjType = -1;

	}
	//赋值构造函数
	SceneRpcObjDieNotifyWraper(const SceneRpcObjDieNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcObjDieNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcObjDieNotify ToPB() const
	{
		SceneRpcObjDieNotify v;
		v.set_objid( m_ObjId );
		v.set_respawntime( m_RespawnTime );
		v.set_configid( m_ConfigId );
		v.set_objtype( m_ObjType );

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
		SceneRpcObjDieNotify pb;
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
	void Init(const SceneRpcObjDieNotify& v)
	{
		m_ObjId = v.objid();
		m_RespawnTime = v.respawntime();
		m_ConfigId = v.configid();
		m_ObjType = v.objtype();

	}

private:
	//ObjId
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
	//Respawn
	INT32 m_RespawnTime;
public:
	void SetRespawnTime( INT32 v)
	{
		m_RespawnTime=v;
	}
	INT32 GetRespawnTime()
	{
		return m_RespawnTime;
	}
	INT32 GetRespawnTime() const
	{
		return m_RespawnTime;
	}
private:
	//ConfigId
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
	//ObjType
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SceneRpcDeletePlayerNotifyWraper>{ enum{ID=RPC_CODE_SCENE_DELETEPLAYER_NOTIFY};};
template<> struct MessageIdT<SceneRpcCreateObjNotifyWraper>{ enum{ID=RPC_CODE_SCENE_CREATEOBJ_NOTIFY};};
template<> struct MessageIdT<SceneRpcCEnterSceneNotifyWraper>{ enum{ID=RPC_CODE_SCENE_CENTERSCENE_NOTIFY};};
template<> struct MessageIdT<SceneRpcSEnterSceneNotifyWraper>{ enum{ID=RPC_CODE_SCENE_SENTERSCENE_NOTIFY};};
template<> struct MessageIdT<SceneRpcObjDieNotifyWraper>{ enum{ID=RPC_CODE_SCENE_OBJDIE_NOTIFY};};
template<> struct MessageIdT<SceneRpcSEnterMirrorSceneNotifyWraper>{ enum{ID=RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY};};
template<> struct MessageIdT<SceneRpcChangeSceneLeaveNotifyWraper>{ enum{ID=RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY};};
template<> struct MessageIdT<SceneRpcSyncSceneLineStatsNotifyWraper>{ enum{ID=RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY};};
template<> struct MessageIdT<SceneRpcKickOutGameNotifyWraper>{ enum{ID=RPC_CODE_SCENE_KICKOUTGAME_NOTIFY};};


#endif
