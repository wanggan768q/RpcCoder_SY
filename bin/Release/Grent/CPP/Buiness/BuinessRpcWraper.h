/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperBuiness.h
* Author:       甘业清
* Description:  生活技能RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_BUINESS_H
#define __RPC_WRAPER_BUINESS_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "BuinessRpc.pb.h"



//生活技能类的枚举定义
enum ConstBuinessE
{
	MODULE_ID_BUINESS                            = 22,	//生活技能模块ID
	RPC_CODE_BUINESS_BUINESSSYNC_REQUEST         = 2251,	//生活技能-->初始化-->请求
	RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST       = 2252,	//生活技能-->解锁-->请求
	RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST        = 2253,	//生活技能-->学习技能-->请求
	RPC_CODE_BUINESS_BUINESSMAKE_REQUEST         = 2254,	//生活技能-->制作-->请求


};


//学习技能回应封装类
class BuinessRpcBuinessStudyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessStudyReplyWraper()
	{
		
		m_Result = -1;
		m_SkillData = BuinessSkillDataWraper();

	}
	//赋值构造函数
	BuinessRpcBuinessStudyReplyWraper(const BuinessRpcBuinessStudyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessStudyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessStudyReply ToPB() const
	{
		BuinessRpcBuinessStudyReply v;
		v.set_result( m_Result );
		*v.mutable_skilldata()= m_SkillData.ToPB();

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
		BuinessRpcBuinessStudyReply pb;
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
	void Init(const BuinessRpcBuinessStudyReply& v)
	{
		m_Result = v.result();
		m_SkillData = v.skilldata();

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
	//技能新属性
	BuinessSkillDataWraper m_SkillData;
public:
	void SetSkillData( const BuinessSkillDataWraper& v)
	{
		m_SkillData=v;
	}
	BuinessSkillDataWraper GetSkillData()
	{
		return m_SkillData;
	}
	BuinessSkillDataWraper GetSkillData() const
	{
		return m_SkillData;
	}

};
//学习技能请求封装类
class BuinessRpcBuinessStudyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessStudyAskWraper()
	{
		
		m_SkillID = -1;
		m_StudyType = -1;

	}
	//赋值构造函数
	BuinessRpcBuinessStudyAskWraper(const BuinessRpcBuinessStudyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessStudyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessStudyAsk ToPB() const
	{
		BuinessRpcBuinessStudyAsk v;
		v.set_skillid( m_SkillID );
		v.set_studytype( m_StudyType );

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
		BuinessRpcBuinessStudyAsk pb;
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
	void Init(const BuinessRpcBuinessStudyAsk& v)
	{
		m_SkillID = v.skillid();
		m_StudyType = v.studytype();

	}

private:
	//技能ID
	INT32 m_SkillID;
public:
	void SetSkillID( INT32 v)
	{
		m_SkillID=v;
	}
	INT32 GetSkillID()
	{
		return m_SkillID;
	}
	INT32 GetSkillID() const
	{
		return m_SkillID;
	}
private:
	//学习类型
	INT32 m_StudyType;
public:
	void SetStudyType( INT32 v)
	{
		m_StudyType=v;
	}
	INT32 GetStudyType()
	{
		return m_StudyType;
	}
	INT32 GetStudyType() const
	{
		return m_StudyType;
	}

};
//制作回应封装类
class BuinessRpcBuinessMakeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessMakeReplyWraper()
	{
		
		m_Result = -1;
		m_ItemID = -1;
		m_ItemCount = -1;

	}
	//赋值构造函数
	BuinessRpcBuinessMakeReplyWraper(const BuinessRpcBuinessMakeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessMakeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessMakeReply ToPB() const
	{
		BuinessRpcBuinessMakeReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );
		v.set_itemcount( m_ItemCount );

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
		BuinessRpcBuinessMakeReply pb;
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
	void Init(const BuinessRpcBuinessMakeReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();
		m_ItemCount = v.itemcount();

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
	//道具ID
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
	//数量
	INT32 m_ItemCount;
public:
	void SetItemCount( INT32 v)
	{
		m_ItemCount=v;
	}
	INT32 GetItemCount()
	{
		return m_ItemCount;
	}
	INT32 GetItemCount() const
	{
		return m_ItemCount;
	}

};
//制作请求封装类
class BuinessRpcBuinessMakeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessMakeAskWraper()
	{
		
		m_SkillID = -1;

	}
	//赋值构造函数
	BuinessRpcBuinessMakeAskWraper(const BuinessRpcBuinessMakeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessMakeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessMakeAsk ToPB() const
	{
		BuinessRpcBuinessMakeAsk v;
		v.set_skillid( m_SkillID );

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
		BuinessRpcBuinessMakeAsk pb;
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
	void Init(const BuinessRpcBuinessMakeAsk& v)
	{
		m_SkillID = v.skillid();

	}

private:
	//使用哪个技能
	INT32 m_SkillID;
public:
	void SetSkillID( INT32 v)
	{
		m_SkillID=v;
	}
	INT32 GetSkillID()
	{
		return m_SkillID;
	}
	INT32 GetSkillID() const
	{
		return m_SkillID;
	}

};
//初始化回应封装类
class BuinessRpcBuinessSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessSyncReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	BuinessRpcBuinessSyncReplyWraper(const BuinessRpcBuinessSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessSyncReply ToPB() const
	{
		BuinessRpcBuinessSyncReply v;
		v.set_result( m_Result );
		v.mutable_skilldatas()->Reserve(m_SkillDatas.size());
		for (int i=0; i<(int)m_SkillDatas.size(); i++)
		{
			*v.add_skilldatas() = m_SkillDatas[i].ToPB();
		}
		v.mutable_unlockinfos()->Reserve(m_UnLockInfos.size());
		for (int i=0; i<(int)m_UnLockInfos.size(); i++)
		{
			*v.add_unlockinfos() = m_UnLockInfos[i].ToPB();
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
		BuinessRpcBuinessSyncReply pb;
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
	void Init(const BuinessRpcBuinessSyncReply& v)
	{
		m_Result = v.result();
		m_SkillDatas.clear();
		m_SkillDatas.reserve(v.skilldatas_size());
		for( int i=0; i<v.skilldatas_size(); i++)
			m_SkillDatas.push_back(v.skilldatas(i));
		m_UnLockInfos.clear();
		m_UnLockInfos.reserve(v.unlockinfos_size());
		for( int i=0; i<v.unlockinfos_size(); i++)
			m_UnLockInfos.push_back(v.unlockinfos(i));

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
	//生活技能列表
	vector<BuinessSkillDataWraper> m_SkillDatas;
public:
	int SizeSkillDatas()
	{
		return m_SkillDatas.size();
	}
	const vector<BuinessSkillDataWraper>& GetSkillDatas() const
	{
		return m_SkillDatas;
	}
	BuinessSkillDataWraper GetSkillDatas(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillDatas.size())
		{
			assert(false);
			return BuinessSkillDataWraper();
		}
		return m_SkillDatas[Index];
	}
	void SetSkillDatas( const vector<BuinessSkillDataWraper>& v )
	{
		m_SkillDatas=v;
	}
	void ClearSkillDatas( )
	{
		m_SkillDatas.clear();
	}
	void SetSkillDatas( int Index, const BuinessSkillDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillDatas.size())
		{
			assert(false);
			return;
		}
		m_SkillDatas[Index] = v;
	}
	void AddSkillDatas( const BuinessSkillDataWraper& v )
	{
		m_SkillDatas.push_back(v);
	}
private:
	//解锁剩余时间
	vector<BuinessUnlockInfoWraper> m_UnLockInfos;
public:
	int SizeUnLockInfos()
	{
		return m_UnLockInfos.size();
	}
	const vector<BuinessUnlockInfoWraper>& GetUnLockInfos() const
	{
		return m_UnLockInfos;
	}
	BuinessUnlockInfoWraper GetUnLockInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnLockInfos.size())
		{
			assert(false);
			return BuinessUnlockInfoWraper();
		}
		return m_UnLockInfos[Index];
	}
	void SetUnLockInfos( const vector<BuinessUnlockInfoWraper>& v )
	{
		m_UnLockInfos=v;
	}
	void ClearUnLockInfos( )
	{
		m_UnLockInfos.clear();
	}
	void SetUnLockInfos( int Index, const BuinessUnlockInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnLockInfos.size())
		{
			assert(false);
			return;
		}
		m_UnLockInfos[Index] = v;
	}
	void AddUnLockInfos( const BuinessUnlockInfoWraper& v )
	{
		m_UnLockInfos.push_back(v);
	}

};
//初始化请求封装类
class BuinessRpcBuinessSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessSyncAskWraper()
	{
		

	}
	//赋值构造函数
	BuinessRpcBuinessSyncAskWraper(const BuinessRpcBuinessSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessSyncAsk ToPB() const
	{
		BuinessRpcBuinessSyncAsk v;

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
		BuinessRpcBuinessSyncAsk pb;
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
	void Init(const BuinessRpcBuinessSyncAsk& v)
	{

	}


};
//解锁回应封装类
class BuinessRpcBuinessUnlockReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessUnlockReplyWraper()
	{
		
		m_Result = -1;
		m_UnLockInfo = BuinessUnlockInfoWraper();

	}
	//赋值构造函数
	BuinessRpcBuinessUnlockReplyWraper(const BuinessRpcBuinessUnlockReply& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessUnlockReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessUnlockReply ToPB() const
	{
		BuinessRpcBuinessUnlockReply v;
		v.set_result( m_Result );
		v.mutable_changeskilldatas()->Reserve(m_ChangeSkillDatas.size());
		for (int i=0; i<(int)m_ChangeSkillDatas.size(); i++)
		{
			*v.add_changeskilldatas() = m_ChangeSkillDatas[i].ToPB();
		}
		*v.mutable_unlockinfo()= m_UnLockInfo.ToPB();

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
		BuinessRpcBuinessUnlockReply pb;
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
	void Init(const BuinessRpcBuinessUnlockReply& v)
	{
		m_Result = v.result();
		m_ChangeSkillDatas.clear();
		m_ChangeSkillDatas.reserve(v.changeskilldatas_size());
		for( int i=0; i<v.changeskilldatas_size(); i++)
			m_ChangeSkillDatas.push_back(v.changeskilldatas(i));
		m_UnLockInfo = v.unlockinfo();

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
	//改变的技能
	vector<BuinessSkillDataWraper> m_ChangeSkillDatas;
public:
	int SizeChangeSkillDatas()
	{
		return m_ChangeSkillDatas.size();
	}
	const vector<BuinessSkillDataWraper>& GetChangeSkillDatas() const
	{
		return m_ChangeSkillDatas;
	}
	BuinessSkillDataWraper GetChangeSkillDatas(int Index) const
	{
		if(Index<0 || Index>=(int)m_ChangeSkillDatas.size())
		{
			assert(false);
			return BuinessSkillDataWraper();
		}
		return m_ChangeSkillDatas[Index];
	}
	void SetChangeSkillDatas( const vector<BuinessSkillDataWraper>& v )
	{
		m_ChangeSkillDatas=v;
	}
	void ClearChangeSkillDatas( )
	{
		m_ChangeSkillDatas.clear();
	}
	void SetChangeSkillDatas( int Index, const BuinessSkillDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ChangeSkillDatas.size())
		{
			assert(false);
			return;
		}
		m_ChangeSkillDatas[Index] = v;
	}
	void AddChangeSkillDatas( const BuinessSkillDataWraper& v )
	{
		m_ChangeSkillDatas.push_back(v);
	}
private:
	//解锁信息
	BuinessUnlockInfoWraper m_UnLockInfo;
public:
	void SetUnLockInfo( const BuinessUnlockInfoWraper& v)
	{
		m_UnLockInfo=v;
	}
	BuinessUnlockInfoWraper GetUnLockInfo()
	{
		return m_UnLockInfo;
	}
	BuinessUnlockInfoWraper GetUnLockInfo() const
	{
		return m_UnLockInfo;
	}

};
//解锁请求封装类
class BuinessRpcBuinessUnlockAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	BuinessRpcBuinessUnlockAskWraper()
	{
		
		m_SkillID = -1;

	}
	//赋值构造函数
	BuinessRpcBuinessUnlockAskWraper(const BuinessRpcBuinessUnlockAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessRpcBuinessUnlockAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessRpcBuinessUnlockAsk ToPB() const
	{
		BuinessRpcBuinessUnlockAsk v;
		v.set_skillid( m_SkillID );

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
		BuinessRpcBuinessUnlockAsk pb;
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
	void Init(const BuinessRpcBuinessUnlockAsk& v)
	{
		m_SkillID = v.skillid();

	}

private:
	//要解锁的ID
	INT32 m_SkillID;
public:
	void SetSkillID( INT32 v)
	{
		m_SkillID=v;
	}
	INT32 GetSkillID()
	{
		return m_SkillID;
	}
	INT32 GetSkillID() const
	{
		return m_SkillID;
	}

};

template<typename T> struct MessageIdT;


#endif
