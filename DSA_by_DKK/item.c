#include<stdio.h>
#include<stdlib.h>
#define bool int


int fibnacci(int n)
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
void perm(char *str,int idx,int l,int *count)
{
   if(idx==l)
   {
      printf("%s\n",str);
      (*count)++;
      return;
   }
   int i;
   for(i=idx;i<l;i++)
   {
      str[idx]=str[i]+str[idx]-(str[i]=str[idx]);
      perm(str,idx+1,l,count);
      str[idx]=str[i]+str[idx]-(str[i]=str[idx]);
   }
}
bool isprime(int n)
{
    if(n<=1)
        return 0;
    int i;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int power(int base,int ex)
{
    int ans=1;
    while(ex)
    {
        if(ex%2)
            ans*=base;
        base*=base;
        ex/=2;
    }
    return ans;
}
bool isarmstrong(int n)
{
    // calculating number of digits
    int num = n,dig=0;
    while(num){
        dig++;
        num/=10;
    }
    num=n;
    int rem=0;
    while(num)
    {
        rem += power(num%10,dig);
        num /= 10;
    }
    if(n==rem)
        return 1;
    return 0;
}
void menu()
{
    int choice;
    scanf("%d",&choice);
    int n;
    int a,b,c;
    switch (choice)
    {
        case 1:
            scanf("%d",&n);
            printf("%s\n",isprime(n)?"yes":"no");
            break;
        case 2:
            scanf("%d",&n);
            printf("%s\n",isarmstrong(n)?"yes":"no");
            break;
        case 3:
            scanf("%d%d%d",&a,&b,&c);
            if(a>=b)
            {
                if(a>=c)
                    printf("%d\n",a);
                else
                    printf("%d\n",c);
            }
            else{
                if(b>=c)
                    printf("%d\n",b);
                else    
                    printf("%d\n",c);
            }
        case 4:
            exit(0);
    }
}
int main()
{
  menu();
  return 0;
}