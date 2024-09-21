#include <stdio.h>

int * solution(int A[], int N, int K)
{
    int res[5] = {0};
    if (N == 0)
    {
        return res;
    }
    int i =0;
    int j =0;
    K%=N; 
    for (i = 0, j = K; i<N; i++)
    {
        res[j] = A[i];
        j = (j+1)%N;
    }

    return res;
}



int main() {
    // You must mention the size of the array, if you want more than one
    // element initialized to 0
    // Here, all 5 elements are set to 0!
    int arr[5] = {10, 20, 30, 40, 50};
    int * res = solution(arr,5,3);
    for (int i=0; i<5; i++) {
        printf("%d\n", &res[i]);
    }
    return 0;
}