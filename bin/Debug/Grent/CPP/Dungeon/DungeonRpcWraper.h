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
	RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY          = 656,	//副本-->战况信息-->通知
	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST         = 657,	//副本-->副本数据请求-->请求
	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST     = 658,	//副本-->副本挑战信息-->请求
	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST      = 659,	//副本-->创建序章副本-->请求
	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST        = 660,	//副本-->强制退出序章-->请求
	RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY        = 661,	//副本-->副本目标-->通知
	RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY  = 662,	//副本-->副本子任务完成情况-->通知
	RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY       = 663,	//副本-->副本提示-->通知
	RPC_CODE_DUNGEON_SCENEOPERATOR1_REQUEST      = 664,	//副本-->场景操作1-->请求
	RPC_CODE_DUNGEON_FORCEENTERNEXTDUNGEONLAYER_NOTIFY= 665,	//副本-->强制进入下一层-->通知
	RPC_CODE_DUNGEON_DUNGEONREWARDUPDATE_NOTIFY  = 666,	//副本-->副本更新-->通知
	RPC_CODE_DUNGEON_VICTORYOFALLLAYER_NOTIFY    = 667,	//副本-->全部层胜利-->通知
	RPC_CODE_DUNGEON_LAYERBEGIN_NOTIFY           = 668,	//副本-->层数开始-->通知
	RPC_CODE_DUNGEON_LAYERSETTLEMENT_NOTIFY      = 669,	//副本-->当前层结算-->通知
	RPC_CODE_DUNGEON_SCENEOPERATORN_NOTIFY       = 670,	//副本-->场景操作通知-->通知
	RPC_CODE_DUNGEON_ENTERLAYERDUNGEON_NOTIFY    = 671,	//副本-->进入爬塔副本-->通知
	RPC_CODE_DUNGEON_DUNGEONEXPLOITS_NOTIFY      = 672,	//副本-->副本战绩数据-->通知
	RPC_CODE_DUNGEON_CREATEDUNGEONWITHROBOT_REQUEST= 673,	//副本-->使用机器人组队进副本-->请求
	RPC_CODE_DUNGEON_USEBOSSNUM_REQUEST          = 674,	//副本-->使用挑战次数-->请求


};


