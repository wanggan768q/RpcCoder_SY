/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperEvent.h
* Author:       郭晓波
* Description:  事件模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EVENT_H
#define __RPC_WRAPER_EVENT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "EventRpc.pb.h"



//事件模块类的枚举定义
enum ConstEventE
{
	MODULE_ID_EVENT                              = 5,	//事件模块模块ID
	RPC_CODE_EVENT_MOVE_NOTIFY                   = 551,	//事件模块-->ObjMove-->通知
	RPC_CODE_EVENT_STOPMOVE_NOTIFY               = 552,	//事件模块-->ObjStopMove-->通知
	RPC_CODE_EVENT_BOSSDIED_NOTIFY               = 553,	//事件模块-->Boss死亡-->通知


};


//Boss死亡通知封装类
class EventRpcBossDiedNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcBossDiedNotifyWraper()
	{
		
		m_SceneId = -1;
		m_ObjId = -1;
		m_IsEndingBoss = false;

	}
	//赋值构造函数
	EventRpcBossDiedNotifyWraper(const EventRpcBossDiedNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcBossDiedNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcBossDiedNotify ToPB() const
	{
		EventRpcBossDiedNotify v;
		v.set_sceneid( m_SceneId );
		v.set_objid( m_ObjId );
		v.set_isendingboss( m_IsEndingBoss );

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
		EventRpcBossDiedNotify pb;
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
	void Init(const EventRpcBossDiedNotify& v)
	{
		m_SceneId = v.sceneid();
		m_ObjId = v.objid();
		m_IsEndingBoss = v.isendingboss();

	}

private:
	//boss死亡的场景id
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
	//Boss的ObjId
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
	//是否是最终boss
	bool m_IsEndingBoss;
public:
	void SetIsEndingBoss( bool v)
	{
		m_IsEndingBoss=v;
	}
	bool GetIsEndingBoss()
	{
		return m_IsEndingBoss;
	}
	bool GetIsEndingBoss() const
	{
		return m_IsEndingBoss;
	}

};
//ObjStopMove通知封装类
class EventRpcStopMoveNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcStopMoveNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	EventRpcStopMoveNotifyWraper(const EventRpcStopMoveNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcStopMoveNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcStopMoveNotify ToPB() const
	{
		EventRpcStopMoveNotify v;
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
		EventRpcStopMoveNotify pb;
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const EventRpcStopMoveNotify& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();

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

};
//ObjMove通知封装类
class EventRpcMoveNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcMoveNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	EventRpcMoveNotifyWraper(const EventRpcMoveNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcMoveNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcMoveNotify ToPB() const
	{
		EventRpcMoveNotify v;
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
		EventRpcMoveNotify pb;
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const EventRpcMoveNotify& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();

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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<EventRpcMoveNotifyWraper>{ enum{ID=RPC_CODE_EVENT_MOVE_NOTIFY};};
template<> struct MessageIdT<EventRpcStopMoveNotifyWraper>{ enum{ID=RPC_CODE_EVENT_STOPMOVE_NOTIFY};};
template<> struct MessageIdT<EventRpcBossDiedNotifyWraper>{ enum{ID=RPC_CODE_EVENT_BOSSDIED_NOTIFY};};


#endif
