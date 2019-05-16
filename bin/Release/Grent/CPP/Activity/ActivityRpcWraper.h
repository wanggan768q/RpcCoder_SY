/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperActivity.h
* Author:       甘业清
* Description:  活动RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ACTIVITY_H
#define __RPC_WRAPER_ACTIVITY_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ActivityRpc.pb.h"



//活动类的枚举定义
enum ConstActivityE
{
	MODULE_ID_ACTIVITY                           = 24,	//活动模块ID
	RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY    = 2451,	//活动-->精英怪信息-->通知
	RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST          = 2452,	//活动-->生成对象-->请求
	RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY        = 2453,	//活动-->活动开启前通知-->通知
	RPC_CODE_ACTIVITY_XINGYAO_REQUEST            = 2454,	//活动-->星耀王座进入-->请求
	RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY        = 2455,	//活动-->活动时间信息-->通知
	RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST    = 2456,	//活动-->请求获取活动时间-->请求
	RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST         = 2457,	//活动-->星耀NPC-->请求
	RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY       = 2458,	//活动-->星耀高额奖励-->通知
	RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY       = 2459,	//活动-->operation活动表时间-->通知


};


//星耀NPC请求封装类
class ActivityRpcXingyaoNPCAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcXingyaoNPCAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityRpcXingyaoNPCAskWraper(const ActivityRpcXingyaoNPCAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcXingyaoNPCAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcXingyaoNPCAsk ToPB() const
	{
		ActivityRpcXingyaoNPCAsk v;

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
		ActivityRpcXingyaoNPCAsk pb;
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
	void Init(const ActivityRpcXingyaoNPCAsk& v)
	{

	}


};
//请求获取活动时间回应封装类
class ActivityRpcReqActivityTimeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcReqActivityTimeReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ActivityRpcReqActivityTimeReplyWraper(const ActivityRpcReqActivityTimeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcReqActivityTimeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcReqActivityTimeReply ToPB() const
	{
		ActivityRpcReqActivityTimeReply v;
		v.set_result( m_Result );
		v.mutable_acttimelist()->Reserve(m_ActTimeList.size());
		for (int i=0; i<(int)m_ActTimeList.size(); i++)
		{
			*v.add_acttimelist() = m_ActTimeList[i].ToPB();
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
		ActivityRpcReqActivityTimeReply pb;
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
	void Init(const ActivityRpcReqActivityTimeReply& v)
	{
		m_Result = v.result();
		m_ActTimeList.clear();
		m_ActTimeList.reserve(v.acttimelist_size());
		for( int i=0; i<v.acttimelist_size(); i++)
			m_ActTimeList.push_back(v.acttimelist(i));

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
	//活动时间信息
	vector<ActivityTimeWraper> m_ActTimeList;
public:
	int SizeActTimeList()
	{
		return m_ActTimeList.size();
	}
	const vector<ActivityTimeWraper>& GetActTimeList() const
	{
		return m_ActTimeList;
	}
	ActivityTimeWraper GetActTimeList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return ActivityTimeWraper();
		}
		return m_ActTimeList[Index];
	}
	void SetActTimeList( const vector<ActivityTimeWraper>& v )
	{
		m_ActTimeList=v;
	}
	void ClearActTimeList( )
	{
		m_ActTimeList.clear();
	}
	void SetActTimeList( int Index, const ActivityTimeWraper& v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return;
		}
		m_ActTimeList[Index] = v;
	}
	void AddActTimeList( const ActivityTimeWraper& v )
	{
		m_ActTimeList.push_back(v);
	}

};
//请求获取活动时间请求封装类
class ActivityRpcReqActivityTimeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcReqActivityTimeAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityRpcReqActivityTimeAskWraper(const ActivityRpcReqActivityTimeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcReqActivityTimeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcReqActivityTimeAsk ToPB() const
	{
		ActivityRpcReqActivityTimeAsk v;

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
		ActivityRpcReqActivityTimeAsk pb;
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
	void Init(const ActivityRpcReqActivityTimeAsk& v)
	{

	}


};
//operation活动表时间通知封装类
class ActivityRpcOperationTimeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcOperationTimeNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityRpcOperationTimeNotifyWraper(const ActivityRpcOperationTimeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcOperationTimeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcOperationTimeNotify ToPB() const
	{
		ActivityRpcOperationTimeNotify v;
		v.mutable_acttimelist()->Reserve(m_ActTimeList.size());
		for (int i=0; i<(int)m_ActTimeList.size(); i++)
		{
			*v.add_acttimelist() = m_ActTimeList[i].ToPB();
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
		ActivityRpcOperationTimeNotify pb;
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
	void Init(const ActivityRpcOperationTimeNotify& v)
	{
		m_ActTimeList.clear();
		m_ActTimeList.reserve(v.acttimelist_size());
		for( int i=0; i<v.acttimelist_size(); i++)
			m_ActTimeList.push_back(v.acttimelist(i));

	}

private:
	//活动时间信息
	vector<ActivityTimeWraper> m_ActTimeList;
public:
	int SizeActTimeList()
	{
		return m_ActTimeList.size();
	}
	const vector<ActivityTimeWraper>& GetActTimeList() const
	{
		return m_ActTimeList;
	}
	ActivityTimeWraper GetActTimeList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return ActivityTimeWraper();
		}
		return m_ActTimeList[Index];
	}
	void SetActTimeList( const vector<ActivityTimeWraper>& v )
	{
		m_ActTimeList=v;
	}
	void ClearActTimeList( )
	{
		m_ActTimeList.clear();
	}
	void SetActTimeList( int Index, const ActivityTimeWraper& v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return;
		}
		m_ActTimeList[Index] = v;
	}
	void AddActTimeList( const ActivityTimeWraper& v )
	{
		m_ActTimeList.push_back(v);
	}

};
//星耀高额奖励通知封装类
class ActivityRpcXingyaoRewardNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcXingyaoRewardNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityRpcXingyaoRewardNotifyWraper(const ActivityRpcXingyaoRewardNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcXingyaoRewardNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcXingyaoRewardNotify ToPB() const
	{
		ActivityRpcXingyaoRewardNotify v;

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
		ActivityRpcXingyaoRewardNotify pb;
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
	void Init(const ActivityRpcXingyaoRewardNotify& v)
	{

	}


};
//星耀NPC回应封装类
class ActivityRpcXingyaoNPCReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcXingyaoNPCReplyWraper()
	{
		
		m_Result = -1;
		m_Sceneid = -1;
		m_Waypoinid = -1;

	}
	//赋值构造函数
	ActivityRpcXingyaoNPCReplyWraper(const ActivityRpcXingyaoNPCReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcXingyaoNPCReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcXingyaoNPCReply ToPB() const
	{
		ActivityRpcXingyaoNPCReply v;
		v.set_result( m_Result );
		v.set_sceneid( m_Sceneid );
		v.set_waypoinid( m_Waypoinid );

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
		ActivityRpcXingyaoNPCReply pb;
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
	void Init(const ActivityRpcXingyaoNPCReply& v)
	{
		m_Result = v.result();
		m_Sceneid = v.sceneid();
		m_Waypoinid = v.waypoinid();

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
	//场景ID
	INT32 m_Sceneid;
public:
	void SetSceneid( INT32 v)
	{
		m_Sceneid=v;
	}
	INT32 GetSceneid()
	{
		return m_Sceneid;
	}
	INT32 GetSceneid() const
	{
		return m_Sceneid;
	}
private:
	//路点ID
	INT32 m_Waypoinid;
public:
	void SetWaypoinid( INT32 v)
	{
		m_Waypoinid=v;
	}
	INT32 GetWaypoinid()
	{
		return m_Waypoinid;
	}
	INT32 GetWaypoinid() const
	{
		return m_Waypoinid;
	}

};
//活动时间信息通知封装类
class ActivityRpcActivityTimeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcActivityTimeNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityRpcActivityTimeNotifyWraper(const ActivityRpcActivityTimeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcActivityTimeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcActivityTimeNotify ToPB() const
	{
		ActivityRpcActivityTimeNotify v;
		v.mutable_acttimelist()->Reserve(m_ActTimeList.size());
		for (int i=0; i<(int)m_ActTimeList.size(); i++)
		{
			*v.add_acttimelist() = m_ActTimeList[i].ToPB();
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
		ActivityRpcActivityTimeNotify pb;
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
	void Init(const ActivityRpcActivityTimeNotify& v)
	{
		m_ActTimeList.clear();
		m_ActTimeList.reserve(v.acttimelist_size());
		for( int i=0; i<v.acttimelist_size(); i++)
			m_ActTimeList.push_back(v.acttimelist(i));

	}

private:
	//活动时间信息
	vector<ActivityTimeWraper> m_ActTimeList;
public:
	int SizeActTimeList()
	{
		return m_ActTimeList.size();
	}
	const vector<ActivityTimeWraper>& GetActTimeList() const
	{
		return m_ActTimeList;
	}
	ActivityTimeWraper GetActTimeList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return ActivityTimeWraper();
		}
		return m_ActTimeList[Index];
	}
	void SetActTimeList( const vector<ActivityTimeWraper>& v )
	{
		m_ActTimeList=v;
	}
	void ClearActTimeList( )
	{
		m_ActTimeList.clear();
	}
	void SetActTimeList( int Index, const ActivityTimeWraper& v )
	{
		if(Index<0 || Index>=(int)m_ActTimeList.size())
		{
			assert(false);
			return;
		}
		m_ActTimeList[Index] = v;
	}
	void AddActTimeList( const ActivityTimeWraper& v )
	{
		m_ActTimeList.push_back(v);
	}

};
//生成对象回应封装类
class ActivityRpcCreateObjReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcCreateObjReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ActivityRpcCreateObjReplyWraper(const ActivityRpcCreateObjReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcCreateObjReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcCreateObjReply ToPB() const
	{
		ActivityRpcCreateObjReply v;
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
		ActivityRpcCreateObjReply pb;
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
	void Init(const ActivityRpcCreateObjReply& v)
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
//生成对象请求封装类
class ActivityRpcCreateObjAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcCreateObjAskWraper()
	{
		
		m_CommonId = -1;

	}
	//赋值构造函数
	ActivityRpcCreateObjAskWraper(const ActivityRpcCreateObjAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcCreateObjAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcCreateObjAsk ToPB() const
	{
		ActivityRpcCreateObjAsk v;
		v.set_commonid( m_CommonId );

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
		ActivityRpcCreateObjAsk pb;
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
	void Init(const ActivityRpcCreateObjAsk& v)
	{
		m_CommonId = v.commonid();

	}

private:
	//当前id
	INT32 m_CommonId;
public:
	void SetCommonId( INT32 v)
	{
		m_CommonId=v;
	}
	INT32 GetCommonId()
	{
		return m_CommonId;
	}
	INT32 GetCommonId() const
	{
		return m_CommonId;
	}

};
//精英怪信息通知封装类
class ActivityRpcEliteMonsterInfoNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcEliteMonsterInfoNotifyWraper()
	{
		
		m_State = -1;
		m_Info = EliteMonsterInfoWraper();

	}
	//赋值构造函数
	ActivityRpcEliteMonsterInfoNotifyWraper(const ActivityRpcEliteMonsterInfoNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcEliteMonsterInfoNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcEliteMonsterInfoNotify ToPB() const
	{
		ActivityRpcEliteMonsterInfoNotify v;
		v.set_state( m_State );
		*v.mutable_info()= m_Info.ToPB();

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
		ActivityRpcEliteMonsterInfoNotify pb;
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
	void Init(const ActivityRpcEliteMonsterInfoNotify& v)
	{
		m_State = v.state();
		m_Info = v.info();

	}

private:
	//状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//信息
	EliteMonsterInfoWraper m_Info;
public:
	void SetInfo( const EliteMonsterInfoWraper& v)
	{
		m_Info=v;
	}
	EliteMonsterInfoWraper GetInfo()
	{
		return m_Info;
	}
	EliteMonsterInfoWraper GetInfo() const
	{
		return m_Info;
	}

};
//星耀王座回应封装类
class ActivityRpcXingyaoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcXingyaoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ActivityRpcXingyaoReplyWraper(const ActivityRpcXingyaoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcXingyaoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcXingyaoReply ToPB() const
	{
		ActivityRpcXingyaoReply v;
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
		ActivityRpcXingyaoReply pb;
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
	void Init(const ActivityRpcXingyaoReply& v)
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
//星耀王座进入请求封装类
class ActivityRpcXingyaoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcXingyaoAskWraper()
	{
		
		m_NPCid = -1;

	}
	//赋值构造函数
	ActivityRpcXingyaoAskWraper(const ActivityRpcXingyaoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcXingyaoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcXingyaoAsk ToPB() const
	{
		ActivityRpcXingyaoAsk v;
		v.set_npcid( m_NPCid );

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
		ActivityRpcXingyaoAsk pb;
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
	void Init(const ActivityRpcXingyaoAsk& v)
	{
		m_NPCid = v.npcid();

	}

private:
	//NPC
	INT32 m_NPCid;
public:
	void SetNPCid( INT32 v)
	{
		m_NPCid=v;
	}
	INT32 GetNPCid()
	{
		return m_NPCid;
	}
	INT32 GetNPCid() const
	{
		return m_NPCid;
	}

};
//活动开启前通知通知封装类
class ActivityRpcOpenActivityNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityRpcOpenActivityNotifyWraper()
	{
		
		m_ActId = -1;
		m_DiffTm = -1;
		m_SceneId = -1;
		m_Pos = Vector3Wraper();

	}
	//赋值构造函数
	ActivityRpcOpenActivityNotifyWraper(const ActivityRpcOpenActivityNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityRpcOpenActivityNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityRpcOpenActivityNotify ToPB() const
	{
		ActivityRpcOpenActivityNotify v;
		v.set_actid( m_ActId );
		v.set_difftm( m_DiffTm );
		v.set_sceneid( m_SceneId );
		*v.mutable_pos()= m_Pos.ToPB();

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
		ActivityRpcOpenActivityNotify pb;
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
	void Init(const ActivityRpcOpenActivityNotify& v)
	{
		m_ActId = v.actid();
		m_DiffTm = v.difftm();
		m_SceneId = v.sceneid();
		m_Pos = v.pos();

	}

private:
	//活动id
	INT32 m_ActId;
public:
	void SetActId( INT32 v)
	{
		m_ActId=v;
	}
	INT32 GetActId()
	{
		return m_ActId;
	}
	INT32 GetActId() const
	{
		return m_ActId;
	}
private:
	//活动开启前时间
	INT32 m_DiffTm;
public:
	void SetDiffTm( INT32 v)
	{
		m_DiffTm=v;
	}
	INT32 GetDiffTm()
	{
		return m_DiffTm;
	}
	INT32 GetDiffTm() const
	{
		return m_DiffTm;
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
	//传送位置
	Vector3Wraper m_Pos;
public:
	void SetPos( const Vector3Wraper& v)
	{
		m_Pos=v;
	}
	Vector3Wraper GetPos()
	{
		return m_Pos;
	}
	Vector3Wraper GetPos() const
	{
		return m_Pos;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ActivityRpcEliteMonsterInfoNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITY_ELITEMONSTERINFO_NOTIFY};};
template<> struct MessageIdT<ActivityRpcOpenActivityNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITY_OPENACTIVITY_NOTIFY};};
template<> struct MessageIdT<ActivityRpcActivityTimeNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITY_ACTIVITYTIME_NOTIFY};};
template<> struct MessageIdT<ActivityRpcXingyaoRewardNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITY_XINGYAOREWARD_NOTIFY};};
template<> struct MessageIdT<ActivityRpcOperationTimeNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITY_OPERATIONTIME_NOTIFY};};


#endif
