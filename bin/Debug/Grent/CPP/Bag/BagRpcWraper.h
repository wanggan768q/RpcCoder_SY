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
	RPC_CODE_BAG_SALEITEM_REQUEST                = 1252,	//Bag-->SaleItem-->请求
	RPC_CODE_BAG_LOCKITEM_REQUEST                = 1253,	//Bag-->LockItem-->请求
	RPC_CODE_BAG_DEBLOCKING_REQUEST              = 1254,	//Bag-->解锁背包格子-->请求
	RPC_CODE_BAG_TAKEITEM_REQUEST                = 1255,	//Bag-->TakeItem-->请求
	RPC_CODE_BAG_TIDY_REQUEST                    = 1256,	//Bag-->整理-->请求
	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST         = 1257,	//Bag-->临时背包全部取回-->请求
	RPC_CODE_BAG_BAGCHANGE_NOTIFY                = 1258,	//Bag-->背包数据推送-->通知
	RPC_CODE_BAG_MERGEITEM_REQUEST               = 1259,	//Bag-->MergeItem-->请求
	RPC_CODE_BAG_BAGSYNC_REQUEST                 = 1260,	//Bag-->背包数据初始化-->请求
	RPC_CODE_BAG_ADDITEM_NOTIFY                  = 1261,	//Bag-->新加物品-->通知
	RPC_CODE_BAG_CONSUMEITEM_REQUEST             = 1262,	//Bag-->根据物品id使用物品-->请求
	RPC_CODE_BAG_ITEMCHANGE_NOTIFY               = 1263,	//Bag-->物品改变-->通知
	RPC_CODE_BAG_CLICKITEM_REQUEST               = 1264,	//Bag-->点击物品-->请求
	RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST         = 1265,	//Bag-->通过位置删除物品-->请求
	RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST        = 1266,	//Bag-->清除背包红点-->请求


};


