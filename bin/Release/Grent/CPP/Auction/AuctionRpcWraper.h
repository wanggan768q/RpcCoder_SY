/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperAuction.h
* Author:       甘业清
* Description:  拍卖行RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_AUCTION_H
#define __RPC_WRAPER_AUCTION_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "AuctionRpc.pb.h"



//拍卖行类的枚举定义
enum ConstAuctionE
{
	MODULE_ID_AUCTION                            = 52,	//拍卖行模块ID
	RPC_CODE_AUCTION_AUCTIONINFO_REQUEST         = 5251,	//拍卖行-->查询拍卖行信息-->请求
	RPC_CODE_AUCTION_SELLITEM_REQUEST            = 5252,	//拍卖行-->请求上架-->请求
	RPC_CODE_AUCTION_SELLAGAIN_REQUEST           = 5253,	//拍卖行-->重新上架-->请求
	RPC_CODE_AUCTION_BUY_REQUEST                 = 5254,	//拍卖行-->购买-->请求
	RPC_CODE_AUCTION_GETITEM_REQUEST             = 5255,	//拍卖行-->取回拍卖道具-->请求
	RPC_CODE_AUCTION_RECORD_REQUEST              = 5256,	//拍卖行-->交易记录-->请求
	RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST     = 5257,	//拍卖行-->按类别查询简单信息-->请求
	RPC_CODE_AUCTION_SALEPREPARE_REQUEST         = 5258,	//拍卖行-->预上架-->请求
	RPC_CODE_AUCTION_GETITEMBACK_REQUEST         = 5259,	//拍卖行-->取回上架物品-->请求
	RPC_CODE_AUCTION_GETMYSALELIST_REQUEST       = 5260,	//拍卖行-->玩家当前拍卖列表-->请求


};


