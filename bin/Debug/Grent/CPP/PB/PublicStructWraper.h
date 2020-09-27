/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     PubWraperClass.h
* Author:       郭晓波
* Description:  公共数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __PUB_WRAPER_CLASS_H
#define __PUB_WRAPER_CLASS_H

#include "BASE.h"
#include "PublicStruct.pb.h"
#include "DataWraperInterface.h"



//AttrKeyValue封装类
class AttrKeyValueWraper
{
public:
	//构造函数
	AttrKeyValueWraper()
	{
		
		m_Key = -1;
		m_Value = -1;
		m_Quality = -1;
		m_Key2 = -1;

	}
	//赋值构造函数
	AttrKeyValueWraper(const AttrKeyValue& v){ Init(v); }
	//等号重载函数
	void operator = (const AttrKeyValue& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AttrKeyValue ToPB() const
	{
		AttrKeyValue v;
		v.set_key( m_Key );
		v.set_value( m_Value );
		v.set_quality( m_Quality );
		v.set_key2( m_Key2 );

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
		AttrKeyValue pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AttrKeyValue& v)
	{
		m_Key = v.key();
		m_Value = v.value();
		m_Quality = v.quality();
		m_Key2 = v.key2();

	}

private:
	//属性的key
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//Value
	int64_t m_Value;
public:
	void SetValue( int64_t v)
	{
		m_Value=v;
	}
	int64_t GetValue()
	{
		return m_Value;
	}
	int64_t GetValue() const
	{
		return m_Value;
	}
private:
	//quality
	INT32 m_Quality;
public:
	void SetQuality( INT32 v)
	{
		m_Quality=v;
	}
	INT32 GetQuality()
	{
		return m_Quality;
	}
	INT32 GetQuality() const
	{
		return m_Quality;
	}
private:
	//附加key
	INT32 m_Key2;
public:
	void SetKey2( INT32 v)
	{
		m_Key2=v;
	}
	INT32 GetKey2()
	{
		return m_Key2;
	}
	INT32 GetKey2() const
	{
		return m_Key2;
	}

};
//颜色封装类
class ColorWraper
{
public:
	//构造函数
	ColorWraper()
	{
		
		m_R = -1;
		m_G = -1;
		m_B = -1;
		m_A = -1;

	}
	//赋值构造函数
	ColorWraper(const Color& v){ Init(v); }
	//等号重载函数
	void operator = (const Color& v){ Init(v); }
 	//转化成Protobuffer类型函数
	Color ToPB() const
	{
		Color v;
		v.set_r( m_R );
		v.set_g( m_G );
		v.set_b( m_B );
		v.set_a( m_A );

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
		Color pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const Color& v)
	{
		m_R = v.r();
		m_G = v.g();
		m_B = v.b();
		m_A = v.a();

	}

private:
	//红
	float m_R;
public:
	void SetR( float v)
	{
		m_R=v;
	}
	float GetR()
	{
		return m_R;
	}
	float GetR() const
	{
		return m_R;
	}
private:
	//绿
	float m_G;
public:
	void SetG( float v)
	{
		m_G=v;
	}
	float GetG()
	{
		return m_G;
	}
	float GetG() const
	{
		return m_G;
	}
private:
	//蓝
	float m_B;
public:
	void SetB( float v)
	{
		m_B=v;
	}
	float GetB()
	{
		return m_B;
	}
	float GetB() const
	{
		return m_B;
	}
private:
	//透明度
	float m_A;
public:
	void SetA( float v)
	{
		m_A=v;
	}
	float GetA()
	{
		return m_A;
	}
	float GetA() const
	{
		return m_A;
	}

};
//宠物成长度封装类
class PetFeedDataWraper
{
public:
	//构造函数
	PetFeedDataWraper()
	{
		
		m_Level = 0;
		m_Exp = 0;
		m_FeedCount = 0;

	}
	//赋值构造函数
	PetFeedDataWraper(const PetFeedData& v){ Init(v); }
	//等号重载函数
	void operator = (const PetFeedData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetFeedData ToPB() const
	{
		PetFeedData v;
		v.set_level( m_Level );
		v.set_exp( m_Exp );
		v.set_feedcount( m_FeedCount );

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
		PetFeedData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PetFeedData& v)
	{
		m_Level = v.level();
		m_Exp = v.exp();
		m_FeedCount = v.feedcount();

	}

private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//经验
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
	//今日喂养次数
	INT32 m_FeedCount;
public:
	void SetFeedCount( INT32 v)
	{
		m_FeedCount=v;
	}
	INT32 GetFeedCount()
	{
		return m_FeedCount;
	}
	INT32 GetFeedCount() const
	{
		return m_FeedCount;
	}

};
//宠物被动技能封装类
class PetSkillWraper
{
public:
	//构造函数
	PetSkillWraper()
	{
		
		m_SkillId = -1;
		m_Lock = -1;

	}
	//赋值构造函数
	PetSkillWraper(const PetSkill& v){ Init(v); }
	//等号重载函数
	void operator = (const PetSkill& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetSkill ToPB() const
	{
		PetSkill v;
		v.set_skillid( m_SkillId );
		v.set_lock( m_Lock );

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
		PetSkill pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PetSkill& v)
	{
		m_SkillId = v.skillid();
		m_Lock = v.lock();

	}

private:
	//技能id
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
private:
	//宠物技能锁 0未加锁1加锁
	INT32 m_Lock;
public:
	void SetLock( INT32 v)
	{
		m_Lock=v;
	}
	INT32 GetLock()
	{
		return m_Lock;
	}
	INT32 GetLock() const
	{
		return m_Lock;
	}

};
//v3封装类
class Vector3Wraper
{
public:
	//构造函数
	Vector3Wraper()
	{
		
		m_X = -1;
		m_Y = -1;
		m_Z = -1;

	}
	//赋值构造函数
	Vector3Wraper(const Vector3& v){ Init(v); }
	//等号重载函数
	void operator = (const Vector3& v){ Init(v); }
 	//转化成Protobuffer类型函数
	Vector3 ToPB() const
	{
		Vector3 v;
		v.set_x( m_X );
		v.set_y( m_Y );
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
		Vector3 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const Vector3& v)
	{
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();

	}

private:
	//x
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
	//y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}
private:
	//z
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
//EquipAttr封装类
class EquipAttrWraper
{
public:
	//构造函数
	EquipAttrWraper()
	{
		
		m_BattleScore = -1;

	}
	//赋值构造函数
	EquipAttrWraper(const EquipAttr& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipAttr& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipAttr ToPB() const
	{
		EquipAttr v;
		v.mutable_baseattr()->Reserve(m_BaseAttr.size());
		for (int i=0; i<(int)m_BaseAttr.size(); i++)
		{
			*v.add_baseattr() = m_BaseAttr[i].ToPB();
		}
		v.mutable_extraattr()->Reserve(m_ExtraAttr.size());
		for (int i=0; i<(int)m_ExtraAttr.size(); i++)
		{
			*v.add_extraattr() = m_ExtraAttr[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );

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
		EquipAttr pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipAttr& v)
	{
		m_BaseAttr.clear();
		m_BaseAttr.reserve(v.baseattr_size());
		for( int i=0; i<v.baseattr_size(); i++)
			m_BaseAttr.push_back(v.baseattr(i));
		m_ExtraAttr.clear();
		m_ExtraAttr.reserve(v.extraattr_size());
		for( int i=0; i<v.extraattr_size(); i++)
			m_ExtraAttr.push_back(v.extraattr(i));
		m_BattleScore = v.battlescore();

	}

private:
	//基础属性
	vector<AttrKeyValueWraper> m_BaseAttr;
public:
	int SizeBaseAttr()
	{
		return m_BaseAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetBaseAttr() const
	{
		return m_BaseAttr;
	}
	AttrKeyValueWraper GetBaseAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_BaseAttr[Index];
	}
	void SetBaseAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_BaseAttr=v;
	}
	void ClearBaseAttr( )
	{
		m_BaseAttr.clear();
	}
	void SetBaseAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_BaseAttr.size())
		{
			assert(false);
			return;
		}
		m_BaseAttr[Index] = v;
	}
	void AddBaseAttr( const AttrKeyValueWraper& v )
	{
		m_BaseAttr.push_back(v);
	}
private:
	//高级属性
	vector<AttrKeyValueWraper> m_ExtraAttr;
public:
	int SizeExtraAttr()
	{
		return m_ExtraAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetExtraAttr() const
	{
		return m_ExtraAttr;
	}
	AttrKeyValueWraper GetExtraAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_ExtraAttr[Index];
	}
	void SetExtraAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_ExtraAttr=v;
	}
	void ClearExtraAttr( )
	{
		m_ExtraAttr.clear();
	}
	void SetExtraAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return;
		}
		m_ExtraAttr[Index] = v;
	}
	void AddExtraAttr( const AttrKeyValueWraper& v )
	{
		m_ExtraAttr.push_back(v);
	}
private:
	//装备评分
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}

};
//精炼数据封装类
class RefineDataWraper
{
public:
	//构造函数
	RefineDataWraper()
	{
		
		m_Level = 0;
		m_Extend = 0;

	}
	//赋值构造函数
	RefineDataWraper(const RefineData& v){ Init(v); }
	//等号重载函数
	void operator = (const RefineData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RefineData ToPB() const
	{
		RefineData v;
		v.set_level( m_Level );
		v.set_extend( m_Extend );

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
		RefineData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RefineData& v)
	{
		m_Level = v.level();
		m_Extend = v.extend();

	}

private:
	//精炼等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//精炼度
	INT32 m_Extend;
public:
	void SetExtend( INT32 v)
	{
		m_Extend=v;
	}
	INT32 GetExtend()
	{
		return m_Extend;
	}
	INT32 GetExtend() const
	{
		return m_Extend;
	}

};
//捏脸基础结构封装类
class PinchFaceBaseWraper
{
public:
	//构造函数
	PinchFaceBaseWraper()
	{
		
		m_Id = -1;
		m_Value = -1;
		m_Color = ColorWraper();

	}
	//赋值构造函数
	PinchFaceBaseWraper(const PinchFaceBase& v){ Init(v); }
	//等号重载函数
	void operator = (const PinchFaceBase& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PinchFaceBase ToPB() const
	{
		PinchFaceBase v;
		v.set_id( m_Id );
		v.set_value( m_Value );
		*v.mutable_color()= m_Color.ToPB();

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
		PinchFaceBase pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PinchFaceBase& v)
	{
		m_Id = v.id();
		m_Value = v.value();
		m_Color = v.color();

	}

private:
	//配置id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//值
	float m_Value;
public:
	void SetValue( float v)
	{
		m_Value=v;
	}
	float GetValue()
	{
		return m_Value;
	}
	float GetValue() const
	{
		return m_Value;
	}
private:
	//颜色
	ColorWraper m_Color;
public:
	void SetColor( const ColorWraper& v)
	{
		m_Color=v;
	}
	ColorWraper GetColor()
	{
		return m_Color;
	}
	ColorWraper GetColor() const
	{
		return m_Color;
	}

};
//宠物数据封装类
class PetDataWraper
{
public:
	//构造函数
	PetDataWraper()
	{
		
		m_Exp = -1;
		m_Level = -1;
		m_Name = "";
		m_BattleScore = -1;
		m_TalentScore = -1;
		m_Wild = false;
		m_FeedData = PetFeedDataWraper();

	}
	//赋值构造函数
	PetDataWraper(const PetData& v){ Init(v); }
	//等号重载函数
	void operator = (const PetData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetData ToPB() const
	{
		PetData v;
		v.set_exp( m_Exp );
		v.set_level( m_Level );
		v.set_name( m_Name );
		v.mutable_attrs()->Reserve(m_Attrs.size());
		for (int i=0; i<(int)m_Attrs.size(); i++)
		{
			*v.add_attrs() = m_Attrs[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );
		v.mutable_talent()->Reserve(m_Talent.size());
		for (int i=0; i<(int)m_Talent.size(); i++)
		{
			*v.add_talent() = m_Talent[i].ToPB();
		}
		v.mutable_skilllist()->Reserve(m_SkillList.size());
		for (int i=0; i<(int)m_SkillList.size(); i++)
		{
			*v.add_skilllist() = m_SkillList[i].ToPB();
		}
		v.set_talentscore( m_TalentScore );
		v.set_wild( m_Wild );
		*v.mutable_feeddata()= m_FeedData.ToPB();

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
		PetData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PetData& v)
	{
		m_Exp = v.exp();
		m_Level = v.level();
		m_Name = v.name();
		m_Attrs.clear();
		m_Attrs.reserve(v.attrs_size());
		for( int i=0; i<v.attrs_size(); i++)
			m_Attrs.push_back(v.attrs(i));
		m_BattleScore = v.battlescore();
		m_Talent.clear();
		m_Talent.reserve(v.talent_size());
		for( int i=0; i<v.talent_size(); i++)
			m_Talent.push_back(v.talent(i));
		m_SkillList.clear();
		m_SkillList.reserve(v.skilllist_size());
		for( int i=0; i<v.skilllist_size(); i++)
			m_SkillList.push_back(v.skilllist(i));
		m_TalentScore = v.talentscore();
		m_Wild = v.wild();
		m_FeedData = v.feeddata();

	}

private:
	//经验
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
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
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
	//属性
	vector<AttrKeyValueWraper> m_Attrs;
public:
	int SizeAttrs()
	{
		return m_Attrs.size();
	}
	const vector<AttrKeyValueWraper>& GetAttrs() const
	{
		return m_Attrs;
	}
	AttrKeyValueWraper GetAttrs(int Index) const
	{
		if(Index<0 || Index>=(int)m_Attrs.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_Attrs[Index];
	}
	void SetAttrs( const vector<AttrKeyValueWraper>& v )
	{
		m_Attrs=v;
	}
	void ClearAttrs( )
	{
		m_Attrs.clear();
	}
	void SetAttrs( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_Attrs.size())
		{
			assert(false);
			return;
		}
		m_Attrs[Index] = v;
	}
	void AddAttrs( const AttrKeyValueWraper& v )
	{
		m_Attrs.push_back(v);
	}
private:
	//战力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//资质
	vector<AttrKeyValueWraper> m_Talent;
public:
	int SizeTalent()
	{
		return m_Talent.size();
	}
	const vector<AttrKeyValueWraper>& GetTalent() const
	{
		return m_Talent;
	}
	AttrKeyValueWraper GetTalent(int Index) const
	{
		if(Index<0 || Index>=(int)m_Talent.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_Talent[Index];
	}
	void SetTalent( const vector<AttrKeyValueWraper>& v )
	{
		m_Talent=v;
	}
	void ClearTalent( )
	{
		m_Talent.clear();
	}
	void SetTalent( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_Talent.size())
		{
			assert(false);
			return;
		}
		m_Talent[Index] = v;
	}
	void AddTalent( const AttrKeyValueWraper& v )
	{
		m_Talent.push_back(v);
	}
private:
	//技能列表
	vector<PetSkillWraper> m_SkillList;
public:
	int SizeSkillList()
	{
		return m_SkillList.size();
	}
	const vector<PetSkillWraper>& GetSkillList() const
	{
		return m_SkillList;
	}
	PetSkillWraper GetSkillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return PetSkillWraper();
		}
		return m_SkillList[Index];
	}
	void SetSkillList( const vector<PetSkillWraper>& v )
	{
		m_SkillList=v;
	}
	void ClearSkillList( )
	{
		m_SkillList.clear();
	}
	void SetSkillList( int Index, const PetSkillWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return;
		}
		m_SkillList[Index] = v;
	}
	void AddSkillList( const PetSkillWraper& v )
	{
		m_SkillList.push_back(v);
	}
private:
	//资质评分
	INT32 m_TalentScore;
public:
	void SetTalentScore( INT32 v)
	{
		m_TalentScore=v;
	}
	INT32 GetTalentScore()
	{
		return m_TalentScore;
	}
	INT32 GetTalentScore() const
	{
		return m_TalentScore;
	}
private:
	//是否野生
	bool m_Wild;
public:
	void SetWild( bool v)
	{
		m_Wild=v;
	}
	bool GetWild()
	{
		return m_Wild;
	}
	bool GetWild() const
	{
		return m_Wild;
	}
private:
	//宠物喂养数据
	PetFeedDataWraper m_FeedData;
public:
	void SetFeedData( const PetFeedDataWraper& v)
	{
		m_FeedData=v;
	}
	PetFeedDataWraper GetFeedData()
	{
		return m_FeedData;
	}
	PetFeedDataWraper GetFeedData() const
	{
		return m_FeedData;
	}

};
//魂石数据封装类
class SoulStoneDataWraper
{
public:
	//构造函数
	SoulStoneDataWraper()
	{
		
		m_SuitId = -1;
		m_BattleScore = 0;

	}
	//赋值构造函数
	SoulStoneDataWraper(const SoulStoneData& v){ Init(v); }
	//等号重载函数
	void operator = (const SoulStoneData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SoulStoneData ToPB() const
	{
		SoulStoneData v;
		v.mutable_attr()->Reserve(m_Attr.size());
		for (int i=0; i<(int)m_Attr.size(); i++)
		{
			*v.add_attr() = m_Attr[i].ToPB();
		}
		v.set_suitid( m_SuitId );
		v.set_battlescore( m_BattleScore );

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
		SoulStoneData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SoulStoneData& v)
	{
		m_Attr.clear();
		m_Attr.reserve(v.attr_size());
		for( int i=0; i<v.attr_size(); i++)
			m_Attr.push_back(v.attr(i));
		m_SuitId = v.suitid();
		m_BattleScore = v.battlescore();

	}

private:
	//属性
	vector<AttrKeyValueWraper> m_Attr;
public:
	int SizeAttr()
	{
		return m_Attr.size();
	}
	const vector<AttrKeyValueWraper>& GetAttr() const
	{
		return m_Attr;
	}
	AttrKeyValueWraper GetAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_Attr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_Attr[Index];
	}
	void SetAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_Attr=v;
	}
	void ClearAttr( )
	{
		m_Attr.clear();
	}
	void SetAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_Attr.size())
		{
			assert(false);
			return;
		}
		m_Attr[Index] = v;
	}
	void AddAttr( const AttrKeyValueWraper& v )
	{
		m_Attr.push_back(v);
	}
private:
	//套装id
	INT32 m_SuitId;
public:
	void SetSuitId( INT32 v)
	{
		m_SuitId=v;
	}
	INT32 GetSuitId()
	{
		return m_SuitId;
	}
	INT32 GetSuitId() const
	{
		return m_SuitId;
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}

};
//装备时装ID封装类
class TreasureEquipedIDWraper
{
public:
	//构造函数
	TreasureEquipedIDWraper()
	{
		
		m_TreasureHair = -1;
		m_TreasureHead = -1;
		m_TreasureBody = -1;
		m_TreasureWeapon = -1;
		m_TreasureWing = -1;
		m_TreasureRiding = -1;
		m_TreasureFootPrint = -1;
		m_EquipHair = -1;
		m_EquipHead = -1;
		m_EquipBody = -1;
		m_EquipWeapon = -1;
		m_Headdisplayswitch = true;
		m_Fashiondisplayswitch = true;
		m_InitHair = -1;
		m_InitHead = -1;
		m_InitBody = -1;
		m_InitWeapon = -1;

	}
	//赋值构造函数
	TreasureEquipedIDWraper(const TreasureEquipedID& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureEquipedID& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureEquipedID ToPB() const
	{
		TreasureEquipedID v;
		v.set_treasurehair( m_TreasureHair );
		v.set_treasurehead( m_TreasureHead );
		v.set_treasurebody( m_TreasureBody );
		v.set_treasureweapon( m_TreasureWeapon );
		v.set_treasurewing( m_TreasureWing );
		v.set_treasureriding( m_TreasureRiding );
		v.set_treasurefootprint( m_TreasureFootPrint );
		v.set_equiphair( m_EquipHair );
		v.set_equiphead( m_EquipHead );
		v.set_equipbody( m_EquipBody );
		v.set_equipweapon( m_EquipWeapon );
		v.set_headdisplayswitch( m_Headdisplayswitch );
		v.set_fashiondisplayswitch( m_Fashiondisplayswitch );
		v.set_inithair( m_InitHair );
		v.set_inithead( m_InitHead );
		v.set_initbody( m_InitBody );
		v.set_initweapon( m_InitWeapon );

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
		TreasureEquipedID pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TreasureEquipedID& v)
	{
		m_TreasureHair = v.treasurehair();
		m_TreasureHead = v.treasurehead();
		m_TreasureBody = v.treasurebody();
		m_TreasureWeapon = v.treasureweapon();
		m_TreasureWing = v.treasurewing();
		m_TreasureRiding = v.treasureriding();
		m_TreasureFootPrint = v.treasurefootprint();
		m_EquipHair = v.equiphair();
		m_EquipHead = v.equiphead();
		m_EquipBody = v.equipbody();
		m_EquipWeapon = v.equipweapon();
		m_Headdisplayswitch = v.headdisplayswitch();
		m_Fashiondisplayswitch = v.fashiondisplayswitch();
		m_InitHair = v.inithair();
		m_InitHead = v.inithead();
		m_InitBody = v.initbody();
		m_InitWeapon = v.initweapon();

	}

private:
	//头发(时装)
	INT32 m_TreasureHair;
public:
	void SetTreasureHair( INT32 v)
	{
		m_TreasureHair=v;
	}
	INT32 GetTreasureHair()
	{
		return m_TreasureHair;
	}
	INT32 GetTreasureHair() const
	{
		return m_TreasureHair;
	}
private:
	//头部(时装)
	INT32 m_TreasureHead;
public:
	void SetTreasureHead( INT32 v)
	{
		m_TreasureHead=v;
	}
	INT32 GetTreasureHead()
	{
		return m_TreasureHead;
	}
	INT32 GetTreasureHead() const
	{
		return m_TreasureHead;
	}
private:
	//身体(时装)
	INT32 m_TreasureBody;
public:
	void SetTreasureBody( INT32 v)
	{
		m_TreasureBody=v;
	}
	INT32 GetTreasureBody()
	{
		return m_TreasureBody;
	}
	INT32 GetTreasureBody() const
	{
		return m_TreasureBody;
	}
private:
	//武器(时装)
	INT32 m_TreasureWeapon;
public:
	void SetTreasureWeapon( INT32 v)
	{
		m_TreasureWeapon=v;
	}
	INT32 GetTreasureWeapon()
	{
		return m_TreasureWeapon;
	}
	INT32 GetTreasureWeapon() const
	{
		return m_TreasureWeapon;
	}
private:
	//翅膀
	INT32 m_TreasureWing;
public:
	void SetTreasureWing( INT32 v)
	{
		m_TreasureWing=v;
	}
	INT32 GetTreasureWing()
	{
		return m_TreasureWing;
	}
	INT32 GetTreasureWing() const
	{
		return m_TreasureWing;
	}
private:
	//坐骑
	INT32 m_TreasureRiding;
public:
	void SetTreasureRiding( INT32 v)
	{
		m_TreasureRiding=v;
	}
	INT32 GetTreasureRiding()
	{
		return m_TreasureRiding;
	}
	INT32 GetTreasureRiding() const
	{
		return m_TreasureRiding;
	}
private:
	//步尘
	INT32 m_TreasureFootPrint;
public:
	void SetTreasureFootPrint( INT32 v)
	{
		m_TreasureFootPrint=v;
	}
	INT32 GetTreasureFootPrint()
	{
		return m_TreasureFootPrint;
	}
	INT32 GetTreasureFootPrint() const
	{
		return m_TreasureFootPrint;
	}
private:
	//头发(真实)(服务器存库用)
	INT32 m_EquipHair;
public:
	void SetEquipHair( INT32 v)
	{
		m_EquipHair=v;
	}
	INT32 GetEquipHair()
	{
		return m_EquipHair;
	}
	INT32 GetEquipHair() const
	{
		return m_EquipHair;
	}
private:
	//头部(真实)(服务器存库用)
	INT32 m_EquipHead;
public:
	void SetEquipHead( INT32 v)
	{
		m_EquipHead=v;
	}
	INT32 GetEquipHead()
	{
		return m_EquipHead;
	}
	INT32 GetEquipHead() const
	{
		return m_EquipHead;
	}
private:
	//身体(真实)(服务器存库用)
	INT32 m_EquipBody;
public:
	void SetEquipBody( INT32 v)
	{
		m_EquipBody=v;
	}
	INT32 GetEquipBody()
	{
		return m_EquipBody;
	}
	INT32 GetEquipBody() const
	{
		return m_EquipBody;
	}
private:
	//武器(真实)(服务器存库用)
	INT32 m_EquipWeapon;
public:
	void SetEquipWeapon( INT32 v)
	{
		m_EquipWeapon=v;
	}
	INT32 GetEquipWeapon()
	{
		return m_EquipWeapon;
	}
	INT32 GetEquipWeapon() const
	{
		return m_EquipWeapon;
	}
private:
	//头部显示开关
	bool m_Headdisplayswitch;
public:
	void SetHeaddisplayswitch( bool v)
	{
		m_Headdisplayswitch=v;
	}
	bool GetHeaddisplayswitch()
	{
		return m_Headdisplayswitch;
	}
	bool GetHeaddisplayswitch() const
	{
		return m_Headdisplayswitch;
	}
private:
	//时装显示开关
	bool m_Fashiondisplayswitch;
public:
	void SetFashiondisplayswitch( bool v)
	{
		m_Fashiondisplayswitch=v;
	}
	bool GetFashiondisplayswitch()
	{
		return m_Fashiondisplayswitch;
	}
	bool GetFashiondisplayswitch() const
	{
		return m_Fashiondisplayswitch;
	}
private:
	//默认头发(服务器存库用)
	INT32 m_InitHair;
public:
	void SetInitHair( INT32 v)
	{
		m_InitHair=v;
	}
	INT32 GetInitHair()
	{
		return m_InitHair;
	}
	INT32 GetInitHair() const
	{
		return m_InitHair;
	}
private:
	//默认脸(服务器存库用)
	INT32 m_InitHead;
public:
	void SetInitHead( INT32 v)
	{
		m_InitHead=v;
	}
	INT32 GetInitHead()
	{
		return m_InitHead;
	}
	INT32 GetInitHead() const
	{
		return m_InitHead;
	}
private:
	//默认护甲(服务器存库用)
	INT32 m_InitBody;
public:
	void SetInitBody( INT32 v)
	{
		m_InitBody=v;
	}
	INT32 GetInitBody()
	{
		return m_InitBody;
	}
	INT32 GetInitBody() const
	{
		return m_InitBody;
	}
private:
	//默认武器(服务器存库用)
	INT32 m_InitWeapon;
public:
	void SetInitWeapon( INT32 v)
	{
		m_InitWeapon=v;
	}
	INT32 GetInitWeapon()
	{
		return m_InitWeapon;
	}
	INT32 GetInitWeapon() const
	{
		return m_InitWeapon;
	}

};
//捏脸数据结构封装类
class PinchFaceDataWraper
{
public:
	//构造函数
	PinchFaceDataWraper()
	{
		

	}
	//赋值构造函数
	PinchFaceDataWraper(const PinchFaceData& v){ Init(v); }
	//等号重载函数
	void operator = (const PinchFaceData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PinchFaceData ToPB() const
	{
		PinchFaceData v;
		v.mutable_datainfo()->Reserve(m_DataInfo.size());
		for (int i=0; i<(int)m_DataInfo.size(); i++)
		{
			*v.add_datainfo() = m_DataInfo[i].ToPB();
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
		PinchFaceData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PinchFaceData& v)
	{
		m_DataInfo.clear();
		m_DataInfo.reserve(v.datainfo_size());
		for( int i=0; i<v.datainfo_size(); i++)
			m_DataInfo.push_back(v.datainfo(i));

	}

private:
	//捏脸数据
	vector<PinchFaceBaseWraper> m_DataInfo;
public:
	int SizeDataInfo()
	{
		return m_DataInfo.size();
	}
	const vector<PinchFaceBaseWraper>& GetDataInfo() const
	{
		return m_DataInfo;
	}
	PinchFaceBaseWraper GetDataInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_DataInfo.size())
		{
			assert(false);
			return PinchFaceBaseWraper();
		}
		return m_DataInfo[Index];
	}
	void SetDataInfo( const vector<PinchFaceBaseWraper>& v )
	{
		m_DataInfo=v;
	}
	void ClearDataInfo( )
	{
		m_DataInfo.clear();
	}
	void SetDataInfo( int Index, const PinchFaceBaseWraper& v )
	{
		if(Index<0 || Index>=(int)m_DataInfo.size())
		{
			assert(false);
			return;
		}
		m_DataInfo[Index] = v;
	}
	void AddDataInfo( const PinchFaceBaseWraper& v )
	{
		m_DataInfo.push_back(v);
	}

};
//队伍专精目标封装类
class TeamProfessionTargetWraper
{
public:
	//构造函数
	TeamProfessionTargetWraper()
	{
		
		m_ProfessionId = -1;
		m_Size = -1;

	}
	//赋值构造函数
	TeamProfessionTargetWraper(const TeamProfessionTarget& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamProfessionTarget& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamProfessionTarget ToPB() const
	{
		TeamProfessionTarget v;
		v.set_professionid( m_ProfessionId );
		v.set_size( m_Size );

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
		TeamProfessionTarget pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamProfessionTarget& v)
	{
		m_ProfessionId = v.professionid();
		m_Size = v.size();

	}

private:
	//专精id
	INT32 m_ProfessionId;
public:
	void SetProfessionId( INT32 v)
	{
		m_ProfessionId=v;
	}
	INT32 GetProfessionId()
	{
		return m_ProfessionId;
	}
	INT32 GetProfessionId() const
	{
		return m_ProfessionId;
	}
private:
	//个数
	INT32 m_Size;
public:
	void SetSize( INT32 v)
	{
		m_Size=v;
	}
	INT32 GetSize()
	{
		return m_Size;
	}
	INT32 GetSize() const
	{
		return m_Size;
	}

};
//CharacterLocation封装类
class CharacterLocationWraper
{
public:
	//构造函数
	CharacterLocationWraper()
	{
		
		m_SceneId = -1;
		m_Pos = Vector3Wraper();
		m_MapId = -1;
		m_DungeonConfigId = -1;
		m_LineId = -1;
		m_SceneConfigId = -1;
		m_MirrorId = -1;
		m_ServerId = -1;

	}
	//赋值构造函数
	CharacterLocationWraper(const CharacterLocation& v){ Init(v); }
	//等号重载函数
	void operator = (const CharacterLocation& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CharacterLocation ToPB() const
	{
		CharacterLocation v;
		v.set_sceneid( m_SceneId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_mapid( m_MapId );
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_lineid( m_LineId );
		v.set_sceneconfigid( m_SceneConfigId );
		v.set_mirrorid( m_MirrorId );
		v.set_serverid( m_ServerId );

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
		CharacterLocation pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CharacterLocation& v)
	{
		m_SceneId = v.sceneid();
		m_Pos = v.pos();
		m_MapId = v.mapid();
		m_DungeonConfigId = v.dungeonconfigid();
		m_LineId = v.lineid();
		m_SceneConfigId = v.sceneconfigid();
		m_MirrorId = v.mirrorid();
		m_ServerId = v.serverid();

	}

private:
	//队员场景id
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
	//场景id
	INT32 m_MapId;
public:
	void SetMapId( INT32 v)
	{
		m_MapId=v;
	}
	INT32 GetMapId()
	{
		return m_MapId;
	}
	INT32 GetMapId() const
	{
		return m_MapId;
	}
private:
	//副本配置表id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}
private:
	//线Id
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
	//场景的配置表id
	INT32 m_SceneConfigId;
public:
	void SetSceneConfigId( INT32 v)
	{
		m_SceneConfigId=v;
	}
	INT32 GetSceneConfigId()
	{
		return m_SceneConfigId;
	}
	INT32 GetSceneConfigId() const
	{
		return m_SceneConfigId;
	}
private:
	//场景的配置Id
	INT32 m_MirrorId;
public:
	void SetMirrorId( INT32 v)
	{
		m_MirrorId=v;
	}
	INT32 GetMirrorId()
	{
		return m_MirrorId;
	}
	INT32 GetMirrorId() const
	{
		return m_MirrorId;
	}
private:
	//服务器Id
	INT32 m_ServerId;
public:
	void SetServerId( INT32 v)
	{
		m_ServerId=v;
	}
	INT32 GetServerId()
	{
		return m_ServerId;
	}
	INT32 GetServerId() const
	{
		return m_ServerId;
	}

};
//投票数据封装类
class VoteDataWraper
{
public:
	//构造函数
	VoteDataWraper()
	{
		
		m_Candidate = 0;

	}
	//赋值构造函数
	VoteDataWraper(const VoteData& v){ Init(v); }
	//等号重载函数
	void operator = (const VoteData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	VoteData ToPB() const
	{
		VoteData v;
		v.set_candidate( m_Candidate );
		v.mutable_voteplayer()->Reserve(m_VotePlayer.size());
		for (int i=0; i<(int)m_VotePlayer.size(); i++)
		{
			v.add_voteplayer(m_VotePlayer[i]);
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
		VoteData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const VoteData& v)
	{
		m_Candidate = v.candidate();
		m_VotePlayer.clear();
		m_VotePlayer.reserve(v.voteplayer_size());
		for( int i=0; i<v.voteplayer_size(); i++)
			m_VotePlayer.push_back(v.voteplayer(i));

	}

private:
	//投票id
	uint64_t m_Candidate;
public:
	void SetCandidate( uint64_t v)
	{
		m_Candidate=v;
	}
	uint64_t GetCandidate()
	{
		return m_Candidate;
	}
	uint64_t GetCandidate() const
	{
		return m_Candidate;
	}
private:
	//投票过的人
	vector<uint64_t> m_VotePlayer;
public:
	int SizeVotePlayer()
	{
		return m_VotePlayer.size();
	}
	const vector<uint64_t>& GetVotePlayer() const
	{
		return m_VotePlayer;
	}
	uint64_t GetVotePlayer(int Index) const
	{
		if(Index<0 || Index>=(int)m_VotePlayer.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_VotePlayer[Index];
	}
	void SetVotePlayer( const vector<uint64_t>& v )
	{
		m_VotePlayer=v;
	}
	void ClearVotePlayer( )
	{
		m_VotePlayer.clear();
	}
	void SetVotePlayer( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_VotePlayer.size())
		{
			assert(false);
			return;
		}
		m_VotePlayer[Index] = v;
	}
	void AddVotePlayer( uint64_t v = 0 )
	{
		m_VotePlayer.push_back(v);
	}

};
//ItemData封装类
class ItemDataWraper
{
public:
	//构造函数
	ItemDataWraper()
	{
		
		m_IsLock = false;
		m_OverlayCount = -1;
		m_ConfigId = -1;
		m_EquipAttr = EquipAttrWraper();
		m_IsBind = true;
		m_Guid = 0;
		m_PetData = PetDataWraper();
		m_BindRule = 1;
		m_SaleCD = 0;
		m_SoulStone = SoulStoneDataWraper();
		m_RefineData = RefineDataWraper();
		m_CacheAttr = EquipAttrWraper();
		m_WaysOfObtaining = -1;

	}
	//赋值构造函数
	ItemDataWraper(const ItemData& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemData ToPB() const
	{
		ItemData v;
		v.set_islock( m_IsLock );
		v.set_overlaycount( m_OverlayCount );
		v.set_configid( m_ConfigId );
		*v.mutable_equipattr()= m_EquipAttr.ToPB();
		v.set_isbind( m_IsBind );
		v.set_guid( m_Guid );
		*v.mutable_petdata()= m_PetData.ToPB();
		v.set_bindrule( m_BindRule );
		v.set_salecd( m_SaleCD );
		*v.mutable_soulstone()= m_SoulStone.ToPB();
		*v.mutable_refinedata()= m_RefineData.ToPB();
		*v.mutable_cacheattr()= m_CacheAttr.ToPB();
		v.set_waysofobtaining( m_WaysOfObtaining );

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
		ItemData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemData& v)
	{
		m_IsLock = v.islock();
		m_OverlayCount = v.overlaycount();
		m_ConfigId = v.configid();
		m_EquipAttr = v.equipattr();
		m_IsBind = v.isbind();
		m_Guid = v.guid();
		m_PetData = v.petdata();
		m_BindRule = v.bindrule();
		m_SaleCD = v.salecd();
		m_SoulStone = v.soulstone();
		m_RefineData = v.refinedata();
		m_CacheAttr = v.cacheattr();
		m_WaysOfObtaining = v.waysofobtaining();

	}

private:
	//物品锁
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}
private:
	//物品叠加数量
	INT32 m_OverlayCount;
public:
	void SetOverlayCount( INT32 v)
	{
		m_OverlayCount=v;
	}
	INT32 GetOverlayCount()
	{
		return m_OverlayCount;
	}
	INT32 GetOverlayCount() const
	{
		return m_OverlayCount;
	}
private:
	//物品表的id
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
private:
	//装备属性
	EquipAttrWraper m_EquipAttr;
public:
	void SetEquipAttr( const EquipAttrWraper& v)
	{
		m_EquipAttr=v;
	}
	EquipAttrWraper GetEquipAttr()
	{
		return m_EquipAttr;
	}
	EquipAttrWraper GetEquipAttr() const
	{
		return m_EquipAttr;
	}
private:
	//是否绑定
	bool m_IsBind;
public:
	void SetIsBind( bool v)
	{
		m_IsBind=v;
	}
	bool GetIsBind()
	{
		return m_IsBind;
	}
	bool GetIsBind() const
	{
		return m_IsBind;
	}
private:
	//物品guid
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
	//宠物的数据
	PetDataWraper m_PetData;
public:
	void SetPetData( const PetDataWraper& v)
	{
		m_PetData=v;
	}
	PetDataWraper GetPetData()
	{
		return m_PetData;
	}
	PetDataWraper GetPetData() const
	{
		return m_PetData;
	}
private:
	//绑定规则
	INT32 m_BindRule;
public:
	void SetBindRule( INT32 v)
	{
		m_BindRule=v;
	}
	INT32 GetBindRule()
	{
		return m_BindRule;
	}
	INT32 GetBindRule() const
	{
		return m_BindRule;
	}
private:
	//交易cd
	INT32 m_SaleCD;
public:
	void SetSaleCD( INT32 v)
	{
		m_SaleCD=v;
	}
	INT32 GetSaleCD()
	{
		return m_SaleCD;
	}
	INT32 GetSaleCD() const
	{
		return m_SaleCD;
	}
private:
	//魂石
	SoulStoneDataWraper m_SoulStone;
public:
	void SetSoulStone( const SoulStoneDataWraper& v)
	{
		m_SoulStone=v;
	}
	SoulStoneDataWraper GetSoulStone()
	{
		return m_SoulStone;
	}
	SoulStoneDataWraper GetSoulStone() const
	{
		return m_SoulStone;
	}
private:
	//精炼数据
	RefineDataWraper m_RefineData;
public:
	void SetRefineData( const RefineDataWraper& v)
	{
		m_RefineData=v;
	}
	RefineDataWraper GetRefineData()
	{
		return m_RefineData;
	}
	RefineDataWraper GetRefineData() const
	{
		return m_RefineData;
	}
private:
	//缓存属性
	EquipAttrWraper m_CacheAttr;
public:
	void SetCacheAttr( const EquipAttrWraper& v)
	{
		m_CacheAttr=v;
	}
	EquipAttrWraper GetCacheAttr()
	{
		return m_CacheAttr;
	}
	EquipAttrWraper GetCacheAttr() const
	{
		return m_CacheAttr;
	}
private:
	//WaysOfObtaining
	INT32 m_WaysOfObtaining;
public:
	void SetWaysOfObtaining( INT32 v)
	{
		m_WaysOfObtaining=v;
	}
	INT32 GetWaysOfObtaining()
	{
		return m_WaysOfObtaining;
	}
	INT32 GetWaysOfObtaining() const
	{
		return m_WaysOfObtaining;
	}

};
//TeamMemberInfo封装类
class TeamMemberInfoWraper
{
public:
	//构造函数
	TeamMemberInfoWraper()
	{
		
		m_RoleId = 0;
		m_Level = 0;
		m_Name = "";
		m_ConfigId = -1;
		m_Hp = -1;
		m_Status = -1;
		m_MaxHp = -1;
		m_Location = CharacterLocationWraper();
		m_ProfessionId = -1;
		m_OnLine = 1;
		m_FollowTeam = -1;
		m_Robot = false;
		m_Camp = -1;
		m_GuildGuid = 0;
		m_BattleScore = -1;
		m_Treasureinfo = TreasureEquipedIDWraper();
		m_GhostGuid = 0;
		m_Occupation = -1;
		m_PinchData = PinchFaceDataWraper();
		m_WillLeaveTime = 0;
		m_LastLogoutTime = -1;

	}
	//赋值构造函数
	TeamMemberInfoWraper(const TeamMemberInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberInfo ToPB() const
	{
		TeamMemberInfo v;
		v.set_roleid( m_RoleId );
		v.set_level( m_Level );
		v.set_name( m_Name );
		v.set_configid( m_ConfigId );
		v.set_hp( m_Hp );
		v.set_status( m_Status );
		v.set_maxhp( m_MaxHp );
		*v.mutable_location()= m_Location.ToPB();
		v.set_professionid( m_ProfessionId );
		v.set_online( m_OnLine );
		v.set_followteam( m_FollowTeam );
		v.mutable_buffidlist()->Reserve(m_BuffIdList.size());
		for (int i=0; i<(int)m_BuffIdList.size(); i++)
		{
			v.add_buffidlist(m_BuffIdList[i]);
		}
		v.set_robot( m_Robot );
		v.set_camp( m_Camp );
		v.set_guildguid( m_GuildGuid );
		v.set_battlescore( m_BattleScore );
		*v.mutable_treasureinfo()= m_Treasureinfo.ToPB();
		v.set_ghostguid( m_GhostGuid );
		v.set_occupation( m_Occupation );
		*v.mutable_pinchdata()= m_PinchData.ToPB();
		v.set_willleavetime( m_WillLeaveTime );
		v.set_lastlogouttime( m_LastLogoutTime );

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
		TeamMemberInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamMemberInfo& v)
	{
		m_RoleId = v.roleid();
		m_Level = v.level();
		m_Name = v.name();
		m_ConfigId = v.configid();
		m_Hp = v.hp();
		m_Status = v.status();
		m_MaxHp = v.maxhp();
		m_Location = v.location();
		m_ProfessionId = v.professionid();
		m_OnLine = v.online();
		m_FollowTeam = v.followteam();
		m_BuffIdList.clear();
		m_BuffIdList.reserve(v.buffidlist_size());
		for( int i=0; i<v.buffidlist_size(); i++)
			m_BuffIdList.push_back(v.buffidlist(i));
		m_Robot = v.robot();
		m_Camp = v.camp();
		m_GuildGuid = v.guildguid();
		m_BattleScore = v.battlescore();
		m_Treasureinfo = v.treasureinfo();
		m_GhostGuid = v.ghostguid();
		m_Occupation = v.occupation();
		m_PinchData = v.pinchdata();
		m_WillLeaveTime = v.willleavetime();
		m_LastLogoutTime = v.lastlogouttime();

	}

private:
	//队员RoleId
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
	//队员等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//name
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
	//configid
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
private:
	//生命值
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//Status
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//生命值
	int64_t m_MaxHp;
public:
	void SetMaxHp( int64_t v)
	{
		m_MaxHp=v;
	}
	int64_t GetMaxHp()
	{
		return m_MaxHp;
	}
	int64_t GetMaxHp() const
	{
		return m_MaxHp;
	}
private:
	//Location
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}
private:
	//专精ID
	INT32 m_ProfessionId;
public:
	void SetProfessionId( INT32 v)
	{
		m_ProfessionId=v;
	}
	INT32 GetProfessionId()
	{
		return m_ProfessionId;
	}
	INT32 GetProfessionId() const
	{
		return m_ProfessionId;
	}
private:
	//在线
	INT32 m_OnLine;
public:
	void SetOnLine( INT32 v)
	{
		m_OnLine=v;
	}
	INT32 GetOnLine()
	{
		return m_OnLine;
	}
	INT32 GetOnLine() const
	{
		return m_OnLine;
	}
private:
	//队员是否跟随队长
	INT32 m_FollowTeam;
public:
	void SetFollowTeam( INT32 v)
	{
		m_FollowTeam=v;
	}
	INT32 GetFollowTeam()
	{
		return m_FollowTeam;
	}
	INT32 GetFollowTeam() const
	{
		return m_FollowTeam;
	}
private:
	//buff
	vector<INT32> m_BuffIdList;
public:
	int SizeBuffIdList()
	{
		return m_BuffIdList.size();
	}
	const vector<INT32>& GetBuffIdList() const
	{
		return m_BuffIdList;
	}
	INT32 GetBuffIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffIdList.size())
		{
			assert(false);
			return INT32();
		}
		return m_BuffIdList[Index];
	}
	void SetBuffIdList( const vector<INT32>& v )
	{
		m_BuffIdList=v;
	}
	void ClearBuffIdList( )
	{
		m_BuffIdList.clear();
	}
	void SetBuffIdList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_BuffIdList.size())
		{
			assert(false);
			return;
		}
		m_BuffIdList[Index] = v;
	}
	void AddBuffIdList( INT32 v = -1 )
	{
		m_BuffIdList.push_back(v);
	}
private:
	//是否是机器人
	bool m_Robot;
public:
	void SetRobot( bool v)
	{
		m_Robot=v;
	}
	bool GetRobot()
	{
		return m_Robot;
	}
	bool GetRobot() const
	{
		return m_Robot;
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
	//公会GUID
	uint64_t m_GuildGuid;
public:
	void SetGuildGuid( uint64_t v)
	{
		m_GuildGuid=v;
	}
	uint64_t GetGuildGuid()
	{
		return m_GuildGuid;
	}
	uint64_t GetGuildGuid() const
	{
		return m_GuildGuid;
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//外显
	TreasureEquipedIDWraper m_Treasureinfo;
public:
	void SetTreasureinfo( const TreasureEquipedIDWraper& v)
	{
		m_Treasureinfo=v;
	}
	TreasureEquipedIDWraper GetTreasureinfo()
	{
		return m_Treasureinfo;
	}
	TreasureEquipedIDWraper GetTreasureinfo() const
	{
		return m_Treasureinfo;
	}
private:
	//幽灵ID
	uint64_t m_GhostGuid;
public:
	void SetGhostGuid( uint64_t v)
	{
		m_GhostGuid=v;
	}
	uint64_t GetGhostGuid()
	{
		return m_GhostGuid;
	}
	uint64_t GetGhostGuid() const
	{
		return m_GhostGuid;
	}
private:
	//MT TT DPS
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
	//捏脸数据
	PinchFaceDataWraper m_PinchData;
public:
	void SetPinchData( const PinchFaceDataWraper& v)
	{
		m_PinchData=v;
	}
	PinchFaceDataWraper GetPinchData()
	{
		return m_PinchData;
	}
	PinchFaceDataWraper GetPinchData() const
	{
		return m_PinchData;
	}
private:
	//将要在什么时候离开缔约团
	int64_t m_WillLeaveTime;
public:
	void SetWillLeaveTime( int64_t v)
	{
		m_WillLeaveTime=v;
	}
	int64_t GetWillLeaveTime()
	{
		return m_WillLeaveTime;
	}
	int64_t GetWillLeaveTime() const
	{
		return m_WillLeaveTime;
	}
private:
	//最后登出时间
	int64_t m_LastLogoutTime;
public:
	void SetLastLogoutTime( int64_t v)
	{
		m_LastLogoutTime=v;
	}
	int64_t GetLastLogoutTime()
	{
		return m_LastLogoutTime;
	}
	int64_t GetLastLogoutTime() const
	{
		return m_LastLogoutTime;
	}

};
//目标队伍封装类
class TeamTargetWraper
{
public:
	//构造函数
	TeamTargetWraper()
	{
		
		m_Id = 0;
		m_MinLevel = 0;
		m_MaxLevel = 0;
		m_TargetType = 0;

	}
	//赋值构造函数
	TeamTargetWraper(const TeamTarget& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamTarget& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamTarget ToPB() const
	{
		TeamTarget v;
		v.set_id( m_Id );
		v.set_minlevel( m_MinLevel );
		v.set_maxlevel( m_MaxLevel );
		v.mutable_profession()->Reserve(m_Profession.size());
		for (int i=0; i<(int)m_Profession.size(); i++)
		{
			*v.add_profession() = m_Profession[i].ToPB();
		}
		v.set_targettype( m_TargetType );

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
		TeamTarget pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamTarget& v)
	{
		m_Id = v.id();
		m_MinLevel = v.minlevel();
		m_MaxLevel = v.maxlevel();
		m_Profession.clear();
		m_Profession.reserve(v.profession_size());
		for( int i=0; i<v.profession_size(); i++)
			m_Profession.push_back(v.profession(i));
		m_TargetType = v.targettype();

	}

private:
	//唯一标识　全部队伍：0
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//最小等级
	INT32 m_MinLevel;
public:
	void SetMinLevel( INT32 v)
	{
		m_MinLevel=v;
	}
	INT32 GetMinLevel()
	{
		return m_MinLevel;
	}
	INT32 GetMinLevel() const
	{
		return m_MinLevel;
	}
private:
	//最大等级
	INT32 m_MaxLevel;
public:
	void SetMaxLevel( INT32 v)
	{
		m_MaxLevel=v;
	}
	INT32 GetMaxLevel()
	{
		return m_MaxLevel;
	}
	INT32 GetMaxLevel() const
	{
		return m_MaxLevel;
	}
private:
	//职能
	vector<TeamProfessionTargetWraper> m_Profession;
public:
	int SizeProfession()
	{
		return m_Profession.size();
	}
	const vector<TeamProfessionTargetWraper>& GetProfession() const
	{
		return m_Profession;
	}
	TeamProfessionTargetWraper GetProfession(int Index) const
	{
		if(Index<0 || Index>=(int)m_Profession.size())
		{
			assert(false);
			return TeamProfessionTargetWraper();
		}
		return m_Profession[Index];
	}
	void SetProfession( const vector<TeamProfessionTargetWraper>& v )
	{
		m_Profession=v;
	}
	void ClearProfession( )
	{
		m_Profession.clear();
	}
	void SetProfession( int Index, const TeamProfessionTargetWraper& v )
	{
		if(Index<0 || Index>=(int)m_Profession.size())
		{
			assert(false);
			return;
		}
		m_Profession[Index] = v;
	}
	void AddProfession( const TeamProfessionTargetWraper& v )
	{
		m_Profession.push_back(v);
	}
private:
	//目标类型
	INT32 m_TargetType;
public:
	void SetTargetType( INT32 v)
	{
		m_TargetType=v;
	}
	INT32 GetTargetType()
	{
		return m_TargetType;
	}
	INT32 GetTargetType() const
	{
		return m_TargetType;
	}

};
//投票信息封装类
class VoteMsgWraper
{
public:
	//构造函数
	VoteMsgWraper()
	{
		
		m_VoteId = 0;
		m_VoteEndTime = 0;
		m_Result = 0;

	}
	//赋值构造函数
	VoteMsgWraper(const VoteMsg& v){ Init(v); }
	//等号重载函数
	void operator = (const VoteMsg& v){ Init(v); }
 	//转化成Protobuffer类型函数
	VoteMsg ToPB() const
	{
		VoteMsg v;
		v.set_voteid( m_VoteId );
		v.mutable_dt()->Reserve(m_Dt.size());
		for (int i=0; i<(int)m_Dt.size(); i++)
		{
			*v.add_dt() = m_Dt[i].ToPB();
		}
		v.set_voteendtime( m_VoteEndTime );
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
		VoteMsg pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const VoteMsg& v)
	{
		m_VoteId = v.voteid();
		m_Dt.clear();
		m_Dt.reserve(v.dt_size());
		for( int i=0; i<v.dt_size(); i++)
			m_Dt.push_back(v.dt(i));
		m_VoteEndTime = v.voteendtime();
		m_Result = v.result();

	}

private:
	//投票id
	uint64_t m_VoteId;
public:
	void SetVoteId( uint64_t v)
	{
		m_VoteId=v;
	}
	uint64_t GetVoteId()
	{
		return m_VoteId;
	}
	uint64_t GetVoteId() const
	{
		return m_VoteId;
	}
private:
	//投票数据
	vector<VoteDataWraper> m_Dt;
public:
	int SizeDt()
	{
		return m_Dt.size();
	}
	const vector<VoteDataWraper>& GetDt() const
	{
		return m_Dt;
	}
	VoteDataWraper GetDt(int Index) const
	{
		if(Index<0 || Index>=(int)m_Dt.size())
		{
			assert(false);
			return VoteDataWraper();
		}
		return m_Dt[Index];
	}
	void SetDt( const vector<VoteDataWraper>& v )
	{
		m_Dt=v;
	}
	void ClearDt( )
	{
		m_Dt.clear();
	}
	void SetDt( int Index, const VoteDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Dt.size())
		{
			assert(false);
			return;
		}
		m_Dt[Index] = v;
	}
	void AddDt( const VoteDataWraper& v )
	{
		m_Dt.push_back(v);
	}
private:
	//VoteEndTime
	INT32 m_VoteEndTime;
public:
	void SetVoteEndTime( INT32 v)
	{
		m_VoteEndTime=v;
	}
	INT32 GetVoteEndTime()
	{
		return m_VoteEndTime;
	}
	INT32 GetVoteEndTime() const
	{
		return m_VoteEndTime;
	}
private:
	//结果
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
//ChatMsg封装类
class ChatMsgWraper
{
public:
	//构造函数
	ChatMsgWraper()
	{
		
		m_Chat_content = "";
		m_Chat_voice_url = "";
		m_Chat_voice_secs = -1;
		m_StringUIConfigId = -1;

	}
	//赋值构造函数
	ChatMsgWraper(const ChatMsg& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatMsg& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatMsg ToPB() const
	{
		ChatMsg v;
		v.set_chat_content( m_Chat_content );
		v.set_chat_voice_url( m_Chat_voice_url );
		v.set_chat_voice_secs( m_Chat_voice_secs );
		v.mutable_items()->Reserve(m_Items.size());
		for (int i=0; i<(int)m_Items.size(); i++)
		{
			*v.add_items() = m_Items[i].ToPB();
		}
		v.set_stringuiconfigid( m_StringUIConfigId );
		v.mutable_params()->Reserve(m_Params.size());
		for (int i=0; i<(int)m_Params.size(); i++)
		{
			v.add_params( m_Params[i]);
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
		ChatMsg pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatMsg& v)
	{
		m_Chat_content = v.chat_content();
		m_Chat_voice_url = v.chat_voice_url();
		m_Chat_voice_secs = v.chat_voice_secs();
		m_Items.clear();
		m_Items.reserve(v.items_size());
		for( int i=0; i<v.items_size(); i++)
			m_Items.push_back(v.items(i));
		m_StringUIConfigId = v.stringuiconfigid();
		m_Params.clear();
		m_Params.reserve(v.params_size());
		for( int i=0; i<v.params_size(); i++)
			m_Params.push_back(v.params(i));

	}

private:
	//文字内容
	string m_Chat_content;
public:
	void SetChat_content( const string& v)
	{
		m_Chat_content=v;
	}
	string GetChat_content()
	{
		return m_Chat_content;
	}
	string GetChat_content() const
	{
		return m_Chat_content;
	}
private:
	//音频URL
	string m_Chat_voice_url;
public:
	void SetChat_voice_url( const string& v)
	{
		m_Chat_voice_url=v;
	}
	string GetChat_voice_url()
	{
		return m_Chat_voice_url;
	}
	string GetChat_voice_url() const
	{
		return m_Chat_voice_url;
	}
private:
	//音频秒数
	INT32 m_Chat_voice_secs;
public:
	void SetChat_voice_secs( INT32 v)
	{
		m_Chat_voice_secs=v;
	}
	INT32 GetChat_voice_secs()
	{
		return m_Chat_voice_secs;
	}
	INT32 GetChat_voice_secs() const
	{
		return m_Chat_voice_secs;
	}
private:
	//items
	vector<ItemDataWraper> m_Items;
public:
	int SizeItems()
	{
		return m_Items.size();
	}
	const vector<ItemDataWraper>& GetItems() const
	{
		return m_Items;
	}
	ItemDataWraper GetItems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Items[Index];
	}
	void SetItems( const vector<ItemDataWraper>& v )
	{
		m_Items=v;
	}
	void ClearItems( )
	{
		m_Items.clear();
	}
	void SetItems( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return;
		}
		m_Items[Index] = v;
	}
	void AddItems( const ItemDataWraper& v )
	{
		m_Items.push_back(v);
	}
private:
	//StringUIConfigId
	INT32 m_StringUIConfigId;
public:
	void SetStringUIConfigId( INT32 v)
	{
		m_StringUIConfigId=v;
	}
	INT32 GetStringUIConfigId()
	{
		return m_StringUIConfigId;
	}
	INT32 GetStringUIConfigId() const
	{
		return m_StringUIConfigId;
	}
private:
	//Params
	vector<string> m_Params;
public:
	int SizeParams()
	{
		return m_Params.size();
	}
	const vector<string>& GetParams() const
	{
		return m_Params;
	}
	string GetParams(int Index) const
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return string();
		}
		return m_Params[Index];
	}
	void SetParams( const vector<string>& v )
	{
		m_Params=v;
	}
	void ClearParams( )
	{
		m_Params.clear();
	}
	void SetParams( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return;
		}
		m_Params[Index] = v;
	}
	void AddParams( const string& v )
	{
		m_Params.push_back(v);
	}

};
//QuestStepData封装类
class QuestStepDataWraper
{
public:
	//构造函数
	QuestStepDataWraper()
	{
		
		m_Status = 0;
		m_Progress  = 0;

	}
	//赋值构造函数
	QuestStepDataWraper(const QuestStepData& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestStepData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestStepData ToPB() const
	{
		QuestStepData v;
		v.set_status( m_Status );
		v.set_progress ( m_Progress  );

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
		QuestStepData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const QuestStepData& v)
	{
		m_Status = v.status();
		m_Progress  = v.progress ();

	}

private:
	//Status
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//进度
	INT32 m_Progress ;
public:
	void SetProgress ( INT32 v)
	{
		m_Progress =v;
	}
	INT32 GetProgress ()
	{
		return m_Progress ;
	}
	INT32 GetProgress () const
	{
		return m_Progress ;
	}

};
//星耀玩家信息封装类
class StarBattlePlayerInfoWraper
{
public:
	//构造函数
	StarBattlePlayerInfoWraper()
	{
		
		m_Playerguid = 0;
		m_Playername = "";
		m_Level = -1;
		m_RoleID = -1;

	}
	//赋值构造函数
	StarBattlePlayerInfoWraper(const StarBattlePlayerInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const StarBattlePlayerInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StarBattlePlayerInfo ToPB() const
	{
		StarBattlePlayerInfo v;
		v.set_playerguid( m_Playerguid );
		v.set_playername( m_Playername );
		v.set_level( m_Level );
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
		StarBattlePlayerInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const StarBattlePlayerInfo& v)
	{
		m_Playerguid = v.playerguid();
		m_Playername = v.playername();
		m_Level = v.level();
		m_RoleID = v.roleid();

	}

private:
	//playerguid
	uint64_t m_Playerguid;
public:
	void SetPlayerguid( uint64_t v)
	{
		m_Playerguid=v;
	}
	uint64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	uint64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//playername
	string m_Playername;
public:
	void SetPlayername( const string& v)
	{
		m_Playername=v;
	}
	string GetPlayername()
	{
		return m_Playername;
	}
	string GetPlayername() const
	{
		return m_Playername;
	}
private:
	//Level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
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
//联系人数据结构封装类
class ContactDataWraper
{
public:
	//构造函数
	ContactDataWraper()
	{
		
		m_RoleId = 0;
		m_TeamId = 0;
		m_Nickname = "";
		m_ConfigId = -1;
		m_Level = 1;
		m_ResourceId = -1;
		m_Alias = "";
		m_FamiliarPoint = 0;
		m_OnLine = 0;
		m_CombatValue = -1;
		m_LastLoginTime = -1;
		m_PopularPoint = 0;
		m_UnionId = 0;
		m_UnionName = "";

	}
	//赋值构造函数
	ContactDataWraper(const ContactData& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactData ToPB() const
	{
		ContactData v;
		v.set_roleid( m_RoleId );
		v.set_teamid( m_TeamId );
		v.set_nickname( m_Nickname );
		v.set_configid( m_ConfigId );
		v.set_level( m_Level );
		v.set_resourceid( m_ResourceId );
		v.set_alias( m_Alias );
		v.set_familiarpoint( m_FamiliarPoint );
		v.set_online( m_OnLine );
		v.set_combatvalue( m_CombatValue );
		v.set_lastlogintime( m_LastLoginTime );
		v.set_popularpoint( m_PopularPoint );
		v.set_unionid( m_UnionId );
		v.set_unionname( m_UnionName );

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
		ContactData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ContactData& v)
	{
		m_RoleId = v.roleid();
		m_TeamId = v.teamid();
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();
		m_Level = v.level();
		m_ResourceId = v.resourceid();
		m_Alias = v.alias();
		m_FamiliarPoint = v.familiarpoint();
		m_OnLine = v.online();
		m_CombatValue = v.combatvalue();
		m_LastLoginTime = v.lastlogintime();
		m_PopularPoint = v.popularpoint();
		m_UnionId = v.unionid();
		m_UnionName = v.unionname();

	}

private:
	//玩家唯一id
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
	//玩家队伍Id
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
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
private:
	//Level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//资源Id
	INT32 m_ResourceId;
public:
	void SetResourceId( INT32 v)
	{
		m_ResourceId=v;
	}
	INT32 GetResourceId()
	{
		return m_ResourceId;
	}
	INT32 GetResourceId() const
	{
		return m_ResourceId;
	}
private:
	//别名
	string m_Alias;
public:
	void SetAlias( const string& v)
	{
		m_Alias=v;
	}
	string GetAlias()
	{
		return m_Alias;
	}
	string GetAlias() const
	{
		return m_Alias;
	}
private:
	//亲密度
	INT32 m_FamiliarPoint;
public:
	void SetFamiliarPoint( INT32 v)
	{
		m_FamiliarPoint=v;
	}
	INT32 GetFamiliarPoint()
	{
		return m_FamiliarPoint;
	}
	INT32 GetFamiliarPoint() const
	{
		return m_FamiliarPoint;
	}
private:
	//是否在线
	INT32 m_OnLine;
public:
	void SetOnLine( INT32 v)
	{
		m_OnLine=v;
	}
	INT32 GetOnLine()
	{
		return m_OnLine;
	}
	INT32 GetOnLine() const
	{
		return m_OnLine;
	}
private:
	//战斗力
	INT32 m_CombatValue;
public:
	void SetCombatValue( INT32 v)
	{
		m_CombatValue=v;
	}
	INT32 GetCombatValue()
	{
		return m_CombatValue;
	}
	INT32 GetCombatValue() const
	{
		return m_CombatValue;
	}
private:
	//最后登录状态
	int64_t m_LastLoginTime;
public:
	void SetLastLoginTime( int64_t v)
	{
		m_LastLoginTime=v;
	}
	int64_t GetLastLoginTime()
	{
		return m_LastLoginTime;
	}
	int64_t GetLastLoginTime() const
	{
		return m_LastLoginTime;
	}
private:
	//人气值
	INT32 m_PopularPoint;
public:
	void SetPopularPoint( INT32 v)
	{
		m_PopularPoint=v;
	}
	INT32 GetPopularPoint()
	{
		return m_PopularPoint;
	}
	INT32 GetPopularPoint() const
	{
		return m_PopularPoint;
	}
private:
	//UnionId
	uint64_t m_UnionId;
public:
	void SetUnionId( uint64_t v)
	{
		m_UnionId=v;
	}
	uint64_t GetUnionId()
	{
		return m_UnionId;
	}
	uint64_t GetUnionId() const
	{
		return m_UnionId;
	}
private:
	//UnionName
	string m_UnionName;
public:
	void SetUnionName( const string& v)
	{
		m_UnionName=v;
	}
	string GetUnionName()
	{
		return m_UnionName;
	}
	string GetUnionName() const
	{
		return m_UnionName;
	}

};
//技能对象封装类
class SkillObjWraper
{
public:
	//构造函数
	SkillObjWraper()
	{
		
		m_Pos = -1;
		m_SkillId = -1;

	}
	//赋值构造函数
	SkillObjWraper(const SkillObj& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillObj ToPB() const
	{
		SkillObj v;
		v.set_pos( m_Pos );
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
		SkillObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillObj& v)
	{
		m_Pos = v.pos();
		m_SkillId = v.skillid();

	}

private:
	//技能位置(0-4)
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//技能数据
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
//实时副本战绩数据封装类
class PlayerRealTimeExploitWraper
{
public:
	//构造函数
	PlayerRealTimeExploitWraper()
	{
		
		m_RoleId = 0;
		m_PlayerLevel = 0;
		m_PlayerName = "";
		m_Occupation = 0;
		m_ExploitsValue = 0;

	}
	//赋值构造函数
	PlayerRealTimeExploitWraper(const PlayerRealTimeExploit& v){ Init(v); }
	//等号重载函数
	void operator = (const PlayerRealTimeExploit& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PlayerRealTimeExploit ToPB() const
	{
		PlayerRealTimeExploit v;
		v.set_roleid( m_RoleId );
		v.set_playerlevel( m_PlayerLevel );
		v.set_playername( m_PlayerName );
		v.set_occupation( m_Occupation );
		v.set_exploitsvalue( m_ExploitsValue );

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
		PlayerRealTimeExploit pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PlayerRealTimeExploit& v)
	{
		m_RoleId = v.roleid();
		m_PlayerLevel = v.playerlevel();
		m_PlayerName = v.playername();
		m_Occupation = v.occupation();
		m_ExploitsValue = v.exploitsvalue();

	}

private:
	//玩家id
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
	//玩家等级
	INT32 m_PlayerLevel;
public:
	void SetPlayerLevel( INT32 v)
	{
		m_PlayerLevel=v;
	}
	INT32 GetPlayerLevel()
	{
		return m_PlayerLevel;
	}
	INT32 GetPlayerLevel() const
	{
		return m_PlayerLevel;
	}
private:
	//玩家名字
	string m_PlayerName;
public:
	void SetPlayerName( const string& v)
	{
		m_PlayerName=v;
	}
	string GetPlayerName()
	{
		return m_PlayerName;
	}
	string GetPlayerName() const
	{
		return m_PlayerName;
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
	//数据
	INT32 m_ExploitsValue;
public:
	void SetExploitsValue( INT32 v)
	{
		m_ExploitsValue=v;
	}
	INT32 GetExploitsValue()
	{
		return m_ExploitsValue;
	}
	INT32 GetExploitsValue() const
	{
		return m_ExploitsValue;
	}

};
//行当道具信息封装类
class BusinessQuestItemWraper
{
public:
	//构造函数
	BusinessQuestItemWraper()
	{
		
		m_ItemID = -1;
		m_Count = -1;

	}
	//赋值构造函数
	BusinessQuestItemWraper(const BusinessQuestItem& v){ Init(v); }
	//等号重载函数
	void operator = (const BusinessQuestItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BusinessQuestItem ToPB() const
	{
		BusinessQuestItem v;
		v.set_itemid( m_ItemID );
		v.set_count( m_Count );

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
		BusinessQuestItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BusinessQuestItem& v)
	{
		m_ItemID = v.itemid();
		m_Count = v.count();

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
	//需求数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}

};
//匹配信息封装类
class MatchInfoWraper
{
public:
	//构造函数
	MatchInfoWraper()
	{
		
		m_RoleId = 0;
		m_Level = 0;
		m_ConfigId = -1;
		m_ProfessionId = -1;
		m_Name = "";
		m_Ready = -1;
		m_Camp = 0;
		m_Integral = 0;
		m_Section = 0;
		m_Robot = false;
		m_GhostGuid = 0;
		m_Guild = 0;

	}
	//赋值构造函数
	MatchInfoWraper(const MatchInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchInfo ToPB() const
	{
		MatchInfo v;
		v.set_roleid( m_RoleId );
		v.set_level( m_Level );
		v.set_configid( m_ConfigId );
		v.set_professionid( m_ProfessionId );
		v.set_name( m_Name );
		v.set_ready( m_Ready );
		v.set_camp( m_Camp );
		v.set_integral( m_Integral );
		v.set_section( m_Section );
		v.set_robot( m_Robot );
		v.set_ghostguid( m_GhostGuid );
		v.set_guild( m_Guild );

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
		MatchInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MatchInfo& v)
	{
		m_RoleId = v.roleid();
		m_Level = v.level();
		m_ConfigId = v.configid();
		m_ProfessionId = v.professionid();
		m_Name = v.name();
		m_Ready = v.ready();
		m_Camp = v.camp();
		m_Integral = v.integral();
		m_Section = v.section();
		m_Robot = v.robot();
		m_GhostGuid = v.ghostguid();
		m_Guild = v.guild();

	}

private:
	//玩家id
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
	//玩家等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//configid
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
private:
	//专精ID
	INT32 m_ProfessionId;
public:
	void SetProfessionId( INT32 v)
	{
		m_ProfessionId=v;
	}
	INT32 GetProfessionId()
	{
		return m_ProfessionId;
	}
	INT32 GetProfessionId() const
	{
		return m_ProfessionId;
	}
private:
	//name
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
	//准备
	INT32 m_Ready;
public:
	void SetReady( INT32 v)
	{
		m_Ready=v;
	}
	INT32 GetReady()
	{
		return m_Ready;
	}
	INT32 GetReady() const
	{
		return m_Ready;
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
	//积分
	INT32 m_Integral;
public:
	void SetIntegral( INT32 v)
	{
		m_Integral=v;
	}
	INT32 GetIntegral()
	{
		return m_Integral;
	}
	INT32 GetIntegral() const
	{
		return m_Integral;
	}
private:
	//段位
	INT32 m_Section;
public:
	void SetSection( INT32 v)
	{
		m_Section=v;
	}
	INT32 GetSection()
	{
		return m_Section;
	}
	INT32 GetSection() const
	{
		return m_Section;
	}
private:
	//机器人
	bool m_Robot;
public:
	void SetRobot( bool v)
	{
		m_Robot=v;
	}
	bool GetRobot()
	{
		return m_Robot;
	}
	bool GetRobot() const
	{
		return m_Robot;
	}
private:
	//幽灵
	uint64_t m_GhostGuid;
public:
	void SetGhostGuid( uint64_t v)
	{
		m_GhostGuid=v;
	}
	uint64_t GetGhostGuid()
	{
		return m_GhostGuid;
	}
	uint64_t GetGhostGuid() const
	{
		return m_GhostGuid;
	}
private:
	//帮会id
	uint64_t m_Guild;
public:
	void SetGuild( uint64_t v)
	{
		m_Guild=v;
	}
	uint64_t GetGuild()
	{
		return m_Guild;
	}
	uint64_t GetGuild() const
	{
		return m_Guild;
	}

};
//ChatInfo封装类
class ChatInfoWraper
{
public:
	//构造函数
	ChatInfoWraper()
	{
		
		m_Player_name = "";
		m_Player_guid = 0;
		m_Avatar_id = -1;
		m_Player_level = -1;
		m_Avatar_frame_id = -1;
		m_Config_id = -1;
		m_Timestamp = 0;
		m_Chat_msg = ChatMsgWraper();
		m_Team_id = 0;
		m_Guild_guid = 0;

	}
	//赋值构造函数
	ChatInfoWraper(const ChatInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatInfo ToPB() const
	{
		ChatInfo v;
		v.set_player_name( m_Player_name );
		v.set_player_guid( m_Player_guid );
		v.set_avatar_id( m_Avatar_id );
		v.set_player_level( m_Player_level );
		v.set_avatar_frame_id( m_Avatar_frame_id );
		v.set_config_id( m_Config_id );
		v.set_timestamp( m_Timestamp );
		*v.mutable_chat_msg()= m_Chat_msg.ToPB();
		v.set_team_id( m_Team_id );
		v.set_guild_guid( m_Guild_guid );

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
		ChatInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatInfo& v)
	{
		m_Player_name = v.player_name();
		m_Player_guid = v.player_guid();
		m_Avatar_id = v.avatar_id();
		m_Player_level = v.player_level();
		m_Avatar_frame_id = v.avatar_frame_id();
		m_Config_id = v.config_id();
		m_Timestamp = v.timestamp();
		m_Chat_msg = v.chat_msg();
		m_Team_id = v.team_id();
		m_Guild_guid = v.guild_guid();

	}

private:
	//玩家名字
	string m_Player_name;
public:
	void SetPlayer_name( const string& v)
	{
		m_Player_name=v;
	}
	string GetPlayer_name()
	{
		return m_Player_name;
	}
	string GetPlayer_name() const
	{
		return m_Player_name;
	}
private:
	//玩家GUID
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}
private:
	//头像ID
	INT32 m_Avatar_id;
public:
	void SetAvatar_id( INT32 v)
	{
		m_Avatar_id=v;
	}
	INT32 GetAvatar_id()
	{
		return m_Avatar_id;
	}
	INT32 GetAvatar_id() const
	{
		return m_Avatar_id;
	}
private:
	//等级
	INT32 m_Player_level;
public:
	void SetPlayer_level( INT32 v)
	{
		m_Player_level=v;
	}
	INT32 GetPlayer_level()
	{
		return m_Player_level;
	}
	INT32 GetPlayer_level() const
	{
		return m_Player_level;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id;
public:
	void SetAvatar_frame_id( INT32 v)
	{
		m_Avatar_frame_id=v;
	}
	INT32 GetAvatar_frame_id()
	{
		return m_Avatar_frame_id;
	}
	INT32 GetAvatar_frame_id() const
	{
		return m_Avatar_frame_id;
	}
private:
	//角色配置ID
	INT32 m_Config_id;
public:
	void SetConfig_id( INT32 v)
	{
		m_Config_id=v;
	}
	INT32 GetConfig_id()
	{
		return m_Config_id;
	}
	INT32 GetConfig_id() const
	{
		return m_Config_id;
	}
private:
	//时间戳
	uint64_t m_Timestamp;
public:
	void SetTimestamp( uint64_t v)
	{
		m_Timestamp=v;
	}
	uint64_t GetTimestamp()
	{
		return m_Timestamp;
	}
	uint64_t GetTimestamp() const
	{
		return m_Timestamp;
	}
private:
	//聊天消息
	ChatMsgWraper m_Chat_msg;
public:
	void SetChat_msg( const ChatMsgWraper& v)
	{
		m_Chat_msg=v;
	}
	ChatMsgWraper GetChat_msg()
	{
		return m_Chat_msg;
	}
	ChatMsgWraper GetChat_msg() const
	{
		return m_Chat_msg;
	}
private:
	//队伍id
	uint64_t m_Team_id;
public:
	void SetTeam_id( uint64_t v)
	{
		m_Team_id=v;
	}
	uint64_t GetTeam_id()
	{
		return m_Team_id;
	}
	uint64_t GetTeam_id() const
	{
		return m_Team_id;
	}
private:
	//公会id 0表示无公会
	uint64_t m_Guild_guid;
public:
	void SetGuild_guid( uint64_t v)
	{
		m_Guild_guid=v;
	}
	uint64_t GetGuild_guid()
	{
		return m_Guild_guid;
	}
	uint64_t GetGuild_guid() const
	{
		return m_Guild_guid;
	}

};
//QuestData封装类
class QuestDataWraper
{
public:
	//构造函数
	QuestDataWraper()
	{
		
		m_ConfigId = -1;
		m_Status = -1;
		m_QuestIndex = 0;
		m_QuestMaxIndex = 0;
		m_QuestBeginTime = 0;

	}
	//赋值构造函数
	QuestDataWraper(const QuestData& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestData ToPB() const
	{
		QuestData v;
		v.set_configid( m_ConfigId );
		v.set_status( m_Status );
		v.mutable_queststeps()->Reserve(m_QuestSteps.size());
		for (int i=0; i<(int)m_QuestSteps.size(); i++)
		{
			*v.add_queststeps() = m_QuestSteps[i].ToPB();
		}
		v.set_questindex( m_QuestIndex );
		v.set_questmaxindex( m_QuestMaxIndex );
		v.set_questbegintime( m_QuestBeginTime );

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
		QuestData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const QuestData& v)
	{
		m_ConfigId = v.configid();
		m_Status = v.status();
		m_QuestSteps.clear();
		m_QuestSteps.reserve(v.queststeps_size());
		for( int i=0; i<v.queststeps_size(); i++)
			m_QuestSteps.push_back(v.queststeps(i));
		m_QuestIndex = v.questindex();
		m_QuestMaxIndex = v.questmaxindex();
		m_QuestBeginTime = v.questbegintime();

	}

private:
	//物品表的id
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
private:
	//Status
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//QuestSteps
	vector<QuestStepDataWraper> m_QuestSteps;
public:
	int SizeQuestSteps()
	{
		return m_QuestSteps.size();
	}
	const vector<QuestStepDataWraper>& GetQuestSteps() const
	{
		return m_QuestSteps;
	}
	QuestStepDataWraper GetQuestSteps(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestSteps.size())
		{
			assert(false);
			return QuestStepDataWraper();
		}
		return m_QuestSteps[Index];
	}
	void SetQuestSteps( const vector<QuestStepDataWraper>& v )
	{
		m_QuestSteps=v;
	}
	void ClearQuestSteps( )
	{
		m_QuestSteps.clear();
	}
	void SetQuestSteps( int Index, const QuestStepDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_QuestSteps.size())
		{
			assert(false);
			return;
		}
		m_QuestSteps[Index] = v;
	}
	void AddQuestSteps( const QuestStepDataWraper& v )
	{
		m_QuestSteps.push_back(v);
	}
private:
	//第几部任务
	INT32 m_QuestIndex;
public:
	void SetQuestIndex( INT32 v)
	{
		m_QuestIndex=v;
	}
	INT32 GetQuestIndex()
	{
		return m_QuestIndex;
	}
	INT32 GetQuestIndex() const
	{
		return m_QuestIndex;
	}
private:
	//任务最大值
	INT32 m_QuestMaxIndex;
public:
	void SetQuestMaxIndex( INT32 v)
	{
		m_QuestMaxIndex=v;
	}
	INT32 GetQuestMaxIndex()
	{
		return m_QuestMaxIndex;
	}
	INT32 GetQuestMaxIndex() const
	{
		return m_QuestMaxIndex;
	}
private:
	//任务开始时间
	int64_t m_QuestBeginTime;
public:
	void SetQuestBeginTime( int64_t v)
	{
		m_QuestBeginTime=v;
	}
	int64_t GetQuestBeginTime()
	{
		return m_QuestBeginTime;
	}
	int64_t GetQuestBeginTime() const
	{
		return m_QuestBeginTime;
	}

};
//坐骑喂养宠物道具记录封装类
class MountDevItemWraper
{
public:
	//构造函数
	MountDevItemWraper()
	{
		
		m_ItemId = -1;
		m_ItemCount = -1;

	}
	//赋值构造函数
	MountDevItemWraper(const MountDevItem& v){ Init(v); }
	//等号重载函数
	void operator = (const MountDevItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MountDevItem ToPB() const
	{
		MountDevItem v;
		v.set_itemid( m_ItemId );
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
		MountDevItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MountDevItem& v)
	{
		m_ItemId = v.itemid();
		m_ItemCount = v.itemcount();

	}

private:
	//道具ID
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
private:
	//道具数量
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
//TeamInfo封装类
class TeamInfoWraper
{
public:
	//构造函数
	TeamInfoWraper()
	{
		
		m_LeaderRoleId = 0;
		m_TeamId = 0;
		m_TeamType = -1;
		m_TeamTarget = TeamTargetWraper();

	}
	//赋值构造函数
	TeamInfoWraper(const TeamInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamInfo ToPB() const
	{
		TeamInfo v;
		v.mutable_members()->Reserve(m_Members.size());
		for (int i=0; i<(int)m_Members.size(); i++)
		{
			*v.add_members() = m_Members[i].ToPB();
		}
		v.set_leaderroleid( m_LeaderRoleId );
		v.set_teamid( m_TeamId );
		v.set_teamtype( m_TeamType );
		*v.mutable_teamtarget()= m_TeamTarget.ToPB();

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
		TeamInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamInfo& v)
	{
		m_Members.clear();
		m_Members.reserve(v.members_size());
		for( int i=0; i<v.members_size(); i++)
			m_Members.push_back(v.members(i));
		m_LeaderRoleId = v.leaderroleid();
		m_TeamId = v.teamid();
		m_TeamType = v.teamtype();
		m_TeamTarget = v.teamtarget();

	}

private:
	//Members
	vector<TeamMemberInfoWraper> m_Members;
public:
	int SizeMembers()
	{
		return m_Members.size();
	}
	const vector<TeamMemberInfoWraper>& GetMembers() const
	{
		return m_Members;
	}
	TeamMemberInfoWraper GetMembers(int Index) const
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return TeamMemberInfoWraper();
		}
		return m_Members[Index];
	}
	void SetMembers( const vector<TeamMemberInfoWraper>& v )
	{
		m_Members=v;
	}
	void ClearMembers( )
	{
		m_Members.clear();
	}
	void SetMembers( int Index, const TeamMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return;
		}
		m_Members[Index] = v;
	}
	void AddMembers( const TeamMemberInfoWraper& v )
	{
		m_Members.push_back(v);
	}
private:
	//LeaderRoleId
	uint64_t m_LeaderRoleId;
public:
	void SetLeaderRoleId( uint64_t v)
	{
		m_LeaderRoleId=v;
	}
	uint64_t GetLeaderRoleId()
	{
		return m_LeaderRoleId;
	}
	uint64_t GetLeaderRoleId() const
	{
		return m_LeaderRoleId;
	}
private:
	//TeamId
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//TeamType
	INT32 m_TeamType;
public:
	void SetTeamType( INT32 v)
	{
		m_TeamType=v;
	}
	INT32 GetTeamType()
	{
		return m_TeamType;
	}
	INT32 GetTeamType() const
	{
		return m_TeamType;
	}
private:
	//队伍目标
	TeamTargetWraper m_TeamTarget;
public:
	void SetTeamTarget( const TeamTargetWraper& v)
	{
		m_TeamTarget=v;
	}
	TeamTargetWraper GetTeamTarget()
	{
		return m_TeamTarget;
	}
	TeamTargetWraper GetTeamTarget() const
	{
		return m_TeamTarget;
	}

};
//ChatMsgVote封装类
class ChatMsgVoteWraper
{
public:
	//构造函数
	ChatMsgVoteWraper()
	{
		
		m_Chat_content = "";
		m_Chat_voice_url = "";
		m_Chat_voice_secs = -1;
		m_StringUIConfigId = -1;
		m_VoteMsgData = VoteMsgWraper();

	}
	//赋值构造函数
	ChatMsgVoteWraper(const ChatMsgVote& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatMsgVote& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatMsgVote ToPB() const
	{
		ChatMsgVote v;
		v.set_chat_content( m_Chat_content );
		v.set_chat_voice_url( m_Chat_voice_url );
		v.set_chat_voice_secs( m_Chat_voice_secs );
		v.mutable_items()->Reserve(m_Items.size());
		for (int i=0; i<(int)m_Items.size(); i++)
		{
			*v.add_items() = m_Items[i].ToPB();
		}
		v.set_stringuiconfigid( m_StringUIConfigId );
		v.mutable_params()->Reserve(m_Params.size());
		for (int i=0; i<(int)m_Params.size(); i++)
		{
			v.add_params( m_Params[i]);
		}
		*v.mutable_votemsgdata()= m_VoteMsgData.ToPB();

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
		ChatMsgVote pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatMsgVote& v)
	{
		m_Chat_content = v.chat_content();
		m_Chat_voice_url = v.chat_voice_url();
		m_Chat_voice_secs = v.chat_voice_secs();
		m_Items.clear();
		m_Items.reserve(v.items_size());
		for( int i=0; i<v.items_size(); i++)
			m_Items.push_back(v.items(i));
		m_StringUIConfigId = v.stringuiconfigid();
		m_Params.clear();
		m_Params.reserve(v.params_size());
		for( int i=0; i<v.params_size(); i++)
			m_Params.push_back(v.params(i));
		m_VoteMsgData = v.votemsgdata();

	}

private:
	//文字内容
	string m_Chat_content;
public:
	void SetChat_content( const string& v)
	{
		m_Chat_content=v;
	}
	string GetChat_content()
	{
		return m_Chat_content;
	}
	string GetChat_content() const
	{
		return m_Chat_content;
	}
private:
	//音频URL
	string m_Chat_voice_url;
public:
	void SetChat_voice_url( const string& v)
	{
		m_Chat_voice_url=v;
	}
	string GetChat_voice_url()
	{
		return m_Chat_voice_url;
	}
	string GetChat_voice_url() const
	{
		return m_Chat_voice_url;
	}
private:
	//音频秒数
	INT32 m_Chat_voice_secs;
public:
	void SetChat_voice_secs( INT32 v)
	{
		m_Chat_voice_secs=v;
	}
	INT32 GetChat_voice_secs()
	{
		return m_Chat_voice_secs;
	}
	INT32 GetChat_voice_secs() const
	{
		return m_Chat_voice_secs;
	}
private:
	//items
	vector<ItemDataWraper> m_Items;
public:
	int SizeItems()
	{
		return m_Items.size();
	}
	const vector<ItemDataWraper>& GetItems() const
	{
		return m_Items;
	}
	ItemDataWraper GetItems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return ItemDataWraper();
		}
		return m_Items[Index];
	}
	void SetItems( const vector<ItemDataWraper>& v )
	{
		m_Items=v;
	}
	void ClearItems( )
	{
		m_Items.clear();
	}
	void SetItems( int Index, const ItemDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return;
		}
		m_Items[Index] = v;
	}
	void AddItems( const ItemDataWraper& v )
	{
		m_Items.push_back(v);
	}
private:
	//StringUIConfigId
	INT32 m_StringUIConfigId;
public:
	void SetStringUIConfigId( INT32 v)
	{
		m_StringUIConfigId=v;
	}
	INT32 GetStringUIConfigId()
	{
		return m_StringUIConfigId;
	}
	INT32 GetStringUIConfigId() const
	{
		return m_StringUIConfigId;
	}
private:
	//Params
	vector<string> m_Params;
public:
	int SizeParams()
	{
		return m_Params.size();
	}
	const vector<string>& GetParams() const
	{
		return m_Params;
	}
	string GetParams(int Index) const
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return string();
		}
		return m_Params[Index];
	}
	void SetParams( const vector<string>& v )
	{
		m_Params=v;
	}
	void ClearParams( )
	{
		m_Params.clear();
	}
	void SetParams( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return;
		}
		m_Params[Index] = v;
	}
	void AddParams( const string& v )
	{
		m_Params.push_back(v);
	}
private:
	//投票数据
	VoteMsgWraper m_VoteMsgData;
public:
	void SetVoteMsgData( const VoteMsgWraper& v)
	{
		m_VoteMsgData=v;
	}
	VoteMsgWraper GetVoteMsgData()
	{
		return m_VoteMsgData;
	}
	VoteMsgWraper GetVoteMsgData() const
	{
		return m_VoteMsgData;
	}

};
//ItemObj封装类
class ItemObjWraper
{
public:
	//构造函数
	ItemObjWraper()
	{
		
		m_Pos = -1;
		m_ItemData = ItemDataWraper();
		m_RedPoint = false;

	}
	//赋值构造函数
	ItemObjWraper(const ItemObj& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemObj& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemObj ToPB() const
	{
		ItemObj v;
		v.set_pos( m_Pos );
		*v.mutable_itemdata()= m_ItemData.ToPB();
		v.set_redpoint( m_RedPoint );

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
		ItemObj pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemObj& v)
	{
		m_Pos = v.pos();
		m_ItemData = v.itemdata();
		m_RedPoint = v.redpoint();

	}

private:
	//Pos
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//ItemData
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
	//是否有红点
	bool m_RedPoint;
public:
	void SetRedPoint( bool v)
	{
		m_RedPoint=v;
	}
	bool GetRedPoint()
	{
		return m_RedPoint;
	}
	bool GetRedPoint() const
	{
		return m_RedPoint;
	}

};
//珍宝附加信息数据封装类
class TreasureExtraInfoWraper
{
public:
	//构造函数
	TreasureExtraInfoWraper()
	{
		
		m_Color_Type = -1;
		m_Time_Type = -1;
		m_State = 0;
		m_Expier_Time = -1;

	}
	//赋值构造函数
	TreasureExtraInfoWraper(const TreasureExtraInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureExtraInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureExtraInfo ToPB() const
	{
		TreasureExtraInfo v;
		v.set_color_type( m_Color_Type );
		v.set_time_type( m_Time_Type );
		v.set_state( m_State );
		v.set_expier_time( m_Expier_Time );

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
		TreasureExtraInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TreasureExtraInfo& v)
	{
		m_Color_Type = v.color_type();
		m_Time_Type = v.time_type();
		m_State = v.state();
		m_Expier_Time = v.expier_time();

	}

private:
	//颜色类型
	INT32 m_Color_Type;
public:
	void SetColor_Type( INT32 v)
	{
		m_Color_Type=v;
	}
	INT32 GetColor_Type()
	{
		return m_Color_Type;
	}
	INT32 GetColor_Type() const
	{
		return m_Color_Type;
	}
private:
	//时限类型
	INT32 m_Time_Type;
public:
	void SetTime_Type( INT32 v)
	{
		m_Time_Type=v;
	}
	INT32 GetTime_Type()
	{
		return m_Time_Type;
	}
	INT32 GetTime_Type() const
	{
		return m_Time_Type;
	}
private:
	//状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//解锁到期时间
	int64_t m_Expier_Time;
public:
	void SetExpier_Time( int64_t v)
	{
		m_Expier_Time=v;
	}
	int64_t GetExpier_Time()
	{
		return m_Expier_Time;
	}
	int64_t GetExpier_Time() const
	{
		return m_Expier_Time;
	}

};
//礼物点数封装类
class FriendGiftPointWraper
{
public:
	//构造函数
	FriendGiftPointWraper()
	{
		
		m_Guid = 0;
		m_Point = 0;

	}
	//赋值构造函数
	FriendGiftPointWraper(const FriendGiftPoint& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendGiftPoint& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendGiftPoint ToPB() const
	{
		FriendGiftPoint v;
		v.set_guid( m_Guid );
		v.set_point( m_Point );

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
		FriendGiftPoint pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const FriendGiftPoint& v)
	{
		m_Guid = v.guid();
		m_Point = v.point();

	}

private:
	//玩家guid
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
	//点数
	INT32 m_Point;
public:
	void SetPoint( INT32 v)
	{
		m_Point=v;
	}
	INT32 GetPoint()
	{
		return m_Point;
	}
	INT32 GetPoint() const
	{
		return m_Point;
	}

};
//整形坐标 需要除100封装类
class Vector3IntWraper
{
public:
	//构造函数
	Vector3IntWraper()
	{
		
		m_X = -1;
		m_Z = -1;

	}
	//赋值构造函数
	Vector3IntWraper(const Vector3Int& v){ Init(v); }
	//等号重载函数
	void operator = (const Vector3Int& v){ Init(v); }
 	//转化成Protobuffer类型函数
	Vector3Int ToPB() const
	{
		Vector3Int v;
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
		Vector3Int pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const Vector3Int& v)
	{
		m_X = v.x();
		m_Z = v.z();

	}

private:
	//X
	INT32 m_X;
public:
	void SetX( INT32 v)
	{
		m_X=v;
	}
	INT32 GetX()
	{
		return m_X;
	}
	INT32 GetX() const
	{
		return m_X;
	}
private:
	//Z
	INT32 m_Z;
public:
	void SetZ( INT32 v)
	{
		m_Z=v;
	}
	INT32 GetZ()
	{
		return m_Z;
	}
	INT32 GetZ() const
	{
		return m_Z;
	}

};
//道具分解设定数据封装类
class ItemResolveDataWraper
{
public:
	//构造函数
	ItemResolveDataWraper()
	{
		
		m_Qulity = -1;
		m_IsResolve = 0;

	}
	//赋值构造函数
	ItemResolveDataWraper(const ItemResolveData& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemResolveData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemResolveData ToPB() const
	{
		ItemResolveData v;
		v.set_qulity( m_Qulity );
		v.set_isresolve( m_IsResolve );

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
		ItemResolveData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemResolveData& v)
	{
		m_Qulity = v.qulity();
		m_IsResolve = v.isresolve();

	}

private:
	//道具品质
	INT32 m_Qulity;
public:
	void SetQulity( INT32 v)
	{
		m_Qulity=v;
	}
	INT32 GetQulity()
	{
		return m_Qulity;
	}
	INT32 GetQulity() const
	{
		return m_Qulity;
	}
private:
	//是否设定自动分解
	INT32 m_IsResolve;
public:
	void SetIsResolve( INT32 v)
	{
		m_IsResolve=v;
	}
	INT32 GetIsResolve()
	{
		return m_IsResolve;
	}
	INT32 GetIsResolve() const
	{
		return m_IsResolve;
	}

};
//完成任务id封装类
class MaxQuestCompleteIdWraper
{
public:
	//构造函数
	MaxQuestCompleteIdWraper()
	{
		
		m_QuestType = -1;
		m_MaxConfigId = -1;

	}
	//赋值构造函数
	MaxQuestCompleteIdWraper(const MaxQuestCompleteId& v){ Init(v); }
	//等号重载函数
	void operator = (const MaxQuestCompleteId& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MaxQuestCompleteId ToPB() const
	{
		MaxQuestCompleteId v;
		v.set_questtype( m_QuestType );
		v.set_maxconfigid( m_MaxConfigId );

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
		MaxQuestCompleteId pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MaxQuestCompleteId& v)
	{
		m_QuestType = v.questtype();
		m_MaxConfigId = v.maxconfigid();

	}

private:
	//任务类型
	INT32 m_QuestType;
public:
	void SetQuestType( INT32 v)
	{
		m_QuestType=v;
	}
	INT32 GetQuestType()
	{
		return m_QuestType;
	}
	INT32 GetQuestType() const
	{
		return m_QuestType;
	}
private:
	//最大任务id
	INT32 m_MaxConfigId;
public:
	void SetMaxConfigId( INT32 v)
	{
		m_MaxConfigId=v;
	}
	INT32 GetMaxConfigId()
	{
		return m_MaxConfigId;
	}
	INT32 GetMaxConfigId() const
	{
		return m_MaxConfigId;
	}

};
//收到赠送列表封装类
class FriendGifPointListWraper
{
public:
	//构造函数
	FriendGifPointListWraper()
	{
		

	}
	//赋值构造函数
	FriendGifPointListWraper(const FriendGifPointList& v){ Init(v); }
	//等号重载函数
	void operator = (const FriendGifPointList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FriendGifPointList ToPB() const
	{
		FriendGifPointList v;
		v.mutable_sentgiftlist()->Reserve(m_SentGiftList.size());
		for (int i=0; i<(int)m_SentGiftList.size(); i++)
		{
			*v.add_sentgiftlist() = m_SentGiftList[i].ToPB();
		}
		v.mutable_acquiregiftlist()->Reserve(m_AcquireGiftList.size());
		for (int i=0; i<(int)m_AcquireGiftList.size(); i++)
		{
			*v.add_acquiregiftlist() = m_AcquireGiftList[i].ToPB();
		}
		v.mutable_unacquiregiftlist()->Reserve(m_UnAcquireGiftList.size());
		for (int i=0; i<(int)m_UnAcquireGiftList.size(); i++)
		{
			*v.add_unacquiregiftlist() = m_UnAcquireGiftList[i].ToPB();
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
		FriendGifPointList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const FriendGifPointList& v)
	{
		m_SentGiftList.clear();
		m_SentGiftList.reserve(v.sentgiftlist_size());
		for( int i=0; i<v.sentgiftlist_size(); i++)
			m_SentGiftList.push_back(v.sentgiftlist(i));
		m_AcquireGiftList.clear();
		m_AcquireGiftList.reserve(v.acquiregiftlist_size());
		for( int i=0; i<v.acquiregiftlist_size(); i++)
			m_AcquireGiftList.push_back(v.acquiregiftlist(i));
		m_UnAcquireGiftList.clear();
		m_UnAcquireGiftList.reserve(v.unacquiregiftlist_size());
		for( int i=0; i<v.unacquiregiftlist_size(); i++)
			m_UnAcquireGiftList.push_back(v.unacquiregiftlist(i));

	}

private:
	//已经赠送列表
	vector<FriendGiftPointWraper> m_SentGiftList;
public:
	int SizeSentGiftList()
	{
		return m_SentGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetSentGiftList() const
	{
		return m_SentGiftList;
	}
	FriendGiftPointWraper GetSentGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_SentGiftList[Index];
	}
	void SetSentGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_SentGiftList=v;
	}
	void ClearSentGiftList( )
	{
		m_SentGiftList.clear();
	}
	void SetSentGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_SentGiftList.size())
		{
			assert(false);
			return;
		}
		m_SentGiftList[Index] = v;
	}
	void AddSentGiftList( const FriendGiftPointWraper& v )
	{
		m_SentGiftList.push_back(v);
	}
private:
	//已经收取列表
	vector<FriendGiftPointWraper> m_AcquireGiftList;
public:
	int SizeAcquireGiftList()
	{
		return m_AcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetAcquireGiftList() const
	{
		return m_AcquireGiftList;
	}
	FriendGiftPointWraper GetAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_AcquireGiftList[Index];
	}
	void SetAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_AcquireGiftList=v;
	}
	void ClearAcquireGiftList( )
	{
		m_AcquireGiftList.clear();
	}
	void SetAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_AcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_AcquireGiftList[Index] = v;
	}
	void AddAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_AcquireGiftList.push_back(v);
	}
private:
	//可收取
	vector<FriendGiftPointWraper> m_UnAcquireGiftList;
public:
	int SizeUnAcquireGiftList()
	{
		return m_UnAcquireGiftList.size();
	}
	const vector<FriendGiftPointWraper>& GetUnAcquireGiftList() const
	{
		return m_UnAcquireGiftList;
	}
	FriendGiftPointWraper GetUnAcquireGiftList(int Index) const
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return FriendGiftPointWraper();
		}
		return m_UnAcquireGiftList[Index];
	}
	void SetUnAcquireGiftList( const vector<FriendGiftPointWraper>& v )
	{
		m_UnAcquireGiftList=v;
	}
	void ClearUnAcquireGiftList( )
	{
		m_UnAcquireGiftList.clear();
	}
	void SetUnAcquireGiftList( int Index, const FriendGiftPointWraper& v )
	{
		if(Index<0 || Index>=(int)m_UnAcquireGiftList.size())
		{
			assert(false);
			return;
		}
		m_UnAcquireGiftList[Index] = v;
	}
	void AddUnAcquireGiftList( const FriendGiftPointWraper& v )
	{
		m_UnAcquireGiftList.push_back(v);
	}

};
//当前完成数量封装类
class DungeonTargetContentWraper
{
public:
	//构造函数
	DungeonTargetContentWraper()
	{
		
		m_Index = -1;
		m_TemplateId = -1;
		m_MaxCount = -1;
		m_CurCount = -1;
		m_Description = -1;
		m_IParam = -1;

	}
	//赋值构造函数
	DungeonTargetContentWraper(const DungeonTargetContent& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonTargetContent& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonTargetContent ToPB() const
	{
		DungeonTargetContent v;
		v.set_index( m_Index );
		v.set_templateid( m_TemplateId );
		v.set_maxcount( m_MaxCount );
		v.set_curcount( m_CurCount );
		v.set_description( m_Description );
		v.set_iparam( m_IParam );

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
		DungeonTargetContent pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DungeonTargetContent& v)
	{
		m_Index = v.index();
		m_TemplateId = v.templateid();
		m_MaxCount = v.maxcount();
		m_CurCount = v.curcount();
		m_Description = v.description();
		m_IParam = v.iparam();

	}

private:
	//子任务序号
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
private:
	//模板id
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}
private:
	//目标数量
	INT32 m_MaxCount;
public:
	void SetMaxCount( INT32 v)
	{
		m_MaxCount=v;
	}
	INT32 GetMaxCount()
	{
		return m_MaxCount;
	}
	INT32 GetMaxCount() const
	{
		return m_MaxCount;
	}
private:
	//当前完成数量
	INT32 m_CurCount;
public:
	void SetCurCount( INT32 v)
	{
		m_CurCount=v;
	}
	INT32 GetCurCount()
	{
		return m_CurCount;
	}
	INT32 GetCurCount() const
	{
		return m_CurCount;
	}
private:
	//描述文字Id
	INT32 m_Description;
public:
	void SetDescription( INT32 v)
	{
		m_Description=v;
	}
	INT32 GetDescription()
	{
		return m_Description;
	}
	INT32 GetDescription() const
	{
		return m_Description;
	}
private:
	//目标参数
	INT32 m_IParam;
public:
	void SetIParam( INT32 v)
	{
		m_IParam=v;
	}
	INT32 GetIParam()
	{
		return m_IParam;
	}
	INT32 GetIParam() const
	{
		return m_IParam;
	}

};
//拍卖的商品封装类
class AuctionItemWraper
{
public:
	//构造函数
	AuctionItemWraper()
	{
		
		m_OwnerGuid = 0;
		m_Price = 1;
		m_Currency = 1;
		m_ItemData = ItemDataWraper();
		m_Status = 0;
		m_SaleTS = -1;

	}
	//赋值构造函数
	AuctionItemWraper(const AuctionItem& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionItem ToPB() const
	{
		AuctionItem v;
		v.set_ownerguid( m_OwnerGuid );
		v.set_price( m_Price );
		v.set_currency( m_Currency );
		*v.mutable_itemdata()= m_ItemData.ToPB();
		v.set_status( m_Status );
		v.set_salets( m_SaleTS );

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
		AuctionItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AuctionItem& v)
	{
		m_OwnerGuid = v.ownerguid();
		m_Price = v.price();
		m_Currency = v.currency();
		m_ItemData = v.itemdata();
		m_Status = v.status();
		m_SaleTS = v.salets();

	}

private:
	//拍卖商品的人guid
	uint64_t m_OwnerGuid;
public:
	void SetOwnerGuid( uint64_t v)
	{
		m_OwnerGuid=v;
	}
	uint64_t GetOwnerGuid()
	{
		return m_OwnerGuid;
	}
	uint64_t GetOwnerGuid() const
	{
		return m_OwnerGuid;
	}
private:
	//拍卖报价
	INT32 m_Price;
public:
	void SetPrice( INT32 v)
	{
		m_Price=v;
	}
	INT32 GetPrice()
	{
		return m_Price;
	}
	INT32 GetPrice() const
	{
		return m_Price;
	}
private:
	//钱币种类
	INT32 m_Currency;
public:
	void SetCurrency( INT32 v)
	{
		m_Currency=v;
	}
	INT32 GetCurrency()
	{
		return m_Currency;
	}
	INT32 GetCurrency() const
	{
		return m_Currency;
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
	//道具状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//上架时间
	INT32 m_SaleTS;
public:
	void SetSaleTS( INT32 v)
	{
		m_SaleTS=v;
	}
	INT32 GetSaleTS()
	{
		return m_SaleTS;
	}
	INT32 GetSaleTS() const
	{
		return m_SaleTS;
	}

};
//每层随机到的3个备选buf封装类
class ClimTowerBuffListWraper
{
public:
	//构造函数
	ClimTowerBuffListWraper()
	{
		
		m_Tower = -1;

	}
	//赋值构造函数
	ClimTowerBuffListWraper(const ClimTowerBuffList& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerBuffList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerBuffList ToPB() const
	{
		ClimTowerBuffList v;
		v.set_tower( m_Tower );
		v.mutable_buffid()->Reserve(m_BuffId.size());
		for (int i=0; i<(int)m_BuffId.size(); i++)
		{
			v.add_buffid(m_BuffId[i]);
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
		ClimTowerBuffList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ClimTowerBuffList& v)
	{
		m_Tower = v.tower();
		m_BuffId.clear();
		m_BuffId.reserve(v.buffid_size());
		for( int i=0; i<v.buffid_size(); i++)
			m_BuffId.push_back(v.buffid(i));

	}

private:
	//塔索引
	INT32 m_Tower;
public:
	void SetTower( INT32 v)
	{
		m_Tower=v;
	}
	INT32 GetTower()
	{
		return m_Tower;
	}
	INT32 GetTower() const
	{
		return m_Tower;
	}
private:
	//每个塔备选BufId
	vector<INT32> m_BuffId;
public:
	int SizeBuffId()
	{
		return m_BuffId.size();
	}
	const vector<INT32>& GetBuffId() const
	{
		return m_BuffId;
	}
	INT32 GetBuffId(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffId.size())
		{
			assert(false);
			return INT32();
		}
		return m_BuffId[Index];
	}
	void SetBuffId( const vector<INT32>& v )
	{
		m_BuffId=v;
	}
	void ClearBuffId( )
	{
		m_BuffId.clear();
	}
	void SetBuffId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_BuffId.size())
		{
			assert(false);
			return;
		}
		m_BuffId[Index] = v;
	}
	void AddBuffId( INT32 v = -1 )
	{
		m_BuffId.push_back(v);
	}

};
//福利奖励封装类
class WelfareRewardWraper
{
public:
	//构造函数
	WelfareRewardWraper()
	{
		
		m_RewardID = -1;
		m_RewardNum = -1;

	}
	//赋值构造函数
	WelfareRewardWraper(const WelfareReward& v){ Init(v); }
	//等号重载函数
	void operator = (const WelfareReward& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WelfareReward ToPB() const
	{
		WelfareReward v;
		v.set_rewardid( m_RewardID );
		v.set_rewardnum( m_RewardNum );

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
		WelfareReward pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WelfareReward& v)
	{
		m_RewardID = v.rewardid();
		m_RewardNum = v.rewardnum();

	}

private:
	//奖励ID
	INT32 m_RewardID;
public:
	void SetRewardID( INT32 v)
	{
		m_RewardID=v;
	}
	INT32 GetRewardID()
	{
		return m_RewardID;
	}
	INT32 GetRewardID() const
	{
		return m_RewardID;
	}
private:
	//奖励数量
	INT32 m_RewardNum;
public:
	void SetRewardNum( INT32 v)
	{
		m_RewardNum=v;
	}
	INT32 GetRewardNum()
	{
		return m_RewardNum;
	}
	INT32 GetRewardNum() const
	{
		return m_RewardNum;
	}

};
//世界BOSS得分信息封装类
class WorldBossScoreInfoWraper
{
public:
	//构造函数
	WorldBossScoreInfoWraper()
	{
		
		m_Playerguid = 0;
		m_Level = -1;
		m_Name = "";
		m_Occupation = -1;
		m_RankAll = -1;
		m_RankOccupation = -1;
		m_Score = -1;
		m_Capacity = -1;

	}
	//赋值构造函数
	WorldBossScoreInfoWraper(const WorldBossScoreInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossScoreInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossScoreInfo ToPB() const
	{
		WorldBossScoreInfo v;
		v.set_playerguid( m_Playerguid );
		v.set_level( m_Level );
		v.set_name( m_Name );
		v.set_occupation( m_Occupation );
		v.set_rankall( m_RankAll );
		v.set_rankoccupation( m_RankOccupation );
		v.set_score( m_Score );
		v.set_capacity( m_Capacity );

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
		WorldBossScoreInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossScoreInfo& v)
	{
		m_Playerguid = v.playerguid();
		m_Level = v.level();
		m_Name = v.name();
		m_Occupation = v.occupation();
		m_RankAll = v.rankall();
		m_RankOccupation = v.rankoccupation();
		m_Score = v.score();
		m_Capacity = v.capacity();

	}

private:
	//playerguid
	uint64_t m_Playerguid;
public:
	void SetPlayerguid( uint64_t v)
	{
		m_Playerguid=v;
	}
	uint64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	uint64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
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
	//所有排名
	INT32 m_RankAll;
public:
	void SetRankAll( INT32 v)
	{
		m_RankAll=v;
	}
	INT32 GetRankAll()
	{
		return m_RankAll;
	}
	INT32 GetRankAll() const
	{
		return m_RankAll;
	}
private:
	//职业排名
	INT32 m_RankOccupation;
public:
	void SetRankOccupation( INT32 v)
	{
		m_RankOccupation=v;
	}
	INT32 GetRankOccupation()
	{
		return m_RankOccupation;
	}
	INT32 GetRankOccupation() const
	{
		return m_RankOccupation;
	}
private:
	//积分
	INT32 m_Score;
public:
	void SetScore( INT32 v)
	{
		m_Score=v;
	}
	INT32 GetScore()
	{
		return m_Score;
	}
	INT32 GetScore() const
	{
		return m_Score;
	}
private:
	//战力
	INT32 m_Capacity;
public:
	void SetCapacity( INT32 v)
	{
		m_Capacity=v;
	}
	INT32 GetCapacity()
	{
		return m_Capacity;
	}
	INT32 GetCapacity() const
	{
		return m_Capacity;
	}

};
//玩家匹配信息封装类
class PlayerMatchDataWraper
{
public:
	//构造函数
	PlayerMatchDataWraper()
	{
		
		m_MatchType = 0;
		m_Elo = 0;
		m_Auto = 0;

	}
	//赋值构造函数
	PlayerMatchDataWraper(const PlayerMatchData& v){ Init(v); }
	//等号重载函数
	void operator = (const PlayerMatchData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PlayerMatchData ToPB() const
	{
		PlayerMatchData v;
		v.set_matchtype( m_MatchType );
		v.set_elo( m_Elo );
		v.set_auto( m_Auto );

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
		PlayerMatchData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PlayerMatchData& v)
	{
		m_MatchType = v.matchtype();
		m_Elo = v.elo();
		m_Auto = v.auto();

	}

private:
	//匹配类型
	INT32 m_MatchType;
public:
	void SetMatchType( INT32 v)
	{
		m_MatchType=v;
	}
	INT32 GetMatchType()
	{
		return m_MatchType;
	}
	INT32 GetMatchType() const
	{
		return m_MatchType;
	}
private:
	//匹配elo
	INT32 m_Elo;
public:
	void SetElo( INT32 v)
	{
		m_Elo=v;
	}
	INT32 GetElo()
	{
		return m_Elo;
	}
	INT32 GetElo() const
	{
		return m_Elo;
	}
private:
	//是否自动匹配
	INT32 m_Auto;
public:
	void SetAuto( INT32 v)
	{
		m_Auto=v;
	}
	INT32 GetAuto()
	{
		return m_Auto;
	}
	INT32 GetAuto() const
	{
		return m_Auto;
	}

};
//场景线的状态封装类
class LineStatsWraper
{
public:
	//构造函数
	LineStatsWraper()
	{
		
		m_LineId = -1;
		m_LineStats = -1;

	}
	//赋值构造函数
	LineStatsWraper(const LineStats& v){ Init(v); }
	//等号重载函数
	void operator = (const LineStats& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LineStats ToPB() const
	{
		LineStats v;
		v.set_lineid( m_LineId );
		v.set_linestats( m_LineStats );

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
		LineStats pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const LineStats& v)
	{
		m_LineId = v.lineid();
		m_LineStats = v.linestats();

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
	//线的状态
	INT32 m_LineStats;
public:
	void SetLineStats( INT32 v)
	{
		m_LineStats=v;
	}
	INT32 GetLineStats()
	{
		return m_LineStats;
	}
	INT32 GetLineStats() const
	{
		return m_LineStats;
	}

};
//好友分组封装类
class ContactGroupWraper
{
public:
	//构造函数
	ContactGroupWraper()
	{
		
		m_GroupName = "";
		m_GroupId = -1;

	}
	//赋值构造函数
	ContactGroupWraper(const ContactGroup& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactGroup& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactGroup ToPB() const
	{
		ContactGroup v;
		v.set_groupname( m_GroupName );
		v.mutable_grouproleids()->Reserve(m_GroupRoleIds.size());
		for (int i=0; i<(int)m_GroupRoleIds.size(); i++)
		{
			v.add_grouproleids(m_GroupRoleIds[i]);
		}
		v.set_groupid( m_GroupId );

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
		ContactGroup pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ContactGroup& v)
	{
		m_GroupName = v.groupname();
		m_GroupRoleIds.clear();
		m_GroupRoleIds.reserve(v.grouproleids_size());
		for( int i=0; i<v.grouproleids_size(); i++)
			m_GroupRoleIds.push_back(v.grouproleids(i));
		m_GroupId = v.groupid();

	}

private:
	//分组名字
	string m_GroupName;
public:
	void SetGroupName( const string& v)
	{
		m_GroupName=v;
	}
	string GetGroupName()
	{
		return m_GroupName;
	}
	string GetGroupName() const
	{
		return m_GroupName;
	}
private:
	//分组好友Id
	vector<uint64_t> m_GroupRoleIds;
public:
	int SizeGroupRoleIds()
	{
		return m_GroupRoleIds.size();
	}
	const vector<uint64_t>& GetGroupRoleIds() const
	{
		return m_GroupRoleIds;
	}
	uint64_t GetGroupRoleIds(int Index) const
	{
		if(Index<0 || Index>=(int)m_GroupRoleIds.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_GroupRoleIds[Index];
	}
	void SetGroupRoleIds( const vector<uint64_t>& v )
	{
		m_GroupRoleIds=v;
	}
	void ClearGroupRoleIds( )
	{
		m_GroupRoleIds.clear();
	}
	void SetGroupRoleIds( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_GroupRoleIds.size())
		{
			assert(false);
			return;
		}
		m_GroupRoleIds[Index] = v;
	}
	void AddGroupRoleIds( uint64_t v = 0 )
	{
		m_GroupRoleIds.push_back(v);
	}
private:
	//组Id
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}

};
//联系人设置封装类
class ContactSettingWraper
{
public:
	//构造函数
	ContactSettingWraper()
	{
		
		m_CloseApplyFriend = -1;
		m_ClearFirend = -1;

	}
	//赋值构造函数
	ContactSettingWraper(const ContactSetting& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactSetting& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactSetting ToPB() const
	{
		ContactSetting v;
		v.set_closeapplyfriend( m_CloseApplyFriend );
		v.set_clearfirend( m_ClearFirend );

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
		ContactSetting pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ContactSetting& v)
	{
		m_CloseApplyFriend = v.closeapplyfriend();
		m_ClearFirend = v.clearfirend();

	}

private:
	//好友申请
	INT32 m_CloseApplyFriend;
public:
	void SetCloseApplyFriend( INT32 v)
	{
		m_CloseApplyFriend=v;
	}
	INT32 GetCloseApplyFriend()
	{
		return m_CloseApplyFriend;
	}
	INT32 GetCloseApplyFriend() const
	{
		return m_CloseApplyFriend;
	}
private:
	//自动清除好友
	INT32 m_ClearFirend;
public:
	void SetClearFirend( INT32 v)
	{
		m_ClearFirend=v;
	}
	INT32 GetClearFirend()
	{
		return m_ClearFirend;
	}
	INT32 GetClearFirend() const
	{
		return m_ClearFirend;
	}

};
//匹配房间的阵营列表封装类
class MatchRoomCampsWraper
{
public:
	//构造函数
	MatchRoomCampsWraper()
	{
		

	}
	//赋值构造函数
	MatchRoomCampsWraper(const MatchRoomCamps& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRoomCamps& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRoomCamps ToPB() const
	{
		MatchRoomCamps v;
		v.mutable_players()->Reserve(m_Players.size());
		for (int i=0; i<(int)m_Players.size(); i++)
		{
			*v.add_players() = m_Players[i].ToPB();
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
		MatchRoomCamps pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MatchRoomCamps& v)
	{
		m_Players.clear();
		m_Players.reserve(v.players_size());
		for( int i=0; i<v.players_size(); i++)
			m_Players.push_back(v.players(i));

	}

private:
	//玩家
	vector<MatchInfoWraper> m_Players;
public:
	int SizePlayers()
	{
		return m_Players.size();
	}
	const vector<MatchInfoWraper>& GetPlayers() const
	{
		return m_Players;
	}
	MatchInfoWraper GetPlayers(int Index) const
	{
		if(Index<0 || Index>=(int)m_Players.size())
		{
			assert(false);
			return MatchInfoWraper();
		}
		return m_Players[Index];
	}
	void SetPlayers( const vector<MatchInfoWraper>& v )
	{
		m_Players=v;
	}
	void ClearPlayers( )
	{
		m_Players.clear();
	}
	void SetPlayers( int Index, const MatchInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Players.size())
		{
			assert(false);
			return;
		}
		m_Players[Index] = v;
	}
	void AddPlayers( const MatchInfoWraper& v )
	{
		m_Players.push_back(v);
	}

};
//竞技场奖励信息封装类
class PvpBattleRewardInfoWraper
{
public:
	//构造函数
	PvpBattleRewardInfoWraper()
	{
		
		m_ItemID = -1;
		m_ItemCout = -1;

	}
	//赋值构造函数
	PvpBattleRewardInfoWraper(const PvpBattleRewardInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpBattleRewardInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpBattleRewardInfo ToPB() const
	{
		PvpBattleRewardInfo v;
		v.set_itemid( m_ItemID );
		v.set_itemcout( m_ItemCout );

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
		PvpBattleRewardInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpBattleRewardInfo& v)
	{
		m_ItemID = v.itemid();
		m_ItemCout = v.itemcout();

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
	//道具数量
	INT32 m_ItemCout;
public:
	void SetItemCout( INT32 v)
	{
		m_ItemCout=v;
	}
	INT32 GetItemCout()
	{
		return m_ItemCout;
	}
	INT32 GetItemCout() const
	{
		return m_ItemCout;
	}

};
//MailItem封装类
class MailItemWraper
{
public:
	//构造函数
	MailItemWraper()
	{
		
		m_ItemID = -1;
		m_ItemCount = -1;
		m_Transit = false;

	}
	//赋值构造函数
	MailItemWraper(const MailItem& v){ Init(v); }
	//等号重载函数
	void operator = (const MailItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailItem ToPB() const
	{
		MailItem v;
		v.set_itemid( m_ItemID );
		v.set_itemcount( m_ItemCount );
		v.set_transit( m_Transit );

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
		MailItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MailItem& v)
	{
		m_ItemID = v.itemid();
		m_ItemCount = v.itemcount();
		m_Transit = v.transit();

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
	//道具数量
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
private:
	//transit
	bool m_Transit;
public:
	void SetTransit( bool v)
	{
		m_Transit=v;
	}
	bool GetTransit()
	{
		return m_Transit;
	}
	bool GetTransit() const
	{
		return m_Transit;
	}

};
//功能和UI开关封装类
class UICategoryDataWraper
{
public:
	//构造函数
	UICategoryDataWraper()
	{
		
		m_Index = -1;
		m_Locked = true;

	}
	//赋值构造函数
	UICategoryDataWraper(const UICategoryData& v){ Init(v); }
	//等号重载函数
	void operator = (const UICategoryData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	UICategoryData ToPB() const
	{
		UICategoryData v;
		v.set_index( m_Index );
		v.set_locked( m_Locked );

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
		UICategoryData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const UICategoryData& v)
	{
		m_Index = v.index();
		m_Locked = v.locked();

	}

private:
	//功能或UI在UICategory中的索引
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
private:
	//是否锁定
	bool m_Locked;
public:
	void SetLocked( bool v)
	{
		m_Locked=v;
	}
	bool GetLocked()
	{
		return m_Locked;
	}
	bool GetLocked() const
	{
		return m_Locked;
	}

};
//房间基础信息封装类
class RoomBaseInfoWraper
{
public:
	//构造函数
	RoomBaseInfoWraper()
	{
		
		m_Name = "";
		m_ManageRoleId = 0;
		m_Announcement = "";
		m_RoomId = 0;
		m_RoomType = 0;
		m_LastChatTime = 0;

	}
	//赋值构造函数
	RoomBaseInfoWraper(const RoomBaseInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const RoomBaseInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RoomBaseInfo ToPB() const
	{
		RoomBaseInfo v;
		v.set_name( m_Name );
		v.set_manageroleid( m_ManageRoleId );
		v.set_announcement( m_Announcement );
		v.set_roomid( m_RoomId );
		v.set_roomtype( m_RoomType );
		v.set_lastchattime( m_LastChatTime );

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
		RoomBaseInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RoomBaseInfo& v)
	{
		m_Name = v.name();
		m_ManageRoleId = v.manageroleid();
		m_Announcement = v.announcement();
		m_RoomId = v.roomid();
		m_RoomType = v.roomtype();
		m_LastChatTime = v.lastchattime();

	}

private:
	//房间名字
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
	//群主名字
	uint64_t m_ManageRoleId;
public:
	void SetManageRoleId( uint64_t v)
	{
		m_ManageRoleId=v;
	}
	uint64_t GetManageRoleId()
	{
		return m_ManageRoleId;
	}
	uint64_t GetManageRoleId() const
	{
		return m_ManageRoleId;
	}
private:
	//公告
	string m_Announcement;
public:
	void SetAnnouncement( const string& v)
	{
		m_Announcement=v;
	}
	string GetAnnouncement()
	{
		return m_Announcement;
	}
	string GetAnnouncement() const
	{
		return m_Announcement;
	}
private:
	//房间唯一id
	uint64_t m_RoomId;
public:
	void SetRoomId( uint64_t v)
	{
		m_RoomId=v;
	}
	uint64_t GetRoomId()
	{
		return m_RoomId;
	}
	uint64_t GetRoomId() const
	{
		return m_RoomId;
	}
private:
	//RoomType
	INT32 m_RoomType;
public:
	void SetRoomType( INT32 v)
	{
		m_RoomType=v;
	}
	INT32 GetRoomType()
	{
		return m_RoomType;
	}
	INT32 GetRoomType() const
	{
		return m_RoomType;
	}
private:
	//LastChatTime
	int64_t m_LastChatTime;
public:
	void SetLastChatTime( int64_t v)
	{
		m_LastChatTime=v;
	}
	int64_t GetLastChatTime()
	{
		return m_LastChatTime;
	}
	int64_t GetLastChatTime() const
	{
		return m_LastChatTime;
	}

};
//生活配方数据封装类
class LifeFormulaDataWraper
{
public:
	//构造函数
	LifeFormulaDataWraper()
	{
		
		m_FormulaID = -1;
		m_LastRefreshTime = -1;
		m_MakeTimes = -1;

	}
	//赋值构造函数
	LifeFormulaDataWraper(const LifeFormulaData& v){ Init(v); }
	//等号重载函数
	void operator = (const LifeFormulaData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LifeFormulaData ToPB() const
	{
		LifeFormulaData v;
		v.set_formulaid( m_FormulaID );
		v.set_lastrefreshtime( m_LastRefreshTime );
		v.set_maketimes( m_MakeTimes );

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
		LifeFormulaData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const LifeFormulaData& v)
	{
		m_FormulaID = v.formulaid();
		m_LastRefreshTime = v.lastrefreshtime();
		m_MakeTimes = v.maketimes();

	}

private:
	//配方id
	INT32 m_FormulaID;
public:
	void SetFormulaID( INT32 v)
	{
		m_FormulaID=v;
	}
	INT32 GetFormulaID()
	{
		return m_FormulaID;
	}
	INT32 GetFormulaID() const
	{
		return m_FormulaID;
	}
private:
	//上次刷新时间
	INT32 m_LastRefreshTime;
public:
	void SetLastRefreshTime( INT32 v)
	{
		m_LastRefreshTime=v;
	}
	INT32 GetLastRefreshTime()
	{
		return m_LastRefreshTime;
	}
	INT32 GetLastRefreshTime() const
	{
		return m_LastRefreshTime;
	}
private:
	//当前配方制作次数
	INT32 m_MakeTimes;
public:
	void SetMakeTimes( INT32 v)
	{
		m_MakeTimes=v;
	}
	INT32 GetMakeTimes()
	{
		return m_MakeTimes;
	}
	INT32 GetMakeTimes() const
	{
		return m_MakeTimes;
	}

};
//ResolveUnit封装类
class ResolveUnitWraper
{
public:
	//构造函数
	ResolveUnitWraper()
	{
		
		m_ItemType = -1;

	}
	//赋值构造函数
	ResolveUnitWraper(const ResolveUnit& v){ Init(v); }
	//等号重载函数
	void operator = (const ResolveUnit& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ResolveUnit ToPB() const
	{
		ResolveUnit v;
		v.mutable_resolvelist()->Reserve(m_ResolveList.size());
		for (int i=0; i<(int)m_ResolveList.size(); i++)
		{
			*v.add_resolvelist() = m_ResolveList[i].ToPB();
		}
		v.set_itemtype( m_ItemType );

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
		ResolveUnit pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ResolveUnit& v)
	{
		m_ResolveList.clear();
		m_ResolveList.reserve(v.resolvelist_size());
		for( int i=0; i<v.resolvelist_size(); i++)
			m_ResolveList.push_back(v.resolvelist(i));
		m_ItemType = v.itemtype();

	}

private:
	//分解数据列表
	vector<ItemResolveDataWraper> m_ResolveList;
public:
	int SizeResolveList()
	{
		return m_ResolveList.size();
	}
	const vector<ItemResolveDataWraper>& GetResolveList() const
	{
		return m_ResolveList;
	}
	ItemResolveDataWraper GetResolveList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ResolveList.size())
		{
			assert(false);
			return ItemResolveDataWraper();
		}
		return m_ResolveList[Index];
	}
	void SetResolveList( const vector<ItemResolveDataWraper>& v )
	{
		m_ResolveList=v;
	}
	void ClearResolveList( )
	{
		m_ResolveList.clear();
	}
	void SetResolveList( int Index, const ItemResolveDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ResolveList.size())
		{
			assert(false);
			return;
		}
		m_ResolveList[Index] = v;
	}
	void AddResolveList( const ItemResolveDataWraper& v )
	{
		m_ResolveList.push_back(v);
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}

};
//ChatRoomPlayerData封装类
class ChatRoomPlayerDataWraper
{
public:
	//构造函数
	ChatRoomPlayerDataWraper()
	{
		
		m_PlayerContact = ContactDataWraper();
		m_NewMsgCount = 0;
		m_LastReadTime = -1;
		m_JoinTime = 0;
		m_ClearIndex = 0;

	}
	//赋值构造函数
	ChatRoomPlayerDataWraper(const ChatRoomPlayerData& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRoomPlayerData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRoomPlayerData ToPB() const
	{
		ChatRoomPlayerData v;
		*v.mutable_playercontact()= m_PlayerContact.ToPB();
		v.set_newmsgcount( m_NewMsgCount );
		v.set_lastreadtime( m_LastReadTime );
		v.set_jointime( m_JoinTime );
		v.set_clearindex( m_ClearIndex );

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
		ChatRoomPlayerData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatRoomPlayerData& v)
	{
		m_PlayerContact = v.playercontact();
		m_NewMsgCount = v.newmsgcount();
		m_LastReadTime = v.lastreadtime();
		m_JoinTime = v.jointime();
		m_ClearIndex = v.clearindex();

	}

private:
	//玩家信息
	ContactDataWraper m_PlayerContact;
public:
	void SetPlayerContact( const ContactDataWraper& v)
	{
		m_PlayerContact=v;
	}
	ContactDataWraper GetPlayerContact()
	{
		return m_PlayerContact;
	}
	ContactDataWraper GetPlayerContact() const
	{
		return m_PlayerContact;
	}
private:
	//NewMsgCount
	INT32 m_NewMsgCount;
public:
	void SetNewMsgCount( INT32 v)
	{
		m_NewMsgCount=v;
	}
	INT32 GetNewMsgCount()
	{
		return m_NewMsgCount;
	}
	INT32 GetNewMsgCount() const
	{
		return m_NewMsgCount;
	}
private:
	//LastReadTime
	int64_t m_LastReadTime;
public:
	void SetLastReadTime( int64_t v)
	{
		m_LastReadTime=v;
	}
	int64_t GetLastReadTime()
	{
		return m_LastReadTime;
	}
	int64_t GetLastReadTime() const
	{
		return m_LastReadTime;
	}
private:
	//JoinTime
	int64_t m_JoinTime;
public:
	void SetJoinTime( int64_t v)
	{
		m_JoinTime=v;
	}
	int64_t GetJoinTime()
	{
		return m_JoinTime;
	}
	int64_t GetJoinTime() const
	{
		return m_JoinTime;
	}
private:
	//ClearIndex
	INT32 m_ClearIndex;
public:
	void SetClearIndex( INT32 v)
	{
		m_ClearIndex=v;
	}
	INT32 GetClearIndex()
	{
		return m_ClearIndex;
	}
	INT32 GetClearIndex() const
	{
		return m_ClearIndex;
	}

};
//ChatInfoVote封装类
class ChatInfoVoteWraper
{
public:
	//构造函数
	ChatInfoVoteWraper()
	{
		
		m_Player_name = "";
		m_Player_guid = 0;
		m_Avatar_id = -1;
		m_Player_level = -1;
		m_Avatar_frame_id = -1;
		m_Avatar_frame_id1 = -1;
		m_Config_id = -1;
		m_Timestamp = -1;
		m_Chat_msg = ChatMsgVoteWraper();
		m_Team_id = 0;
		m_Guild_guid = 0;

	}
	//赋值构造函数
	ChatInfoVoteWraper(const ChatInfoVote& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatInfoVote& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatInfoVote ToPB() const
	{
		ChatInfoVote v;
		v.set_player_name( m_Player_name );
		v.set_player_guid( m_Player_guid );
		v.set_avatar_id( m_Avatar_id );
		v.set_player_level( m_Player_level );
		v.set_avatar_frame_id( m_Avatar_frame_id );
		v.set_avatar_frame_id1( m_Avatar_frame_id1 );
		v.set_config_id( m_Config_id );
		v.set_timestamp( m_Timestamp );
		*v.mutable_chat_msg()= m_Chat_msg.ToPB();
		v.set_team_id( m_Team_id );
		v.set_guild_guid( m_Guild_guid );

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
		ChatInfoVote pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatInfoVote& v)
	{
		m_Player_name = v.player_name();
		m_Player_guid = v.player_guid();
		m_Avatar_id = v.avatar_id();
		m_Player_level = v.player_level();
		m_Avatar_frame_id = v.avatar_frame_id();
		m_Avatar_frame_id1 = v.avatar_frame_id1();
		m_Config_id = v.config_id();
		m_Timestamp = v.timestamp();
		m_Chat_msg = v.chat_msg();
		m_Team_id = v.team_id();
		m_Guild_guid = v.guild_guid();

	}

private:
	//玩家名字
	string m_Player_name;
public:
	void SetPlayer_name( const string& v)
	{
		m_Player_name=v;
	}
	string GetPlayer_name()
	{
		return m_Player_name;
	}
	string GetPlayer_name() const
	{
		return m_Player_name;
	}
private:
	//玩家GUID
	uint64_t m_Player_guid;
public:
	void SetPlayer_guid( uint64_t v)
	{
		m_Player_guid=v;
	}
	uint64_t GetPlayer_guid()
	{
		return m_Player_guid;
	}
	uint64_t GetPlayer_guid() const
	{
		return m_Player_guid;
	}
private:
	//头像ID
	INT32 m_Avatar_id;
public:
	void SetAvatar_id( INT32 v)
	{
		m_Avatar_id=v;
	}
	INT32 GetAvatar_id()
	{
		return m_Avatar_id;
	}
	INT32 GetAvatar_id() const
	{
		return m_Avatar_id;
	}
private:
	//等级
	INT32 m_Player_level;
public:
	void SetPlayer_level( INT32 v)
	{
		m_Player_level=v;
	}
	INT32 GetPlayer_level()
	{
		return m_Player_level;
	}
	INT32 GetPlayer_level() const
	{
		return m_Player_level;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id;
public:
	void SetAvatar_frame_id( INT32 v)
	{
		m_Avatar_frame_id=v;
	}
	INT32 GetAvatar_frame_id()
	{
		return m_Avatar_frame_id;
	}
	INT32 GetAvatar_frame_id() const
	{
		return m_Avatar_frame_id;
	}
private:
	//头像框ID
	INT32 m_Avatar_frame_id1;
public:
	void SetAvatar_frame_id1( INT32 v)
	{
		m_Avatar_frame_id1=v;
	}
	INT32 GetAvatar_frame_id1()
	{
		return m_Avatar_frame_id1;
	}
	INT32 GetAvatar_frame_id1() const
	{
		return m_Avatar_frame_id1;
	}
private:
	//角色配置ID
	INT32 m_Config_id;
public:
	void SetConfig_id( INT32 v)
	{
		m_Config_id=v;
	}
	INT32 GetConfig_id()
	{
		return m_Config_id;
	}
	INT32 GetConfig_id() const
	{
		return m_Config_id;
	}
private:
	//时间戳
	int64_t m_Timestamp;
public:
	void SetTimestamp( int64_t v)
	{
		m_Timestamp=v;
	}
	int64_t GetTimestamp()
	{
		return m_Timestamp;
	}
	int64_t GetTimestamp() const
	{
		return m_Timestamp;
	}
private:
	//聊天消息
	ChatMsgVoteWraper m_Chat_msg;
public:
	void SetChat_msg( const ChatMsgVoteWraper& v)
	{
		m_Chat_msg=v;
	}
	ChatMsgVoteWraper GetChat_msg()
	{
		return m_Chat_msg;
	}
	ChatMsgVoteWraper GetChat_msg() const
	{
		return m_Chat_msg;
	}
private:
	//队伍id
	uint64_t m_Team_id;
public:
	void SetTeam_id( uint64_t v)
	{
		m_Team_id=v;
	}
	uint64_t GetTeam_id()
	{
		return m_Team_id;
	}
	uint64_t GetTeam_id() const
	{
		return m_Team_id;
	}
private:
	//公会id 0表示无公会
	uint64_t m_Guild_guid;
public:
	void SetGuild_guid( uint64_t v)
	{
		m_Guild_guid=v;
	}
	uint64_t GetGuild_guid()
	{
		return m_Guild_guid;
	}
	uint64_t GetGuild_guid() const
	{
		return m_Guild_guid;
	}

};
//爬塔buf选择记录封装类
class ClimTowerBufWraper
{
public:
	//构造函数
	ClimTowerBufWraper()
	{
		
		m_Layer = -1;
		m_BuffId = -1;

	}
	//赋值构造函数
	ClimTowerBufWraper(const ClimTowerBuf& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerBuf& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerBuf ToPB() const
	{
		ClimTowerBuf v;
		v.set_layer( m_Layer );
		v.set_buffid( m_BuffId );

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
		ClimTowerBuf pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ClimTowerBuf& v)
	{
		m_Layer = v.layer();
		m_BuffId = v.buffid();

	}

private:
	//爬塔层Id
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
private:
	//选择的bufId
	INT32 m_BuffId;
public:
	void SetBuffId( INT32 v)
	{
		m_BuffId=v;
	}
	INT32 GetBuffId()
	{
		return m_BuffId;
	}
	INT32 GetBuffId() const
	{
		return m_BuffId;
	}

};
//坐骑等级数据封装类
class MountLevelDataWraper
{
public:
	//构造函数
	MountLevelDataWraper()
	{
		
		m_Level = 1;
		m_Experience = 0;

	}
	//赋值构造函数
	MountLevelDataWraper(const MountLevelData& v){ Init(v); }
	//等号重载函数
	void operator = (const MountLevelData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MountLevelData ToPB() const
	{
		MountLevelData v;
		v.set_level( m_Level );
		v.set_experience( m_Experience );
		v.mutable_develophistory()->Reserve(m_DevelopHistory.size());
		for (int i=0; i<(int)m_DevelopHistory.size(); i++)
		{
			*v.add_develophistory() = m_DevelopHistory[i].ToPB();
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
		MountLevelData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MountLevelData& v)
	{
		m_Level = v.level();
		m_Experience = v.experience();
		m_DevelopHistory.clear();
		m_DevelopHistory.reserve(v.develophistory_size());
		for( int i=0; i<v.develophistory_size(); i++)
			m_DevelopHistory.push_back(v.develophistory(i));

	}

private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//经验
	INT32 m_Experience;
public:
	void SetExperience( INT32 v)
	{
		m_Experience=v;
	}
	INT32 GetExperience()
	{
		return m_Experience;
	}
	INT32 GetExperience() const
	{
		return m_Experience;
	}
private:
	//养成历史
	vector<MountDevItemWraper> m_DevelopHistory;
public:
	int SizeDevelopHistory()
	{
		return m_DevelopHistory.size();
	}
	const vector<MountDevItemWraper>& GetDevelopHistory() const
	{
		return m_DevelopHistory;
	}
	MountDevItemWraper GetDevelopHistory(int Index) const
	{
		if(Index<0 || Index>=(int)m_DevelopHistory.size())
		{
			assert(false);
			return MountDevItemWraper();
		}
		return m_DevelopHistory[Index];
	}
	void SetDevelopHistory( const vector<MountDevItemWraper>& v )
	{
		m_DevelopHistory=v;
	}
	void ClearDevelopHistory( )
	{
		m_DevelopHistory.clear();
	}
	void SetDevelopHistory( int Index, const MountDevItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_DevelopHistory.size())
		{
			assert(false);
			return;
		}
		m_DevelopHistory[Index] = v;
	}
	void AddDevelopHistory( const MountDevItemWraper& v )
	{
		m_DevelopHistory.push_back(v);
	}

};
//坐骑亲密度封装类
class MountIntimateDataWraper
{
public:
	//构造函数
	MountIntimateDataWraper()
	{
		
		m_Level = 1;
		m_Experience = 0;
		m_TodayExp = 0;

	}
	//赋值构造函数
	MountIntimateDataWraper(const MountIntimateData& v){ Init(v); }
	//等号重载函数
	void operator = (const MountIntimateData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MountIntimateData ToPB() const
	{
		MountIntimateData v;
		v.set_level( m_Level );
		v.set_experience( m_Experience );
		v.mutable_feedhistory()->Reserve(m_FeedHistory.size());
		for (int i=0; i<(int)m_FeedHistory.size(); i++)
		{
			*v.add_feedhistory() = m_FeedHistory[i].ToPB();
		}
		v.set_todayexp( m_TodayExp );

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
		MountIntimateData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MountIntimateData& v)
	{
		m_Level = v.level();
		m_Experience = v.experience();
		m_FeedHistory.clear();
		m_FeedHistory.reserve(v.feedhistory_size());
		for( int i=0; i<v.feedhistory_size(); i++)
			m_FeedHistory.push_back(v.feedhistory(i));
		m_TodayExp = v.todayexp();

	}

private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//经验
	INT32 m_Experience;
public:
	void SetExperience( INT32 v)
	{
		m_Experience=v;
	}
	INT32 GetExperience()
	{
		return m_Experience;
	}
	INT32 GetExperience() const
	{
		return m_Experience;
	}
private:
	//喂养记录
	vector<MountDevItemWraper> m_FeedHistory;
public:
	int SizeFeedHistory()
	{
		return m_FeedHistory.size();
	}
	const vector<MountDevItemWraper>& GetFeedHistory() const
	{
		return m_FeedHistory;
	}
	MountDevItemWraper GetFeedHistory(int Index) const
	{
		if(Index<0 || Index>=(int)m_FeedHistory.size())
		{
			assert(false);
			return MountDevItemWraper();
		}
		return m_FeedHistory[Index];
	}
	void SetFeedHistory( const vector<MountDevItemWraper>& v )
	{
		m_FeedHistory=v;
	}
	void ClearFeedHistory( )
	{
		m_FeedHistory.clear();
	}
	void SetFeedHistory( int Index, const MountDevItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_FeedHistory.size())
		{
			assert(false);
			return;
		}
		m_FeedHistory[Index] = v;
	}
	void AddFeedHistory( const MountDevItemWraper& v )
	{
		m_FeedHistory.push_back(v);
	}
private:
	//今日喂养所得经验
	INT32 m_TodayExp;
public:
	void SetTodayExp( INT32 v)
	{
		m_TodayExp=v;
	}
	INT32 GetTodayExp()
	{
		return m_TodayExp;
	}
	INT32 GetTodayExp() const
	{
		return m_TodayExp;
	}

};
//公会副本每层数据封装类
class GuildDungeonLayerDataWraper
{
public:
	//构造函数
	GuildDungeonLayerDataWraper()
	{
		
		m_LayerIndex = 1;
		m_GuildName = "";
		m_PassTeamInfo = TeamInfoWraper();

	}
	//赋值构造函数
	GuildDungeonLayerDataWraper(const GuildDungeonLayerData& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildDungeonLayerData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildDungeonLayerData ToPB() const
	{
		GuildDungeonLayerData v;
		v.set_layerindex( m_LayerIndex );
		v.set_guildname( m_GuildName );
		*v.mutable_passteaminfo()= m_PassTeamInfo.ToPB();

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
		GuildDungeonLayerData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildDungeonLayerData& v)
	{
		m_LayerIndex = v.layerindex();
		m_GuildName = v.guildname();
		m_PassTeamInfo = v.passteaminfo();

	}

private:
	//层数
	INT32 m_LayerIndex;
public:
	void SetLayerIndex( INT32 v)
	{
		m_LayerIndex=v;
	}
	INT32 GetLayerIndex()
	{
		return m_LayerIndex;
	}
	INT32 GetLayerIndex() const
	{
		return m_LayerIndex;
	}
private:
	//最先通关公会名称
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//最先通关队伍
	TeamInfoWraper m_PassTeamInfo;
public:
	void SetPassTeamInfo( const TeamInfoWraper& v)
	{
		m_PassTeamInfo=v;
	}
	TeamInfoWraper GetPassTeamInfo()
	{
		return m_PassTeamInfo;
	}
	TeamInfoWraper GetPassTeamInfo() const
	{
		return m_PassTeamInfo;
	}

};
//聊天联系人数据封装类
class ContactsChatMsgWraper
{
public:
	//构造函数
	ContactsChatMsgWraper()
	{
		
		m_RoleId = 0;
		m_HasNewMsg = false;

	}
	//赋值构造函数
	ContactsChatMsgWraper(const ContactsChatMsg& v){ Init(v); }
	//等号重载函数
	void operator = (const ContactsChatMsg& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ContactsChatMsg ToPB() const
	{
		ContactsChatMsg v;
		v.set_roleid( m_RoleId );
		v.set_hasnewmsg( m_HasNewMsg );
		v.mutable_charinfolist()->Reserve(m_CharInfoList.size());
		for (int i=0; i<(int)m_CharInfoList.size(); i++)
		{
			*v.add_charinfolist() = m_CharInfoList[i].ToPB();
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
		ContactsChatMsg pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ContactsChatMsg& v)
	{
		m_RoleId = v.roleid();
		m_HasNewMsg = v.hasnewmsg();
		m_CharInfoList.clear();
		m_CharInfoList.reserve(v.charinfolist_size());
		for( int i=0; i<v.charinfolist_size(); i++)
			m_CharInfoList.push_back(v.charinfolist(i));

	}

private:
	//聊天Id
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
	//HasNewMsg
	bool m_HasNewMsg;
public:
	void SetHasNewMsg( bool v)
	{
		m_HasNewMsg=v;
	}
	bool GetHasNewMsg()
	{
		return m_HasNewMsg;
	}
	bool GetHasNewMsg() const
	{
		return m_HasNewMsg;
	}
private:
	//聊天信息
	vector<ChatInfoWraper> m_CharInfoList;
public:
	int SizeCharInfoList()
	{
		return m_CharInfoList.size();
	}
	const vector<ChatInfoWraper>& GetCharInfoList() const
	{
		return m_CharInfoList;
	}
	ChatInfoWraper GetCharInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CharInfoList.size())
		{
			assert(false);
			return ChatInfoWraper();
		}
		return m_CharInfoList[Index];
	}
	void SetCharInfoList( const vector<ChatInfoWraper>& v )
	{
		m_CharInfoList=v;
	}
	void ClearCharInfoList( )
	{
		m_CharInfoList.clear();
	}
	void SetCharInfoList( int Index, const ChatInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_CharInfoList.size())
		{
			assert(false);
			return;
		}
		m_CharInfoList[Index] = v;
	}
	void AddCharInfoList( const ChatInfoWraper& v )
	{
		m_CharInfoList.push_back(v);
	}

};
//拼接字符串封装类
class AppendStringWraper
{
public:
	//构造函数
	AppendStringWraper()
	{
		
		m_TransID = -1;
		m_Key = -1;

	}
	//赋值构造函数
	AppendStringWraper(const AppendString& v){ Init(v); }
	//等号重载函数
	void operator = (const AppendString& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AppendString ToPB() const
	{
		AppendString v;
		v.set_transid( m_TransID );
		v.set_key( m_Key );
		v.mutable_stringlist()->Reserve(m_StringList.size());
		for (int i=0; i<(int)m_StringList.size(); i++)
		{
			v.add_stringlist( m_StringList[i]);
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
		AppendString pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AppendString& v)
	{
		m_TransID = v.transid();
		m_Key = v.key();
		m_StringList.clear();
		m_StringList.reserve(v.stringlist_size());
		for( int i=0; i<v.stringlist_size(); i++)
			m_StringList.push_back(v.stringlist(i));

	}

private:
	//transid
	INT32 m_TransID;
public:
	void SetTransID( INT32 v)
	{
		m_TransID=v;
	}
	INT32 GetTransID()
	{
		return m_TransID;
	}
	INT32 GetTransID() const
	{
		return m_TransID;
	}
private:
	//key
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//StringList
	vector<string> m_StringList;
public:
	int SizeStringList()
	{
		return m_StringList.size();
	}
	const vector<string>& GetStringList() const
	{
		return m_StringList;
	}
	string GetStringList(int Index) const
	{
		if(Index<0 || Index>=(int)m_StringList.size())
		{
			assert(false);
			return string();
		}
		return m_StringList[Index];
	}
	void SetStringList( const vector<string>& v )
	{
		m_StringList=v;
	}
	void ClearStringList( )
	{
		m_StringList.clear();
	}
	void SetStringList( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_StringList.size())
		{
			assert(false);
			return;
		}
		m_StringList[Index] = v;
	}
	void AddStringList( const string& v )
	{
		m_StringList.push_back(v);
	}

};
//进入的目标封装类
class MatchTargetInfoWraper
{
public:
	//构造函数
	MatchTargetInfoWraper()
	{
		
		m_DungeonConfigId = -1;
		m_SceneConfigId = -1;
		m_SceneType = 0;
		m_MirrorConfigId = -1;
		m_Starbattleid = -1;
		m_FuntionId = 0;

	}
	//赋值构造函数
	MatchTargetInfoWraper(const MatchTargetInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchTargetInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchTargetInfo ToPB() const
	{
		MatchTargetInfo v;
		v.set_dungeonconfigid( m_DungeonConfigId );
		v.set_sceneconfigid( m_SceneConfigId );
		v.set_scenetype( m_SceneType );
		v.set_mirrorconfigid( m_MirrorConfigId );
		v.set_starbattleid( m_Starbattleid );
		v.set_funtionid( m_FuntionId );

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
		MatchTargetInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MatchTargetInfo& v)
	{
		m_DungeonConfigId = v.dungeonconfigid();
		m_SceneConfigId = v.sceneconfigid();
		m_SceneType = v.scenetype();
		m_MirrorConfigId = v.mirrorconfigid();
		m_Starbattleid = v.starbattleid();
		m_FuntionId = v.funtionid();

	}

private:
	//副本id
	INT32 m_DungeonConfigId;
public:
	void SetDungeonConfigId( INT32 v)
	{
		m_DungeonConfigId=v;
	}
	INT32 GetDungeonConfigId()
	{
		return m_DungeonConfigId;
	}
	INT32 GetDungeonConfigId() const
	{
		return m_DungeonConfigId;
	}
private:
	//场景配置Id
	INT32 m_SceneConfigId;
public:
	void SetSceneConfigId( INT32 v)
	{
		m_SceneConfigId=v;
	}
	INT32 GetSceneConfigId()
	{
		return m_SceneConfigId;
	}
	INT32 GetSceneConfigId() const
	{
		return m_SceneConfigId;
	}
private:
	//副本类型
	INT32 m_SceneType;
public:
	void SetSceneType( INT32 v)
	{
		m_SceneType=v;
	}
	INT32 GetSceneType()
	{
		return m_SceneType;
	}
	INT32 GetSceneType() const
	{
		return m_SceneType;
	}
private:
	//镜像id
	INT32 m_MirrorConfigId;
public:
	void SetMirrorConfigId( INT32 v)
	{
		m_MirrorConfigId=v;
	}
	INT32 GetMirrorConfigId()
	{
		return m_MirrorConfigId;
	}
	INT32 GetMirrorConfigId() const
	{
		return m_MirrorConfigId;
	}
private:
	//星耀NPCid
	INT32 m_Starbattleid;
public:
	void SetStarbattleid( INT32 v)
	{
		m_Starbattleid=v;
	}
	INT32 GetStarbattleid()
	{
		return m_Starbattleid;
	}
	INT32 GetStarbattleid() const
	{
		return m_Starbattleid;
	}
private:
	//FuntionId
	INT32 m_FuntionId;
public:
	void SetFuntionId( INT32 v)
	{
		m_FuntionId=v;
	}
	INT32 GetFuntionId()
	{
		return m_FuntionId;
	}
	INT32 GetFuntionId() const
	{
		return m_FuntionId;
	}

};
//运营登录封装类
class SpecLoginRewardWraper
{
public:
	//构造函数
	SpecLoginRewardWraper()
	{
		
		m_Index = -1;
		m_Get = -1;
		m_SetTime = -1;

	}
	//赋值构造函数
	SpecLoginRewardWraper(const SpecLoginReward& v){ Init(v); }
	//等号重载函数
	void operator = (const SpecLoginReward& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SpecLoginReward ToPB() const
	{
		SpecLoginReward v;
		v.set_index( m_Index );
		v.set_get( m_Get );
		v.set_settime( m_SetTime );

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
		SpecLoginReward pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SpecLoginReward& v)
	{
		m_Index = v.index();
		m_Get = v.get();
		m_SetTime = v.settime();

	}

private:
	//索引
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
private:
	//是否领取0未领取1领取
	INT32 m_Get;
public:
	void SetGet( INT32 v)
	{
		m_Get=v;
	}
	INT32 GetGet()
	{
		return m_Get;
	}
	INT32 GetGet() const
	{
		return m_Get;
	}
private:
	//设置时间
	int64_t m_SetTime;
public:
	void SetSetTime( int64_t v)
	{
		m_SetTime=v;
	}
	int64_t GetSetTime()
	{
		return m_SetTime;
	}
	int64_t GetSetTime() const
	{
		return m_SetTime;
	}

};
//星耀通关队伍信息封装类
class StarBattleTeamInfoWraper
{
public:
	//构造函数
	StarBattleTeamInfoWraper()
	{
		
		m_PassTime = -1;
		m_PassUseTime = -1;

	}
	//赋值构造函数
	StarBattleTeamInfoWraper(const StarBattleTeamInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const StarBattleTeamInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StarBattleTeamInfo ToPB() const
	{
		StarBattleTeamInfo v;
		v.set_passtime( m_PassTime );
		v.set_passusetime( m_PassUseTime );
		v.mutable_memberinfo()->Reserve(m_MemberInfo.size());
		for (int i=0; i<(int)m_MemberInfo.size(); i++)
		{
			*v.add_memberinfo() = m_MemberInfo[i].ToPB();
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
		StarBattleTeamInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const StarBattleTeamInfo& v)
	{
		m_PassTime = v.passtime();
		m_PassUseTime = v.passusetime();
		m_MemberInfo.clear();
		m_MemberInfo.reserve(v.memberinfo_size());
		for( int i=0; i<v.memberinfo_size(); i++)
			m_MemberInfo.push_back(v.memberinfo(i));

	}

private:
	//通关时间
	int64_t m_PassTime;
public:
	void SetPassTime( int64_t v)
	{
		m_PassTime=v;
	}
	int64_t GetPassTime()
	{
		return m_PassTime;
	}
	int64_t GetPassTime() const
	{
		return m_PassTime;
	}
private:
	//通关用时
	INT32 m_PassUseTime;
public:
	void SetPassUseTime( INT32 v)
	{
		m_PassUseTime=v;
	}
	INT32 GetPassUseTime()
	{
		return m_PassUseTime;
	}
	INT32 GetPassUseTime() const
	{
		return m_PassUseTime;
	}
private:
	//通关队员信息
	vector<StarBattlePlayerInfoWraper> m_MemberInfo;
public:
	int SizeMemberInfo()
	{
		return m_MemberInfo.size();
	}
	const vector<StarBattlePlayerInfoWraper>& GetMemberInfo() const
	{
		return m_MemberInfo;
	}
	StarBattlePlayerInfoWraper GetMemberInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_MemberInfo.size())
		{
			assert(false);
			return StarBattlePlayerInfoWraper();
		}
		return m_MemberInfo[Index];
	}
	void SetMemberInfo( const vector<StarBattlePlayerInfoWraper>& v )
	{
		m_MemberInfo=v;
	}
	void ClearMemberInfo( )
	{
		m_MemberInfo.clear();
	}
	void SetMemberInfo( int Index, const StarBattlePlayerInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_MemberInfo.size())
		{
			assert(false);
			return;
		}
		m_MemberInfo[Index] = v;
	}
	void AddMemberInfo( const StarBattlePlayerInfoWraper& v )
	{
		m_MemberInfo.push_back(v);
	}

};
//实时战绩封装类
class RealTimeExploitsWraper
{
public:
	//构造函数
	RealTimeExploitsWraper()
	{
		
		m_ExploitsType = 0;

	}
	//赋值构造函数
	RealTimeExploitsWraper(const RealTimeExploits& v){ Init(v); }
	//等号重载函数
	void operator = (const RealTimeExploits& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RealTimeExploits ToPB() const
	{
		RealTimeExploits v;
		v.mutable_playerlist()->Reserve(m_PlayerList.size());
		for (int i=0; i<(int)m_PlayerList.size(); i++)
		{
			*v.add_playerlist() = m_PlayerList[i].ToPB();
		}
		v.set_exploitstype( m_ExploitsType );

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
		RealTimeExploits pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RealTimeExploits& v)
	{
		m_PlayerList.clear();
		m_PlayerList.reserve(v.playerlist_size());
		for( int i=0; i<v.playerlist_size(); i++)
			m_PlayerList.push_back(v.playerlist(i));
		m_ExploitsType = v.exploitstype();

	}

private:
	//数据
	vector<PlayerRealTimeExploitWraper> m_PlayerList;
public:
	int SizePlayerList()
	{
		return m_PlayerList.size();
	}
	const vector<PlayerRealTimeExploitWraper>& GetPlayerList() const
	{
		return m_PlayerList;
	}
	PlayerRealTimeExploitWraper GetPlayerList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PlayerList.size())
		{
			assert(false);
			return PlayerRealTimeExploitWraper();
		}
		return m_PlayerList[Index];
	}
	void SetPlayerList( const vector<PlayerRealTimeExploitWraper>& v )
	{
		m_PlayerList=v;
	}
	void ClearPlayerList( )
	{
		m_PlayerList.clear();
	}
	void SetPlayerList( int Index, const PlayerRealTimeExploitWraper& v )
	{
		if(Index<0 || Index>=(int)m_PlayerList.size())
		{
			assert(false);
			return;
		}
		m_PlayerList[Index] = v;
	}
	void AddPlayerList( const PlayerRealTimeExploitWraper& v )
	{
		m_PlayerList.push_back(v);
	}
private:
	//数据
	INT32 m_ExploitsType;
public:
	void SetExploitsType( INT32 v)
	{
		m_ExploitsType=v;
	}
	INT32 GetExploitsType()
	{
		return m_ExploitsType;
	}
	INT32 GetExploitsType() const
	{
		return m_ExploitsType;
	}

};
//移动信息封装类
class MotionInfoWraper
{
public:
	//构造函数
	MotionInfoWraper()
	{
		
		m_MotionType = -1;
		m_IsAllowChangeRunAnimation = false;
		m_IsFollow = false;
		m_IsLookAtMoving = false;

	}
	//赋值构造函数
	MotionInfoWraper(const MotionInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MotionInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MotionInfo ToPB() const
	{
		MotionInfo v;
		v.set_motiontype( m_MotionType );
		v.mutable_motionpath()->Reserve(m_MotionPath.size());
		for (int i=0; i<(int)m_MotionPath.size(); i++)
		{
			*v.add_motionpath() = m_MotionPath[i].ToPB();
		}
		v.set_isallowchangerunanimation( m_IsAllowChangeRunAnimation );
		v.set_isfollow( m_IsFollow );
		v.set_islookatmoving( m_IsLookAtMoving );

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
		MotionInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MotionInfo& v)
	{
		m_MotionType = v.motiontype();
		m_MotionPath.clear();
		m_MotionPath.reserve(v.motionpath_size());
		for( int i=0; i<v.motionpath_size(); i++)
			m_MotionPath.push_back(v.motionpath(i));
		m_IsAllowChangeRunAnimation = v.isallowchangerunanimation();
		m_IsFollow = v.isfollow();
		m_IsLookAtMoving = v.islookatmoving();

	}

private:
	//移动类型
	INT32 m_MotionType;
public:
	void SetMotionType( INT32 v)
	{
		m_MotionType=v;
	}
	INT32 GetMotionType()
	{
		return m_MotionType;
	}
	INT32 GetMotionType() const
	{
		return m_MotionType;
	}
private:
	//移动路点
	vector<Vector3IntWraper> m_MotionPath;
public:
	int SizeMotionPath()
	{
		return m_MotionPath.size();
	}
	const vector<Vector3IntWraper>& GetMotionPath() const
	{
		return m_MotionPath;
	}
	Vector3IntWraper GetMotionPath(int Index) const
	{
		if(Index<0 || Index>=(int)m_MotionPath.size())
		{
			assert(false);
			return Vector3IntWraper();
		}
		return m_MotionPath[Index];
	}
	void SetMotionPath( const vector<Vector3IntWraper>& v )
	{
		m_MotionPath=v;
	}
	void ClearMotionPath( )
	{
		m_MotionPath.clear();
	}
	void SetMotionPath( int Index, const Vector3IntWraper& v )
	{
		if(Index<0 || Index>=(int)m_MotionPath.size())
		{
			assert(false);
			return;
		}
		m_MotionPath[Index] = v;
	}
	void AddMotionPath( const Vector3IntWraper& v )
	{
		m_MotionPath.push_back(v);
	}
private:
	//是否允许改变动画
	bool m_IsAllowChangeRunAnimation;
public:
	void SetIsAllowChangeRunAnimation( bool v)
	{
		m_IsAllowChangeRunAnimation=v;
	}
	bool GetIsAllowChangeRunAnimation()
	{
		return m_IsAllowChangeRunAnimation;
	}
	bool GetIsAllowChangeRunAnimation() const
	{
		return m_IsAllowChangeRunAnimation;
	}
private:
	//是否跟随状态
	bool m_IsFollow;
public:
	void SetIsFollow( bool v)
	{
		m_IsFollow=v;
	}
	bool GetIsFollow()
	{
		return m_IsFollow;
	}
	bool GetIsFollow() const
	{
		return m_IsFollow;
	}
private:
	//是否朝向移动目标点
	bool m_IsLookAtMoving;
public:
	void SetIsLookAtMoving( bool v)
	{
		m_IsLookAtMoving=v;
	}
	bool GetIsLookAtMoving()
	{
		return m_IsLookAtMoving;
	}
	bool GetIsLookAtMoving() const
	{
		return m_IsLookAtMoving;
	}

};
//奖励找回物品信息封装类
class RewardRecoveryItemWraper
{
public:
	//构造函数
	RewardRecoveryItemWraper()
	{
		
		m_ItemID = -1;
		m_ItemNum = -1;
		m_ItemType = 0;

	}
	//赋值构造函数
	RewardRecoveryItemWraper(const RewardRecoveryItem& v){ Init(v); }
	//等号重载函数
	void operator = (const RewardRecoveryItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RewardRecoveryItem ToPB() const
	{
		RewardRecoveryItem v;
		v.set_itemid( m_ItemID );
		v.set_itemnum( m_ItemNum );
		v.set_itemtype( m_ItemType );

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
		RewardRecoveryItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RewardRecoveryItem& v)
	{
		m_ItemID = v.itemid();
		m_ItemNum = v.itemnum();
		m_ItemType = v.itemtype();

	}

private:
	//物品ID
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
	//物品个数
	INT32 m_ItemNum;
public:
	void SetItemNum( INT32 v)
	{
		m_ItemNum=v;
	}
	INT32 GetItemNum()
	{
		return m_ItemNum;
	}
	INT32 GetItemNum() const
	{
		return m_ItemNum;
	}
private:
	//掉落类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}

};
//行当任务信息封装类
class BusinessQuestInfoWraper
{
public:
	//构造函数
	BusinessQuestInfoWraper()
	{
		
		m_NpcID = -1;
		m_QuestID = -1;

	}
	//赋值构造函数
	BusinessQuestInfoWraper(const BusinessQuestInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const BusinessQuestInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BusinessQuestInfo ToPB() const
	{
		BusinessQuestInfo v;
		v.set_npcid( m_NpcID );
		v.set_questid( m_QuestID );
		v.mutable_itemlist()->Reserve(m_ItemList.size());
		for (int i=0; i<(int)m_ItemList.size(); i++)
		{
			*v.add_itemlist() = m_ItemList[i].ToPB();
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
		BusinessQuestInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BusinessQuestInfo& v)
	{
		m_NpcID = v.npcid();
		m_QuestID = v.questid();
		m_ItemList.clear();
		m_ItemList.reserve(v.itemlist_size());
		for( int i=0; i<v.itemlist_size(); i++)
			m_ItemList.push_back(v.itemlist(i));

	}

private:
	//NPCID
	INT32 m_NpcID;
public:
	void SetNpcID( INT32 v)
	{
		m_NpcID=v;
	}
	INT32 GetNpcID()
	{
		return m_NpcID;
	}
	INT32 GetNpcID() const
	{
		return m_NpcID;
	}
private:
	//任务ID
	INT32 m_QuestID;
public:
	void SetQuestID( INT32 v)
	{
		m_QuestID=v;
	}
	INT32 GetQuestID()
	{
		return m_QuestID;
	}
	INT32 GetQuestID() const
	{
		return m_QuestID;
	}
private:
	//需要提交的道具列表
	vector<BusinessQuestItemWraper> m_ItemList;
public:
	int SizeItemList()
	{
		return m_ItemList.size();
	}
	const vector<BusinessQuestItemWraper>& GetItemList() const
	{
		return m_ItemList;
	}
	BusinessQuestItemWraper GetItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return BusinessQuestItemWraper();
		}
		return m_ItemList[Index];
	}
	void SetItemList( const vector<BusinessQuestItemWraper>& v )
	{
		m_ItemList=v;
	}
	void ClearItemList( )
	{
		m_ItemList.clear();
	}
	void SetItemList( int Index, const BusinessQuestItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return;
		}
		m_ItemList[Index] = v;
	}
	void AddItemList( const BusinessQuestItemWraper& v )
	{
		m_ItemList.push_back(v);
	}

};
//套装信息封装类
class SuitInfoWraper
{
public:
	//构造函数
	SuitInfoWraper()
	{
		
		m_Suit_id = -1;
		m_Collect_num = -1;

	}
	//赋值构造函数
	SuitInfoWraper(const SuitInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const SuitInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SuitInfo ToPB() const
	{
		SuitInfo v;
		v.set_suit_id( m_Suit_id );
		v.set_collect_num( m_Collect_num );

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
		SuitInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SuitInfo& v)
	{
		m_Suit_id = v.suit_id();
		m_Collect_num = v.collect_num();

	}

private:
	//套装ID
	INT32 m_Suit_id;
public:
	void SetSuit_id( INT32 v)
	{
		m_Suit_id=v;
	}
	INT32 GetSuit_id()
	{
		return m_Suit_id;
	}
	INT32 GetSuit_id() const
	{
		return m_Suit_id;
	}
private:
	//套装集齐数
	INT32 m_Collect_num;
public:
	void SetCollect_num( INT32 v)
	{
		m_Collect_num=v;
	}
	INT32 GetCollect_num()
	{
		return m_Collect_num;
	}
	INT32 GetCollect_num() const
	{
		return m_Collect_num;
	}

};
//CompletedQuestList封装类
class CompletedQuestListWraper
{
public:
	//构造函数
	CompletedQuestListWraper()
	{
		

	}
	//赋值构造函数
	CompletedQuestListWraper(const CompletedQuestList& v){ Init(v); }
	//等号重载函数
	void operator = (const CompletedQuestList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CompletedQuestList ToPB() const
	{
		CompletedQuestList v;
		v.mutable_idlist()->Reserve(m_IdList.size());
		for (int i=0; i<(int)m_IdList.size(); i++)
		{
			v.add_idlist(m_IdList[i]);
		}
		v.mutable_maxcompleteidlist()->Reserve(m_MaxCompleteIdList.size());
		for (int i=0; i<(int)m_MaxCompleteIdList.size(); i++)
		{
			*v.add_maxcompleteidlist() = m_MaxCompleteIdList[i].ToPB();
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
		CompletedQuestList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CompletedQuestList& v)
	{
		m_IdList.clear();
		m_IdList.reserve(v.idlist_size());
		for( int i=0; i<v.idlist_size(); i++)
			m_IdList.push_back(v.idlist(i));
		m_MaxCompleteIdList.clear();
		m_MaxCompleteIdList.reserve(v.maxcompleteidlist_size());
		for( int i=0; i<v.maxcompleteidlist_size(); i++)
			m_MaxCompleteIdList.push_back(v.maxcompleteidlist(i));

	}

private:
	//IdList
	vector<INT32> m_IdList;
public:
	int SizeIdList()
	{
		return m_IdList.size();
	}
	const vector<INT32>& GetIdList() const
	{
		return m_IdList;
	}
	INT32 GetIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_IdList.size())
		{
			assert(false);
			return INT32();
		}
		return m_IdList[Index];
	}
	void SetIdList( const vector<INT32>& v )
	{
		m_IdList=v;
	}
	void ClearIdList( )
	{
		m_IdList.clear();
	}
	void SetIdList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_IdList.size())
		{
			assert(false);
			return;
		}
		m_IdList[Index] = v;
	}
	void AddIdList( INT32 v = -1 )
	{
		m_IdList.push_back(v);
	}
private:
	//完成任务最大类型
	vector<MaxQuestCompleteIdWraper> m_MaxCompleteIdList;
public:
	int SizeMaxCompleteIdList()
	{
		return m_MaxCompleteIdList.size();
	}
	const vector<MaxQuestCompleteIdWraper>& GetMaxCompleteIdList() const
	{
		return m_MaxCompleteIdList;
	}
	MaxQuestCompleteIdWraper GetMaxCompleteIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_MaxCompleteIdList.size())
		{
			assert(false);
			return MaxQuestCompleteIdWraper();
		}
		return m_MaxCompleteIdList[Index];
	}
	void SetMaxCompleteIdList( const vector<MaxQuestCompleteIdWraper>& v )
	{
		m_MaxCompleteIdList=v;
	}
	void ClearMaxCompleteIdList( )
	{
		m_MaxCompleteIdList.clear();
	}
	void SetMaxCompleteIdList( int Index, const MaxQuestCompleteIdWraper& v )
	{
		if(Index<0 || Index>=(int)m_MaxCompleteIdList.size())
		{
			assert(false);
			return;
		}
		m_MaxCompleteIdList[Index] = v;
	}
	void AddMaxCompleteIdList( const MaxQuestCompleteIdWraper& v )
	{
		m_MaxCompleteIdList.push_back(v);
	}

};
//公会新闻封装类
class GuildNewsWraper
{
public:
	//构造函数
	GuildNewsWraper()
	{
		
		m_OptionType = -1;

	}
	//赋值构造函数
	GuildNewsWraper(const GuildNews& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildNews& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildNews ToPB() const
	{
		GuildNews v;
		v.set_optiontype( m_OptionType );
		v.mutable_eventsparm()->Reserve(m_EventsParm.size());
		for (int i=0; i<(int)m_EventsParm.size(); i++)
		{
			v.add_eventsparm( m_EventsParm[i]);
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
		GuildNews pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildNews& v)
	{
		m_OptionType = v.optiontype();
		m_EventsParm.clear();
		m_EventsParm.reserve(v.eventsparm_size());
		for( int i=0; i<v.eventsparm_size(); i++)
			m_EventsParm.push_back(v.eventsparm(i));

	}

private:
	//公会新闻类型
	INT32 m_OptionType;
public:
	void SetOptionType( INT32 v)
	{
		m_OptionType=v;
	}
	INT32 GetOptionType()
	{
		return m_OptionType;
	}
	INT32 GetOptionType() const
	{
		return m_OptionType;
	}
private:
	//事件参数
	vector<string> m_EventsParm;
public:
	int SizeEventsParm()
	{
		return m_EventsParm.size();
	}
	const vector<string>& GetEventsParm() const
	{
		return m_EventsParm;
	}
	string GetEventsParm(int Index) const
	{
		if(Index<0 || Index>=(int)m_EventsParm.size())
		{
			assert(false);
			return string();
		}
		return m_EventsParm[Index];
	}
	void SetEventsParm( const vector<string>& v )
	{
		m_EventsParm=v;
	}
	void ClearEventsParm( )
	{
		m_EventsParm.clear();
	}
	void SetEventsParm( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_EventsParm.size())
		{
			assert(false);
			return;
		}
		m_EventsParm[Index] = v;
	}
	void AddEventsParm( const string& v )
	{
		m_EventsParm.push_back(v);
	}

};
//宝石槽位信息封装类
class JewelSlotWraper
{
public:
	//构造函数
	JewelSlotWraper()
	{
		
		m_ItemId = -1;
		m_Unlocked = false;

	}
	//赋值构造函数
	JewelSlotWraper(const JewelSlot& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelSlot& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelSlot ToPB() const
	{
		JewelSlot v;
		v.set_itemid( m_ItemId );
		v.set_unlocked( m_Unlocked );

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
		JewelSlot pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const JewelSlot& v)
	{
		m_ItemId = v.itemid();
		m_Unlocked = v.unlocked();

	}

private:
	//道具ID
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
private:
	//是否解锁
	bool m_Unlocked;
public:
	void SetUnlocked( bool v)
	{
		m_Unlocked=v;
	}
	bool GetUnlocked()
	{
		return m_Unlocked;
	}
	bool GetUnlocked() const
	{
		return m_Unlocked;
	}

};
//公会旗帜封装类
class GuildFlagWraper
{
public:
	//构造函数
	GuildFlagWraper()
	{
		
		m_FlagEquiped = -1;

	}
	//赋值构造函数
	GuildFlagWraper(const GuildFlag& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildFlag& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildFlag ToPB() const
	{
		GuildFlag v;
		v.set_flagequiped( m_FlagEquiped );
		v.mutable_flagunlocked()->Reserve(m_FlagUnlocked.size());
		for (int i=0; i<(int)m_FlagUnlocked.size(); i++)
		{
			v.add_flagunlocked(m_FlagUnlocked[i]);
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
		GuildFlag pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildFlag& v)
	{
		m_FlagEquiped = v.flagequiped();
		m_FlagUnlocked.clear();
		m_FlagUnlocked.reserve(v.flagunlocked_size());
		for( int i=0; i<v.flagunlocked_size(); i++)
			m_FlagUnlocked.push_back(v.flagunlocked(i));

	}

private:
	//显示的旗帜
	INT32 m_FlagEquiped;
public:
	void SetFlagEquiped( INT32 v)
	{
		m_FlagEquiped=v;
	}
	INT32 GetFlagEquiped()
	{
		return m_FlagEquiped;
	}
	INT32 GetFlagEquiped() const
	{
		return m_FlagEquiped;
	}
private:
	//已解锁的旗帜
	vector<INT32> m_FlagUnlocked;
public:
	int SizeFlagUnlocked()
	{
		return m_FlagUnlocked.size();
	}
	const vector<INT32>& GetFlagUnlocked() const
	{
		return m_FlagUnlocked;
	}
	INT32 GetFlagUnlocked(int Index) const
	{
		if(Index<0 || Index>=(int)m_FlagUnlocked.size())
		{
			assert(false);
			return INT32();
		}
		return m_FlagUnlocked[Index];
	}
	void SetFlagUnlocked( const vector<INT32>& v )
	{
		m_FlagUnlocked=v;
	}
	void ClearFlagUnlocked( )
	{
		m_FlagUnlocked.clear();
	}
	void SetFlagUnlocked( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_FlagUnlocked.size())
		{
			assert(false);
			return;
		}
		m_FlagUnlocked[Index] = v;
	}
	void AddFlagUnlocked( INT32 v = -1 )
	{
		m_FlagUnlocked.push_back(v);
	}

};
//珍宝数据封装类
class TreasureDataWraper
{
public:
	//构造函数
	TreasureDataWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	TreasureDataWraper(const TreasureData& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureData ToPB() const
	{
		TreasureData v;
		v.set_id( m_ID );
		v.mutable_extra_info()->Reserve(m_Extra_Info.size());
		for (int i=0; i<(int)m_Extra_Info.size(); i++)
		{
			*v.add_extra_info() = m_Extra_Info[i].ToPB();
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
		TreasureData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TreasureData& v)
	{
		m_ID = v.id();
		m_Extra_Info.clear();
		m_Extra_Info.reserve(v.extra_info_size());
		for( int i=0; i<v.extra_info_size(); i++)
			m_Extra_Info.push_back(v.extra_info(i));

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//珍宝附加信息
	vector<TreasureExtraInfoWraper> m_Extra_Info;
public:
	int SizeExtra_Info()
	{
		return m_Extra_Info.size();
	}
	const vector<TreasureExtraInfoWraper>& GetExtra_Info() const
	{
		return m_Extra_Info;
	}
	TreasureExtraInfoWraper GetExtra_Info(int Index) const
	{
		if(Index<0 || Index>=(int)m_Extra_Info.size())
		{
			assert(false);
			return TreasureExtraInfoWraper();
		}
		return m_Extra_Info[Index];
	}
	void SetExtra_Info( const vector<TreasureExtraInfoWraper>& v )
	{
		m_Extra_Info=v;
	}
	void ClearExtra_Info( )
	{
		m_Extra_Info.clear();
	}
	void SetExtra_Info( int Index, const TreasureExtraInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Extra_Info.size())
		{
			assert(false);
			return;
		}
		m_Extra_Info[Index] = v;
	}
	void AddExtra_Info( const TreasureExtraInfoWraper& v )
	{
		m_Extra_Info.push_back(v);
	}

};
//技能集合封装类
class SkillContainerWraper
{
public:
	//构造函数
	SkillContainerWraper()
	{
		

	}
	//赋值构造函数
	SkillContainerWraper(const SkillContainer& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillContainer& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillContainer ToPB() const
	{
		SkillContainer v;
		v.mutable_skillobjlist()->Reserve(m_SkillObjList.size());
		for (int i=0; i<(int)m_SkillObjList.size(); i++)
		{
			*v.add_skillobjlist() = m_SkillObjList[i].ToPB();
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
		SkillContainer pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillContainer& v)
	{
		m_SkillObjList.clear();
		m_SkillObjList.reserve(v.skillobjlist_size());
		for( int i=0; i<v.skillobjlist_size(); i++)
			m_SkillObjList.push_back(v.skillobjlist(i));

	}

private:
	//技能集合
	vector<SkillObjWraper> m_SkillObjList;
public:
	int SizeSkillObjList()
	{
		return m_SkillObjList.size();
	}
	const vector<SkillObjWraper>& GetSkillObjList() const
	{
		return m_SkillObjList;
	}
	SkillObjWraper GetSkillObjList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillObjList.size())
		{
			assert(false);
			return SkillObjWraper();
		}
		return m_SkillObjList[Index];
	}
	void SetSkillObjList( const vector<SkillObjWraper>& v )
	{
		m_SkillObjList=v;
	}
	void ClearSkillObjList( )
	{
		m_SkillObjList.clear();
	}
	void SetSkillObjList( int Index, const SkillObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillObjList.size())
		{
			assert(false);
			return;
		}
		m_SkillObjList[Index] = v;
	}
	void AddSkillObjList( const SkillObjWraper& v )
	{
		m_SkillObjList.push_back(v);
	}

};
//PvpEndPlayer封装类
class PvpEndPlayerWraper
{
public:
	//构造函数
	PvpEndPlayerWraper()
	{
		
		m_RoleID = 0;
		m_RoleName = "";
		m_DeadCount = -1;
		m_KillCount = -1;
		m_LiveCount = -1;
		m_ConfigId = -1;
		m_DamageCount = -1;

	}
	//赋值构造函数
	PvpEndPlayerWraper(const PvpEndPlayer& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpEndPlayer& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpEndPlayer ToPB() const
	{
		PvpEndPlayer v;
		v.set_roleid( m_RoleID );
		v.set_rolename( m_RoleName );
		v.set_deadcount( m_DeadCount );
		v.set_killcount( m_KillCount );
		v.set_livecount( m_LiveCount );
		v.set_configid( m_ConfigId );
		v.set_damagecount( m_DamageCount );

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
		PvpEndPlayer pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpEndPlayer& v)
	{
		m_RoleID = v.roleid();
		m_RoleName = v.rolename();
		m_DeadCount = v.deadcount();
		m_KillCount = v.killcount();
		m_LiveCount = v.livecount();
		m_ConfigId = v.configid();
		m_DamageCount = v.damagecount();

	}

private:
	//RoleID
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
	//RoleName
	string m_RoleName;
public:
	void SetRoleName( const string& v)
	{
		m_RoleName=v;
	}
	string GetRoleName()
	{
		return m_RoleName;
	}
	string GetRoleName() const
	{
		return m_RoleName;
	}
private:
	//DeadCount
	INT32 m_DeadCount;
public:
	void SetDeadCount( INT32 v)
	{
		m_DeadCount=v;
	}
	INT32 GetDeadCount()
	{
		return m_DeadCount;
	}
	INT32 GetDeadCount() const
	{
		return m_DeadCount;
	}
private:
	//KillCount
	INT32 m_KillCount;
public:
	void SetKillCount( INT32 v)
	{
		m_KillCount=v;
	}
	INT32 GetKillCount()
	{
		return m_KillCount;
	}
	INT32 GetKillCount() const
	{
		return m_KillCount;
	}
private:
	//LiveCount
	INT32 m_LiveCount;
public:
	void SetLiveCount( INT32 v)
	{
		m_LiveCount=v;
	}
	INT32 GetLiveCount()
	{
		return m_LiveCount;
	}
	INT32 GetLiveCount() const
	{
		return m_LiveCount;
	}
private:
	//ConfigId
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
private:
	//伤害量
	INT32 m_DamageCount;
public:
	void SetDamageCount( INT32 v)
	{
		m_DamageCount=v;
	}
	INT32 GetDamageCount()
	{
		return m_DamageCount;
	}
	INT32 GetDamageCount() const
	{
		return m_DamageCount;
	}

};
//日常任务封装类
class DailyQuestWraper
{
public:
	//构造函数
	DailyQuestWraper()
	{
		
		m_MainQuest = QuestDataWraper();
		m_AtivityQuest = QuestDataWraper();
		m_RewardTimes = -1;
		m_ActivityId = -1;

	}
	//赋值构造函数
	DailyQuestWraper(const DailyQuest& v){ Init(v); }
	//等号重载函数
	void operator = (const DailyQuest& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DailyQuest ToPB() const
	{
		DailyQuest v;
		*v.mutable_mainquest()= m_MainQuest.ToPB();
		*v.mutable_ativityquest()= m_AtivityQuest.ToPB();
		v.set_rewardtimes( m_RewardTimes );
		v.set_activityid( m_ActivityId );

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
		DailyQuest pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DailyQuest& v)
	{
		m_MainQuest = v.mainquest();
		m_AtivityQuest = v.ativityquest();
		m_RewardTimes = v.rewardtimes();
		m_ActivityId = v.activityid();

	}

private:
	//主任务
	QuestDataWraper m_MainQuest;
public:
	void SetMainQuest( const QuestDataWraper& v)
	{
		m_MainQuest=v;
	}
	QuestDataWraper GetMainQuest()
	{
		return m_MainQuest;
	}
	QuestDataWraper GetMainQuest() const
	{
		return m_MainQuest;
	}
private:
	//活跃度任务
	QuestDataWraper m_AtivityQuest;
public:
	void SetAtivityQuest( const QuestDataWraper& v)
	{
		m_AtivityQuest=v;
	}
	QuestDataWraper GetAtivityQuest()
	{
		return m_AtivityQuest;
	}
	QuestDataWraper GetAtivityQuest() const
	{
		return m_AtivityQuest;
	}
private:
	//奖励倍数
	INT32 m_RewardTimes;
public:
	void SetRewardTimes( INT32 v)
	{
		m_RewardTimes=v;
	}
	INT32 GetRewardTimes()
	{
		return m_RewardTimes;
	}
	INT32 GetRewardTimes() const
	{
		return m_RewardTimes;
	}
private:
	//ActivityId
	INT32 m_ActivityId;
public:
	void SetActivityId( INT32 v)
	{
		m_ActivityId=v;
	}
	INT32 GetActivityId()
	{
		return m_ActivityId;
	}
	INT32 GetActivityId() const
	{
		return m_ActivityId;
	}

};
//首次胜利领取封装类
class FirstVicGetWraper
{
public:
	//构造函数
	FirstVicGetWraper()
	{
		
		m_Id = -1;
		m_Get = 0;

	}
	//赋值构造函数
	FirstVicGetWraper(const FirstVicGet& v){ Init(v); }
	//等号重载函数
	void operator = (const FirstVicGet& v){ Init(v); }
 	//转化成Protobuffer类型函数
	FirstVicGet ToPB() const
	{
		FirstVicGet v;
		v.set_id( m_Id );
		v.set_get( m_Get );

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
		FirstVicGet pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const FirstVicGet& v)
	{
		m_Id = v.id();
		m_Get = v.get();

	}

private:
	//层数
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//是否领取
	INT32 m_Get;
public:
	void SetGet( INT32 v)
	{
		m_Get=v;
	}
	INT32 GetGet()
	{
		return m_Get;
	}
	INT32 GetGet() const
	{
		return m_Get;
	}

};
//装备洗练属性封装类
class EquipWashInfoWraper
{
public:
	//构造函数
	EquipWashInfoWraper()
	{
		
		m_EquipGuid = 0;
		m_BattleScore = -1;

	}
	//赋值构造函数
	EquipWashInfoWraper(const EquipWashInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipWashInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipWashInfo ToPB() const
	{
		EquipWashInfo v;
		v.set_equipguid( m_EquipGuid );
		v.mutable_extraattr()->Reserve(m_ExtraAttr.size());
		for (int i=0; i<(int)m_ExtraAttr.size(); i++)
		{
			*v.add_extraattr() = m_ExtraAttr[i].ToPB();
		}
		v.mutable_lockedindex()->Reserve(m_LockedIndex.size());
		for (int i=0; i<(int)m_LockedIndex.size(); i++)
		{
			v.add_lockedindex(m_LockedIndex[i]);
		}
		v.set_battlescore( m_BattleScore );

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
		EquipWashInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipWashInfo& v)
	{
		m_EquipGuid = v.equipguid();
		m_ExtraAttr.clear();
		m_ExtraAttr.reserve(v.extraattr_size());
		for( int i=0; i<v.extraattr_size(); i++)
			m_ExtraAttr.push_back(v.extraattr(i));
		m_LockedIndex.clear();
		m_LockedIndex.reserve(v.lockedindex_size());
		for( int i=0; i<v.lockedindex_size(); i++)
			m_LockedIndex.push_back(v.lockedindex(i));
		m_BattleScore = v.battlescore();

	}

private:
	//GUID
	uint64_t m_EquipGuid;
public:
	void SetEquipGuid( uint64_t v)
	{
		m_EquipGuid=v;
	}
	uint64_t GetEquipGuid()
	{
		return m_EquipGuid;
	}
	uint64_t GetEquipGuid() const
	{
		return m_EquipGuid;
	}
private:
	//新的附加属性
	vector<AttrKeyValueWraper> m_ExtraAttr;
public:
	int SizeExtraAttr()
	{
		return m_ExtraAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetExtraAttr() const
	{
		return m_ExtraAttr;
	}
	AttrKeyValueWraper GetExtraAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_ExtraAttr[Index];
	}
	void SetExtraAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_ExtraAttr=v;
	}
	void ClearExtraAttr( )
	{
		m_ExtraAttr.clear();
	}
	void SetExtraAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.size())
		{
			assert(false);
			return;
		}
		m_ExtraAttr[Index] = v;
	}
	void AddExtraAttr( const AttrKeyValueWraper& v )
	{
		m_ExtraAttr.push_back(v);
	}
private:
	//锁的属性
	vector<INT32> m_LockedIndex;
public:
	int SizeLockedIndex()
	{
		return m_LockedIndex.size();
	}
	const vector<INT32>& GetLockedIndex() const
	{
		return m_LockedIndex;
	}
	INT32 GetLockedIndex(int Index) const
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return INT32();
		}
		return m_LockedIndex[Index];
	}
	void SetLockedIndex( const vector<INT32>& v )
	{
		m_LockedIndex=v;
	}
	void ClearLockedIndex( )
	{
		m_LockedIndex.clear();
	}
	void SetLockedIndex( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_LockedIndex.size())
		{
			assert(false);
			return;
		}
		m_LockedIndex[Index] = v;
	}
	void AddLockedIndex( INT32 v = -1 )
	{
		m_LockedIndex.push_back(v);
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}

};
//PvpBattleInfo封装类
class PvpBattleInfoWraper
{
public:
	//构造函数
	PvpBattleInfoWraper()
	{
		
		m_WinCount = -1;
		m_LoseCount = -1;
		m_DrawCount = -1;
		m_ContinuityWinCount = -1;
		m_Rank = -1;
		m_Star = -1;
		m_Elo = -1;
		m_BattleCount = -1;
		m_HistoryRank = -1;
		m_TodayFirst = false;
		m_ContinuityLoseCount = -1;
		m_DailyWinCount = -1;
		m_DailyBattleCount = -1;

	}
	//赋值构造函数
	PvpBattleInfoWraper(const PvpBattleInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpBattleInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpBattleInfo ToPB() const
	{
		PvpBattleInfo v;
		v.set_wincount( m_WinCount );
		v.set_losecount( m_LoseCount );
		v.set_drawcount( m_DrawCount );
		v.set_continuitywincount( m_ContinuityWinCount );
		v.set_rank( m_Rank );
		v.set_star( m_Star );
		v.set_elo( m_Elo );
		v.set_battlecount( m_BattleCount );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			v.add_rewardlist(m_RewardList[i]);
		}
		v.set_historyrank( m_HistoryRank );
		v.set_todayfirst( m_TodayFirst );
		v.set_continuitylosecount( m_ContinuityLoseCount );
		v.set_dailywincount( m_DailyWinCount );
		v.set_dailybattlecount( m_DailyBattleCount );
		v.mutable_dailyreward()->Reserve(m_DailyReward.size());
		for (int i=0; i<(int)m_DailyReward.size(); i++)
		{
			v.add_dailyreward(m_DailyReward[i]);
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
		PvpBattleInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpBattleInfo& v)
	{
		m_WinCount = v.wincount();
		m_LoseCount = v.losecount();
		m_DrawCount = v.drawcount();
		m_ContinuityWinCount = v.continuitywincount();
		m_Rank = v.rank();
		m_Star = v.star();
		m_Elo = v.elo();
		m_BattleCount = v.battlecount();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));
		m_HistoryRank = v.historyrank();
		m_TodayFirst = v.todayfirst();
		m_ContinuityLoseCount = v.continuitylosecount();
		m_DailyWinCount = v.dailywincount();
		m_DailyBattleCount = v.dailybattlecount();
		m_DailyReward.clear();
		m_DailyReward.reserve(v.dailyreward_size());
		for( int i=0; i<v.dailyreward_size(); i++)
			m_DailyReward.push_back(v.dailyreward(i));

	}

private:
	//WinCount
	INT32 m_WinCount;
public:
	void SetWinCount( INT32 v)
	{
		m_WinCount=v;
	}
	INT32 GetWinCount()
	{
		return m_WinCount;
	}
	INT32 GetWinCount() const
	{
		return m_WinCount;
	}
private:
	//LoseCount
	INT32 m_LoseCount;
public:
	void SetLoseCount( INT32 v)
	{
		m_LoseCount=v;
	}
	INT32 GetLoseCount()
	{
		return m_LoseCount;
	}
	INT32 GetLoseCount() const
	{
		return m_LoseCount;
	}
private:
	//DrawCount
	INT32 m_DrawCount;
public:
	void SetDrawCount( INT32 v)
	{
		m_DrawCount=v;
	}
	INT32 GetDrawCount()
	{
		return m_DrawCount;
	}
	INT32 GetDrawCount() const
	{
		return m_DrawCount;
	}
private:
	//ContinuityWinCount
	INT32 m_ContinuityWinCount;
public:
	void SetContinuityWinCount( INT32 v)
	{
		m_ContinuityWinCount=v;
	}
	INT32 GetContinuityWinCount()
	{
		return m_ContinuityWinCount;
	}
	INT32 GetContinuityWinCount() const
	{
		return m_ContinuityWinCount;
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
	//Elo
	INT32 m_Elo;
public:
	void SetElo( INT32 v)
	{
		m_Elo=v;
	}
	INT32 GetElo()
	{
		return m_Elo;
	}
	INT32 GetElo() const
	{
		return m_Elo;
	}
private:
	//对局次数
	INT32 m_BattleCount;
public:
	void SetBattleCount( INT32 v)
	{
		m_BattleCount=v;
	}
	INT32 GetBattleCount()
	{
		return m_BattleCount;
	}
	INT32 GetBattleCount() const
	{
		return m_BattleCount;
	}
private:
	//领取过的段位奖励
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
private:
	//历史最高段位
	INT32 m_HistoryRank;
public:
	void SetHistoryRank( INT32 v)
	{
		m_HistoryRank=v;
	}
	INT32 GetHistoryRank()
	{
		return m_HistoryRank;
	}
	INT32 GetHistoryRank() const
	{
		return m_HistoryRank;
	}
private:
	//每日首胜
	bool m_TodayFirst;
public:
	void SetTodayFirst( bool v)
	{
		m_TodayFirst=v;
	}
	bool GetTodayFirst()
	{
		return m_TodayFirst;
	}
	bool GetTodayFirst() const
	{
		return m_TodayFirst;
	}
private:
	//连败场次
	INT32 m_ContinuityLoseCount;
public:
	void SetContinuityLoseCount( INT32 v)
	{
		m_ContinuityLoseCount=v;
	}
	INT32 GetContinuityLoseCount()
	{
		return m_ContinuityLoseCount;
	}
	INT32 GetContinuityLoseCount() const
	{
		return m_ContinuityLoseCount;
	}
private:
	//今日胜利次数
	INT32 m_DailyWinCount;
public:
	void SetDailyWinCount( INT32 v)
	{
		m_DailyWinCount=v;
	}
	INT32 GetDailyWinCount()
	{
		return m_DailyWinCount;
	}
	INT32 GetDailyWinCount() const
	{
		return m_DailyWinCount;
	}
private:
	//今日参与次数
	INT32 m_DailyBattleCount;
public:
	void SetDailyBattleCount( INT32 v)
	{
		m_DailyBattleCount=v;
	}
	INT32 GetDailyBattleCount()
	{
		return m_DailyBattleCount;
	}
	INT32 GetDailyBattleCount() const
	{
		return m_DailyBattleCount;
	}
private:
	//领过的每日奖励
	vector<INT32> m_DailyReward;
public:
	int SizeDailyReward()
	{
		return m_DailyReward.size();
	}
	const vector<INT32>& GetDailyReward() const
	{
		return m_DailyReward;
	}
	INT32 GetDailyReward(int Index) const
	{
		if(Index<0 || Index>=(int)m_DailyReward.size())
		{
			assert(false);
			return INT32();
		}
		return m_DailyReward[Index];
	}
	void SetDailyReward( const vector<INT32>& v )
	{
		m_DailyReward=v;
	}
	void ClearDailyReward( )
	{
		m_DailyReward.clear();
	}
	void SetDailyReward( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_DailyReward.size())
		{
			assert(false);
			return;
		}
		m_DailyReward[Index] = v;
	}
	void AddDailyReward( INT32 v = -1 )
	{
		m_DailyReward.push_back(v);
	}

};
//BagData封装类
class BagDataWraper
{
public:
	//构造函数
	BagDataWraper()
	{
		
		m_BagType = -1;
		m_CurCapacity = -1;

	}
	//赋值构造函数
	BagDataWraper(const BagData& v){ Init(v); }
	//等号重载函数
	void operator = (const BagData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagData ToPB() const
	{
		BagData v;
		v.mutable_items()->Reserve(m_Items.size());
		for (int i=0; i<(int)m_Items.size(); i++)
		{
			*v.add_items() = m_Items[i].ToPB();
		}
		v.set_bagtype( m_BagType );
		v.set_curcapacity( m_CurCapacity );

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
		BagData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BagData& v)
	{
		m_Items.clear();
		m_Items.reserve(v.items_size());
		for( int i=0; i<v.items_size(); i++)
			m_Items.push_back(v.items(i));
		m_BagType = v.bagtype();
		m_CurCapacity = v.curcapacity();

	}

private:
	//物品列表
	vector<ItemObjWraper> m_Items;
public:
	int SizeItems()
	{
		return m_Items.size();
	}
	const vector<ItemObjWraper>& GetItems() const
	{
		return m_Items;
	}
	ItemObjWraper GetItems(int Index) const
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return ItemObjWraper();
		}
		return m_Items[Index];
	}
	void SetItems( const vector<ItemObjWraper>& v )
	{
		m_Items=v;
	}
	void ClearItems( )
	{
		m_Items.clear();
	}
	void SetItems( int Index, const ItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_Items.size())
		{
			assert(false);
			return;
		}
		m_Items[Index] = v;
	}
	void AddItems( const ItemObjWraper& v )
	{
		m_Items.push_back(v);
	}
private:
	//背包类型:0背包,1仓库,2临时背包
	INT32 m_BagType;
public:
	void SetBagType( INT32 v)
	{
		m_BagType=v;
	}
	INT32 GetBagType()
	{
		return m_BagType;
	}
	INT32 GetBagType() const
	{
		return m_BagType;
	}
private:
	//当前的容量
	INT32 m_CurCapacity;
public:
	void SetCurCapacity( INT32 v)
	{
		m_CurCapacity=v;
	}
	INT32 GetCurCapacity()
	{
		return m_CurCapacity;
	}
	INT32 GetCurCapacity() const
	{
		return m_CurCapacity;
	}

};
//申请入公会玩家简要信息封装类
class GuildMemberTinyInfoWraper
{
public:
	//构造函数
	GuildMemberTinyInfoWraper()
	{
		
		m_Guid = 0;
		m_PlayerName = "";
		m_Occupition = -1;
		m_Level = -1;
		m_FightScore = -1;
		m_TotalContribute = -1;
		m_RoleConfigID = -1;

	}
	//赋值构造函数
	GuildMemberTinyInfoWraper(const GuildMemberTinyInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildMemberTinyInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildMemberTinyInfo ToPB() const
	{
		GuildMemberTinyInfo v;
		v.set_guid( m_Guid );
		v.set_playername( m_PlayerName );
		v.set_occupition( m_Occupition );
		v.set_level( m_Level );
		v.set_fightscore( m_FightScore );
		v.set_totalcontribute( m_TotalContribute );
		v.set_roleconfigid( m_RoleConfigID );

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
		GuildMemberTinyInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildMemberTinyInfo& v)
	{
		m_Guid = v.guid();
		m_PlayerName = v.playername();
		m_Occupition = v.occupition();
		m_Level = v.level();
		m_FightScore = v.fightscore();
		m_TotalContribute = v.totalcontribute();
		m_RoleConfigID = v.roleconfigid();

	}

private:
	//guid
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
	//玩家名字
	string m_PlayerName;
public:
	void SetPlayerName( const string& v)
	{
		m_PlayerName=v;
	}
	string GetPlayerName()
	{
		return m_PlayerName;
	}
	string GetPlayerName() const
	{
		return m_PlayerName;
	}
private:
	//职业
	INT32 m_Occupition;
public:
	void SetOccupition( INT32 v)
	{
		m_Occupition=v;
	}
	INT32 GetOccupition()
	{
		return m_Occupition;
	}
	INT32 GetOccupition() const
	{
		return m_Occupition;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//战力
	INT32 m_FightScore;
public:
	void SetFightScore( INT32 v)
	{
		m_FightScore=v;
	}
	INT32 GetFightScore()
	{
		return m_FightScore;
	}
	INT32 GetFightScore() const
	{
		return m_FightScore;
	}
private:
	//玩家总帮贡
	INT32 m_TotalContribute;
public:
	void SetTotalContribute( INT32 v)
	{
		m_TotalContribute=v;
	}
	INT32 GetTotalContribute()
	{
		return m_TotalContribute;
	}
	INT32 GetTotalContribute() const
	{
		return m_TotalContribute;
	}
private:
	//角色configid
	INT32 m_RoleConfigID;
public:
	void SetRoleConfigID( INT32 v)
	{
		m_RoleConfigID=v;
	}
	INT32 GetRoleConfigID()
	{
		return m_RoleConfigID;
	}
	INT32 GetRoleConfigID() const
	{
		return m_RoleConfigID;
	}

};
//共鸣数据封装类
class EquipResonanceInfoWraper
{
public:
	//构造函数
	EquipResonanceInfoWraper()
	{
		
		m_ConfId = -1;
		m_BattleScore = -1;
		m_NewBattleScore = -1;

	}
	//赋值构造函数
	EquipResonanceInfoWraper(const EquipResonanceInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipResonanceInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipResonanceInfo ToPB() const
	{
		EquipResonanceInfo v;
		v.set_confid( m_ConfId );
		v.mutable_resonanceattr()->Reserve(m_ResonanceAttr.size());
		for (int i=0; i<(int)m_ResonanceAttr.size(); i++)
		{
			*v.add_resonanceattr() = m_ResonanceAttr[i].ToPB();
		}
		v.mutable_newresonanceattr()->Reserve(m_NewResonanceAttr.size());
		for (int i=0; i<(int)m_NewResonanceAttr.size(); i++)
		{
			*v.add_newresonanceattr() = m_NewResonanceAttr[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );
		v.set_newbattlescore( m_NewBattleScore );

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
		EquipResonanceInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipResonanceInfo& v)
	{
		m_ConfId = v.confid();
		m_ResonanceAttr.clear();
		m_ResonanceAttr.reserve(v.resonanceattr_size());
		for( int i=0; i<v.resonanceattr_size(); i++)
			m_ResonanceAttr.push_back(v.resonanceattr(i));
		m_NewResonanceAttr.clear();
		m_NewResonanceAttr.reserve(v.newresonanceattr_size());
		for( int i=0; i<v.newresonanceattr_size(); i++)
			m_NewResonanceAttr.push_back(v.newresonanceattr(i));
		m_BattleScore = v.battlescore();
		m_NewBattleScore = v.newbattlescore();

	}

private:
	//表ID
	INT32 m_ConfId;
public:
	void SetConfId( INT32 v)
	{
		m_ConfId=v;
	}
	INT32 GetConfId()
	{
		return m_ConfId;
	}
	INT32 GetConfId() const
	{
		return m_ConfId;
	}
private:
	//属性列表
	vector<AttrKeyValueWraper> m_ResonanceAttr;
public:
	int SizeResonanceAttr()
	{
		return m_ResonanceAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetResonanceAttr() const
	{
		return m_ResonanceAttr;
	}
	AttrKeyValueWraper GetResonanceAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_ResonanceAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_ResonanceAttr[Index];
	}
	void SetResonanceAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_ResonanceAttr=v;
	}
	void ClearResonanceAttr( )
	{
		m_ResonanceAttr.clear();
	}
	void SetResonanceAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_ResonanceAttr.size())
		{
			assert(false);
			return;
		}
		m_ResonanceAttr[Index] = v;
	}
	void AddResonanceAttr( const AttrKeyValueWraper& v )
	{
		m_ResonanceAttr.push_back(v);
	}
private:
	//增加的属性
	vector<AttrKeyValueWraper> m_NewResonanceAttr;
public:
	int SizeNewResonanceAttr()
	{
		return m_NewResonanceAttr.size();
	}
	const vector<AttrKeyValueWraper>& GetNewResonanceAttr() const
	{
		return m_NewResonanceAttr;
	}
	AttrKeyValueWraper GetNewResonanceAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_NewResonanceAttr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_NewResonanceAttr[Index];
	}
	void SetNewResonanceAttr( const vector<AttrKeyValueWraper>& v )
	{
		m_NewResonanceAttr=v;
	}
	void ClearNewResonanceAttr( )
	{
		m_NewResonanceAttr.clear();
	}
	void SetNewResonanceAttr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_NewResonanceAttr.size())
		{
			assert(false);
			return;
		}
		m_NewResonanceAttr[Index] = v;
	}
	void AddNewResonanceAttr( const AttrKeyValueWraper& v )
	{
		m_NewResonanceAttr.push_back(v);
	}
private:
	//战力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//新的战斗力
	INT32 m_NewBattleScore;
public:
	void SetNewBattleScore( INT32 v)
	{
		m_NewBattleScore=v;
	}
	INT32 GetNewBattleScore()
	{
		return m_NewBattleScore;
	}
	INT32 GetNewBattleScore() const
	{
		return m_NewBattleScore;
	}

};
//公会权限封装类
class GuildJurisdictionWraper
{
public:
	//构造函数
	GuildJurisdictionWraper()
	{
		
		m_ConfigID = -1;
		m_CurState = false;
		m_IsCanSet = false;

	}
	//赋值构造函数
	GuildJurisdictionWraper(const GuildJurisdiction& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildJurisdiction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildJurisdiction ToPB() const
	{
		GuildJurisdiction v;
		v.set_configid( m_ConfigID );
		v.set_curstate( m_CurState );
		v.set_iscanset( m_IsCanSet );

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
		GuildJurisdiction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildJurisdiction& v)
	{
		m_ConfigID = v.configid();
		m_CurState = v.curstate();
		m_IsCanSet = v.iscanset();

	}

private:
	//权限id
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
	}
private:
	//当前状态
	bool m_CurState;
public:
	void SetCurState( bool v)
	{
		m_CurState=v;
	}
	bool GetCurState()
	{
		return m_CurState;
	}
	bool GetCurState() const
	{
		return m_CurState;
	}
private:
	//是否可被操作
	bool m_IsCanSet;
public:
	void SetIsCanSet( bool v)
	{
		m_IsCanSet=v;
	}
	bool GetIsCanSet()
	{
		return m_IsCanSet;
	}
	bool GetIsCanSet() const
	{
		return m_IsCanSet;
	}

};
//RandomQuestData封装类
class RandomQuestDataWraper
{
public:
	//构造函数
	RandomQuestDataWraper()
	{
		
		m_ActivityId = -1;
		m_DayPorgress = 0;
		m_LastCompleteTime = -1;
		m_HoldPorgress = 0;
		m_HumanLevel = 0;
		m_ExtraTime = 0;
		m_LastAcceptQuestTime = 0;
		m_DailyActivity = 0;
		m_LastTime = -1;

	}
	//赋值构造函数
	RandomQuestDataWraper(const RandomQuestData& v){ Init(v); }
	//等号重载函数
	void operator = (const RandomQuestData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RandomQuestData ToPB() const
	{
		RandomQuestData v;
		v.set_activityid( m_ActivityId );
		v.mutable_questidlist()->Reserve(m_QuestIdList.size());
		for (int i=0; i<(int)m_QuestIdList.size(); i++)
		{
			v.add_questidlist(m_QuestIdList[i]);
		}
		v.set_dayporgress( m_DayPorgress );
		v.set_lastcompletetime( m_LastCompleteTime );
		v.mutable_randomlistquestid()->Reserve(m_RandomListQuestId.size());
		for (int i=0; i<(int)m_RandomListQuestId.size(); i++)
		{
			v.add_randomlistquestid(m_RandomListQuestId[i]);
		}
		v.set_holdporgress( m_HoldPorgress );
		v.set_humanlevel( m_HumanLevel );
		v.set_extratime( m_ExtraTime );
		v.mutable_curentacceptlist()->Reserve(m_CurentAcceptList.size());
		for (int i=0; i<(int)m_CurentAcceptList.size(); i++)
		{
			v.add_curentacceptlist(m_CurentAcceptList[i]);
		}
		v.set_lastacceptquesttime( m_LastAcceptQuestTime );
		v.set_dailyactivity( m_DailyActivity );
		v.set_lasttime( m_LastTime );

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
		RandomQuestData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RandomQuestData& v)
	{
		m_ActivityId = v.activityid();
		m_QuestIdList.clear();
		m_QuestIdList.reserve(v.questidlist_size());
		for( int i=0; i<v.questidlist_size(); i++)
			m_QuestIdList.push_back(v.questidlist(i));
		m_DayPorgress = v.dayporgress();
		m_LastCompleteTime = v.lastcompletetime();
		m_RandomListQuestId.clear();
		m_RandomListQuestId.reserve(v.randomlistquestid_size());
		for( int i=0; i<v.randomlistquestid_size(); i++)
			m_RandomListQuestId.push_back(v.randomlistquestid(i));
		m_HoldPorgress = v.holdporgress();
		m_HumanLevel = v.humanlevel();
		m_ExtraTime = v.extratime();
		m_CurentAcceptList.clear();
		m_CurentAcceptList.reserve(v.curentacceptlist_size());
		for( int i=0; i<v.curentacceptlist_size(); i++)
			m_CurentAcceptList.push_back(v.curentacceptlist(i));
		m_LastAcceptQuestTime = v.lastacceptquesttime();
		m_DailyActivity = v.dailyactivity();
		m_LastTime = v.lasttime();

	}

private:
	//活动id
	INT32 m_ActivityId;
public:
	void SetActivityId( INT32 v)
	{
		m_ActivityId=v;
	}
	INT32 GetActivityId()
	{
		return m_ActivityId;
	}
	INT32 GetActivityId() const
	{
		return m_ActivityId;
	}
private:
	//任务列表id
	vector<INT32> m_QuestIdList;
public:
	int SizeQuestIdList()
	{
		return m_QuestIdList.size();
	}
	const vector<INT32>& GetQuestIdList() const
	{
		return m_QuestIdList;
	}
	INT32 GetQuestIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestIdList.size())
		{
			assert(false);
			return INT32();
		}
		return m_QuestIdList[Index];
	}
	void SetQuestIdList( const vector<INT32>& v )
	{
		m_QuestIdList=v;
	}
	void ClearQuestIdList( )
	{
		m_QuestIdList.clear();
	}
	void SetQuestIdList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_QuestIdList.size())
		{
			assert(false);
			return;
		}
		m_QuestIdList[Index] = v;
	}
	void AddQuestIdList( INT32 v = -1 )
	{
		m_QuestIdList.push_back(v);
	}
private:
	//日次数
	INT32 m_DayPorgress;
public:
	void SetDayPorgress( INT32 v)
	{
		m_DayPorgress=v;
	}
	INT32 GetDayPorgress()
	{
		return m_DayPorgress;
	}
	INT32 GetDayPorgress() const
	{
		return m_DayPorgress;
	}
private:
	//活动最后完成时间
	int64_t m_LastCompleteTime;
public:
	void SetLastCompleteTime( int64_t v)
	{
		m_LastCompleteTime=v;
	}
	int64_t GetLastCompleteTime()
	{
		return m_LastCompleteTime;
	}
	int64_t GetLastCompleteTime() const
	{
		return m_LastCompleteTime;
	}
private:
	//记录完成的任务用
	vector<INT32> m_RandomListQuestId;
public:
	int SizeRandomListQuestId()
	{
		return m_RandomListQuestId.size();
	}
	const vector<INT32>& GetRandomListQuestId() const
	{
		return m_RandomListQuestId;
	}
	INT32 GetRandomListQuestId(int Index) const
	{
		if(Index<0 || Index>=(int)m_RandomListQuestId.size())
		{
			assert(false);
			return INT32();
		}
		return m_RandomListQuestId[Index];
	}
	void SetRandomListQuestId( const vector<INT32>& v )
	{
		m_RandomListQuestId=v;
	}
	void ClearRandomListQuestId( )
	{
		m_RandomListQuestId.clear();
	}
	void SetRandomListQuestId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_RandomListQuestId.size())
		{
			assert(false);
			return;
		}
		m_RandomListQuestId[Index] = v;
	}
	void AddRandomListQuestId( INT32 v = -1 )
	{
		m_RandomListQuestId.push_back(v);
	}
private:
	//找回次数
	INT32 m_HoldPorgress;
public:
	void SetHoldPorgress( INT32 v)
	{
		m_HoldPorgress=v;
	}
	INT32 GetHoldPorgress()
	{
		return m_HoldPorgress;
	}
	INT32 GetHoldPorgress() const
	{
		return m_HoldPorgress;
	}
private:
	//资源找回等级
	INT32 m_HumanLevel;
public:
	void SetHumanLevel( INT32 v)
	{
		m_HumanLevel=v;
	}
	INT32 GetHumanLevel()
	{
		return m_HumanLevel;
	}
	INT32 GetHumanLevel() const
	{
		return m_HumanLevel;
	}
private:
	//额外次数
	INT32 m_ExtraTime;
public:
	void SetExtraTime( INT32 v)
	{
		m_ExtraTime=v;
	}
	INT32 GetExtraTime()
	{
		return m_ExtraTime;
	}
	INT32 GetExtraTime() const
	{
		return m_ExtraTime;
	}
private:
	//当前接受了的任务，防止升级后和表的任务对应不上
	vector<INT32> m_CurentAcceptList;
public:
	int SizeCurentAcceptList()
	{
		return m_CurentAcceptList.size();
	}
	const vector<INT32>& GetCurentAcceptList() const
	{
		return m_CurentAcceptList;
	}
	INT32 GetCurentAcceptList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CurentAcceptList.size())
		{
			assert(false);
			return INT32();
		}
		return m_CurentAcceptList[Index];
	}
	void SetCurentAcceptList( const vector<INT32>& v )
	{
		m_CurentAcceptList=v;
	}
	void ClearCurentAcceptList( )
	{
		m_CurentAcceptList.clear();
	}
	void SetCurentAcceptList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_CurentAcceptList.size())
		{
			assert(false);
			return;
		}
		m_CurentAcceptList[Index] = v;
	}
	void AddCurentAcceptList( INT32 v = -1 )
	{
		m_CurentAcceptList.push_back(v);
	}
private:
	//上次接此活动的时间
	int64_t m_LastAcceptQuestTime;
public:
	void SetLastAcceptQuestTime( int64_t v)
	{
		m_LastAcceptQuestTime=v;
	}
	int64_t GetLastAcceptQuestTime()
	{
		return m_LastAcceptQuestTime;
	}
	int64_t GetLastAcceptQuestTime() const
	{
		return m_LastAcceptQuestTime;
	}
private:
	//每日已经获得活跃度
	INT32 m_DailyActivity;
public:
	void SetDailyActivity( INT32 v)
	{
		m_DailyActivity=v;
	}
	INT32 GetDailyActivity()
	{
		return m_DailyActivity;
	}
	INT32 GetDailyActivity() const
	{
		return m_DailyActivity;
	}
private:
	//LastTime
	int64_t m_LastTime;
public:
	void SetLastTime( int64_t v)
	{
		m_LastTime=v;
	}
	int64_t GetLastTime()
	{
		return m_LastTime;
	}
	int64_t GetLastTime() const
	{
		return m_LastTime;
	}

};
//天赋预设信息封装类
class TalentPlanInfoWraper
{
public:
	//构造函数
	TalentPlanInfoWraper()
	{
		
		m_TalentDirection = -1;

	}
	//赋值构造函数
	TalentPlanInfoWraper(const TalentPlanInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TalentPlanInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalentPlanInfo ToPB() const
	{
		TalentPlanInfo v;
		v.set_talentdirection( m_TalentDirection );
		v.mutable_talentskillidlist()->Reserve(m_TalentSkillIdList.size());
		for (int i=0; i<(int)m_TalentSkillIdList.size(); i++)
		{
			v.add_talentskillidlist(m_TalentSkillIdList[i]);
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
		TalentPlanInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TalentPlanInfo& v)
	{
		m_TalentDirection = v.talentdirection();
		m_TalentSkillIdList.clear();
		m_TalentSkillIdList.reserve(v.talentskillidlist_size());
		for( int i=0; i<v.talentskillidlist_size(); i++)
			m_TalentSkillIdList.push_back(v.talentskillidlist(i));

	}

private:
	//职业方向
	INT32 m_TalentDirection;
public:
	void SetTalentDirection( INT32 v)
	{
		m_TalentDirection=v;
	}
	INT32 GetTalentDirection()
	{
		return m_TalentDirection;
	}
	INT32 GetTalentDirection() const
	{
		return m_TalentDirection;
	}
private:
	//使用的天赋技能ID
	vector<INT32> m_TalentSkillIdList;
public:
	int SizeTalentSkillIdList()
	{
		return m_TalentSkillIdList.size();
	}
	const vector<INT32>& GetTalentSkillIdList() const
	{
		return m_TalentSkillIdList;
	}
	INT32 GetTalentSkillIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_TalentSkillIdList.size())
		{
			assert(false);
			return INT32();
		}
		return m_TalentSkillIdList[Index];
	}
	void SetTalentSkillIdList( const vector<INT32>& v )
	{
		m_TalentSkillIdList=v;
	}
	void ClearTalentSkillIdList( )
	{
		m_TalentSkillIdList.clear();
	}
	void SetTalentSkillIdList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_TalentSkillIdList.size())
		{
			assert(false);
			return;
		}
		m_TalentSkillIdList[Index] = v;
	}
	void AddTalentSkillIdList( INT32 v = -1 )
	{
		m_TalentSkillIdList.push_back(v);
	}

};
//装备洗练数据封装类
class EquipWashDataWraper
{
public:
	//构造函数
	EquipWashDataWraper()
	{
		
		m_LeftTimes = -1;

	}
	//赋值构造函数
	EquipWashDataWraper(const EquipWashData& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipWashData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipWashData ToPB() const
	{
		EquipWashData v;
		v.mutable_equipwashinfolist()->Reserve(m_EquipWashInfoList.size());
		for (int i=0; i<(int)m_EquipWashInfoList.size(); i++)
		{
			*v.add_equipwashinfolist() = m_EquipWashInfoList[i].ToPB();
		}
		v.set_lefttimes( m_LeftTimes );

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
		EquipWashData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipWashData& v)
	{
		m_EquipWashInfoList.clear();
		m_EquipWashInfoList.reserve(v.equipwashinfolist_size());
		for( int i=0; i<v.equipwashinfolist_size(); i++)
			m_EquipWashInfoList.push_back(v.equipwashinfolist(i));
		m_LeftTimes = v.lefttimes();

	}

private:
	//洗练数据列表
	vector<EquipWashInfoWraper> m_EquipWashInfoList;
public:
	int SizeEquipWashInfoList()
	{
		return m_EquipWashInfoList.size();
	}
	const vector<EquipWashInfoWraper>& GetEquipWashInfoList() const
	{
		return m_EquipWashInfoList;
	}
	EquipWashInfoWraper GetEquipWashInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipWashInfoList.size())
		{
			assert(false);
			return EquipWashInfoWraper();
		}
		return m_EquipWashInfoList[Index];
	}
	void SetEquipWashInfoList( const vector<EquipWashInfoWraper>& v )
	{
		m_EquipWashInfoList=v;
	}
	void ClearEquipWashInfoList( )
	{
		m_EquipWashInfoList.clear();
	}
	void SetEquipWashInfoList( int Index, const EquipWashInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipWashInfoList.size())
		{
			assert(false);
			return;
		}
		m_EquipWashInfoList[Index] = v;
	}
	void AddEquipWashInfoList( const EquipWashInfoWraper& v )
	{
		m_EquipWashInfoList.push_back(v);
	}
private:
	//当日洗炼剩余次数
	INT32 m_LeftTimes;
public:
	void SetLeftTimes( INT32 v)
	{
		m_LeftTimes=v;
	}
	INT32 GetLeftTimes()
	{
		return m_LeftTimes;
	}
	INT32 GetLeftTimes() const
	{
		return m_LeftTimes;
	}

};
//称号数据结构封装类
class CTitleDataWraper
{
public:
	//构造函数
	CTitleDataWraper()
	{
		
		m_TitleId = -1;
		m_TimeStamp = -1;

	}
	//赋值构造函数
	CTitleDataWraper(const CTitleData& v){ Init(v); }
	//等号重载函数
	void operator = (const CTitleData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CTitleData ToPB() const
	{
		CTitleData v;
		v.set_titleid( m_TitleId );
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
		CTitleData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CTitleData& v)
	{
		m_TitleId = v.titleid();
		m_TimeStamp = v.timestamp();

	}

private:
	//称号id
	INT32 m_TitleId;
public:
	void SetTitleId( INT32 v)
	{
		m_TitleId=v;
	}
	INT32 GetTitleId()
	{
		return m_TitleId;
	}
	INT32 GetTitleId() const
	{
		return m_TitleId;
	}
private:
	//称号过期时间
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
//天赋技能信息封装类
class TalentSkillInfoWraper
{
public:
	//构造函数
	TalentSkillInfoWraper()
	{
		
		m_TalentSkillId = -1;
		m_TalentSkillLevelID = -1;

	}
	//赋值构造函数
	TalentSkillInfoWraper(const TalentSkillInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TalentSkillInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalentSkillInfo ToPB() const
	{
		TalentSkillInfo v;
		v.set_talentskillid( m_TalentSkillId );
		v.set_talentskilllevelid( m_TalentSkillLevelID );

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
		TalentSkillInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TalentSkillInfo& v)
	{
		m_TalentSkillId = v.talentskillid();
		m_TalentSkillLevelID = v.talentskilllevelid();

	}

private:
	//天赋技能ID
	INT32 m_TalentSkillId;
public:
	void SetTalentSkillId( INT32 v)
	{
		m_TalentSkillId=v;
	}
	INT32 GetTalentSkillId()
	{
		return m_TalentSkillId;
	}
	INT32 GetTalentSkillId() const
	{
		return m_TalentSkillId;
	}
private:
	//天赋技能等级ID
	INT32 m_TalentSkillLevelID;
public:
	void SetTalentSkillLevelID( INT32 v)
	{
		m_TalentSkillLevelID=v;
	}
	INT32 GetTalentSkillLevelID()
	{
		return m_TalentSkillLevelID;
	}
	INT32 GetTalentSkillLevelID() const
	{
		return m_TalentSkillLevelID;
	}

};
//公会副本活动数据封装类
class GuildDungeonActDataWraper
{
public:
	//构造函数
	GuildDungeonActDataWraper()
	{
		

	}
	//赋值构造函数
	GuildDungeonActDataWraper(const GuildDungeonActData& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildDungeonActData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildDungeonActData ToPB() const
	{
		GuildDungeonActData v;
		v.mutable_layerinfo()->Reserve(m_LayerInfo.size());
		for (int i=0; i<(int)m_LayerInfo.size(); i++)
		{
			*v.add_layerinfo() = m_LayerInfo[i].ToPB();
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
		GuildDungeonActData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildDungeonActData& v)
	{
		m_LayerInfo.clear();
		m_LayerInfo.reserve(v.layerinfo_size());
		for( int i=0; i<v.layerinfo_size(); i++)
			m_LayerInfo.push_back(v.layerinfo(i));

	}

private:
	//公会副本各层信息
	vector<GuildDungeonLayerDataWraper> m_LayerInfo;
public:
	int SizeLayerInfo()
	{
		return m_LayerInfo.size();
	}
	const vector<GuildDungeonLayerDataWraper>& GetLayerInfo() const
	{
		return m_LayerInfo;
	}
	GuildDungeonLayerDataWraper GetLayerInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_LayerInfo.size())
		{
			assert(false);
			return GuildDungeonLayerDataWraper();
		}
		return m_LayerInfo[Index];
	}
	void SetLayerInfo( const vector<GuildDungeonLayerDataWraper>& v )
	{
		m_LayerInfo=v;
	}
	void ClearLayerInfo( )
	{
		m_LayerInfo.clear();
	}
	void SetLayerInfo( int Index, const GuildDungeonLayerDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_LayerInfo.size())
		{
			assert(false);
			return;
		}
		m_LayerInfo[Index] = v;
	}
	void AddLayerInfo( const GuildDungeonLayerDataWraper& v )
	{
		m_LayerInfo.push_back(v);
	}

};
//公会副本玩家数据封装类
class GuildDungeonPlayerDataWraper
{
public:
	//构造函数
	GuildDungeonPlayerDataWraper()
	{
		
		m_HistoryMaxLayer = 0;
		m_CurrMaxLayer = 0;
		m_CurrRewardLayer = 0;

	}
	//赋值构造函数
	GuildDungeonPlayerDataWraper(const GuildDungeonPlayerData& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildDungeonPlayerData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildDungeonPlayerData ToPB() const
	{
		GuildDungeonPlayerData v;
		v.set_historymaxlayer( m_HistoryMaxLayer );
		v.set_currmaxlayer( m_CurrMaxLayer );
		v.set_currrewardlayer( m_CurrRewardLayer );

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
		GuildDungeonPlayerData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildDungeonPlayerData& v)
	{
		m_HistoryMaxLayer = v.historymaxlayer();
		m_CurrMaxLayer = v.currmaxlayer();
		m_CurrRewardLayer = v.currrewardlayer();

	}

private:
	//历史最高层数
	INT32 m_HistoryMaxLayer;
public:
	void SetHistoryMaxLayer( INT32 v)
	{
		m_HistoryMaxLayer=v;
	}
	INT32 GetHistoryMaxLayer()
	{
		return m_HistoryMaxLayer;
	}
	INT32 GetHistoryMaxLayer() const
	{
		return m_HistoryMaxLayer;
	}
private:
	//当次活动最高层数
	INT32 m_CurrMaxLayer;
public:
	void SetCurrMaxLayer( INT32 v)
	{
		m_CurrMaxLayer=v;
	}
	INT32 GetCurrMaxLayer()
	{
		return m_CurrMaxLayer;
	}
	INT32 GetCurrMaxLayer() const
	{
		return m_CurrMaxLayer;
	}
private:
	//当次活动领奖层数
	INT32 m_CurrRewardLayer;
public:
	void SetCurrRewardLayer( INT32 v)
	{
		m_CurrRewardLayer=v;
	}
	INT32 GetCurrRewardLayer()
	{
		return m_CurrRewardLayer;
	}
	INT32 GetCurrRewardLayer() const
	{
		return m_CurrRewardLayer;
	}

};
//技能方案信息封装类
class SkillPlanInfoWraper
{
public:
	//构造函数
	SkillPlanInfoWraper()
	{
		

	}
	//赋值构造函数
	SkillPlanInfoWraper(const SkillPlanInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillPlanInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillPlanInfo ToPB() const
	{
		SkillPlanInfo v;
		v.mutable_runeidlist()->Reserve(m_RuneIDList.size());
		for (int i=0; i<(int)m_RuneIDList.size(); i++)
		{
			v.add_runeidlist(m_RuneIDList[i]);
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
		SkillPlanInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillPlanInfo& v)
	{
		m_RuneIDList.clear();
		m_RuneIDList.reserve(v.runeidlist_size());
		for( int i=0; i<v.runeidlist_size(); i++)
			m_RuneIDList.push_back(v.runeidlist(i));

	}

private:
	//铭文ID的集合
	vector<INT32> m_RuneIDList;
public:
	int SizeRuneIDList()
	{
		return m_RuneIDList.size();
	}
	const vector<INT32>& GetRuneIDList() const
	{
		return m_RuneIDList;
	}
	INT32 GetRuneIDList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RuneIDList.size())
		{
			assert(false);
			return INT32();
		}
		return m_RuneIDList[Index];
	}
	void SetRuneIDList( const vector<INT32>& v )
	{
		m_RuneIDList=v;
	}
	void ClearRuneIDList( )
	{
		m_RuneIDList.clear();
	}
	void SetRuneIDList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_RuneIDList.size())
		{
			assert(false);
			return;
		}
		m_RuneIDList[Index] = v;
	}
	void AddRuneIDList( INT32 v = -1 )
	{
		m_RuneIDList.push_back(v);
	}

};
//时装装备属性封装类
class TreasureEquipAttrWraper
{
public:
	//构造函数
	TreasureEquipAttrWraper()
	{
		
		m_Key = -1;
		m_AddType = -1;
		m_Value = -1;

	}
	//赋值构造函数
	TreasureEquipAttrWraper(const TreasureEquipAttr& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureEquipAttr& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureEquipAttr ToPB() const
	{
		TreasureEquipAttr v;
		v.set_key( m_Key );
		v.set_addtype( m_AddType );
		v.set_value( m_Value );

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
		TreasureEquipAttr pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TreasureEquipAttr& v)
	{
		m_Key = v.key();
		m_AddType = v.addtype();
		m_Value = v.value();

	}

private:
	//key
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//加值类型(0:值 1:百分比)
	INT32 m_AddType;
public:
	void SetAddType( INT32 v)
	{
		m_AddType=v;
	}
	INT32 GetAddType()
	{
		return m_AddType;
	}
	INT32 GetAddType() const
	{
		return m_AddType;
	}
private:
	//value
	float m_Value;
public:
	void SetValue( float v)
	{
		m_Value=v;
	}
	float GetValue()
	{
		return m_Value;
	}
	float GetValue() const
	{
		return m_Value;
	}

};
//宝石信息封装类
class JewelInfoWraper
{
public:
	//构造函数
	JewelInfoWraper()
	{
		
		m_EquipSlot = -1;

	}
	//赋值构造函数
	JewelInfoWraper(const JewelInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const JewelInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	JewelInfo ToPB() const
	{
		JewelInfo v;
		v.set_equipslot( m_EquipSlot );
		v.mutable_jewelslots()->Reserve(m_JewelSlots.size());
		for (int i=0; i<(int)m_JewelSlots.size(); i++)
		{
			*v.add_jewelslots() = m_JewelSlots[i].ToPB();
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
		JewelInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const JewelInfo& v)
	{
		m_EquipSlot = v.equipslot();
		m_JewelSlots.clear();
		m_JewelSlots.reserve(v.jewelslots_size());
		for( int i=0; i<v.jewelslots_size(); i++)
			m_JewelSlots.push_back(v.jewelslots(i));

	}

private:
	//装备位
	INT32 m_EquipSlot;
public:
	void SetEquipSlot( INT32 v)
	{
		m_EquipSlot=v;
	}
	INT32 GetEquipSlot()
	{
		return m_EquipSlot;
	}
	INT32 GetEquipSlot() const
	{
		return m_EquipSlot;
	}
private:
	//该位置宝石信息
	vector<JewelSlotWraper> m_JewelSlots;
public:
	int SizeJewelSlots()
	{
		return m_JewelSlots.size();
	}
	const vector<JewelSlotWraper>& GetJewelSlots() const
	{
		return m_JewelSlots;
	}
	JewelSlotWraper GetJewelSlots(int Index) const
	{
		if(Index<0 || Index>=(int)m_JewelSlots.size())
		{
			assert(false);
			return JewelSlotWraper();
		}
		return m_JewelSlots[Index];
	}
	void SetJewelSlots( const vector<JewelSlotWraper>& v )
	{
		m_JewelSlots=v;
	}
	void ClearJewelSlots( )
	{
		m_JewelSlots.clear();
	}
	void SetJewelSlots( int Index, const JewelSlotWraper& v )
	{
		if(Index<0 || Index>=(int)m_JewelSlots.size())
		{
			assert(false);
			return;
		}
		m_JewelSlots[Index] = v;
	}
	void AddJewelSlots( const JewelSlotWraper& v )
	{
		m_JewelSlots.push_back(v);
	}

};
//行当数据封装类
class BusinessQuestDataWraper
{
public:
	//构造函数
	BusinessQuestDataWraper()
	{
		
		m_BusinessQuestInfo = BusinessQuestInfoWraper();
		m_CompleteCount = -1;
		m_ResetCount = -1;

	}
	//赋值构造函数
	BusinessQuestDataWraper(const BusinessQuestData& v){ Init(v); }
	//等号重载函数
	void operator = (const BusinessQuestData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BusinessQuestData ToPB() const
	{
		BusinessQuestData v;
		*v.mutable_businessquestinfo()= m_BusinessQuestInfo.ToPB();
		v.set_completecount( m_CompleteCount );
		v.set_resetcount( m_ResetCount );

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
		BusinessQuestData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BusinessQuestData& v)
	{
		m_BusinessQuestInfo = v.businessquestinfo();
		m_CompleteCount = v.completecount();
		m_ResetCount = v.resetcount();

	}

private:
	//当前任务的信息
	BusinessQuestInfoWraper m_BusinessQuestInfo;
public:
	void SetBusinessQuestInfo( const BusinessQuestInfoWraper& v)
	{
		m_BusinessQuestInfo=v;
	}
	BusinessQuestInfoWraper GetBusinessQuestInfo()
	{
		return m_BusinessQuestInfo;
	}
	BusinessQuestInfoWraper GetBusinessQuestInfo() const
	{
		return m_BusinessQuestInfo;
	}
private:
	//完成次数
	INT32 m_CompleteCount;
public:
	void SetCompleteCount( INT32 v)
	{
		m_CompleteCount=v;
	}
	INT32 GetCompleteCount()
	{
		return m_CompleteCount;
	}
	INT32 GetCompleteCount() const
	{
		return m_CompleteCount;
	}
private:
	//重置次数
	INT32 m_ResetCount;
public:
	void SetResetCount( INT32 v)
	{
		m_ResetCount=v;
	}
	INT32 GetResetCount()
	{
		return m_ResetCount;
	}
	INT32 GetResetCount() const
	{
		return m_ResetCount;
	}

};
//精英怪信息封装类
class EliteMonsterInfoWraper
{
public:
	//构造函数
	EliteMonsterInfoWraper()
	{
		
		m_FinishTime = -1;
		m_CommonId = -1;

	}
	//赋值构造函数
	EliteMonsterInfoWraper(const EliteMonsterInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const EliteMonsterInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EliteMonsterInfo ToPB() const
	{
		EliteMonsterInfo v;
		v.set_finishtime( m_FinishTime );
		v.set_commonid( m_CommonId );

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
		EliteMonsterInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EliteMonsterInfo& v)
	{
		m_FinishTime = v.finishtime();
		m_CommonId = v.commonid();

	}

private:
	//完成次数
	INT32 m_FinishTime;
public:
	void SetFinishTime( INT32 v)
	{
		m_FinishTime=v;
	}
	INT32 GetFinishTime()
	{
		return m_FinishTime;
	}
	INT32 GetFinishTime() const
	{
		return m_FinishTime;
	}
private:
	//当前精英怪任务id
	INT32 m_CommonId;
public:
	void SetCommonId( INT32 v)
	{
		m_CommonId=v;
	}
	INT32 GetCommonId()
	{
		return m_CommonId;
	}
	INT32 GetCommonId() const
	{
		return m_CommonId;
	}

};
//公会BOSS排行榜信息封装类
class GuildBossRankInfoWraper
{
public:
	//构造函数
	GuildBossRankInfoWraper()
	{
		
		m_Playerguid = 0;
		m_Configid = -1;
		m_Playername = "";
		m_Score = -1;
		m_Rank = -1;

	}
	//赋值构造函数
	GuildBossRankInfoWraper(const GuildBossRankInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildBossRankInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildBossRankInfo ToPB() const
	{
		GuildBossRankInfo v;
		v.set_playerguid( m_Playerguid );
		v.set_configid( m_Configid );
		v.set_playername( m_Playername );
		v.set_score( m_Score );
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
		GuildBossRankInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildBossRankInfo& v)
	{
		m_Playerguid = v.playerguid();
		m_Configid = v.configid();
		m_Playername = v.playername();
		m_Score = v.score();
		m_Rank = v.rank();

	}

private:
	//playerguid
	uint64_t m_Playerguid;
public:
	void SetPlayerguid( uint64_t v)
	{
		m_Playerguid=v;
	}
	uint64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	uint64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//role表configid
	INT32 m_Configid;
public:
	void SetConfigid( INT32 v)
	{
		m_Configid=v;
	}
	INT32 GetConfigid()
	{
		return m_Configid;
	}
	INT32 GetConfigid() const
	{
		return m_Configid;
	}
private:
	//playername
	string m_Playername;
public:
	void SetPlayername( const string& v)
	{
		m_Playername=v;
	}
	string GetPlayername()
	{
		return m_Playername;
	}
	string GetPlayername() const
	{
		return m_Playername;
	}
private:
	//伤害
	INT32 m_Score;
public:
	void SetScore( INT32 v)
	{
		m_Score=v;
	}
	INT32 GetScore()
	{
		return m_Score;
	}
	INT32 GetScore() const
	{
		return m_Score;
	}
private:
	//排名
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
//副本奖励数据封装类
class PBUIRewardDataWraper
{
public:
	//构造函数
	PBUIRewardDataWraper()
	{
		
		m_ItemId = 0;
		m_ItemCount = 0;
		m_RoleId = 0;
		m_PlayerName = "";

	}
	//赋值构造函数
	PBUIRewardDataWraper(const PBUIRewardData& v){ Init(v); }
	//等号重载函数
	void operator = (const PBUIRewardData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PBUIRewardData ToPB() const
	{
		PBUIRewardData v;
		v.set_itemid( m_ItemId );
		v.set_itemcount( m_ItemCount );
		v.set_roleid( m_RoleId );
		v.set_playername( m_PlayerName );

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
		PBUIRewardData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PBUIRewardData& v)
	{
		m_ItemId = v.itemid();
		m_ItemCount = v.itemcount();
		m_RoleId = v.roleid();
		m_PlayerName = v.playername();

	}

private:
	//物品id
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
private:
	//物品数量
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
private:
	//玩家唯一id
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
	//玩家名字
	string m_PlayerName;
public:
	void SetPlayerName( const string& v)
	{
		m_PlayerName=v;
	}
	string GetPlayerName()
	{
		return m_PlayerName;
	}
	string GetPlayerName() const
	{
		return m_PlayerName;
	}

};
//魂石套装封装类
class SoulStoneSuitWraper
{
public:
	//构造函数
	SoulStoneSuitWraper()
	{
		
		m_SoulInfo = SuitInfoWraper();

	}
	//赋值构造函数
	SoulStoneSuitWraper(const SoulStoneSuit& v){ Init(v); }
	//等号重载函数
	void operator = (const SoulStoneSuit& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SoulStoneSuit ToPB() const
	{
		SoulStoneSuit v;
		*v.mutable_soulinfo()= m_SoulInfo.ToPB();
		v.mutable_stoneinfo()->Reserve(m_StoneInfo.size());
		for (int i=0; i<(int)m_StoneInfo.size(); i++)
		{
			*v.add_stoneinfo() = m_StoneInfo[i].ToPB();
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
		SoulStoneSuit pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SoulStoneSuit& v)
	{
		m_SoulInfo = v.soulinfo();
		m_StoneInfo.clear();
		m_StoneInfo.reserve(v.stoneinfo_size());
		for( int i=0; i<v.stoneinfo_size(); i++)
			m_StoneInfo.push_back(v.stoneinfo(i));

	}

private:
	//套装信息
	SuitInfoWraper m_SoulInfo;
public:
	void SetSoulInfo( const SuitInfoWraper& v)
	{
		m_SoulInfo=v;
	}
	SuitInfoWraper GetSoulInfo()
	{
		return m_SoulInfo;
	}
	SuitInfoWraper GetSoulInfo() const
	{
		return m_SoulInfo;
	}
private:
	//魂石数据
	vector<SoulStoneDataWraper> m_StoneInfo;
public:
	int SizeStoneInfo()
	{
		return m_StoneInfo.size();
	}
	const vector<SoulStoneDataWraper>& GetStoneInfo() const
	{
		return m_StoneInfo;
	}
	SoulStoneDataWraper GetStoneInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_StoneInfo.size())
		{
			assert(false);
			return SoulStoneDataWraper();
		}
		return m_StoneInfo[Index];
	}
	void SetStoneInfo( const vector<SoulStoneDataWraper>& v )
	{
		m_StoneInfo=v;
	}
	void ClearStoneInfo( )
	{
		m_StoneInfo.clear();
	}
	void SetStoneInfo( int Index, const SoulStoneDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_StoneInfo.size())
		{
			assert(false);
			return;
		}
		m_StoneInfo[Index] = v;
	}
	void AddStoneInfo( const SoulStoneDataWraper& v )
	{
		m_StoneInfo.push_back(v);
	}

};
//装备槽封装类
class EquipSlotInfoWraper
{
public:
	//构造函数
	EquipSlotInfoWraper()
	{
		
		m_Enhance_Level = -1;
		m_Enhance_Exp = -1;
		m_BattleScore = -1;
		m_Slot_Type = -1;

	}
	//赋值构造函数
	EquipSlotInfoWraper(const EquipSlotInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotInfo ToPB() const
	{
		EquipSlotInfo v;
		v.set_enhance_level( m_Enhance_Level );
		v.set_enhance_exp( m_Enhance_Exp );
		v.mutable_enhance_attr()->Reserve(m_Enhance_Attr.size());
		for (int i=0; i<(int)m_Enhance_Attr.size(); i++)
		{
			*v.add_enhance_attr() = m_Enhance_Attr[i].ToPB();
		}
		v.set_battlescore( m_BattleScore );
		v.set_slot_type( m_Slot_Type );

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
		EquipSlotInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipSlotInfo& v)
	{
		m_Enhance_Level = v.enhance_level();
		m_Enhance_Exp = v.enhance_exp();
		m_Enhance_Attr.clear();
		m_Enhance_Attr.reserve(v.enhance_attr_size());
		for( int i=0; i<v.enhance_attr_size(); i++)
			m_Enhance_Attr.push_back(v.enhance_attr(i));
		m_BattleScore = v.battlescore();
		m_Slot_Type = v.slot_type();

	}

private:
	//强化等级
	INT32 m_Enhance_Level;
public:
	void SetEnhance_Level( INT32 v)
	{
		m_Enhance_Level=v;
	}
	INT32 GetEnhance_Level()
	{
		return m_Enhance_Level;
	}
	INT32 GetEnhance_Level() const
	{
		return m_Enhance_Level;
	}
private:
	//当前段位强化经验
	INT32 m_Enhance_Exp;
public:
	void SetEnhance_Exp( INT32 v)
	{
		m_Enhance_Exp=v;
	}
	INT32 GetEnhance_Exp()
	{
		return m_Enhance_Exp;
	}
	INT32 GetEnhance_Exp() const
	{
		return m_Enhance_Exp;
	}
private:
	//强化属性
	vector<AttrKeyValueWraper> m_Enhance_Attr;
public:
	int SizeEnhance_Attr()
	{
		return m_Enhance_Attr.size();
	}
	const vector<AttrKeyValueWraper>& GetEnhance_Attr() const
	{
		return m_Enhance_Attr;
	}
	AttrKeyValueWraper GetEnhance_Attr(int Index) const
	{
		if(Index<0 || Index>=(int)m_Enhance_Attr.size())
		{
			assert(false);
			return AttrKeyValueWraper();
		}
		return m_Enhance_Attr[Index];
	}
	void SetEnhance_Attr( const vector<AttrKeyValueWraper>& v )
	{
		m_Enhance_Attr=v;
	}
	void ClearEnhance_Attr( )
	{
		m_Enhance_Attr.clear();
	}
	void SetEnhance_Attr( int Index, const AttrKeyValueWraper& v )
	{
		if(Index<0 || Index>=(int)m_Enhance_Attr.size())
		{
			assert(false);
			return;
		}
		m_Enhance_Attr[Index] = v;
	}
	void AddEnhance_Attr( const AttrKeyValueWraper& v )
	{
		m_Enhance_Attr.push_back(v);
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//装备槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}

};
//生活技能解锁封装类
class BuinessUnlockInfoWraper
{
public:
	//构造函数
	BuinessUnlockInfoWraper()
	{
		
		m_Mutual = -1;
		m_EndTime = -1;

	}
	//赋值构造函数
	BuinessUnlockInfoWraper(const BuinessUnlockInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessUnlockInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessUnlockInfo ToPB() const
	{
		BuinessUnlockInfo v;
		v.set_mutual( m_Mutual );
		v.set_endtime( m_EndTime );

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
		BuinessUnlockInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BuinessUnlockInfo& v)
	{
		m_Mutual = v.mutual();
		m_EndTime = v.endtime();

	}

private:
	//互斥类型
	INT32 m_Mutual;
public:
	void SetMutual( INT32 v)
	{
		m_Mutual=v;
	}
	INT32 GetMutual()
	{
		return m_Mutual;
	}
	INT32 GetMutual() const
	{
		return m_Mutual;
	}
private:
	//解锁的结束时间
	int64_t m_EndTime;
public:
	void SetEndTime( int64_t v)
	{
		m_EndTime=v;
	}
	int64_t GetEndTime()
	{
		return m_EndTime;
	}
	int64_t GetEndTime() const
	{
		return m_EndTime;
	}

};
//生活技能封装类
class BuinessSkillDataWraper
{
public:
	//构造函数
	BuinessSkillDataWraper()
	{
		
		m_SkillID = -1;
		m_SkillLv = -1;
		m_Locked = -1;
		m_SkillExp = -1;
		m_UseCount = -1;

	}
	//赋值构造函数
	BuinessSkillDataWraper(const BuinessSkillData& v){ Init(v); }
	//等号重载函数
	void operator = (const BuinessSkillData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuinessSkillData ToPB() const
	{
		BuinessSkillData v;
		v.set_skillid( m_SkillID );
		v.set_skilllv( m_SkillLv );
		v.set_locked( m_Locked );
		v.set_skillexp( m_SkillExp );
		v.set_usecount( m_UseCount );

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
		BuinessSkillData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BuinessSkillData& v)
	{
		m_SkillID = v.skillid();
		m_SkillLv = v.skilllv();
		m_Locked = v.locked();
		m_SkillExp = v.skillexp();
		m_UseCount = v.usecount();

	}

private:
	//生活技能ID
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
	//等级
	INT32 m_SkillLv;
public:
	void SetSkillLv( INT32 v)
	{
		m_SkillLv=v;
	}
	INT32 GetSkillLv()
	{
		return m_SkillLv;
	}
	INT32 GetSkillLv() const
	{
		return m_SkillLv;
	}
private:
	//是否锁
	INT32 m_Locked;
public:
	void SetLocked( INT32 v)
	{
		m_Locked=v;
	}
	INT32 GetLocked()
	{
		return m_Locked;
	}
	INT32 GetLocked() const
	{
		return m_Locked;
	}
private:
	//当前经验
	INT32 m_SkillExp;
public:
	void SetSkillExp( INT32 v)
	{
		m_SkillExp=v;
	}
	INT32 GetSkillExp()
	{
		return m_SkillExp;
	}
	INT32 GetSkillExp() const
	{
		return m_SkillExp;
	}
private:
	//使用技能书的次数
	INT32 m_UseCount;
public:
	void SetUseCount( INT32 v)
	{
		m_UseCount=v;
	}
	INT32 GetUseCount()
	{
		return m_UseCount;
	}
	INT32 GetUseCount() const
	{
		return m_UseCount;
	}

};
//宠物自动转化封装类
class PetItemAutoBreakInfoWraper
{
public:
	//构造函数
	PetItemAutoBreakInfoWraper()
	{
		
		m_ProtoId = -1;
		m_BreakType = -1;

	}
	//赋值构造函数
	PetItemAutoBreakInfoWraper(const PetItemAutoBreakInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const PetItemAutoBreakInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PetItemAutoBreakInfo ToPB() const
	{
		PetItemAutoBreakInfo v;
		v.set_protoid( m_ProtoId );
		v.set_breaktype( m_BreakType );

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
		PetItemAutoBreakInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PetItemAutoBreakInfo& v)
	{
		m_ProtoId = v.protoid();
		m_BreakType = v.breaktype();

	}

private:
	//宠物类型ID
	INT32 m_ProtoId;
public:
	void SetProtoId( INT32 v)
	{
		m_ProtoId=v;
	}
	INT32 GetProtoId()
	{
		return m_ProtoId;
	}
	INT32 GetProtoId() const
	{
		return m_ProtoId;
	}
private:
	//转化类型
	INT32 m_BreakType;
public:
	void SetBreakType( INT32 v)
	{
		m_BreakType=v;
	}
	INT32 GetBreakType()
	{
		return m_BreakType;
	}
	INT32 GetBreakType() const
	{
		return m_BreakType;
	}

};
//Resource封装类
class ResourceWraper
{
public:
	//构造函数
	ResourceWraper()
	{
		
		m_Type = 0;
		m_Value = 0;
		m_TodayValue = -1;

	}
	//赋值构造函数
	ResourceWraper(const Resource& v){ Init(v); }
	//等号重载函数
	void operator = (const Resource& v){ Init(v); }
 	//转化成Protobuffer类型函数
	Resource ToPB() const
	{
		Resource v;
		v.set_type( m_Type );
		v.set_value( m_Value );
		v.set_todayvalue( m_TodayValue );

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
		Resource pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const Resource& v)
	{
		m_Type = v.type();
		m_Value = v.value();
		m_TodayValue = v.todayvalue();

	}

private:
	//资源类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//Value
	int64_t m_Value;
public:
	void SetValue( int64_t v)
	{
		m_Value=v;
	}
	int64_t GetValue()
	{
		return m_Value;
	}
	int64_t GetValue() const
	{
		return m_Value;
	}
private:
	//当日获得的
	int64_t m_TodayValue;
public:
	void SetTodayValue( int64_t v)
	{
		m_TodayValue=v;
	}
	int64_t GetTodayValue()
	{
		return m_TodayValue;
	}
	int64_t GetTodayValue() const
	{
		return m_TodayValue;
	}

};
//技能cd数据封装类
class SkillCDInfoWraper
{
public:
	//构造函数
	SkillCDInfoWraper()
	{
		
		m_SkillId = -1;
		m_SurplusTime = -1;
		m_CommonSurplusTime = -1;

	}
	//赋值构造函数
	SkillCDInfoWraper(const SkillCDInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillCDInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillCDInfo ToPB() const
	{
		SkillCDInfo v;
		v.set_skillid( m_SkillId );
		v.set_surplustime( m_SurplusTime );
		v.set_commonsurplustime( m_CommonSurplusTime );

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
		SkillCDInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillCDInfo& v)
	{
		m_SkillId = v.skillid();
		m_SurplusTime = v.surplustime();
		m_CommonSurplusTime = v.commonsurplustime();

	}

private:
	//技能Id
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
private:
	//剩余CD时间
	INT32 m_SurplusTime;
public:
	void SetSurplusTime( INT32 v)
	{
		m_SurplusTime=v;
	}
	INT32 GetSurplusTime()
	{
		return m_SurplusTime;
	}
	INT32 GetSurplusTime() const
	{
		return m_SurplusTime;
	}
private:
	//公共CD剩余时间
	INT32 m_CommonSurplusTime;
public:
	void SetCommonSurplusTime( INT32 v)
	{
		m_CommonSurplusTime=v;
	}
	INT32 GetCommonSurplusTime()
	{
		return m_CommonSurplusTime;
	}
	INT32 GetCommonSurplusTime() const
	{
		return m_CommonSurplusTime;
	}

};
//副本战绩封装类
class DungeonExploitsWraper
{
public:
	//构造函数
	DungeonExploitsWraper()
	{
		

	}
	//赋值构造函数
	DungeonExploitsWraper(const DungeonExploits& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonExploits& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonExploits ToPB() const
	{
		DungeonExploits v;
		v.mutable_exploits()->Reserve(m_Exploits.size());
		for (int i=0; i<(int)m_Exploits.size(); i++)
		{
			*v.add_exploits() = m_Exploits[i].ToPB();
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
		DungeonExploits pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DungeonExploits& v)
	{
		m_Exploits.clear();
		m_Exploits.reserve(v.exploits_size());
		for( int i=0; i<v.exploits_size(); i++)
			m_Exploits.push_back(v.exploits(i));

	}

private:
	//战绩数据
	vector<RealTimeExploitsWraper> m_Exploits;
public:
	int SizeExploits()
	{
		return m_Exploits.size();
	}
	const vector<RealTimeExploitsWraper>& GetExploits() const
	{
		return m_Exploits;
	}
	RealTimeExploitsWraper GetExploits(int Index) const
	{
		if(Index<0 || Index>=(int)m_Exploits.size())
		{
			assert(false);
			return RealTimeExploitsWraper();
		}
		return m_Exploits[Index];
	}
	void SetExploits( const vector<RealTimeExploitsWraper>& v )
	{
		m_Exploits=v;
	}
	void ClearExploits( )
	{
		m_Exploits.clear();
	}
	void SetExploits( int Index, const RealTimeExploitsWraper& v )
	{
		if(Index<0 || Index>=(int)m_Exploits.size())
		{
			assert(false);
			return;
		}
		m_Exploits[Index] = v;
	}
	void AddExploits( const RealTimeExploitsWraper& v )
	{
		m_Exploits.push_back(v);
	}

};
//兑换活动信息封装类
class ExchangeInfoWraper
{
public:
	//构造函数
	ExchangeInfoWraper()
	{
		
		m_ConfId = -1;
		m_ExchangeCount = -1;

	}
	//赋值构造函数
	ExchangeInfoWraper(const ExchangeInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ExchangeInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExchangeInfo ToPB() const
	{
		ExchangeInfo v;
		v.set_confid( m_ConfId );
		v.set_exchangecount( m_ExchangeCount );

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
		ExchangeInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ExchangeInfo& v)
	{
		m_ConfId = v.confid();
		m_ExchangeCount = v.exchangecount();

	}

private:
	//兑换项Id
	INT32 m_ConfId;
public:
	void SetConfId( INT32 v)
	{
		m_ConfId=v;
	}
	INT32 GetConfId()
	{
		return m_ConfId;
	}
	INT32 GetConfId() const
	{
		return m_ConfId;
	}
private:
	//兑换次数
	INT32 m_ExchangeCount;
public:
	void SetExchangeCount( INT32 v)
	{
		m_ExchangeCount=v;
	}
	INT32 GetExchangeCount()
	{
		return m_ExchangeCount;
	}
	INT32 GetExchangeCount() const
	{
		return m_ExchangeCount;
	}

};
//星耀NPCinfo封装类
class StarBattleNPCWraper
{
public:
	//构造函数
	StarBattleNPCWraper()
	{
		
		m_Id = -1;
		m_Waypointid = -1;
		m_Index = -1;
		m_Incount = 0;
		m_Wincount = 0;

	}
	//赋值构造函数
	StarBattleNPCWraper(const StarBattleNPC& v){ Init(v); }
	//等号重载函数
	void operator = (const StarBattleNPC& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StarBattleNPC ToPB() const
	{
		StarBattleNPC v;
		v.set_id( m_Id );
		v.set_waypointid( m_Waypointid );
		v.set_index( m_Index );
		v.set_incount( m_Incount );
		v.set_wincount( m_Wincount );

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
		StarBattleNPC pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const StarBattleNPC& v)
	{
		m_Id = v.id();
		m_Waypointid = v.waypointid();
		m_Index = v.index();
		m_Incount = v.incount();
		m_Wincount = v.wincount();

	}

private:
	//id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//waypointid(不用了)
	INT32 m_Waypointid;
public:
	void SetWaypointid( INT32 v)
	{
		m_Waypointid=v;
	}
	INT32 GetWaypointid()
	{
		return m_Waypointid;
	}
	INT32 GetWaypointid() const
	{
		return m_Waypointid;
	}
private:
	//index(星耀表里第几个NPC)
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
private:
	//进入的队伍数
	INT32 m_Incount;
public:
	void SetIncount( INT32 v)
	{
		m_Incount=v;
	}
	INT32 GetIncount()
	{
		return m_Incount;
	}
	INT32 GetIncount() const
	{
		return m_Incount;
	}
private:
	//胜利的队伍数
	INT32 m_Wincount;
public:
	void SetWincount( INT32 v)
	{
		m_Wincount=v;
	}
	INT32 GetWincount()
	{
		return m_Wincount;
	}
	INT32 GetWincount() const
	{
		return m_Wincount;
	}

};
//生活技能数据封装类
class LifeSkillDataWraper
{
public:
	//构造函数
	LifeSkillDataWraper()
	{
		
		m_SkillID = -1;
		m_SkillLevel = -1;
		m_SkillExp = -1;

	}
	//赋值构造函数
	LifeSkillDataWraper(const LifeSkillData& v){ Init(v); }
	//等号重载函数
	void operator = (const LifeSkillData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LifeSkillData ToPB() const
	{
		LifeSkillData v;
		v.set_skillid( m_SkillID );
		v.set_skilllevel( m_SkillLevel );
		v.set_skillexp( m_SkillExp );
		v.mutable_formula()->Reserve(m_Formula.size());
		for (int i=0; i<(int)m_Formula.size(); i++)
		{
			*v.add_formula() = m_Formula[i].ToPB();
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
		LifeSkillData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const LifeSkillData& v)
	{
		m_SkillID = v.skillid();
		m_SkillLevel = v.skilllevel();
		m_SkillExp = v.skillexp();
		m_Formula.clear();
		m_Formula.reserve(v.formula_size());
		for( int i=0; i<v.formula_size(); i++)
			m_Formula.push_back(v.formula(i));

	}

private:
	//生活技能id
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
	//生活技能等级
	INT32 m_SkillLevel;
public:
	void SetSkillLevel( INT32 v)
	{
		m_SkillLevel=v;
	}
	INT32 GetSkillLevel()
	{
		return m_SkillLevel;
	}
	INT32 GetSkillLevel() const
	{
		return m_SkillLevel;
	}
private:
	//生活技能经验
	INT32 m_SkillExp;
public:
	void SetSkillExp( INT32 v)
	{
		m_SkillExp=v;
	}
	INT32 GetSkillExp()
	{
		return m_SkillExp;
	}
	INT32 GetSkillExp() const
	{
		return m_SkillExp;
	}
private:
	//配方信息
	vector<LifeFormulaDataWraper> m_Formula;
public:
	int SizeFormula()
	{
		return m_Formula.size();
	}
	const vector<LifeFormulaDataWraper>& GetFormula() const
	{
		return m_Formula;
	}
	LifeFormulaDataWraper GetFormula(int Index) const
	{
		if(Index<0 || Index>=(int)m_Formula.size())
		{
			assert(false);
			return LifeFormulaDataWraper();
		}
		return m_Formula[Index];
	}
	void SetFormula( const vector<LifeFormulaDataWraper>& v )
	{
		m_Formula=v;
	}
	void ClearFormula( )
	{
		m_Formula.clear();
	}
	void SetFormula( int Index, const LifeFormulaDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Formula.size())
		{
			assert(false);
			return;
		}
		m_Formula[Index] = v;
	}
	void AddFormula( const LifeFormulaDataWraper& v )
	{
		m_Formula.push_back(v);
	}

};
//PBVote封装类
class PBVoteWraper
{
public:
	//构造函数
	PBVoteWraper()
	{
		
		m_Type = 0;
		m_RoleId = 0;
		m_VoteId = 0;

	}
	//赋值构造函数
	PBVoteWraper(const PBVote& v){ Init(v); }
	//等号重载函数
	void operator = (const PBVote& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PBVote ToPB() const
	{
		PBVote v;
		v.set_type( m_Type );
		v.set_roleid( m_RoleId );
		v.mutable_voterole()->Reserve(m_VoteRole.size());
		for (int i=0; i<(int)m_VoteRole.size(); i++)
		{
			v.add_voterole(m_VoteRole[i]);
		}
		v.set_voteid( m_VoteId );

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
		PBVote pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PBVote& v)
	{
		m_Type = v.type();
		m_RoleId = v.roleid();
		m_VoteRole.clear();
		m_VoteRole.reserve(v.voterole_size());
		for( int i=0; i<v.voterole_size(); i++)
			m_VoteRole.push_back(v.voterole(i));
		m_VoteId = v.voteid();

	}

private:
	//Type
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//RoleId
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
	//VoteRole
	vector<uint64_t> m_VoteRole;
public:
	int SizeVoteRole()
	{
		return m_VoteRole.size();
	}
	const vector<uint64_t>& GetVoteRole() const
	{
		return m_VoteRole;
	}
	uint64_t GetVoteRole(int Index) const
	{
		if(Index<0 || Index>=(int)m_VoteRole.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_VoteRole[Index];
	}
	void SetVoteRole( const vector<uint64_t>& v )
	{
		m_VoteRole=v;
	}
	void ClearVoteRole( )
	{
		m_VoteRole.clear();
	}
	void SetVoteRole( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_VoteRole.size())
		{
			assert(false);
			return;
		}
		m_VoteRole[Index] = v;
	}
	void AddVoteRole( uint64_t v = 0 )
	{
		m_VoteRole.push_back(v);
	}
private:
	//VoteId
	uint64_t m_VoteId;
public:
	void SetVoteId( uint64_t v)
	{
		m_VoteId=v;
	}
	uint64_t GetVoteId()
	{
		return m_VoteId;
	}
	uint64_t GetVoteId() const
	{
		return m_VoteId;
	}

};
//纹章盒封装类
class EmblemBoxDataWraper
{
public:
	//构造函数
	EmblemBoxDataWraper()
	{
		
		m_Emblem_slot = ItemDataWraper();
		m_Diamante_id = -1;

	}
	//赋值构造函数
	EmblemBoxDataWraper(const EmblemBoxData& v){ Init(v); }
	//等号重载函数
	void operator = (const EmblemBoxData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EmblemBoxData ToPB() const
	{
		EmblemBoxData v;
		*v.mutable_emblem_slot()= m_Emblem_slot.ToPB();
		v.set_diamante_id( m_Diamante_id );

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
		EmblemBoxData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EmblemBoxData& v)
	{
		m_Emblem_slot = v.emblem_slot();
		m_Diamante_id = v.diamante_id();

	}

private:
	//装备纹章
	ItemDataWraper m_Emblem_slot;
public:
	void SetEmblem_slot( const ItemDataWraper& v)
	{
		m_Emblem_slot=v;
	}
	ItemDataWraper GetEmblem_slot()
	{
		return m_Emblem_slot;
	}
	ItemDataWraper GetEmblem_slot() const
	{
		return m_Emblem_slot;
	}
private:
	//镶钻id
	INT32 m_Diamante_id;
public:
	void SetDiamante_id( INT32 v)
	{
		m_Diamante_id=v;
	}
	INT32 GetDiamante_id()
	{
		return m_Diamante_id;
	}
	INT32 GetDiamante_id() const
	{
		return m_Diamante_id;
	}

};
//QuestListData封装类
class QuestListDataWraper
{
public:
	//构造函数
	QuestListDataWraper()
	{
		

	}
	//赋值构造函数
	QuestListDataWraper(const QuestListData& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestListData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestListData ToPB() const
	{
		QuestListData v;
		v.mutable_questslist()->Reserve(m_QuestsList.size());
		for (int i=0; i<(int)m_QuestsList.size(); i++)
		{
			*v.add_questslist() = m_QuestsList[i].ToPB();
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
		QuestListData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const QuestListData& v)
	{
		m_QuestsList.clear();
		m_QuestsList.reserve(v.questslist_size());
		for( int i=0; i<v.questslist_size(); i++)
			m_QuestsList.push_back(v.questslist(i));

	}

private:
	//QuestsList
	vector<QuestDataWraper> m_QuestsList;
public:
	int SizeQuestsList()
	{
		return m_QuestsList.size();
	}
	const vector<QuestDataWraper>& GetQuestsList() const
	{
		return m_QuestsList;
	}
	QuestDataWraper GetQuestsList(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestsList.size())
		{
			assert(false);
			return QuestDataWraper();
		}
		return m_QuestsList[Index];
	}
	void SetQuestsList( const vector<QuestDataWraper>& v )
	{
		m_QuestsList=v;
	}
	void ClearQuestsList( )
	{
		m_QuestsList.clear();
	}
	void SetQuestsList( int Index, const QuestDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_QuestsList.size())
		{
			assert(false);
			return;
		}
		m_QuestsList[Index] = v;
	}
	void AddQuestsList( const QuestDataWraper& v )
	{
		m_QuestsList.push_back(v);
	}

};
//RelationUnionInfo封装类
class RelationUnionInfoWraper
{
public:
	//构造函数
	RelationUnionInfoWraper()
	{
		
		m_LeaderRoleId = 0;
		m_TeamId = 0;
		m_TeamType = -1;
		m_RelationUnionName = "";
		m_UnionValue = 0;
		m_MergeUnionId = 0;

	}
	//赋值构造函数
	RelationUnionInfoWraper(const RelationUnionInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const RelationUnionInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RelationUnionInfo ToPB() const
	{
		RelationUnionInfo v;
		v.set_leaderroleid( m_LeaderRoleId );
		v.set_teamid( m_TeamId );
		v.set_teamtype( m_TeamType );
		v.mutable_memberevent()->Reserve(m_MemberEvent.size());
		for (int i=0; i<(int)m_MemberEvent.size(); i++)
		{
			*v.add_memberevent() = m_MemberEvent[i].ToPB();
		}
		v.set_relationunionname( m_RelationUnionName );
		v.mutable_members()->Reserve(m_Members.size());
		for (int i=0; i<(int)m_Members.size(); i++)
		{
			*v.add_members() = m_Members[i].ToPB();
		}
		v.set_unionvalue( m_UnionValue );
		v.mutable_voteevent()->Reserve(m_VoteEvent.size());
		for (int i=0; i<(int)m_VoteEvent.size(); i++)
		{
			*v.add_voteevent() = m_VoteEvent[i].ToPB();
		}
		v.set_mergeunionid( m_MergeUnionId );

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
		RelationUnionInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RelationUnionInfo& v)
	{
		m_LeaderRoleId = v.leaderroleid();
		m_TeamId = v.teamid();
		m_TeamType = v.teamtype();
		m_MemberEvent.clear();
		m_MemberEvent.reserve(v.memberevent_size());
		for( int i=0; i<v.memberevent_size(); i++)
			m_MemberEvent.push_back(v.memberevent(i));
		m_RelationUnionName = v.relationunionname();
		m_Members.clear();
		m_Members.reserve(v.members_size());
		for( int i=0; i<v.members_size(); i++)
			m_Members.push_back(v.members(i));
		m_UnionValue = v.unionvalue();
		m_VoteEvent.clear();
		m_VoteEvent.reserve(v.voteevent_size());
		for( int i=0; i<v.voteevent_size(); i++)
			m_VoteEvent.push_back(v.voteevent(i));
		m_MergeUnionId = v.mergeunionid();

	}

private:
	//LeaderRoleId
	uint64_t m_LeaderRoleId;
public:
	void SetLeaderRoleId( uint64_t v)
	{
		m_LeaderRoleId=v;
	}
	uint64_t GetLeaderRoleId()
	{
		return m_LeaderRoleId;
	}
	uint64_t GetLeaderRoleId() const
	{
		return m_LeaderRoleId;
	}
private:
	//TeamId
	uint64_t m_TeamId;
public:
	void SetTeamId( uint64_t v)
	{
		m_TeamId=v;
	}
	uint64_t GetTeamId()
	{
		return m_TeamId;
	}
	uint64_t GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//TeamType
	INT32 m_TeamType;
public:
	void SetTeamType( INT32 v)
	{
		m_TeamType=v;
	}
	INT32 GetTeamType()
	{
		return m_TeamType;
	}
	INT32 GetTeamType() const
	{
		return m_TeamType;
	}
private:
	//MemberEvent
	vector<ChatInfoVoteWraper> m_MemberEvent;
public:
	int SizeMemberEvent()
	{
		return m_MemberEvent.size();
	}
	const vector<ChatInfoVoteWraper>& GetMemberEvent() const
	{
		return m_MemberEvent;
	}
	ChatInfoVoteWraper GetMemberEvent(int Index) const
	{
		if(Index<0 || Index>=(int)m_MemberEvent.size())
		{
			assert(false);
			return ChatInfoVoteWraper();
		}
		return m_MemberEvent[Index];
	}
	void SetMemberEvent( const vector<ChatInfoVoteWraper>& v )
	{
		m_MemberEvent=v;
	}
	void ClearMemberEvent( )
	{
		m_MemberEvent.clear();
	}
	void SetMemberEvent( int Index, const ChatInfoVoteWraper& v )
	{
		if(Index<0 || Index>=(int)m_MemberEvent.size())
		{
			assert(false);
			return;
		}
		m_MemberEvent[Index] = v;
	}
	void AddMemberEvent( const ChatInfoVoteWraper& v )
	{
		m_MemberEvent.push_back(v);
	}
private:
	//缔约团
	string m_RelationUnionName;
public:
	void SetRelationUnionName( const string& v)
	{
		m_RelationUnionName=v;
	}
	string GetRelationUnionName()
	{
		return m_RelationUnionName;
	}
	string GetRelationUnionName() const
	{
		return m_RelationUnionName;
	}
private:
	//Members
	vector<TeamMemberInfoWraper> m_Members;
public:
	int SizeMembers()
	{
		return m_Members.size();
	}
	const vector<TeamMemberInfoWraper>& GetMembers() const
	{
		return m_Members;
	}
	TeamMemberInfoWraper GetMembers(int Index) const
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return TeamMemberInfoWraper();
		}
		return m_Members[Index];
	}
	void SetMembers( const vector<TeamMemberInfoWraper>& v )
	{
		m_Members=v;
	}
	void ClearMembers( )
	{
		m_Members.clear();
	}
	void SetMembers( int Index, const TeamMemberInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Members.size())
		{
			assert(false);
			return;
		}
		m_Members[Index] = v;
	}
	void AddMembers( const TeamMemberInfoWraper& v )
	{
		m_Members.push_back(v);
	}
private:
	//UnionValue
	uint64_t m_UnionValue;
public:
	void SetUnionValue( uint64_t v)
	{
		m_UnionValue=v;
	}
	uint64_t GetUnionValue()
	{
		return m_UnionValue;
	}
	uint64_t GetUnionValue() const
	{
		return m_UnionValue;
	}
private:
	//MemberEvent
	vector<ChatInfoVoteWraper> m_VoteEvent;
public:
	int SizeVoteEvent()
	{
		return m_VoteEvent.size();
	}
	const vector<ChatInfoVoteWraper>& GetVoteEvent() const
	{
		return m_VoteEvent;
	}
	ChatInfoVoteWraper GetVoteEvent(int Index) const
	{
		if(Index<0 || Index>=(int)m_VoteEvent.size())
		{
			assert(false);
			return ChatInfoVoteWraper();
		}
		return m_VoteEvent[Index];
	}
	void SetVoteEvent( const vector<ChatInfoVoteWraper>& v )
	{
		m_VoteEvent=v;
	}
	void ClearVoteEvent( )
	{
		m_VoteEvent.clear();
	}
	void SetVoteEvent( int Index, const ChatInfoVoteWraper& v )
	{
		if(Index<0 || Index>=(int)m_VoteEvent.size())
		{
			assert(false);
			return;
		}
		m_VoteEvent[Index] = v;
	}
	void AddVoteEvent( const ChatInfoVoteWraper& v )
	{
		m_VoteEvent.push_back(v);
	}
private:
	//MergeUnionId
	uint64_t m_MergeUnionId;
public:
	void SetMergeUnionId( uint64_t v)
	{
		m_MergeUnionId=v;
	}
	uint64_t GetMergeUnionId()
	{
		return m_MergeUnionId;
	}
	uint64_t GetMergeUnionId() const
	{
		return m_MergeUnionId;
	}

};
//数据库背包封装类
class DBBagsWraper
{
public:
	//构造函数
	DBBagsWraper()
	{
		

	}
	//赋值构造函数
	DBBagsWraper(const DBBags& v){ Init(v); }
	//等号重载函数
	void operator = (const DBBags& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DBBags ToPB() const
	{
		DBBags v;
		v.mutable_bags()->Reserve(m_Bags.size());
		for (int i=0; i<(int)m_Bags.size(); i++)
		{
			*v.add_bags() = m_Bags[i].ToPB();
		}
		v.mutable_redpointguids()->Reserve(m_RedPointGuids.size());
		for (int i=0; i<(int)m_RedPointGuids.size(); i++)
		{
			v.add_redpointguids(m_RedPointGuids[i]);
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
		DBBags pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DBBags& v)
	{
		m_Bags.clear();
		m_Bags.reserve(v.bags_size());
		for( int i=0; i<v.bags_size(); i++)
			m_Bags.push_back(v.bags(i));
		m_RedPointGuids.clear();
		m_RedPointGuids.reserve(v.redpointguids_size());
		for( int i=0; i<v.redpointguids_size(); i++)
			m_RedPointGuids.push_back(v.redpointguids(i));

	}

private:
	//背包列表
	vector<BagDataWraper> m_Bags;
public:
	int SizeBags()
	{
		return m_Bags.size();
	}
	const vector<BagDataWraper>& GetBags() const
	{
		return m_Bags;
	}
	BagDataWraper GetBags(int Index) const
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return BagDataWraper();
		}
		return m_Bags[Index];
	}
	void SetBags( const vector<BagDataWraper>& v )
	{
		m_Bags=v;
	}
	void ClearBags( )
	{
		m_Bags.clear();
	}
	void SetBags( int Index, const BagDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Bags.size())
		{
			assert(false);
			return;
		}
		m_Bags[Index] = v;
	}
	void AddBags( const BagDataWraper& v )
	{
		m_Bags.push_back(v);
	}
private:
	//红点系统
	vector<uint64_t> m_RedPointGuids;
public:
	int SizeRedPointGuids()
	{
		return m_RedPointGuids.size();
	}
	const vector<uint64_t>& GetRedPointGuids() const
	{
		return m_RedPointGuids;
	}
	uint64_t GetRedPointGuids(int Index) const
	{
		if(Index<0 || Index>=(int)m_RedPointGuids.size())
		{
			assert(false);
			return uint64_t();
		}
		return m_RedPointGuids[Index];
	}
	void SetRedPointGuids( const vector<uint64_t>& v )
	{
		m_RedPointGuids=v;
	}
	void ClearRedPointGuids( )
	{
		m_RedPointGuids.clear();
	}
	void SetRedPointGuids( int Index, uint64_t v )
	{
		if(Index<0 || Index>=(int)m_RedPointGuids.size())
		{
			assert(false);
			return;
		}
		m_RedPointGuids[Index] = v;
	}
	void AddRedPointGuids( uint64_t v = 0 )
	{
		m_RedPointGuids.push_back(v);
	}

};
//ChatRoomPBInfo封装类
class ChatRoomPBInfoWraper
{
public:
	//构造函数
	ChatRoomPBInfoWraper()
	{
		
		m_RoomBaseInfoPB = RoomBaseInfoWraper();

	}
	//赋值构造函数
	ChatRoomPBInfoWraper(const ChatRoomPBInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatRoomPBInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatRoomPBInfo ToPB() const
	{
		ChatRoomPBInfo v;
		v.mutable_playerlist()->Reserve(m_PlayerList.size());
		for (int i=0; i<(int)m_PlayerList.size(); i++)
		{
			*v.add_playerlist() = m_PlayerList[i].ToPB();
		}
		*v.mutable_roombaseinfopb()= m_RoomBaseInfoPB.ToPB();
		v.mutable_chatmsg()->Reserve(m_ChatMsg.size());
		for (int i=0; i<(int)m_ChatMsg.size(); i++)
		{
			*v.add_chatmsg() = m_ChatMsg[i].ToPB();
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
		ChatRoomPBInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatRoomPBInfo& v)
	{
		m_PlayerList.clear();
		m_PlayerList.reserve(v.playerlist_size());
		for( int i=0; i<v.playerlist_size(); i++)
			m_PlayerList.push_back(v.playerlist(i));
		m_RoomBaseInfoPB = v.roombaseinfopb();
		m_ChatMsg.clear();
		m_ChatMsg.reserve(v.chatmsg_size());
		for( int i=0; i<v.chatmsg_size(); i++)
			m_ChatMsg.push_back(v.chatmsg(i));

	}

private:
	//PlayerList
	vector<ChatRoomPlayerDataWraper> m_PlayerList;
public:
	int SizePlayerList()
	{
		return m_PlayerList.size();
	}
	const vector<ChatRoomPlayerDataWraper>& GetPlayerList() const
	{
		return m_PlayerList;
	}
	ChatRoomPlayerDataWraper GetPlayerList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PlayerList.size())
		{
			assert(false);
			return ChatRoomPlayerDataWraper();
		}
		return m_PlayerList[Index];
	}
	void SetPlayerList( const vector<ChatRoomPlayerDataWraper>& v )
	{
		m_PlayerList=v;
	}
	void ClearPlayerList( )
	{
		m_PlayerList.clear();
	}
	void SetPlayerList( int Index, const ChatRoomPlayerDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_PlayerList.size())
		{
			assert(false);
			return;
		}
		m_PlayerList[Index] = v;
	}
	void AddPlayerList( const ChatRoomPlayerDataWraper& v )
	{
		m_PlayerList.push_back(v);
	}
private:
	//RoomBaseInfoPB
	RoomBaseInfoWraper m_RoomBaseInfoPB;
public:
	void SetRoomBaseInfoPB( const RoomBaseInfoWraper& v)
	{
		m_RoomBaseInfoPB=v;
	}
	RoomBaseInfoWraper GetRoomBaseInfoPB()
	{
		return m_RoomBaseInfoPB;
	}
	RoomBaseInfoWraper GetRoomBaseInfoPB() const
	{
		return m_RoomBaseInfoPB;
	}
private:
	//ChatMsg
	vector<ChatInfoWraper> m_ChatMsg;
public:
	int SizeChatMsg()
	{
		return m_ChatMsg.size();
	}
	const vector<ChatInfoWraper>& GetChatMsg() const
	{
		return m_ChatMsg;
	}
	ChatInfoWraper GetChatMsg(int Index) const
	{
		if(Index<0 || Index>=(int)m_ChatMsg.size())
		{
			assert(false);
			return ChatInfoWraper();
		}
		return m_ChatMsg[Index];
	}
	void SetChatMsg( const vector<ChatInfoWraper>& v )
	{
		m_ChatMsg=v;
	}
	void ClearChatMsg( )
	{
		m_ChatMsg.clear();
	}
	void SetChatMsg( int Index, const ChatInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ChatMsg.size())
		{
			assert(false);
			return;
		}
		m_ChatMsg[Index] = v;
	}
	void AddChatMsg( const ChatInfoWraper& v )
	{
		m_ChatMsg.push_back(v);
	}

};
//ChatEventMsg封装类
class ChatEventMsgWraper
{
public:
	//构造函数
	ChatEventMsgWraper()
	{
		
		m_StringUIConfigId = -1;

	}
	//赋值构造函数
	ChatEventMsgWraper(const ChatEventMsg& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatEventMsg& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatEventMsg ToPB() const
	{
		ChatEventMsg v;
		v.set_stringuiconfigid( m_StringUIConfigId );
		v.mutable_params()->Reserve(m_Params.size());
		for (int i=0; i<(int)m_Params.size(); i++)
		{
			v.add_params( m_Params[i]);
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
		ChatEventMsg pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatEventMsg& v)
	{
		m_StringUIConfigId = v.stringuiconfigid();
		m_Params.clear();
		m_Params.reserve(v.params_size());
		for( int i=0; i<v.params_size(); i++)
			m_Params.push_back(v.params(i));

	}

private:
	//StringUIConfigId
	INT32 m_StringUIConfigId;
public:
	void SetStringUIConfigId( INT32 v)
	{
		m_StringUIConfigId=v;
	}
	INT32 GetStringUIConfigId()
	{
		return m_StringUIConfigId;
	}
	INT32 GetStringUIConfigId() const
	{
		return m_StringUIConfigId;
	}
private:
	//Params
	vector<string> m_Params;
public:
	int SizeParams()
	{
		return m_Params.size();
	}
	const vector<string>& GetParams() const
	{
		return m_Params;
	}
	string GetParams(int Index) const
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return string();
		}
		return m_Params[Index];
	}
	void SetParams( const vector<string>& v )
	{
		m_Params=v;
	}
	void ClearParams( )
	{
		m_Params.clear();
	}
	void SetParams( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_Params.size())
		{
			assert(false);
			return;
		}
		m_Params[Index] = v;
	}
	void AddParams( const string& v )
	{
		m_Params.push_back(v);
	}

};
//节日boss 奖励封装类
class BossAwardWraper
{
public:
	//构造函数
	BossAwardWraper()
	{
		
		m_Type = -1;
		m_ItemId = -1;
		m_ItemCount = -1;

	}
	//赋值构造函数
	BossAwardWraper(const BossAward& v){ Init(v); }
	//等号重载函数
	void operator = (const BossAward& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BossAward ToPB() const
	{
		BossAward v;
		v.set_type( m_Type );
		v.set_itemid( m_ItemId );
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
		BossAward pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BossAward& v)
	{
		m_Type = v.type();
		m_ItemId = v.itemid();
		m_ItemCount = v.itemcount();

	}

private:
	//类型 [1 个人贡献 2 最后一击]
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//物品id
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
private:
	//物品个数
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
//OnlineUserInfo封装类
class OnlineUserInfoWraper
{
public:
	//构造函数
	OnlineUserInfoWraper()
	{
		
		m_RoleId = 0;
		m_Level = -1;
		m_Location = CharacterLocationWraper();
		m_Guildguid = 0;
		m_PlayerMatchData = PlayerMatchDataWraper();
		m_RoleName = "";
		m_ConfigID = -1;
		m_TreasureCount = -1;
		m_TreasureLevel = -1;
		m_PetConfigID = -1;
		m_PetLevel = -1;
		m_PvP3v3WinCount = -1;
		m_PvP5v5WinCount = -1;
		m_Roam_zone = -1;
		m_Account = "";
		m_ProfessionId = -1;

	}
	//赋值构造函数
	OnlineUserInfoWraper(const OnlineUserInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const OnlineUserInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OnlineUserInfo ToPB() const
	{
		OnlineUserInfo v;
		v.set_roleid( m_RoleId );
		v.set_level( m_Level );
		*v.mutable_location()= m_Location.ToPB();
		v.set_guildguid( m_Guildguid );
		*v.mutable_playermatchdata()= m_PlayerMatchData.ToPB();
		v.set_rolename( m_RoleName );
		v.set_configid( m_ConfigID );
		v.set_treasurecount( m_TreasureCount );
		v.set_treasurelevel( m_TreasureLevel );
		v.set_petconfigid( m_PetConfigID );
		v.set_petlevel( m_PetLevel );
		v.set_pvp3v3wincount( m_PvP3v3WinCount );
		v.set_pvp5v5wincount( m_PvP5v5WinCount );
		v.set_roam_zone( m_Roam_zone );
		v.set_account( m_Account );
		v.set_professionid( m_ProfessionId );
		v.mutable_pvpbattleinfolist()->Reserve(m_PvPBattleInfoList.size());
		for (int i=0; i<(int)m_PvPBattleInfoList.size(); i++)
		{
			*v.add_pvpbattleinfolist() = m_PvPBattleInfoList[i].ToPB();
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
		OnlineUserInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const OnlineUserInfo& v)
	{
		m_RoleId = v.roleid();
		m_Level = v.level();
		m_Location = v.location();
		m_Guildguid = v.guildguid();
		m_PlayerMatchData = v.playermatchdata();
		m_RoleName = v.rolename();
		m_ConfigID = v.configid();
		m_TreasureCount = v.treasurecount();
		m_TreasureLevel = v.treasurelevel();
		m_PetConfigID = v.petconfigid();
		m_PetLevel = v.petlevel();
		m_PvP3v3WinCount = v.pvp3v3wincount();
		m_PvP5v5WinCount = v.pvp5v5wincount();
		m_Roam_zone = v.roam_zone();
		m_Account = v.account();
		m_ProfessionId = v.professionid();
		m_PvPBattleInfoList.clear();
		m_PvPBattleInfoList.reserve(v.pvpbattleinfolist_size());
		for( int i=0; i<v.pvpbattleinfolist_size(); i++)
			m_PvPBattleInfoList.push_back(v.pvpbattleinfolist(i));

	}

private:
	//RoleId
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
	//level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//Location
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}
private:
	//公会ID
	uint64_t m_Guildguid;
public:
	void SetGuildguid( uint64_t v)
	{
		m_Guildguid=v;
	}
	uint64_t GetGuildguid()
	{
		return m_Guildguid;
	}
	uint64_t GetGuildguid() const
	{
		return m_Guildguid;
	}
private:
	//玩家匹配信息
	PlayerMatchDataWraper m_PlayerMatchData;
public:
	void SetPlayerMatchData( const PlayerMatchDataWraper& v)
	{
		m_PlayerMatchData=v;
	}
	PlayerMatchDataWraper GetPlayerMatchData()
	{
		return m_PlayerMatchData;
	}
	PlayerMatchDataWraper GetPlayerMatchData() const
	{
		return m_PlayerMatchData;
	}
private:
	//角色名
	string m_RoleName;
public:
	void SetRoleName( const string& v)
	{
		m_RoleName=v;
	}
	string GetRoleName()
	{
		return m_RoleName;
	}
	string GetRoleName() const
	{
		return m_RoleName;
	}
private:
	//角色ID
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
	}
private:
	//珍宝阁
	INT32 m_TreasureCount;
public:
	void SetTreasureCount( INT32 v)
	{
		m_TreasureCount=v;
	}
	INT32 GetTreasureCount()
	{
		return m_TreasureCount;
	}
	INT32 GetTreasureCount() const
	{
		return m_TreasureCount;
	}
private:
	//珍宝阁等级
	INT32 m_TreasureLevel;
public:
	void SetTreasureLevel( INT32 v)
	{
		m_TreasureLevel=v;
	}
	INT32 GetTreasureLevel()
	{
		return m_TreasureLevel;
	}
	INT32 GetTreasureLevel() const
	{
		return m_TreasureLevel;
	}
private:
	//宠物id
	INT32 m_PetConfigID;
public:
	void SetPetConfigID( INT32 v)
	{
		m_PetConfigID=v;
	}
	INT32 GetPetConfigID()
	{
		return m_PetConfigID;
	}
	INT32 GetPetConfigID() const
	{
		return m_PetConfigID;
	}
private:
	//宠物等级
	INT32 m_PetLevel;
public:
	void SetPetLevel( INT32 v)
	{
		m_PetLevel=v;
	}
	INT32 GetPetLevel()
	{
		return m_PetLevel;
	}
	INT32 GetPetLevel() const
	{
		return m_PetLevel;
	}
private:
	//竞技场胜场数
	INT32 m_PvP3v3WinCount;
public:
	void SetPvP3v3WinCount( INT32 v)
	{
		m_PvP3v3WinCount=v;
	}
	INT32 GetPvP3v3WinCount()
	{
		return m_PvP3v3WinCount;
	}
	INT32 GetPvP3v3WinCount() const
	{
		return m_PvP3v3WinCount;
	}
private:
	//5V5胜利次数
	INT32 m_PvP5v5WinCount;
public:
	void SetPvP5v5WinCount( INT32 v)
	{
		m_PvP5v5WinCount=v;
	}
	INT32 GetPvP5v5WinCount()
	{
		return m_PvP5v5WinCount;
	}
	INT32 GetPvP5v5WinCount() const
	{
		return m_PvP5v5WinCount;
	}
private:
	//跨服zoneid
	INT32 m_Roam_zone;
public:
	void SetRoam_zone( INT32 v)
	{
		m_Roam_zone=v;
	}
	INT32 GetRoam_zone()
	{
		return m_Roam_zone;
	}
	INT32 GetRoam_zone() const
	{
		return m_Roam_zone;
	}
private:
	//账号
	string m_Account;
public:
	void SetAccount( const string& v)
	{
		m_Account=v;
	}
	string GetAccount()
	{
		return m_Account;
	}
	string GetAccount() const
	{
		return m_Account;
	}
private:
	//专精ID
	INT32 m_ProfessionId;
public:
	void SetProfessionId( INT32 v)
	{
		m_ProfessionId=v;
	}
	INT32 GetProfessionId()
	{
		return m_ProfessionId;
	}
	INT32 GetProfessionId() const
	{
		return m_ProfessionId;
	}
private:
	//PVP信息
	vector<PvpBattleInfoWraper> m_PvPBattleInfoList;
public:
	int SizePvPBattleInfoList()
	{
		return m_PvPBattleInfoList.size();
	}
	const vector<PvpBattleInfoWraper>& GetPvPBattleInfoList() const
	{
		return m_PvPBattleInfoList;
	}
	PvpBattleInfoWraper GetPvPBattleInfoList(int Index) const
	{
		if(Index<0 || Index>=(int)m_PvPBattleInfoList.size())
		{
			assert(false);
			return PvpBattleInfoWraper();
		}
		return m_PvPBattleInfoList[Index];
	}
	void SetPvPBattleInfoList( const vector<PvpBattleInfoWraper>& v )
	{
		m_PvPBattleInfoList=v;
	}
	void ClearPvPBattleInfoList( )
	{
		m_PvPBattleInfoList.clear();
	}
	void SetPvPBattleInfoList( int Index, const PvpBattleInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_PvPBattleInfoList.size())
		{
			assert(false);
			return;
		}
		m_PvPBattleInfoList[Index] = v;
	}
	void AddPvPBattleInfoList( const PvpBattleInfoWraper& v )
	{
		m_PvPBattleInfoList.push_back(v);
	}

};
//角色信息封装类
class CharacterInfoWraper
{
public:
	//构造函数
	CharacterInfoWraper()
	{
		
		m_RoleId = 0;
		m_Nickname = "";
		m_ConfigId = -1;
		m_Hp = -1;
		m_HpMax = -1;
		m_Level = -1;
		m_TreasureEquiped = TreasureEquipedIDWraper();
		m_PinchData = PinchFaceDataWraper();

	}
	//赋值构造函数
	CharacterInfoWraper(const CharacterInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const CharacterInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CharacterInfo ToPB() const
	{
		CharacterInfo v;
		v.set_roleid( m_RoleId );
		v.set_nickname( m_Nickname );
		v.set_configid( m_ConfigId );
		v.set_hp( m_Hp );
		v.set_hpmax( m_HpMax );
		v.set_level( m_Level );
		*v.mutable_treasureequiped()= m_TreasureEquiped.ToPB();
		*v.mutable_pinchdata()= m_PinchData.ToPB();

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
		CharacterInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CharacterInfo& v)
	{
		m_RoleId = v.roleid();
		m_Nickname = v.nickname();
		m_ConfigId = v.configid();
		m_Hp = v.hp();
		m_HpMax = v.hpmax();
		m_Level = v.level();
		m_TreasureEquiped = v.treasureequiped();
		m_PinchData = v.pinchdata();

	}

private:
	//roleID
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
private:
	//血量
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//血量上限
	INT32 m_HpMax;
public:
	void SetHpMax( INT32 v)
	{
		m_HpMax=v;
	}
	INT32 GetHpMax()
	{
		return m_HpMax;
	}
	INT32 GetHpMax() const
	{
		return m_HpMax;
	}
private:
	//Level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//穿戴的时装
	TreasureEquipedIDWraper m_TreasureEquiped;
public:
	void SetTreasureEquiped( const TreasureEquipedIDWraper& v)
	{
		m_TreasureEquiped=v;
	}
	TreasureEquipedIDWraper GetTreasureEquiped()
	{
		return m_TreasureEquiped;
	}
	TreasureEquipedIDWraper GetTreasureEquiped() const
	{
		return m_TreasureEquiped;
	}
private:
	//捏脸
	PinchFaceDataWraper m_PinchData;
public:
	void SetPinchData( const PinchFaceDataWraper& v)
	{
		m_PinchData=v;
	}
	PinchFaceDataWraper GetPinchData()
	{
		return m_PinchData;
	}
	PinchFaceDataWraper GetPinchData() const
	{
		return m_PinchData;
	}

};
//活动提醒通知封装类
class ActivityNoticeWraper
{
public:
	//构造函数
	ActivityNoticeWraper()
	{
		
		m_ActId = -1;
		m_Begin_time = -1;
		m_End_time = -1;
		m_Status = -1;

	}
	//赋值构造函数
	ActivityNoticeWraper(const ActivityNotice& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityNotice& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityNotice ToPB() const
	{
		ActivityNotice v;
		v.set_actid( m_ActId );
		v.set_begin_time( m_Begin_time );
		v.set_end_time( m_End_time );
		v.set_status( m_Status );

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
		ActivityNotice pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ActivityNotice& v)
	{
		m_ActId = v.actid();
		m_Begin_time = v.begin_time();
		m_End_time = v.end_time();
		m_Status = v.status();

	}

private:
	//活动id
	INT32 m_ActId;
public:
	void SetActId( INT32 v)
	{
		m_ActId=v;
	}
	INT32 GetActId()
	{
		return m_ActId;
	}
	INT32 GetActId() const
	{
		return m_ActId;
	}
private:
	//开启时间
	INT32 m_Begin_time;
public:
	void SetBegin_time( INT32 v)
	{
		m_Begin_time=v;
	}
	INT32 GetBegin_time()
	{
		return m_Begin_time;
	}
	INT32 GetBegin_time() const
	{
		return m_Begin_time;
	}
private:
	//结束时间
	INT32 m_End_time;
public:
	void SetEnd_time( INT32 v)
	{
		m_End_time=v;
	}
	INT32 GetEnd_time()
	{
		return m_End_time;
	}
	INT32 GetEnd_time() const
	{
		return m_End_time;
	}
private:
	//状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}

};
//技能自定义数据封装类
class CustomSkiDataWraper
{
public:
	//构造函数
	CustomSkiDataWraper()
	{
		
		m_Key = "";
		m_KeyType = -1;
		m_IntV = 0;
		m_BoolV = false;

	}
	//赋值构造函数
	CustomSkiDataWraper(const CustomSkiData& v){ Init(v); }
	//等号重载函数
	void operator = (const CustomSkiData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	CustomSkiData ToPB() const
	{
		CustomSkiData v;
		v.set_key( m_Key );
		v.set_keytype( m_KeyType );
		v.set_intv( m_IntV );
		v.set_boolv( m_BoolV );

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
		CustomSkiData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const CustomSkiData& v)
	{
		m_Key = v.key();
		m_KeyType = v.keytype();
		m_IntV = v.intv();
		m_BoolV = v.boolv();

	}

private:
	//key
	string m_Key;
public:
	void SetKey( const string& v)
	{
		m_Key=v;
	}
	string GetKey()
	{
		return m_Key;
	}
	string GetKey() const
	{
		return m_Key;
	}
private:
	//type
	INT32 m_KeyType;
public:
	void SetKeyType( INT32 v)
	{
		m_KeyType=v;
	}
	INT32 GetKeyType()
	{
		return m_KeyType;
	}
	INT32 GetKeyType() const
	{
		return m_KeyType;
	}
private:
	//int
	INT32 m_IntV;
public:
	void SetIntV( INT32 v)
	{
		m_IntV=v;
	}
	INT32 GetIntV()
	{
		return m_IntV;
	}
	INT32 GetIntV() const
	{
		return m_IntV;
	}
private:
	//bool
	bool m_BoolV;
public:
	void SetBoolV( bool v)
	{
		m_BoolV=v;
	}
	bool GetBoolV()
	{
		return m_BoolV;
	}
	bool GetBoolV() const
	{
		return m_BoolV;
	}

};
//ChatChannelData封装类
class ChatChannelDataWraper
{
public:
	//构造函数
	ChatChannelDataWraper()
	{
		
		m_Chat_channel = -1;

	}
	//赋值构造函数
	ChatChannelDataWraper(const ChatChannelData& v){ Init(v); }
	//等号重载函数
	void operator = (const ChatChannelData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ChatChannelData ToPB() const
	{
		ChatChannelData v;
		v.set_chat_channel( m_Chat_channel );
		v.mutable_chat_infos()->Reserve(m_Chat_infos.size());
		for (int i=0; i<(int)m_Chat_infos.size(); i++)
		{
			*v.add_chat_infos() = m_Chat_infos[i].ToPB();
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
		ChatChannelData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ChatChannelData& v)
	{
		m_Chat_channel = v.chat_channel();
		m_Chat_infos.clear();
		m_Chat_infos.reserve(v.chat_infos_size());
		for( int i=0; i<v.chat_infos_size(); i++)
			m_Chat_infos.push_back(v.chat_infos(i));

	}

private:
	//聊天频道
	INT32 m_Chat_channel;
public:
	void SetChat_channel( INT32 v)
	{
		m_Chat_channel=v;
	}
	INT32 GetChat_channel()
	{
		return m_Chat_channel;
	}
	INT32 GetChat_channel() const
	{
		return m_Chat_channel;
	}
private:
	//聊天消息列表
	vector<ChatInfoWraper> m_Chat_infos;
public:
	int SizeChat_infos()
	{
		return m_Chat_infos.size();
	}
	const vector<ChatInfoWraper>& GetChat_infos() const
	{
		return m_Chat_infos;
	}
	ChatInfoWraper GetChat_infos(int Index) const
	{
		if(Index<0 || Index>=(int)m_Chat_infos.size())
		{
			assert(false);
			return ChatInfoWraper();
		}
		return m_Chat_infos[Index];
	}
	void SetChat_infos( const vector<ChatInfoWraper>& v )
	{
		m_Chat_infos=v;
	}
	void ClearChat_infos( )
	{
		m_Chat_infos.clear();
	}
	void SetChat_infos( int Index, const ChatInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_Chat_infos.size())
		{
			assert(false);
			return;
		}
		m_Chat_infos[Index] = v;
	}
	void AddChat_infos( const ChatInfoWraper& v )
	{
		m_Chat_infos.push_back(v);
	}

};
//全服目标奖励封装类
class ObjectiveAwardWraper
{
public:
	//构造函数
	ObjectiveAwardWraper()
	{
		
		m_Id = -1;
		m_State = -1;
		m_Type = -1;
		m_NeedTime = -1;

	}
	//赋值构造函数
	ObjectiveAwardWraper(const ObjectiveAward& v){ Init(v); }
	//等号重载函数
	void operator = (const ObjectiveAward& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ObjectiveAward ToPB() const
	{
		ObjectiveAward v;
		v.set_id( m_Id );
		v.set_state( m_State );
		v.mutable_itemid()->Reserve(m_ItemId.size());
		for (int i=0; i<(int)m_ItemId.size(); i++)
		{
			v.add_itemid(m_ItemId[i]);
		}
		v.set_type( m_Type );
		v.set_needtime( m_NeedTime );
		v.mutable_itemnum()->Reserve(m_ItemNum.size());
		for (int i=0; i<(int)m_ItemNum.size(); i++)
		{
			v.add_itemnum(m_ItemNum[i]);
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
		ObjectiveAward pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ObjectiveAward& v)
	{
		m_Id = v.id();
		m_State = v.state();
		m_ItemId.clear();
		m_ItemId.reserve(v.itemid_size());
		for( int i=0; i<v.itemid_size(); i++)
			m_ItemId.push_back(v.itemid(i));
		m_Type = v.type();
		m_NeedTime = v.needtime();
		m_ItemNum.clear();
		m_ItemNum.reserve(v.itemnum_size());
		for( int i=0; i<v.itemnum_size(); i++)
			m_ItemNum.push_back(v.itemnum(i));

	}

private:
	//ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//状态
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}
private:
	//物品
	vector<INT32> m_ItemId;
public:
	int SizeItemId()
	{
		return m_ItemId.size();
	}
	const vector<INT32>& GetItemId() const
	{
		return m_ItemId;
	}
	INT32 GetItemId(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemId.size())
		{
			assert(false);
			return INT32();
		}
		return m_ItemId[Index];
	}
	void SetItemId( const vector<INT32>& v )
	{
		m_ItemId=v;
	}
	void ClearItemId( )
	{
		m_ItemId.clear();
	}
	void SetItemId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ItemId.size())
		{
			assert(false);
			return;
		}
		m_ItemId[Index] = v;
	}
	void AddItemId( INT32 v = -1 )
	{
		m_ItemId.push_back(v);
	}
private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//达成次数
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
	//物品个数
	vector<INT32> m_ItemNum;
public:
	int SizeItemNum()
	{
		return m_ItemNum.size();
	}
	const vector<INT32>& GetItemNum() const
	{
		return m_ItemNum;
	}
	INT32 GetItemNum(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemNum.size())
		{
			assert(false);
			return INT32();
		}
		return m_ItemNum[Index];
	}
	void SetItemNum( const vector<INT32>& v )
	{
		m_ItemNum=v;
	}
	void ClearItemNum( )
	{
		m_ItemNum.clear();
	}
	void SetItemNum( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_ItemNum.size())
		{
			assert(false);
			return;
		}
		m_ItemNum[Index] = v;
	}
	void AddItemNum( INT32 v = -1 )
	{
		m_ItemNum.push_back(v);
	}

};
//道具简易数据封装类
class ItemSimpleDataWraper
{
public:
	//构造函数
	ItemSimpleDataWraper()
	{
		
		m_ConfID = -1;
		m_Count = -1;

	}
	//赋值构造函数
	ItemSimpleDataWraper(const ItemSimpleData& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemSimpleData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemSimpleData ToPB() const
	{
		ItemSimpleData v;
		v.set_confid( m_ConfID );
		v.set_count( m_Count );

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
		ItemSimpleData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemSimpleData& v)
	{
		m_ConfID = v.confid();
		m_Count = v.count();

	}

private:
	//道具ConfID
	INT32 m_ConfID;
public:
	void SetConfID( INT32 v)
	{
		m_ConfID=v;
	}
	INT32 GetConfID()
	{
		return m_ConfID;
	}
	INT32 GetConfID() const
	{
		return m_ConfID;
	}
private:
	//数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}

};
//召唤物数据封装类
class SummonDataWraper
{
public:
	//构造函数
	SummonDataWraper()
	{
		
		m_SummonId = -1;
		m_ExpiredTime = -1;
		m_Index = -1;

	}
	//赋值构造函数
	SummonDataWraper(const SummonData& v){ Init(v); }
	//等号重载函数
	void operator = (const SummonData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SummonData ToPB() const
	{
		SummonData v;
		v.set_summonid( m_SummonId );
		v.set_expiredtime( m_ExpiredTime );
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
		SummonData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SummonData& v)
	{
		m_SummonId = v.summonid();
		m_ExpiredTime = v.expiredtime();
		m_Index = v.index();

	}

private:
	//召唤表id
	INT32 m_SummonId;
public:
	void SetSummonId( INT32 v)
	{
		m_SummonId=v;
	}
	INT32 GetSummonId()
	{
		return m_SummonId;
	}
	INT32 GetSummonId() const
	{
		return m_SummonId;
	}
private:
	//到期时间
	int64_t m_ExpiredTime;
public:
	void SetExpiredTime( int64_t v)
	{
		m_ExpiredTime=v;
	}
	int64_t GetExpiredTime()
	{
		return m_ExpiredTime;
	}
	int64_t GetExpiredTime() const
	{
		return m_ExpiredTime;
	}
private:
	//召唤索引
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
//分解列表封装类
class ItemResolveDataListWraper
{
public:
	//构造函数
	ItemResolveDataListWraper()
	{
		

	}
	//赋值构造函数
	ItemResolveDataListWraper(const ItemResolveDataList& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemResolveDataList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemResolveDataList ToPB() const
	{
		ItemResolveDataList v;
		v.mutable_resolvelist()->Reserve(m_ResolveList.size());
		for (int i=0; i<(int)m_ResolveList.size(); i++)
		{
			*v.add_resolvelist() = m_ResolveList[i].ToPB();
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
		ItemResolveDataList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemResolveDataList& v)
	{
		m_ResolveList.clear();
		m_ResolveList.reserve(v.resolvelist_size());
		for( int i=0; i<v.resolvelist_size(); i++)
			m_ResolveList.push_back(v.resolvelist(i));

	}

private:
	//分解数据列表
	vector<ResolveUnitWraper> m_ResolveList;
public:
	int SizeResolveList()
	{
		return m_ResolveList.size();
	}
	const vector<ResolveUnitWraper>& GetResolveList() const
	{
		return m_ResolveList;
	}
	ResolveUnitWraper GetResolveList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ResolveList.size())
		{
			assert(false);
			return ResolveUnitWraper();
		}
		return m_ResolveList[Index];
	}
	void SetResolveList( const vector<ResolveUnitWraper>& v )
	{
		m_ResolveList=v;
	}
	void ClearResolveList( )
	{
		m_ResolveList.clear();
	}
	void SetResolveList( int Index, const ResolveUnitWraper& v )
	{
		if(Index<0 || Index>=(int)m_ResolveList.size())
		{
			assert(false);
			return;
		}
		m_ResolveList[Index] = v;
	}
	void AddResolveList( const ResolveUnitWraper& v )
	{
		m_ResolveList.push_back(v);
	}

};
//世界BOSS得分玩家简要信息封装类
class WorldBossScoreTinyInfoWraper
{
public:
	//构造函数
	WorldBossScoreTinyInfoWraper()
	{
		
		m_Playerguid = 0;
		m_Score = -1;
		m_Damage = 0;
		m_Capacity = 0;

	}
	//赋值构造函数
	WorldBossScoreTinyInfoWraper(const WorldBossScoreTinyInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossScoreTinyInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossScoreTinyInfo ToPB() const
	{
		WorldBossScoreTinyInfo v;
		v.set_playerguid( m_Playerguid );
		v.set_score( m_Score );
		v.set_damage( m_Damage );
		v.set_capacity( m_Capacity );

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
		WorldBossScoreTinyInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossScoreTinyInfo& v)
	{
		m_Playerguid = v.playerguid();
		m_Score = v.score();
		m_Damage = v.damage();
		m_Capacity = v.capacity();

	}

private:
	//playerguid
	uint64_t m_Playerguid;
public:
	void SetPlayerguid( uint64_t v)
	{
		m_Playerguid=v;
	}
	uint64_t GetPlayerguid()
	{
		return m_Playerguid;
	}
	uint64_t GetPlayerguid() const
	{
		return m_Playerguid;
	}
private:
	//score
	INT32 m_Score;
public:
	void SetScore( INT32 v)
	{
		m_Score=v;
	}
	INT32 GetScore()
	{
		return m_Score;
	}
	INT32 GetScore() const
	{
		return m_Score;
	}
private:
	//damage(用于最后一击)
	INT32 m_Damage;
public:
	void SetDamage( INT32 v)
	{
		m_Damage=v;
	}
	INT32 GetDamage()
	{
		return m_Damage;
	}
	INT32 GetDamage() const
	{
		return m_Damage;
	}
private:
	//战力
	INT32 m_Capacity;
public:
	void SetCapacity( INT32 v)
	{
		m_Capacity=v;
	}
	INT32 GetCapacity()
	{
		return m_Capacity;
	}
	INT32 GetCapacity() const
	{
		return m_Capacity;
	}

};
//KeyValue结构封装类
class KeyValueWraper
{
public:
	//构造函数
	KeyValueWraper()
	{
		
		m_KeyId = -1;
		m_KeyValue = -1;

	}
	//赋值构造函数
	KeyValueWraper(const KeyValue& v){ Init(v); }
	//等号重载函数
	void operator = (const KeyValue& v){ Init(v); }
 	//转化成Protobuffer类型函数
	KeyValue ToPB() const
	{
		KeyValue v;
		v.set_keyid( m_KeyId );
		v.set_keyvalue( m_KeyValue );

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
		KeyValue pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const KeyValue& v)
	{
		m_KeyId = v.keyid();
		m_KeyValue = v.keyvalue();

	}

private:
	//id
	INT32 m_KeyId;
public:
	void SetKeyId( INT32 v)
	{
		m_KeyId=v;
	}
	INT32 GetKeyId()
	{
		return m_KeyId;
	}
	INT32 GetKeyId() const
	{
		return m_KeyId;
	}
private:
	//value
	INT32 m_KeyValue;
public:
	void SetKeyValue( INT32 v)
	{
		m_KeyValue=v;
	}
	INT32 GetKeyValue()
	{
		return m_KeyValue;
	}
	INT32 GetKeyValue() const
	{
		return m_KeyValue;
	}

};
//装备共鸣数据封装类
class EquipResonanceDataWraper
{
public:
	//构造函数
	EquipResonanceDataWraper()
	{
		

	}
	//赋值构造函数
	EquipResonanceDataWraper(const EquipResonanceData& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipResonanceData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipResonanceData ToPB() const
	{
		EquipResonanceData v;
		v.mutable_resonancelist()->Reserve(m_ResonanceList.size());
		for (int i=0; i<(int)m_ResonanceList.size(); i++)
		{
			*v.add_resonancelist() = m_ResonanceList[i].ToPB();
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
		EquipResonanceData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipResonanceData& v)
	{
		m_ResonanceList.clear();
		m_ResonanceList.reserve(v.resonancelist_size());
		for( int i=0; i<v.resonancelist_size(); i++)
			m_ResonanceList.push_back(v.resonancelist(i));

	}

private:
	//数据列表
	vector<EquipResonanceInfoWraper> m_ResonanceList;
public:
	int SizeResonanceList()
	{
		return m_ResonanceList.size();
	}
	const vector<EquipResonanceInfoWraper>& GetResonanceList() const
	{
		return m_ResonanceList;
	}
	EquipResonanceInfoWraper GetResonanceList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ResonanceList.size())
		{
			assert(false);
			return EquipResonanceInfoWraper();
		}
		return m_ResonanceList[Index];
	}
	void SetResonanceList( const vector<EquipResonanceInfoWraper>& v )
	{
		m_ResonanceList=v;
	}
	void ClearResonanceList( )
	{
		m_ResonanceList.clear();
	}
	void SetResonanceList( int Index, const EquipResonanceInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ResonanceList.size())
		{
			assert(false);
			return;
		}
		m_ResonanceList[Index] = v;
	}
	void AddResonanceList( const EquipResonanceInfoWraper& v )
	{
		m_ResonanceList.push_back(v);
	}

};
//机器人封装类
class RobotWraper
{
public:
	//构造函数
	RobotWraper()
	{
		
		m_ConfigID = -1;
		m_Name = "";
		m_Level = -1;
		m_Guid = 0;
		m_Occupation = -1;

	}
	//赋值构造函数
	RobotWraper(const Robot& v){ Init(v); }
	//等号重载函数
	void operator = (const Robot& v){ Init(v); }
 	//转化成Protobuffer类型函数
	Robot ToPB() const
	{
		Robot v;
		v.set_configid( m_ConfigID );
		v.set_name( m_Name );
		v.set_level( m_Level );
		v.set_guid( m_Guid );
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
		Robot pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const Robot& v)
	{
		m_ConfigID = v.configid();
		m_Name = v.name();
		m_Level = v.level();
		m_Guid = v.guid();
		m_Occupation = v.occupation();

	}

private:
	//配置id
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
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
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//roleid
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
	//MT TT DPS
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
//声望数据封装类
class ReputationInfoPBWraper
{
public:
	//构造函数
	ReputationInfoPBWraper()
	{
		
		m_ID = -1;
		m_Value = -1;

	}
	//赋值构造函数
	ReputationInfoPBWraper(const ReputationInfoPB& v){ Init(v); }
	//等号重载函数
	void operator = (const ReputationInfoPB& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ReputationInfoPB ToPB() const
	{
		ReputationInfoPB v;
		v.set_id( m_ID );
		v.set_value( m_Value );

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
		ReputationInfoPB pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ReputationInfoPB& v)
	{
		m_ID = v.id();
		m_Value = v.value();

	}

private:
	//声望id
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//声望数值
	int64_t m_Value;
public:
	void SetValue( int64_t v)
	{
		m_Value=v;
	}
	int64_t GetValue()
	{
		return m_Value;
	}
	int64_t GetValue() const
	{
		return m_Value;
	}

};
//技能数据封装类
class SkillDataWraper
{
public:
	//构造函数
	SkillDataWraper()
	{
		
		m_CurUseContainer = -1;

	}
	//赋值构造函数
	SkillDataWraper(const SkillData& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillData ToPB() const
	{
		SkillData v;
		v.mutable_skillcontainerlist()->Reserve(m_SkillContainerList.size());
		for (int i=0; i<(int)m_SkillContainerList.size(); i++)
		{
			*v.add_skillcontainerlist() = m_SkillContainerList[i].ToPB();
		}
		v.set_curusecontainer( m_CurUseContainer );
		v.mutable_skillslotlevel()->Reserve(m_SkillSlotLevel.size());
		for (int i=0; i<(int)m_SkillSlotLevel.size(); i++)
		{
			v.add_skillslotlevel(m_SkillSlotLevel[i]);
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
		SkillData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillData& v)
	{
		m_SkillContainerList.clear();
		m_SkillContainerList.reserve(v.skillcontainerlist_size());
		for( int i=0; i<v.skillcontainerlist_size(); i++)
			m_SkillContainerList.push_back(v.skillcontainerlist(i));
		m_CurUseContainer = v.curusecontainer();
		m_SkillSlotLevel.clear();
		m_SkillSlotLevel.reserve(v.skillslotlevel_size());
		for( int i=0; i<v.skillslotlevel_size(); i++)
			m_SkillSlotLevel.push_back(v.skillslotlevel(i));

	}

private:
	//技能分类集合
	vector<SkillContainerWraper> m_SkillContainerList;
public:
	int SizeSkillContainerList()
	{
		return m_SkillContainerList.size();
	}
	const vector<SkillContainerWraper>& GetSkillContainerList() const
	{
		return m_SkillContainerList;
	}
	SkillContainerWraper GetSkillContainerList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillContainerList.size())
		{
			assert(false);
			return SkillContainerWraper();
		}
		return m_SkillContainerList[Index];
	}
	void SetSkillContainerList( const vector<SkillContainerWraper>& v )
	{
		m_SkillContainerList=v;
	}
	void ClearSkillContainerList( )
	{
		m_SkillContainerList.clear();
	}
	void SetSkillContainerList( int Index, const SkillContainerWraper& v )
	{
		if(Index<0 || Index>=(int)m_SkillContainerList.size())
		{
			assert(false);
			return;
		}
		m_SkillContainerList[Index] = v;
	}
	void AddSkillContainerList( const SkillContainerWraper& v )
	{
		m_SkillContainerList.push_back(v);
	}
private:
	//当前使用的技能专精
	INT32 m_CurUseContainer;
public:
	void SetCurUseContainer( INT32 v)
	{
		m_CurUseContainer=v;
	}
	INT32 GetCurUseContainer()
	{
		return m_CurUseContainer;
	}
	INT32 GetCurUseContainer() const
	{
		return m_CurUseContainer;
	}
private:
	//技能栏位等级
	vector<INT32> m_SkillSlotLevel;
public:
	int SizeSkillSlotLevel()
	{
		return m_SkillSlotLevel.size();
	}
	const vector<INT32>& GetSkillSlotLevel() const
	{
		return m_SkillSlotLevel;
	}
	INT32 GetSkillSlotLevel(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillSlotLevel.size())
		{
			assert(false);
			return INT32();
		}
		return m_SkillSlotLevel[Index];
	}
	void SetSkillSlotLevel( const vector<INT32>& v )
	{
		m_SkillSlotLevel=v;
	}
	void ClearSkillSlotLevel( )
	{
		m_SkillSlotLevel.clear();
	}
	void SetSkillSlotLevel( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SkillSlotLevel.size())
		{
			assert(false);
			return;
		}
		m_SkillSlotLevel[Index] = v;
	}
	void AddSkillSlotLevel( INT32 v = 0 )
	{
		m_SkillSlotLevel.push_back(v);
	}

};
//坐骑信息封装类
class MountDataWraper
{
public:
	//构造函数
	MountDataWraper()
	{
		
		m_MountId = -1;
		m_MountState = -1;
		m_MountLevelData = MountLevelDataWraper();
		m_MountIntimateData = MountIntimateDataWraper();
		m_BattleScore = -1;
		m_MountSkinId = -1;

	}
	//赋值构造函数
	MountDataWraper(const MountData& v){ Init(v); }
	//等号重载函数
	void operator = (const MountData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MountData ToPB() const
	{
		MountData v;
		v.set_mountid( m_MountId );
		v.set_mountstate( m_MountState );
		*v.mutable_mountleveldata()= m_MountLevelData.ToPB();
		*v.mutable_mountintimatedata()= m_MountIntimateData.ToPB();
		v.set_battlescore( m_BattleScore );
		v.set_mountskinid( m_MountSkinId );

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
		MountData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MountData& v)
	{
		m_MountId = v.mountid();
		m_MountState = v.mountstate();
		m_MountLevelData = v.mountleveldata();
		m_MountIntimateData = v.mountintimatedata();
		m_BattleScore = v.battlescore();
		m_MountSkinId = v.mountskinid();

	}

private:
	//坐骑ID
	INT32 m_MountId;
public:
	void SetMountId( INT32 v)
	{
		m_MountId=v;
	}
	INT32 GetMountId()
	{
		return m_MountId;
	}
	INT32 GetMountId() const
	{
		return m_MountId;
	}
private:
	//坐骑状态
	INT32 m_MountState;
public:
	void SetMountState( INT32 v)
	{
		m_MountState=v;
	}
	INT32 GetMountState()
	{
		return m_MountState;
	}
	INT32 GetMountState() const
	{
		return m_MountState;
	}
private:
	//等级数据
	MountLevelDataWraper m_MountLevelData;
public:
	void SetMountLevelData( const MountLevelDataWraper& v)
	{
		m_MountLevelData=v;
	}
	MountLevelDataWraper GetMountLevelData()
	{
		return m_MountLevelData;
	}
	MountLevelDataWraper GetMountLevelData() const
	{
		return m_MountLevelData;
	}
private:
	//请密度数据
	MountIntimateDataWraper m_MountIntimateData;
public:
	void SetMountIntimateData( const MountIntimateDataWraper& v)
	{
		m_MountIntimateData=v;
	}
	MountIntimateDataWraper GetMountIntimateData()
	{
		return m_MountIntimateData;
	}
	MountIntimateDataWraper GetMountIntimateData() const
	{
		return m_MountIntimateData;
	}
private:
	//战力值
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//坐骑皮肤
	INT32 m_MountSkinId;
public:
	void SetMountSkinId( INT32 v)
	{
		m_MountSkinId=v;
	}
	INT32 GetMountSkinId()
	{
		return m_MountSkinId;
	}
	INT32 GetMountSkinId() const
	{
		return m_MountSkinId;
	}

};
//物品分解数据封装类
class ItemAutoOperatorDataWraper
{
public:
	//构造函数
	ItemAutoOperatorDataWraper()
	{
		

	}
	//赋值构造函数
	ItemAutoOperatorDataWraper(const ItemAutoOperatorData& v){ Init(v); }
	//等号重载函数
	void operator = (const ItemAutoOperatorData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ItemAutoOperatorData ToPB() const
	{
		ItemAutoOperatorData v;
		v.mutable_autosaledisassemble()->Reserve(m_AutoSaleDisassemble.size());
		for (int i=0; i<(int)m_AutoSaleDisassemble.size(); i++)
		{
			*v.add_autosaledisassemble() = m_AutoSaleDisassemble[i].ToPB();
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
		ItemAutoOperatorData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ItemAutoOperatorData& v)
	{
		m_AutoSaleDisassemble.clear();
		m_AutoSaleDisassemble.reserve(v.autosaledisassemble_size());
		for( int i=0; i<v.autosaledisassemble_size(); i++)
			m_AutoSaleDisassemble.push_back(v.autosaledisassemble(i));

	}

private:
	//是否一键售卖列表
	vector<ItemResolveDataWraper> m_AutoSaleDisassemble;
public:
	int SizeAutoSaleDisassemble()
	{
		return m_AutoSaleDisassemble.size();
	}
	const vector<ItemResolveDataWraper>& GetAutoSaleDisassemble() const
	{
		return m_AutoSaleDisassemble;
	}
	ItemResolveDataWraper GetAutoSaleDisassemble(int Index) const
	{
		if(Index<0 || Index>=(int)m_AutoSaleDisassemble.size())
		{
			assert(false);
			return ItemResolveDataWraper();
		}
		return m_AutoSaleDisassemble[Index];
	}
	void SetAutoSaleDisassemble( const vector<ItemResolveDataWraper>& v )
	{
		m_AutoSaleDisassemble=v;
	}
	void ClearAutoSaleDisassemble( )
	{
		m_AutoSaleDisassemble.clear();
	}
	void SetAutoSaleDisassemble( int Index, const ItemResolveDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_AutoSaleDisassemble.size())
		{
			assert(false);
			return;
		}
		m_AutoSaleDisassemble[Index] = v;
	}
	void AddAutoSaleDisassemble( const ItemResolveDataWraper& v )
	{
		m_AutoSaleDisassemble.push_back(v);
	}

};
//公会技能封装类
class GuildSkillWraper
{
public:
	//构造函数
	GuildSkillWraper()
	{
		
		m_Id = -1;
		m_GuildSkillLevel = -1;
		m_GuildSkillExp = -1;

	}
	//赋值构造函数
	GuildSkillWraper(const GuildSkill& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildSkill& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildSkill ToPB() const
	{
		GuildSkill v;
		v.set_id( m_Id );
		v.set_guildskilllevel( m_GuildSkillLevel );
		v.set_guildskillexp( m_GuildSkillExp );

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
		GuildSkill pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildSkill& v)
	{
		m_Id = v.id();
		m_GuildSkillLevel = v.guildskilllevel();
		m_GuildSkillExp = v.guildskillexp();

	}

private:
	//id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//技能等级
	INT32 m_GuildSkillLevel;
public:
	void SetGuildSkillLevel( INT32 v)
	{
		m_GuildSkillLevel=v;
	}
	INT32 GetGuildSkillLevel()
	{
		return m_GuildSkillLevel;
	}
	INT32 GetGuildSkillLevel() const
	{
		return m_GuildSkillLevel;
	}
private:
	//技能经验
	INT32 m_GuildSkillExp;
public:
	void SetGuildSkillExp( INT32 v)
	{
		m_GuildSkillExp=v;
	}
	INT32 GetGuildSkillExp()
	{
		return m_GuildSkillExp;
	}
	INT32 GetGuildSkillExp() const
	{
		return m_GuildSkillExp;
	}

};
//排名显示信息封装类
class WorldBossRankInfoWraper
{
public:
	//构造函数
	WorldBossRankInfoWraper()
	{
		
		m_Rank = -1;
		m_Name = "";
		m_Level = -1;
		m_Score = -1;

	}
	//赋值构造函数
	WorldBossRankInfoWraper(const WorldBossRankInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRankInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRankInfo ToPB() const
	{
		WorldBossRankInfo v;
		v.set_rank( m_Rank );
		v.set_name( m_Name );
		v.set_level( m_Level );
		v.set_score( m_Score );

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
		WorldBossRankInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossRankInfo& v)
	{
		m_Rank = v.rank();
		m_Name = v.name();
		m_Level = v.level();
		m_Score = v.score();

	}

private:
	//排名
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
	//玩家名字
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
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//积分
	INT32 m_Score;
public:
	void SetScore( INT32 v)
	{
		m_Score=v;
	}
	INT32 GetScore()
	{
		return m_Score;
	}
	INT32 GetScore() const
	{
		return m_Score;
	}

};
//UI和功能开关数据封装类
class UICategoryDBListWraper
{
public:
	//构造函数
	UICategoryDBListWraper()
	{
		
		m_OpenAll = false;

	}
	//赋值构造函数
	UICategoryDBListWraper(const UICategoryDBList& v){ Init(v); }
	//等号重载函数
	void operator = (const UICategoryDBList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	UICategoryDBList ToPB() const
	{
		UICategoryDBList v;
		v.mutable_data()->Reserve(m_Data.size());
		for (int i=0; i<(int)m_Data.size(); i++)
		{
			*v.add_data() = m_Data[i].ToPB();
		}
		v.set_openall( m_OpenAll );

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
		UICategoryDBList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const UICategoryDBList& v)
	{
		m_Data.clear();
		m_Data.reserve(v.data_size());
		for( int i=0; i<v.data_size(); i++)
			m_Data.push_back(v.data(i));
		m_OpenAll = v.openall();

	}

private:
	//某项UI和功能解锁
	vector<UICategoryDataWraper> m_Data;
public:
	int SizeData()
	{
		return m_Data.size();
	}
	const vector<UICategoryDataWraper>& GetData() const
	{
		return m_Data;
	}
	UICategoryDataWraper GetData(int Index) const
	{
		if(Index<0 || Index>=(int)m_Data.size())
		{
			assert(false);
			return UICategoryDataWraper();
		}
		return m_Data[Index];
	}
	void SetData( const vector<UICategoryDataWraper>& v )
	{
		m_Data=v;
	}
	void ClearData( )
	{
		m_Data.clear();
	}
	void SetData( int Index, const UICategoryDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Data.size())
		{
			assert(false);
			return;
		}
		m_Data[Index] = v;
	}
	void AddData( const UICategoryDataWraper& v )
	{
		m_Data.push_back(v);
	}
private:
	//是否全开放
	bool m_OpenAll;
public:
	void SetOpenAll( bool v)
	{
		m_OpenAll=v;
	}
	bool GetOpenAll()
	{
		return m_OpenAll;
	}
	bool GetOpenAll() const
	{
		return m_OpenAll;
	}

};
//公会货币信息封装类
class GuildCurrencyWraper
{
public:
	//构造函数
	GuildCurrencyWraper()
	{
		
		m_Currencytype = -1;
		m_CurrencyChangeNum = -1;
		m_CurrencyTotalNum = -1;

	}
	//赋值构造函数
	GuildCurrencyWraper(const GuildCurrency& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildCurrency& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildCurrency ToPB() const
	{
		GuildCurrency v;
		v.set_currencytype( m_Currencytype );
		v.set_currencychangenum( m_CurrencyChangeNum );
		v.set_currencytotalnum( m_CurrencyTotalNum );

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
		GuildCurrency pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildCurrency& v)
	{
		m_Currencytype = v.currencytype();
		m_CurrencyChangeNum = v.currencychangenum();
		m_CurrencyTotalNum = v.currencytotalnum();

	}

private:
	//货币类型
	INT32 m_Currencytype;
public:
	void SetCurrencytype( INT32 v)
	{
		m_Currencytype=v;
	}
	INT32 GetCurrencytype()
	{
		return m_Currencytype;
	}
	INT32 GetCurrencytype() const
	{
		return m_Currencytype;
	}
private:
	//货币改变数量
	INT32 m_CurrencyChangeNum;
public:
	void SetCurrencyChangeNum( INT32 v)
	{
		m_CurrencyChangeNum=v;
	}
	INT32 GetCurrencyChangeNum()
	{
		return m_CurrencyChangeNum;
	}
	INT32 GetCurrencyChangeNum() const
	{
		return m_CurrencyChangeNum;
	}
private:
	//货币总数
	INT32 m_CurrencyTotalNum;
public:
	void SetCurrencyTotalNum( INT32 v)
	{
		m_CurrencyTotalNum=v;
	}
	INT32 GetCurrencyTotalNum()
	{
		return m_CurrencyTotalNum;
	}
	INT32 GetCurrencyTotalNum() const
	{
		return m_CurrencyTotalNum;
	}

};
//结算信息封装类
class PvpBattleEndInfoWraper
{
public:
	//构造函数
	PvpBattleEndInfoWraper()
	{
		
		m_WinState = -1;
		m_BeforeRank = -1;
		m_BeforeStar = -1;
		m_AfterRank = -1;
		m_AfterStar = -1;
		m_BattleTime = -1;

	}
	//赋值构造函数
	PvpBattleEndInfoWraper(const PvpBattleEndInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpBattleEndInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpBattleEndInfo ToPB() const
	{
		PvpBattleEndInfo v;
		v.set_winstate( m_WinState );
		v.set_beforerank( m_BeforeRank );
		v.set_beforestar( m_BeforeStar );
		v.set_afterrank( m_AfterRank );
		v.set_afterstar( m_AfterStar );
		v.mutable_rewardlist()->Reserve(m_RewardList.size());
		for (int i=0; i<(int)m_RewardList.size(); i++)
		{
			*v.add_rewardlist() = m_RewardList[i].ToPB();
		}
		v.mutable_leftplayerlist()->Reserve(m_LeftPlayerList.size());
		for (int i=0; i<(int)m_LeftPlayerList.size(); i++)
		{
			*v.add_leftplayerlist() = m_LeftPlayerList[i].ToPB();
		}
		v.mutable_rightplayerlist()->Reserve(m_RightPlayerList.size());
		for (int i=0; i<(int)m_RightPlayerList.size(); i++)
		{
			*v.add_rightplayerlist() = m_RightPlayerList[i].ToPB();
		}
		v.set_battletime( m_BattleTime );

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
		PvpBattleEndInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpBattleEndInfo& v)
	{
		m_WinState = v.winstate();
		m_BeforeRank = v.beforerank();
		m_BeforeStar = v.beforestar();
		m_AfterRank = v.afterrank();
		m_AfterStar = v.afterstar();
		m_RewardList.clear();
		m_RewardList.reserve(v.rewardlist_size());
		for( int i=0; i<v.rewardlist_size(); i++)
			m_RewardList.push_back(v.rewardlist(i));
		m_LeftPlayerList.clear();
		m_LeftPlayerList.reserve(v.leftplayerlist_size());
		for( int i=0; i<v.leftplayerlist_size(); i++)
			m_LeftPlayerList.push_back(v.leftplayerlist(i));
		m_RightPlayerList.clear();
		m_RightPlayerList.reserve(v.rightplayerlist_size());
		for( int i=0; i<v.rightplayerlist_size(); i++)
			m_RightPlayerList.push_back(v.rightplayerlist(i));
		m_BattleTime = v.battletime();

	}

private:
	//输赢
	INT32 m_WinState;
public:
	void SetWinState( INT32 v)
	{
		m_WinState=v;
	}
	INT32 GetWinState()
	{
		return m_WinState;
	}
	INT32 GetWinState() const
	{
		return m_WinState;
	}
private:
	//上一次的段位
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
	//上一次的星级
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
	//当前段位
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
	//当前星级
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
	//左侧玩家列表
	vector<PvpEndPlayerWraper> m_LeftPlayerList;
public:
	int SizeLeftPlayerList()
	{
		return m_LeftPlayerList.size();
	}
	const vector<PvpEndPlayerWraper>& GetLeftPlayerList() const
	{
		return m_LeftPlayerList;
	}
	PvpEndPlayerWraper GetLeftPlayerList(int Index) const
	{
		if(Index<0 || Index>=(int)m_LeftPlayerList.size())
		{
			assert(false);
			return PvpEndPlayerWraper();
		}
		return m_LeftPlayerList[Index];
	}
	void SetLeftPlayerList( const vector<PvpEndPlayerWraper>& v )
	{
		m_LeftPlayerList=v;
	}
	void ClearLeftPlayerList( )
	{
		m_LeftPlayerList.clear();
	}
	void SetLeftPlayerList( int Index, const PvpEndPlayerWraper& v )
	{
		if(Index<0 || Index>=(int)m_LeftPlayerList.size())
		{
			assert(false);
			return;
		}
		m_LeftPlayerList[Index] = v;
	}
	void AddLeftPlayerList( const PvpEndPlayerWraper& v )
	{
		m_LeftPlayerList.push_back(v);
	}
private:
	//右侧玩家列表
	vector<PvpEndPlayerWraper> m_RightPlayerList;
public:
	int SizeRightPlayerList()
	{
		return m_RightPlayerList.size();
	}
	const vector<PvpEndPlayerWraper>& GetRightPlayerList() const
	{
		return m_RightPlayerList;
	}
	PvpEndPlayerWraper GetRightPlayerList(int Index) const
	{
		if(Index<0 || Index>=(int)m_RightPlayerList.size())
		{
			assert(false);
			return PvpEndPlayerWraper();
		}
		return m_RightPlayerList[Index];
	}
	void SetRightPlayerList( const vector<PvpEndPlayerWraper>& v )
	{
		m_RightPlayerList=v;
	}
	void ClearRightPlayerList( )
	{
		m_RightPlayerList.clear();
	}
	void SetRightPlayerList( int Index, const PvpEndPlayerWraper& v )
	{
		if(Index<0 || Index>=(int)m_RightPlayerList.size())
		{
			assert(false);
			return;
		}
		m_RightPlayerList[Index] = v;
	}
	void AddRightPlayerList( const PvpEndPlayerWraper& v )
	{
		m_RightPlayerList.push_back(v);
	}
private:
	//战斗时间
	INT32 m_BattleTime;
public:
	void SetBattleTime( INT32 v)
	{
		m_BattleTime=v;
	}
	INT32 GetBattleTime()
	{
		return m_BattleTime;
	}
	INT32 GetBattleTime() const
	{
		return m_BattleTime;
	}

};
//buff信息封装类
class BuffInfoWraper
{
public:
	//构造函数
	BuffInfoWraper()
	{
		
		m_ObjId = 0;
		m_CasterId = 0;
		m_OpType = -1;
		m_BufId = -1;
		m_RemainTime = -1;
		m_BuffLv = -1;
		m_Sn = -1;
		m_LayerCount = 0;

	}
	//赋值构造函数
	BuffInfoWraper(const BuffInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const BuffInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BuffInfo ToPB() const
	{
		BuffInfo v;
		v.set_objid( m_ObjId );
		v.set_casterid( m_CasterId );
		v.set_optype( m_OpType );
		v.set_bufid( m_BufId );
		v.set_remaintime( m_RemainTime );
		v.set_bufflv( m_BuffLv );
		v.set_sn( m_Sn );
		v.set_layercount( m_LayerCount );

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
		BuffInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const BuffInfo& v)
	{
		m_ObjId = v.objid();
		m_CasterId = v.casterid();
		m_OpType = v.optype();
		m_BufId = v.bufid();
		m_RemainTime = v.remaintime();
		m_BuffLv = v.bufflv();
		m_Sn = v.sn();
		m_LayerCount = v.layercount();

	}

private:
	//持有者ID
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//Buff释放者ID
	uint64_t m_CasterId;
public:
	void SetCasterId( uint64_t v)
	{
		m_CasterId=v;
	}
	uint64_t GetCasterId()
	{
		return m_CasterId;
	}
	uint64_t GetCasterId() const
	{
		return m_CasterId;
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
private:
	//bufid
	INT32 m_BufId;
public:
	void SetBufId( INT32 v)
	{
		m_BufId=v;
	}
	INT32 GetBufId()
	{
		return m_BufId;
	}
	INT32 GetBufId() const
	{
		return m_BufId;
	}
private:
	//剩余时间
	INT32 m_RemainTime;
public:
	void SetRemainTime( INT32 v)
	{
		m_RemainTime=v;
	}
	INT32 GetRemainTime()
	{
		return m_RemainTime;
	}
	INT32 GetRemainTime() const
	{
		return m_RemainTime;
	}
private:
	//buf 等级
	INT32 m_BuffLv;
public:
	void SetBuffLv( INT32 v)
	{
		m_BuffLv=v;
	}
	INT32 GetBuffLv()
	{
		return m_BuffLv;
	}
	INT32 GetBuffLv() const
	{
		return m_BuffLv;
	}
private:
	//buff序列号
	INT32 m_Sn;
public:
	void SetSn( INT32 v)
	{
		m_Sn=v;
	}
	INT32 GetSn()
	{
		return m_Sn;
	}
	INT32 GetSn() const
	{
		return m_Sn;
	}
private:
	//层数
	INT32 m_LayerCount;
public:
	void SetLayerCount( INT32 v)
	{
		m_LayerCount=v;
	}
	INT32 GetLayerCount()
	{
		return m_LayerCount;
	}
	INT32 GetLayerCount() const
	{
		return m_LayerCount;
	}

};
//副本数据封装类
class DungeonDataWraper
{
public:
	//构造函数
	DungeonDataWraper()
	{
		
		m_DurationMentTime = 0;
		m_ConclusionTime = 0;
		m_PrepareTime = 0;
		m_RewardTime = 0;

	}
	//赋值构造函数
	DungeonDataWraper(const DungeonData& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonData ToPB() const
	{
		DungeonData v;
		v.set_durationmenttime( m_DurationMentTime );
		v.set_conclusiontime( m_ConclusionTime );
		v.set_preparetime( m_PrepareTime );
		v.set_rewardtime( m_RewardTime );

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
		DungeonData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DungeonData& v)
	{
		m_DurationMentTime = v.durationmenttime();
		m_ConclusionTime = v.conclusiontime();
		m_PrepareTime = v.preparetime();
		m_RewardTime = v.rewardtime();

	}

private:
	//副本释放
	INT32 m_DurationMentTime;
public:
	void SetDurationMentTime( INT32 v)
	{
		m_DurationMentTime=v;
	}
	INT32 GetDurationMentTime()
	{
		return m_DurationMentTime;
	}
	INT32 GetDurationMentTime() const
	{
		return m_DurationMentTime;
	}
private:
	//副本结算时间
	INT32 m_ConclusionTime;
public:
	void SetConclusionTime( INT32 v)
	{
		m_ConclusionTime=v;
	}
	INT32 GetConclusionTime()
	{
		return m_ConclusionTime;
	}
	INT32 GetConclusionTime() const
	{
		return m_ConclusionTime;
	}
private:
	//副本准备时间
	INT32 m_PrepareTime;
public:
	void SetPrepareTime( INT32 v)
	{
		m_PrepareTime=v;
	}
	INT32 GetPrepareTime()
	{
		return m_PrepareTime;
	}
	INT32 GetPrepareTime() const
	{
		return m_PrepareTime;
	}
private:
	//奖励时间
	INT32 m_RewardTime;
public:
	void SetRewardTime( INT32 v)
	{
		m_RewardTime=v;
	}
	INT32 GetRewardTime()
	{
		return m_RewardTime;
	}
	INT32 GetRewardTime() const
	{
		return m_RewardTime;
	}

};
//ServerInfo封装类
class ServerInfoWraper
{
public:
	//构造函数
	ServerInfoWraper()
	{
		
		m_Id = -1;
		m_Name = "";
		m_Region = -1;
		m_Status = -1;
		m_Promo = -1;
		m_Ip = "";
		m_Port = -1;

	}
	//赋值构造函数
	ServerInfoWraper(const ServerInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ServerInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ServerInfo ToPB() const
	{
		ServerInfo v;
		v.set_id( m_Id );
		v.set_name( m_Name );
		v.set_region( m_Region );
		v.set_status( m_Status );
		v.set_promo( m_Promo );
		v.set_ip( m_Ip );
		v.set_port( m_Port );

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
		ServerInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ServerInfo& v)
	{
		m_Id = v.id();
		m_Name = v.name();
		m_Region = v.region();
		m_Status = v.status();
		m_Promo = v.promo();
		m_Ip = v.ip();
		m_Port = v.port();

	}

private:
	//id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//服务器名字
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
	//大区
	INT32 m_Region;
public:
	void SetRegion( INT32 v)
	{
		m_Region=v;
	}
	INT32 GetRegion()
	{
		return m_Region;
	}
	INT32 GetRegion() const
	{
		return m_Region;
	}
private:
	//状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//推荐
	INT32 m_Promo;
public:
	void SetPromo( INT32 v)
	{
		m_Promo=v;
	}
	INT32 GetPromo()
	{
		return m_Promo;
	}
	INT32 GetPromo() const
	{
		return m_Promo;
	}
private:
	//ip地址
	string m_Ip;
public:
	void SetIp( const string& v)
	{
		m_Ip=v;
	}
	string GetIp()
	{
		return m_Ip;
	}
	string GetIp() const
	{
		return m_Ip;
	}
private:
	//端口
	INT32 m_Port;
public:
	void SetPort( INT32 v)
	{
		m_Port=v;
	}
	INT32 GetPort()
	{
		return m_Port;
	}
	INT32 GetPort() const
	{
		return m_Port;
	}

};
//队伍快速更新信息封装类
class TeamMemberQuickUpdateInfoWraper
{
public:
	//构造函数
	TeamMemberQuickUpdateInfoWraper()
	{
		
		m_Location = CharacterLocationWraper();
		m_MaxMp = -1;
		m_MaxHp = -1;

	}
	//赋值构造函数
	TeamMemberQuickUpdateInfoWraper(const TeamMemberQuickUpdateInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberQuickUpdateInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberQuickUpdateInfo ToPB() const
	{
		TeamMemberQuickUpdateInfo v;
		*v.mutable_location()= m_Location.ToPB();
		v.set_maxmp( m_MaxMp );
		v.set_maxhp( m_MaxHp );

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
		TeamMemberQuickUpdateInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamMemberQuickUpdateInfo& v)
	{
		m_Location = v.location();
		m_MaxMp = v.maxmp();
		m_MaxHp = v.maxhp();

	}

private:
	//Location
	CharacterLocationWraper m_Location;
public:
	void SetLocation( const CharacterLocationWraper& v)
	{
		m_Location=v;
	}
	CharacterLocationWraper GetLocation()
	{
		return m_Location;
	}
	CharacterLocationWraper GetLocation() const
	{
		return m_Location;
	}
private:
	//生命值
	int64_t m_MaxMp;
public:
	void SetMaxMp( int64_t v)
	{
		m_MaxMp=v;
	}
	int64_t GetMaxMp()
	{
		return m_MaxMp;
	}
	int64_t GetMaxMp() const
	{
		return m_MaxMp;
	}
private:
	//生命值
	int64_t m_MaxHp;
public:
	void SetMaxHp( int64_t v)
	{
		m_MaxHp=v;
	}
	int64_t GetMaxHp()
	{
		return m_MaxHp;
	}
	int64_t GetMaxHp() const
	{
		return m_MaxHp;
	}

};
//公会信息封装类
class GuildInfoWraper
{
public:
	//构造函数
	GuildInfoWraper()
	{
		
		m_Guid = 0;
		m_GuildName = "";
		m_GuildLeader = "";
		m_GuildLevel = -1;
		m_MemberCount = -1;
		m_OnlineCount = -1;
		m_GuildProsper = -1;
		m_GuildMoney = -1;
		m_GuildResource = -1;
		m_GuildCreed = "";
		m_Flag = GuildFlagWraper();
		m_IsAutoJoin = false;
		m_GuildOldName = "";
		m_GuildCreater = "";
		m_SelfOffice = -1;
		m_TotalCount = -1;
		m_IsVacation = false;
		m_HaveApplied = false;
		m_MaintainCost = -1;
		m_GuildWelfare = -1;
		m_LeaderGuid = 0;
		m_CampEndTime = 0;
		m_Guildcamp = 2;
		m_GuildShortName = "";
		m_GuildShortColorID = -1;

	}
	//赋值构造函数
	GuildInfoWraper(const GuildInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildInfo ToPB() const
	{
		GuildInfo v;
		v.set_guid( m_Guid );
		v.set_guildname( m_GuildName );
		v.set_guildleader( m_GuildLeader );
		v.set_guildlevel( m_GuildLevel );
		v.set_membercount( m_MemberCount );
		v.set_onlinecount( m_OnlineCount );
		v.set_guildprosper( m_GuildProsper );
		v.set_guildmoney( m_GuildMoney );
		v.set_guildresource( m_GuildResource );
		v.set_guildcreed( m_GuildCreed );
		*v.mutable_flag()= m_Flag.ToPB();
		v.mutable_news()->Reserve(m_News.size());
		for (int i=0; i<(int)m_News.size(); i++)
		{
			*v.add_news() = m_News[i].ToPB();
		}
		v.set_isautojoin( m_IsAutoJoin );
		v.set_guildoldname( m_GuildOldName );
		v.set_guildcreater( m_GuildCreater );
		v.set_selfoffice( m_SelfOffice );
		v.set_totalcount( m_TotalCount );
		v.set_isvacation( m_IsVacation );
		v.set_haveapplied( m_HaveApplied );
		v.set_maintaincost( m_MaintainCost );
		v.set_guildwelfare( m_GuildWelfare );
		v.set_leaderguid( m_LeaderGuid );
		v.set_campendtime( m_CampEndTime );
		v.set_guildcamp( m_Guildcamp );
		v.set_guildshortname( m_GuildShortName );
		v.set_guildshortcolorid( m_GuildShortColorID );

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
		GuildInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildInfo& v)
	{
		m_Guid = v.guid();
		m_GuildName = v.guildname();
		m_GuildLeader = v.guildleader();
		m_GuildLevel = v.guildlevel();
		m_MemberCount = v.membercount();
		m_OnlineCount = v.onlinecount();
		m_GuildProsper = v.guildprosper();
		m_GuildMoney = v.guildmoney();
		m_GuildResource = v.guildresource();
		m_GuildCreed = v.guildcreed();
		m_Flag = v.flag();
		m_News.clear();
		m_News.reserve(v.news_size());
		for( int i=0; i<v.news_size(); i++)
			m_News.push_back(v.news(i));
		m_IsAutoJoin = v.isautojoin();
		m_GuildOldName = v.guildoldname();
		m_GuildCreater = v.guildcreater();
		m_SelfOffice = v.selfoffice();
		m_TotalCount = v.totalcount();
		m_IsVacation = v.isvacation();
		m_HaveApplied = v.haveapplied();
		m_MaintainCost = v.maintaincost();
		m_GuildWelfare = v.guildwelfare();
		m_LeaderGuid = v.leaderguid();
		m_CampEndTime = v.campendtime();
		m_Guildcamp = v.guildcamp();
		m_GuildShortName = v.guildshortname();
		m_GuildShortColorID = v.guildshortcolorid();

	}

private:
	//guid
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
	//公会名称
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//公会会长
	string m_GuildLeader;
public:
	void SetGuildLeader( const string& v)
	{
		m_GuildLeader=v;
	}
	string GetGuildLeader()
	{
		return m_GuildLeader;
	}
	string GetGuildLeader() const
	{
		return m_GuildLeader;
	}
private:
	//公会等级
	INT32 m_GuildLevel;
public:
	void SetGuildLevel( INT32 v)
	{
		m_GuildLevel=v;
	}
	INT32 GetGuildLevel()
	{
		return m_GuildLevel;
	}
	INT32 GetGuildLevel() const
	{
		return m_GuildLevel;
	}
private:
	//成员数量
	INT32 m_MemberCount;
public:
	void SetMemberCount( INT32 v)
	{
		m_MemberCount=v;
	}
	INT32 GetMemberCount()
	{
		return m_MemberCount;
	}
	INT32 GetMemberCount() const
	{
		return m_MemberCount;
	}
private:
	//在线人数
	INT32 m_OnlineCount;
public:
	void SetOnlineCount( INT32 v)
	{
		m_OnlineCount=v;
	}
	INT32 GetOnlineCount()
	{
		return m_OnlineCount;
	}
	INT32 GetOnlineCount() const
	{
		return m_OnlineCount;
	}
private:
	//公会繁荣度
	INT32 m_GuildProsper;
public:
	void SetGuildProsper( INT32 v)
	{
		m_GuildProsper=v;
	}
	INT32 GetGuildProsper()
	{
		return m_GuildProsper;
	}
	INT32 GetGuildProsper() const
	{
		return m_GuildProsper;
	}
private:
	//公会资金
	INT32 m_GuildMoney;
public:
	void SetGuildMoney( INT32 v)
	{
		m_GuildMoney=v;
	}
	INT32 GetGuildMoney()
	{
		return m_GuildMoney;
	}
	INT32 GetGuildMoney() const
	{
		return m_GuildMoney;
	}
private:
	//公会资源
	INT32 m_GuildResource;
public:
	void SetGuildResource( INT32 v)
	{
		m_GuildResource=v;
	}
	INT32 GetGuildResource()
	{
		return m_GuildResource;
	}
	INT32 GetGuildResource() const
	{
		return m_GuildResource;
	}
private:
	//公会宗旨
	string m_GuildCreed;
public:
	void SetGuildCreed( const string& v)
	{
		m_GuildCreed=v;
	}
	string GetGuildCreed()
	{
		return m_GuildCreed;
	}
	string GetGuildCreed() const
	{
		return m_GuildCreed;
	}
private:
	//公会旗帜
	GuildFlagWraper m_Flag;
public:
	void SetFlag( const GuildFlagWraper& v)
	{
		m_Flag=v;
	}
	GuildFlagWraper GetFlag()
	{
		return m_Flag;
	}
	GuildFlagWraper GetFlag() const
	{
		return m_Flag;
	}
private:
	//公会新闻
	vector<GuildNewsWraper> m_News;
public:
	int SizeNews()
	{
		return m_News.size();
	}
	const vector<GuildNewsWraper>& GetNews() const
	{
		return m_News;
	}
	GuildNewsWraper GetNews(int Index) const
	{
		if(Index<0 || Index>=(int)m_News.size())
		{
			assert(false);
			return GuildNewsWraper();
		}
		return m_News[Index];
	}
	void SetNews( const vector<GuildNewsWraper>& v )
	{
		m_News=v;
	}
	void ClearNews( )
	{
		m_News.clear();
	}
	void SetNews( int Index, const GuildNewsWraper& v )
	{
		if(Index<0 || Index>=(int)m_News.size())
		{
			assert(false);
			return;
		}
		m_News[Index] = v;
	}
	void AddNews( const GuildNewsWraper& v )
	{
		m_News.push_back(v);
	}
private:
	//是否允许自动入会
	bool m_IsAutoJoin;
public:
	void SetIsAutoJoin( bool v)
	{
		m_IsAutoJoin=v;
	}
	bool GetIsAutoJoin()
	{
		return m_IsAutoJoin;
	}
	bool GetIsAutoJoin() const
	{
		return m_IsAutoJoin;
	}
private:
	//公会曾用名
	string m_GuildOldName;
public:
	void SetGuildOldName( const string& v)
	{
		m_GuildOldName=v;
	}
	string GetGuildOldName()
	{
		return m_GuildOldName;
	}
	string GetGuildOldName() const
	{
		return m_GuildOldName;
	}
private:
	//公会创始人
	string m_GuildCreater;
public:
	void SetGuildCreater( const string& v)
	{
		m_GuildCreater=v;
	}
	string GetGuildCreater()
	{
		return m_GuildCreater;
	}
	string GetGuildCreater() const
	{
		return m_GuildCreater;
	}
private:
	//自己的公会职位
	INT32 m_SelfOffice;
public:
	void SetSelfOffice( INT32 v)
	{
		m_SelfOffice=v;
	}
	INT32 GetSelfOffice()
	{
		return m_SelfOffice;
	}
	INT32 GetSelfOffice() const
	{
		return m_SelfOffice;
	}
private:
	//公会目前可容纳人员总数
	INT32 m_TotalCount;
public:
	void SetTotalCount( INT32 v)
	{
		m_TotalCount=v;
	}
	INT32 GetTotalCount()
	{
		return m_TotalCount;
	}
	INT32 GetTotalCount() const
	{
		return m_TotalCount;
	}
private:
	//是否请假
	bool m_IsVacation;
public:
	void SetIsVacation( bool v)
	{
		m_IsVacation=v;
	}
	bool GetIsVacation()
	{
		return m_IsVacation;
	}
	bool GetIsVacation() const
	{
		return m_IsVacation;
	}
private:
	//是否已申请
	bool m_HaveApplied;
public:
	void SetHaveApplied( bool v)
	{
		m_HaveApplied=v;
	}
	bool GetHaveApplied()
	{
		return m_HaveApplied;
	}
	bool GetHaveApplied() const
	{
		return m_HaveApplied;
	}
private:
	//维护费用
	INT32 m_MaintainCost;
public:
	void SetMaintainCost( INT32 v)
	{
		m_MaintainCost=v;
	}
	INT32 GetMaintainCost()
	{
		return m_MaintainCost;
	}
	INT32 GetMaintainCost() const
	{
		return m_MaintainCost;
	}
private:
	//公会福利
	INT32 m_GuildWelfare;
public:
	void SetGuildWelfare( INT32 v)
	{
		m_GuildWelfare=v;
	}
	INT32 GetGuildWelfare()
	{
		return m_GuildWelfare;
	}
	INT32 GetGuildWelfare() const
	{
		return m_GuildWelfare;
	}
private:
	//会长guid
	uint64_t m_LeaderGuid;
public:
	void SetLeaderGuid( uint64_t v)
	{
		m_LeaderGuid=v;
	}
	uint64_t GetLeaderGuid()
	{
		return m_LeaderGuid;
	}
	uint64_t GetLeaderGuid() const
	{
		return m_LeaderGuid;
	}
private:
	//阵营转换结束时间
	uint64_t m_CampEndTime;
public:
	void SetCampEndTime( uint64_t v)
	{
		m_CampEndTime=v;
	}
	uint64_t GetCampEndTime()
	{
		return m_CampEndTime;
	}
	uint64_t GetCampEndTime() const
	{
		return m_CampEndTime;
	}
private:
	//公会阵营(2中立 4神圣 5自由)
	INT32 m_Guildcamp;
public:
	void SetGuildcamp( INT32 v)
	{
		m_Guildcamp=v;
	}
	INT32 GetGuildcamp()
	{
		return m_Guildcamp;
	}
	INT32 GetGuildcamp() const
	{
		return m_Guildcamp;
	}
private:
	//公会简称
	string m_GuildShortName;
public:
	void SetGuildShortName( const string& v)
	{
		m_GuildShortName=v;
	}
	string GetGuildShortName()
	{
		return m_GuildShortName;
	}
	string GetGuildShortName() const
	{
		return m_GuildShortName;
	}
private:
	//公会简称颜色
	INT32 m_GuildShortColorID;
public:
	void SetGuildShortColorID( INT32 v)
	{
		m_GuildShortColorID=v;
	}
	INT32 GetGuildShortColorID()
	{
		return m_GuildShortColorID;
	}
	INT32 GetGuildShortColorID() const
	{
		return m_GuildShortColorID;
	}

};
//世界BOSS排行榜封装类
class WorldBossRankWraper
{
public:
	//构造函数
	WorldBossRankWraper()
	{
		
		m_Occupation = -1;

	}
	//赋值构造函数
	WorldBossRankWraper(const WorldBossRank& v){ Init(v); }
	//等号重载函数
	void operator = (const WorldBossRank& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorldBossRank ToPB() const
	{
		WorldBossRank v;
		v.mutable_scoreinfo()->Reserve(m_ScoreInfo.size());
		for (int i=0; i<(int)m_ScoreInfo.size(); i++)
		{
			*v.add_scoreinfo() = m_ScoreInfo[i].ToPB();
		}
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
		WorldBossRank pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorldBossRank& v)
	{
		m_ScoreInfo.clear();
		m_ScoreInfo.reserve(v.scoreinfo_size());
		for( int i=0; i<v.scoreinfo_size(); i++)
			m_ScoreInfo.push_back(v.scoreinfo(i));
		m_Occupation = v.occupation();

	}

private:
	//世界BOSS积分信息
	vector<WorldBossScoreInfoWraper> m_ScoreInfo;
public:
	int SizeScoreInfo()
	{
		return m_ScoreInfo.size();
	}
	const vector<WorldBossScoreInfoWraper>& GetScoreInfo() const
	{
		return m_ScoreInfo;
	}
	WorldBossScoreInfoWraper GetScoreInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_ScoreInfo.size())
		{
			assert(false);
			return WorldBossScoreInfoWraper();
		}
		return m_ScoreInfo[Index];
	}
	void SetScoreInfo( const vector<WorldBossScoreInfoWraper>& v )
	{
		m_ScoreInfo=v;
	}
	void ClearScoreInfo( )
	{
		m_ScoreInfo.clear();
	}
	void SetScoreInfo( int Index, const WorldBossScoreInfoWraper& v )
	{
		if(Index<0 || Index>=(int)m_ScoreInfo.size())
		{
			assert(false);
			return;
		}
		m_ScoreInfo[Index] = v;
	}
	void AddScoreInfo( const WorldBossScoreInfoWraper& v )
	{
		m_ScoreInfo.push_back(v);
	}
private:
	//职业类型(为0时是总排行榜)
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
//DailyQuestList封装类
class DailyQuestListWraper
{
public:
	//构造函数
	DailyQuestListWraper()
	{
		

	}
	//赋值构造函数
	DailyQuestListWraper(const DailyQuestList& v){ Init(v); }
	//等号重载函数
	void operator = (const DailyQuestList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DailyQuestList ToPB() const
	{
		DailyQuestList v;
		v.mutable_dailyquestlist()->Reserve(m_DailyQuestList.size());
		for (int i=0; i<(int)m_DailyQuestList.size(); i++)
		{
			*v.add_dailyquestlist() = m_DailyQuestList[i].ToPB();
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
		DailyQuestList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DailyQuestList& v)
	{
		m_DailyQuestList.clear();
		m_DailyQuestList.reserve(v.dailyquestlist_size());
		for( int i=0; i<v.dailyquestlist_size(); i++)
			m_DailyQuestList.push_back(v.dailyquestlist(i));

	}

private:
	//DailyQuestList
	vector<DailyQuestWraper> m_DailyQuestList;
public:
	int SizeDailyQuestList()
	{
		return m_DailyQuestList.size();
	}
	const vector<DailyQuestWraper>& GetDailyQuestList() const
	{
		return m_DailyQuestList;
	}
	DailyQuestWraper GetDailyQuestList(int Index) const
	{
		if(Index<0 || Index>=(int)m_DailyQuestList.size())
		{
			assert(false);
			return DailyQuestWraper();
		}
		return m_DailyQuestList[Index];
	}
	void SetDailyQuestList( const vector<DailyQuestWraper>& v )
	{
		m_DailyQuestList=v;
	}
	void ClearDailyQuestList( )
	{
		m_DailyQuestList.clear();
	}
	void SetDailyQuestList( int Index, const DailyQuestWraper& v )
	{
		if(Index<0 || Index>=(int)m_DailyQuestList.size())
		{
			assert(false);
			return;
		}
		m_DailyQuestList[Index] = v;
	}
	void AddDailyQuestList( const DailyQuestWraper& v )
	{
		m_DailyQuestList.push_back(v);
	}

};
//通讯录封装类
class AddressBookWraper
{
public:
	//构造函数
	AddressBookWraper()
	{
		
		m_Setting = ContactSettingWraper();
		m_MyRoleData = ContactDataWraper();
		m_GiftPointList = FriendGifPointListWraper();

	}
	//赋值构造函数
	AddressBookWraper(const AddressBook& v){ Init(v); }
	//等号重载函数
	void operator = (const AddressBook& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AddressBook ToPB() const
	{
		AddressBook v;
		v.mutable_contactdatalist()->Reserve(m_ContactDataList.size());
		for (int i=0; i<(int)m_ContactDataList.size(); i++)
		{
			*v.add_contactdatalist() = m_ContactDataList[i].ToPB();
		}
		v.mutable_contactgroups()->Reserve(m_ContactGroups.size());
		for (int i=0; i<(int)m_ContactGroups.size(); i++)
		{
			*v.add_contactgroups() = m_ContactGroups[i].ToPB();
		}
		*v.mutable_setting()= m_Setting.ToPB();
		*v.mutable_myroledata()= m_MyRoleData.ToPB();
		v.mutable_sortgroupid()->Reserve(m_SortGroupId.size());
		for (int i=0; i<(int)m_SortGroupId.size(); i++)
		{
			v.add_sortgroupid(m_SortGroupId[i]);
		}
		*v.mutable_giftpointlist()= m_GiftPointList.ToPB();
		v.mutable_chatmsglist()->Reserve(m_ChatMsgList.size());
		for (int i=0; i<(int)m_ChatMsgList.size(); i++)
		{
			*v.add_chatmsglist() = m_ChatMsgList[i].ToPB();
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
		AddressBook pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AddressBook& v)
	{
		m_ContactDataList.clear();
		m_ContactDataList.reserve(v.contactdatalist_size());
		for( int i=0; i<v.contactdatalist_size(); i++)
			m_ContactDataList.push_back(v.contactdatalist(i));
		m_ContactGroups.clear();
		m_ContactGroups.reserve(v.contactgroups_size());
		for( int i=0; i<v.contactgroups_size(); i++)
			m_ContactGroups.push_back(v.contactgroups(i));
		m_Setting = v.setting();
		m_MyRoleData = v.myroledata();
		m_SortGroupId.clear();
		m_SortGroupId.reserve(v.sortgroupid_size());
		for( int i=0; i<v.sortgroupid_size(); i++)
			m_SortGroupId.push_back(v.sortgroupid(i));
		m_GiftPointList = v.giftpointlist();
		m_ChatMsgList.clear();
		m_ChatMsgList.reserve(v.chatmsglist_size());
		for( int i=0; i<v.chatmsglist_size(); i++)
			m_ChatMsgList.push_back(v.chatmsglist(i));

	}

private:
	//联系人列表
	vector<ContactDataWraper> m_ContactDataList;
public:
	int SizeContactDataList()
	{
		return m_ContactDataList.size();
	}
	const vector<ContactDataWraper>& GetContactDataList() const
	{
		return m_ContactDataList;
	}
	ContactDataWraper GetContactDataList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactDataList.size())
		{
			assert(false);
			return ContactDataWraper();
		}
		return m_ContactDataList[Index];
	}
	void SetContactDataList( const vector<ContactDataWraper>& v )
	{
		m_ContactDataList=v;
	}
	void ClearContactDataList( )
	{
		m_ContactDataList.clear();
	}
	void SetContactDataList( int Index, const ContactDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactDataList.size())
		{
			assert(false);
			return;
		}
		m_ContactDataList[Index] = v;
	}
	void AddContactDataList( const ContactDataWraper& v )
	{
		m_ContactDataList.push_back(v);
	}
private:
	//联系人分组数据
	vector<ContactGroupWraper> m_ContactGroups;
public:
	int SizeContactGroups()
	{
		return m_ContactGroups.size();
	}
	const vector<ContactGroupWraper>& GetContactGroups() const
	{
		return m_ContactGroups;
	}
	ContactGroupWraper GetContactGroups(int Index) const
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return ContactGroupWraper();
		}
		return m_ContactGroups[Index];
	}
	void SetContactGroups( const vector<ContactGroupWraper>& v )
	{
		m_ContactGroups=v;
	}
	void ClearContactGroups( )
	{
		m_ContactGroups.clear();
	}
	void SetContactGroups( int Index, const ContactGroupWraper& v )
	{
		if(Index<0 || Index>=(int)m_ContactGroups.size())
		{
			assert(false);
			return;
		}
		m_ContactGroups[Index] = v;
	}
	void AddContactGroups( const ContactGroupWraper& v )
	{
		m_ContactGroups.push_back(v);
	}
private:
	//好友设置
	ContactSettingWraper m_Setting;
public:
	void SetSetting( const ContactSettingWraper& v)
	{
		m_Setting=v;
	}
	ContactSettingWraper GetSetting()
	{
		return m_Setting;
	}
	ContactSettingWraper GetSetting() const
	{
		return m_Setting;
	}
private:
	//我自己的数据
	ContactDataWraper m_MyRoleData;
public:
	void SetMyRoleData( const ContactDataWraper& v)
	{
		m_MyRoleData=v;
	}
	ContactDataWraper GetMyRoleData()
	{
		return m_MyRoleData;
	}
	ContactDataWraper GetMyRoleData() const
	{
		return m_MyRoleData;
	}
private:
	//排序的id
	vector<INT32> m_SortGroupId;
public:
	int SizeSortGroupId()
	{
		return m_SortGroupId.size();
	}
	const vector<INT32>& GetSortGroupId() const
	{
		return m_SortGroupId;
	}
	INT32 GetSortGroupId(int Index) const
	{
		if(Index<0 || Index>=(int)m_SortGroupId.size())
		{
			assert(false);
			return INT32();
		}
		return m_SortGroupId[Index];
	}
	void SetSortGroupId( const vector<INT32>& v )
	{
		m_SortGroupId=v;
	}
	void ClearSortGroupId( )
	{
		m_SortGroupId.clear();
	}
	void SetSortGroupId( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SortGroupId.size())
		{
			assert(false);
			return;
		}
		m_SortGroupId[Index] = v;
	}
	void AddSortGroupId( INT32 v = -1 )
	{
		m_SortGroupId.push_back(v);
	}
private:
	//友情点
	FriendGifPointListWraper m_GiftPointList;
public:
	void SetGiftPointList( const FriendGifPointListWraper& v)
	{
		m_GiftPointList=v;
	}
	FriendGifPointListWraper GetGiftPointList()
	{
		return m_GiftPointList;
	}
	FriendGifPointListWraper GetGiftPointList() const
	{
		return m_GiftPointList;
	}
private:
	//玩家聊天信息
	vector<ContactsChatMsgWraper> m_ChatMsgList;
public:
	int SizeChatMsgList()
	{
		return m_ChatMsgList.size();
	}
	const vector<ContactsChatMsgWraper>& GetChatMsgList() const
	{
		return m_ChatMsgList;
	}
	ContactsChatMsgWraper GetChatMsgList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ChatMsgList.size())
		{
			assert(false);
			return ContactsChatMsgWraper();
		}
		return m_ChatMsgList[Index];
	}
	void SetChatMsgList( const vector<ContactsChatMsgWraper>& v )
	{
		m_ChatMsgList=v;
	}
	void ClearChatMsgList( )
	{
		m_ChatMsgList.clear();
	}
	void SetChatMsgList( int Index, const ContactsChatMsgWraper& v )
	{
		if(Index<0 || Index>=(int)m_ChatMsgList.size())
		{
			assert(false);
			return;
		}
		m_ChatMsgList[Index] = v;
	}
	void AddChatMsgList( const ContactsChatMsgWraper& v )
	{
		m_ChatMsgList.push_back(v);
	}

};
//玩家准备状态封装类
class PvpPlayerStateWraper
{
public:
	//构造函数
	PvpPlayerStateWraper()
	{
		
		m_RoleID = 0;
		m_State = -1;

	}
	//赋值构造函数
	PvpPlayerStateWraper(const PvpPlayerState& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpPlayerState& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpPlayerState ToPB() const
	{
		PvpPlayerState v;
		v.set_roleid( m_RoleID );
		v.set_state( m_State );

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
		PvpPlayerState pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpPlayerState& v)
	{
		m_RoleID = v.roleid();
		m_State = v.state();

	}

private:
	//RoleID
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
	//State
	INT32 m_State;
public:
	void SetState( INT32 v)
	{
		m_State=v;
	}
	INT32 GetState()
	{
		return m_State;
	}
	INT32 GetState() const
	{
		return m_State;
	}

};
//交易记录封装类
class AuctionRecSimpleWraper
{
public:
	//构造函数
	AuctionRecSimpleWraper()
	{
		
		m_RecGuid = 0;
		m_SoldTS = -1;
		m_ItemId = -1;
		m_Count = -1;
		m_Currency = -1;
		m_Cost = -1;
		m_SoldType = -1;
		m_Tax = -1;
		m_IsGot = false;

	}
	//赋值构造函数
	AuctionRecSimpleWraper(const AuctionRecSimple& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRecSimple& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRecSimple ToPB() const
	{
		AuctionRecSimple v;
		v.set_recguid( m_RecGuid );
		v.set_soldts( m_SoldTS );
		v.set_itemid( m_ItemId );
		v.set_count( m_Count );
		v.set_currency( m_Currency );
		v.set_cost( m_Cost );
		v.set_soldtype( m_SoldType );
		v.set_tax( m_Tax );
		v.set_isgot( m_IsGot );

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
		AuctionRecSimple pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AuctionRecSimple& v)
	{
		m_RecGuid = v.recguid();
		m_SoldTS = v.soldts();
		m_ItemId = v.itemid();
		m_Count = v.count();
		m_Currency = v.currency();
		m_Cost = v.cost();
		m_SoldType = v.soldtype();
		m_Tax = v.tax();
		m_IsGot = v.isgot();

	}

private:
	//物品guid
	uint64_t m_RecGuid;
public:
	void SetRecGuid( uint64_t v)
	{
		m_RecGuid=v;
	}
	uint64_t GetRecGuid()
	{
		return m_RecGuid;
	}
	uint64_t GetRecGuid() const
	{
		return m_RecGuid;
	}
private:
	//交易时间
	INT32 m_SoldTS;
public:
	void SetSoldTS( INT32 v)
	{
		m_SoldTS=v;
	}
	INT32 GetSoldTS()
	{
		return m_SoldTS;
	}
	INT32 GetSoldTS() const
	{
		return m_SoldTS;
	}
private:
	//商品itemID
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
private:
	//数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}
private:
	//货币类型
	INT32 m_Currency;
public:
	void SetCurrency( INT32 v)
	{
		m_Currency=v;
	}
	INT32 GetCurrency()
	{
		return m_Currency;
	}
	INT32 GetCurrency() const
	{
		return m_Currency;
	}
private:
	//货币数量
	INT32 m_Cost;
public:
	void SetCost( INT32 v)
	{
		m_Cost=v;
	}
	INT32 GetCost()
	{
		return m_Cost;
	}
	INT32 GetCost() const
	{
		return m_Cost;
	}
private:
	//交易类型
	INT32 m_SoldType;
public:
	void SetSoldType( INT32 v)
	{
		m_SoldType=v;
	}
	INT32 GetSoldType()
	{
		return m_SoldType;
	}
	INT32 GetSoldType() const
	{
		return m_SoldType;
	}
private:
	//税
	INT32 m_Tax;
public:
	void SetTax( INT32 v)
	{
		m_Tax=v;
	}
	INT32 GetTax()
	{
		return m_Tax;
	}
	INT32 GetTax() const
	{
		return m_Tax;
	}
private:
	//是不是交付
	bool m_IsGot;
public:
	void SetIsGot( bool v)
	{
		m_IsGot=v;
	}
	bool GetIsGot()
	{
		return m_IsGot;
	}
	bool GetIsGot() const
	{
		return m_IsGot;
	}

};
//32位程序封装类
class IntPairWraper
{
public:
	//构造函数
	IntPairWraper()
	{
		
		m_Key = -1;
		m_Value = -1;

	}
	//赋值构造函数
	IntPairWraper(const IntPair& v){ Init(v); }
	//等号重载函数
	void operator = (const IntPair& v){ Init(v); }
 	//转化成Protobuffer类型函数
	IntPair ToPB() const
	{
		IntPair v;
		v.set_key( m_Key );
		v.set_value( m_Value );

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
		IntPair pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const IntPair& v)
	{
		m_Key = v.key();
		m_Value = v.value();

	}

private:
	//键值
	INT32 m_Key;
public:
	void SetKey( INT32 v)
	{
		m_Key=v;
	}
	INT32 GetKey()
	{
		return m_Key;
	}
	INT32 GetKey() const
	{
		return m_Key;
	}
private:
	//值
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}

};
//每日计数封装类
class DailyCountWraper
{
public:
	//构造函数
	DailyCountWraper()
	{
		
		m_Count = 0;
		m_Time = 0;
		m_TimeId = 0;
		m_Flag = -1;

	}
	//赋值构造函数
	DailyCountWraper(const DailyCount& v){ Init(v); }
	//等号重载函数
	void operator = (const DailyCount& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DailyCount ToPB() const
	{
		DailyCount v;
		v.set_count( m_Count );
		v.set_time( m_Time );
		v.set_timeid( m_TimeId );
		v.set_flag( m_Flag );

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
		DailyCount pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DailyCount& v)
	{
		m_Count = v.count();
		m_Time = v.time();
		m_TimeId = v.timeid();
		m_Flag = v.flag();

	}

private:
	//计数
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}
private:
	//时间
	int64_t m_Time;
public:
	void SetTime( int64_t v)
	{
		m_Time=v;
	}
	int64_t GetTime()
	{
		return m_Time;
	}
	int64_t GetTime() const
	{
		return m_Time;
	}
private:
	//时间id 保留字段
	INT32 m_TimeId;
public:
	void SetTimeId( INT32 v)
	{
		m_TimeId=v;
	}
	INT32 GetTimeId()
	{
		return m_TimeId;
	}
	INT32 GetTimeId() const
	{
		return m_TimeId;
	}
private:
	//计数标识
	INT32 m_Flag;
public:
	void SetFlag( INT32 v)
	{
		m_Flag=v;
	}
	INT32 GetFlag()
	{
		return m_Flag;
	}
	INT32 GetFlag() const
	{
		return m_Flag;
	}

};
//爬塔信息封装类
class ClimTowerInfoWraper
{
public:
	//构造函数
	ClimTowerInfoWraper()
	{
		
		m_LastTime = 0;
		m_CurLayer = 1;
		m_MaxLayer = 0;
		m_ResetLayerTime = 0;
		m_HoldLayer = 0;
		m_EnterPlay = 0;
		m_CurWave = -1;
		m_RefreshCount = -1;
		m_SweepCount = -1;

	}
	//赋值构造函数
	ClimTowerInfoWraper(const ClimTowerInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ClimTowerInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ClimTowerInfo ToPB() const
	{
		ClimTowerInfo v;
		v.set_lasttime( m_LastTime );
		v.set_curlayer( m_CurLayer );
		v.set_maxlayer( m_MaxLayer );
		v.set_resetlayertime( m_ResetLayerTime );
		v.mutable_firstget()->Reserve(m_FirstGet.size());
		for (int i=0; i<(int)m_FirstGet.size(); i++)
		{
			*v.add_firstget() = m_FirstGet[i].ToPB();
		}
		v.set_holdlayer( m_HoldLayer );
		v.set_enterplay( m_EnterPlay );
		v.set_curwave( m_CurWave );
		v.mutable_bufflists()->Reserve(m_BuffLists.size());
		for (int i=0; i<(int)m_BuffLists.size(); i++)
		{
			*v.add_bufflists() = m_BuffLists[i].ToPB();
		}
		v.set_refreshcount( m_RefreshCount );
		v.set_sweepcount( m_SweepCount );
		v.mutable_bufselhistory()->Reserve(m_BufSelHistory.size());
		for (int i=0; i<(int)m_BufSelHistory.size(); i++)
		{
			*v.add_bufselhistory() = m_BufSelHistory[i].ToPB();
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
		ClimTowerInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ClimTowerInfo& v)
	{
		m_LastTime = v.lasttime();
		m_CurLayer = v.curlayer();
		m_MaxLayer = v.maxlayer();
		m_ResetLayerTime = v.resetlayertime();
		m_FirstGet.clear();
		m_FirstGet.reserve(v.firstget_size());
		for( int i=0; i<v.firstget_size(); i++)
			m_FirstGet.push_back(v.firstget(i));
		m_HoldLayer = v.holdlayer();
		m_EnterPlay = v.enterplay();
		m_CurWave = v.curwave();
		m_BuffLists.clear();
		m_BuffLists.reserve(v.bufflists_size());
		for( int i=0; i<v.bufflists_size(); i++)
			m_BuffLists.push_back(v.bufflists(i));
		m_RefreshCount = v.refreshcount();
		m_SweepCount = v.sweepcount();
		m_BufSelHistory.clear();
		m_BufSelHistory.reserve(v.bufselhistory_size());
		for( int i=0; i<v.bufselhistory_size(); i++)
			m_BufSelHistory.push_back(v.bufselhistory(i));

	}

private:
	//每次爬塔时间
	int64_t m_LastTime;
public:
	void SetLastTime( int64_t v)
	{
		m_LastTime=v;
	}
	int64_t GetLastTime()
	{
		return m_LastTime;
	}
	int64_t GetLastTime() const
	{
		return m_LastTime;
	}
private:
	//玩家当前层
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
private:
	//已挑战完成最大层
	INT32 m_MaxLayer;
public:
	void SetMaxLayer( INT32 v)
	{
		m_MaxLayer=v;
	}
	INT32 GetMaxLayer()
	{
		return m_MaxLayer;
	}
	INT32 GetMaxLayer() const
	{
		return m_MaxLayer;
	}
private:
	//最高层重置时间
	int64_t m_ResetLayerTime;
public:
	void SetResetLayerTime( int64_t v)
	{
		m_ResetLayerTime=v;
	}
	int64_t GetResetLayerTime()
	{
		return m_ResetLayerTime;
	}
	int64_t GetResetLayerTime() const
	{
		return m_ResetLayerTime;
	}
private:
	//首次胜利领取奖励标识
	vector<FirstVicGetWraper> m_FirstGet;
public:
	int SizeFirstGet()
	{
		return m_FirstGet.size();
	}
	const vector<FirstVicGetWraper>& GetFirstGet() const
	{
		return m_FirstGet;
	}
	FirstVicGetWraper GetFirstGet(int Index) const
	{
		if(Index<0 || Index>=(int)m_FirstGet.size())
		{
			assert(false);
			return FirstVicGetWraper();
		}
		return m_FirstGet[Index];
	}
	void SetFirstGet( const vector<FirstVicGetWraper>& v )
	{
		m_FirstGet=v;
	}
	void ClearFirstGet( )
	{
		m_FirstGet.clear();
	}
	void SetFirstGet( int Index, const FirstVicGetWraper& v )
	{
		if(Index<0 || Index>=(int)m_FirstGet.size())
		{
			assert(false);
			return;
		}
		m_FirstGet[Index] = v;
	}
	void AddFirstGet( const FirstVicGetWraper& v )
	{
		m_FirstGet.push_back(v);
	}
private:
	//找回奖励层数
	INT32 m_HoldLayer;
public:
	void SetHoldLayer( INT32 v)
	{
		m_HoldLayer=v;
	}
	INT32 GetHoldLayer()
	{
		return m_HoldLayer;
	}
	INT32 GetHoldLayer() const
	{
		return m_HoldLayer;
	}
private:
	//当天是否进入过系统
	INT32 m_EnterPlay;
public:
	void SetEnterPlay( INT32 v)
	{
		m_EnterPlay=v;
	}
	INT32 GetEnterPlay()
	{
		return m_EnterPlay;
	}
	INT32 GetEnterPlay() const
	{
		return m_EnterPlay;
	}
private:
	//当前第几波怪
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
private:
	//Buff列表
	vector<ClimTowerBuffListWraper> m_BuffLists;
public:
	int SizeBuffLists()
	{
		return m_BuffLists.size();
	}
	const vector<ClimTowerBuffListWraper>& GetBuffLists() const
	{
		return m_BuffLists;
	}
	ClimTowerBuffListWraper GetBuffLists(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffLists.size())
		{
			assert(false);
			return ClimTowerBuffListWraper();
		}
		return m_BuffLists[Index];
	}
	void SetBuffLists( const vector<ClimTowerBuffListWraper>& v )
	{
		m_BuffLists=v;
	}
	void ClearBuffLists( )
	{
		m_BuffLists.clear();
	}
	void SetBuffLists( int Index, const ClimTowerBuffListWraper& v )
	{
		if(Index<0 || Index>=(int)m_BuffLists.size())
		{
			assert(false);
			return;
		}
		m_BuffLists[Index] = v;
	}
	void AddBuffLists( const ClimTowerBuffListWraper& v )
	{
		m_BuffLists.push_back(v);
	}
private:
	//Buff刷新次数
	INT32 m_RefreshCount;
public:
	void SetRefreshCount( INT32 v)
	{
		m_RefreshCount=v;
	}
	INT32 GetRefreshCount()
	{
		return m_RefreshCount;
	}
	INT32 GetRefreshCount() const
	{
		return m_RefreshCount;
	}
private:
	//一键扫荡次数
	INT32 m_SweepCount;
public:
	void SetSweepCount( INT32 v)
	{
		m_SweepCount=v;
	}
	INT32 GetSweepCount()
	{
		return m_SweepCount;
	}
	INT32 GetSweepCount() const
	{
		return m_SweepCount;
	}
private:
	//buf选择记录
	vector<ClimTowerBufWraper> m_BufSelHistory;
public:
	int SizeBufSelHistory()
	{
		return m_BufSelHistory.size();
	}
	const vector<ClimTowerBufWraper>& GetBufSelHistory() const
	{
		return m_BufSelHistory;
	}
	ClimTowerBufWraper GetBufSelHistory(int Index) const
	{
		if(Index<0 || Index>=(int)m_BufSelHistory.size())
		{
			assert(false);
			return ClimTowerBufWraper();
		}
		return m_BufSelHistory[Index];
	}
	void SetBufSelHistory( const vector<ClimTowerBufWraper>& v )
	{
		m_BufSelHistory=v;
	}
	void ClearBufSelHistory( )
	{
		m_BufSelHistory.clear();
	}
	void SetBufSelHistory( int Index, const ClimTowerBufWraper& v )
	{
		if(Index<0 || Index>=(int)m_BufSelHistory.size())
		{
			assert(false);
			return;
		}
		m_BufSelHistory[Index] = v;
	}
	void AddBufSelHistory( const ClimTowerBufWraper& v )
	{
		m_BufSelHistory.push_back(v);
	}

};
//表情动作信息封装类
class ExpressionActionInfoWraper
{
public:
	//构造函数
	ExpressionActionInfoWraper()
	{
		
		m_ActionId = -1;
		m_UnLock = false;

	}
	//赋值构造函数
	ExpressionActionInfoWraper(const ExpressionActionInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionActionInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionActionInfo ToPB() const
	{
		ExpressionActionInfo v;
		v.set_actionid( m_ActionId );
		v.set_unlock( m_UnLock );

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
		ExpressionActionInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ExpressionActionInfo& v)
	{
		m_ActionId = v.actionid();
		m_UnLock = v.unlock();

	}

private:
	//Id
	INT32 m_ActionId;
public:
	void SetActionId( INT32 v)
	{
		m_ActionId=v;
	}
	INT32 GetActionId()
	{
		return m_ActionId;
	}
	INT32 GetActionId() const
	{
		return m_ActionId;
	}
private:
	//是否解锁
	bool m_UnLock;
public:
	void SetUnLock( bool v)
	{
		m_UnLock=v;
	}
	bool GetUnLock()
	{
		return m_UnLock;
	}
	bool GetUnLock() const
	{
		return m_UnLock;
	}

};
//公会事件封装类
class GuildEventWraper
{
public:
	//构造函数
	GuildEventWraper()
	{
		
		m_Guid = 0;
		m_Date = 0;
		m_OptionType = -1;

	}
	//赋值构造函数
	GuildEventWraper(const GuildEvent& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildEvent& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildEvent ToPB() const
	{
		GuildEvent v;
		v.set_guid( m_Guid );
		v.set_date( m_Date );
		v.set_optiontype( m_OptionType );
		v.mutable_eventsparm()->Reserve(m_EventsParm.size());
		for (int i=0; i<(int)m_EventsParm.size(); i++)
		{
			v.add_eventsparm( m_EventsParm[i]);
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
		GuildEvent pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildEvent& v)
	{
		m_Guid = v.guid();
		m_Date = v.date();
		m_OptionType = v.optiontype();
		m_EventsParm.clear();
		m_EventsParm.reserve(v.eventsparm_size());
		for( int i=0; i<v.eventsparm_size(); i++)
			m_EventsParm.push_back(v.eventsparm(i));

	}

private:
	//guid
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
	//加速日期
	uint64_t m_Date;
public:
	void SetDate( uint64_t v)
	{
		m_Date=v;
	}
	uint64_t GetDate()
	{
		return m_Date;
	}
	uint64_t GetDate() const
	{
		return m_Date;
	}
private:
	//公会新闻类型
	INT32 m_OptionType;
public:
	void SetOptionType( INT32 v)
	{
		m_OptionType=v;
	}
	INT32 GetOptionType()
	{
		return m_OptionType;
	}
	INT32 GetOptionType() const
	{
		return m_OptionType;
	}
private:
	//事件参数
	vector<string> m_EventsParm;
public:
	int SizeEventsParm()
	{
		return m_EventsParm.size();
	}
	const vector<string>& GetEventsParm() const
	{
		return m_EventsParm;
	}
	string GetEventsParm(int Index) const
	{
		if(Index<0 || Index>=(int)m_EventsParm.size())
		{
			assert(false);
			return string();
		}
		return m_EventsParm[Index];
	}
	void SetEventsParm( const vector<string>& v )
	{
		m_EventsParm=v;
	}
	void ClearEventsParm( )
	{
		m_EventsParm.clear();
	}
	void SetEventsParm( int Index, const string& v )
	{
		if(Index<0 || Index>=(int)m_EventsParm.size())
		{
			assert(false);
			return;
		}
		m_EventsParm[Index] = v;
	}
	void AddEventsParm( const string& v )
	{
		m_EventsParm.push_back(v);
	}

};
//匹配出来的房间封装类
class PBMatchRoomWraper
{
public:
	//构造函数
	PBMatchRoomWraper()
	{
		
		m_MatchTarget = MatchTargetInfoWraper();
		m_RoomId = 0;
		m_MatchType = -1;
		m_EndTime = -1;

	}
	//赋值构造函数
	PBMatchRoomWraper(const PBMatchRoom& v){ Init(v); }
	//等号重载函数
	void operator = (const PBMatchRoom& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PBMatchRoom ToPB() const
	{
		PBMatchRoom v;
		v.mutable_camps()->Reserve(m_Camps.size());
		for (int i=0; i<(int)m_Camps.size(); i++)
		{
			*v.add_camps() = m_Camps[i].ToPB();
		}
		*v.mutable_matchtarget()= m_MatchTarget.ToPB();
		v.set_roomid( m_RoomId );
		v.set_matchtype( m_MatchType );
		v.set_endtime( m_EndTime );

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
		PBMatchRoom pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PBMatchRoom& v)
	{
		m_Camps.clear();
		m_Camps.reserve(v.camps_size());
		for( int i=0; i<v.camps_size(); i++)
			m_Camps.push_back(v.camps(i));
		m_MatchTarget = v.matchtarget();
		m_RoomId = v.roomid();
		m_MatchType = v.matchtype();
		m_EndTime = v.endtime();

	}

private:
	//阵营列表
	vector<MatchRoomCampsWraper> m_Camps;
public:
	int SizeCamps()
	{
		return m_Camps.size();
	}
	const vector<MatchRoomCampsWraper>& GetCamps() const
	{
		return m_Camps;
	}
	MatchRoomCampsWraper GetCamps(int Index) const
	{
		if(Index<0 || Index>=(int)m_Camps.size())
		{
			assert(false);
			return MatchRoomCampsWraper();
		}
		return m_Camps[Index];
	}
	void SetCamps( const vector<MatchRoomCampsWraper>& v )
	{
		m_Camps=v;
	}
	void ClearCamps( )
	{
		m_Camps.clear();
	}
	void SetCamps( int Index, const MatchRoomCampsWraper& v )
	{
		if(Index<0 || Index>=(int)m_Camps.size())
		{
			assert(false);
			return;
		}
		m_Camps[Index] = v;
	}
	void AddCamps( const MatchRoomCampsWraper& v )
	{
		m_Camps.push_back(v);
	}
private:
	//匹配目标
	MatchTargetInfoWraper m_MatchTarget;
public:
	void SetMatchTarget( const MatchTargetInfoWraper& v)
	{
		m_MatchTarget=v;
	}
	MatchTargetInfoWraper GetMatchTarget()
	{
		return m_MatchTarget;
	}
	MatchTargetInfoWraper GetMatchTarget() const
	{
		return m_MatchTarget;
	}
private:
	//匹配的房间id
	uint64_t m_RoomId;
public:
	void SetRoomId( uint64_t v)
	{
		m_RoomId=v;
	}
	uint64_t GetRoomId()
	{
		return m_RoomId;
	}
	uint64_t GetRoomId() const
	{
		return m_RoomId;
	}
private:
	//匹配类型
	INT32 m_MatchType;
public:
	void SetMatchType( INT32 v)
	{
		m_MatchType=v;
	}
	INT32 GetMatchType()
	{
		return m_MatchType;
	}
	INT32 GetMatchType() const
	{
		return m_MatchType;
	}
private:
	//EndTime
	int64_t m_EndTime;
public:
	void SetEndTime( int64_t v)
	{
		m_EndTime=v;
	}
	int64_t GetEndTime()
	{
		return m_EndTime;
	}
	int64_t GetEndTime() const
	{
		return m_EndTime;
	}

};
//帮会成员信息封装类
class GuildMemberInfoWraper
{
public:
	//构造函数
	GuildMemberInfoWraper()
	{
		
		m_OfficeType = -1;
		m_WeekContribute = -1;
		m_HistoryContribute = -1;
		m_TotalContribute = -1;
		m_WeekQuestCount = -1;
		m_WeekCampCount = -1;
		m_InTime = -1;
		m_GuildTinyInfo = GuildMemberTinyInfoWraper();
		m_LeaveTime = 0;
		m_IsVacation = false;
		m_IsForbiddenChat = false;

	}
	//赋值构造函数
	GuildMemberInfoWraper(const GuildMemberInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildMemberInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildMemberInfo ToPB() const
	{
		GuildMemberInfo v;
		v.set_officetype( m_OfficeType );
		v.set_weekcontribute( m_WeekContribute );
		v.set_historycontribute( m_HistoryContribute );
		v.set_totalcontribute( m_TotalContribute );
		v.set_weekquestcount( m_WeekQuestCount );
		v.set_weekcampcount( m_WeekCampCount );
		v.set_intime( m_InTime );
		*v.mutable_guildtinyinfo()= m_GuildTinyInfo.ToPB();
		v.set_leavetime( m_LeaveTime );
		v.set_isvacation( m_IsVacation );
		v.set_isforbiddenchat( m_IsForbiddenChat );

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
		GuildMemberInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildMemberInfo& v)
	{
		m_OfficeType = v.officetype();
		m_WeekContribute = v.weekcontribute();
		m_HistoryContribute = v.historycontribute();
		m_TotalContribute = v.totalcontribute();
		m_WeekQuestCount = v.weekquestcount();
		m_WeekCampCount = v.weekcampcount();
		m_InTime = v.intime();
		m_GuildTinyInfo = v.guildtinyinfo();
		m_LeaveTime = v.leavetime();
		m_IsVacation = v.isvacation();
		m_IsForbiddenChat = v.isforbiddenchat();

	}

private:
	//职务
	INT32 m_OfficeType;
public:
	void SetOfficeType( INT32 v)
	{
		m_OfficeType=v;
	}
	INT32 GetOfficeType()
	{
		return m_OfficeType;
	}
	INT32 GetOfficeType() const
	{
		return m_OfficeType;
	}
private:
	//本周帮贡
	INT32 m_WeekContribute;
public:
	void SetWeekContribute( INT32 v)
	{
		m_WeekContribute=v;
	}
	INT32 GetWeekContribute()
	{
		return m_WeekContribute;
	}
	INT32 GetWeekContribute() const
	{
		return m_WeekContribute;
	}
private:
	//历史帮贡
	INT32 m_HistoryContribute;
public:
	void SetHistoryContribute( INT32 v)
	{
		m_HistoryContribute=v;
	}
	INT32 GetHistoryContribute()
	{
		return m_HistoryContribute;
	}
	INT32 GetHistoryContribute() const
	{
		return m_HistoryContribute;
	}
private:
	//总帮贡
	INT32 m_TotalContribute;
public:
	void SetTotalContribute( INT32 v)
	{
		m_TotalContribute=v;
	}
	INT32 GetTotalContribute()
	{
		return m_TotalContribute;
	}
	INT32 GetTotalContribute() const
	{
		return m_TotalContribute;
	}
private:
	//本周内政
	INT32 m_WeekQuestCount;
public:
	void SetWeekQuestCount( INT32 v)
	{
		m_WeekQuestCount=v;
	}
	INT32 GetWeekQuestCount()
	{
		return m_WeekQuestCount;
	}
	INT32 GetWeekQuestCount() const
	{
		return m_WeekQuestCount;
	}
private:
	//本周内政
	INT32 m_WeekCampCount;
public:
	void SetWeekCampCount( INT32 v)
	{
		m_WeekCampCount=v;
	}
	INT32 GetWeekCampCount()
	{
		return m_WeekCampCount;
	}
	INT32 GetWeekCampCount() const
	{
		return m_WeekCampCount;
	}
private:
	//入会时间
	int64_t m_InTime;
public:
	void SetInTime( int64_t v)
	{
		m_InTime=v;
	}
	int64_t GetInTime()
	{
		return m_InTime;
	}
	int64_t GetInTime() const
	{
		return m_InTime;
	}
private:
	//成员简要信息
	GuildMemberTinyInfoWraper m_GuildTinyInfo;
public:
	void SetGuildTinyInfo( const GuildMemberTinyInfoWraper& v)
	{
		m_GuildTinyInfo=v;
	}
	GuildMemberTinyInfoWraper GetGuildTinyInfo()
	{
		return m_GuildTinyInfo;
	}
	GuildMemberTinyInfoWraper GetGuildTinyInfo() const
	{
		return m_GuildTinyInfo;
	}
private:
	//离线时间
	uint64_t m_LeaveTime;
public:
	void SetLeaveTime( uint64_t v)
	{
		m_LeaveTime=v;
	}
	uint64_t GetLeaveTime()
	{
		return m_LeaveTime;
	}
	uint64_t GetLeaveTime() const
	{
		return m_LeaveTime;
	}
private:
	//是否请假
	bool m_IsVacation;
public:
	void SetIsVacation( bool v)
	{
		m_IsVacation=v;
	}
	bool GetIsVacation()
	{
		return m_IsVacation;
	}
	bool GetIsVacation() const
	{
		return m_IsVacation;
	}
private:
	//是否被禁言
	bool m_IsForbiddenChat;
public:
	void SetIsForbiddenChat( bool v)
	{
		m_IsForbiddenChat=v;
	}
	bool GetIsForbiddenChat()
	{
		return m_IsForbiddenChat;
	}
	bool GetIsForbiddenChat() const
	{
		return m_IsForbiddenChat;
	}

};
//公会建筑贡献信息封装类
class GuildBuildingContributionInfoWraper
{
public:
	//构造函数
	GuildBuildingContributionInfoWraper()
	{
		
		m_Guid = 0;
		m_PlayerName = "";
		m_SpeedTime = -1;
		m_Date = 0;

	}
	//赋值构造函数
	GuildBuildingContributionInfoWraper(const GuildBuildingContributionInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildBuildingContributionInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildBuildingContributionInfo ToPB() const
	{
		GuildBuildingContributionInfo v;
		v.set_guid( m_Guid );
		v.set_playername( m_PlayerName );
		v.set_speedtime( m_SpeedTime );
		v.set_date( m_Date );

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
		GuildBuildingContributionInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildBuildingContributionInfo& v)
	{
		m_Guid = v.guid();
		m_PlayerName = v.playername();
		m_SpeedTime = v.speedtime();
		m_Date = v.date();

	}

private:
	//guid
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
	//玩家名字
	string m_PlayerName;
public:
	void SetPlayerName( const string& v)
	{
		m_PlayerName=v;
	}
	string GetPlayerName()
	{
		return m_PlayerName;
	}
	string GetPlayerName() const
	{
		return m_PlayerName;
	}
private:
	//加速时长
	INT32 m_SpeedTime;
public:
	void SetSpeedTime( INT32 v)
	{
		m_SpeedTime=v;
	}
	INT32 GetSpeedTime()
	{
		return m_SpeedTime;
	}
	INT32 GetSpeedTime() const
	{
		return m_SpeedTime;
	}
private:
	//加速日期
	uint64_t m_Date;
public:
	void SetDate( uint64_t v)
	{
		m_Date=v;
	}
	uint64_t GetDate()
	{
		return m_Date;
	}
	uint64_t GetDate() const
	{
		return m_Date;
	}

};
//职业权限封装类
class GuildOfficeJurisdictionWraper
{
public:
	//构造函数
	GuildOfficeJurisdictionWraper()
	{
		
		m_OfficeType = -1;

	}
	//赋值构造函数
	GuildOfficeJurisdictionWraper(const GuildOfficeJurisdiction& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildOfficeJurisdiction& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildOfficeJurisdiction ToPB() const
	{
		GuildOfficeJurisdiction v;
		v.set_officetype( m_OfficeType );
		v.mutable_jurisdictionlist()->Reserve(m_JurisdictionList.size());
		for (int i=0; i<(int)m_JurisdictionList.size(); i++)
		{
			*v.add_jurisdictionlist() = m_JurisdictionList[i].ToPB();
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
		GuildOfficeJurisdiction pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildOfficeJurisdiction& v)
	{
		m_OfficeType = v.officetype();
		m_JurisdictionList.clear();
		m_JurisdictionList.reserve(v.jurisdictionlist_size());
		for( int i=0; i<v.jurisdictionlist_size(); i++)
			m_JurisdictionList.push_back(v.jurisdictionlist(i));

	}

private:
	//职位枚举
	INT32 m_OfficeType;
public:
	void SetOfficeType( INT32 v)
	{
		m_OfficeType=v;
	}
	INT32 GetOfficeType()
	{
		return m_OfficeType;
	}
	INT32 GetOfficeType() const
	{
		return m_OfficeType;
	}
private:
	//权力列表
	vector<GuildJurisdictionWraper> m_JurisdictionList;
public:
	int SizeJurisdictionList()
	{
		return m_JurisdictionList.size();
	}
	const vector<GuildJurisdictionWraper>& GetJurisdictionList() const
	{
		return m_JurisdictionList;
	}
	GuildJurisdictionWraper GetJurisdictionList(int Index) const
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.size())
		{
			assert(false);
			return GuildJurisdictionWraper();
		}
		return m_JurisdictionList[Index];
	}
	void SetJurisdictionList( const vector<GuildJurisdictionWraper>& v )
	{
		m_JurisdictionList=v;
	}
	void ClearJurisdictionList( )
	{
		m_JurisdictionList.clear();
	}
	void SetJurisdictionList( int Index, const GuildJurisdictionWraper& v )
	{
		if(Index<0 || Index>=(int)m_JurisdictionList.size())
		{
			assert(false);
			return;
		}
		m_JurisdictionList[Index] = v;
	}
	void AddJurisdictionList( const GuildJurisdictionWraper& v )
	{
		m_JurisdictionList.push_back(v);
	}

};
//请假信息封装类
class GuildVacationInfoWraper
{
public:
	//构造函数
	GuildVacationInfoWraper()
	{
		
		m_Guid = 0;
		m_PlayerName = "";
		m_Level = -1;
		m_Reason = "";
		m_LeftTime = 0;

	}
	//赋值构造函数
	GuildVacationInfoWraper(const GuildVacationInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildVacationInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildVacationInfo ToPB() const
	{
		GuildVacationInfo v;
		v.set_guid( m_Guid );
		v.set_playername( m_PlayerName );
		v.set_level( m_Level );
		v.set_reason( m_Reason );
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
		GuildVacationInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildVacationInfo& v)
	{
		m_Guid = v.guid();
		m_PlayerName = v.playername();
		m_Level = v.level();
		m_Reason = v.reason();
		m_LeftTime = v.lefttime();

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
	//玩家名字
	string m_PlayerName;
public:
	void SetPlayerName( const string& v)
	{
		m_PlayerName=v;
	}
	string GetPlayerName()
	{
		return m_PlayerName;
	}
	string GetPlayerName() const
	{
		return m_PlayerName;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//请假理由
	string m_Reason;
public:
	void SetReason( const string& v)
	{
		m_Reason=v;
	}
	string GetReason()
	{
		return m_Reason;
	}
	string GetReason() const
	{
		return m_Reason;
	}
private:
	//审批倒计时
	uint64_t m_LeftTime;
public:
	void SetLeftTime( uint64_t v)
	{
		m_LeftTime=v;
	}
	uint64_t GetLeftTime()
	{
		return m_LeftTime;
	}
	uint64_t GetLeftTime() const
	{
		return m_LeftTime;
	}

};
//公会建筑信息封装类
class GuildBuildingInfoWraper
{
public:
	//构造函数
	GuildBuildingInfoWraper()
	{
		
		m_BuildingType = -1;
		m_BuildingLv = -1;
		m_LeftTime = 0;

	}
	//赋值构造函数
	GuildBuildingInfoWraper(const GuildBuildingInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const GuildBuildingInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GuildBuildingInfo ToPB() const
	{
		GuildBuildingInfo v;
		v.set_buildingtype( m_BuildingType );
		v.set_buildinglv( m_BuildingLv );
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
		GuildBuildingInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const GuildBuildingInfo& v)
	{
		m_BuildingType = v.buildingtype();
		m_BuildingLv = v.buildinglv();
		m_LeftTime = v.lefttime();

	}

private:
	//建筑类型
	INT32 m_BuildingType;
public:
	void SetBuildingType( INT32 v)
	{
		m_BuildingType=v;
	}
	INT32 GetBuildingType()
	{
		return m_BuildingType;
	}
	INT32 GetBuildingType() const
	{
		return m_BuildingType;
	}
private:
	//建筑等级
	INT32 m_BuildingLv;
public:
	void SetBuildingLv( INT32 v)
	{
		m_BuildingLv=v;
	}
	INT32 GetBuildingLv()
	{
		return m_BuildingLv;
	}
	INT32 GetBuildingLv() const
	{
		return m_BuildingLv;
	}
private:
	//升级剩余时间
	uint64_t m_LeftTime;
public:
	void SetLeftTime( uint64_t v)
	{
		m_LeftTime=v;
	}
	uint64_t GetLeftTime()
	{
		return m_LeftTime;
	}
	uint64_t GetLeftTime() const
	{
		return m_LeftTime;
	}

};
//最大任务列表封装类
class QuestMaxQuestListWraper
{
public:
	//构造函数
	QuestMaxQuestListWraper()
	{
		

	}
	//赋值构造函数
	QuestMaxQuestListWraper(const QuestMaxQuestList& v){ Init(v); }
	//等号重载函数
	void operator = (const QuestMaxQuestList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	QuestMaxQuestList ToPB() const
	{
		QuestMaxQuestList v;
		v.mutable_questlist()->Reserve(m_QuestList.size());
		for (int i=0; i<(int)m_QuestList.size(); i++)
		{
			*v.add_questlist() = m_QuestList[i].ToPB();
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
		QuestMaxQuestList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const QuestMaxQuestList& v)
	{
		m_QuestList.clear();
		m_QuestList.reserve(v.questlist_size());
		for( int i=0; i<v.questlist_size(); i++)
			m_QuestList.push_back(v.questlist(i));

	}

private:
	//最大任务列表
	vector<CompletedQuestListWraper> m_QuestList;
public:
	int SizeQuestList()
	{
		return m_QuestList.size();
	}
	const vector<CompletedQuestListWraper>& GetQuestList() const
	{
		return m_QuestList;
	}
	CompletedQuestListWraper GetQuestList(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return CompletedQuestListWraper();
		}
		return m_QuestList[Index];
	}
	void SetQuestList( const vector<CompletedQuestListWraper>& v )
	{
		m_QuestList=v;
	}
	void ClearQuestList( )
	{
		m_QuestList.clear();
	}
	void SetQuestList( int Index, const CompletedQuestListWraper& v )
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return;
		}
		m_QuestList[Index] = v;
	}
	void AddQuestList( const CompletedQuestListWraper& v )
	{
		m_QuestList.push_back(v);
	}

};
//今日在线福利信息封装类
class OnlineInfoWraper
{
public:
	//构造函数
	OnlineInfoWraper()
	{
		
		m_ID = -1;
		m_State = false;
		m_RewardInfo = WelfareRewardWraper();

	}
	//赋值构造函数
	OnlineInfoWraper(const OnlineInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const OnlineInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	OnlineInfo ToPB() const
	{
		OnlineInfo v;
		v.set_id( m_ID );
		v.set_state( m_State );
		*v.mutable_rewardinfo()= m_RewardInfo.ToPB();

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
		OnlineInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const OnlineInfo& v)
	{
		m_ID = v.id();
		m_State = v.state();
		m_RewardInfo = v.rewardinfo();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//是否已领取
	bool m_State;
public:
	void SetState( bool v)
	{
		m_State=v;
	}
	bool GetState()
	{
		return m_State;
	}
	bool GetState() const
	{
		return m_State;
	}
private:
	//奖励信息
	WelfareRewardWraper m_RewardInfo;
public:
	void SetRewardInfo( const WelfareRewardWraper& v)
	{
		m_RewardInfo=v;
	}
	WelfareRewardWraper GetRewardInfo()
	{
		return m_RewardInfo;
	}
	WelfareRewardWraper GetRewardInfo() const
	{
		return m_RewardInfo;
	}

};
//等级福利信息封装类
class LevelInfoWraper
{
public:
	//构造函数
	LevelInfoWraper()
	{
		
		m_ID = -1;
		m_State = false;

	}
	//赋值构造函数
	LevelInfoWraper(const LevelInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const LevelInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LevelInfo ToPB() const
	{
		LevelInfo v;
		v.set_id( m_ID );
		v.set_state( m_State );
		v.mutable_rewardinfo()->Reserve(m_RewardInfo.size());
		for (int i=0; i<(int)m_RewardInfo.size(); i++)
		{
			*v.add_rewardinfo() = m_RewardInfo[i].ToPB();
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
		LevelInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const LevelInfo& v)
	{
		m_ID = v.id();
		m_State = v.state();
		m_RewardInfo.clear();
		m_RewardInfo.reserve(v.rewardinfo_size());
		for( int i=0; i<v.rewardinfo_size(); i++)
			m_RewardInfo.push_back(v.rewardinfo(i));

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//是否已领取
	bool m_State;
public:
	void SetState( bool v)
	{
		m_State=v;
	}
	bool GetState()
	{
		return m_State;
	}
	bool GetState() const
	{
		return m_State;
	}
private:
	//奖励信息
	vector<WelfareRewardWraper> m_RewardInfo;
public:
	int SizeRewardInfo()
	{
		return m_RewardInfo.size();
	}
	const vector<WelfareRewardWraper>& GetRewardInfo() const
	{
		return m_RewardInfo;
	}
	WelfareRewardWraper GetRewardInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardInfo.size())
		{
			assert(false);
			return WelfareRewardWraper();
		}
		return m_RewardInfo[Index];
	}
	void SetRewardInfo( const vector<WelfareRewardWraper>& v )
	{
		m_RewardInfo=v;
	}
	void ClearRewardInfo( )
	{
		m_RewardInfo.clear();
	}
	void SetRewardInfo( int Index, const WelfareRewardWraper& v )
	{
		if(Index<0 || Index>=(int)m_RewardInfo.size())
		{
			assert(false);
			return;
		}
		m_RewardInfo[Index] = v;
	}
	void AddRewardInfo( const WelfareRewardWraper& v )
	{
		m_RewardInfo.push_back(v);
	}

};
//签到福利信息封装类
class MonthSignInInfoWraper
{
public:
	//构造函数
	MonthSignInInfoWraper()
	{
		
		m_ID = -1;
		m_State = false;
		m_RewardInfo = WelfareRewardWraper();

	}
	//赋值构造函数
	MonthSignInInfoWraper(const MonthSignInInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MonthSignInInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MonthSignInInfo ToPB() const
	{
		MonthSignInInfo v;
		v.set_id( m_ID );
		v.set_state( m_State );
		*v.mutable_rewardinfo()= m_RewardInfo.ToPB();

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
		MonthSignInInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MonthSignInInfo& v)
	{
		m_ID = v.id();
		m_State = v.state();
		m_RewardInfo = v.rewardinfo();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//是否已领取
	bool m_State;
public:
	void SetState( bool v)
	{
		m_State=v;
	}
	bool GetState()
	{
		return m_State;
	}
	bool GetState() const
	{
		return m_State;
	}
private:
	//奖励信息
	WelfareRewardWraper m_RewardInfo;
public:
	void SetRewardInfo( const WelfareRewardWraper& v)
	{
		m_RewardInfo=v;
	}
	WelfareRewardWraper GetRewardInfo()
	{
		return m_RewardInfo;
	}
	WelfareRewardWraper GetRewardInfo() const
	{
		return m_RewardInfo;
	}

};
//累计登陆福利信息封装类
class AccumulateSignInfoWraper
{
public:
	//构造函数
	AccumulateSignInfoWraper()
	{
		
		m_ID = -1;
		m_State = false;
		m_RewardInfo = WelfareRewardWraper();

	}
	//赋值构造函数
	AccumulateSignInfoWraper(const AccumulateSignInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const AccumulateSignInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AccumulateSignInfo ToPB() const
	{
		AccumulateSignInfo v;
		v.set_id( m_ID );
		v.set_state( m_State );
		*v.mutable_rewardinfo()= m_RewardInfo.ToPB();

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
		AccumulateSignInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AccumulateSignInfo& v)
	{
		m_ID = v.id();
		m_State = v.state();
		m_RewardInfo = v.rewardinfo();

	}

private:
	//ID
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//是否已领取
	bool m_State;
public:
	void SetState( bool v)
	{
		m_State=v;
	}
	bool GetState()
	{
		return m_State;
	}
	bool GetState() const
	{
		return m_State;
	}
private:
	//奖励信息
	WelfareRewardWraper m_RewardInfo;
public:
	void SetRewardInfo( const WelfareRewardWraper& v)
	{
		m_RewardInfo=v;
	}
	WelfareRewardWraper GetRewardInfo()
	{
		return m_RewardInfo;
	}
	WelfareRewardWraper GetRewardInfo() const
	{
		return m_RewardInfo;
	}

};
//场景状态封装类
class SceneStatsWraper
{
public:
	//构造函数
	SceneStatsWraper()
	{
		
		m_SceneId = -1;

	}
	//赋值构造函数
	SceneStatsWraper(const SceneStats& v){ Init(v); }
	//等号重载函数
	void operator = (const SceneStats& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SceneStats ToPB() const
	{
		SceneStats v;
		v.mutable_lines()->Reserve(m_Lines.size());
		for (int i=0; i<(int)m_Lines.size(); i++)
		{
			*v.add_lines() = m_Lines[i].ToPB();
		}
		v.set_sceneid( m_SceneId );

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
		SceneStats pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SceneStats& v)
	{
		m_Lines.clear();
		m_Lines.reserve(v.lines_size());
		for( int i=0; i<v.lines_size(); i++)
			m_Lines.push_back(v.lines(i));
		m_SceneId = v.sceneid();

	}

private:
	//场景下线的状态
	vector<LineStatsWraper> m_Lines;
public:
	int SizeLines()
	{
		return m_Lines.size();
	}
	const vector<LineStatsWraper>& GetLines() const
	{
		return m_Lines;
	}
	LineStatsWraper GetLines(int Index) const
	{
		if(Index<0 || Index>=(int)m_Lines.size())
		{
			assert(false);
			return LineStatsWraper();
		}
		return m_Lines[Index];
	}
	void SetLines( const vector<LineStatsWraper>& v )
	{
		m_Lines=v;
	}
	void ClearLines( )
	{
		m_Lines.clear();
	}
	void SetLines( int Index, const LineStatsWraper& v )
	{
		if(Index<0 || Index>=(int)m_Lines.size())
		{
			assert(false);
			return;
		}
		m_Lines[Index] = v;
	}
	void AddLines( const LineStatsWraper& v )
	{
		m_Lines.push_back(v);
	}
private:
	//场景Id
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

};
//副本BOSS挑战信息封装类
class DungeonBossInfoWraper
{
public:
	//构造函数
	DungeonBossInfoWraper()
	{
		
		m_Bossid = -1;
		m_Number = -1;
		m_Dungeonid = -1;
		m_MaxNumber = -1;
		m_RefreshType = -1;
		m_HoldNum = 0;
		m_Killed = 0;
		m_DungeonType = -1;
		m_BossIndex = -1;

	}
	//赋值构造函数
	DungeonBossInfoWraper(const DungeonBossInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonBossInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonBossInfo ToPB() const
	{
		DungeonBossInfo v;
		v.set_bossid( m_Bossid );
		v.set_number( m_Number );
		v.set_dungeonid( m_Dungeonid );
		v.set_maxnumber( m_MaxNumber );
		v.set_refreshtype( m_RefreshType );
		v.set_holdnum( m_HoldNum );
		v.set_killed( m_Killed );
		v.set_dungeontype( m_DungeonType );
		v.set_bossindex( m_BossIndex );

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
		DungeonBossInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DungeonBossInfo& v)
	{
		m_Bossid = v.bossid();
		m_Number = v.number();
		m_Dungeonid = v.dungeonid();
		m_MaxNumber = v.maxnumber();
		m_RefreshType = v.refreshtype();
		m_HoldNum = v.holdnum();
		m_Killed = v.killed();
		m_DungeonType = v.dungeontype();
		m_BossIndex = v.bossindex();

	}

private:
	//BOSSID
	INT32 m_Bossid;
public:
	void SetBossid( INT32 v)
	{
		m_Bossid=v;
	}
	INT32 GetBossid()
	{
		return m_Bossid;
	}
	INT32 GetBossid() const
	{
		return m_Bossid;
	}
private:
	//BOSS挑战次数
	INT32 m_Number;
public:
	void SetNumber( INT32 v)
	{
		m_Number=v;
	}
	INT32 GetNumber()
	{
		return m_Number;
	}
	INT32 GetNumber() const
	{
		return m_Number;
	}
private:
	//副本ID
	INT32 m_Dungeonid;
public:
	void SetDungeonid( INT32 v)
	{
		m_Dungeonid=v;
	}
	INT32 GetDungeonid()
	{
		return m_Dungeonid;
	}
	INT32 GetDungeonid() const
	{
		return m_Dungeonid;
	}
private:
	//挑战最大次数
	INT32 m_MaxNumber;
public:
	void SetMaxNumber( INT32 v)
	{
		m_MaxNumber=v;
	}
	INT32 GetMaxNumber()
	{
		return m_MaxNumber;
	}
	INT32 GetMaxNumber() const
	{
		return m_MaxNumber;
	}
private:
	//刷新类型
	INT32 m_RefreshType;
public:
	void SetRefreshType( INT32 v)
	{
		m_RefreshType=v;
	}
	INT32 GetRefreshType()
	{
		return m_RefreshType;
	}
	INT32 GetRefreshType() const
	{
		return m_RefreshType;
	}
private:
	//找回次数
	INT32 m_HoldNum;
public:
	void SetHoldNum( INT32 v)
	{
		m_HoldNum=v;
	}
	INT32 GetHoldNum()
	{
		return m_HoldNum;
	}
	INT32 GetHoldNum() const
	{
		return m_HoldNum;
	}
private:
	//击杀标记
	INT32 m_Killed;
public:
	void SetKilled( INT32 v)
	{
		m_Killed=v;
	}
	INT32 GetKilled()
	{
		return m_Killed;
	}
	INT32 GetKilled() const
	{
		return m_Killed;
	}
private:
	//副本类型
	INT32 m_DungeonType;
public:
	void SetDungeonType( INT32 v)
	{
		m_DungeonType=v;
	}
	INT32 GetDungeonType()
	{
		return m_DungeonType;
	}
	INT32 GetDungeonType() const
	{
		return m_DungeonType;
	}
private:
	//BOSS次序
	INT32 m_BossIndex;
public:
	void SetBossIndex( INT32 v)
	{
		m_BossIndex=v;
	}
	INT32 GetBossIndex()
	{
		return m_BossIndex;
	}
	INT32 GetBossIndex() const
	{
		return m_BossIndex;
	}

};
//技能位置信息封装类
class SkillPosInfoWraper
{
public:
	//构造函数
	SkillPosInfoWraper()
	{
		
		m_Pos = -1;
		m_CurLevel = -1;

	}
	//赋值构造函数
	SkillPosInfoWraper(const SkillPosInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const SkillPosInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SkillPosInfo ToPB() const
	{
		SkillPosInfo v;
		v.set_pos( m_Pos );
		v.set_curlevel( m_CurLevel );

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
		SkillPosInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SkillPosInfo& v)
	{
		m_Pos = v.pos();
		m_CurLevel = v.curlevel();

	}

private:
	//技能位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}
private:
	//技能位置当前等级
	INT32 m_CurLevel;
public:
	void SetCurLevel( INT32 v)
	{
		m_CurLevel=v;
	}
	INT32 GetCurLevel()
	{
		return m_CurLevel;
	}
	INT32 GetCurLevel() const
	{
		return m_CurLevel;
	}

};
//交易记录详细封装类
class AuctionRecDetailWraper
{
public:
	//构造函数
	AuctionRecDetailWraper()
	{
		
		m_BuyGuid = 0;
		m_SoldTS = -1;
		m_AuctionItem = AuctionItemWraper();
		m_IsGot = false;
		m_Cost = -1;
		m_Tax = -1;
		m_Currency = -1;
		m_RecGuid = 0;
		m_NewItemGuid = false;
		m_SoldType = -1;

	}
	//赋值构造函数
	AuctionRecDetailWraper(const AuctionRecDetail& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionRecDetail& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionRecDetail ToPB() const
	{
		AuctionRecDetail v;
		v.set_buyguid( m_BuyGuid );
		v.set_soldts( m_SoldTS );
		*v.mutable_auctionitem()= m_AuctionItem.ToPB();
		v.set_isgot( m_IsGot );
		v.set_cost( m_Cost );
		v.set_tax( m_Tax );
		v.set_currency( m_Currency );
		v.set_recguid( m_RecGuid );
		v.set_newitemguid( m_NewItemGuid );
		v.set_soldtype( m_SoldType );

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
		AuctionRecDetail pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AuctionRecDetail& v)
	{
		m_BuyGuid = v.buyguid();
		m_SoldTS = v.soldts();
		m_AuctionItem = v.auctionitem();
		m_IsGot = v.isgot();
		m_Cost = v.cost();
		m_Tax = v.tax();
		m_Currency = v.currency();
		m_RecGuid = v.recguid();
		m_NewItemGuid = v.newitemguid();
		m_SoldType = v.soldtype();

	}

private:
	//购买人guid
	uint64_t m_BuyGuid;
public:
	void SetBuyGuid( uint64_t v)
	{
		m_BuyGuid=v;
	}
	uint64_t GetBuyGuid()
	{
		return m_BuyGuid;
	}
	uint64_t GetBuyGuid() const
	{
		return m_BuyGuid;
	}
private:
	//购买时间
	INT32 m_SoldTS;
public:
	void SetSoldTS( INT32 v)
	{
		m_SoldTS=v;
	}
	INT32 GetSoldTS()
	{
		return m_SoldTS;
	}
	INT32 GetSoldTS() const
	{
		return m_SoldTS;
	}
private:
	//商品信息
	AuctionItemWraper m_AuctionItem;
public:
	void SetAuctionItem( const AuctionItemWraper& v)
	{
		m_AuctionItem=v;
	}
	AuctionItemWraper GetAuctionItem()
	{
		return m_AuctionItem;
	}
	AuctionItemWraper GetAuctionItem() const
	{
		return m_AuctionItem;
	}
private:
	//商品是否交付
	bool m_IsGot;
public:
	void SetIsGot( bool v)
	{
		m_IsGot=v;
	}
	bool GetIsGot()
	{
		return m_IsGot;
	}
	bool GetIsGot() const
	{
		return m_IsGot;
	}
private:
	//花费
	INT32 m_Cost;
public:
	void SetCost( INT32 v)
	{
		m_Cost=v;
	}
	INT32 GetCost()
	{
		return m_Cost;
	}
	INT32 GetCost() const
	{
		return m_Cost;
	}
private:
	//税
	INT32 m_Tax;
public:
	void SetTax( INT32 v)
	{
		m_Tax=v;
	}
	INT32 GetTax()
	{
		return m_Tax;
	}
	INT32 GetTax() const
	{
		return m_Tax;
	}
private:
	//货币种类
	INT32 m_Currency;
public:
	void SetCurrency( INT32 v)
	{
		m_Currency=v;
	}
	INT32 GetCurrency()
	{
		return m_Currency;
	}
	INT32 GetCurrency() const
	{
		return m_Currency;
	}
private:
	//RecGuid
	uint64_t m_RecGuid;
public:
	void SetRecGuid( uint64_t v)
	{
		m_RecGuid=v;
	}
	uint64_t GetRecGuid()
	{
		return m_RecGuid;
	}
	uint64_t GetRecGuid() const
	{
		return m_RecGuid;
	}
private:
	//商品获得时是不是新guid
	bool m_NewItemGuid;
public:
	void SetNewItemGuid( bool v)
	{
		m_NewItemGuid=v;
	}
	bool GetNewItemGuid()
	{
		return m_NewItemGuid;
	}
	bool GetNewItemGuid() const
	{
		return m_NewItemGuid;
	}
private:
	//买还是卖
	INT32 m_SoldType;
public:
	void SetSoldType( INT32 v)
	{
		m_SoldType=v;
	}
	INT32 GetSoldType()
	{
		return m_SoldType;
	}
	INT32 GetSoldType() const
	{
		return m_SoldType;
	}

};
//装备槽星封装类
class EquipSlotStarInfoWraper
{
public:
	//构造函数
	EquipSlotStarInfoWraper()
	{
		
		m_RankUp_Level = -1;
		m_Slot_Type = -1;
		m_BattleScore = -1;
		m_NextBattleScore = -1;

	}
	//赋值构造函数
	EquipSlotStarInfoWraper(const EquipSlotStarInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipSlotStarInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipSlotStarInfo ToPB() const
	{
		EquipSlotStarInfo v;
		v.set_rankup_level( m_RankUp_Level );
		v.set_slot_type( m_Slot_Type );
		v.set_battlescore( m_BattleScore );
		v.set_nextbattlescore( m_NextBattleScore );

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
		EquipSlotStarInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipSlotStarInfo& v)
	{
		m_RankUp_Level = v.rankup_level();
		m_Slot_Type = v.slot_type();
		m_BattleScore = v.battlescore();
		m_NextBattleScore = v.nextbattlescore();

	}

private:
	//星级
	INT32 m_RankUp_Level;
public:
	void SetRankUp_Level( INT32 v)
	{
		m_RankUp_Level=v;
	}
	INT32 GetRankUp_Level()
	{
		return m_RankUp_Level;
	}
	INT32 GetRankUp_Level() const
	{
		return m_RankUp_Level;
	}
private:
	//装备槽类型
	INT32 m_Slot_Type;
public:
	void SetSlot_Type( INT32 v)
	{
		m_Slot_Type=v;
	}
	INT32 GetSlot_Type()
	{
		return m_Slot_Type;
	}
	INT32 GetSlot_Type() const
	{
		return m_Slot_Type;
	}
private:
	//战斗力
	INT32 m_BattleScore;
public:
	void SetBattleScore( INT32 v)
	{
		m_BattleScore=v;
	}
	INT32 GetBattleScore()
	{
		return m_BattleScore;
	}
	INT32 GetBattleScore() const
	{
		return m_BattleScore;
	}
private:
	//高一星战斗力
	INT32 m_NextBattleScore;
public:
	void SetNextBattleScore( INT32 v)
	{
		m_NextBattleScore=v;
	}
	INT32 GetNextBattleScore()
	{
		return m_NextBattleScore;
	}
	INT32 GetNextBattleScore() const
	{
		return m_NextBattleScore;
	}

};
//星耀信息封装类
class StarBattleInfoWraper
{
public:
	//构造函数
	StarBattleInfoWraper()
	{
		
		m_ServerFast = StarBattleTeamInfoWraper();
		m_ServerFirst = StarBattleTeamInfoWraper();
		m_ServerWeekFast = StarBattleTeamInfoWraper();
		m_Id = -1;
		m_Npcid = -1;
		m_LeftCount = -1;
		m_Incount = 0;
		m_Wincount = 0;
		m_Npcindex = -1;

	}
	//赋值构造函数
	StarBattleInfoWraper(const StarBattleInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const StarBattleInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StarBattleInfo ToPB() const
	{
		StarBattleInfo v;
		*v.mutable_serverfast()= m_ServerFast.ToPB();
		*v.mutable_serverfirst()= m_ServerFirst.ToPB();
		*v.mutable_serverweekfast()= m_ServerWeekFast.ToPB();
		v.set_id( m_Id );
		v.set_npcid( m_Npcid );
		v.set_leftcount( m_LeftCount );
		v.set_incount( m_Incount );
		v.set_wincount( m_Wincount );
		v.set_npcindex( m_Npcindex );

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
		StarBattleInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const StarBattleInfo& v)
	{
		m_ServerFast = v.serverfast();
		m_ServerFirst = v.serverfirst();
		m_ServerWeekFast = v.serverweekfast();
		m_Id = v.id();
		m_Npcid = v.npcid();
		m_LeftCount = v.leftcount();
		m_Incount = v.incount();
		m_Wincount = v.wincount();
		m_Npcindex = v.npcindex();

	}

private:
	//本服最快通关(不用了)
	StarBattleTeamInfoWraper m_ServerFast;
public:
	void SetServerFast( const StarBattleTeamInfoWraper& v)
	{
		m_ServerFast=v;
	}
	StarBattleTeamInfoWraper GetServerFast()
	{
		return m_ServerFast;
	}
	StarBattleTeamInfoWraper GetServerFast() const
	{
		return m_ServerFast;
	}
private:
	//本服首通(不用了)
	StarBattleTeamInfoWraper m_ServerFirst;
public:
	void SetServerFirst( const StarBattleTeamInfoWraper& v)
	{
		m_ServerFirst=v;
	}
	StarBattleTeamInfoWraper GetServerFirst()
	{
		return m_ServerFirst;
	}
	StarBattleTeamInfoWraper GetServerFirst() const
	{
		return m_ServerFirst;
	}
private:
	//本周最快(不用了)
	StarBattleTeamInfoWraper m_ServerWeekFast;
public:
	void SetServerWeekFast( const StarBattleTeamInfoWraper& v)
	{
		m_ServerWeekFast=v;
	}
	StarBattleTeamInfoWraper GetServerWeekFast()
	{
		return m_ServerWeekFast;
	}
	StarBattleTeamInfoWraper GetServerWeekFast() const
	{
		return m_ServerWeekFast;
	}
private:
	//id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//NPCID
	INT32 m_Npcid;
public:
	void SetNpcid( INT32 v)
	{
		m_Npcid=v;
	}
	INT32 GetNpcid()
	{
		return m_Npcid;
	}
	INT32 GetNpcid() const
	{
		return m_Npcid;
	}
private:
	//星耀剩余次数（不用了）
	INT32 m_LeftCount;
public:
	void SetLeftCount( INT32 v)
	{
		m_LeftCount=v;
	}
	INT32 GetLeftCount()
	{
		return m_LeftCount;
	}
	INT32 GetLeftCount() const
	{
		return m_LeftCount;
	}
private:
	//当前进入镜像的队伍数
	INT32 m_Incount;
public:
	void SetIncount( INT32 v)
	{
		m_Incount=v;
	}
	INT32 GetIncount()
	{
		return m_Incount;
	}
	INT32 GetIncount() const
	{
		return m_Incount;
	}
private:
	//已经胜利的队伍数
	INT32 m_Wincount;
public:
	void SetWincount( INT32 v)
	{
		m_Wincount=v;
	}
	INT32 GetWincount()
	{
		return m_Wincount;
	}
	INT32 GetWincount() const
	{
		return m_Wincount;
	}
private:
	//第几个NPC
	INT32 m_Npcindex;
public:
	void SetNpcindex( INT32 v)
	{
		m_Npcindex=v;
	}
	INT32 GetNpcindex()
	{
		return m_Npcindex;
	}
	INT32 GetNpcindex() const
	{
		return m_Npcindex;
	}

};
//邮件信息封装类
class MailInfoWraper
{
public:
	//构造函数
	MailInfoWraper()
	{
		
		m_Mail_type = 0;
		m_Mail_id = 0;
		m_IsRead = false;
		m_IsGet = false;
		m_Title = AppendStringWraper();
		m_Salutation = AppendStringWraper();
		m_Content = AppendStringWraper();
		m_Sender_name = AppendStringWraper();
		m_Sender_id = 0;
		m_Start_time = -1;
		m_Expire_time = -1;
		m_Receiver_id = 0;

	}
	//赋值构造函数
	MailInfoWraper(const MailInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MailInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MailInfo ToPB() const
	{
		MailInfo v;
		v.set_mail_type( m_Mail_type );
		v.set_mail_id( m_Mail_id );
		v.set_isread( m_IsRead );
		v.set_isget( m_IsGet );
		*v.mutable_title()= m_Title.ToPB();
		*v.mutable_salutation()= m_Salutation.ToPB();
		*v.mutable_content()= m_Content.ToPB();
		*v.mutable_sender_name()= m_Sender_name.ToPB();
		v.mutable_itemlist()->Reserve(m_ItemList.size());
		for (int i=0; i<(int)m_ItemList.size(); i++)
		{
			*v.add_itemlist() = m_ItemList[i].ToPB();
		}
		v.set_sender_id( m_Sender_id );
		v.set_start_time( m_Start_time );
		v.set_expire_time( m_Expire_time );
		v.set_receiver_id( m_Receiver_id );

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
		MailInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MailInfo& v)
	{
		m_Mail_type = v.mail_type();
		m_Mail_id = v.mail_id();
		m_IsRead = v.isread();
		m_IsGet = v.isget();
		m_Title = v.title();
		m_Salutation = v.salutation();
		m_Content = v.content();
		m_Sender_name = v.sender_name();
		m_ItemList.clear();
		m_ItemList.reserve(v.itemlist_size());
		for( int i=0; i<v.itemlist_size(); i++)
			m_ItemList.push_back(v.itemlist(i));
		m_Sender_id = v.sender_id();
		m_Start_time = v.start_time();
		m_Expire_time = v.expire_time();
		m_Receiver_id = v.receiver_id();

	}

private:
	//邮件类型
	INT32 m_Mail_type;
public:
	void SetMail_type( INT32 v)
	{
		m_Mail_type=v;
	}
	INT32 GetMail_type()
	{
		return m_Mail_type;
	}
	INT32 GetMail_type() const
	{
		return m_Mail_type;
	}
private:
	//邮件id
	INT32 m_Mail_id;
public:
	void SetMail_id( INT32 v)
	{
		m_Mail_id=v;
	}
	INT32 GetMail_id()
	{
		return m_Mail_id;
	}
	INT32 GetMail_id() const
	{
		return m_Mail_id;
	}
private:
	//已读
	bool m_IsRead;
public:
	void SetIsRead( bool v)
	{
		m_IsRead=v;
	}
	bool GetIsRead()
	{
		return m_IsRead;
	}
	bool GetIsRead() const
	{
		return m_IsRead;
	}
private:
	//已领
	bool m_IsGet;
public:
	void SetIsGet( bool v)
	{
		m_IsGet=v;
	}
	bool GetIsGet()
	{
		return m_IsGet;
	}
	bool GetIsGet() const
	{
		return m_IsGet;
	}
private:
	//标题
	AppendStringWraper m_Title;
public:
	void SetTitle( const AppendStringWraper& v)
	{
		m_Title=v;
	}
	AppendStringWraper GetTitle()
	{
		return m_Title;
	}
	AppendStringWraper GetTitle() const
	{
		return m_Title;
	}
private:
	//称呼
	AppendStringWraper m_Salutation;
public:
	void SetSalutation( const AppendStringWraper& v)
	{
		m_Salutation=v;
	}
	AppendStringWraper GetSalutation()
	{
		return m_Salutation;
	}
	AppendStringWraper GetSalutation() const
	{
		return m_Salutation;
	}
private:
	//内容
	AppendStringWraper m_Content;
public:
	void SetContent( const AppendStringWraper& v)
	{
		m_Content=v;
	}
	AppendStringWraper GetContent()
	{
		return m_Content;
	}
	AppendStringWraper GetContent() const
	{
		return m_Content;
	}
private:
	//发送人
	AppendStringWraper m_Sender_name;
public:
	void SetSender_name( const AppendStringWraper& v)
	{
		m_Sender_name=v;
	}
	AppendStringWraper GetSender_name()
	{
		return m_Sender_name;
	}
	AppendStringWraper GetSender_name() const
	{
		return m_Sender_name;
	}
private:
	//物品id列表
	vector<MailItemWraper> m_ItemList;
public:
	int SizeItemList()
	{
		return m_ItemList.size();
	}
	const vector<MailItemWraper>& GetItemList() const
	{
		return m_ItemList;
	}
	MailItemWraper GetItemList(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return MailItemWraper();
		}
		return m_ItemList[Index];
	}
	void SetItemList( const vector<MailItemWraper>& v )
	{
		m_ItemList=v;
	}
	void ClearItemList( )
	{
		m_ItemList.clear();
	}
	void SetItemList( int Index, const MailItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemList.size())
		{
			assert(false);
			return;
		}
		m_ItemList[Index] = v;
	}
	void AddItemList( const MailItemWraper& v )
	{
		m_ItemList.push_back(v);
	}
private:
	//发送角色id
	uint64_t m_Sender_id;
public:
	void SetSender_id( uint64_t v)
	{
		m_Sender_id=v;
	}
	uint64_t GetSender_id()
	{
		return m_Sender_id;
	}
	uint64_t GetSender_id() const
	{
		return m_Sender_id;
	}
private:
	//开始时间戳
	INT32 m_Start_time;
public:
	void SetStart_time( INT32 v)
	{
		m_Start_time=v;
	}
	INT32 GetStart_time()
	{
		return m_Start_time;
	}
	INT32 GetStart_time() const
	{
		return m_Start_time;
	}
private:
	//失效时间戳
	INT32 m_Expire_time;
public:
	void SetExpire_time( INT32 v)
	{
		m_Expire_time=v;
	}
	INT32 GetExpire_time()
	{
		return m_Expire_time;
	}
	INT32 GetExpire_time() const
	{
		return m_Expire_time;
	}
private:
	//接收角色id
	uint64_t m_Receiver_id;
public:
	void SetReceiver_id( uint64_t v)
	{
		m_Receiver_id=v;
	}
	uint64_t GetReceiver_id()
	{
		return m_Receiver_id;
	}
	uint64_t GetReceiver_id() const
	{
		return m_Receiver_id;
	}

};
//拼接字符串List封装类
class AppendStringListWraper
{
public:
	//构造函数
	AppendStringListWraper()
	{
		

	}
	//赋值构造函数
	AppendStringListWraper(const AppendStringList& v){ Init(v); }
	//等号重载函数
	void operator = (const AppendStringList& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AppendStringList ToPB() const
	{
		AppendStringList v;
		v.mutable_stringappendlist()->Reserve(m_StringAppendList.size());
		for (int i=0; i<(int)m_StringAppendList.size(); i++)
		{
			*v.add_stringappendlist() = m_StringAppendList[i].ToPB();
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
		AppendStringList pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AppendStringList& v)
	{
		m_StringAppendList.clear();
		m_StringAppendList.reserve(v.stringappendlist_size());
		for( int i=0; i<v.stringappendlist_size(); i++)
			m_StringAppendList.push_back(v.stringappendlist(i));

	}

private:
	//拼接字符串
	vector<AppendStringWraper> m_StringAppendList;
public:
	int SizeStringAppendList()
	{
		return m_StringAppendList.size();
	}
	const vector<AppendStringWraper>& GetStringAppendList() const
	{
		return m_StringAppendList;
	}
	AppendStringWraper GetStringAppendList(int Index) const
	{
		if(Index<0 || Index>=(int)m_StringAppendList.size())
		{
			assert(false);
			return AppendStringWraper();
		}
		return m_StringAppendList[Index];
	}
	void SetStringAppendList( const vector<AppendStringWraper>& v )
	{
		m_StringAppendList=v;
	}
	void ClearStringAppendList( )
	{
		m_StringAppendList.clear();
	}
	void SetStringAppendList( int Index, const AppendStringWraper& v )
	{
		if(Index<0 || Index>=(int)m_StringAppendList.size())
		{
			assert(false);
			return;
		}
		m_StringAppendList[Index] = v;
	}
	void AddStringAppendList( const AppendStringWraper& v )
	{
		m_StringAppendList.push_back(v);
	}

};
//运营活动登录信息封装类
class SpecLoginInfoWraper
{
public:
	//构造函数
	SpecLoginInfoWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	SpecLoginInfoWraper(const SpecLoginInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const SpecLoginInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	SpecLoginInfo ToPB() const
	{
		SpecLoginInfo v;
		v.set_id( m_Id );
		v.mutable_rewardinfo()->Reserve(m_RewardInfo.size());
		for (int i=0; i<(int)m_RewardInfo.size(); i++)
		{
			*v.add_rewardinfo() = m_RewardInfo[i].ToPB();
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
		SpecLoginInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const SpecLoginInfo& v)
	{
		m_Id = v.id();
		m_RewardInfo.clear();
		m_RewardInfo.reserve(v.rewardinfo_size());
		for( int i=0; i<v.rewardinfo_size(); i++)
			m_RewardInfo.push_back(v.rewardinfo(i));

	}

private:
	//活动
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//领奖信息
	vector<SpecLoginRewardWraper> m_RewardInfo;
public:
	int SizeRewardInfo()
	{
		return m_RewardInfo.size();
	}
	const vector<SpecLoginRewardWraper>& GetRewardInfo() const
	{
		return m_RewardInfo;
	}
	SpecLoginRewardWraper GetRewardInfo(int Index) const
	{
		if(Index<0 || Index>=(int)m_RewardInfo.size())
		{
			assert(false);
			return SpecLoginRewardWraper();
		}
		return m_RewardInfo[Index];
	}
	void SetRewardInfo( const vector<SpecLoginRewardWraper>& v )
	{
		m_RewardInfo=v;
	}
	void ClearRewardInfo( )
	{
		m_RewardInfo.clear();
	}
	void SetRewardInfo( int Index, const SpecLoginRewardWraper& v )
	{
		if(Index<0 || Index>=(int)m_RewardInfo.size())
		{
			assert(false);
			return;
		}
		m_RewardInfo[Index] = v;
	}
	void AddRewardInfo( const SpecLoginRewardWraper& v )
	{
		m_RewardInfo.push_back(v);
	}

};
//装备打造神器值封装类
class EquipBuildAtfWraper
{
public:
	//构造函数
	EquipBuildAtfWraper()
	{
		
		m_Level = -1;
		m_Atf_value = -1;

	}
	//赋值构造函数
	EquipBuildAtfWraper(const EquipBuildAtf& v){ Init(v); }
	//等号重载函数
	void operator = (const EquipBuildAtf& v){ Init(v); }
 	//转化成Protobuffer类型函数
	EquipBuildAtf ToPB() const
	{
		EquipBuildAtf v;
		v.set_level( m_Level );
		v.set_atf_value( m_Atf_value );

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
		EquipBuildAtf pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const EquipBuildAtf& v)
	{
		m_Level = v.level();
		m_Atf_value = v.atf_value();

	}

private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//神器值
	INT32 m_Atf_value;
public:
	void SetAtf_value( INT32 v)
	{
		m_Atf_value=v;
	}
	INT32 GetAtf_value()
	{
		return m_Atf_value;
	}
	INT32 GetAtf_value() const
	{
		return m_Atf_value;
	}

};
//掉落物品封装类
class DropItemWraper
{
public:
	//构造函数
	DropItemWraper()
	{
		
		m_ItemType = -1;
		m_ItemID = -1;
		m_ItemNum = -1;
		m_Bind = false;
		m_Transit = false;

	}
	//赋值构造函数
	DropItemWraper(const DropItem& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItem ToPB() const
	{
		DropItem v;
		v.set_itemtype( m_ItemType );
		v.set_itemid( m_ItemID );
		v.set_itemnum( m_ItemNum );
		v.set_bind( m_Bind );
		v.set_transit( m_Transit );

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
		DropItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DropItem& v)
	{
		m_ItemType = v.itemtype();
		m_ItemID = v.itemid();
		m_ItemNum = v.itemnum();
		m_Bind = v.bind();
		m_Transit = v.transit();

	}

private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}
private:
	//物品编号
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
	//物品数量
	INT32 m_ItemNum;
public:
	void SetItemNum( INT32 v)
	{
		m_ItemNum=v;
	}
	INT32 GetItemNum()
	{
		return m_ItemNum;
	}
	INT32 GetItemNum() const
	{
		return m_ItemNum;
	}
private:
	//是否绑定
	bool m_Bind;
public:
	void SetBind( bool v)
	{
		m_Bind=v;
	}
	bool GetBind()
	{
		return m_Bind;
	}
	bool GetBind() const
	{
		return m_Bind;
	}
private:
	//transit
	bool m_Transit;
public:
	void SetTransit( bool v)
	{
		m_Transit=v;
	}
	bool GetTransit()
	{
		return m_Transit;
	}
	bool GetTransit() const
	{
		return m_Transit;
	}

};
//ObjPosInfo封装类
class ObjPosInfoWraper
{
public:
	//构造函数
	ObjPosInfoWraper()
	{
		
		m_ObjId = 0;
		m_Id = -1;
		m_X = -1;
		m_Z = -1;
		m_Type = -1;

	}
	//赋值构造函数
	ObjPosInfoWraper(const ObjPosInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ObjPosInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ObjPosInfo ToPB() const
	{
		ObjPosInfo v;
		v.set_objid( m_ObjId );
		v.set_id( m_Id );
		v.set_x( m_X );
		v.set_z( m_Z );
		v.set_type( m_Type );

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
		ObjPosInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ObjPosInfo& v)
	{
		m_ObjId = v.objid();
		m_Id = v.id();
		m_X = v.x();
		m_Z = v.z();
		m_Type = v.type();

	}

private:
	//ObjId
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//z
	INT32 m_X;
public:
	void SetX( INT32 v)
	{
		m_X=v;
	}
	INT32 GetX()
	{
		return m_X;
	}
	INT32 GetX() const
	{
		return m_X;
	}
private:
	//z
	INT32 m_Z;
public:
	void SetZ( INT32 v)
	{
		m_Z=v;
	}
	INT32 GetZ()
	{
		return m_Z;
	}
	INT32 GetZ() const
	{
		return m_Z;
	}
private:
	//类型(1eventobj,2creature)
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}

};
//资源找回信息封装类
class RewardRecoveryInfoWraper
{
public:
	//构造函数
	RewardRecoveryInfoWraper()
	{
		
		m_Id = -1;
		m_NormalState = 0;
		m_PerfectState = -1;
		m_CostItemNormal = RewardRecoveryItemWraper();
		m_CostItemPerfect = RewardRecoveryItemWraper();

	}
	//赋值构造函数
	RewardRecoveryInfoWraper(const RewardRecoveryInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const RewardRecoveryInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RewardRecoveryInfo ToPB() const
	{
		RewardRecoveryInfo v;
		v.set_id( m_Id );
		v.mutable_itemnormal()->Reserve(m_ItemNormal.size());
		for (int i=0; i<(int)m_ItemNormal.size(); i++)
		{
			*v.add_itemnormal() = m_ItemNormal[i].ToPB();
		}
		v.mutable_itemperfect()->Reserve(m_ItemPerfect.size());
		for (int i=0; i<(int)m_ItemPerfect.size(); i++)
		{
			*v.add_itemperfect() = m_ItemPerfect[i].ToPB();
		}
		v.set_normalstate( m_NormalState );
		v.set_perfectstate( m_PerfectState );
		*v.mutable_costitemnormal()= m_CostItemNormal.ToPB();
		*v.mutable_costitemperfect()= m_CostItemPerfect.ToPB();

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
		RewardRecoveryInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RewardRecoveryInfo& v)
	{
		m_Id = v.id();
		m_ItemNormal.clear();
		m_ItemNormal.reserve(v.itemnormal_size());
		for( int i=0; i<v.itemnormal_size(); i++)
			m_ItemNormal.push_back(v.itemnormal(i));
		m_ItemPerfect.clear();
		m_ItemPerfect.reserve(v.itemperfect_size());
		for( int i=0; i<v.itemperfect_size(); i++)
			m_ItemPerfect.push_back(v.itemperfect(i));
		m_NormalState = v.normalstate();
		m_PerfectState = v.perfectstate();
		m_CostItemNormal = v.costitemnormal();
		m_CostItemPerfect = v.costitemperfect();

	}

private:
	//资源找回ID
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//普通找回物品
	vector<RewardRecoveryItemWraper> m_ItemNormal;
public:
	int SizeItemNormal()
	{
		return m_ItemNormal.size();
	}
	const vector<RewardRecoveryItemWraper>& GetItemNormal() const
	{
		return m_ItemNormal;
	}
	RewardRecoveryItemWraper GetItemNormal(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemNormal.size())
		{
			assert(false);
			return RewardRecoveryItemWraper();
		}
		return m_ItemNormal[Index];
	}
	void SetItemNormal( const vector<RewardRecoveryItemWraper>& v )
	{
		m_ItemNormal=v;
	}
	void ClearItemNormal( )
	{
		m_ItemNormal.clear();
	}
	void SetItemNormal( int Index, const RewardRecoveryItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemNormal.size())
		{
			assert(false);
			return;
		}
		m_ItemNormal[Index] = v;
	}
	void AddItemNormal( const RewardRecoveryItemWraper& v )
	{
		m_ItemNormal.push_back(v);
	}
private:
	//完美找回物品
	vector<RewardRecoveryItemWraper> m_ItemPerfect;
public:
	int SizeItemPerfect()
	{
		return m_ItemPerfect.size();
	}
	const vector<RewardRecoveryItemWraper>& GetItemPerfect() const
	{
		return m_ItemPerfect;
	}
	RewardRecoveryItemWraper GetItemPerfect(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemPerfect.size())
		{
			assert(false);
			return RewardRecoveryItemWraper();
		}
		return m_ItemPerfect[Index];
	}
	void SetItemPerfect( const vector<RewardRecoveryItemWraper>& v )
	{
		m_ItemPerfect=v;
	}
	void ClearItemPerfect( )
	{
		m_ItemPerfect.clear();
	}
	void SetItemPerfect( int Index, const RewardRecoveryItemWraper& v )
	{
		if(Index<0 || Index>=(int)m_ItemPerfect.size())
		{
			assert(false);
			return;
		}
		m_ItemPerfect[Index] = v;
	}
	void AddItemPerfect( const RewardRecoveryItemWraper& v )
	{
		m_ItemPerfect.push_back(v);
	}
private:
	//找回状态普通
	INT32 m_NormalState;
public:
	void SetNormalState( INT32 v)
	{
		m_NormalState=v;
	}
	INT32 GetNormalState()
	{
		return m_NormalState;
	}
	INT32 GetNormalState() const
	{
		return m_NormalState;
	}
private:
	//找回状态完美
	INT32 m_PerfectState;
public:
	void SetPerfectState( INT32 v)
	{
		m_PerfectState=v;
	}
	INT32 GetPerfectState()
	{
		return m_PerfectState;
	}
	INT32 GetPerfectState() const
	{
		return m_PerfectState;
	}
private:
	//找回消耗类型普通
	RewardRecoveryItemWraper m_CostItemNormal;
public:
	void SetCostItemNormal( const RewardRecoveryItemWraper& v)
	{
		m_CostItemNormal=v;
	}
	RewardRecoveryItemWraper GetCostItemNormal()
	{
		return m_CostItemNormal;
	}
	RewardRecoveryItemWraper GetCostItemNormal() const
	{
		return m_CostItemNormal;
	}
private:
	//找回消耗类型完美
	RewardRecoveryItemWraper m_CostItemPerfect;
public:
	void SetCostItemPerfect( const RewardRecoveryItemWraper& v)
	{
		m_CostItemPerfect=v;
	}
	RewardRecoveryItemWraper GetCostItemPerfect()
	{
		return m_CostItemPerfect;
	}
	RewardRecoveryItemWraper GetCostItemPerfect() const
	{
		return m_CostItemPerfect;
	}

};
//军衔排行信息封装类
class WorshipPlayerDataWraper
{
public:
	//构造函数
	WorshipPlayerDataWraper()
	{
		
		m_Role_id = -1;
		m_Role_name = "";
		m_Rank_level = -1;
		m_Worship_cout = -1;
		m_Rank = -1;

	}
	//赋值构造函数
	WorshipPlayerDataWraper(const WorshipPlayerData& v){ Init(v); }
	//等号重载函数
	void operator = (const WorshipPlayerData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	WorshipPlayerData ToPB() const
	{
		WorshipPlayerData v;
		v.set_role_id( m_Role_id );
		v.set_role_name( m_Role_name );
		v.set_rank_level( m_Rank_level );
		v.set_worship_cout( m_Worship_cout );
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
		WorshipPlayerData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const WorshipPlayerData& v)
	{
		m_Role_id = v.role_id();
		m_Role_name = v.role_name();
		m_Rank_level = v.rank_level();
		m_Worship_cout = v.worship_cout();
		m_Rank = v.rank();

	}

private:
	//role_id
	INT32 m_Role_id;
public:
	void SetRole_id( INT32 v)
	{
		m_Role_id=v;
	}
	INT32 GetRole_id()
	{
		return m_Role_id;
	}
	INT32 GetRole_id() const
	{
		return m_Role_id;
	}
private:
	//Role_name
	string m_Role_name;
public:
	void SetRole_name( const string& v)
	{
		m_Role_name=v;
	}
	string GetRole_name()
	{
		return m_Role_name;
	}
	string GetRole_name() const
	{
		return m_Role_name;
	}
private:
	//Rank_level
	INT32 m_Rank_level;
public:
	void SetRank_level( INT32 v)
	{
		m_Rank_level=v;
	}
	INT32 GetRank_level()
	{
		return m_Rank_level;
	}
	INT32 GetRank_level() const
	{
		return m_Rank_level;
	}
private:
	//Worship_cout
	INT32 m_Worship_cout;
public:
	void SetWorship_cout( INT32 v)
	{
		m_Worship_cout=v;
	}
	INT32 GetWorship_cout()
	{
		return m_Worship_cout;
	}
	INT32 GetWorship_cout() const
	{
		return m_Worship_cout;
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

};
//轮盘数据封装类
class ExpressionWheelInfoWraper
{
public:
	//构造函数
	ExpressionWheelInfoWraper()
	{
		
		m_Index = -1;
		m_ActionID = -1;

	}
	//赋值构造函数
	ExpressionWheelInfoWraper(const ExpressionWheelInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ExpressionWheelInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ExpressionWheelInfo ToPB() const
	{
		ExpressionWheelInfo v;
		v.set_index( m_Index );
		v.set_actionid( m_ActionID );

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
		ExpressionWheelInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ExpressionWheelInfo& v)
	{
		m_Index = v.index();
		m_ActionID = v.actionid();

	}

private:
	//索引
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
private:
	//ID
	INT32 m_ActionID;
public:
	void SetActionID( INT32 v)
	{
		m_ActionID=v;
	}
	INT32 GetActionID()
	{
		return m_ActionID;
	}
	INT32 GetActionID() const
	{
		return m_ActionID;
	}

};
//药剂封装类
class RecoverMedicamentWraper
{
public:
	//构造函数
	RecoverMedicamentWraper()
	{
		
		m_AutoHpMedicament = -1;
		m_HpPercentage = -1;

	}
	//赋值构造函数
	RecoverMedicamentWraper(const RecoverMedicament& v){ Init(v); }
	//等号重载函数
	void operator = (const RecoverMedicament& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RecoverMedicament ToPB() const
	{
		RecoverMedicament v;
		v.mutable_hpmedicamentlist()->Reserve(m_HpMedicamentList.size());
		for (int i=0; i<(int)m_HpMedicamentList.size(); i++)
		{
			v.add_hpmedicamentlist(m_HpMedicamentList[i]);
		}
		v.set_autohpmedicament( m_AutoHpMedicament );
		v.set_hppercentage( m_HpPercentage );

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
		RecoverMedicament pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RecoverMedicament& v)
	{
		m_HpMedicamentList.clear();
		m_HpMedicamentList.reserve(v.hpmedicamentlist_size());
		for( int i=0; i<v.hpmedicamentlist_size(); i++)
			m_HpMedicamentList.push_back(v.hpmedicamentlist(i));
		m_AutoHpMedicament = v.autohpmedicament();
		m_HpPercentage = v.hppercentage();

	}

private:
	//HpMedicamentList
	vector<INT32> m_HpMedicamentList;
public:
	int SizeHpMedicamentList()
	{
		return m_HpMedicamentList.size();
	}
	const vector<INT32>& GetHpMedicamentList() const
	{
		return m_HpMedicamentList;
	}
	INT32 GetHpMedicamentList(int Index) const
	{
		if(Index<0 || Index>=(int)m_HpMedicamentList.size())
		{
			assert(false);
			return INT32();
		}
		return m_HpMedicamentList[Index];
	}
	void SetHpMedicamentList( const vector<INT32>& v )
	{
		m_HpMedicamentList=v;
	}
	void ClearHpMedicamentList( )
	{
		m_HpMedicamentList.clear();
	}
	void SetHpMedicamentList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_HpMedicamentList.size())
		{
			assert(false);
			return;
		}
		m_HpMedicamentList[Index] = v;
	}
	void AddHpMedicamentList( INT32 v = -1 )
	{
		m_HpMedicamentList.push_back(v);
	}
private:
	//自动使用
	INT32 m_AutoHpMedicament;
public:
	void SetAutoHpMedicament( INT32 v)
	{
		m_AutoHpMedicament=v;
	}
	INT32 GetAutoHpMedicament()
	{
		return m_AutoHpMedicament;
	}
	INT32 GetAutoHpMedicament() const
	{
		return m_AutoHpMedicament;
	}
private:
	//血量低于百分之几
	INT32 m_HpPercentage;
public:
	void SetHpPercentage( INT32 v)
	{
		m_HpPercentage=v;
	}
	INT32 GetHpPercentage()
	{
		return m_HpPercentage;
	}
	INT32 GetHpPercentage() const
	{
		return m_HpPercentage;
	}

};
//队伍快速刷新信息封装类
class TeamMemberHpInfoWraper
{
public:
	//构造函数
	TeamMemberHpInfoWraper()
	{
		
		m_Hp = -1;
		m_MaxHp = -1;
		m_RoleId = 0;

	}
	//赋值构造函数
	TeamMemberHpInfoWraper(const TeamMemberHpInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberHpInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberHpInfo ToPB() const
	{
		TeamMemberHpInfo v;
		v.set_hp( m_Hp );
		v.set_maxhp( m_MaxHp );
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
		TeamMemberHpInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamMemberHpInfo& v)
	{
		m_Hp = v.hp();
		m_MaxHp = v.maxhp();
		m_RoleId = v.roleid();

	}

private:
	//生命值
	INT32 m_Hp;
public:
	void SetHp( INT32 v)
	{
		m_Hp=v;
	}
	INT32 GetHp()
	{
		return m_Hp;
	}
	INT32 GetHp() const
	{
		return m_Hp;
	}
private:
	//生命值
	int64_t m_MaxHp;
public:
	void SetMaxHp( int64_t v)
	{
		m_MaxHp=v;
	}
	int64_t GetMaxHp()
	{
		return m_MaxHp;
	}
	int64_t GetMaxHp() const
	{
		return m_MaxHp;
	}
private:
	//队员RoleId
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
//队伍位置封装类
class TeamMemberPosWraper
{
public:
	//构造函数
	TeamMemberPosWraper()
	{
		
		m_Pos = Vector3Wraper();
		m_RoleId = 0;

	}
	//赋值构造函数
	TeamMemberPosWraper(const TeamMemberPos& v){ Init(v); }
	//等号重载函数
	void operator = (const TeamMemberPos& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeamMemberPos ToPB() const
	{
		TeamMemberPos v;
		*v.mutable_pos()= m_Pos.ToPB();
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
		TeamMemberPos pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeamMemberPos& v)
	{
		m_Pos = v.pos();
		m_RoleId = v.roleid();

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
	//队员RoleId
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
//队伍bufflist封装类
class TeanMemberBuffWraper
{
public:
	//构造函数
	TeanMemberBuffWraper()
	{
		
		m_RoleId = 0;

	}
	//赋值构造函数
	TeanMemberBuffWraper(const TeanMemberBuff& v){ Init(v); }
	//等号重载函数
	void operator = (const TeanMemberBuff& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TeanMemberBuff ToPB() const
	{
		TeanMemberBuff v;
		v.set_roleid( m_RoleId );
		v.mutable_buffidlist()->Reserve(m_BuffIdList.size());
		for (int i=0; i<(int)m_BuffIdList.size(); i++)
		{
			v.add_buffidlist(m_BuffIdList[i]);
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
		TeanMemberBuff pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TeanMemberBuff& v)
	{
		m_RoleId = v.roleid();
		m_BuffIdList.clear();
		m_BuffIdList.reserve(v.buffidlist_size());
		for( int i=0; i<v.buffidlist_size(); i++)
			m_BuffIdList.push_back(v.buffidlist(i));

	}

private:
	//队员RoleId
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
	//buff
	vector<INT32> m_BuffIdList;
public:
	int SizeBuffIdList()
	{
		return m_BuffIdList.size();
	}
	const vector<INT32>& GetBuffIdList() const
	{
		return m_BuffIdList;
	}
	INT32 GetBuffIdList(int Index) const
	{
		if(Index<0 || Index>=(int)m_BuffIdList.size())
		{
			assert(false);
			return INT32();
		}
		return m_BuffIdList[Index];
	}
	void SetBuffIdList( const vector<INT32>& v )
	{
		m_BuffIdList=v;
	}
	void ClearBuffIdList( )
	{
		m_BuffIdList.clear();
	}
	void SetBuffIdList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_BuffIdList.size())
		{
			assert(false);
			return;
		}
		m_BuffIdList[Index] = v;
	}
	void AddBuffIdList( INT32 v = -1 )
	{
		m_BuffIdList.push_back(v);
	}

};
//PvpPlayerInfo封装类
class PvpPlayerInfoWraper
{
public:
	//构造函数
	PvpPlayerInfoWraper()
	{
		
		m_RoleID = 0;
		m_RoleName = "";
		m_Level = -1;
		m_Rank = -1;
		m_PvpInfo = PvpBattleInfoWraper();
		m_GuildName = "";
		m_ConfigID = -1;
		m_Robot = false;
		m_ProfessionId = -1;

	}
	//赋值构造函数
	PvpPlayerInfoWraper(const PvpPlayerInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const PvpPlayerInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PvpPlayerInfo ToPB() const
	{
		PvpPlayerInfo v;
		v.set_roleid( m_RoleID );
		v.set_rolename( m_RoleName );
		v.set_level( m_Level );
		v.set_rank( m_Rank );
		*v.mutable_pvpinfo()= m_PvpInfo.ToPB();
		v.set_guildname( m_GuildName );
		v.set_configid( m_ConfigID );
		v.set_robot( m_Robot );
		v.set_professionid( m_ProfessionId );

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
		PvpPlayerInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const PvpPlayerInfo& v)
	{
		m_RoleID = v.roleid();
		m_RoleName = v.rolename();
		m_Level = v.level();
		m_Rank = v.rank();
		m_PvpInfo = v.pvpinfo();
		m_GuildName = v.guildname();
		m_ConfigID = v.configid();
		m_Robot = v.robot();
		m_ProfessionId = v.professionid();

	}

private:
	//RoleID
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
	//RoleName
	string m_RoleName;
public:
	void SetRoleName( const string& v)
	{
		m_RoleName=v;
	}
	string GetRoleName()
	{
		return m_RoleName;
	}
	string GetRoleName() const
	{
		return m_RoleName;
	}
private:
	//Level
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
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
	//PvpInfo
	PvpBattleInfoWraper m_PvpInfo;
public:
	void SetPvpInfo( const PvpBattleInfoWraper& v)
	{
		m_PvpInfo=v;
	}
	PvpBattleInfoWraper GetPvpInfo()
	{
		return m_PvpInfo;
	}
	PvpBattleInfoWraper GetPvpInfo() const
	{
		return m_PvpInfo;
	}
private:
	//GuildName
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//ConfigID
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
	}
private:
	//是否机器人
	bool m_Robot;
public:
	void SetRobot( bool v)
	{
		m_Robot=v;
	}
	bool GetRobot()
	{
		return m_Robot;
	}
	bool GetRobot() const
	{
		return m_Robot;
	}
private:
	//专精ID
	INT32 m_ProfessionId;
public:
	void SetProfessionId( INT32 v)
	{
		m_ProfessionId=v;
	}
	INT32 GetProfessionId()
	{
		return m_ProfessionId;
	}
	INT32 GetProfessionId() const
	{
		return m_ProfessionId;
	}

};
//随机任务数据库封装类
class RandomQuestListDataWraper
{
public:
	//构造函数
	RandomQuestListDataWraper()
	{
		

	}
	//赋值构造函数
	RandomQuestListDataWraper(const RandomQuestListData& v){ Init(v); }
	//等号重载函数
	void operator = (const RandomQuestListData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RandomQuestListData ToPB() const
	{
		RandomQuestListData v;
		v.mutable_questlist()->Reserve(m_QuestList.size());
		for (int i=0; i<(int)m_QuestList.size(); i++)
		{
			*v.add_questlist() = m_QuestList[i].ToPB();
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
		RandomQuestListData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RandomQuestListData& v)
	{
		m_QuestList.clear();
		m_QuestList.reserve(v.questlist_size());
		for( int i=0; i<v.questlist_size(); i++)
			m_QuestList.push_back(v.questlist(i));

	}

private:
	//任务列表
	vector<RandomQuestDataWraper> m_QuestList;
public:
	int SizeQuestList()
	{
		return m_QuestList.size();
	}
	const vector<RandomQuestDataWraper>& GetQuestList() const
	{
		return m_QuestList;
	}
	RandomQuestDataWraper GetQuestList(int Index) const
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return RandomQuestDataWraper();
		}
		return m_QuestList[Index];
	}
	void SetQuestList( const vector<RandomQuestDataWraper>& v )
	{
		m_QuestList=v;
	}
	void ClearQuestList( )
	{
		m_QuestList.clear();
	}
	void SetQuestList( int Index, const RandomQuestDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_QuestList.size())
		{
			assert(false);
			return;
		}
		m_QuestList[Index] = v;
	}
	void AddQuestList( const RandomQuestDataWraper& v )
	{
		m_QuestList.push_back(v);
	}

};
//副本任务目标封装类
class DungeonTargetWraper
{
public:
	//构造函数
	DungeonTargetWraper()
	{
		
		m_TypeId = -1;
		m_Index = -1;
		m_Description = -1;
		m_IParam = -1;

	}
	//赋值构造函数
	DungeonTargetWraper(const DungeonTarget& v){ Init(v); }
	//等号重载函数
	void operator = (const DungeonTarget& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DungeonTarget ToPB() const
	{
		DungeonTarget v;
		v.set_typeid( m_TypeId );
		v.set_index( m_Index );
		v.mutable_targetcontent()->Reserve(m_TargetContent.size());
		for (int i=0; i<(int)m_TargetContent.size(); i++)
		{
			*v.add_targetcontent() = m_TargetContent[i].ToPB();
		}
		v.set_description( m_Description );
		v.set_iparam( m_IParam );

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
		DungeonTarget pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const DungeonTarget& v)
	{
		m_TypeId = v.typeid();
		m_Index = v.index();
		m_TargetContent.clear();
		m_TargetContent.reserve(v.targetcontent_size());
		for( int i=0; i<v.targetcontent_size(); i++)
			m_TargetContent.push_back(v.targetcontent(i));
		m_Description = v.description();
		m_IParam = v.iparam();

	}

private:
	//目标类型
	INT32 m_TypeId;
public:
	void SetTypeId( INT32 v)
	{
		m_TypeId=v;
	}
	INT32 GetTypeId()
	{
		return m_TypeId;
	}
	INT32 GetTypeId() const
	{
		return m_TypeId;
	}
private:
	//目标序号
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
private:
	//子任务
	vector<DungeonTargetContentWraper> m_TargetContent;
public:
	int SizeTargetContent()
	{
		return m_TargetContent.size();
	}
	const vector<DungeonTargetContentWraper>& GetTargetContent() const
	{
		return m_TargetContent;
	}
	DungeonTargetContentWraper GetTargetContent(int Index) const
	{
		if(Index<0 || Index>=(int)m_TargetContent.size())
		{
			assert(false);
			return DungeonTargetContentWraper();
		}
		return m_TargetContent[Index];
	}
	void SetTargetContent( const vector<DungeonTargetContentWraper>& v )
	{
		m_TargetContent=v;
	}
	void ClearTargetContent( )
	{
		m_TargetContent.clear();
	}
	void SetTargetContent( int Index, const DungeonTargetContentWraper& v )
	{
		if(Index<0 || Index>=(int)m_TargetContent.size())
		{
			assert(false);
			return;
		}
		m_TargetContent[Index] = v;
	}
	void AddTargetContent( const DungeonTargetContentWraper& v )
	{
		m_TargetContent.push_back(v);
	}
private:
	//副本目标描述Id
	INT32 m_Description;
public:
	void SetDescription( INT32 v)
	{
		m_Description=v;
	}
	INT32 GetDescription()
	{
		return m_Description;
	}
	INT32 GetDescription() const
	{
		return m_Description;
	}
private:
	//副本目标参数
	INT32 m_IParam;
public:
	void SetIParam( INT32 v)
	{
		m_IParam=v;
	}
	INT32 GetIParam()
	{
		return m_IParam;
	}
	INT32 GetIParam() const
	{
		return m_IParam;
	}

};
//红点信息封装类
class RedDotInfoWraper
{
public:
	//构造函数
	RedDotInfoWraper()
	{
		
		m_Type = -1;
		m_IsLight = -1;

	}
	//赋值构造函数
	RedDotInfoWraper(const RedDotInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const RedDotInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RedDotInfo ToPB() const
	{
		RedDotInfo v;
		v.set_type( m_Type );
		v.set_islight( m_IsLight );

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
		RedDotInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RedDotInfo& v)
	{
		m_Type = v.type();
		m_IsLight = v.islight();

	}

private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//是否亮
	INT32 m_IsLight;
public:
	void SetIsLight( INT32 v)
	{
		m_IsLight=v;
	}
	INT32 GetIsLight()
	{
		return m_IsLight;
	}
	INT32 GetIsLight() const
	{
		return m_IsLight;
	}

};
//佣兵信息封装类
class MercenaryInfoWraper
{
public:
	//构造函数
	MercenaryInfoWraper()
	{
		
		m_Id = 0;

	}
	//赋值构造函数
	MercenaryInfoWraper(const MercenaryInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MercenaryInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MercenaryInfo ToPB() const
	{
		MercenaryInfo v;
		v.set_id( m_Id );

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
		MercenaryInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MercenaryInfo& v)
	{
		m_Id = v.id();

	}

private:
	//佣兵id
	uint64_t m_Id;
public:
	void SetId( uint64_t v)
	{
		m_Id=v;
	}
	uint64_t GetId()
	{
		return m_Id;
	}
	uint64_t GetId() const
	{
		return m_Id;
	}

};
//排行榜信息封装类
class RankInfoWraper
{
public:
	//构造函数
	RankInfoWraper()
	{
		
		m_RoleID = 0;
		m_RoleName = "";
		m_ConfigID = -1;
		m_GuildID = 0;
		m_GuildName = "";
		m_PetID = -1;
		m_PetLevel = -1;
		m_TreasureCount = -1;
		m_TreasureLevel = -1;
		m_Score = -1;
		m_Level = -1;
		m_GuildFlagID = -1;
		m_WinCount = -1;
		m_GuildDungeonLayer = -1;
		m_GuildDungeonTime = -1;

	}
	//赋值构造函数
	RankInfoWraper(const RankInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const RankInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	RankInfo ToPB() const
	{
		RankInfo v;
		v.set_roleid( m_RoleID );
		v.set_rolename( m_RoleName );
		v.set_configid( m_ConfigID );
		v.set_guildid( m_GuildID );
		v.set_guildname( m_GuildName );
		v.set_petid( m_PetID );
		v.set_petlevel( m_PetLevel );
		v.set_treasurecount( m_TreasureCount );
		v.set_treasurelevel( m_TreasureLevel );
		v.set_score( m_Score );
		v.set_level( m_Level );
		v.set_guildflagid( m_GuildFlagID );
		v.set_wincount( m_WinCount );
		v.set_guilddungeonlayer( m_GuildDungeonLayer );
		v.set_guilddungeontime( m_GuildDungeonTime );

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
		RankInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const RankInfo& v)
	{
		m_RoleID = v.roleid();
		m_RoleName = v.rolename();
		m_ConfigID = v.configid();
		m_GuildID = v.guildid();
		m_GuildName = v.guildname();
		m_PetID = v.petid();
		m_PetLevel = v.petlevel();
		m_TreasureCount = v.treasurecount();
		m_TreasureLevel = v.treasurelevel();
		m_Score = v.score();
		m_Level = v.level();
		m_GuildFlagID = v.guildflagid();
		m_WinCount = v.wincount();
		m_GuildDungeonLayer = v.guilddungeonlayer();
		m_GuildDungeonTime = v.guilddungeontime();

	}

private:
	//角色唯一ID
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
	//角色名
	string m_RoleName;
public:
	void SetRoleName( const string& v)
	{
		m_RoleName=v;
	}
	string GetRoleName()
	{
		return m_RoleName;
	}
	string GetRoleName() const
	{
		return m_RoleName;
	}
private:
	//职业ID
	INT32 m_ConfigID;
public:
	void SetConfigID( INT32 v)
	{
		m_ConfigID=v;
	}
	INT32 GetConfigID()
	{
		return m_ConfigID;
	}
	INT32 GetConfigID() const
	{
		return m_ConfigID;
	}
private:
	//工会ID
	uint64_t m_GuildID;
public:
	void SetGuildID( uint64_t v)
	{
		m_GuildID=v;
	}
	uint64_t GetGuildID()
	{
		return m_GuildID;
	}
	uint64_t GetGuildID() const
	{
		return m_GuildID;
	}
private:
	//工会名
	string m_GuildName;
public:
	void SetGuildName( const string& v)
	{
		m_GuildName=v;
	}
	string GetGuildName()
	{
		return m_GuildName;
	}
	string GetGuildName() const
	{
		return m_GuildName;
	}
private:
	//宠物ID
	INT32 m_PetID;
public:
	void SetPetID( INT32 v)
	{
		m_PetID=v;
	}
	INT32 GetPetID()
	{
		return m_PetID;
	}
	INT32 GetPetID() const
	{
		return m_PetID;
	}
private:
	//宠物等级
	INT32 m_PetLevel;
public:
	void SetPetLevel( INT32 v)
	{
		m_PetLevel=v;
	}
	INT32 GetPetLevel()
	{
		return m_PetLevel;
	}
	INT32 GetPetLevel() const
	{
		return m_PetLevel;
	}
private:
	//外观数量
	INT32 m_TreasureCount;
public:
	void SetTreasureCount( INT32 v)
	{
		m_TreasureCount=v;
	}
	INT32 GetTreasureCount()
	{
		return m_TreasureCount;
	}
	INT32 GetTreasureCount() const
	{
		return m_TreasureCount;
	}
private:
	//宝物库等级
	INT32 m_TreasureLevel;
public:
	void SetTreasureLevel( INT32 v)
	{
		m_TreasureLevel=v;
	}
	INT32 GetTreasureLevel()
	{
		return m_TreasureLevel;
	}
	INT32 GetTreasureLevel() const
	{
		return m_TreasureLevel;
	}
private:
	//排行分数
	INT32 m_Score;
public:
	void SetScore( INT32 v)
	{
		m_Score=v;
	}
	INT32 GetScore()
	{
		return m_Score;
	}
	INT32 GetScore() const
	{
		return m_Score;
	}
private:
	//等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//工会旗帜ID
	INT32 m_GuildFlagID;
public:
	void SetGuildFlagID( INT32 v)
	{
		m_GuildFlagID=v;
	}
	INT32 GetGuildFlagID()
	{
		return m_GuildFlagID;
	}
	INT32 GetGuildFlagID() const
	{
		return m_GuildFlagID;
	}
private:
	//胜场数
	INT32 m_WinCount;
public:
	void SetWinCount( INT32 v)
	{
		m_WinCount=v;
	}
	INT32 GetWinCount()
	{
		return m_WinCount;
	}
	INT32 GetWinCount() const
	{
		return m_WinCount;
	}
private:
	//工会爬塔层数
	INT32 m_GuildDungeonLayer;
public:
	void SetGuildDungeonLayer( INT32 v)
	{
		m_GuildDungeonLayer=v;
	}
	INT32 GetGuildDungeonLayer()
	{
		return m_GuildDungeonLayer;
	}
	INT32 GetGuildDungeonLayer() const
	{
		return m_GuildDungeonLayer;
	}
private:
	//工会爬塔时间
	INT32 m_GuildDungeonTime;
public:
	void SetGuildDungeonTime( INT32 v)
	{
		m_GuildDungeonTime=v;
	}
	INT32 GetGuildDungeonTime()
	{
		return m_GuildDungeonTime;
	}
	INT32 GetGuildDungeonTime() const
	{
		return m_GuildDungeonTime;
	}

};
//拍卖行商品数量信息封装类
class AuctionItemCntWraper
{
public:
	//构造函数
	AuctionItemCntWraper()
	{
		
		m_ItemId = -1;
		m_Count = -1;
		m_InShow = false;

	}
	//赋值构造函数
	AuctionItemCntWraper(const AuctionItemCnt& v){ Init(v); }
	//等号重载函数
	void operator = (const AuctionItemCnt& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AuctionItemCnt ToPB() const
	{
		AuctionItemCnt v;
		v.set_itemid( m_ItemId );
		v.set_count( m_Count );
		v.set_inshow( m_InShow );

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
		AuctionItemCnt pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const AuctionItemCnt& v)
	{
		m_ItemId = v.itemid();
		m_Count = v.count();
		m_InShow = v.inshow();

	}

private:
	//商品id
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
private:
	//商品数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
	}
private:
	//InShow
	bool m_InShow;
public:
	void SetInShow( bool v)
	{
		m_InShow=v;
	}
	bool GetInShow()
	{
		return m_InShow;
	}
	bool GetInShow() const
	{
		return m_InShow;
	}

};
//obj创建需要信息封装类
class ObjCreateInfoWraper
{
public:
	//构造函数
	ObjCreateInfoWraper()
	{
		
		m_ObjId = 0;
		m_Pos = Vector3Wraper();
		m_Dir = -1;
		m_Status = -1;
		m_TargetPos = Vector3Wraper();
		m_ObjData = "";
		m_Motion = MotionInfoWraper();
		m_IsNew = false;
		m_SkillPrepareId = -1;
		m_SkillPrepareTime = -1;
		m_LoopSkillId = -1;

	}
	//赋值构造函数
	ObjCreateInfoWraper(const ObjCreateInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ObjCreateInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ObjCreateInfo ToPB() const
	{
		ObjCreateInfo v;
		v.set_objid( m_ObjId );
		*v.mutable_pos()= m_Pos.ToPB();
		v.set_dir( m_Dir );
		v.set_status( m_Status );
		*v.mutable_targetpos()= m_TargetPos.ToPB();
		v.set_objdata( m_ObjData );
		*v.mutable_motion()= m_Motion.ToPB();
		v.set_isnew( m_IsNew );
		v.set_skillprepareid( m_SkillPrepareId );
		v.set_skillpreparetime( m_SkillPrepareTime );
		v.set_loopskillid( m_LoopSkillId );

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
		ObjCreateInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ObjCreateInfo& v)
	{
		m_ObjId = v.objid();
		m_Pos = v.pos();
		m_Dir = v.dir();
		m_Status = v.status();
		m_TargetPos = v.targetpos();
		m_ObjData = v.objdata();
		m_Motion = v.motion();
		m_IsNew = v.isnew();
		m_SkillPrepareId = v.skillprepareid();
		m_SkillPrepareTime = v.skillpreparetime();
		m_LoopSkillId = v.loopskillid();

	}

private:
	//id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
	}
private:
	//位置
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
	//状态
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//目标点（针对npc）
	Vector3Wraper m_TargetPos;
public:
	void SetTargetPos( const Vector3Wraper& v)
	{
		m_TargetPos=v;
	}
	Vector3Wraper GetTargetPos()
	{
		return m_TargetPos;
	}
	Vector3Wraper GetTargetPos() const
	{
		return m_TargetPos;
	}
private:
	//Obj 数据
	string m_ObjData;
public:
	void SetObjData( const string& v)
	{
		m_ObjData=v;
	}
	string GetObjData()
	{
		return m_ObjData;
	}
	string GetObjData() const
	{
		return m_ObjData;
	}
private:
	//移动信息
	MotionInfoWraper m_Motion;
public:
	void SetMotion( const MotionInfoWraper& v)
	{
		m_Motion=v;
	}
	MotionInfoWraper GetMotion()
	{
		return m_Motion;
	}
	MotionInfoWraper GetMotion() const
	{
		return m_Motion;
	}
private:
	//是否为新创建的obj
	bool m_IsNew;
public:
	void SetIsNew( bool v)
	{
		m_IsNew=v;
	}
	bool GetIsNew()
	{
		return m_IsNew;
	}
	bool GetIsNew() const
	{
		return m_IsNew;
	}
private:
	//蓄力技能Id
	INT32 m_SkillPrepareId;
public:
	void SetSkillPrepareId( INT32 v)
	{
		m_SkillPrepareId=v;
	}
	INT32 GetSkillPrepareId()
	{
		return m_SkillPrepareId;
	}
	INT32 GetSkillPrepareId() const
	{
		return m_SkillPrepareId;
	}
private:
	//蓄力技能时间
	INT32 m_SkillPrepareTime;
public:
	void SetSkillPrepareTime( INT32 v)
	{
		m_SkillPrepareTime=v;
	}
	INT32 GetSkillPrepareTime()
	{
		return m_SkillPrepareTime;
	}
	INT32 GetSkillPrepareTime() const
	{
		return m_SkillPrepareTime;
	}
private:
	//循环动作技能Id
	INT32 m_LoopSkillId;
public:
	void SetLoopSkillId( INT32 v)
	{
		m_LoopSkillId=v;
	}
	INT32 GetLoopSkillId()
	{
		return m_LoopSkillId;
	}
	INT32 GetLoopSkillId() const
	{
		return m_LoopSkillId;
	}

};
//活动时间信息封装类
class ActivityTimeWraper
{
public:
	//构造函数
	ActivityTimeWraper()
	{
		
		m_Begin = -1;
		m_End = -1;
		m_Id = -1;

	}
	//赋值构造函数
	ActivityTimeWraper(const ActivityTime& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityTime& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityTime ToPB() const
	{
		ActivityTime v;
		v.set_begin( m_Begin );
		v.set_end( m_End );
		v.set_id( m_Id );

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
		ActivityTime pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ActivityTime& v)
	{
		m_Begin = v.begin();
		m_End = v.end();
		m_Id = v.id();

	}

private:
	//活动开始时间
	INT32 m_Begin;
public:
	void SetBegin( INT32 v)
	{
		m_Begin=v;
	}
	INT32 GetBegin()
	{
		return m_Begin;
	}
	INT32 GetBegin() const
	{
		return m_Begin;
	}
private:
	//活动结束时间
	INT32 m_End;
public:
	void SetEnd( INT32 v)
	{
		m_End=v;
	}
	INT32 GetEnd()
	{
		return m_End;
	}
	INT32 GetEnd() const
	{
		return m_End;
	}
private:
	//活动id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}

};
//专精信息封装类
class ProfessionInfoWraper
{
public:
	//构造函数
	ProfessionInfoWraper()
	{
		
		m_Index = -1;

	}
	//赋值构造函数
	ProfessionInfoWraper(const ProfessionInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ProfessionInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ProfessionInfo ToPB() const
	{
		ProfessionInfo v;
		v.set_index( m_Index );
		v.mutable_skilllist()->Reserve(m_SkillList.size());
		for (int i=0; i<(int)m_SkillList.size(); i++)
		{
			v.add_skilllist(m_SkillList[i]);
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
		ProfessionInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ProfessionInfo& v)
	{
		m_Index = v.index();
		m_SkillList.clear();
		m_SkillList.reserve(v.skilllist_size());
		for( int i=0; i<v.skilllist_size(); i++)
			m_SkillList.push_back(v.skilllist(i));

	}

private:
	//索引
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
private:
	//技能列表
	vector<INT32> m_SkillList;
public:
	int SizeSkillList()
	{
		return m_SkillList.size();
	}
	const vector<INT32>& GetSkillList() const
	{
		return m_SkillList;
	}
	INT32 GetSkillList(int Index) const
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return INT32();
		}
		return m_SkillList[Index];
	}
	void SetSkillList( const vector<INT32>& v )
	{
		m_SkillList=v;
	}
	void ClearSkillList( )
	{
		m_SkillList.clear();
	}
	void SetSkillList( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_SkillList.size())
		{
			assert(false);
			return;
		}
		m_SkillList[Index] = v;
	}
	void AddSkillList( INT32 v = -1 )
	{
		m_SkillList.push_back(v);
	}

};
//珍宝阁数据信息封装类
class TreasureDepotDataWraper
{
public:
	//构造函数
	TreasureDepotDataWraper()
	{
		
		m_Level = 1;
		m_Point = 0;
		m_UnlockCount = -1;
		m_TotalPoint = 0;

	}
	//赋值构造函数
	TreasureDepotDataWraper(const TreasureDepotData& v){ Init(v); }
	//等号重载函数
	void operator = (const TreasureDepotData& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TreasureDepotData ToPB() const
	{
		TreasureDepotData v;
		v.set_level( m_Level );
		v.set_point( m_Point );
		v.mutable_treasure_data()->Reserve(m_Treasure_Data.size());
		for (int i=0; i<(int)m_Treasure_Data.size(); i++)
		{
			*v.add_treasure_data() = m_Treasure_Data[i].ToPB();
		}
		v.set_unlockcount( m_UnlockCount );
		v.set_totalpoint( m_TotalPoint );

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
		TreasureDepotData pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const TreasureDepotData& v)
	{
		m_Level = v.level();
		m_Point = v.point();
		m_Treasure_Data.clear();
		m_Treasure_Data.reserve(v.treasure_data_size());
		for( int i=0; i<v.treasure_data_size(); i++)
			m_Treasure_Data.push_back(v.treasure_data(i));
		m_UnlockCount = v.unlockcount();
		m_TotalPoint = v.totalpoint();

	}

private:
	//珍宝阁等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//珍宝阁点数
	INT32 m_Point;
public:
	void SetPoint( INT32 v)
	{
		m_Point=v;
	}
	INT32 GetPoint()
	{
		return m_Point;
	}
	INT32 GetPoint() const
	{
		return m_Point;
	}
private:
	//珍宝
	vector<TreasureDataWraper> m_Treasure_Data;
public:
	int SizeTreasure_Data()
	{
		return m_Treasure_Data.size();
	}
	const vector<TreasureDataWraper>& GetTreasure_Data() const
	{
		return m_Treasure_Data;
	}
	TreasureDataWraper GetTreasure_Data(int Index) const
	{
		if(Index<0 || Index>=(int)m_Treasure_Data.size())
		{
			assert(false);
			return TreasureDataWraper();
		}
		return m_Treasure_Data[Index];
	}
	void SetTreasure_Data( const vector<TreasureDataWraper>& v )
	{
		m_Treasure_Data=v;
	}
	void ClearTreasure_Data( )
	{
		m_Treasure_Data.clear();
	}
	void SetTreasure_Data( int Index, const TreasureDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_Treasure_Data.size())
		{
			assert(false);
			return;
		}
		m_Treasure_Data[Index] = v;
	}
	void AddTreasure_Data( const TreasureDataWraper& v )
	{
		m_Treasure_Data.push_back(v);
	}
private:
	//已解锁的外显总数
	INT32 m_UnlockCount;
public:
	void SetUnlockCount( INT32 v)
	{
		m_UnlockCount=v;
	}
	INT32 GetUnlockCount()
	{
		return m_UnlockCount;
	}
	INT32 GetUnlockCount() const
	{
		return m_UnlockCount;
	}
private:
	//解锁总共获得的点数
	INT32 m_TotalPoint;
public:
	void SetTotalPoint( INT32 v)
	{
		m_TotalPoint=v;
	}
	INT32 GetTotalPoint()
	{
		return m_TotalPoint;
	}
	INT32 GetTotalPoint() const
	{
		return m_TotalPoint;
	}

};
//ShopItem封装类
class ShopItemWraper
{
public:
	//构造函数
	ShopItemWraper()
	{
		
		m_ShopItemID = -1;
		m_TotalBuyCount = -1;
		m_BuyCount = -1;

	}
	//赋值构造函数
	ShopItemWraper(const ShopItem& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopItem& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopItem ToPB() const
	{
		ShopItem v;
		v.set_shopitemid( m_ShopItemID );
		v.set_totalbuycount( m_TotalBuyCount );
		v.set_buycount( m_BuyCount );

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
		ShopItem pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ShopItem& v)
	{
		m_ShopItemID = v.shopitemid();
		m_TotalBuyCount = v.totalbuycount();
		m_BuyCount = v.buycount();

	}

private:
	//ShopItemID
	INT32 m_ShopItemID;
public:
	void SetShopItemID( INT32 v)
	{
		m_ShopItemID=v;
	}
	INT32 GetShopItemID()
	{
		return m_ShopItemID;
	}
	INT32 GetShopItemID() const
	{
		return m_ShopItemID;
	}
private:
	//TotalBuyCount
	INT32 m_TotalBuyCount;
public:
	void SetTotalBuyCount( INT32 v)
	{
		m_TotalBuyCount=v;
	}
	INT32 GetTotalBuyCount()
	{
		return m_TotalBuyCount;
	}
	INT32 GetTotalBuyCount() const
	{
		return m_TotalBuyCount;
	}
private:
	//本次购买的数量
	INT32 m_BuyCount;
public:
	void SetBuyCount( INT32 v)
	{
		m_BuyCount=v;
	}
	INT32 GetBuyCount()
	{
		return m_BuyCount;
	}
	INT32 GetBuyCount() const
	{
		return m_BuyCount;
	}

};
//删除obj所需信息封装类
class ObjDeleteInfoWraper
{
public:
	//构造函数
	ObjDeleteInfoWraper()
	{
		
		m_ObjId = 0;
		m_SceneId = -1;
		m_ObjData = "";

	}
	//赋值构造函数
	ObjDeleteInfoWraper(const ObjDeleteInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const ObjDeleteInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ObjDeleteInfo ToPB() const
	{
		ObjDeleteInfo v;
		v.set_objid( m_ObjId );
		v.set_sceneid( m_SceneId );
		v.set_objdata( m_ObjData );

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
		ObjDeleteInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const ObjDeleteInfo& v)
	{
		m_ObjId = v.objid();
		m_SceneId = v.sceneid();
		m_ObjData = v.objdata();

	}

private:
	//obj id
	uint64_t m_ObjId;
public:
	void SetObjId( uint64_t v)
	{
		m_ObjId=v;
	}
	uint64_t GetObjId()
	{
		return m_ObjId;
	}
	uint64_t GetObjId() const
	{
		return m_ObjId;
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
	//obj数据
	string m_ObjData;
public:
	void SetObjData( const string& v)
	{
		m_ObjData=v;
	}
	string GetObjData()
	{
		return m_ObjData;
	}
	string GetObjData() const
	{
		return m_ObjData;
	}

};
//MatchLimit封装类
class MatchLimitWraper
{
public:
	//构造函数
	MatchLimitWraper()
	{
		
		m_MinIntegral = 0;
		m_MinSection = 0;
		m_MinLevel = 0;
		m_MaxLevel = 0;
		m_MaxIntegral = 0;
		m_MaxSection = 0;

	}
	//赋值构造函数
	MatchLimitWraper(const MatchLimit& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchLimit& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchLimit ToPB() const
	{
		MatchLimit v;
		v.set_minintegral( m_MinIntegral );
		v.set_minsection( m_MinSection );
		v.set_minlevel( m_MinLevel );
		v.set_maxlevel( m_MaxLevel );
		v.set_maxintegral( m_MaxIntegral );
		v.set_maxsection( m_MaxSection );

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
		MatchLimit pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MatchLimit& v)
	{
		m_MinIntegral = v.minintegral();
		m_MinSection = v.minsection();
		m_MinLevel = v.minlevel();
		m_MaxLevel = v.maxlevel();
		m_MaxIntegral = v.maxintegral();
		m_MaxSection = v.maxsection();

	}

private:
	//最小积分
	INT32 m_MinIntegral;
public:
	void SetMinIntegral( INT32 v)
	{
		m_MinIntegral=v;
	}
	INT32 GetMinIntegral()
	{
		return m_MinIntegral;
	}
	INT32 GetMinIntegral() const
	{
		return m_MinIntegral;
	}
private:
	//最小段位
	INT32 m_MinSection;
public:
	void SetMinSection( INT32 v)
	{
		m_MinSection=v;
	}
	INT32 GetMinSection()
	{
		return m_MinSection;
	}
	INT32 GetMinSection() const
	{
		return m_MinSection;
	}
private:
	//最低等级
	INT32 m_MinLevel;
public:
	void SetMinLevel( INT32 v)
	{
		m_MinLevel=v;
	}
	INT32 GetMinLevel()
	{
		return m_MinLevel;
	}
	INT32 GetMinLevel() const
	{
		return m_MinLevel;
	}
private:
	//最高等级
	INT32 m_MaxLevel;
public:
	void SetMaxLevel( INT32 v)
	{
		m_MaxLevel=v;
	}
	INT32 GetMaxLevel()
	{
		return m_MaxLevel;
	}
	INT32 GetMaxLevel() const
	{
		return m_MaxLevel;
	}
private:
	//最大积分
	INT32 m_MaxIntegral;
public:
	void SetMaxIntegral( INT32 v)
	{
		m_MaxIntegral=v;
	}
	INT32 GetMaxIntegral()
	{
		return m_MaxIntegral;
	}
	INT32 GetMaxIntegral() const
	{
		return m_MaxIntegral;
	}
private:
	//最大段位
	INT32 m_MaxSection;
public:
	void SetMaxSection( INT32 v)
	{
		m_MaxSection=v;
	}
	INT32 GetMaxSection()
	{
		return m_MaxSection;
	}
	INT32 GetMaxSection() const
	{
		return m_MaxSection;
	}

};
//排位匹配条件封装类
class MatchRankInfoWraper
{
public:
	//构造函数
	MatchRankInfoWraper()
	{
		
		m_Integral = 0;
		m_Section = 0;

	}
	//赋值构造函数
	MatchRankInfoWraper(const MatchRankInfo& v){ Init(v); }
	//等号重载函数
	void operator = (const MatchRankInfo& v){ Init(v); }
 	//转化成Protobuffer类型函数
	MatchRankInfo ToPB() const
	{
		MatchRankInfo v;
		v.set_integral( m_Integral );
		v.set_section( m_Section );

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
		MatchRankInfo pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}
	/*
	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}
	*/
	/*
	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}*/


private:
	//从Protobuffer类型初始化
	void Init(const MatchRankInfo& v)
	{
		m_Integral = v.integral();
		m_Section = v.section();

	}

private:
	//积分
	INT32 m_Integral;
public:
	void SetIntegral( INT32 v)
	{
		m_Integral=v;
	}
	INT32 GetIntegral()
	{
		return m_Integral;
	}
	INT32 GetIntegral() const
	{
		return m_Integral;
	}
private:
	//段位
	INT32 m_Section;
public:
	void SetSection( INT32 v)
	{
		m_Section=v;
	}
	INT32 GetSection()
	{
		return m_Section;
	}
	INT32 GetSection() const
	{
		return m_Section;
	}

};

#endif
