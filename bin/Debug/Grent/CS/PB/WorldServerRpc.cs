//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: WorldServerRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"WorldServerRpcChangeSceneAsk")]
  public partial class WorldServerRpcChangeSceneAsk : global::ProtoBuf.IExtensible
  {
    public WorldServerRpcChangeSceneAsk() {}
    
    private ulong _RoleId = (ulong)0;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"RoleId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((ulong)0)]
    public ulong RoleId
    {
      get { return _RoleId; }
      set { _RoleId = value; }
    }
    private int _CurSceneId = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"CurSceneId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int CurSceneId
    {
      get { return _CurSceneId; }
      set { _CurSceneId = value; }
    }
    private int _TargetSceneId = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"TargetSceneId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int TargetSceneId
    {
      get { return _TargetSceneId; }
      set { _TargetSceneId = value; }
    }
    private int _MemId = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"MemId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int MemId
    {
      get { return _MemId; }
      set { _MemId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"WorldServerRpcChangeSceneReply")]
  public partial class WorldServerRpcChangeSceneReply : global::ProtoBuf.IExtensible
  {
    public WorldServerRpcChangeSceneReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private ulong _RoleId = (ulong)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"RoleId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((ulong)0)]
    public ulong RoleId
    {
      get { return _RoleId; }
      set { _RoleId = value; }
    }
    private int _CurSceneId = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"CurSceneId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int CurSceneId
    {
      get { return _CurSceneId; }
      set { _CurSceneId = value; }
    }
    private int _TargetSceneId = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"TargetSceneId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int TargetSceneId
    {
      get { return _TargetSceneId; }
      set { _TargetSceneId = value; }
    }
    private int _MemId = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"MemId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int MemId
    {
      get { return _MemId; }
      set { _MemId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"WorldServerRpcEnterSceneAsk")]
  public partial class WorldServerRpcEnterSceneAsk : global::ProtoBuf.IExtensible
  {
    public WorldServerRpcEnterSceneAsk() {}
    
    private ulong _RoleId = (ulong)0;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"RoleId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((ulong)0)]
    public ulong RoleId
    {
      get { return _RoleId; }
      set { _RoleId = value; }
    }
    private int _SceneId = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"SceneId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SceneId
    {
      get { return _SceneId; }
      set { _SceneId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"WorldServerRpcEnterSceneReply")]
  public partial class WorldServerRpcEnterSceneReply : global::ProtoBuf.IExtensible
  {
    public WorldServerRpcEnterSceneReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}