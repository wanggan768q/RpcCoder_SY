/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperQuest.h
* Author:       甘业清
* Description:  QuestRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_QUEST_H
#define __RPC_WRAPER_QUEST_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "QuestRpc.pb.h"



//Quest类的枚举定义
enum ConstQuestE
{
	MODULE_ID_QUEST                              = 15,	//Quest模块ID
	RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY          = 1551,	//Quest-->OnAcceptQuest-->通知
	RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST     = 1552,	//Quest-->CompleteQuestStep-->请求
	RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY        = 1553,	//Quest-->OnCompleteQuest-->通知
	RPC_CODE_QUEST_UPDATEQUEST_NOTIFY            = 1554,	//Quest-->更新任务-->通知
	RPC_CODE_QUEST_GIVEUPQUEST_REQUEST           = 1555,	//Quest-->放弃任务-->请求
	RPC_CODE_QUEST_COMPLETEQUEST_REQUEST         = 1556,	//Quest-->完成任务-->请求
	RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST= 1557,	//Quest-->完成接受任务对话框-->请求
	RPC_CODE_QUEST_ACCEPTQUEST_REQUEST           = 1558,	//Quest-->客户端接受任务-->请求
	RPC_CODE_QUEST_SYNCQUEST_REQUEST             = 1559,	//Quest-->SyncQuest-->请求
	RPC_CODE_QUEST_GETREWARD_REQUEST             = 1560,	//Quest-->GetReward-->请求
	RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY      = 1561,	//Quest-->上次任务通知-->通知
	RPC_CODE_QUEST_GETQUESTDATA_REQUEST          = 1562,	//Quest-->获取某个任务数据-->请求
	RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST        = 1563,	//Quest-->每日活动-->请求
	RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY       = 1564,	//Quest-->每日活动任务更新-->通知
	RPC_CODE_QUEST_CONSUMEITEM_REQUEST           = 1565,	//Quest-->任务消耗物品-->请求
	RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST  = 1566,	//Quest-->完成任务id请求-->请求
	RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY = 1567,	//Quest-->完成的任务列表-->通知
	RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST      = 1568,	//Quest-->精英怪击杀次数-->请求
	RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY     = 1569,	//Quest-->通知新可接任务-->通知


};


