#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node in dynamic memory
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
        return;
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

// Delete the first occurrence of a node matching the given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head;

    // Traverse to find the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // If node to be deleted is the head node
    if (*head == temp) {
        *head = temp->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free the memory allocated to the node
    free(temp);
}

// Print the list from Head to Tail
void printForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Print the list from Tail to Head (Demonstrates bidirectional traversal)
void printBackward(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Driver program to test the operations
int main() {
    struct Node* head = NULL; // Initialize empty list

    // Test Insertions
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtHead(&head, 5); // List becomes: 5 -> 10 -> 20 -> 30

    printForward(head);
    printBackward(head);

    // Test Deletion
    printf("\nDeleting 20...\n");
    deleteNode(&head, 20);
    printForward(head);

    printf("\nDeleting 5 (Head)...\n");
    deleteNode(&head, 5);
    printForward(head);

    // Free remaining nodes before exiting (Good practice)
    while (head != NULL) {
        deleteNode(&head, head->data);
    }

    return 0;
}


