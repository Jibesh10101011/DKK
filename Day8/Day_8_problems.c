#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}node;
node *head;
node* search(int x)
{
    node *temp=head;
    while(temp)
    {
        if(temp->data==x)
        return temp;
        temp=temp->next;
    }
    return temp;
}
void createDll()
{
    head=NULL;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);
        head=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
}
void insertAfter()
{
    int x;
    printf("Enter Element after : ");
    scanf("%d",&x);
    node *temp=search(x);
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);

    if(!temp->next)
    {
        ptr->prev=temp;
        temp->next=ptr;
        ptr->next=NULL;
    }
    else 
    {
        ptr->next=temp->next;
        temp->next->prev=ptr;
        ptr->prev=temp;
        temp->next=ptr;
    }
}
void insertBefore()
{
    int x;
    printf("Enter Element before : ");
    scanf("%d",&x);
    node *temp=search(x);
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);
     
    if(temp==head)
    {
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
    else 
    {
        ptr->next=temp;
        temp->prev->next=ptr;
        ptr->prev=temp->prev;
        temp->prev=ptr;
    }
}
void insertByPos()
{
    node *temp=head;
    int ps;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);
     
    printf("\nEnter position : ");
    scanf("%d",&ps);

    for(int i=1;i<ps;i++)
    temp=temp->next;

    if(temp==head)
    {
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
    else 
    {
        ptr->next=temp;
        temp->prev->next=ptr;
        ptr->prev=temp->prev;
        temp->prev=ptr;
    }
}
void display()
{
    node *temp=head;
    while(temp)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
}
void displayRec(node *temp)
{
    if(!temp)
    return;
    printf("%d ",temp->data);
    displayRec(temp->next);
}
void deleteByElement()
{
    int x;
    printf("Enter element to be deleted : ");
    scanf("%d",&x);
    node *temp=search(x);
    if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
        free(temp);   
    }
    else if(!temp->next)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    else 
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
void append()
{
    int x;
    node *temp=head;
    while(temp->next)
       temp=temp->next;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);

    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else 
    {
        ptr->prev=temp;
        temp->next=ptr;
        ptr->next=NULL;

    }
}
void deleteByPos()
{
    int ps;
    printf("\nEnter position : ");
    scanf("%d",&ps);
    node* temp=head;

    for(int i=1;i<ps;i++)
        temp=temp->next;

    if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
        free(temp);   
    }
    else if(!temp->next)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    else 
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
void reverseprint()
{
    node*temp=head;
    while(temp->next)
        temp=temp->next;
    printf("Linked list printed in reverse order:\n");
    while (temp)    
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
void reverseDLL()
{
    node *ptr=head;
    node *temp=ptr->next;
    if(!temp) //if only 1 node
    return;
    node *u=temp->next;
    
    temp->next=temp->prev;
    temp->prev->prev=temp;
    temp->prev=NULL;
    temp->prev->next=NULL;
    head=temp;
    temp=u;
    while(temp)
    {
        u=temp->next;
        temp->next=temp->prev;
        temp->prev->prev=temp;
        temp->prev=NULL;
        head=temp;
        temp=u;
    }

}
void reverseDLL2()
{
    node *temp,*ptr;
    while (head->next)
        head=head->next;
    temp=head,ptr=head->prev;
    node* swap;
    while (ptr)
    {
        ptr = temp->prev;
        swap = temp->next;
        temp->next=temp->prev;
        temp->prev=swap;
        temp=ptr;
    }
        
}
void menu()
{
   int flag=1;
   while(flag)  
   {
    printf("Choose from the following:\n");
    printf("0. Create DLL\n");
    printf("1. To display list:\n");
    printf("2. To display using recursive function\n");
    printf("3. To reverse print\n");
    printf("4. To insert element after a node\n");
    printf("5. To insert element before a node\n");
    printf("6. To insert element at a given position\n");
    printf("7. To delete a given element\n");
    printf("8. To delete by a given position\n");
    printf("9. To reverse a linked list\n");
    printf("10. Append\n->>");
    int x;
    scanf("%d",&x);
    switch (x)
    {
         case 0:
        createDll();
        break;
    case 1:
        display();
        break;
    case 2:
        displayRec(head);
        break;
    case 3:
        reverseprint();
        break;
    case 4:
        insertAfter();
        break;
    case 5:
        insertBefore();
        break;
    case 6:
        insertByPos();
        break;
    case 7:
        deleteByElement();
        break;
    case 8:
        deleteByPos();
        break;
    case 9:
        reverseDLL2();
        break;
    case 10:
        append();
        break;
    default:
        printf("Sorry! wrong choice\n");
        break;
    }
    printf("\nDo you want to continue 1/0 ?\n");
    scanf("%d",&flag);
   }
}
int main()
{
  menu();
  return 0;
}