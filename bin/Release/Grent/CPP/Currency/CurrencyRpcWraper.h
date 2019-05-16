/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperCurrency.h
* Author:       甘业清
* Description:  货币RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CURRENCY_H
#define __RPC_WRAPER_CURRENCY_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "CurrencyRpc.pb.h"



//货币类的枚举定义
enum ConstCurrencyE
{
	MODULE_ID_CURRENCY                           = 19,	//货币模块ID
	RPC_CODE_CURRENCY_TRANSFROM_REQUEST          = 1951,	//货币-->货币兑换-->请求
	RPC_CODE_CURRENCY_SHOW_REQUEST               = 1952,	//货币-->货币展示-->请求


};


//货币展示请求封装类
class CurrencyRpcShowAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CurrencyRpcShowAskWraper()
	{
		

	}
	//赋值构造函数
	CurrencyRpcShowAskWraper(const CurrencyRpcShowAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CurrencyRpcShowAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CurrencyRpcShowAsk ToPB() const
	{
		CurrencyRpcShowAsk v;

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
		CurrencyRpcShowAsk pb;
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
	void Init(const CurrencyRpcShowAsk& v)
	{

	}


};
//货币展示回应封装类
class CurrencyRpcShowReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CurrencyRpcShowReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CurrencyRpcShowReplyWraper(const CurrencyRpcShowReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CurrencyRpcShowReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CurrencyRpcShowReply ToPB() const
	{
		CurrencyRpcShowReply v;
		v.set_result( m_Result );
		v.mutable_showresources()->Reserve(m_ShowResources.size());
		for (int i=0; i<(int)m_ShowResources.size(); i++)
		{
			*v.add_showresources() = m_ShowResources[i].ToPB();
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
		CurrencyRpcShowReply pb;
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
	void Init(const CurrencyRpcShowReply& v)
	{
		m_Result = v.result();
		m_ShowResources.clear();
		m_ShowResources.reserve(v.showresources_size());
		for( int i=0; i<v.showresources_size(); i++)
			m_ShowResources.push_back(v.showresources(i));

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
	//展示货币信息
	vector<ResourceWraper> m_ShowResources;
public:
	int SizeShowResources()
	{
		return m_ShowResources.size();
	}
	const vector<ResourceWraper>& GetShowResources() const
	{
		return m_ShowResources;
	}
	ResourceWraper GetShowResources(int Index) const
	{
		if(Index<0 || Index>=(int)m_ShowResources.size())
		{
			assert(false);
			return ResourceWraper();
		}
		return m_ShowResources[Index];
	}
	void SetShowResources( const vector<ResourceWraper>& v )
	{
		m_ShowResources=v;
	}
	void ClearShowResources( )
	{
		m_ShowResources.clear();
	}
	void SetShowResources( int Index, const ResourceWraper& v )
	{
		if(Index<0 || Index>=(int)m_ShowResources.size())
		{
			assert(false);
			return;
		}
		m_ShowResources[Index] = v;
	}
	void AddShowResources( const ResourceWraper& v )
	{
		m_ShowResources.push_back(v);
	}

};
//货币兑换请求封装类
class CurrencyRpcTransfromAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CurrencyRpcTransfromAskWraper()
	{
		
		m_To_type = -1;
		m_From_type = -1;
		m_From_num = 0;
		m_Diamond_bind_num = 0;

	}
	//赋值构造函数
	CurrencyRpcTransfromAskWraper(const CurrencyRpcTransfromAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CurrencyRpcTransfromAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CurrencyRpcTransfromAsk ToPB() const
	{
		CurrencyRpcTransfromAsk v;
		v.set_to_type( m_To_type );
		v.set_from_type( m_From_type );
		v.set_from_num( m_From_num );
		v.set_diamond_bind_num( m_Diamond_bind_num );

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
		CurrencyRpcTransfromAsk pb;
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
	void Init(const CurrencyRpcTransfromAsk& v)
	{
		m_To_type = v.to_type();
		m_From_type = v.from_type();
		m_From_num = v.from_num();
		m_Diamond_bind_num = v.diamond_bind_num();

	}

private:
	//兑换目标类型
	INT32 m_To_type;
public:
	void SetTo_type( INT32 v)
	{
		m_To_type=v;
	}
	INT32 GetTo_type()
	{
		return m_To_type;
	}
	INT32 GetTo_type() const
	{
		return m_To_type;
	}
private:
	//兑换来源类型
	INT32 m_From_type;
public:
	void SetFrom_type( INT32 v)
	{
		m_From_type=v;
	}
	INT32 GetFrom_type()
	{
		return m_From_type;
	}
	INT32 GetFrom_type() const
	{
		return m_From_type;
	}
private:
	//兑换来源数量
	int64_t m_From_num;
public:
	void SetFrom_num( int64_t v)
	{
		m_From_num=v;
	}
	int64_t GetFrom_num()
	{
		return m_From_num;
	}
	int64_t GetFrom_num() const
	{
		return m_From_num;
	}
private:
	//绑定钻石使用数量
	int64_t m_Diamond_bind_num;
public:
	void SetDiamond_bind_num( int64_t v)
	{
		m_Diamond_bind_num=v;
	}
	int64_t GetDiamond_bind_num()
	{
		return m_Diamond_bind_num;
	}
	int64_t GetDiamond_bind_num() const
	{
		return m_Diamond_bind_num;
	}

};
//货币兑换回应封装类
class CurrencyRpcTransfromReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CurrencyRpcTransfromReplyWraper()
	{
		
		m_Result = -9999;
		m_Reward_type = -1;
		m_Reward_num = 0;

	}
	//赋值构造函数
	CurrencyRpcTransfromReplyWraper(const CurrencyRpcTransfromReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CurrencyRpcTransfromReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CurrencyRpcTransfromReply ToPB() const
	{
		CurrencyRpcTransfromReply v;
		v.set_result( m_Result );
		v.set_reward_type( m_Reward_type );
		v.set_reward_num( m_Reward_num );

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
		CurrencyRpcTransfromReply pb;
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
	void Init(const CurrencyRpcTransfromReply& v)
	{
		m_Result = v.result();
		m_Reward_type = v.reward_type();
		m_Reward_num = v.reward_num();

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
	//获得货币类型
	INT32 m_Reward_type;
public:
	void SetReward_type( INT32 v)
	{
		m_Reward_type=v;
	}
	INT32 GetReward_type()
	{
		return m_Reward_type;
	}
	INT32 GetReward_type() const
	{
		return m_Reward_type;
	}
private:
	//获得货币数量
	int64_t m_Reward_num;
public:
	void SetReward_num( int64_t v)
	{
		m_Reward_num=v;
	}
	int64_t GetReward_num()
	{
		return m_Reward_num;
	}
	int64_t GetReward_num() const
	{
		return m_Reward_num;
	}

};

template<typename T> struct MessageIdT;


#endif
