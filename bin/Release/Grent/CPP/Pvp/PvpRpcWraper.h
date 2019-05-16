/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperPvp.h
* Author:       甘业清
* Description:  PvpRPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_PVP_H
#define __RPC_WRAPER_PVP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "PvpRpc.pb.h"



//Pvp类的枚举定义
enum ConstPvpE
{
	MODULE_ID_PVP                                = 34,	//Pvp模块ID
	RPC_CODE_PVP_RANK_REQUEST                    = 3451,	//Pvp-->Rank-->请求
	RPC_CODE_PVP_MATCH_REQUEST                   = 3452,	//Pvp-->匹配-->请求
	RPC_CODE_PVP_MATCHNOTIFY_NOTIFY              = 3453,	//Pvp-->匹配的通知-->通知
	RPC_CODE_PVP_MATCHCANCLE_REQUEST             = 3454,	//Pvp-->取消匹配-->请求
	RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY        = 3455,	//Pvp-->取消匹配通知-->通知
	RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST       = 3456,	//Pvp-->请求战斗信息-->请求
	RPC_CODE_PVP_PVPBATTLESTART_NOTIFY           = 3457,	//Pvp-->PvpBattleStart-->通知
	RPC_CODE_PVP_PVPBATTLEEND_NOTIFY             = 3458,	//Pvp-->PvpBattleEnd-->通知
	RPC_CODE_PVP_PLAYERREADY_REQUEST             = 3459,	//Pvp-->PlayerReady-->请求
	RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY        = 3460,	//Pvp-->玩家准备的通知-->通知
	RPC_CODE_PVP_READYFAILD_NOTIFY               = 3461,	//Pvp-->等待确认超时-->通知
	RPC_CODE_PVP_MATCHSUCESS_NOTIFY              = 3462,	//Pvp-->匹配完成-->通知
	RPC_CODE_PVP_RANKCHANGE_NOTIFY               = 3463,	//Pvp-->段位变化-->通知
	RPC_CODE_PVP_RETURNLASTSCENE_REQUEST         = 3464,	//Pvp-->返回-->请求
	RPC_CODE_PVP_ARENASTARTTIME_NOTIFY           = 3465,	//Pvp-->通知开始时间-->通知
	RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY          = 3466,	//Pvp-->更新击杀数量-->通知
	RPC_CODE_PVP_ARENALEFTTIME_NOTIFY            = 3467,	//Pvp-->剩余时间-->通知
	RPC_CODE_PVP_LASTRANK_REQUEST                = 3468,	//Pvp-->上个赛季的排行-->请求
	RPC_CODE_PVP_NEWSEASON_NOTIFY                = 3469,	//Pvp-->新赛季通知-->通知
	RPC_CODE_PVP_GETSEASONREWARD_REQUEST         = 3470,	//Pvp-->领取奖励-->请求
	RPC_CODE_PVP_RECONNECT_NOTIFY                = 3471,	//Pvp-->重连-->通知
	RPC_CODE_PVP_GETREWARD_REQUEST               = 3472,	//Pvp-->获取奖励-->请求


};


