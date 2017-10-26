using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace BattleKernel
{
    //战斗核心动作枚举
    public enum KernelActionE
    {
        ACTION_NOOP = 0,
$ActionEnum$
    }

    public class ActionPoolManager {

        private static ActionPoolManager _instance;

        public static ActionPoolManager GetInstance() { 
            if (_instance == null) {
                _instance = new ActionPoolManager();
            }
            return _instance;
        }

$DefineActionPool$

        public Action CreateAction(KernelActionE actionType)
        {
$PoolCreateAction$
            return null;
        }

        public void StoreAction(Action action)
        {
$PoolStoreAction$
        }

    }

    public abstract class Action : Ex.IResetable
    {
        public Action()
        {
            ActionType = KernelActionE.ACTION_NOOP;
        }
        public virtual MemoryStream GetWraperStream()
        {
            return new MemoryStream();
        }
        public virtual void SetWraperStream(MemoryStream ms)
        {
        }
        public virtual int Serialize(MemoryStream ms)
        {
            MemoryStream tmpStream = new MemoryStream();
            Int16 Len = 0;
            tmpStream.Write(BitConverter.GetBytes(Len), 0, 2);
            tmpStream.WriteByte(m_ActionType);
            tmpStream.Write(BitConverter.GetBytes(m_OccurTime), 0, 4);
            byte[] dataArr = GetWraperStream().ToArray();
            tmpStream.Write(dataArr, 0, dataArr.Length);
            Len = (Int16)tmpStream.Length;
            tmpStream.Position = 0;
            tmpStream.Write(BitConverter.GetBytes(Len), 0, 2);

            ms.Write(tmpStream.ToArray(), 0, (int)tmpStream.Length);
            return (int)tmpStream.Length;
        }
        public void Create(byte[] buf)
        {
            OccurTime = BitConverter.ToInt32(buf, 1);
            SetWraperStream(new MemoryStream(buf, 5, buf.Length - 5));
        }

        public static Action Deserialize(byte[] buf)
        {
            try 
            {
                KernelActionE aType = (KernelActionE)buf[0];
                switch (aType)
                {
$ActionDeserialize$
                    default:
                        break;
                }
            }
            catch( Exception e )
            {
                e.GetType();
            }
            return null;
        }

        public Int32 OccurTime
        {
            get { return m_OccurTime; }
            set { m_OccurTime = value; }
        }
        public KernelActionE ActionType
        {
            set { m_ActionType = (byte)value; }
            get { return (KernelActionE)m_ActionType; }
        }
        protected byte m_ActionType = 0;
        protected Int32 m_OccurTime = 0;

        public virtual void New()
        {
            ActionType = KernelActionE.ACTION_NOOP;
            m_OccurTime = 0;
        }

        public virtual void Reset()
        {
            ActionType = KernelActionE.ACTION_NOOP;
            m_OccurTime = 0;
        }
    }

$ActionClass$

}
