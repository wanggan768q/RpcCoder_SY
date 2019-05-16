/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperEquipment.h
* Author:       甘业清
* Description:  装备RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EQUIPMENT_H
#define __RPC_WRAPER_EQUIPMENT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "EquipmentRpc.pb.h"



//装备类的枚举定义
enum ConstEquipmentE
{
	MODULE_ID_EQUIPMENT                          = 18,	//装备模块ID
	RPC_CODE_EQUIPMENT_EQUIP_REQUEST             = 1851,	//装备-->Equip-->请求
	RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST           = 1852,	//装备-->UnEquip-->请求
	RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST    = 1853,	//装备-->SwitchEquipSet-->请求
	RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST         = 1854,	//装备-->Equip-->请求
	RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST   = 1855,	//装备-->激活共鸣-->请求
	RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST  = 1856,	//装备-->共鸣洗练-->请求
	RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST= 1857,	//装备-->保存共鸣属性-->请求
	RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST= 1858,	//装备-->初始化-->请求
	RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST     = 1859,	//装备-->初始化洗练数据-->请求
	RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST         = 1860,	//装备-->请求洗练-->请求
	RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST     = 1861,	//装备-->保存-->请求
	RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST    = 1862,	//装备-->装备打造-->请求
	RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST        = 1863,	//装备-->打造请求-->请求
	RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST     = 1864,	//装备-->获取其他玩家信息-->请求
	RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST      = 1865,	//装备-->装备继承-->请求


};


