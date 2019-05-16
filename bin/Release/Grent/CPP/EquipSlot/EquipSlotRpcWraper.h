/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperEquipSlot.h
* Author:       甘业清
* Description:  装备槽RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EQUIPSLOT_H
#define __RPC_WRAPER_EQUIPSLOT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "EquipSlotRpc.pb.h"



//装备槽类的枚举定义
enum ConstEquipSlotE
{
	MODULE_ID_EQUIPSLOT                          = 27,	//装备槽模块ID
	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST     = 2751,	//装备槽-->同步装备槽相关-->请求
	RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST  = 2752,	//装备槽-->装备槽强化-->请求
	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST = 2753,	//装备槽-->同步装备槽星-->请求
	RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST   = 2754,	//装备槽-->装备槽升星-->请求


};


//装备槽升星回应封装类
class EquipSlotRpcUpStarEquipSlotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcUpStarEquipSlotReplyWraper()
	{
		
		m_Result = -1;
		m_Slot_Type = -1;
		m_UpStarResult = -1;

	}
	//赋值构造函数
	EquipSlotRpcUpStarEquipSlotReplyWraper(const EquipSlotRpcUpStarEquipSlotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcUpStarEquipSlotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcUpStarEquipSlotReply ToPB() const
	{
		EquipSlotRpcUpStarEquipSlotReply v;
		v.set_result( m_Result );
		v.mutable_equipslotstarlist()->Reserve(m_EquipSlotStarList.size());
		for (int i=0; i<(int)m_EquipSlotStarList.size(); i++)
		{
			*v.add_equipslotstarlist() = m_EquipSlotStarList[i].ToPB();
		}
		v.set_slot_type( m_Slot_Type );
		v.set_upstarresult( m_UpStarResult );

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
		EquipSlotRpcUpStarEquipSlotReply pb;
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
	void Init(const EquipSlotRpcUpStarEquipSlotReply& v)
	{
		m_Result = v.result();
		m_EquipSlotStarList.clear();
		m_EquipSlotStarList.reserve(v.equipslotstarlist_size());
		for( int i=0; i<v.equipslotstarlist_size(); i++)
			m_EquipSlotStarList.push_back(v.equipslotstarlist(i));
		m_Slot_Type = v.slot_type();
		m_UpStarResult = v.upstarresult();

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
	//装备槽星级列表
	vector<EquipSlotStarInfoWraper> m_EquipSlotStarList;
public:
	int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.size();
	}
	const vector<EquipSlotStarInfoWraper>& GetEquipSlotStarList() const
	{
		return m_EquipSlotStarList;
	}
	EquipSlotStarInfoWraper GetEquipSlotStarList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return EquipSlotStarInfoWraper();
		}
		return m_EquipSlotStarList[Index];
	}
	void SetEquipSlotStarList( const vector<EquipSlotStarInfoWraper>& v )
	{
		m_EquipSlotStarList=v;
	}
	void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.clear();
	}
	void SetEquipSlotStarList( int Index, const EquipSlotStarInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotStarList[Index] = v;
	}
	void AddEquipSlotStarList( const EquipSlotStarInfoWraper& v )
	{
		m_EquipSlotStarList.push_back(v);
	}
private:
	//槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}
private:
	//升星结果
	INT32 m_UpStarResult;
