/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperJewel.h
* Author:       甘业清
* Description:  宝石模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_JEWEL_H
#define __RPC_WRAPER_JEWEL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "JewelRpc.pb.h"



//宝石模块类的枚举定义
enum ConstJewelE
{
	MODULE_ID_JEWEL                              = 25,	//宝石模块模块ID
	RPC_CODE_JEWEL_JEWELSYNC_REQUEST             = 2551,	//宝石模块-->同步-->请求
	RPC_CODE_JEWEL_INSETJEWEL_REQUEST            = 2552,	//宝石模块-->镶嵌-->请求
	RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST           = 2553,	//宝石模块-->摘除宝石-->请求
	RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST         = 2554,	//宝石模块-->合成宝石-->请求
	RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST      = 2555,	//宝石模块-->对已镶嵌的宝石合成-->请求
	RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST       = 2556,	//宝石模块-->解锁-->请求
	RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST         = 2557,	//宝石模块-->快速合成-->请求


};


//对已镶嵌的宝石合成回应封装类
class JewelRpcCompoundSetJewelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcCompoundSetJewelReplyWraper()
	{
		
		m_Result = -1;
		m_JewelInfo = JewelInfoWraper();

	}
	//赋值构造函数
	JewelRpcCompoundSetJewelReplyWraper(const JewelRpcCompoundSetJewelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcCompoundSetJewelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcCompoundSetJewelReply ToPB() const
	{
		JewelRpcCompoundSetJewelReply v;
		v.set_result( m_Result );
		*v.mutable_jewelinfo()= m_JewelInfo.ToPB();

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
		JewelRpcCompoundSetJewelReply pb;
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
	void Init(const JewelRpcCompoundSetJewelReply& v)
	{
		m_Result = v.result();
		m_JewelInfo = v.jewelinfo();

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
	//宝石信息
	JewelInfoWraper m_JewelInfo;
public:
	void SetJewelInfo( const JewelInfoWraper& v)
	{
		m_JewelInfo=v;
	}
	JewelInfoWraper GetJewelInfo()
	{
		return m_JewelInfo;
	}
	JewelInfoWraper GetJewelInfo() const
	{
		return m_JewelInfo;
	}

};
//对已镶嵌的宝石合成请求封装类
class JewelRpcCompoundSetJewelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcCompoundSetJewelAskWraper()
	{
		
		m_EquipType = -1;
		m_JewelSlot = -1;

	}
	//赋值构造函数
	JewelRpcCompoundSetJewelAskWraper(const JewelRpcCompoundSetJewelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcCompoundSetJewelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcCompoundSetJewelAsk ToPB() const
	{
		JewelRpcCompoundSetJewelAsk v;
		v.set_equiptype( m_EquipType );
		v.set_jewelslot( m_JewelSlot );

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
		JewelRpcCompoundSetJewelAsk pb;
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
	void Init(const JewelRpcCompoundSetJewelAsk& v)
	{
		m_EquipType = v.equiptype();
		m_JewelSlot = v.jewelslot();

	}

private:
	//装备位
	INT32 m_EquipType;
public:
	void SetEquipType( INT32 v)
	{
		m_EquipType=v;
	}
	INT32 GetEquipType()
	{
		return m_EquipType;
	}
	INT32 GetEquipType() const
	{
		return m_EquipType;
	}
private:
	//宝石位
	INT32 m_JewelSlot;
public:
	void SetJewelSlot( INT32 v)
	{
		m_JewelSlot=v;
	}
	INT32 GetJewelSlot()
	{
		return m_JewelSlot;
	}
	INT32 GetJewelSlot() const
	{
		return m_JewelSlot;
	}

};
//合成宝石回应封装类
class JewelRpcCompoundJewelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcCompoundJewelReplyWraper()
	{
		
		m_Result = -1;
		m_JewelId = -1;

	}
	//赋值构造函数
	JewelRpcCompoundJewelReplyWraper(const JewelRpcCompoundJewelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcCompoundJewelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcCompoundJewelReply ToPB() const
	{
		JewelRpcCompoundJewelReply v;
		v.set_result( m_Result );
		v.set_jewelid( m_JewelId );

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
		JewelRpcCompoundJewelReply pb;
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
	void Init(const JewelRpcCompoundJewelReply& v)
	{
		m_Result = v.result();
		m_JewelId = v.jewelid();

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
	//宝石ID
	INT32 m_JewelId;
public:
	void SetJewelId( INT32 v)
	{
		m_JewelId=v;
	}
	INT32 GetJewelId()
	{
		return m_JewelId;
	}
	INT32 GetJewelId() const
	{
		return m_JewelId;
	}

};
//解锁请求封装类
class JewelRpcUnlockJewelSlotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcUnlockJewelSlotAskWraper()
	{
		
		m_EquipSlot = -1;
		m_JewelSlot = -1;

	}
	//赋值构造函数
	JewelRpcUnlockJewelSlotAskWraper(const JewelRpcUnlockJewelSlotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcUnlockJewelSlotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcUnlockJewelSlotAsk ToPB() const
	{
		JewelRpcUnlockJewelSlotAsk v;
		v.set_equipslot( m_EquipSlot );
		v.set_jewelslot( m_JewelSlot );

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
		JewelRpcUnlockJewelSlotAsk pb;
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
	void Init(const JewelRpcUnlockJewelSlotAsk& v)
	{
		m_EquipSlot = v.equipslot();
		m_JewelSlot = v.jewelslot();

	}

private:
	//装备位
	INT32 m_EquipSlot;
public:
	void SetEquipSlot( INT32 v)
	{
		m_EquipSlot=v;
	}
	INT32 GetEquipSlot()
	{
		return m_EquipSlot;
	}
	INT32 GetEquipSlot() const
	{
		return m_EquipSlot;
	}
private:
	//槽位
	INT32 m_JewelSlot;
public:
	void SetJewelSlot( INT32 v)
	{
		m_JewelSlot=v;
	}
	INT32 GetJewelSlot()
	{
		return m_JewelSlot;
	}
	INT32 GetJewelSlot() const
	{
		return m_JewelSlot;
	}

};
//快速合成回应封装类
class JewelRpcQuickCompoundReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcQuickCompoundReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	JewelRpcQuickCompoundReplyWraper(const JewelRpcQuickCompoundReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcQuickCompoundReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcQuickCompoundReply ToPB() const
	{
		JewelRpcQuickCompoundReply v;
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
		JewelRpcQuickCompoundReply pb;
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
	void Init(const JewelRpcQuickCompoundReply& v)
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
//快速合成请求封装类
class JewelRpcQuickCompoundAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcQuickCompoundAskWraper()
	{
		
		m_JewelId = -1;

	}
	//赋值构造函数
	JewelRpcQuickCompoundAskWraper(const JewelRpcQuickCompoundAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcQuickCompoundAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcQuickCompoundAsk ToPB() const
	{
		JewelRpcQuickCompoundAsk v;
		v.set_jewelid( m_JewelId );

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
		JewelRpcQuickCompoundAsk pb;
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
	void Init(const JewelRpcQuickCompoundAsk& v)
	{
		m_JewelId = v.jewelid();

	}

private:
	//要合成谁
	INT32 m_JewelId;
public:
	void SetJewelId( INT32 v)
	{
		m_JewelId=v;
	}
	INT32 GetJewelId()
	{
		return m_JewelId;
	}
	INT32 GetJewelId() const
	{
		return m_JewelId;
	}

};
//解锁回应封装类
class JewelRpcUnlockJewelSlotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcUnlockJewelSlotReplyWraper()
	{
		
		m_Result = -1;
		m_JewelInfo = JewelInfoWraper();

	}
	//赋值构造函数
	JewelRpcUnlockJewelSlotReplyWraper(const JewelRpcUnlockJewelSlotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcUnlockJewelSlotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcUnlockJewelSlotReply ToPB() const
	{
		JewelRpcUnlockJewelSlotReply v;
		v.set_result( m_Result );
		*v.mutable_jewelinfo()= m_JewelInfo.ToPB();

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
		JewelRpcUnlockJewelSlotReply pb;
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
	void Init(const JewelRpcUnlockJewelSlotReply& v)
	{
		m_Result = v.result();
		m_JewelInfo = v.jewelinfo();

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
	//宝石信息
	JewelInfoWraper m_JewelInfo;
public:
	void SetJewelInfo( const JewelInfoWraper& v)
	{
		m_JewelInfo=v;
	}
	JewelInfoWraper GetJewelInfo()
	{
		return m_JewelInfo;
	}
	JewelInfoWraper GetJewelInfo() const
	{
		return m_JewelInfo;
	}

};
//镶嵌请求封装类
class JewelRpcInsetJewelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcInsetJewelAskWraper()
	{
		
		m_EquipSlot = -1;
		m_JewelId = -1;
		m_JewelSlot = -1;

	}
	//赋值构造函数
	JewelRpcInsetJewelAskWraper(const JewelRpcInsetJewelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcInsetJewelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcInsetJewelAsk ToPB() const
	{
		JewelRpcInsetJewelAsk v;
		v.set_equipslot( m_EquipSlot );
		v.set_jewelid( m_JewelId );
		v.set_jewelslot( m_JewelSlot );

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
		JewelRpcInsetJewelAsk pb;
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
	void Init(const JewelRpcInsetJewelAsk& v)
	{
		m_EquipSlot = v.equipslot();
		m_JewelId = v.jewelid();
		m_JewelSlot = v.jewelslot();

	}

private:
	//装备位
	INT32 m_EquipSlot;
public:
	void SetEquipSlot( INT32 v)
	{
		m_EquipSlot=v;
	}
	INT32 GetEquipSlot()
	{
		return m_EquipSlot;
	}
	INT32 GetEquipSlot() const
	{
		return m_EquipSlot;
	}
private:
	//宝石ID
	INT32 m_JewelId;
public:
	void SetJewelId( INT32 v)
	{
		m_JewelId=v;
	}
	INT32 GetJewelId()
	{
		return m_JewelId;
	}
	INT32 GetJewelId() const
	{
		return m_JewelId;
	}
private:
	//宝石位
	INT32 m_JewelSlot;
public:
	void SetJewelSlot( INT32 v)
	{
		m_JewelSlot=v;
	}
	INT32 GetJewelSlot()
	{
		return m_JewelSlot;
	}
	INT32 GetJewelSlot() const
	{
		return m_JewelSlot;
	}

};
//同步回应封装类
class JewelRpcJewelSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcJewelSyncReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	JewelRpcJewelSyncReplyWraper(const JewelRpcJewelSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcJewelSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcJewelSyncReply ToPB() const
	{
		JewelRpcJewelSyncReply v;
		v.set_result( m_Result );
		v.mutable_jewelinfos()->Reserve(m_JewelInfos.size());
		for (int i=0; i<(int)m_JewelInfos.size(); i++)
		{
			*v.add_jewelinfos() = m_JewelInfos[i].ToPB();
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
		JewelRpcJewelSyncReply pb;
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
	void Init(const JewelRpcJewelSyncReply& v)
	{
		m_Result = v.result();
		m_JewelInfos.clear();
		m_JewelInfos.reserve(v.jewelinfos_size());
		for( int i=0; i<v.jewelinfos_size(); i++)
			m_JewelInfos.push_back(v.jewelinfos(i));

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
	//宝石信息
	vector<JewelInfoWraper> m_JewelInfos;
public:
	int SizeJewelInfos()
	{
		return m_JewelInfos.size();
	}
	const vector<JewelInfoWraper>& GetJewelInfos() const
	{
		return m_JewelInfos;
	}
	JewelInfoWraper GetJewelInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_JewelInfos.size())
		{
			assert(false);
			return JewelInfoWraper();
		}
		return m_JewelInfos[Index];
	}
	void SetJewelInfos( const vector<JewelInfoWraper>& v )
	{
		m_JewelInfos=v;
	}
	void ClearJewelInfos( )
	{
		m_JewelInfos.clear();
	}
	void SetJewelInfos( int Index, const JewelInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_JewelInfos.size())
		{
			assert(false);
			return;
		}
		m_JewelInfos[Index] = v;
	}
	void AddJewelInfos( const JewelInfoWraper& v )
	{
		m_JewelInfos.push_back(v);
	}

};
//同步请求封装类
class JewelRpcJewelSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcJewelSyncAskWraper()
	{
		

	}
	//赋值构造函数
	JewelRpcJewelSyncAskWraper(const JewelRpcJewelSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcJewelSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcJewelSyncAsk ToPB() const
	{
		JewelRpcJewelSyncAsk v;

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
		JewelRpcJewelSyncAsk pb;
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
	void Init(const JewelRpcJewelSyncAsk& v)
	{

	}


};
//镶嵌回应封装类
class JewelRpcInsetJewelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcInsetJewelReplyWraper()
	{
		
		m_Result = -1;
		m_JewelInfo = JewelInfoWraper();

	}
	//赋值构造函数
	JewelRpcInsetJewelReplyWraper(const JewelRpcInsetJewelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcInsetJewelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcInsetJewelReply ToPB() const
	{
		JewelRpcInsetJewelReply v;
		v.set_result( m_Result );
		*v.mutable_jewelinfo()= m_JewelInfo.ToPB();

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
		JewelRpcInsetJewelReply pb;
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
	void Init(const JewelRpcInsetJewelReply& v)
	{
		m_Result = v.result();
		m_JewelInfo = v.jewelinfo();

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
	//宝石信息
	JewelInfoWraper m_JewelInfo;
public:
	void SetJewelInfo( const JewelInfoWraper& v)
	{
		m_JewelInfo=v;
	}
	JewelInfoWraper GetJewelInfo()
	{
		return m_JewelInfo;
	}
	JewelInfoWraper GetJewelInfo() const
	{
		return m_JewelInfo;
	}

};
//合成宝石请求封装类
class JewelRpcCompoundJewelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcCompoundJewelAskWraper()
	{
		
		m_JewelId = -1;
		m_UseSafeItem = false;

	}
	//赋值构造函数
	JewelRpcCompoundJewelAskWraper(const JewelRpcCompoundJewelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcCompoundJewelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcCompoundJewelAsk ToPB() const
	{
		JewelRpcCompoundJewelAsk v;
		v.set_jewelid( m_JewelId );
		v.set_usesafeitem( m_UseSafeItem );

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
		JewelRpcCompoundJewelAsk pb;
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
	void Init(const JewelRpcCompoundJewelAsk& v)
	{
		m_JewelId = v.jewelid();
		m_UseSafeItem = v.usesafeitem();

	}

private:
	//使用的宝石ID
	INT32 m_JewelId;
public:
	void SetJewelId( INT32 v)
	{
		m_JewelId=v;
	}
	INT32 GetJewelId()
	{
		return m_JewelId;
	}
	INT32 GetJewelId() const
	{
		return m_JewelId;
	}
private:
	//是否使用保底道具
	bool m_UseSafeItem;
public:
	void SetUseSafeItem( bool v)
	{
		m_UseSafeItem=v;
	}
	bool GetUseSafeItem()
	{
		return m_UseSafeItem;
	}
	bool GetUseSafeItem() const
	{
		return m_UseSafeItem;
	}

};
//摘除宝石回应封装类
class JewelRpcRemoveJewelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcRemoveJewelReplyWraper()
	{
		
		m_Result = -1;
		m_JewelInfo = JewelInfoWraper();

	}
	//赋值构造函数
	JewelRpcRemoveJewelReplyWraper(const JewelRpcRemoveJewelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcRemoveJewelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcRemoveJewelReply ToPB() const
	{
		JewelRpcRemoveJewelReply v;
		v.set_result( m_Result );
		*v.mutable_jewelinfo()= m_JewelInfo.ToPB();

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
		JewelRpcRemoveJewelReply pb;
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
	void Init(const JewelRpcRemoveJewelReply& v)
	{
		m_Result = v.result();
		m_JewelInfo = v.jewelinfo();

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
	//宝石信息
	JewelInfoWraper m_JewelInfo;
public:
	void SetJewelInfo( const JewelInfoWraper& v)
	{
		m_JewelInfo=v;
	}
	JewelInfoWraper GetJewelInfo()
	{
		return m_JewelInfo;
	}
	JewelInfoWraper GetJewelInfo() const
	{
		return m_JewelInfo;
	}

};
//摘除宝石请求封装类
class JewelRpcRemoveJewelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	JewelRpcRemoveJewelAskWraper()
	{
		
		m_EquipSlot = -1;
		m_JewelSlot = -1;

	}
	//赋值构造函数
	JewelRpcRemoveJewelAskWraper(const JewelRpcRemoveJewelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelRpcRemoveJewelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelRpcRemoveJewelAsk ToPB() const
	{
		JewelRpcRemoveJewelAsk v;
		v.set_equipslot( m_EquipSlot );
		v.set_jewelslot( m_JewelSlot );

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
		JewelRpcRemoveJewelAsk pb;
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
	void Init(const JewelRpcRemoveJewelAsk& v)
	{
		m_EquipSlot = v.equipslot();
		m_JewelSlot = v.jewelslot();

	}

private:
	//装备位
	INT32 m_EquipSlot;
public:
	void SetEquipSlot( INT32 v)
	{
		m_EquipSlot=v;
	}
	INT32 GetEquipSlot()
	{
		return m_EquipSlot;
	}
	INT32 GetEquipSlot() const
	{
		return m_EquipSlot;
	}
private:
	//宝石位置
	INT32 m_JewelSlot;
public:
	void SetJewelSlot( INT32 v)
	{
		m_JewelSlot=v;
	}
	INT32 GetJewelSlot()
	{
		return m_JewelSlot;
	}
	INT32 GetJewelSlot() const
	{
		return m_JewelSlot;
	}

};

template<typename T> struct MessageIdT;


#endif
