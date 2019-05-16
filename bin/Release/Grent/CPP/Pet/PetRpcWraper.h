/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperPet.h
* Author:       甘业清
* Description:  宠物模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_PET_H
#define __RPC_WRAPER_PET_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "PetRpc.pb.h"



//宠物模块类的枚举定义
enum ConstPetE
{
	MODULE_ID_PET                                = 31,	//宠物模块模块ID
	RPC_CODE_PET_PETSYNC_REQUEST                 = 3151,	//宠物模块-->同步-->请求
	RPC_CODE_PET_UNSUMMON_REQUEST                = 3152,	//宠物模块-->召回-->请求
	RPC_CODE_PET_LEVELUPGRADE_REQUEST            = 3153,	//宠物模块-->升级-->请求
	RPC_CODE_PET_STARUPGRADE_REQUEST             = 3154,	//宠物模块-->升星-->请求
	RPC_CODE_PET_CHANGENAME_REQUEST              = 3155,	//宠物模块-->改名-->请求
	RPC_CODE_PET_INHERIT_REQUEST                 = 3156,	//宠物模块-->传承-->请求
	RPC_CODE_PET_SKILLINHERIT_REQUEST            = 3157,	//宠物模块-->技能继承-->请求
	RPC_CODE_PET_PASSIVESKILLS_REQUEST           = 3158,	//宠物模块-->宠物被动技能列表-->请求
	RPC_CODE_PET_STUDYSKILL_REQUEST              = 3159,	//宠物模块-->学习被动技能-->请求
	RPC_CODE_PET_LOCKSKILL_REQUEST               = 3160,	//宠物模块-->锁定技能-->请求
	RPC_CODE_PET_UNLOCKSKILL_REQUEST             = 3161,	//宠物模块-->解除技能锁定-->请求


};


