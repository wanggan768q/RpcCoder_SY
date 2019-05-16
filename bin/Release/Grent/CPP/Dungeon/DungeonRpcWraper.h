/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperDungeon.h
* Author:       甘业清
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
	RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY          = 656,	//副本-->战况信息-->通知
	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST         = 657,	//副本-->副本数据请求-->请求
	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST     = 658,	//副本-->副本挑战信息-->请求
	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST      = 659,	//副本-->创建序章副本-->请求
	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST        = 660,	//副本-->强制退出序章-->请求
	RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY        = 661,	//副本-->副本目标-->通知
	RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY  = 662,	//副本-->副本子任务完成情况-->通知
	RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY       = 663,	//副本-->副本提示-->通知


};


//创建序章副本请求封装类
class DungeonRpcCreateTutorialAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcCreateTutorialAskWraper()
	{
		
		m_RoleId = 0;
		m_DungeonConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateTutorialAskWraper(const DungeonRpcCreateTutorialAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateTutorialAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateTutorialAsk ToPB() const
	{
		DungeonRpcCreateTutorialAsk v;
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
		DungeonRpcCreateTutorialAsk pb;
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
	void Init(const DungeonRpcCreateTutorialAsk& v)
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
//创建序章副本回应封装类
class DungeonRpcCreateTutorialReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcCreateTutorialReplyWraper()
	{
		
		m_Result = -1;
		m_DungeonConfigId = -1;
		m_SceneConfigId = -1;

	}
	//赋值构造函数
	DungeonRpcCreateTutorialReplyWraper(const DungeonRpcCreateTutorialReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateTutorialReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateTutorialReply ToPB() const
	{
		DungeonRpcCreateTutorialReply v;
		v.set_result( m_Result );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_sceneconfigid( m_SceneConfigId );

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
		DungeonRpcCreateTutorialReply pb;
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
	void Init(const DungeonRpcCreateTutorialReply& v)
	{
		m_Result = v.result();
		m_DungeonConfigId = v.dungeonconfigid();
		m_SceneConfigId = v.sceneconfigid();

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

};
//副本挑战信息回应封装类
class DungeonRpcDungeonListInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonListInfoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	DungeonRpcDungeonListInfoReplyWraper(const DungeonRpcDungeonListInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonListInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonListInfoReply ToPB() const
	{
		DungeonRpcDungeonListInfoReply v;
		v.set_result( m_Result );
		v.mutable_dungeonbossdata()->Reserve(m_DungeonBossData.size());
		for (int i=0; i<(int)m_DungeonBossData.size(); i++)
		{
			*v.add_dungeonbossdata() = m_DungeonBossData[i].ToPB();
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
		DungeonRpcDungeonListInfoReply pb;
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
	void Init(const DungeonRpcDungeonListInfoReply& v)
	{
		m_Result = v.result();
		m_DungeonBossData.clear();
		m_DungeonBossData.reserve(v.dungeonbossdata_size());
		for( int i=0; i<v.dungeonbossdata_size(); i++)
			m_DungeonBossData.push_back(v.dungeonbossdata(i));

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
	//副本BOSS挑战数据
	vector<DungeonBossInfoWraper> m_DungeonBossData;
public:
	int SizeDungeonBossData()
	{
		return m_DungeonBossData.size();
	}
	const vector<DungeonBossInfoWraper>& GetDungeonBossData() const
	{
		return m_DungeonBossData;
	}
	DungeonBossInfoWraper GetDungeonBossData(int Index) const
	{
		if(Index<0 || Index>=(int)m_DungeonBossData.size())
		{
			assert(false);
			return DungeonBossInfoWraper();
		}
		return m_DungeonBossData[Index];
	}
	void SetDungeonBossData( const vector<DungeonBossInfoWraper>& v )
	{
		m_DungeonBossData=v;
	}
	void ClearDungeonBossData( )
	{
		m_DungeonBossData.clear();
	}
	void SetDungeonBossData( int Index, const DungeonBossInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_DungeonBossData.size())
		{
			assert(false);
			return;
		}
		m_DungeonBossData[Index] = v;
	}
	void AddDungeonBossData( const DungeonBossInfoWraper& v )
	{
		m_DungeonBossData.push_back(v);
	}

};
//副本数据请求回应封装类
class DungeonRpcDungeonSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonSyncReplyWraper()
	{
		
		m_Result = -1;
		m_Data = DungeonDataWraper();

	}
	//赋值构造函数
	DungeonRpcDungeonSyncReplyWraper(const DungeonRpcDungeonSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonSyncReply ToPB() const
	{
		DungeonRpcDungeonSyncReply v;
		v.set_result( m_Result );
		*v.mutable_data()= m_Data.ToPB();

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
		DungeonRpcDungeonSyncReply pb;
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
	void Init(const DungeonRpcDungeonSyncReply& v)
	{
		m_Result = v.result();
		m_Data = v.data();

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
	//副本数据
	DungeonDataWraper m_Data;
public:
	void SetData( const DungeonDataWraper& v)
	{
		m_Data=v;
	}
	DungeonDataWraper GetData()
	{
		return m_Data;
	}
	DungeonDataWraper GetData() const
	{
		return m_Data;
	}

};
//副本挑战信息请求封装类
class DungeonRpcDungeonListInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonListInfoAskWraper()
	{
		

	}
	//赋值构造函数
	DungeonRpcDungeonListInfoAskWraper(const DungeonRpcDungeonListInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonListInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonListInfoAsk ToPB() const
	{
		DungeonRpcDungeonListInfoAsk v;

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
		DungeonRpcDungeonListInfoAsk pb;
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
	void Init(const DungeonRpcDungeonListInfoAsk& v)
	{

	}


};
//副本子任务完成情况通知封装类
class DungeonRpcTargetContentChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcTargetContentChangeNotifyWraper()
	{
		
		m_Index = -1;
		m_SubIndex = -1;
		m_CurCount = -1;

	}
	//赋值构造函数
	DungeonRpcTargetContentChangeNotifyWraper(const DungeonRpcTargetContentChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcTargetContentChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcTargetContentChangeNotify ToPB() const
	{
		DungeonRpcTargetContentChangeNotify v;
		v.set_index( m_Index );
		v.set_subindex( m_SubIndex );
		v.set_curcount( m_CurCount );

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
		DungeonRpcTargetContentChangeNotify pb;
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
	void Init(const DungeonRpcTargetContentChangeNotify& v)
	{
		m_Index = v.index();
		m_SubIndex = v.subindex();
		m_CurCount = v.curcount();

	}

private:
	//目标序号
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}
private:
	//子任务序号
	INT32 m_SubIndex;
public:
	void SetSubIndex( INT32 v)
	{
		m_SubIndex=v;
	}
	INT32 GetSubIndex()
	{
		return m_SubIndex;
	}
	INT32 GetSubIndex() const
	{
		return m_SubIndex;
	}
private:
	//当前完成情况
	INT32 m_CurCount;
public:
	void SetCurCount( INT32 v)
	{
		m_CurCount=v;
	}
	INT32 GetCurCount()
	{
		return m_CurCount;
	}
	INT32 GetCurCount() const
	{
		return m_CurCount;
	}

};
//副本提示通知封装类
class DungeonRpcDungeon_NotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeon_NotifyNotifyWraper()
	{
		
		m_TextId = -1;

	}
	//赋值构造函数
	DungeonRpcDungeon_NotifyNotifyWraper(const DungeonRpcDungeon_NotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeon_NotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeon_NotifyNotify ToPB() const
	{
		DungeonRpcDungeon_NotifyNotify v;
		v.set_textid( m_TextId );

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
		DungeonRpcDungeon_NotifyNotify pb;
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
	void Init(const DungeonRpcDungeon_NotifyNotify& v)
	{
		m_TextId = v.textid();

	}

private:
	//副本提示id
	INT32 m_TextId;
public:
	void SetTextId( INT32 v)
	{
		m_TextId=v;
	}
	INT32 GetTextId()
	{
		return m_TextId;
	}
	INT32 GetTextId() const
	{
		return m_TextId;
	}

};
//副本目标通知封装类
class DungeonRpcDungeonTargetNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonTargetNotifyWraper()
	{
		

	}
	//赋值构造函数
	DungeonRpcDungeonTargetNotifyWraper(const DungeonRpcDungeonTargetNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonTargetNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonTargetNotify ToPB() const
	{
		DungeonRpcDungeonTargetNotify v;
		v.mutable_dungeontarget()->Reserve(m_DungeonTarget.size());
		for (int i=0; i<(int)m_DungeonTarget.size(); i++)
		{
			*v.add_dungeontarget() = m_DungeonTarget[i].ToPB();
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
		DungeonRpcDungeonTargetNotify pb;
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
	void Init(const DungeonRpcDungeonTargetNotify& v)
	{
		m_DungeonTarget.clear();
		m_DungeonTarget.reserve(v.dungeontarget_size());
		for( int i=0; i<v.dungeontarget_size(); i++)
			m_DungeonTarget.push_back(v.dungeontarget(i));

	}

private:
	//DungeonTarget
	vector<DungeonTargetWraper> m_DungeonTarget;
public:
	int SizeDungeonTarget()
	{
		return m_DungeonTarget.size();
	}
	const vector<DungeonTargetWraper>& GetDungeonTarget() const
	{
		return m_DungeonTarget;
	}
	DungeonTargetWraper GetDungeonTarget(int Index) const
	{
		if(Index<0 || Index>=(int)m_DungeonTarget.size())
		{
			assert(false);
			return DungeonTargetWraper();
		}
		return m_DungeonTarget[Index];
	}
	void SetDungeonTarget( const vector<DungeonTargetWraper>& v )
	{
		m_DungeonTarget=v;
	}
	void ClearDungeonTarget( )
	{
		m_DungeonTarget.clear();
	}
	void SetDungeonTarget( int Index, const DungeonTargetWraper& v )
	{
		if(Index<0 || Index>=(int)m_DungeonTarget.size())
		{
			assert(false);
			return;
		}
		m_DungeonTarget[Index] = v;
	}
	void AddDungeonTarget( const DungeonTargetWraper& v )
	{
		m_DungeonTarget.push_back(v);
	}

};
//强制退出序章请求封装类
class DungeonRpcQuitTutorialAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcQuitTutorialAskWraper()
	{
		

	}
	//赋值构造函数
	DungeonRpcQuitTutorialAskWraper(const DungeonRpcQuitTutorialAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcQuitTutorialAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcQuitTutorialAsk ToPB() const
	{
		DungeonRpcQuitTutorialAsk v;

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
		DungeonRpcQuitTutorialAsk pb;
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
	void Init(const DungeonRpcQuitTutorialAsk& v)
	{

	}


};
//强制退出序章回应封装类
class DungeonRpcQuitTutorialReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcQuitTutorialReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	DungeonRpcQuitTutorialReplyWraper(const DungeonRpcQuitTutorialReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcQuitTutorialReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcQuitTutorialReply ToPB() const
	{
		DungeonRpcQuitTutorialReply v;
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
		DungeonRpcQuitTutorialReply pb;
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
	void Init(const DungeonRpcQuitTutorialReply& v)
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
//副本数据请求请求封装类
class DungeonRpcDungeonSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonSyncAskWraper()
	{
		

	}
	//赋值构造函数
	DungeonRpcDungeonSyncAskWraper(const DungeonRpcDungeonSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonSyncAsk ToPB() const
	{
		DungeonRpcDungeonSyncAsk v;

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
		DungeonRpcDungeonSyncAsk pb;
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
	void Init(const DungeonRpcDungeonSyncAsk& v)
	{

	}


};
//退出副本回应封装类
class DungeonRpcExitDungeonReplyWraper : public DataWraperInterface 
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
//队长创建副本以后通知我请求封装类
class DungeonRpcInformCreateDungeonAskWraper : public DataWraperInterface 
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
//退出副本请求封装类
class DungeonRpcExitDungeonAskWraper : public DataWraperInterface 
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
//CreateDungeon请求封装类
class DungeonRpcCreateDungeonAskWraper : public DataWraperInterface 
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
//CreateDungeon回应封装类
class DungeonRpcCreateDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcCreateDungeonReplyWraper()
	{
		
		m_Result = -9999;
		m_DungeonConfigId = -1;
		m_SceneConfigId = -1;

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
		v.set_sceneconfigid( m_SceneConfigId );

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
	void Init(const DungeonRpcCreateDungeonReply& v)
	{
		m_Result = v.result();
		m_DungeonConfigId = v.dungeonconfigid();
		m_SceneConfigId = v.sceneconfigid();

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

};
//进入副本通知回应封装类
class DungeonRpcEnterDungeonReplyWraper : public DataWraperInterface 
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
//战况信息通知封装类
class DungeonRpcDungeonDataNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DungeonRpcDungeonDataNotifyWraper()
	{
		
		m_BeginTime = -1;

	}
	//赋值构造函数
	DungeonRpcDungeonDataNotifyWraper(const DungeonRpcDungeonDataNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonDataNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonDataNotify ToPB() const
	{
		DungeonRpcDungeonDataNotify v;
		v.set_begintime( m_BeginTime );

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
		DungeonRpcDungeonDataNotify pb;
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
	void Init(const DungeonRpcDungeonDataNotify& v)
	{
		m_BeginTime = v.begintime();

	}

private:
	//副本开始时间
	INT32 m_BeginTime;
public:
	void SetBeginTime( INT32 v)
	{
		m_BeginTime=v;
	}
	INT32 GetBeginTime()
	{
		return m_BeginTime;
	}
	INT32 GetBeginTime() const
	{
		return m_BeginTime;
	}

};
//进入副本通知请求封装类
class DungeonRpcEnterDungeonAskWraper : public DataWraperInterface 
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
//队长创建副本以后通知我回应封装类
class DungeonRpcInformCreateDungeonReplyWraper : public DataWraperInterface 
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
//Settlement通知封装类
class DungeonRpcSettlementNotifyWraper : public DataWraperInterface 
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DungeonRpcSettlementNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonDataNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonTargetNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY};};
template<> struct MessageIdT<DungeonRpcTargetContentChangeNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeon_NotifyNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY};};


#endif
