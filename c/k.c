// #include <stdio.h>
// #include <stdlib.h>
// int sol(int X, int Y, int D)
// {
//     int quot, rem;
//     quot = (Y - X) / D;
//     rem  = (Y - X) % D;
//     int res;
//     if (rem != 0)
//     {   
//         quot +=1;
//     }
//     return quot;
// }

// int main()
// {
//     printf("quot is %d\n", sol(10,85,30));
// }

#include <stdio.h>

union check_endian
{
    unsigned int value;
    char r;
};


union check_endian endian;

  
int main(void)
{
    endian.value = 0x1;
 
    if (endian.r == 1) 
        printf("Your system is Little Endian\n");
    else
        printf("Your system is Big Endian\n");
    return 0;
}