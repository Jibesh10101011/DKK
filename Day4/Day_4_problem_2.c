#include<stdio.h>
#include<process.h>
#include<stdlib.h>
void f1()
{   
    
    int i,j;
    int height,width; // Unit px
    printf("Enter the height and width of the image : ") ;
    scanf("%d%d",&height,&width);
    int img[height][width];
    int val=255;
    int flag=1;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {    
             if(flag)
             {
               img[i][j]=255;
               flag=0;
             }
             else 
             { 
               img[i][j]=0;
               flag=1;
             }
        }
        flag=flag==0?1:0;
    }


    FILE *ptr=fopen("pic1.pgm","wb");
    	fprintf(ptr,"P2\n%d %d\n255\n", width, height);
    FILE *ptr2=fopen("pic2.pgm","wb");
        fprintf(ptr2,"P2\n%d %d\n255\n", width, height);
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        fprintf(ptr,"%d ",img[i][j]);
        fprintf(ptr,"\n");
    }

    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        fprintf(ptr2,"%d ",255-img[i][j]);
        fprintf(ptr2,"\n");
    }

    fclose(ptr);
    fclose(ptr2);

}
int main()
{
  f1();
  return 0;
}