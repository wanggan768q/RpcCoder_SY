/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperPetCapture.h
* Author:       甘业清
* Description:  宠物捕获RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_PETCAPTURE_H
#define __RPC_WRAPER_PETCAPTURE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "PetCaptureRpc.pb.h"



//宠物捕获类的枚举定义
enum ConstPetCaptureE
{
	MODULE_ID_PETCAPTURE                         = 44,	//宠物捕获模块ID
	RPC_CODE_PETCAPTURE_CAPTURE_REQUEST          = 4451,	//宠物捕获-->宠物捕获-->请求
	RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY        = 4452,	//宠物捕获-->捕获到宠物广播-->通知
	RPC_CODE_PETCAPTURE_LOGIN_NOTIFY             = 4453,	//宠物捕获-->宠物捕获登录-->通知
	RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST      = 4454,	//宠物捕获-->宠物npc位置-->请求


};


//宠物捕获登录通知封装类
class PetCaptureRpcLoginNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcLoginNotifyWraper()
	{
		
		m_WayPoint = -1;
		m_SceneId = -1;
		m_Pos = Vector3Wraper();

	}
	//赋值构造函数
	PetCaptureRpcLoginNotifyWraper(const PetCaptureRpcLoginNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcLoginNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcLoginNotify ToPB() const
	{
		PetCaptureRpcLoginNotify v;
		v.set_waypoint( m_WayPoint );
		v.set_sceneid( m_SceneId );
		*v.mutable_pos()= m_Pos.ToPB();

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
		PetCaptureRpcLoginNotify pb;
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
	void Init(const PetCaptureRpcLoginNotify& v)
	{
		m_WayPoint = v.waypoint();
		m_SceneId = v.sceneid();
		m_Pos = v.pos();

	}

private:
	//宠物捕获npc刷新路点
	INT32 m_WayPoint;
public:
	void SetWayPoint( INT32 v)
	{
		m_WayPoint=v;
	}
	INT32 GetWayPoint()
	{
		return m_WayPoint;
	}
	INT32 GetWayPoint() const
	{
		return m_WayPoint;
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
	//npc位置
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

};
//宠物npc位置请求封装类
class PetCaptureRpcPetLocationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcPetLocationAskWraper()
	{
		
		m_LineId = -1;

	}
	//赋值构造函数
	PetCaptureRpcPetLocationAskWraper(const PetCaptureRpcPetLocationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcPetLocationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcPetLocationAsk ToPB() const
	{
		PetCaptureRpcPetLocationAsk v;
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
		PetCaptureRpcPetLocationAsk pb;
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
	void Init(const PetCaptureRpcPetLocationAsk& v)
	{
		m_LineId = v.lineid();

	}

private:
	//分线id
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
//宠物npc位置回应封装类
class PetCaptureRpcPetLocationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcPetLocationReplyWraper()
	{
		
		m_Result = -1;
		m_Pos = Vector3Wraper();
		m_SceneId = -1;
		m_WayPoint = -1;

	}
	//赋值构造函数
	PetCaptureRpcPetLocationReplyWraper(const PetCaptureRpcPetLocationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcPetLocationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcPetLocationReply ToPB() const
	{
		PetCaptureRpcPetLocationReply v;
		v.set_result( m_Result );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_sceneid( m_SceneId );
		v.set_waypoint( m_WayPoint );

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
		PetCaptureRpcPetLocationReply pb;
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
	void Init(const PetCaptureRpcPetLocationReply& v)
	{
		m_Result = v.result();
		m_Pos = v.pos();
		m_SceneId = v.sceneid();
		m_WayPoint = v.waypoint();

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
	//坐标
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
	//路点
	INT32 m_WayPoint;
public:
	void SetWayPoint( INT32 v)
	{
		m_WayPoint=v;
	}
	INT32 GetWayPoint()
	{
		return m_WayPoint;
	}
	INT32 GetWayPoint() const
	{
		return m_WayPoint;
	}

};
//宠物捕获请求封装类
class PetCaptureRpcCaptureAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcCaptureAskWraper()
	{
		
		m_BallType = 1;

	}
	//赋值构造函数
	PetCaptureRpcCaptureAskWraper(const PetCaptureRpcCaptureAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcCaptureAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcCaptureAsk ToPB() const
	{
		PetCaptureRpcCaptureAsk v;
		v.set_balltype( m_BallType );

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
		PetCaptureRpcCaptureAsk pb;
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
	void Init(const PetCaptureRpcCaptureAsk& v)
	{
		m_BallType = v.balltype();

	}

private:
	//精灵球道具类型
	INT32 m_BallType;
public:
	void SetBallType( INT32 v)
	{
		m_BallType=v;
	}
	INT32 GetBallType()
	{
		return m_BallType;
	}
	INT32 GetBallType() const
	{
		return m_BallType;
	}

};
//宠物捕获回应封装类
class PetCaptureRpcCaptureReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcCaptureReplyWraper()
	{
		
		m_Result = -1;
		m_CreatureId = -1;
		m_PetId = -1;

	}
	//赋值构造函数
	PetCaptureRpcCaptureReplyWraper(const PetCaptureRpcCaptureReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcCaptureReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcCaptureReply ToPB() const
	{
		PetCaptureRpcCaptureReply v;
		v.set_result( m_Result );
		v.set_creatureid( m_CreatureId );
		v.set_petid( m_PetId );

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
		PetCaptureRpcCaptureReply pb;
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
	void Init(const PetCaptureRpcCaptureReply& v)
	{
		m_Result = v.result();
		m_CreatureId = v.creatureid();
		m_PetId = v.petid();

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
	//宠物模型id
	INT32 m_CreatureId;
public:
	void SetCreatureId( INT32 v)
	{
		m_CreatureId=v;
	}
	INT32 GetCreatureId()
	{
		return m_CreatureId;
	}
	INT32 GetCreatureId() const
	{
		return m_CreatureId;
	}
private:
	//掉落宠物id
	INT32 m_PetId;
public:
	void SetPetId( INT32 v)
	{
		m_PetId=v;
	}
	INT32 GetPetId()
	{
		return m_PetId;
	}
	INT32 GetPetId() const
	{
		return m_PetId;
	}

};
//捕获到宠物广播通知封装类
class PetCaptureRpcCapturePetNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetCaptureRpcCapturePetNotifyWraper()
	{
		
		m_PetId = -1;
		m_NickName = "";
		m_RoleId = -1;
		m_CreatureId = -1;

	}
	//赋值构造函数
	PetCaptureRpcCapturePetNotifyWraper(const PetCaptureRpcCapturePetNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PetCaptureRpcCapturePetNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetCaptureRpcCapturePetNotify ToPB() const
	{
		PetCaptureRpcCapturePetNotify v;
		v.set_petid( m_PetId );
		v.set_nickname( m_NickName );
		v.set_roleid( m_RoleId );
		v.set_creatureid( m_CreatureId );

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
		PetCaptureRpcCapturePetNotify pb;
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
	void Init(const PetCaptureRpcCapturePetNotify& v)
	{
		m_PetId = v.petid();
		m_NickName = v.nickname();
		m_RoleId = v.roleid();
		m_CreatureId = v.creatureid();

	}

private:
	//捕获到宠物id
	INT32 m_PetId;
public:
	void SetPetId( INT32 v)
	{
		m_PetId=v;
	}
	INT32 GetPetId()
	{
		return m_PetId;
	}
	INT32 GetPetId() const
	{
		return m_PetId;
	}
private:
	//捕获到宠物人昵称
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
	//捕获到宠物角色id
	INT32 m_RoleId;
public:
	void SetRoleId( INT32 v)
	{
		m_RoleId=v;
	}
	INT32 GetRoleId()
	{
		return m_RoleId;
	}
	INT32 GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//宠物模型id
	INT32 m_CreatureId;
public:
	void SetCreatureId( INT32 v)
	{
		m_CreatureId=v;
	}
	INT32 GetCreatureId()
	{
		return m_CreatureId;
	}
	INT32 GetCreatureId() const
	{
		return m_CreatureId;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<PetCaptureRpcCapturePetNotifyWraper>{ enum{ID=RPC_CODE_PETCAPTURE_CAPTUREPET_NOTIFY};};
template<> struct MessageIdT<PetCaptureRpcLoginNotifyWraper>{ enum{ID=RPC_CODE_PETCAPTURE_LOGIN_NOTIFY};};


#endif
