#include <stdio.h> 
#include <stdlib.h> 
struct Node  
{ 
    int data; 
    struct Node* next; 
}; 
struct Queue  
{ 
    struct Node *front, *rear; 
}; 
 
struct Node* newNode(int data)  
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 
struct Queue* createQueue()  
{ 
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    queue->front = queue->rear = NULL; 
    return queue; 
} 
void enqueue(struct Queue* queue, int data)  
{ 
    struct Node* temp = newNode(data); 
    if (queue->rear == NULL) { 
        queue->front = queue->rear = temp; 
        temp->next = temp; 
        return; 
    } 
    queue->rear->next = temp; 
    queue->rear = temp; 
    queue->rear->next = queue->front; 
} 
int dequeue(struct Queue* queue)  
{ 
    if (queue->front == NULL) { 
        printf("Queue is empty\n"); 
        return -1; 
    } 
    if (queue->front == queue->rear) { 
        int data = queue->front->data; 
        free(queue->front); 
        queue->front = queue->rear = NULL; 
        return data; 
    } 
    struct Node* temp = queue->front; 
    queue->front = queue->front->next; 
    int data = temp->data; 
    free(temp); 
    queue->rear->next = queue->front; 
    return data; 
} 
 
int main()  
{ 
    struct Queue* queue = createQueue(); 
    int choice, data; 
    while (1) { 
        printf("\nChoose operation:\n"); 
        printf("1.Enqueue\n"); 
        printf("2.Dequeue\n"); 
        printf("3.Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch(choice) { 
            case 1: 
                printf("Enter element to enqueue:"); 
                scanf("%d", &data); 
                enqueue(queue, data); 
                printf("%d enqueued to the queue\n", data); 
                break; 
            case 2: 
                data = dequeue(queue); 
                if (data != -1) 
                    printf("Dequeued element: %d\n", data); 
                break; 
            case 3: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice! Please enter a valid option.\n"); 
        } 
    } 
    return 0; 
}