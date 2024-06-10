#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(rear==-1 && front==-1)
    {
    rear=front=0;
    queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
    printf("queue is full");
    }
    else
    { 
       rear= (rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    printf("underflow condition");
    else if(rear==front)
    {
        rear=front=-1;
    }
    else
    {
        printf("the dequeued element is %d",queue[front]);
       front= (front+1)%N;
    }
}
int main()
{
    int choice,value;
    while(1)
    {
        printf(" main menu\n.....\n1.enqueue\n2.dequeue\n3.exit\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value to enqueued");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue(); 
            break;
            case 3:
            printf("exiting.....\n");
            return 0;
            default:
            printf("invalid choice,please try again.\n");
        }
    }
    return 0;
}