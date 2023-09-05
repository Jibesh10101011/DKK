#include<stdio.h>
#include<stdlib.h>
typedef struct Arr {
    int *ar;
    int size;
    int count;
}Arr;
int linearSearch(int a[],int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        return i;
    }
    return -1;
}
int binraySearch(int a[],int x,int start,int end)
{
    if(start>end)
    return 0;
    int mid=(start+end)/2;
    if(a[mid]==x)
    return 1;
    if(a[mid]<x)
    return binraySearch(a,x,mid+1,end);
    return binraySearch(a,x,start,mid-1);
}
void display(Arr *A)
{  

    for(int i=0;i<A->count;i++)
        printf("%d ",A->ar[i]);
    printf("\n");
}
void insert(Arr *A,int x,int pos)
{
    if(A->count==A->size)
    {
        printf("Array is Full\n");
        return;
    }
    if(pos>A->count+1)
    {
        printf("Invalid position, range should be in 1 to %d\n",A->count+1);
        return;
    }
    for(int i=A->count;i>=pos;i--)
        A->ar[i]=A->ar[i-1];    
    A->ar[pos-1]=x;
    A->count++; //incrementing #elements
}
void deleteIndex(Arr* A,int pos)
{
    if(A->count==0)
    {
        printf("Array is Empty(Underflow) nothing to delete\n");
        return;
    }
    for(int i=pos-1;i<A->count-1;i++)
    A->ar[i]=A->ar[i+1];
    A->count--;
}
void deleteByItem(Arr *A,int x)
{
    int pos=linearSearch(A->ar,x,A->count)+1;
    deleteIndex(A,pos);
}
Arr* createArr()
{
    Arr *A=(Arr*)malloc(sizeof(Arr));
    printf("Enter the size of the Array : ");
    scanf("%d",&A->size);
    A->ar=(int*)calloc(A->size,sizeof(int));
    A->count=0;
    return A;
}
void bubbleSort(Arr *A)
{
    for(int i=0;i<A->count;i++)
    {
        for(int j=i+1;j<A->count;j++)
        {
            if(A->ar[i]>A->ar[j])
            A->ar[i]=A->ar[i]+A->ar[j]-(A->ar[j]=A->ar[i]);
        }
    }
}
void insertionsort(Arr* A)
{
    int i,j;
    for(i=0;i<A->count;i++)
    {
        for(j=i;j && A->ar[j]<A->ar[j-1];j--)
            A->ar[j] = A->ar[j]+A->ar[j-1] - (A->ar[j-1]=A->ar[j]);
    }
}
void search(Arr *A,int x)
{
    int idx=linearSearch(A->ar,x,A->count);
    if(idx==-1)
    {
        printf("Element not found\n");
        return;
    }
    printf("Element is found at index : %d\n",idx);
}
int main()
{
  Arr *A=createArr();
  for(int i=0;i<6;i++)  //arr = [1,56,54,13,24,22]
  {
     int u;
     scanf("%d",&u);
     insert(A,u,i+1); // insert(Array,element,position)
  }
    display(A);
    deleteIndex(A,2);  //deleteByPos 
    display(A);
    search(A,4);       //linearSearch
    display(A);
    int x;
    insertionsort(A);
    display(A);
    printf("Input Element for finding : ");
    scanf("%d",&x);
    if(binraySearch(A->ar,x,0,A->count-1))
    printf("Element Found\n");
    else 
    printf("Not exist\n");
     
    printf("Input Element for delete : ");  
    scanf("%d",&x);
    deleteByItem(A,x);  //deleted by value

    display(A);
  return 0;
}