//新加物品通知封装类
class BagRpcAddItemNotifyWraper
{
public:
	//构造函数
	BagRpcAddItemNotifyWraper()
	{
		

	}
	//赋值构造函数
	BagRpcAddItemNotifyWraper(const BagRpcAddItemNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcAddItemNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcAddItemNotify ToPB() const
	{
		BagRpcAddItemNotify v;
		v.mutable_item()->Reserve(m_Item.size());
		for (int i=0; i<(int)m_Item.size(); i++)
		{
			*v.add_item() = m_Item[i].ToPB();
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
		BagRpcAddItemNotify pb;
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
	void Init(const BagRpcAddItemNotify& v)
	{
		m_Item.clear();
		m_Item.reserve(v.item_size());
		for( int i=0; i<v.item_size(); i++)
			m_Item.push_back(v.item(i));

	}

private:
	//位置
	vector<ItemObjWraper> m_Item;
public:
	int SizeItem()
	{
		return m_Item.size();
	}
	const vector<ItemObjWraper>& GetItem() const
	{
		return m_Item;
	}
	ItemObjWraper GetItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_Item.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_Item[Index];
	}
	void SetItem( const vector<ItemObjWraper>& v )
	{
		m_Item=v;
	}
	void ClearItem( )
	{
		m_Item.clear();
	}
	void SetItem( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_Item.size())
		{
			assert(false);
			return;
		}
		m_Item[Index] = v;
	}
	void AddItem( const ItemObjWraper& v )
	{
		m_Item.push_back(v);
	}

};
//根据物品id使用物品请求封装类
class BagRpcConsumeItemAskWraper
{
public:
	//构造函数
	BagRpcConsumeItemAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcConsumeItemAskWraper(const BagRpcConsumeItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcConsumeItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcConsumeItemAsk ToPB() const
	{
		BagRpcConsumeItemAsk v;
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
		BagRpcConsumeItemAsk pb;
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
	void Init(const BagRpcConsumeItemAsk& v)
	{
		m_ItemData.clear();
		m_ItemData.reserve(v.itemdata_size());
		for( int i=0; i<v.itemdata_size(); i++)
			m_ItemData.push_back(v.itemdata(i));

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
//根据物品id使用物品回应封装类
class BagRpcConsumeItemReplyWraper
{
public:
	//构造函数
	BagRpcConsumeItemReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BagRpcConsumeItemReplyWraper(const BagRpcConsumeItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcConsumeItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcConsumeItemReply ToPB() const
	{
		BagRpcConsumeItemReply v;
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
		BagRpcConsumeItemReply pb;
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
	void Init(const BagRpcConsumeItemReply& v)
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
//背包数据初始化回应封装类
class BagRpcBagSyncReplyWraper
{
public:
	//构造函数
	BagRpcBagSyncReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BagRpcBagSyncReplyWraper(const BagRpcBagSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagSyncReply ToPB() const
	{
		BagRpcBagSyncReply v;
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
		BagRpcBagSyncReply pb;
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
	void Init(const BagRpcBagSyncReply& v)
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
	//Bags
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
//MergeItem请求封装类
class BagRpcMergeItemAskWraper
{
public:
	//构造函数
	BagRpcMergeItemAskWraper()
	{
		
		m_Pos = -1;
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcMergeItemAskWraper(const BagRpcMergeItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcMergeItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcMergeItemAsk ToPB() const
	{
		BagRpcMergeItemAsk v;
		v.set_pos( m_Pos );
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
		BagRpcMergeItemAsk pb;
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
	void Init(const BagRpcMergeItemAsk& v)
	{
		m_Pos = v.pos();
		m_BagType = v.bagtype();

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
//MergeItem回应封装类
class BagRpcMergeItemReplyWraper
{
public:
	//构造函数
	BagRpcMergeItemReplyWraper()
	{
		
		m_Result = -9999;
		m_Bags = BagDataWraper();

	}
	//赋值构造函数
	BagRpcMergeItemReplyWraper(const BagRpcMergeItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcMergeItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcMergeItemReply ToPB() const
	{
		BagRpcMergeItemReply v;
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
		BagRpcMergeItemReply pb;
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
	void Init(const BagRpcMergeItemReply& v)
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
//背包数据初始化请求封装类
class BagRpcBagSyncAskWraper
{
public:
	//构造函数
	BagRpcBagSyncAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcBagSyncAskWraper(const BagRpcBagSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcBagSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcBagSyncAsk ToPB() const
	{
		BagRpcBagSyncAsk v;

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
		BagRpcBagSyncAsk pb;
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
	void Init(const BagRpcBagSyncAsk& v)
	{

	}


};
//通过位置删除物品回应封装类
class BagRpcRemoveItemByPosReplyWraper
{
public:
	//构造函数
	BagRpcRemoveItemByPosReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BagRpcRemoveItemByPosReplyWraper(const BagRpcRemoveItemByPosReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcRemoveItemByPosReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcRemoveItemByPosReply ToPB() const
	{
		BagRpcRemoveItemByPosReply v;
		v.set_result( m_Result );
		v.mutable_itemlist()->Reserve(m_ItemList.size());
		for (int i=0; i<(int)m_ItemList.size(); i++)
		{
			*v.add_itemlist() = m_ItemList[i].ToPB();
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
		BagRpcRemoveItemByPosReply pb;
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
	void Init(const BagRpcRemoveItemByPosReply& v)
	{
		m_Result = v.result();
		m_ItemList.clear();
		m_ItemList.reserve(v.itemlist_size());
		for( int i=0; i<v.itemlist_size(); i++)
			m_ItemList.push_back(v.itemlist(i));

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
	//改变的物品
	vector<ItemObjWraper> m_ItemList;
public:
	int SizeItemList()
	{
		return m_ItemList.size();
	}
	const vector<ItemObjWraper>& GetItemList() const
	{
		return m_ItemList;
	}
	ItemObjWraper GetItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_ItemList[Index];
	}
	void SetItemList( const vector<ItemObjWraper>& v )
	{
		m_ItemList=v;
	}
	void ClearItemList( )
	{
		m_ItemList.clear();
	}
	void SetItemList( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return;
		}
		m_ItemList[Index] = v;
	}
	void AddItemList( const ItemObjWraper& v )
	{
		m_ItemList.push_back(v);
	}

};
//清除背包红点请求封装类
class BagRpcClearBagRedPointAskWraper
{
public:
	//构造函数
	BagRpcClearBagRedPointAskWraper()
	{
		

	}
	//赋值构造函数
	BagRpcClearBagRedPointAskWraper(const BagRpcClearBagRedPointAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcClearBagRedPointAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcClearBagRedPointAsk ToPB() const
	{
		BagRpcClearBagRedPointAsk v;

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
		BagRpcClearBagRedPointAsk pb;
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
	void Init(const BagRpcClearBagRedPointAsk& v)
	{

	}


};
//清除背包红点回应封装类
class BagRpcClearBagRedPointReplyWraper
{
public:
	//构造函数
	BagRpcClearBagRedPointReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BagRpcClearBagRedPointReplyWraper(const BagRpcClearBagRedPointReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcClearBagRedPointReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcClearBagRedPointReply ToPB() const
	{
		BagRpcClearBagRedPointReply v;
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
		BagRpcClearBagRedPointReply pb;
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
	void Init(const BagRpcClearBagRedPointReply& v)
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
//通过位置删除物品请求封装类
class BagRpcRemoveItemByPosAskWraper
{
public:
	//构造函数
	BagRpcRemoveItemByPosAskWraper()
	{
		
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcRemoveItemByPosAskWraper(const BagRpcRemoveItemByPosAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcRemoveItemByPosAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcRemoveItemByPosAsk ToPB() const
	{
		BagRpcRemoveItemByPosAsk v;
		v.mutable_poslist()->Reserve(m_PosList.size());
		for (int i=0; i<(int)m_PosList.size(); i++)
		{
			v.add_poslist(m_PosList[i]);
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
		BagRpcRemoveItemByPosAsk pb;
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
	void Init(const BagRpcRemoveItemByPosAsk& v)
	{
		m_PosList.clear();
		m_PosList.reserve(v.poslist_size());
		for( int i=0; i<v.poslist_size(); i++)
			m_PosList.push_back(v.poslist(i));
		m_BagType = v.bagtype();

	}

private:
	//位置列表
	vector<INT32> m_PosList;
public:
	int SizePosList()
	{
		return m_PosList.size();
	}
	const vector<INT32>& GetPosList() const
	{
		return m_PosList;
	}
	INT32 GetPosList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PosList.size())
		{
			assert(false);
			return INT32();
		}
		return m_PosList[Index];
	}
	void SetPosList( const vector<INT32>& v )
	{
		m_PosList=v;
	}
	void ClearPosList( )
	{
		m_PosList.clear();
	}
	void SetPosList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_PosList.size())
		{
			assert(false);
			return;
		}
		m_PosList[Index] = v;
	}
	void AddPosList( INT32 v = -1 )
	{
		m_PosList.push_back(v);
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
//物品改变通知封装类
class BagRpcItemChangeNotifyWraper
{
public:
	//构造函数
	BagRpcItemChangeNotifyWraper()
	{
		
		m_BagType = -1;

	}
	//赋值构造函数
	BagRpcItemChangeNotifyWraper(const BagRpcItemChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcItemChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcItemChangeNotify ToPB() const
	{
		BagRpcItemChangeNotify v;
		v.mutable_itemlist()->Reserve(m_ItemList.size());
		for (int i=0; i<(int)m_ItemList.size(); i++)
		{
			*v.add_itemlist() = m_ItemList[i].ToPB();
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
		BagRpcItemChangeNotify pb;
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
	void Init(const BagRpcItemChangeNotify& v)
	{
		m_ItemList.clear();
		m_ItemList.reserve(v.itemlist_size());
		for( int i=0; i<v.itemlist_size(); i++)
			m_ItemList.push_back(v.itemlist(i));
		m_BagType = v.bagtype();

	}

private:
	//改变的物品
	vector<ItemObjWraper> m_ItemList;
public:
	int SizeItemList()
	{
		return m_ItemList.size();
	}
	const vector<ItemObjWraper>& GetItemList() const
	{
		return m_ItemList;
	}
	ItemObjWraper GetItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_ItemList[Index];
	}
	void SetItemList( const vector<ItemObjWraper>& v )
	{
		m_ItemList=v;
	}
	void ClearItemList( )
	{
		m_ItemList.clear();
	}
	void SetItemList( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return;
		}
		m_ItemList[Index] = v;
	}
	void AddItemList( const ItemObjWraper& v )
	{
		m_ItemList.push_back(v);
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
//点击物品请求封装类
class BagRpcClickItemAskWraper
{
public:
	//构造函数
	BagRpcClickItemAskWraper()
	{
		
		m_Guid = 0;

	}
	//赋值构造函数
	BagRpcClickItemAskWraper(const BagRpcClickItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcClickItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcClickItemAsk ToPB() const
	{
		BagRpcClickItemAsk v;
		v.set_guid( m_Guid );

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
		BagRpcClickItemAsk pb;
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
	void Init(const BagRpcClickItemAsk& v)
	{
		m_Guid = v.guid();

	}

private:
	//物品GUID
	uint64_t m_Guid;
public:
	void SetGuid( uint64_t v)
	{
		m_Guid=v;
	}
	uint64_t GetGuid()
	{
		return m_Guid;
	}
	uint64_t GetGuid() const
	{
		return m_Guid;
	}

};
//点击物品回应封装类
class BagRpcClickItemReplyWraper
{
public:
	//构造函数
	BagRpcClickItemReplyWraper()
	{
		
		m_Result = -1;
		m_Item = ItemObjWraper();

	}
	//赋值构造函数
	BagRpcClickItemReplyWraper(const BagRpcClickItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BagRpcClickItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagRpcClickItemReply ToPB() const
	{
		BagRpcClickItemReply v;
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
		BagRpcClickItemReply pb;
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
	void Init(const BagRpcClickItemReply& v)
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
//LockItem请求封装类
class BagRpcLockItemAskWraper
{
public:
	//构造函数
	BagRpcLockItemAskWraper()
	{
		
		m_Pos = -1;
		m_IsLock = false;
		m_BagType = -1;

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
		m_BagType = v.bagtype();

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
//UseItem请求封装类
class BagRpcUseItemAskWraper
{
public:
	//构造函数
	BagRpcUseItemAskWraper()
	{
		
		m_Count = -1;
		m_Pos = -1;
		m_BagType = -1;
		m_TargetId = 0;
		m_OptionIdx = 0;

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
		v.set_bagtype( m_BagType );
		v.set_targetid( m_TargetId );
		v.set_optionidx( m_OptionIdx );

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
		m_BagType = v.bagtype();
		m_TargetId = v.targetid();
		m_OptionIdx = v.optionidx();

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
	//目标guid
	uint64_t m_TargetId;
public:
	void SetTargetId( uint64_t v)
	{
		m_TargetId=v;
	}
	uint64_t GetTargetId()
	{
		return m_TargetId;
	}
	uint64_t GetTargetId() const
	{
		return m_TargetId;
	}
private:
	//自选礼包的索引
	INT32 m_OptionIdx;
public:
	void SetOptionIdx( INT32 v)
	{
		m_OptionIdx=v;
	}
	INT32 GetOptionIdx()
	{
		return m_OptionIdx;
	}
	INT32 GetOptionIdx() const
	{
		return m_OptionIdx;
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
		m_NowItem = ItemObjWraper();

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
		*v.mutable_nowitem()= m_NowItem.ToPB();

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
		m_NowItem = v.nowitem();

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
private:
	//当前道具 
	ItemObjWraper m_NowItem;
public:
	void SetNowItem( const ItemObjWraper& v)
	{
		m_NowItem=v;
	}
	ItemObjWraper GetNowItem()
	{
		return m_NowItem;
	}
	ItemObjWraper GetNowItem() const
	{
		return m_NowItem;
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
		m_BagType = -1;

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
		m_BagType = v.bagtype();

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
//整理回应封装类
class BagRpcTidyReplyWraper
{
public:
	//构造函数
	BagRpcTidyReplyWraper()
	{
		
		m_Result = -9999;
		m_Bags = BagDataWraper();

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
	//整理后的背包数据
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<BagRpcBagChangeNotifyWraper>{ enum{ID=RPC_CODE_BAG_BAGCHANGE_NOTIFY};};
template<> struct MessageIdT<BagRpcAddItemNotifyWraper>{ enum{ID=RPC_CODE_BAG_ADDITEM_NOTIFY};};
template<> struct MessageIdT<BagRpcItemChangeNotifyWraper>{ enum{ID=RPC_CODE_BAG_ITEMCHANGE_NOTIFY};};


#endif
