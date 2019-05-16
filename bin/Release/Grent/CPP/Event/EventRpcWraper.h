/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperEvent.h
* Author:       甘业清
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
	RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY          = 553,	//事件模块-->属性改变-->通知
	RPC_CODE_EVENT_COINCHANGE_NOTIFY             = 554,	//事件模块-->货币的变化通知-->通知
	RPC_CODE_EVENT_MOVEPOS_NOTIFY                = 555,	//事件模块-->按点移动-->通知


};


//货币的变化通知通知封装类
class EventRpcCoinChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcCoinChangeNotifyWraper()
	{
		
		m_Type = -1;
		m_Value = -1;

	}
	//赋值构造函数
	EventRpcCoinChangeNotifyWraper(const EventRpcCoinChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcCoinChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcCoinChangeNotify ToPB() const
	{
		EventRpcCoinChangeNotify v;
		v.set_type( m_Type );
		v.set_value( m_Value );

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
		EventRpcCoinChangeNotify pb;
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
	void Init(const EventRpcCoinChangeNotify& v)
	{
		m_Type = v.type();
		m_Value = v.value();

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
private:
	//值
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}

};
//按点移动通知封装类
class EventRpcMovePosNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcMovePosNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Dir = -1;
		m_IsAllowChangeRunAnimation = true;
		m_Follow = -1;

	}
	//赋值构造函数
	EventRpcMovePosNotifyWraper(const EventRpcMovePosNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcMovePosNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcMovePosNotify ToPB() const
	{
		EventRpcMovePosNotify v;
		v.set_objid( m_ObjId );
		v.mutable_poslist()->Reserve(m_PosList.size());
		for (int i=0; i<(int)m_PosList.size(); i++)
		{
			*v.add_poslist() = m_PosList[i].ToPB();
		}
		v.set_dir( m_Dir );
		v.set_isallowchangerunanimation( m_IsAllowChangeRunAnimation );
		v.set_follow( m_Follow );

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
		EventRpcMovePosNotify pb;
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
	void Init(const EventRpcMovePosNotify& v)
	{
		m_ObjId = v.objid();
		m_PosList.clear();
		m_PosList.reserve(v.poslist_size());
		for( int i=0; i<v.poslist_size(); i++)
			m_PosList.push_back(v.poslist(i));
		m_Dir = v.dir();
		m_IsAllowChangeRunAnimation = v.isallowchangerunanimation();
		m_Follow = v.follow();

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
	//要移动的位置
	vector<Vector3IntWraper> m_PosList;
public:
	int SizePosList()
	{
		return m_PosList.size();
	}
	const vector<Vector3IntWraper>& GetPosList() const
	{
		return m_PosList;
	}
	Vector3IntWraper GetPosList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PosList.size())
		{
			assert(false);
			return Vector3IntWraper();
		}
		return m_PosList[Index];
	}
	void SetPosList( const vector<Vector3IntWraper>& v )
	{
		m_PosList=v;
	}
	void ClearPosList( )
	{
		m_PosList.clear();
	}
	void SetPosList( int Index, const Vector3IntWraper& v )
	{
		if(Index<0 || Index>=(int)m_PosList.size())
		{
			assert(false);
			return;
		}
		m_PosList[Index] = v;
	}
	void AddPosList( const Vector3IntWraper& v )
	{
		m_PosList.push_back(v);
	}
private:
	//Dir
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
	//是否允许切换Run动画
	bool m_IsAllowChangeRunAnimation;
public:
	void SetIsAllowChangeRunAnimation( bool v)
	{
		m_IsAllowChangeRunAnimation=v;
	}
	bool GetIsAllowChangeRunAnimation()
	{
		return m_IsAllowChangeRunAnimation;
	}
	bool GetIsAllowChangeRunAnimation() const
	{
		return m_IsAllowChangeRunAnimation;
	}
private:
	//是否跟随状态
	INT32 m_Follow;
public:
	void SetFollow( INT32 v)
	{
		m_Follow=v;
	}
	INT32 GetFollow()
	{
		return m_Follow;
	}
	INT32 GetFollow() const
	{
		return m_Follow;
	}

};
//属性改变通知封装类
class EventRpcObjAttrChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcObjAttrChangeNotifyWraper()
	{
		
		m_Speed = -1;
		m_Hp = -1;
		m_Status = -1;
		m_ConfigId = -1;
		m_ObjId = -1;

	}
	//赋值构造函数
	EventRpcObjAttrChangeNotifyWraper(const EventRpcObjAttrChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const EventRpcObjAttrChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EventRpcObjAttrChangeNotify ToPB() const
	{
		EventRpcObjAttrChangeNotify v;
		v.set_speed( m_Speed );
		v.set_hp( m_Hp );
		v.set_status( m_Status );
		v.set_configid( m_ConfigId );
		v.set_objid( m_ObjId );

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
		EventRpcObjAttrChangeNotify pb;
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
	void Init(const EventRpcObjAttrChangeNotify& v)
	{
		m_Speed = v.speed();
		m_Hp = v.hp();
		m_Status = v.status();
		m_ConfigId = v.configid();
		m_ObjId = v.objid();

	}

private:
	//speed
	float m_Speed;
public:
	void SetSpeed( float v)
	{
		m_Speed=v;
	}
	float GetSpeed()
	{
		return m_Speed;
	}
	float GetSpeed() const
	{
		return m_Speed;
	}
private:
	//Hp
	int64_t m_Hp;
public:
	void SetHp( int64_t v)
	{
		m_Hp=v;
	}
	int64_t GetHp()
	{
		return m_Hp;
	}
	int64_t GetHp() const
	{
		return m_Hp;
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
	//NpcId改变
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
	//对象id
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

};
//ObjMove通知封装类
class EventRpcMoveNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcMoveNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = Vector3Wraper();
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

};
//ObjStopMove通知封装类
class EventRpcStopMoveNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EventRpcStopMoveNotifyWraper()
	{
		
		m_ObjId = -1;
		m_Pos = Vector3IntWraper();
		m_Dir = -1;
		m_Type = -1;

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
		m_Type = v.type();

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
	Vector3IntWraper m_Pos;
public:
	void SetPos( const Vector3IntWraper& v)
	{
		m_Pos=v;
	}
	Vector3IntWraper GetPos()
	{
		return m_Pos;
	}
	Vector3IntWraper GetPos() const
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<EventRpcMoveNotifyWraper>{ enum{ID=RPC_CODE_EVENT_MOVE_NOTIFY};};
template<> struct MessageIdT<EventRpcStopMoveNotifyWraper>{ enum{ID=RPC_CODE_EVENT_STOPMOVE_NOTIFY};};
template<> struct MessageIdT<EventRpcObjAttrChangeNotifyWraper>{ enum{ID=RPC_CODE_EVENT_OBJATTRCHANGE_NOTIFY};};
template<> struct MessageIdT<EventRpcCoinChangeNotifyWraper>{ enum{ID=RPC_CODE_EVENT_COINCHANGE_NOTIFY};};
template<> struct MessageIdT<EventRpcMovePosNotifyWraper>{ enum{ID=RPC_CODE_EVENT_MOVEPOS_NOTIFY};};


#endif
