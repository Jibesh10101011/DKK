#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define bool int 
#define true 1
#define false 0
clock_t start;
clock_t end;
double getTime1();

    // double time_spent = 0.0;
    // clock_t begin = clock();
    // clock_t end = clock();
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("The elapsed time is %f seconds", time_spent);

void printFile()
{
    FILE *ptr=fopen("file.txt","w");
    fprintf(ptr,"\nTime is : %f seconds\n",getTime1());
    fclose(ptr);
}
double getTime1()
{
    return (double)(clock()-start)/CLOCKS_PER_SEC;
}
void bubbleSort(int a[],int n)
{

    start = clock();
    double time_spent=0.0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(a[j-1]>a[j])
            a[j]=a[j-1]+a[j]-(a[j-1]=a[j]);
        }
    }
    printf("\nTime is : %f seconds\n",getTime1());
    printFile();
}
void modefiedBubbleSort(int a[],int n)
{
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=false;
        for(int j=1;j<=n-i;j++)
        {
            if(a[j-1]>a[j])
            {
              a[j]=a[j-1]+a[j]-(a[j-1]=a[j]);
              flag=true;
            }
        }
        if(!flag)
        break;
    }

}
void selectionSort(int a[],int n)
{
     for(int i=0;i<n;i++)
     {  
        int idx=i;
        for(int j=i+1;j<n;j++)
        {
           if(a[idx]>a[j])   
           idx=j;
        }
        a[i]=a[i]+a[idx]-(a[idx]=a[i]);
     }
}
void insertionSort(int* a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j && a[j]<a[j-1];j--)
            a[j]=a[j]+a[j-1]-(a[j-1]=a[j]);
    }
}
void mergeArr(int arr[],int bgn1,int n1,int bgn2,int n2)
{
    int a[n1+n2-bgn1-bgn2+2];
    int i1=bgn1,i2=bgn2,i=0;
    while(i1<=n1&&i2<=n2)
    {
        if(arr[i1]<arr[i2])
        {
           a[i]=arr[i1];
           i1++;
        }
        else 
        {
            a[i]=arr[i2];
            i2++;
        }
        i++;
    }
    while(i1<=n1)
    {
       a[i]=arr[i1];
       i1++,i++;
    }
    while(i2<=n2)
    {
       a[i]=arr[i2];
       i++,i2++;
    }
    for(int u=bgn1;u<=n2;u++)
    arr[u]=a[u-bgn1];
}
void mergeSort(int arr[],int start,int end)
{
    if(start==end)
    return;
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    mergeArr(arr,start,mid,mid+1,end);
}
void printArr(int a[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
void menu(int arr[],int n)
{
    FILE *ptr=fopen("file.txt","w");
    printf("1. Selection Sort\n");
    fprintf(ptr,"1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    fprintf(ptr,"1. Bubble Sort\n");
    printf("3. Modified bubble Sort\n");
    fprintf(ptr,"1. Modified Bubble Sort\n");
    printf("4. Insertion Sort\n");
    fprintf(ptr,"1. Insertion Sort Sort\n");
    printf("5. Merge Sort\n--> ");
    fprintf(ptr,"1. Merge Sort\n");
    fclose(ptr);
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 1:
        selectionSort(arr,n);
        break;
        case 2:
        bubbleSort(arr,n);
        break;
        case 3:
        modefiedBubbleSort(arr,n);
        break;
        case 4:
        insertionSort(arr,n);
        break;
        case 5:
        mergeSort(arr,0,n-1);
        break;
        default:
        break;
    }
    // printArr(arr,n);
}
void f1()
{
    int n;
    printf("Enter the size of the Array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Input the elements of the array : \n");
    for(int i=n;i>=1;i--)
    arr[i-1]=i;
    menu(arr,n);

}
int main()
{
   f1();
   return 0;
}