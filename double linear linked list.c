#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* prev; 
    struct Node* next; 
}; 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed!\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
    return newNode; 
} 
 
void insertAtBeginning(struct Node** headRef, int data) { 
    struct Node* newNode = createNode(data); 
    if (*headRef == NULL) { 
        *headRef = newNode; 
    } else { 
        newNode->next = *headRef; 
        (*headRef)->prev = newNode; 
        *headRef = newNode; 
    } 
    printf("Node with data %d inserted at the beginning.\n", data); 
} 
void insertAtEnd(struct Node** headRef, int data) { 
    struct Node* newNode = createNode(data); 
    struct Node* temp = *headRef; 
    if (*headRef == NULL) { 
        *headRef = newNode; 
    } else { 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
        newNode->prev = temp; 
    } 
    printf("Node with data %d inserted at the end.\n", data); 
} 
void deleteNode(struct Node** headRef, int data) { 
    struct Node* temp = *headRef; 
    if (temp == NULL) { 
        printf("List is empty. Deletion failed.\n"); 
        return; 
    } 
    if (temp->data == data) { 
        *headRef = temp->next; 
        if (*headRef != NULL) { 
            (*headRef)->prev = NULL; 
        } 
        free(temp); 
        printf("Node with data %d deleted from the list.\n", data); 
        return; 
    } 
    while (temp != NULL && temp->data != data) { 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Node with data %d not found in the list. Deletion failed.\n", data); 
        return; 
    } 
    temp->prev->next = temp->next; 
    if (temp->next != NULL) { 
        temp->next->prev = temp->prev; 
    } 
    free(temp); 
    printf("Node with data %d deleted from the list.\n", data); 
} 
void searchNode(struct Node* head, int data) { 
    struct Node* temp = head; 
    while (temp != NULL && temp->data != data) { 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Node with data %d not found in the list.\n", data); 
    } else { 
        printf("Node with data %d found in the list.\n", data); 
    } 
} 
void printList(struct Node* head) { 
    printf("Doubly Linked List: "); 
    while (head != NULL) { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
    printf("\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, data; 
     
    do { 
        printf("\nDoubly Linked List Operations\n"); 
        printf("1.Insert at beginning\n"); 
        printf("2.Insert at end\n"); 
        printf("3.Delete a node\n"); 
        printf("4.Search for a node\n"); 
        printf("5.Display\n"); 
        printf("6.Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
         
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at the beginning: "); 
                scanf("%d", &data); 
                insertAtBeginning(&head, data); 
                break; 
            case 2: 
                printf("Enter data to insert at the end: "); 
                scanf("%d", &data); 
                insertAtEnd(&head, data); 
                break; 
            case 3: 
                printf("Enter data of the node to delete: "); 
                scanf("%d", &data); 
                deleteNode(&head, data); 
                break; 
            case 4: 
                printf("Enter data of the node to search: "); 
                scanf("%d", &data); 
                searchNode(head, data); 
                break; 
            case 5: 
                printList(head); 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } while (choice != 6); 
 
    return 0; 
}