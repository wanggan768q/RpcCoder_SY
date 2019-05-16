/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperLogin.h
* Author:       甘业清
* Description:  登录模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_LOGIN_H
#define __RPC_WRAPER_LOGIN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "LoginRpc.pb.h"



//登录模块类的枚举定义
enum ConstLoginE
{
	MODULE_ID_LOGIN                              = 2,	//登录模块模块ID
	RPC_CODE_LOGIN_LOGIN_REQUEST                 = 251,	//登录模块-->登录-->请求
	RPC_CODE_LOGIN_SELECTCHARACTER_REQUEST       = 252,	//登录模块-->选择角色-->请求
	RPC_CODE_LOGIN_CREATECHARACTER_REQUEST       = 253,	//登录模块-->创建角色-->请求
	RPC_CODE_LOGIN_DELETECHARACTER_REQUEST       = 254,	//登录模块-->删除角色-->请求
	RPC_CODE_LOGIN_TEST_REQUEST                  = 255,	//登录模块-->Test-->请求
	RPC_CODE_LOGIN_TEST1_REQUEST                 = 256,	//登录模块-->Test1-->请求
	RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY            = 257,	//登录模块-->登录 排队通知-->通知
	RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY         = 258,	//登录模块-->可以登录服务器的通知-->通知


};


