////
//// Created by yoav9 on 09/02/2022.
////
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "math.h"

/**
 * A function that parses the number and checks if it has two identical consecutive digits, return 0 if there isn't
 * or the index of the less significant identical digit
 * @param number : the number to be tested
 * @return 0 if no two identical digits, or index of the less significant digit
 */
int helper(int number)
{
    char data[512];
    sprintf(data, "%d", number);
    int length = strlen(data);
    char k = data[0];
    for(int i = 1; i < length; i++)
    {
        if(k == data[i])
        {
            return length - i;
        }
        k = data[i];
    }
    return 0;
}

/**
 * A function that resets values in a number to zero
 * @param number - the number to parse
 * @param ind: the index to reset from
 * @return the changed number
 */
int helper2(int number, int ind)
{
    char data[512];
    char *ptr;
    sprintf(data, "%d", number);
    int length = strlen(data);
    int k;
    int l = 0;
    for(int i = length-1; i > length - ind  ; i--)
    {
       data[i] = (l == 0) ? '1' : '0';
       l = (l==0) ? 1 : 0;
    }
    k = strtol(data, &ptr,10);
    return k;
}

/**
 * The function that finds the next number of a given number that doesnt have two identical consecutive digits
 * @param number the number which predecessor were looking for
 * @return : the next number
 */
int func(int number)
{
    int mul = 1;
    int num = number + mul;
    int res = helper(num);
    while (res > 0)
    {
        mul = pow(10, res-1);
        num = num + mul;
        if(res > 1)
        {
            num = helper2(num,res);
        }
        res = helper(num);
    }
    return num;
}


//tests
int main()
{
    printf("res is = %d\n", func(55)); //should give 56
    printf("res is = %d\n", func(1765)); //should give 1767
    printf("res is = %d\n", func(98)); // should give 101
    printf("res is = %d\n", func(44432)); // should give 45010
    printf("res is = %d\n", func(3298)); // should give 3401
}

main();