//按类别查询简单信息回应封装类
class AuctionRpcItemInfoByClassReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcItemInfoByClassReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcItemInfoByClassReplyWraper(const AuctionRpcItemInfoByClassReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcItemInfoByClassReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcItemInfoByClassReply ToPB() const
	{
		AuctionRpcItemInfoByClassReply v;
		v.set_result( m_Result );
		v.mutable_itemcount()->Reserve(m_ItemCount.size());
		for (int i=0; i<(int)m_ItemCount.size(); i++)
		{
			*v.add_itemcount() = m_ItemCount[i].ToPB();
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
		AuctionRpcItemInfoByClassReply pb;
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
	void Init(const AuctionRpcItemInfoByClassReply& v)
	{
		m_Result = v.result();
		m_ItemCount.clear();
		m_ItemCount.reserve(v.itemcount_size());
		for( int i=0; i<v.itemcount_size(); i++)
			m_ItemCount.push_back(v.itemcount(i));

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
	//道具数量信息
	vector<AuctionItemCntWraper> m_ItemCount;
public:
	int SizeItemCount()
	{
		return m_ItemCount.size();
	}
	const vector<AuctionItemCntWraper>& GetItemCount() const
	{
		return m_ItemCount;
	}
	AuctionItemCntWraper GetItemCount(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemCount.size())
		{
			assert(false);
			return AuctionItemCntWraper();
		}
		return m_ItemCount[Index];
	}
	void SetItemCount( const vector<AuctionItemCntWraper>& v )
	{
		m_ItemCount=v;
	}
	void ClearItemCount( )
	{
		m_ItemCount.clear();
	}
	void SetItemCount( int Index, const AuctionItemCntWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemCount.size())
		{
			assert(false);
			return;
		}
		m_ItemCount[Index] = v;
	}
	void AddItemCount( const AuctionItemCntWraper& v )
	{
		m_ItemCount.push_back(v);
	}

};
//预上架请求封装类
class AuctionRpcSalePrepareAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSalePrepareAskWraper()
	{
		
		m_ItemId = -1;

	}
	//赋值构造函数
	AuctionRpcSalePrepareAskWraper(const AuctionRpcSalePrepareAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSalePrepareAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSalePrepareAsk ToPB() const
	{
		AuctionRpcSalePrepareAsk v;
		v.set_itemid( m_ItemId );

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
		AuctionRpcSalePrepareAsk pb;
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
	void Init(const AuctionRpcSalePrepareAsk& v)
	{
		m_ItemId = v.itemid();

	}

private:
	//预上架物品ID
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}

};
//按类别查询简单信息请求封装类
class AuctionRpcItemInfoByClassAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcItemInfoByClassAskWraper()
	{
		
		m_ItemClass = -1;
		m_ItemSubClass = -1;
		m_Prof = -1;
		m_Level = -1;

	}
	//赋值构造函数
	AuctionRpcItemInfoByClassAskWraper(const AuctionRpcItemInfoByClassAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcItemInfoByClassAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcItemInfoByClassAsk ToPB() const
	{
		AuctionRpcItemInfoByClassAsk v;
		v.set_itemclass( m_ItemClass );
		v.mutable_itemid()->Reserve(m_ItemId.size());
		for (int i=0; i<(int)m_ItemId.size(); i++)
		{
			v.add_itemid(m_ItemId[i]);
		}
		v.set_itemsubclass( m_ItemSubClass );
		v.set_prof( m_Prof );
		v.set_level( m_Level );

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
		AuctionRpcItemInfoByClassAsk pb;
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
	void Init(const AuctionRpcItemInfoByClassAsk& v)
	{
		m_ItemClass = v.itemclass();
		m_ItemId.clear();
		m_ItemId.reserve(v.itemid_size());
		for( int i=0; i<v.itemid_size(); i++)
			m_ItemId.push_back(v.itemid(i));
		m_ItemSubClass = v.itemsubclass();
		m_Prof = v.prof();
		m_Level = v.level();

	}

private:
	//商品类别(关注，装备，道具，宠物)
	INT32 m_ItemClass;
public:
	void SetItemClass( INT32 v)
	{
		m_ItemClass=v;
	}
	INT32 GetItemClass()
	{
		return m_ItemClass;
	}
	INT32 GetItemClass() const
	{
		return m_ItemClass;
	}
private:
	//关注物品的id
	vector<INT32> m_ItemId;
public:
	int SizeItemId()
	{
		return m_ItemId.size();
	}
	const vector<INT32>& GetItemId() const
	{
		return m_ItemId;
	}
	INT32 GetItemId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemId.size())
		{
			assert(false);
			return INT32();
		}
		return m_ItemId[Index];
	}
	void SetItemId( const vector<INT32>& v )
	{
		m_ItemId=v;
	}
	void ClearItemId( )
	{
		m_ItemId.clear();
	}
	void SetItemId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ItemId.size())
		{
			assert(false);
			return;
		}
		m_ItemId[Index] = v;
	}
	void AddItemId( INT32 v = -1 )
	{
		m_ItemId.push_back(v);
	}
private:
	//子类别
	INT32 m_ItemSubClass;
public:
	void SetItemSubClass( INT32 v)
	{
		m_ItemSubClass=v;
	}
	INT32 GetItemSubClass()
	{
		return m_ItemSubClass;
	}
	INT32 GetItemSubClass() const
	{
		return m_ItemSubClass;
	}
private:
	//职业
	INT32 m_Prof;
