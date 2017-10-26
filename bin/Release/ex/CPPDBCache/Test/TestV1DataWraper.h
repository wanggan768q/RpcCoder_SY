/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperTest.h
* Author:       甘业清
* Description:  test同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_TEST_H
#define __SYNC_WRAPER_TEST_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "TestV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//User封装类
class TestUserWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<TestUserWraperV1>
{
public:
	//构造函数
	TestUserWraperV1()
	{
		SetDataWraper( this );

		m_Hp = -1;

	}
	//赋值构造函数
	TestUserWraperV1(const TestUserV1& v){ Init(v); }
	//等号重载函数
	void operator = (const TestUserV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TestUserV1 ToPB() const
	{
		TestUserV1 v;
		v.set_hp( m_Hp );

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
		TestUserV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Hp(hp) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Hp：%di</li>\r\n",m_Hp);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TestUserV1& v)
	{
		m_Hp = v.hp();

	}

private:
	//hp
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

};

#endif
