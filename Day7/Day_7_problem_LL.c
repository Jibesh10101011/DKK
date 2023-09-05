#include<stdio.h>
#include<stdlib.h>
#define bool int 
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
void display() 
{
    node *temp=head;
    printf("Linked List is : \nstart");
    while(temp)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reversePrint()
{
    node *temp=head;
    int arr[1000];    // Let's assume maximum 1000 nodes
    int idx=0;
    while(temp)
    {
        arr[idx]=temp->data;
        temp=temp->next;
        idx++;
    }
    for(int i=idx-1;i>=0;i--)
    printf("%d ",arr[i]);
    printf("\n");

}
void displayRec(node *temp)
{
    if(!temp)
    return;
    printf("->%d",temp->data);
    displayRec(temp->next);
}
node* search(int data)
{
    node *temp=head;
    while(temp)
    {
        if(temp->data==data)
        return temp;
        temp=temp->next;
    }
    return temp;
}
void creation()
{
    int flag;
    int val;
    node *temp=head;
    node *ptr=(node*)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&ptr->data);
    head=ptr;
    printf("Do you want to continue 1/0 ?\n");
    scanf("%d",&flag);
    while(flag)
    {   
        ptr->next=(node*)malloc(sizeof(node));
        printf("Enter the data : ");
        scanf("%d",&ptr->next->data);
        ptr=ptr->next;
        printf("Do you want to continue 1/0 ?\n");
        scanf("%d",&flag);
        
    }
    ptr->next=NULL;
}
void insertAfterNode(int val)
{
   node *temp=search(val);
   if(!temp)
   return;
   node *ptr=(node*)malloc(sizeof(node));
   printf("\nEnter value : ");
   scanf("%d",&ptr->data);
   ptr->next=temp->next;
   temp->next=ptr;
}
void insertBeforeNode(int val)
{
    node *temp=head;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nEnter value : ");
    scanf("%d",&ptr->data);
    if(temp->data==val)
    {
        ptr->next=temp;
        head=ptr;
    } 
    else 
    {
        while(temp->next&&temp->next->data!=val)
        temp=temp->next;
        if(temp->next)     // ==> searching node exists in LL
        { 
            ptr->next=temp->next;
            temp->next=ptr;
        }
        else    // ==> searching node does not exist in LL
        {
            printf("Searching node does not exist\n");
            delete(ptr);
        }
    }
} 

void deletion(int data)  //value of deleted node
{
    node *temp=head;
    if(temp->data==data)
    {
        head=temp->next;
        delete(temp);
    }
    else 
    {
        while(temp->next&&temp->next->data!=data)
        temp=temp->next;
        if(temp->next)    // delete node data exists
        {
            node *ptr=temp->next;
            temp->next=ptr->next;
            delete(ptr);
        }
        else 
            printf("There is not any node of %d value\n",data);
    }
}
void reverseLL()
{
    node *temp=head->next;
    if(!temp)  // ==> Single Node
    return;
    node *ptr=temp->next;
    temp->next=head;
    head->next=NULL;
    head=temp;
    temp=ptr;
    while(temp)
    {
        ptr=temp->next;
        temp->next=head;
        head=temp;
        temp=ptr;
    }
}
void insAf()
{
    int val;
    printf("\nEnter the value of the Node : ");
    scanf("%d",&val);
    insertAfterNode(val);
}
void insBf()
{
    int val;
    printf("\nEnter the value of the Node : ");
    scanf("%d",&val);
    insertBeforeNode(val);
}
void dletNode()
{
    int val;
    printf("\nEnter Node's value want to delete : ");
    scanf("%d",&val);
    deletion(val);
}
void srchNode()
{
    int val;
    printf("\nEnter searching Node's value : ");
    scanf("%d",&val); 
    node *ptr=search(val);
    if(ptr)
        printf("Node is found and value is %d\n",ptr->data);
    else 
       printf("Does not exist\n");
}
void menu()
{
    creation();
    int n;
    printf("No of operations : ");
    scanf("%d",&n);
    while(n--)
    {
        printf("1. Inset afeter a Node\n");
        printf("2. Insert before a Node\n");
        printf("3. Delete a Node\n");
        printf("4. Searching a Node\n");
        printf("5. Disaply LL\n");
        printf("6. Reverse print\n");
        printf("7. Reverse the Linked List\n");
        printf("8. Display using recursive\n");
        int x;
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                insAf();
                break;   
            case 2:
                insBf();
                break;   
            case 3:
                dletNode();
                break;   
            case 4:
                srchNode();
                break;   
            case 5:
                display();
                break; 
            case 6:
                reversePrint();
                break;      
            case 7:
                reverseLL();
                break;   
            case 8:
                printf("start");
                displayRec(head);
                printf("\n");
            default:
            exit(0);
        }
    }
}
int main()
{
  menu();
  return 0;
}