//剩余时间通知封装类
class PvpRpcArenaLeftTimeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcArenaLeftTimeNotifyWraper()
	{
		
		m_LeftTime = -1;

	}
	//赋值构造函数
	PvpRpcArenaLeftTimeNotifyWraper(const PvpRpcArenaLeftTimeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcArenaLeftTimeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcArenaLeftTimeNotify ToPB() const
	{
		PvpRpcArenaLeftTimeNotify v;
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
		PvpRpcArenaLeftTimeNotify pb;
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
	void Init(const PvpRpcArenaLeftTimeNotify& v)
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
//上个赛季的排行请求封装类
class PvpRpcLastRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcLastRankAskWraper()
	{
		
		m_PvpType = -1;

	}
	//赋值构造函数
	PvpRpcLastRankAskWraper(const PvpRpcLastRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcLastRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcLastRankAsk ToPB() const
	{
		PvpRpcLastRankAsk v;
		v.set_pvptype( m_PvpType );

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
		PvpRpcLastRankAsk pb;
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
	void Init(const PvpRpcLastRankAsk& v)
	{
		m_PvpType = v.pvptype();

	}

private:
	//类型
	INT32 m_PvpType;
public:
	void SetPvpType( INT32 v)
	{
		m_PvpType=v;
	}
	INT32 GetPvpType()
	{
		return m_PvpType;
	}
	INT32 GetPvpType() const
	{
		return m_PvpType;
	}

};
//上个赛季的排行回应封装类
class PvpRpcLastRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcLastRankReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcLastRankReplyWraper(const PvpRpcLastRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcLastRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcLastRankReply ToPB() const
	{
		PvpRpcLastRankReply v;
		v.set_result( m_Result );
		v.mutable_ranklist()->Reserve(m_RankList.size());
		for (int i=0; i<(int)m_RankList.size(); i++)
		{
			*v.add_ranklist() = m_RankList[i].ToPB();
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
		PvpRpcLastRankReply pb;
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
	void Init(const PvpRpcLastRankReply& v)
	{
		m_Result = v.result();
		m_RankList.clear();
		m_RankList.reserve(v.ranklist_size());
		for( int i=0; i<v.ranklist_size(); i++)
			m_RankList.push_back(v.ranklist(i));

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
	//排行信息
	vector<PvpPlayerInfoWraper> m_RankList;
public:
	int SizeRankList()
	{
		return m_RankList.size();
	}
	const vector<PvpPlayerInfoWraper>& GetRankList() const
	{
		return m_RankList;
	}
	PvpPlayerInfoWraper GetRankList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankList.size())
		{
			assert(false);
			return PvpPlayerInfoWraper();
		}
		return m_RankList[Index];
	}
	void SetRankList( const vector<PvpPlayerInfoWraper>& v )
	{
		m_RankList=v;
	}
	void ClearRankList( )
	{
		m_RankList.clear();
	}
	void SetRankList( int Index, const PvpPlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RankList.size())
		{
			assert(false);
			return;
		}
		m_RankList[Index] = v;
	}
	void AddRankList( const PvpPlayerInfoWraper& v )
	{
		m_RankList.push_back(v);
	}

};
//更新击杀数量通知封装类
class PvpRpcUpdateKillCountNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcUpdateKillCountNotifyWraper()
	{
		
		m_LeftTeamKill = -1;
		m_RightTeamKill = -1;

	}
	//赋值构造函数
	PvpRpcUpdateKillCountNotifyWraper(const PvpRpcUpdateKillCountNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcUpdateKillCountNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcUpdateKillCountNotify ToPB() const
	{
		PvpRpcUpdateKillCountNotify v;
		v.set_leftteamkill( m_LeftTeamKill );
		v.set_rightteamkill( m_RightTeamKill );

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
		PvpRpcUpdateKillCountNotify pb;
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
	void Init(const PvpRpcUpdateKillCountNotify& v)
	{
		m_LeftTeamKill = v.leftteamkill();
		m_RightTeamKill = v.rightteamkill();

	}

private:
	//左方杀人数
	INT32 m_LeftTeamKill;
public:
	void SetLeftTeamKill( INT32 v)
	{
		m_LeftTeamKill=v;
	}
	INT32 GetLeftTeamKill()
	{
		return m_LeftTeamKill;
	}
	INT32 GetLeftTeamKill() const
	{
		return m_LeftTeamKill;
	}
private:
	//右侧杀人数
	INT32 m_RightTeamKill;
public:
	void SetRightTeamKill( INT32 v)
	{
		m_RightTeamKill=v;
	}
	INT32 GetRightTeamKill()
	{
		return m_RightTeamKill;
	}
	INT32 GetRightTeamKill() const
	{
		return m_RightTeamKill;
	}

};
//返回请求封装类
class PvpRpcReturnLastSceneAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcReturnLastSceneAskWraper()
	{
		

	}
	//赋值构造函数
	PvpRpcReturnLastSceneAskWraper(const PvpRpcReturnLastSceneAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcReturnLastSceneAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcReturnLastSceneAsk ToPB() const
	{
		PvpRpcReturnLastSceneAsk v;

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
		PvpRpcReturnLastSceneAsk pb;
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
	void Init(const PvpRpcReturnLastSceneAsk& v)
	{

	}


};
//返回回应封装类
class PvpRpcReturnLastSceneReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcReturnLastSceneReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcReturnLastSceneReplyWraper(const PvpRpcReturnLastSceneReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcReturnLastSceneReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcReturnLastSceneReply ToPB() const
	{
		PvpRpcReturnLastSceneReply v;
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
		PvpRpcReturnLastSceneReply pb;
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
	void Init(const PvpRpcReturnLastSceneReply& v)
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
//通知开始时间通知封装类
class PvpRpcArenaStartTimeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcArenaStartTimeNotifyWraper()
	{
		
		m_NeedTime = -1;
		m_TimeStamp = -1;

	}
	//赋值构造函数
	PvpRpcArenaStartTimeNotifyWraper(const PvpRpcArenaStartTimeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcArenaStartTimeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcArenaStartTimeNotify ToPB() const
	{
		PvpRpcArenaStartTimeNotify v;
		v.set_needtime( m_NeedTime );
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
		PvpRpcArenaStartTimeNotify pb;
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
	void Init(const PvpRpcArenaStartTimeNotify& v)
	{
		m_NeedTime = v.needtime();
		m_TimeStamp = v.timestamp();

	}

private:
	//剩余时间 秒
	INT32 m_NeedTime;
public:
	void SetNeedTime( INT32 v)
	{
		m_NeedTime=v;
	}
	INT32 GetNeedTime()
	{
		return m_NeedTime;
	}
	INT32 GetNeedTime() const
	{
		return m_NeedTime;
	}
private:
	//时间戳 
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
//新赛季通知通知封装类
class PvpRpcNewSeasonNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcNewSeasonNotifyWraper()
	{
		
		m_LastRank = -1;
		m_LastStar = -1;
		m_LastRanking = -1;

	}
	//赋值构造函数
	PvpRpcNewSeasonNotifyWraper(const PvpRpcNewSeasonNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcNewSeasonNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcNewSeasonNotify ToPB() const
	{
		PvpRpcNewSeasonNotify v;
		v.set_lastrank( m_LastRank );
		v.set_laststar( m_LastStar );
		v.set_lastranking( m_LastRanking );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			*v.add_rewardlist() = m_RewardList[i].ToPB();
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
		PvpRpcNewSeasonNotify pb;
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
	void Init(const PvpRpcNewSeasonNotify& v)
	{
		m_LastRank = v.lastrank();
		m_LastStar = v.laststar();
		m_LastRanking = v.lastranking();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));

	}

private:
	//上赛季段位
	INT32 m_LastRank;
public:
	void SetLastRank( INT32 v)
	{
		m_LastRank=v;
	}
	INT32 GetLastRank()
	{
		return m_LastRank;
	}
	INT32 GetLastRank() const
	{
		return m_LastRank;
	}
private:
	//上赛季星级
	INT32 m_LastStar;
public:
	void SetLastStar( INT32 v)
	{
		m_LastStar=v;
	}
	INT32 GetLastStar()
	{
		return m_LastStar;
	}
	INT32 GetLastStar() const
	{
		return m_LastStar;
	}
private:
	//上赛季排名
	INT32 m_LastRanking;
public:
	void SetLastRanking( INT32 v)
	{
		m_LastRanking=v;
	}
	INT32 GetLastRanking()
	{
		return m_LastRanking;
	}
	INT32 GetLastRanking() const
	{
		return m_LastRanking;
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

};
//重连通知封装类
class PvpRpcReconnectNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcReconnectNotifyWraper()
	{
		
		m_NeedKill = -1;
		m_ArenaState = -1;
		m_LeftTime = -1;
		m_LeftKill = -1;
		m_RightKill = -1;
		m_Camp = -1;
		m_TimeStamp = -1;

	}
	//赋值构造函数
	PvpRpcReconnectNotifyWraper(const PvpRpcReconnectNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcReconnectNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcReconnectNotify ToPB() const
	{
		PvpRpcReconnectNotify v;
		v.set_needkill( m_NeedKill );
		v.set_arenastate( m_ArenaState );
		v.set_lefttime( m_LeftTime );
		v.set_leftkill( m_LeftKill );
		v.set_rightkill( m_RightKill );
		v.set_camp( m_Camp );
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
		PvpRpcReconnectNotify pb;
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
	void Init(const PvpRpcReconnectNotify& v)
	{
		m_NeedKill = v.needkill();
		m_ArenaState = v.arenastate();
		m_LeftTime = v.lefttime();
		m_LeftKill = v.leftkill();
		m_RightKill = v.rightkill();
		m_Camp = v.camp();
		m_TimeStamp = v.timestamp();

	}

private:
	//需要杀人数
	INT32 m_NeedKill;
public:
	void SetNeedKill( INT32 v)
	{
		m_NeedKill=v;
	}
	INT32 GetNeedKill()
	{
		return m_NeedKill;
	}
	INT32 GetNeedKill() const
	{
		return m_NeedKill;
	}
private:
	//竞技场状态
	INT32 m_ArenaState;
public:
	void SetArenaState( INT32 v)
	{
		m_ArenaState=v;
	}
	INT32 GetArenaState()
	{
		return m_ArenaState;
	}
	INT32 GetArenaState() const
	{
		return m_ArenaState;
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
private:
	//左侧阵营击杀数量
	INT32 m_LeftKill;
public:
	void SetLeftKill( INT32 v)
	{
		m_LeftKill=v;
	}
	INT32 GetLeftKill()
	{
		return m_LeftKill;
	}
	INT32 GetLeftKill() const
	{
		return m_LeftKill;
	}
private:
	//右侧阵营击杀数量
	INT32 m_RightKill;
public:
	void SetRightKill( INT32 v)
	{
		m_RightKill=v;
	}
	INT32 GetRightKill()
	{
		return m_RightKill;
	}
	INT32 GetRightKill() const
	{
		return m_RightKill;
	}
private:
	//阵营
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
	//时间戳
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
//获取奖励请求封装类
class PvpRpcGetRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcGetRewardAskWraper()
	{
		
		m_PvPType = -1;
		m_Rank = -1;

	}
	//赋值构造函数
	PvpRpcGetRewardAskWraper(const PvpRpcGetRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcGetRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcGetRewardAsk ToPB() const
	{
		PvpRpcGetRewardAsk v;
		v.set_pvptype( m_PvPType );
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
		PvpRpcGetRewardAsk pb;
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
	void Init(const PvpRpcGetRewardAsk& v)
	{
		m_PvPType = v.pvptype();
		m_Rank = v.rank();

	}

private:
	//战斗类型
	INT32 m_PvPType;
public:
	void SetPvPType( INT32 v)
	{
		m_PvPType=v;
	}
	INT32 GetPvPType()
	{
		return m_PvPType;
	}
	INT32 GetPvPType() const
	{
		return m_PvPType;
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
//获取奖励回应封装类
class PvpRpcGetRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcGetRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcGetRewardReplyWraper(const PvpRpcGetRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcGetRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcGetRewardReply ToPB() const
	{
		PvpRpcGetRewardReply v;
		v.set_result( m_Result );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			v.add_rewardlist(m_RewardList[i]);
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
		PvpRpcGetRewardReply pb;
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
	void Init(const PvpRpcGetRewardReply& v)
	{
		m_Result = v.result();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));

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
	//已领过的
	vector<INT32> m_RewardList;
public:
	int SizeRewardList()
	{
		return m_RewardList.size();
	}
	const vector<INT32>& GetRewardList() const
	{
		return m_RewardList;
	}
	INT32 GetRewardList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return INT32();
		}
		return m_RewardList[Index];
	}
	void SetRewardList( const vector<INT32>& v )
	{
		m_RewardList=v;
	}
	void ClearRewardList( )
	{
		m_RewardList.clear();
	}
	void SetRewardList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_RewardList.size())
		{
			assert(false);
			return;
		}
		m_RewardList[Index] = v;
	}
	void AddRewardList( INT32 v = -1 )
	{
		m_RewardList.push_back(v);
	}

};
//请求战斗信息回应封装类
class PvpRpcPvpBattleInfoSyncReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPvpBattleInfoSyncReplyWraper()
	{
		
		m_Result = -1;
		m_BattleInfo = PvpBattleInfoWraper();
		m_Season = -1;
		m_RankIndex = -1;

	}
	//赋值构造函数
	PvpRpcPvpBattleInfoSyncReplyWraper(const PvpRpcPvpBattleInfoSyncReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPvpBattleInfoSyncReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPvpBattleInfoSyncReply ToPB() const
	{
		PvpRpcPvpBattleInfoSyncReply v;
		v.set_result( m_Result );
		*v.mutable_battleinfo()= m_BattleInfo.ToPB();
		v.set_season( m_Season );
		v.set_rankindex( m_RankIndex );

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
		PvpRpcPvpBattleInfoSyncReply pb;
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
	void Init(const PvpRpcPvpBattleInfoSyncReply& v)
	{
		m_Result = v.result();
		m_BattleInfo = v.battleinfo();
		m_Season = v.season();
		m_RankIndex = v.rankindex();

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
	//战斗信息
	PvpBattleInfoWraper m_BattleInfo;
public:
	void SetBattleInfo( const PvpBattleInfoWraper& v)
	{
		m_BattleInfo=v;
	}
	PvpBattleInfoWraper GetBattleInfo()
	{
		return m_BattleInfo;
	}
	PvpBattleInfoWraper GetBattleInfo() const
	{
		return m_BattleInfo;
	}
private:
	//当前赛季
	INT32 m_Season;
public:
	void SetSeason( INT32 v)
	{
		m_Season=v;
	}
	INT32 GetSeason()
	{
		return m_Season;
	}
	INT32 GetSeason() const
	{
		return m_Season;
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

};
//领取奖励请求封装类
class PvpRpcGetSeasonRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcGetSeasonRewardAskWraper()
	{
		

	}
	//赋值构造函数
	PvpRpcGetSeasonRewardAskWraper(const PvpRpcGetSeasonRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcGetSeasonRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcGetSeasonRewardAsk ToPB() const
	{
		PvpRpcGetSeasonRewardAsk v;

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
		PvpRpcGetSeasonRewardAsk pb;
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
	void Init(const PvpRpcGetSeasonRewardAsk& v)
	{

	}


};
//领取奖励回应封装类
class PvpRpcGetSeasonRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcGetSeasonRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcGetSeasonRewardReplyWraper(const PvpRpcGetSeasonRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcGetSeasonRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcGetSeasonRewardReply ToPB() const
	{
		PvpRpcGetSeasonRewardReply v;
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
		PvpRpcGetSeasonRewardReply pb;
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
	void Init(const PvpRpcGetSeasonRewardReply& v)
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
//请求战斗信息请求封装类
class PvpRpcPvpBattleInfoSyncAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPvpBattleInfoSyncAskWraper()
	{
		

	}
	//赋值构造函数
	PvpRpcPvpBattleInfoSyncAskWraper(const PvpRpcPvpBattleInfoSyncAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPvpBattleInfoSyncAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPvpBattleInfoSyncAsk ToPB() const
	{
		PvpRpcPvpBattleInfoSyncAsk v;

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
		PvpRpcPvpBattleInfoSyncAsk pb;
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
	void Init(const PvpRpcPvpBattleInfoSyncAsk& v)
	{

	}


};
//段位变化通知封装类
class PvpRpcRankChangeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcRankChangeNotifyWraper()
	{
		
		m_PvpType = -1;
		m_BeforeRank = -1;
		m_AfterRank = -1;
		m_BeforeStar = -1;
		m_AfterStar = -1;

	}
	//赋值构造函数
	PvpRpcRankChangeNotifyWraper(const PvpRpcRankChangeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcRankChangeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcRankChangeNotify ToPB() const
	{
		PvpRpcRankChangeNotify v;
		v.set_pvptype( m_PvpType );
		v.set_beforerank( m_BeforeRank );
		v.set_afterrank( m_AfterRank );
		v.set_beforestar( m_BeforeStar );
		v.set_afterstar( m_AfterStar );

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
		PvpRpcRankChangeNotify pb;
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
	void Init(const PvpRpcRankChangeNotify& v)
	{
		m_PvpType = v.pvptype();
		m_BeforeRank = v.beforerank();
		m_AfterRank = v.afterrank();
		m_BeforeStar = v.beforestar();
		m_AfterStar = v.afterstar();

	}

private:
	//类型
	INT32 m_PvpType;
public:
	void SetPvpType( INT32 v)
	{
		m_PvpType=v;
	}
	INT32 GetPvpType()
	{
		return m_PvpType;
	}
	INT32 GetPvpType() const
	{
		return m_PvpType;
	}
private:
	//之前段位
	INT32 m_BeforeRank;
public:
	void SetBeforeRank( INT32 v)
	{
		m_BeforeRank=v;
	}
	INT32 GetBeforeRank()
	{
		return m_BeforeRank;
	}
	INT32 GetBeforeRank() const
	{
		return m_BeforeRank;
	}
private:
	//之后段位
	INT32 m_AfterRank;
public:
	void SetAfterRank( INT32 v)
	{
		m_AfterRank=v;
	}
	INT32 GetAfterRank()
	{
		return m_AfterRank;
	}
	INT32 GetAfterRank() const
	{
		return m_AfterRank;
	}
private:
	//星级
	INT32 m_BeforeStar;
public:
	void SetBeforeStar( INT32 v)
	{
		m_BeforeStar=v;
	}
	INT32 GetBeforeStar()
	{
		return m_BeforeStar;
	}
	INT32 GetBeforeStar() const
	{
		return m_BeforeStar;
	}
private:
	//星级
	INT32 m_AfterStar;
public:
	void SetAfterStar( INT32 v)
	{
		m_AfterStar=v;
	}
	INT32 GetAfterStar()
	{
		return m_AfterStar;
	}
	INT32 GetAfterStar() const
	{
		return m_AfterStar;
	}

};
//匹配的通知通知封装类
class PvpRpcMatchNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchNotifyNotifyWraper()
	{
		

	}
	//赋值构造函数
	PvpRpcMatchNotifyNotifyWraper(const PvpRpcMatchNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchNotifyNotify ToPB() const
	{
		PvpRpcMatchNotifyNotify v;

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
		PvpRpcMatchNotifyNotify pb;
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
	void Init(const PvpRpcMatchNotifyNotify& v)
	{

	}


};
//MatchCancle请求封装类
class PvpRpcMatchCancleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchCancleAskWraper()
	{
		

	}
	//赋值构造函数
	PvpRpcMatchCancleAskWraper(const PvpRpcMatchCancleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchCancleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchCancleAsk ToPB() const
	{
		PvpRpcMatchCancleAsk v;

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
		PvpRpcMatchCancleAsk pb;
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
	void Init(const PvpRpcMatchCancleAsk& v)
	{

	}


};
//MatchCancle回应封装类
class PvpRpcMatchCancleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchCancleReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcMatchCancleReplyWraper(const PvpRpcMatchCancleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchCancleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchCancleReply ToPB() const
	{
		PvpRpcMatchCancleReply v;
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
		PvpRpcMatchCancleReply pb;
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
	void Init(const PvpRpcMatchCancleReply& v)
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
//Match回应封装类
class PvpRpcMatchReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcMatchReplyWraper(const PvpRpcMatchReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchReply ToPB() const
	{
		PvpRpcMatchReply v;
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
		PvpRpcMatchReply pb;
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
	void Init(const PvpRpcMatchReply& v)
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
//Rank请求封装类
class PvpRpcRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcRankAskWraper()
	{
		
		m_PvpType = -1;

	}
	//赋值构造函数
	PvpRpcRankAskWraper(const PvpRpcRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcRankAsk ToPB() const
	{
		PvpRpcRankAsk v;
		v.set_pvptype( m_PvpType );

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
		PvpRpcRankAsk pb;
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
	void Init(const PvpRpcRankAsk& v)
	{
		m_PvpType = v.pvptype();

	}

private:
	//PvpType
	INT32 m_PvpType;
public:
	void SetPvpType( INT32 v)
	{
		m_PvpType=v;
	}
	INT32 GetPvpType()
	{
		return m_PvpType;
	}
	INT32 GetPvpType() const
	{
		return m_PvpType;
	}

};
//Rank回应封装类
class PvpRpcRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcRankReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcRankReplyWraper(const PvpRpcRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcRankReply ToPB() const
	{
		PvpRpcRankReply v;
		v.set_result( m_Result );
		v.mutable_ranklist()->Reserve(m_RankList.size());
		for (int i=0; i<(int)m_RankList.size(); i++)
		{
			*v.add_ranklist() = m_RankList[i].ToPB();
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
		PvpRpcRankReply pb;
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
	void Init(const PvpRpcRankReply& v)
	{
		m_Result = v.result();
		m_RankList.clear();
		m_RankList.reserve(v.ranklist_size());
		for( int i=0; i<v.ranklist_size(); i++)
			m_RankList.push_back(v.ranklist(i));

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
	//RankList
	vector<PvpPlayerInfoWraper> m_RankList;
public:
	int SizeRankList()
	{
		return m_RankList.size();
	}
	const vector<PvpPlayerInfoWraper>& GetRankList() const
	{
		return m_RankList;
	}
	PvpPlayerInfoWraper GetRankList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RankList.size())
		{
			assert(false);
			return PvpPlayerInfoWraper();
		}
		return m_RankList[Index];
	}
	void SetRankList( const vector<PvpPlayerInfoWraper>& v )
	{
		m_RankList=v;
	}
	void ClearRankList( )
	{
		m_RankList.clear();
	}
	void SetRankList( int Index, const PvpPlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RankList.size())
		{
			assert(false);
			return;
		}
		m_RankList[Index] = v;
	}
	void AddRankList( const PvpPlayerInfoWraper& v )
	{
		m_RankList.push_back(v);
	}

};
//Match请求封装类
class PvpRpcMatchAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchAskWraper()
	{
		
		m_PvpType = -1;

	}
	//赋值构造函数
	PvpRpcMatchAskWraper(const PvpRpcMatchAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchAsk ToPB() const
	{
		PvpRpcMatchAsk v;
		v.set_pvptype( m_PvpType );

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
		PvpRpcMatchAsk pb;
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
	void Init(const PvpRpcMatchAsk& v)
	{
		m_PvpType = v.pvptype();

	}

private:
	//PvpType
	INT32 m_PvpType;
public:
	void SetPvpType( INT32 v)
	{
		m_PvpType=v;
	}
	INT32 GetPvpType()
	{
		return m_PvpType;
	}
	INT32 GetPvpType() const
	{
		return m_PvpType;
	}

};
//取消匹配通知通知封装类
class PvpRpcMatchCancleNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchCancleNotifyNotifyWraper()
	{
		
		m_RoleId = 0;
		m_Name = "";
		m_Reason = -1;

	}
	//赋值构造函数
	PvpRpcMatchCancleNotifyNotifyWraper(const PvpRpcMatchCancleNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchCancleNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchCancleNotifyNotify ToPB() const
	{
		PvpRpcMatchCancleNotifyNotify v;
		v.set_roleid( m_RoleId );
		v.set_name( m_Name );
		v.set_reason( m_Reason );

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
		PvpRpcMatchCancleNotifyNotify pb;
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
	void Init(const PvpRpcMatchCancleNotifyNotify& v)
	{
		m_RoleId = v.roleid();
		m_Name = v.name();
		m_Reason = v.reason();

	}

private:
	//取消者的ID
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
private:
	//原因
	INT32 m_Reason;
public:
	void SetReason( INT32 v)
	{
		m_Reason=v;
	}
	INT32 GetReason()
	{
		return m_Reason;
	}
	INT32 GetReason() const
	{
		return m_Reason;
	}

};
//PvpBattleStart通知封装类
class PvpRpcPvpBattleStartNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPvpBattleStartNotifyWraper()
	{
		
		m_LeftKill = -1;
		m_RightKill = -1;
		m_NeedKill = -1;

	}
	//赋值构造函数
	PvpRpcPvpBattleStartNotifyWraper(const PvpRpcPvpBattleStartNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPvpBattleStartNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPvpBattleStartNotify ToPB() const
	{
		PvpRpcPvpBattleStartNotify v;
		v.set_leftkill( m_LeftKill );
		v.set_rightkill( m_RightKill );
		v.set_needkill( m_NeedKill );

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
		PvpRpcPvpBattleStartNotify pb;
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
	void Init(const PvpRpcPvpBattleStartNotify& v)
	{
		m_LeftKill = v.leftkill();
		m_RightKill = v.rightkill();
		m_NeedKill = v.needkill();

	}

private:
	//左侧阵营击杀数量
	INT32 m_LeftKill;
public:
	void SetLeftKill( INT32 v)
	{
		m_LeftKill=v;
	}
	INT32 GetLeftKill()
	{
		return m_LeftKill;
	}
	INT32 GetLeftKill() const
	{
		return m_LeftKill;
	}
private:
	//右侧阵营击杀数量
	INT32 m_RightKill;
public:
	void SetRightKill( INT32 v)
	{
		m_RightKill=v;
	}
	INT32 GetRightKill()
	{
		return m_RightKill;
	}
	INT32 GetRightKill() const
	{
		return m_RightKill;
	}
private:
	//需要击杀多少人
	INT32 m_NeedKill;
public:
	void SetNeedKill( INT32 v)
	{
		m_NeedKill=v;
	}
	INT32 GetNeedKill()
	{
		return m_NeedKill;
	}
	INT32 GetNeedKill() const
	{
		return m_NeedKill;
	}

};
//PvpBattleEnd通知封装类
class PvpRpcPvpBattleEndNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPvpBattleEndNotifyWraper()
	{
		
		m_BattleEndInfo = PvpBattleEndInfoWraper();

	}
	//赋值构造函数
	PvpRpcPvpBattleEndNotifyWraper(const PvpRpcPvpBattleEndNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPvpBattleEndNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPvpBattleEndNotify ToPB() const
	{
		PvpRpcPvpBattleEndNotify v;
		*v.mutable_battleendinfo()= m_BattleEndInfo.ToPB();

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
		PvpRpcPvpBattleEndNotify pb;
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
	void Init(const PvpRpcPvpBattleEndNotify& v)
	{
		m_BattleEndInfo = v.battleendinfo();

	}

private:
	//结算信息
	PvpBattleEndInfoWraper m_BattleEndInfo;
public:
	void SetBattleEndInfo( const PvpBattleEndInfoWraper& v)
	{
		m_BattleEndInfo=v;
	}
	PvpBattleEndInfoWraper GetBattleEndInfo()
	{
		return m_BattleEndInfo;
	}
	PvpBattleEndInfoWraper GetBattleEndInfo() const
	{
		return m_BattleEndInfo;
	}

};
//匹配完成通知封装类
class PvpRpcMatchSucessNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcMatchSucessNotifyWraper()
	{
		
		m_Time = -1;

	}
	//赋值构造函数
	PvpRpcMatchSucessNotifyWraper(const PvpRpcMatchSucessNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcMatchSucessNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcMatchSucessNotify ToPB() const
	{
		PvpRpcMatchSucessNotify v;
		v.mutable_leftteam()->Reserve(m_LeftTeam.size());
		for (int i=0; i<(int)m_LeftTeam.size(); i++)
		{
			*v.add_leftteam() = m_LeftTeam[i].ToPB();
		}
		v.mutable_rightteam()->Reserve(m_RightTeam.size());
		for (int i=0; i<(int)m_RightTeam.size(); i++)
		{
			*v.add_rightteam() = m_RightTeam[i].ToPB();
		}
		v.set_time( m_Time );

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
		PvpRpcMatchSucessNotify pb;
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
	void Init(const PvpRpcMatchSucessNotify& v)
	{
		m_LeftTeam.clear();
		m_LeftTeam.reserve(v.leftteam_size());
		for( int i=0; i<v.leftteam_size(); i++)
			m_LeftTeam.push_back(v.leftteam(i));
		m_RightTeam.clear();
		m_RightTeam.reserve(v.rightteam_size());
		for( int i=0; i<v.rightteam_size(); i++)
			m_RightTeam.push_back(v.rightteam(i));
		m_Time = v.time();

	}

private:
	//左边队伍
	vector<PvpPlayerInfoWraper> m_LeftTeam;
public:
	int SizeLeftTeam()
	{
		return m_LeftTeam.size();
	}
	const vector<PvpPlayerInfoWraper>& GetLeftTeam() const
	{
		return m_LeftTeam;
	}
	PvpPlayerInfoWraper GetLeftTeam(int Index) const
	{
		if(Index<0 || Index>=(int)m_LeftTeam.size())
		{
			assert(false);
			return PvpPlayerInfoWraper();
		}
		return m_LeftTeam[Index];
	}
	void SetLeftTeam( const vector<PvpPlayerInfoWraper>& v )
	{
		m_LeftTeam=v;
	}
	void ClearLeftTeam( )
	{
		m_LeftTeam.clear();
	}
	void SetLeftTeam( int Index, const PvpPlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_LeftTeam.size())
		{
			assert(false);
			return;
		}
		m_LeftTeam[Index] = v;
	}
	void AddLeftTeam( const PvpPlayerInfoWraper& v )
	{
		m_LeftTeam.push_back(v);
	}
private:
	//右侧队伍
	vector<PvpPlayerInfoWraper> m_RightTeam;
public:
	int SizeRightTeam()
	{
		return m_RightTeam.size();
	}
	const vector<PvpPlayerInfoWraper>& GetRightTeam() const
	{
		return m_RightTeam;
	}
	PvpPlayerInfoWraper GetRightTeam(int Index) const
	{
		if(Index<0 || Index>=(int)m_RightTeam.size())
		{
			assert(false);
			return PvpPlayerInfoWraper();
		}
		return m_RightTeam[Index];
	}
	void SetRightTeam( const vector<PvpPlayerInfoWraper>& v )
	{
		m_RightTeam=v;
	}
	void ClearRightTeam( )
	{
		m_RightTeam.clear();
	}
	void SetRightTeam( int Index, const PvpPlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_RightTeam.size())
		{
			assert(false);
			return;
		}
		m_RightTeam[Index] = v;
	}
	void AddRightTeam( const PvpPlayerInfoWraper& v )
	{
		m_RightTeam.push_back(v);
	}
private:
	//倒计时
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}

};
//等待确认超时通知封装类
class PvpRpcReadyFaildNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcReadyFaildNotifyWraper()
	{
		
		m_Reason = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	PvpRpcReadyFaildNotifyWraper(const PvpRpcReadyFaildNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcReadyFaildNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcReadyFaildNotify ToPB() const
	{
		PvpRpcReadyFaildNotify v;
		v.set_reason( m_Reason );
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
		PvpRpcReadyFaildNotify pb;
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
	void Init(const PvpRpcReadyFaildNotify& v)
	{
		m_Reason = v.reason();
		m_RoleId = v.roleid();

	}

private:
	//原因
	INT32 m_Reason;
public:
	void SetReason( INT32 v)
	{
		m_Reason=v;
	}
	INT32 GetReason()
	{
		return m_Reason;
	}
	INT32 GetReason() const
	{
		return m_Reason;
	}
private:
	//角色ID
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
//PlayerReady请求封装类
class PvpRpcPlayerReadyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPlayerReadyAskWraper()
	{
		
		m_OpreationType = -1;

	}
	//赋值构造函数
	PvpRpcPlayerReadyAskWraper(const PvpRpcPlayerReadyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPlayerReadyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPlayerReadyAsk ToPB() const
	{
		PvpRpcPlayerReadyAsk v;
		v.set_opreationtype( m_OpreationType );

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
		PvpRpcPlayerReadyAsk pb;
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
	void Init(const PvpRpcPlayerReadyAsk& v)
	{
		m_OpreationType = v.opreationtype();

	}

private:
	//取消或确认
	INT32 m_OpreationType;
public:
	void SetOpreationType( INT32 v)
	{
		m_OpreationType=v;
	}
	INT32 GetOpreationType()
	{
		return m_OpreationType;
	}
	INT32 GetOpreationType() const
	{
		return m_OpreationType;
	}

};
//PlayerReady回应封装类
class PvpRpcPlayerReadyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPlayerReadyReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	PvpRpcPlayerReadyReplyWraper(const PvpRpcPlayerReadyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPlayerReadyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPlayerReadyReply ToPB() const
	{
		PvpRpcPlayerReadyReply v;
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
		PvpRpcPlayerReadyReply pb;
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
	void Init(const PvpRpcPlayerReadyReply& v)
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
//玩家准备的通知通知封装类
class PvpRpcPlayerReadyNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PvpRpcPlayerReadyNotifyNotifyWraper()
	{
		
		m_RoleId = 0;
		m_OpType = -1;

	}
	//赋值构造函数
	PvpRpcPlayerReadyNotifyNotifyWraper(const PvpRpcPlayerReadyNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpRpcPlayerReadyNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpRpcPlayerReadyNotifyNotify ToPB() const
	{
		PvpRpcPlayerReadyNotifyNotify v;
		v.set_roleid( m_RoleId );
		v.set_optype( m_OpType );

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
		PvpRpcPlayerReadyNotifyNotify pb;
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
	void Init(const PvpRpcPlayerReadyNotifyNotify& v)
	{
		m_RoleId = v.roleid();
		m_OpType = v.optype();

	}

private:
	//角色ID
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
	//操作类型
	INT32 m_OpType;
public:
	void SetOpType( INT32 v)
	{
		m_OpType=v;
	}
	INT32 GetOpType()
	{
		return m_OpType;
	}
	INT32 GetOpType() const
	{
		return m_OpType;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<PvpRpcMatchNotifyNotifyWraper>{ enum{ID=RPC_CODE_PVP_MATCHNOTIFY_NOTIFY};};
template<> struct MessageIdT<PvpRpcMatchCancleNotifyNotifyWraper>{ enum{ID=RPC_CODE_PVP_MATCHCANCLENOTIFY_NOTIFY};};
template<> struct MessageIdT<PvpRpcPvpBattleStartNotifyWraper>{ enum{ID=RPC_CODE_PVP_PVPBATTLESTART_NOTIFY};};
template<> struct MessageIdT<PvpRpcPvpBattleEndNotifyWraper>{ enum{ID=RPC_CODE_PVP_PVPBATTLEEND_NOTIFY};};
template<> struct MessageIdT<PvpRpcPlayerReadyNotifyNotifyWraper>{ enum{ID=RPC_CODE_PVP_PLAYERREADYNOTIFY_NOTIFY};};
template<> struct MessageIdT<PvpRpcReadyFaildNotifyWraper>{ enum{ID=RPC_CODE_PVP_READYFAILD_NOTIFY};};
template<> struct MessageIdT<PvpRpcMatchSucessNotifyWraper>{ enum{ID=RPC_CODE_PVP_MATCHSUCESS_NOTIFY};};
template<> struct MessageIdT<PvpRpcRankChangeNotifyWraper>{ enum{ID=RPC_CODE_PVP_RANKCHANGE_NOTIFY};};
template<> struct MessageIdT<PvpRpcArenaStartTimeNotifyWraper>{ enum{ID=RPC_CODE_PVP_ARENASTARTTIME_NOTIFY};};
template<> struct MessageIdT<PvpRpcUpdateKillCountNotifyWraper>{ enum{ID=RPC_CODE_PVP_UPDATEKILLCOUNT_NOTIFY};};
template<> struct MessageIdT<PvpRpcArenaLeftTimeNotifyWraper>{ enum{ID=RPC_CODE_PVP_ARENALEFTTIME_NOTIFY};};
template<> struct MessageIdT<PvpRpcNewSeasonNotifyWraper>{ enum{ID=RPC_CODE_PVP_NEWSEASON_NOTIFY};};
template<> struct MessageIdT<PvpRpcReconnectNotifyWraper>{ enum{ID=RPC_CODE_PVP_RECONNECT_NOTIFY};};


#endif
