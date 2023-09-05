#include<stdio.h>
#include<time.h>
int main()
{
    clock_t begin = clock();
    int a;
    for(int i=0;i<10000;i++)
        for(int j=0;j<10000;j++)
            a=5;
    double output = (double)(clock()-begin)/CLOCKS_PER_SEC;
    printf("The out put is %f",output);
    return 0;
}