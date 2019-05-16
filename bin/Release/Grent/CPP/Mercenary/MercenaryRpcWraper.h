/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMercenary.h
* Author:       甘业清
* Description:  佣兵RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MERCENARY_H
#define __RPC_WRAPER_MERCENARY_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MercenaryRpc.pb.h"



//佣兵类的枚举定义
enum ConstMercenaryE
{
	MODULE_ID_MERCENARY                          = 51,	//佣兵模块ID
	RPC_CODE_MERCENARY_INQUEUE_REQUEST           = 5151,	//佣兵-->入队-->请求
	RPC_CODE_MERCENARY_OUTQUEUE_REQUEST          = 5152,	//佣兵-->出队-->请求
	RPC_CODE_MERCENARY_AUTOSET_REQUEST           = 5153,	//佣兵-->自动配置-->请求
	RPC_CODE_MERCENARY_INFO_REQUEST              = 5154,	//佣兵-->请求佣兵信息-->请求


};


//自动配置回应封装类
class MercenaryRpcAutoSetReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcAutoSetReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MercenaryRpcAutoSetReplyWraper(const MercenaryRpcAutoSetReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcAutoSetReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcAutoSetReply ToPB() const
	{
		MercenaryRpcAutoSetReply v;
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
		MercenaryRpcAutoSetReply pb;
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
	void Init(const MercenaryRpcAutoSetReply& v)
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
//自动配置请求封装类
class MercenaryRpcAutoSetAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcAutoSetAskWraper()
	{
		

	}
	//赋值构造函数
	MercenaryRpcAutoSetAskWraper(const MercenaryRpcAutoSetAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcAutoSetAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcAutoSetAsk ToPB() const
	{
		MercenaryRpcAutoSetAsk v;

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
		MercenaryRpcAutoSetAsk pb;
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
	void Init(const MercenaryRpcAutoSetAsk& v)
	{

	}


};
//佣兵信息回应封装类
class MercenaryRpcInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcInfoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MercenaryRpcInfoReplyWraper(const MercenaryRpcInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcInfoReply ToPB() const
	{
		MercenaryRpcInfoReply v;
		v.set_result( m_Result );
		v.mutable_mercenary()->Reserve(m_Mercenary.size());
		for (int i=0; i<(int)m_Mercenary.size(); i++)
		{
			*v.add_mercenary() = m_Mercenary[i].ToPB();
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
		MercenaryRpcInfoReply pb;
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
	void Init(const MercenaryRpcInfoReply& v)
	{
		m_Result = v.result();
		m_Mercenary.clear();
		m_Mercenary.reserve(v.mercenary_size());
		for( int i=0; i<v.mercenary_size(); i++)
			m_Mercenary.push_back(v.mercenary(i));

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
	//佣兵信息
	vector<MercenaryInfoWraper> m_Mercenary;
public:
	int SizeMercenary()
	{
		return m_Mercenary.size();
	}
	const vector<MercenaryInfoWraper>& GetMercenary() const
	{
		return m_Mercenary;
	}
	MercenaryInfoWraper GetMercenary(int Index) const
	{
		if(Index<0 || Index>=(int)m_Mercenary.size())
		{
			assert(false);
			return MercenaryInfoWraper();
		}
		return m_Mercenary[Index];
	}
	void SetMercenary( const vector<MercenaryInfoWraper>& v )
	{
		m_Mercenary=v;
	}
	void ClearMercenary( )
	{
		m_Mercenary.clear();
	}
	void SetMercenary( int Index, const MercenaryInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Mercenary.size())
		{
			assert(false);
			return;
		}
		m_Mercenary[Index] = v;
	}
	void AddMercenary( const MercenaryInfoWraper& v )
	{
		m_Mercenary.push_back(v);
	}

};
//佣兵信息请求封装类
class MercenaryRpcInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcInfoAskWraper()
	{
		

	}
	//赋值构造函数
	MercenaryRpcInfoAskWraper(const MercenaryRpcInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcInfoAsk ToPB() const
	{
		MercenaryRpcInfoAsk v;

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
		MercenaryRpcInfoAsk pb;
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
	void Init(const MercenaryRpcInfoAsk& v)
	{

	}


};
//入队回应封装类
class MercenaryRpcInQueueReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcInQueueReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MercenaryRpcInQueueReplyWraper(const MercenaryRpcInQueueReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcInQueueReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcInQueueReply ToPB() const
	{
		MercenaryRpcInQueueReply v;
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
		MercenaryRpcInQueueReply pb;
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
	void Init(const MercenaryRpcInQueueReply& v)
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
//入队请求封装类
class MercenaryRpcInQueueAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcInQueueAskWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	MercenaryRpcInQueueAskWraper(const MercenaryRpcInQueueAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcInQueueAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcInQueueAsk ToPB() const
	{
		MercenaryRpcInQueueAsk v;
		v.set_id( m_Id );

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
		MercenaryRpcInQueueAsk pb;
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
	void Init(const MercenaryRpcInQueueAsk& v)
	{
		m_Id = v.id();

	}

private:
	//入队佣兵id
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

};
//出队回应封装类
class MercenaryRpcOutQueueReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcOutQueueReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MercenaryRpcOutQueueReplyWraper(const MercenaryRpcOutQueueReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcOutQueueReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcOutQueueReply ToPB() const
	{
		MercenaryRpcOutQueueReply v;
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
		MercenaryRpcOutQueueReply pb;
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
	void Init(const MercenaryRpcOutQueueReply& v)
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
//出队请求封装类
class MercenaryRpcOutQueueAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MercenaryRpcOutQueueAskWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	MercenaryRpcOutQueueAskWraper(const MercenaryRpcOutQueueAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryRpcOutQueueAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryRpcOutQueueAsk ToPB() const
	{
		MercenaryRpcOutQueueAsk v;
		v.set_id( m_Id );

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
		MercenaryRpcOutQueueAsk pb;
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
	void Init(const MercenaryRpcOutQueueAsk& v)
	{
		m_Id = v.id();

	}

private:
	//出队佣兵id
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

};

template<typename T> struct MessageIdT;


#endif
