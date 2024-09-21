int BinaryGap (int N)
{
    int cnt = 0, ret = 0;
    int flg = 0;
    while (N)
    {
        if(N&1)
        {
            flg++;
            if ((cnt > ret) && (flg > 1))
            {
                ret = cnt;
            }
            cnt = 0;
        }
        else
        {
            cnt += flg > 0;
        }

        N >>= 1;
    }
    return ret;
}