using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//快速反应界面表配置数据类
public class QteUiElement
{
	public int id;               	//数据索引	
	public string comment;       	//任务备注	仅策划用
	public int ui_display_type;  	//qte所使用的UI展现类型	1：雷达型 2：计量表型 3：旋转显示型 4：点击型 5: 涂抹型
	public int delay_close_time; 	//qte成功后延迟多久关闭	单位为毫秒，0为立刻关闭 -1为不关闭（动画会循环播放）
	public string main_ui;       	//主UI	QTE触发后所弹出的主UI：图片名称
	public ls ui_1;              	//第1个ui素材	QTE成功后，所展现的第一个ui素材
	public lf ui_1_location;     	//第1个ui的位置	以屏幕正中为0|0 尽量填整数
	public int ui_1_value_1;     	//对应值1	
	public int ui_1_value_2;     	//对应值2	
	public ls ui_2;              	//第2个ui素材	QTE成功后，所展现的第2个ui素材
	public lf ui_2_location;     	//第2个ui的位置	以屏幕正中为0|0
	public int ui_2_value_1;     	//对应值1	
	public lf ui_2_value_2;      	//对应值2	
	public ls ui_3;              	//第3个ui素材	QTE成功后，所展现的第3个ui素材
	public lf ui_3_location;     	//第3个ui的位置	以屏幕正中为0|0
	public int ui_3_value_1;     	//对应值1	
	public int ui_3_value_2;     	//对应值2	
	public string dialog_img;    	//对话框背景图	
	public lf dialog_position;   	//对话框的位置	以屏幕正中为0|0
	public int dialog_value_1;   	//对话内容	StringNotice的ID
	public int dialog_value_2;   	//	暂时无用

	public bool IsValidate = false;
	public QteUiElement()
	{
		id = -1;
	}
};

//快速反应界面表配置封装类
public class QteUiTable
{

	private QteUiTable()
	{
		m_mapElements = new Dictionary<int, QteUiElement>();
		m_emptyItem = new QteUiElement();
		m_vecAllElements = new List<QteUiElement>();
	}
	private Dictionary<int, QteUiElement> m_mapElements = null;
	private List<QteUiElement>	m_vecAllElements = null;
	private QteUiElement m_emptyItem = null;
	private static QteUiTable sInstance = null;

