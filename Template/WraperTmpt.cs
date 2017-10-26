
	//构造函数
	public $WraperName$()
	{
$ConstructField$
	}

	//重置函数
	public void ResetWraper()
	{
$ConstructField$
	}

 	//转化成Protobuffer类型函数
	public $PBName$ ToPB()
	{
		$PBName$ v = new $PBName$();
$ToPBField$
		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB($PBName$ v)
	{
        if (v == null)
            return;
$InitFuncField$
	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<$PBName$>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		$PBName$ pb = ProtoBuf.Serializer.Deserialize<$PBName$>(protoMS);
		FromPB(pb);
		return true;
	}

$GetSetSizeField$