public:
	void SetUpStarResult( INT32 v)
	{
		m_UpStarResult=v;
	}
	INT32 GetUpStarResult()
	{
		return m_UpStarResult;
	}
	INT32 GetUpStarResult() const
	{
		return m_UpStarResult;
	}

};
//装备槽升星请求封装类
class EquipSlotRpcUpStarEquipSlotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcUpStarEquipSlotAskWraper()
	{
		
		m_Slot_Type = -1;
		m_IsProtection = false;

	}
	//赋值构造函数
	EquipSlotRpcUpStarEquipSlotAskWraper(const EquipSlotRpcUpStarEquipSlotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcUpStarEquipSlotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcUpStarEquipSlotAsk ToPB() const
	{
		EquipSlotRpcUpStarEquipSlotAsk v;
		v.set_slot_type( m_Slot_Type );
		v.set_isprotection( m_IsProtection );

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
		EquipSlotRpcUpStarEquipSlotAsk pb;
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
	void Init(const EquipSlotRpcUpStarEquipSlotAsk& v)
	{
		m_Slot_Type = v.slot_type();
		m_IsProtection = v.isprotection();

	}

private:
	//槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}
private:
	//是否保底
	bool m_IsProtection;
public:
	void SetIsProtection( bool v)
	{
		m_IsProtection=v;
	}
	bool GetIsProtection()
	{
		return m_IsProtection;
	}
	bool GetIsProtection() const
	{
		return m_IsProtection;
	}

};
//同步装备槽星回应封装类
class EquipSlotRpcSyncEquipSlotStarReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcSyncEquipSlotStarReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	EquipSlotRpcSyncEquipSlotStarReplyWraper(const EquipSlotRpcSyncEquipSlotStarReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcSyncEquipSlotStarReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcSyncEquipSlotStarReply ToPB() const
	{
		EquipSlotRpcSyncEquipSlotStarReply v;
		v.set_result( m_Result );
		v.mutable_equipslotstarlist()->Reserve(m_EquipSlotStarList.size());
		for (int i=0; i<(int)m_EquipSlotStarList.size(); i++)
		{
			*v.add_equipslotstarlist() = m_EquipSlotStarList[i].ToPB();
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
		EquipSlotRpcSyncEquipSlotStarReply pb;
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
	void Init(const EquipSlotRpcSyncEquipSlotStarReply& v)
	{
		m_Result = v.result();
		m_EquipSlotStarList.clear();
		m_EquipSlotStarList.reserve(v.equipslotstarlist_size());
		for( int i=0; i<v.equipslotstarlist_size(); i++)
			m_EquipSlotStarList.push_back(v.equipslotstarlist(i));

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
	//装备槽星级列表
	vector<EquipSlotStarInfoWraper> m_EquipSlotStarList;
public:
	int SizeEquipSlotStarList()
	{
		return m_EquipSlotStarList.size();
	}
	const vector<EquipSlotStarInfoWraper>& GetEquipSlotStarList() const
	{
		return m_EquipSlotStarList;
	}
	EquipSlotStarInfoWraper GetEquipSlotStarList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return EquipSlotStarInfoWraper();
		}
		return m_EquipSlotStarList[Index];
	}
	void SetEquipSlotStarList( const vector<EquipSlotStarInfoWraper>& v )
	{
		m_EquipSlotStarList=v;
	}
	void ClearEquipSlotStarList( )
	{
		m_EquipSlotStarList.clear();
	}
	void SetEquipSlotStarList( int Index, const EquipSlotStarInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotStarList.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotStarList[Index] = v;
	}
	void AddEquipSlotStarList( const EquipSlotStarInfoWraper& v )
	{
		m_EquipSlotStarList.push_back(v);
	}

};
//同步装备槽星请求封装类
class EquipSlotRpcSyncEquipSlotStarAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcSyncEquipSlotStarAskWraper()
	{
		

	}
	//赋值构造函数
	EquipSlotRpcSyncEquipSlotStarAskWraper(const EquipSlotRpcSyncEquipSlotStarAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcSyncEquipSlotStarAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcSyncEquipSlotStarAsk ToPB() const
	{
		EquipSlotRpcSyncEquipSlotStarAsk v;

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
		EquipSlotRpcSyncEquipSlotStarAsk pb;
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
	void Init(const EquipSlotRpcSyncEquipSlotStarAsk& v)
	{

	}


};
//同步装备槽相关回应封装类
class EquipSlotRpcSyncEquipSlotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcSyncEquipSlotReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	EquipSlotRpcSyncEquipSlotReplyWraper(const EquipSlotRpcSyncEquipSlotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcSyncEquipSlotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcSyncEquipSlotReply ToPB() const
	{
		EquipSlotRpcSyncEquipSlotReply v;
		v.set_result( m_Result );
		v.mutable_equipslotdata()->Reserve(m_EquipSlotData.size());
		for (int i=0; i<(int)m_EquipSlotData.size(); i++)
		{
			*v.add_equipslotdata() = m_EquipSlotData[i].ToPB();
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
		EquipSlotRpcSyncEquipSlotReply pb;
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
	void Init(const EquipSlotRpcSyncEquipSlotReply& v)
	{
		m_Result = v.result();
		m_EquipSlotData.clear();
		m_EquipSlotData.reserve(v.equipslotdata_size());
		for( int i=0; i<v.equipslotdata_size(); i++)
			m_EquipSlotData.push_back(v.equipslotdata(i));

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
	//装备槽信息
	vector<EquipSlotInfoWraper> m_EquipSlotData;
public:
	int SizeEquipSlotData()
	{
		return m_EquipSlotData.size();
	}
	const vector<EquipSlotInfoWraper>& GetEquipSlotData() const
	{
		return m_EquipSlotData;
	}
	EquipSlotInfoWraper GetEquipSlotData(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return EquipSlotInfoWraper();
		}
		return m_EquipSlotData[Index];
	}
	void SetEquipSlotData( const vector<EquipSlotInfoWraper>& v )
	{
		m_EquipSlotData=v;
	}
	void ClearEquipSlotData( )
	{
		m_EquipSlotData.clear();
	}
	void SetEquipSlotData( int Index, const EquipSlotInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotData[Index] = v;
	}
	void AddEquipSlotData( const EquipSlotInfoWraper& v )
	{
		m_EquipSlotData.push_back(v);
	}

};
//同步装备槽相关请求封装类
class EquipSlotRpcSyncEquipSlotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcSyncEquipSlotAskWraper()
	{
		

	}
	//赋值构造函数
	EquipSlotRpcSyncEquipSlotAskWraper(const EquipSlotRpcSyncEquipSlotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcSyncEquipSlotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcSyncEquipSlotAsk ToPB() const
	{
		EquipSlotRpcSyncEquipSlotAsk v;

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
		EquipSlotRpcSyncEquipSlotAsk pb;
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
	void Init(const EquipSlotRpcSyncEquipSlotAsk& v)
	{

	}


};
//装备槽强化回应封装类
class EquipSlotRpcEnhanceEquipSlotReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcEnhanceEquipSlotReplyWraper()
	{
		
		m_Result = -1;
		m_Slot_Type = -1;

	}
	//赋值构造函数
	EquipSlotRpcEnhanceEquipSlotReplyWraper(const EquipSlotRpcEnhanceEquipSlotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcEnhanceEquipSlotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcEnhanceEquipSlotReply ToPB() const
	{
		EquipSlotRpcEnhanceEquipSlotReply v;
		v.set_result( m_Result );
		v.mutable_equipslotdata()->Reserve(m_EquipSlotData.size());
		for (int i=0; i<(int)m_EquipSlotData.size(); i++)
		{
			*v.add_equipslotdata() = m_EquipSlotData[i].ToPB();
		}
		v.set_slot_type( m_Slot_Type );

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
		EquipSlotRpcEnhanceEquipSlotReply pb;
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
	void Init(const EquipSlotRpcEnhanceEquipSlotReply& v)
	{
		m_Result = v.result();
		m_EquipSlotData.clear();
		m_EquipSlotData.reserve(v.equipslotdata_size());
		for( int i=0; i<v.equipslotdata_size(); i++)
			m_EquipSlotData.push_back(v.equipslotdata(i));
		m_Slot_Type = v.slot_type();

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
	//装备槽信息
	vector<EquipSlotInfoWraper> m_EquipSlotData;
public:
	int SizeEquipSlotData()
	{
		return m_EquipSlotData.size();
	}
	const vector<EquipSlotInfoWraper>& GetEquipSlotData() const
	{
		return m_EquipSlotData;
	}
	EquipSlotInfoWraper GetEquipSlotData(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return EquipSlotInfoWraper();
		}
		return m_EquipSlotData[Index];
	}
	void SetEquipSlotData( const vector<EquipSlotInfoWraper>& v )
	{
		m_EquipSlotData=v;
	}
	void ClearEquipSlotData( )
	{
		m_EquipSlotData.clear();
	}
	void SetEquipSlotData( int Index, const EquipSlotInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipSlotData.size())
		{
			assert(false);
			return;
		}
		m_EquipSlotData[Index] = v;
	}
	void AddEquipSlotData( const EquipSlotInfoWraper& v )
	{
		m_EquipSlotData.push_back(v);
	}
private:
	//槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}

};
//装备槽强化请求封装类
class EquipSlotRpcEnhanceEquipSlotAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipSlotRpcEnhanceEquipSlotAskWraper()
	{
		
		m_Slot_Type = -1;

	}
	//赋值构造函数
	EquipSlotRpcEnhanceEquipSlotAskWraper(const EquipSlotRpcEnhanceEquipSlotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotRpcEnhanceEquipSlotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotRpcEnhanceEquipSlotAsk ToPB() const
	{
		EquipSlotRpcEnhanceEquipSlotAsk v;
		v.set_slot_type( m_Slot_Type );
		v.mutable_costitemlist()->Reserve(m_CostItemList.size());
		for (int i=0; i<(int)m_CostItemList.size(); i++)
		{
			*v.add_costitemlist() = m_CostItemList[i].ToPB();
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
		EquipSlotRpcEnhanceEquipSlotAsk pb;
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
	void Init(const EquipSlotRpcEnhanceEquipSlotAsk& v)
	{
		m_Slot_Type = v.slot_type();
		m_CostItemList.clear();
		m_CostItemList.reserve(v.costitemlist_size());
		for( int i=0; i<v.costitemlist_size(); i++)
			m_CostItemList.push_back(v.costitemlist(i));

	}

private:
	//槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}
private:
	//消耗物品列表
	vector<ItemSimpleDataWraper> m_CostItemList;
public:
	int SizeCostItemList()
	{
		return m_CostItemList.size();
	}
	const vector<ItemSimpleDataWraper>& GetCostItemList() const
	{
		return m_CostItemList;
	}
	ItemSimpleDataWraper GetCostItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CostItemList.size())
		{
			assert(false);
			return ItemSimpleDataWraper();
		}
		return m_CostItemList[Index];
	}
	void SetCostItemList( const vector<ItemSimpleDataWraper>& v )
	{
		m_CostItemList=v;
	}
	void ClearCostItemList( )
	{
		m_CostItemList.clear();
	}
	void SetCostItemList( int Index, const ItemSimpleDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_CostItemList.size())
		{
			assert(false);
			return;
		}
		m_CostItemList[Index] = v;
	}
	void AddCostItemList( const ItemSimpleDataWraper& v )
	{
		m_CostItemList.push_back(v);
	}

};

template<typename T> struct MessageIdT;


#endif
