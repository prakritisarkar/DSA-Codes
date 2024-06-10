#include<stdio.h>
#define N 5
int deque[N];
int front=-1;
int rear=-1;
void enqueuefront(int x)
{
    if((front==-0&&rear==N-1)||(front==rear+1))
    printf("queue is full");
    else if(front==-1&&rear==-1)
    {
    front=rear=0;
    deque[front]=x;
    }
    else if(front==0)
    {
        front=N-1;
        deque[front]=x;
    }
    else
    {
       front--;
       deque[front]=x;
    }
}
void enqueuerear(int x)
{
    if((front==0&&front==N-1)||(front==rear+1))
    printf("queue is full");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        deque[rear]=x;
    }
    else if(rear==N-1)
    {
        rear=0;
        deque[rear]=x;
    }
    else
    {
        rear++;
        deque[rear]=x;
    }
}
void dequeuefront()
{
    if(front==-1&&rear==-1)
    printf("queue is empty");
    else if(front==rear)
    {
    front=rear=-1;
    }
    else if(front==N-1)
    {
      printf("the dequeued element is %d",deque[front]);
       front=0;
    }
    else
    {
        printf("the dequeued element is %d",deque[front]);
        front++;

    }
}
void dequeuerear()
{
    if(front==-1&&rear==-1)
    printf("queue is empty");
    else if(rear==front)
    front=rear=-1;
    else if(rear==0)
    rear=N-1;
    else
    {

    printf("the dequeued element is %d",deque[rear]);
    rear--;
    }

}

int main()  
{ 
    int choice, item; 
    do { 
        printf("\n---- Menu ----\n"); 
        printf("1.enqueue at front\n"); 
        printf("2.enqueue at rear\n"); 
        printf("3.dequeue from front\n"); 
        printf("4.dequeue from rear\n"); 
        printf("5.Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: 
                printf("Enter the element to enqueue at front: "); 
                scanf("%d", &item); 
                enqueuefront(item); 
                break; 
            case 2: 
                printf("Enter the element to enqueue at rear: "); 
                scanf("%d", &item); 
                enqueuerear(item); 
                break; 
            case 3: 
                dequeuefront(); 
                break; 
            case 4: 
                dequeuerear(); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please enter a valid choice.\n"); 
        } 
    } while(choice != 6); 
 
    return 0; 
}