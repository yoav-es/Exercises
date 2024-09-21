#include <stdio.h>

int rehabCalc(int A[], int N, int X, int Y)
{
    int min = 10000;
    for (int j = 0; j < (N - Y ) ; j++)
    {
        int tmpsum = 0;
        int k = 0;
        for (int i = j; i <= (N - 1); i+= Y)
        {
            tmpsum += A[i];
            if(k == X)
            {
                break;
            }
            k++;
        }

        if (min > tmpsum && k == X)
        {
            min = tmpsum;
        }
    }
    return  min;
}



int main()
{
    int A1[] = {4,2,3,7};
    int A2[] = {10,3,4,7};
    int A3[] = {4,2,5,4,3,5,1,4,2,7};

    printf("the minimum cos of rehabilitation is %d\n", rehabCalc(A1,4,2,2));
    printf("the minimum cos of rehabilitation is %d\n", rehabCalc(A2,4,2,3));
    printf("the minimum cos of rehabilitation is %d\n", rehabCalc(A3,9,3,2));
}




