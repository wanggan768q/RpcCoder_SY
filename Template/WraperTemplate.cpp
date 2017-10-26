
//$CNName$封装类
class $WraperName$ : public DataWraperInterface $ModuleDataWraperDef$
{
public:
	//构造函数
	$WraperName$()
	{
		$ModuleDataSetWraper$
$ConstructField$
	}
	//赋值构造函数
	$WraperName$(const $PBName$& v){ Init(v); }
	//等号重载函数
	void operator = (const $PBName$& v){ Init(v); }
 	//转化成Protobuffer类型函数
	$PBName$ ToPB() const
	{
		$PBName$ v;
$ToPBField$
		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		$PBName$ pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
$HtmlFieldHeader$
		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
$htmlField$
		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const $PBName$& v)
	{
$InitFuncField$
	}

$GetSetSizeField$
};