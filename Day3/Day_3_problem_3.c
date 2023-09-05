#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{   
   struct node *next;
   char name[50];
   int marks;
}node;
node *last=NULL;
void insert(int data,char name[])
{
    node *t=last;
    if(!last)
    {
        node *n=(node*)malloc(sizeof(node));
        n->marks=data;
        strcpy(n->name,name);
        last=n;
        n->next=n;
        return;
    }
    node *n=(node*)malloc(sizeof(node));
    n->marks=data;
    strcpy(n->name,name);
    n->next=last->next;
    last->next=n;
    last=n; 
}
node* search(char *name,int marks)
{
    node *t=last;
    while(strcmp(t->next->name,name)&&t->next->marks!=marks)
    t=t->next;
    return t;
}
void delete(char *name,int marks)
{
    node *prev=search(name,marks);
    node *curr=prev->next;
    if(curr==last)
    {
        if(last==last->next)   // Single Node
        {
             free(last);
             last=NULL;
             return;
        }
        else 
        {
            prev->next=last->next;
            free(last);
            last=prev;
            return;
        }
    }
    prev->next=curr->next;
    free(curr);
}
void printFile()
{
    FILE *ptr=fopen("file.txt","w");
    node *t=last->next;
    while(t!=last)
    {
        fprintf(ptr,"%s      %d\n",t->name,t->marks);
        t=t->next;
    }
    fprintf(ptr,"%s      %d\n",t->name,t->marks);
}
void printData()
{
    node *t=last->next;
    while(t!=last)
    {
        printf("Name %s marks %d\n",t->name,t->marks);
        t=t->next;
    }
    printf("Name %s marks %d",t->name,t->marks);
}
void append()
{
    char name[40];
    int marks;
    printf("Name : ");
    scanf("%s",name);
    printf("\nMarks : ");
    scanf("%d",&marks);
    insert(marks,name);
}
void deleteRecord()
{
    char name[40];
    int marks;
    printf("Student's Name : ");
    fgets(name,20,stdin);
    printf("\n Marks : ");
    scanf("%d",&marks);
    delete(name,marks);
}
void updateData()
{
    char name[40];
    int marks;
    int new_marks;
    printf("Enter Name of the student : ");
    fgets(name,40,stdin);
    printf("\nEnter the old marks : ");
    scanf("%d",&marks);
    node *prev=search(name,marks);
    printf("\nEnter new marks of student : ");
    scanf("%d",&new_marks);
    prev->next->marks=new_marks;
}
void menu()
{
    int x;
    printf("1. Append new record of a student\n");
    printf("2. Delete a record of a specific student\n");
    printf("3. Update a field of student\n");
    printf("4. Display All records\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        append();
        break;
        case 2:
        deleteRecord();
        break;
        case 3:
        updateData();
        break;
        case 4:
        printFile();  // All new records we can watch in the file;
    }
}
int main()
{
  int i;
  char na[50];
  int marks;
  for(int i=0;i<4;i++)
  {
     menu();
  }
//   printData();
// //   printData();
//   printf("\n\n\n");
//   delete(na,marks);
//   printf("\n\n\n");
// //   printData();
// printFile();
//   printf("\n\n\n\n\n");
//   scanf("%s %d",na,&marks);

//   node *temp=search(na,marks);
//   temp=temp->next;
//   printf("%s    %d",temp->name,temp->marks);
  return 0;
}