//强制进入下一层通知封装类
class DungeonRpcForceEnterNextDungeonLayerNotifyWraper
{
public:
	//构造函数
	DungeonRpcForceEnterNextDungeonLayerNotifyWraper()
	{
		
		m_NextLayer = 1;
		m_Breward = false;

	}
	//赋值构造函数
	DungeonRpcForceEnterNextDungeonLayerNotifyWraper(const DungeonRpcForceEnterNextDungeonLayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcForceEnterNextDungeonLayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcForceEnterNextDungeonLayerNotify ToPB() const
	{
		DungeonRpcForceEnterNextDungeonLayerNotify v;
		v.set_nextlayer( m_NextLayer );
		v.set_breward( m_Breward );

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
		DungeonRpcForceEnterNextDungeonLayerNotify pb;
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
	void Init(const DungeonRpcForceEnterNextDungeonLayerNotify& v)
	{
		m_NextLayer = v.nextlayer();
		m_Breward = v.breward();

	}

private:
	//下一层是多少层
	INT32 m_NextLayer;
public:
	void SetNextLayer( INT32 v)
	{
		m_NextLayer=v;
	}
	INT32 GetNextLayer()
	{
		return m_NextLayer;
	}
	INT32 GetNextLayer() const
	{
		return m_NextLayer;
	}
private:
	//本层是否奖励(公会副本)
	bool m_Breward;
public:
	void SetBreward( bool v)
	{
		m_Breward=v;
	}
	bool GetBreward()
	{
		return m_Breward;
	}
	bool GetBreward() const
	{
		return m_Breward;
	}

};
//场景操作1回应封装类
class DungeonRpcSceneOperator1ReplyWraper
{
public:
	//构造函数
	DungeonRpcSceneOperator1ReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	DungeonRpcSceneOperator1ReplyWraper(const DungeonRpcSceneOperator1Reply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcSceneOperator1Reply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcSceneOperator1Reply ToPB() const
	{
		DungeonRpcSceneOperator1Reply v;
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
		DungeonRpcSceneOperator1Reply pb;
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
	void Init(const DungeonRpcSceneOperator1Reply& v)
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
//全部层胜利通知封装类
class DungeonRpcVictoryOfAllLayerNotifyWraper
{
public:
	//构造函数
	DungeonRpcVictoryOfAllLayerNotifyWraper()
	{
		
		m_LastLayer = -1;

	}
	//赋值构造函数
	DungeonRpcVictoryOfAllLayerNotifyWraper(const DungeonRpcVictoryOfAllLayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcVictoryOfAllLayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcVictoryOfAllLayerNotify ToPB() const
	{
		DungeonRpcVictoryOfAllLayerNotify v;
		v.set_lastlayer( m_LastLayer );

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
		DungeonRpcVictoryOfAllLayerNotify pb;
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
	void Init(const DungeonRpcVictoryOfAllLayerNotify& v)
	{
		m_LastLayer = v.lastlayer();

	}

private:
	//最后层数
	INT32 m_LastLayer;
public:
	void SetLastLayer( INT32 v)
	{
		m_LastLayer=v;
	}
	INT32 GetLastLayer()
	{
		return m_LastLayer;
	}
	INT32 GetLastLayer() const
	{
		return m_LastLayer;
	}

};
//副本更新通知封装类
class DungeonRpcDungeonRewardUpdateNotifyWraper
{
public:
	//构造函数
	DungeonRpcDungeonRewardUpdateNotifyWraper()
	{
		
		m_NewRoleId = 0;
		m_NewIndex = 0;

	}
	//赋值构造函数
	DungeonRpcDungeonRewardUpdateNotifyWraper(const DungeonRpcDungeonRewardUpdateNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonRewardUpdateNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonRewardUpdateNotify ToPB() const
	{
		DungeonRpcDungeonRewardUpdateNotify v;
		v.mutable_openroleidlist()->Reserve(m_OpenRoleIdList.size());
		for (int i=0; i<(int)m_OpenRoleIdList.size(); i++)
		{
			v.add_openroleidlist(m_OpenRoleIdList[i]);
		}
		v.set_newroleid( m_NewRoleId );
		v.set_newindex( m_NewIndex );

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
		DungeonRpcDungeonRewardUpdateNotify pb;
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
	void Init(const DungeonRpcDungeonRewardUpdateNotify& v)
	{
		m_OpenRoleIdList.clear();
		m_OpenRoleIdList.reserve(v.openroleidlist_size());
		for( int i=0; i<v.openroleidlist_size(); i++)
			m_OpenRoleIdList.push_back(v.openroleidlist(i));
		m_NewRoleId = v.newroleid();
		m_NewIndex = v.newindex();

	}

private:
	//玩家的唯一id列表
	vector<uint64_t> m_OpenRoleIdList;
public:
	int SizeOpenRoleIdList()
	{
		return m_OpenRoleIdList.size();
	}
	const vector<uint64_t>& GetOpenRoleIdList() const
	{
		return m_OpenRoleIdList;
	}
	uint64_t GetOpenRoleIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_OpenRoleIdList.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_OpenRoleIdList[Index];
	}
	void SetOpenRoleIdList( const vector<uint64_t>& v )
	{
		m_OpenRoleIdList=v;
	}
	void ClearOpenRoleIdList( )
	{
		m_OpenRoleIdList.clear();
	}
	void SetOpenRoleIdList( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_OpenRoleIdList.size())
		{
			assert(false);
			return;
		}
		m_OpenRoleIdList[Index] = v;
	}
	void AddOpenRoleIdList( uint64_t v = 0 )
	{
		m_OpenRoleIdList.push_back(v);
	}
private:
	//新翻牌的人
	uint64_t m_NewRoleId;
public:
	void SetNewRoleId( uint64_t v)
	{
		m_NewRoleId=v;
	}
	uint64_t GetNewRoleId()
	{
		return m_NewRoleId;
	}
	uint64_t GetNewRoleId() const
	{
		return m_NewRoleId;
	}
private:
	//下标
	INT32 m_NewIndex;
public:
	void SetNewIndex( INT32 v)
	{
		m_NewIndex=v;
	}
	INT32 GetNewIndex()
	{
		return m_NewIndex;
	}
	INT32 GetNewIndex() const
	{
		return m_NewIndex;
	}

};
//副本子任务完成情况通知封装类
class DungeonRpcTargetContentChangeNotifyWraper
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
//副本目标通知封装类
class DungeonRpcDungeonTargetNotifyWraper
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
//场景操作1请求封装类
class DungeonRpcSceneOperator1AskWraper
{
public:
	//构造函数
	DungeonRpcSceneOperator1AskWraper()
	{
		
		m_OpCode = 0;
		m_OpExtraParam = 0;

	}
	//赋值构造函数
	DungeonRpcSceneOperator1AskWraper(const DungeonRpcSceneOperator1Ask& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcSceneOperator1Ask& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcSceneOperator1Ask ToPB() const
	{
		DungeonRpcSceneOperator1Ask v;
		v.set_opcode( m_OpCode );
		v.set_opextraparam( m_OpExtraParam );

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
		DungeonRpcSceneOperator1Ask pb;
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
	void Init(const DungeonRpcSceneOperator1Ask& v)
	{
		m_OpCode = v.opcode();
		m_OpExtraParam = v.opextraparam();

	}

private:
	//0:转罗盘，1翻牌子
	INT32 m_OpCode;
public:
	void SetOpCode( INT32 v)
	{
		m_OpCode=v;
	}
	INT32 GetOpCode()
	{
		return m_OpCode;
	}
	INT32 GetOpCode() const
	{
		return m_OpCode;
	}
private:
	//额外参数
	INT32 m_OpExtraParam;
public:
	void SetOpExtraParam( INT32 v)
	{
		m_OpExtraParam=v;
	}
	INT32 GetOpExtraParam()
	{
		return m_OpExtraParam;
	}
	INT32 GetOpExtraParam() const
	{
		return m_OpExtraParam;
	}

};
//副本提示通知封装类
class DungeonRpcDungeon_NotifyNotifyWraper
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
//层数开始通知封装类
class DungeonRpcLayerBeginNotifyWraper
{
public:
	//构造函数
	DungeonRpcLayerBeginNotifyWraper()
	{
		

	}
	//赋值构造函数
	DungeonRpcLayerBeginNotifyWraper(const DungeonRpcLayerBeginNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcLayerBeginNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcLayerBeginNotify ToPB() const
	{
		DungeonRpcLayerBeginNotify v;

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
		DungeonRpcLayerBeginNotify pb;
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
	void Init(const DungeonRpcLayerBeginNotify& v)
	{

	}


};
//使用机器人组队进副本回应封装类
class DungeonRpcCreateDungeonWithRobotReplyWraper
{
public:
	//构造函数
	DungeonRpcCreateDungeonWithRobotReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonWithRobotReplyWraper(const DungeonRpcCreateDungeonWithRobotReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonWithRobotReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonWithRobotReply ToPB() const
	{
		DungeonRpcCreateDungeonWithRobotReply v;
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
		DungeonRpcCreateDungeonWithRobotReply pb;
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
	void Init(const DungeonRpcCreateDungeonWithRobotReply& v)
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
//使用机器人组队进副本请求封装类
class DungeonRpcCreateDungeonWithRobotAskWraper
{
public:
	//构造函数
	DungeonRpcCreateDungeonWithRobotAskWraper()
	{
		
		m_DungeonConfigId = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	DungeonRpcCreateDungeonWithRobotAskWraper(const DungeonRpcCreateDungeonWithRobotAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcCreateDungeonWithRobotAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcCreateDungeonWithRobotAsk ToPB() const
	{
		DungeonRpcCreateDungeonWithRobotAsk v;
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_roleid( m_RoleId );

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
		DungeonRpcCreateDungeonWithRobotAsk pb;
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
	void Init(const DungeonRpcCreateDungeonWithRobotAsk& v)
	{
		m_DungeonConfigId = v.dungeonconfigid();
		m_RoleId = v.roleid();

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

};
//使用挑战次数回应封装类
class DungeonRpcUseBossNumReplyWraper
{
public:
	//构造函数
	DungeonRpcUseBossNumReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	DungeonRpcUseBossNumReplyWraper(const DungeonRpcUseBossNumReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcUseBossNumReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcUseBossNumReply ToPB() const
	{
		DungeonRpcUseBossNumReply v;
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
		DungeonRpcUseBossNumReply pb;
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
	void Init(const DungeonRpcUseBossNumReply& v)
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
//使用挑战次数请求封装类
class DungeonRpcUseBossNumAskWraper
{
public:
	//构造函数
	DungeonRpcUseBossNumAskWraper()
	{
		
		m_BUse = false;

	}
	//赋值构造函数
	DungeonRpcUseBossNumAskWraper(const DungeonRpcUseBossNumAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcUseBossNumAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcUseBossNumAsk ToPB() const
	{
		DungeonRpcUseBossNumAsk v;
		v.set_buse( m_BUse );

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
		DungeonRpcUseBossNumAsk pb;
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
	void Init(const DungeonRpcUseBossNumAsk& v)
	{
		m_BUse = v.buse();

	}

private:
	//是否使用
	bool m_BUse;
public:
	void SetBUse( bool v)
	{
		m_BUse=v;
	}
	bool GetBUse()
	{
		return m_BUse;
	}
	bool GetBUse() const
	{
		return m_BUse;
	}

};
//场景操作通知通知封装类
class DungeonRpcSceneOperatorNNotifyWraper
{
public:
	//构造函数
	DungeonRpcSceneOperatorNNotifyWraper()
	{
		
		m_OpCode = 0;

	}
	//赋值构造函数
	DungeonRpcSceneOperatorNNotifyWraper(const DungeonRpcSceneOperatorNNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcSceneOperatorNNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcSceneOperatorNNotify ToPB() const
	{
		DungeonRpcSceneOperatorNNotify v;
		v.set_opcode( m_OpCode );

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
		DungeonRpcSceneOperatorNNotify pb;
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
	void Init(const DungeonRpcSceneOperatorNNotify& v)
	{
		m_OpCode = v.opcode();

	}

private:
	//0:转罗盘，1翻牌子
	INT32 m_OpCode;
public:
	void SetOpCode( INT32 v)
	{
		m_OpCode=v;
	}
	INT32 GetOpCode()
	{
		return m_OpCode;
	}
	INT32 GetOpCode() const
	{
		return m_OpCode;
	}

};
//当前层结算通知封装类
class DungeonRpcLayerSettlementNotifyWraper
{
public:
	//构造函数
	DungeonRpcLayerSettlementNotifyWraper()
	{
		
		m_NextLayer = 1;

	}
	//赋值构造函数
	DungeonRpcLayerSettlementNotifyWraper(const DungeonRpcLayerSettlementNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcLayerSettlementNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcLayerSettlementNotify ToPB() const
	{
		DungeonRpcLayerSettlementNotify v;
		v.set_nextlayer( m_NextLayer );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			*v.add_rewardlist() = m_RewardList[i].ToPB();
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
		DungeonRpcLayerSettlementNotify pb;
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
	void Init(const DungeonRpcLayerSettlementNotify& v)
	{
		m_NextLayer = v.nextlayer();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));

	}

private:
	//下一层是多少层
	INT32 m_NextLayer;
public:
	void SetNextLayer( INT32 v)
	{
		m_NextLayer=v;
	}
	INT32 GetNextLayer()
	{
		return m_NextLayer;
	}
	INT32 GetNextLayer() const
	{
		return m_NextLayer;
	}
private:
	//奖励列表
	vector<PBUIRewardDataWraper> m_RewardList;
public:
	int SizeRewardList()
	{
		return m_RewardList.size();
	}
	const vector<PBUIRewardDataWraper>& GetRewardList() const
	{
		return m_RewardList;
	}
	PBUIRewardDataWraper GetRewardList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return PBUIRewardDataWraper();
		}
		return m_RewardList[Index];
	}
	void SetRewardList( const vector<PBUIRewardDataWraper>& v )
	{
		m_RewardList=v;
	}
	void ClearRewardList( )
	{
		m_RewardList.clear();
	}
	void SetRewardList( int Index, const PBUIRewardDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return;
		}
		m_RewardList[Index] = v;
	}
	void AddRewardList( const PBUIRewardDataWraper& v )
	{
		m_RewardList.push_back(v);
	}

};
//副本战绩数据通知封装类
class DungeonRpcDungeonExploitsNotifyWraper
{
public:
	//构造函数
	DungeonRpcDungeonExploitsNotifyWraper()
	{
		
		m_Exploits = DungeonExploitsWraper();

	}
	//赋值构造函数
	DungeonRpcDungeonExploitsNotifyWraper(const DungeonRpcDungeonExploitsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcDungeonExploitsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcDungeonExploitsNotify ToPB() const
	{
		DungeonRpcDungeonExploitsNotify v;
		*v.mutable_exploits()= m_Exploits.ToPB();

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
		DungeonRpcDungeonExploitsNotify pb;
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
	void Init(const DungeonRpcDungeonExploitsNotify& v)
	{
		m_Exploits = v.exploits();

	}

private:
	//战绩数据
	DungeonExploitsWraper m_Exploits;
public:
	void SetExploits( const DungeonExploitsWraper& v)
	{
		m_Exploits=v;
	}
	DungeonExploitsWraper GetExploits()
	{
		return m_Exploits;
	}
	DungeonExploitsWraper GetExploits() const
	{
		return m_Exploits;
	}

};
//进入爬塔副本通知封装类
class DungeonRpcEnterLayerDungeonNotifyWraper
{
public:
	//构造函数
	DungeonRpcEnterLayerDungeonNotifyWraper()
	{
		
		m_CurrentLayer = -1;
		m_CurentLayerRemainTime = -1;

	}
	//赋值构造函数
	DungeonRpcEnterLayerDungeonNotifyWraper(const DungeonRpcEnterLayerDungeonNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonRpcEnterLayerDungeonNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonRpcEnterLayerDungeonNotify ToPB() const
	{
		DungeonRpcEnterLayerDungeonNotify v;
		v.set_currentlayer( m_CurrentLayer );
		v.set_curentlayerremaintime( m_CurentLayerRemainTime );

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
		DungeonRpcEnterLayerDungeonNotify pb;
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
	void Init(const DungeonRpcEnterLayerDungeonNotify& v)
	{
		m_CurrentLayer = v.currentlayer();
		m_CurentLayerRemainTime = v.curentlayerremaintime();

	}

private:
	//当前层
	INT32 m_CurrentLayer;
public:
	void SetCurrentLayer( INT32 v)
	{
		m_CurrentLayer=v;
	}
	INT32 GetCurrentLayer()
	{
		return m_CurrentLayer;
	}
	INT32 GetCurrentLayer() const
	{
		return m_CurrentLayer;
	}
private:
	//当前层剩余时间
	INT32 m_CurentLayerRemainTime;
public:
	void SetCurentLayerRemainTime( INT32 v)
	{
		m_CurentLayerRemainTime=v;
	}
	INT32 GetCurentLayerRemainTime()
	{
		return m_CurentLayerRemainTime;
	}
	INT32 GetCurentLayerRemainTime() const
	{
		return m_CurentLayerRemainTime;
	}

};
//强制退出序章回应封装类
class DungeonRpcQuitTutorialReplyWraper
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
//Settlement通知封装类
class DungeonRpcSettlementNotifyWraper
{
public:
	//构造函数
	DungeonRpcSettlementNotifyWraper()
	{
		
		m_SettlementResult = -1;
		m_Exploits = DungeonExploitsWraper();
		m_Exp = -1;
		m_Gold = -1;
		m_DungeonPassTime = -1;
		m_ForceRetreatSceneTime = -1;
		m_RemainTime = -1;
		m_Starbattleid = -1;
		m_SceneType = -1;

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
		*v.mutable_exploits()= m_Exploits.ToPB();
		v.set_exp( m_Exp );
		v.mutable_uiiteminfolist()->Reserve(m_UiItemInfoList.size());
		for (int i=0; i<(int)m_UiItemInfoList.size(); i++)
		{
			*v.add_uiiteminfolist() = m_UiItemInfoList[i].ToPB();
		}
		v.set_gold( m_Gold );
		v.set_dungeonpasstime( m_DungeonPassTime );
		v.set_forceretreatscenetime( m_ForceRetreatSceneTime );
		v.set_remaintime( m_RemainTime );
		v.set_starbattleid( m_Starbattleid );
		v.set_scenetype( m_SceneType );

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
		m_Exploits = v.exploits();
		m_Exp = v.exp();
		m_UiItemInfoList.clear();
		m_UiItemInfoList.reserve(v.uiiteminfolist_size());
		for( int i=0; i<v.uiiteminfolist_size(); i++)
			m_UiItemInfoList.push_back(v.uiiteminfolist(i));
		m_Gold = v.gold();
		m_DungeonPassTime = v.dungeonpasstime();
		m_ForceRetreatSceneTime = v.forceretreatscenetime();
		m_RemainTime = v.remaintime();
		m_Starbattleid = v.starbattleid();
		m_SceneType = v.scenetype();

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
private:
	//战绩数据
	DungeonExploitsWraper m_Exploits;
public:
	void SetExploits( const DungeonExploitsWraper& v)
	{
		m_Exploits=v;
	}
	DungeonExploitsWraper GetExploits()
	{
		return m_Exploits;
	}
	DungeonExploitsWraper GetExploits() const
	{
		return m_Exploits;
	}
private:
	//本局经验
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//物品信息
	vector<ItemObjWraper> m_UiItemInfoList;
public:
	int SizeUiItemInfoList()
	{
		return m_UiItemInfoList.size();
	}
	const vector<ItemObjWraper>& GetUiItemInfoList() const
	{
		return m_UiItemInfoList;
	}
	ItemObjWraper GetUiItemInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UiItemInfoList.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_UiItemInfoList[Index];
	}
	void SetUiItemInfoList( const vector<ItemObjWraper>& v )
	{
		m_UiItemInfoList=v;
	}
	void ClearUiItemInfoList( )
	{
		m_UiItemInfoList.clear();
	}
	void SetUiItemInfoList( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_UiItemInfoList.size())
		{
			assert(false);
			return;
		}
		m_UiItemInfoList[Index] = v;
	}
	void AddUiItemInfoList( const ItemObjWraper& v )
	{
		m_UiItemInfoList.push_back(v);
	}
private:
	//金钱
	INT32 m_Gold;
public:
	void SetGold( INT32 v)
	{
		m_Gold=v;
	}
	INT32 GetGold()
	{
		return m_Gold;
	}
	INT32 GetGold() const
	{
		return m_Gold;
	}
private:
	//通过时间
	INT32 m_DungeonPassTime;
public:
	void SetDungeonPassTime( INT32 v)
	{
		m_DungeonPassTime=v;
	}
	INT32 GetDungeonPassTime()
	{
		return m_DungeonPassTime;
	}
	INT32 GetDungeonPassTime() const
	{
		return m_DungeonPassTime;
	}
private:
	//什么时候强制离开副本
	int64_t m_ForceRetreatSceneTime;
public:
	void SetForceRetreatSceneTime( int64_t v)
	{
		m_ForceRetreatSceneTime=v;
	}
	int64_t GetForceRetreatSceneTime()
	{
		return m_ForceRetreatSceneTime;
	}
	int64_t GetForceRetreatSceneTime() const
	{
		return m_ForceRetreatSceneTime;
	}
private:
	//剩下在副本里面的时间
	int64_t m_RemainTime;
public:
	void SetRemainTime( int64_t v)
	{
		m_RemainTime=v;
	}
	int64_t GetRemainTime()
	{
		return m_RemainTime;
	}
	int64_t GetRemainTime() const
	{
		return m_RemainTime;
	}
private:
	//星耀NPCid
	INT32 m_Starbattleid;
public:
	void SetStarbattleid( INT32 v)
	{
		m_Starbattleid=v;
	}
	INT32 GetStarbattleid()
	{
		return m_Starbattleid;
	}
	INT32 GetStarbattleid() const
	{
		return m_Starbattleid;
	}
private:
	//场景的类型
	INT32 m_SceneType;
public:
	void SetSceneType( INT32 v)
	{
		m_SceneType=v;
	}
	INT32 GetSceneType()
	{
		return m_SceneType;
	}
	INT32 GetSceneType() const
	{
		return m_SceneType;
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
//创建序章副本请求封装类
class DungeonRpcCreateTutorialAskWraper
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
//副本挑战信息回应封装类
class DungeonRpcDungeonListInfoReplyWraper
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
//强制退出序章请求封装类
class DungeonRpcQuitTutorialAskWraper
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
	void Init(const DungeonRpcQuitTutorialAsk& v)
	{

	}


};
//创建序章副本回应封装类
class DungeonRpcCreateTutorialReplyWraper
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
//副本数据请求请求封装类
class DungeonRpcDungeonSyncAskWraper
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
	void Init(const DungeonRpcDungeonSyncAsk& v)
	{

	}


};
//战况信息通知封装类
class DungeonRpcDungeonDataNotifyWraper
{
public:
	//构造函数
	DungeonRpcDungeonDataNotifyWraper()
	{
		
		m_BeginTime = 0;
		m_Data = DungeonDataWraper();
		m_Exploits = DungeonExploitsWraper();

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
		*v.mutable_data()= m_Data.ToPB();
		*v.mutable_exploits()= m_Exploits.ToPB();

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
	void Init(const DungeonRpcDungeonDataNotify& v)
	{
		m_BeginTime = v.begintime();
		m_Data = v.data();
		m_Exploits = v.exploits();

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
private:
	//战绩数据
	DungeonExploitsWraper m_Exploits;
public:
	void SetExploits( const DungeonExploitsWraper& v)
	{
		m_Exploits=v;
	}
	DungeonExploitsWraper GetExploits()
	{
		return m_Exploits;
	}
	DungeonExploitsWraper GetExploits() const
	{
		return m_Exploits;
	}

};
//副本挑战信息请求封装类
class DungeonRpcDungeonListInfoAskWraper
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
	void Init(const DungeonRpcDungeonListInfoAsk& v)
	{

	}


};
//副本数据请求回应封装类
class DungeonRpcDungeonSyncReplyWraper
{
public:
	//构造函数
	DungeonRpcDungeonSyncReplyWraper()
	{
		
		m_Result = -1;
		m_Data = DungeonDataWraper();
		m_Exploits = DungeonExploitsWraper();

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
		*v.mutable_exploits()= m_Exploits.ToPB();

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
	void Init(const DungeonRpcDungeonSyncReply& v)
	{
		m_Result = v.result();
		m_Data = v.data();
		m_Exploits = v.exploits();

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
private:
	//战绩数据
	DungeonExploitsWraper m_Exploits;
public:
	void SetExploits( const DungeonExploitsWraper& v)
	{
		m_Exploits=v;
	}
	DungeonExploitsWraper GetExploits()
	{
		return m_Exploits;
	}
	DungeonExploitsWraper GetExploits() const
	{
		return m_Exploits;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DungeonRpcSettlementNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonDataNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONDATA_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonTargetNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONTARGET_NOTIFY};};
template<> struct MessageIdT<DungeonRpcTargetContentChangeNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_TARGETCONTENTCHANGE_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeon_NotifyNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEON_NOTIFY_NOTIFY};};
template<> struct MessageIdT<DungeonRpcForceEnterNextDungeonLayerNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_FORCEENTERNEXTDUNGEONLAYER_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonRewardUpdateNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONREWARDUPDATE_NOTIFY};};
template<> struct MessageIdT<DungeonRpcVictoryOfAllLayerNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_VICTORYOFALLLAYER_NOTIFY};};
template<> struct MessageIdT<DungeonRpcLayerBeginNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_LAYERBEGIN_NOTIFY};};
template<> struct MessageIdT<DungeonRpcLayerSettlementNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_LAYERSETTLEMENT_NOTIFY};};
template<> struct MessageIdT<DungeonRpcSceneOperatorNNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_SCENEOPERATORN_NOTIFY};};
template<> struct MessageIdT<DungeonRpcEnterLayerDungeonNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_ENTERLAYERDUNGEON_NOTIFY};};
template<> struct MessageIdT<DungeonRpcDungeonExploitsNotifyWraper>{ enum{ID=RPC_CODE_DUNGEON_DUNGEONEXPLOITS_NOTIFY};};


#endif
