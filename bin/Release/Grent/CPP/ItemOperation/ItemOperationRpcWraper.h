/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperItemOperation.h
* Author:       甘业清
* Description:  道具操作RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ITEMOPERATION_H
#define __RPC_WRAPER_ITEMOPERATION_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ItemOperationRpc.pb.h"



//道具操作类的枚举定义
enum ConstItemOperationE
{
	MODULE_ID_ITEMOPERATION                      = 17,	//道具操作模块ID
	RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST= 1751,	//道具操作-->道具分解界面初始化-->请求
	RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST   = 1752,	//道具操作-->道具分解-->请求
	RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST = 1753,	//道具操作-->更改设置-->请求
	RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST  = 1754,	//道具操作-->一键分解-->请求
	RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST  = 1755,	//道具操作-->道具合成-->请求


};


//一键分解请求封装类
class ItemOperationRpcBatchResolveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcBatchResolveAskWraper()
	{
		
		m_Qulity = -1;

	}
	//赋值构造函数
	ItemOperationRpcBatchResolveAskWraper(const ItemOperationRpcBatchResolveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcBatchResolveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcBatchResolveAsk ToPB() const
	{
		ItemOperationRpcBatchResolveAsk v;
		v.set_qulity( m_Qulity );

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
		ItemOperationRpcBatchResolveAsk pb;
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
	void Init(const ItemOperationRpcBatchResolveAsk& v)
	{
		m_Qulity = v.qulity();

	}

private:
	//一键分解的品质类别
	INT32 m_Qulity;
public:
	void SetQulity( INT32 v)
	{
		m_Qulity=v;
	}
	INT32 GetQulity()
	{
		return m_Qulity;
	}
	INT32 GetQulity() const
	{
		return m_Qulity;
	}

};
//更改设置回应封装类
class ItemOperationRpcChangeSettingReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcChangeSettingReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ItemOperationRpcChangeSettingReplyWraper(const ItemOperationRpcChangeSettingReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcChangeSettingReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcChangeSettingReply ToPB() const
	{
		ItemOperationRpcChangeSettingReply v;
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
		ItemOperationRpcChangeSettingReply pb;
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
	void Init(const ItemOperationRpcChangeSettingReply& v)
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
//一键分解回应封装类
class ItemOperationRpcBatchResolveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcBatchResolveReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ItemOperationRpcBatchResolveReplyWraper(const ItemOperationRpcBatchResolveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcBatchResolveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcBatchResolveReply ToPB() const
	{
		ItemOperationRpcBatchResolveReply v;
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
		ItemOperationRpcBatchResolveReply pb;
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
	void Init(const ItemOperationRpcBatchResolveReply& v)
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
//道具合成回应封装类
class ItemOperationRpcItemCompoundReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemCompoundReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemConfID = -1;

	}
	//赋值构造函数
	ItemOperationRpcItemCompoundReplyWraper(const ItemOperationRpcItemCompoundReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemCompoundReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemCompoundReply ToPB() const
	{
		ItemOperationRpcItemCompoundReply v;
		v.set_result( m_Result );
		v.set_itemconfid( m_ItemConfID );

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
		ItemOperationRpcItemCompoundReply pb;
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
	void Init(const ItemOperationRpcItemCompoundReply& v)
	{
		m_Result = v.result();
		m_ItemConfID = v.itemconfid();

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
	//合成道具的confID
	INT32 m_ItemConfID;
public:
	void SetItemConfID( INT32 v)
	{
		m_ItemConfID=v;
	}
	INT32 GetItemConfID()
	{
		return m_ItemConfID;
	}
	INT32 GetItemConfID() const
	{
		return m_ItemConfID;
	}

};
//道具合成请求封装类
class ItemOperationRpcItemCompoundAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemCompoundAskWraper()
	{
		
		m_ItemConfID = -1;

	}
	//赋值构造函数
	ItemOperationRpcItemCompoundAskWraper(const ItemOperationRpcItemCompoundAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemCompoundAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemCompoundAsk ToPB() const
	{
		ItemOperationRpcItemCompoundAsk v;
		v.set_itemconfid( m_ItemConfID );

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
		ItemOperationRpcItemCompoundAsk pb;
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
	void Init(const ItemOperationRpcItemCompoundAsk& v)
	{
		m_ItemConfID = v.itemconfid();

	}

private:
	//合成道具的confID
	INT32 m_ItemConfID;
public:
	void SetItemConfID( INT32 v)
	{
		m_ItemConfID=v;
	}
	INT32 GetItemConfID()
	{
		return m_ItemConfID;
	}
	INT32 GetItemConfID() const
	{
		return m_ItemConfID;
	}

};
//道具分解界面初始化回应封装类
class ItemOperationRpcItemResolveSettingSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemResolveSettingSyncReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ItemOperationRpcItemResolveSettingSyncReplyWraper(const ItemOperationRpcItemResolveSettingSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemResolveSettingSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemResolveSettingSyncReply ToPB() const
	{
		ItemOperationRpcItemResolveSettingSyncReply v;
		v.set_result( m_Result );
		v.mutable_setting()->Reserve(m_Setting.size());
		for (int i=0; i<(int)m_Setting.size(); i++)
		{
			*v.add_setting() = m_Setting[i].ToPB();
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
		ItemOperationRpcItemResolveSettingSyncReply pb;
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
	void Init(const ItemOperationRpcItemResolveSettingSyncReply& v)
	{
		m_Result = v.result();
		m_Setting.clear();
		m_Setting.reserve(v.setting_size());
		for( int i=0; i<v.setting_size(); i++)
			m_Setting.push_back(v.setting(i));

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
	//设置列表
	vector<ItemResolveDataWraper> m_Setting;
public:
	int SizeSetting()
	{
		return m_Setting.size();
	}
	const vector<ItemResolveDataWraper>& GetSetting() const
	{
		return m_Setting;
	}
	ItemResolveDataWraper GetSetting(int Index) const
	{
		if(Index<0 || Index>=(int)m_Setting.size())
		{
			assert(false);
			return ItemResolveDataWraper();
		}
		return m_Setting[Index];
	}
	void SetSetting( const vector<ItemResolveDataWraper>& v )
	{
		m_Setting=v;
	}
	void ClearSetting( )
	{
		m_Setting.clear();
	}
	void SetSetting( int Index, const ItemResolveDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Setting.size())
		{
			assert(false);
			return;
		}
		m_Setting[Index] = v;
	}
	void AddSetting( const ItemResolveDataWraper& v )
	{
		m_Setting.push_back(v);
	}

};
//道具分解界面初始化请求封装类
class ItemOperationRpcItemResolveSettingSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemResolveSettingSyncAskWraper()
	{
		

	}
	//赋值构造函数
	ItemOperationRpcItemResolveSettingSyncAskWraper(const ItemOperationRpcItemResolveSettingSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemResolveSettingSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemResolveSettingSyncAsk ToPB() const
	{
		ItemOperationRpcItemResolveSettingSyncAsk v;

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
		ItemOperationRpcItemResolveSettingSyncAsk pb;
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
	void Init(const ItemOperationRpcItemResolveSettingSyncAsk& v)
	{

	}


};
//道具分解请求封装类
class ItemOperationRpcItemResolveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemResolveAskWraper()
	{
		
		m_ItemPos = -1;
		m_Count = -1;

	}
	//赋值构造函数
	ItemOperationRpcItemResolveAskWraper(const ItemOperationRpcItemResolveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemResolveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemResolveAsk ToPB() const
	{
		ItemOperationRpcItemResolveAsk v;
		v.set_itempos( m_ItemPos );
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
		ItemOperationRpcItemResolveAsk pb;
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
	void Init(const ItemOperationRpcItemResolveAsk& v)
	{
		m_ItemPos = v.itempos();
		m_Count = v.count();

	}

private:
	//道具的位置
	INT32 m_ItemPos;
public:
	void SetItemPos( INT32 v)
	{
		m_ItemPos=v;
	}
	INT32 GetItemPos()
	{
		return m_ItemPos;
	}
	INT32 GetItemPos() const
	{
		return m_ItemPos;
	}
private:
	//分解道具数量
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
//更改设置请求封装类
class ItemOperationRpcChangeSettingAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcChangeSettingAskWraper()
	{
		

	}
	//赋值构造函数
	ItemOperationRpcChangeSettingAskWraper(const ItemOperationRpcChangeSettingAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcChangeSettingAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcChangeSettingAsk ToPB() const
	{
		ItemOperationRpcChangeSettingAsk v;
		v.mutable_settinglist()->Reserve(m_SettingList.size());
		for (int i=0; i<(int)m_SettingList.size(); i++)
		{
			*v.add_settinglist() = m_SettingList[i].ToPB();
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
		ItemOperationRpcChangeSettingAsk pb;
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
	void Init(const ItemOperationRpcChangeSettingAsk& v)
	{
		m_SettingList.clear();
		m_SettingList.reserve(v.settinglist_size());
		for( int i=0; i<v.settinglist_size(); i++)
			m_SettingList.push_back(v.settinglist(i));

	}

private:
	//设置列表
	vector<ItemResolveDataWraper> m_SettingList;
public:
	int SizeSettingList()
	{
		return m_SettingList.size();
	}
	const vector<ItemResolveDataWraper>& GetSettingList() const
	{
		return m_SettingList;
	}
	ItemResolveDataWraper GetSettingList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SettingList.size())
		{
			assert(false);
			return ItemResolveDataWraper();
		}
		return m_SettingList[Index];
	}
	void SetSettingList( const vector<ItemResolveDataWraper>& v )
	{
		m_SettingList=v;
	}
	void ClearSettingList( )
	{
		m_SettingList.clear();
	}
	void SetSettingList( int Index, const ItemResolveDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SettingList.size())
		{
			assert(false);
			return;
		}
		m_SettingList[Index] = v;
	}
	void AddSettingList( const ItemResolveDataWraper& v )
	{
		m_SettingList.push_back(v);
	}

};
//道具分解回应封装类
class ItemOperationRpcItemResolveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ItemOperationRpcItemResolveReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemID = -1;

	}
	//赋值构造函数
	ItemOperationRpcItemResolveReplyWraper(const ItemOperationRpcItemResolveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemOperationRpcItemResolveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemOperationRpcItemResolveReply ToPB() const
	{
		ItemOperationRpcItemResolveReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );
		v.mutable_itemsimpledatalist()->Reserve(m_ItemSimpleDataList.size());
		for (int i=0; i<(int)m_ItemSimpleDataList.size(); i++)
		{
			*v.add_itemsimpledatalist() = m_ItemSimpleDataList[i].ToPB();
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
		ItemOperationRpcItemResolveReply pb;
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
	void Init(const ItemOperationRpcItemResolveReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();
		m_ItemSimpleDataList.clear();
		m_ItemSimpleDataList.reserve(v.itemsimpledatalist_size());
		for( int i=0; i<v.itemsimpledatalist_size(); i++)
			m_ItemSimpleDataList.push_back(v.itemsimpledatalist(i));

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
	//道具唯一ID
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//道具简易数据列表
	vector<ItemSimpleDataWraper> m_ItemSimpleDataList;
public:
	int SizeItemSimpleDataList()
	{
		return m_ItemSimpleDataList.size();
	}
	const vector<ItemSimpleDataWraper>& GetItemSimpleDataList() const
	{
		return m_ItemSimpleDataList;
	}
	ItemSimpleDataWraper GetItemSimpleDataList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemSimpleDataList.size())
		{
			assert(false);
			return ItemSimpleDataWraper();
		}
		return m_ItemSimpleDataList[Index];
	}
	void SetItemSimpleDataList( const vector<ItemSimpleDataWraper>& v )
	{
		m_ItemSimpleDataList=v;
	}
	void ClearItemSimpleDataList( )
	{
		m_ItemSimpleDataList.clear();
	}
	void SetItemSimpleDataList( int Index, const ItemSimpleDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemSimpleDataList.size())
		{
			assert(false);
			return;
		}
		m_ItemSimpleDataList[Index] = v;
	}
	void AddItemSimpleDataList( const ItemSimpleDataWraper& v )
	{
		m_ItemSimpleDataList.push_back(v);
	}

};

template<typename T> struct MessageIdT;


#endif
