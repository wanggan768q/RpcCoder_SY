/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperBag.h
* Author:       郭晓波
* Description:  BagRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BAG_H
#define __RPC_WRAPER_BAG_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BagRpc.pb.h"



//Bag类的枚举定义
enum ConstBagE
{
	MODULE_ID_BAG                                = 12,	//Bag模块ID
	RPC_CODE_BAG_USEITEM_REQUEST                 = 1251,	//Bag-->UseItem-->请求
	RPC_CODE_BAG_SYNC_REQUEST                    = 1252,	//Bag-->请求背包数据-->请求
	RPC_CODE_BAG_SALEITEM_REQUEST                = 1253,	//Bag-->SaleItem-->请求
	RPC_CODE_BAG_LOCKITEM_REQUEST                = 1254,	//Bag-->LockItem-->请求
	RPC_CODE_BAG_DEBLOCKING_REQUEST              = 1255,	//Bag-->解锁背包格子-->请求
	RPC_CODE_BAG_TAKEITEM_REQUEST                = 1256,	//Bag-->TakeItem-->请求
	RPC_CODE_BAG_TIDY_REQUEST                    = 1257,	//Bag-->整理-->请求
	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST         = 1258,	//Bag-->临时背包全部取回-->请求
	RPC_CODE_BAG_BAGCHANGE_NOTIFY                = 1259,	//Bag-->背包数据推送-->通知


};


