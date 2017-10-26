    //$CNName$
    public class $ActionName$ : $WraperName$
    {
        public override MemoryStream GetWraperStream()
        {
            return ToMemoryStream();
        }
        public override void SetWraperStream(MemoryStream ms)
        {
            FromMemoryStream(ms);
        }
        public override void New()
        {
            base.New();
            ActionType = KernelActionE.$ACTION_ENUM$;
        }
        public override void Reset()
        {
            base.Reset();
            ResetWraper();
        }
    }