//宠物被动技能列表请求封装类
class PetRpcPassiveSkillsAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcPassiveSkillsAskWraper()
	{
		
		m_Guid = 0;

	}
	//赋值构造函数
	PetRpcPassiveSkillsAskWraper(const PetRpcPassiveSkillsAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcPassiveSkillsAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcPassiveSkillsAsk ToPB() const
	{
		PetRpcPassiveSkillsAsk v;
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
		PetRpcPassiveSkillsAsk pb;
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
	void Init(const PetRpcPassiveSkillsAsk& v)
	{
		m_Guid = v.guid();

	}

private:
	//宠物唯一id
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
//宠物被动技能列表回应封装类
class PetRpcPassiveSkillsReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcPassiveSkillsReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PetRpcPassiveSkillsReplyWraper(const PetRpcPassiveSkillsReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcPassiveSkillsReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcPassiveSkillsReply ToPB() const
	{
		PetRpcPassiveSkillsReply v;
		v.set_result( m_Result );
		v.mutable_skills()->Reserve(m_Skills.size());
		for (int i=0; i<(int)m_Skills.size(); i++)
		{
			*v.add_skills() = m_Skills[i].ToPB();
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
		PetRpcPassiveSkillsReply pb;
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
	void Init(const PetRpcPassiveSkillsReply& v)
	{
		m_Result = v.result();
		m_Skills.clear();
		m_Skills.reserve(v.skills_size());
		for( int i=0; i<v.skills_size(); i++)
			m_Skills.push_back(v.skills(i));

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
	//宠物被动技能列表
	vector<PetSkillWraper> m_Skills;
public:
	int SizeSkills()
	{
		return m_Skills.size();
	}
	const vector<PetSkillWraper>& GetSkills() const
	{
		return m_Skills;
	}
	PetSkillWraper GetSkills(int Index) const
	{
		if(Index<0 || Index>=(int)m_Skills.size())
		{
			assert(false);
			return PetSkillWraper();
		}
		return m_Skills[Index];
	}
	void SetSkills( const vector<PetSkillWraper>& v )
	{
		m_Skills=v;
	}
	void ClearSkills( )
	{
		m_Skills.clear();
	}
	void SetSkills( int Index, const PetSkillWraper& v )
	{
		if(Index<0 || Index>=(int)m_Skills.size())
		{
			assert(false);
			return;
		}
		m_Skills[Index] = v;
	}
	void AddSkills( const PetSkillWraper& v )
	{
		m_Skills.push_back(v);
	}

};
//技能继承回应封装类
class PetRpcSkillInheritReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcSkillInheritReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcSkillInheritReplyWraper(const PetRpcSkillInheritReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcSkillInheritReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcSkillInheritReply ToPB() const
	{
		PetRpcSkillInheritReply v;
		v.set_result( m_Result );
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
		PetRpcSkillInheritReply pb;
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
	void Init(const PetRpcSkillInheritReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//传承回应封装类
class PetRpcInheritReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcInheritReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcInheritReplyWraper(const PetRpcInheritReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcInheritReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcInheritReply ToPB() const
	{
		PetRpcInheritReply v;
		v.set_result( m_Result );
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
		PetRpcInheritReply pb;
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
	void Init(const PetRpcInheritReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//技能继承请求封装类
class PetRpcSkillInheritAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcSkillInheritAskWraper()
	{
		
		m_Guid = 0;
		m_UseGuid = 0;

	}
	//赋值构造函数
	PetRpcSkillInheritAskWraper(const PetRpcSkillInheritAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcSkillInheritAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcSkillInheritAsk ToPB() const
	{
		PetRpcSkillInheritAsk v;
		v.set_guid( m_Guid );
		v.set_useguid( m_UseGuid );

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
		PetRpcSkillInheritAsk pb;
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
	void Init(const PetRpcSkillInheritAsk& v)
	{
		m_Guid = v.guid();
		m_UseGuid = v.useguid();

	}

private:
	//要操作的道具GUid
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
private:
	//使用道具的GUid
	uint64_t m_UseGuid;
public:
	void SetUseGuid( uint64_t v)
	{
		m_UseGuid=v;
	}
	uint64_t GetUseGuid()
	{
		return m_UseGuid;
	}
	uint64_t GetUseGuid() const
	{
		return m_UseGuid;
	}

};
//学习被动技能请求封装类
class PetRpcStudySkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcStudySkillAskWraper()
	{
		
		m_Guid = 0;
		m_ItemId = -1;

	}
	//赋值构造函数
	PetRpcStudySkillAskWraper(const PetRpcStudySkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcStudySkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcStudySkillAsk ToPB() const
	{
		PetRpcStudySkillAsk v;
		v.set_guid( m_Guid );
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
		PetRpcStudySkillAsk pb;
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
	void Init(const PetRpcStudySkillAsk& v)
	{
		m_Guid = v.guid();
		m_ItemId = v.itemid();

	}

private:
	//物品唯一id
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

};
//解除技能锁定请求封装类
class PetRpcUnLockSkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcUnLockSkillAskWraper()
	{
		
		m_Guid = 0;
		m_SkillId = -1;

	}
	//赋值构造函数
	PetRpcUnLockSkillAskWraper(const PetRpcUnLockSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcUnLockSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcUnLockSkillAsk ToPB() const
	{
		PetRpcUnLockSkillAsk v;
		v.set_guid( m_Guid );
		v.set_skillid( m_SkillId );

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
		PetRpcUnLockSkillAsk pb;
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
	void Init(const PetRpcUnLockSkillAsk& v)
	{
		m_Guid = v.guid();
		m_SkillId = v.skillid();

	}

private:
	//物品唯一id
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
private:
	//技能唯一id
	INT32 m_SkillId;
public:
	void SetSkillId( INT32 v)
	{
		m_SkillId=v;
	}
	INT32 GetSkillId()
	{
		return m_SkillId;
	}
	INT32 GetSkillId() const
	{
		return m_SkillId;
	}

};
//解除技能锁定回应封装类
class PetRpcUnLockSkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcUnLockSkillReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcUnLockSkillReplyWraper(const PetRpcUnLockSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcUnLockSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcUnLockSkillReply ToPB() const
	{
		PetRpcUnLockSkillReply v;
		v.set_result( m_Result );
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
		PetRpcUnLockSkillReply pb;
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
	void Init(const PetRpcUnLockSkillReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//锁住技能回应封装类
class PetRpcLockSkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcLockSkillReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcLockSkillReplyWraper(const PetRpcLockSkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcLockSkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcLockSkillReply ToPB() const
	{
		PetRpcLockSkillReply v;
		v.set_result( m_Result );
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
		PetRpcLockSkillReply pb;
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
	void Init(const PetRpcLockSkillReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//学习被动技能回应封装类
class PetRpcStudySkillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcStudySkillReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();
		m_ReplacedSkillId = -1;
		m_Index = -1;

	}
	//赋值构造函数
	PetRpcStudySkillReplyWraper(const PetRpcStudySkillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcStudySkillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcStudySkillReply ToPB() const
	{
		PetRpcStudySkillReply v;
		v.set_result( m_Result );
		*v.mutable_itemdata()= m_ItemData.ToPB();
		v.set_replacedskillid( m_ReplacedSkillId );
		v.set_index( m_Index );

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
		PetRpcStudySkillReply pb;
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
	void Init(const PetRpcStudySkillReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();
		m_ReplacedSkillId = v.replacedskillid();
		m_Index = v.index();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}
private:
	//替换掉的技能id
	INT32 m_ReplacedSkillId;
public:
	void SetReplacedSkillId( INT32 v)
	{
		m_ReplacedSkillId=v;
	}
	INT32 GetReplacedSkillId()
	{
		return m_ReplacedSkillId;
	}
	INT32 GetReplacedSkillId() const
	{
		return m_ReplacedSkillId;
	}
private:
	//学习技能id
	INT32 m_Index;
public:
	void SetIndex( INT32 v)
	{
		m_Index=v;
	}
	INT32 GetIndex()
	{
		return m_Index;
	}
	INT32 GetIndex() const
	{
		return m_Index;
	}

};
//锁住技能请求封装类
class PetRpcLockSkillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcLockSkillAskWraper()
	{
		
		m_Guid = 0;
		m_SkillId = -1;

	}
	//赋值构造函数
	PetRpcLockSkillAskWraper(const PetRpcLockSkillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcLockSkillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcLockSkillAsk ToPB() const
	{
		PetRpcLockSkillAsk v;
		v.set_guid( m_Guid );
		v.set_skillid( m_SkillId );

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
		PetRpcLockSkillAsk pb;
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
	void Init(const PetRpcLockSkillAsk& v)
	{
		m_Guid = v.guid();
		m_SkillId = v.skillid();

	}

private:
	//物品唯一id
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
private:
	//锁住的技能id
	INT32 m_SkillId;
public:
	void SetSkillId( INT32 v)
	{
		m_SkillId=v;
	}
	INT32 GetSkillId()
	{
		return m_SkillId;
	}
	INT32 GetSkillId() const
	{
		return m_SkillId;
	}

};
//召回回应封装类
class PetRpcUnSummonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcUnSummonReplyWraper()
	{
		
		m_Result = -1;
		m_ItemObj = ItemObjWraper();

	}
	//赋值构造函数
	PetRpcUnSummonReplyWraper(const PetRpcUnSummonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcUnSummonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcUnSummonReply ToPB() const
	{
		PetRpcUnSummonReply v;
		v.set_result( m_Result );
		*v.mutable_itemobj()= m_ItemObj.ToPB();

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
		PetRpcUnSummonReply pb;
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
	void Init(const PetRpcUnSummonReply& v)
	{
		m_Result = v.result();
		m_ItemObj = v.itemobj();

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
	//ItemObj
	ItemObjWraper m_ItemObj;
public:
	void SetItemObj( const ItemObjWraper& v)
	{
		m_ItemObj=v;
	}
	ItemObjWraper GetItemObj()
	{
		return m_ItemObj;
	}
	ItemObjWraper GetItemObj() const
	{
		return m_ItemObj;
	}

};
//升级请求封装类
class PetRpcLevelUpgradeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcLevelUpgradeAskWraper()
	{
		
		m_Guid = 0;

	}
	//赋值构造函数
	PetRpcLevelUpgradeAskWraper(const PetRpcLevelUpgradeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcLevelUpgradeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcLevelUpgradeAsk ToPB() const
	{
		PetRpcLevelUpgradeAsk v;
		v.set_guid( m_Guid );
		v.mutable_itemcount()->Reserve(m_ItemCount.size());
		for (int i=0; i<(int)m_ItemCount.size(); i++)
		{
			v.add_itemcount(m_ItemCount[i]);
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
		PetRpcLevelUpgradeAsk pb;
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
	void Init(const PetRpcLevelUpgradeAsk& v)
	{
		m_Guid = v.guid();
		m_ItemCount.clear();
		m_ItemCount.reserve(v.itemcount_size());
		for( int i=0; i<v.itemcount_size(); i++)
			m_ItemCount.push_back(v.itemcount(i));

	}

private:
	//Guid
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
private:
	//各类型道具数量
	vector<INT32> m_ItemCount;
public:
	int SizeItemCount()
	{
		return m_ItemCount.size();
	}
	const vector<INT32>& GetItemCount() const
	{
		return m_ItemCount;
	}
	INT32 GetItemCount(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemCount.size())
		{
			assert(false);
			return INT32();
		}
		return m_ItemCount[Index];
	}
	void SetItemCount( const vector<INT32>& v )
	{
		m_ItemCount=v;
	}
	void ClearItemCount( )
	{
		m_ItemCount.clear();
	}
	void SetItemCount( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ItemCount.size())
		{
			assert(false);
			return;
		}
		m_ItemCount[Index] = v;
	}
	void AddItemCount( INT32 v = -1 )
	{
		m_ItemCount.push_back(v);
	}

};
//召回请求封装类
class PetRpcUnSummonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcUnSummonAskWraper()
	{
		

	}
	//赋值构造函数
	PetRpcUnSummonAskWraper(const PetRpcUnSummonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcUnSummonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcUnSummonAsk ToPB() const
	{
		PetRpcUnSummonAsk v;

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
		PetRpcUnSummonAsk pb;
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
	void Init(const PetRpcUnSummonAsk& v)
	{

	}


};
//同步请求封装类
class PetRpcPetSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcPetSyncAskWraper()
	{
		

	}
	//赋值构造函数
	PetRpcPetSyncAskWraper(const PetRpcPetSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcPetSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcPetSyncAsk ToPB() const
	{
		PetRpcPetSyncAsk v;

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
		PetRpcPetSyncAsk pb;
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
	void Init(const PetRpcPetSyncAsk& v)
	{

	}


};
//同步回应封装类
class PetRpcPetSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcPetSyncReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcPetSyncReplyWraper(const PetRpcPetSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcPetSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcPetSyncReply ToPB() const
	{
		PetRpcPetSyncReply v;
		v.set_result( m_Result );
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
		PetRpcPetSyncReply pb;
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
	void Init(const PetRpcPetSyncReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//宠物数据
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//升级回应封装类
class PetRpcLevelUpgradeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcLevelUpgradeReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcLevelUpgradeReplyWraper(const PetRpcLevelUpgradeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcLevelUpgradeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcLevelUpgradeReply ToPB() const
	{
		PetRpcLevelUpgradeReply v;
		v.set_result( m_Result );
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
		PetRpcLevelUpgradeReply pb;
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
	void Init(const PetRpcLevelUpgradeReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具属性
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};
//改名回应封装类
class PetRpcChangeNameReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcChangeNameReplyWraper()
	{
		
		m_Result = -1;
		m_Name = "";

	}
	//赋值构造函数
	PetRpcChangeNameReplyWraper(const PetRpcChangeNameReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcChangeNameReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcChangeNameReply ToPB() const
	{
		PetRpcChangeNameReply v;
		v.set_result( m_Result );
		v.set_name( m_Name );

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
		PetRpcChangeNameReply pb;
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
	void Init(const PetRpcChangeNameReply& v)
	{
		m_Result = v.result();
		m_Name = v.name();

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
	//名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}

};
//传承请求封装类
class PetRpcInheritAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcInheritAskWraper()
	{
		
		m_Guid = 0;
		m_UseGuid = 0;

	}
	//赋值构造函数
	PetRpcInheritAskWraper(const PetRpcInheritAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcInheritAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcInheritAsk ToPB() const
	{
		PetRpcInheritAsk v;
		v.set_guid( m_Guid );
		v.set_useguid( m_UseGuid );

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
		PetRpcInheritAsk pb;
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
	void Init(const PetRpcInheritAsk& v)
	{
		m_Guid = v.guid();
		m_UseGuid = v.useguid();

	}

private:
	//要操作的道具GUid
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
private:
	//使用道具的GUid
	uint64_t m_UseGuid;
public:
	void SetUseGuid( uint64_t v)
	{
		m_UseGuid=v;
	}
	uint64_t GetUseGuid()
	{
		return m_UseGuid;
	}
	uint64_t GetUseGuid() const
	{
		return m_UseGuid;
	}

};
//改名请求封装类
class PetRpcChangeNameAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcChangeNameAskWraper()
	{
		
		m_Guid = 0;
		m_NewName = "";

	}
	//赋值构造函数
	PetRpcChangeNameAskWraper(const PetRpcChangeNameAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcChangeNameAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcChangeNameAsk ToPB() const
	{
		PetRpcChangeNameAsk v;
		v.set_guid( m_Guid );
		v.set_newname( m_NewName );

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
		PetRpcChangeNameAsk pb;
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
	void Init(const PetRpcChangeNameAsk& v)
	{
		m_Guid = v.guid();
		m_NewName = v.newname();

	}

private:
	//GUID
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
private:
	//新名字
	string m_NewName;
public:
	void SetNewName( const string& v)
	{
		m_NewName=v;
	}
	string GetNewName()
	{
		return m_NewName;
	}
	string GetNewName() const
	{
		return m_NewName;
	}

};
//升星请求封装类
class PetRpcStarUpgradeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcStarUpgradeAskWraper()
	{
		
		m_Guid = 0;
		m_UseGuid = 0;

	}
	//赋值构造函数
	PetRpcStarUpgradeAskWraper(const PetRpcStarUpgradeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcStarUpgradeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcStarUpgradeAsk ToPB() const
	{
		PetRpcStarUpgradeAsk v;
		v.set_guid( m_Guid );
		v.set_useguid( m_UseGuid );

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
		PetRpcStarUpgradeAsk pb;
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
	void Init(const PetRpcStarUpgradeAsk& v)
	{
		m_Guid = v.guid();
		m_UseGuid = v.useguid();

	}

private:
	//Guid
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
private:
	//使用素材的GUID
	uint64_t m_UseGuid;
public:
	void SetUseGuid( uint64_t v)
	{
		m_UseGuid=v;
	}
	uint64_t GetUseGuid()
	{
		return m_UseGuid;
	}
	uint64_t GetUseGuid() const
	{
		return m_UseGuid;
	}

};
//升星回应封装类
class PetRpcStarUpgradeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PetRpcStarUpgradeReplyWraper()
	{
		
		m_Result = -1;
		m_ItemData = ItemDataWraper();

	}
	//赋值构造函数
	PetRpcStarUpgradeReplyWraper(const PetRpcStarUpgradeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PetRpcStarUpgradeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetRpcStarUpgradeReply ToPB() const
	{
		PetRpcStarUpgradeReply v;
		v.set_result( m_Result );
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
		PetRpcStarUpgradeReply pb;
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
	void Init(const PetRpcStarUpgradeReply& v)
	{
		m_Result = v.result();
		m_ItemData = v.itemdata();

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
	//道具数据
	ItemDataWraper m_ItemData;
public:
	void SetItemData( const ItemDataWraper& v)
	{
		m_ItemData=v;
	}
	ItemDataWraper GetItemData()
	{
		return m_ItemData;
	}
	ItemDataWraper GetItemData() const
	{
		return m_ItemData;
	}

};

template<typename T> struct MessageIdT;


#endif