//TakeItem回应封装类
class BagRpcTakeItemReplyWraper
{
public:
	//构造函数
	BagRpcTakeItemReplyWraper()
	{
		
		m_Result = -9999;
		m_ToItemObj = ItemObjWraper();
		m_FromItemObj = ItemObjWraper();
		m_FromBagType = -1;
		m_ToBagType = -1;

	}
	//赋值构造函数
	BagRpcTakeItemReplyWraper(const BagRpcTakeItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTakeItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTakeItemReply ToPB() const
	{
		BagRpcTakeItemReply v;
		v.set_result( m_Result );
		*v.mutable_toitemobj()= m_ToItemObj.ToPB();
		*v.mutable_fromitemobj()= m_FromItemObj.ToPB();
		v.set_frombagtype( m_FromBagType );
		v.set_tobagtype( m_ToBagType );

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
		BagRpcTakeItemReply pb;
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
	void Init(const BagRpcTakeItemReply& v)
	{
		m_Result = v.result();
		m_ToItemObj = v.toitemobj();
		m_FromItemObj = v.fromitemobj();
		m_FromBagType = v.frombagtype();
		m_ToBagType = v.tobagtype();

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
	//目标背包道具
	ItemObjWraper m_ToItemObj;
public:
	void SetToItemObj( const ItemObjWraper& v)
	{
		m_ToItemObj=v;
	}
	ItemObjWraper GetToItemObj()
	{
		return m_ToItemObj;
	}
	ItemObjWraper GetToItemObj() const
	{
		return m_ToItemObj;
	}
private:
	//源背包道具
	ItemObjWraper m_FromItemObj;
public:
	void SetFromItemObj( const ItemObjWraper& v)
	{
		m_FromItemObj=v;
	}
	ItemObjWraper GetFromItemObj()
	{
		return m_FromItemObj;
	}
	ItemObjWraper GetFromItemObj() const
	{
		return m_FromItemObj;
	}
private:
	//源背包
	INT32 m_FromBagType;
public:
	void SetFromBagType( INT32 v)
	{
		m_FromBagType=v;
	}
	INT32 GetFromBagType()
	{
		return m_FromBagType;
	}
	INT32 GetFromBagType() const
	{
		return m_FromBagType;
	}
private:
	//目标背包
	INT32 m_ToBagType;
public:
	void SetToBagType( INT32 v)
	{
		m_ToBagType=v;
	}
	INT32 GetToBagType()
	{
		return m_ToBagType;
	}
	INT32 GetToBagType() const
	{
		return m_ToBagType;
	}

};
//整理请求封装类
class BagRpcTidyAskWraper
{
public:
	//构造函数
	BagRpcTidyAskWraper()
	{
		
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcTidyAskWraper(const BagRpcTidyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTidyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTidyAsk ToPB() const
	{
		BagRpcTidyAsk v;
		v.set_bagtype( m_BagType );

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
		BagRpcTidyAsk pb;
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
	void Init(const BagRpcTidyAsk& v)
	{
		m_BagType = v.bagtype();

	}

private:
	//背包类型
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}

};
//解锁背包格子回应封装类
class BagRpcDeblockingReplyWraper
{
public:
	//构造函数
	BagRpcDeblockingReplyWraper()
	{
		
		m_Result = -9999;
		m_BagType = -1;
		m_CurCapacity = -1;

	}
	//赋值构造函数
	BagRpcDeblockingReplyWraper(const BagRpcDeblockingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcDeblockingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcDeblockingReply ToPB() const
	{
		BagRpcDeblockingReply v;
		v.set_result( m_Result );
		v.set_bagtype( m_BagType );
		v.set_curcapacity( m_CurCapacity );

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
		BagRpcDeblockingReply pb;
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
	void Init(const BagRpcDeblockingReply& v)
	{
		m_Result = v.result();
		m_BagType = v.bagtype();
		m_CurCapacity = v.curcapacity();

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
	//背包类型
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}
private:
	//当前的容量
	INT32 m_CurCapacity;
public:
	void SetCurCapacity( INT32 v)
	{
		m_CurCapacity=v;
	}
	INT32 GetCurCapacity()
	{
		return m_CurCapacity;
	}
	INT32 GetCurCapacity() const
	{
		return m_CurCapacity;
	}

};
//TakeItem请求封装类
class BagRpcTakeItemAskWraper
{
public:
	//构造函数
	BagRpcTakeItemAskWraper()
	{
		
		m_FromBagType = -1;
		m_ToBagType = -1;
		m_FromPos = -1;

	}
	//赋值构造函数
	BagRpcTakeItemAskWraper(const BagRpcTakeItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTakeItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTakeItemAsk ToPB() const
	{
		BagRpcTakeItemAsk v;
		v.set_frombagtype( m_FromBagType );
		v.set_tobagtype( m_ToBagType );
		v.set_frompos( m_FromPos );

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
		BagRpcTakeItemAsk pb;
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
	void Init(const BagRpcTakeItemAsk& v)
	{
		m_FromBagType = v.frombagtype();
		m_ToBagType = v.tobagtype();
		m_FromPos = v.frompos();

	}

private:
	//源背包
	INT32 m_FromBagType;
public:
	void SetFromBagType( INT32 v)
	{
		m_FromBagType=v;
	}
	INT32 GetFromBagType()
	{
		return m_FromBagType;
	}
	INT32 GetFromBagType() const
	{
		return m_FromBagType;
	}
private:
	//目标背包
	INT32 m_ToBagType;
public:
	void SetToBagType( INT32 v)
	{
		m_ToBagType=v;
	}
	INT32 GetToBagType()
	{
		return m_ToBagType;
	}
	INT32 GetToBagType() const
	{
		return m_ToBagType;
	}
private:
	//源背包位置
	INT32 m_FromPos;
public:
	void SetFromPos( INT32 v)
	{
		m_FromPos=v;
	}
	INT32 GetFromPos()
	{
		return m_FromPos;
	}
	INT32 GetFromPos() const
	{
		return m_FromPos;
	}

};
//临时背包全部取回回应封装类
class BagRpcTakeAllBackBagsReplyWraper
{
public:
	//构造函数
	BagRpcTakeAllBackBagsReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcTakeAllBackBagsReplyWraper(const BagRpcTakeAllBackBagsReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTakeAllBackBagsReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTakeAllBackBagsReply ToPB() const
	{
		BagRpcTakeAllBackBagsReply v;
		v.set_result( m_Result );
		v.mutable_bags()->Reserve(m_Bags.size());
		for (int i=0; i<(int)m_Bags.size(); i++)
		{
			*v.add_bags() = m_Bags[i].ToPB();
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
		BagRpcTakeAllBackBagsReply pb;
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
	void Init(const BagRpcTakeAllBackBagsReply& v)
	{
		m_Result = v.result();
		m_Bags.clear();
		m_Bags.reserve(v.bags_size());
		for( int i=0; i<v.bags_size(); i++)
			m_Bags.push_back(v.bags(i));

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
	//所有背包数据
	vector<BagDataWraper> m_Bags;
public:
	int SizeBags()
	{
		return m_Bags.size();
	}
	const vector<BagDataWraper>& GetBags() const
	{
		return m_Bags;
	}
	BagDataWraper GetBags(int Index) const
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return BagDataWraper();
		}
		return m_Bags[Index];
	}
	void SetBags( const vector<BagDataWraper>& v )
	{
		m_Bags=v;
	}
	void ClearBags( )
	{
		m_Bags.clear();
	}
	void SetBags( int Index, const BagDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return;
		}
		m_Bags[Index] = v;
	}
	void AddBags( const BagDataWraper& v )
	{
		m_Bags.push_back(v);
	}

};
//背包数据推送通知封装类
class BagRpcBagChangeNotifyWraper
{
public:
	//构造函数
	BagRpcBagChangeNotifyWraper()
	{
		
		m_Result = -9999;
		m_Bags = BagDataWraper();

	}
	//赋值构造函数
	BagRpcBagChangeNotifyWraper(const BagRpcBagChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagChangeNotify ToPB() const
	{
		BagRpcBagChangeNotify v;
		v.set_result( m_Result );
		*v.mutable_bags()= m_Bags.ToPB();

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
		BagRpcBagChangeNotify pb;
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
	void Init(const BagRpcBagChangeNotify& v)
	{
		m_Result = v.result();
		m_Bags = v.bags();

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
	//所有背包数据
	BagDataWraper m_Bags;
public:
	void SetBags( const BagDataWraper& v)
	{
		m_Bags=v;
	}
	BagDataWraper GetBags()
	{
		return m_Bags;
	}
	BagDataWraper GetBags() const
	{
		return m_Bags;
	}

};
//整理回应封装类
class BagRpcTidyReplyWraper
{
public:
	//构造函数
	BagRpcTidyReplyWraper()
	{
		
		m_Result = -9999;
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcTidyReplyWraper(const BagRpcTidyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTidyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTidyReply ToPB() const
	{
		BagRpcTidyReply v;
		v.set_result( m_Result );
		v.mutable_bags()->Reserve(m_Bags.size());
		for (int i=0; i<(int)m_Bags.size(); i++)
		{
			*v.add_bags() = m_Bags[i].ToPB();
		}
		v.set_bagtype( m_BagType );

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
		BagRpcTidyReply pb;
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
	void Init(const BagRpcTidyReply& v)
	{
		m_Result = v.result();
		m_Bags.clear();
		m_Bags.reserve(v.bags_size());
		for( int i=0; i<v.bags_size(); i++)
			m_Bags.push_back(v.bags(i));
		m_BagType = v.bagtype();

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
	//所有背包数据
	vector<BagDataWraper> m_Bags;
public:
	int SizeBags()
	{
		return m_Bags.size();
	}
	const vector<BagDataWraper>& GetBags() const
	{
		return m_Bags;
	}
	BagDataWraper GetBags(int Index) const
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return BagDataWraper();
		}
		return m_Bags[Index];
	}
	void SetBags( const vector<BagDataWraper>& v )
	{
		m_Bags=v;
	}
	void ClearBags( )
	{
		m_Bags.clear();
	}
	void SetBags( int Index, const BagDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return;
		}
		m_Bags[Index] = v;
	}
	void AddBags( const BagDataWraper& v )
	{
		m_Bags.push_back(v);
	}
private:
	//BagType
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}

};
//临时背包全部取回请求封装类
class BagRpcTakeAllBackBagsAskWraper
{
public:
	//构造函数
	BagRpcTakeAllBackBagsAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcTakeAllBackBagsAskWraper(const BagRpcTakeAllBackBagsAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcTakeAllBackBagsAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcTakeAllBackBagsAsk ToPB() const
	{
		BagRpcTakeAllBackBagsAsk v;

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
		BagRpcTakeAllBackBagsAsk pb;
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
	void Init(const BagRpcTakeAllBackBagsAsk& v)
	{

	}


};
//解锁背包格子请求封装类
class BagRpcDeblockingAskWraper
{
public:
	//构造函数
	BagRpcDeblockingAskWraper()
	{
		
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcDeblockingAskWraper(const BagRpcDeblockingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcDeblockingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcDeblockingAsk ToPB() const
	{
		BagRpcDeblockingAsk v;
		v.set_bagtype( m_BagType );

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
		BagRpcDeblockingAsk pb;
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
	void Init(const BagRpcDeblockingAsk& v)
	{
		m_BagType = v.bagtype();

	}

private:
	//背包类型
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}

};
//请求背包数据请求封装类
class BagRpcSyncAskWraper
{
public:
	//构造函数
	BagRpcSyncAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcSyncAskWraper(const BagRpcSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSyncAsk ToPB() const
	{
		BagRpcSyncAsk v;

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
		BagRpcSyncAsk pb;
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
	void Init(const BagRpcSyncAsk& v)
	{

	}


};
//请求背包数据回应封装类
class BagRpcSyncReplyWraper
{
public:
	//构造函数
	BagRpcSyncReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	BagRpcSyncReplyWraper(const BagRpcSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSyncReply ToPB() const
	{
		BagRpcSyncReply v;
		v.set_result( m_Result );
		v.mutable_bags()->Reserve(m_Bags.size());
		for (int i=0; i<(int)m_Bags.size(); i++)
		{
			*v.add_bags() = m_Bags[i].ToPB();
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
		BagRpcSyncReply pb;
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
	void Init(const BagRpcSyncReply& v)
	{
		m_Result = v.result();
		m_Bags.clear();
		m_Bags.reserve(v.bags_size());
		for( int i=0; i<v.bags_size(); i++)
			m_Bags.push_back(v.bags(i));

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
	//所有背包数据
	vector<BagDataWraper> m_Bags;
public:
	int SizeBags()
	{
		return m_Bags.size();
	}
	const vector<BagDataWraper>& GetBags() const
	{
		return m_Bags;
	}
	BagDataWraper GetBags(int Index) const
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return BagDataWraper();
		}
		return m_Bags[Index];
	}
	void SetBags( const vector<BagDataWraper>& v )
	{
		m_Bags=v;
	}
	void ClearBags( )
	{
		m_Bags.clear();
	}
	void SetBags( int Index, const BagDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return;
		}
		m_Bags[Index] = v;
	}
	void AddBags( const BagDataWraper& v )
	{
		m_Bags.push_back(v);
	}

};
//UseItem请求封装类
class BagRpcUseItemAskWraper
{
public:
	//构造函数
	BagRpcUseItemAskWraper()
	{
		
		m_Count = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	BagRpcUseItemAskWraper(const BagRpcUseItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUseItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUseItemAsk ToPB() const
	{
		BagRpcUseItemAsk v;
		v.set_count( m_Count );
		v.set_pos( m_Pos );

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
		BagRpcUseItemAsk pb;
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
	void Init(const BagRpcUseItemAsk& v)
	{
		m_Count = v.count();
		m_Pos = v.pos();

	}

private:
	//数量
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
private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//UseItem回应封装类
class BagRpcUseItemReplyWraper
{
public:
	//构造函数
	BagRpcUseItemReplyWraper()
	{
		
		m_Result = -9999;
		m_Item = ItemObjWraper();

	}
	//赋值构造函数
	BagRpcUseItemReplyWraper(const BagRpcUseItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcUseItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcUseItemReply ToPB() const
	{
		BagRpcUseItemReply v;
		v.set_result( m_Result );
		*v.mutable_item()= m_Item.ToPB();

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
		BagRpcUseItemReply pb;
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
	void Init(const BagRpcUseItemReply& v)
	{
		m_Result = v.result();
		m_Item = v.item();

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
	//位置
	ItemObjWraper m_Item;
public:
	void SetItem( const ItemObjWraper& v)
	{
		m_Item=v;
	}
	ItemObjWraper GetItem()
	{
		return m_Item;
	}
	ItemObjWraper GetItem() const
	{
		return m_Item;
	}

};
//LockItem请求封装类
class BagRpcLockItemAskWraper
{
public:
	//构造函数
	BagRpcLockItemAskWraper()
	{
		
		m_Pos = -1;
		m_IsLock = false;

	}
	//赋值构造函数
	BagRpcLockItemAskWraper(const BagRpcLockItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcLockItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcLockItemAsk ToPB() const
	{
		BagRpcLockItemAsk v;
		v.set_pos( m_Pos );
		v.set_islock( m_IsLock );

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
		BagRpcLockItemAsk pb;
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
	void Init(const BagRpcLockItemAsk& v)
	{
		m_Pos = v.pos();
		m_IsLock = v.islock();

	}

private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//IsLock
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}

};
//LockItem回应封装类
class BagRpcLockItemReplyWraper
{
public:
	//构造函数
	BagRpcLockItemReplyWraper()
	{
		
		m_Result = -9999;
		m_Item = ItemObjWraper();

	}
	//赋值构造函数
	BagRpcLockItemReplyWraper(const BagRpcLockItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcLockItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcLockItemReply ToPB() const
	{
		BagRpcLockItemReply v;
		v.set_result( m_Result );
		*v.mutable_item()= m_Item.ToPB();

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
		BagRpcLockItemReply pb;
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
	void Init(const BagRpcLockItemReply& v)
	{
		m_Result = v.result();
		m_Item = v.item();

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
	//位置
	ItemObjWraper m_Item;
public:
	void SetItem( const ItemObjWraper& v)
	{
		m_Item=v;
	}
	ItemObjWraper GetItem()
	{
		return m_Item;
	}
	ItemObjWraper GetItem() const
	{
		return m_Item;
	}

};
//SaleItem请求封装类
class BagRpcSaleItemAskWraper
{
public:
	//构造函数
	BagRpcSaleItemAskWraper()
	{
		
		m_Pos = -1;
		m_Count = -1;

	}
	//赋值构造函数
	BagRpcSaleItemAskWraper(const BagRpcSaleItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSaleItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSaleItemAsk ToPB() const
	{
		BagRpcSaleItemAsk v;
		v.set_pos( m_Pos );
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
		BagRpcSaleItemAsk pb;
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
	void Init(const BagRpcSaleItemAsk& v)
	{
		m_Pos = v.pos();
		m_Count = v.count();

	}

private:
	//位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//卖出数量
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
//SaleItem回应封装类
class BagRpcSaleItemReplyWraper
{
public:
	//构造函数
	BagRpcSaleItemReplyWraper()
	{
		
		m_Result = -9999;
		m_Item = ItemObjWraper();

	}
	//赋值构造函数
	BagRpcSaleItemReplyWraper(const BagRpcSaleItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcSaleItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcSaleItemReply ToPB() const
	{
		BagRpcSaleItemReply v;
		v.set_result( m_Result );
		*v.mutable_item()= m_Item.ToPB();

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
		BagRpcSaleItemReply pb;
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
	void Init(const BagRpcSaleItemReply& v)
	{
		m_Result = v.result();
		m_Item = v.item();

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
	//位置
	ItemObjWraper m_Item;
public:
	void SetItem( const ItemObjWraper& v)
	{
		m_Item=v;
	}
	ItemObjWraper GetItem()
	{
		return m_Item;
	}
	ItemObjWraper GetItem() const
	{
		return m_Item;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<BagRpcBagChangeNotifyWraper>{ enum{ID=RPC_CODE_BAG_BAGCHANGE_NOTIFY};};


#endif
