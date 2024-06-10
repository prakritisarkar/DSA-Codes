#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*top=0;
void push(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=top;
    newnode->data=x;
    top=newnode;
}
void pop()
{
    struct node*temp;
    temp=top;
    if(top==NULL)
    {
        printf("stack is empty");    
    }
    else
    {
        printf("%d",top->data);
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
    printf("stack is empty");
    else
    {
        printf("%d",top->data);
    }
}
int isempty()
{
    return top==NULL;
}
void display()
{
    struct node*temp;
    temp=top;
    if(top==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while(temp!=NULL)
        {
        printf("%d",temp->data);
        temp=temp->next;
        }
    }
}
int main()
{
    int ch,value;
    while(1)
    {  
    printf("\nenter stack operations\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.check if empty\n");
    printf("5.display\n");
    printf("6.exit\n");
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("enter the value to be pushed",value);
        scanf("%d",&value);
        push(value);
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        if(isempty())
        {
            printf("stack is empty");  
        }
        else
        {
            printf("stack is not empty");
        }
        break;
        case 5:
        display();
        break;
        case 6:
        printf("exit");
        default:
        printf("invalid choice");

    }
  }
  return 0;
}