using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//邮件配置表配置数据类
public class MailElement
{
	public int id;               	//邮件ID	邮件所对应的ID
	public string comment;       	//阶级注释	策划用
	public int platform_type;    	//平台类型	0安卓 1IOS （暂无）
	public int mail_type;        	//邮件类型	0纯文本邮件 1道具发放类 3物品找回类（暂无） 4系统消息
	public string mail_title;    	//邮件标题	
	public string mail_short_title;	//邮件省略标题	
	public string sender;        	//邮件发件人	
	public string call;          	//称呼	
	public string mail_body;     	//邮件正文	

	public bool IsValidate = false;
	public MailElement()
	{
		id = -1;
	}
};

//邮件配置表配置封装类
public class MailTable
{

	private MailTable()
	{
		m_mapElements = new Dictionary<int, MailElement>();
		m_emptyItem = new MailElement();
		m_vecAllElements = new List<MailElement>();
	}
	private Dictionary<int, MailElement> m_mapElements = null;
	private List<MailElement>	m_vecAllElements = null;
	private MailElement m_emptyItem = null;
	private static MailTable sInstance = null;

	public static MailTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MailTable();
			return sInstance;
		}
	}

	public MailElement GetElement(int key)
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

  public List<MailElement> GetAllElement(Predicate<MailElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Mail.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Mail.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Mail.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("Mail.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mail.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mail.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="platform_type"){Ex.Logger.Log("Mail.csv中字段[platform_type]位置不对应"); return false; }
		if(vecLine[3]!="mail_type"){Ex.Logger.Log("Mail.csv中字段[mail_type]位置不对应"); return false; }
		if(vecLine[4]!="mail_title"){Ex.Logger.Log("Mail.csv中字段[mail_title]位置不对应"); return false; }
		if(vecLine[5]!="mail_short_title"){Ex.Logger.Log("Mail.csv中字段[mail_short_title]位置不对应"); return false; }
		if(vecLine[6]!="sender"){Ex.Logger.Log("Mail.csv中字段[sender]位置不对应"); return false; }
		if(vecLine[7]!="call"){Ex.Logger.Log("Mail.csv中字段[call]位置不对应"); return false; }
		if(vecLine[8]!="mail_body"){Ex.Logger.Log("Mail.csv中字段[mail_body]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MailElement member = new MailElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.platform_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mail_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mail_title);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mail_short_title);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sender);
			readPos += GameAssist.ReadString( binContent, readPos, out member.call);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mail_body);

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("Mail.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mail.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mail.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="platform_type"){Ex.Logger.Log("Mail.csv中字段[platform_type]位置不对应"); return false; }
		if(vecLine[3]!="mail_type"){Ex.Logger.Log("Mail.csv中字段[mail_type]位置不对应"); return false; }
		if(vecLine[4]!="mail_title"){Ex.Logger.Log("Mail.csv中字段[mail_title]位置不对应"); return false; }
		if(vecLine[5]!="mail_short_title"){Ex.Logger.Log("Mail.csv中字段[mail_short_title]位置不对应"); return false; }
		if(vecLine[6]!="sender"){Ex.Logger.Log("Mail.csv中字段[sender]位置不对应"); return false; }
		if(vecLine[7]!="call"){Ex.Logger.Log("Mail.csv中字段[call]位置不对应"); return false; }
		if(vecLine[8]!="mail_body"){Ex.Logger.Log("Mail.csv中字段[mail_body]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			MailElement member = new MailElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.platform_type=Convert.ToInt32(vecLine[2]);
			member.mail_type=Convert.ToInt32(vecLine[3]);
			member.mail_title=vecLine[4];
			member.mail_short_title=vecLine[5];
			member.sender=vecLine[6];
			member.call=vecLine[7];
			member.mail_body=vecLine[8];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
