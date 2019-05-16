/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperDropItem.h
* Author:       甘业清
* Description:  掉落RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DROPITEM_H
#define __RPC_WRAPER_DROPITEM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DropItemRpc.pb.h"



//掉落类的枚举定义
enum ConstDropItemE
{
	MODULE_ID_DROPITEM                           = 20,	//掉落模块ID
	RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY           = 2051,	//掉落-->掉落通知-->通知


};


//掉落通知通知封装类
class DropItemRpcDropTtemsNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemRpcDropTtemsNotifyWraper()
	{
		
		m_KillObjID = -1;
		m_KillerObjID = -1;
		m_OwnerObjID = -1;
		m_Pos = Vector3Wraper();
		m_NetWorkType = -1;

	}
	//赋值构造函数
	DropItemRpcDropTtemsNotifyWraper(const DropItemRpcDropTtemsNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemRpcDropTtemsNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemRpcDropTtemsNotify ToPB() const
	{
		DropItemRpcDropTtemsNotify v;
		v.mutable_dropitems()->Reserve(m_Dropitems.size());
		for (int i=0; i<(int)m_Dropitems.size(); i++)
		{
			*v.add_dropitems() = m_Dropitems[i].ToPB();
		}
		v.set_killobjid( m_KillObjID );
		v.set_killerobjid( m_KillerObjID );
		v.set_ownerobjid( m_OwnerObjID );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_networktype( m_NetWorkType );

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
		DropItemRpcDropTtemsNotify pb;
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
	void Init(const DropItemRpcDropTtemsNotify& v)
	{
		m_Dropitems.clear();
		m_Dropitems.reserve(v.dropitems_size());
		for( int i=0; i<v.dropitems_size(); i++)
			m_Dropitems.push_back(v.dropitems(i));
		m_KillObjID = v.killobjid();
		m_KillerObjID = v.killerobjid();
		m_OwnerObjID = v.ownerobjid();
		m_Pos = v.pos();
		m_NetWorkType = v.networktype();

	}

private:
	//掉落物品
	vector<DropItemWraper> m_Dropitems;
public:
	int SizeDropitems()
	{
		return m_Dropitems.size();
	}
	const vector<DropItemWraper>& GetDropitems() const
	{
		return m_Dropitems;
	}
	DropItemWraper GetDropitems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Dropitems.size())
		{
			assert(false);
			return DropItemWraper();
		}
		return m_Dropitems[Index];
	}
	void SetDropitems( const vector<DropItemWraper>& v )
	{
		m_Dropitems=v;
	}
	void ClearDropitems( )
	{
		m_Dropitems.clear();
	}
	void SetDropitems( int Index, const DropItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_Dropitems.size())
		{
			assert(false);
			return;
		}
		m_Dropitems[Index] = v;
	}
	void AddDropitems( const DropItemWraper& v )
	{
		m_Dropitems.push_back(v);
	}
private:
	//死亡怪物ID
	INT32 m_KillObjID;
public:
	void SetKillObjID( INT32 v)
	{
		m_KillObjID=v;
	}
	INT32 GetKillObjID()
	{
		return m_KillObjID;
	}
	INT32 GetKillObjID() const
	{
		return m_KillObjID;
	}
private:
	//主角ID
	INT32 m_KillerObjID;
public:
	void SetKillerObjID( INT32 v)
	{
		m_KillerObjID=v;
	}
	INT32 GetKillerObjID()
	{
		return m_KillerObjID;
	}
	INT32 GetKillerObjID() const
	{
		return m_KillerObjID;
	}
private:
	//所属ID
	INT32 m_OwnerObjID;
public:
	void SetOwnerObjID( INT32 v)
	{
		m_OwnerObjID=v;
	}
	INT32 GetOwnerObjID()
	{
		return m_OwnerObjID;
	}
	INT32 GetOwnerObjID() const
	{
		return m_OwnerObjID;
	}
private:
	//Pos
	Vector3Wraper m_Pos;
public:
	void SetPos( const Vector3Wraper& v)
	{
		m_Pos=v;
	}
	Vector3Wraper GetPos()
	{
		return m_Pos;
	}
	Vector3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//掉落广播类型
	INT32 m_NetWorkType;
public:
	void SetNetWorkType( INT32 v)
	{
		m_NetWorkType=v;
	}
	INT32 GetNetWorkType()
	{
		return m_NetWorkType;
	}
	INT32 GetNetWorkType() const
	{
		return m_NetWorkType;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DropItemRpcDropTtemsNotifyWraper>{ enum{ID=RPC_CODE_DROPITEM_DROPTTEMS_NOTIFY};};


#endif
