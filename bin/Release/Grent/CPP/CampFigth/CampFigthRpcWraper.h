/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperCampFigth.h
* Author:       甘业清
* Description:  CampFigthRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CAMPFIGTH_H
#define __RPC_WRAPER_CAMPFIGTH_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "CampFigthRpc.pb.h"



//CampFigth类的枚举定义
enum ConstCampFigthE
{
	MODULE_ID_CAMPFIGTH                          = 26,	//CampFigth模块ID
	RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST    = 2651,	//CampFigth-->MilitaryBroken-->请求
	RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY= 2652,	//CampFigth-->CampFightContribution-->通知
	RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY   = 2653,	//CampFigth-->ObjKillBroadcast-->通知
	RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY           = 2654,	//CampFigth-->NpcBirth-->通知
	RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST  = 2655,	//CampFigth-->GetMilitaryValue-->请求
	RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY       = 2656,	//CampFigth-->KillDeadInfo-->通知
	RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST           = 2657,	//CampFigth-->Worship-->请求
	RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST       = 2658,	//CampFigth-->WorshipRank-->请求
	RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY          = 2659,	//CampFigth-->新赛季-->通知
	RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST    = 2660,	//CampFigth-->同步段位奖励-->请求
	RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST     = 2661,	//CampFigth-->获取段位奖励-->请求
	RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST  = 2662,	//CampFigth-->进入战场-->请求


};


//新赛季通知封装类
class CampFigthRpcNewSeasonNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcNewSeasonNotifyWraper()
	{
		
		m_Rank = -1;
		m_Star = -1;
		m_RankIndex = -1;
		m_Lastseason = -1;

	}
	//赋值构造函数
	CampFigthRpcNewSeasonNotifyWraper(const CampFigthRpcNewSeasonNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcNewSeasonNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcNewSeasonNotify ToPB() const
	{
		CampFigthRpcNewSeasonNotify v;
		v.set_rank( m_Rank );
		v.set_star( m_Star );
		v.set_rankindex( m_RankIndex );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			*v.add_rewardlist() = m_RewardList[i].ToPB();
		}
		v.set_lastseason( m_Lastseason );

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
		CampFigthRpcNewSeasonNotify pb;
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
	void Init(const CampFigthRpcNewSeasonNotify& v)
	{
		m_Rank = v.rank();
		m_Star = v.star();
		m_RankIndex = v.rankindex();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));
		m_Lastseason = v.lastseason();

	}

private:
	//段位
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//星级
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}
private:
	//排名
	INT32 m_RankIndex;
public:
	void SetRankIndex( INT32 v)
	{
		m_RankIndex=v;
	}
	INT32 GetRankIndex()
	{
		return m_RankIndex;
	}
	INT32 GetRankIndex() const
	{
		return m_RankIndex;
	}
private:
	//奖励列表
	vector<PvpBattleRewardInfoWraper> m_RewardList;
public:
	int SizeRewardList()
	{
		return m_RewardList.size();
	}
	const vector<PvpBattleRewardInfoWraper>& GetRewardList() const
	{
		return m_RewardList;
	}
	PvpBattleRewardInfoWraper GetRewardList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return PvpBattleRewardInfoWraper();
		}
		return m_RewardList[Index];
	}
	void SetRewardList( const vector<PvpBattleRewardInfoWraper>& v )
	{
		m_RewardList=v;
	}
	void ClearRewardList( )
	{
		m_RewardList.clear();
	}
	void SetRewardList( int Index, const PvpBattleRewardInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return;
		}
		m_RewardList[Index] = v;
	}
	void AddRewardList( const PvpBattleRewardInfoWraper& v )
	{
		m_RewardList.push_back(v);
	}
private:
	//上一赛季
	INT32 m_Lastseason;
