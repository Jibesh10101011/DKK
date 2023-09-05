#include<stdio.h>
void perm(char *str,int idx,int l,int *count)
{
   if(idx==l)
   {
      printf("%s\n",str);
      (*count)++;
      return;
   }
   int i;
   for(i=idx+1;i<l;i++)
   {   
         str[idx]=str[i]+str[idx]-(str[i]=str[idx]);
         perm(str,idx+1,l,count);
         str[idx]=str[i]+str[idx]-(str[i]=str[idx]);
   }
   }
int main()
{
  int n;
  printf("Enter the length of the string\n");
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  int c=0;
  perm(s,0,n,&c);
  printf("\n%d",c);
  return 0;
}