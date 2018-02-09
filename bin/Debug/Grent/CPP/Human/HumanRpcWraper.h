/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperHuman.h
* Author:       郭晓波
* Description:  玩家模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_HUMAN_H
#define __RPC_WRAPER_HUMAN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "HumanRpc.pb.h"



//玩家模块类的枚举定义
enum ConstHumanE
{
	MODULE_ID_HUMAN                              = 4,	//玩家模块模块ID
	RPC_CODE_HUMAN_MOVE_REQUEST                  = 451,	//玩家模块-->human move-->请求
	RPC_CODE_HUMAN_STOPMOVE_REQUEST              = 452,	//玩家模块-->客户端停止移动-->请求
	RPC_CODE_HUMAN_MOVECHECK_NOTIFY              = 453,	//玩家模块-->移动检测-->通知
	RPC_CODE_HUMAN_MOVEBYPOS_NOTIFY              = 454,	//玩家模块-->按照点来移动-->通知
	RPC_CODE_HUMAN_RESPAWN_REQUEST               = 455,	//玩家模块-->Respawn-->请求


};


//按照点来移动通知封装类
class HumanRpcMoveByPosNotifyWraper
{
public:
	//构造函数
	HumanRpcMoveByPosNotifyWraper()
	{
		
		m_ObjId = -1;
		m_TargetX = -1;
		m_TargetY = -1;

	}
	//赋值构造函数
	HumanRpcMoveByPosNotifyWraper(const HumanRpcMoveByPosNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveByPosNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveByPosNotify ToPB() const
	{
		HumanRpcMoveByPosNotify v;
		v.set_objid( m_ObjId );
		v.set_targetx( m_TargetX );
		v.set_targety( m_TargetY );

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
		HumanRpcMoveByPosNotify pb;
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
	void Init(const HumanRpcMoveByPosNotify& v)
	{
		m_ObjId = v.objid();
		m_TargetX = v.targetx();
		m_TargetY = v.targety();

	}

private:
	//目标ID
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
	//目标位置
	float m_TargetX;
public:
	void SetTargetX( float v)
	{
		m_TargetX=v;
	}
	float GetTargetX()
	{
		return m_TargetX;
	}
	float GetTargetX() const
	{
		return m_TargetX;
	}
private:
	//目标位置
	float m_TargetY;
public:
	void SetTargetY( float v)
	{
		m_TargetY=v;
	}
	float GetTargetY()
	{
		return m_TargetY;
	}
	float GetTargetY() const
	{
		return m_TargetY;
	}

};
//移动检测通知封装类
class HumanRpcMoveCheckNotifyWraper
{
public:
	//构造函数
	HumanRpcMoveCheckNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Dir = -1;
		m_X = -1;
		m_Y = -1;

	}
	//赋值构造函数
	HumanRpcMoveCheckNotifyWraper(const HumanRpcMoveCheckNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveCheckNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveCheckNotify ToPB() const
	{
		HumanRpcMoveCheckNotify v;
		v.set_objid( m_ObjId );
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_y( m_Y );

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
		HumanRpcMoveCheckNotify pb;
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
	void Init(const HumanRpcMoveCheckNotify& v)
	{
		m_ObjId = v.objid();
		m_Dir = v.dir();
		m_X = v.x();
		m_Y = v.y();

	}

private:
	//角色ID
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
	//x位置
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//y位置
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}

};
//Respawn回应封装类
class HumanRpcRespawnReplyWraper
{
public:
	//构造函数
	HumanRpcRespawnReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	HumanRpcRespawnReplyWraper(const HumanRpcRespawnReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcRespawnReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcRespawnReply ToPB() const
	{
		HumanRpcRespawnReply v;
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
		HumanRpcRespawnReply pb;
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
	void Init(const HumanRpcRespawnReply& v)
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
//Respawn请求封装类
class HumanRpcRespawnAskWraper
{
public:
	//构造函数
	HumanRpcRespawnAskWraper()
	{
		

	}
	//赋值构造函数
	HumanRpcRespawnAskWraper(const HumanRpcRespawnAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcRespawnAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcRespawnAsk ToPB() const
	{
		HumanRpcRespawnAsk v;

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
		HumanRpcRespawnAsk pb;
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
	void Init(const HumanRpcRespawnAsk& v)
	{

	}


};
//human move回应封装类
class HumanRpcMoveReplyWraper
{
public:
	//构造函数
	HumanRpcMoveReplyWraper()
	{
		
		m_Result = -9999;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	HumanRpcMoveReplyWraper(const HumanRpcMoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveReply ToPB() const
	{
		HumanRpcMoveReply v;
		v.set_result( m_Result );
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
		HumanRpcMoveReply pb;
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
	void Init(const HumanRpcMoveReply& v)
	{
		m_Result = v.result();
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
	//当前位置
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
	//移动方向
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
//human move请求封装类
class HumanRpcMoveAskWraper
{
public:
	//构造函数
	HumanRpcMoveAskWraper()
	{
		
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcMoveAskWraper(const HumanRpcMoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveAsk ToPB() const
	{
		HumanRpcMoveAsk v;
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcMoveAsk pb;
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
	void Init(const HumanRpcMoveAsk& v)
	{
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//移动方向
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
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//客户端停止移动回应封装类
class HumanRpcStopMoveReplyWraper
{
public:
	//构造函数
	HumanRpcStopMoveReplyWraper()
	{
		
		m_Result = -9999;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	HumanRpcStopMoveReplyWraper(const HumanRpcStopMoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcStopMoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcStopMoveReply ToPB() const
	{
		HumanRpcStopMoveReply v;
		v.set_result( m_Result );
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
		HumanRpcStopMoveReply pb;
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
	void Init(const HumanRpcStopMoveReply& v)
	{
		m_Result = v.result();
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
	//当前位置
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
	//移动方向
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
//客户端停止移动请求封装类
class HumanRpcStopMoveAskWraper
{
public:
	//构造函数
	HumanRpcStopMoveAskWraper()
	{
		
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcStopMoveAskWraper(const HumanRpcStopMoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcStopMoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcStopMoveAsk ToPB() const
	{
		HumanRpcStopMoveAsk v;
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcStopMoveAsk pb;
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
	void Init(const HumanRpcStopMoveAsk& v)
	{
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//移动方向
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
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<HumanRpcMoveCheckNotifyWraper>{ enum{ID=RPC_CODE_HUMAN_MOVECHECK_NOTIFY};};
template<> struct MessageIdT<HumanRpcMoveByPosNotifyWraper>{ enum{ID=RPC_CODE_HUMAN_MOVEBYPOS_NOTIFY};};


#endif
