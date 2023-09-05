#include<stdio.h>
#include<stdlib.h>
void printFile(char *s)
{
    FILE *ptr=fopen(s,"r");
    char ch=fgetc(ptr);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(ptr);
    }
    fclose(ptr);
}
void mergeFile()
{
    char file1[50];
    char file2[50];
    printf("File-1 Name : \n");
    scanf("%s",file1);
    printf("File-2 Name : \n");  
    scanf("%s",file2);     //merge file1 and file2
    FILE *ptr1=fopen(file1,"r");
    FILE *ptr2=fopen(file2,"r");

    FILE *ptr3=fopen("file3.txt","w");
    char ch=fgetc(ptr1);
    while(ch!=EOF)       // File-1 data 
    {
        fprintf(ptr3,"%c",ch);
        ch=fgetc(ptr1);
    }
    
    ch=fgetc(ptr2);
    while(ch!=EOF)
    {
        fprintf(ptr3,"%c",ch);
        ch=fgetc(ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    printFile("file3.txt");
}
void copyFile()
{
    char file1[50];
    char file2[50];
    printf("File-1 Name : \n");
    scanf("%s",file1);
    printf("File-2 Name : \n");  // Copy File-1 data to File-2 
    scanf("%s",file2);
    FILE *ptr1=fopen(file1,"r");
    FILE *ptr2=fopen(file2,"w");
    char ch=fgetc(ptr1);
    while(ch!=EOF)
    {
        fprintf(ptr2,"%c",ch);
        ch=fgetc(ptr1);
    }
    fclose(ptr2);
    fclose(ptr1);
    printFile(file2);
}
void deleteFile()
{
    char file[50];
    printf("File Name : ");
    scanf("%s",file);
    if(remove(file))
    printf("Not succesfull deletion\n");
    else 
    printf("Success\n");
}
void menu()
{
    int x;
    char file_name[50];
    printf("1.  Print the contents of file\n");
    printf("2.  Copy contents of one file to another file\n");
    printf("3.  Merge contents of two file into a third file\n");
    printf("4.  Delete a File\n");
    scanf("%d",&x);
    switch (x)
    {
        case 1:
        printf("Enter File name : ");
        scanf("%s",file_name);
        printFile(file_name);
        break;
        case 2: 
        copyFile();
        break;
        case 3:
        mergeFile();
        break;
        case 4:
        deleteFile();
        break;
        case 5:
        exit(0);
    }
}
int main()
{
   menu();
}