public:
	void SetProf( INT32 v)
	{
		m_Prof=v;
	}
	INT32 GetProf()
	{
		return m_Prof;
	}
	INT32 GetProf() const
	{
		return m_Prof;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}

};
//交易记录请求封装类
class AuctionRpcRecordAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcRecordAskWraper()
	{
		

	}
	//赋值构造函数
	AuctionRpcRecordAskWraper(const AuctionRpcRecordAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcRecordAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcRecordAsk ToPB() const
	{
		AuctionRpcRecordAsk v;

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
		AuctionRpcRecordAsk pb;
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
	void Init(const AuctionRpcRecordAsk& v)
	{

	}


};
//交易记录回应封装类
class AuctionRpcRecordReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcRecordReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcRecordReplyWraper(const AuctionRpcRecordReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcRecordReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcRecordReply ToPB() const
	{
		AuctionRpcRecordReply v;
		v.set_result( m_Result );
		v.mutable_record()->Reserve(m_Record.size());
		for (int i=0; i<(int)m_Record.size(); i++)
		{
			*v.add_record() = m_Record[i].ToPB();
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
		AuctionRpcRecordReply pb;
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
	void Init(const AuctionRpcRecordReply& v)
	{
		m_Result = v.result();
		m_Record.clear();
		m_Record.reserve(v.record_size());
		for( int i=0; i<v.record_size(); i++)
			m_Record.push_back(v.record(i));

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
	//交易记录简单信息
	vector<AuctionRecSimpleWraper> m_Record;
public:
	int SizeRecord()
	{
		return m_Record.size();
	}
	const vector<AuctionRecSimpleWraper>& GetRecord() const
	{
		return m_Record;
	}
	AuctionRecSimpleWraper GetRecord(int Index) const
	{
		if(Index<0 || Index>=(int)m_Record.size())
		{
			assert(false);
			return AuctionRecSimpleWraper();
		}
		return m_Record[Index];
	}
	void SetRecord( const vector<AuctionRecSimpleWraper>& v )
	{
		m_Record=v;
	}
	void ClearRecord( )
	{
		m_Record.clear();
	}
	void SetRecord( int Index, const AuctionRecSimpleWraper& v )
	{
		if(Index<0 || Index>=(int)m_Record.size())
		{
			assert(false);
			return;
		}
		m_Record[Index] = v;
	}
	void AddRecord( const AuctionRecSimpleWraper& v )
	{
		m_Record.push_back(v);
	}

};
//玩家当前拍卖列表请求封装类
class AuctionRpcGetMySaleListAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetMySaleListAskWraper()
	{
		

	}
	//赋值构造函数
	AuctionRpcGetMySaleListAskWraper(const AuctionRpcGetMySaleListAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetMySaleListAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetMySaleListAsk ToPB() const
	{
		AuctionRpcGetMySaleListAsk v;

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
		AuctionRpcGetMySaleListAsk pb;
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
	void Init(const AuctionRpcGetMySaleListAsk& v)
	{

	}


};
//玩家当前拍卖列表回应封装类
class AuctionRpcGetMySaleListReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetMySaleListReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcGetMySaleListReplyWraper(const AuctionRpcGetMySaleListReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetMySaleListReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetMySaleListReply ToPB() const
	{
		AuctionRpcGetMySaleListReply v;
		v.set_result( m_Result );
		v.mutable_auctionitem()->Reserve(m_AuctionItem.size());
		for (int i=0; i<(int)m_AuctionItem.size(); i++)
		{
			*v.add_auctionitem() = m_AuctionItem[i].ToPB();
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
		AuctionRpcGetMySaleListReply pb;
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
	void Init(const AuctionRpcGetMySaleListReply& v)
	{
		m_Result = v.result();
		m_AuctionItem.clear();
		m_AuctionItem.reserve(v.auctionitem_size());
		for( int i=0; i<v.auctionitem_size(); i++)
			m_AuctionItem.push_back(v.auctionitem(i));

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
	//道具信息
	vector<AuctionItemWraper> m_AuctionItem;
public:
	int SizeAuctionItem()
	{
		return m_AuctionItem.size();
	}
	const vector<AuctionItemWraper>& GetAuctionItem() const
	{
		return m_AuctionItem;
	}
	AuctionItemWraper GetAuctionItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_AuctionItem.size())
		{
			assert(false);
			return AuctionItemWraper();
		}
		return m_AuctionItem[Index];
	}
	void SetAuctionItem( const vector<AuctionItemWraper>& v )
	{
		m_AuctionItem=v;
	}
	void ClearAuctionItem( )
	{
		m_AuctionItem.clear();
	}
	void SetAuctionItem( int Index, const AuctionItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_AuctionItem.size())
		{
			assert(false);
			return;
		}
		m_AuctionItem[Index] = v;
	}
	void AddAuctionItem( const AuctionItemWraper& v )
	{
		m_AuctionItem.push_back(v);
	}

};
//取回上架物品回应封装类
class AuctionRpcGetItemBackReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetItemBackReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcGetItemBackReplyWraper(const AuctionRpcGetItemBackReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetItemBackReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetItemBackReply ToPB() const
	{
		AuctionRpcGetItemBackReply v;
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
		AuctionRpcGetItemBackReply pb;
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
	void Init(const AuctionRpcGetItemBackReply& v)
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
//预上架回应封装类
class AuctionRpcSalePrepareReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSalePrepareReplyWraper()
	{
		
		m_Result = -1;
		m_ItemId = -1;
		m_BasePrice = 0;

	}
	//赋值构造函数
	AuctionRpcSalePrepareReplyWraper(const AuctionRpcSalePrepareReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSalePrepareReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSalePrepareReply ToPB() const
	{
		AuctionRpcSalePrepareReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemId );
		v.set_baseprice( m_BasePrice );
		v.mutable_goldgroup()->Reserve(m_GoldGroup.size());
		for (int i=0; i<(int)m_GoldGroup.size(); i++)
		{
			v.add_goldgroup(m_GoldGroup[i]);
		}
		v.mutable_diamondgroup()->Reserve(m_DiamondGroup.size());
		for (int i=0; i<(int)m_DiamondGroup.size(); i++)
		{
			v.add_diamondgroup(m_DiamondGroup[i]);
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
		AuctionRpcSalePrepareReply pb;
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
	void Init(const AuctionRpcSalePrepareReply& v)
	{
		m_Result = v.result();
		m_ItemId = v.itemid();
		m_BasePrice = v.baseprice();
		m_GoldGroup.clear();
		m_GoldGroup.reserve(v.goldgroup_size());
		for( int i=0; i<v.goldgroup_size(); i++)
			m_GoldGroup.push_back(v.goldgroup(i));
		m_DiamondGroup.clear();
		m_DiamondGroup.reserve(v.diamondgroup_size());
		for( int i=0; i<v.diamondgroup_size(); i++)
			m_DiamondGroup.push_back(v.diamondgroup(i));

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
	//商品ID 
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//基准价
	INT32 m_BasePrice;
public:
	void SetBasePrice( INT32 v)
	{
		m_BasePrice=v;
	}
	INT32 GetBasePrice()
	{
		return m_BasePrice;
	}
	INT32 GetBasePrice() const
	{
		return m_BasePrice;
	}
private:
	//GoldGroup
	vector<INT32> m_GoldGroup;
public:
	int SizeGoldGroup()
	{
		return m_GoldGroup.size();
	}
	const vector<INT32>& GetGoldGroup() const
	{
		return m_GoldGroup;
	}
	INT32 GetGoldGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_GoldGroup.size())
		{
			assert(false);
			return INT32();
		}
		return m_GoldGroup[Index];
	}
	void SetGoldGroup( const vector<INT32>& v )
	{
		m_GoldGroup=v;
	}
	void ClearGoldGroup( )
	{
		m_GoldGroup.clear();
	}
	void SetGoldGroup( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_GoldGroup.size())
		{
			assert(false);
			return;
		}
		m_GoldGroup[Index] = v;
	}
	void AddGoldGroup( INT32 v = -1 )
	{
		m_GoldGroup.push_back(v);
	}
private:
	//DiamondGroup
	vector<INT32> m_DiamondGroup;
public:
	int SizeDiamondGroup()
	{
		return m_DiamondGroup.size();
	}
	const vector<INT32>& GetDiamondGroup() const
	{
		return m_DiamondGroup;
	}
	INT32 GetDiamondGroup(int Index) const
	{
		if(Index<0 || Index>=(int)m_DiamondGroup.size())
		{
			assert(false);
			return INT32();
		}
		return m_DiamondGroup[Index];
	}
	void SetDiamondGroup( const vector<INT32>& v )
	{
		m_DiamondGroup=v;
	}
	void ClearDiamondGroup( )
	{
		m_DiamondGroup.clear();
	}
	void SetDiamondGroup( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_DiamondGroup.size())
		{
			assert(false);
			return;
		}
		m_DiamondGroup[Index] = v;
	}
	void AddDiamondGroup( INT32 v = -1 )
	{
		m_DiamondGroup.push_back(v);
	}

};
//取回上架物品请求封装类
class AuctionRpcGetItemBackAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetItemBackAskWraper()
	{
		
		m_ItemGuid = 0;

	}
	//赋值构造函数
	AuctionRpcGetItemBackAskWraper(const AuctionRpcGetItemBackAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetItemBackAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetItemBackAsk ToPB() const
	{
		AuctionRpcGetItemBackAsk v;
		v.set_itemguid( m_ItemGuid );

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
		AuctionRpcGetItemBackAsk pb;
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
	void Init(const AuctionRpcGetItemBackAsk& v)
	{
		m_ItemGuid = v.itemguid();

	}

private:
	//道具Guid
	uint64_t m_ItemGuid;
public:
	void SetItemGuid( uint64_t v)
	{
		m_ItemGuid=v;
	}
	uint64_t GetItemGuid()
	{
		return m_ItemGuid;
	}
	uint64_t GetItemGuid() const
	{
		return m_ItemGuid;
	}

};
//请求上架回应封装类
class AuctionRpcSellItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSellItemReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcSellItemReplyWraper(const AuctionRpcSellItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSellItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSellItemReply ToPB() const
	{
		AuctionRpcSellItemReply v;
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
		AuctionRpcSellItemReply pb;
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
	void Init(const AuctionRpcSellItemReply& v)
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
//购买请求封装类
class AuctionRpcBuyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcBuyAskWraper()
	{
		
		m_ItemGuid = 0;
		m_Count = -1;

	}
	//赋值构造函数
	AuctionRpcBuyAskWraper(const AuctionRpcBuyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcBuyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcBuyAsk ToPB() const
	{
		AuctionRpcBuyAsk v;
		v.set_itemguid( m_ItemGuid );
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
		AuctionRpcBuyAsk pb;
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
	void Init(const AuctionRpcBuyAsk& v)
	{
		m_ItemGuid = v.itemguid();
		m_Count = v.count();

	}

private:
	//购买道具的guid
	uint64_t m_ItemGuid;
public:
	void SetItemGuid( uint64_t v)
	{
		m_ItemGuid=v;
	}
	uint64_t GetItemGuid()
	{
		return m_ItemGuid;
	}
	uint64_t GetItemGuid() const
	{
		return m_ItemGuid;
	}
private:
	//买入数量
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
//请求上架请求封装类
class AuctionRpcSellItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSellItemAskWraper()
	{
		
		m_ItemGuid = 0;
		m_ItemId = -1;
		m_Price = 0;
		m_Currency = -1;
		m_Count = -1;

	}
	//赋值构造函数
	AuctionRpcSellItemAskWraper(const AuctionRpcSellItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSellItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSellItemAsk ToPB() const
	{
		AuctionRpcSellItemAsk v;
		v.set_itemguid( m_ItemGuid );
		v.set_itemid( m_ItemId );
		v.set_price( m_Price );
		v.set_currency( m_Currency );
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
		AuctionRpcSellItemAsk pb;
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
	void Init(const AuctionRpcSellItemAsk& v)
	{
		m_ItemGuid = v.itemguid();
		m_ItemId = v.itemid();
		m_Price = v.price();
		m_Currency = v.currency();
		m_Count = v.count();

	}

private:
	//出售道具guid
	uint64_t m_ItemGuid;
public:
	void SetItemGuid( uint64_t v)
	{
		m_ItemGuid=v;
	}
	uint64_t GetItemGuid()
	{
		return m_ItemGuid;
	}
	uint64_t GetItemGuid() const
	{
		return m_ItemGuid;
	}
private:
	//ItemId
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//拍卖价格
	INT32 m_Price;
public:
	void SetPrice( INT32 v)
	{
		m_Price=v;
	}
	INT32 GetPrice()
	{
		return m_Price;
	}
	INT32 GetPrice() const
	{
		return m_Price;
	}
private:
	//交易钱币类型
	INT32 m_Currency;
public:
	void SetCurrency( INT32 v)
	{
		m_Currency=v;
	}
	INT32 GetCurrency()
	{
		return m_Currency;
	}
	INT32 GetCurrency() const
	{
		return m_Currency;
	}
private:
	//交易数量
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
//级别封装类
class AuctionRpcAuctionInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcAuctionInfoAskWraper()
	{
		
		m_ItemId = -1;
		m_QueueType = -1;
		m_CurPage = -1;

	}
	//赋值构造函数
	AuctionRpcAuctionInfoAskWraper(const AuctionRpcAuctionInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcAuctionInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcAuctionInfoAsk ToPB() const
	{
		AuctionRpcAuctionInfoAsk v;
		v.set_itemid( m_ItemId );
		v.set_queuetype( m_QueueType );
		v.set_curpage( m_CurPage );

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
		AuctionRpcAuctionInfoAsk pb;
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
	void Init(const AuctionRpcAuctionInfoAsk& v)
	{
		m_ItemId = v.itemid();
		m_QueueType = v.queuetype();
		m_CurPage = v.curpage();

	}

private:
	//道具id
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//排序类型
	INT32 m_QueueType;
public:
	void SetQueueType( INT32 v)
	{
		m_QueueType=v;
	}
	INT32 GetQueueType()
	{
		return m_QueueType;
	}
	INT32 GetQueueType() const
	{
		return m_QueueType;
	}
private:
	//当前页
	INT32 m_CurPage;
public:
	void SetCurPage( INT32 v)
	{
		m_CurPage=v;
	}
	INT32 GetCurPage()
	{
		return m_CurPage;
	}
	INT32 GetCurPage() const
	{
		return m_CurPage;
	}

};
//查询拍卖行信息回应封装类
class AuctionRpcAuctionInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcAuctionInfoReplyWraper()
	{
		
		m_Result = -1;
		m_TotalPage = 1;

	}
	//赋值构造函数
	AuctionRpcAuctionInfoReplyWraper(const AuctionRpcAuctionInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcAuctionInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcAuctionInfoReply ToPB() const
	{
		AuctionRpcAuctionInfoReply v;
		v.set_result( m_Result );
		v.mutable_auctionitem()->Reserve(m_AuctionItem.size());
		for (int i=0; i<(int)m_AuctionItem.size(); i++)
		{
			*v.add_auctionitem() = m_AuctionItem[i].ToPB();
		}
		v.set_totalpage( m_TotalPage );

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
		AuctionRpcAuctionInfoReply pb;
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
	void Init(const AuctionRpcAuctionInfoReply& v)
	{
		m_Result = v.result();
		m_AuctionItem.clear();
		m_AuctionItem.reserve(v.auctionitem_size());
		for( int i=0; i<v.auctionitem_size(); i++)
			m_AuctionItem.push_back(v.auctionitem(i));
		m_TotalPage = v.totalpage();

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
	//查询到的信息
	vector<AuctionItemWraper> m_AuctionItem;
public:
	int SizeAuctionItem()
	{
		return m_AuctionItem.size();
	}
	const vector<AuctionItemWraper>& GetAuctionItem() const
	{
		return m_AuctionItem;
	}
	AuctionItemWraper GetAuctionItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_AuctionItem.size())
		{
			assert(false);
			return AuctionItemWraper();
		}
		return m_AuctionItem[Index];
	}
	void SetAuctionItem( const vector<AuctionItemWraper>& v )
	{
		m_AuctionItem=v;
	}
	void ClearAuctionItem( )
	{
		m_AuctionItem.clear();
	}
	void SetAuctionItem( int Index, const AuctionItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_AuctionItem.size())
		{
			assert(false);
			return;
		}
		m_AuctionItem[Index] = v;
	}
	void AddAuctionItem( const AuctionItemWraper& v )
	{
		m_AuctionItem.push_back(v);
	}
private:
	//道具总页数
	INT32 m_TotalPage;
public:
	void SetTotalPage( INT32 v)
	{
		m_TotalPage=v;
	}
	INT32 GetTotalPage()
	{
		return m_TotalPage;
	}
	INT32 GetTotalPage() const
	{
		return m_TotalPage;
	}

};
//取回交易记录中物品封装类
class AuctionRpcGetItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetItemAskWraper()
	{
		

	}
	//赋值构造函数
	AuctionRpcGetItemAskWraper(const AuctionRpcGetItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetItemAsk ToPB() const
	{
		AuctionRpcGetItemAsk v;
		v.mutable_buyrecguid()->Reserve(m_BuyRecGuid.size());
		for (int i=0; i<(int)m_BuyRecGuid.size(); i++)
		{
			v.add_buyrecguid(m_BuyRecGuid[i]);
		}
		v.mutable_salerecguid()->Reserve(m_SaleRecGuid.size());
		for (int i=0; i<(int)m_SaleRecGuid.size(); i++)
		{
			v.add_salerecguid(m_SaleRecGuid[i]);
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
		AuctionRpcGetItemAsk pb;
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
	void Init(const AuctionRpcGetItemAsk& v)
	{
		m_BuyRecGuid.clear();
		m_BuyRecGuid.reserve(v.buyrecguid_size());
		for( int i=0; i<v.buyrecguid_size(); i++)
			m_BuyRecGuid.push_back(v.buyrecguid(i));
		m_SaleRecGuid.clear();
		m_SaleRecGuid.reserve(v.salerecguid_size());
		for( int i=0; i<v.salerecguid_size(); i++)
			m_SaleRecGuid.push_back(v.salerecguid(i));

	}

private:
	//拍卖行的商品guid
	vector<uint64_t> m_BuyRecGuid;
public:
	int SizeBuyRecGuid()
	{
		return m_BuyRecGuid.size();
	}
	const vector<uint64_t>& GetBuyRecGuid() const
	{
		return m_BuyRecGuid;
	}
	uint64_t GetBuyRecGuid(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuyRecGuid.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_BuyRecGuid[Index];
	}
	void SetBuyRecGuid( const vector<uint64_t>& v )
	{
		m_BuyRecGuid=v;
	}
	void ClearBuyRecGuid( )
	{
		m_BuyRecGuid.clear();
	}
	void SetBuyRecGuid( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_BuyRecGuid.size())
		{
			assert(false);
			return;
		}
		m_BuyRecGuid[Index] = v;
	}
	void AddBuyRecGuid( uint64_t v = 0 )
	{
		m_BuyRecGuid.push_back(v);
	}
private:
	//卖的记录guid
	vector<uint64_t> m_SaleRecGuid;
public:
	int SizeSaleRecGuid()
	{
		return m_SaleRecGuid.size();
	}
	const vector<uint64_t>& GetSaleRecGuid() const
	{
		return m_SaleRecGuid;
	}
	uint64_t GetSaleRecGuid(int Index) const
	{
		if(Index<0 || Index>=(int)m_SaleRecGuid.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_SaleRecGuid[Index];
	}
	void SetSaleRecGuid( const vector<uint64_t>& v )
	{
		m_SaleRecGuid=v;
	}
	void ClearSaleRecGuid( )
	{
		m_SaleRecGuid.clear();
	}
	void SetSaleRecGuid( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_SaleRecGuid.size())
		{
			assert(false);
			return;
		}
		m_SaleRecGuid[Index] = v;
	}
	void AddSaleRecGuid( uint64_t v = 0 )
	{
		m_SaleRecGuid.push_back(v);
	}

};
//取回拍卖道具回应封装类
class AuctionRpcGetItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcGetItemReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcGetItemReplyWraper(const AuctionRpcGetItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcGetItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcGetItemReply ToPB() const
	{
		AuctionRpcGetItemReply v;
		v.set_result( m_Result );
		v.mutable_record()->Reserve(m_Record.size());
		for (int i=0; i<(int)m_Record.size(); i++)
		{
			*v.add_record() = m_Record[i].ToPB();
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
		AuctionRpcGetItemReply pb;
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
	void Init(const AuctionRpcGetItemReply& v)
	{
		m_Result = v.result();
		m_Record.clear();
		m_Record.reserve(v.record_size());
		for( int i=0; i<v.record_size(); i++)
			m_Record.push_back(v.record(i));

	}

private:
	//结果
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
	//返回道具的信息
	vector<AuctionRecSimpleWraper> m_Record;
public:
	int SizeRecord()
	{
		return m_Record.size();
	}
	const vector<AuctionRecSimpleWraper>& GetRecord() const
	{
		return m_Record;
	}
	AuctionRecSimpleWraper GetRecord(int Index) const
	{
		if(Index<0 || Index>=(int)m_Record.size())
		{
			assert(false);
			return AuctionRecSimpleWraper();
		}
		return m_Record[Index];
	}
	void SetRecord( const vector<AuctionRecSimpleWraper>& v )
	{
		m_Record=v;
	}
	void ClearRecord( )
	{
		m_Record.clear();
	}
	void SetRecord( int Index, const AuctionRecSimpleWraper& v )
	{
		if(Index<0 || Index>=(int)m_Record.size())
		{
			assert(false);
			return;
		}
		m_Record[Index] = v;
	}
	void AddRecord( const AuctionRecSimpleWraper& v )
	{
		m_Record.push_back(v);
	}

};
//重新上架回应封装类
class AuctionRpcSellAgainReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSellAgainReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcSellAgainReplyWraper(const AuctionRpcSellAgainReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSellAgainReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSellAgainReply ToPB() const
	{
		AuctionRpcSellAgainReply v;
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
		AuctionRpcSellAgainReply pb;
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
	void Init(const AuctionRpcSellAgainReply& v)
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
//购买回应封装类
class AuctionRpcBuyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcBuyReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	AuctionRpcBuyReplyWraper(const AuctionRpcBuyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcBuyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcBuyReply ToPB() const
	{
		AuctionRpcBuyReply v;
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
		AuctionRpcBuyReply pb;
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
	void Init(const AuctionRpcBuyReply& v)
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
//重新上架请求封装类
class AuctionRpcSellAgainAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AuctionRpcSellAgainAskWraper()
	{
		
		m_ItemGuid = 0;
		m_Price = -1;

	}
	//赋值构造函数
	AuctionRpcSellAgainAskWraper(const AuctionRpcSellAgainAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRpcSellAgainAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRpcSellAgainAsk ToPB() const
	{
		AuctionRpcSellAgainAsk v;
		v.set_itemguid( m_ItemGuid );
		v.set_price( m_Price );

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
		AuctionRpcSellAgainAsk pb;
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
	void Init(const AuctionRpcSellAgainAsk& v)
	{
		m_ItemGuid = v.itemguid();
		m_Price = v.price();

	}

private:
	//再次销售物品guid
	uint64_t m_ItemGuid;
public:
	void SetItemGuid( uint64_t v)
	{
		m_ItemGuid=v;
	}
	uint64_t GetItemGuid()
	{
		return m_ItemGuid;
	}
	uint64_t GetItemGuid() const
	{
		return m_ItemGuid;
	}
private:
	//价格
	INT32 m_Price;
public:
	void SetPrice( INT32 v)
	{
		m_Price=v;
	}
	INT32 GetPrice()
	{
		return m_Price;
	}
	INT32 GetPrice() const
	{
		return m_Price;
	}

};

template<typename T> struct MessageIdT;


#endif
