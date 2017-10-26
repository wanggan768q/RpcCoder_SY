namespace Editor
{
    using System;
    using System.Collections;
    using System.ComponentModel;

    public class ModuleDataStructConverter : StringConverter
    {
        public TypeConverter.StandardValuesCollection GetStandardValues(Module m)
        {
            ArrayList list = new ArrayList();
            foreach (DataStruct struct2 in m.moduleDataStruct)
            {
                if (struct2.ProtoType == DataStruct.protoTypeE.RpcProto)
                {
                    list.Add(struct2.StructName);
                }
            }
            return new TypeConverter.StandardValuesCollection(list.ToArray());
        }

        public override TypeConverter.StandardValuesCollection GetStandardValues(ITypeDescriptorContext context)
        {
            Module.OperaterItem.SubOperaterItem instance = (Module.OperaterItem.SubOperaterItem) context.Instance;
            Module m = instance.operaterItem.module;
            return this.GetStandardValues(m);
        }

        public override bool GetStandardValuesExclusive(ITypeDescriptorContext context) => 
            true;

        public override bool GetStandardValuesSupported(ITypeDescriptorContext context) => 
            true;
    }
}