	public static QteUiTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new QteUiTable();
			return sInstance;
		}
	}

	public QteUiElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<QteUiElement> GetAllElement(Predicate<QteUiElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("QteUi.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("QteUi.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[QteUi.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 21)
		{
			Ex.Logger.Log("QteUi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QteUi.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QteUi.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="ui_display_type"){Ex.Logger.Log("QteUi.csv中字段[ui_display_type]位置不对应"); return false; }
		if(vecLine[3]!="delay_close_time"){Ex.Logger.Log("QteUi.csv中字段[delay_close_time]位置不对应"); return false; }
		if(vecLine[4]!="main_ui"){Ex.Logger.Log("QteUi.csv中字段[main_ui]位置不对应"); return false; }
		if(vecLine[5]!="ui_1"){Ex.Logger.Log("QteUi.csv中字段[ui_1]位置不对应"); return false; }
		if(vecLine[6]!="ui_1_location"){Ex.Logger.Log("QteUi.csv中字段[ui_1_location]位置不对应"); return false; }
		if(vecLine[7]!="ui_1_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_1_value_1]位置不对应"); return false; }
		if(vecLine[8]!="ui_1_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_1_value_2]位置不对应"); return false; }
		if(vecLine[9]!="ui_2"){Ex.Logger.Log("QteUi.csv中字段[ui_2]位置不对应"); return false; }
		if(vecLine[10]!="ui_2_location"){Ex.Logger.Log("QteUi.csv中字段[ui_2_location]位置不对应"); return false; }
		if(vecLine[11]!="ui_2_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_2_value_1]位置不对应"); return false; }
		if(vecLine[12]!="ui_2_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_2_value_2]位置不对应"); return false; }
		if(vecLine[13]!="ui_3"){Ex.Logger.Log("QteUi.csv中字段[ui_3]位置不对应"); return false; }
		if(vecLine[14]!="ui_3_location"){Ex.Logger.Log("QteUi.csv中字段[ui_3_location]位置不对应"); return false; }
		if(vecLine[15]!="ui_3_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_3_value_1]位置不对应"); return false; }
		if(vecLine[16]!="ui_3_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_3_value_2]位置不对应"); return false; }
		if(vecLine[17]!="dialog_img"){Ex.Logger.Log("QteUi.csv中字段[dialog_img]位置不对应"); return false; }
		if(vecLine[18]!="dialog_position"){Ex.Logger.Log("QteUi.csv中字段[dialog_position]位置不对应"); return false; }
		if(vecLine[19]!="dialog_value_1"){Ex.Logger.Log("QteUi.csv中字段[dialog_value_1]位置不对应"); return false; }
		if(vecLine[20]!="dialog_value_2"){Ex.Logger.Log("QteUi.csv中字段[dialog_value_2]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			QteUiElement member = new QteUiElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_display_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.delay_close_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.main_ui);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_1_location);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_1_value_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_1_value_2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_2_location);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_2_value_1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_2_value_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ui_3_location);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_3_value_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_3_value_2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.dialog_img);
			readPos += GameAssist.ReadString( binContent, readPos, out member.dialog_position);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dialog_value_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dialog_value_2 );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 21)
		{
			Ex.Logger.Log("QteUi.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("QteUi.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("QteUi.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="ui_display_type"){Ex.Logger.Log("QteUi.csv中字段[ui_display_type]位置不对应"); return false; }
		if(vecLine[3]!="delay_close_time"){Ex.Logger.Log("QteUi.csv中字段[delay_close_time]位置不对应"); return false; }
		if(vecLine[4]!="main_ui"){Ex.Logger.Log("QteUi.csv中字段[main_ui]位置不对应"); return false; }
		if(vecLine[5]!="ui_1"){Ex.Logger.Log("QteUi.csv中字段[ui_1]位置不对应"); return false; }
		if(vecLine[6]!="ui_1_location"){Ex.Logger.Log("QteUi.csv中字段[ui_1_location]位置不对应"); return false; }
		if(vecLine[7]!="ui_1_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_1_value_1]位置不对应"); return false; }
		if(vecLine[8]!="ui_1_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_1_value_2]位置不对应"); return false; }
		if(vecLine[9]!="ui_2"){Ex.Logger.Log("QteUi.csv中字段[ui_2]位置不对应"); return false; }
		if(vecLine[10]!="ui_2_location"){Ex.Logger.Log("QteUi.csv中字段[ui_2_location]位置不对应"); return false; }
		if(vecLine[11]!="ui_2_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_2_value_1]位置不对应"); return false; }
		if(vecLine[12]!="ui_2_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_2_value_2]位置不对应"); return false; }
		if(vecLine[13]!="ui_3"){Ex.Logger.Log("QteUi.csv中字段[ui_3]位置不对应"); return false; }
		if(vecLine[14]!="ui_3_location"){Ex.Logger.Log("QteUi.csv中字段[ui_3_location]位置不对应"); return false; }
		if(vecLine[15]!="ui_3_value_1"){Ex.Logger.Log("QteUi.csv中字段[ui_3_value_1]位置不对应"); return false; }
		if(vecLine[16]!="ui_3_value_2"){Ex.Logger.Log("QteUi.csv中字段[ui_3_value_2]位置不对应"); return false; }
		if(vecLine[17]!="dialog_img"){Ex.Logger.Log("QteUi.csv中字段[dialog_img]位置不对应"); return false; }
		if(vecLine[18]!="dialog_position"){Ex.Logger.Log("QteUi.csv中字段[dialog_position]位置不对应"); return false; }
		if(vecLine[19]!="dialog_value_1"){Ex.Logger.Log("QteUi.csv中字段[dialog_value_1]位置不对应"); return false; }
		if(vecLine[20]!="dialog_value_2"){Ex.Logger.Log("QteUi.csv中字段[dialog_value_2]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)21)
			{
				return false;
			}
			QteUiElement member = new QteUiElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.ui_display_type=Convert.ToInt32(vecLine[2]);
			member.delay_close_time=Convert.ToInt32(vecLine[3]);
			member.main_ui=vecLine[4];
			member.ui_1=vecLine[5];
			member.ui_1_location=vecLine[6];
			member.ui_1_value_1=Convert.ToInt32(vecLine[7]);
			member.ui_1_value_2=Convert.ToInt32(vecLine[8]);
			member.ui_2=vecLine[9];
			member.ui_2_location=vecLine[10];
			member.ui_2_value_1=Convert.ToInt32(vecLine[11]);
			member.ui_2_value_2=vecLine[12];
			member.ui_3=vecLine[13];
			member.ui_3_location=vecLine[14];
			member.ui_3_value_1=Convert.ToInt32(vecLine[15]);
			member.ui_3_value_2=Convert.ToInt32(vecLine[16]);
			member.dialog_img=vecLine[17];
			member.dialog_position=vecLine[18];
			member.dialog_value_1=Convert.ToInt32(vecLine[19]);
			member.dialog_value_2=Convert.ToInt32(vecLine[20]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
