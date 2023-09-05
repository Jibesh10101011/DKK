#include<stdio.h>
int fibnacci(int n)  //Using for loop
{
    int a=0,b=1,c;
    printf("%d %d ",a,b);
    for(int i=0;i<n-2;i++)
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
}
int fib_using_while(int n)
{
    int a=0,b=1,c;
    printf("%d %d ",a,b);
    int t=n-2;
    while(t--)
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
}
int fib_using_do_while(int n) 
{   
    int a=0,b=1,c;
    printf("%d %d ",a,b);
    int t=n-3;
    do 
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
    while(t--);
}
int main()
{ 
  int n;
  scanf("%d",&n);
  fibnacci(n);
//   fib_using_while(n);
//   fib_using_do_while(n);
  return 0;
}