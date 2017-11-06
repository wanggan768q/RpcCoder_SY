/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     RpcWraperHuman.h
* Author:       郭晓波
* Description:  玩家模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_HUMAN_H
#define __RPC_WRAPER_HUMAN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "HumanRpc.pb.h"



//玩家模块类的枚举定义
enum ConstHumanE
{
	MODULE_ID_HUMAN                              = 4,	//玩家模块模块ID
	RPC_CODE_HUMAN_MOVE_REQUEST                  = 451,	//玩家模块-->human move-->请求
	RPC_CODE_HUMAN_STOPMOVE_REQUEST              = 452,	//玩家模块-->客户端停止移动-->请求
	RPC_CODE_HUMAN_MOVEMENTVERIFICATION_REQUEST  = 453,	//玩家模块-->移动验证-->请求
	RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY            = 454,	//玩家模块-->客户端位置校验-->通知
	RPC_CODE_HUMAN_GCMOVECHECK_NOTIFY            = 455,	//玩家模块-->服务器位置校验通知-->通知


};


//移动验证回应封装类
class HumanRpcMovementVerificationReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcMovementVerificationReplyWraper()
	{
		
		m_Result = -9999;
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcMovementVerificationReplyWraper(const HumanRpcMovementVerificationReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMovementVerificationReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMovementVerificationReply ToPB() const
	{
		HumanRpcMovementVerificationReply v;
		v.set_result( m_Result );
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcMovementVerificationReply pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcMovementVerificationReply& v)
	{
		m_Result = v.result();
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

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
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//移动验证请求封装类
class HumanRpcMovementVerificationAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcMovementVerificationAskWraper()
	{
		
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcMovementVerificationAskWraper(const HumanRpcMovementVerificationAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMovementVerificationAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMovementVerificationAsk ToPB() const
	{
		HumanRpcMovementVerificationAsk v;
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcMovementVerificationAsk pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcMovementVerificationAsk& v)
	{
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//服务器位置校验通知通知封装类
class HumanRpcGCMoveCheckNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcGCMoveCheckNotifyWraper()
	{
		
		m_Dir = -1;
		m_Pos = V3Wraper();

	}
	//赋值构造函数
	HumanRpcGCMoveCheckNotifyWraper(const HumanRpcGCMoveCheckNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcGCMoveCheckNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcGCMoveCheckNotify ToPB() const
	{
		HumanRpcGCMoveCheckNotify v;
		v.set_dir( m_Dir );
		*v.mutable_pos()= m_Pos.ToPB();

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
		HumanRpcGCMoveCheckNotify pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcGCMoveCheckNotify& v)
	{
		m_Dir = v.dir();
		m_Pos = v.pos();

	}

private:
	//方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}

};
//客户端位置校验通知封装类
class HumanRpcCGMoveCheckNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcCGMoveCheckNotifyWraper()
	{
		
		m_Dir = 0;
		m_Pos = V3Wraper();

	}
	//赋值构造函数
	HumanRpcCGMoveCheckNotifyWraper(const HumanRpcCGMoveCheckNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcCGMoveCheckNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcCGMoveCheckNotify ToPB() const
	{
		HumanRpcCGMoveCheckNotify v;
		v.set_dir( m_Dir );
		*v.mutable_pos()= m_Pos.ToPB();

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
		HumanRpcCGMoveCheckNotify pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcCGMoveCheckNotify& v)
	{
		m_Dir = v.dir();
		m_Pos = v.pos();

	}

private:
	//方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}

};
//human move回应封装类
class HumanRpcMoveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcMoveReplyWraper()
	{
		
		m_Result = -9999;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	HumanRpcMoveReplyWraper(const HumanRpcMoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveReply ToPB() const
	{
		HumanRpcMoveReply v;
		v.set_result( m_Result );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );

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
		HumanRpcMoveReply pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcMoveReply& v)
	{
		m_Result = v.result();
		m_Pos = v.pos();
		m_Dir = v.dir();

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
	//当前位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}

};
//human move请求封装类
class HumanRpcMoveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcMoveAskWraper()
	{
		
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcMoveAskWraper(const HumanRpcMoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcMoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcMoveAsk ToPB() const
	{
		HumanRpcMoveAsk v;
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcMoveAsk pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcMoveAsk& v)
	{
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//客户端停止移动回应封装类
class HumanRpcStopMoveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcStopMoveReplyWraper()
	{
		
		m_Result = -9999;
		m_Pos = V3Wraper();
		m_Dir = -1;

	}
	//赋值构造函数
	HumanRpcStopMoveReplyWraper(const HumanRpcStopMoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcStopMoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcStopMoveReply ToPB() const
	{
		HumanRpcStopMoveReply v;
		v.set_result( m_Result );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );

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
		HumanRpcStopMoveReply pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcStopMoveReply& v)
	{
		m_Result = v.result();
		m_Pos = v.pos();
		m_Dir = v.dir();

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
	//当前位置
	V3Wraper m_Pos;
public:
	void SetPos( const V3Wraper& v)
	{
		m_Pos=v;
	}
	V3Wraper GetPos()
	{
		return m_Pos;
	}
	V3Wraper GetPos() const
	{
		return m_Pos;
	}
private:
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}

};
//客户端停止移动请求封装类
class HumanRpcStopMoveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	HumanRpcStopMoveAskWraper()
	{
		
		m_Dir = -1;
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	HumanRpcStopMoveAskWraper(const HumanRpcStopMoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const HumanRpcStopMoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	HumanRpcStopMoveAsk ToPB() const
	{
		HumanRpcStopMoveAsk v;
		v.set_dir( m_Dir );
		v.set_x( m_X );
		v.set_z( m_Z );

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
		HumanRpcStopMoveAsk pb;
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
		tmpLine.Fmt("<li>Dir：%.2ff</li>\r\n",m_Dir);
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const HumanRpcStopMoveAsk& v)
	{
		m_Dir = v.dir();
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//移动方向
	float m_Dir;
public:
	void SetDir( float v)
	{
		m_Dir=v;
	}
	float GetDir()
	{
		return m_Dir;
	}
	float GetDir() const
	{
		return m_Dir;
	}
private:
	//CurPosX
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//CurPosZ
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<HumanRpcCGMoveCheckNotifyWraper>{ enum{ID=RPC_CODE_HUMAN_CGMOVECHECK_NOTIFY};};
template<> struct MessageIdT<HumanRpcGCMoveCheckNotifyWraper>{ enum{ID=RPC_CODE_HUMAN_GCMOVECHECK_NOTIFY};};


#endif
