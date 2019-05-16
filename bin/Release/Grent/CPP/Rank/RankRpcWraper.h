/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperRank.h
* Author:       甘业清
* Description:  排行榜RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_RANK_H
#define __RPC_WRAPER_RANK_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "RankRpc.pb.h"



//排行榜类的枚举定义
enum ConstRankE
{
	MODULE_ID_RANK                               = 56,	//排行榜模块ID
	RPC_CODE_RANK_RANK_REQUEST                   = 5651,	//排行榜-->请求排行榜-->请求


};


//请求排行榜回应封装类
class RankRpcRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	RankRpcRankReplyWraper()
	{
		
		m_Result = -1;
		m_RankIndex = -1;
		m_MyValue = -1;

	}
	//赋值构造函数
	RankRpcRankReplyWraper(const RankRpcRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const RankRpcRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RankRpcRankReply ToPB() const
	{
		RankRpcRankReply v;
		v.set_result( m_Result );
		v.mutable_rankinfolist()->Reserve(m_RankInfoList.size());
		for (int i=0; i<(int)m_RankInfoList.size(); i++)
		{
			*v.add_rankinfolist() = m_RankInfoList[i].ToPB();
		}
		v.set_rankindex( m_RankIndex );
		v.set_myvalue( m_MyValue );

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
		RankRpcRankReply pb;
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
	void Init(const RankRpcRankReply& v)
	{
		m_Result = v.result();
		m_RankInfoList.clear();
		m_RankInfoList.reserve(v.rankinfolist_size());
		for( int i=0; i<v.rankinfolist_size(); i++)
			m_RankInfoList.push_back(v.rankinfolist(i));
		m_RankIndex = v.rankindex();
		m_MyValue = v.myvalue();

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
	//排行榜信息
	vector<RankInfoWraper> m_RankInfoList;
public:
	int SizeRankInfoList()
	{
		return m_RankInfoList.size();
	}
	const vector<RankInfoWraper>& GetRankInfoList() const
	{
		return m_RankInfoList;
	}
	RankInfoWraper GetRankInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankInfoList.size())
		{
			assert(false);
			return RankInfoWraper();
		}
		return m_RankInfoList[Index];
	}
	void SetRankInfoList( const vector<RankInfoWraper>& v )
	{
		m_RankInfoList=v;
	}
	void ClearRankInfoList( )
	{
		m_RankInfoList.clear();
	}
	void SetRankInfoList( int Index, const RankInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RankInfoList.size())
		{
			assert(false);
			return;
		}
		m_RankInfoList[Index] = v;
	}
	void AddRankInfoList( const RankInfoWraper& v )
	{
		m_RankInfoList.push_back(v);
	}
private:
	//自己的排名
	INT32 m_RankIndex;
public:
	void SetRankIndex( INT32 v)
	{
		m_RankIndex=v;
	}
	INT32 GetRankIndex()
	{
		return m_RankIndex;
	}
	INT32 GetRankIndex() const
	{
		return m_RankIndex;
	}
private:
	//我的
	int64_t m_MyValue;
public:
	void SetMyValue( int64_t v)
	{
		m_MyValue=v;
	}
	int64_t GetMyValue()
	{
		return m_MyValue;
	}
	int64_t GetMyValue() const
	{
		return m_MyValue;
	}

};
//请求排行榜请求封装类
class RankRpcRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	RankRpcRankAskWraper()
	{
		
		m_RankType = -1;
		m_RankSubType = -1;

	}
	//赋值构造函数
	RankRpcRankAskWraper(const RankRpcRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const RankRpcRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RankRpcRankAsk ToPB() const
	{
		RankRpcRankAsk v;
		v.set_ranktype( m_RankType );
		v.set_ranksubtype( m_RankSubType );

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
		RankRpcRankAsk pb;
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
	void Init(const RankRpcRankAsk& v)
	{
		m_RankType = v.ranktype();
		m_RankSubType = v.ranksubtype();

	}

private:
	//排行榜类型
	INT32 m_RankType;
public:
	void SetRankType( INT32 v)
	{
		m_RankType=v;
	}
	INT32 GetRankType()
	{
		return m_RankType;
	}
	INT32 GetRankType() const
	{
		return m_RankType;
	}
private:
	//子类型
	INT32 m_RankSubType;
public:
	void SetRankSubType( INT32 v)
	{
		m_RankSubType=v;
	}
	INT32 GetRankSubType()
	{
		return m_RankSubType;
	}
	INT32 GetRankSubType() const
	{
		return m_RankSubType;
	}

};

template<typename T> struct MessageIdT;


#endif