public:
	void SetLastseason( INT32 v)
	{
		m_Lastseason=v;
	}
	INT32 GetLastseason()
	{
		return m_Lastseason;
	}
	INT32 GetLastseason() const
	{
		return m_Lastseason;
	}

};
//同步段位奖励请求封装类
class CampFigthRpcSyncRankRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcSyncRankRewardAskWraper()
	{
		

	}
	//赋值构造函数
	CampFigthRpcSyncRankRewardAskWraper(const CampFigthRpcSyncRankRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcSyncRankRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcSyncRankRewardAsk ToPB() const
	{
		CampFigthRpcSyncRankRewardAsk v;

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
		CampFigthRpcSyncRankRewardAsk pb;
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
	void Init(const CampFigthRpcSyncRankRewardAsk& v)
	{

	}


};
//WorshipRank请求封装类
class CampFigthRpcWorshipRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcWorshipRankAskWraper()
	{
		
		m_RoleID = -1;

	}
	//赋值构造函数
	CampFigthRpcWorshipRankAskWraper(const CampFigthRpcWorshipRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcWorshipRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcWorshipRankAsk ToPB() const
	{
		CampFigthRpcWorshipRankAsk v;
		v.set_roleid( m_RoleID );

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
		CampFigthRpcWorshipRankAsk pb;
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
	void Init(const CampFigthRpcWorshipRankAsk& v)
	{
		m_RoleID = v.roleid();

	}

private:
	//RoleID
	INT32 m_RoleID;
public:
	void SetRoleID( INT32 v)
	{
		m_RoleID=v;
	}
	INT32 GetRoleID()
	{
		return m_RoleID;
	}
	INT32 GetRoleID() const
	{
		return m_RoleID;
	}

};
//WorshipRank回应封装类
class CampFigthRpcWorshipRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcWorshipRankReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CampFigthRpcWorshipRankReplyWraper(const CampFigthRpcWorshipRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcWorshipRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcWorshipRankReply ToPB() const
	{
		CampFigthRpcWorshipRankReply v;
		v.set_result( m_Result );
		v.mutable_roledatas()->Reserve(m_RoleDatas.size());
		for (int i=0; i<(int)m_RoleDatas.size(); i++)
		{
			*v.add_roledatas() = m_RoleDatas[i].ToPB();
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
		CampFigthRpcWorshipRankReply pb;
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
	void Init(const CampFigthRpcWorshipRankReply& v)
	{
		m_Result = v.result();
		m_RoleDatas.clear();
		m_RoleDatas.reserve(v.roledatas_size());
		for( int i=0; i<v.roledatas_size(); i++)
			m_RoleDatas.push_back(v.roledatas(i));

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
	//RoleDatas
	vector<WorshipPlayerDataWraper> m_RoleDatas;
public:
	int SizeRoleDatas()
	{
		return m_RoleDatas.size();
	}
	const vector<WorshipPlayerDataWraper>& GetRoleDatas() const
	{
		return m_RoleDatas;
	}
	WorshipPlayerDataWraper GetRoleDatas(int Index) const
	{
		if(Index<0 || Index>=(int)m_RoleDatas.size())
		{
			assert(false);
			return WorshipPlayerDataWraper();
		}
		return m_RoleDatas[Index];
	}
	void SetRoleDatas( const vector<WorshipPlayerDataWraper>& v )
	{
		m_RoleDatas=v;
	}
	void ClearRoleDatas( )
	{
		m_RoleDatas.clear();
	}
	void SetRoleDatas( int Index, const WorshipPlayerDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_RoleDatas.size())
		{
			assert(false);
			return;
		}
		m_RoleDatas[Index] = v;
	}
	void AddRoleDatas( const WorshipPlayerDataWraper& v )
	{
		m_RoleDatas.push_back(v);
	}

};
//同步段位奖励回应封装类
class CampFigthRpcSyncRankRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcSyncRankRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CampFigthRpcSyncRankRewardReplyWraper(const CampFigthRpcSyncRankRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcSyncRankRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcSyncRankRewardReply ToPB() const
	{
		CampFigthRpcSyncRankRewardReply v;
		v.set_result( m_Result );
		v.mutable_rankrewardlist()->Reserve(m_RankRewardList.size());
		for (int i=0; i<(int)m_RankRewardList.size(); i++)
		{
			v.add_rankrewardlist(m_RankRewardList[i]);
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
		CampFigthRpcSyncRankRewardReply pb;
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
	void Init(const CampFigthRpcSyncRankRewardReply& v)
	{
		m_Result = v.result();
		m_RankRewardList.clear();
		m_RankRewardList.reserve(v.rankrewardlist_size());
		for( int i=0; i<v.rankrewardlist_size(); i++)
			m_RankRewardList.push_back(v.rankrewardlist(i));

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
	//已领取的奖励
	vector<INT32> m_RankRewardList;
public:
	int SizeRankRewardList()
	{
		return m_RankRewardList.size();
	}
	const vector<INT32>& GetRankRewardList() const
	{
		return m_RankRewardList;
	}
	INT32 GetRankRewardList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankRewardList.size())
		{
			assert(false);
			return INT32();
		}
		return m_RankRewardList[Index];
	}
	void SetRankRewardList( const vector<INT32>& v )
	{
		m_RankRewardList=v;
	}
	void ClearRankRewardList( )
	{
		m_RankRewardList.clear();
	}
	void SetRankRewardList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_RankRewardList.size())
		{
			assert(false);
			return;
		}
		m_RankRewardList[Index] = v;
	}
	void AddRankRewardList( INT32 v = -1 )
	{
		m_RankRewardList.push_back(v);
	}

};
//进入战场请求封装类
class CampFigthRpcEnterBattleSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcEnterBattleSceneAskWraper()
	{
		

	}
	//赋值构造函数
	CampFigthRpcEnterBattleSceneAskWraper(const CampFigthRpcEnterBattleSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcEnterBattleSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcEnterBattleSceneAsk ToPB() const
	{
		CampFigthRpcEnterBattleSceneAsk v;

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
		CampFigthRpcEnterBattleSceneAsk pb;
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
	void Init(const CampFigthRpcEnterBattleSceneAsk& v)
	{

	}


};
//进入战场回应封装类
class CampFigthRpcEnterBattleSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcEnterBattleSceneReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	CampFigthRpcEnterBattleSceneReplyWraper(const CampFigthRpcEnterBattleSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcEnterBattleSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcEnterBattleSceneReply ToPB() const
	{
		CampFigthRpcEnterBattleSceneReply v;
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
		CampFigthRpcEnterBattleSceneReply pb;
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
	void Init(const CampFigthRpcEnterBattleSceneReply& v)
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
//获取段位奖励请求封装类
class CampFigthRpcGetRankRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcGetRankRewardAskWraper()
	{
		
		m_Rank = -1;

	}
	//赋值构造函数
	CampFigthRpcGetRankRewardAskWraper(const CampFigthRpcGetRankRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcGetRankRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcGetRankRewardAsk ToPB() const
	{
		CampFigthRpcGetRankRewardAsk v;
		v.set_rank( m_Rank );

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
		CampFigthRpcGetRankRewardAsk pb;
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
	void Init(const CampFigthRpcGetRankRewardAsk& v)
	{
		m_Rank = v.rank();

	}

private:
	//段位
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}

};
//获取段位奖励回应封装类
class CampFigthRpcGetRankRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcGetRankRewardReplyWraper()
	{
		
		m_Result = -1;
		m_Rank = -1;

	}
	//赋值构造函数
	CampFigthRpcGetRankRewardReplyWraper(const CampFigthRpcGetRankRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcGetRankRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcGetRankRewardReply ToPB() const
	{
		CampFigthRpcGetRankRewardReply v;
		v.set_result( m_Result );
		v.set_rank( m_Rank );

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
		CampFigthRpcGetRankRewardReply pb;
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
	void Init(const CampFigthRpcGetRankRewardReply& v)
	{
		m_Result = v.result();
		m_Rank = v.rank();

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
	//领取的段位
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}

};
//Worship回应封装类
class CampFigthRpcWorshipReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcWorshipReplyWraper()
	{
		
		m_Result = -1;
		m_WorshipRoleID = -1;
		m_WorshipCount = -1;

	}
	//赋值构造函数
	CampFigthRpcWorshipReplyWraper(const CampFigthRpcWorshipReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcWorshipReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcWorshipReply ToPB() const
	{
		CampFigthRpcWorshipReply v;
		v.set_result( m_Result );
		v.set_worshiproleid( m_WorshipRoleID );
		v.set_worshipcount( m_WorshipCount );

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
		CampFigthRpcWorshipReply pb;
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
	void Init(const CampFigthRpcWorshipReply& v)
	{
		m_Result = v.result();
		m_WorshipRoleID = v.worshiproleid();
		m_WorshipCount = v.worshipcount();

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
	//WorshipRoleID
	INT32 m_WorshipRoleID;
public:
	void SetWorshipRoleID( INT32 v)
	{
		m_WorshipRoleID=v;
	}
	INT32 GetWorshipRoleID()
	{
		return m_WorshipRoleID;
	}
	INT32 GetWorshipRoleID() const
	{
		return m_WorshipRoleID;
	}
private:
	//WorshipCount
	INT32 m_WorshipCount;
public:
	void SetWorshipCount( INT32 v)
	{
		m_WorshipCount=v;
	}
	INT32 GetWorshipCount()
	{
		return m_WorshipCount;
	}
	INT32 GetWorshipCount() const
	{
		return m_WorshipCount;
	}

};
//CampFightContribution通知封装类
class CampFigthRpcCampFightContributionNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcCampFightContributionNotifyWraper()
	{
		
		m_Camp = -1;
		m_ContributionValue = -1;

	}
	//赋值构造函数
	CampFigthRpcCampFightContributionNotifyWraper(const CampFigthRpcCampFightContributionNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcCampFightContributionNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcCampFightContributionNotify ToPB() const
	{
		CampFigthRpcCampFightContributionNotify v;
		v.set_camp( m_Camp );
		v.set_contributionvalue( m_ContributionValue );

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
		CampFigthRpcCampFightContributionNotify pb;
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
	void Init(const CampFigthRpcCampFightContributionNotify& v)
	{
		m_Camp = v.camp();
		m_ContributionValue = v.contributionvalue();

	}

private:
	//Camp
	INT32 m_Camp;
public:
	void SetCamp( INT32 v)
	{
		m_Camp=v;
	}
	INT32 GetCamp()
	{
		return m_Camp;
	}
	INT32 GetCamp() const
	{
		return m_Camp;
	}
private:
	//ContributionValue
	INT32 m_ContributionValue;
public:
	void SetContributionValue( INT32 v)
	{
		m_ContributionValue=v;
	}
	INT32 GetContributionValue()
	{
		return m_ContributionValue;
	}
	INT32 GetContributionValue() const
	{
		return m_ContributionValue;
	}

};
//ObjKillBroadcast通知封装类
class CampFigthRpcObjKillBroadcastNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcObjKillBroadcastNotifyWraper()
	{
		
		m_KillerObjID = -1;
		m_KillerName = -1;
		m_DeadObjID = -1;
		m_DeadObjResID = -1;

	}
	//赋值构造函数
	CampFigthRpcObjKillBroadcastNotifyWraper(const CampFigthRpcObjKillBroadcastNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcObjKillBroadcastNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcObjKillBroadcastNotify ToPB() const
	{
		CampFigthRpcObjKillBroadcastNotify v;
		v.set_killerobjid( m_KillerObjID );
		v.set_killername( m_KillerName );
		v.set_deadobjid( m_DeadObjID );
		v.set_deadobjresid( m_DeadObjResID );

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
		CampFigthRpcObjKillBroadcastNotify pb;
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
	void Init(const CampFigthRpcObjKillBroadcastNotify& v)
	{
		m_KillerObjID = v.killerobjid();
		m_KillerName = v.killername();
		m_DeadObjID = v.deadobjid();
		m_DeadObjResID = v.deadobjresid();

	}

private:
	//KillerObjID
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
	//KillerName
	INT32 m_KillerName;
public:
	void SetKillerName( INT32 v)
	{
		m_KillerName=v;
	}
	INT32 GetKillerName()
	{
		return m_KillerName;
	}
	INT32 GetKillerName() const
	{
		return m_KillerName;
	}
private:
	//DeadObjID
	INT32 m_DeadObjID;
public:
	void SetDeadObjID( INT32 v)
	{
		m_DeadObjID=v;
	}
	INT32 GetDeadObjID()
	{
		return m_DeadObjID;
	}
	INT32 GetDeadObjID() const
	{
		return m_DeadObjID;
	}
private:
	//DeadObjResID
	INT32 m_DeadObjResID;
public:
	void SetDeadObjResID( INT32 v)
	{
		m_DeadObjResID=v;
	}
	INT32 GetDeadObjResID()
	{
		return m_DeadObjResID;
	}
	INT32 GetDeadObjResID() const
	{
		return m_DeadObjResID;
	}

};
//MilitaryBroken请求封装类
class CampFigthRpcMilitaryBrokenAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcMilitaryBrokenAskWraper()
	{
		
		m_RoleID = -1;

	}
	//赋值构造函数
	CampFigthRpcMilitaryBrokenAskWraper(const CampFigthRpcMilitaryBrokenAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcMilitaryBrokenAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcMilitaryBrokenAsk ToPB() const
	{
		CampFigthRpcMilitaryBrokenAsk v;
		v.set_roleid( m_RoleID );

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
		CampFigthRpcMilitaryBrokenAsk pb;
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
	void Init(const CampFigthRpcMilitaryBrokenAsk& v)
	{
		m_RoleID = v.roleid();

	}

private:
	//roleid
	INT32 m_RoleID;
public:
	void SetRoleID( INT32 v)
	{
		m_RoleID=v;
	}
	INT32 GetRoleID()
	{
		return m_RoleID;
	}
	INT32 GetRoleID() const
	{
		return m_RoleID;
	}

};
//MilitaryBroken回应封装类
class CampFigthRpcMilitaryBrokenReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcMilitaryBrokenReplyWraper()
	{
		
		m_Result = -1;
		m_Rank = -1;
		m_Star = -1;
		m_Exp = -1;

	}
	//赋值构造函数
	CampFigthRpcMilitaryBrokenReplyWraper(const CampFigthRpcMilitaryBrokenReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcMilitaryBrokenReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcMilitaryBrokenReply ToPB() const
	{
		CampFigthRpcMilitaryBrokenReply v;
		v.set_result( m_Result );
		v.set_rank( m_Rank );
		v.set_star( m_Star );
		v.set_exp( m_Exp );

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
		CampFigthRpcMilitaryBrokenReply pb;
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
	void Init(const CampFigthRpcMilitaryBrokenReply& v)
	{
		m_Result = v.result();
		m_Rank = v.rank();
		m_Star = v.star();
		m_Exp = v.exp();

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
	//Rank
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//Star
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}
private:
	//Exp
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}

};
//NpcBirth通知封装类
class CampFigthRpcNpcBirthNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcNpcBirthNotifyWraper()
	{
		
		m_Camp = -1;
		m_BirthObjID = -1;
		m_BirthObjResID = -1;

	}
	//赋值构造函数
	CampFigthRpcNpcBirthNotifyWraper(const CampFigthRpcNpcBirthNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcNpcBirthNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcNpcBirthNotify ToPB() const
	{
		CampFigthRpcNpcBirthNotify v;
		v.set_camp( m_Camp );
		v.set_birthobjid( m_BirthObjID );
		v.set_birthobjresid( m_BirthObjResID );

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
		CampFigthRpcNpcBirthNotify pb;
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
	void Init(const CampFigthRpcNpcBirthNotify& v)
	{
		m_Camp = v.camp();
		m_BirthObjID = v.birthobjid();
		m_BirthObjResID = v.birthobjresid();

	}

private:
	//Camp
	INT32 m_Camp;
public:
	void SetCamp( INT32 v)
	{
		m_Camp=v;
	}
	INT32 GetCamp()
	{
		return m_Camp;
	}
	INT32 GetCamp() const
	{
		return m_Camp;
	}
private:
	//BirthObjID
	INT32 m_BirthObjID;
public:
	void SetBirthObjID( INT32 v)
	{
		m_BirthObjID=v;
	}
	INT32 GetBirthObjID()
	{
		return m_BirthObjID;
	}
	INT32 GetBirthObjID() const
	{
		return m_BirthObjID;
	}
private:
	//BirthObjResID
	INT32 m_BirthObjResID;
public:
	void SetBirthObjResID( INT32 v)
	{
		m_BirthObjResID=v;
	}
	INT32 GetBirthObjResID()
	{
		return m_BirthObjResID;
	}
	INT32 GetBirthObjResID() const
	{
		return m_BirthObjResID;
	}

};
//KillDeadInfo通知封装类
class CampFigthRpcKillDeadInfoNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcKillDeadInfoNotifyWraper()
	{
		
		m_KillNum = -1;
		m_DeadNum = -1;
		m_Rank = -1;
		m_Exp = -1;
		m_Star = -1;

	}
	//赋值构造函数
	CampFigthRpcKillDeadInfoNotifyWraper(const CampFigthRpcKillDeadInfoNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcKillDeadInfoNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcKillDeadInfoNotify ToPB() const
	{
		CampFigthRpcKillDeadInfoNotify v;
		v.set_killnum( m_KillNum );
		v.set_deadnum( m_DeadNum );
		v.set_rank( m_Rank );
		v.set_exp( m_Exp );
		v.set_star( m_Star );

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
		CampFigthRpcKillDeadInfoNotify pb;
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
	void Init(const CampFigthRpcKillDeadInfoNotify& v)
	{
		m_KillNum = v.killnum();
		m_DeadNum = v.deadnum();
		m_Rank = v.rank();
		m_Exp = v.exp();
		m_Star = v.star();

	}

private:
	//KillNum
	INT32 m_KillNum;
public:
	void SetKillNum( INT32 v)
	{
		m_KillNum=v;
	}
	INT32 GetKillNum()
	{
		return m_KillNum;
	}
	INT32 GetKillNum() const
	{
		return m_KillNum;
	}
private:
	//DeadNum
	INT32 m_DeadNum;
public:
	void SetDeadNum( INT32 v)
	{
		m_DeadNum=v;
	}
	INT32 GetDeadNum()
	{
		return m_DeadNum;
	}
	INT32 GetDeadNum() const
	{
		return m_DeadNum;
	}
private:
	//Rank
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//Exp
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//Star
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}

};
//Worship请求封装类
class CampFigthRpcWorshipAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcWorshipAskWraper()
	{
		
		m_WorshipRoleID = -1;

	}
	//赋值构造函数
	CampFigthRpcWorshipAskWraper(const CampFigthRpcWorshipAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcWorshipAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcWorshipAsk ToPB() const
	{
		CampFigthRpcWorshipAsk v;
		v.set_worshiproleid( m_WorshipRoleID );

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
		CampFigthRpcWorshipAsk pb;
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
	void Init(const CampFigthRpcWorshipAsk& v)
	{
		m_WorshipRoleID = v.worshiproleid();

	}

private:
	//WorshipRoleID
	INT32 m_WorshipRoleID;
public:
	void SetWorshipRoleID( INT32 v)
	{
		m_WorshipRoleID=v;
	}
	INT32 GetWorshipRoleID()
	{
		return m_WorshipRoleID;
	}
	INT32 GetWorshipRoleID() const
	{
		return m_WorshipRoleID;
	}

};
//GetMilitaryValue请求封装类
class CampFigthRpcGetMilitaryValueAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcGetMilitaryValueAskWraper()
	{
		
		m_RoleID = -1;

	}
	//赋值构造函数
	CampFigthRpcGetMilitaryValueAskWraper(const CampFigthRpcGetMilitaryValueAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcGetMilitaryValueAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcGetMilitaryValueAsk ToPB() const
	{
		CampFigthRpcGetMilitaryValueAsk v;
		v.set_roleid( m_RoleID );

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
		CampFigthRpcGetMilitaryValueAsk pb;
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
	void Init(const CampFigthRpcGetMilitaryValueAsk& v)
	{
		m_RoleID = v.roleid();

	}

private:
	//RoleID
	INT32 m_RoleID;
public:
	void SetRoleID( INT32 v)
	{
		m_RoleID=v;
	}
	INT32 GetRoleID()
	{
		return m_RoleID;
	}
	INT32 GetRoleID() const
	{
		return m_RoleID;
	}

};
//GetMilitaryValue回应封装类
class CampFigthRpcGetMilitaryValueReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	CampFigthRpcGetMilitaryValueReplyWraper()
	{
		
		m_Result = -1;
		m_Rank = -1;
		m_Star = -1;
		m_Exp = -1;
		m_Curseason = -1;
		m_TodayHornor = -1;

	}
	//赋值构造函数
	CampFigthRpcGetMilitaryValueReplyWraper(const CampFigthRpcGetMilitaryValueReply& v){ Init(v); }
	//等号重载函数
	void operator = (const CampFigthRpcGetMilitaryValueReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CampFigthRpcGetMilitaryValueReply ToPB() const
	{
		CampFigthRpcGetMilitaryValueReply v;
		v.set_result( m_Result );
		v.set_rank( m_Rank );
		v.set_star( m_Star );
		v.set_exp( m_Exp );
		v.set_curseason( m_Curseason );
		v.set_todayhornor( m_TodayHornor );

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
		CampFigthRpcGetMilitaryValueReply pb;
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
	void Init(const CampFigthRpcGetMilitaryValueReply& v)
	{
		m_Result = v.result();
		m_Rank = v.rank();
		m_Star = v.star();
		m_Exp = v.exp();
		m_Curseason = v.curseason();
		m_TodayHornor = v.todayhornor();

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
	//Rank
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//Star
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}
private:
	//Exp
	INT32 m_Exp;
public:
	void SetExp( INT32 v)
	{
		m_Exp=v;
	}
	INT32 GetExp()
	{
		return m_Exp;
	}
	INT32 GetExp() const
	{
		return m_Exp;
	}
private:
	//当前赛季
	INT32 m_Curseason;
public:
	void SetCurseason( INT32 v)
	{
		m_Curseason=v;
	}
	INT32 GetCurseason()
	{
		return m_Curseason;
	}
	INT32 GetCurseason() const
	{
		return m_Curseason;
	}
private:
	//今日获得荣誉值
	INT32 m_TodayHornor;
public:
	void SetTodayHornor( INT32 v)
	{
		m_TodayHornor=v;
	}
	INT32 GetTodayHornor()
	{
		return m_TodayHornor;
	}
	INT32 GetTodayHornor() const
	{
		return m_TodayHornor;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<CampFigthRpcCampFightContributionNotifyWraper>{ enum{ID=RPC_CODE_CAMPFIGTH_CAMPFIGHTCONTRIBUTION_NOTIFY};};
template<> struct MessageIdT<CampFigthRpcObjKillBroadcastNotifyWraper>{ enum{ID=RPC_CODE_CAMPFIGTH_OBJKILLBROADCAST_NOTIFY};};
template<> struct MessageIdT<CampFigthRpcNpcBirthNotifyWraper>{ enum{ID=RPC_CODE_CAMPFIGTH_NPCBIRTH_NOTIFY};};
template<> struct MessageIdT<CampFigthRpcKillDeadInfoNotifyWraper>{ enum{ID=RPC_CODE_CAMPFIGTH_KILLDEADINFO_NOTIFY};};
template<> struct MessageIdT<CampFigthRpcNewSeasonNotifyWraper>{ enum{ID=RPC_CODE_CAMPFIGTH_NEWSEASON_NOTIFY};};


#endif
