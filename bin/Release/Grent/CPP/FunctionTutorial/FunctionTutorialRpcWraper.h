/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperFunctionTutorial.h
* Author:       甘业清
* Description:  功能引导RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_FUNCTIONTUTORIAL_H
#define __RPC_WRAPER_FUNCTIONTUTORIAL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "FunctionTutorialRpc.pb.h"



//功能引导类的枚举定义
enum ConstFunctionTutorialE
{
	MODULE_ID_FUNCTIONTUTORIAL                   = 45,	//功能引导模块ID
	RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST= 4551,	//功能引导-->同步-->请求
	RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST = 4552,	//功能引导-->完成-->请求
	RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST = 4553,	//功能引导-->激活步骤-->请求


};


//完成回应封装类
class FunctionTutorialRpcFinishStepReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcFinishStepReplyWraper()
	{
		
		m_Result = -1;
		m_FunctionID = -1;

	}
	//赋值构造函数
	FunctionTutorialRpcFinishStepReplyWraper(const FunctionTutorialRpcFinishStepReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcFinishStepReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcFinishStepReply ToPB() const
	{
		FunctionTutorialRpcFinishStepReply v;
		v.set_result( m_Result );
		v.set_functionid( m_FunctionID );

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
		FunctionTutorialRpcFinishStepReply pb;
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
	void Init(const FunctionTutorialRpcFinishStepReply& v)
	{
		m_Result = v.result();
		m_FunctionID = v.functionid();

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
	//完成的ID
	INT32 m_FunctionID;
public:
	void SetFunctionID( INT32 v)
	{
		m_FunctionID=v;
	}
	INT32 GetFunctionID()
	{
		return m_FunctionID;
	}
	INT32 GetFunctionID() const
	{
		return m_FunctionID;
	}

};
//激活步骤请求封装类
class FunctionTutorialRpcActiveStepAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcActiveStepAskWraper()
	{
		
		m_FunctionID = -1;

	}
	//赋值构造函数
	FunctionTutorialRpcActiveStepAskWraper(const FunctionTutorialRpcActiveStepAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcActiveStepAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcActiveStepAsk ToPB() const
	{
		FunctionTutorialRpcActiveStepAsk v;
		v.set_functionid( m_FunctionID );

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
		FunctionTutorialRpcActiveStepAsk pb;
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
	void Init(const FunctionTutorialRpcActiveStepAsk& v)
	{
		m_FunctionID = v.functionid();

	}

private:
	//引导ID
	INT32 m_FunctionID;
public:
	void SetFunctionID( INT32 v)
	{
		m_FunctionID=v;
	}
	INT32 GetFunctionID()
	{
		return m_FunctionID;
	}
	INT32 GetFunctionID() const
	{
		return m_FunctionID;
	}

};
//激活步骤回应封装类
class FunctionTutorialRpcActiveStepReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcActiveStepReplyWraper()
	{
		
		m_Result = -1;
		m_FunctionID = -1;

	}
	//赋值构造函数
	FunctionTutorialRpcActiveStepReplyWraper(const FunctionTutorialRpcActiveStepReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcActiveStepReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcActiveStepReply ToPB() const
	{
		FunctionTutorialRpcActiveStepReply v;
		v.set_result( m_Result );
		v.set_functionid( m_FunctionID );

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
		FunctionTutorialRpcActiveStepReply pb;
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
	void Init(const FunctionTutorialRpcActiveStepReply& v)
	{
		m_Result = v.result();
		m_FunctionID = v.functionid();

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
	//引导ID
	INT32 m_FunctionID;
public:
	void SetFunctionID( INT32 v)
	{
		m_FunctionID=v;
	}
	INT32 GetFunctionID()
	{
		return m_FunctionID;
	}
	INT32 GetFunctionID() const
	{
		return m_FunctionID;
	}

};
//同步请求封装类
class FunctionTutorialRpcSyncFunctionStepAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcSyncFunctionStepAskWraper()
	{
		

	}
	//赋值构造函数
	FunctionTutorialRpcSyncFunctionStepAskWraper(const FunctionTutorialRpcSyncFunctionStepAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcSyncFunctionStepAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcSyncFunctionStepAsk ToPB() const
	{
		FunctionTutorialRpcSyncFunctionStepAsk v;

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
		FunctionTutorialRpcSyncFunctionStepAsk pb;
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
	void Init(const FunctionTutorialRpcSyncFunctionStepAsk& v)
	{

	}


};
//同步回应封装类
class FunctionTutorialRpcSyncFunctionStepReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcSyncFunctionStepReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	FunctionTutorialRpcSyncFunctionStepReplyWraper(const FunctionTutorialRpcSyncFunctionStepReply& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcSyncFunctionStepReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcSyncFunctionStepReply ToPB() const
	{
		FunctionTutorialRpcSyncFunctionStepReply v;
		v.set_result( m_Result );
		v.mutable_functionlist()->Reserve(m_FunctionList.size());
		for (int i=0; i<(int)m_FunctionList.size(); i++)
		{
			v.add_functionlist(m_FunctionList[i]);
		}
		v.mutable_activefunctionlist()->Reserve(m_ActiveFunctionList.size());
		for (int i=0; i<(int)m_ActiveFunctionList.size(); i++)
		{
			v.add_activefunctionlist(m_ActiveFunctionList[i]);
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
		FunctionTutorialRpcSyncFunctionStepReply pb;
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
	void Init(const FunctionTutorialRpcSyncFunctionStepReply& v)
	{
		m_Result = v.result();
		m_FunctionList.clear();
		m_FunctionList.reserve(v.functionlist_size());
		for( int i=0; i<v.functionlist_size(); i++)
			m_FunctionList.push_back(v.functionlist(i));
		m_ActiveFunctionList.clear();
		m_ActiveFunctionList.reserve(v.activefunctionlist_size());
		for( int i=0; i<v.activefunctionlist_size(); i++)
			m_ActiveFunctionList.push_back(v.activefunctionlist(i));

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
	//已完成步骤Id
	vector<INT32> m_FunctionList;
public:
	int SizeFunctionList()
	{
		return m_FunctionList.size();
	}
	const vector<INT32>& GetFunctionList() const
	{
		return m_FunctionList;
	}
	INT32 GetFunctionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_FunctionList.size())
		{
			assert(false);
			return INT32();
		}
		return m_FunctionList[Index];
	}
	void SetFunctionList( const vector<INT32>& v )
	{
		m_FunctionList=v;
	}
	void ClearFunctionList( )
	{
		m_FunctionList.clear();
	}
	void SetFunctionList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_FunctionList.size())
		{
			assert(false);
			return;
		}
		m_FunctionList[Index] = v;
	}
	void AddFunctionList( INT32 v = -1 )
	{
		m_FunctionList.push_back(v);
	}
private:
	//激活的
	vector<INT32> m_ActiveFunctionList;
public:
	int SizeActiveFunctionList()
	{
		return m_ActiveFunctionList.size();
	}
	const vector<INT32>& GetActiveFunctionList() const
	{
		return m_ActiveFunctionList;
	}
	INT32 GetActiveFunctionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ActiveFunctionList.size())
		{
			assert(false);
			return INT32();
		}
		return m_ActiveFunctionList[Index];
	}
	void SetActiveFunctionList( const vector<INT32>& v )
	{
		m_ActiveFunctionList=v;
	}
	void ClearActiveFunctionList( )
	{
		m_ActiveFunctionList.clear();
	}
	void SetActiveFunctionList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ActiveFunctionList.size())
		{
			assert(false);
			return;
		}
		m_ActiveFunctionList[Index] = v;
	}
	void AddActiveFunctionList( INT32 v = -1 )
	{
		m_ActiveFunctionList.push_back(v);
	}

};
//完成请求封装类
class FunctionTutorialRpcFinishStepAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	FunctionTutorialRpcFinishStepAskWraper()
	{
		
		m_FunctionID = -1;

	}
	//赋值构造函数
	FunctionTutorialRpcFinishStepAskWraper(const FunctionTutorialRpcFinishStepAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const FunctionTutorialRpcFinishStepAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FunctionTutorialRpcFinishStepAsk ToPB() const
	{
		FunctionTutorialRpcFinishStepAsk v;
		v.set_functionid( m_FunctionID );

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
		FunctionTutorialRpcFinishStepAsk pb;
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
	void Init(const FunctionTutorialRpcFinishStepAsk& v)
	{
		m_FunctionID = v.functionid();

	}

private:
	//步骤ID
	INT32 m_FunctionID;
public:
	void SetFunctionID( INT32 v)
	{
		m_FunctionID=v;
	}
	INT32 GetFunctionID()
	{
		return m_FunctionID;
	}
	INT32 GetFunctionID() const
	{
		return m_FunctionID;
	}

};

template<typename T> struct MessageIdT;


#endif
