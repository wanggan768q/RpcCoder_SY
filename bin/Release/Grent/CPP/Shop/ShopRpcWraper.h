/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperShop.h
* Author:       甘业清
* Description:  商店RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SHOP_H
#define __RPC_WRAPER_SHOP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ShopRpc.pb.h"



//商店类的枚举定义
enum ConstShopE
{
	MODULE_ID_SHOP                               = 33,	//商店模块ID
	RPC_CODE_SHOP_BUYITEM_REQUEST                = 3351,	//商店-->BuyItem-->请求
	RPC_CODE_SHOP_SHOPINFO_REQUEST               = 3352,	//商店-->ShopInfo-->请求


};


//ShopInfo请求封装类
class ShopRpcShopInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcShopInfoAskWraper()
	{
		
		m_RoleID = -1;

	}
	//赋值构造函数
	ShopRpcShopInfoAskWraper(const ShopRpcShopInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcShopInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcShopInfoAsk ToPB() const
	{
		ShopRpcShopInfoAsk v;
		v.set_roleid( m_RoleID );

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
		ShopRpcShopInfoAsk pb;
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
	void Init(const ShopRpcShopInfoAsk& v)
	{
		m_RoleID = v.roleid();

	}

private:
	//RoleID
	INT32 m_RoleID;
public:
	void SetRoleID( INT32 v)
	{
		m_RoleID=v;
	}
	INT32 GetRoleID()
	{
		return m_RoleID;
	}
	INT32 GetRoleID() const
	{
		return m_RoleID;
	}

};
//ShopInfo回应封装类
class ShopRpcShopInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcShopInfoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ShopRpcShopInfoReplyWraper(const ShopRpcShopInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcShopInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcShopInfoReply ToPB() const
	{
		ShopRpcShopInfoReply v;
		v.set_result( m_Result );
		v.mutable_iteminfo()->Reserve(m_ItemInfo.size());
		for (int i=0; i<(int)m_ItemInfo.size(); i++)
		{
			*v.add_iteminfo() = m_ItemInfo[i].ToPB();
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
		ShopRpcShopInfoReply pb;
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
	void Init(const ShopRpcShopInfoReply& v)
	{
		m_Result = v.result();
		m_ItemInfo.clear();
		m_ItemInfo.reserve(v.iteminfo_size());
		for( int i=0; i<v.iteminfo_size(); i++)
			m_ItemInfo.push_back(v.iteminfo(i));

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
	//ItemInfo
	vector<ShopItemWraper> m_ItemInfo;
public:
	int SizeItemInfo()
	{
		return m_ItemInfo.size();
	}
	const vector<ShopItemWraper>& GetItemInfo() const
	{
		return m_ItemInfo;
	}
	ShopItemWraper GetItemInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemInfo.size())
		{
			assert(false);
			return ShopItemWraper();
		}
		return m_ItemInfo[Index];
	}
	void SetItemInfo( const vector<ShopItemWraper>& v )
	{
		m_ItemInfo=v;
	}
	void ClearItemInfo( )
	{
		m_ItemInfo.clear();
	}
	void SetItemInfo( int Index, const ShopItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemInfo.size())
		{
			assert(false);
			return;
		}
		m_ItemInfo[Index] = v;
	}
	void AddItemInfo( const ShopItemWraper& v )
	{
		m_ItemInfo.push_back(v);
	}

};
//BuyItem请求封装类
class ShopRpcBuyItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcBuyItemAskWraper()
	{
		
		m_ShopItemId = -1;
		m_ItemNum = -1;

	}
	//赋值构造函数
	ShopRpcBuyItemAskWraper(const ShopRpcBuyItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcBuyItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcBuyItemAsk ToPB() const
	{
		ShopRpcBuyItemAsk v;
		v.set_shopitemid( m_ShopItemId );
		v.set_itemnum( m_ItemNum );

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
		ShopRpcBuyItemAsk pb;
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
	void Init(const ShopRpcBuyItemAsk& v)
	{
		m_ShopItemId = v.shopitemid();
		m_ItemNum = v.itemnum();

	}

private:
	//ShopItemId
	INT32 m_ShopItemId;
public:
	void SetShopItemId( INT32 v)
	{
		m_ShopItemId=v;
	}
	INT32 GetShopItemId()
	{
		return m_ShopItemId;
	}
	INT32 GetShopItemId() const
	{
		return m_ShopItemId;
	}
private:
	//ItemNum
	INT32 m_ItemNum;
public:
	void SetItemNum( INT32 v)
	{
		m_ItemNum=v;
	}
	INT32 GetItemNum()
	{
		return m_ItemNum;
	}
	INT32 GetItemNum() const
	{
		return m_ItemNum;
	}

};
//BuyItem回应封装类
class ShopRpcBuyItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcBuyItemReplyWraper()
	{
		
		m_Result = -1;
		m_ItemInfo = ShopItemWraper();

	}
	//赋值构造函数
	ShopRpcBuyItemReplyWraper(const ShopRpcBuyItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcBuyItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcBuyItemReply ToPB() const
	{
		ShopRpcBuyItemReply v;
		v.set_result( m_Result );
		*v.mutable_iteminfo()= m_ItemInfo.ToPB();

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
		ShopRpcBuyItemReply pb;
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
	void Init(const ShopRpcBuyItemReply& v)
	{
		m_Result = v.result();
		m_ItemInfo = v.iteminfo();

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
	//ItemInfo
	ShopItemWraper m_ItemInfo;
public:
	void SetItemInfo( const ShopItemWraper& v)
	{
		m_ItemInfo=v;
	}
	ShopItemWraper GetItemInfo()
	{
		return m_ItemInfo;
	}
	ShopItemWraper GetItemInfo() const
	{
		return m_ItemInfo;
	}

};

template<typename T> struct MessageIdT;


#endif
