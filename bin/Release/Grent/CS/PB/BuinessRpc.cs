//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: BuinessRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessSyncAsk")]
  public partial class BuinessRpcBuinessSyncAsk : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessSyncAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessSyncReply")]
  public partial class BuinessRpcBuinessSyncReply : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessSyncReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<BuinessSkillData> _SkillDatas = new global::System.Collections.Generic.List<BuinessSkillData>();
    [global::ProtoBuf.ProtoMember(2, Name=@"SkillDatas", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<BuinessSkillData> SkillDatas
    {
      get { return _SkillDatas; }
    }
  
    private readonly global::System.Collections.Generic.List<BuinessUnlockInfo> _UnLockInfos = new global::System.Collections.Generic.List<BuinessUnlockInfo>();
    [global::ProtoBuf.ProtoMember(3, Name=@"UnLockInfos", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<BuinessUnlockInfo> UnLockInfos
    {
      get { return _UnLockInfos; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessUnlockAsk")]
  public partial class BuinessRpcBuinessUnlockAsk : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessUnlockAsk() {}
    
    private int _SkillID = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SkillID", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillID
    {
      get { return _SkillID; }
      set { _SkillID = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessUnlockReply")]
  public partial class BuinessRpcBuinessUnlockReply : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessUnlockReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<BuinessSkillData> _ChangeSkillDatas = new global::System.Collections.Generic.List<BuinessSkillData>();
    [global::ProtoBuf.ProtoMember(2, Name=@"ChangeSkillDatas", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<BuinessSkillData> ChangeSkillDatas
    {
      get { return _ChangeSkillDatas; }
    }
  
    private BuinessUnlockInfo _UnLockInfo = null;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"UnLockInfo", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public BuinessUnlockInfo UnLockInfo
    {
      get { return _UnLockInfo; }
      set { _UnLockInfo = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessStudyAsk")]
  public partial class BuinessRpcBuinessStudyAsk : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessStudyAsk() {}
    
    private int _SkillID = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SkillID", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillID
    {
      get { return _SkillID; }
      set { _SkillID = value; }
    }
    private int _StudyType = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"StudyType", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int StudyType
    {
      get { return _StudyType; }
      set { _StudyType = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessStudyReply")]
  public partial class BuinessRpcBuinessStudyReply : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessStudyReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private BuinessSkillData _SkillData = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"SkillData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public BuinessSkillData SkillData
    {
      get { return _SkillData; }
      set { _SkillData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessMakeAsk")]
  public partial class BuinessRpcBuinessMakeAsk : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessMakeAsk() {}
    
    private int _SkillID = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SkillID", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillID
    {
      get { return _SkillID; }
      set { _SkillID = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BuinessRpcBuinessMakeReply")]
  public partial class BuinessRpcBuinessMakeReply : global::ProtoBuf.IExtensible
  {
    public BuinessRpcBuinessMakeReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private int _ItemID = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"ItemID", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ItemID
    {
      get { return _ItemID; }
      set { _ItemID = value; }
    }
    private int _ItemCount = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"ItemCount", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ItemCount
    {
      get { return _ItemCount; }
      set { _ItemCount = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}