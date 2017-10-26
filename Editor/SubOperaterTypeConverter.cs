namespace Editor
{
    using System;
    using System.Collections;
    using System.ComponentModel;

    public class SubOperaterTypeConverter : StringConverter
    {
        public override TypeConverter.StandardValuesCollection GetStandardValues(ITypeDescriptorContext context)
        {
            Module.OperaterItem.SubOperaterItem instance = (Module.OperaterItem.SubOperaterItem) context.Instance;
            Module module = instance.operaterItem.module;
            ArrayList list = new ArrayList {
                Module.OperateType.OP_ASK,
                Module.OperateType.OP_REPLY,
                Module.OperateType.OP_CLIENT_NOTIFY,
                Module.OperateType.OP_SERVER_NOTIFY,
                Module.OperateType.OP_DUPLEX_NOTIFY
            };
            return new TypeConverter.StandardValuesCollection(list.ToArray());
        }

        public override bool GetStandardValuesExclusive(ITypeDescriptorContext context) => 
            true;

        public override bool GetStandardValuesSupported(ITypeDescriptorContext context) => 
            true;
    }
}

