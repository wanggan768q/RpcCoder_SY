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
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 351,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 352,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 353,	//场景模块-->连接场景服务器-->请求
	RPC_CODE_SCENE_CHANGESCENE_REQUEST           = 354,	//场景模块-->多线程移除场景上的玩家-->请求
	RPC_CODE_SCENE_CREATEOBJ_NOTIFY              = 355,	//场景模块-->创建物体-->通知
	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST      = 356,	//场景模块-->SurroundingHuman-->请求
	RPC_CODE_SCENE_CENTERSCENE_NOTIFY            = 357,	//场景模块-->进入场景-->通知
	RPC_CODE_SCENE_SENTERSCENE_NOTIFY            = 358,	//场景模块-->进入场景返回-->通知
	RPC_CODE_SCENE_OBJDIE_NOTIFY                 = 359,	//场景模块-->ObjDie-->通知
	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST   = 360,	//场景模块-->collide 场景切换-->请求


};


//进入场景通知封装类
class SceneRpcCEnterSceneNotifyWraper
{
public:
	//构造函数
	SceneRpcCEnterSceneNotifyWraper()
	{
		
		m_SceneId = -1;
		m_MapId = -1;

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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcCEnterSceneNotify& v)
	{
		m_SceneId = v.sceneid();
		m_MapId = v.mapid();

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

};
//SurroundingHuman回应封装类
class SceneRpcSurroundingHumanReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//SurroundingHuman请求封装类
class SceneRpcSurroundingHumanAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcSurroundingHumanAsk& v)
	{

	}


};
//进入场景返回通知封装类
class SceneRpcSEnterSceneNotifyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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

};
//collide回应封装类
class SceneRpcCollide_ChangeSceneReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//collide请求封装类
class SceneRpcCollide_ChangeSceneAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//ObjDie通知封装类
class SceneRpcObjDieNotifyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//创建物体通知封装类
class SceneRpcCreateObjNotifyWraper
{
public:
	//构造函数
	SceneRpcCreateObjNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_Dir = -1;
		m_ObjType = -1;
		m_ConfigId = -1;
		m_Status = -1;
		m_MoveSpeed = -1;
		m_RoleId = 0;
		m_NickName = "";
		m_Hp = -1;
		m_TargetPos = V3Wraper();
		m_HpMax = -1;

	}
	//赋值构造函数
	SceneRpcCreateObjNotifyWraper(const SceneRpcCreateObjNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcCreateObjNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcCreateObjNotify ToPB() const
	{
		SceneRpcCreateObjNotify v;
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );
		v.set_objtype( m_ObjType );
		v.set_configid( m_ConfigId );
		v.set_status( m_Status );
		v.set_movespeed( m_MoveSpeed );
		v.set_roleid( m_RoleId );
		v.set_nickname( m_NickName );
		v.set_hp( m_Hp );
		*v.mutable_targetpos()= m_TargetPos.ToPB();
		v.set_hpmax( m_HpMax );

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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcCreateObjNotify& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();
		m_ObjType = v.objtype();
		m_ConfigId = v.configid();
		m_Status = v.status();
		m_MoveSpeed = v.movespeed();
		m_RoleId = v.roleid();
		m_NickName = v.nickname();
		m_Hp = v.hp();
		m_TargetPos = v.targetpos();
		m_HpMax = v.hpmax();

	}

private:
	//id
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
	//类型
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
	//MoveSpeed
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
private:
	//玩家唯一id
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
	//名字昵称
	string m_NickName;
public:
	void SetNickName( const string& v)
	{
		m_NickName=v;
	}
	string GetNickName()
	{
		return m_NickName;
	}
	string GetNickName() const
	{
		return m_NickName;
	}
private:
	//血量
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//目标点（针对npc）
	V3Wraper m_TargetPos;
public:
	void SetTargetPos( const V3Wraper& v)
	{
		m_TargetPos=v;
	}
	V3Wraper GetTargetPos()
	{
		return m_TargetPos;
	}
	V3Wraper GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//血量上限
	INT32 m_HpMax;
public:
	void SetHpMax( INT32 v)
	{
		m_HpMax=v;
	}
	INT32 GetHpMax()
	{
		return m_HpMax;
	}
	INT32 GetHpMax() const
	{
		return m_HpMax;
	}

};
//删除玩家通知封装类
class SceneRpcDeletePlayerNotifyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//进入场景完成回应封装类
class SceneRpcLoadSceneCompleteReplyWraper
{
public:
	//构造函数
	SceneRpcLoadSceneCompleteReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleInfo = CharacterInfoWraper();
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_Dir = -1;

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
		*v.mutable_roleinfo()= m_RoleInfo.ToPB();
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );

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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcLoadSceneCompleteReply& v)
	{
		m_Result = v.result();
		m_RoleInfo = v.roleinfo();
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();

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

};
//进入场景完成请求封装类
class SceneRpcLoadSceneCompleteAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//连接场景服务器请求封装类
class SceneRpcConnectGameServerAskWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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
//多线程移除场景上的玩家回应封装类
class SceneRpcChangeSceneReplyWraper
{
public:
	//构造函数
	SceneRpcChangeSceneReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;

	}
	//赋值构造函数
	SceneRpcChangeSceneReplyWraper(const SceneRpcChangeSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcChangeSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcChangeSceneReply ToPB() const
	{
		SceneRpcChangeSceneReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );

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
		SceneRpcChangeSceneReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcChangeSceneReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();

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

};
//多线程移除场景上的玩家请求封装类
class SceneRpcChangeSceneAskWraper
{
public:
	//构造函数
	SceneRpcChangeSceneAskWraper()
	{
		
		m_RoleId = 0;
		m_CurSceneId = -1;
		m_TargetSceneId = -1;

	}
	//赋值构造函数
	SceneRpcChangeSceneAskWraper(const SceneRpcChangeSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneRpcChangeSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneRpcChangeSceneAsk ToPB() const
	{
		SceneRpcChangeSceneAsk v;
		v.set_roleid( m_RoleId );
		v.set_cursceneid( m_CurSceneId );
		v.set_targetsceneid( m_TargetSceneId );

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
		SceneRpcChangeSceneAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneRpcChangeSceneAsk& v)
	{
		m_RoleId = v.roleid();
		m_CurSceneId = v.cursceneid();
		m_TargetSceneId = v.targetsceneid();

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

};
//连接场景服务器回应封装类
class SceneRpcConnectGameServerReplyWraper
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
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SceneRpcDeletePlayerNotifyWraper>{ enum{ID=RPC_CODE_SCENE_DELETEPLAYER_NOTIFY};};
template<> struct MessageIdT<SceneRpcCreateObjNotifyWraper>{ enum{ID=RPC_CODE_SCENE_CREATEOBJ_NOTIFY};};
template<> struct MessageIdT<SceneRpcCEnterSceneNotifyWraper>{ enum{ID=RPC_CODE_SCENE_CENTERSCENE_NOTIFY};};
template<> struct MessageIdT<SceneRpcSEnterSceneNotifyWraper>{ enum{ID=RPC_CODE_SCENE_SENTERSCENE_NOTIFY};};
template<> struct MessageIdT<SceneRpcObjDieNotifyWraper>{ enum{ID=RPC_CODE_SCENE_OBJDIE_NOTIFY};};


#endif
