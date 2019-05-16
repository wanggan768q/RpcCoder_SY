/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperMedicament.h
* Author:       甘业清
* Description:  药剂RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_MEDICAMENT_H
#define __RPC_WRAPER_MEDICAMENT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "MedicamentRpc.pb.h"



//药剂类的枚举定义
enum ConstMedicamentE
{
	MODULE_ID_MEDICAMENT                         = 28,	//药剂模块ID
	RPC_CODE_MEDICAMENT_FILLHP_REQUEST           = 2851,	//药剂-->使用物品填充hp池-->请求
	RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST    = 2852,	//药剂-->一键添加-->请求
	RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST= 2853,	//药剂-->客户端刷新药剂-->请求
	RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY= 2854,	//药剂-->服务器刷新药剂-->通知
	RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST= 2855,	//药剂-->请求数据-->请求
	RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST     = 2856,	//药剂-->药剂CD-->请求
	RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY= 2857,	//药剂-->通知CD-->通知


};


//请求数据回应封装类
class MedicamentRpcSyncMedicamentDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcSyncMedicamentDataReplyWraper()
	{
		
		m_Result = -1;
		m_Medicament = RecoverMedicamentWraper();

	}
	//赋值构造函数
	MedicamentRpcSyncMedicamentDataReplyWraper(const MedicamentRpcSyncMedicamentDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcSyncMedicamentDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcSyncMedicamentDataReply ToPB() const
	{
		MedicamentRpcSyncMedicamentDataReply v;
		v.set_result( m_Result );
		*v.mutable_medicament()= m_Medicament.ToPB();

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
		MedicamentRpcSyncMedicamentDataReply pb;
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
	void Init(const MedicamentRpcSyncMedicamentDataReply& v)
	{
		m_Result = v.result();
		m_Medicament = v.medicament();

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
	//药剂
	RecoverMedicamentWraper m_Medicament;
public:
	void SetMedicament( const RecoverMedicamentWraper& v)
	{
		m_Medicament=v;
	}
	RecoverMedicamentWraper GetMedicament()
	{
		return m_Medicament;
	}
	RecoverMedicamentWraper GetMedicament() const
	{
		return m_Medicament;
	}

};
//请求数据请求封装类
class MedicamentRpcSyncMedicamentDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcSyncMedicamentDataAskWraper()
	{
		

	}
	//赋值构造函数
	MedicamentRpcSyncMedicamentDataAskWraper(const MedicamentRpcSyncMedicamentDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcSyncMedicamentDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcSyncMedicamentDataAsk ToPB() const
	{
		MedicamentRpcSyncMedicamentDataAsk v;

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
		MedicamentRpcSyncMedicamentDataAsk pb;
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
	void Init(const MedicamentRpcSyncMedicamentDataAsk& v)
	{

	}


};
//服务器刷新药剂通知封装类
class MedicamentRpcServerRefreshMedicamentNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcServerRefreshMedicamentNotifyWraper()
	{
		
		m_Medicament = RecoverMedicamentWraper();

	}
	//赋值构造函数
	MedicamentRpcServerRefreshMedicamentNotifyWraper(const MedicamentRpcServerRefreshMedicamentNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcServerRefreshMedicamentNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcServerRefreshMedicamentNotify ToPB() const
	{
		MedicamentRpcServerRefreshMedicamentNotify v;
		*v.mutable_medicament()= m_Medicament.ToPB();

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
		MedicamentRpcServerRefreshMedicamentNotify pb;
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
	void Init(const MedicamentRpcServerRefreshMedicamentNotify& v)
	{
		m_Medicament = v.medicament();

	}

private:
	//药剂
	RecoverMedicamentWraper m_Medicament;
public:
	void SetMedicament( const RecoverMedicamentWraper& v)
	{
		m_Medicament=v;
	}
	RecoverMedicamentWraper GetMedicament()
	{
		return m_Medicament;
	}
	RecoverMedicamentWraper GetMedicament() const
	{
		return m_Medicament;
	}

};
//通知CD通知封装类
class MedicamentRpcMedicamentCDNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcMedicamentCDNotifyNotifyWraper()
	{
		
		m_LeftTime = -1;

	}
	//赋值构造函数
	MedicamentRpcMedicamentCDNotifyNotifyWraper(const MedicamentRpcMedicamentCDNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcMedicamentCDNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcMedicamentCDNotifyNotify ToPB() const
	{
		MedicamentRpcMedicamentCDNotifyNotify v;
		v.set_lefttime( m_LeftTime );

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
		MedicamentRpcMedicamentCDNotifyNotify pb;
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
	void Init(const MedicamentRpcMedicamentCDNotifyNotify& v)
	{
		m_LeftTime = v.lefttime();

	}

private:
	//剩余时间
	INT32 m_LeftTime;
public:
	void SetLeftTime( INT32 v)
	{
		m_LeftTime=v;
	}
	INT32 GetLeftTime()
	{
		return m_LeftTime;
	}
	INT32 GetLeftTime() const
	{
		return m_LeftTime;
	}

};
//药剂CD回应封装类
class MedicamentRpcMedicamentCDReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcMedicamentCDReplyWraper()
	{
		
		m_Result = -1;
		m_LeftTime = -1;

	}
	//赋值构造函数
	MedicamentRpcMedicamentCDReplyWraper(const MedicamentRpcMedicamentCDReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcMedicamentCDReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcMedicamentCDReply ToPB() const
	{
		MedicamentRpcMedicamentCDReply v;
		v.set_result( m_Result );
		v.set_lefttime( m_LeftTime );

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
		MedicamentRpcMedicamentCDReply pb;
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
	void Init(const MedicamentRpcMedicamentCDReply& v)
	{
		m_Result = v.result();
		m_LeftTime = v.lefttime();

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
	//剩余时间
	INT32 m_LeftTime;
public:
	void SetLeftTime( INT32 v)
	{
		m_LeftTime=v;
	}
	INT32 GetLeftTime()
	{
		return m_LeftTime;
	}
	INT32 GetLeftTime() const
	{
		return m_LeftTime;
	}

};
//药剂CD请求封装类
class MedicamentRpcMedicamentCDAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcMedicamentCDAskWraper()
	{
		

	}
	//赋值构造函数
	MedicamentRpcMedicamentCDAskWraper(const MedicamentRpcMedicamentCDAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcMedicamentCDAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcMedicamentCDAsk ToPB() const
	{
		MedicamentRpcMedicamentCDAsk v;

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
		MedicamentRpcMedicamentCDAsk pb;
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
	void Init(const MedicamentRpcMedicamentCDAsk& v)
	{

	}


};
//一键添加请求封装类
class MedicamentRpcOneStepFillHpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcOneStepFillHpAskWraper()
	{
		

	}
	//赋值构造函数
	MedicamentRpcOneStepFillHpAskWraper(const MedicamentRpcOneStepFillHpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcOneStepFillHpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcOneStepFillHpAsk ToPB() const
	{
		MedicamentRpcOneStepFillHpAsk v;
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
		MedicamentRpcOneStepFillHpAsk pb;
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
	void Init(const MedicamentRpcOneStepFillHpAsk& v)
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
//使用物品填充hp池回应封装类
class MedicamentRpcFillHpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcFillHpReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MedicamentRpcFillHpReplyWraper(const MedicamentRpcFillHpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcFillHpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcFillHpReply ToPB() const
	{
		MedicamentRpcFillHpReply v;
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
		MedicamentRpcFillHpReply pb;
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
	void Init(const MedicamentRpcFillHpReply& v)
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
//使用物品填充hp池请求封装类
class MedicamentRpcFillHpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcFillHpAskWraper()
	{
		
		m_ItemData = ItemSimpleDataWraper();

	}
	//赋值构造函数
	MedicamentRpcFillHpAskWraper(const MedicamentRpcFillHpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcFillHpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcFillHpAsk ToPB() const
	{
		MedicamentRpcFillHpAsk v;
		*v.mutable_itemdata()= m_ItemData.ToPB();

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
		MedicamentRpcFillHpAsk pb;
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
	void Init(const MedicamentRpcFillHpAsk& v)
	{
		m_ItemData = v.itemdata();

	}

private:
	//物品id
	ItemSimpleDataWraper m_ItemData;
public:
	void SetItemData( const ItemSimpleDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemSimpleDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemSimpleDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//客户端刷新药剂回应封装类
class MedicamentRpcClientRefreshMedicamentReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcClientRefreshMedicamentReplyWraper()
	{
		
		m_Result = -1;
		m_Medicament = RecoverMedicamentWraper();

	}
	//赋值构造函数
	MedicamentRpcClientRefreshMedicamentReplyWraper(const MedicamentRpcClientRefreshMedicamentReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcClientRefreshMedicamentReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcClientRefreshMedicamentReply ToPB() const
	{
		MedicamentRpcClientRefreshMedicamentReply v;
		v.set_result( m_Result );
		*v.mutable_medicament()= m_Medicament.ToPB();

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
		MedicamentRpcClientRefreshMedicamentReply pb;
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
	void Init(const MedicamentRpcClientRefreshMedicamentReply& v)
	{
		m_Result = v.result();
		m_Medicament = v.medicament();

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
	//药剂
	RecoverMedicamentWraper m_Medicament;
public:
	void SetMedicament( const RecoverMedicamentWraper& v)
	{
		m_Medicament=v;
	}
	RecoverMedicamentWraper GetMedicament()
	{
		return m_Medicament;
	}
	RecoverMedicamentWraper GetMedicament() const
	{
		return m_Medicament;
	}

};
//客户端刷新药剂请求封装类
class MedicamentRpcClientRefreshMedicamentAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcClientRefreshMedicamentAskWraper()
	{
		
		m_Medicament = RecoverMedicamentWraper();

	}
	//赋值构造函数
	MedicamentRpcClientRefreshMedicamentAskWraper(const MedicamentRpcClientRefreshMedicamentAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcClientRefreshMedicamentAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcClientRefreshMedicamentAsk ToPB() const
	{
		MedicamentRpcClientRefreshMedicamentAsk v;
		*v.mutable_medicament()= m_Medicament.ToPB();

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
		MedicamentRpcClientRefreshMedicamentAsk pb;
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
	void Init(const MedicamentRpcClientRefreshMedicamentAsk& v)
	{
		m_Medicament = v.medicament();

	}

private:
	//药剂
	RecoverMedicamentWraper m_Medicament;
public:
	void SetMedicament( const RecoverMedicamentWraper& v)
	{
		m_Medicament=v;
	}
	RecoverMedicamentWraper GetMedicament()
	{
		return m_Medicament;
	}
	RecoverMedicamentWraper GetMedicament() const
	{
		return m_Medicament;
	}

};
//一键添加回应封装类
class MedicamentRpcOneStepFillHpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	MedicamentRpcOneStepFillHpReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	MedicamentRpcOneStepFillHpReplyWraper(const MedicamentRpcOneStepFillHpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const MedicamentRpcOneStepFillHpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MedicamentRpcOneStepFillHpReply ToPB() const
	{
		MedicamentRpcOneStepFillHpReply v;
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
		MedicamentRpcOneStepFillHpReply pb;
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
	void Init(const MedicamentRpcOneStepFillHpReply& v)
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<MedicamentRpcServerRefreshMedicamentNotifyWraper>{ enum{ID=RPC_CODE_MEDICAMENT_SERVERREFRESHMEDICAMENT_NOTIFY};};
template<> struct MessageIdT<MedicamentRpcMedicamentCDNotifyNotifyWraper>{ enum{ID=RPC_CODE_MEDICAMENT_MEDICAMENTCDNOTIFY_NOTIFY};};


#endif
