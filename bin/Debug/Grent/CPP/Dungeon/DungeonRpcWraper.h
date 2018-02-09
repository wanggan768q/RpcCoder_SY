/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperDungeon.h
* Author:       郭晓波
* Description:  副本RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DUNGEON_H
#define __RPC_WRAPER_DUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DungeonRpc.pb.h"



//副本类的枚举定义
enum ConstDungeonE
{
	MODULE_ID_DUNGEON                            = 6,	//副本模块ID
	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST       = 651,	//副本-->CreateDungeon-->请求
	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST         = 652,	//副本-->退出副本-->请求
	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST        = 653,	//副本-->进入副本通知-->请求
	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654,	//副本-->队长创建副本以后通知我-->请求
	RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY           = 655,	//副本-->Settlement-->通知


};


//Settlement通知封装类
class DungeonRpcSettlementNotifyWraper
{
public:
	//构造函数
	DungeonRpcSettlementNotifyWraper()
	{
		
		m_SettlementResult = -1;

	}
	//赋值构造函数
	DungeonRpcSettlementNotifyWraper(const DungeonRpcSettlementNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcSettlementNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcSettlementNotify ToPB() const
	{
		DungeonRpcSettlementNotify v;
		v.set_settlementresult( m_SettlementResult );

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
		DungeonRpcSettlementNotify pb;
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
	void Init(const DungeonRpcSettlementNotify& v)
	{
		m_SettlementResult = v.settlementresult();

	}

private:
	//SettlementResult
	INT32 m_SettlementResult;
public:
	void SetSettlementResult( INT32 v)
	{
		m_SettlementResult=v;
	}
	INT32 GetSettlementResult()
	{
		return m_SettlementResult;
	}
	INT32 GetSettlementResult() const
	{
		return m_SettlementResult;
	}

};
//队长创建副本以后通知我回应封装类
class DungeonRpcInformCreateDungeonReplyWraper
{
public:
	//构造函数
	DungeonRpcInformCreateDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	DungeonRpcInformCreateDungeonReplyWraper(const DungeonRpcInformCreateDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcInformCreateDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcInformCreateDungeonReply ToPB() const
	{
		DungeonRpcInformCreateDungeonReply v;
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
		DungeonRpcInformCreateDungeonReply pb;
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
	void Init(const DungeonRpcInformCreateDungeonReply& v)
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
//进入副本通知回应封装类
class DungeonRpcEnterDungeonReplyWraper
{
public:
	//构造函数
	DungeonRpcEnterDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	DungeonRpcEnterDungeonReplyWraper(const DungeonRpcEnterDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcEnterDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcEnterDungeonReply ToPB() const
	{
		DungeonRpcEnterDungeonReply v;
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
		DungeonRpcEnterDungeonReply pb;
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
	void Init(const DungeonRpcEnterDungeonReply& v)
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
//进入副本通知请求封装类
class DungeonRpcEnterDungeonAskWraper
{
public:
	//构造函数
	DungeonRpcEnterDungeonAskWraper()
	{
		
		m_SceneId = -1;
		m_DungeonConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcEnterDungeonAskWraper(const DungeonRpcEnterDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcEnterDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcEnterDungeonAsk ToPB() const
	{
		DungeonRpcEnterDungeonAsk v;
		v.set_sceneid( m_SceneId );
		v.set_dungeonconfigid( m_DungeonConfigId );

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
		DungeonRpcEnterDungeonAsk pb;
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
	void Init(const DungeonRpcEnterDungeonAsk& v)
	{
		m_SceneId = v.sceneid();
		m_DungeonConfigId = v.dungeonconfigid();

	}

private:
	//场景id
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
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}

};
//队长创建副本以后通知我请求封装类
class DungeonRpcInformCreateDungeonAskWraper
{
public:
	//构造函数
	DungeonRpcInformCreateDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_TargetSceneId = -1;
		m_DungeonConfigId = -1;
		m_CurSceneId = -1;
		m_Result = -9999;

	}
	//赋值构造函数
	DungeonRpcInformCreateDungeonAskWraper(const DungeonRpcInformCreateDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcInformCreateDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcInformCreateDungeonAsk ToPB() const
	{
		DungeonRpcInformCreateDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_targetsceneid( m_TargetSceneId );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_cursceneid( m_CurSceneId );
		v.set_result( m_Result );
		v.mutable_roleids()->Reserve(m_RoleIds.size());
		for (int i=0; i<(int)m_RoleIds.size(); i++)
		{
			v.add_roleids(m_RoleIds[i]);
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
		DungeonRpcInformCreateDungeonAsk pb;
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
	void Init(const DungeonRpcInformCreateDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_TargetSceneId = v.targetsceneid();
		m_DungeonConfigId = v.dungeonconfigid();
		m_CurSceneId = v.cursceneid();
		m_Result = v.result();
		m_RoleIds.clear();
		m_RoleIds.reserve(v.roleids_size());
		for( int i=0; i<v.roleids_size(); i++)
			m_RoleIds.push_back(v.roleids(i));

	}

private:
	//玩家的唯一id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//目标场景id
	INT32 m_TargetSceneId;
public:
	void SetTargetSceneId( INT32 v)
	{
		m_TargetSceneId=v;
	}
	INT32 GetTargetSceneId()
	{
		return m_TargetSceneId;
	}
	INT32 GetTargetSceneId() const
	{
		return m_TargetSceneId;
	}
private:
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}
private:
	//队员当前场景
	INT32 m_CurSceneId;
public:
	void SetCurSceneId( INT32 v)
	{
		m_CurSceneId=v;
	}
	INT32 GetCurSceneId()
	{
		return m_CurSceneId;
	}
	INT32 GetCurSceneId() const
	{
		return m_CurSceneId;
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
	//玩家的唯一id
	vector<uint64_t> m_RoleIds;
public:
	int SizeRoleIds()
	{
		return m_RoleIds.size();
	}
	const vector<uint64_t>& GetRoleIds() const
	{
		return m_RoleIds;
	}
	uint64_t GetRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RoleIds[Index];
	}
	void SetRoleIds( const vector<uint64_t>& v )
	{
		m_RoleIds=v;
	}
	void ClearRoleIds( )
	{
		m_RoleIds.clear();
	}
	void SetRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RoleIds.size())
		{
			assert(false);
			return;
		}
		m_RoleIds[Index] = v;
	}
	void AddRoleIds( uint64_t v = 0 )
	{
		m_RoleIds.push_back(v);
	}

};
//CreateDungeon回应封装类
class DungeonRpcCreateDungeonReplyWraper
{
public:
	//构造函数
	DungeonRpcCreateDungeonReplyWraper()
	{
		
		m_Result = -9999;
		m_DungeonConfigId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonReplyWraper(const DungeonRpcCreateDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonReply ToPB() const
	{
		DungeonRpcCreateDungeonReply v;
		v.set_result( m_Result );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_sceneid( m_SceneId );

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
		DungeonRpcCreateDungeonReply pb;
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
	void Init(const DungeonRpcCreateDungeonReply& v)
	{
		m_Result = v.result();
		m_DungeonConfigId = v.dungeonconfigid();
		m_SceneId = v.sceneid();

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
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}
private:
	//场景id
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

};
//CreateDungeon请求封装类
class DungeonRpcCreateDungeonAskWraper
{
public:
	//构造函数
	DungeonRpcCreateDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_DungeonConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonAskWraper(const DungeonRpcCreateDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonAsk ToPB() const
	{
		DungeonRpcCreateDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_dungeonconfigid( m_DungeonConfigId );

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
		DungeonRpcCreateDungeonAsk pb;
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
	void Init(const DungeonRpcCreateDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_DungeonConfigId = v.dungeonconfigid();

	}

private:
	//HumanRoleId
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//副本配置id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}

};
//退出副本回应封装类
class DungeonRpcExitDungeonReplyWraper
{
public:
	//构造函数
	DungeonRpcExitDungeonReplyWraper()
	{
		
		m_Result = -9999;
		m_SceneConfigId = -1;
		m_SceneId = -1;

	}
	//赋值构造函数
	DungeonRpcExitDungeonReplyWraper(const DungeonRpcExitDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcExitDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcExitDungeonReply ToPB() const
	{
		DungeonRpcExitDungeonReply v;
		v.set_result( m_Result );
		v.set_sceneconfigid( m_SceneConfigId );
		v.set_sceneid( m_SceneId );

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
		DungeonRpcExitDungeonReply pb;
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
	void Init(const DungeonRpcExitDungeonReply& v)
	{
		m_Result = v.result();
		m_SceneConfigId = v.sceneconfigid();
		m_SceneId = v.sceneid();

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
	//SceneConfigId
	INT32 m_SceneConfigId;
public:
	void SetSceneConfigId( INT32 v)
	{
		m_SceneConfigId=v;
	}
	INT32 GetSceneConfigId()
	{
		return m_SceneConfigId;
	}
	INT32 GetSceneConfigId() const
	{
		return m_SceneConfigId;
	}
private:
	//场景id
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

};
//退出副本请求封装类
class DungeonRpcExitDungeonAskWraper
{
public:
	//构造函数
	DungeonRpcExitDungeonAskWraper()
	{
		
		m_RoleId = 0;
		m_SceneId = -1;

	}
	//赋值构造函数
	DungeonRpcExitDungeonAskWraper(const DungeonRpcExitDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcExitDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcExitDungeonAsk ToPB() const
	{
		DungeonRpcExitDungeonAsk v;
		v.set_roleid( m_RoleId );
		v.set_sceneid( m_SceneId );

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
		DungeonRpcExitDungeonAsk pb;
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
	void Init(const DungeonRpcExitDungeonAsk& v)
	{
		m_RoleId = v.roleid();
		m_SceneId = v.sceneid();

	}

private:
	//HumanRoleId
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//场景id
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DungeonRpcSettlementNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY};};


#endif
