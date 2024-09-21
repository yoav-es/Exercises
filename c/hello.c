#include <stdio.h>

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

int main() {
    int res = BinaryGap(20);
    printf("%d", res); // Removed the '&' as it's not needed to print an integer
    return 0;
}