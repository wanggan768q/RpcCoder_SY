/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperExpressionAction.h
* Author:       甘业清
* Description:  表情动作RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_EXPRESSIONACTION_H
#define __RPC_WRAPER_EXPRESSIONACTION_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ExpressionActionRpc.pb.h"



//表情动作类的枚举定义
enum ConstExpressionActionE
{
	MODULE_ID_EXPRESSIONACTION                   = 49,	//表情动作模块ID
	RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST       = 4951,	//表情动作-->数据同步-->请求
	RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST   = 4952,	//表情动作-->设置轮盘-->请求
	RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST  = 4953,	//表情动作-->使用表情-->请求
	RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY= 4954,	//表情动作-->使用表情通知-->通知


};


//使用表情请求封装类
class ExpressionActionRpcUseActionAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcUseActionAskWraper()
	{
		
		m_ActionId = -1;

	}
	//赋值构造函数
	ExpressionActionRpcUseActionAskWraper(const ExpressionActionRpcUseActionAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcUseActionAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcUseActionAsk ToPB() const
	{
		ExpressionActionRpcUseActionAsk v;
		v.set_actionid( m_ActionId );

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
		ExpressionActionRpcUseActionAsk pb;
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
	void Init(const ExpressionActionRpcUseActionAsk& v)
	{
		m_ActionId = v.actionid();

	}

private:
	//表情ID
	INT32 m_ActionId;
public:
	void SetActionId( INT32 v)
	{
		m_ActionId=v;
	}
	INT32 GetActionId()
	{
		return m_ActionId;
	}
	INT32 GetActionId() const
	{
		return m_ActionId;
	}

};
//使用表情回应封装类
class ExpressionActionRpcUseActionReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcUseActionReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ExpressionActionRpcUseActionReplyWraper(const ExpressionActionRpcUseActionReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcUseActionReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcUseActionReply ToPB() const
	{
		ExpressionActionRpcUseActionReply v;
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
		ExpressionActionRpcUseActionReply pb;
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
	void Init(const ExpressionActionRpcUseActionReply& v)
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
//使用表情通知通知封装类
class ExpressionActionRpcUseActionNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcUseActionNotifyNotifyWraper()
	{
		
		m_ObjId = -1;
		m_ActionId = -1;

	}
	//赋值构造函数
	ExpressionActionRpcUseActionNotifyNotifyWraper(const ExpressionActionRpcUseActionNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcUseActionNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcUseActionNotifyNotify ToPB() const
	{
		ExpressionActionRpcUseActionNotifyNotify v;
		v.set_objid( m_ObjId );
		v.set_actionid( m_ActionId );

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
		ExpressionActionRpcUseActionNotifyNotify pb;
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
	void Init(const ExpressionActionRpcUseActionNotifyNotify& v)
	{
		m_ObjId = v.objid();
		m_ActionId = v.actionid();

	}

private:
	//角色Id
	INT32 m_ObjId;
public:
	void SetObjId( INT32 v)
	{
		m_ObjId=v;
	}
	INT32 GetObjId()
	{
		return m_ObjId;
	}
	INT32 GetObjId() const
	{
		return m_ObjId;
	}
private:
	//动作ID
	INT32 m_ActionId;
public:
	void SetActionId( INT32 v)
	{
		m_ActionId=v;
	}
	INT32 GetActionId()
	{
		return m_ActionId;
	}
	INT32 GetActionId() const
	{
		return m_ActionId;
	}

};
//设置轮盘回应封装类
class ExpressionActionRpcSetWheelReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcSetWheelReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ExpressionActionRpcSetWheelReplyWraper(const ExpressionActionRpcSetWheelReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcSetWheelReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcSetWheelReply ToPB() const
	{
		ExpressionActionRpcSetWheelReply v;
		v.set_result( m_Result );
		v.mutable_wheellist()->Reserve(m_WheelList.size());
		for (int i=0; i<(int)m_WheelList.size(); i++)
		{
			v.add_wheellist(m_WheelList[i]);
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
		ExpressionActionRpcSetWheelReply pb;
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
	void Init(const ExpressionActionRpcSetWheelReply& v)
	{
		m_Result = v.result();
		m_WheelList.clear();
		m_WheelList.reserve(v.wheellist_size());
		for( int i=0; i<v.wheellist_size(); i++)
			m_WheelList.push_back(v.wheellist(i));

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
	//轮盘信息
	vector<INT32> m_WheelList;
public:
	int SizeWheelList()
	{
		return m_WheelList.size();
	}
	const vector<INT32>& GetWheelList() const
	{
		return m_WheelList;
	}
	INT32 GetWheelList(int Index) const
	{
		if(Index<0 || Index>=(int)m_WheelList.size())
		{
			assert(false);
			return INT32();
		}
		return m_WheelList[Index];
	}
	void SetWheelList( const vector<INT32>& v )
	{
		m_WheelList=v;
	}
	void ClearWheelList( )
	{
		m_WheelList.clear();
	}
	void SetWheelList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_WheelList.size())
		{
			assert(false);
			return;
		}
		m_WheelList[Index] = v;
	}
	void AddWheelList( INT32 v = -1 )
	{
		m_WheelList.push_back(v);
	}

};
//数据同步请求封装类
class ExpressionActionRpcSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcSyncAskWraper()
	{
		

	}
	//赋值构造函数
	ExpressionActionRpcSyncAskWraper(const ExpressionActionRpcSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcSyncAsk ToPB() const
	{
		ExpressionActionRpcSyncAsk v;

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
		ExpressionActionRpcSyncAsk pb;
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
	void Init(const ExpressionActionRpcSyncAsk& v)
	{

	}


};
//数据同步回应封装类
class ExpressionActionRpcSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcSyncReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ExpressionActionRpcSyncReplyWraper(const ExpressionActionRpcSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcSyncReply ToPB() const
	{
		ExpressionActionRpcSyncReply v;
		v.set_result( m_Result );
		v.mutable_expressionactionlist()->Reserve(m_ExpressionActionList.size());
		for (int i=0; i<(int)m_ExpressionActionList.size(); i++)
		{
			*v.add_expressionactionlist() = m_ExpressionActionList[i].ToPB();
		}
		v.mutable_expressionwheellist()->Reserve(m_ExpressionWheelList.size());
		for (int i=0; i<(int)m_ExpressionWheelList.size(); i++)
		{
			v.add_expressionwheellist(m_ExpressionWheelList[i]);
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
		ExpressionActionRpcSyncReply pb;
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
	void Init(const ExpressionActionRpcSyncReply& v)
	{
		m_Result = v.result();
		m_ExpressionActionList.clear();
		m_ExpressionActionList.reserve(v.expressionactionlist_size());
		for( int i=0; i<v.expressionactionlist_size(); i++)
			m_ExpressionActionList.push_back(v.expressionactionlist(i));
		m_ExpressionWheelList.clear();
		m_ExpressionWheelList.reserve(v.expressionwheellist_size());
		for( int i=0; i<v.expressionwheellist_size(); i++)
			m_ExpressionWheelList.push_back(v.expressionwheellist(i));

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
	//表情信息
	vector<ExpressionActionInfoWraper> m_ExpressionActionList;
public:
	int SizeExpressionActionList()
	{
		return m_ExpressionActionList.size();
	}
	const vector<ExpressionActionInfoWraper>& GetExpressionActionList() const
	{
		return m_ExpressionActionList;
	}
	ExpressionActionInfoWraper GetExpressionActionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExpressionActionList.size())
		{
			assert(false);
			return ExpressionActionInfoWraper();
		}
		return m_ExpressionActionList[Index];
	}
	void SetExpressionActionList( const vector<ExpressionActionInfoWraper>& v )
	{
		m_ExpressionActionList=v;
	}
	void ClearExpressionActionList( )
	{
		m_ExpressionActionList.clear();
	}
	void SetExpressionActionList( int Index, const ExpressionActionInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExpressionActionList.size())
		{
			assert(false);
			return;
		}
		m_ExpressionActionList[Index] = v;
	}
	void AddExpressionActionList( const ExpressionActionInfoWraper& v )
	{
		m_ExpressionActionList.push_back(v);
	}
private:
	//轮盘
	vector<INT32> m_ExpressionWheelList;
public:
	int SizeExpressionWheelList()
	{
		return m_ExpressionWheelList.size();
	}
	const vector<INT32>& GetExpressionWheelList() const
	{
		return m_ExpressionWheelList;
	}
	INT32 GetExpressionWheelList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExpressionWheelList.size())
		{
			assert(false);
			return INT32();
		}
		return m_ExpressionWheelList[Index];
	}
	void SetExpressionWheelList( const vector<INT32>& v )
	{
		m_ExpressionWheelList=v;
	}
	void ClearExpressionWheelList( )
	{
		m_ExpressionWheelList.clear();
	}
	void SetExpressionWheelList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ExpressionWheelList.size())
		{
			assert(false);
			return;
		}
		m_ExpressionWheelList[Index] = v;
	}
	void AddExpressionWheelList( INT32 v = -1 )
	{
		m_ExpressionWheelList.push_back(v);
	}

};
//设置轮盘请求封装类
class ExpressionActionRpcSetWheelAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ExpressionActionRpcSetWheelAskWraper()
	{
		
		m_Index = -1;
		m_ActionId = -1;

	}
	//赋值构造函数
	ExpressionActionRpcSetWheelAskWraper(const ExpressionActionRpcSetWheelAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionRpcSetWheelAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionRpcSetWheelAsk ToPB() const
	{
		ExpressionActionRpcSetWheelAsk v;
		v.set_index( m_Index );
		v.set_actionid( m_ActionId );

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
		ExpressionActionRpcSetWheelAsk pb;
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
	void Init(const ExpressionActionRpcSetWheelAsk& v)
	{
		m_Index = v.index();
		m_ActionId = v.actionid();

	}

private:
	//索引
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
	//表情ID
	INT32 m_ActionId;
public:
	void SetActionId( INT32 v)
	{
		m_ActionId=v;
	}
	INT32 GetActionId()
	{
		return m_ActionId;
	}
	INT32 GetActionId() const
	{
		return m_ActionId;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ExpressionActionRpcUseActionNotifyNotifyWraper>{ enum{ID=RPC_CODE_EXPRESSIONACTION_USEACTIONNOTIFY_NOTIFY};};


#endif