//每日活动任务更新通知封装类
class QuestRpcDailyQuestUpdateNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcDailyQuestUpdateNotifyWraper()
	{
		
		m_AtivityQuestData = DailyQuestWraper();

	}
	//赋值构造函数
	QuestRpcDailyQuestUpdateNotifyWraper(const QuestRpcDailyQuestUpdateNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcDailyQuestUpdateNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcDailyQuestUpdateNotify ToPB() const
	{
		QuestRpcDailyQuestUpdateNotify v;
		*v.mutable_ativityquestdata()= m_AtivityQuestData.ToPB();

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
		QuestRpcDailyQuestUpdateNotify pb;
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
	void Init(const QuestRpcDailyQuestUpdateNotify& v)
	{
		m_AtivityQuestData = v.ativityquestdata();

	}

private:
	//每日活动数据
	DailyQuestWraper m_AtivityQuestData;
public:
	void SetAtivityQuestData( const DailyQuestWraper& v)
	{
		m_AtivityQuestData=v;
	}
	DailyQuestWraper GetAtivityQuestData()
	{
		return m_AtivityQuestData;
	}
	DailyQuestWraper GetAtivityQuestData() const
	{
		return m_AtivityQuestData;
	}

};
//每日活动回应封装类
class QuestRpcSyncDailyQuestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncDailyQuestReplyWraper()
	{
		
		m_Result = -1;
		m_DailyQuestList = DailyQuestListWraper();

	}
	//赋值构造函数
	QuestRpcSyncDailyQuestReplyWraper(const QuestRpcSyncDailyQuestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncDailyQuestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncDailyQuestReply ToPB() const
	{
		QuestRpcSyncDailyQuestReply v;
		v.set_result( m_Result );
		*v.mutable_dailyquestlist()= m_DailyQuestList.ToPB();

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
		QuestRpcSyncDailyQuestReply pb;
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
	void Init(const QuestRpcSyncDailyQuestReply& v)
	{
		m_Result = v.result();
		m_DailyQuestList = v.dailyquestlist();

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
	//DailyQuestList
	DailyQuestListWraper m_DailyQuestList;
public:
	void SetDailyQuestList( const DailyQuestListWraper& v)
	{
		m_DailyQuestList=v;
	}
	DailyQuestListWraper GetDailyQuestList()
	{
		return m_DailyQuestList;
	}
	DailyQuestListWraper GetDailyQuestList() const
	{
		return m_DailyQuestList;
	}

};
//任务消耗物品回应封装类
class QuestRpcConsumeItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcConsumeItemReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcConsumeItemReplyWraper(const QuestRpcConsumeItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcConsumeItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcConsumeItemReply ToPB() const
	{
		QuestRpcConsumeItemReply v;
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
		QuestRpcConsumeItemReply pb;
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
	void Init(const QuestRpcConsumeItemReply& v)
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
//任务消耗物品请求封装类
class QuestRpcConsumeItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcConsumeItemAskWraper()
	{
		
		m_QuestConfigId = -1;

	}
	//赋值构造函数
	QuestRpcConsumeItemAskWraper(const QuestRpcConsumeItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcConsumeItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcConsumeItemAsk ToPB() const
	{
		QuestRpcConsumeItemAsk v;
		v.set_questconfigid( m_QuestConfigId );
		v.mutable_itemdata()->Reserve(m_ItemData.size());
		for (int i=0; i<(int)m_ItemData.size(); i++)
		{
			*v.add_itemdata() = m_ItemData[i].ToPB();
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
		QuestRpcConsumeItemAsk pb;
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
	void Init(const QuestRpcConsumeItemAsk& v)
	{
		m_QuestConfigId = v.questconfigid();
		m_ItemData.clear();
		m_ItemData.reserve(v.itemdata_size());
		for( int i=0; i<v.itemdata_size(); i++)
			m_ItemData.push_back(v.itemdata(i));

	}

private:
	//任务表的id
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}
private:
	//物品id
	vector<ItemSimpleDataWraper> m_ItemData;
public:
	int SizeItemData()
	{
		return m_ItemData.size();
	}
	const vector<ItemSimpleDataWraper>& GetItemData() const
	{
		return m_ItemData;
	}
	ItemSimpleDataWraper GetItemData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemData.size())
		{
			assert(false);
			return ItemSimpleDataWraper();
		}
		return m_ItemData[Index];
	}
	void SetItemData( const vector<ItemSimpleDataWraper>& v )
	{
		m_ItemData=v;
	}
	void ClearItemData( )
	{
		m_ItemData.clear();
	}
	void SetItemData( int Index, const ItemSimpleDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemData.size())
		{
			assert(false);
			return;
		}
		m_ItemData[Index] = v;
	}
	void AddItemData( const ItemSimpleDataWraper& v )
	{
		m_ItemData.push_back(v);
	}

};
//获取某个任务数据请求封装类
class QuestRpcGetQuestDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGetQuestDataAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcGetQuestDataAskWraper(const QuestRpcGetQuestDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGetQuestDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGetQuestDataAsk ToPB() const
	{
		QuestRpcGetQuestDataAsk v;
		v.mutable_questconfigid()->Reserve(m_QuestConfigId.size());
		for (int i=0; i<(int)m_QuestConfigId.size(); i++)
		{
			v.add_questconfigid(m_QuestConfigId[i]);
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
		QuestRpcGetQuestDataAsk pb;
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
	void Init(const QuestRpcGetQuestDataAsk& v)
	{
		m_QuestConfigId.clear();
		m_QuestConfigId.reserve(v.questconfigid_size());
		for( int i=0; i<v.questconfigid_size(); i++)
			m_QuestConfigId.push_back(v.questconfigid(i));

	}

private:
	//接受任务表
	vector<INT32> m_QuestConfigId;
public:
	int SizeQuestConfigId()
	{
		return m_QuestConfigId.size();
	}
	const vector<INT32>& GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.size())
		{
			assert(false);
			return INT32();
		}
		return m_QuestConfigId[Index];
	}
	void SetQuestConfigId( const vector<INT32>& v )
	{
		m_QuestConfigId=v;
	}
	void ClearQuestConfigId( )
	{
		m_QuestConfigId.clear();
	}
	void SetQuestConfigId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.size())
		{
			assert(false);
			return;
		}
		m_QuestConfigId[Index] = v;
	}
	void AddQuestConfigId( INT32 v = -1 )
	{
		m_QuestConfigId.push_back(v);
	}

};
//上次任务通知通知封装类
class QuestRpcRemoveQuestNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcRemoveQuestNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcRemoveQuestNotifyNotifyWraper(const QuestRpcRemoveQuestNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcRemoveQuestNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcRemoveQuestNotifyNotify ToPB() const
	{
		QuestRpcRemoveQuestNotifyNotify v;
		v.mutable_questconfigid()->Reserve(m_QuestConfigId.size());
		for (int i=0; i<(int)m_QuestConfigId.size(); i++)
		{
			v.add_questconfigid(m_QuestConfigId[i]);
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
		QuestRpcRemoveQuestNotifyNotify pb;
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
	void Init(const QuestRpcRemoveQuestNotifyNotify& v)
	{
		m_QuestConfigId.clear();
		m_QuestConfigId.reserve(v.questconfigid_size());
		for( int i=0; i<v.questconfigid_size(); i++)
			m_QuestConfigId.push_back(v.questconfigid(i));

	}

private:
	//接受任务表
	vector<INT32> m_QuestConfigId;
public:
	int SizeQuestConfigId()
	{
		return m_QuestConfigId.size();
	}
	const vector<INT32>& GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.size())
		{
			assert(false);
			return INT32();
		}
		return m_QuestConfigId[Index];
	}
	void SetQuestConfigId( const vector<INT32>& v )
	{
		m_QuestConfigId=v;
	}
	void ClearQuestConfigId( )
	{
		m_QuestConfigId.clear();
	}
	void SetQuestConfigId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_QuestConfigId.size())
		{
			assert(false);
			return;
		}
		m_QuestConfigId[Index] = v;
	}
	void AddQuestConfigId( INT32 v = -1 )
	{
		m_QuestConfigId.push_back(v);
	}

};
//每日活动请求封装类
class QuestRpcSyncDailyQuestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncDailyQuestAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcSyncDailyQuestAskWraper(const QuestRpcSyncDailyQuestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncDailyQuestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncDailyQuestAsk ToPB() const
	{
		QuestRpcSyncDailyQuestAsk v;

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
		QuestRpcSyncDailyQuestAsk pb;
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
	void Init(const QuestRpcSyncDailyQuestAsk& v)
	{

	}


};
//获取某个任务数据回应封装类
class QuestRpcGetQuestDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGetQuestDataReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcGetQuestDataReplyWraper(const QuestRpcGetQuestDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGetQuestDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGetQuestDataReply ToPB() const
	{
		QuestRpcGetQuestDataReply v;
		v.set_result( m_Result );
		v.mutable_questlist()->Reserve(m_QuestList.size());
		for (int i=0; i<(int)m_QuestList.size(); i++)
		{
			*v.add_questlist() = m_QuestList[i].ToPB();
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
		QuestRpcGetQuestDataReply pb;
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
	void Init(const QuestRpcGetQuestDataReply& v)
	{
		m_Result = v.result();
		m_QuestList.clear();
		m_QuestList.reserve(v.questlist_size());
		for( int i=0; i<v.questlist_size(); i++)
			m_QuestList.push_back(v.questlist(i));

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
	//返回给客户端的任务列表
	vector<QuestDataWraper> m_QuestList;
public:
	int SizeQuestList()
	{
		return m_QuestList.size();
	}
	const vector<QuestDataWraper>& GetQuestList() const
	{
		return m_QuestList;
	}
	QuestDataWraper GetQuestList(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return QuestDataWraper();
		}
		return m_QuestList[Index];
	}
	void SetQuestList( const vector<QuestDataWraper>& v )
	{
		m_QuestList=v;
	}
	void ClearQuestList( )
	{
		m_QuestList.clear();
	}
	void SetQuestList( int Index, const QuestDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return;
		}
		m_QuestList[Index] = v;
	}
	void AddQuestList( const QuestDataWraper& v )
	{
		m_QuestList.push_back(v);
	}

};
//任务列表请求封装类
class QuestRpcQuestMaxListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcQuestMaxListAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcQuestMaxListAskWraper(const QuestRpcQuestMaxListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcQuestMaxListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcQuestMaxListAsk ToPB() const
	{
		QuestRpcQuestMaxListAsk v;

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
		QuestRpcQuestMaxListAsk pb;
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
	void Init(const QuestRpcQuestMaxListAsk& v)
	{

	}


};
//精英怪击杀次数请求封装类
class QuestRpcEliteFinishCountAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcEliteFinishCountAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcEliteFinishCountAskWraper(const QuestRpcEliteFinishCountAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcEliteFinishCountAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcEliteFinishCountAsk ToPB() const
	{
		QuestRpcEliteFinishCountAsk v;

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
		QuestRpcEliteFinishCountAsk pb;
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
	void Init(const QuestRpcEliteFinishCountAsk& v)
	{

	}


};
//完成的任务列表通知封装类
class QuestRpcCompleteQuestIdsNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteQuestIdsNotifyNotifyWraper()
	{
		
		m_CompleteQuestIds = CompletedQuestListWraper();

	}
	//赋值构造函数
	QuestRpcCompleteQuestIdsNotifyNotifyWraper(const QuestRpcCompleteQuestIdsNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteQuestIdsNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteQuestIdsNotifyNotify ToPB() const
	{
		QuestRpcCompleteQuestIdsNotifyNotify v;
		*v.mutable_completequestids()= m_CompleteQuestIds.ToPB();

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
		QuestRpcCompleteQuestIdsNotifyNotify pb;
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
	void Init(const QuestRpcCompleteQuestIdsNotifyNotify& v)
	{
		m_CompleteQuestIds = v.completequestids();

	}

private:
	//完成的任务列表
	CompletedQuestListWraper m_CompleteQuestIds;
public:
	void SetCompleteQuestIds( const CompletedQuestListWraper& v)
	{
		m_CompleteQuestIds=v;
	}
	CompletedQuestListWraper GetCompleteQuestIds()
	{
		return m_CompleteQuestIds;
	}
	CompletedQuestListWraper GetCompleteQuestIds() const
	{
		return m_CompleteQuestIds;
	}

};
//通知新可接任务通知封装类
class QuestRpcSyncCanAcceptQuestNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncCanAcceptQuestNotifyWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcSyncCanAcceptQuestNotifyWraper(const QuestRpcSyncCanAcceptQuestNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncCanAcceptQuestNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncCanAcceptQuestNotify ToPB() const
	{
		QuestRpcSyncCanAcceptQuestNotify v;
		v.mutable_canacceptquest()->Reserve(m_CanAcceptQuest.size());
		for (int i=0; i<(int)m_CanAcceptQuest.size(); i++)
		{
			v.add_canacceptquest(m_CanAcceptQuest[i]);
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
		QuestRpcSyncCanAcceptQuestNotify pb;
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
	void Init(const QuestRpcSyncCanAcceptQuestNotify& v)
	{
		m_CanAcceptQuest.clear();
		m_CanAcceptQuest.reserve(v.canacceptquest_size());
		for( int i=0; i<v.canacceptquest_size(); i++)
			m_CanAcceptQuest.push_back(v.canacceptquest(i));

	}

private:
	//新的可接任务
	vector<INT32> m_CanAcceptQuest;
public:
	int SizeCanAcceptQuest()
	{
		return m_CanAcceptQuest.size();
	}
	const vector<INT32>& GetCanAcceptQuest() const
	{
		return m_CanAcceptQuest;
	}
	INT32 GetCanAcceptQuest(int Index) const
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.size())
		{
			assert(false);
			return INT32();
		}
		return m_CanAcceptQuest[Index];
	}
	void SetCanAcceptQuest( const vector<INT32>& v )
	{
		m_CanAcceptQuest=v;
	}
	void ClearCanAcceptQuest( )
	{
		m_CanAcceptQuest.clear();
	}
	void SetCanAcceptQuest( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.size())
		{
			assert(false);
			return;
		}
		m_CanAcceptQuest[Index] = v;
	}
	void AddCanAcceptQuest( INT32 v = -1 )
	{
		m_CanAcceptQuest.push_back(v);
	}

};
//精英怪击杀次数回应封装类
class QuestRpcEliteFinishCountReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcEliteFinishCountReplyWraper()
	{
		
		m_Result = -1;
		m_Count = -1;

	}
	//赋值构造函数
	QuestRpcEliteFinishCountReplyWraper(const QuestRpcEliteFinishCountReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcEliteFinishCountReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcEliteFinishCountReply ToPB() const
	{
		QuestRpcEliteFinishCountReply v;
		v.set_result( m_Result );
		v.set_count( m_Count );

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
		QuestRpcEliteFinishCountReply pb;
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
	void Init(const QuestRpcEliteFinishCountReply& v)
	{
		m_Result = v.result();
		m_Count = v.count();

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
	//精英怪击杀次数
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}

};
//最大类型任务通知通知封装类
class QuestRpcQuestMaxListNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcQuestMaxListNotifyNotifyWraper()
	{
		
		m_QuestList = QuestMaxQuestListWraper();

	}
	//赋值构造函数
	QuestRpcQuestMaxListNotifyNotifyWraper(const QuestRpcQuestMaxListNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcQuestMaxListNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcQuestMaxListNotifyNotify ToPB() const
	{
		QuestRpcQuestMaxListNotifyNotify v;
		*v.mutable_questlist()= m_QuestList.ToPB();

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
		QuestRpcQuestMaxListNotifyNotify pb;
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
	void Init(const QuestRpcQuestMaxListNotifyNotify& v)
	{
		m_QuestList = v.questlist();

	}

private:
	//任务列表
	QuestMaxQuestListWraper m_QuestList;
public:
	void SetQuestList( const QuestMaxQuestListWraper& v)
	{
		m_QuestList=v;
	}
	QuestMaxQuestListWraper GetQuestList()
	{
		return m_QuestList;
	}
	QuestMaxQuestListWraper GetQuestList() const
	{
		return m_QuestList;
	}

};
//任务列表回应封装类
class QuestRpcQuestMaxListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcQuestMaxListReplyWraper()
	{
		
		m_Result = -1;
		m_QuestList = QuestMaxQuestListWraper();

	}
	//赋值构造函数
	QuestRpcQuestMaxListReplyWraper(const QuestRpcQuestMaxListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcQuestMaxListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcQuestMaxListReply ToPB() const
	{
		QuestRpcQuestMaxListReply v;
		v.set_result( m_Result );
		*v.mutable_questlist()= m_QuestList.ToPB();

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
		QuestRpcQuestMaxListReply pb;
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
	void Init(const QuestRpcQuestMaxListReply& v)
	{
		m_Result = v.result();
		m_QuestList = v.questlist();

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
	//任务列表
	QuestMaxQuestListWraper m_QuestList;
public:
	void SetQuestList( const QuestMaxQuestListWraper& v)
	{
		m_QuestList=v;
	}
	QuestMaxQuestListWraper GetQuestList()
	{
		return m_QuestList;
	}
	QuestMaxQuestListWraper GetQuestList() const
	{
		return m_QuestList;
	}

};
//完成任务id请求回应封装类
class QuestRpcSyncCompleteQuestIdsReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncCompleteQuestIdsReplyWraper()
	{
		
		m_Result = -1;
		m_CompleteQuestIds = CompletedQuestListWraper();

	}
	//赋值构造函数
	QuestRpcSyncCompleteQuestIdsReplyWraper(const QuestRpcSyncCompleteQuestIdsReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncCompleteQuestIdsReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncCompleteQuestIdsReply ToPB() const
	{
		QuestRpcSyncCompleteQuestIdsReply v;
		v.set_result( m_Result );
		*v.mutable_completequestids()= m_CompleteQuestIds.ToPB();

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
		QuestRpcSyncCompleteQuestIdsReply pb;
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
	void Init(const QuestRpcSyncCompleteQuestIdsReply& v)
	{
		m_Result = v.result();
		m_CompleteQuestIds = v.completequestids();

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
	//完成的任务列表
	CompletedQuestListWraper m_CompleteQuestIds;
public:
	void SetCompleteQuestIds( const CompletedQuestListWraper& v)
	{
		m_CompleteQuestIds=v;
	}
	CompletedQuestListWraper GetCompleteQuestIds()
	{
		return m_CompleteQuestIds;
	}
	CompletedQuestListWraper GetCompleteQuestIds() const
	{
		return m_CompleteQuestIds;
	}

};
//完成任务id请求请求封装类
class QuestRpcSyncCompleteQuestIdsAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncCompleteQuestIdsAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcSyncCompleteQuestIdsAskWraper(const QuestRpcSyncCompleteQuestIdsAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncCompleteQuestIdsAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncCompleteQuestIdsAsk ToPB() const
	{
		QuestRpcSyncCompleteQuestIdsAsk v;

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
		QuestRpcSyncCompleteQuestIdsAsk pb;
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
	void Init(const QuestRpcSyncCompleteQuestIdsAsk& v)
	{

	}


};
//GetReward回应封装类
class QuestRpcGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGetRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcGetRewardReplyWraper(const QuestRpcGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGetRewardReply ToPB() const
	{
		QuestRpcGetRewardReply v;
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
		QuestRpcGetRewardReply pb;
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
	void Init(const QuestRpcGetRewardReply& v)
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
//更新任务通知封装类
class QuestRpcUpdateQuestNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcUpdateQuestNotifyWraper()
	{
		
		m_Quest = QuestDataWraper();

	}
	//赋值构造函数
	QuestRpcUpdateQuestNotifyWraper(const QuestRpcUpdateQuestNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcUpdateQuestNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcUpdateQuestNotify ToPB() const
	{
		QuestRpcUpdateQuestNotify v;
		*v.mutable_quest()= m_Quest.ToPB();

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
		QuestRpcUpdateQuestNotify pb;
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
	void Init(const QuestRpcUpdateQuestNotify& v)
	{
		m_Quest = v.quest();

	}

private:
	//任务数据
	QuestDataWraper m_Quest;
public:
	void SetQuest( const QuestDataWraper& v)
	{
		m_Quest=v;
	}
	QuestDataWraper GetQuest()
	{
		return m_Quest;
	}
	QuestDataWraper GetQuest() const
	{
		return m_Quest;
	}

};
//调用客户端Lua通知封装类
class QuestRpcCallClientLuaNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCallClientLuaNotifyWraper()
	{
		
		m_Str = "";

	}
	//赋值构造函数
	QuestRpcCallClientLuaNotifyWraper(const QuestRpcCallClientLuaNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCallClientLuaNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCallClientLuaNotify ToPB() const
	{
		QuestRpcCallClientLuaNotify v;
		v.set_str( m_Str );

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
		QuestRpcCallClientLuaNotify pb;
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
	void Init(const QuestRpcCallClientLuaNotify& v)
	{
		m_Str = v.str();

	}

private:
	//lua函数字符串
	string m_Str;
public:
	void SetStr( const string& v)
	{
		m_Str=v;
	}
	string GetStr()
	{
		return m_Str;
	}
	string GetStr() const
	{
		return m_Str;
	}

};
//放弃任务回应封装类
class QuestRpcGiveUpQuestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGiveUpQuestReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	QuestRpcGiveUpQuestReplyWraper(const QuestRpcGiveUpQuestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGiveUpQuestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGiveUpQuestReply ToPB() const
	{
		QuestRpcGiveUpQuestReply v;
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
		QuestRpcGiveUpQuestReply pb;
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
	void Init(const QuestRpcGiveUpQuestReply& v)
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
//放弃任务请求封装类
class QuestRpcGiveUpQuestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGiveUpQuestAskWraper()
	{
		
		m_QuestConfigId = -1;

	}
	//赋值构造函数
	QuestRpcGiveUpQuestAskWraper(const QuestRpcGiveUpQuestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGiveUpQuestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGiveUpQuestAsk ToPB() const
	{
		QuestRpcGiveUpQuestAsk v;
		v.set_questconfigid( m_QuestConfigId );

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
		QuestRpcGiveUpQuestAsk pb;
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
	void Init(const QuestRpcGiveUpQuestAsk& v)
	{
		m_QuestConfigId = v.questconfigid();

	}

private:
	//任务表的id
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}

};
//CompleteQuestStep请求封装类
class QuestRpcCompleteQuestStepAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteQuestStepAskWraper()
	{
		
		m_QuestConfigId = -1;
		m_QuestStep = -1;
		m_TargetId = -1;
		m_QuestStepEventType = -1;

	}
	//赋值构造函数
	QuestRpcCompleteQuestStepAskWraper(const QuestRpcCompleteQuestStepAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteQuestStepAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteQuestStepAsk ToPB() const
	{
		QuestRpcCompleteQuestStepAsk v;
		v.set_questconfigid( m_QuestConfigId );
		v.set_queststep( m_QuestStep );
		v.set_targetid( m_TargetId );
		v.set_queststepeventtype( m_QuestStepEventType );

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
		QuestRpcCompleteQuestStepAsk pb;
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
	void Init(const QuestRpcCompleteQuestStepAsk& v)
	{
		m_QuestConfigId = v.questconfigid();
		m_QuestStep = v.queststep();
		m_TargetId = v.targetid();
		m_QuestStepEventType = v.queststepeventtype();

	}

private:
	//任务表的id
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}
private:
	//QuestStep
	INT32 m_QuestStep;
public:
	void SetQuestStep( INT32 v)
	{
		m_QuestStep=v;
	}
	INT32 GetQuestStep()
	{
		return m_QuestStep;
	}
	INT32 GetQuestStep() const
	{
		return m_QuestStep;
	}
private:
	//NpcConfigId
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//事件类型
	INT32 m_QuestStepEventType;
public:
	void SetQuestStepEventType( INT32 v)
	{
		m_QuestStepEventType=v;
	}
	INT32 GetQuestStepEventType()
	{
		return m_QuestStepEventType;
	}
	INT32 GetQuestStepEventType() const
	{
		return m_QuestStepEventType;
	}

};
//OnAcceptQuest通知封装类
class QuestRpcOnAcceptQuestNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcOnAcceptQuestNotifyWraper()
	{
		
		m_AcceptQuest = QuestDataWraper();

	}
	//赋值构造函数
	QuestRpcOnAcceptQuestNotifyWraper(const QuestRpcOnAcceptQuestNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcOnAcceptQuestNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcOnAcceptQuestNotify ToPB() const
	{
		QuestRpcOnAcceptQuestNotify v;
		*v.mutable_acceptquest()= m_AcceptQuest.ToPB();

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
		QuestRpcOnAcceptQuestNotify pb;
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
	void Init(const QuestRpcOnAcceptQuestNotify& v)
	{
		m_AcceptQuest = v.acceptquest();

	}

private:
	//新接受的任务
	QuestDataWraper m_AcceptQuest;
public:
	void SetAcceptQuest( const QuestDataWraper& v)
	{
		m_AcceptQuest=v;
	}
	QuestDataWraper GetAcceptQuest()
	{
		return m_AcceptQuest;
	}
	QuestDataWraper GetAcceptQuest() const
	{
		return m_AcceptQuest;
	}

};
//OnCompleteQuest通知封装类
class QuestRpcOnCompleteQuestNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcOnCompleteQuestNotifyWraper()
	{
		
		m_QuestData = QuestDataWraper();

	}
	//赋值构造函数
	QuestRpcOnCompleteQuestNotifyWraper(const QuestRpcOnCompleteQuestNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcOnCompleteQuestNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcOnCompleteQuestNotify ToPB() const
	{
		QuestRpcOnCompleteQuestNotify v;
		*v.mutable_questdata()= m_QuestData.ToPB();

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
		QuestRpcOnCompleteQuestNotify pb;
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
	void Init(const QuestRpcOnCompleteQuestNotify& v)
	{
		m_QuestData = v.questdata();

	}

private:
	//任务数据
	QuestDataWraper m_QuestData;
public:
	void SetQuestData( const QuestDataWraper& v)
	{
		m_QuestData=v;
	}
	QuestDataWraper GetQuestData()
	{
		return m_QuestData;
	}
	QuestDataWraper GetQuestData() const
	{
		return m_QuestData;
	}

};
//CompleteQuestStep回应封装类
class QuestRpcCompleteQuestStepReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteQuestStepReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	QuestRpcCompleteQuestStepReplyWraper(const QuestRpcCompleteQuestStepReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteQuestStepReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteQuestStepReply ToPB() const
	{
		QuestRpcCompleteQuestStepReply v;
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
		QuestRpcCompleteQuestStepReply pb;
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
	void Init(const QuestRpcCompleteQuestStepReply& v)
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
//完成任务请求封装类
class QuestRpcCompleteQuestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteQuestAskWraper()
	{
		
		m_QuestConfigId = -1;
		m_TargetId = -1;
		m_QuestEventType = -1;

	}
	//赋值构造函数
	QuestRpcCompleteQuestAskWraper(const QuestRpcCompleteQuestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteQuestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteQuestAsk ToPB() const
	{
		QuestRpcCompleteQuestAsk v;
		v.set_questconfigid( m_QuestConfigId );
		v.set_targetid( m_TargetId );
		v.set_questeventtype( m_QuestEventType );

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
		QuestRpcCompleteQuestAsk pb;
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
	void Init(const QuestRpcCompleteQuestAsk& v)
	{
		m_QuestConfigId = v.questconfigid();
		m_TargetId = v.targetid();
		m_QuestEventType = v.questeventtype();

	}

private:
	//任务表的id
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}
private:
	//NpcConfigId
	INT32 m_TargetId;
public:
	void SetTargetId( INT32 v)
	{
		m_TargetId=v;
	}
	INT32 GetTargetId()
	{
		return m_TargetId;
	}
	INT32 GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//事件类型
	INT32 m_QuestEventType;
public:
	void SetQuestEventType( INT32 v)
	{
		m_QuestEventType=v;
	}
	INT32 GetQuestEventType()
	{
		return m_QuestEventType;
	}
	INT32 GetQuestEventType() const
	{
		return m_QuestEventType;
	}

};
//SyncQuest请求封装类
class QuestRpcSyncQuestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncQuestAskWraper()
	{
		

	}
	//赋值构造函数
	QuestRpcSyncQuestAskWraper(const QuestRpcSyncQuestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncQuestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncQuestAsk ToPB() const
	{
		QuestRpcSyncQuestAsk v;

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
		QuestRpcSyncQuestAsk pb;
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
	void Init(const QuestRpcSyncQuestAsk& v)
	{

	}


};
//客户端接受任务回应封装类
class QuestRpcAcceptQuestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcAcceptQuestReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcAcceptQuestReplyWraper(const QuestRpcAcceptQuestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcAcceptQuestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcAcceptQuestReply ToPB() const
	{
		QuestRpcAcceptQuestReply v;
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
		QuestRpcAcceptQuestReply pb;
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
	void Init(const QuestRpcAcceptQuestReply& v)
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
//GetReward请求封装类
class QuestRpcGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcGetRewardAskWraper()
	{
		
		m_QuestConfigId = -1;

	}
	//赋值构造函数
	QuestRpcGetRewardAskWraper(const QuestRpcGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcGetRewardAsk ToPB() const
	{
		QuestRpcGetRewardAsk v;
		v.set_questconfigid( m_QuestConfigId );

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
		QuestRpcGetRewardAsk pb;
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
	void Init(const QuestRpcGetRewardAsk& v)
	{
		m_QuestConfigId = v.questconfigid();

	}

private:
	//接受任务表
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}

};
//SyncQuest回应封装类
class QuestRpcSyncQuestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcSyncQuestReplyWraper()
	{
		
		m_Result = -1;
		m_QuestList = QuestListDataWraper();

	}
	//赋值构造函数
	QuestRpcSyncQuestReplyWraper(const QuestRpcSyncQuestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcSyncQuestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcSyncQuestReply ToPB() const
	{
		QuestRpcSyncQuestReply v;
		v.set_result( m_Result );
		*v.mutable_questlist()= m_QuestList.ToPB();
		v.mutable_completequestidslist()->Reserve(m_CompleteQuestIdsList.size());
		for (int i=0; i<(int)m_CompleteQuestIdsList.size(); i++)
		{
			v.add_completequestidslist(m_CompleteQuestIdsList[i]);
		}
		v.mutable_canacceptquest()->Reserve(m_CanAcceptQuest.size());
		for (int i=0; i<(int)m_CanAcceptQuest.size(); i++)
		{
			v.add_canacceptquest(m_CanAcceptQuest[i]);
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
		QuestRpcSyncQuestReply pb;
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
	void Init(const QuestRpcSyncQuestReply& v)
	{
		m_Result = v.result();
		m_QuestList = v.questlist();
		m_CompleteQuestIdsList.clear();
		m_CompleteQuestIdsList.reserve(v.completequestidslist_size());
		for( int i=0; i<v.completequestidslist_size(); i++)
			m_CompleteQuestIdsList.push_back(v.completequestidslist(i));
		m_CanAcceptQuest.clear();
		m_CanAcceptQuest.reserve(v.canacceptquest_size());
		for( int i=0; i<v.canacceptquest_size(); i++)
			m_CanAcceptQuest.push_back(v.canacceptquest(i));

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
	//任务列表
	QuestListDataWraper m_QuestList;
public:
	void SetQuestList( const QuestListDataWraper& v)
	{
		m_QuestList=v;
	}
	QuestListDataWraper GetQuestList()
	{
		return m_QuestList;
	}
	QuestListDataWraper GetQuestList() const
	{
		return m_QuestList;
	}
private:
	//完成任务列表
	vector<INT32> m_CompleteQuestIdsList;
public:
	int SizeCompleteQuestIdsList()
	{
		return m_CompleteQuestIdsList.size();
	}
	const vector<INT32>& GetCompleteQuestIdsList() const
	{
		return m_CompleteQuestIdsList;
	}
	INT32 GetCompleteQuestIdsList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CompleteQuestIdsList.size())
		{
			assert(false);
			return INT32();
		}
		return m_CompleteQuestIdsList[Index];
	}
	void SetCompleteQuestIdsList( const vector<INT32>& v )
	{
		m_CompleteQuestIdsList=v;
	}
	void ClearCompleteQuestIdsList( )
	{
		m_CompleteQuestIdsList.clear();
	}
	void SetCompleteQuestIdsList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_CompleteQuestIdsList.size())
		{
			assert(false);
			return;
		}
		m_CompleteQuestIdsList[Index] = v;
	}
	void AddCompleteQuestIdsList( INT32 v = -1 )
	{
		m_CompleteQuestIdsList.push_back(v);
	}
private:
	//可接的任务
	vector<INT32> m_CanAcceptQuest;
public:
	int SizeCanAcceptQuest()
	{
		return m_CanAcceptQuest.size();
	}
	const vector<INT32>& GetCanAcceptQuest() const
	{
		return m_CanAcceptQuest;
	}
	INT32 GetCanAcceptQuest(int Index) const
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.size())
		{
			assert(false);
			return INT32();
		}
		return m_CanAcceptQuest[Index];
	}
	void SetCanAcceptQuest( const vector<INT32>& v )
	{
		m_CanAcceptQuest=v;
	}
	void ClearCanAcceptQuest( )
	{
		m_CanAcceptQuest.clear();
	}
	void SetCanAcceptQuest( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_CanAcceptQuest.size())
		{
			assert(false);
			return;
		}
		m_CanAcceptQuest[Index] = v;
	}
	void AddCanAcceptQuest( INT32 v = -1 )
	{
		m_CanAcceptQuest.push_back(v);
	}

};
//完成接受任务对话框请求封装类
class QuestRpcCompleteAcceptChatMenuAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteAcceptChatMenuAskWraper()
	{
		
		m_QuestConfigId = -1;

	}
	//赋值构造函数
	QuestRpcCompleteAcceptChatMenuAskWraper(const QuestRpcCompleteAcceptChatMenuAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteAcceptChatMenuAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteAcceptChatMenuAsk ToPB() const
	{
		QuestRpcCompleteAcceptChatMenuAsk v;
		v.set_questconfigid( m_QuestConfigId );

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
		QuestRpcCompleteAcceptChatMenuAsk pb;
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
	void Init(const QuestRpcCompleteAcceptChatMenuAsk& v)
	{
		m_QuestConfigId = v.questconfigid();

	}

private:
	//任务表的id
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}

};
//完成任务回应封装类
class QuestRpcCompleteQuestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteQuestReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcCompleteQuestReplyWraper(const QuestRpcCompleteQuestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteQuestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteQuestReply ToPB() const
	{
		QuestRpcCompleteQuestReply v;
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
		QuestRpcCompleteQuestReply pb;
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
	void Init(const QuestRpcCompleteQuestReply& v)
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
//客户端接受任务请求封装类
class QuestRpcAcceptQuestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcAcceptQuestAskWraper()
	{
		
		m_Type = -1;
		m_QuestConfigId = -1;

	}
	//赋值构造函数
	QuestRpcAcceptQuestAskWraper(const QuestRpcAcceptQuestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcAcceptQuestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcAcceptQuestAsk ToPB() const
	{
		QuestRpcAcceptQuestAsk v;
		v.set_type( m_Type );
		v.set_questconfigid( m_QuestConfigId );

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
		QuestRpcAcceptQuestAsk pb;
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
	void Init(const QuestRpcAcceptQuestAsk& v)
	{
		m_Type = v.type();
		m_QuestConfigId = v.questconfigid();

	}

private:
	//任务类型
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
private:
	//接受任务表
	INT32 m_QuestConfigId;
public:
	void SetQuestConfigId( INT32 v)
	{
		m_QuestConfigId=v;
	}
	INT32 GetQuestConfigId()
	{
		return m_QuestConfigId;
	}
	INT32 GetQuestConfigId() const
	{
		return m_QuestConfigId;
	}

};
//完成接受任务对话框回应封装类
class QuestRpcCompleteAcceptChatMenuReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	QuestRpcCompleteAcceptChatMenuReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	QuestRpcCompleteAcceptChatMenuReplyWraper(const QuestRpcCompleteAcceptChatMenuReply& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestRpcCompleteAcceptChatMenuReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestRpcCompleteAcceptChatMenuReply ToPB() const
	{
		QuestRpcCompleteAcceptChatMenuReply v;
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
		QuestRpcCompleteAcceptChatMenuReply pb;
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
	void Init(const QuestRpcCompleteAcceptChatMenuReply& v)
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<QuestRpcOnAcceptQuestNotifyWraper>{ enum{ID=RPC_CODE_QUEST_ONACCEPTQUEST_NOTIFY};};
template<> struct MessageIdT<QuestRpcOnCompleteQuestNotifyWraper>{ enum{ID=RPC_CODE_QUEST_ONCOMPLETEQUEST_NOTIFY};};
template<> struct MessageIdT<QuestRpcUpdateQuestNotifyWraper>{ enum{ID=RPC_CODE_QUEST_UPDATEQUEST_NOTIFY};};
template<> struct MessageIdT<QuestRpcRemoveQuestNotifyNotifyWraper>{ enum{ID=RPC_CODE_QUEST_REMOVEQUESTNOTIFY_NOTIFY};};
template<> struct MessageIdT<QuestRpcDailyQuestUpdateNotifyWraper>{ enum{ID=RPC_CODE_QUEST_DAILYQUESTUPDATE_NOTIFY};};
template<> struct MessageIdT<QuestRpcCompleteQuestIdsNotifyNotifyWraper>{ enum{ID=RPC_CODE_QUEST_COMPLETEQUESTIDSNOTIFY_NOTIFY};};
template<> struct MessageIdT<QuestRpcSyncCanAcceptQuestNotifyWraper>{ enum{ID=RPC_CODE_QUEST_SYNCCANACCEPTQUEST_NOTIFY};};


#endif
