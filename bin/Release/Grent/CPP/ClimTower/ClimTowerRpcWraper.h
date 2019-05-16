/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperClimTower.h
* Author:       甘业清
* Description:  爬塔玩法RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_CLIMTOWER_H
#define __RPC_WRAPER_CLIMTOWER_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ClimTowerRpc.pb.h"



//爬塔玩法类的枚举定义
enum ConstClimTowerE
{
	MODULE_ID_CLIMTOWER                          = 47,	//爬塔玩法模块ID
	RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY           = 4751,	//爬塔玩法-->玩法开启规则-->通知
	RPC_CODE_CLIMTOWER_ENTER_REQUEST             = 4752,	//爬塔玩法-->进入爬塔活动-->请求
	RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST         = 4753,	//爬塔玩法-->挑战-->请求
	RPC_CODE_CLIMTOWER_RANK_REQUEST              = 4754,	//爬塔玩法-->获取排行榜信息-->请求
	RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST    = 4755,	//爬塔玩法-->首次通关奖励领奖-->请求
	RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY          = 4756,	//爬塔玩法-->下一层通知-->通知
	RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY       = 4757,	//爬塔玩法-->挑战结束-->通知
	RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY        = 4758,	//爬塔玩法-->每波怪物刷新通知-->通知


};


