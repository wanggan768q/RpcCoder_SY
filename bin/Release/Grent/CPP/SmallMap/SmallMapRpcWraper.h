/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperSmallMap.h
* Author:       甘业清
* Description:  小地图相关RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SMALLMAP_H
#define __RPC_WRAPER_SMALLMAP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "SmallMapRpc.pb.h"



//小地图相关类的枚举定义
enum ConstSmallMapE
{
	MODULE_ID_SMALLMAP                           = 14,	//小地图相关模块ID
	RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY              = 1451,	//小地图相关-->新的对象创建-->通知
	RPC_CODE_SMALLMAP_DELOBJ_NOTIFY              = 1452,	//小地图相关-->删除obj-->通知


};


//删除obj通知封装类
class SmallMapRpcDelObjNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SmallMapRpcDelObjNotifyWraper()
	{
		
		m_ObjId = -1;

	}
	//赋值构造函数
	SmallMapRpcDelObjNotifyWraper(const SmallMapRpcDelObjNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SmallMapRpcDelObjNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SmallMapRpcDelObjNotify ToPB() const
	{
		SmallMapRpcDelObjNotify v;
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
		SmallMapRpcDelObjNotify pb;
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
	void Init(const SmallMapRpcDelObjNotify& v)
	{
		m_ObjId = v.objid();

	}

private:
	//objId
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
//新的对象创建通知封装类
class SmallMapRpcNewObjNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SmallMapRpcNewObjNotifyWraper()
	{
		
		m_ObjId = -1;
		m_DataId = -1;
		m_WorldPos = Vector3Wraper();

	}
	//赋值构造函数
	SmallMapRpcNewObjNotifyWraper(const SmallMapRpcNewObjNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const SmallMapRpcNewObjNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SmallMapRpcNewObjNotify ToPB() const
	{
		SmallMapRpcNewObjNotify v;
		v.set_objid( m_ObjId );
		v.set_dataid( m_DataId );
		*v.mutable_worldpos()= m_WorldPos.ToPB();

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
		SmallMapRpcNewObjNotify pb;
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
	void Init(const SmallMapRpcNewObjNotify& v)
	{
		m_ObjId = v.objid();
		m_DataId = v.dataid();
		m_WorldPos = v.worldpos();

	}

private:
	//objID
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
	//DataId
	INT32 m_DataId;
public:
	void SetDataId( INT32 v)
	{
		m_DataId=v;
	}
	INT32 GetDataId()
	{
		return m_DataId;
	}
	INT32 GetDataId() const
	{
		return m_DataId;
	}
private:
	//位置信息
	Vector3Wraper m_WorldPos;
public:
	void SetWorldPos( const Vector3Wraper& v)
	{
		m_WorldPos=v;
	}
	Vector3Wraper GetWorldPos()
	{
		return m_WorldPos;
	}
	Vector3Wraper GetWorldPos() const
	{
		return m_WorldPos;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SmallMapRpcNewObjNotifyWraper>{ enum{ID=RPC_CODE_SMALLMAP_NEWOBJ_NOTIFY};};
template<> struct MessageIdT<SmallMapRpcDelObjNotifyWraper>{ enum{ID=RPC_CODE_SMALLMAP_DELOBJ_NOTIFY};};


#endif
