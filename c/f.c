int solution(int A[])
{
    int sum = 0;
    int res;
    int len = sizeof(A)/sizeof(A[0]) + 2;
    if (len <3)
    {
        return 1;
    }
    for(int i = 0; i < len; i++)
    {
        res += i; 
    }
    for(int j = 0; j < len - 1; j++)
    {
        sum += A[j]; 
    }
    return (res - sum);
}

int main()
{
    int K[] = {2};
    printf("res = %d\n",solution(K));
}