/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperWorldBoss.h
* Author:       甘业清
* Description:  世界BOSS模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_WORLDBOSS_H
#define __RPC_WRAPER_WORLDBOSS_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "WorldBossRpc.pb.h"



//世界BOSS模块类的枚举定义
enum ConstWorldBossE
{
	MODULE_ID_WORLDBOSS                          = 23,	//世界BOSS模块模块ID
	RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST     = 2351,	//世界BOSS模块-->世界BOSS信息-->请求
	RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST = 2352,	//世界BOSS模块-->世界BOSS排行榜信息-->请求


};


//世界BOSS伤害排行信息请求封装类
class WorldBossRpcWorldBossRankInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossRpcWorldBossRankInfoAskWraper()
	{
		
		m_BossID = -1;
		m_Occupation = -1;

	}
	//赋值构造函数
	WorldBossRpcWorldBossRankInfoAskWraper(const WorldBossRpcWorldBossRankInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRpcWorldBossRankInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRpcWorldBossRankInfoAsk ToPB() const
	{
		WorldBossRpcWorldBossRankInfoAsk v;
		v.set_bossid( m_BossID );
		v.set_occupation( m_Occupation );

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
		WorldBossRpcWorldBossRankInfoAsk pb;
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
	void Init(const WorldBossRpcWorldBossRankInfoAsk& v)
	{
		m_BossID = v.bossid();
		m_Occupation = v.occupation();

	}

private:
	//BossID
	INT32 m_BossID;
public:
	void SetBossID( INT32 v)
	{
		m_BossID=v;
	}
	INT32 GetBossID()
	{
		return m_BossID;
	}
	INT32 GetBossID() const
	{
		return m_BossID;
	}
private:
	//职业
	INT32 m_Occupation;
public:
	void SetOccupation( INT32 v)
	{
		m_Occupation=v;
	}
	INT32 GetOccupation()
	{
		return m_Occupation;
	}
	INT32 GetOccupation() const
	{
		return m_Occupation;
	}

};
//世界BOSS伤害排行信息回应封装类
class WorldBossRpcWorldBossRankInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossRpcWorldBossRankInfoReplyWraper()
	{
		
		m_Result = -1;
		m_LastKillName = "";
		m_MaxDamageName = "";
		m_MyRank = -1;
		m_Occupation = -1;
		m_BossID = -1;
		m_MyOccupationRank = -1;
		m_MyScore = -1;

	}
	//赋值构造函数
	WorldBossRpcWorldBossRankInfoReplyWraper(const WorldBossRpcWorldBossRankInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRpcWorldBossRankInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRpcWorldBossRankInfoReply ToPB() const
	{
		WorldBossRpcWorldBossRankInfoReply v;
		v.set_result( m_Result );
		v.mutable_rankinfo()->Reserve(m_RankInfo.size());
		for (int i=0; i<(int)m_RankInfo.size(); i++)
		{
			*v.add_rankinfo() = m_RankInfo[i].ToPB();
		}
		v.set_lastkillname( m_LastKillName );
		v.set_maxdamagename( m_MaxDamageName );
		v.set_myrank( m_MyRank );
		v.set_occupation( m_Occupation );
		v.set_bossid( m_BossID );
		v.set_myoccupationrank( m_MyOccupationRank );
		v.set_myscore( m_MyScore );

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
		WorldBossRpcWorldBossRankInfoReply pb;
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
	void Init(const WorldBossRpcWorldBossRankInfoReply& v)
	{
		m_Result = v.result();
		m_RankInfo.clear();
		m_RankInfo.reserve(v.rankinfo_size());
		for( int i=0; i<v.rankinfo_size(); i++)
			m_RankInfo.push_back(v.rankinfo(i));
		m_LastKillName = v.lastkillname();
		m_MaxDamageName = v.maxdamagename();
		m_MyRank = v.myrank();
		m_Occupation = v.occupation();
		m_BossID = v.bossid();
		m_MyOccupationRank = v.myoccupationrank();
		m_MyScore = v.myscore();

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
	//排行榜信息
	vector<WorldBossRankInfoWraper> m_RankInfo;
public:
	int SizeRankInfo()
	{
		return m_RankInfo.size();
	}
	const vector<WorldBossRankInfoWraper>& GetRankInfo() const
	{
		return m_RankInfo;
	}
	WorldBossRankInfoWraper GetRankInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankInfo.size())
		{
			assert(false);
			return WorldBossRankInfoWraper();
		}
		return m_RankInfo[Index];
	}
	void SetRankInfo( const vector<WorldBossRankInfoWraper>& v )
	{
		m_RankInfo=v;
	}
	void ClearRankInfo( )
	{
		m_RankInfo.clear();
	}
	void SetRankInfo( int Index, const WorldBossRankInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RankInfo.size())
		{
			assert(false);
			return;
		}
		m_RankInfo[Index] = v;
	}
	void AddRankInfo( const WorldBossRankInfoWraper& v )
	{
		m_RankInfo.push_back(v);
	}
private:
	//最后一击玩家名字
	string m_LastKillName;
public:
	void SetLastKillName( const string& v)
	{
		m_LastKillName=v;
	}
	string GetLastKillName()
	{
		return m_LastKillName;
	}
	string GetLastKillName() const
	{
		return m_LastKillName;
	}
private:
	//最大伤害玩家名字
	string m_MaxDamageName;
public:
	void SetMaxDamageName( const string& v)
	{
		m_MaxDamageName=v;
	}
	string GetMaxDamageName()
	{
		return m_MaxDamageName;
	}
	string GetMaxDamageName() const
	{
		return m_MaxDamageName;
	}
private:
	//个人排名
	INT32 m_MyRank;
public:
	void SetMyRank( INT32 v)
	{
		m_MyRank=v;
	}
	INT32 GetMyRank()
	{
		return m_MyRank;
	}
	INT32 GetMyRank() const
	{
		return m_MyRank;
	}
private:
	//职业
	INT32 m_Occupation;
public:
	void SetOccupation( INT32 v)
	{
		m_Occupation=v;
	}
	INT32 GetOccupation()
	{
		return m_Occupation;
	}
	INT32 GetOccupation() const
	{
		return m_Occupation;
	}
private:
	//BossID
	INT32 m_BossID;
public:
	void SetBossID( INT32 v)
	{
		m_BossID=v;
	}
	INT32 GetBossID()
	{
		return m_BossID;
	}
	INT32 GetBossID() const
	{
		return m_BossID;
	}
private:
	//个人职业排名
	INT32 m_MyOccupationRank;
public:
	void SetMyOccupationRank( INT32 v)
	{
		m_MyOccupationRank=v;
	}
	INT32 GetMyOccupationRank()
	{
		return m_MyOccupationRank;
	}
	INT32 GetMyOccupationRank() const
	{
		return m_MyOccupationRank;
	}
private:
	//个人积分
	INT32 m_MyScore;
public:
	void SetMyScore( INT32 v)
	{
		m_MyScore=v;
	}
	INT32 GetMyScore()
	{
		return m_MyScore;
	}
	INT32 GetMyScore() const
	{
		return m_MyScore;
	}

};
//世界BOSS信息请求封装类
class WorldBossRpcWorldBossInfoAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossRpcWorldBossInfoAskWraper()
	{
		
		m_BossID = -1;

	}
	//赋值构造函数
	WorldBossRpcWorldBossInfoAskWraper(const WorldBossRpcWorldBossInfoAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRpcWorldBossInfoAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRpcWorldBossInfoAsk ToPB() const
	{
		WorldBossRpcWorldBossInfoAsk v;
		v.set_bossid( m_BossID );

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
		WorldBossRpcWorldBossInfoAsk pb;
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
	void Init(const WorldBossRpcWorldBossInfoAsk& v)
	{
		m_BossID = v.bossid();

	}

private:
	//世界BOSSID
	INT32 m_BossID;
public:
	void SetBossID( INT32 v)
	{
		m_BossID=v;
	}
	INT32 GetBossID()
	{
		return m_BossID;
	}
	INT32 GetBossID() const
	{
		return m_BossID;
	}

};
//世界BOSS信息回应封装类
class WorldBossRpcWorldBossInfoReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	WorldBossRpcWorldBossInfoReplyWraper()
	{
		
		m_Result = -1;
		m_BossID = -1;

	}
	//赋值构造函数
	WorldBossRpcWorldBossInfoReplyWraper(const WorldBossRpcWorldBossInfoReply& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRpcWorldBossInfoReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRpcWorldBossInfoReply ToPB() const
	{
		WorldBossRpcWorldBossInfoReply v;
		v.set_result( m_Result );
		v.mutable_worldbossinfos()->Reserve(m_WorldBossInfos.size());
		for (int i=0; i<(int)m_WorldBossInfos.size(); i++)
		{
			*v.add_worldbossinfos() = m_WorldBossInfos[i].ToPB();
		}
		v.set_bossid( m_BossID );

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
		WorldBossRpcWorldBossInfoReply pb;
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
	void Init(const WorldBossRpcWorldBossInfoReply& v)
	{
		m_Result = v.result();
		m_WorldBossInfos.clear();
		m_WorldBossInfos.reserve(v.worldbossinfos_size());
		for( int i=0; i<v.worldbossinfos_size(); i++)
			m_WorldBossInfos.push_back(v.worldbossinfos(i));
		m_BossID = v.bossid();

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
	//世界BOSS信息
	vector<WorldBossInfoWraper> m_WorldBossInfos;
public:
	int SizeWorldBossInfos()
	{
		return m_WorldBossInfos.size();
	}
	const vector<WorldBossInfoWraper>& GetWorldBossInfos() const
	{
		return m_WorldBossInfos;
	}
	WorldBossInfoWraper GetWorldBossInfos(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossInfos.size())
		{
			assert(false);
			return WorldBossInfoWraper();
		}
		return m_WorldBossInfos[Index];
	}
	void SetWorldBossInfos( const vector<WorldBossInfoWraper>& v )
	{
		m_WorldBossInfos=v;
	}
	void ClearWorldBossInfos( )
	{
		m_WorldBossInfos.clear();
	}
	void SetWorldBossInfos( int Index, const WorldBossInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossInfos.size())
		{
			assert(false);
			return;
		}
		m_WorldBossInfos[Index] = v;
	}
	void AddWorldBossInfos( const WorldBossInfoWraper& v )
	{
		m_WorldBossInfos.push_back(v);
	}
private:
	//bossID
	INT32 m_BossID;
public:
	void SetBossID( INT32 v)
	{
		m_BossID=v;
	}
	INT32 GetBossID()
	{
		return m_BossID;
	}
	INT32 GetBossID() const
	{
		return m_BossID;
	}

};

template<typename T> struct MessageIdT;


#endif
