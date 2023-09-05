#include<stdio.h>
#include<string.h>
void p(char s[],char u[],int i,int r)
{  
    int j;
    if(i==r)
    { 
        printf("%s ",u);
        return;
    }
    for(j=i;s[j];j++) 
    {   
        if(u[i]!=s[j])
        {
            u[i]=s[j];
            u[i+1]='\0';
            s[i]=s[j]+s[i]-(s[j]=s[i]);
            p(s,u,i+1,r);
            s[i]=s[j]+s[i]-(s[j]=s[i]);
        }
    }
}
int main()
{   
    char s[200],u[200]="",r;
    printf("Enter a string you wish\n");
    scanf("%s",s);
    printf("Enter value of r =");
    scanf("%d",&r);
    p(s,u,0,r);
    return 0;
}
// void p(char s[],char u[],int i,int r)
// {  
//     int j;
//     if(i==r)
//     { 
//         printf("%s ",u);
//         return;
//     }
//     for(j=i;s[j];j++) 
//     {   
//         // u[i]=s[j];
//         if(u[i]==s[j])
//         {
//             continue;
//         } else {
//         u[i]=s[j];
//         u[i+1]='\0';
//         }
//         if(i!=j)
//         s[i]=s[j]+s[i]-(s[j]=s[i]);
//         p(s,u,i+1,r);
//         s[i]=s[j]+s[i]-(s[j]=s[i]);
//     }
// }