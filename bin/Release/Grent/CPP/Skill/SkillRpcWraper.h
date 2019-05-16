/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperSkill.h
* Author:       甘业清
* Description:  技能模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SKILL_H
#define __RPC_WRAPER_SKILL_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "SkillRpc.pb.h"



//技能模块类的枚举定义
enum ConstSkillE
{
	MODULE_ID_SKILL                              = 21,	//技能模块模块ID
	RPC_CODE_SKILL_SKILLINFO_REQUEST             = 2151,	//技能模块-->技能信息-->请求
	RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST       = 2152,	//技能模块-->更新技能信息-->请求
	RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST       = 2153,	//技能模块-->技能栏位升级-->请求
	RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST        = 2154,	//技能模块-->技能栏位等级信息-->请求


};


//技能栏位升级回应封装类
class SkillRpcLevelUpSkillPosReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLevelUpSkillPosReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SkillRpcLevelUpSkillPosReplyWraper(const SkillRpcLevelUpSkillPosReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLevelUpSkillPosReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLevelUpSkillPosReply ToPB() const
	{
		SkillRpcLevelUpSkillPosReply v;
		v.set_result( m_Result );
		v.mutable_posinfo()->Reserve(m_PosInfo.size());
		for (int i=0; i<(int)m_PosInfo.size(); i++)
		{
			*v.add_posinfo() = m_PosInfo[i].ToPB();
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
		SkillRpcLevelUpSkillPosReply pb;
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
	void Init(const SkillRpcLevelUpSkillPosReply& v)
	{
		m_Result = v.result();
		m_PosInfo.clear();
		m_PosInfo.reserve(v.posinfo_size());
		for( int i=0; i<v.posinfo_size(); i++)
			m_PosInfo.push_back(v.posinfo(i));

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
	//技能位置信息
	vector<SkillPosInfoWraper> m_PosInfo;
public:
	int SizePosInfo()
	{
		return m_PosInfo.size();
	}
	const vector<SkillPosInfoWraper>& GetPosInfo() const
	{
		return m_PosInfo;
	}
	SkillPosInfoWraper GetPosInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_PosInfo.size())
		{
			assert(false);
			return SkillPosInfoWraper();
		}
		return m_PosInfo[Index];
	}
	void SetPosInfo( const vector<SkillPosInfoWraper>& v )
	{
		m_PosInfo=v;
	}
	void ClearPosInfo( )
	{
		m_PosInfo.clear();
	}
	void SetPosInfo( int Index, const SkillPosInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PosInfo.size())
		{
			assert(false);
			return;
		}
		m_PosInfo[Index] = v;
	}
	void AddPosInfo( const SkillPosInfoWraper& v )
	{
		m_PosInfo.push_back(v);
	}

};
//技能栏位升级请求封装类
class SkillRpcLevelUpSkillPosAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcLevelUpSkillPosAskWraper()
	{
		
		m_SkillPos = 0;
		m_IsAuto = false;

	}
	//赋值构造函数
	SkillRpcLevelUpSkillPosAskWraper(const SkillRpcLevelUpSkillPosAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcLevelUpSkillPosAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcLevelUpSkillPosAsk ToPB() const
	{
		SkillRpcLevelUpSkillPosAsk v;
		v.set_skillpos( m_SkillPos );
		v.set_isauto( m_IsAuto );

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
		SkillRpcLevelUpSkillPosAsk pb;
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
	void Init(const SkillRpcLevelUpSkillPosAsk& v)
	{
		m_SkillPos = v.skillpos();
		m_IsAuto = v.isauto();

	}

private:
	//技能栏位
	INT32 m_SkillPos;
public:
	void SetSkillPos( INT32 v)
	{
		m_SkillPos=v;
	}
	INT32 GetSkillPos()
	{
		return m_SkillPos;
	}
	INT32 GetSkillPos() const
	{
		return m_SkillPos;
	}
private:
	//是否一键升级
	bool m_IsAuto;
public:
	void SetIsAuto( bool v)
	{
		m_IsAuto=v;
	}
	bool GetIsAuto()
	{
		return m_IsAuto;
	}
	bool GetIsAuto() const
	{
		return m_IsAuto;
	}

};
//技能栏位等级信息回应封装类
class SkillRpcSkillLevelInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSkillLevelInfoReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	SkillRpcSkillLevelInfoReplyWraper(const SkillRpcSkillLevelInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSkillLevelInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSkillLevelInfoReply ToPB() const
	{
		SkillRpcSkillLevelInfoReply v;
		v.set_result( m_Result );
		v.mutable_posinfo()->Reserve(m_PosInfo.size());
		for (int i=0; i<(int)m_PosInfo.size(); i++)
		{
			*v.add_posinfo() = m_PosInfo[i].ToPB();
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
		SkillRpcSkillLevelInfoReply pb;
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
	void Init(const SkillRpcSkillLevelInfoReply& v)
	{
		m_Result = v.result();
		m_PosInfo.clear();
		m_PosInfo.reserve(v.posinfo_size());
		for( int i=0; i<v.posinfo_size(); i++)
			m_PosInfo.push_back(v.posinfo(i));

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
	//技能位置信息
	vector<SkillPosInfoWraper> m_PosInfo;
public:
	int SizePosInfo()
	{
		return m_PosInfo.size();
	}
	const vector<SkillPosInfoWraper>& GetPosInfo() const
	{
		return m_PosInfo;
	}
	SkillPosInfoWraper GetPosInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_PosInfo.size())
		{
			assert(false);
			return SkillPosInfoWraper();
		}
		return m_PosInfo[Index];
	}
	void SetPosInfo( const vector<SkillPosInfoWraper>& v )
	{
		m_PosInfo=v;
	}
	void ClearPosInfo( )
	{
		m_PosInfo.clear();
	}
	void SetPosInfo( int Index, const SkillPosInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PosInfo.size())
		{
			assert(false);
			return;
		}
		m_PosInfo[Index] = v;
	}
	void AddPosInfo( const SkillPosInfoWraper& v )
	{
		m_PosInfo.push_back(v);
	}

};
//技能栏位等级信息请求封装类
class SkillRpcSkillLevelInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSkillLevelInfoAskWraper()
	{
		

	}
	//赋值构造函数
	SkillRpcSkillLevelInfoAskWraper(const SkillRpcSkillLevelInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSkillLevelInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSkillLevelInfoAsk ToPB() const
	{
		SkillRpcSkillLevelInfoAsk v;

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
		SkillRpcSkillLevelInfoAsk pb;
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
	void Init(const SkillRpcSkillLevelInfoAsk& v)
	{

	}


};
//技能信息回应封装类
class SkillRpcSkillInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSkillInfoReplyWraper()
	{
		
		m_Result = -1;
		m_CurUseMastery = -1;

	}
	//赋值构造函数
	SkillRpcSkillInfoReplyWraper(const SkillRpcSkillInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSkillInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSkillInfoReply ToPB() const
	{
		SkillRpcSkillInfoReply v;
		v.set_result( m_Result );
		v.set_curusemastery( m_CurUseMastery );
		v.mutable_professioninfos()->Reserve(m_ProfessionInfos.size());
		for (int i=0; i<(int)m_ProfessionInfos.size(); i++)
		{
			*v.add_professioninfos() = m_ProfessionInfos[i].ToPB();
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
		SkillRpcSkillInfoReply pb;
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
	void Init(const SkillRpcSkillInfoReply& v)
	{
		m_Result = v.result();
		m_CurUseMastery = v.curusemastery();
		m_ProfessionInfos.clear();
		m_ProfessionInfos.reserve(v.professioninfos_size());
		for( int i=0; i<v.professioninfos_size(); i++)
			m_ProfessionInfos.push_back(v.professioninfos(i));

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
	//当前使用专精
	INT32 m_CurUseMastery;
public:
	void SetCurUseMastery( INT32 v)
	{
		m_CurUseMastery=v;
	}
	INT32 GetCurUseMastery()
	{
		return m_CurUseMastery;
	}
	INT32 GetCurUseMastery() const
	{
		return m_CurUseMastery;
	}
private:
	//技能信息
	vector<ProfessionInfoWraper> m_ProfessionInfos;
public:
	int SizeProfessionInfos()
	{
		return m_ProfessionInfos.size();
	}
	const vector<ProfessionInfoWraper>& GetProfessionInfos() const
	{
		return m_ProfessionInfos;
	}
	ProfessionInfoWraper GetProfessionInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return ProfessionInfoWraper();
		}
		return m_ProfessionInfos[Index];
	}
	void SetProfessionInfos( const vector<ProfessionInfoWraper>& v )
	{
		m_ProfessionInfos=v;
	}
	void ClearProfessionInfos( )
	{
		m_ProfessionInfos.clear();
	}
	void SetProfessionInfos( int Index, const ProfessionInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return;
		}
		m_ProfessionInfos[Index] = v;
	}
	void AddProfessionInfos( const ProfessionInfoWraper& v )
	{
		m_ProfessionInfos.push_back(v);
	}

};
//技能信息请求封装类
class SkillRpcSkillInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcSkillInfoAskWraper()
	{
		

	}
	//赋值构造函数
	SkillRpcSkillInfoAskWraper(const SkillRpcSkillInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcSkillInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcSkillInfoAsk ToPB() const
	{
		SkillRpcSkillInfoAsk v;

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
		SkillRpcSkillInfoAsk pb;
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
	void Init(const SkillRpcSkillInfoAsk& v)
	{

	}


};
//更新技能信息回应封装类
class SkillRpcUpdateSkillInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcUpdateSkillInfoReplyWraper()
	{
		
		m_Result = -1;
		m_CurUseMastery = -1;

	}
	//赋值构造函数
	SkillRpcUpdateSkillInfoReplyWraper(const SkillRpcUpdateSkillInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcUpdateSkillInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcUpdateSkillInfoReply ToPB() const
	{
		SkillRpcUpdateSkillInfoReply v;
		v.set_result( m_Result );
		v.set_curusemastery( m_CurUseMastery );
		v.mutable_professioninfos()->Reserve(m_ProfessionInfos.size());
		for (int i=0; i<(int)m_ProfessionInfos.size(); i++)
		{
			*v.add_professioninfos() = m_ProfessionInfos[i].ToPB();
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
		SkillRpcUpdateSkillInfoReply pb;
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
	void Init(const SkillRpcUpdateSkillInfoReply& v)
	{
		m_Result = v.result();
		m_CurUseMastery = v.curusemastery();
		m_ProfessionInfos.clear();
		m_ProfessionInfos.reserve(v.professioninfos_size());
		for( int i=0; i<v.professioninfos_size(); i++)
			m_ProfessionInfos.push_back(v.professioninfos(i));

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
	//当前使用的专精页
	INT32 m_CurUseMastery;
public:
	void SetCurUseMastery( INT32 v)
	{
		m_CurUseMastery=v;
	}
	INT32 GetCurUseMastery()
	{
		return m_CurUseMastery;
	}
	INT32 GetCurUseMastery() const
	{
		return m_CurUseMastery;
	}
private:
	//最新的技能信息
	vector<ProfessionInfoWraper> m_ProfessionInfos;
public:
	int SizeProfessionInfos()
	{
		return m_ProfessionInfos.size();
	}
	const vector<ProfessionInfoWraper>& GetProfessionInfos() const
	{
		return m_ProfessionInfos;
	}
	ProfessionInfoWraper GetProfessionInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return ProfessionInfoWraper();
		}
		return m_ProfessionInfos[Index];
	}
	void SetProfessionInfos( const vector<ProfessionInfoWraper>& v )
	{
		m_ProfessionInfos=v;
	}
	void ClearProfessionInfos( )
	{
		m_ProfessionInfos.clear();
	}
	void SetProfessionInfos( int Index, const ProfessionInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return;
		}
		m_ProfessionInfos[Index] = v;
	}
	void AddProfessionInfos( const ProfessionInfoWraper& v )
	{
		m_ProfessionInfos.push_back(v);
	}

};
//更新技能信息请求封装类
class SkillRpcUpdateSkillInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	SkillRpcUpdateSkillInfoAskWraper()
	{
		
		m_CurUseMastery = -1;

	}
	//赋值构造函数
	SkillRpcUpdateSkillInfoAskWraper(const SkillRpcUpdateSkillInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillRpcUpdateSkillInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillRpcUpdateSkillInfoAsk ToPB() const
	{
		SkillRpcUpdateSkillInfoAsk v;
		v.mutable_professioninfos()->Reserve(m_ProfessionInfos.size());
		for (int i=0; i<(int)m_ProfessionInfos.size(); i++)
		{
			*v.add_professioninfos() = m_ProfessionInfos[i].ToPB();
		}
		v.set_curusemastery( m_CurUseMastery );

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
		SkillRpcUpdateSkillInfoAsk pb;
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
	void Init(const SkillRpcUpdateSkillInfoAsk& v)
	{
		m_ProfessionInfos.clear();
		m_ProfessionInfos.reserve(v.professioninfos_size());
		for( int i=0; i<v.professioninfos_size(); i++)
			m_ProfessionInfos.push_back(v.professioninfos(i));
		m_CurUseMastery = v.curusemastery();

	}

private:
	//技能信息
	vector<ProfessionInfoWraper> m_ProfessionInfos;
public:
	int SizeProfessionInfos()
	{
		return m_ProfessionInfos.size();
	}
	const vector<ProfessionInfoWraper>& GetProfessionInfos() const
	{
		return m_ProfessionInfos;
	}
	ProfessionInfoWraper GetProfessionInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return ProfessionInfoWraper();
		}
		return m_ProfessionInfos[Index];
	}
	void SetProfessionInfos( const vector<ProfessionInfoWraper>& v )
	{
		m_ProfessionInfos=v;
	}
	void ClearProfessionInfos( )
	{
		m_ProfessionInfos.clear();
	}
	void SetProfessionInfos( int Index, const ProfessionInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ProfessionInfos.size())
		{
			assert(false);
			return;
		}
		m_ProfessionInfos[Index] = v;
	}
	void AddProfessionInfos( const ProfessionInfoWraper& v )
	{
		m_ProfessionInfos.push_back(v);
	}
private:
	//使用中的专精
	INT32 m_CurUseMastery;
public:
	void SetCurUseMastery( INT32 v)
	{
		m_CurUseMastery=v;
	}
	INT32 GetCurUseMastery()
	{
		return m_CurUseMastery;
	}
	INT32 GetCurUseMastery() const
	{
		return m_CurUseMastery;
	}

};

template<typename T> struct MessageIdT;


#endif
