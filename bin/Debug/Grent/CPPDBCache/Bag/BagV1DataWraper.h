/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     SyncWraperBag.h
* Author:       郭晓波
* Description:  Bag同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_BAG_H
#define __SYNC_WRAPER_BAG_H

#include "BaseDef.h"
#include "BagV1Data.pb.h"
using namespace std;



//Item数据库存储结构封装类
class BagItemDBWraperV1
{
public:
	//构造函数
	BagItemDBWraperV1()
	{
		
		m_Guid = -1;
		m_Lock = false;
		m_OverlayCount = -1;

	}
	//赋值构造函数
	BagItemDBWraperV1(const BagItemDBV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagItemDBV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagItemDBV1 ToPB() const
	{
		BagItemDBV1 v;
		v.set_guid( m_Guid );
		v.set_lock( m_Lock );
		v.set_overlaycount( m_OverlayCount );

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
		BagItemDBV1 pb;
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
	void Init(const BagItemDBV1& v)
	{
		m_Guid = v.guid();
		m_Lock = v.lock();
		m_OverlayCount = v.overlaycount();

	}

private:
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//Lock
	bool m_Lock;
public:
	void SetLock( bool v)
	{
		m_Lock=v;
	}
	bool GetLock()
	{
		return m_Lock;
	}
	bool GetLock() const
	{
		return m_Lock;
	}
private:
	//OverlayCount
	INT32 m_OverlayCount;
public:
	void SetOverlayCount( INT32 v)
	{
		m_OverlayCount=v;
	}
	INT32 GetOverlayCount()
	{
		return m_OverlayCount;
	}
	INT32 GetOverlayCount() const
	{
		return m_OverlayCount;
	}

};
//ItemData封装类
class BagItemDataWraperV1
{
public:
	//构造函数
	BagItemDataWraperV1()
	{
		
		m_Guid = -1;
		m_Lock = false;
		m_OverlayCount = -1;

	}
	//赋值构造函数
	BagItemDataWraperV1(const BagItemDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagItemDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagItemDataV1 ToPB() const
	{
		BagItemDataV1 v;
		v.set_guid( m_Guid );
		v.set_lock( m_Lock );
		v.set_overlaycount( m_OverlayCount );

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
		BagItemDataV1 pb;
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
	void Init(const BagItemDataV1& v)
	{
		m_Guid = v.guid();
		m_Lock = v.lock();
		m_OverlayCount = v.overlaycount();

	}

private:
	//Guid
	INT32 m_Guid;
public:
	void SetGuid( INT32 v)
	{
		m_Guid=v;
	}
	INT32 GetGuid()
	{
		return m_Guid;
	}
	INT32 GetGuid() const
	{
		return m_Guid;
	}
private:
	//Lock
	bool m_Lock;
public:
	void SetLock( bool v)
	{
		m_Lock=v;
	}
	bool GetLock()
	{
		return m_Lock;
	}
	bool GetLock() const
	{
		return m_Lock;
	}
private:
	//OverlayCount
	INT32 m_OverlayCount;
public:
	void SetOverlayCount( INT32 v)
	{
		m_OverlayCount=v;
	}
	INT32 GetOverlayCount()
	{
		return m_OverlayCount;
	}
	INT32 GetOverlayCount() const
	{
		return m_OverlayCount;
	}

};

#endif