//请求洗练回应封装类
class EquipmentRpcEquipWashReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashReplyWraper()
	{
		
		m_Result = -1;
		m_EquipWashInfo = EquipWashInfoWraper();
		m_LeftTimes = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipWashReplyWraper(const EquipmentRpcEquipWashReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashReply ToPB() const
	{
		EquipmentRpcEquipWashReply v;
		v.set_result( m_Result );
		*v.mutable_equipwashinfo()= m_EquipWashInfo.ToPB();
		v.set_lefttimes( m_LeftTimes );

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
		EquipmentRpcEquipWashReply pb;
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
	void Init(const EquipmentRpcEquipWashReply& v)
	{
		m_Result = v.result();
		m_EquipWashInfo = v.equipwashinfo();
		m_LeftTimes = v.lefttimes();

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
	//洗练数据
	EquipWashInfoWraper m_EquipWashInfo;
public:
	void SetEquipWashInfo( const EquipWashInfoWraper& v)
	{
		m_EquipWashInfo=v;
	}
	EquipWashInfoWraper GetEquipWashInfo()
	{
		return m_EquipWashInfo;
	}
	EquipWashInfoWraper GetEquipWashInfo() const
	{
		return m_EquipWashInfo;
	}
private:
	//剩余次数
	INT32 m_LeftTimes;
public:
	void SetLeftTimes( INT32 v)
	{
		m_LeftTimes=v;
	}
	INT32 GetLeftTimes()
	{
		return m_LeftTimes;
	}
	INT32 GetLeftTimes() const
	{
		return m_LeftTimes;
	}

};
//保存请求封装类
class EquipmentRpcEquipWashSaveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashSaveAskWraper()
	{
		
		m_Guid = 0;

	}
	//赋值构造函数
	EquipmentRpcEquipWashSaveAskWraper(const EquipmentRpcEquipWashSaveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashSaveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashSaveAsk ToPB() const
	{
		EquipmentRpcEquipWashSaveAsk v;
		v.set_guid( m_Guid );

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
		EquipmentRpcEquipWashSaveAsk pb;
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
	void Init(const EquipmentRpcEquipWashSaveAsk& v)
	{
		m_Guid = v.guid();

	}

private:
	//装备GUID
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}

};
//保存回应封装类
class EquipmentRpcEquipWashSaveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashSaveReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipWashSaveReplyWraper(const EquipmentRpcEquipWashSaveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashSaveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashSaveReply ToPB() const
	{
		EquipmentRpcEquipWashSaveReply v;
		v.set_result( m_Result );
		*v.mutable_itemdata()= m_ItemData.ToPB();
		v.mutable_lockedindex()->Reserve(m_LockedIndex.size());
		for (int i=0; i<(int)m_LockedIndex.size(); i++)
		{
			v.add_lockedindex(m_LockedIndex[i]);
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
		EquipmentRpcEquipWashSaveReply pb;
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
	void Init(const EquipmentRpcEquipWashSaveReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();
		m_LockedIndex.clear();
		m_LockedIndex.reserve(v.lockedindex_size());
		for( int i=0; i<v.lockedindex_size(); i++)
			m_LockedIndex.push_back(v.lockedindex(i));

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
	//保存后的道具数据
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}
private:
	//锁定索引
	vector<INT32> m_LockedIndex;
public:
	int SizeLockedIndex()
	{
		return m_LockedIndex.size();
	}
	const vector<INT32>& GetLockedIndex() const
	{
		return m_LockedIndex;
	}
	INT32 GetLockedIndex(int Index) const
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return INT32();
		}
		return m_LockedIndex[Index];
	}
	void SetLockedIndex( const vector<INT32>& v )
	{
		m_LockedIndex=v;
	}
	void ClearLockedIndex( )
	{
		m_LockedIndex.clear();
	}
	void SetLockedIndex( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return;
		}
		m_LockedIndex[Index] = v;
	}
	void AddLockedIndex( INT32 v = -1 )
	{
		m_LockedIndex.push_back(v);
	}

};
//请求洗练请求封装类
class EquipmentRpcEquipWashAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashAskWraper()
	{
		
		m_Guid = 0;

	}
	//赋值构造函数
	EquipmentRpcEquipWashAskWraper(const EquipmentRpcEquipWashAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashAsk ToPB() const
	{
		EquipmentRpcEquipWashAsk v;
		v.set_guid( m_Guid );
		v.mutable_lockedindex()->Reserve(m_LockedIndex.size());
		for (int i=0; i<(int)m_LockedIndex.size(); i++)
		{
			v.add_lockedindex(m_LockedIndex[i]);
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
		EquipmentRpcEquipWashAsk pb;
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
	void Init(const EquipmentRpcEquipWashAsk& v)
	{
		m_Guid = v.guid();
		m_LockedIndex.clear();
		m_LockedIndex.reserve(v.lockedindex_size());
		for( int i=0; i<v.lockedindex_size(); i++)
			m_LockedIndex.push_back(v.lockedindex(i));

	}

private:
	//唯一id
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}
private:
	//锁的条目
	vector<INT32> m_LockedIndex;
public:
	int SizeLockedIndex()
	{
		return m_LockedIndex.size();
	}
	const vector<INT32>& GetLockedIndex() const
	{
		return m_LockedIndex;
	}
	INT32 GetLockedIndex(int Index) const
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return INT32();
		}
		return m_LockedIndex[Index];
	}
	void SetLockedIndex( const vector<INT32>& v )
	{
		m_LockedIndex=v;
	}
	void ClearLockedIndex( )
	{
		m_LockedIndex.clear();
	}
	void SetLockedIndex( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return;
		}
		m_LockedIndex[Index] = v;
	}
	void AddLockedIndex( INT32 v = -1 )
	{
		m_LockedIndex.push_back(v);
	}

};
//初始化回应封装类
class EquipmentRpcEquipResonanceSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipResonanceSyncReplyWraper()
	{
		
		m_Result = -1;
		m_ResonanceData = EquipResonanceDataWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipResonanceSyncReplyWraper(const EquipmentRpcEquipResonanceSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipResonanceSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipResonanceSyncReply ToPB() const
	{
		EquipmentRpcEquipResonanceSyncReply v;
		v.set_result( m_Result );
		*v.mutable_resonancedata()= m_ResonanceData.ToPB();

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
		EquipmentRpcEquipResonanceSyncReply pb;
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
	void Init(const EquipmentRpcEquipResonanceSyncReply& v)
	{
		m_Result = v.result();
		m_ResonanceData = v.resonancedata();

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
	//数据
	EquipResonanceDataWraper m_ResonanceData;
public:
	void SetResonanceData( const EquipResonanceDataWraper& v)
	{
		m_ResonanceData=v;
	}
	EquipResonanceDataWraper GetResonanceData()
	{
		return m_ResonanceData;
	}
	EquipResonanceDataWraper GetResonanceData() const
	{
		return m_ResonanceData;
	}

};
//初始化洗练数据请求封装类
class EquipmentRpcEquipWashSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashSyncAskWraper()
	{
		

	}
	//赋值构造函数
	EquipmentRpcEquipWashSyncAskWraper(const EquipmentRpcEquipWashSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashSyncAsk ToPB() const
	{
		EquipmentRpcEquipWashSyncAsk v;

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
		EquipmentRpcEquipWashSyncAsk pb;
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
	void Init(const EquipmentRpcEquipWashSyncAsk& v)
	{

	}


};
//初始化洗练数据回应封装类
class EquipmentRpcEquipWashSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipWashSyncReplyWraper()
	{
		
		m_Result = -1;
		m_EquipWashData = EquipWashDataWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipWashSyncReplyWraper(const EquipmentRpcEquipWashSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipWashSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipWashSyncReply ToPB() const
	{
		EquipmentRpcEquipWashSyncReply v;
		v.set_result( m_Result );
		*v.mutable_equipwashdata()= m_EquipWashData.ToPB();

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
		EquipmentRpcEquipWashSyncReply pb;
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
	void Init(const EquipmentRpcEquipWashSyncReply& v)
	{
		m_Result = v.result();
		m_EquipWashData = v.equipwashdata();

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
	//洗练数据
	EquipWashDataWraper m_EquipWashData;
public:
	void SetEquipWashData( const EquipWashDataWraper& v)
	{
		m_EquipWashData=v;
	}
	EquipWashDataWraper GetEquipWashData()
	{
		return m_EquipWashData;
	}
	EquipWashDataWraper GetEquipWashData() const
	{
		return m_EquipWashData;
	}

};
//装备打造请求封装类
class EquipmentRpcEquipBuildSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipBuildSyncAskWraper()
	{
		

	}
	//赋值构造函数
	EquipmentRpcEquipBuildSyncAskWraper(const EquipmentRpcEquipBuildSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipBuildSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipBuildSyncAsk ToPB() const
	{
		EquipmentRpcEquipBuildSyncAsk v;

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
		EquipmentRpcEquipBuildSyncAsk pb;
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
	void Init(const EquipmentRpcEquipBuildSyncAsk& v)
	{

	}


};
//获取其他玩家信息回应封装类
class EquipmentRpcGetPlayerInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcGetPlayerInfoReplyWraper()
	{
		
		m_Result = -1;
		m_Player_name = "";
		m_Player_guid = 0;
		m_Avatar_id = -1;
		m_Player_level = -1;
		m_Avatar_frame_id = -1;
		m_Config_id = -1;
		m_Guild_id = 0;
		m_Guild_name = "";
		m_BattleScore = -1;
		m_Pet_item_data = ItemDataWraper();
		m_TreasureHair = -1;
		m_TreasureHead = -1;
		m_TreasureBody = -1;
		m_TreasureWeapon = -1;
		m_TreasureWing = -1;
		m_TeamId = 0;

	}
	//赋值构造函数
	EquipmentRpcGetPlayerInfoReplyWraper(const EquipmentRpcGetPlayerInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcGetPlayerInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcGetPlayerInfoReply ToPB() const
	{
		EquipmentRpcGetPlayerInfoReply v;
		v.set_result( m_Result );
		v.set_player_name( m_Player_name );
		v.set_player_guid( m_Player_guid );
		v.set_avatar_id( m_Avatar_id );
		v.set_player_level( m_Player_level );
		v.set_avatar_frame_id( m_Avatar_frame_id );
		v.set_config_id( m_Config_id );
		v.set_guild_id( m_Guild_id );
		v.set_guild_name( m_Guild_name );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
		}
		v.mutable_suit_infos()->Reserve(m_Suit_infos.size());
		for (int i=0; i<(int)m_Suit_infos.size(); i++)
		{
			*v.add_suit_infos() = m_Suit_infos[i].ToPB();
		}
		v.mutable_equipslotdata()->Reserve(m_EquipSlotData.size());
		for (int i=0; i<(int)m_EquipSlotData.size(); i++)
		{
			*v.add_equipslotdata() = m_EquipSlotData[i].ToPB();
		}
		v.mutable_equipslotstarlist()->Reserve(m_EquipSlotStarList.size());
		for (int i=0; i<(int)m_EquipSlotStarList.size(); i++)
		{
			*v.add_equipslotstarlist() = m_EquipSlotStarList[i].ToPB();
		}
		v.mutable_jewelinfos()->Reserve(m_JewelInfos.size());
		for (int i=0; i<(int)m_JewelInfos.size(); i++)
		{
			*v.add_jewelinfos() = m_JewelInfos[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );
		*v.mutable_pet_item_data()= m_Pet_item_data.ToPB();
		v.set_treasurehair( m_TreasureHair );
		v.set_treasurehead( m_TreasureHead );
		v.set_treasurebody( m_TreasureBody );
		v.set_treasureweapon( m_TreasureWeapon );
		v.set_treasurewing( m_TreasureWing );
		v.set_teamid( m_TeamId );

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
		EquipmentRpcGetPlayerInfoReply pb;
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
	void Init(const EquipmentRpcGetPlayerInfoReply& v)
	{
		m_Result = v.result();
		m_Player_name = v.player_name();
		m_Player_guid = v.player_guid();
		m_Avatar_id = v.avatar_id();
		m_Player_level = v.player_level();
		m_Avatar_frame_id = v.avatar_frame_id();
		m_Config_id = v.config_id();
		m_Guild_id = v.guild_id();
		m_Guild_name = v.guild_name();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));
		m_Suit_infos.clear();
		m_Suit_infos.reserve(v.suit_infos_size());
		for( int i=0; i<v.suit_infos_size(); i++)
			m_Suit_infos.push_back(v.suit_infos(i));
		m_EquipSlotData.clear();
		m_EquipSlotData.reserve(v.equipslotdata_size());
		for( int i=0; i<v.equipslotdata_size(); i++)
			m_EquipSlotData.push_back(v.equipslotdata(i));
		m_EquipSlotStarList.clear();
		m_EquipSlotStarList.reserve(v.equipslotstarlist_size());
		for( int i=0; i<v.equipslotstarlist_size(); i++)
			m_EquipSlotStarList.push_back(v.equipslotstarlist(i));
		m_JewelInfos.clear();
		m_JewelInfos.reserve(v.jewelinfos_size());
		for( int i=0; i<v.jewelinfos_size(); i++)
			m_JewelInfos.push_back(v.jewelinfos(i));
		m_BattleScore = v.battlescore();
		m_Pet_item_data = v.pet_item_data();
		m_TreasureHair = v.treasurehair();
		m_TreasureHead = v.treasurehead();
		m_TreasureBody = v.treasurebody();
		m_TreasureWeapon = v.treasureweapon();
		m_TreasureWing = v.treasurewing();
		m_TeamId = v.teamid();

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
	//玩家名字
	string m_Player_name;
public:
	void SetPlayer_name( const string& v)
	{
		m_Player_name=v;
	}
	string GetPlayer_name()
	{
		return m_Player_name;
	}
	string GetPlayer_name() const
	{
		return m_Player_name;
	}
private:
	//玩家GUID
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}
private:
	//头像ID
	INT32 m_Avatar_id;
public:
	void SetAvatar_id( INT32 v)
	{
		m_Avatar_id=v;
	}
	INT32 GetAvatar_id()
	{
		return m_Avatar_id;
	}
	INT32 GetAvatar_id() const
	{
		return m_Avatar_id;
	}
private:
	//等级
	INT32 m_Player_level;
public:
	void SetPlayer_level( INT32 v)
	{
		m_Player_level=v;
	}
	INT32 GetPlayer_level()
	{
		return m_Player_level;
	}
	INT32 GetPlayer_level() const
	{
		return m_Player_level;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id;
public:
	void SetAvatar_frame_id( INT32 v)
	{
		m_Avatar_frame_id=v;
	}
	INT32 GetAvatar_frame_id()
	{
		return m_Avatar_frame_id;
	}
	INT32 GetAvatar_frame_id() const
	{
		return m_Avatar_frame_id;
	}
private:
	//角色配置ID
	INT32 m_Config_id;
public:
	void SetConfig_id( INT32 v)
	{
		m_Config_id=v;
	}
	INT32 GetConfig_id()
	{
		return m_Config_id;
	}
	INT32 GetConfig_id() const
	{
		return m_Config_id;
	}
private:
	//公会id
	uint64_t m_Guild_id;
public:
	void SetGuild_id( uint64_t v)
	{
		m_Guild_id=v;
	}
	uint64_t GetGuild_id()
	{
		return m_Guild_id;
	}
	uint64_t GetGuild_id() const
	{
		return m_Guild_id;
	}
private:
	//公会名字
	string m_Guild_name;
public:
	void SetGuild_name( const string& v)
	{
		m_Guild_name=v;
	}
	string GetGuild_name()
	{
		return m_Guild_name;
	}
	string GetGuild_name() const
	{
		return m_Guild_name;
	}
private:
	//装备信息
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}
private:
	//Suit_infos
	vector<SuitInfoWraper> m_Suit_infos;
public:
	int SizeSuit_infos()
	{
		return m_Suit_infos.size();
	}
	const vector<SuitInfoWraper>& GetSuit_infos() const
	{
		return m_Suit_infos;
	}
	SuitInfoWraper GetSuit_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_Suit_infos[Index];
	}
	void SetSuit_infos( const vector<SuitInfoWraper>& v )
	{
		m_Suit_infos=v;
	}
	void ClearSuit_infos( )
	{
		m_Suit_infos.clear();
	}
	void SetSuit_infos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return;
		}
		m_Suit_infos[Index] = v;
	}
	void AddSuit_infos( const SuitInfoWraper& v )
	{
		m_Suit_infos.push_back(v);
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
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//宠物数据
	ItemDataWraper m_Pet_item_data;
public:
	void SetPet_item_data( const ItemDataWraper& v)
	{
		m_Pet_item_data=v;
	}
	ItemDataWraper GetPet_item_data()
	{
		return m_Pet_item_data;
	}
	ItemDataWraper GetPet_item_data() const
	{
		return m_Pet_item_data;
	}
private:
	//头发时装ID
	INT32 m_TreasureHair;
public:
	void SetTreasureHair( INT32 v)
	{
		m_TreasureHair=v;
	}
	INT32 GetTreasureHair()
	{
		return m_TreasureHair;
	}
	INT32 GetTreasureHair() const
	{
		return m_TreasureHair;
	}
private:
	//头部时装ID
	INT32 m_TreasureHead;
public:
	void SetTreasureHead( INT32 v)
	{
		m_TreasureHead=v;
	}
	INT32 GetTreasureHead()
	{
		return m_TreasureHead;
	}
	INT32 GetTreasureHead() const
	{
		return m_TreasureHead;
	}
private:
	//身体时装
	INT32 m_TreasureBody;
public:
	void SetTreasureBody( INT32 v)
	{
		m_TreasureBody=v;
	}
	INT32 GetTreasureBody()
	{
		return m_TreasureBody;
	}
	INT32 GetTreasureBody() const
	{
		return m_TreasureBody;
	}
private:
	//武器时装
	INT32 m_TreasureWeapon;
public:
	void SetTreasureWeapon( INT32 v)
	{
		m_TreasureWeapon=v;
	}
	INT32 GetTreasureWeapon()
	{
		return m_TreasureWeapon;
	}
	INT32 GetTreasureWeapon() const
	{
		return m_TreasureWeapon;
	}
private:
	//翅膀时装
	INT32 m_TreasureWing;
public:
	void SetTreasureWing( INT32 v)
	{
		m_TreasureWing=v;
	}
	INT32 GetTreasureWing()
	{
		return m_TreasureWing;
	}
	INT32 GetTreasureWing() const
	{
		return m_TreasureWing;
	}
private:
	//队伍id
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
	}

};
//装备继承请求封装类
class EquipmentRpcEquipInheritAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipInheritAskWraper()
	{
		
		m_ToGuid = 0;
		m_FromGuid = 0;

	}
	//赋值构造函数
	EquipmentRpcEquipInheritAskWraper(const EquipmentRpcEquipInheritAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipInheritAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipInheritAsk ToPB() const
	{
		EquipmentRpcEquipInheritAsk v;
		v.set_toguid( m_ToGuid );
		v.set_fromguid( m_FromGuid );

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
		EquipmentRpcEquipInheritAsk pb;
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
	void Init(const EquipmentRpcEquipInheritAsk& v)
	{
		m_ToGuid = v.toguid();
		m_FromGuid = v.fromguid();

	}

private:
	//被继承的装备GUID
	uint64_t m_ToGuid;
public:
	void SetToGuid( uint64_t v)
	{
		m_ToGuid=v;
	}
	uint64_t GetToGuid()
	{
		return m_ToGuid;
	}
	uint64_t GetToGuid() const
	{
		return m_ToGuid;
	}
private:
	//从哪个装备继承
	uint64_t m_FromGuid;
public:
	void SetFromGuid( uint64_t v)
	{
		m_FromGuid=v;
	}
	uint64_t GetFromGuid()
	{
		return m_FromGuid;
	}
	uint64_t GetFromGuid() const
	{
		return m_FromGuid;
	}

};
//装备继承回应封装类
class EquipmentRpcEquipInheritReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipInheritReplyWraper()
	{
		
		m_Result = -1;
		m_NewEquip = ItemDataWraper();
		m_FromGuid = 0;

	}
	//赋值构造函数
	EquipmentRpcEquipInheritReplyWraper(const EquipmentRpcEquipInheritReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipInheritReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipInheritReply ToPB() const
	{
		EquipmentRpcEquipInheritReply v;
		v.set_result( m_Result );
		*v.mutable_newequip()= m_NewEquip.ToPB();
		v.mutable_equipdata()->Reserve(m_EquipData.size());
		for (int i=0; i<(int)m_EquipData.size(); i++)
		{
			*v.add_equipdata() = m_EquipData[i].ToPB();
		}
		v.mutable_suitinfos()->Reserve(m_SuitInfos.size());
		for (int i=0; i<(int)m_SuitInfos.size(); i++)
		{
			*v.add_suitinfos() = m_SuitInfos[i].ToPB();
		}
		v.set_fromguid( m_FromGuid );

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
		EquipmentRpcEquipInheritReply pb;
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
	void Init(const EquipmentRpcEquipInheritReply& v)
	{
		m_Result = v.result();
		m_NewEquip = v.newequip();
		m_EquipData.clear();
		m_EquipData.reserve(v.equipdata_size());
		for( int i=0; i<v.equipdata_size(); i++)
			m_EquipData.push_back(v.equipdata(i));
		m_SuitInfos.clear();
		m_SuitInfos.reserve(v.suitinfos_size());
		for( int i=0; i<v.suitinfos_size(); i++)
			m_SuitInfos.push_back(v.suitinfos(i));
		m_FromGuid = v.fromguid();

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
	//新装备
	ItemDataWraper m_NewEquip;
public:
	void SetNewEquip( const ItemDataWraper& v)
	{
		m_NewEquip=v;
	}
	ItemDataWraper GetNewEquip()
	{
		return m_NewEquip;
	}
	ItemDataWraper GetNewEquip() const
	{
		return m_NewEquip;
	}
private:
	//装备信息
	vector<ItemDataWraper> m_EquipData;
public:
	int SizeEquipData()
	{
		return m_EquipData.size();
	}
	const vector<ItemDataWraper>& GetEquipData() const
	{
		return m_EquipData;
	}
	ItemDataWraper GetEquipData(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipData.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_EquipData[Index];
	}
	void SetEquipData( const vector<ItemDataWraper>& v )
	{
		m_EquipData=v;
	}
	void ClearEquipData( )
	{
		m_EquipData.clear();
	}
	void SetEquipData( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipData.size())
		{
			assert(false);
			return;
		}
		m_EquipData[Index] = v;
	}
	void AddEquipData( const ItemDataWraper& v )
	{
		m_EquipData.push_back(v);
	}
private:
	//套装信息
	vector<SuitInfoWraper> m_SuitInfos;
public:
	int SizeSuitInfos()
	{
		return m_SuitInfos.size();
	}
	const vector<SuitInfoWraper>& GetSuitInfos() const
	{
		return m_SuitInfos;
	}
	SuitInfoWraper GetSuitInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_SuitInfos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_SuitInfos[Index];
	}
	void SetSuitInfos( const vector<SuitInfoWraper>& v )
	{
		m_SuitInfos=v;
	}
	void ClearSuitInfos( )
	{
		m_SuitInfos.clear();
	}
	void SetSuitInfos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_SuitInfos.size())
		{
			assert(false);
			return;
		}
		m_SuitInfos[Index] = v;
	}
	void AddSuitInfos( const SuitInfoWraper& v )
	{
		m_SuitInfos.push_back(v);
	}
private:
	//FromGuid
	uint64_t m_FromGuid;
public:
	void SetFromGuid( uint64_t v)
	{
		m_FromGuid=v;
	}
	uint64_t GetFromGuid()
	{
		return m_FromGuid;
	}
	uint64_t GetFromGuid() const
	{
		return m_FromGuid;
	}

};
//获取其他玩家信息请求封装类
class EquipmentRpcGetPlayerInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcGetPlayerInfoAskWraper()
	{
		
		m_Player_guid = 0;

	}
	//赋值构造函数
	EquipmentRpcGetPlayerInfoAskWraper(const EquipmentRpcGetPlayerInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcGetPlayerInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcGetPlayerInfoAsk ToPB() const
	{
		EquipmentRpcGetPlayerInfoAsk v;
		v.set_player_guid( m_Player_guid );

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
		EquipmentRpcGetPlayerInfoAsk pb;
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
	void Init(const EquipmentRpcGetPlayerInfoAsk& v)
	{
		m_Player_guid = v.player_guid();

	}

private:
	//玩家guid
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}

};
//装备打造回应封装类
class EquipmentRpcEquipBuildSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipBuildSyncReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipBuildSyncReplyWraper(const EquipmentRpcEquipBuildSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipBuildSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipBuildSyncReply ToPB() const
	{
		EquipmentRpcEquipBuildSyncReply v;
		v.set_result( m_Result );
		v.mutable_atf_list()->Reserve(m_Atf_list.size());
		for (int i=0; i<(int)m_Atf_list.size(); i++)
		{
			*v.add_atf_list() = m_Atf_list[i].ToPB();
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
		EquipmentRpcEquipBuildSyncReply pb;
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
	void Init(const EquipmentRpcEquipBuildSyncReply& v)
	{
		m_Result = v.result();
		m_Atf_list.clear();
		m_Atf_list.reserve(v.atf_list_size());
		for( int i=0; i<v.atf_list_size(); i++)
			m_Atf_list.push_back(v.atf_list(i));

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
	//神器值列表
	vector<EquipBuildAtfWraper> m_Atf_list;
public:
	int SizeAtf_list()
	{
		return m_Atf_list.size();
	}
	const vector<EquipBuildAtfWraper>& GetAtf_list() const
	{
		return m_Atf_list;
	}
	EquipBuildAtfWraper GetAtf_list(int Index) const
	{
		if(Index<0 || Index>=(int)m_Atf_list.size())
		{
			assert(false);
			return EquipBuildAtfWraper();
		}
		return m_Atf_list[Index];
	}
	void SetAtf_list( const vector<EquipBuildAtfWraper>& v )
	{
		m_Atf_list=v;
	}
	void ClearAtf_list( )
	{
		m_Atf_list.clear();
	}
	void SetAtf_list( int Index, const EquipBuildAtfWraper& v )
	{
		if(Index<0 || Index>=(int)m_Atf_list.size())
		{
			assert(false);
			return;
		}
		m_Atf_list[Index] = v;
	}
	void AddAtf_list( const EquipBuildAtfWraper& v )
	{
		m_Atf_list.push_back(v);
	}

};
//打造请求请求封装类
class EquipmentRpcEquipBuildAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipBuildAskWraper()
	{
		
		m_Level = -1;
		m_Occupation = -1;
		m_Slot_type = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipBuildAskWraper(const EquipmentRpcEquipBuildAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipBuildAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipBuildAsk ToPB() const
	{
		EquipmentRpcEquipBuildAsk v;
		v.set_level( m_Level );
		v.set_occupation( m_Occupation );
		v.set_slot_type( m_Slot_type );

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
		EquipmentRpcEquipBuildAsk pb;
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
	void Init(const EquipmentRpcEquipBuildAsk& v)
	{
		m_Level = v.level();
		m_Occupation = v.occupation();
		m_Slot_type = v.slot_type();

	}

private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//职业
	INT32 m_Occupation;
public:
	void SetOccupation( INT32 v)
	{
		m_Occupation=v;
	}
	INT32 GetOccupation()
	{
		return m_Occupation;
	}
	INT32 GetOccupation() const
	{
		return m_Occupation;
	}
private:
	//整备类型
	INT32 m_Slot_type;
public:
	void SetSlot_type( INT32 v)
	{
		m_Slot_type=v;
	}
	INT32 GetSlot_type()
	{
		return m_Slot_type;
	}
	INT32 GetSlot_type() const
	{
		return m_Slot_type;
	}

};
//打造请求回应封装类
class EquipmentRpcEquipBuildReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipBuildReplyWraper()
	{
		
		m_Result = -1;
		m_EquipBuildAtf = EquipBuildAtfWraper();
		m_Equip = ItemObjWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipBuildReplyWraper(const EquipmentRpcEquipBuildReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipBuildReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipBuildReply ToPB() const
	{
		EquipmentRpcEquipBuildReply v;
		v.set_result( m_Result );
		*v.mutable_equipbuildatf()= m_EquipBuildAtf.ToPB();
		*v.mutable_equip()= m_Equip.ToPB();

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
		EquipmentRpcEquipBuildReply pb;
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
	void Init(const EquipmentRpcEquipBuildReply& v)
	{
		m_Result = v.result();
		m_EquipBuildAtf = v.equipbuildatf();
		m_Equip = v.equip();

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
	//打造后的神器值
	EquipBuildAtfWraper m_EquipBuildAtf;
public:
	void SetEquipBuildAtf( const EquipBuildAtfWraper& v)
	{
		m_EquipBuildAtf=v;
	}
	EquipBuildAtfWraper GetEquipBuildAtf()
	{
		return m_EquipBuildAtf;
	}
	EquipBuildAtfWraper GetEquipBuildAtf() const
	{
		return m_EquipBuildAtf;
	}
private:
	//打造出的装备
	ItemObjWraper m_Equip;
public:
	void SetEquip( const ItemObjWraper& v)
	{
		m_Equip=v;
	}
	ItemObjWraper GetEquip()
	{
		return m_Equip;
	}
	ItemObjWraper GetEquip() const
	{
		return m_Equip;
	}

};
//切换装备套装请求封装类
class EquipmentRpcSwitchEquipSetAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcSwitchEquipSetAskWraper()
	{
		
		m_To_index = -1;

	}
	//赋值构造函数
	EquipmentRpcSwitchEquipSetAskWraper(const EquipmentRpcSwitchEquipSetAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcSwitchEquipSetAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcSwitchEquipSetAsk ToPB() const
	{
		EquipmentRpcSwitchEquipSetAsk v;
		v.set_to_index( m_To_index );

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
		EquipmentRpcSwitchEquipSetAsk pb;
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
	void Init(const EquipmentRpcSwitchEquipSetAsk& v)
	{
		m_To_index = v.to_index();

	}

private:
	//切换为几号套装
	INT32 m_To_index;
public:
	void SetTo_index( INT32 v)
	{
		m_To_index=v;
	}
	INT32 GetTo_index()
	{
		return m_To_index;
	}
	INT32 GetTo_index() const
	{
		return m_To_index;
	}

};
//切换装备套装回应封装类
class EquipmentRpcSwitchEquipSetReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcSwitchEquipSetReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	EquipmentRpcSwitchEquipSetReplyWraper(const EquipmentRpcSwitchEquipSetReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcSwitchEquipSetReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcSwitchEquipSetReply ToPB() const
	{
		EquipmentRpcSwitchEquipSetReply v;
		v.set_result( m_Result );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
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
		EquipmentRpcSwitchEquipSetReply pb;
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
	void Init(const EquipmentRpcSwitchEquipSetReply& v)
	{
		m_Result = v.result();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));

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
	//更新背包
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}

};
//同步装备套装请求封装类
class EquipmentRpcSyncEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcSyncEquipAskWraper()
	{
		

	}
	//赋值构造函数
	EquipmentRpcSyncEquipAskWraper(const EquipmentRpcSyncEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcSyncEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcSyncEquipAsk ToPB() const
	{
		EquipmentRpcSyncEquipAsk v;

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
		EquipmentRpcSyncEquipAsk pb;
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
	void Init(const EquipmentRpcSyncEquipAsk& v)
	{

	}


};
//卸载装备回应封装类
class EquipmentRpcUnEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcUnEquipReplyWraper()
	{
		
		m_Result = -9999;
		m_SlotType = -1;

	}
	//赋值构造函数
	EquipmentRpcUnEquipReplyWraper(const EquipmentRpcUnEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcUnEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcUnEquipReply ToPB() const
	{
		EquipmentRpcUnEquipReply v;
		v.set_result( m_Result );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
		}
		v.mutable_suit_infos()->Reserve(m_Suit_infos.size());
		for (int i=0; i<(int)m_Suit_infos.size(); i++)
		{
			*v.add_suit_infos() = m_Suit_infos[i].ToPB();
		}
		v.set_slottype( m_SlotType );

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
		EquipmentRpcUnEquipReply pb;
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
	void Init(const EquipmentRpcUnEquipReply& v)
	{
		m_Result = v.result();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));
		m_Suit_infos.clear();
		m_Suit_infos.reserve(v.suit_infos_size());
		for( int i=0; i<v.suit_infos_size(); i++)
			m_Suit_infos.push_back(v.suit_infos(i));
		m_SlotType = v.slottype();

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
	//更新背包s
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}
private:
	//Suit_infos
	vector<SuitInfoWraper> m_Suit_infos;
public:
	int SizeSuit_infos()
	{
		return m_Suit_infos.size();
	}
	const vector<SuitInfoWraper>& GetSuit_infos() const
	{
		return m_Suit_infos;
	}
	SuitInfoWraper GetSuit_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_Suit_infos[Index];
	}
	void SetSuit_infos( const vector<SuitInfoWraper>& v )
	{
		m_Suit_infos=v;
	}
	void ClearSuit_infos( )
	{
		m_Suit_infos.clear();
	}
	void SetSuit_infos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return;
		}
		m_Suit_infos[Index] = v;
	}
	void AddSuit_infos( const SuitInfoWraper& v )
	{
		m_Suit_infos.push_back(v);
	}
private:
	//SlotType
	INT32 m_SlotType;
public:
	void SetSlotType( INT32 v)
	{
		m_SlotType=v;
	}
	INT32 GetSlotType()
	{
		return m_SlotType;
	}
	INT32 GetSlotType() const
	{
		return m_SlotType;
	}

};
//装备请求封装类
class EquipmentRpcEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipAskWraper()
	{
		
		m_Pos = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipAskWraper(const EquipmentRpcEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipAsk ToPB() const
	{
		EquipmentRpcEquipAsk v;
		v.set_pos( m_Pos );

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
		EquipmentRpcEquipAsk pb;
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
	void Init(const EquipmentRpcEquipAsk& v)
	{
		m_Pos = v.pos();

	}

private:
	//背包位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//装备回应封装类
class EquipmentRpcEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipReplyWraper()
	{
		
		m_Result = -9999;
		m_SlotType = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipReplyWraper(const EquipmentRpcEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipReply ToPB() const
	{
		EquipmentRpcEquipReply v;
		v.set_result( m_Result );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
		}
		v.mutable_suit_infos()->Reserve(m_Suit_infos.size());
		for (int i=0; i<(int)m_Suit_infos.size(); i++)
		{
			*v.add_suit_infos() = m_Suit_infos[i].ToPB();
		}
		v.set_slottype( m_SlotType );

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
		EquipmentRpcEquipReply pb;
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
	void Init(const EquipmentRpcEquipReply& v)
	{
		m_Result = v.result();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));
		m_Suit_infos.clear();
		m_Suit_infos.reserve(v.suit_infos_size());
		for( int i=0; i<v.suit_infos_size(); i++)
			m_Suit_infos.push_back(v.suit_infos(i));
		m_SlotType = v.slottype();

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
	//更新背包
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}
private:
	//Suit_infos
	vector<SuitInfoWraper> m_Suit_infos;
public:
	int SizeSuit_infos()
	{
		return m_Suit_infos.size();
	}
	const vector<SuitInfoWraper>& GetSuit_infos() const
	{
		return m_Suit_infos;
	}
	SuitInfoWraper GetSuit_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_Suit_infos[Index];
	}
	void SetSuit_infos( const vector<SuitInfoWraper>& v )
	{
		m_Suit_infos=v;
	}
	void ClearSuit_infos( )
	{
		m_Suit_infos.clear();
	}
	void SetSuit_infos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return;
		}
		m_Suit_infos[Index] = v;
	}
	void AddSuit_infos( const SuitInfoWraper& v )
	{
		m_Suit_infos.push_back(v);
	}
private:
	//SlotType
	INT32 m_SlotType;
public:
	void SetSlotType( INT32 v)
	{
		m_SlotType=v;
	}
	INT32 GetSlotType()
	{
		return m_SlotType;
	}
	INT32 GetSlotType() const
	{
		return m_SlotType;
	}

};
//卸载装备请求封装类
class EquipmentRpcUnEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcUnEquipAskWraper()
	{
		
		m_SlotType = -1;

	}
	//赋值构造函数
	EquipmentRpcUnEquipAskWraper(const EquipmentRpcUnEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcUnEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcUnEquipAsk ToPB() const
	{
		EquipmentRpcUnEquipAsk v;
		v.set_slottype( m_SlotType );

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
		EquipmentRpcUnEquipAsk pb;
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
	void Init(const EquipmentRpcUnEquipAsk& v)
	{
		m_SlotType = v.slottype();

	}

private:
	//装备槽类型
	INT32 m_SlotType;
public:
	void SetSlotType( INT32 v)
	{
		m_SlotType=v;
	}
	INT32 GetSlotType()
	{
		return m_SlotType;
	}
	INT32 GetSlotType() const
	{
		return m_SlotType;
	}

};
//同步装备套装回应封装类
class EquipmentRpcSyncEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcSyncEquipReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	EquipmentRpcSyncEquipReplyWraper(const EquipmentRpcSyncEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcSyncEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcSyncEquipReply ToPB() const
	{
		EquipmentRpcSyncEquipReply v;
		v.set_result( m_Result );
		v.mutable_equip_data()->Reserve(m_Equip_data.size());
		for (int i=0; i<(int)m_Equip_data.size(); i++)
		{
			*v.add_equip_data() = m_Equip_data[i].ToPB();
		}
		v.mutable_suit_infos()->Reserve(m_Suit_infos.size());
		for (int i=0; i<(int)m_Suit_infos.size(); i++)
		{
			*v.add_suit_infos() = m_Suit_infos[i].ToPB();
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
		EquipmentRpcSyncEquipReply pb;
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
	void Init(const EquipmentRpcSyncEquipReply& v)
	{
		m_Result = v.result();
		m_Equip_data.clear();
		m_Equip_data.reserve(v.equip_data_size());
		for( int i=0; i<v.equip_data_size(); i++)
			m_Equip_data.push_back(v.equip_data(i));
		m_Suit_infos.clear();
		m_Suit_infos.reserve(v.suit_infos_size());
		for( int i=0; i<v.suit_infos_size(); i++)
			m_Suit_infos.push_back(v.suit_infos(i));

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
	//装备信息
	vector<ItemDataWraper> m_Equip_data;
public:
	int SizeEquip_data()
	{
		return m_Equip_data.size();
	}
	const vector<ItemDataWraper>& GetEquip_data() const
	{
		return m_Equip_data;
	}
	ItemDataWraper GetEquip_data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Equip_data[Index];
	}
	void SetEquip_data( const vector<ItemDataWraper>& v )
	{
		m_Equip_data=v;
	}
	void ClearEquip_data( )
	{
		m_Equip_data.clear();
	}
	void SetEquip_data( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Equip_data.size())
		{
			assert(false);
			return;
		}
		m_Equip_data[Index] = v;
	}
	void AddEquip_data( const ItemDataWraper& v )
	{
		m_Equip_data.push_back(v);
	}
private:
	//Suit_infos
	vector<SuitInfoWraper> m_Suit_infos;
public:
	int SizeSuit_infos()
	{
		return m_Suit_infos.size();
	}
	const vector<SuitInfoWraper>& GetSuit_infos() const
	{
		return m_Suit_infos;
	}
	SuitInfoWraper GetSuit_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return SuitInfoWraper();
		}
		return m_Suit_infos[Index];
	}
	void SetSuit_infos( const vector<SuitInfoWraper>& v )
	{
		m_Suit_infos=v;
	}
	void ClearSuit_infos( )
	{
		m_Suit_infos.clear();
	}
	void SetSuit_infos( int Index, const SuitInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Suit_infos.size())
		{
			assert(false);
			return;
		}
		m_Suit_infos[Index] = v;
	}
	void AddSuit_infos( const SuitInfoWraper& v )
	{
		m_Suit_infos.push_back(v);
	}

};
//保存共鸣属性请求封装类
class EquipmentRpcEquipResonanceSaveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipResonanceSaveAskWraper()
	{
		
		m_ConfId = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipResonanceSaveAskWraper(const EquipmentRpcEquipResonanceSaveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipResonanceSaveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipResonanceSaveAsk ToPB() const
	{
		EquipmentRpcEquipResonanceSaveAsk v;
		v.set_confid( m_ConfId );

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
		EquipmentRpcEquipResonanceSaveAsk pb;
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
	void Init(const EquipmentRpcEquipResonanceSaveAsk& v)
	{
		m_ConfId = v.confid();

	}

private:
	//Id
	INT32 m_ConfId;
public:
	void SetConfId( INT32 v)
	{
		m_ConfId=v;
	}
	INT32 GetConfId()
	{
		return m_ConfId;
	}
	INT32 GetConfId() const
	{
		return m_ConfId;
	}

};
//保存共鸣属性回应封装类
class EquipmentRpcEquipResonanceSaveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipResonanceSaveReplyWraper()
	{
		
		m_Result = -1;
		m_ResonanceInfo = EquipResonanceInfoWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipResonanceSaveReplyWraper(const EquipmentRpcEquipResonanceSaveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipResonanceSaveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipResonanceSaveReply ToPB() const
	{
		EquipmentRpcEquipResonanceSaveReply v;
		v.set_result( m_Result );
		*v.mutable_resonanceinfo()= m_ResonanceInfo.ToPB();

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
		EquipmentRpcEquipResonanceSaveReply pb;
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
	void Init(const EquipmentRpcEquipResonanceSaveReply& v)
	{
		m_Result = v.result();
		m_ResonanceInfo = v.resonanceinfo();

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
	//最新的数据
	EquipResonanceInfoWraper m_ResonanceInfo;
public:
	void SetResonanceInfo( const EquipResonanceInfoWraper& v)
	{
		m_ResonanceInfo=v;
	}
	EquipResonanceInfoWraper GetResonanceInfo()
	{
		return m_ResonanceInfo;
	}
	EquipResonanceInfoWraper GetResonanceInfo() const
	{
		return m_ResonanceInfo;
	}

};
//初始化请求封装类
class EquipmentRpcEquipResonanceSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipResonanceSyncAskWraper()
	{
		

	}
	//赋值构造函数
	EquipmentRpcEquipResonanceSyncAskWraper(const EquipmentRpcEquipResonanceSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipResonanceSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipResonanceSyncAsk ToPB() const
	{
		EquipmentRpcEquipResonanceSyncAsk v;

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
		EquipmentRpcEquipResonanceSyncAsk pb;
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
	void Init(const EquipmentRpcEquipResonanceSyncAsk& v)
	{

	}


};
//共鸣洗练回应封装类
class EquipmentRpcEquipDoResonanceReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipDoResonanceReplyWraper()
	{
		
		m_Result = -1;
		m_AddAttr = EquipResonanceInfoWraper();

	}
	//赋值构造函数
	EquipmentRpcEquipDoResonanceReplyWraper(const EquipmentRpcEquipDoResonanceReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipDoResonanceReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipDoResonanceReply ToPB() const
	{
		EquipmentRpcEquipDoResonanceReply v;
		v.set_result( m_Result );
		*v.mutable_addattr()= m_AddAttr.ToPB();

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
		EquipmentRpcEquipDoResonanceReply pb;
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
	void Init(const EquipmentRpcEquipDoResonanceReply& v)
	{
		m_Result = v.result();
		m_AddAttr = v.addattr();

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
	//增加的属性
	EquipResonanceInfoWraper m_AddAttr;
public:
	void SetAddAttr( const EquipResonanceInfoWraper& v)
	{
		m_AddAttr=v;
	}
	EquipResonanceInfoWraper GetAddAttr()
	{
		return m_AddAttr;
	}
	EquipResonanceInfoWraper GetAddAttr() const
	{
		return m_AddAttr;
	}

};
//激活共鸣请求封装类
class EquipmentRpcResonanceUnlockAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcResonanceUnlockAskWraper()
	{
		
		m_ConfId = -1;

	}
	//赋值构造函数
	EquipmentRpcResonanceUnlockAskWraper(const EquipmentRpcResonanceUnlockAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcResonanceUnlockAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcResonanceUnlockAsk ToPB() const
	{
		EquipmentRpcResonanceUnlockAsk v;
		v.set_confid( m_ConfId );

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
		EquipmentRpcResonanceUnlockAsk pb;
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
	void Init(const EquipmentRpcResonanceUnlockAsk& v)
	{
		m_ConfId = v.confid();

	}

private:
	//ID
	INT32 m_ConfId;
public:
	void SetConfId( INT32 v)
	{
		m_ConfId=v;
	}
	INT32 GetConfId()
	{
		return m_ConfId;
	}
	INT32 GetConfId() const
	{
		return m_ConfId;
	}

};
//激活共鸣回应封装类
class EquipmentRpcResonanceUnlockReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcResonanceUnlockReplyWraper()
	{
		
		m_Result = -1;
		m_ResonanceInfo = EquipResonanceInfoWraper();

	}
	//赋值构造函数
	EquipmentRpcResonanceUnlockReplyWraper(const EquipmentRpcResonanceUnlockReply& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcResonanceUnlockReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcResonanceUnlockReply ToPB() const
	{
		EquipmentRpcResonanceUnlockReply v;
		v.set_result( m_Result );
		*v.mutable_resonanceinfo()= m_ResonanceInfo.ToPB();

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
		EquipmentRpcResonanceUnlockReply pb;
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
	void Init(const EquipmentRpcResonanceUnlockReply& v)
	{
		m_Result = v.result();
		m_ResonanceInfo = v.resonanceinfo();

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
	//数据
	EquipResonanceInfoWraper m_ResonanceInfo;
public:
	void SetResonanceInfo( const EquipResonanceInfoWraper& v)
	{
		m_ResonanceInfo=v;
	}
	EquipResonanceInfoWraper GetResonanceInfo()
	{
		return m_ResonanceInfo;
	}
	EquipResonanceInfoWraper GetResonanceInfo() const
	{
		return m_ResonanceInfo;
	}

};
//共鸣洗练请求封装类
class EquipmentRpcEquipDoResonanceAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	EquipmentRpcEquipDoResonanceAskWraper()
	{
		
		m_ConfId = -1;

	}
	//赋值构造函数
	EquipmentRpcEquipDoResonanceAskWraper(const EquipmentRpcEquipDoResonanceAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipmentRpcEquipDoResonanceAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipmentRpcEquipDoResonanceAsk ToPB() const
	{
		EquipmentRpcEquipDoResonanceAsk v;
		v.set_confid( m_ConfId );

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
		EquipmentRpcEquipDoResonanceAsk pb;
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
	void Init(const EquipmentRpcEquipDoResonanceAsk& v)
	{
		m_ConfId = v.confid();

	}

private:
	//Id
	INT32 m_ConfId;
public:
	void SetConfId( INT32 v)
	{
		m_ConfId=v;
	}
	INT32 GetConfId()
	{
		return m_ConfId;
	}
	INT32 GetConfId() const
	{
		return m_ConfId;
	}

};

template<typename T> struct MessageIdT;


#endif