//Test回应封装类
class LoginRpcTestReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcTestReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	LoginRpcTestReplyWraper(const LoginRpcTestReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcTestReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcTestReply ToPB() const
	{
		LoginRpcTestReply v;
		v.set_result( m_Result );
		v.mutable_a()->Reserve(m_A.size());
		for (int i=0; i<(int)m_A.size(); i++)
		{
			v.add_a(m_A[i]);
		}
		v.mutable_b()->Reserve(m_B.size());
		for (int i=0; i<(int)m_B.size(); i++)
		{
			v.add_b(m_B[i]);
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
		LoginRpcTestReply pb;
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
	void Init(const LoginRpcTestReply& v)
	{
		m_Result = v.result();
		m_A.clear();
		m_A.reserve(v.a_size());
		for( int i=0; i<v.a_size(); i++)
			m_A.push_back(v.a(i));
		m_B.clear();
		m_B.reserve(v.b_size());
		for( int i=0; i<v.b_size(); i++)
			m_B.push_back(v.b(i));

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
	//A
	vector<int64_t> m_A;
public:
	int SizeA()
	{
		return m_A.size();
	}
	const vector<int64_t>& GetA() const
	{
		return m_A;
	}
	int64_t GetA(int Index) const
	{
		if(Index<0 || Index>=(int)m_A.size())
		{
			assert(false);
			return int64_t();
		}
		return m_A[Index];
	}
	void SetA( const vector<int64_t>& v )
	{
		m_A=v;
	}
	void ClearA( )
	{
		m_A.clear();
	}
	void SetA( int Index, int64_t v )
	{
		if(Index<0 || Index>=(int)m_A.size())
		{
			assert(false);
			return;
		}
		m_A[Index] = v;
	}
	void AddA( int64_t v = -1 )
	{
		m_A.push_back(v);
	}
private:
	//B
	vector<uint64_t> m_B;
public:
	int SizeB()
	{
		return m_B.size();
	}
	const vector<uint64_t>& GetB() const
	{
		return m_B;
	}
	uint64_t GetB(int Index) const
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_B[Index];
	}
	void SetB( const vector<uint64_t>& v )
	{
		m_B=v;
	}
	void ClearB( )
	{
		m_B.clear();
	}
	void SetB( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return;
		}
		m_B[Index] = v;
	}
	void AddB( uint64_t v = 0 )
	{
		m_B.push_back(v);
	}

};
//Test请求封装类
class LoginRpcTestAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcTestAskWraper()
	{
		

	}
	//赋值构造函数
	LoginRpcTestAskWraper(const LoginRpcTestAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcTestAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcTestAsk ToPB() const
	{
		LoginRpcTestAsk v;
		v.mutable_a()->Reserve(m_A.size());
		for (int i=0; i<(int)m_A.size(); i++)
		{
			v.add_a(m_A[i]);
		}
		v.mutable_b()->Reserve(m_B.size());
		for (int i=0; i<(int)m_B.size(); i++)
		{
			v.add_b(m_B[i]);
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
		LoginRpcTestAsk pb;
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
	void Init(const LoginRpcTestAsk& v)
	{
		m_A.clear();
		m_A.reserve(v.a_size());
		for( int i=0; i<v.a_size(); i++)
			m_A.push_back(v.a(i));
		m_B.clear();
		m_B.reserve(v.b_size());
		for( int i=0; i<v.b_size(); i++)
			m_B.push_back(v.b(i));

	}

private:
	//A
	vector<int64_t> m_A;
public:
	int SizeA()
	{
		return m_A.size();
	}
	const vector<int64_t>& GetA() const
	{
		return m_A;
	}
	int64_t GetA(int Index) const
	{
		if(Index<0 || Index>=(int)m_A.size())
		{
			assert(false);
			return int64_t();
		}
		return m_A[Index];
	}
	void SetA( const vector<int64_t>& v )
	{
		m_A=v;
	}
	void ClearA( )
	{
		m_A.clear();
	}
	void SetA( int Index, int64_t v )
	{
		if(Index<0 || Index>=(int)m_A.size())
		{
			assert(false);
			return;
		}
		m_A[Index] = v;
	}
	void AddA( int64_t v = -1 )
	{
		m_A.push_back(v);
	}
private:
	//B
	vector<uint64_t> m_B;
public:
	int SizeB()
	{
		return m_B.size();
	}
	const vector<uint64_t>& GetB() const
	{
		return m_B;
	}
	uint64_t GetB(int Index) const
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_B[Index];
	}
	void SetB( const vector<uint64_t>& v )
	{
		m_B=v;
	}
	void ClearB( )
	{
		m_B.clear();
	}
	void SetB( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return;
		}
		m_B[Index] = v;
	}
	void AddB( uint64_t v = 0 )
	{
		m_B.push_back(v);
	}

};
//删除角色回应封装类
class LoginRpcDeleteCharacterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcDeleteCharacterReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	LoginRpcDeleteCharacterReplyWraper(const LoginRpcDeleteCharacterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcDeleteCharacterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcDeleteCharacterReply ToPB() const
	{
		LoginRpcDeleteCharacterReply v;
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
		LoginRpcDeleteCharacterReply pb;
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
	void Init(const LoginRpcDeleteCharacterReply& v)
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
//Test1请求封装类
class LoginRpcTest1AskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcTest1AskWraper()
	{
		

	}
	//赋值构造函数
	LoginRpcTest1AskWraper(const LoginRpcTest1Ask& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcTest1Ask& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcTest1Ask ToPB() const
	{
		LoginRpcTest1Ask v;
		v.mutable_b()->Reserve(m_B.size());
		for (int i=0; i<(int)m_B.size(); i++)
		{
			v.add_b(m_B[i]);
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
		LoginRpcTest1Ask pb;
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
	void Init(const LoginRpcTest1Ask& v)
	{
		m_B.clear();
		m_B.reserve(v.b_size());
		for( int i=0; i<v.b_size(); i++)
			m_B.push_back(v.b(i));

	}

private:
	//B
	vector<uint64_t> m_B;
public:
	int SizeB()
	{
		return m_B.size();
	}
	const vector<uint64_t>& GetB() const
	{
		return m_B;
	}
	uint64_t GetB(int Index) const
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_B[Index];
	}
	void SetB( const vector<uint64_t>& v )
	{
		m_B=v;
	}
	void ClearB( )
	{
		m_B.clear();
	}
	void SetB( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_B.size())
		{
			assert(false);
			return;
		}
		m_B[Index] = v;
	}
	void AddB( uint64_t v = 0 )
	{
		m_B.push_back(v);
	}

};
//可以登录服务器的通知通知封装类
class LoginRpcLoginEnterGameNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginEnterGameNotifyWraper()
	{
		
		m_RoleID = 0;
		m_LastSceneID = -1;
		m_LineID = -1;

	}
	//赋值构造函数
	LoginRpcLoginEnterGameNotifyWraper(const LoginRpcLoginEnterGameNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginEnterGameNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginEnterGameNotify ToPB() const
	{
		LoginRpcLoginEnterGameNotify v;
		v.set_roleid( m_RoleID );
		v.set_lastsceneid( m_LastSceneID );
		v.set_lineid( m_LineID );

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
		LoginRpcLoginEnterGameNotify pb;
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
	void Init(const LoginRpcLoginEnterGameNotify& v)
	{
		m_RoleID = v.roleid();
		m_LastSceneID = v.lastsceneid();
		m_LineID = v.lineid();

	}

private:
	//角色ID
	uint64_t m_RoleID;
public:
	void SetRoleID( uint64_t v)
	{
		m_RoleID=v;
	}
	uint64_t GetRoleID()
	{
		return m_RoleID;
	}
	uint64_t GetRoleID() const
	{
		return m_RoleID;
	}
private:
	//最后场景
	INT32 m_LastSceneID;
public:
	void SetLastSceneID( INT32 v)
	{
		m_LastSceneID=v;
	}
	INT32 GetLastSceneID()
	{
		return m_LastSceneID;
	}
	INT32 GetLastSceneID() const
	{
		return m_LastSceneID;
	}
private:
	//线
	INT32 m_LineID;
public:
	void SetLineID( INT32 v)
	{
		m_LineID=v;
	}
	INT32 GetLineID()
	{
		return m_LineID;
	}
	INT32 GetLineID() const
	{
		return m_LineID;
	}

};
//登录 排队通知通知封装类
class LoginRpcLoginLineUpNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginLineUpNotifyWraper()
	{
		
		m_LineUpIndex = -1;

	}
	//赋值构造函数
	LoginRpcLoginLineUpNotifyWraper(const LoginRpcLoginLineUpNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginLineUpNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginLineUpNotify ToPB() const
	{
		LoginRpcLoginLineUpNotify v;
		v.set_lineupindex( m_LineUpIndex );

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
		LoginRpcLoginLineUpNotify pb;
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
	void Init(const LoginRpcLoginLineUpNotify& v)
	{
		m_LineUpIndex = v.lineupindex();

	}

private:
	//排队索引
	INT32 m_LineUpIndex;
public:
	void SetLineUpIndex( INT32 v)
	{
		m_LineUpIndex=v;
	}
	INT32 GetLineUpIndex()
	{
		return m_LineUpIndex;
	}
	INT32 GetLineUpIndex() const
	{
		return m_LineUpIndex;
	}

};
//Test1回应封装类
class LoginRpcTest1ReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcTest1ReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	LoginRpcTest1ReplyWraper(const LoginRpcTest1Reply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcTest1Reply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcTest1Reply ToPB() const
	{
		LoginRpcTest1Reply v;
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
		LoginRpcTest1Reply pb;
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
	void Init(const LoginRpcTest1Reply& v)
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
//选择角色请求封装类
class LoginRpcSelectCharacterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcSelectCharacterAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	LoginRpcSelectCharacterAskWraper(const LoginRpcSelectCharacterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcSelectCharacterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcSelectCharacterAsk ToPB() const
	{
		LoginRpcSelectCharacterAsk v;
		v.set_roleid( m_RoleId );

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
		LoginRpcSelectCharacterAsk pb;
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
	void Init(const LoginRpcSelectCharacterAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//登录回应封装类
class LoginRpcLoginReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_Pos = Vector3Wraper();
		m_LastSelectRoleId = 0;

	}
	//赋值构造函数
	LoginRpcLoginReplyWraper(const LoginRpcLoginReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginReply ToPB() const
	{
		LoginRpcLoginReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.mutable_characterlist()->Reserve(m_CharacterList.size());
		for (int i=0; i<(int)m_CharacterList.size(); i++)
		{
			*v.add_characterlist() = m_CharacterList[i].ToPB();
		}
		v.set_lastselectroleid( m_LastSelectRoleId );

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
		LoginRpcLoginReply pb;
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
	void Init(const LoginRpcLoginReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_Pos = v.pos();
		m_CharacterList.clear();
		m_CharacterList.reserve(v.characterlist_size());
		for( int i=0; i<v.characterlist_size(); i++)
			m_CharacterList.push_back(v.characterlist(i));
		m_LastSelectRoleId = v.lastselectroleid();

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
	//用户ID
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//测试引用
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
	//所有角色信息
	vector<CharacterInfoWraper> m_CharacterList;
public:
	int SizeCharacterList()
	{
		return m_CharacterList.size();
	}
	const vector<CharacterInfoWraper>& GetCharacterList() const
	{
		return m_CharacterList;
	}
	CharacterInfoWraper GetCharacterList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CharacterList.size())
		{
			assert(false);
			return CharacterInfoWraper();
		}
		return m_CharacterList[Index];
	}
	void SetCharacterList( const vector<CharacterInfoWraper>& v )
	{
		m_CharacterList=v;
	}
	void ClearCharacterList( )
	{
		m_CharacterList.clear();
	}
	void SetCharacterList( int Index, const CharacterInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_CharacterList.size())
		{
			assert(false);
			return;
		}
		m_CharacterList[Index] = v;
	}
	void AddCharacterList( const CharacterInfoWraper& v )
	{
		m_CharacterList.push_back(v);
	}
private:
	//最后一次选择的角色ID
	uint64_t m_LastSelectRoleId;
public:
	void SetLastSelectRoleId( uint64_t v)
	{
		m_LastSelectRoleId=v;
	}
	uint64_t GetLastSelectRoleId()
	{
		return m_LastSelectRoleId;
	}
	uint64_t GetLastSelectRoleId() const
	{
		return m_LastSelectRoleId;
	}

};
//登录请求封装类
class LoginRpcLoginAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcLoginAskWraper()
	{
		
		m_Username = "";
		m_Passwd = "";
		m_SnId = "";
		m_GameId = "";
		m_Mac = "";
		m_Token = "";

	}
	//赋值构造函数
	LoginRpcLoginAskWraper(const LoginRpcLoginAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcLoginAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcLoginAsk ToPB() const
	{
		LoginRpcLoginAsk v;
		v.set_username( m_Username );
		v.set_passwd( m_Passwd );
		v.set_snid( m_SnId );
		v.set_gameid( m_GameId );
		v.set_mac( m_Mac );
		v.set_token( m_Token );

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
		LoginRpcLoginAsk pb;
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
	void Init(const LoginRpcLoginAsk& v)
	{
		m_Username = v.username();
		m_Passwd = v.passwd();
		m_SnId = v.snid();
		m_GameId = v.gameid();
		m_Mac = v.mac();
		m_Token = v.token();

	}

private:
	//用户名
	string m_Username;
public:
	void SetUsername( const string& v)
	{
		m_Username=v;
	}
	string GetUsername()
	{
		return m_Username;
	}
	string GetUsername() const
	{
		return m_Username;
	}
private:
	//密码
	string m_Passwd;
public:
	void SetPasswd( const string& v)
	{
		m_Passwd=v;
	}
	string GetPasswd()
	{
		return m_Passwd;
	}
	string GetPasswd() const
	{
		return m_Passwd;
	}
private:
	//渠道号
	string m_SnId;
public:
	void SetSnId( const string& v)
	{
		m_SnId=v;
	}
	string GetSnId()
	{
		return m_SnId;
	}
	string GetSnId() const
	{
		return m_SnId;
	}
private:
	//GameId
	string m_GameId;
public:
	void SetGameId( const string& v)
	{
		m_GameId=v;
	}
	string GetGameId()
	{
		return m_GameId;
	}
	string GetGameId() const
	{
		return m_GameId;
	}
private:
	//mac地址
	string m_Mac;
public:
	void SetMac( const string& v)
	{
		m_Mac=v;
	}
	string GetMac()
	{
		return m_Mac;
	}
	string GetMac() const
	{
		return m_Mac;
	}
private:
	//Token
	string m_Token;
public:
	void SetToken( const string& v)
	{
		m_Token=v;
	}
	string GetToken()
	{
		return m_Token;
	}
	string GetToken() const
	{
		return m_Token;
	}

};
//选择角色回应封装类
class LoginRpcSelectCharacterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcSelectCharacterReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_LastSceneID = -1;
		m_Ban_Reason = "";
		m_LineId = -1;
		m_Ban_EndTime = -1;

	}
	//赋值构造函数
	LoginRpcSelectCharacterReplyWraper(const LoginRpcSelectCharacterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcSelectCharacterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcSelectCharacterReply ToPB() const
	{
		LoginRpcSelectCharacterReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_lastsceneid( m_LastSceneID );
		v.set_ban_reason( m_Ban_Reason );
		v.set_lineid( m_LineId );
		v.set_ban_endtime( m_Ban_EndTime );

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
		LoginRpcSelectCharacterReply pb;
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
	void Init(const LoginRpcSelectCharacterReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_LastSceneID = v.lastsceneid();
		m_Ban_Reason = v.ban_reason();
		m_LineId = v.lineid();
		m_Ban_EndTime = v.ban_endtime();

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
	//id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//LastSceneID
	INT32 m_LastSceneID;
public:
	void SetLastSceneID( INT32 v)
	{
		m_LastSceneID=v;
	}
	INT32 GetLastSceneID()
	{
		return m_LastSceneID;
	}
	INT32 GetLastSceneID() const
	{
		return m_LastSceneID;
	}
private:
	//禁止理由
	string m_Ban_Reason;
public:
	void SetBan_Reason( const string& v)
	{
		m_Ban_Reason=v;
	}
	string GetBan_Reason()
	{
		return m_Ban_Reason;
	}
	string GetBan_Reason() const
	{
		return m_Ban_Reason;
	}
private:
	//线id
	INT32 m_LineId;
public:
	void SetLineId( INT32 v)
	{
		m_LineId=v;
	}
	INT32 GetLineId()
	{
		return m_LineId;
	}
	INT32 GetLineId() const
	{
		return m_LineId;
	}
private:
	//解封时间戳
	INT32 m_Ban_EndTime;
public:
	void SetBan_EndTime( INT32 v)
	{
		m_Ban_EndTime=v;
	}
	INT32 GetBan_EndTime()
	{
		return m_Ban_EndTime;
	}
	INT32 GetBan_EndTime() const
	{
		return m_Ban_EndTime;
	}

};
//删除角色请求封装类
class LoginRpcDeleteCharacterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcDeleteCharacterAskWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	LoginRpcDeleteCharacterAskWraper(const LoginRpcDeleteCharacterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcDeleteCharacterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcDeleteCharacterAsk ToPB() const
	{
		LoginRpcDeleteCharacterAsk v;
		v.set_roleid( m_RoleId );

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
		LoginRpcDeleteCharacterAsk pb;
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
	void Init(const LoginRpcDeleteCharacterAsk& v)
	{
		m_RoleId = v.roleid();

	}

private:
	//id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}

};
//创建角色回应封装类
class LoginRpcCreateCharacterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCreateCharacterReplyWraper()
	{
		
		m_Result = -9999;
		m_RoleId = 0;
		m_TimeStamp = 0;

	}
	//赋值构造函数
	LoginRpcCreateCharacterReplyWraper(const LoginRpcCreateCharacterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCreateCharacterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCreateCharacterReply ToPB() const
	{
		LoginRpcCreateCharacterReply v;
		v.set_result( m_Result );
		v.set_roleid( m_RoleId );
		v.set_timestamp( m_TimeStamp );

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
		LoginRpcCreateCharacterReply pb;
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
	void Init(const LoginRpcCreateCharacterReply& v)
	{
		m_Result = v.result();
		m_RoleId = v.roleid();
		m_TimeStamp = v.timestamp();

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
	//角色id
	uint64_t m_RoleId;
public:
	void SetRoleId( uint64_t v)
	{
		m_RoleId=v;
	}
	uint64_t GetRoleId()
	{
		return m_RoleId;
	}
	uint64_t GetRoleId() const
	{
		return m_RoleId;
	}
private:
	//创建角色时间
	INT32 m_TimeStamp;
public:
	void SetTimeStamp( INT32 v)
	{
		m_TimeStamp=v;
	}
	INT32 GetTimeStamp()
	{
		return m_TimeStamp;
	}
	INT32 GetTimeStamp() const
	{
		return m_TimeStamp;
	}

};
//创建角色请求封装类
class LoginRpcCreateCharacterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcCreateCharacterAskWraper()
	{
		
		m_Nickname = "";
		m_ConfigId = -1;

	}
	//赋值构造函数
	LoginRpcCreateCharacterAskWraper(const LoginRpcCreateCharacterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcCreateCharacterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcCreateCharacterAsk ToPB() const
	{
		LoginRpcCreateCharacterAsk v;
		v.set_nickname( m_Nickname );
		v.set_configid( m_ConfigId );

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
		LoginRpcCreateCharacterAsk pb;
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
	void Init(const LoginRpcCreateCharacterAsk& v)
	{
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();

	}

private:
	//昵称
	string m_Nickname;
public:
	void SetNickname( const string& v)
	{
		m_Nickname=v;
	}
	string GetNickname()
	{
		return m_Nickname;
	}
	string GetNickname() const
	{
		return m_Nickname;
	}
private:
	//配置表id
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<LoginRpcLoginLineUpNotifyWraper>{ enum{ID=RPC_CODE_LOGIN_LOGINLINEUP_NOTIFY};};
template<> struct MessageIdT<LoginRpcLoginEnterGameNotifyWraper>{ enum{ID=RPC_CODE_LOGIN_LOGINENTERGAME_NOTIFY};};


#endif
