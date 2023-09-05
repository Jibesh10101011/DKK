#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void circlee()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "c:\\turboc3\\BGI");
   circle(250, 200, 50);
   getch();
   closegraph();
}
void rectanglee() 
{
    int gd = DETECT, gm;
    int left = 150, top = 150;
    int right = 450, bottom = 450;
    initgraph(&gd, &gm, "c:\\turboc3\\BGI");
    rectangle(left, top, right, bottom);
    getch();
}
void trianglee() 
{
    int gd = DETECT, gm;
    int left = 150, top = 150;
    int right = 450, bottom = 450;
    initgraph(&gd, &gm, "c:\\turboc3\\BGI");
    line(150,150,450,450);
    line(150,150,300,300);
    line(450,150,300,300);
    line(150,150,300,300);
    getch();  
} 
void menu()
{
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    int n;
    printf("Input your option\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
         circlee();
         break;
        case 2:
         rectanglee();
         break;
        case 3:
         trianglee();
         break;
    }
}
int main()
{
  menu();
  return 0;
}