//首次通关奖励领奖回应封装类
class ClimTowerRpcFirstVicRewardReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcFirstVicRewardReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ClimTowerRpcFirstVicRewardReplyWraper(const ClimTowerRpcFirstVicRewardReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcFirstVicRewardReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcFirstVicRewardReply ToPB() const
	{
		ClimTowerRpcFirstVicRewardReply v;
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
		ClimTowerRpcFirstVicRewardReply pb;
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
	void Init(const ClimTowerRpcFirstVicRewardReply& v)
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
//首次通关奖励领奖请求封装类
class ClimTowerRpcFirstVicRewardAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcFirstVicRewardAskWraper()
	{
		
		m_Layer = -1;

	}
	//赋值构造函数
	ClimTowerRpcFirstVicRewardAskWraper(const ClimTowerRpcFirstVicRewardAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcFirstVicRewardAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcFirstVicRewardAsk ToPB() const
	{
		ClimTowerRpcFirstVicRewardAsk v;
		v.set_layer( m_Layer );

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
		ClimTowerRpcFirstVicRewardAsk pb;
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
	void Init(const ClimTowerRpcFirstVicRewardAsk& v)
	{
		m_Layer = v.layer();

	}

private:
	//领取哪一层奖励
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}

};
//获取排行榜信息回应封装类
class ClimTowerRpcRankReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcRankReplyWraper()
	{
		
		m_Result = -1;

	}
	//赋值构造函数
	ClimTowerRpcRankReplyWraper(const ClimTowerRpcRankReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcRankReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcRankReply ToPB() const
	{
		ClimTowerRpcRankReply v;
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
		ClimTowerRpcRankReply pb;
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
	void Init(const ClimTowerRpcRankReply& v)
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
//每波怪物刷新通知通知封装类
class ClimTowerRpcWaveRefreshNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcWaveRefreshNotifyWraper()
	{
		
		m_AllWaves = -1;
		m_CurWave = -1;

	}
	//赋值构造函数
	ClimTowerRpcWaveRefreshNotifyWraper(const ClimTowerRpcWaveRefreshNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcWaveRefreshNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcWaveRefreshNotify ToPB() const
	{
		ClimTowerRpcWaveRefreshNotify v;
		v.set_allwaves( m_AllWaves );
		v.set_curwave( m_CurWave );

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
		ClimTowerRpcWaveRefreshNotify pb;
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
	void Init(const ClimTowerRpcWaveRefreshNotify& v)
	{
		m_AllWaves = v.allwaves();
		m_CurWave = v.curwave();

	}

private:
	//总共几波怪物
	INT32 m_AllWaves;
public:
	void SetAllWaves( INT32 v)
	{
		m_AllWaves=v;
	}
	INT32 GetAllWaves()
	{
		return m_AllWaves;
	}
	INT32 GetAllWaves() const
	{
		return m_AllWaves;
	}
private:
	//当前怪物波数
	INT32 m_CurWave;
public:
	void SetCurWave( INT32 v)
	{
		m_CurWave=v;
	}
	INT32 GetCurWave()
	{
		return m_CurWave;
	}
	INT32 GetCurWave() const
	{
		return m_CurWave;
	}

};
//挑战结束通知封装类
class ClimTowerRpcChallengeEndNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcChallengeEndNotifyWraper()
	{
		

	}
	//赋值构造函数
	ClimTowerRpcChallengeEndNotifyWraper(const ClimTowerRpcChallengeEndNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcChallengeEndNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcChallengeEndNotify ToPB() const
	{
		ClimTowerRpcChallengeEndNotify v;

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
		ClimTowerRpcChallengeEndNotify pb;
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
	void Init(const ClimTowerRpcChallengeEndNotify& v)
	{

	}


};
//下一层通知通知封装类
class ClimTowerRpcNextLayerNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcNextLayerNotifyWraper()
	{
		
		m_CurLayer = -1;

	}
	//赋值构造函数
	ClimTowerRpcNextLayerNotifyWraper(const ClimTowerRpcNextLayerNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcNextLayerNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcNextLayerNotify ToPB() const
	{
		ClimTowerRpcNextLayerNotify v;
		v.set_curlayer( m_CurLayer );

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
		ClimTowerRpcNextLayerNotify pb;
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
	void Init(const ClimTowerRpcNextLayerNotify& v)
	{
		m_CurLayer = v.curlayer();

	}

private:
	//当前层
	INT32 m_CurLayer;
public:
	void SetCurLayer( INT32 v)
	{
		m_CurLayer=v;
	}
	INT32 GetCurLayer()
	{
		return m_CurLayer;
	}
	INT32 GetCurLayer() const
	{
		return m_CurLayer;
	}

};
//挑战回应封装类
class ClimTowerRpcChallengeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcChallengeReplyWraper()
	{
		
		m_Result = -1;
		m_DungeonId = -1;
		m_SceneId = -1;
		m_WayPoint = -1;

	}
	//赋值构造函数
	ClimTowerRpcChallengeReplyWraper(const ClimTowerRpcChallengeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcChallengeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcChallengeReply ToPB() const
	{
		ClimTowerRpcChallengeReply v;
		v.set_result( m_Result );
		v.set_dungeonid( m_DungeonId );
		v.set_sceneid( m_SceneId );
		v.set_waypoint( m_WayPoint );

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
		ClimTowerRpcChallengeReply pb;
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
	void Init(const ClimTowerRpcChallengeReply& v)
	{
		m_Result = v.result();
		m_DungeonId = v.dungeonid();
		m_SceneId = v.sceneid();
		m_WayPoint = v.waypoint();

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
	//副本id
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//场景id
	INT32 m_SceneId;
public:
	void SetSceneId( INT32 v)
	{
		m_SceneId=v;
	}
	INT32 GetSceneId()
	{
		return m_SceneId;
	}
	INT32 GetSceneId() const
	{
		return m_SceneId;
	}
private:
	//路点
	INT32 m_WayPoint;
public:
	void SetWayPoint( INT32 v)
	{
		m_WayPoint=v;
	}
	INT32 GetWayPoint()
	{
		return m_WayPoint;
	}
	INT32 GetWayPoint() const
	{
		return m_WayPoint;
	}

};
//挑战请求封装类
class ClimTowerRpcChallengeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcChallengeAskWraper()
	{
		
		m_Layer = 1;

	}
	//赋值构造函数
	ClimTowerRpcChallengeAskWraper(const ClimTowerRpcChallengeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcChallengeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcChallengeAsk ToPB() const
	{
		ClimTowerRpcChallengeAsk v;
		v.set_layer( m_Layer );

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
		ClimTowerRpcChallengeAsk pb;
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
	void Init(const ClimTowerRpcChallengeAsk& v)
	{
		m_Layer = v.layer();

	}

private:
	//挑战层
	INT32 m_Layer;
public:
	void SetLayer( INT32 v)
	{
		m_Layer=v;
	}
	INT32 GetLayer()
	{
		return m_Layer;
	}
	INT32 GetLayer() const
	{
		return m_Layer;
	}

};
//玩法开启规则通知封装类
class ClimTowerRpcOpenRuleNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcOpenRuleNotifyWraper()
	{
		

	}
	//赋值构造函数
	ClimTowerRpcOpenRuleNotifyWraper(const ClimTowerRpcOpenRuleNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcOpenRuleNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcOpenRuleNotify ToPB() const
	{
		ClimTowerRpcOpenRuleNotify v;

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
		ClimTowerRpcOpenRuleNotify pb;
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
	void Init(const ClimTowerRpcOpenRuleNotify& v)
	{

	}


};
//获取排行榜信息请求封装类
class ClimTowerRpcRankAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcRankAskWraper()
	{
		

	}
	//赋值构造函数
	ClimTowerRpcRankAskWraper(const ClimTowerRpcRankAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcRankAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcRankAsk ToPB() const
	{
		ClimTowerRpcRankAsk v;

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
		ClimTowerRpcRankAsk pb;
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
	void Init(const ClimTowerRpcRankAsk& v)
	{

	}


};
//进入爬塔活动回应封装类
class ClimTowerRpcEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcEnterReplyWraper()
	{
		
		m_Result = -1;
		m_EnterInfo = ClimTowerInfoWraper();
		m_RemainTimes = 0;

	}
	//赋值构造函数
	ClimTowerRpcEnterReplyWraper(const ClimTowerRpcEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcEnterReply ToPB() const
	{
		ClimTowerRpcEnterReply v;
		v.set_result( m_Result );
		*v.mutable_enterinfo()= m_EnterInfo.ToPB();
		v.set_remaintimes( m_RemainTimes );

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
		ClimTowerRpcEnterReply pb;
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
	void Init(const ClimTowerRpcEnterReply& v)
	{
		m_Result = v.result();
		m_EnterInfo = v.enterinfo();
		m_RemainTimes = v.remaintimes();

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
	//进入爬塔挑战
	ClimTowerInfoWraper m_EnterInfo;
public:
	void SetEnterInfo( const ClimTowerInfoWraper& v)
	{
		m_EnterInfo=v;
	}
	ClimTowerInfoWraper GetEnterInfo()
	{
		return m_EnterInfo;
	}
	ClimTowerInfoWraper GetEnterInfo() const
	{
		return m_EnterInfo;
	}
private:
	//剩余挑战次数
	INT32 m_RemainTimes;
public:
	void SetRemainTimes( INT32 v)
	{
		m_RemainTimes=v;
	}
	INT32 GetRemainTimes()
	{
		return m_RemainTimes;
	}
	INT32 GetRemainTimes() const
	{
		return m_RemainTimes;
	}

};
//进入爬塔活动请求封装类
class ClimTowerRpcEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ClimTowerRpcEnterAskWraper()
	{
		

	}
	//赋值构造函数
	ClimTowerRpcEnterAskWraper(const ClimTowerRpcEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerRpcEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerRpcEnterAsk ToPB() const
	{
		ClimTowerRpcEnterAsk v;

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
		ClimTowerRpcEnterAsk pb;
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
	void Init(const ClimTowerRpcEnterAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ClimTowerRpcOpenRuleNotifyWraper>{ enum{ID=RPC_CODE_CLIMTOWER_OPENRULE_NOTIFY};};
template<> struct MessageIdT<ClimTowerRpcNextLayerNotifyWraper>{ enum{ID=RPC_CODE_CLIMTOWER_NEXTLAYER_NOTIFY};};
template<> struct MessageIdT<ClimTowerRpcChallengeEndNotifyWraper>{ enum{ID=RPC_CODE_CLIMTOWER_CHALLENGEEND_NOTIFY};};
template<> struct MessageIdT<ClimTowerRpcWaveRefreshNotifyWraper>{ enum{ID=RPC_CODE_CLIMTOWER_WAVEREFRESH_NOTIFY};};


#endif
