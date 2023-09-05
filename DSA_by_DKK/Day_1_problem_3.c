#include<stdio.h>
int find_elements(int *arr,int x,int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        return i;
    }
    return -1;
}
int main()
{
   int n;
   printf("Enter the length of the array\n");
   scanf("%d",&n);
   int a[n];
   printf("Input elements\n");
   int i;
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   int x;
   printf("Enter the element\n");
   scanf("%d",&x);
   int idx=find_elements(a,x,n);
   if(idx==-1)
   printf("Not found\n");
   else 
   printf("Element found at idx %d",idx);
}