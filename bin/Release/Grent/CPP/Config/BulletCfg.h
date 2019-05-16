#ifndef __BULLET_CONFIG_H
#define __BULLET_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//子弹类配置数据结构
struct BulletElement
{
	friend class BulletTable;
	int id;                      	//子弹ID	
	string comment;              	//描述	子弹备注信息，和显示无关
	int generateLocationType;    	//生成位置类型	0=读表，根据表中配置数据决定生成位置 1=技能选择位置 2=技能目标位置
	int generateNum;             	//产生数量	最大产生子弹的数量
	int generateType;            	//产生方式	0=平行 1=扇形 2=追踪
	float objParam;              	//发射偏转角度	初始子弹创建偏转角度
	float bulletGap;             	//子弹空间间隔	如果产生方式是0，则填入间隔距离； 如果产生方式是1，则填入角度。 单位：m
	float startRange;            	//生成点偏移距离	子弹生成时子弹起始位置与caster之间距离，单位：m
	float generateRange;         	//子弹生成距离	子弹以caster位置+生成点偏移距离为起始点，以子弹生成方向和该距离为参数生成子弹，单位：m
	int moveCount;               	//移动段数	子弹可飞行多段
	vector<int> moveType;        	//各段子弹移动类型	0=读表 1=飞向技能选择的位置 2=飞向技能目标 3=飞向技能选择的方向 4=飞向caster
	vector<int> deflectionAngle; 	//飞行偏移角度	当前方向（初始为生成方向）加偏转角度，作为子弹该段的飞行方向。若该段移动类型为飞向指定目标，则填0
	vector<float> maxRange;      	//最大距离	各段最大飞行距离（m），若该段移动方向或位置是玩家选择的，则填0占位
	vector<int> duration;        	//飞行时间	各段飞行时间，用连接符“|”连接，单位：ms 最大飞行距离为0时，表示子弹持续时间；距离大于0时，表示飞行时间； 当飞行时间填写0时，子弹按照发射速度进行移动
	vector<float> speed;         	//子弹飞行速度	各段飞行速度，用连接符“|”连接，单位：m/s 子弹发射的飞行速度
	vector<int> stayTime;        	//子弹停留时间	各段子弹停留时间，用连接符“|”连接，单位：ms
	vector<int> attackList;      	//产生效果的attackList	碰撞后产生的attackId，多个attack用连接符“|”连接
	string flyEffect;            	//特效名称	模型或特效名称
	int buffMount;               	//挂点ID	特效挂点ID
	string endEffect;            	//结束特效	子弹消失是是否播放特效 没有特效=不填 有特效填特效名称
	int flags;                   	//是否产生碰撞	0=穿墙 1=碰墙消失 2=碰墙停留
	int disappearType;           	//消失类型	0:走完整个过程消失 1:打足最大碰撞次数消失
	int maxCollisionTimes;       	//最大碰撞次数	 最大碰撞目标个数
	int isLast;                  	//是否持续伤害	一次性伤害=0，同一个人只受到一次伤害，在达到最远距离或打到最大碰撞次数后消失； 持续伤害=1，同一个人可受到多次伤害，在持续时间结束后消失
	int interval;                	//间隔时间	持续伤害的间隔时间，单位：ms
	int typeId;                  	//类型ID	客户端对特殊子弹的处理 0=常规 1=冰龙
	vector<int> triggerAttackId; 	//额外触发的attackid	当子弹触发效果区域和碰撞区域大小不一致时，将用于检测碰撞区域的attack的list填写到该列；区域大小一致时直接使用attackList，该列为空
	int hitOnce;                 	//同一个人是否伤害一次	弃用字段 同一个人是否伤害一次 0=否 1=是
	int hasFinalEffect;          	//到最大距离是否产生效果	弃用字段 服务器和客户端均未使用

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	BulletElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//子弹类配置封装类
class BulletTable
{
	friend class TableData;
private:
	BulletTable(){}
	~BulletTable(){}
	map<int, BulletElement>	m_mapElements;
	vector<BulletElement>	m_vecAllElements;
	BulletElement m_emptyItem;
public:
	static BulletTable& Instance()
	{
		static BulletTable sInstance;
		return sInstance;
	}

	BulletElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BulletElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("Bullet.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Bullet.bin", strTableContent ) )
		{
			printf_message("配置文件[Bullet.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 29)
		{
			printf_message("Bullet.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Bullet.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Bullet.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="generateLocationType"){printf_message("Bullet.csv中字段[generateLocationType]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="generateNum"){printf_message("Bullet.csv中字段[generateNum]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="generateType"){printf_message("Bullet.csv中字段[generateType]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="objParam"){printf_message("Bullet.csv中字段[objParam]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="bulletGap"){printf_message("Bullet.csv中字段[bulletGap]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="startRange"){printf_message("Bullet.csv中字段[startRange]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="generateRange"){printf_message("Bullet.csv中字段[generateRange]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="moveCount"){printf_message("Bullet.csv中字段[moveCount]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="moveType"){printf_message("Bullet.csv中字段[moveType]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="deflectionAngle"){printf_message("Bullet.csv中字段[deflectionAngle]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="maxRange"){printf_message("Bullet.csv中字段[maxRange]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="duration"){printf_message("Bullet.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="speed"){printf_message("Bullet.csv中字段[speed]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="stayTime"){printf_message("Bullet.csv中字段[stayTime]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="attackList"){printf_message("Bullet.csv中字段[attackList]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="flyEffect"){printf_message("Bullet.csv中字段[flyEffect]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="buffMount"){printf_message("Bullet.csv中字段[buffMount]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="endEffect"){printf_message("Bullet.csv中字段[endEffect]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="flags"){printf_message("Bullet.csv中字段[flags]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="disappearType"){printf_message("Bullet.csv中字段[disappearType]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="maxCollisionTimes"){printf_message("Bullet.csv中字段[maxCollisionTimes]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="isLast"){printf_message("Bullet.csv中字段[isLast]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="interval"){printf_message("Bullet.csv中字段[interval]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="typeId"){printf_message("Bullet.csv中字段[typeId]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="triggerAttackId"){printf_message("Bullet.csv中字段[triggerAttackId]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="hitOnce"){printf_message("Bullet.csv中字段[hitOnce]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="hasFinalEffect"){printf_message("Bullet.csv中字段[hasFinalEffect]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)29)
			{
				assert(false);
				return false;
			}
			BulletElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.generateLocationType=(int)atoi(vecLine[2].c_str());
			member.generateNum=(int)atoi(vecLine[3].c_str());
			member.generateType=(int)atoi(vecLine[4].c_str());
			member.objParam=(float)atof(vecLine[5].c_str());
			member.bulletGap=(float)atof(vecLine[6].c_str());
			member.startRange=(float)atof(vecLine[7].c_str());
			member.generateRange=(float)atof(vecLine[8].c_str());
			member.moveCount=(int)atoi(vecLine[9].c_str());
			member.flyEffect=vecLine[17];
			member.buffMount=(int)atoi(vecLine[18].c_str());
			member.endEffect=vecLine[19];
			member.flags=(int)atoi(vecLine[20].c_str());
			member.disappearType=(int)atoi(vecLine[21].c_str());
			member.maxCollisionTimes=(int)atoi(vecLine[22].c_str());
			member.isLast=(int)atoi(vecLine[23].c_str());
			member.interval=(int)atoi(vecLine[24].c_str());
			member.typeId=(int)atoi(vecLine[25].c_str());
			member.hitOnce=(int)atoi(vecLine[27].c_str());
			member.hasFinalEffect=(int)atoi(vecLine[28].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
