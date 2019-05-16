/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTreasure.h
* Author:       甘业清
* Description:  珍宝阁RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TREASURE_H
#define __RPC_WRAPER_TREASURE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TreasureRpc.pb.h"



//珍宝阁类的枚举定义
enum ConstTreasureE
{
	MODULE_ID_TREASURE                           = 32,	//珍宝阁模块ID
	RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST  = 3251,	//珍宝阁-->珍宝阁数据-->请求
	RPC_CODE_TREASURE_TREASUREINFO_REQUEST       = 3252,	//珍宝阁-->珍宝数据-->请求
	RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST     = 3253,	//珍宝阁-->珍宝解锁-->请求
	RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST      = 3254,	//珍宝阁-->珍宝穿戴-->请求
	RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST   = 3255,	//珍宝阁-->穿戴的珍宝-->请求
	RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST  = 3256,	//珍宝阁-->珍宝阁升级-->请求
	RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST    = 3257,	//珍宝阁-->卸下珍宝-->请求
	RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY   = 3258,	//珍宝阁-->已装备时装ID-->通知
	RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST  = 3259,	//珍宝阁-->续期-->请求
	RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY = 3260,	//珍宝阁-->解锁并穿戴-->通知


};


//珍宝阁升级回应封装类
class TreasureRpcTreasureDepotLvUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDepotLvUpReplyWraper()
	{
		
		m_Result = -1;
		m_Level = -1;
		m_Point = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureDepotLvUpReplyWraper(const TreasureRpcTreasureDepotLvUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDepotLvUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDepotLvUpReply ToPB() const
	{
		TreasureRpcTreasureDepotLvUpReply v;
		v.set_result( m_Result );
		v.set_level( m_Level );
		v.set_point( m_Point );

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
		TreasureRpcTreasureDepotLvUpReply pb;
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
	void Init(const TreasureRpcTreasureDepotLvUpReply& v)
	{
		m_Result = v.result();
		m_Level = v.level();
		m_Point = v.point();

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
	//珍宝阁等级
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
	//珍宝阁点数
	INT32 m_Point;
public:
	void SetPoint( INT32 v)
	{
		m_Point=v;
	}
	INT32 GetPoint()
	{
		return m_Point;
	}
	INT32 GetPoint() const
	{
		return m_Point;
	}

};
//卸下珍宝请求封装类
class TreasureRpcTreasureUnEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureUnEquipAskWraper()
	{
		
		m_Id = -1;
		m_Color_Type = -1;
		m_Time_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureUnEquipAskWraper(const TreasureRpcTreasureUnEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureUnEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureUnEquipAsk ToPB() const
	{
		TreasureRpcTreasureUnEquipAsk v;
		v.set_id( m_Id );
		v.set_color_type( m_Color_Type );
		v.set_time_type( m_Time_Type );

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
		TreasureRpcTreasureUnEquipAsk pb;
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
	void Init(const TreasureRpcTreasureUnEquipAsk& v)
	{
		m_Id = v.id();
		m_Color_Type = v.color_type();
		m_Time_Type = v.time_type();

	}

private:
	//珍宝ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//颜色类型
	INT32 m_Color_Type;
public:
	void SetColor_Type( INT32 v)
	{
		m_Color_Type=v;
	}
	INT32 GetColor_Type()
	{
		return m_Color_Type;
	}
	INT32 GetColor_Type() const
	{
		return m_Color_Type;
	}
private:
	//时限类型
	INT32 m_Time_Type;
public:
	void SetTime_Type( INT32 v)
	{
		m_Time_Type=v;
	}
	INT32 GetTime_Type()
	{
		return m_Time_Type;
	}
	INT32 GetTime_Type() const
	{
		return m_Time_Type;
	}

};
//穿戴的珍宝回应封装类
class TreasureRpcTreasureEquipSycReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureEquipSycReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureEquipSycReplyWraper(const TreasureRpcTreasureEquipSycReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureEquipSycReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureEquipSycReply ToPB() const
	{
		TreasureRpcTreasureEquipSycReply v;
		v.set_result( m_Result );
		v.mutable_treasueequiped()->Reserve(m_TreasueEquiped.size());
		for (int i=0; i<(int)m_TreasueEquiped.size(); i++)
		{
			*v.add_treasueequiped() = m_TreasueEquiped[i].ToPB();
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
		TreasureRpcTreasureEquipSycReply pb;
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
	void Init(const TreasureRpcTreasureEquipSycReply& v)
	{
		m_Result = v.result();
		m_TreasueEquiped.clear();
		m_TreasueEquiped.reserve(v.treasueequiped_size());
		for( int i=0; i<v.treasueequiped_size(); i++)
			m_TreasueEquiped.push_back(v.treasueequiped(i));

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
	//穿戴的珍宝信息
	vector<TreasureDataWraper> m_TreasueEquiped;
public:
	int SizeTreasueEquiped()
	{
		return m_TreasueEquiped.size();
	}
	const vector<TreasureDataWraper>& GetTreasueEquiped() const
	{
		return m_TreasueEquiped;
	}
	TreasureDataWraper GetTreasueEquiped(int Index) const
	{
		if(Index<0 || Index>=(int)m_TreasueEquiped.size())
		{
			assert(false);
			return TreasureDataWraper();
		}
		return m_TreasueEquiped[Index];
	}
	void SetTreasueEquiped( const vector<TreasureDataWraper>& v )
	{
		m_TreasueEquiped=v;
	}
	void ClearTreasueEquiped( )
	{
		m_TreasueEquiped.clear();
	}
	void SetTreasueEquiped( int Index, const TreasureDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_TreasueEquiped.size())
		{
			assert(false);
			return;
		}
		m_TreasueEquiped[Index] = v;
	}
	void AddTreasueEquiped( const TreasureDataWraper& v )
	{
		m_TreasueEquiped.push_back(v);
	}

};
//珍宝阁升级请求封装类
class TreasureRpcTreasureDepotLvUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDepotLvUpAskWraper()
	{
		

	}
	//赋值构造函数
	TreasureRpcTreasureDepotLvUpAskWraper(const TreasureRpcTreasureDepotLvUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDepotLvUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDepotLvUpAsk ToPB() const
	{
		TreasureRpcTreasureDepotLvUpAsk v;

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
		TreasureRpcTreasureDepotLvUpAsk pb;
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
	void Init(const TreasureRpcTreasureDepotLvUpAsk& v)
	{

	}


};
//卸下珍宝回应封装类
class TreasureRpcTreasureUnEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureUnEquipReplyWraper()
	{
		
		m_Result = -1;
		m_TreasureUnequiped = TreasureDataWraper();
		m_TreasureEquiped = TreasureDataWraper();

	}
	//赋值构造函数
	TreasureRpcTreasureUnEquipReplyWraper(const TreasureRpcTreasureUnEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureUnEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureUnEquipReply ToPB() const
	{
		TreasureRpcTreasureUnEquipReply v;
		v.set_result( m_Result );
		*v.mutable_treasureunequiped()= m_TreasureUnequiped.ToPB();
		*v.mutable_treasureequiped()= m_TreasureEquiped.ToPB();

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
		TreasureRpcTreasureUnEquipReply pb;
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
	void Init(const TreasureRpcTreasureUnEquipReply& v)
	{
		m_Result = v.result();
		m_TreasureUnequiped = v.treasureunequiped();
		m_TreasureEquiped = v.treasureequiped();

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
	//卸下的珍宝
	TreasureDataWraper m_TreasureUnequiped;
public:
	void SetTreasureUnequiped( const TreasureDataWraper& v)
	{
		m_TreasureUnequiped=v;
	}
	TreasureDataWraper GetTreasureUnequiped()
	{
		return m_TreasureUnequiped;
	}
	TreasureDataWraper GetTreasureUnequiped() const
	{
		return m_TreasureUnequiped;
	}
private:
	//穿上的默认时装
	TreasureDataWraper m_TreasureEquiped;
public:
	void SetTreasureEquiped( const TreasureDataWraper& v)
	{
		m_TreasureEquiped=v;
	}
	TreasureDataWraper GetTreasureEquiped()
	{
		return m_TreasureEquiped;
	}
	TreasureDataWraper GetTreasureEquiped() const
	{
		return m_TreasureEquiped;
	}

};
//续期回应封装类
class TreasureRpcTreasureDelayTimeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDelayTimeReplyWraper()
	{
		
		m_Result = -1;
		m_TreasureUnLocked = TreasureDataWraper();
		m_Points = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureDelayTimeReplyWraper(const TreasureRpcTreasureDelayTimeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDelayTimeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDelayTimeReply ToPB() const
	{
		TreasureRpcTreasureDelayTimeReply v;
		v.set_result( m_Result );
		*v.mutable_treasureunlocked()= m_TreasureUnLocked.ToPB();
		v.set_points( m_Points );

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
		TreasureRpcTreasureDelayTimeReply pb;
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
	void Init(const TreasureRpcTreasureDelayTimeReply& v)
	{
		m_Result = v.result();
		m_TreasureUnLocked = v.treasureunlocked();
		m_Points = v.points();

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
	//已解锁的珍宝
	TreasureDataWraper m_TreasureUnLocked;
public:
	void SetTreasureUnLocked( const TreasureDataWraper& v)
	{
		m_TreasureUnLocked=v;
	}
	TreasureDataWraper GetTreasureUnLocked()
	{
		return m_TreasureUnLocked;
	}
	TreasureDataWraper GetTreasureUnLocked() const
	{
		return m_TreasureUnLocked;
	}
private:
	//珍宝阁点数
	INT32 m_Points;
public:
	void SetPoints( INT32 v)
	{
		m_Points=v;
	}
	INT32 GetPoints()
	{
		return m_Points;
	}
	INT32 GetPoints() const
	{
		return m_Points;
	}

};
//解锁并穿戴通知封装类
class TreasureRpcTreasureUnlockEquipNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureUnlockEquipNotifyWraper()
	{
		
		m_Result = -1;
		m_TreasureEquiped = TreasureDataWraper();
		m_TreasureUnequiped = TreasureDataWraper();
		m_Points = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureUnlockEquipNotifyWraper(const TreasureRpcTreasureUnlockEquipNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureUnlockEquipNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureUnlockEquipNotify ToPB() const
	{
		TreasureRpcTreasureUnlockEquipNotify v;
		v.set_result( m_Result );
		*v.mutable_treasureequiped()= m_TreasureEquiped.ToPB();
		*v.mutable_treasureunequiped()= m_TreasureUnequiped.ToPB();
		v.set_points( m_Points );

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
		TreasureRpcTreasureUnlockEquipNotify pb;
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
	void Init(const TreasureRpcTreasureUnlockEquipNotify& v)
	{
		m_Result = v.result();
		m_TreasureEquiped = v.treasureequiped();
		m_TreasureUnequiped = v.treasureunequiped();
		m_Points = v.points();

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
	//穿戴的珍宝
	TreasureDataWraper m_TreasureEquiped;
public:
	void SetTreasureEquiped( const TreasureDataWraper& v)
	{
		m_TreasureEquiped=v;
	}
	TreasureDataWraper GetTreasureEquiped()
	{
		return m_TreasureEquiped;
	}
	TreasureDataWraper GetTreasureEquiped() const
	{
		return m_TreasureEquiped;
	}
private:
	//脱掉的珍宝
	TreasureDataWraper m_TreasureUnequiped;
public:
	void SetTreasureUnequiped( const TreasureDataWraper& v)
	{
		m_TreasureUnequiped=v;
	}
	TreasureDataWraper GetTreasureUnequiped()
	{
		return m_TreasureUnequiped;
	}
	TreasureDataWraper GetTreasureUnequiped() const
	{
		return m_TreasureUnequiped;
	}
private:
	//珍宝阁点数
	INT32 m_Points;
public:
	void SetPoints( INT32 v)
	{
		m_Points=v;
	}
	INT32 GetPoints()
	{
		return m_Points;
	}
	INT32 GetPoints() const
	{
		return m_Points;
	}

};
//已装备时装ID通知封装类
class TreasureRpcTreasureEquipedIDNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureEquipedIDNotifyWraper()
	{
		
		m_TreasureID = TreasureEquipedIDWraper();
		m_ObjID = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureEquipedIDNotifyWraper(const TreasureRpcTreasureEquipedIDNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureEquipedIDNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureEquipedIDNotify ToPB() const
	{
		TreasureRpcTreasureEquipedIDNotify v;
		*v.mutable_treasureid()= m_TreasureID.ToPB();
		v.set_objid( m_ObjID );

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
		TreasureRpcTreasureEquipedIDNotify pb;
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
	void Init(const TreasureRpcTreasureEquipedIDNotify& v)
	{
		m_TreasureID = v.treasureid();
		m_ObjID = v.objid();

	}

private:
	//装备的时装ID
	TreasureEquipedIDWraper m_TreasureID;
public:
	void SetTreasureID( const TreasureEquipedIDWraper& v)
	{
		m_TreasureID=v;
	}
	TreasureEquipedIDWraper GetTreasureID()
	{
		return m_TreasureID;
	}
	TreasureEquipedIDWraper GetTreasureID() const
	{
		return m_TreasureID;
	}
private:
	//objid
	INT32 m_ObjID;
public:
	void SetObjID( INT32 v)
	{
		m_ObjID=v;
	}
	INT32 GetObjID()
	{
		return m_ObjID;
	}
	INT32 GetObjID() const
	{
		return m_ObjID;
	}

};
//续期请求封装类
class TreasureRpcTreasureDelayTimeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDelayTimeAskWraper()
	{
		
		m_Id = -1;
		m_Color_Type = -1;
		m_Time_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureDelayTimeAskWraper(const TreasureRpcTreasureDelayTimeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDelayTimeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDelayTimeAsk ToPB() const
	{
		TreasureRpcTreasureDelayTimeAsk v;
		v.set_id( m_Id );
		v.set_color_type( m_Color_Type );
		v.set_time_type( m_Time_Type );

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
		TreasureRpcTreasureDelayTimeAsk pb;
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
	void Init(const TreasureRpcTreasureDelayTimeAsk& v)
	{
		m_Id = v.id();
		m_Color_Type = v.color_type();
		m_Time_Type = v.time_type();

	}

private:
	//珍宝ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//附加颜色类型
	INT32 m_Color_Type;
public:
	void SetColor_Type( INT32 v)
	{
		m_Color_Type=v;
	}
	INT32 GetColor_Type()
	{
		return m_Color_Type;
	}
	INT32 GetColor_Type() const
	{
		return m_Color_Type;
	}
private:
	//时限类型
	INT32 m_Time_Type;
public:
	void SetTime_Type( INT32 v)
	{
		m_Time_Type=v;
	}
	INT32 GetTime_Type()
	{
		return m_Time_Type;
	}
	INT32 GetTime_Type() const
	{
		return m_Time_Type;
	}

};
//珍宝数据请求封装类
class TreasureRpcTreasureInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureInfoAskWraper()
	{
		
		m_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureInfoAskWraper(const TreasureRpcTreasureInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureInfoAsk ToPB() const
	{
		TreasureRpcTreasureInfoAsk v;
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
		TreasureRpcTreasureInfoAsk pb;
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
	void Init(const TreasureRpcTreasureInfoAsk& v)
	{
		m_Type = v.type();

	}

private:
	//珍宝类型
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
//珍宝数据回应封装类
class TreasureRpcTreasureInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureInfoReplyWraper()
	{
		
		m_Result = -1;
		m_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureInfoReplyWraper(const TreasureRpcTreasureInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureInfoReply ToPB() const
	{
		TreasureRpcTreasureInfoReply v;
		v.set_result( m_Result );
		v.mutable_treasure_info()->Reserve(m_Treasure_Info.size());
		for (int i=0; i<(int)m_Treasure_Info.size(); i++)
		{
			*v.add_treasure_info() = m_Treasure_Info[i].ToPB();
		}
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
		TreasureRpcTreasureInfoReply pb;
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
	void Init(const TreasureRpcTreasureInfoReply& v)
	{
		m_Result = v.result();
		m_Treasure_Info.clear();
		m_Treasure_Info.reserve(v.treasure_info_size());
		for( int i=0; i<v.treasure_info_size(); i++)
			m_Treasure_Info.push_back(v.treasure_info(i));
		m_Type = v.type();

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
	//珍宝数据
	vector<TreasureDataWraper> m_Treasure_Info;
public:
	int SizeTreasure_Info()
	{
		return m_Treasure_Info.size();
	}
	const vector<TreasureDataWraper>& GetTreasure_Info() const
	{
		return m_Treasure_Info;
	}
	TreasureDataWraper GetTreasure_Info(int Index) const
	{
		if(Index<0 || Index>=(int)m_Treasure_Info.size())
		{
			assert(false);
			return TreasureDataWraper();
		}
		return m_Treasure_Info[Index];
	}
	void SetTreasure_Info( const vector<TreasureDataWraper>& v )
	{
		m_Treasure_Info=v;
	}
	void ClearTreasure_Info( )
	{
		m_Treasure_Info.clear();
	}
	void SetTreasure_Info( int Index, const TreasureDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Treasure_Info.size())
		{
			assert(false);
			return;
		}
		m_Treasure_Info[Index] = v;
	}
	void AddTreasure_Info( const TreasureDataWraper& v )
	{
		m_Treasure_Info.push_back(v);
	}
private:
	//珍宝类型
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
//珍宝阁数据请求封装类
class TreasureRpcTreasureDepotInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDepotInfoAskWraper()
	{
		

	}
	//赋值构造函数
	TreasureRpcTreasureDepotInfoAskWraper(const TreasureRpcTreasureDepotInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDepotInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDepotInfoAsk ToPB() const
	{
		TreasureRpcTreasureDepotInfoAsk v;

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
		TreasureRpcTreasureDepotInfoAsk pb;
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
	void Init(const TreasureRpcTreasureDepotInfoAsk& v)
	{

	}


};
//珍宝阁数据回应封装类
class TreasureRpcTreasureDepotInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureDepotInfoReplyWraper()
	{
		
		m_Result = -1;
		m_Level = 1;
		m_Point = 0;

	}
	//赋值构造函数
	TreasureRpcTreasureDepotInfoReplyWraper(const TreasureRpcTreasureDepotInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureDepotInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureDepotInfoReply ToPB() const
	{
		TreasureRpcTreasureDepotInfoReply v;
		v.set_result( m_Result );
		v.set_level( m_Level );
		v.set_point( m_Point );

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
		TreasureRpcTreasureDepotInfoReply pb;
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
	void Init(const TreasureRpcTreasureDepotInfoReply& v)
	{
		m_Result = v.result();
		m_Level = v.level();
		m_Point = v.point();

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
	//珍宝阁等级
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
	//珍宝阁点数
	INT32 m_Point;
public:
	void SetPoint( INT32 v)
	{
		m_Point=v;
	}
	INT32 GetPoint()
	{
		return m_Point;
	}
	INT32 GetPoint() const
	{
		return m_Point;
	}

};
//珍宝解锁请求封装类
class TreasureRpcTreasureUnlockAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureUnlockAskWraper()
	{
		
		m_Id = -1;
		m_Color_Type = -1;
		m_Time_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureUnlockAskWraper(const TreasureRpcTreasureUnlockAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureUnlockAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureUnlockAsk ToPB() const
	{
		TreasureRpcTreasureUnlockAsk v;
		v.set_id( m_Id );
		v.set_color_type( m_Color_Type );
		v.set_time_type( m_Time_Type );

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
		TreasureRpcTreasureUnlockAsk pb;
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
	void Init(const TreasureRpcTreasureUnlockAsk& v)
	{
		m_Id = v.id();
		m_Color_Type = v.color_type();
		m_Time_Type = v.time_type();

	}

private:
	//珍宝ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//附加颜色类型
	INT32 m_Color_Type;
public:
	void SetColor_Type( INT32 v)
	{
		m_Color_Type=v;
	}
	INT32 GetColor_Type()
	{
		return m_Color_Type;
	}
	INT32 GetColor_Type() const
	{
		return m_Color_Type;
	}
private:
	//时限类型
	INT32 m_Time_Type;
public:
	void SetTime_Type( INT32 v)
	{
		m_Time_Type=v;
	}
	INT32 GetTime_Type()
	{
		return m_Time_Type;
	}
	INT32 GetTime_Type() const
	{
		return m_Time_Type;
	}

};
//珍宝穿戴回应封装类
class TreasureRpcTreasureEquipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureEquipReplyWraper()
	{
		
		m_Result = -1;
		m_TreasureEquiped = TreasureDataWraper();
		m_TreasureUnequiped = TreasureDataWraper();

	}
	//赋值构造函数
	TreasureRpcTreasureEquipReplyWraper(const TreasureRpcTreasureEquipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureEquipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureEquipReply ToPB() const
	{
		TreasureRpcTreasureEquipReply v;
		v.set_result( m_Result );
		*v.mutable_treasureequiped()= m_TreasureEquiped.ToPB();
		*v.mutable_treasureunequiped()= m_TreasureUnequiped.ToPB();

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
		TreasureRpcTreasureEquipReply pb;
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
	void Init(const TreasureRpcTreasureEquipReply& v)
	{
		m_Result = v.result();
		m_TreasureEquiped = v.treasureequiped();
		m_TreasureUnequiped = v.treasureunequiped();

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
	//穿戴的珍宝
	TreasureDataWraper m_TreasureEquiped;
public:
	void SetTreasureEquiped( const TreasureDataWraper& v)
	{
		m_TreasureEquiped=v;
	}
	TreasureDataWraper GetTreasureEquiped()
	{
		return m_TreasureEquiped;
	}
	TreasureDataWraper GetTreasureEquiped() const
	{
		return m_TreasureEquiped;
	}
private:
	//脱掉的珍宝
	TreasureDataWraper m_TreasureUnequiped;
public:
	void SetTreasureUnequiped( const TreasureDataWraper& v)
	{
		m_TreasureUnequiped=v;
	}
	TreasureDataWraper GetTreasureUnequiped()
	{
		return m_TreasureUnequiped;
	}
	TreasureDataWraper GetTreasureUnequiped() const
	{
		return m_TreasureUnequiped;
	}

};
//穿戴的珍宝请求封装类
class TreasureRpcTreasureEquipSycAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureEquipSycAskWraper()
	{
		

	}
	//赋值构造函数
	TreasureRpcTreasureEquipSycAskWraper(const TreasureRpcTreasureEquipSycAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureEquipSycAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureEquipSycAsk ToPB() const
	{
		TreasureRpcTreasureEquipSycAsk v;

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
		TreasureRpcTreasureEquipSycAsk pb;
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
	void Init(const TreasureRpcTreasureEquipSycAsk& v)
	{

	}


};
//珍宝解锁回应封装类
class TreasureRpcTreasureUnlockReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureUnlockReplyWraper()
	{
		
		m_Result = -1;
		m_TreasureUnLocked = TreasureDataWraper();
		m_Points = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureUnlockReplyWraper(const TreasureRpcTreasureUnlockReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureUnlockReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureUnlockReply ToPB() const
	{
		TreasureRpcTreasureUnlockReply v;
		v.set_result( m_Result );
		*v.mutable_treasureunlocked()= m_TreasureUnLocked.ToPB();
		v.set_points( m_Points );

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
		TreasureRpcTreasureUnlockReply pb;
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
	void Init(const TreasureRpcTreasureUnlockReply& v)
	{
		m_Result = v.result();
		m_TreasureUnLocked = v.treasureunlocked();
		m_Points = v.points();

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
	//已解锁的珍宝
	TreasureDataWraper m_TreasureUnLocked;
public:
	void SetTreasureUnLocked( const TreasureDataWraper& v)
	{
		m_TreasureUnLocked=v;
	}
	TreasureDataWraper GetTreasureUnLocked()
	{
		return m_TreasureUnLocked;
	}
	TreasureDataWraper GetTreasureUnLocked() const
	{
		return m_TreasureUnLocked;
	}
private:
	//珍宝阁点数
	INT32 m_Points;
public:
	void SetPoints( INT32 v)
	{
		m_Points=v;
	}
	INT32 GetPoints()
	{
		return m_Points;
	}
	INT32 GetPoints() const
	{
		return m_Points;
	}

};
//珍宝穿戴请求封装类
class TreasureRpcTreasureEquipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TreasureRpcTreasureEquipAskWraper()
	{
		
		m_Id = -1;
		m_Color_Type = -1;
		m_Time_Type = -1;

	}
	//赋值构造函数
	TreasureRpcTreasureEquipAskWraper(const TreasureRpcTreasureEquipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureRpcTreasureEquipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureRpcTreasureEquipAsk ToPB() const
	{
		TreasureRpcTreasureEquipAsk v;
		v.set_id( m_Id );
		v.set_color_type( m_Color_Type );
		v.set_time_type( m_Time_Type );

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
		TreasureRpcTreasureEquipAsk pb;
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
	void Init(const TreasureRpcTreasureEquipAsk& v)
	{
		m_Id = v.id();
		m_Color_Type = v.color_type();
		m_Time_Type = v.time_type();

	}

private:
	//珍宝ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//珍宝颜色类型
	INT32 m_Color_Type;
public:
	void SetColor_Type( INT32 v)
	{
		m_Color_Type=v;
	}
	INT32 GetColor_Type()
	{
		return m_Color_Type;
	}
	INT32 GetColor_Type() const
	{
		return m_Color_Type;
	}
private:
	//时限类型
	INT32 m_Time_Type;
public:
	void SetTime_Type( INT32 v)
	{
		m_Time_Type=v;
	}
	INT32 GetTime_Type()
	{
		return m_Time_Type;
	}
	INT32 GetTime_Type() const
	{
		return m_Time_Type;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TreasureRpcTreasureEquipedIDNotifyWraper>{ enum{ID=RPC_CODE_TREASURE_TREASUREEQUIPEDID_NOTIFY};};
template<> struct MessageIdT<TreasureRpcTreasureUnlockEquipNotifyWraper>{ enum{ID=RPC_CODE_TREASURE_TREASUREUNLOCKEQUIP_NOTIFY};};


#endif
