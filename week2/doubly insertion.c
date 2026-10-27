#include <stdio.h>
#include <stdlib.h>
struct Node {
	
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the very beginning (Head)
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        return ;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Insert a node at the very end (Tail)
void insertAtTail(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}
int main() {
    struct Node* head = NULL; 

    // Test Insertions
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtHead(&head, 5); 
    printForward(head);
    printBackward(head);
     while (head != NULL) {
        deleteNode(&head, head->data);
    }

    return 0;
}

