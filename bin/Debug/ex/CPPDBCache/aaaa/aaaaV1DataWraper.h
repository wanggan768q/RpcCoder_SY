/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperaaaa.h
* Author:       甘业清
* Description:  aaa同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_AAAA_H
#define __SYNC_WRAPER_AAAA_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "aaaaV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//asdasd封装类
class aaaassssssWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<aaaassssssWraperV1>
{
public:
	//构造函数
	aaaassssssWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	aaaassssssWraperV1(const aaaassssssV1& v){ Init(v); }
	//等号重载函数
	void operator = (const aaaassssssV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	aaaassssssV1 ToPB() const
	{
		aaaassssssV1 v;

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
		aaaassssssV1 pb;
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
	void Init(const aaaassssssV1& v)
	{

	}


};

#endif
