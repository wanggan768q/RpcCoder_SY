//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: TreasureRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDepotInfoAsk")]
  public partial class TreasureRpcTreasureDepotInfoAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDepotInfoAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDepotInfoReply")]
  public partial class TreasureRpcTreasureDepotInfoReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDepotInfoReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private int _Level = (int)1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Level", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)1)]
    public int Level
    {
      get { return _Level; }
      set { _Level = value; }
    }
    private int _Point = (int)0;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Point", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Point
    {
      get { return _Point; }
      set { _Point = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureInfoAsk")]
  public partial class TreasureRpcTreasureInfoAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureInfoAsk() {}
    
    private int _Type = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Type
    {
      get { return _Type; }
      set { _Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureInfoReply")]
  public partial class TreasureRpcTreasureInfoReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureInfoReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<TreasureData> _Treasure_Info = new global::System.Collections.Generic.List<TreasureData>();
    [global::ProtoBuf.ProtoMember(2, Name=@"Treasure_Info", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<TreasureData> Treasure_Info
    {
      get { return _Treasure_Info; }
    }
  
    private int _Type = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Type
    {
      get { return _Type; }
      set { _Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureUnlockAsk")]
  public partial class TreasureRpcTreasureUnlockAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureUnlockAsk() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Color_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Color_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Color_Type
    {
      get { return _Color_Type; }
      set { _Color_Type = value; }
    }
    private int _Time_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Time_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Time_Type
    {
      get { return _Time_Type; }
      set { _Time_Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureUnlockReply")]
  public partial class TreasureRpcTreasureUnlockReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureUnlockReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private TreasureData _TreasureUnLocked = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TreasureUnLocked", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureUnLocked
    {
      get { return _TreasureUnLocked; }
      set { _TreasureUnLocked = value; }
    }
    private int _Points = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Points", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Points
    {
      get { return _Points; }
      set { _Points = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureEquipAsk")]
  public partial class TreasureRpcTreasureEquipAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureEquipAsk() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Color_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Color_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Color_Type
    {
      get { return _Color_Type; }
      set { _Color_Type = value; }
    }
    private int _Time_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Time_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Time_Type
    {
      get { return _Time_Type; }
      set { _Time_Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureEquipReply")]
  public partial class TreasureRpcTreasureEquipReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureEquipReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private TreasureData _TreasureEquiped = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TreasureEquiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureEquiped
    {
      get { return _TreasureEquiped; }
      set { _TreasureEquiped = value; }
    }
    private TreasureData _TreasureUnequiped = null;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"TreasureUnequiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureUnequiped
    {
      get { return _TreasureUnequiped; }
      set { _TreasureUnequiped = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureEquipSycAsk")]
  public partial class TreasureRpcTreasureEquipSycAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureEquipSycAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureEquipSycReply")]
  public partial class TreasureRpcTreasureEquipSycReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureEquipSycReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<TreasureData> _TreasueEquiped = new global::System.Collections.Generic.List<TreasureData>();
    [global::ProtoBuf.ProtoMember(2, Name=@"TreasueEquiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<TreasureData> TreasueEquiped
    {
      get { return _TreasueEquiped; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDepotLvUpAsk")]
  public partial class TreasureRpcTreasureDepotLvUpAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDepotLvUpAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDepotLvUpReply")]
  public partial class TreasureRpcTreasureDepotLvUpReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDepotLvUpReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private int _Level = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Level", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Level
    {
      get { return _Level; }
      set { _Level = value; }
    }
    private int _Point = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Point", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Point
    {
      get { return _Point; }
      set { _Point = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureUnEquipAsk")]
  public partial class TreasureRpcTreasureUnEquipAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureUnEquipAsk() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Color_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Color_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Color_Type
    {
      get { return _Color_Type; }
      set { _Color_Type = value; }
    }
    private int _Time_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Time_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Time_Type
    {
      get { return _Time_Type; }
      set { _Time_Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureUnEquipReply")]
  public partial class TreasureRpcTreasureUnEquipReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureUnEquipReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private TreasureData _TreasureUnequiped = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TreasureUnequiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureUnequiped
    {
      get { return _TreasureUnequiped; }
      set { _TreasureUnequiped = value; }
    }
    private TreasureData _TreasureEquiped = null;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"TreasureEquiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureEquiped
    {
      get { return _TreasureEquiped; }
      set { _TreasureEquiped = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureEquipedIDNotify")]
  public partial class TreasureRpcTreasureEquipedIDNotify : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureEquipedIDNotify() {}
    
    private TreasureEquipedID _TreasureID = null;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"TreasureID", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureEquipedID TreasureID
    {
      get { return _TreasureID; }
      set { _TreasureID = value; }
    }
    private int _ObjID = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"ObjID", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ObjID
    {
      get { return _ObjID; }
      set { _ObjID = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDelayTimeAsk")]
  public partial class TreasureRpcTreasureDelayTimeAsk : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDelayTimeAsk() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Color_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Color_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Color_Type
    {
      get { return _Color_Type; }
      set { _Color_Type = value; }
    }
    private int _Time_Type = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Time_Type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Time_Type
    {
      get { return _Time_Type; }
      set { _Time_Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureDelayTimeReply")]
  public partial class TreasureRpcTreasureDelayTimeReply : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureDelayTimeReply() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private TreasureData _TreasureUnLocked = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TreasureUnLocked", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureUnLocked
    {
      get { return _TreasureUnLocked; }
      set { _TreasureUnLocked = value; }
    }
    private int _Points = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Points", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Points
    {
      get { return _Points; }
      set { _Points = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"TreasureRpcTreasureUnlockEquipNotify")]
  public partial class TreasureRpcTreasureUnlockEquipNotify : global::ProtoBuf.IExtensible
  {
    public TreasureRpcTreasureUnlockEquipNotify() {}
    
    private int _Result = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private TreasureData _TreasureEquiped = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TreasureEquiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureEquiped
    {
      get { return _TreasureEquiped; }
      set { _TreasureEquiped = value; }
    }
    private TreasureData _TreasureUnequiped = null;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"TreasureUnequiped", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public TreasureData TreasureUnequiped
    {
      get { return _TreasureUnequiped; }
      set { _TreasureUnequiped = value; }
    }
    private int _Points = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Points", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Points
    {
      get { return _Points; }
      set { _Points = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}