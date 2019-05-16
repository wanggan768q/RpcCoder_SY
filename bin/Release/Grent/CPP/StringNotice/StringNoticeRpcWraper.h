/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperStringNotice.h
* Author:       甘业清
* Description:  文本提示RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_STRINGNOTICE_H
#define __RPC_WRAPER_STRINGNOTICE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "StringNoticeRpc.pb.h"



//文本提示类的枚举定义
enum ConstStringNoticeE
{
	MODULE_ID_STRINGNOTICE                       = 55,	//文本提示模块ID
	RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY          = 5551,	//文本提示-->通知-->通知


};


//通知通知封装类
class StringNoticeRpcNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StringNoticeRpcNoticeNotifyWraper()
	{
		
		m_ConfigId = -1;

	}
	//赋值构造函数
	StringNoticeRpcNoticeNotifyWraper(const StringNoticeRpcNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const StringNoticeRpcNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StringNoticeRpcNoticeNotify ToPB() const
	{
		StringNoticeRpcNoticeNotify v;
		v.set_configid( m_ConfigId );
		v.mutable_param()->Reserve(m_Param.size());
		for (int i=0; i<(int)m_Param.size(); i++)
		{
			v.add_param( m_Param[i]);
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
		StringNoticeRpcNoticeNotify pb;
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
	void Init(const StringNoticeRpcNoticeNotify& v)
	{
		m_ConfigId = v.configid();
		m_Param.clear();
		m_Param.reserve(v.param_size());
		for( int i=0; i<v.param_size(); i++)
			m_Param.push_back(v.param(i));

	}

private:
	//文本ID
	INT32 m_ConfigId;
public:
	void SetConfigId( INT32 v)
	{
		m_ConfigId=v;
	}
	INT32 GetConfigId()
	{
		return m_ConfigId;
	}
	INT32 GetConfigId() const
	{
		return m_ConfigId;
	}
private:
	//参数
	vector<string> m_Param;
public:
	int SizeParam()
	{
		return m_Param.size();
	}
	const vector<string>& GetParam() const
	{
		return m_Param;
	}
	string GetParam(int Index) const
	{
		if(Index<0 || Index>=(int)m_Param.size())
		{
			assert(false);
			return string();
		}
		return m_Param[Index];
	}
	void SetParam( const vector<string>& v )
	{
		m_Param=v;
	}
	void ClearParam( )
	{
		m_Param.clear();
	}
	void SetParam( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_Param.size())
		{
			assert(false);
			return;
		}
		m_Param[Index] = v;
	}
	void AddParam( const string& v )
	{
		m_Param.push_back(v);
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<StringNoticeRpcNoticeNotifyWraper>{ enum{ID=RPC_CODE_STRINGNOTICE_NOTICE_NOTIFY};};


#endif
