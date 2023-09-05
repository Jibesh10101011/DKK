#include<stdio.h>
typedef struct Student {
    int rollNumber;
    char name[50];
    float marks;
}Student;
void printFromFileToConsole()
{   
    char file[200];
    printf("Enter your filename with extesion you want to read\n");
    scanf("%s",file);
    FILE *ptr=fopen(file,"r");
    char ch=fgetc(ptr);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(ptr);
    }
    fclose(ptr);
}
int main()
{      
        Student s;
        char filename[40];  
        printf("enter binary file: ");
        scanf("%s", filename);
        FILE *file8 = fopen(filename,"ab+");
        printf("Enter student name: ");
        scanf("%s", &s.name);
        fprintf(file8,"Name : %s\n",s.name);
        printf("Enter roll no: ");
        scanf("%d",&s.rollNumber);
        fprintf(file8,"Roll No : %d\n",s.rollNumber);
        printf("Enter student marks: ");
        scanf("%f", &s.marks);
        fprintf(file8,"Marks %f\n",s.marks);
        printf("Dispaly all data:\n");  // In console
        printf("Name : %s Roll No : %d Marks : %f\n",s.name,s.rollNumber,s.marks);
        fclose(file8);
        printFromFileToConsole();
        // while (fread(&s, sizeof(struct Student), 1, file8)) {
        // printf("Name: %s, Marks: %.2f, Roll no:%d \n", s.name, s.marks,s.rollNumber);
        // }
  return 0;
}