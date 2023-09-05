#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct  node
{
    char data;
    struct node *next;
}node;
typedef struct stack {
    node *head;
}stack;
stack* createStack()
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->head=NULL;
    return s;
}
void push(stack *s,char x)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=s->head;
    s->head=ptr;
}
char pop(stack *s)
{
    char ch='\0';
    if(s->head)
    {   
        node *temp=s->head;
        ch=temp->data;
        s->head=s->head->next;
        free(temp);
    }
    return ch;
}
char  top(stack *s)
{
    if(s->head)
    return s->head->data;
    return '\0';
}
int priority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}
void infixToPostfix(char *s)
{
    int n=strlen(s),ptop;
    char fnl[100]={'\0'},ch;
    stack *stk=createStack();
    int idx=0;
    for(int i=0;i<n;i++)
    {
        switch(s[i])
        {
            case '(':
                push(stk,'(');
                break;
            case ')':
                ch=pop(stk);
                while(ch!='(')
                {
                    fnl[idx++]=ch;
                    ch=pop(stk);
                }
                break;
            case '^':
                push(stk,'^');
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                ch=top(stk);
                ptop=priority(s[i]);
                while(ptop<priority(ch))
                {
                    fnl[idx++]=ch;
                    pop(stk);
                    ch=top(stk);
                }
                push(stk,s[i]);
                break;
            default :
                fnl[idx++]=s[i];
        }
    }
    fnl[idx]='\0';
    printf("\n%s",fnl);
}
int main()
{
    char s[100];
    scanf("%s",s);
    infixToPostfix(s);
    return 0;
}