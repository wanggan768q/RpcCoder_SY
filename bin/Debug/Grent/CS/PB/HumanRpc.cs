//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: HumanRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcMoveAsk")]
  public partial class HumanRpcMoveAsk : global::ProtoBuf.IExtensible
  {
    public HumanRpcMoveAsk() {}
    
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private float _X = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"X", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float X
    {
      get { return _X; }
      set { _X = value; }
    }
    private float _Z = (float)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Z", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Z
    {
      get { return _Z; }
      set { _Z = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcMoveReply")]
  public partial class HumanRpcMoveReply : global::ProtoBuf.IExtensible
  {
    public HumanRpcMoveReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private V3 _Pos = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public V3 Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcStopMoveAsk")]
  public partial class HumanRpcStopMoveAsk : global::ProtoBuf.IExtensible
  {
    public HumanRpcStopMoveAsk() {}
    
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private float _X = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"X", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float X
    {
      get { return _X; }
      set { _X = value; }
    }
    private float _Z = (float)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Z", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Z
    {
      get { return _Z; }
      set { _Z = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcStopMoveReply")]
  public partial class HumanRpcStopMoveReply : global::ProtoBuf.IExtensible
  {
    public HumanRpcStopMoveReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private V3 _Pos = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public V3 Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcMovementVerificationAsk")]
  public partial class HumanRpcMovementVerificationAsk : global::ProtoBuf.IExtensible
  {
    public HumanRpcMovementVerificationAsk() {}
    
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private float _X = (float)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"X", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float X
    {
      get { return _X; }
      set { _X = value; }
    }
    private float _Z = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Z", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Z
    {
      get { return _Z; }
      set { _Z = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcMovementVerificationReply")]
  public partial class HumanRpcMovementVerificationReply : global::ProtoBuf.IExtensible
  {
    public HumanRpcMovementVerificationReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private float _X = (float)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"X", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float X
    {
      get { return _X; }
      set { _X = value; }
    }
    private float _Z = (float)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Z", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Z
    {
      get { return _Z; }
      set { _Z = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcCGMoveCheckNotify")]
  public partial class HumanRpcCGMoveCheckNotify : global::ProtoBuf.IExtensible
  {
    public HumanRpcCGMoveCheckNotify() {}
    
    private float _Dir = (float)0;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)0)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private V3 _Pos = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public V3 Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"HumanRpcGCMoveCheckNotify")]
  public partial class HumanRpcGCMoveCheckNotify : global::ProtoBuf.IExtensible
  {
    public HumanRpcGCMoveCheckNotify() {}
    
    private float _Dir = (float)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Dir", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float Dir
    {
      get { return _Dir; }
      set { _Dir = value; }
    }
    private V3 _Pos = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public V3 Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}